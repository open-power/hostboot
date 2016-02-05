/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/dimm/rank.C $              */
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
/// @file rank.C
/// @brief Manage dIMM ranks
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include "../mss.H"

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{

//
// Static table of rank pair assignments. Some of thoem won't be valid depending on
// the plug rules (which may be OpenPOWER, IBM, etc.) Some also won't make sense
// -- 3 rank DIMM? -- but it doesn't take up much space and lord knows stranger things
// have happened ... Won't hurt to have this defined JustInCase(tm).
// Index by [DIMM1 rank count][DIMM0 rank count] and first is the RANK_PAIR0 register,
// second is RANK_PAIR1.
//
static const std::vector< std::vector< std::pair< uint64_t, uint64_t > > > rank_pair_assignments =
{
    { {0x0000, 0x0000}, {0x1000, 0x0000}, {0x1030, 0x0000}, {0x1030, 0x5000}, {0x1030, 0x5070} },
    { {0x9000, 0x0000}, {0x1090, 0x0000}, {0x1090, 0x3000}, {0x1090, 0x3050}, {0x1090, 0x5730} },
    { {0x90B0, 0x0000}, {0x1090, 0xB000}, {0x1090, 0x30B0}, {0x1390, 0x50B0}, {0x1390, 0x57B0} },
    { {0x90B0, 0xD000}, {0x1090, 0xB0D0}, {0x109B, 0x30D0}, {0x139B, 0x50D0}, {0x139B, 0x57D0} },
    { {0x90B0, 0xD0F0}, {0x1090, 0xB0DF}, {0x109B, 0x30DF}, {0x139B, 0x50DF}, {0x139B, 0x57DF} },
};

//
// Static table of vectors representing the master ranks, depending on the rank pair
// config. This table maps 1-1 to the table above, and allows us to skip the bit manipulation
// to figure out the master ranks. Note, no ranks means an empty vector ...
//
static const std::vector< std::vector< std::vector< uint64_t > > > primary_rank_pairs =
{
    { {},           {0},          {0, 1},       {0, 1, 2},    {0, 1, 2, 3} },
    { {4},          {0, 4},       {0, 4, 1},    {0, 4, 2, 1}, {0, 4, 2, 1} },
    { {4, 5},       {0, 4, 5},    {0, 4, 1, 5}, {0, 4, 2, 5}, {0, 4, 2, 5} },
    { {4, 5},       {0, 4, 5},    {0, 4, 1, 5}, {0, 4, 2, 5}, {0, 4, 2, 5} },
    { {4, 5, 6, 7}, {0, 4, 5, 6}, {0, 4, 1, 6}, {0, 4, 2, 6}, {0, 4, 2, 6} },
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
/// @brief Return a vector of rank numbers which represent the primary rank pairs for this dimm
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

    for (auto d : i_target.getChildren<TARGET_TYPE_DIMM>())
    {
        FAPI_TRY( mss::eff_num_ranks_per_dimm(d, l_rank_count[mss::index(d)]) );
    }

    o_rps = primary_rank_pairs[l_rank_count[1]][l_rank_count[0]];

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

    for (auto r : l_prs)
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
    uint8_t l_ranks;
    FAPI_TRY( eff_num_ranks_per_dimm(i_target, l_ranks) );

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

    for (auto d : i_target.getChildren<TARGET_TYPE_DIMM>())
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
/// @brief Setup the rank information in the port
/// @tparam T the fapi2::TargetType
/// @param[in] i_target the target (MCA or MBA?)
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode set_rank_pairs(const fapi2::Target<TARGET_TYPE_MCA>& i_target)
{
    // If a memory system consists of four or less ranks, each Rank Pair must contain one rank. Each rank has
    // unique configuration registers, calibration registers, and registers to store delay values. When a system
    // contains four or less ranks, each rank number used by the system must be loaded into one of the Primary
    // Rank fields.

    // Set the CSID to all 'unused' and we'll reset them as we configure rank pairs.
    // Note: Centaur configured this as 0xff00 all the time - it's unclear if we need
    // to set only the bits for the rank pairs configured, or whether 0xff00 will suffice. BRS
    fapi2::buffer<uint64_t> l_csid_data(0xFF00);

    fapi2::buffer<uint64_t> l_rp0_register;
    fapi2::buffer<uint64_t> l_rp1_register;

    // Get the count of rank pairs for all DIMM on the port
    std::vector<uint8_t> l_rank_count(MAX_DIMM_PER_PORT, 0);

    for (auto d : i_target.getChildren<TARGET_TYPE_DIMM>())
    {
        FAPI_TRY( mss::eff_num_ranks_per_dimm(d, l_rank_count[mss::index(d)]) );
    }

    l_rp0_register = rank_pair_assignments[l_rank_count[1]][l_rank_count[0]].first;
    l_rp1_register = rank_pair_assignments[l_rank_count[1]][l_rank_count[0]].second;

    FAPI_DBG("setting rank pairs for %s. [%d,%d] (0x%08llx, 0x%08llx) csid: 0x%016llx",
             mss::c_str(i_target), l_rank_count[1], l_rank_count[0], l_rp0_register, l_rp1_register, l_csid_data);

    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_PC_RANK_PAIR0_P0, l_rp0_register) );
    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_PC_RANK_PAIR1_P0, l_rp1_register) );
    FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_PC_CSID_CFG_P0, l_csid_data) );

    // HACK HACK HACK: put this in the code properly!! BRS
    {
        fapi2::buffer<uint64_t> l_fix_me;
        l_fix_me.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_RP1_PRI>();

        l_fix_me.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_A3_A4>();
        l_fix_me.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_A5_A6>();
        l_fix_me.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_A7_A8>();
        l_fix_me.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_A11_A13>();
        l_fix_me.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_BA0_BA1>();
        l_fix_me.setBit<MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_BG0_BG1>();
        FAPI_DBG("pc_rank_group: 0x%016llx", uint64_t(l_fix_me));
        FAPI_TRY( mss::putScom(i_target, MCA_DDRPHY_PC_RANK_GROUP_P0, l_fix_me) );
    }

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
    std::vector< uint64_t > l_prs;
    uint64_t l_index = 0;

    FAPI_TRY( primary_ranks(i_target, l_prs) );

    o_pairs.clear();

    // Can't use for (auto rp : l_prs) as rp is unused. BRS
    for (auto rp_iter = l_prs.begin(); rp_iter != l_prs.end(); ++rp_iter)
    {
        o_pairs.push_back(l_index);
        l_index += 1;
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace
