/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/plug_rules/exp_plug_rules.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
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

} // plug_rule
} // exp
} // mss
