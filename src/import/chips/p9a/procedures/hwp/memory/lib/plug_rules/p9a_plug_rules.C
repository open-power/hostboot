/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/plug_rules/p9a_plug_rules.C $ */
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
#include <mss_explorer_attribute_getters.H>

namespace mss
{

namespace plug_rule
{

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

fapi_try_exit:
    return fapi2::current_err;
}

} // ns plug_rule

} // ns mss
