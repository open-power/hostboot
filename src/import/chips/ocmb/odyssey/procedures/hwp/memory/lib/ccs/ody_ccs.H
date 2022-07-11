/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ccs/ody_ccs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file ody_ccs.H
/// @brief Odyssey CCS specializations
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _ODY_CCS_H_
#define _ODY_CCS_H_

#include <fapi2.H>
#include <lib/ccs/ody_ccs_traits.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <generic/memory/lib/ccs/ccs_instruction.H>

namespace mss
{
namespace ccs
{

///
/// @brief Gets the register value for the idles/repeats multiplier
/// @param[in] i_idles the requested number of idles
/// @param[in] i_repeats the requested number of repeats
/// @return the register value for the idles/repeats multiplier
///
uint8_t get_inst_idle_reg_multiplier(const uint16_t i_idles, const uint16_t i_repeats);

///
/// @brief Gets the numeric value for the idles/repeats multiplier
/// @param[in] i_reg_multiplier the register value (0b00 to 0b11)
/// @return the register numeric for the idles/repeats multiplier
///
uint16_t get_inst_idle_numeric_multiplier(const uint8_t i_reg_multiplier);

///
/// @brief Create, initialize a JEDEC Device Deselect CCS command - Odyssey specialization
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the Device Deselect CCS instruction
///
template<>
instruction_t<mss::mc_type::ODYSSEY> des_command<mss::mc_type::ODYSSEY>(const uint16_t i_idle);

///
/// @brief Sets any signals associated with the chip selects for this instruction - Odyssey specialization
/// @param[in] i_csn01 chip selects 0 and 1
/// @param[in] i_csn23 chip selects 2 and 3
/// @param[in] i_cid the chip ID values to set
/// @param[in] i_update_cid if true, the CID is updated, if not it is ignored
/// @note Odyssey specialization CS01 is for command 0, while CS23 is for command 1
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::set_chipselects_helper(const uint8_t i_csn01, const uint8_t i_csn23,
        const uint8_t i_cid, const bool i_update_cid);

///
/// @brief Gets the CKE signals (Memory controller and DRAM technology dependent) - Odyssey specialization
/// @param[out] o_cke the CKE for this instruction
/// @note nothing to do for Odyssey
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::get_cke_helper(uint8_t& o_cke) const;

///
/// @brief Gets the CKE signals (Memory controller and DRAM technology dependent) - Odyssey specialization
/// @param[in] i_cke the CKE for this instruction
/// @note nothing to do for Odyssey
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::set_cke_helper(const uint8_t i_cke);

///
/// @brief Updates the idles and repeats based upon the memory controller - Odyssey specialization
/// @param[in] i_target the port target for this instruction - for error logging
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode instruction_t<mss::mc_type::ODYSSEY>::configure_idles_and_repeats(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target );

///
/// @brief Grabs the idles from the CCS array - Odyssey specialization
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::get_idles();

///
/// @brief Grabs the repeats from the CCS array - Odyssey specialization
///
template<>
void instruction_t<mss::mc_type::ODYSSEY>::get_repeats();

///
/// @brief Determines our rank configuration type - Odyssey specialization
/// @param[in] i_target the MCA target on which to operate
/// @param[out] o_rank_config the rank configuration
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode get_rank_config<mss::mc_type::ODYSSEY>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        rank_configuration& o_rank_config);

} // namespace ccs
} // namespace mss

#endif
