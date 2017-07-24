/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

// Platform includes
#include <prdfMemAddress.H>
#include <prdfMemCaptureData.H>
#include <prdfMemScrubUtils.H>
#include <prdfP9McaDataBundle.H>
#include <prdfP9McbistExtraSig.H>
#include <prdfParserEnums.H>

// External includes
#include <util/misc.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::handleCmdComplete( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::handleCmdComplete] "

    uint32_t o_rc = SUCCESS;

    do
    {
        #ifdef __HOSTBOOT_RUNTIME

        // Make sure the TD controller is initialized.
        o_rc = initialize();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "initialize() failed" );
            break;
        }

        #else // IPL only

        PRDF_ASSERT( isInMdiaMode() ); // MDIA must be running.

        // Inform MDIA the command has completed and PRD is starting analysis.
        o_rc = mdiaSendEventMsg( iv_chip->getTrgt(), MDIA::RESET_TIMER );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(RESET_TIMER) failed" );
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
        MemCaptureData::addEccData<T>( iv_chip, io_sc );

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

        // Tell MDIA to skip further analysis on this target.
        uint32_t l_rc = mdiaSendEventMsg( iv_chip->getTrgt(),
                                          MDIA::STOP_TESTING );
        if ( SUCCESS != l_rc )
            PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(STOP_TESTING) failed" );

        #endif
    }
    else
    {
        collectStateCaptureData( io_sc, TD_CTLR_DATA::END );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// This is a forward reference to a function that is locally defined in
// prdfMemTdCtlr_ipl.C and prdfMemTdCtlr_rt.C. The reason for this is that the
// MemTdCtlr template is only created for the MCBIST and MBA targets, not the
// MCA, but the ECC analysis is done on each MCA and MBA. Therefore, we needed
// some way to change the template to use the MCA. It is also a local function
// because this is only for MemTdCtlr internal use and it didn't make much sense
// to create a public function.
template<TARGETING::TYPE T, typename D>
uint32_t __checkEcc( ExtensibleChip * i_chip, TdQueue & io_queue,
                     const MemAddr & i_addr, bool & o_errorsFound,
                     STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __analyzeCmdComplete( ExtensibleChip * i_chip,
                               TdQueue & io_queue,
                               TdRankListEntry & o_stoppedRank,
                               #ifndef __HOSTBOOT_RUNTIME
                               bool & o_broadcastMode,
                               #endif
                               const MemAddr & i_addr,
                               bool & o_errorsFound,
                               STEP_CODE_DATA_STRUCT & io_sc );

template<>
uint32_t __analyzeCmdComplete<TYPE_MCBIST>( ExtensibleChip * i_chip,
                                            TdQueue & io_queue,
                                            TdRankListEntry & o_stoppedRank,
                                            #ifndef __HOSTBOOT_RUNTIME
                                            bool & o_broadcastMode,
                                            #endif
                                            const MemAddr & i_addr,
                                            bool & o_errorsFound,
                                            STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[__analyzeCmdComplete] "

    uint32_t o_rc = SUCCESS;

    o_errorsFound = false;

    do
    {
        // Get all ports in which the command was run.
        std::vector<ExtensibleChip *> portList;
        o_rc = getMcbistMaintPort( i_chip, portList );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMcbistMaintPort(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // In broadcast mode, the rank configuration for all ports will be the
        // same. In non-broadcast mode, there will only be one MCA in the list.
        // Therefore, we can simply use the first MCA in the list for all
        // configs.
        ExtensibleChip * stopChip = portList.front();
        MemRank          stopRank = i_addr.getRank();

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
        if ( Util::isSimicsRunning() )
        {
            std::vector<MemRank> list;
            getSlaveRanks<TYPE_MCA>( stopChip->getTrgt(), list );
            PRDF_ASSERT( !list.empty() ); // func target with no config ranks

            stopRank = list.back(); // Get the last configured rank.
        }
        // #####################################################################

        // Update iv_stoppedRank.
        o_stoppedRank = TdRankListEntry ( stopChip, stopRank );
        #ifndef __HOSTBOOT_RUNTIME
        // Update iv_broadcastMode.
        o_broadcastMode = ( 1 < portList.size() );
        #endif

        // Check each MCA for ECC errors.
        for ( auto & mcaChip : portList )
        {
            bool errorsFound;
            uint32_t l_rc = __checkEcc<TYPE_MCA, McaDataBundle *>( mcaChip,
                                                                   io_queue,
                                                                   i_addr,
                                                                   errorsFound,
                                                                   io_sc );
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "__checkEcc<TYPE_MCA>(0x%08x) failed",
                          mcaChip->getHuid() );
                o_rc |= l_rc; continue; // Try the other MCAs.
            }

            if ( errorsFound ) o_errorsFound = true;
        }
        if ( SUCCESS != o_rc ) break;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t __analyzeCmdComplete<TYPE_MBA>( ExtensibleChip * i_chip,
                                         TdQueue & io_queue,
                                         TdRankListEntry & o_stoppedRank,
                                         #ifndef __HOSTBOOT_RUNTIME
                                         bool & o_broadcastMode,
                                         #endif
                                         const MemAddr & i_addr,
                                         bool & o_errorsFound,
                                         STEP_CODE_DATA_STRUCT & io_sc )
{
    // Update iv_stoppedRank.
    o_stoppedRank = TdRankListEntry( i_chip, i_addr.getRank() );

    /* TODO RTC 157888
    // Check the MBA for ECC errors.
    return __checkEcc<TYPE_MBA>(i_chip, io_queue, i_addr, o_errorsFound, io_sc);
    */
    return SUCCESS;
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
        o_rc = __analyzeCmdComplete<T>( iv_chip, iv_queue, iv_stoppedRank,
                                        #ifndef __HOSTBOOT_RUNTIME
                                        iv_broadcastMode,
                                        #endif
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
            // only stopped for FFDC. Simply resume the command instead of
            // starting a new one. Note that it is possible to get here if we
            // were running a TD procedure and the PRD service is reset.
            // Therefore, we must check if background scrubbing was actually
            // configured.
            bool isBgScrub;
            o_rc = isBgScrubConfig<T>( iv_chip, isBgScrub );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "isBgScrubConfig(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            if ( isBgScrub ) iv_resumeBgScrub = true;
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

template<>
uint32_t MemTdCtlr<TYPE_MCBIST>::maskEccAttns()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MCBIST>::maskEccAttns] "

    uint32_t o_rc = SUCCESS;

    // Loop through all MCAs.
    for ( auto mcaChip : getConnected(iv_chip, TYPE_MCA) )
    {
        SCAN_COMM_REGISTER_CLASS * mask =
            mcaChip->getRegister( "MCAECCFIR_MASK_OR" );

        mask->clearAllBits();
        mask->SetBit(8); // Mainline read NCE
        mask->SetBit(9); // Mainline read TCE

        o_rc = mask->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on MCAECCFIR_MASK_OR" );
            break;
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MCBIST>::unmaskEccAttns()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MCBIST>::unmaskEccAttns] "

    uint32_t o_rc = SUCCESS;

    // Memory CEs were masked at the beginning of the TD procedure, so
    // clear and unmask them. Also, it is possible that memory UEs have
    // thresholded so clear and unmask them as well.

    // Loop through all MCAs.
    for ( auto mcaChip : getConnected(iv_chip, TYPE_MCA) )
    {
        SCAN_COMM_REGISTER_CLASS * fir =
            mcaChip->getRegister( "MCAECCFIR_AND" );
        SCAN_COMM_REGISTER_CLASS * mask =
            mcaChip->getRegister( "MCAECCFIR_MASK_AND" );

        fir->setAllBits(); mask->setAllBits();

        // Don't clear the NCE and TCE attentions if specified to save the mask
        // in the iv_saveEccMask array.
        if ( !iv_saveEccMask[mcaChip->getPos()%MAX_PORT_PER_MCBIST] )
        {
            fir->ClearBit(8);  mask->ClearBit(8);  // Mainline read NCE
            fir->ClearBit(9);  mask->ClearBit(9);  // Mainline read TCE
        }
        fir->ClearBit(14); mask->ClearBit(14); // Mainline read UE

        o_rc = fir->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on MCAECCFIR_AND" );
            break;
        }

        o_rc = mask->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on MCAECCFIR_MASK_AND" );
            break;
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MBA>::maskEccAttns()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MBA>::maskEccAttns] "

    uint32_t o_rc = SUCCESS;

    // TODO RTC 176901
    //do
    //{
    //    // Don't want to handle memory CEs during any TD procedures, so
    //    // mask them.

    //    const char * reg_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR_MASK_OR"
    //                                            : "MBA1_MBSECCFIR_MASK_OR";
    //    SCAN_COMM_REGISTER_CLASS * reg = iv_membChip->getRegister(reg_str);

    //    reg->clearAllBits();
    //    reg->SetBit(16); // fetch NCE
    //    reg->SetBit(17); // fetch RCE
    //    reg->SetBit(43); // prefetch UE

    //    o_rc = reg->Write();
    //    if ( SUCCESS != o_rc )
    //    {
    //        PRDF_ERR( PRDF_FUNC "Write() failed on %s", reg_str );
    //        break;
    //    }

    //    iv_fetchAttnsMasked = true;

    //} while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MBA>::unmaskEccAttns()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MBA>::unmaskEccAttns] "

    uint32_t o_rc = SUCCESS;

    // TODO RTC 176901
    //do
    //{
    //    // Memory CEs where masked at the beginning of the TD procedure, so
    //    // clear and unmask them. Also, it is possible that memory UEs have
    //    // thresholded so clear and unmask them as well.

    //    const char * fir_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR_AND"
    //                                            : "MBA1_MBSECCFIR_AND";
    //    const char * msk_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR_MASK_AND"
    //                                            : "MBA1_MBSECCFIR_MASK_AND";

    //    SCAN_COMM_REGISTER_CLASS * fir = iv_membChip->getRegister( fir_str );
    //    SCAN_COMM_REGISTER_CLASS * msk = iv_membChip->getRegister( msk_str );

    //    fir->setAllBits(); msk->setAllBits();
    //    fir->ClearBit(16); msk->ClearBit(16); // fetch NCE
    //    fir->ClearBit(17); msk->ClearBit(17); // fetch RCE
    //    fir->ClearBit(19); msk->ClearBit(19); // fetch UE
    //    fir->ClearBit(43); msk->ClearBit(43); // prefetch UE

    //    o_rc = fir->Write();
    //    if ( SUCCESS != o_rc )
    //    {
    //        PRDF_ERR( PRDF_FUNC "Write() failed on %s", fir_str );
    //        break;
    //    }

    //    o_rc = msk->Write();
    //    if ( SUCCESS != o_rc )
    //    {
    //        PRDF_ERR( PRDF_FUNC "Write() failed on %s", msk_str );
    //        break;
    //    }

    //    iv_fetchAttnsMasked = false;

    //} while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class MemTdCtlr<TYPE_MCBIST>;
template class MemTdCtlr<TYPE_MBA>;

//------------------------------------------------------------------------------

} // end namespace PRDF

