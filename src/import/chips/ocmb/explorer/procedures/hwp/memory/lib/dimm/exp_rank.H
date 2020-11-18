/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/exp_rank.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file exp_rank.H
/// @brief Explorer rank definitions
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

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

        // Note! a configuration of 2 4-rank dimms is not possible.
        // In this hypothetical scenario, the value for phy-rank would not
        // be valid / does not apply, as there will be some rollover.
        static constexpr uint8_t PHY_RANK_INDEX_STEP = 2;
};

///
/// @brief Return a vector of rank numbers which represent the primary rank pairs for this port
/// @param[in] i_target port target on which to operate
/// @param[out] o_ranks a vector of ranks
/// @return FAPI@_RC_SUCCESS iff all is ok
inline fapi2::ReturnCode primary_ranks( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        std::vector< uint64_t >& o_rps )
{
    o_rps.clear();
    std::vector<mss::rank::info<mss::mc_type::EXPLORER>> l_rank_info_vect;
    FAPI_TRY(mss::rank::ranks_on_port<mss::mc_type::EXPLORER>(i_target, l_rank_info_vect));

    // Loop through and assemble the ranks
    for(const auto& l_rank_info : l_rank_info_vect)
    {
        o_rps.push_back(l_rank_info.get_port_rank());
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return a vector of rank numbers which represent the primary rank pairs for this dimm
/// @param[in] i_target DIMM target on which to operate
/// @param[out] o_ranks a vector of ranks
/// @return FAPI@_RC_SUCCESS iff all is ok
inline fapi2::ReturnCode primary_ranks( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        std::vector< uint64_t >& o_rps )
{
    o_rps.clear();
    std::vector<mss::rank::info<mss::mc_type::EXPLORER>> l_rank_info_vect;
    FAPI_TRY(mss::rank::ranks_on_dimm<mss::mc_type::EXPLORER>(i_target, l_rank_info_vect));

    // Loop through and assemble the ranks
    for(const auto& l_rank_info : l_rank_info_vect)
    {
        o_rps.push_back(l_rank_info.get_port_rank());
    }

fapi_try_exit:
    return fapi2::current_err;
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

///
/// @brief Return a vector of rank numbers which represent the ranks for this dimm
/// @param[in] i_dimm_target TARGET_TYPE_DIMM
/// @param[out] o_ranks a vector of ranks for dimm (numbers)
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template<>
inline fapi2::ReturnCode ranks_on_dimm_helper<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
        i_dimm_target,
        std::vector<uint64_t>& o_ranks)
{
    std::vector<uint64_t> l_ranks;
    std::vector<mss::rank::info<>> l_vect;

    FAPI_TRY( mss::rank::ranks_on_dimm<mss::mc_type::EXPLORER>(i_dimm_target, l_vect) );

    // Loop through and get ranks or each
    for (const auto l_rank_info : l_vect)
    {
        l_ranks.push_back( l_rank_info.get_dimm_rank() );
    }

    o_ranks = l_ranks;

fapi_try_exit:
    return fapi2::current_err;
}


} // namespace rank
} // namespace mss
#endif
