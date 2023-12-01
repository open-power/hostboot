/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ccs/ody_row_repair.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
/// @file ody_row_repair.C
/// @brief API for DDR5 row repair HWP
///
// *HWP HWP Owner: Sneha Kadam <Sneha.Kadam1@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <fapi2.H>
#include <lib/shared/ody_consts.H>
#include <lib/ecc/ecc_traits_odyssey.H>
#include <lib/ccs/ody_ccs_traits.H>
#include <lib/mc/ody_port_traits.H>
#include <lib/mcbist/ody_mcbist_traits.H>
#include <lib/ccs/ody_row_repair.H>
#include <generic/memory/lib/ccs/ccs_ddr5_commands.H>
#include <lib/mcbist/ody_mcbist_traits.H>
#include <lib/dimm/ody_rank.H>

#include <generic/memory/lib/utils/buffer_ops.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <mss_generic_attribute_getters.H>
#include <ody_attribute_accessors_manual.H>
#include <mss_generic_system_attribute_getters.H>
#include <ody_scom_ody_odc.H>

#include <generic/memory/lib/utils/mcbist/gen_mss_memdiags.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

namespace row_repair
{

///
/// @brief Configures registers for ccs repair execution - Odyssey specialization
/// @param[in] i_mc_target The MC target
/// @param[in] i_mem_port_target The Mem Port target
/// @param[out] o_modeq_reg A buffer to return the original value of modeq
/// @return FAPI2_RC_SUCCESS iff okay
///
template <>
fapi2::ReturnCode config_ccs_regs<mss::mc_type::ODYSSEY>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_mc_target,
        const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_mem_port_target,
        fapi2::buffer<uint64_t>& o_modeq_reg)
{
    return mss::ccs::config_ccs_regs_for_concurrent<mss::mc_type::ODYSSEY>(i_mc_target, o_modeq_reg);
}

} // namespace row_repair

namespace ody
{

namespace row_repair
{

///
/// @brief Creates the DRAM bitmap for row repair on all DRAMS
/// @return the DRAM bitmap for repairs on all DRAMs
///
fapi2::buffer<uint64_t> select_all_drams_for_repair()
{
    fapi2::buffer<uint64_t> l_dram_bitmap;
    l_dram_bitmap.setBit<DRAM_START_BIT, DRAM_LEN>();
    l_dram_bitmap.invert();
    return l_dram_bitmap;
}

///
/// @brief Initializes the DRAM repair entry array with invalid entries
/// @param [in,out] io_repairs_per_dimm Array of repair enteries
///
void init_repair_entry_arr( REPAIR_ARR& io_repairs_per_dimm)
{
    for(uint8_t l_dimm_rank = 0; l_dimm_rank < mss::ody::MAX_RANK_PER_DIMM; l_dimm_rank++)
    {
        io_repairs_per_dimm[l_dimm_rank] = mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>();
    }
}

///
/// @brief Initializes the DRAM repair map with invalid entries per dimm
/// @param [in,out] io_repair_map Array of Array repair enteries per dimm
///
void init_repair_map(REPAIR_MAP& io_repair_map)
{
    for(uint8_t l_port_pos = 0; l_port_pos < mss::ody::MAX_DIMM_PER_OCMB; l_port_pos++)
    {
        init_repair_entry_arr(io_repair_map[l_port_pos]);
    }
}

///
/// @brief Retrieves number of DRAM on DIMM
/// @param[in] i_dram_width width of DRAM
/// @param[in,out] io_dram_num DRAM index
///
void get_dram_count(const uint8_t i_dram_width,
                    uint8_t& io_dram_num)
{
    io_dram_num = i_dram_width == fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4 ?
                  mss::ody::generic_consts::ODY_NUM_DRAM_X4 : mss::ody::generic_consts::ODY_NUM_DRAM_X8;
}

///
/// @brief Calculates appropriate byte and byte mask per DRAM width
/// @param[in] i_target i_target DIMM target
/// @param[in] i_dram_nibbles  DRAM nibbles
/// @param[in] i_dram_width  DRAM width
/// @param[in,out] io_byte  DRAM byte index
/// @param[in,out] io_mask  Byte mask
/// @return @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode get_dram_byte_mask(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint8_t i_dram_nibbles,
    const uint8_t i_dram_width,
    uint8_t& io_byte,
    uint8_t& io_mask
)
{
    constexpr size_t MASK_NIBBLE0 = 0xF0;
    constexpr size_t MASK_NIBBLE1 = 0x0F;

    // Grabs the numeric DRAM instance and ensures that the DRAM is inbounds
    io_byte = (i_dram_width == fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X8) ?
              i_dram_nibbles :
              i_dram_nibbles / mss::NIBBLES_PER_BYTE;

    if (i_dram_width == fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4)
    {
        io_mask = mss::is_odd(i_dram_nibbles) ? MASK_NIBBLE1 : MASK_NIBBLE0;
    }
    else if(i_dram_width == fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X8)
    {
        io_mask = 0xFF;
    }

    return fapi2::current_err;
}

///
/// @brief Creates the DRAM bitmap for row repair
/// @param[in] i_dram the DRAM on which to conduct row repairs
/// @param[out] o_dram_bitmap the DRAM bitmap on which to conduct row repairs
/// @return FAPI2_RC_SUCCESS if and only if ok
///
// TODO:ZEN:MST-2263 Update Odyssey row repair to support x8 DIMM
fapi2::ReturnCode create_dram_bitmap(const uint64_t i_dram, fapi2::buffer<uint64_t>& o_dram_bitmap)
{
    o_dram_bitmap.flush<1>();
    FAPI_TRY(o_dram_bitmap.clearBit(DRAM_START_BIT + i_dram));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Build a table of PPR row repairs from attribute data for a given DIMM
/// @param[in] i_target DIMM target
/// @param[in] i_row_repair_data array of row repair attribute values for the DIMM
/// @param[out] o_repairs_per_dimm array of row repair data buffers
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode build_row_repair_table(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_row_repair_data[mss::ody::MAX_RANK_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK],
        REPAIR_ARR& o_repairs_per_dimm)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    constexpr uint8_t MAX_BANK_GROUP = 8;
    constexpr uint8_t MAX_BANKS = 4;

    uint8_t l_num_dram = 0;
    uint8_t l_num_subrank = 0;

    // Determine repair data bounds
    uint8_t l_mranks = 0;
    uint8_t l_total_ranks = 0;
    uint8_t l_rows = 0;
    uint8_t l_dram_width = 0;
    FAPI_TRY( mss::attr::get_num_master_ranks_per_dimm(i_target, l_mranks) );
    FAPI_TRY( mss::attr::get_logical_ranks_per_dimm(i_target, l_total_ranks) );
    FAPI_TRY( mss::attr::get_dram_row_bits(i_target, l_rows) );
    FAPI_TRY( mss::attr::get_dram_width(i_target, l_dram_width) );

    // Clear repair entry array
    init_repair_entry_arr(o_repairs_per_dimm);

    get_dram_count(l_dram_width, l_num_dram);

    if (l_mranks != 0)
    {
        l_num_subrank = l_total_ranks / l_mranks;
    }

    for (uint8_t l_dimm_rank = 0; l_dimm_rank < l_mranks; ++l_dimm_rank)
    {
        fapi2::buffer<uint32_t> l_row_repair_data;

        // Convert each entry from an array of bytes into a fapi2::buffer
        for (uint8_t l_byte = 0; l_byte < ROW_REPAIR_BYTES_PER_RANK; ++l_byte)
        {
            FAPI_TRY(l_row_repair_data.insertFromRight(i_row_repair_data[l_dimm_rank][l_byte],
                     l_byte * BITS_PER_BYTE,
                     BITS_PER_BYTE));
        }

        FAPI_INF(TARGTIDFORMAT " row repair entry for rank%u 0x%08x", TARGTID, l_dimm_rank, l_row_repair_data);

        // Create repair entry
        mss::row_repair::repair_entry<mss::mc_type::ODYSSEY> l_entry(l_row_repair_data, l_dimm_rank);

        if (l_entry.is_valid())
        {
            const uint64_t MAX_ROW = 1 << l_rows;
            const uint64_t MAX_SRANK = 1 << l_num_subrank;

            // srank, BG, BA, and row address are used bit-reversed in the row repair commands,
            // so need to reverse them to print and do boundary checking
            fapi2::buffer<uint32_t> l_logical_data;
            fapi2::buffer<uint32_t> l_original_data(l_entry.iv_bg);
            mss::swizzle < 32 - mss::ody::row_repair_data::ROW_REPAIR_BANK_GROUP_LEN,
                mss::ody::row_repair_data::ROW_REPAIR_BANK_GROUP_LEN,
                31 > (l_original_data, l_logical_data);
            const uint64_t l_logical_bg = l_logical_data;

            l_original_data.flush<0>();
            l_logical_data.flush<0>();
            l_original_data = l_entry.iv_bank;
            mss::swizzle < 32 - mss::ody::row_repair_data::ROW_REPAIR_BANK_LEN,
                mss::ody::row_repair_data::ROW_REPAIR_BANK_LEN,
                31 > (l_original_data, l_logical_data);
            const uint64_t l_logical_bank = l_logical_data;

            l_original_data.flush<0>();
            l_logical_data.flush<0>();
            l_original_data = l_entry.iv_row;
            mss::swizzle < 32 - ROW_REPAIR_ROW_ADDR_LEN,
                ROW_REPAIR_ROW_ADDR_LEN,
                31 > (l_original_data, l_logical_data);
            const uint64_t l_logical_row = l_logical_data;

            l_original_data.flush<0>();
            l_logical_data.flush<0>();
            l_original_data = l_entry.iv_srank;
            mss::swizzle < 32 - ROW_REPAIR_SRANK_LEN,
                ROW_REPAIR_SRANK_LEN,
                31 > (l_original_data, l_logical_data);
            const uint64_t l_logical_srank = l_logical_data;

            FAPI_INF_NO_SBE("Found valid row repair request in VPD for DIMM " TARGTIDFORMAT
                            ", DRAM %d, mrank %d, srank %d, bg %d, bank %d, row 0x%05x",
                            TARGTID, l_entry.iv_dram, l_entry.iv_dimm_rank, l_logical_srank,
                            l_logical_bg, l_logical_bank, l_logical_row);

            FAPI_INF_NO_SBE("Maxes for dimm " TARGTIDFORMAT ": DRAM %d, mrank %d, srank %d, bg %d, bank %d, row 0x%05x",
                            TARGTID, l_num_dram, l_mranks, l_num_subrank,
                            MAX_BANK_GROUP, MAX_BANKS, MAX_ROW);

            // Do some sanity checking here
            FAPI_ASSERT((l_entry.iv_dram < l_num_dram) &&
                        (l_logical_srank < MAX_SRANK) &&
                        (l_logical_bg < MAX_BANK_GROUP) &&
                        (l_logical_bank < MAX_BANKS) &&
                        (l_logical_row < MAX_ROW),
                        fapi2::ODY_ROW_REPAIR_ENTRY_OUT_OF_BOUNDS().
                        set_DIMM_TARGET(i_target).
                        set_DRAM(l_entry.iv_dram).
                        set_DRAM_MAX(l_num_dram).
                        set_MRANK(l_dimm_rank).
                        set_SRANK(l_logical_srank).
                        set_SRANK_MAX(MAX_SRANK).
                        set_BANK_GROUP(l_logical_bg).
                        set_BANK_GROUP_MAX(MAX_BANK_GROUP).
                        set_BANK(l_logical_bank).
                        set_BANK_MAX(MAX_BANKS).
                        set_ROW(l_logical_row).
                        set_ROW_MAX(MAX_ROW),
#ifndef __PPE__
                        "%s SPD contained out of bounds row repair entry: DRAM: " TARGTIDFORMAT " MAX: %d mrank %d srank %d MAX: %d"
                        "bg %d MAX: %d bank %d MAX: %d row 0x%05x MAX: 0x%05x",
                        TARGTID, l_entry.iv_dram, l_num_dram, l_dimm_rank, l_logical_srank, MAX_SRANK,
                        l_logical_bg, MAX_BANK_GROUP, l_logical_bank, MAX_BANKS, l_logical_row, MAX_ROW

#else
                        TARGTIDFORMAT" SPD contained out of bounds row repair entry: DRAM: %d MAX: %d mrank %d"
                        TARGTID, l_entry.iv_dram, l_num_dram, l_dimm_rank

#endif
                       );
            // Insert row repair request into list
            o_repairs_per_dimm[l_dimm_rank] = l_entry;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Create an error log and return with a good error code if a valid row repair is found
/// @param[in] i_target the DIMM target
/// @param[in] i_repair the repair data to validate
/// @return successful error code
///
fapi2::ReturnCode log_repairs_disabled_errors(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair)
{
    FAPI_ASSERT((!i_repair.is_valid()),
                fapi2::ODY_ROW_REPAIR_WITH_MNFG_REPAIRS_DISABLED().
                set_DIMM_TARGET(i_target).
                set_DRAM(i_repair.iv_dram).
                set_MRANK(i_repair.iv_dimm_rank).
                set_SRANK(i_repair.iv_srank).
                set_BANK_GROUP(i_repair.iv_bg).
                set_BANK(i_repair.iv_bank).
                set_ROW(i_repair.iv_row),
#ifndef __PPE__
                TARGTIDFORMAT" Row repair valid but DRAM repairs are disabled for DRAM %d, mrank %d, subrank %d, bg %d, bank %d, row 0x%05x",
                TARGTID, i_repair.iv_dram, i_repair.iv_dimm_rank, i_repair.iv_srank, i_repair.iv_bg, i_repair.iv_bank,
                i_repair.iv_row
#else
                TARGTIDFORMAT" Row repair valid but DRAM repairs are disabled for DRAM %d, mrank %d, subrank %d",
                TARGTID, i_repair.iv_dram, i_repair.iv_dimm_rank, i_repair.iv_srank
#endif
               );
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // We've found a valid row repair - log it as predictive, so we get callouts in MFG test but don't fail out
    fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_PREDICTIVE);
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Swizzle CCS bits between two fapi2 buffers, and insert from source to destination
/// @param[in,out] io_repair the address repair information
///
void swizzle_repair_entry(mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& io_repair)
{
    // swizzle srank bits
    fapi2::buffer<uint8_t> l_temp_buffer_8_in(io_repair.iv_srank);
    fapi2::buffer<uint8_t> l_temp_buffer_8_out;
    swizzle<SRANK_START, SRANK_LEN, SRANK_LAST>( l_temp_buffer_8_in, l_temp_buffer_8_out );
    io_repair.iv_srank = l_temp_buffer_8_out;

    // swizzle bank group
    l_temp_buffer_8_in = io_repair.iv_bg;
    l_temp_buffer_8_out.flush<0>();
    swizzle<BG_START, BG_LEN, BG_LAST>( l_temp_buffer_8_in, l_temp_buffer_8_out );
    io_repair.iv_bg = l_temp_buffer_8_out;

    // swizzle bank
    l_temp_buffer_8_in = io_repair.iv_bank;
    l_temp_buffer_8_out.flush<0>();
    swizzle<BANK_START, BANK_LEN, BANK_LAST>( l_temp_buffer_8_in, l_temp_buffer_8_out );
    io_repair.iv_bank = l_temp_buffer_8_out;

    // swizzle row
    fapi2::buffer<uint32_t> l_temp_buffer_32_in(io_repair.iv_row);
    fapi2::buffer<uint32_t> l_temp_buffer_32_out;
    swizzle<ROW_START, ROW_LEN, ROW_LAST>( l_temp_buffer_32_in, l_temp_buffer_32_out );
    io_repair.iv_row = l_temp_buffer_32_out;
}

///
/// @brief Perform a sPPR row repair operation
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @param[in, out] io_program the ccs program to setup for row repair
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_sppr( const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                              const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair,
                              mss::ccs::program<mss::mc_type::ODYSSEY>& io_program)
{
    // Variable Declarations
    uint64_t l_freq = 0;

    // Use rank to determine ranks and targets
    // Get port rank and target
    const auto& l_port_target = i_rank_info.get_port_target();
    const auto& l_port_rank = i_rank_info.get_port_rank();

    // Get dimm rank and target
    const auto& l_dimm_target = i_rank_info.get_dimm_target();

    // Get the OCMB target
    const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    // Declare timings
    // tMRD value is taken from Table 20 of JEDEC spec revision JESD79-5B_v1.20
    const uint64_t tMRD = 34;
    // WL delay
    constexpr uint64_t WL = 128;

    uint8_t tRCD = 0;
    uint8_t tWR = 0;
    uint8_t tRP = 0;
    uint8_t l_odt_attr[4];

    // Commands and MR declarations
    constexpr uint8_t MR24_GUARD_KEY = 24;
    constexpr uint8_t MR23_PPR = 23;
    constexpr uint8_t ENABLE_SPPR = 0b00000010;
    constexpr uint8_t EXIT_SPPR = 0b00000000;

    // Copy and update the inputted class's address swizzle
    auto l_repair = i_repair;
    swizzle_repair_entry(l_repair);

    // Get timing from API and attributes
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRCD, l_port_target, tRCD) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TWR, l_port_target, tWR) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRP, l_port_target, tRP) );

    // Get freq from attributes:
    FAPI_TRY( mss::freq<mss::mc_type::ODYSSEY>(l_ocmb_target, l_freq),
              "Failed to retrieve freq values on ",
              GENTARGTIDFORMAT, GENTARGTID(l_ocmb_target) );

    // Get ODT bits for ccs
    FAPI_TRY( mss::attr::get_si_odt_wr(l_dimm_target, l_odt_attr) );
    // TODO: ZEN-MST1680: Add DDR5 CCS ODT functionality

    //-------------------------------
    // SPPR COMMAND:
    //-------------------------------

    // 0. Add des command - handled by CCS execute

    // 1. Back up data.
    //    For static:
    //      Repairs deployed as part of draminit_mc, are done before memory contains valid data.
    //      So no need to backup/restore data in this case.
    //    For dynamic:
    //       Repairs are performed during runtime.
    //       In this case the memory controller will clean up after the row repair
    // 2. Check shared hppr resource destination registers (MR 54, 55, 56, 57)
    //    TODO: ZEN-MST:2222 Check shared hppr/sppr resource destination registers for row repair

    // 3. Precharge_all(): Create instruction for precharge and add it to the instruction array.
    io_program.iv_instructions.push_back(mss::ccs::ddr5::precharge_all_command<mss::mc_type::ODYSSEY>(l_port_rank,
                                         l_repair.iv_srank, tRP));

    FAPI_MFG( "Running srank fix on dimm " GENTARGTIDFORMAT " with srank %d", GENTARGTID(l_dimm_target),
              i_repair.iv_srank );

    // 4. Enable sPPR using MR23 bits "OP[2:1]=01" and wait tMRD.
    io_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>(l_port_rank, MR23_PPR,
                                         ENABLE_SPPR, tMRD));

    // 5. Guard Key Sequence:
    io_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                         (l_port_rank, MR24_GUARD_KEY, GUARDKEY_SEQ_ONE, tMRD));

    io_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                         (l_port_rank, MR24_GUARD_KEY, GUARDKEY_SEQ_TWO, tMRD));

    io_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                         (l_port_rank, MR24_GUARD_KEY, GUARDKEY_SEQ_THREE, tMRD));

    io_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>
                                         (l_port_rank, MR24_GUARD_KEY, GUARDKEY_SEQ_FOUR, tMRD));

    // 6. ACT to failed bank/address
    io_program.iv_instructions.push_back(mss::ccs::ddr5::act_command<mss::mc_type::ODYSSEY>(l_port_rank, l_repair.iv_srank,
                                         l_repair.iv_bg, l_repair.iv_bank, l_repair.iv_row, tRCD));

    // Write + enable the data (and wait tPGM_sPPR => WL + 8 + tWR)
    {
        typedef ccsTraits<mss::mc_type::ODYSSEY> TT;
        constexpr auto BC_MODE = mss::states::OFF_N;
        constexpr auto PARTIAL_WRITE_MODE = mss::states::OFF_N;
        // The write to precharge delay is added after the data enables
        const uint64_t WR_TO_PRE_DELAY = 8 + tWR + WL;

        // 7. WR Command with dq bits low:
        auto l_inst_temp = mss::ccs::ddr5::wr_command<mss::mc_type::ODYSSEY>(l_port_rank, l_repair.iv_srank,
                           l_repair.iv_bg, l_repair.iv_bank, l_repair.iv_row, BC_MODE, PARTIAL_WRITE_MODE);
        fapi2::buffer<uint64_t> l_dram_bitmap;
        FAPI_TRY(create_dram_bitmap(l_repair.iv_dram, l_dram_bitmap));

        // Add the data to array 1
        l_inst_temp.arr1.template insertFromRight<TT::ARR1_READ_OR_WRITE_DATA, TT::ARR1_READ_OR_WRITE_DATA_LEN>(l_dram_bitmap);

        // 8. After WL, DQ[3:0] of the individual Target DRAM must be LOW for 8tCK
        // TODO: ZEN-MST1680: Add DDR5 CCS ODT functionality
        // update_ODT(l_idle = 0);
        FAPI_TRY(mss::ccs::ddr5::update_wr_to_wr_data_enable_timing<mss::mc_type::ODYSSEY>(l_port_target, l_inst_temp));
        io_program.iv_instructions.push_back(l_inst_temp);
        mss::ccs::ddr5::append_wr_data_enable_command<mss::mc_type::ODYSSEY>(l_port_rank, io_program.iv_instructions, false,
                WR_TO_PRE_DELAY);
    }

    // 9. PRE to Bank (and wait tPGM_Exit => tRP)
    // 10. Wait tRP to allow the DRAM to recognize repaired Row address (tRP comes from here)
    {
        // Delay for PRE command
        io_program.iv_instructions.push_back(mss::ccs::ddr5::precharge_bank_command<mss::mc_type::ODYSSEY>(l_port_rank,
                                             l_repair.iv_srank,
                                             l_repair.iv_bg, l_repair.iv_bank, tRP));
    }

    // 11. Exit sPPR with setting MR23 bit "OP[2:1]=00" and wait tMRD
    io_program.iv_instructions.push_back(mss::ccs::ddr5::mrw_command<mss::mc_type::ODYSSEY>(l_port_rank, MR23_PPR,
                                         EXIT_SPPR, tMRD));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform a sPPR row repair operation at runtime
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dynamic_row_repair( const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
                                      const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair)
{
    using CCS = ccsTraits<mss::mc_type::ODYSSEY>;
    using MCB = mss::mcbistTraits<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>;

    fapi2::buffer<uint64_t> l_modeq_reg;
    fapi2::buffer<uint64_t> l_mcbist_status;
    fapi2::buffer<uint64_t> l_ccs_status;
    fapi2::buffer<uint64_t> l_reg_data;
    bool l_poll_result = false;

    // Get port rank and target
    const auto& l_port_target = i_rank_info.get_port_target();

    // Get OCMB Target
    const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    // Create Program
    mss::ccs::program<mss::mc_type::ODYSSEY> l_program;

    // Add des command to ensure that there's no timing violations between a refresh and another command
    // The time for this is tRFC
    // This is 410ns -> 984 clocks. rounded up to 1000 for saftey
    // Note: assuming that we will not be in powerdown or selftime refresh as it's unclear what happens when a PDX/SRX is done on an idle DRAM
    constexpr uint16_t POWER_DOWN_EXIT_DELAY = 1000;
    l_program.iv_instructions.push_back(mss::ccs::ddr5::des_command<mss::mc_type::ODYSSEY>(POWER_DOWN_EXIT_DELAY));

    // Setup SPPR CCS program
    FAPI_TRY( setup_sppr(i_rank_info, i_repair, l_program),
              "Failed sppr program setup for dynamic_row_repair on ",
              GENTARGTIDFORMAT, GENTARGTID(l_port_target) );

    // Stop the CCS engine just for giggles - it might be running ...
    FAPI_TRY( mss::ccs::start_stop<mss::mc_type::ODYSSEY>(l_ocmb_target, mss::states::STOP),
              "Error stopping CCS engine before ccs::execution on ",
              GENTARGTIDFORMAT, GENTARGTID(l_ocmb_target) );

    // Verify that the in-progress bit has not been set for CCS, meaning no other CCS is running
    l_poll_result = mss::poll(l_ocmb_target, CCS::STATQ_REG, poll_parameters(),
                              [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("ccs statq (stop) " UINT64FORMAT ", remaining: %d", UINT64_VALUE(stat_reg), poll_remaining);
        // We're done polling when we see ccs is not in progress.
        return stat_reg.getBit<CCS::CCS_IN_PROGRESS>() != 1;
    });

    // Check that ccs is not being used after poll
    FAPI_ASSERT(l_poll_result == true,
                fapi2::ODY_ROW_REPAIR_CCS_STUCK_IN_PROGRESS().
                set_OCMB_TARGET(l_ocmb_target),
                GENTARGTIDFORMAT
                " CCS engine is in use and is not available for repair",
                GENTARGTID(l_ocmb_target));

    // Stop any ongoing MCBIST command
    FAPI_TRY( mss::memdiags::stop<mss::mc_type::ODYSSEY>(l_ocmb_target),
              "MCBIST engine failed to stop current command in progress on "
              GENTARGTIDFORMAT, GENTARGTID(l_ocmb_target) );

    // Verify that the in-progress bit has not been set for MCBIST, meaning the MCBIST is free
    l_poll_result = mss::poll(l_ocmb_target, MCB::STATQ_REG, poll_parameters(),
                              [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("mcbist statq (stop) ", UINT64FORMAT ", remaining: %d", UINT64_VALUE(stat_reg), poll_remaining);
        // We're done polling when we see mcbist is not in progress.
        return stat_reg.getBit<MCB::MCBIST_IN_PROGRESS>() != 1;
    });

    // Check that mcbist is not being used after poll
    FAPI_ASSERT(l_poll_result == true,
                fapi2::ODY_ROW_REPAIR_MCBIST_STUCK_IN_PROGRESS().
                set_OCMB_TARGET(l_ocmb_target),
                GENTARGTIDFORMAT
                " MCBIST failed to exit previous command and is not available for repair",
                GENTARGTID(l_ocmb_target));

    FAPI_INF(GENTARGTIDFORMAT " Deploying dynamic row repair", GENTARGTID(l_ocmb_target));

    // Configure CCS regs for execution
    FAPI_TRY( mss::ccs::config_ccs_regs_for_concurrent<mss::mc_type::ODYSSEY>(l_ocmb_target, l_modeq_reg ) );

    // Backup ODC_SRQ_MBA_FARB0Q value before running Concurrent CCS
    FAPI_TRY( mss::ccs::pre_execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb_target, l_reg_data) );

    // Run CCS via MCBIST for Concurrent CCS
    FAPI_TRY( mss::ccs::execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb_target, l_program, l_port_target) );

    // Restore ODC_SRQ_MBA_FARB0Q value after running Concurrent CCS
    FAPI_TRY( mss::ccs::post_execute_via_mcbist<mss::mc_type::ODYSSEY>(l_ocmb_target, l_reg_data) );

    // Revert CCS regs after execution
    FAPI_TRY( mss::ccs::revert_config_regs<mss::mc_type::ODYSSEY>(l_ocmb_target, l_modeq_reg) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Deploy enough PPR row repairs to test all spare rows
/// @param[in] i_target_ocmb ocmb target
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode activate_all_spare_rows(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_ocmb)
{
    FAPI_INF(GENTARGTIDFORMAT" Deploying row repairs to test all spare rows", GENTARGTID(i_target_ocmb));

    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target_ocmb))
    {
        constexpr bool REPAIR_VALID = 1;
        constexpr uint8_t DRAM_POS = 0;
        constexpr uint8_t BANK_POS = 0;

        uint8_t l_num_sranks = 0;

        // Set all DRAM select bits so we get repairs on all DRAMs
        const auto l_dram_bitmap = select_all_drams_for_repair();

        // Gets the rank info for this DIMM
        std::vector<mss::rank::info<mss::mc_type::ODYSSEY>> l_rank_infos;
        FAPI_TRY(ranks_on_dimm(l_dimm, l_rank_infos),
                 "Failed to retrieve ranks on dimm on " GENTARGTIDFORMAT,
                 GENTARGTID(l_dimm) );

        // Get dimm information
        FAPI_TRY(mss::ody::get_srank_count(l_dimm, l_num_sranks));

        // Loops thru RANKs
        for (const auto& l_rank_info : l_rank_infos)
        {
            const auto l_dimm_rank = l_rank_info.get_dimm_rank();

            for (uint8_t l_srank = 0; l_srank < l_num_sranks; ++l_srank)
            {
                // Note: setting row = rank so we don't use row0 for every repair
                uint32_t l_row = l_dimm_rank;

                // Note: DIMM can only support one repair per BG, so we loop on BG and use BA=0
                // TODO: ZEN:MST-2222 likely hit the limitation on allowed PPR resources while doing this
                for (uint8_t l_bg = 0; l_bg < mss::ody::MAX_BG_PER_DIMM; ++l_bg)
                {
                    mss::row_repair::repair_entry<mss::mc_type::ODYSSEY> l_repair(REPAIR_VALID, l_dimm_rank, DRAM_POS, l_srank, l_bg,
                            BANK_POS,
                            l_row);
#ifndef __PPE__
                    FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Deploying row repairs on rank %d, DRAM %d, subrank %d, bg %d, bank %d, row 0x%05x",
                                    GENTARGTID(l_dimm), l_dimm_rank, DRAM_POS, l_srank, l_bg, BANK_POS, l_row);
#else
                    FAPI_INF(GENTARGTIDFORMAT " Deploying row repairs on rank %d, DRAM %d, subrank %d",
                             GENTARGTID(l_dimm), l_dimm_rank, DRAM_POS, l_srank);
                    FAPI_INF(" bg %d, bank %d, row 0x%05x", l_bg, BANK_POS, l_row);
#endif
                    FAPI_TRY( standalone_row_repair(l_rank_info, l_repair),
                              "Failed standalone_row_repair on " GENTARGTIDFORMAT " rank %d",
                              GENTARGTID(l_dimm), l_dimm_rank );
                }
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets the number of bad bits on a DRAM for a given row repair
/// @param[in] i_target the DIMM target on which to operate
/// @param[in] i_row_repair_dram_byte the byte of data that contains the row repair's DRAM information
/// @param[in] i_bad_bits the array of bad bits for this rank
/// @param[out] o_num_bad_bits_for_dram the number of bad bits on this DRAM
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode get_num_bad_bits(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const uint8_t i_row_repair_dram_byte,
                                   const uint8_t i_bad_bits[BAD_DQ_BYTE_COUNT],
                                   uint8_t& o_num_bad_bits_for_dram)
{
    o_num_bad_bits_for_dram = 0;

    uint8_t l_dram = 0;
    const fapi2::buffer<uint8_t> l_buffer(i_row_repair_dram_byte);

    // Note: we're using the 0-31 values here;
    // however, the ones we want are on the first byte, so we should be ok
    l_buffer.extractToRight<mss::ROW_REPAIR_DRAM_POS, ROW_REPAIR_DRAM_POS_LEN>(l_dram);
    uint8_t l_byte = 0;

    // Mask assuming a x8 DRAM, so the whole byte
    uint8_t l_mask = 0xff;

    uint8_t l_dram_width = 0;
    FAPI_TRY( mss::attr::get_dram_width(i_target, l_dram_width) );

    FAPI_TRY(get_dram_byte_mask(i_target, l_dram, l_dram_width, l_byte, l_mask));

    // Protect our array index
    FAPI_ASSERT(l_byte < mss::BAD_DQ_BYTE_COUNT,
                fapi2::ODY_DRAM_INDEX_OUT_OF_BOUNDS().
                set_DIMM_TARGET(i_target).
                set_DRAM_WIDTH(l_dram_width).
                set_INDEX(l_dram),
                "DRAM index %d supplied to get_num_bad_bits is out of bounds on " TARGTIDFORMAT,
                l_dram, TARGTID);


    {
        const uint8_t l_bad_bits_on_dram = i_bad_bits[l_byte] & l_mask;
        o_num_bad_bits_for_dram = mss::bit_count(l_bad_bits_on_dram);
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Gets the row repair attribute and clears out any unneeded repairs
/// @param[in] i_target the DIMM target on which to operate
/// @param[out] o_row_repair_data the row repair data to process for this DIMM
/// @return FAPI2_RC_SUCCESS iff successful
/// @note Clears out the repairs if there is more than one bad bit on the DRAM that would be repaired
///
fapi2::ReturnCode clear_row_repairs_on_bad_dram(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t (&o_row_repair_data)[mss::ody::MAX_RANK_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK])
{
    constexpr uint8_t WHOLE_DRAM_BAD = 2;
    constexpr uint8_t ROW_REPAIR_CLEAR_VALUE = 0;
    constexpr uint8_t ROW_REPAIR_DRAM_BYTE = 0;
    constexpr uint8_t ROW_REPAIR_VALID_BYTE = 3;
    constexpr uint8_t ROW_REPAIR_VALID_BIT = 7;
    uint8_t l_bad_dq_bitmap[mss::ody::MAX_RANK_PER_DIMM][BAD_DQ_BYTE_COUNT] = {};
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_BAD_DQ_BITMAP, i_target, l_bad_dq_bitmap) );

    // Load row repair data for the dimm
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_ROW_REPAIR_DATA, i_target, o_row_repair_data) );

    // Loops through all of the possible ranks on this DIMM and checks the repair data
    for(uint8_t l_rank = 0; l_rank < mss::ody::MAX_RANK_PER_DIMM; ++l_rank)
    {
        const fapi2::buffer<uint8_t> l_repair_valid_data(o_row_repair_data[l_rank][ROW_REPAIR_VALID_BYTE]);

        // If this repair is not valid, skip it
        if(!l_repair_valid_data.getBit<ROW_REPAIR_VALID_BIT>())
        {
            continue;
        }

        // Otherwise, ensure that the row repair is on a DRAM that won't have to be spared or marked off
        // Note: DRAMs will have to be spared or marked off at two bad bits
        uint8_t l_num_bad_bits = 0;

        // Gets the number of bad bits for the DRAM associated with this repair data
        FAPI_TRY(get_num_bad_bits(i_target,
                                  o_row_repair_data[l_rank][ROW_REPAIR_DRAM_BYTE],
                                  l_bad_dq_bitmap[l_rank],
                                  l_num_bad_bits),
                 "Failed to retrieve number of bad bits on rank %d on " TARGTIDFORMAT,
                 l_rank, TARGTID);

        // If the whole DRAM would be called out as bad, then clear the row repair data associated
        // This way, we free up the row repair on this rank
        if(l_num_bad_bits >= WHOLE_DRAM_BAD)
        {
            std::fill(std::begin(o_row_repair_data[l_rank]), std::end(o_row_repair_data[l_rank]), ROW_REPAIR_CLEAR_VALUE);
        }
    }

    // Sets the row repair data
    // This way, any repairs that were freed can be cleaned up
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_ROW_REPAIR_DATA, i_target, o_row_repair_data) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Map all repair data to dimm target
/// @param[in] i_target_ocmb ocmb target
/// @param[out] o_repair_map the map to fill with repair pairs
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode map_repairs_per_dimm( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_ocmb,
                                        REPAIR_MAP& o_repair_map)
{
    // Clear map for new repairs
    init_repair_map(o_repair_map);

    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target_ocmb))
    {
        uint8_t l_row_repair_data[mss::ody::MAX_RANK_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK] = {0};
        REPAIR_ARR l_repairs_per_dimm;

        // Load row repair data for the dimm
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_ROW_REPAIR_DATA, l_dimm, l_row_repair_data) );

        // Clear out any repairs on bad DRAM
        // This way, we can use those row repairs again if needed
        FAPI_TRY( clear_row_repairs_on_bad_dram(l_dimm, l_row_repair_data),
                  "Failed to clear row repairs on " GENTARGTIDFORMAT,
                  GENTARGTID(l_dimm) );

        // Build repair table
        FAPI_TRY( build_row_repair_table(l_dimm, l_row_repair_data, l_repairs_per_dimm),
                  "Failed to build row repair table on " GENTARGTIDFORMAT,
                  GENTARGTID(l_dimm) );

        // Add dimm repairs to map
        const auto& l_port = mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(l_dimm);
        uint8_t l_port_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(l_port);

        for(uint8_t l_dimm_rank = 0; l_dimm_rank < mss::ody::MAX_RANK_PER_DIMM; l_dimm_rank++)
        {
            o_repair_map[l_port_pos][l_dimm_rank] = l_repairs_per_dimm[l_dimm_rank];
        }

    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Perform a sPPR row repair operation during the IPL
/// @param[in] i_rank_info rank info of the address to repair
/// @param[in] i_repair the address repair information
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode standalone_row_repair( const mss::rank::info<mss::mc_type::ODYSSEY>& i_rank_info,
        const mss::row_repair::repair_entry<mss::mc_type::ODYSSEY>& i_repair)
{
    using CCS = ccsTraits<mss::mc_type::ODYSSEY>;

    fapi2::buffer<uint64_t> l_modeq_reg;
    fapi2::buffer<uint64_t> l_mcbist_status;
    fapi2::buffer<uint64_t> l_ccs_status;
    fapi2::buffer<uint64_t> l_reg_data;
    bool l_poll_result = false;

    // Get port rank and target
    const auto& l_port_target = i_rank_info.get_port_target();

    // Get OCMB Target
    const auto& l_ocmb_target = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(l_port_target);

    // Create Program
    mss::ccs::program<mss::mc_type::ODYSSEY> l_program;

    // Add des command to ensure that there's no timing violations between a refresh and another command
    // The time for this is tRFC
    // This is 410ns -> 984 clocks. rounded up to 1000 for saftey
    // Note: assuming that we will not be in powerdown or selftime refresh as it's unclear what happens when a PDX/SRX is done on an idle DRAM
    constexpr uint16_t POWER_DOWN_EXIT_DELAY = 1000;
    l_program.iv_instructions.push_back(mss::ccs::ddr5::des_command<mss::mc_type::ODYSSEY>(POWER_DOWN_EXIT_DELAY));

    // Setup SPPR CCS program
    FAPI_TRY( setup_sppr(i_rank_info, i_repair, l_program),
              "Failed sppr program setup for dynamic_row_repair on "
              GENTARGTIDFORMAT, GENTARGTID(l_port_target) );

    // Stop the CCS engine just for giggles - it might be running ...
    FAPI_TRY( mss::ccs::start_stop<mss::mc_type::ODYSSEY>(l_ocmb_target, mss::states::STOP),
              "Error stopping CCS engine before ccs::execution on "
              GENTARGTIDFORMAT, GENTARGTID(l_ocmb_target) );

    // Verify that the in-progress bit has not been set for CCS, meaning no other CCS is running
    l_poll_result = mss::poll(l_ocmb_target, CCS::STATQ_REG, poll_parameters(),
                              [](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_INF("ccs statq (stop) " UINT64FORMAT ", remaining: %d", UINT64_VALUE(stat_reg), poll_remaining);
        // We're done polling when we see ccs is not in progress.
        return stat_reg.getBit<CCS::CCS_IN_PROGRESS>() != 1;
    });

    // Check that ccs is not being used after poll
    FAPI_ASSERT(l_poll_result == true,
                fapi2::ODY_ROW_REPAIR_CCS_STUCK_IN_PROGRESS().
                set_OCMB_TARGET(l_ocmb_target),
                GENTARGTIDFORMAT
                " CCS engine is in use and is not available for repair",
                GENTARGTID(l_ocmb_target));



    FAPI_INF(GENTARGTIDFORMAT " Deploying row repair using standalone CCS", GENTARGTID(l_ocmb_target));

    // Configure CCS regs for execution
    FAPI_TRY( mss::ccs::config_ccs_regs_for_concurrent<mss::mc_type::ODYSSEY>(l_ocmb_target, l_modeq_reg ) );

    // Run CCS standalone execution
    FAPI_TRY( mss::ccs::execute<mss::mc_type::ODYSSEY>(l_ocmb_target, l_program, l_port_target) );

    // Revert CCS regs after execution
    FAPI_TRY( mss::ccs::revert_config_regs<mss::mc_type::ODYSSEY>(l_ocmb_target, l_modeq_reg) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Deploy mapped row repairs
/// @param[in] i_target ocmb target
/// @param[in] i_repair_map the map with repair data pairs
/// @param[in] i_runtime true if at runtime requiring dynamic
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode deploy_mapped_repairs(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const REPAIR_MAP& i_repair_map,
    const bool i_runtime )
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // Iterate through DRAM repairs structure
    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        uint8_t l_port_pos = mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>
                             (mss::find_target<fapi2::TARGET_TYPE_MEM_PORT>(l_dimm));

        // Loops thru repairs
        for (const auto& l_repair : i_repair_map[l_port_pos])
        {
            const auto& l_dimm_rank = l_repair.iv_dimm_rank;
            mss::rank::info<mss::mc_type::ODYSSEY> l_rank_info(l_dimm, l_dimm_rank, l_rc);
            const auto& l_port_rank = l_rank_info.get_port_rank();

            // Check rank info completed
            FAPI_TRY(l_rc, "Failed creating rank info " GENTARGTIDFORMAT, GENTARGTID(l_dimm));

            if (l_repair.is_valid())
            {
                // Deploy row repair and clear bad DQs
                FAPI_INF_NO_SBE(
                    GENTARGTIDFORMAT" Deploying row repair on DRAM %d, dimm rank %d, subrank %d, bg %d, bank %d, row 0x%05x",
                    GENTARGTID(l_dimm), l_repair.iv_dram, l_dimm_rank, l_repair.iv_srank, l_repair.iv_bg, l_repair.iv_bank,
                    l_repair.iv_row);

                // Check if at runtime for dynamic vs standalone
                if (i_runtime)
                {
                    FAPI_TRY( dynamic_row_repair(l_rank_info, l_repair),
                              "Failed dynamic_row_repair on " GENTARGTIDFORMAT " rank %d",
                              GENTARGTID(l_dimm), l_dimm_rank );
                }
                else
                {
                    FAPI_TRY( standalone_row_repair(l_rank_info, l_repair),
                              "Failed standalone_row_repair on " GENTARGTIDFORMAT " rank %d",
                              GENTARGTID(l_dimm), l_dimm_rank );
                }

                // Clear bad DQ bits for this port, DIMM, rank that will be fixed by this row repair
                FAPI_INF_NO_SBE("Updating bad bits on DIMM " GENTARGTIDFORMAT
                                " , DRAM %d, port rank %d, subrank %d, bg %d, bank %d, row 0x%05x",
                                GENTARGTID(l_dimm), l_repair.iv_dram, l_port_rank, l_repair.iv_srank, l_repair.iv_bg,
                                l_repair.iv_bank, l_repair.iv_row);
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}



} // namespace row_repair
} // namespace ody
} // namespace mss
