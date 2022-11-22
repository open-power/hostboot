/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mss_buffer_utils.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
/// @file mss_buffer_utils.H
/// @brief Buffer utility functions
///

// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_BUFFER_UTILS_H_
#define _MSS_BUFFER_UTILS_H_

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_generic_check.H>

namespace mss
{

///
/// @brief Helper function to find bit length of an integral type
/// @tparam T integral type
/// @return bit length for given integral type
///
template < typename T >
constexpr size_t get_bit_length()
{
    return sizeof(T) * BITS_PER_BYTE;
}

///
/// @brief Helper function to find bit length of an input param
/// @tparam T input type
/// @param[in] i_input argument we want to get bit length of
/// @return bit length for given input
///
template < typename T >
constexpr size_t get_bit_length(const T& i_input)
{
    return sizeof(T) * BITS_PER_BYTE;
}

///
/// @brief Variadic helper function to find bit length of integral types
/// @tparam T input type
/// @tparam Types input type for a list in input params
/// @param[in] i_first first argument we want to get bit length of
/// @param[in] i_args list of arguments we want to get the total bit length of
/// @return total bit length for given input
//
template < typename T, typename... Types >
constexpr size_t get_bit_length (const T& i_first, const Types& ... i_args)
{
    // Recursive-ish pattern to add up bit length of passed in params
    return get_bit_length(i_first) + get_bit_length(i_args...);
}

///
/// @brief Base function to insert entire values of any integral value into a buffer uint16 buffer with 2 uint8 numbers
/// @param[out] o_out buffer we wish to insert values to
/// @param[in] i_input1
/// @param[in] i_input0
/// @note inserts full integral size in bit length (e.g. uint8_t -> 8 bits, uint32_t -> 32 bits)
///
inline void right_aligned_insert(fapi2::buffer<uint16_t>& o_out, const uint8_t i_input1, const uint8_t i_input0)
{
    constexpr size_t INPUT_BIT_SIZE = 8;

    o_out = 0;

    o_out.insertFromRight<0, INPUT_BIT_SIZE>(i_input1)
    .insertFromRight<INPUT_BIT_SIZE, INPUT_BIT_SIZE>(i_input0);
}

///
/// @brief Base function to insert entire values of any integral value into a buffer int64 buffer with 2 uint8 numbers
/// @param[out] o_out buffer we wish to insert values to
/// @param[in] i_input1
/// @param[in] i_input0
/// @note inserts full integral size in bit length (e.g. uint8_t -> 8 bits, uint32_t -> 32 bits)
///
inline void right_aligned_insert(fapi2::buffer<int64_t>& o_out, const uint8_t i_input1, const uint8_t i_input0)
{
    constexpr size_t INPUT_BIT_SIZE = 8;
    constexpr size_t BUFFER_BIT_SIZE = 64;
    constexpr size_t INPUT0_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 1);
    constexpr size_t INPUT1_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 2);

    o_out = 0;

    o_out.insertFromRight<INPUT1_POS, INPUT_BIT_SIZE>(i_input1)
    .insertFromRight<INPUT0_POS, INPUT_BIT_SIZE>(i_input0);
}

///
/// @brief Base function to insert entire values of any integral value into a buffer uint64 buffer with 4 uint8 numbers
/// @param[out] o_out buffer we wish to insert values to
/// @param[in] i_input3
/// @param[in] i_input2
/// @param[in] i_input1
/// @param[in] i_input0
/// @note inserts full integral size in bit length (e.g. uint8_t -> 8 bits, uint32_t -> 32 bits)
///
inline void right_aligned_insert(fapi2::buffer<uint64_t>& o_out, const uint8_t i_input3, const uint8_t i_input2,
                                 const uint8_t i_input1, const uint8_t i_input0)
{
    constexpr size_t INPUT_BIT_SIZE = 8;
    constexpr size_t BUFFER_BIT_SIZE = 64;
    constexpr size_t INPUT0_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 1);
    constexpr size_t INPUT1_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 2);
    constexpr size_t INPUT2_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 3);
    constexpr size_t INPUT3_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 4);

    o_out = 0;

    o_out.insertFromRight<INPUT3_POS, INPUT_BIT_SIZE>(i_input3)
    .insertFromRight<INPUT2_POS, INPUT_BIT_SIZE>(i_input2)
    .insertFromRight<INPUT1_POS, INPUT_BIT_SIZE>(i_input1)
    .insertFromRight<INPUT0_POS, INPUT_BIT_SIZE>(i_input0);
}

///
/// @brief Base function to insert entire values of any integral value into a buffer uint64 buffer with 5 uint8 numbers
/// @param[out] o_out buffer we wish to insert values to
/// @param[in] i_input4
/// @param[in] i_input3
/// @param[in] i_input2
/// @param[in] i_input1
/// @param[in] i_input0
/// @note inserts full integral size in bit length (e.g. uint8_t -> 8 bits, uint32_t -> 32 bits)
///
inline void right_aligned_insert(fapi2::buffer<uint64_t>& o_out, const uint8_t i_input4, const uint8_t i_input3,
                                 const uint8_t i_input2, const uint8_t i_input1, const uint8_t i_input0)
{
    constexpr size_t INPUT_BIT_SIZE = 8;
    constexpr size_t BUFFER_BIT_SIZE = 64;
    constexpr size_t INPUT0_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 1);
    constexpr size_t INPUT1_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 2);
    constexpr size_t INPUT2_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 3);
    constexpr size_t INPUT3_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 4);
    constexpr size_t INPUT4_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 5);

    o_out = 0;

    o_out.insertFromRight<INPUT4_POS, INPUT_BIT_SIZE>(i_input4)
    .insertFromRight<INPUT3_POS, INPUT_BIT_SIZE>(i_input3)
    .insertFromRight<INPUT2_POS, INPUT_BIT_SIZE>(i_input2)
    .insertFromRight<INPUT1_POS, INPUT_BIT_SIZE>(i_input1)
    .insertFromRight<INPUT0_POS, INPUT_BIT_SIZE>(i_input0);
}

///
/// @brief Base function to insert entire values of any integral value into a buffer uint64 buffer with 4 uint16 numbers
/// @param[out] o_out buffer we wish to insert values to
/// @param[in] i_input3
/// @param[in] i_input2
/// @param[in] i_input1
/// @param[in] i_input0
/// @note inserts full integral size in bit length (e.g. uint8_t -> 8 bits, uint32_t -> 32 bits)
///
inline void right_aligned_insert(fapi2::buffer<uint64_t>& o_out, const uint16_t i_input3, const uint16_t i_input2,
                                 const uint16_t i_input1, const uint16_t i_input0)
{
    constexpr size_t INPUT_BIT_SIZE = 16;
    constexpr size_t BUFFER_BIT_SIZE = 64;
    constexpr size_t INPUT0_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 1);
    constexpr size_t INPUT1_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 2);
    constexpr size_t INPUT2_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 3);
    constexpr size_t INPUT3_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 4);

    o_out = 0;

    o_out.insertFromRight<INPUT3_POS, INPUT_BIT_SIZE>(i_input3)
    .insertFromRight<INPUT2_POS, INPUT_BIT_SIZE>(i_input2)
    .insertFromRight<INPUT1_POS, INPUT_BIT_SIZE>(i_input1)
    .insertFromRight<INPUT0_POS, INPUT_BIT_SIZE>(i_input0);
}

///
/// @brief Base function to insert entire values of any integral value into a buffer uint32 buffer with 4 uint8 numbers
/// @param[out] o_out buffer we wish to insert values to
/// @param[in] i_input3
/// @param[in] i_input2
/// @param[in] i_input1
/// @param[in] i_input0
/// @note inserts full integral size in bit length (e.g. uint8_t -> 8 bits, uint32_t -> 32 bits)
///
inline void right_aligned_insert(fapi2::buffer<uint32_t>& o_out, const uint8_t i_input3, const uint8_t i_input2,
                                 const uint8_t i_input1, const uint8_t i_input0)
{
    constexpr size_t INPUT_BIT_SIZE = 8;
    constexpr size_t BUFFER_BIT_SIZE = 32;
    constexpr size_t INPUT0_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 1);
    constexpr size_t INPUT1_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 2);
    constexpr size_t INPUT2_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 3);
    constexpr size_t INPUT3_POS = BUFFER_BIT_SIZE - (INPUT_BIT_SIZE * 4);

    o_out = 0;

    o_out.insertFromRight<INPUT3_POS, INPUT_BIT_SIZE>(i_input3)
    .insertFromRight<INPUT2_POS, INPUT_BIT_SIZE>(i_input2)
    .insertFromRight<INPUT1_POS, INPUT_BIT_SIZE>(i_input1)
    .insertFromRight<INPUT0_POS, INPUT_BIT_SIZE>(i_input0);
}

}// mss

#endif // _MSS_BUFFER_UTILS_H_
