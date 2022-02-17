/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_attribute_accessors_manual.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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

#include <lib/shared/exp_consts.H>
#include <lib/exp_attribute_accessors_manual.H>
#include <lib/dimm/exp_kind.H>
#include <mss_p10_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>

namespace mss
{

///
/// @brief Check if any dimms exist that have RCD enabled - DIMM specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode has_rcd( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                           bool& o_has_rcd )
{
    // Assume RCD is not supported at beginning of check
    o_has_rcd = false;

    uint8_t l_dimm_type = 0;
    uint8_t l_rcd_supported = 0;

    FAPI_TRY(mss::attr::get_dimm_type(i_target, l_dimm_type));
    FAPI_TRY(mss::attr::get_supported_rcd(i_target, l_rcd_supported));

    // OR with tmp_rcd to maintain running true/false if RCD on *any* DIMM
    o_has_rcd |= ((l_dimm_type == fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_RDIMM) ||
                  (l_dimm_type == fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_LRDIMM));

    o_has_rcd |= (l_rcd_supported == fapi2::ENUM_ATTR_MEM_EFF_SUPPORTED_RCD_RCD_PER_CHANNEL_1);

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Check if any dimms exist that have RCD enabled - MEM PORT specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode has_rcd( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                           bool& o_has_rcd )
{
    // Assume RCD is not supported at beginning of check
    o_has_rcd = false;

    // Loop over all DIMM's and determine if we have an RCD
    for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        bool l_current_dimm_rcd = false;
        FAPI_TRY(has_rcd(l_dimm, l_current_dimm_rcd));
        o_has_rcd |= l_current_dimm_rcd;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Check if any dimms exist that have RCD enabled - OCMB CHIP specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode has_rcd( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                           bool& o_has_rcd )
{
    // Assume RCD is not supported at beginning of check
    o_has_rcd = false;

    // Nested for loops to determine DIMM type if DIMMs exist
    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        bool l_current_port_rcd = false;
        FAPI_TRY(has_rcd(l_port, l_current_port_rcd));
        o_has_rcd |= l_current_port_rcd;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    return fapi2::current_err;
}

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

    uint8_t l_mds_ddimm = 0;

    FAPI_TRY(mss::attr::get_mds_ddimm(i_target, l_mds_ddimm));

    o_is_mds = (l_mds_ddimm == fapi2::ENUM_ATTR_MEM_EFF_MDS_DDIMM_TRUE);

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

    fapi2::ATTR_MEM_EFF_MDS_DDIMM_Type l_mds_ddimm_on_port = {};

    FAPI_TRY(mss::attr::get_mds_ddimm(i_target, l_mds_ddimm_on_port));

    // Loop over all DIMM's and determine if we have any MDS type DIMMs
    for (const auto l_mds_ddimm : l_mds_ddimm_on_port)
    {
        o_is_mds |= (l_mds_ddimm == fapi2::ENUM_ATTR_MEM_EFF_MDS_DDIMM_TRUE);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss
