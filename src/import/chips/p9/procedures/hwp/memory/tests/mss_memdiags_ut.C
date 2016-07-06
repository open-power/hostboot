/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/tests/mss_memdiags_ut.C $      */
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
/// @file mss_memdiags_ut.C
/// @brief Unit tests for memory MEMDIAGS functions
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP FW Owner: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 4
// *HWP Consumed by: CI
//#pragma once

#include <cstdarg>

#include <mss.H>
#include <catch.hpp>

#include <lib/mcbist/mcbist.H>
#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/settings.H>
#include <lib/eff_config/memory_size.H>
#include <lib/fir/memdiags_fir.H>

#include <lib/utils/poll.H>
#include <lib/utils/count_dimm.H>
#include <tests/target_fixture.H>

using fapi2::FAPI2_RC_SUCCESS;
using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{
namespace test
{

/**
 * @brief Test Case for memdiags
 * @note mcbist_target_test_fixture is the fixture to use with this test case
 */
TEST_CASE_METHOD(mss::test::mcbist_target_test_fixture, "memdiags", "[memdiags]")
{
    // Don't count the invalid maint address - we know we're setting that.
    fapi2::buffer<uint64_t> l_fir_mask;
    l_fir_mask.setBit<MCBIST_MCBISTFIRQ_INVALID_MAINT_ADDRESS>().invert();

    // Loops over MCBIST targets that were defined in the associated config
    for_each_target([l_fir_mask](const fapi2::Target<TARGET_TYPE_MCBIST>& i_target)
    {

        uint8_t is_sim = 0;
        REQUIRE_FALSE( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION,
                                     fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), is_sim) );

        SECTION("Test stop_condition structure")
        {
            // Stops default to all conditions off and all thresholded conditions disabled
            mss::mcbist::stop_conditions l_t;
            REQUIRE( 0xffffffff00000000 == l_t );

            {
                l_t.set_thresh_nce_int( 0 );
                REQUIRE( 0xffffffff00000000 == l_t );

                l_t.set_thresh_nce_int( 1 );
                REQUIRE( 0x0fffffff00000000 == l_t );

                l_t.set_thresh_nce_int( 2 );
                REQUIRE( 0x1fffffff00000000 == l_t );

                // Because 2^3 is 8 which is the exponent of the nearest rounded down power of 2 (12 - 4 == 8)
                l_t.set_thresh_nce_int( 12 );
                REQUIRE( 0x3fffffff00000000 == l_t );

                l_t.set_thresh_nce_int( mss::mcbist::stop_conditions::DISABLE );
                REQUIRE( 0xffffffff00000000 == l_t );
            }

            {
                l_t.set_thresh_nce_soft( 0 );
                REQUIRE( 0xffffffff00000000 == l_t );

                l_t.set_thresh_nce_soft( 1 );
                REQUIRE( 0xf0ffffff00000000 == l_t );

                l_t.set_thresh_nce_soft( 2 );
                REQUIRE( 0xf1ffffff00000000 == l_t );

                // Because 2^3 is 8 which is the exponent of the nearest rounded down power of 2 (12 - 4 == 8)
                l_t.set_thresh_nce_soft( 12 );
                REQUIRE( 0xf3ffffff00000000 == l_t );

                l_t.set_thresh_nce_soft( mss::mcbist::stop_conditions::DISABLE );
                REQUIRE( 0xffffffff00000000 == l_t );
            }

            {
                l_t.set_thresh_nce_hard( 0 );
                REQUIRE( 0xffffffff00000000 == l_t );

                l_t.set_thresh_nce_hard( 1 );
                REQUIRE( 0xff0fffff00000000 == l_t );

                l_t.set_thresh_nce_hard( 2 );
                REQUIRE( 0xff1fffff00000000 == l_t );

                l_t.set_thresh_nce_hard( 10 );
                REQUIRE( 0xff3fffff00000000 == l_t );

                l_t.set_thresh_nce_hard( mss::mcbist::stop_conditions::DISABLE );
                REQUIRE( 0xffffffff00000000 == l_t );
            }

            {
                l_t.set_thresh_rce( 0 );
                REQUIRE( 0xffffffff00000000 == l_t );

                l_t.set_thresh_rce( 1 );
                REQUIRE( 0xfff0ffff00000000 == l_t );

                l_t.set_thresh_rce( 2 );
                REQUIRE( 0xfff1ffff00000000 == l_t );

                l_t.set_thresh_rce( 5 );
                REQUIRE( 0xfff2ffff00000000 == l_t );

                l_t.set_thresh_rce( mss::mcbist::stop_conditions::DISABLE );
                REQUIRE( 0xffffffff00000000 == l_t );
            }

            // Little method chaining check
            {
                memdiags::stop_conditions l_t(0);
                l_t.set_thresh_ice( mss::mcbist::stop_conditions::DISABLE )
                .set_thresh_mce_int( mss::mcbist::stop_conditions::DISABLE );
                REQUIRE( 0x0000ff0000000000 == l_t );
            }

            {
                l_t.set_thresh_mce_soft( 0 );
                REQUIRE( 0xffffffff00000000 == l_t );

                l_t.set_thresh_mce_soft( 1 );
                REQUIRE( 0xffffff0f00000000 == l_t );

                l_t.set_thresh_mce_soft( 2 );
                REQUIRE( 0xffffff1f00000000 == l_t );

                l_t.set_thresh_mce_soft( 10 );
                REQUIRE( 0xffffff3f00000000 == l_t );

                l_t.set_thresh_mce_soft( mss::mcbist::stop_conditions::DISABLE );
                REQUIRE( 0xffffffff00000000 == l_t );

            }

            {
                l_t.set_thresh_mce_hard( 0 );
                REQUIRE( 0xffffffff00000000 == l_t );

                l_t.set_thresh_mce_hard( 1 );
                REQUIRE( 0xfffffff000000000 == l_t );

                l_t.set_thresh_mce_hard( 2 );
                REQUIRE( 0xfffffff100000000 == l_t );

                l_t.set_thresh_mce_hard( 7 );
                REQUIRE( 0xfffffff200000000 == l_t );

                l_t.set_thresh_mce_hard( mss::mcbist::stop_conditions::DISABLE );
                REQUIRE( 0xffffffff00000000 == l_t );
            }

            {
                l_t.set_pause_on_sce( mss::ON );
                REQUIRE( 0xffffffff80000000 == l_t );
            }

            {
                l_t.set_pause_on_mce( mss::ON );
                REQUIRE( 0xffffffffc0000000 == l_t );
            }

            {
                l_t.set_pause_on_mpe( mss::ON );
                REQUIRE( 0xffffffffe0000000 == l_t );
            }

            {
                l_t.set_pause_on_ue( mss::ON );
                REQUIRE( 0xfffffffff0000000 == l_t );
            }

            {
                l_t.set_pause_on_sue( mss::ON );
                REQUIRE( 0xfffffffff8000000 == l_t );
            }

            {
                l_t.set_pause_on_aue( mss::ON );
                REQUIRE( 0xfffffffffc000000 == l_t );
            }

            {
                l_t.set_pause_on_rcd( mss::ON );
                REQUIRE( 0xfffffffffe000000 == l_t );
            }

            {
                l_t.set_symbol_counter_mode( mss::mcbist::stop_conditions::DISABLE );
                REQUIRE( 0xfffffffffe000600 == l_t );
            }

            {
                l_t.set_nce_hard_symbol_count_enable( mss::ON );
                REQUIRE( 0xfffffffffe000640 == l_t );
            }

            {
                l_t.set_pause_mcb_error( mss::ON );
                REQUIRE( 0xfffffffffe000660 == l_t );
            }

            {
                l_t.set_pause_mcb_log_full( mss::ON );
                REQUIRE( 0xfffffffffe000670 == l_t );
            }

            {
                l_t.set_maint_rce_with_ce( mss::ON );
                REQUIRE( 0xfffffffffe000678 == l_t );
            }

            {
                l_t.set_mce_soft_symbol_count_enable( mss::ON );
                REQUIRE( 0xfffffffffe00067c == l_t );
            }

            {
                l_t.set_mce_inter_symbol_count_enable( mss::ON );
                REQUIRE( 0xfffffffffe00067e == l_t );
            }

            {
                l_t.set_mce_hard_symbol_count_enable( mss::ON );
                REQUIRE( 0xfffffffffe00067f == l_t );
            }
        }


        // If there are no DIMM we don't need to bother.
        if (mss::count_dimm(i_target) == 0)
        {
            return 0;
        }


        // Note that the testing of the memdiags operations leverages the helper directly
        // is it is more flexible allowing better control over simulation environments.
        SECTION("Test sf_init")
        {
            // Loading of patterns is tested in the mcbist unit test.

            mss::mcbist::constraints l_const(memdiags::PATTERN_5);

            FAPI_INF("\n\n\n start sf_init\n\n\n");

            // The addresses here are calculated so that we get a few iterations
            // of polling on an AWAN, but not so much that we run the risk of timing out
            mss::mcbist::address().get_range<mss::mcbist::address::COL>(l_const.iv_end_address);
            l_const.iv_end_address.set_column(0b111111);
            memdiags::operation<TARGET_TYPE_MCBIST> l_bob(i_target, mss::mcbist::init_subtest<TARGET_TYPE_MCBIST>(), l_const);
            REQUIRE_FALSE( l_bob.multi_port_init() );
            REQUIRE_FALSE( l_bob.execute() );

            // Check the things we default to so that we have a canary in case the defaults change
            // Zero out cmd timebase - mcbist::program constructor does that for us.
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBPARMQ, l_read) );
                REQUIRE( 0 == l_read );
            }

            // Load stop conditions - default state - already 0's from mcbist::program's ctor.
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBCFGQ, l_read) );
                REQUIRE( 0x0000000000000081 == l_read );
            }

            // Load thresholds - default state (expecting default threshold register state)
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MBSTRQ, l_read) );
                REQUIRE( 0xffffffff00000000 == l_read );
            }

            // Enable maint addressing mode - enabled by default in the mcbist::program ctor
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBAGRAQ, l_read) );
                REQUIRE( 0x0020000000000000 == l_read );
            }

            // Check the address registers
            {
                fapi2::buffer<uint64_t> l_read;

                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBSA0Q, l_read) );
                REQUIRE(l_read == 0x0);
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBEA0Q, l_read) );
                REQUIRE(l_read == 0x0000001ffc000000);
            }

            // Poll for the fir bit. We expect this to be set ...
            fapi2::buffer<uint64_t> l_status;
            fapi2::buffer<uint64_t> l_last_address;

            // A small vector of addresses to poll during the polling loop
            static const std::vector<mss::poll_probe<fapi2::TARGET_TYPE_MCBIST>> l_probes =
            {
                {i_target, "mcbist current address", MCBIST_MCBMCATQ},
            };

            poll_parameters l_poll_parameters;
            bool l_poll_results = mss::poll(i_target, MCBIST_MCBISTFIRQ, l_poll_parameters,
                                            [&l_status](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
            {
                FAPI_DBG("mcbist firq 0x%llx, remaining: %d", stat_reg, poll_remaining);
                l_status = stat_reg;
                return l_status.getBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>() == true;
            },
            l_probes);

            // Pass or fail output the current address. This is useful for debugging when we can get it.
            REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBMCATQ, l_last_address) );
            FAPI_INF("MCBIST last address: 0x%016lx", l_last_address);

            REQUIRE( l_poll_results == true );

            // Check for errors
            {
                fapi2::buffer<uint64_t> l_read;

                REQUIRE( 0x20000000000000 == (l_status & l_fir_mask) );
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBSTATQ, l_read) );
                REQUIRE(l_read == 0);
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MBSEC1Q, l_read) );
                REQUIRE(l_read == 0);
            }

        }


        SECTION("Test sf_read")
        {
            // Loading of patterns is tested in the mcbist unit test.

            memdiags::stop_conditions l_stops;
            mss::mcbist::constraints l_const(l_stops);

            // The addresses here are calculated so that we get a few iterations
            // of polling on an AWAN, but not so much that we run the risk of timing out
            mss::mcbist::address().get_range<mss::mcbist::address::COL>(l_const.iv_end_address);
            l_const.iv_end_address.set_column(0b111111);
            memdiags::operation<TARGET_TYPE_MCBIST> l_bob(i_target, mss::mcbist::read_subtest<TARGET_TYPE_MCBIST>(),
                    l_const);
            REQUIRE_FALSE( l_bob.multi_port_init() );
            REQUIRE_FALSE( l_bob.execute() );

            // Check the things we default to so that we have a canary in case the defaults change
            // Zero out cmd timebase - mcbist::program constructor does that for us.
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBPARMQ, l_read) );
                REQUIRE( 0 == l_read );
            }

            // Load stop conditions - default state - already 0's from mcbist::program's ctor.
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBCFGQ, l_read) );
                REQUIRE( 0x0000000000000081 == l_read );
            }

            // Load thresholds - default state (expecting default threshold register state)
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MBSTRQ, l_read) );
                REQUIRE( 0xffffffff00000000 == l_read );
            }

            // Enable maint addressing mode - enabled by default in the mcbist::program ctor
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBAGRAQ, l_read) );
                REQUIRE( 0x0020000000000000 == l_read );
            }

            // Check the address registers
            {
                fapi2::buffer<uint64_t> l_read;

                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBSA0Q, l_read) );
                REQUIRE(l_read == 0x0);
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBEA0Q, l_read) );
                REQUIRE(l_read == 0x0000001ffc000000);
            }

            // Poll for the fir bit. We expect this to be set ...
            fapi2::buffer<uint64_t> l_status;
            fapi2::buffer<uint64_t> l_last_address;

            // A small vector of addresses to poll during the polling loop
            static const std::vector<mss::poll_probe<fapi2::TARGET_TYPE_MCBIST>> l_probes =
            {
                {i_target, "mcbist current address", MCBIST_MCBMCATQ},
            };

            poll_parameters l_poll_parameters;
            bool l_poll_results = mss::poll(i_target, MCBIST_MCBISTFIRQ, l_poll_parameters,
                                            [&l_status](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
            {
                FAPI_DBG("mcbist firq 0x%llx, remaining: %d", stat_reg, poll_remaining);
                l_status = stat_reg;
                return l_status.getBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>() == true;
            },
            l_probes);

            // Pass or fail output the current address. This is useful for debugging when we can get it.
            REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBMCATQ, l_last_address) );
            FAPI_INF("MCBIST last address: 0x%016lx", l_last_address);

            REQUIRE( l_poll_results == true );

            // Check for errors
            {
                fapi2::buffer<uint64_t> l_read;

                REQUIRE( 0x20000000000000 == (l_status & l_fir_mask) );
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBSTATQ, l_read) );
                REQUIRE(l_read == 0);
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MBSEC1Q, l_read) );
                REQUIRE(l_read == 0);
            }
        }


        SECTION("Test sf_read to end of port")
        {
            // Loading of patterns is tested in the mcbist unit test.

            // The addresses here are calculated so that we get a few iterations
            // of polling on an AWAN, but not so much that we run the risk of timing out
            mss::mcbist::address l_start;
            mss::mcbist::address().get_range<mss::mcbist::address::DIMM>(l_start);
            l_start.set_bank(0);
            l_start.set_bank_group(0);
            l_start.set_column(0);

            REQUIRE_FALSE( memdiags::sf_read(i_target, mss::mcbist::stop_conditions(), l_start) );

            // Check the things we default to so that we have a canary in case the defaults change
            // Zero out cmd timebase - mcbist::program constructor does that for us.
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBPARMQ, l_read) );
                REQUIRE( 0 == l_read );
            }

            // Load stop conditions - default state - already 0's from mcbist::program's ctor.
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBCFGQ, l_read) );
                REQUIRE( 0x00000000000000a1 == l_read );
            }

            // Load thresholds - default state (expecting default threshold register state)
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MBSTRQ, l_read) );
                REQUIRE( 0xffffffff00000000 == l_read );
            }

            // Enable maint addressing mode - enabled by default in the mcbist::program ctor
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBAGRAQ, l_read) );
                REQUIRE( 0x0020000000000000 == l_read );
            }

            // Check the address registers
            {
                fapi2::buffer<uint64_t> l_read;

                // We use different address end boundaries if we're in sim or not.
                const uint64_t l_end_expect = is_sim ? 0x1fffffe07c000000 : 0x1ffffffffc000000;

                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBSA0Q, l_read) );
                REQUIRE(l_read == 0x1fffffc000000000);
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBEA0Q, l_read) );
                REQUIRE(l_read == l_end_expect);
            }

            // Poll for the fir bit. We expect this to be set ...
            fapi2::buffer<uint64_t> l_status;
            fapi2::buffer<uint64_t> l_last_address;

            // A small vector of addresses to poll during the polling loop
            static const std::vector<mss::poll_probe<fapi2::TARGET_TYPE_MCBIST>> l_probes =
            {
                {i_target, "mcbist current address", MCBIST_MCBMCATQ},
            };

            poll_parameters l_poll_parameters;
            bool l_poll_results = mss::poll(i_target, MCBIST_MCBISTFIRQ, l_poll_parameters,
                                            [&l_status](const size_t poll_remaining,
                                                    const fapi2::buffer<uint64_t>& stat_reg) -> bool
            {
                FAPI_DBG("mcbist firq 0x%llx, remaining: %d", stat_reg, poll_remaining);
                l_status = stat_reg;
                return l_status.getBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>() == true;
            },
            l_probes);

            // Pass or fail output the current address. This is useful for debugging when we can get it.
            REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBMCATQ, l_last_address) );
            FAPI_INF("MCBIST last address: 0x%016lx", l_last_address);

            REQUIRE( l_poll_results == true );

            // Check for errors
            {
                fapi2::buffer<uint64_t> l_read;

                REQUIRE( 0x20000000000000 == (l_status & l_fir_mask) );
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBSTATQ, l_read) );
                REQUIRE(l_read == 0);
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MBSEC1Q, l_read) );
                REQUIRE(l_read == 0);
            }

        }

        SECTION("Test continuous scrub")
        {
            // How many DIMM do we have? This effects the subtests we create
            const auto l_dimm_count = mss::find_targets<TARGET_TYPE_DIMM>(i_target).size();
            FAPI_INF("seeing %d DIMM", l_dimm_count);

            // The addresses here are calculated so that we get a few iterations
            // of polling on an AWAN, but not so much that we run the risk of timing out
            mss::mcbist::address l_start;
            mss::mcbist::address().get_range<mss::mcbist::address::DIMM>(l_start);
            l_start.set_bank(0);
            l_start.set_bank_group(0);
            l_start.set_column(0);

            REQUIRE_FALSE( memdiags::background_scrub(i_target, memdiags::stop_conditions(),
                           memdiags::speed::BG_SCRUB, l_start) );

            // check the state of the mcbist engine

            // Check the iv_parameters
            {
                fapi2::buffer<uint64_t> l_read;
                uint64_t l_size;
                REQUIRE_FALSE( mss::eff_memory_size(i_target, l_size) );
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBPARMQ, l_read) );

                FAPI_INF("seeing memory size %d", l_size);

                switch (l_size)
                {
                    case 128:
                        REQUIRE(l_read == 0x68000000000000);
                        break;

                    case 64:
                        REQUIRE(l_read == 0xC8000000000000);
                        break;

                    default:
                        FAIL("Memory size not supported");
                        break;
                };
            }

            // Check the address registers
            {
                // Address config 0 should have the start and end for a complete DIMM (in sim)
                fapi2::buffer<uint64_t> l_read;

                // We use different address end boundaries if we're in sim or not.
                const uint64_t l_end_expect = is_sim ? 0x000000207C000000 : 0x1ffffffffc000000;

                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBSA0Q, l_read) );
                REQUIRE(l_read == 0x0);
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBEA0Q, l_read) );
                REQUIRE(l_read == l_end_expect);
            }
            {
                // Address 1 should have the start we configured and an end which is the
                // real end of the DIMM address range
                fapi2::buffer<uint64_t> l_read;

                // We use different address end boundaries if we're in sim or not.
                const uint64_t l_end_expect = is_sim ? 0x1fffffe07c000000 : 0x1ffffffffc000000;

                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBSA1Q, l_read) );
                REQUIRE(l_read == 0x1fffffc000000000);
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBEA1Q, l_read) );
                REQUIRE(l_read == l_end_expect);
            }

            // Check the subtests
            {
                if (l_dimm_count == 8)
                {
                    fapi2::buffer<uint64_t> l_read;

                    REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBMR0Q, l_read) );
                    REQUIRE(l_read == 0x9009718090089208);
                    REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBMR1Q, l_read) );
                    REQUIRE(l_read == 0x9408960898089a08);
                    REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBMR2Q, l_read) );
                    REQUIRE(l_read == 0x9c089e0871040000);
                }
            }

            // Make sure continuous scrub doesn't set the FIR bit. More for verifying our actions than
            // anything else
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBISTFIRQ, l_read) );
                REQUIRE( l_read.getBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>() == false );
            }

            // We should have the LEN64 bit turned off
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBCFGQ, l_read) );
                REQUIRE( 0x0000000000000001 == l_read );
            }


        }

        SECTION("Test targeted scrub")
        {
            // Test that passing in no-stop is a bug
            REQUIRE( memdiags::targeted_scrub(i_target, memdiags::stop_conditions(),
                                              memdiags::speed::LUDICROUS, mss::mcbist::address(),
                                              memdiags::end_boundary::NONE) );

            REQUIRE_FALSE( memdiags::targeted_scrub(i_target, memdiags::stop_conditions(),
                                                    memdiags::speed::LUDICROUS, mss::mcbist::address(),
                                                    memdiags::end_boundary::STOP_AFTER_MASTER_RANK) );

            // Make sure targeted scrub sets the FIR bit. More for verifying our actions than
            // anything else
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBISTFIRQ, l_read) );
                REQUIRE( l_read.getBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>() == true );
            }

            // Check the address registers
            {
                // Address config 0 should have the start and end for a complete DIMM (in sim)
                fapi2::buffer<uint64_t> l_read;

                // We use different address end boundaries if we're in sim or not.
                const uint64_t l_end_expect = is_sim ? 0x000000207C000000 : 0x1ffffffffc000000;

                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBSA0Q, l_read) );
                REQUIRE(l_read == 0x0);
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBEA0Q, l_read) );
                REQUIRE(l_read == l_end_expect);
            }

            // Check the subtests
            {
                fapi2::buffer<uint64_t> l_read;

                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBMR0Q, l_read) );
                REQUIRE(l_read == 0x900c000000000000);
            }

            // We should have the LEN64 bit turned off but we turned on pause-on-rank boundary
            {
                fapi2::buffer<uint64_t> l_read;
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBCFGQ, l_read) );
                REQUIRE( 0x0000000020000041 == l_read );
            }

        }

        SECTION("Test what happens on stop-after-rank")
        {
            mss::mcbist::address l_start_address;
            mss::mcbist::address l_end_address;
            fapi2::ReturnCode l_rc;

            // Make our start be really close to the end of the rank an our end be the end so we
            // can check to see what happens at the end of the rank
            l_start_address.get_range<mss::mcbist::address::MRANK>(l_end_address);
            l_start_address = l_end_address - 10;

            memdiags::constraints l_const(memdiags::stop_conditions(), memdiags::speed::LUDICROUS,
                                          memdiags::end_boundary::STOP_AFTER_MASTER_RANK,
                                          l_start_address);

            l_const.iv_end_address = l_end_address;

            memdiags::targeted_scrub_operation<TARGET_TYPE_MCBIST> l_op(i_target, l_const, l_rc);

            REQUIRE_FALSE( l_rc );

            // Add a goto on to the end of this program so that if it stops we know it stopped because
            // of the rank boundary.
            l_op.get_program().iv_subtests.push_back(mss::mcbist::goto_subtest<TARGET_TYPE_MCBIST>(0));

            REQUIRE_FALSE( l_op.execute() );

            // A small vector of addresses to poll during the polling loop
            static const std::vector<mss::poll_probe<fapi2::TARGET_TYPE_MCBIST>> l_probes =
            {
                {i_target, "mcbist current address", MCBIST_MCBMCATQ},
            };

            poll_parameters l_poll_parameters;
            fapi2::buffer<uint64_t> l_status;
            fapi2::buffer<uint64_t> l_last_address;

            bool l_poll_results = mss::poll(i_target, MCBIST_MCBISTFIRQ, l_poll_parameters,
                                            [&l_status](const size_t poll_remaining,
                                                    const fapi2::buffer<uint64_t>& stat_reg) -> bool
            {
                FAPI_DBG("mcbist firq 0x%llx, remaining: %d", stat_reg, poll_remaining);
                l_status = stat_reg;
                return l_status.getBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>() == true;
            },
            l_probes);

            // Pass or fail output the current address. This is useful for debugging when we can get it.
            REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBMCATQ, l_last_address) );
            FAPI_INF("MCBIST last address: 0x%016lx", l_last_address);

            REQUIRE( l_poll_results == true );

            // Check for errors
            {
                fapi2::buffer<uint64_t> l_read;

                REQUIRE( 0x20000000000000 == (l_status & l_fir_mask) );
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBSTATQ, l_read) );
                REQUIRE(l_read == 0);
                REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MBSEC1Q, l_read) );
                REQUIRE(l_read == 0);
            }

            // We asked to stop at the end of a rank, so we should not be able to continue to the end of the rank
            REQUIRE( memdiags::continue_cmd(i_target, memdiags::end_boundary::STOP_AFTER_MASTER_RANK) );

            // Continue but ask to stop at the end of the subtest
            REQUIRE_FALSE( memdiags::continue_cmd(i_target, memdiags::end_boundary::STOP_AFTER_SUBTEST) );

            l_poll_results = mss::poll(i_target, MCBIST_MCBISTFIRQ, l_poll_parameters,
                                       [&l_status](const size_t poll_remaining,
                                                   const fapi2::buffer<uint64_t>& stat_reg) -> bool
            {
                FAPI_DBG("mcbist firq 0x%llx, remaining: %d", stat_reg, poll_remaining);
                l_status = stat_reg;
                return l_status.getBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>() == true;
            },
            l_probes);

            // Pass or fail output the current address. This is useful for debugging when we can get it.
            REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBMCATQ, l_last_address) );
            FAPI_INF("MCBIST last address: 0x%016lx", l_last_address);

            REQUIRE( l_poll_results == true );
        }

        // Reset and check that unmasking sets all the right bits
        {
            REQUIRE_FALSE( mss::putScom(i_target, MCBIST_MCBISTFIRACT0, 0) );
            REQUIRE_FALSE( mss::putScom(i_target, MCBIST_MCBISTFIRACT1, 0) );
            REQUIRE_FALSE( mss::putScom(i_target, MCBIST_MCBISTFIRMASK_AND, 0) );

            REQUIRE_FALSE( mss::unmask_memdiags_errors(i_target) );

            fapi2::buffer<uint64_t> l_mcbistfir_mask;
            fapi2::buffer<uint64_t> l_mcbistfir_action0;
            fapi2::buffer<uint64_t> l_mcbistfir_action1;

            REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBISTFIRACT0, l_mcbistfir_action0) );
            REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBISTFIRACT1, l_mcbistfir_action1) );
            REQUIRE_FALSE( mss::getScom(i_target, MCBIST_MCBISTFIRMASK_AND, l_mcbistfir_mask) );

            REQUIRE( 0x0020000000000000 == l_mcbistfir_action0);
            REQUIRE( 0x0000000000000000 == l_mcbistfir_action1);
            REQUIRE( 0xffdfffffffffffff == l_mcbistfir_mask);
        }
        return 0;
    });
}

} // ns test
} // ns mss
