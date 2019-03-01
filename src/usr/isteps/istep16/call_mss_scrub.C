/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_mss_scrub.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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

#include    <errl/errlentry.H>
#include    <initservice/isteps_trace.H>
#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>
#include    <util/misc.H>
#include    <diag/prdf/prdfMain.H>

#include <plat_hwp_invoker.H>     // for FAPI_INVOKE_HWP
#include <lib/fir/memdiags_fir.H> // for mss::unmask::after_background_scrub

using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;

namespace ISTEP_16
{
void* call_mss_scrub (void *io_pArgs)
{
    #define ISTEP_FUNC "call_mss_scrub: "

    IStepError l_stepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ISTEP_FUNC "entry" );

    errlHndl_t errl = nullptr;

    do
    {
        if ( Util::isSimicsRunning() )
        {
            // There are performance issues and some functional deficiencies
            // that make background scrub problematic in SIMICs.
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ISTEP_FUNC
                       "Background scrubbing not supported in SIMICs" );
            break;
        }

        TargetHandle_t sysTrgt = nullptr;
        targetService().getTopLevelTarget( sysTrgt );

        TargetHandle_t masterProc = nullptr;
        targetService().masterProcChipTargetHandle( masterProc );

        // Determine which target type runs the maintenance commands.
        TARGETING::MODEL masterProcModel = masterProc->getAttr<ATTR_MODEL>();
        TARGETING::TYPE maintTrgtType;
        switch ( masterProcModel )
        {
            case MODEL_CUMULUS: maintTrgtType = TYPE_MBA;       break;
            case MODEL_NIMBUS:  maintTrgtType = TYPE_MCBIST;    break;
            default:
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ISTEP_FUNC
                           "Master PROC model %d not supported",
                           masterProcModel );
                /*@
                * @errortype
                * @moduleid     ISTEP::MOD_MSS_SCRUB
                * @reasoncode   ISTEP::RC_INVALID_TARGET_TYPE
                * @userdata1    Master processor model
                * @userdata2    unused
                * @devdesc      The master processor model is unsupported.
                * @custdesc     A problem occurred during the IPL of the system.
                */
                errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ISTEP::MOD_MSS_SCRUB,
                                    ISTEP::RC_INVALID_TARGET_TYPE,
                                    masterProcModel, 0,
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
        }
        if ( nullptr != errl ) break;

        // Start background scrubbing on all targets of this maintenance type.
        TargetHandleList maintList; getAllChiplets( maintList, maintTrgtType );
        for ( auto & maintTrgt : maintList )
        {
            bool start = true; // initially true except for MP-IPL conditions.

#ifdef CONFIG_NVDIMM
            // During MP-IPLs, We only want to start background scrubbing on
            // maintenance targets that have connected NVDIMMs.
            if ( sysTrgt->getAttr<ATTR_IS_MPIPL_HB>() )
            {
                start = false; // Only true if there is an NVDIMM.

                // Find at least one DIMM behind this MCBIST that is an NVDIMM.
                TargetHandleList dimmList;
                getChildAffinityTargets( dimmList, maintTrgt, CLASS_NA,
                                         TYPE_DIMM );
                for ( auto & dimmTrgt : dimmList )
                {
                    start = isNVDIMM(dimmTrgt);
                    if ( start ) break;
                }
            }
#endif
            // Continue to the next target if we are unable to start background
            // scrubbing on this target.
            if ( !start ) continue;

            // Start the command on this target.
            errl = PRDF::startScrub( maintTrgt );
            if ( nullptr != errl )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ISTEP_FUNC
                           "PRDF::startScrub(0x%08x) failed",
                           get_huid(maintTrgt) );
                break;
            }

            // Nimbus chips require us to unmask some additional FIR bits. Note
            // that this is not needed on Cumulus based systems because this is
            // already contained within the other Centaur HWPs.
            if ( TYPE_MCBIST == maintTrgtType )
            {
                fapi2::Target<fapi2::TARGET_TYPE_MCBIST> ft ( maintTrgt );

                FAPI_INVOKE_HWP( errl, mss::unmask::after_background_scrub, ft);
                if ( nullptr != errl )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ISTEP_FUNC
                               "mss::unmask::after_background_scrub(0x%08x) "
                               "failed", get_huid(maintTrgt) );
                    break;
                }
            }
        }
        if ( nullptr != errl ) break;

    } while (0);

    if ( nullptr != errl )
    {
        l_stepError.addErrorDetails( errl );
        errl->collectTrace( "ISTEPS_TRACE", 256 );
        errlCommit( errl, HWPF_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ISTEP_FUNC "exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();

    #undef ISTEP_FUNC
}

};
