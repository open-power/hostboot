/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/p10_attribute_accessors_manual.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file p10_attribute_accessors_manual.C
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

#include <lib/p10_attribute_accessors_manual.H>
#include <mss_p10_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>

namespace mss
{

///
/// @brief Function to check if MNFG OMI screening test is set up, helper for unit testing
/// @param[in] i_omi_screen_set true if ENUM_ATTR_MFG_FLAGS_MFG_OMI_CRC_EDPL_SCREEN is set
/// @param[in] i_num_allowed number of CRC or EDPL errors allowed, from attribute values
/// @return true if MNFG OMI screening test is set up
///
bool check_omi_mfg_screen_setting_helper(const bool i_omi_screen_set,
        const uint16_t i_num_allowed)
{
    // if the mnfg policy is set, and we're allowing a non-zero number of CRCs/EDPLs,
    // we need to set up the screen settings
    return (i_omi_screen_set && (i_num_allowed > 0));
}

///
/// @brief Function to check if MNFG OMI screening CRC test is set up
/// @param[out] o_is_set will be set to true if MNFG OMI screening CRC test is set up
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode check_omi_mfg_screen_crc_setting(bool& o_is_set)
{
    fapi2::ATTR_MFG_SCREEN_OMI_CRC_ALLOWED_Type l_crc_allowed = 0;
    bool l_omi_screen_set = false;
    o_is_set = false;

    // NOTE: This is a workaround for an infra problem where new MFG_FLAG enums aren't
    // getting propagated to the HWSV software. The new flag MNFG_OMI_CRC_EDPL_SCREEN
    // is in the slot previously called MNFG_POLICY_FLAG_AVAIL_05
    constexpr uint32_t MNFG_OMI_CRC_EDPL_SCREEN = fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_POLICY_FLAG_AVAIL_05;

    FAPI_TRY(mss::check_mfg_flag(MNFG_OMI_CRC_EDPL_SCREEN, l_omi_screen_set));
    FAPI_TRY(mss::attr::get_mfg_screen_omi_crc_allowed(l_crc_allowed));

    o_is_set = check_omi_mfg_screen_setting_helper(l_omi_screen_set, l_crc_allowed);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Function to check if MNFG OMI screening EDPL test is set up
/// @param[out] o_is_set will be set to true if MNFG OMI screening EDPL test is set up
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode check_omi_mfg_screen_edpl_setting(bool& o_is_set)
{
    fapi2::ATTR_MFG_SCREEN_OMI_EDPL_ALLOWED_Type l_edpl_allowed = 0;
    bool l_omi_screen_set = false;
    o_is_set = false;

    // NOTE: This is a workaround for an infra problem where new MFG_FLAG enums aren't
    // getting propagated to the HWSV software. The new flag MNFG_OMI_CRC_EDPL_SCREEN
    // is in the slot previously called MNFG_POLICY_FLAG_AVAIL_05
    constexpr uint32_t MNFG_OMI_CRC_EDPL_SCREEN = fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_POLICY_FLAG_AVAIL_05;

    FAPI_TRY(mss::check_mfg_flag(MNFG_OMI_CRC_EDPL_SCREEN, l_omi_screen_set));
    FAPI_TRY(mss::attr::get_mfg_screen_omi_edpl_allowed(l_edpl_allowed));

    o_is_set = check_omi_mfg_screen_setting_helper(l_omi_screen_set, l_edpl_allowed);

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss
