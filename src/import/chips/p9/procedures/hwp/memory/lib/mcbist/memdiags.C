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

#include <lib/utils/poll.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::FAPI2_RC_SUCCESS;
using fapi2::FAPI2_RC_INVALID_PARAMETER;

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
    // Too long, make shorter
    using TT = mss::mcbist::mcbistTraits<TARGET_TYPE_MCBIST>;

    // Poll parameters are defined as TK so that we wait a nice time for operations
    // For now use the defaults
    mss::poll_parameters l_poll_parameters;
    fapi2::buffer<uint64_t> l_status;
    fapi2::buffer<uint64_t> l_last_address;
    bool l_poll_result = false;

    FAPI_INF("Stopping any mcbist operations which are in progress");

    // TODO RTC:153951 Add masking of FIR when stopping
    FAPI_TRY( mss::mcbist::start_stop(i_target, mss::STOP) );

    // Poll waiting for the engine to stop
    l_poll_result = mss::poll(i_target, TT::STATQ_REG, l_poll_parameters,
                              [&l_status](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_DBG("looking for mcbist not in-progress, mcbist statq 0x%llx, remaining: %d", stat_reg, poll_remaining);
        l_status = stat_reg;
        // We're done polling when either we see we're in progress or we see we're done.
        return l_status.getBit<TT::MCBIST_IN_PROGRESS>() == false;
    });

    // Pass or fail output the current address. This is useful for debugging when we can get it.
    // It's in the register FFDC for memdiags so we don't need it below
    FAPI_TRY( mss::getScom(i_target, TT::LAST_ADDR_REG, l_last_address) );
    FAPI_INF("MCBIST last address (during stop): 0x%016lx", l_last_address);

    // So we've either stopped or we timed out
    FAPI_ASSERT( l_poll_result == true,
                 fapi2::MSS_MEMDIAGS_MCBIST_FAILED_TO_STOP().set_TARGET(i_target),
                 "The MCBIST engine failed to stop its program" );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief memdiags init helper
/// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
/// in subclassed constructors more easily.
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template<>
fapi2::ReturnCode operation<TARGET_TYPE_MCBIST>::base_init()
{
    FAPI_INF("memdiags base init");

    // Check the state of the MCBIST engine to make sure its OK that we proceed.
    // Force stop the engine (per spec, as opposed to waiting our turn)
    FAPI_TRY( memdiags::stop(iv_target) );

    // Zero out cmd timebase - mcbist::program constructor does that for us.
    // Load pattern
    FAPI_TRY( iv_program.change_pattern(iv_const.iv_pattern) );

    // Load stop conditions
    iv_program.change_stops(iv_const.iv_stop);

    // Load end boundaries
    iv_program.change_end_boundary(iv_const.iv_end_boundary);

    // Load thresholds
    iv_program.change_thresholds(iv_const.iv_thresholds);

    // Setup the requested speed
    FAPI_TRY( iv_program.change_speed(iv_target, iv_const.iv_speed) );

    // Enable maint addressing mode - enabled by default in the mcbist::program ctor

    // Apparently the MCBIST engine needs the ports selected even tho the ports are specified
    // in the subtest. We can just select them all, and it adjusts when it executes the subtest
    iv_program.select_ports(0b1111);

    // Kick it off, don't wait for a result
    iv_program.change_async(mss::ON);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief memdiags multi-port init helper
/// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
/// in subclassed constructors more easily.
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template<>
fapi2::ReturnCode operation<TARGET_TYPE_MCBIST>::multi_port_init()
{
    FAPI_INF("multi-port init %s", mss::c_str(iv_target));

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
            auto l_subtest = iv_subtest;

            l_subtest.enable_port(mss::relative_pos<TARGET_TYPE_MCBIST>(p));
            l_subtest.enable_dimm(mss::index(d));
            iv_program.iv_subtests.push_back(l_subtest);
            FAPI_INF("adding superfast subtest for %s (dimm %d)", mss::c_str(d), mss::index(d));
        }
    }

    // A operation which has an end address of 0 means 'to the end'
    if (iv_const.iv_end_address == 0)
    {
        iv_const.iv_start_address.get_range<mss::mcbist::address::DIMM>(iv_const.iv_end_address);
    }

    // Configure the address range
    FAPI_TRY( mss::mcbist::config_address_range0(iv_target, iv_const.iv_start_address, iv_const.iv_end_address) );

    // Initialize the common sections
    FAPI_TRY( base_init() );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Single port initializer
/// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
/// in subclassed constructors more easily.
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template<>
fapi2::ReturnCode operation<TARGET_TYPE_MCBIST>::single_port_init()
{
    FAPI_INF("single port init");

    const uint64_t l_relative_port_number = iv_const.iv_start_address.get_port();
    const uint64_t l_dimm_number = iv_const.iv_start_address.get_dimm();

    // Make sure the specificed port is functional
    FAPI_ASSERT( mss::is_functional<TARGET_TYPE_MCA>(iv_target, l_relative_port_number),
                 fapi2::MSS_MEMDIAGS_PORT_NOT_FUNCTIONAL()
                 .set_RELATIVE_PORT_POSITION(l_relative_port_number)
                 .set_ADDRESS( uint64_t(iv_const.iv_start_address) )
                 .set_TARGET(iv_target),
                 "Port with relative postion %d is not functional", l_relative_port_number );

    // No broadcast mode for this one
    // Push on a read subtest
    {
        mss::mcbist::subtest_t<TARGET_TYPE_MCBIST> l_subtest = iv_subtest;

        l_subtest.enable_port(l_relative_port_number);
        l_subtest.enable_dimm(l_dimm_number);
        iv_program.iv_subtests.push_back(l_subtest);
        FAPI_INF("adding subtest 0x%x for port %d, DIMM %d", l_subtest, l_relative_port_number, l_dimm_number);
    }

    // The address should have the port and DIMM noted in it. All we need to do is calculate the
    // remainder of the address, assuming the caller didn't setup an end address already.
    // *INDENT-OFF*
    if (iv_const.iv_end_address == 0)
    {
        iv_is_sim ?
            iv_const.iv_start_address.get_sim_end_address(iv_const.iv_end_address) :
            iv_const.iv_start_address.get_range<mss::mcbist::address::DIMM>(iv_const.iv_end_address);
    }
    // *INDENT-ON*

    // Configure the address range
    FAPI_TRY( mss::mcbist::config_address_range0(iv_target, iv_const.iv_start_address, iv_const.iv_end_address) );

    // Initialize the common sections
    FAPI_TRY( base_init() );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief memdiags::continuous_scrub_operation constructor
/// @param[in] i_target the target of the mcbist engine
/// @param[in] i_const the contraints of the operation
/// @param[out] o_rc the fapi2::ReturnCode of the intialization process
///
template<>
continuous_scrub_operation<TARGET_TYPE_MCBIST>::continuous_scrub_operation(
    const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
    const constraints i_const,
    fapi2::ReturnCode& o_rc ):
    operation<TARGET_TYPE_MCBIST>(i_target, mss::mcbist::scrub_subtest<TARGET_TYPE_MCBIST>(), i_const)
{
    mss::mcbist::address l_generic_start_address;
    mss::mcbist::address l_generic_end_address;

    FAPI_INF("setting up for continuous scrub");

    // Scrub operations run 128B
    iv_program.change_len64(mss::OFF);

    // We build a little program here which allows us to restart the loop in the event of a pause.
    // So we need to craft some of the address ranges and some of the subtests by hand.

    // Setup address config 0 to cover all the addresses for a port/dimm.
    // We leverage the MCBIST's ability to skip invalid addresses, and just setup
    // If we're running in the simulator, we want to only touch the addresses which training touched
    // *INDENT-OFF*
    iv_is_sim ?
        l_generic_start_address.get_sim_end_address(l_generic_end_address) :
        l_generic_start_address.get_range<mss::mcbist::address::DIMM>(l_generic_end_address);
    // *INDENT-ON*

    FAPI_TRY( mss::mcbist::config_address_range0(i_target, l_generic_start_address, l_generic_end_address) );

    // We push on a fake subtest 0 and subtest 1. We fix them up after we fill in the
    // rest of the subtests.
    iv_program.iv_subtests.push_back(iv_subtest);
    iv_program.iv_subtests.push_back(iv_subtest);

    // a generic 0 - DIMM address range.
    //
    // Subtests 2-9: One subtest per port/dimm each covering the whole range of that
    // port/dimm. scrub_subtests by default are using address config 0, so each of
    // these get their full address complement.
    for (const auto& p : iv_target.template getChildren<TARGET_TYPE_MCA>())
    {
        for (const auto& d : p.template getChildren<TARGET_TYPE_DIMM>())
        {
            // Don't destroy the subtest passed in, copy it
            auto l_subtest = iv_subtest;

            l_subtest.enable_port(mss::relative_pos<TARGET_TYPE_MCBIST>(p));
            l_subtest.enable_dimm(mss::index(d));
            iv_program.iv_subtests.push_back(l_subtest);
            FAPI_INF("adding scrub subtest for %s (dimm %d) (0x%x)", mss::c_str(d), mss::index(d), l_subtest);
        }
    }

    //
    // Subtest 10: goto subtest 2. This causes us to loop back to the first port/dimm and go thru them all
    // This subtest will be marked the last when the MCBMR registers are filled in.
    //
    iv_program.iv_subtests.push_back(mss::mcbist::goto_subtest<TARGET_TYPE_MCBIST>(2));
    FAPI_INF("last goto subtest (10) is going to subtest 2 (0x%x)", iv_program.iv_subtests[2]);

    // Ok, now we can go back in to fill in the first two subtests.

    {
        auto l_subtest = iv_subtest;
        auto l_port = iv_const.iv_start_address.get_port();
        auto l_dimm = iv_const.iv_start_address.get_dimm();
        size_t l_index = 2;

        // By default if we don't find our port/dimm in the subtests, we just go back to the beginning.
        uint64_t l_goto_subtest = 2;

        //
        // subtest 0
        //

        // load the start address given and calculate the end address. Stick this into address config 1
        // We don't need to account for the simulator here as the caller can do that when they setup the
        // start address.
        // *INDENT-OFF*
        iv_is_sim ?
            iv_const.iv_start_address.get_sim_end_address(iv_const.iv_end_address) :
            iv_const.iv_start_address.get_range<mss::mcbist::address::DIMM>(iv_const.iv_end_address);
        // *INDENT-ON*

        FAPI_TRY( mss::mcbist::config_address_range1(i_target, iv_const.iv_start_address, iv_const.iv_end_address) );

        // We need to use this address range. We know it's ok to write to element 0 as we pushed it on above
        l_subtest.change_addr_sel(1);
        l_subtest.enable_port(l_port);
        l_subtest.enable_dimm(l_dimm);

        iv_program.iv_subtests[0] = l_subtest;
        FAPI_INF("adding scrub subtest 0 for port %d dimm %d (0x%02x)", l_port, l_dimm, l_subtest);

        //
        // subtest 1
        //

        // From the port/dimm specified in the start address, we know what subtest should execute next. The idea
        // being that this 0'th subtest is a mechanism to allow the caller to start a scrub 'in the middle' and
        // jump to the next port/dimm which would have been scrubbed. The hard part is that we don't know where
        // in the subtest vector the 'next' port/dimm are placed. So we look for our port/dimm (skipping subtest 0
        // since we know that's us and skipping subtest 1 since it isn't there yet.)
        for (; l_index < iv_program.iv_subtests.size(); ++l_index)
        {
            auto l_my_dimm = iv_program.iv_subtests[l_index].get_dimm();
            auto l_my_port = iv_program.iv_subtests[l_index].get_port();

            if ((l_dimm == l_my_dimm) && (l_port == l_my_port))
            {
                l_goto_subtest = l_index + 1;
                break;
            }
        }

        // Since we set l_goto_subtest up with a meaningful default, we can just make a subtest with the
        // l_goto_subtest subtest specified and pop that in to index 1.
        FAPI_INF("adding scrub subtest 1 to goto subtest %d (port %d, dimm %d, test 0x%02x)", l_goto_subtest,
                 iv_program.iv_subtests[l_goto_subtest].get_port(),
                 iv_program.iv_subtests[l_goto_subtest].get_dimm(),
                 iv_program.iv_subtests[l_goto_subtest] );

        iv_program.iv_subtests[1] = mss::mcbist::goto_subtest<TARGET_TYPE_MCBIST>(l_goto_subtest);
    }

    // Initialize the common sections
    FAPI_TRY( base_init() );

fapi_try_exit:
    o_rc = fapi2::current_err;
    return;
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

    uint8_t is_sim = false;
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
        constraints l_const(i_pattern);
        sf_init_operation<TARGET_TYPE_MCBIST> l_init_op(i_target, l_const, l_rc);

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
                           const stop_conditions i_stop,
                           const thresholds& i_thresholds )
{
    FAPI_INF("superfast read start");

    fapi2::ReturnCode l_rc;
    constraints l_const(i_stop, i_thresholds);
    sf_read_operation<TARGET_TYPE_MCBIST> l_read_op(i_target, l_const, l_rc);

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
                           const stop_conditions i_stop,
                           const thresholds& i_thresholds,
                           const mss::mcbist::address& i_address )
{
    FAPI_INF("superfast read - end of port");

    fapi2::ReturnCode l_rc;
    constraints l_const(i_stop, i_thresholds, i_address);
    sf_read_eop_operation<TARGET_TYPE_MCBIST> l_read_op(i_target, l_const, l_rc);

    FAPI_ASSERT( l_rc == FAPI2_RC_SUCCESS,
                 fapi2::MSS_MEMDIAGS_SUPERFAST_READ_FAILED_TO_INIT().set_TARGET(i_target),
                 "Unable to initialize the MCBIST engine for a sf read %s", mss::c_str(i_target) );

    return l_read_op.execute();

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Scrub - continuous scrub all memory behind the target
/// @param[in] i_target the target behind which all memory should be scrubbed
/// @param[in] i_stop stop conditions
/// @param[in] i_thresholds thresholds
/// @param[in] i_speed the speed to scrub
/// @param[in] i_address mcbist::address representing the port, dimm, rank
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
///
template<>
fapi2::ReturnCode background_scrub( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                                    const stop_conditions i_stop,
                                    const thresholds& i_thresholds,
                                    const speed i_speed,
                                    const mss::mcbist::address& i_address )
{
    FAPI_INF("continuous (background) scrub");

    fapi2::ReturnCode l_rc;
    constraints l_const(i_stop, i_thresholds, i_speed, end_boundary::NONE, i_address);
    continuous_scrub_operation<TARGET_TYPE_MCBIST> l_op(i_target, l_const, l_rc);

    FAPI_ASSERT( l_rc == FAPI2_RC_SUCCESS,
                 fapi2::MSS_MEMDIAGS_CONTINUOUS_SCRUB_FAILED_TO_INIT().set_TARGET(i_target),
                 "Unable to initialize the MCBIST engine for a continuous scrub %s", mss::c_str(i_target) );

    return l_op.execute();

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Scrub - targeted scrub all memory behind the target
/// @param[in] i_target the target behind which all memory should be scrubbed
/// @param[in] i_stop stop conditions
/// @param[in] i_thresholds thresholds
/// @param[in] i_speed the speed to scrub
/// @param[in] i_address mcbist::address representing the port, dimm, rank
/// @param[in] i_end whether to end, and where
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
///
template<>
fapi2::ReturnCode targeted_scrub( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                                  const stop_conditions i_stop,
                                  const thresholds& i_thresholds,
                                  const speed i_speed,
                                  const mss::mcbist::address& i_address,
                                  const end_boundary i_end )
{
    FAPI_INF("targeted scrub");

    if (i_stop == memdiags::stop_conditions::DONT_STOP)
    {
        FAPI_ERR("targeted scrub must have stop conditions");
        return FAPI2_RC_INVALID_PARAMETER;
    }

    fapi2::ReturnCode l_rc;
    constraints l_const(i_stop, i_thresholds, i_speed, i_end, i_address);
    targeted_scrub_operation<TARGET_TYPE_MCBIST> l_op(i_target, l_const, l_rc);

    FAPI_ASSERT( l_rc == FAPI2_RC_SUCCESS,
                 fapi2::MSS_MEMDIAGS_TARGETED_SCRUB_FAILED_TO_INIT().set_TARGET(i_target),
                 "Unable to initialize the MCBIST engine for a targeted scrub %s", mss::c_str(i_target) );

    return l_op.execute();

fapi_try_exit:
    return fapi2::current_err;
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
/// @note overloaded as there's no 'invalid' state for thresholds.
///
template<>
fapi2::ReturnCode continue_cmd( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                                const thresholds& i_thresholds,
                                const end_boundary i_end,
                                const stop_conditions i_stop,
                                const speed i_speed )
{
    // Too long, make shorter
    using TT = mss::mcbist::mcbistTraits<TARGET_TYPE_MCBIST>;

    // We can use a local mcbist::program to help with the bit processing, and then write just the registers we touch.
    mss::mcbist::program<TARGET_TYPE_MCBIST> l_program;
    fapi2::buffer<uint64_t> l_status;

    FAPI_INF("continue_cmd");

    // TODO RTC:155518 Check for stop or in progress before allowing continue. Not critical
    // as the caller should know and can check the in-progress bit in the event they don't

    // This is OK as because the i_end is optional, for the caller to specify a
    // stop condition other than DONT_CHANGE, they'd have to specify the end too
    // It doean't make any sense to have a 'don't stop' in the end boundaries as
    // you need to tell the stop conditions that.
    if (i_stop != stop_conditions::DONT_CHANGE)
    {
        // Before we go too far, check to see if we're already stopped at the boundary we are asking to stop at
        bool l_stopped_at_boundary = false;
        uint64_t l_error_mode = 0;

        FAPI_TRY( mss::getScom(i_target, MCBIST_MCBCFGQ, l_program.iv_config) );
        l_program.iv_config.extractToRight<TT::CFG_PAUSE_ON_ERROR_MODE, TT::CFG_PAUSE_ON_ERROR_MODE_LEN>(l_error_mode);

        switch (i_stop)
        {
            case stop_conditions::STOP_AFTER_ADDRESS:
                l_stopped_at_boundary =
                    l_program.iv_config.getBit<TT::MCBIST_CFG_FORCE_PAUSE_AFTER_ADDR>() ||
                    l_error_mode == stop_conditions::STOP_AFTER_ADDRESS;
                break;

            case stop_conditions::STOP_AFTER_RANK:
                l_stopped_at_boundary =
                    l_program.iv_config.getBit<TT::MCBIST_CFG_PAUSE_AFTER_RANK>() ||
                    l_error_mode == stop_conditions::STOP_AFTER_RANK;
                break;

            case stop_conditions::STOP_AFTER_SUBTEST:
                l_stopped_at_boundary =
                    l_program.iv_config.getBit<TT::MCBIST_CFG_FORCE_PAUSE_AFTER_SUBTEST>() ||
                    l_error_mode == stop_conditions::STOP_AFTER_SUBTEST;
                break;

            // By default we're not stopped at a boundary we're going to continue from
            default:
                break;
        };

        FAPI_ASSERT( l_stopped_at_boundary == false,
                     fapi2::MSS_MEMDIAGS_ALREADY_AT_BOUNDARY().set_TARGET(i_target).set_BOUNDARY(i_stop),
                     "Asked to stop at a boundary, but we're already there" );

        // Ok, if we're here either we need to change the stop and boundary conditions.
        // Read-modify-write the fields in the program.
        FAPI_TRY( mss::getScom(i_target, TT::MCBAGRAQ_REG, l_program.iv_addr_gen) );

        l_program.change_stops(i_stop);

        l_program.change_end_boundary(i_end);

        FAPI_TRY( mss::mcbist::load_addr_gen(i_target, l_program) );

        FAPI_TRY( mss::mcbist::load_config(i_target, l_program) );
    }

    // Thresholds
    FAPI_TRY( mss::mcbist::load_thresholds(i_target, i_thresholds) );

    // Setup speed
    FAPI_TRY( l_program.change_speed(i_target, i_speed) );

    // Clear the program complete FIR
    FAPI_TRY( mss::putScom(i_target, MCBIST_MCBISTFIRQ_AND,
                           fapi2::buffer<uint64_t>().setBit<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>().invert()) );

    // Tickle the resume from pause
    FAPI_TRY( mss::mcbist::resume(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Continue current command on next address
/// The current commaand has paused on an error, so we can record the address of the error
/// and finish the current master or slave rank.
/// @param[in] i_target the target
/// @param[in] i_end where to end, if stop conditions change (defaults to Master Rank)
/// @param[in] i_stop stop conditions (default - DONT_CHANGE meaning 'don't change conditions')
/// @param[in] i_speed the speed to scrub (default - SAM_SPEED meaning leave speed untouched)
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode continue_cmd( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                                const end_boundary i_end,
                                const stop_conditions i_stop,
                                const speed i_speed )
{
    FAPI_INF("continue_cmd - no change thresholds");

    // Read current thresholds and pass them as if they're changed.
    fapi2::buffer<uint64_t> i_thresholds;
    FAPI_TRY( mss::getScom(i_target, mss::mcbist::mcbistTraits<TARGET_TYPE_MCBIST>::THRESHOLD_REG, i_thresholds) );

    return continue_cmd( i_target, thresholds(i_thresholds), i_end, i_stop, i_speed );

fapi_try_exit:
    return fapi2::current_err;
}



}
