/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_e.H $         */
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

#ifndef __p10_scom_eq_e_H_
#define __p10_scom_eq_e_H_


namespace scomt
{
namespace eq
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t EPS_DBG_TRACE_REG_1 = 0x200183eeull;

static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// eq/reg00030.H

static const uint64_t EPS_FIR_LOCAL_ACTION1 = 0x20040011ull;

static const uint32_t EPS_FIR_LOCAL_ACTION1_00 = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION1_01 = 1;
static const uint32_t EPS_FIR_LOCAL_ACTION1_02 = 2;
static const uint32_t EPS_FIR_LOCAL_ACTION1_03 = 3;
static const uint32_t EPS_FIR_LOCAL_ACTION1_04 = 4;
static const uint32_t EPS_FIR_LOCAL_ACTION1_05 = 5;
static const uint32_t EPS_FIR_LOCAL_ACTION1_06 = 6;
static const uint32_t EPS_FIR_LOCAL_ACTION1_07 = 7;
static const uint32_t EPS_FIR_LOCAL_ACTION1_08 = 8;
static const uint32_t EPS_FIR_LOCAL_ACTION1_09 = 9;
static const uint32_t EPS_FIR_LOCAL_ACTION1_10 = 10;
static const uint32_t EPS_FIR_LOCAL_ACTION1_11 = 11;
static const uint32_t EPS_FIR_LOCAL_ACTION1_12 = 12;
static const uint32_t EPS_FIR_LOCAL_ACTION1_13 = 13;
static const uint32_t EPS_FIR_LOCAL_ACTION1_14 = 14;
static const uint32_t EPS_FIR_LOCAL_ACTION1_15 = 15;
static const uint32_t EPS_FIR_LOCAL_ACTION1_16 = 16;
static const uint32_t EPS_FIR_LOCAL_ACTION1_17 = 17;
static const uint32_t EPS_FIR_LOCAL_ACTION1_18 = 18;
static const uint32_t EPS_FIR_LOCAL_ACTION1_19 = 19;
static const uint32_t EPS_FIR_LOCAL_ACTION1_20 = 20;
static const uint32_t EPS_FIR_LOCAL_ACTION1_21 = 21;
static const uint32_t EPS_FIR_LOCAL_ACTION1_22 = 22;
static const uint32_t EPS_FIR_LOCAL_ACTION1_23 = 23;
static const uint32_t EPS_FIR_LOCAL_ACTION1_24 = 24;
static const uint32_t EPS_FIR_LOCAL_ACTION1_25 = 25;
static const uint32_t EPS_FIR_LOCAL_ACTION1_26 = 26;
static const uint32_t EPS_FIR_LOCAL_ACTION1_27 = 27;
static const uint32_t EPS_FIR_LOCAL_ACTION1_28 = 28;
static const uint32_t EPS_FIR_LOCAL_ACTION1_29 = 29;
static const uint32_t EPS_FIR_LOCAL_ACTION1_30 = 30;
static const uint32_t EPS_FIR_LOCAL_ACTION1_31 = 31;
static const uint32_t EPS_FIR_LOCAL_ACTION1_32 = 32;
static const uint32_t EPS_FIR_LOCAL_ACTION1_33 = 33;
static const uint32_t EPS_FIR_LOCAL_ACTION1_34 = 34;
static const uint32_t EPS_FIR_LOCAL_ACTION1_35 = 35;
static const uint32_t EPS_FIR_LOCAL_ACTION1_36 = 36;
static const uint32_t EPS_FIR_LOCAL_ACTION1_37 = 37;
static const uint32_t EPS_FIR_LOCAL_ACTION1_38 = 38;
static const uint32_t EPS_FIR_LOCAL_ACTION1_39 = 39;
static const uint32_t EPS_FIR_LOCAL_ACTION1_40 = 40;
static const uint32_t EPS_FIR_LOCAL_ACTION1_41 = 41;
static const uint32_t EPS_FIR_LOCAL_ACTION1_42 = 42;
static const uint32_t EPS_FIR_LOCAL_ACTION1_43 = 43;
static const uint32_t EPS_FIR_LOCAL_ACTION1_44 = 44;
static const uint32_t EPS_FIR_LOCAL_ACTION1_45 = 45;
static const uint32_t EPS_FIR_LOCAL_ACTION1_46 = 46;
static const uint32_t EPS_FIR_LOCAL_ACTION1_47 = 47;
static const uint32_t EPS_FIR_LOCAL_ACTION1_48 = 48;
// eq/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR0_CONFIG = 0x20018202ull;

static const uint32_t L3TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// eq/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA1_TR0_TRACE_HI_DATA_REG = 0x20018240ull;

static const uint32_t L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// eq/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA1_TR0_CONFIG_1 = 0x20018244ull;

static const uint32_t L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// eq/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA1_TR1_CONFIG = 0x20018262ull;

static const uint32_t L3TRA1_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA1_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA1_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA1_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA1_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// eq/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA2_TR1_TRACE_LO_DATA_REG = 0x200182a1ull;

static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// eq/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA3_TR0_CONFIG_9 = 0x200182c9ull;

static const uint32_t L3TRA3_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA3_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA3_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA3_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// eq/reg00030.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA3_TR1_CONFIG_0 = 0x200182e3ull;

static const uint32_t L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// eq/reg00030.H

static const uint64_t OPCG_REG1 = 0x20030003ull;

static const uint32_t OPCG_REG1_SCAN_COUNT = 0;
static const uint32_t OPCG_REG1_SCAN_COUNT_LEN = 12;
static const uint32_t OPCG_REG1_MISR_A_VAL = 12;
static const uint32_t OPCG_REG1_MISR_A_VAL_LEN = 12;
static const uint32_t OPCG_REG1_MISR_B_VAL = 24;
static const uint32_t OPCG_REG1_MISR_B_VAL_LEN = 12;
static const uint32_t OPCG_REG1_MISR_INIT_WAIT = 36;
static const uint32_t OPCG_REG1_MISR_INIT_WAIT_LEN = 12;
static const uint32_t OPCG_REG1_SCAN_CLK_USE_EVEN = 49;
static const uint32_t OPCG_REG1_RTIM_THOLD_FORCE = 52;
static const uint32_t OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL = 53;
static const uint32_t OPCG_REG1_SG_HIGH_DURING_FILL = 54;
static const uint32_t OPCG_REG1_LBIST_SKITTER_CTL = 55;
static const uint32_t OPCG_REG1_LBIST_SKITTER_CTL_LEN = 2;
static const uint32_t OPCG_REG1_MISR_MODE = 57;
static const uint32_t OPCG_REG1_INFINITE_MODE = 58;
static const uint32_t OPCG_REG1_NSL_FILL_COUNT = 59;
static const uint32_t OPCG_REG1_NSL_FILL_COUNT_LEN = 5;
// eq/reg00030.H

static const uint64_t QME_DERP = 0x200e0250ull;

static const uint32_t QME_DERP_DEND = 0;
static const uint32_t QME_DERP_DEND_LEN = 32;
static const uint32_t QME_DERP_SOR = 32;
static const uint32_t QME_DERP_SOR_LEN = 32;
// eq/reg00030.H

static const uint64_t QME_EINR = 0x200e0274ull;

static const uint32_t QME_EINR_QME_EINR_INTERRUPT_INPUT = 0;
static const uint32_t QME_EINR_QME_EINR_INTERRUPT_INPUT_LEN = 64;
// eq/reg00030.H

static const uint64_t QME_LFIR_RWX = 0x200e0000ull;
static const uint64_t QME_LFIR_WOX_AND = 0x200e0001ull;
static const uint64_t QME_LFIR_WOX_OR = 0x200e0002ull;

static const uint32_t QME_LFIR_PPE_HALT_ERROR = 0;
static const uint32_t QME_LFIR_DEBUG_TRIGGER = 1;
static const uint32_t QME_LFIR_SPARE_TRIGGER = 2;
static const uint32_t QME_LFIR_PPE_WATCHDOG = 3;
static const uint32_t QME_LFIR_LOCAL_PCB_TIMEOUT = 4;
static const uint32_t QME_LFIR_FABRIC_ERROR = 5;
static const uint32_t QME_LFIR_SRAM_UE = 6;
static const uint32_t QME_LFIR_SRAM_CE = 7;
static const uint32_t QME_LFIR_RESCLK_ARRAY_PARITY_ERR = 8;
static const uint32_t QME_LFIR_PCB_INTERRUPT_PROTOCOL_ERR = 9;
static const uint32_t QME_LFIR_SRAM_SCRUB_ERR = 10;
static const uint32_t QME_LFIR_CTFS_ERR = 11;
static const uint32_t QME_LFIR_CPMS_ERR = 12;
static const uint32_t QME_LFIR_PGPE_HEARTBEAT_LOST = 13;
static const uint32_t QME_LFIR_BCE_TIMEOUT = 14;
static const uint32_t QME_LFIR_RESCLK_PROTOCOL_ERR = 15;
static const uint32_t QME_LFIR_PCB_RESET_WHEN_ACTIVE = 16;
static const uint32_t QME_LFIR_SPECIAL_WKUP_PROTOCOL_ERR = 17;
static const uint32_t QME_LFIR_SPECIAL_WKUP_DONE_WINDOW = 18;
static const uint32_t QME_LFIR_DISABLED_INTR = 19;
static const uint32_t QME_LFIR_DECONFIGURED_INTR = 20;
static const uint32_t QME_LFIR_RS4_TIMEOUT = 21;
static const uint32_t QME_LFIR_PB_DATA_HANG = 22;
static const uint32_t QME_LFIR_SPARE23 = 23;
static const uint32_t QME_LFIR_SPARE24 = 24;
static const uint32_t QME_LFIR_FIR_PARITY_ERR_DUP = 25;
static const uint32_t QME_LFIR_FIR_PARITY_ERR = 26;
// eq/reg00030.H

static const uint64_t QME_PCBSII = 0x200e0038ull;
// eq/reg00030.H

static const uint64_t SLAVE_CONFIG_REG = 0x200f001eull;

static const uint32_t SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK = 0;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN = 1;
static const uint32_t SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP = 2;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK = 3;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_HEARTBEAT = 4;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO = 5;
static const uint32_t SLAVE_CONFIG_REG_PM_DISABLE = 6;
static const uint32_t SLAVE_CONFIG_REG_PM_MUX_DISABLE = 7;
static const uint32_t SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS = 8;
static const uint32_t SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS = 9;
static const uint32_t SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS = 10;
static const uint32_t SLAVE_CONFIG_REG_MASK_PCBSL_ERRS = 11;
static const uint32_t SLAVE_CONFIG_REG_MASK_PLL_ERRS = 12;
static const uint32_t SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN = 8;
// eq/reg00030.H

static const uint64_t XSTOP2 = 0x2003000dull;

static const uint32_t XSTOP2_XSTOP2_MASK_B = 0;
static const uint32_t XSTOP2_ALIGNED_XSTOP2 = 1;
static const uint32_t XSTOP2_TRIGGER_OPCG_ON_XSTOP2 = 2;
static const uint32_t XSTOP2_XSTOP2_WAIT_ALLWAYS = 3;
static const uint32_t XSTOP2_XSTOP2_PERV = 4;
static const uint32_t XSTOP2_XSTOP2_UNIT1 = 5;
static const uint32_t XSTOP2_XSTOP2_UNIT2 = 6;
static const uint32_t XSTOP2_XSTOP2_UNIT3 = 7;
static const uint32_t XSTOP2_XSTOP2_UNIT4 = 8;
static const uint32_t XSTOP2_XSTOP2_UNIT5 = 9;
static const uint32_t XSTOP2_XSTOP2_UNIT6 = 10;
static const uint32_t XSTOP2_XSTOP2_UNIT7 = 11;
static const uint32_t XSTOP2_XSTOP2_UNIT8 = 12;
static const uint32_t XSTOP2_XSTOP2_UNIT9 = 13;
static const uint32_t XSTOP2_XSTOP2_UNIT10 = 14;
static const uint32_t XSTOP2_XSTOP2_UNIT11 = 15;
static const uint32_t XSTOP2_XSTOP2_UNIT12 = 16;
static const uint32_t XSTOP2_XSTOP2_UNIT13 = 17;
static const uint32_t XSTOP2_XSTOP2_UNIT14 = 18;
static const uint32_t XSTOP2_XSTOP2_WAIT_CYCLES = 48;
static const uint32_t XSTOP2_XSTOP2_WAIT_CYCLES_LEN = 12;
// eq/reg00030.H

}
}
#include "eq/reg00030.H"
#endif
