/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/workarounds/p9a_omi_workarounds.H $ */
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
/// @file p9a_omi_workarounds.H
/// @brief Workarounds for p9a_omi_* procedures
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#ifndef P9A_OMI_WORKAROUNDS_H_
#define P9A_OMI_WORKAROUNDS_H_

#include <fapi2.H>

namespace mss
{
namespace workarounds
{
namespace mc
{
///
/// @brief Helper function to determine whether PRBS OMI workaround will be performed, that can be unit tested
///
/// @param[in] i_ocmb_type OCMB type/name
/// @param[in] i_proc_type PROC type/name
/// @return true/false perform workaround
///
bool is_prbs_omi_required(const uint8_t i_ocmb_type, const uint8_t i_proc_type);

///
/// @brief Helper function to determine whether PRBS axone OMI workarounds will be performed, that can be unit tested
///
/// @param[in] i_ocmb_type OCMB type/name
/// @param[in] i_proc_type PROC type/name
/// @return true/false perform workaround
///
bool is_prbs_omi_axone_required(const uint8_t i_ocmb_type, const uint8_t i_proc_type);

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
/// @param[out] o_required workaround required
/// @return FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode get_ocmb_proc_types(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_chip,
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_proc_chip,
    uint8_t& o_ocmb_type,
    uint8_t& o_proc_type);

///
/// @brief Perform the PRBS OMI workaround for gemini configurations
///
/// @param[in] i_omi OMI
/// @param[in] i_dl_x4_backoff_en backoff enable bit
/// @return fapi2::FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode omi_training_prbs_gem(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI> i_omi,
    const uint8_t i_dl_x4_backoff_en);

///
/// @brief Perform p9a_omi_train workaround for Axone+Explorer
///
/// @param[in] i_omi OMI target
/// @param[in] i_dl_x4_backoff_en backoff enable field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode omi_training_prbs(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI> i_omi,
    const uint8_t i_dl_x4_backoff_en);

///
/// @brief Perform p9a_omi_setup (pre-training) workaround for Axone+Explorer
///
/// @param[in] i_omi OMI target
/// @param[in] i_dl_x4_backoff_en backoff enable field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode pre_omi_training_prbs(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI> i_omi,
    const uint8_t i_dl_x4_backoff_en);

} // namespace mc
} // namespace workarounds
} // namespace mss

#endif
