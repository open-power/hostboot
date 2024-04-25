/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/plug_rules/p10_plug_rules.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2024                        */
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
/// @file p10_plug_rules.H
/// @brief Enforcement of rules for plugging in DIMM
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _P10_PLUG_RULES_H_
#define _P10_PLUG_RULES_H_

#include <fapi2.H>

namespace mss
{

namespace plug_rule
{

///
/// @brief Enforces that MDS dimms are not mixed with non-MDS dimms
/// @param[in] i_target the dimm target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode check_mds(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target);

///
/// @brief Checks that the MDS Dimms have valid media controller targets
/// @param[in] i_target the OCMB target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode check_mds_media_controller(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

//
/// @brief Helper function to check if the dimm's SPD rev is less than min SPD rev
/// @param[in] i_dimm dimm target
/// @param[in] i_spd_min_rev supported minimun spd revision
/// @param[in] i_spd_rev attr value of the spd revision of the DIMM
/// @param[in] i_dram_gen attr value of the dram generation
/// @param[in] i_pvr_82_sys attr value of system
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note need this to run only on p11 systems
///
fapi2::ReturnCode check_ddimm_spd_revision_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
        const uint8_t i_spd_min_rev,
        uint8_t i_spd_rev,
        uint8_t i_dram_gen,
        uint8_t i_pvr_82_sys);

///
/// @brief Check if the dimm's SPD rev is less than min SPD rev
/// @param[in] i_target port target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note need this to run only on p11 systems
///
fapi2::ReturnCode check_ddimm_spd_revision(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target);

///
/// @brief Enforce the plug-rules for planar system
/// @param[in] i_target FAPI2 target (mem port)
/// @param[in] i_is_planar a uint8_t ATTR_MEM_MRW_IS_PLANAR attr
/// @return fapi2::FAPI2_RC_SUCCESS if okay, otherwise a MSS_PLUG_RULE error code
///
fapi2::ReturnCode enforce_planar_plug_rules(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint8_t i_is_planar);

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
/// @brief Helper function for reset_n_dead_load unit testing
/// @param[in] i_reset_group non-functional ocmb reset group
/// @param[in] i_functional_dimms vector of all functional configured DIMMs under proc chip
/// @param[in,out] io_verified_reset_groups list of reset groups we've already verified
/// @param[out] o_callout_ocmbs vector of configured OCMB_CHIPs that need to be called out
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode reset_n_dead_load_helper(const uint64_t i_reset_group,
        const std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>>& i_functional_dimms,
        std::vector<uint8_t>& io_verified_reset_groups,
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>>& o_callout_ocmbs);

///
/// @brief Enforce shared reset_n dependency
/// @param[in] i_target proc chip target
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode reset_n_dead_load(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // ns plug_rule
} // ns mss

#endif // _P10_PLUG_RULES_H_
