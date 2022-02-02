/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_utils_ddr5.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
// EKB-Mirror-To: hostboot

///
/// @file spd_utils_ddr5.H
/// @brief DDR5 SPD utility functions definitions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_UTILS_DDR5_H_
#define _MSS_SPD_UTILS_DDR5_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{
namespace spd
{
namespace ddr5
{

///
/// @brief Helper function to calculate a DDR5 SPD timing in ps from the SPD
/// @param[in] i_target DIMM target
/// @param[in] i_spd the SPD binary
/// @param[in] i_start_byte the starting byte for this timing
/// @param[in] i_ffdc_codes the FFDC for this timing
/// @param[out] o_time_in_ps the amount of time in ps
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode get_timing(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const std::vector<uint8_t>& i_spd,
    const uint16_t i_start_byte,
    const uint16_t i_ffdc_codes,
    uint64_t& o_time_in_ps );

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

///
/// @brief Returns clock cycles based on input application period
/// @tparam T input type
/// @tparam OT output type
/// @param[in] i_function the calling function to log for FFDC
/// @param[in] i_timing_in_ps timing parameter in ps
/// @param[in] i_tck_in_ps  clock period in ps
/// @param[out] o_value_nck the end calculation in nck
/// @return FAPI2_RC_SUCCESS iff okay
/// @note DDR4 SPD Contents Rounding Algorithm
/// @note Item 2220.46
///
template<typename T, typename OT>
inline fapi2::ReturnCode calc_nck(const uint16_t i_function,
                                  const T& i_timing_in_ps,
                                  const T& i_tck_in_ps,
                                  OT& o_val_nck)
{
    // Aka 0.30% -> JEDEC multiplies by 1000 to keep all math using integers
    constexpr T CORRECTION_FACTOR = 3;
    constexpr T SCALING = 1000;
    constexpr T ROUNDING_FACTOR = 997;
    o_val_nck = 0;

    // Ensures that the tCK is not zero
    FAPI_ASSERT( i_tck_in_ps != 0,
                 fapi2::MSS_DIVIDE_BY_ZERO().
                 set_DIVISOR(i_timing_in_ps).
                 set_DIVIDEND(i_tck_in_ps).
                 set_FUNCTION(i_function),
                 "tCK is 0 ps. Asserting to avoid a divide by zero error");

    // The algorithm is taken from the DDR5 JEDEC SPD spec -> version 1.0 beta
    {
        const T l_initial_calc  = i_timing_in_ps * ROUNDING_FACTOR;
        const T l_corrected_nck = l_initial_calc / i_tck_in_ps;
        const T l_numerator     = l_corrected_nck + SCALING;
        const T l_result        = l_numerator / SCALING;
        o_val_nck = l_result;
        FAPI_ASSERT( i_timing_in_ps == (l_initial_calc / ROUNDING_FACTOR),
                     fapi2::MSS_INVALID_CAST_CALC_NCK().
                     set_TIMING_PS(i_timing_in_ps).
                     set_NCK_NS(i_tck_in_ps).
                     set_CORRECTION_FACTOR(CORRECTION_FACTOR).
                     set_FUNCTION(i_function),
                     "Overflow occured on intial calculation. Returned data is %d", o_val_nck);
        FAPI_ASSERT( l_numerator == (l_corrected_nck + SCALING),
                     fapi2::MSS_INVALID_CAST_CALC_NCK().
                     set_TIMING_PS(i_timing_in_ps).
                     set_NCK_NS(i_tck_in_ps).
                     set_CORRECTION_FACTOR(CORRECTION_FACTOR).
                     set_FUNCTION(i_function),
                     "Overflow occured on calculation of numerator. Returned data is %d", o_val_nck);
        FAPI_ASSERT( static_cast<T>(o_val_nck) == l_result,
                     fapi2::MSS_INVALID_CAST_CALC_NCK().
                     set_TIMING_PS(i_timing_in_ps).
                     set_NCK_NS(i_tck_in_ps).
                     set_CORRECTION_FACTOR(CORRECTION_FACTOR).
                     set_FUNCTION(i_function),
                     "Overflow occured. Returned data is %d", o_val_nck);
    }

    // If we don't assert, we don't know what's in current_err ...
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retrieves an nCK value from the SPD with byte checking
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd the SPD binary
/// @param[in] i_start_byte the starting byte for this timing
/// @param[in] i_ffdc_codes the FFDC for this timing
/// @param[out] o_time_in_nck the amount of time in nck
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Should be used for 3 byte timing values, specifcally timings from bytes 70-84
///
fapi2::ReturnCode get_nck_for_timing_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::vector<uint8_t>& i_spd,
    const uint16_t i_start_byte,
    const uint16_t i_ffdc_codes,
    uint8_t& o_time_in_nck );

///
/// @brief Retrieves an nCK value from the SPD for a timing with a lower clock limit
/// @param[in] i_dimm DIMM target
/// @param[in] i_spd the SPD binary
/// @param[in] i_start_byte the starting byte for this timing
/// @param[in] i_ffdc_codes the FFDC for this timing
/// @param[in] i_tck_in_ps the number of ps to a single clock cycle
/// @param[out] o_time_in_ps the amount of time in nck
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Should be used for 3 byte timing values, specifcally timings from bytes 70-84
///
fapi2::ReturnCode get_nck_with_lower_clock_limit(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm,
    const std::vector<uint8_t>& i_spd,
    const uint16_t i_start_byte,
    const uint16_t i_ffdc_codes,
    const uint64_t i_tck_in_ps,
    uint8_t& o_time_in_nck );

}// ddr5

}// spd

}// mss

#endif // _MSS_SPD_UTILS_DDR5_H_
