/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_attribute_accessors_manual.H $ */
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

///
/// @file exp_attribute_accessors_manual.H
/// @brief Manually created attribute accessors.
/// Some attributes aren't in files we want to incorporate in to our automated
/// accessor generator. EC workarounds is one example - everytime someone creates
/// a work-around they'd be burdened with updating this file.
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory
#ifndef EXP_ATTR_ACCESS_MANUAL_H_
#define EXP_ATTR_ACCESS_MANUAL_H_

#include <fapi2.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/shared/exp_consts.H>

namespace mss
{

///
/// @brief Unit-testable half dimm mode helper function. Calculates half dimm mode based on input params
/// @param[in] i_target OCMB chip
/// @param[in] i_is_enterprise enterprise mode is enabled
/// @param[in] i_half_dimm_attr half dimm mode as obtained from attribute
/// @param[in] i_half_dimm_override_attr half dimm mode override from attribute
/// @param[out] o_is_half_dimm_mode resulting value for half dimm mode after calculations
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
inline fapi2::ReturnCode half_dimm_mode_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const bool i_is_enterprise,
    const uint8_t i_half_dimm_attr,
    const uint8_t i_half_dimm_override_attr,
    bool& o_is_half_dimm_mode )
{
    o_is_half_dimm_mode = false;

    bool l_is_half_dimm = 0;

    // First let's assert that ocmb_half_dimm_mode isn't HALF_DIMM when ENTERPRISE is 0
    // Even though this could theoretically be overridden back to FULL_DIMM, we should
    // check that the initial value is also valid.
    FAPI_ASSERT(!i_half_dimm_attr || i_is_enterprise,
                fapi2::MSS_EXP_HALF_DIMM_MODE_NOT_SUPPORTED()
                .set_ENTERPRISE_SETTING(i_is_enterprise)
                .set_HALF_DIMM_SETTING(i_half_dimm_attr)
                .set_OCMB_TARGET(i_target),
                "%s Invalid configuration: ATTR_MSS_OCMB_HALF_DIMM_MODE set to HALF_DIMM while enterprise is disabled",
                mss::c_str(i_target));

    // This might be overwritten below by overrides
    l_is_half_dimm = (i_half_dimm_attr == fapi2::ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_HALF_DIMM);

    // Now let's apply the override
    if (i_half_dimm_override_attr == fapi2::ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_OVERRIDE_OVERRIDE_HALF_DIMM)
    {
        l_is_half_dimm = true;

        // Assert once more that this is valid
        FAPI_ASSERT(!l_is_half_dimm || i_is_enterprise,
                    fapi2::MSS_EXP_HALF_DIMM_MODE_NOT_SUPPORTED()
                    .set_ENTERPRISE_SETTING(i_is_enterprise)
                    .set_HALF_DIMM_SETTING(l_is_half_dimm)
                    .set_OCMB_TARGET(i_target),
                    "%s Invalid configuration: HALF_DIMM_MODE overridden to HALF_DIMM while enterprise is disabled",
                    mss::c_str(i_target));

        FAPI_DBG("%s overridden to HALF_DIMM_MODE", mss::c_str(i_target));
    }

    else if (i_half_dimm_override_attr == fapi2::ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_OVERRIDE_OVERRIDE_FULL_DIMM)
    {
        l_is_half_dimm = false;
        FAPI_DBG("%s overridden to FULL_DIMM_MODE", mss::c_str(i_target));
    }

    o_is_half_dimm_mode = l_is_half_dimm;

    FAPI_INF("%s %s in enterprise mode, and %s override is present. The chip is in %s (attribute %u)",
             mss::c_str(i_target),
             i_is_enterprise ? "is" : "is not",
             i_half_dimm_override_attr > 0 ? "an" : "no",
             o_is_half_dimm_mode ? "half-DIMM mode" : "full-DIMM mode", l_is_half_dimm);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets whether the OCMB will be configured to half-DIMM mode
/// @param[in] i_target OCMB target on which to operate
/// @param[out] o_is_half_dimm_mode true if the part is in half-DIMM mode
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
inline fapi2::ReturnCode half_dimm_mode(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const bool i_is_enterprise_mode,
    bool& o_is_half_dimm_mode )
{
    // Variables
    o_is_half_dimm_mode = false;
    uint8_t l_half_dimm_attr = 0;
    uint8_t l_override_attr = 0;

    FAPI_TRY( mss::attr::get_ocmb_half_dimm_mode(i_target, l_half_dimm_attr) );
    FAPI_TRY( mss::attr::get_ocmb_half_dimm_mode_override(i_target, l_override_attr) );

    // o_is_half_dimm_mode will be set by the helper function
    FAPI_TRY( mss::half_dimm_mode_helper(i_target, i_is_enterprise_mode, l_half_dimm_attr, l_override_attr,
                                         o_is_half_dimm_mode));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MEM_EFF_VOLT_VDDR setter
/// @tparam T the fapi2 target type of the target
/// @param[in] i_target const ref to the TARGET_TYPE_OCMB_CHIP
/// @param[in] i_value value to set
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
//TODO: Remove this once we have auto-generated attr setters
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode set_volt_vddr(const fapi2::Target<T>& i_target, uint32_t i_value)
{
    const auto l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_VOLT_VDDR, l_ocmb, i_value) );
    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR("failed setting ATTR_MEM_EFF_VOLT_VDDR: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief ATTR_MEM_EFF_VOLT_VPP setter
/// @tparam T the fapi2 target type of the target
/// @param[in] i_target const ref to the TARGET_TYPE_OCMB_CHIP
/// @param[in] i_value value to set
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
//TODO: Remove this once we have auto-generated attr setters
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode set_volt_vpp(const fapi2::Target<T>& i_target, uint32_t i_value)
{
    const auto l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MEM_EFF_VOLT_VPP, l_ocmb, i_value) );
    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR("failed setting ATTR_MEM_EFF_VOLT_VPP: 0x%lx (target: %s)",
             uint64_t(fapi2::current_err), mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief Get whether the CS configuration should be tied (A0 == B0 A1 == B1)
///
/// @param[in] i_target MEM_PORT target
/// @param[in] o_cs_tied true/false whether CS configuration should be tied
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
inline fapi2::ReturnCode get_cs_tied(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, bool& o_cs_tied)
{
    o_cs_tied = false;

    bool l_four_rank_mode = false;
    bool l_dual_drop = false;

    uint8_t l_ranks_per_dimm[2] = {};
    uint8_t l_four_rank_mode_attr[2] = {};

    FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_target, l_ranks_per_dimm));
    l_dual_drop = (l_ranks_per_dimm[0] > 0 && l_ranks_per_dimm[1] > 0) ? true : false;

    FAPI_TRY(mss::attr::get_four_rank_mode(i_target, l_four_rank_mode_attr));
    l_four_rank_mode = (l_four_rank_mode_attr[0] == fapi2::ENUM_ATTR_MEM_EFF_FOUR_RANK_MODE_ENABLE);

    // This logic mirrors the logic for def_cs_tied in explorer.scom.initfile
    o_cs_tied = (!l_four_rank_mode && !l_dual_drop);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get the firwmare revision based upon the partition that was booted
/// @param[in] i_target OCMB_CHIP target
/// @param[out] o_fw_version the FW version that was booted
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
inline fapi2::ReturnCode get_booted_fw_version(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        uint32_t& o_fw_version)
{
    o_fw_version = 0;
    uint32_t l_partition = 0;

    FAPI_TRY(mss::attr::get_exp_fw_partition_id(i_target, l_partition));

    // If we're the A-side partion, grab the A-side value
    if(l_partition == fapi2::ENUM_ATTR_MSS_EXP_FW_PARTITION_ID_A)
    {
        return mss::attr::get_exp_fw_version_a(i_target, o_fw_version);
    }

    // Otherwise, return the B-side value
    return mss::attr::get_exp_fw_version_b(i_target, o_fw_version);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Gets if the given target has a quad encoded CS
/// @tparam TargetType T target type
/// @param[in] i_target the target
/// @param[out] o_is_quad_encoded_cs true if the part uses quad encoded CS otherwise false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note Used for the workaround to JIRA355 - quad encoded CS rank1/2 being swapped between IBM's logic and the DFI
///
template<fapi2::TargetType T>
fapi2::ReturnCode is_quad_encoded_cs(const fapi2::Target<T>& i_target,
                                     bool& o_is_quad_encoded_cs);

} // ns mss

#endif
