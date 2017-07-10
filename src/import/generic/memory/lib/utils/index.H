/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/index.H $                 */
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
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_INDEX_H_
#define _MSS_INDEX_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/pos.H>

///
/// @brief Trait classes for the mss::index functions
///
template<fapi2::TargetType T>
class indexTraits
{
    public:
        enum
        {
            MCS_PER_MC = 2,
            PORTS_PER_MCBIST = 4,
            PORTS_PER_MCS = 2,
            DIMMS_PER_PORT = 2,
            MBA_PER_MC = 2,
        };
};

namespace mss
{

///
/// @brief Return an attribute array index from a fapi2 target
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target a fapi2 target
/// @return size_t the attribute array index.
///
template< fapi2::TargetType T >
inline size_t index(const fapi2::Target<T>& i_target);

///
/// @brief Return an attribute array index from a DIMM target
/// @param[in] i_target a DIMM target representing the DIMM in question
/// @return size_t the attribute array index.
///
template<>
inline size_t index(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target)
{
    typedef indexTraits<fapi2::TARGET_TYPE_DIMM> TT;
    return mss::pos(i_target) % TT::DIMMS_PER_PORT;
}

///
///@brief Return an attribute array index from a MCA target
/// @param[in] i_target a MCA target representing the MCA in question
/// @return size_t the attribute array index.
///
template<>
inline size_t index(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target)
{
    typedef indexTraits<fapi2::TARGET_TYPE_MCA> TT;
    return mss::pos(i_target) % TT::PORTS_PER_MCS;
}

///
/// @brief Return an attribute array index from a MCS target
/// @param[in] i_target a MCS target representing the MCS in question
/// @return size_t the attribute array index.
///
template<>
inline size_t index(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target)
{
    typedef indexTraits<fapi2::TARGET_TYPE_MCS> TT;
    return mss::pos(i_target) % TT::MCS_PER_MC;
}

///
/// @brief Return an attribute array index from a rank number
/// @param[in] i_rank uint64_t a rank number DIMM0 {0, 1, 2, 3} DIMM1 {0, 1, 2, 3}
/// @return size_t the attribute array index.
///
inline size_t index(const uint64_t i_rank)
{
    constexpr size_t RANK_MID_POINT = 4;
    return i_rank % RANK_MID_POINT;
}

}
#endif
