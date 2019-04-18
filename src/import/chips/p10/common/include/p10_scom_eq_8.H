/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_8.H $         */
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

#ifndef __p10_scom_eq_8_H_
#define __p10_scom_eq_8_H_


namespace scomt
{
namespace eq
{


static const uint64_t ASSIST_INTERRUPT_REG = 0x200f0011ull;
// eq/reg00024.H

static const uint64_t EDRAM_STATUS = 0x200f0029ull;

static const uint32_t EDRAM_STATUS_EDRAM_STAT = 0;
static const uint32_t EDRAM_STATUS_EDRAM_STAT_LEN = 4;
// eq/reg00024.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t EPS_DBG_TRACE_REG_0 = 0x200183edull;

static const uint32_t EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// eq/reg00024.H

static const uint64_t EPS_FIR_GXSTOP1_MASK_REG = 0x20040014ull;

static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP = 0;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV = 1;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN = 2;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP = 3;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4 = 4;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP = 5;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_OOB1 = 6;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// eq/reg00024.H

static const uint64_t EPS_FIR_LOCAL_ACTION0 = 0x20040010ull;

static const uint32_t EPS_FIR_LOCAL_ACTION0_00 = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION0_01 = 1;
static const uint32_t EPS_FIR_LOCAL_ACTION0_02 = 2;
static const uint32_t EPS_FIR_LOCAL_ACTION0_03 = 3;
static const uint32_t EPS_FIR_LOCAL_ACTION0_04 = 4;
static const uint32_t EPS_FIR_LOCAL_ACTION0_05 = 5;
static const uint32_t EPS_FIR_LOCAL_ACTION0_06 = 6;
static const uint32_t EPS_FIR_LOCAL_ACTION0_07 = 7;
static const uint32_t EPS_FIR_LOCAL_ACTION0_08 = 8;
static const uint32_t EPS_FIR_LOCAL_ACTION0_09 = 9;
static const uint32_t EPS_FIR_LOCAL_ACTION0_10 = 10;
static const uint32_t EPS_FIR_LOCAL_ACTION0_11 = 11;
static const uint32_t EPS_FIR_LOCAL_ACTION0_12 = 12;
static const uint32_t EPS_FIR_LOCAL_ACTION0_13 = 13;
static const uint32_t EPS_FIR_LOCAL_ACTION0_14 = 14;
static const uint32_t EPS_FIR_LOCAL_ACTION0_15 = 15;
static const uint32_t EPS_FIR_LOCAL_ACTION0_16 = 16;
static const uint32_t EPS_FIR_LOCAL_ACTION0_17 = 17;
static const uint32_t EPS_FIR_LOCAL_ACTION0_18 = 18;
static const uint32_t EPS_FIR_LOCAL_ACTION0_19 = 19;
static const uint32_t EPS_FIR_LOCAL_ACTION0_20 = 20;
static const uint32_t EPS_FIR_LOCAL_ACTION0_21 = 21;
static const uint32_t EPS_FIR_LOCAL_ACTION0_22 = 22;
static const uint32_t EPS_FIR_LOCAL_ACTION0_23 = 23;
static const uint32_t EPS_FIR_LOCAL_ACTION0_24 = 24;
static const uint32_t EPS_FIR_LOCAL_ACTION0_25 = 25;
static const uint32_t EPS_FIR_LOCAL_ACTION0_26 = 26;
static const uint32_t EPS_FIR_LOCAL_ACTION0_27 = 27;
static const uint32_t EPS_FIR_LOCAL_ACTION0_28 = 28;
static const uint32_t EPS_FIR_LOCAL_ACTION0_29 = 29;
static const uint32_t EPS_FIR_LOCAL_ACTION0_30 = 30;
static const uint32_t EPS_FIR_LOCAL_ACTION0_31 = 31;
static const uint32_t EPS_FIR_LOCAL_ACTION0_32 = 32;
static const uint32_t EPS_FIR_LOCAL_ACTION0_33 = 33;
static const uint32_t EPS_FIR_LOCAL_ACTION0_34 = 34;
static const uint32_t EPS_FIR_LOCAL_ACTION0_35 = 35;
static const uint32_t EPS_FIR_LOCAL_ACTION0_36 = 36;
static const uint32_t EPS_FIR_LOCAL_ACTION0_37 = 37;
static const uint32_t EPS_FIR_LOCAL_ACTION0_38 = 38;
static const uint32_t EPS_FIR_LOCAL_ACTION0_39 = 39;
static const uint32_t EPS_FIR_LOCAL_ACTION0_40 = 40;
static const uint32_t EPS_FIR_LOCAL_ACTION0_41 = 41;
static const uint32_t EPS_FIR_LOCAL_ACTION0_42 = 42;
static const uint32_t EPS_FIR_LOCAL_ACTION0_43 = 43;
static const uint32_t EPS_FIR_LOCAL_ACTION0_44 = 44;
static const uint32_t EPS_FIR_LOCAL_ACTION0_45 = 45;
static const uint32_t EPS_FIR_LOCAL_ACTION0_46 = 46;
static const uint32_t EPS_FIR_LOCAL_ACTION0_47 = 47;
static const uint32_t EPS_FIR_LOCAL_ACTION0_48 = 48;
// eq/reg00024.H

static const uint64_t ERROR_REG = 0x200f001full;

static const uint32_t ERROR_REG_CE_ERROR = 0;
static const uint32_t ERROR_REG_CHIPLET_ERRORS = 1;
static const uint32_t ERROR_REG_CHIPLET_ERRORS_LEN = 3;
static const uint32_t ERROR_REG_PARITY_ERROR = 4;
static const uint32_t ERROR_REG_DATA_BUFFER_ERROR = 5;
static const uint32_t ERROR_REG_ADDR_BUFFER_ERROR = 6;
static const uint32_t ERROR_REG_PCB_FSM_ERROR = 7;
static const uint32_t ERROR_REG_CL_FSM_ERROR = 8;
static const uint32_t ERROR_REG_INT_RX_FSM_ERROR = 9;
static const uint32_t ERROR_REG_INT_TX_FSM_ERROR = 10;
static const uint32_t ERROR_REG_INT_TYPE_ERROR = 11;
static const uint32_t ERROR_REG_CL_DATA_ERROR = 12;
static const uint32_t ERROR_REG_INFO_ERROR = 13;
static const uint32_t ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR = 15;
static const uint32_t ERROR_REG_PCB_INTERFACE_ERROR = 16;
static const uint32_t ERROR_REG_CHIPLET_OFFLINE = 17;
static const uint32_t ERROR_REG_EDRAM_SEQUENCE_ERR = 18;
static const uint32_t ERROR_REG_CTRL_REG_PARITY_ERROR = 19;
static const uint32_t ERROR_REG_ADDRESS_REG_PARITY_ERROR = 20;
static const uint32_t ERROR_REG_TIMEOUT_REG_PARITY_ERROR = 21;
static const uint32_t ERROR_REG_CONFIG_REG_PARITY_ERROR = 22;
static const uint32_t ERROR_REG_DIV_REG_PARITY_ERROR = 23;
static const uint32_t ERROR_REG_PLL_UNLOCK_ERROR = 24;
static const uint32_t ERROR_REG_PLL_UNLOCK_ERROR_LEN = 8;
// eq/reg00024.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA1_TR0_CONFIG_0 = 0x20018243ull;

static const uint32_t L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// eq/reg00024.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA1_TR1_CONFIG_9 = 0x20018269ull;

static const uint32_t L3TRA1_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA1_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA1_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA1_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA1_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA1_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// eq/reg00024.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA3_TR1_CONFIG_1 = 0x200182e4ull;

static const uint32_t L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// eq/reg00024.H

static const uint64_t OPCG_REG0 = 0x20030002ull;

static const uint32_t OPCG_REG0_RUNN_MODE = 0;
static const uint32_t OPCG_REG0_OPCG_GO = 1;
static const uint32_t OPCG_REG0_RUN_SCAN0 = 2;
static const uint32_t OPCG_REG0_SCAN0_MODE = 3;
static const uint32_t OPCG_REG0_OPCG_IN_SLAVE_MODE = 4;
static const uint32_t OPCG_REG0_OPCG_IN_MASTER_MODE = 5;
static const uint32_t OPCG_REG0_KEEP_MS_MODE = 6;
static const uint32_t OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL = 7;
static const uint32_t OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL = 8;
static const uint32_t OPCG_REG0_RUN_OPCG_ON_UPDATE_DR = 11;
static const uint32_t OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR = 12;
static const uint32_t OPCG_REG0_STOP_RUNN_ON_XSTOP = 13;
static const uint32_t OPCG_REG0_OPCG_STARTS_BIST = 14;
static const uint32_t OPCG_REG0_LOOP_COUNT = 21;
static const uint32_t OPCG_REG0_LOOP_COUNT_LEN = 43;
// eq/reg00024.H

static const uint64_t QME_DORP = 0x200e0254ull;

static const uint32_t QME_DORP_QUOTIENT = 0;
static const uint32_t QME_DORP_QUOTIENT_LEN = 32;
static const uint32_t QME_DORP_REMAINDER = 32;
static const uint32_t QME_DORP_REMAINDER_LEN = 32;
// eq/reg00024.H

static const uint64_t QME_RVCR = 0x200e0084ull;

static const uint32_t QME_RVCR_QME_RVCR_RVID_VALUE = 1;
static const uint32_t QME_RVCR_QME_RVCR_RVID_VALUE_LEN = 7;
// eq/reg00024.H

static const uint64_t QME_SCOM_XIRAMRA = 0x200e0204ull;
// eq/reg00024.H

static const uint64_t QME_SCOM_XIVDR28 = 0x200e0298ull;

static const uint32_t QME_SCOM_XIVDR28_8 = 0;
static const uint32_t QME_SCOM_XIVDR28_8_LEN = 32;
static const uint32_t QME_SCOM_XIVDR28_9 = 32;
static const uint32_t QME_SCOM_XIVDR28_9_LEN = 32;
// eq/reg00024.H

static const uint64_t QME_SCOM_XIVDR8 = 0x200e0290ull;

static const uint32_t QME_SCOM_XIVDR8_8 = 0;
static const uint32_t QME_SCOM_XIVDR8_8_LEN = 32;
static const uint32_t QME_SCOM_XIVDR8_9 = 32;
static const uint32_t QME_SCOM_XIVDR8_9_LEN = 32;
// eq/reg00024.H

static const uint64_t QME_SCRA_RW = 0x200e0124ull;
static const uint64_t QME_SCRA_WO_CLEAR = 0x200e0127ull;
static const uint64_t QME_SCRA_WO_OR = 0x200e0126ull;

static const uint32_t QME_SCRA_QME_SCRA_DATA = 0;
static const uint32_t QME_SCRA_QME_SCRA_DATA_LEN = 32;
// eq/reg00024.H

static const uint64_t SCAN_CAPTUREDR_LONG = 0x2003d000ull;
// eq/reg00024.H

static const uint64_t SCAN_REGION_TYPE = 0x20030005ull;

static const uint32_t SCAN_REGION_TYPE_SYSTEM_FAST_INIT = 0;
static const uint32_t SCAN_REGION_TYPE_PARALLEL_SCAN = 1;
static const uint32_t SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR = 2;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_VITL = 3;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_PERV = 4;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT1 = 5;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT2 = 6;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT3 = 7;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT4 = 8;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT5 = 9;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT6 = 10;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT7 = 11;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT8 = 12;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT9 = 13;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT10 = 14;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT11 = 15;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT12 = 16;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT13 = 17;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT14 = 18;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_FUNC = 48;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_CFG = 49;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR = 50;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_REGF = 51;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_LBIST = 52;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_ABIST = 53;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_REPR = 54;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_TIME = 55;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_BNDY = 56;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_FARR = 57;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_CMSK = 58;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_INEX = 59;
// eq/reg00024.H

static const uint64_t XSTOP3 = 0x2003000eull;

static const uint32_t XSTOP3_XSTOP3_MASK_B = 0;
static const uint32_t XSTOP3_ALIGNED_XSTOP3 = 1;
static const uint32_t XSTOP3_TRIGGER_OPCG_ON_XSTOP3 = 2;
static const uint32_t XSTOP3_XSTOP3_WAIT_ALLWAYS = 3;
static const uint32_t XSTOP3_XSTOP3_PERV = 4;
static const uint32_t XSTOP3_XSTOP3_UNIT1 = 5;
static const uint32_t XSTOP3_XSTOP3_UNIT2 = 6;
static const uint32_t XSTOP3_XSTOP3_UNIT3 = 7;
static const uint32_t XSTOP3_XSTOP3_UNIT4 = 8;
static const uint32_t XSTOP3_XSTOP3_UNIT5 = 9;
static const uint32_t XSTOP3_XSTOP3_UNIT6 = 10;
static const uint32_t XSTOP3_XSTOP3_UNIT7 = 11;
static const uint32_t XSTOP3_XSTOP3_UNIT8 = 12;
static const uint32_t XSTOP3_XSTOP3_UNIT9 = 13;
static const uint32_t XSTOP3_XSTOP3_UNIT10 = 14;
static const uint32_t XSTOP3_XSTOP3_UNIT11 = 15;
static const uint32_t XSTOP3_XSTOP3_UNIT12 = 16;
static const uint32_t XSTOP3_XSTOP3_UNIT13 = 17;
static const uint32_t XSTOP3_XSTOP3_UNIT14 = 18;
static const uint32_t XSTOP3_XSTOP3_WAIT_CYCLES = 48;
static const uint32_t XSTOP3_XSTOP3_WAIT_CYCLES_LEN = 12;
// eq/reg00024.H

}
}
#include "eq/reg00024.H"
#endif
