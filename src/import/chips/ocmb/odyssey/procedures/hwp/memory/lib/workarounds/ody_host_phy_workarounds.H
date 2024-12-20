/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_host_phy_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2025                        */
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
/// @file ody_host_phy_workarounds.H
/// @brief Workarounds for host to check Odyssey PHY related issues
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_HOST_ODY_PHY_WORKAROUNDS_H_
#define _MSS_HOST_ODY_PHY_WORKAROUNDS_H_

#include <fapi2.H>

namespace mss
{
namespace ody
{
namespace phy
{
namespace workarounds
{

///
/// @brief Catches and asserts out if the Odyssey suffered a fatal error
/// @param[in] i_target the target on which to operate
/// @return FAPI2_RC_SUCCSS iff ok
/// @note Identifies a fatal error by if the ODT disable bit is set
///
fapi2::ReturnCode gard_fatal_errors( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target );

} // ns workarounds
} // ns phy
} // ns ody
} // ns mss

#endif
