/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_omi_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file exp_omi_workarounds.H
/// @brief Workarounds for exp_omi_* procedures
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#ifndef _EXP_OMI_WORKAROUNDS_H_
#define _EXP_OMI_WORKAROUNDS_H_

#include <fapi2.H>

namespace mss
{
namespace exp
{
namespace workarounds
{
namespace omi
{

///
/// @brief Determine if the OCMB is an explorer
///
/// @param[in] i_ocmb_chip OCMB chip
/// @param[out] o_explorer true/false is explorer
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
/// @note Used for exp_omi_train procedure to differentiate fw_status behavior with gemini
///
fapi2::ReturnCode ocmb_is_explorer(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_chip, bool& o_explorer);

///
/// @brief Set configurable delay based on the PRBS ATTR and SIM mode
///
/// @param[in] i_ocmb_chip OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode prbs_delay(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_chip);

///
/// @brief Determine if we need to bypass MENTERP register reads/writes
///
/// @param[in] i_target OCMB chip
/// @param[out] o_workaround true (1) for gemini, else false (0)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode gem_menterp(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_target,
                              uint8_t& o_workaround);

/// @brief Determine if / perform the gemini workaround to setup the OMI config registers
///
/// @param[in] i_target OCMB (gemini)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
///
fapi2::ReturnCode gem_setup_config(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Workaround for exp_omi_train to perform dlx_config0 setup
///
/// @param[in] i_target OCMB chip
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode training_prbs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Workaround for exp_omi_setup to perform dlx_config0 setup
///
/// @param[in] i_target OCMB chip
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode pre_training_prbs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Workaround for exp_omi-setup to set explorer cdr bw value
/// @param[in] i_target OCMB chip
/// @param[in] i_omi_freq OMI operating frequency
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode cdr_bw_override(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  uint32_t i_omi_freq);


///
/// @brief Override CDR bandwidth setting via I2C command
///
/// @param[in] i_cdr_bw_override setting from ATTR_OMI_CDR_BW_OVERRIDE
/// @param[in,out] io_data i2c data to send
///
void setup_cdr_bw_i2c(const uint8_t i_cdr_bw_override,
                      std::vector<uint8_t>& io_data);

///
/// @brief Override CDR bandwidth setting via I2C command
///
/// @param[in] i_target OCMB_CHIP target
/// @param[in] i_cdr_bw_override setting from ATTR_OMI_CDR_BW_OVERRIDE
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode override_cdr_bw_i2c(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint8_t i_cdr_bw_override);

///
/// @brief Override CDR offset setting via I2C command
///
/// @param[in] i_cdr_offset setting from ATTR_MSS_EXP_OMI_CDR_OFFSET
/// @param[in] i_cdr_offset_lane_mask setting from ATTR_MSS_EXP_OMI_CDR_OFFSET_LANE_MASK
/// @param[in,out] io_data i2c data to send
///
void setup_cdr_offset_i2c(const uint8_t i_cdr_offset,
                          const uint8_t i_cdr_offset_lane_mask,
                          std::vector<uint8_t>& io_data);

///
/// @brief Override CDR offset setting via I2C command
///
/// @param[in] i_target OCMB_CHIP target
/// @param[in] i_cdr_offset setting from ATTR_MSS_EXP_OMI_CDR_OFFSET
/// @param[in] i_cdr_offset_lane_mask setting from ATTR_MSS_EXP_OMI_CDR_OFFSET_LANE_MASK
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode override_cdr_offset(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint8_t i_cdr_offset,
    const uint8_t i_cdr_offset_lane_mask);

///
/// @brief Select and set dl_layer_boot_mode for BOOT_CONFIG0
///
/// @param[in] i_target OCMB_CHIP target
/// @param[in] i_is_apollo value of ATTR_IS_APOLLO
/// @param[in,out] io_boot_config_data BOOT_CONFIG0 data
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode select_dl_layer_boot_mode(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint8_t i_is_apollo,
    std::vector<uint8_t>& io_boot_config_data);

} // omi
} // workarounds
} // exp
} // mss

#endif
