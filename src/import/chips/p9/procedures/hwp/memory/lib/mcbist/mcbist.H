/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mcbist/mcbist.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file mcbist.H
/// @brief Run and manage the MCBIST engine
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MCBIST_H_
#define _MSS_MCBIST_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/shared/mss_const.H>
#include <lib/ecc/ecc_traits_nimbus.H>
#include <lib/mc/port.H>
#include <lib/utils/mss_nimbus_conversions.H>
#include <lib/utils/bit_count.H>
#include <lib/dimm/nimbus_kind.H>
#include <lib/mcbist/mcbist_traits.H>
#include <lib/workarounds/mcbist_workarounds.H>
#include <generic/memory/lib/utils/num.H>
#include <generic/memory/lib/utils/poll.H>
#include <generic/memory/lib/utils/memory_size.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_patterns.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_settings.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>
#include <generic/memory/lib/utils/dump_regs.H>

namespace mss
{
namespace mcbist
{

////
/// @brief Checks if broadcast mode is capable of being enabled on this target
/// @param[in] i_target the target to effect
/// @param[in] i_bc_force attribute's value to force off broadcast mode
/// @param[in] i_bc_enable attribute's value to enable or disable broadcast mode
/// @param[in] i_chip_bc_capable true if the chip is BC capable
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states is_broadcast_capable_helper(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const uint8_t i_bc_force,
        const uint8_t i_bc_enable,
        const bool i_chip_bc_capable);

///
/// @brief Checks if broadcast mode is capable of being enabled on this target
/// @tparam MC the mc type of the T
/// @tparam T, the fapi2::TargetType
/// @param[in] i_target the target to effect
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T >
const mss::states is_broadcast_capable(const fapi2::Target<T>& i_target);


///
/// @brief Checks if broadcast mode is capable of being enabled on this vector of targets
/// @tparam MC the mc type of the T
/// @tparam T, the fapi2::TargetType
/// @param[in] i_targets the vector of targets to analyze
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T >
const mss::states is_broadcast_capable(const std::vector<fapi2::Target<T>>& i_targets);

///
/// @brief Checks if broadcast mode is capable of being enabled on this vector of targets
/// @param[in] i_target the target to effect
/// @return o_capable - yes iff these vector of targets are broadcast capable
///
const mss::states is_broadcast_capable(const std::vector<mss::dimm::kind<>>& i_kinds);

///
/// @brief Configures all of the ports for broadcast mode
/// @tparam MC the mc type of the T
/// @tparam T, the fapi2::TargetType
/// @param[in] i_target the target to effect
/// @param[out] o_port_select - the configuration of the selected ports
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T >
fapi2::ReturnCode setup_broadcast_port_select(const fapi2::Target<T>& i_target, uint64_t& o_port_select);

///
/// @brief Checks if broadcast mode is capable based upon the timings
/// @param[in] i_targets the targets to effect
/// @param[out] o_broadcast_capable YES if BC capable, otherwise NO
/// @return FAPI2_RC_SUCCSS iff ok
/// @note all timing attributes must be equal for broadcast to be capable
///
fapi2::ReturnCode is_broadcast_capable_timings(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCA>>& i_targets,
        mss::states& o_broadcast_capable);

///
/// @brief Enables broadcast mode
/// @tparam MC the mc type of the T
/// @tparam T, the fapi2::TargetType
/// @param[in] i_target the target to effect
/// @param[in,out] io_program the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T >
fapi2::ReturnCode enable_broadcast_mode(const fapi2::Target<T>& i_target, mcbist::program<>& io_program);

///
/// @brief Load MCBIST ECC (and?) spare data pattern given a pattern - explorer specialization
/// @param[in] i_target the target to effect
/// @param[in] i_pattern an mcbist::patterns
/// @param[in] i_invert whether to invert the pattern or not
/// @note this overload disappears when we have real patterns.
/// @return FAPI2_RC_SUCCSS iff ok
///
template< >
inline fapi2::ReturnCode load_eccspare_pattern<mss::mc_type::NIMBUS>(
    const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
    const pattern& i_pattern,
    const bool i_invert )
{
    // First up assemble the pattern
    const auto l_pattern = generate_eccspare_pattern(i_pattern, i_invert);

    FAPI_TRY(fapi2::putScom(i_target, MCBIST_MCBFDQ, l_pattern));

fapi_try_exit:
    return fapi2::current_err;
}
} // namespace MCBIST

} // namespace mss

#endif
