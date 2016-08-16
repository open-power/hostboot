/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mc/xlate.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file xlate.C
/// @brief Subroutines to manipulate the memory controller translation registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/mss_attribute_accessors.H>

#include <lib/mc/mc.H>
#include <lib/mc/xlate.H>
#include <lib/utils/scom.H>
#include <lib/utils/find.H>
#include <lib/dimm/kind.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{
namespace mc
{

/// A little vector of translators. We have one of these for each DIMM we support
static const std::vector<xlate_setup> xlate_map =
{
    // 2R4Gbx4 DDR4 RDIMM
    {
        dimm::kind(2, 0, 4, 4, fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM, 16, 16),
        xlate_dimm_2R4Gbx4
    },
    {
        dimm::kind(1, 0, 4, 4, fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4, fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM, 16, 8),
        xlate_dimm_1R4Gbx4
    },

};

///
/// @brief Helper to lay down the col and bank mappings.
/// @param[in] o_xlate1 a buffer representing the xlate register to modify
/// @param[in] o_xlate2 a buffer representing the xlate register to modify
/// @note This is for 16 bank DIMM, 32 bank DIMM will be different
///
static void column_and_16bank_helper(fapi2::buffer<uint64_t>& l_xlate1, fapi2::buffer<uint64_t>& l_xlate2)
{
    // These are compile time freebies, so there's no need to bother putting them in a pre-defined
    // constant and or-ing them in. Keeps things much more clear when the performance team wants to muck
    // around with the settings. Mappings taken directly from the Nimbus Workbook. The magic numbers
    // aren't; they're settings as defined in the scomdef

    l_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL4_BIT_MAP,
                             MCS_PORT02_MCP0XLT1_COL4_BIT_MAP_LEN>(0b01101);

    l_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL5_BIT_MAP,
                             MCS_PORT02_MCP0XLT1_COL5_BIT_MAP_LEN>(0b01100);

    l_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL6_BIT_MAP,
                             MCS_PORT02_MCP0XLT1_COL6_BIT_MAP_LEN>(0b01011);

    l_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL7_BIT_MAP,
                             MCS_PORT02_MCP0XLT1_COL7_BIT_MAP_LEN>(0b01010);

    l_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_COL8_BIT_MAP,
                             MCS_PORT02_MCP0XLT2_COL8_BIT_MAP_LEN>(0b01001);

    l_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_COL9_BIT_MAP,
                             MCS_PORT02_MCP0XLT2_COL9_BIT_MAP_LEN>(0b00111);

    l_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP,
                             MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP_LEN>(0b01110);

    l_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP,
                             MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP_LEN>(0b10000);

    l_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP,
                             MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP_LEN>(0b10001);

    l_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP,
                             MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP_LEN>(0b10010);
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in] o_xlate a buffer representing the xlate register to modify
/// @param[in] o_xlate1 a buffer representing the xlate register to modify
/// @param[in] o_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R4Gbx4 DDR4 RDIMM
///
void xlate_dimm_2R4Gbx4( const dimm::kind& i_kind,
                         const uint64_t i_offset,
                         const bool i_largest,
                         fapi2::buffer<uint64_t>& o_xlate,
                         fapi2::buffer<uint64_t>& o_xlate1,
                         fapi2::buffer<uint64_t>& o_xlate2 )
{
    // Set the proper bit if there is a DIMM in this slot. If there wasn't, we wouldn't see
    // this DIMM in the vector, so this is always safe.
    o_xlate.setBit(MCS_PORT02_MCP0XLT0_SLOT0_VALID + i_offset);

    // Check our master ranks, and enable the proper bits.
    // Note this seems a little backward. M0 is the left most bit, M1 the right most.
    // So, M1 changes for ranks 0,1 and M0 changes for ranks 3,4
    // 2 rank DIMM, so master bit 1 (least significant) bit needs to be mapped.
    o_xlate.setBit(MCS_PORT13_MCP0XLT0_SLOT0_M1_VALID + i_offset);
    o_xlate.insertFromRight<MCS_PORT02_MCP0XLT0_M1_BIT_MAP, MCS_PORT02_MCP0XLT0_M1_BIT_MAP_LEN>(0b01111);

    // Tell the MC which of the row bits are valid, and map the DIMM selector
    // We're a 16 row DIMM, so ROW15 is valid.
    o_xlate.setBit(MCS_PORT02_MCP0XLT0_SLOT0_ROW15_VALID + i_offset);
    o_xlate.insertFromRight<MCS_PORT02_MCP0XLT0_R15_BIT_MAP, MCS_PORT02_MCP0XLT0_R15_BIT_MAP_LEN>(0b00110);

    // Drop down the column assignments
    column_and_16bank_helper(o_xlate1, o_xlate2);

    // Setup the D-bit. If we're the largest DIMM, it is our mapping which maters.
    // Notice tht we don't care if the D-value bit has been set; this mapping needs to be setup regardless (SJ Powell says so)
    if (i_largest)
    {
        FAPI_INF("setting d-bit mapping (am largest) for %s", mss::c_str(i_kind.iv_target));
        o_xlate.insertFromRight(0b00101, MCS_PORT02_MCP0XLT0_D_BIT_MAP + i_offset, MCS_PORT02_MCP0XLT0_D_BIT_MAP_LEN);
    }
}


///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in] o_xlate a buffer representing the xlate register to modify
/// @param[in] o_xlate1 a buffer representing the xlate register to modify
/// @param[in] o_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R4Gbx4 DDR4 RDIMM
///
void xlate_dimm_1R4Gbx4( const dimm::kind& i_kind,
                         const uint64_t i_offset,
                         const bool i_largest,
                         fapi2::buffer<uint64_t>& o_xlate,
                         fapi2::buffer<uint64_t>& o_xlate1,
                         fapi2::buffer<uint64_t>& o_xlate2 )
{
    // 1R DIMM are special. We need to handle 2 1R DIMM on a port as a special case - kind of make them look like
    // a single 2R DIMM. So we have to do a little dance here to get our partners configuration.
    const auto& l_mca = mss::find_target<TARGET_TYPE_MCA>(i_kind.iv_target);
    const auto& l_dimms = mss::find_targets<TARGET_TYPE_DIMM>(l_mca);

    const std::vector<dimm::kind> l_dimm_kinds = dimm::kind::vector(l_dimms);
    bool l_all_slots_1R = false;

    // If we only have 1 DIMM, we don't have two slots with 1R DIMM. If we need to check, iterate
    // over the DIMM kinds and make sure all the DIMM have one master and zero slaves.
    if (l_dimms.size() > 1)
    {
        l_all_slots_1R = true;

        for (const auto& k : l_dimm_kinds)
        {
            l_all_slots_1R &= (k.iv_master_ranks == 1) && (k.iv_slave_ranks == 0);
        }

        FAPI_INF("We have a 1R DIMM and more than one DIMM installed; all 1R? %s",
                 (l_all_slots_1R == true ? "yes" : "no") );
    }

    // Set the proper bit if there is a DIMM in this slot. If there wasn't, we wouldn't see
    // this DIMM in the vector, so this is always safe.
    o_xlate.setBit(MCS_PORT02_MCP0XLT0_SLOT0_VALID + i_offset);

    // If we have all the slots filled in with 1R/0 slave DIMM, we build a very differnt mapping.
    if (l_all_slots_1R)
    {
        // Tell the MC which of the row bits are valid, and map the DIMM selector
        // We're a 16 row DIMM, so ROW15 is valid.
        o_xlate.setBit(MCS_PORT02_MCP0XLT0_SLOT0_ROW15_VALID + i_offset);
        o_xlate.insertFromRight<MCS_PORT02_MCP0XLT0_R15_BIT_MAP, MCS_PORT02_MCP0XLT0_R15_BIT_MAP_LEN>(0b00110);

        // Drop down the column assignments.
        column_and_16bank_helper(o_xlate1, o_xlate2);

        // Setup the D-bit. Since both DIMM are identical, we just need to setup the map
        FAPI_INF("setting d-bit mapping (all 1R DIMM) for %s", mss::c_str(i_kind.iv_target));
        o_xlate.insertFromRight<MCS_PORT02_MCP0XLT0_D_BIT_MAP, MCS_PORT02_MCP0XLT0_D_BIT_MAP_LEN>(0b01111);

        return;
    }

    // So if we're here we have only 1 1R DIMM installed. This translation is different.

    // Tell the MC which of the row bits are valid, and map the DIMM selector
    // We're a 16 row DIMM, so ROW15 is valid.
    o_xlate.setBit(MCS_PORT02_MCP0XLT0_SLOT0_ROW15_VALID + i_offset);
    o_xlate.insertFromRight<MCS_PORT02_MCP0XLT0_R15_BIT_MAP, MCS_PORT02_MCP0XLT0_R15_BIT_MAP_LEN>(0b00111);

    // We don't just drop down the col and bank assignments, they're different.
    o_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL4_BIT_MAP,
                             MCS_PORT02_MCP0XLT1_COL4_BIT_MAP_LEN>(0b01110);

    o_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL5_BIT_MAP,
                             MCS_PORT02_MCP0XLT1_COL5_BIT_MAP_LEN>(0b01101);

    o_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL6_BIT_MAP,
                             MCS_PORT02_MCP0XLT1_COL6_BIT_MAP_LEN>(0b01100);

    o_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL7_BIT_MAP,
                             MCS_PORT02_MCP0XLT1_COL7_BIT_MAP_LEN>(0b01011);

    o_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_COL8_BIT_MAP,
                             MCS_PORT02_MCP0XLT2_COL8_BIT_MAP_LEN>(0b01010);

    o_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_COL9_BIT_MAP,
                             MCS_PORT02_MCP0XLT2_COL9_BIT_MAP_LEN>(0b01001);

    o_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP,
                             MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP_LEN>(0b01111);

    o_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP,
                             MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP_LEN>(0b10000);

    o_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP,
                             MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP_LEN>(0b10001);

    o_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP,
                             MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP_LEN>(0b10010);

    // There's nothing to do for the D-bit. We're either not the largest DIMM, in which case the lrgest DIMM
    // will fix up our D-bit mapping, or we're the only DIMM in the port. If we're the only DIMM in the port,
    // there is no D-bit mapping for a 1 slot 1R DIMM.
    return;
}

///
/// @brief Perform initializations of the MC translation - MCA specialization
/// @param[in] i_target, the target which has the MCA to map
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode setup_xlate_map(const fapi2::Target<TARGET_TYPE_MCA>& i_target)
{
    fapi2::buffer<uint64_t> l_xlate;
    fapi2::buffer<uint64_t> l_xlate1;
    fapi2::buffer<uint64_t> l_xlate2;

    const auto l_dimms = i_target.getChildren<TARGET_TYPE_DIMM>();

    // We need to keep around specifications of both DIMM as we set the D bit based on the sizes of the DIMM
    std::vector<dimm::kind> l_dimm_kinds = dimm::kind::vector(l_dimms);

    FAPI_INF("Setting up xlate registers for MCA%d (%d)", mss::pos(i_target), mss::index(i_target));

    // Considering the DIMM, record who gets the D bit. We make sure the *smallest* DIMM has the highest address
    // range by setting it's D bit to 1. This eliminates, or reduces, holes in the memory map.
    // However, we need to set that DIMM's D bit in the location of the largest DIMM's D-bit map (I know that's
    // hard to grok - set the D bit in the smallest DIMM but in the location mapped for the largest.) So we
    // keep track of the largest DIMM so when we set it up, we make sure to set the D-bit in the other.
    std::sort(l_dimm_kinds.begin(), l_dimm_kinds.end(), [](const dimm::kind & a, const dimm::kind & b) -> bool
    {
        return a.iv_size > b.iv_size;
    });

    FAPI_INF("DIMM with the largest size on this port is %s %dR %dgbx%d (%dG)",
             mss::c_str(l_dimm_kinds[0].iv_target),
             l_dimm_kinds[0].iv_master_ranks, l_dimm_kinds[0].iv_dram_density,
             l_dimm_kinds[0].iv_dram_width, l_dimm_kinds[0].iv_size);

    const auto l_d_bit_target = l_dimm_kinds[0].iv_target;

    // Get the functional DIMM on this port.
    for (const auto& d : l_dimms)
    {
        // Our slot (0, 1) is the same as our general index.
        const uint64_t l_slot = mss::index(d);

        // Our slot offset tells us which 16 bit section in the xlt register to use for this DIMM
        // We'll either use the left most bits (slot 0) or move 16 bits to the right for slot 1.
        const uint64_t l_slot_offset = l_slot * 16;

        // Grab our kind out of the vector
        auto l_kind = std::find_if(l_dimm_kinds.begin(), l_dimm_kinds.end(), [&l_slot](const dimm::kind & k) -> bool
        {
            return mss::index(k.iv_target) == l_slot;
        });

        // If we don't find the fellow, we have a programming bug as we made the kind vector from the
        // vector we're iterating over.
        if (l_kind == l_dimm_kinds.end())
        {
            FAPI_ERR("can't find our dimm in the kind vector: l_slot %d %s", l_slot, mss::c_str(d));
            fapi2::Assert(false);
        }

        FAPI_DBG("address translation for DIMM %s %dR %dgbx%d (%dG) in slot %d",
                 mss::c_str(d), l_kind->iv_master_ranks, l_kind->iv_dram_density,
                 l_kind->iv_dram_width, l_kind->iv_size, l_slot);

        // Set the proper bit if there is a DIMM in this slot. If there wasn't, we wouldn't see
        // this DIMM in the vector, so this is always safe.
        l_xlate.setBit(MCS_PORT02_MCP0XLT0_SLOT0_VALID + l_slot_offset);

        // Find the proper set function based on this DIMM kind.
        const auto l_setup = std::find_if( xlate_map.begin(), xlate_map.end(), [l_kind](const xlate_setup & x) -> bool
        {
            return x.iv_kind == *l_kind;
        } );

        // If we're the smallest DIMM in the port and we have more than one DIMM, we set our D-bit.
        if( (l_d_bit_target != d) && (l_dimms.size() > 1) )
        {
            FAPI_INF("noting d-bit of 1 for %s", mss::c_str(d));
            l_xlate.setBit(MCS_PORT13_MCP0XLT0_SLOT0_D_VALUE + l_slot_offset);
        }

        // If we didn't find it, raise a stink.
        FAPI_ASSERT( l_setup != xlate_map.end(),
                     fapi2::MSS_NO_XLATE_FOR_DIMM().
                     set_DIMM_IN_ERROR(d).
                     set_MASTER_RANKS(l_kind->iv_master_ranks).
                     set_SLAVE_RANKS(l_kind->iv_slave_ranks).
                     set_DRAM_DENSITY(l_kind->iv_dram_density).
                     set_DRAM_WIDTH(l_kind->iv_dram_width).
                     set_DRAM_GENERATION(l_kind->iv_dram_generation).
                     set_DIMM_TYPE(l_kind->iv_dimm_type).
                     set_ROWS(l_kind->iv_rows).
                     set_SIZE(l_kind->iv_size),
                     "no address translation funtion for DIMM %s %dR %dgbx%d (%dG) in slot %d",
                     mss::c_str(d), l_kind->iv_master_ranks, l_kind->iv_dram_density,
                     l_kind->iv_dram_width, l_kind->iv_size, l_slot );

        // If we did find it, call the translation function to fill in the blanks.
        // The conditional argument tells the setup function whether this setup sould set the D bit, as we're
        // the largest DIMM on the port.
        l_setup->iv_func(*l_kind, l_slot_offset, (l_kind->iv_target == l_d_bit_target), l_xlate, l_xlate1, l_xlate2);
    }


    FAPI_INF("cramming 0x%016lx in for MCP0XLT0", l_xlate);
    FAPI_INF("cramming 0x%016lx in for MCP0XLT1", l_xlate1);
    FAPI_INF("cramming 0x%016lx in for MCP0XLT2", l_xlate2);

    FAPI_TRY( mss::putScom(i_target, MCA_MBA_MCP0XLT0, l_xlate)  );
    FAPI_TRY( mss::putScom(i_target, MCA_MBA_MCP0XLT1, l_xlate1) );
    FAPI_TRY( mss::putScom(i_target, MCA_MBA_MCP0XLT2, l_xlate2) );

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace mc
} // namespace mss
