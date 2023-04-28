/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_common_utils_ddr5.C $ */
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
/// @brief Write a register of a PMIC target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
///
void pmic_reg_write(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg, const fapi2::buffer<uint8_t>& i_data)
{
    if (!(io_pmic.iv_pmic_state & mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_write(io_pmic.iv_pmic, i_reg, i_data) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic.iv_pmic_state |= mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL;
        }
    }
}

///
/// @brief Write a register of a DT target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair struct including target / state info
/// @param[in] i_reg register
/// @param[in] i_data input buffer
///
void dt_reg_write(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg, const fapi2::buffer<uint8_t>& i_data)
{
    if (!(io_pmic.iv_dt_state & mss::pmic::ddr5::dt_state::DT_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_write(io_pmic.iv_dt, i_reg, i_data) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic.iv_dt_state |= mss::pmic::ddr5::dt_state::DT_I2C_FAIL;
        }
    }
}


///
/// @brief Read contiguous registers of a PMIC target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_output output buffer
///
template <size_t N>
void pmic_reg_read_contiguous(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg,
                              fapi2::buffer<uint8_t> (&o_output)[N])
{
    if (!(io_pmic.iv_pmic_state & mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_read_contiguous(io_pmic.iv_pmic, i_reg, o_output) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic.iv_pmic_state |= mss::pmic::ddr5::pmic_state::PMIC_I2C_FAIL;
        }
    }
}

///
/// @brief Read contiguous registers of a DT target. This function is for the runtime health check and telemetry functions
///        because it updates the pmic and dt states, and doesn't update fapi2::current_err
///
/// @param[in,out] io_pmic target_info_pmic_dt_pair class including target / state info
/// @param[in] i_reg register
/// @param[out] o_output output buffer
///
template <size_t N>
void dt_reg_read_contiguous(target_info_pmic_dt_pair& io_pmic, const uint8_t i_reg,
                            fapi2::buffer<uint8_t> (&o_output)[N])
{
    if (!(io_pmic.iv_dt_state & mss::pmic::ddr5::dt_state::DT_I2C_FAIL))
    {
        if (mss::pmic::i2c::reg_read_contiguous(io_pmic.iv_dt, i_reg, o_output) != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            io_pmic.iv_dt_state |= mss::pmic::ddr5::dt_state::DT_I2C_FAIL;
        }
    }
}

} // ddr5
} // pmic
} // mss
