/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfCenMbaTdCtlr.C $           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#include <prdfCenMbaTdCtlr.H>

// Framework includes
#include <iipconst.h>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>
#include <prdfRegisterCache.H>
#include <prdfTrace.H>

// Pegasus includes
#include <prdfCalloutUtil.H>
#include <prdfCenAddress.H>
#include <prdfCenConst.H>
#include <prdfCenDqBitmap.H>
#include <prdfCenMbaDataBundle.H>
#include <prdfCenSymbol.H>

// TODO: RTC 68096 Currently we are only supporting x8 DRAM. Once support for x4
//       DRAM is available, it will have impact on DRAM spare.

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

enum EccErrorMask
{
    NO_ERROR  = 0,        ///< No ECC errors found
    UE        = 0x01,     ///< UE
    MPE       = 0x02,     ///< Chip mark placed
    MCE       = 0x04,     ///< CE on chip mark
    HARD_CTE  = 0x08,     ///< Hard CE threshold exceeed
    SOFT_CTE  = 0x10,     ///< Soft CE threshold exceeed
    INTER_CTE = 0x20,     ///< Intermittent CE threshold exceeed
    RETRY_CTE = 0x40,     ///< Retry CE threshold exceeed
};

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
    NULL,                                   // RANK_SCRUB
};

//------------------------------------------------------------------------------
//                            Public Functions
//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleCmdCompleteEvent( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleCmdCompleteEvent] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

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
        o_rc = mdiaSendEventMsg( mba, MDIA::RESET_TIMER );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"mdiaSendEventMsg(RESET_TIMER) failed" );
            break;
        }

        if ( NULL == cv_cmdCompleteFuncs[iv_tdState] )
        {
            PRDF_ERR( PRDF_FUNC"Function for state %d not supported",
                      iv_tdState );
            o_rc = FAIL; break;
        }

        o_rc = (this->*cv_cmdCompleteFuncs[iv_tdState])( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Failed to continue analysis" );
            break;
        }

        // Do some cleanup if the TD procedure is complete.
        if ( !isInTdMode() )
        {
            o_rc = exitTdSequence();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"exitTdSequence() failed" );
                break;
            }
        }

    } while(0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"iv_mbaChip:0x%08x iv_initialized:%c iv_tdState:%d "
                  "iv_rank:M%dS%d iv_mark:%2d %2d", getHuid(mba),
                  iv_initialized ? 'T' : 'F', iv_tdState, iv_rank.getMaster(),
                  iv_rank.getSlave(), iv_mark.getCM().getSymbol(),
                  iv_mark.getSM().getSymbol() );

        int32_t l_rc = cleanupPrevCmd(); // Just in case.
        if ( SUCCESS != l_rc )
            PRDF_ERR( PRDF_FUNC"cleanupPrevCmd() failed" );

        l_rc = mdiaSendEventMsg( mba, MDIA::SKIP_MBA );
        if ( SUCCESS != l_rc )
            PRDF_ERR( PRDF_FUNC"mdiaSendEventMsg(SKIP_MBA) failed" );

        io_sc.service_data->SetErrorSig( PRDFSIG_MaintCmdComplete_ERROR );
        io_sc.service_data->SetServiceCall();

        // There may have been a code bug, callout 2nd level support.
        io_sc.service_data->SetCallout( NextLevelSupport_ENUM, MRU_HIGH );

        // Callout the mark. If nothing was added to the callout list (no valid
        // marks), callout the MBA.
        CalloutUtil::calloutMark( mba, iv_rank, iv_mark, io_sc );
        if ( 1 == io_sc.service_data->GetMruList().size() )
            io_sc.service_data->SetCallout( mba );

        // Just in case it was a legitimate maintenance command complete (error
        // log not committed) but something else failed.
        io_sc.service_data->ClearFlag(ServiceDataCollector::DONT_COMMIT_ERRL);
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc,
                                     const CenRank & i_rank,
                                     const CenMbaTdCtlrCommon::TdType i_event )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleTdEvent] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        o_rc = initialize();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"initialize() failed" );
            break;
        }

        // This is a no-op in Hostboot. Instead, print a trace statement
        // indicating the intended request.
        PRDF_INF( PRDF_FUNC"TD request found during Hostboot: "
                  "iv_mbaChip=0x%08x i_rank=M%dS%d i_event=%d",
                  getHuid(mba), i_rank.getMaster(), i_rank.getSlave(),
                  i_event );

    } while(0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"iv_mbaChip:0x%08x iv_initialized:%c iv_tdState:%d",
                  getHuid(mba), iv_initialized ? 'T' : 'F', iv_tdState );
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

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        if ( iv_initialized ) break; // nothing to do

        // Check for valid MBA.
        if ( TYPE_MBA != getTargetType(mba) )
        {
            PRDF_ERR( PRDF_FUNC"iv_mbaChip is not TYPE_MBA" );
            o_rc = FAIL; break;
        }

        iv_initialized = true;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::analyzeCmdComplete( STEP_CODE_DATA_STRUCT & io_sc )
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

        // Get the rank on which maintenance command stopped
        CenAddr addr;
        o_rc = getCenMaintStartAddr( iv_mbaChip, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"cenGetMaintAddr() failed" );
            break;
        }
        iv_rank = CenRank( addr.getRank() );

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask );
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

            // Start TPS Phase 1
            io_sc.service_data->SetErrorSig( PRDFSIG_StartTpsPhase1 );
            o_rc = startTpsPhase1();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"startTpsPhase1() failed" );
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

int32_t CenMbaTdCtlr::analyzeVcmPhase1( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::analyzeVcmPhase1] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        if ( VCM_PHASE_1 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask );
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
            io_sc.service_data->SetErrorSig( PRDFSIG_StartVcmPhase2 );

            CalloutUtil::calloutMark( mba, iv_rank, iv_mark, io_sc );

            // Start VCM Phase 2
            o_rc = startVcmPhase2();
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

int32_t CenMbaTdCtlr::analyzeVcmPhase2( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::analyzeVcmPhase2] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        if ( VCM_PHASE_2 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask );
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

            io_sc.service_data->SetErrorSig( PRDFSIG_VcmFalseAlarm );

            CalloutUtil::calloutMark( mba, iv_rank, iv_mark, io_sc );

            // In the field, this error log will be recoverable for now, but we
            // may have to add thresholding later if they become a problem. In
            // manufacturing, this error log will be predictive.

            if ( areDramRepairsDisabled() )
                io_sc.service_data->SetServiceCall();

            // Remove chip mark from hardware.
            iv_mark.clearCM();
            bool junk;
            o_rc = mssSetMarkStore( mba, iv_rank, iv_mark, junk );
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

int32_t CenMbaTdCtlr::analyzeDsdPhase1( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::analyzeDsdPhase1] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        if ( DSD_PHASE_1 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask );
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
            io_sc.service_data->SetErrorSig( PRDFSIG_StartDsdPhase2 );

            CalloutUtil::calloutMark( mba, iv_rank, iv_mark, io_sc );

            // Start DSD Phase 2
            o_rc = startDsdPhase2();
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

int32_t CenMbaTdCtlr::analyzeDsdPhase2( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::analyzeDsdPhase2] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        if ( DSD_PHASE_2 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask );
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

            io_sc.service_data->SetErrorSig( PRDFSIG_DsdDramSpared );

            CalloutUtil::calloutMark( mba, iv_rank, iv_mark, io_sc );

            // Remove chip mark from hardware.
            iv_mark.clearCM();
            bool junk;
            o_rc = mssSetMarkStore( mba, iv_rank, iv_mark, junk );
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

int32_t CenMbaTdCtlr::analyzeTpsPhase1( STEP_CODE_DATA_STRUCT & io_sc )
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
        o_rc = checkEccErrors( eccErrorMask );
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
            // Start TPS Phase 2
            io_sc.service_data->SetErrorSig( PRDFSIG_StartTpsPhase2 );
            o_rc = startTpsPhase2();
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

int32_t CenMbaTdCtlr::analyzeTpsPhase2( STEP_CODE_DATA_STRUCT & io_sc )
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
        o_rc = checkEccErrors( eccErrorMask );
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
            io_sc.service_data->SetErrorSig( PRDFSIG_EndTpsPhase2 );
            iv_tdState = NO_OP;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startVcmPhase1()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startVcmPhase1] "

    int32_t o_rc = SUCCESS;

    iv_tdState = VCM_PHASE_1;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        o_rc = prepareNextCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"prepareNextCmd() failed" );
            break;
        }

        // Start phase 1.
        uint32_t stopCond = ( mss_MaintCmd::STOP_ON_END_ADDRESS |
                              mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION );

        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::TIMEBASE_STEER_CLEANUP,
                                  mba, iv_rank, stopCond );
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

int32_t CenMbaTdCtlr::startVcmPhase2()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startVcmPhase2] "

    int32_t o_rc = SUCCESS;

    iv_tdState = VCM_PHASE_2;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        o_rc = prepareNextCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"prepareNextCmd() failed" );
            break;
        }

        // Start phase 2.
        uint32_t stopCond = ( mss_MaintCmd::STOP_ON_END_ADDRESS |
                              mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION );

        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::SUPERFAST_READ,
                                  mba, iv_rank, stopCond );
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

int32_t CenMbaTdCtlr::startDsdPhase1()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startDsdPhase1] "

    int32_t o_rc = SUCCESS;

    iv_tdState = DSD_PHASE_1;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        o_rc = prepareNextCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"prepareNextCmd() failed" );
            break;
        }

        // Set the steer mux
        o_rc = mssSetSteerMux( mba, iv_rank, iv_mark.getCM(), false );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"mssSetSteerMux() failed" );
            break;
        }

        // Start phase 1.
        uint32_t stopCond = ( mss_MaintCmd::STOP_ON_END_ADDRESS |
                              mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION );

        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::TIMEBASE_STEER_CLEANUP,
                                  mba, iv_rank, stopCond );
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

int32_t CenMbaTdCtlr::startDsdPhase2()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startDsdPhase2] "

    int32_t o_rc = SUCCESS;

    iv_tdState = DSD_PHASE_2;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        o_rc = prepareNextCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"prepareNextCmd() failed" );
            break;
        }

        // Start phase 2.
        uint32_t stopCond = ( mss_MaintCmd::STOP_ON_END_ADDRESS |
                              mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION );

        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::SUPERFAST_READ,
                                  mba, iv_rank, stopCond );
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

int32_t CenMbaTdCtlr::startTpsPhase1()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startTpsPhase1] "

    int32_t o_rc = SUCCESS;

    iv_tdState = TPS_PHASE_1;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

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
        uint32_t stopCond = ( mss_MaintCmd::STOP_ON_END_ADDRESS |
                              mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION );

        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::TIMEBASE_SCRUB,
                                  mba, iv_rank, stopCond, true, true );
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

int32_t CenMbaTdCtlr::startTpsPhase2()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::startTpsPhase2] "

    int32_t o_rc = SUCCESS;

    iv_tdState = TPS_PHASE_2;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

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
        uint32_t stopCond = ( mss_MaintCmd::STOP_ON_END_ADDRESS |
                              mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION );

        iv_mssCmd = createMssCmd( mss_MaintCmdWrapper::TIMEBASE_SCRUB,
                                  mba, iv_rank, stopCond, true, true );
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

int32_t CenMbaTdCtlr::checkEccErrors( uint16_t & o_eccErrorMask )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::checkEccErrors] "

    int32_t o_rc = SUCCESS;

    o_eccErrorMask = NO_ERROR;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );
        ExtensibleChip * membChip = mbadb->getMembChip();
        if ( NULL == membChip )
        {
            PRDF_ERR( PRDF_FUNC"getMembChip() failed: MBA=0x%08x",
                      getHuid(mba) );
            o_rc = FAIL; break;
        }

        const char * reg_str = ( 0 == getTargetPosition(mba) )
                                    ? "MBA0_MBSECCFIR" : "MBA1_MBSECCFIR";
        SCAN_COMM_REGISTER_CLASS * mbsEccFir = membChip->getRegister( reg_str );

        o_rc = mbsEccFir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on %s", reg_str );
            break;
        }

        if ( mbsEccFir->IsBitSet(20 + iv_rank.getMaster()) )
        {
            o_eccErrorMask |= MPE;

            // Clean up side-effect FIRs that may be set due to the chip mark.
            o_rc = chipMarkCleanup();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"chipMarkCleanup() failed" );
                break;
            }
        }

        if ( mbsEccFir->IsBitSet(38) ) o_eccErrorMask |= MCE;
        if ( mbsEccFir->IsBitSet(41) ) o_eccErrorMask |= UE;

        SCAN_COMM_REGISTER_CLASS * mbaSpaFir =
                            iv_mbaChip->getRegister("MBASPA");
        o_rc = mbaSpaFir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Failed to read MBASPA Regsiter");
            break;
        }

        if ( mbaSpaFir->IsBitSet(1) ) o_eccErrorMask |= HARD_CTE;
        if ( mbaSpaFir->IsBitSet(2) ) o_eccErrorMask |= SOFT_CTE;
        if ( mbaSpaFir->IsBitSet(3) ) o_eccErrorMask |= INTER_CTE;
        if ( mbaSpaFir->IsBitSet(4) ) o_eccErrorMask |= RETRY_CTE;

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

    io_sc.service_data->SetErrorSig( PRDFSIG_MaintUE );
    io_sc.service_data->SetServiceCall();

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();
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
        o_rc = mssIplUeIsolation( mba, iv_rank, bitmap );
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

            TargetHandleList dimms = getConnectedDimms( mba, iv_rank, ps );
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
            callouts = getConnectedDimms( mba, iv_rank );
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

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        // Get the current marks in hardware.
        o_rc = mssGetMarkStore( mba, iv_rank, iv_mark );
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

        io_sc.service_data->SetErrorSig( PRDFSIG_StartVcmPhase1 );

        CalloutUtil::calloutMark( mba, iv_rank, iv_mark, io_sc );

        // Start VCM procedure
        o_rc = startVcmPhase1();
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

int32_t CenMbaTdCtlr::handleMCE_VCM2( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleMCE_VCM2] "

    int32_t o_rc = SUCCESS;

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        if ( VCM_PHASE_2 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        io_sc.service_data->SetErrorSig( PRDFSIG_VcmVerified );

        CalloutUtil::calloutMark( mba, iv_rank, iv_mark, io_sc );

        if ( areDramRepairsDisabled() )
        {
            iv_tdState = NO_OP; // The TD procedure is complete.

            io_sc.service_data->SetServiceCall();

            break; // nothing else to do.
        }

        bool startDsdProcedure = false;

        // Read VPD.
        CenDqBitmap bitmap;
        o_rc = getBadDqBitmap( mba, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getBadDqBitmap() failed" );
            break;
        }

        // The chip mark is considered verified, so set it in VPD.
        // NOTE: If this chip mark was placed on the spare, the original failing
        //       DRAM will have already been set in VPD so this will be
        //       redundant but it simplifies the rest of the logic below.
        o_rc = bitmap.setDram( iv_mark.getCM().getSymbol() );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setDram() failed" );
            break;
        }

        // RAS callout policies can be determined by the DIMM type. We can
        // assume IS DIMMs are on low end systems and Centaur DIMMs are on
        // mid/high end systems.
        bool isCenDimm = false;
        o_rc = isMembufOnDimm( mba, isCenDimm );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"isMembufOnDimm() failed" );
            break;
        }

        if ( isCenDimm ) // Medium/high end systems
        {
            uint8_t ps = iv_mark.getCM().getPortSlct();

            // It is possible that a Centaur DIMM does not have spare DRAMs.
            // Check the VPD for available spares. Note that a x4 DIMM may have
            // one or two spare DRAMs so check for availability on both.
            // TODO: RTC 68096 Add support for x4 DRAMs.
            bool dramSparePossible = false;
            o_rc = bitmap.isDramSpareAvailable( ps, dramSparePossible );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"isDramSpareAvailable() failed" );
                break;
            }

            if ( dramSparePossible )
            {
                // Verify the spare is not already used.
                CenSymbol sp0, sp1, ecc;
                // TODO: RTC 68096 need to support ECC spare.
                o_rc = mssGetSteerMux( mba, iv_rank, sp0, sp1, ecc );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC"mssGetSteerMux() failed" );
                    break;
                }

                if ( ((0 == ps) && !sp0.isValid()) ||
                     ((1 == ps) && !sp1.isValid()) )
                {
                    // A spare DRAM is available.
                    startDsdProcedure = true;
                }
                else if ( iv_mark.getCM().getDram() ==
                          (0 == ps ? sp0.getDram() : sp1.getDram()) )
                {
                    io_sc.service_data->SetErrorSig( PRDFSIG_VcmBadSpare );

                    // The chip mark was on the spare DRAM and it is bad, so
                    // call it out and set it in VPD.

                    MemoryMru memmru ( mba, iv_rank, iv_mark.getCM() );
                    memmru.setDramSpared();
                    io_sc.service_data->SetCallout( memmru );
                    io_sc.service_data->SetServiceCall();

                    o_rc = bitmap.setDramSpare( ps );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC"setDramSpare() failed" );
                        break;
                    }
                }
                else
                {
                    // Chip mark and DRAM spare are both used.
                    io_sc.service_data->SetErrorSig( PRDFSIG_VcmMarksUnavail );
                    io_sc.service_data->SetServiceCall();
                }
            }
            else
            {
                // Chip mark is in place and sparing is not possible.
                io_sc.service_data->SetErrorSig( PRDFSIG_VcmMarksUnavail );
                io_sc.service_data->SetServiceCall();
            }
        }
        else // Low end systems
        {
            // Not able to do dram sparing. If there is a symbol mark, there are
            // no repairs available so call it out and set the error log to
            // predictive.
            if ( iv_mark.getSM().isValid() )
            {
                io_sc.service_data->SetErrorSig( PRDFSIG_VcmMarksUnavail );
                io_sc.service_data->SetServiceCall();
            }
        }

        // Write VPD.
        o_rc = setBadDqBitmap( mba, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setBadDqBitmap() failed" );
            break;
        }

        // Start DSD Phase 1, if possible.
        if ( startDsdProcedure )
        {
            io_sc.service_data->SetErrorSig( PRDFSIG_StartDsdPhase1 );

            o_rc = startDsdPhase1();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"startDsdPhase1() failed" );
                break;
            }
        }
        else
        {
            iv_tdState = NO_OP; // The TD procedure is complete.
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleMCE_DSD2( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[CenMbaTdCtlr::handleMCE_DSD2] "

    int32_t o_rc = SUCCESS;

    io_sc.service_data->SetErrorSig( PRDFSIG_DsdBadSpare );
    io_sc.service_data->SetServiceCall();

    TargetHandle_t mba = iv_mbaChip->GetChipHandle();

    do
    {
        if ( DSD_PHASE_2 != iv_tdState )
        {
            PRDF_ERR( PRDF_FUNC"Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Callout mark and spare DRAM.
        CalloutUtil::calloutMark( mba, iv_rank, iv_mark, io_sc );

        MemoryMru memmru ( mba, iv_rank, iv_mark.getCM() );
        memmru.setDramSpared();
        io_sc.service_data->SetCallout( memmru );

        // The spare DRAM is bad, so set it in VPD. At this point, the chip mark
        // should have already been set in the VPD because it was recently
        // verified.

        CenDqBitmap bitmap;
        o_rc = getBadDqBitmap( mba, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getBadDqBitmap() failed" );
            break;
        }

        o_rc = bitmap.setDramSpare( iv_mark.getCM().getPortSlct() );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setDramSpare() failed" );
            break;
        }

        o_rc = setBadDqBitmap( mba, iv_rank, bitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"setBadDqBitmap() failed" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::exitTdSequence()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::exitTdSequence] "

    int32_t o_rc = SUCCESS;

    do
    {
        // Clean up the previous command
        // PRD is not starting another command but MDIA might be so clear the
        // counters and FIRs as well.
        o_rc = prepareNextCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"prepareNextCmd() failed" );
            break;
        }

        // Inform MDIA about command complete
        // Note that we only want to send the command complete message if
        // everything above is successful because a bad return code will result
        // in a SKIP_MBA message sent. There is no need to send redundant
        // messages.
        o_rc = signalMdiaCmdComplete();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"signalMdiaCmdComplete() failed" );
            break;
        }

        // Clear out the mark, just in case. This is so we don't accidentally
        // callout this mark on another rank in an error patch scenario.
        iv_mark = CenMark();

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::prepareNextCmd()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::prepareNextCmd] "

    int32_t o_rc = SUCCESS;

    do
    {
        CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );
        ExtensibleChip * membChip = mbadb->getMembChip();
        if ( NULL == membChip )
        {
            PRDF_ERR( PRDF_FUNC"getMembChip() failed" );
            o_rc = FAIL; break;
        }

        uint32_t mbaPos = getTargetPosition( iv_mbaChip->GetChipHandle() );

        //----------------------------------------------------------------------
        // Clean up previous command
        //----------------------------------------------------------------------

        o_rc = cleanupPrevCmd();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"cleanupPrevCmd() failed" );
            break;
        }

        //----------------------------------------------------------------------
        // Clear ECC counters
        //----------------------------------------------------------------------

        const char * reg_str = ( 0 == mbaPos ) ? "MBA0_MBSTR" : "MBA1_MBSTR";
        SCAN_COMM_REGISTER_CLASS * mbstr = membChip->getRegister( reg_str );
        o_rc = mbstr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on %s", reg_str );
            break;
        }

        mbstr->SetBit(53); // Setting this bit clears all counters.

        o_rc = mbstr->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on %s", reg_str );
            break;
        }

        // Hardware automatically clears bit 53, so flush this register out of
        // the register cache to avoid clearing the counters again with a write
        // from the out-of-date cached copy.
        RegDataCache & cache = RegDataCache::getCachedRegisters();
        cache.flush( membChip, mbstr );

        //----------------------------------------------------------------------
        // Clear ECC FIRs
        //----------------------------------------------------------------------

        reg_str = ( 0 == mbaPos ) ? "MBA0_MBSECCFIR_AND" : "MBA1_MBSECCFIR_AND";
        SCAN_COMM_REGISTER_CLASS * firand = membChip->getRegister( reg_str );
        firand->setAllBits();

        // Clear MPE bit for this rank.
        firand->ClearBit( 20 + iv_rank.getMaster() );

        // Clear NCE, SCE, MCE, RCE, SUE, UE bits (36-41)
        firand->SetBitFieldJustified( 36, 6, 0 );

        o_rc = firand->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on %s", reg_str );
            break;
        }

        SCAN_COMM_REGISTER_CLASS * spaAnd =
                                iv_mbaChip->getRegister("MBASPA_AND");
        spaAnd->setAllBits();

        // clear threshold exceeded attentions
        spaAnd->SetBitFieldJustified( 1, 4, 0 );

        o_rc = spaAnd->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Write() failed on MBASPA_AND" );
            o_rc = FAIL; break;
        }

    } while (0);

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
        o_rc = getMemAddrRange( iv_mbaChip->GetChipHandle(), junk, allEndAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getMemAddrRange() failed" );
            break;
        }

        // Get the address currently in the MBMEA.
        CenAddr curEndAddr;
        o_rc = getCenMaintEndAddr( iv_mbaChip, curEndAddr );
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
                        (allEndAddr == curEndAddr) ? MDIA::COMMAND_COMPLETE
                                                   : MDIA::COMMAND_STOPPED;

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

// Do the setup for mnfg IPL CE
int32_t CenMbaTdCtlr::mnfgCeSetup()
{
    #define PRDF_FUNC "[CenMbaTdCtlr::mnfgCeSetup] "

    int32_t o_rc = SUCCESS;

    do
    {
        CenMbaDataBundle * mbadb = getMbaDataBundle( iv_mbaChip );
        ExtensibleChip * membChip = mbadb->getMembChip();
        if ( NULL == membChip )
        {
            PRDF_ERR( PRDF_FUNC"getMembChip() failed" );
            o_rc = FAIL; break;
        }

        uint32_t mbaPos = getTargetPosition( iv_mbaChip->GetChipHandle() );

        const char * reg_str = ( 0 == mbaPos ) ? "MBA0_MBSTR" : "MBA1_MBSTR";
        SCAN_COMM_REGISTER_CLASS * mbstr = membChip->getRegister( reg_str );
        o_rc = mbstr->Read();
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

