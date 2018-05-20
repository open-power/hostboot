/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaTdCtlr_rt.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
//                            Private Functions
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

int32_t CenMbaTdCtlr::startTpsPhase1( STEP_CODE_DATA_STRUCT & io_sc )
{
    // Initially true, until hardware error is found.
    iv_tpsFalseAlarm = true;

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // moved to TpsEvent class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
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
        // Add entry to UE table.
        if ( (TPS_PHASE_1 != iv_tdState) )
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
        const char * fir_str = (0 == iv_mbaPos) ? "MBSECCFIR_0_AND"
                                                : "MBSECCFIR_1_AND";

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

        // Callout all DIMMs that have reached threshold.
        //   Centaur DIMMS: Any non-zero count, threshold on 1.
        //   IS DIMMS:      Allow 1, threshold on 2 (because of limited spares).
        uint8_t thr = isMembufOnDimm<TYPE_MBA>(iv_mbaTrgt) ? 1 : 2;
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
            o_thr = getScrubCeThreshold( iv_mbaChip, iv_rank );
        }

    } while( 0 );

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
        const char * reg_str = (0 == iv_mbaPos) ? "MBSECCFIR_0_AND"
                                                : "MBSECCFIR_1_AND";
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

} // end namespace PRDF
