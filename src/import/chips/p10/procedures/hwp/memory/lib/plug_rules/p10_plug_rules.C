/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/plug_rules/p10_plug_rules.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file p10_plug_rules.C
/// @brief Enforcement of rules for plugging in DIMM
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <lib/shared/p10_consts.H>
#include <algorithm>

#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/num.H>
#include <mss_generic_attribute_getters.H>

#include <fapi2.H>
#include <lib/plug_rules/p10_plug_rules.H>
#include <lib/plug_rules/exp_spd_keys_supported_map.H>

namespace mss
{

namespace plug_rule
{

///
/// @brief Target based constructor
/// @param[in] i_target the DIMM target on which to operate
/// @param[out] o_rc SUCCESS if the function passes
/// @note Reads in the attributes
///
spd_lookup_key::spd_lookup_key(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc)
{
    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
    FAPI_TRY( mss::attr::get_module_mfg_id(i_target, iv_module_mfg_id) );
    FAPI_TRY( mss::attr::get_dram_module_height(l_ocmb, iv_dimm_height) );
    FAPI_TRY( mss::attr::get_dimm_size(i_target, iv_dimm_size) );

fapi_try_exit:
    o_rc = fapi2::current_err;
}

///
/// @brief Target based constructor
/// @param[in] i_module_mfg_id the module manufacturing ID
/// @param[in] i_dimm_height the DIMM height (1U, 2U, 4U)
/// @param[in] i_dimm_size the DIMM size in question (16GB, 32GB, etc)
/// @note Used to create the lookup table
///
spd_lookup_key::spd_lookup_key(const uint16_t i_module_mfg_id,
                               const uint8_t i_dimm_height,
                               const uint32_t i_dimm_size) :
    iv_module_mfg_id(i_module_mfg_id),
    iv_dimm_height(i_dimm_height),
    iv_dimm_size(i_dimm_size)
{}

///
/// @brief Less than comparison operator
/// @param[in] i_rhs the value to compare against
/// @return true if this spd_lookup_key is less than i_rhs
///
bool spd_lookup_key::operator<(const spd_lookup_key& i_rhs) const
{
    if(iv_module_mfg_id != i_rhs.iv_module_mfg_id)
    {
        return iv_module_mfg_id < i_rhs.iv_module_mfg_id;
    }

    if(iv_dimm_height != i_rhs.iv_dimm_height)
    {
        return iv_dimm_height < i_rhs.iv_dimm_height;
    }

    return iv_dimm_size < i_rhs.iv_dimm_size;
}

///
/// @brief Not equal to comparison operator
/// @param[in] i_rhs the value to compare against
/// @return true if this spd_lookup_key is not equal to i_rhs
///
bool spd_lookup_key::operator!=(const spd_lookup_key& i_rhs) const
{
    return iv_module_mfg_id != i_rhs.iv_module_mfg_id ||
           iv_dimm_height != i_rhs.iv_dimm_height ||
           iv_dimm_size != i_rhs.iv_dimm_size;
}

///
/// @brief Enforce the plug-rules we can do after eff_config
/// @param[in] i_target FAPI2 target (port)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode enforce_post_eff_config(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    uint8_t l_ignore_plug_rules = 0;

    // If there are no DIMM, we can just get out.
    if (mss::count_dimm(i_target) == 0)
    {
        FAPI_INF("Skipping plug rule check on %s because it has no DIMM configured", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY( mss::attr::get_ignore_mem_plug_rules(l_ignore_plug_rules) );

    // Skip plug rule checks if set to ignore (e.g. on Apollo)
    if (l_ignore_plug_rules == fapi2::ENUM_ATTR_MEM_IGNORE_PLUG_RULES_YES)
    {
        FAPI_INF("%s Attribute set to ignore plug rule checking", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Check SPD revision limits
    FAPI_TRY( ddimm_spd_revision(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

namespace check
{

///
/// @brief Check that we recognize SPD lookup key and return the SPD versions associated with the key
/// @param[in] i_target dimm target
/// @param[in] i_key the SPD lookup key to be used to grab the combined revisions
/// @param[out] o_minimum_combined_rev minimum SPD combined revisions
/// @param[out] o_latest_combined_rev latest SPD combined revisions
/// @return fapi2::FAPI2_RC_SUCCESS if okay. A non-SUCCESS return will also produce an informational log
///
fapi2::ReturnCode spd_revision_key(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const spd_lookup_key& i_key,
                                   uint16_t& o_minimum_combined_rev,
                                   uint16_t& o_latest_combined_rev)
{
    // Check that we can find the ID in our latest revision list
    FAPI_ASSERT( mss::find_value_from_key(MINIMUM_SPD_KEY_COMBINED_REV, i_key, o_minimum_combined_rev),
                 fapi2::MSS_UNKNOWN_DIMM_SPD_KEY()
                 .set_DIMM_TARGET(i_target)
                 .set_MODULE_MFG_ID(i_key.iv_module_mfg_id)
                 .set_DIMM_HEIGHT(i_key.iv_dimm_height)
                 .set_DIMM_SIZE(i_key.iv_dimm_size),
                 "%s DDIMM has unrecognized key MFG_ID:0x%04X Height:%u Size:%u for minimum SPD rev",
                 mss::c_str(i_target), i_key.iv_module_mfg_id, i_key.iv_dimm_height, i_key.iv_dimm_size );

    FAPI_ASSERT( mss::find_value_from_key(LATEST_SPD_KEY_COMBINED_REV, i_key, o_latest_combined_rev),
                 fapi2::MSS_UNKNOWN_DIMM_SPD_KEY()
                 .set_DIMM_TARGET(i_target)
                 .set_MODULE_MFG_ID(i_key.iv_module_mfg_id)
                 .set_DIMM_HEIGHT(i_key.iv_dimm_height)
                 .set_DIMM_SIZE(i_key.iv_dimm_size),
                 "%s DDIMM has unrecognized key MFG_ID:0x%04X Height:%u Size:%u for latest SPD rev",
                 mss::c_str(i_target), i_key.iv_module_mfg_id, i_key.iv_dimm_height, i_key.iv_dimm_size );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered - we want this error to be informational
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::RC_MSS_UNKNOWN_DIMM_SPD_KEY;
}

///
/// @brief Check DDIMM SPD revision and content revision versus minimum supported
/// @param[in] i_target dimm target
/// @param[in] i_spd_combined_revision the combined SPD revision and content
/// @param[in] i_min_combined_rev SPD minimum combined revision information
/// @return fapi2::FAPI2_RC_SUCCESS if okay. A non-SUCCESS return will also produce an informational log
/// @note The return code from this function is only used in unit tests.
///
fapi2::ReturnCode spd_minimum_combined_revision(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint16_t i_spd_combined_rev,
        const uint16_t i_min_combined_rev)
{

    // Check the combined revision
    FAPI_ASSERT( i_spd_combined_rev >= i_min_combined_rev,
                 fapi2::MSS_UNSUPPORTED_SPD_COMBINED_REVISION()
                 .set_DIMM_TARGET(i_target)
                 .set_SPD_COMBINED_REVISION(i_spd_combined_rev)
                 .set_MINIMUM_FUNCTIONAL_SPD_COMBINED_REVISION(i_min_combined_rev),
                 "%s DDIMM has an unsupported SPD combined revision and needs to be updated (0x%04X < 0x%04X)",
                 mss::c_str(i_target), i_spd_combined_rev, i_min_combined_rev );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered - we want this error to be informational
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::RC_MSS_UNSUPPORTED_SPD_COMBINED_REVISION;
}

///
/// @brief Check DDIMM SPD revision and content revision versus latest supported
/// @param[in] i_target dimm target
/// @param[in] i_spd_combined_revision the combined SPD revision and content
/// @param[in] i_latest_combined_rev latest SPD combined revision information
/// @return fapi2::FAPI2_RC_SUCCESS if okay. A non-SUCCESS return will also produce an informational log
/// @note The return code from this function is only used in unit tests.
///
fapi2::ReturnCode spd_latest_combined_revision(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint16_t i_spd_combined_rev,
        const uint16_t i_latest_combined_rev)
{
    // Check the combined revision
    if(i_spd_combined_rev < i_latest_combined_rev)
    {
        // For the lab, we just want to log these as informational errors
#ifndef __HOSTBOOT_MODULE
        FAPI_INF("%s DDIMM has non-current SPD combined revision and could be updated (0x%04X < 0x%04X)",
                 mss::c_str(i_target), i_spd_combined_rev, i_latest_combined_rev );
        // Return a bad RC here for unit test confirmation
        return fapi2::RC_MSS_NON_CURRENT_SPD_COMBINED_REVISION;
#else
        // For hostboot, we want to generate an informational error log
        FAPI_ASSERT( false,
                     fapi2::MSS_NON_CURRENT_SPD_COMBINED_REVISION()
                     .set_DIMM_TARGET(i_target)
                     .set_SPD_COMBINED_REVISION(i_spd_combined_rev)
                     .set_LATEST_SPD_COMBINED_REVISION(i_latest_combined_rev),
                     "%s DDIMM has non-current SPD combined revision and could be updated (0x%04X < 0x%04X)",
                     mss::c_str(i_target), i_spd_combined_rev, i_latest_combined_rev );
#endif
    }
    else
    {
        FAPI_DBG("%s DDIMM has current SPD combined revision (0x%04X >= 0x%04X)",
                 mss::c_str(i_target), i_spd_combined_rev, i_latest_combined_rev );
    }

    return fapi2::FAPI2_RC_SUCCESS;

#ifdef __HOSTBOOT_MODULE
fapi_try_exit:
    // Log the error as recovered - we want this error to be informational
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::RC_MSS_NON_CURRENT_SPD_COMBINED_REVISION;
#endif
}

} // namespace check

///
/// @brief Enforce minimum functional DDIMM SPD revision
/// @param[in] i_target port target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode ddimm_spd_revision(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_spd_rev = 0;
    uint8_t l_spd_content_rev = 0;

    FAPI_TRY( mss::attr::get_spd_revision(i_target, l_spd_rev) );
    FAPI_TRY( mss::attr::get_spd_content_revision(i_target, l_spd_content_rev) );

    for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        uint8_t l_dimm_type = 0;
        uint16_t l_min_combined_rev = 0;
        uint16_t l_latest_combined_rev = 0;
        spd_lookup_key l_key(l_dimm, l_rc);
        FAPI_TRY(l_rc, "%s failed to build spd_lookup_key", mss::c_str(l_dimm));

        FAPI_TRY( mss::attr::get_dimm_type(l_dimm, l_dimm_type) );

        // These checks are not valid if we're not dealing with a DDIMM, so skip if not
        if (l_dimm_type != fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM)
        {
            FAPI_INF("Skipping SPD revision plug rule check on %s because it is not a DDIMM", mss::c_str(i_target));
            continue;
        }

        // First make sure we can get the SPD combined revision using the key
        // This is not necessarily a hard fail, so don't bomb out, but we have to skip the SPD revision checks.
        l_rc = check::spd_revision_key(l_dimm, l_key, l_min_combined_rev, l_latest_combined_rev);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_INF("Skipping SPD revision plug rule check on %s because it has an unrecognized SPD key MFG_ID:0x%04X Height:%u Size:%u",
                     mss::c_str(i_target), l_key.iv_module_mfg_id, l_key.iv_dimm_height, l_key.iv_dimm_size);
            continue;
        }

        {
            // Assemble the SPD combined revision
            // We simply put the SPD revision before the content revision
            fapi2::buffer<uint16_t> l_spd_combined_revision;
            l_spd_combined_revision.insertFromRight<0, BITS_PER_BYTE>(l_spd_rev)
            .insertFromRight<BITS_PER_BYTE, BITS_PER_BYTE>(l_spd_content_rev);

            // Now check the minimum SPD combined revision
            // Note: skipping target trace here as the 4th variable appears to cause issues w/ FAPI_TRY
            // The DIMM target should be called out in the combined revision code
            // We do want to callout the key here, so we know what type of DIMM failed
            FAPI_TRY( check::spd_minimum_combined_revision(l_dimm, l_spd_combined_revision, l_min_combined_rev),
                      "SPD min rev check failed key MFG_ID:0x%04X Height:%u Size:%u",
                      l_key.iv_module_mfg_id, l_key.iv_dimm_height, l_key.iv_dimm_size );

            // Finally check the latest SPD combined revision
            // Don't bother checking the return code here because this check only produces informational logs
            // (and the RC is only used for unit tests)
            check::spd_latest_combined_revision(l_dimm, l_spd_combined_revision, l_latest_combined_rev);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns plug_rule

} // ns mss
