/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/phy/exp_phy_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
/// @file exp_phy_utils.H
/// @brief Utility functions to control phy access
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{
namespace exp
{
namespace phy
{

///
/// @brief Configure the PHY to allow/disallow register accesses via scom
/// @param[in] i_target the target on which to operate
/// @param[in] i_state the state to set the PHY to - either mss::states::ON_N or mss::states::OFF_N
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_phy_access(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                       const mss::states i_state);

///
/// @brief Disable the ALERT_N bit in MCHP PHY
///
/// @param[in] i_target MEM_PORT target
/// @param[in] i_is_planar true if this is a planar system
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode disable_alert_n(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                  const uint8_t i_is_planar);

///
/// @brief Enable async drive of the ALERT_N receiver in MCHP PHY for planar
///
/// @param[in] i_target MEM_PORT target
/// @param[in] i_is_planar true if this is a planar system
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode enable_alert_n_sync_bypass(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_is_planar);

} // phy
} // exp
} // mss
