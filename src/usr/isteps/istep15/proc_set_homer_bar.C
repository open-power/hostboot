/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep15/proc_set_homer_bar.C $                 */
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
/**
 *  @file proc_set_homer_bar.C
 *  Contains code for setting the HOMER BAR registers for OCC and QME
 *  HOMER = Hardware Offload Microcode Engine Region
 */

//From Hostboot Directory
////System
#include    <limits.h>
#include    <sys/misc.h>

////Error handling and traces
#include    <errl/errluserdetails.H>
#include    <errl/errlmanager.H>
#include    <errl/errlentry.H>
#include    <errl/errludtarget.H>
#include    <isteps/hwpisteperror.H>
#include    <initservice/isteps_trace.H>

////Targeting support
#include    <targeting/common/utilFilter.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <fapi2/target.H>

//From Import Directory (EKB Repository)
#include    <return_code.H>
#include    <p10_pm_set_homer_bar.H>

//Namespaces
using namespace ERRORLOG;
using namespace TARGETING;
using namespace fapi2;

namespace ISTEP_15
{
enum : uint64_t
{
    HOMER_SIZE_IN_MB    =4,
};

void* proc_set_homer_bar (void *io_pArgs)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "proc_set_homer_bar entry" );
    ISTEP_ERROR::IStepError l_StepError;
    errlHndl_t l_errl = nullptr;
    TargetHandleList l_procChips;

    //Use targeting code to get a list of all processors
    getAllChips( l_procChips, TYPE_PROC   );

    //Loop through all of the procs and call the HWP on each one
    for (const auto & l_procChip: l_procChips)
    {

        //Convert the Target into a fapi2::Target by passing
        //the const_casted l_procChip into the fapi::Target constructor
        const fapi2::Target<TARGET_TYPE_PROC_CHIP>
            l_fapiCpuTarget((l_procChip));

        const uint64_t homerAddr =
            l_procChip->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>();

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "proc_set_homer_bar: calling p10_pm_set_homer_bar(huid=0x%08x, homerAddr=0x%016llx)",
                get_huid(l_procChip),
                homerAddr);

        //call p10_pm_set_homer_bar.C HWP
        FAPI_INVOKE_HWP( l_errl,
                        p10_pm_set_homer_bar,
                        l_fapiCpuTarget,
                        homerAddr,
                        HOMER_SIZE_IN_MB);
        if(l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "proc_set_homer_bar: p10_pm_set_homer_bar(huid=0x%08x, homerAddr=0x%016llx) FAILED! "
                    TRACE_ERR_FMT,
                    get_huid(l_procChip),
                    homerAddr,
                    TRACE_ERR_ARGS(l_errl));
            l_StepError.addErrorDetails( l_errl );
            errlCommit( l_errl, HWPF_COMP_ID );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "proc_set_homer_bar exit" );
    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
