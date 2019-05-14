/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_d.H $       */
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

#ifndef __p10_scom_perv_d_H_
#define __p10_scom_perv_d_H_


namespace scomt
{
namespace perv
{


static const uint64_t CC_ATOMIC_LOCK_REG = 0x000303ffull;

static const uint32_t CC_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CC_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CC_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CC_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CC_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// perv/reg00019.H

static const uint64_t COMP_P_0_CMD_WRDAT = 0x00030000ull;

static const uint32_t COMP_P_0_CMD_WRDAT_WRITE_NOT_READ = 0;
// perv/reg00019.H

static const uint64_t COMP_P_0_RSIM = 0x00030009ull;
// perv/reg00019.H

static const uint64_t CTRL_ATOMIC_LOCK_REG = 0x000003ffull;

static const uint32_t CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// perv/reg00019.H

static const uint64_t DPLL_CNTL_NEST_REGS_STAT = 0x00000155ull;

static const uint32_t DPLL_CNTL_NEST_REGS_STAT_FREQOUT = 1;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_FREQOUT_LEN = 11;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT = 12;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT_LEN = 5;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE = 60;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE = 61;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE = 62;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_LOCK = 63;
// perv/reg00019.H

static const uint64_t EPS_DBG_DEBUG_TRACE_CONTROL = 0x000107d0ull;
// perv/reg00019.H

static const uint64_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ = 0x0005003cull;

static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_CBS_EL_HIST_FSI = 0x00002806ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_EL_HIST_FSI_BYTE = 0x00002818ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_EL_HIST_SCOM = 0x00050006ull;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_0_FSI = 0x00002840ull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_0_FSI_BYTE = 0x00002900ull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_0_RW = 0x00050040ull;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_13_FSI = 0x000028cdull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_13_FSI_BYTE = 0x00002b34ull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_13_RW = 0x000500cdull;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_6_FSI = 0x00002906ull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_6_FSI_BYTE = 0x00002c18ull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_6_RW = 0x00050106ull;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI = 0x00002910ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE = 0x00002c40ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW = 0x00050110ull;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_FSI = 0x00002815ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE = 0x00002854ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_RW = 0x00050015ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_RESET_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_BYPASS_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_BYPASS_CLKSEL_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLK_TEST_IN_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CONTROL_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CONTROL_DC_LEN = 28;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_FSI = 0x00002936ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_FSI_BYTE = 0x00002cd8ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_WO_CLEAR = 0x00050136ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_PLLREFCLK_RCVR_TERM_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_PLLREFCLK_RCVR_TERM_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_PCIREFCLK_RCVR_TERM_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_PCIREFCLK_RCVR_TERM_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_ROOT_CTRL6_4 = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_ROOT_CTRL6_5 = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_ROOT_CTRL6_6_31 = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_ROOT_CTRL6_6_31_LEN = 26;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SB_MSG_FSI = 0x00002809ull;
static const uint32_t FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE = 0x00002824ull;
static const uint32_t FSXCOMP_FSXLOG_SB_MSG_SCOM = 0x00050009ull;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI = 0x00002838ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE = 0x000028e0ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW = 0x00050038ull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1_LEN = 32;
// perv/reg00019.H

static const uint64_t L3TRA0_TR0_CONFIG_9 = 0x00018209ull;

static const uint32_t L3TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00019.H

static const uint64_t L3TRA0_TR1_CONFIG_0 = 0x00018223ull;

static const uint32_t L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00019.H

static const uint64_t L3TRA2_TR0_CONFIG_1 = 0x00018284ull;

static const uint32_t L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00019.H

static const uint64_t L3TRA2_TR1_CONFIG = 0x000182a2ull;

static const uint32_t L3TRA2_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA2_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA2_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA2_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA2_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA2_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA2_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// perv/reg00019.H

static const uint64_t L3TRA3_TR0_CONFIG = 0x000182c2ull;

static const uint32_t L3TRA3_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA3_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA3_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA3_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA3_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA3_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA3_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// perv/reg00019.H

static const uint64_t OPCG_CAPT1 = 0x00030010ull;

static const uint32_t OPCG_CAPT1_COUNT = 0;
static const uint32_t OPCG_CAPT1_COUNT_LEN = 4;
static const uint32_t OPCG_CAPT1_SEQ_01 = 4;
static const uint32_t OPCG_CAPT1_SEQ_01_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_02 = 9;
static const uint32_t OPCG_CAPT1_SEQ_02_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_03 = 14;
static const uint32_t OPCG_CAPT1_SEQ_03_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_04 = 19;
static const uint32_t OPCG_CAPT1_SEQ_04_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_05 = 24;
static const uint32_t OPCG_CAPT1_SEQ_05_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_06 = 29;
static const uint32_t OPCG_CAPT1_SEQ_06_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_07 = 34;
static const uint32_t OPCG_CAPT1_SEQ_07_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_08 = 39;
static const uint32_t OPCG_CAPT1_SEQ_08_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_09 = 44;
static const uint32_t OPCG_CAPT1_SEQ_09_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_10 = 49;
static const uint32_t OPCG_CAPT1_SEQ_10_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_11 = 54;
static const uint32_t OPCG_CAPT1_SEQ_11_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_12 = 59;
static const uint32_t OPCG_CAPT1_SEQ_12_LEN = 5;
// perv/reg00019.H

static const uint64_t OTPC_M_COMMAND_REGISTER = 0x00010000ull;

static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_BIT_WITHSTART = 0;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_BIT_WITHADDR = 1;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_BIT_READCONT = 2;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_BIT_WITHSTOP = 3;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_LENGTH = 4;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_LENGTH_LEN = 4;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_BIT_RNW = 15;
static const uint32_t OTPC_M_COMMAND_REGISTER_REG_ADDR_LEN = 23;
static const uint32_t OTPC_M_COMMAND_REGISTER_REG_ADDR_LEN_LEN = 3;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_1 = 32;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_1_LEN = 8;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_2 = 40;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_2_LEN = 8;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_3 = 48;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_3_LEN = 8;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_4 = 56;
static const uint32_t OTPC_M_COMMAND_REGISTER_CMD_REG_ADDR_4_LEN = 8;
// perv/reg00019.H

static const uint64_t OTPC_M_MEASURE_REG0 = 0x00010010ull;

static const uint32_t OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA = 0;
static const uint32_t OTPC_M_MEASURE_REG0_SEEPROM_MEASUREMENT0_DATA_LEN = 64;
// perv/reg00019.H

static const uint64_t PRIMARY_ADDRESS_REG = 0x000f0000ull;
// perv/reg00019.H

static const uint64_t RECOV_MASK_RW = 0x00040041ull;
static const uint64_t RECOV_MASK_WO_CLEAR = 0x00040061ull;
static const uint64_t RECOV_MASK_WO_OR = 0x00040051ull;

static const uint32_t RECOV_MASK_1 = 1;
static const uint32_t RECOV_MASK_2 = 2;
static const uint32_t RECOV_MASK_3 = 3;
static const uint32_t RECOV_MASK_4 = 4;
static const uint32_t RECOV_MASK_5 = 5;
static const uint32_t RECOV_MASK_6 = 6;
static const uint32_t RECOV_MASK_7 = 7;
static const uint32_t RECOV_MASK_8 = 8;
static const uint32_t RECOV_MASK_9 = 9;
static const uint32_t RECOV_MASK_10 = 10;
static const uint32_t RECOV_MASK_11 = 11;
static const uint32_t RECOV_MASK_12 = 12;
static const uint32_t RECOV_MASK_13 = 13;
static const uint32_t RECOV_MASK_14 = 14;
static const uint32_t RECOV_MASK_15 = 15;
static const uint32_t RECOV_MASK_16 = 16;
static const uint32_t RECOV_MASK_17 = 17;
static const uint32_t RECOV_MASK_18 = 18;
static const uint32_t RECOV_MASK_19 = 19;
static const uint32_t RECOV_MASK_20 = 20;
static const uint32_t RECOV_MASK_21 = 21;
static const uint32_t RECOV_MASK_22 = 22;
static const uint32_t RECOV_MASK_23 = 23;
static const uint32_t RECOV_MASK_24 = 24;
static const uint32_t RECOV_MASK_25 = 25;
static const uint32_t RECOV_MASK_26 = 26;
static const uint32_t RECOV_MASK_27 = 27;
static const uint32_t RECOV_MASK_28 = 28;
static const uint32_t RECOV_MASK_29 = 29;
static const uint32_t RECOV_MASK_30 = 30;
static const uint32_t RECOV_MASK_31 = 31;
static const uint32_t RECOV_MASK_32 = 32;
static const uint32_t RECOV_MASK_33 = 33;
static const uint32_t RECOV_MASK_34 = 34;
static const uint32_t RECOV_MASK_35 = 35;
static const uint32_t RECOV_MASK_36 = 36;
static const uint32_t RECOV_MASK_37 = 37;
static const uint32_t RECOV_MASK_38 = 38;
static const uint32_t RECOV_MASK_39 = 39;
static const uint32_t RECOV_MASK_40 = 40;
static const uint32_t RECOV_MASK_41 = 41;
static const uint32_t RECOV_MASK_42 = 42;
static const uint32_t RECOV_MASK_43 = 43;
static const uint32_t RECOV_MASK_44 = 44;
static const uint32_t RECOV_MASK_45 = 45;
static const uint32_t RECOV_MASK_46 = 46;
static const uint32_t RECOV_MASK_47 = 47;
static const uint32_t RECOV_MASK_48 = 48;
static const uint32_t RECOV_MASK_49 = 49;
static const uint32_t RECOV_MASK_50 = 50;
static const uint32_t RECOV_MASK_51 = 51;
static const uint32_t RECOV_MASK_52 = 52;
static const uint32_t RECOV_MASK_53 = 53;
// perv/reg00019.H

static const uint64_t REC_ERR_MST4_REG3 = 0x000f0053ull;

static const uint32_t REC_ERR_MST4_REG3_48_MST4_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST4_REG3_48_MST4_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST4_REG3_48_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_49_MST4_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST4_REG3_49_MST4_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST4_REG3_49_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_50_MST4_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST4_REG3_50_MST4_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST4_REG3_50_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_51_MST4_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST4_REG3_51_MST4_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST4_REG3_51_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_52_MST4_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST4_REG3_52_MST4_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST4_REG3_52_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_53_MST4_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST4_REG3_53_MST4_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST4_REG3_53_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_54_MST4_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST4_REG3_54_MST4_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST4_REG3_54_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_55_MST4_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST4_REG3_55_MST4_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST4_REG3_55_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_56_MST4_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST4_REG3_56_MST4_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST4_REG3_56_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_57_MST4_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST4_REG3_57_MST4_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST4_REG3_57_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_58_MST4_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST4_REG3_58_MST4_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST4_REG3_58_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_59_MST4_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST4_REG3_59_MST4_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST4_REG3_59_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_60_MST4_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST4_REG3_60_MST4_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST4_REG3_60_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_61_MST4_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST4_REG3_61_MST4_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST4_REG3_61_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_62_MST4_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST4_REG3_62_MST4_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST4_REG3_62_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG3_63_MST4_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST4_REG3_63_MST4_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST4_REG3_63_MST4_ERROR_CODE_LEN = 3;
// perv/reg00019.H

static const uint64_t SCAN_UPDATEDR_LONG = 0x0003b000ull;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG102 = 0x00008066ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG102_REGISTER102 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG102_REGISTER102_LEN = 64;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG13 = 0x0000800dull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG13_REGISTER13 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG13_REGISTER13_LEN = 64;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG24 = 0x00008018ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG24_REGISTER24 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG24_REGISTER24_LEN = 64;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG3 = 0x00008003ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG3_REGISTER3 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG3_REGISTER3_LEN = 64;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG45 = 0x0000802dull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG45_REGISTER45 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG45_REGISTER45_LEN = 64;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG72 = 0x00008048ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG72_REGISTER72 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG72_REGISTER72_LEN = 64;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG87 = 0x00008057ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG87_REGISTER87 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG87_REGISTER87_LEN = 64;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG98 = 0x00008062ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG98_REGISTER98 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG98_REGISTER98_LEN = 64;
// perv/reg00019.H

static const uint64_t TOD_FSM_REG = 0x00040024ull;

static const uint32_t TOD_FSM_REG_I_PATH_FSM_STATE = 0;
static const uint32_t TOD_FSM_REG_I_PATH_FSM_STATE_LEN = 4;
static const uint32_t TOD_FSM_REG_TOD_IS_RUNNING = 4;
static const uint32_t TOD_FSM_REG_REG_0X24_SPARE_05_07 = 5;
static const uint32_t TOD_FSM_REG_REG_0X24_SPARE_05_07_LEN = 3;
// perv/reg00019.H

static const uint64_t TOD_PSS_MSS_STATUS_REG = 0x00040008ull;

static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT = 0;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT_LEN = 3;
static const uint32_t TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 = 3;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS = 4;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS = 5;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID = 6;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID = 7;
static const uint32_t TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID = 8;
static const uint32_t TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID = 9;
static const uint32_t TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID = 10;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS = 11;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS = 12;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS = 13;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS = 14;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS = 15;
static const uint32_t TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS = 16;
static const uint32_t TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS = 17;
static const uint32_t TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS = 18;
static const uint32_t TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS = 19;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_RUNNING = 20;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_PRIMARY = 21;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_SECONDARY = 22;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER = 23;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER = 24;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_SLAVE = 25;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT = 26;
static const uint32_t TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT = 27;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH = 28;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH = 29;
static const uint32_t TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 = 30;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER = 31;
// perv/reg00019.H

static const uint64_t TOD_S_PATH_STATUS_REG = 0x0004000aull;

static const uint32_t TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE = 0;
static const uint32_t TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE_LEN = 4;
static const uint32_t TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE = 4;
static const uint32_t TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE_LEN = 4;
static const uint32_t TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO = 8;
static const uint32_t TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO_LEN = 5;
static const uint32_t TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15 = 13;
static const uint32_t TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15_LEN = 3;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_0_CPS = 16;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_0_CPS_LEN = 8;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_1_CPS = 24;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_1_CPS_LEN = 8;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT = 32;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT_LEN = 8;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT = 40;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT_LEN = 8;
// perv/reg00019.H

static const uint64_t TRA0_TR0_CONFIG_9 = 0x00010409ull;

static const uint32_t TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00019.H

static const uint64_t TRA0_TR1_CONFIG_0 = 0x00010443ull;

static const uint32_t TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00019.H

static const uint64_t TRA1_TR1_TRACE_HI_DATA_REG = 0x000104c0ull;

static const uint32_t TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00019.H

static const uint64_t TRA2_TR0_TRACE_LO_DATA_REG = 0x00010501ull;

static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00019.H

static const uint64_t TRA2_TR0_CONFIG_1 = 0x00010504ull;

static const uint32_t TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00019.H

static const uint64_t TRA4_TR1_CONFIG = 0x00010642ull;

static const uint32_t TRA4_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA4_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA4_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA4_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA4_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TRA4_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA4_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA4_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA4_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA4_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA4_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA4_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA4_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA4_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// perv/reg00019.H

static const uint64_t TRA5_TR0_CONFIG = 0x00010682ull;

static const uint32_t TRA5_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA5_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA5_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA5_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA5_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TRA5_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA5_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA5_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA5_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA5_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA5_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA5_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA5_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA5_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// perv/reg00019.H

static const uint64_t TRA5_TR0_CONFIG_0 = 0x00010683ull;

static const uint32_t TRA5_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA5_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00019.H

static const uint64_t TRA5_TR1_CONFIG_9 = 0x000106c9ull;

static const uint32_t TRA5_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA5_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA5_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA5_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA5_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA5_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA5_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA5_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA5_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00019.H

}
}
#include "perv/reg00019.H"
#endif
