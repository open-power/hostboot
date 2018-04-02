/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/mss_dynamic_vid_utils.H $ */
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
/// @file mss_dynamic_vid_utils.H
/// @brief Utility procedures for dyanamic voltage
///
/// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
/// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB

#ifndef MSS_DYNAMIC_VID_UTILS_H
#define MSS_DYNAMIC_VID_UTILS_H

#include <fapi2.H>

///
/// @brief Checks centaur configurations and outputs DRAM device type
/// @param[in]  std::vector<fapi2::Target> l_targets  Reference to vector of Centaur Targets in a particular power domain
/// @param[out] o_dram_type the DRAM device type (DDR3 or DDR4)
/// @return ReturnCode success IFF everything passes
///
fapi2::ReturnCode check_dram_gen_plug(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>>& i_targets,
                                      uint8_t& o_dram_gen);


#endif // MSS_DYNAMIC_VID_UTILS_H
