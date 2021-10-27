/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/exp_rank.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_EXP_RANK_H_
#define _MSS_EXP_RANK_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/mss_rank.H>
#include <lib/shared/exp_consts.H>
#include <lib/exp_attribute_accessors_manual.H>

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

        static constexpr fapi2::TargetType MEM_PORT_TARGET_TYPE = fapi2::TARGET_TYPE_MEM_PORT;
};

///
/// @brief Return a vector of rank numbers which represent the primary rank pairs for this port
/// @param[in] i_target port target on which to operate
/// @param[out] o_port_ranks a vector of ranks
/// @return FAPI2_RC_SUCCESS iff all is ok
inline fapi2::ReturnCode primary_ranks( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        std::vector< uint64_t >& o_port_ranks )
{
    o_port_ranks.clear();
    std::vector<mss::rank::info<mss::mc_type::EXPLORER>> l_rank_info_vect;
    FAPI_TRY(mss::rank::ranks_on_port<mss::mc_type::EXPLORER>(i_target, l_rank_info_vect));

    // Loop through and assemble the ranks
    for(const auto& l_rank_info : l_rank_info_vect)
    {
        o_port_ranks.push_back(l_rank_info.get_port_rank());
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return a vector of rank numbers which represent the primary rank pairs for this dimm
/// @param[in] i_target DIMM target on which to operate
/// @param[out] o_port_ranks a vector of ranks
/// @return FAPI2_RC_SUCCESS iff all is ok
inline fapi2::ReturnCode primary_ranks( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        std::vector< uint64_t >& o_port_ranks )
{
    o_port_ranks.clear();
    std::vector<mss::rank::info<mss::mc_type::EXPLORER>> l_rank_info_vect;
    FAPI_TRY(mss::rank::ranks_on_dimm<mss::mc_type::EXPLORER>(i_target, l_rank_info_vect));

    // Loop through and assemble the ranks
    for(const auto& l_rank_info : l_rank_info_vect)
    {
        o_port_ranks.push_back(l_rank_info.get_port_rank());
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return the *port relative position* of the DIMM which posesses this rank
/// @param[in] i_port_rank the rank number.
/// @return the relative position of the DIMM which contains this rank.
inline size_t get_dimm_from_rank(const uint64_t i_port_rank)
{
    using TT = rankTraits<mss::mc_type::EXPLORER>;
    return i_port_rank / TT::MAX_RANKS_PER_DIMM;
}

///
/// @brief Return a vector of rank numbers which represent the ranks for this dimm
/// @param[in] i_dimm_target TARGET_TYPE_DIMM
/// @param[out] o_dimm_ranks a vector of port ranks for dimm (numbers)
/// @return FAPI2_RC_SUCCESS iff all is ok
/// @note Outputs the port rank numbers for this DIMM
///
template<>
inline fapi2::ReturnCode ranks_on_dimm_helper<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm_target,
    std::vector<uint64_t>& o_port_ranks)
{
    std::vector<uint64_t> l_port_ranks;
    std::vector<mss::rank::info<mss::mc_type::EXPLORER>> l_vect;

    FAPI_TRY( mss::rank::ranks_on_dimm<mss::mc_type::EXPLORER>(i_dimm_target, l_vect) );

    // Loop through and get ranks or each
    for (const auto l_rank_info : l_vect)
    {
        l_port_ranks.push_back( l_rank_info.get_port_rank() );
    }

    o_port_ranks = l_port_ranks;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Works around any issues with swizzle on the PHY ranks - explorer/DIMM
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_phy_rank the PHY rank which might need to be updated
/// @return FAPI2_RC_SUCCESS iff success
///
template <>
inline fapi2::ReturnCode phy_rank_swizzle_workaround<mss::mc_type::EXPLORER>(const
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, uint8_t& io_phy_rank)
{
    bool l_is_quad_encoded_cs = false;
    FAPI_TRY(is_quad_encoded_cs(i_target, l_is_quad_encoded_cs));

    // Note: ranks 1/2 are swapped in the quad encoded mapping compared to the JEDEC perspective
    // The reason for this is that there is a bug in the explorer logic documented in JIRA355
    // This bug swaps the signals on the DFI interface for ranks 1/2
    // So, IBM's memory controller perspective rank 2 accesses JEDEC rank 1
    // While IBM's memory controller perspective rank 1 accesses JEDEC rank 2
    // The decision was made to swap these encodings
    // This way any row repair/CCS requests will match the memory controller rank called out in the IBM register
    // Other CCS relevant information (ODT signals, etc) should be handled via the attributes being encoded in the IBM perspective
    // We handle this fix in the rank API here by swapping PHY rank 1/2
    if(l_is_quad_encoded_cs)
    {
        // If we're rank 1, swap to rank 2
        if(io_phy_rank == 1)
        {
            io_phy_rank = 2;
        }
        // If we're rank 2, swap to rank 1
        else if(io_phy_rank == 2)
        {
            io_phy_rank = 1;
        }
    }

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Works around any issues with swizzle on the PHY ranks - explorer/MEM_PORT specialization
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_phy_rank the PHY rank which might need to be updated
/// @return FAPI2_RC_SUCCESS iff success
///
template <>
inline fapi2::ReturnCode phy_rank_swizzle_workaround<mss::mc_type::EXPLORER>(const
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, uint8_t& io_phy_rank)
{
    bool l_is_quad_encoded_cs = false;
    FAPI_TRY(is_quad_encoded_cs(i_target, l_is_quad_encoded_cs));

    // Note: ranks 1/2 are swapped in the quad encoded mapping compared to the JEDEC perspective
    // The reason for this is that there is a bug in the explorer logic documented in JIRA355
    // This bug swaps the signals on the DFI interface for ranks 1/2
    // So, IBM's memory controller perspective rank 2 accesses JEDEC rank 1
    // While IBM's memory controller perspective rank 1 accesses JEDEC rank 2
    // The decision was made to swap these encodings
    // This way any row repair/CCS requests will match the memory controller rank called out in the IBM register
    // Other CCS relevant information (ODT signals, etc) should be handled via the attributes being encoded in the IBM perspective
    // We handle this fix in the rank API here by swapping PHY rank 1/2
    if(l_is_quad_encoded_cs)
    {
        // If we're rank 1, swap to rank 2
        if(io_phy_rank == 1)
        {
            io_phy_rank = 2;
        }
        // If we're rank 2, swap to rank 1
        else if(io_phy_rank == 2)
        {
            io_phy_rank = 1;
        }
    }

fapi_try_exit:
    return fapi2::current_err;

}

} // namespace rank
} // namespace mss
#endif
