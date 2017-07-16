/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mss_math.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MATH_H_
#define _MSS_MATH_H_

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
/// @brief Poor man's round half away from 0
/// @param[in] i_input starting point
/// @return rounded int64_t value
/// @note HB doesn't have std::round, referenced from:
/// https://stackoverflow.com/questions/4572556/concise-way-to-implement-round-in-c
///
inline int64_t round_half_away_from_zero( const double i_input )
{
    // Casting to avoid comparison of diff data types
    // Explicitly casting INT64_MAX to avoid truncation of casting
    // floating point to integer
    if( i_input > static_cast<double>(INT64_MAX) )
    {
        FAPI_ERR("Invalid input greater than %d", INT64_MAX);
        fapi2::Assert(false);
    }

    return ( i_input < 0.0 ? static_cast<int64_t>(i_input - 0.5) :  static_cast<int64_t>(i_input + 0.5) );
}


}// mss

#endif
