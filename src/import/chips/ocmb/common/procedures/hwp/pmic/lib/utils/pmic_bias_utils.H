/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_bias_utils.H $ */
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
/// @file pmic_bias_utils.H
/// @brief Procedure definition to bias PMIC
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __PMIC_BIAS_UTILS_H__
#define __PMIC_BIAS_UTILS_H__

#include <fapi2.H>
#include <lib/utils/pmic_consts.H>
#include <lib/utils/pmic_common_utils.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <generic/memory/lib/utils/c_str.H>

namespace mss
{
namespace pmic
{

///
/// @brief Rail settings that the bias procedure can modify
///
enum setting
{
    // We order these by rail in groups of 4 so they match with the rail enums,
    // so the rail can be derived from just a % 4 when we have more settings to change (see current)
    SWA_VOLT = 0,
    SWB_VOLT = 1,
    SWC_VOLT = 2,
    SWD_VOLT = 3,
    // SWA_CURRENT = 4,
    // SWB_CURRENT = 5,
    // ..
    // ..
    NO_SETTING = 8,
};

///
/// @brief Different methods of biasing
///
enum unit
{
    NO_UNIT = 0, // default value that we can use for error checking
    VALUE = 1,
    PERCENT = 2,
};

// Max bias % change that the procedure will allow without override flag
static constexpr float PERCENT_MAX_BIAS = 10.0;

//-------- JEDEC SPECIFIC HELPER FUNCS ---------//

///
/// @brief Set the voltage of a rail (post-rounding)
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_rail rail to set
/// @param[in] i_target_voltage voltage to set to
/// @param[in] i_range_selection range (0 or 1) of the rail
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode set_new_rail_voltage(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const mss::pmic::rail i_rail,
    const uint32_t i_target_voltage,
    const uint8_t i_range_selection);

///
/// @brief round a target rail voltage to the nearest step of 5mV to create the voltage bitmap
///
/// @param[in] l_target_voltage_unrounded unrounded voltage
/// @return uint32_t rounded voltage
///
uint32_t round_rail_target_voltage(const uint32_t l_target_voltage_unrounded);

///
/// @brief Checks if bias percentage is within the MAX_BIAS threshold
///
/// @param[in] i_percent percentage to check
/// @param[in] i_force force change (would force evaluation to true)
/// @return true if in range, false if not
///
bool bias_percent_within_threshold(const float i_percent, const bool i_force);

///
/// @brief Get the current rail voltage of a JEDEC PMIC
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_rail rail to read from
/// @param[out] o_current_rail_voltage voltage calculated for rail
/// @param[out] o_range_selection range selection of that voltage
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
/// @note not templated as the arguments may differ for other chips (if we ever use others)
///
fapi2::ReturnCode get_current_rail_voltage(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>&
        i_pmic_target,
        const mss::pmic::rail i_rail,
        uint32_t& o_current_rail_voltage,
        uint8_t& o_range_selection);

//-------------- HELPER FUNCTIONS --------------//

///
/// @brief Set the voltage percent on the specified rail of a PMIC device
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_rail rail to bias
/// @param[in] i_percent percentage change
/// @param[in] i_force override 10% change limit
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode set_voltage_percent(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
                                      const mss::pmic::rail i_rail,
                                      const float i_percent,
                                      const bool i_force);

///
/// @brief Set the voltage of a rail by a value
///
/// @param[in] i_pmic_target PMIC to bias
/// @param[in] i_rail rail to bias
/// @param[in] i_value value to set to
/// @param[in] i_force override 10% change limit
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode set_voltage_value(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
                                    const mss::pmic::rail i_rail,
                                    const float i_value,
                                    const bool i_force);

//------------------- BIAS FUNCTIONS -----------------//

///
/// @brief Bias a chip with the given settings
///
/// @param[in] i_pmic_target - the pmic_target
/// @param[in] i_setting setting to change (swa_volt, swb_volt, etc.)
/// @param[in] i_amount amount to change by
/// @param[in] i_unit percentage or value
/// @param[in] i_force ignore 10% change limit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode bias_chip(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
                            const mss::pmic::setting i_setting,
                            const float i_amount,
                            const mss::pmic::unit i_unit,
                            const bool i_force);

} // pmic
} // mss

#endif
