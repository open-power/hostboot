/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mss_buffer_utils.H $      */
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
/// @brief Helper function for insertion boilerplate
/// @tparam INPUT_BIT_LEN input bit length
/// @tparam T input type
/// @tparam OT output type
/// @param[in] i_data data to insert
/// @param[in,out] io_out buffer we wish to insert values to
/// @note inserts full integral size in bit length (e.g. uint8_t -> 8 bits, uint32_t -> 32 bits)
///
template <size_t INPUT_BIT_LEN, typename T, typename OT>
static void right_aligned_insert_helper(const T i_data, fapi2::buffer<OT>& io_out)
{
    constexpr size_t BUFFER_BIT_LEN = get_bit_length<OT>();

    constexpr size_t l_start_bit = BUFFER_BIT_LEN - INPUT_BIT_LEN;
    constexpr size_t l_len = get_bit_length<T>();

    FAPI_DBG("Total input bit length %d, output bit length %d, insert start bit %d, insert length %d, data %d",
             INPUT_BIT_LEN, BUFFER_BIT_LEN, l_start_bit, l_len, i_data);

    io_out.template insertFromRight<l_start_bit, l_len >(i_data);
}

///
/// @brief Base function to insert entire values of any integral value into a buffer
/// @tparam T input type
/// @tparam OT output type of fapi2::buffer
/// @param[in,out] io_out buffer we wish to insert values to
/// @param[in] i_input argument we want to get bit length of
/// @note inserts full integral size in bit length (e.g. uint8_t -> 8 bits, uint32_t -> 32 bits)
///
template <typename T, typename OT>
void right_aligned_insert(fapi2::buffer<OT>& io_out, const T& i_input)
{
    constexpr size_t l_input_total_args_bit_length = get_bit_length(i_input);
    right_aligned_insert_helper<l_input_total_args_bit_length>(i_input, io_out);
}

///
/// @brief Variadic function to insert entire values of any integral value into a buffer
/// @tparam T input type
/// @tparam OT output type of fapi2::buffer
/// @tparam Types input type for a list in input params
/// @param[in,out] io_out buffer we wish to insert values to
/// @param[in] i_first first argument we want to get bit length of
/// @param[in] i_args list of arguments we want to get the total bit length of
/// @note inserts full integral size in bit length (e.g. uint8_t -> 8 bits, uint32_t -> 32 bits)
/// @note params are ordered to be inserted from left to right
///
template <typename T, typename OT, typename... Types>
void right_aligned_insert(fapi2::buffer<OT>& io_out, const T& first, const Types& ... args)
{
    constexpr size_t l_input_total_args_bit_length = get_bit_length(first, args...);
    right_aligned_insert_helper<l_input_total_args_bit_length>(first, io_out);

    right_aligned_insert(io_out, args...);
}

}// mss

#endif // _MSS_BUFFER_UTILS_H_
