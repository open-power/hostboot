/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/conversions.H $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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

#include <fapi2.H>
#include <mss_attribute_accessors.H>
#include "../shared/mss_const.H"
#include "find.H"

// Mutiplication factor to go from clocks to simcycles.
// Is this just 2400 speed or does this hold for all? BRS
static const uint64_t SIM_CYCLES_PER_CYCLE = 8;

namespace mss
{

///
/// @brief Return the number of picoseconds taken by a certain mhz
/// @param[in] i_mhz - the mhz of interest
/// @return the picoseconds
///
inline uint64_t mhz_to_ps(const uint64_t i_mhz)
{
    // Just used for indexs into the array below
    enum freqs { FREQ_2400 = 0, };

    // ATTR_MSS_FREQ is in mHZ, and we know us per clock is 1/(freq/2)
    // We don't have many frequencies, so lets just make a little table.
    static const uint64_t FREQ_TO_PS[MAX_SUPPORTED_FREQUENCIES] =
    {
        // 2400 is 833 picoseconds per clock
        833
    };

    switch(i_mhz)
    {
        case 2400:
            return FREQ_TO_PS[FREQ_2400];

        default:
            FAPI_ERR("unsupported frequency %d", i_mhz);
            fapi2::Assert(false);

            // Keeps compiler happy
            return 0;
    }
}

///
/// @brief Translate from cycles to sim cycles
/// @param[in] i_cycles, the cycles to translate
/// @return uint64_t, the number of sim cycles.
///
inline uint64_t cycles_to_simcycles( const uint64_t i_cycles )
{
    // Is this always the case or do we need the freq to really figure this out?
    return i_cycles * SIM_CYCLES_PER_CYCLE;
}

///
/// @brief Return the number of cycles contained in a count of picoseconds
/// @param[in] i_target, target for the frequency attribute
/// @param[in] i_ps, the number of picoseconds to convert
/// @return uint64_t, the number of cycles
///
template< fapi2::TargetType T >
inline uint64_t ps_to_cycles(const fapi2::Target<T>& i_target, const uint64_t i_ps)
{
    // The frequency in mHZ
    uint64_t l_freq;
    uint64_t l_divisor = 0;
    uint64_t l_quotient = 0;
    uint64_t l_remainder = 0;

    FAPI_TRY( mss::freq( find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq) );

    // Hoping the compiler figures out how to do these together.
    l_divisor = mhz_to_ps(l_freq);
    l_quotient = i_ps / l_divisor;
    l_remainder = i_ps % l_divisor;

    // Make sure we add a cycle if there wasn't an even number of cycles in the input
    FAPI_DBG("converting %dps to %d cycles", i_ps, l_quotient + (l_remainder == 0 ? 0 : 1));

    return l_quotient + (l_remainder == 0 ? 0 : 1);

fapi_try_exit:

    // We simply can't work if we can't get the frequency - so this should be ok
    FAPI_ERR("Can't get MSS_FREQ - stopping");
    fapi2::Assert(false);

    // Keeps compiler happy
    return 0;
}

///
/// @brief Return the number of ps contained in a count of cycles
/// @param[in] i_target, target for the frequency attribute
/// @param[in] i_ps, the number of cycles to convert
/// @return uint64_t, the number of picoseconds
///
template< fapi2::TargetType T >
inline uint64_t cycles_to_ps(const fapi2::Target<T>& i_target, const uint64_t i_cycles)
{
    // The frequency in mHZ
    uint64_t l_freq;

    FAPI_TRY( mss::freq( find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_freq) );

    FAPI_DBG("converting %d cycles to %dps", i_cycles, i_cycles * mhz_to_ps(l_freq));
    return i_cycles * mhz_to_ps(l_freq);

fapi_try_exit:

    // We simply can't work if we can't get the frequency - so this should be ok
    FAPI_ERR("Can't get MSS_FREQ - stopping");
    fapi2::Assert(false);

    // Keeps compiler happy
    return 0;
}

///
/// @brief Return the number of cycles contained in a count of microseconds
/// @param[in] i_target, target for the frequency attribute
/// @param[in] i_ps, the number of microseconds to convert
/// @return uint64_t, the number of cycles
///
template< fapi2::TargetType T >
inline uint64_t us_to_cycles(const fapi2::Target<T>& i_target, const uint64_t i_us)
{
    return ps_to_cycles(i_target, i_us * CONVERT_PS_IN_A_US);
}

///
/// @brief Return the number of cycles contained in a count of nanoseconds
/// @param[in] i_target, target for the frequency attribute
/// @param[in] i_ps, the number of nanoseconds to convert
/// @return uint64_t, the number of cycles
///
template< fapi2::TargetType T >
inline uint64_t ns_to_cycles(const fapi2::Target<T>& i_target, const uint64_t i_ns)
{
    return ps_to_cycles(i_target, i_ns * CONVERT_PS_IN_A_NS);
}

///
/// @brief Return the number of microseconds contained in a count of cycles
/// @tparam T, the target type
/// @tparam D, the time conversion (NS_IN_PS, etc)
/// @param[in] i_target, target for the frequency attribute
/// @param[in] i_ps, the number of cycles to convert
/// @return uint64_t, the number of microseconds
///
template< fapi2::TargetType T, uint64_t D >
inline uint64_t cycles_to_time(const fapi2::Target<T>& i_target, const uint64_t i_cycles)
{
    // Hoping the compiler figures out how to do these together.
    uint64_t l_dividend = cycles_to_ps(i_target, i_cycles);
    uint64_t l_quotient = l_dividend / D;
    uint64_t l_remainder = l_dividend % D;

    // Make sure we add time if there wasn't an even number of cycles
    return  l_quotient + (l_remainder == 0 ? 0 : 1);
}

///
/// @brief Return the number of nanoseconds contained in a count of cycles
/// @param[in] i_target, target for the frequency attribute
/// @param[in] i_cycles, the number of cycles to convert
/// @return uint64_t, the number of nanoseconds
///
template< fapi2::TargetType T >
inline uint64_t cycles_to_ns(const fapi2::Target<T>& i_target, const uint64_t i_cycles)
{
    uint64_t l_ns = cycles_to_time<T, CONVERT_PS_IN_A_NS>(i_target, i_cycles);
    FAPI_DBG("converting %d cycles to %dns", i_cycles, l_ns);

    return l_ns;
}

///
/// @brief Return the number of microseconds contained in a count of cycles
/// @param[in] i_target, target for the frequency attribute
/// @param[in] i_cycles, the number of cycles to convert
/// @return uint64_t, the number of microseconds
///
template< fapi2::TargetType T >
inline uint64_t cycles_to_us(const fapi2::Target<T>& i_target, const uint64_t i_cycles)
{
    uint64_t l_us = cycles_to_time<T, CONVERT_PS_IN_A_US>(i_target, i_cycles);
    FAPI_DBG("converting %d cycles to %dus", i_cycles, l_us);

    return l_us;
}

///
/// @brief Calculate TWLO_TWLOE - this needs to go in to eff_config and be an attribute
/// @tparam fapi2::TargetType T of the target used to calculate cycles from ns
/// @param[in] i_target, the target used to get DIMM clocks
/// @return uint64_t, TWLO_TWLOE in cycles
///
template< fapi2::TargetType T >
inline uint64_t twlo_twloe(const fapi2::Target<T>& i_target)
{
    return 12 + mss::ns_to_cycles(i_target, tWLO - tWLOE);
}

///
/// @brief Convert nanoseconds to picoseconds
/// @param[in] int64_t i_time_in_ns, time in nanoseconds
/// @return int64_t, time in picoseconds
///
inline int64_t ns_to_ps(const int64_t& i_time_in_ns)
{
    return i_time_in_ns * CONVERT_PS_IN_A_NS;
}

///
/// @brief Convert nanoseconds to picoseconds
/// @param[in] int64_t i_time_in_ps, time in picoseconds
/// @return int64_t, time in nanoseconds
///
inline int64_t ps_to_ns(const int64_t& i_time_in_ps)
{
    int64_t remainder = i_time_in_ps % CONVERT_PS_IN_A_NS;
    int64_t l_time_in_ns = i_time_in_ps / CONVERT_PS_IN_A_NS;

    // Round up if remainder isn't even
    return l_time_in_ns + ( remainder == 0 ? 0 : 1 );
}

};// mss namespace
#endif
