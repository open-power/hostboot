/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_draminit_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file ody_draminit_utils.H
/// @brief Odyssey PHY draminit utility functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _ODY_DRAMINIT_UTILS_H_
#define _ODY_DRAMINIT_UTILS_H_

#include <fapi2.H>

namespace mss
{
namespace ody
{
namespace phy
{

///
/// @brief Starts the firmware draminit training
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Assumes that the firmware binaries and data structures are loaded appropriately
///
fapi2::ReturnCode start_training(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Cleans up from the firmware draminit training
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note puts the processor into a stall state
///
fapi2::ReturnCode cleanup_training(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

} // namespace phy
} // namespace ody
} // namespace mss
#endif
