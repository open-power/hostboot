/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/ocmbupd/odyupd.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

#include "ocmbupd_trace.H"

#include <istepHelperFuncs.H>
#include <console/consoleif.H>

#include <ocmbupd/ocmbupd.H>
#include <ocmbupd/ocmbFwImage.H>

#include <hwas/common/hwas.H>

#include <targeting/odyutil.H>
#include <ocmbupd_helpers.H>

using namespace HWAS;
using namespace ERRORLOG;
using namespace TARGETING;
using namespace ISTEP_ERROR;

#define TRACF(...) TRACFCOMP(g_trac_ocmbupd, __VA_ARGS__)

using namespace ocmbupd;
using namespace SBEIO;

namespace ocmbupd
{

// This is an owning handle to the OCMBFW PNOR partition, and is used
// for all PNOR accesses in this module.
ocmbupd::ocmbfw_owning_ptr_t OCMBFW_HANDLE;

// @TODO: JIRA PFHB-522 Delete this function when OCMBFW header v1 is dropped
bool odysseyCodeUpdateSupported()
{
    return OCMBFW_HANDLE != nullptr;
}

const char* codelevel_info_type_to_string(const codelevel_info_t::codelevel_info_type t)
{
    switch (t)
    {
    case codelevel_info_t::bootloader:
        return "bootloader";
    case codelevel_info_t::runtime:
        return "runtime";
    }

    return "UNKNOWN";
}

/**
 * @brief Write a set of firmware images to the given Odyssey chip.
 *
 * @param[in] i_ocmb              The Odyssey chip.
 * @param[in] i_fwhdr             The OCMBFW PNOR partition header pointer.
 * @param[in] i_updates_required  The images to write.
 */
errlHndl_t odyssey_update_code(Target* const i_ocmb,
                               const ody_cur_version_new_image_t& i_updates_required)
{
    TRACF(ENTER_MRK"odyssey_update_code(0x%08X)",
          get_huid(i_ocmb));

    errlHndl_t errl = nullptr;

    for (const auto [ clip, img ] : i_updates_required)
    {
        TRACF("odyssey_update_code(0x%08X): Updating %s firmware image...",
              get_huid(i_ocmb),
              codelevel_info_type_to_string(clip.type));

 #if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
        CONSOLE::displayf(CONSOLE::DEFAULT, nullptr,
                          "Updating %s firmware image on Odyssey chip 0x%08X",
                          codelevel_info_type_to_string(clip.type),
                          get_huid(i_ocmb));
 #endif

        errl = sendUpdateImageRequest(i_ocmb,
                                      clip,
                                      get_ext_image_contents(OCMBFW_HANDLE.get(), img),
                                      img->image_size);

        if (errl)
        {
            TRACF("odyssey_update_code(0x%08X): "
                  "sendUpdateImageRequest(type=%s) failed: " TRACE_ERR_FMT,
                  get_huid(i_ocmb),
                  codelevel_info_type_to_string(clip.type),
                  TRACE_ERR_ARGS(errl));
            break;
        }
        else
        {
            TRACF("odyssey_update_code(0x%08X): "
                  "Update completed successfully",
                  get_huid(i_ocmb));

 #if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
        CONSOLE::displayf(CONSOLE::DEFAULT, nullptr,
                          "Successfully updated %s firmware image on Odyssey chip 0x%08X",
                          codelevel_info_type_to_string(clip.type),
                          get_huid(i_ocmb));
 #endif
        }
    }

    TRACF(EXIT_MRK"odyssey_update_code(0x%08X) = 0x%08X",
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
 */
void check_for_odyssey_codeupdate_needed(Target* const i_ocmb,
                                         ody_cur_version_new_image_t& o_updates_required,
                                         uint64_t* const o_rt_hash_prefix,
                                         uint64_t* const o_bldr_hash_prefix,
                                         const bool i_force_all)
{
    TRACF(ENTER_MRK"check_for_odyssey_codeupdate_needed(0x%08X)",
          get_huid(i_ocmb));

    do
    {

    const auto ec = i_ocmb->getAttr<ATTR_EC>();
    const auto dd_level_major = (ec & 0xF0) >> 4,
               dd_level_minor = (ec & 0x0F);

    /* Get the code levels on the Odyssey and see whether there are
     * any hash mismatches. */
    std::vector<codelevel_info_t> l_codelevels;

    // create an ordered codelevel vector for the loop below, with the
    // bootloader coming first, before the runtime
    auto l_boot_codelevel    = i_ocmb->getAttrAsStdArr<ATTR_SBE_BOOTLOADER_CODELEVEL>();
    auto l_runtime_codelevel = i_ocmb->getAttrAsStdArr<ATTR_SBE_RUNTIME_CODELEVEL>();
    codelevel_info_t l_boot_info(codelevel_info_t::codelevel_info_type::bootloader,
                                 l_boot_codelevel.data());
    codelevel_info_t l_runtime_info(codelevel_info_t::codelevel_info_type::runtime,
                                    l_runtime_codelevel.data());
    l_codelevels.push_back(l_boot_info);   // push BOOTLOADER_CODELEVEL first
    l_codelevels.push_back(l_runtime_info);

    // If the bootloader needs to be updated, then we will always
    // update the runtime, because a change in size of the bootloader
    // can cause the runtime to break (even if the runtime hash
    // doesn't change). We will always evaluate the bootloader image
    // before the runtime image (so that this variable will be set in
    // time for the check).
    bool bootloader_needs_update = false;

    const auto is_golden_side = i_ocmb->getAttr<ATTR_SPPE_BOOT_SIDE>() == SPPE_BOOT_SIDE_GOLDEN;

    for (const auto& codelevel : l_codelevels)
    {
        image_type_t image_type = { };
        const char* image_type_str = nullptr;
        const uint64_t hash_prefix = *reinterpret_cast<const uint64_t*>(codelevel.hash);

        switch (codelevel.type)
        {
        case codelevel_info_t::bootloader:
            image_type = IMAGE_TYPE_BOOTLOADER;
            image_type_str = "bootloader";
            o_bldr_hash_prefix && (*o_bldr_hash_prefix = hash_prefix);
            break;
        case codelevel_info_t::runtime:
            image_type = IMAGE_TYPE_RUNTIME;
            image_type_str = "runtime";
            o_rt_hash_prefix && (*o_rt_hash_prefix = hash_prefix);
            break;
        }

        /* Find the appropriate image in PNOR to compare hashes with. */
        const ocmbfw_ext_image_info* img = nullptr;
        if (auto errl = find_ocmbfw_ext_image(img,
                                              OCMBFW_HANDLE.get(),
                                              OCMB_TYPE_ODYSSEY,
                                              image_type,
                                              dd_level_major,
                                              dd_level_minor))
        {
            TRACF("check_for_odyssey_codeupdate_needed: Cannot locate image with ocmb type = %d, "
                  "image type = %d, dd = %d.%d in OCMBFW PNOR partition; skipping firmware update",
                  OCMB_TYPE_ODYSSEY, image_type, dd_level_major, dd_level_minor);
            delete errl;
            break;
        }

        static_assert(sizeof(img->image_hash) == sizeof(codelevel.hash));

        // Set the measured hashes for secureboot comparison between measurements
        // from the Odyssey later.
        if(codelevel.type == codelevel_info_t::bootloader)
        {
            i_ocmb->setAttr<ATTR_SPPE_BOOTLOADER_MEASUREMENT_HASH>(img->measured_hash);
        }
        else if(codelevel.type == codelevel_info_t::runtime)
        {
            i_ocmb->setAttr<ATTR_SPPE_RUNTIME_MEASUREMENT_HASH>(img->measured_hash);
        }

        /* If the hashes don't match; or if the bootloader needs
           updating and this image is the runtime image (see comments
           for bootloader_needs_update); or if this is the golden side
           (the golden side is always considered out of date, because
           it's only used to do code update); or if the caller asked
           us to forcefully consider everything updateable; then we
           need to update this image. */

        if ((bootloader_needs_update && (codelevel.type == codelevel_info_t::runtime))
            || memcmp(&img->image_hash, &codelevel.hash, sizeof(img->image_hash))
            || is_golden_side
            || i_force_all)
        {
            char flashed_hash_str[25] = { }, hb_hash_str[25] = { };
            str_to_hex(flashed_hash_str, codelevel.hash, (sizeof(flashed_hash_str) - 1) / 2);
            str_to_hex(hb_hash_str, img->image_hash, (sizeof(hb_hash_str) - 1) / 2);

            TRACF("check_for_odyssey_codeupdate_needed: OCMB 0x%08X %s needs update "
                  "(flashed level = %s, hostboot's level = %s, override = %d)",
                  get_huid(i_ocmb), image_type_str, flashed_hash_str, hb_hash_str, i_force_all);

            o_updates_required.push_back({ codelevel, img });

            if (codelevel.type == codelevel_info_t::bootloader)
            {
                bootloader_needs_update = true;
            }
        }
        else
        {
            TRACF("check_for_odyssey_codeupdate_needed: OCMB 0x%08X %s does NOT need update",
                  get_huid(i_ocmb), image_type_str);
        }
    }

    } while (false);

    TRACF(EXIT_MRK"check_for_odyssey_codeupdate_needed");

    return;
}

/** @brief Add callouts and collect traces for the given Odyssey code
 *  update error. Deconfigure the given OCMB (delayed).
 */
void add_odyssey_callouts(errlHndl_t& i_errl, const Target* const i_ocmb)
{
    i_errl->collectTrace(SBEIO_COMP_NAME);
    i_errl->collectTrace(I2CR_COMP_NAME);
    i_errl->collectTrace(OCMBUPD_COMP_NAME);

    i_errl->addHwCallout(i_ocmb, SRCI_PRIORITY_HIGH, DELAYED_DECONFIG, GARD_NULL);
}

/**
 * @brief Update Odyssey OCMB firmware on the given target if necessary.
 */
errlHndl_t odysseyUpdateImages(Target* const i_ocmb, const bool i_force_update_all)
{
    errlHndl_t errl = nullptr;

    TRACF(ENTER_MRK"odysseyUpdateImages(0x%08X, i_on_update_force_all=%d)",
          get_huid(i_ocmb), i_force_update_all);

    do
    {

    if (UTIL::isOdysseyChip(i_ocmb))
    {
        ody_cur_version_new_image_t images_to_update;

        check_for_odyssey_codeupdate_needed(i_ocmb,
                                            images_to_update,
                                            nullptr,
                                            nullptr,
                                            i_force_update_all);

        errl = odyssey_update_code(i_ocmb, images_to_update);

        if (errl)
        {
            add_odyssey_callouts(errl, i_ocmb);
            break;
        }
    }

    } while (false);

    return errl;
}

/**
 * @brief Initialize the global OCMBWF PNOR partition handle.
 *
 * The returned handle will cause the PNOR partition to be unloaded
 * when this module is unloaded.
 */
int init_module_ocmbfw_pnor_handle()
{
    using namespace ISTEPS_TRACE;

    errlHndl_t errl = nullptr;

    OCMBFW_HANDLE = ocmbupd::load_ocmbfw_pnor_section(errl);

    if (errl)
    {
        TRACISTEP(ERR_MRK"init_module_ocmbfw_pnor_handle(): load_ocmbfw_pnor_section failed: "
                  TRACE_ERR_FMT,
                  TRACE_ERR_ARGS(errl));

        TRACISTEP(INFO_MRK"init_module_ocmbfw_pnor_handle: Ignoring error until support for "
                  "OCMBFW PNOR partition version 1 is dropped");

        // @TODO: JIRA PFHB-522 Capture this error when OCMBFW V1
        // support is deprecated, this should fail the boot
        delete errl;
        errl = nullptr;

        OCMBFW_HANDLE = nullptr;

        //captureError(errl, l_StepError, ISTEP_COMP_ID);
    }

    return 0;
}

// This is just a mechanism to call the function when this module is
// loaded.
static int ocmbfw_pnor_init = init_module_ocmbfw_pnor_handle();

/**
 *  @brief  Determines if the error is recoverable by I2C OCMB update.
 *          If recoverable, commits error as recovered and triggers reconfig loop.
 *          If not-recoverable, will act as normal captureError() call.
 *
 *  @note See captureErrorOcmbUpdateCheck for parameter documentation.
 */
void odysseyCaptureErrorOcmbUpdateCheck(errlHndl_t& io_err,
                                        ISTEP_ERROR::IStepError& io_stepError,
                                        const compId_t i_componentId,
                                        const TARGETING::Target* const i_target)
{
    static bool ody_fsm_global_event_processed = false; // we only want to do a
                                                        // notify-all-odysseys operation for
                                                        // a hwp fail at most one time per
                                                        // boot (because the fsm handler is
                                                        // not idempotent, and it doesn't
                                                        // care about the particular error
                                                        // when it happens on non-odyssey
                                                        // targets), so we use this flag to
                                                        // keep track of that.

    static bool restart_needed = false; // whether a notify-all-odysseys event triggered a
                                        // reconfig loop. If this is true, all the hwp
                                        // errors are marked as recovered.

    // We send the OTHER_HW_HWP_FAIL event to *all* the ocmbs. This lets them update if they
    // need to, in hopes that the code update will fix the error on the next boot. We only
    // want to do this one time at most in one boot (otherwise the fsm could think that a
    // separate event happened again; the event processing is not idempotent) so if we do
    // this once, we set a flag so that we don't do it again, and mark all the hwp errors as
    // recovered.

    if (!ody_fsm_global_event_processed)
    {
        TRACISTEP(INFO_MRK"odysseyCaptureErrorOcmbUpdateCheck: Broadcasting Odyssey code "
                  "update FSM event to all functional OCMBs");

        ody_fsm_global_event_processed = true;

        auto upd_errl = ody_upd_all_process_event(OTHER_HW_HWP_FAIL,
                                                  EVENT_ON_FUNCTIONAL_OCMBS,
                                                  REQUEST_RECONFIG_IF_NEEDED,
                                                  &restart_needed);

        if (upd_errl)
        {   // we had a real error that should halt the boot; commit the errors
            // as-is.
            TRACISTEP(ERR_MRK"odysseyCaptureErrorOcmbUpdateCheck: ody_upd_all_process_event "
                      "failed with error when handling event OTHER_HW_HWP_FAIL "
                      "for error on target 0x%08X "
                      TRACE_ERR_FMT,
                      get_huid(i_target),
                      TRACE_ERR_ARGS(upd_errl));

            captureError(move(upd_errl), io_stepError, i_componentId);
        }
    }

    if (restart_needed)
    {   // the call to ody_upd_all_process_event will have requested a reconfig
        // loop; just suppress the error here and let that happen. If it didn't
        // request a reconfig loop then that means it didn't do any code update and
        // there's no chance that it will fix the hwp error next boot, so we don't
        // modify the severity. (And if an error occurred, it won't have set
        // restart_needed.)
        TRACISTEP(INFO_MRK"odysseyCaptureErrorOcmbUpdateCheck: Setting error 0x%08X to RECOVERED",
                  ERRL_GETEID_SAFE(io_err));
        io_err->setSev(ERRL_SEV_RECOVERED);
    }

    io_err->collectTrace(ISTEP_COMP_NAME);
    errlCommit(io_err, i_componentId);

    TRACISTEP(EXIT_MRK"odysseyCaptureErrorOcmbUpdateCheck");
}

}
