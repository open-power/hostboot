/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mss_math.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MATH_H_
#define _MSS_MATH_H_

#include <fapi2.H>
#include <cstdint>

namespace mss
{
///
/// @brief Calculates inclusive range
/// @tparam T input and output type
/// @param[in] i_start starting point
/// @param[in] i_end ending point
/// @return inclusive range calculation
///
// TODO RTC:174277 - create unit test structure for generic/memory
template<typename T >
inline constexpr T inclusive_range( const T i_start, const T i_end )
{
    return (i_end - i_start) + 1;
}


///
/// @brief Divide and round unsigned values
/// @tparam T input and output types
/// @param[in] i_divisor the divisor (number to be divided)
/// @param[in] i_dividend the dividend (number to divide by)
/// @param[in] i_function the calling function
/// @param[out] o_quotient the quotient
/// @return FAPI2_RC_SUCCESS iff successful
///
template<typename T>
inline fapi2::ReturnCode divide_and_round( const T i_divisor,
        const T i_dividend,
        const uint16_t i_function,
        T& o_quotient )
{
    o_quotient = 0;

    // Zero dividend would cause a divide-by-zero, so prevent that
    FAPI_ASSERT( (i_dividend != 0),
                 fapi2::MSS_DIVIDE_BY_ZERO()
                 .set_DIVISOR(i_divisor)
                 .set_DIVIDEND(i_dividend)
                 .set_FUNCTION(i_function),
                 "Caught an attempt to divide by zero (%d / %d)",
                 i_divisor, i_dividend );

    {
        const auto l_quotient_unrounded = i_divisor / i_dividend;
        const auto l_remainder = i_divisor % i_dividend;

        // Round the quotient up or down depending on the remainder
        o_quotient = l_quotient_unrounded + ((l_remainder >= i_dividend / 2) ? 1 : 0);
    }
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Round value to a multiple of another number
///
/// @param[in] i_value value to round
/// @param[in] i_multiple multiple to round to
/// @return uint64_t rounded value
///
inline uint32_t round_to_nearest_multiple(const uint32_t i_value, const uint32_t i_multiple)
{
    return ((i_value + i_multiple / 2) / i_multiple) * i_multiple;
}

///
/// @brief Determines if the double has decimal digits and adds 1 and rounds if true
/// @param[in] i_val the double to be rounded up if trialing digits
/// @return the input value rounded up to the next whole digit
/// @note Called in p9_mss_bulk_pwr_throttles
///
inline uint32_t round_up(const double i_val)
{
    //convert to uint to truncate decimals and convert back to double for comparison
    uint32_t temp = uint32_t (i_val);

    //if not equal, lost something from truncating, so add 1
    temp += (temp == i_val) ? 0 : 1;

    //Truncate final value
    return temp;
}

}// mss

#endif
