/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_utils.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file spd_utls.H
/// @brief SPD utility functions definitions
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_UTILS_H_
#define _MSS_SPD_UTILS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{
namespace spd
{

///
/// @brief Calculates timing value
/// @param[in] i_timing_mtb timing value in MTB units
/// @param[in] i_mtb_multiplier SPD medium timebase
/// @param[in] i_timing_ftb fine offset of timing value
/// @param[in] i_ftb_multiplier SPD fine timebase
/// @return the timing value in picoseconds
///
inline int32_t calc_timing_from_timebase(
    const int32_t i_timing_mtb,
    const int32_t i_mtb_multiplier,
    const int32_t i_timing_ftb,
    const int32_t i_ftb_multiplier)
{
    // JEDEC algorithm
    const int32_t l_timing_val = i_timing_mtb * i_mtb_multiplier;
    const int32_t l_fine_offset = i_timing_ftb * i_ftb_multiplier;

    return l_timing_val + l_fine_offset;
}

///
/// @brief Helper to compute JEDEC's SPD rounding algorithm
/// to convert ps to nCK
/// @tparam T input type
/// @tparam OT output type
/// @param[in] i_timing_in_ps timing parameter in ps
/// @param[in] i_tck_in_ps  clock period in ps
/// @param[in] i_inverse_corr_factor inverse correction factor (defined by JEDEC)
/// @param[out] o_value_nck the end calculation in nck
/// @return true if overflow didn't occur, false otherwise
/// @note DDR4 SPD Contents Rounding Algorithm
/// @note Item 2220.46
///
template<typename T, typename OT>
static inline bool jedec_spd_rounding_alg(const T& i_timing_in_ps,
        const T& i_tck_in_ps,
        const guard_band i_inverse_corr_factor,
        OT& o_val_nck)
{
    o_val_nck = 0;

    // Preliminary nCK calculation, scaled by 1000 per JDEC algorithm
    T l_temp_nck = (i_timing_in_ps * mss::CONVERT_PS_IN_A_NS);

    // Checks for an overflow
    if((l_temp_nck / mss::CONVERT_PS_IN_A_NS) != i_timing_in_ps)
    {
        FAPI_ERR("Found an overflow on the intial timing calculation! %u * %u != %u",
                 i_timing_in_ps, mss::CONVERT_PS_IN_A_NS, l_temp_nck);
        return false;
    }

    l_temp_nck = l_temp_nck / (i_tck_in_ps == 0 ? 1 : i_tck_in_ps);
    l_temp_nck += i_inverse_corr_factor;
    l_temp_nck = l_temp_nck / mss::CONVERT_PS_IN_A_NS;

    // Check for overflow
    // static_cast needed for HB compiler that complains about
    // comparision of two different integral types
    o_val_nck = l_temp_nck;

    FAPI_DBG("Input timing (ps) %d, tCK (ps) %d, temp output %d, output (nCK) %d",
             i_timing_in_ps, i_tck_in_ps, l_temp_nck, o_val_nck);

    return (static_cast<T>(o_val_nck) == l_temp_nck);
}

///
/// @brief Returns clock cycles based on input application period
/// @tparam T input type
/// @tparam OT output type
/// @param[in] i_function the calling function to log for FFDC
/// @param[in] i_timing_in_ps timing parameter in ps
/// @param[in] i_tck_in_ps  clock period in ps
/// @param[in] i_inverse_corr_factor inverse correction factor  (defined by JEDEC)
/// @param[out] o_value_nck the end calculation in nck
/// @return FAPI2_RC_SUCCESS iff okay
/// @note DDR4 SPD Contents Rounding Algorithm
/// @note Item 2220.46
///
template<typename T, typename OT>
inline fapi2::ReturnCode calc_nck(const uint16_t i_function,
                                  const T& i_timing_in_ps,
                                  const T& i_tck_in_ps,
                                  const guard_band i_inverse_corr_factor,
                                  OT& o_val_nck)
{
    FAPI_ASSERT( jedec_spd_rounding_alg(i_timing_in_ps,
                                        i_tck_in_ps,
                                        i_inverse_corr_factor,
                                        o_val_nck),
                 fapi2::MSS_INVALID_CAST_CALC_NCK().
                 set_TIMING_PS(i_timing_in_ps).
                 set_NCK_NS(i_tck_in_ps).
                 set_CORRECTION_FACTOR(i_inverse_corr_factor).
                 set_FUNCTION(i_function),
                 "Overflow occured. Returned data is %d", o_val_nck);

    // If we don't assert, we don't know what's in current_err ...
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to retrieves medium and fine timebase values
/// @param[in] i_ocmb OCMB target
/// @param[in] i_spd the SPD binary
/// @param[out] o_mtb the medium timebase (MTB) from SPD
/// @param[out] o_ftb the fine timebase (FTB) from SPD
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode get_timebases(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
    const std::vector<uint8_t>& i_spd,
    uint8_t& o_mtb,
    uint8_t& o_ftb );

///
/// @brief Retrieves SDRAM Minimum Cycle Time (tCKmin) from SPD
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd SPD binary
/// @param[out] o_value tCKmin value in ps
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode get_tckmin(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::vector<uint8_t>& i_spd,
    uint64_t& o_value);

///
/// @brief Retrieves SDRAM Maximum Cycle Time (tCKmax) from SPD
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd SPD binary
/// @param[out] o_value tCKmax value in ps
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode get_tckmax(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::vector<uint8_t>& i_spd,
    uint64_t& o_value);

}// spd

}// mss

#endif // _MSS_SPD_UTILS_H_
