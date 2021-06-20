/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#include <prdfMemTdCtlr.H>

// Framework includes
#include <prdfRegisterCache.H>
#include <UtilHash.H>

// Platform includes
#include <prdfMemAddress.H>
#include <prdfMemCaptureData.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemExtraSig.H>
#include <prdfParserEnums.H>
#include <UtilHash.H> // for Util::hashString

// External includes
#include <util/misc.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
TdRankListEntry __getStopRank( ExtensibleChip * i_chip, const MemAddr & i_addr )
{
    MemRank stopRank = i_addr.getRank();

    // ############################ SIMICs only ############################
    // We have found it to be increasingly difficult to simulate the MCBMCAT
    // register in SIMICs. We tried copying the address in the MCBEA
    // registers, but the HWP code will input the last possible address to
    // the MCBEA registers, but it is likely that this address is not a
    // configured address. MCBIST commands are tolerant of this, where MBA
    // maintenance commands are not. Also, there are multiple possible
    // subtests for MCBIST commands. So it is difficult to determine which
    // subtest will be the last configured address. To maintain sanity, we
    // will simply short-circuit the code and ensure we always get the last
    // configured rank.
    if ( ::Util::isSimicsRunning() )
    {
        std::vector<MemRank> list;
        getSlaveRanks<T>( i_chip->getTrgt(), list );
        PRDF_ASSERT( !list.empty() ); // func target with no config ranks

        stopRank = list.back(); // Get the last configured rank.
    }
    // #####################################################################

    return TdRankListEntry( i_chip, stopRank );
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::handleCmdComplete( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::handleCmdComplete] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Make sure the TD controller is initialized.
        o_rc = initialize();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "initialize() failed" );
            break;
        }

        #ifndef __HOSTBOOT_RUNTIME // IPL only

        // TODO: RTC 179251 asserting here doesn't give us enough FFDC to debug
        //       why we got this erroneous attention. Eventually, we will want
        //       to add the capture data to the assert error log. Until then
        //       exit with a bad RC and make the error log predictive.
        // PRDF_ASSERT( isInMdiaMode() ); // MDIA must be running.
        if ( !isInMdiaMode() )
        {
            PRDF_ERR( PRDF_FUNC "IPL cmd complete attn outside of MDIA" );
            o_rc = FAIL;
            break;
        }

        // Inform MDIA the command has completed and PRD is starting analysis.
        // If MDIA started the command, the reset message will do the cleanup
        // for the super fast command.
        o_rc = mdiaSendEventMsg( iv_chip->getTrgt(), MDIA::RESET_TIMER );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(RESET_TIMER) failed" );
            break;
        }

        // If PRD started a super fast command, this will do the cleanup for the
        // super fast command.
        o_rc = cleanupSfRead<T>( iv_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "cleanupSfRead(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        #endif

        collectStateCaptureData( io_sc, TD_CTLR_DATA::START );

        if ( nullptr == iv_curProcedure )
        {
            // There are no TD procedures currently in progress.

            // Check for ECC errors, if they exist.
            bool errorsFound = false;
            o_rc = analyzeCmdComplete( errorsFound, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "analyzeCmdComplete(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            // If the command completed successfully with no error, the error
            // log will not have any useful information. Therefore, do not
            // commit the error log. This is done to avoid useless
            // informational error logs.
            if ( !errorsFound ) io_sc.service_data->setDontCommitErrl();
        }

        // Move onto the next step in the state machine.
        o_rc = nextStep( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "nextStep() failed" );
            break;
        }

    } while (0);

    // Gather capture data even if something failed above.
    // NOTE: There is no need to capture the data if the command completed
    //       successfully with no errors because the error log will not be
    //       committed.
    if ( !io_sc.service_data->queryDontCommitErrl() )
    {
        collectStateCaptureData( io_sc, TD_CTLR_DATA::END );
        MemCaptureData::addEccData<T>( iv_chip, io_sc );
    }

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed on 0x%08x", iv_chip->getHuid() );

        // Just in case it was a legitimate command complete (error log not
        // committed) but something else failed.
        io_sc.service_data->clearDontCommitErrl();

        // Change signature indicating there was an error in analysis.
        io_sc.service_data->setSignature( iv_chip->getHuid(),
                                          PRDFSIG_CmdComplete_ERROR );

        // Something definitely failed, so callout 2nd level support.
        io_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_HIGH );
        io_sc.service_data->setServiceCall();

        #ifndef __HOSTBOOT_RUNTIME // IPL only

        if ( isInMdiaMode() )
        {
            // Tell MDIA to skip further analysis on this target.
            uint32_t l_rc = mdiaSendEventMsg( iv_chip->getTrgt(),
                                              MDIA::STOP_TESTING );
            if ( SUCCESS != l_rc )
                PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(STOP_TESTING) failed" );
        }

        #endif
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// This is a forward reference to a function that is locally defined in
// prdfMemTdCtlr_ipl.C and prdfMemTdCtlr_rt.C.
template<TARGETING::TYPE T>
uint32_t __checkEcc( ExtensibleChip * i_chip,
                     const MemAddr & i_addr, bool & o_errorsFound,
                     STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __analyzeCmdComplete( ExtensibleChip * i_chip,
                               TdRankListEntry & o_stoppedRank,
                               const MemAddr & i_addr,
                               bool & o_errorsFound,
                               STEP_CODE_DATA_STRUCT & io_sc );

template<>
uint32_t __analyzeCmdComplete<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                               TdRankListEntry & o_stoppedRank,
                                               const MemAddr & i_addr,
                                               bool & o_errorsFound,
                                               STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[__analyzeCmdComplete] "

    uint32_t o_rc = SUCCESS;

    o_errorsFound = false;

    do
    {
        // Update iv_stoppedRank.
        o_stoppedRank = __getStopRank<TYPE_OCMB_CHIP>( i_chip, i_addr );

        // Check the OCMB for ECC errors.
        bool errorsFound;
        o_rc = __checkEcc<TYPE_OCMB_CHIP>( i_chip, i_addr, errorsFound, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "__checkEcc<TYPE_OCMB_CHIP>(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        if ( errorsFound ) o_errorsFound = true;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::analyzeCmdComplete( bool & o_errorsFound,
                                           STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::analyzeCmdComplete] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // First, get the address in which the command stopped.
        MemAddr addr;
        o_rc = getMemMaintAddr<T>( iv_chip, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr<T>(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Then, check for ECC errors, if they exist.
        o_rc = __analyzeCmdComplete<T>( iv_chip, iv_stoppedRank,
                                        addr, o_errorsFound, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "__analyzeCmdComplete<T>(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        #ifdef __HOSTBOOT_RUNTIME

        if ( iv_queue.empty() )
        {
            // The queue is empty so it is possible that background scrubbing
            // only stopped for FFDC. If possible, simply resume the command
            // instead of starting a new one. This must be checked here instead
            // of in defaultStep() because a TD procedure could have been run
            // before defaultStep() and it is possible that canResumeBgScrub()
            // could give as a false positive in that case.
            o_rc = canResumeBgScrub( iv_resumeBgScrub, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "canResumeBgScrub(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }
        }
        else
        {
            // The analyzeCmdComplete() function is only called if there was a
            // command complete attention and there were no TD procedures
            // currently in progress. At this point, there are new TD procedures
            // in the queue so we want to mask certain fetch attentions to avoid
            // the complication of handling the attentions during the TD
            // procedures.
            o_rc = maskEccAttns();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "maskEccAttns() failed" );
                break;
            }
        }

        #endif

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
void MemTdCtlr<T>::collectStateCaptureData( STEP_CODE_DATA_STRUCT & io_sc,
                                            const char * i_startEnd )
{
    #define PRDF_FUNC "[MemTdCtlr<T>::collectStateCaptureData] "

    // Get the number of entries in the TD queue (limit 16)
    TdQueue::Queue queue = iv_queue.getQueue();
    uint8_t queueCount = queue.size();
    if ( 16 < queueCount ) queueCount = 16;

    // Don't add anything if there is no data.
    if ( nullptr == iv_curProcedure && 0 == queueCount ) return;

    // Get the version to use.
    uint8_t version = TD_CTLR_DATA::VERSION_1;

    // Get the IPL state.
    #ifdef __HOSTBOOT_RUNTIME
    uint8_t state = TD_CTLR_DATA::RT;
    #else
    uint8_t state = TD_CTLR_DATA::IPL;
    #endif

    // Get the buffer length (header + TD queue)
    uint32_t hdrLen = TD_CTLR_DATA::v1_HEADER;
    uint32_t entLen = TD_CTLR_DATA::v1_ENTRY;
    if ( TD_CTLR_DATA::VERSION_2 == version )
    {
        hdrLen = TD_CTLR_DATA::v2_HEADER;
        entLen = TD_CTLR_DATA::v2_ENTRY;
    }

    uint32_t bitLen = hdrLen + queueCount * entLen;

    // Init the buffer.
    BitStringBuffer bsb( bitLen );

    //##########################################################################
    // Header data
    //##########################################################################

    uint8_t curMrnk  = 0;
    uint8_t curSrnk  = 0;
    uint8_t curPhase = TdEntry::Phase::TD_PHASE_0;
    uint8_t curType  = TdEntry::TdType::INVALID_EVENT;
    uint8_t curPort  = 0;

    if ( nullptr != iv_curProcedure )
    {
        curMrnk  = iv_curProcedure->getRank().getMaster();
        curSrnk  = iv_curProcedure->getRank().getSlave();
        curPhase = iv_curProcedure->getPhase();
        curType  = iv_curProcedure->getType();
    }

    uint32_t pos = 0;

    bsb.setFieldJustify( pos, 1, state      ); pos+=1;
    bsb.setFieldJustify( pos, 3, version    ); pos+=3;
    bsb.setFieldJustify( pos, 3, curMrnk    ); pos+=3;
    bsb.setFieldJustify( pos, 3, curSrnk    ); pos+=3;
    bsb.setFieldJustify( pos, 4, curPhase   ); pos+=4;
    bsb.setFieldJustify( pos, 4, curType    ); pos+=4;
    bsb.setFieldJustify( pos, 4, queueCount ); pos+=4;

    // port is only for VERSION_2
    if ( TD_CTLR_DATA::VERSION_2 == version )
    {
        bsb.setFieldJustify( pos, 2, curPort ); pos+=2;
    }

    //##########################################################################
    // TD Queue
    //##########################################################################

    for ( uint32_t n = 0; n < queueCount; n++ )
    {
        uint8_t itMrnk = queue[n]->getRank().getMaster();
        uint8_t itSrnk = queue[n]->getRank().getSlave();
        uint8_t itType = queue[n]->getType();
        uint8_t itPort = 0;

        bsb.setFieldJustify( pos, 3, itMrnk ); pos+=3;
        bsb.setFieldJustify( pos, 3, itSrnk ); pos+=3;
        bsb.setFieldJustify( pos, 4, itType ); pos+=4;

        if ( TD_CTLR_DATA::VERSION_2 == version )
        {
            bsb.setFieldJustify( pos, 2, itPort ); pos+=2;
        }
    }

    //##########################################################################
    // Add the capture data
    //##########################################################################

    CaptureData & cd = io_sc.service_data->GetCaptureData();
    cd.Add( iv_chip->getTrgt(), Util::hashString(i_startEnd), bsb );

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::handleDsdImpeTh( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::triggerDsdEventImpeTh] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Make sure the TD controller is initialized.
        o_rc = initialize();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "initialize() failed on 0x%08x",
                      iv_chip->getHuid() );
            break;
        }

        // Don't interrupt a TD procedure if one is already in progress.
        if ( nullptr != iv_curProcedure ) break;

        #ifdef __HOSTBOOT_RUNTIME

        // Stop background scrubbing.
        o_rc = stopBgScrub<T>( iv_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "stopBgScrub<T>(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Update the rank we stopped background scrub on
        MemAddr addr;
        o_rc = getMemMaintAddr<T>( iv_chip, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr<T>(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        iv_stoppedRank = __getStopRank<T>( iv_chip, addr );

        // At this point, there are new TD procedures in the queue so we
        // want to mask certain fetch attentions to avoid the complication
        // of handling the attentions during the TD procedures.
        o_rc = maskEccAttns();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "maskEccAttns() failed" );
            break;
        }

        #endif

        // Since we had to manually stop the maintenance command, refresh all
        // relevant registers that may have changed since the initial capture.
        recaptureRegs( io_sc );

        collectStateCaptureData( io_sc, TD_CTLR_DATA::START );

        // Move onto the next step in the state machine.
        o_rc = nextStep( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "nextStep() failed on 0x%08x",
                      iv_chip->getHuid() );
            break;
        }

    } while (0);

    // Gather capture data even if something failed above.
    collectStateCaptureData( io_sc, TD_CTLR_DATA::END );

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed on 0x%08x", iv_chip->getHuid() );

        // Change signature indicating there was an error in analysis.
        io_sc.service_data->setSignature( iv_chip->getHuid(),
                                          PRDFSIG_CmdComplete_ERROR );

        // Something definitely failed, so callout 2nd level support.
        io_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_HIGH );
        io_sc.service_data->setServiceCall();
    }

    return o_rc;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

template<>
void MemTdCtlr<TYPE_OCMB_CHIP>::recaptureRegs( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[recaptureRegs<TYPE_OCMB_CHIP>] "

    RegDataCache & cache = RegDataCache::getCachedRegisters();
    CaptureData & cd = io_sc.service_data->GetCaptureData();

    // refresh and recapture the ocmb registers
    const char * ocmbRegs[] =
    {
        "MCBISTFIR", "RDFFIR", "MBSEC0", "MBSEC1", "OCMB_MBSSYMEC0",
        "OCMB_MBSSYMEC1", "OCMB_MBSSYMEC2", "OCMB_MBSSYMEC3",
        "OCMB_MBSSYMEC4", "OCMB_MBSSYMEC5", "OCMB_MBSSYMEC6",
        "OCMB_MBSSYMEC7", "OCMB_MBSSYMEC8", "MBSMSEC", "MCBMCAT",
    };

    for ( uint32_t i = 0; i < sizeof(ocmbRegs)/sizeof(char*); i++ )
    {
        SCAN_COMM_REGISTER_CLASS * reg = iv_chip->getRegister( ocmbRegs[i] );
        cache.flush( iv_chip, reg );
    }

    iv_chip->CaptureErrorData( cd, Util::hashString("MaintCmdRegs_ocmb") );

    #undef PRDF_FUNC
}


//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class MemTdCtlr<TYPE_OCMB_CHIP>;

//------------------------------------------------------------------------------

} // end namespace PRDF

