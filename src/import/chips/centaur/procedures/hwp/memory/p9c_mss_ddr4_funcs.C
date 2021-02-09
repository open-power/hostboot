/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_ddr4_funcs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
/// @file p9c_mss_ddr4_funcs.C
/// @brief Tools for DDR4 DIMMs centaur procedures
///
/// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB CI

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi2.H>

#include <p9c_mss_funcs.H>
#include <cen_gen_scom_addresses.H>
#include <p9c_mss_ddr4_funcs.H>
#include <generic/memory/lib/utils/c_str.H>
#include <dimmConsts.H>

/// @brief Writes MPR pattern for inverted address location for training with DDR4 RDIMMs.
/// @param[in] i_target_mba          Reference to MBA Target<fapi2::TARGET_TYPE_MBA>.
/// @return ReturnCode
fapi2::ReturnCode mss_ddr4_invert_mpr_write( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
{
    uint32_t l_rank_number = 0;

    fapi2::variable_buffer l_address_16(16);
    fapi2::variable_buffer l_bank_3(3);
    fapi2::variable_buffer l_activate_1(1);
    fapi2::variable_buffer l_rasn_1(1);
    fapi2::variable_buffer l_casn_1(1);
    fapi2::variable_buffer l_wen_1(1);
    fapi2::variable_buffer l_cke_4(4);
    fapi2::variable_buffer l_csn_8(8);
    fapi2::variable_buffer l_ddr_cal_type_4(4);
    fapi2::variable_buffer l_odt_4(4);
    fapi2::variable_buffer l_num_idles_16(16);
    fapi2::variable_buffer l_num_repeat_16(16);
    fapi2::variable_buffer l_data_20(20);
    fapi2::variable_buffer l_read_compare_1(1);
    fapi2::variable_buffer l_rank_cal_4(4);
    fapi2::variable_buffer l_ddr_cal_enable_1(1);
    fapi2::variable_buffer l_ccs_end_1(1);
    fapi2::variable_buffer l_mrs3(16);
    fapi2::buffer<uint64_t> l_data_buffer;

    uint16_t l_MRS3 = 0;
    uint8_t l_mpr_op = 0; // MPR Op
    uint32_t l_ccs_inst_cnt = 0;
    uint16_t l_num_ranks = 0;
    uint8_t l_mpr_pattern = 0xAA;
    uint8_t l_num_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //[port][dimm]
    uint8_t l_num_master_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //[port][dimm]
    uint8_t l_is_sim = 0;
    uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
    uint8_t l_dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_dram_al = 0;
    uint8_t l_dram_cl = 0;
    uint8_t l_mpr_write_delay = 0;
    constexpr uint32_t NUM_POLL = 100;
    constexpr uint8_t TMOD = 24;
    fapi2::buffer<uint64_t> l_data_64;
    FAPI_TRY(l_casn_1.clearBit(0));
    FAPI_TRY(l_wen_1.clearBit(0));
    FAPI_TRY(l_cke_4.setBit(0, 4));
    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_odt_4.clearBit(0, 4));
    FAPI_TRY(l_rasn_1.clearBit(0));
    FAPI_TRY(l_activate_1.setBit(0));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target_mba, l_num_ranks_array));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba, l_num_master_ranks_array));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target_mba, l_address_mirror_map));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target_mba, l_dram_stack));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CL, i_target_mba, l_dram_cl));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_AL, i_target_mba, l_dram_al));

    for (uint8_t l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
    {
        // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
        FAPI_TRY(l_csn_8.setBit(0, 8));
        FAPI_TRY(l_address_16.clearBit(0, 16));
        FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 400, 0, 16));

        FAPI_INF( "Stack Type in mss_ddr4_invert_mpr_write : %d\n", l_dram_stack[0][0]);


        FAPI_TRY(mss_ccs_inst_arry_0( i_target_mba,
                                      l_ccs_inst_cnt,
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
                                      l_port));

        FAPI_TRY(mss_ccs_inst_arry_1( i_target_mba,
                                      l_ccs_inst_cnt,
                                      l_num_idles_16,
                                      l_num_repeat_16,
                                      l_data_20,
                                      l_read_compare_1,
                                      l_rank_cal_4,
                                      l_ddr_cal_enable_1,
                                      l_ccs_end_1));

        l_ccs_inst_cnt++;

        for (uint8_t l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++)
        {
            if (l_dram_stack[0][0] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
            {
                l_num_ranks = l_num_master_ranks_array[l_port][l_dimm];
            }
            else
            {
                l_num_ranks = l_num_ranks_array[l_port][l_dimm];
            }

            if (l_num_ranks == 0)
            {
                FAPI_INF( "PORT%d DIMM%d not configured. Num_ranks: %d ", l_port, l_dimm, l_num_ranks);
            }
            else
            {
                // Rank 0-3
                for ( l_rank_number = 0; l_rank_number < l_num_ranks; l_rank_number++)
                {

                    FAPI_TRY(l_csn_8.setBit(0, 8));
                    FAPI_TRY(l_csn_8.clearBit(l_rank_number + 4 * l_dimm));

                    FAPI_TRY(mss_disable_cid(i_target_mba, l_csn_8, l_cke_4));

                    FAPI_TRY(l_address_16.clearBit(0, 16));

                    // MRS CMD to CMD spacing = 12 cycles
                    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 24, 0, 16));

                    if (l_port == 0)
                    {
                        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_DDRPHY_PC_MR3_PRI_RP0_P0,
                                                l_data_buffer)); // Need to look up Rank Group???
                    }
                    else if ( l_port == 1 )
                    {
                        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_DDRPHY_PC_MR3_PRI_RP0_P1,
                                                l_data_buffer)); // Need to look up Rank Group???
                    }

                    l_data_buffer.reverse();
                    FAPI_TRY(l_mrs3.insert((uint64_t)l_data_buffer, 0, 16, 0), " Error setting up buffers");
                    FAPI_TRY(l_mrs3.extract(l_MRS3, 0, 16), " Error setting up buffers");


                    FAPI_INF( "CURRENT MRS 3: 0x%04X", l_MRS3);

                    l_mpr_op = 0xff;

                    FAPI_TRY(l_mrs3.insert((uint8_t) l_mpr_op, 2, 1), " Error setting up buffers");

                    FAPI_TRY(l_mrs3.extract(l_MRS3, 0, 16), " Error setting up buffers");
                    FAPI_INF( "Set data flow from MPR, New MRS 3: 0x%04X", l_MRS3);

                    FAPI_TRY(l_address_16.insert(l_mrs3, 0, 16, 0), " Error setting up buffers");
                    FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7), " Error setting up buffers");
                    FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6), " Error setting up buffers");
                    FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5), " Error setting up buffers");

                    // Indicate B-Side DRAMS BG1=1
                    FAPI_TRY(l_address_16.setBit(15), " Error setting up buffers"); // Set BG1 = 1

                    FAPI_TRY(l_address_16.flipBit(3, 7), " Error setting up buffers"); // Invert A3:A9
                    FAPI_TRY(l_address_16.flipBit(11), " Error setting up buffers"); // Invert A11
                    FAPI_TRY(l_address_16.flipBit(13), " Error setting up buffers"); // Invert A13
                    FAPI_TRY(l_address_16.flipBit(14), " Error setting up buffers"); // Invert A17
                    FAPI_TRY(l_bank_3.flipBit(0, 3), " Error setting up buffers");   // Invert BA0,BA1,BG0

                    if (( l_address_mirror_map[l_port][l_dimm] & (0x08 >> l_rank_number) ) && (l_is_sim == 0))
                    {
                        FAPI_TRY(mss_address_mirror_swizzle(i_target_mba, l_address_16, l_bank_3));

                    }

                    // Send out to the CCS array
                    FAPI_TRY(mss_ccs_inst_arry_0( i_target_mba,
                                                  l_ccs_inst_cnt,
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
                                                  l_port));

                    FAPI_TRY(mss_ccs_inst_arry_1( i_target_mba,
                                                  l_ccs_inst_cnt,
                                                  l_num_idles_16,
                                                  l_num_repeat_16,
                                                  l_data_20,
                                                  l_read_compare_1,
                                                  l_rank_cal_4,
                                                  l_ddr_cal_enable_1,
                                                  l_ccs_end_1));

                    l_ccs_inst_cnt++;


                    // Write pattern to MPR register
                    //Command structure setup
                    l_cke_4.flush<1>();
                    FAPI_TRY(l_rasn_1.setBit(0), " Error setting up buffers");
                    FAPI_TRY(l_casn_1.clearBit(0), " Error setting up buffers");
                    FAPI_TRY(l_wen_1.clearBit(0), " Error setting up buffers");


                    //Final setup
                    l_odt_4.flush<0>();
                    l_ddr_cal_type_4.flush<0>();
                    FAPI_TRY(l_activate_1.setBit(0), " Error setting up buffers");


                    //Calculate tWR_MPR
                    l_mpr_write_delay = TMOD + (l_dram_cl - l_dram_al);
                    //CCS Array 1 Setup
                    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) l_mpr_write_delay, 0, 16), " Error setting up buffers");
                    l_num_repeat_16.flush<0>();
                    l_data_20.flush<0>();
                    l_read_compare_1.flush<0>();
                    l_rank_cal_4.flush<0>();
                    l_ddr_cal_enable_1.flush<0>();
                    l_ccs_end_1.flush<0>();

                    FAPI_TRY(l_address_16.clearBit(0, 16), " Error setting up buffers");
                    FAPI_TRY(l_address_16.insertFromRight(l_mpr_pattern, 0, 8), " Error setting up buffers");

                    FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7), " Error setting up buffers");
                    FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6), " Error setting up buffers");
                    FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5), " Error setting up buffers");

                    // Indicate B-Side DRAMS BG1=1
                    FAPI_TRY(l_address_16.setBit(15), " Error setting up buffers"); // Set BG1 = 1

                    FAPI_TRY(l_address_16.flipBit(3, 7), " Error setting up buffers"); // Invert A3:A9
                    FAPI_TRY(l_address_16.flipBit(11), " Error setting up buffers"); // Invert A11
                    FAPI_TRY(l_address_16.flipBit(13), " Error setting up buffers"); // Invert A13
                    FAPI_TRY(l_address_16.flipBit(14), " Error setting up buffers"); // Invert A17
                    FAPI_TRY(l_bank_3.flipBit(0, 3), " Error setting up buffers");   // Invert BA0,BA1,BG0

                    if (( l_address_mirror_map[l_port][l_dimm] & (0x08 >> l_rank_number) ) && (l_is_sim == 0))
                    {
                        FAPI_TRY(mss_address_mirror_swizzle(i_target_mba, l_address_16, l_bank_3));

                    }

                    FAPI_INF( "Writing MPR register with 0101 pattern");
                    // Send out to the CCS array
                    FAPI_TRY(mss_ccs_inst_arry_0( i_target_mba,
                                                  l_ccs_inst_cnt,
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
                                                  l_port));

                    FAPI_TRY(mss_ccs_inst_arry_1( i_target_mba,
                                                  l_ccs_inst_cnt,
                                                  l_num_idles_16,
                                                  l_num_repeat_16,
                                                  l_data_20,
                                                  l_read_compare_1,
                                                  l_rank_cal_4,
                                                  l_ddr_cal_enable_1,
                                                  l_ccs_end_1));

                    l_ccs_inst_cnt++;

                    // Restore MR3 to normal MPR operation
                    //Command structure setup
                    l_cke_4.flush<1>();
                    FAPI_TRY(l_rasn_1.clearBit(0));
                    FAPI_TRY(l_casn_1.clearBit(0));
                    FAPI_TRY(l_wen_1.clearBit(0));

                    FAPI_TRY(l_read_compare_1.clearBit(0));

                    l_odt_4.flush<0>();
                    l_ddr_cal_type_4.flush<0>();
                    FAPI_TRY(l_activate_1.setBit(0));

                    l_num_repeat_16.flush<0>();
                    l_data_20.flush<0>();
                    l_read_compare_1.flush<0>();
                    l_rank_cal_4.flush<0>();
                    l_ddr_cal_enable_1.flush<0>();
                    l_ccs_end_1.flush<0>();

                    FAPI_TRY(l_address_16.clearBit(0, 16));

                    // MRS CMD to CMD spacing = 12 cycles
                    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 24, 0, 16));

                    if (l_port == 0)
                    {
                        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_DDRPHY_PC_MR3_PRI_RP0_P0,
                                                l_data_buffer)); // Need to look up Rank Group???
                    }
                    else if ( l_port == 1 )
                    {
                        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_DDRPHY_PC_MR3_PRI_RP0_P1,
                                                l_data_buffer)); // Need to look up Rank Group???
                    }

                    l_data_buffer.reverse();
                    FAPI_TRY(l_mrs3.insert((uint64_t)l_data_buffer, 0, 16, 0));
                    FAPI_TRY(l_mrs3.extract(l_MRS3, 0, 16));


                    FAPI_INF( "CURRENT MRS 3: 0x%04X", l_MRS3);

                    l_mpr_op = 0x00;

                    FAPI_TRY(l_mrs3.insert((uint8_t) l_mpr_op, 2, 1), " Error setting up buffers");

                    FAPI_TRY(l_mrs3.extract(l_MRS3, 0, 16), " Error setting up buffers");
                    FAPI_INF( "Set data flow from MPR, New MRS 3: 0x%04X", l_MRS3);


                    FAPI_TRY(l_address_16.insert(l_mrs3, 0, 16, 0));
                    FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7));
                    FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6));
                    FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5));

                    // Indicate B-Side DRAMS BG1=1
                    FAPI_TRY(l_address_16.setBit(15), " Error setting up buffers"); // Set BG1 = 1

                    FAPI_TRY(l_address_16.flipBit(3, 7), " Error setting up buffers"); // Invert A3:A9
                    FAPI_TRY(l_address_16.flipBit(11), " Error setting up buffers"); // Invert A11
                    FAPI_TRY(l_address_16.flipBit(13), " Error setting up buffers"); // Invert A13
                    FAPI_TRY(l_address_16.flipBit(14), " Error setting up buffers"); // Invert A17
                    FAPI_TRY(l_bank_3.flipBit(0, 3), " Error setting up buffers");   // Invert BA0,BA1,BG0


                    if (( l_address_mirror_map[l_port][l_dimm] & (0x08 >> l_rank_number) ) && (l_is_sim == 0))
                    {
                        FAPI_TRY(mss_address_mirror_swizzle(i_target_mba, l_address_16, l_bank_3));

                    }



                    // Send out to the CCS array
                    FAPI_TRY(mss_ccs_inst_arry_0( i_target_mba,
                                                  l_ccs_inst_cnt,
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
                                                  l_port));

                    FAPI_TRY(mss_ccs_inst_arry_1( i_target_mba,
                                                  l_ccs_inst_cnt,
                                                  l_num_idles_16,
                                                  l_num_repeat_16,
                                                  l_data_20,
                                                  l_read_compare_1,
                                                  l_rank_cal_4,
                                                  l_ddr_cal_enable_1,
                                                  l_ccs_end_1));
                    l_ccs_inst_cnt++;
                }
            }
        }
    }

    FAPI_TRY(mss_execute_ccs_inst_array( i_target_mba, NUM_POLL, 60));

fapi_try_exit:
    return fapi2::current_err;
}


/// @brief Creates RCD_CNTRL_WORD attribute for DDR4 register
/// @param[in] i_target_mba          Reference to MBA Target<fapi2::TARGET_TYPE_MBA>.
/// @return ReturnCode
fapi2::ReturnCode mss_create_rcd_ddr4(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
{
    uint8_t l_rcd_cntl_word_0_1 = 0;
    uint8_t l_rcd_cntl_word_2 = 0;
    uint8_t l_rcd_cntl_word_3 = 0;
    uint8_t l_rcd_cntl_word_4 = 0;
    uint8_t l_rcd_cntl_word_5 = 0;
    uint8_t l_rcd_cntl_word_6_7 = 0;
    uint8_t l_rcd_cntl_word_8_9 = 0;
    uint8_t l_rcd_cntl_word_10 = 0;
    uint8_t l_rcd_cntl_word_11 = 0;
    uint8_t l_rcd_cntl_word_12 = 0;
    uint8_t l_rcd_cntl_word_13 = 0;
    uint8_t l_rcd_cntl_word_14 = 0;
    uint8_t l_rcd_cntl_word_15 = 0;
    uint64_t l_rcd_cntl_word_0_15 = 0;
    uint8_t l_stack_type[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint64_t l_attr_eff_dimm_rcd_cntl_word_0_15[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_num_ranks_per_dimm_u8array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_num_master_ranks_per_dimm_u8array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_dimm_type_u8 = 0;
    uint8_t l_dram_width_u8 = 0;
    uint64_t l_attr_eff_dimm_cntl_word_x = 0;
    uint8_t l_rcd_cntl_word_1x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_2x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_3x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_7x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_8x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_9x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_Ax[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_Bx[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint32_t l_mss_freq = 0;
    uint32_t l_mss_volt = 0;
    fapi2::variable_buffer l_data_buffer_8(8);
    fapi2::variable_buffer l_data_buffer_64(64);
    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_target_centaur;


    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba,
                           l_num_master_ranks_per_dimm_u8array));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target_mba, l_stack_type));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target_mba, l_dimm_type_u8));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_RCD_CNTL_WORD_0_15, i_target_mba, l_attr_eff_dimm_rcd_cntl_word_0_15));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target_mba, l_num_ranks_per_dimm_u8array));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target_mba, l_dram_width_u8));


    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_MAX_TIMEOUT, i_target_mba, l_attr_eff_dimm_cntl_word_x));

    l_target_centaur = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, l_target_centaur, l_mss_freq));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VOLT, l_target_centaur, l_mss_volt));

    for (uint8_t l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
    {
        for (uint8_t l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++)
        {

            // Global Features, Clock Driver Enable Control Words
            l_rcd_cntl_word_0_1   = 0x00;

            // Timing and IBT Control Word
            l_rcd_cntl_word_2 = 0;

            // CA and CS Signals Driver Characteristics Control Word
            if (l_num_ranks_per_dimm_u8array[l_port][l_dimm] > 1)
            {
                l_rcd_cntl_word_3   = 6; // QxCS0_n...QxCS3_n Outputs strong drive, Address/Command moderate drive
            }
            else
            {
                l_rcd_cntl_word_3   = 5; // QxCS0_n...QxCS3_n Outputs moderate drive, Address/Command moderate drive
            }

            l_rcd_cntl_word_4     = 5;    // QxODT0...QxODT1 and QxCKE0...QxCKE1 Output Drivers moderate drive
            l_rcd_cntl_word_5     = 5;    // Clock Y1_t, Y1_c, Y3_t, Y3_c and Y0_t, Y0_c, Y2_t, Y2_c Output Drivers moderate drive

            // Command Space Control Word
            l_rcd_cntl_word_6_7 = 0xf0; // No op

            // Input/Output Configuration, Power Saving Settings Control Words
            if(l_stack_type[l_port][l_dimm] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
            {
                //no master ranks found, then program to disable all CIDs
                //master ranks should always be found so this is a bit weird - might want to throw an error here
                if(l_num_master_ranks_per_dimm_u8array[l_port][l_dimm] == 0)
                {
                    l_rcd_cntl_word_8_9 = 0x30;
                }
                //determine stack density - 2H, 4H, or 8H
                else
                {
                    uint8_t l_stack_height = l_num_ranks_per_dimm_u8array[l_port][l_dimm] /
                                             l_num_master_ranks_per_dimm_u8array[l_port][l_dimm];
                    FAPI_INF("3DS RCD set stack_height: %d", l_stack_height);

                    if(l_stack_height == 8)
                    {
                        l_rcd_cntl_word_8_9 = 0x00;
                        l_rcd_cntl_word_Bx[l_port][l_dimm] = 0x00;
                    }
                    else if(l_stack_height == 4)
                    {
                        l_rcd_cntl_word_8_9 = 0x10;
                        l_rcd_cntl_word_Bx[l_port][l_dimm] = 0x04;
                    }
                    else if(l_stack_height == 2)
                    {
                        l_rcd_cntl_word_8_9 = 0x20;
                        l_rcd_cntl_word_Bx[l_port][l_dimm] = 0x06;
                    }
                    //weird, we shouldn't have 1H stacks
                    else
                    {
                        l_rcd_cntl_word_8_9 = 0x30;
                    }
                }
            }
            //LR DIMM and 4 ranks
            else if(l_dimm_type_u8 == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM
                    && l_num_ranks_per_dimm_u8array[l_port][l_dimm] == 4)
            {
                FAPI_INF("Creating RCD value for F0rC08 - LRDDIMM and 4 ranks -> 0x10");
                l_rcd_cntl_word_8_9 = 0x10;
            }
            else
            {
                l_rcd_cntl_word_8_9 = 0x30;
                l_rcd_cntl_word_Bx[l_port][l_dimm] = 0x07;
            }

            // RDIMM Operating Speed Control Word
            if ( l_mss_freq <= 1733 )          // 1600
            {
                l_rcd_cntl_word_10 = 0;
            }
            else if ( l_mss_freq <= 2000 )     // 1866
            {
                l_rcd_cntl_word_10 = 1;
            }
            else if ( l_mss_freq <= 2266 )     // 2133
            {
                l_rcd_cntl_word_10 = 2;
            }
            else if ( l_mss_freq <= 2533 )     // 2400
            {
                l_rcd_cntl_word_10 = 3;
            }
            else if ( l_mss_freq <= 2800 )     // 2666
            {
                l_rcd_cntl_word_10 = 4;
            }
            else if ( l_mss_freq <= 3333 )     // 3200
            {
                l_rcd_cntl_word_10 = 5;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_DRAM_INVALID_FREQ().
                            set_TARGET_MBA_ERROR(i_target_mba).
                            set_FREQ(l_mss_freq).
                            set_TARGET(i_target_mba),
                            "Invalid LRDIMM ATTR_CEN_MSS_FREQ = %d on %s!",
                            l_mss_freq,
                            mss::c_str(i_target_mba));
            }

            // Operating Voltage VDD and VREFCA Source Control Word
            if ( l_mss_volt >= 1120 )          // 1.2V
            {
                l_rcd_cntl_word_11 = 14;
            }
            else if ( l_mss_volt >= 1020 )     // 1.0xV
            {
                l_rcd_cntl_word_11 = 15;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_DRAM_INVALID_VOLT().
                            set_TARGET_MBA_ERROR(i_target_mba).
                            set_VOLT(l_mss_volt).
                            set_TARGET(i_target_mba),
                            "Invalid LRDIMM ATTR_CEN_MSS_VOLT = %d on %s!", l_mss_volt,
                            mss::c_str(i_target_mba));
            }

            // Training Control Word
            l_rcd_cntl_word_12 = 0;

            // DIMM Configuration Control words
            FAPI_TRY(l_data_buffer_8.clearBit(0, 8));

            if ( l_dimm_type_u8 == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM  )
            {
                FAPI_TRY(l_data_buffer_8.setBit(1)); //DUALCS MODE
            }

            if ( l_num_ranks_per_dimm_u8array[l_port][l_dimm] > 1 )
            {
                FAPI_TRY(l_data_buffer_8.setBit(0)); // Address mirroring for MRS commands
            }

            FAPI_TRY(l_data_buffer_8.extractToRight( l_rcd_cntl_word_13, 0, 4));

            // Parity Control Word - turn on Parity, pulse alert_n, pulse according to the table
            l_rcd_cntl_word_14 = 0x0D;

            // Command Latency Adder Control Word
            if ( l_dimm_type_u8 == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM  )
            {
                l_rcd_cntl_word_15 = 0; // 0nCk latency adder
            }
            else
            {
                l_rcd_cntl_word_15 = 0; // 1nCk latency adder with DB control bus
            }

            FAPI_INF("RCD_CNTL_WORDS %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x ", l_rcd_cntl_word_0_1,
                     l_rcd_cntl_word_2,
                     l_rcd_cntl_word_3,
                     l_rcd_cntl_word_4,
                     l_rcd_cntl_word_5,
                     l_rcd_cntl_word_6_7,
                     l_rcd_cntl_word_8_9,
                     l_rcd_cntl_word_10,
                     l_rcd_cntl_word_11,
                     l_rcd_cntl_word_12,
                     l_rcd_cntl_word_13,
                     l_rcd_cntl_word_14,
                     l_rcd_cntl_word_15 );

            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_0_1, 0 , 8));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_2,   8 , 4));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_3,   12, 4));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_4,   16, 4));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_5,   20, 4));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_6_7, 24, 8));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_8_9, 32, 8));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_10,  40, 4));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_11,  44, 4));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_12,  48, 4));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_13,  52, 4));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_14,  56, 4));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_15,  60, 4));
            FAPI_TRY(l_data_buffer_64.extract(l_rcd_cntl_word_0_15, 0, 64));
            l_attr_eff_dimm_rcd_cntl_word_0_15[l_port][l_dimm] =  l_rcd_cntl_word_0_15;

            // Set RCD control word x

            // RC1x Internal VREF CW
            l_rcd_cntl_word_1x[l_port][l_dimm] = 0;

            // RC2x I2C Bus Control Word
            l_rcd_cntl_word_2x[l_port][l_dimm] = 0;

            // RC3x Fine Granularity  RDIMM Operating Speed Control Word
            if ( l_mss_freq > 1240 && l_mss_freq < 3200 )
            {
                l_rcd_cntl_word_3x[l_port][l_dimm] = int ((l_mss_freq - 1250) / 20);
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_DRAM_INVALID_FREQ().
                            set_TARGET_MBA_ERROR(i_target_mba).
                            set_FREQ(l_mss_freq).
                            set_PORT(l_port).
                            set_TARGET(i_target_mba),
                            "Invalid DIMM ATTR_CEN_MSS_FREQ = %d on %s!",
                            l_mss_freq,
                            mss::c_str(i_target_mba));
            }

            // RC7x IBT Control Word
            l_rcd_cntl_word_7x[l_port][l_dimm] = 0;

            // RC8x ODT Input Buffer/IBT, QxODT Output Buffer and Timing Control Word
            l_rcd_cntl_word_8x[l_port][l_dimm] = 0;

            // RC9x QxODT[1:0] Write Pattern CW
            l_rcd_cntl_word_9x[l_port][l_dimm] = 0;

            // RCAx QxODT[1:0] Read Pattern CW
            l_rcd_cntl_word_Ax[l_port][l_dimm] = 0;

            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_1x[l_port][l_dimm], 0 , 8));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_2x[l_port][l_dimm], 8 , 8));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_3x[l_port][l_dimm], 16, 8));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_7x[l_port][l_dimm], 24, 8));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_8x[l_port][l_dimm], 32, 8));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_9x[l_port][l_dimm], 40, 8));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_Ax[l_port][l_dimm], 48, 8));
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_rcd_cntl_word_Bx[l_port][l_dimm], 56, 8));

            FAPI_TRY(l_data_buffer_64.extract(l_attr_eff_dimm_cntl_word_x, 0, 64));
            FAPI_INF("from data buffer: rcd control word X %llX", l_attr_eff_dimm_cntl_word_x );

        } // end dimm loop
    } // end port loop

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_RCD_CNTL_WORD_0_15, i_target_mba, l_attr_eff_dimm_rcd_cntl_word_0_15));

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_1x, i_target_mba, l_rcd_cntl_word_1x));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_2x, i_target_mba, l_rcd_cntl_word_2x));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_3x, i_target_mba, l_rcd_cntl_word_3x));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_7x, i_target_mba, l_rcd_cntl_word_7x));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_8x, i_target_mba, l_rcd_cntl_word_8x));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_9x, i_target_mba, l_rcd_cntl_word_9x));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_Ax, i_target_mba, l_rcd_cntl_word_Ax));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_Bx, i_target_mba, l_rcd_cntl_word_Bx));

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Generates the RCD control word chip selects
/// @param[in] i_target - MBA target on which to opearte
/// @param[in] i_dimm - DIMM on which to operate
/// @param[out] o_rcd_cs - chip selects for the RCD
/// @param[in,out] io_cke - CKE's as this contains CID2
/// @return ReturnCode
fapi2::ReturnCode generate_rcd_cs( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                   const uint32_t i_dimm,
                                   fapi2::variable_buffer& o_rcd_cs,
                                   fapi2::variable_buffer& io_cke)
{
    // Enable the CS for the first rank on the DIMM
    const uint64_t RANK = i_dimm == 0 ? 0 : 4;
    fapi2::variable_buffer l_csn_8(8);

    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_csn_8.clearBit(RANK), "mss_rcd_load: Error setting up buffers"); //DCS0_n is LOW

    FAPI_TRY(mss_disable_cid(i_target, l_csn_8, io_cke));

    o_rcd_cs = l_csn_8;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Writes the 4-bit RCD control words for DDR4 register.
/// @param[in] i_target             Reference to MBA Target<fapi2::TARGET_TYPE_MBA>.
/// @param[in] i_port_number        MBA port number
/// @param[in] i_dimm               the DIMM number to issue the RCW to
/// @param[in] i_cke                CKE bits to use
/// @param[in] i_rcd_num            RCD control word number
/// @param[in] i_rcd_data           RCD control word data
/// @param[in] i_delay              number of idles
/// @param[in, out] io_ccs_inst_cnt  CCS instruction count
/// @return ReturnCode
fapi2::ReturnCode mss_rcd_load_ddr4_4bit(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    const uint32_t i_port_number,
    const uint32_t i_dimm,
    const fapi2::variable_buffer& i_cke,
    const uint64_t i_rcd_num,
    const uint64_t i_rcd_data,
    const uint64_t i_delay,
    uint32_t& io_ccs_inst_cnt)
{

    fapi2::variable_buffer l_address_16(16);
    fapi2::variable_buffer l_bank_3(3);
    fapi2::variable_buffer l_activate_1(1);
    fapi2::variable_buffer l_rasn_1(1);
    fapi2::variable_buffer l_casn_1(1);
    fapi2::variable_buffer l_wen_1(1);
    fapi2::variable_buffer l_odt_4(4);
    fapi2::variable_buffer l_ddr_cal_type_4(4);
    fapi2::variable_buffer l_num_idles_16(16);
    fapi2::variable_buffer l_num_repeat_16(16);
    fapi2::variable_buffer l_data_20(20);
    fapi2::variable_buffer l_read_compare_1(1);
    fapi2::variable_buffer l_rank_cal_4(4);
    fapi2::variable_buffer l_ddr_cal_enable_1(1);
    fapi2::variable_buffer l_ccs_end_1(1);
    fapi2::variable_buffer l_csn_8(8);
    auto l_cke = i_cke;

    // ALL active CS lines at a time.
    FAPI_TRY(generate_rcd_cs( i_target, i_dimm, l_csn_8, l_cke), "mss_4bit_load: Error setting up buffers %s",
             mss::c_str(i_target));

    // DBG1, DBG0, DBA1, DBA0 = 4`b0111
    FAPI_TRY(l_bank_3.setBit(0, 3), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));
    // DACT_n is HIGH
    FAPI_TRY(l_activate_1.setBit(0), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));
    // RAS_n/CAS_n/WE_n are LOW
    FAPI_TRY(l_rasn_1.clearBit(0), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));
    FAPI_TRY(l_casn_1.clearBit(0), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));
    FAPI_TRY(l_wen_1.clearBit(0), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));
    FAPI_TRY(l_odt_4.clearBit(0, 4));

    //control word number code bits A[7:4]
    // JEDEC vs CCS swizzle here
    FAPI_TRY(l_address_16.clearBit(0, 16), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));
    FAPI_TRY(l_address_16.insert(i_rcd_num, 7, 1, 60), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));
    FAPI_TRY(l_address_16.insert(i_rcd_num, 6, 1, 61), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));
    FAPI_TRY(l_address_16.insert(i_rcd_num, 5, 1, 62), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));
    FAPI_TRY(l_address_16.insert(i_rcd_num, 4, 1, 63), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));

    //control word values RCD0 = A0, RCD1 = A1, RCD2 = A2, RCD3 = A3
    // JEDEC vs CCS swizzle here
    FAPI_TRY(l_address_16.insert(i_rcd_data, 0, 1, 63), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));
    FAPI_TRY(l_address_16.insert(i_rcd_data, 1, 1, 62), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));
    FAPI_TRY(l_address_16.insert(i_rcd_data, 2, 1, 61), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));
    FAPI_TRY(l_address_16.insert(i_rcd_data, 3, 1, 60), "mss_4bit_load: Error setting up buffers %s", mss::c_str(i_target));

    // Insert the delays
    FAPI_TRY(l_num_idles_16.insertFromRight(i_delay, 0, 16), "mss_4bit_load: Error setting up buffers %s",
             mss::c_str(i_target));

    // Send out to the CCS array
    FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                  io_ccs_inst_cnt,
                                  l_address_16,
                                  l_bank_3,
                                  l_activate_1,
                                  l_rasn_1,
                                  l_casn_1,
                                  l_wen_1,
                                  l_cke,
                                  l_csn_8,
                                  l_odt_4,
                                  l_ddr_cal_type_4,
                                  i_port_number), "mss_4bit_load: Error setting up CCS array0 %s", mss::c_str(i_target));

    FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                  io_ccs_inst_cnt,
                                  l_num_idles_16,
                                  l_num_repeat_16,
                                  l_data_20,
                                  l_read_compare_1,
                                  l_rank_cal_4,
                                  l_ddr_cal_enable_1,
                                  l_ccs_end_1), "mss_4bit_load: Error setting up CCS array1 %s", mss::c_str(i_target));

    io_ccs_inst_cnt++;

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Sends out RC09 and resets the DRAM
/// @param[in] i_target             Reference to MBA Target<fapi2::TARGET_TYPE_MBA>.
/// @param[in] i_port_number        MBA port number
/// @param[in] i_dimm - DIMM on which to operate
/// @param[in, out] io_cke          CKE bits to use
/// @param[in, out] io_ccs_inst_cnt  CCS instruction count
/// @return ReturnCode
fapi2::ReturnCode mss_rcd_load_workaround( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        const uint32_t i_port_number,
        const uint32_t i_dimm,
        fapi2::variable_buffer& io_cke,
        uint32_t& io_ccs_inst_cnt)
{
    // Hit RC09 + enable the CKE's
    {
        constexpr uint64_t CKE_PER_DIMM = 2;
        constexpr uint64_t CKE_PER_PORT = 4;

        // Setup the RCD number
        constexpr uint64_t RCD_NUM = 9;
        // Delay taken from the above delays
        constexpr uint64_t RCD_DELAY = 12;
        uint64_t l_rcd_data = 0;
        uint64_t l_rcd_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]; //[port][dimm]
        fapi2::buffer<uint64_t> l_rcd_cntl_wrd_64;

        // Enable the CKE's for this DIMM
        // 2 CKE per DIMM, 4 CKE per port (2 per DIMM and two DIMM per port)
        const uint64_t l_cke_start = (i_dimm * CKE_PER_DIMM) + (i_port_number * CKE_PER_PORT);
        FAPI_TRY(io_cke.setBit(l_cke_start, CKE_PER_DIMM), "failed to setup CKE %s", mss::c_str(i_target));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_RCD_CNTL_WORD_0_15, i_target, l_rcd_array));
        l_rcd_cntl_wrd_64 = l_rcd_array[i_port_number][i_dimm];

        // Issue that command
        l_rcd_cntl_wrd_64.extractToRight<RCD_NUM * 4, 4>(l_rcd_data);
        FAPI_TRY(mss_rcd_load_ddr4_4bit( i_target,
                                         i_port_number,
                                         i_dimm,
                                         io_cke,
                                         RCD_NUM,
                                         l_rcd_data,
                                         RCD_DELAY,
                                         io_ccs_inst_cnt), "mss_rcd_load: Failed to setup 4-bit CW %s", mss::c_str(i_target));
    }

    // Do the DRAM reset - toggle it on and toggle it off
    {
        constexpr uint64_t RESET_ON  = 0x02;
        constexpr uint64_t RESET_CLEAR  = 0x03;
        constexpr uint64_t RESET_RCW = 6;
        // Taken emperically from Nimbus
        constexpr uint64_t RCW_DELAY = 8000;

        // Reset...
        FAPI_TRY(mss_rcd_load_ddr4_4bit( i_target,
                                         i_port_number,
                                         i_dimm,
                                         io_cke,
                                         RESET_RCW,
                                         RESET_ON,
                                         RCW_DELAY,
                                         io_ccs_inst_cnt), "mss_rcd_load: Failed to setup 4-bit CW %s", mss::c_str(i_target));
        // ... Clear the reset
        FAPI_TRY(mss_rcd_load_ddr4_4bit( i_target,
                                         i_port_number,
                                         i_dimm,
                                         io_cke,
                                         RESET_RCW,
                                         RESET_CLEAR,
                                         RCW_DELAY,
                                         io_ccs_inst_cnt), "mss_rcd_load: Failed to setup 4-bit CW %s", mss::c_str(i_target));
    }
fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Writes RCD control words for DDR4 register.
/// @param[in] i_target             Reference to MBA Target<fapi2::TARGET_TYPE_MBA>.
/// @param[in] i_port_number        MBA port number
/// @param[in, out] io_cke          CKE bits to use
/// @param[in, out] io_ccs_inst_cnt  CCS instruction count
/// @return ReturnCode
fapi2::ReturnCode mss_rcd_load_ddr4(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    const uint32_t i_port_number,
    fapi2::variable_buffer& io_cke,
    uint32_t& io_ccs_inst_cnt)
{
    // Vector of RCD commands and their delays
    // First in the pair is the RCD number
    static const std::vector<std::pair<uint64_t, uint64_t>> RCD_NUM_AND_DELAY =
    {
        {0, 12},
        {1, 12},
        {2, 4000},
        {3, 12},
        {4, 12},
        {5, 12},
        {6, 12},
        {7, 12},
        {8, 12},
        // Note: 9 is missing this is intentional
        // Per a supplier workaround, we need to set this guy last to clear out any corruption that could happen
        {10, 4000},
        {11, 12},
        {12, 12},
        {13, 12},
        {14, 12},
        {15, 12},
    };

    uint32_t l_dimm_number = 0;
    fapi2::variable_buffer l_rcd_cntl_wrd_4(8);
    fapi2::variable_buffer l_rcd_cntl_wrd_8(8);
    fapi2::variable_buffer l_rcd_cntl_wrd_64(64);
    uint16_t l_num_ranks = 0;
    uint8_t l_num_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]; //[port][dimm]
    uint64_t l_rcd_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]; //[port][dimm]
    uint8_t l_dimm_type = 0;
    uint32_t l_cntlx_offset[] = {1, 2, 3, 7, 8, 9, 10, 11};
    uint8_t l_rcd_cntl_word_1x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_2x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_3x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_7x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_8x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_9x[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_Ax[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_rcd_cntl_word_Bx[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    // Dummy attribute for addtitional cntl words
    uint64_t l_rcdx_array = 0;

    fapi2::variable_buffer l_address_16(16);
    fapi2::variable_buffer l_bank_3(3);
    fapi2::variable_buffer l_activate_1(1);
    fapi2::variable_buffer l_rasn_1(1);
    fapi2::variable_buffer l_casn_1(1);
    fapi2::variable_buffer l_wen_1(1);
    fapi2::variable_buffer l_cke_8(8);
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

    FAPI_TRY(mss_create_rcd_ddr4(i_target));
    FAPI_TRY(l_rasn_1.setBit(0));
    FAPI_TRY(l_casn_1.setBit(0));
    FAPI_TRY(l_wen_1.setBit(0));
    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_odt_4.clearBit(0, 4));
    FAPI_TRY(l_activate_1.setBit(0));


    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target, l_num_ranks_array));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_RCD_CNTL_WORD_0_15, i_target, l_rcd_array));



    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_1x, i_target, l_rcd_cntl_word_1x));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_2x, i_target, l_rcd_cntl_word_2x));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_3x, i_target, l_rcd_cntl_word_3x));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_7x, i_target, l_rcd_cntl_word_7x));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_8x, i_target, l_rcd_cntl_word_8x));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_9x, i_target, l_rcd_cntl_word_9x));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_Ax, i_target, l_rcd_cntl_word_Ax));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_DDR4_RC_Bx, i_target, l_rcd_cntl_word_Bx));


    // Keep CKE's at current levels, waiting min Reset CKE exit time (tXPR) - 400 cycles
    FAPI_TRY(l_address_16.clearBit(0, 16), "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));
    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 400, 0, 16), "mss_rcd_load: Error setting up buffers %s",
             mss::c_str(i_target));
    FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                  io_ccs_inst_cnt,
                                  l_address_16,
                                  l_bank_3,
                                  l_activate_1,
                                  l_rasn_1,
                                  l_casn_1,
                                  l_wen_1,
                                  io_cke,
                                  l_csn_8,
                                  l_odt_4,
                                  l_ddr_cal_type_4,
                                  i_port_number), "mss_rcd_load: Error setting up CCS array0 %s", mss::c_str(i_target));

    FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                  io_ccs_inst_cnt,
                                  l_num_idles_16,
                                  l_num_repeat_16,
                                  l_data_20,
                                  l_read_compare_1,
                                  l_rank_cal_4,
                                  l_ddr_cal_enable_1,
                                  l_ccs_end_1), "mss_rcd_load: Error setting up CCS array1 %s", mss::c_str(i_target));

    io_ccs_inst_cnt++;

    FAPI_INF( "+++++++++++++++++++++ LOADING RCD CONTROL WORDS FOR %s PORT %d +++++++++++++++++++++", mss::c_str(i_target),
              i_port_number);

    for ( l_dimm_number = 0; l_dimm_number < MAX_DIMM_PER_PORT; l_dimm_number ++)
    {
        l_num_ranks = l_num_ranks_array[i_port_number][l_dimm_number];

        if (l_num_ranks == 0)
        {
            FAPI_INF( "%s PORT%d DIMM%d not configured. Num_ranks: %d", mss::c_str(i_target), i_port_number, l_dimm_number,
                      l_num_ranks);
        }
        else
        {
            FAPI_INF( "RCD SETTINGS FOR %s PORT%d DIMM%d ", mss::c_str(i_target), i_port_number, l_dimm_number);
            FAPI_INF( "RCD %s Control Word: 0x%016llX", mss::c_str(i_target), l_rcd_array[i_port_number][l_dimm_number]);
            FAPI_INF( "RCD %s Control Word X: 0x%016llX", mss::c_str(i_target), l_rcdx_array);

            // ALL active CS lines at a time.
            FAPI_TRY(generate_rcd_cs(i_target, l_dimm_number, l_csn_8, io_cke));

            // DBG1, DBG0, DBA1, DBA0 = 4`b0111
            FAPI_TRY(l_bank_3.setBit(0, 3), "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));
            // DACT_n is HIGH
            FAPI_TRY(l_activate_1.setBit(0), "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));
            // RAS_n/CAS_n/WE_n are LOW
            FAPI_TRY(l_rasn_1.clearBit(0), "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));
            FAPI_TRY(l_casn_1.clearBit(0), "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));
            FAPI_TRY(l_wen_1.clearBit(0), "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));

            // Propogate through the 16, 4-bit control words
            FAPI_TRY(l_rcd_cntl_wrd_64.insert(l_rcd_array[i_port_number][l_dimm_number]),
                     "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));

            for ( const auto& l_rcd_pair : RCD_NUM_AND_DELAY )
            {
                const auto l_rcd_number = l_rcd_pair.first;
                const auto l_rcd_delay = l_rcd_pair.second;
                uint64_t l_rcd_data = 0;
                FAPI_TRY(l_rcd_cntl_wrd_64.extractToRight(l_rcd_data, 4 * l_rcd_number, 4), "mss_rcd_load: Error setting up buffers %s",
                         mss::c_str(i_target));
                FAPI_TRY(mss_rcd_load_ddr4_4bit( i_target,
                                                 i_port_number,
                                                 l_dimm_number,
                                                 io_cke,
                                                 l_rcd_number,
                                                 l_rcd_data,
                                                 l_rcd_delay,
                                                 io_ccs_inst_cnt), "mss_rcd_load: Failed to setup 4-bit CW %s", mss::c_str(i_target));
            }

            // 8-bit Control words
            for ( uint8_t l_rcd_number = 0; l_rcd_number <= 7; l_rcd_number ++)
            {
                //FAPI_TRY(l_bank_3.clearBit(0, 3);
                FAPI_TRY(l_address_16.clearBit(0, 16), "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));

                switch(l_cntlx_offset[l_rcd_number])
                {
                    case 0x01:
                        FAPI_TRY(l_rcd_cntl_wrd_8.insert(l_rcd_cntl_word_1x[i_port_number][l_dimm_number], 0, 8, 0),
                                 "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));
                        break;

                    case 0x02:
                        FAPI_TRY(l_rcd_cntl_wrd_8.insert(l_rcd_cntl_word_2x[i_port_number][l_dimm_number], 0, 8, 0),
                                 "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));
                        break;

                    case 0x03:
                        FAPI_TRY(l_rcd_cntl_wrd_8.insert(l_rcd_cntl_word_3x[i_port_number][l_dimm_number], 0, 8, 0),
                                 "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));
                        break;

                    case 0x07:
                        FAPI_TRY(l_rcd_cntl_wrd_8.insert(l_rcd_cntl_word_7x[i_port_number][l_dimm_number], 0, 8, 0),
                                 "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));
                        break;

                    case 0x08:
                        FAPI_TRY(l_rcd_cntl_wrd_8.insert(l_rcd_cntl_word_8x[i_port_number][l_dimm_number], 0, 8, 0),
                                 "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));
                        break;

                    case 0x09:
                        FAPI_TRY(l_rcd_cntl_wrd_8.insert(l_rcd_cntl_word_9x[i_port_number][l_dimm_number], 0, 8, 0),
                                 "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));
                        break;

                    case 0x0a:
                        FAPI_TRY(l_rcd_cntl_wrd_8.insert(l_rcd_cntl_word_Ax[i_port_number][l_dimm_number], 0, 8, 0),
                                 "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));
                        break;

                    case 0x0b:
                    default:
                        FAPI_TRY(l_rcd_cntl_wrd_8.insert(l_rcd_cntl_word_Bx[i_port_number][l_dimm_number], 0, 8, 0),
                                 "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target));
                        break;
                }

                //control word number code bits A[11:8]
                FAPI_TRY(l_address_16.insert(l_cntlx_offset[l_rcd_number], 11, 1, 28), "mss_rcd_load: Error setting up buffers %s",
                         mss::c_str(i_target));
                FAPI_TRY(l_address_16.insert(l_cntlx_offset[l_rcd_number], 10, 1, 29), "mss_rcd_load: Error setting up buffers %s",
                         mss::c_str(i_target));
                FAPI_TRY(l_address_16.insert(l_cntlx_offset[l_rcd_number],  9, 1, 30), "mss_rcd_load: Error setting up buffers %s",
                         mss::c_str(i_target));
                FAPI_TRY(l_address_16.insert(l_cntlx_offset[l_rcd_number],  8, 1, 31), "mss_rcd_load: Error setting up buffers %s",
                         mss::c_str(i_target));

                //control word values RCD0 = A0, RCD1 = A1, RCD2 = A2, RCD3 = A3, RCD4=A4, RCD5=A5, RCD6=A6, RCD7=A7
                //
                FAPI_TRY(l_address_16.insert(l_rcd_cntl_wrd_8, 0, 1, 7), "mss_rcd_load: Error setting up buffers %s",
                         mss::c_str(i_target));
                FAPI_TRY(l_address_16.insert(l_rcd_cntl_wrd_8, 1, 1, 6), "mss_rcd_load: Error setting up buffers %s",
                         mss::c_str(i_target));
                FAPI_TRY(l_address_16.insert(l_rcd_cntl_wrd_8, 2, 1, 5), "mss_rcd_load: Error setting up buffers %s",
                         mss::c_str(i_target));
                FAPI_TRY(l_address_16.insert(l_rcd_cntl_wrd_8, 3, 1, 4), "mss_rcd_load: Error setting up buffers %s",
                         mss::c_str(i_target));
                FAPI_TRY(l_address_16.insert(l_rcd_cntl_wrd_8, 4, 1, 3), "mss_rcd_load: Error setting up buffers %s",
                         mss::c_str(i_target));
                FAPI_TRY(l_address_16.insert(l_rcd_cntl_wrd_8, 5, 1, 2), "mss_rcd_load: Error setting up buffers %s",
                         mss::c_str(i_target));
                FAPI_TRY(l_address_16.insert(l_rcd_cntl_wrd_8, 6, 1, 1), "mss_rcd_load: Error setting up buffers %s",
                         mss::c_str(i_target));
                FAPI_TRY(l_address_16.insert(l_rcd_cntl_wrd_8, 7, 1, 0), "mss_rcd_load: Error setting up buffers %s",
                         mss::c_str(i_target));

                // Send out to the CCS array
                if ( l_rcd_number == 2 ) // CW RC3x
                {
                    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 4000, 0 , 16 ),
                             "mss_rcd_load: Error setting up buffers %s", mss::c_str(i_target)); // wait tStab for clock timing rcd words
                }
                else
                {
                    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 12, 0, 16), "mss_rcd_load: Error setting up buffers %s",
                             mss::c_str(i_target));
                }


                FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                              io_ccs_inst_cnt,
                                              l_address_16,
                                              l_bank_3,
                                              l_activate_1,
                                              l_rasn_1,
                                              l_casn_1,
                                              l_wen_1,
                                              io_cke,
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

                io_ccs_inst_cnt++;

            }

            // Does the RCD load workaround here
            FAPI_TRY(mss_rcd_load_workaround( i_target,
                                              i_port_number,
                                              l_dimm_number,
                                              io_cke,
                                              io_ccs_inst_cnt), "mss_rcd_load: failed RCD workaround %s", mss::c_str(i_target));
        }
    }

    // Note: preserving CKE's here - it's important to avoid DRAM corruption
    FAPI_TRY(mss_ccs_set_end_bit( i_target, io_ccs_inst_cnt - 1, io_cke), "CCS_SET_END_BIT FAILED FAPI_TRY %s",
             mss::c_str(i_target));
    io_ccs_inst_cnt = 0;

    FAPI_TRY(mss_execute_ccs_inst_array(i_target, 10, 10), " EXECUTE_CCS_INST_ARRAY FAILED FAPI_TRY %s",
             mss::c_str(i_target));
fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Writes RCD control words for DDR4 register.
/// @param[in] i_target             Reference to MBA Target<fapi2::TARGET_TYPE_MBA>.
/// @param[in] i_port_number        MBA port number
/// @param[in, out] io_ccs_inst_cnt  CCS instruction count
/// @return ReturnCode
fapi2::ReturnCode mss_mrs_load_ddr4(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    const uint32_t i_port_number,
    uint32_t& io_ccs_inst_cnt
)
{

    uint32_t l_dimm_number = 0;
    uint32_t l_rank_number = 0;
    uint32_t l_mrs_number = 0;
    uint16_t l_MRS0 = 0;
    uint16_t l_MRS1 = 0;
    uint16_t l_MRS2 = 0;
    uint16_t l_MRS3 = 0;
    uint16_t l_MRS4 = 0;
    uint16_t l_MRS5 = 0;
    uint16_t l_MRS6 = 0;
    uint16_t l_num_ranks = 0;
    uint8_t l_num_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]; //[port][dimm]
    uint8_t l_num_master_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]; //[port][dimm]
    uint8_t l_dimm_type = 0;
    uint8_t l_is_sim = 0;
    uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]; //address_mirror_map[port][dimm]
    uint8_t l_dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_dram_bl = 0;
    uint8_t l_read_bt = 0; //Read Burst Type
    uint8_t l_dram_cl = 0;
    uint8_t l_test_mode = 0; //TEST MODE
    uint8_t l_dll_reset = 0; //DLL Reset
    uint8_t l_dram_wr = 0; //DRAM write recovery
    uint8_t l_dram_rtp = 0; //DRAM RTP - read to precharge
    uint8_t l_dll_precharge = 0; //DLL Control For Precharge
    uint8_t l_dll_enable = 0; //DLL Enable
    uint8_t l_out_drv_imp_cntl[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_dram_rtt_nom[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM];
    uint8_t l_dram_al = 0;
    uint8_t l_wr_lvl = 0; //write leveling enable
    uint8_t l_tdqs_enable = 0; //TDQS Enable
    uint8_t l_q_off = 0; //Qoff - Output buffer Enable
    uint8_t l_lpasr = 0; // Low Power Auto Self-Refresh -- new not yet supported
    uint8_t l_cwl = 0; // CAS Write Latency
    uint8_t l_dram_rtt_wr[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM];
    uint8_t l_write_crc = 0; // CAS Write Latency
    uint8_t l_mpr_op = 0; // MPR Op
    uint8_t l_mpr_page = 0; // MPR Page Selection  - NEW
    uint8_t l_geardown_mode = 0; // Gear Down Mode  - NEW
    uint8_t l_dram_access = 0; // per dram accessibility  - NEW
    uint8_t l_temp_readout = 0; // Temperature sensor readout  - NEW
    uint8_t l_fine_refresh = 0; // fine refresh mode  - NEW
    uint8_t l_wr_latency = 0; // write latency for CRC and DM  - NEW
    uint8_t l_read_format = 0; // MPR READ FORMAT  - NEW
    uint8_t l_max_pd_mode = 0; // Max Power down mode -  NEW
    uint8_t l_temp_ref_range = 0; // Temp ref range -  NEW
    uint8_t l_temp_ref_mode = 0; // Temp controlled ref mode -  NEW
    uint8_t l_vref_mon = 0; // Internal Vref Monitor -  NEW
    uint8_t l_cs_cmd_latency = 0; // CS to CMD/ADDR Latency -  NEW
    uint8_t l_ref_abort = 0; // Self Refresh Abort -  NEW
    uint8_t l_rd_pre_train_mode = 0; // Read Pre amble Training Mode -  NEW
    uint8_t l_rd_preamble = 0; // Read Pre amble -  NEW
    uint8_t l_wr_preamble = 0; // Write Pre amble -  NEW
    uint8_t l_ca_parity_latency = 0; //C/A Parity Latency Mode  -  NEW
    uint8_t l_crc_error_clear = 0; //CRC Error Clear  -  NEW
    uint8_t l_ca_parity_error_status = 0; //C/A Parity Error Status  -  NEW
    uint8_t l_odt_input_buffer = 0; //ODT Input Buffer during power down  -  NEW
    uint8_t l_rtt_park[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM]; //RTT_Park value  -  NEW
    uint8_t l_ca_parity = 0; //CA Parity Persistance Error  -  NEW
    uint8_t l_data_mask = 0; //Data Mask  -  NEW
    uint8_t l_write_dbi = 0; //Write DBI  -  NEW
    uint8_t l_read_dbi = 0; //Read DBI  -  NEW
    uint8_t l_vrefdq_train_value[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM]; //vrefdq_train value   -  NEW
    uint8_t l_vrefdq_train_range[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM]; //vrefdq_train range   -  NEW
    uint8_t l_vrefdq_train_enable[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM]; //vrefdq_train enable  -  NEW
    uint8_t l_tccd_l = 0; //tccd_l  -  NEW
    uint8_t l_dram_wr_rtp = 0x00;

    fapi2::buffer<uint64_t> l_data_64;
    fapi2::variable_buffer l_data_buffer_64(64);
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
    fapi2::variable_buffer l_num_idles_16_vref_train(16);
    fapi2::variable_buffer l_num_repeat_16(16);
    fapi2::variable_buffer l_data_20(20);
    fapi2::variable_buffer l_read_compare_1(1);
    fapi2::variable_buffer l_rank_cal_4(4);
    fapi2::variable_buffer l_ddr_cal_enable_1(1);
    fapi2::variable_buffer l_ccs_end_1(1);

    fapi2::variable_buffer l_mrs4(16);
    fapi2::variable_buffer l_mrs5(16);
    fapi2::variable_buffer l_mrs6(16);
    fapi2::variable_buffer l_mrs6_train_on(16);
    fapi2::variable_buffer l_mrs0(16);
    fapi2::variable_buffer l_mrs1(16);
    fapi2::variable_buffer l_mrs2(16);
    fapi2::variable_buffer l_mrs3(16);

    fapi2::variable_buffer l_data_buffer(64);

    FAPI_TRY(l_activate_1.setBit(0));
    FAPI_TRY(l_rasn_1.clearBit(0));
    FAPI_TRY(l_casn_1.clearBit(0));
    FAPI_TRY(l_wen_1.clearBit(0));
    FAPI_TRY(l_cke_4.clearBit(0, 4));
    FAPI_TRY(l_csn_8.clearBit(0, 8));
    FAPI_TRY(l_odt_4.clearBit(0, 4));

    FAPI_TRY(l_num_idles_16_vref_train.insertFromRight((uint32_t) 160, 0, 16));


    FAPI_INF( "+++++++++++++++++++++ LOADING MRS SETTINGS FOR PORT %d +++++++++++++++++++++", i_port_number);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target, l_num_ranks_array));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, l_num_master_ranks_array));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>() , l_is_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target, l_address_mirror_map));

    // WORKAROUNDS
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_CCS_MODEQ, l_data_64));
    l_data_64.setBit<61>();
    //Setting up CCS mode
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_CCS_MODEQ, l_data_64));


    FAPI_TRY(fapi2::getScom(i_target,  CEN_MBA_DDRPHY_WC_CONFIG3_P0, l_data_64));
    //Setting up CCS mode
    l_data_64.clearBit<48>();
    FAPI_TRY(fapi2::putScom(i_target,  CEN_MBA_DDRPHY_WC_CONFIG3_P0, l_data_64));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target, l_dram_stack));

    //MRS0
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_BL, i_target, l_dram_bl));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_RBT, i_target, l_read_bt));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CL, i_target, l_dram_cl));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TM, i_target, l_test_mode));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DLL_RESET, i_target, l_dll_reset));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WR, i_target, l_dram_wr));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WR, i_target, l_dram_rtp));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DLL_PPD, i_target, l_dll_precharge));


    if (l_dram_bl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_BL_BL8)
    {
        l_dram_bl = 0x00;
    }
    else if (l_dram_bl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_BL_OTF)
    {
        l_dram_bl = 0x80;
    }
    else if (l_dram_bl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_BL_BC4)
    {
        l_dram_bl = 0x40;
    }

    if ( (l_dram_wr == 10) )//&& (l_dram_rtp == 5) )
    {
        l_dram_wr_rtp = 0x00;
    }
    else if ( (l_dram_wr == 12) )//&& (l_dram_rtp == 6) )
    {
        l_dram_wr_rtp = 0x80;
    }
    else if ( (l_dram_wr == 13) )//&& (l_dram_rtp == 7) )
    {
        l_dram_wr_rtp = 0x40;
    }
    else if ( (l_dram_wr == 14) )//&& (l_dram_rtp == 8) )
    {
        l_dram_wr_rtp = 0xC0;
    }
    else if ( (l_dram_wr == 18) )//&& (l_dram_rtp == 9) )
    {
        l_dram_wr_rtp = 0x20;
    }
    else if ( (l_dram_wr == 20) )//&& (l_dram_rtp == 10) )
    {
        l_dram_wr_rtp = 0xA0;
    }
    else if ( (l_dram_wr == 24) )//&& (l_dram_rtp == 12) )
    {
        l_dram_wr_rtp = 0x60;
    }

    if (l_read_bt == fapi2::ENUM_ATTR_CEN_EFF_DRAM_RBT_SEQUENTIAL)
    {
        l_read_bt = 0x00;
    }
    else if (l_read_bt == fapi2::ENUM_ATTR_CEN_EFF_DRAM_RBT_INTERLEAVE)
    {
        l_read_bt = 0xFF;
    }

    if ((l_dram_cl > 8) && (l_dram_cl < 17))
    {
        l_dram_cl = l_dram_cl - 9;
    }
    else if ((l_dram_cl > 17) && (l_dram_cl < 25))
    {
        l_dram_cl = (l_dram_cl >> 1) - 1;
    }

    l_dram_cl = mss_reverse_8bits(l_dram_cl);

    if (l_test_mode == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TM_NORMAL)
    {
        l_test_mode = 0x00;
    }
    else if (l_test_mode == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TM_TEST)
    {
        l_test_mode = 0xFF;
    }

    if (l_dll_reset == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_RESET_YES)
    {
        l_dll_reset = 0xFF;
    }
    else if (l_dll_reset == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_RESET_NO)
    {
        l_dll_reset = 0x00;
    }

    if (l_dll_precharge == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_PPD_SLOWEXIT)
    {
        l_dll_precharge = 0x00;
    }
    else if (l_dll_precharge == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_PPD_FASTEXIT)
    {
        l_dll_precharge = 0xFF;
    }

    //MRS1
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DLL_ENABLE, i_target, l_dll_enable));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RON, i_target, l_out_drv_imp_cntl));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RTT_NOM, i_target, l_dram_rtt_nom));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_AL, i_target, l_dram_al));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE, i_target, l_wr_lvl));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TDQS, i_target, l_tdqs_enable));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER, i_target, l_q_off));


    if (l_dll_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_ENABLE_DISABLE)
    {
        l_dll_enable = 0x00;
    }
    else if (l_dll_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_ENABLE_ENABLE)
    {
        l_dll_enable = 0xFF;
    }

    if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_DISABLE)
    {
        l_dram_al = 0x00;
    }
    else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_1)
    {
        l_dram_al = 0x80;
    }
    else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_2)
    {
        l_dram_al = 0x40;
    }
    else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_3) //Jeremy
    {
        l_dram_al = 0xC0;
    }

    if (l_wr_lvl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE_DISABLE)
    {
        l_wr_lvl = 0x00;
    }
    else if (l_wr_lvl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE_ENABLE)
    {
        l_wr_lvl = 0xFF;
    }

    if (l_tdqs_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_DISABLE)
    {
        l_tdqs_enable = 0x00;
    }
    else if (l_tdqs_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_ENABLE)
    {
        l_tdqs_enable = 0xFF;
    }

    if (l_q_off == fapi2::ENUM_ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER_DISABLE)
    {
        l_q_off = 0xFF;
    }
    else if (l_q_off == fapi2::ENUM_ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER_ENABLE)
    {
        l_q_off = 0x00;
    }

    //MRS2

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_LPASR, i_target, l_lpasr));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CWL, i_target, l_cwl));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RTT_WR, i_target, l_dram_rtt_wr));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_WRITE_CRC, i_target, l_write_crc));


    if (l_lpasr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_LPASR_MANUAL_NORMAL)
    {
        l_lpasr = 0x00;
    }
    else if (l_lpasr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_LPASR_MANUAL_REDUCED)
    {
        l_lpasr = 0x80;
    }
    else if (l_lpasr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_LPASR_MANUAL_EXTENDED)
    {
        l_lpasr = 0x40;
    }
    else if (l_lpasr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_LPASR_ASR)
    {
        l_lpasr = 0xFF;
    }

    if ((l_cwl > 8) && (l_cwl < 13))
    {
        l_cwl = l_cwl - 9;
    }
    else if ((l_cwl > 13) && (l_cwl < 19))
    {
        l_cwl = (l_cwl >> 1) - 3;
    }
    else
    {
        //no correcct value for CWL was found
        FAPI_INF("ERROR: Improper CWL value found. Setting CWL to 9 and continuing...");
        l_cwl = 0;
    }

    l_cwl = mss_reverse_8bits(l_cwl);

    if ( l_write_crc == fapi2::ENUM_ATTR_CEN_EFF_WRITE_CRC_ENABLE)
    {
        l_write_crc = 0xFF;
    }
    else if (l_write_crc == fapi2::ENUM_ATTR_CEN_EFF_WRITE_CRC_DISABLE)
    {
        l_write_crc = 0x00;
    }

    //MRS3
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_MODE, i_target, l_mpr_op));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_PAGE, i_target, l_mpr_page));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_GEARDOWN_MODE, i_target, l_geardown_mode));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PER_DRAM_ACCESS, i_target, l_dram_access));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TEMP_READOUT, i_target, l_temp_readout));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_FINE_REFRESH_MODE, i_target, l_fine_refresh));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CRC_WR_LATENCY, i_target, l_wr_latency));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_RD_FORMAT, i_target, l_read_format));


    if (l_mpr_op == fapi2::ENUM_ATTR_CEN_EFF_MPR_MODE_ENABLE)
    {
        l_mpr_op = 0xFF;
    }
    else if (l_mpr_op == fapi2::ENUM_ATTR_CEN_EFF_MPR_MODE_DISABLE)
    {
        l_mpr_op = 0x00;
    }

    l_mpr_page = mss_reverse_8bits(l_mpr_page);

    if (l_dram_access == fapi2::ENUM_ATTR_CEN_EFF_PER_DRAM_ACCESS_ENABLE)
    {
        l_dram_access = 0xFF;
    }
    else if (l_dram_access == fapi2::ENUM_ATTR_CEN_EFF_PER_DRAM_ACCESS_DISABLE)
    {
        l_dram_access = 0x00;
    }

    if ( l_geardown_mode == fapi2::ENUM_ATTR_CEN_EFF_GEARDOWN_MODE_HALF)
    {
        l_geardown_mode = 0x00;
    }
    else if ( l_geardown_mode == fapi2::ENUM_ATTR_CEN_EFF_GEARDOWN_MODE_QUARTER)
    {
        l_geardown_mode = 0xFF;
    }

    if (l_temp_readout == fapi2::ENUM_ATTR_CEN_EFF_TEMP_READOUT_ENABLE)
    {
        l_temp_readout = 0xFF;
    }
    else if (l_temp_readout == fapi2::ENUM_ATTR_CEN_EFF_TEMP_READOUT_DISABLE)
    {
        l_temp_readout = 0x00;
    }

    if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_NORMAL)
    {
        l_fine_refresh = 0x00;
    }
    else if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_FIXED_2X)
    {
        l_fine_refresh = 0x80;
    }
    else if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_FIXED_4X)
    {
        l_fine_refresh = 0x40;
    }
    else if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_FLY_2X)
    {
        l_fine_refresh = 0xA0;
    }
    else if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_FLY_4X)
    {
        l_fine_refresh = 0x60;
    }

    if (l_wr_latency == fapi2::ENUM_ATTR_CEN_EFF_CRC_WR_LATENCY_4NCK)
    {
        l_wr_latency = 0x00;
    }
    else if (l_wr_latency == fapi2::ENUM_ATTR_CEN_EFF_CRC_WR_LATENCY_5NCK)
    {
        l_wr_latency = 0x80;
    }
    else if (l_wr_latency == fapi2::ENUM_ATTR_CEN_EFF_CRC_WR_LATENCY_6NCK)
    {
        l_wr_latency = 0xC0;
    }

    if (l_read_format == fapi2::ENUM_ATTR_CEN_EFF_MPR_RD_FORMAT_SERIAL)
    {
        l_read_format = 0x00;
    }
    else if (l_read_format == fapi2::ENUM_ATTR_CEN_EFF_MPR_RD_FORMAT_PARALLEL)
    {
        l_read_format = 0x80;
    }
    else if (l_read_format == fapi2::ENUM_ATTR_CEN_EFF_MPR_RD_FORMAT_STAGGERED)
    {
        l_read_format = 0x40;
    }
    else if (l_read_format == fapi2::ENUM_ATTR_CEN_EFF_MPR_RD_FORMAT_RESERVED_TEMP)
    {
        l_read_format = 0xC0;
    }

    //MRS4
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MAX_POWERDOWN_MODE, i_target, l_max_pd_mode));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TEMP_REF_RANGE, i_target, l_temp_ref_range));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TEMP_REF_MODE, i_target, l_temp_ref_mode));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_INT_VREF_MON, i_target, l_vref_mon));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CS_CMD_LATENCY, i_target, l_cs_cmd_latency));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SELF_REF_ABORT, i_target, l_ref_abort));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_RD_PREAMBLE_TRAIN, i_target, l_rd_pre_train_mode));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_RD_PREAMBLE, i_target, l_rd_preamble));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_WR_PREAMBLE, i_target, l_wr_preamble));


    if ( l_max_pd_mode == fapi2::ENUM_ATTR_CEN_EFF_MAX_POWERDOWN_MODE_ENABLE)
    {
        l_max_pd_mode = 0xF0;
    }
    else if ( l_max_pd_mode == fapi2::ENUM_ATTR_CEN_EFF_MAX_POWERDOWN_MODE_DISABLE)
    {
        l_max_pd_mode = 0x00;
    }

    if (l_temp_ref_range == fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_RANGE_NORMAL)
    {
        l_temp_ref_range = 0x00;
    }
    else if ( l_temp_ref_range == fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_RANGE_EXTEND)
    {
        l_temp_ref_range = 0xFF;
    }

    if (l_temp_ref_mode == fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_MODE_ENABLE)
    {
        l_temp_ref_mode = 0x80;
    }
    else if (l_temp_ref_mode == fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_MODE_DISABLE)
    {
        l_temp_ref_mode = 0x00;
    }

    if ( l_vref_mon == fapi2::ENUM_ATTR_CEN_EFF_INT_VREF_MON_ENABLE)
    {
        l_vref_mon = 0xFF;
    }
    else if ( l_vref_mon == fapi2::ENUM_ATTR_CEN_EFF_INT_VREF_MON_DISABLE)
    {
        l_vref_mon = 0x00;
    }


    if ( l_cs_cmd_latency == 3)
    {
        l_cs_cmd_latency = 0x80;
    }
    else if (l_cs_cmd_latency == 4)
    {
        l_cs_cmd_latency = 0x40;
    }
    else if (l_cs_cmd_latency == 5)
    {
        l_cs_cmd_latency = 0xC0;
    }
    else if (l_cs_cmd_latency == 6)
    {
        l_cs_cmd_latency = 0x20;
    }
    else if (l_cs_cmd_latency == 8)
    {
        l_cs_cmd_latency = 0xA0;
    }

    if (l_ref_abort == fapi2::ENUM_ATTR_CEN_EFF_SELF_REF_ABORT_ENABLE)
    {
        l_ref_abort = 0xFF;
    }
    else if (l_ref_abort == fapi2::ENUM_ATTR_CEN_EFF_SELF_REF_ABORT_DISABLE)
    {
        l_ref_abort = 0x00;
    }

    if (l_rd_pre_train_mode == fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_TRAIN_ENABLE)
    {
        l_rd_pre_train_mode = 0xFF;
    }
    else if (l_rd_pre_train_mode == fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_TRAIN_DISABLE)
    {
        l_rd_pre_train_mode = 0x00;
    }

    if (l_rd_preamble == fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_1NCLK)
    {
        l_rd_preamble = 0x00;
    }
    else if (l_rd_preamble == fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_2NCLK)
    {
        l_rd_preamble = 0xFF;
    }

    if (l_wr_preamble == fapi2::ENUM_ATTR_CEN_EFF_WR_PREAMBLE_1NCLK)
    {
        l_wr_preamble = 0x00;
    }
    else if (l_wr_preamble == fapi2::ENUM_ATTR_CEN_EFF_WR_PREAMBLE_2NCLK)
    {
        l_wr_preamble = 0xFF;
    }


    //MRS5
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CA_PARITY_LATENCY , i_target, l_ca_parity_latency));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CRC_ERROR_CLEAR , i_target, l_crc_error_clear));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CA_PARITY_ERROR_STATUS , i_target, l_ca_parity_error_status));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_ODT_INPUT_BUFF , i_target, l_odt_input_buffer));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RTT_PARK , i_target, l_rtt_park));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CA_PARITY , i_target, l_ca_parity));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DATA_MASK , i_target, l_data_mask));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_WRITE_DBI , i_target, l_write_dbi));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_READ_DBI , i_target, l_read_dbi));



    if (l_ca_parity_latency == 4)
    {
        l_ca_parity_latency = 0x80;
    }
    else if (l_ca_parity_latency == 5)
    {
        l_ca_parity_latency = 0x40;
    }
    else if (l_ca_parity_latency == 6)
    {
        l_ca_parity_latency = 0xC0;
    }
    else if (l_ca_parity_latency == 8)
    {
        l_ca_parity_latency = 0x20;
    }
    else if (l_ca_parity_latency == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_LATENCY_DISABLE)
    {
        l_ca_parity_latency = 0x00;
    }

    if (l_crc_error_clear == fapi2::ENUM_ATTR_CEN_EFF_CRC_ERROR_CLEAR_ERROR)
    {
        l_crc_error_clear = 0xFF;
    }
    else if (l_crc_error_clear == fapi2::ENUM_ATTR_CEN_EFF_CRC_ERROR_CLEAR_CLEAR)
    {
        l_crc_error_clear = 0x00;
    }

    if (l_ca_parity_error_status == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_ERROR_STATUS_ERROR)
    {
        l_ca_parity_error_status = 0xFF;
    }
    else if (l_ca_parity_error_status == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_ERROR_STATUS_CLEAR)
    {
        l_ca_parity_error_status = 0x00;
    }

    if (l_odt_input_buffer == fapi2::ENUM_ATTR_CEN_EFF_ODT_INPUT_BUFF_ACTIVATED)
    {
        l_odt_input_buffer = 0x00;
    }
    else if (l_odt_input_buffer == fapi2::ENUM_ATTR_CEN_EFF_ODT_INPUT_BUFF_DEACTIVATED)
    {
        l_odt_input_buffer = 0xFF;
    }


    if (l_ca_parity == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_ENABLE)
    {
        l_ca_parity = 0xFF;
    }
    else if (l_ca_parity == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_DISABLE)
    {
        l_ca_parity = 0x00;
    }

    if (l_data_mask == fapi2::ENUM_ATTR_CEN_EFF_DATA_MASK_DISABLE)
    {
        l_data_mask = 0x00;
    }
    else if (l_data_mask == fapi2::ENUM_ATTR_CEN_EFF_DATA_MASK_ENABLE)
    {
        l_data_mask = 0xFF;
    }

    if (l_write_dbi == fapi2::ENUM_ATTR_CEN_EFF_WRITE_DBI_DISABLE)
    {
        l_write_dbi = 0x00;
    }
    else if (l_write_dbi == fapi2::ENUM_ATTR_CEN_EFF_WRITE_DBI_ENABLE)
    {
        l_write_dbi = 0xFF;
    }

    if (l_read_dbi == fapi2::ENUM_ATTR_CEN_EFF_READ_DBI_DISABLE)
    {
        l_read_dbi = 0x00;
    }
    else if (l_read_dbi == fapi2::ENUM_ATTR_CEN_EFF_READ_DBI_ENABLE)
    {
        l_read_dbi = 0xFF;
    }

    //MRS6
    FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, i_target, l_vrefdq_train_value));
    FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE, i_target, l_vrefdq_train_range));
    FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target, l_vrefdq_train_enable));
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
    FAPI_TRY(l_cke_4.setBit(0, 4));
    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_address_16.clearBit(0, 16));
    FAPI_TRY(l_odt_4.clearBit(0, 4));
    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 400, 0, 16));
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

    io_ccs_inst_cnt++;

    // Dimm 0-1
    for ( l_dimm_number = 0; l_dimm_number < MAX_DIMM_PER_PORT; l_dimm_number ++)
    {
        //if the dram stack type is a 3DS dimm
        if(l_dram_stack[i_port_number][l_dimm_number]  == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
        {
            FAPI_INF("DIMM is a 3DS l_type, using num_master_ranks_array");
            l_num_ranks = l_num_master_ranks_array[i_port_number][l_dimm_number];
        }
        else
        {
            l_num_ranks = l_num_ranks_array[i_port_number][l_dimm_number];
        }

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

                //For DDR4:
                //Address 14 = Address 17, Address 15 = BG1
                FAPI_TRY(l_mrs0.insert((uint8_t) l_dram_bl, 0, 2, 0));
                FAPI_TRY(l_mrs0.insert((uint8_t) l_dram_cl, 2, 1, 0));
                FAPI_TRY(l_mrs0.insert((uint8_t) l_read_bt, 3, 1, 0));
                FAPI_TRY(l_mrs0.insert((uint8_t) l_dram_cl, 4, 3, 1));
                FAPI_TRY(l_mrs0.insert((uint8_t) l_test_mode, 7, 1));
                FAPI_TRY(l_mrs0.insert((uint8_t) l_dll_reset, 8, 1));
                FAPI_TRY(l_mrs0.insert((uint8_t) l_dram_wr_rtp, 9, 3));
                FAPI_TRY(l_mrs0.insert((uint8_t) 0x00, 12, 4));

                FAPI_TRY(l_mrs0.extract(l_MRS0, 0, 16));

                if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_DISABLE)
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0x00;
                }
                else if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] ==
                         fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM240) //not supported
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0x20;
                    FAPI_INF("DRAM RTT_NOM is configured for 240 OHM which is not supported.");
                }
                else if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] ==
                         fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM48) //not supported
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0xA0;
                    FAPI_INF("DRAM RTT_NOM is configured for 48 OHM which is not supported.");
                }
                else if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM40)
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0xC0;
                }
                else if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM60)
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0x80;
                }
                else if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM120)
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0x40;
                }
                else if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] ==
                         fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM80) // not supported
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0x60;
                    FAPI_INF("DRAM RTT_NOM is configured for 80 OHM which is not supported.");
                }
                else if (l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] ==
                         fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM34) // not supported
                {
                    l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number] = 0xE0;
                    FAPI_INF("DRAM RTT_NOM is configured for 34 OHM which is not supported.");
                }

                if (l_out_drv_imp_cntl[i_port_number][l_dimm_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_OHM34)
                {
                    l_out_drv_imp_cntl[i_port_number][l_dimm_number] = 0x00;
                }
                else if (l_out_drv_imp_cntl[i_port_number][l_dimm_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_OHM48)
                {
                    l_out_drv_imp_cntl[i_port_number][l_dimm_number] = 0x80;
                }

                //For DDR4:
                //Address 14 = Address 17, Address 15 = BG1
                FAPI_TRY(l_mrs1.insert((uint8_t) l_dll_enable, 0, 1, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_out_drv_imp_cntl[i_port_number][l_dimm_number], 1, 2, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_dram_al, 3, 2, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) 0x00, 5, 2));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_wr_lvl, 7, 1, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_dram_rtt_nom[i_port_number][l_dimm_number][l_rank_number], 8, 3, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_tdqs_enable, 11, 1, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) l_q_off, 12, 1, 0));
                FAPI_TRY(l_mrs1.insert((uint8_t) 0x00, 13, 3));


                FAPI_TRY(l_mrs1.extract(l_MRS1, 0, 16));


                if (l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_DISABLE)
                {
                    l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] = 0x00;
                }
                else if (l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_OHM120)
                {
                    l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] = 0x80;
                }
                else if (l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] ==
                         240)//fapi2::ENUM_ATTR_CEN_EFF_DRAM_RTT_WR_OHM240)
                {
                    l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] = 0x40;
                }
                else if (l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] ==
                         0xFF)//fapi2::ENUM_ATTR_CEN_EFF_DRAM_RTT_WR_HIGHZ)
                {
                    l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number] = 0xFF;
                }

                FAPI_TRY(l_mrs2.insert((uint8_t) 0x00, 0, 3));
                FAPI_TRY(l_mrs2.insert((uint8_t) l_cwl, 3, 3));
                FAPI_TRY(l_mrs2.insert((uint8_t) l_lpasr, 6, 2));
                FAPI_TRY(l_mrs2.insert((uint8_t) 0x00, 8, 1));
                FAPI_TRY(l_mrs2.insert((uint8_t) l_dram_rtt_wr[i_port_number][l_dimm_number][l_rank_number], 9, 2));
                FAPI_TRY(l_mrs2.insert((uint8_t) 0x00, 11, 1));
                FAPI_TRY(l_mrs2.insert((uint8_t) l_write_crc, 12, 1));
                FAPI_TRY(l_mrs2.insert((uint8_t) 0x00, 13, 2));

                FAPI_TRY(l_mrs2.extract(l_MRS2, 0, 16));

                FAPI_TRY(l_mrs3.insert((uint8_t) l_mpr_page, 0, 2));
                FAPI_TRY(l_mrs3.insert((uint8_t) l_mpr_op, 2, 1));
                FAPI_TRY(l_mrs3.insert((uint8_t) l_geardown_mode, 3, 1));
                FAPI_TRY(l_mrs3.insert((uint8_t) l_dram_access, 4, 1));
                FAPI_TRY(l_mrs3.insert((uint8_t) l_temp_readout, 5, 1));
                FAPI_TRY(l_mrs3.insert((uint8_t) l_fine_refresh, 6, 3));
                FAPI_TRY(l_mrs3.insert((uint8_t) l_wr_latency, 9, 2));
                FAPI_TRY(l_mrs3.insert((uint8_t) l_read_format, 11, 2));
                FAPI_TRY(l_mrs3.insert((uint8_t) 0x00, 13, 2));


                FAPI_TRY(l_mrs3.extract(l_MRS3, 0, 16));

                FAPI_TRY(l_mrs4.insert((uint8_t) 0x00, 0, 1));
                FAPI_TRY(l_mrs4.insert((uint8_t) l_max_pd_mode, 1, 1));
                FAPI_TRY(l_mrs4.insert((uint8_t) l_temp_ref_range, 2, 1));
                FAPI_TRY(l_mrs4.insert((uint8_t) l_temp_ref_mode, 3, 1));
                FAPI_TRY(l_mrs4.insert((uint8_t) l_vref_mon, 4, 1));
                FAPI_TRY(l_mrs4.insert((uint8_t) 0x00, 5, 1));
                FAPI_TRY(l_mrs4.insert((uint8_t) l_cs_cmd_latency, 6, 3));
                FAPI_TRY(l_mrs4.insert((uint8_t) l_ref_abort, 9, 1));
                FAPI_TRY(l_mrs4.insert((uint8_t) l_rd_pre_train_mode, 10, 1));
                FAPI_TRY(l_mrs4.insert((uint8_t) l_rd_preamble, 11, 1));
                FAPI_TRY(l_mrs4.insert((uint8_t) l_wr_preamble, 12, 1));
                FAPI_TRY(l_mrs4.extract(l_MRS4, 0, 16));


                //MRS5
                if (l_rtt_park[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_DISABLE)
                {
                    l_rtt_park[i_port_number][l_dimm_number][l_rank_number] = 0x00;
                }
                else if (l_rtt_park[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_60OHM)
                {
                    l_rtt_park[i_port_number][l_dimm_number][l_rank_number] = 0x80;
                }
                else if (l_rtt_park[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_40OHM)
                {
                    l_rtt_park[i_port_number][l_dimm_number][l_rank_number] = 0xC0;
                }
                else if (l_rtt_park[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_120OHM)
                {
                    l_rtt_park[i_port_number][l_dimm_number][l_rank_number] = 0x40;
                }
                else if (l_rtt_park[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_240OHM)
                {
                    l_rtt_park[i_port_number][l_dimm_number][l_rank_number] = 0x20;
                }
                else if (l_rtt_park[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_48OHM)
                {
                    l_rtt_park[i_port_number][l_dimm_number][l_rank_number] = 0xA0;
                }
                else if (l_rtt_park[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_80OHM)
                {
                    l_rtt_park[i_port_number][l_dimm_number][l_rank_number] = 0x60;
                }
                else if (l_rtt_park[i_port_number][l_dimm_number][l_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_34OHM)
                {
                    l_rtt_park[i_port_number][l_dimm_number][l_rank_number] = 0xE0;
                }

                FAPI_TRY(l_mrs5.insert((uint8_t) l_ca_parity_latency, 0, 2));
                FAPI_TRY(l_mrs5.insert((uint8_t) l_crc_error_clear, 3, 1));
                FAPI_TRY(l_mrs5.insert((uint8_t) l_ca_parity_error_status, 4, 1));
                FAPI_TRY(l_mrs5.insert((uint8_t) l_odt_input_buffer, 5, 1));
                FAPI_TRY(l_mrs5.insert((uint8_t) l_rtt_park[i_port_number][l_dimm_number][l_rank_number], 6, 3));
                FAPI_TRY(l_mrs5.insert((uint8_t) l_ca_parity, 9, 1));
                FAPI_TRY(l_mrs5.insert((uint8_t) l_data_mask, 10, 1));
                FAPI_TRY(l_mrs5.insert((uint8_t) l_write_dbi, 11, 1));
                FAPI_TRY(l_mrs5.insert((uint8_t) l_read_dbi, 12, 1));
                FAPI_TRY(l_mrs5.insert((uint8_t) 0x00, 13, 2));


                FAPI_TRY(l_mrs5.extract(l_MRS5, 0, 16));

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
                    l_vrefdq_train_enable[i_port_number][l_dimm_number][l_rank_number] = 0xFF;
                }
                else if (l_vrefdq_train_enable[i_port_number][l_dimm_number][l_rank_number] ==
                         fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE)
                {
                    l_vrefdq_train_enable[i_port_number][l_dimm_number][l_rank_number] = 0x00;
                }

                FAPI_TRY(l_mrs6.insert((uint8_t) l_vrefdq_train_value[i_port_number][l_dimm_number][l_rank_number], 0, 6));
                FAPI_TRY(l_mrs6.insert((uint8_t) l_vrefdq_train_range[i_port_number][l_dimm_number][l_rank_number], 6, 1));
                FAPI_TRY(l_mrs6.insert((uint8_t) l_vrefdq_train_enable[i_port_number][l_dimm_number][l_rank_number], 7, 1));
                FAPI_TRY(l_mrs6.insert((uint8_t) 0x00, 8, 2));
                FAPI_TRY(l_mrs6.insert((uint8_t) l_tccd_l, 10, 3));
                FAPI_TRY(l_mrs6.insert((uint8_t) 0x00, 13, 2));

                FAPI_TRY(l_mrs6_train_on.insert((uint8_t) l_vrefdq_train_value[i_port_number][l_dimm_number][l_rank_number], 0, 6));
                FAPI_TRY(l_mrs6_train_on.insert((uint8_t) l_vrefdq_train_range[i_port_number][l_dimm_number][l_rank_number], 6, 1));
                FAPI_TRY(l_mrs6_train_on.insert((uint8_t) 0xff, 7, 1));
                FAPI_TRY(l_mrs6_train_on.insert((uint8_t) 0x00, 8, 2));
                FAPI_TRY(l_mrs6_train_on.insert((uint8_t) l_tccd_l, 10, 3));
                FAPI_TRY(l_mrs6_train_on.insert((uint8_t) 0x00, 13, 2));


                FAPI_TRY(l_mrs6.extract(l_MRS6, 0, 16));

                FAPI_INF( "MRS 0: 0x%04X", l_MRS0);
                FAPI_INF( "MRS 1: 0x%04X", l_MRS1);
                FAPI_INF( "MRS 2: 0x%04X", l_MRS2);
                FAPI_INF( "MRS 3: 0x%04X", l_MRS3);
                FAPI_INF( "MRS 4: 0x%04X", l_MRS4);
                FAPI_INF( "MRS 5: 0x%04X", l_MRS5);
                FAPI_INF( "MRS 6: 0x%04X", l_MRS6);


                // Only corresponding CS to rank
                FAPI_TRY(l_csn_8.setBit(0, 8));
                FAPI_TRY(l_csn_8.clearBit(l_rank_number + 4 * l_dimm_number));


                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target, l_dram_stack));


                FAPI_INF( "Stack Type: %d\n", l_dram_stack[0][0]);

                FAPI_TRY(mss_disable_cid(i_target, l_csn_8, l_cke_4));

                // Propogate through the 4 MRS cmds
                for ( l_mrs_number = 0; l_mrs_number < 7; l_mrs_number ++)
                {
                    //l_mrs_number = 1;
                    // Copying the current MRS into address buffer matching the MRS_array order
                    // Setting the bank address
                    if (l_mrs_number == 0)
                    {
                        FAPI_TRY(l_address_16.insert(l_mrs3, 0, 16, 0));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5));
                    }
                    else if ( l_mrs_number == 1)
                    {

                        FAPI_TRY(l_address_16.insert(l_mrs6, 0, 16, 0));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS6_BA, 0, 1, 7));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS6_BA, 1, 1, 6));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS6_BA, 2, 1, 5));
                    }
                    else if ( l_mrs_number == 2)
                    {
                        FAPI_TRY(l_address_16.insert(l_mrs5, 0, 16, 0));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS5_BA, 0, 1, 7));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS5_BA, 1, 1, 6));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS5_BA, 2, 1, 5));
                    }
                    else if ( l_mrs_number == 3)
                    {
                        FAPI_TRY(l_address_16.insert(l_mrs4, 0, 16, 0));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS4_BA, 0, 1, 7));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS4_BA, 1, 1, 6));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS4_BA, 2, 1, 5));
                    }
                    else if ( l_mrs_number == 4)
                    {
                        FAPI_TRY(l_address_16.insert(l_mrs2, 0, 16, 0));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS2_BA, 0, 1, 7));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS2_BA, 1, 1, 6));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS2_BA, 2, 1, 5));
                    }
                    else if ( l_mrs_number == 5)
                    {
                        FAPI_TRY(l_address_16.insert(l_mrs1, 0, 16, 0));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5));
                    }
                    else if ( l_mrs_number == 6)
                    {
                        FAPI_TRY(l_address_16.insert(l_mrs0, 0, 16, 0));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS0_BA, 0, 1, 7));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS0_BA, 1, 1, 6));
                        FAPI_TRY(l_bank_3.insert((uint8_t) MRS0_BA, 2, 1, 5));
                    }

                    //mrs_number = 7;

                    if (( l_address_mirror_map[i_port_number][l_dimm_number] & (0x08 >> l_rank_number) ) && (l_is_sim == 0))
                    {
                        FAPI_DBG("enter swizzle");
                        FAPI_TRY(mss_address_mirror_swizzle(i_target, l_address_16, l_bank_3));

                    }


                    FAPI_DBG("enter ccs inst arr 0");
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

                    io_ccs_inst_cnt++;



                }

                // Address inversion for RCD
                if ( (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM)
                     || (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM) )
                {
                    FAPI_INF( "Sending out MRS with Address Inversion to B-side DRAMs\n");


                    // Propogate through the 4 MRS cmds
                    for ( l_mrs_number = 0; l_mrs_number < 7; l_mrs_number ++)
                    {
                        // Copying the current MRS into address buffer matching the MRS_array order
                        // Setting the bank address
                        if (l_mrs_number == 0)
                        {
                            FAPI_TRY(l_address_16.insert(l_mrs3, 0, 16, 0));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5));
                        }
                        else if ( l_mrs_number == 1)
                        {


                            FAPI_TRY(l_address_16.insert(l_mrs6, 0, 16, 0));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS6_BA, 0, 1, 7));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS6_BA, 1, 1, 6));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS6_BA, 2, 1, 5));
                        }
                        else if ( l_mrs_number == 2)
                        {
                            FAPI_TRY(l_address_16.insert(l_mrs5, 0, 16, 0));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS5_BA, 0, 1, 7));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS5_BA, 1, 1, 6));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS5_BA, 2, 1, 5));
                        }
                        else if ( l_mrs_number == 3)
                        {
                            FAPI_TRY(l_address_16.insert(l_mrs4, 0, 16, 0));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS4_BA, 0, 1, 7));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS4_BA, 1, 1, 6));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS4_BA, 2, 1, 5));
                        }
                        else if ( l_mrs_number == 4)
                        {
                            FAPI_TRY(l_address_16.insert(l_mrs2, 0, 16, 0));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS2_BA, 0, 1, 7));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS2_BA, 1, 1, 6));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS2_BA, 2, 1, 5));
                        }
                        else if ( l_mrs_number == 5)
                        {
                            FAPI_TRY(l_address_16.insert(l_mrs1, 0, 16, 0));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5));
                        }
                        else if ( l_mrs_number == 6)
                        {
                            FAPI_TRY(l_address_16.insert(l_mrs0, 0, 16, 0));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS0_BA, 0, 1, 7));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS0_BA, 1, 1, 6));
                            FAPI_TRY(l_bank_3.insert((uint8_t) MRS0_BA, 2, 1, 5));
                        }

                        // Indicate B-Side DRAMS BG1=1
                        FAPI_TRY(l_address_16.setBit(15));  // Set BG1 = 1
                        FAPI_TRY(l_address_16.flipBit(3, 7)); // Invert A3:A9
                        FAPI_TRY(l_address_16.flipBit(11));  // Invert A11
                        FAPI_TRY(l_address_16.flipBit(13));  // Invert A13
                        FAPI_TRY(l_address_16.flipBit(14));  // Invert A17
                        FAPI_TRY(l_bank_3.flipBit(0, 3));    // Invert BA0,BA1,BG0


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

                        io_ccs_inst_cnt++;

                    }
                }

            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///@brief Converts RTT_WR values to RTT_NOM
///@param[in] rtt_wr value
///@param[out] rtt_nom value
uint8_t convert_rtt_wr_to_rtt_nom(uint8_t i_rtt_wr, uint8_t& i_rtt_nom)
{
    switch(i_rtt_wr)
    {
        case fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_OHM120:
            i_rtt_nom = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM120;
            break;

        case 240:
            i_rtt_nom = fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM240;
            break;

        case 0xFF:
        case fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_DISABLE:
        default:
            FAPI_INF("RTT_WR is disabled! Skipping the swap of termination values to keep RTT_NOM with it's nominal values!!");
            return 1;
    }

    return 0;
}

///
/// @brief Setup CCS for B-side writes
/// @param[in] i_target mba target being calibrated
/// @param[in] i_port port being calibrated
/// @param[in] i_mrank mrank being calibrated
/// @param[in] i_srank srank being calibrated
/// @param[in] i_address_16 A-side DRAM address
/// @param[in] i_bank_3 A-side bank address
/// @param[in] i_activate_1 activate bit
/// @param[in] i_rasn_1 rasn bit
/// @param[in] i_casn_1 casn bit
/// @param[in] i_wen_1 wen bit
/// @param[in] i_cke_4 cke bits
/// @param[in] i_odt_4 odt bits
/// @param[in] i_ddr_cal_type_4 ddr cal type
/// @param[in] i_num_idles_16 number of idles
/// @param[in] i_num_repeat_16 number of repeats
/// @param[in] i_data_20 ccs data
/// @param[in] i_read_compare_1 read compare bit
/// @param[in] i_rank_cal_4 rank cal bits
/// @param[in] i_ddr_cal_enable_1 ddr cal enable bit
/// @param[in] i_ccs_end_1 ccs end bit
/// @param[in,out] CCS instruction Number
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_b_side_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                   const uint8_t i_port,
                                   const uint8_t i_mrank,
                                   const uint8_t i_srank,
                                   const fapi2::variable_buffer& i_address_16,
                                   const fapi2::variable_buffer& i_bank_3,
                                   const fapi2::variable_buffer& i_activate_1,
                                   const fapi2::variable_buffer& i_rasn_1,
                                   const fapi2::variable_buffer& i_casn_1,
                                   const fapi2::variable_buffer& i_wen_1,
                                   const fapi2::variable_buffer& i_cke_4,
                                   const fapi2::variable_buffer& i_odt_4,
                                   const fapi2::variable_buffer& i_ddr_cal_type_4,
                                   const fapi2::variable_buffer& i_num_idles_16,
                                   const fapi2::variable_buffer& i_num_repeat_16,
                                   const fapi2::variable_buffer& i_data_20,
                                   const fapi2::variable_buffer& i_read_compare_1,
                                   const fapi2::variable_buffer& i_rank_cal_4,
                                   const fapi2::variable_buffer& i_ddr_cal_enable_1,
                                   const fapi2::variable_buffer& i_ccs_end_1,
                                   uint32_t& io_ccs_inst_cnt)
{
    fapi2::variable_buffer l_address_16(16);
    fapi2::variable_buffer l_bank_3(3);
    fapi2::variable_buffer l_csn_8(8);
    fapi2::variable_buffer l_cke_4(4);
    l_cke_4 = i_cke_4;
    uint8_t l_dimm_type = 0;
    uint8_t l_is_sim = 0;
    uint8_t l_dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
    const uint8_t l_dimm = (i_mrank) / MAX_RANKS_PER_DIMM;
    const uint8_t l_dimm_rank = i_mrank - MAX_RANKS_PER_DIMM * l_dimm;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target, l_dram_stack));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target, l_address_mirror_map));

    if ( (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM)
         || (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM) )
    {
        //takes values from the A-side
        FAPI_TRY(l_address_16.clearBit(0, 16));
        FAPI_TRY(l_address_16.insert(i_address_16, 0, 16, 0));
        FAPI_TRY(l_bank_3.clearBit(0, 3));
        FAPI_TRY(l_bank_3.insert(i_bank_3, 0, 3, 0));

        //FLIPS all necessary bits
        // Indicate B-Side DRAMS BG1=1
        FAPI_TRY(l_address_16.setBit(15));  // Set BG1 = 1

        FAPI_TRY(l_address_16.flipBit(3, 7)); // Invert A3:A9
        FAPI_TRY(l_address_16.flipBit(11));  // Invert A11
        FAPI_TRY(l_address_16.flipBit(13));  // Invert A13
        FAPI_TRY(l_address_16.flipBit(14));  // Invert A17
        FAPI_TRY(l_bank_3.flipBit(0, 3));    // Invert BA0,BA1,BG0

        //loads the previous DRAM
        if (( l_address_mirror_map[i_port][l_dimm] & (0x08 >> l_dimm_rank) ) && (l_is_sim == 0))
        {
            FAPI_TRY(mss_address_mirror_swizzle(i_target, l_address_16, l_bank_3));

        }

        // Only corresponding CS to rank
        access_address l_addr = {0, 0, i_mrank, i_srank, 0, i_port};
        FAPI_TRY(cs_decode(i_target, l_addr, l_dram_stack[i_port][l_dimm], l_csn_8));

        FAPI_TRY(mss_disable_cid(i_target, l_csn_8, l_cke_4));

        // Send out to the CCS array
        FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                      io_ccs_inst_cnt,
                                      l_address_16,
                                      l_bank_3,
                                      i_activate_1,
                                      i_rasn_1,
                                      i_casn_1,
                                      i_wen_1,
                                      l_cke_4,
                                      l_csn_8,
                                      i_odt_4,
                                      i_ddr_cal_type_4,
                                      i_port));

        FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                      io_ccs_inst_cnt,
                                      i_num_idles_16,
                                      i_num_repeat_16,
                                      i_data_20,
                                      i_read_compare_1,
                                      i_rank_cal_4,
                                      i_ddr_cal_enable_1,
                                      i_ccs_end_1));

        io_ccs_inst_cnt++;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set non calibrating ranks to wr lvl mode on and qoff disabled during wr lvling
/// @param[in] i_target mba target being calibrated
/// @param[in] i_port port being calibrated
/// @param[in] i_rank rank pair group being calibrated
/// @param[in] i_state 1 turn on (configure) or 0 turn off (cleanup)
/// @param[in,out] io_ccs_inst_cnt CCS instruction Number
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_wr_lvl_mrs_ddr4(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                        const uint8_t i_port,
                                        const uint8_t i_rank,
                                        const uint8_t i_state,
                                        uint32_t& io_ccs_inst_cnt)
{
    fapi2::variable_buffer l_data_buffer_16(16);
    fapi2::variable_buffer l_bank_3(3);
    fapi2::variable_buffer l_activate_1(1);
    fapi2::variable_buffer l_rasn_1(1);
    fapi2::variable_buffer l_casn_1(1);
    fapi2::variable_buffer l_wen_1(1);
    fapi2::variable_buffer l_cke_4(4);
    fapi2::variable_buffer l_csn_8(8);
    fapi2::variable_buffer l_ddr_cal_type_4(4);
    fapi2::variable_buffer l_data_buffer_16_backup(16);
    fapi2::variable_buffer l_bank_3_backup(3);
    fapi2::variable_buffer l_odt_4(4);
    fapi2::variable_buffer l_num_idles_16(16);
    fapi2::variable_buffer l_num_repeat_16(16);
    fapi2::variable_buffer l_data_20(20);
    fapi2::variable_buffer l_read_compare_1(1);
    fapi2::variable_buffer l_rank_cal_4(4);
    fapi2::variable_buffer l_ddr_cal_enable_1(1);
    fapi2::variable_buffer l_ccs_end_1(1);
    uint8_t l_is_sim = 0;
    uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
    // dimm 0, dimm_rank 0-3 = ranks 0-3; dimm 1, dimm_rank 0-3 = ranks 4-7
    const uint8_t l_dimm = (i_rank) / MAX_RANKS_PER_DIMM;
    const uint8_t l_dimm_rank = i_rank - MAX_RANKS_PER_DIMM * l_dimm;
    access_address l_addr = {0, 0, 0, 0, 0};
    uint32_t l_delay = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target, l_address_mirror_map));

    // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
    l_delay = 400;
    FAPI_TRY(add_nop_to_ccs(i_target, l_addr, l_delay, io_ccs_inst_cnt));

    // Load nominal MRS values for the MR1, which contains RTT_NOM
    FAPI_INF("Sending MRS to rank %d on %s", i_rank, mss::c_str(i_target));
    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 12, 0, 16));
    FAPI_TRY(l_activate_1.setBit(0));
    FAPI_TRY(l_rasn_1.clearBit(0));
    FAPI_TRY(l_casn_1.clearBit(0));
    FAPI_TRY(l_wen_1.clearBit(0));
    FAPI_TRY(l_cke_4.setBit(0, 4));
    FAPI_TRY(l_csn_8.clearBit(0, 8));
    FAPI_TRY(l_odt_4.clearBit(0, 4));

    FAPI_TRY(mss_ddr4_load_nominal_mrs_pda(i_target, l_bank_3, l_data_buffer_16, MRS1_BA, i_port,  l_dimm,
                                           l_dimm_rank), "mss_ddr4_load_nominal_mrs_pda failed on %s", mss::c_str(i_target));

    // Insert on or off to wr lvl enable and qoff
    FAPI_TRY(l_data_buffer_16.insert(i_state, 7, 1, 0));
    FAPI_TRY(l_data_buffer_16.insert(i_state, 12, 1, 0));

    // Only corresponding CS to rank
    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_csn_8.clearBit(i_rank));

    FAPI_TRY(mss_disable_cid(i_target, l_csn_8, l_cke_4));

    FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7));
    FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6));
    FAPI_TRY(l_bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5));
    FAPI_TRY(l_data_buffer_16_backup.insert(l_data_buffer_16, 0, 16, 0));
    FAPI_TRY(l_bank_3_backup.insert(l_bank_3, 0 , 3, 0));

    // Do the mirror swizzle if needed
    if (( l_address_mirror_map[i_port][l_dimm] & (0x08 >> l_dimm_rank) ) && (l_is_sim == 0))
    {
        FAPI_INF("Doing address_mirroring_swizzle for %d %d %d %02x", i_port, l_dimm, l_dimm_rank,
                 l_address_mirror_map[i_port][l_dimm] );
        FAPI_TRY(mss_address_mirror_swizzle(i_target, l_data_buffer_16, l_bank_3), "mss_address_mirror_swizzle failed on %s",
                 mss::c_str(i_target));

    }
    else
    {
        FAPI_INF("No swizzle for address_mirroring_swizzle necessary for %d %d %d 0x%02x", i_port, l_dimm, l_dimm_rank,
                 l_address_mirror_map[i_port][l_dimm] );
    }

    FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                  io_ccs_inst_cnt,
                                  l_data_buffer_16,
                                  l_bank_3,
                                  l_activate_1,
                                  l_rasn_1,
                                  l_casn_1,
                                  l_wen_1,
                                  l_cke_4,
                                  l_csn_8,
                                  l_odt_4,
                                  l_ddr_cal_type_4,
                                  i_port), "ccs_inst_arry_0 failed on %s", mss::c_str(i_target));

    FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                  io_ccs_inst_cnt,
                                  l_num_idles_16,
                                  l_num_repeat_16,
                                  l_data_20,
                                  l_read_compare_1,
                                  l_rank_cal_4,
                                  l_ddr_cal_enable_1,
                                  l_ccs_end_1), "ccs_inst_arry_0 failed on %s", mss::c_str(i_target));
    io_ccs_inst_cnt++;

    // Do a B side MRS write
    FAPI_TRY( setup_b_side_ccs(i_target, i_port, i_rank, 0, l_data_buffer_16_backup,
                               l_bank_3_backup, l_activate_1, l_rasn_1, l_casn_1, l_wen_1,
                               l_cke_4, l_odt_4, l_ddr_cal_type_4, l_num_idles_16, l_num_repeat_16,
                               l_data_20, l_read_compare_1, l_rank_cal_4, l_ddr_cal_enable_1,
                               l_ccs_end_1, io_ccs_inst_cnt) );

    // Set a NOP as the last command
    l_addr.port = i_port;
    l_delay = 12;
    FAPI_TRY(add_nop_to_ccs(i_target, l_addr, l_delay, io_ccs_inst_cnt));

    // Setup end bit for CCS
    FAPI_TRY(mss_ccs_set_end_bit(i_target, io_ccs_inst_cnt - 1), "mss_ccs_set_end_bit failed on %s", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Swaps RTT_NOM and RTT_WR
/// @param[in]  target:  Reference to centaur.mba target,
/// @param[in]  MBA Position
/// @param[in]  Port Number
/// @param[in]  Rank Number
/// @param[in]  Rank Pair group
/// @param[in,out]  CCS instruction Number
/// @param[in,out]  Original RTT NOM
/// @return ReturnCode
fapi2::ReturnCode mss_ddr4_rtt_nom_rtt_wr_swap(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
    const uint8_t i_mbaPosition,
    const uint32_t i_port_number,
    const uint8_t i_rank,
    const uint32_t i_rank_pair_group,
    uint32_t& io_ccs_inst_cnt,
    uint8_t& io_dram_rtt_nom_original
)
{
    // fapi2::Target MBA level
    // This is a function written specifically for mss_draminit_training
    // Meant for placing RTT_WR into RTT_NOM within MR1 before wr_lvl
    // If the function argument dram_rtt_nom_original has a value of 0xFF it will put the original rtt_nom there
    // and write rtt_wr to the rtt_nom value
    // If the function argument dram_rtt_nom_original has any value besides 0xFF it will try to write that value to rtt_nom.

    FAPI_INF("Swapping RTT_WR values into RTT_NOM or swapping RTT_NOM back to its nominal value");

    fapi2::variable_buffer l_address_16(16);
    fapi2::variable_buffer l_address_16_backup(16);
    fapi2::variable_buffer l_bank_3(3);
    fapi2::variable_buffer l_bank_3_backup(3);
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

    fapi2::variable_buffer l_mrs1_16(16);
    fapi2::variable_buffer l_mrs2_16(16);

    fapi2::variable_buffer l_data_buffer_64(64);
    // dimm 0, dimm_rank 0-3 = ranks 0-3; dimm 1, dimm_rank 0-3 = ranks 4-7
    const uint8_t l_dimm = (i_rank) / MAX_RANKS_PER_DIMM;
    const uint8_t l_dimm_rank = i_rank - MAX_RANKS_PER_DIMM * l_dimm;

    uint8_t l_dimm_type = 0;
    uint8_t l_skip_swap = 0;;
    uint8_t l_is_sim = 0;
    uint8_t l_dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT]; //address_mirror_map[port][dimm]
    uint8_t l_dram_rtt_nom[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM];
    uint8_t l_dram_rtt_wr[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM];
    uint32_t l_addr16_print1, l_addr16_print2;
    l_addr16_print1 = l_addr16_print2 = 0;


    FAPI_TRY(l_activate_1.setBit(0));
    FAPI_TRY(l_rasn_1.clearBit(0));
    FAPI_TRY(l_casn_1.clearBit(0));
    FAPI_TRY(l_wen_1.clearBit(0));
    FAPI_TRY(l_cke_4.setBit(0, 4));
    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_odt_4.clearBit(0, 4));


    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target, l_dram_stack));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target, l_address_mirror_map));



    // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_address_16.clearBit(0, 16));
    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 400, 0, 16));
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

    io_ccs_inst_cnt++;

    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_csn_8.clearBit(i_rank));
    //sets up the MRS
    FAPI_TRY(l_rasn_1.clearBit(0, 1));
    FAPI_TRY(l_casn_1.clearBit(0, 1));
    FAPI_TRY(l_wen_1.clearBit(0, 1));

    // MRS CMD to CMD spacing = 12 cycles
    FAPI_TRY(l_num_idles_16.insertFromRight((uint32_t) 12, 0, 16));
    FAPI_INF( "Editing RTT_NOM during wr_lvl or for PDA for %s PORT: %d RP: %d", mss::c_str(i_target), i_port_number,
              i_rank_pair_group);

    //load nominal MRS values for the MR1, which contains RTT_NOM
    FAPI_TRY(mss_ddr4_load_nominal_mrs_pda(i_target, l_bank_3, l_address_16, MRS1_BA, i_port_number,  l_dimm,
                                           l_dimm_rank));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RTT_WR, i_target, l_dram_rtt_wr));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RTT_NOM, i_target, l_dram_rtt_nom));

    //do modifications based upon RTT_WR values if need be - a 0xFF indicates no swap done, so do the swap
    if(io_dram_rtt_nom_original == 0xFF)
    {
        io_dram_rtt_nom_original = 1;
        l_skip_swap = convert_rtt_wr_to_rtt_nom(l_dram_rtt_wr[i_port_number][l_dimm][l_dimm_rank],
                                                l_dram_rtt_nom[i_port_number][l_dimm][l_dimm_rank]);

        //skips the remainder of the swapping code if it is not needed - this is not an error, just returning out of the function
        if(l_skip_swap)
        {
            return fapi2::current_err;
        }

        FAPI_INF("Swapping RTT_WR value of 0x%02x into RTT_NOM=0x%02x", l_dram_rtt_wr[i_port_number][l_dimm][l_dimm_rank],
                 l_dram_rtt_nom[i_port_number][l_dimm][l_dimm_rank]);
        FAPI_TRY(l_address_16.extract(l_addr16_print1, 0, 16));

        FAPI_TRY(mss_ddr4_modify_mrs_pda(i_target, l_address_16, fapi2::ATTR_CEN_VPD_DRAM_RTT_NOM,
                                         l_dram_rtt_nom[i_port_number][l_dimm][l_dimm_rank]));

        FAPI_TRY(l_address_16.extract(l_addr16_print2, 0, 16));
        FAPI_DBG("Modified MR1 to have RTT_WR's value in RTT_NOM");
        FAPI_DBG("Printing before 0x%04x and after 0x%04x", l_addr16_print1, l_addr16_print2);
    }
    else
    {
        FAPI_INF("Not doing the swap, just setting back to nominal values 0x%02x", io_dram_rtt_nom_original);
        l_skip_swap = convert_rtt_wr_to_rtt_nom(l_dram_rtt_wr[i_port_number][l_dimm][l_dimm_rank],
                                                l_dram_rtt_nom[i_port_number][l_dimm][l_dimm_rank]);

        //skips the remainder of the swapping code if it is not needed - this is not an error, just returning out of the function
        if(l_skip_swap)
        {
            return fapi2::current_err;
        }
    }

    FAPI_TRY(l_address_16_backup.insert(l_address_16, 0, 16, 0));
    FAPI_TRY(l_bank_3_backup.insert(l_bank_3, 0 , 3, 0));

    FAPI_INF("Issuing MRS command");

    //loads the previous DRAM
    if (( l_address_mirror_map[i_port_number][l_dimm] & (0x08 >> l_dimm_rank) ) && (l_is_sim == 0))
    {
        FAPI_INF("Doing address_mirroring_swizzle for %d %d %d %02x", i_port_number, l_dimm, l_dimm_rank,
                 l_address_mirror_map[i_port_number][l_dimm] );
        FAPI_TRY(mss_address_mirror_swizzle(i_target, l_address_16, l_bank_3));

    }
    else
    {
        FAPI_INF("No swizzle for address_mirroring_swizzle necessary for %d %d %d 0x%02x", i_port_number, l_dimm, l_dimm_rank,
                 l_address_mirror_map[i_port_number][l_dimm] );
    }

    // Only corresponding CS to rank
    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_csn_8.clearBit(i_rank));

    FAPI_TRY(mss_disable_cid(i_target, l_csn_8, l_cke_4));

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

    io_ccs_inst_cnt++;

    //do a B side MRS write if needed
    FAPI_TRY( setup_b_side_ccs(i_target, i_port_number, i_rank, 0, l_address_16_backup,
                               l_bank_3_backup, l_activate_1, l_rasn_1, l_casn_1, l_wen_1,
                               l_cke_4, l_odt_4, l_ddr_cal_type_4, l_num_idles_16, l_num_repeat_16,
                               l_data_20, l_read_compare_1, l_rank_cal_4, l_ddr_cal_enable_1,
                               l_ccs_end_1, io_ccs_inst_cnt) );

    //sets a NOP as the last command
    FAPI_TRY(l_cke_4.setBit(0, 4));
    FAPI_TRY(l_csn_8.setBit(0, 8));
    FAPI_TRY(l_address_16.clearBit(0, 16));
    FAPI_TRY(l_rasn_1.setBit(0, 1));
    FAPI_TRY(l_casn_1.setBit(0, 1));
    FAPI_TRY(l_wen_1.setBit(0, 1));

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

    io_ccs_inst_cnt++;

    //Setup end bit for CCS
    FAPI_TRY(mss_ccs_set_end_bit (i_target, io_ccs_inst_cnt - 1));

    //Execute the CCS array
    FAPI_INF("Executing the CCS array\n");
    FAPI_TRY(mss_execute_ccs_inst_array (i_target, 100, 60));

fapi_try_exit:
    return fapi2::current_err;

}

/// @brief Modifies the passed in address_16 buffer based upon the given attribute and data
/// @param[in]  target:  Reference to l_centaur.mba target,
/// @param[in,out]  fapi2::variable_buffer& address_16:  MRS values - this is modified by the given attribute name and data
/// @param[in]  uint32_t i_attribute_name:  enumerated value containing the attribute name to be modified - attr_name tells the function which bits to modify
/// @param[in]  uint8_t i_attribute_data:   data telss the function what values to set to the modified bits
/// @return ReturnCode
fapi2::ReturnCode mss_ddr4_modify_mrs_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        fapi2::variable_buffer& i_address_16, const uint32_t i_attribute_name, const uint8_t i_attribute_data)
{
    uint8_t l_dram_bl = i_attribute_data;
    uint8_t l_read_bt = i_attribute_data; //Read Burst Type
    uint8_t l_dram_cl = i_attribute_data;
    uint8_t l_test_mode = i_attribute_data; //TEST MODE
    uint8_t l_dll_reset = i_attribute_data; //DLL Reset
    uint8_t l_dram_wr = i_attribute_data; //DRAM write recovery
    uint8_t l_dram_rtp = i_attribute_data; //DRAM RTP - read to precharge
    uint8_t l_dram_wr_rtp = i_attribute_data;
    uint8_t l_dll_precharge =
        i_attribute_data; //DLL Control For Precharge if (dll_precharge == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_PPD_SLOWEXIT)
    uint8_t l_dll_enable = i_attribute_data; //DLL Enable
    uint8_t l_out_drv_imp_cntl = i_attribute_data;
    uint8_t l_dram_rtt_nom = i_attribute_data;
    uint8_t l_dram_al = i_attribute_data;
    uint8_t l_wr_lvl = i_attribute_data; //write leveling enable
    uint8_t l_tdqs_enable = i_attribute_data; //TDQS Enable
    uint8_t l_q_off = i_attribute_name; //Qoff - Output buffer Enable
    uint8_t l_lpasr = i_attribute_data; // Low Power Auto Self-Refresh -- new not yet supported
    uint8_t l_cwl = i_attribute_data; // CAS Write Latency
    uint8_t l_dram_rtt_wr = i_attribute_data;
    uint8_t l_mpr_op = i_attribute_data; // MPR Op
    uint8_t l_mpr_page = i_attribute_data; // MPR Page Selection
    uint8_t l_geardown_mode = i_attribute_data; // Gear Down Mode
    uint8_t l_temp_readout = i_attribute_data; // Temperature sensor readout
    uint8_t l_fine_refresh = i_attribute_data; // fine refresh mode
    uint8_t l_wr_latency = i_attribute_data; // write latency for CRC and DM
    uint8_t l_write_crc = i_attribute_data; // CAS Write Latency
    uint8_t l_read_format = i_attribute_data; // MPR READ FORMAT
    uint8_t l_max_pd_mode = i_attribute_data; // Max Power down mode
    uint8_t l_temp_ref_range = i_attribute_data; // Temp ref range
    uint8_t l_temp_ref_mode = i_attribute_data; // Temp controlled ref mode
    uint8_t l_vref_mon = i_attribute_data; // Internal Vref Monitor
    uint8_t l_cs_cmd_latency = i_attribute_data; // CS to CMD/ADDR Latency
    uint8_t l_ref_abort = i_attribute_data; // Self Refresh Abort
    uint8_t l_rd_pre_train_mode = i_attribute_data; // Read Pre amble Training Mode
    uint8_t l_rd_preamble = i_attribute_data; // Read Pre amble
    uint8_t l_wr_preamble = i_attribute_data; // Write Pre amble
    uint8_t l_ca_parity_latency = i_attribute_data; //C/A Parity Latency Mode
    uint8_t l_crc_error_clear = i_attribute_data; //CRC Error Clear
    uint8_t l_ca_parity_error_status = i_attribute_data; //C/A Parity Error Status
    uint8_t l_odt_input_buffer = i_attribute_data; //ODT Input Buffer during power down
    uint8_t l_rtt_park = i_attribute_data; //RTT_Park value
    uint8_t l_ca_parity = i_attribute_data; //CA Parity Persistance Error
    uint8_t l_data_mask = i_attribute_data; //Data Mask
    uint8_t l_write_dbi = i_attribute_data; //Write DBI
    uint8_t l_read_dbi = i_attribute_data; //Read DBI
    uint8_t l_vrefdq_train_value = i_attribute_data; //vrefdq_train value
    uint8_t l_vrefdq_train_range = i_attribute_data; //vrefdq_train range
    uint8_t l_vrefdq_train_enable = i_attribute_data; //vrefdq_train enable
    uint8_t l_tccd_l = i_attribute_data; //tccd_l
    uint8_t l_dram_access = 0;

    switch (i_attribute_name)
    {
        case fapi2::ATTR_CEN_EFF_DRAM_BL:
            if (l_dram_bl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_BL_BL8)
            {
                l_dram_bl = 0x00;
            }
            else if (l_dram_bl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_BL_OTF)
            {
                l_dram_bl = 0x80;
            }
            else if (l_dram_bl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_BL_BC4)
            {
                l_dram_bl = 0x40;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_dram_bl, 0, 2, 0));
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_RBT:
            if (l_read_bt == fapi2::ENUM_ATTR_CEN_EFF_DRAM_RBT_SEQUENTIAL)
            {
                l_read_bt = 0x00;
            }
            else if (l_read_bt == fapi2::ENUM_ATTR_CEN_EFF_DRAM_RBT_INTERLEAVE)
            {
                l_read_bt = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_read_bt, 3, 1, 0));
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_CL:
            if ((l_dram_cl > 8) && (l_dram_cl < 17))
            {
                l_dram_cl = l_dram_cl - 9;
            }
            else if ((l_dram_cl > 17) && (l_dram_cl < 25))
            {
                l_dram_cl = (l_dram_cl >> 1) - 1;
            }

            l_dram_cl = mss_reverse_8bits(l_dram_cl);
            FAPI_TRY(i_address_16.insert((uint8_t) l_dram_cl, 2, 1, 0));
            FAPI_TRY(i_address_16.insert((uint8_t) l_dram_cl, 4, 3, 1));
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_TM:
            if (l_test_mode == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TM_NORMAL)
            {
                l_test_mode = 0x00;
            }
            else if (l_test_mode == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TM_TEST)
            {
                l_test_mode = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_test_mode, 7, 1));
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_DLL_RESET:
            l_dll_reset = 0x00;
            FAPI_ERR( "ERROR: ATTR_CEN_EFF_DRAM_DLL_RESET accessed during PDA functionality, overwritten");
            FAPI_TRY(i_address_16.insert((uint8_t) l_dll_reset, 8, 1));
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_WR:
            if ( (l_dram_wr == 10) )//&& (l_dram_rtp == 5) )
            {
                l_dram_wr_rtp = 0x00;
            }
            else if ( (l_dram_wr == 12) )//&& (l_dram_rtp == 6) )
            {
                l_dram_wr_rtp = 0x80;
            }
            else if ( (l_dram_wr == 13) )//&& (l_dram_rtp == 7) )
            {
                l_dram_wr_rtp = 0x40;
            }
            else if ( (l_dram_wr == 14) )//&& (l_dram_rtp == 8) )
            {
                l_dram_wr_rtp = 0xC0;
            }
            else if ( (l_dram_wr == 18) )//&& (l_dram_rtp == 9) )
            {
                l_dram_wr_rtp = 0x20;
            }
            else if ( (l_dram_wr == 20) )//&& (l_dram_rtp == 10) )
            {
                l_dram_wr_rtp = 0xA0;
            }
            else if ( (l_dram_wr == 24) )//&& (l_dram_rtp == 12) )
            {
                l_dram_wr_rtp = 0x60;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_dram_wr_rtp, 9, 3));
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_TRTP:
            if ( (l_dram_rtp == 5) )
            {
                l_dram_wr_rtp = 0x00;
            }
            else if ( (l_dram_rtp == 6) )
            {
                l_dram_wr_rtp = 0x80;
            }
            else if ( (l_dram_rtp == 7) )
            {
                l_dram_wr_rtp = 0x40;
            }
            else if ( (l_dram_rtp == 8) )
            {
                l_dram_wr_rtp = 0xC0;
            }
            else if ( (l_dram_rtp == 9) )
            {
                l_dram_wr_rtp = 0x20;
            }
            else if ( (l_dram_rtp == 10) )
            {
                l_dram_wr_rtp = 0xA0;
            }
            else if ( (l_dram_rtp == 12) )
            {
                l_dram_wr_rtp = 0x60;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_dram_wr_rtp, 9, 3));
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_DLL_PPD:
            if (l_dll_precharge == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_PPD_SLOWEXIT)
            {
                l_dll_precharge = 0x00;
            }
            else if (l_dll_precharge == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_PPD_FASTEXIT)
            {
                l_dll_precharge = 0xFF;
            }

            FAPI_INF("ERROR: ATTR_CEN_EFF_DRAM_DLL_PPD is an unused MRS value!!! Skipping...");
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_DLL_ENABLE:
            if (l_dll_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_ENABLE_DISABLE)
            {
                l_dll_enable = 0x00;
            }
            else if (l_dll_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_ENABLE_ENABLE)
            {
                l_dll_enable = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_dll_enable, 0, 1, 0));
            break;

        case fapi2::ATTR_CEN_VPD_DRAM_RON:
            if (l_out_drv_imp_cntl == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_OHM34)
            {
                l_out_drv_imp_cntl = 0x00;
            }
            else if (l_out_drv_imp_cntl == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_OHM48)
            {
                l_out_drv_imp_cntl = 0x80;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_out_drv_imp_cntl, 1, 2, 0));
            break;

        case fapi2::ATTR_CEN_VPD_DRAM_RTT_NOM:
            if (l_dram_rtt_nom == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_DISABLE)
            {
                l_dram_rtt_nom = 0x00;
            }
            else if (l_dram_rtt_nom == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM240) //not supported
            {
                l_dram_rtt_nom = 0x20;
            }
            else if (l_dram_rtt_nom == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM48) //not supported
            {
                l_dram_rtt_nom = 0xA0;
            }
            else if (l_dram_rtt_nom == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM40)
            {
                l_dram_rtt_nom = 0xC0;
            }
            else if (l_dram_rtt_nom == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM60)
            {
                l_dram_rtt_nom = 0x80;
            }
            else if (l_dram_rtt_nom == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM120)
            {
                l_dram_rtt_nom = 0x40;
            }
            else if (l_dram_rtt_nom == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM80) // not supported
            {
                l_dram_rtt_nom = 0x60;
            }
            else if (l_dram_rtt_nom == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM34) // not supported
            {
                l_dram_rtt_nom = 0xE0;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_dram_rtt_nom, 8, 3, 0));
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_AL:
            if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_DISABLE)
            {
                l_dram_al = 0x00;
            }
            else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_1)
            {
                l_dram_al = 0x80;
            }
            else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_2)
            {
                l_dram_al = 0x40;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_dram_al, 3, 2, 0));
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE:
            if (l_wr_lvl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE_DISABLE)
            {
                l_wr_lvl = 0x00;
            }
            else if (l_wr_lvl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE_ENABLE)
            {
                l_wr_lvl = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_wr_lvl, 7, 1, 0));
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_TDQS:
            if (l_tdqs_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_DISABLE)
            {
                l_tdqs_enable = 0x00;
            }
            else if (l_tdqs_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_ENABLE)
            {
                l_tdqs_enable = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_tdqs_enable, 11, 1, 0));
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER:
            if (l_q_off == fapi2::ENUM_ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER_DISABLE)
            {
                l_q_off = 0xFF;
            }
            else if (l_q_off == fapi2::ENUM_ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER_ENABLE)
            {
                l_q_off = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_q_off, 12, 1, 0));
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_LPASR:
            if (l_lpasr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_LPASR_MANUAL_NORMAL)
            {
                l_lpasr = 0x00;
            }
            else if (l_lpasr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_LPASR_MANUAL_REDUCED)
            {
                l_lpasr = 0x80;
            }
            else if (l_lpasr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_LPASR_MANUAL_EXTENDED)
            {
                l_lpasr = 0x40;
            }
            else if (l_lpasr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_LPASR_ASR)
            {
                l_lpasr = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_lpasr, 6, 2));
            break;

        case fapi2::ATTR_CEN_EFF_DRAM_CWL:
            if ((l_cwl > 8) && (l_cwl < 13))
            {
                l_cwl = l_cwl - 9;
            }
            else if ((l_cwl > 13) && (l_cwl < 19))
            {
                l_cwl = (l_cwl >> 1) - 3;
            }
            else
            {
                //no correcct value for CWL was found
                FAPI_INF("ERROR: Improper CWL value found. Setting CWL to 9 and continuing...");
                l_cwl = 0;
            }

            l_cwl = mss_reverse_8bits(l_cwl);
            FAPI_TRY(i_address_16.insert((uint8_t) l_cwl, 3, 3));
            break;

        case fapi2::ATTR_CEN_VPD_DRAM_RTT_WR:
            if (l_dram_rtt_wr == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_DISABLE)
            {
                l_dram_rtt_wr = 0x00;
            }
            else if (l_dram_rtt_wr == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_OHM120)
            {
                l_dram_rtt_wr = 0x80;
            }
            else if (l_dram_rtt_wr == 240)//fapi2::ENUM_ATTR_CEN_EFF_DRAM_RTT_WR_OHM240)
            {
                l_dram_rtt_wr = 0x40;
            }
            else if (l_dram_rtt_wr == 0xFF)//fapi2::ENUM_ATTR_CEN_EFF_DRAM_RTT_WR_HIGHZ)
            {
                l_dram_rtt_wr = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_dram_rtt_wr, 9, 2));
            break;

        case fapi2::ATTR_CEN_EFF_WRITE_CRC:
            if ( l_write_crc == fapi2::ENUM_ATTR_CEN_EFF_WRITE_CRC_ENABLE)
            {
                l_write_crc = 0xFF;
            }
            else if (l_write_crc == fapi2::ENUM_ATTR_CEN_EFF_WRITE_CRC_DISABLE)
            {
                l_write_crc = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_write_crc, 12, 1));
            break;

        case fapi2::ATTR_CEN_EFF_MPR_MODE:
            if (l_mpr_op == fapi2::ENUM_ATTR_CEN_EFF_MPR_MODE_ENABLE)
            {
                l_mpr_op = 0xFF;
            }
            else if (l_mpr_op == fapi2::ENUM_ATTR_CEN_EFF_MPR_MODE_DISABLE)
            {
                l_mpr_op = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_mpr_op, 2, 1));
            break;

        case fapi2::ATTR_CEN_EFF_MPR_PAGE:
            l_mpr_page = mss_reverse_8bits(l_mpr_page);
            FAPI_TRY(i_address_16.insert((uint8_t) l_mpr_page, 0, 2));
            break;

        case fapi2::ATTR_CEN_EFF_GEARDOWN_MODE:
            if ( l_geardown_mode == fapi2::ENUM_ATTR_CEN_EFF_GEARDOWN_MODE_HALF)
            {
                l_geardown_mode = 0x00;
            }
            else if ( l_geardown_mode == fapi2::ENUM_ATTR_CEN_EFF_GEARDOWN_MODE_QUARTER)
            {
                l_geardown_mode = 0xFF;
            }

            if (l_temp_readout == fapi2::ENUM_ATTR_CEN_EFF_TEMP_READOUT_ENABLE)
            {
                l_temp_readout = 0xFF;
            }
            else if (l_temp_readout == fapi2::ENUM_ATTR_CEN_EFF_TEMP_READOUT_DISABLE)
            {
                l_temp_readout = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_geardown_mode, 3, 1));
            break;

        case fapi2::ATTR_CEN_EFF_TEMP_READOUT:
            if (l_temp_readout == fapi2::ENUM_ATTR_CEN_EFF_TEMP_READOUT_ENABLE)
            {
                l_temp_readout = 0xFF;
            }
            else if (l_temp_readout == fapi2::ENUM_ATTR_CEN_EFF_TEMP_READOUT_DISABLE)
            {
                l_temp_readout = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_temp_readout, 5, 1));
            break;

        case fapi2::ATTR_CEN_EFF_FINE_REFRESH_MODE:
            if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_NORMAL)
            {
                l_fine_refresh = 0x00;
            }
            else if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_FIXED_2X)
            {
                l_fine_refresh = 0x80;
            }
            else if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_FIXED_4X)
            {
                l_fine_refresh = 0x40;
            }
            else if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_FLY_2X)
            {
                l_fine_refresh = 0xA0;
            }
            else if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_FLY_4X)
            {
                l_fine_refresh = 0x60;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_fine_refresh, 6, 3));
            break;

        case fapi2::ATTR_CEN_EFF_CRC_WR_LATENCY:
            if (l_wr_latency == fapi2::ENUM_ATTR_CEN_EFF_CRC_WR_LATENCY_4NCK)
            {
                l_wr_latency = 0x00;
            }
            else if (l_wr_latency == fapi2::ENUM_ATTR_CEN_EFF_CRC_WR_LATENCY_5NCK)
            {
                l_wr_latency = 0x80;
            }
            else if (l_wr_latency == fapi2::ENUM_ATTR_CEN_EFF_CRC_WR_LATENCY_6NCK)
            {
                l_wr_latency = 0xC0;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_wr_latency, 9, 2));
            break;

        case fapi2::ATTR_CEN_EFF_MPR_RD_FORMAT:
            if (l_read_format == fapi2::ENUM_ATTR_CEN_EFF_MPR_RD_FORMAT_SERIAL)
            {
                l_read_format = 0x00;
            }
            else if (l_read_format == fapi2::ENUM_ATTR_CEN_EFF_MPR_RD_FORMAT_PARALLEL)
            {
                l_read_format = 0x80;
            }
            else if (l_read_format == fapi2::ENUM_ATTR_CEN_EFF_MPR_RD_FORMAT_STAGGERED)
            {
                l_read_format = 0x40;
            }
            else if (l_read_format == fapi2::ENUM_ATTR_CEN_EFF_MPR_RD_FORMAT_RESERVED_TEMP)
            {
                l_read_format = 0xC0;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_read_format, 11, 2));
            break;

        case fapi2::ATTR_CEN_EFF_PER_DRAM_ACCESS:
            FAPI_INF("ERROR: ATTR_CEN_EFF_PER_DRAM_ACCESS selected.  Forcing PDA to be on for this function");
            l_dram_access = 0xFF;
            FAPI_TRY(i_address_16.insert((uint8_t) l_dram_access, 4, 1));
            break;

        case fapi2::ATTR_CEN_EFF_MAX_POWERDOWN_MODE:
            if ( l_max_pd_mode == fapi2::ENUM_ATTR_CEN_EFF_MAX_POWERDOWN_MODE_ENABLE)
            {
                l_max_pd_mode = 0xF0;
            }
            else if ( l_max_pd_mode == fapi2::ENUM_ATTR_CEN_EFF_MAX_POWERDOWN_MODE_DISABLE)
            {
                l_max_pd_mode = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_max_pd_mode, 1, 1));
            break;

        case fapi2::ATTR_CEN_EFF_TEMP_REF_RANGE:
            if (l_temp_ref_range == fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_RANGE_NORMAL)
            {
                l_temp_ref_range = 0x00;
            }
            else if ( l_temp_ref_range == fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_RANGE_EXTEND)
            {
                l_temp_ref_range = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_temp_ref_range, 2, 1));
            break;

        case fapi2::ATTR_CEN_EFF_TEMP_REF_MODE:
            if (l_temp_ref_mode == fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_MODE_ENABLE)
            {
                l_temp_ref_mode = 0x80;
            }
            else if (l_temp_ref_mode == fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_MODE_DISABLE)
            {
                l_temp_ref_mode = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_temp_ref_mode, 3, 1));
            break;

        case fapi2::ATTR_CEN_EFF_INT_VREF_MON:
            if ( l_vref_mon == fapi2::ENUM_ATTR_CEN_EFF_INT_VREF_MON_ENABLE)
            {
                l_vref_mon = 0xFF;
            }
            else if ( l_vref_mon == fapi2::ENUM_ATTR_CEN_EFF_INT_VREF_MON_DISABLE)
            {
                l_vref_mon = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_vref_mon, 4, 1));
            break;

        case fapi2::ATTR_CEN_EFF_CS_CMD_LATENCY:
            if ( l_cs_cmd_latency == 3)
            {
                l_cs_cmd_latency = 0x80;
            }
            else if (l_cs_cmd_latency == 4)
            {
                l_cs_cmd_latency = 0x40;
            }
            else if (l_cs_cmd_latency == 5)
            {
                l_cs_cmd_latency = 0xC0;
            }
            else if (l_cs_cmd_latency == 6)
            {
                l_cs_cmd_latency = 0x20;
            }
            else if (l_cs_cmd_latency == 8)
            {
                l_cs_cmd_latency = 0xA0;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_cs_cmd_latency, 6, 3));
            break;

        case fapi2::ATTR_CEN_EFF_SELF_REF_ABORT:
            if (l_ref_abort == fapi2::ENUM_ATTR_CEN_EFF_SELF_REF_ABORT_ENABLE)
            {
                l_ref_abort = 0xFF;
            }
            else if (l_ref_abort == fapi2::ENUM_ATTR_CEN_EFF_SELF_REF_ABORT_DISABLE)
            {
                l_ref_abort = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_ref_abort, 9, 1));
            break;

        case fapi2::ATTR_CEN_EFF_RD_PREAMBLE_TRAIN:
            if (l_rd_pre_train_mode == fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_TRAIN_ENABLE)
            {
                l_rd_pre_train_mode = 0xFF;
            }
            else if (l_rd_pre_train_mode == fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_TRAIN_DISABLE)
            {
                l_rd_pre_train_mode = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_rd_pre_train_mode, 10, 1));
            break;

        case fapi2::ATTR_CEN_EFF_RD_PREAMBLE:
            if (l_rd_preamble == fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_1NCLK)
            {
                l_rd_preamble = 0x00;
            }
            else if (l_rd_preamble == fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_2NCLK)
            {
                l_rd_preamble = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_rd_preamble, 11, 1));
            break;

        case fapi2::ATTR_CEN_EFF_WR_PREAMBLE:
            if (l_wr_preamble == fapi2::ENUM_ATTR_CEN_EFF_WR_PREAMBLE_1NCLK)
            {
                l_wr_preamble = 0x00;
            }
            else if (l_wr_preamble == fapi2::ENUM_ATTR_CEN_EFF_WR_PREAMBLE_2NCLK)
            {
                l_wr_preamble = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_wr_preamble, 12, 1));
            break;

        case fapi2::ATTR_CEN_EFF_CA_PARITY_LATENCY:
            if (l_ca_parity_latency == 4)
            {
                l_ca_parity_latency = 0x80;
            }
            else if (l_ca_parity_latency == 5)
            {
                l_ca_parity_latency = 0x40;
            }
            else if (l_ca_parity_latency == 6)
            {
                l_ca_parity_latency = 0xC0;
            }
            else if (l_ca_parity_latency == 8)
            {
                l_ca_parity_latency = 0x20;
            }
            else if (l_ca_parity_latency == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_LATENCY_DISABLE)
            {
                l_ca_parity_latency = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_ca_parity_latency, 0, 2));
            break;

        case fapi2::ATTR_CEN_EFF_CRC_ERROR_CLEAR:
            if (l_crc_error_clear == fapi2::ENUM_ATTR_CEN_EFF_CRC_ERROR_CLEAR_ERROR)
            {
                l_crc_error_clear = 0xFF;
            }
            else if (l_crc_error_clear == fapi2::ENUM_ATTR_CEN_EFF_CRC_ERROR_CLEAR_CLEAR)
            {
                l_crc_error_clear = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_crc_error_clear, 3, 1));
            break;

        case fapi2::ATTR_CEN_EFF_CA_PARITY_ERROR_STATUS:
            if (l_ca_parity_error_status == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_ERROR_STATUS_ERROR)
            {
                l_ca_parity_error_status = 0xFF;
            }
            else if (l_ca_parity_error_status == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_ERROR_STATUS_CLEAR)
            {
                l_ca_parity_error_status = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_ca_parity_error_status, 4, 1));
            break;

        case fapi2::ATTR_CEN_EFF_ODT_INPUT_BUFF:
            if (l_odt_input_buffer == fapi2::ENUM_ATTR_CEN_EFF_ODT_INPUT_BUFF_ACTIVATED)
            {
                l_odt_input_buffer = 0x00;
            }
            else if (l_odt_input_buffer == fapi2::ENUM_ATTR_CEN_EFF_ODT_INPUT_BUFF_DEACTIVATED)
            {
                l_odt_input_buffer = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_odt_input_buffer, 5, 1));
            break;

        case fapi2::ATTR_CEN_VPD_DRAM_RTT_PARK:
            if (l_rtt_park == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_DISABLE)
            {
                l_rtt_park = 0x00;
            }
            else if (l_rtt_park == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_60OHM)
            {
                l_rtt_park = 0x80;
            }
            else if (l_rtt_park == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_40OHM)
            {
                l_rtt_park = 0xC0;
            }
            else if (l_rtt_park == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_120OHM)
            {
                l_rtt_park = 0x40;
            }
            else if (l_rtt_park == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_240OHM)
            {
                l_rtt_park = 0x20;
            }
            else if (l_rtt_park == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_48OHM)
            {
                l_rtt_park = 0xA0;
            }
            else if (l_rtt_park == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_80OHM)
            {
                l_rtt_park = 0x60;
            }
            else if (l_rtt_park == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_34OHM)
            {
                l_rtt_park = 0xE0;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_rtt_park, 6, 3));
            break;

        case fapi2::ATTR_CEN_EFF_CA_PARITY:
            if (l_ca_parity == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_ENABLE)
            {
                l_ca_parity = 0xFF;
            }
            else if (l_ca_parity == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_DISABLE)
            {
                l_ca_parity = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_ca_parity, 9, 1));
            break;

        case fapi2::ATTR_CEN_EFF_DATA_MASK:
            if (l_data_mask == fapi2::ENUM_ATTR_CEN_EFF_DATA_MASK_DISABLE)
            {
                l_data_mask = 0x00;
            }
            else if (l_data_mask == fapi2::ENUM_ATTR_CEN_EFF_DATA_MASK_ENABLE)
            {
                l_data_mask = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_data_mask, 10, 1));
            break;

        case fapi2::ATTR_CEN_EFF_WRITE_DBI:
            if (l_write_dbi == fapi2::ENUM_ATTR_CEN_EFF_WRITE_DBI_DISABLE)
            {
                l_write_dbi = 0x00;
            }
            else if (l_write_dbi == fapi2::ENUM_ATTR_CEN_EFF_WRITE_DBI_ENABLE)
            {
                l_write_dbi = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_write_dbi, 11, 1));
            break;

        case fapi2::ATTR_CEN_EFF_READ_DBI:
            if (l_read_dbi == fapi2::ENUM_ATTR_CEN_EFF_READ_DBI_DISABLE)
            {
                l_read_dbi = 0x00;
            }
            else if (l_read_dbi == fapi2::ENUM_ATTR_CEN_EFF_READ_DBI_ENABLE)
            {
                l_read_dbi = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_read_dbi, 12, 1));
            break;

        case fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE:
            l_vrefdq_train_value = mss_reverse_8bits(l_vrefdq_train_value);
            FAPI_TRY(i_address_16.insert((uint8_t) l_vrefdq_train_value, 0, 6));
            break;

        case fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE:
            if (l_vrefdq_train_range == fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE_RANGE1)
            {
                l_vrefdq_train_range = 0x00;
            }
            else if (l_vrefdq_train_range == fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE_RANGE2)
            {
                l_vrefdq_train_range = 0xFF;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_vrefdq_train_range, 6, 1));
            break;

        case fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE:
            if (l_vrefdq_train_enable == fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE)
            {
                l_vrefdq_train_enable = 0xFF;
            }
            else if (l_vrefdq_train_enable == fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE)
            {
                l_vrefdq_train_enable = 0x00;
            }

            FAPI_TRY(i_address_16.insert((uint8_t) l_vrefdq_train_enable, 7, 1));
            break;

        case fapi2::ATTR_CEN_TCCD_L:
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

            FAPI_TRY(i_address_16.insert((uint8_t) l_tccd_l, 10, 3));
            break;

        //MRS attribute not found, error out
        default:
            FAPI_ASSERT(false, fapi2::CEN_MSS_PDA_NONMRS_ATTR_NAME().
                        set_NONMRS_ATTR_NAME(i_attribute_name).
                        set_MBA_TARGET(i_target),
                        "ERROR!! Found attribute name not associated with an MRS! Exiting...");
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief loads in a nominal MRS value into the address_16 and bank_3
/// @param[in]  i_target:  Reference to centaur.mba target,
/// @param[out]  fapi2::variable_buffer& i_bank_3:  bank bits to be issued during MRS
/// @param[out]  fapi2::variable_buffer& i_address_16:  16 address lanes to be issued during MRS - setup during function
/// @param[in]  uint8_t i_MRS:  which MRS to configure
/// @param[in]  uint8_t i_port_number: the port on which to configure the MRS - used for ID'ing which attributes to use
/// @param[in]  uint8_t i_dimm_number: the DIMM on which to configure the MRS - used for ID'ing which attributes to use
/// @param[in]  uint8_t i_rank_number: the rank on which to configure the MRS - used for ID'ing which attributes to use
/// @return ReturnCode
fapi2::ReturnCode mss_ddr4_load_nominal_mrs_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        fapi2::variable_buffer& i_bank_3, fapi2::variable_buffer& i_address_16, const uint8_t i_MRS,
        const uint8_t i_port_number,
        const uint8_t i_dimm_number, const uint8_t i_rank_number)
{
    uint8_t l_dll_enable = 0; //DLL Enable
    uint8_t l_out_drv_imp_cntl[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT];
    uint8_t l_dram_rtt_nom[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM];
    uint8_t l_dram_al = 0;
    uint8_t l_wr_lvl = 0; //write leveling enable
    uint8_t l_tdqs_enable = 0; //TDQS Enable
    uint8_t l_q_off = 0; //Qoff - Output buffer Enable
    uint8_t l_mpr_op = 0; // MPR Op
    uint8_t l_mpr_page = 0; // MPR Page Selection  - NEW
    uint8_t l_geardown_mode = 0; // Gear Down Mode  - NEW
    uint8_t l_temp_readout = 0; // Temperature sensor readout  - NEW
    uint8_t l_fine_refresh = 0; // fine refresh mode  - NEW
    uint8_t l_wr_latency = 0; // write latency for CRC and DM  - NEW
    uint8_t l_read_format = 0; // MPR READ FORMAT  - NEW
    uint8_t l_dram_bl = 0;
    uint8_t l_read_bt = 0; //Read Burst Type
    uint8_t l_dram_cl = 0;
    uint8_t l_test_mode = 0; //TEST MODE
    uint8_t l_dll_reset = 0; //DLL Reset
    uint8_t l_dram_wr = 0; //DRAM write recovery
    uint8_t l_dram_rtp = 0; //DRAM RTP - read to precharge
    uint8_t l_dll_precharge = 0; //DLL Control For Precharge
    uint8_t l_lpasr = 0; // Low Power Auto Self-Refresh -- new not yet supported
    uint8_t l_cwl = 0; // CAS Write Latency
    uint8_t l_dram_rtt_wr[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM];
    uint8_t l_write_crc = 0; // CAS Write Latency
    uint8_t l_max_pd_mode = 0; // Max Power down mode -  NEW
    uint8_t l_temp_ref_range = 0; // Temp ref range -  NEW
    uint8_t l_temp_ref_mode = 0; // Temp controlled ref mode -  NEW
    uint8_t l_vref_mon = 0; // Internal Vref Monitor -  NEW
    uint8_t l_cs_cmd_latency = 0; // CS to CMD/ADDR Latency -  NEW
    uint8_t l_ref_abort = 0; // Self Refresh Abort -  NEW
    uint8_t l_rd_pre_train_mode = 0; // Read Pre amble Training Mode -  NEW
    uint8_t l_rd_preamble = 0; // Read Pre amble -  NEW
    uint8_t l_wr_preamble = 0; // Write Pre amble -  NEW
    uint8_t l_ca_parity_latency = 0; //C/A Parity Latency Mode  -  NEW
    uint8_t l_crc_error_clear = 0; //CRC Error Clear  -  NEW
    uint8_t l_ca_parity_error_status = 0; //C/A Parity Error Status  -  NEW
    uint8_t l_odt_input_buffer = 0; //ODT Input Buffer during power down  -  NEW
    uint8_t l_rtt_park[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM]; //RTT_Park value  -  NEW
    uint8_t l_ca_parity = 0; //CA Parity Persistance Error  -  NEW
    uint8_t l_data_mask = 0; //Data Mask  -  NEW
    uint8_t l_write_dbi = 0; //Write DBI  -  NEW
    uint8_t l_read_dbi = 0; //Read DBI  -  NEW
    uint8_t l_vrefdq_train_value[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM]; //vrefdq_train value   -  NEW
    uint8_t l_vrefdq_train_range[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM]; //vrefdq_train range   -  NEW
    uint8_t l_vrefdq_train_enable[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM]; //vrefdq_train enable  -  NEW
    uint8_t l_tccd_l = 0; //tccd_l  -  NEW

    FAPI_TRY(i_address_16.clearBit(0, 16), "mss_mrs_load: Error setting up buffers");
    FAPI_TRY(i_bank_3.clearBit(0, 3), "mss_mrs_load: Error setting up buffers");

    //MRS0
    if(i_MRS == MRS0_BA)
    {

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_BL, i_target, l_dram_bl));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_RBT, i_target, l_read_bt));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CL, i_target, l_dram_cl));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TM, i_target, l_test_mode));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DLL_RESET, i_target, l_dll_reset));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WR, i_target, l_dram_wr));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRTP, i_target, l_dram_rtp));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DLL_PPD, i_target, l_dll_precharge));


        if (l_dram_bl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_BL_BL8)
        {
            l_dram_bl = 0x00;
        }
        else if (l_dram_bl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_BL_OTF)
        {
            l_dram_bl = 0x80;
        }
        else if (l_dram_bl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_BL_BC4)
        {
            l_dram_bl = 0x40;
        }

        uint8_t l_dram_wr_rtp = 0x00;

        if ( (l_dram_wr == 10) )//&& (l_dram_rtp == 5) )
        {
            l_dram_wr_rtp = 0x00;
        }
        else if ( (l_dram_wr == 12) )//&& (l_dram_rtp == 6) )
        {
            l_dram_wr_rtp = 0x80;
        }
        else if ( (l_dram_wr == 13) )//&& (l_dram_rtp == 7) )
        {
            l_dram_wr_rtp = 0x40;
        }
        else if ( (l_dram_wr == 14) )//&& (l_dram_rtp == 8) )
        {
            l_dram_wr_rtp = 0xC0;
        }
        else if ( (l_dram_wr == 18) )//&& (l_dram_rtp == 9) )
        {
            l_dram_wr_rtp = 0x20;
        }
        else if ( (l_dram_wr == 20) )//&& (l_dram_rtp == 10) )
        {
            l_dram_wr_rtp = 0xA0;
        }
        else if ( (l_dram_wr == 24) )//&& (l_dram_rtp == 12) )
        {
            l_dram_wr_rtp = 0x60;
        }

        if (l_read_bt == fapi2::ENUM_ATTR_CEN_EFF_DRAM_RBT_SEQUENTIAL)
        {
            l_read_bt = 0x00;
        }
        else if (l_read_bt == fapi2::ENUM_ATTR_CEN_EFF_DRAM_RBT_INTERLEAVE)
        {
            l_read_bt = 0xFF;
        }

        if ((l_dram_cl > 8) && (l_dram_cl < 17))
        {
            l_dram_cl = l_dram_cl - 9;
        }
        else if ((l_dram_cl > 17) && (l_dram_cl < 25))
        {
            l_dram_cl = (l_dram_cl >> 1) - 1;
        }

        l_dram_cl = mss_reverse_8bits(l_dram_cl);

        if (l_test_mode == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TM_NORMAL)
        {
            l_test_mode = 0x00;
        }
        else if (l_test_mode == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TM_TEST)
        {
            l_test_mode = 0xFF;
        }

        FAPI_INF("Overwriting DLL reset with values to not reset the DRAM.");
        l_dll_reset = 0x00;

        if (l_dll_precharge == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_PPD_SLOWEXIT)
        {
            l_dll_precharge = 0x00;
        }
        else if (l_dll_precharge == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_PPD_FASTEXIT)
        {
            l_dll_precharge = 0xFF;
        }

        //For DDR4:
        //Address l_14 = Address 17, Address l_15 = BG1
        FAPI_TRY(i_address_16.insert((uint8_t) l_dram_bl, 0, 2, 0));
        FAPI_TRY(i_address_16.insert((uint8_t) l_dram_cl, 2, 1, 0));
        FAPI_TRY(i_address_16.insert((uint8_t) l_read_bt, 3, 1, 0));
        FAPI_TRY(i_address_16.insert((uint8_t) l_dram_cl, 4, 3, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_test_mode, 7, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_dll_reset, 8, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_dram_wr_rtp, 9, 3));
        FAPI_TRY(i_address_16.insert((uint8_t) 0x00, 12, 4));

        FAPI_TRY(i_bank_3.insert((uint8_t) MRS0_BA, 0, 1, 7));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS0_BA, 1, 1, 6));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS0_BA, 2, 1, 5));
    }

    //MRS1
    else if(i_MRS == MRS1_BA)
    {

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DLL_ENABLE, i_target, l_dll_enable));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RON, i_target, l_out_drv_imp_cntl));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RTT_NOM, i_target, l_dram_rtt_nom));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_AL, i_target, l_dram_al));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE, i_target, l_wr_lvl));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TDQS, i_target, l_tdqs_enable));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER, i_target, l_q_off));


        if (l_dll_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_ENABLE_DISABLE)
        {
            l_dll_enable = 0x00;
        }
        else if (l_dll_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_DLL_ENABLE_ENABLE)
        {
            l_dll_enable = 0xFF;
        }

        if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_DISABLE)
        {
            l_dram_al = 0x00;
        }
        else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_1)
        {
            l_dram_al = 0x80;
        }
        else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_2)
        {
            l_dram_al = 0x40;
        }
        else if (l_dram_al == fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_CL_MINUS_3)
        {
            l_dram_al = 0xC0;
        }

        if (l_wr_lvl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE_DISABLE)
        {
            l_wr_lvl = 0x00;
        }
        else if (l_wr_lvl == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE_ENABLE)
        {
            l_wr_lvl = 0xFF;
        }

        if (l_tdqs_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_DISABLE)
        {
            l_tdqs_enable = 0x00;
        }
        else if (l_tdqs_enable == fapi2::ENUM_ATTR_CEN_EFF_DRAM_TDQS_ENABLE)
        {
            l_tdqs_enable = 0xFF;
        }

        if (l_q_off == fapi2::ENUM_ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER_DISABLE)
        {
            l_q_off = 0xFF;
        }
        else if (l_q_off == fapi2::ENUM_ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER_ENABLE)
        {
            l_q_off = 0x00;
        }

        if (l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_DISABLE)
        {
            l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] = 0x00;
        }
        else if (l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] ==
                 fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM240) //not supported
        {
            l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] = 0x20;
        }
        else if (l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] ==
                 fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM48) //not supported
        {
            l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] = 0xA0;
        }
        else if (l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM40)
        {
            l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] = 0xC0;
        }
        else if (l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM60)
        {
            l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] = 0x80;
        }
        else if (l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM120)
        {
            l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] = 0x40;
        }
        else if (l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] ==
                 fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM80) // not supported
        {
            l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] = 0x60;
        }
        else if (l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] ==
                 fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_NOM_OHM34) // not supported
        {
            l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number] = 0xE0;
        }

        if (l_out_drv_imp_cntl[i_port_number][i_dimm_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_OHM34)
        {
            l_out_drv_imp_cntl[i_port_number][i_dimm_number] = 0x00;
        }
        else if (l_out_drv_imp_cntl[i_port_number][i_dimm_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RON_OHM48)
        {
            l_out_drv_imp_cntl[i_port_number][i_dimm_number] = 0x80;
        }

        //For DDR4:
        //Address l_14 = Address 17, Address l_15 = BG1
        FAPI_TRY(i_address_16.insert((uint8_t) l_dll_enable, 0, 1, 0));
        FAPI_TRY(i_address_16.insert((uint8_t) l_out_drv_imp_cntl[i_port_number][i_dimm_number], 1, 2, 0));
        FAPI_TRY(i_address_16.insert((uint8_t) l_dram_al, 3, 2, 0));
        FAPI_TRY(i_address_16.insert((uint8_t) 0x00, 5, 2));
        FAPI_TRY(i_address_16.insert((uint8_t) l_wr_lvl, 7, 1, 0));
        FAPI_TRY(i_address_16.insert((uint8_t) l_dram_rtt_nom[i_port_number][i_dimm_number][i_rank_number], 8, 3, 0));
        FAPI_TRY(i_address_16.insert((uint8_t) l_tdqs_enable, 11, 1, 0));
        FAPI_TRY(i_address_16.insert((uint8_t) l_q_off, 12, 1, 0));
        FAPI_TRY(i_address_16.insert((uint8_t) 0x00, 13, 3));

        FAPI_TRY(i_bank_3.insert((uint8_t) MRS1_BA, 0, 1, 7));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS1_BA, 1, 1, 6));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS1_BA, 2, 1, 5));
    }
    //MRS2
    else if(i_MRS == MRS2_BA)
    {

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_LPASR, i_target, l_lpasr));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CWL, i_target, l_cwl));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RTT_WR, i_target, l_dram_rtt_wr));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_WRITE_CRC, i_target, l_write_crc));


        if (l_lpasr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_LPASR_MANUAL_NORMAL)
        {
            l_lpasr = 0x00;
        }
        else if (l_lpasr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_LPASR_MANUAL_REDUCED)
        {
            l_lpasr = 0x80;
        }
        else if (l_lpasr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_LPASR_MANUAL_EXTENDED)
        {
            l_lpasr = 0x40;
        }
        else if (l_lpasr == fapi2::ENUM_ATTR_CEN_EFF_DRAM_LPASR_ASR)
        {
            l_lpasr = 0xFF;
        }

        if ((l_cwl > 8) && (l_cwl < 13))
        {
            l_cwl = l_cwl - 9;
        }
        else if ((l_cwl > 13) && (l_cwl < 19))
        {
            l_cwl = (l_cwl >> 1) - 3;
        }
        else
        {
            //no correcct value for CWL was found
            FAPI_INF("ERROR: Improper CWL value found. Setting CWL to 9 and continuing...");
            l_cwl = 0;
        }

        l_cwl = mss_reverse_8bits(l_cwl);

        if ( l_write_crc == fapi2::ENUM_ATTR_CEN_EFF_WRITE_CRC_ENABLE)
        {
            l_write_crc = 0xFF;
        }
        else if (l_write_crc == fapi2::ENUM_ATTR_CEN_EFF_WRITE_CRC_DISABLE)
        {
            l_write_crc = 0x00;
        }

        if (l_dram_rtt_wr[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_DISABLE)
        {
            l_dram_rtt_wr[i_port_number][i_dimm_number][i_rank_number] = 0x00;
        }
        else if (l_dram_rtt_wr[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_WR_OHM120)
        {
            l_dram_rtt_wr[i_port_number][i_dimm_number][i_rank_number] = 0x80;
        }
        else if (l_dram_rtt_wr[i_port_number][i_dimm_number][i_rank_number] ==
                 240)//fapi2::ENUM_ATTR_CEN_EFF_DRAM_RTT_WR_OHM240)
        {
            l_dram_rtt_wr[i_port_number][i_dimm_number][i_rank_number] = 0x40;
        }
        else if (l_dram_rtt_wr[i_port_number][i_dimm_number][i_rank_number] ==
                 0xFF)//fapi2::ENUM_ATTR_CEN_EFF_DRAM_RTT_WR_HIGHZ)
        {
            l_dram_rtt_wr[i_port_number][i_dimm_number][i_rank_number] = 0xFF;
        }

        FAPI_TRY(i_address_16.insert((uint8_t) 0x00, 0, 3));
        FAPI_TRY(i_address_16.insert((uint8_t) l_cwl, 3, 3));
        FAPI_TRY(i_address_16.insert((uint8_t) l_lpasr, 6, 2));
        FAPI_TRY(i_address_16.insert((uint8_t) 0x00, 8, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_dram_rtt_wr[i_port_number][i_dimm_number][i_rank_number], 9, 2));
        FAPI_TRY(i_address_16.insert((uint8_t) 0x00, 11, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_write_crc, 12, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) 0x00, 13, 2));

        FAPI_TRY(i_bank_3.insert((uint8_t) MRS2_BA, 0, 1, 7));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS2_BA, 1, 1, 6));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS2_BA, 2, 1, 5));
    }
    //MRS3
    else if(i_MRS == MRS3_BA)
    {

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_MODE, i_target, l_mpr_op));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_PAGE, i_target, l_mpr_page));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_GEARDOWN_MODE, i_target, l_geardown_mode));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TEMP_READOUT, i_target, l_temp_readout));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_FINE_REFRESH_MODE, i_target, l_fine_refresh));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CRC_WR_LATENCY, i_target, l_wr_latency));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_RD_FORMAT, i_target, l_read_format));


        if (l_mpr_op == fapi2::ENUM_ATTR_CEN_EFF_MPR_MODE_ENABLE)
        {
            l_mpr_op = 0xFF;
        }
        else if (l_mpr_op == fapi2::ENUM_ATTR_CEN_EFF_MPR_MODE_DISABLE)
        {
            l_mpr_op = 0x00;
        }

        l_mpr_page = mss_reverse_8bits(l_mpr_page);

        if ( l_geardown_mode == fapi2::ENUM_ATTR_CEN_EFF_GEARDOWN_MODE_HALF)
        {
            l_geardown_mode = 0x00;
        }
        else if ( l_geardown_mode == fapi2::ENUM_ATTR_CEN_EFF_GEARDOWN_MODE_QUARTER)
        {
            l_geardown_mode = 0xFF;
        }

        if (l_temp_readout == fapi2::ENUM_ATTR_CEN_EFF_TEMP_READOUT_ENABLE)
        {
            l_temp_readout = 0xFF;
        }
        else if (l_temp_readout == fapi2::ENUM_ATTR_CEN_EFF_TEMP_READOUT_DISABLE)
        {
            l_temp_readout = 0x00;
        }

        if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_NORMAL)
        {
            l_fine_refresh = 0x00;
        }
        else if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_FIXED_2X)
        {
            l_fine_refresh = 0x80;
        }
        else if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_FIXED_4X)
        {
            l_fine_refresh = 0x40;
        }
        else if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_FLY_2X)
        {
            l_fine_refresh = 0xA0;
        }
        else if (l_fine_refresh == fapi2::ENUM_ATTR_CEN_EFF_FINE_REFRESH_MODE_FLY_4X)
        {
            l_fine_refresh = 0x60;
        }

        if (l_wr_latency == fapi2::ENUM_ATTR_CEN_EFF_CRC_WR_LATENCY_4NCK)
        {
            l_wr_latency = 0x00;
        }
        else if (l_wr_latency == fapi2::ENUM_ATTR_CEN_EFF_CRC_WR_LATENCY_5NCK)
        {
            l_wr_latency = 0x80;
        }
        else if (l_wr_latency == fapi2::ENUM_ATTR_CEN_EFF_CRC_WR_LATENCY_6NCK)
        {
            l_wr_latency = 0xC0;
        }

        if (l_read_format == fapi2::ENUM_ATTR_CEN_EFF_MPR_RD_FORMAT_SERIAL)
        {
            l_read_format = 0x00;
        }
        else if (l_read_format == fapi2::ENUM_ATTR_CEN_EFF_MPR_RD_FORMAT_PARALLEL)
        {
            l_read_format = 0x80;
        }
        else if (l_read_format == fapi2::ENUM_ATTR_CEN_EFF_MPR_RD_FORMAT_STAGGERED)
        {
            l_read_format = 0x40;
        }
        else if (l_read_format == fapi2::ENUM_ATTR_CEN_EFF_MPR_RD_FORMAT_RESERVED_TEMP)
        {
            l_read_format = 0xC0;
        }

        FAPI_TRY(i_address_16.insert((uint8_t) l_mpr_page, 0, 2));
        FAPI_TRY(i_address_16.insert((uint8_t) l_mpr_op, 2, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_geardown_mode, 3, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) 0xFF, 4, 1)); //has PDA mode enabled!!!! just for this code!
        FAPI_TRY(i_address_16.insert((uint8_t) l_temp_readout, 5, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_fine_refresh, 6, 3));
        FAPI_TRY(i_address_16.insert((uint8_t) l_wr_latency, 9, 2));
        FAPI_TRY(i_address_16.insert((uint8_t) l_read_format, 11, 2));
        FAPI_TRY(i_address_16.insert((uint8_t) 0x00, 13, 2));

        FAPI_TRY(i_bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5));
    }
    //MRS4
    else if(i_MRS == MRS4_BA)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MAX_POWERDOWN_MODE, i_target, l_max_pd_mode));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TEMP_REF_RANGE, i_target, l_temp_ref_range));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TEMP_REF_MODE, i_target, l_temp_ref_mode));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_INT_VREF_MON, i_target, l_vref_mon));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CS_CMD_LATENCY, i_target, l_cs_cmd_latency));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SELF_REF_ABORT, i_target, l_ref_abort));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_RD_PREAMBLE_TRAIN, i_target, l_rd_pre_train_mode));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_RD_PREAMBLE, i_target, l_rd_preamble));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_WR_PREAMBLE, i_target, l_wr_preamble));


        if ( l_max_pd_mode == fapi2::ENUM_ATTR_CEN_EFF_MAX_POWERDOWN_MODE_ENABLE)
        {
            l_max_pd_mode = 0xF0;
        }
        else if ( l_max_pd_mode == fapi2::ENUM_ATTR_CEN_EFF_MAX_POWERDOWN_MODE_DISABLE)
        {
            l_max_pd_mode = 0x00;
        }

        if (l_temp_ref_range == fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_RANGE_NORMAL)
        {
            l_temp_ref_range = 0x00;
        }
        else if ( l_temp_ref_range == fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_RANGE_EXTEND)
        {
            l_temp_ref_range = 0xFF;
        }

        if (l_temp_ref_mode == fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_MODE_ENABLE)
        {
            l_temp_ref_mode = 0x80;
        }
        else if (l_temp_ref_mode == fapi2::ENUM_ATTR_CEN_EFF_TEMP_REF_MODE_DISABLE)
        {
            l_temp_ref_mode = 0x00;
        }

        if ( l_vref_mon == fapi2::ENUM_ATTR_CEN_EFF_INT_VREF_MON_ENABLE)
        {
            l_vref_mon = 0xFF;
        }
        else if ( l_vref_mon == fapi2::ENUM_ATTR_CEN_EFF_INT_VREF_MON_DISABLE)
        {
            l_vref_mon = 0x00;
        }


        if ( l_cs_cmd_latency == 3)
        {
            l_cs_cmd_latency = 0x80;
        }
        else if (l_cs_cmd_latency == 4)
        {
            l_cs_cmd_latency = 0x40;
        }
        else if (l_cs_cmd_latency == 5)
        {
            l_cs_cmd_latency = 0xC0;
        }
        else if (l_cs_cmd_latency == 6)
        {
            l_cs_cmd_latency = 0x20;
        }
        else if (l_cs_cmd_latency == 8)
        {
            l_cs_cmd_latency = 0xA0;
        }

        if (l_ref_abort == fapi2::ENUM_ATTR_CEN_EFF_SELF_REF_ABORT_ENABLE)
        {
            l_ref_abort = 0xFF;
        }
        else if (l_ref_abort == fapi2::ENUM_ATTR_CEN_EFF_SELF_REF_ABORT_DISABLE)
        {
            l_ref_abort = 0x00;
        }

        if (l_rd_pre_train_mode == fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_TRAIN_ENABLE)
        {
            l_rd_pre_train_mode = 0xFF;
        }
        else if (l_rd_pre_train_mode == fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_TRAIN_DISABLE)
        {
            l_rd_pre_train_mode = 0x00;
        }

        if (l_rd_preamble == fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_1NCLK)
        {
            l_rd_preamble = 0x00;
        }
        else if (l_rd_preamble == fapi2::ENUM_ATTR_CEN_EFF_RD_PREAMBLE_2NCLK)
        {
            l_rd_preamble = 0xFF;
        }

        if (l_wr_preamble == fapi2::ENUM_ATTR_CEN_EFF_WR_PREAMBLE_1NCLK)
        {
            l_wr_preamble = 0x00;
        }
        else if (l_wr_preamble == fapi2::ENUM_ATTR_CEN_EFF_WR_PREAMBLE_2NCLK)
        {
            l_wr_preamble = 0xFF;
        }

        FAPI_TRY(i_address_16.insert((uint8_t) 0x00, 0, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_max_pd_mode, 1, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_temp_ref_range, 2, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_temp_ref_mode, 3, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_vref_mon, 4, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) 0x00, 5, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_cs_cmd_latency, 6, 3));
        FAPI_TRY(i_address_16.insert((uint8_t) l_ref_abort, 9, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_rd_pre_train_mode, 10, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_rd_preamble, 11, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_wr_preamble, 12, 1));

        FAPI_TRY(i_bank_3.insert((uint8_t) MRS4_BA, 0, 1, 7));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS4_BA, 1, 1, 6));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS4_BA, 2, 1, 5));
    }
    //MRS5
    else if(i_MRS == MRS5_BA)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CA_PARITY_LATENCY , i_target, l_ca_parity_latency));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CRC_ERROR_CLEAR , i_target, l_crc_error_clear));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CA_PARITY_ERROR_STATUS , i_target, l_ca_parity_error_status));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_ODT_INPUT_BUFF , i_target, l_odt_input_buffer));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_RTT_PARK , i_target, l_rtt_park));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CA_PARITY , i_target, l_ca_parity));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DATA_MASK , i_target, l_data_mask));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_WRITE_DBI , i_target, l_write_dbi));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_READ_DBI , i_target, l_read_dbi));



        if (l_ca_parity_latency == 4)
        {
            l_ca_parity_latency = 0x80;
        }
        else if (l_ca_parity_latency == 5)
        {
            l_ca_parity_latency = 0x40;
        }
        else if (l_ca_parity_latency == 6)
        {
            l_ca_parity_latency = 0xC0;
        }
        else if (l_ca_parity_latency == 8)
        {
            l_ca_parity_latency = 0x20;
        }
        else if (l_ca_parity_latency == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_LATENCY_DISABLE)
        {
            l_ca_parity_latency = 0x00;
        }

        if (l_crc_error_clear == fapi2::ENUM_ATTR_CEN_EFF_CRC_ERROR_CLEAR_ERROR)
        {
            l_crc_error_clear = 0xFF;
        }
        else if (l_crc_error_clear == fapi2::ENUM_ATTR_CEN_EFF_CRC_ERROR_CLEAR_CLEAR)
        {
            l_crc_error_clear = 0x00;
        }

        if (l_ca_parity_error_status == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_ERROR_STATUS_ERROR)
        {
            l_ca_parity_error_status = 0xFF;
        }
        else if (l_ca_parity_error_status == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_ERROR_STATUS_CLEAR)
        {
            l_ca_parity_error_status = 0x00;
        }

        if (l_odt_input_buffer == fapi2::ENUM_ATTR_CEN_EFF_ODT_INPUT_BUFF_ACTIVATED)
        {
            l_odt_input_buffer = 0x00;
        }
        else if (l_odt_input_buffer == fapi2::ENUM_ATTR_CEN_EFF_ODT_INPUT_BUFF_DEACTIVATED)
        {
            l_odt_input_buffer = 0xFF;
        }


        if (l_ca_parity == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_ENABLE)
        {
            l_ca_parity = 0xFF;
        }
        else if (l_ca_parity == fapi2::ENUM_ATTR_CEN_EFF_CA_PARITY_DISABLE)
        {
            l_ca_parity = 0x00;
        }

        if (l_data_mask == fapi2::ENUM_ATTR_CEN_EFF_DATA_MASK_DISABLE)
        {
            l_data_mask = 0x00;
        }
        else if (l_data_mask == fapi2::ENUM_ATTR_CEN_EFF_DATA_MASK_ENABLE)
        {
            l_data_mask = 0xFF;
        }

        if (l_write_dbi == fapi2::ENUM_ATTR_CEN_EFF_WRITE_DBI_DISABLE)
        {
            l_write_dbi = 0x00;
        }
        else if (l_write_dbi == fapi2::ENUM_ATTR_CEN_EFF_WRITE_DBI_ENABLE)
        {
            l_write_dbi = 0xFF;
        }

        if (l_read_dbi == fapi2::ENUM_ATTR_CEN_EFF_READ_DBI_DISABLE)
        {
            l_read_dbi = 0x00;
        }
        else if (l_read_dbi == fapi2::ENUM_ATTR_CEN_EFF_READ_DBI_ENABLE)
        {
            l_read_dbi = 0xFF;
        }

        if (l_rtt_park[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_DISABLE)
        {
            l_rtt_park[i_port_number][i_dimm_number][i_rank_number] = 0x00;
        }
        else if (l_rtt_park[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_60OHM)
        {
            l_rtt_park[i_port_number][i_dimm_number][i_rank_number] = 0x80;
        }
        else if (l_rtt_park[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_40OHM)
        {
            l_rtt_park[i_port_number][i_dimm_number][i_rank_number] = 0xC0;
        }
        else if (l_rtt_park[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_120OHM)
        {
            l_rtt_park[i_port_number][i_dimm_number][i_rank_number] = 0x40;
        }
        else if (l_rtt_park[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_240OHM)
        {
            l_rtt_park[i_port_number][i_dimm_number][i_rank_number] = 0x20;
        }
        else if (l_rtt_park[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_48OHM)
        {
            l_rtt_park[i_port_number][i_dimm_number][i_rank_number] = 0xA0;
        }
        else if (l_rtt_park[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_80OHM)
        {
            l_rtt_park[i_port_number][i_dimm_number][i_rank_number] = 0x60;
        }
        else if (l_rtt_park[i_port_number][i_dimm_number][i_rank_number] == fapi2::ENUM_ATTR_CEN_VPD_DRAM_RTT_PARK_34OHM)
        {
            l_rtt_park[i_port_number][i_dimm_number][i_rank_number] = 0xE0;
        }

        FAPI_TRY(i_address_16.insert((uint8_t) l_ca_parity_latency, 0, 2));
        FAPI_TRY(i_address_16.insert((uint8_t) l_crc_error_clear, 3, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_ca_parity_error_status, 4, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_odt_input_buffer, 5, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_rtt_park[i_port_number][i_dimm_number][i_rank_number], 6, 3));
        FAPI_TRY(i_address_16.insert((uint8_t) l_ca_parity, 9, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_data_mask, 10, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_write_dbi, 11, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_read_dbi, 12, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) 0x00, 13, 2));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS5_BA, 0, 1, 7));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS5_BA, 1, 1, 6));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS5_BA, 2, 1, 5));
    }
    //MRS6
    else if(i_MRS == MRS6_BA)
    {

        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, i_target, l_vrefdq_train_value));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE, i_target, l_vrefdq_train_range));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, i_target, l_vrefdq_train_enable));
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

        l_vrefdq_train_value[i_port_number][i_dimm_number][i_rank_number] = mss_reverse_8bits(
                    l_vrefdq_train_value[i_port_number][i_dimm_number][i_rank_number]);

        if (l_vrefdq_train_range[i_port_number][i_dimm_number][i_rank_number] ==
            fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE_RANGE1)
        {
            l_vrefdq_train_range[i_port_number][i_dimm_number][i_rank_number] = 0x00;
        }
        else if (l_vrefdq_train_range[i_port_number][i_dimm_number][i_rank_number] ==
                 fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE_RANGE2)
        {
            l_vrefdq_train_range[i_port_number][i_dimm_number][i_rank_number] = 0xFF;
        }

        if (l_vrefdq_train_enable[i_port_number][i_dimm_number][i_rank_number] ==
            fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE)
        {
            l_vrefdq_train_enable[i_port_number][i_dimm_number][i_rank_number] = 0xFF;
        }
        else if (l_vrefdq_train_enable[i_port_number][i_dimm_number][i_rank_number] ==
                 fapi2::ENUM_ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE)
        {
            l_vrefdq_train_enable[i_port_number][i_dimm_number][i_rank_number] = 0x00;
        }

        FAPI_TRY(i_address_16.insert((uint8_t) l_vrefdq_train_value[i_port_number][i_dimm_number][i_rank_number], 0, 6));
        FAPI_TRY(i_address_16.insert((uint8_t) l_vrefdq_train_range[i_port_number][i_dimm_number][i_rank_number], 6, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) l_vrefdq_train_enable[i_port_number][i_dimm_number][i_rank_number], 7, 1));
        FAPI_TRY(i_address_16.insert((uint8_t) 0x00, 8, 2));
        FAPI_TRY(i_address_16.insert((uint8_t) l_tccd_l, 10, 3));
        FAPI_TRY(i_address_16.insert((uint8_t) 0x00, 13, 2));

        FAPI_TRY(i_bank_3.insert((uint8_t) MRS6_BA, 0, 1, 7));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS6_BA, 1, 1, 6));
        FAPI_TRY(i_bank_3.insert((uint8_t) MRS6_BA, 2, 1, 5));
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_PDA_MRS_NOT_FOUND().
                    set_MRS_VALUE(i_MRS).
                    set_MBA_TARGET(i_target),
                    "ERROR!! Found attribute name not associated with an MRS! Exiting...");
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Add an MRS command to the CCS program
/// @param[in] i_target_mba mba target
/// @param[in] i_addr address struct for MRS
/// @param[in] i_delay delay associated with this instruction
/// @param[in,out] io_instruction_number position in CCS program in which to insert MRS command (will be incremented)
/// @return FAPI2_RC_SUCCESS iff successful
/// @note MR should be selected using i_addr.bank with constants from dimmConsts.H
fapi2::ReturnCode add_mrs_to_ccs_ddr4(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                      const access_address i_addr,
                                      const uint32_t i_delay,
                                      uint32_t& io_instruction_number)
{
    uint8_t l_is_sim = 0;
    uint8_t l_address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
    uint8_t l_stack_type_u8array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
    const uint8_t l_dimm = i_addr.mrank / MAX_RANKS_PER_DIMM;
    const uint8_t l_dimm_rank = i_addr.mrank % MAX_RANKS_PER_DIMM;

    // CCS Array 0 buffers
    fapi2::variable_buffer addr_16(16);
    fapi2::variable_buffer addr_16_pre_swizzle(16);
    fapi2::variable_buffer bank_3(3);
    fapi2::variable_buffer ddr4_activate_1(1);
    fapi2::variable_buffer rasn_1(1);
    fapi2::variable_buffer casn_1(1);
    fapi2::variable_buffer wen_1(1);
    fapi2::variable_buffer cke_4(4);
    fapi2::variable_buffer csn_8(8);
    fapi2::variable_buffer odt_4(4);
    fapi2::variable_buffer cal_type_4(4);

    // CCS Array 1 buffers
    fapi2::variable_buffer idles_16(16);
    fapi2::variable_buffer repeat_16(16);
    fapi2::variable_buffer pattern_20(20);
    fapi2::variable_buffer read_compare_1(1);
    fapi2::variable_buffer rank_cal_4(4);
    fapi2::variable_buffer cal_enable_1(1);
    fapi2::variable_buffer ccs_end_1(1);
    fapi2::buffer<uint8_t> l_data_8;
    fapi2::buffer<uint16_t> l_data_16;
    uint32_t l_port = i_addr.port;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_sim));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target_mba, l_address_mirror_map));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target_mba,  l_stack_type_u8array));

    // CCS Array 0 Setup

    // Buffer conversions from inputs
    FAPI_TRY(addr_16.insertFromRight(i_addr.row_addr, 0, 16));
    FAPI_TRY(addr_16.extract(l_data_16));
    l_data_16.reverse();
    FAPI_TRY(addr_16.insert((uint16_t)l_data_16));
    FAPI_TRY(addr_16_pre_swizzle.insert((uint16_t)l_data_16));
    FAPI_TRY(bank_3.insertFromRight(i_addr.bank, 0, 3));
    FAPI_TRY(bank_3.extract(l_data_8, 0, 3));
    l_data_8.reverse();
    FAPI_TRY(bank_3.insertFromRight((uint8_t)l_data_8, 0 , 3));
    FAPI_INF("%s add_MRS_to_ccs ADDR : 0x%04X  MR : 0x%X", mss::c_str(i_target_mba), i_addr.row_addr, i_addr.bank);

    FAPI_TRY(cs_decode(i_target_mba, i_addr, l_stack_type_u8array[0][0], csn_8));
    cke_4.flush<1>();
    FAPI_TRY(mss_disable_cid(i_target_mba, csn_8, cke_4));

    // Command structure setup
    FAPI_TRY(rasn_1.clearBit(0));
    FAPI_TRY(casn_1.clearBit(0));
    FAPI_TRY(wen_1.clearBit(0));

    FAPI_TRY(read_compare_1.clearBit(0));

    // Final setup
    odt_4.flush<0>();
    cal_type_4.flush<0>();
    FAPI_TRY(ddr4_activate_1.setBit(0));

    if ((l_address_mirror_map[l_port][l_dimm] & (0x08 >> l_dimm_rank) ) && (l_is_sim == 0))
    {
        FAPI_TRY(mss_address_mirror_swizzle(i_target_mba, addr_16, bank_3));
    }

    FAPI_TRY(mss_ccs_inst_arry_0(i_target_mba,
                                 io_instruction_number,
                                 addr_16,
                                 bank_3,
                                 ddr4_activate_1,
                                 rasn_1,
                                 casn_1,
                                 wen_1,
                                 cke_4,
                                 csn_8,
                                 odt_4,
                                 cal_type_4,
                                 l_port));

    // CCS Array 1 Setup
    FAPI_TRY(idles_16.insertFromRight(i_delay, 0, 16));
    repeat_16.flush<0>();
    pattern_20.flush<0>();
    read_compare_1.flush<0>();
    rank_cal_4.flush<0>();
    cal_enable_1.flush<0>();
    ccs_end_1.flush<0>();

    FAPI_TRY(mss_ccs_inst_arry_1(i_target_mba,
                                 io_instruction_number,
                                 idles_16,
                                 repeat_16,
                                 pattern_20,
                                 read_compare_1,
                                 rank_cal_4,
                                 cal_enable_1,
                                 ccs_end_1));
    ++io_instruction_number;

    // Do a B side MRS write
    FAPI_TRY( setup_b_side_ccs(i_target_mba, l_port, i_addr.mrank, i_addr.srank, addr_16_pre_swizzle,
                               bank_3, ddr4_activate_1, rasn_1, casn_1, wen_1,
                               cke_4, odt_4, cal_type_4, idles_16, repeat_16,
                               pattern_20, read_compare_1, rank_cal_4, cal_enable_1,
                               ccs_end_1, io_instruction_number) );

fapi_try_exit:
    return fapi2::current_err;
}
