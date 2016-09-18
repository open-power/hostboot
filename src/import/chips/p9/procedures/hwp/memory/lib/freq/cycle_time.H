/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/freq/cycle_time.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include <lib/freq/sync.H>

namespace mss
{

enum FREQ_MARGIN : std::uint64_t
{
    // -5% of 1866 MT/s
    MIN_FREQ_MARGIN = 1772,

    // +5% of 2666 MT/s
    MAX_FREQ_MARGIN = 2799,
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

///
/// @brief          Selects DIMM frequency to run based on supported system frequencies
/// @tparam         T the fapi2::TargetType for which the DIMM information exists.
/// @param[in]      target from which to get the dimm information
/// @param[in,out]  io_dimm_freq input is current dimm freq & output is next
///                 lowest dimm freq between 1866 MT/s (-5% margin)  - 2666 MT/s (+5% margin)
/// @return         FAPI2_RC_SUCCESS iff ok
/// @note           Frequency values obtained from:
/// @note           From P9 User's Manual Version 0.8 - June 08, 2015
/// @note           Memory Controller Unit - page 199 of 456
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode select_supported_freq(const fapi2::Target<T>& i_target, uint64_t& io_dimm_freq)
{
    uint32_t l_min_freq = 0;
    uint32_t l_max_freq = 0;
    std::vector<uint32_t> l_freqs;

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

    FAPI_TRY( mss::supported_freqs(i_target, l_freqs) );
    l_min_freq = *(l_freqs.begin());
    l_max_freq = *(l_freqs.end() - 1);

    // Corner case to take into account -5% margin
    if(io_dimm_freq  < l_min_freq)
    {
        io_dimm_freq = l_min_freq;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Corner case to take into account +5% margin
    if(io_dimm_freq > l_max_freq)
    {
        io_dimm_freq = l_max_freq;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Selects next lowest freq btw 1866 - 2666 [MT/s]
    {
        // supported_freqs sorts so upper_bound is valid.
        auto iterator = std::upper_bound(l_freqs.begin(), l_freqs.end(), io_dimm_freq);
        io_dimm_freq = *(--iterator);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief         Determines next highest min cycle time (tCK)
/// @param[in,out] io_tCK_in_ps min cycle time in ps
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
