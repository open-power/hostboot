/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_access_delay_reg.C $ */
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
/// @file p9c_mss_access_delay_reg.C
/// @brief helper functions for accessing and modifying delay registers
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///


//----------------------------------------------------------------------
//  My Includes
//----------------------------------------------------------------------
#include <p9c_mss_access_delay_reg.H>
#include <generic/memory/lib/utils/c_str.H>
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi2.H>
#include <dimmConsts.H>
extern "C" {

    ///@function mss_access_delay_reg()
    ///@brief This function Read and Write delay values for RD_DQ, WR_DQ, RD_DQS, WR_DQS
    ///@param[in] Target MBA=i_target_mba
    ///@param[in] i_access_type_e = READ or WRITE
    ///@param[in] i_port_u8=0 or 1
    ///@param[in] i_rank_u8=valid ranks
    ///@param[in] i_input_type_e=RD_DQ or RD_DQS or WR_DQ or WR_DQS or RAW_modes
    ///@param[in] i_input_index_u8=follow ISDIMMnet/C4 for non raw modes and supports raw modes
    ///@param[in] i_verbose-extra print statements
    ///@param[in,out] delay value=io_value_u32 if i_access_type_e = READ else if i_access_type_e = WRITE no return value
    ///@return fapi2::ReturnCode
    fapi2::ReturnCode mss_access_delay_reg(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                           const access_type_t i_access_type_e,
                                           const uint8_t i_port_u8,
                                           const uint8_t i_rank_u8,
                                           const input_type_t i_input_type_e,
                                           const uint8_t i_input_index_u8,
                                           const bool i_verbose,
                                           uint32_t& io_value_u32)
    {
        uint8_t l_val = 0;
        uint8_t l_dram_width = 0;
        scom_location l_out;
        uint64_t l_scom_add = 0x0ull;
        uint32_t l_sbit = 0;
        uint32_t l_len = 0;
        fapi2::buffer<uint64_t> l_data_buffer_64;
        fapi2::variable_buffer out(16);
        uint32_t l_output = 0;
        uint32_t l_start = 0;
        uint8_t l_rank_pair = 9;
        uint8_t l_rankpair_table[MAX_RANKS_PER_PORT] = {};
        uint8_t l_dimmtype = 0;
        uint8_t l_block = 0;
        uint8_t l_lane = 0;
        uint8_t l_start_bit = 0;
        uint8_t l_len8 = 0;
        input_type l_type;
        uint8_t l_mbapos = 0;
        uint8_t l_adr = 0;
        const uint8_t l_addr_lane[MAX_PORTS_PER_CEN][MAX_ADDR] =
        {
            {1, 5, 3, 7, 10, 6, 4, 10, 13, 12, 9, 9, 0, 0, 6, 4, 1, 4, 8},
            {7, 10, 3, 6, 8, 12, 6, 1, 5, 8, 2, 0, 13, 4, 5, 9, 6, 11, 9},
            {8, 0, 7, 1, 12, 10, 1, 5, 9, 5, 13, 5, 4, 2, 4, 9, 10, 9, 0},
            {6, 2, 9, 9, 2, 3, 4, 10, 0, 5, 1, 5, 4, 1, 8, 11, 5, 12, 1},
        };
        const uint8_t l_addr_adr[MAX_PORTS_PER_CEN][MAX_ADDR] =
        {
            {2, 1, 1, 3, 1, 3, 1, 3, 3, 3, 2, 3, 2, 3, 1, 0, 3, 3, 3},
            {2, 1, 2, 2, 1, 3, 1, 1, 1, 3, 1, 3, 2, 3, 3, 0, 0, 1, 3},
            {2, 2, 3, 0, 3, 1, 2, 0, 1, 3, 2, 1, 0, 2, 3, 3, 3, 2, 1},
            {3, 0, 2, 3, 2, 0, 3, 3, 1, 2, 2, 1, 0, 1, 3, 3, 0, 3, 0},
        };
        const uint8_t l_cmd_lane[MAX_PORTS_PER_CEN][MAX_CMD] =
        {
            {2, 11, 5},
            {2, 10, 10},
            {3, 11, 3},
            {7, 10, 7},
        };
        const uint8_t l_cmd_adr[MAX_PORTS_PER_CEN][MAX_CMD] =
        {
            {3, 1, 3},
            {2, 3, 2},
            {1, 3, 0},
            {1, 1, 3},
        };
        const uint8_t l_cnt_lane[MAX_PORTS_PER_CEN][MAX_CNT] =
        {
            {0, 7, 3, 1, 7, 8, 8, 3, 8, 6, 7, 2, 2, 0, 9, 1, 3, 6, 9, 2},
            {5, 4, 0, 5, 11, 9, 10, 7, 1, 11, 0, 4, 12, 3, 6, 8, 1, 4, 7, 7},
            {0, 4, 7, 13, 11, 5, 12, 2, 3, 6, 11, 6, 7, 1, 10, 8, 8, 2, 4, 1},
            {0, 11, 9, 8, 4, 7, 0, 3, 8, 6, 13, 8, 7, 0, 6, 6, 1, 2, 9, 5},
        };
        const uint8_t l_cnt_adr[MAX_PORTS_PER_CEN][MAX_CNT] =
        {
            {1, 0, 3, 0, 2, 2, 1, 2, 0, 0, 1, 2, 0, 0, 1, 1, 0, 2, 0, 1},
            {2, 1, 2, 0, 2, 1, 0, 1, 3, 0, 1, 0, 2, 1, 3, 0, 2, 2, 3, 0},
            {0, 1, 1, 3, 1, 2, 2, 0, 2, 2, 0, 1, 2, 1, 0, 3, 1, 1, 2, 3},
            {2, 1, 0, 2, 1, 0, 3, 2, 0, 1, 3, 1, 2, 0, 0, 2, 3, 1, 1, 3},
        };
        const uint8_t l_clk_lane[MAX_PORTS_PER_CEN][MAX_CLK] =
        {
            {10, 11, 11, 10, 4, 5, 13, 12},
            {3, 2, 8, 9, 1, 0, 3, 2},
            {11, 10, 6, 7, 2, 3, 8, 9},
            {3, 2, 13, 12, 10, 11, 11, 10},
        };
        const uint8_t l_clk_adr[MAX_PORTS_PER_CEN][MAX_CLK] =
        {
            {0, 0, 2, 2, 2, 2, 2, 2},
            {3, 3, 2, 2, 0, 0, 0, 0},
            {2, 2, 0, 0, 3, 3, 0, 0},
            {3, 3, 2, 2, 0, 0, 2, 2},
        };

        FAPI_TRY(mss_getrankpair(i_target_mba, i_port_u8, i_rank_u8, &l_rank_pair, l_rankpair_table));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_dimmtype));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target_mba, l_dram_width));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_mba, l_mbapos));

        if(i_verbose)
        {
            FAPI_INF("dimm type=%d", l_dimmtype);
            FAPI_INF("rank pair=%d", l_rank_pair);
        }

        FAPI_ASSERT(i_port_u8 < MAX_PORTS_PER_MBA,
                    fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                    set_MBA_TARGET(i_target_mba).
                    set_ACCESS_TYPE_PARAM(i_access_type_e).
                    set_PORT_PARAM(i_port_u8).
                    set_RANK_PARAM(i_rank_u8).
                    set_TYPE_PARAM(i_input_type_e).
                    set_INDEX_PARAM(i_input_index_u8),
                    "Wrong port specified (%d)", i_port_u8);

        FAPI_ASSERT(l_mbapos < MAX_MBA_PER_CEN,
                    fapi2::CEN_MSS_ACCESS_DELAY_REG_BAD_MBA_POS().
                    set_MBA_POS(l_mbapos).
                    set_MBA_TARGET(i_target_mba),
                    "Bad position from ATTR_CHIP_UNIT_POS (%d)", l_mbapos);

        FAPI_ASSERT((l_dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4)
                    || (l_dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X8),
                    fapi2::CEN_MSS_ACCESS_DELAY_REG_BAD_DRAM_WIDTH().
                    set_DRAM_WIDTH(l_dram_width).
                    set_MBA_TARGET(i_target_mba),
                    "Bad dram width from ATTR_EFF_DRAM_WIDTH (%d)", l_dram_width);

        if(i_verbose)
        {
            FAPI_INF("dram width=%d", l_dram_width);
        }

        if(i_input_type_e == RD_DQ || i_input_type_e == WR_DQ)
        {
            if(l_dimmtype == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
            {
                FAPI_ASSERT(i_input_index_u8 < CDIMM_MAX_DQ_80,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "CDIMM_DQ: Wrong input index specified (%d, max %d)" ,
                            i_input_index_u8, CDIMM_MAX_DQ_80);
                l_type = CDIMM_DQ;
            }
            else
            {
                FAPI_ASSERT(i_input_index_u8 < ISDIMM_MAX_DQ_72,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "ISDIMM_DQ: Wrong input index specified (%d, max %d)",
                            i_input_index_u8, ISDIMM_MAX_DQ_72);
                l_type = ISDIMM_DQ;
            }

            FAPI_TRY(rosetta_map(i_target_mba, i_port_u8, l_type, i_input_index_u8, i_verbose, l_val));

            if(i_verbose)
            {
                FAPI_INF("C4 value is=%d", l_val);
            }

            FAPI_TRY(cross_coupled(i_target_mba, i_port_u8, l_rank_pair, i_input_type_e, l_val, i_verbose, l_out));

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_out.scom_addr);
                FAPI_INF("start bit=%d", l_out.start_bit);
                FAPI_INF("length=%d", l_out.bit_length);
            }

            l_scom_add = l_out.scom_addr;
            l_sbit = l_out.start_bit;
            l_len = l_out.bit_length;

        }

        else if(i_input_type_e == RAW_CDIMM_WR_DQ || i_input_type_e == RAW_CDIMM_RD_DQ)
        {
            FAPI_ASSERT(i_input_index_u8 <= CDIMM_MAX_DQ_80,
                        fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                        set_MBA_TARGET(i_target_mba).
                        set_ACCESS_TYPE_PARAM(i_access_type_e).
                        set_PORT_PARAM(i_port_u8).
                        set_RANK_PARAM(i_rank_u8).
                        set_TYPE_PARAM(i_input_type_e).
                        set_INDEX_PARAM(i_input_index_u8),
                        "CDIMM_DQ: Wrong input index specified (%d, max %d)" ,
                        i_input_index_u8, CDIMM_MAX_DQ_80);
            l_type = CDIMM_DQ;

            FAPI_TRY(rosetta_map(i_target_mba, i_port_u8, l_type, i_input_index_u8, i_verbose, l_val));

            if(i_verbose)
            {
                FAPI_INF("C4 value is=%d", l_val);
            }

            FAPI_TRY(cross_coupled(i_target_mba, i_port_u8, l_rank_pair, i_input_type_e, l_val, i_verbose, l_out));

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_out.scom_addr);
                FAPI_INF("start bit=%d", l_out.start_bit);
                FAPI_INF("length=%d", l_out.bit_length);
            }

            l_scom_add = l_out.scom_addr;
            l_sbit = l_out.start_bit;
            l_len = l_out.bit_length;

        }


        else if(i_input_type_e == ADDRESS)
        {
            FAPI_ASSERT(i_input_index_u8 < MAX_ADDR && (get_port(l_mbapos, i_port_u8)) < 4,
                        fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                        set_MBA_TARGET(i_target_mba).
                        set_ACCESS_TYPE_PARAM(i_access_type_e).
                        set_PORT_PARAM(i_port_u8).
                        set_RANK_PARAM(i_rank_u8).
                        set_TYPE_PARAM(i_input_type_e).
                        set_INDEX_PARAM(i_input_index_u8),
                        "Wrong input index specified (%d)", i_input_index_u8);

            l_lane = l_addr_lane[(get_port(l_mbapos, i_port_u8))][i_input_index_u8];
            l_adr = l_addr_adr[(get_port(l_mbapos, i_port_u8))][i_input_index_u8];


            ip_type_t l_input = ADDRESS_t;

            if(i_verbose)
            {
                FAPI_INF("ADR=%d", l_adr);
                FAPI_INF("lane=%d", l_lane);
            }

            l_block = l_adr;
            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == DATA_DISABLE)
        {
            FAPI_ASSERT(i_input_index_u8 < MAX_DATA_DISABLE, //5 delay values for data bits disable register
                        fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                        set_MBA_TARGET(i_target_mba).
                        set_ACCESS_TYPE_PARAM(i_access_type_e).
                        set_PORT_PARAM(i_port_u8).
                        set_RANK_PARAM(i_rank_u8).
                        set_TYPE_PARAM(i_input_type_e).
                        set_INDEX_PARAM(i_input_index_u8),
                        "Wrong input index specified (%d)", i_input_index_u8);

            l_block = i_input_index_u8;

            ip_type_t l_input = DATA_DISABLE_t;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
            }

            l_lane = 0;
            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }


        else if(i_input_type_e == COMMAND)
        {
            if(i_input_index_u8 < MAX_CMD && (get_port(l_mbapos, i_port_u8)) < 4) // 3 delay values for Command
            {
                l_lane = l_cmd_lane[(get_port(l_mbapos, i_port_u8))][i_input_index_u8];
                l_adr = l_cmd_adr[(get_port(l_mbapos, i_port_u8))][i_input_index_u8];
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input index specified (%d)", i_input_index_u8);
            }

            ip_type_t l_input = COMMAND_t;

            if(i_verbose)
            {
                FAPI_INF("ADR=%d", l_adr);
                FAPI_INF("lane=%d", l_lane);
            }

            l_block = l_adr;
            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == CONTROL)
        {
            FAPI_ASSERT(i_input_index_u8 < MAX_CNT && (get_port(l_mbapos, i_port_u8)) < 4, // 20 delay values for Control
                        fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                        set_MBA_TARGET(i_target_mba).
                        set_ACCESS_TYPE_PARAM(i_access_type_e).
                        set_PORT_PARAM(i_port_u8).
                        set_RANK_PARAM(i_rank_u8).
                        set_TYPE_PARAM(i_input_type_e).
                        set_INDEX_PARAM(i_input_index_u8),
                        "Wrong input index specified (%d)", i_input_index_u8);

            l_lane = l_cnt_lane[(get_port(l_mbapos, i_port_u8))][i_input_index_u8];
            l_adr = l_cnt_adr[(get_port(l_mbapos, i_port_u8))][i_input_index_u8];

            ip_type_t l_input = CONTROL_t;

            if(i_verbose)
            {
                FAPI_INF("ADR=%d", l_adr);
                FAPI_INF("lane=%d", l_lane);
            }

            l_block = l_adr;
            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == CLOCK)
        {
            FAPI_ASSERT(i_input_index_u8 < MAX_CLK && (get_port(l_mbapos, i_port_u8)) < 4,
                        fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                        set_MBA_TARGET(i_target_mba).
                        set_ACCESS_TYPE_PARAM(i_access_type_e).
                        set_PORT_PARAM(i_port_u8).
                        set_RANK_PARAM(i_rank_u8).
                        set_TYPE_PARAM(i_input_type_e).
                        set_INDEX_PARAM(i_input_index_u8),
                        "Wrong input index specified (%d)", i_input_index_u8);
            l_lane = l_clk_lane[(get_port(l_mbapos, i_port_u8))][i_input_index_u8];
            l_adr = l_clk_adr[(get_port(l_mbapos, i_port_u8))][i_input_index_u8];
            ip_type_t l_input = CLOCK_t;

            if(i_verbose)
            {
                FAPI_INF("ADR=%d", l_adr);
                FAPI_INF("lane=%d", l_lane);
            }

            l_block = l_adr;
            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }


        else if (i_input_type_e == RD_DQS || i_input_type_e == WR_DQS || i_input_type_e == DQS_ALIGN
                 ||  i_input_type_e == DQS_GATE || i_input_type_e == RDCLK || i_input_type_e == DQSCLK)
        {

            if(l_dimmtype == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
            {
                l_type = CDIMM_DQS;
            }
            else
            {
                l_type = ISDIMM_DQS;
            }

            FAPI_TRY(rosetta_map(i_target_mba, i_port_u8, l_type, i_input_index_u8, i_verbose, l_val));

            if(i_verbose)
            {
                FAPI_INF("C4 value is=%d", l_val);
            }

            FAPI_TRY(cross_coupled(i_target_mba, i_port_u8, l_rank_pair, i_input_type_e, l_val, i_verbose, l_out));

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_out.scom_addr);
                FAPI_INF("start bit=%d", l_out.start_bit);
                FAPI_INF("length=%d", l_out.bit_length);
            }

            l_scom_add = l_out.scom_addr;
            l_sbit = l_out.start_bit;
            l_len = l_out.bit_length;

        }

        else if (i_input_type_e == RAW_CDIMM_WR_DQS || i_input_type_e == RAW_CDIMM_RD_DQS
                 || i_input_type_e == RAW_CDIMM_DQS_ALIGN ||  i_input_type_e == RAW_CDIMM_DQS_GATE || i_input_type_e == RAW_CDIMM_DQSCLK)
        {

            l_type = CDIMM_DQS;

            FAPI_TRY(rosetta_map(i_target_mba, i_port_u8, l_type, i_input_index_u8, i_verbose, l_val));

            if(i_verbose)
            {
                FAPI_INF("C4 value is=%d", l_val);
            }

            FAPI_TRY(cross_coupled(i_target_mba, i_port_u8, l_rank_pair, i_input_type_e, l_val, i_verbose, l_out));

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_out.scom_addr);
                FAPI_INF("start bit=%d", l_out.start_bit);
                FAPI_INF("length=%d", l_out.bit_length);
            }

            l_scom_add = l_out.scom_addr;
            l_sbit = l_out.start_bit;
            l_len = l_out.bit_length;

        }



        else if(i_input_type_e == RAW_RDCLK_0 || i_input_type_e == RAW_RDCLK_1 || i_input_type_e == RAW_RDCLK_2
                || i_input_type_e == RAW_RDCLK_3 || i_input_type_e == RAW_RDCLK_4)
        {
            if(i_input_type_e == RAW_RDCLK_0)
            {
                l_block = 0;
            }

            else if(i_input_type_e == RAW_RDCLK_1)
            {
                l_block = 1;
            }

            else if(i_input_type_e == RAW_RDCLK_2)
            {
                l_block = 2;
            }

            else if(i_input_type_e == RAW_RDCLK_3)
            {
                l_block = 3;
            }

            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 3) // 4 delay values for RDCLK
            {
                l_lane = i_input_index_u8;
            }

            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_RDCLK;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_DQSCLK_0 || i_input_type_e == RAW_DQSCLK_1 || i_input_type_e == RAW_DQSCLK_2
                || i_input_type_e == RAW_DQSCLK_3 || i_input_type_e == RAW_DQSCLK_4)
        {
            if(i_input_type_e == RAW_DQSCLK_0)
            {
                l_block = 0;
            }

            else if(i_input_type_e == RAW_DQSCLK_1)
            {
                l_block = 1;
            }

            else if(i_input_type_e == RAW_DQSCLK_2)
            {
                l_block = 2;
            }

            else if(i_input_type_e == RAW_DQSCLK_3)
            {
                l_block = 3;
            }

            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 3) // 4 delay values for DQSCLK
            {
                l_lane = i_input_index_u8;
            }

            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_DQSCLK;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }


        else if(i_input_type_e == RAW_WR_DQ_0 || i_input_type_e == RAW_WR_DQ_1 || i_input_type_e == RAW_WR_DQ_2
                || i_input_type_e == RAW_WR_DQ_3 || i_input_type_e == RAW_WR_DQ_4)
        {
            if(i_input_type_e == RAW_WR_DQ_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_WR_DQ_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_WR_DQ_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_WR_DQ_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 15) // 16 Write delay values for DQ bits
            {
                l_lane = i_input_index_u8;
            }

            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_WR_DQ;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_RD_DQ_0 || i_input_type_e == RAW_RD_DQ_1 || i_input_type_e == RAW_RD_DQ_2
                || i_input_type_e == RAW_RD_DQ_3 || i_input_type_e == RAW_RD_DQ_4)
        {
            if(i_input_type_e == RAW_RD_DQ_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_RD_DQ_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_RD_DQ_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_RD_DQ_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 15) // 16 read delay values for DQ bits
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_RD_DQ;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_RD_DQS_0 || i_input_type_e == RAW_RD_DQS_1 || i_input_type_e == RAW_RD_DQS_2
                || i_input_type_e == RAW_RD_DQS_3 || i_input_type_e == RAW_RD_DQS_4)
        {
            if(i_input_type_e == RAW_RD_DQS_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_RD_DQS_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_RD_DQS_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_RD_DQS_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 3) // 4 Read DQS delay values
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_RD_DQS;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_DQS_ALIGN_0 || i_input_type_e == RAW_DQS_ALIGN_1 || i_input_type_e == RAW_DQS_ALIGN_2
                || i_input_type_e == RAW_DQS_ALIGN_3 || i_input_type_e == RAW_DQS_ALIGN_4)
        {
            if(i_input_type_e == RAW_DQS_ALIGN_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_DQS_ALIGN_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_DQS_ALIGN_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_DQS_ALIGN_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 3)   // 4 DQS alignment delay values
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input index specified (%d)", i_input_index_u8);
            }

            ip_type_t l_input = RAW_DQS_ALIGN;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }


        else if(i_input_type_e == RAW_WR_DQS_0 || i_input_type_e == RAW_WR_DQS_1 || i_input_type_e == RAW_WR_DQS_2
                || i_input_type_e == RAW_WR_DQS_3 || i_input_type_e == RAW_WR_DQS_4)
        {
            if(i_input_type_e == RAW_WR_DQS_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_WR_DQS_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_WR_DQS_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_WR_DQS_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 3)    // 4 Write DQS delay values
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_WR_DQS;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }
        else if(i_input_type_e == RAW_SYS_CLK_0 || i_input_type_e == RAW_SYS_CLK_1 || i_input_type_e == RAW_SYS_CLK_2
                || i_input_type_e == RAW_SYS_CLK_3 || i_input_type_e == RAW_SYS_CLK_4)
        {
            if(i_input_type_e == RAW_SYS_CLK_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_SYS_CLK_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_SYS_CLK_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_SYS_CLK_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 == 0) // 1 system clock delay value
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input index specified (%d)", i_input_index_u8);
            }

            ip_type_t l_input = RAW_SYS_CLK;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_SYS_ADDR_CLK)
        {
            if(i_input_index_u8 <= 1) // 1 system address clock delay value
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input index specified (%d)", i_input_index_u8);
            }

            ip_type_t l_input = RAW_SYS_ADDR_CLKS0S1;

            if(i_verbose)
            {
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }


        else if(i_input_type_e == RAW_WR_CLK_0 || i_input_type_e == RAW_WR_CLK_1 || i_input_type_e == RAW_WR_CLK_2
                || i_input_type_e == RAW_WR_CLK_3 || i_input_type_e == RAW_WR_CLK_4)
        {
            if(i_input_type_e == RAW_WR_CLK_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_WR_CLK_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_WR_CLK_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_WR_CLK_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 == 0)         //  1 Write clock delay value
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input index specified (%d)", i_input_index_u8);
            }

            ip_type_t l_input = RAW_WR_CLK;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_ADDR_0 || i_input_type_e == RAW_ADDR_1 || i_input_type_e == RAW_ADDR_2
                || i_input_type_e == RAW_ADDR_3)
        {
            if(i_input_type_e == RAW_ADDR_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_ADDR_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_ADDR_2)
            {
                l_block = 2;
            }
            else
            {
                l_block = 3;
            }

            if(i_input_index_u8 <= 15)    //  16 Addr delay values
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input index specified (%d)", i_input_index_u8);
            }

            ip_type_t l_input = RAW_ADDR;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_DQS_GATE_0 || i_input_type_e == RAW_DQS_GATE_1 || i_input_type_e == RAW_DQS_GATE_2
                || i_input_type_e == RAW_DQS_GATE_3 || i_input_type_e == RAW_DQS_GATE_4)
        {
            if(i_input_type_e == RAW_DQS_GATE_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_DQS_GATE_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_DQS_GATE_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_DQS_GATE_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 3)   // 4 Gate Delay values
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input index specified (%d)", i_input_index_u8);
            }

            ip_type_t l_input = RAW_DQS_GATE;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                        set_MBA_TARGET(i_target_mba).
                        set_ACCESS_TYPE_PARAM(i_access_type_e).
                        set_PORT_PARAM(i_port_u8).
                        set_RANK_PARAM(i_rank_u8).
                        set_TYPE_PARAM(i_input_type_e).
                        set_INDEX_PARAM(i_input_index_u8),
                        "Wrong input type specified (%d)", i_input_type_e);
        }

        if(i_access_type_e == READ)
        {
            FAPI_TRY(fapi2::getScom(i_target_mba, l_scom_add, l_data_buffer_64));
            FAPI_TRY(l_data_buffer_64.extractToRight(l_output, l_sbit, l_len));
            io_value_u32 = l_output;
            // FAPI_INF("Delay value=%d",io_value_u32);
        }

        else if(i_access_type_e == WRITE)
        {

            if(i_input_type_e == RD_DQ || i_input_type_e == RD_DQS || i_input_type_e == RAW_RD_DQ_0
               || i_input_type_e == RAW_RD_DQ_1 || i_input_type_e == RAW_RD_DQ_2 || i_input_type_e == RAW_RD_DQ_3
               || i_input_type_e == RAW_RD_DQ_4 || i_input_type_e == RAW_RD_DQS_0 || i_input_type_e == RAW_RD_DQS_1
               || i_input_type_e == RAW_RD_DQS_2 || i_input_type_e == RAW_RD_DQS_3 || i_input_type_e == RAW_RD_DQS_4
               || i_input_type_e == RAW_SYS_ADDR_CLK || i_input_type_e == RAW_SYS_CLK_0 || i_input_type_e == RAW_SYS_CLK_1
               || i_input_type_e == RAW_SYS_CLK_2 || i_input_type_e == RAW_SYS_CLK_3 || i_input_type_e == RAW_SYS_CLK_4
               || i_input_type_e == RAW_WR_CLK_0 || i_input_type_e == RAW_WR_CLK_1 || i_input_type_e == RAW_WR_CLK_2
               || i_input_type_e == RAW_WR_CLK_3 || i_input_type_e == RAW_WR_CLK_4
               || i_input_type_e == RAW_ADDR_0 || i_input_type_e == RAW_ADDR_1 || i_input_type_e == RAW_ADDR_2
               || i_input_type_e == RAW_ADDR_3 || i_input_type_e == RAW_DQS_ALIGN_0 || i_input_type_e == RAW_DQS_ALIGN_1
               || i_input_type_e == RAW_DQS_ALIGN_2 || i_input_type_e == RAW_DQS_ALIGN_3 || i_input_type_e == RAW_DQS_ALIGN_4
               || i_input_type_e == DQS_ALIGN || i_input_type_e == COMMAND || i_input_type_e == ADDRESS || i_input_type_e == CONTROL
               || i_input_type_e == CLOCK || i_input_type_e == RAW_CDIMM_RD_DQ || i_input_type_e == RAW_CDIMM_RD_DQS
               || i_input_type_e == RAW_CDIMM_DQS_ALIGN)
            {
                l_start = 25; // l_start is starting bit of delay value in the register. There are different registers and each register has a different field for delay
            }
            else if(i_input_type_e == WR_DQ || i_input_type_e == WR_DQS || i_input_type_e == RAW_WR_DQ_0
                    || i_input_type_e == RAW_WR_DQ_1 || i_input_type_e == RAW_WR_DQ_2 || i_input_type_e == RAW_WR_DQ_3
                    || i_input_type_e == RAW_WR_DQ_4 || i_input_type_e == RAW_WR_DQS_0 || i_input_type_e == RAW_WR_DQS_1
                    || i_input_type_e == RAW_WR_DQS_2 || i_input_type_e == RAW_WR_DQS_3 || i_input_type_e == RAW_WR_DQS_4
                    || i_input_type_e == RAW_CDIMM_WR_DQ || i_input_type_e == RAW_CDIMM_WR_DQS )
            {
                l_start = 22;
            }

            else if(i_input_type_e == RAW_DQS_GATE_0 || i_input_type_e == RAW_DQS_GATE_1 || i_input_type_e == RAW_DQS_GATE_2
                    || i_input_type_e == RAW_DQS_GATE_3 || i_input_type_e == RAW_DQS_GATE_4 || i_input_type_e == DQS_GATE
                    || i_input_type_e == RAW_CDIMM_DQS_GATE)
            {
                l_start = 29;
            }

            else if(i_input_type_e == RAW_RDCLK_0 || i_input_type_e == RAW_RDCLK_1 || i_input_type_e == RAW_RDCLK_2
                    || i_input_type_e == RAW_RDCLK_3 || i_input_type_e == RAW_RDCLK_4 || i_input_type_e == RDCLK
                    || i_input_type_e == RAW_DQSCLK_0 || i_input_type_e == RAW_DQSCLK_1 || i_input_type_e == RAW_DQSCLK_2
                    || i_input_type_e == RAW_DQSCLK_3 || i_input_type_e == RAW_DQSCLK_4 || i_input_type_e == DQSCLK
                    || i_input_type_e == RAW_CDIMM_DQSCLK)
            {
                l_start = 30;
            }

            else if(i_input_type_e == DATA_DISABLE)
            {
                l_start = 16;
            }

            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                            set_MBA_TARGET(i_target_mba).
                            set_ACCESS_TYPE_PARAM(i_access_type_e).
                            set_PORT_PARAM(i_port_u8).
                            set_RANK_PARAM(i_rank_u8).
                            set_TYPE_PARAM(i_input_type_e).
                            set_INDEX_PARAM(i_input_index_u8),
                            "Wrong input type specified (%d)", i_input_type_e);

            }

            if(i_verbose)
            {
                FAPI_INF("value given=%d", io_value_u32);
            }

            FAPI_TRY(fapi2::getScom(i_target_mba, l_scom_add, l_data_buffer_64));
            FAPI_TRY(l_data_buffer_64.insert(io_value_u32, l_sbit, l_len, l_start));
            FAPI_TRY(fapi2::putScom(i_target_mba, l_scom_add, l_data_buffer_64));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///@function cross_coupled()
    ///@brief This function returns address,start bit and bit length for RD_DQ, WR_DQ, RD_DQS, WR_DQS
    ///@param[in] Target MBA=i_target_mba
    ///@param[in] i_port_u8=0 or 1
    ///@param[in] i_rank_pair=0 or 1 or 2 or 3
    ///@param[in] i_input_type_e=RD_DQ or RD_DQS or WR_DQ or WR_DQS
    ///@param[in] i_input_index_u8=0-79/0-71/0-8/0-19
    ///@param[in] i_verbose-extra print statements
    ///@param[out] out (address,start bit and bit length)
    ///@return fapi2::ReturnCode
    fapi2::ReturnCode cross_coupled(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                    const uint8_t i_port,
                                    const uint8_t i_rank_pair,
                                    const input_type_t i_input_type_e,
                                    const uint8_t i_input_index,
                                    const bool i_verbose,
                                    scom_location& out)
    {
        const uint8_t l_dqs = 4;
        const uint8_t l_lane_dq[MAX_PORTS_PER_CEN][DIMM_TO_C4_DQ_ENTRIES] =
        {
            {4, 6, 5, 7, 2, 1, 3, 0, 13, 15, 12, 14, 8, 9, 11, 10, 13, 15, 12, 14, 9, 8, 11, 10, 13, 15, 12, 14, 11, 9, 10, 8, 11, 8, 9, 10, 12, 13, 14, 15, 7, 6, 5, 4, 1, 3, 2, 0, 5, 6, 4, 7, 3, 1, 2, 0, 7, 4, 5, 6, 2, 0, 3, 1, 3, 0, 1, 2, 6, 5, 4, 7, 11, 8, 9, 10, 15, 13, 12, 14},
            {9, 11, 8, 10, 13, 14, 15, 12, 10, 8, 11, 9, 12, 13, 14, 15, 1, 0, 2, 3, 4, 5, 6, 7, 9, 11, 10, 8, 15, 12, 13, 14, 5, 7, 6, 4, 1, 0, 2, 3, 0, 2, 1, 3, 5, 4, 6, 7, 0, 2, 3, 1, 4, 5, 6, 7, 12, 15, 13, 14, 11, 8, 10, 9, 5, 7, 4, 6, 3, 2, 0, 1, 14, 12, 15, 13, 9, 8, 11, 10},
            {13, 15, 12, 14, 11, 9, 10, 8, 13, 12, 14, 15, 10, 9, 11, 8, 5, 6, 7, 4, 2, 3, 0, 1, 10, 9, 8, 11, 13, 12, 15, 14, 15, 12, 13, 14, 11, 10, 9, 8, 7, 6, 4, 5, 1, 0, 3, 2, 0, 2, 1, 3, 5, 6, 4, 7, 5, 7, 6, 4, 1, 0, 2, 3, 1, 2, 3, 0, 7, 6, 5, 4, 9, 10, 8, 11, 12, 15, 14, 13},
            {4, 5, 6, 7, 0, 1, 3, 2, 12, 13, 15, 14, 8, 9, 10, 11, 10, 8, 11, 9, 12, 13, 15, 14, 3, 0, 1, 2, 4, 6, 7, 5, 9, 10, 11, 8, 14, 13, 15, 12, 7, 5, 6, 4, 3, 1, 2, 0, 5, 6, 7, 4, 1, 2, 3, 0, 14, 12, 15, 13, 8, 10, 9, 11, 0, 3, 2, 1, 6, 5, 7, 4, 10, 11, 9, 8, 12, 13, 15, 14},
        };
        const uint8_t l_dqs_dq_lane[MAX_PORTS_PER_CEN][DIMM_TO_C4_DQS_ENTRIES] =
        {
            {4, 0, 12, 8, 12, 8, 12, 8, 8, 12, 4, 0, 4, 0, 4, 0, 0, 4, 8, 12},
            {8, 12, 8, 12, 0, 4, 8, 12, 4, 0, 0, 4, 0, 4, 12, 8, 4, 0, 12, 8},
            {12, 8, 12, 8, 4, 0, 8, 12, 12, 8, 4, 0, 0, 4, 4, 0, 0, 4, 8, 12},
            {4, 0, 12, 8, 8, 12, 0, 4, 8, 12, 4, 0, 4, 0, 12, 8, 0, 4, 8, 12},
        };
        const uint8_t l_block_dq[MAX_PORTS_PER_CEN][DIMM_TO_C4_DQ_ENTRIES] =
        {
            {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2},
            {1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4},
            {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        };
        const uint8_t l_block_dqs[MAX_PORTS_PER_CEN][DIMM_TO_C4_DQS_ENTRIES] =
        {
            {2, 2, 2, 2, 0, 0, 3, 3, 4, 4, 3, 3, 4, 4, 1, 1, 0, 0, 1, 1},
            {0, 0, 3, 3, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 1, 1, 2, 2},
            {1, 1, 3, 3, 0, 0, 0, 0, 2, 2, 2, 2, 3, 3, 4, 4, 1, 1, 4, 4},
            {2, 2, 2, 2, 0, 0, 0, 0, 3, 3, 3, 3, 4, 4, 4, 4, 1, 1, 1, 1},
        };
        const uint8_t l_dqslane[l_dqs] = {16, 18, 20, 22};
        uint8_t l_j = 0;
        uint8_t l_flag = 0;
        uint8_t l_mbapos = 0;
        uint8_t l_dram_width = 0;
        uint8_t l_lane = 0;
        uint8_t l_block = 0;
        uint8_t l_lane_dqs[4] = {0};
        uint8_t l_index = 0;
        uint8_t l_dq = 0;
        uint64_t l_scom_address_64 = 0x0ull;
        uint8_t l_start_bit = 0;
        uint8_t l_len = 0;
        ip_type_t l_input_type;
        fapi2::buffer<uint64_t> l_data_buffer_64;
        uint8_t l_dimmtype = 0;
        uint8_t l_swizzle = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_DQS_SWIZZLE_TYPE, i_target_mba, l_swizzle));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_mba, l_mbapos));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_dimmtype));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target_mba, l_dram_width));

        FAPI_ASSERT(get_port(l_mbapos, i_port) < 4,
                    fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                    set_MBA_TARGET(i_target_mba).
                    set_PORT_PARAM(i_port).
                    set_RANK_PARAM(i_rank_pair).
                    set_TYPE_PARAM(i_input_type_e).
                    set_INDEX_PARAM(i_input_index),
                    "Port not valid (%d)", get_port(l_mbapos, i_port));

        if(i_input_type_e == RD_DQ || i_input_type_e == WR_DQ || i_input_type_e == RAW_CDIMM_WR_DQ
           || i_input_type_e == RAW_CDIMM_RD_DQ )
        {
            l_lane = l_lane_dq[get_port(l_mbapos, i_port)][i_input_index];
            l_block = l_block_dq[get_port(l_mbapos, i_port)][i_input_index];

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            if(i_input_type_e == RD_DQ)
            {
                l_input_type = RD_DQ_t;
            }
            else
            {
                l_input_type = WR_DQ_t;
            }


            FAPI_TRY(get_address(i_target_mba, i_port, i_rank_pair, l_input_type, l_block, l_lane, l_scom_address_64, l_start_bit,
                                 l_len));
            out.scom_addr = l_scom_address_64;
            out.start_bit = l_start_bit;
            out.bit_length = l_len;
        }

        else if (i_input_type_e == WR_DQS ||  i_input_type_e == DQS_ALIGN || i_input_type_e == RAW_CDIMM_WR_DQS
                 || i_input_type_e == RAW_CDIMM_DQS_ALIGN)
        {
            l_dq = l_dqs_dq_lane[get_port(l_mbapos, i_port)][i_input_index];
            l_block = l_block_dqs[get_port(l_mbapos, i_port)][i_input_index];

            l_input_type = RD_CLK_t;
            FAPI_TRY(get_address(i_target_mba, i_port, i_rank_pair, l_input_type, l_block, l_lane, l_scom_address_64, l_start_bit,
                                 l_len));

            FAPI_TRY(fapi2::getScom(i_target_mba, l_scom_address_64, l_data_buffer_64));

            if(l_dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4)
            {

                if (l_data_buffer_64.getBit(48))
                {
                    l_lane_dqs[l_index] = 16;
                    l_index++;
                }
                else if(l_data_buffer_64.getBit(52))
                {
                    l_lane_dqs[l_index] = 18;
                    l_index++;
                }

                if (l_data_buffer_64.getBit(49))
                {
                    l_lane_dqs[l_index] = 16;
                    l_index++;
                }

                else if (l_data_buffer_64.getBit(53))
                {
                    l_lane_dqs[l_index] = 18;
                    l_index++;
                }

                if (l_data_buffer_64.getBit(54))
                {
                    l_lane_dqs[l_index] = 20;
                    l_index++;
                }
                else if (l_data_buffer_64.getBit(56))
                {
                    l_lane_dqs[l_index] = 22;
                    l_index++;
                }

                if (l_data_buffer_64.getBit(55))
                {
                    l_lane_dqs[l_index] = 20;
                    l_index++;
                }
                else if (l_data_buffer_64.getBit(57))   // else is not possible as one of them will definitely get set
                {
                    l_lane_dqs[l_index] = 22;
                    l_index++;
                }

                if(l_dq == 0)
                {
                    l_lane = l_lane_dqs[0];
                }
                else if(l_dq == 4)
                {
                    l_lane = l_lane_dqs[1];
                }
                else if(l_dq == 8)
                {
                    l_lane = l_lane_dqs[2];
                }
                else
                {
                    l_lane = l_lane_dqs[3];
                }

            } //end if DRAM_WIDTH_X4


            else
            {
                if (l_data_buffer_64.getBit(48) && l_data_buffer_64.getBit(49))
                {
                    l_lane_dqs[l_index] = 16;
                    l_index++;
                }
                else if (l_data_buffer_64.getBit(52) && l_data_buffer_64.getBit(53))
                {
                    l_lane_dqs[l_index] = 18;
                    l_index++;
                }

                if (l_data_buffer_64.getBit(54) && l_data_buffer_64.getBit(55))
                {
                    l_lane_dqs[l_index] = 20;
                    l_index++;
                }
                else if (l_data_buffer_64.getBit(56)
                         && l_data_buffer_64.getBit(57))  // else is not possible as one of them will definitely get set
                {
                    l_lane_dqs[l_index] = 22;
                    l_index++;
                }

                if(i_verbose)
                {
                    FAPI_INF("array is=%d and %d", l_lane_dqs[0], l_lane_dqs[1]);
                }

                if((l_dq == 0) || (l_dq == 4))
                {
                    l_lane = l_lane_dqs[0];
                }
                else
                {
                    l_lane = l_lane_dqs[1];
                }

                if(l_dimmtype == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
                {
                    if((i_input_index == 1) || (i_input_index == 3) || (i_input_index == 5) || (i_input_index == 7) || (i_input_index == 9)
                       || (i_input_index == 11) || (i_input_index == 13) || (i_input_index == 15) || (i_input_index == 17)
                       || (i_input_index == 19))
                    {
                        if(l_lane == 16)
                        {
                            l_lane = 18;
                        }
                        else if(l_lane == 18)
                        {
                            l_lane = 16;
                        }

                        else if(l_lane == 20)
                        {
                            l_lane = 22;
                        }

                        else
                        {
                            l_lane = 20;
                        }

                    }
                }

                else
                {
                    if((i_port == 0) && (l_mbapos == 0))
                    {
                        if(l_swizzle == 1)
                        {
                            if((i_input_index == 3) || (i_input_index == 1) || (i_input_index == 4) || (i_input_index == 17)
                               || (i_input_index == 9) || (i_input_index == 11) || (i_input_index == 13) || (i_input_index == 15)
                               ||  (i_input_index == 6))
                            {
                                if(l_lane == 16)
                                {
                                    l_lane = 18;
                                }
                                else if(l_lane == 18)
                                {
                                    l_lane = 16;
                                }

                                else if(l_lane == 20)
                                {
                                    l_lane = 22;
                                }

                                else
                                {
                                    l_lane = 20;
                                }

                            }
                        }

                        else
                        {
                            if((i_input_index == 3) || (i_input_index == 1) || (i_input_index == 5) || (i_input_index == 7) || (i_input_index == 9)
                               || (i_input_index == 11) || (i_input_index == 13) || (i_input_index == 15) ||  (i_input_index == 17))
                            {
                                if(l_lane == 16)
                                {
                                    l_lane = 18;
                                }
                                else if(l_lane == 18)
                                {
                                    l_lane = 16;
                                }

                                else if(l_lane == 20)
                                {
                                    l_lane = 22;
                                }

                                else
                                {
                                    l_lane = 20;
                                }
                            }

                        }
                    }

                    else if((i_port == 1) && (l_mbapos == 0))
                    {
                        if(l_swizzle == 1)
                        {
                            if((i_input_index == 2) || (i_input_index == 0) || (i_input_index == 4) || (i_input_index == 17)
                               || (i_input_index == 9) || (i_input_index == 11) || (i_input_index == 13) || (i_input_index == 15)
                               ||  (i_input_index == 7))
                            {
                                if(l_lane == 16)
                                {
                                    l_lane = 18;
                                }
                                else if(l_lane == 18)
                                {
                                    l_lane = 16;
                                }

                                else if(l_lane == 20)
                                {
                                    l_lane = 22;
                                }

                                else
                                {
                                    l_lane = 20;
                                }
                            }
                        }

                        else
                        {
                            if((i_input_index == 1) || (i_input_index == 3) || (i_input_index == 5) || (i_input_index == 7) || (i_input_index == 9)
                               || (i_input_index == 11) || (i_input_index == 13) || (i_input_index == 15) ||  (i_input_index == 17))
                            {
                                if(l_lane == 16)
                                {
                                    l_lane = 18;
                                }
                                else if(l_lane == 18)
                                {
                                    l_lane = 16;
                                }

                                else if(l_lane == 20)
                                {
                                    l_lane = 22;
                                }

                                else
                                {
                                    l_lane = 20;
                                }
                            }
                        }
                    }


                    else
                    {
                        if((i_input_index == 1) || (i_input_index == 3) || (i_input_index == 5) || (i_input_index == 7) || (i_input_index == 9)
                           || (i_input_index == 11) || (i_input_index == 13) || (i_input_index == 15) ||  (i_input_index == 17))
                        {
                            if(l_lane == 16)
                            {
                                l_lane = 18;
                            }
                            else if(l_lane == 18)
                            {
                                l_lane = 16;
                            }

                            else if(l_lane == 20)
                            {
                                l_lane = 22;
                            }

                            else
                            {
                                l_lane = 20;
                            }
                        }
                    }
                } // end if dimm is not custom dimm

            } // end if dram width is not X4

            if(i_input_type_e == WR_DQS)
            {
                l_input_type = WR_DQS_t;
            }
            else
            {
                l_input_type = DQS_ALIGN_t;
            }


            for(l_j = 0; l_j < 4; l_j++)
            {
                if(l_lane == l_dqslane[l_j])
                {
                    l_flag = 1;
                    break;
                }
            }

            if(l_flag == 0)
            {
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::CEN_CROSS_COUPLED_INVALID_DQS().
                                   set_INVALID_DQS(l_lane).
                                   set_MBA_TARGET(i_target_mba),
                                   "Invalid DQS and DQS lane=%d on %s lwm", l_lane, mss::c_str(i_target_mba));
            }

            FAPI_TRY(get_address(i_target_mba, i_port, i_rank_pair, l_input_type, l_block, l_lane, l_scom_address_64, l_start_bit,
                                 l_len));
            out.scom_addr = l_scom_address_64;
            out.start_bit = l_start_bit;
            out.bit_length = l_len;
        }


        else if (i_input_type_e == RD_DQS || i_input_type_e == DQS_GATE || i_input_type_e == RDCLK || i_input_type_e == DQSCLK
                 || i_input_type_e == RAW_CDIMM_DQS_GATE || i_input_type_e == RAW_CDIMM_DQSCLK || i_input_type_e == RAW_CDIMM_RD_DQS )
        {
            l_dq = l_dqs_dq_lane[get_port(l_mbapos, i_port)][i_input_index];
            l_block = l_block_dqs[get_port(l_mbapos, i_port)][i_input_index];

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("l_dqs_dq_lane=%d", l_dq);
            }

            if(l_dq == 0)
            {
                l_lane = 16;
            }

            else if(l_dq == 4)
            {
                l_lane = 18;
            }

            else if (l_dq == 8)
            {
                l_lane = 20;
            }

            else
            {
                l_lane = 22;
            }

            if (i_input_type_e == DQS_GATE)
            {
                l_input_type = DQS_GATE_t;
            }

            else if(i_input_type_e == RDCLK)
            {
                l_input_type = RDCLK_t;
            }

            else if(i_input_type_e == RD_DQS)
            {
                l_input_type = RD_DQS_t;
            }

            else
            {
                l_input_type = DQSCLK_t;
            }

            if(i_verbose)
            {
                FAPI_INF("lane is=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port, i_rank_pair, l_input_type, l_block, l_lane, l_scom_address_64, l_start_bit,
                                 l_len));
            out.scom_addr = l_scom_address_64;
            out.start_bit = l_start_bit;
            out.bit_length = l_len;
        }

        else
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_CROSS_COUPLED_INVALID_INPUT().
                        set_MBA_TARGET(i_target_mba).
                        set_TYPE_PARAM(i_input_type_e),
                        "Wrong input type specified (%d)", i_input_type_e);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }


    ///@function rosetta_map()
    ///@brief This function returns C4 bit for the corresponding ISDIMM bit
    ///@param[in] Target MBA=i_target_mba
    ///@param[in] i_port_u8=0 or 1
    ///@param[in] i_input_type_e=RD_DQ or RD_DQS or WR_DQ or WR_DQS
    ///@param[in] i_input_index_u8=0-79/0-71/0-8/0-19
    ///@param[in] i_verbose-extra print statements
    ///@param[out] C4 bit=o_value
    ///@return fapi2::returnCode
    fapi2::ReturnCode rosetta_map(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                  const uint8_t i_port,
                                  const input_type i_input_type_e,
                                  const uint8_t i_input_index,
                                  const bool i_verbose,
                                  uint8_t& o_value) //This function is used by some other procedures
    {
        // Boundary check is done again
        uint8_t l_mbapos = 0;
        uint8_t l_dimmtype = 0;
        uint8_t l_swizzle = 0;
        const uint8_t l_GL_DQ_p0_g1[ISDIMM_MAX_DQ_72] = {10, 9, 11, 8, 12, 13, 14, 15, 3, 1, 2, 0, 7, 5, 4, 6, 20, 21, 22, 23, 16, 17, 18, 19, 64, 65, 66, 67, 71, 70, 69, 68, 32, 33, 34, 35, 36, 37, 38, 39, 42, 40, 43, 41, 44, 46, 45, 47, 48, 51, 50, 49, 52, 53, 54, 55, 58, 56, 57, 59, 60, 61, 62, 63, 31, 28, 29, 30, 25, 27, 26, 24};
        const uint8_t l_GL_DQ_p0_g2[ISDIMM_MAX_DQ_72] = {10, 9, 11, 8, 12, 13, 14, 15, 3, 1, 2, 0, 7, 5, 4, 6, 16, 17, 18, 19, 20, 21, 22, 23, 64, 65, 66, 67, 71, 70, 69, 68, 32, 33, 34, 35, 36, 37, 38, 39, 42, 40, 43, 41, 44, 46, 45, 47, 48, 51, 50, 49, 52, 53, 54, 55, 58, 56, 57, 59, 60, 61, 62, 63, 25, 27, 26, 24, 28, 31, 29, 30};
        const uint8_t l_GL_DQ_p1_g1[ISDIMM_MAX_DQ_72] = {15, 13, 12, 14, 9, 8, 10, 11, 5, 7, 4, 6, 3, 2, 1, 0, 20, 22, 21, 23, 16, 17, 18, 19, 70, 71, 69, 68, 67, 66, 65, 64, 32, 35, 34, 33, 38, 37, 39, 36, 40, 41, 42, 43, 44, 45, 46, 47, 49, 50, 48, 51, 52, 53, 54, 55, 59, 57, 56, 58, 60, 62, 61, 63, 27, 26, 25, 24, 31, 30, 28, 29};
        const uint8_t l_GL_DQ_p1_g2[ISDIMM_MAX_DQ_72] = {8, 9, 10, 11, 12, 13, 14, 15, 3, 2, 1, 0, 4, 5, 6, 7, 16, 17, 18, 19, 20, 21, 22, 23, 67, 66, 64, 65, 70, 71, 69, 68, 32, 35, 34, 33, 38, 37, 39, 36, 40, 41, 42, 43, 44, 45, 46, 47, 49, 50, 48, 51, 52, 53, 54, 55, 59, 57, 56, 58, 60, 62, 61, 63, 27, 26, 25, 24, 31, 30, 28, 29};
        const uint8_t l_GL_DQ_p2[ISDIMM_MAX_DQ_72] = {9, 11, 10, 8, 12, 15, 13, 14, 0, 1, 3, 2, 5, 4, 7, 6, 19, 17, 16, 18, 20, 22, 21, 23, 66, 67, 65, 64, 71, 70, 69, 68, 32, 33, 34, 35, 36, 37, 38, 39, 41, 40, 43, 42, 45, 44, 47, 46, 48, 49, 50, 51, 52, 53, 54, 55, 58, 56, 57, 59, 60, 61, 62, 63, 25, 27, 24, 26, 28, 31, 29, 30};
        const uint8_t l_GL_DQ_p3[ISDIMM_MAX_DQ_72] = {3, 2, 0, 1, 4, 5, 6, 7, 11, 10, 8, 9, 15, 14, 12, 13, 16, 17, 18, 19, 20, 21, 22, 23, 64, 65, 66, 67, 68, 69, 70, 71, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 24, 25, 26, 27, 28, 29, 30, 31};

        const uint8_t l_GL_DQS_p0_g1[ISDIMM_MAX_DQS_18] = {2, 0, 5, 16, 8, 10, 12, 14, 7, 3, 1, 4, 17, 9, 11, 13, 15, 6};
        const uint8_t l_GL_DQS_p0_g2[ISDIMM_MAX_DQS_18] = {2, 0, 4, 16, 8, 10, 12, 14, 6, 3, 1, 5, 17, 9, 11, 13, 15, 7};
        const uint8_t l_GL_DQS_p1_g1[ISDIMM_MAX_DQS_18] = {3, 1, 5, 16, 8, 10, 12, 14, 6, 2, 0, 4, 17, 9, 11, 13, 15, 7};
        const uint8_t l_GL_DQS_p1_g2[ISDIMM_MAX_DQS_18] = {2, 0, 4, 16, 8, 10, 12, 14, 6, 3, 1, 5, 17, 9, 11, 13, 15, 7};
        const uint8_t l_GL_DQS_p2[ISDIMM_MAX_DQS_18] = {2, 0, 4, 16, 8, 10, 12, 14, 6, 3, 1, 5, 17, 9, 11, 13, 15, 7};
        const uint8_t l_GL_DQS_p3[ISDIMM_MAX_DQS_18] = {0, 2, 4, 16, 8, 10, 12, 14, 6, 1, 3, 5, 17, 9, 11, 13, 15, 7};
        uint8_t l_isdm_c4_dq[4][80];
        uint8_t l_isdm_c4_dqs[4][20];

        FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_DQS_SWIZZLE_TYPE, i_target_mba, l_swizzle);
        FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_dimmtype);

        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> i_target_centaur;
        i_target_centaur = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        if(l_dimmtype != fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_ISDIMMTOC4DQS, i_target_centaur, l_isdm_c4_dqs));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_ISDIMMTOC4DQ, i_target_centaur, l_isdm_c4_dq));
        }


        if(l_swizzle == 0 || l_swizzle == 1 || l_swizzle == 2)
        {
            if(i_verbose)
            {
                FAPI_INF("swizzle type=%d", l_swizzle);
            }
        }

        else
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_ROSETTA_MAP_BAD_SWIZZLE_VALUE().
                        set_SWIZZLE_TYPE(l_swizzle),
                        "Wrong swizzle value (%d)", l_swizzle);

        }

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_mba, l_mbapos));

        if(i_port > 1)
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_ROSETTA_MAP_INVALID_INPUT().
                        set_MBA_TARGET(i_target_mba).
                        set_PORT_PARAM(i_port).
                        set_TYPE_PARAM(i_input_type_e).
                        set_INDEX_PARAM(i_input_index),
                        "Wrong port specified (%d)", i_port);

        }

        if (l_mbapos > 1)
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_ROSETTA_MAP_BAD_MBA_POS().
                        set_MBA_TARGET(i_target_mba).
                        set_MBA_POS(l_mbapos),
                        "Bad position from ATTR_CHIP_UNIT_POS (%d)", l_mbapos);

        }

        if(i_input_type_e == ISDIMM_DQ)
        {
            if(i_port == 0 && l_mbapos == 0)
            {
                if(l_swizzle == 1)
                {
                    o_value = l_GL_DQ_p0_g1[i_input_index];
                }
                else if(l_swizzle == 0)
                {
                    o_value = l_GL_DQ_p0_g2[i_input_index];
                }
                else
                {
                    o_value = l_isdm_c4_dq[i_port][i_input_index];
                }

            }

            else if(i_port == 1 && l_mbapos == 0)
            {
                if(l_swizzle == 1)
                {
                    o_value = l_GL_DQ_p1_g1[i_input_index];
                }

                else if(l_swizzle == 0)
                {
                    o_value = l_GL_DQ_p1_g2[i_input_index];
                }

                else
                {
                    o_value = l_isdm_c4_dq[i_port][i_input_index];
                }

            }

            else if(i_port == 0 && l_mbapos == 1)
            {
                if(l_swizzle == 1 || l_swizzle == 0)
                {
                    o_value = l_GL_DQ_p2[i_input_index];
                }
                else
                {
                    o_value = l_isdm_c4_dq[i_port][i_input_index];
                }
            }

            else
            {
                if(l_swizzle == 1 || l_swizzle == 0)
                {
                    o_value = l_GL_DQ_p3[i_input_index];
                }
                else
                {
                    o_value = l_isdm_c4_dq[i_port][i_input_index];
                }

            }


        }


        else if(i_input_type_e == ISDIMM_DQS)
        {

            if(i_port == 0 && l_mbapos == 0)
            {
                if(l_swizzle == 1)
                {
                    o_value = l_GL_DQS_p0_g1[i_input_index];
                }
                else if(l_swizzle == 0)
                {
                    o_value = l_GL_DQS_p0_g2[i_input_index];
                }
                else
                {
                    o_value = l_isdm_c4_dqs[i_port][i_input_index];
                }

            }
            else if(i_port == 1 && l_mbapos == 0)
            {
                if(l_swizzle == 1)
                {
                    o_value = l_GL_DQS_p1_g1[i_input_index];
                }
                else if(l_swizzle == 0)
                {
                    o_value = l_GL_DQS_p1_g2[i_input_index];
                }
                else
                {
                    o_value = l_isdm_c4_dqs[i_port][i_input_index];
                }

            }

            else if(i_port == 0 && l_mbapos == 1)
            {
                if(l_swizzle == 1 || l_swizzle == 0)
                {
                    o_value = l_GL_DQS_p2[i_input_index];
                }
                else
                {
                    o_value = l_isdm_c4_dqs[i_port][i_input_index];
                }
            }
            else
            {
                if(l_swizzle == 1 || l_swizzle == 0)
                {
                    o_value = l_GL_DQS_p3[i_input_index];
                }

                else
                {
                    o_value = l_isdm_c4_dqs[i_port][i_input_index];
                }

            }


        }
        else if(i_input_type_e == CDIMM_DQS)
        {
            o_value = i_input_index;
        }

        else if(i_input_type_e == CDIMM_DQ)
        {
            o_value = i_input_index;
        }

        else
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_ROSETTA_MAP_INVALID_INPUT().
                        set_MBA_TARGET(i_target_mba).
                        set_PORT_PARAM(i_port).
                        set_TYPE_PARAM(i_input_type_e).
                        set_INDEX_PARAM(i_input_index),
                        "Wrong input type specified (%d)", i_input_type_e);

        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///@function get_address()
    ///@brief This function returns address,start bit and bit length for RD_DQ, WR_DQ, RD_DQS, WR_DQS
    ///@param[in] Target MBA=i_target_mba
    ///@param[in] i_port_u8=0 or 1
    ///@param[in] i_rank_pair=0 or 1 or 2 or 3
    ///@param[in] i_input_type_e=RD_DQ or RD_DQS or WR_DQ or WR_DQS
    ///@param[in] i_block=0 or 1 or 2 or 3 or 4
    ///@param[in] i_lane=0-15
    ///@param[out] scom address=o_scom_address_64
    ///@param[out] start bit=o_start_bit
    ///@param[out] bit length=o_len
    ///@return fapi2::ReturnCode
    fapi2::ReturnCode get_address(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                  const uint8_t i_port,
                                  const uint8_t i_rank_pair,
                                  const ip_type_t i_input_type_e,
                                  const uint8_t i_block,
                                  uint8_t i_lane,
                                  uint64_t& o_scom_address_64,
                                  uint8_t& o_start_bit,
                                  uint8_t& o_len)
    {
        uint64_t l_scom_address_64 = 0x0ull;
        uint64_t l_temp = 0x0ull;
        uint8_t l_mbapos;
        uint8_t l_lane = 0;
        const uint64_t l_port01_st = 0x8000000000000000ull;
        const uint64_t l_port23_st = 0x8001000000000000ull;
        const uint64_t l_port01_adr_st = 0x8000400000000000ull;
        const uint64_t l_port23_adr_st = 0x8001400000000000ull;
        const uint32_t l_port01_en = 0x0301143f;
        const uint64_t l_rd_port01_en = 0x040301143full;
        const uint64_t l_sys_clk_en = 0x730301143full;
        const uint64_t l_wr_clk_en = 0x740301143full;
        const uint64_t l_adr02_st = 0x8000400000000000ull;
        const uint64_t l_adr13_st = 0x8001400000000000ull;
        const uint64_t l_dqs_gate_en = 0x000000130301143full;
        const uint64_t l_dqsclk_en = 0x090301143full;
        const uint64_t l_data_ds_en = 0x7c0301143full;
        uint8_t l_tmp = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_mba, l_mbapos));

        if(i_input_type_e == WR_DQ_t || i_input_type_e == RAW_WR_DQ || i_input_type_e == RAW_CDIMM_WR_DQ_t )
        {
            if(i_lane > 7)
            {
                l_scom_address_64 = 0x00000040;
                l_scom_address_64 = l_scom_address_64 << 32;
                l_temp |= (i_lane - 8);
            }

            else
            {
                l_scom_address_64 |= 0x00000038;
                l_scom_address_64 = l_scom_address_64 << 32;
                l_temp |= i_lane;
            }

            l_temp |= (i_block * 4) << 8;
            l_temp |= i_rank_pair << 8;
            l_temp = l_temp << 32;

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_port01_st | l_temp | l_port01_en;
            }
            else
            {
                l_scom_address_64 |= l_port23_st | l_temp | l_port01_en;
            }

            o_scom_address_64 = l_scom_address_64;
            o_start_bit = 48;
            o_len = 10;

        }

        else if(i_input_type_e == RD_DQ_t || i_input_type_e == RAW_RD_DQ || i_input_type_e == RAW_CDIMM_RD_DQ_t)
        {
            l_scom_address_64 |= 0x00000050;
            l_scom_address_64 = l_scom_address_64 << 32;
            l_lane = i_lane / 2;
            l_temp |= l_lane;
            l_temp |= (i_block * 4) << 8;
            l_temp |= i_rank_pair << 8;
            l_temp = l_temp << 32;

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_port01_st | l_temp | l_port01_en;
            }
            else
            {
                l_scom_address_64 |= l_port23_st | l_temp | l_port01_en;
            }

            if((i_lane % 2) == 0)
            {
                o_start_bit = 48;
                o_len = 7;
            }
            else
            {
                o_start_bit = 56;
                o_len = 7;
            }


            o_scom_address_64 = l_scom_address_64;

        }

        else if(i_input_type_e == COMMAND_t || i_input_type_e == CLOCK_t ||  i_input_type_e == CONTROL_t
                ||  i_input_type_e == ADDRESS_t )
        {
            l_tmp |= 4;
            l_lane = i_lane / 2;
            l_temp = l_lane + l_tmp;
            l_temp |= (i_block * 4) << 8;
            l_temp = l_temp << 32;

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_port01_adr_st | l_temp | l_port01_en;
            }
            else
            {
                l_scom_address_64 |= l_port23_adr_st | l_temp | l_port01_en;
            }

            if((i_lane % 2) == 0)
            {
                o_start_bit = 49;
                o_len = 7;
            }
            else
            {
                o_start_bit = 57;
                o_len = 7;
            }


            o_scom_address_64 = l_scom_address_64;

        }


        else if(i_input_type_e == WR_DQS_t  || i_input_type_e == RAW_WR_DQS || i_input_type_e == RAW_CDIMM_WR_DQS_t)
        {

            if(i_input_type_e == RAW_WR_DQS)
            {
                if(i_lane == 0)
                {
                    i_lane = 16;
                }
                else if(i_lane == 1)
                {
                    i_lane = 18;
                }
                else if(i_lane == 2)
                {
                    i_lane = 20;
                }
                else
                {
                    i_lane = 22;
                }
            }

            if(i_lane == 16)
            {
                l_scom_address_64 |= 0x00000048;
            }
            else if(i_lane == 18)
            {
                l_scom_address_64 |= 0x0000004a;
            }
            else if(i_lane == 20)
            {
                l_scom_address_64 |= 0x0000004c;
            }
            else
            {
                l_scom_address_64 |= 0x0000004e;
            }

            l_scom_address_64 = l_scom_address_64 << 32;
            l_temp |= (i_block * 4) << 8;
            l_temp |= i_rank_pair << 8;
            l_temp = l_temp << 32;

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_port01_st | l_temp | l_port01_en;
            }
            else
            {
                l_scom_address_64 |= l_port23_st | l_temp | l_port01_en;
            }

            o_start_bit = 48;
            o_len = 10;
            o_scom_address_64 = l_scom_address_64;

        }

        else if(i_input_type_e == DATA_DISABLE_t)
        {
            l_temp |= (i_block * 4) << 8;
            l_temp |= i_rank_pair << 8;
            l_temp = l_temp << 32;

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_port01_st | l_temp | l_data_ds_en;
            }
            else
            {
                l_scom_address_64 |= l_port23_st | l_temp | l_data_ds_en;
            }

            o_start_bit = 48;
            o_len = 16;
            o_scom_address_64 = l_scom_address_64;
        }

        else if(i_input_type_e == RD_CLK_t)
        {
            l_temp |= (i_block * 4) << 8;
            l_temp |= i_rank_pair << 8;
            l_temp = l_temp << 32;

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_port01_st | l_temp | l_rd_port01_en;
            }
            else
            {
                l_scom_address_64 |= l_port23_st | l_temp | l_rd_port01_en;
            }


            o_start_bit = 0;
            o_len = 0;
            o_scom_address_64 = l_scom_address_64;

        }

        else if(i_input_type_e == RD_DQS_t || i_input_type_e == RAW_RD_DQS || i_input_type_e == RAW_CDIMM_RD_DQS_t)
        {

            if(i_input_type_e == RAW_RD_DQS)
            {
                if(i_lane == 0)
                {
                    i_lane = 16;
                }
                else if(i_lane == 1)
                {
                    i_lane = 18;
                }
                else if(i_lane == 2)
                {
                    i_lane = 20;
                }
                else
                {
                    i_lane = 22;
                }
            }

            if(i_lane == 16)
            {
                l_scom_address_64 |= 0x00000030;
                o_start_bit = 49;
            }
            else if(i_lane == 18)
            {
                l_scom_address_64 |= 0x00000030;
                o_start_bit = 57;
            }
            else if(i_lane == 20)
            {
                l_scom_address_64 |= 0x00000031;
                o_start_bit = 49;
            }
            else
            {
                l_scom_address_64 |= 0x00000031;
                o_start_bit = 57;
            }

            l_scom_address_64 = l_scom_address_64 << 32;
            l_temp |= (i_block * 4) << 8;
            l_temp |= i_rank_pair << 8;
            l_temp = l_temp << 32;

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_port01_st | l_temp | l_port01_en;
            }
            else
            {
                l_scom_address_64 |= l_port23_st | l_temp | l_port01_en;
            }


            o_len = 7;
            o_scom_address_64 = l_scom_address_64;

        }

        else if(i_input_type_e == RDCLK_t || i_input_type_e == RAW_RDCLK)
        {
            if(i_input_type_e == RAW_RDCLK)
            {
                if(i_lane == 0)
                {
                    i_lane = 16;
                }
                else if(i_lane == 1)
                {
                    i_lane = 18;
                }
                else if(i_lane == 2)
                {
                    i_lane = 20;
                }
                else
                {
                    i_lane = 22;
                }
            }

            if(i_lane == 16)
            {
                o_start_bit = 50;
            }
            else if(i_lane == 18)
            {
                o_start_bit = 54;
            }
            else if(i_lane == 20)
            {
                o_start_bit = 58;
            }
            else
            {
                o_start_bit = 62;
            }

            l_temp |= (i_block * 4) << 8;
            l_temp |= i_rank_pair << 8;
            l_temp = l_temp << 32;

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_port01_st | l_temp | l_dqsclk_en;
            }
            else
            {
                l_scom_address_64 |= l_port23_st | l_temp | l_dqsclk_en;
            }

            o_len = 2;
            o_scom_address_64 = l_scom_address_64;

        }

        else if(i_input_type_e == DQSCLK_t || i_input_type_e == RAW_DQSCLK || i_input_type_e == RAW_CDIMM_DQSCLK_t)
        {
            if(i_input_type_e == RAW_DQSCLK)
            {
                if(i_lane == 0)
                {
                    i_lane = 16;
                }
                else if(i_lane == 1)
                {
                    i_lane = 18;
                }
                else if(i_lane == 2)
                {
                    i_lane = 20;
                }
                else
                {
                    i_lane = 22;
                }
            }

            if(i_lane == 16)
            {
                o_start_bit = 48;
            }
            else if(i_lane == 18)
            {
                o_start_bit = 52;
            }
            else if(i_lane == 20)
            {
                o_start_bit = 56;
            }
            else
            {
                o_start_bit = 60;
            }

            l_temp |= (i_block * 4) << 8;
            l_temp |= i_rank_pair << 8;
            l_temp = l_temp << 32;

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_port01_st | l_temp | l_dqsclk_en;
            }
            else
            {
                l_scom_address_64 |= l_port23_st | l_temp | l_dqsclk_en;
            }

            o_len = 2;
            o_scom_address_64 = l_scom_address_64;

        }


        else if(i_input_type_e == DQS_ALIGN_t || i_input_type_e == RAW_DQS_ALIGN  || i_input_type_e == RAW_CDIMM_DQS_ALIGN_t)
        {

            if(i_input_type_e == RAW_DQS_ALIGN)
            {
                if(i_lane == 0)
                {
                    i_lane = 16;
                }
                else if(i_lane == 1)
                {
                    i_lane = 18;
                }
                else if(i_lane == 2)
                {
                    i_lane = 20;
                }
                else
                {
                    i_lane = 22;
                }
            }

            if(i_lane == 16)
            {
                l_scom_address_64 |= 0x0000005c;
                o_start_bit = 49;
            }
            else if(i_lane == 18)
            {
                l_scom_address_64 |= 0x0000005c;
                o_start_bit = 57;
            }
            else if(i_lane == 20)
            {
                l_scom_address_64 |= 0x0000005d;
                o_start_bit = 49;
            }
            else
            {
                l_scom_address_64 |= 0x0000005d;
                o_start_bit = 57;
            }

            l_scom_address_64 = l_scom_address_64 << 32;
            l_temp |= (i_block * 4) << 8;
            l_temp |= i_rank_pair << 8;
            l_temp = l_temp << 32;

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_port01_st | l_temp | l_port01_en;
            }
            else
            {
                l_scom_address_64 |= l_port23_st | l_temp | l_port01_en;
            }


            o_len = 7;
            o_scom_address_64 = l_scom_address_64;

        }



        else if(i_input_type_e == RAW_SYS_ADDR_CLKS0S1)
        {

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                if(i_lane == 0)
                {
                    l_scom_address_64 = 0x800080340301143full;
                }
                else
                {
                    l_scom_address_64 = 0x800084340301143full;
                }
            }

            else
            {
                if(i_lane == 0)
                {
                    l_scom_address_64 = 0x800180340301143full;
                }
                else
                {
                    l_scom_address_64 = 0x800184340301143full;
                }
            }

            o_start_bit = 49;
            o_len = 7;
            o_scom_address_64 = l_scom_address_64;

        }

        else if(i_input_type_e == RAW_SYS_CLK)
        {
            l_temp |= (i_block * 4) << 8;
            l_temp = l_temp << 32;

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_port01_st | l_temp | l_sys_clk_en;
            }
            else
            {
                l_scom_address_64 |= l_port23_st | l_temp | l_sys_clk_en;
            }

            o_start_bit = 49;
            o_len = 7;
            o_scom_address_64 = l_scom_address_64;

        }

        else if(i_input_type_e == RAW_WR_CLK)
        {
            l_temp |= (i_block * 4) << 8;
            l_temp = l_temp << 32;

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_port01_st | l_temp | l_wr_clk_en;
            }
            else
            {
                l_scom_address_64 |= l_port23_st | l_temp | l_wr_clk_en;
            }

            o_start_bit = 49;
            o_len = 7;
            o_scom_address_64 = l_scom_address_64;

        }

        else if(i_input_type_e == RAW_ADDR)
        {
            l_scom_address_64 |= 0x00000004;
            l_lane = i_lane;

            if(i_lane <= 7)
            {
                i_lane = i_lane / 2;
            }
            else if(i_lane == 8 || i_lane == 9)
            {
                l_scom_address_64 = 0x00000008;
                i_lane = 0;
            }
            else if(i_lane == 10 || i_lane == 11)
            {
                l_scom_address_64 = 0x00000009;
                i_lane = 0;
            }
            else if(i_lane == 12 || i_lane == 13)
            {
                l_scom_address_64 = 0x0000000a;
                i_lane = 0;
            }
            else
            {
                l_scom_address_64 = 0x0000000b;
                i_lane = 0;
            }

            l_scom_address_64 = l_scom_address_64 << 32;
            l_temp |= i_lane;
            l_temp |= (i_block * 4) << 8;
            l_temp = l_temp << 32;

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_adr02_st | l_temp | l_port01_en;
            }
            else
            {
                l_scom_address_64 |= l_adr13_st | l_temp | l_port01_en;
            }

            if((l_lane % 2) == 0)
            {
                o_start_bit = 49;
                o_len = 7;
            }
            else
            {
                o_start_bit = 57;
                o_len = 7;
            }


            o_scom_address_64 = l_scom_address_64;

        }

        else if(i_input_type_e == RAW_DQS_GATE ||  i_input_type_e == DQS_GATE_t || i_input_type_e == RAW_CDIMM_DQS_GATE_t)
        {
            if(i_input_type_e == RAW_DQS_GATE)
            {
                l_lane = i_lane / 4;
                l_temp |= l_lane;
            }

            if(i_input_type_e == DQS_GATE_t)
            {
                l_lane = i_lane;
            }

            l_temp |= (i_block * 4) << 8;
            l_temp |= i_rank_pair << 8;
            l_temp = l_temp << 32;

            if(i_input_type_e == RAW_DQS_GATE)
            {
                if((i_lane % 4) == 0)
                {
                    o_start_bit = 49;
                    o_len = 3;
                }
                else if((i_lane % 4) == 1)
                {
                    o_start_bit = 53;
                    o_len = 3;
                }

                else if((i_lane % 4) == 2)
                {
                    o_start_bit = 57;
                    o_len = 3;
                }

                else
                {
                    o_start_bit = 61;
                    o_len = 3;
                }
            }

            else
            {
                if(l_lane == 16)
                {
                    o_start_bit = 49;
                    o_len = 3;
                }
                else if(l_lane == 18)
                {
                    o_start_bit = 53;
                    o_len = 3;
                }

                else if(l_lane == 20)
                {
                    o_start_bit = 57;
                    o_len = 3;
                }

                else
                {
                    o_start_bit = 61;
                    o_len = 3;
                }

            }

            if((i_port == 0 && l_mbapos == 0) || (i_port == 0 && l_mbapos == 1))
            {
                l_scom_address_64 |= l_port01_st | l_temp | l_dqs_gate_en;
            }
            else
            {
                l_scom_address_64 |= l_port23_st | l_temp | l_dqs_gate_en;
            }

            o_scom_address_64 = l_scom_address_64;

        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///@function mss_getrankpair()
    ///@brief This function returns rank pair and valid ranks from a given rank
    ///@param[in] Target MBA=i_target_mba
    ///@param[in] i_port_u8=0 or 1
    ///@param[in] i_rank=valid ranks
    ///@param[out] rank pair=o_rank_pair
    ///@param[out] valid ranks=o_rankpair_table[]
    ///@return fapi2::ReturnCode
    fapi2::ReturnCode mss_getrankpair(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                      const uint8_t i_port,
                                      const uint8_t i_rank,
                                      uint8_t* o_rank_pair,
                                      uint8_t o_rankpair_table[])
    {
        uint8_t l_temp_rank[2] = {0};
        uint8_t l_temp_rankpair_table[16] = {0};
        uint8_t l_i = 0;
        uint8_t l_rank_pair = 0;
        uint8_t l_j = 0;
        uint8_t l_temp_swap = 0;

        for(l_i = 0; l_i < 8; l_i++)     //populate Rank Pair Table as FF - invalid
        {
            //l_temp_rankpair_table[l_i]=255;
            o_rankpair_table[l_i] = 255;
        }

        FAPI_ASSERT( i_port < 2,
                     fapi2::CEN_MSS_ACCESS_DELAY_REG_INVALID_INPUT().
                     set_MBA_TARGET(i_target_mba).
                     set_PORT_PARAM(i_port).
                     set_RANK_PARAM(i_rank),
                     "Port shall not be greater than 1.\n");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP0, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[0] = l_temp_rank[i_port];

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP1, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[1] = l_temp_rank[i_port];

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP2, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[2] = l_temp_rank[i_port];
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP3, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[3] = l_temp_rank[i_port];

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP0, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[4] = l_temp_rank[i_port];

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP1, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[5] = l_temp_rank[i_port];
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP2, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[6] = l_temp_rank[i_port];

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP3, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[7] = l_temp_rank[i_port];

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP0, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[8] = l_temp_rank[i_port];

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP1, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[9] = l_temp_rank[i_port];

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP2, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[10] = l_temp_rank[i_port];

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP3, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[11] = l_temp_rank[i_port];

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[12] = l_temp_rank[i_port];

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[13] = l_temp_rank[i_port];

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[14] = l_temp_rank[i_port];

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3, i_target_mba, l_temp_rank));
        l_temp_rankpair_table[15] = l_temp_rank[i_port];

        for(l_i = 0; l_i < 16; l_i++)
        {
            if(l_temp_rankpair_table[l_i] == i_rank)
            {
                l_rank_pair = l_i;
                break;
            }
        }

        l_rank_pair = l_rank_pair % 4; // if index l_i is greater than 4,8,12 Secondary, Tertiary, Quaternary.


        for(l_i = 0; l_i < 15; l_i++)
        {
            for(l_j = l_i + 1; l_j < 16; l_j++)
            {
                if(l_temp_rankpair_table[l_i] > l_temp_rankpair_table[l_j])
                {
                    l_temp_swap = l_temp_rankpair_table[l_j];
                    l_temp_rankpair_table[l_j] = l_temp_rankpair_table[l_i];
                    l_temp_rankpair_table[l_i] = l_temp_swap;
                }
            }
        }

        for(l_i = 0; l_i < 8; l_i++)
        {
            if(l_temp_rankpair_table[l_i] != 255)
            {
                o_rankpair_table[l_i] = l_temp_rankpair_table[l_i];
            }
        }

        *o_rank_pair = l_rank_pair;

    fapi_try_exit:
        return fapi2::current_err;
    } //end of mss_getrankpair

    ///@function mss_c4_phy()
    ///@brief This function returns address,start bit and bit length for RD_DQ, WR_DQ, RD_DQS, WR_DQS
    ///@param[in] Target MBA=i_target_mba
    ///@param[in] i_port_u8=0 or 1
    ///@param[in] i_rank_pair=0 or 1 or 2 or 3
    ///@param[in] i_input_type_e=RD_DQ or RD_DQS or WR_DQ or WR_DQS
    ///@param[in,out] io_input_index_u8=0-79/0-71/0-8/0-19
    ///@param[in] i_verbose-extra print statements
    ///@param[in,out] phy_lane
    ///@param[in,out] phy_l_block
    ///@param[in] flag
    ///@return fapi2::ReturnCode
    fapi2::ReturnCode mss_c4_phy(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                 const uint8_t i_port,
                                 const uint8_t i_rank_pair,
                                 const input_type_t i_input_type_e,
                                 uint8_t& io_input_index,
                                 const bool i_verbose,
                                 uint8_t& phy_lane,
                                 uint8_t& phy_block,
                                 const uint8_t flag)
    {
        const uint8_t l_lane_dq[MAX_PORTS_PER_CEN][DIMM_TO_C4_DQ_ENTRIES] =
        {
            {4, 6, 5, 7, 2, 1, 3, 0, 13, 15, 12, 14, 8, 9, 11, 10, 13, 15, 12, 14, 9, 8, 11, 10, 13, 15, 12, 14, 11, 9, 10, 8, 11, 8, 9, 10, 12, 13, 14, 15, 7, 6, 5, 4, 1, 3, 2, 0, 5, 6, 4, 7, 3, 1, 2, 0, 7, 4, 5, 6, 2, 0, 3, 1, 3, 0, 1, 2, 6, 5, 4, 7, 11, 8, 9, 10, 15, 13, 12, 14},
            {9, 11, 8, 10, 13, 14, 15, 12, 10, 8, 11, 9, 12, 13, 14, 15, 1, 0, 2, 3, 4, 5, 6, 7, 9, 11, 10, 8, 15, 12, 13, 14, 5, 7, 6, 4, 1, 0, 2, 3, 0, 2, 1, 3, 5, 4, 6, 7, 0, 2, 3, 1, 4, 5, 6, 7, 12, 15, 13, 14, 11, 8, 10, 9, 5, 7, 4, 6, 3, 2, 0, 1, 14, 12, 15, 13, 9, 8, 11, 10},
            {13, 15, 12, 14, 11, 9, 10, 8, 13, 12, 14, 15, 10, 9, 11, 8, 5, 6, 7, 4, 2, 3, 0, 1, 10, 9, 8, 11, 13, 12, 15, 14, 15, 12, 13, 14, 11, 10, 9, 8, 7, 6, 4, 5, 1, 0, 3, 2, 0, 2, 1, 3, 5, 6, 4, 7, 5, 7, 6, 4, 1, 0, 2, 3, 1, 2, 3, 0, 7, 6, 5, 4, 9, 10, 8, 11, 12, 15, 14, 13},
            {4, 5, 6, 7, 0, 1, 3, 2, 12, 13, 15, 14, 8, 9, 10, 11, 10, 8, 11, 9, 12, 13, 15, 14, 3, 0, 1, 2, 4, 6, 7, 5, 9, 10, 11, 8, 14, 13, 15, 12, 7, 5, 6, 4, 3, 1, 2, 0, 5, 6, 7, 4, 1, 2, 3, 0, 14, 12, 15, 13, 8, 10, 9, 11, 0, 3, 2, 1, 6, 5, 7, 4, 10, 11, 9, 8, 12, 13, 15, 14},
        };
        const uint8_t l_dqs_dq_lane[MAX_PORTS_PER_CEN][DIMM_TO_C4_DQS_ENTRIES] =
        {
            {4, 0, 12, 8, 12, 8, 12, 8, 8, 12, 4, 0, 4, 0, 4, 0, 0, 4, 8, 12},
            {8, 12, 8, 12, 0, 4, 8, 12, 4, 0, 0, 4, 0, 4, 12, 8, 4, 0, 12, 8},
            {12, 8, 12, 8, 4, 0, 8, 12, 12, 8, 4, 0, 0, 4, 4, 0, 0, 4, 8, 12},
            {4, 0, 12, 8, 8, 12, 0, 4, 8, 12, 4, 0, 4, 0, 12, 8, 0, 4, 8, 12},
        };
        const uint8_t l_block_dq[MAX_PORTS_PER_CEN][DIMM_TO_C4_DQ_ENTRIES] =
        {
            {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2},
            {1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4},
            {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        };
        const uint8_t l_block_dqs[MAX_PORTS_PER_CEN][DIMM_TO_C4_DQS_ENTRIES] =
        {
            {2, 2, 2, 2, 0, 0, 3, 3, 4, 4, 3, 3, 4, 4, 1, 1, 0, 0, 1, 1},
            {0, 0, 3, 3, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 1, 1, 2, 2},
            {1, 1, 3, 3, 0, 0, 0, 0, 2, 2, 2, 2, 3, 3, 4, 4, 1, 1, 4, 4},
            {2, 2, 2, 2, 0, 0, 0, 0, 3, 3, 3, 3, 4, 4, 4, 4, 1, 1, 1, 1},
        };
        uint8_t l_mbapos = 0;
        uint8_t l_dram_width = 0;
        uint8_t l_lane = 0;
        uint8_t l_block = 0;
        uint8_t l_lane_dqs[4] = {0}; //Initialize to 0.  This is a numerical ID of a false lane.  Another function catches this in mss_draminit_training.
        uint8_t l_index = 0;
        uint8_t l_dq = 0;
        uint8_t l_phy_dq = 0;
        uint64_t l_scom_address_64 = 0x0ull;
        uint8_t l_start_bit = 0;
        uint8_t l_len = 0;
        ip_type_t l_input_type;
        fapi2::buffer<uint64_t> l_data_buffer_64;
        uint8_t l_dimmtype = 0;
        uint8_t l_swizzle = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_DQS_SWIZZLE_TYPE, i_target_mba, l_swizzle));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_mba, l_mbapos));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_dimmtype));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target_mba, l_dram_width));


        if(i_input_type_e == RD_DQ || i_input_type_e == WR_DQ)
        {
            if(flag == 1)
            {
                for(l_phy_dq = 0; l_phy_dq < DIMM_TO_C4_DQ_ENTRIES; l_phy_dq++)
                {
                    if(phy_block == l_block_dq[get_port(l_mbapos, i_port)][l_phy_dq])
                    {
                        if(phy_lane == l_lane_dq[get_port(l_mbapos, i_port)][l_phy_dq])
                        {
                            io_input_index = l_phy_dq;
                        }
                    }
                }
            }
            else
            {

                l_lane = l_lane_dq[get_port(l_mbapos, i_port)][io_input_index];
                l_block = l_block_dq[get_port(l_mbapos, i_port)][io_input_index];
            }

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            if(flag == 0)
            {
                phy_lane = l_lane;
                phy_block = l_block;
            }

            // out.scom_addr=l_scom_address_64;
            // out.start_bit=l_start_bit;
            // out.bit_length=l_len;
        }

        else if (i_input_type_e == WR_DQS ||  i_input_type_e == DQS_ALIGN)
        {
            l_dq = l_dqs_dq_lane[get_port(l_mbapos, i_port)][io_input_index];
            l_block = l_block_dqs[get_port(l_mbapos, i_port)][io_input_index];

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("l_dqs_dq_lane=%d", l_dq);
            }

            l_input_type = RD_CLK_t;
            FAPI_TRY(get_address(i_target_mba, i_port, i_rank_pair, l_input_type, l_block, l_lane, l_scom_address_64, l_start_bit,
                                 l_len));

            if(i_verbose)
            {
                FAPI_INF("read clock address=%llx", l_scom_address_64);
            }

            FAPI_TRY(fapi2::getScom(i_target_mba, l_scom_address_64, l_data_buffer_64));

            if(l_dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4)
            {

                if (l_data_buffer_64.getBit(48))
                {
                    l_lane_dqs[0] = 16;

                }
                else if(l_data_buffer_64.getBit(52))
                {
                    l_lane_dqs[0] = 18;

                }

                if (l_data_buffer_64.getBit(49))
                {
                    l_lane_dqs[1] = 16;

                }

                else if (l_data_buffer_64.getBit(53))
                {
                    l_lane_dqs[1] = 18;

                }

                if (l_data_buffer_64.getBit(54))
                {
                    l_lane_dqs[2] = 20;

                }
                else if (l_data_buffer_64.getBit(56))
                {
                    l_lane_dqs[2] = 22;

                }

                if (l_data_buffer_64.getBit(55))
                {
                    l_lane_dqs[3] = 20;
                }
                else if (l_data_buffer_64.getBit(57))   // else is not possible as one of them will definitely get set
                {
                    l_lane_dqs[3] = 22;

                }

                if(i_verbose)
                {
                    FAPI_INF("array is=%d and %d and %d and %d", l_lane_dqs[0], l_lane_dqs[1], l_lane_dqs[2], l_lane_dqs[3]);
                }

                if(l_dq == 0)
                {
                    l_lane = l_lane_dqs[0];
                }
                else if(l_dq == 4)
                {
                    l_lane = l_lane_dqs[1];
                }
                else if(l_dq == 8)
                {
                    l_lane = l_lane_dqs[2];
                }
                else
                {
                    l_lane = l_lane_dqs[3];
                }

                if(i_verbose)
                {
                    FAPI_INF("lane is=%d", l_lane);
                }
            }


            else
            {
                if (l_data_buffer_64.getBit(48) && l_data_buffer_64.getBit(49))
                {
                    l_lane_dqs[l_index] = 16;
                    l_index++;
                }
                else if (l_data_buffer_64.getBit(52) && l_data_buffer_64.getBit(53))
                {
                    l_lane_dqs[l_index] = 18;
                    l_index++;
                }

                if (l_data_buffer_64.getBit(54) && l_data_buffer_64.getBit(55))
                {
                    l_lane_dqs[l_index] = 20;
                    l_index++;
                }
                else if (l_data_buffer_64.getBit(56)
                         && l_data_buffer_64.getBit(57))  // else is not possible as one of them will definitely get set
                {
                    l_lane_dqs[l_index] = 22;
                    l_index++;
                }

                if(i_verbose)
                {
                    FAPI_INF("array is=%d and %d", l_lane_dqs[0], l_lane_dqs[1]);
                }

                if((l_dq == 0) || (l_dq == 4))
                {
                    l_lane = l_lane_dqs[0];
                }
                else
                {
                    l_lane = l_lane_dqs[1];
                }

                if(l_dimmtype == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
                {
                    if((io_input_index == 1) || (io_input_index == 3) || (io_input_index == 5) || (io_input_index == 7)
                       || (io_input_index == 9)
                       || (io_input_index == 11) || (io_input_index == 13) || (io_input_index == 15) || (io_input_index == 17)
                       || (io_input_index == 19))
                    {
                        if(l_lane == 16)
                        {
                            l_lane = 18;
                        }
                        else if(l_lane == 18)
                        {
                            l_lane = 16;
                        }

                        else if(l_lane == 20)
                        {
                            l_lane = 22;
                        }

                        else
                        {
                            l_lane = 20;
                        }

                    }
                }

                else
                {
                    if((i_port == 0) && (l_mbapos == 0))
                    {
                        if(l_swizzle == 1)
                        {
                            if((io_input_index == 3) || (io_input_index == 1) || (io_input_index == 4) || (io_input_index == 17)
                               || (io_input_index == 9) || (io_input_index == 11) || (io_input_index == 13) || (io_input_index == 15)
                               ||  (io_input_index == 6))
                            {
                                if(l_lane == 16)
                                {
                                    l_lane = 18;
                                }
                                else if(l_lane == 18)
                                {
                                    l_lane = 16;
                                }

                                else if(l_lane == 20)
                                {
                                    l_lane = 22;
                                }

                                else
                                {
                                    l_lane = 20;
                                }

                            }
                        }

                        else
                        {
                            if((io_input_index == 3) || (io_input_index == 1) || (io_input_index == 5) || (io_input_index == 7)
                               || (io_input_index == 9)
                               || (io_input_index == 11) || (io_input_index == 13) || (io_input_index == 15) ||  (io_input_index == 17))
                            {
                                if(l_lane == 16)
                                {
                                    l_lane = 18;
                                }
                                else if(l_lane == 18)
                                {
                                    l_lane = 16;
                                }

                                else if(l_lane == 20)
                                {
                                    l_lane = 22;
                                }

                                else
                                {
                                    l_lane = 20;
                                }
                            }

                        }
                    }

                    else if((i_port == 1) && (l_mbapos == 0))
                    {
                        if(l_swizzle == 1)
                        {
                            if((io_input_index == 2) || (io_input_index == 0) || (io_input_index == 4) || (io_input_index == 17)
                               || (io_input_index == 9) || (io_input_index == 11) || (io_input_index == 13) || (io_input_index == 15)
                               ||  (io_input_index == 7))
                            {
                                if(l_lane == 16)
                                {
                                    l_lane = 18;
                                }
                                else if(l_lane == 18)
                                {
                                    l_lane = 16;
                                }

                                else if(l_lane == 20)
                                {
                                    l_lane = 22;
                                }

                                else
                                {
                                    l_lane = 20;
                                }
                            }
                        }

                        else
                        {
                            if((io_input_index == 1) || (io_input_index == 3) || (io_input_index == 5) || (io_input_index == 7)
                               || (io_input_index == 9)
                               || (io_input_index == 11) || (io_input_index == 13) || (io_input_index == 15) ||  (io_input_index == 17))
                            {
                                if(l_lane == 16)
                                {
                                    l_lane = 18;
                                }
                                else if(l_lane == 18)
                                {
                                    l_lane = 16;
                                }

                                else if(l_lane == 20)
                                {
                                    l_lane = 22;
                                }

                                else
                                {
                                    l_lane = 20;
                                }
                            }
                        }
                    }


                    else
                    {
                        if((io_input_index == 1) || (io_input_index == 3) || (io_input_index == 5) || (io_input_index == 7)
                           || (io_input_index == 9)
                           || (io_input_index == 11) || (io_input_index == 13) || (io_input_index == 15) ||  (io_input_index == 17))
                        {
                            if(l_lane == 16)
                            {
                                l_lane = 18;
                            }
                            else if(l_lane == 18)
                            {
                                l_lane = 16;
                            }

                            else if(l_lane == 20)
                            {
                                l_lane = 22;
                            }

                            else
                            {
                                l_lane = 20;
                            }

                        }
                    }



                }

                if(i_verbose)
                {
                    FAPI_INF("lane is=%d", l_lane);
                }
            }

            if(flag == 0)
            {
                phy_lane = l_lane;
                phy_block = l_block;
            }
        }
        else if (i_input_type_e == RD_DQS || i_input_type_e == DQS_GATE || i_input_type_e == RDCLK || i_input_type_e == DQSCLK)
        {


            l_dq = l_dqs_dq_lane[get_port(l_mbapos, i_port)][io_input_index];
            l_block = l_block_dqs[get_port(l_mbapos, i_port)][io_input_index];

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("l_dqs_dq_lane=%d", l_dq);
            }

            if(l_dq == 0)
            {
                l_lane = 16;
            }

            else if(l_dq == 4)
            {
                l_lane = 18;
            }

            else if (l_dq == 8)
            {
                l_lane = 20;
            }

            else
            {
                l_lane = 22;
            }

            //FAPI_INF("here");

            if (i_input_type_e == DQS_GATE)
            {
                l_input_type = DQS_GATE_t;
            }

            else if(i_input_type_e == RDCLK)
            {
                l_input_type = RDCLK_t;
            }

            else if(i_input_type_e == RD_DQS)
            {
                l_input_type = RD_DQS_t;
            }

            else
            {
                l_input_type = DQSCLK_t;
            }

            if(i_verbose)
            {
                FAPI_INF("lane is=%d", l_lane);
            }

            if(flag == 0)
            {
                phy_lane = l_lane;
                phy_block = l_block;
            }
        }

        else
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_C4_PHY_INVALID_INPUT().
                        set_TYPE_PARAM(i_input_type_e),
                        "Wrong input type specified (%d)", i_input_type_e);
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
    ///@brief Reads or Writes delay values
    ///@param[in] i_target_mba     Reference to centaur.mba target
    ///@param[in] i_access_type_e  Access type (READ or WRITE)
    ///@param[in] i_port_u8        Port number
    ///@param[in] i_rank_u8        Rank number
    ///@param[in] i_input_type_e   Input type (from input_type_t)
    ///@param[in] i_input_index_u8 Input index
    ///@param[in] i_verbose        1 = Verbose tracing
    ///@param[io] io_value_u32     READ=input, WRITE=output
    ///@return ReturnCode
    fapi2::ReturnCode mss_access_delay_reg_schmoo(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
            const access_type_t i_access_type_e,
            const uint8_t i_port_u8,
            const uint8_t i_rank_u8,
            const input_type_t i_input_type_e,
            const uint8_t i_input_index_u8,
            const bool i_verbose,
            uint16_t& io_value_u16)
    {
        uint8_t l_val = 0;
        uint8_t l_dram_width = 0;
        scom_location l_out;
        uint64_t l_scom_add = 0x0ull;
        uint32_t l_sbit = 0;
        uint32_t l_len = 0;
        uint32_t l_value_u32 = 0;
        fapi2::buffer<uint64_t> l_data_buffer_64;
        fapi2::variable_buffer l_data_buffer_32(32);
        fapi2::variable_buffer out(16);
        uint32_t l_output = 0;
        uint32_t l_start = 0;
        uint8_t l_rank_pair = 9;
        uint8_t l_rankpair_table[MAX_RANKS_PER_PORT] = {255};
        uint8_t l_dimmtype = 0;
        uint8_t l_block = 0;
        uint8_t l_lane = 0;
        uint8_t l_start_bit = 0;
        uint8_t l_len8 = 0;
        input_type l_type;
        uint8_t l_mbapos = 0;
        uint8_t l_adr = 0;
        const uint8_t l_addr_lane[MAX_PORTS_PER_CEN][MAX_ADDR] =
        {
            {1, 5, 3, 7, 10, 6, 4, 10, 13, 12, 9, 9, 0, 0, 6, 4, 1, 4, 8}, //P0
            {7, 10, 3, 6, 8, 12, 6, 1, 5, 8, 2, 0, 13, 4, 5, 9, 6, 11, 9}, //P1
            {8, 0, 7, 1, 12, 10, 1, 5, 9, 5, 13, 5, 4, 2, 4, 9, 10, 9, 0}, //P2
            {6, 2, 9, 9, 2, 3, 4, 10, 0, 5, 1, 5, 4, 1, 8, 11, 5, 12, 1}, //P3
        };
        const uint8_t l_addr_adr[MAX_PORTS_PER_CEN][MAX_ADDR] =
        {
            {2, 1, 1, 3, 1, 3, 1, 3, 3, 3, 2, 3, 2, 3, 1, 0, 3, 3, 3},
            {2, 1, 2, 2, 1, 3, 1, 1, 1, 3, 1, 3, 2, 3, 3, 0, 0, 1, 3},
            {2, 2, 3, 0, 3, 1, 2, 0, 1, 3, 2, 1, 0, 2, 3, 3, 3, 2, 1},
            {3, 0, 2, 3, 2, 0, 3, 3, 1, 2, 2, 1, 0, 1, 3, 3, 0, 3, 0},
        };

        const uint8_t l_cmd_lane[MAX_PORTS_PER_CEN][MAX_CMD] =
        {
            {2, 11, 5},
            {2, 10, 10},
            {3, 11, 3},
            {7, 10, 7},
        };

        const uint8_t l_cmd_adr[MAX_PORTS_PER_CEN][MAX_CMD] =
        {
            {3, 1, 3},
            {2, 3, 2},
            {1, 3, 0},
            {1, 1, 3},
        };

        const uint8_t l_cnt_lane[MAX_PORTS_PER_CEN][MAX_CNT] =
        {
            {0, 7, 3, 1, 7, 8, 8, 3, 8, 6, 7, 2, 2, 0, 9, 1, 3, 6, 9, 2},
            {5, 4, 0, 5, 11, 9, 10, 7, 1, 11, 0, 4, 12, 3, 6, 8, 1, 4, 7, 7},
            {0, 4, 7, 13, 11, 5, 12, 2, 3, 6, 11, 6, 7, 1, 10, 8, 8, 2, 4, 1},
            {0, 11, 9, 8, 4, 7, 0, 3, 8, 6, 13, 8, 7, 0, 6, 6, 1, 2, 9, 5},
        };
        const uint8_t l_cnt_adr[MAX_PORTS_PER_CEN][MAX_CNT] =
        {
            {1, 0, 3, 0, 2, 2, 1, 2, 0, 0, 1, 2, 0, 0, 1, 1, 0, 2, 0, 1},
            {2, 1, 2, 0, 2, 1, 0, 1, 3, 0, 1, 0, 2, 1, 3, 0, 2, 2, 3, 0},
            {0, 1, 1, 3, 1, 2, 2, 0, 2, 2, 0, 1, 2, 1, 0, 3, 1, 1, 2, 3},
            {2, 1, 0, 2, 1, 0, 3, 2, 0, 1, 3, 1, 2, 0, 0, 2, 3, 1, 1, 3},
        };

        const uint8_t l_clk_lane[MAX_PORTS_PER_CEN][MAX_CLK] =
        {
            {10, 11, 11, 10, 4, 5, 13, 12},
            {3, 2, 8, 9, 1, 0, 3, 2},
            {11, 10, 6, 7, 2, 3, 8, 9},
            {3, 2, 13, 12, 10, 11, 11, 10},
        };
        const uint8_t l_clk_adr[MAX_PORTS_PER_CEN][MAX_CLK] =
        {
            {0, 0, 2, 2, 2, 2, 2, 2},
            {3, 3, 2, 2, 0, 0, 0, 0},
            {2, 2, 0, 0, 3, 3, 0, 0},
            {3, 3, 2, 2, 0, 0, 2, 2},
        };


        FAPI_TRY(mss_getrankpair(i_target_mba, i_port_u8, i_rank_u8, &l_rank_pair, l_rankpair_table));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba, l_dimmtype));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target_mba, l_dram_width));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target_mba, l_mbapos));

        if(i_verbose)
        {
            FAPI_INF("dimm type=%d", l_dimmtype);
            FAPI_INF("rank pair=%d", l_rank_pair);
        }

        FAPI_ASSERT(i_port_u8 < MAX_PORTS_PER_MBA,
                    fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                    "Wrong port specified (%d)", i_port_u8);

        FAPI_ASSERT(l_mbapos < MAX_MBA_PER_CEN,
                    fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_BAD_MBA_POS(),
                    "Bad position from ATTR_CHIP_UNIT_POS (%d)", l_mbapos);

        FAPI_ASSERT(l_dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4 ||
                    l_dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X8,
                    fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_BAD_DRAM_WIDTH().
                    set_DRAM_WIDTH(l_dram_width),
                    "Bad dram width from ATTR_EFF_DRAM_WIDTH (%d)", l_dram_width);

        if(i_verbose)
        {
            FAPI_INF("dram width=%d", l_dram_width);
        }


        if(i_input_type_e == RD_DQ || i_input_type_e == WR_DQ)
        {

            if(l_dimmtype == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
            {
                FAPI_ASSERT(i_input_index_u8 < CDIMM_MAX_DQ_80,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "CDIMM_DQ: Wrong input index specified (%d, max %d)" ,
                            i_input_index_u8, CDIMM_MAX_DQ_80);

                l_type = CDIMM_DQ;
            }
            else
            {

                FAPI_ASSERT(i_input_index_u8 < ISDIMM_MAX_DQ_72,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "ISDIMM_DQ: Wrong input index specified (%d, max %d)",
                            i_input_index_u8, ISDIMM_MAX_DQ_72);

                l_type = ISDIMM_DQ;
            }

            FAPI_TRY(rosetta_map(i_target_mba, i_port_u8, l_type, i_input_index_u8, i_verbose, l_val));

            if(i_verbose)
            {
                FAPI_INF("C4 value is=%d", l_val);
            }

            FAPI_TRY(cross_coupled(i_target_mba, i_port_u8, l_rank_pair, i_input_type_e, l_val, i_verbose, l_out));

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_out.scom_addr);
                FAPI_INF("start bit=%d", l_out.start_bit);
                FAPI_INF("length=%d", l_out.bit_length);
            }

            l_scom_add = l_out.scom_addr;
            l_sbit = l_out.start_bit;
            l_len = l_out.bit_length;

        }

        else if(i_input_type_e == ADDRESS)
        {
            FAPI_ASSERT(i_input_index_u8 < MAX_ADDR && (get_port(l_mbapos, i_port_u8) < 4),
                        fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                        "Wrong input index specified (%d)", i_input_index_u8);

            l_lane = l_addr_lane[get_port(l_mbapos, i_port_u8)][i_input_index_u8];
            l_adr = l_addr_adr[get_port(l_mbapos, i_port_u8)][i_input_index_u8];

            ip_type_t l_input = ADDRESS_t;

            if(i_verbose)
            {
                FAPI_INF("ADR=%d", l_adr);
                FAPI_INF("lane=%d", l_lane);
            }

            l_block = l_adr;
            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == DATA_DISABLE)
        {
            FAPI_ASSERT(i_input_index_u8 < MAX_DATA_DISABLE,
                        fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                        "Wrong input index specified (%d)", i_input_index_u8);

            l_block = i_input_index_u8;

            ip_type_t l_input = DATA_DISABLE_t;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
            }

            l_lane = 0;
            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }


        else if(i_input_type_e == COMMAND)
        {
            FAPI_ASSERT(i_input_index_u8 < MAX_CMD && (get_port(l_mbapos, i_port_u8)) < 4, // 3 values for command
                        fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                        "Wrong input index specified (%d)", i_input_index_u8);

            l_lane = l_cmd_lane[get_port(l_mbapos, i_port_u8)][i_input_index_u8];
            l_adr = l_cmd_adr[get_port(l_mbapos, i_port_u8)][i_input_index_u8];

            ip_type_t l_input = COMMAND_t;

            if(i_verbose)
            {
                FAPI_INF("ADR=%d", l_adr);
                FAPI_INF("lane=%d", l_lane);
            }

            l_block = l_adr;
            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == CONTROL)
        {
            FAPI_ASSERT(i_input_index_u8 < MAX_CNT && (get_port(l_mbapos, i_port_u8)) < 4,
                        fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                        "Wrong input index specified (%d)", i_input_index_u8);

            l_lane = l_cnt_lane[get_port(l_mbapos, i_port_u8)][i_input_index_u8];
            l_adr = l_cnt_adr[get_port(l_mbapos, i_port_u8)][i_input_index_u8];

            ip_type_t l_input = CONTROL_t;

            if(i_verbose)
            {
                FAPI_INF("ADR=%d", l_adr);
                FAPI_INF("lane=%d", l_lane);
            }

            l_block = l_adr;
            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == CLOCK)
        {
            FAPI_ASSERT(i_input_index_u8 < MAX_CLK && (get_port(l_mbapos, i_port_u8)) < 4,
                        fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                        "Wrong input index specified (%d)", i_input_index_u8);

            l_lane = l_clk_lane[get_port(l_mbapos, i_port_u8)][i_input_index_u8];
            l_adr = l_clk_adr[get_port(l_mbapos, i_port_u8)][i_input_index_u8];

            ip_type_t l_input = CLOCK_t;

            if(i_verbose)
            {
                FAPI_INF("ADR=%d", l_adr);
                FAPI_INF("lane=%d", l_lane);
            }

            l_block = l_adr;
            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }


        else if (i_input_type_e == RD_DQS || i_input_type_e == WR_DQS || i_input_type_e == DQS_ALIGN
                 ||  i_input_type_e == DQS_GATE || i_input_type_e == RDCLK || i_input_type_e == DQSCLK)
        {

            if(l_dimmtype == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES)
            {
                l_type = CDIMM_DQS;
            }
            else
            {
                l_type = ISDIMM_DQS;
            }

            FAPI_TRY(rosetta_map(i_target_mba, i_port_u8, l_type, i_input_index_u8, i_verbose, l_val));

            if(i_verbose)
            {
                FAPI_INF("C4 value is=%d", l_val);
            }

            FAPI_TRY(cross_coupled(i_target_mba, i_port_u8, l_rank_pair, i_input_type_e, l_val, i_verbose, l_out));

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_out.scom_addr);
                FAPI_INF("start bit=%d", l_out.start_bit);
                FAPI_INF("length=%d", l_out.bit_length);
            }

            l_scom_add = l_out.scom_addr;
            l_sbit = l_out.start_bit;
            l_len = l_out.bit_length;

        }


        else if(i_input_type_e == RAW_RDCLK_0 || i_input_type_e == RAW_RDCLK_1 || i_input_type_e == RAW_RDCLK_2
                || i_input_type_e == RAW_RDCLK_3 || i_input_type_e == RAW_RDCLK_4)
        {
            if(i_input_type_e == RAW_RDCLK_0)
            {
                l_block = 0;
            }

            else if(i_input_type_e == RAW_RDCLK_1)
            {
                l_block = 1;
            }

            else if(i_input_type_e == RAW_RDCLK_2)
            {
                l_block = 2;
            }

            else if(i_input_type_e == RAW_RDCLK_3)
            {
                l_block = 3;
            }

            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 3) // 4 delay values for RDCLK
            {
                l_lane = i_input_index_u8;
            }

            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_RDCLK;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_DQSCLK_0 || i_input_type_e == RAW_DQSCLK_1 || i_input_type_e == RAW_DQSCLK_2
                || i_input_type_e == RAW_DQSCLK_3 || i_input_type_e == RAW_DQSCLK_4)
        {
            if(i_input_type_e == RAW_DQSCLK_0)
            {
                l_block = 0;
            }

            else if(i_input_type_e == RAW_DQSCLK_1)
            {
                l_block = 1;
            }

            else if(i_input_type_e == RAW_DQSCLK_2)
            {
                l_block = 2;
            }

            else if(i_input_type_e == RAW_DQSCLK_3)
            {
                l_block = 3;
            }

            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 3) // 4 delay values for DQSCLK
            {
                l_lane = i_input_index_u8;
            }

            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_DQSCLK;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }


        else if(i_input_type_e == RAW_WR_DQ_0 || i_input_type_e == RAW_WR_DQ_1 || i_input_type_e == RAW_WR_DQ_2
                || i_input_type_e == RAW_WR_DQ_3 || i_input_type_e == RAW_WR_DQ_4)
        {
            if(i_input_type_e == RAW_WR_DQ_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_WR_DQ_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_WR_DQ_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_WR_DQ_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 15) // 16 Write delay values for DQ bits
            {
                l_lane = i_input_index_u8;
            }

            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_WR_DQ;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_RD_DQ_0 || i_input_type_e == RAW_RD_DQ_1 || i_input_type_e == RAW_RD_DQ_2
                || i_input_type_e == RAW_RD_DQ_3 || i_input_type_e == RAW_RD_DQ_4)
        {
            if(i_input_type_e == RAW_RD_DQ_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_RD_DQ_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_RD_DQ_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_RD_DQ_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 15) // 16 read delay values for DQ bits
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_RD_DQ;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_RD_DQS_0 || i_input_type_e == RAW_RD_DQS_1 || i_input_type_e == RAW_RD_DQS_2
                || i_input_type_e == RAW_RD_DQS_3 || i_input_type_e == RAW_RD_DQS_4)
        {
            if(i_input_type_e == RAW_RD_DQS_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_RD_DQS_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_RD_DQS_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_RD_DQS_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 3) // 4 Read DQS delay values
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "Wrong input index specified (%d)", i_input_index_u8);
            }

            ip_type_t l_input = RAW_RD_DQS;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_DQS_ALIGN_0 || i_input_type_e == RAW_DQS_ALIGN_1 || i_input_type_e == RAW_DQS_ALIGN_2
                || i_input_type_e == RAW_DQS_ALIGN_3 || i_input_type_e == RAW_DQS_ALIGN_4)
        {
            if(i_input_type_e == RAW_DQS_ALIGN_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_DQS_ALIGN_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_DQS_ALIGN_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_DQS_ALIGN_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 3)   // 4 DQS alignment delay values
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_DQS_ALIGN;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }


        else if(i_input_type_e == RAW_WR_DQS_0 || i_input_type_e == RAW_WR_DQS_1 || i_input_type_e == RAW_WR_DQS_2
                || i_input_type_e == RAW_WR_DQS_3 || i_input_type_e == RAW_WR_DQS_4)
        {
            if(i_input_type_e == RAW_WR_DQS_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_WR_DQS_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_WR_DQS_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_WR_DQS_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 3)    // 4 Write DQS delay values
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "Wrong input index specified (%d)", i_input_index_u8);
            }

            ip_type_t l_input = RAW_WR_DQS;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }
        else if(i_input_type_e == RAW_SYS_CLK_0 || i_input_type_e == RAW_SYS_CLK_1 || i_input_type_e == RAW_SYS_CLK_2
                || i_input_type_e == RAW_SYS_CLK_3 || i_input_type_e == RAW_SYS_CLK_4)
        {
            if(i_input_type_e == RAW_SYS_CLK_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_SYS_CLK_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_SYS_CLK_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_SYS_CLK_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 == 0) // 1 system clock delay value
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "Wrong input index specified (%d)", i_input_index_u8);
            }

            ip_type_t l_input = RAW_SYS_CLK;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_SYS_ADDR_CLK)
        {
            if(i_input_index_u8 <= 1) // 1 system address clock delay value
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_SYS_ADDR_CLKS0S1;

            if(i_verbose)
            {
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }


        else if(i_input_type_e == RAW_WR_CLK_0 || i_input_type_e == RAW_WR_CLK_1 || i_input_type_e == RAW_WR_CLK_2
                || i_input_type_e == RAW_WR_CLK_3 || i_input_type_e == RAW_WR_CLK_4)
        {
            if(i_input_type_e == RAW_WR_CLK_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_WR_CLK_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_WR_CLK_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_WR_CLK_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 == 0)         //  1 Write clock delay value
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_WR_CLK;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_ADDR_0 || i_input_type_e == RAW_ADDR_1 || i_input_type_e == RAW_ADDR_2
                || i_input_type_e == RAW_ADDR_3)
        {
            if(i_input_type_e == RAW_ADDR_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_ADDR_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_ADDR_2)
            {
                l_block = 2;
            }
            else
            {
                l_block = 3;
            }

            if(i_input_index_u8 <= 15)    //  16 Addr delay values
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_ADDR;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else if(i_input_type_e == RAW_DQS_GATE_0 || i_input_type_e == RAW_DQS_GATE_1 || i_input_type_e == RAW_DQS_GATE_2
                || i_input_type_e == RAW_DQS_GATE_3 || i_input_type_e == RAW_DQS_GATE_4)
        {
            if(i_input_type_e == RAW_DQS_GATE_0)
            {
                l_block = 0;
            }
            else if(i_input_type_e == RAW_DQS_GATE_1)
            {
                l_block = 1;
            }
            else if(i_input_type_e == RAW_DQS_GATE_2)
            {
                l_block = 2;
            }
            else if(i_input_type_e == RAW_DQS_GATE_3)
            {
                l_block = 3;
            }
            else
            {
                l_block = 4;
            }

            if(i_input_index_u8 <= 3)   // 4 Gate Delay values
            {
                l_lane = i_input_index_u8;
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "Wrong input index specified (%d)", i_input_index_u8);

            }

            ip_type_t l_input = RAW_DQS_GATE;

            if(i_verbose)
            {
                FAPI_INF("l_block=%d", l_block);
                FAPI_INF("lane=%d", l_lane);
            }

            FAPI_TRY(get_address(i_target_mba, i_port_u8, l_rank_pair, l_input, l_block, l_lane, l_scom_add, l_start_bit, l_len8));
            l_sbit = l_start_bit;
            l_len = l_len8;

            if(i_verbose)
            {
                FAPI_INF("scom_address=%llX", l_scom_add);
                FAPI_INF("start bit=%d", l_start_bit);
                FAPI_INF("length=%d", l_len8);
            }
        }

        else
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                        "Wrong input index specified (%d)",
                        i_input_index_u8);
        }

        if(i_access_type_e == READ)
        {
            FAPI_TRY(fapi2::getScom(i_target_mba, l_scom_add, l_data_buffer_64));
            FAPI_TRY(l_data_buffer_64.extractToRight(l_output, l_sbit, l_len), "couldn't extract");
            FAPI_TRY(l_data_buffer_32.insert(l_output, 0, 32), "couldn't insert");
            FAPI_TRY(l_data_buffer_32.extract(io_value_u16, 16, 16), "couldn't extract2");
        }

        else if(i_access_type_e == WRITE)
        {

            if(i_input_type_e == RD_DQ || i_input_type_e == RD_DQS || i_input_type_e == RAW_RD_DQ_0
               || i_input_type_e == RAW_RD_DQ_1 || i_input_type_e == RAW_RD_DQ_2 || i_input_type_e == RAW_RD_DQ_3
               || i_input_type_e == RAW_RD_DQ_4 || i_input_type_e == RAW_RD_DQS_0 || i_input_type_e == RAW_RD_DQS_1
               || i_input_type_e == RAW_RD_DQS_2 || i_input_type_e == RAW_RD_DQS_3 || i_input_type_e == RAW_RD_DQS_4
               || i_input_type_e == RAW_SYS_ADDR_CLK || i_input_type_e == RAW_SYS_CLK_0 || i_input_type_e == RAW_SYS_CLK_1
               || i_input_type_e == RAW_SYS_CLK_2 || i_input_type_e == RAW_SYS_CLK_3 || i_input_type_e == RAW_SYS_CLK_4
               || i_input_type_e == RAW_WR_CLK_0 || i_input_type_e == RAW_WR_CLK_1 || i_input_type_e == RAW_WR_CLK_2
               || i_input_type_e == RAW_WR_CLK_3 || i_input_type_e == RAW_WR_CLK_4
               || i_input_type_e == RAW_ADDR_0 || i_input_type_e == RAW_ADDR_1 || i_input_type_e == RAW_ADDR_2
               || i_input_type_e == RAW_ADDR_3 || i_input_type_e == RAW_DQS_ALIGN_0 || i_input_type_e == RAW_DQS_ALIGN_1
               || i_input_type_e == RAW_DQS_ALIGN_2 || i_input_type_e == RAW_DQS_ALIGN_3 || i_input_type_e == RAW_DQS_ALIGN_4
               || i_input_type_e == DQS_ALIGN || i_input_type_e == COMMAND || i_input_type_e == ADDRESS || i_input_type_e == CONTROL
               || i_input_type_e == CLOCK )
            {
                l_start = 25; // l_start is starting bit of delay value in the register. There are different registers and each register has a different field for delay
            }
            else if(i_input_type_e == WR_DQ || i_input_type_e == WR_DQS || i_input_type_e == RAW_WR_DQ_0
                    || i_input_type_e == RAW_WR_DQ_1 || i_input_type_e == RAW_WR_DQ_2 || i_input_type_e == RAW_WR_DQ_3
                    || i_input_type_e == RAW_WR_DQ_4 || i_input_type_e == RAW_WR_DQS_0 || i_input_type_e == RAW_WR_DQS_1
                    || i_input_type_e == RAW_WR_DQS_2 || i_input_type_e == RAW_WR_DQS_3 || i_input_type_e == RAW_WR_DQS_4 )
            {
                l_start = 22;
            }

            else if(i_input_type_e == RAW_DQS_GATE_0 || i_input_type_e == RAW_DQS_GATE_1 || i_input_type_e == RAW_DQS_GATE_2
                    || i_input_type_e == RAW_DQS_GATE_3 || i_input_type_e == RAW_DQS_GATE_4 || i_input_type_e == DQS_GATE)
            {
                l_start = 29;
            }

            else if(i_input_type_e == RAW_RDCLK_0 || i_input_type_e == RAW_RDCLK_1 || i_input_type_e == RAW_RDCLK_2
                    || i_input_type_e == RAW_RDCLK_3 || i_input_type_e == RAW_RDCLK_4 || i_input_type_e == RDCLK
                    || i_input_type_e == RAW_DQSCLK_0 || i_input_type_e == RAW_DQSCLK_1 || i_input_type_e == RAW_DQSCLK_2
                    || i_input_type_e == RAW_DQSCLK_3 || i_input_type_e == RAW_DQSCLK_4 || i_input_type_e == DQSCLK)
            {
                l_start = 30;
            }

            else if(i_input_type_e == DATA_DISABLE)
            {
                l_start = 16;
            }

            else
            {
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_ACCESS_DELAY_REG_SCHMOO_INVALID_INPUT(),
                            "Wrong input type specified (%d)", i_input_type_e);

            }

            if(i_verbose)
            {
                FAPI_INF("value given=%d", io_value_u16);
            }

            FAPI_TRY(l_data_buffer_32.insert(io_value_u16, 16, 16));
            FAPI_TRY(l_data_buffer_32.extract(l_value_u32));

            FAPI_TRY(fapi2::getScom(i_target_mba, l_scom_add, l_data_buffer_64));
            FAPI_TRY(l_data_buffer_64.insert(l_value_u32, l_sbit, l_len, l_start));
            FAPI_TRY(fapi2::putScom(i_target_mba, l_scom_add, l_data_buffer_64));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
} // extern "C"
