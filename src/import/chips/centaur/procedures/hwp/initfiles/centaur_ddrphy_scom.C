/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/initfiles/centaur_ddrphy_scom.C $ */
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
#include "centaur_ddrphy_scom.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0x000000000000 = 0x000000000000;
constexpr uint64_t literal_4 = 4;
constexpr uint64_t literal_0xFFFF = 0xFFFF;
constexpr uint64_t literal_0x0000 = 0x0000;
constexpr uint64_t literal_0b0 = 0b0;
constexpr uint64_t literal_0b1 = 0b1;
constexpr uint64_t literal_0b0000 = 0b0000;
constexpr uint64_t literal_0x0F00 = 0x0F00;
constexpr uint64_t literal_0x8640 = 0x8640;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0x8580 = 0x8580;
constexpr uint64_t literal_0xC0C0 = 0xC0C0;
constexpr uint64_t literal_0xC300 = 0xC300;
constexpr uint64_t literal_0b000 = 0b000;
constexpr uint64_t literal_68625 = 68625;
constexpr uint64_t literal_48625 = 48625;
constexpr uint64_t literal_0x1 = 0x1;
constexpr uint64_t literal_64500 = 64500;
constexpr uint64_t literal_44500 = 44500;
constexpr uint64_t literal_0x4 = 0x4;
constexpr uint64_t literal_75500 = 75500;
constexpr uint64_t literal_55500 = 55500;
constexpr uint64_t literal_0xB = 0xB;
constexpr uint64_t literal_71375 = 71375;
constexpr uint64_t literal_51375 = 51375;
constexpr uint64_t literal_0x8 = 0x8;
constexpr uint64_t literal_65875 = 65875;
constexpr uint64_t literal_45875 = 45875;
constexpr uint64_t literal_0x3 = 0x3;
constexpr uint64_t literal_79625 = 79625;
constexpr uint64_t literal_59625 = 59625;
constexpr uint64_t literal_0xE = 0xE;
constexpr uint64_t literal_81000 = 81000;
constexpr uint64_t literal_61000 = 61000;
constexpr uint64_t literal_0xF = 0xF;
constexpr uint64_t literal_74125 = 74125;
constexpr uint64_t literal_54125 = 54125;
constexpr uint64_t literal_0xA = 0xA;
constexpr uint64_t literal_76875 = 76875;
constexpr uint64_t literal_56875 = 56875;
constexpr uint64_t literal_0xC = 0xC;
constexpr uint64_t literal_78250 = 78250;
constexpr uint64_t literal_58250 = 58250;
constexpr uint64_t literal_0xD = 0xD;
constexpr uint64_t literal_67250 = 67250;
constexpr uint64_t literal_47250 = 47250;
constexpr uint64_t literal_0x2 = 0x2;
constexpr uint64_t literal_63125 = 63125;
constexpr uint64_t literal_43125 = 43125;
constexpr uint64_t literal_0x5 = 0x5;
constexpr uint64_t literal_0x0 = 0x0;
constexpr uint64_t literal_60375 = 60375;
constexpr uint64_t literal_40375 = 40375;
constexpr uint64_t literal_0x7 = 0x7;
constexpr uint64_t literal_61750 = 61750;
constexpr uint64_t literal_41750 = 41750;
constexpr uint64_t literal_0x6 = 0x6;
constexpr uint64_t literal_72750 = 72750;
constexpr uint64_t literal_52750 = 52750;
constexpr uint64_t literal_0x9 = 0x9;
constexpr uint64_t literal_0b11 = 0b11;
constexpr uint64_t literal_0b00 = 0b00;
constexpr uint64_t literal_8 = 8;
constexpr uint64_t literal_0b1100000 = 0b1100000;
constexpr uint64_t literal_0x1101011 = 0x1101011;
constexpr uint64_t literal_1200 = 1200;
constexpr uint64_t literal_0b1000 = 0b1000;
constexpr uint64_t literal_1460 = 1460;
constexpr uint64_t literal_0b0100 = 0b0100;
constexpr uint64_t literal_1732 = 1732;
constexpr uint64_t literal_0b0010 = 0b0010;
constexpr uint64_t literal_1993 = 1993;
constexpr uint64_t literal_0b1100 = 0b1100;
constexpr uint64_t literal_0b0001 = 0b0001;
constexpr uint64_t literal_0b0011 = 0b0011;
constexpr uint64_t literal_0b0111 = 0b0111;
constexpr uint64_t literal_0b1111 = 0b1111;
constexpr uint64_t literal_0x689 = 0x689;
constexpr uint64_t literal_1459 = 1459;
constexpr uint64_t literal_1400 = 1400;
constexpr uint64_t literal_0b111 = 0b111;
constexpr uint64_t literal_1271 = 1271;
constexpr uint64_t literal_0b10 = 0b10;
constexpr uint64_t literal_0xFFF = 0xFFF;
constexpr uint64_t literal_0x3EF = 0x3EF;
constexpr uint64_t literal_0x7EF = 0x7EF;
constexpr uint64_t literal_0x3CF = 0x3CF;
constexpr uint64_t literal_0x000 = 0x000;
constexpr uint64_t literal_0xFF0 = 0xFF0;
constexpr uint64_t literal_0x7E0 = 0x7E0;
constexpr uint64_t literal_0x3C0 = 0x3C0;
constexpr uint64_t literal_0x186 = 0x186;
constexpr uint64_t literal_0x182 = 0x182;
constexpr uint64_t literal_0x180 = 0x180;
constexpr uint64_t literal_0x102 = 0x102;
constexpr uint64_t literal_0x100 = 0x100;
constexpr uint64_t literal_0x007 = 0x007;
constexpr uint64_t literal_0x003 = 0x003;
constexpr uint64_t literal_0x3C6 = 0x3C6;
constexpr uint64_t literal_0xFF00 = 0xFF00;
constexpr uint64_t literal_0xFF0F = 0xFF0F;
constexpr uint64_t literal_0xFFF0 = 0xFFF0;
constexpr uint64_t literal_0x0C00 = 0x0C00;
constexpr uint64_t literal_0x0CC0 = 0x0CC0;
constexpr uint64_t literal_0x8400 = 0x8400;
constexpr uint64_t literal_0x8480 = 0x8480;
constexpr uint64_t literal_0x8500 = 0x8500;
constexpr uint64_t literal_0x60 = 0x60;
constexpr uint64_t literal_0x6B = 0x6B;
constexpr uint64_t literal_0x8600 = 0x8600;
constexpr uint64_t literal_0x8440 = 0x8440;
constexpr uint64_t literal_0x18 = 0x18;
constexpr uint64_t literal_0x04 = 0x04;
constexpr uint64_t literal_0b01 = 0b01;
constexpr uint64_t literal_0xFFFC = 0xFFFC;
constexpr uint64_t literal_0x26 = 0x26;
constexpr uint64_t literal_0x40 = 0x40;
constexpr uint64_t literal_0x00 = 0x00;
constexpr uint64_t literal_0b0000010 = 0b0000010;
constexpr uint64_t literal_0x70 = 0x70;
constexpr uint64_t literal_0x0001 = 0x0001;
constexpr uint64_t literal_765 = 765;
constexpr uint64_t literal_196605 = 196605;
constexpr uint64_t literal_2 = 2;
constexpr uint64_t literal_455 = 455;
constexpr uint64_t literal_540 = 540;
constexpr uint64_t literal_485 = 485;
constexpr uint64_t literal_510 = 510;
constexpr uint64_t literal_430 = 430;
constexpr uint64_t literal_565 = 565;
constexpr uint64_t literal_490 = 490;
constexpr uint64_t literal_505 = 505;
constexpr uint64_t literal_435 = 435;
constexpr uint64_t literal_560 = 560;
constexpr uint64_t literal_460 = 460;
constexpr uint64_t literal_535 = 535;
constexpr uint64_t literal_420 = 420;
constexpr uint64_t literal_575 = 575;
constexpr uint64_t literal_470 = 470;
constexpr uint64_t literal_525 = 525;
constexpr uint64_t literal_480 = 480;
constexpr uint64_t literal_515 = 515;
constexpr uint64_t literal_440 = 440;
constexpr uint64_t literal_555 = 555;
constexpr uint64_t literal_475 = 475;
constexpr uint64_t literal_520 = 520;
constexpr uint64_t literal_445 = 445;
constexpr uint64_t literal_550 = 550;
constexpr uint64_t literal_495 = 495;
constexpr uint64_t literal_500 = 500;
constexpr uint64_t literal_425 = 425;
constexpr uint64_t literal_570 = 570;
constexpr uint64_t literal_465 = 465;
constexpr uint64_t literal_530 = 530;
constexpr uint64_t literal_450 = 450;
constexpr uint64_t literal_545 = 545;
constexpr uint64_t literal_0xff = 0xff;
constexpr uint64_t literal_0x5555 = 0x5555;
constexpr uint64_t literal_3 = 3;
constexpr uint64_t literal_128 = 128;
constexpr uint64_t literal_256 = 256;
constexpr uint64_t literal_64 = 64;
constexpr uint64_t literal_32 = 32;
constexpr uint64_t literal_2133 = 2133;
constexpr uint64_t literal_3200 = 3200;
constexpr uint64_t literal_16 = 16;
constexpr uint64_t literal_1600 = 1600;
constexpr uint64_t literal_0b00000000000000 = 0b00000000000000;
constexpr uint64_t literal_0b01000 = 0b01000;
constexpr uint64_t literal_0b01111 = 0b01111;
constexpr uint64_t literal_0b1010 = 0b1010;
constexpr uint64_t literal_0x10 = 0x10;
constexpr uint64_t literal_0x1B = 0x1B;
constexpr uint64_t literal_0b000000 = 0b000000;
constexpr uint64_t literal_0b100000 = 0b100000;
constexpr uint64_t literal_0b101010 = 0b101010;
constexpr uint64_t literal_0x0F = 0x0F;
constexpr uint64_t literal_0x4A40 = 0x4A40;
constexpr uint64_t literal_0xC000 = 0xC000;
constexpr uint64_t literal_0xC0 = 0xC0;
constexpr uint64_t literal_0x08 = 0x08;
constexpr uint64_t literal_0x06 = 0x06;
constexpr uint64_t literal_0b111111 = 0b111111;
constexpr uint64_t literal_0x0000000000000000 = 0x0000000000000000;

fapi2::ReturnCode centaur_ddrphy_scom(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& TGT0,
                                      const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1, const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& TGT2)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT2, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT2, l_chip_ec));
        fapi2::ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR_Type l_TGT0_ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, TGT0,
                               l_TGT0_ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR));
        uint64_t l_def_valid_p0 = (l_TGT0_ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR >> literal_4);
        fapi2::ATTR_CEN_EFF_DRAM_WIDTH_Type l_TGT0_ATTR_CEN_EFF_DRAM_WIDTH;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_WIDTH));
        uint64_t l_def_is_x8 = (l_TGT0_ATTR_CEN_EFF_DRAM_WIDTH == ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X8);
        fapi2::ATTR_CHIP_UNIT_POS_Type l_TGT0_ATTR_CHIP_UNIT_POS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, TGT0, l_TGT0_ATTR_CHIP_UNIT_POS));
        uint64_t l_def_is_mba23 = (l_TGT0_ATTR_CHIP_UNIT_POS == literal_1);
        uint64_t l_def_is_x4 = (l_TGT0_ATTR_CEN_EFF_DRAM_WIDTH == ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4);
        uint64_t l_def_is_mba01 = (l_TGT0_ATTR_CHIP_UNIT_POS == literal_0);
        fapi2::ATTR_CEN_EFF_CUSTOM_DIMM_Type l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, TGT0, l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM));
        fapi2::ATTR_CEN_MSS_DQS_SWIZZLE_TYPE_Type l_TGT0_ATTR_CEN_MSS_DQS_SWIZZLE_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_DQS_SWIZZLE_TYPE, TGT0, l_TGT0_ATTR_CEN_MSS_DQS_SWIZZLE_TYPE));
        uint64_t l_def_is_type1 = ((l_TGT0_ATTR_CEN_MSS_DQS_SWIZZLE_TYPE == literal_1)
                                   && (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM != ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES));
        fapi2::ATTR_CEN_EFF_DRAM_GEN_Type l_TGT0_ATTR_CEN_EFF_DRAM_GEN;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_GEN));
        uint64_t l_def_is_ddr4 = (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4);
        fapi2::ATTR_CEN_EFF_RD_VREF_Type l_TGT0_ATTR_CEN_EFF_RD_VREF;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_RD_VREF, TGT0, l_TGT0_ATTR_CEN_EFF_RD_VREF));
        uint64_t l_def_dqs_offset = literal_8;
        fapi2::ATTR_IS_SIMULATION_Type l_TGT1_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT1, l_TGT1_ATTR_IS_SIMULATION));
        uint64_t l_def_is_sim = (l_TGT1_ATTR_IS_SIMULATION == literal_1);
        fapi2::ATTR_CEN_MSS_EFF_VPD_VERSION_Type l_TGT0_ATTR_CEN_MSS_EFF_VPD_VERSION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_EFF_VPD_VERSION, TGT0, l_TGT0_ATTR_CEN_MSS_EFF_VPD_VERSION));
        uint64_t l_def_old_cdimm = (l_TGT0_ATTR_CEN_MSS_EFF_VPD_VERSION == ENUM_ATTR_CEN_VPD_VERSION_OLD_CDIMM);
        fapi2::ATTR_CEN_VPD_TSYS_DP18_Type l_TGT0_ATTR_CEN_VPD_TSYS_DP18;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_TSYS_DP18, TGT0, l_TGT0_ATTR_CEN_VPD_TSYS_DP18));
        fapi2::ATTR_CEN_MSS_FREQ_Type l_TGT2_ATTR_CEN_MSS_FREQ;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, TGT2, l_TGT2_ATTR_CEN_MSS_FREQ));
        fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_Type l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS, TGT0, l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS));
        uint64_t l_def_ffe1_p0 = (((l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] ==
                                    ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE480)
                                   || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE480))
                                  || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE480));
        uint64_t l_def_ffe2_p0 = (((l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] ==
                                    ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE240)
                                   || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE240))
                                  || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE240));
        uint64_t l_def_ffe3_p0 = (((l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] ==
                                    ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE160)
                                   || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE160))
                                  || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE160));
        uint64_t l_def_ffe4_p0 = (((l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] ==
                                    ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE120)
                                   || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE120))
                                  || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE120));
        fapi2::ATTR_CEN_MSS_VOLT_Type l_TGT2_ATTR_CEN_MSS_VOLT;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_VOLT, TGT2, l_TGT2_ATTR_CEN_MSS_VOLT));
        uint64_t l_def_cdi_dqs_ohm24_p0 = (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] ==
                                           ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM24_FFE0);
        uint64_t l_def_cdi_dqs_ohm34_p0 = (((((l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] ==
                                               ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0)
                                              || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE480))
                                             || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE240))
                                            || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE160))
                                           || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE120));
        uint64_t l_def_cdi_dqs_ohm30_p0 = (((((l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] ==
                                               ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE0)
                                              || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE480))
                                             || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE240))
                                            || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE160))
                                           || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE120));
        uint64_t l_def_cdi_dqs_ohm40_p0 = (((((l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] ==
                                               ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE0)
                                              || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE480))
                                             || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE240))
                                            || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE160))
                                           || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_0] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE120));
        fapi2::ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_Type l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS, TGT0, l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS));
        uint64_t l_def_cri_dqs_ohm15_p0 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_0] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM15);
        uint64_t l_def_is_ddr3 = (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3);
        uint64_t l_def_cri_dqs_ohm20_p0 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_0] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM20);
        uint64_t l_def_cri_dqs_ohm30_p0 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_0] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM30);
        uint64_t l_def_cri_dqs_ohm40_p0 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_0] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM40);
        uint64_t l_def_cri_dqs_ohm48_p0 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_0] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM48);
        uint64_t l_def_cri_dqs_ohm60_p0 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_0] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM60);
        uint64_t l_def_cri_dqs_ohm80_p0 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_0] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM80);
        uint64_t l_def_cri_dqs_ohm120_p0 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_0] ==
                                            ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM120);
        uint64_t l_def_cri_dqs_ohm160_p0 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_0] ==
                                            ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM160);
        uint64_t l_def_cri_dqs_ohm240_p0 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_0] ==
                                            ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM240);
        fapi2::ATTR_CEN_VPD_DIMM_SPARE_Type l_TGT0_ATTR_CEN_VPD_DIMM_SPARE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DIMM_SPARE, TGT0, l_TGT0_ATTR_CEN_VPD_DIMM_SPARE));
        uint64_t l_def_p0_no_spare = (l_TGT0_ATTR_CEN_VPD_DIMM_SPARE[literal_0][literal_0][literal_0] ==
                                      ENUM_ATTR_CEN_VPD_DIMM_SPARE_NO_SPARE);
        uint64_t l_def_p0_has_spare_upper = (l_TGT0_ATTR_CEN_VPD_DIMM_SPARE[literal_0][literal_0][literal_0] ==
                                             ENUM_ATTR_CEN_VPD_DIMM_SPARE_HIGH_NIBBLE);
        uint64_t l_def_p0_has_spare_lower = (l_TGT0_ATTR_CEN_VPD_DIMM_SPARE[literal_0][literal_0][literal_0] ==
                                             ENUM_ATTR_CEN_VPD_DIMM_SPARE_LOW_NIBBLE);
        uint64_t l_def_p0_has_spare_full = (l_TGT0_ATTR_CEN_VPD_DIMM_SPARE[literal_0][literal_0][literal_0] ==
                                            ENUM_ATTR_CEN_VPD_DIMM_SPARE_FULL_BYTE);
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN0_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN0, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN0));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE1_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE1, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE1));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A3_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A3;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A3, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A3));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN3_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN3;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN3, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN3));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE0_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE0, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE0));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN3_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN3;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN3, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN3));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT0_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT0, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT0));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_RASN_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_RASN;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_RASN, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_RASN));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A15_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A15;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A15, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A15));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A12_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A12;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A12, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A12));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A7_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A7;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A7, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A7));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_PAR_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_PAR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_PAR, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_PAR));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE1_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE1, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE1));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN1_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN1, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN1));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE0_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE0, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE0));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT0_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT0, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT0));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE2_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE2, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE2));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE2_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE2, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE2));
        fapi2::ATTR_CEN_VPD_DRV_IMP_ADDR_Type l_TGT0_ATTR_CEN_VPD_DRV_IMP_ADDR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRV_IMP_ADDR, TGT0, l_TGT0_ATTR_CEN_VPD_DRV_IMP_ADDR));
        uint64_t l_def_cdi_addr_ohm15_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_ADDR[literal_0] ==
                                            ENUM_ATTR_CEN_VPD_DRV_IMP_ADDR_OHM15);
        uint64_t l_def_cdi_addr_ohm30_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_ADDR[literal_0] ==
                                            ENUM_ATTR_CEN_VPD_DRV_IMP_ADDR_OHM30);
        uint64_t l_def_cdi_addr_ohm20_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_ADDR[literal_0] ==
                                            ENUM_ATTR_CEN_VPD_DRV_IMP_ADDR_OHM20);
        uint64_t l_def_cdi_addr_ohm40_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_ADDR[literal_0] ==
                                            ENUM_ATTR_CEN_VPD_DRV_IMP_ADDR_OHM40);
        fapi2::ATTR_CEN_VPD_DRV_IMP_CNTL_Type l_TGT0_ATTR_CEN_VPD_DRV_IMP_CNTL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRV_IMP_CNTL, TGT0, l_TGT0_ATTR_CEN_VPD_DRV_IMP_CNTL));
        uint64_t l_def_cdi_ctl_ohm15_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CNTL[literal_0] == ENUM_ATTR_CEN_VPD_DRV_IMP_CNTL_OHM15);
        uint64_t l_def_cdi_ctl_ohm30_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CNTL[literal_0] == ENUM_ATTR_CEN_VPD_DRV_IMP_CNTL_OHM30);
        uint64_t l_def_cdi_ctl_ohm20_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CNTL[literal_0] == ENUM_ATTR_CEN_VPD_DRV_IMP_CNTL_OHM20);
        uint64_t l_def_cdi_ctl_ohm40_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CNTL[literal_0] == ENUM_ATTR_CEN_VPD_DRV_IMP_CNTL_OHM40);
        fapi2::ATTR_CEN_VPD_DRV_IMP_CLK_Type l_TGT0_ATTR_CEN_VPD_DRV_IMP_CLK;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRV_IMP_CLK, TGT0, l_TGT0_ATTR_CEN_VPD_DRV_IMP_CLK));
        uint64_t l_def_cdi_clk_ohm15_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CLK[literal_0] == ENUM_ATTR_CEN_VPD_DRV_IMP_CLK_OHM15);
        uint64_t l_def_cdi_clk_ohm30_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CLK[literal_0] == ENUM_ATTR_CEN_VPD_DRV_IMP_CLK_OHM30);
        uint64_t l_def_cdi_clk_ohm20_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CLK[literal_0] == ENUM_ATTR_CEN_VPD_DRV_IMP_CLK_OHM20);
        uint64_t l_def_cdi_clk_ohm40_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CLK[literal_0] == ENUM_ATTR_CEN_VPD_DRV_IMP_CLK_OHM40);
        fapi2::ATTR_CEN_VPD_DRV_IMP_SPCKE_Type l_TGT0_ATTR_CEN_VPD_DRV_IMP_SPCKE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRV_IMP_SPCKE, TGT0, l_TGT0_ATTR_CEN_VPD_DRV_IMP_SPCKE));
        uint64_t l_def_cdi_spcke_ohm15_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_SPCKE[literal_0] ==
                                             ENUM_ATTR_CEN_VPD_DRV_IMP_SPCKE_OHM15);
        uint64_t l_def_cdi_spcke_ohm30_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_SPCKE[literal_0] ==
                                             ENUM_ATTR_CEN_VPD_DRV_IMP_SPCKE_OHM30);
        uint64_t l_def_cdi_spcke_ohm20_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_SPCKE[literal_0] ==
                                             ENUM_ATTR_CEN_VPD_DRV_IMP_SPCKE_OHM20);
        uint64_t l_def_cdi_spcke_ohm40_p0 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_SPCKE[literal_0] ==
                                             ENUM_ATTR_CEN_VPD_DRV_IMP_SPCKE_OHM40);
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA2_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA2, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA2));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE3_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE3;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE3, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE3));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT1_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT1, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT1));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT1_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT1, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT1));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A2_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A2, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A2));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_WEN_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_WEN;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_WEN, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_WEN));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A6_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A6;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A6, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A6));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A11_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A11;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A11, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A11));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A1_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A1, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A1));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A14_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A14;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A14, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A14));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE3_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE3;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE3, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE3));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN2_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN2, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN2));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN2_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN2, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN2));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A8_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A8;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A8, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A8));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A4_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A4;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A4, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A4));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A5_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A5;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A5, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A5));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN0_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN0, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN0));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A0_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A0, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A0));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A13_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A13;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A13, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A13));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN1_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN1, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN1));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA1_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA1, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA1));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A10_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A10;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A10, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A10));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA0_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA0, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA0));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_CASN_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_CASN;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_CASN, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_CASN));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A9_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A9;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A9, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A9));
        fapi2::ATTR_CEN_VPD_PHASE_ROT_M_ACTN_Type l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_ACTN;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_PHASE_ROT_M_ACTN, TGT0, l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_ACTN));
        fapi2::ATTR_CEN_VPD_TSYS_ADR_Type l_TGT0_ATTR_CEN_VPD_TSYS_ADR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_TSYS_ADR, TGT0, l_TGT0_ATTR_CEN_VPD_TSYS_ADR));
        fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP1_Type l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP1, TGT0, l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP1));
        uint64_t l_def_val_srg1_p0 = (l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP1[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_SECONDARY_RANK_GROUP1_INVALID);
        fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP0_Type l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP0, TGT0, l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0));
        uint64_t l_def_val_prg0_p0 = (l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0_INVALID);
        fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP0_Type l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP0, TGT0, l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP0));
        uint64_t l_def_val_srg0_p0 = (l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP0[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_SECONDARY_RANK_GROUP0_INVALID);
        fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP1_Type l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP1, TGT0, l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP1));
        uint64_t l_def_val_prg1_p0 = (l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP1[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP1_INVALID);
        fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP3_Type l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP3;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP3, TGT0, l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP3));
        uint64_t l_def_val_prg3_p0 = (l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP3[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP3_INVALID);
        fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP2_Type l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_PRIMARY_RANK_GROUP2, TGT0, l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP2));
        uint64_t l_def_val_prg2_p0 = (l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP2[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP2_INVALID);
        fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP2_Type l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP2, TGT0, l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP2));
        uint64_t l_def_val_srg2_p0 = (l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP2[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_SECONDARY_RANK_GROUP2_INVALID);
        fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP3_Type l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP3;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SECONDARY_RANK_GROUP3, TGT0, l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP3));
        uint64_t l_def_val_srg3_p0 = (l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP3[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_SECONDARY_RANK_GROUP3_INVALID);
        uint64_t l_def_FAST_SIM_PC = (l_TGT1_ATTR_IS_SIMULATION == literal_1);
        fapi2::ATTR_CEN_EFF_MEMCAL_INTERVAL_Type l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MEMCAL_INTERVAL, TGT0, l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL));
        fapi2::ATTR_CEN_EFF_ZQCAL_INTERVAL_Type l_TGT0_ATTR_CEN_EFF_ZQCAL_INTERVAL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_ZQCAL_INTERVAL, TGT0, l_TGT0_ATTR_CEN_EFF_ZQCAL_INTERVAL));
        uint64_t l_def_not_ddr4 = (l_TGT0_ATTR_CEN_EFF_DRAM_GEN != ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4);
        fapi2::ATTR_CEN_VPD_WLO_Type l_TGT0_ATTR_CEN_VPD_WLO;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_WLO, TGT0, l_TGT0_ATTR_CEN_VPD_WLO));
        fapi2::ATTR_CEN_VPD_RLO_Type l_TGT0_ATTR_CEN_VPD_RLO;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_RLO, TGT0, l_TGT0_ATTR_CEN_VPD_RLO));
        uint64_t l_def_is_custom = (l_TGT0_ATTR_CEN_EFF_CUSTOM_DIMM == ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES);
        fapi2::ATTR_CEN_EFF_DIMM_TYPE_Type l_TGT0_ATTR_CEN_EFF_DIMM_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, TGT0, l_TGT0_ATTR_CEN_EFF_DIMM_TYPE));
        uint64_t l_def_is_lrdimm = (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM);
        uint64_t l_def_is_rdimm = (l_TGT0_ATTR_CEN_EFF_DIMM_TYPE == ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM);
        fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM_Type l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, TGT0, l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM));
        fapi2::ATTR_CEN_EFF_DRAM_WR_VREF_Type l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WR_VREF, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF));
        fapi2::ATTR_CEN_EFF_DRAM_TRFI_Type l_TGT0_ATTR_CEN_EFF_DRAM_TRFI;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRFI, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_TRFI));
        fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP0_Type l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP0, TGT0, l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP0));
        uint64_t l_def_val_trg0_p0 = (l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP0[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_TERTIARY_RANK_GROUP0_INVALID);
        fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0_Type l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0, TGT0, l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0));
        uint64_t l_def_val_qrg0_p0 = (l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0_INVALID);
        fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP1_Type l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP1, TGT0, l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP1));
        uint64_t l_def_val_trg1_p0 = (l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP1[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_TERTIARY_RANK_GROUP1_INVALID);
        fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1_Type l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1, TGT0, l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1));
        uint64_t l_def_val_qrg1_p0 = (l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1_INVALID);
        fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP2_Type l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP2, TGT0, l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP2));
        uint64_t l_def_val_trg2_p0 = (l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP2[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_TERTIARY_RANK_GROUP2_INVALID);
        fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2_Type l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2, TGT0, l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2));
        uint64_t l_def_val_qrg2_p0 = (l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2_INVALID);
        fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP3_Type l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP3;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TERTIARY_RANK_GROUP3, TGT0, l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP3));
        uint64_t l_def_val_trg3_p0 = (l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP3[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_TERTIARY_RANK_GROUP3_INVALID);
        fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3_Type l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3, TGT0, l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3));
        uint64_t l_def_val_qrg3_p0 = (l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3[literal_0] !=
                                      ENUM_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3_INVALID);
        fapi2::ATTR_CEN_EFF_STACK_TYPE_Type l_TGT0_ATTR_CEN_EFF_STACK_TYPE;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, TGT0, l_TGT0_ATTR_CEN_EFF_STACK_TYPE));
        uint64_t l_def_is_tsv_ddr4_p0 = ((l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_0][literal_0] ==
                                          ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS) && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4));
        fapi2::ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED_Type l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED, TGT0, l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED));
        uint64_t l_def_2N_mode = (l_TGT0_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED == ENUM_ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED_TRUE);
        fapi2::ATTR_CEN_VPD_ODT_WR_Type l_TGT0_ATTR_CEN_VPD_ODT_WR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_ODT_WR, TGT0, l_TGT0_ATTR_CEN_VPD_ODT_WR));
        fapi2::ATTR_CEN_VPD_ODT_RD_Type l_TGT0_ATTR_CEN_VPD_ODT_RD;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_ODT_RD, TGT0, l_TGT0_ATTR_CEN_VPD_ODT_RD));
        fapi2::ATTR_CEN_EFF_DRAM_TRFC_Type l_TGT0_ATTR_CEN_EFF_DRAM_TRFC;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRFC, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_TRFC));
        fapi2::ATTR_CEN_EFF_DRAM_TRCD_Type l_TGT0_ATTR_CEN_EFF_DRAM_TRCD;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRCD, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_TRCD));
        fapi2::ATTR_CEN_EFF_DRAM_TRP_Type l_TGT0_ATTR_CEN_EFF_DRAM_TRP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRP, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_TRP));
        fapi2::ATTR_CEN_EFF_DRAM_TRC_Type l_TGT0_ATTR_CEN_EFF_DRAM_TRC;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRC, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_TRC));
        fapi2::ATTR_CEN_EFF_DRAM_CWL_Type l_TGT0_ATTR_CEN_EFF_DRAM_CWL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CWL, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_CWL));
        uint64_t l_def_tODTL_DDR4_NOAL = (l_TGT0_ATTR_CEN_EFF_DRAM_CWL - literal_3);
        fapi2::ATTR_CEN_EFF_DRAM_AL_Type l_TGT0_ATTR_CEN_EFF_DRAM_AL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_AL, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_AL));
        uint64_t l_def_AL_dis = (l_TGT0_ATTR_CEN_EFF_DRAM_AL == literal_0);
        fapi2::ATTR_CEN_EFF_DRAM_CL_Type l_TGT0_ATTR_CEN_EFF_DRAM_CL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CL, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_CL));
        uint64_t l_def_tODTL_DDR3 = (((l_TGT0_ATTR_CEN_EFF_DRAM_CWL + l_TGT0_ATTR_CEN_EFF_DRAM_CL) -
                                      l_TGT0_ATTR_CEN_EFF_DRAM_AL) - literal_2);
        uint64_t l_def_AL_ena = (l_TGT0_ATTR_CEN_EFF_DRAM_AL != literal_0);
        uint64_t l_def_tODTL_DDR3_NOAL = (l_TGT0_ATTR_CEN_EFF_DRAM_CWL - literal_2);
        uint64_t l_def_tODTL_DDR4 = (((l_TGT0_ATTR_CEN_EFF_DRAM_CWL + l_TGT0_ATTR_CEN_EFF_DRAM_CL) -
                                      l_TGT0_ATTR_CEN_EFF_DRAM_AL) - literal_3);
        fapi2::ATTR_CEN_VPD_GPO_Type l_TGT0_ATTR_CEN_VPD_GPO;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_GPO, TGT0, l_TGT0_ATTR_CEN_VPD_GPO));
        fapi2::ATTR_CEN_EFF_DRAM_BL_Type l_TGT0_ATTR_CEN_EFF_DRAM_BL;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_BL, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_BL));
        uint64_t l_def_is_bl8 = (l_TGT0_ATTR_CEN_EFF_DRAM_BL == ENUM_ATTR_CEN_EFF_DRAM_BL_BL8);
        fapi2::ATTR_CEN_EFF_DRAM_TRTP_Type l_TGT0_ATTR_CEN_EFF_DRAM_TRTP;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TRTP, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_TRTP));
        uint64_t l_def_TRTP_PLUS_AL = ((((l_TGT0_ATTR_CEN_EFF_DRAM_TRTP + l_TGT0_ATTR_CEN_EFF_DRAM_CL) +
                                         l_TGT0_ATTR_CEN_EFF_DRAM_CL) - l_TGT0_ATTR_CEN_EFF_DRAM_AL) + l_TGT0_ATTR_CEN_VPD_GPO[literal_0]);
        fapi2::ATTR_CEN_EFF_DRAM_TWTR_Type l_TGT0_ATTR_CEN_EFF_DRAM_TWTR;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_TWTR, TGT0, l_TGT0_ATTR_CEN_EFF_DRAM_TWTR));
        uint64_t l_def_TWTR_PLUS_OFF = (l_TGT0_ATTR_CEN_EFF_DRAM_TWTR + literal_8);
        uint64_t l_def_TRTP_PLUS_NOAL = ((l_TGT0_ATTR_CEN_EFF_DRAM_TRTP + l_TGT0_ATTR_CEN_EFF_DRAM_CL) +
                                         l_TGT0_ATTR_CEN_VPD_GPO[literal_0]);
        uint64_t l_def_valid_p1 = (l_TGT0_ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR & literal_0x0F);
        uint64_t l_def_cdi_dqs_ohm24_p1 = (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] ==
                                           ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM24_FFE0);
        uint64_t l_def_cdi_dqs_ohm34_p1 = (((((l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] ==
                                               ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0)
                                              || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE480))
                                             || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE240))
                                            || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE160))
                                           || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE120));
        uint64_t l_def_cdi_dqs_ohm30_p1 = (((((l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] ==
                                               ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE0)
                                              || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE480))
                                             || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE240))
                                            || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE160))
                                           || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE120));
        uint64_t l_def_cdi_dqs_ohm40_p1 = (((((l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] ==
                                               ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE0)
                                              || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE480))
                                             || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE240))
                                            || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE160))
                                           || (l_TGT0_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS[literal_1] == ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE120));
        uint64_t l_def_cri_dqs_ohm15_p1 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_1] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM15);
        uint64_t l_def_cri_dqs_ohm20_p1 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_1] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM20);
        uint64_t l_def_cri_dqs_ohm30_p1 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_1] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM30);
        uint64_t l_def_cri_dqs_ohm40_p1 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_1] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM40);
        uint64_t l_def_cri_dqs_ohm48_p1 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_1] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM48);
        uint64_t l_def_cri_dqs_ohm60_p1 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_1] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM60);
        uint64_t l_def_cri_dqs_ohm80_p1 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_1] ==
                                           ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM80);
        uint64_t l_def_cri_dqs_ohm120_p1 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_1] ==
                                            ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM120);
        uint64_t l_def_cri_dqs_ohm160_p1 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_1] ==
                                            ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM160);
        uint64_t l_def_cri_dqs_ohm240_p1 = (l_TGT0_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS[literal_1] ==
                                            ENUM_ATTR_CEN_EFF_CEN_RCV_IMP_DQ_DQS_OHM240);
        uint64_t l_def_p1_no_spare = (l_TGT0_ATTR_CEN_VPD_DIMM_SPARE[literal_1][literal_0][literal_0] ==
                                      ENUM_ATTR_CEN_VPD_DIMM_SPARE_NO_SPARE);
        uint64_t l_def_p1_has_spare_upper = (l_TGT0_ATTR_CEN_VPD_DIMM_SPARE[literal_1][literal_0][literal_0] ==
                                             ENUM_ATTR_CEN_VPD_DIMM_SPARE_HIGH_NIBBLE);
        uint64_t l_def_p1_has_spare_lower = (l_TGT0_ATTR_CEN_VPD_DIMM_SPARE[literal_1][literal_0][literal_0] ==
                                             ENUM_ATTR_CEN_VPD_DIMM_SPARE_LOW_NIBBLE);
        uint64_t l_def_p1_has_spare_full = (l_TGT0_ATTR_CEN_VPD_DIMM_SPARE[literal_1][literal_0][literal_0] ==
                                            ENUM_ATTR_CEN_VPD_DIMM_SPARE_FULL_BYTE);
        uint64_t l_def_cdi_addr_ohm15_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_ADDR[literal_1] ==
                                            ENUM_ATTR_CEN_VPD_DRV_IMP_ADDR_OHM15);
        uint64_t l_def_cdi_addr_ohm30_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_ADDR[literal_1] ==
                                            ENUM_ATTR_CEN_VPD_DRV_IMP_ADDR_OHM30);
        uint64_t l_def_cdi_addr_ohm20_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_ADDR[literal_1] ==
                                            ENUM_ATTR_CEN_VPD_DRV_IMP_ADDR_OHM20);
        uint64_t l_def_cdi_addr_ohm40_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_ADDR[literal_1] ==
                                            ENUM_ATTR_CEN_VPD_DRV_IMP_ADDR_OHM40);
        uint64_t l_def_cdi_spcke_ohm15_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_SPCKE[literal_1] ==
                                             ENUM_ATTR_CEN_VPD_DRV_IMP_SPCKE_OHM15);
        uint64_t l_def_cdi_spcke_ohm30_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_SPCKE[literal_1] ==
                                             ENUM_ATTR_CEN_VPD_DRV_IMP_SPCKE_OHM30);
        uint64_t l_def_cdi_spcke_ohm20_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_SPCKE[literal_1] ==
                                             ENUM_ATTR_CEN_VPD_DRV_IMP_SPCKE_OHM20);
        uint64_t l_def_cdi_spcke_ohm40_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_SPCKE[literal_1] ==
                                             ENUM_ATTR_CEN_VPD_DRV_IMP_SPCKE_OHM40);
        uint64_t l_def_cdi_ctl_ohm15_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CNTL[literal_1] == ENUM_ATTR_CEN_VPD_DRV_IMP_CNTL_OHM15);
        uint64_t l_def_cdi_ctl_ohm30_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CNTL[literal_1] == ENUM_ATTR_CEN_VPD_DRV_IMP_CNTL_OHM30);
        uint64_t l_def_cdi_ctl_ohm20_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CNTL[literal_1] == ENUM_ATTR_CEN_VPD_DRV_IMP_CNTL_OHM20);
        uint64_t l_def_cdi_ctl_ohm40_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CNTL[literal_1] == ENUM_ATTR_CEN_VPD_DRV_IMP_CNTL_OHM40);
        uint64_t l_def_cdi_clk_ohm15_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CLK[literal_1] == ENUM_ATTR_CEN_VPD_DRV_IMP_CLK_OHM15);
        uint64_t l_def_cdi_clk_ohm20_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CLK[literal_1] == ENUM_ATTR_CEN_VPD_DRV_IMP_CLK_OHM20);
        uint64_t l_def_cdi_clk_ohm30_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CLK[literal_1] == ENUM_ATTR_CEN_VPD_DRV_IMP_CLK_OHM30);
        uint64_t l_def_cdi_clk_ohm40_p1 = (l_TGT0_ATTR_CEN_VPD_DRV_IMP_CLK[literal_1] == ENUM_ATTR_CEN_VPD_DRV_IMP_CLK_OHM40);
        uint64_t l_def_val_prg1_p1 = (l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP1[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP1_INVALID);
        uint64_t l_def_val_prg0_p1 = (l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0_INVALID);
        uint64_t l_def_val_srg1_p1 = (l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP1[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_SECONDARY_RANK_GROUP1_INVALID);
        uint64_t l_def_val_srg0_p1 = (l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP0[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_SECONDARY_RANK_GROUP0_INVALID);
        uint64_t l_def_val_srg2_p1 = (l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP2[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_SECONDARY_RANK_GROUP2_INVALID);
        uint64_t l_def_val_prg2_p1 = (l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP2[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP2_INVALID);
        uint64_t l_def_val_prg3_p1 = (l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP3[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_PRIMARY_RANK_GROUP3_INVALID);
        uint64_t l_def_val_srg3_p1 = (l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP3[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_SECONDARY_RANK_GROUP3_INVALID);
        uint64_t l_def_val_trg0_p1 = (l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP0[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_TERTIARY_RANK_GROUP0_INVALID);
        uint64_t l_def_val_qrg0_p1 = (l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0_INVALID);
        uint64_t l_def_val_trg1_p1 = (l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP1[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_TERTIARY_RANK_GROUP1_INVALID);
        uint64_t l_def_val_qrg1_p1 = (l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1_INVALID);
        uint64_t l_def_val_trg2_p1 = (l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP2[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_TERTIARY_RANK_GROUP2_INVALID);
        uint64_t l_def_val_qrg3_p1 = (l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3_INVALID);
        uint64_t l_def_val_qrg2_p1 = (l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2_INVALID);
        uint64_t l_def_val_trg3_p1 = (l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP3[literal_1] !=
                                      ENUM_ATTR_CEN_EFF_TERTIARY_RANK_GROUP3_INVALID);
        uint64_t l_def_is_tsv_ddr4_p1 = ((l_TGT0_ATTR_CEN_EFF_STACK_TYPE[literal_1][literal_0] ==
                                          ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS) && (l_TGT0_ATTR_CEN_EFF_DRAM_GEN == ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4));
        fapi2::buffer<uint64_t> l_scom_buffer;
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_valid_p0)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000030301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000030301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000060301143full, l_scom_buffer ));

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_48625)
                 || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_68625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_44500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_64500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_55500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_75500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_51375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_71375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_45875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_65875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_59625)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_79625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61000)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_81000)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_54125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_74125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_56875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_76875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_58250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_78250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_47250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_67250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_43125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_63125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_40375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_60375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_41750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_52750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_72750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x9 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_48625)
                 || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_68625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_44500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_64500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_55500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_75500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_51375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_71375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_45875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_65875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_59625)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_79625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_61000)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_81000)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_54125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_74125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_56875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_76875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_58250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_78250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_47250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_67250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_43125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_63125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_40375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_60375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_41750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_61750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_52750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_72750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x9 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000120301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000120301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000370301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_def_dqs_offset );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000370301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000740301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0b1100000 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x1101011 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_DP18[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000740301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000750301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1993)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (l_def_ffe1_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_ffe2_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0011 );
            }
            else if (l_def_ffe3_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_ffe4_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000750301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000760301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000760301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000770301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000770301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000780301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000780301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800000790301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800000790301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000007a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000007a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000007b0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C6 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000007b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800001040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800001040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800001050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800001050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800002040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800002040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800002050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800002050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800003040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800003040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800003050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800003050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_valid_p0) && l_def_p0_no_spare))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF00 );
            }
            else if (((l_def_is_mba01 && l_def_valid_p0) && l_def_p0_has_spare_upper))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF0F );
            }
            else if (((l_def_is_mba01 && l_def_valid_p0) && l_def_p0_has_spare_lower))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFF0 );
            }
            else if ((l_def_is_mba23 && l_def_valid_p0))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            if (((l_def_is_mba01 && l_def_valid_p0) && l_def_p0_has_spare_full))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (((l_def_is_mba01 && l_def_valid_p0) && l_def_p0_no_spare))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF00 );
            }
            else if (((l_def_is_mba01 && l_def_valid_p0) && l_def_p0_has_spare_upper))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF0F );
            }
            else if (((l_def_is_mba01 && l_def_valid_p0) && l_def_p0_has_spare_lower))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFF0 );
            }
            else if ((l_def_is_mba23 && l_def_valid_p0))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004030301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004030301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_is_x4) && (l_def_p0_has_spare_upper || l_def_p0_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0C00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8480 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8500 );
            }
            else if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004060301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_48625)
                 || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_68625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_44500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_64500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_55500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_75500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_51375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_71375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_45875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_65875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_59625)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_79625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61000)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_81000)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_54125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_74125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_56875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_76875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_58250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_78250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_47250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_67250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_43125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_63125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_40375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_60375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_41750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_52750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_72750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x9 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004120301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004120301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004370301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_def_dqs_offset );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004370301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004740301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x60 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x6B );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_DP18[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004740301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004750301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1993)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (l_def_ffe1_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_ffe2_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0011 );
            }
            else if (l_def_ffe3_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_ffe4_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004750301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004760301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004760301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004770301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004770301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004780301143full, l_scom_buffer ));

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004780301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800004790301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800004790301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000047a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000047a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000047b0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C6 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000047b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800005040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_is_x4) && (l_def_p0_has_spare_upper || l_def_p0_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0C00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800005040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800005050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_p0_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0C00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8480 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8500 );
            }
            else if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800005050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800006040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba01 && l_def_is_x4) && (l_def_p0_has_spare_upper || l_def_p0_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800006040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800006050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0C00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8480 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8500 );
            }
            else if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800006050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800007040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_is_x4) && (l_def_p0_has_spare_upper || l_def_p0_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0C00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800007040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800007050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_p0_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0C00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8480 );
            }
            else if (((l_def_is_mba01 && l_def_p0_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8500 );
            }
            else if (((l_def_is_mba01 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800007050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_valid_p0)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            if (l_def_valid_p0)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008030301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008030301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008060301143full, l_scom_buffer ));

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_48625)
                 || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_68625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_44500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_64500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_55500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_75500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_51375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_71375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_45875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_65875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_59625)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_79625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61000)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_81000)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_54125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_74125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_56875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_76875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_58250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_78250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_47250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_67250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_43125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_63125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_40375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_60375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_41750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_52750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_72750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x9 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008120301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008120301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008370301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_def_dqs_offset );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008370301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008740301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x60 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x6B );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_DP18[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008740301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008750301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1993)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (l_def_ffe1_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_ffe2_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0011 );
            }
            else if (l_def_ffe3_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_ffe4_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008750301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008760301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008760301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008770301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008770301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008780301143full, l_scom_buffer ));

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008780301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800008790301143full, l_scom_buffer ));

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800008790301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000087a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000087a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000087b0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C6 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000087b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800009040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800009040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800009050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800009050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000a040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000a040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000a050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000a050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000b040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000b040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000b050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000b050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c000301143full, l_scom_buffer ));

            if (l_def_valid_p0)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            if (literal_1)
            {
            }

            if (l_def_valid_p0)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c030301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c030301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c060301143full, l_scom_buffer ));

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_48625)
                 || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_68625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_44500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_64500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_55500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_75500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_51375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_71375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_45875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_65875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_59625)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_79625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61000)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_81000)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_54125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_74125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_56875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_76875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_58250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_78250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_47250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_67250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_43125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_63125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_40375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_60375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_41750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_52750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_72750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x9 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c120301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c120301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c370301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_def_dqs_offset );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c370301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c740301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x60 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x6B );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_DP18[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c740301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c750301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1993)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (l_def_ffe1_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_ffe2_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0011 );
            }
            else if (l_def_ffe3_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_ffe4_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c750301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c760301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c760301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c770301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c770301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c780301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c780301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c790301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c790301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c7a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c7a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000c7b0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C6 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000c7b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000d040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000d040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000d050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000d050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000e040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000e040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000e050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000e050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000f040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000f040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80000f050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80000f050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_valid_p0))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (((l_def_is_mba23 && l_def_valid_p0) && l_def_p0_no_spare))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF00 );
            }
            else if (((l_def_is_mba23 && l_def_valid_p0) && l_def_p0_has_spare_upper))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF0F );
            }
            else if (((l_def_is_mba23 && l_def_valid_p0) && l_def_p0_has_spare_lower))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFF0 );
            }
            else if (((l_def_is_mba23 && l_def_valid_p0) && l_def_p0_has_spare_full))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010030301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010030301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010040301143full, l_scom_buffer ));

            if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_is_x4) && (l_def_p0_has_spare_upper || l_def_p0_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x0000 );
            }

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_is_x4) && (l_def_p0_has_spare_upper || l_def_p0_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8600 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8440 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010060301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_48625)
                 || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_68625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_44500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_64500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_55500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_75500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_51375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_71375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_45875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_65875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_59625)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_79625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61000)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_81000)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_54125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_74125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_56875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_76875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_58250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_78250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_47250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_67250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_43125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_63125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_40375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_60375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_41750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_52750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_72750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x9 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_48625)
                 || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_68625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_44500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_64500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_55500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_75500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_51375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_71375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_45875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_65875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_59625)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_79625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_61000)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_81000)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_54125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_74125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_56875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_76875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_58250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_78250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_47250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_67250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_43125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_63125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_40375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_60375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_41750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_61750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_52750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_0] == literal_72750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x9 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010120301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010120301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010370301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_def_dqs_offset );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010370301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010740301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x60 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x6B );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_DP18[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010740301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010750301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1993)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (l_def_ffe1_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_ffe2_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0011 );
            }
            else if (l_def_ffe3_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_ffe4_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010750301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010760301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010760301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010770301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010770301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010780301143full, l_scom_buffer ));

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010780301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800010790301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            if (l_def_cdi_dqs_ohm24_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p0)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800010790301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000107a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000107a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000107b0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm40_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm48_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C6 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm60_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm80_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm120_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm240_p0))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000107b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800011040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_is_x4) && (l_def_p0_has_spare_upper || l_def_p0_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800011040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800011050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8600 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8440 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800011050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800012040301143full, l_scom_buffer ));

            if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_is_x4) && (l_def_p0_has_spare_upper || l_def_p0_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x0000 );
            }

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_is_x4) && (l_def_p0_has_spare_upper || l_def_p0_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800012040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800012050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8600 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8440 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800012050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800013040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_is_x4) && (l_def_p0_has_spare_upper || l_def_p0_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_is_x4) && (l_def_p0_has_spare_upper || l_def_p0_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800013040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800013050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8600 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8440 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba23 && l_def_p0_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p0_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800013050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800040000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFF0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800040000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800040010301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x18 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x04 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 1, 56, uint64_t>(literal_0x18 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 1, 56, uint64_t>(literal_0x04 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800040010301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800040040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN0[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE1[literal_0] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A3[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN3[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800040040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800040050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE0[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN3[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT0[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_RASN[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800040050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800040060301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A15[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A12[literal_0] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A7[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_PAR[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800040060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800040070301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE1[literal_0] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN1[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800040070301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800040080301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE0[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT0[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800040080301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800040090301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE2[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE2[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800040090301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800040200301143full, l_scom_buffer ));

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800040200301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800040210301143full, l_scom_buffer ));

            if ((l_def_cdi_spcke_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_spcke_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_spcke_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800040210301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000402a0301143full, l_scom_buffer ));

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000402a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000402b0301143full, l_scom_buffer ));

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000402b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800044000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFF0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800044000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800044040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN0[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA2[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE3[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE1[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800044040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800044050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT1[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT1[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A2[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_WEN[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800044050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800044060301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN1[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A6[literal_0] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A11[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A1[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800044060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800044070301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A14[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE3[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE2[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN2[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800044070301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800044080301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN2[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT0[literal_0] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A8[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE2[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800044080301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800044090301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A4[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A5[literal_0] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN0[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_RASN[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800044090301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800044200301143full, l_scom_buffer ));

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_spcke_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_spcke_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_spcke_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_spcke_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800044200301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800044210301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_spcke_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800044210301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000442a0301143full, l_scom_buffer ));

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000442a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000442b0301143full, l_scom_buffer ));

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000442b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800048000301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0xFFFC );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFC );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800048000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800048010301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x04 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x26 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800048010301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800048040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A12[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A1[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A0[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A6[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800048040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800048050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE3[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A13[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN3[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE0[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800048050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800048060301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT0[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN1[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800048060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800048070301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE1[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT1[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN0[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE0[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800048070301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800048080301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN1[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A0[literal_0] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA1[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A10[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800048080301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800048090301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800048090301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000480a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN2[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A10[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000480a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800048200301143full, l_scom_buffer ));

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_spcke_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800048200301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800048210301143full, l_scom_buffer ));

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800048210301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000482a0301143full, l_scom_buffer ));

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000482a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000482b0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000482b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFC );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0xFFFC );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c010301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c010301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A13[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_PAR[literal_0] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT1[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA0[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_WEN[literal_0] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN2[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c060301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A14[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA1[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_CASN[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A9[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c070301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A5[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_ACTN[literal_0] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A2[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A3[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c070301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c080301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE3[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA2[literal_0] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A15[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A11[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c080301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c090301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A7[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA0[literal_0] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_ACTN[literal_0] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_CASN[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c090301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c0a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A4[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A9[literal_0] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN3[literal_0] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A8[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c0a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c200301143full, l_scom_buffer ));

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c200301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c210301143full, l_scom_buffer ));

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_spcke_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_spcke_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p0 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c210301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c2a0301143full, l_scom_buffer ));

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c2a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80004c2b0301143full, l_scom_buffer ));

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80004c2b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800080300301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800080300301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800080310301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800080310301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800080320301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0b0000010 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800080320301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800080330301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x60 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x70 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_ADR[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800080330301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800080350301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800080350301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800084300301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800084300301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800084310301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800084310301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800084320301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0b0000010 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800084320301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800084330301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x60 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x70 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_ADR[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800084330301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800084350301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800084350301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0020301143full, l_scom_buffer ));

            if (l_def_val_srg1_p0)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }
            else if (l_def_val_prg0_p0)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0[literal_0] );
            }

            if (l_def_val_srg0_p0)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP0[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
            }

            if (l_def_val_prg0_p0)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_prg0_p0)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_srg0_p0)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP0[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_srg0_p0)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg1_p0)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP1[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_prg1_p0)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_srg1_p0)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP1[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_srg1_p0)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_srg1_p0)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP1[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0020301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0030301143full, l_scom_buffer ));

            if (l_def_val_prg3_p0)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
            }

            if (l_def_val_prg2_p0)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP2[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_prg2_p0)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_srg2_p0)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP2[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_srg2_p0)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg3_p0)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP3[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_prg3_p0)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_srg3_p0)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP3[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_srg3_p0)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_srg2_p0)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_srg3_p0)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg2_p0)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg3_p0)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP3[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_srg3_p0)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP3[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0030301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 15, 49, uint64_t>(literal_0x0001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0080301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_FAST_SIM_PC == literal_1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(((l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL / literal_765) + literal_1) );
            }
            else if ((l_def_FAST_SIM_PC == literal_0))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(((l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL / literal_196605) + literal_1) );
            }

            if ((l_def_FAST_SIM_PC == literal_1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(((l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL / literal_765) + literal_1) );
            }
            else if ((l_def_FAST_SIM_PC == literal_0))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(((l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL / literal_196605) + literal_1) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0080301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0090301143full, l_scom_buffer ));

            if ((l_def_FAST_SIM_PC == literal_1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(((l_TGT0_ATTR_CEN_EFF_ZQCAL_INTERVAL / literal_765) + literal_1) );
            }
            else if ((l_def_FAST_SIM_PC == literal_0))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(((l_TGT0_ATTR_CEN_EFF_ZQCAL_INTERVAL / literal_196605) + literal_1) );
            }

            if (literal_1)
            {
            }

            if ((l_def_FAST_SIM_PC == literal_1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(((l_TGT0_ATTR_CEN_EFF_ZQCAL_INTERVAL / literal_765) + literal_1) );
            }
            else if ((l_def_FAST_SIM_PC == literal_0))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(((l_TGT0_ATTR_CEN_EFF_ZQCAL_INTERVAL / literal_196605) + literal_1) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0090301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00b0301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
            }

            if (l_def_val_prg0_p0)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg1_p0)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg2_p0)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }
            else if (l_def_val_prg3_p0)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b00 );
            }

            if ((l_def_FAST_SIM_PC == literal_0))
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_FAST_SIM_PC == literal_1))
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b1 );
            }

            if ((l_def_FAST_SIM_PC == literal_0))
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_FAST_SIM_PC == literal_1))
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg0_p0)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg1_p0)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg2_p0)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg3_p0)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00c0301143full, l_scom_buffer ));

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_not_ddr4)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (l_def_not_ddr4)
            {
            }
            else if (l_def_is_ddr4)
            {
            }

            if (l_def_not_ddr4)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }
            else if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_not_ddr4)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_not_ddr4)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b0 );
            }
            else if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00c0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00d0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(l_TGT0_ATTR_CEN_VPD_WLO[literal_0] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(l_TGT0_ATTR_CEN_VPD_RLO[literal_0] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_custom)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }
            else if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_lrdimm)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_def_is_lrdimm || l_def_is_rdimm))
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00d0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00e0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00e0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c00f0301143full, l_scom_buffer ));

            if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >= literal_4))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] == literal_2))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_1] == literal_4)
                 || (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] > literal_4)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_1] == literal_2))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1100 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_1] == literal_1))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
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
            }

            if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] >= literal_4))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] == literal_2))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_1] == literal_4)
                 || (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_0] > literal_4)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_1] == literal_2))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1100 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_0][literal_1] == literal_1))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c00f0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0150301143full, l_scom_buffer ));

            if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_540)
                 || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_455)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_510)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_485)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_565)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_430)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_505)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_490)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_560)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_435)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_535)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_460)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_575)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_420)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_525)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_470)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_515)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_480)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_555)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_440)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_520)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_475)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_550)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_445)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_500)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_495)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_570)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_425)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_530)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_465)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_545)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_450)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x9 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_540)
                 || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_455)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_510)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_485)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_565)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_430)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_505)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_490)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_560)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_435)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_535)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_460)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_575)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_420)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_525)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_470)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_515)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_480)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_555)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_440)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_520)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_475)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_550)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_445)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_500)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_495)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_570)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_425)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_530)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_465)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_545)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_450)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x9 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0b0000 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] >= literal_500))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] < literal_500))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] >= literal_500))
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] < literal_500))
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_540)
                 || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_455)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_510)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_485)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_565)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_430)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_505)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_490)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_560)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_435)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_535)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_460)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_575)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_420)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_525)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_470)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_515)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_480)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_555)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_440)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_520)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_475)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_550)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_445)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_500)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_495)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_570)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_425)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_530)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_465)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_545)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_450)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x9 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0b0000 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] >= literal_500))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] < literal_500))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_540)
                 || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_455)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_510)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_485)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_565)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_430)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_505)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_490)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_560)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_435)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_535)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_460)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_575)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_420)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_525)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_470)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_515)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_480)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_555)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_440)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_520)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_475)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_550)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_445)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_500)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_495)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_570)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_425)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_530)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_465)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_545)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_0] == literal_450)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x9 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0150301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0160301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
            }

            if (l_def_val_prg0_p0)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg1_p0)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg2_p0)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg3_p0)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0160301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0170301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 7, 57, uint64_t>((l_TGT0_ATTR_CEN_EFF_DRAM_TRFI >> literal_8) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0170301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0300301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_val_trg0_p0)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP0[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg0_p0)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg0_p0)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_qrg0_p0)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_trg1_p0)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP1[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg1_p0)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg1_p0)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_qrg1_p0)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg1_p0)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_qrg0_p0)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg1_p0)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_trg0_p0)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_trg1_p0)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_trg0_p0)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP0[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_qrg0_p0)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg1_p0)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP1[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0300301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0310301143full, l_scom_buffer ));

            if (l_def_val_trg2_p0)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg2_p0)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg3_p0)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg3_p0)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
            }

            if (l_def_val_trg2_p0)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP2[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg2_p0)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg2_p0)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_qrg2_p0)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_trg3_p0)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP3[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg3_p0)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg3_p0)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_qrg3_p0)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg2_p0)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg3_p0)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg3_p0)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP3[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg2_p0)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP2[literal_0] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0310301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c0330301143full, l_scom_buffer ));

            if (l_def_is_tsv_ddr4_p0)
            {
                l_scom_buffer.insert<48, 1, 56, uint64_t>(literal_0x00 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 56, uint64_t>(literal_0xff );
            }

            if (literal_1)
            {
            }

            if (l_def_is_tsv_ddr4_p0)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x00 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0xff );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c0330301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c4000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x5555 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c4000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c4010301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x5555 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c4010301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c4020301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_2N_mode)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<50, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (l_def_not_ddr4)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_2N_mode)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (l_def_not_ddr4)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c4020301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c40a0301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_0][literal_0] );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_0][literal_0] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_0][literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c40a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c40b0301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_0][literal_2] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_0][literal_3] );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_0][literal_2] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_0][literal_3] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c40b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c40c0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_1][literal_0] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_1][literal_1] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_1][literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c40c0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c40d0301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_1][literal_3] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_1][literal_2] );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_1][literal_2] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_0][literal_1][literal_3] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c40d0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c40e0301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_0][literal_0][literal_0] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_0][literal_0][literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c40e0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c40f0301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_0][literal_0][literal_2] );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_0][literal_0][literal_2] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_0][literal_0][literal_3] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_0][literal_0][literal_3] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c40f0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c4100301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_0][literal_1][literal_1] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_0][literal_1][literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c4100301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c4110301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_0][literal_1][literal_2] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_0][literal_1][literal_3] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_0][literal_1][literal_2] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c4110301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c4120301143full, l_scom_buffer ));

            if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRFC <= literal_256) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRFC > literal_128)))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRFC <= literal_128) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRFC > literal_64)))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRFC <= literal_64) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRFC > literal_32)))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x6 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRFC > literal_256))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x9 );
            }

            if (literal_1)
            {
            }

            if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_2133) && l_def_is_ddr3))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_2133) && l_def_is_ddr3))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ < literal_3200) && l_def_is_ddr4))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRCD <= literal_8))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRCD > literal_8) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD <= literal_16)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRCD > literal_16))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x5 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRP < literal_8))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRP > literal_8) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP <= literal_16)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRP > literal_16))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRFC <= literal_256) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRFC > literal_128)))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRFC <= literal_128) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRFC > literal_64)))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRFC <= literal_64) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRFC > literal_32)))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x6 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRFC > literal_256))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x9 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRP < literal_8))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRP > literal_8) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP <= literal_16)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRP > literal_16))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c4120301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c4130301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr4 || (l_TGT2_ATTR_CEN_MSS_FREQ > literal_1600)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0xA );
            }
            else if ((l_def_is_ddr3 && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1600)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x9 );
            }

            if ((l_def_is_ddr4 || (l_TGT2_ATTR_CEN_MSS_FREQ > literal_1600)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0xA );
            }
            else if ((l_def_is_ddr3 && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1600)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x6 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x6 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x6 );
            }

            if ((l_def_is_ddr4 || (l_TGT2_ATTR_CEN_MSS_FREQ > literal_1600)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0xA );
            }
            else if ((l_def_is_ddr3 && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1600)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x9 );
            }

            if ((l_def_is_ddr4 || (l_TGT2_ATTR_CEN_MSS_FREQ > literal_1600)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0xA );
            }
            else if ((l_def_is_ddr3 && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1600)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x6 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c4130301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c4140301143full, l_scom_buffer ));

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_8))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_64) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_128)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_8) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_16)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_32) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_64)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_16) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_32)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x5 );
            }

            if (((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_16))
                      && (l_def_tODTL_DDR4_NOAL > literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_64))
                      && (l_def_tODTL_DDR4_NOAL > literal_32)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x6 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_32))
                      && (l_def_tODTL_DDR4_NOAL > literal_16)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }

            if (literal_1)
            {
            }

            if (((l_def_is_ddr3 && l_def_AL_ena) && (l_def_tODTL_DDR3 <= literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_is_ddr3 && l_def_AL_ena) && (l_def_tODTL_DDR3 <= literal_16)) && (l_def_tODTL_DDR3 > literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((((l_def_is_ddr3 && l_def_AL_ena) && (l_def_tODTL_DDR3 <= literal_32)) && (l_def_tODTL_DDR3 > literal_16)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_is_ddr3 && l_def_AL_ena) && (l_def_tODTL_DDR3 <= literal_64)) && (l_def_tODTL_DDR3 > literal_32)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_def_is_ddr3 && l_def_AL_dis) && (l_def_tODTL_DDR3_NOAL <= literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_is_ddr3 && l_def_AL_dis) && (l_def_tODTL_DDR3_NOAL <= literal_16))
                      && (l_def_tODTL_DDR3_NOAL > literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((((l_def_is_ddr3 && l_def_AL_dis) && (l_def_tODTL_DDR3_NOAL <= literal_32))
                      && (l_def_tODTL_DDR3_NOAL > literal_16)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_is_ddr3 && l_def_AL_dis) && (l_def_tODTL_DDR3_NOAL <= literal_64))
                      && (l_def_tODTL_DDR3_NOAL > literal_32)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_def_is_ddr4 && l_def_AL_ena) && (l_def_tODTL_DDR4 <= literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_ena) && (l_def_tODTL_DDR4 <= literal_16)) && (l_def_tODTL_DDR4 > literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_ena) && (l_def_tODTL_DDR4 <= literal_32)) && (l_def_tODTL_DDR4 > literal_16)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_ena) && (l_def_tODTL_DDR4 <= literal_64)) && (l_def_tODTL_DDR4 > literal_32)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_16))
                      && (l_def_tODTL_DDR4_NOAL > literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_32))
                      && (l_def_tODTL_DDR4_NOAL > literal_16)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_64))
                      && (l_def_tODTL_DDR4_NOAL > literal_32)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_64) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_128)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_32) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_64)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_16) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_32)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_8) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_16)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_8))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x3 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c4140301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(l_TGT0_ATTR_CEN_VPD_GPO[literal_0] );
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
                l_scom_buffer.insert<54, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8010301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 50, uint64_t>(literal_0b00000000000000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 50, uint64_t>(literal_0b00000000000000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8010301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8020301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_bl8)
            {
                l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_bl8)
            {
                l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8020301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000c8070301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<51, 4, 60, uint64_t>(literal_0b1010 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<51, 4, 60, uint64_t>(literal_0b1010 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000c8070301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000cc000301143full, l_scom_buffer ));

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1B );
            }

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1B );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b1 );
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<57, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<57, 6, 58, uint64_t>(literal_0b100000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000cc000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000cc010301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b101010 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000cc010301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8000cc020301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }

            if ((l_def_AL_ena && (l_def_TWTR_PLUS_OFF >= l_def_TRTP_PLUS_AL)))
            {
                l_scom_buffer.insert<52, 6, 58, uint64_t>(l_def_TWTR_PLUS_OFF );
            }
            else if ((l_def_AL_ena && (l_def_TWTR_PLUS_OFF < l_def_TRTP_PLUS_AL)))
            {
                l_scom_buffer.insert<52, 6, 58, uint64_t>(l_def_TRTP_PLUS_AL );
            }
            else if ((l_def_AL_dis && (l_def_TWTR_PLUS_OFF >= l_def_TRTP_PLUS_NOAL)))
            {
                l_scom_buffer.insert<52, 6, 58, uint64_t>(l_def_TWTR_PLUS_OFF );
            }
            else if ((l_def_AL_dis && (l_def_TWTR_PLUS_OFF < l_def_TRTP_PLUS_NOAL)))
            {
                l_scom_buffer.insert<52, 6, 58, uint64_t>(l_def_TRTP_PLUS_NOAL );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8000cc020301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800100000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_valid_p1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            if (l_def_valid_p1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800100000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800100030301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800100030301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800100040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800100040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800100050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4A40 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800100050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800100060301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_48625)
                 || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_68625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_44500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_64500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_55500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_75500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_51375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_71375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_45875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_65875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_59625)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_79625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61000)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_81000)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_54125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_74125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_56875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_76875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_58250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_78250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_47250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_67250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_43125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_63125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_40375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_60375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_41750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_52750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_72750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x9 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800100060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800100120301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800100120301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800100370301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_def_dqs_offset );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800100370301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800100740301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x60 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x6B );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_DP18[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800100740301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800100750301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1993)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (l_def_ffe1_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_ffe2_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0011 );
            }
            else if (l_def_ffe3_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_ffe4_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800100750301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800100760301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800100760301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800100770301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800100770301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800100780301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800100780301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800100790301143full, l_scom_buffer ));

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800100790301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001007a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001007a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001007b0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C6 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001007b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800101040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800101040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800101050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800101050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800102040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800102040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800102050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800102050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800103040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800103040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800103050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800103050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800104000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba23 && l_def_valid_p1) && l_def_p1_no_spare))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF00 );
            }
            else if (((l_def_is_mba23 && l_def_valid_p1) && l_def_p1_has_spare_upper))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF0F );
            }
            else if (((l_def_is_mba23 && l_def_valid_p1) && l_def_p1_has_spare_lower))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFF0 );
            }
            else if (((l_def_is_mba23 && l_def_valid_p1) && l_def_p1_has_spare_full))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            if ((l_def_is_mba01 && l_def_valid_p1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (((l_def_is_mba23 && l_def_valid_p1) && l_def_p1_no_spare))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF00 );
            }
            else if (((l_def_is_mba23 && l_def_valid_p1) && l_def_p1_has_spare_upper))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF0F );
            }
            else if (((l_def_is_mba23 && l_def_valid_p1) && l_def_p1_has_spare_lower))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFF0 );
            }
            else if (((l_def_is_mba23 && l_def_valid_p1) && l_def_p1_has_spare_full))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800104000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800104030301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800104030301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800104040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC000 );
            }
            else if (((l_def_is_mba23 && l_def_is_x4) && (l_def_p1_has_spare_upper || l_def_p1_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x4) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800104040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800104050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_is_x4) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8440 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8600 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC000 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800104050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800104060301143full, l_scom_buffer ));

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800104060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800104120301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800104120301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800104370301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_def_dqs_offset );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800104370301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800104740301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x60 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x6B );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_DP18[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800104740301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800104750301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1993)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (l_def_ffe1_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_ffe2_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0011 );
            }
            else if (l_def_ffe3_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_ffe4_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800104750301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800104760301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800104760301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800104770301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800104770301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800104780301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800104780301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800104790301143full, l_scom_buffer ));

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800104790301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001047a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001047a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001047b0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C6 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001047b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800105040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_is_x4) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (((l_def_is_mba23 && l_def_is_x4) && (l_def_p1_has_spare_upper || l_def_p1_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800105040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800105050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_is_x4) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8440 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8600 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC000 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800105050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800106040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_is_x4) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (((l_def_is_mba23 && l_def_is_x4) && (l_def_p1_has_spare_upper || l_def_p1_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800106040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800106050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_is_x4) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8440 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8600 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800106050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800107040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_is_x4) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC000 );
            }
            else if (((l_def_is_mba23 && l_def_is_x4) && (l_def_p1_has_spare_upper || l_def_p1_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800107040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800107050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_is_x4) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8440 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8600 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC000 );
            }
            else if (((l_def_is_mba23 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (((l_def_is_mba23 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800107050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800108000301143full, l_scom_buffer ));

            if (((l_def_is_mba01 && l_def_valid_p1) && l_def_p1_has_spare_full))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (((l_def_is_mba01 && l_def_valid_p1) && l_def_p1_no_spare))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF00 );
            }
            else if (((l_def_is_mba01 && l_def_valid_p1) && l_def_p1_has_spare_lower))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF0F );
            }
            else if (((l_def_is_mba01 && l_def_valid_p1) && l_def_p1_has_spare_upper))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFF0 );
            }
            else if ((l_def_is_mba23 && l_def_valid_p1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_valid_p1) && l_def_p1_has_spare_full))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (((l_def_is_mba01 && l_def_valid_p1) && l_def_p1_no_spare))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF00 );
            }
            else if (((l_def_is_mba01 && l_def_valid_p1) && l_def_p1_has_spare_lower))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFF0F );
            }
            else if (((l_def_is_mba01 && l_def_valid_p1) && l_def_p1_has_spare_upper))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFF0 );
            }
            else if ((l_def_is_mba23 && l_def_valid_p1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800108000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800108030301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800108030301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800108040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba01 && l_def_is_x4) && (l_def_p1_has_spare_upper || l_def_p1_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800108040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800108050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_p1_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8600 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8440 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0C00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800108050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800108060301143full, l_scom_buffer ));

            if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_48625)
                 || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_68625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_44500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_64500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_55500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_75500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_51375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_71375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_45875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_65875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_59625)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_79625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61000)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_81000)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_54125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_74125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_56875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_76875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_58250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_78250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_47250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_67250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_43125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_63125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_40375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_60375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_41750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_52750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_72750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x9 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_48625)
                 || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_68625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_44500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_64500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_55500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_75500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_51375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_71375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_45875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_65875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_59625)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_79625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61000)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_81000)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_54125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_74125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_56875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_76875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_58250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_78250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_47250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_67250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_43125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_63125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_40375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_60375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_41750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_52750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_72750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x9 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800108060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800108120301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800108120301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800108370301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_def_dqs_offset );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800108370301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800108740301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x60 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x6B );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_DP18[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800108740301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800108750301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1993)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (l_def_ffe1_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_ffe2_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0011 );
            }
            else if (l_def_ffe3_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_ffe4_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800108750301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800108760301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800108760301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800108770301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800108770301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800108780301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800108780301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800108790301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800108790301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001087a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001087a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001087b0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C6 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001087b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800109040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba01 && l_def_is_x4) && (l_def_p1_has_spare_upper || l_def_p1_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800109040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800109050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8600 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8440 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800109050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010a040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (((l_def_is_mba01 && l_def_is_x4) && (l_def_p1_has_spare_upper || l_def_p1_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0C00 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010a040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010a050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8600 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8440 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010a050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010b040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba01 && l_def_is_x4) && (l_def_p1_has_spare_upper || l_def_p1_has_spare_lower)))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010b040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010b050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0F00 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0C00 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_upper) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8600 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_lower) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8440 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_full) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if (((l_def_is_mba01 && l_def_p1_has_spare_full) && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (((l_def_is_mba01 && l_def_p1_no_spare) && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8400 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010b050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c000301143full, l_scom_buffer ));

            if (l_def_valid_p1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            if (literal_1)
            {
            }

            if (l_def_valid_p1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c030301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c030301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x4A40 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c060301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_48625)
                 || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_68625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_44500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_64500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_55500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_75500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_51375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_71375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_45875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_65875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_59625)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_79625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61000)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_81000)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_54125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_74125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_56875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_76875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_58250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_78250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_47250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_67250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_43125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_63125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_40375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_60375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_41750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_52750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_72750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x9 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c120301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c120301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c370301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_def_dqs_offset );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c370301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c740301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x60 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x6B );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_DP18[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c740301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c750301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1993)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (l_def_ffe1_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_ffe2_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0011 );
            }
            else if (l_def_ffe3_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_ffe4_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c750301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c760301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c760301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c770301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c770301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c780301143full, l_scom_buffer ));

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c780301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c790301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c790301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c7a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c7a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010c7b0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C6 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010c7b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010d040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x4A40 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010d040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010d050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4A40 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010d050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010e040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010e040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010e050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4A40 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010e050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010f040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x4A40 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010f040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80010f050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x4A40 );
            }
            else if (((l_def_is_mba01 && l_def_is_x8) && l_def_is_type1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC0C0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80010f050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800110000301143full, l_scom_buffer ));

            if (l_def_valid_p1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            if (literal_1)
            {
            }

            if (l_def_valid_p1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800110000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800110030301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800110030301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800110040301143full, l_scom_buffer ));

            if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x0000 );
            }

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800110040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800110050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800110050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800110060301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_48625)
                 || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_68625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_44500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_64500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_55500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_75500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_51375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_71375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_45875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_65875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_59625)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_79625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61000)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_81000)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_54125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_74125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_56875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_76875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_58250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_78250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_47250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_67250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_43125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_63125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_40375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_60375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_41750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_52750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_72750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x9 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_48625)
                 || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_68625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_44500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_64500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_55500)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_75500)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_51375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_71375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_45875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_65875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_59625)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_79625)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61000)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_81000)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_54125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_74125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_56875)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_76875)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_58250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_78250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_47250)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_67250)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_43125)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_63125)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_40375)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_60375)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_41750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_61750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_52750)
                      || (l_TGT0_ATTR_CEN_EFF_RD_VREF[literal_1] == literal_72750)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x9 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800110060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800110120301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800110120301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800110370301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_def_dqs_offset );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800110370301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800110740301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x60 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0x6B );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_DP18[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800110740301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800110750301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1993)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (l_def_ffe1_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_ffe2_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0011 );
            }
            else if (l_def_ffe3_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0111 );
            }
            else if (l_def_ffe4_p0)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800110750301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800110760301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800110760301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800110770301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800110770301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800110780301143full, l_scom_buffer ));

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 52, uint64_t>(literal_0x000 );
            }

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800110780301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800110790301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_cdi_dqs_ohm24_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFFF );
            }
            else if (l_def_cdi_dqs_ohm30_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7EF );
            }
            else if (l_def_cdi_dqs_ohm34_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3EF );
            }
            else if (l_def_cdi_dqs_ohm40_p1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3CF );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800110790301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001107a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001107a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001107b0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_ddr3 && l_def_cri_dqs_ohm15_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0xFF0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm20_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm30_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x182 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x102 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm160_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x007 );
            }
            else if ((l_def_is_ddr3 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x003 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm40_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x7E0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm48_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C6 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm60_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x3C0 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm80_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x186 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm120_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x180 );
            }
            else if ((l_def_is_ddr4 && l_def_cri_dqs_ohm240_p1))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x100 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001107b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800111040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800111040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800111050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800111050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800112040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800112040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800112050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800112050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800113040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 48, uint64_t>(literal_0x0000 );
            }

            if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x0CC0 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0xC300 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800113040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800113050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_is_mba01 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8580 );
            }
            else if ((l_def_is_mba01 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xC300 );
            }
            else if ((l_def_is_mba23 && l_def_is_x4))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x8640 );
            }
            else if ((l_def_is_mba23 && l_def_is_x8))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0CC0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800113050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800140000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFF0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0xFFF0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800140000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800140010301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0xC0 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x04 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800140010301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800140040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE1[literal_1] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA2[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800140040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800140050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A1[literal_1] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A5[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800140050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800140060301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A12[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE3[literal_1] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA0[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN3[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800140060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800140070301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA0[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE2[literal_1] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN1[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT1[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800140070301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800140080301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE0[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE3[literal_1] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN2[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A15[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800140080301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800140090301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN2[literal_1] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE1[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800140090301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800140200301143full, l_scom_buffer ));

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_spcke_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_spcke_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_spcke_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800140200301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800140210301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_cdi_spcke_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800140210301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001402a0301143full, l_scom_buffer ));

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001402a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001402b0301143full, l_scom_buffer ));

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001402b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800144000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFF0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0xFFF0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800144000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800144040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE2[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A8[literal_1] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A7[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A13[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800144040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800144050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT1[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A10[literal_1] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_PAR[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE1[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800144050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800144060301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN1[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN0[literal_1] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A8[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A11[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800144060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800144070301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE1[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A6[literal_1] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_WEN[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN3[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800144070301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800144080301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A4[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE3[literal_1] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN1[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT0[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800144080301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800144090301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_RASN[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A1[literal_1] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN1[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA1[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800144090301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800144200301143full, l_scom_buffer ));

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_spcke_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800144200301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800144210301143full, l_scom_buffer ));

            if ((l_def_cdi_spcke_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_spcke_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800144210301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001442a0301143full, l_scom_buffer ));

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001442a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001442b0301143full, l_scom_buffer ));

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001442b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800148000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFC );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0xFFFC );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800148000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800148010301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x08 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x06 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800148010301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800148040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN0[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN2[literal_1] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A10[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT0[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800148040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800148050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_WEN[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A4[literal_1] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN3[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A2[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800148050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800148060301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT1[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_ACTN[literal_1] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN0[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A9[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800148060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800148070301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A3[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE3[literal_1] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE0[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A0[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800148070301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800148080301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN3[literal_1] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A2[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800148080301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800148090301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_CASN[literal_1] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN0[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800148090301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001480a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE0[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1[literal_1] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A12[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001480a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800148200301143full, l_scom_buffer ));

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_spcke_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_spcke_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800148200301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800148210301143full, l_scom_buffer ));

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800148210301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001482a0301143full, l_scom_buffer ));

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001482a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001482b0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001482b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80014c000301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 12, 48, uint64_t>(literal_0xFFFC );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0xFFFC );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80014c000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80014c010301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x40 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 1, 56, uint64_t>(literal_0x40 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80014c010301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80014c040301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN2[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A11[literal_1] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE0[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT0[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80014c040301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80014c050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0[literal_1] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80014c050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80014c060301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A13[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A6[literal_1] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A14[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT1[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80014c060301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80014c070301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE2[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A0[literal_1] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT0[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_CASN[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80014c070301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80014c080301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A9[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A14[literal_1] );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA2[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A3[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80014c080301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80014c090301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_RASN[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A7[literal_1] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A15[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_ACTN[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80014c090301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80014c0a0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_A5[literal_1] );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA1[literal_1] );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE2[literal_1] );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_PHASE_ROT_M_PAR[literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80014c0a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80014c200301143full, l_scom_buffer ));

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_clk_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_clk_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_clk_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_clk_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_spcke_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_ctl_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_ctl_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_ctl_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_ctl_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80014c200301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80014c210301143full, l_scom_buffer ));

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba01))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }
            else if ((l_def_cdi_spcke_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_addr_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_addr_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_addr_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_addr_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b11 );
            }

            if ((l_def_cdi_spcke_ohm15_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if ((l_def_cdi_spcke_ohm30_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b10 );
            }
            else if ((l_def_cdi_spcke_ohm20_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }
            else if ((l_def_cdi_spcke_ohm40_p1 && l_def_is_mba23))
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80014c210301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80014c2a0301143full, l_scom_buffer ));

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b01 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<60, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b01 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b10 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80014c2a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x80014c2b0301143full, l_scom_buffer ));

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<56, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<50, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba01)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b00 );
            }
            else if (l_def_is_mba23)
            {
                l_scom_buffer.insert<58, 2, 62, uint64_t>(literal_0b11 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<48, 2, 62, uint64_t>(literal_0b00 );
            }

            if (l_def_is_mba23)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x80014c2b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800180300301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800180300301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800180310301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800180310301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800180320301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0b0000010 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800180320301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800180330301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x60 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x70 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_ADR[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800180330301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800180350301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800180350301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800184300301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1200))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ < literal_1460))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1459))
            {
                l_scom_buffer.insert<48, 12, 52, uint64_t>(literal_0x689 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1400))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800184300301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800184310301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<51, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_VOLT <= literal_1271))
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b11 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b10 );
            }

            if ((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1200))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1200) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1460)))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b0100 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1460) && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1732)))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b0010 );
            }
            else if ((l_TGT2_ATTR_CEN_MSS_FREQ > literal_1732))
            {
                l_scom_buffer.insert<59, 4, 60, uint64_t>(literal_0b1100 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800184310301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800184320301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 7, 57, uint64_t>(literal_0b0000010 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 2, 62, uint64_t>(literal_0b00 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800184320301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800184330301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x60 );
            }
            else if (l_def_old_cdimm)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x70 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_TSYS_ADR[literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800184330301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800184350301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800184350301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c0020301143full, l_scom_buffer ));

            if (l_def_val_prg1_p1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP1[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_prg0_p1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg0_p1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_srg1_p1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP1[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
            }

            if (l_def_val_prg0_p1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP0[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_prg0_p1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_srg0_p1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP0[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_srg0_p1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg1_p1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP1[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_prg1_p1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_srg1_p1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP1[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_srg1_p1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_srg1_p1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg1_p1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c0020301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c0030301143full, l_scom_buffer ));

            if (l_def_val_srg2_p1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP2[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_prg2_p1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP2[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
            }

            if (l_def_val_prg2_p1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP2[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_prg2_p1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_srg2_p1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP2[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_srg2_p1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg3_p1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP3[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_prg3_p1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_srg3_p1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP3[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_srg3_p1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_srg3_p1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_SECONDARY_RANK_GROUP3[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_prg3_p1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_PRIMARY_RANK_GROUP3[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_srg2_p1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg3_p1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c0030301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c0050301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 15, 49, uint64_t>(literal_0x0001 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c0050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c0080301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_def_FAST_SIM_PC == literal_1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(((l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL / literal_765) + literal_1) );
            }
            else if ((l_def_FAST_SIM_PC == literal_0))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(((l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL / literal_196605) + literal_1) );
            }

            if ((l_def_FAST_SIM_PC == literal_1))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(((l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL / literal_765) + literal_1) );
            }
            else if ((l_def_FAST_SIM_PC == literal_0))
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(((l_TGT0_ATTR_CEN_EFF_MEMCAL_INTERVAL / literal_196605) + literal_1) );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c0080301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c00b0301143full, l_scom_buffer ));

            if ((l_def_FAST_SIM_PC == literal_0))
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_FAST_SIM_PC == literal_1))
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
            }

            if (l_def_val_prg0_p1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg1_p1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg2_p1)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg3_p1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b00 );
            }

            if ((l_def_FAST_SIM_PC == literal_0))
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_def_FAST_SIM_PC == literal_1))
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c00b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c00c0301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_ddr4)
            {
            }
            else if (l_def_not_ddr4)
            {
            }

            if (l_def_not_ddr4)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b0 );
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b0 );
            }
            else if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<50, 1, 63, uint64_t>(literal_0b1 );
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0001 );
            }
            else if (l_def_not_ddr4)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_not_ddr4)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b0 );
            }
            else if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_not_ddr4)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }
            else if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c00c0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c00d0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(l_TGT0_ATTR_CEN_VPD_WLO[literal_1] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(l_TGT0_ATTR_CEN_VPD_RLO[literal_1] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_custom)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }
            else if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_lrdimm)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if ((l_def_is_lrdimm || l_def_is_rdimm))
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c00d0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c00e0301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c00e0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c00f0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_1][literal_0] >= literal_4))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_1][literal_0] == literal_2))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_1][literal_0] == literal_1))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_1][literal_1] == literal_4)
                 || (l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_1][literal_0] > literal_4)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1111 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_1][literal_1] == literal_2))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1100 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_NUM_RANKS_PER_DIMM[literal_1][literal_1] == literal_1))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b1000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0b0000 );
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
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c00f0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c0150301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] >= literal_500))
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] < literal_500))
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_540)
                 || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_455)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_510)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_485)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_565)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_430)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_505)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_490)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_560)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_435)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_535)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_460)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_575)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_420)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_525)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_470)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_515)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_480)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_555)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_440)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_520)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_475)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_550)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_445)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_500)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_495)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_570)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_425)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_530)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_465)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_545)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_450)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x9 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0b0000 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] >= literal_500))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] < literal_500))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_540)
                 || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_455)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_510)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_485)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_565)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_430)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_505)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_490)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_560)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_435)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_535)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_460)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_575)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_420)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_525)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_470)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_515)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_480)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_555)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_440)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_520)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_475)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_550)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_445)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_500)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_495)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_570)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_425)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_530)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_465)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_545)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_450)))
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0x9 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<54, 4, 60, uint64_t>(literal_0b0000 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] >= literal_500))
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] < literal_500))
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b1 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_540)
                 || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_455)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x1 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_510)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_485)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_565)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_430)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xB );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_505)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_490)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_560)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_435)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_535)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_460)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xE );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_575)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_420)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xF );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_525)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_470)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xA );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_515)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_480)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xC );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_555)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_440)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0xD );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_520)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_475)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x2 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_550)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_445)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_500)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_495)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x0 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_570)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_425)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_530)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_465)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_545)
                      || (l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] == literal_450)))
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0x9 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 4, 60, uint64_t>(literal_0b0000 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] >= literal_500))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b0 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_WR_VREF[literal_1] < literal_500))
            {
                l_scom_buffer.insert<53, 1, 63, uint64_t>(literal_0b1 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c0150301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c0160301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg0_p1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg1_p1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg2_p1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_prg3_p1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c0160301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c0170301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 7, 57, uint64_t>((l_TGT0_ATTR_CEN_EFF_DRAM_TRFI >> literal_8) );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c0170301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c0300301143full, l_scom_buffer ));

            if (l_def_val_trg0_p1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_trg0_p1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP0[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
            }

            if (l_def_val_trg0_p1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP0[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg0_p1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg0_p1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_qrg0_p1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_trg1_p1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP1[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg1_p1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg1_p1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP1[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_qrg1_p1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg0_p1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP0[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg1_p1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP1[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg1_p1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg1_p1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c0300301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c0310301143full, l_scom_buffer ));

            if (l_def_val_trg2_p1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg3_p1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
            }

            if (l_def_val_trg2_p1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP2[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg2_p1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg2_p1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP2[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_qrg2_p1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_trg3_p1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP3[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_trg3_p1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_qrg3_p1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_QUATERNARY_RANK_GROUP3[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<60, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_val_qrg3_p1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_val_trg3_p1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(l_TGT0_ATTR_CEN_EFF_TERTIARY_RANK_GROUP3[literal_1] );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<56, 3, 61, uint64_t>(literal_0b000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c0310301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c0330301143full, l_scom_buffer ));

            if (l_def_is_tsv_ddr4_p1)
            {
                l_scom_buffer.insert<48, 1, 56, uint64_t>(literal_0x00 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 56, uint64_t>(literal_0xff );
            }

            if (literal_1)
            {
            }

            if (l_def_is_tsv_ddr4_p1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x00 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0xff );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c0330301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c4000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x5555 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 16, 48, uint64_t>(literal_0x5555 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c4000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c4020301143full, l_scom_buffer ));

            if (l_def_is_ddr4)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (l_def_not_ddr4)
            {
                l_scom_buffer.insert<54, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<50, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_2N_mode)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b1 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<49, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c4020301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c40a0301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_0][literal_0] );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_0][literal_0] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_0][literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c40a0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c40b0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_0][literal_2] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_0][literal_3] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_0][literal_3] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c40b0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c40c0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_1][literal_0] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_1][literal_1] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_1][literal_1] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_1][literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c40c0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c40d0301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_1][literal_2] );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_1][literal_2] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_1][literal_3] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_WR[literal_1][literal_1][literal_3] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c40d0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c40e0301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_0][literal_0] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_0][literal_1] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_0][literal_1] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_0][literal_0] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c40e0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c40f0301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_0][literal_2] );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_0][literal_2] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_0][literal_3] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_0][literal_3] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c40f0301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c4100301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_1][literal_0] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_1][literal_1] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_1][literal_0] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_1][literal_1] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c4100301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c4110301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_1][literal_2] );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 8, 56, uint64_t>(l_TGT0_ATTR_CEN_VPD_ODT_RD[literal_1][literal_1][literal_3] );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c4110301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c4120301143full, l_scom_buffer ));

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRP < literal_8))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRP > literal_8) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP <= literal_16)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRP > literal_16))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }

            if (literal_1)
            {
            }

            if (((l_TGT2_ATTR_CEN_MSS_FREQ > literal_2133) && l_def_is_ddr3))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_2133) && l_def_is_ddr3))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ < literal_3200) && l_def_is_ddr4))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRCD <= literal_8))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRCD > literal_8) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD <= literal_16)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRCD > literal_16))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x5 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRP < literal_8))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRP > literal_8) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRP <= literal_16)))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRP > literal_16))
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRFC <= literal_256) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRFC > literal_128)))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x8 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRFC <= literal_128) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRFC > literal_64)))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRFC <= literal_64) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRFC > literal_32)))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x6 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRFC > literal_256))
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x9 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRCD <= literal_8))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRCD > literal_8) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRCD <= literal_16)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRCD > literal_16))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x5 );
            }

            if (((l_TGT2_ATTR_CEN_MSS_FREQ <= literal_2133) && l_def_is_ddr3))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT2_ATTR_CEN_MSS_FREQ < literal_3200) && l_def_is_ddr4))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c4120301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c4130301143full, l_scom_buffer ));

            if ((l_def_is_ddr4 || (l_TGT2_ATTR_CEN_MSS_FREQ > literal_1600)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0xA );
            }
            else if ((l_def_is_ddr3 && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1600)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x9 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x6 );
            }

            if ((l_def_is_ddr4 || (l_TGT2_ATTR_CEN_MSS_FREQ > literal_1600)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0xA );
            }
            else if ((l_def_is_ddr3 && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1600)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x6 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }

            if (literal_1)
            {
            }

            if ((l_def_is_ddr4 || (l_TGT2_ATTR_CEN_MSS_FREQ > literal_1600)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0xA );
            }
            else if ((l_def_is_ddr3 && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1600)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x9 );
            }

            if ((l_def_is_ddr4 || (l_TGT2_ATTR_CEN_MSS_FREQ > literal_1600)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0xA );
            }
            else if ((l_def_is_ddr3 && (l_TGT2_ATTR_CEN_MSS_FREQ <= literal_1600)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x6 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x5 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 4, 60, uint64_t>(literal_0x6 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c4130301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c4140301143full, l_scom_buffer ));

            if (((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_16))
                      && (l_def_tODTL_DDR4_NOAL > literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_64))
                      && (l_def_tODTL_DDR4_NOAL > literal_32)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x6 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_32))
                      && (l_def_tODTL_DDR4_NOAL > literal_16)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x0 );
            }

            if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_8))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_64) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_128)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_8) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_16)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x4 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_32) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_64)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_16) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_32)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x5 );
            }

            if (literal_1)
            {
            }

            if (((l_def_is_ddr3 && l_def_AL_ena) && (l_def_tODTL_DDR3 <= literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_is_ddr3 && l_def_AL_ena) && (l_def_tODTL_DDR3 <= literal_16)) && (l_def_tODTL_DDR3 > literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((((l_def_is_ddr3 && l_def_AL_ena) && (l_def_tODTL_DDR3 <= literal_32)) && (l_def_tODTL_DDR3 > literal_16)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_is_ddr3 && l_def_AL_ena) && (l_def_tODTL_DDR3 <= literal_64)) && (l_def_tODTL_DDR3 > literal_32)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_def_is_ddr3 && l_def_AL_dis) && (l_def_tODTL_DDR3_NOAL <= literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_is_ddr3 && l_def_AL_dis) && (l_def_tODTL_DDR3_NOAL <= literal_16))
                      && (l_def_tODTL_DDR3_NOAL > literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((((l_def_is_ddr3 && l_def_AL_dis) && (l_def_tODTL_DDR3_NOAL <= literal_32))
                      && (l_def_tODTL_DDR3_NOAL > literal_16)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_is_ddr3 && l_def_AL_dis) && (l_def_tODTL_DDR3_NOAL <= literal_64))
                      && (l_def_tODTL_DDR3_NOAL > literal_32)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_def_is_ddr4 && l_def_AL_ena) && (l_def_tODTL_DDR4 <= literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_ena) && (l_def_tODTL_DDR4 <= literal_16)) && (l_def_tODTL_DDR4 > literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_ena) && (l_def_tODTL_DDR4 <= literal_32)) && (l_def_tODTL_DDR4 > literal_16)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_ena) && (l_def_tODTL_DDR4 <= literal_64)) && (l_def_tODTL_DDR4 > literal_32)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_16))
                      && (l_def_tODTL_DDR4_NOAL > literal_8)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_32))
                      && (l_def_tODTL_DDR4_NOAL > literal_16)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }
            else if ((((l_def_is_ddr4 && l_def_AL_dis) && (l_def_tODTL_DDR4_NOAL <= literal_64))
                      && (l_def_tODTL_DDR4_NOAL > literal_32)))
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x0 );
            }

            if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_64) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_128)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x7 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_32) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_64)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x6 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_16) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_32)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x5 );
            }
            else if (((l_TGT0_ATTR_CEN_EFF_DRAM_TRC > literal_8) && (l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_16)))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x4 );
            }
            else if ((l_TGT0_ATTR_CEN_EFF_DRAM_TRC <= literal_8))
            {
                l_scom_buffer.insert<52, 4, 60, uint64_t>(literal_0x3 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 4, 60, uint64_t>(literal_0x0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c4140301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c8000301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(l_TGT0_ATTR_CEN_VPD_GPO[literal_1] );
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
                l_scom_buffer.insert<54, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<58, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<60, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<61, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b1 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c8000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c8010301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 50, uint64_t>(literal_0b00000000000000 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 14, 50, uint64_t>(literal_0b00000000000000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c8010301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c8020301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_bl8)
            {
                l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 2, 62, uint64_t>(literal_0b11 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<59, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_bl8)
            {
                l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 5, 59, uint64_t>(literal_0b01111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c8020301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001c8070301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<51, 4, 60, uint64_t>(literal_0b1010 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 2, 62, uint64_t>(literal_0b00 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<57, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 3, 61, uint64_t>(literal_0b000 );
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<51, 4, 60, uint64_t>(literal_0b1010 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<51, 4, 60, uint64_t>(literal_0b0000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001c8070301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001cc000301143full, l_scom_buffer ));

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1B );
            }

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x10 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 8, 56, uint64_t>(literal_0x1B );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<56, 1, 63, uint64_t>(literal_0b1 );
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<57, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<57, 6, 58, uint64_t>(literal_0b100000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001cc000301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001cc010301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b101010 );
            }

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b1100 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0b0000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<52, 3, 61, uint64_t>(literal_0b000 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b101010 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001cc010301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001cc020301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }

            if ((l_def_AL_ena && (l_def_TWTR_PLUS_OFF >= l_def_TRTP_PLUS_AL)))
            {
                l_scom_buffer.insert<52, 6, 58, uint64_t>(l_def_TWTR_PLUS_OFF );
            }
            else if ((l_def_AL_ena && (l_def_TWTR_PLUS_OFF < l_def_TRTP_PLUS_AL)))
            {
                l_scom_buffer.insert<52, 6, 58, uint64_t>(l_def_TRTP_PLUS_AL );
            }
            else if ((l_def_AL_dis && (l_def_TWTR_PLUS_OFF >= l_def_TRTP_PLUS_NOAL)))
            {
                l_scom_buffer.insert<52, 6, 58, uint64_t>(l_def_TWTR_PLUS_OFF );
            }
            else if ((l_def_AL_dis && (l_def_TWTR_PLUS_OFF < l_def_TRTP_PLUS_NOAL)))
            {
                l_scom_buffer.insert<52, 6, 58, uint64_t>(l_def_TRTP_PLUS_NOAL );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<62, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<63, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x3 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<48, 4, 60, uint64_t>(literal_0x5 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001cc020301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x8001cc050301143full, l_scom_buffer ));

            if (literal_1)
            {
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<49, 6, 58, uint64_t>(literal_0b000000 );
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b111111 );
            }

            if (literal_1)
            {
                l_scom_buffer.insert<48, 1, 63, uint64_t>(literal_0b0 );
            }

            if (l_def_is_sim)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b000000 );
            }
            else if (literal_1)
            {
                l_scom_buffer.insert<55, 6, 58, uint64_t>(literal_0b111111 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x8001cc050301143full, l_scom_buffer));
        }
        {
            FAPI_TRY(fapi2::getScom( TGT0, 0x800200930301143full, l_scom_buffer ));

            if (literal_1)
            {
                l_scom_buffer.insert<48, 6, 48, uint64_t>(literal_0x0000000000000000 );
                l_scom_buffer.insert<56, 5, 56, uint64_t>(literal_0x0000000000000000 );
            }

            FAPI_TRY(fapi2::putScom(TGT0, 0x800200930301143full, l_scom_buffer));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
