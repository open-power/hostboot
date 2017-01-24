/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/rank.C $   */
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
/// @file rank.C
/// @brief Manage dIMM ranks
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
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
// Index by [DIMM1 rank count][DIMM0 rank count] and first is the RANK_PAIR0 register,
// second is RANK_PAIR1.
//
// TODO RTC 160869: Review hard coded values, possibly make into traits?
static const std::vector< std::vector< std::pair< uint64_t, uint64_t > > > rank_pair_assignments =
{
    { {0x0000, 0x0000}, {0x1000, 0x0000}, {0x1030, 0x0000}, {0x1530, 0x0000}, {0x1537, 0x0000} },
    { {0x0000, 0x9000}, {0x1000, 0x9000}, {0x1030, 0x9000}, {0x1530, 0x9000}, {0x1537, 0x9000} },
    { {0x0000, 0x90B0}, {0x1000, 0x90B0}, {0x1030, 0x90B0}, {0x1530, 0x90B0}, {0x1537, 0x90B0} },
    { {0x0000, 0x9DB0}, {0x1000, 0x9DB0}, {0x1030, 0x9DB0}, {0x1530, 0x9DB0}, {0x1537, 0x9DB0} },
    { {0x0000, 0x9DBF}, {0x1000, 0x9DBF}, {0x1030, 0x9DBF}, {0x1530, 0x9DBF}, {0x1537, 0x9DBF} },
};

//
// Static table of vectors representing the master ranks, depending on the rank pair
// config. This table maps 1-1 to the table above, and allows us to skip the bit manipulation
// to figure out the master ranks. Note, no ranks means an empty vector ...
//
static const std::vector< std::vector< std::vector< uint64_t > > > primary_rank_pairs =
{
    { {},                       {0},                {0, 1},       {0, 1},       {0, 1} },
    { {NO_RANK, NO_RANK, 4},    {0, NO_RANK, 4},    {0, 1, 4},    {0, 1, 4},    {0, 1, 4} },
    { {NO_RANK, NO_RANK, 4, 5}, {0, NO_RANK, 4, 5}, {0, 1, 4, 5}, {0, 1, 4, 5}, {0, 1, 4, 5} },
    { {NO_RANK, NO_RANK, 4, 5}, {0, NO_RANK, 4, 5}, {0, 1, 4, 5}, {0, 1, 4, 5}, {0, 1, 4, 5} },
    { {NO_RANK, NO_RANK, 4, 5}, {0, NO_RANK, 4, 5}, {0, 1, 4, 5}, {0, 1, 4, 5}, {0, 1, 4, 5} },
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
    FAPI_ASSERT( (l_dimm_idx < l_dimms.size()),
                 fapi2::MSS_BAD_DIMM_INDEX_FOR_GIVEN_RANK()
                 .set_RANK(i_rank)
                 .set_DIMM_INDEX(l_dimm_idx)
                 .set_TARGET(i_target),
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
                 .set_TARGET(i_target),
                 "Couldn't find a DIMM to match given rank (%d) and DIMM position (%d): %s",
                 i_rank,
                 l_dimm_idx,
                 mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return a vector of rank numbers which represent the primary rank pairs for this port
/// @tparam T the target type
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

    FAPI_DBG("ranks: %d, %d", l_rank_count[0], l_rank_count[1]);

    // Walk through rank pair table and skip empty pairs
    o_rps.clear();

    for (const auto l_rank : primary_rank_pairs[l_rank_count[1]][l_rank_count[0]])
    {
        if (l_rank != NO_RANK)
        {
            o_rps.push_back(l_rank);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return a vector of rank numbers which represent the primary rank pairs for this dimm
/// @tparam T the target type
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
/// @tparam T the fapi2::TargetType
/// @param[in] i_target the target (MCA or MBA?)
/// @param[out] o_registers the regiter settings for the appropriate rank pairs
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode get_rank_pair_assignments(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
        std::pair<uint64_t, uint64_t>& o_registers)
{
    // TODO RTC:160869 add enum for rank pair 0 when it gets created
    typedef rankPairTraits<fapi2::TARGET_TYPE_MCA, 0> RPT;

    std::vector<uint8_t> l_rank_count(MAX_DIMM_PER_PORT, 0);
    uint16_t l_regs[RPT::NUM_RANK_PAIR_REGS] = {0};

    for (const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        FAPI_TRY( mss::eff_num_master_ranks_per_dimm(d, l_rank_count[mss::index(d)]) );
    }

    // Get the override attribute setting
    FAPI_TRY( mss::eff_rank_group_override(i_target, l_regs) );

    // If the override attribute is zero, use the default assignments that correspond to the rank count.
    // Need only to check the first array entry since we need a valid primary rank in RP0 due to plug rules.
    o_registers = (l_regs[0] == 0) ?
                  rank_pair_assignments[l_rank_count[1]][l_rank_count[0]] :
                  std::make_pair(static_cast<uint64_t>(l_regs[0]), static_cast<uint64_t>(l_regs[1]));

    FAPI_DBG("rank pair assignments for %s. [%d,%d] (0x%08llx, 0x%08llx)",
             mss::c_str(i_target), l_rank_count[1], l_rank_count[0], o_registers.first, o_registers.second);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Setup the rank information in the port
/// @tparam T the fapi2::TargetType
/// @param[in] i_target the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode set_rank_pairs(const fapi2::Target<TARGET_TYPE_MCA>& i_target)
{
    fapi2::buffer<uint64_t> l_rp_reg;
    fapi2::buffer<uint64_t> l_rank_group;

    // If a memory system consists of four or less ranks, each Rank Pair must contain one rank. Each rank has
    // unique configuration registers, calibration registers, and registers to store delay values. When a system
    // contains four or less ranks, each rank number used by the system must be loaded into one of the Primary
    // Rank fields.

    // Set the CSID to all 'unused' and we'll reset them as we configure rank pairs.
    // Note: Centaur configured this as 0xff00 all the time - it's unclear if we need
    // to set only the bits for the rank pairs configured, or whether 0xff00 will suffice. BRS
    fapi2::buffer<uint64_t> l_csid_data(0xFF00);

    std::pair<uint64_t, uint64_t> l_rp_registers;
    FAPI_TRY( get_rank_pair_assignments(i_target, l_rp_registers) );

    FAPI_DBG("setting rank pairs for %s. 0x%08llx, 0x%08llx csid: 0x%016llx",
             mss::c_str(i_target), l_rp_registers.first, l_rp_registers.second, l_csid_data);

    // need an extra pair of parens to make FAPI_TRY parsing work correctly
    FAPI_TRY( (mss::rank::write_rank_pair_reg< 0, 0 >(i_target, l_rp_registers.first)) );
    FAPI_TRY( (mss::rank::write_rank_pair_reg< 2, 0 >(i_target, l_rp_registers.second)) );
    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_PC_CSID_CFG_P0, l_csid_data) );

    // Set primary and secondary mirror in RANK_GROUP register.
    l_rp_reg = l_rp_registers.first;
    FAPI_TRY( mss::rank::set_mirror_bits<0>(i_target, l_rp_reg, l_rank_group) );
    FAPI_TRY( mss::rank::set_mirror_bits<1>(i_target, l_rp_reg, l_rank_group) );
    l_rp_reg = l_rp_registers.second;
    FAPI_TRY( mss::rank::set_mirror_bits<2>(i_target, l_rp_reg, l_rank_group) );
    FAPI_TRY( mss::rank::set_mirror_bits<3>(i_target, l_rp_reg, l_rank_group) );

    l_rank_group.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_A3_A4>();
    l_rank_group.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_A5_A6>();
    l_rank_group.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_A7_A8>();
    l_rank_group.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_A11_A13>();
    l_rank_group.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_BA0_BA1>();
    l_rank_group.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_BG0_BG1>();
    FAPI_TRY( write_rank_group(i_target, l_rank_group) );

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
/// @tparam T the fapi2::TargetType
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

    for (const auto& d : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        FAPI_TRY( mss::eff_num_master_ranks_per_dimm(d, l_rank_count[mss::index(d)]) );
    }

    // Get the override attribute setting
    FAPI_TRY( mss::eff_rank_group_override(i_target, l_regs) );

    // If the override attribute is zero, use the default assignments that correspond to the rank count
    if (l_regs[0] == 0)
    {
        l_prs = primary_rank_pairs[l_rank_count[1]][l_rank_count[0]];

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
/// @tparam T the fapi2::TargetType
/// @param[in] i_target  the target (MCA or MBA?)
/// @param[in] i_rank the physical rank number
/// @param[out] o_pairs the rank pair
/// @return FAPI2_RC_SUCCESS if and only if ok, FAPI2_RC_INVALID_PARAMETER if the rank isn't found
///
template<>
fapi2::ReturnCode get_pair_from_rank(const fapi2::Target<TARGET_TYPE_MCA>& i_target,
                                     uint64_t i_rank, uint64_t& o_pair)
{
    // Sort of brute-force, but no real good other way to do it. Given the
    // rank-pair configuration we walk the config looking for our rank, and
    // return the pair. This is always a small 'search' as there are only
    // 4 possible rank pair registers
    // TK this is a std::pair and needs to change to support 3DS

    fapi2::buffer<uint64_t> l_rank_valid;
    uint64_t l_rank_pri = 0;
    uint64_t l_rank_sec = 0;
    std::pair<uint64_t, uint64_t> l_rp_registers;
    FAPI_TRY( get_rank_pair_assignments(i_target, l_rp_registers) );

    FAPI_DBG("seeing rank pair registers: 0x%016lx 0x%016lx, rank %d",
             l_rp_registers.first, l_rp_registers.second, i_rank);

    // Check RP0
    l_rank_valid = l_rp_registers.first;
    l_rank_valid.extractToRight<EVEN_PRIMARY_RANK, RANK_LEN>(l_rank_pri);
    l_rank_valid.extractToRight<EVEN_SECONDARY_RANK, RANK_LEN>(l_rank_sec);

    if (((l_rank_valid.getBit<EVEN_PRIMARY_VALID>()) && (l_rank_pri == i_rank)) ||
        ((l_rank_valid.getBit<EVEN_SECONDARY_VALID>()) && (l_rank_sec == i_rank)))
    {
        o_pair = 0;
        return FAPI2_RC_SUCCESS;
    }

    // Check RP1
    l_rank_valid.extractToRight<ODD_PRIMARY_RANK, RANK_LEN>(l_rank_pri);
    l_rank_valid.extractToRight<ODD_SECONDARY_RANK, RANK_LEN>(l_rank_sec);

    if (((l_rank_valid.getBit<ODD_PRIMARY_VALID>()) && (l_rank_pri == i_rank)) ||
        ((l_rank_valid.getBit<ODD_SECONDARY_VALID>()) && (l_rank_sec == i_rank)))
    {
        o_pair = 1;
        return FAPI2_RC_SUCCESS;
    }

    // Check RP2
    l_rank_valid = l_rp_registers.second;
    l_rank_valid.extractToRight<EVEN_PRIMARY_RANK, RANK_LEN>(l_rank_pri);
    l_rank_valid.extractToRight<EVEN_SECONDARY_RANK, RANK_LEN>(l_rank_sec);

    if (((l_rank_valid.getBit<EVEN_PRIMARY_VALID>()) && (l_rank_pri == i_rank)) ||
        ((l_rank_valid.getBit<EVEN_SECONDARY_VALID>()) && (l_rank_sec == i_rank)))
    {
        o_pair = 2;
        return FAPI2_RC_SUCCESS;
    }

    // Check RP3
    l_rank_valid.extractToRight<ODD_PRIMARY_RANK, RANK_LEN>(l_rank_pri);
    l_rank_valid.extractToRight<ODD_SECONDARY_RANK, RANK_LEN>(l_rank_sec);

    if (((l_rank_valid.getBit<ODD_PRIMARY_VALID>()) && (l_rank_pri == i_rank)) ||
        ((l_rank_valid.getBit<ODD_SECONDARY_VALID>()) && (l_rank_sec == i_rank)))
    {
        o_pair = 3;
        return FAPI2_RC_SUCCESS;
    }

    // Rank not found
    return FAPI2_RC_INVALID_PARAMETER;

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace rank

} // namespace mss
