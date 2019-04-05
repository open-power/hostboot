/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/exp_rank.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef _MSS_EXP_RANK_H_
#define _MSS_EXP_RANK_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/mss_rank.H>

namespace mss
{
namespace rank
{

///
/// @brief Rank traits for explorer
///
template <>
class rankTraits<mss::mc_type::EXPLORER>
{
    public:
        static constexpr uint8_t MAX_DIMMS_PER_PORT = 2;
        static constexpr uint8_t MAX_RANKS_PER_DIMM = 4;
        static constexpr uint8_t RANK_INDEX_STEP = 4;
};

///
/// @brief Return a vector of rank numbers which represent the primary rank pairs for this port or dimm
/// @tparam T the target type
/// @param[in] i_target TARGET_TYPE_MCA or TARGET_TYPEDIMM
/// @param[out] o_rps a vector of rank_pairs
/// @return FAPI@_RC_SUCCESS iff all is ok
//TODO: Need to implement this
template< fapi2::TargetType T >
inline fapi2::ReturnCode primary_ranks( const fapi2::Target<T>& i_target, std::vector< uint64_t >& o_rps )
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Return the *port relative position* of the DIMM which posesses this rank
/// @param[in] i_rank the rank number.
/// @return the relative position of the DIMM which contains this rank.
inline size_t get_dimm_from_rank(const uint64_t i_rank)
{
    using TT = rankTraits<mss::mc_type::EXPLORER>;
    return i_rank / TT::MAX_RANKS_PER_DIMM;
}

} // namespace rank
} // namespace mss
#endif
