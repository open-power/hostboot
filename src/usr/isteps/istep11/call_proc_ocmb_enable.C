/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep11/call_proc_ocmb_enable.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
 *  @file call_proc_ocmb_enable.C
 *
 *  Support file for IStep: proc_ocmb_enable
 *    Release reset, start clocks to OCMB
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

//  Error handling support
#include <errl/errlentry.H>                 // errlHndl_t
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>              // ErrlUserDetailsTarget
#include <istepHelperFuncs.H>              // captureError

//  Tracing support
#include <initservice/isteps_trace.H>       // g_trac_isteps_trace

// Fapi Support
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <isteps/hwpisteperror.H>           // IStepError

#ifdef CONFIG_PLDM
#include <pldm/requests/pldm_pdr_requests.H>
#endif

//  HWP call support
#include <p10_ocmb_enable.H>

using namespace ISTEPS_TRACE;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_11
{
void* call_proc_ocmb_enable (void *io_pArgs)
{
    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_proc_ocmb_enable");

    errlHndl_t  l_errl = nullptr;
    IStepError l_StepError;

#ifdef CONFIG_PLDM
    PLDM::sendProgressStateChangeEvent(PLDM_STATE_SET_BOOT_PROG_STATE_MEM_INITIALIZATION);
#endif

    TargetHandleList functionalProcChipList;

    getAllChips(functionalProcChipList, TYPE_PROC, true);

    // loop thru the list of processors
    for (TargetHandleList::const_iterator
            l_proc_iter = functionalProcChipList.begin();
            l_proc_iter != functionalProcChipList.end();
            ++l_proc_iter)
    {
        TRACFCOMP(g_trac_isteps_trace,
                    "START : p10_ocmb_enable "
                    "starting on 0x%.08X", get_huid( *l_proc_iter ));

        // Invoke the HWP passing in the proc target
        // HWP loops on child OCMB targets
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                l_fapiProcTarget( *l_proc_iter );
        FAPI_INVOKE_HWP(l_errl,
                        p10_ocmb_enable,
                        l_fapiProcTarget);

        if (l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "ERROR : call_proc_ocmb_enable HWP(): "
                      "p10_ocmb_enable failed on target 0x%08X."
                      TRACE_ERR_FMT,
                      get_huid(*l_proc_iter),
                      TRACE_ERR_ARGS(l_errl));

            // Capture error and continue to next proc
            captureError(l_errl, l_StepError, HWPF_COMP_ID, *l_proc_iter);
        }
        else
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "SUCCESS : p10_ocmb_enable "
                      "completed ok on 0x%.08X",
                      get_huid( *l_proc_iter ));
        }
    }

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_proc_ocmb_enable");
    return l_StepError.getErrorHandle();
}

};
