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
#include <chipids.H>

// Explorer error logs
#include <expscom/expscom_errlog.H>

// sendProgressCode
#include <initservice/istepdispatcherif.H>

// Code update
#include <expupd/expupd.H>
#include <expupd/ocmbFwImage.H>

using namespace ISTEPS_TRACE;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

#define TRACF(...) TRACFCOMP(g_trac_isteps_trace, __VA_ARGS__)

using namespace expupd;
using namespace SBEIO;

namespace ISTEP_11
{

/** brief Add callouts and collect traces for the given Odyssey code
 *  update error. Deconfigure the given OCMB (delayed).
 */
void handle_odyssey_code_update_error(IStepError& i_stepError,
                                      errlHndl_t& i_errl,
                                      const Target* const i_ocmb)
{
    i_errl->collectTrace(SBEIO_COMP_NAME);
    i_errl->collectTrace(I2CR_COMP_NAME);
    i_errl->collectTrace(EXPUPD_COMP_NAME);

    i_errl->addHwCallout(i_ocmb,
                         HWAS::SRCI_PRIORITY_HIGH,
                         HWAS::DELAYED_DECONFIG,
                         HWAS::GARD_NULL);

    captureError(i_errl, i_stepError, ISTEP_COMP_ID, i_ocmb);
}

/**
 * @brief List of pairs of the image level currently flashed on the
 *        SBE, and a pointer to new image contents in the OCMBFW PNOR
 *        partition for that image type.
 */
using cur_version_new_image_t = std::vector<std::pair<codelevel_info_t, const ocmbfw_ext_image_info*>>;

/**
 * @brief Write a set of firmware images to the given Odyssey chip.
 *
 * @param[in] i_ocmb              The Odyssey chip.
 * @param[in] i_fwhdr             The OCMBFW PNOR partition header pointer.
 * @param[in] i_updates_required  The images to write.
 */
errlHndl_t odyssey_update_code(Target* const i_ocmb,
                               const ocmbfw_owning_ptr_t& i_fwhdr,
                               const cur_version_new_image_t& i_updates_required)
{
    TRACF(ENTER_MRK"call_ocmb_check_for_ready/odyssey_update_code(0x%08X)",
          get_huid(i_ocmb));

    errlHndl_t errl = nullptr;

    for (const auto [ clip, img ] : i_updates_required)
    {
        TRACF("call_ocmb_check_for_ready/odyssey_update_code(0x%08X): "
              "Updating firmware image %d...",
              get_huid(i_ocmb),
              clip.type);

 #if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
        CONSOLE::displayf(CONSOLE::DEFAULT, nullptr,
                          "Updating firmware image %d on Odyssey chip 0x%08X",
                          clip.type, get_huid(i_ocmb));
 #endif

        errl = sendUpdateImageRequest(i_ocmb,
                                      clip,
                                      get_ext_image_contents(i_fwhdr.get(), img),
                                      img->image_size);

        if (errl)
        {
            TRACF("call_ocmb_check_for_ready/odyssey_update_code(0x%08X): "
                  "sendUpdateImageRequest(type=%d) failed: " TRACE_ERR_FMT,
                  get_huid(i_ocmb),
                  clip.type,
                  TRACE_ERR_ARGS(errl));
            break;
        }
        else
        {
            TRACF("call_ocmb_check_for_ready/odyssey_update_code(0x%08X): "
                  "Update completed successfully",
                  get_huid(i_ocmb));
        }
    }

    TRACF(EXIT_MRK"call_ocmb_check_for_ready/odyssey_update_code(0x%08X) = 0x%08X",
          get_huid(i_ocmb), ERRL_GETPLID_SAFE(errl));

    return errl;
}

/** @brief Convert a numeric value from 0-15 to a hex character representing it.
 */
char char_to_hex(uint8_t value)
{
    value = value & 0xF;
    if (value < 10) return '0' + value;
    return 'A' + (value - 10);
}

/**
 * @brief Convert a byte string to a human-readable hexadecimal representation.
 *
 * @param[out] o_buf       The output buffer (must contain at 2*i_bytes_len + 1 elements)
 * @param[in] i_bytes      The bytes to convert
 * @param[in] i_bytes_len  Number of bytes to convert
 */
void str_to_hex(char* const o_buf, const uint8_t* const i_bytes, const size_t i_bytes_len)
{
    for (size_t i = 0; i < i_bytes_len; ++i)
    {
        o_buf[i*2] = char_to_hex(i_bytes[i] >> 4);
        o_buf[i*2 + 1] = char_to_hex(i_bytes[i]);
    }

    o_buf[i_bytes_len * 2] = '\0';
}

/**
 * @brief Check which Odyssey images need to be updated in the given chip, compared
 *        to what exists in PNOR.
 *
 * @param[in] i_ocmb               The Odyssey chip.
 * @param[in] i_fwhdr              The OCMBFW PNOR partition header pointer.
 * @param[out] o_updates_required  The images needing update.
 * @return                         Error if any, otherwise nullptr.
 */
errlHndl_t check_for_odyssey_codeupdate_needed(Target* const i_ocmb,
                                               const ocmbfw_owning_ptr_t& i_fwhdr,
                                               cur_version_new_image_t& o_updates_required)
{
    TRACF(ENTER_MRK"call_ocmb_check_for_ready/check_for_odyssey_codeupdate_needed(0x%08X)",
          get_huid(i_ocmb));

    errlHndl_t errl = nullptr;

    do
    {

    const auto ec = i_ocmb->getAttr<ATTR_EC>();
    const auto dd_level_major = (ec & 0xF0) >> 4,
               dd_level_minor = (ec & 0x0F);

    /* Get the code levels on the Odyssey and see whether there are
     * any hash mismatches. */

    std::vector<codelevel_info_t> codelevels;
    errl = sendGetCodeLevelsRequest(i_ocmb, codelevels);

    if (errl)
    {
        break;
    }

    for (const auto& codelevel : codelevels)
    {
        image_type_t image_type = { };
        const char* image_type_str = nullptr;

        switch (codelevel.type)
        {
        case codelevel_info_t::bootloader:
            image_type = IMAGE_TYPE_BOOTLOADER;
            image_type_str = "bootloader";
            break;
        case codelevel_info_t::runtime:
            image_type = IMAGE_TYPE_RUNTIME;
            image_type_str = "runtime";
            break;
        }

        /* Find the appropriate image in PNOR to compare hashes with. */

        const ocmbfw_ext_image_info* img = nullptr;
        errl = find_ocmbfw_ext_image(img, i_fwhdr.get(), OCMB_TYPE_ODYSSEY, image_type,
                                     dd_level_major, dd_level_minor);

        if (errl)
        {
            TRACF("check_for_odyssey_codeupdate_needed: Cannot locate image with ocmb type = %d, "
                  "image type = %d, dd = %d.%d in OCMBFW PNOR partition",
                  OCMB_TYPE_ODYSSEY, image_type, dd_level_major, dd_level_minor);
            break;
        }

        static_assert(sizeof(img->image_hash) == sizeof(codelevel.hash));

        /* If the hashes don't match, we need to update this image. */

        if (memcmp(&img->image_hash, &codelevel.hash, sizeof(img->image_hash)))
        {
            char flashed_hash_str[25] = { }, hb_hash_str[25] = { };
            str_to_hex(flashed_hash_str, codelevel.hash, (sizeof(flashed_hash_str) - 1) / 2);
            str_to_hex(hb_hash_str, img->image_hash, (sizeof(hb_hash_str) - 1) / 2);

            TRACF("check_for_odyssey_codeupdate_needed: OCMB 0x%08X %s needs update "
                  "(flashed level = %s, hostboot's level = %s)",
                  get_huid(i_ocmb), image_type_str, flashed_hash_str, hb_hash_str);

            o_updates_required.push_back({ codelevel, img });
        }
        else
        {
            TRACF("check_for_odyssey_codeupdate_needed: OCMB 0x%08X %s does NOT need update",
                  get_huid(i_ocmb), image_type_str);
        }
    }

    } while (false);

    TRACF(EXIT_MRK"call_ocmb_check_for_ready/check_for_odyssey_codeupdate_needed");

    return errl;
}

void* call_ocmb_check_for_ready (void *io_pArgs)
{
    TRACF(ENTER_MRK"call_ocmb_check_for_ready");

    errlHndl_t l_errl = nullptr;
    IStepError l_StepError;

    do
    {

    bool perform_odyssey_codeupdate_check = true;
    const auto ocmbfw_pnor_section_header = load_ocmbfw_pnor_section(l_errl);

    if (l_errl)
    {
        TRACF("call_ocmb_check_for_ready: load_ocmbfw_pnor_section failed: "
              TRACE_ERR_FMT,
              TRACE_ERR_ARGS(l_errl));

        TRACF("call_ocmb_check_for_ready: Ignoring error until support for "
              "OCMBFW PNOR partition version 1 is dropped");

        // @TODO: Capture this error when OCMBFW V1 support is deprecated
        delete l_errl;
        l_errl = nullptr;

        //captureError(l_errl, l_StepError, ISTEP_COMP_ID);

        perform_odyssey_codeupdate_check = false;
    }

    // We need to do an explicit delay before our first i2c operation
    //  to OCMB to ensure we don't catch it too early in the boot
    //  and lock it up.
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

        if(UTIL::assertGetToplevelTarget()->getAttr<TARGETING::ATTR_OCMB_ISTEP_MODE>())
        {
            const uint32_t l_ocmb_istep_mode_enable_mask = 0xC0000000; // set bit 0 and bit 1, 0x00 = autoboot 0x11=istep mode
            // later in HWP's the ATTR_OCMB_BOOT_FLAGS will be used to properly boot the Odyssey SPPE
            uint32_t l_attr_ocmb_boot_flags = UTIL::assertGetToplevelTarget()->getAttr<ATTR_OCMB_BOOT_FLAGS>();
            l_attr_ocmb_boot_flags |= l_ocmb_istep_mode_enable_mask;
            TRACFCOMP(g_trac_isteps_trace, "call_ocmb_check_for_ready setAttr ATTR_OCMB_BOOT_FLAGS=0x%X", l_attr_ocmb_boot_flags);
            UTIL::assertGetToplevelTarget()->setAttr<TARGETING::ATTR_OCMB_BOOT_FLAGS>(l_attr_ocmb_boot_flags);
        }

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
                // Odyssey chips require a few more HWPs to run to start them up:
                // ody_sppe_config_update writes the SPPE config
                // ody_cbs_start starts SPPE
                // ody_sppe_check_for_ready makes sure that SPPE booted correctly

                if(l_ocmb->getAttr<TARGETING::ATTR_CHIP_ID>() == POWER_CHIPID::ODYSSEY_16)
                {
                    FAPI_INVOKE_HWP(l_errl, ody_sppe_config_update, l_fapi_ocmb_target);
                    if(l_errl)
                    {
                        TRACF("call_ocmb_check_for_ready: ody_sppe_config failed on OCMB 0x%x", get_huid(l_ocmb));
                        captureError(l_errl, l_StepError, HWPF_COMP_ID, l_ocmb);
                    }

                    FAPI_INVOKE_HWP(l_errl, ody_cbs_start, l_fapi_ocmb_target);
                    if(l_errl)
                    {
                        TRACF("call_ocmb_check_for_ready: ody_cbs_start failed on OCMB 0x%x", get_huid(l_ocmb));
                        captureError(l_errl, l_StepError, HWPF_COMP_ID, l_ocmb);
                    }

                    FAPI_INVOKE_HWP(l_errl, ody_sppe_check_for_ready, l_fapi_ocmb_target);

                    do
                    {

                    if(l_errl)
                    {
                        // TODO JIRA: PFHB-257 Handle Odyssey boot failures
                        TRACF("call_ocmb_check_for_ready: ody_sppe_check_for_ready failed on OCMB 0x%x",
                              get_huid(l_ocmb));
                        captureError(l_errl, l_StepError, HWPF_COMP_ID, l_ocmb);
                        break;
                    }

                    if (perform_odyssey_codeupdate_check)
                    {
                        cur_version_new_image_t updates_needed;
                        l_errl = check_for_odyssey_codeupdate_needed(l_ocmb,
                                                                     ocmbfw_pnor_section_header,
                                                                     updates_needed);

                        if (l_errl)
                        {
                            handle_odyssey_code_update_error(l_StepError, l_errl, l_ocmb);
                            break;
                        }

                        if (!updates_needed.empty())
                        {
                            l_errl = odyssey_update_code(l_ocmb,
                                                         ocmbfw_pnor_section_header,
                                                         updates_needed);
                        }

                        if (l_errl)
                        {
                            handle_odyssey_code_update_error(l_StepError, l_errl, l_ocmb);
                            break;
                        }
                    }

                    } while (false);
                }
            } // End of if/else l_errl
        } // End of OCMB Loop

        // Grab informational Explorer logs (early IPL = true)
        EXPSCOM::createExplorerLogs(l_functionalOcmbChipList, true);
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

    TRACF(EXIT_MRK"call_ocmb_check_for_ready");
    return l_StepError.getErrorHandle();
}

};
