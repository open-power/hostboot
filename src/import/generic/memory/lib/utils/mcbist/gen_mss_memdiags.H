/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mcbist/gen_mss_memdiags.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file gen_mss_memdiags.H
/// @brief API for memory diagnostics
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
//

#ifndef _GEN_MSS_MEMDIAGS_H_
#define _GEN_MSS_MEMDIAGS_H_

#include <fapi2.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_address.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_patterns.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_settings.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/conversions.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/poll.H>


namespace mss
{

///
/// @brief Determine if a thing is functional
/// @tparam I, the type of the item we want to check for
/// @tparam P, the type of the parent which holds the things of interest
/// @param[in] i_target the parent containing the thing we're looking for
/// @param[in] i_rel_pos the relative position of the item of interest.
/// @return bool true iff the thing at i_rel_pos is noted as functional
///
template< fapi2::TargetType I, fapi2::TargetType P >
inline bool is_functional( const fapi2::Target<P>& i_target, const uint64_t i_rel_pos )
{
    // Not sure of a good way to do this ... we get all the functional
    // children of the parent and look for our relative position ...
    for (const auto& i : i_target.template getChildren<I>(fapi2::TARGET_STATE_FUNCTIONAL))
    {
        if (mss::template relative_pos<P>(i) == i_rel_pos)
        {
            return true;
        }
    }

    return false;
}

namespace mcbist
{
namespace sim
{

/// @brief Perform a sim version of initializing memory
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T
/// @param T a fapi2::TargetType
/// @param[in] i_target
/// @param[in] i_pattern an index representing a pattern to use to initialize memory (defaults to 0)
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = mcbistTraits<MC, T> >
fapi2::ReturnCode sf_init( const fapi2::Target<T>& i_target, const uint64_t i_pattern )
{
    FAPI_INF("Start sim init for %s", mss::c_str(i_target));

    // If we're running in the simulator, we want to only touch the addresses which training touched

    for (const auto& p : i_target.template getChildren<TT::PORT_TYPE>())
    {
        std::vector<uint64_t> l_pr;
        mss::mcbist::program<MC> l_program;

        mss::mcbist::address l_start;
        mss::mcbist::address l_end;

        size_t l_rank_address_pair = 0;

        // No point in bothering if we don't have any DIMM
        if (mss::count_dimm(p) == 0)
        {
            FAPI_INF("No DIMM on %s, not running sf_init", mss::c_str(p));
            continue;
        }

        // In sim we know a few things ...
        // Get the primary ranks for this port. We know there can only be 4, and we know we only trained the primary
        // ranks. Therefore, we only need to clean up the primary ranks. And because there's 4 max, we can do it
        // all using the 4 address range registers of tne MCBIST (broadcast currently not considered.)
        // So we can write 0's to those to get their ECC fixed up.
        FAPI_TRY( mss::rank::primary_ranks(p, l_pr) );

        FAPI_ASSERT(l_pr.size() <= mss::MAX_RANK_PER_DIMM,
                    fapi2::MSS_INVALID_PRIMARY_RANK_COUNT()
                    .set_PORT_TARGET(p)
                    .set_RANK_COUNT(l_pr),
                    "Failed to get a valid number of primary ranks on %s, Max number of ranks: %d, Current rank count: %d",
                    mss::c_str(p), mss::MAX_RANK_PER_DIMM, l_pr.size());

        for (auto r = l_pr.begin(); r != l_pr.end(); ++l_rank_address_pair, ++r)
        {
            FAPI_INF("sim init %s, rank %d", mss::c_str(p), *r);

            // Setup l_start to represent this rank, and then make the end address from that.
            l_start.set_master_rank(*r);

            // Set C3 bit to get an entire cache line
            l_start.get_sim_end_address(l_end);

            // By default we're in maint address mode, not address counting mode. So we give it a start and end, and ignore
            // anything invalid - that's what maint address mode is all about
            mss::mcbist::config_address_range<MC>(i_target, l_start, l_end, l_rank_address_pair);

            // Write
            {
                // Run in ECC mode, 64B writes (superfast mode)

                mss::mcbist::subtest_t<MC> l_fw_subtest =
                    mss::mcbist::write_subtest<MC>();

                l_fw_subtest.enable_port(mss::relative_pos<T>(p));
                l_fw_subtest.change_addr_sel(l_rank_address_pair);
                l_fw_subtest.enable_dimm(mss::rank::get_dimm_from_rank(*r));
                l_program.iv_subtests.push_back(l_fw_subtest);
                FAPI_DBG("adding superfast write for %s rank %d (dimm %d)", mss::c_str(p), *r, mss::rank::get_dimm_from_rank(*r));
            }

            // Read - we do a read here as verification can use this as a tool as we do the write and then the read.
            // If we failed to write properly the read would thow ECC errors. Just a write (which the real hardware would
            // do) doesn't catch that. This takes longer, but it's not terribly long in any event.
            {
                // Run in ECC mode, 64B writes (superfast mode)
                mss::mcbist::subtest_t<MC> l_fr_subtest =
                    mss::mcbist::read_subtest<MC>();

                l_fr_subtest.enable_port(mss::relative_pos<T>(p));
                l_fr_subtest.change_addr_sel(l_rank_address_pair);
                l_fr_subtest.enable_dimm(mss::rank::get_dimm_from_rank(*r));
                l_program.iv_subtests.push_back(l_fr_subtest);
                FAPI_DBG("adding superfast read for %s rank %d (dimm %d)", mss::c_str(p), *r, mss::rank::get_dimm_from_rank(*r));
            }
        }

        // Write pattern
        FAPI_TRY( mss::mcbist::load_pattern<MC>(i_target, i_pattern) );

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
        l_port.setBit(mss::relative_pos<T>(p));
        l_program.select_ports(l_port >> 4);

        // Kick it off, wait for a result
        FAPI_TRY( mss::mcbist::execute(i_target, l_program) );
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_INF("End sim init for %s", mss::c_str(i_target));
    return fapi2::current_err;
}

} // namespace sim
} // namespace mcbist


namespace memdiags
{

// Map some of the mcbist namespace here to make it easier for users of memdiags
// This is an intentional using statement in a header which is typically
// disallowed - I am intentionally pulling these into this namespace for all callers.
using mss::mcbist::constraints;
using mss::mcbist::speed;
using mss::mcbist::end_boundary;
using mss::mcbist::stop_conditions;
using mss::mcbist::cache_line;
using mss::mcbist::pattern;
using mss::mcbist::patterns;

// Why not mss::mcbist::address? Because the fields can't be pulled in via using,
// and it seems even more confusing to have a memdiags address but have to use
// mcbist fields. So, we all use mcbist address until such time that its promoted
// to some other general namespace.

using mss::mcbist::PATTERN_ZEROS;
using mss::mcbist::PATTERN_0;
using mss::mcbist::PATTERN_ONES;
using mss::mcbist::PATTERN_1;
using mss::mcbist::PATTERN_2;
using mss::mcbist::PATTERN_3;
using mss::mcbist::PATTERN_4;
using mss::mcbist::PATTERN_5;
using mss::mcbist::PATTERN_6;
using mss::mcbist::PATTERN_7;
using mss::mcbist::PATTERN_8;
using mss::mcbist::PATTERN_RANDOM;
using mss::mcbist::LAST_PATTERN;
using mss::mcbist::NO_PATTERN;

///
/// @brief Set up memory controller specific settings for pre-maint mode read
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the portTraits associated with the port
/// @param[in] i_target the memory controller target
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode pre_maint_read_settings( const fapi2::Target<T>& i_target );

///
/// @brief Set up memory controller specific settings for pre-scrub
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the portTraits associated with the port
/// @param[in] i_target the memory controller target
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = portTraits<MC> >
fapi2::ReturnCode pre_scrub_settings( const fapi2::Target<T>& i_target );

///
/// @brief Stop the current command
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType of the target
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T>
fapi2::ReturnCode stop( const fapi2::Target<T>& i_target )
{
    // Too long, make shorter
    using TT = mss::mcbistTraits<MC, T>;
    using ET = mss::mcbistMCTraits<MC>;

    // Poll parameters are defined as TK so that we wait a nice time for operations
    // For now use the defaults
    mss::poll_parameters l_poll_parameters;
    fapi2::buffer<uint64_t> l_status;
    fapi2::buffer<uint64_t> l_last_address;
    bool l_poll_result = false;

    FAPI_INF("Stopping any mcbist operations which are in progress for %s", mss::c_str(i_target));

    // TODO RTC:153951 Add masking of FIR when stopping
    FAPI_TRY( mss::mcbist::start_stop<MC>(i_target, mss::STOP) );

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
    FAPI_INF("MCBIST last address (during stop): 0x%016lx for %s",
             l_last_address, mss::c_str(i_target));

    // So we've either stopped or we timed out
    FAPI_ASSERT( l_poll_result == true,
                 ET::memdiags_failed_to_stop()
                 .set_MC_TARGET(i_target)
                 .set_POLL_COUNT(l_poll_parameters.iv_poll_count),
                 "%s The MCBIST engine failed to stop its program",
                 mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;

}


///
/// @class Base class for memdiags operations
/// @tparam MC the mc type of the T
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mcbistTraits associated with T
///
template< mss::mc_type MC, fapi2::TargetType T = mss::mcbistMCTraits<MC>::MC_TARGET_TYPE , typename TT = mcbistTraits<MC, T> >
class operation
{
    public:
        ///
        /// @brief memdiags::operation constructor
        /// @param[in] i_target the target of the mcbist engine
        /// @param[in] i_subtest the proper subtest for this operation
        /// @param[in] i_const mss::constraint structure
        ///
        operation( const fapi2::Target<T>& i_target,
                   const mss::mcbist::subtest_t<MC> i_subtest,
                   const constraints<MC> i_const ):
            iv_target(i_target),
            iv_subtest(i_subtest),
            iv_const(i_const)
        {
            FAPI_TRY( mss::attr::get_is_simulation (iv_sim) );
            return;

        fapi_try_exit:
            // Seems like a safe risk to take ...
            FAPI_ERR("Unable to get the attribute ATTR_IS_SIMULATION");
            return;
        }

        operation() = delete;

        ///
        /// @brief Execute the memdiags operation
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        inline fapi2::ReturnCode execute()
        {
            return mss::mcbist::execute(iv_target, iv_program);
        }

        ///
        /// @brief memdiags::operation destructor
        ///
        virtual ~operation() = default;

        ///
        /// @brief memdiags init helper
        /// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
        /// in subclassed constructores more easily.
        /// @return FAPI2_RC_SUCCESS iff everything ok
        ///
        fapi2::ReturnCode base_init();

        ///
        /// @brief Configures all subtests for a multiport init
        /// @param[in] i_dimms a vector of DIMM targets
        ///
        void configure_multiport_subtests(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>>& i_dimms);

        ///
        /// @brief memdiags multi-port init helper
        /// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
        /// in subclassed constructores more easily.
        /// @return FAPI2_RC_SUCCESS iff everything ok
        ///
        fapi2::ReturnCode multi_port_init();

        ///
        /// @brief memdiags multi-port init for specific chip
        /// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
        /// in subclassed constructores more easily.
        /// @return FAPI2_RC_SUCCESS iff everything ok
        ///
        fapi2::ReturnCode multi_port_init_internal();


        ///
        /// @brief memdiags multi-port address config helper
        /// Initializes the address configs needed for a multi port operation
        /// @return FAPI2_RC_SUCCESS iff everything ok
        ///
        fapi2::ReturnCode multi_port_addr();

        ///
        /// @brief Single port initializer
        /// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
        /// in subclassed constructores more easily.
        /// @return FAPI2_RC_SUCCESS iff everything ok
        ///
        fapi2::ReturnCode single_port_init();

        ///
        /// @brief get the protected mcbist program - useful for testing
        /// @return a reference to the iv_program member
        /// @note Intentionally not const ref; allows getter to set.
        ///
        mss::mcbist::program<MC>& get_program()
        {
            return iv_program;
        }

        ///
        /// @brief get the protected mcbist subtest_t - useful for testing
        /// @return a reference to the iv_subtest member
        ///
        const mss::mcbist::subtest_t<MC>& get_subtest() const
        {
            return iv_subtest;
        }

    protected:
        fapi2::Target<T>          iv_target;
        mss::mcbist::subtest_t<MC> iv_subtest;
        constraints<MC>            iv_const;
        mss::mcbist::program<MC>   iv_program;
        uint8_t                   iv_sim;
};



///
/// @brief memdiags init helper
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T
/// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
/// in subclassed constructors more easily.
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT >
inline fapi2::ReturnCode operation<MC, T, TT>::base_init()
{
    FAPI_INF("memdiags base init for %s", mss::c_str(iv_target));

    // Check the state of the MCBIST engine to make sure its OK that we proceed.
    // Force stop the engine (per spec, as opposed to waiting our turn)
    FAPI_TRY( memdiags::stop<MC>(iv_target) );

    // Zero out cmd timebase - mcbist::program constructor does that for us.
    // Load pattern
    FAPI_TRY( iv_program.change_pattern(iv_const.iv_pattern) );

    // Load end boundaries
    iv_program.change_end_boundary(iv_const.iv_end_boundary);

    // Load thresholds
    iv_program.change_thresholds(iv_const.iv_stop);

    // Setup the requested speed
    FAPI_TRY( iv_program.change_speed(iv_target, iv_const.iv_speed) );

    // Enable maint addressing mode - enabled by default in the mcbist::program ctor

    // Apparently the MCBIST engine needs the ports selected even though the ports are specified
    // in the subtest. We can just select them all, and it adjusts when it executes the subtest
    iv_program.select_ports(0b1111);

    // Kick it off, don't wait for a result
    iv_program.change_async(mss::ON);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Single port initializer
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T
/// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
/// in subclassed constructors more easily.
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT >
inline fapi2::ReturnCode operation<MC, T, TT>::single_port_init()
{
    using ET = mcbistMCTraits<MC>;
    FAPI_INF("single port init for %s", mss::c_str(iv_target));

    const uint64_t l_relative_port_number = iv_const.iv_start_address.get_port();
    const uint64_t l_dimm_number = iv_const.iv_start_address.get_dimm();

    // Make sure the specificed port is functional
    FAPI_ASSERT( mss::is_functional<TT::PORT_TYPE>(iv_target, l_relative_port_number),
                 ET::memdiags_port_not_functional()
                 .set_RELATIVE_PORT_POSITION(l_relative_port_number)
                 .set_ADDRESS( uint64_t(iv_const.iv_start_address) )
                 .set_MC_TARGET(iv_target),
                 "Port with relative postion %d is not functional for %s",
                 l_relative_port_number, mss::c_str(iv_target));

    // No broadcast mode for this one
    // Push on a read subtest
    {
        mss::mcbist::subtest_t<MC> l_subtest = iv_subtest;

        l_subtest.enable_port(l_relative_port_number);
        l_subtest.enable_dimm(l_dimm_number);
        iv_program.iv_subtests.push_back(l_subtest);
        FAPI_INF("%s adding subtest  0x%04x for port %d, DIMM %d",
                 mss::c_str(iv_target), l_subtest, l_relative_port_number, l_dimm_number);
    }

    // The address should have the port and DIMM noted in it. All we need to do is calculate the
    // remainder of the address
    if (iv_sim)
    {
        iv_const.iv_start_address.get_sim_end_address(iv_const.iv_end_address);
    }
    else if (iv_const.iv_end_address == TT::LARGEST_ADDRESS)
    {
        // Only the DIMM range as we don't want to cross ports.
        iv_const.iv_start_address.template get_range<mss::mcbist::address::DIMM>(iv_const.iv_end_address);
    }

    // Configure the address range
    FAPI_TRY( mss::mcbist::config_address_range0<MC>(iv_target, iv_const.iv_start_address, iv_const.iv_end_address) );

    // Initialize the common sections
    FAPI_TRY( base_init() );

fapi_try_exit:
    return fapi2::current_err;
}



///
/// @brief memdiags multi-port init helper
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT the mcbistTraits associated with T
/// Initializes common sections. Broken out rather than the base class ctor to enable checking return codes
/// in subclassed constructors more easily.
/// @return FAPI2_RC_SUCCESS iff everything ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT >
inline fapi2::ReturnCode operation<MC, T, TT>::multi_port_init()
{
    FAPI_INF("multi-port init for %s", mss::c_str(iv_target));

    const auto l_port = mss::find_targets<TT::PORT_TYPE>(iv_target);

    // Make sure we have ports, if we don't then exit out
    if(l_port.size() == 0)
    {
        // Cronus can have no ports under an MCBIST, FW deconfigures by association
        FAPI_INF("%s has no attached ports skipping setup", mss::c_str(iv_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Let's assume we are going to send out all subtest unless we are in broadcast mode,
    // where we only send up to 2 subtests under an port ( 1 for each DIMM) which is why no const
    auto l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target);

    if( l_dimms.size() == 0)
    {
        // Cronus can have no DIMMS under an MCBIST, FW deconfigures by association
        FAPI_INF("%s has no attached DIMMs skipping setup", mss::c_str(iv_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    return multi_port_init_internal();
}


///
/// @class Class for memdiags' super-fast init
/// @tparam MC the mc type of the T
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mcbistTraits associated with T
///
template< mss::mc_type MC, fapi2::TargetType T = mss::mcbistMCTraits<MC>::MC_TARGET_TYPE , typename TT = mcbistTraits<MC, T> >
struct sf_init_operation : public operation<MC>
{

    ///
    /// @brief memdiags::sf_init_operation constructor
    /// @param[in] i_target the target of the mcbist engine
    /// @param[in] i_const mss::constraint structure
    /// @param[out] o_rc the fapi2::ReturnCode of the intialization process
    ///
    sf_init_operation( const fapi2::Target<T>& i_target,
                       const constraints<MC> i_const,
                       fapi2::ReturnCode& o_rc):
        operation<MC>(i_target, mss::mcbist::init_subtest<MC>(), i_const)
    {
        // If sf_init was passed the random data pattern, then modify the subtest to use the true random data
        if(i_const.iv_pattern == PATTERN_RANDOM)
        {
            this->iv_subtest.change_data_mode(mss::mcbist::data_mode::RAND_FWD_MAINT);
        }

        // We're a multi-port operation
        o_rc = this->multi_port_init();
    }

    sf_init_operation() = delete;
};



///
/// @class Class for memdiags' super-fast read
/// @tparam MC the mc type of the T
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mcbistTraits associated with T
///
template< mss::mc_type MC, fapi2::TargetType T = mss::mcbistMCTraits<MC>::MC_TARGET_TYPE , typename TT = mcbistTraits<MC, T> >
struct sf_read_operation : public operation<MC>
{

    ///
    /// @brief memdiags::sf_read_operation constructor
    /// @param[in] i_target the target of the mcbist engine
    /// @param[in] i_const mss::constraint structure
    /// @param[out] o_rc the fapi2::ReturnCode of the intialization process
    ///
    sf_read_operation( const fapi2::Target<T>& i_target,
                       const constraints<MC> i_const,
                       fapi2::ReturnCode& o_rc):
        operation<MC>(i_target, mss::mcbist::read_subtest<MC>(), i_const)
    {
        // We're a multi-port operation
        o_rc = this->multi_port_init();
    }

    sf_read_operation() = delete;
};


///
/// @class Class for memdiags' super-fast read to end of port
/// @tparam MC the mc type of the T
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mcbistTraits associated with T
///
template< mss::mc_type MC, fapi2::TargetType T = mss::mcbistMCTraits<MC>::MC_TARGET_TYPE , typename TT = mcbistTraits<MC, T> >
struct sf_read_eop_operation : public operation<MC>
{
    ///
    /// @brief memdiags::sf_read_operation constructor
    /// @param[in] i_target the target of the mcbist engine
    /// @param[in] i_const mss::constraint structure
    /// @param[out] o_rc the fapi2::ReturnCode of the intialization process
    ///
    sf_read_eop_operation( const fapi2::Target<T>& i_target,
                           const constraints<MC> i_const,
                           fapi2::ReturnCode& o_rc ):
        operation<MC>(i_target, mss::mcbist::read_subtest<MC>(), i_const)
    {
        // We're a single-port operation
        o_rc = this->single_port_init();
    }

    sf_read_eop_operation() = delete;
};

///
/// @class Class for memdiags' continuous scrub
/// @tparam MC the mc type of the T
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mcbistTraits associated with T
///
template< mss::mc_type MC, fapi2::TargetType T = mss::mcbistMCTraits<MC>::MC_TARGET_TYPE , typename TT = mcbistTraits<MC, T> >
struct continuous_scrub_operation : public operation<MC>
{

    ///
    /// @brief memdiags::continuous_scrub_operation constructor
    /// @param[in] i_target the target of the mcbist engine
    /// @param[in] i_const the contraints of the operation
    /// @param[out] o_rc the fapi2::ReturnCode of the intialization process
    ///
    continuous_scrub_operation( const fapi2::Target<T>& i_target,
                                const constraints<MC> i_const,
                                fapi2::ReturnCode& o_rc );

    continuous_scrub_operation() = delete;
};

///
/// @brief memdiags::continuous_scrub_operation constructor
/// @tparam MC the mc type of the T
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mcbistTraits associated with T
/// @param[in] i_target the target of the mcbist engine
/// @param[in] i_const the contraints of the operation
/// @param[out] o_rc the fapi2::ReturnCode of the intialization process
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT>
continuous_scrub_operation<MC, T, TT>::continuous_scrub_operation(
    const fapi2::Target<T>& i_target,
    const constraints<MC> i_const,
    fapi2::ReturnCode& o_rc ):
    operation<MC>(i_target, mss::mcbist::scrub_subtest<MC>(), i_const)
{
    mss::mcbist::address l_generic_start_address;
    mss::mcbist::address l_generic_end_address;

    FAPI_INF("setting up for continuous scrub for %s", mss::c_str(i_target));

    // Scrub operations run 128B
    operation<MC>::iv_program.change_len64(mss::OFF);

    // We build a little program here which allows us to restart the loop in the event of a pause.
    // So we need to craft some of the address ranges and some of the subtests by hand.

    // Setup address config 0 to cover all the addresses for a port/dimm.
    // We leverage the MCBIST's ability to skip invalid addresses, and just setup
    // If we're running in the simulator, we want to only touch the addresses which training touched
    // *INDENT-OFF*
    operation<MC>::iv_sim ?
        l_generic_start_address.get_sim_end_address(l_generic_end_address) :
        l_generic_start_address.get_range<mss::mcbist::address::DIMM>(l_generic_end_address);
    // *INDENT-ON*

    FAPI_TRY( mss::mcbist::config_address_range0<MC>(i_target, l_generic_start_address, l_generic_end_address) );

    // We push on a fake subtest 0 and subtest 1. We fix them up after we fill in the
    // rest of the subtests.
    operation<MC>::iv_program.iv_subtests.push_back(operation<MC>::iv_subtest);
    operation<MC>::iv_program.iv_subtests.push_back(operation<MC>::iv_subtest);

    // a generic 0 - DIMM address range.
    //
    // Subtests 2-9: One subtest per port/dimm each covering the whole range of that
    // port/dimm. scrub_subtests by default are using address config 0, so each of
    // these get their full address complement.
    for (const auto& p : operation<MC>::iv_target.template getChildren<TT::PORT_TYPE>())
    {
        for (const auto& d : p.template getChildren<fapi2::TARGET_TYPE_DIMM>())
        {
            // Don't destroy the subtest passed in, copy it
            auto l_subtest = operation<MC>::iv_subtest;

            l_subtest.enable_port(mss::relative_pos<T>(p));
            l_subtest.enable_dimm(mss::index(d));
            operation<MC>::iv_program.iv_subtests.push_back(l_subtest);
            FAPI_INF("adding scrub subtest for %s (dimm %d) ( 0x%04x)", mss::c_str(d), mss::index(d), l_subtest);
        }
    }

    //
    // Subtest 10: goto subtest 2. This causes us to loop back to the first port/dimm and go thru them all
    // This subtest will be marked the last when the MCBMR registers are filled in.
    //
    operation<MC>::iv_program.iv_subtests.push_back(mss::mcbist::goto_subtest<MC>(2));
    FAPI_INF("last goto subtest (10) is going to subtest 2 ( 0x%04x) for %s", operation<MC>::iv_program.iv_subtests[2],
             mss::c_str(operation<MC>::iv_target));

    // Ok, now we can go back in to fill in the first two subtests.

    {
        auto l_subtest = operation<MC>::iv_subtest;
        auto l_port = operation<MC>::iv_const.iv_start_address.get_port();
        auto l_dimm = operation<MC>::iv_const.iv_start_address.get_dimm();
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
        operation<MC>::iv_sim ?
            operation<MC>::iv_const.iv_start_address.get_sim_end_address(operation<MC>::iv_const.iv_end_address) :
            operation<MC>::iv_const.iv_start_address.template get_range<mss::mcbist::address::DIMM>(operation<MC>::iv_const.iv_end_address);
        // *INDENT-ON*

        FAPI_TRY( mss::mcbist::config_address_range1<MC>(i_target, operation<MC>::iv_const.iv_start_address,
                  operation<MC>::iv_const.iv_end_address) );

        // We need to use this address range. We know it's ok to write to element 0 as we pushed it on above
        l_subtest.change_addr_sel(1);
        l_subtest.enable_port(l_port);
        l_subtest.enable_dimm(l_dimm);

        operation<MC>::iv_program.iv_subtests[0] = l_subtest;
        FAPI_INF("adding scrub subtest 0 for port %d dimm %d (0x%04x) for %s", l_port, l_dimm, l_subtest, mss::c_str(i_target));

        //
        // subtest 1
        //

        // From the port/dimm specified in the start address, we know what subtest should execute next. The idea
        // being that this 0'th subtest is a mechanism to allow the caller to start a scrub 'in the middle' and
        // jump to the next port/dimm which would have been scrubbed. The hard part is that we don't know where
        // in the subtest vector the 'next' port/dimm are placed. So we look for our port/dimm (skipping subtest 0
        // since we know that's us and skipping subtest 1 since it isn't there yet.)
        for (; l_index < operation<MC>::iv_program.iv_subtests.size(); ++l_index)
        {
            auto l_my_dimm = operation<MC>::iv_program.iv_subtests[l_index].get_dimm();
            auto l_my_port = operation<MC>::iv_program.iv_subtests[l_index].get_port();

            if ((l_dimm == l_my_dimm) && (l_port == l_my_port))
            {
                l_goto_subtest = l_index + 1;
                break;
            }
        }

        // Since we set l_goto_subtest up with a meaningful default, we can just make a subtest with the
        // l_goto_subtest subtest specified and pop that in to index 1.
        FAPI_INF("adding scrub subtest 1 to goto subtest %d (port %d, dimm %d, test 0x%04x) for %s", l_goto_subtest,
                 operation<MC>::iv_program.iv_subtests[l_goto_subtest].get_port(),
                 operation<MC>::iv_program.iv_subtests[l_goto_subtest].get_dimm(),
                 operation<MC>::iv_program.iv_subtests[l_goto_subtest], mss::c_str(i_target) );

        operation<MC>::iv_program.iv_subtests[1] = mss::mcbist::goto_subtest<MC>(l_goto_subtest);
    }

    // Initialize the common sections
    FAPI_TRY( operation<MC>::base_init() );

fapi_try_exit:
    o_rc = fapi2::current_err;
    return;
}



///
/// @class Class for memdiags' targeted scrub
/// @tparam MC the mc type of the T
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mcbistTraits associated with T
///
template< mss::mc_type MC, fapi2::TargetType T = mss::mcbistMCTraits<MC>::MC_TARGET_TYPE , typename TT = mcbistTraits<MC, T> >
struct targeted_scrub_operation : public operation<MC>
{

    ///
    /// @brief memdiags::targeted_scrub_operation constructor
    /// @param[in] i_target the target of the mcbist engine
    /// @param[in] i_const the contraints of the operation
    /// @param[out] o_rc the fapi2::ReturnCode of the intialization process
    ///
    targeted_scrub_operation( const fapi2::Target<T>& i_target,
                              const constraints<MC> i_const,
                              fapi2::ReturnCode& o_rc ):
        operation<MC>(i_target, mss::mcbist::scrub_subtest<MC>(), i_const)
    {
        // Scrub operations run 128B
        this->iv_program.change_len64(mss::OFF);

        // We're a single-port operation
        o_rc = this->single_port_init();

        // Targeted scrub needs to force a pause and the end boundary. So we make sure that happens here.
        // Note: the PAUSE_ON_ERROR_MODE setting should pause the test on errors, or at the end so we
        // shouldn't need a forced pause
        this->iv_program.change_forced_pause( end_boundary::NONE );
    }

    targeted_scrub_operation() = delete;
};

///
/// @brief Super Fast Init - used to init all memory behind a target with a given pattern
/// @note Uses broadcast mode if possible
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType of the target
/// @param[in] i_target the target behind which all memory should be initialized
/// @param[in] i_pattern an index representing a pattern to use to init memory (defaults to 0)
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
///
template<  mss::mc_type MC, fapi2::TargetType T >
fapi2::ReturnCode sf_init( const fapi2::Target<T>& i_target,
                           const uint64_t i_pattern = PATTERN_0 )
{
    using ET = mss::mcbistMCTraits<MC>;
    FAPI_INF("superfast init start for %s", mss::c_str(i_target));

    uint8_t l_sim = false;
    FAPI_TRY( mss::attr::get_is_simulation( l_sim) );

    if (l_sim)
    {
        // Use some sort of pattern in sim in case the verification folks need to look for something
        // TK. Need a verification pattern. This is a not-good pattern for verification ... We don't really
        // have a good pattern for verification defined.
        FAPI_INF("running mss sim init in place of sf_init for %s", mss::c_str(i_target));
        return mss::mcbist::sim::sf_init<MC>(i_target, i_pattern);
    }
    else
    {
        fapi2::ReturnCode l_rc;
        constraints<MC> l_const(i_pattern);
        sf_init_operation<MC> l_init_op(i_target, l_const, l_rc);

        FAPI_ASSERT( l_rc == fapi2::FAPI2_RC_SUCCESS,
                     ET::memdiags_sf_init_failed_init().set_MC_TARGET(i_target),
                     "Unable to initialize the MCBIST engine for a sf read %s", mss::c_str(i_target) );

        return l_init_op.execute();
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Super Fast Read - used to run superfast read on all memory behind the target
/// Determines ability to braodcast to all ports behind a target, does so if possible.
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType of the target
/// @tparam TT the mcbistTraits associated with T - derived
/// @param[in] i_target the target behind which all memory should be read
/// @param[in] i_stop stop conditions
/// @param[in] i_address mcbist::address representing the address from which to start.
//    Defaults to the first address behind the target
/// @param[in] i_end whether to end, and where
///   Defaults to stop after slave rank
/// @param[in] i_end_address mcbist::address representing the address to end.
//    Defaults to TT::LARGEST_ADDRESS
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
/// @note The address is often the port, dimm, rank but this is not enforced in the API.
///
template< mss::mc_type MC, fapi2::TargetType T = mss::mcbistMCTraits<MC>::MC_TARGET_TYPE , typename TT = mcbistTraits<MC, T> >
fapi2::ReturnCode sf_read( const fapi2::Target<T>& i_target,
                           const stop_conditions<MC>& i_stop,
                           const mss::mcbist::address& i_address = mss::mcbist::address(),
                           const end_boundary i_end = end_boundary::STOP_AFTER_SLAVE_RANK,
                           const mss::mcbist::address& i_end_address = mss::mcbist::address(TT::LARGEST_ADDRESS) )
{
    using ET = mss::mcbistMCTraits<MC>;
    FAPI_INF("superfast read - start for %s", mss::c_str(i_target));

    FAPI_TRY( pre_maint_read_settings<MC>(i_target) );

    {
        fapi2::ReturnCode l_rc;
        constraints<MC> l_const(i_stop, speed::LUDICROUS, i_end, i_address, i_end_address);
        sf_read_operation<MC> l_read_op(i_target, l_const, l_rc);

        FAPI_ASSERT( l_rc == fapi2::FAPI2_RC_SUCCESS,
                     ET::memdiags_sf_init_failed_init().set_MC_TARGET(i_target),
                     "Unable to initialize the MCBIST engine for a sf read %s", mss::c_str(i_target) );

        return l_read_op.execute();
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Scrub - continuous scrub all memory behind the target
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType of the target
/// @param[in] i_target the target behind which all memory should be scrubbed
/// @param[in] i_stop stop conditions
/// @param[in] i_speed the speed to scrub
/// @param[in] i_address mcbist::address representing the address from which to start.
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
/// @note The address is often the port, dimm, rank but this is not enforced in the API.
///
template< mss::mc_type MC, fapi2::TargetType T >
fapi2::ReturnCode background_scrub( const fapi2::Target<T>& i_target,
                                    const stop_conditions<MC>& i_stop,
                                    const speed i_speed,
                                    const mss::mcbist::address& i_address )
{
    using ET = mss::mcbistMCTraits<MC>;
    FAPI_INF("continuous (background) scrub for %s", mss::c_str(i_target));

    FAPI_TRY( pre_scrub_settings<MC>(i_target) );

    {
        fapi2::ReturnCode l_rc;
        constraints<MC> l_const(i_stop, i_speed, end_boundary::STOP_AFTER_ADDRESS, i_address);
        continuous_scrub_operation<MC> l_op(i_target, l_const, l_rc);

        FAPI_ASSERT( l_rc == fapi2::FAPI2_RC_SUCCESS,
                     ET::memdiags_continuous_scrub_failed_init().set_MC_TARGET(i_target),
                     "Unable to initialize the MCBIST engine for a continuous scrub %s", mss::c_str(i_target) );

        return l_op.execute();
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Scrub - targeted scrub all memory described by the input address (rank, slave, etc.)
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType of the target
/// @param[in] i_target the target behind which all memory should be scrubbed
/// @param[in] i_stop stop conditions
/// @param[in] i_speed the speed to scrub
/// @param[in] i_start_address mcbist::address representing the address from which to start.
/// @param[in] i_end_address mcbist::address representing the address at which to end.
/// @param[in] i_end whether to end, and where
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
/// @note The address is often the port, dimm, rank but this is not enforced in the API.
///
template< mss::mc_type MC, fapi2::TargetType T >
fapi2::ReturnCode targeted_scrub( const fapi2::Target<T>& i_target,
                                  const stop_conditions<MC>& i_stop,
                                  const mss::mcbist::address& i_start_address,
                                  const mss::mcbist::address& i_end_address,
                                  const end_boundary i_end )
{
    using ET = mss::mcbistMCTraits<MC>;
    FAPI_INF("targeted scrub for %s", mss::c_str(i_target));

    FAPI_TRY( pre_scrub_settings<MC>(i_target) );

    {
        fapi2::ReturnCode l_rc;
        constraints<MC> l_const(i_stop, speed::LUDICROUS, i_end, i_start_address, i_end_address);
        targeted_scrub_operation<MC> l_op(i_target, l_const, l_rc);

        FAPI_ASSERT( l_rc == fapi2::FAPI2_RC_SUCCESS,
                     ET::memdiags_targeted_scrub_failed_init().set_MC_TARGET(i_target),
                     "Unable to initialize the MCBIST engine for a targeted scrub %s", mss::c_str(i_target) );

        return l_op.execute();
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Continue current command on next address
/// The current commaand has paused on an error, so we can record the address of the error
/// and finish the current master or slave rank.
/// @tparam MC the mc type of the T
/// @tparam T the fapi2::TargetType of the target
/// @param[in] i_target the target
/// @param[in] i_end whether to end, and where (default - don't stop at end of rank)
/// @param[in] i_stop stop conditions (default - 0 meaning 'don't change conditions')
/// @param[in] i_speed the speed to scrub (default - SAME_SPEED meaning leave speed untouched)
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T >
fapi2::ReturnCode continue_cmd( const fapi2::Target<T>& i_target,
                                const end_boundary i_end = end_boundary::DONT_CHANGE,
                                const stop_conditions<MC>& i_stop = stop_conditions<MC>(stop_conditions<MC>::DONT_CHANGE),
                                const speed i_speed = speed::SAME_SPEED )
{
    // Too long, make shorter
    using TT = mss::mcbistTraits<MC, T>;
    using ET = mss::mcbistMCTraits<MC>;

    // We can use a local mcbist::program to help with the bit processing, and then write just the registers we touch.
    mss::mcbist::program<MC> l_program;
    fapi2::buffer<uint64_t> l_status;

    FAPI_INF("continue_cmd for %s", mss::c_str(i_target));

    // TODO RTC:155518 Check for stop or in progress before allowing continue. Not critical
    // as the caller should know and can check the in-progress bit in the event they don't

    if (i_end != end_boundary::DONT_CHANGE)
    {
        // Before we go too far, check to see if we're already stopped at the boundary we are asking to stop at
        bool l_stopped_at_boundary = false;
        uint64_t l_error_mode = 0;
        bool l_detect_slave = false;

        FAPI_TRY( mss::getScom(i_target, TT::CFGQ_REG, l_program.iv_config) );
        FAPI_TRY( mss::getScom(i_target, TT::MCBAGRAQ_REG, l_program.iv_addr_gen) );
        l_program.iv_config.template extractToRight<TT::CFG_PAUSE_ON_ERROR_MODE, TT::CFG_PAUSE_ON_ERROR_MODE_LEN>(l_error_mode);
        l_detect_slave = l_program.iv_addr_gen.template getBit<TT::MAINT_DETECT_SRANK_BOUNDARIES>();


        switch (i_end)
        {
            case end_boundary::STOP_AFTER_ADDRESS:
                l_stopped_at_boundary =
                    l_program.iv_config.template getBit< TT::MCBIST_CFG_FORCE_PAUSE_AFTER_ADDR>() ||
                    l_error_mode == end_boundary::STOP_AFTER_ADDRESS;
                break;

            case end_boundary::STOP_AFTER_SLAVE_RANK:
                // Note: we really want STOP_AFTER_MASTER_RANK here even though we're in the slave
                // case because MASTER_RANK has the a 0 so that l_error_mode will check correctly
                l_stopped_at_boundary =
                    l_program.iv_config.template getBit< TT::MCBIST_CFG_PAUSE_AFTER_RANK>() ||
                    ((l_error_mode == end_boundary::STOP_AFTER_MASTER_RANK) && (l_detect_slave == false));
                break;

            case end_boundary::STOP_AFTER_MASTER_RANK:
                l_stopped_at_boundary =
                    l_program.iv_config.template getBit< TT::MCBIST_CFG_PAUSE_AFTER_RANK>() ||
                    ((l_error_mode == end_boundary::STOP_AFTER_MASTER_RANK) && (l_detect_slave == true));
                break;

            case end_boundary::STOP_AFTER_SUBTEST:
                l_stopped_at_boundary =
                    l_program.iv_config.template getBit< TT::MCBIST_CFG_FORCE_PAUSE_AFTER_SUBTEST>() ||
                    l_error_mode == end_boundary::STOP_AFTER_SUBTEST;
                break;

            // By default we're not stopped at a boundary we're going to continue from
            default:
                break;
        };

        FAPI_ASSERT( l_stopped_at_boundary == false,
                     ET::memdiags_already_at_boundary().set_MC_TARGET(i_target).set_BOUNDARY(i_stop),
                     "Asked to stop at a boundary, but we're already there" );

        // Ok, if we're here either we need to change the stop and boundary conditions.
        // Read-modify-write the fields in the program.
        FAPI_TRY( mss::getScom(i_target, TT::MCBAGRAQ_REG, l_program.iv_addr_gen) );

        // Note: we are specifically not configuring broadcast mode here
        // The continue command is called by PRD exclusively at mainline
        // If we're at mainline, we can't run in broadcast mode
        // If we ever need to call continue elsewhere, we'll need to do the following
        // 1) add the function to configure broadcast mode
        // 2) add in a switch to disable broadcast mode if we're at runtime

        l_program.change_end_boundary(i_end);

        FAPI_TRY( mss::mcbist::load_addr_gen<MC>(i_target, l_program) );

        FAPI_TRY( mss::mcbist::load_config<MC>(i_target, l_program) );
    }

    // Thresholds
    // According to API definition, 0 means don't change conditions
    if( i_stop != stop_conditions<MC>::DONT_CHANGE)
    {
        FAPI_TRY( mss::mcbist::load_thresholds<MC>(i_target, i_stop) );
    }

    // Setup speed
    FAPI_TRY( l_program.change_speed(i_target, i_speed) );

    // Load new speed unless we aren't changing it
    if( i_speed != speed::SAME_SPEED )
    {
        FAPI_TRY( load_mcbparm(i_target, l_program) );
    }

    // Tickle the resume from pause
    FAPI_TRY( mss::mcbist::resume<MC>(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Polls MCBIST for completion after an async test
/// @tparam MC the mc type of the T
/// @tparam T fapi2::TargetType of the MC engine
/// @tparam TT the mcbistTraits associated with T
/// @param[in] i_target MC
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = mcbistTraits<MC, T> >
fapi2::ReturnCode mss_async_polling_loop(const fapi2::Target<T>& i_target )
{
    using ET = mss::mcbistMCTraits<MC>;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // A small vector of addresses to poll during the polling loop
    const std::vector<mss::poll_probe<T>> l_probes =
    {
        {i_target, "mcbist current address", TT::LAST_ADDR_REG},
    };

    // Poll for completion.
    fapi2::buffer<uint64_t> l_status;
    bool l_poll_results = false;

    // We'll fill in the initial delay below
    mss::poll_parameters l_poll_parameters(0, 200, 100 * mss::DELAY_1MS, 200, 10000);
    uint64_t l_memory_size = 0;

    FAPI_TRY( mss::eff_memory_size<MC>(i_target, l_memory_size) );
    l_poll_parameters.iv_initial_delay = mss::calculate_initial_delay<MC>(i_target,
                                         (l_memory_size * mss::BYTES_PER_GB), l_rc);
    FAPI_TRY(l_rc, "%s time to clock or clock to time conversion failed", mss::c_str(i_target));

    l_poll_results = mss::poll(i_target, TT::FIRQ_REG, l_poll_parameters,
                               [&l_status](const size_t poll_remaining,
                                           const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_DBG("mcbist firq 0x%llx, remaining: %d", stat_reg, poll_remaining);
        l_status = stat_reg;
        return l_status.getBit<TT::MCB_PROGRAM_COMPLETE>();
    },
    l_probes);

    FAPI_ASSERT( l_poll_results == true,
                 ET::memdiags_sf_init_failed_init().set_MC_TARGET(i_target),
                 "sf init for scrub/memdiags timedout %s", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Begin initialize memory
/// @tparam MC the mc type of the T
/// @tparam T fapi2::TargetType of the MC engine
/// @tparam TT the mcbistTraits associated with T
/// @param[in] i_target MC
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = mcbistTraits<MC, T> >
fapi2::ReturnCode mss_initialize_memory(const fapi2::Target<T>& i_target )
{
    FAPI_INF("Start mss_initialize_memory for %s", mss::c_str(i_target));

    // If there are no DIMM we don't need to bother. In fact, we can't as we didn't setup
    // attributes for the PHY, etc.
    if (mss::count_dimm(i_target) == 0)
    {
        FAPI_INF("... skipping scrub for %s - no DIMM ...", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // If we're running in the simulator, we want to only touch the addresses which training touched
    uint8_t l_sim = 0;

    FAPI_TRY( mss::attr::get_is_simulation( l_sim) );

    if (l_sim)
    {
        FAPI_INF("running mss sim init in place of scrub for %s", mss::c_str(i_target));

        // Use some sort of pattern in sim in case the verification folks need to look for something
        // TK. Need a verification pattern. This is a not-good pattern for verification ... We don't really
        // have a good pattern for verification defined.
        auto l_rc = mss::mcbist::sim::sf_init<MC>(i_target, mss::mcbist::PATTERN_0);

        // Unmask firs and turn off FIFO mode before returning
        FAPI_TRY ( mss::unmask::after_memdiags<MC>( i_target ) );
        FAPI_TRY ( mss::reset_reorder_queue_settings<MC>(i_target) );

        return l_rc;
    }

    // In Cronus on hardware (which is how we got here - f/w doesn't call this) we want
    // to call sf_init (0's)
    // TK we need to check FIR given the way this is right now, we should adjust with better stop
    // conditions when we learn more about what we want to find in the lab
    FAPI_TRY( mss::memdiags::sf_init<MC>(i_target, mss::mcbist::PATTERN_0) );

    // Polls for completion
    FAPI_TRY(mss_async_polling_loop<MC>(i_target));

    // Unmask firs after memdiags and turn off FIFO mode
    FAPI_TRY ( mss::unmask::after_memdiags<MC>( i_target ) );
    FAPI_TRY ( mss::reset_reorder_queue_settings<MC>(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Begin background scrub helper
/// @tparam MC the mc type of the T
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mcbistTraits associated with T
/// @param[in] i_target MC
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = mcbistTraits<MC, T> >
fapi2::ReturnCode mss_background_scrub_helper( const fapi2::Target<T>& i_target )
{
    FAPI_INF("Start mss_background_scrub_helper b on: %s", mss::c_str( i_target ));

    // If there are no DIMM we don't need to bother. In fact, we can't as we didn't setup
    // attributes for the PHY, etc.
    if (mss::count_dimm(i_target) == 0)
    {
        FAPI_INF("... skipping background scrub for %s - no DIMM ...", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // If we're running in the simulator, we want to only touch the addresses which training touched
    uint8_t l_sim = 0;
    FAPI_TRY( mss::attr::get_is_simulation(l_sim) );

    // Kick off background scrub if we are not running in sim
    if (!(l_sim))
    {
        // Start background scrub
        FAPI_TRY ( mss::memdiags::background_scrub<MC>( i_target,
                   mss::mcbist::stop_conditions<MC>(),
                   mss::mcbist::speed::BG_SCRUB,
                   mss::mcbist::address() ) );
    }

    // Unmask firs after background scrub is started
    FAPI_TRY ( mss::unmask::after_background_scrub<MC>( i_target ) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Begin firmware background scrub helper
/// @tparam MC the mc type of the T
/// @tparam T fapi2::TargetType of the MCBIST engine
/// @tparam TT the mcbistTraits associated with T
/// @param[in] i_target MC
/// @param[in] i_stop stop conditions
/// @param[in] i_speed the speed to scrub
/// @param[in] i_address mcbist::address representing the address from which to start
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = mcbistTraits<MC, T> >
fapi2::ReturnCode mss_firmware_background_scrub_helper( const fapi2::Target<T>& i_target,
        const stop_conditions<MC>& i_stop,
        const speed i_speed,
        const mss::mcbist::address& i_address )
{
    FAPI_INF("Start mss_firmware_background_scrub_helper on: %s", mss::c_str( i_target ));

    // Start background scrub
    FAPI_TRY ( mss::memdiags::background_scrub<MC>( i_target,
               i_stop,
               i_speed,
               i_address) );

    // Do not unmask firs here, since PRD explicitly calls mss::unmask::after_background_scrub.
    // In Cronus, the procedure calls mss_background_scrub_helper which does the unmasks.

fapi_try_exit:
    return fapi2::current_err;
}


} // namespace memdiags

} // namespace mss
#endif
