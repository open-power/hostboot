/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/exp_kind.C $ */
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

///
/// @file exp_kind.C
/// @brief Encapsulation for dimms of all types
///
// *HWP HWP Owner: Amita Banchhor <Amita.Banchhor@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <lib/shared/exp_defaults.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>
#include <lib/shared/exp_consts.H>
#include <lib/dimm/exp_kind.H>
#include <lib/exp_attribute_accessors_manual.H>

namespace mss
{

namespace dimm
{

///
/// @brief Check if any dimms exist that have RCD enabled - explorer/DIMM specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode has_rcd<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
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
/// @brief Check if any dimms exist that have RCD enabled - explorer/PORT specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode has_rcd<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        bool& o_has_rcd )
{
    // Assume RCD is not supported at beginning of check
    o_has_rcd = false;

    // Loop over all DIMM's and determine if we have an RCD
    for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        bool l_current_dimm_rcd = false;
        FAPI_TRY(has_rcd<mss::mc_type::EXPLORER>(l_dimm, l_current_dimm_rcd));
        o_has_rcd |= l_current_dimm_rcd;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Check if any dimms exist that have RCD enabled - explorer/OCMB specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode has_rcd<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        bool& o_has_rcd )
{
    // Assume RCD is not supported at beginning of check
    o_has_rcd = false;

    // Nested for loops to determine DIMM type if DIMMs exist
    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        bool l_current_port_rcd = false;
        FAPI_TRY(has_rcd<mss::mc_type::EXPLORER>(l_port, l_current_port_rcd));
        o_has_rcd |= l_current_port_rcd;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Check if any dimm is hybrid type MDS - explorer/DIMM specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_is_mds - true iff any DIMM is hybrid type MDS
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode is_mds<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool& o_is_mds )
{
    // Call manual accessor for dimm
    return mss::is_mds(i_target, o_is_mds);
}

///
/// @brief Check if any dimm is hybrid type MDS - explorer/DIMM specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_is_mds - true iff any DIMM is hybrid type MDS
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode is_mds<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        bool& o_is_mds )
{
    // Call manual accessor for mem_port
    return mss::is_mds(i_target, o_is_mds);
}

///
/// @brief Check if any dimm is hybrid type MDS - explorer/DIMM specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_is_mds - true iff any DIMM is hybrid type MDS
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode is_mds<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        bool& o_is_mds )
{
    // Assume its not MDS to start
    o_is_mds = false;

    // Loop over all PORT's and determine if we have any MDS type DIMMs
    for(const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        bool l_current_port_mds = false;
        FAPI_TRY(is_mds<mss::mc_type::EXPLORER>(l_port, l_current_port_mds));
        o_is_mds |= l_current_port_mds;
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Check if any dimm is hybrid type MDS - explorer/DIMM specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_is_mds - true iff any DIMM is hybrid type MDS
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode is_mds<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target,
        bool& o_is_mds )
{
    // Assume it's not MDS to start
    o_is_mds = false;

    // Find and loop over omi targets
    for (const auto& l_omi : i_target.getChildren<fapi2::TARGET_TYPE_OMI>())
    {
        // Find and loop over ocmb targets, checking for MDS dimms on each
        for (const auto& l_ocmb : l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>())
        {
            bool l_current_ocmb_mds = false;
            FAPI_TRY(is_mds<mss::mc_type::EXPLORER>(l_ocmb, l_current_ocmb_mds));
            o_is_mds |= l_current_ocmb_mds;
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    return fapi2::current_err;
}

} // end dimm ns
} // end mss ns
