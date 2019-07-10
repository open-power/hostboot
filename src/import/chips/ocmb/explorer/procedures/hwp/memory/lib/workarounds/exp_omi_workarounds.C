/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_omi_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file exp_omi_workarounds.C
/// @brief Workarounds for exp_omi_* procedures
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#include <generic/memory/lib/utils/find.H>
#include <lib/workarounds/exp_omi_workarounds.H>
#include <lib/shared/exp_consts.H>
#include <lib/omi/exp_omi_utils.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>

namespace mss
{
namespace exp
{
namespace workarounds
{
namespace omi
{
///
/// @brief Determine if OCMB PRBS workaround needs to be performed
///
/// @param[in] i_ocmb_chip OCMB target
/// @param[out] o_required workaround needs to be performed
/// @return FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode is_prbs_ocmb_required(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_chip,
    bool& o_required)
{
    // Check chip type
    uint8_t l_proc_type = 0;
    const auto& l_proc_chip = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_ocmb_chip);
    FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, l_proc_chip, l_proc_type),
             "Error getting ATTR_NAME of %s", mss::c_str(l_proc_chip));

    // OCMB Workaround Logic:
    // Non-P10 (Apollo): OCMB workaround on
    // P10 - No workaround required (no enum for this yet, so we must revisit this when the time comes)
    o_required = l_proc_type != fapi2::ENUM_ATTR_NAME_P10;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Performs OCMB PRBS workaround
///
/// @param[in] i_ocmb_chip OCMB chip
/// @param[in] i_dl_x4_backoff_en backoff enable
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode prbs_ocmb(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_chip,
    const uint8_t i_dl_x4_backoff_en)
{
    FAPI_DBG("Performing PRBS OCMB workaround on %s", mss::c_str(i_ocmb_chip));

    uint8_t l_sim = 0;
    uint32_t l_prbs_time = 0;
    uint64_t l_prbs_time_scaled = 0;

    FAPI_TRY( mss::attr::get_is_simulation( l_sim) );

    FAPI_TRY(mss::attr::get_omi_dl_preipl_prbs_time(mss::find_target<fapi2::TARGET_TYPE_OMI>(i_ocmb_chip), l_prbs_time),
             "Error from FAPI_ATTR_GET (ATTR_OMI_DL_PREIPL_PRBS_TIME)");
    l_prbs_time_scaled = l_prbs_time * mss::common_timings::DELAY_1MS;

    // State 6
    FAPI_TRY(mss::exp::omi::setup_omi_dl0_config0(i_ocmb_chip,
             mss::omi::train_mode::TX_TRAINING_STATE3,
             i_dl_x4_backoff_en));

    // Set configurable delay based on the PRBS ATTR and SIM mode
    FAPI_TRY(fapi2::delay(l_prbs_time_scaled, mss::common_timings::DELAY_1US));
    FAPI_DBG("OMI Training Pre-ipl PRBS Time = %dns",
             (l_sim ? mss::common_timings::DELAY_1US : l_prbs_time_scaled));

    // Enable training state 1 to send Pattern A
    FAPI_TRY(mss::exp::omi::setup_omi_dl0_config0(i_ocmb_chip,
             mss::omi::train_mode::TX_PATTERN_A,
             i_dl_x4_backoff_en));

    // Not calling with ENABLE_AUTO_TRAINING for explorer

fapi_try_exit:
    return fapi2::current_err;
}

} // omi
} // workarounds
} // exp
} // mss
