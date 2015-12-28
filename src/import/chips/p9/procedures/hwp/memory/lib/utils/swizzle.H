/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/swizzle.H $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file swizzle.H
/// @brief Swizzle bits
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SWIZZLE_H_
#define _MSS_SWIZZLE_H_

#include <fapi2.H>

namespace mss
{

///
/// @brief Swap two bits in a buffer
/// @tparam TB, the bit in the buffer to move to SB
/// @tparam SB, the bit in the buffer to move to TB
/// @tparam T, integral type of the buffer
/// @param[in,out] io_data, reference to the buffer
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
/// @tparam TB, the bit in the buffer to negate
/// @tparam T, integral type of the buffer
/// @param[in,out] io_data, reference to the buffer
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
/// @brief Swizzle bits between two fapi2 buffers, and insert from source to destination
/// @tparam DS, the start bit in the destination buffer - swizzle will count up from here
/// @tparam L, how many bits to swizzle
/// @tparam SS, the start bit in the source buffer - swizzle will count down from here
/// @param[in] source buffer - these bits will be decremented
/// @param[in] destination buffer - these bits will be incremented
/// @return reference to the destination
///
template<uint64_t DS, uint64_t L, uint64_t SS, typename SB, typename DB>
inline fapi2::buffer<DB>& swizzle( fapi2::buffer<SB> i_source, fapi2::buffer<DB>& o_destination )
{
    // Reverse the destination, and then mangle the start bits to get things to line up
    fapi2::buffer<SB> l_tmp(i_source);
    reverse(i_source);

#ifdef SWIZZLE_TRACE
    FAPI_DBG("swizzle o: 0x%0X s: 0x%X d: 0x%llX ds: %d l: %d ss: %d",
             l_tmp, i_source, o_destination, DS, L, (sizeof(SB) * 8) - (SS + 1));
#endif

    return o_destination.template insert < DS, L, (sizeof(SB) * 8) - (SS + 1) > (SB(i_source));
}

}
#endif
