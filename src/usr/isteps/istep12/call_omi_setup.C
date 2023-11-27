/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_setup.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2024                        */
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
 * @file    call_omi_setup.C
 *
 *  Contains the wrapper for Istep 12.6
 *      exp_omi_setup
 *      p10_omi_setup
 */

#include    <stdint.h>
#include    <sys/time.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <util/threadpool.H>
#include    <sys/task.h>
#include    <initservice/istepdispatcherif.H>
#include    <hwpThread.H>
#include    <hwpThreadHelper.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <targeting/targplatutil.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>          // captureError

#include    <ocmbupd/ocmbupd.H> // i2c update check

// Fapi Support
#include    <config.h>

// HWP
#include    <exp_omi_setup.H>
#include    <p10_omi_setup.H>
#include    <ody_omi_setup.H>

#include    <sbeio/sbeioif.H>

#include    <chipids.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;
using   namespace   SBEIO;

#define CONTEXT call_omi_setup

namespace ISTEP_12
{

errlHndl_t run_omi_setup(IStepError& io_stepError, Target* const i_omic, const bool i_run_ody_hwp_from_host)
{
    errlHndl_t l_err = nullptr;

    do
    {

        // call exp_omi_setup first with each target's associated OCMB
        // call p10_omi_setup second with each target
        fapi2::Target<fapi2::TARGET_TYPE_OMIC> l_fapi_omic_target(i_omic);

        // each OMIC could have up to 2 child OMIs
        const auto l_childOMIs = l_fapi_omic_target.getChildren<fapi2::TARGET_TYPE_OMI>();

        // Loop through the OMIs and find their child OCMB
        // Run exp_omi_setup with the OCMB
        for (const auto omi : l_childOMIs)
        {
            // Get the OCMB from the OMI
            const auto l_childOCMB = omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>();

            assert(l_childOCMB.size() <= 1,
                   "Unexpected number %d of OCMB children of OMI", l_childOCMB.size());

            if (l_childOCMB.empty())
            {
                continue;
            }

            const auto ocmb = l_childOCMB[0];
            Target* const l_ocmbTarget = ocmb.get();

            if (UTIL::isOdysseyChip(l_ocmbTarget))
            {
                TRACFCOMP(g_trac_isteps_trace,
                          INFO_MRK"ody_omi_setup HWP target HUID 0x%.08x i_run_ody_hwp_from_host:%d",
                          get_huid(l_ocmbTarget), i_run_ody_hwp_from_host);

                if (i_run_ody_hwp_from_host)
                {
                    RUN_ODY_HWP(CONTEXT, io_stepError, l_err, l_ocmbTarget, ody_omi_setup, ocmb);
                }
                else
                {
                    RUN_ODY_CHIPOP(CONTEXT, io_stepError, l_err, l_ocmbTarget, IO_ODY_OMI_SETUP);
                }

            ERROR_EXIT: // used by RUN_ODY_HWP/CHIPOP
                if (l_err)
                {
                    HANDLE_ODY_HWP_ERROR(CONTEXT, ody_omi_setup, io_stepError, l_ocmbTarget, l_err);
                }
            }
            else
            {
                TRACISTEP(INFO_MRK"exp_omi_setup HWP target HUID 0x%.08x",
                          get_huid(l_ocmbTarget));

                size_t l_maxTime_secs = 0;
                timespec_t l_preLoopTime = {};
                timespec_t l_ocmbCurrentTime = {};
                clock_gettime(CLOCK_MONOTONIC, &l_preLoopTime);

                bool l_one_more_try = false;
                // Save the original timeout (to be restored after exp_omi_setup)
                // Units for the attribute are milliseconds; the value returned is > 1 second
                const auto original_timeout_ms
                  = l_ocmbTarget->getAttr<ATTR_MSS_EXP_OMI_SETUP_POLL_COUNT>();
                
                // Calculate MAX Wait Time - Round up on seconds
                // - ATTR_MSS_EXP_OMI_SETUP_POLL_COUNT in msec (see exp_attributes.xml)
                // - The calculation is as follows:
                // 1) Start with the 'seconds' value of the pre-loop time
                // 2) Add *double* the 'seconds' amount of the original timeout value
                //    -- the *double* is just to be on the safe side, as we're only dealing with
                //       seconds and not minutes here
                // 3) Add 3 to round up for the nanoseconds of (1) and double the milliseconds of (2)
                l_maxTime_secs = l_preLoopTime.tv_sec
                  + (2 * (original_timeout_ms / MS_PER_SEC))
                  + 3;

                // exp_omi_setup will read this attribute to know how long to
                // poll. If this number is too large and we get too many I2C error
                // logs between calls to FAPI_INVOKE_HWP, we will run out of memory.
                // So break the original timeout into smaller timeouts.
                // This will not affect how the loop below will use l_maxTime_secs to look for a timeouts
                const ATTR_MSS_EXP_OMI_SETUP_POLL_COUNT_type smaller_timeout_ms = 100;
                l_ocmbTarget->setAttr<ATTR_MSS_EXP_OMI_SETUP_POLL_COUNT>(smaller_timeout_ms);

                TRACISTEP("run_omi_setup: OCMB 0x%.8X: "
                          "original_timeout_ms = %d, smaller_timeout_ms = %d, "
                          "l_preLoopTime.tv_sec = %lu l_maxTime_secs = %lu",
                          get_huid(l_ocmbTarget), original_timeout_ms, smaller_timeout_ms,
                          l_preLoopTime.tv_sec, l_maxTime_secs);

                bool l_only_poll = false;
                while (true)
                {
                    // Delete the log from the previous iteration
                    if( l_err )
                    {
                        delete l_err;
                        l_err = nullptr;
                    }

                    FAPI_INVOKE_HWP(l_err, exp_omi_setup, ocmb, l_only_poll, l_one_more_try);
                    // On success, quit retrying.
                    if (!l_err)
                    {
                        TRACISTEP("run_omi_setup:exp_omi_setup DONE ! HUID=0x%.8X", get_huid(l_ocmbTarget));
                        break;
                    }
                    // from now just poll, skip the other work
                    l_only_poll = true;

                    clock_gettime(CLOCK_MONOTONIC, &l_ocmbCurrentTime);
                    if (l_ocmbCurrentTime.tv_sec > l_maxTime_secs)
                    {
                        if (l_one_more_try == false)
                        {
                            // Do one more attempt just to be safe
                            l_one_more_try = true;
                            TRACISTEP("run_omi_setup: Setting 'one more try' based on times HUID=0x%.8X "
                                      "l_ocmbCurrentTime.tv_sec = %lu, l_maxTime_secs = %lu",
                                      get_huid(l_ocmbTarget), l_ocmbCurrentTime.tv_sec, l_maxTime_secs);
                        }
                        else
                        {
                            // Already done "one more try" so just break
                            TRACISTEP("run_omi_setup: Breaking as 'one more try' exhausted HUID=0x%.8X "
                                      "l_ocmbCurrentTime.tv_sec = %lu, l_maxTime_secs = %lu",
                                      get_huid(l_ocmbTarget), l_ocmbCurrentTime.tv_sec, l_maxTime_secs);
                            break;
                        }
                    }

                    // we don't want to just hammer the i2c because we've got other threads
                    // trying to get in too so add a small delay between calls
                    nanosleep(0,100*NS_PER_MSEC);
                }

                // Restore original timeout value
                l_ocmbTarget->setAttr<ATTR_MSS_EXP_OMI_SETUP_POLL_COUNT>(original_timeout_ms);

                if (l_err)
                {
                    TRACISTEP(ERR_MRK"exp_omi_setup HWP: failed on target 0x%08X. "
                              TRACE_ERR_FMT,
                              get_huid(l_ocmbTarget),
                              TRACE_ERR_ARGS(l_err));

                    break; // have to quit here, we can only return one error
                }
                
                TRACISTEP(INFO_MRK"SUCCESS running exp_omi_setup HWP on target HUID %.8X.",
                          get_huid(l_ocmbTarget));
            }

            // reset the watchdog, this work may cause timeouts.
            INITSERVICE::sendProgressCode();
        }

        if (l_err)
        {
            break;
        }

        TRACISTEP(INFO_MRK"p10_omi_setup HWP target HUID 0x%.08x",
                  get_huid(i_omic));

        FAPI_INVOKE_HWP(l_err, p10_omi_setup, l_fapi_omic_target);

        if (l_err)
        {
            TRACISTEP(ERR_MRK"call p10_omi_setup HWP: failed on target 0x%08X. "
                      TRACE_ERR_FMT,
                      get_huid(i_omic),
                      TRACE_ERR_ARGS(l_err));
            break;
        }

        TRACISTEP(INFO_MRK"SUCCESS running p10_omi_setup HWP on target HUID %.8X.",
                  get_huid(i_omic));
    } while (false);

    return l_err;
}

void* call_omi_setup (void *io_pArgs)
{
    IStepError l_StepError;

    TRACISTEP(ENTER_MRK"call_omi_setup");

    do
    {

    // 12.6.a exp_omi_setup.C
    //        - Set any register (via I2C) on the Explorer before OMI is
    //          trained
    const auto l_omicTargetList = composable(getAllChiplets)(TYPE_OMIC, true);
    TRACISTEP(INFO_MRK"call_omi_setup: %d OMICs found", l_omicTargetList.size());

    const auto sys = UTIL::assertGetToplevelTarget();

    const auto run_ody_hwp_from_host = sys->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(l_omicTargetList,
                                                   l_StepError,
                                                   "omi_setup",
                                                   [&](Target* const i_omic)
    {
        return run_omi_setup(l_StepError, i_omic, run_ody_hwp_from_host);
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(ERR_MRK"call_omi_setup: omi_setup error");
        break;
    }

    // Check explorer FW levels and do an i2c update if needed.
    // The update will fail before step 12.6 because the inbound doorbell
    // register (along with many other parts of the scommable logic) in Explorer
    // isn't clocked before we run the FW_BOOT_CONFIG0 command.
    // This prevents all inband commands from working, even using the i2c
    // interface, until after exp_omi_setup runs.
    // Check if explorer chips need an update (skipped on MPIPL)
    if (sys->getAttr<ATTR_IS_MPIPL_HB>())
    {
        TRACISTEP("skipping ocmbFwI2cUpdateStatusCheck() due to MPIPL");
    }
    else
    {
        ocmbupd::ocmbFwI2cUpdateStatusCheck(l_StepError);
    }

    // Set ATTR_ATTN_CHK_OCMBS to let ATTN know that we may now get attentions
    // from Explorer, but interrupts from the OCMB are not enabled yet.
    if (!UTIL::hasOdysseyOcmbChildren(UTIL::getCurrentNodeTarget()))
    {
        TRACISTEP("Enable attention processing for Explorer OCMBs");
        sys->setAttr<ATTR_ATTN_CHK_OCMBS>(1);
    }

    } while (false);

    TRACISTEP(EXIT_MRK"call_omi_setup");

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

}
