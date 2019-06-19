/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_4.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_perv_4_H_
#define __p10_scom_perv_4_H_


namespace scomt
{
namespace perv
{


static const uint64_t CLOCK_STAT_ARY = 0x0003000aull;

static const uint32_t CLOCK_STAT_ARY_PERV_ARY = 4;
static const uint32_t CLOCK_STAT_ARY_UNIT1_ARY = 5;
static const uint32_t CLOCK_STAT_ARY_UNIT2_ARY = 6;
static const uint32_t CLOCK_STAT_ARY_UNIT3_ARY = 7;
static const uint32_t CLOCK_STAT_ARY_UNIT4_ARY = 8;
static const uint32_t CLOCK_STAT_ARY_UNIT5_ARY = 9;
static const uint32_t CLOCK_STAT_ARY_UNIT6_ARY = 10;
static const uint32_t CLOCK_STAT_ARY_UNIT7_ARY = 11;
static const uint32_t CLOCK_STAT_ARY_UNIT8_ARY = 12;
static const uint32_t CLOCK_STAT_ARY_UNIT9_ARY = 13;
static const uint32_t CLOCK_STAT_ARY_UNIT10_ARY = 14;
static const uint32_t CLOCK_STAT_ARY_UNIT11_ARY = 15;
static const uint32_t CLOCK_STAT_ARY_UNIT12_ARY = 16;
static const uint32_t CLOCK_STAT_ARY_UNIT13_ARY = 17;
static const uint32_t CLOCK_STAT_ARY_UNIT14_ARY = 18;
// perv/reg00006.H

static const uint64_t COMP_INTR_ERROR_STATUS_REG = 0x000f0034ull;
// perv/reg00006.H

static const uint64_t EPS_FIR_LOCAL_ACTION2 = 0x00040109ull;

static const uint32_t EPS_FIR_LOCAL_ACTION2_00 = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION2_01 = 1;
static const uint32_t EPS_FIR_LOCAL_ACTION2_02 = 2;
static const uint32_t EPS_FIR_LOCAL_ACTION2_03 = 3;
static const uint32_t EPS_FIR_LOCAL_ACTION2_04 = 4;
static const uint32_t EPS_FIR_LOCAL_ACTION2_05 = 5;
static const uint32_t EPS_FIR_LOCAL_ACTION2_06 = 6;
static const uint32_t EPS_FIR_LOCAL_ACTION2_07 = 7;
static const uint32_t EPS_FIR_LOCAL_ACTION2_08 = 8;
static const uint32_t EPS_FIR_LOCAL_ACTION2_09 = 9;
static const uint32_t EPS_FIR_LOCAL_ACTION2_10 = 10;
static const uint32_t EPS_FIR_LOCAL_ACTION2_11 = 11;
static const uint32_t EPS_FIR_LOCAL_ACTION2_12 = 12;
static const uint32_t EPS_FIR_LOCAL_ACTION2_13 = 13;
static const uint32_t EPS_FIR_LOCAL_ACTION2_14 = 14;
static const uint32_t EPS_FIR_LOCAL_ACTION2_15 = 15;
static const uint32_t EPS_FIR_LOCAL_ACTION2_16 = 16;
static const uint32_t EPS_FIR_LOCAL_ACTION2_17 = 17;
static const uint32_t EPS_FIR_LOCAL_ACTION2_18 = 18;
static const uint32_t EPS_FIR_LOCAL_ACTION2_19 = 19;
static const uint32_t EPS_FIR_LOCAL_ACTION2_20 = 20;
static const uint32_t EPS_FIR_LOCAL_ACTION2_21 = 21;
static const uint32_t EPS_FIR_LOCAL_ACTION2_22 = 22;
static const uint32_t EPS_FIR_LOCAL_ACTION2_23 = 23;
static const uint32_t EPS_FIR_LOCAL_ACTION2_24 = 24;
static const uint32_t EPS_FIR_LOCAL_ACTION2_25 = 25;
static const uint32_t EPS_FIR_LOCAL_ACTION2_26 = 26;
static const uint32_t EPS_FIR_LOCAL_ACTION2_27 = 27;
static const uint32_t EPS_FIR_LOCAL_ACTION2_28 = 28;
static const uint32_t EPS_FIR_LOCAL_ACTION2_29 = 29;
static const uint32_t EPS_FIR_LOCAL_ACTION2_30 = 30;
static const uint32_t EPS_FIR_LOCAL_ACTION2_31 = 31;
static const uint32_t EPS_FIR_LOCAL_ACTION2_32 = 32;
static const uint32_t EPS_FIR_LOCAL_ACTION2_33 = 33;
static const uint32_t EPS_FIR_LOCAL_ACTION2_34 = 34;
static const uint32_t EPS_FIR_LOCAL_ACTION2_35 = 35;
static const uint32_t EPS_FIR_LOCAL_ACTION2_36 = 36;
static const uint32_t EPS_FIR_LOCAL_ACTION2_37 = 37;
static const uint32_t EPS_FIR_LOCAL_ACTION2_38 = 38;
static const uint32_t EPS_FIR_LOCAL_ACTION2_39 = 39;
static const uint32_t EPS_FIR_LOCAL_ACTION2_40 = 40;
static const uint32_t EPS_FIR_LOCAL_ACTION2_41 = 41;
static const uint32_t EPS_FIR_LOCAL_ACTION2_42 = 42;
static const uint32_t EPS_FIR_LOCAL_ACTION2_43 = 43;
static const uint32_t EPS_FIR_LOCAL_ACTION2_44 = 44;
static const uint32_t EPS_FIR_LOCAL_ACTION2_45 = 45;
static const uint32_t EPS_FIR_LOCAL_ACTION2_46 = 46;
static const uint32_t EPS_FIR_LOCAL_ACTION2_47 = 47;
static const uint32_t EPS_FIR_LOCAL_ACTION2_48 = 48;
static const uint32_t EPS_FIR_LOCAL_ACTION2_49 = 49;
static const uint32_t EPS_FIR_LOCAL_ACTION2_50 = 50;
static const uint32_t EPS_FIR_LOCAL_ACTION2_51 = 51;
static const uint32_t EPS_FIR_LOCAL_ACTION2_52 = 52;
static const uint32_t EPS_FIR_LOCAL_ACTION2_53 = 53;
static const uint32_t EPS_FIR_LOCAL_ACTION2_54 = 54;
static const uint32_t EPS_FIR_LOCAL_ACTION2_55 = 55;
static const uint32_t EPS_FIR_LOCAL_ACTION2_56 = 56;
static const uint32_t EPS_FIR_LOCAL_ACTION2_57 = 57;
static const uint32_t EPS_FIR_LOCAL_ACTION2_58 = 58;
static const uint32_t EPS_FIR_LOCAL_ACTION2_59 = 59;
static const uint32_t EPS_FIR_LOCAL_ACTION2_60 = 60;
static const uint32_t EPS_FIR_LOCAL_ACTION2_61 = 61;
static const uint32_t EPS_FIR_LOCAL_ACTION2_62 = 62;
static const uint32_t EPS_FIR_LOCAL_ACTION2_63 = 63;
// perv/reg00006.H

static const uint64_t EPS_THERM_WSUB_INJECT_REG = 0x00050011ull;

static const uint32_t EPS_THERM_WSUB_INJECT_REG_TRIP = 0;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_TRIP_LEN = 2;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_MODE = 2;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_MODE_LEN = 2;
// perv/reg00006.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG = 0x00050036ull;

static const uint32_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG_CLKSRC = 0;
static const uint32_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG_CLKSRC_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG_DELAY_SELECT = 36;
static const uint32_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN = 2;
// perv/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_13_FSI = 0x0000284dull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_13_FSI_BYTE = 0x00002934ull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_13_RW = 0x0005004dull;
// perv/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI = 0x00002844ull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_4_FSI_BYTE = 0x00002910ull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_4_RW = 0x00050044ull;
// perv/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI = 0x000028c8ull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_8_FSI_BYTE = 0x00002b20ull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_8_RW = 0x000500c8ull;
// perv/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI = 0x00002902ull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_2_FSI_BYTE = 0x00002c08ull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_2_RW = 0x00050102ull;
// perv/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_FSI = 0x0000281bull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE = 0x0000286cull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_RW = 0x0005001bull;

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED = 0;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_PLL_BNDY_BYPASS_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_4_RESERVED = 4;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_5_RESERVED = 5;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_6_RESERVED = 6;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_7_RESERVED = 7;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_8_RESERVED = 8;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_9_RESERVED = 9;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_10_RESERVED = 10;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_11_RESERVED = 11;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_12_RESERVED = 12;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_13_RESERVED = 13;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_14_RESERVED = 14;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_15_RESERVED = 15;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_RESERVED = 20;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_21_RESERVED = 21;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_22_RESERVED = 22;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_23_RESERVED = 23;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_24_RESERVED = 24;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_TP_CLK_PULSE_ENABLE_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_TP_CLK_PULSE_MODE_DC = 26;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_TP_CLK_PULSE_MODE_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_28_RESERVED = 28;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_29_RESERVED = 29;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_30_RESERVED = 30;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_TP_PCB_PM_MUX_SEL_DC = 31;
// perv/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_FSI = 0x00002811ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_FSI_BYTE = 0x00002844ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_RW = 0x00050011ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE0_SEL_DC_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE1_SEL_DC_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_MESH_SEL_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_DRV_EN_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_PROBE_HIGHDRIVE_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_FSI_PROBE_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP0_DC = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP1_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_AN_PROBE_DRVR_MCPRECOMP2_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_IDDQ_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_RI_CONTROL = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SPARE_DI_CONTROL = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_22_SPARE_TEST = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_26_SPARE = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_GLBCK_MEM_TESTCLK_SEL_DC = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL = 31;
// perv/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI = 0x00002934ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE = 0x00002cd0ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR = 0x00050134ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_5_SPARE = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_13_SPARE = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_17_SPARE = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_26_SPARE = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_30_SPARE = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE = 31;
// perv/reg00006.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI = 0x0000283cull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE = 0x000028f0ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW = 0x0005003cull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5_LEN = 32;
// perv/reg00006.H

static const uint64_t L3TRA0_TR1_CONFIG_4 = 0x00018227ull;

static const uint32_t L3TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t L3TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t L3TRA0_TR1_CONFIG_4_B_LEN = 24;
// perv/reg00006.H

static const uint64_t L3TRA1_TR0_CONFIG_2 = 0x00018245ull;

static const uint32_t L3TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t L3TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t L3TRA1_TR0_CONFIG_2_B_LEN = 24;
// perv/reg00006.H

static const uint64_t L3TRA2_TR0_CONFIG_5 = 0x00018288ull;

static const uint32_t L3TRA2_TR0_CONFIG_5_C = 0;
static const uint32_t L3TRA2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA2_TR0_CONFIG_5_D = 24;
static const uint32_t L3TRA2_TR0_CONFIG_5_D_LEN = 24;
// perv/reg00006.H

static const uint64_t L3TRA3_TR1_CONFIG_3 = 0x000182e6ull;

static const uint32_t L3TRA3_TR1_CONFIG_3_C = 0;
static const uint32_t L3TRA3_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA3_TR1_CONFIG_3_D = 24;
static const uint32_t L3TRA3_TR1_CONFIG_3_D_LEN = 24;
// perv/reg00006.H

static const uint64_t MCAST_GRP_0_SLAVES_REG = 0x000f0000ull;

static const uint32_t MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0 = 0;
static const uint32_t MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0_LEN = 6;
// perv/reg00006.H

static const uint64_t MCAST_GRP_3_SLAVES_REG = 0x000f0003ull;

static const uint32_t MCAST_GRP_3_SLAVES_REG_SLAVES_MCAST_GROUP_3 = 0;
static const uint32_t MCAST_GRP_3_SLAVES_REG_SLAVES_MCAST_GROUP_3_LEN = 6;
// perv/reg00006.H

static const uint64_t MCAST_GRP_5_SLAVES_REG = 0x000f0005ull;

static const uint32_t MCAST_GRP_5_SLAVES_REG_SLAVES_MCAST_GROUP_5 = 0;
static const uint32_t MCAST_GRP_5_SLAVES_REG_SLAVES_MCAST_GROUP_5_LEN = 6;
// perv/reg00006.H

static const uint64_t MCAST_GRP_6_SLAVES_REG = 0x000f0006ull;

static const uint32_t MCAST_GRP_6_SLAVES_REG_SLAVES_MCAST_GROUP_6 = 0;
static const uint32_t MCAST_GRP_6_SLAVES_REG_SLAVES_MCAST_GROUP_6_LEN = 6;
// perv/reg00006.H

static const uint64_t OPCG_REG2 = 0x00030004ull;

static const uint32_t OPCG_REG2_OPCG_GO2 = 0;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING = 1;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING_LEN = 3;
static const uint32_t OPCG_REG2_PRPG_VALUE = 4;
static const uint32_t OPCG_REG2_PRPG_VALUE_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_A_VAL = 16;
static const uint32_t OPCG_REG2_PRPG_A_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_B_VAL = 28;
static const uint32_t OPCG_REG2_PRPG_B_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_MODE = 40;
static const uint32_t OPCG_REG2_SM_LBIST_CNTRL = 48;
static const uint32_t OPCG_REG2_SM_LBIST_CNTRL_LEN = 16;
// perv/reg00006.H

static const uint64_t OTPC_M_MEASURE_REG4 = 0x00010014ull;

static const uint32_t OTPC_M_MEASURE_REG4_SEEPROM_MEASUREMENT4_DATA = 0;
static const uint32_t OTPC_M_MEASURE_REG4_SEEPROM_MEASUREMENT4_DATA_LEN = 64;
// perv/reg00006.H

static const uint64_t PCB_OPCG_GO = 0x00030020ull;

static const uint32_t PCB_OPCG_GO_PCB_OPCGGO = 0;
// perv/reg00006.H

static const uint64_t REC_ERR_MST1_REG0 = 0x000f0044ull;

static const uint32_t REC_ERR_MST1_REG0_MASTER_MST1_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST1_REG0_MASTER_MST1_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST1_REG0_MASTER_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE1_MST1_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST1_REG0_SLAVE1_MST1_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST1_REG0_SLAVE1_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE2_MST1_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST1_REG0_SLAVE2_MST1_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST1_REG0_SLAVE2_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE3_MST1_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST1_REG0_SLAVE3_MST1_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST1_REG0_SLAVE3_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE4_MST1_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST1_REG0_SLAVE4_MST1_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST1_REG0_SLAVE4_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE5_MST1_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST1_REG0_SLAVE5_MST1_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST1_REG0_SLAVE5_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE6_MST1_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST1_REG0_SLAVE6_MST1_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST1_REG0_SLAVE6_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE7_MST1_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST1_REG0_SLAVE7_MST1_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST1_REG0_SLAVE7_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE8_MST1_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST1_REG0_SLAVE8_MST1_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST1_REG0_SLAVE8_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE9_MST1_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST1_REG0_SLAVE9_MST1_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST1_REG0_SLAVE9_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE10_MST1_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST1_REG0_SLAVE10_MST1_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST1_REG0_SLAVE10_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE11_MST1_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST1_REG0_SLAVE11_MST1_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST1_REG0_SLAVE11_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE12_MST1_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST1_REG0_SLAVE12_MST1_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST1_REG0_SLAVE12_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE13_MST1_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST1_REG0_SLAVE13_MST1_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST1_REG0_SLAVE13_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE14_MST1_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST1_REG0_SLAVE14_MST1_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST1_REG0_SLAVE14_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG0_SLAVE15_MST1_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST1_REG0_SLAVE15_MST1_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST1_REG0_SLAVE15_MST1_ERROR_CODE_LEN = 3;
// perv/reg00006.H

static const uint64_t REC_ERR_MST5_REG1 = 0x000f0055ull;

static const uint32_t REC_ERR_MST5_REG1_16_MST5_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST5_REG1_16_MST5_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST5_REG1_16_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_17_MST5_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST5_REG1_17_MST5_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST5_REG1_17_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_18_MST5_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST5_REG1_18_MST5_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST5_REG1_18_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_19_MST5_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST5_REG1_19_MST5_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST5_REG1_19_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_20_MST5_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST5_REG1_20_MST5_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST5_REG1_20_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_21_MST5_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST5_REG1_21_MST5_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST5_REG1_21_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_22_MST5_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST5_REG1_22_MST5_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST5_REG1_22_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_23_MST5_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST5_REG1_23_MST5_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST5_REG1_23_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_24_MST5_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST5_REG1_24_MST5_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST5_REG1_24_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_25_MST5_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST5_REG1_25_MST5_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST5_REG1_25_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_26_MST5_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST5_REG1_26_MST5_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST5_REG1_26_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_27_MST5_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST5_REG1_27_MST5_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST5_REG1_27_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_28_MST5_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST5_REG1_28_MST5_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST5_REG1_28_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_29_MST5_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST5_REG1_29_MST5_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST5_REG1_29_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_30_MST5_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST5_REG1_30_MST5_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST5_REG1_30_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG1_31_MST5_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST5_REG1_31_MST5_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST5_REG1_31_MST5_ERROR_CODE_LEN = 3;
// perv/reg00006.H

static const uint64_t REC_ERR_REG2 = 0x000f0013ull;

static const uint32_t REC_ERR_REG2_32_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_REG2_32_ERROR_CODE = 1;
static const uint32_t REC_ERR_REG2_32_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_33_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_REG2_33_ERROR_CODE = 5;
static const uint32_t REC_ERR_REG2_33_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_34_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_REG2_34_ERROR_CODE = 9;
static const uint32_t REC_ERR_REG2_34_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_35_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_REG2_35_ERROR_CODE = 13;
static const uint32_t REC_ERR_REG2_35_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_36_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_REG2_36_ERROR_CODE = 17;
static const uint32_t REC_ERR_REG2_36_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_37_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_REG2_37_ERROR_CODE = 21;
static const uint32_t REC_ERR_REG2_37_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_38_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_REG2_38_ERROR_CODE = 25;
static const uint32_t REC_ERR_REG2_38_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_39_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_REG2_39_ERROR_CODE = 29;
static const uint32_t REC_ERR_REG2_39_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_40_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_REG2_40_ERROR_CODE = 33;
static const uint32_t REC_ERR_REG2_40_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_41_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_REG2_41_ERROR_CODE = 37;
static const uint32_t REC_ERR_REG2_41_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_42_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_REG2_42_ERROR_CODE = 41;
static const uint32_t REC_ERR_REG2_42_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_43_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_REG2_43_ERROR_CODE = 45;
static const uint32_t REC_ERR_REG2_43_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_44_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_REG2_44_ERROR_CODE = 49;
static const uint32_t REC_ERR_REG2_44_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_45_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_REG2_45_ERROR_CODE = 53;
static const uint32_t REC_ERR_REG2_45_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_46_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_REG2_46_ERROR_CODE = 57;
static const uint32_t REC_ERR_REG2_46_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG2_47_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_REG2_47_ERROR_CODE = 61;
static const uint32_t REC_ERR_REG2_47_ERROR_CODE_LEN = 3;
// perv/reg00006.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG106 = 0x0000806aull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG106_REGISTER106 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG106_REGISTER106_LEN = 64;
// perv/reg00006.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG119 = 0x00008077ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG119_REGISTER119 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG119_REGISTER119_LEN = 64;
// perv/reg00006.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG17 = 0x00008011ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG17_REGISTER17 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG17_REGISTER17_LEN = 64;
// perv/reg00006.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG20 = 0x00008014ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG20_REGISTER20 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG20_REGISTER20_LEN = 64;
// perv/reg00006.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG41 = 0x00008029ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG41_REGISTER41 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG41_REGISTER41_LEN = 64;
// perv/reg00006.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG69 = 0x00008045ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG69_REGISTER69 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG69_REGISTER69_LEN = 64;
// perv/reg00006.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG7 = 0x00008007ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG7_REGISTER7 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG7_REGISTER7_LEN = 64;
// perv/reg00006.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG76 = 0x0000804cull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG76_REGISTER76 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG76_REGISTER76_LEN = 64;
// perv/reg00006.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG83 = 0x00008053ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG83_REGISTER83 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG83_REGISTER83_LEN = 64;
// perv/reg00006.H

static const uint64_t TOD_LOAD_MOD_REG = 0x00040018ull;

static const uint32_t TOD_LOAD_MOD_REG_TRIGGER = 0;
static const uint32_t TOD_LOAD_MOD_REG_SYNC_ENABLE = 1;
// perv/reg00006.H

static const uint64_t TOD_M_PATH_CTRL_REG = 0x00040000ull;

static const uint32_t TOD_M_PATH_CTRL_REG_0_OSC_NOT_VALID = 0;
static const uint32_t TOD_M_PATH_CTRL_REG_1_OSC_NOT_VALID = 1;
static const uint32_t TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_DISABLE = 2;
static const uint32_t TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_DISABLE = 3;
static const uint32_t TOD_M_PATH_CTRL_REG_STEP_CREATE_DUAL_EDGE_DISABLE = 4;
static const uint32_t TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT = 5;
static const uint32_t TOD_M_PATH_CTRL_REG_SYNC_CREATE_SPS_SELECT_LEN = 3;
static const uint32_t TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION = 8;
static const uint32_t TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CPS_DEVIATION_LEN = 4;
static const uint32_t TOD_M_PATH_CTRL_REG_0_STEP_CHECK_CONSTANT_CPS_ENABLE = 12;
static const uint32_t TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT = 13;
static const uint32_t TOD_M_PATH_CTRL_REG_0_STEP_CHECK_VALIDITY_COUNT_LEN = 3;
static const uint32_t TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION = 16;
static const uint32_t TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CPS_DEVIATION_LEN = 4;
static const uint32_t TOD_M_PATH_CTRL_REG_1_STEP_CHECK_CONSTANT_CPS_ENABLE = 20;
static const uint32_t TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT = 21;
static const uint32_t TOD_M_PATH_CTRL_REG_1_STEP_CHECK_VALIDITY_COUNT_LEN = 3;
static const uint32_t TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR = 24;
static const uint32_t TOD_M_PATH_CTRL_REG_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN = 2;
static const uint32_t TOD_M_PATH_CTRL_REG_0_LOCAL_STEP_MODE_ENABLE = 26;
static const uint32_t TOD_M_PATH_CTRL_REG_1_LOCAL_STEP_MODE_ENABLE = 27;
static const uint32_t TOD_M_PATH_CTRL_REG_0_STEP_STEER_ENABLE = 28;
static const uint32_t TOD_M_PATH_CTRL_REG_1_STEP_STEER_ENABLE = 29;
static const uint32_t TOD_M_PATH_CTRL_REG_0_STEP_ALIGN_CLKGATE_DISABLE = 30;
static const uint32_t TOD_M_PATH_CTRL_REG_1_STEP_ALIGN_CLKGATE_DISABLE = 31;
// perv/reg00006.H

static const uint64_t TOD_TIMER_REG = 0x0004000dull;

static const uint32_t TOD_TIMER_REG_VALUE = 0;
static const uint32_t TOD_TIMER_REG_VALUE_LEN = 60;
static const uint32_t TOD_TIMER_REG_ENABLE0 = 60;
static const uint32_t TOD_TIMER_REG_ENABLE1 = 61;
static const uint32_t TOD_TIMER_REG_STATUS0 = 62;
static const uint32_t TOD_TIMER_REG_STATUS1 = 63;
// perv/reg00006.H

static const uint64_t TRA0_TR0_TRACE_LO_DATA_REG = 0x00010401ull;

static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00006.H

static const uint64_t TRA0_TR1_CONFIG_4 = 0x00010447ull;

static const uint32_t TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t TRA0_TR1_CONFIG_4_B_LEN = 24;
// perv/reg00006.H

static const uint64_t TRA1_TR0_CONFIG_2 = 0x00010485ull;

static const uint32_t TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t TRA1_TR0_CONFIG_2_B_LEN = 24;
// perv/reg00006.H

static const uint64_t TRA2_TR0_CONFIG_5 = 0x00010508ull;

static const uint32_t TRA2_TR0_CONFIG_5_C = 0;
static const uint32_t TRA2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA2_TR0_CONFIG_5_D = 24;
static const uint32_t TRA2_TR0_CONFIG_5_D_LEN = 24;
// perv/reg00006.H

static const uint64_t TRA3_TR1_TRACE_HI_DATA_REG = 0x000105c0ull;

static const uint32_t TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00006.H

static const uint64_t TRA3_TR1_CONFIG_3 = 0x000105c6ull;

static const uint32_t TRA3_TR1_CONFIG_3_C = 0;
static const uint32_t TRA3_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TRA3_TR1_CONFIG_3_D = 24;
static const uint32_t TRA3_TR1_CONFIG_3_D_LEN = 24;
// perv/reg00006.H

static const uint64_t TRA4_TR1_CONFIG_2 = 0x00010645ull;

static const uint32_t TRA4_TR1_CONFIG_2_A = 0;
static const uint32_t TRA4_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TRA4_TR1_CONFIG_2_B = 24;
static const uint32_t TRA4_TR1_CONFIG_2_B_LEN = 24;
// perv/reg00006.H

static const uint64_t TRA5_TR0_CONFIG_4 = 0x00010687ull;

static const uint32_t TRA5_TR0_CONFIG_4_A = 0;
static const uint32_t TRA5_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TRA5_TR0_CONFIG_4_B = 24;
static const uint32_t TRA5_TR0_CONFIG_4_B_LEN = 24;
// perv/reg00006.H

static const uint64_t TRA6_TR0_CONFIG_3 = 0x00010706ull;

static const uint32_t TRA6_TR0_CONFIG_3_C = 0;
static const uint32_t TRA6_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA6_TR0_CONFIG_3_D = 24;
static const uint32_t TRA6_TR0_CONFIG_3_D_LEN = 24;
// perv/reg00006.H

static const uint64_t XSTOP1 = 0x0003000cull;

static const uint32_t XSTOP1_XSTOP1_MASK_B = 0;
static const uint32_t XSTOP1_ALIGNED_XSTOP1 = 1;
static const uint32_t XSTOP1_TRIGGER_OPCG_ON_XSTOP1 = 2;
static const uint32_t XSTOP1_XSTOP1_WAIT_ALLWAYS = 3;
static const uint32_t XSTOP1_XSTOP1_PERV = 4;
static const uint32_t XSTOP1_XSTOP1_UNIT1 = 5;
static const uint32_t XSTOP1_XSTOP1_UNIT2 = 6;
static const uint32_t XSTOP1_XSTOP1_UNIT3 = 7;
static const uint32_t XSTOP1_XSTOP1_UNIT4 = 8;
static const uint32_t XSTOP1_XSTOP1_UNIT5 = 9;
static const uint32_t XSTOP1_XSTOP1_UNIT6 = 10;
static const uint32_t XSTOP1_XSTOP1_UNIT7 = 11;
static const uint32_t XSTOP1_XSTOP1_UNIT8 = 12;
static const uint32_t XSTOP1_XSTOP1_UNIT9 = 13;
static const uint32_t XSTOP1_XSTOP1_UNIT10 = 14;
static const uint32_t XSTOP1_XSTOP1_UNIT11 = 15;
static const uint32_t XSTOP1_XSTOP1_UNIT12 = 16;
static const uint32_t XSTOP1_XSTOP1_UNIT13 = 17;
static const uint32_t XSTOP1_XSTOP1_UNIT14 = 18;
static const uint32_t XSTOP1_XSTOP1_WAIT_CYCLES = 48;
static const uint32_t XSTOP1_XSTOP1_WAIT_CYCLES_LEN = 12;
// perv/reg00006.H

}
}
#ifndef __PPE_HCODE__
    #include "perv/reg00006.H"
#endif
#endif
