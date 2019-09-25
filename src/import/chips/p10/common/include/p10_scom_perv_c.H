/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_c.H $       */
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

#ifndef __p10_scom_perv_c_H_
#define __p10_scom_perv_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC = 0x0001832full;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT = 0;
// perv/reg00024.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_DCC_OVERRIDE = 0x00014306ull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_DCC_OVERRIDE_ENABLE = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_DCC_OVERRIDE_VALUE = 4;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_DCC_OVERRIDE_VALUE_LEN = 8;
// perv/reg00024.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_DCC_TARGET = 0x00014308ull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE_LEN = 7;
// perv/reg00024.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SOFT_RESET = 0x00012305ull;
// perv/reg00024.H

static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_INIT_MODE = 0x00012320ull;
// perv/reg00024.H

static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SINGLE_STEP_MODE = 0x00012324ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SINGLE_STEP_MODE_STEP_COUNT = 0;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SINGLE_STEP_MODE_STEP_COUNT_LEN = 32;
// perv/reg00024.H

static const uint64_t CLK_ADJ_03_DCADJ_WRAP_PHASE_MEASUREMENT = 0x00011318ull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL = 1;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL_LEN = 7;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL = 8;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL = 9;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL_LEN = 7;
// perv/reg00024.H

static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES = 0x0001133aull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_0 = 2;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_0_LEN = 6;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_1 = 10;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_1_LEN = 6;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_2 = 18;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_2_LEN = 6;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_3 = 26;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CORE_PDLY_FSM_STATES_3_LEN = 6;
// perv/reg00024.H

static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_CHICKEN_SWITCHES = 0x00011335ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_CHICKEN_SWITCHES_STOP_ON_ERROR = 0;
// perv/reg00024.H

static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_IGNORE_CNT = 0x00011329ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_IGNORE_CNT_IGNORE_CNT_VALUE = 0;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_IGNORE_CNT_IGNORE_CNT_VALUE_LEN = 3;
// perv/reg00024.H

static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS = 0x0001132cull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CORE_PDLYS_CORE_PDLYS_INVERT = 0;
// perv/reg00024.H

static const uint64_t CPLT_CTRL2_RW = 0x00000002ull;
static const uint64_t CPLT_CTRL2_WO_CLEAR = 0x00000022ull;
static const uint64_t CPLT_CTRL2_WO_OR = 0x00000012ull;

static const uint32_t CPLT_CTRL2_0_PGOOD = 4;
static const uint32_t CPLT_CTRL2_1_PGOOD = 5;
static const uint32_t CPLT_CTRL2_2_PGOOD = 6;
static const uint32_t CPLT_CTRL2_3_PGOOD = 7;
static const uint32_t CPLT_CTRL2_4_PGOOD = 8;
static const uint32_t CPLT_CTRL2_5_PGOOD = 9;
static const uint32_t CPLT_CTRL2_6_PGOOD = 10;
static const uint32_t CPLT_CTRL2_7_PGOOD = 11;
static const uint32_t CPLT_CTRL2_8_PGOOD = 12;
static const uint32_t CPLT_CTRL2_9_PGOOD = 13;
static const uint32_t CPLT_CTRL2_10_PGOOD = 14;
static const uint32_t CPLT_CTRL2_11_PGOOD = 15;
static const uint32_t CPLT_CTRL2_12_PGOOD = 16;
static const uint32_t CPLT_CTRL2_13_PGOOD = 17;
static const uint32_t CPLT_CTRL2_14_PGOOD = 18;
// perv/reg00024.H

static const uint64_t CPLT_MASK0 = 0x00000101ull;

static const uint32_t CPLT_MASK0_ITR_MASK = 0;
static const uint32_t CPLT_MASK0_ITR_MASK_LEN = 32;
// perv/reg00024.H

static const uint64_t CTRL_PROTECT_MODE_REG = 0x000003feull;

static const uint32_t CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// perv/reg00024.H

static const uint64_t EPS_DBG_MODE_REG = 0x000107c0ull;

static const uint32_t EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION = 11;
static const uint32_t EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 12;
static const uint32_t EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE = 13;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_ON = 16;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_UNUSED = 26;
static const uint32_t EPS_DBG_MODE_REG_UNUSED_LEN = 6;
// perv/reg00024.H

static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5 = 0x00040085ull;

static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR = 0;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR = 1;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR = 2;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR = 3;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR = 4;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR = 5;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR = 6;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR = 7;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// perv/reg00024.H

static const uint64_t EPS_PSC_WRITE_PROTECT_ENABLE_REG = 0x00010005ull;

static const uint32_t EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING = 0;
static const uint32_t EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_CBS_CS = 0x00050001ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_FSI = 0x00002801ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE = 0x00002804ull;

static const uint32_t FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER = 0;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART = 2;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START = 3;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT = 4;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN = 5;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY = 6;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN = 10;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR = 16;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN = 16;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_FSI = 0x0000280bull;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE = 0x0000282cull;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_RO = 0x0005000bull;

static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_RESET_EP = 0;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP = 1;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF = 2;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE = 3;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ = 4;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD = 5;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE = 8;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE_LEN = 5;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE = 13;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR = 14;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE = 15;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE = 16;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE = 20;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR = 24;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR = 25;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR = 26;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED = 27;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET = 28;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE = 29;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE = 30;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK = 31;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_CBS_FSI = 0x00002802ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_FSI_BYTE = 0x00002808ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_RO = 0x00050002ull;

static const uint32_t FSXCOMP_FSXLOG_CBS_SIGNATURE = 0;
static const uint32_t FSXCOMP_FSXLOG_CBS_SIGNATURE_LEN = 16;
static const uint32_t FSXCOMP_FSXLOG_CBS_TRANS_DELAY = 22;
static const uint32_t FSXCOMP_FSXLOG_CBS_TRANS_DELAY_LEN = 10;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_CBS_HIST = 0x00050005ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_HIST_FSI = 0x00002805ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_HIST_FSI_BYTE = 0x00002814ull;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_14_FSI = 0x0000288eull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_14_FSI_BYTE = 0x00002a38ull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_14_RO = 0x0005008eull;

static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_14_MDA_M1B_DATA_AREA_14 = 0;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_14_MDA_M1B_DATA_AREA_14_LEN = 32;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_5_FSI = 0x00002885ull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_5_FSI_BYTE = 0x00002a14ull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_5_RO = 0x00050085ull;

static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_5_MDA_M1B_DATA_AREA_5 = 0;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_5_MDA_M1B_DATA_AREA_5_LEN = 32;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_3_FSI = 0x000028c3ull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_3_FSI_BYTE = 0x00002b0cull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_3_RW = 0x000500c3ull;

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_3_MDA_M2A_DATA_AREA_3 = 0;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_3_MDA_M2A_DATA_AREA_3_LEN = 32;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_10_FSI = 0x0000290aull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_10_FSI_BYTE = 0x00002c28ull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_10_RO = 0x0005010aull;

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_10_MDA_M2B_DATA_AREA_10 = 0;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_10_MDA_M2B_DATA_AREA_10_LEN = 32;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_9_FSI = 0x00002909ull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_9_FSI_BYTE = 0x00002c24ull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_9_RO = 0x00050109ull;

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_9_MDA_M2B_DATA_AREA_9 = 0;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_9_MDA_M2B_DATA_AREA_9_LEN = 32;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_0_B_FSI = 0x00002825ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_0_B_FSI_BYTE = 0x00002894ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_0_B_RO = 0x00050025ull;

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_0_B_M1HC0B_MAILBOX_1_HEADER_COMMAND_0_B = 0;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_0_B_M1HC0B_MAILBOX_1_HEADER_COMMAND_0_B_LEN = 32;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_0_A_FSI = 0x00002829ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_0_A_FSI_BYTE = 0x000028a4ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_0_A_RW = 0x00050029ull;

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_0_A_M2HC0A_MAILBOX_2_HEADER_COMMAND_0_A = 0;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_0_A_M2HC0A_MAILBOX_2_HEADER_COMMAND_0_A_LEN = 32;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_FSI = 0x00002836ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_FSI0 = 0x00002837ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_FSI_BYTE = 0x000028d8ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_RO = 0x00050036ull;

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_ABORT_MAILBOX_2 = 24;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_ABORT_MAILBOX_1 = 25;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_LBUS_SLAVE_B_DOORBELL_ERROR_MAILBOX_2 =
    26;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_LBUS_SLAVE_B_DOORBELL_ERROR_MAILBOX_1 =
    27;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_XDN_MAILBOX_2 = 28;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_XDN_MAILBOX_1 = 29;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_LBUS_SLAVE_B_PENDING_MAILBOX_2 = 30;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_MASK_1_LBUS_SLAVE_B_PENDING_MAILBOX_1 = 31;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI = 0x0000291aull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE = 0x00002c68ull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW = 0x0005011aull;

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG = 0;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG_LEN = 32;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_RCS_EL2_FSI = 0x00002942ull;
static const uint32_t FSXCOMP_FSXLOG_RCS_EL2_FSI_BYTE = 0x00002d08ull;
static const uint32_t FSXCOMP_FSXLOG_RCS_EL2_RO = 0x00050142ull;

static const uint32_t FSXCOMP_FSXLOG_RCS_EL2_SNS = 0;
static const uint32_t FSXCOMP_FSXLOG_RCS_EL2_SNS_LEN = 17;
static const uint32_t FSXCOMP_FSXLOG_RCS_EL2_ERR = 17;
static const uint32_t FSXCOMP_FSXLOG_RCS_EL2_ERR_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_RCS_EL2_TIME = 21;
static const uint32_t FSXCOMP_FSXLOG_RCS_EL2_TIME_LEN = 11;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_11_FSI = 0x00002982ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_11_FSI_BYTE = 0x00002e08ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_11_RW = 0x00050182ull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_11_SR_SCRATCH_REGISTER_11 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_11_SR_SCRATCH_REGISTER_11_LEN = 32;
// perv/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SNS2LTH_FSI = 0x0000281eull;
static const uint32_t FSXCOMP_FSXLOG_SNS2LTH_FSI_BYTE = 0x00002878ull;
static const uint32_t FSXCOMP_FSXLOG_SNS2LTH_RO = 0x0005001eull;

static const uint32_t FSXCOMP_FSXLOG_SNS2LTH_TPFSI_RCS_SENSE_DC_32_63 = 0;
static const uint32_t FSXCOMP_FSXLOG_SNS2LTH_TPFSI_RCS_SENSE_DC_32_63_LEN = 32;
// perv/reg00024.H

static const uint64_t HOSTATTN_UNMASKED = 0x00040014ull;

static const uint32_t HOSTATTN_UNMASKED_IN = 1;
static const uint32_t HOSTATTN_UNMASKED_IN_LEN = 53;
// perv/reg00024.H

static const uint64_t L3TRA1_TR0_CONFIG_9 = 0x00018249ull;

static const uint32_t L3TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t L3TRA1_TR0_CONFIG_9_SPARE_LT = 37;
// perv/reg00024.H

static const uint64_t L3TRA1_TR1_CONFIG_0 = 0x00018263ull;

static const uint32_t L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00024.H

static const uint64_t L3TRA3_TR0_CONFIG_1 = 0x000182c4ull;

static const uint32_t L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00024.H

static const uint64_t MULTICAST_GROUP_4 = 0x000f0004ull;

static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP = 3;
static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN = 3;
// perv/reg00024.H

static const uint64_t OTPC_M_MEASURE_REG14 = 0x0001001eull;

static const uint32_t OTPC_M_MEASURE_REG14_SEEPROM_MEASUREMENT14_DATA = 0;
static const uint32_t OTPC_M_MEASURE_REG14_SEEPROM_MEASUREMENT14_DATA_LEN = 64;
// perv/reg00024.H

static const uint64_t PCB_OPCG_STOP = 0x00030030ull;

static const uint32_t PCB_OPCG_STOP_PCB_OPCGSTOP = 0;
// perv/reg00024.H

static const uint64_t PRE_COUNTER_REG = 0x000f0028ull;

static const uint32_t PRE_COUNTER_REG_PRE_COUNTER = 0;
static const uint32_t PRE_COUNTER_REG_PRE_COUNTER_LEN = 8;
// perv/reg00024.H

static const uint64_t REC_ERR_MST14_REG1 = 0x000f0079ull;

static const uint32_t REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST14_REG1_16_MST14_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST14_REG1_16_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST14_REG1_17_MST14_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST14_REG1_17_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST14_REG1_18_MST14_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST14_REG1_18_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST14_REG1_19_MST14_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST14_REG1_19_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST14_REG1_20_MST14_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST14_REG1_20_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST14_REG1_21_MST14_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST14_REG1_21_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST14_REG1_22_MST14_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST14_REG1_22_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST14_REG1_23_MST14_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST14_REG1_23_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST14_REG1_24_MST14_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST14_REG1_24_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST14_REG1_25_MST14_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST14_REG1_25_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST14_REG1_26_MST14_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST14_REG1_26_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST14_REG1_27_MST14_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST14_REG1_27_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST14_REG1_28_MST14_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST14_REG1_28_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST14_REG1_29_MST14_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST14_REG1_29_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST14_REG1_30_MST14_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST14_REG1_30_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST14_REG1_31_MST14_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST14_REG1_31_MST14_ERROR_CODE_LEN = 3;
// perv/reg00024.H

static const uint64_t REC_ERR_MST2_REG1 = 0x000f0049ull;

static const uint32_t REC_ERR_MST2_REG1_16_MST2_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST2_REG1_16_MST2_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST2_REG1_16_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_17_MST2_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST2_REG1_17_MST2_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST2_REG1_17_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_18_MST2_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST2_REG1_18_MST2_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST2_REG1_18_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_19_MST2_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST2_REG1_19_MST2_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST2_REG1_19_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_20_MST2_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST2_REG1_20_MST2_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST2_REG1_20_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_21_MST2_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST2_REG1_21_MST2_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST2_REG1_21_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_22_MST2_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST2_REG1_22_MST2_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST2_REG1_22_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_23_MST2_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST2_REG1_23_MST2_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST2_REG1_23_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_24_MST2_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST2_REG1_24_MST2_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST2_REG1_24_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_25_MST2_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST2_REG1_25_MST2_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST2_REG1_25_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_26_MST2_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST2_REG1_26_MST2_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST2_REG1_26_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_27_MST2_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST2_REG1_27_MST2_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST2_REG1_27_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_28_MST2_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST2_REG1_28_MST2_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST2_REG1_28_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_29_MST2_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST2_REG1_29_MST2_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST2_REG1_29_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_30_MST2_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST2_REG1_30_MST2_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST2_REG1_30_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG1_31_MST2_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST2_REG1_31_MST2_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST2_REG1_31_MST2_ERROR_CODE_LEN = 3;
// perv/reg00024.H

static const uint64_t REC_ERR_MST6_REG0 = 0x000f0058ull;

static const uint32_t REC_ERR_MST6_REG0_MASTER_MST6_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST6_REG0_MASTER_MST6_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST6_REG0_MASTER_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE1_MST6_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST6_REG0_SLAVE1_MST6_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST6_REG0_SLAVE1_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE2_MST6_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST6_REG0_SLAVE2_MST6_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST6_REG0_SLAVE2_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE3_MST6_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST6_REG0_SLAVE3_MST6_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST6_REG0_SLAVE3_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE4_MST6_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST6_REG0_SLAVE4_MST6_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST6_REG0_SLAVE4_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE5_MST6_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST6_REG0_SLAVE5_MST6_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST6_REG0_SLAVE5_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE6_MST6_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST6_REG0_SLAVE6_MST6_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST6_REG0_SLAVE6_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE7_MST6_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST6_REG0_SLAVE7_MST6_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST6_REG0_SLAVE7_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE8_MST6_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST6_REG0_SLAVE8_MST6_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST6_REG0_SLAVE8_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE9_MST6_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST6_REG0_SLAVE9_MST6_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST6_REG0_SLAVE9_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE10_MST6_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST6_REG0_SLAVE10_MST6_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST6_REG0_SLAVE10_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE11_MST6_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST6_REG0_SLAVE11_MST6_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST6_REG0_SLAVE11_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE12_MST6_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST6_REG0_SLAVE12_MST6_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST6_REG0_SLAVE12_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE13_MST6_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST6_REG0_SLAVE13_MST6_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST6_REG0_SLAVE13_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE14_MST6_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST6_REG0_SLAVE14_MST6_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST6_REG0_SLAVE14_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG0_SLAVE15_MST6_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST6_REG0_SLAVE15_MST6_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST6_REG0_SLAVE15_MST6_ERROR_CODE_LEN = 3;
// perv/reg00024.H

static const uint64_t REC_ERR_MST8_REG0 = 0x000f0060ull;

static const uint32_t REC_ERR_MST8_REG0_MASTER_MST8_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST8_REG0_MASTER_MST8_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST8_REG0_MASTER_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE1_MST8_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST8_REG0_SLAVE1_MST8_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST8_REG0_SLAVE1_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE2_MST8_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST8_REG0_SLAVE2_MST8_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST8_REG0_SLAVE2_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE3_MST8_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST8_REG0_SLAVE3_MST8_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST8_REG0_SLAVE3_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE4_MST8_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST8_REG0_SLAVE4_MST8_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST8_REG0_SLAVE4_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE5_MST8_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST8_REG0_SLAVE5_MST8_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST8_REG0_SLAVE5_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE6_MST8_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST8_REG0_SLAVE6_MST8_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST8_REG0_SLAVE6_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE7_MST8_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST8_REG0_SLAVE7_MST8_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST8_REG0_SLAVE7_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE8_MST8_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST8_REG0_SLAVE8_MST8_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST8_REG0_SLAVE8_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE9_MST8_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST8_REG0_SLAVE9_MST8_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST8_REG0_SLAVE9_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE10_MST8_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST8_REG0_SLAVE10_MST8_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST8_REG0_SLAVE10_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE11_MST8_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST8_REG0_SLAVE11_MST8_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST8_REG0_SLAVE11_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE12_MST8_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST8_REG0_SLAVE12_MST8_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST8_REG0_SLAVE12_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE13_MST8_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST8_REG0_SLAVE13_MST8_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST8_REG0_SLAVE13_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE14_MST8_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST8_REG0_SLAVE14_MST8_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST8_REG0_SLAVE14_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG0_SLAVE15_MST8_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST8_REG0_SLAVE15_MST8_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST8_REG0_SLAVE15_MST8_ERROR_CODE_LEN = 3;
// perv/reg00024.H

static const uint64_t SCAN64CONTSCAN = 0x0003f000ull;

static const uint32_t SCAN64CONTSCAN_SCAN64CONTSCAN_REG = 0;
static const uint32_t SCAN64CONTSCAN_SCAN64CONTSCAN_REG_LEN = 64;
// perv/reg00024.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG112 = 0x00018070ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG112_REGISTER112 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG112_REGISTER112_LEN = 64;
// perv/reg00024.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG125 = 0x0001807dull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG125_REGISTER125 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG125_REGISTER125_LEN = 64;
// perv/reg00024.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG34 = 0x00018022ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG34_REGISTER34 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG34_REGISTER34_LEN = 64;
// perv/reg00024.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG55 = 0x00018037ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG55_REGISTER55 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG55_REGISTER55_LEN = 64;
// perv/reg00024.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG62 = 0x0001803eull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG62_REGISTER62 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG62_REGISTER62_LEN = 64;
// perv/reg00025.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG88 = 0x00018058ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG88_REGISTER88 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG88_REGISTER88_LEN = 64;
// perv/reg00025.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG97 = 0x00018061ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG97_REGISTER97 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG97_REGISTER97_LEN = 64;
// perv/reg00025.H

static const uint64_t TOD_PRI_PORT_0_CTRL_REG = 0x00040001ull;

static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT = 0;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT_LEN = 3;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03 = 3;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT = 4;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT = 6;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT = 8;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT = 10;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT = 12;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT = 14;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT = 16;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT = 18;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE = 20;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE = 21;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE = 22;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE = 23;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE = 24;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE = 25;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE = 26;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE = 27;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31 = 28;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31_LEN = 4;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE = 32;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE_LEN = 8;
// perv/reg00025.H

static const uint64_t TRA0_TR1_TRACE_LO_DATA_REG = 0x00010441ull;

static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00025.H

static const uint64_t TRA1_TR0_CONFIG_9 = 0x00010489ull;

static const uint32_t TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t TRA1_TR0_CONFIG_9_SPARE_LT = 37;
// perv/reg00025.H

static const uint64_t TRA1_TR1_CONFIG_0 = 0x000104c3ull;

static const uint32_t TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00025.H

static const uint64_t TRA3_TR0_TRACE_HI_DATA_REG = 0x00010580ull;

static const uint32_t TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00025.H

static const uint64_t TRA3_TR0_CONFIG_1 = 0x00010584ull;

static const uint32_t TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00025.H

static const uint64_t TRA4_TR0_CONFIG_0 = 0x00010603ull;

static const uint32_t TRA4_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA4_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00025.H

static const uint64_t TRA4_TR1_CONFIG_9 = 0x00010649ull;

static const uint32_t TRA4_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA4_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA4_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA4_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA4_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA4_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA4_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t TRA4_TR1_CONFIG_9_SPARE_LT = 37;
// perv/reg00025.H

static const uint64_t TRA6_TR1_CONFIG_1 = 0x00010744ull;

static const uint32_t TRA6_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA6_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00025.H

static const uint64_t XSTOP_INTERRUPT_REG = 0x000f001cull;

static const uint32_t XSTOP_INTERRUPT_REG_XSTOP = 0;
// perv/reg00025.H

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00024.H"
#include "perv/reg00025.H"
#endif
#endif
