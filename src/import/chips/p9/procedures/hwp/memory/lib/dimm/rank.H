/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/rank.H $   */
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
/// @file rank.H
/// @brief Do things with or for ranks
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_RANK_H_
#define _MSS_RANK_H_

#include <fapi2.H>
#include <lib/mss_attribute_accessors.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/utils/num.H>
#include <lib/utils/count_dimm.H>
#include <lib/shared/mss_const.H>

namespace mss
{

enum
{
    PRIMARY = 0,
    SECONDARY = 1,
    TERTIARY = 2,
    QUATERNARY = 3,
    NO_RANK = 999,

    // These enums represent the rank fields and valid bits from rank_pair_assignments
    EVEN_PRIMARY_RANK = 48,
    EVEN_SECONDARY_RANK = 52,
    ODD_PRIMARY_RANK = 56,
    ODD_SECONDARY_RANK = 60,
    RANK_LEN = 3,
    EVEN_PRIMARY_VALID = 51,
    EVEN_SECONDARY_VALID = 55,
    ODD_PRIMARY_VALID = 59,
    ODD_SECONDARY_VALID = 63,

};

///
/// @class rankPairTraits
/// @brief a collection of traits associated with rank pairs
/// @tparam T fapi2::TargetType representing the PHY
/// @tparam RP the rank pair
///
template< fapi2::TargetType T, uint64_t RP >
class rankPairTraits;

///
/// @class rankPairTraits
/// @brief a collection of traits associated with the Centaur PHY
///
template< uint64_t RP >
class rankPairTraits< fapi2::TARGET_TYPE_MBA, RP >
{
};

///
/// @class rankPairTraits
/// @brief a collection of traits associated with the Nimbus PHY rank pair 0
///
// TODO RTC:160869 Clean up rank utility functions, edd enums where appropriate
template<>
class rankPairTraits< fapi2::TARGET_TYPE_MCA, 0 >
{
    public:
        enum
        {
            NUM_RANK_PAIR_REGS = 2,
            NUM_RANKS_IN_PAIR = 4,
        };

        // MCA rank config registers
        constexpr static uint64_t RANK_GROUP = MCA_DDRPHY_PC_RANK_GROUP_P0;
        constexpr static uint64_t RANK_GROUP_EXT = MCA_DDRPHY_PC_RANK_GROUP_EXT_P0;
        static const std::vector< uint64_t > RANK_PAIR_REGS;

        // Mapping for which fields below (primary, secondary, ...) go into which regs
        static const std::vector< uint64_t > RANK_PAIR_FIELD_MAP;

        // MCA rank and valid fields.
        constexpr static const uint64_t RANK_PAIR_FIELDS[] =
        {
            MCA_DDRPHY_PC_RANK_PAIR0_P0_PRI,
            MCA_DDRPHY_PC_RANK_PAIR0_P0_SEC,
            MCA_DDRPHY_PC_RANK_PAIR2_P0_PAIR0_TER,
            MCA_DDRPHY_PC_RANK_PAIR2_P0_PAIR0_QUA,
        };
        constexpr static const uint64_t RANK_PAIR_LENGTHS[] =
        {
            MCA_DDRPHY_PC_RANK_PAIR0_P0_PRI_LEN,
            MCA_DDRPHY_PC_RANK_PAIR0_P0_SEC_LEN,
            MCA_DDRPHY_PC_RANK_PAIR2_P0_PAIR0_TER_LEN,
            MCA_DDRPHY_PC_RANK_PAIR2_P0_PAIR0_QUA_LEN,
        };
        constexpr static const uint64_t RANK_PAIR_VALIDS[] =
        {
            MCA_DDRPHY_PC_RANK_PAIR0_P0_PRI_V,
            MCA_DDRPHY_PC_RANK_PAIR0_P0_SEC_V,
            MCA_DDRPHY_PC_RANK_PAIR2_P0_PAIR0_TER_V,
            MCA_DDRPHY_PC_RANK_PAIR2_P0_PAIR0_QUA_V,
        };

        // PHY RANK_GROUP register ADDR_MIRROR fields, indexed by rank ordinal
        constexpr static const uint64_t ADDR_MIRROR[] =
        {
            MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_RP0_PRI,
            MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_RP0_SEC,
            MCA_DDRPHY_PC_RANK_GROUP_EXT_P0_ADDR_MIRROR_RP0_TER,
            MCA_DDRPHY_PC_RANK_GROUP_EXT_P0_ADDR_MIRROR_RP0_QUA,
        };
};

///
/// @class rankPairTraits
/// @brief a collection of traits associated with the Nimbus PHY rank pair 1
///
template<>
class rankPairTraits< fapi2::TARGET_TYPE_MCA, 1 >
{
    public:
        enum
        {
            NUM_RANK_PAIR_REGS = 2,
            NUM_RANKS_IN_PAIR = 4,
        };

        // MCA rank config registers
        static const std::vector< uint64_t > RANK_PAIR_REGS;

        // Mapping for which fields below (primary, secondary, ...) go into which regs
        static const std::vector< uint64_t > RANK_PAIR_FIELD_MAP;

        // MCA rank and valid fields.
        constexpr static const uint64_t RANK_PAIR_FIELDS[] =
        {
            MCA_DDRPHY_PC_RANK_PAIR0_P0_PAIR1_PRI,
            MCA_DDRPHY_PC_RANK_PAIR0_P0_PAIR1_SEC,
            MCA_DDRPHY_PC_RANK_PAIR2_P0_PAIR1_TER,
            MCA_DDRPHY_PC_RANK_PAIR2_P0_PAIR1_QUA,
        };
        constexpr static const uint64_t RANK_PAIR_LENGTHS[] =
        {
            MCA_DDRPHY_PC_RANK_PAIR0_P0_PAIR1_PRI_LEN,
            MCA_DDRPHY_PC_RANK_PAIR0_P0_PAIR1_SEC_LEN,
            MCA_DDRPHY_PC_RANK_PAIR2_P0_PAIR1_TER_LEN,
            MCA_DDRPHY_PC_RANK_PAIR2_P0_PAIR1_QUA_LEN,
        };
        constexpr static const uint64_t RANK_PAIR_VALIDS[] =
        {
            MCA_DDRPHY_PC_RANK_PAIR0_P0_PAIR1_PRI_V,
            MCA_DDRPHY_PC_RANK_PAIR0_P0_PAIR1_SEC_V,
            MCA_DDRPHY_PC_RANK_PAIR2_P0_PAIR1_TER_V,
            MCA_DDRPHY_PC_RANK_PAIR2_P0_PAIR1_QUA_V,
        };
        // PHY RANK_GROUP register ADDR_MIRROR fields, indexed by rank ordinal
        constexpr static const uint64_t ADDR_MIRROR[] =
        {
            MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_RP1_PRI,
            MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_RP1_SEC,
            MCA_DDRPHY_PC_RANK_GROUP_EXT_P0_ADDR_MIRROR_RP1_TER,
            MCA_DDRPHY_PC_RANK_GROUP_EXT_P0_ADDR_MIRROR_RP1_QUA,
        };
};

///
/// @class rankPairTraits
/// @brief a collection of traits associated with the Nimbus PHY rank pair 2
///
template<>
class rankPairTraits< fapi2::TARGET_TYPE_MCA, 2 >
{
    public:
        enum
        {
            NUM_RANK_PAIR_REGS = 2,
            NUM_RANKS_IN_PAIR = 4,
        };

        // MCA rank config registers
        static const std::vector< uint64_t > RANK_PAIR_REGS;

        // Mapping for which fields below (primary, secondary, ...) go into which regs
        static const std::vector< uint64_t > RANK_PAIR_FIELD_MAP;

        // MCA rank and valid fields.
        constexpr static const uint64_t RANK_PAIR_FIELDS[] =
        {
            MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR2_PRI,
            MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR2_SEC,
            MCA_DDRPHY_PC_RANK_PAIR3_P0_PAIR2_TER,
            MCA_DDRPHY_PC_RANK_PAIR3_P0_PAIR2_QUA,
        };
        constexpr static const uint64_t RANK_PAIR_LENGTHS[] =
        {
            MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR2_PRI_LEN,
            MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR2_SEC_LEN,
            MCA_DDRPHY_PC_RANK_PAIR3_P0_PAIR2_TER_LEN,
            MCA_DDRPHY_PC_RANK_PAIR3_P0_PAIR2_QUA_LEN,
        };
        constexpr static const uint64_t RANK_PAIR_VALIDS[] =
        {
            MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR2_PRI_V,
            MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR2_SEC_V,
            MCA_DDRPHY_PC_RANK_PAIR3_P0_PAIR2_TER_V,
            MCA_DDRPHY_PC_RANK_PAIR3_P0_PAIR2_QUA_V,
        };
        // PHY RANK_GROUP register ADDR_MIRROR fields, indexed by rank ordinal
        constexpr static const uint64_t ADDR_MIRROR[] =
        {
            MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_RP2_PRI,
            MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_RP2_SEC,
            MCA_DDRPHY_PC_RANK_GROUP_EXT_P0_ADDR_MIRROR_RP2_TER,
            MCA_DDRPHY_PC_RANK_GROUP_EXT_P0_ADDR_MIRROR_RP2_QUA,
        };
};

///
/// @class rankPairTraits
/// @brief a collection of traits associated with the Nimbus PHY rank pair 3
///
template<>
class rankPairTraits< fapi2::TARGET_TYPE_MCA, 3 >
{
    public:
        enum
        {
            NUM_RANK_PAIR_REGS = 2,
            NUM_RANKS_IN_PAIR = 4,
        };

        // MCA rank config registers
        static const std::vector< uint64_t > RANK_PAIR_REGS;

        // Mapping for which fields below (primary, secondary, ...) go into which regs
        static const std::vector< uint64_t > RANK_PAIR_FIELD_MAP;

        // MCA rank and valid fields.
        constexpr static const uint64_t RANK_PAIR_FIELDS[] =
        {
            MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR3_PRI,
            MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR3_SEC,
            MCA_DDRPHY_PC_RANK_PAIR3_P0_TER,
            MCA_DDRPHY_PC_RANK_PAIR3_P0_QUA,
        };
        constexpr static const uint64_t RANK_PAIR_LENGTHS[] =
        {
            MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR3_PRI_LEN,
            MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR3_SEC_LEN,
            MCA_DDRPHY_PC_RANK_PAIR3_P0_TER_LEN,
            MCA_DDRPHY_PC_RANK_PAIR3_P0_QUA_LEN,
        };
        constexpr static const uint64_t RANK_PAIR_VALIDS[] =
        {
            MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR3_PRI_V,
            MCA_DDRPHY_PC_RANK_PAIR1_P0_PAIR3_SEC_V,
            MCA_DDRPHY_PC_RANK_PAIR3_P0_TER_V,
            MCA_DDRPHY_PC_RANK_PAIR3_P0_QUA_V,
        };
        // PHY RANK_GROUP register ADDR_MIRROR fields, indexed by rank ordinal
        constexpr static const uint64_t ADDR_MIRROR[] =
        {
            MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_RP3_PRI,
            MCA_DDRPHY_PC_RANK_GROUP_P0_ADDR_MIRROR_RP3_SEC,
            MCA_DDRPHY_PC_RANK_GROUP_EXT_P0_ADDR_MIRROR_RP3_TER,
            MCA_DDRPHY_PC_RANK_GROUP_EXT_P0_ADDR_MIRROR_RP3_QUA,
        };
};

// TODO RTC:160717 Tidy up function names in mss::rank namespace
namespace rank
{

///
/// @brief Maps a rank's canonical number to the proper ordinal number for the PHY
/// @param[in] i_count the number of DIMM to be considered
/// @param[in] i_rank the rank number to be mapped
/// @return the mapped value
// i_rank passed by value to save a local variable in the caller
///
template <fapi2::TargetType T>
inline uint64_t map_rank_ordinal_to_phy( const size_t i_count, const uint64_t i_rank );

///
/// @brief Maps a rank's canonical number to the proper ordinal number for the PHY
/// @param[in] i_count the number of DIMM to be considered
/// @param[in] i_rank the rank number to be mapped
/// @return the mapped value
// i_rank passed by value to save a local
///
template <>
inline uint64_t map_rank_ordinal_to_phy<fapi2::TARGET_TYPE_MCA>( const size_t i_count, const uint64_t i_rank )
{
    if (i_count == 0)
    {
        FAPI_ERR("seeing 0 DIMM?");
        fapi2::Assert(false);
    }

    if ((i_count == MAX_DIMM_PER_PORT) && (i_rank >= RANK_MID_POINT))
    {
        return i_rank - MAX_RANKS_DIMM1;
    }

    // Nothing to do in the single drop case. Nothing to do for {0,1} on a dual drop either
    return i_rank;
}

///
/// @brief Maps a rank's canonical number to the proper ordinal number for the PHY
/// @param[in] i_target the fapi2 target of the MCA
/// @param[in] i_rank the rank number to be mapped
/// @return the mapped value
// i_rank passed by value to save a local
///
inline uint64_t map_rank_ordinal_to_phy( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, const uint64_t i_rank )
{
    return map_rank_ordinal_to_phy<fapi2::TARGET_TYPE_MCA>(count_dimm(i_target), i_rank);
}

///
/// @brief Maps a ranks canonical number to the proper ordinal number
/// for the PHY
/// @param[in] i_target the fapi2 target of the MBA
/// @param[in] i_rank the rank number to be mapped
/// @return the mapped value
// i_rank passed by value to save a local
///
inline uint64_t map_rank_ordinal_to_phy( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, const uint64_t i_rank )
{
    // NOOP for Centaur
    return i_rank;
}

///
/// @brief Maps a rank's canonical number from the proper ordinal number for the PHY
/// @param[in] i_count the number of DIMM to be considered
/// @param[in] i_rank the rank number to be mapped
/// @return the mapped value
// i_rank passed by value to save a local
///
template <fapi2::TargetType T>
inline uint64_t map_rank_ordinal_from_phy( const size_t i_count, const uint64_t i_rank );

///
/// @brief Maps a rank's canonical number from the proper ordinal number for the PHY
/// @param[in] i_count the number of DIMM to be considered
/// @param[in] i_rank the rank number to be mapped
/// @return the mapped value
// i_rank passed by value to save a local
///
template <>
inline uint64_t map_rank_ordinal_from_phy<fapi2::TARGET_TYPE_MCA>( const size_t i_count, const uint64_t i_rank )
{
    if (i_count == 0)
    {
        FAPI_ERR("seeing 0 DIMM?");
        fapi2::Assert(false);
    }

    if ((i_count == MAX_DIMM_PER_PORT) && ((i_rank + MAX_RANKS_DIMM1) >= RANK_MID_POINT))
    {
        return i_rank + MAX_RANKS_DIMM1;
    }

    // Nothing to do in the single drop case. Nothing to do for {0,1} on a dual drop either
    return i_rank;
}

///
/// @brief Maps a rank's canonical number from the proper ordinal number for the PHY
/// @param[in] i_target the fapi2 target of the MCA
/// @param[in] i_rank the rank number to be mapped
/// @return the mapped value
// i_rank passed by value to save a local
///
inline uint64_t map_rank_ordinal_from_phy( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rank )
{
    return map_rank_ordinal_from_phy<fapi2::TARGET_TYPE_MCA>(count_dimm(i_target), i_rank);
}

///
/// @brief Maps a ranks canonical number to the proper ordinal number
/// for the PHY
/// @param[in] i_target the fapi2 target of the MBA
/// @param[in] i_rank the rank number to be mapped
/// @return the mapped value
// i_rank passed by value to save a local
///
inline uint64_t map_rank_ordinal_from_phy( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        const uint64_t i_rank )
{
    // NOOP for Centaur
    return i_rank;
}

///
/// @brief Convert rank indexes in a rank_pair reg value from MC perspective to PHY perspective
/// @tparam T fapi2 Target Type the type of the MC target
/// @param[in] i_target the fapi2 target of the MCA
/// @param[in] i_count the number of DIMM to be considered
/// @param[in] i_rp_reg value of RANK_PAIR register
/// @param[in, out] io_data the register value with mapped rank indexes
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode map_rank_pair_to_phy( const fapi2::Target<T>& i_target,
        const size_t i_count,
        const fapi2::buffer<uint64_t>& i_rp_reg_value,
        fapi2::buffer<uint64_t>& io_data );


///
/// @brief Convert rank indexes in a rank_pair reg value from MC perspective to PHY perspective
/// @param[in] i_target the fapi2 target of the MCA
/// @param[in] i_count the number of DIMM to be considered
/// @param[in] i_rp_reg value of RANK_PAIR register
/// @param[in, out] io_data the register value with mapped rank indexes
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template<>
inline fapi2::ReturnCode map_rank_pair_to_phy( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const size_t i_count,
        const fapi2::buffer<uint64_t>& i_rp_reg_value,
        fapi2::buffer<uint64_t>& io_data )
{
    uint64_t l_rank = 0;

    FAPI_ASSERT(i_count != 0,
                fapi2::MSS_NO_DIMM_FOR_MAPPING()
                .set_MCA_TARGET(i_target)
                .set_FUNCTION(RANK_PAIR_TO_PHY),
                "%s Tried to map rank pairs on a port without any DIMMs",
                mss::c_str(i_target));

    // copy over so we get the valid bits
    io_data = i_rp_reg_value;

    // No mapping necessary if single drop
    if (i_count != 1)
    {
        i_rp_reg_value.extractToRight<EVEN_PRIMARY_RANK, RANK_LEN>(l_rank);
        l_rank = map_rank_ordinal_to_phy<fapi2::TARGET_TYPE_MCA>(i_count, l_rank);
        io_data.insertFromRight<EVEN_PRIMARY_RANK, RANK_LEN>(l_rank);

        i_rp_reg_value.extractToRight<EVEN_SECONDARY_RANK, RANK_LEN>(l_rank);
        l_rank = map_rank_ordinal_to_phy<fapi2::TARGET_TYPE_MCA>(i_count, l_rank);
        io_data.insertFromRight<EVEN_SECONDARY_RANK, RANK_LEN>(l_rank);

        i_rp_reg_value.extractToRight<ODD_PRIMARY_RANK, RANK_LEN>(l_rank);
        l_rank = map_rank_ordinal_to_phy<fapi2::TARGET_TYPE_MCA>(i_count, l_rank);
        io_data.insertFromRight<ODD_PRIMARY_RANK, RANK_LEN>(l_rank);

        i_rp_reg_value.extractToRight<ODD_SECONDARY_RANK, RANK_LEN>(l_rank);
        l_rank = map_rank_ordinal_to_phy<fapi2::TARGET_TYPE_MCA>(i_count, l_rank);
        io_data.insertFromRight<ODD_SECONDARY_RANK, RANK_LEN>(l_rank);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Convert rank indexes in a rank_pair reg value from MC perspective to PHY perspective
/// @param[in] i_target the fapi2 target of the MCA
/// @param[in] i_rp_reg value of RANK_PAIR register
/// @param[in, out] io_data the register value with mapped rank indexes
/// @return FAPI2_RC_SUCCESS iff all is ok
///
inline fapi2::ReturnCode map_rank_pair_to_phy( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const fapi2::buffer<uint64_t>& i_rp_reg_value,
        fapi2::buffer<uint64_t>& io_data )
{
    return map_rank_pair_to_phy(i_target, count_dimm(i_target), i_rp_reg_value, io_data);
}

///
/// @brief Convert rank indexes in a rank_pair reg value from MC perspective to PHY perspective
/// @param[in] i_target the fapi2 target of the MCA
/// @param[in] i_rp_reg value of RANK_PAIR register
/// @param[in, out] io_data the register value with mapped rank indexes
/// @return FAPI2_RC_SUCCESS iff all is ok
///
inline fapi2::ReturnCode map_rank_pair_to_phy( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        const fapi2::buffer<uint64_t>& i_rp_reg_value,
        fapi2::buffer<uint64_t>& io_data )
{
    // NOOP for Centaur
    io_data = i_rp_reg_value;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Convert rank indexes in a rank_pair reg value from PHY perspective to MC perspective
/// @tparam T fapi2 Target Type the type of the MC target
/// @param[in] i_target the fapi2 target of the MCA
/// @param[in] i_count the number of DIMM to be considered
/// @param[in] i_rp_reg value of RANK_PAIR register
/// @param[in, out] io_data the register value with mapped rank indexes
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode map_rank_pair_from_phy( const fapi2::Target<T>& i_target,
        const size_t i_count,
        const fapi2::buffer<uint64_t>& i_rp_reg_value,
        fapi2::buffer<uint64_t>& io_data );

///
/// @brief Convert rank indexes in a rank_pair reg value from PHY perspective to MC perspective
/// Specialization for TARGET_TYPE_MCA
/// @param[in] i_target the fapi2 target of the MCA
/// @param[in] i_count the number of DIMM to be considered
/// @param[in] i_rp_reg value of RANK_PAIR register
/// @param[in, out] io_data the register value with mapped rank indexes
/// @return FAPI2_RC_SUCCESS iff all is ok
///
template<>
inline fapi2::ReturnCode map_rank_pair_from_phy( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const size_t i_count,
        const fapi2::buffer<uint64_t>& i_rp_reg_value,
        fapi2::buffer<uint64_t>& io_data )
{
    uint64_t l_rank = 0;

    FAPI_ASSERT(i_count != 0,
                fapi2::MSS_NO_DIMM_FOR_MAPPING()
                .set_FUNCTION(RANK_PAIR_FROM_PHY)
                .set_MCA_TARGET(i_target),
                "Tried to map rank pairs on a port without any DIMMs");

    // copy over so we get the valid bits
    io_data = i_rp_reg_value;

    // No mapping necessary if single drop
    if (i_count != 1)
    {
        i_rp_reg_value.extractToRight<EVEN_PRIMARY_RANK, RANK_LEN>(l_rank);
        l_rank = map_rank_ordinal_from_phy<fapi2::TARGET_TYPE_MCA>(i_count, l_rank);
        io_data.insertFromRight<EVEN_PRIMARY_RANK, RANK_LEN>(l_rank);

        i_rp_reg_value.extractToRight<EVEN_SECONDARY_RANK, RANK_LEN>(l_rank);
        l_rank = map_rank_ordinal_from_phy<fapi2::TARGET_TYPE_MCA>(i_count, l_rank);
        io_data.insertFromRight<EVEN_SECONDARY_RANK, RANK_LEN>(l_rank);

        i_rp_reg_value.extractToRight<ODD_PRIMARY_RANK, RANK_LEN>(l_rank);
        l_rank = map_rank_ordinal_from_phy<fapi2::TARGET_TYPE_MCA>(i_count, l_rank);
        io_data.insertFromRight<ODD_PRIMARY_RANK, RANK_LEN>(l_rank);

        i_rp_reg_value.extractToRight<ODD_SECONDARY_RANK, RANK_LEN>(l_rank);
        l_rank = map_rank_ordinal_from_phy<fapi2::TARGET_TYPE_MCA>(i_count, l_rank);
        io_data.insertFromRight<ODD_SECONDARY_RANK, RANK_LEN>(l_rank);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Convert rank indexes in a rank_pair reg value from PHY perspective to MC perspective
/// @param[in] i_target the fapi2 target of the MCA
/// @param[in] i_rp_reg value of RANK_PAIR register
/// @param[in, out] io_data the register value with mapped rank indexes
/// @return FAPI2_RC_SUCCESS iff all is ok
///
inline fapi2::ReturnCode map_rank_pair_from_phy( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const fapi2::buffer<uint64_t>& i_rp_reg_value,
        fapi2::buffer<uint64_t>& io_data )
{
    return map_rank_pair_from_phy(i_target, count_dimm(i_target), i_rp_reg_value, io_data);
}

///
/// @brief Convert rank indexes in a rank_pair reg value from PHY perspective to MC perspective
/// @param[in] i_target the fapi2 target of the MCA
/// @param[in] i_rp_reg value of RANK_PAIR register
/// @param[in, out] io_data the register value with mapped rank indexes
/// @return FAPI2_RC_SUCCESS iff all is ok
///
inline fapi2::ReturnCode map_rank_pair_from_phy( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        const fapi2::buffer<uint64_t>& i_rp_reg_value,
        fapi2::buffer<uint64_t>& io_data )
{
    // NOOP for Centaur
    io_data = i_rp_reg_value;
    return fapi2::FAPI2_RC_SUCCESS;
}

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
/// @brief Return the DIMM target which posesses this rank on a given port
/// @tparam T the fapi2::TargetType of the port
/// @tparam D the fapi2::TargetType of the DIMM
/// @param[in] i_target the port target
/// @param[in] i_rank the rank number
/// @param[out] o_dimm the DIMM target
/// @return FAPI2_RC_SUCCESS iff all is ok, FAPI2_RC_INVALID_PARAMETER otherwise
///
template< fapi2::TargetType T, fapi2::TargetType D >
fapi2::ReturnCode get_dimm_target_from_rank(const fapi2::Target<T>& i_target,
        const uint64_t i_rank,
        fapi2::Target<D>& o_dimm);

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

///
/// @brief Read PC Rank Pair register
/// @tparam RP rank pair index
/// @tparam N register index
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to rankPairTraits<T, RP>
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t RP, uint64_t N, fapi2::TargetType T, typename TT = rankPairTraits<T, RP> >
inline fapi2::ReturnCode read_rank_pair_reg( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    fapi2::buffer<uint64_t> l_buf;
    static_assert((N < TT::NUM_RANK_PAIR_REGS), "Rank pair register index failed range check");
    FAPI_TRY( mss::getScom(i_target, TT::RANK_PAIR_REGS[N], l_buf) );
    FAPI_INF("read_rank_pair_reg: 0x%016lx", l_buf);
    FAPI_TRY( map_rank_pair_from_phy(i_target, l_buf, o_data) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write PC Rank Pair register
/// @tparam RP rank pair register index
/// @tparam N register index
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to rankPairTraits<T, RP>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t RP, uint64_t N, fapi2::TargetType T, typename TT = rankPairTraits<T, RP> >
inline fapi2::ReturnCode write_rank_pair_reg( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    fapi2::buffer<uint64_t> l_buf;
    static_assert((N < TT::NUM_RANK_PAIR_REGS), "Rank pair register index failed range check");
    FAPI_TRY( map_rank_pair_to_phy(i_target, i_data, l_buf) );
    FAPI_TRY( mss::putScom(i_target, TT::RANK_PAIR_REGS[N], l_buf) );
    FAPI_INF("write_rank_pair_reg: 0x%016lx", l_buf);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read PC Rank Group register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to rankPairTraits<T, 0>
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = rankPairTraits<T, 0> >
inline fapi2::ReturnCode read_rank_group( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::RANK_GROUP, o_data) );
    FAPI_INF("read_rank_group: 0x%016lx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write PC Rank Group register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to rankPairTraits<T, 0>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = rankPairTraits<T, 0> >
inline fapi2::ReturnCode write_rank_group( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_TRY( mss::putScom(i_target, TT::RANK_GROUP, i_data) );
    FAPI_INF("write_rank_group: 0x%016lx", i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Read PC Rank Group Extension register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to rankPairTraits<T, 0>
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = rankPairTraits<T, 0> >
inline fapi2::ReturnCode read_rank_group_ext( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::RANK_GROUP_EXT, o_data) );
    FAPI_INF("read_rank_group_ext: 0x%016lx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write PC Rank Group Extension register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to rankPairTraits<T, 0>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = rankPairTraits<T, 0> >
inline fapi2::ReturnCode write_rank_group_ext( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_TRY( mss::putScom(i_target, TT::RANK_GROUP_EXT, i_data) );
    FAPI_INF("write_rank_group_ext: 0x%016lx", i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_rank_field
/// @tparam RP rank pair (group) index
/// @tparam R rank index in pair (PRIMARY, SECONDARY, etc)
/// @tparam T fapi2 Target Type
/// @tparam TT traits type defaults to rankPairTraits<T, RP>
/// @param[in, out] io_data the register value
/// @param[in] i_value rank number
/// @note When configured for a protocol that only supports a single rank system, the rankpair 0 primary
///       rank must be set to 0
///
template< uint64_t RP, uint64_t R, fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = rankPairTraits<T, RP> >
inline void set_rank_field( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    static_assert((R < TT::NUM_RANKS_IN_PAIR), "Rank index failed range check");
    io_data.insertFromRight<TT::RANK_PAIR_FIELDS[R], TT::RANK_PAIR_LENGTHS[R]>(i_value);
    // also set valid field
    io_data.writeBit<TT::RANK_PAIR_VALIDS[R]>(mss::YES);

    FAPI_INF("set_rank_field (rp%d, r%d): 0x%01lx", RP, R, i_value);
}

///
/// @brief set_rank_field
/// @tparam RP rank pair (group) index
/// @tparam T fapi2 Target Type
/// @tparam TT traits type defaults to rankPairTraits<T, RP>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[i] i_rank rank index in pair (PRIMARY, SECONDARY, etc)
/// @param[in] i_value rank number
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note When configured for a protocol that only supports a single rank system, the rankpair 0 primary
///       rank must be set to 0
///
template< uint64_t RP, fapi2::TargetType T, typename TT = rankPairTraits<T, RP> >
inline fapi2::ReturnCode set_rank_field( const fapi2::Target<T>& i_target,
        fapi2::buffer<uint64_t>& io_data,
        const uint64_t i_rank,
        const uint64_t i_value )
{
    switch (i_rank)
    {
        case(0):
            set_rank_field<RP, 0>(io_data, i_value);
            return fapi2::FAPI2_RC_SUCCESS;

        case(1):
            set_rank_field<RP, 1>(io_data, i_value);
            return fapi2::FAPI2_RC_SUCCESS;

        case(2):
            set_rank_field<RP, 2>(io_data, i_value);
            return fapi2::FAPI2_RC_SUCCESS;

        case(3):
            set_rank_field<RP, 3>(io_data, i_value);
            return fapi2::FAPI2_RC_SUCCESS;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_RANK()
                         .set_RANK(i_rank)
                         .set_MCA_TARGET(i_target)
                         .set_FUNCTION(SET_RANK_FIELD),
                         "%s Invalid rank (%d) in set_rank_field",
                         mss::c_str(i_target),
                         i_rank);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief get_rank_field
/// @tparam RP rank pair (group) index
/// @tparam R rank index in pair (PRIMARY, SECONDARY, etc)
/// @tparam T fapi2 Target Type
/// @tparam TT traits type defaults to rankPairTraits<T, RP>
/// @param[in] i_data the register value
/// @param[out] o_value rank number
///
template< uint64_t RP, uint64_t R, fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = rankPairTraits<T, RP> >
inline void get_rank_field( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    static_assert((R < TT::NUM_RANKS_IN_PAIR), "Rank index failed range check");
    i_data.extractToRight<TT::RANK_PAIR_FIELDS[R], TT::RANK_PAIR_LENGTHS[R]>(o_value);

    FAPI_INF("get_rank_field (rp%d, r%d): 0x%01lx", RP, R, o_value);
}

///
/// @brief get_rank_field
/// @tparam RP rank pair (group) index
/// @tparam T fapi2 Target Type
/// @tparam TT traits type defaults to rankPairTraits<T, RP>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[i] i_rank rank index in pair (PRIMARY, SECONDARY, etc)
/// @param[out] o_value rank number
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t RP, fapi2::TargetType T, typename TT = rankPairTraits<T, RP> >
inline fapi2::ReturnCode get_rank_field( const fapi2::Target<T>& i_target,
        fapi2::buffer<uint64_t>& i_data,
        const uint64_t i_rank,
        uint64_t& o_value )
{
    switch (i_rank)
    {
        case(0):
            get_rank_field<RP, 0>(i_data, o_value);
            return fapi2::FAPI2_RC_SUCCESS;

        case(1):
            get_rank_field<RP, 1>(i_data, o_value);
            return fapi2::FAPI2_RC_SUCCESS;

        case(2):
            get_rank_field<RP, 2>(i_data, o_value);
            return fapi2::FAPI2_RC_SUCCESS;

        case(3):
            get_rank_field<RP, 3>(i_data, o_value);
            return fapi2::FAPI2_RC_SUCCESS;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_RANK()
                         .set_RANK(i_rank)
                         .set_MCA_TARGET(i_target)
                         .set_FUNCTION(GET_RANK_FIELD),
                         "%s Invalid rank (%d) in get_ranks_in_pair",
                         mss::c_str(i_target),
                         i_rank);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_pair_valid
/// @tparam RP rank pair (group) index
/// @tparam R rank index in pair (PRIMARY, SECONDARY, etc)
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to rankPairTraits<T, RP>
/// @param[in, out] io_data the register value
/// @param[in] i_state mss::YES or mss::NO - desired state
/// @note Indicates value in the RANK_PAIR field is valid
///
template< uint64_t RP, uint64_t R, fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = rankPairTraits<T, RP> >
inline void set_pair_valid( fapi2::buffer<uint64_t>& io_data, const mss::states i_state )
{
    static_assert((R < TT::NUM_RANKS_IN_PAIR), "Rank index failed range check");
    io_data.writeBit<TT::RANK_PAIR_VALIDS[R]>(i_state);

    FAPI_INF("set_pair_valid (rp%d, r%d): 0x%01lx", RP, R, i_state);
}

///
/// @brief set_pair_valid
/// @tparam RP rank pair (group) index
/// @tparam T fapi2 Target
/// @tparam TT traits type defaults to rankPairTraits<T, RP>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[in] i_rank rank index in pair (PRIMARY, SECONDARY, etc)
/// @param[in] i_state mss::YES or mss::NO - desired state
/// @note Indicates value in the RANK_PAIR field is valid
///
template< uint64_t RP, fapi2::TargetType T, typename TT = rankPairTraits<T, RP> >
inline fapi2::ReturnCode set_pair_valid( const fapi2::Target<T>& i_target,
        fapi2::buffer<uint64_t>& io_data,
        const uint64_t i_rank,
        const mss::states i_state )
{
    switch (i_rank)
    {
        case(0):
            set_pair_valid<RP, 0>(io_data, i_state);
            return fapi2::FAPI2_RC_SUCCESS;

        case(1):
            set_pair_valid<RP, 1>(io_data, i_state);
            return fapi2::FAPI2_RC_SUCCESS;

        case(2):
            set_pair_valid<RP, 2>(io_data, i_state);
            return fapi2::FAPI2_RC_SUCCESS;

        case(3):
            set_pair_valid<RP, 3>(io_data, i_state);
            return fapi2::FAPI2_RC_SUCCESS;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_RANK()
                         .set_RANK(i_rank)
                         .set_MCA_TARGET(i_target)
                         .set_FUNCTION(GET_RANKS_IN_PAIR),
                         "%s Invalid rank (%d) in get_ranks_in_pair",
                         mss::c_str(i_target),
                         i_rank);

    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief get_pair_valid
/// @tparam RP rank pair (group) index
/// @tparam R rank index in pair (PRIMARY, SECONDARY, etc)
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to rankPairTraits<T, RP>
/// @param[in] i_data the register value
/// @param[out] o_state mss::YES or mss::NO - representing the state of the field
/// @note Indicates value in the RANK_PAIR field is valid
///
template< uint64_t RP, uint64_t R, fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = rankPairTraits<T, RP> >
inline void get_pair_valid( const fapi2::buffer<uint64_t>& i_data, mss::states& o_state )
{
    static_assert((R < TT::NUM_RANKS_IN_PAIR), "Rank index failed range check");
    o_state = (i_data.getBit<TT::RANK_PAIR_VALIDS[R]>() == false) ? mss::NO : mss::YES;

    FAPI_INF("get_pair_valid (rp%d, r%d): 0x%01lx", RP, R, o_state);
}

///
/// @brief get_pair_valid
/// @tparam RP rank pair (group) index
/// @tparam T fapi2 Target Type
/// @tparam TT traits type defaults to rankPairTraits<T, RP>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[in] i_rank rank index in pair (PRIMARY, SECONDARY, etc)
/// @param[out] o_state mss::YES or mss::NO - representing the state of the field
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note Indicates value in the RANK_PAIR field is valid
///
template< uint64_t RP, fapi2::TargetType T, typename TT = rankPairTraits<T, RP> >
inline fapi2::ReturnCode get_pair_valid( const fapi2::Target<T> i_target,
        fapi2::buffer<uint64_t>& i_data,
        const uint64_t i_rank,
        mss::states& o_state )
{
    switch (i_rank)
    {
        case(0):
            get_pair_valid<RP, 0>(i_data, o_state);
            return fapi2::FAPI2_RC_SUCCESS;

        case(1):
            get_pair_valid<RP, 1>(i_data, o_state);
            return fapi2::FAPI2_RC_SUCCESS;

        case(2):
            get_pair_valid<RP, 2>(i_data, o_state);
            return fapi2::FAPI2_RC_SUCCESS;

        case(3):
            get_pair_valid<RP, 3>(i_data, o_state);
            return fapi2::FAPI2_RC_SUCCESS;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_RANK()
                         .set_RANK(i_rank)
                         .set_MCA_TARGET(i_target)
                         .set_FUNCTION(GET_PAIR_VALID),
                         "%s Invalid rank (%d) passed into get get_pair_valid",
                         mss::c_str(i_target),
                         i_rank);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_ranks_in_pair
/// @tparam RP rank pair (group) index
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to rankPairTraits<T, RP>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_ranks vector of rank numbers (primary, secondary, tertiary, quaternary)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note All ranks will be marked as valid in the pair, unless specified as enum NO_RANK
///
template< uint64_t RP, fapi2::TargetType T, typename TT = rankPairTraits<T, RP> >
fapi2::ReturnCode set_ranks_in_pair( const fapi2::Target<T>& i_target,
                                     const std::vector<uint64_t> i_ranks )
{
    // Read the rank pair register(s)
    fapi2::buffer<uint64_t> l_reg;
    std::vector<fapi2::buffer<uint64_t>> l_data;
    uint64_t l_ordinal = 0;

    FAPI_ASSERT( i_ranks.size() == TT::NUM_RANKS_IN_PAIR,
                 fapi2::MSS_INVALID_RANK_VECTOR_PASSED_IN()
                 .set_RANK_SIZE(i_ranks.size())
                 .set_MCA_TARGET(i_target)
                 .set_FUNCTION(SET_RANKS_IN_PAIR),
                 "%s Invalid vector of ranks passed in ",
                 mss::c_str(i_target));

    // Use the reg API here so we get the PHY to MC rank conversion
    FAPI_TRY( (mss::rank::read_rank_pair_reg< RP, 0 >(i_target, l_reg)) );
    l_data.push_back(l_reg);
    FAPI_TRY( (mss::rank::read_rank_pair_reg< RP, 1 >(i_target, l_reg)) );
    l_data.push_back(l_reg);

    // Modify
    for (const auto l_rank : i_ranks)
    {
        if (l_rank == NO_RANK)
        {
            FAPI_TRY( set_pair_valid<RP>(i_target, l_data.at(TT::RANK_PAIR_FIELD_MAP[l_ordinal]), l_ordinal, mss::NO) );
        }
        else
        {
            FAPI_TRY( set_rank_field<RP>(i_target, l_data.at(TT::RANK_PAIR_FIELD_MAP[l_ordinal]), l_ordinal, l_rank) );
        }

        ++l_ordinal;
    }

    // Use the reg API here so we get the MC to PHY rank conversion
    FAPI_TRY( (mss::rank::write_rank_pair_reg< RP, 0 >(i_target, l_data[0])) );
    FAPI_TRY( (mss::rank::write_rank_pair_reg< RP, 1 >(i_target, l_data[1])) );

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get the ordered list of ranks in a given pair
/// @tparam RP rank pair (group) index
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to rankPairTraits<T, RP>
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_ranks vector of rank numbers (primary, secondary, tertiary, quaternary)
/// @note Any ranks not marked as valid in the pair will be returned as enum NO_RANK
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< uint64_t RP, fapi2::TargetType T, typename TT = rankPairTraits<T, RP> >
fapi2::ReturnCode get_ranks_in_pair( const fapi2::Target<T>& i_target,
                                     std::vector<uint64_t>& o_ranks )
{
    static_assert(RP < MAX_RANK_PER_DIMM, "Passed in Rank Pair is too high");

    o_ranks.clear();

    // Read the rank pair register(s)
    fapi2::buffer<uint64_t> l_reg;
    std::vector<fapi2::buffer<uint64_t>> l_data;

    // Use the reg API here so we get the PHY to MC rank conversion
    FAPI_TRY( (mss::rank::read_rank_pair_reg< RP, 0 >(i_target, l_reg)) );
    l_data.push_back(l_reg);
    FAPI_TRY( (mss::rank::read_rank_pair_reg< RP, 1 >(i_target, l_reg)) );
    l_data.push_back(l_reg);

    // Get data
    for (uint64_t l_ordinal = 0; l_ordinal < TT::NUM_RANKS_IN_PAIR; ++l_ordinal)
    {
        // Check to make sure rank is vlaid
        FAPI_ASSERT( l_ordinal < MAX_RANK_PER_DIMM,
                     fapi2::MSS_INVALID_RANK()
                     .set_RANK(l_ordinal)
                     .set_MCA_TARGET(i_target)
                     .set_FUNCTION(GET_RANKS_IN_PAIR),
                     "%s Invalid rank (%d) in set_ranks_in_pair",
                     mss::c_str(i_target),
                     l_ordinal);


        mss::states l_state = mss::NO;

        FAPI_TRY( get_pair_valid<RP>(i_target, l_data.at(TT::RANK_PAIR_FIELD_MAP[l_ordinal]), l_ordinal, l_state) );

        if (l_state == mss::NO)
        {
            o_ranks.push_back(NO_RANK);
        }
        else
        {
            uint64_t l_rank = 0;
            FAPI_TRY( get_rank_field<RP>(i_target, l_data.at(TT::RANK_PAIR_FIELD_MAP[l_ordinal]), l_ordinal, l_rank) );
            o_ranks.push_back(l_rank);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get the ordered list of ranks in all pairs
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_ranks vector of vectors of rank numbers (primary, secondary, tertiary, quaternary)
/// @note Any ranks not marked as valid in the pair will be returned as enum NO_RANK
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode get_ranks_in_pairs( const fapi2::Target<T>& i_target,
                                      std::vector<std::vector<uint64_t>>& o_ranks )
{
    o_ranks.clear();
    std::vector<uint64_t> l_temp;

    FAPI_TRY( get_ranks_in_pair<0>( i_target, l_temp ) );
    o_ranks.push_back(l_temp);
    FAPI_TRY( get_ranks_in_pair<1>( i_target, l_temp ) );
    o_ranks.push_back(l_temp);
    FAPI_TRY( get_ranks_in_pair<2>( i_target, l_temp ) );
    o_ranks.push_back(l_temp);
    FAPI_TRY( get_ranks_in_pair<3>( i_target, l_temp ) );
    o_ranks.push_back(l_temp);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check whether a given rank needs to be mirrored
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_rank rank number
/// @param[in] i_valid true if the rank is valid
/// @param[out] o_mirrored true if rank needs to be mirrored
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode is_mirrored( const fapi2::Target<T>& i_target,
                               const uint64_t i_rank,
                               const bool i_valid,
                               bool& o_mirrored )
{
    uint8_t l_mirror[MAX_DIMM_PER_PORT] = {0};
    FAPI_TRY( eff_dimm_rcd_mirror_mode(i_target, l_mirror) );

    o_mirrored = false;

    // A rank is mirrored if all are true:
    //  - the rank is valid
    //  - the rank is odd
    //  - the mirror mode attribute is set for the rank's DIMM
    if (i_valid &&
        mss::is_odd(i_rank) &&
        (l_mirror[get_dimm_from_rank(i_rank)] == fapi2::ENUM_ATTR_EFF_DIMM_RCD_MIRROR_MODE_ON))
    {
        o_mirrored = true;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief get_ranks_in_pair
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] RP rank pair gets ranks in pairs
/// @param[out] o_ranks vector of rank numbers (primary, secondary, tertiary, quaternary)
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_ranks_in_pair( const fapi2::Target<T>& i_target,
        const uint64_t& i_rp,
        std::vector<uint64_t>& o_ranks )
{
    // Switches based upon the number of rank pairs
    switch(i_rp)
    {
        case 0:
            FAPI_TRY((get_ranks_in_pair<0, T>(i_target, o_ranks)));
            break;

        case 1:
            FAPI_TRY((get_ranks_in_pair<1, T>(i_target, o_ranks)));
            break;

        case 2:
            FAPI_TRY((get_ranks_in_pair<2, T>(i_target, o_ranks)));
            break;

        case 3:
            FAPI_TRY((get_ranks_in_pair<3, T>(i_target, o_ranks)));
            break;

        // Error case
        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_RANK_PAIR()
                         .set_RANK_PAIR(i_rp)
                         .set_FUNCTION(GET_RANKS_IN_PAIR)
                         .set_MCA_TARGET(i_target),
                         "%s Invalid number of rankpairs entered. num: %lu max: %lu",
                         mss::c_str(i_target),
                         i_rp,
                         MAX_PRIMARY_RANKS_PER_PORT);
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
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
                                   fapi2::buffer<uint64_t>& io_data );

} // namespace rank

} // namespace mss
#endif
