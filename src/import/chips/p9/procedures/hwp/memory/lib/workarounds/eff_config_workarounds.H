/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/eff_config_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file eff_config_workarounds.H
/// @brief Workarounds for effective config
/// Workarounds are very device specific, so there is no attempt to generalize
/// this code in any way.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _EFF_CONFIG_WORKAROUNDS_H_
#define _EFF_CONFIG_WORKAROUNDS_H_

#include <fapi2.H>
#include <lib/shared/nimbus_defaults.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <lib/dimm/nimbus_kind.H>

namespace mss
{

namespace workarounds
{

namespace eff_config
{

///
/// @brief Checks if the NVDIMM RC drive strength workaround is needed
/// @param[in] i_target DIMM target on which to operate
/// @param[out] o_is_needed true if the workaround is needed
/// @return SUCCESS if the code executes successfully
///
fapi2::ReturnCode is_nvdimm_rc_drive_strength_needed(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool& o_is_needed);

///
/// @brief Updates the RC drive strength if the workaround is needed
/// @param[in] i_target DIMM target on which to operate
/// @param[in] i_override_value the value to override if the workaround needs to be applied
/// @param[in,out] io_rc_value Register Control word value to update
/// @return SUCCESS if the code executes successfully
///
fapi2::ReturnCode nvdimm_rc_drive_strength(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_override_value,
        fapi2::buffer<uint8_t>& io_rc_value);

///
/// @brief Updates timing attributes to be synchronized allowing the parts to be broadcast capable
/// @param[in] i_target MCS target on which to operate
/// @return SUCCESS if the code executes successfully
/// @note synchronizes attributes across the whole MCBIST
///
fapi2::ReturnCode synchronize_broadcast_timings(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target);

///
/// @brief Checks if the 128GB WLO workaround is required
/// @param[in] i_kinds vector of DIMM kinds on which to operate
/// @return true if the workaround is needed, otherwise false
///
bool is_128gb_workaround_needed(const std::vector<mss::dimm::kind<>>& i_kinds);

///
/// @brief Updates the WLO if the 128GB workaround is required
/// @param[in] i_kinds vector of DIMM kinds on which to operate
/// @param[in,out] io_wlo the WLO value to be updated
///
void update_128gb_wlo_if_needed(const std::vector<mss::dimm::kind<>>& i_kinds,
                                uint8_t& io_wlo);

///
/// @brief Updates the VREFDQ if the 128GB workaround is required
/// @param[in] i_kinds vector of DIMM kinds on which to operate
/// @param[in,out] io_vrefdq_train the WR VREF values to be updated
///
void update_128gb_vrefdq_if_needed(const std::vector<mss::dimm::kind<>>& i_kinds,
                                   uint8_t (&io_vrefdq_train)[2][4]);

///
/// @brief Updates the attributes if the 128GB workaround is required
/// @param[in] i_target MCS target on which to operate
/// @return SUCCESS if the code executes successfully
/// @note synchronizes attributes across the whole MCBIST
///
fapi2::ReturnCode update_128gb_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target);

} // ns eff_config

namespace plug_rule
{

///
/// @brief Ensures that there is no mixing between 128GB vendors
/// @param[in] i_kinds vector of DIMM kinds on which to operate
/// @return SUCCESS if the code executes successfully
/// @note Due to a vendor sensitivity that requires workarounds, we cannot mix 128GB vendors in the same MCA
///
fapi2::ReturnCode no_128gb_vendor_mixing(const std::vector<mss::dimm::kind<>>& i_kinds);

} // ns plug_rule
} // ns workarounds
} // ns mss
#endif
