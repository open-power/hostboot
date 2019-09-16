/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/workarounds/p9a_omi_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

///
/// @file p9a_omi_workarounds.C
/// @brief Workarounds for p9a_omi_* procedures
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <lib/shared/axone_defaults.H>
#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fld.H>
#include <p9a_mc_scom_addresses_fixes.H>
#include <p9a_mc_scom_addresses_fld_fixes.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <lib/mc/omi.H>
#include <lib/mc/omi_traits.H>
#include <lib/workarounds/p9a_omi_workarounds.H>

namespace mss
{
namespace workarounds
{
namespace mc
{
///
/// @brief Helper function to determine whether PRBS OMI workaround will be performed, that can be unit tested
///
/// @param[in] i_ocmb_type OCMB type/name
/// @param[in] i_proc_type PROC type/name
/// @return true/false perform workaround
///
bool is_prbs_omi_required(const uint8_t i_ocmb_type, const uint8_t i_proc_type)
{
    // OMI Workaround Logic:
    // Explorer+Axone: OMI/PROC-side workaround off
    // Gemini+Axone: OMI/PROC-side workaround on
    // Any+apollo: OMI/PROC-side workaround on
    // P10: No workarounds required. Enums don't exist yet, so this must be revisited later
    return ((i_proc_type != fapi2::ENUM_ATTR_NAME_AXONE) || (i_ocmb_type == fapi2::ENUM_ATTR_NAME_GEMINI)); // Gem && axone
}

///
/// @brief Helper function to determine whether PRBS axone OMI workarounds will be performed, that can be unit tested
///
/// @param[in] i_ocmb_type OCMB type/name
/// @param[in] i_proc_type PROC type/name
/// @return true/false perform workaround
///
bool is_prbs_omi_axone_required(const uint8_t i_ocmb_type, const uint8_t i_proc_type)
{
    // OMI Workaround Logic:
    // Explorer+Axone: Workaround on.
    // Else: None
    return ((i_proc_type == fapi2::ENUM_ATTR_NAME_AXONE)
            && (i_ocmb_type == fapi2::ENUM_ATTR_NAME_EXPLORER)); // Explorer && axone
}

///
/// @brief Perform PRBS delay from prbs time and sim attributes
///
/// @param[in] i_omi OMI target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode prbs_delay(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi)
{
    uint8_t l_sim = 0;
    uint32_t l_prbs_time = 0;
    uint64_t l_prbs_time_scaled = 0;

    FAPI_TRY( mss::attr::get_is_simulation( l_sim) );

    FAPI_TRY(mss::attr::get_omi_dl_preipl_prbs_time(i_omi, l_prbs_time),
             "Error from FAPI_ATTR_GET (ATTR_OMI_DL_PREIPL_PRBS_TIME)");
    l_prbs_time_scaled = l_prbs_time * mss::common_timings::DELAY_1MS;

    FAPI_TRY(fapi2::delay(l_prbs_time_scaled, mss::common_timings::DELAY_1US));
    FAPI_DBG("OMI Training Pre-ipl PRBS Time = %dns",
             (l_sim ? mss::common_timings::DELAY_1US : l_prbs_time_scaled));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get PROC and OCMB types
///
/// @param[in] i_ocmb_chip OCMB chip
/// @param[in] i_proc_chip PROC chip
/// @param[out] o_required workaround required
/// @return FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode get_ocmb_proc_types(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_chip,
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_proc_chip,
    uint8_t& o_ocmb_type,
    uint8_t& o_proc_type)
{
    FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, i_ocmb_chip, o_ocmb_type),
             "Error getting ATTR_NAME of %s", mss::c_str(i_ocmb_chip));

    FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, i_proc_chip, o_proc_type),
             "Error getting ATTR_NAME of %s", mss::c_str(i_proc_chip));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform the PRBS OMI workaround for gemini configurations
///
/// @param[in] i_omi OMI
/// @param[in] i_dl_x4_backoff_en backoff enable bit
/// @return fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode omi_training_prbs_gem(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI> i_omi,
    const uint8_t i_dl_x4_backoff_en)
{
    FAPI_DBG("Performing PRBS OMI workaround on %s", mss::c_str(i_omi));

    // *_CONFIG0 should be the last one written, since it starts the training.
    // We are not using the pre-ipl PRBS auto training mode because it doesn't function properly in Axone

    // Enable training state 6 to send TS3
    FAPI_TRY(mss::mc::setup_mc_config0(i_omi, mss::omi::train_mode::TX_TRAINING_STATE3, i_dl_x4_backoff_en));

    FAPI_TRY(prbs_delay(i_omi));

    // Enable training state 1 to send Pattern A
    FAPI_TRY(mss::mc::setup_mc_config0(i_omi, mss::omi::train_mode::TX_PATTERN_A, i_dl_x4_backoff_en));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform p9a_omi_train workaround for Axone+Explorer
///
/// @param[in] i_omi OMI target
/// @param[in] i_dl_x4_backoff_en backoff enable field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode omi_training_prbs(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI> i_omi,
    const uint8_t i_dl_x4_backoff_en)
{
    FAPI_DBG("Performing OMI Train axone workaround on %s", mss::c_str(i_omi));

    // Training mode 1: send Pattern A
    FAPI_TRY(mss::mc::setup_mc_config0(i_omi, mss::omi::train_mode::TX_PATTERN_A, i_dl_x4_backoff_en));

    FAPI_TRY(fapi2::delay(100 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform p9a_omi_setup (pre-training) workaround for Axone+Explorer
///
/// @param[in] i_omi OMI target
/// @param[in] i_dl_x4_backoff_en backoff enable field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode pre_omi_training_prbs(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI> i_omi,
    const uint8_t i_dl_x4_backoff_en)
{
    FAPI_DBG("Performing OMI Setup axone workaround on %s", mss::c_str(i_omi));

    // Training mode 4: send State 1
    FAPI_TRY(mss::mc::setup_mc_config0(i_omi, mss::omi::train_mode::TX_TRAINING_STATE1, i_dl_x4_backoff_en));

    FAPI_TRY(prbs_delay(i_omi));

fapi_try_exit:
    return fapi2::current_err;
}

} // mc
} // workarounds
} // mss
