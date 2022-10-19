/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/prd/hwp_wrappers.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file hwp_wrappers.H
/// @brief Main wrapper file for PRD calling memory procedure code
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _HWP_WRAPPERS_H_
#define _HWP_WRAPPERS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_traits.H>
#include <lib/mcbist/exp_mcbist_traits.H>
#include <lib/mc/exp_port_traits.H>
#include <lib/mcbist/ody_mcbist_traits.H>
#include <lib/mc/ody_port_traits.H>

///
/// @brief Memdiags stop command wrapper for Explorer
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode exp_stop( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target );

///
/// @brief Memdiags Super Fast Init command wrapper for Nimbus
/// @param[in] i_target the target behind which all memory should be initialized
/// @param[in] i_pattern an index representing a pattern to use to init memory (defaults to 0)
/// @return FAPI2_RC_SUCCESS iff everything ok
///
fapi2::ReturnCode exp_sf_init( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const uint64_t i_pattern );

///
/// @brief Memdiags Super Fast Read command wrapper for Explorer
/// @param[in] i_target the target behind which all memory should be read
/// @param[in] i_stop stop conditions
/// @param[in] i_address mcbist::address representing the address from which to start.
//    Defaults to the first address behind the target
/// @param[in] i_end whether to end, and where
///   Defaults to stop after slave rank
/// @param[in] i_end_address mcbist::address representing the address to end.
//    Defaults to TT::LARGEST_ADDRESS
/// @return FAPI2_RC_SUCCESS iff everything ok
///
fapi2::ReturnCode exp_sf_read( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const mss::mcbist::stop_conditions<mss::mc_type::EXPLORER>& i_stop,
                               const mss::mcbist::address& i_address = mss::mcbist::address(),
                               const mss::mcbist::end_boundary i_end = mss::mcbist::end_boundary::STOP_AFTER_SLAVE_RANK,
                               const mss::mcbist::address& i_end_address = mss::mcbist::address(
                                       mss::mcbistTraits<mss::mc_type::EXPLORER, fapi2::TARGET_TYPE_OCMB_CHIP>::LARGEST_ADDRESS) );

///
/// @brief Continuous background scrub command wrapper for Explorer
/// @param[in] i_target the target behind which all memory should be scrubbed
/// @param[in] i_stop stop conditions
/// @param[in] i_speed the speed to scrub
/// @param[in] i_address mcbist::address representing the address from which to start.
/// @return FAPI2_RC_SUCCESS iff everything ok
///
fapi2::ReturnCode exp_background_scrub( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        const mss::mcbist::stop_conditions<mss::mc_type::EXPLORER>& i_stop,
                                        const mss::mcbist::speed i_speed,
                                        const mss::mcbist::address& i_address );

///
/// @brief Targeted scrub command wrapper for Explorer
/// @param[in] i_target the target behind which all memory should be scrubbed
/// @param[in] i_stop stop conditions
/// @param[in] i_start_address mcbist::address representing the address from which to start.
/// @param[in] i_end_address mcbist::address representing the address at which to end.
/// @param[in] i_end whether to end, and where
/// @return FAPI2_RC_SUCCESS iff everything ok
///
fapi2::ReturnCode exp_targeted_scrub( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                      const mss::mcbist::stop_conditions<mss::mc_type::EXPLORER>& i_stop,
                                      const mss::mcbist::address& i_start_address,
                                      const mss::mcbist::address& i_end_address,
                                      const mss::mcbist::end_boundary i_end );

///
/// @brief Continue current command wrapper for Explorer
/// @param[in] i_target the target
/// @param[in] i_end whether to end, and where (default - don't stop at end of rank)
/// @param[in] i_stop stop conditions (default - 0 meaning 'don't change conditions')
/// @param[in] i_speed the speed to scrub (default - SAME_SPEED meaning leave speed untouched)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode exp_continue_cmd( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const mss::mcbist::end_boundary i_end = mss::mcbist::end_boundary::DONT_CHANGE,
                                    const mss::mcbist::stop_conditions<mss::mc_type::EXPLORER>& i_stop =
                                        mss::mcbist::stop_conditions<mss::mc_type::EXPLORER>
                                        (mss::mcbist::stop_conditions<mss::mc_type::EXPLORER>::DONT_CHANGE),
                                    const mss::mcbist::speed i_speed = mss::mcbist::speed::SAME_SPEED );

///
/// @brief Restore DRAM repairs wrapper for Explorer
/// @param[in] i_target A target representing a port
/// @param[in,out] io_repairs_applied bit mask, where a bit set means a rank had repairs applied (bit0 = rank0, etc)
/// @param[in,out] io_repairs_exceeded bit mask, where a bit set means a DIMM had more bad bits than could be repaired (bit0 = DIMM0 etc)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode exp_restore_repairs( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       fapi2::buffer<uint8_t>& io_repairs_applied,
                                       fapi2::buffer<uint8_t>& io_repairs_exceeded );


///
/// @brief Reads the steer muxes for the given rank
/// @param[in] i_target MEM_PORT target
/// @param[in] i_rank Rank we want to read steer mux for.
/// @param[out] o_dram_spare0_symbol First symbol index of the DRAM fixed by the
///                                  spare on port0 (if no steer, return 0xff)
/// @param[out] o_dram_spare1_symbol First symbol index of the DRAM fixed by the
///                                  spare on port1 (if no steer, return 0xff)
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode exp_check_steering(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                     const uint8_t i_port_rank,
                                     uint8_t& o_dram_spare0_symbol,
                                     uint8_t& o_dram_spare1_symbol );

///
/// @brief Set write mux, wait for periodic cal, set read mux, for the given rank.
/// @param[in] i_target MEM PORT target
/// @param[in] i_port_rank Rank we want to write steer mux for.
/// @param[in] i_symbol First symbol index of the DRAM to steer around.
/// @param[in] i_ignore_bad_bits Set to true to deploy spare regardless of training fails on it (default false)
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode exp_do_steering( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                   const uint8_t i_port_rank,
                                   const uint8_t i_symbol,
                                   const bool i_ignore_bad_bits = false );

///
/// @brief Broadcast mode check wrapper for Explorer
/// @param[in] i_target the target to effect
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states exp_is_broadcast_capable(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);


///
/// @brief Broadcast mode check wrapper for Explorer
/// @param[in] i_targets the vector of targets to analyze
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states exp_is_broadcast_capable(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>>& i_targets);

///
/// @brief Broadcast mode check wrapper for Explorer
/// @param[in] i_kinds the dimms to effect
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states exp_is_broadcast_capable(const std::vector<mss::dimm::kind<mss::mc_type::EXPLORER>>& i_kinds);

///
/// @brief Undeploy the specified spare on the provided rank for Explorer
/// @param[in] i_target MEM PORT target
/// @param[in] i_port_rank Port rank we want to undo the steer mux for.
/// @param[in] i_spare spare number (0 or 1 for explorer)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode exp_unspare(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                              const uint8_t i_port_rank,
                              const size_t i_spare);

///
/// @brief Memdiags stop command wrapper for Odyssey
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode ody_stop( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target );

///
/// @brief Memdiags Super Fast Init command wrapper for Nimbus
/// @param[in] i_target the target behind which all memory should be initialized
/// @param[in] i_pattern an index representing a pattern to use to init memory (defaults to 0)
/// @return FAPI2_RC_SUCCESS iff everything ok
///
fapi2::ReturnCode ody_sf_init( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const uint64_t i_pattern );

///
/// @brief Memdiags Super Fast Read command wrapper for Odyssey
/// @param[in] i_target the target behind which all memory should be read
/// @param[in] i_stop stop conditions
/// @param[in] i_address mcbist::address representing the address from which to start.
//    Defaults to the first address behind the target
/// @param[in] i_end whether to end, and where
///   Defaults to stop after slave rank
/// @param[in] i_end_address mcbist::address representing the address to end.
//    Defaults to TT::LARGEST_ADDRESS
/// @return FAPI2_RC_SUCCESS iff everything ok
///
fapi2::ReturnCode ody_sf_read( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY>& i_stop,
                               const mss::mcbist::address& i_address = mss::mcbist::address(),
                               const mss::mcbist::end_boundary i_end = mss::mcbist::end_boundary::STOP_AFTER_SLAVE_RANK,
                               const mss::mcbist::address& i_end_address = mss::mcbist::address(
                                       mss::mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>::LARGEST_ADDRESS) );

///
/// @brief Continuous background scrub command wrapper for Odyssey
/// @param[in] i_target the target behind which all memory should be scrubbed
/// @param[in] i_stop stop conditions
/// @param[in] i_speed the speed to scrub
/// @param[in] i_address mcbist::address representing the address from which to start.
/// @return FAPI2_RC_SUCCESS iff everything ok
///
fapi2::ReturnCode ody_background_scrub( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        const mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY>& i_stop,
                                        const mss::mcbist::speed i_speed,
                                        const mss::mcbist::address& i_address );

///
/// @brief Targeted scrub command wrapper for Odyssey
/// @param[in] i_target the target behind which all memory should be scrubbed
/// @param[in] i_stop stop conditions
/// @param[in] i_start_address mcbist::address representing the address from which to start.
/// @param[in] i_end_address mcbist::address representing the address at which to end.
/// @param[in] i_end whether to end, and where
/// @return FAPI2_RC_SUCCESS iff everything ok
///
fapi2::ReturnCode ody_targeted_scrub( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                      const mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY>& i_stop,
                                      const mss::mcbist::address& i_start_address,
                                      const mss::mcbist::address& i_end_address,
                                      const mss::mcbist::end_boundary i_end );

///
/// @brief Continue current command wrapper for Odyssey
/// @param[in] i_target the target
/// @param[in] i_end whether to end, and where (default - don't stop at end of rank)
/// @param[in] i_stop stop conditions (default - 0 meaning 'don't change conditions')
/// @param[in] i_speed the speed to scrub (default - SAME_SPEED meaning leave speed untouched)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode ody_continue_cmd( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const mss::mcbist::end_boundary i_end = mss::mcbist::end_boundary::DONT_CHANGE,
                                    const mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY>& i_stop =
                                        mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY>
                                        (mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY>::DONT_CHANGE),
                                    const mss::mcbist::speed i_speed = mss::mcbist::speed::SAME_SPEED );

///
/// @brief Restore DRAM repairs wrapper for Odyssey
/// @param[in] i_target A target representing a port
/// @param[in,out] io_repairs_applied bit mask, where a bit set means a rank had repairs applied (bit0 = rank0, etc)
/// @param[in,out] io_repairs_exceeded bit mask, where a bit set means a DIMM had more bad bits than could be repaired (bit0 = DIMM0 etc)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode ody_restore_repairs( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       fapi2::buffer<uint8_t>& io_repairs_applied,
                                       fapi2::buffer<uint8_t>& io_repairs_exceeded );


///
/// @brief Reads the steer muxes for the given rank
/// @param[in] i_target MEM_PORT target
/// @param[in] i_rank Rank we want to read steer mux for.
/// @param[out] o_dram_spare0_symbol First symbol index of the DRAM fixed by the
///                                  spare on port0 (if no steer, return 0xff)
/// @param[out] o_dram_spare1_symbol First symbol index of the DRAM fixed by the
///                                  spare on port1 (if no steer, return 0xff)
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode ody_check_steering(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                     const uint8_t i_port_rank,
                                     uint8_t& o_dram_spare0_symbol,
                                     uint8_t& o_dram_spare1_symbol );

///
/// @brief Set write mux, wait for periodic cal, set read mux, for the given rank.
/// @param[in] i_target MEM PORT target
/// @param[in] i_port_rank Rank we want to write steer mux for.
/// @param[in] i_symbol First symbol index of the DRAM to steer around.
/// @param[in] i_ignore_bad_bits Set to true to deploy spare regardless of training fails on it (default false)
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode ody_do_steering( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                   const uint8_t i_port_rank,
                                   const uint8_t i_symbol,
                                   const bool i_ignore_bad_bits = false );

///
/// @brief Broadcast mode check wrapper for Odyssey
/// @param[in] i_target the target to effect
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states ody_is_broadcast_capable(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);


///
/// @brief Broadcast mode check wrapper for Odyssey
/// @param[in] i_targets the vector of targets to analyze
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states ody_is_broadcast_capable(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>>& i_targets);

///
/// @brief Broadcast mode check wrapper for Odyssey
/// @param[in] i_kinds the dimms to effect
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states ody_is_broadcast_capable(const std::vector<mss::dimm::kind<mss::mc_type::ODYSSEY>>& i_kinds);

///
/// @brief Undeploy the specified spare on the provided rank for Odyssey
/// @param[in] i_target MEM PORT target
/// @param[in] i_port_rank Port rank we want to undo the steer mux for.
/// @param[in] i_spare spare number (0 or 1 for odylorer)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode ody_unspare(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                              const uint8_t i_port_rank,
                              const size_t i_spare);

#endif
