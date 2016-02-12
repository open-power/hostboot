/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/runtime/prdfCenMbaTdCtlr_rt.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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

#include <prdfCenMbaTdCtlr_rt.H>

// Framework includes
#include <iipconst.h>
#include <prdfGlobal.H>
#include <prdfTrace.H>
#include <prdfExtensibleChip.H>
#include <prdfPlatServices.H>
#include <UtilHash.H>
#include <prdfRegisterCache.H>

#ifndef __HOSTBOOT_RUNTIME
  #include <prdfSdcFileControl.H>
#endif

// Pegasus includes
#include <prdfCenAddress.H>
#include <prdfCenDqBitmap.H>
#include <prdfCenMbaDataBundle.H>
#include <prdfCenMbaExtraSig.H>
#include <prdfCalloutUtil.H>
#include <prdfCenMemUtils.H>
#include <prdfCenMbaThresholds.H>
#include <prdfCenMbaDynMemDealloc_rt.H>

using namespace TARGETING;

namespace PRDF
{

using namespace CalloutUtil;
using namespace PlatServices;
using namespace MemUtils;

//------------------------------------------------------------------------------
//                            Class Variables
//------------------------------------------------------------------------------

CenMbaTdCtlr::FUNCS CenMbaTdCtlr::cv_cmdCompleteFuncs[] =
{
    &CenMbaTdCtlr::analyzeCmdComplete,      // NO_OP
    &CenMbaTdCtlr::analyzeVcmPhase1,        // VCM_PHASE_1
    &CenMbaTdCtlr::analyzeVcmPhase2,        // VCM_PHASE_2
    &CenMbaTdCtlr::analyzeDsdPhase1,        // DSD_PHASE_1
    NULL,                                   // DSD_PHASE_2
    &CenMbaTdCtlr::analyzeTpsPhase1,        // TPS_PHASE_1
    NULL,                                   // TPS_PHASE_2
};

//------------------------------------------------------------------------------
//                            Public Functions
//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleCmdCompleteEvent( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleCmdCompleteEvent] "

    int32_t o_rc = SUCCESS;

    do
    {
        o_rc = initialize();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "initialize() failed" );
            break;
        }

        collectStateCaptureDataStart( io_sc );

        // Get address in which the command stopped and the end address.
        // Some analysis is dependent on if the maintenance command has reached
        // the end address or stopped in the middle.
        CenAddr stopAddr;
        o_rc = getCenMaintStartAddr( iv_mbaChip, stopAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getCenMaintStartAddr() failed" );
            break;
        }

        CenAddr endAddr;
        o_rc = getCenMaintEndAddr( iv_mbaChip, endAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getCenMaintEndAddr() failed" );
            break;
        }

        // Call analysis function based on state.
        if ( NULL == cv_cmdCompleteFuncs[iv_tdState] )
        {
            PRDF_ERR( PRDF_FUNC "Function for state %d not supported",
                      iv_tdState );
            o_rc = FAIL; break;
        }

        o_rc = (this->*cv_cmdCompleteFuncs[iv_tdState])( io_sc, stopAddr,
                                                         endAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Failed to continue analysis" );
            break;
        }

    } while(0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed." );
        badPathErrorHandling( io_sc );

        int32_t l_rc = cleanupPrevCmd( io_sc ); // Just in case.
        if ( SUCCESS != l_rc )
            PRDF_ERR( PRDF_FUNC "cleanupPrevCmd() failed" );

        // Will not resume background scrubbing because that may be the root
        // cause of the failure.
    }
    else
    {
        collectStateCaptureDataEnd( io_sc );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc,
                                     const CenRank & i_rank,
                                     const TdType i_event,
                                     bool i_banTps )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleTdEvent] "

    int32_t o_rc = SUCCESS;

    do
    {
        o_rc = initialize();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "initialize() failed" );
            break;
        }

        collectStateCaptureDataStart( io_sc );

        // Add a new entry to the queue.
        if ( VCM_EVENT == i_event )
            o_rc = addTdQueueEntryVCM( i_rank );
        else if ( TPS_EVENT == i_event )
            o_rc = addTdQueueEntryTPS( i_rank, io_sc, i_banTps );
        else
            o_rc = FAIL;

        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Failed to add TD queue entry" );
            break;
        }

        // Don't interrupt a TD procedure if one is already in progress.
        if ( isInTdMode() ) break;

        // If the fetch attentions are already masked, then this must have been
        // a TPS request due to a memory UE, which will eventually be
        // thresholded by the rule code. Therefore, there is no need to stop
        // background scrubbing.
        if ( (TPS_EVENT == i_event) && iv_fetchAttnsMasked ) break;

        // Stop background scrubbing. Whether to start a new TD procedure or to
        // temporarily mask TPS triggers while TPS is banned to prevent
        // flooding.
        if ( NULL == iv_mssCmd )
        {
            // This scenario will only exist if there was a resest/reload or
            // failover. It should be safe to just make a dummy command so that
            // we can stop the current command.
            iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::TIMEBASE_SCRUB,
                                      iv_mbaTrgt, CenRank(0), 0 );
            if ( NULL == iv_mssCmd )
            {
                PRDF_ERR( PRDF_FUNC "createMssCmd() failed" );
                break;
            }

            o_rc = iv_mssCmd->stopCmd();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "stopCmd() failed" );
                break;
            }

            // We don't want to chance calling cleanupCmd() on this command
            // since we created a temporary command object just to stop
            // background scrubbing. Therefore, delete the object.
            delete iv_mssCmd; iv_mssCmd = NULL;
        }
        else
        {
            o_rc = iv_mssCmd->stopCmd();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "stopCmd() failed" );
                break;
            }
        }

        // If the queue is empty, there were no pending requests and the new
        // TPS request was blocked. In this case, we need to temporarily mask
        // TPS triggers (except memory UEs) while TPS is banned to prevent
        // flooding.
        if ( iv_queue.empty() )
        {
            o_rc = maskFetchAttns();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "maskFetchAttns() failed" );
                break;
            }
        }

        // Since we had to manually stop the maintenance command we should
        // refresh all relevant registers that may have changed state.

        RegDataCache & cache = RegDataCache::getCachedRegisters();

        const char * membRegs[2][18] =
        {
            { "MBA0_MBSECCFIR", "MBA0_MBSECCFIR_MASK",
              "MBA0_MBSECCFIR_ACT0", "MBA0_MBSECCFIR_ACT1",
              "MBA0_MBSECCERRPT_0","MBA0_MBSECCERRPT_1",
              "MBA0_MBSEC0", "MBA0_MBSEC1", "MBA0_MBSTR",
              "MBA0_MBSSYMEC0", "MBA0_MBSSYMEC1", "MBA0_MBSSYMEC2",
              "MBA0_MBSSYMEC3", "MBA0_MBSSYMEC4", "MBA0_MBSSYMEC5",
              "MBA0_MBSSYMEC6", "MBA0_MBSSYMEC7", "MBA0_MBSSYMEC8", },
            { "MBA1_MBSECCFIR", "MBA1_MBSECCFIR_MASK",
              "MBA1_MBSECCFIR_ACT0", "MBA1_MBSECCFIR_ACT1",
              "MBA1_MBSECCERRPT_0","MBA1_MBSECCERRPT_1",
              "MBA1_MBSEC0", "MBA1_MBSEC1", "MBA1_MBSTR",
              "MBA1_MBSSYMEC0", "MBA1_MBSSYMEC1", "MBA1_MBSSYMEC2",
              "MBA1_MBSSYMEC3", "MBA1_MBSSYMEC4", "MBA1_MBSSYMEC5",
              "MBA1_MBSSYMEC6", "MBA1_MBSSYMEC7", "MBA1_MBSSYMEC8", },
        };
        for ( uint32_t i = 0; i < 18; i++ )
        {
            SCAN_COMM_REGISTER_CLASS * reg
                           = iv_membChip->getRegister( membRegs[iv_mbaPos][i] );
            cache.flush( iv_membChip, reg );
        }

        const char * mbaRegs[8] =
        {
            "MBASPA", "MBASPA_MASK", "MBMCT", "MBMSR", "MBMACA", "MBMEA",
            "MBASCTL", "MBAECTL",
        };
        for ( uint32_t i = 0; i < 8; i++ )
        {
            SCAN_COMM_REGISTER_CLASS * reg
                                    = iv_mbaChip->getRegister( mbaRegs[i] );
            cache.flush( iv_mbaChip, reg );
        }

        // Now recapture those registers.

        CaptureData & cd = io_sc.service_data->GetCaptureData();

        if ( 0 == iv_mbaPos )
        {
            iv_membChip->CaptureErrorData(cd,
                                        Util::hashString("MaintCmdRegs_mba0") );
        }
        else
        {
            iv_membChip->CaptureErrorData(cd,
                                        Util::hashString("MaintCmdRegs_mba1") );
        }

        iv_mbaChip->CaptureErrorData(cd, Util::hashString("MaintCmdRegs"));

        // Start the next diagnostics procedure. It is possible that background
        // scrub could have found an ECC error before we had a chance to stop
        // the command. Therefore, we need to call analyzeCmdComplete() instead
        // of startNextTd() so that any ECC errors found can be handled. Also,
        // analyzeCmdComplete() will initialize the interrupted rank so that we
        // can calculate the 'next good rank'.

        CenAddr stopAddr;
        o_rc = getCenMaintStartAddr( iv_mbaChip, stopAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getCenMaintStartAddr() failed" );
            break;
        }

        CenAddr endAddr;
        o_rc = getCenMaintEndAddr( iv_mbaChip, endAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getCenMaintEndAddr() failed" );
            break;
        }

        o_rc = analyzeCmdComplete( io_sc, stopAddr, endAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeCmdComplete() failed" );
            break;
        }

    } while(0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed: i_event=%d i_rank=m%ds%d i_banTps=%c",
                  i_event, i_rank.getMaster(), i_rank.getSlave(),
                  i_banTps ? 'T' : 'F' );

        badPathErrorHandling( io_sc );

        int32_t l_rc = cleanupPrevCmd( io_sc ); // Just in case.
        if ( SUCCESS != l_rc )
            PRDF_ERR( PRDF_FUNC "cleanupPrevCmd() failed" );
    }
    else
    {
        collectStateCaptureDataEnd( io_sc );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleRrFo()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleRrFo] "

    int32_t o_rc = SUCCESS;

    do
    {
        // NOTE: For performance reasons, we will not call initialize() yet.
        //       Instead, we will first query the hardware to determine if the
        //       TD controller even needed to be involved. Then we will call
        //       initialize(), if needed.

        // Check for condition which may require to start a maintenance
        // command during R/R or F/o.
        // We will not start maintenance for any of  following conditions
        // 1. Maintenance command is already running.
        // 2. Maintenance command complete bit is set.

        // Check if maintenance command is running currently.
        SCAN_COMM_REGISTER_CLASS * mbmsr =
                                iv_mbaChip->getRegister("MBMSR");

        o_rc = mbmsr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBMSR");
            break;
        }

        if ( mbmsr->IsBitSet(0) )
            break;

        // Check if maintenance command complete attention is set.
        SCAN_COMM_REGISTER_CLASS * mbaSpa =
                                iv_mbaChip->getRegister("MBASPA");
        o_rc = mbaSpa->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBASPA");
            break;
        }

        if ( mbaSpa->IsBitSet(0) ||  mbaSpa->IsBitSet(8) )
            break;

        // Now that we know we need to use the TD controller, initialize it.
        o_rc = initialize();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "initialize() failed" );
            break;
        }

        // Create a temporary sdc as we do not want to write separate
        // version for startBgScrub during R/R and FO
        // Also we do not want to save this SDC. So set the "Don't save sdc"
        // flag.
        ServiceDataCollector serviceData;
        STEP_CODE_DATA_STRUCT sdc;
        sdc.service_data = &serviceData;
        sdc.service_data->setFlag( ServiceDataCollector::DONT_SAVE_SDC );

        o_rc = startNextTd( sdc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startBgScrub() failed" );
            break;
        }
    } while (0);

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------
//                            Private Functions
//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::initialize()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::initialize] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( iv_initialized ) break; // nothing to do

        // Initialize common instance variables
        o_rc = CenMbaTdCtlrCommon::initialize();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "CenMbaTdCtlrCommon::initialize() failed" );
            break;
        }

        // Initialize the list of master ranks.
        o_rc = iv_masterRanks.initialize( iv_mbaTrgt );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "TdRankList::initialize() failed" );
            break;
        }

        // Unmask the fetch attentions just in case there were masked during a
        // TD procedure prior to a reset/reload.
        o_rc = unmaskFetchAttns();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "unmaskFetchAttns() failed" );
            break;
        }

        //----------------------------------------------------------------------
        // Add any unverified chip marks to the TD queue
        //----------------------------------------------------------------------

        // Will want to clear the MPE attention for any unverified chip marks.
        // This is so we don't get redundant attentions for chip marks that are
        // already in the queue. This is reset/reload safe because initialize()
        // will be called again and we can redetect the unverified chip marks.

        const char * reg_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR_AND"
                                                : "MBA1_MBSECCFIR_AND";
        SCAN_COMM_REGISTER_CLASS * firand = iv_membChip->getRegister( reg_str );
        firand->setAllBits();

        // Search all configured ranks for unverfied chip marks.
        TdRankList::List rankList = iv_masterRanks.getList();
        for ( TdRankList::ListItr it = rankList.begin();
              it != rankList.end(); it++ )
        {
            CenMark markData;
            CenRank rank ( it->rank );

            // Get mark store from hardware.
            o_rc = mssGetMarkStore( iv_mbaTrgt, rank, markData );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "mssGetMarkStore() failed." );
                o_rc = FAIL; break;
            }

            // Move on to the next rank if there is no chip mark in hardware.
            if ( !markData.getCM().isValid() ) continue;

            // Check if chip mark also present in VPD.
            CenDqBitmap bitmap;
            o_rc = getBadDqBitmap( iv_mbaTrgt, rank, bitmap );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed" );
                break;
            }

            bool vpdCM;
            o_rc = bitmap.isChipMark( markData.getCM(), vpdCM );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "isChipMark() failed" );
                break;
            }

            if ( !vpdCM )
            {
                PRDF_INF( PRDF_FUNC "Adding CM to queue: huid=0x%08x rank=%d",
                          iv_mbaChip->GetId(), rank.getMaster() );

                // Chip mark is not present in VPD. Add it to queue.
                o_rc = addTdQueueEntryVCM( rank );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "addTdQueueEntryVCM() failed" );
                    break;
                }

                // Clear MPE bits for this rank.
                firand->ClearBit(  0 + rank.getMaster() ); // fetch
                firand->ClearBit( 20 + rank.getMaster() ); // scrub
            }
        }
        if ( SUCCESS != o_rc ) break;

        if ( !iv_queue.empty() )
        {
            // Unverified chip marks found so clear the FIR bits.
            o_rc = firand->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on %s", reg_str );
                break;
            }
        }

        //----------------------------------------------------------------------
        // At this point, the TD controller is initialized.
        //----------------------------------------------------------------------

        iv_initialized = true;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::analyzeCmdComplete( STEP_CODE_DATA_STRUCT & io_sc,
                                          const CenAddr & i_stopAddr,
                                          const CenAddr & i_endAddr )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::analyzeCmdComplete] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( NO_OP != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Initialize iv_rank. This must be done before calling other
        // functions as they require iv_rank to be accurate.
        iv_rank = i_stopAddr.getRank();

        // Background scrubbing was interrupted, most likely because of an ECC
        // error, so set the interrupted rank in the rank list.
        o_rc = iv_masterRanks.setInterruptedRank( iv_rank );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setInterruptedRank() failed" );
            break;
        }

        // Get all reported error conditions.
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccErrors() failed" );
            break;
        }

        // The order of the following checks is important. Each call to handle
        // an error will set the PRD signature and override the previous
        // signature. We want the highest priority error signature (memory UEs)
        // to be displayed so these checks should be ordered from lowest to
        // highest priority.

        if ( (eccErrorMask & SOFT_CTE) || (eccErrorMask & INTER_CTE) )
        {
            o_rc = handleSoftIntCeEte_NonTd( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleSoftIntCeEte_NonTd() failed" );
                break;
            }
        }

        if ( eccErrorMask & HARD_CTE )
        {
            o_rc = handleHardCeEte_NonTd( io_sc, i_stopAddr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleHardCeEte_NonTd() failed" );
                break;
            }
        }

        if ( eccErrorMask & RETRY_CTE )
        {
            o_rc = handleRceEte_NonTd( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleRceEte_NonTd() failed" );
                break;
            }
        }

        if ( eccErrorMask & MPE )
        {
            o_rc = handleMpe_NonTd( io_sc, i_stopAddr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMpe_NonTd() failed" );
                break;
            }
        }

        if ( eccErrorMask & UE )
        {
            o_rc = handleUe_NonTd( io_sc, i_stopAddr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleUe_NonTd() failed" );
                break;
            }
        }

        if ( iv_queue.empty() )
        {
            // No TD requests so resume background. If the scrub reached the end
            // address, start background scrubbing on the next good rank.
            // Otherwise, resume the current scrub.

            if ( i_endAddr == i_stopAddr )
            {
                if ( (NO_ERROR == eccErrorMask) || (MCE == eccErrorMask) )
                {
                    // The scrub completed without an error (this function
                    // currently ignores MCEs). Don't commit the error log
                    // (reduces informational error logs).
                    io_sc.service_data->setDontCommitErrl();
                }

                o_rc = startBgScrub( io_sc );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "startBgScrub() failed" );
                    break;
                }
            }
            else
            {
                // Restart the scrub on the next address.
                o_rc = resumeScrub( io_sc, eccErrorMask );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "resumeScrub() failed" );
                    break;
                }
            }
        }
        else
        {
            // A TD request was added to the queue, start the next TD request.
            o_rc = startNextTd( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startNextTd() failed" );
                break;
            }
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::analyzeVcmPhase1( STEP_CODE_DATA_STRUCT & io_sc,
                                        const CenAddr & i_stopAddr,
                                        const CenAddr & i_endAddr )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::analyzeVcmPhase1] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( VCM_PHASE_1 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Add the mark to the callout list.
        CalloutUtil::calloutMark( iv_mbaTrgt, iv_rank, iv_mark, io_sc );

        // Check for any ECC errors that occurred during the procedure.
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccErrors() failed" );
            break;
        }

        if ( eccErrorMask & UE )
        {
            o_rc = handleUe_Td( io_sc, i_stopAddr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleUe_Td() failed" );
                break;
            }

            // Abort the procedure.
            iv_tdState = NO_OP;
            break;
        }

        if ( eccErrorMask & RETRY_CTE )
        {
            o_rc = handleRceEte_Td( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleRceEte_Td() failed" );
                break;
            }
        }

        // If the scrub stopped on the last address of the rank, start the next
        // TD procedure. Otherwise, resume background scrubbing. This is needed
        // for attentions like retry CTEs where, due to a hardware issue, must
        // report the attention immediately and cannot wait for the scrub to get
        // to the end of the rank.

        if ( i_endAddr == i_stopAddr )
        {
            // Start VCM Phase 2
            o_rc = startVcmPhase2( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startVcmPhase2() failed" );
                break;
            }
        }
        else
        {
            // Restart the scrub on the next address.
            o_rc = resumeScrub( io_sc, eccErrorMask );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "resumeScrub() failed" );
                break;
            }
        }

    } while(0);

    // If this TD procedure was aborted, execute TD complete sequence.
    if ( (iv_tdState == NO_OP) && (SUCCESS == o_rc) )
    {
        o_rc = handleTdComplete( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "handleTdComplete() failed" );
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::analyzeVcmPhase2( STEP_CODE_DATA_STRUCT & io_sc,
                                        const CenAddr & i_stopAddr,
                                        const CenAddr & i_endAddr )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::analyzeVcmPhase2] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( VCM_PHASE_2 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Add the mark to the callout list.
        CalloutUtil::calloutMark( iv_mbaTrgt, iv_rank, iv_mark, io_sc );

        // Check for any ECC errors that occurred during the procedure.
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccErrors() failed" );
            break;
        }

        if ( eccErrorMask & UE )
        {
            o_rc = handleUe_Td( io_sc, i_stopAddr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleUe_Td() failed" );
                break;
            }

            // Abort the procedure.
            iv_tdState = NO_OP;
            break;
        }

        if ( eccErrorMask & RETRY_CTE )
        {
            o_rc = handleRceEte_Td( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleRceEte_Td() failed" );
                break;
            }
        }

        if ( eccErrorMask & MCE )
        {
            // Chip mark is verified.
            // Do callouts, VPD updates, and start DRAM sparing, if possible.
            o_rc = handleMCE_VCM2( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMCE_VCM2() failed" );
                break;
            }
        }
        else if ( i_endAddr == i_stopAddr )
        {
            // Chip mark verification failed.
            setTdSignature( io_sc, PRDFSIG_VcmFalseAlarm );

            // In manufacturing, this error log will be predictive.
            if ( areDramRepairsDisabled() )
            {
                io_sc.service_data->setServiceCall();
                iv_tdState = NO_OP; // Move on to the next TD procedure.
                break;
            }

            // Increment the false alarm count and threshold. if needed.
            if ( iv_vcmRankData.incFalseAlarm(iv_rank, io_sc) )
            {
                io_sc.service_data->AddSignatureList( iv_mbaTrgt,
                                            PRDFSIG_VcmFalseAlarmExceeded );

                // Treat the chip mark as verified.
                o_rc = handleMCE_VCM2( io_sc );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "handleMCE_VCM2() failed" );
                }
            }
            else
            {
                // Remove chip mark from hardware.
                iv_mark.clearCM();

                // There is small time window where hardware places a chip mark
                // immediately after it is removed, but before the HWP procedure
                // can query the FIR registers. In this case, we will simply
                // allow the write to be 'blocked' and handle the new chip mark
                // in a separate attention.
                bool allowWriteBlocked = true;
                bool blocked; // Currently ignored.
                o_rc = mssSetMarkStore( iv_mbaTrgt, iv_rank, iv_mark, blocked,
                                        allowWriteBlocked );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "mssSetMarkStore() failed" );
                    break;
                }

                iv_tdState = NO_OP; // Move on to the next TD procedure.
            }
        }
        else
        {
            // Restart the scrub on the next address.
            o_rc = resumeScrub( io_sc, eccErrorMask );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "resumeScrub() failed" );
                break;
            }
        }

    } while(0);

    // If this TD procedure was aborted, execute TD complete sequence.
    if ( (iv_tdState == NO_OP) && (SUCCESS == o_rc) )
    {
        o_rc = handleTdComplete( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "handleTdComplete() failed" );
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::analyzeDsdPhase1( STEP_CODE_DATA_STRUCT & io_sc,
                                        const CenAddr & i_stopAddr,
                                        const CenAddr & i_endAddr )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::analyzeDsdPhase1] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( DSD_PHASE_1 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Add the mark to the callout list.
        CalloutUtil::calloutMark( iv_mbaTrgt, iv_rank, iv_mark, io_sc );

        // Check for any ECC errors that occurred during the procedure.
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccErrors() failed" );
            break;
        }

        if ( eccErrorMask & UE )
        {
            o_rc = handleUe_Td( io_sc, i_stopAddr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleUe_Td() failed" );
                break;
            }

            // Abort the procedure.
            iv_tdState = NO_OP;
            break;
        }

        if ( eccErrorMask & RETRY_CTE )
        {
            o_rc = handleRceEte_Td( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleRceEte_Td() failed" );
                break;
            }
        }

        if ( i_endAddr == i_stopAddr )
        {
            // At this point, the procedure has not been aborted due to an error
            // like a memory UE so consider the spare successful.
            setTdSignature( io_sc, PRDFSIG_DsdDramSpared );

            // Remove chip mark from hardware.
            iv_mark.clearCM();

            // There is small time window where hardware places a chip mark
            // immediately after it is removed, but before the HWP procedure can
            // query the FIR registers. In this case, we will simply allow the
            // write to be 'blocked' and handle the new chip mark in a separate
            // attention.
            bool allowWriteBlocked = true;
            bool blocked; // Currently ignored.
            o_rc = mssSetMarkStore( iv_mbaTrgt, iv_rank, iv_mark, blocked,
                                    allowWriteBlocked );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "mssSetMarkStore() failed" );
                break;
            }

            // Always reset the state machine after DSD Phase 1 is complete.
            iv_tdState = NO_OP;
        }
        else
        {
            // Restart the scrub on the next address.
            o_rc = resumeScrub( io_sc, eccErrorMask );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "resumeScrub() failed" );
                break;
            }
        }

    } while(0);

    // If this TD procedure was completed or aborted, execute TD complete
    // sequence.
    if ( (iv_tdState == NO_OP) && (SUCCESS == o_rc) )
    {
        o_rc = handleTdComplete( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "handleTdComplete() failed" );
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::analyzeTpsPhase1( STEP_CODE_DATA_STRUCT & io_sc,
                                        const CenAddr & i_stopAddr,
                                        const CenAddr & i_endAddr )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::analyzeTpsPhase1] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( TPS_PHASE_1 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Get the current marks in hardware (initialize iv_mark).
        o_rc = mssGetMarkStore( iv_mbaTrgt, iv_rank, iv_mark );
        if ( SUCCESS != o_rc )
        {
           PRDF_ERR( PRDF_FUNC "mssGetMarkStore() failed." );
           break;
        }

        const bool reachedEndAddr = ( i_stopAddr == i_endAddr );

        // Check for any ECC errors that occurred during the procedure.
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccErrors() failed" );
            break;
        }

        // The order of the following checks is important. Each call to handle
        // an error will set the PRD signature and override the previous
        // signature. We want the highest priority error signature (memory UEs)
        // to be displayed so these checks should be ordered from lowest to
        // highest priority.

        if ( eccErrorMask & MPE )
        {
            // Only error that will not potentially produce a predictive error,
            // so lowest priority.

            o_rc = handleMpe_Tps( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMpe_Tps() failed" );
                break;
            }

            // Abort this procedure and the do the VCM procedure.
            iv_tdState = NO_OP;
            break;
        }

        // The hardware thresholds are intentionally set to the max value for
        // stop on error conditions in the middle of the scrub. Therefore, we
        // must check the per symbol counters for threshold regardless of any
        // CTE attentions if the scrub has reached the end of the rank.
        // Otherwise, check the per symbol counters only of a CTE attention is
        // raised somewhere in the middle of the scrub.
        bool ceTypeTh = iv_tpsRankData.checkCeTypeTh(iv_rank);
        if ( ( reachedEndAddr                              ) ||
             ( !ceTypeTh &&  (eccErrorMask & HARD_CTE )    ) ||
             (  ceTypeTh && ((eccErrorMask & SOFT_CTE ) ||
                             (eccErrorMask & INTER_CTE) ||
                             (eccErrorMask & HARD_CTE ))   ) )
        {
            o_rc = handleCeEte_Tps( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleCeEte_Tps() failed" );
                break;
            }
        }

        if ( eccErrorMask & RETRY_CTE )
        {
            o_rc = handleRceEte_Td( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleRceEte_Td() failed" );
                break;
            }
        }

        if ( eccErrorMask & UE )
        {
            o_rc = handleUe_Td( io_sc, i_stopAddr, false ); // No TPS request.
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleUe_Td() failed" );
                break;
            }
        }

        // If the command had reached the end of the rank, handle any false
        // alarm conditions, if needed, and continue on to the next TD
        // procedure. Otherwise, resume the scrub starting on the next address.
        if ( reachedEndAddr )
        {
            // Handle false alarm conditions, if needed.
            if ( iv_tpsFalseAlarm )
            {
                o_rc = handleTpsFalseAlarm( io_sc );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "handleTpsFalseAlarm() failed" );
                    break;
                }
            }

            // This procedure is done. Reset the state machine and go onto the
            // next TD procedure.
            iv_tdState = NO_OP;
            break;
        }

        // Restart the scrub on the next address.
        o_rc = resumeScrub( io_sc, eccErrorMask );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "resumeScrub() failed" );
            break;
        }

    } while(0);

    // Callout the rank if no other callouts have been made.
    if ( 0 == io_sc.service_data->getMruListSize() )
    {
        MemoryMru memmru( iv_mbaTrgt, iv_rank,
                          MemoryMruData::CALLOUT_RANK );
        io_sc.service_data->SetCallout( memmru );
    }

    // If this TD procedure was aborted, execute TD complete sequence.
    if ( (iv_tdState == NO_OP) && (SUCCESS == o_rc) )
    {
        o_rc = handleTdComplete( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "handleTdComplete() failed" );
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startVcmPhase1( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startVcmPhase1] "

    int32_t o_rc = SUCCESS;

    io_sc.service_data->AddSignatureList( iv_mbaTrgt, PRDFSIG_StartVcmPhase1 );
    iv_tdState = VCM_PHASE_1;

    do
    {
        // Starting a new phase of VCM procedure. Reset the scrub resume counter
        iv_scrubResumeCounter.reset();

        // Get the current marks in hardware (initialize iv_mark).
        o_rc = mssGetMarkStore( iv_mbaTrgt, iv_rank, iv_mark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssGetMarkStore() failed");
            break;
        }

        o_rc = prepareNextCmd( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd() failed" );
            break;
        }

        // Start phase 1.
        o_rc = doTdScrubCmd( COND_RT_VCM_DSD );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "doTdScrubCmd() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startVcmPhase2( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startVcmPhase2] "

    int32_t o_rc = SUCCESS;

    io_sc.service_data->AddSignatureList( iv_mbaTrgt, PRDFSIG_StartVcmPhase2 );
    iv_tdState = VCM_PHASE_2;

    do
    {
        // Starting a new phase of VCM procedure. Reset the scrub resume counter
        iv_scrubResumeCounter.reset();

        o_rc = prepareNextCmd( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd() failed" );
            break;
        }

        // Start phase 2.
        o_rc = doTdScrubCmd( COND_RT_VCM_DSD | mss_MaintCmd::STOP_ON_MCE );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "doTdScrubCmd() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startDsdPhase1( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startDsdPhase1] "

    int32_t o_rc = SUCCESS;

    io_sc.service_data->AddSignatureList( iv_mbaTrgt, PRDFSIG_StartDsdPhase1 );
    iv_tdState = DSD_PHASE_1;

    do
    {
        // Starting a new DSD procedure. Reset the scrub resume counter.
        iv_scrubResumeCounter.reset();

        o_rc = prepareNextCmd( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd() failed" );
            break;
        }

        // Set the steer mux
        o_rc = mssSetSteerMux( iv_mbaTrgt, iv_rank, iv_mark.getCM(),
                               iv_isEccSteer );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssSetSteerMux() failed" );
            break;
        }

        // Start phase 1.
        o_rc = doTdScrubCmd( COND_RT_VCM_DSD );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "doTdScrubCmd() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startTpsPhase1( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startTpsPhase1] "

    int32_t o_rc = SUCCESS;

    io_sc.service_data->AddSignatureList( iv_mbaTrgt, PRDFSIG_StartTpsPhase1 );
    iv_tdState = TPS_PHASE_1;

    do
    {
        // Initially true, until hardware error is found.
        iv_tpsFalseAlarm = true;

        // Starting a new TPS procedure. Reset the scrub resume counter.
        iv_scrubResumeCounter.reset();

        o_rc = prepareNextCmd( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd() failed" );
            break;
        }

        // Set CE thresholds.
        o_rc = setTpsThresholds();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setTpsThresholds() failed" );
            break;
        }

        // Set stop conditions based on CE count type.
        uint32_t stopCond = COND_RT_TPS_HARD_CE;
        if ( iv_tpsRankData.checkCeTypeTh(iv_rank) )
        {
            stopCond = COND_RT_TPS_ALL_CE;
        }

        // Start TPS phase 1.
        o_rc = doTdScrubCmd( stopCond, mss_MaintCmdWrapper::SLAVE_RANK_ONLY );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "doTdScrubCmd() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startBgScrub( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startBgScrub] "

    int32_t o_rc = SUCCESS;

    iv_tdState = NO_OP;

    do
    {
        // Starting a scrub on a new rank. Reset the scrub resume counter.
        iv_scrubResumeCounter.reset();

        // Cleanup hardware before starting the maintenance command. This will
        // clear the ECC counters, which must be done before setting the ETE
        // thresholds.
        o_rc = prepareNextCmd( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd() failed" );
            break;
        }

        // Set the default thresholds for all ETE attentions.
        o_rc = setRtEteThresholds();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setRtEteThresholds() failed" );
            break;
        }

        // Unmask the fetch attentions that were explicitly masked during the
        // TD procedure.
        o_rc = unmaskFetchAttns();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "unmaskFetchAttns() failed" );
            break;
        }

        // Background scrubbing will need to start from the first address of the
        // next good rank. The current design is to not stop on the end address
        // and let background scrubbing run continuously. Technically, this
        // means we do not need to specify the end address for the maintenance
        // command, however, I think we should still input the last address of
        // the last rank behind the MBA as the end address just in case we need
        // to flip the switch and stop on the end address (for hardware
        // workarounds and such). Also, assume since we are resuming background
        // scrubbing all entries in iv_masterRanks are good, for now.

        TdRankList::Entry entry = iv_masterRanks.findNextGoodRank();
        if ( iv_rank == entry.rank )
        {
            // It is possible that the next good rank is the rank that was just
            // targeted for diagnostics. If so, we want to try to start
            // scrubbing on the rank after this just in case the this rank has
            // a lot of errors. This is not a perfect system because it is
            // possible that were two TD procedures recently done in a four rank
            // system and it just so happens that the next good rank is one of
            // the recently targeted ranks. However, scrub will eventually get
            // to all of the rank so this is a limitation we can to live with
            // because it isn't worth the extra code.

            entry = iv_masterRanks.findNextGoodRank();
        }

        // It is important to initialize iv_rank here so that possible back to
        // back maintenance command complete attentions do not accidentally
        // cause a rank to get skipped due to the next good rank check above.
        iv_rank = entry.rank;

        // Start background scrub.
        o_rc = doBgScrubCmd( COND_BG_SCRUB );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "doBgScrubCmd() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startNextTd( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startNextTd] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( iv_queue.empty() )
        {
            // No pending requests, so start backgound scrubbing.
            o_rc = startBgScrub( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startBgScrub() failed" );
                break;
            }
        }
        else
        {
            // Start the next TD procedure.
            TdQueueEntry entry = iv_queue.getNextEntry();
            iv_rank = CenRank( entry.rank );

            switch ( entry.type )
            {
                case VCM_EVENT: o_rc = startVcmPhase1( io_sc ); break;
                case TPS_EVENT: o_rc = startTpsPhase1( io_sc ); break;
                default: o_rc = FAIL;
            }
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "failed to start procedure for event %d",
                          entry.type );
                break;
            }
            // Mask fetch attentions during TD procedures. startNextTd is called
            // from many places. Mask attention here rather in caller function.
            // Though now maskFetchAttns will be called multiple times for back
            // to back TD requests but its minor issue as TD procedure takes
            // atleast 5 hours. Also it will save us from potential bugs
            // if we miss at any place.
            o_rc = maskFetchAttns();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "maskFetchAttns() failed" );
                break;
            }

        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::resumeScrub( STEP_CODE_DATA_STRUCT & io_sc,
                                   uint32_t i_eccErrorMask )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::resumeScrub] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( (NO_OP       != iv_tdState) &&
             (VCM_PHASE_1 != iv_tdState) && (VCM_PHASE_2 != iv_tdState) &&
             (DSD_PHASE_1 != iv_tdState) && (TPS_PHASE_1 != iv_tdState) )
        {
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Manually clear the CE counters based on the error type.
        o_rc = clearCeCounters( i_eccErrorMask );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "clearCeCounters() failed" );
            break;
        }

        // Do not clear the CE counters. The target counters have been manually
        // cleared based on error type.
        o_rc = prepareNextCmd( io_sc, false );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd() failed" );
            break;
        }

        // Increment the start address.
        iv_mssCmd = createIncAddrMssCmd( iv_mbaTrgt );
        if ( NULL == iv_mssCmd )
        {
            PRDF_ERR( PRDF_FUNC "createIncAddrMssCmd returned NULL" );
            o_rc = FAIL; break;
        }

        o_rc = iv_mssCmd->setupAndExecuteCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setupAndExecuteCmd() failed" );
            break;
        }

        // Get the new start address.
        CenAddr addr;
        o_rc = getCenMaintStartAddr( iv_mbaChip, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getCenMaintStartAddr() failed" );
            break;
        }

        // Again, do not clear the CE counters.
        o_rc = prepareNextCmd( io_sc, false );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "prepareNextCmd() failed" );
            break;
        }

        // Set the control flags and stop conditions based on the procedure
        // type. The defaults will be for background scrubbing where we want to
        // stop at the end of the rank.
        uint32_t flags    = mss_MaintCmdWrapper::NO_FLAGS;
        uint32_t stopCond = COND_BG_SCRUB | mss_MaintCmd::STOP_ON_END_ADDRESS;
        if ( TPS_PHASE_1 == iv_tdState )
        {
            flags = mss_MaintCmdWrapper::SLAVE_RANK_ONLY;

            // Set stop conditions based on CE count type.
            stopCond = COND_RT_TPS_HARD_CE;
            if ( iv_tpsRankData.checkCeTypeTh(iv_rank) )
            {
                stopCond = COND_RT_TPS_ALL_CE;
            }
        }
        else if ( (VCM_PHASE_1 == iv_tdState) || (DSD_PHASE_1 == iv_tdState) )
        {
            stopCond = COND_RT_VCM_DSD;
        }
        else if ( VCM_PHASE_2 == iv_tdState )
        {
            stopCond = COND_RT_VCM_DSD | mss_MaintCmd::STOP_ON_MCE;
        }

        // If the command had been resumed 16 times on this rank, clear the stop
        // on error flags (everything except MPE) and continue on to the end of
        // the rank. This is needed so that the scrub can complete without
        // getting flooded with attentions.
        if ( iv_scrubResumeCounter.isTh() )
        {
            stopCond &= ~mss_MaintCmd::STOP_ON_HARD_NCE_ETE;
            stopCond &= ~mss_MaintCmd::STOP_ON_INT_NCE_ETE;
            stopCond &= ~mss_MaintCmd::STOP_ON_SOFT_NCE_ETE;
            stopCond &= ~mss_MaintCmd::STOP_ON_RETRY_CE_ETE;
            stopCond &= ~mss_MaintCmd::STOP_ON_UE;
        }

        if ( NO_OP == iv_tdState )
        {
            // Resume background scrub.
            o_rc = doBgScrubCmd( stopCond, flags, &addr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "doBgScrubCmd() failed" );
                break;
            }
        }
        else
        {
            // Resume the TD procedure.
            o_rc = doTdScrubCmd( stopCond, flags, &addr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "doTdScrubCmd() failed" );
                break;
            }
        }

        // The resume was successful. Increment the resume counter.
        iv_scrubResumeCounter.incCount();

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleTdComplete( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleTdComplete] "

    int32_t o_rc = SUCCESS;

    do
    {
        // A TD procedure has completed. Deactivate all entries in the CE table
        // for the rank that was just targeted. This must be done before finding
        // the next good rank so that iv_rank will contain the rank that was
        // just targeted. Also remove the entry from RCE table.
        CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );
        mbadb->iv_ceTable.deactivateRank( iv_rank );
        mbadb->iv_rceTable.flushEntry( iv_rank );

        // Clear out the mark, just in case. This is so we don't accidentally
        // callout this mark on another rank in an error path scenario.
        iv_mark = CenMark();

        // Remove TD request from the queue.
        o_rc = removeTdQueueEntry();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "removeTdQueueEntry() failed" );
            break;
        }

        // Move on to the next TD procedure or restart background scrubbing.
        o_rc = startNextTd( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startNextTd() failed" );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::addTdQueueEntryVCM( const CenRank & i_rank )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::addTdQueueEntryVCM] "

    int32_t o_rc = SUCCESS;

    do
    {
        // Verify a chip mark exists in hardware for this rank.
        CenMark mark;
        o_rc = mssGetMarkStore( iv_mbaTrgt, i_rank, mark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssGetMarkStore() failed");
            break;
        }
        if ( !mark.getCM().isValid() )
        {
            PRDF_ERR( PRDF_FUNC "VCM event but no valid chip mark" );
            o_rc = FAIL; break;
        }

        // Push the TD request to the queue.
        iv_queue.push( TdQueueEntry(VCM_EVENT, i_rank) );

        // Mark this rank as bad.
        o_rc = iv_masterRanks.setBad( i_rank );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setBad() failed" );
            break;
        }

    } while(0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed: i_rank=m%ds%d",
                  i_rank.getMaster(), i_rank.getSlave() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::addTdQueueEntryTPS( const CenRank & i_rank,
                                          STEP_CODE_DATA_STRUCT & io_sc,
                                          bool i_banTps )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::addTdQueueEntryTPS] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( iv_tpsRankData.isBanned(i_rank, io_sc) )
        {
            // TPS is banned, do not add the request to the queue.
            break;
        }

        // Check for any available repairs. There is no point doing TPS if we
        // cannot apply a repair.
        CenMark mark;
        o_rc = mssGetMarkStore( iv_mbaTrgt, i_rank, mark );
        if ( SUCCESS != o_rc )
        {
           PRDF_ERR( PRDF_FUNC "mssGetMarkStore() failed." );
           break;
        }
        if ( mark.getCM().isValid() &&
             (iv_x4Dimm || (!iv_x4Dimm && mark.getSM().isValid())) )
        {
            bool port0Available, port1Available;
            o_rc  = checkForAvailableSpares( 0, port0Available );
            o_rc |= checkForAvailableSpares( 1, port1Available );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "checkForAvailableSpares() failed." );
                break;
            }

            if ( !port0Available && !port1Available )
            {
                // Ban TPS to avoid rechecking with subsequent TPS requests.
                iv_tpsRankData.ban( iv_rank );

                // TPS is banned, do not add the request to the queue.
                break;
            }
        }

        if ( i_banTps )
        {
            // Ban all future TPS requests for this rank (not including
            // this one).
            iv_tpsRankData.ban( i_rank );
        }

        // Push the TD request to the queue.
        iv_queue.push( TdQueueEntry(TPS_EVENT, i_rank) );

        // Mark this rank as bad.
        o_rc = iv_masterRanks.setBad( i_rank );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setBad() failed" );
            break;
        }

    } while(0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed: i_rank=m%ds%d i_banTps=%c",
                  i_rank.getMaster(), i_rank.getSlave(),
                  i_banTps ? 'T' : 'F' );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::removeTdQueueEntry()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::removeTdQueueEntry] "

    int32_t o_rc = SUCCESS;

    iv_queue.pop();

    // If there are no more references to iv_rank in the TD queue, set the rank
    // as 'good'.
    if ( !iv_queue.exists(iv_rank) )
    {
        o_rc = iv_masterRanks.setGood( iv_rank );
        if ( SUCCESS != o_rc )
            PRDF_ERR( PRDF_FUNC "setGood() failed" );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::cleanupPrevCmd( STEP_CODE_DATA_STRUCT & io_sc )
{
    #ifndef __HOSTBOOT_RUNTIME
    ForceSyncAnalysis(*io_sc.service_data);
    #endif
    return CenMbaTdCtlrCommon::cleanupPrevCmd();
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::prepareNextCmd( STEP_CODE_DATA_STRUCT & io_sc,
                                      bool i_clearStats  )
{
    #ifndef __HOSTBOOT_RUNTIME
    ForceSyncAnalysis(*io_sc.service_data);
    #endif
    return CenMbaTdCtlrCommon::prepareNextCmd( i_clearStats );
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleUe_Td( STEP_CODE_DATA_STRUCT & io_sc,
                                   const CenAddr & i_stopAddr,
                                   bool i_addTpsRequest )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleUe_Td] "

    int32_t o_rc = SUCCESS;

    setTdSignature( io_sc, PRDFSIG_MaintUE );

    // Clear TPS false alarm flag.
    iv_tpsFalseAlarm = false;

    // Callout the rank
    MemoryMru memmru ( iv_mbaTrgt, iv_rank, MemoryMruData::CALLOUT_RANK );
    io_sc.service_data->SetCallout( memmru );

    // Make error log predictive
    io_sc.service_data->setServiceCall();

    do
    {
        // Add entry to UE table. Note that it is possible that there was a
        // resume threshold during TPS, which means that the stop-on-UE
        // condition was cleared and the scrub was forced to go to the end of
        // the rank. In this case, we cannot be certain which address the UE had
        // occurred on, so do not add the address to the UE table.
        if ( (TPS_PHASE_1 != iv_tdState) || !iv_scrubResumeCounter.isTh() )
        {
            CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );
            mbadb->iv_ueTable.addEntry( UE_TABLE::SCRUB_UE, i_stopAddr );

            // Send lmb gard message to PHYP.
            o_rc =  DEALLOC::lmbGard( iv_mbaChip, i_stopAddr, false );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "lmbGard() failed" );
                break;
            }
        }

        if ( i_addTpsRequest )
        {
            // Add a TPS request to the queue and ban any future TPS requests.
            o_rc = addTdQueueEntryTPS( i_stopAddr.getRank(), io_sc, true );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "addTdQueueEntryTPS() failed" );
                break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleRceEte_Td( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleRceEte_Td] "

    int32_t o_rc = SUCCESS;

    setTdSignature( io_sc, PRDFSIG_MaintRETRY_CTE );

    // Clear TPS false alarm flag.
    iv_tpsFalseAlarm = false;

    // Callout the rank
    MemoryMru memmru ( iv_mbaTrgt, iv_rank, MemoryMruData::CALLOUT_RANK );
    io_sc.service_data->SetCallout( memmru );

    // Make error log predictive
    io_sc.service_data->setServiceCall();

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleMpe_Tps( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleMpe_Tps] "

    int32_t o_rc = SUCCESS;

    setTdSignature( io_sc, PRDFSIG_MaintMPE );

    // Clear TPS false alarm flag.
    iv_tpsFalseAlarm = false;

    do
    {
        // Callout the mark.
        CalloutUtil::calloutMark( iv_mbaTrgt, iv_rank, iv_mark, io_sc );

        // Add a VCM request to the queue.
        o_rc = addTdQueueEntryVCM( iv_rank );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "addTdQueueEntryVCM() failed" );
            break;
        }

        // Clear the scrub attention. This is needed later if we need to write
        // markstore for a symbol mark.
        const char * fir_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR_AND"
                                                : "MBA1_MBSECCFIR_AND";

        SCAN_COMM_REGISTER_CLASS * fir = iv_membChip->getRegister( fir_str );

        fir->ClearBit( 20 + iv_rank.getMaster() ); // scrub

        o_rc = fir->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on %s", fir_str );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleCeEte_Tps( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleCeEte_Tps] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( TPS_PHASE_1 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Get the current threshold.
        uint16_t thr = 0;
        o_rc = getTpsCeThr( thr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getTpsCeThr() failed." );
            break;
        }

        // Get all symbols that have a count greater than or equal to the target
        // threshold.
        MaintSymbols symData; CenSymbol targetCM;
        o_rc = collectCeStats( iv_mbaChip, iv_rank, symData, targetCM, thr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "collectCeStats() failed." );
            break;
        }

        // Check for false alarms.
        if ( symData.empty() ) break; // nothing else to do

        // There is valid data so clear the false alarm flag.
        iv_tpsFalseAlarm = false;

        // Callout all DIMMS with symbol count that reached threshold.
        CalloutUtil::calloutSymbolData( iv_mbaTrgt, iv_rank, symData, io_sc );

        // Check if DRAM repairs are disabled.
        if ( areDramRepairsDisabled() )
        {
            io_sc.service_data->setServiceCall();
            break; // nothing else to do
        }

        // Add all symbols to the VPD.
        CenDqBitmap bitmap;
        o_rc = getBadDqBitmap( iv_mbaTrgt, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed" );
            break;
        }

        for ( MaintSymbols::iterator it = symData.begin();
              it != symData.end(); it++ )
        {
            bitmap.setSymbol( it->symbol );
        }

        o_rc = setBadDqBitmap( iv_mbaTrgt, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setBadDqBitmap() failed" );
            break;
        }

        // Check if the chip mark is available.
        bool cmPlaced = false;
        if ( !iv_mark.getCM().isValid() )
        {
            if ( targetCM.isValid() )
            {
                // Use the DRAM with the highest total count.
                iv_mark.setCM( targetCM );
                o_rc = tpsChipMark( io_sc );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "tpsChipMark() failed." );
                    break;
                }

                cmPlaced = true;
            }
            // If the symbol mark has been used then use the chip mark.
            else if ( !iv_x4Dimm && iv_mark.getSM().isValid() )
            {
                for ( MaintSymbols::iterator it = symData.end();
                      it-- != symData.begin(); )
                {
                    if ( !(it->symbol == iv_mark.getSM()) )
                    {
                        iv_mark.setCM( it->symbol );
                        o_rc = tpsChipMark( io_sc );
                        if ( SUCCESS != o_rc )
                        {
                            PRDF_ERR( PRDF_FUNC "tpsChipMark() failed." );
                            break;
                        }

                        cmPlaced = true;
                        break;
                    }
                }
                if ( SUCCESS != o_rc ) break;
            }
        }

        // Check if the symbol mark is available. Note that symbol marks are not
        // available in x4 mode. Also, we only want to place a symbol mark if we
        // did not just place a chip mark above. The reason for this is because
        // having a chip mark and symbol mark at the same time increases the
        // chance of UEs. We will want to wait until the chip mark we placed
        // above is verified< and possibily steered, before placing the symbol
        // mark.
        if ( !cmPlaced && !iv_x4Dimm && !iv_mark.getSM().isValid() )
        {
            // Use the symbol with the highest count.
            iv_mark.setSM( symData.back().symbol );
            o_rc = tpsSymbolMark( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "tpsSymbolMark() failed." );
                break;
            }
        }

        // We know with a degree of confidence that any chip mark placed in this
        // function will be verified. Therefore, we can do a early check here
        // and make a predictive callout if the chip mark and all available
        // spares have been used. This is useful because the targeted
        // diagnostics procedure will take much longer to complete due to a
        // hardware issue. By making the predictive callout now, we will send a
        // Dynamic Memory Deallocation message to PHYP sooner so that they can
        // attempt to get off the memory instead of waiting for the callout
        // after the VCM procedure.

        if ( iv_mark.getCM().isValid() )
        {
            bool available;
            o_rc = checkForAvailableSpares( iv_mark.getCM().getPortSlct(),
                                            available );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "checkForAvailableSpares() failed" );
                break;
            }

            if ( !available )
            {
                // Spares have been used. Callout the mark. Make the error log
                // predictive.
                CalloutUtil::calloutMark( iv_mbaTrgt, iv_rank, iv_mark, io_sc );
                setTdSignature( io_sc, PRDFSIG_TpsCmAndSpare );
                io_sc.service_data->setServiceCall();
            }
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleUe_NonTd( STEP_CODE_DATA_STRUCT & io_sc,
                                      const CenAddr & i_addr )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleUe_NonTd] "

    int32_t o_rc = SUCCESS;

    setTdSignature( io_sc, PRDFSIG_MaintUE );

    do
    {
        // Add entry to UE table.
        CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );
        mbadb->iv_ueTable.addEntry( UE_TABLE::SCRUB_UE, i_addr );

        // Callout the rank.
        MemoryMru memmru ( iv_mbaTrgt, iv_rank, MemoryMruData::CALLOUT_RANK );
        io_sc.service_data->SetCallout( memmru );
        io_sc.service_data->setServiceCall();

        // Add a TPS request to the queue and ban any future TPS requests.
        o_rc = addTdQueueEntryTPS( iv_rank, io_sc, true );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "addTdQueueEntryTPS() failed" );
            break;
        }

        // Send lmb gard message to PHYP.
        o_rc =  DEALLOC::lmbGard( iv_mbaChip, i_addr, false );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "lmbGard() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleMpe_NonTd( STEP_CODE_DATA_STRUCT & io_sc,
                                       const CenAddr & i_addr )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleMpe_NonTd] "

    int32_t o_rc = SUCCESS;

    setTdSignature( io_sc, PRDFSIG_MaintMPE );

    do
    {
        // Add entry to UE table.
        CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );
        mbadb->iv_ueTable.addEntry( UE_TABLE::SCRUB_MPE, i_addr );

        // Add a VCM request to the queue.
        o_rc = addTdQueueEntryVCM( iv_rank );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "addTdQueueEntryVCM() failed" );
            break;
        }

        // Get the current mark in hardware.
        CenMark mark;
        o_rc = mssGetMarkStore( iv_mbaTrgt, iv_rank, mark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssGetMarkStore() failed");
            break;
        }

        // Callout the mark.
        CalloutUtil::calloutMark( iv_mbaTrgt, iv_rank, mark, io_sc );

    } while( 0 );

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleRceEte_NonTd( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleRceEte_NonTd] "

    int32_t o_rc = SUCCESS;

    setTdSignature( io_sc, PRDFSIG_MaintRETRY_CTE );

    do
    {
        MemoryMru memmru ( iv_mbaTrgt, iv_rank, MemoryMruData::CALLOUT_RANK );
        io_sc.service_data->SetCallout( memmru );

        bool doTps = true;

        if ( mfgMode() )
        {
            // Get RCE count.
            const char * reg_str = (0 == iv_mbaPos) ? "MBA0_MBSEC1"
                                                    : "MBA1_MBSEC1";
            SCAN_COMM_REGISTER_CLASS * mbsec1
                                        = iv_membChip->getRegister( reg_str );
            o_rc = mbsec1->Read();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Read() failed on %s", reg_str );
                break;
            }

            uint16_t count = mbsec1->GetBitFieldJustified( 0, 12 );

            // Add count to RCE table
            CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );
            doTps = mbadb->iv_rceTable.addEntry( iv_rank, io_sc, count );
        }
        else
            io_sc.service_data->setServiceCall();

        if ( doTps )
        {
            o_rc = addTdQueueEntryTPS( iv_rank, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "addTdQueueEntryTPS() failed" );
                break;
            }
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleHardCeEte_NonTd( STEP_CODE_DATA_STRUCT & io_sc,
                                             const CenAddr & i_addr )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleHardCeEte_NonTd] "

    int32_t o_rc = SUCCESS;

    setTdSignature( io_sc, PRDFSIG_MaintHARD_CTE );

    do
    {
        // Send page deallocation message to PHYP
        o_rc = DEALLOC::pageGard( iv_mbaChip, i_addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "pageGard() failed" );
            break;
        }

        // Get the failing symbol. Note that the hard CE threshold is 1 so there
        // should only be one symbol with a non-zero per symbol count.

        MaintSymbols symData; CenSymbol junk;
        o_rc = collectCeStats( iv_mbaChip, iv_rank, symData, junk );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "collectCeStats() failed." );
            break;
        }

        if ( 1 != symData.size() )
        {
            PRDF_ERR( PRDF_FUNC "collectCeStats() return size %d, but was "
                      "expecting size 1", symData.size() );
            o_rc = FAIL;
            break;
        }

        CenSymbol symbol = symData[0].symbol;

        // Callout the symbol.
        MemoryMru memmru ( iv_mbaTrgt, iv_rank, symbol );
        io_sc.service_data->SetCallout( memmru );

        // Add entry to CE table and add a TPS request to the queue, if needed.
        CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );
        if ( mbadb->iv_ceTable.addEntry(i_addr, symbol, true) )
        {
            o_rc = addTdQueueEntryTPS( iv_rank, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "addTdQueueEntryTPS() failed" );
                break;
            }
        }

        // Any hard CEs in MNFG should be immediately reported.
        if ( mfgMode() )
            io_sc.service_data->setServiceCall();

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleSoftIntCeEte_NonTd( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleSoftIntCeEte_NonTd] "

    int32_t o_rc = SUCCESS;

    setTdSignature( io_sc, PRDFSIG_MaintNCE_CTE );

    do
    {
        // Callout the rank. Note that the per CE counters only capture hard CEs
        // so it is not possible to isolate any further than a rank.
        MemoryMru memmru ( iv_mbaTrgt, iv_rank, MemoryMruData::CALLOUT_RANK );
        io_sc.service_data->SetCallout( memmru );

        // Add a TPS request to the queue.
        o_rc = addTdQueueEntryTPS( iv_rank, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "addTdQueueEntryTPS() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleTpsFalseAlarm( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleTpsFalseAlarm] "

    int32_t o_rc = SUCCESS;

    setTdSignature( io_sc, PRDFSIG_TpsFalseAlarm );

    do
    {
        if ( TPS_PHASE_1 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        bool isMbDimm = false;
        o_rc = isMembufOnDimm( iv_mbaTrgt, isMbDimm );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "isMembufOnDimm() failed." );
            break;
        }

        // Callout all DIMMs that have reached threshold.
        //   Centaur DIMMS: Any non-zero count, threshold on 1.
        //   IS DIMMS:      Allow 1, threshold on 2 (because of limited spares).
        uint8_t thr = isMbDimm ? 1 : 2;
        MaintSymbols symData; CenSymbol junk;
        o_rc = collectCeStats( iv_mbaChip, iv_rank, symData, junk, thr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "collectCeStats() failed." );
            break;
        }

        if ( symData.empty() )
        {
            // There is no data so callout the rank.
            MemoryMru memmru (iv_mbaTrgt, iv_rank, MemoryMruData::CALLOUT_RANK);
            io_sc.service_data->SetCallout( memmru );
        }
        else
        {
            CalloutUtil::calloutSymbolData(iv_mbaTrgt, iv_rank, symData, io_sc);
        }

        // In manufacturing, this error log will be predictive.
        if ( areDramRepairsDisabled() )
        {
            io_sc.service_data->setServiceCall();
            break; // nothing else to do
        }

        // Increase the false alarm counter. Continue only if false alarm
        // threshold is exceeded.
        if ( !iv_tpsRankData.incFalseAlarm(iv_rank, io_sc) ) break;

        setTdSignature( io_sc, PRDFSIG_TpsFalseAlarmExceeded );

        // If there are no symbols in the list, exit quietly.
        if ( symData.empty() ) break;

        // Use the symbol with the highest count to place a symbol or chip mark,
        // if possible. Note that we only want to use one repair for this false
        // alarm to avoid using up all the repairs for 'weak' errors.
        CenSymbol highestSymbol = symData.back().symbol;

        // Check if the symbol mark is available. Note that symbol marks are not
        // available in x4 mode.
        if ( !iv_x4Dimm && !iv_mark.getSM().isValid() )
        {
            iv_mark.setSM( highestSymbol );
            o_rc = tpsSymbolMark( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "tpsSymbolMark() failed." );
                break;
            }

            // Add this symbol to the VPD.
            CenDqBitmap bitmap;
            o_rc = getBadDqBitmap( iv_mbaTrgt, iv_rank, bitmap );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed" );
                break;
            }

            bitmap.setSymbol( highestSymbol );

            o_rc = setBadDqBitmap( iv_mbaTrgt, iv_rank, bitmap );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "setBadDqBitmap() failed" );
                break;
            }
        }
        // Check if the chip mark is available.
        else if ( !iv_mark.getCM().isValid() )
        {
            iv_mark.setCM( highestSymbol );
            o_rc = tpsChipMark( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "tpsChipMark() failed" );
                break;
            }
        }
        else
        {
            // The spares have been used. Make the error log predictive.
            setTdSignature( io_sc, PRDFSIG_TpsMarksUnavail );
            io_sc.service_data->setServiceCall();
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::getTpsCeThr( uint16_t & o_thr )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::getTpsCeThr] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( TPS_PHASE_1 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL;
            break;
        }

        if ( !iv_tpsRankData.checkCeTypeTh(iv_rank) )
        {
            o_thr = mfgMode() ? 1 : 48;
        }
        else
        {
            o_rc = getScrubCeThreshold( iv_mbaChip, iv_rank, o_thr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getScrubCeThreshold() failed." );
                break;
            }
        }

    } while( 0 );

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::setTpsThresholds()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::setTpsThresholds] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( TPS_PHASE_1 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL;
            break;
        }

        const char * reg_str = (0 == iv_mbaPos) ? "MBA0_MBSTR" : "MBA1_MBSTR";
        SCAN_COMM_REGISTER_CLASS * mbstr = iv_membChip->getRegister( reg_str );

        // MBSTR's content could be modified by cleanupCmd() so refresh cache.
        o_rc = mbstr->ForceRead();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "ForceRead() failed on %s", reg_str );
            break;
        }

        // Set all CE thresholds to the maximum value. The reason for this is if
        // there are a lot of CEs we can stop the TPS scrub and place any marks,
        // if needed. This will save time since the TPS scrub could take several
        // hours. The threshold is set to the max value so that we can get
        // enough data to place a mark.
        mbstr->SetBitFieldJustified(  4, 12, 0xfff );
        mbstr->SetBitFieldJustified( 16, 12, 0xfff );
        mbstr->SetBitFieldJustified( 28, 12, 0xfff );

        if ( !iv_tpsRankData.checkCeTypeTh(iv_rank) )
        {
            // Set the per symbol counters to count only hard CEs.
            mbstr->SetBitFieldJustified( 55, 3, 0x1 );
        }
        else
        {
            // Set the per symbol counters to count all CE typs.
            mbstr->SetBitFieldJustified( 55, 3, 0x7 );
        }

        o_rc = mbstr->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on %s", reg_str );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::tpsChipMark( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::tpsChipMark] "

    int32_t o_rc = SUCCESS;

    setTdSignature( io_sc, PRDFSIG_TpsChipMark );

    do
    {
        if ( TPS_PHASE_1 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Write the chip mark to markstore.
        bool allowWriteBlocked = true;
        bool blocked;
        o_rc = mssSetMarkStore( iv_mbaTrgt, iv_rank, iv_mark, blocked,
                                allowWriteBlocked );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssSetMarkStore() failed" );
            break;
        }

        if ( blocked )
        {
            // Continue on with the rest of the TPS procedure as if nothing
            // failed. We will find the new chip mark on a subsequent attention.
            // The chances are that hardware had placed a chip mark on the same
            // DRAM that we tried to write, so for now, ignore these failing
            // symbols.
        }
        else
        {
            // Add a VCM request to the queue.
            o_rc = addTdQueueEntryVCM( iv_rank );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "addTdQueueEntryVCM() failed" );
                break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::tpsSymbolMark( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::tpsSymbolMark] "

    int32_t o_rc = SUCCESS;

    setTdSignature( io_sc, PRDFSIG_TpsSymbolMark );

    do
    {
        if ( TPS_PHASE_1 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Write the symbol mark to markstore.
        bool allowWriteBlocked = true;
        bool blocked = false;
        o_rc = mssSetMarkStore( iv_mbaTrgt, iv_rank, iv_mark, blocked,
                                allowWriteBlocked );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssSetMarkStore() failed." );
            o_rc = FAIL; break;
        }

        if ( !blocked ) break; // Write was successful, no need to continue.

        // Hardware placed a new chip mark. Add a VCM request to the queue.
        o_rc = addTdQueueEntryVCM( iv_rank );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "addTdQueueEntryVCM() failed" );
            break;
        }

        // Clear the fetch attention before attempting the rewrite.
        const char * reg_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR_AND"
                                                : "MBA1_MBSECCFIR_AND";
        SCAN_COMM_REGISTER_CLASS * firand = iv_membChip->getRegister( reg_str );
        firand->setAllBits();
        firand->ClearBit( 0 + iv_rank.getMaster() ); // fetch
        o_rc = firand->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on %s", reg_str );
            break;
        }

        // Rewrite markstore. Do not allow this write to be blocked. If it is
        // blocked there is a code bug. Note that iv_mark was updated with the
        // hardware placed chip mark in the previous call to mssSetMarkStore().
        o_rc = mssSetMarkStore( iv_mbaTrgt, iv_rank, iv_mark, blocked );
        if ( SUCCESS != o_rc )
        {
           PRDF_ERR( PRDF_FUNC "mssSetMarkStore() failed on retry." );
           break;
        }

    } while( 0 );

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::maskFetchAttns()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::maskFetchAttns] "

    int32_t o_rc = SUCCESS;

    do
    {
        // Don't want to handle memory CEs during any TD procedures, so
        // mask them.

        const char * reg_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR_MASK_OR"
                                                : "MBA1_MBSECCFIR_MASK_OR";
        SCAN_COMM_REGISTER_CLASS * reg = iv_membChip->getRegister(reg_str);

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

        iv_fetchAttnsMasked = true;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::unmaskFetchAttns()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::unmaskFetchAttns] "

    int32_t o_rc = SUCCESS;

    do
    {
        // Memory CEs where masked at the beginning of the TD procedure, so
        // clear and unmask them. Also, it is possible that memory UEs have
        // thresholded so clear and unmask them as well.

        const char * fir_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR_AND"
                                                : "MBA1_MBSECCFIR_AND";
        const char * msk_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR_MASK_AND"
                                                : "MBA1_MBSECCFIR_MASK_AND";

        SCAN_COMM_REGISTER_CLASS * fir = iv_membChip->getRegister( fir_str );
        SCAN_COMM_REGISTER_CLASS * msk = iv_membChip->getRegister( msk_str );

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

        iv_fetchAttnsMasked = false;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::clearCeCounters( uint32_t i_eccErrorMask )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::clearCeCounters] "

    int32_t o_rc = SUCCESS;

    do
    {
        const char * ec0Reg_str =
                        (0 == iv_mbaPos) ? "MBA0_MBSEC0" : "MBA1_MBSEC0";
        SCAN_COMM_REGISTER_CLASS * ec0Reg =
                        iv_membChip->getRegister( ec0Reg_str );
        bool updateEc0 = false;

        o_rc = ec0Reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s", ec0Reg_str );
            break;
        }

        if ( i_eccErrorMask & SOFT_CTE )
        {
            // Clear Soft CE total count.
            ec0Reg->SetBitFieldJustified( 0, 12, 0 );
            updateEc0 = true;
        }

        if ( i_eccErrorMask & INTER_CTE )
        {
            // Clear Intermittent CE total count.
            ec0Reg->SetBitFieldJustified( 12, 12, 0 );
            updateEc0 = true;
        }

        if ( i_eccErrorMask & HARD_CTE )
        {
            // Clear the hard CE total count.
            ec0Reg->SetBitFieldJustified( 24, 12, 0 );
            updateEc0 = true;

            // Clear all of the per symbol counters. The assumption is that only
            // hard CEs are captured in the per symbol counters.

            o_rc = clearPerSymbolCounters( iv_membChip, iv_mbaPos );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "clearCeStats() failed " );
                break;
            }
        }

        if ( i_eccErrorMask & RETRY_CTE )
        {
            // Clear only the RCE total count.
            const char * ec1Reg_str =
                            (0 == iv_mbaPos) ? "MBA0_MBSEC1" : "MBA1_MBSEC1";
            SCAN_COMM_REGISTER_CLASS * ec1Reg =
                            iv_membChip->getRegister( ec1Reg_str );

            o_rc = ec1Reg->Read();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Read() failed on %s", ec1Reg_str );
                break;
            }

            ec1Reg->SetBitFieldJustified( 0, 12, 0 );

            o_rc = ec1Reg->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on %s", ec1Reg_str );
                break;
            }
        }

        if( true == updateEc0 )
        {
            o_rc = ec0Reg->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on %s", ec0Reg_str );
                break;
            }
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::doBgScrubCmd( uint32_t i_stopCond, uint32_t i_flags,
                                    const CenAddr * i_sAddrOverride )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::doBgScrubCmd] "

    int32_t o_rc = SUCCESS;

    do
    {
        mss_MaintCmd::TimeBaseSpeed cmdSpeed = enableFastBgScrub()
                                            ? mss_MaintCmd::FAST_MED_BW_IMPACT
                                            : mss_MaintCmd::BG_SCRUB;

        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::TIMEBASE_SCRUB,
                                  iv_mbaTrgt, iv_rank, i_stopCond,
                                  cmdSpeed, i_flags, i_sAddrOverride );
        if ( NULL == iv_mssCmd )
        {
            PRDF_ERR( PRDF_FUNC "createMssCmd() failed");
            o_rc = FAIL; break;
        }

        o_rc = iv_mssCmd->setupAndExecuteCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setupAndExecuteCmd() failed" );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::doTdScrubCmd( uint32_t i_stopCond, uint32_t i_flags,
                                    const CenAddr * i_sAddrOverride )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::doTdScrubCmd] "

    int32_t o_rc = SUCCESS;

    do
    {
        mss_MaintCmd::TimeBaseSpeed cmdSpeed = enableFastBgScrub()
                                            ? mss_MaintCmd::FAST_MAX_BW_IMPACT
                                            : mss_MaintCmd::FAST_MIN_BW_IMPACT;

        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::TIMEBASE_SCRUB,
                                  iv_mbaTrgt, iv_rank, i_stopCond,
                                  cmdSpeed, i_flags, i_sAddrOverride );
        if ( NULL == iv_mssCmd )
        {
            PRDF_ERR( PRDF_FUNC "createMssCmd() failed");
            o_rc = FAIL; break;
        }

        o_rc = iv_mssCmd->setupAndExecuteCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setupAndExecuteCmd() failed" );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::checkForAvailableSpares( uint8_t i_ps, bool & o_avail )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::checkForAvailableSpares] "

    int32_t o_rc = SUCCESS;

    o_avail = false;

    do
    {
        // First, make sure the spares are supported and have not been
        // intentially made unavailable by the manufacturer via the VPD.

        CenDqBitmap bitmap;
        o_rc = getBadDqBitmap( iv_mbaTrgt, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed" );
            break;
        }

        bool dramSparePossible = false;
        bool eccSparePossible  = false;
        o_rc = bitmap.isSpareAvailable( i_ps, dramSparePossible,
                                        eccSparePossible );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "isDramSpareAvailable() failed" );
            break;
        }

        // Second, query hardware for the any available spares.

        CenSymbol sp0, sp1, ecc;
        o_rc = mssGetSteerMux( iv_mbaTrgt, iv_rank, sp0, sp1, ecc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed" );
            break;
        }

        if ( ( dramSparePossible &&
               (0 == i_ps ? !sp0.isValid() : !sp1.isValid()) ) ||
             ( eccSparePossible && !ecc.isValid() ) )
        {
           o_avail = true;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void CenMbaTdCtlr::collectStateCaptureData( STEP_CODE_DATA_STRUCT & io_sc,
                                            const char * i_descTag )
{
    static const size_t sz_maxData = 256;

    // Initialize to 0.
    uint8_t data[sz_maxData];
    memset( data, 0x00, sz_maxData );

    size_t sz_actData = 0;

    //##########################################################################
    // Header data (4 bytes)
    //##########################################################################

    uint8_t mrnk        = iv_rank.getMaster();              // 3-bit
    uint8_t srnk        = iv_rank.getSlave();               // 3-bit
    uint8_t fetchMsk    = iv_fetchAttnsMasked ? 1 : 0;      // 1-bit
    uint8_t state       = iv_tdState & 0x0f;                // 4-bit
    uint8_t rescount    = iv_scrubResumeCounter.getCount(); // 8-bit
    uint8_t badRankMask = 0x00;                             // 8-bit

    TdRankList::List list = iv_masterRanks.getList();
    for ( TdRankList::ListItr it = list.begin(); it != list.end(); it++ )
    {
        if ( !it->isGood )
        {
            badRankMask |= 0x80 >> it->rank.getMaster();
        }
    }

    // This is a hack to ensure the data is non-zero. Otherwise, the section may
    // not be added to the capture data.
    uint8_t hack = 1; // 1-bit

    data[0] = rescount;
    data[1] = badRankMask;
    data[2] = state << 4 | mrnk << 1 | fetchMsk;
    data[3] = srnk  << 5 | hack << 4;                           // 4 extra bits

    sz_actData += 4;

    //##########################################################################
    // TD Request Queue (min 1 byte, max 33 bytes)
    //##########################################################################

    // To ensure we have enough space we are only going to add the first 16
    // entries of the queue.

    TdQueue::Queue queue = iv_queue.getQueue();

    uint8_t queueCount = queue.size();
    if ( 16 < queueCount ) queueCount = 16;

    data[sz_actData] = queueCount;
    sz_actData += 1;

    for ( TdQueue::QueueItr it = queue.begin(); it != queue.end(); it++ )
    {
        data[sz_actData  ] = it->type;
        data[sz_actData+1] = it->rank.getMaster() << 5 |
                             it->rank.getSlave()  << 2;     // 2 extra bits

        sz_actData += 2;
    }

    //##########################################################################
    // VCM Rank Data (min 1 byte, max 17 bytes)
    //##########################################################################

    uint8_t vcmDataCount = 0;
    uint8_t vcmDataCountIdx = sz_actData; // keep track, will update later

    sz_actData += 1; // Make room for VCM data count byte

    for ( TdRankList::ListItr it = list.begin(); it != list.end(); it++ )
    {
        CenRank master = it->rank;
        uint8_t mr = master.getMaster();

        uint8_t faCount = iv_vcmRankData.getFalseAlarmCount(master); // 8-bit

        if ( 0 != faCount )
        {
            vcmDataCount++;

            data[sz_actData  ] = faCount;
            data[sz_actData+1] = mr << 5;                       // 3 extra bits

            sz_actData += 2;
        }
    }

    data[vcmDataCountIdx] = vcmDataCount; // update count

    //##########################################################################
    // TPS Rank Data (min 1 byte, max 129 bytes)
    //##########################################################################

    uint8_t tpsDataCount = 0;
    uint8_t tpsDataCountIdx = sz_actData; // keep track, will update later

    sz_actData += 1; // Make room for TPS data count byte

    for ( TdRankList::ListItr it = list.begin(); it != list.end(); it++ )
    {
        CenRank master = it->rank;
        uint8_t mr = master.getMaster();

        for ( uint8_t sr = 0; sr < SLAVE_RANKS_PER_MASTER_RANK; sr++ )
        {
            CenRank slave = CenRank( mr, sr );

            uint8_t faCount = iv_tpsRankData.getFalseAlarmCount(slave);
            uint8_t isBan   = iv_tpsRankData.isBanned(slave, io_sc) ? 1 : 0;

            if ( (0 != faCount) || (0 != isBan) )
            {
                tpsDataCount++;

                data[sz_actData  ] = faCount;
                data[sz_actData+1] = mr << 5 | sr << 2 | isBan << 1; // 1 extra

                sz_actData += 2;
            }
        }
    }

    data[tpsDataCountIdx] = tpsDataCount; // update count

    //##########################################################################
    // Add the capture data
    //##########################################################################

    // Adjust the size to be word aligned.
    static const size_t sz_word = sizeof(CPU_WORD);
    sz_actData = ((sz_actData+sz_word-1) / sz_word) * sz_word;

    // Fix endianness issues with non PPC machines.
    for ( uint32_t i = 0; i < (sz_actData/sz_word); i++ )
        ((CPU_WORD*)data)[i] = htonl(((CPU_WORD*)data)[i]);

    // Add the capture data.
    CaptureData & cd = io_sc.service_data->GetCaptureData();
    BIT_STRING_ADDRESS_CLASS bs ( 0, sz_actData*8, (CPU_WORD *) &data );
    cd.Add( iv_mbaTrgt, Util::hashString(i_descTag), bs );
}

//------------------------------------------------------------------------------

void CenMbaTdCtlr::collectStateCaptureDataStart( STEP_CODE_DATA_STRUCT & io_sc )
{
    collectStateCaptureData( io_sc, "TDCTLR_STATE_DATA_START" );
}

//------------------------------------------------------------------------------

void CenMbaTdCtlr::collectStateCaptureDataEnd( STEP_CODE_DATA_STRUCT & io_sc )
{
    collectStateCaptureData( io_sc, "TDCTLR_STATE_DATA_END" );
}

} // end namespace PRDF
