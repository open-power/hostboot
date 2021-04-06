/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_proc_fabric_iovalid.C $           */
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
 *  @file call_proc_fabric_iovalid.C
 *
 *  Support file for IStep: proc_fabric_iovalid
 *   Lower functional fences on local SMP
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

// Standard library
#include <stdint.h>
#include <arch/magic.H>

// Trace
#include <trace/interface.H>

// Initservice
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>

// Error log
#include <errl/errlentry.H>
#include <errl/errludtarget.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>

// IStep-related
#include <isteps/hwpisteperror.H>
#include <istepHelperFuncs.H>

// HWAS
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwasCommon.H>

// Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/trace.H>
#include <targeting/common/mfgFlagAccessors.H>

// FAPI
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>

// HWP
#include <p10_fabric_iovalid.H>

namespace ISTEP_09
{

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;
using namespace HWAS;

void* call_proc_fabric_iovalid(void* const io_pArgs)
{
    errlHndl_t l_errl = nullptr;
    IStepError l_StepError;
    std::vector<fapi2::ReturnCode> l_fapiRcs;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_fabric_iovalid entry" );

    // get a list of all the procs in the system
    TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    // Loop through all processors including master
    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target(l_cpu_target);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Running p10_fabric_iovalid HWP on processor target 0x%.8X",
                  get_huid(l_cpu_target));

        if (TARGETING::isSMPWrapConfig())
        {
            const bool l_set_not_clear = true,
                       l_update_internode = true,
                       l_update_intranode = true;

            FAPI_INVOKE_HWP(l_errl, p10_fabric_iovalid,
                            l_fapi2_proc_target,
                            l_set_not_clear,
                            l_update_intranode,
                            l_update_internode,
                            l_fapiRcs);

            if ((l_errl == nullptr) && !l_fapiRcs.empty())
            {
                //if HWP did not return an error, then create a new
                //error to link all the RCs with
                /*@
                 * @errortype  ERRL_SEV_UNRECOVERABLE
                 * @moduleid   MOD_SMP_WRAP_PROC_IOVALID
                 * @reasoncode RC_LINK_TRAIN_ERRORS_FROM_HWP
                 * @userdata0  PROC HUID
                 * @userdata1  Number of RCs from HWP
                 * @devdesc    p10_fabric_iovalid HWP returned errors on odd and
                 *             even links. Creating an error to link all the
                 *             individual link RCs together
                 * @custdesc   There was an error training the SMP cables.
                 */
                l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                       MOD_SMP_WRAP_PROC_IOVALID,
                                       RC_LINK_TRAIN_ERRORS_FROM_HWP,
                                       get_huid(l_cpu_target),
                                       l_fapiRcs.size());
            }

            //Something bad happened during the hwp run
            for (auto l_rc : l_fapiRcs)
            {
                errlHndl_t l_tempErr = rcToErrl(l_rc);
                if (l_tempErr)
                {
                    l_tempErr->plid(l_errl->plid());

                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_cpu_target).addToLog(l_tempErr);

                    // save the error
                    captureError(l_tempErr,
                                 l_StepError,
                                 HWPF_COMP_ID,
                                 l_cpu_target);
                }
            }
        }
        else
        {
            const bool l_set_not_clear = true,
                       l_update_internode = false,
                       l_update_intranode = true;

            // Note:
            // When this HWP gets run under HB, it should only train X PHYS, not As.
            // The HWP shouldn't fill any data into vector l_fapiRcs for X's,
            // only for A's that could be used to trigger a reconfig loop in FSP.
            // Therefore, we ignore the check for l_fapiRcs here.
            FAPI_INVOKE_HWP(l_errl, p10_fabric_iovalid,
                            l_fapi2_proc_target,
                            l_set_not_clear,
                            l_update_intranode,
                            l_update_internode,
                            l_fapiRcs);
        }

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"p10_fabric_iovalid HWP returns error for HUID 0x%.8X"
                      TRACE_ERR_FMT,
                      get_huid(l_cpu_target),
                      TRACE_ERR_ARGS(l_errl));

            //@FIXME-RTC:254475-Remove once this works everywhere
            if( MAGIC_INST_CHECK_FEATURE(MAGIC_FEATURE__IGNORESMPFAIL) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "WORKAROUND> Ignoring error for now - p10_fabric_iovalid" );
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                errlCommit( l_errl, HWPF_COMP_ID );
            }
            else
            {
                captureError(l_errl, l_StepError, HWPF_COMP_ID, l_cpu_target);
            }
        }
    } // end of going through all processors

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_fabric_iovalid exit");

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

} // end namespace
