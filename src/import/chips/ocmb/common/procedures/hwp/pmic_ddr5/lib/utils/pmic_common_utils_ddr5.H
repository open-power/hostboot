/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_common_utils_ddr5.H $ */
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
#include <pmic_consts.H>
#include <pmic_common_utils.H>
#include <mss_pmic_attribute_getters.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{
namespace pmic
{
namespace ddr5
{
using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

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

    // PMIC target provided here. Other arguments to be provided via capture list
    if (!l_disabled)
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

    // DT target provided here. Other arguments to be provided via capture list
    if (!l_disabled)
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

// Extra constants
static constexpr uint16_t CURRENT_MULTIPLIER = 125;
static constexpr uint16_t PHASE_MIN = 250;
static constexpr uint16_t PHASE_MAX = 1500;

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
/// @brief Struct of DT health check telemetry to populate
///
struct __attribute__((__packed__)) dt_health_check_telemetry
{
    uint8_t  iv_breadcrumb   = 0;
    uint8_t  reserved0 = 0;

    uint16_t iv_ro_inputs_1 = 0;
    uint16_t iv_ro_inputs_0 = 0;

    uint16_t reserved1 = 0;
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
/// @brief Write a register of a PMIC target
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
///
void pmic_reg_write(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg, const fapi2::buffer<uint8_t>& i_data);

///
/// @brief Write a register of a DT target
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
///
void dt_reg_write(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg, const fapi2::buffer<uint8_t>& i_data);

///
/// @brief Reverse write a register of a PMIC target
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
/// @return None
///
void pmic_reg_write_reverse_buffer(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg,
                                   const fapi2::buffer<uint8_t>& i_data);

///
/// @brief Reverse write a register of a DT target
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
/// @return None
///
void dt_reg_write_reverse_buffer(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg,
                                 const fapi2::buffer<uint8_t>& i_data);

///
/// @brief Reverse read a register of a PMIC target
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_data output buffer
/// @return None
///
void pmic_reg_read_reverse_buffer(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg,
                                  fapi2::buffer<uint8_t>& o_data);

///
/// @brief Reverse read contiguous registers of a DT target
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_output output buffer
/// @return None
///
void dt_reg_read_reverse_buffer(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg, fapi2::buffer<uint8_t>& o_data);

///
/// @brief Read contiguous registers of a PMIC target
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_output output buffer
///
template <size_t N>
void pmic_reg_read_contiguous(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg,
                              fapi2::buffer<uint8_t> (&o_output)[N]);

///
/// @brief Read contiguous registers of a DT target
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_output output buffer
///
template <size_t N>
void dt_reg_read_contiguous(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg,
                            fapi2::buffer<uint8_t> (&o_output)[N]);

///
/// @brief Write contiguous registers to a PMIC target
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[in] i_data_buffer buffer of data to be writen to register addresses
/// @return None
///
template <size_t N>
void pmic_reg_write_contiguous(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg,
                               fapi2::buffer<uint8_t> (&i_data_buffer)[N]);

///
/// @brief Write contiguous registers to a DT target
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[in] i_data_buffer buffer of data to be writen to register addresses
/// @return None
///
template <size_t N>
void dt_reg_write_contiguous(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg,
                             fapi2::buffer<uint8_t> (&i_data_buffer)[N]);

} // ddr5
} // pmic
} // mss

#endif
