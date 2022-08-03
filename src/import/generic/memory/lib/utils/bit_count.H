/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/bit_count.H $             */
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
/// @file bit_count.H
/// @brief count bits
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_BIT_COUNT_H_
#define _MSS_BIT_COUNT_H_

#include <fapi2.H>

namespace mss
{

///
/// @brief Count the bits in a T which are set (1)
/// @tparam T an integral type. e.g., uint64_t, uint8_t
/// @param[in] i_value the value to check, count
/// @return uint64_t the number of bits set in the input
///
template< typename T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
inline uint64_t bit_count(const T& i_value)
{
    if (i_value == 0)
    {
        return 0;
    }
    else
    {
        return bit_count(i_value >> 1) + (i_value & 0x01);
    }
}

///
/// @brief Count the bits in a subset of a fapi2::buffer
/// @tparam S the starting bit location in the buffer
/// @tparam T an integral type. e.g., uint64_t, uint8_t
/// @param[in] i_buffer, the buffer from which to count bits
/// @return uint64_t the number of bits set in the input
///
template< uint64_t S, typename T >
inline uint64_t bit_count(const fapi2::buffer<T>& i_buffer)
{
    // If the bit is set, return 1, otherwise 0
    return i_buffer.template getBit<S>() ? 1 : 0;
}

///
/// @brief Count the bits in a subset of a fapi2::buffer
/// @tparam S the starting bit location in the buffer
/// @tparam L the length of the bits to check in the buffer
/// @tparam T an integral type. e.g., uint64_t, uint8_t
/// @param[in] i_buffer, the buffer from which to count bits
/// @return uint64_t the number of bits set in the input
///
template< uint64_t S, uint64_t L, typename T >
inline uint64_t bit_count(const fapi2::buffer<T>& i_buffer)
{
    T l_temp = 0;
    i_buffer. template extractToRight<S, L>(l_temp);
    return bit_count(l_temp);
}

///
/// @brief Return the bit position of the first bit set, from the left
/// @tparam T, an integral type. e.g., uint64_t, uint8_t
/// @param[in] i_value the value to check
/// @return uint64_t the bit position of the first set bit
/// @bote assumes you checked to make sure there were bits set because it will return 0
///
template< typename T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
inline uint64_t first_bit_set(const T& i_value, const uint64_t i_pos = 0)
{
    if (i_value == 0)
    {
        return 0;
    }

    if (fapi2::buffer<T>(i_value).template getBit(i_pos))
    {
        return i_pos;
    }
    else
    {
        return first_bit_set(i_value, i_pos + 1);
    }
}

}
#endif
