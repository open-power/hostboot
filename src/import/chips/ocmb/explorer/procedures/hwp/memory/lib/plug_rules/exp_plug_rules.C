/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/plug_rules/exp_plug_rules.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file exp_plug_rules.C
/// @brief Plug rules enforcement for explorer
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/plug_rules/exp_plug_rules.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/count_dimm.H>

namespace mss
{
namespace exp
{
namespace plug_rule
{

///
/// @brief Determine enterprise mode from given attribute/fuse values
///
/// @param[in] i_target OCMB chip target
/// @param[in] i_enterprise_fuse enterprise as determined from fuse
/// @param[in] i_enterprise_policy enterprise policy system attribute value
/// @param[in] i_non_enterprise_override override attribute value
/// @param[out] o_is_enterprise_mode resulting state for enterprise mode
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
/// @note this helper function exists for unit testing purposes
///
fapi2::ReturnCode enterprise_mode_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const bool i_enterprise_fuse,
    const uint8_t i_enterprise_policy,
    const uint8_t i_non_enterprise_override,
    bool& o_is_enterprise_mode)
{
    o_is_enterprise_mode = false;

    // Constexprs to make things easier on the eyes
    constexpr uint8_t REQUIRE_ENTERPRISE = fapi2::ENUM_ATTR_MSS_OCMB_ENTERPRISE_POLICY_REQUIRE_ENTERPRISE;
    constexpr uint8_t FORCE_NONENTERPRISE = fapi2::ENUM_ATTR_MSS_OCMB_ENTERPRISE_POLICY_FORCE_NONENTERPRISE;

    // Truth table:
    // Enterprise (fuse): 0=Disabled 1=Enabled (inverted from fuse logic)
    // Policy: 0=ALLOW_ENTERPRISE (allow any) 1=REQUIRE_ENTERPRISE 2=FORCE_NONENTERPRISE
    // Override OFF: 0=NO_OVERRIDE 1=OVERRIDE_TO_NONENTERPRISE
    //
    // Enterprise (fuse)  Policy  Override OFF  Result  Description
    // 0                  0       0             0
    // 0                  0       1             0
    // 1                  0       0             1
    // 1                  0       1             0
    // 0                  1       0             Error:  We don't support enterprise
    // 0                  1       1             Error:  We don't support enterprise
    // 1                  1       0             1
    // 1                  1       1             0       Override beats policy
    // 0                  2       0             0
    // 0                  2       1             0
    // 1                  2       0             Error:  Policy does not allow for enterprise dimm plugged in
    // 1                  2       1             Error:  Policy does not allow for enterprise dimm plugged in

    // Check if we have one of the error configurations
    const bool l_invalid_config = ((!i_enterprise_fuse) && (i_enterprise_policy == REQUIRE_ENTERPRISE)) ||
                                  ((i_enterprise_fuse) && (i_enterprise_policy == FORCE_NONENTERPRISE));

    // For the below assert, i_enterprise_policy must be 1 or 2 to assert out,
    // so we can use the ternary operator to generate a string description from these two cases
    FAPI_ASSERT(!l_invalid_config,
                fapi2::MSS_EXP_ENTERPRISE_INVALID_CONFIGURATION()
                .set_OCMB_TARGET(i_target)
                .set_ENTERPRISE_SUPPORTED(i_enterprise_fuse)
                .set_POLICY(i_enterprise_policy),
                "%s The enterprise supported bit from the Explorer efuse: %u conflicts with the enterprise "
                "policy attribute setting: %s",
                mss::c_str(i_target),
                i_enterprise_fuse,
                (i_enterprise_policy == FORCE_NONENTERPRISE ? "FORCE_NONENTERPRISE" : "REQUIRE_ENTERPRISE"));

    // Now generate the resulting value from the remaining truth table entries
    // We are non-enterprise whenever i_enterprise_policy is 2, or i_non_enterprise_override.
    // Otherwise, we use the value of i_enterprise_fuse
    o_is_enterprise_mode = i_enterprise_fuse && !((i_enterprise_policy == FORCE_NONENTERPRISE)
                           || (i_non_enterprise_override));

    FAPI_INF("%s is in %s mode. (OCMB chip is %s, with %s)",
             mss::c_str(i_target),
             o_is_enterprise_mode ? "enterprise" : "non-enterprise",
             i_enterprise_fuse ? "enterprise" : "non-enterprise",
             i_non_enterprise_override ? "override to non-enterprise" : "no override");

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets whether the OCMB will be configred to enterprise mode, will assert out if policy/override do not agree
/// @param[in] i_target OCMB target on which to operate
/// @param[in] i_enterprise_fuse enterprise as determined from fuse
/// @param[out] o_is_enterprise_mode true if the part is in enterprise mode
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode enterprise_mode(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const bool i_enterprise_fuse,
    bool& o_is_enterprise_mode )
{
    o_is_enterprise_mode = false;

    // Variables
    uint8_t l_enterprise_policy = 0;
    uint8_t l_override_attr = 0;

    FAPI_TRY( mss::attr::get_ocmb_enterprise_policy(l_enterprise_policy) );
    FAPI_TRY( mss::attr::get_ocmb_nonenterprise_mode_override(i_target, l_override_attr) );

    // This function will populate o_is_enterprise_mode accordingly
    FAPI_TRY(enterprise_mode_helper(i_target, i_enterprise_fuse, l_enterprise_policy, l_override_attr,
                                    o_is_enterprise_mode));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Plug rule helper for no mixing DIMM size
/// @param[in] i_target omic target
/// @param[in] i_kinds a vector of DIMMs plugged into target
/// @param[in] i_ignore_dimm_size_mix_plug_rule a uint8_t plug rule var
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will commit error logs representing the mixing failure and make UT'ing the attr easy
///
fapi2::ReturnCode dimm_size_mixing_helper(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
        const std::vector<mss::dimm::kind<mss::mc_type::EXPLORER>>& i_kinds,
        const uint8_t i_ignore_dimm_size_mix_plug_rule)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    if(i_ignore_dimm_size_mix_plug_rule == fapi2::ENUM_ATTR_MEM_IGNORE_PLUG_RULES_DIMM_SIZE_MIX_YES)
    {
        FAPI_INF("%s Attribute set to ignore DIMM size mixing plug rule checking", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Check for difference in size on the 2 DIMMs'; if different then exit out with an error
    FAPI_ASSERT( (i_kinds[1].iv_size <= i_kinds[0].iv_size),
                 fapi2::MSS_PLUG_RULES_INVALID_DIMM_SIZE_MIX()
                 .set_SMALLER_DIMM_TARGET(i_kinds[0].iv_target)
                 .set_LARGER_DIMM_TARGET(i_kinds[1].iv_target)
                 .set_SMALLER_DIMM_SIZE(i_kinds[0].iv_size)
                 .set_LARGER_DIMM_SIZE(i_kinds[1].iv_size)
                 .set_OMIC_TARGET(i_target),
                 "%s has two different sizes of DIMM installed of size %d  and of size %d. Cannot mix DIMM sizes on OMIC channel pair",
                 mss::c_str(i_target), i_kinds[1].iv_size, i_kinds[0].iv_size );

    FAPI_ASSERT( (i_kinds[0].iv_size <= i_kinds[1].iv_size),
                 fapi2::MSS_PLUG_RULES_INVALID_DIMM_SIZE_MIX()
                 .set_SMALLER_DIMM_TARGET(i_kinds[1].iv_target)
                 .set_LARGER_DIMM_TARGET(i_kinds[0].iv_target)
                 .set_SMALLER_DIMM_SIZE(i_kinds[1].iv_size)
                 .set_LARGER_DIMM_SIZE(i_kinds[0].iv_size)
                 .set_OMIC_TARGET(i_target),
                 "%s has two different sizes of DIMM installed of size %d and of size %d. Cannot mix DIMM sizes on OMIC channel pair",
                 mss::c_str(i_target), i_kinds[0].iv_size, i_kinds[1].iv_size );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Plug rule for no mixing DIMM size
/// @param[in] i_target omic target
/// @param[in] i_kinds a vector of DIMMs plugged into target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will commit error logs representing the mixing failure
///
fapi2::ReturnCode dimm_size_mixing(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                                   const std::vector<mss::dimm::kind<mss::mc_type::EXPLORER>>& i_kinds)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_ignore_dimm_size_mix_plug_rule = 0;
    constexpr uint8_t MAX_DIMM_PER_OMIC = 2;

    // If there are one or fewer DIMM's, we can just get out.
    if (i_kinds.size() < MAX_DIMM_PER_OMIC)
    {
        FAPI_INF("Skipping DIMM size mixing plug rule check on %s because it doesn't have 2 DIMMS", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Get the ignore plug attr
    FAPI_TRY( mss::attr::get_ignore_mem_plug_rules_dimm_size_mix(l_ignore_dimm_size_mix_plug_rule) );

    // Helper function so that the attribute can be UT'ed
    FAPI_TRY(dimm_size_mixing_helper(i_target, i_kinds, l_ignore_dimm_size_mix_plug_rule));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Plug rule helper for no mixing DIMM height
/// @param[in] i_target omic target
/// @param[in] i_kinds a vector of DIMMs plugged into target
/// @param[in] i_ignore_dimm_height_mix_plug_rule a uint8_t plug rule var
/// @param[in] i_mrw_height_plug_rule a uint8_t mrw plug rule var
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will commit error logs representing the mixing failure and make UT'ing the attrs easy
///
fapi2::ReturnCode dimm_height_mixing_helper(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
        const std::vector<mss::dimm::kind<mss::mc_type::EXPLORER>>& i_kinds,
        const uint8_t i_ignore_dimm_height_mix_plug_rule,
        const uint8_t i_mrw_height_plug_rule)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Check for the height plug rule
    if(i_ignore_dimm_height_mix_plug_rule == fapi2::ENUM_ATTR_MEM_IGNORE_PLUG_RULES_DIMM_HEIGHT_MIX_YES)
    {
        FAPI_INF("%s Attribute set to ignore DIMM height mixing plug rule checking", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Check for the mrw height plug rule
    if (i_mrw_height_plug_rule == fapi2::ENUM_ATTR_MSS_MRW_DIMM_HEIGHT_MIXING_POLICY_ALLOWED)
    {
        FAPI_INF("%s System policy allows DIMM height mixing", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Check for difference in heights on the 2 DIMMs'; if different then exit out with an error
    FAPI_ASSERT( (i_kinds[1].iv_module_height <= i_kinds[0].iv_module_height),
                 fapi2::MSS_PLUG_RULES_INVALID_DIMM_HEIGHT_MIX()
                 .set_SMALLER_DIMM_TARGET(i_kinds[0].iv_target)
                 .set_LARGER_DIMM_TARGET(i_kinds[1].iv_target)
                 .set_SMALLER_DIMM_HEIGHT(i_kinds[0].iv_module_height)
                 .set_LARGER_DIMM_HEIGHT(i_kinds[1].iv_module_height)
                 .set_OMIC_TARGET(i_target),
                 "%s has two different heights of DIMM installed of height %d  and of height %d. Cannot mix DIMM height on OMIC channel pair",
                 mss::c_str(i_target), i_kinds[1].iv_module_height, i_kinds[0].iv_module_height );

    FAPI_ASSERT( (i_kinds[0].iv_module_height <= i_kinds[1].iv_module_height),
                 fapi2::MSS_PLUG_RULES_INVALID_DIMM_HEIGHT_MIX()
                 .set_SMALLER_DIMM_TARGET(i_kinds[1].iv_target)
                 .set_LARGER_DIMM_TARGET(i_kinds[0].iv_target)
                 .set_SMALLER_DIMM_HEIGHT(i_kinds[1].iv_module_height)
                 .set_LARGER_DIMM_HEIGHT(i_kinds[0].iv_module_height)
                 .set_OMIC_TARGET(i_target),
                 "%s has two different heights of DIMM installed of height %d and of height %d. Cannot mix DIMM height on OMIC channel pair",
                 mss::c_str(i_target), i_kinds[0].iv_module_height, i_kinds[1].iv_module_height );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Plug rule for no mixing DIMM height
/// @param[in] i_target omic target
/// @param[in] i_kinds a vector of DIMMs plugged into target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will commit error logs representing the mixing failure
///
fapi2::ReturnCode dimm_height_mixing(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                                     const std::vector<mss::dimm::kind<mss::mc_type::EXPLORER>>& i_kinds)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_ignore_dimm_height_mix_plug_rule = 0;
    uint8_t l_mrw_height_plug_rule = 0;
    constexpr uint8_t MAX_DIMM_PER_OMIC = 2;

    // If there are one or fewer DIMM's, we can just get out.
    if (i_kinds.size() < MAX_DIMM_PER_OMIC)
    {
        FAPI_INF("Skipping DIMM height mixing plug rule check on %s because it doesn't have 2 DIMMS", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Get the ignore plug attr
    FAPI_TRY( mss::attr::get_ignore_mem_plug_rules_dimm_height_mix(l_ignore_dimm_height_mix_plug_rule) );

    // Get the MRW ignore plug rule attr
    FAPI_TRY(mss::attr::get_mrw_dimm_height_plug_rule(l_mrw_height_plug_rule));

    // Helper function so that the attributes can be UT'ed
    FAPI_TRY(dimm_height_mixing_helper(i_target, i_kinds, l_ignore_dimm_height_mix_plug_rule, l_mrw_height_plug_rule));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enforce the plug-rules we can do at the beginning of eff_config_thermal
/// @param[in] i_target FAPI2 target (ocmb_chip)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode enforce_pre_eff_config_thermal(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    const auto& l_omic = mss::find_target<fapi2::TARGET_TYPE_OMIC>(mss::find_target<fapi2::TARGET_TYPE_OMI>(i_target));

    uint8_t l_ignore_plug_rules = 0;

    // Get vector of l_kinds
    std::vector<mss::dimm::kind<mss::mc_type::EXPLORER>> l_kinds;

    FAPI_TRY( mss::attr::get_ignore_mem_plug_rules(l_ignore_plug_rules) );

    // Skip all plug rule checks if set to ignore (e.g. on Apollo)
    if (l_ignore_plug_rules == fapi2::ENUM_ATTR_MEM_IGNORE_PLUG_RULES_YES)
    {
        FAPI_INF("%s Attribute set to ignore plug rule checking", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }


    // Get the vector of DIMMS to be checked for size
    for (const auto& l_omi : mss::find_targets<fapi2::TARGET_TYPE_OMI>(l_omic))
    {
        for (const auto& l_ocmb : mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(l_omi))
        {
            for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_ocmb))
            {
                fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
                mss::dimm::kind<mss::mc_type::EXPLORER> l_kind(l_dimm, l_rc);
                FAPI_TRY(l_rc, "%s Failed to create dimm::kind instance", mss::c_str(l_dimm));
                l_kinds.push_back(l_kind);
            }
        }
    }


    // Checking the plug rule for dimm size mix
    FAPI_TRY( dimm_size_mixing( l_omic, l_kinds ) );

    // Checking the plug rule for dimm height mix
    FAPI_TRY( dimm_height_mixing( l_omic, l_kinds ) );

fapi_try_exit:
    return fapi2::current_err;
}

} // plug_rule
} // exp
} // mss
