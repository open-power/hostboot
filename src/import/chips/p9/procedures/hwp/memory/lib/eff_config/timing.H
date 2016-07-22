/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/timing.H $ */
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
/// @file timing.H
/// @brief Determine effective config for mss settings
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_TIMING_H_
#define _MSS_TIMING_H_

#include <cstdint>
#include <fapi2.H>

namespace mss
{

enum GUARD_BAND : size_t
{
    // Used for caclulating spd timing values - from JEDEC rounding algorithm
    // Correction factor is 1% (for DDR3) or 2.5% (for DDR4)
    // when doing integer math, we add-in the inverse correction factor
    // Formula used for derivation:
    // Guardband = 1000 * (1000* correction_factor) - 1
    INVERSE_DDR3_CORRECTION_FACTOR = 989,
    INVERSE_DDR4_CORRECTION_FACTOR = 974,
};

enum class refresh_rate : uint8_t
{
    REF1X = 1,
    REF2X = 2,
    REF4X = 4,
};

enum temp_mode : uint8_t
{
    NORMAL = 1,
    EXTENDED = 2,
};

///
/// @brief Calculates timing value
/// @param[in] i_timing_mtb timing value in MTB units
/// @param[in] i_mtb_multiplier SPD medium timebase
/// @param[in] i_timing_ftb fine offset of timing value
/// @param[in] i_ftb_multiplier SPD fine timebase
/// @return the timing value in picoseconds
///
inline int64_t calc_timing_from_timebase(const int64_t i_timing_mtb,
        const int64_t i_mtb_multiplier,
        const int64_t i_timing_ftb,
        const int64_t i_ftb_multiplier)
{
    // JEDEC algorithm
    const int64_t l_timing_val = i_timing_mtb * i_mtb_multiplier;
    const int64_t l_fine_offset = i_timing_ftb * i_ftb_multiplier;

    return l_timing_val + l_fine_offset;
}

///
/// @brief Returns clock cycles
/// @tparam T input and output type
/// @param[in] timing_in_ps timing parameter in ps
/// @param[in] tck_in_ps  clock period in ps
/// @param[in] inverse_corr_factor inverse correction factor  (defined by JEDEC)
/// @return the clock cycles of timing parameter (provided in ps)
/// @note DDR4 SPD Contents Rounding Algorithm
/// @note Item 2220.46
///
template<typename T>
inline T calc_nck(const T i_timing_in_ps,
                  const T i_tck_in_ps,
                  const T i_inverse_corr_factor)
{
    // Preliminary nCK calculation, scaled by 1000 per JDEC algorithm
    T l_temp_nck = (i_timing_in_ps * 1000) / (i_tck_in_ps == 0 ? 1 : i_tck_in_ps);

    // Apply inverse of correction factor percentage
    l_temp_nck += i_inverse_corr_factor;

    return l_temp_nck / 1000;
}

///
/// @brief Returns application clock period (tCK) based on dimm transfer rate
/// @tparam T the fapi2 target
/// @tparam OT output type
/// @param[in] i_target FAPI2 target
/// @param[out] o_tCK_in_ps application period in ps
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
template<fapi2::TargetType T, typename OT>
inline fapi2::ReturnCode clock_period(const fapi2::Target<T>& i_target,
                                      OT& o_tCK_in_ps)
{
    uint64_t l_dimm_transfer_rate = 0;
    FAPI_TRY( freq(find_target<fapi2::TARGET_TYPE_MCBIST>(i_target), l_dimm_transfer_rate) );

    FAPI_TRY( freq_to_ps(l_dimm_transfer_rate, o_tCK_in_ps) );

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Calculates refresh interval time
/// @param[in] i_mode fine refresh rate mode
/// @param[in] i_temp_refresh_range temperature refresh range
/// @param[out] o_value timing val in ps
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode calc_trefi( const refresh_rate i_mode,
                              const uint8_t i_temp_refresh_range,
                              uint64_t& o_timing );
} // mss

#endif
