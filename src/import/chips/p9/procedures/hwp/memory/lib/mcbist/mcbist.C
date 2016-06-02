/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mcbist/mcbist.C $          */
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
/// @file mcbist.C
/// @brief Run and manage the MCBIST engine
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/mcbist/mcbist.H>
#include <lib/utils/dump_regs.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;

namespace mss
{
namespace mcbist
{

const std::pair<uint64_t, uint64_t> mcbistTraits<fapi2::TARGET_TYPE_MCBIST>::address_pairs[] =
{
    { START_ADDRESS_0, END_ADDRESS_0 },
    { START_ADDRESS_1, END_ADDRESS_1 },
    { START_ADDRESS_2, END_ADDRESS_2 },
    { START_ADDRESS_3, END_ADDRESS_3 },
};


///
/// @brief Load a set of MCBIST subtests in to the MCBIST registers
/// @tparam T, the fapi2::TargetType - derived
/// @tparam TT, the mcbistTraits associated with T - derived
/// @param[in] the target to effect
/// @param[in] the mcbist::program
/// @return FAPI2_RC_SUCCSS iff ok
/// @note assumes the MCBIST engine has been configured.
///
template<>
fapi2::ReturnCode load_mcbmr( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                              const mcbist::program<TARGET_TYPE_MCBIST>& i_program )
{

    // Leave if there are no subtests.
    if (0 == i_program.iv_subtests.size())
    {
        FAPI_INF("no subtests, nothing to do");
        return fapi2::current_err;
    }

    // List of the 8 MCBIST registers - each holds 4 subtests.
    static const std::vector< uint64_t > l_memory_registers =
    {
        MCBIST_MCBMR0Q, MCBIST_MCBMR1Q, MCBIST_MCBMR2Q, MCBIST_MCBMR3Q,
        MCBIST_MCBMR4Q, MCBIST_MCBMR5Q, MCBIST_MCBMR6Q, MCBIST_MCBMR7Q,
    };

    std::vector< uint64_t > l_memory_register_buffers =
    {
        0, 0, 0, 0, 0, 0, 0, 0,
    };

    static const size_t SUBTEST_PER_REG = 4;
    static const size_t SUBTEST_PER_PROGRAM = 32;

    static const auto BITS_IN_SUBTEST = sizeof(mcbist::subtest_t<TARGET_TYPE_MCBIST>().iv_mcbmr) * 8;
    static const auto LEFT_SHIFT = (sizeof(uint64_t) * 8) - BITS_IN_SUBTEST;

    ssize_t l_bin = -1;
    size_t l_register_shift = 0;

    // We'll shift this in to position to indicate which subtest is the last
    static const uint64_t l_done_bit( 0x8000000000000000 >> MCBIST_MCBMR0Q_MCBIST_CFG_TEST00_DONE );

    // TK: For now limit MCBIST programs to 32 subtests.
    const auto l_program_size = i_program.iv_subtests.size();
    FAPI_ASSERT( l_program_size <= SUBTEST_PER_PROGRAM,
                 fapi2::MSS_MCBIST_PROGRAM_TOO_BIG().set_PROGRAM_LENGTH(l_program_size),
                 "mcbist program of length %d exceeds arbitrary maximum of %d", l_program_size, SUBTEST_PER_PROGRAM );

    // Distribute the program over the 8 MCBIST subtest registers
    // We need the index, so increment thru i_program.iv_subtests.size()
    for (size_t l_index = 0; l_index < l_program_size; ++l_index)
    {
        l_bin = (l_index % SUBTEST_PER_REG) == 0 ? l_bin + 1 : l_bin;
        l_register_shift = (l_index % SUBTEST_PER_REG) * BITS_IN_SUBTEST;

        l_memory_register_buffers[l_bin] |=
            (uint64_t(i_program.iv_subtests[l_index].iv_mcbmr) << LEFT_SHIFT) >> l_register_shift;

        FAPI_DBG("putting subtest %d (0x%x) in MCBMR%dQ shifted %d 0x%016llx",
                 l_index, i_program.iv_subtests[l_index].iv_mcbmr, l_bin,
                 l_register_shift, l_memory_register_buffers[l_bin]);
    }

    // l_bin and l_register_shift are the values for the last subtest we'll tell the MCBIST about.
    // We need to set that subtest's done-bit so the MCBIST knows it's the end of the line
    l_memory_register_buffers[l_bin] |= l_done_bit >> l_register_shift;
    FAPI_DBG("setting MCBMR%dQ subtest %llu as the last subtest 0x%016llx",
             l_bin, l_register_shift, l_memory_register_buffers[l_bin]);

    // ... and slam the values in to the registers.
    // Could just decrement l_bin, but that scoms the subtests in backwards and is confusing
    for (auto l_index = 0; l_index <= l_bin; ++l_index)
    {
        FAPI_TRY( mss::putScom(i_target, l_memory_registers[l_index], l_memory_register_buffers[l_index]) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Poll the mcbist engine and check for errors
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] i_target the target to effect
/// @param[in] i_program, the mcbist program which is executing
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff OK
///
template< fapi2::TargetType T, typename TT = mcbistTraits<T> >
fapi2::ReturnCode poll( const fapi2::Target<T>& i_target, const program<T>& i_program )
{
    fapi2::buffer<uint64_t> l_status;

    static const uint64_t l_done = fapi2::buffer<uint64_t>().setBit<TT::MCBIST_DONE>();
    static const uint64_t l_fail = fapi2::buffer<uint64_t>().setBit<TT::MCBIST_FAIL>();
    static const uint64_t l_in_progress = fapi2::buffer<uint64_t>().setBit<TT::MCBIST_IN_PROGRESS>();

    // A small vector of addresses to poll during the polling loop
    static const std::vector<mss::poll_probe<fapi2::TARGET_TYPE_MCBIST>> l_probes =
    {
        {i_target, "mcbist current address", MCBIST_MCBMCATQ},
    };

    mss::poll(i_target, TT::STATQ_REG, i_program.iv_poll,
              [&l_status](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_DBG("mcbist statq 0x%llx, remaining: %d", stat_reg, poll_remaining);
        l_status = stat_reg;
        return l_status.getBit<TT::MCBIST_IN_PROGRESS>() != 1;
    },
    l_probes);

    // Check to see if we're still in progress - meaning we timed out.
    FAPI_ASSERT((l_status & l_in_progress) != l_in_progress,
                fapi2::MSS_MCBIST_TIMEOUT().set_TARGET_IN_ERROR(i_target),
                "MCBIST timed out %s", mss::c_str(i_target));

    // The control register has a bit for done-and-happy and a bit for done-and-unhappy
    if ( ((l_status & l_done) == l_done) || ((l_status & l_fail) == l_fail) )
    {
        FAPI_INF("MCBIST completed, processing errors");

        // We're done. It doesn't mean that there were no errors.
        FAPI_TRY( i_program.process_errors(i_target) );

        // If we're here there were no errors, but lets report if the fail bit was set anyway.
        FAPI_ASSERT( (l_status & l_fail) != l_fail,
                     fapi2::MSS_MCBIST_UNKNOWN_FAILURE()
                     .set_TARGET_IN_ERROR(i_target)
                     .set_STATUS_REGISTER(l_status),
                     "MCBIST reported a fail, but process_errors didn't find it 0x%016llx", l_status );

        // And if we're here all is good with the world.
        return fapi2::current_err;
    }

    FAPI_ASSERT(false,
                fapi2::MSS_MCBIST_MULTIPLE_FAIL_BITS()
                .set_TARGET_IN_ERROR(i_target)
                .set_STATUS_REGISTER(l_status),
                "MCBIST executed <shrug>. Something's not good 0x%016llx", l_status );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Execute the mcbist program
/// @param[in] i_target the target to effect
/// @param[in] i_program, the mcbist program to execute
/// @return fapi2::ReturnCode, FAPI2_RC_SUCCESS iff OK
///
template<>
fapi2::ReturnCode execute( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                           const program<TARGET_TYPE_MCBIST>& i_program )
{
    typedef mcbistTraits<TARGET_TYPE_MCBIST> TT;

    fapi2::buffer<uint64_t> l_status;
    bool l_poll_result = false;
    poll_parameters l_poll_parameters;

    FAPI_TRY( clear_errors(i_target) );

    // Slam the address generator config
    FAPI_TRY( load_addr_gen(i_target, i_program) );

    // Slam the parameters in to the mcbist parameter register
    FAPI_TRY( load_mcbparm(i_target, i_program) );

    // Slam the configured address maps down
    FAPI_TRY( load_mcbamr( i_target, i_program) );

    // Slam the config register down
    FAPI_TRY( load_config( i_target, i_program) );

    // Slam the control register down
    FAPI_TRY( load_control( i_target, i_program) );

    // Load the patterns and any associated bits for random, etc
    FAPI_TRY( load_pattern( i_target, i_program) );

    // Load the thresholds
    FAPI_TRY( load_thresholds( i_target, i_program) );

    // Slam the subtests in to the mcbist registers
    // Always do this last so the action file triggers see the other bits set
    FAPI_TRY( load_mcbmr(i_target, i_program) );

    // Start the engine, and then poll for completion
    FAPI_TRY(start_stop(i_target, mss::START));

    // Verify that the in-progress bit has been set, so we know we started
    // Don't use the program's poll as it could be a very long time. Use the default poll.
    l_poll_result = mss::poll(i_target, TT::STATQ_REG, l_poll_parameters,
                              [&l_status](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_DBG("looking for mcbist start, mcbist statq 0x%llx, remaining: %d", stat_reg, poll_remaining);
        l_status = stat_reg;
        // We're done polling when either we see we're in progress or we see we're done.
        return (l_status.getBit<TT::MCBIST_IN_PROGRESS>() == true) || (l_status.getBit<TT::MCBIST_DONE>() == true);
    });

    // So we've either run/are running or we timed out waiting for the start.
    FAPI_ASSERT( l_poll_result == true,
                 fapi2::MSS_MEMDIAGS_MCBIST_FAILED_TO_START().set_TARGET(i_target),
                 "The MCBIST engine failed to start its program" );

    // If the user asked for async mode, we can leave. Otherwise, poll and check for errors
    if (!i_program.iv_async)
    {
        return mcbist::poll(i_target, i_program);
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace

// Note: outside of the mcbist namespace

///
/// @brief Dump the registers of an mcbist
/// @param[in] i_target, the mcbist in question
/// @return fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode dump_regs( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    return fapi2::current_err;
}


} // namespace
