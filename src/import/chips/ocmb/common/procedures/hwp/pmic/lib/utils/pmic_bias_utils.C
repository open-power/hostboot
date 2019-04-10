/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_bias_utils.C $ */
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
/// @file pmic_bias_utils.C
/// @brief Procedure definition to bias PMIC
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/utils/pmic_bias_utils.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_consts.H>
#include <lib/utils/pmic_common_utils.H>
#include <pmic_regs.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_math.H>

namespace mss
{
namespace pmic
{

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
    const uint8_t i_range_selection)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;

    FAPI_ASSERT(i_range_selection < CONSTS::NUM_RANGES,
                fapi2::PMIC_VOLTAGE_RANGE_SETTING_OUT_OF_RANGE()
                .set_TARGET(i_pmic_target)
                .set_RAIL(i_rail)
                .set_RANGE_SETTING(i_range_selection),
                "set_new_rail_voltage(): The voltage setting provided for PMIC %s on rail %u was out of range (Valid: 0,1). Given: %u",
                mss::c_str(i_pmic_target), uint8_t(i_rail), i_range_selection);

    {
        // Make sure voltage falls within range
        static const uint32_t MIN_VOLT = mss::pmic::VOLT_RANGE_MINS[i_rail][i_range_selection];
        static const uint32_t MAX_VOLT = mss::pmic::VOLT_RANGE_MAXES[i_rail][i_range_selection];

        FAPI_ASSERT((i_target_voltage >= MIN_VOLT) && (i_target_voltage <= MAX_VOLT),
                    fapi2::PMIC_BIAS_VOLTAGE_OUT_OF_RANGE()
                    .set_TARGET(i_pmic_target)
                    .set_VOLTAGE(i_target_voltage)
                    .set_MIN(MIN_VOLT)
                    .set_MAX(MAX_VOLT)
                    .set_RAIL(i_rail),
                    "set_new_rail_voltage(): After rounding the bias voltage, "
                    "the resulting voltage %lumV was out of range LOW: %lumV HIGH: %lumV for PMIC %s on rail %u",
                    i_target_voltage, MIN_VOLT, MAX_VOLT, mss::c_str(i_pmic_target), uint8_t(i_rail));
        {
            // Convert to bit mapping and write back
            const uint32_t l_offset_from_min = i_target_voltage - MIN_VOLT;
            const uint8_t l_voltage_bitmap = l_offset_from_min / CONSTS::VOLT_STEP;

            // Shift and write back
            fapi2::buffer<uint8_t> l_voltage_write_back;

            l_voltage_write_back.insertFromRight<FIELDS::VOLTAGE_SETTING_START, FIELDS::VOLTAGE_SETTING_LENGTH>(l_voltage_bitmap);

            FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, mss::pmic::VOLT_SETTING_ACTIVE_REGS[i_rail], l_voltage_write_back),
                     "set_voltage_percent: Error writing 0x%02hhX of PMIC %s", mss::pmic::VOLT_SETTING_ACTIVE_REGS[i_rail],
                     mss::c_str(i_pmic_target));
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Round a target rail voltage to the nearest step of 5mV to create the voltage bitmap
///
/// @param[in] i_target_voltage_unrounded unrounded voltage
/// @return float rounded voltage
///
uint32_t round_rail_target_voltage(const uint32_t i_target_voltage_unrounded)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    // Round to nearest unit by converting to a MV integer
    const uint32_t l_target_multiple = CONSTS::VOLT_STEP;

    const uint32_t l_target_voltage = mss::round_to_nearest_multiple(i_target_voltage_unrounded, l_target_multiple);

    // Inform the user. This will be especially useful for debugging
    FAPI_INF("Voltage rounded to %luV", l_target_voltage);

    return l_target_voltage;
}

///
/// @brief Checks if bias percentage is within the MAX_BIAS threshold
///
/// @param[in] i_percent percentage to check
/// @param[in] i_force force change (would force evaluation to true)
/// @return true if in range, false if not
///
bool bias_percent_within_threshold(const float i_percent, const bool i_force)
{
    return i_force || ((i_percent < mss::pmic::PERCENT_MAX_BIAS) && (i_percent > (-1) * mss::pmic::PERCENT_MAX_BIAS));
}

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
        uint8_t& o_range_selection)
{
    fapi2::buffer<uint8_t> l_voltage_setting_reg_contents;
    fapi2::buffer<uint8_t> l_voltage_range_reg_contents;

    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    // Get voltage for rail
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, mss::pmic::VOLT_SETTING_ACTIVE_REGS[i_rail],
                                      l_voltage_setting_reg_contents),
             "set_voltage_percent: Error reading 0x%02hhX of PMIC %s", mss::pmic::VOLT_SETTING_ACTIVE_REGS[i_rail],
             mss::c_str(i_pmic_target));

    // Get voltage range selections
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R2B, l_voltage_range_reg_contents),
             "set_voltage_percent: Error reading 0x%02hhX of PMIC %s", REGS::R2B, mss::c_str(i_pmic_target));
    {
        // Identify range
        const uint8_t l_range_selection = l_voltage_range_reg_contents.getBit(mss::pmic::VOLT_RANGE_FLDS[i_rail]);
        uint8_t l_voltage_setting = 0;

        l_voltage_setting_reg_contents.extractToRight<FIELDS::VOLTAGE_SETTING_START, FIELDS::VOLTAGE_SETTING_LENGTH>
        (l_voltage_setting);

        // Get current voltage using: range_min + (step * setting)
        o_current_rail_voltage = mss::pmic::VOLT_RANGE_MINS[i_rail][l_range_selection] + (CONSTS::VOLT_STEP *
                                 l_voltage_setting);
        o_range_selection = l_range_selection;
    }
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the voltage percent on the specified rail of a JEDEC-compliant PMIC
///
/// @param[in] i_pmic_target PMIC to bias
/// @param[in] i_rail rail to bias
/// @param[in] i_percent percentage change
/// @param[in] i_force override 10% change limit
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode set_voltage_percent(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const mss::pmic::rail i_rail,
    const float i_percent,
    const bool i_force)
{
    static constexpr float PERCENT_CONVERSION = 100;

    // Make sure less than 10% if not overriding or within threshold
    FAPI_ASSERT(bias_percent_within_threshold(i_percent, i_force),
                fapi2::PMIC_BIAS_VOLTAGE_PAST_THRESHOLD()
                .set_TARGET(i_pmic_target)
                .set_PERCENT(i_percent)
                .set_RAIL(i_rail),
                "set_voltage_percent(): Bias percentage %f%% provided to PMIC %s exceed the maximum of 10%%. Use -f to override",
                i_percent, mss::c_str(i_pmic_target));
    {
        uint32_t l_current_rail_voltage;
        uint8_t l_range_selection;

        FAPI_TRY(mss::pmic::get_current_rail_voltage(i_pmic_target, i_rail, l_current_rail_voltage, l_range_selection),
                 "set_voltage_percent: Error getting current rail voltage for rail # %u of PMIC %s", i_rail, mss::c_str(i_pmic_target));
        {
            // Obtain target voltage by percent offset
            const uint32_t l_target_voltage_unrounded = l_current_rail_voltage * ((PERCENT_CONVERSION + i_percent) /
                    PERCENT_CONVERSION);

            const uint32_t l_target_voltage = mss::pmic::round_rail_target_voltage(l_target_voltage_unrounded);

            FAPI_TRY(set_new_rail_voltage(i_pmic_target, i_rail, l_target_voltage, l_range_selection),
                     "set_voltage_percent(): Error setting voltage on PMIC %s", mss::c_str(i_pmic_target));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set the voltage of a JEDEC_COMPLIANT pmic's rail
///
/// @param[in] i_pmic_target PMIC to bias
/// @param[in] i_rail rail to bias
/// @param[in] i_value value to set to
/// @param[in] i_force override 10% change limit
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode set_voltage_value(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const mss::pmic::rail i_rail,
    const float i_value,
    const bool i_force)
{
    static constexpr float V_TO_MV_CONVERSION = 1000;
    static constexpr float PERCENT_CONVERSION = 100;

    const uint32_t l_value_mv = i_value * V_TO_MV_CONVERSION;

    uint32_t l_current_rail_voltage = 0;
    uint8_t l_range_selection;

    // Get range selection and voltage
    FAPI_TRY(mss::pmic::get_current_rail_voltage(i_pmic_target, i_rail, l_current_rail_voltage, l_range_selection),
             "set_voltage_percent: Error getting current rail voltage for rail # %u of PMIC %s", i_rail, mss::c_str(i_pmic_target));
    {
        // Calculate percent change
        // Float to avoid integer division
        const float l_percent_change = (((l_current_rail_voltage / static_cast<float>(l_value_mv)) - 1)) * PERCENT_CONVERSION;

        // Make sure less than 10% if not overriding or within threshold
        FAPI_ASSERT(bias_percent_within_threshold(l_percent_change, i_force),
                    fapi2::PMIC_BIAS_VOLTAGE_PAST_THRESHOLD()
                    .set_TARGET(i_pmic_target)
                    .set_PERCENT(l_percent_change)
                    .set_RAIL(i_rail),
                    "set_voltage_value(): Bias percentage %f%% provided to PMIC %s exceed the maximum of 10%%. Use -f to override",
                    l_percent_change, mss::c_str(i_pmic_target));

        {
            const uint32_t l_target_voltage = mss::pmic::round_rail_target_voltage(l_value_mv);

            // Verify new valid voltage and write to PMIC
            FAPI_TRY(set_new_rail_voltage(i_pmic_target, i_rail, l_target_voltage, l_range_selection),
                     "set_voltage_value(): Error setting voltage on PMIC %s", mss::c_str(i_pmic_target));
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief bias procedure for JEDEC compliant chips
///
/// @param[in] i_pmic_target - the pmic_target
/// @param[in] i_setting setting to change (swa_volt, swb_volt, etc.)
/// @param[in] i_amount amount to change by
/// @param[in] i_unit percentage or value
/// @param[in] i_force ignore 10% change limit
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note not templated by vendor. As long as the TI
///
fapi2::ReturnCode bias_chip(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const mss::pmic::setting i_setting,
    const float i_amount,
    const mss::pmic::unit i_unit,
    const bool i_force)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    if (i_unit == mss::pmic::unit::PERCENT)
    {
        FAPI_TRY(set_voltage_percent(i_pmic_target,
                                     static_cast<mss::pmic::rail>(i_setting % CONSTS::NUMBER_OF_RAILS),
                                     i_amount, i_force));
    }
    else // value
    {
        FAPI_TRY(set_voltage_value(i_pmic_target,
                                   static_cast<mss::pmic::rail>(i_setting % CONSTS::NUMBER_OF_RAILS),
                                   i_amount, i_force));
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // pmic
} // mss
