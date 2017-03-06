/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/index.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

#include <generic/memory/lib/utils/pos.H>
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

template<>
inline size_t index(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target)
{
    return mss::pos(i_target) % MCS_PER_MC;
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
