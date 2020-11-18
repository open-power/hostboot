/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/utils/mss_exp_conversions.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file mss_exp_conversions.H
/// @brief Functions to convert units
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_EXPLORER_CONVERSIONS_H_
#define _MSS_EXPLORER_CONVERSIONS_H_

#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/conversions.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

///
/// @brief Return the number of cycles contained in a count of picoseconds
/// @tparam T the target type from which to get the mt/s
/// @tparam OT the output type, derrived from the parameters
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_ps the number of picoseconds to convert
/// @return uint64_t, the number of cycles
///
template< fapi2::TargetType T, typename OT >
inline OT ps_to_cycles(const fapi2::Target<T>& i_target, const OT i_ps)
{
    // The frequency in MT/s
    uint64_t l_freq = 0;
    uint64_t l_clock_period = 0;

    // Each OCMB only has one MEM_PORT
    for (const auto l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        FAPI_TRY(attr::get_freq(l_port, l_freq));
    }

    // No time if MT/s is 0 (well, infinite really but shut up)
    if (l_freq == 0)
    {
        return 0;
    }

    // Hoping the compiler figures out how to do these together.
    FAPI_TRY( freq_to_ps(l_freq, l_clock_period) );

    return ps_to_cycles( l_clock_period, i_ps );

fapi_try_exit:
    // We simply can't work if we can't get the frequency or
    // if we get an unsupported value that can't be converted to a valid tCK (clock period)
    // ...so this should be ok
    FAPI_ERR("Can't get MSS_FREQ or obtained an invalid MSS_FREQ (%d) - stopping", l_freq);
    fapi2::Assert(false);

    // Keeps compiler happy
    return 0;
}

///
/// @brief Return the number of ps contained in a count of cycles
/// @tparam T the target type from which to get the mt/s
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_cycles the number of cycles to convert
/// @return uint64_t, the number of picoseconds
///
template< fapi2::TargetType T >
inline uint64_t cycles_to_ps(const fapi2::Target<T>& i_target, const uint64_t i_cycles)
{
    // The frequency in MHZ
    uint64_t l_freq = 0;
    uint64_t l_clock_period = 0;

    // Each OCMB only has one MEM_PORT
    for (const auto l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        FAPI_TRY(attr::get_freq(l_port, l_freq));
    }

    FAPI_TRY( freq_to_ps(l_freq, l_clock_period) );
    return cycles_to_ps(l_clock_period, i_cycles);

fapi_try_exit:

    // We simply can't work if we can't get the frequency or
    // if we get an unsupported value that can't be converted to a valid tCK (clock period)
    // ...so this should be ok
    FAPI_ERR("Can't get MSS_FREQ or obtained an invalid MSS_FREQ (%d) - stopping", l_freq);
    fapi2::Assert(false);

    // Keeps compiler happy
    return 0;
}

///
/// @brief Return the number of cycles contained in a count of microseconds
/// @tparam T the target type from which to get the mt/s
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_us the number of microseconds to convert
/// @return uint64_t, the number of cycles
///
template< fapi2::TargetType T >
inline uint64_t us_to_cycles(const fapi2::Target<T>& i_target, const uint64_t i_us)
{
    return ps_to_cycles(i_target, i_us * CONVERT_PS_IN_A_US);
}

///
/// @brief Return the number of cycles contained in a count of nanoseconds
/// @tparam T the target type from which to get the mt/s
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_ps the number of nanoseconds to convert
/// @return uint64_t, the number of cycles
///
template< fapi2::TargetType T >
inline uint64_t ns_to_cycles(const fapi2::Target<T>& i_target, const uint64_t i_ns)
{
    return ps_to_cycles(i_target, i_ns * CONVERT_PS_IN_A_NS);
}

///
/// @brief Return the amount of unit time contained in a count of cycles
/// @tparam T the target type from which to get the mt/s
/// @tparam D the time conversion (NS_IN_PS, etc)
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_cycles the number of cycles to convert
/// @return uint64_t, the number of microseconds
///
template< uint64_t D, fapi2::TargetType T >
inline uint64_t cycles_to_time(const fapi2::Target<T>& i_target, const uint64_t i_cycles)
{
    // Hoping the compiler figures out how to do these together.
    uint64_t l_dividend = cycles_to_ps(i_target, i_cycles);
    uint64_t l_quotient = l_dividend / ((D == 0) ? 1 : D);
    uint64_t l_remainder = l_dividend % ((D == 0) ? 1 : D);

    // Make sure we add time if there wasn't an even number of cycles
    return  l_quotient + (l_remainder == 0 ? 0 : 1);
}

///
/// @brief Return the number of nanoseconds contained in a count of cycles
/// @tparam T the target type from which to get the mt/s
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_cycles the number of cycles to convert
/// @return uint64_t, the number of nanoseconds
///
template< fapi2::TargetType T >
inline uint64_t cycles_to_ns(const fapi2::Target<T>& i_target, const uint64_t i_cycles)
{
    uint64_t l_ns = cycles_to_time<CONVERT_PS_IN_A_NS>(i_target, i_cycles);
    return l_ns;
}

///
/// @brief Return the number of microseconds contained in a count of cycles
/// @tparam T the target type from which to get the mt/s
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_cycles the number of cycles to convert
/// @return uint64_t, the number of microseconds
///
template< fapi2::TargetType T >
inline uint64_t cycles_to_us(const fapi2::Target<T>& i_target, const uint64_t i_cycles)
{
    uint64_t l_us = cycles_to_time<CONVERT_PS_IN_A_US>(i_target, i_cycles);
    return l_us;
}

///
/// @brief Return the maximum of two values *in clocks*, the first in clocks the second in ns
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_target
/// @param[in] i_clocks a value in clocks
/// @param[in] i_time a value in nanoseconds
/// @return max( iclocks nCK, i_time ) in clocks
///
template< fapi2::TargetType T >
inline uint64_t max_ck_ns(const fapi2::Target<T>& i_target, const uint64_t i_clocks, const uint64_t i_time)
{
    return std::max( i_clocks, ns_to_cycles(i_target, i_time) );
}

} // ns mss

#endif
