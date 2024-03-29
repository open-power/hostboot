/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/plug_rules/plug_rules.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file plug_rules.H
/// @brief Generic plug rules enforcement based upon MC types
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _PLUG_RULES_H_
#define _PLUG_RULES_H_

#include <fapi2.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <generic/memory/lib/utils/memory_size.H>

namespace mss
{
namespace plug_rule
{
///
/// @brief Plug rule helper for no mixing DIMM size
/// @tparam MC mss::mc_type, the memory controller type
/// @param[in] i_target omic target
/// @param[in] i_ocmbs a vector of OCMB_CHIPs plugged into target
/// @param[in] i_ignore_dimm_size_mix_plug_rule a uint8_t plug rule var
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will commit error logs representing the mixing failure and make UT'ing the attr easy
///
template< mss::mc_type MC >
fapi2::ReturnCode dimm_size_mixing_helper(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>>& i_ocmbs,
        const uint8_t i_ignore_dimm_size_mix_plug_rule)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    if(i_ignore_dimm_size_mix_plug_rule == fapi2::ENUM_ATTR_MEM_IGNORE_PLUG_RULES_DIMM_SIZE_MIX_YES)
    {
        FAPI_INF_NO_SBE("%s Attribute set to ignore DIMM size mixing plug rule checking", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // We know we should have more than one OCMB passed in
    const auto& l_ocmb0 = i_ocmbs[0];
    uint64_t l_size0 = 0;

    FAPI_TRY(mss::eff_memory_size<MC>(l_ocmb0, l_size0));

    // Loops through and compares against all the OCMBs
    for(const auto& l_ocmb : i_ocmbs)
    {
        uint64_t l_size = 0;
        FAPI_TRY(mss::eff_memory_size<MC>(l_ocmb, l_size));

        // Check for difference in size on the 2 OCMBs; if different then exit out with an error
        FAPI_ASSERT( (l_size <= l_size0),
                     fapi2::MSS_PLUG_RULES_INVALID_DIMM_SIZE_MIX()
                     .set_SMALLER_DIMM_TARGET(l_ocmb0)
                     .set_LARGER_DIMM_TARGET(l_ocmb)
                     .set_SMALLER_DIMM_SIZE(l_size0)
                     .set_LARGER_DIMM_SIZE(l_size)
                     .set_OMIC_TARGET(i_target),
                     "%s has two different sizes of DIMM installed of size %d  and of size %d. Cannot mix DIMM sizes on OMIC channel pair",
                     mss::c_str(i_target), l_size, l_size0 );

        FAPI_ASSERT( (l_size0 <= l_size),
                     fapi2::MSS_PLUG_RULES_INVALID_DIMM_SIZE_MIX()
                     .set_SMALLER_DIMM_TARGET(l_ocmb)
                     .set_LARGER_DIMM_TARGET(l_ocmb0)
                     .set_SMALLER_DIMM_SIZE(l_size)
                     .set_LARGER_DIMM_SIZE(l_size0)
                     .set_OMIC_TARGET(i_target),
                     "%s has two different sizes of DIMM installed of size %d and of size %d. Cannot mix DIMM sizes on OMIC channel pair",
                     mss::c_str(i_target), l_size0, l_size );
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Plug rule for no mixing DIMM size
/// @tparam MC mss::mc_type, the memory controller type
/// @param[in] i_target omic target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will commit error logs representing the mixing failure
///
template< mss::mc_type MC >
fapi2::ReturnCode dimm_size_mixing(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_ignore_dimm_size_mix_plug_rule = 0;
    constexpr uint8_t CHECK_DIMM_PER_OMIC = 2;

    const auto& l_ocmbs = mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // If there are one or fewer DIMM's, we can just get out.
    if (l_ocmbs.size() < CHECK_DIMM_PER_OMIC)
    {
        FAPI_INF_NO_SBE("Skipping DIMM size mixing plug rule check on %s because it doesn't have 2 DIMMS",
                        mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Get the ignore plug attr
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_IGNORE_PLUG_RULES_DIMM_SIZE_MIX, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                            l_ignore_dimm_size_mix_plug_rule) );

    // Helper function so that the attribute can be UT'ed
    FAPI_TRY(dimm_size_mixing_helper<MC>(i_target, l_ocmbs, l_ignore_dimm_size_mix_plug_rule));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Plug rule helper for no mixing DIMM height
/// @tparam MC mss::mc_type, the memory controller type
/// @param[in] i_target omic target
/// @param[in] i_kinds a vector of DIMMs plugged into target
/// @param[in] i_ignore_dimm_height_mix_plug_rule a uint8_t plug rule var
/// @param[in] i_mrw_height_plug_rule a uint8_t mrw plug rule var
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will commit error logs representing the mixing failure and make UT'ing the attrs easy
///
template< mss::mc_type MC >
fapi2::ReturnCode dimm_height_mixing_helper(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
        const std::vector<mss::dimm::kind<MC>>& i_kinds,
        const uint8_t i_ignore_dimm_height_mix_plug_rule,
        const uint8_t i_mrw_height_plug_rule)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Check for the height plug rule
    if(i_ignore_dimm_height_mix_plug_rule == fapi2::ENUM_ATTR_MEM_IGNORE_PLUG_RULES_DIMM_HEIGHT_MIX_YES)
    {
        FAPI_INF_NO_SBE("%s Attribute set to ignore DIMM height mixing plug rule checking", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Check for the mrw height plug rule
    if (i_mrw_height_plug_rule == fapi2::ENUM_ATTR_MSS_MRW_DIMM_HEIGHT_MIXING_POLICY_ALLOWED)
    {
        FAPI_INF_NO_SBE("%s System policy allows DIMM height mixing", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // We know we should have more than one DIMM passed in
    const auto& l_kind0 = i_kinds[0];

    // Loops through and compares against all the DIMM's
    for(const auto& l_kind : i_kinds)
    {
        // Check for difference in heights on the 2 DIMMs'; if different then exit out with an error
        FAPI_ASSERT( (l_kind.iv_module_height <= l_kind0.iv_module_height),
                     fapi2::MSS_PLUG_RULES_INVALID_DIMM_HEIGHT_MIX()
                     .set_SMALLER_DIMM_TARGET(l_kind0.iv_target)
                     .set_LARGER_DIMM_TARGET(l_kind.iv_target)
                     .set_SMALLER_DIMM_HEIGHT(l_kind0.iv_module_height)
                     .set_LARGER_DIMM_HEIGHT(l_kind.iv_module_height)
                     .set_OMIC_TARGET(i_target),
                     "%s has two different heights of DIMM installed of height %d  and of height %d. Cannot mix DIMM height on OMIC channel pair",
                     mss::c_str(i_target), l_kind.iv_module_height, l_kind0.iv_module_height );

        FAPI_ASSERT( (l_kind0.iv_module_height <= l_kind.iv_module_height),
                     fapi2::MSS_PLUG_RULES_INVALID_DIMM_HEIGHT_MIX()
                     .set_SMALLER_DIMM_TARGET(l_kind.iv_target)
                     .set_LARGER_DIMM_TARGET(l_kind0.iv_target)
                     .set_SMALLER_DIMM_HEIGHT(l_kind.iv_module_height)
                     .set_LARGER_DIMM_HEIGHT(l_kind0.iv_module_height)
                     .set_OMIC_TARGET(i_target),
                     "%s has two different heights of DIMM installed of height %d and of height %d. Cannot mix DIMM height on OMIC channel pair",
                     mss::c_str(i_target), l_kind0.iv_module_height, l_kind.iv_module_height );
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Plug rule for no mixing DIMM height
/// @tparam MC mss::mc_type, the memory controller type
/// @param[in] i_target omic target
/// @param[in] i_kinds a vector of DIMMs plugged into target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will commit error logs representing the mixing failure
///
template< mss::mc_type MC >
fapi2::ReturnCode dimm_height_mixing(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                                     const std::vector<mss::dimm::kind<MC>>& i_kinds)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_ignore_dimm_height_mix_plug_rule = 0;
    uint8_t l_mrw_height_plug_rule = 0;
    constexpr uint8_t CHECK_DIMM_PER_OMIC = 2;

    // If there are one or fewer DIMM's, we can just get out.
    if (i_kinds.size() < CHECK_DIMM_PER_OMIC)
    {
        FAPI_INF_NO_SBE("Skipping DIMM height mixing plug rule check on %s because it doesn't have 2 DIMMS",
                        mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Get the ignore plug attr
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_IGNORE_PLUG_RULES_DIMM_HEIGHT_MIX, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                            l_ignore_dimm_height_mix_plug_rule) );

    // Get the MRW ignore plug rule attr
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_DIMM_HEIGHT_MIXING_POLICY, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_mrw_height_plug_rule));

    // Helper function so that the attributes can be UT'ed
    FAPI_TRY(dimm_height_mixing_helper(i_target, i_kinds, l_ignore_dimm_height_mix_plug_rule, l_mrw_height_plug_rule));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Plug rule helper for not allowing DDR5 DIMM's to be plugged
/// @tparam MC mss::mc_type, the memory controller type
/// @param[in] i_target omic target
/// @param[in] i_kinds a vector of DIMMs plugged into target
/// @param[in] i_mrw_allow_ddr5 MRW attribute value noting if DDR5 is allowed
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will commit error logs representing the mixing failure and make UT'ing the attrs easy
///
template< mss::mc_type MC >
fapi2::ReturnCode ddr5_allowed_helper(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                                      const std::vector<mss::dimm::kind<MC>>& i_kinds,
                                      const uint8_t i_mrw_allow_ddr5)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    // Check for the DDR5 allowed plug rule
    if(i_mrw_allow_ddr5 == fapi2::ENUM_ATTR_MSS_MRW_ALLOW_DDR5_ALLOW)
    {
        FAPI_INF_NO_SBE("%s Attribute set to allow DDR5, skipping check", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Loops through and compares against all the DIMM's
    for(const auto& l_kind : i_kinds)
    {
        // Check for DDR5 DIMM's; if DDR5 is found, then exit out with an error
        FAPI_ASSERT( (l_kind.iv_dram_generation != fapi2::ENUM_ATTR_MEM_EFF_DRAM_GEN_DDR5),
                     fapi2::MSS_PLUG_RULES_DDR5_NOT_SUPPORTED()
                     .set_DIMM_TARGET(l_kind.iv_target),
                     "%s is a DDR5 DIMM and DDR5 is not allowed on this system",
                     mss::c_str(l_kind.iv_target));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Plug rule for not allowing DDR5 DIMM's to be plugged
/// @tparam MC mss::mc_type, the memory controller type
/// @param[in] i_target omic target
/// @param[in] i_kinds a vector of DIMMs plugged into target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will commit error logs representing the mixing failure
///
template< mss::mc_type MC >
fapi2::ReturnCode ddr5_allowed(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                               const std::vector<mss::dimm::kind<MC>>& i_kinds)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_mrw_ddr5_allowed = 0;

    // Get the attribute that notes if DDR5 is allowed or not
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_ALLOW_DDR5, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                            l_mrw_ddr5_allowed) );

    // Helper function so that the attributes can be UT'ed
    FAPI_TRY(ddr5_allowed_helper(i_target, i_kinds, l_mrw_ddr5_allowed));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Plug rule helper for not allowing any DRAM generation mixing
/// @tparam MC mss::mc_type, the memory controller type
/// @param[in] i_kinds a vector of DIMMs plugged into target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will commit error logs representing the mixing failure
///
template< mss::mc_type MC >
fapi2::ReturnCode dram_gen_mixing_helper(const std::vector<mss::dimm::kind<MC>>& i_kinds)
{
    // One or fewer DIMM's? then we pass this check automatically
    constexpr uint64_t CHECK_REQUIRED = 2;

    if(i_kinds.size() < CHECK_REQUIRED)
    {
        FAPI_INF_NO_SBE("Fewer than 2 DIMM's found, no need to check for DRAM generation mixing");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // We know we should have more than one DIMM passed in
    const auto& l_kind0 = i_kinds[0];

    // Loops through and compares against all the DIMM's
    for(const auto& l_kind : i_kinds)
    {
        // Check for difference in DRAM generations on the 2 DIMMs'; if different then exit out with an error
        FAPI_ASSERT( (l_kind.iv_dram_generation == l_kind0.iv_dram_generation),
                     fapi2::MSS_PLUG_RULES_DRAM_GENERATION_MIXING_NOT_SUPPORTED()
                     .set_DIMM_TARGET(l_kind.iv_target)
                     .set_FIRST_DRAM_GEN(l_kind0.iv_dram_generation)
                     .set_THIS_DRAM_GEN(l_kind.iv_dram_generation),
                     "%s has two different DRAM generations this:%d vs first dimm:%d. Cannot mix DRAM generations on a system planar",
                     mss::c_str(l_kind.iv_target), l_kind.iv_dram_generation, l_kind0.iv_dram_generation );
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Plug rule for not allowing any DRAM generation mixing
/// @tparam MC mss::mc_type, the memory controller type
/// @param[in] i_targets vector of FAPI2 targets (ocmb_chip)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note This function will commit error logs representing the mixing failure
///
template< mss::mc_type MC >
fapi2::ReturnCode dram_gen_mixing(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>>& i_targets)
{
    std::vector<mss::dimm::kind<MC>> l_kinds;

    for(const auto& l_ocmb : i_targets)
    {
        for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_ocmb))
        {
            fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
            mss::dimm::kind<MC> l_kind(l_dimm, l_rc);
            FAPI_TRY(l_rc, "%s Failed to create dimm::kind instance", mss::c_str(l_dimm));
            l_kinds.push_back(l_kind);
        }
    }

    // Helper function so that the attributes can be UT'ed
    FAPI_TRY(dram_gen_mixing_helper(l_kinds));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enforce the plug-rules we can do at the beginning of eff_config_thermal
/// @tparam MC mss::mc_type, the memory controller type
/// @param[in] i_target FAPI2 target (ocmb_chip)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
template< mss::mc_type MC >
fapi2::ReturnCode enforce_pre_eff_config_thermal(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    const auto& l_omic = mss::find_target<fapi2::TARGET_TYPE_OMIC>(mss::find_target<fapi2::TARGET_TYPE_OMI>(i_target));

    uint8_t l_ignore_plug_rules = 0;

    // Get vector of l_kinds
    std::vector<mss::dimm::kind<MC>> l_kinds;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_IGNORE_PLUG_RULES, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                            l_ignore_plug_rules) );

    // Skip all plug rule checks if set to ignore (e.g. on Apollo)
    if (l_ignore_plug_rules == fapi2::ENUM_ATTR_MEM_IGNORE_PLUG_RULES_YES)
    {
        FAPI_INF_NO_SBE("%s Attribute set to ignore plug rule checking", mss::c_str(i_target));
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
                mss::dimm::kind<MC> l_kind(l_dimm, l_rc);
                FAPI_TRY(l_rc, "%s Failed to create dimm::kind instance", mss::c_str(l_dimm));
                l_kinds.push_back(l_kind);
            }
        }
    }


    // Checking the plug rule for dimm size mix
    FAPI_TRY( dimm_size_mixing<MC>( l_omic ) );

    // Checking the plug rule for dimm height mix
    FAPI_TRY( dimm_height_mixing<MC>( l_omic, l_kinds ) );

    // Check if any DDR5 DIMM's are plugged
    FAPI_TRY( ddr5_allowed<MC>( l_omic, l_kinds ) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enforce the plug-rules we can do at the beginning of eff_config_thermal
/// @tparam MC mss::mc_type, the memory controller type
/// @param[in] i_targets vector of FAPI2 targets (ocmb_chip)
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
template< mss::mc_type MC >
fapi2::ReturnCode enforce_pre_eff_config_thermal(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>>&
        i_targets)
{
    uint8_t l_ignore_plug_rules = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_IGNORE_PLUG_RULES, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                            l_ignore_plug_rules) );

    // Skip all plug rule checks if set to ignore (e.g. on Apollo)
    if (l_ignore_plug_rules == fapi2::ENUM_ATTR_MEM_IGNORE_PLUG_RULES_YES)
    {
        FAPI_INF_NO_SBE("Attribute set to ignore plug rule checking");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    for(const auto& l_ocmb : i_targets)
    {
        FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Running enforce_pre_eff_config_thermal ", GENTARGTID(l_ocmb));
        FAPI_TRY(enforce_pre_eff_config_thermal<MC>(l_ocmb),
                 GENTARGTIDFORMAT " Fail encountered in enforce_pre_eff_config_thermal", GENTARGTID(l_ocmb));
    }

    // Check if any DRAM technology generations are mixed
    FAPI_TRY( dram_gen_mixing<MC>(i_targets) );


fapi_try_exit:
    return fapi2::current_err;
}

} // plug_rule
} // mss

#endif
