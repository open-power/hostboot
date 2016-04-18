/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_proc_mcs_skewadjust.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include    <p9_mem_skewadjust.H>

using namespace ERRORLOG;

namespace ISTEP_13
{
void* call_proc_mcs_skewadjust (void *io_pArgs)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_mcs_skewadjust entry" );
    ISTEP_ERROR::IStepError l_StepError;
    errlHndl_t l_errl = NULL;
    do {
        //Use targeting code to get a list of all proc chiplets
        TARGETING::TargetHandleList l_procChiplets;
        getAllChiplets( l_procChiplets, TARGETING::TYPE_PROC   );

        for (const auto & l_procChiplet: l_procChiplets)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi_proc_target(l_procChiplet);

                // Dump current run on target
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running p9_mem_skewadjust HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_procChiplet));

            // call p9_mem_skewadjust.C HWP
             FAPI_INVOKE_HWP( l_errl,
                              p9_mem_skewadjust,
                              l_fapi_proc_target);

            if(l_errl)
            {
                ErrlUserDetailsTarget(l_procChiplet).addToLog(l_errl);
                l_StepError.addErrorDetails( l_errl );
                errlCommit( l_errl, HWPF_COMP_ID );
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "p9_mem_skewadjust:: failed on mcs with HUID : %d",TARGETING::get_huid(l_procChiplet)  );
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS :  p9_mem_skewadjust HWP( )" );
            }
        }
    }while(0);

    // end task, returning any errorlogs to IStepDisp
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_mcs_skewadjust exit" );
    return l_StepError.getErrorHandle();
}

};
