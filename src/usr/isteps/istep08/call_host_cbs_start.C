/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_cbs_start.C $                */
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
 *  @file call_host_cbs_start.C
 *
 *  Support file for IStep: host_cbs_start
 *   CFAM Boot Sequencer
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include <hbotcompid.H>           // HWPF_COMP_ID
#include <attributeenums.H>       // TYPE_PROC
#include <isteps/hwpisteperror.H> //ISTEP_ERROR:IStepError
#include <istepHelperFuncs.H>     // captureError
#include <fapi2/plat_hwp_invoker.H>
#include <sbeio/sbeioif.H>
#include <spi/spi.H> // for SPI lock support
#include <p10_start_cbs.H>
#include <p10_clock_test.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ISTEPS_TRACE;
using namespace TARGETING;
using namespace SBEIO;

namespace ISTEP_08
{

//******************************************************************************
// call_host_cbs_start()
//******************************************************************************
void* call_host_cbs_start(void *io_pArgs)
{
    IStepError  l_stepError;
    errlHndl_t l_errl = nullptr;

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_host_cbs_start");

    //
    //  get a list of all the procs in the system
    //
    TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    //
    //  Identify the master processor
    //
    Target* l_pMasterProcTarget = nullptr;
    targetService().masterProcChipTargetHandle(l_pMasterProcTarget);

    // loop thru all processors, only call procedure on non-master processors
    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        if (l_cpu_target != l_pMasterProcTarget)
        {
            // Prevent HB SPI operations to this slave processor during SBE boot
            l_errl = SPI::spiLockProcessor(l_cpu_target, true);
            if (l_errl)
            {
                // This would be a firmware bug that would be hard to
                // find later so terminate with this failure
                TRACFCOMP(g_trac_isteps_trace,
                          "ERROR : SPI lock failed to target %.8X"
                          TRACE_ERR_FMT,
                          get_huid(l_cpu_target),
                          TRACE_ERR_ARGS(l_errl));
                captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
                break;
            }

            //Before starting the CBS (and thus the SBE) on slave procs
            //Make sure the SBE FIFO is clean by doing a full reset of
            //the fifo
            l_errl = sendFifoReset(l_cpu_target);
            if (l_errl)
            {
                TRACFCOMP(g_trac_isteps_trace,
                          "ERROR : call sendFifoReset target %.8X"
                          TRACE_ERR_FMT,
                          get_huid(l_cpu_target),
                          TRACE_ERR_ARGS(l_errl));
                captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
                continue; //Don't continue on this chip if failed
            }

            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi2_proc_target (l_cpu_target);

            // Run the clock_test before start_cbs
            // to reduce the window for clock failure
            TRACFCOMP(g_trac_isteps_trace,
                     "Running p10_clock_test HWP on processor target %.8X",
                     get_huid(l_cpu_target));

            FAPI_INVOKE_HWP(l_errl, p10_clock_test, l_fapi2_proc_target);
            if(l_errl)
            {
                TRACFCOMP(g_trac_isteps_trace,
                          "ERROR : call p10_clock_test target %.8X"
                          TRACE_ERR_FMT,
                          get_huid(l_cpu_target),
                          TRACE_ERR_ARGS(l_errl));
                captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
            }

            TRACFCOMP(g_trac_isteps_trace,
                     "Running p10_start_cbs HWP on processor target %.8X",
                     get_huid(l_cpu_target));

            FAPI_INVOKE_HWP(l_errl, p10_start_cbs, l_fapi2_proc_target, true);
            if(l_errl)
            {
                TRACFCOMP(g_trac_isteps_trace,
                          "ERROR : call p10_start_cbs target %.8X"
                          TRACE_ERR_FMT,
                          get_huid(l_cpu_target),
                          TRACE_ERR_ARGS(l_errl));
                captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
            }
        }
    }

    // For recovery, attempt to unlock all slave processor SPI engines
    if (l_stepError.getErrorHandle() != nullptr)
    {
        // loop thru all processors, only call procedure on non-master processors
        for (const auto & l_cpu_target: l_cpuTargetList)
        {
            if (l_cpu_target != l_pMasterProcTarget)
            {
                // Allow SPI operations again, as this step is failing
                l_errl = SPI::spiLockProcessor(l_cpu_target, false);
                if (l_errl)
                {
                    // unlock should never fail unless coding issue
                    // since this is just a recovery attempt, delete error
                    delete l_errl;
                    l_errl = nullptr;
                }
            }
        }
    }

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_host_cbs_start");
    return l_stepError.getErrorHandle();
}
};
