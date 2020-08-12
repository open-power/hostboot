/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_memdiag.C $  */
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
/// @file p9_mss_memdiag.C
/// @brief HW Procedure pattern testing
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <lib/shared/nimbus_defaults.H>
#include <fapi2.H>
#include <p9_mss_memdiag.H>

#include <lib/dimm/rank.H>
#include <generic/memory/lib/utils/poll.H>
#include <lib/utils/nimbus_find.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/mcbist/address.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_patterns.H>
#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/mcbist.H>
#include <lib/mc/port.H>
#include <lib/fir/unmask.H>
#include <generic/memory/lib/ecc/ecc.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::TARGET_TYPE_MCA;
using fapi2::FAPI2_RC_SUCCESS;

extern "C"
{
    ///
    /// @brief Begin background scrub and run pattern tests
    /// @param[in] i_target MCBIST
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_memdiag( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
    {
        FAPI_INF("Start mss memdiags on: %s", mss::c_str( i_target ));

        // If there are no DIMM we don't need to bother. In fact, we can't as we didn't setup
        // attributes for the PHY, etc.
        if (mss::count_dimm(i_target) == 0)
        {
            FAPI_INF("... skipping mem_diags %s - no DIMM ...", mss::c_str(i_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // If we're running in the simulator, we want to only touch the addresses which training touched
        uint8_t l_sim = false;
        bool l_poll_results = false;
        fapi2::buffer<uint64_t> l_status;

        // Set poll parameter values for max time to complete sf_init
        constexpr uint64_t INITIAL_DELAY = 0;
        constexpr uint64_t INITIAL_SIM_DELAY = 200;
        constexpr uint64_t DELAY_TIME = 100 * mss::DELAY_1MS;
        constexpr uint64_t SIM_DELAY_TIME = 200;
        constexpr uint64_t MAX_POLL_COUNT = 10000;

        // A small vector of addresses to poll during the polling loop
        const std::vector<mss::poll_probe<fapi2::TARGET_TYPE_MCBIST>> l_probes =
        {
            {i_target, "mcbist current address", MCBIST_MCBMCATQ},
        };

        // We'll fill in the initial delay below
        mss::poll_parameters l_poll_parameters(INITIAL_DELAY, INITIAL_SIM_DELAY, DELAY_TIME, SIM_DELAY_TIME, MAX_POLL_COUNT);
        uint64_t l_memory_size = 0;

        FAPI_TRY( mss::eff_memory_size<mss::mc_type::NIMBUS>(i_target, l_memory_size) );
        l_poll_parameters.iv_initial_delay = mss::calculate_initial_delay(i_target, (l_memory_size * mss::BYTES_PER_GB));

        FAPI_TRY( mss::is_simulation( l_sim) );

        if (l_sim)
        {
            // Use some sort of pattern in sim in case the verification folks need to look for something
            FAPI_INF("running mss sim init in place of memdiags");
            FAPI_TRY ( mss::mcbist::sim::sf_init(i_target, mss::mcbist::PATTERN_0) );

            // Unmask firs and turn off FIFO mode before returning
            FAPI_TRY ( mss::unmask::after_memdiags( i_target ) );
            FAPI_TRY ( mss::reset_reorder_queue_settings(i_target) );

            return fapi2::FAPI2_RC_SUCCESS;
        }

        // Unsure if redundant code? Wasn't called before to my knowledge
        // Only major difference between old mss_scrub and old mss_memdiag
        // Read the bad_dq_bitmap attribute and place corresponding symbol and chip marks
        for (const auto& l_mca : mss::find_targets<TARGET_TYPE_MCA>(i_target))
        {
            fapi2::buffer<uint8_t> l_repairs_applied;
            fapi2::buffer<uint8_t> l_repairs_exceeded;
            std::vector<uint64_t> l_ranks;

            FAPI_TRY( mss::restore_repairs<mss::mc_type::NIMBUS>( l_mca, l_repairs_applied, l_repairs_exceeded) );

            // assert if we have exceeded the allowed repairs
            for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_mca))
            {
                // Note: using MCA here as the scoms used to collect FFDC data fail on the DIMM level target
                FAPI_ASSERT( !(l_repairs_exceeded.getBit(mss::index(l_dimm))),
                             fapi2::MSS_MEMDIAGS_REPAIRS_EXCEEDED().set_MCA_TARGET(l_mca),
                             "p9_mss_memdiag bad bit repairs exceeded %s", mss::c_str(l_mca) );
            }

#ifdef __HOSTBOOT_MODULE
            // assert if both chip and symbol marks exist for any given rank
            FAPI_TRY( mss::rank::ranks(l_mca, l_ranks) );

            for (const auto l_rank : l_ranks)
            {
                if (l_repairs_applied.getBit(l_rank))
                {
                    uint64_t l_galois = 0;
                    mss::states l_confirmed = mss::NO;
                    // check for chip mark in hardware mark store
                    FAPI_TRY( mss::ecc::get_hwms<mss::mc_type::NIMBUS>(l_mca, l_rank, l_galois, l_confirmed) );

                    if (l_confirmed)
                    {
                        auto l_type = mss::ecc::fwms::mark_type::CHIP;
                        auto l_region = mss::ecc::fwms::mark_region::DISABLED;
                        auto l_addr = mss::mcbist::address(0);
                        // check for symbol mark in firmware mark store
                        FAPI_TRY( mss::ecc::get_fwms<mss::mc_type::NIMBUS>(l_mca, l_rank, l_galois, l_type, l_region, l_addr) );

                        FAPI_ASSERT( l_region == mss::ecc::fwms::mark_region::DISABLED,
                                     fapi2::MSS_MEMDIAGS_CHIPMARK_AND_SYMBOLMARK().set_MCA_TARGET(l_mca).set_RANK(l_rank),
                                     "p9_mss_memdiag both chip mark and symbol mark on rank %d: %s", l_rank, mss::c_str(l_mca) );
                    }
                }
            }

#endif
        }

        // In Cronus on hardware (which is how we got here - f/w doesn't call this) we want
        // to call sf_init (0's)
        FAPI_TRY( mss::memdiags::sf_init(i_target, mss::mcbist::PATTERN_0) );

        // Poll for completion.
        l_poll_results = mss::poll(i_target, MCBIST_MCBISTFIRQ, l_poll_parameters,
                                   [&l_status](const size_t poll_remaining,
                                               const fapi2::buffer<uint64_t>& stat_reg) -> bool
        {
            FAPI_DBG("mcbist firq 0x%016llx, remaining: %d", stat_reg, poll_remaining);
            l_status = stat_reg;
            return l_status.getBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>() == true;
        },
        l_probes);

        FAPI_ASSERT( l_poll_results == true,
                     fapi2::MSS_MEMDIAGS_SUPERFAST_INIT_FAILED_TO_INIT().set_MC_TARGET(i_target),
                     "p9_mss_memdiag (init) timedout %s", mss::c_str(i_target) );

        // Unmask firs after memdiags and turn off FIFO mode
        FAPI_TRY ( mss::unmask::after_memdiags( i_target ) );
        FAPI_TRY ( mss::reset_reorder_queue_settings(i_target) );

    fapi_try_exit:
        FAPI_INF("End memdiag");
        return fapi2::current_err;
    }
}
