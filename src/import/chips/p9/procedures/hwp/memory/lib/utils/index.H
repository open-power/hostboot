/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/index.H $            */
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
/// @file index.H
/// @brief Tools to return attribute array index from a fapi2 target
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_INDEX_H_
#define _MSS_INDEX_H_

#include <fapi2.H>

#include <lib/utils/pos.H>
#include <lib/shared/mss_const.H>

namespace mss
{
///
/// @brief Return an attribute array index from a fapi2 target
/// @tparam T the fapi2::TargetType
/// @param[in] i_target a DIMM target representing the DIMM in question
/// @return size_t the attribute array index.
///
template< fapi2::TargetType T >
inline size_t index(const fapi2::Target<T>& i_target);

template<>
inline size_t index(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    return mss::pos(i_target) % MAX_DIMM_PER_PORT;
}

template<>
inline size_t index(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    return mss::pos(i_target) % PORTS_PER_MCS;
}

///
/// @brief Return an attribute array index from a rank number
/// @param[in] i_rank uint64_t a rank number DIMM0 {0, 1, 2, 3} DIMM1 {0, 1, 2, 3}
/// @return size_t the attribute array index.
///
inline size_t index(const uint64_t i_rank)
{
    return i_rank % RANK_MID_POINT;
}

}
#endif
