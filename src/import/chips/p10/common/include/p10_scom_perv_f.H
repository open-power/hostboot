/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_f.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __p10_scom_perv_f_H_
#define __p10_scom_perv_f_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> [BIST]
static const uint64_t BIST = 0x0003000bull;

static const uint32_t BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t BIST_REGION_PERV = 4;
static const uint32_t BIST_REGION_UNIT1 = 5;
static const uint32_t BIST_REGION_UNIT2 = 6;
static const uint32_t BIST_REGION_UNIT3 = 7;
static const uint32_t BIST_REGION_UNIT4 = 8;
static const uint32_t BIST_REGION_UNIT5 = 9;
static const uint32_t BIST_REGION_UNIT6 = 10;
static const uint32_t BIST_REGION_UNIT7 = 11;
static const uint32_t BIST_REGION_UNIT8 = 12;
static const uint32_t BIST_REGION_UNIT9 = 13;
static const uint32_t BIST_REGION_UNIT10 = 14;
static const uint32_t BIST_REGION_UNIT11 = 15;
static const uint32_t BIST_REGION_UNIT12 = 16;
static const uint32_t BIST_REGION_UNIT13 = 17;
static const uint32_t BIST_REGION_UNIT14 = 18;
static const uint32_t BIST_STROBE_WINDOW_EN = 48;
//<< [BIST]
// perv/reg00030.H

//>> [BIT_SEL_REG_2]
static const uint64_t BIT_SEL_REG_2 = 0x000f0008ull;

static const uint32_t BIT_SEL_REG_2_BIT_SELECT_REGISTER_FSP2PIB = 0;
static const uint32_t BIT_SEL_REG_2_BIT_SELECT_REGISTER_FSP2PIB_LEN = 6;
//<< [BIT_SEL_REG_2]
// perv/reg00030.H

//>> [CPLT_CTRL5]
static const uint64_t CPLT_CTRL5_RW = 0x00000005ull;
static const uint64_t CPLT_CTRL5_WO_CLEAR = 0x00000025ull;
static const uint64_t CPLT_CTRL5_WO_OR = 0x00000015ull;

static const uint32_t CPLT_CTRL5_TC_CCFG_PMA0_MUX_SEL_DC = 0;
static const uint32_t CPLT_CTRL5_TP_AN_NMMU_PFET_ENABLE_DC = 0;
static const uint32_t CPLT_CTRL5_0 = 0;
static const uint32_t CPLT_CTRL5_TC_CCFG_PMA1_MUX_SEL_DC = 1;
static const uint32_t CPLT_CTRL5_01 = 1;
static const uint32_t CPLT_CTRL5_1 = 1;
static const uint32_t CPLT_CTRL5_TC_CCFG_PMA2_MUX_SEL_DC = 2;
static const uint32_t CPLT_CTRL5_02 = 2;
static const uint32_t CPLT_CTRL5_2 = 2;
static const uint32_t CPLT_CTRL5_TC_CCFG_PMA3_MUX_SEL_DC = 3;
static const uint32_t CPLT_CTRL5_03 = 3;
static const uint32_t CPLT_CTRL5_3 = 3;
static const uint32_t CPLT_CTRL5_VITL_DFT_FENCE_DC = 3;
static const uint32_t CPLT_CTRL5_TC_CCFG_PCS01_MUX_SEL_DC = 4;
static const uint32_t CPLT_CTRL5_TP_AN_EMO67_PFET_ENABLE_DC = 4;
static const uint32_t CPLT_CTRL5_4 = 4;
static const uint32_t CPLT_CTRL5_REGION0_DFT_FENCE_DC = 4;
static const uint32_t CPLT_CTRL5_TC_CCFG_PCS23_MUX_SEL_DC = 5;
static const uint32_t CPLT_CTRL5_TP_AN_EMO45_PFET_ENABLE_DC = 5;
static const uint32_t CPLT_CTRL5_5 = 5;
static const uint32_t CPLT_CTRL5_REGION1_DFT_FENCE_DC = 5;
static const uint32_t CPLT_CTRL5_TC_CCFG_PIPE_LANEX_EXT_PLL_MODE_DC = 6;
static const uint32_t CPLT_CTRL5_TP_AN_EMO23_PFET_ENABLE_DC = 6;
static const uint32_t CPLT_CTRL5_6 = 6;
static const uint32_t CPLT_CTRL5_REGION2_DFT_FENCE_DC = 6;
static const uint32_t CPLT_CTRL5_TC_CCFG_PHYX_CR_PARA_SEL_DC = 7;
static const uint32_t CPLT_CTRL5_TP_AN_EMO01_PFET_ENABLE_DC = 7;
static const uint32_t CPLT_CTRL5_7 = 7;
static const uint32_t CPLT_CTRL5_REGION3_DFT_FENCE_DC = 7;
static const uint32_t CPLT_CTRL5_TC_CCFG_PHY_EXT_CTRL_SEL_DC = 8;
static const uint32_t CPLT_CTRL5_TP_AN_PAU0_PFET_ENABLE_DC = 8;
static const uint32_t CPLT_CTRL5_8 = 8;
static const uint32_t CPLT_CTRL5_REGION4_DFT_FENCE_DC = 8;
static const uint32_t CPLT_CTRL5_09 = 9;
static const uint32_t CPLT_CTRL5_9 = 9;
static const uint32_t CPLT_CTRL5_REGION5_DFT_FENCE_DC = 9;
static const uint32_t CPLT_CTRL5_010 = 10;
static const uint32_t CPLT_CTRL5_10 = 10;
static const uint32_t CPLT_CTRL5_REGION6_DFT_FENCE_DC = 10;
static const uint32_t CPLT_CTRL5_011 = 11;
static const uint32_t CPLT_CTRL5_TP_AN_PAU3_PFET_ENABLE_DC = 11;
static const uint32_t CPLT_CTRL5_11 = 11;
static const uint32_t CPLT_CTRL5_REGION7_DFT_FENCE_DC = 11;
static const uint32_t CPLT_CTRL5_012 = 12;
static const uint32_t CPLT_CTRL5_TP_AN_PAU4_PFET_ENABLE_DC = 12;
static const uint32_t CPLT_CTRL5_12 = 12;
static const uint32_t CPLT_CTRL5_REGION8_DFT_FENCE_DC = 12;
static const uint32_t CPLT_CTRL5_013 = 13;
static const uint32_t CPLT_CTRL5_TP_AN_PAU5_PFET_ENABLE_DC = 13;
static const uint32_t CPLT_CTRL5_13 = 13;
static const uint32_t CPLT_CTRL5_REGION9_DFT_FENCE_DC = 13;
static const uint32_t CPLT_CTRL5_014 = 14;
static const uint32_t CPLT_CTRL5_TP_AN_PAU6_PFET_ENABLE_DC = 14;
static const uint32_t CPLT_CTRL5_14 = 14;
static const uint32_t CPLT_CTRL5_REGION10_DFT_FENCE_DC = 14;
static const uint32_t CPLT_CTRL5_015 = 15;
static const uint32_t CPLT_CTRL5_TP_AN_PAU7_PFET_ENABLE_DC = 15;
static const uint32_t CPLT_CTRL5_15 = 15;
static const uint32_t CPLT_CTRL5_REGION11_DFT_FENCE_DC = 15;
static const uint32_t CPLT_CTRL5_016 = 16;
static const uint32_t CPLT_CTRL5_TP_AN_PCIE1_PFET_ENABLE_DC = 16;
static const uint32_t CPLT_CTRL5_16 = 16;
static const uint32_t CPLT_CTRL5_REGION12_DFT_FENCE_DC = 16;
static const uint32_t CPLT_CTRL5_017 = 17;
static const uint32_t CPLT_CTRL5_TP_AN_PCIE0_PFET_ENABLE_DC = 17;
static const uint32_t CPLT_CTRL5_17 = 17;
static const uint32_t CPLT_CTRL5_REGION13_DFT_FENCE_DC = 17;
static const uint32_t CPLT_CTRL5_018 = 18;
static const uint32_t CPLT_CTRL5_18 = 18;
static const uint32_t CPLT_CTRL5_REGION14_DFT_FENCE_DC = 18;
static const uint32_t CPLT_CTRL5_019 = 19;
static const uint32_t CPLT_CTRL5_19 = 19;
//<< [CPLT_CTRL5]
// perv/reg00030.H

//>> [EPS_THERM_WSUB_DTS_RESULT0]
static const uint64_t EPS_THERM_WSUB_DTS_RESULT0 = 0x00050000ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
//<< [EPS_THERM_WSUB_DTS_RESULT0]
// perv/reg00030.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL0_SET]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI = 0x00002920ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI_BYTE = 0x00002c80ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_WO_OR = 0x00050120ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_CFAM_PROTECTION_0_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_1_SPARE = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_TPFSI_TPI2C_BUS_FENCE_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_TPCFSI_OPB_SW0_FENCE_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_TPCFSI_OPB_SW0_FENCE_DC_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_6_7_SPARE = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_6_7_SPARE_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_CFAM_PROTECTION_1_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_CFAM_PROTECTION_2_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_CFAM_PIB_SLV_RESET_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_11_SPARE = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_12_SPARE = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_13_SPARE = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_SPARE_FENCE_CONTROL = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_VDD2VIO_LVL_FENCE_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI2PCB_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_OOB_MUX = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_PIB2PCB_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_PCB2PCB_DC = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI_CC_VSB_CBS_REQ = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI_CC_VSB_CBS_CMD = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_FSI_CC_VSB_CBS_CMD_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_24_SPARE_CBS_CONTROL = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_25_SPARE_CBS_CONTROL = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_26_SPARE_CBS_CONTROL = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_27_SPARE_CBS_CONTROL = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_ROOT_CTRL0_28_SPARE_RESET = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_TPFSI_IO_OCMB_RESET_EN = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_PCB_RESET_DC = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_SET_GLOBAL_EP_RESET_DC = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL0_SET]
// perv/reg00030.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL1_SET]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_FSI = 0x00002921ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_FSI_BYTE = 0x00002c84ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_WO_OR = 0x00050121ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_PROBE0_SEL_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_PROBE0_SEL_DC_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_PROBE1_SEL_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_PROBE1_SEL_DC_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_PROBE_MESH_SEL_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_PROBE_DRV_EN_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_10_SPARE = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_FSI_PROBE_SEL_DC = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_FSI_PROBE_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_AN_PROBE_DRVR_MCPRECOMP0_DC = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_AN_PROBE_DRVR_MCPRECOMP1_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_AN_PROBE_DRVR_MCPRECOMP2_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_IDDQ_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_SPARE_RI_CONTROL = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_SPARE_DI_CONTROL = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_RI_DC_B = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_DI1_DC_B = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_DI2_DC_B = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_TPM_DI1_DC_B = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_23_SPARE_TEST = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TP_TEST_BURNIN_MODE_DC = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TPFSI_ARRAY_SET_VBL_TO_VDD_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_TPFSI_TP_GLB_PERST_OVR_DC = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_27_SPARE = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_28_SPARE_TEST_CONTROL = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_29_SPARE_TEST_CONTROL = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_30_SPARE_TEST_CONTROL = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_SET_ROOT_CTRL1_31_SPARE_TEST_CONTROL = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL1_SET]
// perv/reg00030.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL3_SET]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_FSI = 0x00002923ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_FSI_BYTE = 0x00002c8cull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_WO_OR = 0x00050123ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW1_RESET_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW1_BYPASS_EN_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW1_TEST_EN_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW1_ALTREFCLK_SEL_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW2_RESET_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW2_BYPASS_EN_DC = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW2_TEST_EN_DC = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLCLKSW2_ALTREFCLK_SEL_DC = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLTODFLT_RESET_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLTODFLT_BYPASS_EN_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLTODFLT_TEST_EN_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_SPARE_PLLTODFLT = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLNESTFLT_RESET_DC = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLNESTFLT_BYPASS_EN_DC = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLNESTFLT_TEST_EN_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_SPARE_PLLNESTFLT = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLIOFLT_RESET_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLIOFLT_BYPASS_EN_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLIOFLT_TEST_EN_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_SPARE_PLLIOFLT = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLIOSSFLT_RESET_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLIOSSFLT_BYPASS_EN_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PLLIOSSFLT_TEST_EN_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_SPARE_PLLIOSSFLT = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PAU_DPLL_RESET_DC = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PAU_DPLL_BYPASS_EN_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PAU_DPLL_TEST_EN_DC = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_PAU_DPLL_FUNC_CLKSEL_DC = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_NEST_DPLL_RESET_DC = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_NEST_DPLL_BYPASS_EN_DC = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_NEST_DPLL_TEST_EN_DC = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SET_TP_NEST_DPLL_FUNC_CLKSEL_DC = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL3_SET]
// perv/reg00030.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL4_SET]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_FSI = 0x00002924ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_FSI_BYTE = 0x00002c90ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_WO_OR = 0x00050124ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_TOD_LPC_MUX_SEL_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_ROOT_CTRL4_18_SPARE = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_ROOT_CTRL4_19_SPARE = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_MUX1_CLKIN_SEL_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_MUX2A_CLKIN_SEL_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_MUX2B_CLKIN_SEL_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_MUX3_CLKIN_SEL_DC = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_MUX4A_CLKIN_SEL_DC = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_AN_NEST_DIV2_ASYNC_RESET_DC = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TPFSI_ALTREFCLK_SEL = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_ROOT_CTRL4_28_SPARE = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_TP_PLL_FORCE_OUT_EN_DC = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_DPLL_FREEZE_DC = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_SET_ROOT_CTRL4_31_SPARE = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL4_SET]
// perv/reg00030.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL5_SET]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_FSI = 0x00002925ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_FSI_BYTE = 0x00002c94ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_WO_OR = 0x00050125ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_TPFSI_RCS_RESET_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_TPFSI_RCS_BYPASS_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_TPFSI_RCS_CLK_TEST_IN_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_SWO_FORCE_LOW = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_BLOCK_SWO = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_CLEAR_CLK_ERROR_A = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_CLEAR_CLK_ERROR_B = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_SEL_DEL = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_DESKEW = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_DESKEW_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_FILT = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_FILT_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_PFD_PW_SEL = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_FORCE_ERROR_HIGH = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_TESTOUT_EN = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_TESTOUT_SEL = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_TESTOUT_SEL_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_EN_OVERRIDE_A = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_EN_OVERRIDE_B = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_OVRBIT = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_OVRBIT_LEN = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_EN_REFCLK = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SET_EN_ASYNC_OUT = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL5_SET]
// perv/reg00030.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL7_SET]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_FSI = 0x00002927ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_FSI_BYTE = 0x00002c9cull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_WO_OR = 0x00050127ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM0_REFCLK_DRVR_EN_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM1_REFCLK_DRVR_EN_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM2_REFCLK_DRVR_EN_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM3_REFCLK_DRVR_EN_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM4_REFCLK_DRVR_EN_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM5_REFCLK_DRVR_EN_DC = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM6_REFCLK_DRVR_EN_DC = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM7_REFCLK_DRVR_EN_DC = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM8_REFCLK_DRVR_EN_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM9_REFCLK_DRVR_EN_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEMA_REFCLK_DRVR_EN_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEMB_REFCLK_DRVR_EN_DC = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEMC_REFCLK_DRVR_EN_DC = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEMD_REFCLK_DRVR_EN_DC = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEME_REFCLK_DRVR_EN_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEMF_REFCLK_DRVR_EN_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP0A_REFCLK_DRVR_EN_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP0B_REFCLK_DRVR_EN_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP3A_REFCLK_DRVR_EN_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP3B_REFCLK_DRVR_EN_DC = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP4_REFCLK_DRVR_EN_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP5_REFCLK_DRVR_EN_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP6_REFCLK_DRVR_EN_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_OP7_REFCLK_DRVR_EN_DC = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_SET_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL7_SET]
// perv/reg00030.H

//>> [FSXCOMP_FSXLOG_SCRATCH_REGISTER_9]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_9_FSI = 0x00002980ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_9_FSI_BYTE = 0x00002e00ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_9_RW = 0x00050180ull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_9_SR_SCRATCH_REGISTER_9 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_9_SR_SCRATCH_REGISTER_9_LEN = 32;
//<< [FSXCOMP_FSXLOG_SCRATCH_REGISTER_9]
// perv/reg00030.H

//>> [INTERRUPT_TYPE_REG]
static const uint64_t INTERRUPT_TYPE_REG = 0x000f001aull;

static const uint32_t INTERRUPT_TYPE_REG_ATTENTION = 0;
static const uint32_t INTERRUPT_TYPE_REG_RECOVERABLE_ERROR = 1;
static const uint32_t INTERRUPT_TYPE_REG_CHECKSTOP = 2;
//<< [INTERRUPT_TYPE_REG]
// perv/reg00030.H

//>> [P10_20_TIMEOUT_REG]
static const uint64_t TIMEOUT_REG = 0x000f0010ull; // p10:20,

static const uint32_t P10_20_TIMEOUT_REG_INT_TIMEOUT = 0;
static const uint32_t P10_20_TIMEOUT_REG_INT_TIMEOUT_LEN = 2;
//<< [P10_20_TIMEOUT_REG]
// perv/reg00031.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00030.H"
#include "perv/reg00031.H"
#endif
#endif
