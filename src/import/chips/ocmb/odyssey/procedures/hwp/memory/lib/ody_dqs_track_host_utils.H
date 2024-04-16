/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ody_dqs_track_host_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
/// @file ody_dqs_track_utils.H
/// @brief  Tool to track and recal DQS
///
// *HWP HWP Owner: David J. Chung <dj.chung@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory Lab

#ifndef _ODY_DQS_TRACK_UTILS_H_
#define _ODY_DQS_TRACK_UTILS_H_

#include <fapi2.H>

namespace mss
{
namespace ody
{

///
/// @brief Suspend DQS drift track and poll MCBIST until it's done executing
/// @param [in] i_target OCMB target
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode suspend_dqs_track(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Resume DQS drift track
/// @param [in] i_target OCMB target
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode resume_dqs_track(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

} // namespace ody
} // namespace mss
#endif
