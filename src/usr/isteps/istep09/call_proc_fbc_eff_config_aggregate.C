/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_proc_fbc_eff_config_aggregate.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
 *  @file call_proc_fbc_eff_config_aggregate.C
 *
 *  Support file for IStep: proc_fbc_eff_config_aggregate
 *   Pick link(s) for coherency
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

// Standard library
#include <stdint.h>

// Trace
#include <trace/interface.H>

// Initservice
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>

// Error logs
#include <errl/errlentry.H>
#include <errl/errludtarget.H>
#include <errl/errlmanager.H>

// IStep-related
#include <isteps/hwpisteperror.H>
#include <istepHelperFuncs.H>

// Targeting
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/trace.H>

// FAPI
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <fapi2/target.H>

// HWP
#include <p10_fbc_eff_config_aggregate.H>

namespace ISTEP_09
{

void* call_proc_fbc_eff_config_aggregate(void* const io_pArgs)
{
    ISTEP_ERROR::IStepError l_stepError;

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_fbc_eff_config_aggregate entry");

    TARGETING::TargetHandleList l_procChips;
    getAllChips(l_procChips, TARGETING::TYPE_PROC);

    for (const auto l_procChip: l_procChips)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapiProc(l_procChip);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Calling p10_fbc_eff_config_aggregate on PROC HUID=0x%08x",
                  get_huid(l_procChip));

        errlHndl_t l_errl = nullptr;
        FAPI_INVOKE_HWP(l_errl, p10_fbc_eff_config_aggregate, l_fapiProc);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"call_proc_fbc_eff_config_aggregate failed on PROC HUID=0x%08x"
                      TRACE_ERR_FMT,
                      get_huid(l_procChip),
                      TRACE_ERR_ARGS(l_errl));

            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_procChip);

            continue; // continue collecting errors to report at the end
        }
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_fbc_eff_config_aggregate exit");

    return l_stepError.getErrorHandle();
}

} // end namespace
