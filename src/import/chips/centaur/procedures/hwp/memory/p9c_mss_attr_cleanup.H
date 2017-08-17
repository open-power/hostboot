/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_attr_cleanup.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9c_mss_attr_cleanup.H
/// @brief Decode SPD and set attrs
///
// *HWP HWP Owner: Thomas Sand <trsand@us.ibm.com>
// *HWP FW Owner: Luke Mulkey <lwmulkey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef __P9C_MSS_ATTR_CLEANUP__
#define __P9C_MSS_ATTR_CLEANUP__

#include <fapi2.H>

// Lx version 1 parsing/extraction constants
// section offsets
constexpr uint8_t Lx_V1_R_OFFSET_TO_F0S = 24;
constexpr uint8_t Lx_V1_R_OFFSET_TO_F1S = 82;
constexpr uint8_t Lx_V1_R_OFFSET_TO_F2S = 140;
constexpr uint8_t Lx_V1_R_OFFSET_TO_F3S = 198;

typedef fapi2::ReturnCode (*p9c_mss_attr_cleanup_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&);

extern "C"
{

///
/// @brief Programatic over-rides related to effective config
/// @param[in] i_target, the controller (e.g., MCS)
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9c_mss_attr_cleanup( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target );

}

#endif
