/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_volt_vddr_offset.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file p9c_mss_mss_volt_vddr_offset.H
/// @brief Creates VDDR voltage offsets
///
/// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
/// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB

#ifndef P9C_MSS_VOLT_VDDR_OFFSET_H
#define P9C_MSS_VOLT_VDDR_OFFSET_H

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_volt_vddr_offset_FP_t)(const
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>>&);

extern "C"
{

    ///
    /// @brief mss_volt_vddr_offset procedure. Determines operating vddr voltage for dimms behind a vddr voltage domain
    /// @param[in] i_targets  Reference to vector of Centaur Targets in a particular vddr power domain
    /// @return ReturnCode
    ///

    fapi2::ReturnCode p9c_mss_volt_vddr_offset(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>>& i_targets);

} // extern "C"

#endif // P9C_MSS_VOLT_VDDR_OFFSET_H
