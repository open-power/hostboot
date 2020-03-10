/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_proc_fabric_link_layer.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
 *  @file call_proc_fabric_link_layer.C
 *
 *  Support file for IStep: proc_fabric_link_layer
 *   Start SMP link layer
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

// Targeting
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/trace.H>

// IStep-related
#include <isteps/hwpisteperror.H>
#include <istepHelperFuncs.H>

// Initservice
#include <initservice/isteps_trace.H>
#include <initservice/taskargs.H>

// Error log
#include <errl/errlentry.H>
#include <errl/errludtarget.H>
#include <errl/errlmanager.H>

// FAPI
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>

// HWP
#include <p10_fabric_link_layer.H>

namespace ISTEP_09
{

using namespace ISTEP;
using namespace ISTEPS_TRACE;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;
using namespace HWAS;

void* call_proc_fabric_link_layer(void* const io_pArgs)
{
    IStepError l_stepError;
    TRACFCOMP(g_trac_isteps_trace, "call_proc_fabric_link_layer entry");

    // Get all functional proc chip targets
    TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    for (const auto l_handle : l_cpuTargetList)
    {
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_procChip(l_handle);

        TRACFCOMP(g_trac_isteps_trace,
                  "call_proc_fabric_link_layer: Invoking p10_fabric_link_layer on "
                  "PROC HUID 0x%08x",
                  get_huid(l_handle));

        const bool l_trainInternode = false,
                   l_trainIntranode = true;

        errlHndl_t l_errl = nullptr;
        FAPI_INVOKE_HWP(l_errl,
                        p10_fabric_link_layer,
                        l_procChip,
                        l_trainIntranode,
                        l_trainInternode);

        if (l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      ERR_MRK"call_proc_fabric_link_layer: p10_fabric_link_layer failed on "
                      "PROC HUID 0x%08x"
                      TRACE_ERR_FMT,
                      get_huid(l_handle),
                      TRACE_ERR_ARGS(l_errl));

            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_handle);

            continue; // Continue iterating targets to collect all errors and report
        }
    }

    TRACFCOMP( g_trac_isteps_trace, "call_proc_fabric_link_layer exit" );

    return l_stepError.getErrorHandle();
}

}
