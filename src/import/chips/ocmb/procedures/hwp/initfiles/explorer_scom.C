/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/procedures/hwp/initfiles/explorer_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
#include "explorer_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_11 = 11;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_9 = 9;
constexpr uint64_t literal_14 = 14;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_24 = 24;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_266 = 266;
constexpr uint64_t literal_1866 = 1866;
constexpr uint64_t literal_2668 = 2668;
constexpr uint64_t literal_2934 = 2934;
constexpr uint64_t literal_12 = 12;
constexpr uint64_t literal_13 = 13;
constexpr uint64_t literal_0b1000 = 0b1000;
constexpr uint64_t literal_511 = 511;
constexpr uint64_t literal_132 = 132;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_100 = 100;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_0x02 = 0x02;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0x01 = 0x01;
constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_0x00 = 0x00;
constexpr uint64_t literal_64 = 64;
constexpr uint64_t literal_32 = 32;
constexpr uint64_t literal_16 = 16;
constexpr uint64_t literal_0b000 = 0b000;
constexpr uint64_t literal_0b100 = 0b100;
constexpr uint64_t literal_0b010 = 0b010;
constexpr uint64_t literal_0b001 = 0b001;
constexpr uint64_t literal_0b110 = 0b110;
constexpr uint64_t literal_0b011 = 0b011;
constexpr uint64_t literal_0b101 = 0b101;
constexpr uint64_t literal_0b111 = 0b111;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_0x0100 = 0x0100;
constexpr uint64_t literal_10 = 10;
constexpr uint64_t literal_15 = 15;
constexpr uint64_t literal_1024 = 1024;
constexpr uint64_t literal_0b01011 = 0b01011;
constexpr uint64_t literal_0b01100 = 0b01100;
constexpr uint64_t literal_0b01101 = 0b01101;
constexpr uint64_t literal_0b01110 = 0b01110;
constexpr uint64_t literal_0b01111 = 0b01111;
constexpr uint64_t literal_17 = 17;
constexpr uint64_t literal_18 = 18;
constexpr uint64_t literal_0b00110 = 0b00110;
constexpr uint64_t literal_0b10000 = 0b10000;
constexpr uint64_t literal_0b10001 = 0b10001;
constexpr uint64_t literal_0b10010 = 0b10010;
constexpr uint64_t literal_0b10011 = 0b10011;
constexpr uint64_t literal_0b00100 = 0b00100;
constexpr uint64_t literal_0b00001 = 0b00001;
constexpr uint64_t literal_0b00101 = 0b00101;
constexpr uint64_t literal_0b00111 = 0b00111;
constexpr uint64_t literal_0b01000 = 0b01000;
constexpr uint64_t literal_0b01001 = 0b01001;
constexpr uint64_t literal_0b01010 = 0b01010;
constexpr uint64_t literal_0b00000 = 0b00000;
constexpr uint64_t literal_0b00010 = 0b00010;
constexpr uint64_t literal_0b00011 = 0b00011;

fapi2::ReturnCode explorer_scom(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& TGT0,
                                const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT2,
                                const fapi2::Target<fapi2::TARGET_TYPE_MC>& TGT3)
{
    {
        fapi2::ATTR_IS_SIMULATION_Type l_TGT2_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT2, l_TGT2_ATTR_IS_SIMULATION));
        uint64_t l_def_IS_MICROSEMI_SIM = (l_TGT2_ATTR_IS_SIMULATION == literal_1);
        fapi2::ATTR_MEM_EXP_DFIMRL_CLK_Type l_TGT1_ATTR_MEM_EXP_DFIMRL_CLK;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EXP_DFIMRL_CLK, TGT1, l_TGT1_ATTR_MEM_EXP_DFIMRL_CLK));
        fapi2::ATTR_MEM_RDIMM_BUFFER_DELAY_Type l_TGT1_ATTR_MEM_RDIMM_BUFFER_DELAY;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_RDIMM_BUFFER_DELAY, TGT1, l_TGT1_ATTR_MEM_RDIMM_BUFFER_DELAY));
        fapi2::ATTR_MEM_EFF_DIMM_TYPE_Type l_TGT1_ATTR_MEM_EFF_DIMM_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DIMM_TYPE, TGT1, l_TGT1_ATTR_MEM_EFF_DIMM_TYPE));
        uint64_t l_def_RDIMM_TYPE = ((l_TGT1_ATTR_MEM_EFF_DIMM_TYPE[literal_0] == literal_1)
                                     || (l_TGT1_ATTR_MEM_EFF_DIMM_TYPE[literal_0] == literal_3));
        uint64_t l_def_RDIMM_Add_latency = (l_def_RDIMM_TYPE * l_TGT1_ATTR_MEM_RDIMM_BUFFER_DELAY);
        fapi2::ATTR_MEM_EFF_DRAM_CL_Type l_TGT1_ATTR_MEM_EFF_DRAM_CL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_CL, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_CL));
        uint64_t l_def_IS_IBM_SIM = literal_0;
        uint64_t l_def_IS_HW = (l_TGT2_ATTR_IS_SIMULATION == literal_0);
        fapi2::ATTR_MEM_DRAM_CWL_Type l_TGT1_ATTR_MEM_DRAM_CWL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_DRAM_CWL, TGT1, l_TGT1_ATTR_MEM_DRAM_CWL));
        fapi2::ATTR_MEM_EFF_FREQ_Type l_TGT1_ATTR_MEM_EFF_FREQ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_FREQ, TGT1, l_TGT1_ATTR_MEM_EFF_FREQ));
        uint64_t l_def_RANK_SWITCH_TCK = (literal_4 + ((l_TGT1_ATTR_MEM_EFF_FREQ - literal_1866) / literal_266));
        fapi2::ATTR_MEM_EFF_DRAM_TCCD_L_Type l_TGT1_ATTR_MEM_EFF_DRAM_TCCD_L;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TCCD_L, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TCCD_L));
        uint64_t l_def_BUS_TURNAROUND_TCK = (literal_4 + ((l_TGT1_ATTR_MEM_EFF_FREQ - literal_1866) / literal_266));
        fapi2::ATTR_MEM_EFF_DRAM_TWTR_S_Type l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_S;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TWTR_S, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_S));
        fapi2::ATTR_MEM_EFF_DRAM_TWTR_L_Type l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_L;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TWTR_L, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_L));
        fapi2::ATTR_MEM_EFF_DRAM_TFAW_Type l_TGT1_ATTR_MEM_EFF_DRAM_TFAW;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TFAW, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TFAW));
        fapi2::ATTR_MEM_EFF_DRAM_TRCD_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRCD;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRCD, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRCD));
        fapi2::ATTR_MEM_EFF_DRAM_TRP_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRP, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRP));
        fapi2::ATTR_MEM_EFF_DRAM_TRAS_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRAS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRAS, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRAS));
        fapi2::ATTR_MEM_EFF_DRAM_TWR_Type l_TGT1_ATTR_MEM_EFF_DRAM_TWR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TWR, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TWR));
        fapi2::ATTR_MEM_EFF_DRAM_TRTP_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRTP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRTP, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRTP));
        fapi2::ATTR_MEM_EFF_DRAM_TRRD_S_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRRD_S;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRRD_S, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRRD_S));
        fapi2::ATTR_MEM_EFF_DRAM_TRRD_L_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRRD_L;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRRD_L, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRRD_L));
        uint64_t l_def_MEM_EFF_FREQ_EQ_2666 = (l_TGT1_ATTR_MEM_EFF_FREQ < literal_2668);
        uint64_t l_def_MEM_EFF_FREQ_EQ_2933 = ((l_TGT1_ATTR_MEM_EFF_FREQ >= literal_2668)
                                               && (l_TGT1_ATTR_MEM_EFF_FREQ < literal_2934));
        uint64_t l_def_MEM_EFF_FREQ_EQ_3200 = (l_TGT1_ATTR_MEM_EFF_FREQ >= literal_2934);
        fapi2::ATTR_MEM_REORDER_QUEUE_SETTING_Type l_TGT0_ATTR_MEM_REORDER_QUEUE_SETTING;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_REORDER_QUEUE_SETTING, TGT0, l_TGT0_ATTR_MEM_REORDER_QUEUE_SETTING));
        uint64_t l_def_disable_fast_act = literal_1;
        fapi2::ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_Type l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM, TGT1,
                               l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM));
        uint64_t l_def_NUM_MRANKS_1 = ((l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_1] == literal_0x0) |
                                       l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_1]);
        fapi2::ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM_Type l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM, TGT1, l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM));
        uint64_t l_def_NUM_SRANKS_1 = (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] / l_def_NUM_MRANKS_1);
        uint64_t l_def_NUM_MRANKS_0 = ((l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0] == literal_0x0) |
                                       l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0]);
        uint64_t l_def_NUM_SRANKS_0 = (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] / l_def_NUM_MRANKS_0);
        fapi2::ATTR_MSS_MRW_DRAM_2N_MODE_Type l_TGT2_ATTR_MSS_MRW_DRAM_2N_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_DRAM_2N_MODE, TGT2, l_TGT2_ATTR_MSS_MRW_DRAM_2N_MODE));
        fapi2::ATTR_MEM_2N_MODE_Type l_TGT0_ATTR_MEM_2N_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_2N_MODE, TGT0, l_TGT0_ATTR_MEM_2N_MODE));
        fapi2::ATTR_MEM_MRW_IS_PLANAR_Type l_TGT0_ATTR_MEM_MRW_IS_PLANAR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_MRW_IS_PLANAR, TGT0, l_TGT0_ATTR_MEM_MRW_IS_PLANAR));
        uint64_t l_def_SLOT0_DENOMINATOR = ((l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0] == literal_0x0) |
                                            l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0]);
        uint64_t l_def_SLOT0_DRAM_STACK_HEIGHT = (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] /
                l_def_SLOT0_DENOMINATOR);
        uint64_t l_def_SLOT1_DENOMINATOR = ((l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_1] == literal_0x0) |
                                            l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_1]);
        uint64_t l_def_SLOT1_DRAM_STACK_HEIGHT = (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] /
                l_def_SLOT1_DENOMINATOR);
        fapi2::ATTR_MEM_SI_ODT_RD_Type l_TGT1_ATTR_MEM_SI_ODT_RD;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_SI_ODT_RD, TGT1, l_TGT1_ATTR_MEM_SI_ODT_RD));
        uint64_t l_def_dual_drop = ((l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0] > literal_0)
                                    && (l_TGT1_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_1] > literal_0));
        fapi2::ATTR_MEM_EFF_FOUR_RANK_MODE_Type l_TGT1_ATTR_MEM_EFF_FOUR_RANK_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_FOUR_RANK_MODE, TGT1, l_TGT1_ATTR_MEM_EFF_FOUR_RANK_MODE));
        uint64_t l_def_four_rank_mode = (l_TGT1_ATTR_MEM_EFF_FOUR_RANK_MODE[literal_0] == literal_1);
        uint64_t l_def_cs_tied = ((l_def_four_rank_mode == literal_0) && (l_def_dual_drop == literal_0));
        fapi2::ATTR_MEM_SI_ODT_WR_Type l_TGT1_ATTR_MEM_SI_ODT_WR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_SI_ODT_WR, TGT1, l_TGT1_ATTR_MEM_SI_ODT_WR));
        uint64_t l_def_NUM_RANKS = (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] +
                                    l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1]);
        uint64_t l_def_NUM_RANKS_DENOMINATOR = ((l_def_NUM_RANKS == literal_0x0) | l_def_NUM_RANKS);
        fapi2::ATTR_MEM_EFF_DRAM_TREFI_Type l_TGT1_ATTR_MEM_EFF_DRAM_TREFI;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TREFI, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TREFI));
        uint64_t l_def_REFRESH_INTERVAL = (l_TGT1_ATTR_MEM_EFF_DRAM_TREFI / (literal_8 * l_def_NUM_RANKS_DENOMINATOR));
        fapi2::ATTR_MEM_EFF_DRAM_TRFC_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRFC;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRFC, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRFC));
        fapi2::ATTR_MEM_EFF_DRAM_TRFC_DLR_Type l_TGT1_ATTR_MEM_EFF_DRAM_TRFC_DLR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_TRFC_DLR, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_TRFC_DLR));
        uint64_t l_def_REFR_CHECK_INTERVAL = (((l_def_REFRESH_INTERVAL * l_def_NUM_RANKS) * literal_6) / literal_5);
        fapi2::ATTR_MSS_OCMB_HALF_DIMM_MODE_OVERRIDE_Type l_TGT0_ATTR_MSS_OCMB_HALF_DIMM_MODE_OVERRIDE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_HALF_DIMM_MODE_OVERRIDE, TGT0,
                               l_TGT0_ATTR_MSS_OCMB_HALF_DIMM_MODE_OVERRIDE));
        fapi2::ATTR_MSS_OCMB_HALF_DIMM_MODE_Type l_TGT0_ATTR_MSS_OCMB_HALF_DIMM_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_HALF_DIMM_MODE, TGT0, l_TGT0_ATTR_MSS_OCMB_HALF_DIMM_MODE));
        fapi2::ATTR_MSS_OCMB_NONENTERPRISE_MODE_OVERRIDE_Type l_TGT0_ATTR_MSS_OCMB_NONENTERPRISE_MODE_OVERRIDE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_NONENTERPRISE_MODE_OVERRIDE, TGT0,
                               l_TGT0_ATTR_MSS_OCMB_NONENTERPRISE_MODE_OVERRIDE));
        fapi2::ATTR_MSS_OCMB_ENTERPRISE_MODE_Type l_TGT0_ATTR_MSS_OCMB_ENTERPRISE_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_OCMB_ENTERPRISE_MODE, TGT0, l_TGT0_ATTR_MSS_OCMB_ENTERPRISE_MODE));
        uint64_t l_def_enterprise_mode = ((l_TGT0_ATTR_MSS_OCMB_ENTERPRISE_MODE == literal_1)
                                          && (l_TGT0_ATTR_MSS_OCMB_NONENTERPRISE_MODE_OVERRIDE == literal_1));
        uint64_t l_def_half_dimm_mode = ((l_def_enterprise_mode == literal_1)
                                         && (((l_TGT0_ATTR_MSS_OCMB_HALF_DIMM_MODE == literal_1) && (l_TGT0_ATTR_MSS_OCMB_HALF_DIMM_MODE_OVERRIDE != literal_1))
                                             || ((l_TGT0_ATTR_MSS_OCMB_HALF_DIMM_MODE == literal_0)
                                                     && (l_TGT0_ATTR_MSS_OCMB_HALF_DIMM_MODE_OVERRIDE == literal_2))));
        uint64_t l_def_s0_val_0 = (l_def_NUM_SRANKS_0 > literal_4);
        uint64_t l_def_s1_val_0 = (l_def_NUM_SRANKS_0 >= literal_4);
        uint64_t l_def_s2_val_0 = (l_def_NUM_SRANKS_0 >= literal_2);
        uint64_t l_def_s0_val_1 = (l_def_NUM_SRANKS_1 > literal_4);
        uint64_t l_def_s1_val_1 = (l_def_NUM_SRANKS_1 >= literal_4);
        uint64_t l_def_s2_val_1 = (l_def_NUM_SRANKS_1 >= literal_2);
        fapi2::ATTR_MEM_EFF_DRAM_ROW_BITS_Type l_TGT1_ATTR_MEM_EFF_DRAM_ROW_BITS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_ROW_BITS, TGT1, l_TGT1_ATTR_MEM_EFF_DRAM_ROW_BITS));
        uint64_t l_def_row_bit15_val_0 = (l_TGT1_ATTR_MEM_EFF_DRAM_ROW_BITS[literal_0] >= literal_16);
        uint64_t l_def_row_bit15_val_1 = (l_TGT1_ATTR_MEM_EFF_DRAM_ROW_BITS[literal_1] >= literal_16);
        uint64_t l_def_row_bit16_val_0 = (l_TGT1_ATTR_MEM_EFF_DRAM_ROW_BITS[literal_0] >= literal_17);
        uint64_t l_def_row_bit16_val_1 = (l_TGT1_ATTR_MEM_EFF_DRAM_ROW_BITS[literal_1] >= literal_17);
        uint64_t l_def_row_bit17_val_0 = (l_TGT1_ATTR_MEM_EFF_DRAM_ROW_BITS[literal_0] >= literal_18);
        uint64_t l_def_row_bit17_val_1 = (l_TGT1_ATTR_MEM_EFF_DRAM_ROW_BITS[literal_1] >= literal_18);
        uint64_t l_def_slot_val_0 = (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] > literal_0);
        uint64_t l_def_slot_val_1 = (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] > literal_0);
        uint64_t l_def_m0_val_0 = (l_def_NUM_MRANKS_0 > literal_2);
        uint64_t l_def_m1_val_0 = (l_def_NUM_MRANKS_0 >= literal_2);
        uint64_t l_def_m0_val_1 = (l_def_NUM_MRANKS_1 > literal_2);
        uint64_t l_def_m1_val_1 = (l_def_NUM_MRANKS_1 >= literal_2);
        uint64_t l_def_num_of_bitvals_0 = (((((((l_def_row_bit17_val_0 + l_def_row_bit16_val_0) + l_def_row_bit15_val_0) +
                                               l_def_m0_val_0) + l_def_m1_val_0) + l_def_s0_val_0) + l_def_s1_val_0) + l_def_s2_val_0);
        uint64_t l_def_num_of_bitvals_1 = (((((((l_def_row_bit17_val_1 + l_def_row_bit16_val_1) + l_def_row_bit15_val_1) +
                                               l_def_m0_val_1) + l_def_m1_val_1) + l_def_s0_val_1) + l_def_s1_val_1) + l_def_s2_val_1);
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801140cull, l_scom_buffer ));

            if (l_def_IS_MICROSEMI_SIM)
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_11) + l_def_RDIMM_Add_latency) +
                        l_TGT1_ATTR_MEM_EXP_DFIMRL_CLK) );
            }
            else if (l_def_IS_IBM_SIM)
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_4) + l_def_RDIMM_Add_latency) );
            }
            else if (l_def_IS_HW)
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_11) + l_def_RDIMM_Add_latency) +
                        l_TGT1_ATTR_MEM_EXP_DFIMRL_CLK) );
            }

            if (l_def_IS_MICROSEMI_SIM)
            {
                l_scom_buffer.insert<47, 5, 59, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_9) + l_def_RDIMM_Add_latency) );
            }
            else if (l_def_IS_IBM_SIM)
            {
                l_scom_buffer.insert<47, 5, 59, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_4) + l_def_RDIMM_Add_latency) );
            }
            else if (l_def_IS_HW)
            {
                l_scom_buffer.insert<47, 5, 59, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_9) + l_def_RDIMM_Add_latency) );
            }

            if (l_def_IS_MICROSEMI_SIM)
            {
                l_scom_buffer.insert<42, 5, 59, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_9) + l_def_RDIMM_Add_latency) );
            }
            else if (l_def_IS_IBM_SIM)
            {
                l_scom_buffer.insert<42, 5, 59, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_4) + l_def_RDIMM_Add_latency) );
            }
            else if (l_def_IS_HW)
            {
                l_scom_buffer.insert<42, 5, 59, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_CL - literal_9) + l_def_RDIMM_Add_latency) );
            }

            if (l_def_IS_MICROSEMI_SIM)
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(((l_TGT1_ATTR_MEM_DRAM_CWL - literal_14) + l_def_RDIMM_Add_latency) );
            }
            else if (l_def_IS_IBM_SIM)
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(((l_TGT1_ATTR_MEM_DRAM_CWL - literal_9) + l_def_RDIMM_Add_latency) );
            }
            else if (l_def_IS_HW)
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(((l_TGT1_ATTR_MEM_DRAM_CWL - literal_14) + l_def_RDIMM_Add_latency) );
            }

            if (l_def_IS_MICROSEMI_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(((l_TGT1_ATTR_MEM_DRAM_CWL - literal_7) + l_def_RDIMM_Add_latency) );
            }
            else if (l_def_IS_IBM_SIM)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(((l_TGT1_ATTR_MEM_DRAM_CWL - literal_2) + l_def_RDIMM_Add_latency) );
            }
            else if (l_def_IS_HW)
            {
                l_scom_buffer.insert<57, 5, 59, uint64_t>(((l_TGT1_ATTR_MEM_DRAM_CWL - literal_7) + l_def_RDIMM_Add_latency) );
            }

            if (l_def_IS_MICROSEMI_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(((l_TGT1_ATTR_MEM_DRAM_CWL - literal_7) + l_def_RDIMM_Add_latency) );
            }
            else if (l_def_IS_IBM_SIM)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(((l_TGT1_ATTR_MEM_DRAM_CWL - literal_2) + l_def_RDIMM_Add_latency) );
            }
            else if (l_def_IS_HW)
            {
                l_scom_buffer.insert<52, 5, 59, uint64_t>(((l_TGT1_ATTR_MEM_DRAM_CWL - literal_7) + l_def_RDIMM_Add_latency) );
            }

            l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_24 );
            l_scom_buffer.insert<0, 6, 58, uint64_t>(((l_TGT1_ATTR_MEM_EFF_DRAM_CL - l_TGT1_ATTR_MEM_DRAM_CWL) +
                    l_def_RDIMM_Add_latency) );
            l_scom_buffer.insert<6, 6, 58, uint64_t>((((l_TGT1_ATTR_MEM_EFF_DRAM_CL - l_TGT1_ATTR_MEM_DRAM_CWL) + literal_5) +
                    l_def_RDIMM_Add_latency) );
            l_scom_buffer.insert<12, 6, 58, uint64_t>((literal_0 + l_def_RDIMM_Add_latency) );
            l_scom_buffer.insert<18, 6, 58, uint64_t>((literal_5 + l_def_RDIMM_Add_latency) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801140cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801140dull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>((literal_4 + l_def_RANK_SWITCH_TCK) );
            l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<8, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<12, 4, 60, uint64_t>(l_TGT1_ATTR_MEM_EFF_DRAM_TCCD_L );
            l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_4 + l_def_RANK_SWITCH_TCK) );
            l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<24, 4, 60, uint64_t>(literal_4 );
            l_scom_buffer.insert<28, 4, 60, uint64_t>(l_TGT1_ATTR_MEM_EFF_DRAM_TCCD_L );
            l_scom_buffer.insert<32, 5, 59, uint64_t>((((l_TGT1_ATTR_MEM_EFF_DRAM_CL + literal_4) + l_def_BUS_TURNAROUND_TCK) -
                    l_TGT1_ATTR_MEM_DRAM_CWL) );
            l_scom_buffer.insert<37, 5, 59, uint64_t>((((l_TGT1_ATTR_MEM_EFF_DRAM_CL + literal_4) + l_def_BUS_TURNAROUND_TCK) -
                    l_TGT1_ATTR_MEM_DRAM_CWL) );
            l_scom_buffer.insert<42, 5, 59, uint64_t>((((l_TGT1_ATTR_MEM_EFF_DRAM_CL + literal_4) + l_def_BUS_TURNAROUND_TCK) -
                    l_TGT1_ATTR_MEM_DRAM_CWL) );
            l_scom_buffer.insert<47, 4, 60, uint64_t>((((l_TGT1_ATTR_MEM_DRAM_CWL + literal_4) + l_def_BUS_TURNAROUND_TCK) -
                    l_TGT1_ATTR_MEM_EFF_DRAM_CL) );
            l_scom_buffer.insert<51, 6, 58, uint64_t>(((l_TGT1_ATTR_MEM_DRAM_CWL + literal_4) + l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_S) );
            l_scom_buffer.insert<57, 6, 58, uint64_t>(((l_TGT1_ATTR_MEM_DRAM_CWL + literal_4) + l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_S) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801140dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801140eull, l_scom_buffer ));

            l_scom_buffer.insert<0, 4, 60, uint64_t>(l_TGT1_ATTR_MEM_EFF_DRAM_TCCD_L );
            l_scom_buffer.insert<4, 6, 58, uint64_t>(((l_TGT1_ATTR_MEM_DRAM_CWL + literal_4) + l_TGT1_ATTR_MEM_EFF_DRAM_TWTR_L) );
            l_scom_buffer.insert<10, 6, 58, uint64_t>(l_TGT1_ATTR_MEM_EFF_DRAM_TFAW );
            l_scom_buffer.insert<16, 5, 59, uint64_t>(l_TGT1_ATTR_MEM_EFF_DRAM_TRCD );
            l_scom_buffer.insert<21, 5, 59, uint64_t>(l_TGT1_ATTR_MEM_EFF_DRAM_TRP );
            l_scom_buffer.insert<26, 6, 58, uint64_t>(l_TGT1_ATTR_MEM_EFF_DRAM_TRAS );
            l_scom_buffer.insert<41, 7, 57, uint64_t>(((l_TGT1_ATTR_MEM_DRAM_CWL + literal_4) + l_TGT1_ATTR_MEM_EFF_DRAM_TWR) );
            l_scom_buffer.insert<48, 4, 60, uint64_t>(l_TGT1_ATTR_MEM_EFF_DRAM_TRTP );
            l_scom_buffer.insert<52, 4, 60, uint64_t>(l_TGT1_ATTR_MEM_EFF_DRAM_TRRD_S );
            l_scom_buffer.insert<56, 4, 60, uint64_t>(l_TGT1_ATTR_MEM_EFF_DRAM_TRRD_L );

            if ((l_def_MEM_EFF_FREQ_EQ_2666 == literal_1))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_11 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_2933 == literal_1))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_12 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_13 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x801140eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801140full, l_scom_buffer ));

            l_scom_buffer.insert<5, 1, 63, uint64_t>(l_TGT0_ATTR_MEM_REORDER_QUEUE_SETTING );
            l_scom_buffer.insert<55, 4, 60, uint64_t>(literal_0b1000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801140full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011410ull, l_scom_buffer ));

            l_scom_buffer.insert<6, 1, 63, uint64_t>(l_TGT0_ATTR_MEM_REORDER_QUEUE_SETTING );
            l_scom_buffer.insert<12, 1, 63, uint64_t>(l_def_disable_fast_act );
            l_scom_buffer.insert<57, 4, 60, uint64_t>(literal_0b1000 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011410ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011411ull, l_scom_buffer ));

            l_scom_buffer.insert<1, 2, 62, uint64_t>(literal_2 );
            l_scom_buffer.insert<3, 9, 55, uint64_t>(literal_511 );
            l_scom_buffer.insert<13, 8, 56, uint64_t>(literal_132 );
            l_scom_buffer.insert<21, 2, 62, uint64_t>(literal_0 );
            l_scom_buffer.insert<33, 2, 62, uint64_t>(literal_2 );
            l_scom_buffer.insert<35, 9, 55, uint64_t>(literal_8 );
            l_scom_buffer.insert<44, 1, 63, uint64_t>(literal_0 );
            l_scom_buffer.insert<55, 9, 55, uint64_t>(literal_100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011411ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011415ull, l_scom_buffer ));

            l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_1 );

            if ((((l_def_NUM_MRANKS_0 == literal_4) && (l_def_NUM_SRANKS_0 == literal_4)) || ((l_def_NUM_MRANKS_1 == literal_4)
                    && (l_def_NUM_SRANKS_1 == literal_4))))
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_1 );
            }

            if (((l_def_NUM_MRANKS_0 == literal_4) || (l_def_NUM_MRANKS_1 == literal_4)))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_1 );
            }

            if ((l_TGT2_ATTR_MSS_MRW_DRAM_2N_MODE == literal_0x02))
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b1 );
            }
            else if ((l_TGT2_ATTR_MSS_MRW_DRAM_2N_MODE == literal_0x01))
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b0 );
            }
            else if (((l_TGT2_ATTR_MSS_MRW_DRAM_2N_MODE == literal_0x00) && (l_TGT0_ATTR_MEM_2N_MODE == literal_0x02)))
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (((l_TGT2_ATTR_MSS_MRW_DRAM_2N_MODE == literal_0x00) && (l_TGT0_ATTR_MEM_2N_MODE == literal_0x01)))
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b0 );
            }

            l_scom_buffer.insert<19, 1, 63, uint64_t>(l_TGT0_ATTR_MEM_MRW_IS_PLANAR );
            l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_8 );
            l_scom_buffer.insert<24, 7, 57, uint64_t>(literal_64 );
            l_scom_buffer.insert<31, 7, 57, uint64_t>(literal_32 );
            l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_16 );
            l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011415ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011416ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 3, 61, uint64_t>(literal_0b000 );

            if ((l_def_NUM_MRANKS_0 != literal_4))
            {
                l_scom_buffer.insert<3, 3, 61, uint64_t>(literal_0b100 );
            }
            else if ((l_def_NUM_MRANKS_0 == literal_4))
            {
                l_scom_buffer.insert<3, 3, 61, uint64_t>(literal_0b010 );
            }

            if ((l_def_NUM_MRANKS_0 != literal_4))
            {
                l_scom_buffer.insert<6, 3, 61, uint64_t>(literal_0b010 );
            }
            else if ((l_def_NUM_MRANKS_0 == literal_4))
            {
                l_scom_buffer.insert<6, 3, 61, uint64_t>(literal_0b001 );
            }

            if ((l_def_NUM_MRANKS_0 != literal_4))
            {
                l_scom_buffer.insert<9, 3, 61, uint64_t>(literal_0b110 );
            }
            else if ((l_def_NUM_MRANKS_0 == literal_4))
            {
                l_scom_buffer.insert<9, 3, 61, uint64_t>(literal_0b011 );
            }

            if (((l_def_SLOT0_DRAM_STACK_HEIGHT == literal_8) && (l_def_NUM_MRANKS_0 != literal_4)))
            {
                l_scom_buffer.insert<12, 3, 61, uint64_t>(literal_0b001 );
            }
            else if (((l_def_SLOT0_DRAM_STACK_HEIGHT != literal_8) && (l_def_NUM_MRANKS_0 != literal_4)))
            {
                l_scom_buffer.insert<12, 3, 61, uint64_t>(literal_0b000 );
            }
            else if ((l_def_NUM_MRANKS_0 == literal_4))
            {
                l_scom_buffer.insert<12, 3, 61, uint64_t>(literal_0b100 );
            }

            if (((l_def_SLOT0_DRAM_STACK_HEIGHT == literal_8) && (l_def_NUM_MRANKS_0 != literal_4)))
            {
                l_scom_buffer.insert<15, 3, 61, uint64_t>(literal_0b101 );
            }
            else if (((l_def_SLOT0_DRAM_STACK_HEIGHT != literal_8) && (l_def_NUM_MRANKS_0 != literal_4)))
            {
                l_scom_buffer.insert<15, 3, 61, uint64_t>(literal_0b100 );
            }
            else if ((l_def_NUM_MRANKS_0 == literal_4))
            {
                l_scom_buffer.insert<15, 3, 61, uint64_t>(literal_0b110 );
            }

            if (((l_def_SLOT0_DRAM_STACK_HEIGHT == literal_8) && (l_def_NUM_MRANKS_0 != literal_4)))
            {
                l_scom_buffer.insert<18, 3, 61, uint64_t>(literal_0b011 );
            }
            else if (((l_def_SLOT0_DRAM_STACK_HEIGHT != literal_8) && (l_def_NUM_MRANKS_0 != literal_4)))
            {
                l_scom_buffer.insert<18, 3, 61, uint64_t>(literal_0b010 );
            }
            else if ((l_def_NUM_MRANKS_0 == literal_4))
            {
                l_scom_buffer.insert<18, 3, 61, uint64_t>(literal_0b101 );
            }

            if (((l_def_SLOT0_DRAM_STACK_HEIGHT == literal_8) && (l_def_NUM_MRANKS_0 != literal_4)))
            {
                l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0b111 );
            }
            else if (((l_def_SLOT0_DRAM_STACK_HEIGHT != literal_8) && (l_def_NUM_MRANKS_0 != literal_4)))
            {
                l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0b110 );
            }
            else if ((l_def_NUM_MRANKS_0 == literal_4))
            {
                l_scom_buffer.insert<21, 3, 61, uint64_t>(literal_0b111 );
            }

            l_scom_buffer.insert<24, 3, 61, uint64_t>(literal_0b000 );

            if ((l_def_NUM_MRANKS_1 != literal_4))
            {
                l_scom_buffer.insert<27, 3, 61, uint64_t>(literal_0b100 );
            }
            else if ((l_def_NUM_MRANKS_1 == literal_4))
            {
                l_scom_buffer.insert<27, 3, 61, uint64_t>(literal_0b010 );
            }

            if ((l_def_NUM_MRANKS_1 != literal_4))
            {
                l_scom_buffer.insert<30, 3, 61, uint64_t>(literal_0b010 );
            }
            else if ((l_def_NUM_MRANKS_1 == literal_4))
            {
                l_scom_buffer.insert<30, 3, 61, uint64_t>(literal_0b001 );
            }

            if ((l_def_NUM_MRANKS_1 != literal_4))
            {
                l_scom_buffer.insert<33, 3, 61, uint64_t>(literal_0b110 );
            }
            else if ((l_def_NUM_MRANKS_1 == literal_4))
            {
                l_scom_buffer.insert<33, 3, 61, uint64_t>(literal_0b011 );
            }

            if (((l_def_SLOT1_DRAM_STACK_HEIGHT == literal_8) && (l_def_NUM_MRANKS_1 != literal_4)))
            {
                l_scom_buffer.insert<36, 3, 61, uint64_t>(literal_0b001 );
            }
            else if (((l_def_SLOT1_DRAM_STACK_HEIGHT != literal_8) && (l_def_NUM_MRANKS_1 != literal_4)))
            {
                l_scom_buffer.insert<36, 3, 61, uint64_t>(literal_0b000 );
            }
            else if ((l_def_NUM_MRANKS_1 == literal_4))
            {
                l_scom_buffer.insert<36, 3, 61, uint64_t>(literal_0b100 );
            }

            if (((l_def_SLOT1_DRAM_STACK_HEIGHT == literal_8) && (l_def_NUM_MRANKS_1 != literal_4)))
            {
                l_scom_buffer.insert<39, 3, 61, uint64_t>(literal_0b101 );
            }
            else if (((l_def_SLOT1_DRAM_STACK_HEIGHT != literal_8) && (l_def_NUM_MRANKS_1 != literal_4)))
            {
                l_scom_buffer.insert<39, 3, 61, uint64_t>(literal_0b100 );
            }
            else if ((l_def_NUM_MRANKS_1 == literal_4))
            {
                l_scom_buffer.insert<39, 3, 61, uint64_t>(literal_0b110 );
            }

            if (((l_def_SLOT1_DRAM_STACK_HEIGHT == literal_8) && (l_def_NUM_MRANKS_1 != literal_4)))
            {
                l_scom_buffer.insert<42, 3, 61, uint64_t>(literal_0b011 );
            }
            else if (((l_def_SLOT1_DRAM_STACK_HEIGHT != literal_8) && (l_def_NUM_MRANKS_1 != literal_4)))
            {
                l_scom_buffer.insert<42, 3, 61, uint64_t>(literal_0b010 );
            }
            else if ((l_def_NUM_MRANKS_1 == literal_4))
            {
                l_scom_buffer.insert<42, 3, 61, uint64_t>(literal_0b101 );
            }

            if (((l_def_SLOT1_DRAM_STACK_HEIGHT == literal_8) && (l_def_NUM_MRANKS_1 != literal_4)))
            {
                l_scom_buffer.insert<45, 3, 61, uint64_t>(literal_0b111 );
            }
            else if (((l_def_SLOT1_DRAM_STACK_HEIGHT != literal_8) && (l_def_NUM_MRANKS_1 != literal_4)))
            {
                l_scom_buffer.insert<45, 3, 61, uint64_t>(literal_0b110 );
            }
            else if ((l_def_NUM_MRANKS_1 == literal_4))
            {
                l_scom_buffer.insert<45, 3, 61, uint64_t>(literal_0b111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8011416ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011417ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_0] >> literal_7) );
            l_scom_buffer.insert<1, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_0] >> literal_6) );
            l_scom_buffer.insert<2, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_0] >> literal_3) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_0] >> literal_7) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<3, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_0] >> literal_2) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_0] >> literal_6) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<4, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_1] >> literal_7) );
            l_scom_buffer.insert<5, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_1] >> literal_6) );
            l_scom_buffer.insert<6, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_1] >> literal_3) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_1] >> literal_7) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<7, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_1] >> literal_2) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_1] >> literal_6) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<8, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_2] >> literal_7) );
            l_scom_buffer.insert<9, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_2] >> literal_6) );
            l_scom_buffer.insert<10, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_2] >> literal_3) );
            l_scom_buffer.insert<11, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_2] >> literal_2) );
            l_scom_buffer.insert<12, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_3] >> literal_7) );
            l_scom_buffer.insert<13, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_3] >> literal_6) );
            l_scom_buffer.insert<14, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_3] >> literal_3) );
            l_scom_buffer.insert<15, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_0][literal_3] >> literal_2) );
            l_scom_buffer.insert<16, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_0] >> literal_7) );
            l_scom_buffer.insert<17, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_0] >> literal_6) );
            l_scom_buffer.insert<18, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_0] >> literal_3) );
            l_scom_buffer.insert<19, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_0] >> literal_2) );
            l_scom_buffer.insert<20, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_1] >> literal_7) );
            l_scom_buffer.insert<21, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_1] >> literal_6) );
            l_scom_buffer.insert<22, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_1] >> literal_3) );
            l_scom_buffer.insert<23, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_1] >> literal_2) );
            l_scom_buffer.insert<24, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_2] >> literal_7) );
            l_scom_buffer.insert<25, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_2] >> literal_6) );
            l_scom_buffer.insert<26, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_2] >> literal_3) );
            l_scom_buffer.insert<27, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_2] >> literal_2) );
            l_scom_buffer.insert<28, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_3] >> literal_7) );
            l_scom_buffer.insert<29, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_3] >> literal_6) );
            l_scom_buffer.insert<30, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_3] >> literal_3) );
            l_scom_buffer.insert<31, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_RD[literal_1][literal_3] >> literal_2) );
            l_scom_buffer.insert<32, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_0] >> literal_7) );
            l_scom_buffer.insert<33, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_0] >> literal_6) );
            l_scom_buffer.insert<34, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_0] >> literal_3) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_0] >> literal_7) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<35, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_0] >> literal_2) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_0] >> literal_6) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<36, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_1] >> literal_7) );
            l_scom_buffer.insert<37, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_1] >> literal_6) );
            l_scom_buffer.insert<38, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_1] >> literal_3) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_1] >> literal_7) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<39, 1, 63, uint64_t>(((((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_1] >> literal_2) &
                    literal_0b1) && (l_def_cs_tied == literal_0))
                    || (((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_1] >> literal_6) & literal_0b1) && (l_def_cs_tied == literal_1))) );
            l_scom_buffer.insert<40, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_2] >> literal_7) );
            l_scom_buffer.insert<41, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_2] >> literal_6) );
            l_scom_buffer.insert<42, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_2] >> literal_3) );
            l_scom_buffer.insert<43, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_2] >> literal_2) );
            l_scom_buffer.insert<44, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_3] >> literal_7) );
            l_scom_buffer.insert<45, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_3] >> literal_6) );
            l_scom_buffer.insert<46, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_3] >> literal_3) );
            l_scom_buffer.insert<47, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_0][literal_3] >> literal_2) );
            l_scom_buffer.insert<48, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_0] >> literal_7) );
            l_scom_buffer.insert<49, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_0] >> literal_6) );
            l_scom_buffer.insert<50, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_0] >> literal_3) );
            l_scom_buffer.insert<51, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_0] >> literal_2) );
            l_scom_buffer.insert<52, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_1] >> literal_7) );
            l_scom_buffer.insert<53, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_1] >> literal_6) );
            l_scom_buffer.insert<54, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_1] >> literal_3) );
            l_scom_buffer.insert<55, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_1] >> literal_2) );
            l_scom_buffer.insert<56, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_2] >> literal_7) );
            l_scom_buffer.insert<57, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_2] >> literal_6) );
            l_scom_buffer.insert<58, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_2] >> literal_3) );
            l_scom_buffer.insert<59, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_2] >> literal_2) );
            l_scom_buffer.insert<60, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_3] >> literal_7) );
            l_scom_buffer.insert<61, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_3] >> literal_6) );
            l_scom_buffer.insert<62, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_3] >> literal_3) );
            l_scom_buffer.insert<63, 1, 63, uint64_t>((l_TGT1_ATTR_MEM_SI_ODT_WR[literal_1][literal_3] >> literal_2) );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011417ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011419ull, l_scom_buffer ));

            l_scom_buffer.insert<0, 16, 48, uint64_t>(literal_0x0100 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011419ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801141aull, l_scom_buffer ));

            l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_1 );
            l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x801141aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011434ull, l_scom_buffer ));

            l_scom_buffer.insert<8, 11, 53, uint64_t>(l_def_REFRESH_INTERVAL );
            l_scom_buffer.insert<30, 10, 54, uint64_t>(l_TGT1_ATTR_MEM_EFF_DRAM_TRFC );
            l_scom_buffer.insert<40, 10, 54, uint64_t>(l_TGT1_ATTR_MEM_EFF_DRAM_TRFC_DLR );
            l_scom_buffer.insert<5, 3, 61, uint64_t>(literal_0 );
            l_scom_buffer.insert<50, 11, 53, uint64_t>(l_def_REFR_CHECK_INTERVAL );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011434ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011436ull, l_scom_buffer ));

            if ((l_def_MEM_EFF_FREQ_EQ_2666 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_7 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_2933 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_8 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_8 );
            }

            if ((l_def_MEM_EFF_FREQ_EQ_2666 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_7 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_2933 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_8 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_8 );
            }

            if ((l_def_MEM_EFF_FREQ_EQ_2666 == literal_1))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>(literal_8 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_2933 == literal_1))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>(literal_9 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>(literal_10 );
            }

            if (((l_def_NUM_MRANKS_0 == literal_4) || (l_def_NUM_MRANKS_1 == literal_4)))
            {
                l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8011436ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011437ull, l_scom_buffer ));

            if ((l_def_MEM_EFF_FREQ_EQ_2666 == literal_1))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_13 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_2933 == literal_1))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_15 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<17, 5, 59, uint64_t>(literal_16 );
            }

            if ((l_def_MEM_EFF_FREQ_EQ_2666 == literal_1))
            {
                l_scom_buffer.insert<22, 5, 59, uint64_t>(literal_13 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_2933 == literal_1))
            {
                l_scom_buffer.insert<22, 5, 59, uint64_t>(literal_15 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<22, 5, 59, uint64_t>(literal_16 );
            }

            if ((l_def_MEM_EFF_FREQ_EQ_2666 == literal_1))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_8 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_2933 == literal_1))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_9 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<12, 5, 59, uint64_t>(literal_9 );
            }

            if ((l_def_MEM_EFF_FREQ_EQ_2666 == literal_1))
            {
                l_scom_buffer.insert<27, 11, 53, uint64_t>(literal_1024 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_2933 == literal_1))
            {
                l_scom_buffer.insert<27, 11, 53, uint64_t>(literal_1024 );
            }
            else if ((l_def_MEM_EFF_FREQ_EQ_3200 == literal_1))
            {
                l_scom_buffer.insert<27, 11, 53, uint64_t>(literal_1024 );
            }

            l_scom_buffer.insert<46, 11, 53, uint64_t>(l_def_REFRESH_INTERVAL );
            l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_1 );
            FAPI_TRY(fapi2::putScom(TGT0, 0x8011437ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x801186full, l_scom_buffer ));

            if (((l_def_half_dimm_mode == literal_1) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                    || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b01011 );
            }
            else if ((((l_def_half_dimm_mode == literal_1) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b01100 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                      || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b01100 );
            }
            else if ((((l_def_half_dimm_mode == literal_0) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b01101 );
            }

            if (((l_def_half_dimm_mode == literal_1) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                    || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01100 );
            }
            else if ((((l_def_half_dimm_mode == literal_1) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01101 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                      || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01101 );
            }
            else if ((((l_def_half_dimm_mode == literal_0) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<54, 5, 59, uint64_t>(literal_0b01110 );
            }

            if (((l_def_half_dimm_mode == literal_1) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                    || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<49, 5, 59, uint64_t>(literal_0b01101 );
            }
            else if ((((l_def_half_dimm_mode == literal_1) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<49, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                      || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<49, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if ((((l_def_half_dimm_mode == literal_0) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<49, 5, 59, uint64_t>(literal_0b01111 );
            }

            l_scom_buffer.insert<9, 1, 63, uint64_t>(l_def_s0_val_0 );
            l_scom_buffer.insert<10, 1, 63, uint64_t>(l_def_s1_val_0 );
            l_scom_buffer.insert<11, 1, 63, uint64_t>(l_def_s2_val_0 );
            l_scom_buffer.insert<25, 1, 63, uint64_t>(l_def_s0_val_1 );
            l_scom_buffer.insert<26, 1, 63, uint64_t>(l_def_s1_val_1 );
            l_scom_buffer.insert<27, 1, 63, uint64_t>(l_def_s2_val_1 );
            l_scom_buffer.insert<13, 1, 63, uint64_t>(l_def_row_bit15_val_0 );
            l_scom_buffer.insert<29, 1, 63, uint64_t>(l_def_row_bit15_val_1 );
            l_scom_buffer.insert<14, 1, 63, uint64_t>(l_def_row_bit16_val_0 );
            l_scom_buffer.insert<30, 1, 63, uint64_t>(l_def_row_bit16_val_1 );
            l_scom_buffer.insert<15, 1, 63, uint64_t>(l_def_row_bit17_val_0 );
            l_scom_buffer.insert<31, 1, 63, uint64_t>(l_def_row_bit17_val_1 );
            l_scom_buffer.insert<0, 1, 63, uint64_t>(l_def_slot_val_0 );
            l_scom_buffer.insert<16, 1, 63, uint64_t>(l_def_slot_val_1 );
            l_scom_buffer.insert<5, 1, 63, uint64_t>(l_def_m0_val_0 );
            l_scom_buffer.insert<6, 1, 63, uint64_t>(l_def_m1_val_0 );
            l_scom_buffer.insert<21, 1, 63, uint64_t>(l_def_m0_val_1 );
            l_scom_buffer.insert<22, 1, 63, uint64_t>(l_def_m1_val_1 );

            if (((l_def_s2_val_0 == literal_0) && (l_def_s2_val_1 == literal_0)))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b00110 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01100 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01101 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b10001 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b10001 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01101 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b10001 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b10001 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b10010 );
            }

            if (((l_def_half_dimm_mode == literal_1) && (((l_def_row_bit15_val_0 == literal_0)
                    && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_0) || (l_def_s2_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01100 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01101 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_0) || (l_def_s2_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01101 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_0) || (l_def_s2_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10001 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_0) || (l_def_s2_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10001 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10010 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_0) || (l_def_s2_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01101 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_0) || (l_def_s2_val_0 == literal_1)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_0)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10001 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_0) || (l_def_s2_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10001 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0)) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10010 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_0) || (l_def_s2_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_0) && (l_def_s1_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10001 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_0)
                              && (l_def_s0_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10010 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_1))) && ((l_def_s2_val_0 == literal_1) || (l_def_s2_val_1 == literal_1)))
                      && ((l_def_s1_val_0 == literal_1) || (l_def_s1_val_1 == literal_1))) && ((l_def_s0_val_0 == literal_1)
                              || (l_def_s0_val_1 == literal_1)))))
            {
                l_scom_buffer.insert<38, 5, 59, uint64_t>(literal_0b10011 );
            }

            if (((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] < literal_2)
                 && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] < literal_2)))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b00110 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((l_def_num_of_bitvals_0 == literal_1)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b01100 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((l_def_num_of_bitvals_0 == literal_2)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b01101 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((l_def_num_of_bitvals_0 == literal_3)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((l_def_num_of_bitvals_0 == literal_4)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((l_def_num_of_bitvals_0 == literal_5)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((l_def_num_of_bitvals_0 == literal_6)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b10001 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((l_def_num_of_bitvals_0 == literal_7)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b10010 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_def_num_of_bitvals_0 == literal_1)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b01101 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_def_num_of_bitvals_0 == literal_2)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_def_num_of_bitvals_0 == literal_3)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_def_num_of_bitvals_0 == literal_4)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_def_num_of_bitvals_0 == literal_5)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b10001 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_def_num_of_bitvals_0 == literal_6)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b10010 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_def_num_of_bitvals_0 == literal_7)
                      && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] >= literal_2)
                          || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] >= literal_2)))))
            {
                l_scom_buffer.insert<33, 5, 59, uint64_t>(literal_0b10011 );
            }

            if ((l_def_num_of_bitvals_0 >= l_def_num_of_bitvals_1))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0 );
            }
            else if ((l_def_num_of_bitvals_1 > l_def_num_of_bitvals_0))
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_1 );
            }

            if ((l_def_num_of_bitvals_1 > l_def_num_of_bitvals_0))
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0 );
            }
            else if ((l_def_num_of_bitvals_0 >= l_def_num_of_bitvals_1))
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x801186full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011870ull, l_scom_buffer ));

            if ((l_def_half_dimm_mode == literal_1))
            {
                l_scom_buffer.insert<30, 5, 59, uint64_t>(literal_0b00100 );
            }
            else if ((l_def_half_dimm_mode == literal_0))
            {
                l_scom_buffer.insert<30, 5, 59, uint64_t>(literal_0b00001 );
            }

            if (((l_def_NUM_SRANKS_0 > literal_1) || (l_def_NUM_SRANKS_1 > literal_1)))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_0b00110 );
            }

            if ((l_def_half_dimm_mode == literal_1))
            {
                l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_0b00101 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                      || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_0b00110 );
            }
            else if ((((l_def_half_dimm_mode == literal_0) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<35, 5, 59, uint64_t>(literal_0b00111 );
            }

            if (((l_def_half_dimm_mode == literal_1) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                    || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b00110 );
            }
            else if ((((l_def_half_dimm_mode == literal_1) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b00111 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                      || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b00111 );
            }
            else if ((((l_def_half_dimm_mode == literal_0) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b01000 );
            }

            if (((l_def_half_dimm_mode == literal_1) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                    || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0b00111 );
            }
            else if ((((l_def_half_dimm_mode == literal_1) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0b01000 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                      || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0b01000 );
            }
            else if ((((l_def_half_dimm_mode == literal_0) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0b01001 );
            }

            if (((l_def_half_dimm_mode == literal_1) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                    || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b01000 );
            }
            else if ((((l_def_half_dimm_mode == literal_1) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b01001 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                      || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b01001 );
            }
            else if ((((l_def_half_dimm_mode == literal_0) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b01010 );
            }

            if (((l_def_half_dimm_mode == literal_1) && ((l_def_row_bit15_val_0 == literal_0)
                    && (l_def_row_bit15_val_1 == literal_0))))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b01100 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0))))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b01101 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0))))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0))))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b01101 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0))))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0))))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b10000 );
            }

            if (((l_def_half_dimm_mode == literal_1) && ((l_def_row_bit15_val_0 == literal_0)
                    && (l_def_row_bit15_val_1 == literal_0))))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b01101 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0))))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && (((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0))))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_1) && ((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_def_row_bit15_val_0 == literal_0)
                      && (l_def_row_bit15_val_1 == literal_0))))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b01110 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && (l_def_row_bit16_val_0 == literal_0))
                      && (l_def_row_bit16_val_1 == literal_0))))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b01111 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && (((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && (l_def_row_bit17_val_0 == literal_0))
                      && (l_def_row_bit17_val_1 == literal_0))))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((((l_def_row_bit15_val_0 == literal_1)
                      || (l_def_row_bit15_val_1 == literal_1)) && ((l_def_row_bit16_val_0 == literal_1)
                              || (l_def_row_bit16_val_1 == literal_1))) && ((l_def_row_bit17_val_0 == literal_1)
                                      || (l_def_row_bit17_val_1 == literal_0)))))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b10001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8011870ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8011871ull, l_scom_buffer ));

            if ((l_def_half_dimm_mode == literal_1))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if ((l_def_half_dimm_mode == literal_0))
            {
                l_scom_buffer.insert<51, 5, 59, uint64_t>(literal_0b00010 );
            }

            if ((l_def_half_dimm_mode == literal_1))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b00001 );
            }
            else if ((l_def_half_dimm_mode == literal_0))
            {
                l_scom_buffer.insert<43, 5, 59, uint64_t>(literal_0b00011 );
            }

            if ((l_def_half_dimm_mode == literal_1))
            {
                l_scom_buffer.insert<27, 5, 59, uint64_t>(literal_0b00010 );
            }
            else if ((l_def_half_dimm_mode == literal_0))
            {
                l_scom_buffer.insert<27, 5, 59, uint64_t>(literal_0b00100 );
            }

            if ((l_def_half_dimm_mode == literal_1))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_0b00011 );
            }
            else if ((l_def_half_dimm_mode == literal_0))
            {
                l_scom_buffer.insert<19, 5, 59, uint64_t>(literal_0b00101 );
            }

            if (((l_def_half_dimm_mode == literal_1) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                    || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b01001 );
            }
            else if ((((l_def_half_dimm_mode == literal_1) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b01010 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                      || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b01010 );
            }
            else if ((((l_def_half_dimm_mode == literal_0) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<3, 5, 59, uint64_t>(literal_0b01011 );
            }

            if (((l_def_half_dimm_mode == literal_1) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                    || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b01010 );
            }
            else if ((((l_def_half_dimm_mode == literal_1) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b01011 );
            }
            else if (((l_def_half_dimm_mode == literal_0) && ((l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] == literal_1)
                      || (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] == literal_1))))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b01011 );
            }
            else if ((((l_def_half_dimm_mode == literal_0) && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_0] != literal_1))
                      && (l_TGT1_ATTR_MEM_EFF_LOGICAL_RANKS_PER_DIMM[literal_1] != literal_1)))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b01100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8011871ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
