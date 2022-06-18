/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep15/host_establish_ec_chiplet.C $          */
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
/**
 *  @file host_establish_ec_chiplet.C
 *  Contains code for updating multicast on ECs for runtime state
 */

//From Hostboot Directory
////Error handling and traces
#include    <errl/errlentry.H>
#include    <errl/errluserdetails.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>
#include    <isteps/hwpisteperror.H>
#include    <initservice/isteps_trace.H>

//HWP Invoker
#include    <fapi2/plat_hwp_invoker.H>

//Targeting Support
#include    <targeting/common/utilFilter.H>
#include    <fapi2/target.H>

//From Import Directory (EKB Repository)
#include    <p10_update_ec_state.H>

#include <sbeio/sbeioif.H>

//Namespaces
using namespace ERRORLOG;
using namespace TARGETING;
using namespace fapi2;

namespace ISTEP_15
{
void* host_establish_ec_chiplet (void *io_pArgs)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_establish_ec_chiplet entry" );
    ISTEP_ERROR::IStepError l_StepError;
    errlHndl_t l_errl = nullptr;
    do {
        //Use targeting code to get a list of all processors
        TargetHandleList l_procChips;
        getAllChips( l_procChips, TYPE_PROC   );

        for (const auto & l_procChip: l_procChips)
        {
            // ALWAYS send the core config to master and secondary SBEs
            l_errl = SBEIO::psuSendSbeCoreConfig(l_procChip);
            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "host_establish_ec_chiplet: psuSendSbeCoreConfig failed on HUID 0x%08X. "
                          TRACE_ERR_FMT,
                          get_huid(l_procChip),
                          TRACE_ERR_ARGS(l_errl));
                ErrlUserDetailsTarget(l_procChip).addToLog(l_errl);
                // Commit the error and FAIL this ISTEP
                l_StepError.addErrorDetails( l_errl );
                errlCommit( l_errl, HWPF_COMP_ID );
                break;
            }
            else
            {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "host_establish_ec_chiplet: psuSendSbeCoreConfig SUCCESS (possible UNSUPPORTED SBE COMMAND) on HUID 0x%08X. ",
                          get_huid(l_procChip));
            }

            const fapi2::Target<TARGET_TYPE_PROC_CHIP>
                l_fapi_cpu_target(l_procChip);

            // call p10_update_ec_state.C HWP
            FAPI_INVOKE_HWP( l_errl,
                             p10_update_ec_state,
                             l_fapi_cpu_target);
            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "host_establish_ec_chiplet: p10_update_ec_state failed on HUID 0x%08X. "
                          TRACE_ERR_FMT,
                          get_huid(l_procChip),
                          TRACE_ERR_ARGS(l_errl));
                ErrlUserDetailsTarget(l_procChip).addToLog(l_errl);
                l_StepError.addErrorDetails( l_errl );
                errlCommit( l_errl, HWPF_COMP_ID );
            }
        }
    }while(0);

    // end task, returning any errorlogs to IStepDisp
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_establish_ec_chiplet exit" );
    return l_StepError.getErrorHandle();
}
};
