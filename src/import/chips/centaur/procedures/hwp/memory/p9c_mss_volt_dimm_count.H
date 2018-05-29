/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_volt_dimm_count.H $ */
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
///
/// @file p9c_mss_volt_dimm_count.H
/// @brief Determines number of dimms present behind a voltage domain
///
/// *HWP HWP Owner: Andre Marin <aamaring@us.ibm.com>
/// *HWP HWP Backup: Michael Pardeik <pardeik@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#ifndef MSS_VOLT_DIMM_COUNT_H_
#define MSS_VOLT_DIMM_COUNT_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_volt_dimm_count_FP_t)(const
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>>&);

extern "C"
{

    ///
    /// @brief Determines number of dimms present behind a voltage domain
    /// @param[in] i_targets_memb  Reference to vector of present Centaur Targets in a particular power domain
    /// @return ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_volt_dimm_count(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>>&
            i_targets_memb);

} // extern "C"

#endif // MSS_VOLT_DIMM_COUNT_H_
