/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_attr_update.H $ */
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
/// @file p9_mss_attr_update.H
/// @brief Programatic over-rides related to effective config
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef __P9_MSS_ATTR_UPDATE__
#define __P9_MSS_ATTR_UPDATE__

#include <fapi2.H>

// Lx version 1 parsing/extraction constants
// section offsets
constexpr uint8_t Lx_V1_R_OFFSET_TO_F0S = 24;
constexpr uint8_t Lx_V1_R_OFFSET_TO_F1S = 82;
constexpr uint8_t Lx_V1_R_OFFSET_TO_F2S = 140;
constexpr uint8_t Lx_V1_R_OFFSET_TO_F3S = 198;

typedef fapi2::ReturnCode (*p9_mss_attr_update_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MCS>&);

// Define some of the helper API so we can test them in CI
///
/// @brief Given target and memory frequency, return MVPD Lx keyword and
///        offset to first byte in frequency-specific customization section
/// @param[in] i_target the port target (e.g., MCA)
/// @param[out] o_keyword Lx keyword ID for this port
/// @param[out] o_s_offset frequency-specific section byte offset
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9_mss_attr_update_get_lx_offsets( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        fapi2::MvpdKeyword& o_keyword,
        uint8_t& o_s_offset);

extern "C"
{

///
/// @brief Programatic over-rides related to effective config
/// @param[in] i_target, the controller (e.g., MCS)
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_attr_update( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target );

}

#endif
