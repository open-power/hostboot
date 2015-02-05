/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfCenMbaTdCtlr_ipl.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

// The following is required because PRD implements its own version of these
// hardware procedures:
// $Id: mss_scrub.H,v 1.4 2013/12/02 15:00:03 bellows Exp $
// $Id: mss_scrub.C,v 1.10 2014/03/11 19:06:19 gollub Exp $

#include <prdfCenMbaTdCtlr_ipl.H>

// Framework includes
#include <iipconst.h>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>

// Pegasus includes
#include <prdfCalloutUtil.H>
#include <prdfCenAddress.H>
#include <prdfCenConst.H>
#include <prdfCenDqBitmap.H>
#include <prdfCenMbaDataBundle.H>
#include <prdfCenSymbol.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------
//                            Class Variables
//------------------------------------------------------------------------------

CenMbaTdCtlr::FUNCS CenMbaTdCtlr::cv_cmdCompleteFuncs[] =
{
    &CenMbaTdCtlr::analyzeCmdComplete,      // NO_OP
    &CenMbaTdCtlr::analyzeVcmPhase1,        // VCM_PHASE_1
    &CenMbaTdCtlr::analyzeVcmPhase2,        // VCM_PHASE_2
    &CenMbaTdCtlr::analyzeDsdPhase1,        // DSD_PHASE_1
    &CenMbaTdCtlr::analyzeDsdPhase2,        // DSD_PHASE_2
    &CenMbaTdCtlr::analyzeTpsPhase1,        // TPS_PHASE_1
    &CenMbaTdCtlr::analyzeTpsPhase2,        // TPS_PHASE_2
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
        if ( !isInMdiaMode() )
        {
            PRDF_ERR( PRDF_FUNC"A hostboot maintenance command complete "
                      "attention occurred while MDIA was not running." );
            o_rc = FAIL;
            break;
        }

        o_rc = initialize();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"initialize() failed" );
            break;
        }

        // Immediately inform MDIA that the command has finished.
        o_rc = mdiaSendEventMsg( iv_mbaTrgt, MDIA::RESET_TIMER );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"mdiaSendEventMsg(RESET_TIMER) failed" );
            break;
        }

        // Get address in which the command stopped and the end address.
        // Some analysis is dependent on if the maintenance command has reached
        // the end address or stopped in the middle.
        CenAddr stopAddr;
        o_rc = getCenMaintStartAddr( iv_mbaChip, stopAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getCenMaintStartAddr() failed" );
            break;
        }

        CenAddr endAddr;
        o_rc = getCenMaintEndAddr( iv_mbaChip, endAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getCenMaintEndAddr() failed" );
            break;
        }

        // Call analysis function based on state.
        if ( NULL == cv_cmdCompleteFuncs[iv_tdState] )
        {
            PRDF_ERR( PRDF_FUNC"Function for state %d not supported",
                      iv_tdState );
            o_rc = FAIL; break;
        }

        o_rc = (this->*cv_cmdCompleteFuncs[iv_tdState])( io_sc, stopAddr,
                                                         endAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Failed to continue analysis" );
            break;
        }

        // Do some cleanup if the TD procedure is complete.
        if ( !isInTdMode() )
        {
            // Clean up the previous command
            // PRD is not starting another command but MDIA might be so clear
            // the counters and FIRs as well.
            o_rc = prepareNextCmd();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"prepareNextCmd() failed" );
                break;
            }

            // Inform MDIA about command complete
            // Note that we only want to send the command complete message if
            // everything above is successful because a bad return code will
            // result in a SKIP_MBA message sent. There is no need to send
            // redundant messages.
            o_rc = signalMdiaCmdComplete();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"signalMdiaCmdComplete() failed" );
                break;
            }

            // Clear out the mark, just in case. This is so we don't
            // accidentally callout this mark on another rank in an error path
            // scenario.
            iv_mark = CenMark();
        }

    } while(0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed." );
        badPathErrorHandling( io_sc );

        int32_t l_rc = cleanupPrevCmd(); // Just in case.
        if ( SUCCESS != l_rc )
            PRDF_ERR( PRDF_FUNC"cleanupPrevCmd() failed" );

        // Tell MDIA to skip further analysis on this MBA.
        l_rc = mdiaSendEventMsg( iv_mbaTrgt, MDIA::SKIP_MBA );
        if ( SUCCESS != l_rc )
            PRDF_ERR( PRDF_FUNC"mdiaSendEventMsg(SKIP_MBA) failed" );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc,
                                     const CenRank & i_rank,
                                     const CenMbaTdCtlrCommon::TdType i_event,
                                     bool i_banTps )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleTdEvent] "

    // This is a no-op in Hostboot because we can't support Targeted Diagnostics
    // at this time. Instead, print a trace statement indicating the intended
    // request. Note that any VCM request will eventually be found during the
    // initialization of the runtime TD controller.
    PRDF_INF( PRDF_FUNC"TD request found during Hostboot: iv_mbaChip=0x%08x "
              "i_rank=M%dS%d i_event=%d i_banTps=%c", iv_mbaChip->GetId(),
              i_rank.getMaster(), i_rank.getSlave(), i_event,
              i_banTps ? 'T' : 'F' );

    return SUCCESS;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startInitialBgScrub()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startInitialBgScrub] "

    int32_t o_rc = SUCCESS;

    iv_tdState = NO_OP;

    // NOTE: It is possible for a chip mark to have been placed between MDIA
    //       and the initial start scrub. Those unverified chip marks will be
    //       found in the runtime TD controller's initialize() function. The
    //       chip marks will then be verified after the initial fast scrub is
    //       complete.

    do
    {
        // Should have been initialized during MDIA. If not, there is a serious
        // logic issue.
        if ( !iv_initialized )
        {
            PRDF_ERR( PRDF_FUNC"TD controller not initialized." );
            break;
        }

        // Cleanup hardware before starting the maintenance command. This will
        // clear the ECC counters, which must be done before setting the ETE
        // thresholds.
        o_rc = prepareNextCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"prepareNextCmd() failed" );
            break;
        }

        // Set the default thresholds for all ETE attentions.
        o_rc = setRtEteThresholds();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setRtEteThresholds() failed" );
            break;
        }

        // Need the first rank in memory.
        CenAddr startAddr, junk;
        o_rc = getMemAddrRange( iv_mbaTrgt, startAddr, junk );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getMemAddrRange() failed" );
            break;
        }

        mss_MaintCmd::TimeBaseSpeed cmdSpeed = enableFastBgScrub()
                                            ? mss_MaintCmd::FAST_MED_BW_IMPACT
                                            : mss_MaintCmd::FAST_MIN_BW_IMPACT;

        uint32_t stopCond = COND_FAST_SCRUB;

        // TODO: RTC 123338: There are some OpenPOWER companies that do not want
        //       to run with HBRT PRD enabled. Currently the only option right
        //       now is to use the compile flag. Eventually, we may want to add
        //       this as MRW/BIOS option.
        #ifndef CONFIG_HBRT_PRD

        // HBRT PRD is not enabled. Check if this system has an FSP.
        if ( !isSpConfigFsp() )
        {
            // No runtime PRD will be present. Do not start the initial fast
            // scrub. Instead, simply start continuous background scrubbing with
            // no stop-on-error conditions.
            cmdSpeed = enableFastBgScrub() ? mss_MaintCmd::FAST_MED_BW_IMPACT
                                           : mss_MaintCmd::BG_SCRUB;
            stopCond = 0;
        }

        #endif // ifdef CONFIG_HBRT_PRD

        // Start the initial fast scrub.
        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::TIMEBASE_SCRUB,
                                  iv_mbaTrgt, startAddr.getRank(),
                                  stopCond, cmdSpeed,
                                  mss_MaintCmdWrapper::END_OF_MEMORY );
        if ( NULL == iv_mssCmd )
        {
            PRDF_ERR( PRDF_FUNC"createMssCmd() failed" );
            o_rc = FAIL; break;
        }

        o_rc = iv_mssCmd->setupAndExecuteCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setupAndExecuteCmd() failed" );
            break;
        }

    } while (0);

    if ( SUCCESS != o_rc )
    {
        // Can't use badPathErrorHandling() because there is no SDC created when
        // this function is called.

        PRDF_ERR( PRDF_FUNC"iv_mbaChip:0x%08x iv_initialized:%c",
                  iv_mbaChip->GetId(), iv_initialized ? 'T' : 'F' );

        int32_t l_rc = cleanupPrevCmd(); // Just in case.
        if ( SUCCESS != l_rc )
            PRDF_ERR( PRDF_FUNC"cleanupPrevCmd() failed" );
    }

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
            PRDF_ERR( PRDF_FUNC"CenMbaTdCtlrCommon::initialize() failed" );
            break;
        }

        // At this point, the TD controller is initialized.
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
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Initialize iv_rank. This must be done before calling other
        // functions as they require iv_rank to be accurate.
        iv_rank = CenRank( i_stopAddr.getRank() );

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"checkEccErrors() failed" );
            break;
        }

        if ( eccErrorMask & UE )
        {
            // Handle UE. Highest priority
            o_rc = handleUE( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"handleUE() failed" );
                break;
            }
        }
        else if ( eccErrorMask & MPE )
        {
            o_rc = handleMPE( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"handleMPE() failed");
                break;
            }
        }
        else if ( isMfgCeCheckingEnabled() && (eccErrorMask & HARD_CTE) )
        {
            // During MNFG IPL CE, we will get this condition.
            // During SF read, all CE are reported as Hard CE.
            // So we will only check for Hard CE threshold.
            o_rc = handleMnfgCeEte( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"handleMnfgCeEte() failed" );
                break;
            }
        }
        else
        {
            // If maint cmd completed with no error, don't commit error log.
            io_sc.service_data->DontCommitErrorLog();
        }

    } while (0);

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
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Add the mark to the callout list.
        CalloutUtil::calloutMark( iv_mbaTrgt, iv_rank, iv_mark, io_sc );

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"checkEccErrors() failed" );
            break;
        }

        if ( (eccErrorMask & UE) || (eccErrorMask & RETRY_CTE) )
        {
            // Handle UE. Highest priority
            o_rc = handleUE( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"handleUE() failed" );
                break;
            }
        }
        else
        {
            // Start VCM Phase 2
            o_rc = startVcmPhase2( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"startVcmPhase2() failed" );
                break;
            }
        }

    } while(0);

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
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Add the mark to the callout list.
        CalloutUtil::calloutMark( iv_mbaTrgt, iv_rank, iv_mark, io_sc );

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"checkEccErrors() failed" );
            break;
        }

        if ( eccErrorMask & UE )
        {
            // Handle UE. Highest priority
            o_rc = handleUE( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"handleUE() failed" );
                break;
            }
        }
        else if ( eccErrorMask & MCE )
        {
            // Chip mark is verified.

            // Do callouts, VPD updates, and start DRAM sparing, if possible.
            o_rc = handleMCE_VCM2( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"handleMCE_VCM2() failed" );
                break;
            }
        }
        else
        {
            // Chip mark verification failed.

            iv_tdState = NO_OP; // Abort the TD procedure.

            setTdSignature( io_sc, PRDFSIG_VcmFalseAlarm );

            // In the field, this error log will be recoverable for now, but we
            // may have to add thresholding later if they become a problem. In
            // manufacturing, this error log will be predictive.

            if ( areDramRepairsDisabled() )
                io_sc.service_data->SetServiceCall();

            // Remove chip mark from hardware.
            iv_mark.clearCM();
            bool blocked; // not possible during MDIA
            o_rc = mssSetMarkStore( iv_mbaTrgt, iv_rank, iv_mark, blocked );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"mssSetMarkStore() failed" );
                break;
            }
        }

    } while(0);

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
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Add the mark to the callout list.
        CalloutUtil::calloutMark( iv_mbaTrgt, iv_rank, iv_mark, io_sc );

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc)
        {
            PRDF_ERR( PRDF_FUNC"checkEccErrors() failed" );
            break;
        }

        if ( ( eccErrorMask & UE) || ( eccErrorMask & RETRY_CTE ) )
        {
            // Handle UE. Highest priority
            o_rc = handleUE( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"handleUE() failed" );
                break;
            }
        }
        else
        {
            // Start DSD Phase 2
            o_rc = startDsdPhase2( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"startDsdPhase2() failed" );
                break;
            }
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::analyzeDsdPhase2( STEP_CODE_DATA_STRUCT & io_sc,
                                        const CenAddr & i_stopAddr,
                                        const CenAddr & i_endAddr )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::analyzeDsdPhase2] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( DSD_PHASE_2 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Add the mark to the callout list.
        CalloutUtil::calloutMark( iv_mbaTrgt, iv_rank, iv_mark, io_sc );

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"checkEccErrors() failed" );
            break;
        }

        if ( eccErrorMask & UE)
        {
            // Handle UE. Highest priority
            o_rc = handleUE( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"handleUE() failed" );
                break;
            }
        }
        else if ( eccErrorMask & MCE )
        {
            // The spare is bad.

            // Do callouts and VPD updates.
            o_rc = handleMCE_DSD2( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"handleMCE_DSD2() failed" );
                break;
            }
        }
        else
        {
            // The chip mark has successfully been steered to the spare.

            setTdSignature( io_sc, PRDFSIG_DsdDramSpared );

            // Remove chip mark from hardware.
            iv_mark.clearCM();
            bool blocked; // not possible during MDIA
            o_rc = mssSetMarkStore( iv_mbaTrgt, iv_rank, iv_mark, blocked );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"mssSetMarkStore() failed" );
                break;
            }
        }

        iv_tdState = NO_OP; // The TD procedure is complete.

    } while(0);

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
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );

        o_rc = mbadb->getIplCeStats()->collectStats( iv_rank );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"collectStats() failed");
            break;
        }

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"checkEccErrors() failed" );
            break;
        }

        if ( ( eccErrorMask & UE ) || ( eccErrorMask & RETRY_CTE ))
        {
            // Handle UE. Highest priority
            o_rc = handleUE( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"handleUE() failed" );
                break;
            }
        }
        else if ( eccErrorMask & MPE )
        {
            o_rc = handleMPE( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"handleMPE() failed");
                break;
            }
        }
        else
        {
            // No error found so add rank to callout list, just in case.
            MemoryMru memmru (iv_mbaTrgt, iv_rank, MemoryMruData::CALLOUT_RANK);
            io_sc.service_data->SetCallout( memmru );

            // Start TPS Phase 2
            o_rc = startTpsPhase2( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"startTpsPhase2() failed" );
                break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::analyzeTpsPhase2( STEP_CODE_DATA_STRUCT & io_sc,
                                        const CenAddr & i_stopAddr,
                                        const CenAddr & i_endAddr )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::analyzeTpsPhase2] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( TPS_PHASE_2 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );

        o_rc = mbadb->getIplCeStats()->calloutHardCes( iv_rank );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"calloutHardCes() failed");
            break;
        }

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"checkEccErrors() failed" );
            break;
        }

        if ( ( eccErrorMask & UE ) || ( eccErrorMask & RETRY_CTE ))
        {
            // Handle UE. Highest priority
            o_rc = handleUE( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"handleUE() failed" );
                break;
            }
        }
        else if ( eccErrorMask & MPE )
        {
            o_rc = handleMPE( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"handleMPE() failed");
                break;
            }
        }
        else
        {
            // No error found so add rank to callout list, just in case.
            MemoryMru memmru (iv_mbaTrgt, iv_rank, MemoryMruData::CALLOUT_RANK);
            io_sc.service_data->SetCallout( memmru );

            io_sc.service_data->AddSignatureList( iv_mbaTrgt,
                                                  PRDFSIG_EndTpsPhase2 );
            iv_tdState = NO_OP;
        }

    } while (0);

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
        o_rc = prepareNextCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"prepareNextCmd() failed" );
            break;
        }

        // Start phase 1.
        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::TIMEBASE_STEER_CLEANUP,
                                  iv_mbaTrgt, iv_rank, COND_TARGETED_CMD );
        if ( NULL == iv_mssCmd )
        {
            PRDF_ERR( PRDF_FUNC"createMssCmd() failed");
            o_rc = FAIL; break;
        }

        o_rc = iv_mssCmd->setupAndExecuteCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setupAndExecuteCmd() failed" );
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
        o_rc = prepareNextCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"prepareNextCmd() failed" );
            break;
        }

        // Start phase 2.
        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::SUPERFAST_READ,
                                  iv_mbaTrgt, iv_rank, COND_TARGETED_CMD );
        if ( NULL == iv_mssCmd )
        {
            PRDF_ERR( PRDF_FUNC"createMssCmd() failed");
            o_rc = FAIL; break;
        }

        o_rc = iv_mssCmd->setupAndExecuteCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setupAndExecuteCmd() failed" );
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
        o_rc = prepareNextCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"prepareNextCmd() failed" );
            break;
        }

        // Set the steer mux
        o_rc = mssSetSteerMux( iv_mbaTrgt, iv_rank, iv_mark.getCM(),
                               iv_isEccSteer );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"mssSetSteerMux() failed" );
            break;
        }

        // Start phase 1.
        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::TIMEBASE_STEER_CLEANUP,
                                  iv_mbaTrgt, iv_rank, COND_TARGETED_CMD );
        if ( NULL == iv_mssCmd )
        {
            PRDF_ERR( PRDF_FUNC"createMssCmd() failed");
            o_rc = FAIL; break;
        }

        o_rc = iv_mssCmd->setupAndExecuteCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setupAndExecuteCmd() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startDsdPhase2( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startDsdPhase2] "

    int32_t o_rc = SUCCESS;

    io_sc.service_data->AddSignatureList( iv_mbaTrgt, PRDFSIG_StartDsdPhase2 );
    iv_tdState = DSD_PHASE_2;

    do
    {
        o_rc = prepareNextCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"prepareNextCmd() failed" );
            break;
        }

        // Start phase 2.
        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::SUPERFAST_READ,
                                  iv_mbaTrgt, iv_rank, COND_TARGETED_CMD );
        if ( NULL == iv_mssCmd )
        {
            PRDF_ERR( PRDF_FUNC"createMssCmd() failed");
            o_rc = FAIL; break;
        }

        o_rc = iv_mssCmd->setupAndExecuteCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setupAndExecuteCmd() failed" );
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
        o_rc = prepareNextCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"prepareNextCmd() failed" );
            break;
        }

        // We are using current state as input parameter in mnfgCeSetup.
        // So it is mandatory to set iv_tdState before calling this function.
        o_rc = mnfgCeSetup();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"mnfgCeSetup() failed" );
            break;
        }

        // Start phase 1.
        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::TIMEBASE_SCRUB,
                                  iv_mbaTrgt, iv_rank, COND_TARGETED_CMD,
                                  mss_MaintCmd::FAST_MAX_BW_IMPACT,
                                  mss_MaintCmdWrapper::SLAVE_RANK_ONLY );
        if ( NULL == iv_mssCmd )
        {
            PRDF_ERR( PRDF_FUNC"createMssCmd() failed");
            o_rc = FAIL; break;
        }

        o_rc = iv_mssCmd->setupAndExecuteCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setupAndExecuteCmd() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startTpsPhase2( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startTpsPhase2] "

    int32_t o_rc = SUCCESS;

    io_sc.service_data->AddSignatureList( iv_mbaTrgt, PRDFSIG_StartTpsPhase2 );
    iv_tdState = TPS_PHASE_2;

    do
    {
        o_rc = prepareNextCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"prepareNextCmd() failed" );
            break;
        }

        // We are using current state as input parameter in mnfgCeSetup.
        // So it is mandatory to set iv_tdState before calling this function.
        o_rc = mnfgCeSetup();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"mnfgCeSetup() failed" );
            break;
        }

        // Start phase 2.
        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::TIMEBASE_SCRUB,
                                  iv_mbaTrgt, iv_rank, COND_TARGETED_CMD,
                                  mss_MaintCmd::FAST_MAX_BW_IMPACT,
                                  mss_MaintCmdWrapper::SLAVE_RANK_ONLY );
        if ( NULL == iv_mssCmd )
        {
            PRDF_ERR( PRDF_FUNC"createMssCmd() failed");
            o_rc = FAIL; break;
        }

        o_rc = iv_mssCmd->setupAndExecuteCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setupAndExecuteCmd() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleUE( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleUE] "

    using namespace CalloutUtil;

    int32_t o_rc = SUCCESS;

    iv_tdState = NO_OP; // Abort the TD procedure.

    setTdSignature( io_sc, PRDFSIG_MaintUE );
    io_sc.service_data->SetServiceCall();

    CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );

    do
    {
        // Clean up the maintenance command. This is needed just in case the UE
        // isolation procedure is modified to use maintenance commands.
        o_rc = cleanupPrevCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"cleanupPrevCmd() failed" );
            break;
        }

        // Look for all failing bits on this rank.
        CenDqBitmap bitmap;
        o_rc = mssIplUeIsolation( iv_mbaTrgt, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"mssIplUeIsolation() failed" );
            break;
        }

        // Add UE data to capture data.
        bitmap.getCaptureData( io_sc.service_data->GetCaptureData() );

        // Callout the failing DIMMs.
        TargetHandleList callouts;
        for ( int32_t ps = 0; ps < PORT_SLCT_PER_MBA; ps++ )
        {
            bool badDqs = false;
            o_rc = bitmap.badDqs( ps, badDqs );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"badDqs(%d) failed", ps );
                break;
            }

            if ( !badDqs ) continue; // nothing to do.

            TargetHandleList dimms = getConnectedDimms(iv_mbaTrgt, iv_rank, ps);
            if ( 0 == dimms.size() )
            {
                PRDF_ERR( PRDF_FUNC"getConnectedDimms(%d) failed", ps );
                o_rc = FAIL; break;
            }

            callouts.insert( callouts.end(), dimms.begin(), dimms.end() );

            if ( isMfgCeCheckingEnabled() )
            {
                // As we are doing callout for UE, we dont need to do callout
                // during CE for this rank on given port
                mbadb->getIplCeStats()->banAnalysis( iv_rank, ps );
            }
        }
        if ( SUCCESS != o_rc ) break;

        if ( 0 == callouts.size() )
        {
            // It is possible the scrub counters have rolled over to zero due to
            // a known DD1.0 hardware bug. In this case, the best we can do is
            // callout both DIMMs, because at minimum we know there was a UE, we
            // just don't know where.
            // NOTE: If this condition happens because of a DD2.0+ bug, the
            //       mssIplUeIsolation procedure will callout the Centaur.
            callouts = getConnectedDimms( iv_mbaTrgt, iv_rank );
            if ( 0 == callouts.size() )
            {
                PRDF_ERR( PRDF_FUNC"getConnectedDimms() failed" );
                o_rc = FAIL; break;
            }

            if ( isMfgCeCheckingEnabled() )
            {
                // As we are doing callout for UE, we dont need to do callout
                // during CE for this rank on both port
                mbadb->getIplCeStats()->banAnalysis( iv_rank);
            }
        }

        // Callout all DIMMs in the list.
        for ( TargetHandleList::iterator i = callouts.begin();
              i != callouts.end(); i++ )
        {
            io_sc.service_data->SetCallout( *i, MRU_HIGH );
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleMPE( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleMPE] "

    int32_t o_rc = SUCCESS;

    setTdSignature( io_sc, PRDFSIG_MaintMPE );

    do
    {
        // Get the current marks in hardware.
        o_rc = mssGetMarkStore( iv_mbaTrgt, iv_rank, iv_mark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"mssGetMarkStore() failed");
            break;
        }

        if ( !iv_mark.getCM().isValid() )
        {
            PRDF_ERR( PRDF_FUNC"No valid chip mark to verify");
            o_rc = FAIL; break;
        }

        CalloutUtil::calloutMark( iv_mbaTrgt, iv_rank, iv_mark, io_sc );

        // Start VCM procedure
        o_rc = startVcmPhase1( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"startVcmPhase1() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleMnfgCeEte( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleMnfgCeEte] "

    using namespace CalloutUtil;

    int32_t o_rc = SUCCESS;

    do
    {
        MemUtils::MaintSymbols symData; CenSymbol junk;
        o_rc = MemUtils::collectCeStats( iv_mbaChip, iv_rank, symData, junk);
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"MemUtils::collectCeStats() failed. MBA:0x%08x",
                      iv_mbaChip->GetId() );
            break;
        }

        // As HW threshold is set as 1 in mdia, we should only get one symbol
        // here. If there is no symbol, that is an HW error.
        if( 0 == symData.size() )
        {
            PRDF_ERR( PRDF_FUNC" symData size is 0. MBA:0x%08x",
                      iv_mbaChip->GetId() );
            o_rc = FAIL; break;
        }

        // Callout the symbol.
        MemoryMru memmru ( iv_mbaTrgt, iv_rank, symData[0].symbol );
        io_sc.service_data->SetCallout( memmru );

        // Start TPS Phase 1
        o_rc = startTpsPhase1( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"startTpsPhase1() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::signalMdiaCmdComplete()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::signalMdiaCmdComplete] "

    int32_t o_rc = SUCCESS;

    do
    {
        // Determine for MDIA whether or not the command finished at the end of
        // the last rank or if the command will need to be restarted.

        // Get the last address of the last rank in memory.
        CenAddr junk, allEndAddr;
        o_rc = getMemAddrRange( iv_mbaTrgt, junk, allEndAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getMemAddrRange() failed" );
            break;
        }

        // Need to compare the address in which the command stopped.
        CenAddr stoppedAddr;
        o_rc = getCenMaintStartAddr( iv_mbaChip, stoppedAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"cenGetMaintAddr() failed" );
            break;
        }

        // The actual message will need to be sent in post analysis after the
        // FIR bits have been cleared.
        CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );
        mbadb->iv_sendCmdCompleteMsg = true;
        mbadb->iv_cmdCompleteMsgData =
                        (allEndAddr == stoppedAddr) ? MDIA::COMMAND_COMPLETE
                                                    : MDIA::COMMAND_STOPPED;

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Do the setup for mnfg IPL CE
int32_t CenMbaTdCtlr::mnfgCeSetup()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::mnfgCeSetup] "

    int32_t o_rc = SUCCESS;

    do
    {
        const char * reg_str = (0 == iv_mbaPos) ? "MBA0_MBSTR" : "MBA1_MBSTR";
        SCAN_COMM_REGISTER_CLASS * mbstr = iv_membChip->getRegister( reg_str );
        // MBSTR's content could be modified from cleanupCmd()
        // so we need to refresh
        o_rc = mbstr->ForceRead();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on %s", reg_str );
            break;
        }

        if ( TPS_PHASE_1 == iv_tdState )
        {
            //  Enable per-symbol error counters to count soft CEs
            mbstr->SetBit(55);
            mbstr->SetBit(56);
            // Disable per-symbol error counters to count hard CEs
            mbstr->ClearBit(57);
        }
        else if ( TPS_PHASE_2 == iv_tdState )
        {
            //  Disable per-symbol error counters to count soft CEs
            mbstr->ClearBit(55);
            mbstr->ClearBit(56);
            //  Enable per-symbol error counters to count hard CEs
            mbstr->SetBit(57);
        }
        else
        {
            PRDF_ERR( PRDF_FUNC"Inavlid State:%u", iv_tdState );
            o_rc = FAIL; break;
        }

        o_rc = mbstr->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on %s", reg_str );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

} // end namespace PRDF

