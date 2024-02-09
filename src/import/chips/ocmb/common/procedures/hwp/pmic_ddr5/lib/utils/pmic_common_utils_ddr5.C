/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_common_utils_ddr5.C $ */
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
/// @file pmic_common_utils.C
/// @brief Utility functions common for several PMIC DDR5 procedures
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <i2c_pmic.H>
#include <pmic_consts.H>
#include <pmic_common_utils_ddr5.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_math.H>
#include <mss_pmic_attribute_accessors_manual.H>

namespace mss
{
namespace pmic
{
namespace ddr5
{

///
/// @brief Construct a new target_info_redundancy_ddr5 object with the passed in targets
/// @param[in] i_pmics Vector of PMIC targets
/// @param[in] i_dts Vector of DT targets
/// @param[in] i_adc ADC target
/// @param[out] o_rc ReturnCode in case of construction error
/// @note pmic_enable_ddr5.C plug rules ensures that a valid number of I2C, DT and PMIC children targets exist
///
target_info_redundancy_ddr5::target_info_redundancy_ddr5(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PMIC>>&
        i_pmics,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>>& i_dts,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>>& i_adc,
        fapi2::ReturnCode& o_rc)
{
    o_rc = fapi2::FAPI2_RC_SUCCESS;

    iv_number_of_target_infos_present = 0;
    const uint8_t NUM_GENERIC_I2C_DEV = i_adc.size();
    constexpr auto NUM_PRIMARY_PMICS = CONSTS::NUM_PRIMARY_PMICS_DDR5;

    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmics[0]);

    for (const auto& l_pmic : i_pmics)
    {
        uint8_t l_relative_pmic_id = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_REL_POS, l_pmic, l_relative_pmic_id));

        for (const auto& l_dt : i_dts)
        {
            uint8_t l_relative_dt_id = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_REL_POS, l_dt, l_relative_dt_id));

            if(l_relative_pmic_id == l_relative_dt_id)
            {
                iv_pmic_dt_map[iv_number_of_target_infos_present].iv_pmic = l_pmic;
                iv_pmic_dt_map[iv_number_of_target_infos_present].iv_dt = l_dt;
                FAPI_DBG("Found present PMIC: " GENTARGTIDFORMAT, GENTARGTID(l_pmic));
                FAPI_DBG("Found present DT: " GENTARGTIDFORMAT, GENTARGTID(l_dt));
                iv_pmic_dt_map[iv_number_of_target_infos_present].iv_rel_pos = l_relative_pmic_id;
                iv_number_of_target_infos_present++;
                break;
            }
        }
    }

    // If we are given a guaranteed failing list of targets (< 3 PMICs) exit now
    FAPI_ASSERT((iv_number_of_target_infos_present >= NUM_PRIMARY_PMICS) ,
                fapi2::INVALID_PMIC_DT_DDR5_TARGET_CONFIG()
                .set_OCMB_TARGET(l_ocmb)
                .set_NUM_PMICS(iv_number_of_target_infos_present)
                .set_EXPECTED_MIN_PMICS(NUM_PRIMARY_PMICS),
                GENTARGTIDFORMAT " pmic_enable requires at least %u PMICs and DTs. "
                "Given %u PMICs and DTs",
                GENTARGTID(l_ocmb),
                NUM_PRIMARY_PMICS,
                iv_number_of_target_infos_present);

    // If we are given < 1 ADC, exit now
    FAPI_ASSERT((NUM_GENERIC_I2C_DEV == mss::generic_i2c_responder::NUM_TOTAL_DEVICES_I2C_DDR5),
                fapi2::INVALID_GI2C_DDR5_TARGET_CONFIG()
                .set_OCMB_TARGET(l_ocmb)
                .set_NUM_GI2CS(NUM_GENERIC_I2C_DEV)
                .set_EXPECTED_GI2CS(mss::generic_i2c_responder::NUM_TOTAL_DEVICES_I2C_DDR5),
                GENTARGTIDFORMAT " pmic_enable requires exactly %u GI2C responder. "
                "Given %u GI2C",
                GENTARGTID(l_ocmb),
                mss::generic_i2c_responder::NUM_TOTAL_DEVICES_I2C_DDR5,
                NUM_GENERIC_I2C_DEV);

    iv_adc = i_adc[mss::generic_i2c_responder::ADC];

    iv_ocmb = l_ocmb;

    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
}

///
/// @brief Construct a new target_info_redundancy object
///
/// @param[in] i_ocmb OCMB target
/// @param[out] o_rc ReturnCode in case of construction error
/// @note pmic_enable.C plug rules ensures that a valid number of I2C and PMIC children targets exist
///
target_info_redundancy_ddr5::target_info_redundancy_ddr5(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
        fapi2::ReturnCode& o_rc) :
    target_info_redundancy_ddr5::target_info_redundancy_ddr5(
        mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_PMIC>(i_ocmb, fapi2::TARGET_STATE_PRESENT),
        mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_POWER_IC>(i_ocmb, fapi2::TARGET_STATE_PRESENT),
        mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>(i_ocmb),
        o_rc)
{}

///
/// @brief Helper function to get the minimum vin bulk threshold
///
/// @param[in] i_vin_bulk_min_threshold
/// @return VIN bulk minimum value
///
uint16_t get_minimum_vin_bulk_threshold_helper(
    const uint8_t i_vin_bulk_min_threshold)
{
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    uint16_t l_mapped_vin_bulk = 0;

    switch (i_vin_bulk_min_threshold & FIELDS::R1A_VIN_BULK_POWER_GOOD_THRESHOLD_VOLTAGE_MASK)
    {
        case CONSTS::VIN_BULK_9_5V:
            l_mapped_vin_bulk = 9500;

        case CONSTS::VIN_BULK_8_5V:
            l_mapped_vin_bulk = 8500;

        case CONSTS::VIN_BULK_7_5V:
            l_mapped_vin_bulk = 7500;

        case CONSTS::VIN_BULK_6_5V:
            l_mapped_vin_bulk = 6500;

        case CONSTS::VIN_BULK_5_5V:
            l_mapped_vin_bulk = 5500;

        case CONSTS::VIN_BULK_4_25V:
            l_mapped_vin_bulk = 4250;
    }

    return l_mapped_vin_bulk;
}

///
/// @brief Get the minimum vin bulk threshold
///
/// @param[in] i_pmic_target PMIC target
/// @param[out] o_vin_bulk_min VIN bulk minimum value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode get_minimum_vin_bulk_threshold(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    uint16_t& o_vin_bulk_min)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;

    fapi2::buffer<uint8_t> l_vin_bulk_min_threshold;

    // Use R1A value
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R1A, l_vin_bulk_min_threshold));

    o_vin_bulk_min = mss::pmic::ddr5::get_minimum_vin_bulk_threshold_helper(
                         l_vin_bulk_min_threshold);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get the pmics and dt objects
///
/// @param[in,out] io_target_info PMIC and DT target info struct
/// @return std::vector<pmic_dt_info>
///
fapi2::ReturnCode set_pmic_dt_states(target_info_redundancy_ddr5& io_target_info)
{
    for (auto l_count = 0; l_count < io_target_info.iv_number_of_target_infos_present; l_count++)
    {
        FAPI_TRY_NO_TRACE(mss::pmic::ddr5::run_if_present(io_target_info, l_count, [l_count, &io_target_info]
                          (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
        {
            io_target_info.iv_pmic_dt_map[l_count].iv_pmic_state = mss::pmic::ddr5::pmic_state::PMIC_ALL_GOOD;
            io_target_info.iv_pmic_dt_map[l_count].iv_dt_state = mss::pmic::ddr5::dt_state::DT_ALL_GOOD;
            return fapi2::FAPI2_RC_SUCCESS;
        }));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check if we are 4U by checking for at least 3 DT targets
///
/// @param[in] i_ocmb_target OCMB target
/// @return true if 4U, false if not
///
bool is_4u(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
{
    // Platform is expected to provide at least 3 DT targets
    // All 4U DDIMMs have minimum 3 DT targets, and all 2U DDIMMs have zero, so checking those is sufficient to say if we have a 4U
    const auto DTS = i_ocmb_target.getChildren<fapi2::TARGET_TYPE_POWER_IC>(fapi2::TARGET_STATE_PRESENT);

    return (DTS.size() >= mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>::NUM_PRIMARY_DT_DDR5);
}

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
        mss::pmic::ddr5::aggregate_state& io_state)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    // Check if we have recevied any PMIC/DT pairs. Else declare LOST
    if (!io_target_info.iv_number_of_target_infos_present)
    {
        io_state = mss::pmic::ddr5::aggregate_state::LOST;
        // If we are not given any PMIC/DT targets, exit now
        constexpr auto NUM_PRIMARY_PMICS = CONSTS::NUM_PRIMARY_PMICS_DDR5;
        FAPI_ASSERT(false,
                    fapi2::NO_PMIC_DT_DDR5_TARGETS_FOUND()
                    .set_OCMB_TARGET(i_ocmb_target)
                    .set_NUM_PMICS(io_target_info.iv_number_of_target_infos_present)
                    .set_EXPECTED_MIN_PMICS(NUM_PRIMARY_PMICS),
                    GENTARGTIDFORMAT " Pmic health check requires at least %u PMICs and DTs. "
                    "Given %u PMICs and DTs",
                    GENTARGTID(i_ocmb_target),
                    NUM_PRIMARY_PMICS,
                    io_target_info.iv_number_of_target_infos_present);
    }

    // Platform has asserted we will receive at least 3 DT targets iff 4U
    // Do a check to see if we are 4U by checking for minimum 3 DT targets
    if (!mss::pmic::ddr5::is_4u(i_ocmb_target))
    {
        io_state = mss::pmic::ddr5::aggregate_state::DIMM_NOT_4U;
        FAPI_ERR(GENTARGTIDFORMAT " DIMM is not 4U", GENTARGTID(i_ocmb_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    if(io_target_info.iv_number_of_target_infos_present <= CONSTS::NUM_PRIMARY_PMICS_DDR5)
    {
        io_state = mss::pmic::ddr5::aggregate_state::N_MODE;
        FAPI_ERR(GENTARGTIDFORMAT " Declaring N-mode due to not enough functional PMICs/DTs provided",
                 GENTARGTID(i_ocmb_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write a register of a PMIC target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
///
void pmic_reg_write(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg, const fapi2::buffer<uint8_t>& i_data)
{
    if (!(io_pmic_dt.iv_pmic_state & mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_write(io_pmic_dt.iv_pmic, i_reg, i_data) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic_dt.iv_pmic_state |= mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL;
        }
    }
}

///
/// @brief Write a register of a DT target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
///
void dt_reg_write(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg, const fapi2::buffer<uint8_t>& i_data)
{
    if (!(io_pmic_dt.iv_dt_state & mss::pmic::ddr5::dt_state::DT_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_write(io_pmic_dt.iv_dt, i_reg, i_data) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic_dt.iv_dt_state |= mss::pmic::ddr5::dt_state::DT_I2C_FAIL;
        }
    }
}

///
/// @brief Read a register of a PMIC target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[out] o_data input buffer
///
void pmic_reg_read(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg, fapi2::buffer<uint8_t>& o_data)
{
    if (!(io_pmic_dt.iv_pmic_state & mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_read(io_pmic_dt.iv_pmic, i_reg, o_data) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic_dt.iv_pmic_state |= mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL;
        }
    }
}

///
/// @brief Read a register of a DT target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[out] o_data input buffer
///
void dt_reg_read(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg, fapi2::buffer<uint8_t>& o_data)
{
    if (!(io_pmic_dt.iv_dt_state & mss::pmic::ddr5::dt_state::DT_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_read(io_pmic_dt.iv_dt, i_reg, o_data) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic_dt.iv_dt_state |= mss::pmic::ddr5::dt_state::DT_I2C_FAIL;
        }
    }
}

///
/// @brief Reverse write a register of a PMIC target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
/// @return None
///
void pmic_reg_write_reverse_buffer(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                                   const fapi2::buffer<uint8_t>& i_data)
{
    if (!(io_pmic_dt.iv_pmic_state & mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_write_reverse_buffer(io_pmic_dt.iv_pmic, i_reg, i_data) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic_dt.iv_pmic_state |= mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL;
        }
    }
}

///
/// @brief Reverse write a register of a DT target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
/// @return None
///
void dt_reg_write_reverse_buffer(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                                 const fapi2::buffer<uint8_t>& i_data)
{
    if (!(io_pmic_dt.iv_dt_state & mss::pmic::ddr5::dt_state::DT_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_write_reverse_buffer(io_pmic_dt.iv_dt, i_reg, i_data) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic_dt.iv_dt_state |= mss::pmic::ddr5::dt_state::DT_I2C_FAIL;
        }
    }
}

///
/// @brief Reverse read a register of a PMIC target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_data output buffer
/// @return None
///
void pmic_reg_read_reverse_buffer(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                                  fapi2::buffer<uint8_t>& o_data)
{
    if (!(io_pmic_dt.iv_pmic_state & mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_read_reverse_buffer(io_pmic_dt.iv_pmic, i_reg, o_data) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic_dt.iv_pmic_state |= mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL;
        }
    }
}

///
/// @brief Reverse read contiguous registers of a DT target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic_dt target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_data output buffer
/// @return None
///
void dt_reg_read_reverse_buffer(target_info_pmic_dt_pair& io_pmic_dt, const uint8_t i_reg,
                                fapi2::buffer<uint8_t>& o_data)
{
    if (!(io_pmic_dt.iv_dt_state & mss::pmic::ddr5::dt_state::DT_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_read_reverse_buffer(io_pmic_dt.iv_dt, i_reg, o_data) != fapi2::FAPI2_RC_SUCCESS)
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
        uint32_t& o_nominal_voltage)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    using TPS_FIELDS = pmicFields<mss::pmic::product::TPS5383X>;

    uint8_t l_voltage_setting = 0;
    uint8_t l_range_selection = 0;
    uint16_t l_range_min_value = 0;

    bool l_pmic_is_ti = false;
    fapi2::buffer<uint8_t> l_pmic_rev;

    const mss::pmic::id l_id = static_cast<mss::pmic::id>(i_pmic_id);
    uint16_t l_r78_range_min_value_mv = 0;
    uint16_t l_r2b_range_min_value_mv = 0;
    bool l_use_R78_for_range = false;
    fapi2::buffer<uint8_t> l_voltage_setting_reg_contents;
    fapi2::buffer<uint8_t> l_voltage_range_reg_contents;
    fapi2::buffer<uint8_t> l_pmic_vid_offset_coarse_reg;

    const auto& l_pmic_target = i_target_info.iv_pmic_dt_map[i_pmic_id].iv_pmic;

    FAPI_TRY(mss::pmic::pmic_is_ti(l_pmic_target, l_pmic_is_ti));

    // If TI PMIC get the revision and height
    if (l_pmic_is_ti)
    {
        FAPI_TRY(mss::pmic::i2c::reg_read(l_pmic_target, REGS::R3B_REVISION, l_pmic_rev));
        FAPI_ASSERT(l_pmic_rev >= TPS_CONSTS::TI_REV_23,
                    fapi2::PMIC_NOT_DDR5_REVISION().
                    set_PMIC_REVISION(l_pmic_rev).
                    set_PMIC_TARGET(l_pmic_target),
                    GENTARGTIDFORMAT " PMIC is not DDR5 revision %d exiting get_nominal_voltage_ddr5", GENTARGTID(l_pmic_target),
                    l_pmic_rev);
    }
    else
    {
        FAPI_INF_NO_SBE(GENTARGTIDFORMAT " PMIC is not from TI, exiting get_nominal_voltage_ddr5", GENTARGTID(l_pmic_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY(mss::pmic::calculate_voltage_bitmap_from_attr(l_pmic_target, l_id, i_rail, l_voltage_setting));

    // Unlock register R78 for reading for TPS53831 (TI revision >= 0x23)
    FAPI_TRY(mss::pmic::status::unlock_pmic_r70_to_ra3(l_pmic_target));
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmic_target, TPS_REGS::R78_VID_OFFSET_COARSE,
             l_pmic_vid_offset_coarse_reg));

    // Identify range for R78
    switch (i_rail)
    {
        case mss::pmic::rail::SWA:
            l_pmic_vid_offset_coarse_reg.extractToRight<TPS_FIELDS::R78_SWA_VID_OFFSET_COARSE_START,
                                                        TPS_FIELDS::R78_VID_OFFSET_COARSE_LENGTH>(l_range_selection);
            break;

        case mss::pmic::rail::SWB:
            l_pmic_vid_offset_coarse_reg.extractToRight<TPS_FIELDS::R78_SWB_VID_OFFSET_COARSE_START,
                                                        TPS_FIELDS::R78_VID_OFFSET_COARSE_LENGTH>(l_range_selection);
            break;

        case mss::pmic::rail::SWC:
            l_pmic_vid_offset_coarse_reg.extractToRight<TPS_FIELDS::R78_SWC_VID_OFFSET_COARSE_START,
                                                        TPS_FIELDS::R78_VID_OFFSET_COARSE_LENGTH>(l_range_selection);
            break;

        case mss::pmic::rail::SWD:
            l_pmic_vid_offset_coarse_reg.extractToRight<TPS_FIELDS::R78_SWD_VID_OFFSET_COARSE_START,
                                                        TPS_FIELDS::R78_VID_OFFSET_COARSE_LENGTH>(l_range_selection);
            break;

        default:
            FAPI_TRY(fapi2::FAPI2_RC_INVALID_PARAMETER, "get_nominal_voltage_ddr5 rail %u not found",
                     i_rail);
            break;
    }

    // Get range minimum voltage for rail using R78
    l_r78_range_min_value_mv = mss::pmic::VOLT_RANGE_VID_OFFSET_COARSE_MINS[i_rail][l_range_selection];

    // If range setting for rail is not at default value then use it for the range
    l_use_R78_for_range = (l_range_selection != mss::pmic::VOLT_VID_OFFSET_COARSE_DEFAULT[i_rail]);

    // If R78 is not used to define range then get range from R2B
    if (!l_use_R78_for_range)
    {
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmic_target, REGS::R2B, l_voltage_range_reg_contents),
                 "get_nominal_voltage_ddr5: Error reading 0x%02hhX of PMIC " GENTARGTIDFORMAT, REGS::R2B, GENTARGTID(l_pmic_target));

        // Identify range for R2B
        l_range_selection = l_voltage_range_reg_contents.getBit(mss::pmic::VOLT_RANGE_FLDS[i_rail]);

        // Get range minimum voltage for rail using R2B
        l_r2b_range_min_value_mv = mss::pmic::VOLT_RANGE_MINS[i_rail][l_range_selection];
    }

    // Get range minimum voltage that is being used by pmic
    l_range_min_value = (l_use_R78_for_range) ? l_r78_range_min_value_mv : l_r2b_range_min_value_mv;

    // While it's technically possible that we could just have a attribute value of 0 ( == 800mV),
    // we don't currently use this for any rail in any SPD, and it's unlikely that we would ever do so.
    // So, if both the voltage setting and range are 0, it's safe to assume the attributes are not set
    // and we should not continue.
    if(l_voltage_setting == 0 && l_range_selection == 0)
    {
        FAPI_ERR( "Nominal PMIC voltages are not defined for rail being biased. This could mean the rail is "
                  "disabled, or eff_config was not run, meaning biasing by percentage is not supported.");
    }


    // Get nominial voltage using: range_min + (step * setting)
    o_nominal_voltage = l_range_min_value + (CONSTS::VOLT_STEP * l_voltage_setting);

    FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Rail %u Nominal voltage: %lumV", GENTARGTID(l_pmic_target), i_rail,
                    o_nominal_voltage);

fapi_try_exit:
    return fapi2::current_err;
}

//
/// @brief Calculates update over voltage threshold setting using formula from spec
/// @param[in] i_voltage given voltage the pmic is being set to
/// @return bitmap of voltage threshold to set DT's Over voltage protect regs
//
uint8_t calculate_ov_threshold_voltage(const uint32_t i_voltage)
{
    static constexpr uint32_t THRESHOLD_MULT = 110;
    static constexpr uint32_t THRESHOLD_DIFF = 600;
    static constexpr uint32_t THRESHOLD_STEP = 25;

    // Calculate new threshold using equation in 10-1 in PMIC SPEC units in mV's
    uint32_t l_ov_mv = ((i_voltage * THRESHOLD_MULT) / 100);

    // Round to nearest step
    l_ov_mv = mss::round_to_nearest_multiple(l_ov_mv, THRESHOLD_STEP);
    return(uint8_t((l_ov_mv - THRESHOLD_DIFF) / THRESHOLD_STEP));
}

///
/// @brief Updates OV threshold voltages in respective dt's per voltage domain
/// @param i_ocmb_target OCMB Target
/// @param i_volt_domain Voltage domain to ensure we're setting the proper rails
/// @param i_voltage Voltage being set to PMIC
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode update_ov_threshold(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                                      const uint8_t i_volt_domain,
                                      const uint32_t i_voltage)
{
    using DT_REGS  = mss::dt::regs;
    using DT_FIELDS  = mss::dt::fields;
    using DT_POS  = mss::dt::dt_i2c_devices;

    static constexpr uint8_t NUM_BYTES_TO_WRITE = 2;
    auto l_threshold_voltage = calculate_ov_threshold_voltage(i_voltage);

    const auto& l_dts = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_POWER_IC>(i_ocmb_target);
    fapi2::buffer<uint8_t> l_dt_thresh_buffer[NUM_BYTES_TO_WRITE];

    // Check volt domain to see which dt's/rails need to be written to

    // Over Voltage threshold is programmed into 2 6-bit fields across a 16-bit contiguous reg (0x5A & 0x5B for Rails A & B, 0x5C & 0x5D for Rails C & D)
    // In order to properly inject the bits into these regs, we read the current setting into two 8-bit buffers
    // During the read out the date is byte reversed into the buffers
    // To program rails B & D we inject into the first 6-bits of the DT reg 0x5A/5C which are bits 2:7 of our fapi buffer[0]
    // To program rails A & C we inject into the last 4-bits of the DT reg 0x5A/5C which are bits 4:7 of our fapi buffer[1]
    //                                       and first 2-bits of the DT reg 0x5B/5D which are bits 0:1 of our fapi buffer[0]
    // More detailed explaination can be found in pmic_const.H - mss::dt::fields
    switch(i_volt_domain)
    {
        case mss::pmic::volt_domains::VDDQ:

            // All DTs on A & B rails
            for(const auto& l_dt : l_dts)
            {
                FAPI_TRY(mss::pmic::i2c::reg_read_contiguous(l_dt, DT_REGS::OV_THRESHOLD_AB, l_dt_thresh_buffer));

                // Insert data to first buffer for rail B/D
                l_dt_thresh_buffer[0].insertFromRight<DT_FIELDS::OV_THRESH_START_BD, DT_FIELDS::OV_THRESH_LENGTH_BD>
                (l_threshold_voltage);

                // Insert data to first & second buffer for rail A/C
                l_dt_thresh_buffer[1].insertFromRight<DT_FIELDS::OV_THRESH_START_AC_FIRST_BYTE, DT_FIELDS::THRESHOLD_AC_FIRST_BYTE_LEN>
                (l_threshold_voltage >> DT_FIELDS::THRESHOLD_AC_SECOND_BYTE_LEN);
                l_dt_thresh_buffer[0].insertFromRight<DT_FIELDS::OV_THRESH_START_AC_SECOND_BYTE, DT_FIELDS::THRESHOLD_AC_SECOND_BYTE_LEN>
                (l_threshold_voltage);
                FAPI_TRY(mss::pmic::i2c::reg_write_contiguous(l_dt, DT_REGS::OV_THRESHOLD_AB, l_dt_thresh_buffer));
            }

            break;

        case mss::pmic::volt_domains::VDD:

            // DT0, DT1, DT3 on rail C
            // DT0
            FAPI_TRY(mss::pmic::i2c::reg_read_contiguous(l_dts[DT_POS::DT0], DT_REGS::OV_THRESHOLD_CD, l_dt_thresh_buffer));

            // Insert data to first & second buffer for rail A/C

            l_dt_thresh_buffer[1].insertFromRight<DT_FIELDS::OV_THRESH_START_AC_FIRST_BYTE, DT_FIELDS::THRESHOLD_AC_FIRST_BYTE_LEN>
            (l_threshold_voltage >> DT_FIELDS::THRESHOLD_AC_SECOND_BYTE_LEN);
            l_dt_thresh_buffer[0].insertFromRight<DT_FIELDS::OV_THRESH_START_AC_SECOND_BYTE, DT_FIELDS::THRESHOLD_AC_SECOND_BYTE_LEN>
            (l_threshold_voltage);

            FAPI_TRY(mss::pmic::i2c::reg_write_contiguous(l_dts[DT_POS::DT0], DT_REGS::OV_THRESHOLD_CD,
                     l_dt_thresh_buffer));

            // DT1
            FAPI_TRY(mss::pmic::i2c::reg_read_contiguous(l_dts[DT_POS::DT1], DT_REGS::OV_THRESHOLD_CD, l_dt_thresh_buffer));

            // Insert data to first & second buffer for rail A/C
            l_dt_thresh_buffer[1].insertFromRight<DT_FIELDS::OV_THRESH_START_AC_FIRST_BYTE, DT_FIELDS::THRESHOLD_AC_FIRST_BYTE_LEN>
            (l_threshold_voltage >> DT_FIELDS::THRESHOLD_AC_SECOND_BYTE_LEN);
            l_dt_thresh_buffer[0].insertFromRight<DT_FIELDS::OV_THRESH_START_AC_SECOND_BYTE, DT_FIELDS::THRESHOLD_AC_SECOND_BYTE_LEN>
            (l_threshold_voltage);

            FAPI_TRY(mss::pmic::i2c::reg_write_contiguous(l_dts[DT_POS::DT1], DT_REGS::OV_THRESHOLD_CD,
                     l_dt_thresh_buffer));
            // DT 3
            FAPI_TRY(mss::pmic::i2c::reg_read_contiguous(l_dts[DT_POS::DT3], DT_REGS::OV_THRESHOLD_CD, l_dt_thresh_buffer));

            // Insert data to first & second buffer for rail A/C
            l_dt_thresh_buffer[1].insertFromRight<DT_FIELDS::OV_THRESH_START_AC_FIRST_BYTE, DT_FIELDS::THRESHOLD_AC_FIRST_BYTE_LEN>
            (l_threshold_voltage >> DT_FIELDS::THRESHOLD_AC_SECOND_BYTE_LEN);
            l_dt_thresh_buffer[0].insertFromRight<DT_FIELDS::OV_THRESH_START_AC_SECOND_BYTE , DT_FIELDS::THRESHOLD_AC_SECOND_BYTE_LEN>
            (l_threshold_voltage);

            FAPI_TRY(mss::pmic::i2c::reg_write_contiguous(l_dts[DT_POS::DT3], DT_REGS::OV_THRESHOLD_CD,
                     l_dt_thresh_buffer));

            break;

        case mss::pmic::volt_domains::VPP:

            // DT0, DT2 on rail D

            // DT0
            FAPI_TRY(mss::pmic::i2c::reg_read_contiguous(l_dts[DT_POS::DT0], DT_REGS::OV_THRESHOLD_CD, l_dt_thresh_buffer));

            // VPP domain threshold voltage should be calculated with 1/2 input voltage
            l_threshold_voltage = calculate_ov_threshold_voltage(i_voltage / 2);


            // Insert data to first buffer for rail B/D
            l_dt_thresh_buffer[0].insertFromRight<DT_FIELDS::OV_THRESH_START_BD, DT_FIELDS::OV_THRESH_LENGTH_BD>
            (l_threshold_voltage);

            FAPI_TRY(mss::pmic::i2c::reg_write_contiguous(l_dts[DT_POS::DT0], DT_REGS::OV_THRESHOLD_CD,
                     l_dt_thresh_buffer));

            // DT2
            FAPI_TRY(mss::pmic::i2c::reg_read_contiguous(l_dts[DT_POS::DT2], DT_REGS::OV_THRESHOLD_CD, l_dt_thresh_buffer));

            // Insert data to first buffer for rail B/D
            l_dt_thresh_buffer[0].insertFromRight<DT_FIELDS::OV_THRESH_START_BD, DT_FIELDS::OV_THRESH_LENGTH_BD>
            (l_threshold_voltage);

            FAPI_TRY(mss::pmic::i2c::reg_write_contiguous(l_dts[DT_POS::DT2], DT_REGS::OV_THRESHOLD_CD,
                     l_dt_thresh_buffer));

            break;

        case mss::pmic::volt_domains::VIO:

            // DT1 Rail D, DT2 Rail C

            // DT1
            FAPI_TRY(mss::pmic::i2c::reg_read_contiguous(l_dts[DT_POS::DT1], DT_REGS::OV_THRESHOLD_CD, l_dt_thresh_buffer));

            // Insert data to first buffer for rail B/D
            l_dt_thresh_buffer[0].insertFromRight<DT_FIELDS::OV_THRESH_START_BD, DT_FIELDS::OV_THRESH_LENGTH_BD>
            (l_threshold_voltage);

            FAPI_TRY(mss::pmic::i2c::reg_write_contiguous(l_dts[DT_POS::DT1], DT_REGS::OV_THRESHOLD_CD,
                     l_dt_thresh_buffer));

            // DT2
            FAPI_TRY(mss::pmic::i2c::reg_read_contiguous(l_dts[DT_POS::DT2], DT_REGS::OV_THRESHOLD_CD, l_dt_thresh_buffer));

            // Insert data to first & second buffer for rail A/C
            l_dt_thresh_buffer[1].insertFromRight<DT_FIELDS::OV_THRESH_START_AC_FIRST_BYTE, DT_FIELDS::THRESHOLD_AC_FIRST_BYTE_LEN>
            (l_threshold_voltage >> DT_FIELDS::THRESHOLD_AC_SECOND_BYTE_LEN);
            l_dt_thresh_buffer[0].insertFromRight<DT_FIELDS::OV_THRESH_START_AC_SECOND_BYTE, DT_FIELDS::THRESHOLD_AC_SECOND_BYTE_LEN>
            (l_threshold_voltage);

            FAPI_TRY(mss::pmic::i2c::reg_write_contiguous(l_dts[DT_POS::DT2], DT_REGS::OV_THRESHOLD_CD,
                     l_dt_thresh_buffer));
            break;

        default:
            FAPI_ERR(GENTARGTIDFORMAT" Invaild volt domain %u", GENTARGTID(i_ocmb_target), i_volt_domain);
            break;

    }

fapi_try_exit:
    return fapi2::current_err;
}



} // ddr5
} // pmic
} // mss
