/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_mds_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file exp_mds_workarounds.H
/// @brief Workarounds for MDS HWP enablement
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hicmkan@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
/// EKB-Mirror-To: hostboot
///

#ifndef _MDS_WORKAROUNDS_H_
#define _MDS_WORKAROUNDS_H_

namespace mss
{
namespace exp
{
namespace workarounds
{

///
/// @brief Handles the i2c media enablement script from the lab
/// @param[in] i_target the fapi2 target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode mds_i2c_media_enable(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

} // namespace workarounds
} // namespace exp
} // namespace mss

#endif // _MDS_WORKAROUNDS_H_
