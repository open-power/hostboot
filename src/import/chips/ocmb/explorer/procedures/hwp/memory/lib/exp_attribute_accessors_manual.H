/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_attribute_accessors_manual.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#include <generic/memory/lib/utils/c_str.H>

namespace mss
{

///
/// @brief Gets whether the OCMB will be configred to enterprise mode
/// @param[in] i_target OCMB target on which to operate
/// @param[out] o_is_enterprise_mode true if the part is in enterprise mode
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
inline fapi2::ReturnCode enterprise_mode( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        bool& o_is_enterprise_mode )
{
    // Constexprs for beautification
    constexpr uint8_t ENTERPRISE = fapi2::ENUM_ATTR_MSS_OCMB_ENTERPRISE_MODE_ENTERPRISE;
    constexpr uint8_t NO_OVERRIDE = fapi2::ENUM_ATTR_MSS_OCMB_NONENTERPRISE_MODE_OVERRIDE_NO_OVERRIDE;

    // Variables
    o_is_enterprise_mode = false;
    uint8_t l_enterprise = 0;
    uint8_t l_override = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_ENTERPRISE_MODE, i_target, l_enterprise) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_NONENTERPRISE_MODE_OVERRIDE, i_target, l_override) );

    {
        const bool l_enterprise_mode = l_enterprise == ENTERPRISE;
        const bool l_no_override = l_override == NO_OVERRIDE;
        // We will be in enterprise mode (true) IF
        // 1) the chip is in enterprise mode (we can't run in enterprise mode if the part is non-enterprise capable) AND
        // 2) we do not have the override to non-enterprise mode
        o_is_enterprise_mode = l_enterprise_mode && l_no_override;

        FAPI_INF("%s is in %s mode chip is %s override is %s", mss::c_str(i_target),
                 o_is_enterprise_mode ? "enterprise" : "non-enterprise", l_enterprise_mode ? "enterprise" : "non-enterprise",
                 l_no_override ? "no override" : "override to non-enterprise");
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets whether the OCMB will be configured to half-DIMM mode
/// @param[in] i_target OCMB target on which to operate
/// @param[out] o_is_half_dimm_mode true if the part is in half-DIMM mode
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
inline fapi2::ReturnCode half_dimm_mode( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        bool& o_is_half_dimm_mode )
{
    // Variables
    o_is_half_dimm_mode = false;
    bool l_is_enterprise = false;
    uint8_t l_half_dimm = 0;
    uint8_t l_override = 0;

    FAPI_TRY( enterprise_mode(i_target, l_is_enterprise) );

    // We're in full DIMM mode if we're in non-enterprise mode
    if(!l_is_enterprise)
    {
        o_is_half_dimm_mode = false;
        FAPI_INF("%s is in full-DIMM as the chip is in non-enterprise mode", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Now that we're not in enterprise mode, check for overrides
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_HALF_DIMM_MODE_OVERRIDE, i_target, l_override) );

    // If we have an override, set based upon the override
    if(l_override != fapi2::ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_OVERRIDE_NO_OVERRIDE)
    {
        o_is_half_dimm_mode = l_override == fapi2::ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_OVERRIDE_OVERRIDE_HALF_DIMM;
        FAPI_INF("%s is in enterprise mode %s override is present. The chip is in %s (attribute %u)", mss::c_str(i_target),
                 "an", o_is_half_dimm_mode ? "half-DIMM mode" : "full-DIMM mode", l_override);
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // No override, so go with the attribute derived from the ECID
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_HALF_DIMM_MODE, i_target, l_half_dimm) );

    // Set half DIMM mode based upon the the normal attribute
    o_is_half_dimm_mode = l_half_dimm == fapi2::ENUM_ATTR_MSS_OCMB_HALF_DIMM_MODE_HALF_DIMM;
    FAPI_INF("%s is in enterprise mode %s override is present. The chip is in %s (attribute %u)", mss::c_str(i_target),
             "no", o_is_half_dimm_mode ? "half-DIMM mode" : "full-DIMM mode", l_half_dimm);

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss

#endif
