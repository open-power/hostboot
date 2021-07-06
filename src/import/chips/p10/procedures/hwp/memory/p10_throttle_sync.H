/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_throttle_sync.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_throttle_sync.H
/// @brief p10_throttle_sync HWP
/// @note The purpose of this procedure is to triggers sync command from a 'master'
/// MC to other MCs that have attached memory in a processor.
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup  : Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB
///
#ifndef _P10_THROTTLE_SYNC_H_
#define _P10_THROTTLE_SYNC_H_

#include <fapi2.H>

// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_throttle_sync_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

extern "C"
{
    ///
    /// @brief p10_throttle_sync procedure
    /// @param[in] i_target TARGET_TYPE_PROC_CHIP target
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    fapi2::ReturnCode p10_throttle_sync(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif  // _P10_THROTTLE_SYNC_H_
