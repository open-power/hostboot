/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/buffer_ops.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file buffer_ops.H
/// @brief Buffer operations
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _BUFFER_OPS_H_
#define _BUFFER_OPS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>

namespace mss
{

///
/// @brief Swap two bits in a buffer
/// @tparam TB the bit in the buffer to move to SB
/// @tparam SB the bit in the buffer to move to TB
/// @tparam T integral type of the buffer
/// @param[in,out] i_data reference to the buffer
/// @return reference to the input buffer (for chaining)
///
template< uint64_t TB, uint64_t SB, typename T >
inline fapi2::buffer<T>& swap( fapi2::buffer<T>& i_data )
{
    bool l_tb = i_data.template getBit<TB>();
    i_data.template writeBit<TB>(i_data.template getBit<SB>());
    i_data.template writeBit<SB>(l_tb);

    return i_data;
}

///
/// @brief Invert (negate) one bit in a buffer
/// @tparam TB the bit in the buffer to negate
/// @tparam T integral type of the buffer
/// @param[in,out] io_data reference to the buffer
/// @return reference to the input buffer (for chaining)
///
template< uint64_t TB, typename T >
inline fapi2::buffer<T>& negate( fapi2::buffer<T>& i_data )
{
    // Use care when writeBit'ing a getBit as getBit returns a bool and writeBit
    // checks if the input != 0. Negating it (~ getBit) was causing havok. So
    // we do this - note the negation of the conditional to get the reverse.
    i_data.template writeBit<TB>(i_data.template getBit<TB>() == true ? 0 : 1);
    return i_data;
}

///
/// @brief Reverse the buffer
/// @param[in,out] io_buffer the buffer which to reverse
//
//  @note from
//   http://stackoverflow.com/questions/746171/best-algorithm-for-bit-reversal-from-msb-lsb-to-lsb-msb-in-c
///
template< typename T >
static inline void reverse( T& io_buffer )
{
    T l_result = io_buffer;
    size_t l_s = sizeof(T) * 8 - 1;

    for( io_buffer >>= 1; io_buffer; io_buffer >>= 1)
    {
        l_result <<= 1;
        l_result |= io_buffer & 1;
        l_s--;
    }

    l_result <<= l_s;

    io_buffer = l_result;
}

///
/// @brief Reverse a given bit range of a buffer
/// @tparam S start bit
/// @tparam L length of bits to reverse
/// @tparam T buffer type
/// @param[in] io_buffer
///
template<uint64_t S, uint64_t L, typename T>
static inline void reverse_range(fapi2::buffer<T>& io_buffer)
{
    const auto target_length = fapi2::parameterTraits<T>::bit_length();

    static_assert(S < target_length,
                  "reverse_range(): Start is out of bounds");

    static_assert((S + L) <= target_length,
                  "reverse_range(): (Start + Len) is out of bounds");

    fapi2::buffer<T> l_tmp;

    io_buffer.template extractToRight<S, L>(l_tmp);

    l_tmp.reverse();
    io_buffer.template insert<S, L>(l_tmp);
}

///
/// @brief Swizzle bits between two fapi2 buffers, and insert from source to destination
/// @tparam DS the start bit in the destination buffer - swizzle will count up from here
/// @tparam L how many bits to swizzle
/// @tparam SS the start bit in the source buffer - swizzle will count down from here
/// @tparam SB source buffer type
/// @tparam DB destination buffer type
/// @param[in] i_source  source buffer - these bits will be decremented
/// @param[in,out] io_destination destination buffer - these bits will be incremented
/// @return reference to the destination
///
template<uint64_t DS, uint64_t L, uint64_t SS, typename SB, typename DB>
inline fapi2::buffer<DB>& swizzle( const fapi2::buffer<SB>& i_source, fapi2::buffer<DB>& io_destination )
{
    // Steps for the swizzle
    // 1) Reverse the destination buffer
    // 2) compute the source buffer start

    // 1) Reverse the destination buffer
    fapi2::buffer<SB> l_tmp(i_source);
    reverse(l_tmp);

    // 2) compute the source buffer start
    // For the swizzle, we need to know where the source buffer's data starts at
    // The data is right justified, so we want to get the data's length and subtract out the whole data length
    // We subtract out an additonal 1 to account for bits being from 0 to N-1
    constexpr auto l_source_data_start = get_bit_length<SB>() - (SS + 1);
    io_destination.template insert < DS, L, l_source_data_start > (SB(l_tmp));

#ifdef SWIZZLE_TRACE
    // s: source, r: reverse, d: destination, ds: distination start, l: length, ss: source start
    FAPI_DBG("swizzle s: 0x%016llx, r: 0x%016llx, d: 0x%016llx, ds: %d, l: %d, ss: %d",
             i_source, l_tmp, io_destination, DS, L, l_source_data_start);
#endif

    return io_destination;
}

///
/// @brief Swizzle bits between two fapi2 buffers, and insert from source to destination
/// @tparam SB source buffer type
/// @tparam DB destination buffer type
/// @tparam i_destination_start the start bit in the destination buffer - swizzle will count up from here
/// @tparam i_length how many bits to swizzle
/// @tparam i_source_start the start bit in the source buffer - swizzle will count down from here
/// @param[in] i_source  source buffer - these bits will be decremented
/// @param[in,out] io_destination destination buffer - these bits will be incremented
/// @return fapi2::ReturnCode SUCCESS iff the code is successful
///
template<typename SB, typename DB>
inline fapi2::ReturnCode swizzle( const uint64_t i_destination_start,
                                  const uint64_t i_length,
                                  const uint64_t i_source_start,
                                  const fapi2::buffer<SB>& i_source,
                                  fapi2::buffer<DB>& io_destination )
{
    // Steps for the swizzle
    // 1) Reverse the destination buffer
    // 2) compute the source buffer start

    // 1) Reverse the destination buffer
    fapi2::buffer<SB> l_tmp(i_source);
    reverse(l_tmp);

    // 2) compute the source buffer start
    // For the swizzle, we need to know where the source buffer's data starts at
    // The data is right justified, so we want to get the data's length and subtract out the whole data length
    // We subtract out an additonal 1 to account for bits being from 0 to N-1
    const auto l_source_data_start = get_bit_length<SB>() - (i_source_start + 1);
    return io_destination.insert(SB(l_tmp), i_destination_start, i_length, l_source_data_start);
}

} // ns mss

#endif
