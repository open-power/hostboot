/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/phy/cal_timers.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file cal_timers.H
/// @brief Subroutines to calculate the duration of training operations
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_CAL_TIMERS_H_
#define _MSS_CAL_TIMERS_H_

#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <lib/eff_config/timing.H>
#include <lib/utils/poll.H>
#include <lib/phy/read_cntrl.H>

namespace mss
{

///
/// @brief Configure the polling intervals with the proper timeings based on the cal steps enabled
/// @tparam T the fapi2::TargetType of the port
/// @param[in] i_target the port target
/// @param[in] i_total_cycles the number of cycles a cal step takes
/// @param[in,out] io_poll the poll_parameters to update
/// @return FAPI2_RC_SUCCESS iff everything is OK
///
template<fapi2::TargetType T>
inline fapi2::ReturnCode cal_timer_setup(const fapi2::Target<T>& i_target,
        const uint64_t i_total_cycles,
        poll_parameters& io_poll)
{
    // This should equal half of the minimum poll count of the quickest cal segment when in sim
    // i.e. DQS_ALIGN + INITIAL_PAT_WR = 3 polls, so this should be 2
    constexpr uint64_t MINIMUM_POLL_COUNT = 2;

    // Sometimes when running in sim, particularly Mesa, it is helpful to not delay a bunch
    // when training starts - makes it simpler to get an AET for, say, write leveling. So
    // this is here to allow the simple removal of the initial delay for those situations.
#ifdef THRASH_CCS_IP_IN_SIM
    io_poll.iv_initial_delay = mss::cycles_to_ns(i_target, 1);
    io_poll.iv_initial_sim_delay = mss::cycles_to_simcycles(1);
#else
    // We don't want to wait too long for the initial check, just some hueristics here
    io_poll.iv_initial_delay = mss::cycles_to_ns(i_target, i_total_cycles / 8);
    io_poll.iv_initial_sim_delay = mss::cycles_to_simcycles(i_total_cycles / 8);
#endif

    // Delay 10us between polls, and setup the poll count so
    // iv_initial_delay + (iv_delay * iv_poll_count) == i_total_cycles + some fudge;
    io_poll.iv_delay = DELAY_10US;
    io_poll.iv_sim_delay = mss::cycles_to_simcycles(mss::ns_to_cycles(i_target, io_poll.iv_delay));

    // Round up to the cycles left after the initial delay
    const uint64_t l_ns_left = std::max(int64_t(0), (int64_t(mss::cycles_to_ns(i_target,
                                        i_total_cycles)) - int64_t(io_poll.iv_initial_delay)));
    io_poll.iv_poll_count = l_ns_left / io_poll.iv_delay;
    io_poll.iv_poll_count += l_ns_left % io_poll.iv_delay ? 0 : 1;

    // Make the minimum poll count 2, as that's the value of the quickest cal step in sim
    io_poll.iv_poll_count = (io_poll.iv_poll_count < MINIMUM_POLL_COUNT) ? MINIMUM_POLL_COUNT : io_poll.iv_poll_count;

    // Fudge some for sim irregularities. This will increase time to a complete timeout but won't
    // really effect valid training unless these cycles are needed. So this isn't a bad thing ...
    // AKA watchdog timer
    // HB is failing, bump it out 4x for the polling
    io_poll.iv_poll_count *= 4;

    FAPI_INF("%s tc: %luc, id: %luns(%lusc), d: %lu(%lusc), pc: %lu",
             mss::c_str(i_target),
             i_total_cycles,
             io_poll.iv_initial_delay,
             io_poll.iv_initial_sim_delay,
             io_poll.iv_delay,
             io_poll.iv_sim_delay,
             io_poll.iv_poll_count);

    return fapi2::FAPI2_RC_SUCCESS;
}

}
#endif
