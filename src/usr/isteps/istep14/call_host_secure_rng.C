/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_host_secure_rng.C $               */
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
 * @file call_host_secure_rng.C
 *
 *  Support file for IStep: core_activate
 *   Core Activate
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include <stdint.h>

#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>

#include <isteps/hwpisteperror.H>
#include <errl/errludtarget.H>
#include <errl/errlreasoncodes.H>

#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>

//  MVPD
#include <devicefw/userif.H>
#include <vpd/mvpdenums.H>

#include <fapi2/plat_hwp_invoker.H>
#include <p10_rng_init_phase2.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_14
{

//******************************************************************************
// wrapper function to call host_secure_rng
//******************************************************************************
void* call_host_secure_rng(void* const io_pArgs)
{

    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_secure_rng entry" );

    errlHndl_t l_err = nullptr;

    //  get a list of all the procs in the system
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    // Loop through all processors including master
    for (const auto& l_cpu_target : l_cpuTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target(l_cpu_target);

        // Check for functional NX
        TARGETING::TargetHandleList l_nxTargetList;
        getChildChiplets(l_nxTargetList, l_cpu_target, TYPE_NX, true);

        if (l_nxTargetList.empty())
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Running host_secure_rng; no functional NX "
                      "found for proc %.8X",
                      TARGETING::get_huid(l_cpu_target));
            continue;
        }

        FAPI_INVOKE_HWP(l_err, p10_rng_init_phase2, l_fapi2_proc_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR: call p10_rng_init_phase2, PLID=0x%x, rc=0x%.4X: "
                      TRACE_ERR_FMT,
                      l_err->plid(), l_err->reasonCode(),
                      TRACE_ERR_ARGS(l_err));

            for (const auto l_callout
                     : l_err->getUDSections(HWPF_COMP_ID,
                                            ERRORLOG::ERRL_UDT_CALLOUT))
            {
                if (reinterpret_cast<HWAS::callout_ud_t*>(l_callout)->type
                    == HWAS::HW_CALLOUT)
                {
                    for (const auto& l_nxTarget : l_nxTargetList)
                    {
                        l_err->addHwCallout(l_nxTarget,
                                            HWAS::SRCI_PRIORITY_HIGH,
                                            HWAS::DECONFIG,
                                            HWAS::GARD_NULL);
                    }
                 }
            }

            l_StepError.addErrorDetails(l_err);
            errlCommit(l_err, HWPF_COMP_ID);
        }
    } // end of going through all processors

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_host_secure_rng exit");

    return l_StepError.getErrorHandle();
} // end call_host_secure_rng

} // end namespace ISTEP_14
