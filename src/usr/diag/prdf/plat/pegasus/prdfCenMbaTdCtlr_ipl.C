/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfCenMbaTdCtlr_ipl.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2018                        */
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
#include <prdfMemConst.H>
#include <prdfCenDqBitmap.H>
#include <prdfCenMbaDataBundle.H>
#include <prdfCenSymbol.H>

// Custom compile configs
#include <config.h>

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
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Moved to MemTdCtlr class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc,
                                     const CenRank & i_rank,
                                     const CenMbaTdCtlrCommon::TdType i_event,
                                     bool i_banTps )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Moved to MemTdCtlr class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startInitialBgScrub()
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Moved to startBgScrub() in prdfPlatServices.C
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------
//                            Private Functions
//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::initialize()
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Moved to MemTdCtlr class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::analyzeCmdComplete( STEP_CODE_DATA_STRUCT & io_sc,
                                          const CenAddr & i_stopAddr,
                                          const CenAddr & i_endAddr )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Moved to MemTdCtlr class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::analyzeVcmPhase1( STEP_CODE_DATA_STRUCT & io_sc,
                                        const CenAddr & i_stopAddr,
                                        const CenAddr & i_endAddr )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // moved to VcmEvent class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::analyzeVcmPhase2( STEP_CODE_DATA_STRUCT & io_sc,
                                        const CenAddr & i_stopAddr,
                                        const CenAddr & i_endAddr )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // moved to VcmEvent class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
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

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc)
        {
            PRDF_ERR( PRDF_FUNC "checkEccErrors() failed" );
            break;
        }

        if ( ( eccErrorMask & UE) || ( eccErrorMask & RETRY_CTE ) )
        {
            // Handle UE. Highest priority
            o_rc = handleUE( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleUE() failed" );
                break;
            }
        }
        else
        {
            // Start DSD Phase 2
            o_rc = startDsdPhase2( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startDsdPhase2() failed" );
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
            PRDF_ERR( PRDF_FUNC "Invalid state machine configuration" );
            o_rc = FAIL; break;
        }

        // Add the mark to the callout list.
        CalloutUtil::calloutMark( iv_mbaTrgt, iv_rank, iv_mark, io_sc );

        // Get error condition which caused command to stop
        uint16_t eccErrorMask = NO_ERROR;
        o_rc = checkEccErrors( eccErrorMask, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccErrors() failed" );
            break;
        }

        if ( eccErrorMask & UE)
        {
            // Handle UE. Highest priority
            o_rc = handleUE( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleUE() failed" );
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
                PRDF_ERR( PRDF_FUNC "handleMCE_DSD2() failed" );
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
                PRDF_ERR( PRDF_FUNC "mssSetMarkStore() failed" );
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
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Moved to TpsEvent class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::analyzeTpsPhase2( STEP_CODE_DATA_STRUCT & io_sc,
                                        const CenAddr & i_stopAddr,
                                        const CenAddr & i_endAddr )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Moved to TpsEvent class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startVcmPhase1( STEP_CODE_DATA_STRUCT & io_sc )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // moved to VcmEvent class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startVcmPhase2( STEP_CODE_DATA_STRUCT & io_sc )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // moved to VcmEvent class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startDsdPhase1( STEP_CODE_DATA_STRUCT & io_sc )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Moved to DsdEvent class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startDsdPhase2( STEP_CODE_DATA_STRUCT & io_sc )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Moved to DsdEvent class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startTpsPhase1( STEP_CODE_DATA_STRUCT & io_sc )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Moved to TpsEvent class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::startTpsPhase2( STEP_CODE_DATA_STRUCT & io_sc )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Moved to TpsEvent class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleUE( STEP_CODE_DATA_STRUCT & io_sc )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // moved to MemEcc::handleMemUe()
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleMPE( STEP_CODE_DATA_STRUCT & io_sc )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // moved to MemEcc::handleMpe()
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::handleMnfgCeEte( STEP_CODE_DATA_STRUCT & io_sc )
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Moved to TpsEvent class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

//------------------------------------------------------------------------------

int32_t CenMbaTdCtlr::signalMdiaCmdComplete()
{
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Moved to MemTdCtlr class
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    return SUCCESS;
}

} // end namespace PRDF

