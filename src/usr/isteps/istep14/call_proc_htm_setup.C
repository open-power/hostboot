/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_proc_htm_setup.C $                */
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
#include    <p9_htm_setup.H>

//Namespaces
using namespace ERRORLOG;
using namespace TARGETING;
using namespace fapi2;

namespace ISTEP_14
{
void* call_proc_htm_setup (void *io_pArgs)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_htm_setup entry" );
    ISTEP_ERROR::IStepError l_StepError;
    errlHndl_t l_errl = NULL;
    do {
        //Use targeting code to get a list of all processors
        TARGETING::TargetHandleList l_procChips;
        getAllChips( l_procChips, TARGETING::TYPE_PROC   );

        for (const auto & l_procChip: l_procChips)
        {
            const fapi2::Target<TARGET_TYPE_PROC_CHIP>
                l_fapi_cpu_target(l_procChip);
            // call p9_htm_setup.C HWP
             FAPI_INVOKE_HWP( l_errl,
                              p9_htm_setup,
                              l_fapi_cpu_target);

            if(l_errl)
            {
                ErrlUserDetailsTarget(l_procChip).addToLog(l_errl);
                l_StepError.addErrorDetails( l_errl );
                errlCommit( l_errl, HWPF_COMP_ID );
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_htm_setup:: failed on proc with HUID : %d",TARGETING::get_huid(l_procChip)  );
            }
        }
    }while(0);

    // end task, returning any errorlogs to IStepDisp
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_htm_setup exit" );
    return l_StepError.getErrorHandle();
}

};
