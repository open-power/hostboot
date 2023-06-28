/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep11/call_ocmb_check_for_ready.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
#include <targeting/common/targetservice.H>
#include <targeting/odyutil.H>
#include <sbeio/sbeioif.H>
#include <util/misc.H>
#include <sys/time.h>
#include <time.h>

//  HWP call support
#include <exp_check_for_ready.H>
#include <ody_check_for_ready.H>
#include <ody_sppe_config_update.H>
#include <ody_cbs_start.H>
#include <ody_sppe_check_for_ready.H>
#include <pmic_enable.H>
#include <p10_ocmb_enable.H>
#include <platform_vddr.H>
#include <chipids.H>
#include <p10_scom_perv_2.H>

// Explorer error logs
#include <expscom/expscom_errlog.H>

// sendProgressCode
#include <initservice/istepdispatcherif.H>

// Code update
#include <ocmbupd/ocmbupd.H>
#include <ocmbupd/ocmbFwImage.H>
#include <ocmbupd/ody_upd_fsm.H>

using namespace ISTEPS_TRACE;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;
using namespace SBEIO;

using namespace ocmbupd;

#define TRACF(...) TRACFCOMP(g_trac_isteps_trace, __VA_ARGS__)

namespace ISTEP_11
{

errlHndl_t cfam_reset(Target* const i_proc)
{
    errlHndl_t errl = nullptr;

    do
    {

    uint64_t data = 0;
    uint64_t size = sizeof(uint64_t);

    errl = deviceRead(i_proc, &data, size,
                      DEVICE_SCOM_ADDRESS(scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL0_RW));

    if (errl)
    {
        TRACF(ERR_MRK"ocmb_check_for_ready: Failed to read FSXCOMP_FSXLOG_ROOT_CTRL0_RW from 0x%08X - "
              TRACE_ERR_FMT,
              get_huid(i_proc),
              TRACE_ERR_ARGS(errl));
        break;
    }

    // Set the OCMB_RESET_EN bit in the register, which will reset all
    // the OCMBs under this processor
    data |= (0x80000000'00000000ull >> scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN);

    errl = deviceWrite(i_proc, &data, size,
                       DEVICE_SCOM_ADDRESS(scomt::perv::FSXCOMP_FSXLOG_ROOT_CTRL0_RW));

    if (errl)
    {
        TRACF(ERR_MRK"ocmb_check_for_ready: Failed to write FSXCOMP_FSXLOG_ROOT_CTRL0_RW from 0x%08X - "
              TRACE_ERR_FMT,
              get_huid(i_proc),
              TRACE_ERR_ARGS(errl));
        break;
    }

    } while (false);

    return errl;
}

/** @brief Check whether the given error has async FFDC or not.
 */
bool err_is_sppe_not_ready_with_async_ffdc(Target* const i_ocmb, const errlHndl_t i_errl)
{
    bool is_sppe_not_ready_with_async_ffdc = false;

    if (i_errl->reasonCode() == fapi2::RC_POZ_SPPE_NOT_READY_ERR)
    {
        uint64_t data = 0;
        uint64_t datasize = sizeof(data);
        auto errl = deviceRead(i_ocmb,
                               &data,
                               datasize,
                               DEVICE_SCOM_ADDRESS(0x50009));

        if (errl)
        {
            TRACF("call_ocmb_check_for_ready: SCOM read failed on OCMB 0x%08X "
                  "while trying to read the async FFDC bit; deleting error and continuing",
                  get_huid(i_ocmb));
            delete errl;
            errl = nullptr;
        }
        else
        {
            // See mbxscratch.H for this definition
            typedef union
            {
                struct
                {
                    uint64_t iv_sbeBooted : 1;
                    uint64_t iv_asyncFFDC : 1;
                    uint64_t iv_reserved1 : 1;
                    uint64_t iv_currImage : 1; // If 0->SROM , 1->Boot Loader/Runtime
                    uint64_t iv_prevState : 4;
                    uint64_t iv_currState : 4;
                    uint64_t iv_majorStep : 4;
                    uint64_t iv_minorStep : 6;
                    uint64_t iv_reserved2 : 4;
                    uint64_t iv_progressCode : 6;
                    uint64_t iv_unused : 32;
                };
                uint64_t iv_messagingReg;
            }messagingReg_t;

            messagingReg_t reg;
            reg.iv_messagingReg = data;

            if (reg.iv_asyncFFDC)
            {
                is_sppe_not_ready_with_async_ffdc = true;
            }
        }
    }

    return is_sppe_not_ready_with_async_ffdc;
}

/** @brief Called when all of the check_for_ready HWPs have been invoked on the given OCMB,
 *  whether they failed or not. This function handles errors and checks the code version
 *  running on the OCMB if possible.
 *
 *  @param[in] i_ocmb                   The OCMB.
 *  @param[in] i_hwpErrl                Any error returned by a HWP.
 *  @param[in] i_ocmbfw_pnor_partition  Owning handle to the OCMBFW PNOR partition.
 *  @param[out] o_restart_needed        Set to true if the Odyssey code update FSM indicates that the
 *                                      OCMB needs to run through check_for_ready again.
 *
 *  @return    errlHndl_t               Error if any, otherwise nullptr.
 */
errlHndl_t handle_ody_upd_hwps_done(Target* const i_ocmb,
                                    errlHndl_t& i_hwpErrl,
                                    const ocmbfw_owning_ptr_t& i_ocmbfw_pnor_partition,
                                    bool& o_restart_needed)
{
    errlHndl_t errl = nullptr;

    if (i_ocmbfw_pnor_partition) // no point in doing anything if we have no Odyssey images in PNOR.
    {
        ody_upd_event_t event = NO_EVENT;

        if (i_hwpErrl)
        { // If there was a HWP error, check whether there is async FFDC.
            event = OCMB_BOOT_ERROR_NO_FFDC;

            // @TODO: Can we could have async FFDC without a HWP error? If so we should check this
            // in the HWP success path as well.
            if (err_is_sppe_not_ready_with_async_ffdc(i_ocmb, i_hwpErrl))
            {
                event = OCMB_BOOT_ERROR_WITH_FFDC;
            }
            else
            {
                // @TODO: call ody_extract_sbe_rc
            }
        }

        if (event != OCMB_BOOT_ERROR_NO_FFDC)
        { // If there is async FFDC, we might be able to read the code levels.
            errl = set_ody_code_levels_state(i_ocmb, i_ocmbfw_pnor_partition);

            if (errl)
            {
                TRACF("call_ocmb_check_for_ready: set_ody_code_levels_state "
                      "failed on OCMB 0x%X",
                      get_huid(i_ocmb));

                // If we can't read code levels, treat this as a boot failure with no async
                // FFDC.

                event = OCMB_BOOT_ERROR_NO_FFDC;

                errl->plid(i_hwpErrl->plid());
                i_hwpErrl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                errlCommit(i_hwpErrl, HWPF_COMP_ID);
                i_hwpErrl = errl;
                errl = nullptr;
            }
        }

        if (i_hwpErrl)
        {
            // Pass any HWP error to the code update FSM and let it tell us what to do.

            i_hwpErrl->addHwCallout(i_ocmb, HWAS::SRCI_PRIORITY_HIGH, HWAS::DECONFIG, HWAS::GARD_NULL);

            errl = ody_upd_process_event(i_ocmb,
                                         event,
                                         i_hwpErrl,
                                         i_ocmbfw_pnor_partition,
                                         o_restart_needed);
        }
    }

    return errl;
}

void* call_ocmb_check_for_ready (void *io_pArgs)
{
    TRACF(ENTER_MRK"call_ocmb_check_for_ready");

    errlHndl_t l_errl = nullptr;
    IStepError l_StepError;

    const auto sys = UTIL::assertGetToplevelTarget();

    do
    {

    auto ocmbfw = load_ocmbfw_pnor_section(l_errl);

    if (l_errl)
    {
        TRACF(ERR_MRK"call_ocmb_check_for_ready: load_ocmbfw_pnor_section failed: "
              TRACE_ERR_FMT,
              TRACE_ERR_ARGS(l_errl));

        TRACF(INFO_MRK"call_ocmb_check_for_ready: Ignoring error until support for "
              "OCMBFW PNOR partition version 1 is dropped");

        // @TODO: JIRA PFHB-522 Capture this error when OCMBFW V1 support is deprecated
        delete l_errl;
        l_errl = nullptr;

        ocmbfw = nullptr;

        //captureError(errl, o_stepError, ISTEP_COMP_ID);
        // continue to boot the Explorers
    }

    // We need to do an explicit delay before our first i2c operation
    //  to the OCMBs to ensure we don't catch them too early in the boot
    //  and lock them up.
    const auto ocmb_delay = UTIL::assertGetToplevelTarget()
      ->getAttr<ATTR_OCMB_RESET_DELAY_SEC>();
    nanosleep(ocmb_delay,0);

    TargetHandleList functionalProcChipList;

    getAllChips(functionalProcChipList, TYPE_PROC, true);

    // loop thru the list of processors
    for (TargetHandleList::const_iterator
            l_proc_iter = functionalProcChipList.begin();
            l_proc_iter != functionalProcChipList.end();
            ++l_proc_iter)
    {
        TargetHandleList l_functionalOcmbChipList;
        getChildAffinityTargets( l_functionalOcmbChipList,
                                 const_cast<Target*>(*l_proc_iter),
                                 CLASS_CHIP,
                                 TYPE_OCMB_CHIP,
                                 true);

        while (!l_functionalOcmbChipList.empty())
        {
            // For each loop on an OCMB below, multiply the timeout chunk
            size_t loop_multiplier = 1;

            // Keep track of overall time
            size_t l_maxTime_secs = 0;
            timespec_t l_preLoopTime = {};
            timespec_t l_ocmbCurrentTime = {};
            clock_gettime(CLOCK_MONOTONIC, &l_preLoopTime);

            // If this variable is true,
            bool retry_odyssey_check_for_ready = false;

            const auto ocmbs = move(l_functionalOcmbChipList);
            l_functionalOcmbChipList.clear();

            for (const auto l_ocmb : ocmbs)
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
                    // Each attempt can take a few minutes so poke the
                    //  watchdog before each attempt
                    INITSERVICE::sendProgressCode();

                    // Delete the log from the previous iteration
                    if( l_errl )
                    {
                        delete l_errl;
                        l_errl = nullptr;
                    }

                    if(l_ocmb->getAttr<TARGETING::ATTR_CHIP_ID>() == POWER_CHIPID::ODYSSEY_16)
                    {
                        FAPI_INVOKE_HWP(l_errl,
                                        ody_check_for_ready,
                                        l_fapi_ocmb_target);
                    }
                    else
                    {
                        FAPI_INVOKE_HWP(l_errl,
                                        exp_check_for_ready,
                                        l_fapi_ocmb_target);
                    }

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
                    if (l_ocmb->getAttr<TARGETING::ATTR_CHIP_ID>() == POWER_CHIPID::ODYSSEY_16)
                    {
                        TRACFCOMP(g_trac_isteps_trace,
                                  "ERROR : call_ocmb_check_for_ready HWP(): "
                                  "ody_check_for_ready failed on target 0x%08X."
                                  TRACE_ERR_FMT,
                                  get_huid(l_ocmb),
                                  TRACE_ERR_ARGS(l_errl));
                        // Do not capture the error or continue for Odyssey OCMBs; let the
                        // subsequent error-handling code kick in.
                    }
                    else
                    {
                        TRACFCOMP(g_trac_isteps_trace,
                                  "ERROR : call_ocmb_check_for_ready HWP(): "
                                  "exp_check_for_ready failed on target 0x%08X."
                                  TRACE_ERR_FMT,
                                  get_huid(l_ocmb),
                                  TRACE_ERR_ARGS(l_errl));

                        // Capture error and continue to next OCMB
                        captureError(l_errl, l_StepError, HWPF_COMP_ID, l_ocmb);
                        continue;
                    }
                }
                else
                {
                    TRACFCOMP(g_trac_isteps_trace,
                              "SUCCESS : exp/ody check_for_ready "
                              "completed ok");

                    size_t size = 0;

                    TRACFCOMP(g_trac_isteps_trace,
                              "Read IDEC from OCMB 0x%.8X",
                              get_huid(l_ocmb));

                    // This write gets translated into a read of the ocmb chip
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

                        if (l_ocmb->getAttr<TARGETING::ATTR_CHIP_ID>() != POWER_CHIPID::ODYSSEY_16)
                        {
                            // Capture error and continue to next OCMB for Explorer OCMBs. For
                            // Odyssey, let the subsequent error-handling code kick in.
                            captureError(l_errl, l_StepError, HWPF_COMP_ID, l_ocmb);
                            continue;
                        }
                    }
                }

                // Odyssey chips require a few more HWPs to run to start them up:
                // ody_sppe_config_update writes the SPPE config
                // ody_cbs_start starts SPPE
                // ody_sppe_check_for_ready makes sure that SPPE booted correctly
                if(l_ocmb->getAttr<TARGETING::ATTR_CHIP_ID>() != POWER_CHIPID::ODYSSEY_16)
                {
                    continue;
                }

                /* Set the boot side and boot flags appropriately. */

                const ATTR_OCMB_BOOT_FLAGS_type boot_flags
                    = sys->getAttr<TARGETING::ATTR_OCMB_BOOT_FLAGS>();

                const auto boot_side
                    = l_ocmb->getAttr<TARGETING::ATTR_OCMB_BOOT_SIDE>();

                l_ocmb->setAttr<TARGETING::ATTR_SPPE_BOOT_SIDE>(boot_side);

                // See ody_perv_attributes.xml for these definitions
                const uint32_t OCMB_BOOT_FLAGS_BOOT_INDICATION_MASK = 0xC0000000;
                const uint32_t OCMB_BOOT_FLAGS_AUTOBOOT_MODE = 0x00000000;
                const uint32_t OCMB_BOOT_FLAGS_ISTEP_MODE = 0xC0000000;

                if (boot_side == SPPE_BOOT_SIDE_GOLDEN
                    || sys->getAttr<TARGETING::ATTR_OCMB_ISTEP_MODE>())
                {
                    TRACF("call_ocmb_check_for_ready: Disable autoboot for golden side on Odyssey OCMB 0x%08X",
                          get_huid(l_ocmb));

                    // Disable autoboot on the golden side, so that we execute as
                    // little code as possible (and therefore have the smallest chance
                    // of failing) before we update the chip.
                    sys->setAttr<TARGETING::ATTR_OCMB_BOOT_FLAGS>((boot_flags & ~OCMB_BOOT_FLAGS_BOOT_INDICATION_MASK)
                                                                  | OCMB_BOOT_FLAGS_ISTEP_MODE);
                }
                else
                {
                    TRACF("call_ocmb_check_for_ready: Enable autoboot for side %d on Odyssey OCMB 0x%08X",
                          boot_side,
                          get_huid(l_ocmb));

                    sys->setAttr<TARGETING::ATTR_OCMB_BOOT_FLAGS>((boot_flags & ~OCMB_BOOT_FLAGS_BOOT_INDICATION_MASK)
                                                                  | OCMB_BOOT_FLAGS_AUTOBOOT_MODE);
                }

                do
                {
                    if (l_errl)
                    {
                        // This could already be set from ody_check_for_ready or the IDEC
                        // deviceWrite above.
                        break;
                    }

                    FAPI_INVOKE_HWP(l_errl, ody_sppe_config_update, l_fapi_ocmb_target);

                    if(l_errl)
                    {
                        TRACF("call_ocmb_check_for_ready: ody_sppe_config_update failed on OCMB 0x%x", get_huid(l_ocmb));
                        break; // handle error
                    }

                    TRACF("call_ocmb_check_for_ready: setting boot side to %d for OCMB 0x%X",
                          boot_side,
                          get_huid(l_ocmb));

                    FAPI_INVOKE_HWP(l_errl, ody_cbs_start, l_fapi_ocmb_target);
                    if(l_errl)
                    {
                        TRACF("call_ocmb_check_for_ready: ody_cbs_start failed on OCMB 0x%x", get_huid(l_ocmb));
                        break; // handle error
                    }

                    FAPI_INVOKE_HWP(l_errl, ody_sppe_check_for_ready, l_fapi_ocmb_target);

                    if (l_errl)
                    {
                        TRACF("call_ocmb_check_for_ready: ody_sppe_check_for_ready failed on OCMB 0x%x", get_huid(l_ocmb));
                        break;
                    }
                } while (false);

                bool retry_this_odyssey = false;

                if (ocmbfw)
                {
                    l_errl = handle_ody_upd_hwps_done(l_ocmb,
                                                      l_errl,
                                                      ocmbfw,
                                                      retry_this_odyssey);
                }

                if (l_errl)
                {
                    TRACF("call_ocmb_check_for_ready: ody_upd fsm failed to handle "
                          "a hwp error on OCMB 0x%X; failing the Istep - "
                          TRACE_ERR_FMT,
                          get_huid(l_ocmb),
                          TRACE_ERR_ARGS(l_errl));

                    captureError(l_errl, l_StepError, HWPF_COMP_ID, l_ocmb);

                    // If the ody_upd FSM fails, a fatal error
                    // happened and we should stop the boot, so we
                    // break out of the entire istep here.
                    goto FAIL_ISTEP;
                }

                retry_odyssey_check_for_ready = retry_odyssey_check_for_ready || retry_this_odyssey;

                if (retry_this_odyssey)
                {
                    TRACF("call_ocmb_check_for_ready: OCMB 0x%08X requires us to reboot all of the "
                          "Odysseys under processor 0x%08X",
                          get_huid(l_ocmb), get_huid(*l_proc_iter));

                    continue; // We continue boot other Odysseys even though we're going
                              // to reboot them all anyway; that way, if we have, say, M
                              // Odysseys and all of them are going to fail once, we do
                              // 2*M boots total, instead of the 1+2+3+...+M boots that we
                              // would do if we didn't continue here. (This is worse for M
                              // < 3, but is better when M > 3, which is going to be the
                              // common case).
                }

                if (!l_ocmb->getAttr<ATTR_HWAS_STATE>().functional)
                {
                    TRACF("call_ocmb_check_for_ready: OCMB 0x%08X was deconfigured",
                          get_huid(l_ocmb));

                    continue;
                }

                if (ocmbfw)
                {
                    errlHndl_t no_error = nullptr; // no error for this call
                    l_errl = ody_upd_process_event(l_ocmb,
                                                   CHECK_FOR_READY_COMPLETED,
                                                   no_error,
                                                   ocmbfw,
                                                   retry_odyssey_check_for_ready);
                }

                if (l_errl)
                {
                    TRACF("call_ocmb_check_for_ready: ody_upd fsm failed on OCMB 0x%x; "
                          "failing the Istep",
                          get_huid(l_ocmb));

                    captureError(l_errl, l_StepError, HWPF_COMP_ID, l_ocmb);

                    // If the ody_upd FSM fails, a fatal error
                    // happened and we should stop the boot, so we
                    // break out of the entire istep here.
                    goto FAIL_ISTEP;
                }
            } // End of OCMB Loop

            if (retry_odyssey_check_for_ready)
            {
                TRACF("call_ocmb_check_for_ready: restarting all Odysseys under processor "
                      " at the request of the Odyssey code update FSM");

                getChildAffinityTargets(l_functionalOcmbChipList,
                                        const_cast<Target*>(*l_proc_iter),
                                        CLASS_CHIP,
                                        TYPE_OCMB_CHIP,
                                        true /* functional */);

                // After restarting the Odysseys, we assume that we don't know their code
                // level any more.
                std::for_each(begin(l_functionalOcmbChipList),
                              end(l_functionalOcmbChipList),
                              clear_ody_code_levels_state);

                /* Perform a CFAM reset to reboot all the Odysseys under the given
                   processor. We can't do this on an OCMB-by-OCMB basis, so we're limited to
                   doing it at processor granularity. */

                cfam_reset(*l_proc_iter);

                TRACF(INFO_MRK"call_ocmb_check_for_ready: Calling p10_ocmb_enable on 0x%08X",
                      get_huid(*l_proc_iter));

                /* De-assert the CFAM reset. */

                FAPI_INVOKE_HWP(l_errl, p10_ocmb_enable, { *l_proc_iter });

                if (l_errl)
                {
                    TRACF(ERR_MRK"call_ocmb_check_for_ready: p10_ocmb_enable failed "
                          "on target 0x%08X. Failing the Istep. "
                          TRACE_ERR_FMT,
                          get_huid(*l_proc_iter),
                          TRACE_ERR_ARGS(l_errl));

                    // Capture error and fail the istep
                    captureError(l_errl, l_StepError, HWPF_COMP_ID, *l_proc_iter);
                    goto FAIL_ISTEP;
                }

                // We need to do an explicit delay before our first i2c operation
                //  to the OCMBs to ensure we don't catch them too early in the boot
                //  and lock them up.
                const auto ocmb_delay = UTIL::assertGetToplevelTarget()->getAttr<ATTR_OCMB_RESET_DELAY_SEC>();
                nanosleep(ocmb_delay, 0);

                /* The fact that l_functionalOcmbChipList is non-empty will cause us to retry them all. */
            }
        } // End of Odyssey retry loop

        {
            auto explorers
                = composable(getChildAffinityTargets)(const_cast<Target*>(*l_proc_iter),
                                                      CLASS_CHIP,
                                                      TYPE_OCMB_CHIP,
                                                      true);

            explorers.erase(std::remove_if(begin(explorers), end(explorers), UTIL::isOdysseyChip),
                            end(explorers));

            // TODO: Make these for odyssey too
            // Grab informational Explorer logs (early IPL = true)
            EXPSCOM::createExplorerLogs(explorers, true);
        }
    }

    // Loop thru the list of processors and send Memory config info to SBE
    for (auto &l_procTarget: functionalProcChipList)
    {
        l_errl = psuSendSbeMemConfig(l_procTarget);

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

    // Set ATTR_ATTN_CHK_OCMBS to let ATTN know that we may now get attentions
    // from Odyssey, but interrupts from the OCMB are not enabled yet.
    TargetHandleList l_allOCMBs;
    getAllChips(l_allOCMBs, TYPE_OCMB_CHIP, true);
    for (const auto l_ocmb : l_allOCMBs)
    {
        uint32_t l_chipId = l_ocmb->getAttr<TARGETING::ATTR_CHIP_ID>();
        if (l_chipId == POWER_CHIPID::ODYSSEY_16)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "Enable attention processing for Odyssey OCMBs");
            UTIL::assertGetToplevelTarget()->setAttr<ATTR_ATTN_CHK_OCMBS>(1);
        }
        // There can be no mixing of OCMB types so only need to check one
        break;
    }

    // Enable scoms via the Odyssey SBE now that the the SBE is running
    // and we can send it chipops
    for (const auto l_ocmb : l_allOCMBs)
    {
        uint32_t l_chipId = l_ocmb->getAttr<TARGETING::ATTR_CHIP_ID>();
        if (l_chipId == POWER_CHIPID::ODYSSEY_16)
        {
            ScomSwitches l_switches = l_ocmb->getAttr<ATTR_SCOM_SWITCHES>();

            // Turn on SBE SCOM
            l_switches.useSbeScom = 1;

            // Turn off I2C SCOM since all scoms are restricted on
            // secure parts
            l_switches.useI2cScom = 0;

            l_ocmb->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
        }
    }

    } while (false);

 FAIL_ISTEP:

    TRACF(EXIT_MRK"call_ocmb_check_for_ready");
    return l_StepError.getErrorHandle();
}

};
