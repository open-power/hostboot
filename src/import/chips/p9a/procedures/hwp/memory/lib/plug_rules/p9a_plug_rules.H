/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/plug_rules/p9a_plug_rules.H $ */
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
#include <generic/memory/lib/utils/pos.H>

namespace mss
{

namespace plug_rule
{
/// @note This is the oldest functional DDIMM SPD revision
///       any DIMMs with older SPD will be called out
static const uint8_t MIN_FUNCTIONAL_SPD_REV = 0x03;

/// @note These are the latest DDIMM SPD combined revisions
///       combined revision is the SPD revision and the SPD content revision
///       any DIMMs with older SPD will generate an error
///       The first byte is the major revision
///               any updates to this are usually new bytes and will require code updates
///       The second byte is the content revision
///               updates to this byte are most likely values and it's less likely that code will need to be updated
/// @note When adding new vendors, THIS NEEDS TO BE IN SORTED ORDER BY VENDOR ID ENCODING
static const std::vector<std::pair<uint16_t, uint16_t>> LATEST_SPD_COMBINED_REV =
{
    {fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART,      0x0400}, // 0x0194
    {fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_US_MODULAR, 0x0400}, // 0x04AB
    {fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_FUJITSU,    0x0400}, // 0x8004
    {fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON,     0x0400}, // 0x802C
    {fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG,    0x0400}, // 0x80CE
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
/// @brief Check that we recognize DDIMM module manufacturing ID
/// @param[in] i_target dimm target
/// @param[in] i_module_mfg_id DIMM module manufacturing ID
/// @param[out] o_latest_content_rev latest SPD content revision
/// @return fapi2::FAPI2_RC_SUCCESS if okay. A non-SUCCESS return will also produce an informational log
///
fapi2::ReturnCode module_mfg_id(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                const uint16_t i_module_mfg_id,
                                uint16_t& o_latest_content_rev);

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
