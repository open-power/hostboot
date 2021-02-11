/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_common_utils.H $ */
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
/// @file pmic_common_utils.H
/// @brief Utility functions common for several PMIC procedures
///
// *HWP HWP Owner: Mark Pizzutillo <mark.pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

///
/// @brief FAPI_TRY for lambda functions, which goes to a different label
///
#define FAPI_TRY_LAMBDA( __operation__ )                               \
    if ((fapi2::current_err = (__operation__)) != fapi2::FAPI2_RC_SUCCESS) \
    {                                                                      \
        goto fapi_try_exit_lambda;                                         \
    }

#ifndef __PMIC_COMMON_UTILS_H__
#define __PMIC_COMMON_UTILS_H__

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <lib/utils/pmic_consts.H>
#include <mss_pmic_attribute_getters.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{
namespace pmic
{

// For output traces
const std::vector<const char*> PMIC_RAIL_NAMES = {"SWA", "SWB", "SWC", "SWD"};

using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;;

// Arrays to easily index common parameters by rail
static constexpr uint8_t const VOLT_SETTING_ACTIVE_REGS[] =
{
    REGS::R21_SWA_VOLTAGE_SETTING,
    REGS::R23_SWB_VOLTAGE_SETTING,
    REGS::R25_SWC_VOLTAGE_SETTING,
    REGS::R27_SWD_VOLTAGE_SETTING,
};

static constexpr uint8_t const VOLT_SETTING_VENDOR_REGS[] =
{
    REGS::R45_SWA_VOLTAGE_SETTING,
    REGS::R47_SWB_VOLTAGE_SETTING,
    REGS::R49_SWC_VOLTAGE_SETTING,
    REGS::R4B_SWD_VOLTAGE_SETTING,
};

static constexpr uint8_t const VOLT_RANGE_FLDS[] =
{
    FIELDS::SWA_VOLTAGE_RANGE,
    FIELDS::SWB_VOLTAGE_RANGE,
    FIELDS::SWC_VOLTAGE_RANGE,
    FIELDS::SWD_VOLTAGE_RANGE,
};

static constexpr uint32_t const VOLT_RANGE_MINS[][CONSTS::NUM_RANGES] =
{
    {CONSTS::SWABC_VOLT_RANGE0_MIN, CONSTS::SWABC_VOLT_RANGE1_MIN},
    {CONSTS::SWABC_VOLT_RANGE0_MIN, CONSTS::SWABC_VOLT_RANGE1_MIN},
    {CONSTS::SWABC_VOLT_RANGE0_MIN, CONSTS::SWABC_VOLT_RANGE1_MIN},
    {CONSTS::SWD_VOLT_RANGE0_MIN,   CONSTS::SWD_VOLT_RANGE1_MIN},
};

static constexpr uint32_t const VOLT_RANGE_MAXES[][CONSTS::NUM_RANGES] =
{
    {CONSTS::SWABC_VOLT_RANGE0_MAX, CONSTS::SWABC_VOLT_RANGE1_MAX},
    {CONSTS::SWABC_VOLT_RANGE0_MAX, CONSTS::SWABC_VOLT_RANGE1_MAX},
    {CONSTS::SWABC_VOLT_RANGE0_MAX, CONSTS::SWABC_VOLT_RANGE1_MAX},
    {CONSTS::SWD_VOLT_RANGE0_MAX,   CONSTS::SWD_VOLT_RANGE1_MAX},
};

///
/// @brief Get the valid pmics for id object
///
/// @param[in] i_pmic_target
/// @param[in] i_id
/// @param[out] o_pmics vector of PMICS matching
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
inline std::vector<fapi2::Target<fapi2::TARGET_TYPE_PMIC>> get_valid_pmics_for_id(
            const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
            const mss::pmic::id i_id)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_PMIC>> l_output_pmics;

    const auto l_pmics = mss::find_targets<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target);

    for (const auto& l_pmic : l_pmics)
    {
        if (mss::index(l_pmic) % CONSTS::NUM_PRIMARY_PMICS == i_id)
        {
            l_output_pmics.push_back(l_pmic);
        }
    }

    return l_output_pmics;
}

///
/// @brief Determine if PMIC is disabled based on ATTR_MEM_PMIC_FORCE_N_MODE attribute setting
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_disabled true/false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else, error code
///
fapi2::ReturnCode disabled(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target, bool& o_disabled);

///
/// @brief Run the provided function if the PMIC is present and not overridden to N-Mode
///
/// @tparam F function type (expected to be lambda)
/// @param[in] i_pmic_map Map of pmic ID to pmic target
/// @param[in] i_pmic_id desired pmic ID to key on
/// @param[in] i_func lambda function to run if given PMIC is not disabled
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
template<typename F>
fapi2::ReturnCode run_if_present(
    const std::map<size_t, fapi2::Target<fapi2::TARGET_TYPE_PMIC>>& i_pmic_map,
    const uint8_t i_pmic_id,
    const F i_func)
{
    // No const here due to the HB implementation of map/iterator: Does not allow for
    // const iterators to perform the -> operator (has trouble de-const'ing)
    auto l_pmic_it = i_pmic_map.find(i_pmic_id);
    bool l_disabled = false;

    // If we don't have the PMIC in the map, then platform never provided it as present,
    // so we should just exit, do not run i_func()
    if ( l_pmic_it == i_pmic_map.end() )
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    const auto& l_pmic = l_pmic_it->second;

    // PMIC does exist, now see if it was overridden to disabled via ATTR_PMIC_FORCE_N_MODE
    FAPI_TRY(mss::pmic::disabled(l_pmic, l_disabled));

    // PMIC target provided here. Other arguments to be provided via capture list
    if (!l_disabled)
    {
        FAPI_TRY(i_func(l_pmic));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks PMIC for VIN_BULK above minimum tolerance
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode success if good, else, error code
///
fapi2::ReturnCode check_vin_bulk_good(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Get the minimum vin bulk threshold
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_vin_bulk_min VIN bulk minimum value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode get_minimum_vin_bulk_threshold(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    uint16_t& o_vin_bulk_min);

///
/// @brief Helper function to get the minimum vin bulk threshold
///
/// @param[in] i_vin_bulk_min_threshold
/// @param[in] i_is_ti PMIC is TI
/// @param[in] i_rev PMIC revision
/// return VIN bulk minimum value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
uint16_t get_minimum_vin_bulk_threshold_helper(
    const uint8_t i_vin_bulk_min_threshold,
    const bool i_is_ti,
    const uint8_t i_rev);

///
/// @brief Disable the ADC for the pmic
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode disable_pmic_adc(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Enable the ADC for the pmic
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode enable_pmic_adc(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);;

///
/// @brief Unlocks PMIC vendor region
///
/// @param[in] i_pmic_target JEDEC-COMPLIANT PMIC to unlock
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode unlock_vendor_region(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Locks PMIC vendor region
///
/// @param[in] i_pmic_target - JEDEC-COMPLIANT PMIC to lock
/// @param[in] i_rc - return code from the end of the caller function (if applicable)
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff i_rc == SUCCESS && no errors in unlocking, else return current_err
///
fapi2::ReturnCode lock_vendor_region(const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
                                     const fapi2::ReturnCode i_rc = fapi2::FAPI2_RC_SUCCESS);

///
/// @brief Check if PMIC is IDT vendor
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_is_idt true/false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode pmic_is_idt(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target, bool& o_is_idt);

///
/// @brief Check if PMIC is TI vendor
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_is_ti true/false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode pmic_is_ti(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target, bool& o_is_ti);


///
/// @brief Calculate target voltage for PMIC from attribute settings
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_id relative ID of PMIC (0/1)
/// @param[in] i_rail RAIL to calculate voltage for
/// @param[out] o_volt_bitmap output bitmap
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode calculate_voltage_bitmap_from_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const mss::pmic::id i_id,
    const uint8_t i_rail,
    uint8_t& o_volt_bitmap);

///
/// @brief Calculate nominal rail voltages
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_id ID of pmic (0,1)
/// @param[in] i_rail SWA through SWD mapped as 0 to 3
/// @param[out] o_nominal_voltage calculated nominal voltage, shifted in place for register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode calculate_4u_nominal_voltage(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint8_t i_id,
    const uint8_t i_rail,
    uint8_t& o_nominal_voltage);

///
/// @brief Get PMIC position/ID under OCMB target. There could be 4 pmics, but we care about whether its PMIC0(2) or PMIC1(3)
///
/// @param[in] i_pmic_target
/// @return mss::pmic::id
///
inline mss::pmic::id get_relative_pmic_id(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    return static_cast<mss::pmic::id>(mss::index(i_pmic_target) % CONSTS::NUM_PRIMARY_PMICS);
}

namespace status
{

///
/// @brief Information for each field that we can iterate through
///
struct status_field
{
    uint8_t iv_reg_field;
    const char* iv_error_description;
    bool iv_assert_out;
};

static const std::vector<std::pair<uint8_t, std::vector<status_field>>> IDT_SPECIFIC_STATUS_FIELDS =
{
    {
        REGS::R04,
        {   {FIELDS::R04_GLOBAL_ERROR_COUNT, "GLOBAL_ERROR_COUNT: >1 error count since last erase operation", true},
            {FIELDS::R04_GLOBAL_ERROR_LOG_BUCK_OV_OR_UV, "GLOBAL_ERROR_LOG: BUCK OV/UV: Error occurred", true},
            {FIELDS::R04_GLOBAL_ERROR_LOG_VIN_BULK_OVER_VOLTAGE, "GLOBAL_ERROR_LOG: VIN_BULK_OVER_VOLTAGE", true},
            {FIELDS::R04_GLOBAL_ERROR_LOG_CRITICAL_TEMPERATURE, "GLOBAL_ERROR_LOG: CRITICAL_TEMPERATURE", true},
        }
    },

    {
        REGS::R05,
        {   {FIELDS::R05_SWA_POWER_GOOD, "PMIC POWER ON: SWA_PWR_NOT_GOOD", true},
            {FIELDS::R05_SWB_POWER_GOOD, "PMIC POWER ON: SWB_PWR_NOT_GOOD", true},
            {FIELDS::R05_SWC_POWER_GOOD, "PMIC POWER ON: SWC_PWR_NOT_GOOD", true},
            {FIELDS::R05_SWD_POWER_GOOD, "PMIC POWER ON: SWD_PWR_NOT_GOOD", true},
        }
    },

    {
        REGS::R06,
        {   {FIELDS::R06_SWA_UNDER_VOLTAGE_LOCKOUT, "SWA_UNDER_VOLTAGE_LOCKOUT", true},
            {FIELDS::R06_SWB_UNDER_VOLTAGE_LOCKOUT, "SWB_UNDER_VOLTAGE_LOCKOUT", true},
            {FIELDS::R06_SWC_UNDER_VOLTAGE_LOCKOUT, "SWC_UNDER_VOLTAGE_LOCKOUT", true},
            {FIELDS::R06_SWD_UNDER_VOLTAGE_LOCKOUT, "SWD_UNDER_VOLTAGE_LOCKOUT", true},
            {FIELDS::R06_SWA_OVER_VOLTAGE, "SWA_OVER_VOLTAGE", true},
            {FIELDS::R06_SWB_OVER_VOLTAGE, "SWB_OVER_VOLTAGE", true},
            {FIELDS::R06_SWC_OVER_VOLTAGE, "SWC_OVER_VOLTAGE", true},
            {FIELDS::R06_SWD_OVER_VOLTAGE, "SWD_OVER_VOLTAGE", true},
        }
    }
};

///
/// @brief const vector of statuses to check
///
static const std::vector<std::pair<uint8_t, std::vector<status_field>>> STATUS_FIELDS =
{
    {
        REGS::R08,
        {   {FIELDS::R08_VIN_BULK_INPUT_PWR_GOOD_STATUS, "VIN_BULK_INPUT_PWR_NOT_GOOD", true},
            {FIELDS::R08_CRITICAL_TEMP_SHUTDOWN_STATUS,  "CRITICAL_TEMP_SHUTDOWN", true},
            {FIELDS::R08_SWA_PWR_GOOD_STATUS,            "SWA_PWR_NOT_GOOD", true},
            {FIELDS::R08_SWB_PWR_GOOD_STATUS,            "SWB_PWR_NOT_GOOD", true},
            {FIELDS::R08_SWC_PWR_GOOD_STATUS,            "SWC_PWR_NOT_GOOD", true},
            {FIELDS::R08_SWD_PWR_GOOD_STATUS,            "SWD_PWR_NOT_GOOD", true},
            {FIELDS::R08_VIN_MGMT_INPUT_OVER_VOLTAGE,    "VIN_MGMT_INPUT_OVER_VOLTAGE", true},
            {FIELDS::R08_VIN_BULK_INPUT_OVER_VOLTAGE,    "VIN_BULK_INPUT_OVER_VOLTAGE", true},
        }
    },

    {
        REGS::R09,
        {   {FIELDS::R09_PMIC_HIGH_TEMP_WARNING_STATUS,                      "PMIC Temperature exceeded warning threshold", true},
            {FIELDS::R09_VBIAS_PWR_GOOD_STATUS,                              "VBIAS_PWR_NOT_GOOD", true},
            {FIELDS::R09_VOUT_1_8_V_PWR_GOOD_STATUS,                         "VOUT_1.8V_PWR_NOT_GOOD", true},
            {FIELDS::R09_VIN_MGMT_TO_VIN_BULK_SWITCHOVER_STATUS,             "VIN_MGMT is removed (using VIN_Bulk)", true},

            // Do not assert out for High Output Current Consumption Warning
            {FIELDS::R09_SWA_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING_STATUS, "SWA_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING", false},
            {FIELDS::R09_SWB_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING_STATUS, "SWB_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING", false},
            {FIELDS::R09_SWC_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING_STATUS, "SWC_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING", false},
            {FIELDS::R09_SWD_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING_STATUS, "SWD_HIGH_OUTPUT_CURRENT_CONSUMPTION_WARNING", false},
        }
    },

    {
        REGS::R0A,
        {   {FIELDS::R0A_SWA_OUTPUT_OVER_VOLTAGE_STATUS, "SWA_OUTPUT_OVER_VOLTAGE", true},
            {FIELDS::R0A_SWB_OUTPUT_OVER_VOLTAGE_STATUS, "SWB_OUTPUT_OVER_VOLTAGE", true},
            {FIELDS::R0A_SWC_OUTPUT_OVER_VOLTAGE_STATUS, "SWC_OUTPUT_OVER_VOLTAGE", true},
            {FIELDS::R0A_SWD_OUTPUT_OVER_VOLTAGE_STATUS, "SWD_OUTPUT_OVER_VOLTAGE", true},
            {FIELDS::R0A_PEC_ERROR_STATUS,               "PEC_ERROR", true},
            {FIELDS::R0A_PARITY_ERROR_STATUS,            "PARITY_ERROR", true},
            {FIELDS::R0A_IBI_STATUS,                     "PENDING_IBI", true},
        }
    },

    {
        REGS::R0B,
        {   {FIELDS::R0B_SWA_OUTPUT_CURRENT_LIMITER_WARNING_STATUS, "SWA_OUTPUT_CURRENT_LIMITER_EVENT", true},
            {FIELDS::R0B_SWB_OUTPUT_CURRENT_LIMITER_WARNING_STATUS, "SWB_OUTPUT_CURRENT_LIMITER_EVENT", true},
            {FIELDS::R0B_SWC_OUTPUT_CURRENT_LIMITER_WARNING_STATUS, "SWC_OUTPUT_CURRENT_LIMITER_EVENT", true},
            {FIELDS::R0B_SWD_OUTPUT_CURRENT_LIMITER_WARNING_STATUS, "SWD_OUTPUT_CURRENT_LIMITER_EVENT", true},
            {FIELDS::R0B_SWA_OUTPUT_UNDER_VOLTAGE_LOCKOUT_STATUS  , "SWA_OUTPUT_UNDER_VOLTAGE_LOCKOUT", true},
            {FIELDS::R0B_SWB_OUTPUT_UNDER_VOLTAGE_LOCKOUT_STATUS  , "SWB_OUTPUT_UNDER_VOLTAGE_LOCKOUT", true},
            {FIELDS::R0B_SWC_OUTPUT_UNDER_VOLTAGE_LOCKOUT_STATUS  , "SWC_OUTPUT_UNDER_VOLTAGE_LOCKOUT", true},
            {FIELDS::R0B_SWD_OUTPUT_UNDER_VOLTAGE_LOCKOUT_STATUS  , "SWD_OUTPUT_UNDER_VOLTAGE_LOCKOUT", true},
        }
    }
};

///
/// @brief Checks that the PMIC is enabled via VR Enable bit
///
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_for_vr_enable(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Helper function for check_all_pmics, returns one RC
///
/// @param[in] i_ocmb_target OCMB targer
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode Returns the first bad RC found, otherwise, success
///
fapi2::ReturnCode check_all_pmics_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Check the statuses of all PMICs present on the given OCMB chip
///
/// @param[in] i_ocmb_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
/// @note To be used with 1U/2U Enable sequence
///
fapi2::ReturnCode check_all_pmics(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target);

///
/// @brief Check the PMIC's status codes and report back if an error occurred
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_error true/false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode check_pmic(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target, bool& o_error);

///
/// @brief Clear PMIC status registers
///
/// @param[in] i_pmic_target PMIC to clear
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode clear(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Check an individual set of PMIC status codes
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_error_type error type for the PMIC in question
/// @param[in] i_statuses STATUS object to check
/// @param[out] o_error At least one error bit was found to be set
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error in case of an I2C read error
///
fapi2::ReturnCode check_fields(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const char* i_error_type,
    const std::vector<std::pair<uint8_t, std::vector<status_field>>>& i_statuses,
    bool& o_error);

} // status
} // pmic
} // mss

#endif
