/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/lib/utils/pmic_enable_utils_ddr5.H $ */
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
/// @file pmic_enable_utils_ddr5.H
/// @brief Utility functions for PMIC enable operation
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#ifndef __PMIC_ENABLE_UTILS_DDR5_H__
#define __PMIC_ENABLE_UTILS_DDR5_H__

#include <fapi2.H>
#include <pmic_regs.H>
#include <pmic_regs_fld.H>
#include <pmic_enable_utils.H>
#include <lib/utils/pmic_common_utils_ddr5.H>
#include <pmic_common_utils.H>
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
/// @brief Pre config PMIC for power down or pmic enable.
///        Enable/disable power off seq, enable/disable soft-stop, on-off config global
///
/// @param[in] i_target_info target info struct
/// @param[in] i_value_comp_config bool value to be written to the comp_config register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230216 version 0.06"
///       document provided by the Power team
///
fapi2::ReturnCode pre_config(const target_info_redundancy_ddr5& i_target_info,
                             const bool i_value_comp_config);

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
fapi2::ReturnCode enable_disable_pmic(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc,
                                      const uint8_t i_value);

///
/// @brief PMIC post-config. Set/Clear VR_ENABLE, write on_off_config_global reg
///
/// @param[in] i_target_info target info struct
/// @param[in] i_value to be written to PMIC R32 reg
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note The below values of DT regs are taken from the
///       "Redundant PoD5 - Functional Specification dated 20230216 version 0.06"
///       document provided by the Power team
///
fapi2::ReturnCode post_config(const mss::pmic::ddr5::target_info_redundancy_ddr5& i_target_info,
                              const uint8_t i_value);
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
fapi2::ReturnCode pmic_power_down(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Disable PMICs and clear status bits in preparation for enable
///
/// @param[in] i_ocmb_target OCMB parent target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode disable_and_reset_pmics(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_target);

///
/// @brief Enable PMIC for 2U
///
/// @param[in] i_ocmb_target OCMB target parent of PMICs
/// @param[in] i_mode manual/SPD enable mode
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note There is no 1U support for DDR5
///
// TODO: ZEN:MST-1890 Implement pmic_enable() for 2U
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
fapi2::ReturnCode clear_adc_events(const fapi2::Target<fapi2::TARGET_TYPE_GENERICI2CRESPONDER>& i_adc);

///
/// @brief Verify if the pmics have been enabled properly and if not create a unique case of breadcrumbs
///
/// @param[in] i_target_info target info struct
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
// TODO: ZEN:MST-1905 Implement health check
fapi2::ReturnCode redundancy_check_all_pmics(const mss::pmic::ddr5::target_info_redundancy_ddr5& i_target_info);

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
} // ns ddr5
} // ns pmic
} // ns mss

#endif
