/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/plug_rules/p9a_plug_rules.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p9a_plug_rules.C
/// @brief Enforcement of rules for plugging in DIMM
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/axone_consts.H>
#include <algorithm>

#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/assert_noexit.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/num.H>

#include <lib/plug_rules/p9a_plug_rules.H>
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
/// @brief Helper function for channel_a_before_channel_b unit testing
/// @param[in] i_target ocmb chip target
/// @param[in] i_pos ocmb chip position
/// @param[in] i_ocmbs vector of all configured ocmb chips under proc chip
/// @param[out] o_channel_a_pos ocmb chip position
/// @param[out] o_pass true if plug rule passes, false otherwise
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode channel_a_before_channel_b_helper(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint64_t i_pos,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>>& i_ocmbs,
        uint64_t& o_channel_a_pos,
        bool& o_pass)
{
    // Create a vector of the channel A position for each OCMB (according to Swift Design Workbook v1.1 29May2019.pdf)
    static const std::vector<uint8_t> l_dependencies = {0, 0, 0, 2, 0, 4, 0, 6, 0, 9, 0, 11, 0, 12, 0, 14};
    uint64_t l_dependency = 0;
    auto l_ocmb_it = i_ocmbs.begin();

    // Comparator lambda expression
    const auto compare = [&l_dependency](const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_lhs)
    {
        return (mss::relative_pos<fapi2::TARGET_TYPE_PROC_CHIP>(i_lhs) == l_dependency);
    };

    FAPI_ASSERT(i_pos < mss::axone::MAX_DIMM_PER_PROC,
                fapi2::MSS_OUT_OF_BOUNDS_INDEXING()
                .set_TARGET(i_target)
                .set_INDEX(i_pos)
                .set_LIST_SIZE(l_dependencies.size())
                .set_FUNCTION(mss::axone::CHANNEL_A_BEFORE_CHANNEL_B),
                "%s has an invalid position index (%d)", mss::c_str(i_target), i_pos);

    o_channel_a_pos = l_dependencies[i_pos];

    // All even positions are channel A, so they are ok
    if (!is_odd(i_pos))
    {
        o_pass = true;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Check the channel A dependency for i_pos
    l_dependency = l_dependencies[i_pos];

    // Find iterator to matching key (make sure OCMB for channel A is configured)
    l_ocmb_it = std::find_if(i_ocmbs.begin(),
                             i_ocmbs.end(),
                             compare);

    o_pass = l_ocmb_it != i_ocmbs.end();
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enforce plug order dependencies
/// @param[in] i_target proc chip target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode channel_a_before_channel_b(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    typedef mcTypeTraits<mc_type::EXPLORER> TT;

    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    const auto l_ocmbs = mss::find_targets<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);
    const uint64_t l_pos_offset = mss::fapi_pos(i_target) *
                                  (TT::OCMB_PER_OMI * TT::OMI_PER_MCC * TT::MCC_PER_MI * TT::MI_PER_MC * TT::MC_PER_PROC);

    for ( const auto& l_ocmb : l_ocmbs )
    {
        // Find the position of the ocmb chip
        const auto l_pos = mss::relative_pos<fapi2::TARGET_TYPE_PROC_CHIP>(l_ocmb);
        uint64_t l_channel_a_pos = 0;
        bool l_pass = false;

        FAPI_TRY(channel_a_before_channel_b_helper(l_ocmb, l_pos, l_ocmbs, l_channel_a_pos, l_pass));

        // Call out this OCMB if it's channel A partner is not configured
        FAPI_ASSERT( l_pass,
                     fapi2::MSS_PLUG_RULES_SINGLE_DDIMM_IN_WRONG_SLOT()
                     .set_SLOT_POSITION(l_pos + l_pos_offset)
                     .set_CHANNEL_A_SLOT_POSITION(l_channel_a_pos + l_pos_offset)
                     .set_TARGET(l_ocmb),
                     "%s DDIMM is plugged into the wrong slot. Must plug into channel A slot first (%d)", mss::c_str(l_ocmb),
                     (l_channel_a_pos + l_pos_offset) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enforce the plug-rules we can do before mss_freq
/// @param[in] i_target FAPI2 target (proc chip)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode enforce_pre_freq(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    uint8_t l_ignore_plug_rules = 0;

    FAPI_TRY( mss::attr::get_ignore_mem_plug_rules(l_ignore_plug_rules) );

    // Skip plug rule checks if set to ignore (e.g. on Apollo)
    if (l_ignore_plug_rules == fapi2::ENUM_ATTR_MEM_IGNORE_PLUG_RULES_YES)
    {
        FAPI_INF("Attribute set to ignore plug rule checking");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // If there are no DIMM, we can just get out.
    if (mss::count_dimm(mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target)) == 0)
    {
        FAPI_INF("Skipping plug rule check on %s because it has no DIMM configured", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Check channel A versus B plug order dependencies
    FAPI_TRY( channel_a_before_channel_b(i_target) );

fapi_try_exit:
    return fapi2::current_err;
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
/// @brief Check that we recognize DDIMM module manufacturing ID
/// @param[in] i_target dimm target
/// @param[in] i_module_mfg_id DIMM module manufacturing ID
/// @param[out] o_latest_combined_rev latest SPD combined revision
/// @return fapi2::FAPI2_RC_SUCCESS if okay. A non-SUCCESS return will also produce an informational log
///
fapi2::ReturnCode module_mfg_id(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                const uint16_t i_module_mfg_id,
                                uint16_t& o_latest_combined_rev)
{
    // Check that we can find the ID in our latest revision list
    FAPI_ASSERT( mss::find_value_from_key(LATEST_SPD_COMBINED_REV, i_module_mfg_id, o_latest_combined_rev),
                 fapi2::MSS_UNKNOWN_DIMM_MODULE_MFG_ID()
                 .set_DIMM_TARGET(i_target)
                 .set_MODULE_MFG_ID(i_module_mfg_id),
                 "%s DDIMM has unrecognized module manufacturing ID (0x%04X)",
                 mss::c_str(i_target), i_module_mfg_id );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // Log the error as recovered - we want this error to be informational
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_RECOVERED);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::RC_MSS_UNKNOWN_DIMM_MODULE_MFG_ID;
}

///
/// @brief Check DDIMM SPD revision and content revision versus latest supported
/// @param[in] i_target dimm target
/// @param[in] i_spd_rev SPD revision
/// @param[in] i_spd_content_rev SPD content revision
/// @param[in] i_latest_combined_rev latest SPD combined revision
/// @return fapi2::FAPI2_RC_SUCCESS if okay. A non-SUCCESS return will also produce an informational log
/// @note The return code from this function is only used in unit tests.
///
fapi2::ReturnCode spd_combined_revision(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        const uint8_t i_spd_rev,
                                        const uint8_t i_spd_content_rev,
                                        const uint16_t i_latest_combined_rev)
{
    // Assemble the SPD combined revision
    // We simply put the SPD revision before the content revision
    fapi2::buffer<uint16_t> l_spd_combined_revision;
    l_spd_combined_revision.insertFromRight<0, BITS_PER_BYTE>(i_spd_rev)
    .insertFromRight<BITS_PER_BYTE, BITS_PER_BYTE>(i_spd_content_rev);

    // Check the combined revision
    if(l_spd_combined_revision < i_latest_combined_rev)
    {
        // For the lab, we just want to log these as informational errors
#ifndef __HOSTBOOT_MODULE
        FAPI_INF("%s DDIMM has non-current SPD combined revision and could be updated (0x%04X < 0x%04X)",
                 mss::c_str(i_target), l_spd_combined_revision, i_latest_combined_rev );
        // Return a bad RC here for unit test confirmation
        return fapi2::RC_MSS_NON_CURRENT_SPD_COMBINED_REVISION;
#else
        // For hostboot, we want to generate an informational error log
        FAPI_ASSERT( false,
                     fapi2::MSS_NON_CURRENT_SPD_COMBINED_REVISION()
                     .set_DIMM_TARGET(i_target)
                     .set_SPD_COMBINED_REVISION(l_spd_combined_revision)
                     .set_LATEST_SPD_COMBINED_REVISION(i_latest_combined_rev),
                     "%s DDIMM has non-current SPD combined revision and could be updated (0x%04X < 0x%04X)",
                     mss::c_str(i_target), l_spd_combined_revision, i_latest_combined_rev );
#endif
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
        uint16_t l_latest_combined_rev = 0;
        uint8_t l_dimm_type = 0;
        uint16_t l_module_mfg_id = 0;

        FAPI_TRY( mss::attr::get_dimm_type(l_dimm, l_dimm_type) );

        // These checks are not valid if we're not dealing with a DDIMM, so skip if not
        if (l_dimm_type != fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM)
        {
            FAPI_INF("Skipping SPD revision plug rule check on %s because it is not a DDIMM", mss::c_str(i_target));
            continue;
        }

        FAPI_TRY( mss::attr::get_module_mfg_id(l_dimm, l_module_mfg_id) );

        // First make sure we can get the SPD content revision using the module manufacturing ID
        // This is not necessarily a hard fail, so don't bomb out, but we have to skip the SPD revision checks.
        l_rc = check::module_mfg_id(l_dimm, l_module_mfg_id, l_latest_combined_rev);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_INF("Skipping SPD revision plug rule check on %s because it has an unrecognized module manufacturing ID 0x%04X",
                     mss::c_str(i_target), l_module_mfg_id);
            continue;
        }

        // Now check the base SPD revision
        FAPI_ASSERT( (MIN_FUNCTIONAL_SPD_REV <= l_spd_rev),
                     fapi2::MSS_UNSUPPORTED_SPD_REVISION()
                     .set_DIMM_TARGET(l_dimm)
                     .set_SPD_REVISION(l_spd_rev)
                     .set_MINIMUM_FUNCTIONAL_SPD_REVISION(MIN_FUNCTIONAL_SPD_REV),
                     "%s DDIMM has unsupported SPD revision and needs to be updated (0x%02X < 0x%02X)",
                     mss::c_str(l_dimm), l_spd_rev, MIN_FUNCTIONAL_SPD_REV );

        // Finally check the SPD content revision
        // Don't bother checking the return code here because this check only produces informational logs
        // (and the RC is only used for unit tests)
        check::spd_combined_revision(l_dimm, l_spd_rev, l_spd_content_rev, l_latest_combined_rev);
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns plug_rule

} // ns mss
