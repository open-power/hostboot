/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_enable_utils_ddr5.C $ */
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
/// @file pmic_enable_utils_ddr5.C
/// @brief Utility functions for DDR5 PMIC enable operation
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <i2c_pmic.H>
#include <pmic_consts.H>
#include <pmic_enable_utils_ddr5.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <lib/utils/pmic_health_check_utils_ddr5.H>
#include <lib/utils/pmic_periodic_telemetry_utils_ddr5.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/find.H>
#include <mss_generic_attribute_getters.H>
#include <mss_pmic_attribute_accessors_manual.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/poll.H>


namespace mss
{

namespace pmic
{

namespace ddr5
{

///
/// @brief Updates VDD domain during dt enable sequence
/// @param[in] i_target_info target info struct
/// @param[in] i_pmic_id PMIC being addressed in sorted array
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode inline __attribute__((always_inline)) update_vdd_ov_threshold(const target_info_redundancy_ddr5&
        i_target_info,
        const uint8_t i_pmic_id)
{
    uint32_t l_nominal_voltage = 0;
    // Get nominal ddr5 voltage
    FAPI_TRY(mss::pmic::ddr5::get_nominal_voltage_ddr5(
                 i_target_info,
                 i_pmic_id,
                 mss::pmic::rail::SWC,
                 l_nominal_voltage));

    // Update VDD OV threshold
    FAPI_TRY(mss::pmic::ddr5::update_ov_threshold(i_target_info.iv_ocmb,
             mss::pmic::volt_domains::VDD,
             l_nominal_voltage));

fapi_try_exit:
    return fapi2::current_err;
}

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
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    static constexpr uint8_t NUM_BYTES_TO_WRITE = 2;
    static constexpr uint8_t NUM_REGS_TO_WRITE = 2;

    fapi2::buffer<uint8_t> l_dt_data_to_write[NUM_BYTES_TO_WRITE] = {0xFF, 0xFF};

    for (auto l_dt_count = 0; l_dt_count < CONSTS::NUM_PMICS_4U; l_dt_count++)
    {
        // If the corresponding PMIC in the PMIC/DT pair is not overridden to disabled, run the enable
        FAPI_TRY_NO_TRACE(mss::pmic::ddr5::run_if_present_dt(i_target_info, l_dt_count, [&l_dt_data_to_write, l_dt_count,
                          &i_target_info]
                          (const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_dt) -> fapi2::ReturnCode
        {
            FAPI_INF_NO_SBE("Setting up DT " GENTARGTIDFORMAT, GENTARGTID(i_dt));

            const dt::regs FAULTS_CLEAR[] = { DT_REGS::FAULTS_CLEAR_0, DT_REGS::FAULTS_CLEAR_1 };

            for (auto l_dt_reg_count = 0; l_dt_reg_count < NUM_REGS_TO_WRITE; l_dt_reg_count++)
            {
                // Clear faults reg
                FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_contiguous(i_dt, FAULTS_CLEAR[l_dt_reg_count], l_dt_data_to_write));
            }

            // Enable efuse
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write(i_dt, DT_REGS::EN_REGISTER, 0x01));

            // Clear breadcrumb register.
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write(i_dt, DT_REGS::BREADCRUMB, 0x00));

            // Delay for 1 ms. Might remove this if natural delay is sufficient
            fapi2::delay(1 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit_lambda:
            return mss::pmic::declare_n_mode(i_target_info.iv_ocmb, l_dt_count);
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
#ifndef __PPE__
fapi2::ReturnCode power_down_sequence_2u(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;

    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    auto l_pmics = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_PMIC>(i_target);

    // Next, sort them by the sequence attributes
    FAPI_TRY(mss::pmic::order_pmics_by_sequence(i_target, l_pmics));

    // Reverse loop, so we disable in the opposite order as the enable
    for (int16_t l_i = (l_pmics.size() - 1); l_i >= 0; --l_i)
    {
        const auto& PMIC = l_pmics[l_i];
        fapi2::buffer<uint8_t> l_reg_contents;

        // Redundant clearBit, but just so it's clear what we're doing
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(PMIC, REGS::R32, l_reg_contents));
        l_reg_contents.clearBit<FIELDS::R32_VR_ENABLE>();

        // We are opting here to log RC's here as recovered. If this register write fails,
        // the ones later in the procedure will fail as well.
        l_rc = mss::pmic::i2c::reg_write_reverse_buffer(PMIC, REGS::R32, l_reg_contents);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
#ifndef __PPE__
            fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
#endif
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }
    }

    // Delay for 40 ms.
    fapi2::delay(40 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}
#endif

///
/// @brief Pre/post config PMIC
///        Pre -- for power down or pmic enable.
///               Enable/disable power off seq, enable/disable soft-stop, on-off config global
///        Post --  PMIC post-config. Set/Clear VR_ENABLE, write on_off_config_global reg
///
/// @param[in] i_target_info target info struct
/// @param[in] i_is_preconfig bool set context for execution
/// @param[in] i_value bool value to be written to the comp_config register (pre) / PMIC R32 reg (post)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
///       document provided by the Power team
///
fapi2::ReturnCode prepost_config(const target_info_redundancy_ddr5& i_target_info,
                                 const bool i_is_preconfig,
                                 const bool i_value)
{
    using REGS = pmicRegs<mss::pmic::product::JEDEC_COMPLIANT>;
    using TPS_REGS = pmicRegs<mss::pmic::product::TPS5383X>;
    using FIELDS = pmicFields<mss::pmic::product::JEDEC_COMPLIANT>;
    using TPS_FIELDS = pmicFields<mss::pmic::product::TPS5383X>;

    for (auto l_pmic_count = 0; l_pmic_count < i_target_info.iv_number_of_target_infos_present; l_pmic_count++)
    {
        // If the pmic is not overridden to disabled, run the status checking
        FAPI_TRY_NO_TRACE(mss::pmic::ddr5::run_if_present(i_target_info, l_pmic_count, [&i_is_preconfig, &i_value,
                          &i_target_info, l_pmic_count]
                          (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
        {
            FAPI_INF_NO_SBE("%s-config PMIC " GENTARGTIDFORMAT, (i_is_preconfig) ? ("Pre") : ("Post"), GENTARGTID(i_pmic));
            fapi2::buffer<uint8_t> l_reg_buffer;
            static const fapi2::buffer<uint8_t> l_regs_to_be_written_soft_stop[] = {
                REGS::R82,
                REGS::R85,
                REGS::R88,
                REGS::R8B
            };

            if (i_is_preconfig == PRE_CONFIG)
            {
                // soft-stop
                for (const auto& l_reg_addr : l_regs_to_be_written_soft_stop)
                {
                    FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic, l_reg_addr, l_reg_buffer));
                    l_reg_buffer.writeBit<FIELDS::COMP_CONFIG>(i_value);
                    FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic, l_reg_addr, l_reg_buffer));
                }
            }
            else
            {
                // Start VR_ENABLE
                FAPI_INF_NO_SBE("Executing VR_ENABLE for PMIC " GENTARGTIDFORMAT, GENTARGTID(i_pmic));
                FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic, REGS::R32, l_reg_buffer));
                // Start VR Enable (1 --> Bit 7)
                l_reg_buffer.writeBit<FIELDS::R32_VR_ENABLE>(i_value);
                FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic, REGS::R32, l_reg_buffer));
            }

            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_read_reverse_buffer(i_pmic, TPS_REGS::R9C_ON_OFF_CONFIG_GLOBAL, l_reg_buffer));
            l_reg_buffer.clearBit<TPS_FIELDS::R9C_ON_OFF_CONFIG_BIT_0>();
            l_reg_buffer.writeBit<TPS_FIELDS::R9C_ON_OFF_CONFIG_BIT_1>(i_is_preconfig == PRE_CONFIG);
            l_reg_buffer.writeBit<TPS_FIELDS::R9C_ON_OFF_CONFIG_BIT_2>(i_is_preconfig == POST_CONFIG);
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_reverse_buffer(i_pmic, TPS_REGS::R9C_ON_OFF_CONFIG_GLOBAL, l_reg_buffer));

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit_lambda:
            return mss::pmic::declare_n_mode(i_target_info.iv_ocmb, l_pmic_count);
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
        FAPI_INF_NO_SBE("Non-functional targets found from " GENTARGTIDFORMAT, GENTARGTID(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_INF_NO_SBE("Power down PMICs on target " GENTARGTIDFORMAT, GENTARGTID(i_target));

    // First, pre configure PMIC for power down
    FAPI_TRY(mss::pmic::ddr5::prepost_config(l_target_info, PRE_CONFIG, CONSTS::DISABLE));

    // Second. Disable PMIC
    FAPI_INF_NO_SBE("Disable PMIC using ADC " GENTARGTIDFORMAT, GENTARGTID(l_target_info.iv_adc));
    FAPI_TRY(mss::pmic::ddr5::enable_disable_pmic(l_target_info.iv_adc, CONSTS::DISABLE_PMIC_EN));

    // Delay for 60 ms.
    fapi2::delay(60 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // Third, post config PMIC for power down
    FAPI_TRY(mss::pmic::ddr5::prepost_config(l_target_info, POST_CONFIG, CONSTS::DISABLE));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Power down function for 4U pmics
/// @param[in] i_target ocmb target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode inline __attribute__((always_inline)) pmic_power_down(const
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    uint8_t l_module_height = 0;

#ifndef __PPE__
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_MODULE_HEIGHT, i_target, l_module_height));
#else
    l_module_height = fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_DRAM_MODULE_HEIGHT;
#endif

    if (l_module_height == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U)
    {
        // For 4U, do our defined disable sequence
        FAPI_TRY(mss::pmic::ddr5::power_down_sequence_4u(i_target));
    }

#ifndef __PPE__
    else
    {
        FAPI_TRY(mss::pmic::ddr5::power_down_sequence_2u(i_target));
    }

#endif

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
#ifndef __PPE__
            fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_RECOVERED);
#endif
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

#ifdef __PPE__
    const static uint8_t REVISION[] =
    {
        fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_PMIC0_REVISION,
        fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_PMIC1_REVISION,
        fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_PMIC2_REVISION,
        fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_PMIC3_REVISION
    };
    l_rev_attr = REVISION[l_pmic_id];
#else
    // Get attribute
    FAPI_TRY(mss::attr::get_revision[l_pmic_id](i_ocmb_target, l_rev_attr));
#endif


    // Get the register value
    FAPI_TRY(mss::pmic::i2c::reg_read(i_pmic_target, REGS::R3B_REVISION, l_rev_reg));

    if (l_rev_attr == l_rev_reg)
    {
        // The simics check has been added here to skip simics testing of the below function as
        // simics is throwing error for the attribute and revision register mismatch condition.
        // Updating simics is not recommended as there are no real PMICs on the simulation model
        // and skipping this check will not affect rest of the pmic_enable functionality in simics
        // This skips the check in HB CI in simics
#ifdef __PPE__
        l_simics = fapi2::ATTR::TARGET_TYPE_SYSTEM::ATTR_IS_SIMICS;
#else
        FAPI_TRY(mss::attr::get_is_simics(l_simics));
#endif

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
#ifndef __PPE__
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

    FAPI_INF_NO_SBE("Enabling PMICs on " GENTARGTIDFORMAT " with 2U mode", GENTARGTID(i_ocmb_target));

    auto l_pmics = mss::find_targets_sorted_by_pos<fapi2::TARGET_TYPE_PMIC>(i_ocmb_target, fapi2::TARGET_STATE_PRESENT);
    // We're guaranteed to have at least one PMIC here due to the check in pmic_enable
    auto l_current_pmic = l_pmics[0];
    uint8_t l_first_pmic_id = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_REL_POS, l_pmics[PMIC0], l_first_pmic_id));

    // Check for number of pmics received
    FAPI_TRY(mss::pmic::check_number_pmics_received_2u(i_ocmb_target, l_pmics.size()));

    // Ensure the PMICs are in sorted order
    FAPI_TRY(mss::pmic::order_pmics_by_sequence(i_ocmb_target, l_pmics));

#ifdef __PPE__
    const static uint16_t MFG_ID[] =
    {
        fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_PMIC0_MFG_ID,
        fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_PMIC1_MFG_ID,
        fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_PMIC2_MFG_ID,
        fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_PMIC3_MFG_ID
    };
    // Get vendor ID. We just need vendor ID from 1 PMIC as both PMICs will be from the same vendor
    l_vendor_id = MFG_ID[l_first_pmic_id];
#else
    FAPI_TRY(mss::attr::get_mfg_id[l_first_pmic_id](i_ocmb_target, l_vendor_id));
#endif

    // Validate vendor id
    FAPI_TRY((mss::pmic::check::matching_vendors(i_ocmb_target, l_pmics[PMIC0])));

    // Validate revision number
    FAPI_TRY(validate_pmic_revisions(i_ocmb_target, l_pmics[PMIC0]));

    for (const auto& l_pmic : l_pmics)
    {
        l_current_pmic = l_pmic;
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
            // Unlock DDIMM vendor region
            // This step has been skipped here as the first step bias_with_spd_settings() does
            // is to unlock vendor region. Per the power team, the order of unlocking does not matter here

            // Write to reg lock reg
            FAPI_TRY(mss::pmic::status::unlock_pmic_r70_to_ra3(l_pmic));

            FAPI_TRY(mss::pmic::bias_with_spd_settings<mss::pmic::vendor::TI>(l_pmic, i_ocmb_target,
                     static_cast<mss::pmic::id>(l_relative_pmic_id)));
        }
        else
        {
            FAPI_ERR("Renesas not yet supported");
        }
    }

    FAPI_INF_NO_SBE("Executing VR_ENABLE for PMIC " GENTARGTIDFORMAT, GENTARGTID(l_pmics[PMIC0]));
    l_current_pmic = l_pmics[PMIC0];
    // Start VR Enable (1 --> Bit 7)
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmics[PMIC0], REGS::R32, l_pmic_buffer));
    l_pmic_buffer.setBit<FIELDS::R32_VR_ENABLE>();
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmics[PMIC0], REGS::R32, l_pmic_buffer));

    FAPI_INF_NO_SBE("Executing VR_ENABLE for PMIC " GENTARGTIDFORMAT, GENTARGTID(l_pmics[PMIC1]));
    // We have 2 PMICs here as check_number_pmics_received_2u() above makes sure we have 2 PMICs
    l_current_pmic = l_pmics[PMIC1];
    // Start VR Enable (1 --> Bit 7)
    FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmics[PMIC1], REGS::R32, l_pmic_buffer));
    l_pmic_buffer.setBit<FIELDS::R32_VR_ENABLE>();
    FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmics[PMIC1], REGS::R32, l_pmic_buffer));

    // Enable TI PMIC
    if (l_vendor_id == mss::pmic::vendor::TI)
    {
        // TI will be enabled by releasing the CAMP control first and then re-instating it
        FAPI_INF_NO_SBE("Executing CAMP control release for TI PMIC " GENTARGTIDFORMAT, GENTARGTID(l_pmics[PMIC0]));
        l_current_pmic = l_pmics[PMIC0];
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmics[PMIC0], REGS::R32, l_pmic_buffer));
        // Release CAMP control (R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL) (1 --> Bit 3)
        l_pmic_buffer.setBit<FIELDS::R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL>();
        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmics[PMIC0], REGS::R32, l_pmic_buffer));

        FAPI_INF_NO_SBE("Executing CAMP control release for TI PMIC " GENTARGTIDFORMAT, GENTARGTID(l_pmics[PMIC1]));
        l_current_pmic = l_pmics[PMIC1];
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmics[PMIC1], REGS::R32, l_pmic_buffer));
        // Release CAMP control (R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL) (1 --> Bit 3)
        l_pmic_buffer.setBit<FIELDS::R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL>();
        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmics[PMIC1], REGS::R32, l_pmic_buffer));

        // Delay 40mS
        fapi2::delay(40 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

        // Re-instate CAMP control
        FAPI_INF_NO_SBE("Re-instating CAMP control for TI PMIC " GENTARGTIDFORMAT, GENTARGTID(l_pmics[PMIC0]));
        l_current_pmic = l_pmics[PMIC0];
        FAPI_TRY(mss::pmic::i2c::reg_read_reverse_buffer(l_pmics[PMIC0], REGS::R32, l_pmic_buffer));
        // Re-instate CAMP control (R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL) (0 --> Bit 3)
        l_pmic_buffer.clearBit<FIELDS::R32_CAMP_PWR_GOOD_OUTPUT_SIGNAL_CONTROL>();
        FAPI_TRY(mss::pmic::i2c::reg_write_reverse_buffer(l_pmics[PMIC0], REGS::R32, l_pmic_buffer));

        FAPI_INF_NO_SBE("Re-instating CAMP control for TI PMIC " GENTARGTIDFORMAT, GENTARGTID(l_pmics[PMIC1]));
        l_current_pmic = l_pmics[PMIC1];
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

#ifndef __PPE__
    // Host SBE does not support 2U so we can safely ifndef this function call

    // delay after final VR enable and before checking status
    // soft start time and idle delays add up to 12 ms for 2U DDIMMs, so have this delay be > 12 ms)
    fapi2::delay(20 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // Check that all the PMIC statuses are good post-enable
    FAPI_TRY(mss::pmic::status::check_all_pmics(i_ocmb_target),
             "Bad statuses returned, or error checking statuses of PMICs on " GENTARGTIDFORMAT, GENTARGTID(i_ocmb_target));
#endif

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    // Logs the current error as prective, as it predicts that we had a PMIC enable fail
    // Deconfigures happen at the end of an istep, so this should be ok with hostboot
#ifndef __PPE__
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_PREDICTIVE);
#endif
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_ASSERT_NOEXIT(false,
                       fapi2::PMIC_ENABLE_FAIL_DDR5_2U()
                       .set_OCMB_TARGET(i_ocmb_target)
                       .set_PMIC_TARGET(l_current_pmic)
                       .set_RETURN_CODE(static_cast<uint32_t>(fapi2::current_err)),
                       "PMIC " GENTARGTIDFORMAT " failed to enable. See previous errors for details.",
                       GENTARGTID(l_current_pmic));
    return fapi2::current_err;
}
#endif

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

    FAPI_INF_NO_SBE("Enabling ADC " GENTARGTIDFORMAT, GENTARGTID(i_adc));

    static constexpr uint8_t EVENT_RGN_VALUE = 0x00;
    static constexpr uint8_t NUM_BYTES_TO_WRITE = 24;

    static const fapi2::buffer<uint8_t> l_data_system_status[NUM_BYTES_TO_WRITE] =
    {
        0x01, //  [ADC_REGS::SYSTEM_STATUS]
        0x30, //  [ADC_REGS::GENERAL_CFG]
        0x00, //  [ADC_REGS::DATA_CFG]
        0x07, //  [ADC_REGS::OSR_CFG]
        0x32, //  [ADC_REGS::OPMODE_CFG]
        0x81, //  [ADC_REGS::PIN_CFG]
        0x00, //  [ADC_REGS::DUMMY_BYTE_0]
        0x81, //  [ADC_REGS::GPIO_CFG]
        0x00, //  [ADC_REGS::DUMMY_BYTE_1]
        0x80, //  [ADC_REGS::GPO_DRIVE_CFG]
        0x00, //  [ADC_REGS::DUMMY_BYTE_2]
        0x01, //  [ADC_REGS::GPO_VALUE]
        0x00, //  [ADC_REGS::DUMMY_BYTE_3]
        0x00, //  [ADC_REGS::GPI_VALUE]
        0x00, //  [ADC_REGS::DUMMY_BYTE_4]
        0x00, //  [ADC_REGS::DUMMY_BYTE_5]
        0x11, //  [ADC_REGS::SEQUENCE_CFG]
        0x00, //  [ADC_REGS::CHANNEL_SEQ]
        0x7E, //  [ADC_REGS::AUTO_SEQ_CH_SEL]
        0x00, //  [ADC_REGS::DUMMY_BYTE_6]
        0x7E, //  [ADC_REGS::ALERT_CH_SEL]
        0x00, //  [ADC_REGS::DUMMY_BYTE_7]
        0x00, //  [ADC_REGS::ALERT_MAP]
        0x00, //  [ADC_REGS::ALERT_PIN_CFG]
    };

    static const fapi2::buffer<uint8_t> l_data_hysteresis_ch1[NUM_BYTES_TO_WRITE] =
    {
        0xF1,  //  [ADC_REGS::HYSTERESIS_CH1 - ARRAY_OFFSET]
        0xFF,  //  [ADC_REGS::HIGH_TH_CH1 - ARRAY_OFFSET]
        0xE4,  //  [ADC_REGS::EVENT_COUNT_CH1 - ARRAY_OFFSET]
        0xA5,  //  [ADC_REGS::LOW_TH_CH1 - ARRAY_OFFSET]
        0xF1,  //  [ADC_REGS::HYSTERESIS_CH2 - ARRAY_OFFSET]
        0xFF,  //  [ADC_REGS::HIGH_TH_CH2 - ARRAY_OFFSET]
        0x34,  //  [ADC_REGS::EVENT_COUNT_CH2 - ARRAY_OFFSET]
        0x8A,  //  [ADC_REGS::LOW_TH_CH2 - ARRAY_OFFSET]
        0xF1,  //  [ADC_REGS::HYSTERESIS_CH3 - ARRAY_OFFSET]
        0xFF,  //  [ADC_REGS::HIGH_TH_CH3 - ARRAY_OFFSET]
        0x24,  //  [ADC_REGS::EVENT_COUNT_CH3 - ARRAY_OFFSET]
        0x45,  //  [ADC_REGS::LOW_TH_CH3 - ARRAY_OFFSET]
        0xF1,  //  [ADC_REGS::HYSTERESIS_CH4 - ARRAY_OFFSET]
        0xFF,  //  [ADC_REGS::HIGH_TH_CH4 - ARRAY_OFFSET]
        0xF4,  //  [ADC_REGS::EVENT_COUNT_CH4 - ARRAY_OFFSET]
        0x52,  //  [ADC_REGS::LOW_TH_CH4 - ARRAY_OFFSET]
        0xF1,  //  [ADC_REGS::HYSTERESIS_CH5 - ARRAY_OFFSET]
        0xFF,  //  [ADC_REGS::HIGH_TH_CH5 - ARRAY_OFFSET]
        0xE4,  //  [ADC_REGS::EVENT_COUNT_CH5 - ARRAY_OFFSET]
        0xA5,  //  [ADC_REGS::LOW_TH_CH5 - ARRAY_OFFSET]
        0xF1,  //  [ADC_REGS::HYSTERESIS_CH6 - ARRAY_OFFSET]
        0xFF,  //  [ADC_REGS::HIGH_TH_CH6 - ARRAY_OFFSET]
        0x65,  //  [ADC_REGS::EVENT_COUNT_CH6 - ARRAY_OFFSET]
        0x65,  //  [ADC_REGS::LOW_TH_CH6 - ARRAY_OFFSET]
    };

    //ADC write
    FAPI_TRY(mss::pmic::i2c::reg_write_contiguous(i_adc, ADC_REGS::SYSTEM_STATUS, l_data_system_status));

    // ADC::EVENT_RGN reg
    FAPI_TRY(mss::pmic::i2c::reg_write(i_adc, ADC_REGS::EVENT_RGN, EVENT_RGN_VALUE));

    FAPI_TRY(mss::pmic::i2c::reg_write_contiguous(i_adc, ADC_REGS::HYSTERESIS_CH1, l_data_hysteresis_ch1));

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
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

    static constexpr uint8_t NUM_BYTES_TO_WRITE = 2;
    static const fapi2::buffer<uint8_t> l_pmic_data_to_write[NUM_BYTES_TO_WRITE] = { 0x3C, 0x60 };

    for (auto l_pmic_count = 0; l_pmic_count < CONSTS::NUM_PMICS_4U; l_pmic_count++)
    {
        // If the pmic is not overridden to disabled, run the status checking
        FAPI_TRY_NO_TRACE(mss::pmic::ddr5::run_if_present(i_target_info, l_pmic_count, [l_pmic_count, i_ocmb_target]
                          (const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic) -> fapi2::ReturnCode
        {
            uint16_t l_vendor_id = 0;

            FAPI_INF_NO_SBE("Initializing PMIC " GENTARGTIDFORMAT, GENTARGTID(i_pmic));

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
            FAPI_TRY_LAMBDA(mss::pmic::status::unlock_pmic_r70_to_ra3(i_pmic));

            // Enable internal ADC and default to temp readings
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write(i_pmic, REGS::R30, 0xD0));

            // Write to Mask status 0 & 1 regs
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write_contiguous(i_pmic, REGS::R15, l_pmic_data_to_write));

            // Set VIN_BULK PG threshold
            FAPI_TRY_LAMBDA(mss::pmic::i2c::reg_write(i_pmic, REGS::R1A, 0x60));

#ifdef __PPE__
            const static uint16_t MFG_ID[] =
            {
                fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_PMIC0_MFG_ID,
                fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_PMIC1_MFG_ID,
                fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_PMIC2_MFG_ID,
                fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_PMIC3_MFG_ID
            };
            // Get vendor ID. We just need vendor ID from 1 PMIC as both PMICs will be from the same vendor
            l_vendor_id = MFG_ID[l_relative_pmic_id];
#else
            FAPI_TRY_LAMBDA(mss::attr::get_mfg_id[l_relative_pmic_id](i_ocmb_target, l_vendor_id));
#endif

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
            return mss::pmic::declare_n_mode(i_ocmb_target, l_pmic_count);
        }));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check all the breadcrumbs
///
/// @param[in] io_target_info target info struct
/// @param[in] i_health_check_info health check struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode check_all_breadcrumbs(const target_info_redundancy_ddr5& i_target_info,
                                        const mss::pmic::ddr5::health_check_telemetry_data& i_health_check_info)
{
    uint8_t l_simics = 0;

    // Start success so we can't log and return the same error in loop logic
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMICS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_simics));

    for (auto l_dt_count = 0; l_dt_count < CONSTS::NUM_PMICS_4U; l_dt_count++)
    {
        // If the pmic is not overridden to disabled, run the status checking
        FAPI_TRY_NO_TRACE(mss::pmic::ddr5::run_if_present_dt(i_target_info, l_dt_count, [l_dt_count, &i_health_check_info,
                          &i_target_info, l_simics]
                          (const fapi2::Target<fapi2::TARGET_TYPE_POWER_IC>& i_dt) -> fapi2::ReturnCode
        {
            uint8_t l_breadcrumb = i_health_check_info.iv_dt[l_dt_count].iv_breadcrumb;

            if (l_breadcrumb == mss::pmic::ddr5::bread_crumb::STILL_A_FAIL)
            {
                // The simics check has been added here as some PMIC and DT regs are not supported in simics yets.
                // The below function is throwing error in simics as the DT and PMIC regs read from health_check()
                // are throwing errors and entering n-mode which is cauing the HWP to crash at the end.
                // This check has been skipped for now.
                // TODO: ZEN:MST-2454 Get simics support for DT, PMIC and ADC regs for health_check
                if (!l_simics)
                {
                    FAPI_ASSERT_NOEXIT(false,
                    fapi2::PMIC_ENABLE_FAIL_DDR5_4U()
                    .set_OCMB_TARGET(i_target_info.iv_ocmb)
                    .set_PMIC_TARGET(i_target_info.iv_pmic_dt_map[l_dt_count].iv_pmic)
                    .set_RETURN_CODE(static_cast<uint32_t>(fapi2::current_err)),
                    "PMIC " GENTARGTIDFORMAT " failed to enable.",
                    GENTARGTID(i_target_info.iv_pmic_dt_map[l_dt_count].iv_pmic));

                    mss::attr::set_n_mode_helper(i_target_info.iv_ocmb, l_dt_count, mss::pmic::n_mode::N_MODE);
                }
                else
                {
                    FAPI_DBG("Simulation mode detected. Skipping health_check bread_crumb check");
                }
            }

            return fapi2::FAPI2_RC_SUCCESS;
        }));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check the statuses of all PMICs present on the given OCMB chip
///
/// @param[in,out] io_target_info target info struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode inline __attribute__((always_inline)) redundancy_check_all_pmics(target_info_redundancy_ddr5&
        io_target_info)
{
    mss::pmic::ddr5::health_check_telemetry_data l_health_check_info;
    mss::pmic::ddr5::additional_n_mode_telemetry_data l_additional_info;
    mss::pmic::ddr5::periodic_telemetry_data l_periodic_telemetry_data;
    uint8_t l_number_bytes_to_send = 0;

    // Run Telemetry to reset/clear various trackers
    collect_periodic_tele_data(io_target_info, l_periodic_telemetry_data);

    // Calling health check 3 times here to ensure if any PMICs had any issue during IPL, they would be
    // attempted to recover here and would not be in n_mode if not for major issues
    // The number of bytes to send here is 0 as we are not going to send any data to HB. This is just a place holder
    FAPI_TRY(health_check_ddr5(io_target_info, l_health_check_info, l_additional_info, l_periodic_telemetry_data,
                               l_number_bytes_to_send));
    FAPI_TRY(health_check_ddr5(io_target_info, l_health_check_info, l_additional_info, l_periodic_telemetry_data,
                               l_number_bytes_to_send));
    FAPI_TRY(health_check_ddr5(io_target_info, l_health_check_info, l_additional_info, l_periodic_telemetry_data,
                               l_number_bytes_to_send));

    // Check all bread crumbs. If any PMIC has bread crumb not set to ALL_GOOD, report those errors
    FAPI_TRY(check_all_breadcrumbs(io_target_info, l_health_check_info));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Log recoverable errors for each PMIC that declared N-mode
///
/// @param[in] i_target_info Target info struct
/// @param[in] i_n_mode_pmic n-mode states for each PMIC, present or not
///
void inline __attribute__((always_inline)) log_n_modes_as_recoverable_errors_ddr5(
    const target_info_redundancy_ddr5& i_target_info,
    const mss::pmic::n_mode i_n_mode_pmic[CONSTS::NUM_PMICS_4U])
{
    for (uint8_t l_idx = PMIC0; l_idx < CONSTS::NUM_PMICS_4U; ++l_idx)
    {
        // FAPI_ASSERT_NOEXIT's behavior differs from FAPI_ASSERT:
        // NOEXIT commits the error log as soon as the FFDC execute function is called,
        // so we do not need to manually log the error, like with FAPI_ASSERT,
        // so long as we pass in the right severity as an argument
#ifndef __PPE__
        FAPI_ASSERT_NOEXIT((i_n_mode_pmic[l_idx] == mss::pmic::n_mode::N_PLUS_1_MODE),
                           fapi2::PMIC_DROPPED_INTO_N_MODE_DDR5(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                           .set_OCMB_TARGET(i_target_info.iv_ocmb)
                           .set_PMIC_ID(l_idx),
                           GENTARGTIDFORMAT " PMIC%u had errors which caused a drop into N-Mode",
                           GENTARGTID(i_target_info.iv_ocmb), l_idx);
#else
        FAPI_ASSERT_NOEXIT((i_n_mode_pmic[l_idx] == mss::pmic::n_mode::N_PLUS_1_MODE),
                           fapi2::PMIC_DROPPED_INTO_N_MODE_DDR5()
                           .set_OCMB_TARGET(i_target_info.iv_ocmb)
                           .set_PMIC_ID(l_idx),
                           GENTARGTIDFORMAT " PMIC%u had errors which caused a drop into N-Mode",
                           GENTARGTID(i_target_info.iv_ocmb), l_idx);
#endif

        // Set back to success
        if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }
    }
}

///
/// @brief Assert the resulting n-mode states with the proper error FFDC
///
/// @param[in] i_target_info target info struct
/// @param[in] i_n_mode_pmic n-mode states for each PMIC, present or not
/// @param[in] i_mnfg_thresholds thresholds policy setting
/// @return fapi2::ReturnCode iff no n-modes, else, relevant error FFDC
///
fapi2::ReturnCode inline __attribute__((always_inline)) assert_n_mode_states_ddr5(
    const target_info_redundancy_ddr5& i_target_info,
    const mss::pmic::n_mode i_n_mode_pmic[CONSTS::NUM_PMICS_4U],
    const bool i_mnfg_thresholds)
{
    // Check if we have lost a redundant pair :(
    FAPI_ASSERT(!(mss::pmic::ddr5::check::bad_two_or_more(i_n_mode_pmic)),
                fapi2::PMIC_REDUNDANCY_FAIL_DDR5()
                .set_OCMB_TARGET(i_target_info.iv_ocmb)
                .set_N_MODE_PMIC0(i_n_mode_pmic[PMIC0])
                .set_N_MODE_PMIC1(i_n_mode_pmic[PMIC1])
                .set_N_MODE_PMIC2(i_n_mode_pmic[PMIC2])
                .set_N_MODE_PMIC3(i_n_mode_pmic[PMIC3]),
#ifndef __PPE__
                "Two or more PMICs have declared N-Mode. Procedure will not be able "
                "to turn on and provide power to the OCMB " GENTARGTIDFORMAT " N-Mode States:"
                "PMIC0: %u PMIC1: %u PMIC2: %u PMIC3: %u",
                GENTARGTID(i_target_info.iv_ocmb),
                i_n_mode_pmic[PMIC0], i_n_mode_pmic[PMIC1], i_n_mode_pmic[PMIC2], i_n_mode_pmic[PMIC3]);
#else
                "Two or more PMICs have declared N-Mode. Procedure will not be able "
                "to turn on and provide power to the OCMB. N-Mode States:"
                "PMIC0: %u PMIC1: %u PMIC2: %u PMIC3: %u",
                i_n_mode_pmic[PMIC0], i_n_mode_pmic[PMIC1], i_n_mode_pmic[PMIC2], i_n_mode_pmic[PMIC3]);
#endif

    // Now in the other case, if at least one is down, assert this error. However, depending on the
    // thresholds policy setting, in most cases this error will be logged as recoverable in the
    // fapi_try_exit of process_n_mode_results(...)
    FAPI_ASSERT(!(mss::pmic::ddr5::check::bad_any(i_n_mode_pmic)),
                fapi2::DIMM_RUNNING_IN_N_MODE_DDR5()
                .set_OCMB_TARGET(i_target_info.iv_ocmb)
                .set_N_MODE_PMIC0(i_n_mode_pmic[PMIC0])
                .set_N_MODE_PMIC1(i_n_mode_pmic[PMIC1])
                .set_N_MODE_PMIC2(i_n_mode_pmic[PMIC2])
                .set_N_MODE_PMIC3(i_n_mode_pmic[PMIC3]),
#ifndef __PPE__
                GENTARGTIDFORMAT " Warning: At least one of the 4 PMICs had errors which caused a drop into N-Mode. "
                "MNFG_THRESHOLDS has asserted that we %s. N-Mode States:"
                "PMIC0: %u PMIC1: %u PMIC2: %u PMIC3: %u",
                GENTARGTID(i_target_info.iv_ocmb),
                (i_mnfg_thresholds) ? "EXIT." : "DO NOT EXIT. Continuing boot normally with redundant parts.",
                i_n_mode_pmic[PMIC0], i_n_mode_pmic[PMIC1], i_n_mode_pmic[PMIC2], i_n_mode_pmic[PMIC3]);
#else
                "Warning: At least one of the 4 PMICs had errors which caused a drop into N-Mode. "
                "PMIC0: %u PMIC1: %u PMIC2: %u PMIC3: %u",
                i_n_mode_pmic[PMIC0], i_n_mode_pmic[PMIC1], i_n_mode_pmic[PMIC2], i_n_mode_pmic[PMIC3]);
#endif

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Process the results of the N-Mode declarations (if any)
///
/// @param[in] i_target_info OCMB, PMIC and I2C target struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, or error code based on the
///                           n mode results
/// @note Logs a recoverable error per bad PMIC to aid FW, but will return good/bad code
///       whether we are able to continue or not given those states
///
fapi2::ReturnCode process_n_mode_results(const target_info_redundancy_ddr5& i_target_info)
{
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    using mss::pmic::id;

    // Hold N-Mode states
    mss::pmic::n_mode l_n_mode_pmic[CONSTS::NUM_PMICS_4U] =
    {
        mss::pmic::n_mode::N_PLUS_1_MODE,
        mss::pmic::n_mode::N_PLUS_1_MODE,
        mss::pmic::n_mode::N_PLUS_1_MODE,
        mss::pmic::n_mode::N_PLUS_1_MODE,
    };

    // Force an n-mode configuration via lab override
    uint8_t l_force_n_mode = 0;
    fapi2::buffer<uint8_t> l_force_n_mode_buffer;

    // MFG flags vars/consts
    bool l_mnfg_thresholds = false;

    // Grab N mode attributes
    FAPI_TRY(mss::attr::get_n_mode_helper(i_target_info.iv_ocmb, PMIC0, l_n_mode_pmic[PMIC0]));
    FAPI_TRY(mss::attr::get_n_mode_helper(i_target_info.iv_ocmb, PMIC1, l_n_mode_pmic[PMIC1]));
    FAPI_TRY(mss::attr::get_n_mode_helper(i_target_info.iv_ocmb, PMIC2, l_n_mode_pmic[PMIC2]));
    FAPI_TRY(mss::attr::get_n_mode_helper(i_target_info.iv_ocmb, PMIC3, l_n_mode_pmic[PMIC3]));

#ifdef __PPE__
    l_force_n_mode = fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_PMIC_FORCE_N_MODE;
#else
    // Overridden to an N mode configuration
    FAPI_TRY(mss::attr::get_pmic_force_n_mode(i_target_info.iv_ocmb, l_force_n_mode));
#endif
    l_force_n_mode_buffer = l_force_n_mode;

    // Check N-mode override attribute states
    for (uint8_t l_idx = PMIC0; l_idx < CONSTS::NUM_PMICS_4U; ++l_idx)
    {
        // l_force_n_mode_buffer is expected to have an "n-mode configuration" as high bits.
        // in other words, a setting such as 0b11110000 would say to use the n-mode configuration of
        // PMIC0, PMIC1, PMIC2 and PMIC3. Therefore, if bits are not set, we are considering those overridden
        // to be disabled. (Default value is 0xF0). (This logic is not the same as the live n-mode states)
        if (!l_force_n_mode_buffer.getBit(l_idx))
        {
            // Hardcode it to N-Mode, since this pmic is disabled or not-present.
            l_n_mode_pmic[l_idx] = mss::pmic::n_mode::N_MODE;
        }
    }

    // First, we want to log a recoverable error for each PMIC that is in an N-mode state.
    // This helps FW identify which parts are bad if we do have a full redundancy fail which
    // causes a procedure exit. No RC from this function.
    log_n_modes_as_recoverable_errors_ddr5(i_target_info, l_n_mode_pmic);

    // Easy case first, return success if they're all N_PLUS1_MODE (not N-mode)
    if (!l_n_mode_pmic[PMIC0] &&
        !l_n_mode_pmic[PMIC1] &&
        !l_n_mode_pmic[PMIC2] &&
        !l_n_mode_pmic[PMIC3])
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Get mnfg thresholds policy setting
    FAPI_TRY(mss::pmic::get_mnfg_thresholds(l_mnfg_thresholds));

    // If we have any n-modes, we will jump to fapi_try_exit
    FAPI_TRY(assert_n_mode_states_ddr5(i_target_info, l_n_mode_pmic, l_mnfg_thresholds));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    // If we are allowing redundancy, log the N_MODE error as recovered
    if (fapi2::current_err == static_cast<uint32_t>(fapi2::RC_DIMM_RUNNING_IN_N_MODE_DDR5)
        && !l_mnfg_thresholds)
    {
#ifndef __PPE__
        fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
#endif
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

    return fapi2::current_err;
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
    FAPI_INF_NO_SBE("Enabling PMICs on " GENTARGTIDFORMAT " with 4U/redundancy mode", GENTARGTID(i_ocmb_target));

    fapi2::buffer<uint8_t> l_reg_contents;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    static constexpr uint8_t PMIC0 = 0;

    // Grab the targets as a struct, if they exist
    target_info_redundancy_ddr5 l_target_info(i_ocmb_target, l_rc);

    // If platform did not provide a usable set of targets (1 GENERIC_I2C_DEV, at least 3 PMICs and 3 DTs),
    // Then we can't properly enable
    FAPI_TRY(l_rc, "Unusable PMIC/POWER_IC/GENERIC_I2C_DEV child target configuration found from "
             GENTARGTIDFORMAT, GENTARGTID(i_ocmb_target));

    // Reset N Mode attributes
    FAPI_TRY(mss::pmic::check::reset_n_mode_attrs(i_ocmb_target));

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
    FAPI_TRY(mss::pmic::ddr5::prepost_config(l_target_info, PRE_CONFIG, CONSTS::ENABLE));

    // Update dynamic VDD Overvoltage Threshold
    FAPI_TRY(update_vdd_ov_threshold(l_target_info, mss::pmic::id::PMIC0));

    // 3b, Enable PMIC
    FAPI_TRY(mss::pmic::ddr5::enable_disable_pmic(l_target_info.iv_adc, CONSTS::SET_PMIC_EN));

    // Delay for 60 ms
    fapi2::delay(60 * mss::common_timings::DELAY_1MS, mss::common_timings::DELAY_1MS);

    // 3c, Post config PMIC for VR_ENABLE
    FAPI_INF_NO_SBE("Enable PMIC using ADC " GENTARGTIDFORMAT, GENTARGTID(l_target_info.iv_adc));
    FAPI_TRY(mss::pmic::ddr5::prepost_config(l_target_info, POST_CONFIG, CONSTS::ENABLE));

    // Fourth, Clear ADC events
    FAPI_TRY(mss::pmic::ddr5::clear_adc_events(l_target_info.iv_adc));

    // Fifth, verification
    // Now, check that the PMICs were enabled properly. If any don't report on that are expected
    // to be on, declare N-mode there.
    FAPI_TRY(mss::pmic::ddr5::redundancy_check_all_pmics(l_target_info));

    // Finally, process the N-Mode results
    FAPI_TRY(mss::pmic::ddr5::process_n_mode_results(l_target_info));

    FAPI_INF_NO_SBE("Successfully enabled PMICs on" GENTARGTIDFORMAT " with 4U/redundancy mode", GENTARGTID(i_ocmb_target));

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
        FAPI_INF_NO_SBE("No PMICs to enable on " GENTARGTIDFORMAT ", exiting.", GENTARGTID(i_ocmb_target));
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
#ifndef __PPE__
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_MODULE_HEIGHT, i_ocmb_target, l_module_height));
#else
        l_module_height = fapi2::ATTR::TARGET_TYPE_OCMB_CHIP::ATTR_MEM_EFF_DRAM_MODULE_HEIGHT;
#endif

        // Kick off the matching enable procedure
        if (l_module_height == fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U)
        {
            FAPI_INF_NO_SBE("Enabling PMICs on " GENTARGTIDFORMAT "with Redundancy/4U Mode", GENTARGTID(i_ocmb_target));
            FAPI_TRY(mss::pmic::ddr5::enable_with_redundancy(i_ocmb_target));
        }

#ifndef __PPE__
        else
        {
            FAPI_INF_NO_SBE("Enabling PMICs on " GENTARGTIDFORMAT "with 2U Mode", GENTARGTID(i_ocmb_target));
            FAPI_TRY(mss::pmic::ddr5::enable_2u(i_ocmb_target, i_mode));
        }

#endif
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

namespace check
{
///
/// @brief Check if at least one PMIC has declared N mode
///
/// @param[in] i_n_mode_pmic n-mode states of the 4 PMICs
/// @return true/false at least one pmic is bad
///
bool bad_any(const mss::pmic::n_mode i_n_mode_pmic[CONSTS::NUM_PMICS_4U])
{
    // For readability
    static constexpr mss::pmic::n_mode N_MODE = mss::pmic::n_mode::N_MODE;
    // True if any are N_MODE
    return i_n_mode_pmic[0] == N_MODE ||
           i_n_mode_pmic[1] == N_MODE ||
           i_n_mode_pmic[2] == N_MODE ||
           i_n_mode_pmic[3] == N_MODE;
}
///
/// @brief Check if two or more PMIC has declared N mode
///
/// @param[in] i_n_mode_pmic n-mode states of the 4 PMICs
/// @return true/false if two or more pmics are bad
///
bool bad_two_or_more(const mss::pmic::n_mode i_n_mode_pmic[CONSTS::NUM_PMICS_4U])
{
    // For readability
    static constexpr mss::pmic::n_mode N_MODE = mss::pmic::n_mode::N_MODE;
    static constexpr uint8_t NUMBER_PMICS_FAIL_NOT_ACCEPTABLE = 2;
    using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;
    uint8_t l_number_pmic_n_mode = 0;

    for (auto l_count = 0; l_count < CONSTS::NUM_PMICS_4U; l_count++)
    {
        if(i_n_mode_pmic[l_count] == N_MODE)
        {
            l_number_pmic_n_mode++;
        }
    }

    return (l_number_pmic_n_mode >= NUMBER_PMICS_FAIL_NOT_ACCEPTABLE);
}
} // ns check

} // ns ddr5
} // ns pmic
} // ns mss
