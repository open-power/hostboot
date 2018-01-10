/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_proc_setup_bars.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <fapi2/target.H>

#include <p9_setup_bars.H>
#include <p9_mss_setup_bars.H>

// TODO: RTC 184860 Remove MCS acker workaround
#include <initservice/initserviceif.H>
#include <p9_revert_sbe_mcs_setup.H>

//HWP Invoker
#include    <fapi2/plat_hwp_invoker.H>

#include   <attribute_ids.H>

using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;

namespace ISTEP_14
{
void* call_proc_setup_bars (void *io_pArgs)
{
    IStepError  l_stepError;

    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_setup_bars entry" );


    // *******************************
    // Start MCS acker workaround
    // TODO: RTC 184860 Remove MCS acker workaround
    // *******************************
    TARGETING::Target * l_masterProc;
    TARGETING::targetService().masterProcChipTargetHandle( l_masterProc );

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "Running p9_revert_sbe_mcs_setup on "
              "target HUID %.8X",
              TARGETING::get_huid(l_masterProc));

    // cast the target to a fapi2 target
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_master_proc( l_masterProc );

    //Invoke p9_revert_sbe_mcs_setup
    // Pass in boolean describing if we are using the FSP or not
    // If we are using the FSP then we will ask off the SBE fir
    // bits on the TP Local Fir register as the FSP with handle
    // SBE errors
    FAPI_INVOKE_HWP( l_errl, p9_revert_sbe_mcs_setup,
                     l_fapi_master_proc,
                     INITSERVICE::spBaseServicesEnabled());

    if (l_errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR 0x%.8X: p9_revert_sbe_mcs_setup",
                  l_errl->reasonCode());
        // Create IStep error log and cross reference error
        l_stepError.addErrorDetails(l_errl);
        // Commit error
        errlCommit(l_errl,SBE_COMP_ID);
    }
    // *******************************
    // End MCS acker workaround
    // *******************************


    // Get all Centaur targets
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC );

    //  --------------------------------------------------------------------
    //  run mss_setup_bars on all CPUs.
    //  --------------------------------------------------------------------
    for (const auto & l_procChip: l_cpuTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi_cpu_target(l_procChip);

        //  write HUID of target
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "p9_mss_setup_bars: proc "
                "target HUID %.8X", TARGETING::get_huid(l_procChip));

        //  call the HWP with all fapi2::Target
         FAPI_INVOKE_HWP(l_errl,
                         p9_mss_setup_bars,
                         l_fapi_cpu_target );
        if ( l_errl )
        {
            // capture the target data in the elog
            ErrlUserDetailsTarget(l_procChip).addToLog( l_errl );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : mss_setup_bars" );
            // break and return with error
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : p9_mss_setup-bars" );
        }
    }   // endfor


    if ( l_stepError.isNull() )
    {
        //----------------------------------------------------------------------
        //  run proc_setup_bars on all CPUs
        //----------------------------------------------------------------------
        for (auto l_procChip : l_cpuTargetList)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "call p9_setup_bars: Target HUID  %.8X",
                       TARGETING::get_huid(l_procChip) );

            // Call the HWP with each fapi::Target
            FAPI_INVOKE_HWP( l_errl, p9_setup_bars, l_procChip );

            if ( l_errl )
            {
                // Capture the target data in the elog
                ErrlUserDetailsTarget(l_procChip).addToLog( l_errl );

                // Create IStep error log and cross reference to error that occurred
                l_stepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : p9_setup_bars" );

                // break and return with error
                break;

            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS : p9_setup_bars" );
            }
        }

    }   // end if !l_errl

    if ( l_errl )
    {

        // Create IStep error log and cross reference to error that occurred
        l_stepError.addErrorDetails( l_errl);

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_setup_bars exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
