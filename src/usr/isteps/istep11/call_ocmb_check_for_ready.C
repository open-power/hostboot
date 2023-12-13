/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep11/call_ocmb_check_for_ready.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2024                        */
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
#include <initservice/mboxRegs.H>

//  Targeting support
#include <attributeenums.H>                     // TYPE_PROC
#include <targeting/common/utilFilter.H>        // getAllChips
#include <targeting/common/targetservice.H>
#include <targeting/odyutil.H>
#include <sbeio/sbeioif.H>
#include <sbeio/errlud_sbeio.H>
#include <sbeio/sbe_retry_handler.H>
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

#include <hwpThread.H>
#include <hwpThreadHelper.H>

// Code update
#include <ocmbupd/ocmbupd.H>
#include <ocmbupd/ocmbFwImage.H>
#include <ocmbupd/ody_upd_fsm.H>
#include <secureboot/service.H>
#include <targeting/common/mfgFlagAccessors.H>

using namespace ISTEPS_TRACE;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;
using namespace SBEIO;

using namespace ocmbupd;

namespace ISTEP_11
{

errlOwner handle_ody_upd_hwps_done(Target* const, errlOwner, bool&); // forward declaration

/** @brief Called to perform the attribute setup for the OCMB.
 *
 *  @param[in] i_ocmb                   The OCMB.
 *
 *  @return    errlHndl_t               Error if any, otherwise nullptr.
 */
errlHndl_t ody_attribute_setup(Target* const i_ocmb)
{
    errlHndl_t l_errl               = nullptr;
    const auto ocmb_boot_flags_orig = i_ocmb->getAttr<TARGETING::ATTR_OCMB_BOOT_FLAGS>();
    const auto boot_side            = i_ocmb->getAttr<TARGETING::ATTR_OCMB_BOOT_SIDE>();

    i_ocmb->setAttr<TARGETING::ATTR_SPPE_BOOT_SIDE>(boot_side);

    // See ody_perv_attributes.xml for these definitions
    const uint32_t OCMB_BOOT_FLAGS_BOOT_INDICATION_MASK = 0xC0000000;
    const uint32_t OCMB_BOOT_FLAGS_AUTOBOOT_MODE = 0x00000000;
    const uint32_t OCMB_BOOT_FLAGS_ISTEP_MODE = 0xC0000000;

    const auto sys = UTIL::assertGetToplevelTarget();

    uint32_t ocmb_boot_flags_new = (ocmb_boot_flags_orig & ~OCMB_BOOT_FLAGS_BOOT_INDICATION_MASK);

    if (boot_side == SPPE_BOOT_SIDE_GOLDEN || sys->getAttr<TARGETING::ATTR_OCMB_ISTEP_MODE>())
    {
        TRACISTEP("ody_attribute_setup: Disable autoboot for Odyssey golden side HUID=0x%X",
                  get_huid(i_ocmb));

        // Disable autoboot on the golden side, so that we execute as
        // little code as possible (and therefore have the smallest chance
        // of failing) before we update the chip.
        ocmb_boot_flags_new |= OCMB_BOOT_FLAGS_ISTEP_MODE;
        i_ocmb->setAttr<TARGETING::ATTR_OCMB_BOOT_FLAGS>(ocmb_boot_flags_new);
    }
    else
    {
        TRACISTEP("ody_attribute_setup: Enable autoboot for Odyssey side %d HUID=0x%X",
                  boot_side, get_huid(i_ocmb));

        ocmb_boot_flags_new |= OCMB_BOOT_FLAGS_AUTOBOOT_MODE;
        i_ocmb->setAttr<TARGETING::ATTR_OCMB_BOOT_FLAGS>(ocmb_boot_flags_new);
    }

    /*--------------------------------------------------------------------------
     * Setup the security settings in ATTR_OCMB_BOOT_FLAGS
     -------------------------------------------------------------------------*/
    bool security_enabled = SECUREBOOT::enabled();
    bool prod_driver      = (SECUREBOOT::getSbeSecurityBackdoor() == false);
    bool mfg_mode         = TARGETING::areMfgThresholdsActive();

    if (!mfg_mode && !prod_driver)
    {
        // get boot_flags from Scratch3 register on the boot proc
        const auto l_scratchRegs = UTIL::assertGetToplevelTarget()->
                                    getAttrAsStdArr<ATTR_MASTER_MBOX_SCRATCH>();
        const auto boot_flags = l_scratchRegs[INITSERVICE::SPLESS::MboxScratch3_t::REG_IDX];

        uint32_t BOOT_FLAGS_BIT7  = 0x01000000; // Allow ATTR overrides in a secure system
        uint32_t BOOT_FLAGS_BIT11 = 0x00100000; // Disable SCOM Security
        uint32_t BOOT_FLAGS_BIT12 = 0x00080000; // Disable invalid scom address check

        // set bits 7,11,12 in ATTR_OCMB_BOOT_FLAGS to match ATTR_BOOT_FLAGS
        if (boot_flags & BOOT_FLAGS_BIT7)  {ocmb_boot_flags_new |= BOOT_FLAGS_BIT7;}
        if (boot_flags & BOOT_FLAGS_BIT11) {ocmb_boot_flags_new |= BOOT_FLAGS_BIT11;}
        if (boot_flags & BOOT_FLAGS_BIT12) {ocmb_boot_flags_new |= BOOT_FLAGS_BIT12;}

        // check FFT ATTR override to allow scom security
        if (!UTIL::assertGetToplevelTarget()->getAttr<ATTR_OCMB_IGNORE_SCOM_CHECK_DISABLE>())
        {
            // always turn on bit11, *temporary*
            //   @TODO: JIRA: PFHB-664 Remove hardcode setting bit11
            ocmb_boot_flags_new |= BOOT_FLAGS_BIT11;  // Disable SCOM Security
        }

        if (security_enabled)
        {
            uint32_t BOOT_FLAGS_BIT4  = 0x08000000; // Emulate Security Enable
            uint32_t BOOT_FLAGS_BIT16 = 0x00008000; // Enable ECDSA Signature enable
            uint32_t BOOT_FLAGS_BIT17 = 0x00004000; // Enable Dilithium Signature enable
            uint32_t BOOT_FLAGS_BIT19 = 0x00001000; // Enable HW key hash verification

            ocmb_boot_flags_new |= BOOT_FLAGS_BIT4  |
                                   BOOT_FLAGS_BIT16 |
                                   BOOT_FLAGS_BIT17 |
                                   BOOT_FLAGS_BIT19;
        }

        i_ocmb->setAttr<TARGETING::ATTR_OCMB_BOOT_FLAGS>(ocmb_boot_flags_new);

        TRACISTEP("ody_attribute_setup: update security boot flags "
                  "orig:%0.8X new:%0.8X HUID=x%X",
                  ocmb_boot_flags_orig,
                  ocmb_boot_flags_new,
                  get_huid(i_ocmb));
    }

    TRACISTEP("ody_attribute_setup: Setting boot side to boot_side=%d HUID=x%X",
              boot_side, get_huid(i_ocmb));
    return l_errl;
}

/** @brief Called to perform deviceWrite for the OCMB.
 *
 *         See ocmbIdecPhase2 description for details on the
 *         cross-check performed for specifics on the data which
 *         is synced.
 *
 *  @param[in] i_ocmb                   The OCMB.
 *
 *  @return    errlHndl_t               Error if any, otherwise nullptr.
 */
errlHndl_t ocmb_idec_sync(Target* const i_ocmb)
{
    errlHndl_t l_errl = nullptr;
    size_t size = 0;

    TRACISTEP("ocmb_idec_sync: Read IDEC HUID=0x%X", get_huid(i_ocmb));

    // This write gets translated into a read of the ocmb chip
    // in the device driver. First, a read of the chip's IDEC
    // register occurs then ATTR_EC, ATTR_HDAT_EC, and ATTR_CHIP_ID
    // are set with the values found in that register. So, this
    // deviceWrite functions more as a setter for an OCMB target's
    // attributes.
    // Pass 2 as a va_arg to signal the ocmbIDEC function to execute
    // phase 2 of its read process.
    const uint64_t Phase2 = 2;
    l_errl = DeviceFW::deviceWrite(i_ocmb,
                                   nullptr,
                                   size,
                                   DEVICE_IDEC_ADDRESS(),
                                   Phase2);
    return l_errl;
}

/** @brief Called to perform the Explorer/Odyssey check_for_ready HWP.
 *
 *  @param[in] i_ocmb                   The OCMB.
 *
 *  @return    errlHndl_t               Error if any, otherwise nullptr.
 */
errlHndl_t check_for_ready_work(Target* const i_ocmb)
{
    errlHndl_t l_errl = nullptr;
    fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP>l_fapi_ocmb_target(i_ocmb);

    size_t l_maxTime_secs = 0;
    timespec_t l_preLoopTime = {};
    timespec_t l_ocmbCurrentTime = {};
    clock_gettime(CLOCK_MONOTONIC, &l_preLoopTime);

    bool l_one_more_try = false;

    // Save the original timeout (to be restored after exp_check_for_ready)
    // Units for the attribute are milliseconds; the value returned is > 1 second
    const auto original_timeout_ms = i_ocmb->getAttr<ATTR_MSS_CHECK_FOR_READY_TIMEOUT>();

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
    // This will not affect how the loop below will use l_maxTime_secs to look for a timeouts
    const ATTR_MSS_CHECK_FOR_READY_TIMEOUT_type smaller_timeout_ms = 10;
    i_ocmb->setAttr<ATTR_MSS_CHECK_FOR_READY_TIMEOUT>(smaller_timeout_ms);

    TRACISTEP("check_for_ready_work: OCMB 0x%X: "
              "original_timeout_ms = %d, smaller_timeout_ms = %d, "
              "l_preLoopTime.tv_sec = %lu l_maxTime_secs = %lu",
              get_huid(i_ocmb), original_timeout_ms, smaller_timeout_ms,
              l_preLoopTime.tv_sec, l_maxTime_secs);

    while (true)
    {
        // Delete the log from the previous iteration
        if( l_errl )
        {
            delete l_errl;
            l_errl = nullptr;
        }

        if (UTIL::isOdysseyChip(i_ocmb))
        {
            FAPI_INVOKE_HWP(l_errl, ody_check_for_ready, l_fapi_ocmb_target);
        }
        else
        {
            FAPI_INVOKE_HWP(l_errl, exp_check_for_ready, l_fapi_ocmb_target);
        }
        // On success, quit retrying.
        if (!l_errl)
        {
            TRACISTEP("check_for_ready_work: exp/ody_check_for_ready DONE ! HUID=0x%X", get_huid(i_ocmb));
            break;
        }

        clock_gettime(CLOCK_MONOTONIC, &l_ocmbCurrentTime);
        if (l_ocmbCurrentTime.tv_sec > l_maxTime_secs)
        {
            if (l_one_more_try == false)
            {
                // Do one more attempt just to be safe
                l_one_more_try = true;
                TRACISTEP("check_for_ready_work: Setting 'one more try' based on times HUID=0x%X "
                          "l_ocmbCurrentTime.tv_sec = %lu, l_maxTime_secs = %lu",
                          get_huid(i_ocmb), l_ocmbCurrentTime.tv_sec, l_maxTime_secs);
            }
            else
            {
                // Already done "one more try" so just break
                TRACISTEP("check_for_ready_work: Breaking as 'one more try' exhausted HUID=0x%X "
                          "l_ocmbCurrentTime.tv_sec = %lu, l_maxTime_secs = %lu",
                          get_huid(i_ocmb), l_ocmbCurrentTime.tv_sec, l_maxTime_secs);
                break;
            }
        }
    } // end while

    // Restore original timeout value
    i_ocmb->setAttr<ATTR_MSS_CHECK_FOR_READY_TIMEOUT>(original_timeout_ms);
    return l_errl;
}

/** @brief Called to handle the OCMB boot process on a per PROC basis.
 *
 *         This function handles the boot of the OCMB's on a per PROC
 *         basis.  Any OCMB operations or recovery actions will be
 *         handled by leveraging the parallelization of the permittable
 *         OCMB operations.
 *
 *         During each of the PROC's isolation of its children OCMBs, each PROC
 *         will synchronize the necessary OCMB operations to accomplish the proper
 *         OCMB boot sequences.
 *
 *  @param[in] i_proc                   The PROC.
 *  @param[in/out] io_iStepError        The IStepError which will capture any problems.
 *
 *  @return    errlHndl_t               Error if any, otherwise nullptr.
 */
errlHndl_t boot_all_proc_ocmbs(Target* const i_proc, IStepError& io_iStepError)
{
    errlHndl_t l_errl = nullptr;
    TargetHandleList l_functionalOcmbChipList;
    getChildAffinityTargets( l_functionalOcmbChipList,
                             i_proc,
                             CLASS_CHIP,
                             TYPE_OCMB_CHIP,
                             true);

    while (!l_functionalOcmbChipList.empty())
    {
        const auto ocmbs = move(l_functionalOcmbChipList);
        // Not required in the standard for a moved-from vector to be empty
        // Here for completeness
        l_functionalOcmbChipList.clear();
        bool proc_reboot_odysseys = false;

        // Watchdog refresh - each i2c update may take approximately
        // one minute, but this may re-occur, so sendProgressCode
        // once per iteration in the loop
        INITSERVICE::sendProgressCode();
        TRACISTEP("boot_all_proc_ocmbs: sendProgressCode PROC HUID=0x%X", get_huid(i_proc));

        ISTEP::parallel_for_each(ocmbs,
                                 io_iStepError,
                                 "check_for_ready_work",
                                 [&](Target* const i_ocmb)
        {
            errlOwner l_ocmb_errl;

            TRACISTEP("parallel_for_each boot_all_proc_ocmbs: WORKING ON HUID=0x%X", get_huid(i_ocmb));

            do
            {
                if (UTIL::isOdysseyChip(i_ocmb))
                {
                    l_ocmb_errl = ody_attribute_setup(i_ocmb);
                    if (l_ocmb_errl)
                    {
                        TRACISTEP("parallel_for_each ody_attribute_setup: HUID=0x%X PROBLEM !", get_huid(i_ocmb));
                        break;
                    }
                }
                l_ocmb_errl = check_for_ready_work(i_ocmb);
                if (l_ocmb_errl)
                {
                    TRACISTEP("parallel_for_each check_for_ready_work: HUID=0x%X PROBLEM !", get_huid(i_ocmb));
                    break;
                }
                l_ocmb_errl = ocmb_idec_sync(i_ocmb);
                if (l_ocmb_errl)
                {
                    TRACISTEP("parallel_for_each ocmb_idec_sync: HUID=0x%X PROBLEM !", get_huid(i_ocmb));
                    break;
                }
                // ABOVE COMPLETES EXPLORER
                if (!UTIL::isOdysseyChip(i_ocmb))
                {
                    TRACISTEP("parallel_for_each DONE with EXPLORER HUID=0x%X", get_huid(i_ocmb));
                    break;
                }
                FAPI_INVOKE_HWP(l_ocmb_errl, ody_sppe_config_update, { i_ocmb });
                if (l_ocmb_errl)
                {
                    TRACISTEP("parallel_for_each ody_sppe_config_update: HUID=0x%X PROBLEM ! ", get_huid(i_ocmb));
                    break;
                }
                FAPI_INVOKE_HWP(l_ocmb_errl, ody_cbs_start, { i_ocmb });
                if (l_ocmb_errl)
                {
                    TRACISTEP("parallel_for_each ody_cbs_start: HUID=0x%X PROBLEM !", get_huid(i_ocmb));
                    break;
                }
                FAPI_INVOKE_HWP(l_ocmb_errl, ody_sppe_check_for_ready, { i_ocmb });
                if (l_ocmb_errl)
                {
                    TRACISTEP("parallel_for_each HWP ody_sppe_check_for_ready: HUID=0x%X PROBLEM !", get_huid(i_ocmb));
                    break;
                }
            } while (false);

            if (UTIL::isOdysseyChip(i_ocmb))
            {
                l_ocmb_errl = handle_ody_upd_hwps_done(i_ocmb, move(l_ocmb_errl), proc_reboot_odysseys);

                if (l_ocmb_errl)
                {
                    TRACISTEP("parallel_for_each handle_ody_upd_hwps_done: OCMB HUID=0x%X proc_reboot_odysseys=%d",
                              get_huid(i_ocmb), proc_reboot_odysseys);
                    captureError(move(l_ocmb_errl), io_iStepError, HWPF_COMP_ID, i_ocmb);
                    goto EXIT_OCMBS;
                }

                if (proc_reboot_odysseys)
                {
                    TRACISTEP("parallel_for_each boot_all_proc_ocmbs: OCMB HUID=0x%X proc_reboot_odysseys=%d EXIT_OCMBS",
                              get_huid(i_ocmb), proc_reboot_odysseys);
                    goto EXIT_OCMBS;
                }

                if (!i_ocmb->getAttr<ATTR_HWAS_STATE>().functional)
                {
                    TRACISTEP("parallel_for_each boot_all_proc_ocmbs: OCMB HUID=0x%X proc_reboot_odysseys=%d DECONFIG EXIT_OCMBS",
                              get_huid(i_ocmb), proc_reboot_odysseys);
                    goto EXIT_OCMBS;
                }

                errlOwner no_error = nullptr; // no error for this call
                l_ocmb_errl = ody_upd_process_event(i_ocmb,
                                                    CHECK_FOR_READY_COMPLETED,
                                                    no_error,
                                                    proc_reboot_odysseys);

                if (l_ocmb_errl)
                {
                    TRACISTEP("parallel_for_each ody_upd_process_event: OCMB HUID=0x%X proc_reboot_odysseys=%d",
                              get_huid(i_ocmb), proc_reboot_odysseys);
                    UdSPPECodeLevels(i_ocmb).addToLog(l_ocmb_errl);
                    captureError(move(l_ocmb_errl), io_iStepError, HWPF_COMP_ID, i_ocmb);
                    goto EXIT_OCMBS;
                }
            }
            else // EXPLORER
            {
                if (l_ocmb_errl)
                {
                    TRACISTEP("parallel_for_each boot_all_proc_ocmbs: EXPLORER failed HUID=0x%X", get_huid(i_ocmb));
                    captureError(move(l_ocmb_errl), io_iStepError, HWPF_COMP_ID, i_ocmb);
                }
            }

        EXIT_OCMBS:
            return nullptr; // No error should be passed back from the parallel_for_each
        }); // parallel_for_each i_ocmb

        if (proc_reboot_odysseys) // ODYSSEY ONLY PATH BELOW, EXPLORER will NOT set proc_reboot_odysseys
        {
            getChildAffinityTargets(l_functionalOcmbChipList, // this will re-seed the OCMBs to cycle again
                                    i_proc,
                                    CLASS_CHIP,
                                    TYPE_OCMB_CHIP,
                                    true /* functional */);

            // After Odyssey restarts, clear their code levels
            std::for_each(begin(l_functionalOcmbChipList),
                          end(l_functionalOcmbChipList),
                          clear_ody_code_levels_state);

            FAPI_INVOKE_HWP(l_errl, p10_ocmb_enable, { i_proc }); // PROC level, ALL Odysseys reboot, Odyssey ONLY path here

            if (l_errl)
            {
                TRACISTEP(ERR_MRK"boot_all_proc_ocmbs: PROBLEM restarting all Odysseys under PROC HUID=0x%X", get_huid(i_proc));
                captureError(l_errl, io_iStepError, HWPF_COMP_ID, i_proc);
                break;
            }
        }
    } // end while (!l_functionalOcmbChipList.empty())

    TRACISTEP(EXIT_MRK"boot_all_proc_ocmbs: HUID=0x%X", get_huid(i_proc));
    return l_errl;
}

/** @brief Called when all of the check_for_ready HWPs have been invoked on the given OCMB,
 *  whether they failed or not. This function handles errors and checks the code version
 *  running on the OCMB if possible.
 *
 *  @param[in]     i_ocmb               The OCMB.
 *  @param[in/out] io_hwpErrl           Any error returned by a HWP.
 *  @param[out]    o_restart_needed     Set to true if the Odyssey code update
 *                                      FSM indicates that the OCMB needs to run
 *                                      through check_for_ready again.
 *
 *  @return    errlOwner                Error if any, otherwise nullptr.
 *                                       If an error is returned, it means that the
 *                                       IPL should be halted with the given error.
 */
errlOwner handle_ody_upd_hwps_done(Target* const i_ocmb,
                                   errlOwner i_hwpErrl,
                                   bool& o_restart_needed)
{
    auto l_fsm_errl = move(i_hwpErrl);

    ody_upd_event_t l_event = NO_EVENT;

    if (l_fsm_errl)
    {
        l_event = OCMB_BOOT_ERROR_NO_FFDC;
    }

    // Check whether the SBE is running or not.
    if (!l_fsm_errl || !l_fsm_errl->hasUserData1(fapi2::RC_POZ_SPPE_NOT_READY_ERR))
    {
        // If the SPPE isn't halted, then we check for async ffdc.
        // Grab any async FFDC. If there is any async FFDC generated,
        // SPPE will by design attach all of the FFDC to the response to
        // NEXT chip-op that comes in, whatever it may be. So, we need to
        // explicitly check for FFDC as soon as SPPE is up.
        // If we do get any error logs back from this, we'll
        // aggregate them all into one error log and that will be
        // passed to the FSM to decide what to do with them.

        bool async_ffdc = false;
        if (errlOwner l_errlLocal(ody_has_async_ffdc(i_ocmb, async_ffdc)); async_ffdc)
        { // ignore any error from ody_has_async_ffdc; we don't care whether it fails.
            auto async_ffdc_errls = genFifoSBEFFDCErrls(i_ocmb);

            if (!async_ffdc_errls.empty())
            {
                l_event = OCMB_BOOT_ERROR_WITH_FFDC;
                aggregate(l_fsm_errl, move(async_ffdc_errls));
            }
        }
    }
    else
    {
        TRACISTEP("handle_ody_upd_hwps_done(0x%08X): RC_POZ_SPPE_NOT_READY_ERR indicates "
                  "that the SBE is not running",
                  get_huid(i_ocmb));

        OdysseySbeRetryHandler retry_handler(i_ocmb);
        auto halted_rc = hbstd::own(retry_handler.ExtractRC());

        if (halted_rc)
        {
            TRACISTEP("handle_ody_upd_hwps_done(0x%08X): ody_extract_sbe_rc returned 0x%08X",
                      get_huid(i_ocmb),
                      ERRL_GETEID_SAFE(halted_rc));

            aggregate(l_fsm_errl, move(halted_rc));
        }
    }

    if (l_event != OCMB_BOOT_ERROR_NO_FFDC)
    { // Read the code levels if there was no error. If there is async
      // FFDC, we also might be able to read the code levels.
        if (i_ocmb->getAttr<ATTR_SBE_NUM_CAPABILITIES>() == 0)
        {
            // This attr is unset, so run the get code levels chipop to pull
            // the data which contains the number of capabilities supported

            if (auto l_local_errl = hbstd::own(sendGetCodeLevelsRequest(i_ocmb)))
            {
                TRACISTEP("handle_ody_upd_hwps_done: sendGetCodeLevelsRequest "
                          "failed on OCMB 0x%X", get_huid(i_ocmb));

                // If we can't get code levels, treat this as a boot failure with
                // no async FFDC
                l_event = OCMB_BOOT_ERROR_NO_FFDC;

                aggregate(l_fsm_errl, move(l_local_errl));
            }
        }

        if (l_event != OCMB_BOOT_ERROR_NO_FFDC
            && SPPE_BOOT_SIDE_GOLDEN != i_ocmb->getAttr<TARGETING::ATTR_OCMB_BOOT_SIDE>())
        {
            // getCapabilities is not supported with GOLDEN image
            //  *This chipop did not make it into the GOLDEN image in time, and
            //   and the golden image is now locked.

            if (auto l_local_errl = hbstd::own(getFifoSbeCapabilities(i_ocmb)))
            {
                TRACISTEP("handle_ody_upd_hwps_done: getFifoSbeCapabilities "
                          "failed on OCMB 0x%X", get_huid(i_ocmb));

                // If we can't get capabilities, treat this as a boot failure
                // with no async FFDC
                l_event = OCMB_BOOT_ERROR_NO_FFDC;

                aggregate(l_fsm_errl, move(l_local_errl));
            }
        }
    }

    errlOwner l_return_errl;

    if (odysseyCodeUpdateSupported()) // no point in doing anything if we have
                                      // no Odyssey images in PNOR.
    {
        if (l_event != OCMB_BOOT_ERROR_NO_FFDC)
        { // If there was an ERROR_NO_FFDC, the SBE is dead and we don't
          // know the code levels.
            set_ody_code_levels_state(i_ocmb);
        }

        if (l_fsm_errl)
        {
            // Pass any HWP error to the code update FSM and let it tell us what to do.

            UdSPPECodeLevels(i_ocmb).addToLog(l_fsm_errl);
            l_fsm_errl->addHwCallout(i_ocmb,
                                     HWAS::SRCI_PRIORITY_HIGH,
                                     HWAS::DECONFIG,
                                     HWAS::GARD_NULL);
            l_return_errl = ody_upd_process_event(i_ocmb,
                                                  l_event,
                                                  move(l_fsm_errl),
                                                  o_restart_needed);
        }
    }
    else
    { // return the error we were going to pass to the FSM, if code
      // update isn't supported.
        l_return_errl = move(l_fsm_errl);
    }

    return l_return_errl;
}

void* call_ocmb_check_for_ready (void *io_pArgs)
{
    TRACISTEP(ENTER_MRK"call_ocmb_check_for_ready");

    errlHndl_t l_errl = nullptr;
    IStepError l_StepError;

    do
    {

    // We need to do an explicit delay before our first i2c operation
    //  to the OCMBs to ensure we don't catch them too early in the boot
    //  and lock them up.
    const auto ocmb_delay = UTIL::assertGetToplevelTarget()
      ->getAttr<ATTR_OCMB_RESET_DELAY_SEC>();
    nanosleep(ocmb_delay,0);

    TargetHandleList functionalProcChipList;

    getAllChips(functionalProcChipList, TYPE_PROC, true);
    ISTEP::parallel_for_each(composable(getAllChips)(TYPE_PROC, true),
                                                   l_StepError,
                                                   "boot_all_proc_ocmbs",
                                                   [&](Target* const i_proc)
    {
        return boot_all_proc_ocmbs(i_proc, l_StepError);
    });

    const auto reconfig = UTIL::assertGetToplevelTarget()->getAttr<TARGETING::ATTR_RECONFIGURE_LOOP>();
    if ( (!l_StepError.isNull()) || reconfig )
        {
        TRACISTEP(ERR_MRK"call_ocmb_check_for_ready: ISTEPERROR or RECONFIG encountered");
                    goto FAIL_ISTEP;
    }

    // Loop thru the list of processors and send Memory config info to SBE
    for (auto &l_procTarget: functionalProcChipList)
    {
        l_errl = psuSendSbeMemConfig(l_procTarget);

        if (l_errl)
        {
            TRACISTEP(ERR_MRK"ERROR : call_ocmb_check_for_ready HWP(): "
                      "psuSendSbeMemConfig failed HUID=0x%X"
                      TRACE_ERR_FMT,
                      get_huid(l_procTarget),
                      TRACE_ERR_ARGS(l_errl));

            // Commit the error and not fail this istep due to this failure
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACISTEP(INFO_MRK"SUCCESS : call_ocmb_check_for_ready HWP(): "
                      "psuSendSbeMemConfig completed ok HUID=0x%X",
                      get_huid(l_procTarget));
        }
    } // for (auto &l_procTarget: functionalProcChipList)

    // Set ATTR_ATTN_CHK_OCMBS to let ATTN know that we may now get attentions
    // from Odyssey, but interrupts from the OCMB are not enabled yet.
    TargetHandleList l_allOCMBs;
    getAllChips(l_allOCMBs, TYPE_OCMB_CHIP, true);
    for (const auto l_ocmb : l_allOCMBs)
    {
        if (UTIL::isOdysseyChip(l_ocmb))
        {
            TRACISTEP("call_ocmb_check_for_ready: Enable attention processing for Odyssey OCMBs");
            UTIL::assertGetToplevelTarget()->setAttr<ATTR_ATTN_CHK_OCMBS>(1);
        }
        // There can be no mixing of OCMB types so only need to check one
        break;
    }
    // Enable scoms via the Odyssey SBE now that the the SBE is running
    // and we can send it chipops
    for (const auto l_ocmb : l_allOCMBs)
    {
        if (UTIL::isOdysseyChip(l_ocmb))
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

    } while (false); // outer do

 FAIL_ISTEP:

    TRACISTEP(EXIT_MRK"call_ocmb_check_for_ready");
    return l_StepError.getErrorHandle();
}

};
