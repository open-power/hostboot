/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_common_utils_ddr5.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @brief Utility functions common for several PMIC DDR5 procedures
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#ifndef __PMIC_COMMON_UTILS_DDR5_H__
#define __PMIC_COMMON_UTILS_DDR5_H__

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <i2c_pmic.H>
#include <pmic_consts.H>
#include <pmic_common_utils.H>
#include <mss_pmic_attribute_getters.H>
#include <mss_pmic_attribute_accessors_manual.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{
namespace pmic
{
namespace ddr5
{
using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

// Extra constants
static constexpr uint16_t CURRENT_MULTIPLIER = 125;
static constexpr uint16_t PHASE_MIN = 250;
static constexpr uint16_t PHASE_MAX = 1500;

///
/// @brief
///
enum data_position : uint8_t
{
    DATA_0   = 0,
    DATA_1   = 1,
    DATA_2   = 2,
    DATA_3   = 3,
    DATA_4   = 4,
    DATA_5   = 5,
    DATA_6   = 6,
    DATA_7   = 7,
    DATA_8   = 8,
    DATA_9   = 9,
    DATA_10  = 10,
    DATA_11  = 11,
    DATA_12  = 12,
    DATA_13  = 13,
    DATA_14  = 14,
    DATA_15  = 15,
};

///
/// @brief Trim read reset data
///
enum trim_rd_reset : uint16_t
{
    TRIM_UNLOCK            = 0x000E,
    TRIM_LOCK              = 0x000F,
    TRIM_RD_INIT           = 0x3F21,
    EXTENDABLE_RD_PULSE_EN = 0x4080,
    TRIM_PASSWORD          = 0xA55A,
};

///
/// @brief Bread crumb values to return
///
enum bread_crumb : uint8_t
{
    ALL_GOOD             = 0,
    FIRST_ATTEMPT        = 0x51,
    RECOVERY_ATTEMPTED   = 0x52,
    STILL_A_FAIL         = 0x53,
};

///
/// @brief N Mode State to return
///
enum aggregate_state : uint8_t
{
    N_PLUS_1                  = 0,
    N_MODE_POSSIBLE           = 1,
    N_MODE_RECOVERY_ATTEMPTED = 2,
    N_MODE                    = 3,
    LOST                      = 4,
    GI2C_I2C_FAIL             = 5,
    DIMM_NOT_4U               = 6,
};
///
/// @brief States for the pmics to be returned in a uint8_t bitmap
///
enum pmic_state : uint8_t
{
    PMIC_DECONFIGURED       = 0b10000000,
    PMIC_NOT_PRESENT        = 0b00001000,
    PMIC_I2C_FAIL           = 0b00000100,
    PMIC_CURRENT_IMBALANCE  = 0b00000010,
    PMIC_PWR_NOT_GOOD       = 0b00000001,
    PMIC_ALL_GOOD           = 0b00000000,
};

///
/// @brief States for the dts to be returned in a uint8_t bitmap
///
enum dt_state : uint8_t
{
    DT_DECONFIGURED  = 0b10000000,
    DT_NOT_PRESENT   = 0b01000000,
    DT_I2C_FAIL      = 0b00100000,
    DT_SWIN_FAULT_D  = 0b00010000,
    DT_SWIN_FAULT_C  = 0b00001000,
    DT_SWIN_FAULT_B  = 0b00000100,
    DT_SWIN_FAULT_A  = 0b00000010,
    DT_GPI_1         = 0b00000001,
    DT_ALL_GOOD      = 0b00000000,
};

///
/// @brief Struct for a pair of PMIC and DT target
/// @note PMIC and DTs have to be considered as a pair. If 1 PMIC is not available (for any reason),
///       the corresponding DT should be considered as not accessible too and vice-versa.
///
struct target_info_pmic_dt_pair
{
    fapi2::Target<fapi2::TARGET_TYPE_PMIC> iv_pmic;
    fapi2::Target<fapi2::TARGET_TYPE_POWER_IC> iv_dt;

    uint8_t iv_rel_pos = 0;

    // The below 'state' members will be used to keep track of individual pmic and dt states in this pair
    // These members will not be populated or used by pmic_enable but will be used by
    // health check and periodic telemetry tools
    uint8_t iv_pmic_state = 0;
    uint8_t iv_dt_state = 0;
    uint8_t reserved = 0;
};

///
/// @brief Struct for PMIC / DT / ADC target info for redundant PMIC configs
/// @note Requires a redundancy config, or else will try to grab null targets
///
struct target_info_redundancy_ddr5
{
    target_info_pmic_dt_pair iv_pmic_dt_map[CONSTS::NUM_PMICS_4U];
    fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER> iv_adc;

    uint8_t iv_number_of_target_infos_present = 0;

    uint8_t reserved = 0;
    uint16_t reserved0 = 0;

    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> iv_ocmb;

    target_info_redundancy_ddr5() = delete;

    /// @brief Construct a new target_info_redundancy_ddr5 object with the passed in targets
    /// @param[in] i_pmics Vector of PMIC targets
    /// @param[in] i_dts Vector of DT targets
    /// @param[in] i_adc ADC target
    /// @param[out] o_rc ReturnCode in case of construction error
    /// @note pmic_enable_ddr5.C plug rules ensures that a valid number of I2C, DT and PMIC children targets exist
    ///
    target_info_redundancy_ddr5(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PMIC>>& i_pmics,
                                const std::vector<fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>>& i_dts,
                                const std::vector<fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>>& i_adc,
                                fapi2::ReturnCode& o_rc);


    ///
    /// @brief Construct a new target_info_redundancy_ddr5 object
    ///
    /// @param[in] i_ocmb OCMB target
    /// @param[out] o_rc ReturnCode in case of construction error
    /// @note pmic_enable_ddr5.C plug rules ensures that a valid number of I2C, DT and PMIC children targets exist
    ///
    target_info_redundancy_ddr5(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb, fapi2::ReturnCode& o_rc);
};

///
/// @brief Run the provided function if the PMIC is present and not overridden to N-Mode
///
/// @tparam F function type (expected to be lambda)
/// @param[in] i_target_info target info struct
/// @param[in] i_pmic_id desired pmic ID to key on
/// @param[in] i_func lambda function to run if given PMIC is not disabled
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
template<typename F>
fapi2::ReturnCode run_if_present(
    const target_info_redundancy_ddr5& i_target_info,
    const uint8_t i_pmic_id,
    const F i_func)
{
    fapi2::Target<fapi2::TARGET_TYPE_PMIC> l_pmic;
    bool l_disabled = false;
    bool l_pmic_found = false;
    mss::pmic::n_mode l_pmic_dt_not_responding = mss::pmic::n_mode::N_PLUS_1_MODE;
    uint8_t l_count = 0;

    const uint8_t l_num_pmic_4u = CONSTS::NUM_PMICS_4U;
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target_info.iv_pmic_dt_map[0].iv_pmic);

    FAPI_ASSERT((i_pmic_id < l_num_pmic_4u),
                fapi2::INVALID_PMIC_INDEX_RECEIVED()
                .set_OCMB_TARGET(l_ocmb)
                .set_NUM_PMICS(i_pmic_id)
                .set_EXPECTED_MAX_PMICS(l_num_pmic_4u),
                GENTARGTIDFORMAT " Invalid PMIC index received. Maximum index supported is %u."
                "Given %u as index",
                GENTARGTID(l_ocmb),
                l_num_pmic_4u,
                i_pmic_id);

    for (l_count = 0; l_count <= i_target_info.iv_number_of_target_infos_present; l_count++)
    {
        if( i_pmic_id == i_target_info.iv_pmic_dt_map[l_count].iv_rel_pos)
        {
            l_pmic = i_target_info.iv_pmic_dt_map[i_pmic_id].iv_pmic;
            l_pmic_found = true;
            break;
        }
    }

    if (!l_pmic_found)
    {
        // If we don't have the PMIC in the target_info_redundancy_ddr5 struct, then platform never provided it as present,
        // so we should just exit, do not run i_func()
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // PMIC does exist, now see if it was overridden to disabled via ATTR_PMIC_FORCE_N_MODE
    FAPI_TRY(mss::pmic::disabled(l_pmic, l_disabled));

    // PMIC is present but not functional. We are checking this via ATTR_MEM_PMIC_4U_N_MODE attribute
    // Passing l_count here for PMIC ID as l_count represents the rel_pos of that PMIC
    FAPI_TRY(mss::attr::get_n_mode_helper(l_ocmb, l_count, l_pmic_dt_not_responding));

    // PMIC target provided here. Other arguments to be provided via capture list
    if ((!l_disabled) && (!l_pmic_dt_not_responding)
        && (i_target_info.iv_pmic_dt_map[l_count].iv_pmic_state != mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL))
    {
        FAPI_TRY(i_func(l_pmic));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Run the provided function if the DT is present and not overridden to N-Mode
///
/// @tparam F function type (expected to be lambda)
/// @param[in] i_target_info target info struct
/// @param[in] i_dt_id desired DT ID to key on
/// @param[in] i_func lambda function to run if given DT is not disabled
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
template<typename F>
fapi2::ReturnCode run_if_present_dt(
    const target_info_redundancy_ddr5& i_target_info,
    const uint8_t i_dt_id,
    const F i_func)
{
    fapi2::Target<fapi2::TARGET_TYPE_POWER_IC> l_dt;
    fapi2::Target<fapi2::TARGET_TYPE_PMIC> l_pmic;
    bool l_disabled = false;
    bool l_dt_found = false;
    mss::pmic::n_mode l_pmic_dt_not_responding = mss::pmic::n_mode::N_PLUS_1_MODE;
    uint8_t l_count = 0;

    const uint8_t l_num_dt_4u = CONSTS::NUM_DTS_4U;
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target_info.iv_pmic_dt_map[0].iv_dt);

    FAPI_ASSERT((i_dt_id < l_num_dt_4u),
                fapi2::INVALID_DT_INDEX_RECEIVED()
                .set_OCMB_TARGET(l_ocmb)
                .set_NUM_DTS(i_dt_id)
                .set_EXPECTED_MAX_DTS(l_num_dt_4u),
                GENTARGTIDFORMAT " Invalid DT index received. Maximum index supported is %u."
                "Given %u as index",
                GENTARGTID(l_ocmb),
                l_num_dt_4u,
                i_dt_id);

    for (l_count = 0; l_count <= i_target_info.iv_number_of_target_infos_present; l_count++)
    {
        if( i_dt_id == i_target_info.iv_pmic_dt_map[l_count].iv_rel_pos)
        {
            l_dt = i_target_info.iv_pmic_dt_map[i_dt_id].iv_dt;
            l_pmic = i_target_info.iv_pmic_dt_map[i_dt_id].iv_pmic;
            l_dt_found = true;
            break;
        }
    }

    if (!l_dt_found)
    {
        // If we don't have the DT in the target_info_redundancy_ddr5 struct, then platform never provided it as present,
        // so we should just exit, do not run i_func()
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // DT does exist, now see if it was overridden to disabled via ATTR_PMIC_FORCE_N_MODE
    // We are using the PMIC target here as PMIC and DT are a pair
    FAPI_TRY(mss::pmic::disabled(l_pmic, l_disabled));

    // DT is present but not functional. Since we are treating PMIC and DT as a pair,
    // we are checking this via ATTR_MEM_PMIC_4U_N_MODE attribute
    // Passing l_count here for DT ID as l_count represents the rel_pos of that DT
    FAPI_TRY(mss::attr::get_n_mode_helper(l_ocmb, l_count, l_pmic_dt_not_responding));

    // DT target provided here. Other arguments to be provided via capture list
    if ((!l_disabled) && (!l_pmic_dt_not_responding)
        && (i_target_info.iv_pmic_dt_map[l_count].iv_dt_state != mss::pmic::ddr5::dt_state::DT_I2C_FAIL))
    {
        FAPI_TRY(i_func(l_dt));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to get the minimum vin bulk threshold
///
/// @param[in] i_vin_bulk_min_threshold
/// @return VIN bulk minimum value
///
uint16_t get_minimum_vin_bulk_threshold_helper(
    const uint8_t i_vin_bulk_min_threshold);

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
/// @brief Struct of DT health check telemetry to populate
///
struct __attribute__((__packed__)) dt_health_check_telemetry
{
    uint8_t  iv_breadcrumb  = 0;
    uint8_t  reserved0      = 0;
    uint16_t iv_ro_inputs_1 = 0;

    uint16_t iv_ro_inputs_0 = 0;
    uint16_t reserved1      = 0;
};

///
/// @brief Struct of PMIC health check telemetry to populate
///
struct __attribute__((__packed__)) pmic_health_check_telemetry
{
    // Error register
    // Direct read from 8 bit register
    uint8_t iv_r04 = 0;
    uint8_t iv_r05 = 0;
    uint8_t iv_r06 = 0;
    uint8_t iv_r07 = 0;

    // Status register
    // Direct read from 8 bit register
    uint8_t iv_r08 = 0;
    uint8_t iv_r09 = 0;
    uint8_t iv_r0a = 0;
    uint8_t iv_r0b = 0;

    // Values in mA
    uint16_t iv_swa_current_mA = 0;
    uint16_t iv_swb_current_mA = 0;
    uint16_t iv_swc_current_mA = 0;
    uint16_t iv_swd_current_mA = 0;
};

///
/// @brief Struct of health check telemetry data
///
struct __attribute__((__packed__)) health_check_telemetry_data
{
    aggregate_state iv_aggregate_state = aggregate_state::N_PLUS_1;

    uint8_t reserved = 0;
    uint16_t reserved1 = 0;

    dt_health_check_telemetry iv_dt0;
    dt_health_check_telemetry iv_dt1;
    dt_health_check_telemetry iv_dt2;
    dt_health_check_telemetry iv_dt3;

    pmic_health_check_telemetry iv_pmic0;
    pmic_health_check_telemetry iv_pmic1;
    pmic_health_check_telemetry iv_pmic2;
    pmic_health_check_telemetry iv_pmic3;
};

///
/// @brief Struct of adc data for additional health check telemetry in case of n-mode
///
struct __attribute__ ((__packed__)) adc_additional_n_mode_telemetry_data
{
    uint8_t iv_system_status = 0;
    uint8_t iv_general_cfg   = 0;
    uint8_t iv_data_cfg      = 0;
    uint8_t iv_osr_cfg       = 0;

    uint8_t iv_opmode_cfg    = 0;
    uint8_t iv_pin_cfg       = 0;
    uint8_t iv_dummy_0       = 0;
    uint8_t iv_gpio_cfg      = 0;

    uint8_t iv_dummy_1       = 0;
    uint8_t iv_gpo_drive_cfg = 0;
    uint8_t iv_dummy_2       = 0;
    uint8_t iv_gpo_value_cfg = 0;

    uint8_t iv_dummy_3       = 0;
    uint8_t iv_gpi_value     = 0;
    uint8_t iv_dummy_4       = 0;
    uint8_t iv_dummy_5       = 0;
};

///
/// @brief Struct of pmic data for additional health check telemetry in case of n-mode
///
struct __attribute__ ((__packed__)) pmic_additional_n_mode_telemetry_data
{
    uint8_t iv_r2f_pmic_config   = 0;
    uint8_t iv_r32_pmic_enable   = 0;
    uint8_t iv_r33_temp_status   = 0;
    uint8_t iv_r73_status_5      = 0;

    uint8_t iv_r9c_on_off_config = 0;
    uint8_t reserved0            = 0;
    uint16_t reserved1           = 0;
};

///
/// @brief Struct of dt data for additional health check telemetry in case of n-mode
///
struct __attribute__ ((__packed__)) dt_additional_n_mode_telemetry_data
{
    uint16_t iv_r90_ops_state              = 0;
    uint16_t iv_r92_faults_status_0        = 0;

    uint16_t iv_r94_faults_status_1        = 0;
    uint16_t iv_r96_first_faults_status_0  = 0;

    uint16_t iv_r98_first_faults_status_1  = 0;
    uint16_t iv_ra6_infet_mpt_addr         = 0;

    uint16_t iv_ra8_nvm_data               = 0;
    uint16_t iv_rb4_vcc_vin_vinp           = 0;
};

///
/// @brief Struct of additional health check telemetry data in case of n-mode
///
struct __attribute__ ((__packed__)) additional_n_mode_telemetry_data
{
    adc_additional_n_mode_telemetry_data iv_adc;

    pmic_additional_n_mode_telemetry_data iv_pmic[CONSTS::NUM_PMICS_4U];

    dt_additional_n_mode_telemetry_data iv_dt[CONSTS::NUM_DTS_4U];
};

///
/// @brief Struct of adc data for periodic telemetry data collected once every 24 hours
///
struct __attribute__ ((__packed__)) adc_periodic_telemetry_data
{
    // These are the MSB and LSB,
    // two combined 8 bit registers
    uint16_t iv_max_ch0_mV = 0;
    uint16_t iv_max_ch1_mV = 0;
    uint16_t iv_max_ch2_mV = 0;
    uint16_t iv_max_ch3_mV = 0;
    uint16_t iv_max_ch4_mV = 0;
    uint16_t iv_max_ch5_mV = 0;
    uint16_t iv_max_ch6_mV = 0;
    uint16_t iv_max_ch7_mV = 0;

    uint16_t iv_min_ch0_mV = 0;
    uint16_t iv_min_ch1_mV = 0;
    uint16_t iv_min_ch2_mV = 0;
    uint16_t iv_min_ch3_mV = 0;
    uint16_t iv_min_ch4_mV = 0;
    uint16_t iv_min_ch5_mV = 0;
    uint16_t iv_min_ch6_mV = 0;
    uint16_t iv_min_ch7_mV = 0;

    uint16_t iv_recent_ch0_mV = 0;
    uint16_t iv_recent_ch1_mV = 0;
    uint16_t iv_recent_ch2_mV = 0;
    uint16_t iv_recent_ch3_mV = 0;
    uint16_t iv_recent_ch4_mV = 0;
    uint16_t iv_recent_ch5_mV = 0;
    uint16_t iv_recent_ch6_mV = 0;
    uint16_t iv_recent_ch7_mV = 0;
};

///
/// @brief Struct of pmic data for periodic telemetry data collected once every 24 hours
///
struct __attribute__ ((__packed__)) pmic_periodic_telemetry_data
{
    // Values in mA
    uint16_t iv_swa_current_mA     = 0;
    uint16_t iv_swb_current_mA     = 0;
    uint16_t iv_swc_current_mA     = 0;
    uint16_t iv_swd_current_mA     = 0;

    uint16_t iv_r31_sample_vin     = 0;
    uint16_t iv_r31_sample_temp    = 0;

    uint8_t iv_r7c_set_swa_offset = 0;
    uint8_t iv_r7d_set_swb_offset = 0;
    uint8_t iv_r7e_set_swc_offset = 0;
    uint8_t iv_r7f_set_swd_offset = 0;
};

///
/// @brief Struct of dt data for periodic telemetry data collected once every 24 hours
///
struct __attribute__ ((__packed__)) dt_periodic_telemetry_data
{
    uint16_t iv_r9a_iin  = 0;
    uint16_t iv_r9b_vcc  = 0;

    uint16_t iv_r9c_vinp = 0;
    uint16_t iv_r9d_vin  = 0;

    uint16_t iv_r9e_vaux_b = 0;
    uint16_t iv_r9f_vaux_a = 0;

    uint16_t iv_ra0_vaux_d = 0;
    uint16_t iv_ra1_vaux_c = 0;

    uint16_t iv_ra2_vinp_min = 0;
    uint16_t iv_ra3_vinp_max = 0;

    uint16_t iv_ra4_iin_min  = 0;
    uint16_t iv_ra5_iin_max  = 0;

    uint8_t iv_breadcrumb        = 0;
    uint8_t iv_recovery_count    = 0;
    uint8_t iv_neg_orfet_cnt_swa = 0;
    uint8_t iv_neg_orfet_cnt_swc = 0;

    uint8_t iv_neg_orfet_cnt_swd = 0;
    uint8_t iv_reserved0         = 0;
    uint16_t iv_reserved1        = 0;
};

///
/// @brief Struct of periodic telemetry data collected once every 24 hours
/// Revision history:
///     0x51: Initial revision supporting periodic data collection logic from
///       "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
///       document provided by the Power team
///
struct __attribute__ ((__packed__)) periodic_telemetry_data
{
    // Revision of this struct formatting, to be updated
    // when the structure changes
    uint8_t iv_revision = 0x51;
    uint8_t reserved = 0;
    uint16_t reserved1 = 0;

    uint8_t iv_serial_number[26] = {0};
    uint8_t reserved2 = 0;
    uint8_t reserved3 = 0;

    adc_periodic_telemetry_data iv_adc;

    pmic_periodic_telemetry_data iv_pmic[CONSTS::NUM_PMICS_4U];

    dt_periodic_telemetry_data iv_dt[CONSTS::NUM_DTS_4U];
};

///
/// @brief Struct of consolidated health check data which includes the following:
///        1. Health check
///        2. Additional data collected in case of n-mode detected
///        3. Periodic telemetry data in case of n-mode detected
///
struct __attribute__ ((__packed__)) consolidated_health_check_data
{
    health_check_telemetry_data iv_health_check;
    additional_n_mode_telemetry_data iv_additional_data;
    periodic_telemetry_data iv_periodic_telemetry_data;

    uint8_t iv_pmic0_errors = 0;
    uint8_t iv_pmic1_errors = 0;
    uint8_t iv_pmic2_errors = 0;
    uint8_t iv_pmic3_errors = 0;

    uint8_t iv_dt0_errors = 0;
    uint8_t iv_dt1_errors = 0;
    uint8_t iv_dt2_errors = 0;
    uint8_t iv_dt3_errors = 0;
};

///
/// @brief Struct of 2U pmic data for periodic telemetry data collected once every 24 hours
///
struct __attribute__ ((__packed__)) pmic_periodic_2u_telemetry_data
{
    // Error register
    // Direct read from 8 bit register
    uint8_t iv_r04 = 0;
    uint8_t iv_r05 = 0;
    uint8_t iv_r06 = 0;
    uint8_t iv_r07 = 0;

    // Status register
    // Direct read from 8 bit register
    uint8_t iv_r08 = 0;
    uint8_t iv_r09 = 0;
    uint8_t iv_r0a = 0;
    uint8_t iv_r0b = 0;

    // Values in mA
    uint16_t iv_swa_current_mA = 0;
    uint16_t iv_swb_current_mA = 0;
    uint16_t iv_swc_current_mA = 0;
    uint16_t iv_swd_current_mA = 0;

    uint16_t iv_r31_sample_vin     = 0;
    uint16_t iv_r31_sample_temp    = 0;
};

///
/// @brief Struct of 2U periodic telemetry data collected once every 24 hours
/// Revision history:
///     0x21: Initial revision supporting periodic data collection logic from
///       "Non-Redundant PoD5 - Functional Specification dated 20230818 version 0.03"
///       document provided by the Power team
///
struct __attribute__ ((__packed__)) periodic_2U_telemetry_data
{
    // Revision of this struct formatting, to be updated
    // when the structure changes
    uint8_t iv_revision = 0x21;
    uint8_t reserved = 0;
    uint16_t reserved1 = 0;

    uint8_t iv_serial_number[26] = {0};
    uint8_t reserved2 = 0;
    uint8_t reserved3 = 0;

    pmic_periodic_2u_telemetry_data iv_pmic[CONSTS::NUM_PMICS_2U];
};

///
/// @brief Get the pmics and dt objects
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @return std::vector<pmic_dt_info>
///
fapi2::ReturnCode set_pmic_dt_states(target_info_redundancy_ddr5& io_target_info);

///
/// @brief Check if we are 4U by checking for at least 3 DT targets
///
/// @param[in] i_ocmb_target OCMB target
/// @return true if 4U, false if not
///
bool is_4u(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target);

///
/// @brief Helper function to check initial asserts of
///        1. Did we received any PMIC/DT pairs from target
///        2. Is the DIMM 4U
///        3. Did we receive correct number of PMIC/DT pairs from target
///
/// @param[in] i_ocmb_target OCMB target
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @param[in,out] io_state aggregate state
/// @return true if 4U, false if not
///
fapi2::ReturnCode health_check_tele_tool_assert_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        mss::pmic::ddr5::target_info_redundancy_ddr5& io_target_info,
        mss::pmic::ddr5::aggregate_state& io_state);

///
/// @brief Write a register of a PMIC target
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
///
void pmic_reg_write(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg, const fapi2::buffer<uint8_t>& i_data);

///
/// @brief Write a register of a DT target
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
///
void dt_reg_write(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg, const fapi2::buffer<uint8_t>& i_data);

///
/// @brief Read a register of a PMIC target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[out] o_data input buffer
///
void pmic_reg_read(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg, fapi2::buffer<uint8_t>& o_data);

///
/// @brief Read a register of a DT target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[out] o_data input buffer
///
void dt_reg_read(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg, fapi2::buffer<uint8_t>& o_data);

///
/// @brief Reverse write a register of a PMIC target
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
/// @return None
///
void pmic_reg_write_reverse_buffer(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                                   const fapi2::buffer<uint8_t>& i_data);

///
/// @brief Reverse write a register of a DT target
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
/// @return None
///
void dt_reg_write_reverse_buffer(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                                 const fapi2::buffer<uint8_t>& i_data);

///
/// @brief Reverse read a register of a PMIC target
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_data output buffer
/// @return None
///
void pmic_reg_read_reverse_buffer(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                                  fapi2::buffer<uint8_t>& o_data);

///
/// @brief Reverse read contiguous registers of a DT target
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_output output buffer
/// @return None
///
void dt_reg_read_reverse_buffer(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                                fapi2::buffer<uint8_t>& o_data);

///
/// @brief Read contiguous registers of a PMIC target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @tparam N size of the data buffer
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_output output buffer
///
template <size_t N>
void pmic_reg_read_contiguous(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                              fapi2::buffer<uint8_t> (&o_output)[N])
{
    if (!(io_pmic_dt.iv_pmic_state & mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_read_contiguous(io_pmic_dt.iv_pmic, i_reg, o_output) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic_dt.iv_pmic_state |= mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL;
        }
    }
}

///
/// @brief Read contiguous registers of a DT target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @tparam N size of the data buffer
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_output output buffer
///
template <size_t N>
void dt_reg_read_contiguous(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                            fapi2::buffer<uint8_t> (&o_output)[N])
{
    if (!(io_pmic_dt.iv_dt_state & mss::pmic::ddr5::dt_state::DT_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_read_contiguous(io_pmic_dt.iv_dt, i_reg, o_output) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic_dt.iv_dt_state |= mss::pmic::ddr5::dt_state::DT_I2C_FAIL;
        }
    }
}

///
/// @brief Read contiguous registers of a PMIC target and then reverse the buffer.
///        This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @tparam N size of the data buffer
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_output output buffer
///
template <size_t N>
void pmic_reg_read_contiguous_reverse(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                                      fapi2::buffer<uint8_t> (&o_output)[N])
{
    if (!(io_pmic_dt.iv_pmic_state & mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_read_contiguous_reverse(io_pmic_dt.iv_pmic, i_reg, o_output) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic_dt.iv_pmic_state |= mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL;
        }
    }
}

///
/// @brief Read contiguous registers of a DT target and then reverse the buffer.
///        This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @tparam N size of the data buffer
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_output output buffer
///
template <size_t N>
void dt_reg_read_contiguous_reverse(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                                    fapi2::buffer<uint8_t> (&o_output)[N])
{
    if (!(io_pmic_dt.iv_dt_state & mss::pmic::ddr5::dt_state::DT_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_read_contiguous_reverse(io_pmic_dt.iv_dt, i_reg, o_output) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic_dt.iv_dt_state |= mss::pmic::ddr5::dt_state::DT_I2C_FAIL;
        }
    }
}

///
/// @brief Write contiguous registers to a PMIC target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @tparam N size of the data buffer
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[in] i_data_buffer buffer of data to be writen to register addresses
/// @return None
///
template <size_t N>
void pmic_reg_write_contiguous(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                               fapi2::buffer<uint8_t> (&i_data_buffer)[N])
{
    if (!(io_pmic_dt.iv_pmic_state & mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_write_contiguous(io_pmic_dt.iv_pmic, i_reg, i_data_buffer) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic_dt.iv_pmic_state |= mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL;
        }
    }
}

///
/// @brief Write contiguous registers to a DT target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @tparam N size of the data buffer
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[in] i_data_buffer buffer of data to be writen to register addresses
/// @return None
///
template <size_t N>
void dt_reg_write_contiguous(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                             fapi2::buffer<uint8_t> (&i_data_buffer)[N])
{
    if (!(io_pmic_dt.iv_dt_state & mss::pmic::ddr5::dt_state::DT_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_write_contiguous(io_pmic_dt.iv_dt, i_reg, i_data_buffer) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic_dt.iv_dt_state |= mss::pmic::ddr5::dt_state::DT_I2C_FAIL;
        }
    }
}

///
/// @brief Get the nominal rail voltage of a JEDEC-compliant PMIC via attribute
///
/// @param[in] i_target_info target info struct
/// @param[in] i_pmic_id PMIC being adressed in sorted array
/// @param[in] i_rail rail to read from
/// @param[out] o_nominal_voltage voltage calculated
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode get_nominal_voltage_ddr5(const target_info_redundancy_ddr5& i_target_info,
        const uint8_t i_pmic_id,
        const mss::pmic::rail i_rail,
        uint32_t& o_nominal_voltage);

//
/// @brief Calculates update over voltage threshold setting using formula from spec
/// @param[in] i_voltage given voltage the pmic is being set to
/// @return bitmap of voltage threshold to set DT's Over voltage protect regs
//
uint8_t calculate_ov_threshold_voltage(const uint32_t i_voltage);

///
/// @brief Updates OV threshold voltages in respective dt's per voltage domain
/// @param i_ocmb_target OCMB Target
/// @param i_volt_domain Voltage domain to ensure we're setting the proper rails
/// @param i_voltage Voltage being set to PMIC
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode update_ov_threshold(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                                      const uint8_t i_volt_domain,
                                      const uint32_t i_voltage);
} // ddr5
} // pmic
} // mss

#endif
