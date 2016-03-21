/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep15/host_start_stop_engine.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include <p9_pm.H>
#include <p9_pm_stop_gpe_init.H>

//Namespaces
using namespace ERRORLOG;
using namespace TARGETING;
using namespace p9pm;
using namespace fapi2;

namespace ISTEP_15
{
void* host_start_stop_engine (void *io_pArgs)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_start_stop_engine entry" );
    ISTEP_ERROR::IStepError     l_StepError;
    errlHndl_t l_errl = NULL;

    do {
        //Use targeting code to get a list of all processors
        TARGETING::TargetHandleList l_procChips;
        getAllChips( l_procChips, TARGETING::TYPE_PROC   );

        for (const auto & l_procChip: l_procChips)
        {
            //Convert the TARGETING::Target into a fapi2::Target by passing
            //l_procChip into the fapi2::Target constructor
            fapi2::Target<TARGET_TYPE_PROC_CHIP>l_fapi2CpuTarget(
                                                              (l_procChip));

            //call p9_pm_stop_gpe_init.C HWP
            FAPI_INVOKE_HWP(l_errl,
                            p9_pm_stop_gpe_init,
                            l_fapi2CpuTarget,
                            PM_INIT);
            if(l_errl)
            {
                ErrlUserDetailsTarget(l_procChip).addToLog(l_errl);
                l_StepError.addErrorDetails( l_errl );
                errlCommit( l_errl, HWPF_COMP_ID );
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_start_stop_engine:: failed on proc with HUID : %d",TARGETING::get_huid(l_procChip)  );
            }
        }
      }while (0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_start_stop_engine exit" );
    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
