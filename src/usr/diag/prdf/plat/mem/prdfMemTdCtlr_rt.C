/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr_rt.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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

/** @file  prdfMemTdCtlr_rt.C
 *  @brief A state machine for memory Targeted Diagnostics (runtime only).
 */

#include <prdfMemTdCtlr.H>

// Framework includes
#include <prdfRegisterCache.H>
#include <UtilHash.H>

// Platform includes
#include <prdfCenMbaDataBundle.H>
#include <prdfCenMbaExtraSig.H>
#include <prdfMemCaptureData.H>
#include <prdfMemEccAnalysis.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTps.H>
#include <prdfMemUtils.H>
#include <prdfMemVcm.H>
#include <prdfP9McaDataBundle.H>
#include <prdfMemExtraSig.H>
#include <prdfPlatServices.H>


#ifdef __HOSTBOOT_RUNTIME
#include <prdfMemDynDealloc.H>
#endif

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void __recaptureRegs( STEP_CODE_DATA_STRUCT & io_sc, ExtensibleChip * i_chip );

template<>
void __recaptureRegs<TYPE_MCBIST>( STEP_CODE_DATA_STRUCT & io_sc,
                                   ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[__recaptureRegs<TYPE_MCBIST>] "

    RegDataCache & cache = RegDataCache::getCachedRegisters();
    CaptureData & cd = io_sc.service_data->GetCaptureData();

    // refresh and recapture the mcb registers
    const char * mcbRegs[] =
    {
        "MCBISTFIR", "MBSEC0", "MBSEC1", "MCB_MBSSYMEC0",
        "MCB_MBSSYMEC1", "MCB_MBSSYMEC2", "MCB_MBSSYMEC3",
        "MCB_MBSSYMEC4", "MCB_MBSSYMEC5", "MCB_MBSSYMEC6",
        "MCB_MBSSYMEC7", "MCB_MBSSYMEC8", "MBSMSEC", "MCBMCAT",
    };

    for ( uint32_t i = 0; i < sizeof(mcbRegs)/sizeof(char*); i++ )
    {
        SCAN_COMM_REGISTER_CLASS * reg =
            i_chip->getRegister( mcbRegs[i] );
        cache.flush( i_chip, reg );
    }

    i_chip->CaptureErrorData( cd, Util::hashString("MaintCmdRegs_mcb") );

    // refresh and recapture the mca registers
    const char * mcaRegs[] =
    {
        "MCAECCFIR",
    };

    ExtensibleChipList mcaList = getConnected( i_chip, TYPE_MCA );

    for ( auto & mca : mcaList )
    {
        for ( uint32_t i = 0; i < sizeof(mcaRegs)/sizeof(char*); i++ )
        {
            SCAN_COMM_REGISTER_CLASS * reg = mca->getRegister( mcaRegs[i] );
            cache.flush( mca, reg );
        }
        mca->CaptureErrorData( cd, Util::hashString("MaintCmdRegs_mca") );
    }

    #undef PRDF_FUNC
}

template<>
void __recaptureRegs<TYPE_OCMB_CHIP>( STEP_CODE_DATA_STRUCT & io_sc,
                                   ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[__recaptureRegs<TYPE_OCMB_CHIP>] "

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
        SCAN_COMM_REGISTER_CLASS * reg =
            i_chip->getRegister( ocmbRegs[i] );
        cache.flush( i_chip, reg );
    }

    i_chip->CaptureErrorData( cd, Util::hashString("MaintCmdRegs_ocmb") );

    #undef PRDF_FUNC
}

template<>
void __recaptureRegs<TYPE_MBA>( STEP_CODE_DATA_STRUCT & io_sc,
                                ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[__recaptureRegs<TYPE_MBA>] "

    RegDataCache & cache = RegDataCache::getCachedRegisters();
    ExtensibleChip * membChip = getConnectedParent( i_chip, TYPE_MEMBUF );
    TargetHandle_t mbaTrgt = i_chip->GetChipHandle();
    uint32_t mbaPos = getTargetPosition( mbaTrgt );

    const char * membRegs[2][15] =
    {
        { "MBSECCFIR_0", "MBA0_MBSECCERRPT_0","MBA0_MBSECCERRPT_1",
          "MBA0_MBSEC0", "MBA0_MBSEC1", "MBSTR_0",
          "MBA0_MBSSYMEC0", "MBA0_MBSSYMEC1", "MBA0_MBSSYMEC2",
          "MBA0_MBSSYMEC3", "MBA0_MBSSYMEC4", "MBA0_MBSSYMEC5",
          "MBA0_MBSSYMEC6", "MBA0_MBSSYMEC7", "MBA0_MBSSYMEC8", },
        { "MBSECCFIR_1", "MBA1_MBSECCERRPT_0","MBA1_MBSECCERRPT_1",
          "MBA1_MBSEC0", "MBA1_MBSEC1", "MBSTR_1",
          "MBA1_MBSSYMEC0", "MBA1_MBSSYMEC1", "MBA1_MBSSYMEC2",
          "MBA1_MBSSYMEC3", "MBA1_MBSSYMEC4", "MBA1_MBSSYMEC5",
          "MBA1_MBSSYMEC6", "MBA1_MBSSYMEC7", "MBA1_MBSSYMEC8", },
    };
    for ( uint32_t i = 0; i < 15; i++ )
    {
        SCAN_COMM_REGISTER_CLASS * reg
            = membChip->getRegister( membRegs[mbaPos][i] );
        cache.flush( membChip, reg );
    }

    const char * mbaRegs[] =
    {
        "MBASPA", "MBMCT", "MBMSR", "MBMACA", "MBMEA", "MBASCTL", "MBAECTL",
    };
    for ( uint32_t i = 0; i < sizeof(mbaRegs)/sizeof(char*); i++ )
    {
        SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( mbaRegs[i] );
        cache.flush( i_chip, reg );
    }

    // Now recapture those registers.

    CaptureData & cd = io_sc.service_data->GetCaptureData();

    if ( 0 == mbaPos )
    {
        membChip->CaptureErrorData(cd, Util::hashString("MaintCmdRegs_mba0") );
    }
    else
    {
        membChip->CaptureErrorData(cd, Util::hashString("MaintCmdRegs_mba1") );
    }
    i_chip->CaptureErrorData(cd, Util::hashString("MaintCmdRegs"));

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::handleTdEvent] "

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

        // If the queue is empty, there is nothing to do. So there is no point
        // to stopping background scrub. This could have happen if TPS was
        // banned on a rank and the TPS request was never added to the queue. In
        // that case, mask fetch attentions temporarily to prevent flooding.
        if ( iv_queue.empty() )
        {
            o_rc = maskEccAttns();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "maskEccAttns() failed" );
                break;
            }

            break; // Don't stop background scrub.
        }

        // Stop background scrubbing.
        o_rc = stopBgScrub<T>( iv_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "stopBgScrub<T>(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Since we had to manually stop the maintenance command, refresh all
        // relevant registers that may have changed since the initial capture.
        __recaptureRegs<T>( io_sc, iv_chip );

        collectStateCaptureData( io_sc, TD_CTLR_DATA::START );

        // It is possible that background scrub could have found an ECC error
        // before we had a chance to stop the command. Therefore, we need to
        // call analyzeCmdComplete() first so that any ECC errors found can be
        // handled. Also, analyzeCmdComplete() will initialize the variables
        // needed so we know where to restart background scrubbing.
        bool junk = false;
        o_rc = analyzeCmdComplete( junk, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeCmdComplete(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

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

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::defaultStep( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::defaultStep] "

    uint32_t o_rc = SUCCESS;

    if ( iv_resumeBgScrub )
    {
        // Background scrubbing paused for FFDC collection only. Resume the
        // current command.

        iv_resumeBgScrub = false;

        PRDF_TRAC( PRDF_FUNC "Calling resumeBgScrub<T>(0x%08x)",
                   iv_chip->getHuid() );

        o_rc = resumeBgScrub<T>( iv_chip, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "resumeBgScrub<T>(0x%08x) failed",
                      iv_chip->getHuid() );
        }
    }
    else
    {

        // Unmask the ECC attentions that were explicitly masked during the
        // TD procedure.
        o_rc = unmaskEccAttns();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "unmaskEccAttns() failed" );
        }

        // A TD procedure has completed. Restart background scrubbing on the
        // next rank.

        TdRankListEntry nextRank = iv_rankList.getNext( iv_stoppedRank );

        PRDF_TRAC( PRDF_FUNC "Calling startBgScrub<T>(0x%08x, m%ds%d)",
                   nextRank.getChip()->getHuid(),
                   nextRank.getRank().getMaster(),
                   nextRank.getRank().getSlave() );

        o_rc = startBgScrub<T>( nextRank.getChip(), nextRank.getRank() );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startBgScrub<T>(0x%08x,m%ds%d) failed",
                      nextRank.getChip()->getHuid(),
                      nextRank.getRank().getMaster(),
                      nextRank.getRank().getSlave() );
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __handleNceEte( ExtensibleChip * i_chip,
                         const MemAddr & i_addr, STEP_CODE_DATA_STRUCT & io_sc,
                         bool i_isHard = false )
{
    #define PRDF_FUNC "[__handleNceEte] "

    uint32_t o_rc = SUCCESS;

    MemRank rank = i_addr.getRank();
    bool unexpectedSymCount = false;

    do
    {
        // Query the per-symbol counters for the CE symbol(s).
        MemUtils::MaintSymbols symData; MemSymbol junk;
        o_rc = MemUtils::collectCeStats<T>( i_chip, rank, symData, junk );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "MemUtils::collectCeStats(0x%08x,m%ds%d) "
                      "failed", i_chip->getHuid(), rank.getMaster(),
                      rank.getSlave() );
            break;
        }

        // Make sure the list size is correct. Note that Nimbus has two symbol
        // correction. So it is possible to have two symbols in the counters
        // even though the threshold is set to 1.
        uint32_t count = symData.size();
        switch ( T )
        {
            case TYPE_MCA:
            {
                // Expected 1 or 2 symbols
                if ( count < 1 || count > 2 )
                {
                    unexpectedSymCount = true;
                }

                // Increment the CE counter and store the rank we're on,
                // reset the UE and CE counts if we have stopped on a new rank.
                ExtensibleChip * mcb = getConnectedParent(i_chip, TYPE_MCBIST);
                McbistDataBundle * mcbdb = getMcbistDataBundle(mcb);
                if ( mcbdb->iv_ceUeRank != i_addr.getRank() )
                {
                    mcbdb->iv_ceStopCounter.reset();
                    mcbdb->iv_ueStopCounter.reset();
                }
                mcbdb->iv_ceStopCounter.inc( io_sc );
                mcbdb->iv_ceUeRank = i_addr.getRank();

                break;
            }
            case TYPE_MBA:
            {
                // Expected 1 symbol
                if ( count != 1 )
                {
                    unexpectedSymCount = true;
                }

                break;
            }
            case TYPE_OCMB_CHIP:
            {
                // Expected 1 or 2 symbols
                if ( count < 1 || count > 2 )
                {
                    unexpectedSymCount = true;
                }

                // Increment the UE counter and store the rank we're on,
                // reset the UE and CE counts if we have stopped on a new rank.
                OcmbDataBundle * ocmbdb = getOcmbDataBundle(i_chip);
                if ( ocmbdb->iv_ceUeRank != i_addr.getRank() )
                {
                    ocmbdb->iv_ceStopCounter.reset();
                    ocmbdb->iv_ueStopCounter.reset();
                }
                ocmbdb->iv_ceStopCounter.inc( io_sc );
                ocmbdb->iv_ceUeRank = i_addr.getRank();

                break;
            }
            default:
            {
                PRDF_ASSERT( false );
            }
        }

        // If there is an unexpected symbol count from the symbol counter
        // registers, just callout the rank and perform dynamic memory
        // deallocation if needed. Updating the CE table is missed in this
        // case. This case typically shouldn't be hit and is mainly in case
        // of strange behavior from the symbol counter registers.
        if ( unexpectedSymCount )
        {
            PRDF_ERR( PRDF_FUNC "Unexpected symbol count from the per-symbol "
                                "counter registers: %d", count );

            // Add the rank to the callout list.
            MemoryMru mm { i_chip->getTrgt(), rank,
                           MemoryMruData::CALLOUT_RANK };
            io_sc.service_data->SetCallout( mm );

            #ifdef __HOSTBOOT_RUNTIME
            if ( i_isHard )
            {
                // Dynamically deallocate the page.
                if ( SUCCESS != MemDealloc::page<T>( i_chip, i_addr ) )
                {
                    PRDF_ERR( PRDF_FUNC "MemDealloc::page(0x%08x) failed",
                              i_chip->getHuid() );
                }
            }
            #endif

            break;
        }

        for ( auto & d : symData )
        {
            // Add the symbol(s) to the callout list and CE table.
            bool doTps;
            o_rc = MemEcc::handleMemCe<T>( i_chip, i_addr, d.symbol, doTps,
                                           io_sc, i_isHard );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemCe(0x%08x) failed",
                          i_chip->getHuid() );
                break;
            }

            // Add a TPS procedure to the queue, if needed.
            if ( doTps )
            {
                TdEntry * e = new TpsEvent<T>{ i_chip, rank };
                MemDbUtils::pushToQueue<T>( i_chip, e );
            }
        }
        if ( SUCCESS != o_rc ) break;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __handleSoftInterCeEte( ExtensibleChip * i_chip,
                                 const MemAddr & i_addr,
                                 STEP_CODE_DATA_STRUCT & io_sc );

template<>
uint32_t __handleSoftInterCeEte<TYPE_MCA>( ExtensibleChip * i_chip,
                                           const MemAddr & i_addr,
                                           STEP_CODE_DATA_STRUCT & io_sc )
{
    return __handleNceEte<TYPE_MCA>( i_chip, i_addr, io_sc );
}

template<>
uint32_t __handleSoftInterCeEte<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                                 const MemAddr & i_addr,
                                                 STEP_CODE_DATA_STRUCT & io_sc )
{
    return __handleNceEte<TYPE_OCMB_CHIP>( i_chip, i_addr, io_sc );
}

template<>
uint32_t __handleSoftInterCeEte<TYPE_MBA>( ExtensibleChip * i_chip,
                                           const MemAddr & i_addr,
                                           STEP_CODE_DATA_STRUCT & io_sc )
{
    // Due to workarounds on the Centaur we are unable to stop on each
    // occurrence of the soft or intermittent CEs like we do for Nimbus.
    // Instead, the threshold is set much higher. If the threshold is hit we
    // simply want to add the rank to the callout list and trigger TPS.

    MemoryMru mm { i_chip->getTrgt(), i_addr.getRank(),
                   MemoryMruData::CALLOUT_RANK };
    io_sc.service_data->SetCallout( mm );

    TdEntry * e = new TpsEvent<TYPE_MBA>{ i_chip, i_addr.getRank() };
    MemDbUtils::pushToQueue<TYPE_MBA>( i_chip, e );

    return SUCCESS;
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __handleRceEte( ExtensibleChip * i_chip,
                         const MemRank & i_rank, bool & o_errorsFound,
                         STEP_CODE_DATA_STRUCT & io_sc );

template<>
uint32_t __handleRceEte<TYPE_MCA>( ExtensibleChip * i_chip,
                                   const MemRank & i_rank, bool & o_errorsFound,
                                   STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[__handleRceEte] "

    uint32_t o_rc = SUCCESS;

    // Should only get this attention in MNFG mode.
    PRDF_ASSERT( mfgMode() );

    do
    {
        // The RCE ETE attention could be from IUE, IMPE, or IRCD. Need to check
        // MCAECCFIR[37] to determine if there was at least one IUE.
        SCAN_COMM_REGISTER_CLASS * fir = i_chip->getRegister( "MCAECCFIR" );
        o_rc = fir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCAECCFIR: i_chip=0x%08x",
                      i_chip->getHuid() );
            break;
        }
        if ( !fir->IsBitSet(37) ) break; // nothing else to do

        // Handle the IUE.
        o_errorsFound = true;
        io_sc.service_data->AddSignatureList( i_chip->getTrgt(),
                                              PRDFSIG_MaintIUE );
        o_rc = MemEcc::handleMemIue<TYPE_MCA>( i_chip, i_rank, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeMaintIue(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t __handleRceEte<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                         const MemRank & i_rank,
                                         bool & o_errorsFound,
                                         STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[__handleRceEte] "

    uint32_t o_rc = SUCCESS;

    // Should only get this attention in MNFG mode.
    PRDF_ASSERT( mfgMode() );

    do
    {
        // The RCE ETE attention could be from IUE, IMPE, or IRCD. Need to check
        // RDFFIR[37] to determine if there was at least one IUE.
        SCAN_COMM_REGISTER_CLASS * fir = i_chip->getRegister( "RDFFIR" );
        o_rc = fir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on RDFFIR: i_chip=0x%08x",
                      i_chip->getHuid() );
            break;
        }
        if ( !fir->IsBitSet(37) ) break; // nothing else to do

        // Handle the IUE.
        o_errorsFound = true;
        io_sc.service_data->AddSignatureList( i_chip->getTrgt(),
                                              PRDFSIG_MaintIUE );
        o_rc = MemEcc::handleMemIue<TYPE_OCMB_CHIP>( i_chip, i_rank, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeMaintIue(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t __handleRceEte<TYPE_MBA>( ExtensibleChip * i_chip,
                                   const MemRank & i_rank, bool & o_errorsFound,
                                   STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[__handleRceEte] "

    uint32_t o_rc = SUCCESS;

    TargetHandle_t trgt = i_chip->getTrgt();

    o_errorsFound = true;
    io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintRETRY_CTE );

    // Add the rank to the callout list.
    MemoryMru mm { trgt, i_rank, MemoryMruData::CALLOUT_RANK };
    io_sc.service_data->SetCallout( mm );

    do
    {
        bool doTps = true;

        if ( mfgMode() )
        {
            ExtensibleChip * membChip = getConnectedParent(i_chip, TYPE_MEMBUF);

            // Get the current RCE count from hardware.
            const char * reg_str = (0 == i_chip->getPos()) ? "MBA0_MBSEC1"
                                                           : "MBA1_MBSEC1";
            SCAN_COMM_REGISTER_CLASS * reg = membChip->getRegister( reg_str );
            o_rc = reg->Read();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Read() failed on %s", reg_str );
                break;
            }
            uint16_t count = reg->GetBitFieldJustified( 0, 12 );

            // Add the count to RCE table.
            doTps = getMbaDataBundle(i_chip)->iv_rceTable.addEntry( i_rank,
                                                                    io_sc,
                                                                    count );
        }
        else
        {
            // The RCE threshold was set to the maximum. If we hit this then
            // there is definitely a problem.
            io_sc.service_data->setServiceCall();
        }

        // Add a TPS procedure to the queue, if needed.
        if ( doTps )
        {
            TdEntry * e = new TpsEvent<TYPE_MBA>{ i_chip, i_rank };
            MemDbUtils::pushToQueue<TYPE_MBA>( i_chip, e );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t __checkEcc( ExtensibleChip * i_chip,
                     const MemAddr & i_addr, bool & o_errorsFound,
                     STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[__checkEcc] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    o_errorsFound = false;

    TargetHandle_t trgt = i_chip->getTrgt();
    HUID           huid = i_chip->getHuid();

    MemRank rank = i_addr.getRank();

    do
    {
        // Check for ECC errors.
        uint32_t eccAttns = 0;
        o_rc = checkEccFirs<T>( i_chip, eccAttns );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccFirs<T>(0x%08x) failed", huid );
            break;
        }

        if ( 0 != (eccAttns & MAINT_INT_NCE_ETE) )
        {
            o_errorsFound = true;
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintINTER_CTE);

            o_rc = __handleSoftInterCeEte<T>( i_chip, i_addr, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__handleSoftInterCeEte<T>(0x%08x) failed",
                          huid );
                break;
            }
        }

        if ( 0 != (eccAttns & MAINT_SOFT_NCE_ETE) )
        {
            o_errorsFound = true;
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintSOFT_CTE );

            o_rc = __handleSoftInterCeEte<T>( i_chip, i_addr, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__handleSoftInterCeEte<T>(0x%08x) failed",
                          huid );
                break;
            }
        }

        if ( 0 != (eccAttns & MAINT_HARD_NCE_ETE) )
        {
            o_errorsFound = true;
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintHARD_CTE );

            o_rc = __handleNceEte<T>( i_chip, i_addr, io_sc, true );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__handleNceEte<T>(0x%08x) failed",
                          huid );
                break;
            }

            // Any hard CEs in MNFG should be immediately reported.
            // NOTE: We will only use the MNFG thresholds if DRAM repairs is
            //       disabled. This is for a Nimbus DD2.0.1 workaround, but the
            //       change will be permanent for all P9 DD levels.
            if ( areDramRepairsDisabled() )
            {
                io_sc.service_data->setSignature( huid, PRDFSIG_MaintHARD_CTE );
                io_sc.service_data->setServiceCall();
            }
        }

        if ( 0 != (eccAttns & MAINT_MPE) )
        {
            o_errorsFound = true;
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintMPE );

            o_rc = MemEcc::handleMpe<T>( i_chip, i_addr, UE_TABLE::SCRUB_MPE,
                                         io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMpe<T>(0x%08x, 0x%02x) failed",
                          i_chip->getHuid(), rank.getKey() );
                break;
            }
        }

        if ( 0 != (eccAttns & MAINT_RCE_ETE) )
        {
            o_rc = __handleRceEte<T>( i_chip, rank, o_errorsFound,
                                      io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__handleRceEte<T>(0x%08x) failed", huid );
                break;
            }
        }

        if ( 0 != (eccAttns & MAINT_UE) )
        {
            o_errorsFound = true;
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintUE );

            // Since this will be a predictive callout, change the primary
            // signature as well.
            io_sc.service_data->setSignature( huid, PRDFSIG_MaintUE );

            // Add the rank to the callout list.
            o_rc = MemEcc::handleMemUe<T>( i_chip, i_addr, UE_TABLE::SCRUB_UE,
                                           io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemUe<T>(0x%08x) failed",
                          i_chip->getHuid() );
                break;
            }

            // Add a TPS request to the TD queue for additional analysis. It is
            // unlikely the procedure will result in a repair because of the UE.
            // However, we want to run TPS once just to see how bad the rank is.
            TdEntry * e = new TpsEvent<T>{ i_chip, rank };
            MemDbUtils::pushToQueue<T>( i_chip, e );

            // Because of the UE, any further TPS requests will likely have no
            // effect. So ban all subsequent requests.
            MemDbUtils::banTps<T>( i_chip, rank );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t __checkEcc<TYPE_MCA>( ExtensibleChip * i_chip,
                               const MemAddr & i_addr, bool & o_errorsFound,
                               STEP_CODE_DATA_STRUCT & io_sc );
template
uint32_t __checkEcc<TYPE_MBA>( ExtensibleChip * i_chip,
                               const MemAddr & i_addr, bool & o_errorsFound,
                               STEP_CODE_DATA_STRUCT & io_sc );
template
uint32_t __checkEcc<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                     const MemAddr & i_addr,
                                     bool & o_errorsFound,
                                     STEP_CODE_DATA_STRUCT & io_sc );

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

        // Do not unmask NCE and TCE attentions if they have been permanently
        // masked due to certain TPS conditions.
        if ( !(getMcaDataBundle(mcaChip)->iv_maskMainlineNceTce) )
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
uint32_t MemTdCtlr<TYPE_OCMB_CHIP>::maskEccAttns()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_OCMB_CHIP>::maskEccAttns] "

    uint32_t o_rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * mask = iv_chip->getRegister( "RDFFIR_MASK_OR" );

    mask->clearAllBits();
    mask->SetBit(8); // Mainline read NCE
    mask->SetBit(9); // Mainline read TCE

    o_rc = mask->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on RDFFIR_MASK_OR" );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_OCMB_CHIP>::unmaskEccAttns()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_OCMB_CHIP>::unmaskEccAttns] "

    uint32_t o_rc = SUCCESS;

    // Memory CEs were masked at the beginning of the TD procedure, so
    // clear and unmask them. Also, it is possible that memory UEs have
    // thresholded so clear and unmask them as well.

    SCAN_COMM_REGISTER_CLASS * fir  = iv_chip->getRegister( "RDFFIR_AND" );
    SCAN_COMM_REGISTER_CLASS * mask = iv_chip->getRegister( "RDFFIR_MASK_AND" );

    fir->setAllBits(); mask->setAllBits();

    // Do not unmask NCE and TCE attentions if they have been permanently
    // masked due to certain TPS conditions.
    if ( !(getOcmbDataBundle(iv_chip)->iv_maskMainlineNceTce) )
    {
        fir->ClearBit(8);  mask->ClearBit(8);  // Mainline read NCE
        fir->ClearBit(9);  mask->ClearBit(9);  // Mainline read TCE
    }
    fir->ClearBit(14); mask->ClearBit(14); // Mainline read UE

    o_rc = fir->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on RDFFIR_AND" );
    }

    o_rc = mask->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on RDFFIR_MASK_AND" );
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

    do
    {
        // Don't want to handle memory CEs during any TD procedures, so
        // mask them.

        const char * reg_str = (0 == iv_chip->getPos())
            ? "MBSECCFIR_0_MASK_OR" : "MBSECCFIR_1_MASK_OR";

        ExtensibleChip * membChip = getConnectedParent( iv_chip, TYPE_MEMBUF );

        SCAN_COMM_REGISTER_CLASS * reg = membChip->getRegister(reg_str);

        reg->clearAllBits();
        reg->SetBit(16); // fetch NCE
        reg->SetBit(17); // fetch RCE
        reg->SetBit(43); // prefetch UE

        o_rc = reg->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on %s", reg_str );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MBA>::unmaskEccAttns()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MBA>::unmaskEccAttns] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Memory CEs where masked at the beginning of the TD procedure, so
        // clear and unmask them. Also, it is possible that memory UEs have
        // thresholded so clear and unmask them as well.

        const char * fir_str = (0 == iv_chip->getPos())
            ? "MBSECCFIR_0_AND" : "MBSECCFIR_1_AND";
        const char * msk_str = (0 == iv_chip->getPos())
            ? "MBSECCFIR_0_MASK_AND" : "MBSECCFIR_1_MASK_AND";

        ExtensibleChip * membChip = getConnectedParent( iv_chip, TYPE_MEMBUF );

        SCAN_COMM_REGISTER_CLASS * fir = membChip->getRegister( fir_str );
        SCAN_COMM_REGISTER_CLASS * msk = membChip->getRegister( msk_str );

        fir->setAllBits(); msk->setAllBits();
        fir->ClearBit(16); msk->ClearBit(16); // fetch NCE
        fir->ClearBit(17); msk->ClearBit(17); // fetch RCE
        fir->ClearBit(19); msk->ClearBit(19); // fetch UE
        fir->ClearBit(43); msk->ClearBit(43); // prefetch UE

        o_rc = fir->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on %s", fir_str );
            break;
        }

        o_rc = msk->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on %s", msk_str );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
SCAN_COMM_REGISTER_CLASS * __getEccFirAnd( ExtensibleChip * i_chip );

template<>
SCAN_COMM_REGISTER_CLASS * __getEccFirAnd<TYPE_MCA>( ExtensibleChip * i_chip )
{
    return i_chip->getRegister( "MCAECCFIR_AND" );
}

template<>
SCAN_COMM_REGISTER_CLASS * __getEccFirAnd<TYPE_OCMB_CHIP>(
                                                ExtensibleChip * i_chip )
{
    return i_chip->getRegister( "RDFFIR_AND" );
}

template<>
SCAN_COMM_REGISTER_CLASS * __getEccFirAnd<TYPE_MBA>( ExtensibleChip * i_chip )
{
    ExtensibleChip * membChip = getConnectedParent( i_chip, TYPE_MEMBUF );
    return membChip->getRegister( (0 == i_chip->getPos()) ? "MBSECCFIR_0_AND"
                                                          : "MBSECCFIR_1_AND" );
}

template <TARGETING::TYPE TP, TARGETING::TYPE TC>
uint32_t __findChipMarks( TdRankList<TC> & i_rankList )
{
    #define PRDF_FUNC "[__findChipMarks] "

    uint32_t o_rc = SUCCESS;

    for ( auto & entry : i_rankList.getList() )
    {
        ExtensibleChip * chip = entry.getChip();
        MemRank          rank = entry.getRank();

        // Call readChipMark to get MemMark.
        MemMark chipMark;
        o_rc = MarkStore::readChipMark<TP>( chip, rank, chipMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readChipMark(0x%08x,0x%02x) failed",
                      chip->getHuid(), rank.getKey() );
            break;
        }

        if ( !chipMark.isValid() ) continue; // no chip mark present

        // Get the DQ Bitmap data.
        MemDqBitmap dqBitmap;
        o_rc = getBadDqBitmap( chip->getTrgt(), rank, dqBitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap(0x%08x,0x%02x)",
                      chip->getHuid(), rank.getKey() );
            break;
        }

        // Check if the chip mark is verified or not.
        bool cmVerified = false;
        o_rc = dqBitmap.isChipMark( chipMark.getSymbol(), cmVerified );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "dqBitmap.isChipMark() failed on 0x%08x "
                      "0x%02x", chip->getHuid(), rank.getKey() );
            break;
        }

        // If the chip mark is unverified, add a VcmEvent to the TD queue.
        if ( !cmVerified )
        {
            // Chip mark is not present in VPD. Add it to queue.
            TdEntry * e = new VcmEvent<TP>{ chip, rank, chipMark };
            MemDbUtils::pushToQueue<TP>( chip, e );

            // We will want to clear the MPE attention for the unverified chip
            // mark so we don't get any redundant attentions for chip marks that
            // are already in the queue. This is reset/reload safe because
            // initialize() will be called again and we can redetect the
            // unverified chip marks.
            SCAN_COMM_REGISTER_CLASS * reg = __getEccFirAnd<TP>( chip );
            reg->setAllBits();
            reg->ClearBit(  0 + rank.getMaster() ); // fetch
            reg->ClearBit( 20 + rank.getMaster() ); // scrub
            o_rc = reg->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on ECC FIR AND: 0x%08x",
                          chip->getHuid() );
                break;
            }
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t MemTdCtlr<TYPE_MCBIST>::initialize()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MCBIST>::initialize] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( iv_initialized ) break; // nothing to do

        // Unmask the fetch attentions just in case there were masked during a
        // TD procedure prior to a reset/reload.
        o_rc = unmaskEccAttns();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "unmaskEccAttns() failed" );
            break;
        }

        // Find all unverified chip marks.
        o_rc = __findChipMarks<TYPE_MCA>( iv_rankList );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "__findChipMarks() failed on 0x%08x",
                      iv_chip->getHuid() );
            break;
        }

        // At this point, the TD controller is initialized.
        iv_initialized = true;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t MemTdCtlr<TYPE_OCMB_CHIP>::initialize()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_OCMB_CHIP>::initialize] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( iv_initialized ) break; // nothing to do

        // Unmask the fetch attentions just in case there were masked during a
        // TD procedure prior to a reset/reload.
        o_rc = unmaskEccAttns();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "unmaskEccAttns() failed" );
            break;
        }

        // Find all unverified chip marks.
        o_rc = __findChipMarks<TYPE_OCMB_CHIP>( iv_rankList );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "__findChipMarks() failed on 0x%08x",
                      iv_chip->getHuid() );
            break;
        }

        // At this point, the TD controller is initialized.
        iv_initialized = true;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t MemTdCtlr<TYPE_MBA>::initialize()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MBA>::initialize] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( iv_initialized ) break; // nothing to do

        // Unmask the fetch attentions just in case there were masked during a
        // TD procedure prior to a reset/reload.
        o_rc = unmaskEccAttns();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "unmaskEccAttns() failed" );
            break;
        }

        // Find all unverified chip marks.
        o_rc = __findChipMarks<TYPE_MBA>( iv_rankList );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "__findChipMarks() failed on 0x%08x",
                      iv_chip->getHuid() );
            break;
        }

        // At this point, the TD controller is initialized.
        iv_initialized = true;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MCBIST>::handleRrFo()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MCBIST>::handleRrFo] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Check if maintenance command complete attention is set.
        SCAN_COMM_REGISTER_CLASS * mcbistfir =
                                iv_chip->getRegister("MCBISTFIR");
        o_rc = mcbistfir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCBISTFIR");
            break;
        }

        // If there is a command complete attention, nothing to do, break out.
        if ( mcbistfir->IsBitSet(10) ||  mcbistfir->IsBitSet(12) )
            break;


        // Check if a command is not running.
        // If bit 0 of MCB_CNTLSTAT is on, a mcbist run is in progress.
        SCAN_COMM_REGISTER_CLASS * mcb_cntlstat =
            iv_chip->getRegister("MCB_CNTLSTAT");
        o_rc = mcb_cntlstat->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCB_CNTLSTAT" );
            break;
        }

        // If a command is not running, set command complete attn, break.
        if ( !mcb_cntlstat->IsBitSet(0) )
        {
            SCAN_COMM_REGISTER_CLASS * mcbistfir_or =
                iv_chip->getRegister("MCBISTFIR_OR");
            mcbistfir_or->SetBit( 10 );

            mcbistfir_or->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on MCBISTFIR_OR" );
            }
            break;
        }

        // Check if there are unverified chip marks.
        std::vector<TdRankListEntry> vectorList = iv_rankList.getList();

        for ( auto & entry : vectorList )
        {
            ExtensibleChip * mcaChip = entry.getChip();
            MemRank rank = entry.getRank();

            // Get the chip mark
            MemMark chipMark;
            o_rc = MarkStore::readChipMark<TYPE_MCA>( mcaChip, rank, chipMark );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark<TYPE_MCA>(0x%08x,%d) "
                        "failed", mcaChip->getHuid(), rank.getMaster() );
                break;
            }

            if ( !chipMark.isValid() ) continue; // no chip mark present

            // Get the DQ Bitmap data.
            TargetHandle_t mcaTrgt = mcaChip->GetChipHandle();
            MemDqBitmap dqBitmap;

            o_rc = getBadDqBitmap( mcaTrgt, rank, dqBitmap );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getBadDqBitmap(0x%08x, %d)",
                          getHuid(mcaTrgt), rank.getMaster() );
                break;
            }

            // Check if the chip mark is verified or not.
            bool cmVerified = false;
            o_rc = dqBitmap.isChipMark( chipMark.getSymbol(), cmVerified );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "dqBitmap.isChipMark failed." );
                break;
            }

            // If there are any unverified chip marks, stop the command, break.
            if ( !cmVerified )
            {
                o_rc = stopBgScrub<TYPE_MCBIST>( iv_chip );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "stopBgScrub<TYPE_MCBIST>(0x%08x) "
                              "failed", iv_chip->getHuid() );
                }
                break;
            }
        }

    } while (0);

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_OCMB_CHIP>::handleRrFo()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_OCMB_CHIP>::handleRrFo] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Check if maintenance command complete attention is set.
        SCAN_COMM_REGISTER_CLASS * mcbistfir =
                                iv_chip->getRegister("MCBISTFIR");
        o_rc = mcbistfir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCBISTFIR");
            break;
        }

        // If there is a command complete attention, nothing to do, break out.
        if ( mcbistfir->IsBitSet(10) )
            break;


        // Check if a command is not running.
        // If bit 0 of MCB_CNTLSTAT is on, a mcbist run is in progress.
        SCAN_COMM_REGISTER_CLASS * mcb_cntlstat =
            iv_chip->getRegister("MCB_CNTLSTAT");
        o_rc = mcb_cntlstat->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCB_CNTLSTAT" );
            break;
        }

        // If a command is not running, set command complete attn, break.
        if ( !mcb_cntlstat->IsBitSet(0) )
        {
            SCAN_COMM_REGISTER_CLASS * mcbistfir_or =
                iv_chip->getRegister("MCBISTFIR_OR");
            mcbistfir_or->SetBit( 10 );

            mcbistfir_or->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on MCBISTFIR_OR" );
            }
            break;
        }

        // Check if there are unverified chip marks.
        std::vector<TdRankListEntry> vectorList = iv_rankList.getList();

        for ( auto & entry : vectorList )
        {
            ExtensibleChip * ocmbChip = entry.getChip();
            MemRank rank = entry.getRank();

            // Get the chip mark
            MemMark chipMark;
            o_rc = MarkStore::readChipMark<TYPE_OCMB_CHIP>( ocmbChip, rank,
                                                            chipMark );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark<TYPE_OCMB_CHIP>(0x%08x,%d) "
                          "failed", ocmbChip->getHuid(), rank.getMaster() );
                break;
            }

            if ( !chipMark.isValid() ) continue; // no chip mark present

            // Get the DQ Bitmap data.
            MemDqBitmap dqBitmap;

            o_rc = getBadDqBitmap( ocmbChip->getTrgt(), rank, dqBitmap );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getBadDqBitmap(0x%08x, %d)",
                          ocmbChip->getHuid(), rank.getMaster() );
                break;
            }

            // Check if the chip mark is verified or not.
            bool cmVerified = false;
            o_rc = dqBitmap.isChipMark( chipMark.getSymbol(), cmVerified );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "dqBitmap.isChipMark failed." );
                break;
            }

            // If there are any unverified chip marks, stop the command, break.
            if ( !cmVerified )
            {
                o_rc = stopBgScrub<TYPE_OCMB_CHIP>( iv_chip );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "stopBgScrub<TYPE_OCMB_CHIP>(0x%08x) "
                              "failed", iv_chip->getHuid() );
                }
                break;
            }
        }

    } while (0);

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MBA>::handleRrFo()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MBA>::handleRrFo] "

     uint32_t o_rc = SUCCESS;

    do
    {
        // Check if maintenance command complete attention is set.
        SCAN_COMM_REGISTER_CLASS * mbaspa =
                                iv_chip->getRegister("MBASPA");
        o_rc = mbaspa->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBASPA");
            break;
        }

        // If there is a command complete attention, nothing to do, break out.
        if ( mbaspa->IsBitSet(0) ||  mbaspa->IsBitSet(8) )
            break;

        // Check if a maintenance command is running currently.
        SCAN_COMM_REGISTER_CLASS * mbmsr =
                                iv_chip->getRegister("MBMSR");

        o_rc = mbmsr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBMSR");
            break;
        }

        // If a command is not running, set command complete attn, break.
        if ( !mbmsr->IsBitSet(0) )
        {
            SCAN_COMM_REGISTER_CLASS * mbaspa_or =
                iv_chip->getRegister("MBASPA_OR");
            mbaspa_or->SetBit( 0 );

            mbaspa_or->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on MBASPA_OR" );
            }
            break;
        }

        // Check if there are unverified chip marks.
        std::vector<TdRankListEntry> vectorList = iv_rankList.getList();

        for ( auto & entry : vectorList )
        {
            ExtensibleChip * mbaChip = entry.getChip();
            MemRank rank = entry.getRank();

            // Get the chip mark
            MemMark chipMark;
            o_rc = MarkStore::readChipMark<TYPE_MBA>( mbaChip, rank, chipMark );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark<TYPE_MBA>(0x%08x,%d) "
                        "failed", mbaChip->getHuid(), rank.getMaster() );
                break;
            }

            if ( !chipMark.isValid() ) continue; // no chip mark present

            // Get the DQ Bitmap data.
            TargetHandle_t mbaTrgt = mbaChip->GetChipHandle();
            MemDqBitmap dqBitmap;

            o_rc = getBadDqBitmap( mbaTrgt, rank, dqBitmap );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getBadDqBitmap(0x%08x, %d)",
                          getHuid(mbaTrgt), rank.getMaster() );
                break;
            }

            // Check if the chip mark is verified or not.
            bool cmVerified = false;
            o_rc = dqBitmap.isChipMark( chipMark.getSymbol(), cmVerified );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "dqBitmap.isChipMark failed." );
                break;
            }

            // If there are any unverified chip marks, stop the command, break.
            if ( !cmVerified )
            {
                o_rc = stopBgScrub<TYPE_MBA>( iv_chip );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "stopBgScrub<TYPE_MBA>(0x%08x) failed",
                            iv_chip->getHuid() );
                }

                // The HWP that stops the command apparently clears the command
                // complete attention, which we were not expecting. Therefore,
                // we must manually set the attention.
                SCAN_COMM_REGISTER_CLASS * mbaspa_or =
                                            iv_chip->getRegister("MBASPA_OR");
                mbaspa_or->SetBit( 0 );

                mbaspa_or->Write();
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "Write() failed on MBASPA_OR" );
                }

                // There is now a command complete attention for this MBA. So
                // break out of the for-loop.
                break;
            }
        }

    } while (0);

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MCBIST>::canResumeBgScrub( bool & o_canResume,
        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MCBIST>::canResumeBgScrub] "

    uint32_t o_rc = SUCCESS;

    o_canResume = false;

    // It is possible that we were running a TD procedure and the PRD service
    // was reset. Therefore, we must check if background scrubbing was actually
    // configured. There really is not a good way of doing this. A scrub command
    // is a scrub command the only difference is the speed. Unfortunately, that
    // speed can change depending on how the hardware team tunes it. For now, we
    // can use the stop conditions, which should be unique for background scrub,
    // to determine if it has been configured.

    do
    {
        SCAN_COMM_REGISTER_CLASS * reg = iv_chip->getRegister( "MBSTR" );
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBSTR: iv_chip=0x%08x",
                    iv_chip->getHuid() );
            break;
        }
        // Note: The stop conditions for background scrubbing can now be
        // variable depending on whether we have hit threshold for the number
        // of UEs or CEs that we have stopped on on a rank.

        // If we haven't hit CE or UE threshold, check the CE stop conditions
        if ( !getMcbistDataBundle(iv_chip)->iv_ceStopCounter.thReached(io_sc) &&
             !getMcbistDataBundle(iv_chip)->iv_ueStopCounter.thReached(io_sc) )
        {
            // If the stop conditions aren't set, just break out.
            if ( !(0xf != reg->GetBitFieldJustified(0,4) && // NCE int TH
                   0xf != reg->GetBitFieldJustified(4,4) && // NCE soft TH
                   0xf != reg->GetBitFieldJustified(8,4)) ) // NCE hard TH
            {
                break;
            }

        }

        // If we haven't hit UE threshold yet, check the UE stop condition
        if ( !getMcbistDataBundle(iv_chip)->iv_ueStopCounter.thReached(io_sc) )
        {
            // If the stop condition isn't set, just break out
            if ( !reg->IsBitSet(35) ) // pause on UE
            {
                break;
            }
        }

        // Need to check the stop on mpe stop condition regardless of whether
        // we hit the UE or CE threshold.
        if ( reg->IsBitSet(34) ) // pause on MPE
        {
            // If we reach here, all the stop conditions are set for background
            // scrub, so we can resume.
            o_canResume = true;
        }
    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t MemTdCtlr<TYPE_OCMB_CHIP>::canResumeBgScrub( bool & o_canResume,
        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_OCMB_CHIP>::canResumeBgScrub] "

    uint32_t o_rc = SUCCESS;

    o_canResume = false;

    // It is possible that we were running a TD procedure and the PRD service
    // was reset. Therefore, we must check if background scrubbing was actually
    // configured. There really is not a good way of doing this. A scrub command
    // is a scrub command the only difference is the speed. Unfortunately, that
    // speed can change depending on how the hardware team tunes it. For now, we
    // can use the stop conditions, which should be unique for background scrub,
    // to determine if it has been configured.

    do
    {
        SCAN_COMM_REGISTER_CLASS * reg = iv_chip->getRegister( "MBSTR" );
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBSTR: iv_chip=0x%08x",
                    iv_chip->getHuid() );
            break;
        }
        // Note: The stop conditions for background scrubbing can now be
        // variable depending on whether we have hit threshold for the number
        // of UEs or CEs that we have stopped on on a rank.

        // If we haven't hit CE or UE threshold, check the CE stop conditions
        if ( !getOcmbDataBundle(iv_chip)->iv_ceStopCounter.thReached(io_sc) &&
             !getOcmbDataBundle(iv_chip)->iv_ueStopCounter.thReached(io_sc) )
        {
            // If the stop conditions aren't set, just break out.
            if ( !(0xf != reg->GetBitFieldJustified(0,4) && // NCE int TH
                   0xf != reg->GetBitFieldJustified(4,4) && // NCE soft TH
                   0xf != reg->GetBitFieldJustified(8,4)) ) // NCE hard TH
            {
                break;
            }

        }

        // If we haven't hit UE threshold yet, check the UE stop condition
        if ( !getOcmbDataBundle(iv_chip)->iv_ueStopCounter.thReached(io_sc) )
        {
            // If the stop condition isn't set, just break out
            if ( !reg->IsBitSet(35) ) // pause on UE
            {
                break;
            }
        }

        // Need to check the stop on mpe stop condition regardless of whether
        // we hit the UE or CE threshold.
        if ( reg->IsBitSet(34) ) // pause on MPE
        {
            // If we reach here, all the stop conditions are set for background
            // scrub, so we can resume.
            o_canResume = true;
        }
    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t MemTdCtlr<TYPE_MBA>::canResumeBgScrub( bool & o_canResume,
        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MBA>::canResumeBgScrub] "

    uint32_t o_rc = SUCCESS;

    o_canResume = false;

    // It is possible that we were running a TD procedure and the PRD service
    // was reset. Assuming the command did not stop on the last address of the
    // current slave rank, we will simply "resume" the command from the next
    // address to the end of the rank. The MBA resume actually starts a new
    // command, unlike MCBIST. Therefore, we can get away with blindly starting
    // the command without trying to assess what type of command was actually
    // running.

    bool lastAddr = false;
    o_rc = didCmdStopOnLastAddr<TYPE_MBA>( iv_chip, SLAVE_RANK, lastAddr );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "didCmdStopOnLastAddr(0x%08x) failed",
                  iv_chip->getHuid() );
    }
    else
    {
        o_canResume = !lastAddr;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class MemTdCtlr<TYPE_MCBIST>;
template class MemTdCtlr<TYPE_MBA>;
template class MemTdCtlr<TYPE_OCMB_CHIP>;

//------------------------------------------------------------------------------

} // end namespace PRDF


