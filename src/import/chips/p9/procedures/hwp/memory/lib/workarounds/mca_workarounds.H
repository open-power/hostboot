/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/mca_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file workarounds/mca_workarounds.H
/// @brief Workarounds for the MCA logic blocks
/// Workarounds are very deivce specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_WORKAROUNDS_MCA_H_
#define _MSS_WORKAROUNDS_MCA_H_

#include <fapi2.H>

namespace mss
{

namespace workarounds
{

///
/// @brief Checks whether the workaround needs to be run for non-TSV parts
/// @param[in] const ref to the target
/// @param[in] i_power_control - MRW power control
/// @param[in] i_idle_power_control - MRW idle power control value
/// @return bool true iff we're on a Nimbus >= EC 2.0, non-TSV, and self-time-refresh
///
bool check_str_non_tsv_parity_workaround(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_power_control,
        const uint64_t i_idle_power_control);

///
/// @brief Blindly disables the CID parity
/// @param[in] i_target The MCA target on which to run
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode disable_cid_parity(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief Disables CID parity on non-TSV, DD2 parts that run self-time refresh
/// @param[in] i_target The MCA target on which to run
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode str_non_tsv_parity(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

} // ns workarounds

} // ns mss

#endif
