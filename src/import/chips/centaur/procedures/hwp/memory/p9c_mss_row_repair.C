/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_row_repair.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#include <p9c_mss_row_repair.H>
#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fld.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <p9c_mss_funcs.H>
#include <p9c_mss_ddr4_funcs.H>
#include <p9c_mss_rowRepairFuncs.H>
#include <p9c_dimmBadDqBitmapFuncs.H>
#include <map>

using namespace fapi2;

extern "C"
{
    /// @brief Perform a PPR row repair operation
    /// @param[in] i_target_mba mba target
    /// @param[in] i_port port for repair
    /// @param[in] i_mrank master rank of address to repair
    /// @param[in] i_srank slave rank of address to repair
    /// @param[in] i_bg bank group bits of address to repair
    /// @param[in] i_bank bank bits of address to repair
    /// @param[in] i_row row bits of address to repair
    /// @param[in] i_dram_bitmap bitmap of DRAMs selected for repair (b'1 to repair, b'0 to not repair)
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode p9c_mss_row_repair(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                         const uint8_t  i_port,
                                         const uint8_t  i_mrank,
                                         const uint8_t  i_srank,
                                         const uint8_t  i_bg,
                                         const uint8_t  i_bank,
                                         const uint32_t i_row,
                                         const uint32_t i_dram_bitmap)
    {
        constexpr uint64_t REFRESH_BIT = CEN_MBA_MBAREF0Q_CFG_REFRESH_ENABLE;
        constexpr uint32_t NUM_POLL = 10;
        constexpr uint32_t WAIT_TIMER = 1500;
        constexpr uint32_t ENABLE_PPR = 0x0020;
        constexpr uint32_t DISABLE_PPR = 0;
        constexpr uint8_t TMOD = 24;

        const std::vector<uint64_t> MR0_SHADOW_REGS =
        {
            CEN_MBA_DDRPHY_PC_MR0_PRI_RP0_P0,
            CEN_MBA_DDRPHY_PC_MR0_PRI_RP1_P0,
            CEN_MBA_DDRPHY_PC_MR0_PRI_RP2_P0,
            CEN_MBA_DDRPHY_PC_MR0_PRI_RP3_P0,
            CEN_MBA_DDRPHY_PC_MR0_PRI_RP0_P1,
            CEN_MBA_DDRPHY_PC_MR0_PRI_RP1_P1,
            CEN_MBA_DDRPHY_PC_MR0_PRI_RP2_P1,
            CEN_MBA_DDRPHY_PC_MR0_PRI_RP3_P1,
        };

        // MRS address sequence for sPPR setup
        // Note that we need to set a valid column address for these, so we use '0'
        const std::vector<access_address> l_mrs_addrs =
        {
            // Puts the DRAM into PPR mode
            {ENABLE_PPR, 0, i_mrank, i_srank, MRS4_BA, i_port},
            // Writes the guard key sequence to MR0 (4 commands)
            {0x0CFF, 0, i_mrank, i_srank, MRS0_BA, i_port},
            {0x07FF, 0, i_mrank, i_srank, MRS0_BA, i_port},
            {0x0BFF, 0, i_mrank, i_srank, MRS0_BA, i_port},
            {0x03FF, 0, i_mrank, i_srank, MRS0_BA, i_port},
        };

        const uint8_t l_bg_bank = (i_bank << 2) | i_bg;
        access_address l_addr = {i_row, 0, i_mrank, i_srank, l_bg_bank, i_port};
        fapi2::buffer<uint64_t> l_row;
        fapi2::buffer<uint64_t> l_bank;
        fapi2::buffer<uint64_t> l_saved_mr0;
        fapi2::buffer<uint64_t> l_reg_buffer;
        fapi2::buffer<uint64_t> l_dram_scratch;
        uint64_t l_write_pattern = 0;
        uint32_t l_instruction_number = 0;
        uint8_t l_refresh = 0;
        uint8_t l_dram_gen = 0;
        uint8_t l_dram_width = 0;
        uint8_t l_stack_type_u8array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_odt[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};

        uint8_t l_al = 0;
        uint8_t l_trcd = 0;
        uint8_t l_twr = 0;
        uint8_t l_cwl = 0;
        uint32_t l_trfc = 0;
        uint8_t l_pl = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target_mba,  l_dram_gen));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_ODT_WR, i_target_mba,  l_odt));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target_mba,  l_stack_type_u8array));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRCD, i_target_mba, l_trcd));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WR, i_target_mba, l_twr));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_AL, i_target_mba, l_al));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CWL, i_target_mba, l_cwl));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRFC, i_target_mba, l_trfc));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CA_PARITY_LATENCY, i_target_mba, l_pl));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target_mba, l_dram_width));

        // DDR3 doesn't support sPPR, so bail unless we're DDR4
        FAPI_ASSERT(l_dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4,
                    fapi2::CEN_MSS_ROW_REPAIR_NOT_SUPPORTED().
                    set_TARGET_MBA(i_target_mba).
                    set_PORT(i_port).
                    set_MRANK(i_mrank).
                    set_DRAM_GEN(l_dram_gen),
                    "%s Row repair is not supported on DDR3 parts. Port%d mrank%d is %s",
                    mss::c_str(i_target_mba), i_port, i_mrank, (l_dram_gen == 1 ? "DDR3" : "Unknown DRAM gen"));

        // Compute the CCS write pattern to select the desired DRAM(s)
        l_dram_scratch = i_dram_bitmap;
        l_dram_scratch.invert();
        l_dram_scratch.extractToRight<DRAM_START_BIT, DRAM_LEN>(l_write_pattern);

        // Save MR0 data before we write guard key sequence
        FAPI_TRY(fapi2::getScom(i_target_mba, MR0_SHADOW_REGS[0], l_saved_mr0));

        // Turn off refresh
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_reg_buffer));
        l_refresh = l_reg_buffer.getBit<REFRESH_BIT>();
        l_reg_buffer.clearBit<REFRESH_BIT>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_reg_buffer));

        // Precharge all ranks before we set sPPR mode
        FAPI_TRY(add_precharge_all_to_ccs(i_target_mba, l_addr, l_trcd, l_odt, l_stack_type_u8array, l_instruction_number));

        // Put the DRAM into sPPR mode
        for (auto l_mrs_addr : l_mrs_addrs)
        {
            FAPI_TRY(add_mrs_to_ccs_ddr4(i_target_mba, l_mrs_addr, TMOD, l_instruction_number));
        }

        // Enable CCS and set RAS/CAS/WE high during idles
        FAPI_DBG("%s Enabling CCS", mss::c_str(i_target_mba));
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_CCS_MODEQ, l_reg_buffer));
        FAPI_TRY(l_reg_buffer.setBit(29));    //Enable CCS
        FAPI_TRY(l_reg_buffer.setBit(52));    //RAS high
        FAPI_TRY(l_reg_buffer.setBit(53));    //CAS high
        FAPI_TRY(l_reg_buffer.setBit(54));    //WE high
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_CCS_MODEQ, l_reg_buffer));

        // Subtract one from the instruction count because set_end_bit increments it
        --l_instruction_number;
        FAPI_TRY(mss_ccs_set_end_bit(i_target_mba, l_instruction_number), "CCS_SET_END_BIT FAILED");

        // Execute the CCS program
        FAPI_DBG("%s Executing the CCS array", mss::c_str(i_target_mba));
        FAPI_TRY(mss_execute_ccs_inst_array(i_target_mba, NUM_POLL, WAIT_TIMER), " EXECUTE_CCS_INST_ARRAY FAILED");
        l_instruction_number = 0;

        // Restore the MR0 shadow regs
        for (const auto l_mr0_reg : MR0_SHADOW_REGS)
        {
            FAPI_TRY(fapi2::putScom(i_target_mba, l_mr0_reg, l_saved_mr0));
        }

        // Issue ACT command with bank and row fail address
        FAPI_TRY(add_activate_to_ccs(i_target_mba, l_addr, l_trcd, l_instruction_number));

        // Issue WR command with (tWR + WL + 10) cycles delay, values are the result of lab experimentation
        FAPI_TRY(add_write_to_ccs(i_target_mba, l_addr, (l_twr + l_cwl + l_al + l_pl + 10), l_instruction_number));

        // Write pattern (back up the instruction count so we hit the write instruction)
        --l_instruction_number;
        FAPI_TRY(mss_ccs_load_data_pattern(i_target_mba, l_instruction_number, l_write_pattern));
        ++l_instruction_number;

        // Issue precharge all command
        FAPI_TRY(add_precharge_all_to_ccs(i_target_mba, l_addr, l_trcd, l_odt, l_stack_type_u8array, l_instruction_number));

        // Issue DES command for tPGM_exit (12 clks)
        FAPI_TRY(add_des_with_repeat_to_ccs(i_target_mba, l_addr, 0, 12, l_instruction_number));

        // Take the DRAM out of PPR mode (MR4 command)
        l_addr.row_addr = DISABLE_PPR;
        l_addr.bank = MRS4_BA;
        FAPI_TRY(add_mrs_to_ccs_ddr4(i_target_mba, l_addr, TMOD, l_instruction_number));

        // Put the DRAM into the original MR0 mode
        l_addr.bank = MRS0_BA;
        FAPI_TRY(l_saved_mr0.clearBit(55));    //clear the dll reset.
        l_saved_mr0.extractToRight(l_addr.row_addr, 46, 18);
        FAPI_TRY(add_mrs_to_ccs_ddr4(i_target_mba, l_addr, TMOD, l_instruction_number));

        // Enable CCS and set RAS/CAS/WE high during idles
        FAPI_DBG("%s Enabling CCS", mss::c_str(i_target_mba));
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_CCS_MODEQ, l_reg_buffer));
        FAPI_TRY(l_reg_buffer.setBit(29));    //Enable CCS
        FAPI_TRY(l_reg_buffer.setBit(52));    //RAS high
        FAPI_TRY(l_reg_buffer.setBit(53));    //CAS high
        FAPI_TRY(l_reg_buffer.setBit(54));    //WE high
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_CCS_MODEQ, l_reg_buffer));

        // Subtract one from the instruction count because set_end_bit increments it
        --l_instruction_number;
        FAPI_TRY(mss_ccs_set_end_bit(i_target_mba, l_instruction_number), "CCS_SET_END_BIT FAILED");

        // Execute the CCS program
        FAPI_DBG("%s Executing the CCS array", mss::c_str(i_target_mba));
        FAPI_TRY(mss_execute_ccs_inst_array(i_target_mba, NUM_POLL, WAIT_TIMER), " EXECUTE_CCS_INST_ARRAY FAILED");
        l_instruction_number = 0;

        // Disable CCS
        FAPI_DBG("%s Disabling CCS", mss::c_str(i_target_mba));
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_CCS_MODEQ, l_reg_buffer));
        FAPI_TRY(l_reg_buffer.clearBit(29));
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_CCS_MODEQ, l_reg_buffer));

        // Turn on refresh
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MBAREF0Q, l_reg_buffer));
        l_reg_buffer.writeBit<REFRESH_BIT>(l_refresh);
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MBAREF0Q, l_reg_buffer));

    fapi_try_exit:
        return fapi2::current_err;
    }

    /// @brief Clear a row repair entry from the VPD data
    /// @param[in] i_rank master rank
    /// @param[in,out] io_row_repair_data data for this DIMM/rank from the VPD
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode clear_row_repair_entry(const uint8_t i_rank,
            uint8_t (&io_row_repair_data)[MAX_RANKS_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK])
    {
        constexpr uint8_t CLEAR_REPAIR_VALID_IN_BYTE = 0xFE;

        FAPI_ASSERT(i_rank < MAX_RANKS_PER_DIMM,
                    fapi2::CEN_RANK_OUT_OF_BOUNDS().
                    set_RANK(i_rank),
                    "Rank %d supplied to clear_row_repair_entry is out of bounds",
                    i_rank);

        // Clear the valid bit in the entry for this DIMM/rank and write it back
        io_row_repair_data[i_rank][ROW_REPAIR_BYTES_PER_RANK - 1] &= CLEAR_REPAIR_VALID_IN_BYTE;

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    }

    /// @brief Decode a row repair entry from an encoded buffer
    /// @param[in] i_repair row repair data buffer
    /// @param[out] o_dram DRAM position
    /// @param[out] o_srank slave rank
    /// @param[out] o_bg bank group
    /// @param[out] o_bank bank address
    /// @param[out] o_row row address
    /// @return true if the repair request is valid, false otherwise
    bool valid_row_repair_entry( const fapi2::buffer<uint32_t> i_repair,
                                 uint8_t& o_dram,
                                 uint8_t& o_srank,
                                 uint8_t& o_bg,
                                 uint8_t& o_bank,
                                 uint32_t& o_row )
    {
        i_repair.extractToRight<DRAM_POS, DRAM_POS_LEN>(o_dram);
        i_repair.extractToRight<SRANK, SRANK_LEN>(o_srank);
        i_repair.extractToRight<BANK_GROUP, BANK_GROUP_LEN>(o_bg);
        i_repair.extractToRight<BANK, BANK_LEN>(o_bank);
        i_repair.extractToRight<ROW_ADDR, ROW_ADDR_LEN>(o_row);
        return i_repair.getBit<REPAIR_VALID>();
    }

    /// @brief Build a table of PPR row repairs from attribute data for a given DIMM
    /// @param[in] i_target DIMM target
    /// @param[in] i_dram_width the DRAM width
    /// @param[in] i_row_repair_data array of row repair attribute values for the DIMM
    /// @param[out] o_repairs_per_dimm array of row repair data buffers
    /// @param[in,out] io_dram_bad_in_ranks array of how many ranks in which each DRAM was found to need a repair
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode build_row_repair_table(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const uint8_t i_dram_width,
            const uint8_t i_row_repair_data[MAX_RANKS_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK],
            std::vector<fapi2::buffer<uint32_t>>& o_repairs_per_dimm,
            uint8_t io_dram_bad_in_ranks[MC_MAX_DRAMS_PER_RANK_X4])
    {
        const uint8_t l_num_dram = (i_dram_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ?
                                   MAX_DRAMS_PER_RANK_X8 :
                                   (MC_MAX_DRAMS_PER_RANK_X4);

        o_repairs_per_dimm.clear();

        for (uint8_t l_rank = 0; l_rank < MAX_RANKS_PER_DIMM; ++l_rank)
        {
            fapi2::buffer<uint32_t> l_row_repair_entry;

            // Convert each entry from an array of bytes into a fapi2::buffer
            for (uint8_t l_byte = 0; l_byte < ROW_REPAIR_BYTES_PER_RANK; ++l_byte)
            {
                FAPI_TRY(l_row_repair_entry.insertFromRight(i_row_repair_data[l_rank][l_byte],
                         l_byte * BITS_PER_BYTE,
                         BITS_PER_BYTE));
            }

            // Insert row repair request into list (valid or not, so we can index by DIMM rank)
            o_repairs_per_dimm.push_back(l_row_repair_entry);

            uint8_t l_dram = 0;
            uint8_t l_srank = 0;
            uint8_t l_bg = 0;
            uint8_t l_bank = 0;
            uint32_t l_row = 0;

            if (valid_row_repair_entry(l_row_repair_entry, l_dram, l_srank, l_bg, l_bank, l_row))
            {
                FAPI_INF("Found valid row repair request in VPD for DIMM %s, DRAM %d, mrank %d, srank %d, bg %d, bank %d, row 0x%05x",
                         mss::spd::c_str(i_target), l_dram, l_rank, l_srank, l_bg, l_bank, l_row);

                // Do some sanity checking here
                FAPI_ASSERT(l_dram < l_num_dram,
                            fapi2::CEN_ROW_REPAIR_ENTRY_OUT_OF_BOUNDS().
                            set_DIMM_TARGET(i_target).
                            set_DRAM(l_dram).
                            set_MRANK(l_rank).
                            set_SRANK(l_srank).
                            set_BANK_GROUP(l_bg).
                            set_BANK(l_bank).
                            set_ROW(l_row),
                            "%s VPD contained out of bounds row repair entry: DRAM: %d mrank %d srank %d bg %d bank %d row 0x%05x",
                            mss::spd::c_str(i_target), l_dram, l_rank, l_srank, l_bg, l_bank, l_row);

                // Add this rank to the total number of ranks this DRAM appears in
                ++io_dram_bad_in_ranks[l_dram];
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    /// @brief Clear the corresponding bad_bits after a row repair operation
    /// @param[in] i_dram_width the DRAM width
    /// @param[in] i_dram the DRAM index
    /// @param[in,out] io_bad_bits array bad bits data from VPD
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode clear_bad_dq_for_row_repair(const uint8_t i_dram_width,
            const uint8_t i_dram,
            uint8_t (&io_bad_bits)[DIMM_DQ_RANK_BITMAP_SIZE])
    {
        // The DRAM index in ATTR_ROW_REPAIR_DATA is relative to Centaur perspective.
        // The bad_bits attribute is as well, so we can just index into the bad bits array
        // using the DRAM index
        const uint8_t l_byte = (i_dram_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X8) ?
                               i_dram :
                               i_dram / MAX_NIBBLES_PER_BYTE;
        uint8_t l_mask = 0;

        if (i_dram_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4)
        {
            l_mask = (i_dram % MAX_NIBBLES_PER_BYTE == 0) ? 0x0F : 0xF0;
        }

        // Protect our array index
        FAPI_ASSERT(l_byte < DIMM_DQ_RANK_BITMAP_SIZE,
                    fapi2::CEN_DRAM_INDEX_OUT_OF_BOUNDS().
                    set_DRAM(i_dram),
                    "DRAM index %d supplied to clear_bad_dq_for_row_repair is out of bounds",
                    i_dram);

        io_bad_bits[l_byte] &= l_mask;

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Create an error log and return with a good error code if a valid row repair is found
    /// @param[in] i_target the DIMM target
    /// @param[in] i_rank the master rank
    /// @return successful error code
    ///
    fapi2::ReturnCode repairs_disabled_error_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
            const uint8_t i_rank,
            const fapi2::buffer<uint32_t> i_repair)
    {
        uint8_t l_dram = 0;
        uint8_t l_srank = 0;
        uint8_t l_bg = 0;
        uint8_t l_bank = 0;
        uint32_t l_row = 0;

        FAPI_ASSERT(!valid_row_repair_entry(i_repair, l_dram, l_srank, l_bg, l_bank, l_row),
                    fapi2::CEN_ROW_REPAIR_WITH_MNFG_REPAIRS_DISABLED().
                    set_DIMM_TARGET(i_target).
                    set_RANK(i_rank),
                    "%s Row repair valid for rank %d but DRAM repairs are disabled in MNFG flags",
                    mss::spd::c_str(i_target), i_rank);
        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        // We've found a valid row repair - log it as predictive, so we get callouts in MFG test but don't fail out
        fapi2::logError(fapi2::current_err, fapi2::FAPI2_ERRL_SEV_PREDICTIVE);
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    /// @brief Deploy enough PPR row repairs to test all spare rows
    /// @param[in] i_target_mba mba target
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode p9c_mss_activate_all_spare_rows(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {
        uint8_t l_ranks_configed[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t num_mranks[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t num_ranks[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};

        FAPI_INF("%s Deploying row repairs to test all spare rows", mss::c_str(i_target_mba));

        for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target_mba))
        {
            uint8_t l_port = 0;
            uint8_t l_dimm_index = 0;
            uint8_t l_num_sranks = 0;
            fapi2::buffer<uint64_t> l_dram_bitmap;

            // Set all DRAM select bits so we get repairs on all DRAMs
            l_dram_bitmap.setBit<DRAM_START_BIT, DRAM_LEN>();

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT, l_dimm, l_port));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM, l_dimm, l_dimm_index));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_RANKS_CONFIGED, i_target_mba, l_ranks_configed));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba, num_mranks));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target_mba, num_ranks));

            // The number of slave ranks per DIMM is simply the number of total ranks divided by the number of master ranks
            l_num_sranks = num_ranks[l_port][l_dimm_index] / num_mranks[l_port][l_dimm_index];

            for (uint8_t l_mrank = 0; l_mrank < MAX_RANKS_PER_DIMM; ++l_mrank)
            {
                if (l_ranks_configed[l_port][l_dimm_index] & (0x80 >> l_mrank))
                {
                    for (uint8_t l_srank = 0; l_srank < l_num_sranks; ++l_srank)
                    {
                        uint8_t l_port_rank = 0;
                        // Note: setting row = rank so we don't use row0 for every repair
                        uint32_t l_row = l_mrank;
                        // Note: DIMM can only support one repair per BG, so we use BG=0 and BA=0
                        uint8_t l_bg = 0;
                        uint8_t l_bank = 0;

                        l_port_rank = (l_dimm_index * MAX_RANKS_PER_DIMM) + l_mrank;

                        FAPI_TRY(p9c_mss_row_repair(i_target_mba, l_port, l_port_rank, l_srank, l_bg, l_bank, l_row, l_dram_bitmap));
                    }
                }
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    /// @brief Deploy PPR row repairs, if supported, according to VPD attributes
    /// @param[in] i_target_mba mba target
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode p9c_mss_deploy_row_repairs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {
        bool l_sppr_supported = true;
        uint64_t l_mnfg_flags = 0;
        uint8_t l_dram_width = 0;
        uint8_t l_dram_bad_in_ranks[MC_MAX_DRAMS_PER_RANK_X4] = {0};
        uint8_t l_ranks_configed[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_dram = 0;
        uint8_t l_srank = 0;
        uint8_t l_bg = 0;
        uint8_t l_bank = 0;
        uint32_t l_row = 0;

        // This table contains a row repair entry for each DIMM/mrank combination
        std::map<fapi2::Target<fapi2::TARGET_TYPE_DIMM>, std::vector<fapi2::buffer<uint32_t>>> l_row_repairs;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MNFG_FLAGS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_mnfg_flags));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_RANKS_CONFIGED, i_target_mba, l_ranks_configed));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target_mba, l_dram_width));

        // If row repairs are not supported, we're done
        for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target_mba))
        {
            FAPI_TRY(is_sPPR_supported(l_dimm, l_sppr_supported));

            if (!l_sppr_supported)
            {
                FAPI_INF("%s Skipping row repair deployment since it's not supported in the MRW", mss::c_str(i_target_mba));
                return fapi2::FAPI2_RC_SUCCESS;
            }
        }

        // If mnfg flag is set to test all spare rows, we need to do row repair on all dimm/ranks/DRAMs
        if (l_mnfg_flags & fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_TEST_ALL_SPARE_DRAM_ROWS)
        {
            return p9c_mss_activate_all_spare_rows(i_target_mba);
        }

        // Get row repair data from attribute and build table
        for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target_mba))
        {
            uint8_t l_row_repair_data[MAX_RANKS_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK] = {0};
            std::vector<fapi2::buffer<uint32_t>> l_repairs_per_dimm;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ROW_REPAIR_DATA, l_dimm, l_row_repair_data));

            FAPI_TRY(build_row_repair_table(l_dimm, l_dram_width, l_row_repair_data, l_repairs_per_dimm, l_dram_bad_in_ranks));
            l_row_repairs.insert(std::make_pair(l_dimm, l_repairs_per_dimm));
        }

        // If DRAM repairs are disabled (mnfg flag), we're done (but need to callout DIMM if it has row repairs in VPD)
        if (l_mnfg_flags & fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_DISABLE_DRAM_REPAIRS)
        {
            FAPI_INF("%s DRAM repairs are disabled, so skipping row repair deployment", mss::c_str(i_target_mba));

            for (const auto l_pair : l_row_repairs)
            {
                const auto& l_dimm = l_pair.first;
                const auto& l_repairs = l_pair.second;

                for (uint8_t l_rank = 0; l_rank < MAX_RANKS_PER_DIMM; ++l_rank)
                {
                    // If we have a valid repair, call out this DIMM
                    FAPI_TRY(repairs_disabled_error_helper(l_dimm, l_rank, l_repairs[l_rank]));
                }
            }

            return fapi2::FAPI2_RC_SUCCESS;
        }

        // Iterate through DRAM repairs structure
        for (const auto l_pair : l_row_repairs)
        {
            const auto& l_dimm = l_pair.first;
            const auto& l_repairs = l_pair.second;
            uint8_t l_port = 0;
            uint8_t l_total_ranks_on_port = 0;
            uint8_t l_row_repair_data[MAX_RANKS_PER_DIMM][ROW_REPAIR_BYTES_PER_RANK] = {0};

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT, l_dimm, l_port));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ROW_REPAIR_DATA, l_dimm, l_row_repair_data));

            for (uint8_t l_dimm_index = 0; l_dimm_index < MAX_DIMM_PER_PORT; ++l_dimm_index)
            {
                l_total_ranks_on_port += l_ranks_configed[l_port][l_dimm_index];
            }

            for (uint8_t l_rank = 0; l_rank < MAX_RANKS_PER_DIMM; ++l_rank)
            {
                if (valid_row_repair_entry(l_repairs[l_rank], l_dram, l_srank, l_bg, l_bank, l_row))
                {
                    // If a DRAM position is marked bad in VPD for all ranks, skip row repair and clear row repair entry from VPD
                    // as this means the DRAM position has not been calibrated during draminit_training (Centaur workaround)
                    if (l_dram_bad_in_ranks[l_dram] == l_total_ranks_on_port)
                    {
                        FAPI_INF("%s DRAM position %d is bad in all ranks. Skipping row repairs for this DRAM.",
                                 mss::c_str(i_target_mba), l_dram);

                        FAPI_TRY(clear_row_repair_entry(l_rank, l_row_repair_data));

                        continue;
                    }

                    // Deploy row repair and clear bad DQs
                    uint8_t l_dimm_index = 0;
                    uint8_t l_port_rank = 0;
                    uint8_t l_bad_bits[DIMM_DQ_RANK_BITMAP_SIZE] = {0}; // 10 byte array of bad bits
                    fapi2::buffer<uint64_t> l_dram_bitmap;

                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM, l_dimm, l_dimm_index));
                    l_port_rank = (l_dimm_index * MAX_RANKS_PER_DIMM) + l_rank;

                    FAPI_TRY(l_dram_bitmap.setBit(DRAM_START_BIT + l_dram));

                    FAPI_INF("%s Deploying row repair on DRAM %d, mrank %d, srank %d, bg %d, bank %d, row 0x%05x",
                             mss::spd::c_str(l_dimm), l_dram, l_rank, l_srank, l_bg, l_bank, l_row);
                    FAPI_TRY(p9c_mss_row_repair(i_target_mba, l_port, l_port_rank, l_srank, l_bg, l_bank, l_row, l_dram_bitmap));

                    // Clear bad DQ bits for this port, DIMM, rank that will be fixed by this row repair
                    FAPI_INF("%s Updating bad bits on Port %d, DIMM %d, DRAM %d, mrank %d, srank %d, bg %d, bank %d, row 0x%05x",
                             mss::c_str(i_target_mba), l_port, l_dimm_index, l_dram, l_rank, l_srank, l_bg, l_bank, l_row);

                    FAPI_TRY(dimmGetBadDqBitmap(i_target_mba, l_port, l_dimm_index, l_rank, l_bad_bits),
                             "Error from dimmGetBadDqBitmap on %s.", mss::c_str(i_target_mba));

                    FAPI_TRY(clear_bad_dq_for_row_repair(l_dram_width, l_dram, l_bad_bits));

                    FAPI_TRY(dimmSetBadDqBitmap(i_target_mba, l_port, l_dimm_index, l_rank, l_bad_bits),
                             "Error from dimmGetBadDqBitmap on %s.", mss::c_str(i_target_mba));
                }
            }

            // Set the row repair attribute with any changes
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ROW_REPAIR_DATA, l_dimm, l_row_repair_data));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

}
