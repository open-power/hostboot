/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_freq.H $                */
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
/// @file p9_mss_freq.H
/// @brief Calculate and save off DIMM frequencies
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __P9_MSS_FREQ__
#define __P9_MSS_FREQ__

#include <fapi2.H>

namespace mss
{

enum constants : std::uint64_t
{
    TAA_MAX_DDR4 = 18000,
    TWO_MHZ = 2000000,
    DMI_9_6GB = 0x01,
    DMI_16_0GB = 0x02,
    LR_MIN_DDR4_CL = 7,
    LR_MAX_DDR4_CL = 36,
    HR_MIN_DDR4_CL = 23,
    HR_MAX_DDR4_CL = 52,
};

enum frequencies : std::uint64_t
{
    FREQ_2667 = 2667,
    FREQ_2400 = 2400,
    FREQ_2133 = 2133,
    FREQ_1867 = 1867,
    FREQ_1600 = 1600,
};


///
/// @brief      Calculate frequency
/// @tparam     T input
/// @param[in]  i_clock T
/// @return     T (frequency)
///
template<typename T>
inline T calc_freq(T i_clock)
{
    // Casted so compiler performs operations on equivalent data types
    T frequency = TWO_MHZ / i_clock;
    // Round-up if division leaves remainder
    frequency += ( (TWO_MHZ % i_clock) == 0 ? 0 : 1 );

    return frequency;
}

///
/// @brief  Calculate timing value (e.g.tCK, tAA, etc.)
/// @tparam     T input
/// @param[in]  i_freq T
/// @return     T (timing)
///
template<typename T>
inline T calc_clock (T i_freq)
{
    T timing = TWO_MHZ / i_freq;
    // Round-up if division leaves remainder
    timing += ( (TWO_MHZ % i_freq) == 0 ? 0 : 1 );

    return timing;
}

///
/// @brief  Calculate CAS latency
/// @tparam[in]  T
/// @param[in]   tAA_max T,tCKmax T
/// @return      T cas_latency
///
template<typename T>
inline T calc_cas_latency(T tAA_max, T tCKmax)
{
    T cas_latency = tAA_max / tCKmax;
    // Increment if division leaves remainder
    cas_latency += ( (tAA_max % tCKmax) == 0 ? 0 : 1 );

    return cas_latency;
}


}// mss namespace

typedef fapi2::ReturnCode (*p9_mss_freq_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MCS>&);

extern "C"
{

    ///
    /// @brief Calculate and save off DIMM frequencies
    /// @param[in] i_target the controller (e.g., MCS)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_freq( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target );

}

#endif
