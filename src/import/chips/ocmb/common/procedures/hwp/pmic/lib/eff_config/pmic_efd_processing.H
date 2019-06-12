/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/lib/eff_config/pmic_efd_processing.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file pmic_efd_processing.H
/// @brief Processing for EFD for eff config
///

// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI

#ifndef _MSS_PMIC_EFD_PROCESSING_H_
#define _MSS_PMIC_EFD_PROCESSING_H_

#include <fapi2.H>
#include <generic/memory/lib/data_engine/data_engine_traits_def.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <generic/memory/lib/spd/spd_facade.H>

namespace mss
{
namespace pmic
{

///
/// @brief Convert unsigned offset from SPD to signed offset for attributes
///
/// @param[in] i_offset - unsigned offset
/// @param[in] i_direction - direction
/// @return int8_t signed equivalent
/// @note Should be used with SPD data where the offset is 7 bits such that overflow could not be possible
///
int8_t convert_to_signed_offset(const uint8_t i_offset, const uint8_t i_direction);

namespace efd
{

///
/// @brief Processes the EFD PMIC0 SWA Voltage Offset & Direction
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic0_swa_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Processes the EFD PMIC0 SWB Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic0_swb_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Processes the EFD PMIC0 SWC Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic0_swc_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Processes the EFD PMIC0 SWD Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic0_swd_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Processes the EFD PMIC1 SWA Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic1_swa_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Processes the EFD PMIC1 SWB Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic1_swb_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Processes the EFD PMIC1 SWC Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic1_swc_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Processes the EFD PMIC1 SWD Voltage Offset
/// @param[in] i_target the target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode pmic1_swd_voltage_offset(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

///
/// @brief Process the EFD data and set attributes
/// @param[in] i_target DIMM target on which to operate
/// @param[in] i_efd_data the EFD data to process
/// @return fapi2::FAPI2_RC_SUCCESS iff function completes successfully
///
fapi2::ReturnCode process(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const std::shared_ptr<mss::efd::base_decoder>& i_efd_data);

} // ns efd
} // ns exp
} // ns mss
#endif
