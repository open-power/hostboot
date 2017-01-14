/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_mss_thermal_init.C $              */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>

#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>

#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <p9_mss_thermal_init.H>
#include    <p9_throttle_sync.H>


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

namespace ISTEP_14
{
void* call_mss_thermal_init (void *io_pArgs)
{
    IStepError  l_StepError;
    errlHndl_t  l_errl  =   nullptr;
//@TODO RTC:144076 L1 HWPs for Centaur+Cumulus
#if 0
    // -- Cumulus only ---
        // Get all Centaur targets
        TARGETING::TargetHandleList l_memBufTargetList;
        getAllChiplets(l_memBufTargetList, TYPE_MCBIST );

        //  --------------------------------------------------------------------
        //  run mss_thermal_init on all Centaurs
        //  --------------------------------------------------------------------
        for (TargetHandleList::const_iterator
                l_iter = l_memBufTargetList.begin();
                l_iter != l_memBufTargetList.end();
                ++l_iter)
        {
            //  make a local copy of the target for ease of use
            TARGETING::Target*  l_pCentaur = *l_iter;

            //  write HUID of target
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

            fapi2::Target<fapi2::TARGET_TYPE_MCBIST> l_fapi_pCentaur
                (l_pCentaur);

            // Current run on target
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running call_mss_thermal_init HWP on "
                    "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

            FAPI_INVOKE_HWP( l_errl, p9_mss_thermal_init, l_fapi_pCentaur );

            if ( l_errl )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X: mss_thermal_init HWP returns error",
                        l_errl->reasonCode());

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_pCentaur).addToLog( l_errl );

                // Create IStep error log and cross reference
                // to error that occurred
                l_StepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );

                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS : mss_thermal_init HWP( )" );
            }
        }
        if (l_errl)
        {
            break;
        }
        #endif
    do
    {
        // Run proc throttle sync
        // Get all functional proc chip targets
        //Use targeting code to get a list of all processors
        TARGETING::TargetHandleList l_procChips;
        getAllChips( l_procChips, TARGETING::TYPE_PROC   );

        for (const auto & l_procChip: l_procChips)
        {
            //Convert the TARGETING::Target into a fapi2::Target by passing
            //l_procChip into the fapi2::Target constructor
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapi2CpuTarget((l_procChip));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Running p9_throttle_sync HWP on "
                   "target HUID %.8X", TARGETING::get_huid(l_procChip));

            // Call p9_throttle_sync
            FAPI_INVOKE_HWP( l_errl, p9_throttle_sync, l_fapi2CpuTarget );

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: p9_throttle_sync HWP returns error",
                          l_errl->reasonCode());

                // Capture the target data in the elog
                ErrlUserDetailsTarget(l_procChip).addToLog(l_errl);

                // Create IStep error log and cross reference
                //  to error that occurred
                l_StepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );

                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  p9_throttle_sync HWP( )" );
            }
        }

    } while (0);


    if(l_StepError.isNull())
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : call_mss_thermal_init" );
    }


    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
