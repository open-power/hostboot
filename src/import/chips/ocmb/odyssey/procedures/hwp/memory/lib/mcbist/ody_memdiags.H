/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/mcbist/ody_memdiags.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2025                        */
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
/// @file ody_memdiags.H
/// @brief API for memory diagnostics
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
//

#ifndef _MSS_ODY_MEMDIAGS_H_
#define _MSS_ODY_MEMDIAGS_H_

#include <fapi2.H>

#include <lib/shared/ody_consts.H>
#include <lib/mcbist/ody_mcbist.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_amap_config.H>

namespace mss
{

namespace memdiags
{

///
/// @brief Mask MCBISTFIRQ[MCBIST_PROGRAM_COMPLETE] and return the original mask value - ODYSSEY specialization
/// @param[in] i_target the target
/// @param[out] o_fir_mask_save the original mask value to be restored later
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode mask_program_complete<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    fapi2::buffer<uint64_t>& o_fir_mask_save );

///
/// @brief Restore MCBISTFIRQ[MCBIST_PROGRAM_COMPLETE] mask value and clear the FIR - ODYSSEY specialization
/// @param[in] i_target the target
/// @param[in] i_fir_mask_save the original mask value to be restored
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode clear_and_restore_program_complete<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const fapi2::buffer<uint64_t>& i_fir_mask_save );

///
/// @brief Gets the number of srank CIDs configured in the memdiags
/// @param[in] i_port_targets A target representing ports
/// @param[in,out] io_config_srank_bit_count number of bits required to represent a srank
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode get_configured_srank_cid_count<mss::mc_type::ODYSSEY>(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>& i_port_targets,
    uint8_t& io_config_srank_bit_count );

///
/// @brief Checks if a subtest is needed for a given address range
/// @param[in] i_port_index index of memory port being checked
/// @param[in] i_port_exists array of boolean that tells if each port exists
/// @param[in] i_port_start_address port index of starting address
/// @param[in] i_constraints test constraints containing start and end addresses
/// @param[in] i_range_start starting address of subtest
/// @param[in] i_range_end end address of subtest
/// @return true if a subtest should be created, false otherwise
///
bool subtest_in_range(
    const uint8_t i_port_index,
    const bool i_port_exists[mss::ody::MAX_PORT_PER_OCMB],
    const uint64_t i_port_start_address,
    const mss::mcbist::constraints<mss::mc_type::ODYSSEY>& i_constraints,
    const mss::mcbist::address<mss::mc_type::ODYSSEY>& i_range_start,
    const mss::mcbist::address<mss::mc_type::ODYSSEY>& i_range_end);

} // memdiags

} // mss

#endif
