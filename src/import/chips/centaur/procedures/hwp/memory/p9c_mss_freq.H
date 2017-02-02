/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_freq.H $ */
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

/// @file p9c_mss_freq.C
/// @brief DIMM SPD attributes are read to determine optimal DRAM frequency
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamaring@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB


#ifndef MSS_FREQHWPB_H_
#define MSS_FREQHWPB_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_freq_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&);

extern "C"
{
    ///
    /// @brief DIMM SPD attributes are read to determine optimal DRAM frequency
    /// @param[in] i_target_memb Centaur target
    /// @return FAPI2_RC_SUCCESS iff frequency + CL found successfully
    ///
    fapi2::ReturnCode p9c_mss_freq(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target);

} // extern "C"

#endif // MSS_FREQHWPB_H_
