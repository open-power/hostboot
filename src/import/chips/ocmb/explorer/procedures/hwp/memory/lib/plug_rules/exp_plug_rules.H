/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/plug_rules/exp_plug_rules.H $ */
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
/// @file exp_plug_rules.H
/// @brief Plug rules enforcement for explorer
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _EXP_PLUG_RULES_H_
#define _EXP_PLUG_RULES_H_

#include <fapi2.H>
#include <lib/dimm/exp_kind.H>

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
    bool& o_is_enterprise_mode);

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
    bool& o_is_enterprise_mode );

///
/// @brief Plug rule for no mixing DIMM size
/// @param[in] i_target omic target
/// @param[in] i_kinds a vector of DIMM (sorted while procesing)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
/// @note This function will commit error logs representing the mixing failure
///
fapi2::ReturnCode dimm_size_mixing(const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target,
                                   const std::vector<mss::dimm::kind<mss::mc_type::EXPLORER>>& i_kinds);


///
/// @brief Enforce the plug-rules we can do at the beginning of eff_config_thermal
/// @param[in] i_target FAPI2 target (OCMB Chip)
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode enforce_pre_eff_config_thermal(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

} // plug_rule
} // exp
} // mss

#endif
