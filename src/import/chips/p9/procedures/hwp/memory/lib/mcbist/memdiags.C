/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mcbist/memdiags.C $        */
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
/// @file memdiags.C
/// @brief Run and manage the MEMDIAGS engine
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/mcbist/memdiags.H>
#include <lib/mcbist/mcbist.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/settings.H>
#include <lib/mcbist/sim.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::FAPI2_RC_SUCCESS;

namespace memdiags
{

///
/// @brief Stop the current command
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode stop( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_INF("Stopping any mcbist operations which are in progress");

    // TODO RTC:153951 Add masking of FIR when stopping
    return mss::mcbist::start_stop(i_target, mss::STOP);
}

///
/// @brief memdiags::base initializer
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note specialized for Nimbus as the port select mechanism is different
///
template<>
fapi2::ReturnCode memdiags::base<TARGET_TYPE_MCBIST>::init()
{
    FAPI_INF("memdiags base init");

    // Check the state of the MCBIST engine to make sure its OK that we proceed.
    // Force stop the engine (per spec, as opposed to waiting our turn)
    FAPI_TRY( memdiags::stop(iv_target) );

    // Zero out cmd timebase - mcbist::program constructor does that for us.
    // Load pattern
    FAPI_TRY( mss::mcbist::load_pattern(iv_target, iv_const.iv_pattern) );

    // Load stop conditions
    iv_program.change_stops(iv_const.iv_stop);

    // Load thresholds
    FAPI_TRY( mss::mcbist::load_thresholds(iv_target, iv_const.iv_thresholds) );

    // A superfast operation which has an end address of 0 means 'to the end'
    if (iv_const.iv_end_address == 0)
    {
        iv_const.iv_start_address.get_range<memdiags::address::DIMM>(iv_const.iv_end_address);
    }

    // Enable maint addressing mode - enabled by default in the mcbist::program ctor
    // Configure the address range
    FAPI_TRY( mss::mcbist::config_address_range0(iv_target, iv_const.iv_start_address, iv_const.iv_end_address) );

    // Apparently the MCBIST engine needs the ports selected even tho the ports are specified
    // in the subtest. We can just select them all, and it adjusts when it executes the subtest
    iv_program.select_ports(0b1111);

    // Kick it off, don't wait for a result
    iv_program.change_async(mss::ON);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Super Fast Base initializer
/// @note Uses broadcast mode if possible
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template<>
fapi2::ReturnCode memdiags::sf_operation<TARGET_TYPE_MCBIST>::init()
{
    FAPI_INF("superfast init");

    // Initialize the base class
    FAPI_TRY( base::init() );

    // Deterimine which ports are functional and whether we can broadcast to them
    // TK on the broadcast BRS
    // Disable braodcast mode - disabled by default
    // For each functional port, setup 2 INIT subtests, one per DIMM select
    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(iv_target))
    {
        // Run in ECC mode, 64B writes (superfast mode)
        for (const auto& d : mss::find_targets<TARGET_TYPE_DIMM>(p))
        {
            // Don't destroy the subtest passed in, copy it
            mss::mcbist::subtest_t<TARGET_TYPE_MCBIST> l_subtest = iv_subtest;

            l_subtest.enable_port(mss::relative_pos<TARGET_TYPE_MCBIST>(p));
            l_subtest.enable_dimm(mss::index(d));
            iv_program.iv_subtests.push_back(l_subtest);
            FAPI_INF("adding superfast subtest for %s (dimm %d)", mss::c_str(d), mss::index(d));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Super Fast Read (End of Port) initializer
/// @note Uses broadcast mode if possible
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template<>
fapi2::ReturnCode memdiags::sf_read_operation<TARGET_TYPE_MCBIST>::end_of_port_init()
{
    FAPI_INF("superfast read (end of port) init");

    const uint64_t l_relative_port_number = iv_const.iv_start_address.get_port();
    const uint64_t l_dimm_number = iv_const.iv_start_address.get_dimm();

    // Initialize the base class
    FAPI_TRY( base::init() );

    // Make sure the specificed port is functional
    FAPI_ASSERT( mss::is_functional<TARGET_TYPE_MCA>(iv_target, l_relative_port_number),
                 fapi2::MSS_MEMDIAGS_PORT_NOT_FUNCTIONAL()
                 .set_RELATIVE_PORT_POSITION(l_relative_port_number)
                 .set_ADDRESS( uint64_t(iv_const.iv_start_address) )
                 .set_TARGET(iv_target),
                 "Port with relative postion %d is not functional", l_relative_port_number );

    // The address should have the port and DIMM noted in it. All we need to do is calculate the
    // remainder of the address
    iv_const.iv_start_address.get_range<memdiags::address::DIMM>(iv_const.iv_end_address);

    // No broadcast mode for this one
    // Push on a read subtest
    {
        mss::mcbist::subtest_t<TARGET_TYPE_MCBIST> l_subtest = iv_subtest;

        l_subtest.enable_port(l_relative_port_number);
        l_subtest.enable_dimm(l_dimm_number);
        iv_program.iv_subtests.push_back(l_subtest);
        FAPI_INF("adding superfast read remainder of port %d, DIMM %d", l_relative_port_number, l_dimm_number);
    }

    return FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Super Fast Read Init - used to init all memory behind a target with a given pattern
/// @note Uses broadcast mode if possible
/// @param[in] i_target the target behind which all memory should be initialized
/// @param[in] i_pattern an index representing a pattern to use to initize memory (defaults to 0)
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
///
template<>
fapi2::ReturnCode sf_init( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                           const uint64_t i_pattern )
{
    FAPI_INF("superfast init start");

    // If we're running in the simulator, we want to only touch the addresses which training touched
    uint8_t is_sim = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<TARGET_TYPE_SYSTEM>(), is_sim) );

    if (is_sim)
    {
        // Use some sort of pattern in sim in case the verification folks need to look for something
        // TK. Need a verification pattern. This is a not-good pattern for verification ... We don't really
        // have a good pattern for verification defined.
        FAPI_INF("running mss sim init in place of sf_init");
        return mss::mcbist::sim::sf_init(i_target, i_pattern);
    }
    else
    {
        fapi2::ReturnCode l_rc;
        sf_init_operation<TARGET_TYPE_MCBIST> l_init_op(i_target, i_pattern, l_rc);

        FAPI_ASSERT( l_rc == FAPI2_RC_SUCCESS,
                     fapi2::MSS_MEMDIAGS_SUPERFAST_INIT_FAILED_TO_INIT().set_TARGET(i_target),
                     "Unable to initialize the MCBIST engine for a sf read %s", mss::c_str(i_target) );

        return l_init_op.execute();
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Super Fast Read All - used to run superfast read on all memory behind the target
/// @note Uses broadcast mode if possible
/// @param[in] i_target the target behind which all memory should be read
/// @param[in] i_stop stop conditions
/// @param[in] i_thresholds thresholds
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
///
template<>
fapi2::ReturnCode sf_read( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                           const memdiags::stop_conditions i_stop,
                           const memdiags::thresholds& i_thresholds )
{
    FAPI_INF("superfast read start");

    fapi2::ReturnCode l_rc;
    sf_read_operation<TARGET_TYPE_MCBIST> l_read_op(i_target, i_stop, i_thresholds, l_rc);

    FAPI_ASSERT( l_rc == FAPI2_RC_SUCCESS,
                 fapi2::MSS_MEMDIAGS_SUPERFAST_READ_FAILED_TO_INIT().set_TARGET(i_target),
                 "Unable to initialize the MCBIST engine for a sf read %s", mss::c_str(i_target) );

    return l_read_op.execute();

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Super Fast Read to End of Port - used to run superfast read on all memory behind the target
/// @param[in] i_target the target behind which all memory should be read
/// @param[in] i_stop stop conditions
/// @param[in] i_thresholds thresholds
/// @param[in] i_address mcbist::address representing the port, dimm, rank
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
///
template<>
fapi2::ReturnCode sf_read( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                           const memdiags::stop_conditions i_stop,
                           const memdiags::thresholds& i_thresholds,
                           const memdiags::address& i_address )
{
    FAPI_INF("superfast read - end of port");

    fapi2::ReturnCode l_rc;
    sf_read_operation<TARGET_TYPE_MCBIST> l_read_op(i_target, i_stop, i_thresholds, i_address, l_rc);

    FAPI_ASSERT( l_rc == FAPI2_RC_SUCCESS,
                 fapi2::MSS_MEMDIAGS_SUPERFAST_READ_FAILED_TO_INIT().set_TARGET(i_target),
                 "Unable to initialize the MCBIST engine for a sf read %s", mss::c_str(i_target) );

    return l_read_op.execute();

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Scrub - scrub all memory behind the target
/// @param[in] i_target the target behind which all memory should be scrubbed
/// @param[in] i_stop stop conditions
/// @param[in] i_thresholds thresholds
/// @param[in] i_speed the speed to scrub
/// @param[in] i_address mcbist::address representing the port, dimm, rank
/// @param[in] i_end whether to end, and where (default = continuous scrub)
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
///
template<>
fapi2::ReturnCode scrub( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                         const memdiags::stop_conditions i_stop,
                         const memdiags::thresholds& i_thresholds,
                         const memdiags::speed i_speed,
                         const memdiags::address& i_address,
                         const memdiags::end_boundary i_end )
{
    // TK implementation (because Glancy couldn't figure that out <grin>)
    FAPI_INF("scrub");
    return FAPI2_RC_SUCCESS;
}

///
/// @brief Continue current command on next address
/// The current commaand has paused on an error, so we can record the address of the error
/// and finish the current master or slave rank.
/// @param[in] i_target the target
/// @param[in] i_end whether to end, and where (default = don't stop at end of rank)
/// @param[in] i_stop stop conditions (default - 0 meaning 'don't change conditions')
/// @param[in] i_speed the speed to scrub (default - NO_CHANGE meaning leave speed untouched)
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode continue_cmd( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                                const memdiags::end_boundary i_end,
                                const memdiags::stop_conditions i_stop,
                                const memdiags::speed i_speed )
{
    // TK implementation (because Glancy couldn't figure that out <grin>)
    FAPI_INF("continue_cmd");
    return FAPI2_RC_SUCCESS;
}

///
/// @brief Continue current command on next address - change thresholds
/// The current commaand has paused on an error, so we can record the address of the error
/// and finish the current master or slave rank.
/// @param[in] i_target the target
/// @param[in] i_thresholds new thresholds
/// @param[in] i_end whether to end, and where (default = don't stop at end of rank)
/// @param[in] i_stop stop conditions (default - 0 meaning 'don't change conditions')
/// @param[in] i_speed the speed to scrub (default - NO_CHANGE meaning leave speed untouched)
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode continue_cmd( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                                const memdiags::thresholds& i_thresholds,
                                const memdiags::end_boundary i_end,
                                const memdiags::stop_conditions i_stop,
                                const memdiags::speed i_speed )
{
    // TK implementation (because Glancy couldn't figure that out <grin>)
    FAPI_INF("continue_cmd - change thresholds");
    return FAPI2_RC_SUCCESS;
}

}
