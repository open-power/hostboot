/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_omi_workarounds.H $ */
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
/// @brief Determine if OCMB PRBS workaround needs to be performed
///
/// @param[in] i_ocmb_chip OCMB target
/// @param[out] o_required workaround needs to be performed
/// @return FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode is_prbs_ocmb_required(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_chip,
    bool& o_required);

///
/// @brief Performs OCMB PRBS workaround
///
/// @param[in] i_ocmb_chip OCMB chip
/// @param[in] i_dl_x4_backoff_en backoff enable
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode prbs_ocmb(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_ocmb_chip,
    const uint8_t i_dl_x4_backoff_en);

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

} // omi
} // workarounds
} // exp
} // mss

#endif
