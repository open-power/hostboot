/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_attribute_accessors_manual.C $ */
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
/// @file exp_attribute_accessors_manual.C
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

#include <lib/shared/exp_defaults.H>
#include <lib/shared/exp_consts.H>
#include <lib/exp_attribute_accessors_manual.H>
#include <lib/dimm/exp_kind.H>
#include <mss_p10_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>

namespace mss
{

///
/// @brief Gets if the given target has a quad encoded CS - DIMM target specialization
/// @param[in] i_target the target
/// @param[out] o_is_quad_encoded_cs true if the part uses quad encoded CS otherwise false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note Used for the workaround to JIRA355 - quad encoded CS rank1/2 being swapped between IBM's logic and the DFI
///
template<>
fapi2::ReturnCode is_quad_encoded_cs(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     bool& o_is_quad_encoded_cs)
{
    o_is_quad_encoded_cs = false;
    uint8_t l_master_ranks = 0;
    bool l_has_rcd = false;

    FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_target, l_master_ranks));
    FAPI_TRY(mss::dimm::has_rcd<mss::mc_type::EXPLORER>(i_target, l_has_rcd));

    // We're in quad encoded mode IF
    // 1) 4R per DIMM
    // 2) we have an RCD
    o_is_quad_encoded_cs = (l_master_ranks == fapi2::ENUM_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_4R) &&
                           (l_has_rcd);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets if the given target has a quad encoded CS - MEM_PORT target specialization
/// @param[in] i_target the target
/// @param[out] o_is_quad_encoded_cs true if the part uses quad encoded CS otherwise false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note Used for the workaround to JIRA355 - quad encoded CS rank1/2 being swapped between IBM's logic and the DFI
///
template<>
fapi2::ReturnCode is_quad_encoded_cs(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                     bool& o_is_quad_encoded_cs)
{
    o_is_quad_encoded_cs = false;
    uint8_t l_master_ranks[mss::exp::MAX_DIMM_PER_PORT] = {};
    bool l_has_rcd = false;

    FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_target, l_master_ranks));
    FAPI_TRY(mss::dimm::has_rcd<mss::mc_type::EXPLORER>(i_target, l_has_rcd));

    // We're in quad encoded mode IF
    // 1) 4R per DIMM
    // 2) we have an RCD
    o_is_quad_encoded_cs = (l_master_ranks[0] == fapi2::ENUM_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_4R) &&
                           (l_has_rcd);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check if this dimm is hybrid type MDS
/// @param[in] i_target - DIMM target
/// @param[out] o_is_mds - true iff DIMM is hybrid type MDS
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode is_mds( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, bool& o_is_mds )
{
    // Assume its not MDS to start
    o_is_mds = false;

    uint8_t l_hybrid = 0;
    uint8_t l_hybrid_media_type = 0;

    FAPI_TRY(mss::attr::get_hybrid(i_target, l_hybrid));
    FAPI_TRY(mss::attr::get_hybrid_memory_type(i_target, l_hybrid_media_type));

    o_is_mds = (l_hybrid_media_type == fapi2::ENUM_ATTR_MEM_EFF_HYBRID_MEMORY_TYPE_MDS &&
                l_hybrid == fapi2::ENUM_ATTR_MEM_EFF_HYBRID_IS_HYBRID);

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Check if any dimm is hybrid type MDS
/// @param[in] i_target - MEM_PORT target
/// @param[out] o_is_mds - true iff any DIMM is hybrid type MDS
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode is_mds( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, bool& o_is_mds )
{
    // Assume its not MDS to start
    o_is_mds = false;

    // Loop over all DIMM's and determine if we have any MDS type DIMMs
    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        bool l_current_mds = false;
        FAPI_TRY(is_mds(l_dimm, l_current_mds));
        o_is_mds |= l_current_mds;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

namespace exp
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
} // ns exp

} // ns mss
