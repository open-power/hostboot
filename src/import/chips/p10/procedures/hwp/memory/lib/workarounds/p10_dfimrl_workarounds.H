/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/workarounds/p10_dfimrl_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2024                        */
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
/// @file p10_dfimrl_workarounds.H
/// @brief Workarounds for p10 DFIMRL workaround
// *HWP HWP Owner: Sneha Kadam <Sneha.Kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#ifndef _P10_DFIMRL_WORKAROUNDS_H_
#define _P10_DFIMRL_WORKAROUNDS_H_

#include <fapi2.H>

namespace mss
{
namespace workarounds
{
namespace eff_config
{

///
/// @brief Updates the DFIMRL register on an OCMB chip
/// @param[in] i_target the fapi2::Target for the OCMB chip
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
fapi2::ReturnCode config_dfimrl(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

} // namespace eff_config
} // namespace workarounds
} // namespace mss

#endif
