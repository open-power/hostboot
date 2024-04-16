/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_enable_utils_ddr5.H $ */
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
/// @file pmic_enable_utils_ddr5.H
/// @brief Utility functions for PMIC enable operation
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#ifndef __PMIC_ENABLE_UTILS_DDR5_H__
#define __PMIC_ENABLE_UTILS_DDR5_H__

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <pmic_common_utils.H>
#include <lib/utils/pmic_common_utils_ddr5.H>
#include <pmic_consts.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <mss_pmic_attribute_accessors_manual.H>

namespace mss
{

namespace pmic
{

namespace ddr5
{
using CONSTS = mss::pmic::consts<mss::pmic::product::JEDEC_COMPLIANT>;

static constexpr uint8_t PRE_CONFIG = true;
static constexpr uint8_t POST_CONFIG = false;

///
/// @brief Updates VDD domain during dt enable sequence
/// @param[in] i_target_info target info struct
/// @param[in] i_pmic_id PMIC being addressed in sorted array
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode inline __attribute__((always_inline)) update_vdd_ov_threshold(const target_info_redundancy_ddr5&
        i_target_info,
        const uint8_t i_pmic_id);

///
/// @brief Setup and enable DT
///
/// @param[in] i_target_info target info struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230216 version 0.06"
///       document provided by the Power team
///
fapi2::ReturnCode setup_dt(const target_info_redundancy_ddr5& i_target_info);

///
/// @brief PMIC power down sequence for 2U parts
///
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note There is no support for 1U in DDR5
///
// TODO: ZEN:MST-1890 Implement pmic_enable() for 2U
fapi2::ReturnCode power_down_sequence_2u(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

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
                                 const bool i_value);

///
/// @brief Enable/disable PMIC
///
/// @param[in] i_adc ADC target
/// @param[in] i_value to be written to GPO_VALUE ADC reg
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230216 version 0.06"
///       document provided by the Power team
///
fapi2::ReturnCode inline __attribute__((always_inline)) enable_disable_pmic(const
        fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc,
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
/// @brief PMIC power down sequence for 4U parts
///
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode power_down_sequence_4u(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Power down function for 4U pmics
/// @param[in] i_target ocmb target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode inline __attribute__((always_inline)) pmic_power_down(const
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Disable PMICs and clear status bits in preparation for enable
///
/// @param[in] i_ocmb_target OCMB parent target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode disable_and_reset_pmics(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_target);

///
/// @brief Checks if the rev number matches the attr rev number
///
/// @param[in]  i_ocmb_target OCMB target
/// @param[in]  i_pmic_target PMIC target to check
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode validate_pmic_revisions(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
        const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target);

///
/// @brief Helper function to do fapi assert for checking between attr and reg
///
/// @param[in]  i_pmic_target PMIC target to check
/// @param[in]  i_rev_attr attribute value of the revision
/// @param[in]  i_rev_reg register value of the revision
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff no error
///
fapi2::ReturnCode inline __attribute__((always_inline)) validate_pmic_revisions_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_PMIC>& i_pmic_target,
    const uint8_t i_rev_attr,
    const uint8_t i_rev_reg)
{
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_pmic_target);

    FAPI_INF_NO_SBE("PMIC i_rev_attr: 0x%02X, PMIC i_rev_reg: 0x%02X " GENTARGTIDFORMAT, i_rev_attr, i_rev_reg,
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
/// @note There is no 1U support for DDR5
///
fapi2::ReturnCode enable_2u(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
    const mss::pmic::enable_mode i_mode);

///
/// @brief Setup ADC
///
/// @param[in] i_adc ADC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230216 version 0.06"
///       document provided by the Power team
///
fapi2::ReturnCode setup_adc(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc);

///
/// @brief Setup and initialize PMIC
///
/// @param[in] i_ocmb_target OCMB target
/// @param[in] i_target_info target info struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230216 version 0.06"
///       document provided by the Power team
///
fapi2::ReturnCode initialize_pmic(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
                                  const mss::pmic::ddr5::target_info_redundancy_ddr5& i_target_info);

///
/// @brief Clear ADC events that previously occurred. If not then ALERT will immediately assert.
///
/// @param[in] i_adc ARC target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230216 version 0.06"
///       document provided by the Power team
///
fapi2::ReturnCode inline __attribute__((always_inline)) clear_adc_events(const
        fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc)
{
    using ADC_REGS = mss::adc::regs;

    fapi2::buffer<uint8_t> l_reg_contents;

    FAPI_INF_NO_SBE("Clearing previous ADC events port pmic_enable() " GENTARGTIDFORMAT, GENTARGTID(i_adc));

    FAPI_TRY(mss::pmic::i2c::reg_write(i_adc, ADC_REGS::LOW_EVENT_FLAGS, 0xFF));

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
                                        const mss::pmic::ddr5::health_check_telemetry_data& i_health_check_info);

///
/// @brief Check the statuses of all PMICs present on the given OCMB chip
///
/// @param[in,out] io_target_info target info struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode inline __attribute__((always_inline)) redundancy_check_all_pmics(target_info_redundancy_ddr5&
        io_target_info);

///
/// @brief Log recoverable errors for each PMIC that declared N-mode
///
/// @param[in] i_target_info Target info struct
/// @param[in] i_n_mode_pmic n-mode states for each PMIC, present or not
///
void inline __attribute__((always_inline)) log_n_modes_as_recoverable_errors_ddr5(
    const target_info_redundancy_ddr5& i_target_info,
    const mss::pmic::n_mode i_n_mode_pmic[CONSTS::NUM_PMICS_4U]);

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
    const bool i_mnfg_thresholds);

///
/// @brief Process the results of the N-Mode declarations (if any)
///
/// @param[in] i_target_info OCMB, PMIC and I2C target struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, or error code based on the
///                           n mode results
/// @note Logs a recoverable error per bad PMIC to aid FW, but will return good/bad code
///       whether we are able to continue or not given those states
///
fapi2::ReturnCode process_n_mode_results(const target_info_redundancy_ddr5& i_target_info);

///
/// @brief Set the up DTs, ADCs, PMICs for a redundancy configuration / 4U
///
/// @param[in] i_ocmb_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230216 version 0.06"
///       document provided by the Power team
///
fapi2::ReturnCode enable_with_redundancy(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target);

///
/// @brief enable function for pmic module
/// @param[in] i_target ocmb target
/// @param[in] i_mode enable mode operation
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode pmic_enable(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                              const mss::pmic::enable_mode i_mode = mss::pmic::enable_mode::SPD);

namespace check
{
///
/// @brief Check if at least one PMIC has declared N mode
///
/// @param[in] i_n_mode_pmic n-mode states of the 4 PMICs
/// @return true/false at least one pmic is bad
///
bool bad_any(const mss::pmic::n_mode i_n_mode_pmic[CONSTS::NUM_PMICS_4U]);

///
/// @brief Check if two or more PMIC has declared N mode
///
/// @param[in] i_n_mode_pmic n-mode states of the 4 PMICs
/// @return true/false if two or more pmics are bad
///
bool bad_two_or_more(const mss::pmic::n_mode i_n_mode_pmic[CONSTS::NUM_PMICS_4U]);

} // ns check
} // ns ddr5
} // ns pmic
} // ns mss

#endif
