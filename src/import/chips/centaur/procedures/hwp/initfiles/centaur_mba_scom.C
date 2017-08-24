/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/initfiles/centaur_mba_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include "centaur_mba_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b000101 = 0b000101;
constexpr uint64_t literal_0b000011 = 0b000011;
constexpr uint64_t literal_0b000000 = 0b000000;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_1333 = 1333;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_1066 = 1066;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_0b001110 = 0b001110;
constexpr uint64_t literal_9 = 9;
constexpr uint64_t literal_1600 = 1600;
constexpr uint64_t literal_11 = 11;
constexpr uint64_t literal_1866 = 1866;
constexpr uint64_t literal_12 = 12;
constexpr uint64_t literal_0b010100 = 0b010100;
constexpr uint64_t literal_1400 = 1400;
constexpr uint64_t literal_13 = 13;
constexpr uint64_t literal_0b011001 = 0b011001;
constexpr uint64_t literal_0b001111 = 0b001111;
constexpr uint64_t literal_0b011100 = 0b011100;
constexpr uint64_t literal_0b001101 = 0b001101;
constexpr uint64_t literal_10 = 10;
constexpr uint64_t literal_0b010000 = 0b010000;
constexpr uint64_t literal_0b011101 = 0b011101;
constexpr uint64_t literal_0b011010 = 0b011010;
constexpr uint64_t literal_0b010010 = 0b010010;
constexpr uint64_t literal_0b011000 = 0b011000;
constexpr uint64_t literal_0b010111 = 0b010111;
constexpr uint64_t literal_0b010110 = 0b010110;
constexpr uint64_t literal_0b010001 = 0b010001;
constexpr uint64_t literal_0b001100 = 0b001100;
constexpr uint64_t literal_0b010101 = 0b010101;
constexpr uint64_t literal_0b010011 = 0b010011;
constexpr uint64_t literal_0b011011 = 0b011011;
constexpr uint64_t literal_0x0F = 0x0F;
constexpr uint64_t literal_0x07 = 0x07;
constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_0b00 = 0b00;
constexpr uint64_t literal_0b00000 = 0b00000;
constexpr uint64_t literal_2400 = 2400;
constexpr uint64_t literal_0b1001 = 0b1001;
constexpr uint64_t literal_0b0111 = 0b0111;
constexpr uint64_t literal_2133 = 2133;
constexpr uint64_t literal_0b1000 = 0b1000;
constexpr uint64_t literal_0b0100 = 0b0100;
constexpr uint64_t literal_0b0101 = 0b0101;
constexpr uint64_t literal_0b011110 = 0b011110;
constexpr uint64_t literal_0b100001 = 0b100001;
constexpr uint64_t literal_0b100000 = 0b100000;
constexpr uint64_t literal_0b011111 = 0b011111;
constexpr uint64_t literal_0b1011 = 0b1011;
constexpr uint64_t literal_0b1111 = 0b1111;
constexpr uint64_t literal_0b1010 = 0b1010;
constexpr uint64_t literal_0b1101 = 0b1101;
constexpr uint64_t literal_0b1110 = 0b1110;
constexpr uint64_t literal_0b0000 = 0b0000;
constexpr uint64_t literal_0b1100 = 0b1100;
constexpr uint64_t literal_0b0110 = 0b0110;
constexpr uint64_t literal_0b0101011 = 0b0101011;
constexpr uint64_t literal_0b0011011 = 0b0011011;
constexpr uint64_t literal_0b0011010 = 0b0011010;
constexpr uint64_t literal_0b0101110 = 0b0101110;
constexpr uint64_t literal_0b0101010 = 0b0101010;
constexpr uint64_t literal_0b0100110 = 0b0100110;
constexpr uint64_t literal_0b0011100 = 0b0011100;
constexpr uint64_t literal_0b0101000 = 0b0101000;
constexpr uint64_t literal_0b0100101 = 0b0100101;
constexpr uint64_t literal_0b0100000 = 0b0100000;
constexpr uint64_t literal_0b0100001 = 0b0100001;
constexpr uint64_t literal_0b0101100 = 0b0101100;
constexpr uint64_t literal_0b0100111 = 0b0100111;
constexpr uint64_t literal_16 = 16;
constexpr uint64_t literal_0b0001111 = 0b0001111;
constexpr uint64_t literal_0b11110 = 0b11110;
constexpr uint64_t literal_0b10011 = 0b10011;
constexpr uint64_t literal_0b11111 = 0b11111;
constexpr uint64_t literal_0b11101 = 0b11101;
constexpr uint64_t literal_0b11011 = 0b11011;
constexpr uint64_t literal_0b11010 = 0b11010;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0b0110101 = 0b0110101;
constexpr uint64_t literal_0b0110000 = 0b0110000;
constexpr uint64_t literal_0b0101111 = 0b0101111;
constexpr uint64_t literal_0b0110011 = 0b0110011;
constexpr uint64_t literal_0b0100010 = 0b0100010;
constexpr uint64_t literal_0b0110001 = 0b0110001;
constexpr uint64_t literal_0b0011110 = 0b0011110;
constexpr uint64_t literal_0b00000000 = 0b00000000;
constexpr uint64_t literal_0b000 = 0b000;
constexpr uint64_t literal_0b01000000 = 0b01000000;
constexpr uint64_t literal_511 = 511;
constexpr uint64_t literal_16384 = 16384;
constexpr uint64_t literal_0b11 = 0b11;
constexpr uint64_t literal_512 = 512;
constexpr uint64_t literal_0b10 = 0b10;
constexpr uint64_t literal_0b000000000 = 0b000000000;
constexpr uint64_t literal_16777216 = 16777216;
constexpr uint64_t literal_0b000000001 = 0b000000001;
constexpr uint64_t literal_0b0011 = 0b0011;
constexpr uint64_t literal_0b000000000000000000000000 = 0b000000000000000000000000;
constexpr uint64_t literal_0b11111111 = 0b11111111;
constexpr uint64_t literal_21 = 21;
constexpr uint64_t literal_23 = 23;
constexpr uint64_t literal_0b111100 = 0b111100;
constexpr uint64_t literal_0b110100 = 0b110100;
constexpr uint64_t literal_0b111000 = 0b111000;
constexpr uint64_t literal_15 = 15;
constexpr uint64_t literal_22 = 22;
constexpr uint64_t literal_17 = 17;
constexpr uint64_t literal_0b101110 = 0b101110;
constexpr uint64_t literal_0b101000 = 0b101000;
constexpr uint64_t literal_0b110110 = 0b110110;
constexpr uint64_t literal_0b100100 = 0b100100;
constexpr uint64_t literal_0b111010 = 0b111010;
constexpr uint64_t literal_0b101100 = 0b101100;
constexpr uint64_t literal_0b100010 = 0b100010;
constexpr uint64_t literal_0b101001 = 0b101001;
constexpr uint64_t literal_0b101010 = 0b101010;
constexpr uint64_t literal_0b100101 = 0b100101;
constexpr uint64_t literal_0b100110 = 0b100110;
constexpr uint64_t literal_0b101101 = 0b101101;
constexpr uint64_t literal_0b01 = 0b01;
constexpr uint64_t literal_0b0000011 = 0b0000011;
constexpr uint64_t literal_0b0000000 = 0b0000000;
constexpr uint64_t literal_0b011 = 0b011;
constexpr uint64_t literal_0b00011000010 = 0b00011000010;
constexpr uint64_t literal_0b0001100000 = 0b0001100000;
constexpr uint64_t literal_0b0001000000 = 0b0001000000;
constexpr uint64_t literal_0b0000110000 = 0b0000110000;
constexpr uint64_t literal_0b0000100000 = 0b0000100000;
constexpr uint64_t literal_0b00100 = 0b00100;
constexpr uint64_t literal_0b00101 = 0b00101;
constexpr uint64_t literal_0b00011 = 0b00011;
constexpr uint64_t literal_0b00110 = 0b00110;
constexpr uint64_t literal_0b00111 = 0b00111;
constexpr uint64_t literal_0b11100 = 0b11100;
constexpr uint64_t literal_0b01100 = 0b01100;
constexpr uint64_t literal_0b01000 = 0b01000;
constexpr uint64_t literal_0b11001 = 0b11001;
constexpr uint64_t literal_0b01111 = 0b01111;
constexpr uint64_t literal_0b01101 = 0b01101;
constexpr uint64_t literal_0b10111 = 0b10111;
constexpr uint64_t literal_0b10100 = 0b10100;
constexpr uint64_t literal_0b10110 = 0b10110;
constexpr uint64_t literal_0b10000 = 0b10000;
constexpr uint64_t literal_0b0000000011 = 0b0000000011;
constexpr uint64_t literal_48 = 48;
constexpr uint64_t literal_32 = 32;
constexpr uint64_t literal_0x6591B48421021400 = 0x6591B48421021400;
constexpr uint64_t literal_0b00000000000000000000000000000000000000000000000000000 =
    0b00000000000000000000000000000000000000000000000000000;
constexpr uint64_t literal_0b001 = 0b001;
constexpr uint64_t literal_0x1111111111111111 = 0x1111111111111111;
constexpr uint64_t literal_0x2222222222222222 = 0x2222222222222222;
constexpr uint64_t literal_0x3333333333333333 = 0x3333333333333333;
constexpr uint64_t literal_0x4444444444444444 = 0x4444444444444444;
constexpr uint64_t literal_0x5555555555555555 = 0x5555555555555555;
constexpr uint64_t literal_0x6666666666666666 = 0x6666666666666666;
constexpr uint64_t literal_0x7777777777777777 = 0x7777777777777777;
constexpr uint64_t literal_0x8888888888888888 = 0x8888888888888888;
constexpr uint64_t literal_0x9999999999999999 = 0x9999999999999999;
constexpr uint64_t literal_0xAAAAAAAAAAAAAAAA = 0xAAAAAAAAAAAAAAAA;
constexpr uint64_t literal_14 = 14;
constexpr uint64_t literal_0b001001 = 0b001001;
constexpr uint64_t literal_0b000110 = 0b000110;
constexpr uint64_t literal_0b001010 = 0b001010;
constexpr uint64_t literal_0b001000 = 0b001000;
constexpr uint64_t literal_0b000111 = 0b000111;
constexpr uint64_t literal_0b000100 = 0b000100;
constexpr uint64_t literal_0b001011 = 0b001011;
constexpr uint64_t literal_0b000010 = 0b000010;
constexpr uint64_t literal_0b100011 = 0b100011;
constexpr uint64_t literal_0b0000000000000000 = 0b0000000000000000;
constexpr uint64_t literal_0x000000000 = 0x000000000;
constexpr uint64_t literal_0b00000000000000000000000000 = 0b00000000000000000000000000;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_0x00000 = 0x00000;
constexpr uint64_t literal_0xFFFFF = 0xFFFFF;
constexpr uint64_t literal_0xFFF = 0xFFF;
constexpr uint64_t literal_28 = 28;
constexpr uint64_t literal_25 = 25;
constexpr uint64_t literal_26 = 26;
constexpr uint64_t literal_27 = 27;
constexpr uint64_t literal_0x00F = 0x00F;
constexpr uint64_t literal_24 = 24;
constexpr uint64_t literal_0x07F = 0x07F;
constexpr uint64_t literal_0x1FF = 0x1FF;
constexpr uint64_t literal_0x000 = 0x000;
constexpr uint64_t literal_0x0FF = 0x0FF;
constexpr uint64_t literal_0x7FF = 0x7FF;
constexpr uint64_t literal_0x003 = 0x003;
constexpr uint64_t literal_0x03F = 0x03F;
constexpr uint64_t literal_0x001 = 0x001;
constexpr uint64_t literal_0x01F = 0x01F;
constexpr uint64_t literal_0x007 = 0x007;
constexpr uint64_t literal_0x3FF = 0x3FF;
constexpr uint64_t literal_0x00000000 = 0x00000000;
constexpr uint64_t literal_0b00000000000011 = 0b00000000000011;

fapi2::ReturnCode centaur_mba_scom(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& TGT0,
                                   const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT1, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT1, l_chip_ec));
        fapi2::ATTR_CEN_EFF_DIMM_TYPE_Type l_TGT0_ATTR_CEN_EFF_DIMM_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, TGT0, l_TGT0_ATTR_CEN_EFF_DIMM_TYPE));
        uint64_t l_def_RDODT_duration = literal_5;
        fapi2::ATTR_CEN_EFF_DRAM_CWL_Type l_TGT0_ATTR_CEN_EFF_DRAM_CWL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CWL, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_CWL));
        fapi2::ATTR_CEN_EFF_DRAM_CL_Type l_TGT0_ATTR_CEN_EFF_DRAM_CL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CL, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_CL));
        uint64_t l_def_RDODT_start_lrdimm = ((l_TGT0_ATTR_CEN_EFF_DRAM_CL - l_TGT0_ATTR_CEN_EFF_DRAM_CWL) + literal_6);
        uint64_t l_def_RDODT_start_udimm = (l_TGT0_ATTR_CEN_EFF_DRAM_CL - l_TGT0_ATTR_CEN_EFF_DRAM_CWL);
        uint64_t l_def_RDODT_start_rdimm = (l_TGT0_ATTR_CEN_EFF_DRAM_CL - l_TGT0_ATTR_CEN_EFF_DRAM_CWL);
        fapi2::ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED_Type l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED, TGT0, l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED));
        fapi2::ATTR_CEN_EFF_DRAM_TRP_Type l_TGT0_ATTR_CEN_EFF_DRAM_TRP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRP, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_TRP));
        fapi2::ATTR_CEN_EFF_DRAM_TRCD_Type l_TGT0_ATTR_CEN_EFF_DRAM_TRCD;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRCD, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_TRCD));
        fapi2::ATTR_CEN_MSS_FREQ_Type l_TGT1_ATTR_CEN_MSS_FREQ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, TGT1, l_TGT1_ATTR_CEN_MSS_FREQ));
        fapi2::ATTR_CEN_EFF_DRAM_GEN_Type l_TGT0_ATTR_CEN_EFF_DRAM_GEN;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_GEN));
        uint64_t l_def_ddr3_1333_8_8_8_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_8))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_8))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1066_6_6_6R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_6))
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_6)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_6))
                                            && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr3_1066_7_7_7_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_7))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_7)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_7))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly14 = ((l_def_ddr3_1066_7_7_7_2N || l_def_ddr3_1066_6_6_6R)
                || l_def_ddr3_1333_8_8_8_2N);
        uint64_t l_def_margin_rdtag = literal_4;
        uint64_t l_def_ddr4_1600_9_9_9_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_1866_11_11_11 = ((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                               && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                             && (((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
                                                     || ((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))));
        uint64_t l_def_ddr4_1600_11_11_11 = ((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                               && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                             && (((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
                                                     || ((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))));
        uint64_t l_def_ddr3_1333_9_9_9_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1600_9_9_9_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1866_12_12_12_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1866_11_11_11 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1600_11_11_11 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1066_8_8_8_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_8))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_8))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly20 = ((((((((l_def_ddr3_1066_8_8_8_LR || l_def_ddr3_1600_11_11_11)
                || l_def_ddr3_1866_11_11_11) || l_def_ddr3_1866_12_12_12_2N) || l_def_ddr3_1600_9_9_9_LR) || l_def_ddr3_1333_9_9_9_L2)
                || l_def_ddr4_1600_11_11_11) || l_def_ddr4_1866_11_11_11) || l_def_ddr4_1600_9_9_9_LR);
        uint64_t l_def_ddr4_2133_12_12_12_L2 = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_1866_12_12_12_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_2133_13_13_13R = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_2400_14_14_14 = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr3_1866_12_12_12_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_1600_12_12_12_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_1866_13_13_13R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_13))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_13)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_13))
                                               && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr4_1600_13_12_11R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_13))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                               && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly25 = (((((((l_def_ddr4_1600_13_12_11R || l_def_ddr4_1866_13_13_13R)
                || l_def_ddr4_1600_12_12_12_L2) || l_def_ddr3_1866_12_12_12_L2) || l_def_ddr4_2400_14_14_14)
                || l_def_ddr4_2133_13_13_13R) || l_def_ddr4_1866_12_12_12_L2) || l_def_ddr4_2133_12_12_12_L2);
        uint64_t l_def_ddr4_1600_9_9_9_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1600_9_9_9_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1333_8_8_8 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                               && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_8))
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_8))
                                           && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1066_8_8_8_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_8))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_8))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1066_7_7_7 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                               && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_7))
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_7)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_7))
                                           && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly15 = ((((l_def_ddr3_1066_7_7_7 || l_def_ddr3_1066_8_8_8_2N)
                || l_def_ddr3_1333_8_8_8) || l_def_ddr3_1600_9_9_9_2N) || l_def_ddr4_1600_9_9_9_2N);
        uint64_t l_def_ddr4_2400_14_14_14_L2 = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_2133_13_13_13_LR = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_1866_13_13_13_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_13))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_13)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_13))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_1600_13_12_11_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_13))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly28 = (((l_def_ddr4_1600_13_12_11_LR || l_def_ddr4_1866_13_13_13_LR)
                || l_def_ddr4_2133_13_13_13_LR) || l_def_ddr4_2400_14_14_14_L2);
        uint64_t l_def_ddr3_1066_6_6_6 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                               && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_6))
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_6)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_6))
                                           && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly13 = l_def_ddr3_1066_6_6_6;
        uint64_t l_def_ddr4_1600_9_9_9 = ((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                              && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                          && (((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
                                              || ((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))));
        uint64_t l_def_ddr3_1333_8_8_8R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_8))
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_8))
                                            && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr3_1600_10_10_10_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_10))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_10)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_10))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1333_9_9_9_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1600_9_9_9 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                               && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                           && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1066_6_6_6_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_6))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_6)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_6))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1066_7_7_7R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_7))
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_7)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_7))
                                            && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr3_1066_8_8_8 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                               && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_8))
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_8))
                                           && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly16 = (((((((l_def_ddr3_1066_8_8_8 || l_def_ddr3_1066_7_7_7R)
                || l_def_ddr3_1066_6_6_6_L2) || l_def_ddr3_1600_9_9_9) || l_def_ddr3_1333_9_9_9_2N) || l_def_ddr3_1600_10_10_10_2N)
                || l_def_ddr3_1333_8_8_8R) || l_def_ddr4_1600_9_9_9);
        uint64_t l_def_ddr4_2400_14_14_14_LR = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly29 = l_def_ddr4_2400_14_14_14_LR;
        uint64_t l_def_ddr4_2400_13_13_13_L2 = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_2133_12_12_12_LR = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_1866_12_12_12_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_2400_14_14_14R = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr3_1866_12_12_12_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_1600_12_12_12_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly26 = (((((l_def_ddr4_1600_12_12_12_LR || l_def_ddr3_1866_12_12_12_LR)
                || l_def_ddr4_2400_14_14_14R) || l_def_ddr4_1866_12_12_12_LR) || l_def_ddr4_2133_12_12_12_LR)
                || l_def_ddr4_2400_13_13_13_L2);
        uint64_t l_def_ddr4_1600_10_10_10 = ((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_10))
                                               && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_10)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_10))
                                             && (((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
                                                     || ((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))));
        uint64_t l_def_ddr3_1333_8_8_8_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_8))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_8))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1333_9_9_9R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                            && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr3_1866_11_11_11_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1600_11_11_11_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1600_10_10_10 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_10))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_10)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_10))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1066_7_7_7_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_7))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_7)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_7))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly18 = ((((((l_def_ddr3_1066_7_7_7_L2 || l_def_ddr3_1600_10_10_10)
                || l_def_ddr3_1600_11_11_11_2N) || l_def_ddr3_1866_11_11_11_2N) || l_def_ddr3_1333_9_9_9R) || l_def_ddr3_1333_8_8_8_L2)
                || l_def_ddr4_1600_10_10_10);
        uint64_t l_def_ddr4_1866_11_11_11_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_1600_11_11_11_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_2400_13_13_13R = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_2400_14_14_14_2N = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_2133_13_13_13 = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr3_1866_11_11_11_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1600_11_11_11_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_1866_13_13_13 = ((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_13))
                                               && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_13)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_13))
                                             && (((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
                                                     || ((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly24 = (((((((l_def_ddr4_1866_13_13_13 || l_def_ddr3_1600_11_11_11_LR)
                || l_def_ddr3_1866_11_11_11_LR) || l_def_ddr4_2133_13_13_13) || l_def_ddr4_2400_14_14_14_2N)
                || l_def_ddr4_2400_13_13_13R) || l_def_ddr4_1600_11_11_11_LR) || l_def_ddr4_1866_11_11_11_LR);
        uint64_t l_def_ddr4_1866_11_11_11_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_1600_11_11_11_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_2133_12_12_12R = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_1866_12_12_12R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                               && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr4_2133_13_13_13_2N = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_2400_13_13_13 = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr3_1866_11_11_11_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1600_11_11_11_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1866_12_12_12R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                               && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr4_1600_12_12_12R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                               && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr4_1866_13_13_13_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_13))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_13)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_13))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr4_1600_13_12_11 = ((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_13))
                                               && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                             && (((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
                                                     || ((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly23 = (((((((((((l_def_ddr4_1600_13_12_11 || l_def_ddr4_1866_13_13_13_2N)
                || l_def_ddr4_1600_12_12_12R) || l_def_ddr3_1866_12_12_12R) || l_def_ddr3_1600_11_11_11_L2)
                || l_def_ddr3_1866_11_11_11_L2) || l_def_ddr4_2400_13_13_13) || l_def_ddr4_2133_13_13_13_2N)
                || l_def_ddr4_1866_12_12_12R) || l_def_ddr4_2133_12_12_12R) || l_def_ddr4_1600_11_11_11_L2)
                || l_def_ddr4_1866_11_11_11_L2);
        uint64_t l_def_ddr4_1600_11_11_11R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                               && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr4_1600_10_10_10_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_10))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_10)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_10))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_2400_13_13_13_2N = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_2133_12_12_12 = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_1866_12_12_12 = ((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                               && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                             && (((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
                                                     || ((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))));
        uint64_t l_def_ddr3_1600_10_10_10_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_10))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_10)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_10))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1866_12_12_12 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr4_1600_12_12_12 = ((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                               && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                             && (((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
                                                     || ((l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))));
        uint64_t l_def_ddr4_1600_13_12_11_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_13))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly22 = ((((((((l_def_ddr4_1600_13_12_11_2N || l_def_ddr4_1600_12_12_12)
                || l_def_ddr3_1866_12_12_12) || l_def_ddr3_1600_10_10_10_LR) || l_def_ddr4_1866_12_12_12) || l_def_ddr4_2133_12_12_12)
                || l_def_ddr4_2400_13_13_13_2N) || l_def_ddr4_1600_10_10_10_LR) || l_def_ddr4_1600_11_11_11R);
        uint64_t l_def_ddr4_1600_9_9_9R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                            && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr4_1600_10_10_10_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_10))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_10)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_10))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1600_9_9_9R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                            && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr3_1333_9_9_9 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                               && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                           && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1066_6_6_6_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_6))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_6)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_6))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1066_8_8_8R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_8))
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_8))
                                            && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly17 = (((((l_def_ddr3_1066_8_8_8R || l_def_ddr3_1066_6_6_6_LR)
                || l_def_ddr3_1333_9_9_9) || l_def_ddr3_1600_9_9_9R) || l_def_ddr4_1600_10_10_10_2N) || l_def_ddr4_1600_9_9_9R);
        uint64_t l_def_ddr3_1066_6_6_6_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_6))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_6)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_6))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly12 = l_def_ddr3_1066_6_6_6_2N;
        uint64_t l_def_ddr4_1600_10_10_10_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_10))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_10)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_10))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_1866_11_11_11R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                               && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr4_2133_12_12_12_2N = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_1866_12_12_12_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1600_10_10_10_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_10))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_10)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_10))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1333_9_9_9_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1866_11_11_11R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                               && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr3_1600_11_11_11R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                               && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr4_1600_12_12_12_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_12))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_12))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly21 = ((((((((l_def_ddr4_1600_12_12_12_2N || l_def_ddr3_1600_11_11_11R)
                || l_def_ddr3_1866_11_11_11R) || l_def_ddr3_1333_9_9_9_LR) || l_def_ddr3_1600_10_10_10_L2)
                || l_def_ddr4_1866_12_12_12_2N) || l_def_ddr4_2133_12_12_12_2N) || l_def_ddr4_1866_11_11_11R)
                || l_def_ddr4_1600_10_10_10_L2);
        uint64_t l_def_ddr4_1600_9_9_9_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_1600_10_10_10R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_10))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_10)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_10))
                                               && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr4_1866_11_11_11_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr4_1600_11_11_11_2N = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_11))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_11)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2));
        uint64_t l_def_ddr3_1600_9_9_9_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_9))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_9)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_9))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1333_8_8_8_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_8))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_8))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1600_10_10_10R = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_10))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_10)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_10))
                                               && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1));
        uint64_t l_def_ddr3_1066_8_8_8_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_8))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_8))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr3_1066_7_7_7_LR = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_7))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_7)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_7))
                                              && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_0)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly19 = ((((((((l_def_ddr3_1066_7_7_7_LR || l_def_ddr3_1066_8_8_8_L2)
                || l_def_ddr3_1600_10_10_10R) || l_def_ddr3_1333_8_8_8_LR) || l_def_ddr3_1600_9_9_9_L2) || l_def_ddr4_1600_11_11_11_2N)
                || l_def_ddr4_1866_11_11_11_2N) || l_def_ddr4_1600_10_10_10R) || l_def_ddr4_1600_9_9_9_L2);
        uint64_t l_def_ddr4_2133_13_13_13_L2 = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_2400_13_13_13_LR = (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1400);
        uint64_t l_def_ddr4_1866_13_13_13_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_13))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_13)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_13))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_ddr4_1600_13_12_11_L2 = (((((((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2)
                                                && (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)) && (l_TGT0_ATTR_CEN_EFF_DRAM_CL == literal_13))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD == literal_12)) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP == literal_11))
                                                && (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_mba_dsm0q_cfg_rdtag_dly27 = (((l_def_ddr4_1600_13_12_11_L2 || l_def_ddr4_1866_13_13_13_L2)
                || l_def_ddr4_2400_13_13_13_LR) || l_def_ddr4_2133_13_13_13_L2);
        uint64_t l_def_WL_AL_MINUS2 = (((l_TGT0_ATTR_CEN_EFF_DRAM_CWL + l_TGT0_ATTR_CEN_EFF_DRAM_CL) - literal_2) - literal_7);
        fapi2::ATTR_CEN_EFF_DRAM_AL_Type l_TGT0_ATTR_CEN_EFF_DRAM_AL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_AL, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_AL));
        uint64_t l_def_WL_AL_MINUS1 = (((l_TGT0_ATTR_CEN_EFF_DRAM_CWL + l_TGT0_ATTR_CEN_EFF_DRAM_CL) - literal_1) - literal_7);
        uint64_t l_def_WL_AL0 = (l_TGT0_ATTR_CEN_EFF_DRAM_CWL - literal_7);
        fapi2::ATTR_CEN_VPD_WLO_Type l_TGT0_ATTR_CEN_VPD_WLO;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_WLO, TGT0, l_TGT0_ATTR_CEN_VPD_WLO));
        uint64_t l_def_WLO = ((l_TGT0_ATTR_CEN_VPD_WLO[literal_0] & literal_0x07) - (((l_TGT0_ATTR_CEN_VPD_WLO[literal_0] &
                              literal_0x0F) >> literal_3) * literal_8));
        uint64_t l_def_margin2 = literal_0;
        fapi2::ATTR_CEN_EFF_DRAM_TRRD_Type l_TGT0_ATTR_CEN_EFF_DRAM_TRRD;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRRD, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_TRRD));
        fapi2::ATTR_CEN_EFF_STACK_TYPE_Type l_TGT0_ATTR_CEN_EFF_STACK_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, TGT0, l_TGT0_ATTR_CEN_EFF_STACK_TYPE));
        fapi2::ATTR_CHIP_UNIT_POS_Type l_TGT0_ATTR_CHIP_UNIT_POS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, TGT0, l_TGT0_ATTR_CHIP_UNIT_POS));
        uint64_t l_def_mba_tmr0q_WRSM_dlys23 = ((((l_def_ddr3_1333_8_8_8 || l_def_ddr3_1333_8_8_8_2N)
                                                || l_def_ddr3_1333_8_8_8R) || l_def_ddr3_1333_8_8_8_LR) || l_def_ddr3_1333_8_8_8_L2);
        uint64_t l_def_ddr3_1066_8_8_8_group = ((((l_def_ddr3_1066_8_8_8 || l_def_ddr3_1066_8_8_8_2N)
                                                || l_def_ddr3_1066_8_8_8R) || l_def_ddr3_1066_8_8_8_LR) || l_def_ddr3_1066_8_8_8_L2);
        uint64_t l_def_mba_tmr0q_WRSM_dlys21 = l_def_ddr3_1066_8_8_8_group;
        uint64_t l_def_mba_tmr0q_WRSM_dlys30 = ((((l_def_ddr4_2133_12_12_12 || l_def_ddr4_2133_12_12_12_2N)
                                                || l_def_ddr4_2133_12_12_12R) || l_def_ddr4_2133_12_12_12_LR) || l_def_ddr4_2133_12_12_12_L2);
        uint64_t l_def_mba_tmr0q_WRSM_dlys28 = ((((((((((((((l_def_ddr4_1600_12_12_12 || l_def_ddr4_1600_12_12_12_2N)
                                                || l_def_ddr4_1600_12_12_12R) || l_def_ddr4_1600_12_12_12_LR) || l_def_ddr4_1600_12_12_12_L2)
                                                || l_def_ddr3_1600_11_11_11) || l_def_ddr3_1600_11_11_11_2N) || l_def_ddr3_1600_11_11_11R)
                                                || l_def_ddr3_1600_11_11_11_LR) || l_def_ddr3_1600_11_11_11_L2) || l_def_ddr4_1866_11_11_11)
                                                || l_def_ddr4_1866_11_11_11_2N) || l_def_ddr4_1866_11_11_11R) || l_def_ddr4_1866_11_11_11_LR)
                                                || l_def_ddr4_1866_11_11_11_L2);
        uint64_t l_def_mba_tmr0q_WRSM_dlys29 = ((((l_def_ddr4_1866_12_12_12 || l_def_ddr4_1866_12_12_12_2N)
                                                || l_def_ddr4_1866_12_12_12R) || l_def_ddr4_1866_12_12_12_LR) || l_def_ddr4_1866_12_12_12_L2);
        uint64_t l_def_mba_tmr0q_WRSM_dlys33 = ((((l_def_ddr4_2400_14_14_14 || l_def_ddr4_2400_14_14_14_2N)
                                                || l_def_ddr4_2400_14_14_14R) || l_def_ddr4_2400_14_14_14_LR) || l_def_ddr4_2400_14_14_14_L2);
        uint64_t l_def_mba_tmr0q_WRSM_dlys27 = ((((l_def_ddr3_1600_10_10_10 || l_def_ddr3_1600_10_10_10_2N)
                                                || l_def_ddr3_1600_10_10_10R) || l_def_ddr3_1600_10_10_10_LR) || l_def_ddr3_1600_10_10_10_L2);
        uint64_t l_def_mba_tmr0q_WRSM_dlys15 = ((((((l_def_ddr4_1600_11_11_11 || l_def_ddr4_1600_11_11_11_2N)
                                                || l_def_ddr4_1600_11_11_11R) || l_def_ddr4_1600_11_11_11_LR) || l_def_ddr4_1600_11_11_11_L2)
                                                || l_def_ddr4_1600_13_12_11) || l_def_ddr4_1600_13_12_11_2N);
        uint64_t l_def_mba_tmr0q_WRSM_dlys32 = ((((((((((((((l_def_ddr4_1866_13_13_13 || l_def_ddr4_1866_13_13_13_2N)
                                                || l_def_ddr4_1866_13_13_13R) || l_def_ddr4_1866_13_13_13_LR) || l_def_ddr4_1866_13_13_13_L2)
                                                || l_def_ddr3_1866_12_12_12) || l_def_ddr3_1866_12_12_12_2N) || l_def_ddr3_1866_12_12_12R)
                                                || l_def_ddr3_1866_12_12_12_LR) || l_def_ddr3_1866_12_12_12_L2) || l_def_ddr4_2400_13_13_13)
                                                || l_def_ddr4_2400_13_13_13_2N) || l_def_ddr4_2400_13_13_13R) || l_def_ddr4_2400_13_13_13_LR)
                                                || l_def_ddr4_2400_13_13_13_L2);
        uint64_t l_def_mba_tmr0q_WRSM_dlys31 = (((((((((l_def_ddr3_1866_11_11_11 || l_def_ddr3_1866_11_11_11_2N)
                                                || l_def_ddr3_1866_11_11_11R) || l_def_ddr3_1866_11_11_11_LR) || l_def_ddr3_1866_11_11_11_L2)
                                                || l_def_ddr4_2133_13_13_13) || l_def_ddr4_2133_13_13_13_2N) || l_def_ddr4_2133_13_13_13R)
                                                || l_def_ddr4_2133_13_13_13_LR) || l_def_ddr4_2133_13_13_13_L2);
        uint64_t l_def_ddr3_1066_6_6_6_group = ((((l_def_ddr3_1066_6_6_6 || l_def_ddr3_1066_6_6_6_2N)
                                                || l_def_ddr3_1066_6_6_6R) || l_def_ddr3_1066_6_6_6_LR) || l_def_ddr3_1066_6_6_6_L2);
        uint64_t l_def_mba_tmr0q_WRSM_dlys19 = l_def_ddr3_1066_6_6_6_group;
        uint64_t l_def_ddr3_1066_7_7_7_group = ((((l_def_ddr3_1066_7_7_7 || l_def_ddr3_1066_7_7_7_2N)
                                                || l_def_ddr3_1066_7_7_7R) || l_def_ddr3_1066_7_7_7_LR) || l_def_ddr3_1066_7_7_7_L2);
        uint64_t l_def_mba_tmr0q_WRSM_dlys20 = l_def_ddr3_1066_7_7_7_group;
        uint64_t l_def_mba_tmr0q_WRSM_dlys25 = ((((l_def_ddr4_1600_9_9_9 || l_def_ddr4_1600_9_9_9_2N)
                                                || l_def_ddr4_1600_9_9_9R) || l_def_ddr4_1600_9_9_9_LR) || l_def_ddr4_1600_9_9_9_L2);
        uint64_t l_def_mba_tmr0q_WRSM_dlys26 = (((((((((l_def_ddr3_1600_9_9_9 || l_def_ddr3_1600_9_9_9_2N)
                                                || l_def_ddr3_1600_9_9_9R) || l_def_ddr3_1600_9_9_9_LR) || l_def_ddr3_1600_9_9_9_L2) || l_def_ddr4_1600_10_10_10)
                                                || l_def_ddr4_1600_10_10_10_2N) || l_def_ddr4_1600_10_10_10R) || l_def_ddr4_1600_10_10_10_LR)
                                                || l_def_ddr4_1600_10_10_10_L2);
        uint64_t l_def_mba_tmr0q_WRSM_dlys24 = ((((l_def_ddr3_1333_9_9_9 || l_def_ddr3_1333_9_9_9_2N)
                                                || l_def_ddr3_1333_9_9_9R) || l_def_ddr3_1333_9_9_9_LR) || l_def_ddr3_1333_9_9_9_L2);
        uint64_t l_def_mba_tmr0q_RW_dlys11 = (((((((((((((l_def_ddr4_1600_13_12_11 || l_def_ddr4_1866_13_13_13)
                                                || l_def_ddr4_1866_13_13_13_2N) || l_def_ddr4_1866_13_13_13R) || l_def_ddr3_1066_6_6_6_L2) || l_def_ddr3_1066_6_6_6_LR)
                                                || l_def_ddr3_1866_12_12_12) || l_def_ddr3_1866_12_12_12_2N) || l_def_ddr3_1866_12_12_12R) || l_def_ddr4_2400_14_14_14)
                                                || l_def_ddr4_2400_14_14_14_2N) || l_def_ddr4_2400_14_14_14R) || l_def_ddr4_1600_9_9_9_LR) || l_def_ddr4_1600_9_9_9_L2);
        uint64_t l_def_margin1 = literal_1;
        uint64_t l_def_mba_tmr0q_RW_dlys8 = (((((((((((l_def_ddr3_1066_7_7_7 || l_def_ddr3_1066_7_7_7_2N)
                                                || l_def_ddr3_1066_7_7_7R) || l_def_ddr3_1333_8_8_8) || l_def_ddr3_1600_9_9_9) || l_def_ddr3_1333_8_8_8_2N)
                                                || l_def_ddr3_1600_9_9_9_2N) || l_def_ddr3_1333_8_8_8R) || l_def_ddr3_1600_9_9_9R) || l_def_ddr4_1600_10_10_10)
                                              || l_def_ddr4_1600_10_10_10_2N) || l_def_ddr4_1600_10_10_10R);
        uint64_t l_def_mba_tmr0q_RW_dlys7 = (((((l_def_ddr3_1066_6_6_6 || l_def_ddr3_1066_6_6_6_2N) || l_def_ddr3_1066_6_6_6R)
                                               || l_def_ddr4_1600_9_9_9) || l_def_ddr4_1600_9_9_9_2N) || l_def_ddr4_1600_9_9_9R);
        uint64_t l_def_mba_tmr0q_RW_dlys15 = (((((l_def_ddr4_1600_13_12_11_LR || l_def_ddr4_1600_13_12_11_L2)
                                                || l_def_ddr4_1866_13_13_13_LR) || l_def_ddr4_1866_13_13_13_L2) || l_def_ddr4_2400_14_14_14_LR)
                                              || l_def_ddr4_2400_14_14_14_L2);
        uint64_t l_def_mba_tmr0q_RW_dlys10 = (((((((((((((((((l_def_ddr4_1600_12_12_12 || l_def_ddr4_1600_12_12_12_2N)
                                                || l_def_ddr4_1600_12_12_12R) || l_def_ddr4_2133_13_13_13R) || l_def_ddr4_2133_13_13_13_2N)
                                                || l_def_ddr4_2133_13_13_13) || l_def_ddr3_1600_11_11_11) || l_def_ddr3_1866_11_11_11) || l_def_ddr3_1600_11_11_11_2N)
                                                || l_def_ddr3_1866_11_11_11_2N) || l_def_ddr3_1600_11_11_11R) || l_def_ddr3_1866_11_11_11R)
                                                || l_def_ddr4_1866_12_12_12) || l_def_ddr4_2400_13_13_13) || l_def_ddr4_1866_12_12_12_2N)
                                                || l_def_ddr4_2400_13_13_13_2N) || l_def_ddr4_1866_12_12_12R) || l_def_ddr4_2400_13_13_13R);
        uint64_t l_def_mba_tmr0q_RW_dlys13 = ((((((((((l_def_ddr3_1066_8_8_8_L2 || l_def_ddr3_1066_8_8_8_LR)
                                                || l_def_ddr3_1333_9_9_9_L2) || l_def_ddr3_1600_10_10_10_L2) || l_def_ddr3_1866_11_11_11_L2)
                                                || l_def_ddr4_1600_11_11_11_LR) || l_def_ddr4_1866_11_11_11_LR) || l_def_ddr4_2133_12_12_12_LR)
                                                || l_def_ddr4_1600_11_11_11_L2) || l_def_ddr4_1866_11_11_11_L2) || l_def_ddr4_2133_12_12_12_L2);
        uint64_t l_def_mba_tmr0q_RW_dlys14 = ((((((((((((((l_def_ddr4_1600_12_12_12_LR || l_def_ddr4_1600_12_12_12_L2)
                                                || l_def_ddr4_2133_13_13_13_L2) || l_def_ddr4_2133_13_13_13_LR) || l_def_ddr3_1600_11_11_11_LR)
                                                || l_def_ddr3_1866_12_12_12_LR) || l_def_ddr3_1600_11_11_11_L2) || l_def_ddr3_1866_12_12_12_L2)
                                                || l_def_ddr4_1866_12_12_12_LR) || l_def_ddr4_2400_13_13_13_LR) || l_def_ddr4_1866_12_12_12_L2)
                                                || l_def_ddr4_2400_13_13_13_L2) || l_def_ddr3_1333_9_9_9_LR) || l_def_ddr3_1600_10_10_10_LR)
                                              || l_def_ddr3_1866_11_11_11_LR);
        uint64_t l_def_mba_tmr0q_RW_dlys16 = (l_def_ddr4_1600_13_12_11_LR || l_def_ddr4_1600_13_12_11_L2);
        uint64_t l_def_mba_tmr0q_RW_dlys9 = (((((((((((((((((l_def_ddr3_1066_8_8_8 || l_def_ddr3_1066_8_8_8_2N)
                                                || l_def_ddr3_1066_8_8_8R) || l_def_ddr3_1333_9_9_9) || l_def_ddr3_1600_10_10_10) || l_def_ddr3_1333_9_9_9_2N)
                                                || l_def_ddr3_1600_10_10_10_2N) || l_def_ddr3_1333_9_9_9R) || l_def_ddr3_1600_10_10_10R) || l_def_ddr4_1600_11_11_11)
                                                || l_def_ddr4_1866_11_11_11) || l_def_ddr4_2133_12_12_12) || l_def_ddr4_1600_11_11_11_2N)
                                                || l_def_ddr4_1866_11_11_11_2N) || l_def_ddr4_2133_12_12_12_2N) || l_def_ddr4_1600_11_11_11R)
                                              || l_def_ddr4_1866_11_11_11R) || l_def_ddr4_2133_12_12_12R);
        uint64_t l_def_mba_tmr0q_RW_dlys12 = (((((((((l_def_ddr4_1600_13_12_11_2N || l_def_ddr4_1600_13_12_11R)
                                                || l_def_ddr3_1066_7_7_7_L2) || l_def_ddr3_1066_7_7_7_LR) || l_def_ddr3_1333_8_8_8_LR) || l_def_ddr3_1600_9_9_9_LR)
                                                || l_def_ddr3_1333_8_8_8_L2) || l_def_ddr3_1600_9_9_9_L2) || l_def_ddr4_1600_10_10_10_LR)
                                              || l_def_ddr4_1600_10_10_10_L2);
        uint64_t l_def_mba_tmr0q_WRDM_dlys7 = ((((((((((((((((((((l_def_ddr3_1066_6_6_6_group || l_def_ddr4_1600_9_9_9)
                                                || l_def_ddr4_1866_11_11_11) || l_def_ddr4_2133_12_12_12) || l_def_ddr4_2400_14_14_14) || l_def_ddr4_1600_9_9_9_2N)
                                                || l_def_ddr4_1866_11_11_11_2N) || l_def_ddr4_2133_12_12_12_2N) || l_def_ddr4_2400_14_14_14_2N)
                                                || l_def_ddr4_1600_9_9_9R) || l_def_ddr4_1866_11_11_11R) || l_def_ddr4_2133_12_12_12R) || l_def_ddr4_2400_14_14_14R)
                                                || l_def_ddr4_1600_9_9_9_LR) || l_def_ddr4_1866_11_11_11_LR) || l_def_ddr4_2133_12_12_12_LR)
                                                || l_def_ddr4_2400_14_14_14_LR) || l_def_ddr4_1600_9_9_9_L2) || l_def_ddr4_1866_11_11_11_L2)
                                                || l_def_ddr4_2133_12_12_12_L2) || l_def_ddr4_2400_14_14_14_L2);
        uint64_t l_def_mba_tmr0q_WRDM_dlys8 = ((((l_def_ddr4_2400_13_13_13 || l_def_ddr4_2400_13_13_13_2N)
                                                || l_def_ddr4_2400_13_13_13R) || l_def_ddr4_2400_13_13_13_LR) || l_def_ddr4_2400_13_13_13_L2);
        uint64_t l_def_mba_tmr0q_WRDM_dlys4 = ((((((((((((((l_def_ddr4_1600_13_12_11 || l_def_ddr4_1600_13_12_11R)
                                                || l_def_ddr4_1600_13_12_11_2N) || l_def_ddr4_1600_13_12_11_L2) || l_def_ddr4_1600_13_12_11_LR)
                                                || l_def_ddr4_1600_12_12_12) || l_def_ddr4_1600_12_12_12_2N) || l_def_ddr4_1600_12_12_12R)
                                                || l_def_ddr4_1600_12_12_12_LR) || l_def_ddr4_1600_12_12_12_L2) || l_def_ddr3_1600_11_11_11)
                                                || l_def_ddr3_1600_11_11_11_2N) || l_def_ddr3_1600_11_11_11R) || l_def_ddr3_1600_11_11_11_LR)
                                               || l_def_ddr3_1600_11_11_11_L2);
        uint64_t l_def_mba_tmr0q_WRDM_dlys5 = (((((((((((((((((((((((((l_def_ddr4_1866_13_13_13 || l_def_ddr4_1866_13_13_13_2N)
                                                || l_def_ddr4_1866_13_13_13R) || l_def_ddr4_1866_13_13_13_LR) || l_def_ddr4_1866_13_13_13_L2)
                                                || l_def_ddr3_1066_8_8_8_group) || l_def_ddr3_1333_9_9_9) || l_def_ddr3_1600_10_10_10) || l_def_ddr3_1866_12_12_12)
                                                || l_def_ddr3_1333_9_9_9_2N) || l_def_ddr3_1600_10_10_10_2N) || l_def_ddr3_1866_12_12_12_2N) || l_def_ddr3_1333_9_9_9R)
                                                || l_def_ddr3_1600_10_10_10R) || l_def_ddr3_1866_12_12_12R) || l_def_ddr3_1333_9_9_9_LR)
                                                || l_def_ddr3_1600_10_10_10_LR) || l_def_ddr3_1866_12_12_12_LR) || l_def_ddr3_1333_9_9_9_L2)
                                                || l_def_ddr3_1600_10_10_10_L2) || l_def_ddr3_1866_12_12_12_L2) || l_def_ddr4_1600_11_11_11)
                                                || l_def_ddr4_1600_11_11_11_2N) || l_def_ddr4_1600_11_11_11R) || l_def_ddr4_1600_11_11_11_LR)
                                               || l_def_ddr4_1600_11_11_11_L2);
        uint64_t l_def_mba_tmr0q_WRDM_dlys6 = ((((((((((((((((((((((((((((((l_def_ddr3_1066_7_7_7_group
                                                || l_def_ddr3_1333_8_8_8) || l_def_ddr3_1600_9_9_9) || l_def_ddr3_1866_11_11_11) || l_def_ddr3_1333_8_8_8_2N)
                                                || l_def_ddr3_1600_9_9_9_2N) || l_def_ddr3_1866_11_11_11_2N) || l_def_ddr3_1333_8_8_8R) || l_def_ddr3_1600_9_9_9R)
                                                || l_def_ddr3_1866_11_11_11R) || l_def_ddr3_1333_8_8_8_LR) || l_def_ddr3_1600_9_9_9_LR) || l_def_ddr3_1866_11_11_11_LR)
                                                || l_def_ddr3_1333_8_8_8_L2) || l_def_ddr3_1600_9_9_9_L2) || l_def_ddr3_1866_11_11_11_L2) || l_def_ddr4_1600_10_10_10)
                                                || l_def_ddr4_1866_12_12_12) || l_def_ddr4_2133_13_13_13) || l_def_ddr4_1600_10_10_10_2N)
                                                || l_def_ddr4_1866_12_12_12_2N) || l_def_ddr4_2133_13_13_13_2N) || l_def_ddr4_1600_10_10_10R)
                                                || l_def_ddr4_1866_12_12_12R) || l_def_ddr4_2133_13_13_13R) || l_def_ddr4_1600_10_10_10_LR)
                                                || l_def_ddr4_1866_12_12_12_LR) || l_def_ddr4_2133_13_13_13_LR) || l_def_ddr4_1600_10_10_10_L2)
                                                || l_def_ddr4_1866_12_12_12_L2) || l_def_ddr4_2133_13_13_13_L2);
        uint64_t l_def_mba_tmr1q_cfg_trap43 = ((((l_def_ddr4_1866_11_11_11 || l_def_ddr4_1866_11_11_11_2N)
                                                || l_def_ddr4_1866_11_11_11R) || l_def_ddr4_1866_11_11_11_LR) || l_def_ddr4_1866_11_11_11_L2);
        uint64_t l_def_mba_tmr1q_cfg_trap27 = (((((l_def_ddr3_1066_7_7_7_group || l_def_ddr3_1333_8_8_8)
                                                || l_def_ddr3_1333_8_8_8_2N) || l_def_ddr3_1333_8_8_8R) || l_def_ddr3_1333_8_8_8_LR) || l_def_ddr3_1333_8_8_8_L2);
        uint64_t l_def_mba_tmr1q_cfg_trap26 = (((((l_def_ddr3_1066_6_6_6_group || l_def_ddr3_1333_8_8_8)
                                                || l_def_ddr3_1333_8_8_8_2N) || l_def_ddr3_1333_8_8_8R) || l_def_ddr3_1333_8_8_8_LR) || l_def_ddr3_1333_8_8_8_L2);
        uint64_t l_def_mba_tmr1q_cfg_trap46 = ((((l_def_ddr4_1866_13_13_13 || l_def_ddr4_1866_13_13_13_2N)
                                                || l_def_ddr4_1866_13_13_13R) || l_def_ddr4_1866_13_13_13_LR) || l_def_ddr4_1866_13_13_13_L2);
        uint64_t l_def_mba_tmr1q_cfg_trap42 = ((((l_def_ddr4_1600_12_12_12 || l_def_ddr4_1600_12_12_12_2N)
                                                || l_def_ddr4_1600_12_12_12R) || l_def_ddr4_1600_12_12_12_LR) || l_def_ddr4_1600_12_12_12_L2);
        uint64_t l_def_mba_tmr1q_cfg_trap38 = (((((((((l_def_ddr3_1600_10_10_10 || l_def_ddr3_1600_10_10_10_2N)
                                                || l_def_ddr3_1600_10_10_10R) || l_def_ddr3_1600_10_10_10_LR) || l_def_ddr3_1600_10_10_10_L2)
                                                || l_def_ddr4_1600_10_10_10) || l_def_ddr4_1600_10_10_10_2N) || l_def_ddr4_1600_10_10_10R)
                                                || l_def_ddr4_1600_10_10_10_LR) || l_def_ddr4_1600_10_10_10_L2);
        uint64_t l_def_mba_tmr1q_cfg_trap28 = (((((l_def_ddr3_1066_8_8_8_group || l_def_ddr3_1333_8_8_8)
                                                || l_def_ddr3_1333_8_8_8_2N) || l_def_ddr3_1333_8_8_8R) || l_def_ddr3_1333_8_8_8_LR) || l_def_ddr3_1333_8_8_8_L2);
        uint64_t l_def_mba_tmr1q_cfg_trap40 = ((((l_def_ddr3_1866_12_12_12 || l_def_ddr3_1866_12_12_12_2N)
                                                || l_def_ddr3_1866_12_12_12R) || l_def_ddr3_1866_12_12_12_LR) || l_def_ddr3_1866_12_12_12_L2);
        uint64_t l_def_mba_tmr1q_cfg_trap37 = (((((((((l_def_ddr3_1600_9_9_9 || l_def_ddr3_1600_9_9_9_2N)
                                                || l_def_ddr3_1600_9_9_9R) || l_def_ddr3_1600_9_9_9_LR) || l_def_ddr3_1600_9_9_9_L2) || l_def_ddr4_1600_9_9_9)
                                                || l_def_ddr4_1600_9_9_9_2N) || l_def_ddr4_1600_9_9_9R) || l_def_ddr4_1600_9_9_9_LR) || l_def_ddr4_1600_9_9_9_L2);
        uint64_t l_def_mba_tmr1q_cfg_trap32 = ((((l_def_ddr3_1333_8_8_8 || l_def_ddr3_1333_8_8_8_2N) || l_def_ddr3_1333_8_8_8R)
                                                || l_def_ddr3_1333_8_8_8_LR) || l_def_ddr3_1333_8_8_8_L2);
        uint64_t l_def_mba_tmr1q_cfg_trap33 = ((((l_def_ddr3_1333_9_9_9 || l_def_ddr3_1333_9_9_9_2N) || l_def_ddr3_1333_9_9_9R)
                                                || l_def_ddr3_1333_9_9_9_LR) || l_def_ddr3_1333_9_9_9_L2);
        uint64_t l_def_mba_tmr1q_cfg_trap44 = ((((l_def_ddr4_1866_12_12_12 || l_def_ddr4_1866_12_12_12_2N)
                                                || l_def_ddr4_1866_12_12_12R) || l_def_ddr4_1866_12_12_12_LR) || l_def_ddr4_1866_12_12_12_L2);
        uint64_t l_def_mba_tmr1q_cfg_trap39 = ((((((((((((((l_def_ddr3_1600_11_11_11 || l_def_ddr3_1866_11_11_11)
                                                || l_def_ddr3_1600_11_11_11_2N) || l_def_ddr3_1866_11_11_11_2N) || l_def_ddr3_1600_11_11_11R)
                                                || l_def_ddr3_1866_11_11_11R) || l_def_ddr3_1600_11_11_11_LR) || l_def_ddr3_1866_11_11_11_LR)
                                                || l_def_ddr3_1600_11_11_11_L2) || l_def_ddr3_1866_11_11_11_L2) || l_def_ddr4_1600_11_11_11)
                                                || l_def_ddr4_1600_11_11_11_2N) || l_def_ddr4_1600_11_11_11R) || l_def_ddr4_1600_11_11_11_LR)
                                               || l_def_ddr4_1600_11_11_11_L2);
        fapi2::ATTR_CEN_EFF_DRAM_TFAW_Type l_TGT0_ATTR_CEN_EFF_DRAM_TFAW;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TFAW, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_TFAW));
        uint64_t l_def_mba_tmr1q_RRSBG_dlys5 = ((((((((((((((((((((((((((((((((((l_def_ddr4_1600_12_12_12
                                                || l_def_ddr4_1600_12_12_12_2N) || l_def_ddr4_1600_12_12_12R) || l_def_ddr4_1600_12_12_12_LR)
                                                || l_def_ddr4_1600_12_12_12_L2) || l_def_ddr4_1866_13_13_13) || l_def_ddr4_1866_13_13_13_2N)
                                                || l_def_ddr4_1866_13_13_13R) || l_def_ddr4_1866_13_13_13_LR) || l_def_ddr4_1866_13_13_13_L2)
                                                || l_def_ddr4_1600_11_11_11) || l_def_ddr4_1600_11_11_11_2N) || l_def_ddr4_1600_11_11_11R)
                                                || l_def_ddr4_1600_11_11_11_LR) || l_def_ddr4_1600_11_11_11_L2) || l_def_ddr4_1600_10_10_10)
                                                || l_def_ddr4_1600_10_10_10_2N) || l_def_ddr4_1600_10_10_10R) || l_def_ddr4_1600_10_10_10_LR)
                                                || l_def_ddr4_1600_10_10_10_L2) || l_def_ddr4_1600_9_9_9) || l_def_ddr4_1600_9_9_9_2N) || l_def_ddr4_1600_9_9_9R)
                                                || l_def_ddr4_1600_9_9_9_LR) || l_def_ddr4_1600_9_9_9_L2) || l_def_ddr4_1866_12_12_12) || l_def_ddr4_1866_12_12_12_2N)
                                                || l_def_ddr4_1866_12_12_12R) || l_def_ddr4_1866_12_12_12_LR) || l_def_ddr4_1866_12_12_12_L2)
                                                || l_def_ddr4_1866_11_11_11) || l_def_ddr4_1866_11_11_11_2N) || l_def_ddr4_1866_11_11_11R)
                                                || l_def_ddr4_1866_11_11_11_LR) || l_def_ddr4_1866_11_11_11_L2);
        uint64_t l_def_mba_tmr1q_RRSBG_dlys6 = (((((((((((((((((((l_def_ddr4_2133_13_13_13 || l_def_ddr4_2133_13_13_13_2N)
                                                || l_def_ddr4_2133_13_13_13R) || l_def_ddr4_2133_13_13_13_LR) || l_def_ddr4_2133_13_13_13_L2)
                                                || l_def_ddr4_2133_12_12_12) || l_def_ddr4_2133_12_12_12_2N) || l_def_ddr4_2133_12_12_12R)
                                                || l_def_ddr4_2133_12_12_12_LR) || l_def_ddr4_2133_12_12_12_L2) || l_def_ddr4_2400_14_14_14)
                                                || l_def_ddr4_2400_14_14_14_2N) || l_def_ddr4_2400_14_14_14R) || l_def_ddr4_2400_14_14_14_LR)
                                                || l_def_ddr4_2400_14_14_14_L2) || l_def_ddr4_2400_13_13_13) || l_def_ddr4_2400_13_13_13_2N)
                                                || l_def_ddr4_2400_13_13_13R) || l_def_ddr4_2400_13_13_13_LR) || l_def_ddr4_2400_13_13_13_L2);
        uint64_t l_def_mba_tmr1q_RRSBG_dlys0 = (((((((((((((((((((((((((((((((((((((l_def_ddr3_1066_6_6_6_group
                                                || l_def_ddr3_1066_7_7_7_group) || l_def_ddr3_1066_8_8_8_group) || l_def_ddr3_1600_11_11_11)
                                                || l_def_ddr3_1600_11_11_11_2N) || l_def_ddr3_1600_11_11_11R) || l_def_ddr3_1600_11_11_11_LR)
                                                || l_def_ddr3_1600_11_11_11_L2) || l_def_ddr3_1333_9_9_9) || l_def_ddr3_1600_10_10_10) || l_def_ddr3_1333_9_9_9_2N)
                                                || l_def_ddr3_1600_10_10_10_2N) || l_def_ddr3_1333_9_9_9R) || l_def_ddr3_1600_10_10_10R) || l_def_ddr3_1333_9_9_9_LR)
                                                || l_def_ddr3_1600_10_10_10_LR) || l_def_ddr3_1333_9_9_9_L2) || l_def_ddr3_1600_10_10_10_L2) || l_def_ddr3_1333_8_8_8)
                                                || l_def_ddr3_1600_9_9_9) || l_def_ddr3_1333_8_8_8_2N) || l_def_ddr3_1600_9_9_9_2N) || l_def_ddr3_1333_8_8_8R)
                                                || l_def_ddr3_1600_9_9_9R) || l_def_ddr3_1333_8_8_8_LR) || l_def_ddr3_1600_9_9_9_LR) || l_def_ddr3_1333_8_8_8_L2)
                                                || l_def_ddr3_1600_9_9_9_L2) || l_def_ddr3_1866_12_12_12) || l_def_ddr3_1866_12_12_12_2N) || l_def_ddr3_1866_12_12_12R)
                                                || l_def_ddr3_1866_12_12_12_LR) || l_def_ddr3_1866_12_12_12_L2) || l_def_ddr3_1866_11_11_11)
                                                || l_def_ddr3_1866_11_11_11_2N) || l_def_ddr3_1866_11_11_11R) || l_def_ddr3_1866_11_11_11_LR)
                                                || l_def_ddr3_1866_11_11_11_L2);
        uint64_t l_def_mba_tmr1q_WRSBG_dlys30 = ((((l_def_ddr4_1866_11_11_11 || l_def_ddr4_1866_11_11_11_2N)
                                                || l_def_ddr4_1866_11_11_11R) || l_def_ddr4_1866_11_11_11_LR) || l_def_ddr4_1866_11_11_11_L2);
        uint64_t l_def_mba_tmr1q_WRSBG_dlys19 = ((((((l_def_ddr4_1600_11_11_11 || l_def_ddr4_1600_11_11_11_2N)
                                                || l_def_ddr4_1600_11_11_11R) || l_def_ddr4_1600_11_11_11_LR) || l_def_ddr4_1600_11_11_11_L2)
                                                || l_def_ddr4_1600_13_12_11) || l_def_ddr4_1600_13_12_11_2N);
        uint64_t l_def_mba_tmr1q_WRSBG_dlys31 = ((((l_def_ddr4_1866_12_12_12 || l_def_ddr4_1866_12_12_12_2N)
                                                || l_def_ddr4_1866_12_12_12R) || l_def_ddr4_1866_12_12_12_LR) || l_def_ddr4_1866_12_12_12_L2);
        uint64_t l_def_mba_tmr1q_WRSBG_dlys29 = ((((l_def_ddr4_1600_12_12_12 || l_def_ddr4_1600_12_12_12_2N)
                                                || l_def_ddr4_1600_12_12_12R) || l_def_ddr4_1600_12_12_12_LR) || l_def_ddr4_1600_12_12_12_L2);
        uint64_t l_def_mba_tmr1q_WRSBG_dlys0 = (((((((((((((((((((((((((((((((((((((l_def_ddr3_1066_6_6_6_group
                                                || l_def_ddr3_1066_7_7_7_group) || l_def_ddr3_1066_8_8_8_group) || l_def_ddr3_1333_8_8_8) || l_def_ddr3_1333_9_9_9)
                                                || l_def_ddr3_1600_9_9_9) || l_def_ddr3_1600_10_10_10) || l_def_ddr3_1600_11_11_11) || l_def_ddr3_1866_11_11_11)
                                                || l_def_ddr3_1866_12_12_12) || l_def_ddr3_1333_8_8_8_2N) || l_def_ddr3_1333_9_9_9_2N) || l_def_ddr3_1600_9_9_9_2N)
                                                || l_def_ddr3_1600_10_10_10_2N) || l_def_ddr3_1600_11_11_11_2N) || l_def_ddr3_1866_11_11_11_2N)
                                                || l_def_ddr3_1866_12_12_12_2N) || l_def_ddr3_1333_8_8_8R) || l_def_ddr3_1333_9_9_9R) || l_def_ddr3_1600_9_9_9R)
                                                || l_def_ddr3_1600_10_10_10R) || l_def_ddr3_1600_11_11_11R) || l_def_ddr3_1866_11_11_11R) || l_def_ddr3_1866_12_12_12R)
                                                || l_def_ddr3_1333_8_8_8_LR) || l_def_ddr3_1333_9_9_9_LR) || l_def_ddr3_1600_9_9_9_LR) || l_def_ddr3_1600_10_10_10_LR)
                                                || l_def_ddr3_1600_11_11_11_LR) || l_def_ddr3_1866_11_11_11_LR) || l_def_ddr3_1866_12_12_12_LR)
                                                || l_def_ddr3_1333_8_8_8_L2) || l_def_ddr3_1333_9_9_9_L2) || l_def_ddr3_1600_9_9_9_L2) || l_def_ddr3_1600_10_10_10_L2)
                                                || l_def_ddr3_1600_11_11_11_L2) || l_def_ddr3_1866_11_11_11_L2) || l_def_ddr3_1866_12_12_12_L2);
        uint64_t l_def_mba_tmr1q_WRSBG_dlys27 = ((((l_def_ddr4_1600_10_10_10 || l_def_ddr4_1600_10_10_10_2N)
                                                || l_def_ddr4_1600_10_10_10R) || l_def_ddr4_1600_10_10_10_LR) || l_def_ddr4_1600_10_10_10_L2);
        uint64_t l_def_mba_tmr1q_WRSBG_dlys26 = ((((l_def_ddr4_1600_9_9_9 || l_def_ddr4_1600_9_9_9_2N)
                                                || l_def_ddr4_1600_9_9_9R) || l_def_ddr4_1600_9_9_9_LR) || l_def_ddr4_1600_9_9_9_L2);
        uint64_t l_def_mba_tmr1q_cfg_twap53 = ((((l_def_ddr4_1866_13_13_13 || l_def_ddr4_1866_13_13_13_2N)
                                                || l_def_ddr4_1866_13_13_13R) || l_def_ddr4_1866_13_13_13_LR) || l_def_ddr4_1866_13_13_13_L2);
        uint64_t l_def_mba_tmr1q_cfg_twap48 = ((((l_def_ddr4_1600_12_12_12 || l_def_ddr4_1600_12_12_12_2N)
                                                || l_def_ddr4_1600_12_12_12R) || l_def_ddr4_1600_12_12_12_LR) || l_def_ddr4_1600_12_12_12_L2);
        uint64_t l_def_mba_tmr1q_cfg_twap51 = (((((((((l_def_ddr3_1866_12_12_12 || l_def_ddr3_1866_12_12_12_2N)
                                                || l_def_ddr3_1866_12_12_12R) || l_def_ddr3_1866_12_12_12_LR) || l_def_ddr3_1866_12_12_12_L2)
                                                || l_def_ddr4_1866_12_12_12) || l_def_ddr4_1866_12_12_12_2N) || l_def_ddr4_1866_12_12_12R)
                                                || l_def_ddr4_1866_12_12_12_LR) || l_def_ddr4_1866_12_12_12_L2);
        uint64_t l_def_mba_tmr1q_cfg_twap46 = (((((((((l_def_ddr3_1600_11_11_11 || l_def_ddr3_1600_11_11_11_2N)
                                                || l_def_ddr3_1600_11_11_11R) || l_def_ddr3_1600_11_11_11_LR) || l_def_ddr3_1600_11_11_11_L2)
                                                || l_def_ddr4_1600_11_11_11) || l_def_ddr4_1600_11_11_11_2N) || l_def_ddr4_1600_11_11_11R)
                                                || l_def_ddr4_1600_11_11_11_LR) || l_def_ddr4_1600_11_11_11_L2);
        uint64_t l_def_mba_tmr1q_cfg_twap42 = l_def_mba_tmr1q_cfg_trap37;
        uint64_t l_def_mba_tmr1q_cfg_twap34 = l_def_ddr3_1066_8_8_8_group;
        uint64_t l_def_mba_tmr1q_cfg_twap37 = l_def_mba_tmr1q_cfg_trap32;
        uint64_t l_def_mba_tmr1q_cfg_twap49 = (((((((((l_def_ddr3_1866_11_11_11 || l_def_ddr3_1866_11_11_11_2N)
                                                || l_def_ddr3_1866_11_11_11R) || l_def_ddr3_1866_11_11_11_LR) || l_def_ddr3_1866_11_11_11_L2)
                                                || l_def_ddr4_1866_11_11_11) || l_def_ddr4_1866_11_11_11_2N) || l_def_ddr4_1866_11_11_11R)
                                                || l_def_ddr4_1866_11_11_11_LR) || l_def_ddr4_1866_11_11_11_L2);
        uint64_t l_def_mba_tmr1q_cfg_twap32 = l_def_ddr3_1066_7_7_7_group;
        uint64_t l_def_mba_tmr1q_cfg_twap30 = l_def_ddr3_1066_6_6_6_group;
        uint64_t l_def_mba_tmr1q_cfg_twap39 = l_def_mba_tmr1q_cfg_trap33;
        uint64_t l_def_mba_tmr1q_cfg_twap44 = l_def_mba_tmr1q_cfg_trap38;
        fapi2::ATTR_CEN_EFF_ZQCAL_INTERVAL_Type l_TGT0_ATTR_CEN_EFF_ZQCAL_INTERVAL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_ZQCAL_INTERVAL, TGT0, l_TGT0_ATTR_CEN_EFF_ZQCAL_INTERVAL));
        uint64_t l_def_zq_intv_sel10 = (l_TGT0_ATTR_CEN_EFF_ZQCAL_INTERVAL / literal_16384);
        uint64_t l_def_zq_intv_sel11 = (l_TGT0_ATTR_CEN_EFF_ZQCAL_INTERVAL / literal_16777216);
        fapi2::ATTR_CEN_EFF_MEMCAL_INTERVAL_Type l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MEMCAL_INTERVAL, TGT0, l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL));
        uint64_t l_def_mem_intv_sel11 = (l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL / literal_16777216);
        uint64_t l_def_mem_intv_sel10 = (l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL / literal_16384);
        fapi2::ATTR_CEN_EFF_CUSTOM_DIMM_Type l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, TGT0, l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM));
        fapi2::ATTR_CEN_EFF_NUM_DROPS_PER_PORT_Type l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_DROPS_PER_PORT, TGT0, l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT));
        fapi2::ATTR_CEN_EFF_IBM_TYPE_Type l_TGT0_ATTR_CEN_EFF_IBM_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_IBM_TYPE, TGT0, l_TGT0_ATTR_CEN_EFF_IBM_TYPE));
        uint64_t l_def_4a_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                      && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_11)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                              && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_11)))
                                    && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                            && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_3a_2socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_8)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_8)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_4a_cdimm);
        uint64_t l_def_3a_1socket = ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                       && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_8)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                               && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_8)))
                                     && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1));
        uint64_t l_def_3b_2socket = ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                       && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_9)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                               && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_9)))
                                     && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2));
        uint64_t l_def_3b_1socket = ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                       && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_9)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                               && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_9)))
                                     && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1));
        uint64_t l_def_IS3A_IS3B = (((l_def_3b_1socket || l_def_3b_2socket) || l_def_3a_1socket) || l_def_3a_2socket);
        uint64_t l_def_7a_2socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_21)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_21)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_7a_1socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_21)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_21)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_IS7a_C4a_C3a = (((l_def_3a_2socket || l_def_4a_cdimm) || l_def_7a_1socket) || l_def_7a_2socket);
        uint64_t l_def_4a_ddr4_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                           && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_11)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                   && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_11)))
                                         && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_3a_2socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_8)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_8)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_4a_ddr4_cdimm);
        uint64_t l_def_7a_2socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_21)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_21)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_7a_1socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_21)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_21)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_3a_ddr4_cdimm = ((((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                            && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_8)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                    && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_8)))
                                          && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                  && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))) && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_2a_2socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_3a_ddr4_cdimm);
        uint64_t l_def_2a_ddr4_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                           && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                   && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5)))
                                         && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_2a_1socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_2a_ddr4_cdimm);
        uint64_t l_def_C4A_ddr4 = ((((((l_def_2a_1socket_ddr4 || l_def_2a_2socket_ddr4) || l_def_3a_ddr4_cdimm)
                                      || l_def_7a_1socket_ddr4) || l_def_7a_2socket_ddr4) || l_def_3a_2socket_ddr4) || l_def_4a_ddr4_cdimm);
        uint64_t l_def_7c_2socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_23)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_23)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_7c_1socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_23)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_23)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_IS7C = (l_def_7c_1socket || l_def_7c_2socket);
        uint64_t l_def_3c_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                      && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_10)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                              && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_10)))
                                    && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                            && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_2c_2socket = ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                       && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_7)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                               && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_7)))
                                     && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2));
        uint64_t l_def_2a_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                      && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                              && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5)))
                                    && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                            && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_2c_1socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_7)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_7)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_2a_cdimm);
        uint64_t l_def_C3c = ((l_def_2c_1socket || l_def_2c_2socket) || l_def_3c_cdimm);
        uint64_t l_def_5c_2socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_16)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_16)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_5c_1socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_16)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_16)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_5b_2socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_15)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_15)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_5b_1socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_15)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_15)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_1d_2socket = ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                       && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_4)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                               && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_4)))
                                     && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2));
        uint64_t l_def_1c_2socket_nodt = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_3)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_3)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_1d_2socket);
        uint64_t l_def_1d_1socket = ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                       && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_4)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                               && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_4)))
                                     && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1));
        uint64_t l_def_1c_1socket_nodt = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_3)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_3)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_1d_1socket);
        uint64_t l_def_1c_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                      && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_3)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                              && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_3)))
                                    && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                            && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_1b_2socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_2)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_2)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_1c_cdimm);
        uint64_t l_def_1b_1socket = ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                       && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_2)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                               && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_2)))
                                     && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1));
        uint64_t l_def_1a_2socket = ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                       && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_1)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                               && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_1)))
                                     && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2));
        uint64_t l_def_1a_1socket = ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                       && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_1)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                               && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_1)))
                                     && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1));
        uint64_t l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C = ((((((((((l_def_1a_1socket || l_def_1a_2socket)
                || l_def_1b_1socket) || l_def_1b_2socket) || l_def_1c_cdimm) || l_def_1c_1socket_nodt) || l_def_1c_2socket_nodt)
                || l_def_5b_1socket) || l_def_5b_2socket) || l_def_5c_1socket) || l_def_5c_2socket);
        uint64_t l_def_7c_2socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_23)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_23)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_7c_1socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_23)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_23)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_7b_2socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_22)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_22)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_7b_1socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_22)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_22)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_4c_ddr4_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                           && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_13)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                   && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_13)))
                                         && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_3c_2socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_10)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_10)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_4c_ddr4_cdimm);
        uint64_t l_def_3c_1socket_ddr4 = ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                            && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_10)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                    && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_10)))
                                          && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1));
        uint64_t l_def_3c_ddr4_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                           && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_10)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                   && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_10)))
                                         && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_2c_2socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_7)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_7)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_3c_ddr4_cdimm);
        uint64_t l_def_2c_1socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_7)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_7)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_2a_ddr4_cdimm);
        uint64_t l_def_3b_ddr4_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                           && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_9)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                   && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_9)))
                                         && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_2b_2socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_6)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_6)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_3b_ddr4_cdimm);
        uint64_t l_def_2b_ddr4_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                           && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_6)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                   && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_6)))
                                         && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_2b_1socket_ddr4 = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                             && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_6)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                     && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_6)))
                                           && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_2b_ddr4_cdimm);
        uint64_t l_def_C3c_C4C_ddr4 = ((((((((((((l_def_2b_1socket_ddr4 || l_def_2b_2socket_ddr4) || l_def_3b_ddr4_cdimm)
                                                || l_def_2c_1socket_ddr4) || l_def_2c_2socket_ddr4) || l_def_3c_ddr4_cdimm) || l_def_3c_1socket_ddr4)
                                            || l_def_3c_2socket_ddr4) || l_def_4c_ddr4_cdimm) || l_def_7b_1socket_ddr4) || l_def_7b_2socket_ddr4)
                                        || l_def_7c_1socket_ddr4) || l_def_7c_2socket_ddr4);
        uint64_t l_def_5d_2socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_17)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_17)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_5d_1socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_17)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_17)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_IS5D = (l_def_5d_1socket || l_def_5d_2socket);
        uint64_t l_def_3b_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                      && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_9)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                              && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_9)))
                                    && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                            && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_2b_2socket = ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                       && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_6)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                               && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_6)))
                                     && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2));
        uint64_t l_def_2b_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                      && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_6)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                              && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_6)))
                                    && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                            && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_2b_1socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_6)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_6)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_2b_cdimm);
        uint64_t l_def_3a_cdimm = ((((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                       && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_8)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                               && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_8)))
                                     && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                             && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))) && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_2c_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                      && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_7)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                              && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_7)))
                                    && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                            && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_2a_2socket = ((((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                         && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                 && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5)))
                                       && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_2c_cdimm) || l_def_3a_cdimm);
        uint64_t l_def_2a_1socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_2a_cdimm);
        uint64_t l_def_C3b = (((((l_def_2a_1socket || l_def_2a_2socket) || l_def_3a_cdimm) || l_def_2b_1socket)
                               || l_def_2b_2socket) || l_def_3b_cdimm);
        uint64_t l_def_7b_2socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_22)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_22)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_7b_1socket = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                        && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_22)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_22)))
                                      && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3));
        uint64_t l_def_4b_ddr4_cdimm = (((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                                           && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_12)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                                                   && (l_TGT0_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_12)))
                                         && (l_TGT0_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)));
        uint64_t l_def_IS3b_IS7b = ((((l_def_3b_1socket || l_def_3b_2socket) || l_def_4b_ddr4_cdimm) || l_def_7b_1socket)
                                    || l_def_7b_2socket);
        fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA_Type l_TGT0_ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA, TGT0,
                               l_TGT0_ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA));
        fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP_Type l_TGT0_ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP, TGT0,
                               l_TGT0_ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP));
        fapi2::ATTR_CEN_MSS_MEM_THROTTLE_DENOMINATOR_Type l_TGT0_ATTR_CEN_MSS_MEM_THROTTLE_DENOMINATOR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_DENOMINATOR, TGT0,
                               l_TGT0_ATTR_CEN_MSS_MEM_THROTTLE_DENOMINATOR));
        fapi2::ATTR_CEN_MSS_THROTTLE_CONTROL_RAS_WEIGHT_Type l_TGT0_ATTR_CEN_MSS_THROTTLE_CONTROL_RAS_WEIGHT;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_THROTTLE_CONTROL_RAS_WEIGHT, TGT0,
                               l_TGT0_ATTR_CEN_MSS_THROTTLE_CONTROL_RAS_WEIGHT));
        fapi2::ATTR_CEN_MSS_THROTTLE_CONTROL_CAS_WEIGHT_Type l_TGT0_ATTR_CEN_MSS_THROTTLE_CONTROL_CAS_WEIGHT;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_THROTTLE_CONTROL_CAS_WEIGHT, TGT0,
                               l_TGT0_ATTR_CEN_MSS_THROTTLE_CONTROL_CAS_WEIGHT));
        fapi2::ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP_Type
        l_TGT2_ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP, TGT2,
                               l_TGT2_ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP));
        fapi2::ATTR_CEN_MRW_MEM_THROTTLE_DENOMINATOR_Type l_TGT2_ATTR_CEN_MRW_MEM_THROTTLE_DENOMINATOR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_MEM_THROTTLE_DENOMINATOR, TGT2,
                               l_TGT2_ATTR_CEN_MRW_MEM_THROTTLE_DENOMINATOR));
        fapi2::ATTR_CEN_EFF_DRAM_TRFC_Type l_TGT0_ATTR_CEN_EFF_DRAM_TRFC;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRFC, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_TRFC));
        fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM_Type l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, TGT0, l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM));
        uint64_t l_def_mba01_num_ranks = (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] +
                                          l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_1]);
        fapi2::ATTR_CEN_EFF_DRAM_TRFI_Type l_TGT0_ATTR_CEN_EFF_DRAM_TRFI;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRFI, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_TRFI));
        uint64_t l_def_mba01_refresh_interval = (l_TGT0_ATTR_CEN_EFF_DRAM_TRFI / (literal_8 * l_def_mba01_num_ranks));
        uint64_t l_def_mba23_num_ranks = (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_1][literal_0] +
                                          l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_1][literal_1]);
        uint64_t l_def_mba23_refresh_interval = (l_TGT0_ATTR_CEN_EFF_DRAM_TRFI / (literal_8 * l_def_mba23_num_ranks));
        fapi2::ATTR_CEN_EFF_DRAM_DLL_PPD_Type l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DLL_PPD, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD));
        fapi2::ATTR_CEN_EFF_DRAM_DENSITY_Type l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DENSITY, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY));
        uint64_t l_def_2400_8gb_fast_exit_pd_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2400)
                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_2133_8gb_fast_exit_pd_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2133)
                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1866_8gb_fast_exit_pd_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)
                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1600_8gb_fast_exit_pd_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)
                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_2400_8gb_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2400)
                                          && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                        && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_2133_8gb_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2133)
                                          && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                        && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1866_8gb_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)
                                          && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                        && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1600_8gb_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)
                                          && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                        && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1866_8gb_fast_exit_pd = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1600_8gb_fast_exit_pd = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1333_8gb_fast_exit_pd = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1066_8gb_fast_exit_pd = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1866_8gb = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)
                                     && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                   && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1600_8gb = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)
                                     && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                   && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1333_8gb = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)
                                     && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                   && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1066_8gb = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)
                                     && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                   && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_MBAREF0Q_cfg_refr_tsv_stack_dly64 = (((((((((((((((l_def_1066_8gb || l_def_1333_8gb) || l_def_1600_8gb)
                || l_def_1866_8gb) || l_def_1066_8gb_fast_exit_pd) || l_def_1333_8gb_fast_exit_pd) || l_def_1600_8gb_fast_exit_pd)
                || l_def_1866_8gb_fast_exit_pd) || l_def_1600_8gb_ddr4) || l_def_1866_8gb_ddr4) || l_def_2133_8gb_ddr4)
                || l_def_2400_8gb_ddr4) || l_def_1600_8gb_fast_exit_pd_ddr4) || l_def_1866_8gb_fast_exit_pd_ddr4)
                || l_def_2133_8gb_fast_exit_pd_ddr4) || l_def_2400_8gb_fast_exit_pd_ddr4);
        uint64_t l_def_2400_4gb_fast_exit_pd_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2400)
                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_2133_4gb_fast_exit_pd_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2133)
                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1866_4gb_fast_exit_pd_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)
                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1600_4gb_fast_exit_pd_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)
                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_2400_4gb_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2400)
                                          && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                        && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_2133_4gb_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2133)
                                          && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                        && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1866_4gb_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)
                                          && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                        && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1600_4gb_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)
                                          && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                        && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1866_4gb_fast_exit_pd = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1600_4gb_fast_exit_pd = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1333_4gb_fast_exit_pd = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1066_4gb_fast_exit_pd = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1866_4gb = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)
                                     && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                   && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1600_4gb = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)
                                     && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                   && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1333_4gb = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)
                                     && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                   && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1066_4gb = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)
                                     && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_4)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                   && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_MBAREF0Q_cfg_refr_tsv_stack_dly48 = (((((((((((((((l_def_1066_4gb || l_def_1333_4gb) || l_def_1600_4gb)
                || l_def_1866_4gb) || l_def_1066_4gb_fast_exit_pd) || l_def_1333_4gb_fast_exit_pd) || l_def_1600_4gb_fast_exit_pd)
                || l_def_1866_4gb_fast_exit_pd) || l_def_1600_4gb_ddr4) || l_def_1866_4gb_ddr4) || l_def_2133_4gb_ddr4)
                || l_def_2400_4gb_ddr4) || l_def_1600_4gb_fast_exit_pd_ddr4) || l_def_1866_4gb_fast_exit_pd_ddr4)
                || l_def_2133_4gb_fast_exit_pd_ddr4) || l_def_2400_4gb_fast_exit_pd_ddr4);
        uint64_t l_def_2400_2gb_fast_exit_pd_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2400)
                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_2133_2gb_fast_exit_pd_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2133)
                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1866_2gb_fast_exit_pd_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)
                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1600_2gb_fast_exit_pd_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)
                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_2400_2gb_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2400)
                                          && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                        && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_2133_2gb_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2133)
                                          && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                        && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1866_2gb_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)
                                          && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                        && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1600_2gb_ddr4 = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)
                                          && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                        && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2));
        uint64_t l_def_1866_2gb_fast_exit_pd = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1600_2gb_fast_exit_pd = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1333_2gb_fast_exit_pd = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1066_2gb_fast_exit_pd = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_1))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1866_2gb = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866)
                                     && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                   && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1600_2gb = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)
                                     && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                   && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1333_2gb = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333)
                                     && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                   && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_1066_2gb = ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066)
                                     && (l_TGT0_ATTR_CEN_EFF_DRAM_DENSITY == literal_2)) && (l_TGT0_ATTR_CEN_EFF_DRAM_DLL_PPD == literal_0))
                                   && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_1));
        uint64_t l_def_MBAREF0Q_cfg_refr_tsv_stack_dly32 = (((((((((((((((l_def_1066_2gb || l_def_1333_2gb) || l_def_1600_2gb)
                || l_def_1866_2gb) || l_def_1066_2gb_fast_exit_pd) || l_def_1333_2gb_fast_exit_pd) || l_def_1600_2gb_fast_exit_pd)
                || l_def_1866_2gb_fast_exit_pd) || l_def_1600_2gb_ddr4) || l_def_1866_2gb_ddr4) || l_def_2133_2gb_ddr4)
                || l_def_2400_2gb_ddr4) || l_def_1600_2gb_fast_exit_pd_ddr4) || l_def_1866_2gb_fast_exit_pd_ddr4)
                || l_def_2133_2gb_fast_exit_pd_ddr4) || l_def_2400_2gb_fast_exit_pd_ddr4);
        uint64_t l_def_refresh_check_interval = ((l_TGT0_ATTR_CEN_EFF_DRAM_TRFI / literal_8) + ((
                l_TGT0_ATTR_CEN_EFF_DRAM_TRFI / literal_8) / literal_10));
        fapi2::ATTR_CEN_VPD_CKE_PRI_MAP_Type l_TGT0_ATTR_CEN_VPD_CKE_PRI_MAP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_CKE_PRI_MAP, TGT0, l_TGT0_ATTR_CEN_VPD_CKE_PRI_MAP));
        uint64_t l_def_MBARPC0Q_cfg_pup_pdn_dly4 = (((((((((((((((((l_def_1333_2gb || l_def_1333_4gb) || l_def_1333_8gb)
                || l_def_1600_2gb) || l_def_1600_4gb) || l_def_1600_8gb) || l_def_1333_2gb_fast_exit_pd)
                || l_def_1333_4gb_fast_exit_pd) || l_def_1333_8gb_fast_exit_pd) || l_def_1600_2gb_fast_exit_pd)
                || l_def_1600_4gb_fast_exit_pd) || l_def_1600_8gb_fast_exit_pd) || l_def_1600_2gb_ddr4) || l_def_1600_4gb_ddr4)
                || l_def_1600_8gb_ddr4) || l_def_1600_2gb_fast_exit_pd_ddr4) || l_def_1600_4gb_fast_exit_pd_ddr4)
                || l_def_1600_8gb_fast_exit_pd_ddr4);
        uint64_t l_def_MBARPC0Q_cfg_pup_pdn_dly5 = (((((((((((l_def_1866_2gb || l_def_1866_4gb) || l_def_1866_8gb)
                || l_def_1866_2gb_fast_exit_pd) || l_def_1866_4gb_fast_exit_pd) || l_def_1866_8gb_fast_exit_pd) || l_def_1866_2gb_ddr4)
                || l_def_1866_4gb_ddr4) || l_def_1866_8gb_ddr4) || l_def_1866_2gb_fast_exit_pd_ddr4)
                || l_def_1866_4gb_fast_exit_pd_ddr4) || l_def_1866_8gb_fast_exit_pd_ddr4);
        uint64_t l_def_MBARPC0Q_cfg_pup_pdn_dly3 = (((((l_def_1066_2gb || l_def_1066_4gb) || l_def_1066_8gb)
                || l_def_1066_2gb_fast_exit_pd) || l_def_1066_4gb_fast_exit_pd) || l_def_1066_8gb_fast_exit_pd);
        uint64_t l_def_MBARPC0Q_cfg_pup_pdn_dly6 = (((((((((((l_def_2133_2gb_ddr4 || l_def_2133_4gb_ddr4)
                || l_def_2133_8gb_ddr4) || l_def_2400_2gb_ddr4) || l_def_2400_4gb_ddr4) || l_def_2400_8gb_ddr4)
                || l_def_2133_2gb_fast_exit_pd_ddr4) || l_def_2133_4gb_fast_exit_pd_ddr4) || l_def_2133_8gb_fast_exit_pd_ddr4)
                || l_def_2400_2gb_fast_exit_pd_ddr4) || l_def_2400_4gb_fast_exit_pd_ddr4) || l_def_2400_8gb_fast_exit_pd_ddr4);
        fapi2::ATTR_CEN_VPD_POWER_CONTROL_CAPABLE_Type l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_POWER_CONTROL_CAPABLE, TGT1, l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE));
        fapi2::ATTR_CEN_MRW_POWER_CONTROL_REQUESTED_Type l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_POWER_CONTROL_REQUESTED, TGT2, l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED));
        uint64_t l_def_MBARPC0Q_cfg_pup_avail_dly7 = ((l_def_2133_2gb_fast_exit_pd_ddr4 || l_def_2133_4gb_fast_exit_pd_ddr4)
                || l_def_2133_8gb_fast_exit_pd_ddr4);
        uint64_t l_def_margin_pup_slow = literal_0;
        uint64_t l_def_MBARPC0Q_cfg_pup_avail_dly5 = (((((l_def_1600_2gb_fast_exit_pd || l_def_1600_4gb_fast_exit_pd)
                || l_def_1600_8gb_fast_exit_pd) || l_def_1600_2gb_fast_exit_pd_ddr4) || l_def_1600_4gb_fast_exit_pd_ddr4)
                || l_def_1600_8gb_fast_exit_pd_ddr4);
        uint64_t l_def_MBARPC0Q_cfg_pup_avail_dly29 = ((l_def_2400_2gb_ddr4 || l_def_2400_4gb_ddr4) || l_def_2400_8gb_ddr4);
        uint64_t l_def_margin_pup_fast = literal_0;
        uint64_t l_def_MBARPC0Q_cfg_pup_avail_dly6 = (((((l_def_1866_2gb_fast_exit_pd || l_def_1866_4gb_fast_exit_pd)
                || l_def_1866_8gb_fast_exit_pd) || l_def_1866_2gb_fast_exit_pd_ddr4) || l_def_1866_4gb_fast_exit_pd_ddr4)
                || l_def_1866_8gb_fast_exit_pd_ddr4);
        uint64_t l_def_MBARPC0Q_cfg_pup_avail_dly13 = ((l_def_1066_2gb || l_def_1066_4gb) || l_def_1066_8gb);
        uint64_t l_def_MBARPC0Q_cfg_pup_avail_dly8 = ((l_def_2400_2gb_fast_exit_pd_ddr4 || l_def_2400_4gb_fast_exit_pd_ddr4)
                || l_def_2400_8gb_fast_exit_pd_ddr4);
        uint64_t l_def_MBARPC0Q_cfg_pup_avail_dly26 = ((l_def_2133_2gb_ddr4 || l_def_2133_4gb_ddr4) || l_def_2133_8gb_ddr4);
        uint64_t l_def_MBARPC0Q_cfg_pup_avail_dly16 = ((l_def_1333_2gb || l_def_1333_4gb) || l_def_1333_8gb);
        uint64_t l_def_MBARPC0Q_cfg_pup_avail_dly20 = (((((l_def_1600_2gb || l_def_1600_4gb) || l_def_1600_8gb)
                || l_def_1600_2gb_ddr4) || l_def_1600_4gb_ddr4) || l_def_1600_8gb_ddr4);
        uint64_t l_def_MBARPC0Q_cfg_pup_avail_dly4 = (((((l_def_1066_2gb_fast_exit_pd || l_def_1066_4gb_fast_exit_pd)
                || l_def_1066_8gb_fast_exit_pd) || l_def_1333_2gb_fast_exit_pd) || l_def_1333_4gb_fast_exit_pd)
                || l_def_1333_8gb_fast_exit_pd);
        uint64_t l_def_MBARPC0Q_cfg_pup_avail_dly23 = (((((l_def_1866_2gb || l_def_1866_4gb) || l_def_1866_8gb)
                || l_def_1866_2gb_ddr4) || l_def_1866_4gb_ddr4) || l_def_1866_8gb_ddr4);
        uint64_t l_def_MBARPC0Q_cfg_pdn_pup_dly4 = l_def_MBARPC0Q_cfg_pup_pdn_dly4;
        uint64_t l_def_MBARPC0Q_cfg_pdn_pup_dly5 = l_def_MBARPC0Q_cfg_pup_pdn_dly5;
        uint64_t l_def_MBARPC0Q_cfg_pdn_pup_dly3 = l_def_MBARPC0Q_cfg_pup_pdn_dly3;
        uint64_t l_def_MBARPC0Q_cfg_pdn_pup_dly6 = l_def_MBARPC0Q_cfg_pup_pdn_dly6;
        fapi2::ATTR_CEN_VPD_CKE_PWR_MAP_Type l_TGT0_ATTR_CEN_VPD_CKE_PWR_MAP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_CKE_PWR_MAP, TGT0, l_TGT0_ATTR_CEN_VPD_CKE_PWR_MAP));
        uint64_t l_def_shift_pwr_map12 = (l_TGT0_ATTR_CEN_VPD_CKE_PWR_MAP >> literal_16);
        uint64_t l_def_shift_pwr_map4 = (l_TGT0_ATTR_CEN_VPD_CKE_PWR_MAP >> literal_48);
        uint64_t l_def_shift_pwr_map8 = (l_TGT0_ATTR_CEN_VPD_CKE_PWR_MAP >> literal_32);
        fapi2::ATTR_CEN_EFF_DRAM_BANKS_Type l_TGT0_ATTR_CEN_EFF_DRAM_BANKS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_BANKS, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_BANKS));
        fapi2::ATTR_CEN_EFF_DRAM_COLS_Type l_TGT0_ATTR_CEN_EFF_DRAM_COLS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_COLS, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_COLS));
        uint64_t l_def_mcb_addr_bank2_28 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && ((l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16) || (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)));
        uint64_t l_def_mcb_addr_bank2_26 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && ((l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16) || (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)));
        uint64_t l_def_mcb_addr_bank2_27 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                            && ((l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16) || (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)));
        fapi2::ATTR_CEN_EFF_DRAM_ROWS_Type l_TGT0_ATTR_CEN_EFF_DRAM_ROWS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ROWS, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_ROWS));
        fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM_Type l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, TGT0,
                               l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM));
        uint64_t l_def_mcb_addr_col12_bnk8_srank0_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col11_bnk8_srank0_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col10_bnk8_srank0_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col11_bnk16_srank0_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col10_bnk16_srank0_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col12_bnk8_srank0_6 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col12_bnk16_srank0_6 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col11_bnk16_srank0_6 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col12_bnk16_srank0_5 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_srank0_unset = (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                                           (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8));
        uint64_t l_def_mcb_addr_col10_bnk8_srank0_11 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col10_bnk16_srank0_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col11_bnk8_srank0_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col10_bnk8_srank0_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col12_bnk8_srank0_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col11_bnk8_srank0_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col10_bnk8_srank0_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col12_bnk16_srank0_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col11_bnk16_srank0_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col10_bnk16_srank0_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col12_bnk8_srank0_7 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col11_bnk8_srank0_7 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col12_bnk16_srank0_7 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col11_bnk16_srank0_7 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col10_bnk16_srank0_7 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_7))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk8_mrank3_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk8_mrank3_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col11_bnk8_mrank3_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk16_mrank3_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk16_mrank3_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk16_mrank3_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col11_bnk16_mrank3_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col11_bnk16_mrank3_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col10_bnk16_mrank3_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk16_mrank3_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk8_mrank3_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk16_mrank3_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk16_mrank3_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col11_bnk16_mrank3_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row14_col11_bnk8_mrank3_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col10_bnk8_mrank3_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col10_bnk8_mrank3_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row14_col12_bnk8_mrank3_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col11_bnk8_mrank3_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col10_bnk8_mrank3_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row14_col11_bnk16_mrank3_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col10_bnk16_mrank3_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col10_bnk16_mrank3_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_mrank3_unset = (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] == literal_0);
        uint64_t l_def_mcb_addr_row16_col12_bnk8_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk8_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk8_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col11_bnk8_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col11_bnk8_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col11_bnk8_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col11_bnk8_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col10_bnk8_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col10_bnk8_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk16_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk16_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col11_bnk16_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col11_bnk16_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col11_bnk16_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col10_bnk16_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col10_bnk16_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col12_bnk8_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk16_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col11_bnk16_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row15_col10_bnk16_mrank3_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col12_bnk8_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk8_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk8_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col11_bnk8_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col11_bnk8_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col10_bnk8_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk16_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk16_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk16_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col11_bnk16_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col11_bnk16_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col11_bnk16_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col10_bnk16_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk16_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col10_bnk16_mrank3_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row14_col11_bnk8_mrank3_12 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col10_bnk8_mrank3_12 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col10_bnk16_mrank3_12 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row14_col10_bnk8_mrank3_12 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col12_bnk8_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk8_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col11_bnk8_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col11_bnk8_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col10_bnk8_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col10_bnk8_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col10_bnk8_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk16_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col11_bnk16_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col11_bnk16_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col10_bnk16_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col10_bnk16_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col12_bnk8_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col11_bnk8_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row15_col12_bnk16_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col11_bnk16_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col10_bnk16_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row14_col10_bnk16_mrank3_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row14_col12_bnk8_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col11_bnk8_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col11_bnk8_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col10_bnk8_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col10_bnk8_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col10_bnk8_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row14_col11_bnk16_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col10_bnk16_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row15_col12_bnk8_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col11_bnk8_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col10_bnk8_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row14_col12_bnk16_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col11_bnk16_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col10_bnk16_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row14_col10_bnk16_mrank3_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row14_col10_bnk8_mrank3_13 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_0)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col12_bnk8_srank1_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col11_bnk8_srank1_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col10_bnk8_srank1_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col12_bnk16_srank1_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col11_bnk16_srank1_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col10_bnk16_srank1_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col12_bnk16_srank1_6 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col11_bnk8_srank1_11 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col10_bnk8_srank1_11 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col10_bnk16_srank1_11 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_srank1_unset = (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                                           (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4));
        uint64_t l_def_mcb_addr_col12_bnk8_srank1_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col11_bnk8_srank1_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col10_bnk8_srank1_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col11_bnk16_srank1_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col10_bnk16_srank1_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col12_bnk8_srank1_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col11_bnk8_srank1_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col12_bnk16_srank1_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col11_bnk16_srank1_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col10_bnk16_srank1_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col12_bnk8_srank1_7 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col12_bnk16_srank1_7 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col11_bnk16_srank1_7 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col10_bnk8_srank1_12 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_3))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_bank1_28 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                            && ((l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16) || (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)));
        uint64_t l_def_mcb_addr_bank1_29 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && ((l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16) || (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)));
        uint64_t l_def_mcb_addr_bank1_27 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && ((l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16) || (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)));
        uint64_t l_def_mcb_addr_row17_col12_bnk8_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk8_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk8_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col11_bnk8_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col11_bnk8_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col10_bnk8_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk16_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk16_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk16_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col11_bnk16_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col11_bnk16_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col11_bnk16_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col10_bnk16_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk16_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col10_bnk16_mrank2_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col12_bnk8_mrank2_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk16_mrank2_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk16_mrank2_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col11_bnk16_mrank2_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk8_mrank2_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk8_mrank2_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col11_bnk8_mrank2_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk16_mrank2_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk16_mrank2_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk16_mrank2_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col11_bnk16_mrank2_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col11_bnk16_mrank2_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col10_bnk16_mrank2_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row14_col11_bnk8_mrank2_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col10_bnk8_mrank2_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col10_bnk16_mrank2_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row14_col10_bnk8_mrank2_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_mrank2_unset = (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] < literal_4);
        uint64_t l_def_mcb_addr_row15_col12_bnk8_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk8_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col11_bnk8_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col11_bnk8_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col10_bnk8_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col10_bnk8_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col10_bnk8_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk16_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col11_bnk16_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col11_bnk16_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col10_bnk16_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col10_bnk16_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col12_bnk8_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col11_bnk8_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row15_col12_bnk16_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col11_bnk16_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col10_bnk16_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row14_col10_bnk16_mrank2_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col12_bnk8_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk8_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk8_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col11_bnk8_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col11_bnk8_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col11_bnk8_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col11_bnk8_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col10_bnk8_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col10_bnk8_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk16_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk16_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col11_bnk16_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col11_bnk16_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col11_bnk16_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col10_bnk16_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col10_bnk16_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col12_bnk8_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk16_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col11_bnk16_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row15_col10_bnk16_mrank2_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col10_bnk8_mrank2_12 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row14_col12_bnk8_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col11_bnk8_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col11_bnk8_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col10_bnk8_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col10_bnk8_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col10_bnk8_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row14_col11_bnk16_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col10_bnk16_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row15_col12_bnk8_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col11_bnk8_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col10_bnk8_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row14_col12_bnk16_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col11_bnk16_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col10_bnk16_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row14_col10_bnk16_mrank2_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col12_bnk16_mrank2_3 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row14_col11_bnk8_mrank2_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col10_bnk8_mrank2_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col10_bnk8_mrank2_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row14_col12_bnk8_mrank2_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col11_bnk8_mrank2_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col10_bnk8_mrank2_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row14_col11_bnk16_mrank2_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col10_bnk16_mrank2_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col10_bnk16_mrank2_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_3)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col12_bnk8_srank2_11 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col11_bnk8_srank2_11 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col10_bnk8_srank2_11 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col11_bnk16_srank2_11 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_srank2_unset = (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                                           (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2));
        uint64_t l_def_mcb_addr_col12_bnk8_srank2_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col12_bnk16_srank2_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col11_bnk16_srank2_8 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col12_bnk16_srank2_7 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col11_bnk8_srank2_12 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col10_bnk8_srank2_12 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col10_bnk16_srank2_12 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col12_bnk8_srank2_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col11_bnk8_srank2_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col12_bnk16_srank2_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col11_bnk16_srank2_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col10_bnk16_srank2_9 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col10_bnk16_srank2_11 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col12_bnk8_srank2_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col11_bnk8_srank2_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col10_bnk8_srank2_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col12_bnk16_srank2_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_col11_bnk16_srank2_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_col10_bnk16_srank2_10 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_col10_bnk8_srank2_13 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >
                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_1))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col12_bnk8_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk8_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk8_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col11_bnk8_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col11_bnk8_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col11_bnk8_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col11_bnk8_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col10_bnk8_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col10_bnk8_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk16_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk16_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col11_bnk16_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col11_bnk16_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col11_bnk16_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col10_bnk16_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col10_bnk16_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col12_bnk8_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk16_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col11_bnk16_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row15_col10_bnk16_mrank1_6 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col12_bnk8_mrank1_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk8_mrank1_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col11_bnk8_mrank1_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk16_mrank1_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk16_mrank1_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk16_mrank1_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col11_bnk16_mrank1_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col11_bnk16_mrank1_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col10_bnk16_mrank1_4 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk8_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk8_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk8_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col11_bnk8_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col11_bnk8_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col10_bnk8_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk16_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col12_bnk16_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk16_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col11_bnk16_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col11_bnk16_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col11_bnk16_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col10_bnk16_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk16_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col10_bnk16_mrank1_5 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row14_col10_bnk8_mrank1_11 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_mrank1_unset = (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] < literal_8);
        uint64_t l_def_mcb_addr_row14_col12_bnk8_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col11_bnk8_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col11_bnk8_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col10_bnk8_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col10_bnk8_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col10_bnk8_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row14_col11_bnk16_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col10_bnk16_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row15_col12_bnk8_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col11_bnk8_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col10_bnk8_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row14_col12_bnk16_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col11_bnk16_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col10_bnk16_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row14_col10_bnk16_mrank1_8 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col12_bnk8_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk8_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col11_bnk8_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col11_bnk8_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row17_col10_bnk8_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col10_bnk8_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col10_bnk8_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col12_bnk16_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col11_bnk16_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col11_bnk16_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row16_col10_bnk16_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row15_col10_bnk16_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col12_bnk8_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col11_bnk8_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row15_col12_bnk16_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col11_bnk16_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col10_bnk16_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row14_col10_bnk16_mrank1_7 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row14_col11_bnk8_mrank1_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col10_bnk8_mrank1_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col10_bnk8_mrank1_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row14_col12_bnk8_mrank1_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col11_bnk8_mrank1_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row16_col10_bnk8_mrank1_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row14_col11_bnk16_mrank1_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col10_bnk16_mrank1_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col10_bnk16_mrank1_9 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row17_col12_bnk8_mrank1_3 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk16_mrank1_3 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_col12_bnk16_mrank1_3 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)));
        uint64_t l_def_mcb_addr_row17_col11_bnk16_mrank1_3 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row17_col12_bnk16_mrank1_2 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row14_col11_bnk8_mrank1_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row15_col10_bnk8_mrank1_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)));
        uint64_t l_def_mcb_addr_row14_col10_bnk16_mrank1_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_row14_col10_bnk8_mrank1_10 = (((
                    l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] > literal_7)
                && (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                    (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2)))
                && (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                    && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)));
        uint64_t l_def_mcb_addr_unset_bank3 = (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8);
        uint64_t l_def_mcb_addr_bank3_26 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16));
        uint64_t l_def_mcb_addr_bank3_25 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16));
        uint64_t l_def_mcb_addr_bank3_27 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16));
        uint64_t l_def_mcb_addr_row10_16 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row10_17 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row10_14 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row10_15 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row15_9 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row15_11 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_unset_row15 = ((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                               || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15));
        uint64_t l_def_mcb_addr_row15_10 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row15_12 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row8_16 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row8_17 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row8_18 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row8_19 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row11_16 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row11_14 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row11_15 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row11_13 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_9 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))
                                           || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                                               && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row16_11 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17));
        uint64_t l_def_mcb_addr_unset_row16 = (((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16));
        uint64_t l_def_mcb_addr_row16_8 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17));
        uint64_t l_def_mcb_addr_row16_10 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))
                                            || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                                                && (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row9_16 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row9_17 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row9_15 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row9_18 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row12_14 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row12_15 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row12_12 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row12_13 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_bank0_28 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && ((l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16) || (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)));
        uint64_t l_def_mcb_addr_bank0_30 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && ((l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16) || (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)));
        uint64_t l_def_mcb_addr_bank0_29 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                            && ((l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16) || (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)));
        uint64_t l_def_mcb_addr_row13_14 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row13_11 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row13_12 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row13_13 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row14_11 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && (((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)))
                                            || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                                                && (((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                        || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_unset_row14 = (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14);
        uint64_t l_def_mcb_addr_row14_10 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && (((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row14_12 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                              && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && (((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)
                                                      || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)))
                                            || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11) && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8))
                                                && (((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                        || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row14_13 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && (((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row1_24 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row1_26 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row1_23 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row1_25 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row0_24 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row0_26 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row0_25 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row0_27 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row2_22 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row2_24 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row2_23 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row2_25 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row5_22 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row5_20 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row5_21 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row5_19 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row3_22 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row3_24 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row3_21 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row3_23 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_col13_29 = (l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12);
        uint64_t l_def_mcb_addr_unset_col13 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                               || (l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11));
        uint64_t l_def_mcb_addr_row7_17 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row7_20 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row7_18 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row7_19 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row6_20 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row6_21 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row6_18 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row6_19 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row4_22 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row4_20 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_row4_21 = ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_16)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))) || (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12)
                                                             && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                                     || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17))));
        uint64_t l_def_mcb_addr_row4_23 = (((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10)
                                            && (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS == literal_8)) && ((((l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_14)
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_15)) || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_16))
                                                    || (l_TGT0_ATTR_CEN_EFF_DRAM_ROWS == literal_17)));
        uint64_t l_def_mcb_addr_col11_30 = ((l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_11)
                                            || (l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_12));
        uint64_t l_def_mcb_addr_unset_col11 = (l_TGT0_ATTR_CEN_EFF_DRAM_COLS == literal_10);
        fapi2::ATTR_CEN_EFF_SCHMOO_ADDR_MODE_Type l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SCHMOO_ADDR_MODE, TGT0, l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE));
        fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID_Type l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SCHMOO_TEST_VALID, TGT0, l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID));
        uint64_t l_def_mcb_addr_total22_max22 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_22));
        uint64_t l_def_mcb_addr_total28_max29 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_28));
        uint64_t l_def_mcb_addr_total25_max28 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_25));
        uint64_t l_def_mcb_addr_total26_max28 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_26));
        uint64_t l_def_mcb_addr_total27_max28 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_27));
        uint64_t l_def_mcb_addr_total28_max28 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_28));
        uint64_t l_def_mcb_addr_total22_max25 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_22));
        uint64_t l_def_mcb_addr_total23_max25 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_23));
        uint64_t l_def_mcb_addr_total24_max25 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_24));
        uint64_t l_def_mcb_addr_total25_max25 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_25));
        uint64_t l_def_mcb_addr_total22_max23 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_22));
        uint64_t l_def_mcb_addr_total23_max23 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_23));
        uint64_t l_def_mcb_addr_total22_max24 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_22));
        uint64_t l_def_mcb_addr_total23_max24 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_23));
        uint64_t l_def_mcb_addr_total24_max24 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_24));
        uint64_t l_def_mcb_addr_total27_max30 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_27));
        uint64_t l_def_mcb_addr_total28_max30 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_28));
        uint64_t l_def_mcb_addr_total23_max26 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_23));
        uint64_t l_def_mcb_addr_total24_max26 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_24));
        uint64_t l_def_mcb_addr_total25_max26 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_25));
        uint64_t l_def_mcb_addr_total26_max26 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_26));
        uint64_t l_def_mcb_addr_total28_max31 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_28));
        uint64_t l_def_mcb_addr_total24_max27 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_24));
        uint64_t l_def_mcb_addr_total25_max27 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_25));
        uint64_t l_def_mcb_addr_total26_max27 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_26));
        uint64_t l_def_mcb_addr_total27_max27 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] <
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_2))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_27));
        uint64_t l_def_mcb_addr_total26_max29 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_8))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_26));
        uint64_t l_def_mcb_addr_total27_max29 = ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] ==
                                                (l_TGT0_ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM[literal_0][literal_0] + literal_4))
                                                && ((((l_TGT0_ATTR_CEN_EFF_DRAM_COLS - literal_3) + (l_TGT0_ATTR_CEN_EFF_DRAM_BANKS / literal_4)) +
                                                        l_TGT0_ATTR_CEN_EFF_DRAM_ROWS) == literal_27));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301040aull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000101 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 6, 58, uint64_t>(literal_0b000011 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000000 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>((l_def_RDODT_start_lrdimm + l_def_RDODT_duration) );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>((l_def_RDODT_start_udimm + l_def_RDODT_duration) );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>((l_def_RDODT_start_rdimm + l_def_RDODT_duration) );
            }

            if ((l_def_mba_dsm0q_cfg_rdtag_dly14 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b001110 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly20 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010100 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly25 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b011001 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly15 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b001111 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly28 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b011100 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly13 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b001101 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly16 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010000 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly29 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b011101 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly26 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b011010 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly18 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010010 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly24 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b011000 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly23 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010111 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly22 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010110 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly17 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010001 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly12 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b001100 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly21 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010101 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly19 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010011 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly27 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b011011 + l_def_margin_rdtag) );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))
            {
                l_scom_buffer.insert<43, 6, 58, uint64_t>(((l_def_RDODT_start_rdimm + l_def_RDODT_duration) - literal_2) );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3))
            {
                l_scom_buffer.insert<43, 6, 58, uint64_t>(((l_def_RDODT_start_lrdimm + l_def_RDODT_duration) - literal_2) );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
            {
                l_scom_buffer.insert<43, 6, 58, uint64_t>(((l_def_RDODT_start_udimm + l_def_RDODT_duration) - literal_2) );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(l_def_RDODT_start_udimm );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(l_def_RDODT_start_lrdimm );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(l_def_RDODT_start_rdimm );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000101 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b011000 );
            }

            if ((l_def_ddr4_1600_13_12_11_2N == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((l_def_WL_AL_MINUS2 - literal_1) );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2) && (l_TGT0_ATTR_CEN_EFF_DRAM_AL == literal_2)))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(l_def_WL_AL_MINUS2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2) && (l_TGT0_ATTR_CEN_EFF_DRAM_AL == literal_1)))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(l_def_WL_AL_MINUS1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2) && (l_TGT0_ATTR_CEN_EFF_DRAM_AL == literal_0)))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(l_def_WL_AL0 );
            }
            else if ((((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1) || (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3))
                      && (l_TGT0_ATTR_CEN_EFF_DRAM_AL == literal_2)))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((l_def_WL_AL_MINUS2 + l_def_WLO) );
            }
            else if ((((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1) || (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3))
                      && (l_TGT0_ATTR_CEN_EFF_DRAM_AL == literal_0)))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((l_def_WL_AL0 + l_def_WLO) );
            }
            else if ((((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1) || (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3))
                      && (l_TGT0_ATTR_CEN_EFF_DRAM_AL == literal_1)))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((l_def_WL_AL_MINUS1 + l_def_WLO) );
            }

            if ((l_def_mba_dsm0q_cfg_rdtag_dly14 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b001110 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly20 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010100 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly25 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b011001 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly15 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b001111 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly28 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b011100 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly13 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b001101 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly16 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010000 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly29 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b011101 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly26 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b011010 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly18 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010010 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly24 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b011000 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly23 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010111 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly22 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010110 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly17 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010001 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly12 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b001100 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly21 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010101 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly19 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b010011 + l_def_margin_rdtag) );
            }
            else if ((l_def_mba_dsm0q_cfg_rdtag_dly27 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>((literal_0b011011 + l_def_margin_rdtag) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<42, 1, 63, uint64_t>(literal_0 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
            {
                l_scom_buffer.insert<43, 6, 58, uint64_t>(((l_def_RDODT_start_udimm + l_def_RDODT_duration) - literal_2) );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))
            {
                l_scom_buffer.insert<43, 6, 58, uint64_t>(((l_def_RDODT_start_rdimm + l_def_RDODT_duration) - literal_2) );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3))
            {
                l_scom_buffer.insert<43, 6, 58, uint64_t>(((l_def_RDODT_start_lrdimm + l_def_RDODT_duration) - literal_2) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 6, 58, uint64_t>(literal_0b000011 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 5, 59, uint64_t>(literal_0b00000 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>((l_def_RDODT_start_lrdimm + l_def_RDODT_duration) );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>((l_def_RDODT_start_udimm + l_def_RDODT_duration) );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>((l_def_RDODT_start_rdimm + l_def_RDODT_duration) );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(l_def_RDODT_start_udimm );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(l_def_RDODT_start_lrdimm );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(l_def_RDODT_start_rdimm );
            }

            if ((l_def_ddr4_1600_13_12_11_2N == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((l_def_WL_AL_MINUS2 - literal_1) );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2) && (l_TGT0_ATTR_CEN_EFF_DRAM_AL == literal_2)))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(l_def_WL_AL_MINUS2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2) && (l_TGT0_ATTR_CEN_EFF_DRAM_AL == literal_1)))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(l_def_WL_AL_MINUS1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2) && (l_TGT0_ATTR_CEN_EFF_DRAM_AL == literal_0)))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(l_def_WL_AL0 );
            }
            else if ((((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1) || (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3))
                      && (l_TGT0_ATTR_CEN_EFF_DRAM_AL == literal_2)))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((l_def_WL_AL_MINUS2 + l_def_WLO) );
            }
            else if ((((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1) || (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3))
                      && (l_TGT0_ATTR_CEN_EFF_DRAM_AL == literal_0)))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((l_def_WL_AL0 + l_def_WLO) );
            }
            else if ((((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1) || (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3))
                      && (l_TGT0_ATTR_CEN_EFF_DRAM_AL == literal_1)))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((l_def_WL_AL_MINUS1 + l_def_WLO) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b011000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301040aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301040bull, l_scom_buffer ));

            if ((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2400))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>((literal_0b1001 + l_def_margin2) );
            }
            else if ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066) || (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333))
                      || (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>((literal_0b0111 + l_def_margin2) );
            }
            else if (((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866) || (l_TGT1_ATTR_CEN_MSS_FREQ == literal_2133)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>((literal_0b1000 + l_def_margin2) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(l_TGT0_ATTR_CEN_EFF_DRAM_TRRD );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }
            else if ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                       && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_1][literal_0] == literal_2)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                               && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_0][literal_0] == literal_2))))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>((literal_0b0101 + l_def_margin2) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<44, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }
            else if ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                       && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_1][literal_0] == literal_2)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                               && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_0][literal_0] == literal_2))))
            {
                l_scom_buffer.insert<44, 4, 60, uint64_t>((literal_0b0101 + l_def_margin2) );
            }

            if ((l_def_mba_tmr0q_WRSM_dlys23 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b010111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys21 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b010101 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys30 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011110 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys28 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011100 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys29 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011101 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys33 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b100001 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys27 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011011 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys15 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b001111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys32 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b100000 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys31 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys19 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b010011 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys20 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b010100 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys25 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011001 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys26 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011010 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys24 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011000 + l_def_margin2) );
            }

            if ((l_def_mba_tmr0q_RW_dlys11 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1011 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys8 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1000 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys7 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b0111 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys15 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1111 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys10 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1010 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys13 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1101 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys14 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1110 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys16 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b0000 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys9 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1001 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys12 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1100 + l_def_margin1) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }
            else if ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                       && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_1][literal_0] == literal_2)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                               && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_0][literal_0] == literal_2))))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>((literal_0b0101 + l_def_margin2) );
            }

            if ((l_def_mba_tmr0q_RW_dlys11 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1011 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys8 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1000 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys7 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b0111 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys15 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1111 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys10 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1010 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys13 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1101 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys14 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1110 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys16 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b0000 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys9 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1001 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys12 == literal_1))
            {
                l_scom_buffer.insert<12, 4, 60, uint64_t>((literal_0b1100 + l_def_margin1) );
            }

            if ((l_def_mba_tmr0q_RW_dlys11 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1011 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys8 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1000 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys7 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b0111 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys15 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1111 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys10 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1010 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys13 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1101 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys14 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1110 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys16 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b0000 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys9 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1001 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys12 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1100 + l_def_margin1) );
            }

            if ((l_def_mba_tmr0q_RW_dlys11 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1011 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys8 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1000 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys7 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b0111 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys15 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1111 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys10 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1010 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys13 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1101 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys14 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1110 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys16 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b0000 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys9 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1001 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys12 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1100 + l_def_margin1) );
            }

            if ((l_def_mba_tmr0q_WRSM_dlys23 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b010111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys21 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b010101 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys30 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011110 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys28 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011100 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys29 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011101 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys33 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b100001 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys27 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011011 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys15 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b001111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys32 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b100000 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys31 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys19 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b010011 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys20 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b010100 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys25 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011001 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys26 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011010 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys24 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>((literal_0b011000 + l_def_margin2) );
            }

            if ((l_def_mba_tmr0q_WRSM_dlys23 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b010111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys30 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011110 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys28 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011100 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys29 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011101 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys33 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b100001 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys15 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b001111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys27 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011011 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys32 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b100000 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys31 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys25 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011001 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys26 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011010 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys24 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011000 + l_def_margin2) );
            }

            if ((l_def_mba_tmr0q_WRDM_dlys7 == literal_1))
            {
                l_scom_buffer.insert<36, 4, 60, uint64_t>((literal_0b0111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRDM_dlys8 == literal_1))
            {
                l_scom_buffer.insert<36, 4, 60, uint64_t>((literal_0b1000 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRDM_dlys4 == literal_1))
            {
                l_scom_buffer.insert<36, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRDM_dlys5 == literal_1))
            {
                l_scom_buffer.insert<36, 4, 60, uint64_t>((literal_0b0101 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRDM_dlys6 == literal_1))
            {
                l_scom_buffer.insert<36, 4, 60, uint64_t>((literal_0b0110 + l_def_margin2) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<40, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }
            else if ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                       && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_1][literal_0] == literal_2)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                               && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_0][literal_0] == literal_2))))
            {
                l_scom_buffer.insert<40, 4, 60, uint64_t>((literal_0b0101 + l_def_margin2) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<44, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }
            else if ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                       && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_1][literal_0] == literal_2)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                               && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_0][literal_0] == literal_2))))
            {
                l_scom_buffer.insert<44, 4, 60, uint64_t>((literal_0b0101 + l_def_margin2) );
            }

            if ((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2400))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>((literal_0b1001 + l_def_margin2) );
            }
            else if ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066) || (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333))
                      || (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>((literal_0b0111 + l_def_margin2) );
            }
            else if (((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866) || (l_TGT1_ATTR_CEN_MSS_FREQ == literal_2133)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>((literal_0b1000 + l_def_margin2) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<4, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }
            else if ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                       && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_1][literal_0] == literal_2)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                               && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_0][literal_0] == literal_2))))
            {
                l_scom_buffer.insert<4, 4, 60, uint64_t>((literal_0b0101 + l_def_margin2) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(l_TGT0_ATTR_CEN_EFF_DRAM_TRRD );
            }

            if ((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2400))
            {
                l_scom_buffer.insert<8, 4, 60, uint64_t>((literal_0b1001 + l_def_margin2) );
            }
            else if ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066) || (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333))
                      || (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)))
            {
                l_scom_buffer.insert<8, 4, 60, uint64_t>((literal_0b0111 + l_def_margin2) );
            }
            else if (((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866) || (l_TGT1_ATTR_CEN_MSS_FREQ == literal_2133)))
            {
                l_scom_buffer.insert<8, 4, 60, uint64_t>((literal_0b1000 + l_def_margin2) );
            }

            if ((l_def_mba_tmr0q_WRSM_dlys23 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b010111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys30 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011110 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys28 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011100 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys29 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011101 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys33 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b100001 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys15 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b001111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys27 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011011 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys32 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b100000 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys31 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys25 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011001 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys26 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011010 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRSM_dlys24 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>((literal_0b011000 + l_def_margin2) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }

            if ((l_TGT1_ATTR_CEN_MSS_FREQ == literal_2400))
            {
                l_scom_buffer.insert<8, 4, 60, uint64_t>((literal_0b1001 + l_def_margin2) );
            }
            else if ((((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1066) || (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1333))
                      || (l_TGT1_ATTR_CEN_MSS_FREQ == literal_1600)))
            {
                l_scom_buffer.insert<8, 4, 60, uint64_t>((literal_0b0111 + l_def_margin2) );
            }
            else if (((l_TGT1_ATTR_CEN_MSS_FREQ == literal_1866) || (l_TGT1_ATTR_CEN_MSS_FREQ == literal_2133)))
            {
                l_scom_buffer.insert<8, 4, 60, uint64_t>((literal_0b1000 + l_def_margin2) );
            }

            if ((l_def_mba_tmr0q_WRDM_dlys7 == literal_1))
            {
                l_scom_buffer.insert<36, 4, 60, uint64_t>((literal_0b0111 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRDM_dlys8 == literal_1))
            {
                l_scom_buffer.insert<36, 4, 60, uint64_t>((literal_0b1000 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRDM_dlys4 == literal_1))
            {
                l_scom_buffer.insert<36, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRDM_dlys5 == literal_1))
            {
                l_scom_buffer.insert<36, 4, 60, uint64_t>((literal_0b0101 + l_def_margin2) );
            }
            else if ((l_def_mba_tmr0q_WRDM_dlys6 == literal_1))
            {
                l_scom_buffer.insert<36, 4, 60, uint64_t>((literal_0b0110 + l_def_margin2) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<4, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }
            else if ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                       && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_1][literal_0] == literal_2)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                               && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_0][literal_0] == literal_2))))
            {
                l_scom_buffer.insert<4, 4, 60, uint64_t>((literal_0b0101 + l_def_margin2) );
            }

            if ((l_def_mba_tmr0q_RW_dlys11 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1011 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys8 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1000 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys7 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b0111 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys15 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1111 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys10 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1010 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys13 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1101 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys14 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1110 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys16 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b0000 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys9 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1001 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys12 == literal_1))
            {
                l_scom_buffer.insert<16, 4, 60, uint64_t>((literal_0b1100 + l_def_margin1) );
            }

            if ((l_def_mba_tmr0q_RW_dlys11 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1011 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys8 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1000 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys7 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b0111 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys15 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1111 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys10 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1010 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys13 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1101 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys14 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1110 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys16 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b0000 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys9 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1001 + l_def_margin1) );
            }
            else if ((l_def_mba_tmr0q_RW_dlys12 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>((literal_0b1100 + l_def_margin1) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<40, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }
            else if ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                       && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_1][literal_0] == literal_2)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                               && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_0][literal_0] == literal_2))))
            {
                l_scom_buffer.insert<40, 4, 60, uint64_t>((literal_0b0101 + l_def_margin2) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>((literal_0b0100 + l_def_margin2) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301040bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301040cull, l_scom_buffer ));

            if ((l_def_mba_tmr1q_cfg_trap43 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0101011 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap27 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0011011 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap26 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0011010 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap46 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0101110 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap42 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0101010 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap38 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0100110 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap28 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0011100 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap40 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0101000 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap37 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0100101 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap32 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0100000 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap33 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0100001 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap44 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0101100 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap39 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0100111 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_TFAW != literal_16))
            {
                l_scom_buffer.insert<14, 6, 58, uint64_t>(l_TGT0_ATTR_CEN_EFF_DRAM_TFAW );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TFAW == literal_16))
            {
                l_scom_buffer.insert<14, 6, 58, uint64_t>(literal_0b0001111 );
            }

            if (((l_def_mba_tmr1q_RRSBG_dlys5 == literal_1) || (((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                    && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_1][literal_0] == literal_2)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                            && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_0][literal_0] == literal_2)))))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0b0101 );
            }
            else if ((l_def_mba_tmr1q_RRSBG_dlys6 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0b0110 );
            }
            else if ((l_def_mba_tmr1q_RRSBG_dlys0 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0b0000 );
            }

            if ((l_def_mba_tmr1q_WRSBG_dlys30 == literal_1))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b11110 );
            }
            else if ((l_def_mba_tmr1q_WRSBG_dlys19 == literal_1))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b10011 );
            }
            else if ((l_def_mba_tmr1q_WRSBG_dlys31 == literal_1))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_mba_tmr1q_WRSBG_dlys29 == literal_1))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b11101 );
            }
            else if ((l_def_mba_tmr1q_WRSBG_dlys0 == literal_1))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if ((l_def_mba_tmr1q_WRSBG_dlys27 == literal_1))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b11011 );
            }
            else if ((l_def_mba_tmr1q_WRSBG_dlys26 == literal_1))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b11010 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<47, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_def_mba_tmr0q_RW_dlys16 == literal_1))
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_def_mba_tmr0q_RW_dlys16 == literal_1))
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_def_mba_tmr0q_RW_dlys16 == literal_1))
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_def_mba_tmr1q_cfg_twap53 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0110101 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap48 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0110000 );
            }
            else if ((l_def_ddr4_1600_13_12_11 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0101111 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap51 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0110011 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap46 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0101110 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap42 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0101010 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap34 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0100010 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap37 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0100101 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap49 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0110001 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap32 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0100000 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap30 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0011110 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap39 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0100111 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap44 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0101100 );
            }

            if (((l_def_mba_tmr1q_RRSBG_dlys5 == literal_1) || (((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                    && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_1][literal_0] == literal_2)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                            && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_0][literal_0] == literal_2)))))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0b0101 );
            }
            else if ((l_def_mba_tmr1q_RRSBG_dlys6 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0b0110 );
            }
            else if ((l_def_mba_tmr1q_RRSBG_dlys0 == literal_1))
            {
                l_scom_buffer.insert<20, 4, 60, uint64_t>(literal_0b0000 );
            }

            if ((l_def_mba_tmr1q_cfg_twap53 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0110101 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap48 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0110000 );
            }
            else if ((l_def_ddr4_1600_13_12_11 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0101111 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap51 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0110011 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap46 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0101110 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap42 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0101010 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap34 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0100010 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap37 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0100101 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap49 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0110001 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap32 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0100000 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap30 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0011110 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap39 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0100111 );
            }
            else if ((l_def_mba_tmr1q_cfg_twap44 == literal_1))
            {
                l_scom_buffer.insert<7, 7, 57, uint64_t>(literal_0b0101100 );
            }

            if ((l_def_mba_tmr0q_RW_dlys16 == literal_1))
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_def_mba_tmr1q_WRSBG_dlys30 == literal_1))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b11110 );
            }
            else if ((((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1)
                       && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_1][literal_0] == literal_2)) || ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0)
                               && (l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_0][literal_0] == literal_2))))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b10011 );
            }
            else if ((l_def_mba_tmr1q_WRSBG_dlys31 == literal_1))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_mba_tmr1q_WRSBG_dlys29 == literal_1))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b11101 );
            }
            else if ((l_def_mba_tmr1q_WRSBG_dlys0 == literal_1))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if ((l_def_mba_tmr1q_WRSBG_dlys27 == literal_1))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b11011 );
            }
            else if ((l_def_mba_tmr1q_WRSBG_dlys26 == literal_1))
            {
                l_scom_buffer.insert<24, 5, 59, uint64_t>(literal_0b11010 );
            }

            if ((l_def_mba_tmr0q_RW_dlys16 == literal_1))
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_TFAW != literal_16))
            {
                l_scom_buffer.insert<14, 6, 58, uint64_t>(l_TGT0_ATTR_CEN_EFF_DRAM_TFAW );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TFAW == literal_16))
            {
                l_scom_buffer.insert<14, 6, 58, uint64_t>(literal_0b0001111 );
            }

            if ((l_def_mba_tmr0q_RW_dlys16 == literal_1))
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_def_mba_tmr1q_cfg_trap43 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0101011 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap27 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0011011 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap26 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0011010 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap46 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0101110 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap42 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0101010 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap38 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0100110 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap28 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0011100 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap40 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0101000 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap37 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0100101 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap32 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0100000 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap33 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0100001 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap44 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0101100 );
            }
            else if ((l_def_mba_tmr1q_cfg_trap39 == literal_1))
            {
                l_scom_buffer.insert<0, 7, 57, uint64_t>(literal_0b0100111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301040cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301040eull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301040eull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301040full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<13, 4, 60, uint64_t>(literal_0b0100 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0b00000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<25, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<19, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<39, 8, 56, uint64_t>(literal_0b01000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<13, 4, 60, uint64_t>(literal_0b0100 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<19, 4, 60, uint64_t>(literal_0b0000 );
            }

            if ((l_def_zq_intv_sel10 > literal_511))
            {
                l_scom_buffer.insert<1, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_zq_intv_sel10 < literal_512))
            {
                l_scom_buffer.insert<1, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<25, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<29, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<30, 9, 55, uint64_t>(literal_0b000000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<39, 8, 56, uint64_t>(literal_0b01000000 );
            }

            if (((l_def_zq_intv_sel10 > literal_511) && (l_def_zq_intv_sel11 == literal_0)))
            {
                l_scom_buffer.insert<3, 9, 55, uint64_t>(literal_0b000000001 );
            }
            else if ((l_def_zq_intv_sel10 < literal_512))
            {
                l_scom_buffer.insert<3, 9, 55, uint64_t>(l_def_zq_intv_sel10 );
            }
            else if (((l_def_zq_intv_sel10 > literal_511) && (l_def_zq_intv_sel11 > literal_0)))
            {
                l_scom_buffer.insert<3, 9, 55, uint64_t>(l_def_zq_intv_sel11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<47, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(literal_0b00000000 );
            }

            if (((l_def_zq_intv_sel10 > literal_511) && (l_def_zq_intv_sel11 == literal_0)))
            {
                l_scom_buffer.insert<3, 9, 55, uint64_t>(literal_0b000000001 );
            }
            else if ((l_def_zq_intv_sel10 < literal_512))
            {
                l_scom_buffer.insert<3, 9, 55, uint64_t>(l_def_zq_intv_sel10 );
            }
            else if (((l_def_zq_intv_sel10 > literal_511) && (l_def_zq_intv_sel11 > literal_0)))
            {
                l_scom_buffer.insert<3, 9, 55, uint64_t>(l_def_zq_intv_sel11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<47, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<29, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_def_zq_intv_sel10 > literal_511))
            {
                l_scom_buffer.insert<1, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_zq_intv_sel10 < literal_512))
            {
                l_scom_buffer.insert<1, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<30, 9, 55, uint64_t>(literal_0b000000000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301040full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010410ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_def_mem_intv_sel10 > literal_511) && (l_def_mem_intv_sel11 > literal_0)))
            {
                l_scom_buffer.insert<3, 9, 55, uint64_t>(l_def_mem_intv_sel11 );
            }
            else if ((l_def_mem_intv_sel10 < literal_512))
            {
                l_scom_buffer.insert<3, 9, 55, uint64_t>(l_def_mem_intv_sel10 );
            }
            else if (((l_def_mem_intv_sel10 > literal_511) && (l_def_mem_intv_sel11 == literal_0)))
            {
                l_scom_buffer.insert<3, 9, 55, uint64_t>(literal_0b000000001 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<30, 9, 55, uint64_t>(literal_0b000000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<13, 4, 60, uint64_t>(literal_0b0011 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<19, 4, 60, uint64_t>(literal_0b0000 );
            }

            if ((l_def_mem_intv_sel10 > literal_511))
            {
                l_scom_buffer.insert<1, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_mem_intv_sel10 < literal_512))
            {
                l_scom_buffer.insert<1, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<25, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<29, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<30, 9, 55, uint64_t>(literal_0b000000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<39, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_def_mem_intv_sel10 > literal_511) && (l_def_mem_intv_sel11 > literal_0)))
            {
                l_scom_buffer.insert<3, 9, 55, uint64_t>(l_def_mem_intv_sel11 );
            }
            else if ((l_def_mem_intv_sel10 < literal_512))
            {
                l_scom_buffer.insert<3, 9, 55, uint64_t>(l_def_mem_intv_sel10 );
            }
            else if (((l_def_mem_intv_sel10 > literal_511) && (l_def_mem_intv_sel11 == literal_0)))
            {
                l_scom_buffer.insert<3, 9, 55, uint64_t>(literal_0b000000001 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<40, 24, 40, uint64_t>(literal_0b000000000000000000000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<25, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<40, 24, 40, uint64_t>(literal_0b000000000000000000000000 );
            }

            if ((l_def_mem_intv_sel10 > literal_511))
            {
                l_scom_buffer.insert<1, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_mem_intv_sel10 < literal_512))
            {
                l_scom_buffer.insert<1, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<19, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<13, 4, 60, uint64_t>(literal_0b0011 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<29, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<23, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010410ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010412ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<42, 8, 56, uint64_t>(literal_0b11111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<10, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 8, 56, uint64_t>(literal_0b11111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<20, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<22, 8, 56, uint64_t>(literal_0b11111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<2, 8, 56, uint64_t>(literal_0b11111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<30, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0b11111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<40, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<42, 8, 56, uint64_t>(literal_0b11111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 8, 56, uint64_t>(literal_0b11111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 8, 56, uint64_t>(literal_0b11111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<40, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<32, 8, 56, uint64_t>(literal_0b11111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<2, 8, 56, uint64_t>(literal_0b11111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 8, 56, uint64_t>(literal_0b11111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<30, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<22, 8, 56, uint64_t>(literal_0b11111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<20, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<10, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010412ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010413ull, l_scom_buffer ));

            if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1) || (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3)))
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b1 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1) || (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3)))
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1) || (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3)))
            {
                l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE != literal_1) && (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE != literal_3)))
            {
                l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010413ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010414ull, l_scom_buffer ));

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010000 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b110100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010100 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111000 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b011100 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b011110 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b110100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b010001 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b010010 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b100000 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b101110 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b011010 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b011001 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b101000 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b010101 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b110110 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b100100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b010110 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111010 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011110 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011101 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b101100 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1101 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1101 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b101100 );
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b1 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_def_ddr4_1600_13_12_11 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_ddr4_1600_13_12_11_2N == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b110100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b110100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_ddr4_1600_13_12_11 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_ddr4_1600_13_12_11_2N == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111000 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111000 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_ddr4_1600_13_12_11 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_ddr4_1600_13_12_11_2N == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b011100 );
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b011110 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b010001 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b110100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b100000 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b010010 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b101110 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b011001 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b101000 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b011010 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b110110 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b010101 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b100100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b010110 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111010 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011101 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011110 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_ddr4_1600_13_12_11 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_ddr4_1600_13_12_11_2N == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b110100 );
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b11001 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b11011 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b11111 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b11001 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b11001 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b11001 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b11111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010414ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010415ull, l_scom_buffer ));

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b100000 );
            }
            else if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b100000 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b100100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b100000 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b100000 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b101100 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b100100 );
            }
            else if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b100100 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b100100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b100100 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b100001 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111000 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b100010 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b101001 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b101010 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b100101 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b100110 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b101101 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b101110 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_IS3A_IS3B == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b101000 );
            }
            else if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b101000 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b101000 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b101000 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b111000 );
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_ddr4_1600_13_12_11 == literal_1))
            {
            }
            else if ((l_def_ddr4_1600_13_12_11_2N == literal_1))
            {
            }
            else if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_ddr4_1600_13_12_11 == literal_1))
            {
            }
            else if ((l_def_ddr4_1600_13_12_11_2N == literal_1))
            {
            }
            else if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_ddr4_1600_13_12_11 == literal_1))
            {
            }
            else if ((l_def_ddr4_1600_13_12_11_2N == literal_1))
            {
            }
            else if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b100000 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b100100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b100000 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b100000 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b101100 );
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b101000 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b101000 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b101000 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b111000 );
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b100100 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b100100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b100100 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b101100 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b100001 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111000 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b100010 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b101001 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b101010 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_ddr4_1600_13_12_11 == literal_1))
            {
            }
            else if ((l_def_ddr4_1600_13_12_11_2N == literal_1))
            {
            }
            else if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b100101 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b100110 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_C3b == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b101101 );
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS5D == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }
            else if ((l_def_IS7C == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b101110 );
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b111100 );
            }

            if ((l_def_C3b == literal_1))
            {
            }
            else if ((l_def_C3c == literal_1))
            {
            }
            else if ((l_def_C3c_C4C_ddr4 == literal_1))
            {
            }
            else if ((l_def_C4A_ddr4 == literal_1))
            {
            }
            else if ((l_def_IS1A_IS1B_IS1D_C1A_C1B_C1C_C1D_C5C == literal_1))
            {
            }
            else if ((l_def_IS3b_IS7b == literal_1))
            {
            }
            else if ((l_def_IS5D == literal_1))
            {
            }
            else if ((l_def_IS7C == literal_1))
            {
            }
            else if ((l_def_IS7a_C4a_C3a == literal_1))
            {
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010415ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010416ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 15, 49, uint64_t>(l_TGT0_ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<15, 16, 48, uint64_t>(l_TGT0_ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<31, 14, 50, uint64_t>(l_TGT0_ATTR_CEN_MSS_MEM_THROTTLE_DENOMINATOR );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_MSS_THROTTLE_CONTROL_RAS_WEIGHT );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_MSS_THROTTLE_CONTROL_CAS_WEIGHT );
            }

            if ((((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1) || ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                    && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_0))) || (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3)))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2) && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1) || ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                    && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_0))) || (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3)))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2) && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1) || ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                    && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_0))) || (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3)))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2) && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)))
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_1) || ((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                    && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_0))) || (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_3)))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == literal_2) && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1)))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<45, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_MSS_THROTTLE_CONTROL_RAS_WEIGHT );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<15, 16, 48, uint64_t>(l_TGT0_ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_MSS_THROTTLE_CONTROL_CAS_WEIGHT );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<31, 14, 50, uint64_t>(l_TGT0_ATTR_CEN_MSS_MEM_THROTTLE_DENOMINATOR );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 15, 49, uint64_t>(l_TGT0_ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010416ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010417ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<10, 2, 62, uint64_t>(literal_0b01 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 7, 57, uint64_t>(literal_0b0000011 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<19, 7, 57, uint64_t>(literal_0b0000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<27, 15, 49, uint64_t>(l_TGT2_ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<42, 14, 50, uint64_t>(l_TGT2_ATTR_CEN_MRW_MEM_THROTTLE_DENOMINATOR );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<4, 6, 58, uint64_t>(literal_0b000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<42, 14, 50, uint64_t>(l_TGT2_ATTR_CEN_MRW_MEM_THROTTLE_DENOMINATOR );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<27, 15, 49, uint64_t>(l_TGT2_ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010417ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010432ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<30, 10, 54, uint64_t>(l_TGT0_ATTR_CEN_EFF_DRAM_TRFC );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<20, 10, 53, uint64_t>(literal_0b00011000010 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<5, 4, 60, uint64_t>(literal_0b0111 );
            }

            if ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0))
            {
                l_scom_buffer.insert<9, 11, 53, uint64_t>(l_def_mba01_refresh_interval );
            }
            else if ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1))
            {
                l_scom_buffer.insert<9, 11, 53, uint64_t>(l_def_mba23_refresh_interval );
            }

            if (((l_def_ddr4_1600_13_12_11 == literal_1) || (l_def_IS3A_IS3B == literal_1)))
            {
                l_scom_buffer.insert<40, 10, 54, uint64_t>(literal_0b0001100000 );
            }
            else if ((l_def_MBAREF0Q_cfg_refr_tsv_stack_dly64 == literal_1))
            {
                l_scom_buffer.insert<40, 10, 54, uint64_t>(literal_0b0001000000 );
            }
            else if ((l_def_MBAREF0Q_cfg_refr_tsv_stack_dly48 == literal_1))
            {
                l_scom_buffer.insert<40, 10, 54, uint64_t>(literal_0b0000110000 );
            }
            else if ((l_def_MBAREF0Q_cfg_refr_tsv_stack_dly32 == literal_1))
            {
                l_scom_buffer.insert<40, 10, 54, uint64_t>(literal_0b0000100000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<50, 11, 53, uint64_t>(l_def_refresh_check_interval );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<4, 4, 60, uint64_t>(literal_0b0111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<19, 11, 53, uint64_t>(literal_0b00011000010 );
            }

            if ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0))
            {
                l_scom_buffer.insert<8, 11, 53, uint64_t>(l_def_mba01_refresh_interval );
            }
            else if ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1))
            {
                l_scom_buffer.insert<8, 11, 53, uint64_t>(l_def_mba23_refresh_interval );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010432ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010433ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 16, 48, uint64_t>(l_TGT0_ATTR_CEN_VPD_CKE_PRI_MAP[literal_0] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<16, 16, 48, uint64_t>(l_TGT0_ATTR_CEN_VPD_CKE_PRI_MAP[literal_1] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 16, 48, uint64_t>(l_TGT0_ATTR_CEN_VPD_CKE_PRI_MAP[literal_0] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<16, 16, 48, uint64_t>(l_TGT0_ATTR_CEN_VPD_CKE_PRI_MAP[literal_1] );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 4, 48, uint64_t>(l_TGT0_ATTR_CEN_VPD_CKE_PRI_MAP[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010433ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010434ull, l_scom_buffer ));

            if ((l_def_MBARPC0Q_cfg_pup_pdn_dly4 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_0b00100 );
            }
            else if ((l_def_MBARPC0Q_cfg_pup_pdn_dly5 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_0b00101 );
            }
            else if ((l_def_MBARPC0Q_cfg_pup_pdn_dly3 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_0b00011 );
            }
            else if ((l_def_MBARPC0Q_cfg_pup_pdn_dly6 == literal_1))
            {
                l_scom_buffer.insert<16, 5, 59, uint64_t>(literal_0b00110 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<43, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1)
                  && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                      || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3)))
                 || ((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2)
                     && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                         || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3)))))
            {
                l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b1 );
            }
            else if ((((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_0)
                       || ((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1)
                           && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_0)
                               || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2))))
                      || ((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2)
                          && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_0)
                              || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)))))
            {
                l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((((l_def_MBARPC0Q_cfg_pup_avail_dly7 == literal_1) && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1))
                 && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                     || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b00111 + l_def_margin_pup_slow) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly5 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b00101 + l_def_margin_pup_slow) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly29 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b11100 + l_def_margin_pup_fast) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly6 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b00101 + l_def_margin_pup_fast) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly13 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b01100 + l_def_margin_pup_fast) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly8 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b01000 + l_def_margin_pup_slow) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly29 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b11101 + l_def_margin_pup_slow) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly26 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b11010 + l_def_margin_pup_slow) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly5 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b00100 + l_def_margin_pup_fast) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly26 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b11001 + l_def_margin_pup_fast) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly16 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b01111 + l_def_margin_pup_fast) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly20 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b10011 + l_def_margin_pup_fast) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly13 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b01101 + l_def_margin_pup_slow) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly7 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b00110 + l_def_margin_pup_fast) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly4 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b00100 + l_def_margin_pup_slow) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly23 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b10111 + l_def_margin_pup_slow) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly6 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b00110 + l_def_margin_pup_slow) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly20 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b10100 + l_def_margin_pup_slow) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly4 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b00011 + l_def_margin_pup_fast) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly23 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b10110 + l_def_margin_pup_fast) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly16 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b10000 + l_def_margin_pup_slow) );
            }
            else if ((((l_def_MBARPC0Q_cfg_pup_avail_dly8 == literal_1)
                       && (l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2))
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<6, 5, 59, uint64_t>((literal_0b00111 + l_def_margin_pup_fast) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<23, 10, 54, uint64_t>(literal_0b0000000011 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<42, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_def_MBARPC0Q_cfg_pdn_pup_dly4 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b00100 );
            }
            else if ((l_def_MBARPC0Q_cfg_pdn_pup_dly5 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b00101 );
            }
            else if ((l_def_MBARPC0Q_cfg_pdn_pup_dly3 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b00011 );
            }
            else if ((l_def_MBARPC0Q_cfg_pdn_pup_dly6 == literal_1))
            {
                l_scom_buffer.insert<11, 5, 59, uint64_t>(literal_0b00110 );
            }

            if ((((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1)
                  && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                      || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3)))
                 || ((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2)
                     && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                         || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3)))))
            {
                l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_0b1 );
            }
            else if ((((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_0)
                       || ((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1)
                           && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_0)
                               || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2))))
                      || ((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2)
                          && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_0)
                              || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)))))
            {
                l_scom_buffer.insert<22, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010434ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010435ull, l_scom_buffer ));

            if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2)
                 && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                     || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
            }
            else if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1)
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
            }

            if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1)
                 && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                     || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
            }
            else if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2)
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
            }

            if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2)
                 && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                     || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<0, 16, 48, uint64_t>(l_TGT0_ATTR_CEN_VPD_CKE_PRI_MAP[literal_0] );
            }
            else if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1)
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<0, 16, 48, uint64_t>(l_def_shift_pwr_map4 );
            }

            if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1)
                 && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                     || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<16, 16, 48, uint64_t>(l_def_shift_pwr_map8 );
            }
            else if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2)
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<16, 16, 48, uint64_t>(l_TGT0_ATTR_CEN_VPD_CKE_PRI_MAP[literal_1] );
            }

            if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2)
                 && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                     || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<32, 16, 48, uint64_t>(l_TGT0_ATTR_CEN_VPD_CKE_PRI_MAP[literal_0] );
            }
            else if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1)
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<32, 16, 48, uint64_t>(l_def_shift_pwr_map12 );
            }

            if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1)
                 && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                     || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(l_TGT0_ATTR_CEN_VPD_CKE_PWR_MAP );
            }
            else if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2)
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(l_TGT0_ATTR_CEN_VPD_CKE_PRI_MAP[literal_1] );
            }

            if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2)
                 && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                     || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<0, 4, 48, uint64_t>(l_TGT0_ATTR_CEN_VPD_CKE_PRI_MAP[literal_0] );
            }
            else if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1)
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
                l_scom_buffer.insert<0, 4, 48, uint64_t>(l_def_shift_pwr_map4 );
            }

            if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_1)
                 && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_1)
                     || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
            }
            else if (((l_TGT2_ATTR_CEN_MRW_POWER_CONTROL_REQUESTED == literal_2)
                      && ((l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_2)
                          || (l_TGT1_ATTR_CEN_VPD_POWER_CONTROL_CAPABLE == literal_3))))
            {
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010435ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010436ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 3, 61, uint64_t>(literal_0b011 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
            }

            if ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_0))
            {
            }
            else if ((l_TGT0_ATTR_CHIP_UNIT_POS == literal_1))
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x6591B48421021400 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010436ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010614ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<6, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010614ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106a7ull, l_scom_buffer ));

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_GEN != literal_2))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_GEN == literal_2))
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<6, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106a7ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106a8ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<46, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<36, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<6, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<8, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<43, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<22, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<40, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<32, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<14, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<16, 3, 61, uint64_t>(literal_0b001 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<20, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<22, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<27, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<28, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<30, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<32, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<36, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<37, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<38, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<40, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<43, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<44, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<46, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<4, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<6, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<8, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<44, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<28, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<20, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<16, 3, 61, uint64_t>(literal_0b001 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<38, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<30, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<35, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<21, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<14, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<37, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106a8ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106beull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x1111111111111111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106beull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106bfull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x2222222222222222 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106bfull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106c0ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x3333333333333333 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106c0ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106c1ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x4444444444444444 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106c1ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106c2ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x5555555555555555 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106c2ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106c3ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x6666666666666666 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106c3ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106c4ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x7777777777777777 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106c4ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106c5ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x8888888888888888 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106c5ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106c6ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x9999999999999999 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106c6ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106c7ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xAAAAAAAAAAAAAAAA );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106c7ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106c8ull, l_scom_buffer ));

            if ((l_def_mcb_addr_bank2_28 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_mcb_addr_bank2_26 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b011010 );
            }
            else if ((l_def_mcb_addr_bank2_27 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b011011 );
            }

            if ((((((l_def_mcb_addr_col10_bnk16_srank0_9 || l_def_mcb_addr_col11_bnk16_srank0_9)
                    || l_def_mcb_addr_col10_bnk8_srank0_9) || l_def_mcb_addr_col11_bnk8_srank0_9)
                  || l_def_mcb_addr_col12_bnk8_srank0_9) == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((((l_def_mcb_addr_col11_bnk16_srank0_6 || l_def_mcb_addr_col12_bnk16_srank0_6)
                       || l_def_mcb_addr_col12_bnk8_srank0_6) == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b000110 );
            }
            else if ((l_def_mcb_addr_col12_bnk16_srank0_5 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b000101 );
            }
            else if ((l_def_mcb_srank0_unset == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (((((l_def_mcb_addr_col10_bnk8_srank0_10 || l_def_mcb_addr_col11_bnk8_srank0_10)
                        || l_def_mcb_addr_col10_bnk16_srank0_10) || l_def_mcb_addr_col10_bnk8_srank0_11) == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001010 );
            }
            else if (((((((l_def_mcb_addr_col10_bnk16_srank0_8 || l_def_mcb_addr_col11_bnk16_srank0_8)
                          || l_def_mcb_addr_col12_bnk16_srank0_8) || l_def_mcb_addr_col10_bnk8_srank0_8) || l_def_mcb_addr_col11_bnk8_srank0_8)
                       || l_def_mcb_addr_col12_bnk8_srank0_8) == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if ((((((l_def_mcb_addr_col10_bnk16_srank0_7 || l_def_mcb_addr_col11_bnk16_srank0_7)
                         || l_def_mcb_addr_col12_bnk16_srank0_7) || l_def_mcb_addr_col11_bnk8_srank0_7)
                       || l_def_mcb_addr_col12_bnk8_srank0_7) == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b000111 );
            }

            if ((((((((((l_def_mcb_addr_row17_col10_bnk16_mrank3_6 || l_def_mcb_addr_row16_col11_bnk16_mrank3_6)
                        || l_def_mcb_addr_row17_col11_bnk16_mrank3_6) || l_def_mcb_addr_row15_col12_bnk16_mrank3_6)
                      || l_def_mcb_addr_row16_col12_bnk16_mrank3_6) || l_def_mcb_addr_row17_col12_bnk16_mrank3_6)
                    || l_def_mcb_addr_row17_col11_bnk8_mrank3_6) || l_def_mcb_addr_row16_col12_bnk8_mrank3_6)
                  || l_def_mcb_addr_row17_col12_bnk8_mrank3_6) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000110 );
            }
            else if ((l_def_mcb_addr_row17_col12_bnk16_mrank3_4 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000100 );
            }
            else if (((((l_def_mcb_addr_row17_col11_bnk16_mrank3_5 || l_def_mcb_addr_row16_col12_bnk16_mrank3_5)
                        || l_def_mcb_addr_row17_col12_bnk16_mrank3_5) || l_def_mcb_addr_row17_col12_bnk8_mrank3_5) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000101 );
            }
            else if ((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank3_11 || l_def_mcb_addr_row15_col10_bnk16_mrank3_11)
                             || l_def_mcb_addr_row14_col11_bnk16_mrank3_11) || l_def_mcb_addr_row16_col10_bnk8_mrank3_11)
                           || l_def_mcb_addr_row15_col11_bnk8_mrank3_11) || l_def_mcb_addr_row14_col12_bnk8_mrank3_11)
                         || l_def_mcb_addr_row14_col10_bnk8_mrank3_11) || l_def_mcb_addr_row15_col10_bnk8_mrank3_11)
                       || l_def_mcb_addr_row14_col11_bnk8_mrank3_11) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_mrank3_unset == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (((((((((((((((((((((l_def_mcb_addr_row15_col10_bnk16_mrank3_8 || l_def_mcb_addr_row17_col11_bnk16_mrank3_8)
                                        || l_def_mcb_addr_row16_col12_bnk16_mrank3_8) || l_def_mcb_addr_row17_col12_bnk8_mrank3_8)
                                      || l_def_mcb_addr_row16_col10_bnk16_mrank3_8) || l_def_mcb_addr_row17_col10_bnk16_mrank3_8)
                                    || l_def_mcb_addr_row14_col11_bnk16_mrank3_8) || l_def_mcb_addr_row15_col11_bnk16_mrank3_8)
                                  || l_def_mcb_addr_row16_col11_bnk16_mrank3_8) || l_def_mcb_addr_row14_col12_bnk16_mrank3_8)
                                || l_def_mcb_addr_row15_col12_bnk16_mrank3_8) || l_def_mcb_addr_row16_col10_bnk8_mrank3_8)
                              || l_def_mcb_addr_row17_col10_bnk8_mrank3_8) || l_def_mcb_addr_row14_col11_bnk8_mrank3_8)
                            || l_def_mcb_addr_row15_col11_bnk8_mrank3_8) || l_def_mcb_addr_row16_col11_bnk8_mrank3_8)
                          || l_def_mcb_addr_row17_col11_bnk8_mrank3_8) || l_def_mcb_addr_row14_col12_bnk8_mrank3_8)
                        || l_def_mcb_addr_row15_col12_bnk8_mrank3_8) || l_def_mcb_addr_row16_col12_bnk8_mrank3_8) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if ((((((((((((((((l_def_mcb_addr_row16_col10_bnk16_mrank3_7 || l_def_mcb_addr_row17_col12_bnk16_mrank3_7)
                                   || l_def_mcb_addr_row17_col10_bnk16_mrank3_7) || l_def_mcb_addr_row15_col11_bnk16_mrank3_7)
                                 || l_def_mcb_addr_row16_col11_bnk16_mrank3_7) || l_def_mcb_addr_row17_col11_bnk16_mrank3_7)
                               || l_def_mcb_addr_row14_col12_bnk16_mrank3_7) || l_def_mcb_addr_row15_col12_bnk16_mrank3_7)
                             || l_def_mcb_addr_row16_col12_bnk16_mrank3_7) || l_def_mcb_addr_row17_col10_bnk8_mrank3_7)
                           || l_def_mcb_addr_row16_col11_bnk8_mrank3_7) || l_def_mcb_addr_row17_col11_bnk8_mrank3_7)
                         || l_def_mcb_addr_row15_col12_bnk8_mrank3_7) || l_def_mcb_addr_row16_col12_bnk8_mrank3_7)
                       || l_def_mcb_addr_row17_col12_bnk8_mrank3_7) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000111 );
            }
            else if (((((l_def_mcb_addr_row14_col10_bnk8_mrank3_12 || l_def_mcb_addr_row14_col10_bnk16_mrank3_12)
                        || l_def_mcb_addr_row15_col10_bnk8_mrank3_12) || l_def_mcb_addr_row14_col11_bnk8_mrank3_12) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001100 );
            }
            else if (((((((((((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank3_9 || l_def_mcb_addr_row17_col10_bnk16_mrank3_9)
                                      || l_def_mcb_addr_row16_col11_bnk16_mrank3_9) || l_def_mcb_addr_row15_col12_bnk16_mrank3_9)
                                    || l_def_mcb_addr_row17_col11_bnk8_mrank3_9) || l_def_mcb_addr_row16_col12_bnk8_mrank3_9)
                                  || l_def_mcb_addr_row15_col10_bnk16_mrank3_9) || l_def_mcb_addr_row16_col10_bnk16_mrank3_9)
                                || l_def_mcb_addr_row14_col11_bnk16_mrank3_9) || l_def_mcb_addr_row15_col11_bnk16_mrank3_9)
                              || l_def_mcb_addr_row14_col12_bnk16_mrank3_9) || l_def_mcb_addr_row15_col10_bnk8_mrank3_9)
                            || l_def_mcb_addr_row16_col10_bnk8_mrank3_9) || l_def_mcb_addr_row17_col10_bnk8_mrank3_9)
                          || l_def_mcb_addr_row15_col11_bnk8_mrank3_9) || l_def_mcb_addr_row16_col11_bnk8_mrank3_9)
                        || l_def_mcb_addr_row14_col12_bnk8_mrank3_9) || l_def_mcb_addr_row15_col12_bnk8_mrank3_9) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((((((((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank3_10 || l_def_mcb_addr_row16_col10_bnk16_mrank3_10)
                                   || l_def_mcb_addr_row15_col11_bnk16_mrank3_10) || l_def_mcb_addr_row14_col12_bnk16_mrank3_10)
                                 || l_def_mcb_addr_row17_col10_bnk8_mrank3_10) || l_def_mcb_addr_row16_col11_bnk8_mrank3_10)
                               || l_def_mcb_addr_row15_col12_bnk8_mrank3_10) || l_def_mcb_addr_row15_col10_bnk16_mrank3_10)
                             || l_def_mcb_addr_row14_col11_bnk16_mrank3_10) || l_def_mcb_addr_row14_col10_bnk8_mrank3_10)
                           || l_def_mcb_addr_row15_col10_bnk8_mrank3_10) || l_def_mcb_addr_row16_col10_bnk8_mrank3_10)
                         || l_def_mcb_addr_row14_col11_bnk8_mrank3_10) || l_def_mcb_addr_row15_col11_bnk8_mrank3_10)
                       || l_def_mcb_addr_row14_col12_bnk8_mrank3_10) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001010 );
            }
            else if ((l_def_mcb_addr_row14_col10_bnk8_mrank3_13 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001101 );
            }

            if (((((((l_def_mcb_addr_col10_bnk16_srank1_9 || l_def_mcb_addr_col11_bnk16_srank1_9)
                     || l_def_mcb_addr_col12_bnk16_srank1_9) || l_def_mcb_addr_col10_bnk8_srank1_9) || l_def_mcb_addr_col11_bnk8_srank1_9)
                  || l_def_mcb_addr_col12_bnk8_srank1_9) == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((l_def_mcb_addr_col12_bnk16_srank1_6 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b000110 );
            }
            else if ((((l_def_mcb_addr_col10_bnk16_srank1_11 || l_def_mcb_addr_col10_bnk8_srank1_11)
                       || l_def_mcb_addr_col11_bnk8_srank1_11) == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_srank1_unset == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((((((l_def_mcb_addr_col10_bnk16_srank1_10 || l_def_mcb_addr_col11_bnk16_srank1_10)
                         || l_def_mcb_addr_col10_bnk8_srank1_10) || l_def_mcb_addr_col11_bnk8_srank1_10)
                       || l_def_mcb_addr_col12_bnk8_srank1_10) == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001010 );
            }
            else if ((((((l_def_mcb_addr_col10_bnk16_srank1_8 || l_def_mcb_addr_col11_bnk16_srank1_8)
                         || l_def_mcb_addr_col12_bnk16_srank1_8) || l_def_mcb_addr_col11_bnk8_srank1_8)
                       || l_def_mcb_addr_col12_bnk8_srank1_8) == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if ((((l_def_mcb_addr_col11_bnk16_srank1_7 || l_def_mcb_addr_col12_bnk16_srank1_7)
                       || l_def_mcb_addr_col12_bnk8_srank1_7) == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b000111 );
            }
            else if ((l_def_mcb_addr_col10_bnk8_srank1_12 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001100 );
            }

            if ((l_def_mcb_addr_bank1_28 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_mcb_addr_bank1_29 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b011101 );
            }
            else if ((l_def_mcb_addr_bank1_27 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b011011 );
            }

            if ((((((((((((((((l_def_mcb_addr_row16_col10_bnk16_mrank2_6 || l_def_mcb_addr_row17_col12_bnk16_mrank2_6)
                              || l_def_mcb_addr_row17_col10_bnk16_mrank2_6) || l_def_mcb_addr_row15_col11_bnk16_mrank2_6)
                            || l_def_mcb_addr_row16_col11_bnk16_mrank2_6) || l_def_mcb_addr_row17_col11_bnk16_mrank2_6)
                          || l_def_mcb_addr_row14_col12_bnk16_mrank2_6) || l_def_mcb_addr_row15_col12_bnk16_mrank2_6)
                        || l_def_mcb_addr_row16_col12_bnk16_mrank2_6) || l_def_mcb_addr_row17_col10_bnk8_mrank2_6)
                      || l_def_mcb_addr_row16_col11_bnk8_mrank2_6) || l_def_mcb_addr_row17_col11_bnk8_mrank2_6)
                    || l_def_mcb_addr_row15_col12_bnk8_mrank2_6) || l_def_mcb_addr_row16_col12_bnk8_mrank2_6)
                  || l_def_mcb_addr_row17_col12_bnk8_mrank2_6) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000110 );
            }
            else if (((((l_def_mcb_addr_row17_col11_bnk16_mrank2_4 || l_def_mcb_addr_row16_col12_bnk16_mrank2_4)
                        || l_def_mcb_addr_row17_col12_bnk16_mrank2_4) || l_def_mcb_addr_row17_col12_bnk8_mrank2_4) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000100 );
            }
            else if ((((((((((l_def_mcb_addr_row17_col10_bnk16_mrank2_5 || l_def_mcb_addr_row16_col11_bnk16_mrank2_5)
                             || l_def_mcb_addr_row17_col11_bnk16_mrank2_5) || l_def_mcb_addr_row15_col12_bnk16_mrank2_5)
                           || l_def_mcb_addr_row16_col12_bnk16_mrank2_5) || l_def_mcb_addr_row17_col12_bnk16_mrank2_5)
                         || l_def_mcb_addr_row17_col11_bnk8_mrank2_5) || l_def_mcb_addr_row16_col12_bnk8_mrank2_5)
                       || l_def_mcb_addr_row17_col12_bnk8_mrank2_5) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000101 );
            }
            else if (((((l_def_mcb_addr_row14_col10_bnk8_mrank2_11 || l_def_mcb_addr_row14_col10_bnk16_mrank2_11)
                        || l_def_mcb_addr_row15_col10_bnk8_mrank2_11) || l_def_mcb_addr_row14_col11_bnk8_mrank2_11) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if (l_def_mcb_mrank2_unset)
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (((((((((((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank2_8 || l_def_mcb_addr_row17_col10_bnk16_mrank2_8)
                                      || l_def_mcb_addr_row16_col11_bnk16_mrank2_8) || l_def_mcb_addr_row15_col12_bnk16_mrank2_8)
                                    || l_def_mcb_addr_row17_col11_bnk8_mrank2_8) || l_def_mcb_addr_row16_col12_bnk8_mrank2_8)
                                  || l_def_mcb_addr_row15_col10_bnk16_mrank2_8) || l_def_mcb_addr_row16_col10_bnk16_mrank2_8)
                                || l_def_mcb_addr_row14_col11_bnk16_mrank2_8) || l_def_mcb_addr_row15_col11_bnk16_mrank2_8)
                              || l_def_mcb_addr_row14_col12_bnk16_mrank2_8) || l_def_mcb_addr_row15_col10_bnk8_mrank2_8)
                            || l_def_mcb_addr_row16_col10_bnk8_mrank2_8) || l_def_mcb_addr_row17_col10_bnk8_mrank2_8)
                          || l_def_mcb_addr_row15_col11_bnk8_mrank2_8) || l_def_mcb_addr_row16_col11_bnk8_mrank2_8)
                        || l_def_mcb_addr_row14_col12_bnk8_mrank2_8) || l_def_mcb_addr_row15_col12_bnk8_mrank2_8) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if (((((((((((((((((((((l_def_mcb_addr_row15_col10_bnk16_mrank2_7 || l_def_mcb_addr_row17_col11_bnk16_mrank2_7)
                                        || l_def_mcb_addr_row16_col12_bnk16_mrank2_7) || l_def_mcb_addr_row17_col12_bnk8_mrank2_7)
                                      || l_def_mcb_addr_row16_col10_bnk16_mrank2_7) || l_def_mcb_addr_row17_col10_bnk16_mrank2_7)
                                    || l_def_mcb_addr_row14_col11_bnk16_mrank2_7) || l_def_mcb_addr_row15_col11_bnk16_mrank2_7)
                                  || l_def_mcb_addr_row16_col11_bnk16_mrank2_7) || l_def_mcb_addr_row14_col12_bnk16_mrank2_7)
                                || l_def_mcb_addr_row15_col12_bnk16_mrank2_7) || l_def_mcb_addr_row16_col10_bnk8_mrank2_7)
                              || l_def_mcb_addr_row17_col10_bnk8_mrank2_7) || l_def_mcb_addr_row14_col11_bnk8_mrank2_7)
                            || l_def_mcb_addr_row15_col11_bnk8_mrank2_7) || l_def_mcb_addr_row16_col11_bnk8_mrank2_7)
                          || l_def_mcb_addr_row17_col11_bnk8_mrank2_7) || l_def_mcb_addr_row14_col12_bnk8_mrank2_7)
                        || l_def_mcb_addr_row15_col12_bnk8_mrank2_7) || l_def_mcb_addr_row16_col12_bnk8_mrank2_7) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000111 );
            }
            else if ((l_def_mcb_addr_row14_col10_bnk8_mrank2_12 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001100 );
            }
            else if ((((((((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank2_9 || l_def_mcb_addr_row16_col10_bnk16_mrank2_9)
                                   || l_def_mcb_addr_row15_col11_bnk16_mrank2_9) || l_def_mcb_addr_row14_col12_bnk16_mrank2_9)
                                 || l_def_mcb_addr_row17_col10_bnk8_mrank2_9) || l_def_mcb_addr_row16_col11_bnk8_mrank2_9)
                               || l_def_mcb_addr_row15_col12_bnk8_mrank2_9) || l_def_mcb_addr_row15_col10_bnk16_mrank2_9)
                             || l_def_mcb_addr_row14_col11_bnk16_mrank2_9) || l_def_mcb_addr_row14_col10_bnk8_mrank2_9)
                           || l_def_mcb_addr_row15_col10_bnk8_mrank2_9) || l_def_mcb_addr_row16_col10_bnk8_mrank2_9)
                         || l_def_mcb_addr_row14_col11_bnk8_mrank2_9) || l_def_mcb_addr_row15_col11_bnk8_mrank2_9)
                       || l_def_mcb_addr_row14_col12_bnk8_mrank2_9) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((l_def_mcb_addr_row17_col12_bnk16_mrank2_3 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000011 );
            }
            else if ((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank2_10 || l_def_mcb_addr_row15_col10_bnk16_mrank2_10)
                             || l_def_mcb_addr_row14_col11_bnk16_mrank2_10) || l_def_mcb_addr_row16_col10_bnk8_mrank2_10)
                           || l_def_mcb_addr_row15_col11_bnk8_mrank2_10) || l_def_mcb_addr_row14_col12_bnk8_mrank2_10)
                         || l_def_mcb_addr_row14_col10_bnk8_mrank2_10) || l_def_mcb_addr_row15_col10_bnk8_mrank2_10)
                       || l_def_mcb_addr_row14_col11_bnk8_mrank2_10) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001010 );
            }

            if (((((l_def_mcb_addr_col11_bnk16_srank2_11 || l_def_mcb_addr_col10_bnk8_srank2_11)
                   || l_def_mcb_addr_col11_bnk8_srank2_11) || l_def_mcb_addr_col12_bnk8_srank2_11) == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_srank2_unset == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((((l_def_mcb_addr_col11_bnk16_srank2_8 || l_def_mcb_addr_col12_bnk16_srank2_8)
                       || l_def_mcb_addr_col12_bnk8_srank2_8) == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if ((l_def_mcb_addr_col12_bnk16_srank2_7 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b000111 );
            }
            else if ((((l_def_mcb_addr_col10_bnk16_srank2_12 || l_def_mcb_addr_col10_bnk8_srank2_12)
                       || l_def_mcb_addr_col11_bnk8_srank2_12) == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001100 );
            }
            else if ((((((l_def_mcb_addr_col10_bnk16_srank2_9 || l_def_mcb_addr_col11_bnk16_srank2_9)
                         || l_def_mcb_addr_col12_bnk16_srank2_9) || l_def_mcb_addr_col11_bnk8_srank2_9)
                       || l_def_mcb_addr_col12_bnk8_srank2_9) == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((((((((l_def_mcb_addr_col10_bnk16_srank2_10 || l_def_mcb_addr_col11_bnk16_srank2_10)
                           || l_def_mcb_addr_col12_bnk16_srank2_10) || l_def_mcb_addr_col10_bnk8_srank2_10)
                         || l_def_mcb_addr_col11_bnk8_srank2_10) || l_def_mcb_addr_col12_bnk8_srank2_10)
                       || l_def_mcb_addr_col10_bnk16_srank2_11) == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001010 );
            }
            else if ((l_def_mcb_addr_col10_bnk8_srank2_13 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001101 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b000000 );
            }

            if (((((((((((((((((((((l_def_mcb_addr_row15_col10_bnk16_mrank1_6 || l_def_mcb_addr_row17_col11_bnk16_mrank1_6)
                                   || l_def_mcb_addr_row16_col12_bnk16_mrank1_6) || l_def_mcb_addr_row17_col12_bnk8_mrank1_6)
                                 || l_def_mcb_addr_row16_col10_bnk16_mrank1_6) || l_def_mcb_addr_row17_col10_bnk16_mrank1_6)
                               || l_def_mcb_addr_row14_col11_bnk16_mrank1_6) || l_def_mcb_addr_row15_col11_bnk16_mrank1_6)
                             || l_def_mcb_addr_row16_col11_bnk16_mrank1_6) || l_def_mcb_addr_row14_col12_bnk16_mrank1_6)
                           || l_def_mcb_addr_row15_col12_bnk16_mrank1_6) || l_def_mcb_addr_row16_col10_bnk8_mrank1_6)
                         || l_def_mcb_addr_row17_col10_bnk8_mrank1_6) || l_def_mcb_addr_row14_col11_bnk8_mrank1_6)
                       || l_def_mcb_addr_row15_col11_bnk8_mrank1_6) || l_def_mcb_addr_row16_col11_bnk8_mrank1_6)
                     || l_def_mcb_addr_row17_col11_bnk8_mrank1_6) || l_def_mcb_addr_row14_col12_bnk8_mrank1_6)
                   || l_def_mcb_addr_row15_col12_bnk8_mrank1_6) || l_def_mcb_addr_row16_col12_bnk8_mrank1_6) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000110 );
            }
            else if ((((((((((l_def_mcb_addr_row17_col10_bnk16_mrank1_4 || l_def_mcb_addr_row16_col11_bnk16_mrank1_4)
                             || l_def_mcb_addr_row17_col11_bnk16_mrank1_4) || l_def_mcb_addr_row15_col12_bnk16_mrank1_4)
                           || l_def_mcb_addr_row16_col12_bnk16_mrank1_4) || l_def_mcb_addr_row17_col12_bnk16_mrank1_4)
                         || l_def_mcb_addr_row17_col11_bnk8_mrank1_4) || l_def_mcb_addr_row16_col12_bnk8_mrank1_4)
                       || l_def_mcb_addr_row17_col12_bnk8_mrank1_4) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000100 );
            }
            else if ((((((((((((((((l_def_mcb_addr_row16_col10_bnk16_mrank1_5 || l_def_mcb_addr_row17_col12_bnk16_mrank1_5)
                                   || l_def_mcb_addr_row17_col10_bnk16_mrank1_5) || l_def_mcb_addr_row15_col11_bnk16_mrank1_5)
                                 || l_def_mcb_addr_row16_col11_bnk16_mrank1_5) || l_def_mcb_addr_row17_col11_bnk16_mrank1_5)
                               || l_def_mcb_addr_row14_col12_bnk16_mrank1_5) || l_def_mcb_addr_row15_col12_bnk16_mrank1_5)
                             || l_def_mcb_addr_row16_col12_bnk16_mrank1_5) || l_def_mcb_addr_row17_col10_bnk8_mrank1_5)
                           || l_def_mcb_addr_row16_col11_bnk8_mrank1_5) || l_def_mcb_addr_row17_col11_bnk8_mrank1_5)
                         || l_def_mcb_addr_row15_col12_bnk8_mrank1_5) || l_def_mcb_addr_row16_col12_bnk8_mrank1_5)
                       || l_def_mcb_addr_row17_col12_bnk8_mrank1_5) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000101 );
            }
            else if ((l_def_mcb_addr_row14_col10_bnk8_mrank1_11 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_mrank1_unset == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((((((((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank1_8 || l_def_mcb_addr_row16_col10_bnk16_mrank1_8)
                                   || l_def_mcb_addr_row15_col11_bnk16_mrank1_8) || l_def_mcb_addr_row14_col12_bnk16_mrank1_8)
                                 || l_def_mcb_addr_row17_col10_bnk8_mrank1_8) || l_def_mcb_addr_row16_col11_bnk8_mrank1_8)
                               || l_def_mcb_addr_row15_col12_bnk8_mrank1_8) || l_def_mcb_addr_row15_col10_bnk16_mrank1_8)
                             || l_def_mcb_addr_row14_col11_bnk16_mrank1_8) || l_def_mcb_addr_row14_col10_bnk8_mrank1_8)
                           || l_def_mcb_addr_row15_col10_bnk8_mrank1_8) || l_def_mcb_addr_row16_col10_bnk8_mrank1_8)
                         || l_def_mcb_addr_row14_col11_bnk8_mrank1_8) || l_def_mcb_addr_row15_col11_bnk8_mrank1_8)
                       || l_def_mcb_addr_row14_col12_bnk8_mrank1_8) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if (((((((((((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank1_7 || l_def_mcb_addr_row17_col10_bnk16_mrank1_7)
                                      || l_def_mcb_addr_row16_col11_bnk16_mrank1_7) || l_def_mcb_addr_row15_col12_bnk16_mrank1_7)
                                    || l_def_mcb_addr_row17_col11_bnk8_mrank1_7) || l_def_mcb_addr_row16_col12_bnk8_mrank1_7)
                                  || l_def_mcb_addr_row15_col10_bnk16_mrank1_7) || l_def_mcb_addr_row16_col10_bnk16_mrank1_7)
                                || l_def_mcb_addr_row14_col11_bnk16_mrank1_7) || l_def_mcb_addr_row15_col11_bnk16_mrank1_7)
                              || l_def_mcb_addr_row14_col12_bnk16_mrank1_7) || l_def_mcb_addr_row15_col10_bnk8_mrank1_7)
                            || l_def_mcb_addr_row16_col10_bnk8_mrank1_7) || l_def_mcb_addr_row17_col10_bnk8_mrank1_7)
                          || l_def_mcb_addr_row15_col11_bnk8_mrank1_7) || l_def_mcb_addr_row16_col11_bnk8_mrank1_7)
                        || l_def_mcb_addr_row14_col12_bnk8_mrank1_7) || l_def_mcb_addr_row15_col12_bnk8_mrank1_7) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000111 );
            }
            else if ((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank1_9 || l_def_mcb_addr_row15_col10_bnk16_mrank1_9)
                             || l_def_mcb_addr_row14_col11_bnk16_mrank1_9) || l_def_mcb_addr_row16_col10_bnk8_mrank1_9)
                           || l_def_mcb_addr_row15_col11_bnk8_mrank1_9) || l_def_mcb_addr_row14_col12_bnk8_mrank1_9)
                         || l_def_mcb_addr_row14_col10_bnk8_mrank1_9) || l_def_mcb_addr_row15_col10_bnk8_mrank1_9)
                       || l_def_mcb_addr_row14_col11_bnk8_mrank1_9) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if (((((l_def_mcb_addr_row17_col11_bnk16_mrank1_3 || l_def_mcb_addr_row16_col12_bnk16_mrank1_3)
                        || l_def_mcb_addr_row17_col12_bnk16_mrank1_3) || l_def_mcb_addr_row17_col12_bnk8_mrank1_3) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000011 );
            }
            else if ((l_def_mcb_addr_row17_col12_bnk16_mrank1_2 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000010 );
            }
            else if (((((l_def_mcb_addr_row14_col10_bnk8_mrank1_10 || l_def_mcb_addr_row14_col10_bnk16_mrank1_10)
                        || l_def_mcb_addr_row15_col10_bnk8_mrank1_10) || l_def_mcb_addr_row14_col11_bnk8_mrank1_10) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001010 );
            }

            if ((l_def_mcb_addr_unset_bank3 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((l_def_mcb_addr_bank3_26 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011010 );
            }
            else if ((l_def_mcb_addr_bank3_25 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011001 );
            }
            else if ((l_def_mcb_addr_bank3_27 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011011 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b000000 );
            }

            if ((((((((((((((((l_def_mcb_addr_row16_col10_bnk16_mrank2_6 || l_def_mcb_addr_row17_col12_bnk16_mrank2_6)
                              || l_def_mcb_addr_row17_col10_bnk16_mrank2_6) || l_def_mcb_addr_row15_col11_bnk16_mrank2_6)
                            || l_def_mcb_addr_row16_col11_bnk16_mrank2_6) || l_def_mcb_addr_row17_col11_bnk16_mrank2_6)
                          || l_def_mcb_addr_row14_col12_bnk16_mrank2_6) || l_def_mcb_addr_row15_col12_bnk16_mrank2_6)
                        || l_def_mcb_addr_row16_col12_bnk16_mrank2_6) || l_def_mcb_addr_row17_col10_bnk8_mrank2_6)
                      || l_def_mcb_addr_row16_col11_bnk8_mrank2_6) || l_def_mcb_addr_row17_col11_bnk8_mrank2_6)
                    || l_def_mcb_addr_row15_col12_bnk8_mrank2_6) || l_def_mcb_addr_row16_col12_bnk8_mrank2_6)
                  || l_def_mcb_addr_row17_col12_bnk8_mrank2_6) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000110 );
            }
            else if (((((l_def_mcb_addr_row17_col11_bnk16_mrank2_4 || l_def_mcb_addr_row16_col12_bnk16_mrank2_4)
                        || l_def_mcb_addr_row17_col12_bnk16_mrank2_4) || l_def_mcb_addr_row17_col12_bnk8_mrank2_4) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000100 );
            }
            else if ((((((((((l_def_mcb_addr_row17_col10_bnk16_mrank2_5 || l_def_mcb_addr_row16_col11_bnk16_mrank2_5)
                             || l_def_mcb_addr_row17_col11_bnk16_mrank2_5) || l_def_mcb_addr_row15_col12_bnk16_mrank2_5)
                           || l_def_mcb_addr_row16_col12_bnk16_mrank2_5) || l_def_mcb_addr_row17_col12_bnk16_mrank2_5)
                         || l_def_mcb_addr_row17_col11_bnk8_mrank2_5) || l_def_mcb_addr_row16_col12_bnk8_mrank2_5)
                       || l_def_mcb_addr_row17_col12_bnk8_mrank2_5) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000101 );
            }
            else if (((((l_def_mcb_addr_row14_col10_bnk8_mrank2_11 || l_def_mcb_addr_row14_col10_bnk16_mrank2_11)
                        || l_def_mcb_addr_row15_col10_bnk8_mrank2_11) || l_def_mcb_addr_row14_col11_bnk8_mrank2_11) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if (l_def_mcb_mrank2_unset)
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (((((((((((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank2_8 || l_def_mcb_addr_row17_col10_bnk16_mrank2_8)
                                      || l_def_mcb_addr_row16_col11_bnk16_mrank2_8) || l_def_mcb_addr_row15_col12_bnk16_mrank2_8)
                                    || l_def_mcb_addr_row17_col11_bnk8_mrank2_8) || l_def_mcb_addr_row16_col12_bnk8_mrank2_8)
                                  || l_def_mcb_addr_row15_col10_bnk16_mrank2_8) || l_def_mcb_addr_row16_col10_bnk16_mrank2_8)
                                || l_def_mcb_addr_row14_col11_bnk16_mrank2_8) || l_def_mcb_addr_row15_col11_bnk16_mrank2_8)
                              || l_def_mcb_addr_row14_col12_bnk16_mrank2_8) || l_def_mcb_addr_row15_col10_bnk8_mrank2_8)
                            || l_def_mcb_addr_row16_col10_bnk8_mrank2_8) || l_def_mcb_addr_row17_col10_bnk8_mrank2_8)
                          || l_def_mcb_addr_row15_col11_bnk8_mrank2_8) || l_def_mcb_addr_row16_col11_bnk8_mrank2_8)
                        || l_def_mcb_addr_row14_col12_bnk8_mrank2_8) || l_def_mcb_addr_row15_col12_bnk8_mrank2_8) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if (((((((((((((((((((((l_def_mcb_addr_row15_col10_bnk16_mrank2_7 || l_def_mcb_addr_row17_col11_bnk16_mrank2_7)
                                        || l_def_mcb_addr_row16_col12_bnk16_mrank2_7) || l_def_mcb_addr_row17_col12_bnk8_mrank2_7)
                                      || l_def_mcb_addr_row16_col10_bnk16_mrank2_7) || l_def_mcb_addr_row17_col10_bnk16_mrank2_7)
                                    || l_def_mcb_addr_row14_col11_bnk16_mrank2_7) || l_def_mcb_addr_row15_col11_bnk16_mrank2_7)
                                  || l_def_mcb_addr_row16_col11_bnk16_mrank2_7) || l_def_mcb_addr_row14_col12_bnk16_mrank2_7)
                                || l_def_mcb_addr_row15_col12_bnk16_mrank2_7) || l_def_mcb_addr_row16_col10_bnk8_mrank2_7)
                              || l_def_mcb_addr_row17_col10_bnk8_mrank2_7) || l_def_mcb_addr_row14_col11_bnk8_mrank2_7)
                            || l_def_mcb_addr_row15_col11_bnk8_mrank2_7) || l_def_mcb_addr_row16_col11_bnk8_mrank2_7)
                          || l_def_mcb_addr_row17_col11_bnk8_mrank2_7) || l_def_mcb_addr_row14_col12_bnk8_mrank2_7)
                        || l_def_mcb_addr_row15_col12_bnk8_mrank2_7) || l_def_mcb_addr_row16_col12_bnk8_mrank2_7) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000111 );
            }
            else if ((l_def_mcb_addr_row14_col10_bnk8_mrank2_12 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001100 );
            }
            else if ((((((((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank2_9 || l_def_mcb_addr_row16_col10_bnk16_mrank2_9)
                                   || l_def_mcb_addr_row15_col11_bnk16_mrank2_9) || l_def_mcb_addr_row14_col12_bnk16_mrank2_9)
                                 || l_def_mcb_addr_row17_col10_bnk8_mrank2_9) || l_def_mcb_addr_row16_col11_bnk8_mrank2_9)
                               || l_def_mcb_addr_row15_col12_bnk8_mrank2_9) || l_def_mcb_addr_row15_col10_bnk16_mrank2_9)
                             || l_def_mcb_addr_row14_col11_bnk16_mrank2_9) || l_def_mcb_addr_row14_col10_bnk8_mrank2_9)
                           || l_def_mcb_addr_row15_col10_bnk8_mrank2_9) || l_def_mcb_addr_row16_col10_bnk8_mrank2_9)
                         || l_def_mcb_addr_row14_col11_bnk8_mrank2_9) || l_def_mcb_addr_row15_col11_bnk8_mrank2_9)
                       || l_def_mcb_addr_row14_col12_bnk8_mrank2_9) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((l_def_mcb_addr_row17_col12_bnk16_mrank2_3 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000011 );
            }
            else if ((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank2_10 || l_def_mcb_addr_row15_col10_bnk16_mrank2_10)
                             || l_def_mcb_addr_row14_col11_bnk16_mrank2_10) || l_def_mcb_addr_row16_col10_bnk8_mrank2_10)
                           || l_def_mcb_addr_row15_col11_bnk8_mrank2_10) || l_def_mcb_addr_row14_col12_bnk8_mrank2_10)
                         || l_def_mcb_addr_row14_col10_bnk8_mrank2_10) || l_def_mcb_addr_row15_col10_bnk8_mrank2_10)
                       || l_def_mcb_addr_row14_col11_bnk8_mrank2_10) == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001010 );
            }

            if ((((((((((l_def_mcb_addr_row17_col10_bnk16_mrank3_6 || l_def_mcb_addr_row16_col11_bnk16_mrank3_6)
                        || l_def_mcb_addr_row17_col11_bnk16_mrank3_6) || l_def_mcb_addr_row15_col12_bnk16_mrank3_6)
                      || l_def_mcb_addr_row16_col12_bnk16_mrank3_6) || l_def_mcb_addr_row17_col12_bnk16_mrank3_6)
                    || l_def_mcb_addr_row17_col11_bnk8_mrank3_6) || l_def_mcb_addr_row16_col12_bnk8_mrank3_6)
                  || l_def_mcb_addr_row17_col12_bnk8_mrank3_6) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000110 );
            }
            else if ((l_def_mcb_addr_row17_col12_bnk16_mrank3_4 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000100 );
            }
            else if (((((l_def_mcb_addr_row17_col11_bnk16_mrank3_5 || l_def_mcb_addr_row16_col12_bnk16_mrank3_5)
                        || l_def_mcb_addr_row17_col12_bnk16_mrank3_5) || l_def_mcb_addr_row17_col12_bnk8_mrank3_5) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000101 );
            }
            else if ((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank3_11 || l_def_mcb_addr_row15_col10_bnk16_mrank3_11)
                             || l_def_mcb_addr_row14_col11_bnk16_mrank3_11) || l_def_mcb_addr_row16_col10_bnk8_mrank3_11)
                           || l_def_mcb_addr_row15_col11_bnk8_mrank3_11) || l_def_mcb_addr_row14_col12_bnk8_mrank3_11)
                         || l_def_mcb_addr_row14_col10_bnk8_mrank3_11) || l_def_mcb_addr_row15_col10_bnk8_mrank3_11)
                       || l_def_mcb_addr_row14_col11_bnk8_mrank3_11) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_mrank3_unset == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (((((((((((((((((((((l_def_mcb_addr_row15_col10_bnk16_mrank3_8 || l_def_mcb_addr_row17_col11_bnk16_mrank3_8)
                                        || l_def_mcb_addr_row16_col12_bnk16_mrank3_8) || l_def_mcb_addr_row17_col12_bnk8_mrank3_8)
                                      || l_def_mcb_addr_row16_col10_bnk16_mrank3_8) || l_def_mcb_addr_row17_col10_bnk16_mrank3_8)
                                    || l_def_mcb_addr_row14_col11_bnk16_mrank3_8) || l_def_mcb_addr_row15_col11_bnk16_mrank3_8)
                                  || l_def_mcb_addr_row16_col11_bnk16_mrank3_8) || l_def_mcb_addr_row14_col12_bnk16_mrank3_8)
                                || l_def_mcb_addr_row15_col12_bnk16_mrank3_8) || l_def_mcb_addr_row16_col10_bnk8_mrank3_8)
                              || l_def_mcb_addr_row17_col10_bnk8_mrank3_8) || l_def_mcb_addr_row14_col11_bnk8_mrank3_8)
                            || l_def_mcb_addr_row15_col11_bnk8_mrank3_8) || l_def_mcb_addr_row16_col11_bnk8_mrank3_8)
                          || l_def_mcb_addr_row17_col11_bnk8_mrank3_8) || l_def_mcb_addr_row14_col12_bnk8_mrank3_8)
                        || l_def_mcb_addr_row15_col12_bnk8_mrank3_8) || l_def_mcb_addr_row16_col12_bnk8_mrank3_8) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if ((((((((((((((((l_def_mcb_addr_row16_col10_bnk16_mrank3_7 || l_def_mcb_addr_row17_col12_bnk16_mrank3_7)
                                   || l_def_mcb_addr_row17_col10_bnk16_mrank3_7) || l_def_mcb_addr_row15_col11_bnk16_mrank3_7)
                                 || l_def_mcb_addr_row16_col11_bnk16_mrank3_7) || l_def_mcb_addr_row17_col11_bnk16_mrank3_7)
                               || l_def_mcb_addr_row14_col12_bnk16_mrank3_7) || l_def_mcb_addr_row15_col12_bnk16_mrank3_7)
                             || l_def_mcb_addr_row16_col12_bnk16_mrank3_7) || l_def_mcb_addr_row17_col10_bnk8_mrank3_7)
                           || l_def_mcb_addr_row16_col11_bnk8_mrank3_7) || l_def_mcb_addr_row17_col11_bnk8_mrank3_7)
                         || l_def_mcb_addr_row15_col12_bnk8_mrank3_7) || l_def_mcb_addr_row16_col12_bnk8_mrank3_7)
                       || l_def_mcb_addr_row17_col12_bnk8_mrank3_7) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000111 );
            }
            else if (((((l_def_mcb_addr_row14_col10_bnk8_mrank3_12 || l_def_mcb_addr_row14_col10_bnk16_mrank3_12)
                        || l_def_mcb_addr_row15_col10_bnk8_mrank3_12) || l_def_mcb_addr_row14_col11_bnk8_mrank3_12) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001100 );
            }
            else if (((((((((((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank3_9 || l_def_mcb_addr_row17_col10_bnk16_mrank3_9)
                                      || l_def_mcb_addr_row16_col11_bnk16_mrank3_9) || l_def_mcb_addr_row15_col12_bnk16_mrank3_9)
                                    || l_def_mcb_addr_row17_col11_bnk8_mrank3_9) || l_def_mcb_addr_row16_col12_bnk8_mrank3_9)
                                  || l_def_mcb_addr_row15_col10_bnk16_mrank3_9) || l_def_mcb_addr_row16_col10_bnk16_mrank3_9)
                                || l_def_mcb_addr_row14_col11_bnk16_mrank3_9) || l_def_mcb_addr_row15_col11_bnk16_mrank3_9)
                              || l_def_mcb_addr_row14_col12_bnk16_mrank3_9) || l_def_mcb_addr_row15_col10_bnk8_mrank3_9)
                            || l_def_mcb_addr_row16_col10_bnk8_mrank3_9) || l_def_mcb_addr_row17_col10_bnk8_mrank3_9)
                          || l_def_mcb_addr_row15_col11_bnk8_mrank3_9) || l_def_mcb_addr_row16_col11_bnk8_mrank3_9)
                        || l_def_mcb_addr_row14_col12_bnk8_mrank3_9) || l_def_mcb_addr_row15_col12_bnk8_mrank3_9) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((((((((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank3_10 || l_def_mcb_addr_row16_col10_bnk16_mrank3_10)
                                   || l_def_mcb_addr_row15_col11_bnk16_mrank3_10) || l_def_mcb_addr_row14_col12_bnk16_mrank3_10)
                                 || l_def_mcb_addr_row17_col10_bnk8_mrank3_10) || l_def_mcb_addr_row16_col11_bnk8_mrank3_10)
                               || l_def_mcb_addr_row15_col12_bnk8_mrank3_10) || l_def_mcb_addr_row15_col10_bnk16_mrank3_10)
                             || l_def_mcb_addr_row14_col11_bnk16_mrank3_10) || l_def_mcb_addr_row14_col10_bnk8_mrank3_10)
                           || l_def_mcb_addr_row15_col10_bnk8_mrank3_10) || l_def_mcb_addr_row16_col10_bnk8_mrank3_10)
                         || l_def_mcb_addr_row14_col11_bnk8_mrank3_10) || l_def_mcb_addr_row15_col11_bnk8_mrank3_10)
                       || l_def_mcb_addr_row14_col12_bnk8_mrank3_10) == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001010 );
            }
            else if ((l_def_mcb_addr_row14_col10_bnk8_mrank3_13 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001101 );
            }

            if ((((((l_def_mcb_addr_col10_bnk16_srank0_9 || l_def_mcb_addr_col11_bnk16_srank0_9)
                    || l_def_mcb_addr_col10_bnk8_srank0_9) || l_def_mcb_addr_col11_bnk8_srank0_9)
                  || l_def_mcb_addr_col12_bnk8_srank0_9) == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((((l_def_mcb_addr_col11_bnk16_srank0_6 || l_def_mcb_addr_col12_bnk16_srank0_6)
                       || l_def_mcb_addr_col12_bnk8_srank0_6) == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b000110 );
            }
            else if ((l_def_mcb_addr_col12_bnk16_srank0_5 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b000101 );
            }
            else if ((l_def_mcb_srank0_unset == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (((((l_def_mcb_addr_col10_bnk8_srank0_10 || l_def_mcb_addr_col11_bnk8_srank0_10)
                        || l_def_mcb_addr_col10_bnk16_srank0_10) || l_def_mcb_addr_col10_bnk8_srank0_11) == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001010 );
            }
            else if (((((((l_def_mcb_addr_col10_bnk16_srank0_8 || l_def_mcb_addr_col11_bnk16_srank0_8)
                          || l_def_mcb_addr_col12_bnk16_srank0_8) || l_def_mcb_addr_col10_bnk8_srank0_8) || l_def_mcb_addr_col11_bnk8_srank0_8)
                       || l_def_mcb_addr_col12_bnk8_srank0_8) == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if ((((((l_def_mcb_addr_col10_bnk16_srank0_7 || l_def_mcb_addr_col11_bnk16_srank0_7)
                         || l_def_mcb_addr_col12_bnk16_srank0_7) || l_def_mcb_addr_col11_bnk8_srank0_7)
                       || l_def_mcb_addr_col12_bnk8_srank0_7) == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b000111 );
            }

            if (((((((l_def_mcb_addr_col10_bnk16_srank1_9 || l_def_mcb_addr_col11_bnk16_srank1_9)
                     || l_def_mcb_addr_col12_bnk16_srank1_9) || l_def_mcb_addr_col10_bnk8_srank1_9) || l_def_mcb_addr_col11_bnk8_srank1_9)
                  || l_def_mcb_addr_col12_bnk8_srank1_9) == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((l_def_mcb_addr_col12_bnk16_srank1_6 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b000110 );
            }
            else if ((((l_def_mcb_addr_col10_bnk16_srank1_11 || l_def_mcb_addr_col10_bnk8_srank1_11)
                       || l_def_mcb_addr_col11_bnk8_srank1_11) == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_srank1_unset == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((((((l_def_mcb_addr_col10_bnk16_srank1_10 || l_def_mcb_addr_col11_bnk16_srank1_10)
                         || l_def_mcb_addr_col10_bnk8_srank1_10) || l_def_mcb_addr_col11_bnk8_srank1_10)
                       || l_def_mcb_addr_col12_bnk8_srank1_10) == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001010 );
            }
            else if ((((((l_def_mcb_addr_col10_bnk16_srank1_8 || l_def_mcb_addr_col11_bnk16_srank1_8)
                         || l_def_mcb_addr_col12_bnk16_srank1_8) || l_def_mcb_addr_col11_bnk8_srank1_8)
                       || l_def_mcb_addr_col12_bnk8_srank1_8) == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if ((((l_def_mcb_addr_col11_bnk16_srank1_7 || l_def_mcb_addr_col12_bnk16_srank1_7)
                       || l_def_mcb_addr_col12_bnk8_srank1_7) == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b000111 );
            }
            else if ((l_def_mcb_addr_col10_bnk8_srank1_12 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001100 );
            }

            if (((((l_def_mcb_addr_col11_bnk16_srank2_11 || l_def_mcb_addr_col10_bnk8_srank2_11)
                   || l_def_mcb_addr_col11_bnk8_srank2_11) || l_def_mcb_addr_col12_bnk8_srank2_11) == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_srank2_unset == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((((l_def_mcb_addr_col11_bnk16_srank2_8 || l_def_mcb_addr_col12_bnk16_srank2_8)
                       || l_def_mcb_addr_col12_bnk8_srank2_8) == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if ((l_def_mcb_addr_col12_bnk16_srank2_7 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b000111 );
            }
            else if ((((l_def_mcb_addr_col10_bnk16_srank2_12 || l_def_mcb_addr_col10_bnk8_srank2_12)
                       || l_def_mcb_addr_col11_bnk8_srank2_12) == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001100 );
            }
            else if ((((((l_def_mcb_addr_col10_bnk16_srank2_9 || l_def_mcb_addr_col11_bnk16_srank2_9)
                         || l_def_mcb_addr_col12_bnk16_srank2_9) || l_def_mcb_addr_col11_bnk8_srank2_9)
                       || l_def_mcb_addr_col12_bnk8_srank2_9) == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((((((((l_def_mcb_addr_col10_bnk16_srank2_10 || l_def_mcb_addr_col11_bnk16_srank2_10)
                           || l_def_mcb_addr_col12_bnk16_srank2_10) || l_def_mcb_addr_col10_bnk8_srank2_10)
                         || l_def_mcb_addr_col11_bnk8_srank2_10) || l_def_mcb_addr_col12_bnk8_srank2_10)
                       || l_def_mcb_addr_col10_bnk16_srank2_11) == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001010 );
            }
            else if ((l_def_mcb_addr_col10_bnk8_srank2_13 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001101 );
            }

            if ((l_def_mcb_addr_unset_bank3 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((l_def_mcb_addr_bank3_26 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011010 );
            }
            else if ((l_def_mcb_addr_bank3_25 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011001 );
            }
            else if ((l_def_mcb_addr_bank3_27 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011011 );
            }

            if ((l_def_mcb_addr_bank2_28 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_mcb_addr_bank2_26 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b011010 );
            }
            else if ((l_def_mcb_addr_bank2_27 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b011011 );
            }

            if ((l_def_mcb_addr_bank1_28 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_mcb_addr_bank1_29 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b011101 );
            }
            else if ((l_def_mcb_addr_bank1_27 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b011011 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (((((((((((((((((((((l_def_mcb_addr_row15_col10_bnk16_mrank1_6 || l_def_mcb_addr_row17_col11_bnk16_mrank1_6)
                                   || l_def_mcb_addr_row16_col12_bnk16_mrank1_6) || l_def_mcb_addr_row17_col12_bnk8_mrank1_6)
                                 || l_def_mcb_addr_row16_col10_bnk16_mrank1_6) || l_def_mcb_addr_row17_col10_bnk16_mrank1_6)
                               || l_def_mcb_addr_row14_col11_bnk16_mrank1_6) || l_def_mcb_addr_row15_col11_bnk16_mrank1_6)
                             || l_def_mcb_addr_row16_col11_bnk16_mrank1_6) || l_def_mcb_addr_row14_col12_bnk16_mrank1_6)
                           || l_def_mcb_addr_row15_col12_bnk16_mrank1_6) || l_def_mcb_addr_row16_col10_bnk8_mrank1_6)
                         || l_def_mcb_addr_row17_col10_bnk8_mrank1_6) || l_def_mcb_addr_row14_col11_bnk8_mrank1_6)
                       || l_def_mcb_addr_row15_col11_bnk8_mrank1_6) || l_def_mcb_addr_row16_col11_bnk8_mrank1_6)
                     || l_def_mcb_addr_row17_col11_bnk8_mrank1_6) || l_def_mcb_addr_row14_col12_bnk8_mrank1_6)
                   || l_def_mcb_addr_row15_col12_bnk8_mrank1_6) || l_def_mcb_addr_row16_col12_bnk8_mrank1_6) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000110 );
            }
            else if ((((((((((l_def_mcb_addr_row17_col10_bnk16_mrank1_4 || l_def_mcb_addr_row16_col11_bnk16_mrank1_4)
                             || l_def_mcb_addr_row17_col11_bnk16_mrank1_4) || l_def_mcb_addr_row15_col12_bnk16_mrank1_4)
                           || l_def_mcb_addr_row16_col12_bnk16_mrank1_4) || l_def_mcb_addr_row17_col12_bnk16_mrank1_4)
                         || l_def_mcb_addr_row17_col11_bnk8_mrank1_4) || l_def_mcb_addr_row16_col12_bnk8_mrank1_4)
                       || l_def_mcb_addr_row17_col12_bnk8_mrank1_4) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000100 );
            }
            else if ((((((((((((((((l_def_mcb_addr_row16_col10_bnk16_mrank1_5 || l_def_mcb_addr_row17_col12_bnk16_mrank1_5)
                                   || l_def_mcb_addr_row17_col10_bnk16_mrank1_5) || l_def_mcb_addr_row15_col11_bnk16_mrank1_5)
                                 || l_def_mcb_addr_row16_col11_bnk16_mrank1_5) || l_def_mcb_addr_row17_col11_bnk16_mrank1_5)
                               || l_def_mcb_addr_row14_col12_bnk16_mrank1_5) || l_def_mcb_addr_row15_col12_bnk16_mrank1_5)
                             || l_def_mcb_addr_row16_col12_bnk16_mrank1_5) || l_def_mcb_addr_row17_col10_bnk8_mrank1_5)
                           || l_def_mcb_addr_row16_col11_bnk8_mrank1_5) || l_def_mcb_addr_row17_col11_bnk8_mrank1_5)
                         || l_def_mcb_addr_row15_col12_bnk8_mrank1_5) || l_def_mcb_addr_row16_col12_bnk8_mrank1_5)
                       || l_def_mcb_addr_row17_col12_bnk8_mrank1_5) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000101 );
            }
            else if ((l_def_mcb_addr_row14_col10_bnk8_mrank1_11 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_mrank1_unset == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((((((((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank1_8 || l_def_mcb_addr_row16_col10_bnk16_mrank1_8)
                                   || l_def_mcb_addr_row15_col11_bnk16_mrank1_8) || l_def_mcb_addr_row14_col12_bnk16_mrank1_8)
                                 || l_def_mcb_addr_row17_col10_bnk8_mrank1_8) || l_def_mcb_addr_row16_col11_bnk8_mrank1_8)
                               || l_def_mcb_addr_row15_col12_bnk8_mrank1_8) || l_def_mcb_addr_row15_col10_bnk16_mrank1_8)
                             || l_def_mcb_addr_row14_col11_bnk16_mrank1_8) || l_def_mcb_addr_row14_col10_bnk8_mrank1_8)
                           || l_def_mcb_addr_row15_col10_bnk8_mrank1_8) || l_def_mcb_addr_row16_col10_bnk8_mrank1_8)
                         || l_def_mcb_addr_row14_col11_bnk8_mrank1_8) || l_def_mcb_addr_row15_col11_bnk8_mrank1_8)
                       || l_def_mcb_addr_row14_col12_bnk8_mrank1_8) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if (((((((((((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank1_7 || l_def_mcb_addr_row17_col10_bnk16_mrank1_7)
                                      || l_def_mcb_addr_row16_col11_bnk16_mrank1_7) || l_def_mcb_addr_row15_col12_bnk16_mrank1_7)
                                    || l_def_mcb_addr_row17_col11_bnk8_mrank1_7) || l_def_mcb_addr_row16_col12_bnk8_mrank1_7)
                                  || l_def_mcb_addr_row15_col10_bnk16_mrank1_7) || l_def_mcb_addr_row16_col10_bnk16_mrank1_7)
                                || l_def_mcb_addr_row14_col11_bnk16_mrank1_7) || l_def_mcb_addr_row15_col11_bnk16_mrank1_7)
                              || l_def_mcb_addr_row14_col12_bnk16_mrank1_7) || l_def_mcb_addr_row15_col10_bnk8_mrank1_7)
                            || l_def_mcb_addr_row16_col10_bnk8_mrank1_7) || l_def_mcb_addr_row17_col10_bnk8_mrank1_7)
                          || l_def_mcb_addr_row15_col11_bnk8_mrank1_7) || l_def_mcb_addr_row16_col11_bnk8_mrank1_7)
                        || l_def_mcb_addr_row14_col12_bnk8_mrank1_7) || l_def_mcb_addr_row15_col12_bnk8_mrank1_7) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000111 );
            }
            else if ((((((((((l_def_mcb_addr_row14_col10_bnk16_mrank1_9 || l_def_mcb_addr_row15_col10_bnk16_mrank1_9)
                             || l_def_mcb_addr_row14_col11_bnk16_mrank1_9) || l_def_mcb_addr_row16_col10_bnk8_mrank1_9)
                           || l_def_mcb_addr_row15_col11_bnk8_mrank1_9) || l_def_mcb_addr_row14_col12_bnk8_mrank1_9)
                         || l_def_mcb_addr_row14_col10_bnk8_mrank1_9) || l_def_mcb_addr_row15_col10_bnk8_mrank1_9)
                       || l_def_mcb_addr_row14_col11_bnk8_mrank1_9) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if (((((l_def_mcb_addr_row17_col11_bnk16_mrank1_3 || l_def_mcb_addr_row16_col12_bnk16_mrank1_3)
                        || l_def_mcb_addr_row17_col12_bnk16_mrank1_3) || l_def_mcb_addr_row17_col12_bnk8_mrank1_3) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000011 );
            }
            else if ((l_def_mcb_addr_row17_col12_bnk16_mrank1_2 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000010 );
            }
            else if (((((l_def_mcb_addr_row14_col10_bnk8_mrank1_10 || l_def_mcb_addr_row14_col10_bnk16_mrank1_10)
                        || l_def_mcb_addr_row15_col10_bnk8_mrank1_10) || l_def_mcb_addr_row14_col11_bnk8_mrank1_10) == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001010 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106c8ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106c9ull, l_scom_buffer ));

            if ((l_def_mcb_addr_row10_16 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_mcb_addr_row10_17 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b010001 );
            }
            else if ((l_def_mcb_addr_row10_14 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b001110 );
            }
            else if ((l_def_mcb_addr_row10_15 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b001111 );
            }

            if ((l_def_mcb_addr_row15_9 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((l_def_mcb_addr_row15_11 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_addr_unset_row15 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((l_def_mcb_addr_row15_10 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001010 );
            }
            else if ((l_def_mcb_addr_row15_12 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001100 );
            }

            if ((l_def_mcb_addr_row8_16 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_mcb_addr_row8_17 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b010001 );
            }
            else if ((l_def_mcb_addr_row8_18 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b010010 );
            }
            else if ((l_def_mcb_addr_row8_19 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b010011 );
            }

            if ((l_def_mcb_addr_row11_16 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_mcb_addr_row11_14 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001110 );
            }
            else if ((l_def_mcb_addr_row11_15 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001111 );
            }
            else if ((l_def_mcb_addr_row11_13 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001101 );
            }

            if ((l_def_mcb_addr_row16_9 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((l_def_mcb_addr_row16_11 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_addr_unset_row16 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((l_def_mcb_addr_row16_8 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if ((l_def_mcb_addr_row16_10 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001010 );
            }

            if ((l_def_mcb_addr_row9_16 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_mcb_addr_row9_17 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b010001 );
            }
            else if ((l_def_mcb_addr_row9_15 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b001111 );
            }
            else if ((l_def_mcb_addr_row9_18 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b010010 );
            }

            if ((l_def_mcb_addr_row12_14 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001110 );
            }
            else if ((l_def_mcb_addr_row12_15 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001111 );
            }
            else if ((l_def_mcb_addr_row12_12 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001100 );
            }
            else if ((l_def_mcb_addr_row12_13 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001101 );
            }

            if ((l_def_mcb_addr_bank0_28 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_mcb_addr_bank0_30 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b011110 );
            }
            else if ((l_def_mcb_addr_bank0_29 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b011101 );
            }

            if ((l_def_mcb_addr_row13_14 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001110 );
            }
            else if ((l_def_mcb_addr_row13_11 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_addr_row13_12 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001100 );
            }
            else if ((l_def_mcb_addr_row13_13 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001101 );
            }

            if ((l_def_mcb_addr_row14_11 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_addr_unset_row14 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((l_def_mcb_addr_row14_10 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001010 );
            }
            else if ((l_def_mcb_addr_row14_12 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001100 );
            }
            else if ((l_def_mcb_addr_row14_13 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001101 );
            }

            if ((l_def_mcb_addr_bank0_28 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b011100 );
            }
            else if ((l_def_mcb_addr_bank0_30 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b011110 );
            }
            else if ((l_def_mcb_addr_bank0_29 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b011101 );
            }

            if ((l_def_mcb_addr_row15_9 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((l_def_mcb_addr_row15_11 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_addr_unset_row15 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((l_def_mcb_addr_row15_10 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001010 );
            }
            else if ((l_def_mcb_addr_row15_12 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b001100 );
            }

            if ((l_def_mcb_addr_row14_11 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_addr_unset_row14 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((l_def_mcb_addr_row14_10 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001010 );
            }
            else if ((l_def_mcb_addr_row14_12 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001100 );
            }
            else if ((l_def_mcb_addr_row14_13 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b001101 );
            }

            if ((l_def_mcb_addr_row13_14 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001110 );
            }
            else if ((l_def_mcb_addr_row13_11 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_addr_row13_12 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001100 );
            }
            else if ((l_def_mcb_addr_row13_13 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b001101 );
            }

            if ((l_def_mcb_addr_row12_14 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001110 );
            }
            else if ((l_def_mcb_addr_row12_15 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001111 );
            }
            else if ((l_def_mcb_addr_row12_12 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001100 );
            }
            else if ((l_def_mcb_addr_row12_13 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b001101 );
            }

            if ((l_def_mcb_addr_row11_16 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_mcb_addr_row11_14 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001110 );
            }
            else if ((l_def_mcb_addr_row11_15 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001111 );
            }
            else if ((l_def_mcb_addr_row11_13 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b001101 );
            }

            if ((l_def_mcb_addr_row10_16 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_mcb_addr_row10_17 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b010001 );
            }
            else if ((l_def_mcb_addr_row10_14 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b001110 );
            }
            else if ((l_def_mcb_addr_row10_15 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b001111 );
            }

            if ((l_def_mcb_addr_row9_16 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_mcb_addr_row9_17 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b010001 );
            }
            else if ((l_def_mcb_addr_row9_15 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b001111 );
            }
            else if ((l_def_mcb_addr_row9_18 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b010010 );
            }

            if ((l_def_mcb_addr_row8_16 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if ((l_def_mcb_addr_row8_17 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b010001 );
            }
            else if ((l_def_mcb_addr_row8_18 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b010010 );
            }
            else if ((l_def_mcb_addr_row8_19 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b010011 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0000 );
            }

            if ((l_def_mcb_addr_row16_9 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001001 );
            }
            else if ((l_def_mcb_addr_row16_11 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001011 );
            }
            else if ((l_def_mcb_addr_unset_row16 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if ((l_def_mcb_addr_row16_8 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if ((l_def_mcb_addr_row16_10 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b001010 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106c9ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106caull, l_scom_buffer ));

            if ((l_def_mcb_addr_row1_24 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_mcb_addr_row1_26 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b011010 );
            }
            else if ((l_def_mcb_addr_row1_23 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b010111 );
            }
            else if ((l_def_mcb_addr_row1_25 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b011001 );
            }

            if ((l_def_mcb_addr_row0_24 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_mcb_addr_row0_26 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011010 );
            }
            else if ((l_def_mcb_addr_row0_25 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011001 );
            }
            else if ((l_def_mcb_addr_row0_27 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011011 );
            }

            if ((l_def_mcb_addr_row2_22 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b010110 );
            }
            else if ((l_def_mcb_addr_row2_24 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_mcb_addr_row2_23 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b010111 );
            }
            else if ((l_def_mcb_addr_row2_25 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b011001 );
            }

            if ((l_def_mcb_addr_row5_22 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010110 );
            }
            else if ((l_def_mcb_addr_row5_20 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_mcb_addr_row5_21 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010101 );
            }
            else if ((l_def_mcb_addr_row5_19 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010011 );
            }

            if ((l_def_mcb_addr_row3_22 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b010110 );
            }
            else if ((l_def_mcb_addr_row3_24 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_mcb_addr_row3_21 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b010101 );
            }
            else if ((l_def_mcb_addr_row3_23 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b010111 );
            }

            if ((l_def_mcb_addr_col13_29 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b011101 );
            }
            else if ((l_def_mcb_addr_unset_col13 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000000 );
            }

            if ((l_def_mcb_addr_row7_17 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010001 );
            }
            else if ((l_def_mcb_addr_row7_20 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_mcb_addr_row7_18 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010010 );
            }
            else if ((l_def_mcb_addr_row7_19 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010011 );
            }

            if ((l_def_mcb_addr_row6_20 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_mcb_addr_row6_21 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b010101 );
            }
            else if ((l_def_mcb_addr_row6_18 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b010010 );
            }
            else if ((l_def_mcb_addr_row6_19 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b010011 );
            }

            if ((l_def_mcb_addr_row7_17 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010001 );
            }
            else if ((l_def_mcb_addr_row7_20 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_mcb_addr_row7_18 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010010 );
            }
            else if ((l_def_mcb_addr_row7_19 == literal_1))
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b010011 );
            }

            if ((l_def_mcb_addr_row5_22 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010110 );
            }
            else if ((l_def_mcb_addr_row5_20 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_mcb_addr_row5_21 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010101 );
            }
            else if ((l_def_mcb_addr_row5_19 == literal_1))
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b010011 );
            }

            if ((l_def_mcb_addr_row4_22 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b010110 );
            }
            else if ((l_def_mcb_addr_row4_20 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_mcb_addr_row4_21 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b010101 );
            }
            else if ((l_def_mcb_addr_row4_23 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b010111 );
            }

            if ((l_def_mcb_addr_row3_22 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b010110 );
            }
            else if ((l_def_mcb_addr_row3_24 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_mcb_addr_row3_21 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b010101 );
            }
            else if ((l_def_mcb_addr_row3_23 == literal_1))
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b010111 );
            }

            if ((l_def_mcb_addr_row2_22 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b010110 );
            }
            else if ((l_def_mcb_addr_row2_24 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_mcb_addr_row2_23 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b010111 );
            }
            else if ((l_def_mcb_addr_row2_25 == literal_1))
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b011001 );
            }

            if ((l_def_mcb_addr_row1_24 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_mcb_addr_row1_26 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b011010 );
            }
            else if ((l_def_mcb_addr_row1_23 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b010111 );
            }
            else if ((l_def_mcb_addr_row1_25 == literal_1))
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b011001 );
            }

            if ((l_def_mcb_addr_row0_24 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011000 );
            }
            else if ((l_def_mcb_addr_row0_26 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011010 );
            }
            else if ((l_def_mcb_addr_row0_25 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011001 );
            }
            else if ((l_def_mcb_addr_row0_27 == literal_1))
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b011011 );
            }

            if ((l_def_mcb_addr_col13_29 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b011101 );
            }
            else if ((l_def_mcb_addr_unset_col13 == literal_1))
            {
                l_scom_buffer.insert<48, 6, 58, uint64_t>(literal_0b000000 );
            }

            if ((l_def_mcb_addr_col11_30 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b011110 );
            }
            else if ((l_def_mcb_addr_unset_col11 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0000 );
            }

            if ((l_def_mcb_addr_row6_20 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_mcb_addr_row6_21 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b010101 );
            }
            else if ((l_def_mcb_addr_row6_18 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b010010 );
            }
            else if ((l_def_mcb_addr_row6_19 == literal_1))
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b010011 );
            }

            if ((l_def_mcb_addr_row4_22 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b010110 );
            }
            else if ((l_def_mcb_addr_row4_20 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b010100 );
            }
            else if ((l_def_mcb_addr_row4_21 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b010101 );
            }
            else if ((l_def_mcb_addr_row4_23 == literal_1))
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b010111 );
            }

            if ((l_def_mcb_addr_col11_30 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b011110 );
            }
            else if ((l_def_mcb_addr_unset_col11 == literal_1))
            {
                l_scom_buffer.insert<54, 6, 58, uint64_t>(literal_0b000000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106caull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106cbull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b100011 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b100010 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b100101 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b011111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b100001 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<18, 6, 58, uint64_t>(literal_0b100010 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 6, 58, uint64_t>(literal_0b100011 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b100100 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<36, 6, 58, uint64_t>(literal_0b100101 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<42, 6, 58, uint64_t>(literal_0b000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0b0000000000000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b100000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 6, 58, uint64_t>(literal_0b100001 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<6, 6, 58, uint64_t>(literal_0b100000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<30, 6, 58, uint64_t>(literal_0b100100 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106cbull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106d0ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 36, 28, uint64_t>(literal_0x000000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<36, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<38, 26, 38, uint64_t>(literal_0b00000000000000000000000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 36, 28, uint64_t>(literal_0x000000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<36, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106d0ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106d2ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID != literal_1) || ((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                    && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_0))))
            {
                l_scom_buffer.insert<16, 20, 44, uint64_t>(literal_0x00000 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1) && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE != literal_0)))
            {
                l_scom_buffer.insert<16, 20, 44, uint64_t>(literal_0xFFFFF );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<36, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1) && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_3))
                 && l_def_mcb_addr_total22_max22))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if ((((((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                           && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total28_max28)
                         || l_def_mcb_addr_total27_max28) || l_def_mcb_addr_total26_max28) || l_def_mcb_addr_total25_max28)
                      || l_def_mcb_addr_total28_max29))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x00F );
            }
            else if (((((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                          && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total25_max25)
                        || l_def_mcb_addr_total24_max25) || l_def_mcb_addr_total23_max25) || l_def_mcb_addr_total22_max25))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x07F );
            }
            else if (((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                        && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total23_max23)
                      || l_def_mcb_addr_total22_max23))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x1FF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID != literal_1) || ((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                      && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_0))))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x000 );
            }
            else if ((((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                         && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total24_max24)
                       || l_def_mcb_addr_total23_max24) || l_def_mcb_addr_total22_max24))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x0FF );
            }
            else if ((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1) && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_2))
                      && l_def_mcb_addr_total22_max22))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x7FF );
            }
            else if (((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                        && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total28_max30)
                      || l_def_mcb_addr_total27_max30))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x003 );
            }
            else if (((((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                          && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total26_max26)
                        || l_def_mcb_addr_total25_max26) || l_def_mcb_addr_total24_max26) || l_def_mcb_addr_total23_max26))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x03F );
            }
            else if ((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1) && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1))
                      && l_def_mcb_addr_total28_max31))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x001 );
            }
            else if (((((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                          && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total27_max27)
                        || l_def_mcb_addr_total26_max27) || l_def_mcb_addr_total25_max27) || l_def_mcb_addr_total24_max27))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x01F );
            }
            else if (((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                        && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total27_max29)
                      || l_def_mcb_addr_total26_max29))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1) && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1))
                      && l_def_mcb_addr_total22_max22))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x3FF );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0x0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID != literal_1) || ((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                    && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_0))))
            {
                l_scom_buffer.insert<16, 20, 44, uint64_t>(literal_0x00000 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1) && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE != literal_0)))
            {
                l_scom_buffer.insert<16, 20, 44, uint64_t>(literal_0xFFFFF );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<36, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<38, 26, 38, uint64_t>(literal_0b00000000000000000000000000 );
            }

            if ((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1) && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_3))
                 && l_def_mcb_addr_total22_max22))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if ((((((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                           && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total28_max28)
                         || l_def_mcb_addr_total27_max28) || l_def_mcb_addr_total26_max28) || l_def_mcb_addr_total25_max28)
                      || l_def_mcb_addr_total28_max29))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x00F );
            }
            else if (((((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                          && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total25_max25)
                        || l_def_mcb_addr_total24_max25) || l_def_mcb_addr_total23_max25) || l_def_mcb_addr_total22_max25))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x07F );
            }
            else if (((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                        && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total23_max23)
                      || l_def_mcb_addr_total22_max23))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x1FF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID != literal_1) || ((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                      && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_0))))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x000 );
            }
            else if ((((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                         && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total24_max24)
                       || l_def_mcb_addr_total23_max24) || l_def_mcb_addr_total22_max24))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x0FF );
            }
            else if ((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1) && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_2))
                      && l_def_mcb_addr_total22_max22))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x7FF );
            }
            else if (((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                        && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total28_max30)
                      || l_def_mcb_addr_total27_max30))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x003 );
            }
            else if (((((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                          && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total26_max26)
                        || l_def_mcb_addr_total25_max26) || l_def_mcb_addr_total24_max26) || l_def_mcb_addr_total23_max26))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x03F );
            }
            else if ((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1) && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1))
                      && l_def_mcb_addr_total28_max31))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x001 );
            }
            else if (((((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                          && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total27_max27)
                        || l_def_mcb_addr_total26_max27) || l_def_mcb_addr_total25_max27) || l_def_mcb_addr_total24_max27))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x01F );
            }
            else if (((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1)
                        && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1)) && l_def_mcb_addr_total27_max29)
                      || l_def_mcb_addr_total26_max29))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((((l_TGT0_ATTR_CEN_EFF_SCHMOO_TEST_VALID == literal_1) && (l_TGT0_ATTR_CEN_EFF_SCHMOO_ADDR_MODE == literal_1))
                      && l_def_mcb_addr_total22_max22))
            {
                l_scom_buffer.insert<4, 12, 52, uint64_t>(literal_0x3FF );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106d2ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x30106d6ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 6, 58, uint64_t>(literal_0b000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<24, 2, 62, uint64_t>(literal_0b10 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x30106d6ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3010882ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 14, 50, uint64_t>(literal_0b00000000000011 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3010882ull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
