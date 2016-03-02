/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/freq/cycle_time.H $        */
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
/// @file cycle_time.H
/// @brief cycle time (tCK) data & functions needed for CAS latency algorithm
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CYCLE_TIME_H_
#define _MSS_CYCLE_TIME_H_

#include <fapi2.H>
#include <memory>

namespace mss
{

enum FREQ_LIMITS
{
    // Can't add these limits in xml because
    // Cronus won't know what ENUM to print out
    // if there are two enums for the same value.
    MAX_SUPPORTED_FREQ = fapi2::ENUM_ATTR_MSS_FREQ_MT2666,
    MIN_SUPPORTED_FREQ = fapi2::ENUM_ATTR_MSS_FREQ_MT1866
};

enum FREQ_MARGIN : std::uint64_t
{
    // -5% of 1866 MT/s
    MIN_FREQ_MARGIN = 1772,

    // +5% of 2666 MT/s
    MAX_FREQ_MARGIN = 2799,
};

static const std::vector<uint64_t> P9_FREQS
{
    // P9 supported frequencies in addition to
    // TK - How make sure thes vector is always updated if enums are changed?
    fapi2::ENUM_ATTR_MSS_FREQ_MT1866,
    fapi2::ENUM_ATTR_MSS_FREQ_MT2133,
    fapi2::ENUM_ATTR_MSS_FREQ_MT2400,
    fapi2::ENUM_ATTR_MSS_FREQ_MT2666,
};


// Proposed DDR4 Full spec update(79-4A)
// Item No. 1716.78C
// Page 217
// 10.1 Item No. 1716.78C
// Speed Bin Table Note
static const std::vector<uint64_t> tckmin_avg_ddr4
{

    // Timing in picoseconds | Application bin speed
    750,  // 2666 MT/s
    833,  // 2400 MT/s
    937,  // 2133 MT/s
    1071, // 1866 MT/s
    /* 1250, // 1600 MT/s - don't think we support this one - AAM */
};

/// @brief          Selects DIMM frequency to run based on supported system frequencies
/// @param[in,out]  io_dimm_freq input is current dimm freq & output is next
///                 lowest dimm freq between 1866 MT/s (-5% margin)  - 2666 MT/s (+5% margin)
/// @return         FAPI2_RC_SUCCESS iff ok
/// @note           Frequency values obtained from:
/// @note           From P9 User's Manual Version 0.8 - June 08, 2015
/// @note           Memory Controller Unit - page 199 of 456
///
inline fapi2::ReturnCode select_supported_freq(uint64_t& io_dimm_freq)
{
    //TK - This 5% margin was done in P8, continue for P9 ?? - AAMARIN

    // Speed bins for P9 DDR4 are 1866 MT/s -  2666 MT/s
    // Giving -5% margin for 1866 MT/s and +5% margin for 2666 MT/s
    // Error out if frequency is beyond these margins
    FAPI_ASSERT( (io_dimm_freq > MIN_FREQ_MARGIN) &&
                 (io_dimm_freq < MAX_FREQ_MARGIN),
                 fapi2::MSS_UNSUPPORTED_FREQ_CALCULATED().
                 set_DIMM_MIN_FREQ(io_dimm_freq),
                 "Unsupported frequency: %d.  DIMM Freq calculated is < 1773 or > 2799 MT/s",
                 io_dimm_freq);

    // Corner case to take into account -5% margin
    if(io_dimm_freq  < MIN_SUPPORTED_FREQ)
    {
        io_dimm_freq = MIN_SUPPORTED_FREQ;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Corner case to take into account +5% margin
    if(io_dimm_freq > MAX_SUPPORTED_FREQ)
    {
        io_dimm_freq = MAX_SUPPORTED_FREQ;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Selects next lowest freq btw 1866 - 2666 [MT/s]
    {
        auto iterator = std::lower_bound(P9_FREQS.begin(), P9_FREQS.end(), io_dimm_freq);
        io_dimm_freq = *(--iterator);
    }
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief         Determines next highest min cycle time (tCK)
/// @param[in,out] io_tCKmin_in_ps min cycle time in ps
/// @return        fapi2::FAPI2_RC_SUCCESS if ok
///
inline fapi2::ReturnCode select_higher_tck(uint64_t& io_tCK)
{
    auto iterator = std::upper_bound(tckmin_avg_ddr4.begin(),
                                     tckmin_avg_ddr4.end(),
                                     io_tCK);

    // Did we find a greater than value?
    FAPI_ASSERT(iterator != tckmin_avg_ddr4.end(),
                fapi2::MSS_REACHED_HIGHEST_TCK().
                set_TCK(io_tCK),
                "Reached highest valid tCK");

fapi_try_exit:
    return fapi2::current_err;
}


}// mss

#endif
