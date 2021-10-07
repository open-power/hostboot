/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/workarounds/p10_omi_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_omi_workarounds.C
/// @brief Workarounds for p10_omi_* procedures
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <p10_scom_omic.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_generic_attribute_getters.H>
#include <lib/omi/p10_omi_utils.H>
#include <lib/workarounds/p10_omi_workarounds.H>

namespace mss
{
namespace workarounds
{
namespace omi
{
///
/// @brief Helper function to determine whether gem/apollo PRBS OMI workaround will be performed
///
/// @param[in] i_ocmb_type OCMB type/name
/// @param[in] i_proc_type PROC type/name
/// @return true/false perform workaround
///
bool is_gemini_apollo_prbs_required(const uint8_t i_ocmb_type, const uint8_t i_proc_type)
{
    // OMI Workaround Logic:
    // Explorer+P10: OMI/PROC-side workaround off
    // Gemini+P10: OMI/PROC-side workaround on
    // Any+apollo: OMI/PROC-side workaround on
    return ((i_proc_type != fapi2::ENUM_ATTR_NAME_P10) || (i_ocmb_type == fapi2::ENUM_ATTR_NAME_GEMINI));
}

///
/// @brief Helper function to determine whether p10-specific PRBS workaround is required
///
/// @param[in] i_ocmb_type OCMB type/name
/// @param[in] i_proc_type PROC type/name
/// @return true/false perform workaround
///
bool is_p10_prbs_required(const uint8_t i_ocmb_type, const uint8_t i_proc_type)
{
    // OMI Workaround Logic:
    // Explorer+P10: Workaround on.
    // Else: None
    return ((i_proc_type == fapi2::ENUM_ATTR_NAME_P10)
            && (i_ocmb_type == fapi2::ENUM_ATTR_NAME_EXPLORER));
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
/// @param[out] o_ocmb_type OCMB type ATTR_NAME enum
/// @param[out] o_proc_type PROC type ATTR_NAME enum
/// @return FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode get_ocmb_proc_types(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_chip,
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_chip,
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
fapi2::ReturnCode training_prbs_gem(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
    const uint8_t i_dl_x4_backoff_en)
{
    FAPI_DBG("Performing PRBS OMI workaround on %s", mss::c_str(i_omi));

    // OMI training workaround for gemini:
    // Enable training state 6 to send TS3
    FAPI_TRY(mss::omi::setup_mc_config0(i_omi, mss::omi::train_mode::TX_TRAINING_STATE3, i_dl_x4_backoff_en));

    FAPI_TRY(prbs_delay(i_omi));

    // Enable training state 1 to send Pattern A
    FAPI_TRY(mss::omi::setup_mc_config0(i_omi, mss::omi::train_mode::TX_PATTERN_A, i_dl_x4_backoff_en));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform p10_omi_train workaround for P10+Explorer
///
/// @param[in] i_omi OMI target
/// @param[in] i_dl_x4_backoff_en backoff enable field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode training_prbs(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
    const uint8_t i_dl_x4_backoff_en)
{
    FAPI_DBG("Performing OMI Train P10 workaround on %s", mss::c_str(i_omi));

    // OMI training PRBS workaround for P10:
    // Setup OMI side with pattern A

    // Training mode 1: send Pattern A
    FAPI_TRY(mss::omi::setup_mc_config0(i_omi, mss::omi::train_mode::TX_PATTERN_A, i_dl_x4_backoff_en));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform p10_omi_setup (pre-training) workaround for P10+Explorer
///
/// @param[in] i_target OMI target
/// @param[in] i_dl_x4_backoff_en backoff enable field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode pre_training_prbs(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
    const uint8_t i_dl_x4_backoff_en)
{
    FAPI_DBG("Performing OMI Setup P10 workaround on %s", mss::c_str(i_target));

    // Pre-training (omi_setup) workaround for P10
    // Setup OMI side with TX_TRAINING_STATE1

    // Training mode 4: send State 1
    FAPI_TRY(mss::omi::setup_mc_config0(i_target, mss::omi::train_mode::TX_TRAINING_STATE1, i_dl_x4_backoff_en));
    FAPI_TRY(prbs_delay(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Override OMI recal timer to DD1 setting
/// @param[in] i_target the TARGET_TYPE_OMIC to operate on
/// @param[in] i_override_needed value from EC attribute
/// @param[in,out] io_data CMN_CONFIG register data
///
void override_recal_timer(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
    const bool i_override_needed,
    fapi2::buffer<uint64_t>& io_data)
{
    if (i_override_needed)
    {
        FAPI_DBG("%s Setting up OMI recal timer to DD1 setting", mss::c_str(i_target));
        scomt::omic::SET_CMN_CONFIG_CFG_CMN_RECAL_TIMER(mss::omi::recal_timer::RECAL_TIMER_100MS, io_data);
    }
}

} // omi
} // workarounds
} // mss
