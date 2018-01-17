/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/initfiles/centaur_mbs_scom.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
#include "centaur_mbs_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_0b0000000 = 0b0000000;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_0b00000 = 0b00000;
constexpr uint64_t literal_0b010010 = 0b010010;
constexpr uint64_t literal_0b00 = 0b00;
constexpr uint64_t literal_0b00000000000000000000 = 0b00000000000000000000;
constexpr uint64_t literal_0b11 = 0b11;
constexpr uint64_t literal_28 = 28;
constexpr uint64_t literal_0b10101 = 0b10101;
constexpr uint64_t literal_27 = 27;
constexpr uint64_t literal_0b10100 = 0b10100;
constexpr uint64_t literal_24 = 24;
constexpr uint64_t literal_0b10001 = 0b10001;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_31 = 31;
constexpr uint64_t literal_0b11000 = 0b11000;
constexpr uint64_t literal_30 = 30;
constexpr uint64_t literal_0b10111 = 0b10111;
constexpr uint64_t literal_25 = 25;
constexpr uint64_t literal_0b10010 = 0b10010;
constexpr uint64_t literal_26 = 26;
constexpr uint64_t literal_0b10011 = 0b10011;
constexpr uint64_t literal_29 = 29;
constexpr uint64_t literal_0b10110 = 0b10110;
constexpr uint64_t literal_23 = 23;
constexpr uint64_t literal_0b10000 = 0b10000;
constexpr uint64_t literal_32 = 32;
constexpr uint64_t literal_0b11001 = 0b11001;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_0b10 = 0b10;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_0b01 = 0b01;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_13 = 13;
constexpr uint64_t literal_10 = 10;
constexpr uint64_t literal_12 = 12;
constexpr uint64_t literal_9 = 9;
constexpr uint64_t literal_11 = 11;
constexpr uint64_t literal_0b0011 = 0b0011;
constexpr uint64_t literal_0b00000000 = 0b00000000;
constexpr uint64_t literal_0b0000 = 0b0000;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_17 = 17;
constexpr uint64_t literal_7 = 7;
constexpr uint64_t literal_5 = 5;
constexpr uint64_t literal_6 = 6;
constexpr uint64_t literal_0b0010 = 0b0010;
constexpr uint64_t literal_16 = 16;
constexpr uint64_t literal_15 = 15;
constexpr uint64_t literal_1400 = 1400;
constexpr uint64_t literal_0b0101 = 0b0101;
constexpr uint64_t literal_22 = 22;
constexpr uint64_t literal_21 = 21;
constexpr uint64_t literal_0b0111 = 0b0111;
constexpr uint64_t literal_0b0110 = 0b0110;
constexpr uint64_t literal_0b0001 = 0b0001;
constexpr uint64_t literal_0b0100 = 0b0100;
constexpr uint64_t literal_0b000 = 0b000;
constexpr uint64_t literal_0b001 = 0b001;
constexpr uint64_t literal_0b010 = 0b010;
constexpr uint64_t literal_0b000111 = 0b000111;
constexpr uint64_t literal_0b010000 = 0b010000;
constexpr uint64_t literal_0b001000 = 0b001000;
constexpr uint64_t literal_0b100000 = 0b100000;
constexpr uint64_t literal_0b1111 = 0b1111;
constexpr uint64_t literal_0b000110 = 0b000110;
constexpr uint64_t literal_0b00001000000000 = 0b00001000000000;
constexpr uint64_t literal_0b00000111110000 = 0b00000111110000;
constexpr uint64_t literal_0x00000006 = 0x00000006;
constexpr uint64_t literal_0x00000000 = 0x00000000;
constexpr uint64_t literal_0x1111111111111111 = 0x1111111111111111;
constexpr uint64_t literal_0x2222222222222222 = 0x2222222222222222;
constexpr uint64_t literal_0x3333333333333333 = 0x3333333333333333;
constexpr uint64_t literal_0x4444444444444444 = 0x4444444444444444;
constexpr uint64_t literal_0x5555555555555555 = 0x5555555555555555;
constexpr uint64_t literal_0x6666666666666666 = 0x6666666666666666;
constexpr uint64_t literal_0x7777777777777777 = 0x7777777777777777;
constexpr uint64_t literal_0x8888888888888888 = 0x8888888888888888;
constexpr uint64_t literal_0x9999999999999999 = 0x9999999999999999;
constexpr uint64_t literal_0x99 = 0x99;
constexpr uint64_t literal_0xAAAAAAAAAAAAAAAA = 0xAAAAAAAAAAAAAAAA;
constexpr uint64_t literal_0xAA = 0xAA;

fapi2::ReturnCode centaur_mbs_scom(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& TGT0,
                                   const fapi2::Target<fapi2::TARGET_TYPE_MBA>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_L4>& TGT2,
                                   const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT3)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT_Type l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT, TGT0,
                               l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT));
        fapi2::ATTR_CEN_EFF_DRAM_DENSITY_Type l_TGT1_ATTR_CEN_EFF_DRAM_DENSITY;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_DENSITY, TGT1, l_TGT1_ATTR_CEN_EFF_DRAM_DENSITY));
        fapi2::ATTR_CEN_EFF_DRAM_WIDTH_Type l_TGT1_ATTR_CEN_EFF_DRAM_WIDTH;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, TGT1, l_TGT1_ATTR_CEN_EFF_DRAM_WIDTH));
        fapi2::ATTR_CEN_EFF_CUSTOM_DIMM_Type l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, TGT1, l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM));
        fapi2::ATTR_CEN_EFF_DIMM_TYPE_Type l_TGT1_ATTR_CEN_EFF_DIMM_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, TGT1, l_TGT1_ATTR_CEN_EFF_DIMM_TYPE));
        fapi2::ATTR_CEN_EFF_NUM_DROPS_PER_PORT_Type l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_DROPS_PER_PORT, TGT1, l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT));
        fapi2::ATTR_CEN_EFF_IBM_TYPE_Type l_TGT1_ATTR_CEN_EFF_IBM_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_IBM_TYPE, TGT1, l_TGT1_ATTR_CEN_EFF_IBM_TYPE));
        fapi2::ATTR_CHIP_UNIT_POS_Type l_TGT1_ATTR_CHIP_UNIT_POS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, TGT1, l_TGT1_ATTR_CHIP_UNIT_POS));
        uint64_t l_def_mba01 = (l_TGT1_ATTR_CHIP_UNIT_POS == literal_0);
        uint64_t l_def_mba01_4c_ddr4_cdimm = (l_def_mba01
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_13)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_3c_2socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_10)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba01_4c_ddr4_cdimm));
        uint64_t l_def_mba01_3c_1socket_ddr4 = (l_def_mba01
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_10)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba01_mtype_3c = ((l_def_mba01_3c_1socket_ddr4 || l_def_mba01_3c_2socket_ddr4)
                                         || l_def_mba01_4c_ddr4_cdimm);
        uint64_t l_def_mba01_4b_ddr4_cdimm = (l_def_mba01
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_12)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_3b_2socket = (l_def_mba01 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_9)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)));
        uint64_t l_def_mba01_3b_1socket = (l_def_mba01 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_9)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba01_mtype_3b = ((l_def_mba01_3b_1socket || l_def_mba01_3b_2socket) || l_def_mba01_4b_ddr4_cdimm);
        uint64_t l_def_mba01_4a_ddr4_cdimm = (l_def_mba01
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_11)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_4a_cdimm = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_11)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_3a_2socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_8)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba01_4a_ddr4_cdimm));
        uint64_t l_def_mba01_3a_1socket_ddr4 = (l_def_mba01
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_8)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba01_3a_2socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_8)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba01_4a_cdimm));
        uint64_t l_def_mba01_3a_1socket = (l_def_mba01 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_8)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba01_mtype_3a = (((((l_def_mba01_3a_1socket || l_def_mba01_3a_2socket) || l_def_mba01_3a_1socket_ddr4)
                                           || l_def_mba01_3a_2socket_ddr4) || l_def_mba01_4a_cdimm) || l_def_mba01_4a_ddr4_cdimm);
        uint64_t l_def_mba01_type3_memory_populated_behind_MBA01 = ((l_def_mba01_mtype_3a || l_def_mba01_mtype_3b)
                || l_def_mba01_mtype_3c);
        fapi2::ATTR_CEN_EFF_DIMM_RANKS_CONFIGED_Type l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_RANKS_CONFIGED, TGT1, l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED));
        uint64_t l_def_mba01_nomem = (l_def_mba01
                                      && ((l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_0] == literal_0b00000000)
                                          && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_1] == literal_0b00000000)));
        uint64_t l_def_mba01_5d_2socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_17)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_5d_1socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_17)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_mtype_5d = (l_def_mba01_5d_1socket || l_def_mba01_5d_2socket);
        uint64_t l_def_mba01_3c_ddr4_cdimm = (l_def_mba01
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_10)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_3c_cdimm = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_10)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_2c_2socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_7)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba01_3c_ddr4_cdimm));
        uint64_t l_def_mba01_2a_ddr4_cdimm = (l_def_mba01
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_2c_1socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_7)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_mba01_2a_ddr4_cdimm));
        uint64_t l_def_mba01_2c_2socket = (l_def_mba01 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_7)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)));
        uint64_t l_def_mba01_2a_cdimm = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_2c_1socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_7)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_mba01_2a_cdimm));
        uint64_t l_def_mba01_mtype_2c = (((((l_def_mba01_2c_1socket || l_def_mba01_2c_2socket) || l_def_mba01_2c_1socket_ddr4)
                                           || l_def_mba01_2c_2socket_ddr4) || l_def_mba01_3c_cdimm) || l_def_mba01_3c_ddr4_cdimm);
        uint64_t l_def_mba01_3b_ddr4_cdimm = (l_def_mba01
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_9)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_3b_cdimm = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_9)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_2b_2socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_6)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba01_3b_ddr4_cdimm));
        uint64_t l_def_mba01_2b_ddr4_cdimm = (l_def_mba01
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_6)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_2b_1socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_6)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_mba01_2b_ddr4_cdimm));
        uint64_t l_def_mba01_2b_2socket = (l_def_mba01 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_6)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)));
        uint64_t l_def_mba01_2b_cdimm = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_6)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_2b_1socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_6)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_mba01_2b_cdimm));
        uint64_t l_def_mba01_mtype_2b = (((((l_def_mba01_2b_1socket || l_def_mba01_2b_2socket) || l_def_mba01_2b_1socket_ddr4)
                                           || l_def_mba01_2b_2socket_ddr4) || l_def_mba01_3b_cdimm) || l_def_mba01_3b_ddr4_cdimm);
        fapi2::ATTR_CEN_EFF_DRAM_GEN_Type l_TGT1_ATTR_CEN_EFF_DRAM_GEN;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, TGT1, l_TGT1_ATTR_CEN_EFF_DRAM_GEN));
        uint64_t l_def_mba01_3a_ddr4_cdimm = (l_def_mba01
                                              && ((((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_8)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))) && (l_TGT1_ATTR_CEN_EFF_DRAM_GEN == literal_2)));
        uint64_t l_def_mba01_3a_cdimm = (l_def_mba01 && ((((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_8)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))) && (l_TGT1_ATTR_CEN_EFF_DRAM_GEN == literal_1)));
        uint64_t l_def_mba01_2a_2socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba01_3a_ddr4_cdimm));
        uint64_t l_def_mba01_2a_1socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_mba01_2a_ddr4_cdimm));
        uint64_t l_def_mba01_2c_cdimm = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_7)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_2a_2socket = (l_def_mba01 && ((((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba01_2c_cdimm) || l_def_mba01_3a_cdimm));
        uint64_t l_def_mba01_2a_1socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_mba01_2a_cdimm));
        uint64_t l_def_mba01_mtype_2a = (((((l_def_mba01_2a_1socket || l_def_mba01_2a_2socket) || l_def_mba01_2a_1socket_ddr4)
                                           || l_def_mba01_2a_2socket_ddr4) || l_def_mba01_3a_cdimm) || l_def_mba01_3a_ddr4_cdimm);
        uint64_t l_def_mba01_type2_memory_populated_behind_MBA01 = (((l_def_mba01_mtype_2a || l_def_mba01_mtype_2b)
                || l_def_mba01_mtype_2c) || l_def_mba01_mtype_5d);
        uint64_t l_def_mba01_5c_2socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_16)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_5c_1socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_16)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_mtype_5c = (l_def_mba01_5c_1socket || l_def_mba01_5c_2socket);
        uint64_t l_def_mba01_5b_2socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_15)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_5b_1socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_15)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_mtype_5b = (l_def_mba01_5b_1socket || l_def_mba01_5b_2socket);
        fapi2::ATTR_CEN_MSS_FREQ_Type l_TGT0_ATTR_CEN_MSS_FREQ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, TGT0, l_TGT0_ATTR_CEN_MSS_FREQ));
        uint64_t l_def_mba01_mtype_5a = (l_def_mba01 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba01_type5_memory_populated_behind_MBA01 = ((l_def_mba01_mtype_5a || l_def_mba01_mtype_5b)
                || l_def_mba01_mtype_5c);
        uint64_t l_def_mba01_7c_2socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_23)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_7c_1socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_23)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_7c_2socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_23)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_7c_1socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_23)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_mtype_7c = (((l_def_mba01_7c_1socket || l_def_mba01_7c_2socket) || l_def_mba01_7c_1socket_ddr4)
                                         || l_def_mba01_7c_2socket_ddr4);
        uint64_t l_def_mba01_7b_2socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_22)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_7b_1socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_22)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_7b_2socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_22)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_7b_1socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_22)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_mtype_7b = (((l_def_mba01_7b_1socket || l_def_mba01_7b_2socket) || l_def_mba01_7b_1socket_ddr4)
                                         || l_def_mba01_7b_2socket_ddr4);
        uint64_t l_def_mba01_7a_2socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_21)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_7a_1socket_ddr4 = (l_def_mba01
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_21)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_7a_2socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_21)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_7a_1socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_21)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba01_mtype_7a = (((l_def_mba01_7a_1socket || l_def_mba01_7a_2socket) || l_def_mba01_7a_1socket_ddr4)
                                         || l_def_mba01_7a_2socket_ddr4);
        uint64_t l_def_mba01_type7_memory_populated_behind_MBA01 = ((l_def_mba01_mtype_7a || l_def_mba01_mtype_7b)
                || l_def_mba01_mtype_7c);
        uint64_t l_def_mba01_mtype_6c = (l_def_mba01 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba01_mtype_6b = (l_def_mba01 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba01_mtype_6a = (l_def_mba01 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba01_type6_memory_populated_behind_MBA01 = ((l_def_mba01_mtype_6a || l_def_mba01_mtype_6b)
                || l_def_mba01_mtype_6c);
        uint64_t l_def_mba01_1d_2socket = (l_def_mba01 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_4)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)));
        uint64_t l_def_mba01_1c_2socket = ((l_def_mba01 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_3)
                                            && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2))) || l_def_mba01_1d_2socket);
        uint64_t l_def_mba01_1d_1socket = (l_def_mba01 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_4)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba01_1c_1socket = ((l_def_mba01 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_3)
                                            && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1))) || l_def_mba01_1d_1socket);
        uint64_t l_def_mba01_mtype_1c = (l_def_mba01_1c_1socket || l_def_mba01_1c_2socket);
        uint64_t l_def_mba01_1c_cdimm = (l_def_mba01 && ((((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_3)
                                         || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_3))
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba01_1b_2socket = (l_def_mba01 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_2)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba01_1c_cdimm));
        uint64_t l_def_mba01_1b_1socket = (l_def_mba01 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_2)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba01_mtype_1b = ((l_def_mba01_1b_1socket || l_def_mba01_1b_2socket) || l_def_mba01_1c_cdimm);
        uint64_t l_def_mba01_1a_2socket = (l_def_mba01 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_1)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)));
        uint64_t l_def_mba01_1a_1socket = (l_def_mba01 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_1)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba01_mtype_1a = (l_def_mba01_1a_1socket || l_def_mba01_1a_2socket);
        uint64_t l_def_mba01_type1_memory_populated_behind_MBA01 = ((l_def_mba01_mtype_1a || l_def_mba01_mtype_1b)
                || l_def_mba01_mtype_1c);
        uint64_t l_def_mba01_mtype_4c = (l_def_mba01 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba01_mtype_4b = (l_def_mba01 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba01_mtype_4a = (l_def_mba01 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba01_type4_memory_populated_behind_MBA01 = ((l_def_mba01_mtype_4a || l_def_mba01_mtype_4b)
                || l_def_mba01_mtype_4c);
        uint64_t l_def_mba01_hash0_type3c_7c = (l_def_mba01
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_10)
                                                        || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_23)));
        uint64_t l_def_mba01_hash0_type3b_7b = (l_def_mba01
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_9)
                                                        || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_22)));
        uint64_t l_def_mba01_hash0_type2c = (l_def_mba01 && (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_7));
        uint64_t l_def_mba01_hash0_type2b = (l_def_mba01 && (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_6));
        uint64_t l_def_mba01_hash0_type2a = ((l_def_mba01 && (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5))
                                             && ((l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_0] == literal_0)
                                                     || (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_1] == literal_0)));
        uint64_t l_def_mba01_hash0_type1a = ((l_def_mba01 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_1)
                                              || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_1] == literal_1)))
                                             && ((l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_0] == literal_0)
                                                     || (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_1] == literal_0)));
        uint64_t l_def_mba01_hash0_sel = ((((((l_def_mba01 && l_def_mba01_hash0_type1a) || l_def_mba01_hash0_type2a)
                                             || l_def_mba01_hash0_type2b) || l_def_mba01_hash0_type2c) || l_def_mba01_hash0_type3b_7b)
                                          || l_def_mba01_hash0_type3c_7c);
        uint64_t l_def_mba01_hash2_type1d_5c = (l_def_mba01
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_4)
                                                        || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_16)));
        uint64_t l_def_mba01_hash2_type1b_5b = (((l_def_mba01
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_2)
                                                        || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_15)))
                                                && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_0] != literal_0))
                                                && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_1] != literal_0));
        uint64_t l_def_mba01_hash2_sel = ((l_def_mba01 && l_def_mba01_hash2_type1b_5b) || l_def_mba01_hash2_type1d_5c);
        uint64_t l_def_mba01_hash1_type3a_7a = (l_def_mba01
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_8)
                                                        || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_21)));
        uint64_t l_def_mba01_hash1_type2a = (((l_def_mba01
                                               && (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_5))
                                              && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_0] != literal_0))
                                             && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_1] != literal_0));
        uint64_t l_def_mba01_hash1_type1b_5b = ((l_def_mba01
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_2)
                                                        || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_15)))
                                                && ((l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_0] == literal_0)
                                                        || (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_1] == literal_0)));
        uint64_t l_def_mba01_hash1_type1a = (((l_def_mba01
                                               && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_0] == literal_1)
                                                       || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_0][literal_1] == literal_1)))
                                              && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_0] != literal_0))
                                             && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_0][literal_1] != literal_0));
        uint64_t l_def_mba01_hash1_sel = ((((l_def_mba01 && l_def_mba01_hash1_type1a) || l_def_mba01_hash1_type1b_5b)
                                           || l_def_mba01_hash1_type2a) || l_def_mba01_hash1_type3a_7a);
        fapi2::ATTR_CEN_MSS_CACHE_ENABLE_Type l_TGT0_ATTR_CEN_MSS_CACHE_ENABLE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_CACHE_ENABLE, TGT0, l_TGT0_ATTR_CEN_MSS_CACHE_ENABLE));
        fapi2::ATTR_FUNCTIONAL_Type l_TGT2_ATTR_FUNCTIONAL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL, TGT2, l_TGT2_ATTR_FUNCTIONAL));
        fapi2::ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE_Type
        l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE, TGT0,
                               l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE));
        uint64_t l_def_mba01_Centaur_or_Planar_DIMM_with_only_DIMM_slot0_populated = (((((((((((((((((((((
                    l_def_mba01_1a_1socket || l_def_mba01_1b_1socket) || l_def_mba01_1c_1socket) || l_def_mba01_2a_1socket)
                || l_def_mba01_2a_1socket_ddr4) || l_def_mba01_2b_1socket) || l_def_mba01_2b_1socket_ddr4) || l_def_mba01_2c_1socket)
                || l_def_mba01_2c_1socket_ddr4) || l_def_mba01_3a_1socket) || l_def_mba01_3a_1socket_ddr4) || l_def_mba01_3b_1socket)
                || l_def_mba01_3c_1socket_ddr4) || l_def_mba01_5b_1socket) || l_def_mba01_5c_1socket) || l_def_mba01_5d_1socket)
                || l_def_mba01_7a_1socket) || l_def_mba01_7b_1socket) || l_def_mba01_7c_1socket) || l_def_mba01_7a_1socket_ddr4)
                || l_def_mba01_7b_1socket_ddr4) || l_def_mba01_7c_1socket_ddr4);
        uint64_t l_def_mba01_Planar_DIMM_with_both_DIMM_slots_0_and_1_populated = ((((((((((((((((((((((((((((((((
                    l_def_mba01_1a_2socket || l_def_mba01_1b_2socket) || l_def_mba01_1c_2socket) || l_def_mba01_2a_2socket)
                || l_def_mba01_2a_2socket_ddr4) || l_def_mba01_2b_2socket) || l_def_mba01_2b_2socket_ddr4) || l_def_mba01_2c_2socket)
                || l_def_mba01_2c_2socket_ddr4) || l_def_mba01_3a_2socket) || l_def_mba01_3a_2socket_ddr4) || l_def_mba01_3b_2socket)
                || l_def_mba01_3c_2socket_ddr4) || l_def_mba01_5b_2socket) || l_def_mba01_5c_2socket) || l_def_mba01_5d_2socket)
                || l_def_mba01_7a_2socket) || l_def_mba01_7b_2socket) || l_def_mba01_7c_2socket) || l_def_mba01_7a_2socket_ddr4)
                || l_def_mba01_7b_2socket_ddr4) || l_def_mba01_7c_2socket_ddr4) || l_def_mba01_1c_cdimm) || l_def_mba01_3a_cdimm)
                || l_def_mba01_3b_cdimm) || l_def_mba01_3c_cdimm) || l_def_mba01_3a_ddr4_cdimm) || l_def_mba01_3b_ddr4_cdimm)
                || l_def_mba01_3c_ddr4_cdimm) || l_def_mba01_4a_cdimm) || l_def_mba01_4a_ddr4_cdimm) || l_def_mba01_4b_ddr4_cdimm)
                || l_def_mba01_4c_ddr4_cdimm);
        uint64_t l_def_mba01_subtype_A = ((((((l_def_mba01_mtype_1a || l_def_mba01_mtype_2a) || l_def_mba01_mtype_3a)
                                             || l_def_mba01_mtype_4a) || l_def_mba01_mtype_5a) || l_def_mba01_mtype_6a) || l_def_mba01_mtype_7a);
        uint64_t l_def_mba01_subtype_C = (((((((l_def_mba01_mtype_1c || l_def_mba01_mtype_2c) || l_def_mba01_mtype_3c)
                                              || l_def_mba01_mtype_4c) || l_def_mba01_mtype_5c) || l_def_mba01_mtype_5d) || l_def_mba01_mtype_6c)
                                          || l_def_mba01_mtype_7c);
        uint64_t l_def_mba01_subtype_B = ((((((l_def_mba01_mtype_1b || l_def_mba01_mtype_2b) || l_def_mba01_mtype_3b)
                                             || l_def_mba01_mtype_4b) || l_def_mba01_mtype_5b) || l_def_mba01_mtype_6b) || l_def_mba01_mtype_7b);
        uint64_t l_def_mba23 = (l_TGT1_ATTR_CHIP_UNIT_POS == literal_1);
        uint64_t l_def_mba23_7c_1socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_23)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_7b_1socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_22)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_7a_1socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_21)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_7c_1socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_23)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_7b_1socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_22)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_7a_1socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_21)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_5d_1socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_17)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_5c_1socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_16)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_5b_1socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_15)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_3c_1socket_ddr4 = (l_def_mba23
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_10)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba23_3b_1socket = (l_def_mba23 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_9)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba23_3a_1socket_ddr4 = (l_def_mba23
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_8)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba23_3a_1socket = (l_def_mba23 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_8)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba23_2a_ddr4_cdimm = (l_def_mba23
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_2c_1socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_7)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_mba23_2a_ddr4_cdimm));
        uint64_t l_def_mba23_2a_cdimm = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_2c_1socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_7)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_mba23_2a_cdimm));
        uint64_t l_def_mba23_2b_ddr4_cdimm = (l_def_mba23
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_6)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_2b_1socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_6)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_mba23_2b_ddr4_cdimm));
        uint64_t l_def_mba23_2b_cdimm = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_6)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_2b_1socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_6)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_mba23_2b_cdimm));
        uint64_t l_def_mba23_2a_1socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_mba23_2a_ddr4_cdimm));
        uint64_t l_def_mba23_2a_1socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) || l_def_mba23_2a_cdimm));
        uint64_t l_def_mba23_1d_1socket = (l_def_mba23 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_4)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba23_1c_1socket = ((l_def_mba23 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_3)
                                            && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1))) || l_def_mba23_1d_1socket);
        uint64_t l_def_mba23_1b_1socket = (l_def_mba23 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_2)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba23_1a_1socket = (l_def_mba23 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_1)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)));
        uint64_t l_def_mba23_Centaur_or_Planar_DIMM_with_only_DIMM_slot0_populated = (((((((((((((((((((((
                    l_def_mba23_1a_1socket || l_def_mba23_1b_1socket) || l_def_mba23_1c_1socket) || l_def_mba23_2a_1socket)
                || l_def_mba23_2a_1socket_ddr4) || l_def_mba23_2b_1socket) || l_def_mba23_2b_1socket_ddr4) || l_def_mba23_2c_1socket)
                || l_def_mba23_2c_1socket_ddr4) || l_def_mba23_3a_1socket) || l_def_mba23_3a_1socket_ddr4) || l_def_mba23_3b_1socket)
                || l_def_mba23_3c_1socket_ddr4) || l_def_mba23_5b_1socket) || l_def_mba23_5c_1socket) || l_def_mba23_5d_1socket)
                || l_def_mba23_7a_1socket) || l_def_mba23_7b_1socket) || l_def_mba23_7c_1socket) || l_def_mba23_7a_1socket_ddr4)
                || l_def_mba23_7b_1socket_ddr4) || l_def_mba23_7c_1socket_ddr4);
        uint64_t l_def_mba23_4c_ddr4_cdimm = (l_def_mba23
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_13)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_4b_ddr4_cdimm = (l_def_mba23
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_12)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_4a_ddr4_cdimm = (l_def_mba23
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_12)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_4a_cdimm = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_12)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_3c_ddr4_cdimm = (l_def_mba23
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_10)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_3b_ddr4_cdimm = (l_def_mba23
                                              && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_9)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_3a_ddr4_cdimm = (l_def_mba23
                                              && ((((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_8)
                                                      && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                              && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))) && (l_TGT1_ATTR_CEN_EFF_DRAM_GEN == literal_2)));
        uint64_t l_def_mba23_3c_cdimm = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_10)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_3b_cdimm = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_9)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_3a_cdimm = (l_def_mba23 && ((((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_8)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))) && (l_TGT1_ATTR_CEN_EFF_DRAM_GEN == literal_1)));
        uint64_t l_def_mba23_1c_cdimm = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_3)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_7c_2socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_23)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_7b_2socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_22)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_7a_2socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_21)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_7c_2socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_23)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_7b_2socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_22)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_7a_2socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_21)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_5d_2socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_17)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_5c_2socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_16)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_5b_2socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_15)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) && (l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_3)));
        uint64_t l_def_mba23_3c_2socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_10)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba23_4c_ddr4_cdimm));
        uint64_t l_def_mba23_3b_2socket = (l_def_mba23 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_9)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)));
        uint64_t l_def_mba23_3a_2socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_8)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba23_4a_ddr4_cdimm));
        uint64_t l_def_mba23_3a_2socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_8)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba23_4a_cdimm));
        uint64_t l_def_mba23_2c_2socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_7)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba23_3c_ddr4_cdimm));
        uint64_t l_def_mba23_2c_2socket = (l_def_mba23 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_7)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)));
        uint64_t l_def_mba23_2b_2socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_6)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba23_3b_ddr4_cdimm));
        uint64_t l_def_mba23_2b_2socket = (l_def_mba23 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_6)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)));
        uint64_t l_def_mba23_2a_2socket_ddr4 = (l_def_mba23
                                                && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5)
                                                        && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba23_3a_ddr4_cdimm));
        uint64_t l_def_mba23_2c_cdimm = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_7)
                                         && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_1)) && ((l_TGT1_ATTR_CEN_EFF_DIMM_TYPE == literal_2)
                                                 && (l_TGT1_ATTR_CEN_EFF_CUSTOM_DIMM == literal_1))));
        uint64_t l_def_mba23_2a_2socket = (l_def_mba23 && ((((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba23_2c_cdimm) || l_def_mba23_3a_cdimm));
        uint64_t l_def_mba23_1d_2socket = (l_def_mba23 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_4)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)));
        uint64_t l_def_mba23_1c_2socket = ((l_def_mba23 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_3)
                                            && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2))) || l_def_mba23_1d_2socket);
        uint64_t l_def_mba23_1b_2socket = (l_def_mba23 && (((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_2)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)) || l_def_mba23_1c_cdimm));
        uint64_t l_def_mba23_1a_2socket = (l_def_mba23 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_1)
                                           && (l_TGT1_ATTR_CEN_EFF_NUM_DROPS_PER_PORT == literal_2)));
        uint64_t l_def_mba23_Planar_DIMM_with_both_DIMM_slots_0_and_1_populated = ((((((((((((((((((((((((((((((((
                    l_def_mba23_1a_2socket || l_def_mba23_1b_2socket) || l_def_mba23_1c_2socket) || l_def_mba23_2a_2socket)
                || l_def_mba23_2a_2socket_ddr4) || l_def_mba23_2b_2socket) || l_def_mba23_2b_2socket_ddr4) || l_def_mba23_2c_2socket)
                || l_def_mba23_2c_2socket_ddr4) || l_def_mba23_3a_2socket) || l_def_mba23_3a_2socket_ddr4) || l_def_mba23_3b_2socket)
                || l_def_mba23_3c_2socket_ddr4) || l_def_mba23_5b_2socket) || l_def_mba23_5c_2socket) || l_def_mba23_5d_2socket)
                || l_def_mba23_7a_2socket) || l_def_mba23_7b_2socket) || l_def_mba23_7c_2socket) || l_def_mba23_7a_2socket_ddr4)
                || l_def_mba23_7b_2socket_ddr4) || l_def_mba23_7c_2socket_ddr4) || l_def_mba23_1c_cdimm) || l_def_mba23_3a_cdimm)
                || l_def_mba23_3b_cdimm) || l_def_mba23_3c_cdimm) || l_def_mba23_3a_ddr4_cdimm) || l_def_mba23_3b_ddr4_cdimm)
                || l_def_mba23_3c_ddr4_cdimm) || l_def_mba23_4a_cdimm) || l_def_mba23_4a_ddr4_cdimm) || l_def_mba23_4b_ddr4_cdimm)
                || l_def_mba23_4c_ddr4_cdimm);
        uint64_t l_def_mba23_hash0_type3c_7c = (l_def_mba23
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_10)
                                                        || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_23)));
        uint64_t l_def_mba23_hash0_type3b_7b = (l_def_mba23
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_9)
                                                        || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_22)));
        uint64_t l_def_mba23_hash0_type2c = (l_def_mba23 && (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_7));
        uint64_t l_def_mba23_hash0_type2b = (l_def_mba23 && (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_6));
        uint64_t l_def_mba23_hash0_type2a = ((l_def_mba23 && (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5))
                                             && ((l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_0] == literal_0)
                                                     || (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_1] == literal_0)));
        uint64_t l_def_mba23_hash0_type1a = ((l_def_mba23 && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_1)
                                              || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_1] == literal_1)))
                                             && ((l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_0] == literal_0)
                                                     || (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_1] == literal_0)));
        uint64_t l_def_mba23_hash0_sel = ((((((l_def_mba23 && l_def_mba23_hash0_type1a) || l_def_mba23_hash0_type2a)
                                             || l_def_mba23_hash0_type2b) || l_def_mba23_hash0_type2c) || l_def_mba23_hash0_type3b_7b)
                                          || l_def_mba23_hash0_type3c_7c);
        uint64_t l_def_mba23_hash2_type1d_5c = (l_def_mba23
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_4)
                                                        || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_16)));
        uint64_t l_def_mba23_hash2_type1b_5b = (((l_def_mba23
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_2)
                                                        || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_15)))
                                                && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_0] != literal_0))
                                                && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_1] != literal_0));
        uint64_t l_def_mba23_hash2_sel = ((l_def_mba23 && l_def_mba23_hash2_type1b_5b) || l_def_mba23_hash2_type1d_5c);
        uint64_t l_def_mba23_hash1_type3a_7a = (l_def_mba23
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_8)
                                                        || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_21)));
        uint64_t l_def_mba23_hash1_type2a = (((l_def_mba23
                                               && (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_5))
                                              && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_0] != literal_0))
                                             && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_1] != literal_0));
        uint64_t l_def_mba23_hash1_type1b_5b = ((l_def_mba23
                                                && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_2)
                                                        || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_15)))
                                                && ((l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_0] == literal_0)
                                                        || (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_1] == literal_0)));
        uint64_t l_def_mba23_hash1_type1a = (((l_def_mba23
                                               && ((l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_0] == literal_1)
                                                       || (l_TGT1_ATTR_CEN_EFF_IBM_TYPE[literal_1][literal_1] == literal_1)))
                                              && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_0] != literal_0))
                                             && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_1] != literal_0));
        uint64_t l_def_mba23_hash1_sel = ((((l_def_mba23 && l_def_mba23_hash1_type1a) || l_def_mba23_hash1_type1b_5b)
                                           || l_def_mba23_hash1_type2a) || l_def_mba23_hash1_type3a_7a);
        uint64_t l_def_mba23_mtype_3c = ((l_def_mba23_3c_1socket_ddr4 || l_def_mba23_3c_2socket_ddr4)
                                         || l_def_mba23_4c_ddr4_cdimm);
        uint64_t l_def_mba23_mtype_3b = ((l_def_mba23_3b_1socket || l_def_mba23_3b_2socket) || l_def_mba23_4b_ddr4_cdimm);
        uint64_t l_def_mba23_mtype_3a = (((((l_def_mba23_3a_1socket || l_def_mba23_3a_2socket) || l_def_mba23_3a_1socket_ddr4)
                                           || l_def_mba23_3a_2socket_ddr4) || l_def_mba23_4a_cdimm) || l_def_mba23_4a_ddr4_cdimm);
        uint64_t l_def_mba23_type3_memory_populated_behind_MBA23 = ((l_def_mba23_mtype_3a || l_def_mba23_mtype_3b)
                || l_def_mba23_mtype_3c);
        uint64_t l_def_mba23_nomem = (l_def_mba23
                                      && ((l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_0] == literal_0b00000000)
                                          && (l_TGT1_ATTR_CEN_EFF_DIMM_RANKS_CONFIGED[literal_1][literal_1] == literal_0b00000000)));
        uint64_t l_def_mba23_mtype_5d = (l_def_mba23_5d_1socket || l_def_mba23_5d_2socket);
        uint64_t l_def_mba23_mtype_2c = (((((l_def_mba23_2c_1socket || l_def_mba23_2c_2socket) || l_def_mba23_2c_1socket_ddr4)
                                           || l_def_mba23_2c_2socket_ddr4) || l_def_mba23_3c_cdimm) || l_def_mba23_3c_ddr4_cdimm);
        uint64_t l_def_mba23_mtype_2b = (((((l_def_mba23_2b_1socket || l_def_mba23_2b_2socket) || l_def_mba23_2b_1socket_ddr4)
                                           || l_def_mba23_2b_2socket_ddr4) || l_def_mba23_3b_cdimm) || l_def_mba23_3b_ddr4_cdimm);
        uint64_t l_def_mba23_mtype_2a = (((((l_def_mba23_2a_1socket || l_def_mba23_2a_2socket) || l_def_mba23_2a_1socket_ddr4)
                                           || l_def_mba23_2a_2socket_ddr4) || l_def_mba23_3a_cdimm) || l_def_mba23_3a_ddr4_cdimm);
        uint64_t l_def_mba23_type2_memory_populated_behind_MBA23 = (((l_def_mba23_mtype_2a || l_def_mba23_mtype_2b)
                || l_def_mba23_mtype_2c) || l_def_mba23_mtype_5d);
        uint64_t l_def_mba23_mtype_5c = (l_def_mba23_5c_1socket || l_def_mba23_5c_2socket);
        uint64_t l_def_mba23_mtype_5b = (l_def_mba23_5b_1socket || l_def_mba23_5b_2socket);
        uint64_t l_def_mba23_mtype_5a = (l_def_mba23 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba23_type5_memory_populated_behind_MBA23 = ((l_def_mba23_mtype_5a || l_def_mba23_mtype_5b)
                || l_def_mba23_mtype_5c);
        uint64_t l_def_mba23_mtype_7c = (((l_def_mba23_7c_1socket || l_def_mba23_7c_2socket) || l_def_mba23_7c_1socket_ddr4)
                                         || l_def_mba23_7c_2socket_ddr4);
        uint64_t l_def_mba23_mtype_7b = (((l_def_mba23_7b_1socket || l_def_mba23_7b_2socket) || l_def_mba23_7b_1socket_ddr4)
                                         || l_def_mba23_7b_2socket_ddr4);
        uint64_t l_def_mba23_mtype_7a = (((l_def_mba23_7a_1socket || l_def_mba23_7a_2socket) || l_def_mba23_7a_1socket_ddr4)
                                         || l_def_mba23_7a_2socket_ddr4);
        uint64_t l_def_mba23_type7_memory_populated_behind_MBA23 = ((l_def_mba23_mtype_7a || l_def_mba23_mtype_7b)
                || l_def_mba23_mtype_7c);
        uint64_t l_def_mba23_mtype_6c = (l_def_mba23 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba23_mtype_6b = (l_def_mba23 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba23_mtype_6a = (l_def_mba23 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba23_type6_memory_populated_behind_MBA23 = ((l_def_mba23_mtype_6a || l_def_mba23_mtype_6b)
                || l_def_mba23_mtype_6c);
        uint64_t l_def_mba23_mtype_1c = (l_def_mba23_1c_1socket || l_def_mba23_1c_2socket);
        uint64_t l_def_mba23_mtype_1b = ((l_def_mba23_1b_1socket || l_def_mba23_1b_2socket) || l_def_mba23_1c_cdimm);
        uint64_t l_def_mba23_mtype_1a = (l_def_mba23_1a_1socket || l_def_mba23_1a_2socket);
        uint64_t l_def_mba23_type1_memory_populated_behind_MBA23 = ((l_def_mba23_mtype_1a || l_def_mba23_mtype_1b)
                || l_def_mba23_mtype_1c);
        uint64_t l_def_mba23_mtype_4c = (l_def_mba23 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba23_mtype_4b = (l_def_mba23 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba23_mtype_4a = (l_def_mba23 && (l_TGT0_ATTR_CEN_MSS_FREQ == literal_1400));
        uint64_t l_def_mba23_type4_memory_populated_behind_MBA23 = ((l_def_mba23_mtype_4a || l_def_mba23_mtype_4b)
                || l_def_mba23_mtype_4c);
        uint64_t l_def_mba23_subtype_A = ((((((l_def_mba23_mtype_1a || l_def_mba23_mtype_2a) || l_def_mba23_mtype_3a)
                                             || l_def_mba23_mtype_4a) || l_def_mba23_mtype_5a) || l_def_mba23_mtype_6a) || l_def_mba23_mtype_7a);
        uint64_t l_def_mba23_subtype_C = (((((((l_def_mba23_mtype_1c || l_def_mba23_mtype_2c) || l_def_mba23_mtype_3c)
                                              || l_def_mba23_mtype_4c) || l_def_mba23_mtype_5c) || l_def_mba23_mtype_5d) || l_def_mba23_mtype_6c)
                                          || l_def_mba23_mtype_7c);
        uint64_t l_def_mba23_subtype_B = ((((((l_def_mba23_mtype_1b || l_def_mba23_mtype_2b) || l_def_mba23_mtype_3b)
                                             || l_def_mba23_mtype_4b) || l_def_mba23_mtype_5b) || l_def_mba23_mtype_6b) || l_def_mba23_mtype_7b);
        fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM_Type l_TGT1_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, TGT1, l_TGT1_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM));
        uint64_t l_def_num_mba23_ranks = (l_def_mba23
                                          && (l_TGT1_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_1][literal_0] +
                                              l_TGT1_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_1][literal_1]));
        fapi2::ATTR_CEN_MSS_CLEANER_ENABLE_Type l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_CLEANER_ENABLE, TGT3, l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE));
        uint64_t l_def_num_mba01_ranks = (l_def_mba01
                                          && (l_TGT1_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] +
                                              l_TGT1_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_1]));
        fapi2::ATTR_CEN_MSS_PREFETCH_ENABLE_Type l_TGT3_ATTR_CEN_MSS_PREFETCH_ENABLE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_PREFETCH_ENABLE, TGT3, l_TGT3_ATTR_CEN_MSS_PREFETCH_ENABLE));
        uint64_t l_def_num_mbs_ranks = (((l_TGT1_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] +
                                          l_TGT1_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_1]) +
                                         l_TGT1_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_1][literal_0]) +
                                        l_TGT1_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_1][literal_1]);
        fapi2::ATTR_IS_SIMULATION_Type l_TGT3_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT3, l_TGT3_ATTR_IS_SIMULATION));
        uint64_t l_def_mba01_dis_checkbit_inv = (l_def_mba01 && (l_TGT3_ATTR_IS_SIMULATION == literal_1));
        uint64_t l_def_mba23_dis_checkbit_inv = (l_def_mba23 && (l_TGT3_ATTR_IS_SIMULATION == literal_1));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201080aull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<10, 7, 57, uint64_t>(literal_0b0000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0x0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<18, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<19, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<20, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<21, 5, 59, uint64_t>(literal_0b00000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<26, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<27, 6, 58, uint64_t>(literal_0b010010 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<33, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<35, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<37, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<38, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<39, 5, 59, uint64_t>(literal_0b00000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
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

            FAPI_TRY(fapi2::putScom(TGT0, 0x201080aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2010c42ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<2, 8, 56, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2010c42ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201140aull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<5, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT == literal_28))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b10101 );
            }
            else if ((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT == literal_27))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b10100 );
            }
            else if ((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT == literal_24))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b10001 );
            }
            else if ((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT == literal_0))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if ((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT == literal_31))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b11000 );
            }
            else if ((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT == literal_30))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b10111 );
            }
            else if ((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT == literal_25))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b10010 );
            }
            else if ((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT == literal_26))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b10011 );
            }
            else if ((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT == literal_0))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b00000 );
            }
            else if ((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT == literal_29))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b10110 );
            }
            else if ((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT == literal_23))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b10000 );
            }
            else if ((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT == literal_32))
            {
                l_scom_buffer.insert<0, 5, 59, uint64_t>(literal_0b11001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x201140aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201140bull, l_scom_buffer ));

            if ((l_TGT1_ATTR_CEN_EFF_DRAM_DENSITY == literal_2))
            {
                l_scom_buffer.insert<6, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_TGT1_ATTR_CEN_EFF_DRAM_DENSITY == literal_8))
            {
                l_scom_buffer.insert<6, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_TGT1_ATTR_CEN_EFF_DRAM_DENSITY == literal_4))
            {
                l_scom_buffer.insert<6, 2, 62, uint64_t>(literal_0b01 );
            }

            if ((l_TGT1_ATTR_CEN_EFF_DRAM_WIDTH == literal_8))
            {
                l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT1_ATTR_CEN_EFF_DRAM_WIDTH == literal_4))
            {
                l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_def_mba01_type3_memory_populated_behind_MBA01 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0011 );
            }
            else if ((l_def_mba01_nomem == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if ((l_def_mba01_type2_memory_populated_behind_MBA01 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if ((l_def_mba01_type5_memory_populated_behind_MBA01 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0101 );
            }
            else if ((l_def_mba01_type7_memory_populated_behind_MBA01 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if ((l_def_mba01_type6_memory_populated_behind_MBA01 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0110 );
            }
            else if ((l_def_mba01_type1_memory_populated_behind_MBA01 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if ((l_def_mba01_type4_memory_populated_behind_MBA01 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0100 );
            }

            if (l_def_mba01_hash0_sel)
            {
                l_scom_buffer.insert<10, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_mba01_hash2_sel)
            {
                l_scom_buffer.insert<10, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_mba01_hash1_sel)
            {
                l_scom_buffer.insert<10, 2, 62, uint64_t>(literal_0b01 );
            }

            if (((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE == literal_1) && ((l_TGT2_ATTR_FUNCTIONAL == literal_1)
                    && (l_TGT0_ATTR_CEN_MSS_CACHE_ENABLE != literal_0))))
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE == literal_0)
                      || ((l_TGT2_ATTR_FUNCTIONAL == literal_0) || (l_TGT0_ATTR_CEN_MSS_CACHE_ENABLE == literal_0))))
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_def_mba01_Centaur_or_Planar_DIMM_with_only_DIMM_slot0_populated == literal_1))
            {
                l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_mba01_Planar_DIMM_with_both_DIMM_slots_0_and_1_populated == literal_1))
            {
                l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_def_mba01_subtype_A == literal_1))
            {
                l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_mba01_subtype_C == literal_1))
            {
                l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_mba01_subtype_B == literal_1))
            {
                l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x201140bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201140cull, l_scom_buffer ));

            if ((l_TGT1_ATTR_CEN_EFF_DRAM_DENSITY == literal_2))
            {
                l_scom_buffer.insert<6, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_TGT1_ATTR_CEN_EFF_DRAM_DENSITY == literal_8))
            {
                l_scom_buffer.insert<6, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_TGT1_ATTR_CEN_EFF_DRAM_DENSITY == literal_4))
            {
                l_scom_buffer.insert<6, 2, 62, uint64_t>(literal_0b01 );
            }

            if (((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE == literal_0) || ((l_TGT2_ATTR_FUNCTIONAL == literal_0)
                    || (l_TGT0_ATTR_CEN_MSS_CACHE_ENABLE == literal_0))))
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b0 );
            }
            else if (((l_TGT0_ATTR_CEN_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE == literal_1)
                      && ((l_TGT2_ATTR_FUNCTIONAL == literal_1) && (l_TGT0_ATTR_CEN_MSS_CACHE_ENABLE != literal_0))))
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_def_mba23_Centaur_or_Planar_DIMM_with_only_DIMM_slot0_populated == literal_1))
            {
                l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_mba23_Planar_DIMM_with_both_DIMM_slots_0_and_1_populated == literal_1))
            {
                l_scom_buffer.insert<8, 1, 63, uint64_t>(literal_0b1 );
            }

            if (l_def_mba23_hash0_sel)
            {
                l_scom_buffer.insert<10, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_mba23_hash2_sel)
            {
                l_scom_buffer.insert<10, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_mba23_hash1_sel)
            {
                l_scom_buffer.insert<10, 2, 62, uint64_t>(literal_0b01 );
            }

            if ((l_def_mba23_type3_memory_populated_behind_MBA23 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0011 );
            }
            else if ((l_def_mba23_nomem == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0000 );
            }
            else if ((l_def_mba23_type2_memory_populated_behind_MBA23 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if ((l_def_mba23_type5_memory_populated_behind_MBA23 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0101 );
            }
            else if ((l_def_mba23_type7_memory_populated_behind_MBA23 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if ((l_def_mba23_type6_memory_populated_behind_MBA23 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0110 );
            }
            else if ((l_def_mba23_type1_memory_populated_behind_MBA23 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if ((l_def_mba23_type4_memory_populated_behind_MBA23 == literal_1))
            {
                l_scom_buffer.insert<0, 4, 60, uint64_t>(literal_0b0100 );
            }

            if ((l_TGT1_ATTR_CEN_EFF_DRAM_WIDTH == literal_8))
            {
                l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT1_ATTR_CEN_EFF_DRAM_WIDTH == literal_4))
            {
                l_scom_buffer.insert<9, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_def_mba23_subtype_A == literal_1))
            {
                l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_mba23_subtype_C == literal_1))
            {
                l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_mba23_subtype_B == literal_1))
            {
                l_scom_buffer.insert<4, 2, 62, uint64_t>(literal_0b01 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x201140cull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201140dull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<24, 3, 61, uint64_t>(literal_0b000 );
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

            if (literal_1)
            {
                l_scom_buffer.insert<30, 3, 61, uint64_t>(literal_0b010 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<30, 3, 61, uint64_t>(literal_0b010 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<27, 3, 61, uint64_t>(literal_0b001 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<6, 3, 61, uint64_t>(literal_0b010 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<3, 3, 61, uint64_t>(literal_0b001 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<6, 3, 61, uint64_t>(literal_0b010 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<3, 3, 61, uint64_t>(literal_0b001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x201140dull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201140full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<23, 6, 58, uint64_t>(literal_0b000111 );
            }

            if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_1) && (l_def_num_mba23_ranks == literal_2)))
            {
                l_scom_buffer.insert<17, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_1) && (l_def_num_mba01_ranks == literal_4)))
            {
                l_scom_buffer.insert<17, 6, 58, uint64_t>(literal_0b001000 );
            }
            else if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_1) && (l_def_num_mba01_ranks == literal_1)))
            {
                l_scom_buffer.insert<17, 6, 58, uint64_t>(literal_0b100000 );
            }
            else if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_1) && (l_def_num_mba01_ranks == literal_2)))
            {
                l_scom_buffer.insert<17, 6, 58, uint64_t>(literal_0b010000 );
            }
            else if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_1) && (l_def_num_mba23_ranks == literal_1)))
            {
                l_scom_buffer.insert<17, 6, 58, uint64_t>(literal_0b100000 );
            }
            else if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_1) && (l_def_num_mba23_ranks == literal_4)))
            {
                l_scom_buffer.insert<17, 6, 58, uint64_t>(literal_0b001000 );
            }

            if (((l_TGT2_ATTR_FUNCTIONAL == literal_0) || (l_TGT0_ATTR_CEN_MSS_CACHE_ENABLE == literal_0)))
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }
            else if (((l_TGT2_ATTR_FUNCTIONAL == literal_1) && (l_TGT0_ATTR_CEN_MSS_CACHE_ENABLE != literal_0)))
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_0) || ((l_TGT2_ATTR_FUNCTIONAL == literal_0)
                    || (l_TGT0_ATTR_CEN_MSS_CACHE_ENABLE == literal_0))))
            {
                l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b0 );
            }
            else if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_1) && ((l_TGT2_ATTR_FUNCTIONAL == literal_1)
                      && (l_TGT0_ATTR_CEN_MSS_CACHE_ENABLE != literal_0))))
            {
                l_scom_buffer.insert<2, 1, 63, uint64_t>(literal_0b1 );
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
                l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b1 );
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
                l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT3_ATTR_CEN_MSS_PREFETCH_ENABLE == literal_1))
            {
                l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT3_ATTR_CEN_MSS_PREFETCH_ENABLE == literal_0))
            {
                l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_TGT3_ATTR_CEN_MSS_PREFETCH_ENABLE == literal_1))
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT3_ATTR_CEN_MSS_PREFETCH_ENABLE == literal_0))
            {
                l_scom_buffer.insert<12, 1, 63, uint64_t>(literal_0b1 );
            }

            if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_1) && ((l_def_num_mbs_ranks == literal_2)
                    || (l_def_num_mbs_ranks == literal_4))))
            {
                l_scom_buffer.insert<13, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_1) && (l_def_num_mbs_ranks == literal_8)))
            {
                l_scom_buffer.insert<13, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_1) && ((l_def_num_mba01_ranks == literal_1)
                      || (l_def_num_mba01_ranks == literal_2))))
            {
                l_scom_buffer.insert<13, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_1) && (l_def_num_mba01_ranks == literal_4)))
            {
                l_scom_buffer.insert<13, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_1) && ((l_def_num_mba23_ranks == literal_1)
                      || (l_def_num_mba23_ranks == literal_2))))
            {
                l_scom_buffer.insert<13, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if (((l_TGT3_ATTR_CEN_MSS_CLEANER_ENABLE == literal_1) && (l_def_num_mba23_ranks == literal_4)))
            {
                l_scom_buffer.insert<13, 4, 60, uint64_t>(literal_0b0111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<29, 6, 58, uint64_t>(literal_0b000110 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<35, 14, 50, uint64_t>(literal_0b00001000000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 14, 50, uint64_t>(literal_0b00000111110000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x201140full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011428ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 32, 31, uint64_t>(literal_0x00000006 );
            }

            if (literal_1)
            {
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011428ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201144aull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_def_mba01_dis_checkbit_inv == literal_1))
            {
                l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x201144aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201148aull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<16, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_def_mba23_dis_checkbit_inv == literal_1))
            {
                l_scom_buffer.insert<3, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x201148aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011655ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011655ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011681ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x1111111111111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x1111111111111111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011681ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011682ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x2222222222222222 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x2222222222222222 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011682ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011683ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x3333333333333333 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x3333333333333333 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011683ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011684ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x4444444444444444 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x4444444444444444 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011684ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011685ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x5555555555555555 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x5555555555555555 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011685ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011686ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x6666666666666666 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x6666666666666666 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011686ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011687ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x7777777777777777 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x7777777777777777 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011687ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011688ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x8888888888888888 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x8888888888888888 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011688ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011689ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x9999999999999999 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x99 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011689ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201168aull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xAAAAAAAAAAAAAAAA );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xAA );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x201168aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011755ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011755ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011781ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x1111111111111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x1111111111111111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011781ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011782ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x2222222222222222 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x2222222222222222 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011782ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011783ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x3333333333333333 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x3333333333333333 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011783ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011784ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x4444444444444444 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x4444444444444444 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011784ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011785ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x5555555555555555 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x5555555555555555 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011785ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011786ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x6666666666666666 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x6666666666666666 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011786ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011787ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x7777777777777777 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x7777777777777777 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011787ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011788ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x8888888888888888 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x8888888888888888 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011788ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011789ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0x99 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0x9999999999999999 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011789ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201178aull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 8, 56, uint64_t>(literal_0xAA );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<0, 64, 0, uint64_t>(literal_0xAAAAAAAAAAAAAAAA );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x201178aull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2011882ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<2, 8, 56, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2011882ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x20118c2ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<0, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<10, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<11, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<12, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<1, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<2, 8, 56, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x20118c2ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x2012300ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x2012300ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x201230bull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x201230bull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x3012300ull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<7, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x3012300ull, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x301230bull, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<17, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x301230bull, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
