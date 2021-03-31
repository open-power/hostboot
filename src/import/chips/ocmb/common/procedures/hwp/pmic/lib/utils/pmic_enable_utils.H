/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_enable_utils.H $ */
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
/// @file pmic_enable_utils.H
/// @brief Utility functions for PMIC enable operation
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __PMIC_ENABLE_UTILS_H__
#define __PMIC_ENABLE_UTILS_H__

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <lib/i2c/i2c_pmic.H>
#include <lib/utils/pmic_common_utils.H>
#include <lib/utils/pmic_consts.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/index.H>
#include <mss_pmic_attribute_accessors_manual.H>

namespace mss
{

namespace gpio
{

///
/// @brief Poll for the GPIO input port ready on the bit corresponding to the PMIC pair
///
/// @param[in] i_gpio_target GPIO target
/// @param[in] i_pmic_target PMIC target that the input line is connecting to
/// @param[in] i_pmic_pair_bit the PMIC pair bit INPUT_PORT_REG_PMIC_PAIR0/1
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode poll_input_port_ready(
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const mss::gpio::fields i_pmic_pair_bit);

} // ns gpio

namespace pmic
{

using ADC_REGS = mss::adc::regs;
using ADC_FIELDS = mss::adc::fields;
using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

// The sequences below and accompanying comments are
// defined in section 6.1.1 of the Redundant Power on DIMM –
// Functional Specification document

// ADC1 register sequence
// pair<REG,DATA>
static const std::vector<std::pair<uint8_t, uint8_t>> ADC1_CH_INIT =
{
    // 96: Ensure all channel GPIO setting is Open-Drain (re-writing default)
    {ADC_REGS::GPO_DRIVE_CFG, ADC_FIELDS::GPO_DRIVE_CFG_OPEN_DRAIN},

    // 97: Set CH0 output state as HIGH (Keeps CH0 PGO High-Z with PGO OD set)
    {ADC_REGS::GPO_VALUE, ADC_FIELDS::GPO_VALUE_CH0_HIGH},

    // 98: Configure CH0 to be a digital GPO when in GPIO mode
    {ADC_REGS::GPIO_CFG, ADC_FIELDS::GPIO_CFG_CH0_DIGITAL_GP0},

    // 99: Configure CH0 to be a GPIO (it can simultaneously be used as AIN0)
    {ADC_REGS::PIN_CFG, ADC_FIELDS::PIN_CFG_CH0_GPIO},

    // 100: Set channels to auto sequencing, all channels
    {ADC_REGS::AUTO_SEQ_CH_SEL, ADC_FIELDS::AUTO_SEQ_CH_SEL_ALL_AUTO_SEQUENCING},
    // 101: Set auto sequence mode
    {ADC_REGS::SEQUENCE_CFG, ADC_FIELDS::SEQUENCE_CFG_AUTO_SEQUENCE},

    // CH 0
    // 102-105: CH0 Unused
    {ADC_REGS::HYSTERESIS_CH1, ADC_FIELDS::HYSTERESIS_UNUSED},
    {ADC_REGS::HIGH_TH_CH1, ADC_FIELDS::HIGH_TH_DEFAULT},
    {ADC_REGS::EVENT_COUNT_CH1, ADC_FIELDS::EVENT_COUNT_UNUSED},
    {ADC_REGS::LOW_TH_CH1, ADC_FIELDS::LOW_TH_DEFAULT},

    // CH 1
    // 106: Keep upper limit at max, enable hysteresis
    {ADC_REGS::HYSTERESIS_CH1, ADC_FIELDS::HYSTERESIS_UPPER_LIMIT_MAX_ENABLE},

    // 107: Keep default, may skip if not multibyte writing
    {ADC_REGS::HIGH_TH_CH1, ADC_FIELDS::HIGH_TH_DEFAULT},

    // 108: Set up so alert must persist for 4 consecutive readings
    {ADC_REGS::EVENT_COUNT_CH1, ADC_FIELDS::EVENT_COUNT_ADC1_CH1_ALERT_4_CONSECUTIVE_READINGS},

    // 109: 1AB_VLOC (VDDR1) Low Threshold = 0.643 V
    {ADC_REGS::LOW_TH_CH1, ADC_FIELDS::LOW_TH_CH1_1AB_VLOC_LOW_THRESHOLD_643mv},

    // CH 2
    // 110: Keep upper limit at max, enable hysteresis
    {ADC_REGS::HYSTERESIS_CH2, ADC_FIELDS::HYSTERESIS_UPPER_LIMIT_MAX_ENABLE},

    // 111: Keep default, may skip if not multibyte writing
    {ADC_REGS::HIGH_TH_CH2, ADC_FIELDS::HIGH_TH_DEFAULT},

    // 112: Set up so alert must persist for 4 consecutive readings
    {ADC_REGS::EVENT_COUNT_CH2, ADC_FIELDS::EVENT_COUNT_ADC1_CH2_ALERT_4_CONSECUTIVE_READINGS},

    // 113: 1C_VLOC (VIO) Low Threshold = 0.476 V
    {ADC_REGS::LOW_TH_CH2, ADC_FIELDS::LOW_TH_CH2_1C_VLOC_LOW_THRESHOLD_476mv},

    // CH3
    // 114: Keep upper limit at max, enable hysteresis
    {ADC_REGS::HYSTERESIS_CH3, ADC_FIELDS::HYSTERESIS_UPPER_LIMIT_MAX_ENABLE},

    // 115: Keep default, may skip if not multibyte writing
    {ADC_REGS::HIGH_TH_CH3, ADC_FIELDS::HIGH_TH_DEFAULT},

    // 116: Set up so alert must persist for 4 consecutive readings
    {ADC_REGS::EVENT_COUNT_CH3, ADC_FIELDS::EVENT_COUNT_ADC1_CH3_ALERT_4_CONSECUTIVE_READINGS},

    // 117: 1D_VLOC/2 (VPP) Low Threshold = 0.733 V
    {ADC_REGS::LOW_TH_CH3, ADC_FIELDS::LOW_TH_CH3_1D_VLOC_LOW_THRESHOLD_733mv},

    // CH 4
    // 118: Keep upper limit at max, enable hysteresis
    {ADC_REGS::HYSTERESIS_CH4, ADC_FIELDS::HYSTERESIS_UPPER_LIMIT_MAX_ENABLE},

    // 119: Keep default, may skip if not multibyte writing
    {ADC_REGS::HIGH_TH_CH4, ADC_FIELDS::HIGH_TH_DEFAULT},

    // 120: Set up so alert must persist for 4 consecutive readings
    {ADC_REGS::EVENT_COUNT_CH4, ADC_FIELDS::EVENT_COUNT_ADC1_CH4_ALERT_4_CONSECUTIVE_READINGS},

    // 121: 2C_VLOC (VIO) Low Threshold = 0.476 V
    {ADC_REGS::LOW_TH_CH4, ADC_FIELDS::LOW_TH_CH4_2C_VLOC_LOW_THRESHOLD_476mv},

    // CH 5
    // 122: Keep upper limit at max, enable hysteresis
    {ADC_REGS::HYSTERESIS_CH5, ADC_FIELDS::HYSTERESIS_UPPER_LIMIT_MAX_ENABLE},

    // 123: Keep default, may skip if not multibyte writing
    {ADC_REGS::HIGH_TH_CH5, ADC_FIELDS::HIGH_TH_DEFAULT},

    // 124: Set up so alert must persist for 4 consecutive readings
    {ADC_REGS::EVENT_COUNT_CH5, ADC_FIELDS::EVENT_COUNT_ADC1_CH5_ALERT_4_CONSECUTIVE_READINGS},

    // 125: 2D_VLOC/2 (VPP) Low Threshold = 0.733 V
    {ADC_REGS::LOW_TH_CH5, ADC_FIELDS::LOW_TH_CH5_2D_VLOC_LOW_THRESHOLD_733mv},

    // CH 6
    // 126-129: CH6 Unused
    {ADC_REGS::HYSTERESIS_CH6, ADC_FIELDS::HYSTERESIS_UNUSED},
    {ADC_REGS::HIGH_TH_CH6, ADC_FIELDS::HIGH_TH_DEFAULT},
    {ADC_REGS::EVENT_COUNT_CH6, ADC_FIELDS::EVENT_COUNT_UNUSED},
    {ADC_REGS::LOW_TH_CH6, ADC_FIELDS::LOW_TH_DEFAULT},

    // CH 7
    // 130: Keep upper limit at max, enable hysteresis
    {ADC_REGS::HYSTERESIS_CH7, ADC_FIELDS::HYSTERESIS_UPPER_LIMIT_MAX_ENABLE},

    // 131: Keep default, may skip if not multibyte writing
    {ADC_REGS::HIGH_TH_CH7, ADC_FIELDS::HIGH_TH_DEFAULT},

    // 132: Set up so alert must persist for 4 consecutive readings
    {ADC_REGS::EVENT_COUNT_CH7, ADC_FIELDS::EVENT_COUNT_ADC1_CH7_ALERT_4_CONSECUTIVE_READINGS},

    // 133: 2AB_VLOC Low (VDDR1) Threshold = 0.643 V
    {ADC_REGS::LOW_TH_CH7, ADC_FIELDS::LOW_TH_CH7_2AB_VLOC_LOW_THRESHOLD_643mv},

    // Finalize
    // 134: Set channels to trigger an alert, only local voltages
    {ADC_REGS::ALERT_CH_SEL, ADC_FIELDS::ALERT_CH_SEL_ADC1_LOCAL_VOLTAGES_ALERT},

    // 135: Set alert pin function to remain active high (not pulsed)
    {ADC_REGS::ALERT_PIN_CFG, ADC_FIELDS::ALERT_PIN_CFG_ACTIVE_HIGH},

    // 136: Setup autonomous conversions and sampling speed
    {ADC_REGS::OPMODE_CFG, ADC_FIELDS::OPMODE_CFG_AUTONOMOUS},

    // 137: Set over sampling, 8 samples
    {ADC_REGS::OSR_CFG, ADC_FIELDS::OSR_CFG_8_SAMPLE_OVERSAMPLING},

    // 138: Enable digital window comparator and stats
    {ADC_REGS::GENERAL_CFG, ADC_FIELDS::GENERAL_CFG_EN_DIGITAL_WINDOW_COMPARATOR_AND_STATS},

    // 139: Enable Channel sequencing
    {ADC_REGS::SEQUENCE_CFG, ADC_FIELDS::SEQUENCE_CFG_CHANNEL_SEQUENCING},

    // Clear event flags, enable PWM
    {ADC_REGS::HIGH_EVENT_FLAGS, ADC_FIELDS::CLEAR_EVENTS},
    {ADC_REGS::LOW_EVENT_FLAGS, ADC_FIELDS::CLEAR_EVENTS},
    {ADC_REGS::EVENT_COUNT_CH0, ADC_FIELDS::EVENT_COUNT_CH_ENABLE_PWM}
};

// ADC2 register sequence
// pair<REG,DATA>
static const std::vector<std::pair<uint8_t, uint8_t>> ADC2_CH_INIT =
{
    // 140: Ensure all channel GPIO setting is Open-Drain (re-writing default)
    {ADC_REGS::GPO_DRIVE_CFG, ADC_FIELDS::GPO_DRIVE_CFG_OPEN_DRAIN},

    // 141: Set CH0 output state as HIGH (Keeps CH0 PGO High-Z with PGO OD set)
    {ADC_REGS::GPO_VALUE, ADC_FIELDS::GPO_VALUE_CH0_HIGH},

    // 142: Configure CH0 to be a digital GPO when in GPIO mode
    {ADC_REGS::GPIO_CFG, ADC_FIELDS::GPIO_CFG_CH0_DIGITAL_GP0},

    // 143: Configure CH0 to be a GPIO (it can simultaneously be used as AIN0)
    {ADC_REGS::PIN_CFG, ADC_FIELDS::PIN_CFG_CH0_GPIO},

    // 144: Set channels to auto sequencing, all channels
    {ADC_REGS::AUTO_SEQ_CH_SEL, ADC_FIELDS::AUTO_SEQ_CH_SEL_ALL_AUTO_SEQUENCING},

    // 145: Set auto sequence mode
    {ADC_REGS::SEQUENCE_CFG, ADC_FIELDS::SEQUENCE_CFG_AUTO_SEQUENCE},

    // CH 0
    // 146-149: CH0 Unused
    {ADC_REGS::HYSTERESIS_CH0, ADC_FIELDS::HYSTERESIS_UNUSED},
    {ADC_REGS::HIGH_TH_CH0, ADC_FIELDS::HIGH_TH_DEFAULT},
    {ADC_REGS::EVENT_COUNT_CH0, ADC_FIELDS::EVENT_COUNT_UNUSED},
    {ADC_REGS::LOW_TH_CH0, ADC_FIELDS::LOW_TH_DEFAULT},

    // CH 1
    // 150-153: CH1 Unused
    {ADC_REGS::HYSTERESIS_CH1, ADC_FIELDS::HYSTERESIS_UNUSED},
    {ADC_REGS::HIGH_TH_CH1, ADC_FIELDS::HIGH_TH_DEFAULT},
    {ADC_REGS::EVENT_COUNT_CH1, ADC_FIELDS::EVENT_COUNT_UNUSED},
    {ADC_REGS::LOW_TH_CH1, ADC_FIELDS::LOW_TH_DEFAULT},

    // CH 2
    // 154: Keep upper limit at max, enable hysteresis
    {ADC_REGS::HYSTERESIS_CH2, ADC_FIELDS::HYSTERESIS_UPPER_LIMIT_MAX_ENABLE},

    // 155: Keep default, may skip if not multibyte writing
    {ADC_REGS::HIGH_TH_CH2, ADC_FIELDS::HIGH_TH_DEFAULT},

    // 156: Set up so alert must persist for 4 consecutive readings
    {ADC_REGS::EVENT_COUNT_CH2, ADC_FIELDS::EVENT_COUNT_ADC2_CH2_ALERT_4_CONSECUTIVE_READINGS},

    // 157: 3C_VLOC (VDD) Low Threshold = 0.391 V
    {ADC_REGS::LOW_TH_CH2, ADC_FIELDS::LOW_TH_CH2_3C_VLOC_LOW_THRESHOLD_391mv},

    // CH 3
    // 158: Keep upper limit at max, enable hysteresis
    {ADC_REGS::HYSTERESIS_CH3, ADC_FIELDS::HYSTERESIS_UPPER_LIMIT_MAX_ENABLE},

    // 159: Keep default, may skip if not multibyte writing
    {ADC_REGS::HIGH_TH_CH3, ADC_FIELDS::HIGH_TH_DEFAULT},

    // 160: Set up so alert must persist for 4 consecutive readings
    {ADC_REGS::EVENT_COUNT_CH3, ADC_FIELDS::EVENT_COUNT_ADC2_CH3_ALERT_4_CONSECUTIVE_READINGS},

    // 161: 4AB_VLOC (VDDR2) Low Threshold = 0.643 V
    {ADC_REGS::LOW_TH_CH3, ADC_FIELDS::LOW_TH_CH3_4AB_VLOC_LOW_THRESHOLD_543mv},

    // CH 4
    // 162-165: CH4 Unused
    {ADC_REGS::HYSTERESIS_CH4, ADC_FIELDS::HYSTERESIS_UNUSED},
    {ADC_REGS::HIGH_TH_CH4, ADC_FIELDS::HIGH_TH_DEFAULT},
    {ADC_REGS::EVENT_COUNT_CH4, ADC_FIELDS::EVENT_COUNT_UNUSED},
    {ADC_REGS::LOW_TH_CH4, ADC_FIELDS::LOW_TH_DEFAULT},

    // CH 5
    // 166: Keep upper limit at max, enable hysteresis
    {ADC_REGS::HYSTERESIS_CH5, ADC_FIELDS::HYSTERESIS_UPPER_LIMIT_MAX_ENABLE},

    // 167: Keep default, may skip if not multibyte writing
    {ADC_REGS::HIGH_TH_CH5, ADC_FIELDS::HIGH_TH_DEFAULT},

    // 168: Set up so alert must persist for 4 consecutive readings
    {ADC_REGS::EVENT_COUNT_CH5, ADC_FIELDS::EVENT_COUNT_ADC2_CH5_ALERT_4_CONSECUTIVE_READINGS},

    // 169: 4C_VLOC (VDD) Low Threshold = 0.391 V
    {ADC_REGS::LOW_TH_CH5, ADC_FIELDS::LOW_TH_CH5_4C_VLOC_LOW_THRESHOLD_391mv},

    // CH 6
    // 170-173: CH6 Unused
    {ADC_REGS::HYSTERESIS_CH6, ADC_FIELDS::HYSTERESIS_UNUSED},
    {ADC_REGS::HIGH_TH_CH6, ADC_FIELDS::HIGH_TH_DEFAULT},
    {ADC_REGS::EVENT_COUNT_CH6, ADC_FIELDS::EVENT_COUNT_UNUSED},
    {ADC_REGS::LOW_TH_CH6, ADC_FIELDS::LOW_TH_DEFAULT},

    // CH 7
    // 174: Keep upper limit at max, enable hysteresis
    {ADC_REGS::HYSTERESIS_CH7, ADC_FIELDS::HYSTERESIS_UPPER_LIMIT_MAX_ENABLE},

    // 175: Keep default, may skip if not multibyte writing
    {ADC_REGS::HIGH_TH_CH7, ADC_FIELDS::HIGH_TH_DEFAULT},

    // 176: Set up so alert must persist for 4 consecutive readings
    {ADC_REGS::EVENT_COUNT_CH7, ADC_FIELDS::EVENT_COUNT_ADC2_CH7_ALERT_4_CONSECUTIVE_READINGS},

    // 177: 3AB_VLOC (VDDR2) Low Threshold = 0.643 V
    {ADC_REGS::LOW_TH_CH7, ADC_FIELDS::LOW_TH_CH7_3AB_VLOC_LOW_THRESHOLD_543mv},

    // Finalize
    // 178: Set channels to trigger an alert, only local voltages
    {ADC_REGS::ALERT_CH_SEL, ADC_FIELDS::ALERT_CH_SEL_ADC2_LOCAL_VOLTAGES_ALERT},

    // 179: Set alert pin function to remain active high (not pulsed)
    {ADC_REGS::ALERT_PIN_CFG, ADC_FIELDS::ALERT_PIN_CFG_ACTIVE_HIGH},

    // 180: Setup autonomous conversions and sampling speed
    {ADC_REGS::OPMODE_CFG, ADC_FIELDS::OPMODE_CFG_AUTONOMOUS},

    // 181: Set over sampling, 8 samples
    {ADC_REGS::OSR_CFG, ADC_FIELDS::OSR_CFG_8_SAMPLE_OVERSAMPLING},

    // 182: Enable digital window comparator and stats
    {ADC_REGS::GENERAL_CFG, ADC_FIELDS::GENERAL_CFG_EN_DIGITAL_WINDOW_COMPARATOR_AND_STATS},

    // 183: Enable Channel sequencing
    {ADC_REGS::SEQUENCE_CFG, ADC_FIELDS::SEQUENCE_CFG_CHANNEL_SEQUENCING},

    // Clear event flags, enable PWM
    {ADC_REGS::HIGH_EVENT_FLAGS, ADC_FIELDS::CLEAR_EVENTS},
    {ADC_REGS::LOW_EVENT_FLAGS, ADC_FIELDS::CLEAR_EVENTS},
    {ADC_REGS::EVENT_COUNT_CH0, ADC_FIELDS::EVENT_COUNT_CH_ENABLE_PWM}
};

///
/// @brief Struct for PMIC / GPIO / ADC target info for redundant PMIC configs
/// @note Requires a redundancy config, or else will try to grab null targets
///
struct target_info_redundancy
{
    std::map<size_t, fapi2::Target<fapi2::TARGET_TYPE_PMIC>> iv_pmic_map;

    fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE> iv_adc1;
    fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE> iv_adc2;
    fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE> iv_gpio1;
    fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE> iv_gpio2;

    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> iv_ocmb;

    target_info_redundancy() = delete;

    ///
    /// @brief Construct a new target_info_redundancy object
    ///
    /// @param[in] i_ocmb OCMB target
    /// @param[out] o_rc ReturnCode in case of construction error
    /// @note pmic_enable.C plug rules ensures that a valid number of I2C and PMIC children targets exist
    ///
    target_info_redundancy(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb, fapi2::ReturnCode& o_rc)
    {
        o_rc = fapi2::FAPI2_RC_SUCCESS;

        const auto I2C_DEVICES =
            mss::find_targets_sorted_by_index<fapi2::TARGET_TYPE_GENERICI2CSLAVE>(i_ocmb);

        // The ATTR_REL_POS (mss::index) numbering is how PMIC HWP's have numbered the PMICs and how platform
        // provides them. This varies from the "Redundant Power on DIMM – Functional Specification" numbering
        for (const auto& l_pmic : mss::find_targets<fapi2::TARGET_TYPE_PMIC>(i_ocmb))
        {
            // mss::index grabs ATTR_REL_POS, returning 0-3 for these PMIC targets
            iv_pmic_map.insert(std::make_pair(mss::index(l_pmic), l_pmic));
        }

        const uint8_t NUM_PMICS = iv_pmic_map.size();
        const uint8_t NUM_GENERICI2CSLAVE = I2C_DEVICES.size();
        const auto NUM_PRIMARY_PMICS = CONSTS::NUM_PRIMARY_PMICS;

        // If we are given a guaranteed failing list of targets (< 2 PMICs or < 4 GI2CS), exit now
        FAPI_ASSERT((NUM_PMICS >= NUM_PRIMARY_PMICS) &&
                    (NUM_GENERICI2CSLAVE == mss::generic_i2c_slave::NUM_TOTAL_DEVICES),
                    fapi2::INVALID_PMIC_GI2C_TARGET_CONFIG()
                    .set_OCMB_TARGET(i_ocmb)
                    .set_NUM_PMICS(NUM_PMICS)
                    .set_NUM_GI2CS(NUM_GENERICI2CSLAVE)
                    .set_EXPECTED_MIN_PMICS(NUM_PRIMARY_PMICS)
                    .set_EXPECTED_GI2CS(mss::generic_i2c_slave::NUM_TOTAL_DEVICES),
                    "%s pmic_enable requires at least %u PMICs and exactly %u GI2C targets. "
                    "Given %u PMICs, %u GI2C",
                    mss::c_str(i_ocmb),
                    NUM_PRIMARY_PMICS,
                    NUM_GENERICI2CSLAVE,
                    NUM_PMICS,
                    NUM_GENERICI2CSLAVE);

        // Since we have all 4 and they are sorted, we already know what is where
        iv_adc1 = I2C_DEVICES[mss::generic_i2c_slave::ADC1];
        iv_adc2 = I2C_DEVICES[mss::generic_i2c_slave::ADC2];
        iv_gpio1 = I2C_DEVICES[mss::generic_i2c_slave::GPIO1];
        iv_gpio2 = I2C_DEVICES[mss::generic_i2c_slave::GPIO2];

        iv_ocmb = i_ocmb;

        return;

    fapi_try_exit:
        o_rc = fapi2::current_err;
    }


};

///
/// @brief Structure type to loop on when performing SPD or manual enable for 4U pmics
///
struct enable_fields_4u
{
    uint8_t iv_pmic_id;
    fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE> iv_gpio;
    uint8_t iv_input_port_bit;
};

///
/// @brief Fields to loop over when VR-enabling redundant PMICs
///
using enable_loop_fields_t = std::array<mss::pmic::enable_fields_4u, CONSTS::NUM_PMICS_4U>;

//-----------------------------------
// SPD Biasing functions
//-----------------------------------

///
/// @brief set VR enable bit for system startup via R32 (not broadcast)
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode start_vr_enable(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Declare N-Mode and log fapi2::current_err as recoverable
///
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_pmic_id PMIC ID (0-3)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS
/// @note expected to be called in a fapi_try_exit with bad current_err
///
fapi2::ReturnCode declare_n_mode(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    uint8_t i_pmic_id);

///
/// @brief Set the up VIN latch bit for TPS pmics
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode setup_tps_vin_latch(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Set the SWD soft start time to 4ms for the provided PMIC if it is providing VPP
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::FAPI2_RC_SUCCESS iff success
/// @note This is used for 4U in order to avoid the issue of too-high current sink during a VR_DISABLE
///
fapi2::ReturnCode set_soft_start_time(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Set the soft start time to maximum for the provided PMIC
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::FAPI2_RC_SUCCESS iff success
/// @note This is used for 4U in order to avoid the issue of too-high current sink during a VR_DISABLE
///
fapi2::ReturnCode set_soft_stop_time(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Perform pre-enable steps, workarounds, etc.
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode pre_enable_steps(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief bias PMIC with spd settings for phase combination (SWA, SWB or SWA+SWB)
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target - OCMB parent target of pmic
/// @param[in] i_id - PMIC0 or PMIC1
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode bias_with_spd_phase_comb(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id);

///
/// @brief bias PMIC with SPD settings for voltage ranges
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id PMIC0 or PMIC1
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode bias_with_spd_volt_ranges(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id);

///
/// @brief bias PMIC with SPD settings for startup sequence
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id PMIC0 or PMIC1
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode bias_with_spd_startup_seq(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id);

///
/// @brief Set the current limiter warning registers via attributes
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode set_current_limiter_warnings(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target);

///
/// @brief Set the startup seq register with the given parameters
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_rail rail to
/// @param[in] i_round sequence round 1-4
/// @param[in] i_delay delay after round
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode set_startup_seq_register(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint8_t i_rail,
    const uint8_t i_round,
    const uint8_t i_delay);

//-----------------------------------
// Templated SPD Biasing functions
//-----------------------------------

///
/// @brief Bias with spd voltages for IDT pmic
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id relative ID of PMIC (0/1)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template <mss::pmic::vendor V>
fapi2::ReturnCode bias_with_spd_voltages(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id);

///
/// @brief Order PMICs by sequence defined in the SPD
///
/// @param[in] i_ocmb_target OCMB target to pull SPD fields from
/// @param[in,out] io_pmics vector of PMICs that will be re-ordered in place
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode order_pmics_by_sequence(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_target,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PMIC>>& io_pmics);

///
/// @brief Bias with spd voltages for IDT pmic
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id relative ID of PMIC (0/1)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template <>
inline fapi2::ReturnCode bias_with_spd_voltages<mss::pmic::vendor::IDT>(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    for (uint8_t l_rail_index = mss::pmic::rail::SWA; l_rail_index <= mss::pmic::rail::SWD; ++l_rail_index)
    {
        uint8_t l_volt_bitmap;
        FAPI_TRY(calculate_voltage_bitmap_from_attr(i_pmic_target, i_id, l_rail_index, l_volt_bitmap));

        {
            fapi2::buffer<uint8_t> l_volt_buffer = l_volt_bitmap << CONSTS::SHIFT_VOLTAGE_FOR_REG;
            FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, mss::pmic::VOLT_SETTING_ACTIVE_REGS[l_rail_index], l_volt_buffer),
                     "Error writing address 0x%02hhX of PMIC %s", mss::pmic::VOLT_SETTING_ACTIVE_REGS[l_rail_index],
                     mss::c_str(i_pmic_target));
        }

    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Bias with spd voltages for TI pmic
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id relative ID of PMIC (0/1)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template <>
inline fapi2::ReturnCode bias_with_spd_voltages<mss::pmic::vendor::TI>(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    for (uint8_t l_rail_index = mss::pmic::rail::SWA; l_rail_index <= mss::pmic::rail::SWD; ++l_rail_index)
    {
        uint8_t l_volt_bitmap;
        FAPI_TRY(calculate_voltage_bitmap_from_attr(i_pmic_target, i_id, l_rail_index, l_volt_bitmap));

        uint8_t l_volt_range_select = 0;
        FAPI_TRY(mss::attr::get_volt_range_select[l_rail_index][i_id](i_ocmb_target, l_volt_range_select));

        // SWD supports a RANGE 1, but NOT SWA-C
        if (l_rail_index == mss::pmic::rail::SWD)
        {
            // Can set range and voltage directly
            fapi2::buffer<uint8_t> l_volt_range_buffer;

            // Read in what the register has, as to not overwrite any default values
            FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic_target, REGS::R2B, l_volt_range_buffer));

            l_volt_range_buffer.writeBit<FIELDS::SWD_VOLTAGE_RANGE>(l_volt_range_select);

            // Write to PMIC
            FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic_target, REGS::R2B, l_volt_range_buffer));
        }
        else
        {
            // Check if the range is range 1, in which case we will need to convert to range 0 (thanks TI)
            if (l_volt_range_select == CONSTS::RANGE_1)
            {
                // Convert from RANGE1 -> RANGE0

                // Since both ranges are 5mV (at least they're supposed to be)
                // we can just subtract the difference between range 1 and 0
                // which is 600mV -> 800mV
                // 200mV / 5 = 40
                uint8_t l_old_voltage = l_volt_bitmap;
                l_volt_bitmap = l_volt_bitmap - CONSTS::CONVERT_RANGE1_TO_RANGE0;

                // Check for overflow (the old voltage should be larger unless we rolled over)
                FAPI_ASSERT(l_volt_bitmap < l_old_voltage ,
                            fapi2::PMIC_RANGE_CONVERSION_OVERFLOW()
                            .set_PMIC_TARGET(i_pmic_target)
                            .set_RANGE_0_VOLT(l_volt_bitmap)
                            .set_RANGE_1_VOLT(l_old_voltage)
                            .set_RAIL(mss::pmic::VOLT_SETTING_ACTIVE_REGS[l_rail_index]),
                            "Voltage appeared overflowed during conversion from range 1 to 0 on rail %s of %s "
                            "RANGE_1_VOLT: 0x%02X RANGE_0_VOLT: 0x%02X",
                            PMIC_RAIL_NAMES[l_rail_index], mss::c_str(i_pmic_target), l_old_voltage, l_volt_bitmap);
            }
        }

        {
            fapi2::buffer<uint8_t> l_volt_buffer = l_volt_bitmap << CONSTS::SHIFT_VOLTAGE_FOR_REG;
            FAPI_TRY(mss::pmic::i2c::reg_write(i_pmic_target, mss::pmic::VOLT_SETTING_ACTIVE_REGS[l_rail_index], l_volt_buffer),
                     "Error writing address 0x%02hhX of PMIC %s", mss::pmic::VOLT_SETTING_ACTIVE_REGS[l_rail_index],
                     mss::c_str(i_pmic_target));
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Bias PMIC from SPD settings per vendor
///
/// @tparam V mss::pmic::vendor (IDT/TI)
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template <mss::pmic::vendor V>
fapi2::ReturnCode bias_with_spd_settings(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target);

///
/// @brief Bias IDT PMIC from SPD settings
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template<>
inline fapi2::ReturnCode bias_with_spd_settings<mss::pmic::vendor::IDT>(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
{
    // Unlock Vendor Region
    FAPI_TRY(mss::pmic::unlock_vendor_region(i_pmic_target),
             "Error unlocking vendor region on PMIC %s", mss::c_str(i_pmic_target));

    {
        // PMIC position/ID of the OCMB target. There could be 4 total, but we care about whether its PMIC0(2) or PMIC1(3)
        const mss::pmic::id l_relative_pmic_id = get_relative_pmic_id(i_pmic_target);

        // Phase combination
        FAPI_TRY(mss::pmic::bias_with_spd_phase_comb(i_pmic_target, i_ocmb_target, l_relative_pmic_id));

        // Voltage ranges
        FAPI_TRY(mss::pmic::bias_with_spd_volt_ranges(i_pmic_target, i_ocmb_target, l_relative_pmic_id));

        // Voltages
        FAPI_TRY(mss::pmic::bias_with_spd_voltages<mss::pmic::IDT>(i_pmic_target, i_ocmb_target, l_relative_pmic_id));

        // Startup sequence
        FAPI_TRY(mss::pmic::bias_with_spd_startup_seq(i_pmic_target, i_ocmb_target, l_relative_pmic_id));

        // Current consumption
        FAPI_TRY(mss::pmic::set_current_limiter_warnings(i_pmic_target, i_ocmb_target));
    }

fapi_try_exit:
    // Try to lock vendor region even in the case of an error in this function
    return mss::pmic::lock_vendor_region(i_pmic_target, fapi2::current_err);
}

///
/// @brief Bias TI PMIC from SPD settings
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template<>
inline fapi2::ReturnCode bias_with_spd_settings<mss::pmic::vendor::TI>(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
{
    // Unlock Vendor Region
    FAPI_TRY(mss::pmic::unlock_vendor_region(i_pmic_target),
             "Error unlocking vendor region on PMIC %s", mss::c_str(i_pmic_target));
    {
        // PMIC position/ID under OCMB target
        const mss::pmic::id l_relative_pmic_id = get_relative_pmic_id(i_pmic_target);

        // Phase combination
        FAPI_TRY(mss::pmic::bias_with_spd_phase_comb(i_pmic_target, i_ocmb_target, l_relative_pmic_id));

        // Voltages
        // TI pmic only has range 0 for SWA-C. We need to convert anything SPD that says range 1 --> range 0
        FAPI_TRY(mss::pmic::bias_with_spd_voltages<mss::pmic::TI>(i_pmic_target, i_ocmb_target, l_relative_pmic_id));

        // Startup sequence
        FAPI_TRY(mss::pmic::bias_with_spd_startup_seq(i_pmic_target, i_ocmb_target, l_relative_pmic_id));

        // Current consumption
        FAPI_TRY(mss::pmic::set_current_limiter_warnings(i_pmic_target, i_ocmb_target));
    }

fapi_try_exit:
    // Try to lock vendor region even in the case of an error in this function
    return mss::pmic::lock_vendor_region(i_pmic_target, fapi2::current_err);
}

//------------------- ENABLE FUNCTIONS-----------------//

///
/// @brief Function to enable PMIC using SPD settings
///
/// @param[in] i_pmic_target - the pmic target
/// @param[in] i_ocmb_target - the OCMB parent target of the pmic
/// @param[in] i_vendor_id - the vendor ID of the PMIC to bias
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS if successful
///
fapi2::ReturnCode enable_spd(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const uint16_t i_vendor_id);

///
/// @brief Disable PMICs and clear status bits in preparation for enable
///
/// @param[in] i_ocmb_target OCMB parent target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode disable_and_reset_pmics(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_target);

///
/// @brief Enable PMIC for 1U/2U
///
/// @param[in] i_ocmb_target OCMB target parent of PMICs
/// @param[in] i_mode manual/SPD enable mode
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode enable_1u_2u(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::enable_mode i_mode);

///
/// @brief Setup ADC1
///
/// @param[in] i_adc ADC1
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode setup_adc1(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_adc);

///
/// @brief Setup ADC2
///
/// @param[in] i_adc ADC2
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode setup_adc2(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_adc);

///
/// @brief Set the up PMIC ADC to read VIN_BULK
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else unrecoverable error
///
fapi2::ReturnCode setup_adc_vin_bulk_read(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Validate that the efuse appears off by measuring VIN of the given PMIC
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else unrecoverable error
///
fapi2::ReturnCode validate_efuse_off(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Validate that the efuse appears on by measuring VIN of the given PMIC
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else unrecoverable error
///
fapi2::ReturnCode validate_efuse_on(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Enable EFUSE according to 4U Functional Specification
///
/// @param[in] i_gpio GPIO target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note Corresponds to steps (6,7,8) & (16,17,18) in 4U DDIMM Functional Spec
///
fapi2::ReturnCode setup_gpio_efuse(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio);

///
/// @brief Set the up PMIC pair and matching GPIO expander prior to PMIC enable
///
/// @param[in] i_pmic_map PMIC position to target map
/// @param[in] i_pmic_id_0 ID for "pmic0" (0/2) connected to i_gpio
/// @param[in] i_pmic_id_1 ID for "pmic1" (1/3) connected to i_gpio
/// @param[in] i_gpio GPIO target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note the PMIC pair is NOT a redundant pair, this is the independent pair connected to one GPIO
///
fapi2::ReturnCode setup_pmic_pair_and_gpio(
    const std::map<size_t, fapi2::Target<fapi2::TARGET_TYPE_PMIC>>& i_pmic_map,
    const uint8_t i_pmic_id_0,
    const uint8_t i_pmic_id_1,
    const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio);

///
/// @brief Step 1 of enable_with_redundancy: set up the GPIO EFUSE's
///
/// @param[in] i_target_info target info struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else unrecoverable error
///
fapi2::ReturnCode redundancy_gpio_efuse_setup(const target_info_redundancy& i_target_info);

///
/// @brief Set the 4U PMIC to pre-determined settings
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_pmic_id PMIC ID (0-3)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode set_4u_settings(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target, const uint8_t i_pmic_id);

///
/// @brief Kick off VR_ENABLE's for a redundancy PMIC config in the provided mode
///
/// @param[in] i_target_info target info struct
/// @param[in] i_enable_loop_fields Parameters/fields to iterate over
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else unrecoverable error
///
fapi2::ReturnCode redundancy_vr_enable_kickoff(
    const target_info_redundancy& i_target_info,
    const mss::pmic::enable_loop_fields_t& i_enable_loop_fields);

///
/// @brief Check the statuses of all PMICs present on the given OCMB chip
///
/// @param[in] i_ocmb_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
/// @note To be used with 4U/Redundant Enable sequence
///
fapi2::ReturnCode redundancy_check_all_pmics(const target_info_redundancy& i_target_info);

///
/// @brief Set the up GPIOs, ADCs, PMICs for a redundancy configuration / 4U
///
/// @param[in] i_ocmb_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
fapi2::ReturnCode enable_with_redundancy(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target);

///
/// @brief Log recoverable errors for each PMIC that declared N-mode
///
/// @param[in] i_target_info Target info struct
/// @param[in] i_n_mode_pmic n-mode states for each PMIC, present or not
///
void log_n_modes_as_recoverable_errors(
    const target_info_redundancy& i_target_info,
    const std::array<mss::pmic::n_mode, CONSTS::NUM_PMICS_4U>& i_n_mode_pmic);

///
/// @brief Assert the resulting n-mode states with the proper error FFDC
///
/// @param[in] i_target_info target info struct
/// @param[in] i_n_mode_pmic n-mode states for each PMIC, present or not
/// @param[in] i_mnfg_thresholds thresholds policy setting
/// @return fapi2::ReturnCode iff no n-modes, else, relevant error FFDC
///
fapi2::ReturnCode assert_n_mode_states(
    const target_info_redundancy& i_target_info,
    const std::array<mss::pmic::n_mode, CONSTS::NUM_PMICS_4U>& i_n_mode_pmic,
    const bool i_mnfg_thresholds);

///
/// @brief Get the mnfg thresholds policy setting
///
/// @param[out] o_thresholds thresholds policy setting
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode get_mnfg_thresholds(bool& o_thresholds);

///
/// @brief Process the results of the N-Mode declarations (if any)
///
/// @param[in] i_target_info OCMB, PMIC and I2C target struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, or error code based on the
///                           n mode results + policy settings
///
fapi2::ReturnCode process_n_mode_results(const target_info_redundancy& i_target_info);

namespace check
{

///
/// @brief Check for a bad pair given the n-mode states of the 4 4U pmics
///
/// @param[in] i_n_mode_pmic n-mode states of the 4 PMICs
/// @return true/false pair bad
///
bool bad_pair(const std::array<mss::pmic::n_mode, CONSTS::NUM_PMICS_4U>& i_n_mode_pmic);

///
/// @brief Check if at least one PMIC has declared N mode
///
/// @param[in] i_n_mode_pmic n-mode states of the 4 PMICs
/// @return true/false at least one pmic is bad
///
bool bad_any(const std::array<mss::pmic::n_mode, CONSTS::NUM_PMICS_4U>& i_n_mode_pmic);

///
/// @brief Reset N Mode attributes
///
/// @param[in] i_target_info OCMB, PMIC and I2C target struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS, else error code
/// @note For 4U only. Has no effect on 1U/2U.
///
fapi2::ReturnCode reset_n_mode_attrs(const target_info_redundancy& i_target_info);

///
///
/// @param[in] i_gpio GPIO target
/// @param[out] o_already_enabled true if efuses already on, else false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else
///
fapi2::ReturnCode efuses_already_enabled(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CSLAVE>& i_gpio,
        bool& o_already_enabled);

///
/// @brief Helper function to check if GPIO is already enabled given output register contents
///
/// @param[in] i_output OUTPUT register contents
/// @return bool enabled true/false
/// @note unit-testable helper function
///
inline bool efuses_already_enabled_helper(const uint8_t i_polarity, const uint8_t i_output, const uint8_t i_config)
{
    fapi2::buffer<uint8_t> l_output(i_output);

    // We can identify this efuse is enabled if we match the expected settings
    return (i_polarity == mss::gpio::fields::EFUSE_POLARITY_SETTING) &&
           (i_output == mss::gpio::fields::EFUSE_OUTPUT_ON) &&
           (i_config == mss::gpio::fields::CONFIGURATION_IO_MAP);
}

///
/// @brief Check that the vendor ID register and attribute match
///
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_pmic_target PMIC target to check
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode matching_vendors(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Unit testable helper function: Check matching vendor ID between attr and reg values
///
/// @param[in] i_pmic_target PMIC target for FFDC
/// @param[in] i_vendor_attr vendor attribute value
/// @param[in] i_vendor_reg_lo vendor register low byte
/// @param[in] i_vendor_reg_hi vendor register high byte
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode matching_vendors_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint16_t i_vendor_attr,
    const uint8_t i_vendor_reg_lo,
    const uint8_t i_vendor_reg_hi);

///
/// @brief Check that the IDT revision # register and attribute match
///
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_pmic_target PMIC target to check
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode valid_idt_revisions(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Unit testable helper function: Check that the IDT revision # register and attribute match
///
/// @param[in] i_pmic_target PMIC target (for FFDC)
/// @param[in] i_rev_attr revision value from attribute
/// @param[in] i_rev_reg revision value from register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode valid_idt_revisions_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint8_t i_rev_attr,
    const uint8_t i_rev_reg);

} // check
} // pmic
} // mss

#endif
