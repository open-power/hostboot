/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_enable_utils_ddr5.C $ */
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
/// @file pmic_enable_utils_ddr5.C
/// @brief Utility functions for DDR5 PMIC enable operation
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <i2c_pmic.H>
#include <pmic_consts.H>
#include <pmic_enable_utils_ddr5.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <pmic_enable_4u_settings.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/find.H>
#include <mss_generic_attribute_getters.H>
#include <mss_pmic_attribute_accessors_manual.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/pos.H>


namespace mss
{

namespace pmic
{

namespace ddr5
{
///
/// @brief Setup and enable DT
///
/// @param[in] i_target_info target info struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
///       document provided by the Power team
///
fapi2::ReturnCode setup_dt(const target_info_redundancy_ddr5& i_target_info)
{
    using DT_REGS  = mss::dt::regs;
    static constexpr uint8_t NUM_BYTES_TO_WRITE = 2;

    fapi2::buffer<uint8_t> l_dt_data_to_write[NUM_BYTES_TO_WRITE];

    for (auto l_dt_count = 0; l_dt_count < i_target_info.iv_number_of_target_infos_present; l_dt_count++)
    {
        // If the corresponding PMIC in the PMIC/DT pair is not overridden to disabled, run the enable
        FAPI_TRY_NO_TRACE(mss::pmic::ddr5::run_if_present_dt(i_target_info, l_dt_count, [&l_dt_data_to_write]
                          (const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_dt) -> fapi2::ReturnCode
        {
            FAPI_INF("Setting up DT " GENTARGTIDFORMAT, GENTARGTID(i_dt));

            // Clear faults 0 reg
            l_dt_data_to_write[0] = 0xFF;
            l_dt_data_to_write[1] = 0xFF;
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_contiguous(i_dt, DT_REGS::FAULTS_CLEAR_0, l_dt_data_to_write));

            // Clear faults 1 reg
            l_dt_data_to_write[0] = 0xFF;
            l_dt_data_to_write[1] = 0xFF;
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_contiguous(i_dt, DT_REGS::FAULTS_CLEAR_1, l_dt_data_to_write));

            // Enable efuse
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write(i_dt, DT_REGS::EN_REGISTER, 0x01));

            // Clear breadcrumb register.
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write(i_dt, DT_REGS::BREADCRUMB, 0x00));

            // Delay for 1 ms. Might remove this if natural delay is sufficient
            fapi2::delay(1 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit_lambda:
            return fapi2::current_err;
        }));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief PMIC power down sequence for 2U parts
///
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note There is no support for 1U in DDR5
/// @note The below values of PMIC regs are taken from the
///       "Non-Redundant PoD5 - Functional Specification dated 20230403"
///       document provided by the Power team
///
fapi2::ReturnCode power_down_sequence_2u(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;

    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint8_t> l_pmic_buffer;

    auto l_pmics = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_PMIC>(i_target);

    // Next, sort them by the sequence attributes
    FAPI_TRY(mss::pmic::order_pmics_by_sequence(i_target, l_pmics));

    for (const auto& l_pmic : l_pmics)
    {
        // Disable VR Enable (0 --> Bit 7)
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmic, REGS::R32, l_pmic_buffer));
        l_pmic_buffer.clearBit<FIELDS::R32_VR_ENABLE>();
        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmic, REGS::R32, l_pmic_buffer));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Pre config PMIC for power down or pmic enable.
///        Enable/disable power off seq, enable/disable soft-stop, on-off config global
///
/// @param[in] i_target_info target info struct
/// @param[in] i_value_comp_config bool value to be written to the comp_config register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
///       document provided by the Power team
///
fapi2::ReturnCode pre_config(const target_info_redundancy_ddr5& i_target_info,
                             const bool i_value_comp_config)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
    using TPS_FIELDS = pmicFields<mss::pmic::product::TPS5383X>;

    for (auto l_pmic_count = 0; l_pmic_count < i_target_info.iv_number_of_target_infos_present; l_pmic_count++)
    {
        // If the pmic is not overridden to disabled, run the status checking
        FAPI_TRY_NO_TRACE(mss::pmic::ddr5::run_if_present(i_target_info, l_pmic_count, [i_value_comp_config]
                          (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
        {
            FAPI_INF("Pre-config PMIC " GENTARGTIDFORMAT, GENTARGTID(i_pmic));

            fapi2::buffer<uint8_t> l_reg_buffer;

            static const fapi2::buffer<uint8_t> l_regs_to_be_written_soft_stop[] = {
                REGS::R82,
                REGS::R85,
                REGS::R88,
                REGS::R8B
            };
            // soft-stop
            for (const auto& l_reg_addr : l_regs_to_be_written_soft_stop)
            {
                FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic, l_reg_addr, l_reg_buffer));
                l_reg_buffer.writeBit<FIELDS::COMP_CONFIG>(i_value_comp_config);
                FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic, l_reg_addr, l_reg_buffer));
            }

            // ON/OFF config selection for all rails. Rail turn on/off by EN pin only
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic, TPS_REGS::R9C_ON_OFF_CONFIG_GLOBAL, l_reg_buffer));
            l_reg_buffer.clearBit<TPS_FIELDS::R9C_ON_OFF_CONFIG_BIT_0>();
            l_reg_buffer.setBit<TPS_FIELDS::R9C_ON_OFF_CONFIG_BIT_1>();
            l_reg_buffer.clearBit<TPS_FIELDS::R9C_ON_OFF_CONFIG_BIT_2>();
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic, TPS_REGS::R9C_ON_OFF_CONFIG_GLOBAL, l_reg_buffer));

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit_lambda:
            return fapi2::current_err;
        }));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable/disable PMIC
///
/// @param[in] i_adc ADC target
/// @param[in] i_value to be written to GPO_VALUE ADC reg
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
///       document provided by the Power team
///
fapi2::ReturnCode enable_disable_pmic(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc,
                                      const uint8_t i_value)
{
    using ADC_REGS = mss::adc::regs;

    // Set PMIC_EN to 1
    FAPI_TRY(mss::pmic::i2c::reg_write(i_adc, ADC_REGS::GPO_VALUE, i_value));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief PMIC post-config. Set/Clear VR_ENABLE, write on_off_config_global reg
///
/// @param[in] i_target_info target info struct
/// @param[in] i_value to be written to PMIC R32 reg
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
///       document provided by the Power team
///
fapi2::ReturnCode post_config(const target_info_redundancy_ddr5& i_target_info,
                              const uint8_t i_value)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
    using TPS_FIELDS = pmicFields<mss::pmic::product::TPS5383X>;

    for (auto l_pmic_count = 0; l_pmic_count < i_target_info.iv_number_of_target_infos_present; l_pmic_count++)
    {
        // If the pmic is not overridden to disabled, run the status checking
        FAPI_TRY_NO_TRACE(mss::pmic::ddr5::run_if_present(i_target_info, l_pmic_count, [i_value]
                          (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
        {
            fapi2::buffer<uint8_t> l_pmic_buffer;
            FAPI_INF("Post-config PMIC " GENTARGTIDFORMAT, GENTARGTID(i_pmic));

            // Start VR_ENABLE
            FAPI_INF("Executing VR_ENABLE for PMIC " GENTARGTIDFORMAT, GENTARGTID(i_pmic));
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic, REGS::R32, l_pmic_buffer));
            // Start VR Enable (1 --> Bit 7)
            l_pmic_buffer.writeBit<FIELDS::R32_VR_ENABLE>(i_value);
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic, REGS::R32, l_pmic_buffer));

            // ON/OFF config selection for all rails. Rail turn on by I2C, turn off by I2C or falling edge of PGD1_SNS_1P8
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic, TPS_REGS::R9C_ON_OFF_CONFIG_GLOBAL, l_pmic_buffer));
            l_pmic_buffer.clearBit<TPS_FIELDS::R9C_ON_OFF_CONFIG_BIT_0>();
            l_pmic_buffer.clearBit<TPS_FIELDS::R9C_ON_OFF_CONFIG_BIT_1>();
            l_pmic_buffer.setBit<TPS_FIELDS::R9C_ON_OFF_CONFIG_BIT_2>();
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic, TPS_REGS::R9C_ON_OFF_CONFIG_GLOBAL, l_pmic_buffer));

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit_lambda:
            return fapi2::current_err;
        }));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief PMIC power down sequence for 4U parts
///
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode power_down_sequence_4u(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // Grab the targets as a struct, if they exist
    target_info_redundancy_ddr5 l_target_info(i_target, l_rc);

    // If platform did not provide a usable (functional) set of targets (4 GENERICI2CRESPONDER, at least 2 PMICs),
    // Then we can't properly disable, the part is as good as dead, since re-enable would fail
    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        // We don't fail here because we could be looking at a DIMM that's been deconfigured already
        FAPI_INF("Non-functional targets found from " GENTARGTIDFORMAT, GENTARGTID(i_target));
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_INF("Power down PMICs on target " GENTARGTIDFORMAT, GENTARGTID(i_target));

    // First, pre configure PMIC for power down
    FAPI_TRY(mss::pmic::ddr5::pre_config(l_target_info, CONSTS::DISABLE));

    // Second. Disable PMIC
    FAPI_INF("Disable PMIC using ADC " GENTARGTIDFORMAT, GENTARGTID(l_target_info.iv_adc));
    FAPI_TRY(mss::pmic::ddr5::enable_disable_pmic(l_target_info.iv_adc, CONSTS::DISABLE_PMIC_EN));

    // Third, post config PMIC for power down
    FAPI_TRY(mss::pmic::ddr5::post_config(l_target_info, CONSTS::DISABLE));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Power down function for 4U pmics
/// @param[in] i_target ocmb target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode pmic_power_down(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    uint8_t l_module_height = 0;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    FAPI_TRY(mss::attr::get_dram_module_height(i_target, l_module_height));

    if (l_module_height == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U)
    {
        // For 4U, do our defined disable sequence
        FAPI_TRY(mss::pmic::ddr5::power_down_sequence_4u(i_target));
    }
    else
    {
        FAPI_TRY(mss::pmic::ddr5::power_down_sequence_2u(i_target));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Disable PMICs and clear status bits in preparation for enable
///
/// @param[in] i_ocmb_target OCMB parent target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode disable_and_reset_pmics(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // First, grab the PMIC targets in REL_POS order
    // Make sure to grab all pmics - functional or not, in case the parent OCMB
    // was deconfigured. That may have marked the PMICs as non-functional
    auto l_pmics = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target, fapi2::TARGET_STATE_PRESENT);

    // Next, sort them by the sequence attributes
    FAPI_TRY(mss::pmic::order_pmics_by_sequence(i_ocmb_target, l_pmics));

    // Call the PMIC power down sequence
    FAPI_TRY(mss::pmic::ddr5::pmic_power_down(i_ocmb_target));

    // Reverse loop
    for (int16_t l_i = (l_pmics.size() - 1); l_i >= 0; --l_i)
    {
        const auto& PMIC = l_pmics[l_i];

        // Now that it's disabled, let's clear the status bits so errors don't hang over into the next enable
        // Similarly, we will log bad ReturnCodes here as recoverable for the reasons mentioned above
        l_rc = mss::pmic::status::clear(PMIC);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks if the rev number matches the attr rev number
///
/// @param[in]  i_ocmb_target OCMB target
/// @param[in]  i_pmic_target PMIC target to check
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode validate_pmic_revisions(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    uint8_t l_rev_attr = 0;
    fapi2::buffer<uint8_t> l_rev_reg;
    const uint8_t l_pmic_id = mss::index(i_pmic_target);
    uint8_t l_simics = 0;

    // Get attribute value
    FAPI_TRY(mss::attr::get_revision[l_pmic_id](i_ocmb_target, l_rev_attr));

    // Get the register value
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R3B_REVISION, l_rev_reg));

    if (l_rev_attr == l_rev_reg)
    {
        // The simics check has been added here to skip simics testing of the below function as
        // simics is throwing error for the attribute and revision register mismatch condition.
        // Updating simics is not recommended as there are no real PMICs on the simulation model
        // and skipping this check will not affect rest of the pmic_enable functionality in simics
        // This skips the check in HB CI in simics
        FAPI_TRY(mss::attr::get_is_simics(l_simics));

        if (!l_simics)
        {
            // Check if the attr is same as the register value
            FAPI_TRY(validate_pmic_revisions_helper(i_pmic_target, l_rev_attr, l_rev_reg()));
        }
        else
        {
            FAPI_DBG("Simulation mode detected. Skipping revision check between attr and pmic register");
        }
    }


    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to do fapi assert for checking between attr and reg
///
/// @param[in]  i_pmic_target PMIC target to check
/// @param[in]  i_rev_attr attribute value of the revision
/// @param[in]  i_rev_reg register value of the revision
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode validate_pmic_revisions_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint8_t i_rev_attr,
    const uint8_t i_rev_reg)
{
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target);

    FAPI_INF("PMIC i_rev_attr: 0x%02X, PMIC i_rev_reg: 0x%02X " GENTARGTIDFORMAT, i_rev_attr, i_rev_reg,
             GENTARGTID(i_pmic_target));

    FAPI_ASSERT(i_rev_attr == i_rev_reg,
                fapi2::PMIC_MISMATCHING_REVISIONS_DDR5()
                .set_REVISION_ATTR(i_rev_attr)
                .set_REVISION_REG(i_rev_reg)
                .set_PMIC_TARGET(i_pmic_target)
                .set_OCMB_TARGET(l_ocmb),
                "Mismatching PMIC revisions for ATTR: 0x%02X REG: 0x%02X. May have the wrong SPD for this DIMM." GENTARGTIDFORMAT,
                i_rev_attr,
                i_rev_reg,
                GENTARGTID(i_pmic_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable PMIC for 2U
///
/// @param[in] i_ocmb_target OCMB target parent of PMICs
/// @param[in] i_mode manual/SPD enable mode
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note There is no 1U support for DDR5.
/// @note The below values of PMIC regs are taken from the
///       "Non-Redundant PoD5 - Functional Specification dated 20230403"
///       document provided by the Power team
///
fapi2::ReturnCode enable_2u(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::enable_mode i_mode)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    static constexpr uint8_t PMIC0 = 0;
    static constexpr uint8_t PMIC1 = 1;

    uint16_t l_vendor_id = 0;
    fapi2::buffer<uint8_t> l_pmic_buffer;

    FAPI_INF("Enabling PMICs on " GENTARGTIDFORMAT " with 2U mode", GENTARGTID(i_ocmb_target));

    auto l_pmics = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target, fapi2::TARGET_STATE_PRESENT);
    uint8_t l_first_pmic_id = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_REL_POS, l_pmics[PMIC0], l_first_pmic_id));

    // Check for number of pmics received
    FAPI_TRY(mss::pmic::check_number_pmics_received_2u(i_ocmb_target, l_pmics.size()));

    // Ensure the PMICs are in sorted order
    FAPI_TRY(mss::pmic::order_pmics_by_sequence(i_ocmb_target, l_pmics));

    // Get vendor ID. We just need vendor ID from 1 PMIC as both PMICs will be from the same vendor
    FAPI_TRY(mss::attr::get_mfg_id[l_first_pmic_id](i_ocmb_target, l_vendor_id));

    // Validate vendor id
    FAPI_TRY((mss::pmic::check::matching_vendors(i_ocmb_target, l_pmics[PMIC0])));

    // Validate revision number
    FAPI_TRY(validate_pmic_revisions(i_ocmb_target, l_pmics[PMIC0]));

    for (const auto& l_pmic : l_pmics)
    {
        // PMIC position/ID under OCMB target
        uint8_t l_relative_pmic_id = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_REL_POS, l_pmic, l_relative_pmic_id));

        // Clear global status reg
        FAPI_TRY(mss::pmic::i2c::reg_write(l_pmic, REGS::R14, 0x01));

        // Disable write protection
        FAPI_TRY(mss::pmic::i2c::reg_write(l_pmic, REGS::R2F, 0x06));

        // Set mode FCCM for 2U DDR5 DDIMMs for all rails (continuous current mode)
        // FCCM mode not being set by pmic programming scripts at tester, but will be in future
        // Once pmic programming sets FCCM mode this could be removed but doesn't hurt to leave this in for EUH DDIMMs
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmic, REGS::R29, l_pmic_buffer));
        l_pmic_buffer.insertFromRight<FIELDS::R29_SWA_MODE_SELECT_START, FIELDS::SWX_MODE_SELECT_LENGTH>
        (CONSTS::SWX_MODE_SELECT_FCCM);
        l_pmic_buffer.insertFromRight<FIELDS::R29_SWB_MODE_SELECT_START, FIELDS::SWX_MODE_SELECT_LENGTH>
        (CONSTS::SWX_MODE_SELECT_FCCM);
        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmic, REGS::R29, l_pmic_buffer));
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmic, REGS::R2A, l_pmic_buffer));
        l_pmic_buffer.insertFromRight<FIELDS::R2A_SWC_MODE_SELECT_START, FIELDS::SWX_MODE_SELECT_LENGTH>
        (CONSTS::SWX_MODE_SELECT_FCCM);
        l_pmic_buffer.insertFromRight<FIELDS::R2A_SWD_MODE_SELECT_START, FIELDS::SWX_MODE_SELECT_LENGTH>
        (CONSTS::SWX_MODE_SELECT_FCCM);
        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmic, REGS::R2A, l_pmic_buffer));

        // Enable internal ADC and default to temp readings
        FAPI_TRY(mss::pmic::i2c::reg_write(l_pmic, REGS::R30, 0xD0));

        // Bias with SPD
        if (l_vendor_id == mss::pmic::vendor::TI)
        {
            FAPI_TRY(mss::pmic::bias_with_spd_settings<mss::pmic::vendor::TI>(l_pmic, i_ocmb_target,
                     static_cast<mss::pmic::id>(l_relative_pmic_id)));
        }
        else
        {
            FAPI_ERR("Renesas not yet supported");
        }
    }

    FAPI_INF("Executing VR_ENABLE for PMIC " GENTARGTIDFORMAT, GENTARGTID(l_pmics[PMIC0]));
    // Start VR Enable (1 --> Bit 7)
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmics[PMIC0], REGS::R32, l_pmic_buffer));
    l_pmic_buffer.setBit<FIELDS::R32_VR_ENABLE>();
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmics[PMIC0], REGS::R32, l_pmic_buffer));

    FAPI_INF("Executing VR_ENABLE for PMIC " GENTARGTIDFORMAT, GENTARGTID(l_pmics[PMIC1]));
    // Start VR Enable (1 --> Bit 7)
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmics[PMIC1], REGS::R32, l_pmic_buffer));
    l_pmic_buffer.setBit<FIELDS::R32_VR_ENABLE>();
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmics[PMIC1], REGS::R32, l_pmic_buffer));

    // Enable TI PMIC
    if (l_vendor_id == mss::pmic::vendor::TI)
    {
        // TI will be enabled by releasing the CAMP control first and then re-instating it
        FAPI_INF("Executing CAMP control release for TI PMIC " GENTARGTIDFORMAT, GENTARGTID(l_pmics[PMIC0]));
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmics[PMIC0], REGS::R32, l_pmic_buffer));
        // Release CAMP control (R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL) (1 --> Bit 3)
        l_pmic_buffer.setBit<FIELDS::R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL>();
        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmics[PMIC0], REGS::R32, l_pmic_buffer));

        FAPI_INF("Executing CAMP control release for TI PMIC " GENTARGTIDFORMAT, GENTARGTID(l_pmics[PMIC1]));
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmics[PMIC1], REGS::R32, l_pmic_buffer));
        // Release CAMP control (R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL) (1 --> Bit 3)
        l_pmic_buffer.setBit<FIELDS::R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL>();
        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmics[PMIC1], REGS::R32, l_pmic_buffer));

        // Delay 40mS
        fapi2::delay(40 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

        // Re-instate CAMP control
        FAPI_INF("Re-instating CAMP control for TI PMIC " GENTARGTIDFORMAT, GENTARGTID(l_pmics[PMIC0]));
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmics[PMIC0], REGS::R32, l_pmic_buffer));
        // Re-instate CAMP control (R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL) (0 --> Bit 3)
        l_pmic_buffer.clearBit<FIELDS::R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL>();
        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmics[PMIC0], REGS::R32, l_pmic_buffer));

        FAPI_INF("Re-instating CAMP control for TI PMIC " GENTARGTIDFORMAT, GENTARGTID(l_pmics[PMIC1]));
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmics[PMIC1], REGS::R32, l_pmic_buffer));
        // Re-instate CAMP control (R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL) (0 --> Bit 3)
        l_pmic_buffer.clearBit<FIELDS::R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL>();
        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmics[PMIC1], REGS::R32, l_pmic_buffer));
    }
    // Enable IDT/Renesas PMIC
    else if (l_vendor_id == mss::pmic::vendor::IDT)
    {
        FAPI_ERR("Renesas not yet supported");
    }


    FAPI_INF("Successfully enabled PMICs on" GENTARGTIDFORMAT " with 2U mode", GENTARGTID(i_ocmb_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Setup ADC
///
/// @param[in] i_adc ADC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
///       document provided by the Power team
///
fapi2::ReturnCode setup_adc(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc)
{
    using ADC_REGS = mss::adc::regs;
    static constexpr uint8_t NUM_BYTES_TO_WRITE = 24;
    static constexpr uint8_t ARRAY_OFFSET = ADC_REGS::HYSTERESIS_CH1;

    fapi2::buffer<uint8_t> l_data_adc[NUM_BYTES_TO_WRITE];

    FAPI_INF("Enabling ADC " GENTARGTIDFORMAT, GENTARGTID(i_adc));

    l_data_adc[ADC_REGS::SYSTEM_STATUS] = 0x01;
    l_data_adc[ADC_REGS::GENERAL_CFG]   = 0x30;
    l_data_adc[ADC_REGS::DATA_CFG] = 0x00;
    l_data_adc[ADC_REGS::OSR_CFG]   = 0x07;
    l_data_adc[ADC_REGS::OPMODE_CFG] = 0x32;
    l_data_adc[ADC_REGS::PIN_CFG]   = 0x81;
    l_data_adc[ADC_REGS::DUMMY_BYTE_0] = 0x00;
    l_data_adc[ADC_REGS::GPIO_CFG]   = 0x81;
    l_data_adc[ADC_REGS::DUMMY_BYTE_1] = 0x00;
    l_data_adc[ADC_REGS::GPO_DRIVE_CFG]   = 0x80;
    l_data_adc[ADC_REGS::DUMMY_BYTE_2] = 0x00;
    l_data_adc[ADC_REGS::GPO_VALUE]   = 0x01;
    l_data_adc[ADC_REGS::DUMMY_BYTE_3] = 0x00;
    l_data_adc[ADC_REGS::GPI_VALUE]   = 0x00;
    l_data_adc[ADC_REGS::DUMMY_BYTE_4] = 0x00;
    l_data_adc[ADC_REGS::DUMMY_BYTE_5]   = 0x00;
    l_data_adc[ADC_REGS::SEQUENCE_CFG] = 0x11;
    l_data_adc[ADC_REGS::CHANNEL_SEQ]   = 0x00;
    l_data_adc[ADC_REGS::AUTO_SEQ_CH_SEL] = 0x7E;
    l_data_adc[ADC_REGS::DUMMY_BYTE_6]   = 0x00;
    l_data_adc[ADC_REGS::ALERT_CH_SEL] = 0x7E;
    l_data_adc[ADC_REGS::DUMMY_BYTE_7]   = 0x00;
    l_data_adc[ADC_REGS::ALERT_MAP]   = 0x00;
    l_data_adc[ADC_REGS::ALERT_PIN_CFG] = 0x00;

    //ADC write
    FAPI_TRY(mss::pmic::i2c::reg_write_contiguous(i_adc, ADC_REGS::SYSTEM_STATUS, l_data_adc));

    // ADC::EVENT_RGN reg
    l_data_adc[0] = 0x00;
    FAPI_TRY(mss::pmic::i2c::reg_write(i_adc, ADC_REGS::EVENT_RGN, l_data_adc[0]));

    // Using the same l_data_adc array here as we have to write exactly 24 bytes below too
    l_data_adc[ADC_REGS::HYSTERESIS_CH1 - ARRAY_OFFSET]  = 0xF1;
    l_data_adc[ADC_REGS::HIGH_TH_CH1 - ARRAY_OFFSET]     = 0xFF;
    l_data_adc[ADC_REGS::EVENT_COUNT_CH1 - ARRAY_OFFSET] = 0xE4;
    l_data_adc[ADC_REGS::LOW_TH_CH1 - ARRAY_OFFSET]      = 0xA5;

    l_data_adc[ADC_REGS::HYSTERESIS_CH2 - ARRAY_OFFSET]  = 0xF1;
    l_data_adc[ADC_REGS::HIGH_TH_CH2 - ARRAY_OFFSET]     = 0xFF;
    l_data_adc[ADC_REGS::EVENT_COUNT_CH2 - ARRAY_OFFSET] = 0x34;
    l_data_adc[ADC_REGS::LOW_TH_CH2 - ARRAY_OFFSET]      = 0x8A;

    l_data_adc[ADC_REGS::HYSTERESIS_CH3 - ARRAY_OFFSET]  = 0xF1;
    l_data_adc[ADC_REGS::HIGH_TH_CH3 - ARRAY_OFFSET]     = 0xFF;
    l_data_adc[ADC_REGS::EVENT_COUNT_CH3 - ARRAY_OFFSET] = 0x24;
    l_data_adc[ADC_REGS::LOW_TH_CH3 - ARRAY_OFFSET]      = 0x45;

    l_data_adc[ADC_REGS::HYSTERESIS_CH4 - ARRAY_OFFSET]  = 0xF1;
    l_data_adc[ADC_REGS::HIGH_TH_CH4 - ARRAY_OFFSET]     = 0xFF;
    l_data_adc[ADC_REGS::EVENT_COUNT_CH4 - ARRAY_OFFSET] = 0xF4;
    l_data_adc[ADC_REGS::LOW_TH_CH4 - ARRAY_OFFSET]      = 0x52;

    l_data_adc[ADC_REGS::HYSTERESIS_CH5 - ARRAY_OFFSET]  = 0xF1;
    l_data_adc[ADC_REGS::HIGH_TH_CH5 - ARRAY_OFFSET]     = 0xFF;
    l_data_adc[ADC_REGS::EVENT_COUNT_CH5 - ARRAY_OFFSET] = 0xE4;
    l_data_adc[ADC_REGS::LOW_TH_CH5 - ARRAY_OFFSET]      = 0xA5;

    l_data_adc[ADC_REGS::HYSTERESIS_CH6 - ARRAY_OFFSET]  = 0xF1;
    l_data_adc[ADC_REGS::HIGH_TH_CH6 - ARRAY_OFFSET]     = 0xFF;
    l_data_adc[ADC_REGS::EVENT_COUNT_CH6 - ARRAY_OFFSET] = 0x65;
    l_data_adc[ADC_REGS::LOW_TH_CH6 - ARRAY_OFFSET]      = 0x65;
    FAPI_TRY(mss::pmic::i2c::reg_write_contiguous(i_adc, ADC_REGS::HYSTERESIS_CH1, l_data_adc));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Setup and initialize PMIC
///
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_target_info target info struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
///       document provided by the Power team
///
fapi2::ReturnCode initialize_pmic(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                                  const target_info_redundancy_ddr5& i_target_info)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;
    static constexpr uint8_t NUM_BYTES_TO_WRITE = 2;

    for (auto l_pmic_count = 0; l_pmic_count < i_target_info.iv_number_of_target_infos_present; l_pmic_count++)
    {
        // If the pmic is not overridden to disabled, run the status checking
        FAPI_TRY_NO_TRACE(mss::pmic::ddr5::run_if_present(i_target_info, l_pmic_count, [i_ocmb_target]
                          (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
        {
            uint16_t l_vendor_id = 0;
            fapi2::buffer<uint8_t> l_pmic_data_to_write[NUM_BYTES_TO_WRITE];

            FAPI_INF("Initializing PMIC " GENTARGTIDFORMAT, GENTARGTID(i_pmic));

            // PMIC position/ID under OCMB target
            uint8_t l_relative_pmic_id = 0;
            FAPI_TRY_LAMBDA(FAPI_ATTR_GET(fapi2::ATTR_REL_POS, i_pmic, l_relative_pmic_id));

            // Clear global status reg
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write(i_pmic, REGS::R14, 0x01));

            // Disable write protection
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write(i_pmic, REGS::R2F, 0x06));

            // Unlock DDIMM vendor region
            FAPI_TRY_LAMBDA(mss::pmic::unlock_vendor_region(i_pmic));

            // Write to reg lock reg
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write(i_pmic, TPS_REGS::RA2_REG_LOCK, 0x00));
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write(i_pmic, TPS_REGS::RA2_REG_LOCK, 0x95));
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write(i_pmic, TPS_REGS::RA2_REG_LOCK, 0x64));

            // Enable internal ADC and default to temp readings
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write(i_pmic, REGS::R30, 0xD0));

            // Write to Mask status 0 & 1 regs
            l_pmic_data_to_write[0] = 0x3C;
            l_pmic_data_to_write[1] = 0x60;
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_contiguous(i_pmic, REGS::R15, l_pmic_data_to_write));

            // Set VIN_BULK PG threshold
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write(i_pmic, REGS::R1A, 0x60));

            // Get PMIC vendor
            FAPI_TRY_LAMBDA(mss::attr::get_mfg_id[l_relative_pmic_id](i_ocmb_target, l_vendor_id));

            // Bias with SPD
            if (l_vendor_id == mss::pmic::vendor::TI)
            {
                FAPI_TRY_LAMBDA(mss::pmic::bias_with_spd_settings<mss::pmic::vendor::TI>(i_pmic, i_ocmb_target,
                static_cast<mss::pmic::id>(l_relative_pmic_id)));
            }
            else
            {
                FAPI_ERR("Renesas not yet supported");
            }

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit_lambda:
            return fapi2::current_err;
        }));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Clear ADC events that previously occurred. If not then ALERT will immediately assert.
///
/// @param[in] i_adc ADC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
///       document provided by the Power team
///
fapi2::ReturnCode clear_adc_events(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc)
{
    using ADC_REGS = mss::adc::regs;

    fapi2::buffer<uint8_t> l_reg_contents;

    FAPI_INF("Clearing previous ADC events port pmic_enable() " GENTARGTIDFORMAT, GENTARGTID(i_adc));

    FAPI_TRY(mss::pmic::i2c::reg_write(i_adc, ADC_REGS::LOW_EVENT_FLAGS, 0xFF));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Verify if the pmics have been enabled properly and if not create a unique case of breadcrumbs
///
/// @param[in] i_target_info target info struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
// TODO: ZEN:MST-2171 Call health check and periodic telemetry at the end of pmic_enable
fapi2::ReturnCode redundancy_check_all_pmics(const target_info_redundancy_ddr5& i_target_info)
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Set the up DTs, ADCs, PMICs for a redundancy configuration / 4U
///
/// @param[in] i_ocmb_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
///       document provided by the Power team
///
fapi2::ReturnCode enable_with_redundancy(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target)
{
    FAPI_INF("Enabling PMICs on " GENTARGTIDFORMAT " with 4U/redundancy mode", GENTARGTID(i_ocmb_target));

    fapi2::buffer<uint8_t> l_reg_contents;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    static constexpr uint8_t PMIC0 = 0;

    // Grab the targets as a struct, if they exist
    target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);

    // If platform did not provide a usable set of targets (1 GENERIC_I2C_DEV, at least 3 PMICs and 3 DTs),
    // Then we can't properly enable
    FAPI_TRY(l_rc, "Unusable PMIC/POWER_IC/GENERIC_I2C_DEV child target configuration found from "
             GENTARGTIDFORMAT, GENTARGTID(i_ocmb_target));

    // Zeroth, set up the ADC devices
    FAPI_TRY(mss::pmic::ddr5::setup_adc(l_target_info.iv_adc));

    // First, initialize and enable DT
    FAPI_TRY(mss::pmic::ddr5::setup_dt(l_target_info));

    // Validate the vendor_id and revision
    // 1a, Validate pmic vendor id
    FAPI_TRY((mss::pmic::check::matching_vendors(i_ocmb_target, l_target_info.iv_pmic_dt_map[PMIC0].iv_pmic)));

    // 1b, Validate and return revision number
    FAPI_TRY(validate_pmic_revisions(i_ocmb_target, l_target_info.iv_pmic_dt_map[PMIC0].iv_pmic));

    // Second, initialize PMIC
    FAPI_TRY(mss::pmic::ddr5::initialize_pmic(i_ocmb_target, l_target_info));

    // 3a, Pre config pmic for power off seq, disable soft-stop, set global on_off_config
    FAPI_TRY(mss::pmic::ddr5::pre_config(l_target_info, CONSTS::ENABLE));

    // 3b, Enable PMIC
    FAPI_TRY(mss::pmic::ddr5::enable_disable_pmic(l_target_info.iv_adc, CONSTS::SET_PMIC_EN));

    // Delay for 60 ms
    fapi2::delay(60 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // 3c, Post config PMIC for VR_ENABLE
    FAPI_INF("Enable PMIC using ADC " GENTARGTIDFORMAT, GENTARGTID(l_target_info.iv_adc));
    FAPI_TRY(mss::pmic::ddr5::post_config(l_target_info, CONSTS::ENABLE));

    // Fourth, Clear ADC events
    FAPI_TRY(mss::pmic::ddr5::clear_adc_events(l_target_info.iv_adc));

    // Fifth, verification
    // TODO: ZEN:MST-2171 Call health check and periodic telemetry at the end of pmic_enable
    // Now, check that the PMICs were enabled properly. If any don't report on that are expected
    // to be on, create a unique case of breadcrumbs
    FAPI_TRY(mss::pmic::ddr5::redundancy_check_all_pmics(l_target_info));

    FAPI_INF("Successfully enabled PMICs on" GENTARGTIDFORMAT " with 4U/redundancy mode", GENTARGTID(i_ocmb_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable function for pmic modules
/// @param[in] i_target ocmb target
/// @param[in] i_mode enable mode operation
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode pmic_enable(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                              const mss::pmic::enable_mode i_mode)
{
    // Check that we have functional pmics to enable, otherwise, we can just exit now
    if (mss::find_targets<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target, fapi2::TARGET_STATE_PRESENT).empty())
    {
        FAPI_INF("No PMICs to enable on " GENTARGTIDFORMAT ", exiting.", GENTARGTID(i_ocmb_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Disable PMICs and clear status bits so we are starting at a known off state
    // PMICS do not get disbaled when we deconfig ocmb targets. The below function ensures that all the pmics
    // in the world get disbaled first before enabling them.
    FAPI_TRY(mss::pmic::ddr5::disable_and_reset_pmics(i_ocmb_target));

    // This procedure can be called with non-functional targets, so here, we will only
    // choose to enable those that are functional (duh!)
    if (i_ocmb_target.isFunctional())
    {
        uint8_t l_module_height = 0;

        // Grab the module-height attribute to determine 1U/2U vs 4U
        FAPI_TRY(mss::attr::get_dram_module_height(i_ocmb_target, l_module_height));

        // Kick off the matching enable procedure
        if (l_module_height == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U)
        {
            FAPI_INF("Enabling PMICs on " GENTARGTIDFORMAT "with Redundancy/4U Mode", GENTARGTID(i_ocmb_target));
            FAPI_TRY(mss::pmic::ddr5::enable_with_redundancy(i_ocmb_target));
        }
        else
        {
            FAPI_INF("Enabling PMICs on " GENTARGTIDFORMAT "with 2U Mode", GENTARGTID(i_ocmb_target));
            FAPI_TRY(mss::pmic::ddr5::enable_2u(i_ocmb_target, i_mode));
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns ddr5
} // ns pmic
} // ns mss
