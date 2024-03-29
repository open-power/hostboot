/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep15/host_start_stop_engine.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
 *  @file host_start_stop_engine.C
 *  Contains code for initializing the QME (Quad Management Engine).
 */

//From Hostboot Directory
////Error handling and traces
#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>
#include    <isteps/hwpisteperror.H>
#include    <initservice/isteps_trace.H>
#include    <errl/errluserdetails.H>
#include    <errl/errludtarget.H>

//HWP Invoker
#include    <fapi2/plat_hwp_invoker.H>

////Targeting support
#include    <fapi2/target.H>
#include    <targeting/common/utilFilter.H>

//From Import Directory (EKB Repository)
#include <p10_pm.H>
#include <p10_pm_qme_init.H>
#include <p10_pm_xgpe_init.H>

//Namespaces
using namespace ERRORLOG;
using namespace TARGETING;
using namespace pm;
using namespace fapi2;

namespace ISTEP_15
{
void* host_start_stop_engine (void *io_pArgs)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_start_stop_engine entry" );
    ISTEP_ERROR::IStepError     l_StepError;
    errlHndl_t l_errl = nullptr;

    do {

        //Use targeting code to get a list of all processors
        TargetHandleList l_procChips;
        getAllChips( l_procChips, TYPE_PROC );

        // Start XGPE's on all proc chips
        for (const auto & l_procChip: l_procChips)
        {
            //Convert the Target into a fapi2::Target by passing
            //l_procChip into the fapi2::Target constructor
            fapi2::Target<TARGET_TYPE_PROC_CHIP>l_fapi2CpuTarget(
                                                              (l_procChip));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Calling p10_pm_xgpe_init for 0x%.8X target",
                get_huid(l_procChip) );

            //call p10_pm_xgpe_init HWP
            FAPI_INVOKE_HWP(l_errl,
                            p10_pm_xgpe_init,
                            l_fapi2CpuTarget,
                            PM_START);
            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "host_start_stop_engine:: p10_pm_xgpe_init failed on HUID 0x%08x. "
                        TRACE_ERR_FMT,
                        get_huid(l_procChip),
                        TRACE_ERR_ARGS(l_errl));
                ErrlUserDetailsTarget(l_procChip).addToLog(l_errl);
                l_StepError.addErrorDetails( l_errl );
                errlCommit( l_errl, HWPF_COMP_ID );
            }
        }

        // Start QME's on all proc chips
        for (const auto & l_procChip: l_procChips)
        {
            //Convert the Target into a fapi2::Target by passing
            //l_procChip into the fapi2::Target constructor
            fapi2::Target<TARGET_TYPE_PROC_CHIP>l_fapi2CpuTarget(
                                                              (l_procChip));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Calling p10_pm_qme_init for 0x%.8X target",
                get_huid(l_procChip) );

            //call p10_pm_qme_init.C HWP
            FAPI_INVOKE_HWP(l_errl,
                            p10_pm_qme_init,
                            l_fapi2CpuTarget,
                            PM_START);
            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "host_start_stop_engine:: p10_pm_qme_init failed on HUID 0x%08x. "
                        TRACE_ERR_FMT,
                        get_huid(l_procChip),
                        TRACE_ERR_ARGS(l_errl));
                ErrlUserDetailsTarget(l_procChip).addToLog(l_errl);
                l_StepError.addErrorDetails( l_errl );
                errlCommit( l_errl, HWPF_COMP_ID );
            }
        }

      }while (0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_start_stop_engine exit" );
    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
