/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/p10_attribute_accessors_manual.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
// EKB-Mirror-To: hostboot

///
/// @file p10_attribute_accessors_manual.H
/// @brief Manually created attribute accessors.
/// Some attributes aren't in files we want to incorporate in to our automated
/// accessor generator. EC workarounds is one example - everytime someone creates
/// a work-around they'd be burdened with updating this file.
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory
#ifndef P10_ATTR_ACCESS_MANUAL_H_
#define P10_ATTR_ACCESS_MANUAL_H_

#include <fapi2.H>

namespace mss
{

///
/// @brief MFG test type selector for screening test check
///
enum mfg_test_type
{
    MFG_TEST_CRC,
    MFG_TEST_EDPL
};

///
/// @brief Function to check if MNFG OMI screening test is set up, helper for unit testing
/// @param[in] i_omi_screen_set true if ENUM_ATTR_MFG_FLAGS_MFG_OMI_CRC_EDPL_SCREEN is set
/// @param[in] i_num_allowed number of CRC or EDPL errors allowed, from attribute values
/// @return true if MNFG OMI screening test is set up
///
bool check_omi_mfg_screen_setting_helper(const bool i_omi_screen_set,
        const uint16_t i_num_allowed);

///
/// @brief Function to check if MNFG OMI screening CRC test is set up
/// @param[out] o_is_set will be set to true if MNFG OMI screening CRC test is set up
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode check_omi_mfg_screen_crc_setting(bool& o_is_set);

///
/// @brief Function to check if MNFG OMI screening EDPL test is set up
/// @param[out] o_is_set will be set to true if MNFG OMI screening EDPL test is set up
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode check_omi_mfg_screen_edpl_setting(bool& o_is_set);

} // ns mss

#endif
