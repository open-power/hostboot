/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/host_ody_phy_access.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2024                             */
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

// EKB-Mirror-To: hostboot
///
/// @file host_ody_phy_access.H
/// @brief Host Odyssey PHY access functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _HOST_ODY_PHY_ACCESS_H_
#define _HOST_ODY_PHY_ACCESS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{
namespace ody
{
namespace phy
{

///
/// @brief Configure the PHY to allow/disallow register accesses via scom
/// @param[in] i_target the target on which to operate
/// @param[in] i_state the state to set the PHY to - either mss::states::ON_N (scom access) or mss::states::OFF_N (training access)
/// @param[in] i_runtime true if running at runtime, meaning the UCCLK needs to be switched on/off (default: false)
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Specific function for the host to allow for scom specialization as needed
/// @note This function has been duplicated in pmic_periodic_telemetry_utils_ddr5.H since we did not want to include unnecessary
///       libraries in to the PMIC code. Please make sure that both the locations of the function are up to date
///
fapi2::ReturnCode host_configure_phy_scom_access(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const mss::states i_state,
        const bool i_runtime = false);

///
/// @brief Gets the port offset
/// @param[in] i_target the target on which to operate
/// @return the scom offset based upon the port
///
uint64_t get_port_addr_offset(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

} // namespace phy
} // namespace ody
} // namespace mss
#endif
