/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/hwp_wrappers_ody.C $ */
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
// EKB-Mirror-To: hostboot

///
/// @file hwp_wrappers_ody.C
/// @brief Main wrapper file for PRD calling Odyssey memory procedure code
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <lib/ecc/ecc_traits_odyssey.H>
#include <lib/mcbist/ody_mcbist_traits.H>
#include <lib/mcbist/ody_mcbist.H>
#include <lib/dimm/ody_rank.H>
#include <generic/memory/lib/utils/dimm/kind.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>
#include <lib/mcbist/ody_maint_cmds.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/conversions.H>
#include <generic/memory/lib/utils/find.H>
#include <mss_odyssey_attribute_getters.H>
#include <lib/mc/ody_port_traits.H>
#include <lib/shared/ody_consts.H>
#include <lib/dimm/ody_rank.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>
#include <generic/memory/lib/utils/mc/gen_mss_restore_repairs.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

///
/// @brief Memdiags stop command wrapper for Odyssey
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode ody_stop( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    return mss::memdiags::stop<mss::mc_type::ODYSSEY>(i_target);
}

///
/// @brief Memdiags Super Fast Init command wrapper for Odyssey
/// @param[in] i_target the target behind which all memory should be initialized
/// @param[in] i_pattern an index representing a pattern to use to init memory (defaults to 0)
/// @return FAPI2_RC_SUCCESS iff everything ok
///
fapi2::ReturnCode ody_sf_init( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const uint64_t i_pattern )
{
    return mss::memdiags::sf_init<mss::mc_type::ODYSSEY>(i_target, i_pattern);
}

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
                               const mss::mcbist::address& i_address,
                               const mss::mcbist::end_boundary i_end,
                               const mss::mcbist::address& i_end_address )
{
    return mss::memdiags::sf_read<mss::mc_type::ODYSSEY>(i_target, i_stop, i_address, i_end, i_end_address);
}

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
                                        const mss::mcbist::address& i_address )
{
    return mss::memdiags::mss_firmware_background_scrub_helper<mss::mc_type::ODYSSEY>(i_target,
            i_stop,
            i_speed,
            i_address);
}

///
/// @brief Targeted scrub command wrapper for Odyssey
/// @param[in] i_target the target behind which all memory should be scrubbed
/// @param[in] i_stop stop conditions
/// @param[in] i_speed the speed to scrub
/// @param[in] i_start_address mcbist::address representing the address from which to start.
/// @param[in] i_end_address mcbist::address representing the address at which to end.
/// @param[in] i_end whether to end, and where
/// @return FAPI2_RC_SUCCESS iff everything ok
///
fapi2::ReturnCode ody_targeted_scrub( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                      const mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY>& i_stop,
                                      const mss::mcbist::address& i_start_address,
                                      const mss::mcbist::address& i_end_address,
                                      const mss::mcbist::end_boundary i_end )
{
    return mss::memdiags::targeted_scrub<mss::mc_type::ODYSSEY>(i_target, i_stop, i_start_address, i_end_address, i_end);
}

///
/// @brief Continue current command wrapper for Odyssey
/// @param[in] i_target the target
/// @param[in] i_end whether to end, and where (default - don't stop at end of rank)
/// @param[in] i_stop stop conditions (default - 0 meaning 'don't change conditions')
/// @param[in] i_speed the speed to scrub (default - SAME_SPEED meaning leave speed untouched)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode ody_continue_cmd( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    const mss::mcbist::end_boundary i_end,
                                    const mss::mcbist::stop_conditions<mss::mc_type::ODYSSEY>& i_stop,
                                    const mss::mcbist::speed i_speed )
{
    return mss::memdiags::continue_cmd<mss::mc_type::ODYSSEY>(i_target, i_end, i_stop, i_speed);
}

///
/// @brief Restore DRAM repairs wrapper for Odyssey
/// @param[in] i_target A target representing a port
/// @param[in,out] io_repairs_applied bit mask, where a bit set means a rank had repairs applied (bit0 = rank0, etc)
/// @param[in,out] io_repairs_exceeded bit mask, where a bit set means a DIMM had more bad bits than could be repaired (bit0 = DIMM0 etc)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode ody_restore_repairs( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                       fapi2::buffer<uint8_t>& io_repairs_applied,
                                       fapi2::buffer<uint8_t>& io_repairs_exceeded )
{
    return mss::restore_repairs<mss::mc_type::ODYSSEY>(i_target, io_repairs_applied, io_repairs_exceeded);
}


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
                                     uint8_t& o_dram_spare1_symbol )
{
    return mss::steer::check_steering<mss::mc_type::ODYSSEY>(i_target, i_port_rank, o_dram_spare0_symbol,
            o_dram_spare1_symbol);
}

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
                                   const bool i_ignore_bad_bits = false )
{
    return mss::steer::do_steering<mss::mc_type::ODYSSEY>(i_target, i_port_rank, i_symbol, i_ignore_bad_bits);
}

///
/// @brief Broadcast mode check wrapper for Odyssey
/// @param[in] i_target the target to effect
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states ody_is_broadcast_capable(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    return mss::states::NO;
}


///
/// @brief Broadcast mode check wrapper for Odyssey
/// @param[in] i_targets the vector of targets to analyze
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states ody_is_broadcast_capable(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>>& i_targets)
{
    return mss::states::NO;
}

///
/// @brief Broadcast mode check wrapper for Odyssey
/// @param[in] i_kinds the dimms to effect
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states ody_is_broadcast_capable(const std::vector<mss::dimm::kind<mss::mc_type::ODYSSEY>>& i_kinds)
{
    return mss::states::NO;
}

///
/// @brief Undeploy the specified spare on the provided rank for Odyssey
/// @param[in] i_target MEM PORT target
/// @param[in] i_port_rank Port rank we want to undo the steer mux for.
/// @param[in] i_spare spare number (0 or 1 for odyssey)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode ody_unspare(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                              const uint8_t i_port_rank,
                              const size_t i_spare)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    mss::rank::info<mss::mc_type::ODYSSEY> l_rank_info(i_target, i_port_rank, l_rc);

    FAPI_TRY(l_rc, "%s Failed to create rank::info instance for rank %d", mss::c_str(i_target), i_port_rank);
    FAPI_TRY(mss::steer::unspare<mss::mc_type::ODYSSEY>(i_spare, l_rank_info));

fapi_try_exit:
    return fapi2::current_err;
}
