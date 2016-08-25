/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/conversions.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file conversions.H
/// @brief Functions to convert units
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CONVERSIONS_H_
#define _MSS_CONVERSIONS_H_

#include <vector>
#include <fapi2.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/shared/mss_const.H>
#include <lib/utils/find.H>

///
/// @brief Dereferences pointer of the vector's underlying data
//  and casts it to uint8_t[Y] that FAPI_ATTR_SET is expecting by deduction
/// @param[in] X is the input vector
/// @param[in] Y is the size of the vector
/// @warn compiler doesn't like the use of vector method size() for the second param
///
#define UINT8_VECTOR_TO_1D_ARRAY(X, Y)\
    reinterpret_cast<uint8_t(&)[Y]>(*X.data())

///
/// @brief Dereferences pointer of the vector's underlying data
//  and casts it to uint16_t[Y] that FAPI_ATTR_SET is expecting by deduction
/// @param[in] X is the input vector
/// @param[in] Y is the size of the vector
/// @warn compiler doesn't like the use of vector method size() for the second param
///
#define UINT16_VECTOR_TO_1D_ARRAY(X, Y)\
    reinterpret_cast<uint16_t(&)[Y]>(*X.data())

///
/// @brief Dereferences pointer of the vector's underlying data
//  and casts it to uint32_t[Y] that FAPI_ATTR_SET is expecting by deduction
/// @param[in] X is the input vector
/// @param[in] Y is the size of the vector
/// @warn compiler doesn't like the use of vector method size() for the second param
///
#define UINT32_VECTOR_TO_1D_ARRAY(X, Y)\
    reinterpret_cast<uint32_t(&)[Y]>(*X.data())


// Mutiplication factor to go from clocks to simcycles.
// Is this just 2400 speed or does this hold for all? BRS
static const uint64_t SIM_CYCLES_PER_CYCLE = 8;

namespace mss
{


///
/// @brief Return the number of picoseconds
/// @tparam T input type
/// @tparam OT output type
/// @param[in] i_speed_grade input in MegaTransfers per second (MT/s)
/// @param[out] o_tCK_in_ps
/// @return FAPI2_RC_SUCCESS if okay
///
template<typename T, typename OT>
inline fapi2::ReturnCode freq_to_ps(const T i_speed_grade, OT& o_tCK_in_ps )
{
    switch(i_speed_grade)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            o_tCK_in_ps = 1071;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
            o_tCK_in_ps = 937;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            o_tCK_in_ps = 833;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            o_tCK_in_ps = 750;
            break;

        default:
            FAPI_ERR("Invalid dimm speed grade (MT/s) - %d - provided");
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Return the number in MT/s
/// @tparam T input type
/// @tparam OT output type
/// @param[in] i_time_in_ps time in picoseconds
/// @param[out] o_speed_grade transfer rate in MT/s
/// @return FAPI2_RC_SUCCESS if okay
///
template<typename T, typename OT>
fapi2::ReturnCode ps_to_freq(const T i_time_in_ps, OT& o_speed_grade)
{
    switch(i_time_in_ps)
    {
        case 750:
            o_speed_grade = fapi2::ENUM_ATTR_MSS_FREQ_MT2666;
            break;

        case 833:
            o_speed_grade = fapi2::ENUM_ATTR_MSS_FREQ_MT2400;
            break;

        case 937:
            o_speed_grade = fapi2::ENUM_ATTR_MSS_FREQ_MT2133;
            break;

        case 1071:
            o_speed_grade = fapi2::ENUM_ATTR_MSS_FREQ_MT1866;
            break;

        default:
            FAPI_ERR("Invalid clock period (tCK) - %d - provided");
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;

}

///
/// @brief Translate from cycles to sim cycles
/// @param[in] i_cycles the cycles to translate
/// @return uint64_t, the number of sim cycles.
///
inline uint64_t cycles_to_simcycles( const uint64_t i_cycles )
{
    // Is this always the case or do we need the freq to really figure this out?
    return i_cycles * SIM_CYCLES_PER_CYCLE;
}

///
/// @brief Return the number of cycles contained in a count of picoseconds
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_ps the number of picoseconds to convert
/// @return uint64_t, the number of cycles
///
template< fapi2::TargetType T >
inline uint64_t ps_to_cycles(const fapi2::Target<T>& i_target, const uint64_t i_ps)
{
    // The frequency in mHZ
    uint64_t l_freq = 0;
    uint64_t l_divisor = 0;
    uint64_t l_quotient = 0;
    uint64_t l_remainder = 0;

    FAPI_TRY( mss::freq( find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq) );

    // No time if MT/s is 0 (well, infinite really but shut up)
    if (l_freq == 0)
    {
        return 0;
    }

    // Hoping the compiler figures out how to do these together.
    FAPI_TRY( freq_to_ps(l_freq, l_divisor) );
    l_quotient = i_ps / ((l_divisor == 0) ? 1 : l_divisor);
    l_remainder = i_ps % l_divisor;

    // Make sure we add a cycle if there wasn't an even number of cycles in the input
    FAPI_INF("converting %llups to %llu cycles", i_ps, l_quotient + (l_remainder == 0 ? 0 : 1));

    return l_quotient + (l_remainder == 0 ? 0 : 1);

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
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_cycles the number of cycles to convert
/// @return uint64_t, the number of picoseconds
///
template< fapi2::TargetType T >
inline uint64_t cycles_to_ps(const fapi2::Target<T>& i_target, const uint64_t i_cycles)
{
    // The frequency in mHZ
    uint64_t l_freq = 0;
    uint64_t l_clock_period = 0;

    FAPI_TRY( mss::freq( find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq) );
    FAPI_TRY( freq_to_ps(l_freq, l_clock_period) );
    FAPI_INF("converting %llu cycles to %llups", i_cycles, i_cycles * l_clock_period );
    return i_cycles * l_clock_period;

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
/// @brief Return the number of microseconds contained in a count of cycles
/// @tparam T the target type
/// @tparam D the time conversion (NS_IN_PS, etc)
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_cycles the number of cycles to convert
/// @return uint64_t, the number of microseconds
///
template< fapi2::TargetType T, uint64_t D >
inline uint64_t cycles_to_time(const fapi2::Target<T>& i_target, const uint64_t i_cycles)
{
    // Hoping the compiler figures out how to do these together.
    uint64_t l_dividend = cycles_to_ps(i_target, i_cycles);
    uint64_t l_quotient = l_dividend / ((D == 0) ? 1 : D);
    uint64_t l_remainder = l_dividend % D;

    // Make sure we add time if there wasn't an even number of cycles
    return  l_quotient + (l_remainder == 0 ? 0 : 1);
}

///
/// @brief Return the number of nanoseconds contained in a count of cycles
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_cycles the number of cycles to convert
/// @return uint64_t, the number of nanoseconds
///
template< fapi2::TargetType T >
inline uint64_t cycles_to_ns(const fapi2::Target<T>& i_target, const uint64_t i_cycles)
{
    uint64_t l_ns = cycles_to_time<T, CONVERT_PS_IN_A_NS>(i_target, i_cycles);
    FAPI_INF("converting %llu cycles to %lluns", i_cycles, l_ns);

    return l_ns;
}

///
/// @brief Return the number of microseconds contained in a count of cycles
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_cycles the number of cycles to convert
/// @return uint64_t, the number of microseconds
///
template< fapi2::TargetType T >
inline uint64_t cycles_to_us(const fapi2::Target<T>& i_target, const uint64_t i_cycles)
{
    uint64_t l_us = cycles_to_time<T, CONVERT_PS_IN_A_US>(i_target, i_cycles);
    FAPI_INF("converting %llu cycles to %lluus", i_cycles, l_us);

    return l_us;
}

///
/// @brief Convert nanoseconds to picoseconds
/// @tparam T input and output type
/// @param[in] i_time_in_ns time in nanoseconds
/// @return time in picoseconds
///
template<typename T>
inline T ns_to_ps(const T i_time_in_ns)
{
    return i_time_in_ns * CONVERT_PS_IN_A_NS;
}

///
/// @brief Convert nanoseconds to picoseconds
/// @tparam T input and output type
/// @param[in] i_time_in_ps time in picoseconds
/// @return time in nanoseconds
/// @note rounds up
///
template<typename T>
inline T ps_to_ns(const T i_time_in_ps)
{
    T remainder = i_time_in_ps % CONVERT_PS_IN_A_NS;
    T l_time_in_ns = i_time_in_ps / CONVERT_PS_IN_A_NS;

    // Round up if remainder isn't even
    return l_time_in_ns + ( remainder == 0 ? 0 : 1 );
}

///
/// @brief Return the maximum of two values *in clocks*, the first in clocks the second in ns
/// @tparam T the fapi2::TargetType of a type from which we can get MT/s
/// @param[in] i_clocks a value in clocks
/// @param[in] i_time a value in nanoseconds
/// @return max( iclocks nCK, i_time ) in clocks
///
template< fapi2::TargetType T >
inline uint64_t max_ck_ns(const fapi2::Target<T>& i_target, const uint64_t i_clocks, const uint64_t i_time)
{
    return std::max( i_clocks, ns_to_cycles(i_target, i_time) );
}


};// mss namespace

#endif
