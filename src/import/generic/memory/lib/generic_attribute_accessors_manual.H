/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/generic_attribute_accessors_manual.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
/// @file generic_attribute_accessors_manual.H
/// @brief Manually created attribute accessors.
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory
#ifndef GEN_ATTR_ACCESS_MANUAL_H_
#define GEN_ATTR_ACCESS_MANUAL_H_

#include <fapi2.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

///
/// @brief Function to check if a given MFG_FLAG is enabled
/// @param[in] i_flag MFG_FLAG enum to check for
/// @param[out] o_is_set will be set to true if MFG_FLAG is enabled
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode check_mfg_flag(const uint32_t i_flag, bool& o_is_set)
{
    fapi2::ATTR_MFG_FLAGS_Type l_mfg_flags = {0};
    fapi2::buffer<uint32_t> l_mfg_flag_cell;
    o_is_set = false;

    constexpr size_t CELL_SIZE = 32;
    const size_t l_cell_index = i_flag / CELL_SIZE;
    const size_t l_flag_pos = i_flag % CELL_SIZE;

    FAPI_TRY(mss::attr::get_mfg_flags(l_mfg_flags));

    l_mfg_flag_cell = l_mfg_flags[l_cell_index];
    o_is_set = l_mfg_flag_cell.getBit(l_flag_pos);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Check if any dimms exist that have RCD enabled - DIMM specialization
/// @param[in] i_target - the fapi2::Target we are starting from
/// @param[out] o_has_rcd - true iff any DIMM with RCD detected
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode has_rcd( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
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
inline fapi2::ReturnCode has_rcd( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
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
inline fapi2::ReturnCode has_rcd( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
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

} // ns mss

#endif
