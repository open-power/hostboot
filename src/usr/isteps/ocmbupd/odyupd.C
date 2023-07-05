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

using namespace HWAS;
using namespace ERRORLOG;
using namespace TARGETING;
using namespace ISTEP_ERROR;

#define TRACF(...) TRACFCOMP(g_trac_ocmbupd, __VA_ARGS__)

using namespace ocmbupd;
using namespace SBEIO;

namespace ocmbupd
{

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
                               const ocmbfw_owning_ptr_t& i_fwhdr,
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
                                      get_ext_image_contents(i_fwhdr.get(), img),
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
errlHndl_t check_for_odyssey_codeupdate_needed(Target* const i_ocmb,
                                               const ocmbfw_owning_ptr_t& i_fwhdr,
                                               ody_cur_version_new_image_t& o_updates_required,
                                               uint64_t* const o_rt_hash_prefix,
                                               uint64_t* const o_bldr_hash_prefix)
{
    TRACF(ENTER_MRK"check_for_odyssey_codeupdate_needed(0x%08X)",
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

    std::sort(begin(codelevels), end(codelevels),
              [](const codelevel_info_t& lhs, const codelevel_info_t& rhs)
              {
                  // Each type should only appear once in the vector.
                  return lhs.type < rhs.type;
              });

    // If the bootloader needs to be updated, then we will always
    // update the runtime, because a change in size of the bootloader
    // can cause the runtime to break (even if the runtime hash
    // doesn't change). We will always evaluate the bootloader image
    // before the runtime image (so that this variable will be set in
    // time for the check) because of the sort above.
    bool bootloader_needs_update = false;

    for (const auto& codelevel : codelevels)
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
        errl = find_ocmbfw_ext_image(img, i_fwhdr.get(), OCMB_TYPE_ODYSSEY, image_type,
                                     dd_level_major, dd_level_minor);

        if (errl)
        {
            TRACF("check_for_odyssey_codeupdate_needed: Cannot locate image with ocmb type = %d, "
                  "image type = %d, dd = %d.%d in OCMBFW PNOR partition; skipping firmware update",
                  OCMB_TYPE_ODYSSEY, image_type, dd_level_major, dd_level_minor);
            delete errl;
            errl = nullptr;
            break;
        }

        static_assert(sizeof(img->image_hash) == sizeof(codelevel.hash));

        /* If the hashes don't match (or if the bootloader needs
           updating and this image is the runtime image (see comments
           for bootloader_needs_update)), we need to update this
           image. */

        if ((bootloader_needs_update && (codelevel.type == codelevel_info_t::runtime))
             || memcmp(&img->image_hash, &codelevel.hash, sizeof(img->image_hash)))
        {
            char flashed_hash_str[25] = { }, hb_hash_str[25] = { };
            str_to_hex(flashed_hash_str, codelevel.hash, (sizeof(flashed_hash_str) - 1) / 2);
            str_to_hex(hb_hash_str, img->image_hash, (sizeof(hb_hash_str) - 1) / 2);

            TRACF("check_for_odyssey_codeupdate_needed: OCMB 0x%08X %s needs update "
                  "(flashed level = %s, hostboot's level = %s)",
                  get_huid(i_ocmb), image_type_str, flashed_hash_str, hb_hash_str);

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

    TRACF(EXIT_MRK"check_for_odyssey_codeupdate_needed = 0x%08X", ERRL_GETPLID_SAFE(errl));

    return errl;
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
errlHndl_t odysseyUpdateImages(Target* const i_ocmb,
                               const ocmbfw_owning_ptr_t& i_ocmbfw_pnor_partition)
{
    errlHndl_t errl = nullptr;

    do
    {

    if (UTIL::isOdysseyChip(i_ocmb))
    {
        ody_cur_version_new_image_t images_to_update;
        errl = check_for_odyssey_codeupdate_needed(i_ocmb,
                                                   i_ocmbfw_pnor_partition,
                                                   images_to_update);

        if (errl)
        {
            add_odyssey_callouts(errl, i_ocmb);
            break;
        }

        errl = odyssey_update_code(i_ocmb,
                                   i_ocmbfw_pnor_partition,
                                   images_to_update);

        if (errl)
        {
            add_odyssey_callouts(errl, i_ocmb);
            break;
        }
    }

    } while (false);

    return errl;
}

}
