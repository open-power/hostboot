/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/hwp_wrappers_nim.C $ */
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
/// @file hwp_wrappers_nim.C
/// @brief Main wrapper file for PRD calling Nimbus memory procedure code
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <lib/mcbist/mcbist_traits.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <lib/dimm/nimbus_kind.H>
#include <lib/dimm/rank.H>
#include <mss.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>

///
/// @brief Memdiags stop command wrapper for Nimbus
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode nim_stop( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    return mss::memdiags::stop<mss::mc_type::NIMBUS>(i_target);
}

///
/// @brief Memdiags Super Fast Init command wrapper for Nimbus
/// @param[in] i_target the target behind which all memory should be initialized
/// @param[in] i_pattern an index representing a pattern to use to init memory (defaults to 0)
/// @return FAPI2_RC_SUCCESS iff everything ok
///
fapi2::ReturnCode nim_sf_init( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                               const uint64_t i_pattern )
{
    return mss::memdiags::sf_init<mss::mc_type::NIMBUS>(i_target, i_pattern);
}

///
/// @brief Memdiags Super Fast Read command wrapper for Nimbus
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
fapi2::ReturnCode nim_sf_read( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                               const mss::mcbist::stop_conditions<mss::mc_type::NIMBUS>& i_stop,
                               const mss::mcbist::address& i_address,
                               const mss::mcbist::end_boundary i_end,
                               const mss::mcbist::address& i_end_address )
{
    return mss::memdiags::sf_read<mss::mc_type::NIMBUS>(i_target, i_stop, i_address, i_end, i_end_address);
}

///
/// @brief Continuous background scrub command wrapper for Nimbus
/// @param[in] i_target the target behind which all memory should be scrubbed
/// @param[in] i_stop stop conditions
/// @param[in] i_speed the speed to scrub
/// @param[in] i_address mcbist::address representing the address from which to start.
/// @return FAPI2_RC_SUCCESS iff everything ok
///
fapi2::ReturnCode nim_background_scrub( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                        const mss::mcbist::stop_conditions<mss::mc_type::NIMBUS>& i_stop,
                                        const mss::mcbist::speed i_speed,
                                        const mss::mcbist::address& i_address )
{
    return mss::memdiags::background_scrub<mss::mc_type::NIMBUS>(i_target, i_stop, i_speed, i_address);
}

///
/// @brief Targeted scrub command wrapper for Nimbus
/// @param[in] i_target the target behind which all memory should be scrubbed
/// @param[in] i_stop stop conditions
/// @param[in] i_speed the speed to scrub
/// @param[in] i_start_address mcbist::address representing the address from which to start.
/// @param[in] i_end_address mcbist::address representing the address at which to end.
/// @param[in] i_end whether to end, and where
/// @return FAPI2_RC_SUCCESS iff everything ok
///
fapi2::ReturnCode nim_targeted_scrub( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                      const mss::mcbist::stop_conditions<mss::mc_type::NIMBUS>& i_stop,
                                      const mss::mcbist::address& i_start_address,
                                      const mss::mcbist::address& i_end_address,
                                      const mss::mcbist::end_boundary i_end )
{
    return mss::memdiags::targeted_scrub<mss::mc_type::NIMBUS>(i_target, i_stop, i_start_address, i_end_address, i_end);
}

///
/// @brief Continue current command wrapper for Nimbus
/// @param[in] i_target the target
/// @param[in] i_end whether to end, and where (default - don't stop at end of rank)
/// @param[in] i_stop stop conditions (default - 0 meaning 'don't change conditions')
/// @param[in] i_speed the speed to scrub (default - SAME_SPEED meaning leave speed untouched)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode nim_continue_cmd( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                    const mss::mcbist::end_boundary i_end,
                                    const mss::mcbist::stop_conditions<mss::mc_type::NIMBUS>& i_stop,
                                    const mss::mcbist::speed i_speed )
{
    return mss::memdiags::continue_cmd<mss::mc_type::NIMBUS>(i_target, i_end, i_stop, i_speed);
}

///
/// @brief Restore DRAM repairs wrapper for Nimbus
/// @param[in] i_target A target representing a port
/// @param[in,out] io_repairs_applied bit mask, where a bit set means a rank had repairs applied (bit0 = rank0, etc)
/// @param[in,out] io_repairs_exceeded bit mask, where a bit set means a DIMM had more bad bits than could be repaired (bit0 = DIMM0 etc)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode nim_restore_repairs( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                       fapi2::buffer<uint8_t>& io_repairs_applied,
                                       fapi2::buffer<uint8_t>& io_repairs_exceeded )
{
    return mss::restore_repairs<mss::mc_type::NIMBUS>(i_target, io_repairs_applied, io_repairs_exceeded);
}

///
/// @brief Broadcast mode check wrapper for Nimbus
/// @param[in] i_target the target to effect
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states nim_is_broadcast_capable(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target)
{
    return mss::mcbist::is_broadcast_capable<mss::mc_type::NIMBUS>(i_target);
}


///
/// @brief Broadcast mode check wrapper for Nimbus
/// @param[in] i_targets the vector of targets to analyze
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states nim_is_broadcast_capable(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCA>>& i_targets)
{
    return mss::mcbist::is_broadcast_capable<mss::mc_type::NIMBUS>(i_targets);
}

///
/// @brief Broadcast mode check wrapper for Nimbus
/// @param[in] i_kinds the dimms to effect
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states nim_is_broadcast_capable(const std::vector<mss::dimm::kind<mss::mc_type::NIMBUS>>& i_kinds)
{
    return mss::mcbist::is_broadcast_capable(i_kinds);
}
