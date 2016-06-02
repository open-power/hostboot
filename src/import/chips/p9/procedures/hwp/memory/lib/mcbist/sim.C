/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mcbist/sim.C $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file mcbist/sim.C
/// @brief MCBIST/memdiags functions for when we're in simulation mode
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/dimm/rank.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/mcbist.H>
#include <lib/mcbist/patterns.H>
#include <lib/mcbist/sim.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

namespace mcbist
{

namespace sim
{

///
/// @brief Perform a sim version of initializing memory
/// @param[in] i_target MCBIST
/// @param[in] i_pattern an index representing a pattern to use to initize memory (defaults to 0)
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode sf_init( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                           const uint64_t i_pattern )
{
    FAPI_INF("Start sim init");

    // If we're running in the simulator, we want to only touch the addresses which training touched

    for (const auto& p : i_target.getChildren<TARGET_TYPE_MCA>())
    {
        std::vector<uint64_t> l_pr;
        mss::mcbist::program<TARGET_TYPE_MCBIST> l_program;

        mss::mcbist::address l_start;
        mss::mcbist::address l_end;

        size_t l_rank_address_pair = 0;

        // In sim we know a few things ...
        // Get the primary ranks for this port. We know there can only be 4, and we know we only trained the primary
        // ranks. Therefore, we only need to clean up the primary ranks. And because there's 4 max, we can do it
        // all using the 4 address range registers of tne MCBIST (broadcast currently not considered.)
        // So we can write 0's to those to get their ECC fixed up.
        FAPI_TRY( mss::primary_ranks(p, l_pr) );
        fapi2::Assert( l_pr.size() <= mss::MAX_RANK_PER_DIMM );

        for (auto r = l_pr.begin(); r != l_pr.end(); ++l_rank_address_pair, ++r)
        {
            FAPI_INF("sim init %s, rank %d", mss::c_str(p), *r);

            // Setup l_start to represent this rank, and then make the end address from that.
            l_start.set_master_rank(*r);

            // Set C3 bit to get an entire cache line
            l_start.get_sim_end_address(l_end);

            // By default we're in maint address mode, not address counting mode. So we give it a start and end, and ignore
            // anything invalid - that's what maint address mode is all about
            mss::mcbist::config_address_range(i_target, l_start, l_end, l_rank_address_pair);

            // Write
            {
                // Run in ECC mode, 64B writes (superfast mode)

                mss::mcbist::subtest_t<TARGET_TYPE_MCBIST> l_fw_subtest =
                    mss::mcbist::write_subtest<TARGET_TYPE_MCBIST>();

                l_fw_subtest.enable_port(mss::relative_pos<TARGET_TYPE_MCBIST>(p));
                l_fw_subtest.change_addr_sel(l_rank_address_pair);
                l_fw_subtest.enable_dimm(mss::get_dimm_from_rank(*r));
                l_program.iv_subtests.push_back(l_fw_subtest);
                FAPI_DBG("adding superfast write for %s rank %d (dimm %d)", mss::c_str(p), *r, mss::get_dimm_from_rank(*r));
            }

            // Read - we do a read here as verification can use this as a tool as we do the write and then the read.
            // If we failed to write properly the read would thow ECC errors. Just a write (which the real hardware would
            // do) doesn't catch that. This takes longer, but it's not terribly long in any event.
            {
                // Run in ECC mode, 64B writes (superfast mode)
                mss::mcbist::subtest_t<TARGET_TYPE_MCBIST> l_fr_subtest =
                    mss::mcbist::read_subtest<TARGET_TYPE_MCBIST>();

                l_fr_subtest.enable_port(mss::relative_pos<TARGET_TYPE_MCBIST>(p));
                l_fr_subtest.change_addr_sel(l_rank_address_pair);
                l_fr_subtest.enable_dimm(mss::get_dimm_from_rank(*r));
                l_program.iv_subtests.push_back(l_fr_subtest);
                FAPI_DBG("adding superfast read for %s rank %d (dimm %d)", mss::c_str(p), *r, mss::get_dimm_from_rank(*r));
            }
        }

        // Write pattern
        FAPI_TRY( mss::mcbist::load_pattern(i_target, i_pattern) );

        // Setup the sim polling based on a heuristic <cough>guess</cough>
        // Looks like ~400ck per address for a write/read program on the sim-dimm, and add a long number of polls
        // On real hardware wait 100ms and then start polling for another 5s
        l_program.iv_poll.iv_initial_sim_delay = mss::cycles_to_simcycles(((l_end - l_start) * l_pr.size()) * 800);
        l_program.iv_poll.iv_initial_delay = 100 * mss::DELAY_1MS;
        l_program.iv_poll.iv_sim_delay = 100000;
        l_program.iv_poll.iv_delay = 10 * mss::DELAY_1MS;
        l_program.iv_poll.iv_poll_count = 500;

        // Just one port for now. Per Shelton we need to set this in maint address mode
        // even tho we specify the port/dimm in the subtest.
        fapi2::buffer<uint8_t> l_port;
        l_port.setBit(mss::relative_pos<TARGET_TYPE_MCBIST>(p));
        l_program.select_ports(l_port >> 4);

        // Kick it off, wait for a result
        FAPI_TRY( mss::mcbist::execute(i_target, l_program) );
    }

fapi_try_exit:
    FAPI_INF("End sim init");
    return fapi2::current_err;
}

} // namespace sim

} // namespace mcbist

} // namespace mss
