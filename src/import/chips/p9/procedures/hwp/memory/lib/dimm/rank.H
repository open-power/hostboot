/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/dimm/rank.H $              */
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
/// @file rank.H
/// @brief Do things with or for ranks
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_RANK_H_
#define _MSS_RANK_H_

#include <fapi2.H>
#include <mss_attribute_accessors.H>

namespace mss
{

///
/// @brief Return a vector of rank numbers which represent the ranks for this dimm
/// @tparam T the target type you'd like the associated ranks for
/// @param[in] i_target
/// @param[out] o_ranks a vector of ranks (numbers)
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode ranks( const fapi2::Target<T>& i_target, std::vector< uint64_t >& o_ranks );

///
/// @brief Return a vector of rank numbers which represent the primary rank pairs for this port or dimm
/// @tparam T the target type
/// @param[in] i_target TARGET_TYPE_MCA or TARGET_TYPEDIMM
/// @param[out] o_rps a vector of rank_pairs
/// @return FAPI@_RC_SUCCESS iff all is ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode primary_ranks( const fapi2::Target<T>& i_target, std::vector< uint64_t >& o_rps );

///
/// @brief Return true iff this rank is on thie DIMM
/// @param[in] i_target representing the DIMM
/// @param[in] i_rank the rank number.
/// @return true iff i_rank is a rank on i_target
///
bool is_rank_on_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, const uint64_t i_rank);

///
/// @brief Return the *port relative position* of the DIMM which posesses this rank
/// @param[in] i_rank the rank number.
/// @return the relative position of the DIMM which contains this rank.
///
size_t get_dimm_from_rank(const uint64_t i_rank);

///
/// @brief Given a target, get the rank pair assignments, based on DIMMs
/// @tparam T the fapi2::TargetType
/// @param[in] i_target the target (MCA or MBA?)
/// @param[out] o_registers the regiter settings for the appropriate rank pairs
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T>
fapi2::ReturnCode get_rank_pair_assignments(const fapi2::Target<T>& i_target,
        std::pair<uint64_t, uint64_t>& o_registers);

///
/// @brief Setup the rank information in the port
/// @tparam T the fapi2::TargetType
/// @param[in] i_target the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T>
fapi2::ReturnCode set_rank_pairs(const fapi2::Target<T>& i_target);

///
/// @brief get the rank information related to the port
/// @tparam T the fapi2::TargetType
/// @param[in] i_target the target (MCA or MBA?)
/// @param[out] o_pairs std::vector of rank pairs configured
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template< fapi2::TargetType T>
fapi2::ReturnCode get_rank_pairs(const fapi2::Target<T>& i_target, std::vector<uint64_t>& o_pairs);

///
/// @brief Get a rank-pair id from a physical rank
/// Returns a number representing which rank-pair this rank is a part of
/// @tparam T the fapi2::TargetType
/// @param[in] i_target  the target (MCA or MBA?)
/// @param[in] i_rank the physical rank number
/// @param[out] o_pairs the rank pair
/// @return FAPI2_RC_SUCCESS if and only if ok, FAPI2_RC_INVALID_PARAMETER if the rank isn't found
///
template< fapi2::TargetType T>
fapi2::ReturnCode get_pair_from_rank(const fapi2::Target<T>& i_target, const uint64_t i_rank, uint64_t& o_pair);

}
#endif
