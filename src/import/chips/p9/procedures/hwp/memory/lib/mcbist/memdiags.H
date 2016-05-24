/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mcbist/memdiags.H $        */
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
/// @file memdiags.H
/// @brief API for memory diagnostics
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: HB:FSP
//

#ifndef _MSS_MEMDIAGS_H_
#define _MSS_MEMDIAGS_H_

#include <fapi2.H>
#include <lib/mcbist/mcbist.H>
#include <lib/mcbist/address.H>
#include <lib/mcbist/patterns.H>
#include <lib/mcbist/settings.H>

namespace memdiags
{

// Map some of the mcbist namespace here to make it easier for users of memdiags
// This is an intentional using statement in a header which is typically
// disallowed - I am intentionally pulling these into this namespace for all callers.
using mss::mcbist::thresholds;
using mss::mcbist::constraints;
using mss::mcbist::speed;
using mss::mcbist::end_boundary;
using mss::mcbist::stop_conditions;
using mss::mcbist::address;
using mss::mcbist::cache_line;
using mss::mcbist::pattern;
using mss::mcbist::patterns;

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
/// @class Base class for memdiags operations
/// @tparam T fapi2::TargetType of the MCBIST engine
///
template< fapi2::TargetType T >
class base
{
    public:
        ///
        /// @brief memdiags::base constructor
        /// @param[in] i_target the target of the mcbist engine
        /// @param[in] i_const mss::constraint structure
        ///
        base( const fapi2::Target<T>& i_target,
              const memdiags::constraints i_const ):
            iv_target(i_target),
            iv_const(i_const)
        {
        }

        base() = delete;

        ///
        /// @brief memdiags::base initializer
        /// @return FAPI2_RC_SUCCESS iff everything ok
        /// @note specialized for Nimbus as the port select mechanism is different
        // Needed because of the scom operations done in the initialization. There
        // is no good way to handle these errors in a constructor
        ///
        fapi2::ReturnCode init();

        ///
        /// @brief Execute the memdiags operation
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        inline fapi2::ReturnCode execute()
        {
            return mss::mcbist::execute(iv_target, iv_program);
        }

        ///
        /// @brief memdiags::base destructor
        ///
        virtual ~base() = default;

    protected:
        fapi2::Target<T>          iv_target;
        constraints               iv_const;
        mss::mcbist::program<T>   iv_program;
};

///
/// @class Base class for memdiags super-fast operations
/// @tparam T fapi2::TargetType of the MCBIST engine
///
template< fapi2::TargetType T >
class sf_operation : public base<T>
{
    public:
        ///
        /// @brief memdiags::sf_operation constructor
        /// @param[in] i_target the target of the mcbist engine
        /// @param[in] i_const mss::constraint structure
        /// @param[in] i_subtest the appropriate subtest for this operation
        ///
        sf_operation( const fapi2::Target<T>& i_target,
                      const memdiags::constraints i_const,
                      const mss::mcbist::subtest_t<T> i_subtest ):
            base<T>(i_target, i_const),
            iv_subtest(i_subtest)
        {
        }

        sf_operation() = delete;

        ///
        /// @brief memdiags::sf_operation initializer
        /// @return FAPI2_RC_SUCCESS iff everything ok
        // Needed because of the scom operations done in the initialization. There
        // is no good way to handle these errors in a constructor
        ///
        fapi2::ReturnCode init();

        ///
        /// @brief memdiags::sf_operation destructor
        ///
        virtual ~sf_operation() = default;

    protected:
        mss::mcbist::subtest_t<T> iv_subtest;
};

///
/// @class Base class for memdiags' super-fast init
/// @tparam T fapi2::TargetType of the MCBIST engine
///
template< fapi2::TargetType T >
struct sf_init_operation : public sf_operation<T>
{

    ///
    /// @brief memdiags::sf_init_operation constructor
    /// @param[in] i_target the target of the mcbist engine
    /// @param[in] i_pattern an index representing a pattern to use to initize memory
    /// @param[out] o_rc the fapi2::ReturnCode of the intialization process
    ///
    sf_init_operation( const fapi2::Target<T>& i_target,
                       const uint64_t i_pattern,
                       fapi2::ReturnCode& o_rc ):
        sf_operation<T>(i_target, constraints(i_pattern), mss::mcbist::init_subtest<T>())
    {
        o_rc = sf_operation<T>::init();
    }

    sf_init_operation() = delete;
};

///
/// @class Base class for memdiags' super-fast read
/// @tparam T fapi2::TargetType of the MCBIST engine
///
template< fapi2::TargetType T >
struct sf_read_operation : public sf_operation<T>
{

    ///
    /// @brief memdiags::sf_read_operation constructor
    /// @param[in] i_target the target of the mcbist engine
    /// @param[in] i_stop stop conditions
    /// @param[in] i_thresholds thresholds
    /// @param[out] o_rc the fapi2::ReturnCode of the intialization process
    ///
    sf_read_operation( const fapi2::Target<T>& i_target,
                       const memdiags::stop_conditions i_stop,
                       const memdiags::thresholds& i_thresholds,
                       fapi2::ReturnCode& o_rc ):
        sf_operation<T>(i_target, constraints(i_stop, i_thresholds), mss::mcbist::read_subtest<T>())
    {
        o_rc = sf_operation<T>::init();
    }

    ///
    /// @brief memdiags::sf_read_operation constructor - given starting address
    /// @param[in] i_target the target of the mcbist engine
    /// @param[in] i_stop stop conditions
    /// @param[in] i_thresholds thresholds
    /// @param[in] i_address start address of read operation
    /// @note the address indicates this operation is performed on one port, one dimm until the end
    /// @param[out] o_rc the fapi2::ReturnCode of the intialization process
    ///
    sf_read_operation( const fapi2::Target<T>& i_target,
                       const memdiags::stop_conditions i_stop,
                       const memdiags::thresholds& i_thresholds,
                       const memdiags::address& i_start_address,
                       fapi2::ReturnCode& o_rc ):
        sf_operation<T>(i_target, constraints(i_stop, i_thresholds, i_start_address), mss::mcbist::read_subtest<T>())
    {
        o_rc = sf_read_operation<T>::end_of_port_init();
    }

    sf_read_operation() = delete;

    ///
    /// @brief memdiags::sf_read_operation end-of-port initializer
    /// @return FAPI2_RC_SUCCESS iff everything ok
    // Needed because of the scom operations done in the initialization. There
    // is no good way to handle these errors in a constructor
    ///
    fapi2::ReturnCode end_of_port_init();
};

///
/// @brief Super Fast Init - used to init all memory behind a target with a given pattern
/// @note Uses broadcast mode if possible
/// @tparam T the fapi2::TargetType of the target
/// @param[in] i_target the target behind which all memory should be initialized
/// @param[in] i_pattern an index representing a pattern to use to init memory (defaults to 0)
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
///
template< fapi2::TargetType T >
fapi2::ReturnCode sf_init( const fapi2::Target<T>& i_target,
                           const uint64_t i_pattern = PATTERN_0 );

///
/// @brief Super Fast Read All - used to run superfast read on all memory behind the target
/// @note Uses broadcast mode if possible
/// @param[in] i_target the target behind which all memory should be read
/// @param[in] i_stop stop conditions
/// @param[in] i_thresholds thresholds
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
///
template< fapi2::TargetType T >
fapi2::ReturnCode sf_read( const fapi2::Target<T>& i_target,
                           const stop_conditions i_stop,
                           const thresholds& i_thresholds );

///
/// @brief Super Fast Read to End of Port - used to run superfast read on all memory behind the target
/// @tparam T the fapi2::TargetType of the target
/// @param[in] i_target the target behind which all memory should be read
/// @param[in] i_stop stop conditions
/// @param[in] i_thresholds thresholds
/// @param[in] i_address mcbist::address representing the address from which to start.
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
/// @note The address is often the port, dimm, rank but this is not enforced in the API.
///
template< fapi2::TargetType T >
fapi2::ReturnCode sf_read( const fapi2::Target<T>& i_target,
                           const stop_conditions i_stop,
                           const thresholds& i_thresholds,
                           const address& i_address );

///
/// @brief Scrub - scrub all memory behind the target
/// @param[in] i_target the target behind which all memory should be scrubbed
/// @param[in] i_stop stop conditions
/// @param[in] i_thresholds thresholds
/// @param[in] i_speed the speed to scrub
/// @param[in] i_address mcbist::address representing the address from which to start.
/// @param[in] i_end whether to end, and where (default = continuous scrub)
/// @return FAPI2_RC_SUCCESS iff everything ok
/// @note The function is asynchronous, and the caller should be looking for a done attention
/// @note The address is often the port, dimm, rank but this is not enforced in the API.
///
template< fapi2::TargetType T >
fapi2::ReturnCode scrub( const fapi2::Target<T>& i_target,
                         const stop_conditions i_stop,
                         const thresholds& i_thresholds,
                         const speed i_speed,
                         const address& i_address,
                         const end_boundary i_end = end_boundary::NEVER );

///
/// @brief Continue current command on next address
/// The current commaand has paused on an error, so we can record the address of the error
/// and finish the current master or slave rank.
/// @tparam T the fapi2::TargetType of the target
/// @param[in] i_target the target
/// @param[in] i_end whether to end, and where (default = don't stop at end of rank)
/// @param[in] i_stop stop conditions (default - 0 meaning 'don't change conditions')
/// @param[in] i_speed the speed to scrub (default - NO_CHANGE meaning leave speed untouched)
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode continue_cmd( const fapi2::Target<T>& i_target,
                                const end_boundary i_end = end_boundary::DONT_STOP,
                                const stop_conditions i_stop = stop_conditions::DONT_CHANGE,
                                const speed i_speed = speed::SAME_SPEED );

///
/// @brief Continue current command on next address - change thresholds
/// The current commaand has paused on an error, so we can record the address of the error
/// and finish the current master or slave rank.
/// @tparam T the fapi2::TargetType of the target
/// @param[in] i_target the target
/// @param[in] i_thresholds new thresholds
/// @param[in] i_end whether to end, and where (default = don't stop at end of rank)
/// @param[in] i_stop stop conditions (default - 0 meaning 'don't change conditions')
/// @param[in] i_speed the speed to scrub (default - NO_CHANGE meaning leave speed untouched)
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode continue_cmd( const fapi2::Target<T>& i_target,
                                const thresholds& i_thresholds,
                                const end_boundary i_end = end_boundary::DONT_STOP,
                                const stop_conditions i_stop = stop_conditions::DONT_CHANGE,
                                const speed i_speed = speed::SAME_SPEED );

///
/// @brief Stop the current command
/// @tparam T the fapi2::TargetType of the target
/// @param[in] i_target the target
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode stop( const fapi2::Target<T>& i_target );

} // namespace

#endif

