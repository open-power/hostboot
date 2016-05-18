/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/mc/xlate.C $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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

#include <mss_attribute_accessors.H>

#include <lib/mc/mc.H>
#include <lib/utils/scom.H>
#include <lib/dimm/kind.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_PROC_CHIP;
using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

using fapi2::FAPI2_RC_SUCCESS;


namespace mss
{

///
/// @brief Perform initializations of the MC translation
/// @tparm P, the fapi2::TargetType of the port
/// @tparm TT, the typename of the traits
/// @param[in] i_target, the target which has the MCA to map
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
template<>
fapi2::ReturnCode mc<TARGET_TYPE_MCS>::setup_xlate_map(const fapi2::Target<TARGET_TYPE_MCA>& i_target)
{
    fapi2::buffer<uint64_t> l_xlate;
    fapi2::buffer<uint64_t> l_xlate1;
    fapi2::buffer<uint64_t> l_xlate2;

    const auto l_dimms = i_target.getChildren<TARGET_TYPE_DIMM>();

    FAPI_INF("Setting up xlate registers for MCA%d (%d)", mss::pos(i_target), mss::index(i_target));

    // We enable the DIMM select bit for slot1 if we have two DIMM installed
    l_xlate.writeBit<MCS_PORT13_MCP0XLT0_SLOT1_D_VALUE>(l_dimms.size() == 2);

    // Get the functional DIMM on this port.
    for (auto d : l_dimms)
    {
        // Our slot (0, 1) is the same as our general index.
        const uint64_t l_slot = mss::index(d);

        // Our slot offset tells us which 16 bit section in the xlt register to use for this DIMM
        // We'll either use the left most bits (slot 0) or move 16 bits to the right for slot 1.
        const uint64_t l_slot_offset = l_slot * 16;

        // Get the translation array, based on this specific DIMM's config
        dimm::kind l_dimm(d);

        FAPI_DBG("address translation for DIMM %s %dR %dgbx%d in slot %d",
                 mss::c_str(d), l_dimm.iv_master_ranks, l_dimm.iv_dram_density, l_dimm.iv_dram_width, l_slot);


        // Set the proper bit if there is a DIMM in this slot. If there wasn't, we wouldn't see
        // this DIMM in the vector, so this is always safe.
        l_xlate.setBit(MCS_PORT02_MCP0XLT0_SLOT0_VALID + l_slot_offset);


        // Set the 12G DIMM bit if either DIMM is 12G
        // Is this correct? BRS
        l_xlate.writeBit<MCS_PORT13_MCP0XLT0_12GB_ENABLE>(l_dimm.iv_size == 12);

        // Check our master ranks, and enable the proper bits.
        // Note this seems a little backward. M0 is the left most bit, M1 the right most.
        // So, M1 changes for ranks 0,1 and M0 changes for ranks 3,4
        if (l_dimm.iv_master_ranks > 0)
        {
            l_xlate.setBit(MCS_PORT13_MCP0XLT0_SLOT0_M1_VALID + l_slot_offset);
        }

        if (l_dimm.iv_master_ranks > 2)
        {
            l_xlate.setBit(MCS_PORT13_MCP0XLT0_SLOT0_M0_VALID + l_slot_offset);
        }


        // Check slave ranks
        // Note this sems a little backward. S0 is the left-most slave bit. So,
        // if there are more than 0 slave ranks, S2 will increment first.
        if (l_dimm.iv_slave_ranks > 0)
        {
            l_xlate.setBit(MCS_PORT13_MCP0XLT0_SLOT0_S2_VALID + l_slot_offset);
        }

        if (l_dimm.iv_slave_ranks > 2)
        {
            l_xlate.setBit(MCS_PORT13_MCP0XLT0_SLOT0_S1_VALID + l_slot_offset);
        }

        if (l_dimm.iv_slave_ranks > 4)
        {
            l_xlate.setBit(MCS_PORT13_MCP0XLT0_SLOT0_S0_VALID + l_slot_offset);
        }


        // Tell the MC which of the row bits are valid, and map the DIMM selector
        if (l_dimm.iv_rows >= 16)
        {
            l_xlate.setBit(MCS_PORT02_MCP0XLT0_SLOT0_ROW15_VALID + l_slot_offset);
            l_xlate.insertFromRight<MCS_PORT02_MCP0XLT0_R15_BIT_MAP, MCS_PORT02_MCP0XLT0_R15_BIT_MAP_LEN>(0b00110);
            l_xlate.insertFromRight<MCS_PORT02_MCP0XLT0_D_BIT_MAP, MCS_PORT02_MCP0XLT0_D_BIT_MAP_LEN>(0b00101);
        }

        if (l_dimm.iv_rows >= 17)
        {
            l_xlate.setBit(MCS_PORT02_MCP0XLT0_SLOT0_ROW16_VALID + l_slot_offset);
            l_xlate.insertFromRight<MCS_PORT02_MCP0XLT0_R16_BIT_MAP, MCS_PORT02_MCP0XLT0_R16_BIT_MAP_LEN>(0b00101);
            l_xlate.insertFromRight<MCS_PORT02_MCP0XLT0_D_BIT_MAP, MCS_PORT02_MCP0XLT0_D_BIT_MAP_LEN>(0b00100);
        }

        if (l_dimm.iv_rows >= 18)
        {
            l_xlate.setBit(MCS_PORT02_MCP0XLT0_SLOT0_ROW17_VALID + l_slot_offset);
            l_xlate.insertFromRight<MCS_PORT02_MCP0XLT0_R17_BIT_MAP, MCS_PORT02_MCP0XLT0_R17_BIT_MAP_LEN>(0b00100);
            l_xlate.insertFromRight<MCS_PORT02_MCP0XLT0_D_BIT_MAP, MCS_PORT02_MCP0XLT0_D_BIT_MAP_LEN>(0b00011);
        }

    }

    // TK: remove and make general in the loop above BRS

    // Two rank DIMM, so master bit 1 (least significant) bit needs to be mapped.
    l_xlate.insertFromRight<MCS_PORT02_MCP0XLT0_M1_BIT_MAP, MCS_PORT02_MCP0XLT0_M1_BIT_MAP_LEN>(0b01111);

    // Slot 1 isn't populated, so forget those bits for now.

    // DIMM bit map isn't exactly ignored for only one populated slot. It still needs to be
    // set in the map. Per S. Powell.
    // Master rank 0, 1 bit maps are ignored.
    // Row 16,17 bit maps are ignored.
    // Row 15 maps to Port Address bit 6


    // Drop down the column assignments
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

    FAPI_DBG("HACK: Cramming 0x%016lx in for MCP0XLT0", l_xlate);
    FAPI_DBG("HACK: Cramming 0x%016lx in for MCP0XLT1", l_xlate1);
    FAPI_DBG("HACK: Cramming 0x%016lx in for MCP0XLT2", l_xlate2);

    FAPI_TRY( mss::putScom(i_target, MCA_MBA_MCP0XLT0, l_xlate)  );
    FAPI_TRY( mss::putScom(i_target, MCA_MBA_MCP0XLT1, l_xlate1) );
    FAPI_TRY( mss::putScom(i_target, MCA_MBA_MCP0XLT2, l_xlate2) );

fapi_try_exit:
    return fapi2::current_err;
}


} // namespace
