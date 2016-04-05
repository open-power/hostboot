/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_scrub.C $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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
#include <lib/dimm/kind.H>

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

    // If we're running in the simulator, we want to only touch the addresses which training touched
    uint8_t is_sim = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    for (const auto& p : i_target.getChildren<TARGET_TYPE_MCA>())
    {
        std::vector<uint64_t> l_pr;
        mss::mcbist::program<TARGET_TYPE_MCBIST> l_program;

        // In sim we know a few things ...
        // Get the primary ranks for this port. We know there can only be 4, and we know we only trained the primary
        // ranks. Therefore, we only need to clean up the primary ranks. And because there's 4 max, we can do it
        // all using the 4 address range registers of tne MCBIST (broadcast currently not considered.)
        // So we can write 0's to those to get their ECC fixed up.
        FAPI_TRY( mss::primary_ranks(p, l_pr) );

        for (const auto& r : l_pr)
        {
            mss::mcbist::address l_start;
            mss::mcbist::address l_end;

            // Setup l_start to represent this rank, and then make the end address from that.
            l_start.set_master_rank(r);

            // l_end starts like as the max as we want to scrub the entire thing. If we're in sim,
            // we'll wratchet that back.
            l_start.get_range<mss::mcbist::address::MRANK>(l_end);

            if (is_sim)
            {
                l_start.get_range<mss::mcbist::address::COL>(l_end);
                // Set C3 bit to get an entire cache line
                l_end.set_field<mss::mcbist::address::COL>(0b1000000);
            }

            // By default we're in maint address mode, not address counting mode. So we give it a start and end, and ignore
            // anything invalid - that's what maint address mode is all about
            mss::mcbist::config_address_range(i_target, l_start, l_end, r);

            // Write
            {
                // Run in ECC mode, 64B writes (superfast mode)

                mss::mcbist::subtest_t<TARGET_TYPE_MCBIST> l_fw_subtest =
                    mss::mcbist::write_subtest<TARGET_TYPE_MCBIST>();

                l_fw_subtest.enable_port(mss::relative_pos<TARGET_TYPE_MCBIST>(p));
                l_fw_subtest.change_addr_sel(r);
                l_fw_subtest.enable_dimm(mss::get_dimm_from_rank(r));
                l_program.iv_subtests.push_back(l_fw_subtest);
                FAPI_DBG("adding superfast write for %s rank %d (dimm %d)", mss::c_str(p), r, mss::get_dimm_from_rank(r));
            }

            // Read
            {
                // Run in ECC mode, 64B writes (superfast mode)
                mss::mcbist::subtest_t<TARGET_TYPE_MCBIST> l_fr_subtest =
                    mss::mcbist::read_subtest<TARGET_TYPE_MCBIST>();

                l_fr_subtest.enable_port(mss::relative_pos<TARGET_TYPE_MCBIST>(p));
                l_fr_subtest.change_addr_sel(r);
                l_fr_subtest.enable_dimm(mss::get_dimm_from_rank(r));
                l_program.iv_subtests.push_back(l_fr_subtest);
                FAPI_DBG("adding superfast read for %s rank %d (dimm %d)", mss::c_str(p), r, mss::get_dimm_from_rank(r));
            }
        }

        // Write 0's
        FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD0Q, 0) );
        FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD1Q, 0) );
        FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD2Q, 0) );
        FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD3Q, 0) );
        FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD4Q, 0) );
        FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD5Q, 0) );
        FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD6Q, 0) );
        FAPI_TRY( mss::putScom(i_target, MCBIST_MCBFD7Q, 0) );

        // Setup the sim polling based on a heuristic <cough>guess</cough>
        // Looks like ~250ck per address for a write/read program on the sim-dimm, and add a long number of polls
        // and a 64x fudge factor. Testing shows this takes about 50 or so poll loops to complete, which is ok
        l_program.iv_poll.iv_initial_sim_delay = mss::cycles_to_simcycles((64 * l_pr.size()) * 250);
        l_program.iv_poll.iv_delay = 200;

        // On real hardware wait 100ms and then start polling for another 5s
        l_program.iv_poll.iv_initial_delay = 100 * mss::DELAY_1MS;
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
    FAPI_INF("End mss scrub");
    return fapi2::current_err;
}
