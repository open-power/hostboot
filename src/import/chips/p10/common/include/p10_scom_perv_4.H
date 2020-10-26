/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_4.H $       */
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

#ifndef __p10_scom_perv_4_H_
#define __p10_scom_perv_4_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> [CLOCK_STAT_ARY]
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
//<< [CLOCK_STAT_ARY]
// perv/reg00008.H

//>> [FSXCOMP_FSXLOG_PERV_CTRL1]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_FSI = 0x0000281bull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_FSI_BYTE = 0x0000286cull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_RW = 0x0005001bull;

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_0_RESERVED = 0;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED = 3;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_3_15_RESERVED_LEN = 13;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_TP_SEC_BUF_DRV_STRENGTH_DC_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED = 20;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_PERV_CTRL1_20_31_RESERVED_LEN = 12;
//<< [FSXCOMP_FSXLOG_PERV_CTRL1]
// perv/reg00008.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI = 0x00002934ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_FSI_BYTE = 0x00002cd0ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_WO_CLEAR = 0x00050134ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_TOD_LPC_MUX_SEL_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_18_SPARE = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_19_SPARE = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX1_CLKIN_SEL_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2A_CLKIN_SEL_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX2B_CLKIN_SEL_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX3_CLKIN_SEL_DC = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_MUX4A_CLKIN_SEL_DC = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_AN_NEST_DIV2_ASYNC_RESET_DC = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TPFSI_ALTREFCLK_SEL = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_28_SPARE = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_TP_PLL_FORCE_OUT_EN_DC = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_DPLL_FREEZE_DC = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR_ROOT_CTRL4_31_SPARE = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL4_CLEAR]
// perv/reg00008.H

//>> [FSXCOMP_FSXLOG_SCRATCH_REGISTER_5]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI = 0x0000283cull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI_BYTE = 0x000028f0ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_RW = 0x0005003cull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_SR_SCRATCH_REGISTER_5_LEN = 32;
//<< [FSXCOMP_FSXLOG_SCRATCH_REGISTER_5]
// perv/reg00008.H

//>> [OPCG_REG2]
static const uint64_t OPCG_REG2 = 0x00030004ull;

static const uint32_t OPCG_REG2_OPCG_GO2 = 0;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING = 1;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING_LEN = 3;
static const uint32_t OPCG_REG2_PRPG_SEED = 4;
static const uint32_t OPCG_REG2_PRPG_SEED_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_A_VAL = 16;
static const uint32_t OPCG_REG2_PRPG_A_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_B_VAL = 28;
static const uint32_t OPCG_REG2_PRPG_B_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_MODE = 40;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM = 48;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM_LEN = 4;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK = 52;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK_LEN = 4;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT = 56;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE = 57;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE = 58;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE = 59;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT = 60;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT_LEN = 4;
//<< [OPCG_REG2]
// perv/reg00008.H

//>> [TOD_LOAD_MOD_REG]
static const uint64_t TOD_LOAD_MOD_REG = 0x00040018ull;

static const uint32_t TOD_LOAD_MOD_REG_TRIGGER = 0;
static const uint32_t TOD_LOAD_MOD_REG_SYNC_ENABLE = 1;
//<< [TOD_LOAD_MOD_REG]
// perv/reg00009.H

//>> [TOD_M_PATH_CTRL_REG]
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
//<< [TOD_M_PATH_CTRL_REG]
// perv/reg00009.H

//>> [TOD_TIMER_REG]
static const uint64_t TOD_TIMER_REG = 0x0004000dull;

static const uint32_t TOD_TIMER_REG_VALUE = 0;
static const uint32_t TOD_TIMER_REG_VALUE_LEN = 60;
static const uint32_t TOD_TIMER_REG_ENABLE0 = 60;
static const uint32_t TOD_TIMER_REG_ENABLE1 = 61;
static const uint32_t TOD_TIMER_REG_STATUS0 = 62;
static const uint32_t TOD_TIMER_REG_STATUS1 = 63;
//<< [TOD_TIMER_REG]
// perv/reg00009.H

//>> [TRA0_TR0_TRACE_LO_DATA_REG]
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
//<< [TRA0_TR0_TRACE_LO_DATA_REG]
// perv/reg00009.H

//>> [MCAST_GRP_0_SLAVES_REG]
static const uint64_t MCAST_GRP_0_SLAVES_REG = 0x000f0000ull;

static const uint32_t MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0 = 0;
static const uint32_t MCAST_GRP_0_SLAVES_REG_SLAVES_MCAST_GROUP_0_LEN = 6;
//<< [MCAST_GRP_0_SLAVES_REG]
// perv/reg00008.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL1]
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
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_10_SPARE = 10;
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
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TPM_DI1_DC_B = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_23_SPARE_TEST = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TP_TEST_BURNIN_MODE_DC = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_ARRAY_SET_VBL_TO_VDD_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_TPFSI_TP_GLB_PERST_OVR_DC = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_27_SPARE = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_28_SPARE_TEST_CONTROL = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_29_SPARE_TEST_CONTROL = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_30_SPARE_TEST_CONTROL = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_ROOT_CTRL1_31_SPARE_TEST_CONTROL = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL1]
// perv/reg00008.H

//>> [REC_ERR_REG2]
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
//<< [REC_ERR_REG2]
// perv/reg00008.H

//>> [XSTOP1]
static const uint64_t XSTOP1 = 0x0003000cull;

static const uint32_t XSTOP1_ENABLE = 0;
static const uint32_t XSTOP1_WAIT_SNOPA = 1;
static const uint32_t XSTOP1_TRIGGER_OPCG_GO = 2;
static const uint32_t XSTOP1_WAIT_ALWAYS = 3;
static const uint32_t XSTOP1_REGION_PERV = 4;
static const uint32_t XSTOP1_REGION_UNIT1 = 5;
static const uint32_t XSTOP1_REGION_UNIT2 = 6;
static const uint32_t XSTOP1_REGION_UNIT3 = 7;
static const uint32_t XSTOP1_REGION_UNIT4 = 8;
static const uint32_t XSTOP1_REGION_UNIT5 = 9;
static const uint32_t XSTOP1_REGION_UNIT6 = 10;
static const uint32_t XSTOP1_REGION_UNIT7 = 11;
static const uint32_t XSTOP1_REGION_UNIT8 = 12;
static const uint32_t XSTOP1_REGION_UNIT9 = 13;
static const uint32_t XSTOP1_REGION_UNIT10 = 14;
static const uint32_t XSTOP1_REGION_UNIT11 = 15;
static const uint32_t XSTOP1_REGION_UNIT12 = 16;
static const uint32_t XSTOP1_REGION_UNIT13 = 17;
static const uint32_t XSTOP1_REGION_UNIT14 = 18;
static const uint32_t XSTOP1_WAIT_CYCLES = 48;
static const uint32_t XSTOP1_WAIT_CYCLES_LEN = 12;
//<< [XSTOP1]
// perv/reg00009.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00008.H"
#include "perv/reg00009.H"
#endif
#endif
