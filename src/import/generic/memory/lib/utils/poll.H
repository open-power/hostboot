/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/poll.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
/// @file poll.H
/// @brief Poll a scom
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_POLL_H_
#define _MSS_POLL_H_

#include <fapi2.H>

#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

///
/// @class poll_probe
/// @brief Structure to represent a vector of addresses to probe during the polling loop
/// @tparam fapi2::TargetType, representing the target of the probe (does a getscom)
///
template< fapi2::TargetType T >
struct poll_probe
{
    ///
    /// @brief poll-probe constructor
    /// @param[in] i_target the target for the scom operation
    /// @param[in] i_tag some useful text to output with the register data
    /// @param[in] i_register the register for the scom operation
    ///
    poll_probe( const fapi2::Target<T>& i_target, const char* i_tag, const uint64_t i_register ):
        iv_target(i_target),
        iv_tag(i_tag),
        iv_register(i_register)
    {
    }

    fapi2::Target<T> iv_target;

    // String to be output with the value of the register,
    // Often is the name of the register
    const char* iv_tag;
    uint64_t iv_register;
};

///
/// @brief Poll paramter data structure.
/// Represents the parameters used to poll a register.
/// _delays are in ns, _sim_delays are in sim_cycles
/// See conversions.H for conversions.
///
struct poll_parameters
{
    // We need to decide how long to wait before pounding the compeletion SCOM.
    // IN NS
    uint64_t iv_initial_delay;

    // Same as the initial delay, but used when we're running in a simulator
    // IN SIM_CYCLES
    uint64_t iv_initial_sim_delay;

    // How many ns to wait in between poll attempts
    // IN NS
    uint64_t iv_delay;

    // Same as the interpoll delay, but used when we're running in a simulator
    // IN SIM_CYCLES
    uint64_t iv_sim_delay;

    // The count of polls to make
    uint64_t iv_poll_count;

    ///
    /// @brief checks if two poll_parameters are equal
    /// @param[in] i_rhs poll_parameters to compare
    /// @return bool true if equal
    ///
    inline bool operator==( const poll_parameters& i_rhs ) const
    {
        //checks equality
        bool l_equal = iv_initial_delay == i_rhs.iv_initial_delay;
        l_equal &= iv_initial_sim_delay == i_rhs.iv_initial_sim_delay;
        l_equal &= iv_delay == i_rhs.iv_delay;
        l_equal &= iv_sim_delay == i_rhs.iv_sim_delay;
        l_equal &= iv_poll_count == i_rhs.iv_poll_count;

        //returns the result
        return l_equal;
    }

    poll_parameters( const uint64_t i_initial_delay = DELAY_10NS,
                     const uint64_t i_initial_sim_delay = 200,
                     const uint64_t i_delay = DELAY_10NS,
                     const uint64_t i_sim_delay = 200,
                     const uint64_t i_poll_count = DEFAULT_POLL_LIMIT):
        iv_initial_delay(i_initial_delay),
        iv_initial_sim_delay(i_initial_sim_delay),
        iv_delay(i_delay),
        iv_sim_delay(i_sim_delay),
        iv_poll_count(i_poll_count)
    {}
};

///
/// @brief Poll a scom, return whether the poll criteria were met or not
/// @tparam T the fapi2::TargetType
/// @tparam L a lambda representing the completion criteria - returns true
/// @tparam P the fapi2::TargetType of the target in the probe vector
/// iff the poll criteria have been met (and the polling can stop)
/// @param[in] i_target target for the getScom
/// @param[in] i_addr the address for the scom
/// @param[in] i_params a poll_parameters structure
/// @param[in] i_fn the function to call to check the poll criteria
/// [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
///    {
///        return true;
///    }
/// @param[in] i_probes a vector of poll_probes to be used in the polling loop (optional)
/// @return bool, true iff poll criteria was met before the number of iterations
/// ran out.
/// @warning If you want to handle a failure as an error, you need to wrap
/// the call to poll() in a FAPI_ASSERT. FAPI_TRY is *not* the right mechanism
/// as poll() does not return a fapi2::ReturnCode
///
template< fapi2::TargetType T, typename L, fapi2::TargetType P = fapi2::TARGET_TYPE_MCA >
inline bool poll(const fapi2::Target<T>& i_target,
                 const uint64_t i_addr,
                 const poll_parameters i_params,
                 L i_fn,
                 const std::vector< poll_probe<P> >& i_probes = std::vector< poll_probe<P> >() )
{
    fapi2::buffer<uint64_t> l_reg;

#ifndef __PPE__
    FAPI_DBG("%s polling 0x%llx: initial delay %luns(%lusc) poll %luns(%lusc) %lu iters",
             mss::c_str(i_target), i_addr, i_params.iv_initial_delay, i_params.iv_initial_sim_delay,
             i_params.iv_delay, i_params.iv_sim_delay, i_params.iv_poll_count);
#endif

    // We know to wait this long before polling
    FAPI_TRY( fapi2::delay(i_params.iv_initial_delay, i_params.iv_initial_sim_delay) );

    for ( size_t l_poll_limit = i_params.iv_poll_count; l_poll_limit > 0; --l_poll_limit )
    {
        // Output anything in the probes
        for (const auto& p : i_probes)
        {
            fapi2::buffer<uint64_t> l_data;
            FAPI_TRY( mss::getScom(p.iv_target, p.iv_register, l_data) );

            // PPE cannot print 64-bit numbers and only allows for 4 variables per print statement
            // using an ifdef to keep the nice inline format for non-PPE applications
#ifdef __PPE__
            FAPI_INF( TARGTIDFORMAT ": %s REG: " UINT64FORMAT, GENTARGTID(p.iv_target), p.iv_tag, UINT64_VALUE(p.iv_register));
            FAPI_INF( TARGTIDFORMAT ": %s ADDR:" UINT64FORMAT, GENTARGTID(p.iv_target), p.iv_tag, UINT64_VALUE(l_data));
#else
            FAPI_INF( TARGTIDFORMAT ": %s 0x%016llx 0x%016llx", GENTARGTID(p.iv_target), p.iv_tag, p.iv_register, l_data);
#endif
        }

        FAPI_TRY( mss::getScom(i_target, i_addr, l_reg) );

        if (i_fn(l_poll_limit, l_reg) == true)
        {
            FAPI_DBG(TARGTIDFORMAT " polling finished. %d iterations remaining" , TARGTID, l_poll_limit);
            return true;
        }

        FAPI_TRY( fapi2::delay(i_params.iv_delay, i_params.iv_sim_delay) );
    }

    // If we're here, we ran out of poll iterations
    FAPI_INF(TARGTIDFORMAT " WARNING: Timeout on polling", TARGTID);
    return false;

fapi_try_exit:
    FAPI_ERR("mss::poll() hit an error in fapi2::delay or mss::getScom");
    return false;
}

///
/// @brief A generic poll that return whether the poll criteria were met
/// @tparam T the fapi2::TargetType
/// @tparam L a lambda representing the completion criteria - returns true
/// @param[in] i_target target for the getScom
/// @param[in] i_params a poll_parameters structure
/// @param[in] i_fn the function to call to check the poll criteria
/// [capture_by_value]() -> bool
///    {
///        return true;
///    }
/// @return bool, true iff poll criteria was met before the number of iterations
/// ran out.
/// @warning If you want to handle a failure as an error, you need to wrap
/// the call to poll() in a FAPI_ASSERT. FAPI_TRY is *not* the right mechanism
/// as poll() does not return a fapi2::ReturnCode
///
template< fapi2::TargetType T, typename L >
inline bool poll(const fapi2::Target<T>& i_target,
                 const poll_parameters i_params,
                 L i_fn)
{
#ifndef __PPE__
    FAPI_DBG(TARGTIDFORMAT " polling initial delay %luns(%lusc) poll %luns(%lusc) %lu iters",
             TARGTID, i_params.iv_initial_delay, i_params.iv_initial_sim_delay,
             i_params.iv_delay, i_params.iv_sim_delay, i_params.iv_poll_count);
#endif

    // We know to wait this long before polling
    FAPI_TRY( fapi2::delay(i_params.iv_initial_delay, i_params.iv_initial_sim_delay) );

    for ( size_t l_poll_limit = i_params.iv_poll_count; l_poll_limit > 0; --l_poll_limit )
    {
        if (i_fn())
        {
            FAPI_DBG(TARGTIDFORMAT " polling finished. %d iterations remaining" , TARGTID, l_poll_limit);
            return true;
        }

        FAPI_TRY( fapi2::delay(i_params.iv_delay, i_params.iv_sim_delay) );
    }

    // If we're here, we ran out of poll iterations
    FAPI_INF(TARGTIDFORMAT " WARNING: Timeout on polling", TARGTID);
    return false;

fapi_try_exit:
    FAPI_ERR("mss::poll() hit an error in fapi2::delay");
    return false;
}

}
#endif
