/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/utils/pmic_common_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __PMIC_COMMON_UTILS_H__
#define __PMIC_COMMON_UTILS_H__

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <lib/utils/pmic_consts.H>
#include <mss_pmic_attribute_getters.H>
#include <generic/memory/lib/utils/fapi_try_lambda.H>

namespace mss
{
namespace pmic
{
using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;;
using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;
using TPS_CONSTS = mss::pmic::consts<mss::pmic::product::TPS5383X>;;
using TPS_FIELDS = pmicFields<mss::pmic::product::TPS5383X>;

// For output traces
static constexpr const char* PMIC_RAIL_NAMES[] = {"SWA", "SWB", "SWC", "SWD"};

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
    {CONSTS::SWABC_VOLT_RANGE0_MIN, CONSTS::SWABC_VOLT_RANGE1_MIN, CONSTS::SWABC_VOLT_RANGE1_MIN},
    {CONSTS::SWABC_VOLT_RANGE0_MIN, CONSTS::SWABC_VOLT_RANGE1_MIN, CONSTS::SWABC_VOLT_RANGE1_MIN},
    {CONSTS::SWABC_VOLT_RANGE0_MIN, CONSTS::SWABC_VOLT_RANGE1_MIN, CONSTS::SWCD_VOLT_RANGE2_MIN},
    {CONSTS::SWD_VOLT_RANGE0_MIN,   CONSTS::SWD_VOLT_RANGE1_MIN,   CONSTS::SWCD_VOLT_RANGE2_MIN},
};

static constexpr uint32_t const VOLT_RANGE_MAXES[][CONSTS::NUM_RANGES] =
{
    {CONSTS::SWABC_VOLT_RANGE0_MAX, CONSTS::SWABC_VOLT_RANGE1_MAX, CONSTS::SWABC_VOLT_RANGE1_MAX},
    {CONSTS::SWABC_VOLT_RANGE0_MAX, CONSTS::SWABC_VOLT_RANGE1_MAX, CONSTS::SWABC_VOLT_RANGE1_MAX},
    {CONSTS::SWABC_VOLT_RANGE0_MAX, CONSTS::SWABC_VOLT_RANGE1_MAX, CONSTS::SWCD_VOLT_RANGE2_MAX},
    {CONSTS::SWD_VOLT_RANGE0_MAX,   CONSTS::SWD_VOLT_RANGE1_MAX,   CONSTS::SWCD_VOLT_RANGE2_MAX},
};


static constexpr uint8_t const VOLT_VID_OFFSET_COARSE_DEFAULT[] =
{
    TPS_CONSTS::R78_SWA_VID_OFFSET_COARSE_DEFAULT,
    TPS_CONSTS::R78_SWB_VID_OFFSET_COARSE_DEFAULT,
    TPS_CONSTS::R78_SWC_VID_OFFSET_COARSE_DEFAULT,
    TPS_CONSTS::R78_SWD_VID_OFFSET_COARSE_DEFAULT,
};

static constexpr uint32_t const VOLT_RANGE_VID_OFFSET_COARSE_MINS[][TPS_CONSTS::R78_NUM_RANGES] =
{
    {
        TPS_CONSTS::R78_VOLT_SWABCD_RANGE0_MIN, TPS_CONSTS::R78_VOLT_SWABCD_RANGE1_MIN,
        TPS_CONSTS::R78_VOLT_SWABCD_RANGE2_MIN, TPS_CONSTS::R78_VOLT_SWABCD_RANGE3_MIN
    },
    {
        TPS_CONSTS::R78_VOLT_SWABCD_RANGE0_MIN, TPS_CONSTS::R78_VOLT_SWABCD_RANGE1_MIN,
        TPS_CONSTS::R78_VOLT_SWABCD_RANGE2_MIN, TPS_CONSTS::R78_VOLT_SWABCD_RANGE3_MIN
    },
    {
        TPS_CONSTS::R78_VOLT_SWABCD_RANGE0_MIN, TPS_CONSTS::R78_VOLT_SWABCD_RANGE1_MIN,
        TPS_CONSTS::R78_VOLT_SWABCD_RANGE2_MIN, TPS_CONSTS::R78_VOLT_SWABCD_RANGE3_MIN
    },
    {
        TPS_CONSTS::R78_VOLT_SWABCD_RANGE0_MIN, TPS_CONSTS::R78_VOLT_SWABCD_RANGE1_MIN,
        TPS_CONSTS::R78_VOLT_SWABCD_RANGE2_MIN, TPS_CONSTS::R78_VOLT_SWABCD_RANGE3_MIN
    },
};

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
/// @brief Check number of pmics received for 2U. If < 2, then throw an error
///
/// @param[in] i_ocmb_target OCMB target parent of PMICs
/// @param[in] i_pmics_size number of PMIC received
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_number_pmics_received_2u(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const uint8_t i_pmics_size);

///
/// @brief Determine if PMIC is disabled based on ATTR_MEM_PMIC_FORCE_N_MODE attribute setting
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_disabled true/false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else, error code
///
fapi2::ReturnCode disabled(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target, bool& o_disabled);

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

///
/// @brief Calculate target voltage for PMIC from attribute settings
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_id relative ID of PMIC (0/1) (or PMIC2 or PMIC3 for DDR5)
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
/// @brief Set the current limiter warning registers via attributes
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_relative_pmic_id relative PMIC position (0/1 if DDR4, 0/1/2/3 if DDR5)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode set_current_limiter_warnings(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_relative_pmic_id);

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
/// @brief Update PMIC sequence based on SPD rev 0.0
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id PMIC0 or PMIC1
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode update_seq_with_order_and_delay_attr(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id);

///
/// @brief Update PMIC sequence based on the SPD version 0.7.0
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_id PMIC2 or PMIC3
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode update_seq_with_reg_attr(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        const mss::pmic::id i_id);;

///
/// @brief bias PMIC with spd settings for phase combination (SWA, SWB or SWA+SWB)
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target - OCMB parent target of pmic
/// @param[in] i_id - PMIC0 or PMIC1 (or PMIC2 or PMIC3 for DDR5)
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
/// @param[in] i_id PMIC0 or PMIC1 (or PMIC2 or PMIC3 for DDR5)
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
/// @param[in] i_id PMIC0 or PMIC1 (or PMIC2 or PMIC3 for DDR5)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode bias_with_spd_startup_seq(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id);

//-----------------------------------
// Templated SPD Biasing functions
//-----------------------------------
///
/// @brief Bias with spd voltages for TI pmic with revision less than 0x23
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id relative ID of PMIC (0/1) (or PMIC2 or PMIC3 for DDR5)
/// @param[in] i_rail_index SWA/SWB/SWC/SWD rails of pmic
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode bias_with_spd_voltages_TI_rev_less_then_23(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id,
    const uint8_t i_rail_index);

///
/// @brief Bias with spd voltages for IDT pmic
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_id relative ID of PMIC (0/1) (or PMIC2 or PMIC3 for DDR5)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template <mss::pmic::vendor V>
fapi2::ReturnCode bias_with_spd_voltages(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_id);

///
/// @brief Bias PMIC from SPD settings per vendor
///
/// @tparam V mss::pmic::vendor (IDT/TI)
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_ocmb_target OCMB parent target of pmic
/// @param[in] i_relative_pmic_id relative PMIC position (0/1 if DDR4, 0/1/2/3 if DDR5)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template <mss::pmic::vendor V>
fapi2::ReturnCode bias_with_spd_settings(
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_PMIC>& i_pmic_target,
    const fapi2::Target<fapi2::TargetType::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::id i_relative_pmic_id);

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
/// @brief Data for each status rgeister for error reporting
///
struct status_regs
{
    uint8_t iv_r04;
    uint8_t iv_r05;
    uint8_t iv_r06;
    uint8_t iv_r08;
    uint8_t iv_r09;
    uint8_t iv_r0A;
    uint8_t iv_r0B;
    uint8_t iv_r33;
    uint8_t iv_r73;
};

///
/// @brief Information for each field that we can iterate through
///
struct status_field
{
    uint8_t iv_reg_field;
    const char* iv_error_description;
    bool iv_assert_out;
};

///
/// @brief Unlock PMIC registers R70 to RA3
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode unlock_pmic_r70_to_ra3(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Lock PMIC registers R70 to RA3
///
/// @param[in] i_pmic_target PMIC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode lock_pmic_r70_to_ra3(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Clear PMIC status registers
///
/// @param[in] i_pmic_target PMIC to clear
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode clear(const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

#ifndef __PPE__
///
/// @brief const vector of statuses to check
///
static const std::vector<std::pair<uint8_t, std::vector<status_field>>> ERROR_LOG_REG_FIELDS =
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
static const std::vector<std::pair<uint8_t, std::vector<status_field>>> STATUS_FIELDS_TI_LT_REV23 =
{
    // TI REV < 0x23 has some R0A status bits different than other PMICs and revisions
    {
        REGS::R0A,
        {   {FIELDS::R0A_SWA_OUTPUT_OVER_VOLTAGE_STATUS,  "SWA_OUTPUT_OVER_VOLTAGE", true},
            {FIELDS::R0A_SWB_OUTPUT_OVER_VOLTAGE_STATUS,  "SWB_OUTPUT_OVER_VOLTAGE", true},
            {FIELDS::R0A_SWC_OUTPUT_OVER_VOLTAGE_STATUS,  "SWC_OUTPUT_OVER_VOLTAGE", true},
            {FIELDS::R0A_SWD_OUTPUT_OVER_VOLTAGE_STATUS,  "SWD_OUTPUT_OVER_VOLTAGE", true},
            {TPS_FIELDS::R0A_SWA_NEG_OVER_CURRENT_STATUS, "SWA_NEGATIVE_OVER_CURRENT", true},
            {TPS_FIELDS::R0A_SWB_NEG_OVER_CURRENT_STATUS, "SWB_NEGATIVE_OVER_CURRENT", true},
            {TPS_FIELDS::R0A_SWC_NEG_OVER_CURRENT_STATUS, "SWC_NEGATIVE_OVER_CURRENT", true},
            {TPS_FIELDS::R0A_SWD_NEG_OVER_CURRENT_STATUS, "SWD_NEGATIVE_OVER_CURRENT", true},
        }
    }
};

///
/// @brief const vector of statuses to check
///
static const std::vector<std::pair<uint8_t, std::vector<status_field>>> STATUS_FIELDS_NOT_TI_LT_REV23 =
{
    // R0A status bits for other PMICs that are not TI REV < 0x23
    {
        REGS::R0A,
        {   {FIELDS::R0A_SWA_OUTPUT_OVER_VOLTAGE_STATUS,  "SWA_OUTPUT_OVER_VOLTAGE", true},
            {FIELDS::R0A_SWB_OUTPUT_OVER_VOLTAGE_STATUS,  "SWB_OUTPUT_OVER_VOLTAGE", true},
            {FIELDS::R0A_SWC_OUTPUT_OVER_VOLTAGE_STATUS,  "SWC_OUTPUT_OVER_VOLTAGE", true},
            {FIELDS::R0A_SWD_OUTPUT_OVER_VOLTAGE_STATUS,  "SWD_OUTPUT_OVER_VOLTAGE", true},
            {FIELDS::R0A_PEC_ERROR_STATUS,                "PEC_ERROR", true},
            {FIELDS::R0A_PARITY_ERROR_STATUS,             "PARITY_ERROR", true},
            // This is aglobal status bit. If any of the other status bits are set, this sets (including the warnings).
            // We do not want to trigger on warnings. Hence have commented this out.
            // This functionality is the same for DDR4. COmmenting this out here should not be an issue for DDR4
            // This can go into DDR4 1060FW release.
            //{FIELDS::R0A_IBI_STATUS,                      "PENDING_IBI", true},
        }
    }
};

///
/// @brief const vector of statuses to check
///
static const std::vector<std::pair<uint8_t, std::vector<status_field>>> STATUS_FIELDS_TI_GTE_REV23 =
{
    // TI REV >= 0x23 status bits unique to this PMIC
    {
        // R73 - don't forget to unlock this for reading
        TPS_REGS::R73,
        {   {TPS_FIELDS::R73_VIN_OK_Z,                    "VIN_NOT_OK", true},
            {TPS_FIELDS::R73_SWD_NEG_OVER_CURRENT_STATUS, "SWD_NEGATIVE_OVER_CURRENT", true},
            {TPS_FIELDS::R73_SWC_NEG_OVER_CURRENT_STATUS, "SWC_NEGATIVE_OVER_CURRENT", true},
            {TPS_FIELDS::R73_SWB_NEG_OVER_CURRENT_STATUS, "SWB_NEGATIVE_OVER_CURRENT", true},
            {TPS_FIELDS::R73_SWA_NEG_OVER_CURRENT_STATUS, "SWA_NEGATIVE_OVER_CURRENT", true},
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
    },

    {
        REGS::R33,
        {   {FIELDS::R33_VIN_MGMT_PGOOD_SWITCHOVER_MODE_STATUS, "VIN_MGMT_PGOOD_SWITCHOVER_MODE", true},
            {FIELDS::R33_VIN_BULK_UNDER_VOLTAGE_LOCKOUT_STATUS, "VIN_BULK_UNDER_VOLTAGE_LOCKOUT", true},
            {FIELDS::R33_VOUT_1P0V_OUTPUT_POWER_GOOD_STATUS,    "VOUT_1P0V_OUTPUT_POWER_GOOD", true},
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
/// @param[in,out] io_values value of status registers on this PMIC
/// @param[out] o_error true/false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode check_pmic(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    status_regs& io_values,
    bool& o_error);

///
/// @brief Helper to fill in pmic::status::status_regs struct
///
/// @param[in] i_reg status register address
/// @param[in] i_value status register value
/// @param[in,out] io_values value of status registers on this PMIC
///
void status_reg_save_helper(
    const uint8_t i_reg,
    const uint8_t i_value,
    status_regs& io_values);

///
/// @brief Check an individual set of PMIC status codes
///
/// @param[in] i_pmic_target PMIC target
/// @param[in] i_error_type error type for the PMIC in question
/// @param[in] i_statuses STATUS object to check
/// @param[in,out] io_values value of status registers on this PMIC
/// @param[out] o_error At least one error bit was found to be set
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error in case of an I2C read error
///
fapi2::ReturnCode check_fields(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const char* i_error_type,
    const std::vector<std::pair<uint8_t, std::vector<status_field>>>& i_statuses,
    status_regs& io_values,
    bool& o_error);

#endif

} // status

namespace check
{

///
/// @brief Unit testable helper function: Check that the IDT revision # register and attribute match
///
/// @param[in] i_pmic_target PMIC target (for FFDC)
/// @param[in] i_rev_attr revision value from attribute
/// @param[in] i_rev_reg revision value from register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode validate_and_return_idt_revisions_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint8_t i_rev_attr,
    const uint8_t i_rev_reg);

///
/// @brief Check that the IDT revision # register and attribute match and return revision number.
///        In case of TI, just return the revision number
///
/// @param[in]  i_ocmb_target OCMB target
/// @param[in]  i_pmic_target PMIC target to check
/// @param[in]  i_vendor_id to run IDT revision check
/// @param[out] o_rev_reg revision number of PMIC
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode validate_and_return_pmic_revisions(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint16_t i_vendor_id,
    fapi2::buffer<uint8_t>& o_rev_reg);

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

} // check
} // pmic
} // mss

#endif
