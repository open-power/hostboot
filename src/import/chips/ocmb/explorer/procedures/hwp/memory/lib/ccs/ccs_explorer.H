/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/ccs/ccs_explorer.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
/// @file ccs_explorer.H
/// @brief Run and manage the CCS engine
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_CCS_EXPLORER_H_
#define _MSS_CCS_EXPLORER_H_

#include <fapi2.H>
#include <lib/ccs/ccs_traits_explorer.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <generic/memory/lib/ccs/ccs_instruction.H>
#include <generic/memory/lib/ccs/ccs_ddr4_commands.H>

namespace mss
{
namespace ccs
{

///
/// @brief Configures the CCS engine
/// @param[in] i_target the target on which to operate
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode configure_mode(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Create, initialize a JEDEC Device Deselect CCS command - Explorer specialization
/// @param[in] i_idle the idle time to the next command (default to 0)
/// @return the Device Deselect CCS instruction
///
template<>
instruction_t<mss::mc_type::EXPLORER> des_command<mss::mc_type::EXPLORER>(const uint16_t i_idle);

///
/// @brief Sets any signals associated with the chip selects for this instruction - Explorer specialization
/// @param[in] i_csn01 chip selects 0 and 1
/// @param[in] i_csn23 chip selects 2 and 3
/// @param[in] i_cid the chip ID values to set
/// @param[in] i_update_cid if true, the CID is updated, if not it is ignored
/// @note This helper is created to allow different memory controllers to handle the ranks differently
/// Largely, this is to allow for different DRAM generations between memory controllers
///
template<>
void instruction_t<mss::mc_type::EXPLORER>::set_chipselects_helper(const uint8_t i_csn01, const uint8_t i_csn23,
        const uint8_t i_cid, const bool i_update_cid);

///
/// @brief Gets the CKE signals (Memory controller and DRAM technology dependent) - Explorer specialization
/// @param[out] o_cke the CKE for this instruction
/// @note This helper is created to allow different memory controllers to handle the CKE differently
/// Largely, this is to allow for different DRAM generations between memory controllers
///
template<>
void instruction_t<mss::mc_type::EXPLORER>::get_cke_helper(uint8_t& o_cke) const;

///
/// @brief Gets the CKE signals (Memory controller and DRAM technology dependent) - Explorer specialization
/// @param[in] i_cke the CKE for this instruction
/// @note This helper is created to allow different memory controllers to handle the CKE differently
/// Largely, this is to allow for different DRAM generations between memory controllers
///
template<>
void instruction_t<mss::mc_type::EXPLORER>::set_cke_helper(const uint8_t i_cke);

///
/// @brief Updates the idles and repeats based upon the memory controller - Explorer specialization
/// @param[in] i_target the port target for this instruction - for error logging
/// @return fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode instruction_t<mss::mc_type::EXPLORER>::configure_idles_and_repeats(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target );

///
/// @brief Grabs the idles from the CCS array - Explorer specialization
///
template<>
void instruction_t<mss::mc_type::EXPLORER>::get_idles();

///
/// @brief Grabs the repeats from the CCS array - Explorer specialization
///
template<>
void instruction_t<mss::mc_type::EXPLORER>::get_repeats();

} // namespace ccs
} // namespace mss

#endif
