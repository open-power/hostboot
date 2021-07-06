/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_mss_freq_system.H $ */
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
/// @file p10_mss_freq_system.H
/// @brief Matches OMI freq with DDR freq
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef P10_MSS_FREQ_SYSTEM_H_
#define P10_MSS_FREQ_SYSTEM_H_

#include <fapi2.H>
#include <vector>

typedef fapi2::ReturnCode (*p10_mss_freq_system_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

extern "C"
{

    ///
    /// @brief Matches OMI freq with DDR freq
    /// @param[in] i_target PROC_CHIP target
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p10_mss_freq_system(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
}

#endif
