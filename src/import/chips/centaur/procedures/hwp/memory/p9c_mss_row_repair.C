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
#include <p9c_mss_funcs.H>
#include <p9c_mss_ddr4_funcs.H>

using namespace fapi2;

extern "C"
{
    /// @brief Perform a PPR row repair operation
    /// @param[in] i_target_mba mba target
    /// @param[in] i_port port for repair
    /// @param[in] i_mrank master rank of address to repair
    /// @param[in] i_srank slave rank of address to repair
    /// @param[in] i_bank bank bits of address to repair
    /// @param[in] i_row row bits of address to repair
    /// @param[in] i_dram_bitmap bitmap of DRAMs selected for repair (b'1 to repair, b'0 to not repair)
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode p9c_mss_row_repair(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                         const uint8_t  i_port,
                                         const uint8_t  i_mrank,
                                         const uint8_t  i_srank,
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

        // This is the value to shift the input DRAM position to the last 20 bits of l_write_pattern
        constexpr uint8_t DRAM_START_BIT = 44;
        constexpr uint8_t DRAM_LEN = 64 - DRAM_START_BIT;

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

        access_address l_addr = {i_row, 0, i_mrank, i_srank, i_bank, i_port};
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

}
