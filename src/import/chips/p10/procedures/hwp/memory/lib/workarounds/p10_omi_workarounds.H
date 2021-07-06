/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/workarounds/p10_omi_workarounds.H $ */
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
/// @file p10_omi_workarounds.H
/// @brief Workarounds for p10_omi_* procedures
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#ifndef _P10_OMI_WORKAROUNDS_H_
#define _P10_OMI_WORKAROUNDS_H_

#include <fapi2.H>

namespace mss
{
namespace workarounds
{
namespace omi
{
///
/// @brief Helper function to determine whether PRBS OMI workaround will be performed, that can be unit tested
///
/// @param[in] i_ocmb_type OCMB type/name
/// @param[in] i_proc_type PROC type/name
/// @return true/false perform workaround
///
bool is_gemini_apollo_prbs_required(const uint8_t i_ocmb_type, const uint8_t i_proc_type);

///
/// @brief Helper function to determine whether p10-specific PRBS workaround is required
///
/// @param[in] i_ocmb_type OCMB type/name
/// @param[in] i_proc_type PROC type/name
/// @return true/false perform workaround
///
bool is_p10_prbs_required(const uint8_t i_ocmb_type, const uint8_t i_proc_type);

///
/// @brief Perform PRBS delay from prbs time and sim attributes
///
/// @param[in] i_omi OMI target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode prbs_delay(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi);

///
/// @brief Get PROC and OCMB types
///
/// @param[in] i_ocmb_chip OCMB chip
/// @param[in] i_proc_chip PROC chip
/// @param[out] o_ocmb_type OCMB type ATTR_NAME enum
/// @param[out] o_proc_type PROC type ATTR_NAME enum
/// @return FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode get_ocmb_proc_types(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_chip,
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_chip,
    uint8_t& o_ocmb_type,
    uint8_t& o_proc_type);

///
/// @brief Perform the PRBS OMI workaround for gemini configurations
///
/// @param[in] i_omi OMI
/// @param[in] i_dl_x4_backoff_en backoff enable bit
/// @return fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode training_prbs_gem(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
    const uint8_t i_dl_x4_backoff_en);

///
/// @brief Perform p10_omi_train workaround for P10+Explorer
///
/// @param[in] i_omi OMI target
/// @param[in] i_dl_x4_backoff_en backoff enable field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode training_prbs(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi,
    const uint8_t i_dl_x4_backoff_en);

///
/// @brief Perform p10_omi_setup (pre-training) workaround for P10+Explorer
///
/// @param[in] i_target OMI target
/// @param[in] i_dl_x4_backoff_en backoff enable field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode pre_training_prbs(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
    const uint8_t i_dl_x4_backoff_en);

///
/// @brief Override OMI recal timer to DD1 setting
/// @param[in] i_target the TARGET_TYPE_OMIC to operate on
/// @param[in] i_override_needed value from EC attribute
/// @param[in,out] io_data CMN_CONFIG register data
///
void override_recal_timer(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
    const bool i_override_needed,
    fapi2::buffer<uint64_t>& io_data);

} // namespace omi
} // namespace workarounds
} // namespace mss

#endif
