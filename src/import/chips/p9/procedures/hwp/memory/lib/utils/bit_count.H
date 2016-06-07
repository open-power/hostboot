/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/bit_count.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file bit_count.H
/// @brief count bits
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
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

    if (fapi2::buffer<T>(i_value).template getBit<0>())
    {
        return i_pos;
    }
    else
    {
        return first_bit_set(i_value << 1, i_pos + 1);
    }
}

}
#endif
