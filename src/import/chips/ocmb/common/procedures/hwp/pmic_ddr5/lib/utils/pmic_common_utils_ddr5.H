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
// *HWP Level: 3
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
#include <pmic_common_types_ddr5.H>
#ifndef __PPE__
    #include <mss_pmic_attribute_getters.H>
#endif
#include <mss_pmic_attribute_accessors_manual.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{
namespace pmic
{
namespace ddr5
{

#ifndef __PPE__
///
/// @brief periodic_2U_telemetry_data struct meta data
/// @note The first element of the pair holds number of struct members which has same data type
///       The second element of the pair is number which denotes number of bytes that struct member can hold. Mapping is mentioned below.
///       uint8_t => 1, uint16_t => 2, uint32_t => 4, uint64_t => 8,
///
const std::vector<std::pair<uint16_t, uint8_t>> periodic_2U_telemetry_data_struct_meta_data =
{
    // uint8_t iv_revision
    // uint8_t iv_aggregate_pmic_state
    { 2, 1},
    // uint16_t reserved
    { 1, 2},
    // uint8_t iv_serial_number[26]
    // uint8_t iv_pmic_i2c_state
    // uint8_t reserved0
    { 28, 1},
    // uint16_t iv_dqs_tracking_recal_count
    // uint16_t reserved1
    { 2, 2},
    // uint64_t iv_dqs_tracking_log[24]
    // uint64_t iv_dts_data[5]
    { 29, 8},
    //pmic_periodic_2u_telemetry_data iv_pmic[CONSTS::NUM_PMICS_2U]
    // uint8_t iv_pmic0_iv_r04
    // uint8_t iv_pmic0_iv_r05
    // uint8_t iv_pmic0_iv_r06
    // uint8_t iv_pmic0_iv_r07
    // uint8_t iv_pmic0_iv_r08
    // uint8_t iv_pmic0_iv_r09
    // uint8_t iv_pmic0_iv_r0a
    // uint8_t iv_pmic0_iv_r0b
    // uint16_t iv_pmic0_iv_swa_current_mA
    // uint16_t iv_pmic0_iv_swb_current_mA
    // uint16_t iv_pmic0_iv_swc_current_mA
    // uint16_t iv_pmic0_iv_swd_current_mA
    // uint16_t iv_pmic0_iv_r31_sample_vin
    // uint16_t iv_pmic0_iv_r31_sample_temp
    // uint8_t iv_pmic0_iv_r73_status_5
    // uint8_t iv_pmic0_reserved
    // {uint16_t iv_pmic0_reserved1
    { 8, 1}, { 6, 2}, { 2, 1}, { 1, 2}, //PMIC0
    { 8, 1}, { 6, 2}, { 2, 1}, { 1, 2}, //PMIC1
};

///
/// @brief periodic_telemetry_data struct meta data
/// @note The first element of the pair holds number of struct members which has same data type
///       The second element of the pair is number which denotes number of bytes that struct member can hold. Mapping is mentioned below.
///       uint8_t => 1, uint16_t => 2, uint32_t => 4, uint64_t => 8,
///
const std::vector<std::pair<uint16_t, uint8_t>> periodic_telemetry_data_struct_meta_data =
{
    // uint8_t iv_revision
    // uint8_t iv_aggregate_pmic_state
    { 2, 1},
    // uint16_t reserved
    { 1, 2},
    // uint8_t iv_serial_number[26]
    // uint8_t iv_pmic_dt_i2c_state
    // uint8_t iv_adc_i2c_state
    { 28, 1},
    // uint16_t iv_dqs_tracking_recal_count
    // uint16_t reserved1
    { 2, 2},
    // uint64_t iv_dqs_tracking_log[24]
    // uint64_t iv_dts_data[5]
    { 29, 8},
    //adc_periodic_telemetry_data iv_adc
    // uint16_t iv_max_ch0_mV
    // uint16_t iv_max_ch1_mV
    // uint16_t iv_max_ch2_mV
    // uint16_t iv_max_ch3_mV
    // uint16_t iv_max_ch4_mV
    // uint16_t iv_max_ch5_mV
    // uint16_t iv_max_ch6_mV
    // uint16_t iv_max_ch7_mV
    // uint16_t iv_min_ch0_mV
    // uint16_t iv_min_ch1_mV
    // uint16_t iv_min_ch2_mV
    // uint16_t iv_min_ch3_mV
    // uint16_t iv_min_ch4_mV
    // uint16_t iv_min_ch5_mV
    // uint16_t iv_min_ch6_mV
    // uint16_t iv_min_ch7_mV
    // uint16_t iv_recent_ch0_mV
    // uint16_t iv_recent_ch1_mV
    // uint16_t iv_recent_ch2_mV
    // uint16_t iv_recent_ch3_mV
    // uint16_t iv_recent_ch4_mV
    // uint16_t iv_recent_ch5_mV
    // uint16_t iv_recent_ch6_mV
    // uint16_t iv_recent_ch7_mV
    { 24, 2},
    //pmic_periodic_telemetry_data iv_pmic[CONSTS::NUM_PMICS_4U]
    // uint8_t iv_r08
    // uint8_t iv_r09
    // uint8_t iv_r0a
    // uint8_t iv_r0b
    // uint16_t iv_swa_current_mA
    // uint16_t iv_swb_current_mA
    // uint16_t iv_swc_current_mA
    // uint16_t iv_swd_current_mA
    // uint16_t iv_r31_sample_vin
    // uint16_t iv_r31_sample_temp
    // uint8_t iv_r73_status_5
    // uint8_t iv_r7c_set_swa_offset
    // uint8_t iv_r7d_set_swb_offset
    // uint8_t iv_r7e_set_swc_offset
    // uint8_t iv_r7f_set_swd_offset
    // uint8_t reserved
    // uint16_t reserved1
    { 4, 1}, { 6, 2}, { 6, 1}, { 1, 2}, //PMIC0
    { 4, 1}, { 6, 2}, { 6, 1}, { 1, 2}, //PMIC1
    { 4, 1}, { 6, 2}, { 6, 1}, { 1, 2}, //PMIC2
    { 4, 1}, { 6, 2}, { 6, 1}, { 1, 2}, //PMIC3
    //dt_periodic_telemetry_data iv_dt[CONSTS::NUM_DTS_4U]
    // uint16_t iv_r9a_iin
    // uint16_t iv_r9b_vcc
    // uint16_t iv_r9c_vinp
    // uint16_t iv_r9d_vin
    // uint16_t iv_r9e_vaux_b
    // uint16_t iv_r9f_vaux_a
    // uint16_t iv_ra0_vaux_d
    // uint16_t iv_ra1_vaux_c
    // uint16_t iv_ra2_vinp_min
    // uint16_t iv_ra3_vinp_max
    // uint16_t iv_ra4_iin_min
    // uint16_t iv_ra5_iin_max
    // uint8_t iv_breadcrumb
    // uint8_t iv_recovery_count
    // uint8_t iv_neg_orfet_cnt_swa
    // uint8_t iv_neg_orfet_cnt_swc
    // uint8_t iv_neg_orfet_cnt_swd
    // uint8_t iv_reserved0
    // uint16_t iv_reserved1
    { 12, 2}, { 6, 1}, { 1, 2}, //PMIC0
    { 12, 2}, { 6, 1}, { 1, 2}, //PMIC1
    { 12, 2}, { 6, 1}, { 1, 2}, //PMIC2
    { 12, 2}, { 6, 1}, { 1, 2}, //PMIC3
};

///
/// @brief consolidated_health_check_data struct meta data
/// @note The first element of the pair holds number of struct members which has same data type
///       The second element of the pair is number which denotes number of bytes that struct member can hold. Mapping is mentioned below.
///       uint8_t => 1, uint16_t => 2, uint32_t => 4, uint64_t => 8,
///
const std::vector<std::pair<uint16_t, uint8_t>> consolidated_health_check_data_struct_meta_data =
{
    //health_check_telemetry_data iv_health_check
    // uinit8_t => aggregate_state iv_aggregate_state = aggregate_state::N_PLUS_1
    // uint8_t iv_revision
    { 2, 1},
    // uint16_t reserved
    { 1, 2},
    // dt_health_check_telemetry iv_dt[CONSTS::NUM_DTS_4U]
    // uint8_t  iv_breadcrumb
    // uint8_t  reserved0
    // uint16_t iv_ro_inputs_1
    // uint16_t iv_ro_inputs_0
    // uint16_t reserved1
    { 2, 1}, { 3, 2},  //PMIC0
    { 2, 1}, { 3, 2},  //PMIC1
    { 2, 1}, { 3, 2},  //PMIC2
    { 2, 1}, { 3, 2},  //PMIC3
    // pmic_health_check_telemetry iv_pmic[CONSTS::NUM_PMICS_4U]
    // uint8_t iv_r04
    // uint8_t iv_r05
    // uint8_t iv_r06
    // uint8_t iv_r07
    // uint8_t iv_r08
    // uint8_t iv_r09
    // uint8_t iv_r0a
    // uint8_t iv_r0b
    // uint16_t iv_swa_current_mA
    // uint16_t iv_swb_current_mA
    // uint16_t iv_swc_current_mA
    // uint16_t iv_swd_current_mA
    // uint8_t iv_r73_status_5
    // uint8_t reserved
    // uint16_t reserved1
    { 8, 1}, { 4, 2}, { 2, 1}, { 1, 2}, //PMIC0
    { 8, 1}, { 4, 2}, { 2, 1}, { 1, 2}, //PMIC1
    { 8, 1}, { 4, 2}, { 2, 1}, { 1, 2}, //PMIC2
    { 8, 1}, { 4, 2}, { 2, 1}, { 1, 2}, //PMIC3
    //additional_n_mode_telemetry_data iv_additional_data
    // adc_additional_n_mode_telemetry_data iv_adc
    // uint8_t iv_system_status
    // uint8_t iv_general_cfg
    // uint8_t iv_data_cfg
    // uint8_t iv_osr_cfg
    // uint8_t iv_opmode_cfg
    // uint8_t iv_pin_cfg
    // uint8_t iv_dummy_0
    // uint8_t iv_gpio_cfg
    // uint8_t iv_dummy_1
    // uint8_t iv_gpo_drive_cfg
    // uint8_t iv_dummy_2
    // uint8_t iv_gpo_value_cfg
    // uint8_t iv_dummy_3
    // uint8_t iv_gpi_value
    // uint8_t iv_dummy_4
    // uint8_t iv_dummy_5
    { 16, 1},
    // pmic_additional_n_mode_telemetry_data iv_pmic[CONSTS::NUM_PMICS_4U];
    // uint8_t iv_r2f_pmic_config
    // uint8_t iv_r32_pmic_enable
    // uint8_t iv_r33_temp_status
    // uint8_t iv_r9c_on_off_config
    { 4, 1}, //PMIC0
    { 4, 1}, //PMIC1
    { 4, 1}, //PMIC2
    { 4, 1}, //PMIC3
    // dt_additional_n_mode_telemetry_data iv_dt[CONSTS::NUM_DTS_4U];
    // uint16_t iv_r90_ops_state
    // uint16_t iv_r96_first_faults_status_0
    // uint16_t iv_r98_first_faults_status_1
    // uint16_t iv_r92_faults_status_0
    // uint16_t iv_r94_faults_status_1
    // uint16_t iv_ra6_infet_mpt_addr
    // uint16_t iv_ra8_nvm_data
    // uint16_t iv_rb4_vcc_vin_vinp
    { 8, 2}, //PMIC0
    { 8, 2}, //PMIC1
    { 8, 2}, //PMIC2
    { 8, 2}, //PMIC3
    //periodic_telemetry_data iv_periodic_telemetry_data;
    // uint8_t iv_revision
    // uint8_t iv_aggregate_pmic_state
    { 2, 1},
    // uint16_t reserved
    { 1, 2},
    // uint8_t iv_serial_number[26]
    // uint8_t iv_pmic_dt_i2c_state
    // uint8_t iv_adc_i2c_state
    { 28, 1},
    // uint16_t iv_dqs_tracking_recal_count
    // uint16_t reserved1
    { 2, 2},
    // uint64_t iv_dqs_tracking_log[24]
    // uint64_t iv_dts_data[5]
    { 29, 8},
    // adc_periodic_telemetry_data iv_adc
    // uint16_t iv_max_ch0_mV
    // uint16_t iv_max_ch1_mV
    // uint16_t iv_max_ch2_mV
    // uint16_t iv_max_ch3_mV
    // uint16_t iv_max_ch4_mV
    // uint16_t iv_max_ch5_mV
    // uint16_t iv_max_ch6_mV
    // uint16_t iv_max_ch7_mV
    // uint16_t iv_min_ch0_mV
    // uint16_t iv_min_ch1_mV
    // uint16_t iv_min_ch2_mV
    // uint16_t iv_min_ch3_mV
    // uint16_t iv_min_ch4_mV
    // uint16_t iv_min_ch5_mV
    // uint16_t iv_min_ch6_mV
    // uint16_t iv_min_ch7_mV
    // uint16_t iv_recent_ch0_mV
    // uint16_t iv_recent_ch1_mV
    // uint16_t iv_recent_ch2_mV
    // uint16_t iv_recent_ch3_mV
    // uint16_t iv_recent_ch4_mV
    // uint16_t iv_recent_ch5_mV
    // uint16_t iv_recent_ch6_mV
    // uint16_t iv_recent_ch7_mV
    { 24, 2},
    // pmic_periodic_telemetry_data iv_pmic[CONSTS::NUM_PMICS_4U]
    // uint8_t iv_r08
    // uint8_t iv_r09
    // uint8_t iv_r0a
    // uint8_t iv_r0b
    // uint16_t iv_swa_current_mA
    // uint16_t iv_swb_current_mA
    // uint16_t iv_swc_current_mA
    // uint16_t iv_swd_current_mA
    // uint16_t iv_r31_sample_vin
    // uint16_t iv_r31_sample_temp
    // uint8_t iv_r73_status_5
    // uint8_t iv_r7c_set_swa_offset
    // uint8_t iv_r7d_set_swb_offset
    // uint8_t iv_r7e_set_swc_offset
    // uint8_t iv_r7f_set_swd_offset
    // uint8_t reserved
    // uint16_t reserved1
    { 4, 1}, { 6, 2}, { 6, 1}, { 1, 2}, //PMIC0
    { 4, 1}, { 6, 2}, { 6, 1}, { 1, 2}, //PMIC1
    { 4, 1}, { 6, 2}, { 6, 1}, { 1, 2}, //PMIC2
    { 4, 1}, { 6, 2}, { 6, 1}, { 1, 2}, //PMIC3
    // dt_periodic_telemetry_data iv_dt[CONSTS::NUM_DTS_4U]
    // uint16_t iv_r9a_iin
    // uint16_t iv_r9b_vcc
    // uint16_t iv_r9c_vinp
    // uint16_t iv_r9d_vin
    // uint16_t iv_r9e_vaux_b
    // uint16_t iv_r9f_vaux_a
    // uint16_t iv_ra0_vaux_d
    // uint16_t iv_ra1_vaux_c
    // uint16_t iv_ra2_vinp_min
    // uint16_t iv_ra3_vinp_max
    // uint16_t iv_ra4_iin_min
    // uint16_t iv_ra5_iin_max
    // uint8_t iv_breadcrumb
    // uint8_t iv_recovery_count
    // uint8_t iv_neg_orfet_cnt_swa
    // uint8_t iv_neg_orfet_cnt_swc
    // uint8_t iv_neg_orfet_cnt_swd
    // uint8_t iv_reserved0
    // uint16_t iv_reserved1
    { 12, 2}, { 6, 1}, { 1, 2}, //PMIC0
    { 12, 2}, { 6, 1}, { 1, 2}, //PMIC1
    { 12, 2}, { 6, 1}, { 1, 2}, //PMIC2
    { 12, 2}, { 6, 1}, { 1, 2}, //PMIC3
    // uint8_t iv_pmic0_errors
    // uint8_t iv_pmic1_errors
    // uint8_t iv_pmic2_errors
    // uint8_t iv_pmic3_errors
    // uint8_t iv_dt0_errors
    // uint8_t iv_dt1_errors
    // uint8_t iv_dt2_errors
    // uint8_t iv_dt3_errors
    // uint8_t iv_adc_errors
    // uint8_t reserved
    { 10, 1},
    // uint16_t reserved1
    { 1, 2},
};
#endif

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

    // The below 'adc state' member will be used to keep track of the adc state
    // This adc state will not be populated or used by pmic_enable but will be used by
    // health check and periodic telemetry tools
    uint8_t iv_adc_state = 0;

    // Set the corresponding bits if the targets are present
    // These have been numbered from right to left (reverse of FAPI style)
    // Bit 0 - PMIC0
    // Bit 1 - PMIC1
    // Bit 2 - PMIC2
    // Bit 3 - PMIC3
    // Bit 4 - DT1
    // Bit 5 - DT2
    // Bit 6 - DT3
    // Bit 7 - DT4
    fapi2::buffer<uint8_t> iv_pmic_dt_present;

    // Set the corresponding bit if the targets are present
    // BIT 0 - ADC
    fapi2::buffer<uint8_t> iv_adc_present;

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
