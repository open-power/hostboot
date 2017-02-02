/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_volt.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9c_mss_volt.H
/// @brief Reads in supported DIMM voltages from SPD and determines optimal voltage bin for the DIMM voltage domain.
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamaring@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB


#ifndef MSS_VOLTHWPB_H_
#define MSS_VOLTHWPB_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_volt_FP_t)(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>>&);

extern "C"
{

    ///
    /// @brief Reads in supported DIMM voltages from SPD and determines optimal voltage bin for the DIMM voltage domain.
    /// @param[in] i_targets_memb -  vector of centaur targets
    /// @return FAPI2_RC_SUCCESS iff operating voltage found
    ///
    fapi2::ReturnCode p9c_mss_volt(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>>& l_targets_memb);

} // extern "C"

#endif // MSS_VOLTHWPB_H_
