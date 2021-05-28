/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep11/call_ocmb_check_for_ready.C $          */
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
 *  @file call_ocmb_check_for_ready.C
 *
 *  Support file for IStep: ocmb_check_for_ready
 *    Check that OCMB is ready
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

//  Error handling support
#include <errl/errlentry.H>                     // errlHndl_t
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>                  // ErrlUserDetailsTarget
#include <istepHelperFuncs.H>                   // captureError

//  FAPI support
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <isteps/hwpisteperror.H>               // IStepError

//  Tracing support
#include <initservice/isteps_trace.H>           // g_trac_isteps_trace

//  Targeting support
#include <attributeenums.H>                     // TYPE_PROC
#include <targeting/common/utilFilter.H>        // getAllChips
#include <sbeio/sbeioif.H>
#include <util/misc.H>
#include <sys/time.h>
#include <time.h>

//  HWP call support
#include <exp_check_for_ready.H>

// Explorer error logs
#include <expscom/expscom_errlog.H>

using namespace ISTEPS_TRACE;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_11
{
void* call_ocmb_check_for_ready (void *io_pArgs)
{
    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_ocmb_check_for_ready");

    errlHndl_t  l_errl = nullptr;
    IStepError l_StepError;

    TargetHandleList functionalProcChipList;

    getAllChips(functionalProcChipList, TYPE_PROC, true);

    // loop thru the list of processors
    for (TargetHandleList::const_iterator
            l_proc_iter = functionalProcChipList.begin();
            l_proc_iter != functionalProcChipList.end();
            ++l_proc_iter)
    {
        // For each loop on an OCMB below, multiply the timeout chunk
        size_t loop_multiplier = 1;

        // Keep track of overall time
        size_t l_maxTime_secs = 0;
        timespec_t l_preLoopTime = {};
        timespec_t l_ocmbCurrentTime = {};
        clock_gettime(CLOCK_MONOTONIC, &l_preLoopTime);

        TargetHandleList l_functionalOcmbChipList;
        getChildAffinityTargets( l_functionalOcmbChipList,
                                 const_cast<Target*>(*l_proc_iter),
                                 CLASS_CHIP,
                                 TYPE_OCMB_CHIP,
                                 true);

        for (const auto & l_ocmb : l_functionalOcmbChipList)
        {
            TRACFCOMP(g_trac_isteps_trace,
                        "Start : exp_check_for_ready "
                        "for 0x%.08X", get_huid(l_ocmb));

            fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP>
                                    l_fapi_ocmb_target(l_ocmb);

            // Save the original timeout (to be restored after exp_check_for_ready)
            // Units for the attribute are milliseconds; the value returned is > 1 second
            const auto original_timeout_ms
                = l_ocmb->getAttr<ATTR_MSS_CHECK_FOR_READY_TIMEOUT>();

            // Calculate MAX Wait Time - Round up on seconds
            // - ATTR_MSS_CHECK_FOR_READY_TIMEOUT in msec (see exp_attributes.xml)
            // - This assumes that all of the OCMBs on a processor were started at the same time
            //   and that they all have the same original_timeout value
            // - The calculation is as follows:
            // 1) Start with the 'seconds' value of the pre-loop time
            // 2) Add *double* the 'seconds' amount of the original timeout value
            //    -- the *double* is just to be on the safe side, as we're only dealing with
            //       seconds and not minutes here
            // 3) Add 3 to round up for the nanoseconds of (1) and double the milliseconds of (2)
            if (l_maxTime_secs == 0)
            {
                // If not set yet, then set it here:
                l_maxTime_secs = l_preLoopTime.tv_sec
                                 + (2 * (original_timeout_ms / MS_PER_SEC))
                                 + 3;
            }

            // exp_check_for_ready will read this attribute to know how long to
            // poll. If this number is too large and we get too many I2C error
            // logs between calls to FAPI_INVOKE_HWP, we will run out of memory.
            // So break the original timeout into smaller timeouts.
            // This will not affect how the loop below will use l_maxTime_secs to look for a timouts
            const ATTR_MSS_CHECK_FOR_READY_TIMEOUT_type smaller_timeout_ms = 10 * loop_multiplier++;
            l_ocmb->setAttr<ATTR_MSS_CHECK_FOR_READY_TIMEOUT>(smaller_timeout_ms);

            TRACFCOMP(g_trac_isteps_trace,"exp_check_for_ready: For OCMB 0x%X: "
                      "original_timeout_ms = %d, smaller_timeout_ms = %d, "
                      "l_preLoopTime.tv_sec = %lu l_maxTime_secs = %lu",
                      get_huid(l_ocmb), original_timeout_ms, smaller_timeout_ms,
                      l_preLoopTime.tv_sec, l_maxTime_secs);

            // Variable used to track attempting one more time after max time has
            // been succeeded
            bool l_one_more_try = false;

            // Retry exp_check_for_ready as many times as it takes to either
            // succeed or time out
            while (true)
            {
                // Delete the log from the previous iteration
                if( l_errl )
                {
                    delete l_errl;
                    l_errl = nullptr;
                }

                FAPI_INVOKE_HWP(l_errl,
                                exp_check_for_ready,
                                l_fapi_ocmb_target);

                // On success, quit retrying.
                if (!l_errl)
                {
                    break;
                }

                clock_gettime(CLOCK_MONOTONIC, &l_ocmbCurrentTime);
                if (l_ocmbCurrentTime.tv_sec > l_maxTime_secs)
                {
                    if (l_one_more_try == false)
                    {
                        // Do one more attempt just to be safe
                        l_one_more_try = true;
                        TRACFCOMP(g_trac_isteps_trace,"exp_check_for_ready "
                                  "Setting 'one more try' (%d) based on times: "
                                  "l_ocmbCurrentTime.tv_sec = %lu, l_maxTime_secs = %lu",
                                  l_one_more_try, l_ocmbCurrentTime.tv_sec, l_maxTime_secs);

                    }
                    else
                    {
                        // Already done "one more try" so just break
                        TRACFCOMP(g_trac_isteps_trace,"exp_check_for_ready "
                                  "Breaking as 'one more try' (%d) was already set. "
                                  "l_ocmbCurrentTime.tv_sec = %lu, l_maxTime_secs = %lu",
                                  l_one_more_try, l_ocmbCurrentTime.tv_sec, l_maxTime_secs);
                        break;
                    }
                }

            } // end of timeout loop

            // Restore original timeout value
            l_ocmb->setAttr<ATTR_MSS_CHECK_FOR_READY_TIMEOUT>(original_timeout_ms);

            if (l_errl)
            {
                TRACFCOMP(g_trac_isteps_trace,
                          "ERROR : call_ocmb_check_for_ready HWP(): "
                          "exp_check_for_ready failed on target 0x%08X."
                          TRACE_ERR_FMT,
                          get_huid(l_ocmb),
                          TRACE_ERR_ARGS(l_errl));

                // Capture error and continue to next OCMB
                captureError(l_errl, l_StepError, HWPF_COMP_ID, l_ocmb);
            }
            else
            {
                TRACFCOMP(g_trac_isteps_trace,
                          "SUCCESS : exp_check_for_ready "
                          "completed ok");

                size_t size = 0;

                TRACFCOMP(g_trac_isteps_trace,
                          "Read IDEC from OCMB 0x%.8X",
                          get_huid(l_ocmb));

                // This write gets translated into a read of the explorer chip
                // in the device driver. First, a read of the chip's IDEC
                // register occurs then ATTR_EC, ATTR_HDAT_EC, and ATTR_CHIP_ID
                // are set with the values found in that register. So, this
                // deviceWrite functions more as a setter for an OCMB target's
                // attributes.
                // Pass 2 as a va_arg to signal the ocmbIDEC function to execute
                // phase 2 of its read process.
                const uint64_t Phase2 = 2;
                l_errl = DeviceFW::deviceWrite(l_ocmb,
                                   nullptr,
                                   size,
                                   DEVICE_IDEC_ADDRESS(),
                                   Phase2);
                if (l_errl)
                {
                    // read of ID/EC failed even though we THOUGHT we were
                    // present.
                    TRACFCOMP(g_trac_isteps_trace,
                              "ERROR : call_ocmb_check_for_ready HWP(): "
                              "read IDEC failed on target 0x%08X (eid 0x%X)."
                              TRACE_ERR_FMT,
                              get_huid(l_ocmb),
                              l_errl->eid(),
                              TRACE_ERR_ARGS(l_errl));

                    // Capture error and continue to next OCMB
                    captureError(l_errl, l_StepError, HWPF_COMP_ID, l_ocmb);
                }
            } // End of if/else l_errl

        } // End of OCMB Loop

        // Grab informational Explorer logs (early IPL = true)
        EXPSCOM::createExplorerLogs(l_functionalOcmbChipList, true);
    }

    // Loop thru the list of processors and send Memory config info to SBE
    for (auto &l_procTarget: functionalProcChipList)
    {
        l_errl = SBEIO::psuSendSbeMemConfig(l_procTarget);

        if (l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      ERR_MRK"ERROR : call_ocmb_check_for_ready HWP(): "
                      "psuSendSbeMemConfig failed for target 0x%.08X."
                      TRACE_ERR_FMT,
                      get_huid(l_procTarget),
                      TRACE_ERR_ARGS(l_errl));

            // Commit the error and not fail this istep due to this failure
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP(g_trac_isteps_trace,
                      INFO_MRK"SUCCESS : call_ocmb_check_for_ready HWP(): "
                      "psuSendSbeMemConfig completed ok for target 0x%.08X.",
                      get_huid(l_procTarget));
        }
    } // for (auto &l_procTarget: functionalProcChipList)

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_ocmb_check_for_ready");
    return l_StepError.getErrorHandle();
}

};
