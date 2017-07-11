/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_scrub.C $    */
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
/// @file p9_mss_scrub.C
/// @brief Begin background scrub
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mss_scrub.H>

#include <lib/dimm/rank.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/mcbist.H>
#include <lib/mcbist/patterns.H>
#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/sim.H>
#include <lib/utils/count_dimm.H>
#include <lib/fir/memdiags_fir.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::FAPI2_RC_SUCCESS;

///
/// @brief Begin background scrub
/// @param[in] i_target MCBIST
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9_mss_scrub( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_INF("Start mss scrub");

    // If there are no DIMM we don't need to bother. In fact, we can't as we didn't setup
    // attributes for the PHY, etc.
    if (mss::count_dimm(i_target) == 0)
    {
        FAPI_INF("... skipping scrub for %s - no DIMM ...", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // If we're running in the simulator, we want to only touch the addresses which training touched
    uint8_t l_sim = 0;
    bool l_poll_results = false;
    fapi2::buffer<uint64_t> l_status;

    // A small vector of addresses to poll during the polling loop
    const std::vector<mss::poll_probe<fapi2::TARGET_TYPE_MCBIST>> l_probes =
    {
        {i_target, "mcbist current address", MCBIST_MCBMCATQ},
    };

    // We'll fill in the initial delay below
    mss::poll_parameters l_poll_parameters(0, 200, 100 * mss::DELAY_1MS, 200, 10000);
    uint64_t l_memory_size = 0;

    FAPI_TRY( mss::eff_memory_size(i_target, l_memory_size) );
    l_poll_parameters.iv_initial_delay = mss::calculate_initial_delay(i_target, (l_memory_size * mss::BYTES_PER_GB));

    FAPI_TRY( mss::is_simulation( l_sim) );

    if (l_sim)
    {
        fapi2::ReturnCode l_rc;

        // Use some sort of pattern in sim in case the verification folks need to look for something
        // TK. Need a verification pattern. This is a not-good pattern for verification ... We don't really
        // have a good pattern for verification defined.
        FAPI_INF("running mss sim init in place of scrub");
        l_rc = mss::mcbist::sim::sf_init(i_target, mss::mcbist::PATTERN_0);

        // Unmask firs and turn off FIFO mode before returning
        FAPI_TRY ( mss::unmask::after_memdiags( i_target ) );
        FAPI_TRY ( mss::unmask::after_background_scrub( i_target ) );
        FAPI_TRY ( mss::reset_reorder_queue_settings(i_target) );

        return l_rc;
    }

    // In Cronus on hardware (which is how we got here - f/w doesn't call this) we want
    // to call sf_init (0's)
    // TK we need to check FIR given the way this is right now, we should adjust with better stop
    // conditions when we learn more about what we want to find in the lab
    FAPI_TRY( memdiags::sf_init(i_target, mss::mcbist::PATTERN_0) );

    // Poll for completion.
    l_poll_results = mss::poll(i_target, MCBIST_MCBISTFIRQ, l_poll_parameters,
                               [&l_status](const size_t poll_remaining,
                                           const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_DBG("mcbist firq 0x%llx, remaining: %d", stat_reg, poll_remaining);
        l_status = stat_reg;
        return l_status.getBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>() == true;
    },
    l_probes);

    FAPI_ASSERT( l_poll_results == true,
                 fapi2::MSS_MEMDIAGS_SUPERFAST_INIT_FAILED_TO_INIT().set_MCBIST_TARGET(i_target),
                 "p9_mss_scrub (init) timedout %s", mss::c_str(i_target) );

    // Unmask firs after memdiags and turn off FIFO mode
    FAPI_TRY ( mss::unmask::after_memdiags( i_target ) );
    FAPI_TRY ( mss::reset_reorder_queue_settings(i_target) );

    // Start background scrub
    FAPI_TRY ( memdiags::background_scrub( i_target,
                                           mss::mcbist::stop_conditions(),
                                           mss::mcbist::speed::BG_SCRUB,
                                           mss::mcbist::address() ) );

    // Unmask firs after background scrub is started
    FAPI_TRY ( mss::unmask::after_background_scrub( i_target ) );

fapi_try_exit:
    return fapi2::current_err;
}
