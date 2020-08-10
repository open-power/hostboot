/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/workarounds/eff_config_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

namespace mss
{

namespace workarounds
{

namespace eff_config
{

///
/// @brief Updates timing attributes to be synchronized allowing the parts to be broadcast capable
/// @param[in] i_target MCS target on which to operate
/// @return SUCCESS if the code executes successfully
/// @note synchronizes attributes across the whole MCBIST
///
fapi2::ReturnCode synchronize_broadcast_timings(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target);

} // ns eff_config
} // ns workarounds
} // ns mss
#endif
