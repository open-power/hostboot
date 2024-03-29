/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/mss_rank.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file mss_rank.H
/// @brief Tools to obtain rank info from DIMM or PORT target
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_GENERIC_RANK_H_
#define _MSS_GENERIC_RANK_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/index.H>
#include <generic/memory/lib/utils/find.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{
namespace rank
{

///
/// @brief Works around any issues with swizzle on the PHY ranks
/// @tparam MC the memory controller type
/// @tparam fapi2::TargetType T the target type on which to operate
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_phy_rank the PHY rank which might need to be updated
/// @return FAPI2_RC_SUCCESS iff success
///
template <mss::mc_type MC, fapi2::TargetType T>
inline fapi2::ReturnCode phy_rank_swizzle_workaround(const fapi2::Target<T>& i_target, uint8_t& io_phy_rank);

///
/// @brief Returns the value for the EFD rank from between the PHY rank and the port rank
/// @tparam MC the memory controller type
/// @param[in] i_port_rank
/// @param[in] i_phy_rank
/// @return the EFD rank. Depending upon the memory controller, it will either be the port rank or the PHY rank
///
template <mss::mc_type MC>
inline uint8_t compute_efd_rank(const uint8_t i_port_rank, const uint8_t i_phy_rank);

///
/// @brief Rank traits class for variations depending on MC
/// @tparam MC the memory controller type
///
template <mss::mc_type MC>
class rankTraits;

///
/// @brief Rank info class
/// @tparam MC the memory controller type
/// @tparam TT the class traits for the port
///
template <mss::mc_type MC, typename TT = rankTraits<MC>>
class info
{

    public:
        ///
        /// @default Constructor
        /// @note this is needed for certain STL containers but shouldn't be used
        ///
        info() = default;

        ///
        /// @brief Constructor for info object
        /// @param[in] i_target DIMM target
        /// @param[in] i_index dimm rank index 0-3
        /// @param[out] o_rc return code, FAPI2_RC_SUCCESS if no error
        ///
        info(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm_target, const uint8_t i_index, fapi2::ReturnCode& o_rc)
        {
            o_rc = fapi2::FAPI2_RC_SUCCESS;
            // Predeclaring these to avoid "may be un declared" compile issues
            // We'll get good values below if our asserts pass
            iv_dimm_rank = 0;
            iv_port_rank = 0;
            iv_phy_rank = 0;
            iv_efd_rank = 0;

            uint8_t l_master_ranks_per_dimm = 0;
            FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_dimm_target, l_master_ranks_per_dimm));

            FAPI_ASSERT((i_index < l_master_ranks_per_dimm),
                        fapi2::MSS_RANK_OUT_OF_RANGE()
                        .set_TARGET(i_dimm_target)
                        .set_RANK(i_index),
                        "Rank %u provided to info constructor for DIMM " TARGTIDFORMAT " exceeded the number of master ranks per DIMM",
                        i_index, GENTARGTID(i_dimm_target));
            // Targets
            iv_dimm_target = i_dimm_target;
            iv_port_target = mss::find_target<TT::MEM_PORT_TARGET_TYPE>(i_dimm_target);

            // Ranks
            iv_dimm_rank = i_index;
            iv_port_rank = iv_dimm_rank + ((mss::index(i_dimm_target) * TT::RANK_INDEX_STEP));
            iv_phy_rank = iv_dimm_rank + ((mss::index(i_dimm_target) * TT::PHY_RANK_INDEX_STEP));
            FAPI_TRY(phy_rank_swizzle_workaround<MC>(i_dimm_target, iv_phy_rank));
            iv_efd_rank = compute_efd_rank<MC>(iv_port_rank, iv_phy_rank);

        fapi_try_exit:
            o_rc = fapi2::current_err;
        }

        ///
        /// @brief Constructor for info object
        /// @param[in] i_target PORT target
        /// @param[in] i_index port rank index 0-7
        /// @param[out] o_rc return code, FAPI2_RC_SUCCESS if no error
        ///
        info(const fapi2::Target<TT::MEM_PORT_TARGET_TYPE>& i_port_target, const uint8_t i_index, fapi2::ReturnCode& o_rc)
        {
            o_rc = fapi2::FAPI2_RC_SUCCESS;

            // Dimm Target
            const size_t l_target_index = i_index / TT::RANK_INDEX_STEP;
            const auto& l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_port_target);

            // This assumes that the mc_type max # of dimms per port is correct
            FAPI_ASSERT( !l_dimms.empty(),
                         fapi2::MSS_EMPTY_VECTOR().
                         set_FUNCTION(INIT_RANK_INFO).
                         set_TARGET(i_port_target),
                         "Empty dimm vector received on port " TARGTIDFORMAT,
                         GENTARGTID(i_port_target));

            {
                // This will remain false in two cases:
                // Either:
                // 1.   The corresponding DIMM index is out of range (caused by port index out of range)
                // 2.   The corresponding DIMMs master_ranks_per_dimm is less than the desired rank
                bool l_valid_rank = false;

                for (const auto& l_dimm : l_dimms)
                {
                    // Since we can't guarantee the order of the returned dimms, we iterate through until we (might) find
                    // the right one. There's a chance it may not exist for example given info(port, rank13) would give us
                    // a dimm index above 2, which may be out of range, so we could never find a matching dimm, so we will
                    // throw that error.
                    // If we do find the right dimm, we need to then make sure that the master_ranks_per_dimm attribute
                    // is greater than the expected dimm rank.
                    if (mss::index(l_dimm) == l_target_index)
                    {
                        uint8_t l_master_ranks_per_dimm = 0;
                        FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(l_dimm, l_master_ranks_per_dimm));

                        // The rank passed in matches one of a valid DIMM
                        l_valid_rank = (i_index % TT::RANK_INDEX_STEP) < l_master_ranks_per_dimm;

                        iv_dimm_target = l_dimm;
                    }
                }

                FAPI_ASSERT(l_valid_rank,
                            fapi2::MSS_RANK_OUT_OF_RANGE()
                            .set_TARGET(i_port_target)
                            .set_RANK(i_index),
                            "Rank %u provided to rank_info constructor for PORT " TARGTIDFORMAT " was out of range",
                            i_index, GENTARGTID(i_port_target));

                // Port Target
                iv_port_target = i_port_target;

                // Ranks
                iv_dimm_rank = i_index % TT::RANK_INDEX_STEP;
                {
                    const size_t l_dimm_index = i_index / TT::RANK_INDEX_STEP;

                    // Dimm index * 2 sets the center point at 2
                    // Add on the dimm rank
                    // Note that this logic does NOT apply in a hypothetical/impossible 2 4-rank dimm configuration
                    iv_phy_rank = ((l_dimm_index * TT::PHY_RANK_INDEX_STEP) + (iv_dimm_rank));
                }
                FAPI_TRY(phy_rank_swizzle_workaround<MC>(i_port_target, iv_phy_rank));
                iv_port_rank = i_index;
                iv_efd_rank = compute_efd_rank<MC>(iv_port_rank, iv_phy_rank);
            }

        fapi_try_exit:
            o_rc = fapi2::current_err;
        }

        ///
        /// @brief Accessor for port rank
        /// @return the number (0-7) of the rank within its port from the memory controller perspective
        ///
        inline const uint8_t get_port_rank() const
        {
            return iv_port_rank;
        }

        ///
        /// @brief Accessor for rank number of DIMM
        /// @return the number (0-3) of the DIMM. Largely used for indexing attribute values
        ///
        inline const uint8_t get_dimm_rank() const
        {
            return iv_dimm_rank;
        }

        ///
        /// @brief Accessor for phy rank
        /// @return the phy rank value
        /// @note in a hypothetical 2 4-rank dimm configuration (not possible), this value is not valid
        /// This is used for interacting with the PHY. ex) access delay regs, configuring training, phy init, etc
        ///
        inline const uint8_t get_phy_rank() const
        {
            return iv_phy_rank;
        }


        ///
        /// @brief Accessor for the EFD rank
        /// @return the phy rank value
        /// This is used for interacting with the EFD
        ///
        inline const uint8_t get_efd_rank() const
        {
            return iv_efd_rank;
        }

        ///
        /// @brief Accessor for DIMM target
        /// @return the dimm target associated with the rank
        ///
        inline const fapi2::Target<fapi2::TARGET_TYPE_DIMM> get_dimm_target() const
        {
            return iv_dimm_target;
        }

        ///
        /// @brief Accessor for PORT target
        /// @return the port target associated with the rank
        ///
        inline const fapi2::Target<TT::MEM_PORT_TARGET_TYPE> get_port_target() const
        {
            return iv_port_target;
        }

        ///
        /// @brief Comparison operator
        /// @param[in] i_rhs object to compare against
        /// @return true if this object is less than i_rhs
        ///
        bool operator<(const info& i_rhs) const
        {
            // Considering targets the most significant then the ranks
            if(iv_port_target != i_rhs.iv_port_target)
            {
                return iv_port_target < i_rhs.iv_port_target;
            }

            if(iv_dimm_target != i_rhs.iv_dimm_target)
            {
                return iv_dimm_target < i_rhs.iv_dimm_target;
            }

            if(iv_port_rank != i_rhs.iv_port_rank)
            {
                return iv_port_rank < i_rhs.iv_port_rank;
            }

            if(iv_dimm_rank != i_rhs.iv_dimm_rank)
            {
                return iv_dimm_rank < i_rhs.iv_dimm_rank;
            }


            if(iv_phy_rank != i_rhs.iv_phy_rank)
            {
                return iv_phy_rank < i_rhs.iv_phy_rank;
            }

            return iv_efd_rank < i_rhs.iv_efd_rank;
        }

    private:
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_dimm_target;
        fapi2::Target<TT::MEM_PORT_TARGET_TYPE> iv_port_target;

        // The rank within the DIMM:0-3
        // Generally, used for indexing values of an attribute
        uint8_t iv_dimm_rank;

        // The rank withink the port from the memory controller perspective: 0-7
        // Used for displaying results and firmware callouts
        uint8_t iv_port_rank;

        // Note! a configuration of 2 4-rank dimms is not possible.
        // In this hypothetical scenario, the value for phy-rank would not
        // be valid / does not apply, as there will be some rollover.
        // 1 rank-per-dimm: 0 dimm0 2 dimm1
        // 2 rank-per-dimm: 0/1 dimm0 2/3 dimm1.
        // 2 rank single dimm 0/1
        // 4 rank (quad encoded) 0-3.
        uint8_t iv_phy_rank;

        // The rank indexing used for the EFD (a portion of the SPD) is unique per memory controller/DRAM generation
        // For DDR4, it matches the PHY rank
        // For DDR5, it matches the port rank
        uint8_t iv_efd_rank;
} __attribute__ ((aligned (8)));

///
/// @brief Obtains all DIMM ranks on a given port target
/// @tparam MC the memory controller type
/// @tparam TT the class traits for the port
/// @param[in] i_port_target port target
/// @param[out] o_vect vector of ranks
/// @return FAPI2_RC_SUCCESS iff success
///
template <mss::mc_type MC, typename TT = rankTraits<MC>>
fapi2::ReturnCode ranks_on_port(const fapi2::Target<TT::MEM_PORT_TARGET_TYPE>& i_port_target,
                                std::vector<info<MC>>& o_vect)
{
    o_vect.clear();

    uint8_t l_master_ranks_per_dimm[TT::MAX_DIMMS_PER_PORT] __attribute__ ((aligned (4))) = {0};
    FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_port_target, l_master_ranks_per_dimm));

    FAPI_ASSERT(((l_master_ranks_per_dimm[0] <= TT::MAX_RANKS_PER_DIMM) &&
                 (l_master_ranks_per_dimm[1] <= TT::MAX_RANKS_PER_DIMM)),
                fapi2::MSS_TOO_MANY_PRIMARY_RANKS_ON_PORT()
                .set_PORT_TARGET(i_port_target),
                "Primary ranks on PORT " TARGTIDFORMAT " exceeded %u",
                GENTARGTID(i_port_target),
                TT::MAX_RANKS_PER_DIMM);

    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_port_target))
    {
        const uint8_t l_dimm_index = mss::index(l_dimm);
        const uint8_t l_port_index_start = l_dimm_index * TT::RANK_INDEX_STEP;

        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

        // For each rank index of the dimm from the port's perspective
        for (uint8_t l_index = l_port_index_start; l_index < (l_port_index_start + l_master_ranks_per_dimm[l_dimm_index]);
             ++l_index)
        {
            o_vect.push_back(mss::rank::info<MC>(i_port_target, l_index, l_rc));
            FAPI_TRY(l_rc);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Obtains all ranks on a given DIMM target
/// @tparam MC the memory controller type
/// @tparam TT the class traits for the port
/// @param[in] i_target DIMM target
/// @param[out] o_vect vector of ranks
/// @return FAPI2_RC_SUCCESS iff success
///
template <mss::mc_type MC, typename TT = rankTraits<MC>>
fapi2::ReturnCode ranks_on_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm_target,
                                std::vector<info<MC>>& o_vect)
{
    o_vect.clear();
    uint8_t l_master_ranks_per_dimm = 0;
    FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_dimm_target, l_master_ranks_per_dimm));

    FAPI_ASSERT(l_master_ranks_per_dimm <= TT::MAX_RANKS_PER_DIMM,
                fapi2::MSS_TOO_MANY_PRIMARY_RANKS_ON_DIMM()
                .set_RANK_COUNT(l_master_ranks_per_dimm)
                .set_DIMM_TARGET(i_dimm_target),
                "Seeing %d primary ranks on DIMM " TARGTIDFORMAT,
                l_master_ranks_per_dimm,
                GENTARGTID(i_dimm_target));
    {
        // Return code for constructor call
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

        // For each rank index from the dimm's perspective
        for (uint8_t l_index = 0; l_index < l_master_ranks_per_dimm; l_index++)
        {
            o_vect.push_back(mss::rank::info<MC>(i_dimm_target, l_index, l_rc));
            FAPI_TRY(l_rc, "ranks_on_dimm(): Error in rank::info constructor call for DIMM " TARGTIDFORMAT " and rank %u",
                     GENTARGTID(i_dimm_target), l_index);
        }
    }
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return a vector of rank numbers which represent the ranks for this dimm
/// @tparam MC the memory controller type
/// @param[in] i_dimm_target TARGET_TYPE_DIMM
/// @param[out] o_port_ranks a vector of port ranks for dimm (numbers)
/// @return FAPI2_RC_SUCCESS iff all is ok
/// @note Outputs the port rank numbers for this DIMM
///
template<mss::mc_type MC>
fapi2::ReturnCode ranks_on_dimm_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_dimm_target,
                                       std::vector<uint64_t>& o_port_ranks)
{
    std::vector<uint64_t> l_port_ranks;
    std::vector<mss::rank::info<MC>> l_vect;

    FAPI_TRY( mss::rank::ranks_on_dimm<MC>(i_dimm_target, l_vect) );

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
/// @brief Return a vector of rank numbers which represent the primary rank pairs for this port
/// @tparam MC the memory controller type
/// @param[in] i_target port target on which to operate
/// @param[out] o_port_ranks a vector of ranks
/// @return FAPI2_RC_SUCCESS iff all is ok
template <mss::mc_type MC>
inline fapi2::ReturnCode primary_ranks( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        std::vector< uint64_t >& o_port_ranks )
{
    o_port_ranks.clear();
    std::vector<mss::rank::info<MC>> l_rank_info_vect;
    FAPI_TRY(mss::rank::ranks_on_port<MC>(i_target, l_rank_info_vect));

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
/// @tparam MC the memory controller type
/// @param[in] i_target DIMM target on which to operate
/// @param[out] o_port_ranks a vector of ranks
/// @return FAPI2_RC_SUCCESS iff all is ok
template <mss::mc_type MC>
inline fapi2::ReturnCode primary_ranks( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        std::vector< uint64_t >& o_port_ranks )
{
    o_port_ranks.clear();
    std::vector<mss::rank::info<MC>> l_rank_info_vect;
    FAPI_TRY(mss::rank::ranks_on_dimm<MC>(i_target, l_rank_info_vect));

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
/// @tparam MC the memory controller type
/// @param[in] i_port_rank the rank number.
/// @return the relative position of the DIMM which contains this rank.
///
template <mss::mc_type MC>
inline size_t get_dimm_from_rank(const uint64_t i_port_rank)
{
    using TT = rankTraits<MC>;
    return i_port_rank / TT::RANK_INDEX_STEP;
}

} // rank
} // mss
#endif
