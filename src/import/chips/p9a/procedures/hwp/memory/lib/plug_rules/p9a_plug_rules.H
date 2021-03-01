/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/plug_rules/p9a_plug_rules.H $ */
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
/// @file p9a_plug_rules.H
/// @brief Enforcement of rules for plugging in DIMM
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _P9A_PLUG_RULES_H_
#define _P9A_PLUG_RULES_H_

#include <fapi2.H>

namespace mss
{

namespace plug_rule
{

///
/// @class SPD lookup key class
/// @note allows us to lookup the min supported and latest SPD
///
struct spd_lookup_key
{
    uint16_t iv_module_mfg_id;
    uint64_t iv_part_number;
    uint32_t iv_card_rev;

    ///
    /// @brief Target based constructor
    /// @param[in] i_target the DIMM target on which to operate
    /// @param[out] o_rc SUCCESS if the function passes
    /// @note Reads in the attributes
    ///
    spd_lookup_key(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, fapi2::ReturnCode& o_rc);

    ///
    /// @brief Target based constructor
    /// @param[in] i_module_mfg_id the module manufacturing ID
    /// @param[in] i_part_number the DIMM partnumber converted from ASCII
    /// @param[in] i_card_rev the DIMM rawcard version converted from ASCII
    /// @note Used to create the lookup table
    ///
    spd_lookup_key(const uint16_t i_module_mfg_id = 0,
                   const uint64_t i_part_number = 0,
                   const uint32_t i_card_rev = 0) :
        iv_module_mfg_id(i_module_mfg_id),
        iv_part_number(i_part_number),
        iv_card_rev(i_card_rev)
    {}

    ///
    /// @brief Less than comparison operator
    /// @param[in] i_rhs the value to compare against
    /// @return true if this spd_lookup_key is less than i_rhs
    ///
    bool operator<(const spd_lookup_key& i_rhs) const;

    ///
    /// @brief Not equal to comparison operator
    /// @param[in] i_rhs the value to compare against
    /// @return true if this spd_lookup_key is not equal to i_rhs
    ///
    bool operator!=(const spd_lookup_key& i_rhs) const;
};

///
/// @brief Enforce the plug-rules we can do before mss_freq
/// @param[in] i_target FAPI2 target (proc chip)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode enforce_pre_freq(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

///
/// @brief Enforce the plug-rules we can do after eff_config
/// @param[in] i_target FAPI2 target (proc chip)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode enforce_post_eff_config(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Enforce having Channel A plugged before Channel B
/// @param[in] i_target proc chip target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode channel_a_before_channel_b(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

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
        bool& o_pass);

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
                                   uint16_t& o_latest_combined_rev);

///
/// @brief Check DDIMM SPD revision and content revision versus minimum supported
/// @param[in] i_target dimm target
/// @param[in] i_key used for logging if an error occurs
/// @param[in] i_spd_combined_revision the combined SPD revision and content
/// @param[in] i_min_combined_rev SPD minimum combined revision information
/// @return fapi2::FAPI2_RC_SUCCESS if okay. A non-SUCCESS return will also produce an informational log
/// @note The return code from this function is only used in unit tests.
///
fapi2::ReturnCode spd_minimum_combined_revision(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const spd_lookup_key& i_key,
        const uint16_t i_spd_combined_rev,
        const uint16_t i_min_combined_rev);

///
/// @brief Check DDIMM SPD revision and content revision versus latest supported
/// @param[in] i_target dimm target
/// @param[in] i_key used for logging if an error occurs
/// @param[in] i_spd_combined_revision the combined SPD revision and content
/// @param[in] i_latest_combined_rev latest SPD combined revision information
/// @return fapi2::FAPI2_RC_SUCCESS if okay. A non-SUCCESS return will also produce an informational log
/// @note The return code from this function is only used in unit tests.
///
fapi2::ReturnCode spd_latest_combined_revision(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const spd_lookup_key& i_key,
        const uint16_t i_spd_combined_rev,
        const uint16_t i_latest_combined_rev);

} // namespace check

///
/// @brief Enforce minimum functional DDIMM SPD revision
/// @param[in] i_target port target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode ddimm_spd_revision(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

} // ns plug_rule
} // ns mss

#endif // _P9A_PLUG_RULES_H_
