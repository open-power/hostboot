/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_mss_scrub.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scrub entry" );

    errlHndl_t errl = nullptr;

    do
    {
        if ( Util::isSimicsRunning() )
        {
            // There are performance issues and some functional deficiencies
            // that make background scrub problematic in SIMICs.
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Skipping background "
                       "scrub in SIMICs" );
        }
        else
        {
            // Start background scrubbing.
            errl = PRDF::startScrub();
            if ( nullptr != errl )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "PRDF::startScrub() failed" );
                break;
            }
        }

        // Nimbus chips require us to unmask some additional FIR bits. Note that
        // this is not needed on Cumulus based systems because this is already
        // contained within the other Centaur HWPs.
        TargetHandle_t masterProc = nullptr;
        targetService().masterProcChipTargetHandle(masterProc);
        if ( MODEL_NIMBUS == masterProc->getAttr<ATTR_MODEL>() )
        {
            TargetHandleList trgtList; getAllChiplets( trgtList, TYPE_MCBIST );

            for ( auto & tt : trgtList )
            {
                fapi2::Target<fapi2::TARGET_TYPE_MCBIST> ft ( tt );

                FAPI_INVOKE_HWP( errl, mss::unmask::after_background_scrub, ft);
                if ( nullptr != errl )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "mss::unmask::after_background_scrub(0x%08x) "
                               "failed", get_huid(tt) );
                    break;
                }
            }
            if ( nullptr != errl ) break;
        }

    } while (0);

    if ( nullptr != errl )
    {
        l_stepError.addErrorDetails( errl );
        errlCommit( errl, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scrub exit" );
    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
