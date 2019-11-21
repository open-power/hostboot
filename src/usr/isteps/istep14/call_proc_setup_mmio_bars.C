/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_proc_setup_mmio_bars.C $          */
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
 *  @file  call_proc_setup_mmio_bars.C
 *  @brief Contains the wrapper for istep 14.5
 */
#include <errl/errlentry.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <secureboot/service.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <fapi2/target.H>

#include <fapi2/plat_hwp_invoker.H>
#include <attribute_ids.H>

#include <initservice/initserviceif.H>

#include <p10_setup_mmio_bars.H>

using namespace ISTEP_ERROR;
using namespace ERRORLOG;

namespace ISTEP_14
{

void* call_proc_setup_mmio_bars (void *io_pArgs)
{
    IStepError  l_stepError;
    errlHndl_t  l_errl = nullptr;

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_setup_mmio_bars entry");

    // Get all processor targets
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

    //----------------------------------------------------------------------
    //  run proc_setup_mmio_bars on all CPUs
    //----------------------------------------------------------------------
    for (auto l_procChip : l_cpuTargetList)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "call p10_setup_mmio_bars: Target HUID  %.8X",
                  TARGETING::get_huid(l_procChip));

        fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProcChip(l_procChip);

        // Call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_errl, p10_setup_mmio_bars, l_fapiProcChip);

        if (l_errl)
        {
            // Capture the target data in the elog
            ErrlUserDetailsTarget(l_procChip).addToLog(l_errl);

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails(l_errl);

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR: p10_setup_mmio_bars (chip HUID 0x%08x): "
                      TRACE_ERR_FMT,
                      get_huid(l_procChip),
                      TRACE_ERR_ARGS(l_errl));

            l_errl->collectTrace("ISTEPS_TRACE");

            // Commit Error
            errlCommit(l_errl, HWPF_COMP_ID);

            // break and return with error
            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS: p10_setup_mmio_bars (chip HUID 0x%08X)",
                      TARGETING::get_huid(l_procChip));
        }
    }

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_setup_mmio_bars exit");

    // end task, returning any error logs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
