/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_5.H $       */
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

#include "proc_scomt.H"

#ifndef __p10_scom_perv_5_H_
#define __p10_scom_perv_5_H_


namespace scomt
{
namespace perv
{


static const uint64_t COMP_INTR_INTERRUPT1_REG_RWX = 0x000f0020ull;
static const uint64_t COMP_INTR_INTERRUPT1_REG_WOX_AND = 0x000f0022ull;
static const uint64_t COMP_INTR_INTERRUPT1_REG_WOX_OR = 0x000f0021ull;

static const uint32_t COMP_INTR_INTERRUPT1_REG_INTERRUPT1 = 0;
static const uint32_t COMP_INTR_INTERRUPT1_REG_INTERRUPT1_LEN = 56;
// perv/reg00007.H

static const uint64_t COMP_INTR_INTERRUPT2_REG_RWX = 0x000f0023ull;
static const uint64_t COMP_INTR_INTERRUPT2_REG_WOX_AND = 0x000f0025ull;
static const uint64_t COMP_INTR_INTERRUPT2_REG_WOX_OR = 0x000f0024ull;

static const uint32_t COMP_INTR_INTERRUPT2_REG_INTERRUPT2 = 0;
static const uint32_t COMP_INTR_INTERRUPT2_REG_INTERRUPT2_LEN = 56;
// perv/reg00007.H

static const uint64_t COMP_INTR_INTERRUPT3_REG_RWX = 0x000f0026ull;
static const uint64_t COMP_INTR_INTERRUPT3_REG_WOX_AND = 0x000f0028ull;
static const uint64_t COMP_INTR_INTERRUPT3_REG_WOX_OR = 0x000f0027ull;

static const uint32_t COMP_INTR_INTERRUPT3_REG_INTERRUPT3 = 0;
static const uint32_t COMP_INTR_INTERRUPT3_REG_INTERRUPT3_LEN = 56;
// perv/reg00007.H

static const uint64_t COMP_INTR_INTERRUPT4_REG_RWX = 0x000f0029ull;
static const uint64_t COMP_INTR_INTERRUPT4_REG_WOX_AND = 0x000f002bull;
static const uint64_t COMP_INTR_INTERRUPT4_REG_WOX_OR = 0x000f002aull;

static const uint32_t COMP_INTR_INTERRUPT4_REG_INTERRUPT4 = 0;
static const uint32_t COMP_INTR_INTERRUPT4_REG_INTERRUPT4_LEN = 56;
// perv/reg00007.H

static const uint64_t COMP_INTR_INTERRUPT_TYPE_MASK_REG_RW = 0x000f002cull;
static const uint64_t COMP_INTR_INTERRUPT_TYPE_MASK_REG_RW_WAND = 0x000f002eull;
static const uint64_t COMP_INTR_INTERRUPT_TYPE_MASK_REG_RW_WOR = 0x000f002dull;

static const uint32_t COMP_INTR_INTERRUPT_TYPE_MASK_REG_GP = 0;
static const uint32_t COMP_INTR_INTERRUPT_TYPE_MASK_REG_CC = 1;
// perv/reg00007.H

static const uint64_t COMP_P_0_STAT_RDDAT_ERRES = 0x00030001ull;

static const uint32_t COMP_P_0_STAT_RDDAT_ERRES_CMD_PARITY_ERROR = 1;
static const uint32_t COMP_P_0_STAT_RDDAT_ERRES_WR_DATA_PARITY_ERROR = 2;
static const uint32_t COMP_P_0_STAT_RDDAT_ERRES_RD_DATA_PARITY_ERROR = 3;
static const uint32_t COMP_P_0_STAT_RDDAT_ERRES_LCK_STATUS_PARITY_ERROR = 4;
static const uint32_t COMP_P_0_STAT_RDDAT_ERRES_FSM_PARITY_ERROR = 5;
static const uint32_t COMP_P_0_STAT_RDDAT_ERRES_OPB_PARITY_ERROR = 8;
// perv/reg00007.H

static const uint64_t EPS_FIR_GXSTOP3_MASK_REG = 0x00040016ull;

static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP = 0;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV = 1;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN = 2;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP = 3;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4 = 4;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP = 5;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_OOB1 = 6;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// perv/reg00007.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA0 = 0x00050019ull;
// perv/reg00007.H

static const uint64_t EPS_THERM_WSUB_SKITTER_MODE_REG = 0x00050010ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE = 0;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_DISABLE_SKITTER_STICKINESS = 1;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL = 4;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL_LEN = 2;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL = 6;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL_LEN = 2;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS = 8;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS_LEN = 2;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE_WITH_TRIGGER = 44;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_DATA_V_LT = 45;
// perv/reg00007.H

static const uint64_t EPS_THERM_WSUB2_DTS_RESULT1 = 0x00050021ull;

static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT_LEN = 16;
// perv/reg00007.H

static const uint64_t ERROR_STATUS = 0x0003000full;

static const uint32_t ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR = 0;
static const uint32_t ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR = 1;
static const uint32_t ERROR_STATUS_PCB_PARITY_ON_CMD_ERR = 2;
static const uint32_t ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR = 3;
static const uint32_t ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR = 4;
static const uint32_t ERROR_STATUS_PCB_PARITY_ON_DATA_ERR = 5;
static const uint32_t ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR = 6;
static const uint32_t ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR = 7;
static const uint32_t ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR = 8;
static const uint32_t ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR = 9;
static const uint32_t ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR = 10;
static const uint32_t ERROR_STATUS_SCAN_COLLISION_ERR = 11;
static const uint32_t ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR = 12;
static const uint32_t ERROR_STATUS_OPCG_TRIGGER_ERR = 13;
static const uint32_t ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR = 14;
static const uint32_t ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR = 15;
static const uint32_t ERROR_STATUS_PARITY_ON_OPCG_SM_ERR = 16;
static const uint32_t ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR = 17;
static const uint32_t ERROR_STATUS_PARITY_ON_OPCG_REG_ERR = 18;
static const uint32_t ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR = 19;
static const uint32_t ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR = 20;
static const uint32_t ERROR_STATUS_PARITY_ON_GPIO_REG_ERR = 21;
static const uint32_t ERROR_STATUS_CLKCMD_REQUEST_ERR = 22;
static const uint32_t ERROR_STATUS_CBS_PROTOCOL_ERR = 23;
static const uint32_t ERROR_STATUS_VITL_ALIGN_ERR = 24;
static const uint32_t ERROR_STATUS_UNIT_SYNC_LVL_ERR = 25;
static const uint32_t ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR = 26;
static const uint32_t ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR = 27;
// perv/reg00007.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_1_RWX = 0x00002881ull;
// perv/reg00007.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_10_RWX = 0x0000288aull;
// perv/reg00007.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_7_RWX = 0x000028c7ull;
// perv/reg00007.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_14_RWX = 0x0000290eull;
// perv/reg00007.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_ROX = 0x00002830ull;

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_1 = 4;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_1 = 5;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_1 = 6;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_1 = 7;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_1 = 15;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_ILLEGAL_OPERATION_ATTEMPTED_2 = 20;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_WRITE_FULL_PIB_SLAVE_A_MAILBOX_ERROR_2 = 21;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_READ_EMPTY_PIB_SLAVE_A_MAILBOX_ERROR_2 = 22;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_PIB_SLAVE_A_RAM_PARITY_ERROR_DETECTED_2 = 23;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_ERROR_STATUS_CLEAR_STATUS_2 = 31;
// perv/reg00007.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_COPY_RW = 0x00002917ull;
// perv/reg00007.H

static const uint64_t L3TRA0_TR0_CONFIG_2 = 0x00018205ull;

static const uint32_t L3TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t L3TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t L3TRA0_TR0_CONFIG_2_B_LEN = 24;
// perv/reg00007.H

static const uint64_t L3TRA1_TR1_CONFIG_4 = 0x00018267ull;

static const uint32_t L3TRA1_TR1_CONFIG_4_A = 0;
static const uint32_t L3TRA1_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA1_TR1_CONFIG_4_B = 24;
static const uint32_t L3TRA1_TR1_CONFIG_4_B_LEN = 24;
// perv/reg00007.H

static const uint64_t L3TRA2_TR1_CONFIG_3 = 0x000182a6ull;

static const uint32_t L3TRA2_TR1_CONFIG_3_C = 0;
static const uint32_t L3TRA2_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA2_TR1_CONFIG_3_D = 24;
static const uint32_t L3TRA2_TR1_CONFIG_3_D_LEN = 24;
// perv/reg00007.H

static const uint64_t L3TRA3_TR0_CONFIG_5 = 0x000182c8ull;

static const uint32_t L3TRA3_TR0_CONFIG_5_C = 0;
static const uint32_t L3TRA3_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA3_TR0_CONFIG_5_D = 24;
static const uint32_t L3TRA3_TR0_CONFIG_5_D_LEN = 24;
// perv/reg00007.H

static const uint64_t NET_CTRL1_RWX = 0x000f0044ull;
static const uint64_t NET_CTRL1_RWX_WAND = 0x000f0045ull;
static const uint64_t NET_CTRL1_RWX_WOR = 0x000f0046ull;

static const uint32_t NET_CTRL1_PLL_CLKIN_SEL = 0;
static const uint32_t NET_CTRL1_CLK_DCC_BYPASS_EN = 1;
static const uint32_t NET_CTRL1_CLK_PDLY_BYPASS_EN = 2;
static const uint32_t NET_CTRL1_CLK_DIV_BYPASS_EN = 3;
static const uint32_t NET_CTRL1_REFCLK_CLKMUX0_SEL = 4;
static const uint32_t NET_CTRL1_REFCLK_CLKMUX1_SEL = 5;
static const uint32_t NET_CTRL1_PLL_BNDY_BYPASS_EN = 6;
static const uint32_t NET_CTRL1_DPLL_TEST_SEL = 8;
static const uint32_t NET_CTRL1_DPLL_TEST_SEL_LEN = 8;
static const uint32_t NET_CTRL1_SB_STRENGTH = 16;
static const uint32_t NET_CTRL1_SB_STRENGTH_LEN = 4;
static const uint32_t NET_CTRL1_ASYNC_TYPE = 20;
static const uint32_t NET_CTRL1_ASYNC_OBS = 21;
static const uint32_t NET_CTRL1_CPM_CAL_SET = 22;
static const uint32_t NET_CTRL1_SENSEADJ_RESET0 = 23;
static const uint32_t NET_CTRL1_SENSEADJ_RESET1 = 24;
static const uint32_t NET_CTRL1_CLK_PULSE_EN = 25;
static const uint32_t NET_CTRL1_CLK_PULSE_MODE = 26;
static const uint32_t NET_CTRL1_CLK_PULSE_MODE_LEN = 2;
// perv/reg00007.H

static const uint64_t OTPC_M_MEASURE_REG10 = 0x0001001aull;

static const uint32_t OTPC_M_MEASURE_REG10_SEEPROM_MEASUREMENT10_DATA = 0;
static const uint32_t OTPC_M_MEASURE_REG10_SEEPROM_MEASUREMENT10_DATA_LEN = 64;
// perv/reg00007.H

static const uint64_t REC_ERR_MST3_REG3 = 0x000f004full;

static const uint32_t REC_ERR_MST3_REG3_48_MST3_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST3_REG3_48_MST3_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST3_REG3_48_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_49_MST3_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST3_REG3_49_MST3_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST3_REG3_49_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_50_MST3_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST3_REG3_50_MST3_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST3_REG3_50_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_51_MST3_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST3_REG3_51_MST3_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST3_REG3_51_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_52_MST3_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST3_REG3_52_MST3_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST3_REG3_52_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_53_MST3_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST3_REG3_53_MST3_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST3_REG3_53_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_54_MST3_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST3_REG3_54_MST3_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST3_REG3_54_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_55_MST3_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST3_REG3_55_MST3_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST3_REG3_55_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_56_MST3_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST3_REG3_56_MST3_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST3_REG3_56_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_57_MST3_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST3_REG3_57_MST3_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST3_REG3_57_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_58_MST3_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST3_REG3_58_MST3_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST3_REG3_58_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_59_MST3_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST3_REG3_59_MST3_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST3_REG3_59_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_60_MST3_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST3_REG3_60_MST3_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST3_REG3_60_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_61_MST3_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST3_REG3_61_MST3_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST3_REG3_61_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_62_MST3_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST3_REG3_62_MST3_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST3_REG3_62_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG3_63_MST3_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST3_REG3_63_MST3_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST3_REG3_63_MST3_ERROR_CODE_LEN = 3;
// perv/reg00007.H

static const uint64_t REC_ERR_MST7_REG2 = 0x000f005eull;

static const uint32_t REC_ERR_MST7_REG2_32_MST7_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST7_REG2_32_MST7_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST7_REG2_32_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_33_MST7_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST7_REG2_33_MST7_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST7_REG2_33_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_34_MST7_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST7_REG2_34_MST7_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST7_REG2_34_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_35_MST7_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST7_REG2_35_MST7_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST7_REG2_35_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_36_MST7_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST7_REG2_36_MST7_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST7_REG2_36_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_37_MST7_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST7_REG2_37_MST7_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST7_REG2_37_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_38_MST7_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST7_REG2_38_MST7_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST7_REG2_38_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_39_MST7_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST7_REG2_39_MST7_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST7_REG2_39_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_40_MST7_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST7_REG2_40_MST7_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST7_REG2_40_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_41_MST7_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST7_REG2_41_MST7_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST7_REG2_41_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_42_MST7_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST7_REG2_42_MST7_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST7_REG2_42_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_43_MST7_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST7_REG2_43_MST7_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST7_REG2_43_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_44_MST7_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST7_REG2_44_MST7_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST7_REG2_44_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_45_MST7_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST7_REG2_45_MST7_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST7_REG2_45_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_46_MST7_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST7_REG2_46_MST7_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST7_REG2_46_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG2_47_MST7_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST7_REG2_47_MST7_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST7_REG2_47_MST7_ERROR_CODE_LEN = 3;
// perv/reg00007.H

static const uint64_t REC_ERR_MST9_REG2 = 0x000f0066ull;

static const uint32_t REC_ERR_MST9_REG2_32_MST9_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST9_REG2_32_MST9_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST9_REG2_32_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_33_MST9_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST9_REG2_33_MST9_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST9_REG2_33_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_34_MST9_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST9_REG2_34_MST9_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST9_REG2_34_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_35_MST9_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST9_REG2_35_MST9_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST9_REG2_35_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_36_MST9_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST9_REG2_36_MST9_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST9_REG2_36_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_37_MST9_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST9_REG2_37_MST9_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST9_REG2_37_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_38_MST9_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST9_REG2_38_MST9_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST9_REG2_38_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_39_MST9_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST9_REG2_39_MST9_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST9_REG2_39_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_40_MST9_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST9_REG2_40_MST9_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST9_REG2_40_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_41_MST9_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST9_REG2_41_MST9_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST9_REG2_41_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_42_MST9_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST9_REG2_42_MST9_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST9_REG2_42_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_43_MST9_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST9_REG2_43_MST9_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST9_REG2_43_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_44_MST9_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST9_REG2_44_MST9_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST9_REG2_44_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_45_MST9_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST9_REG2_45_MST9_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST9_REG2_45_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_46_MST9_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST9_REG2_46_MST9_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST9_REG2_46_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG2_47_MST9_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST9_REG2_47_MST9_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST9_REG2_47_MST9_ERROR_CODE_LEN = 3;
// perv/reg00007.H

static const uint64_t SCAN_LONG_ROTATE = 0x00039000ull;
// perv/reg00007.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG109 = 0x0000806dull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG109_REGISTER109 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG109_REGISTER109_LEN = 64;
// perv/reg00007.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG116 = 0x00008074ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG116_REGISTER116 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG116_REGISTER116_LEN = 64;
// perv/reg00007.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG121 = 0x00008079ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG121_REGISTER121 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG121_REGISTER121_LEN = 64;
// perv/reg00007.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG18 = 0x00008012ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG18_REGISTER18 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG18_REGISTER18_LEN = 64;
// perv/reg00007.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG30 = 0x0000801eull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG30_REGISTER30 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG30_REGISTER30_LEN = 64;
// perv/reg00007.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG51 = 0x00008033ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG51_REGISTER51 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG51_REGISTER51_LEN = 64;
// perv/reg00007.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG66 = 0x00008042ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG66_REGISTER66 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG66_REGISTER66_LEN = 64;
// perv/reg00007.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG79 = 0x0000804full;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG79_REGISTER79 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG79_REGISTER79_LEN = 64;
// perv/reg00007.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG8 = 0x00008008ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG8_REGISTER8 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG8_REGISTER8_LEN = 64;
// perv/reg00007.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG93 = 0x0000805dull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG93_REGISTER93 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG93_REGISTER93_LEN = 64;
// perv/reg00007.H

static const uint64_t TOD_START_REG = 0x00040022ull;

static const uint32_t TOD_START_REG_FSM_START_TOD_TRIGGER = 0;
static const uint32_t TOD_START_REG_REG_0X22_SPARE_01 = 1;
static const uint32_t TOD_START_REG_FSM_START_TOD_DATA02 = 2;
static const uint32_t TOD_START_REG_REG_0X22_SPARE_03_07 = 3;
static const uint32_t TOD_START_REG_REG_0X22_SPARE_03_07_LEN = 5;
// perv/reg00007.H

static const uint64_t TRA0_TR0_CONFIG_2 = 0x00010405ull;

static const uint32_t TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t TRA0_TR0_CONFIG_2_B_LEN = 24;
// perv/reg00007.H

static const uint64_t TRA1_TR0_TRACE_HI_DATA_REG = 0x00010480ull;

static const uint32_t TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00007.H

static const uint64_t TRA1_TR1_CONFIG_4 = 0x000104c7ull;

static const uint32_t TRA1_TR1_CONFIG_4_A = 0;
static const uint32_t TRA1_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TRA1_TR1_CONFIG_4_B = 24;
static const uint32_t TRA1_TR1_CONFIG_4_B_LEN = 24;
// perv/reg00007.H

static const uint64_t TRA2_TR0_CONFIG = 0x00010502ull;

static const uint32_t TRA2_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA2_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA2_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA2_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TRA2_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA2_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA2_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA2_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// perv/reg00007.H

static const uint64_t TRA2_TR1_TRACE_LO_DATA_REG = 0x00010541ull;

static const uint32_t TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA2_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA2_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00007.H

static const uint64_t TRA2_TR1_CONFIG_3 = 0x00010546ull;

static const uint32_t TRA2_TR1_CONFIG_3_C = 0;
static const uint32_t TRA2_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TRA2_TR1_CONFIG_3_D = 24;
static const uint32_t TRA2_TR1_CONFIG_3_D_LEN = 24;
// perv/reg00007.H

static const uint64_t TRA3_TR0_CONFIG_5 = 0x00010588ull;

static const uint32_t TRA3_TR0_CONFIG_5_C = 0;
static const uint32_t TRA3_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA3_TR0_CONFIG_5_D = 24;
static const uint32_t TRA3_TR0_CONFIG_5_D_LEN = 24;
// perv/reg00007.H

static const uint64_t TRA3_TR1_CONFIG = 0x000105c2ull;

static const uint32_t TRA3_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA3_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA3_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA3_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA3_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TRA3_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA3_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA3_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA3_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA3_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// perv/reg00007.H

static const uint64_t TRA4_TR0_CONFIG_4 = 0x00010607ull;

static const uint32_t TRA4_TR0_CONFIG_4_A = 0;
static const uint32_t TRA4_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TRA4_TR0_CONFIG_4_B = 24;
static const uint32_t TRA4_TR0_CONFIG_4_B_LEN = 24;
// perv/reg00007.H

static const uint64_t TRA5_TR1_CONFIG_2 = 0x000106c5ull;

static const uint32_t TRA5_TR1_CONFIG_2_A = 0;
static const uint32_t TRA5_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TRA5_TR1_CONFIG_2_B = 24;
static const uint32_t TRA5_TR1_CONFIG_2_B_LEN = 24;
// perv/reg00007.H

static const uint64_t TRA6_TR1_CONFIG_5 = 0x00010748ull;

static const uint32_t TRA6_TR1_CONFIG_5_C = 0;
static const uint32_t TRA6_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TRA6_TR1_CONFIG_5_D = 24;
static const uint32_t TRA6_TR1_CONFIG_5_D_LEN = 24;
// perv/reg00007.H

static const uint64_t TRA7_TR0_CONFIG_3 = 0x00010786ull;

static const uint32_t TRA7_TR0_CONFIG_3_C = 0;
static const uint32_t TRA7_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA7_TR0_CONFIG_3_D = 24;
static const uint32_t TRA7_TR0_CONFIG_3_D_LEN = 24;
// perv/reg00007.H

}
}
#include "perv/reg00007.H"
#endif
