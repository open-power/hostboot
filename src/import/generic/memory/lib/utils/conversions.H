/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/conversions.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CONVERSIONS_H_
#define _MSS_CONVERSIONS_H_

#include <vector>
#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/find.H>
#include <mss_generic_attribute_getters.H>

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

namespace dram_freq
{
//
// DRAM clock and frequency information
//
static const std::vector<std::pair<uint64_t, uint64_t>> FREQ_TO_CLOCK_PERIOD =
{
    {DIMM_SPEED_1600, 1250}, // DDR4
    {DIMM_SPEED_1866, 1071}, // DDR4
    {DIMM_SPEED_1866, 1072}, // DDR4 - rounding error.
    {DIMM_SPEED_2133,  937}, // DDR4
    {DIMM_SPEED_2133,  938}, // DDR4 - rounding error.
    {DIMM_SPEED_2400,  833}, // DDR4
    {DIMM_SPEED_2666,  750}, // DDR4
    {DIMM_SPEED_2933,  682}, // DDR4
    {DIMM_SPEED_3200,  625}, // DDR4/5
    {DIMM_SPEED_3600,  555}, // DDR5
    {DIMM_SPEED_4000,  500}, // DDR5
    {DIMM_SPEED_4400,  454}, // DDR5
    {DIMM_SPEED_4800,  416}, // DDR5
};
} // ns dram_freq

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
    // We need to have at least two bytes of data, due to the sizes of the frequencies and clock periods
    constexpr size_t MIN_BYTE_SIZE = 2;
    static_assert(sizeof(T) >= MIN_BYTE_SIZE && sizeof(OT) >= MIN_BYTE_SIZE,
                  "Input and output must be at least 2 bytes in length");

    // Temporary variables to help with the conversion
    const uint64_t l_input = static_cast<uint64_t>(i_speed_grade);
    uint64_t l_output = 0;

// TK look at assert. is a target needed/desired?
    FAPI_ASSERT(find_value_from_key(dram_freq::FREQ_TO_CLOCK_PERIOD, l_input, l_output),
                fapi2::MSS_INVALID_FREQUENCY()
                .set_FREQ(l_input),
                "Frequency %u does not have an associated clock period", l_input);

    // Cast the output type
    o_tCK_in_ps = static_cast<OT>(l_output);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
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
    // We need to have at least two bytes of data, due to the sizes of the frequencies and clock periods
    constexpr size_t MIN_BYTE_SIZE = 2;
    static_assert(sizeof(T) >= MIN_BYTE_SIZE && sizeof(OT) >= MIN_BYTE_SIZE,
                  "Input and output must be at least 2 bytes in length");

    // Temporary variables to help with the conversion
    const uint64_t l_input = static_cast<uint64_t>(i_time_in_ps);
    uint64_t l_output = 0;

    FAPI_ASSERT(find_key_from_value(dram_freq::FREQ_TO_CLOCK_PERIOD, l_input, l_output),
                fapi2::MSS_INVALID_CLOCK_PERIOD()
                .set_CLOCK_PERIOD(l_input),
                "Clock period %u does not have an associated frequency", l_input);

    // Cast the output type
    o_speed_grade = static_cast<OT>(l_output);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;

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
/// @tparam T clock period input type
/// @tparam OT the output type, derrived from the parameters
/// @param[in] i_clock_period clock period in PS
/// @param[in] i_ps the number of picoseconds to convert
/// @return the number of cycles
///
template< typename T, typename OT >
inline OT ps_to_cycles(const T i_clock_period, const OT i_ps)
{
    // Casts the clock period to be in OT type to avoid any weird math issues
    const auto l_divisor = static_cast<OT>(i_clock_period);

    const OT l_rounder = (i_ps < 0) ? -1 : 1;

    // Ensure we don't divide by 0
    const OT l_quotient = i_ps / ((i_clock_period == 0) ? l_rounder : l_divisor);
    const OT l_remainder = i_ps % ((i_clock_period == 0) ? 1 : l_divisor);

    // Make sure we add a cycle if there wasn't an even number of cycles in the input
    FAPI_INF("converting %llups to %llu cycles", i_ps, l_quotient + (l_remainder == 0 ? 0 : l_rounder));

    return l_quotient + (l_remainder == 0 ? 0 : l_rounder);
}

///
/// @brief Return the number of cycles contained in a count of picoseconds
/// @tparam T the target type from which to get the mt/s
/// @tparam OT the output type, derrived from the parameters
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_ps the number of picoseconds to convert
/// @param[out] o_rc a return code used to handle an error
/// @return uint64_t, the number of cycles
///
template< fapi2::TargetType T, typename OT >
inline OT ps_to_cycles(const fapi2::Target<T>& i_target, const OT i_ps, fapi2::ReturnCode& o_rc)
{
    // The frequency in MT/s
    uint64_t l_freq = 0;
    uint64_t l_clock_period = 0;

    // Each OCMB only has one MEM_PORT
    for (const auto l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        FAPI_TRY(mss::attr::get_freq(l_port, l_freq),
                 "%s Can't get valid MSS_FREQ - stopping", mss::c_str(i_target));
    }

    // No time if MT/s is 0 (well, infinite really but shut up)
    if (l_freq == 0)
    {
        return 0;
    }

    // Hoping the compiler figures out how to do these together.
    FAPI_TRY( freq_to_ps(l_freq, l_clock_period),
              "%s Failed to convert memory frequency (%d) to a valid clock period. Clock period returned: (%d) - stopping",
              mss::c_str(i_target), l_freq, l_clock_period);

    return ps_to_cycles( l_clock_period, i_ps);

fapi_try_exit:
    o_rc = fapi2::current_err;

    // Keeps compiler happy
    return 0;
}

///
/// @brief Return the number of ps contained in a count of cycles
/// @param[in] i_clock_period
/// @param[in] i_cycles the number of cycles to convert
/// @return uint64_t, the number of picoseconds
///
inline uint64_t cycles_to_ps(const uint64_t i_clock_period, const uint64_t i_cycles)
{
    const auto l_ps = i_cycles * i_clock_period;
    FAPI_INF("converting %llu cycles to %llups", i_cycles, l_ps );
    return l_ps;
}

///
/// @brief Return the number of ps contained in a count of cycles
/// @tparam T the target type from which to get the mt/s
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_cycles the number of cycles to convert
/// @param[out] o_rc a return code used to handle an error
/// @return uint64_t, the number of picoseconds
///
template< fapi2::TargetType T >
inline uint64_t cycles_to_ps(const fapi2::Target<T>& i_target, const uint64_t i_cycles, fapi2::ReturnCode& o_rc)
{
    // The frequency in MHZ
    uint64_t l_freq = 0;
    uint64_t l_clock_period = 0;

    // Each OCMB only has one MEM_PORT
    for (const auto l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        FAPI_TRY(attr::get_freq(l_port, l_freq),
                 "%s Can't get a valid MSS_FREQ - stopping", mss::c_str(i_target));
    }

    FAPI_TRY( freq_to_ps(l_freq, l_clock_period),
              "%s Failed to convert memory frequency to a valid clock period (%d) - stopping",
              mss::c_str(i_target), l_freq);
    return cycles_to_ps(l_clock_period, i_cycles);

fapi_try_exit:
    o_rc = fapi2::current_err;

    // Keeps compiler happy
    return 0;
}

///
/// @brief Return the number of cycles contained in a count of microseconds
/// @param[in] i_clock_period the clock period in PS
/// @param[in] i_us the number of microseconds to convert
/// @return uint64_t, the number of cycles
///
inline uint64_t us_to_cycles(const uint64_t i_clock_period,  const uint64_t i_us)
{
    return ps_to_cycles(i_clock_period, i_us * CONVERT_PS_IN_A_US);
}

///
/// @brief Return the number of cycles contained in a count of microseconds
/// @tparam T the target type from which to get the mt/s
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_us the number of microseconds to convert
/// @param[out] o_rc a return code used to handle an error
/// @return uint64_t, the number of cycles
///
template< fapi2::TargetType T >
inline uint64_t us_to_cycles(const fapi2::Target<T>& i_target, const uint64_t i_us, fapi2::ReturnCode& o_rc)
{
    return ps_to_cycles(i_target, i_us * CONVERT_PS_IN_A_US, o_rc);
}

///
/// @brief Return the number of cycles contained in a count of nanoseconds
/// @tparam T the target type from which to get the mt/s
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_ps the number of nanoseconds to convert
/// @param[out] o_rc a return code used to handle an error
/// @return uint64_t, the number of cycles
///
template< fapi2::TargetType T >
inline uint64_t ns_to_cycles(const fapi2::Target<T>& i_target, const uint64_t i_ns, fapi2::ReturnCode& o_rc)
{
    return ps_to_cycles(i_target, i_ns * CONVERT_PS_IN_A_NS, o_rc);
}


///
/// @brief Return the number of cycles contained in a count of nanoseconds
/// @param[in] i_clock_period the clock period in PS
/// @param[in] i_ps the number of nanoseconds to convert
/// @return uint64_t, the number of cycles
///
inline uint64_t ns_to_cycles(const uint64_t i_clock_period,  const uint64_t i_ns)
{
    return ps_to_cycles(i_clock_period, i_ns * CONVERT_PS_IN_A_NS);
}

///
/// @brief Return the number of microseconds contained in a count of cycles
/// @tparam D the time conversion (NS_IN_PS, etc)
/// @param[in] i_clock_period the clock period in PS
/// @param[in] i_cycles the number of cycles to convert
/// @return uint64_t, the number of microseconds
///
template< uint64_t D >
inline uint64_t cycles_to_time(const uint64_t i_clock_period, const uint64_t i_cycles)
{
    // Hoping the compiler figures out how to do these together.
    const auto l_dividend = cycles_to_ps(i_clock_period, i_cycles);
    constexpr uint64_t DIVISOR = ((D == 0) ? 1 : D);
    const uint64_t l_quotient = l_dividend / DIVISOR;
    const uint64_t l_remainder = l_dividend % DIVISOR;

    // Make sure we add time if there wasn't an even number of cycles
    return  l_quotient + (l_remainder == 0 ? 0 : 1);
}

///
/// @brief Return the amount of unit time contained in a count of cycles
/// @tparam D the time conversion (NS_IN_PS, etc)
/// @tparam T the target type from which to get the mt/s
/// @param[in] i_target target for the frequency attribute
/// @param[in] i_cycles the number of cycles to convert
/// @param[out] o_rc a return code used to handle an error
/// @return uint64_t, the number of microseconds
///
template< uint64_t D, fapi2::TargetType T >
inline uint64_t cycles_to_time(const fapi2::Target<T>& i_target, const uint64_t i_cycles, fapi2::ReturnCode& o_rc)
{
    // Hoping the compiler figures out how to do these together.
    uint64_t l_dividend = cycles_to_ps(i_target, i_cycles, o_rc);
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
/// @param[out] o_rc a return code used to handle an error
/// @return uint64_t, the number of nanoseconds
///
template< fapi2::TargetType T >
inline uint64_t cycles_to_ns(const fapi2::Target<T>& i_target, const uint64_t i_cycles, fapi2::ReturnCode& o_rc)
{
    uint64_t l_ns = cycles_to_time<CONVERT_PS_IN_A_NS>(i_target, i_cycles, o_rc);
    return l_ns;
}

///
/// @brief Return the number of nanoseconds contained in a count of cycles
/// @tparam T the target type
/// @tparam MC memory controller type
/// @param[in] i_clock_period the clock period in PS
/// @param[in] i_cycles the number of cycles to convert
/// @return uint64_t, the number of nanoseconds
///
inline uint64_t cycles_to_ns(const uint64_t i_clock_period, const uint64_t i_cycles)
{
    const uint64_t l_ns = cycles_to_time<CONVERT_PS_IN_A_NS>(i_clock_period, i_cycles);
    FAPI_INF("converting %llu cycles to %lluns", i_cycles, l_ns);

    return l_ns;
}

///
/// @brief Return the number of microseconds contained in a count of cycles
/// @param[in] i_clock_period the clock period in PS
/// @param[in] i_cycles the number of cycles to convert
/// @return uint64_t, the number of microseconds
///
inline uint64_t cycles_to_us(const uint64_t i_clock_period, const uint64_t i_cycles)
{
    const uint64_t l_us = cycles_to_time<CONVERT_PS_IN_A_US>(i_clock_period, i_cycles);
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
/// @param[in] i_clock_period the clock period in PS
/// @param[in] i_clocks a value in clocks
/// @param[in] i_time a value in nanoseconds
/// @return max( iclocks nCK, i_time ) in clocks
///
inline uint64_t max_ck_ns(const uint64_t i_clock_period, const uint64_t i_clocks, const uint64_t i_time)
{
    return std::max( i_clocks, ns_to_cycles(i_clock_period, i_time) );
}

} // mss namespace

#endif
