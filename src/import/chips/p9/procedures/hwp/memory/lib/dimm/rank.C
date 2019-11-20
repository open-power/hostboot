/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/rank.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file rank.C
/// @brief Manage DIMM ranks
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <mss.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::FAPI2_RC_SUCCESS;
using fapi2::FAPI2_RC_INVALID_PARAMETER;

namespace mss
{
// Definition of the Nimbus PHY rank_pair0 config registers
const std::vector< uint64_t > rankPairTraits<TARGET_TYPE_MCA, 0>::RANK_PAIR_REGS =
{
    MCA_DDRPHY_PC_RANK_PAIR0_P0,
    MCA_DDRPHY_PC_RANK_PAIR2_P0,
};

// Definition of the Nimbus PHY rank_pair1 config registers
const std::vector< uint64_t > rankPairTraits<TARGET_TYPE_MCA, 1>::RANK_PAIR_REGS =
{
    MCA_DDRPHY_PC_RANK_PAIR0_P0,
    MCA_DDRPHY_PC_RANK_PAIR2_P0,
};

// Definition of the Nimbus PHY rank_pair2 config registers
const std::vector< uint64_t > rankPairTraits<TARGET_TYPE_MCA, 2>::RANK_PAIR_REGS =
{
    MCA_DDRPHY_PC_RANK_PAIR1_P0,
    MCA_DDRPHY_PC_RANK_PAIR3_P0,
};

// Definition of the Nimbus PHY rank_pair3 config registers
const std::vector< uint64_t > rankPairTraits<TARGET_TYPE_MCA, 3>::RANK_PAIR_REGS =
{
    MCA_DDRPHY_PC_RANK_PAIR1_P0,
    MCA_DDRPHY_PC_RANK_PAIR3_P0,
};

// Definition of mappings for which fields (primary, secondary, ...) go into which regs
const std::vector< uint64_t > rankPairTraits<TARGET_TYPE_MCA, 0>::RANK_PAIR_FIELD_MAP = { 0, 0, 1, 1 };
const std::vector< uint64_t > rankPairTraits<TARGET_TYPE_MCA, 1>::RANK_PAIR_FIELD_MAP = { 0, 0, 1, 1 };
const std::vector< uint64_t > rankPairTraits<TARGET_TYPE_MCA, 2>::RANK_PAIR_FIELD_MAP = { 0, 0, 1, 1 };
const std::vector< uint64_t > rankPairTraits<TARGET_TYPE_MCA, 3>::RANK_PAIR_FIELD_MAP = { 0, 0, 1, 1 };

namespace rank
{

//
// Static table of rank pair assignments. Some of them won't be valid depending on
// the plug rules (which may be OpenPOWER, IBM, etc.) Some also won't make sense
// -- 3 rank DIMM? -- but it doesn't take up much space and lord knows stranger things
// have happened ... Won't hurt to have this defined JustInCase(tm).
// Index by [DIMM1 rank count][DIMM0 rank count]
// Order and values for the below structure
// Each value represents a rank pair configuration register's proper settings
//  Primary +  secondary 0/1
//  Primary +  secondary 2/3
// Tertiary + quaternary 0/1
// Tertiary + quaternary 2/3
// TODO RTC 160869: Review hard coded values, possibly make into traits?
static const std::vector< std::vector< rank_pair_data > > rank_pair_assignments =
{
    {
        {0x0000, 0x0000, 0x0000, 0x0000}, // 0 ranks DIMM 1, 0 ranks DIMM0
        {0x1000, 0x0000, 0x0000, 0x0000}, // 0 ranks DIMM 1, 1 ranks DIMM0
        {0x1030, 0x0000, 0x0000, 0x0000}, // 0 ranks DIMM 1, 2 ranks DIMM0
        {0x1530, 0x0000, 0x0000, 0x0000}, // 0 ranks DIMM 1, 3 ranks DIMM0
        {0x1537, 0x0000, 0x0000, 0x0000}  // 0 ranks DIMM 1, 4 ranks DIMM0
    },
    {
        {0x0000, 0x9000, 0x0000, 0x0000}, // 1 ranks DIMM 1, 0 ranks DIMM0
        {0x1000, 0x9000, 0x0000, 0x0000}, // 1 ranks DIMM 1, 1 ranks DIMM0
        {0x1030, 0x9000, 0x0000, 0x0000}, // 1 ranks DIMM 1, 2 ranks DIMM0
        {0x1530, 0x9000, 0x0000, 0x0000}, // 1 ranks DIMM 1, 3 ranks DIMM0
        {0x1537, 0x9000, 0x0000, 0x0000}  // 1 ranks DIMM 1, 4 ranks DIMM0
    },
    {
        {0x0000, 0x90B0, 0x0000, 0x0000}, // 2 ranks DIMM 1, 0 ranks DIMM0
        {0x1000, 0x90B0, 0x0000, 0x0000}, // 2 ranks DIMM 1, 1 ranks DIMM0
        {0x1030, 0x90B0, 0x0000, 0x0000}, // 2 ranks DIMM 1, 2 ranks DIMM0
        {0x1530, 0x90B0, 0x0000, 0x0000}, // 2 ranks DIMM 1, 3 ranks DIMM0
        {0x1537, 0x90B0, 0x0000, 0x0000}  // 2 ranks DIMM 1, 4 ranks DIMM0
    },
    {
        {0x0000, 0x9DB0, 0x0000, 0x0000}, // 3 ranks DIMM 1, 0 ranks DIMM0
        {0x1000, 0x9DB0, 0x0000, 0x0000}, // 3 ranks DIMM 1, 1 ranks DIMM0
        {0x1030, 0x9DB0, 0x0000, 0x0000}, // 3 ranks DIMM 1, 2 ranks DIMM0
        {0x1530, 0x9DB0, 0x0000, 0x0000}, // 3 ranks DIMM 1, 3 ranks DIMM0
        {0x1537, 0x9DB0, 0x0000, 0x0000}  // 3 ranks DIMM 1, 4 ranks DIMM0
    },
    {
        {0x0000, 0x9DBF, 0x0000, 0x0000}, // 4 ranks DIMM 1, 0 ranks DIMM0
        {0x1000, 0x9DBF, 0x0000, 0x0000}, // 4 ranks DIMM 1, 1 ranks DIMM0
        {0x1030, 0x9DBF, 0x0000, 0x0000}, // 4 ranks DIMM 1, 2 ranks DIMM0
        {0x1530, 0x9DBF, 0x0000, 0x0000}, // 4 ranks DIMM 1, 3 ranks DIMM0
        {0x1537, 0x9DBF, 0x0000, 0x0000}  // 4 ranks DIMM 1, 4 ranks DIMM0
    },
};

//
// Static table of vectors representing the master ranks, depending on the rank pair
// config. This table maps 1-1 to the table above, and allows us to skip the bit manipulation
// to figure out the master ranks. Note, no ranks means an empty vector ...
//
static const std::vector< std::vector< std::vector< uint64_t > > > primary_rank_pairs =
{
    {
        {},
        {0},
        {0, 1},
        {0, 1},
        {0, 1}
    },
    {
        {NO_RANK, NO_RANK, 4},
        {0, NO_RANK, 4},
        {0, 1, 4},
        {0, 1, 4},
        {0, 1, 4}
    },
    {
        {NO_RANK, NO_RANK, 4, 5},
        {0, NO_RANK, 4, 5},
        {0, 1, 4, 5},
        {0, 1, 4, 5},
        {0, 1, 4, 5}
    },
    {
        {NO_RANK, NO_RANK, 4, 5},
        {0, NO_RANK, 4, 5},
        {0, 1, 4, 5},
        {0, 1, 4, 5},
        {0, 1, 4, 5}
    },
    {
        {NO_RANK, NO_RANK, 4, 5},
        {0, NO_RANK, 4, 5},
        {0, 1, 4, 5},
        {0, 1, 4, 5},
        {0, 1, 4, 5}
    },
};

// Defines the same rank pair tables but this time for LRDIMM
// Nimbus only allows us to have all LR or all RDIMM plugged on a given port, so we're ok having two tables
// Note: for LRDIMM's we want to have common delay settings for each DIMM (DIMM0 has its settings and DIMM1 has its own settings)
// As such, we setup the rank pairs to have primary/secondary/tertiary/quaternary for each DIMM on a single rank pair
//  Primary +  secondary 0/1
//  Primary +  secondary 2/3
// Tertiary + quaternary 0/1
// Tertiary + quaternary 2/3
static const std::vector< std::vector< rank_pair_data > > lr_rank_pair_assignments =
{
    {
        {0x0000, 0x0000, 0x0000, 0x0000}, // 0 ranks DIMM 1, 0 ranks DIMM0
        {0x1000, 0x0000, 0x0000, 0x0000}, // 0 ranks DIMM 1, 1 ranks DIMM0
        {0x1300, 0x0000, 0x0000, 0x0000}, // 0 ranks DIMM 1, 2 ranks DIMM0
        {0x1300, 0x0000, 0x5000, 0x0000}, // 0 ranks DIMM 1, 3 ranks DIMM0
        {0x1300, 0x0000, 0x5700, 0x0000}, // 0 ranks DIMM 1, 4 ranks DIMM0
    },
    {
        {0x0000, 0x9000, 0x0000, 0x0000}, // 1 ranks DIMM 1, 0 ranks DIMM0
        {0x1000, 0x9000, 0x0000, 0x0000}, // 1 ranks DIMM 1, 1 ranks DIMM0
        {0x1300, 0x9000, 0x0000, 0x0000}, // 1 ranks DIMM 1, 2 ranks DIMM0
        {0x1300, 0x9000, 0x5000, 0x0000}, // 1 ranks DIMM 1, 3 ranks DIMM0
        {0x1300, 0x9000, 0x5700, 0x0000}, // 1 ranks DIMM 1, 4 ranks DIMM0
    },
    {
        {0x0000, 0x9B00, 0x0000, 0x0000}, // 2 ranks DIMM 1, 0 ranks DIMM0
        {0x1000, 0x9B00, 0x0000, 0x0000}, // 2 ranks DIMM 1, 1 ranks DIMM0
        {0x1300, 0x9B00, 0x0000, 0x0000}, // 2 ranks DIMM 1, 2 ranks DIMM0
        {0x1300, 0x9B00, 0x5000, 0x0000}, // 2 ranks DIMM 1, 3 ranks DIMM0
        {0x1300, 0x9B00, 0x5700, 0x0000}, // 2 ranks DIMM 1, 4 ranks DIMM0
    },
    {
        {0x0000, 0x9B00, 0x0000, 0xD000}, // 3 ranks DIMM 1, 0 ranks DIMM0
        {0x1000, 0x9B00, 0x0000, 0xD000}, // 3 ranks DIMM 1, 1 ranks DIMM0
        {0x1300, 0x9B00, 0x0000, 0xD000}, // 3 ranks DIMM 1, 2 ranks DIMM0
        {0x1300, 0x9B00, 0x5000, 0xD000}, // 3 ranks DIMM 1, 3 ranks DIMM0
        {0x1300, 0x9B00, 0x5700, 0xD000}, // 3 ranks DIMM 1, 4 ranks DIMM0
    },
    {
        {0x0000, 0x9B00, 0x0000, 0xDF00}, // 4 ranks DIMM 1, 0 ranks DIMM0
        {0x1000, 0x9B00, 0x0000, 0xDF00}, // 4 ranks DIMM 1, 1 ranks DIMM0
        {0x1300, 0x9B00, 0x0000, 0xDF00}, // 4 ranks DIMM 1, 2 ranks DIMM0
        {0x1300, 0x9B00, 0x5000, 0xDF00}, // 4 ranks DIMM 1, 3 ranks DIMM0
        {0x1300, 0x9B00, 0x5700, 0xDF00}, // 4 ranks DIMM 1, 4 ranks DIMM0
    },
};

//
// Static table of vectors representing the master ranks, depending on the rank pair
// config. This table maps 1-1 to the table above, and allows us to skip the bit manipulation
// to figure out the master ranks. Note, no ranks means an empty vector ...
// Note: for LRDIMM's we want to have common delay settings for each DIMM (DIMM0 has its settings and DIMM1 has its own settings)
// As such, we setup the rank pairs to have primary/secondary/tertiary/quaternary for each DIMM on a single rank pair
static const std::vector< std::vector< std::vector< uint64_t > > > lr_primary_rank_pairs =
{
    {
        {},
        {0},
        {0},
        {0},
        {0}
    },
    {
        {NO_RANK, NO_RANK, 4},
        {0, NO_RANK, 4},
        {0, NO_RANK, 4},
        {0, NO_RANK, 4},
        {0, NO_RANK, 4}
    },
    {
        {NO_RANK, NO_RANK, 4},
        {0, NO_RANK, 4},
        {0, NO_RANK, 4},
        {0, NO_RANK, 4},
        {0, NO_RANK, 4}
    },
    {
        {NO_RANK, NO_RANK, 4},
        {0, NO_RANK, 4},
        {0, NO_RANK, 4},
        {0, NO_RANK, 4},
        {0, NO_RANK, 4}
    },
    {
        {NO_RANK, NO_RANK, 4},
        {0, NO_RANK, 4},
        {0, NO_RANK, 4},
        {0, NO_RANK, 4},
        {0, NO_RANK, 4}
    },
};

//
// Static table of vectors representing ranks on a single DIMM
// Note: std::vector< uint64_t > v = single_dimm_ranks[mss::index(dimm)][ranks on dimm];
//
static const std::vector< std::vector< std::vector< uint64_t > > > single_dimm_ranks =
{
    { {},           {0},          {0, 1},       {0, 1, 2},    {0, 1, 2, 3} },
    { {},           {4},          {4, 5},       {4, 5, 6},    {4, 5, 6, 7} },
};

///
/// @brief Returns values based upon LRDIMM type or not
/// @tparam T Type of value to return
/// @param[in] i_dimm_type DIMM type to check
/// @param[in] i_lr input to pass back for LRDIMM
/// @param[in] i_r input to pass back for RDIMM
/// @return returns LR or R inputted values dependent upon LRDIMM type
///
template<typename T>
inline const T& dimm_type_value_select(const uint8_t i_dimm_type,
                                       const T& i_lr,
                                       const T& i_r)
{
    return (i_dimm_type == fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM) ? i_lr : i_r;
}

///
/// @brief Return true iff this rank is on thie DIMM
/// @param[in] i_target representing the DIMM
/// @param[in] i_rank the rank number.
/// @return true iff i_rank is a rank on i_target
///
bool is_rank_on_dimm(const fapi2::Target<TARGET_TYPE_DIMM>& i_target, const uint64_t i_rank)
{
    // DIMM[0] has ranks 0:3, DIMM[1] has ranks 4:7 - if there are not 4 ranks
    // on a DIMM, there are holes. That is, the first rank on DIMM[1] is always
    // rank #4.

    if (i_rank > 7)
    {
        FAPI_ERR("seeing rank %d? %s", i_rank, mss::c_str(i_target));
        return false;
    }

    if ((i_rank < RANK_MID_POINT) && (mss::index(i_target) == 0))
    {
        return true;
    }

    if ((i_rank >= RANK_MID_POINT) && (mss::index(i_target) == 1))
    {
        return true;
    }

    return false;
}

///
/// @brief Return the *port relative position* of the DIMM which posesses this rank
/// @param[in] i_rank the rank number.
/// @return the relative position of the DIMM which contains this rank.
///
size_t get_dimm_from_rank(const uint64_t i_rank)
{
    // DIMM[0] has ranks 0:3, DIMM[1] has ranks 4:7 - if there are not 4 ranks
    // on a DIMM, there are holes. That is, the first rank on DIMM[1] is always
    // rank #4.

    if (i_rank > 7)
    {
        FAPI_ERR("seeing rank %d?", i_rank);
        fapi2::Assert(false);
    }

    return (i_rank < RANK_MID_POINT) ? 0 : 1;
}

///
/// @brief Return the DIMM target which posesses this rank on a given port
/// @param[in] i_target the MCA port target
/// @param[in] i_rank the rank number
/// @param[out] o_dimm the DIMM target
/// @return FAPI2_RC_SUCCESS iff all is ok, FAPI2_RC_INVALID_PARAMETER otherwise
///
template<>
fapi2::ReturnCode get_dimm_target_from_rank(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rank,
        fapi2::Target<TARGET_TYPE_DIMM>& o_dimm)
{
    const size_t l_dimm_idx = get_dimm_from_rank(i_rank);
    const auto l_dimms = mss::find_targets<TARGET_TYPE_DIMM>(i_target);
    bool l_got_one = false;

    // Make sure we get a valid DIMM index. If not, this is a programming error.
    FAPI_ASSERT( (l_dimm_idx < l_dimms.size() ),
                 fapi2::MSS_BAD_DIMM_INDEX_FOR_GIVEN_RANK()
                 .set_RANK(i_rank)
                 .set_DIMM_INDEX(l_dimm_idx)
                 .set_MCA_TARGET(i_target),
                 "Invalid DIMM index (%d) found for provided rank (%d) in get_dimm_target_from_rank: %s",
                 l_dimm_idx,
                 i_rank,
                 mss::c_str(i_target));

    for (const auto& l_dimm : l_dimms)
    {
        if (mss::index(l_dimm) == l_dimm_idx)
        {
            FAPI_DBG("Found DIMM target for rank %d: %s", i_rank, mss::c_str(l_dimm));
            o_dimm = l_dimm;
            l_got_one = true;
        }
    }

    if (l_got_one)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Assert if we don't have a DIMM configured that matches the DIMM index (this shouldn't happen)
    FAPI_ASSERT( false,
                 fapi2::MSS_NO_DIMM_FOR_GIVEN_DIMM_INDEX()
                 .set_RANK(i_rank)
                 .set_DIMM_INDEX(l_dimm_idx)
                 .set_MCA_TARGET(i_target),
                 "Couldn't find a DIMM to match given rank (%d) and DIMM position (%d): %s",
                 i_rank,
                 l_dimm_idx,
                 mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return a vector of rank numbers which represent the primary rank pairs for this port
/// @param[in] i_target  TARGET_TYPE_MCA
/// @param[out] o_rps a vector of rank_pairs
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template<>
fapi2::ReturnCode primary_ranks( const fapi2::Target<TARGET_TYPE_MCA>& i_target, std::vector< uint64_t >& o_rps )
{
    FAPI_INF("get the primary ranks for %s", mss::c_str(i_target));

    // Get the count of rank pairs for both DIMM on the port
    std::vector<uint8_t> l_rank_count(MAX_DIMM_PER_PORT, 0);

    for (const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        FAPI_TRY( mss::eff_num_master_ranks_per_dimm(d, l_rank_count[mss::index(d)]) );
    }

    FAPI_DBG("%s ranks: %d, %d", mss::c_str(i_target), l_rank_count[0], l_rank_count[1]);

    o_rps.clear();

    {
        uint8_t l_dimm_type[MAX_DIMM_PER_PORT] = {};

        // Gets the DIMM type
        FAPI_TRY( mss::eff_dimm_type(i_target, &l_dimm_type[0]));
        const auto& l_primary_rank_pairs = dimm_type_value_select(l_dimm_type[0], lr_primary_rank_pairs, primary_rank_pairs);

        // Walk through rank pair table and skip empty pairs
        for (const auto l_rank : l_primary_rank_pairs[l_rank_count[1]][l_rank_count[0]])
        {
            if (l_rank != NO_RANK)
            {
                o_rps.push_back(l_rank);
            }
        }
    }

    // Returning success in case no DIMM's are configured
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return a vector of rank numbers which represent the primary rank pairs for this dimm
/// @param[in] i_target TARGET_TYPE_DIMM
/// @param[out] o_rps a vector of rank_pairs
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template<>
fapi2::ReturnCode primary_ranks( const fapi2::Target<TARGET_TYPE_DIMM>& i_target, std::vector< uint64_t >& o_rps )
{
    FAPI_INF("get the primary ranks for %s", mss::c_str(i_target));

    std::vector< uint64_t > l_prs;
    FAPI_TRY( primary_ranks(i_target.getParent<TARGET_TYPE_MCA>(), l_prs) );

    o_rps.clear();

    for (const auto r : l_prs)
    {
        if (is_rank_on_dimm(i_target, r))
        {
            o_rps.push_back(r);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return a vector of rank numbers which represent the ranks for this dimm
/// @param[in] i_target TARGET_TYPE_DIMM
/// @param[out] o_ranks a vector of ranks (numbers)
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template<>
fapi2::ReturnCode ranks( const fapi2::Target<TARGET_TYPE_DIMM>& i_target, std::vector< uint64_t >& o_ranks )
{
    uint8_t l_ranks = 0;
    FAPI_TRY( eff_num_master_ranks_per_dimm(i_target, l_ranks) );

    o_ranks = single_dimm_ranks[mss::index(i_target)][l_ranks];

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return a vector of rank numbers which represent the ranks for this dimm
/// @param[in] i_target TARGET_TYPE_MCA
/// @param[out] o_ranks a vector of ranks (numbers)
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template<>
fapi2::ReturnCode ranks( const fapi2::Target<TARGET_TYPE_MCA>& i_target, std::vector< uint64_t >& o_ranks )
{
    // Note: Isn't there a better way to do this?
    std::vector< uint64_t > l_ranks;
    o_ranks.clear();

    for (const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        FAPI_TRY( ranks(d, l_ranks) );
        o_ranks.insert(o_ranks.end(), l_ranks.begin(), l_ranks.end());
    }

    // Lets make sure the ranks are in order - we don't know if the child vector is in position
    // order, but its easy to get the ranks in order by sorting them.
    std::sort(o_ranks.begin(), o_ranks.end());

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Given a target, get the rank pair assignments, based on DIMMs
/// @param[in] i_target the target (MCA or MBA?)
/// @param[out] o_registers the register settings for the appropriate rank pairs
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode get_rank_pair_assignments(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
        rank_pair_data& o_registers)
{
    // TODO RTC:160869 add enum for rank pair 0 when it gets created
    typedef rankPairTraits<fapi2::TARGET_TYPE_MCA, 0> RPT;

    std::vector<uint8_t> l_rank_count(MAX_DIMM_PER_PORT, 0);
    uint16_t l_regs[RPT::NUM_RANK_PAIR_REGS] = {0};
    uint8_t l_dimm_type[MAX_DIMM_PER_PORT] = {};

    for (const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        FAPI_TRY( mss::eff_num_master_ranks_per_dimm(d, l_rank_count[mss::index(d)]) );
    }

    // Gets the DIMM type
    FAPI_TRY( mss::eff_dimm_type(i_target, &l_dimm_type[0]));

    // Get the override attribute setting
    FAPI_TRY( mss::eff_rank_group_override(i_target, l_regs) );

    // If the override attribute is zero, use the default assignments that correspond to the rank count.
    // Need only to check the first array entry since we need a valid primary rank in RP0 due to plug rules.
    {
        // If we're LRDIMM use lr_default rank_pair_assignments as the default vector, otherwise go with rank_pair_assignments
        const auto& l_default_table = dimm_type_value_select(l_dimm_type[0], lr_rank_pair_assignments, rank_pair_assignments);
        o_registers = (l_regs[0] == 0) ?
                      l_default_table[l_rank_count[1]][l_rank_count[0]] :
                      rank_pair_data(l_regs[0], l_regs[1], 0, 0);
    }

    FAPI_DBG("rank pair assignments for %s. [%d,%d] (RP0:0x%04x, RP1:0x%04x, RP2:0x%04x, RP3:0x%04x)",
             mss::c_str(i_target), l_rank_count[1], l_rank_count[0],
             o_registers.iv_rp_reg0, o_registers.iv_rp_reg1, o_registers.iv_rp_reg2, o_registers.iv_rp_reg3);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup the rank information in the port
/// @param[in] i_target the target (MCA)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode set_rank_pairs(const fapi2::Target<TARGET_TYPE_MCA>& i_target)
{
    fapi2::buffer<uint64_t> l_rp_reg;
    fapi2::buffer<uint64_t> l_rank_group;
    fapi2::buffer<uint64_t> l_rank_group_ext;

    // If a memory system consists of four or less ranks, each Rank Pair must contain one rank. Each rank has
    // unique configuration registers, calibration registers, and registers to store delay values. When a system
    // contains four or less ranks, each rank number used by the system must be loaded into one of the Primary
    // Rank fields.

    // Set the CSID to all 'unused' and we'll reset them as we configure rank pairs.
    // Note: Centaur configured this as 0xff00 all the time - it's unclear if we need
    // to set only the bits for the rank pairs configured, or whether 0xff00 will suffice. BRS
    // Updating for DD2 0xF000, as bits 4-7 (in terms of the phy reg) are removed
    constexpr uint64_t DD1_CSID = 0xff00;
    constexpr uint64_t DD2_CSID = 0xf000;
    const fapi2::buffer<uint64_t> l_csid_data = mss::chip_ec_nimbus_lt_2_0(i_target) ? DD1_CSID : DD2_CSID;

    // Gets the rankpairs
    rank_pair_data l_rp_registers;
    FAPI_TRY( get_rank_pair_assignments(i_target, l_rp_registers) );

    FAPI_DBG("setting rank pairs for %s. 0x%04x, 0x%04x 0x%04x, 0x%04x, csid: 0x%016llx",
             mss::c_str(i_target), l_rp_registers.iv_rp_reg0, l_rp_registers.iv_rp_reg1,
             l_rp_registers.iv_rp_reg2, l_rp_registers.iv_rp_reg3, l_csid_data);

    // Need an extra pair of parens to make FAPI_TRY parsing work correctly
    FAPI_TRY( (mss::rank::write_rank_pair_reg< 0, 0 >(i_target, l_rp_registers.iv_rp_reg0)) );
    FAPI_TRY( (mss::rank::write_rank_pair_reg< 2, 0 >(i_target, l_rp_registers.iv_rp_reg1)) );
    FAPI_TRY( (mss::rank::write_rank_pair_reg< 0, 1 >(i_target, l_rp_registers.iv_rp_reg2)) );
    FAPI_TRY( (mss::rank::write_rank_pair_reg< 2, 1 >(i_target, l_rp_registers.iv_rp_reg3)) );
    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_PC_CSID_CFG_P0, l_csid_data) );

    // Register 0 contains RP0/1's primary/secondary ranks - these are controlled by the rank group register
    l_rp_reg = l_rp_registers.iv_rp_reg0;
    FAPI_TRY( mss::rank::set_mirror_bits<0>(i_target, l_rp_reg, l_rank_group) );
    FAPI_TRY( mss::rank::set_mirror_bits<1>(i_target, l_rp_reg, l_rank_group) );

    // Register 1 contains RP2/3's primary/secondary ranks - these are controlled by the rank group register
    l_rp_reg = l_rp_registers.iv_rp_reg1;
    FAPI_TRY( mss::rank::set_mirror_bits<2>(i_target, l_rp_reg, l_rank_group) );
    FAPI_TRY( mss::rank::set_mirror_bits<3>(i_target, l_rp_reg, l_rank_group) );

    // Register 2 contains RP0/1's tertiary/quaternary ranks - these are controlled by the rank group extension register
    l_rp_reg = l_rp_registers.iv_rp_reg2;
    FAPI_TRY( mss::rank::set_mirror_bits<0>(i_target, l_rp_reg, l_rank_group_ext) );
    FAPI_TRY( mss::rank::set_mirror_bits<1>(i_target, l_rp_reg, l_rank_group_ext) );

    // Register 3 contains RP2/3's tertiary/quaternary ranks - these are controlled by the rank group extension register
    l_rp_reg = l_rp_registers.iv_rp_reg3;
    FAPI_TRY( mss::rank::set_mirror_bits<2>(i_target, l_rp_reg, l_rank_group_ext) );
    FAPI_TRY( mss::rank::set_mirror_bits<3>(i_target, l_rp_reg, l_rank_group_ext) );

    // Configure the bits to be mirrored
    l_rank_group.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_A3_A4>();
    l_rank_group.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_A5_A6>();
    l_rank_group.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_A7_A8>();
    l_rank_group.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_A11_A13>();
    l_rank_group.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_BA0_BA1>();
    l_rank_group.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_BG0_BG1>();
    FAPI_TRY( write_rank_group(i_target, l_rank_group) );
    FAPI_TRY( write_rank_group_ext(i_target, l_rank_group_ext) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set rank mirror bits in RANK_GROUP register
/// @tparam RP rank pair (group) index
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to rankPairTraits<T, RP>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_rp_reg_value value of RANK_PAIR register
/// @param[in, out] io_data the register value
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t RP, fapi2::TargetType T, typename TT = rankPairTraits<T, RP> >
fapi2::ReturnCode set_mirror_bits( const fapi2::Target<T>& i_target,
                                   const fapi2::buffer<uint64_t>& i_rp_reg_value,
                                   fapi2::buffer<uint64_t>& io_data )
{
    uint64_t l_rank = 0;
    bool l_mirrored = false;

    // Even vs odd rank pairs are located in different parts of the register, so we check if we're dealing with an even or an odd rankpair
    if (mss::is_odd(RP))
    {
        i_rp_reg_value.extractToRight<ODD_PRIMARY_RANK, RANK_LEN>(l_rank);
        FAPI_TRY( is_mirrored(i_target, l_rank, i_rp_reg_value.getBit<ODD_PRIMARY_VALID>(), l_mirrored) );
        io_data.writeBit<TT::ADDR_MIRROR[0]>(l_mirrored);

        i_rp_reg_value.extractToRight<ODD_SECONDARY_RANK, RANK_LEN>(l_rank);
        FAPI_TRY( is_mirrored(i_target, l_rank, i_rp_reg_value.getBit<ODD_SECONDARY_VALID>(), l_mirrored) );
        io_data.writeBit<TT::ADDR_MIRROR[1]>(l_mirrored);
    }
    else
    {
        i_rp_reg_value.extractToRight<EVEN_PRIMARY_RANK, RANK_LEN>(l_rank);
        FAPI_TRY( is_mirrored(i_target, l_rank, i_rp_reg_value.getBit<EVEN_PRIMARY_VALID>(), l_mirrored) );
        io_data.writeBit<TT::ADDR_MIRROR[0]>(l_mirrored);

        i_rp_reg_value.extractToRight<EVEN_SECONDARY_RANK, RANK_LEN>(l_rank);
        FAPI_TRY( is_mirrored(i_target, l_rank, i_rp_reg_value.getBit<EVEN_SECONDARY_VALID>(), l_mirrored) );
        io_data.writeBit<TT::ADDR_MIRROR[1]>(l_mirrored);
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get a vector of configured rank pairs.
/// Returns a vector of ordinal values of the configured rank pairs. e.g., for a 2R DIMM, {0, 1}
/// @param[in]i_target  the target (MCA or MBA?)
/// @param[out] o_pairs std::vector of rank pairs configured
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode get_rank_pairs(const fapi2::Target<TARGET_TYPE_MCA>& i_target, std::vector<uint64_t>& o_pairs)
{
    // TODO RTC:160869 add enum for rank pair 0 when it gets created
    typedef rankPairTraits<fapi2::TARGET_TYPE_MCA, 0> RPT;

    uint64_t l_index = 0;
    std::vector<uint64_t> l_prs;
    uint16_t l_regs[RPT::NUM_RANK_PAIR_REGS] = {0};

    o_pairs.clear();

    // Get the count of rank pairs for both DIMM on the port
    std::vector<uint8_t> l_rank_count(MAX_DIMM_PER_PORT, 0);
    uint8_t l_dimm_type[MAX_DIMM_PER_PORT] = {};

    // Gets the DIMM type
    FAPI_TRY( mss::eff_dimm_type(i_target, &l_dimm_type[0]));

    for (const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        FAPI_TRY( mss::eff_num_master_ranks_per_dimm(d, l_rank_count[mss::index(d)]) );
    }

    // Get the override attribute setting
    FAPI_TRY( mss::eff_rank_group_override(i_target, l_regs) );

    // If the override attribute is zero, use the default assignments that correspond to the rank count
    if (l_regs[0] == 0)
    {
        const auto& l_primary_rank_pairs = dimm_type_value_select(l_dimm_type[0], lr_primary_rank_pairs, primary_rank_pairs);
        l_prs = l_primary_rank_pairs[l_rank_count[1]][l_rank_count[0]];

        // Walk through rank pair table and skip empty pairs
        // Can't use for (auto rp : l_prs) as rp is unused. BRS
        for (auto rp_iter = l_prs.begin(); rp_iter != l_prs.end(); ++rp_iter)
        {
            if (*rp_iter != NO_RANK)
            {
                o_pairs.push_back(l_index);
            }

            l_index += 1;
        }
    }
    // Else we have to derive the assignments from the override
    else
    {
        // Check RP0
        if (fapi2::buffer<uint64_t>(l_regs[0]).getBit<EVEN_PRIMARY_VALID>())
        {
            o_pairs.push_back(0);
        }

        // Check RP1
        if (fapi2::buffer<uint64_t>(l_regs[0]).getBit<ODD_PRIMARY_VALID>())
        {
            o_pairs.push_back(1);
        }

        // Check RP2
        if (fapi2::buffer<uint64_t>(l_regs[1]).getBit<EVEN_PRIMARY_VALID>())
        {
            o_pairs.push_back(2);
        }

        // Check RP3
        if (fapi2::buffer<uint64_t>(l_regs[1]).getBit<ODD_PRIMARY_VALID>())
        {
            o_pairs.push_back(3);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get a rank-pair id from a physical rank
/// Returns a number representing which rank-pair this rank is a part of
/// @param[in] i_target  the target (MCA or MBA?)
/// @param[in] i_rank the physical rank number
/// @param[out] o_pairs the rank pair
/// @return FAPI2_RC_SUCCESS if and only if ok, FAPI2_RC_INVALID_PARAMETER if the rank isn't found
///
template<>
fapi2::ReturnCode get_pair_from_rank(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                     uint64_t i_rank,
                                     uint64_t& o_pair)
{
    // Sort of brute-force, but no real good other way to do it. Given the
    // rank-pair configuration we walk the config looking for our rank, and
    // return the pair. This is always a small 'search' as there are only
    // 4 possible rank pair registers

    fapi2::buffer<uint64_t> l_rank_valid;
    uint64_t l_rank_pri = 0;
    uint64_t l_rank_sec = 0;
    uint64_t l_rank_ter = 0;
    uint64_t l_rank_qua = 0;
    rank_pair_data l_rp_registers;
    FAPI_TRY( get_rank_pair_assignments(i_target, l_rp_registers), "%s failed get_rank_pair_assignments",
              mss::c_str(i_target) );

    FAPI_DBG("%s seeing rank pair registers: RP0:0x%016lx RP1:0x%016lx RP2:0x%016lx RP3:0x%016lx, rank %d",
             mss::c_str(i_target), l_rp_registers.iv_rp_reg0, l_rp_registers.iv_rp_reg1,
             l_rp_registers.iv_rp_reg2, l_rp_registers.iv_rp_reg3, i_rank);

    // Check RP0
    l_rank_valid = l_rp_registers.iv_rp_reg0;
    l_rank_valid.extractToRight<EVEN_PRIMARY_RANK, RANK_LEN>(l_rank_pri);
    l_rank_valid.extractToRight<EVEN_SECONDARY_RANK, RANK_LEN>(l_rank_sec);

    if (((l_rank_valid.getBit<EVEN_PRIMARY_VALID>()) && (l_rank_pri == i_rank)) ||
        ((l_rank_valid.getBit<EVEN_SECONDARY_VALID>()) && (l_rank_sec == i_rank)))
    {
        o_pair = 0;
        return FAPI2_RC_SUCCESS;
    }

    l_rank_valid = l_rp_registers.iv_rp_reg2;
    l_rank_valid.extractToRight<EVEN_TERTIARY_RANK, RANK_LEN>(l_rank_ter);
    l_rank_valid.extractToRight<EVEN_QUATERNARY_RANK, RANK_LEN>(l_rank_qua);

    if (((l_rank_valid.getBit<EVEN_TERTIARY_VALID>()) && (l_rank_ter == i_rank)) ||
        ((l_rank_valid.getBit<EVEN_QUATERNARY_VALID>()) && (l_rank_qua == i_rank)))
    {
        o_pair = 0;
        return FAPI2_RC_SUCCESS;
    }

    // Check RP1
    l_rank_valid = l_rp_registers.iv_rp_reg0;
    l_rank_valid.extractToRight<ODD_PRIMARY_RANK, RANK_LEN>(l_rank_pri);
    l_rank_valid.extractToRight<ODD_SECONDARY_RANK, RANK_LEN>(l_rank_sec);

    if (((l_rank_valid.getBit<ODD_PRIMARY_VALID>()) && (l_rank_pri == i_rank)) ||
        ((l_rank_valid.getBit<ODD_SECONDARY_VALID>()) && (l_rank_sec == i_rank)))
    {
        o_pair = 1;
        return FAPI2_RC_SUCCESS;
    }

    l_rank_valid = l_rp_registers.iv_rp_reg2;
    l_rank_valid.extractToRight<ODD_TERTIARY_RANK, RANK_LEN>(l_rank_ter);
    l_rank_valid.extractToRight<ODD_QUATERNARY_RANK, RANK_LEN>(l_rank_qua);

    if (((l_rank_valid.getBit<ODD_TERTIARY_VALID>()) && (l_rank_ter == i_rank)) ||
        ((l_rank_valid.getBit<ODD_QUATERNARY_VALID>()) && (l_rank_qua == i_rank)))
    {
        o_pair = 1;
        return FAPI2_RC_SUCCESS;
    }

    // Check RP2
    l_rank_valid = l_rp_registers.iv_rp_reg1;
    l_rank_valid.extractToRight<EVEN_PRIMARY_RANK, RANK_LEN>(l_rank_pri);
    l_rank_valid.extractToRight<EVEN_SECONDARY_RANK, RANK_LEN>(l_rank_sec);

    if (((l_rank_valid.getBit<EVEN_PRIMARY_VALID>()) && (l_rank_pri == i_rank)) ||
        ((l_rank_valid.getBit<EVEN_SECONDARY_VALID>()) && (l_rank_sec == i_rank)))
    {
        o_pair = 2;
        return FAPI2_RC_SUCCESS;
    }

    l_rank_valid = l_rp_registers.iv_rp_reg3;
    l_rank_valid.extractToRight<EVEN_TERTIARY_RANK, RANK_LEN>(l_rank_ter);
    l_rank_valid.extractToRight<EVEN_QUATERNARY_RANK, RANK_LEN>(l_rank_qua);

    if (((l_rank_valid.getBit<EVEN_TERTIARY_VALID>()) && (l_rank_ter == i_rank)) ||
        ((l_rank_valid.getBit<EVEN_QUATERNARY_VALID>()) && (l_rank_qua == i_rank)))
    {
        o_pair = 2;
        return FAPI2_RC_SUCCESS;
    }

    // Check RP3
    l_rank_valid = l_rp_registers.iv_rp_reg1;
    l_rank_valid.extractToRight<ODD_PRIMARY_RANK, RANK_LEN>(l_rank_pri);
    l_rank_valid.extractToRight<ODD_SECONDARY_RANK, RANK_LEN>(l_rank_sec);

    if (((l_rank_valid.getBit<ODD_PRIMARY_VALID>()) && (l_rank_pri == i_rank)) ||
        ((l_rank_valid.getBit<ODD_SECONDARY_VALID>()) && (l_rank_sec == i_rank)))
    {
        o_pair = 3;
        return FAPI2_RC_SUCCESS;
    }

    l_rank_valid = l_rp_registers.iv_rp_reg3;
    l_rank_valid.extractToRight<ODD_TERTIARY_RANK, RANK_LEN>(l_rank_ter);
    l_rank_valid.extractToRight<ODD_QUATERNARY_RANK, RANK_LEN>(l_rank_qua);

    if (((l_rank_valid.getBit<ODD_TERTIARY_VALID>()) && (l_rank_ter == i_rank)) ||
        ((l_rank_valid.getBit<ODD_QUATERNARY_VALID>()) && (l_rank_qua == i_rank)))
    {
        o_pair = 3;
        return FAPI2_RC_SUCCESS;
    }

    // Rank not found
    return FAPI2_RC_INVALID_PARAMETER;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return a vector of rank numbers which represent the ranks for this dimm
/// @param[in] i_dimm_target TARGET_TYPE_DIMM
/// @param[out] o_ranks a vector of ranks for dimm (numbers)
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template<>
fapi2::ReturnCode ranks_on_dimm_helper<mss::mc_type::NIMBUS>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
        i_dimm_target,
        std::vector<uint64_t>& o_ranks)
{
    std::vector<uint64_t> l_ranks;
    FAPI_TRY( mss::rank::ranks(i_dimm_target, l_ranks) );
    o_ranks = l_ranks;

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace rank

} // namespace mss
