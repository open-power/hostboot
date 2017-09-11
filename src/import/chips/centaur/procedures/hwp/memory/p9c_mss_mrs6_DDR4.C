/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_mrs6_DDR4.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file mss_mrs6_DDR4.C
/// @brief MRS6 Setting Procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <fapi2.H>
#include <p9c_mss_ddr4_funcs.H>
#include <p9c_mss_funcs.H>
#include <cen_gen_scom_addresses.H>
#include <p9c_mss_mrs6_DDR4.H>
#include <dimmConsts.H>

extern "C"
{
    ///
    /// @brief sets up and runs Mode Register Set 6 on a centaur.mba level target
    /// @param[in]  target:  Reference to centaur.mba target,
    /// @return ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_mrs6_DDR4(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint32_t l_ccs_inst_cnt = 0;

        for (uint8_t l_port_number = 0; l_port_number < 2; ++l_port_number)
        {
            // Step four: Load MRS Setting
            FAPI_INF("Loading MRS6 for port %d", l_port_number);
            FAPI_TRY(mss_mr6_loader(i_target, l_port_number, l_ccs_inst_cnt), " mrs_load Failed");
        }

        // Execute the contents of CCS array
        if (l_ccs_inst_cnt  > 0)
        {
            // Set the End bit on the last CCS Instruction
            FAPI_TRY(mss_ccs_set_end_bit( i_target, l_ccs_inst_cnt - 1), "CCS_SET_END_BIT FAILED");
            FAPI_TRY(mss_execute_ccs_inst_array(i_target, 10, 10), " EXECUTE_CCS_INST_ARRAY FAILED");
            l_ccs_inst_cnt = 0;
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Adds a no-op (NOP) command to the CCS array
    /// @param[in]  i_target_mba:  Reference to centaur.mba target,
    /// @param[in]  i_addr_16: 16 wide ecmdDataBufferBase to be used for the address bus
    /// @param[in]  i_instruction_number: current location in the CCS array
    /// @param[in]  i_rank: current rank
    /// @param[in]  i_bank: current bank
    /// @param[in]  i_delay: delay to add for the command
    /// @param[in]  i_port: current port to execute the NOP on
    /// @return ReturnCode
    ///
    fapi2::ReturnCode add_nop_to_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                     fapi2::variable_buffer& i_addr_16,
                                     uint32_t i_instruction_number,
                                     const uint8_t i_rank,
                                     const uint8_t i_bank,
                                     const uint32_t i_delay,
                                     uint8_t i_port)
    {

        //CCS Array 0 buffers
        fapi2::variable_buffer l_bank_3(3);
        fapi2::variable_buffer l_ddr4_activate_1(1);
        fapi2::variable_buffer l_rasn_1(1);
        fapi2::variable_buffer l_casn_1(1);
        fapi2::variable_buffer l_wen_1(1);
        fapi2::variable_buffer l_cke_4(4);
        fapi2::variable_buffer l_csn_8(8);
        fapi2::variable_buffer l_odt_4(4);
        fapi2::variable_buffer l_cal_type_4(4);

        //CCS Array 1 buffers
        fapi2::variable_buffer l_idles_16(16);
        fapi2::variable_buffer l_repeat_16(16);
        fapi2::variable_buffer l_pattern_20(20);
        fapi2::variable_buffer l_read_compare_1(1);
        fapi2::variable_buffer l_rank_cal_4(4);
        fapi2::variable_buffer l_cal_enable_1(1);
        fapi2::variable_buffer l_ccs_end_1(1);
        FAPI_INF("\n Running NO -OP command");
        fapi2::buffer<uint8_t> l_data_8;
        fapi2::buffer<uint16_t> l_data_16;
        uint8_t l_dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target_mba, l_dram_stack));
        //CCS Array 0 Setup

        //Buffer conversions from inputs
        FAPI_TRY(i_addr_16.extract(l_data_16));
        l_data_16.reverse();
        FAPI_TRY(i_addr_16.insert((uint16_t)l_data_16));
        FAPI_TRY(l_bank_3.insertFromRight(i_bank, 0, 3), "add_activate_to_ccs: Error setting up buffers");
        FAPI_TRY(l_bank_3.extract(l_data_8, 0, 3));
        l_data_8.reverse();
        FAPI_TRY(l_bank_3.insertFromRight((uint8_t)l_data_8, 0 , 3));
        l_csn_8.flush<1>();
        FAPI_TRY(l_csn_8.clearBit(i_rank), "add_activate_to_ccs: Error setting up buffers");

        if (l_dram_stack[0][0] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
        {
            FAPI_INF( "=============  Got in the 3DS stack loop CKE !!!!=====================\n");
            FAPI_TRY(l_csn_8.clearBit(2, 2));
            FAPI_TRY(l_csn_8.clearBit(6, 2));
            FAPI_TRY(l_cke_4.clearBit(1));
        }

        //Command structure setup
        l_cke_4.flush<1>();
        FAPI_TRY(l_rasn_1.setBit(0), "add_activate_to_ccs: Error setting up buffers");
        FAPI_TRY(l_casn_1.setBit(0), "add_activate_to_ccs: Error setting up buffers");
        FAPI_TRY(l_wen_1.setBit(0), "add_activate_to_ccs: Error setting up buffers");

        FAPI_TRY(l_read_compare_1.clearBit(0), "add_activate_to_ccs: Error setting up buffers");

        //Final setup
        l_odt_4.flush<0>();
        l_cal_type_4.flush<0>();
        FAPI_TRY(l_ddr4_activate_1.setBit(0), "add_activate_to_ccs: Error setting up buffers");

        FAPI_TRY(mss_ccs_inst_arry_0(i_target_mba, i_instruction_number, i_addr_16, l_bank_3, l_ddr4_activate_1, l_rasn_1,
                                     l_casn_1, l_wen_1, l_cke_4, l_csn_8, l_odt_4, l_cal_type_4, i_port));


        //CCS Array 1 Setup
        FAPI_TRY(l_idles_16.insertFromRight(i_delay, 0, 16), "add_activate_to_ccs: Error setting up buffers");
        l_repeat_16.flush<0>();
        l_pattern_20.flush<0>();
        l_read_compare_1.flush<0>();
        l_rank_cal_4.flush<0>();
        l_cal_enable_1.flush<0>();
        l_ccs_end_1.flush<0>();

        FAPI_TRY(mss_ccs_inst_arry_1(i_target_mba, i_instruction_number, l_idles_16, l_repeat_16, l_pattern_20,
                                     l_read_compare_1,
                                     l_rank_cal_4, l_cal_enable_1, l_ccs_end_1));
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Loads in MRS6 for a given port number
    /// @param[in]  i_target:  Reference to centaur.mba target,
    /// @param[in]  i_port_number:  Current port to operate on
    /// @param[in,out]  io_ccs_inst_cnt:  Reference to current CCS array position
    /// @return ReturnCode
    ///
    fapi2::ReturnCode mss_mr6_loader(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                     uint32_t i_port_number,
                                     uint32_t& io_ccs_inst_cnt)
    {
        fapi2::buffer<uint64_t> l_data_buffer_64;
        fapi2::buffer<uint64_t> l_data_buffer;
        fapi2::variable_buffer l_address_16(16);
        fapi2::variable_buffer l_bank_3(3);
        fapi2::variable_buffer l_activate_1(1);
        fapi2::variable_buffer l_rasn_1(1);
        fapi2::variable_buffer l_casn_1(1);
        fapi2::variable_buffer l_wen_1(1);
        fapi2::variable_buffer l_cke_4(4);
        fapi2::variable_buffer l_csn_8(8);
        fapi2::variable_buffer l_odt_4(4);
        fapi2::variable_buffer l_ddr_cal_type_4(4);
        fapi2::variable_buffer l_num_idles_16(16);
        fapi2::variable_buffer l_num_repeat_16(16);
        fapi2::variable_buffer l_data_20(20);
        fapi2::variable_buffer l_read_compare_1(1);
        fapi2::variable_buffer l_rank_cal_4(4);
        fapi2::variable_buffer l_ddr_cal_enable_1(1);
        fapi2::variable_buffer l_ccs_end_1(1);
        fapi2::variable_buffer l_mrs0(16);
        fapi2::variable_buffer l_mrs1(16);
        fapi2::variable_buffer l_mrs2(16);
        fapi2::variable_buffer l_mrs3(16);
        fapi2::variable_buffer l_mrs4(16);
        fapi2::variable_buffer l_mrs5(16);
        fapi2::variable_buffer l_mrs6(16);
        uint32_t l_dimm_number = 0;
        uint32_t l_rank_number = 0;
        uint8_t l_tmod_delay = 12;
        uint32_t l_instruction_number = 0;
        uint16_t l_MRS6 = 0;
        uint16_t l_num_ranks = 0;
        uint8_t l_num_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //[port][dimm]
        uint8_t l_dimm_type = 0;
        uint8_t l_is_sim = 0;
        uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
        uint8_t l_vrefdq_train_value[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0}; //vrefdq_train value   -  NEW
        uint8_t l_vrefdq_train_enable[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0}; //vrefdq_train enable  -  NEW
        uint8_t l_vrefdq_train_range[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0}; //vrefdq_train range   -  NEW
        uint8_t l_dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_tccd_l = 0; //tccd_l  -  NEW

        FAPI_INF( "+++++++++++++++++++++ LOADING MRS SETTINGS FOR PORT %d +++++++++++++++++++++", i_port_number);

        FAPI_TRY(l_activate_1.setBit(0));
        FAPI_TRY(l_rasn_1.clearBit(0));
        FAPI_TRY(l_casn_1.clearBit(0));
        FAPI_TRY(l_wen_1.clearBit(0));
        FAPI_TRY(l_cke_4.clearBit(0, 4));
        FAPI_TRY(l_csn_8.clearBit(0, 8));
        FAPI_TRY(l_odt_4.clearBit(0, 4));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, l_num_ranks_array));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target, l_address_mirror_map));

        // WORKAROUNDS
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_CCS_MODEQ, l_data_buffer));
        //Setting up CCS mode
        FAPI_TRY(l_data_buffer.setBit(51), "mss_mr6_loader: Error setting up buffers");
        //set up parity bit manual computation - needed for DDR4
        FAPI_TRY(l_data_buffer.setBit(61), "mss_mr6_loader: Error setting up buffers");
        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_CCS_MODEQ, l_data_buffer));

        if(i_port_number == 0)
        {
            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_WC_CONFIG3_P0, l_data_buffer));
            //Setting up CCS mode
            FAPI_TRY(l_data_buffer.clearBit(48), "mss_mr6_loader: Error setting up buffers");
            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_WC_CONFIG3_P0, l_data_buffer));
        }
        else
        {

            FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_DDRPHY_WC_CONFIG3_P1, l_data_buffer));
            //Setting up CCS mode
            FAPI_TRY(l_data_buffer.clearBit(48), "mss_mr6_loader: Error setting up buffers");
            FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_DDRPHY_WC_CONFIG3_P1, l_data_buffer));
        }

        //Lines commented out in the following section are waiting for xml attribute adds

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target, l_dram_stack));

        FAPI_INF( "Stack Type: %d\n", l_dram_stack[0][0]);

        //MRS6
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, i_target, l_vrefdq_train_value));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE, i_target, l_vrefdq_train_range));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target, l_vrefdq_train_enable));

        FAPI_INF("enable attribute %d", l_vrefdq_train_enable[0][0][0]);

        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_TCCD_L, i_target, l_tccd_l));

        if (l_tccd_l == 4)
        {
            l_tccd_l = 0x00;
        }
        else if (l_tccd_l == 5)
        {
            l_tccd_l = 0x80;
        }
        else if (l_tccd_l == 6)
        {
            l_tccd_l = 0x40;
        }
        else if (l_tccd_l == 7)
        {
            l_tccd_l = 0xC0;
        }
        else if (l_tccd_l == 8)
        {
            l_tccd_l = 0x20;
        }

        // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
        FAPI_TRY(l_cke_4.setBit(0, 4), "mss_mr6_loader: Error setting up buffers");
        FAPI_TRY(l_csn_8.setBit(0, 8), "mss_mr6_loader: Error setting up buffers");
        FAPI_TRY(l_address_16.clearBit(0, 16), "mss_mr6_loader: Error setting up buffers");
        FAPI_TRY(l_odt_4.clearBit(0, 4), "mss_mr6_loader: Error setting up buffers");
        FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 400, 0, 16), "mss_mr6_loader: Error setting up buffers");

        FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                      io_ccs_inst_cnt,
                                      l_address_16,
                                      l_bank_3,
                                      l_activate_1,
                                      l_rasn_1,
                                      l_casn_1,
                                      l_wen_1,
                                      l_cke_4,
                                      l_csn_8,
                                      l_odt_4,
                                      l_ddr_cal_type_4,
                                      i_port_number));
        FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                      io_ccs_inst_cnt,
                                      l_num_idles_16,
                                      l_num_repeat_16,
                                      l_data_20,
                                      l_read_compare_1,
                                      l_rank_cal_4,
                                      l_ddr_cal_enable_1,
                                      l_ccs_end_1));
        io_ccs_inst_cnt ++;

        // Dimm 0-1
        for ( l_dimm_number = 0; l_dimm_number < 2; l_dimm_number ++)
        {
            l_num_ranks = l_num_ranks_array[i_port_number][l_dimm_number];

            if (l_num_ranks == 0)
            {
                FAPI_INF( "PORT%d DIMM%d not configured. Num_ranks: %d ", i_port_number, l_dimm_number, l_num_ranks);
            }
            else
            {
                // Rank 0-3
                for ( l_rank_number = 0; l_rank_number < l_num_ranks; l_rank_number ++)
                {
                    FAPI_INF( "MRS SETTINGS FOR PORT%d DIMM%d RANK%d", i_port_number, l_dimm_number, l_rank_number);

                    FAPI_TRY(l_csn_8.setBit(0, 8));
                    FAPI_TRY(l_address_16.clearBit(0, 16));

                    //MRS6
                    l_vrefdq_train_value[i_port_number][l_dimm_number][l_rank_number] = mss_reverse_8bits(
                                l_vrefdq_train_value[i_port_number][l_dimm_number][l_rank_number]);

                    if (l_vrefdq_train_range[i_port_number][l_dimm_number][l_rank_number] ==
                        fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE_RANGE1)
                    {
                        l_vrefdq_train_range[i_port_number][l_dimm_number][l_rank_number] = 0x00;
                    }
                    else if (l_vrefdq_train_range[i_port_number][l_dimm_number][l_rank_number] ==
                             fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE_RANGE2)
                    {
                        l_vrefdq_train_range[i_port_number][l_dimm_number][l_rank_number] = 0xFF;
                    }

                    if (l_vrefdq_train_enable[i_port_number][l_dimm_number][l_rank_number] ==
                        fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE)
                    {
                        l_vrefdq_train_enable[i_port_number][l_dimm_number][l_rank_number] = 0xff;
                        FAPI_INF("ENABLE is enabled");
                    }
                    else if (l_vrefdq_train_enable[i_port_number][l_dimm_number][l_rank_number] ==
                             fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE)
                    {
                        l_vrefdq_train_enable[i_port_number][l_dimm_number][l_rank_number] = 0x00;
                        FAPI_INF("DISABLE is enabled");
                    }

                    FAPI_TRY(l_mrs6.insert((uint8_t) l_vrefdq_train_value[i_port_number][l_dimm_number][l_rank_number], 0, 6));
                    FAPI_TRY(l_mrs6.insert((uint8_t) l_vrefdq_train_range[i_port_number][l_dimm_number][l_rank_number], 6, 1));
                    FAPI_TRY(l_mrs6.insertFromRight((uint8_t) l_vrefdq_train_enable[i_port_number][l_dimm_number][l_rank_number], 7, 1));

                    FAPI_TRY(l_mrs6.insert((uint8_t) 0x00, 8, 2));
                    FAPI_TRY(l_mrs6.insert((uint8_t) l_tccd_l, 10, 3));
                    FAPI_TRY(l_mrs6.insert((uint8_t) 0x00, 13, 2));

                    FAPI_TRY(l_mrs6.extract(l_MRS6, 0, 16));

                    FAPI_INF( "MRS 6: 0x%04X", l_MRS6);


                    // Only corresponding CS to rank
                    FAPI_TRY(l_csn_8.setBit(0, 8));
                    FAPI_TRY(l_csn_8.clearBit(l_rank_number + 4 * l_dimm_number));

                    if (l_dram_stack[0][0] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
                    {
                        FAPI_INF( "=============  Got in the 3DS stack loop CKE !!!!=====================\n");
                        FAPI_TRY(l_csn_8.clearBit(2, 2));
                        FAPI_TRY(l_csn_8.clearBit(6, 2));
                        FAPI_TRY(l_cke_4.clearBit(1));
                    }

                    // Propogate through the 4 MRS cmds
                    // Copying the current MRS into address buffer matching the MRS_array order
                    // Setting the bank address
                    FAPI_TRY(l_address_16.insert(l_mrs6, 0, 16, 0), "mss_mrs_load: Error setting up buffers");
                    FAPI_TRY(l_bank_3.insert((uint8_t) MRS6_BA, 0, 1, 7), "mss_mrs_load: Error setting up buffers");
                    FAPI_TRY(l_bank_3.insert((uint8_t) MRS6_BA, 1, 1, 6), "mss_mrs_load: Error setting up buffers");
                    FAPI_TRY(l_bank_3.insert((uint8_t) MRS6_BA, 2, 1, 5), "mss_mrs_load: Error setting up buffers");


                    if (( l_address_mirror_map[i_port_number][l_dimm_number] & (0x08 >> l_rank_number) ) && (l_is_sim == 0))
                    {
                        FAPI_TRY(mss_address_mirror_swizzle(i_target, l_address_16, l_bank_3));
                    }

                    // Send out to the CCS array
                    FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                                  io_ccs_inst_cnt,
                                                  l_address_16,
                                                  l_bank_3,
                                                  l_activate_1,
                                                  l_rasn_1,
                                                  l_casn_1,
                                                  l_wen_1,
                                                  l_cke_4,
                                                  l_csn_8,
                                                  l_odt_4,
                                                  l_ddr_cal_type_4,
                                                  i_port_number));
                    FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                                  io_ccs_inst_cnt,
                                                  l_num_idles_16,
                                                  l_num_repeat_16,
                                                  l_data_20,
                                                  l_read_compare_1,
                                                  l_rank_cal_4,
                                                  l_ddr_cal_enable_1,
                                                  l_ccs_end_1));
                    io_ccs_inst_cnt ++;

                    // Address inversion for RCD
                    if ( (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM)
                         || (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM
                             || l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM) )
                    {
                        FAPI_INF( "Sending out MRS with Address Inversion to B-side DRAMs\n");
                        // Propogate through the 4 MRS cmds
                        // Copying the current MRS into address buffer matching the MRS_array order
                        // Setting the bank address
                        FAPI_TRY(l_address_16.insert(l_mrs6, 0, 16, 0), " Error setting up buffers");
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS6_BA, 0, 1, 7), " Error setting up buffers");
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS6_BA, 1, 1, 6), " Error setting up buffers");
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS6_BA, 2, 1, 5), " Error setting up buffers");

                        // Indicate B-Side DRAMS BG1=1
                        FAPI_TRY(l_address_16.setBit(15), " Error setting up buffers"); // Set BG1 = 1

                        FAPI_TRY(l_address_16.flipBit(3, 7), " Error setting up buffers"); // Invert A3:A9
                        FAPI_TRY(l_address_16.flipBit(11), " Error setting up buffers"); // Invert A11
                        FAPI_TRY(l_address_16.flipBit(13), " Error setting up buffers"); // Invert A13
                        FAPI_TRY(l_address_16.flipBit(14), " Error setting up buffers"); // Invert A17
                        FAPI_TRY(l_bank_3.flipBit(0, 3), " Error setting up buffers");   // Invert BA0,BA1,BG0

                        if (( l_address_mirror_map[i_port_number][l_dimm_number] & (0x08 >> l_rank_number) ) && (l_is_sim == 0))
                        {
                            FAPI_TRY(mss_address_mirror_swizzle(i_target, l_address_16, l_bank_3));
                        }

                        // Send out to the CCS array
                        FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                                      io_ccs_inst_cnt,
                                                      l_address_16,
                                                      l_bank_3,
                                                      l_activate_1,
                                                      l_rasn_1,
                                                      l_casn_1,
                                                      l_wen_1,
                                                      l_cke_4,
                                                      l_csn_8,
                                                      l_odt_4,
                                                      l_ddr_cal_type_4,
                                                      i_port_number));
                        FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                                      io_ccs_inst_cnt,
                                                      l_num_idles_16,
                                                      l_num_repeat_16,
                                                      l_data_20,
                                                      l_read_compare_1,
                                                      l_rank_cal_4,
                                                      l_ddr_cal_enable_1,
                                                      l_ccs_end_1));
                        io_ccs_inst_cnt ++;
                    }

                    l_instruction_number = io_ccs_inst_cnt;

                    FAPI_TRY(add_nop_to_ccs (i_target, l_address_16, l_instruction_number, l_rank_number, MRS6_BA, l_tmod_delay,
                                             i_port_number));
                    io_ccs_inst_cnt = l_instruction_number;
                    io_ccs_inst_cnt++;
                }
            }
        }

    fapi_try_exit:
        return fapi2::current_err;

    }
}
