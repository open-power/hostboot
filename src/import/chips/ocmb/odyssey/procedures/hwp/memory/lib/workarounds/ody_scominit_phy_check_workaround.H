/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_scominit_phy_check_workaround.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
/// @file ody_scominit_phy_check_workaround.H
/// @brief Odyssey workarounds set MBXLT0 bits relative to num PHY/ports found
///
// *HWP HWP Owner: David J Chung <dj.chung@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_ODY_SCOMINIT_PHY_CHECK_WORKAROUNDS_H_
#define _MSS_ODY_SCOMINIT_PHY_CHECK_WORKAROUNDS_H_

#include <fapi2.H>


namespace mss
{
namespace ody
{
namespace workarounds
{
///
/// @brief Checks if 2 mem ports are found and sets MBXLT0 bits accordingly
/// @param[in] i_target the OCMB target to operate on
/// @param[in] i_num_ports num mem ports found on ocmb
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode mbxlt0_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                const int16_t i_num_ports);

} // ns workarounds
} // ns ody
} // ns mss

#endif
