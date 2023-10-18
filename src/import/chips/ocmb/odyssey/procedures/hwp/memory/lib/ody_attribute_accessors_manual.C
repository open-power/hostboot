/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ody_attribute_accessors_manual.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
/// @file ody_attribute_accessors_manual.C
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

#include <fapi2.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/num.H>
#include <lib/ody_attribute_accessors_manual.H>

namespace mss
{
namespace ody
{

///
/// @brief Unit-testable half dimm mode helper function. Calculates half dimm mode based on input params
/// @param[in] i_target OCMB chip
/// @param[in] i_half_dimm_attr half dimm mode as obtained from attribute
/// @param[in] i_half_dimm_override_attr half dimm mode override from attribute
/// @param[out] o_is_half_dimm_mode resulting value for half dimm mode after calculations
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode half_dimm_mode_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint8_t i_half_dimm_attr,
    const uint8_t i_half_dimm_override_attr,
    bool& o_is_half_dimm_mode )
{
    bool l_is_half_dimm = 0;

    // This might be overwritten below by overrides
    l_is_half_dimm = (i_half_dimm_attr == fapi2::ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_HALF_DIMM);

    // Now let's apply the override
    if (i_half_dimm_override_attr == fapi2::ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_OVERRIDE_OVERRIDE_HALF_DIMM)
    {
        l_is_half_dimm = true;

    }
    else if (i_half_dimm_override_attr == fapi2::ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_OVERRIDE_OVERRIDE_FULL_DIMM)
    {
        l_is_half_dimm = false;
        FAPI_DBG( GENTARGTIDFORMAT " overridden to FULL_DIMM_MODE", TARGTID);
    }

    o_is_half_dimm_mode = l_is_half_dimm;

#ifndef __PPE__
    FAPI_INF("For " GENTARGTIDFORMAT " , %s override is present. The chip is in %s (attribute %u)",
             TARGTID,
             i_half_dimm_override_attr > 0 ? "an" : "no",
             o_is_half_dimm_mode ? "half-DIMM mode" : "full-DIMM mode", l_is_half_dimm);
#endif

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Gets whether the OCMB will be configured to half-DIMM mode
/// @param[in] i_target OCMB target on which to operate
/// @param[out] o_is_half_dimm_mode true if the part is in half-DIMM mode
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode half_dimm_mode(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    bool& o_is_half_dimm_mode )
{
    // Variables
    o_is_half_dimm_mode = false;
    uint8_t l_half_dimm_attr = 0;
    uint8_t l_override_attr = 0;

    FAPI_TRY( mss::attr::get_ocmb_half_dimm_mode(i_target, l_half_dimm_attr) );
    FAPI_TRY( mss::attr::get_ocmb_half_dimm_mode_override(i_target, l_override_attr) );

    // o_is_half_dimm_mode will be set by the helper function
    FAPI_TRY( half_dimm_mode_helper(i_target, l_half_dimm_attr, l_override_attr,
                                    o_is_half_dimm_mode));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retrieves number of sub ranks per DIMM which is the number of total ranks divided by the number of master ranks
/// @param[in] i_target DIMM target
/// @param[in,out] io_num_sranks Count of sranks
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode get_srank_count(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    uint8_t& io_num_sranks)
{
    uint8_t l_num_ranks = 0;
    uint8_t l_num_mranks = 0;

    FAPI_TRY( mss::attr::get_logical_ranks_per_dimm(i_target, l_num_ranks) );
    FAPI_TRY( mss::attr::get_num_master_ranks_per_dimm(i_target, l_num_mranks) );

    FAPI_ASSERT(l_num_mranks > 0 ,
                fapi2::ODY_NUM_MRANKS_OUT_OF_BOUNDS().
                set_OCMB_TARGET(i_target).
                set_NUM_MRANKS(l_num_mranks),
                TARGTIDFORMAT " returned an out of bounds number of %d mranks",
                TARGTID, l_num_mranks);

    io_num_sranks = l_num_ranks / l_num_mranks;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns ody

} // ns mss
