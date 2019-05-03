/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_e.H $       */
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

#ifndef __p10_scom_pauc_e_H_
#define __p10_scom_pauc_e_H_


namespace scomt
{
namespace pauc
{


static const uint64_t EPS_DBG_TRACE_REG_1 = 0x100107ceull;

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
// pauc/reg00014.H

static const uint64_t EPS_FIR_LOCAL_ACTION1 = 0x10040011ull;

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
// pauc/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t FIR_MASK_REG_RWX = 0x10000043ull;
static const uint64_t FIR_MASK_REG_WOX_AND = 0x10000044ull;
static const uint64_t FIR_MASK_REG_WOX_OR = 0x10000045ull;

static const uint32_t FIR_MASK_REG_IOO0_RX_INVALID_STATE_OR_PARITY_ERROR_MASK = 0;
static const uint32_t FIR_MASK_REG_IOO1_RX_INVALID_STATE_OR_PARITY_ERROR_MASK = 1;
static const uint32_t FIR_MASK_REG_OMI0_RX_INVALID_STATE_OR_PARITY_ERROR_MASK = 2;
static const uint32_t FIR_MASK_REG_OMI1_RX_INVALID_STATE_OR_PARITY_ERROR_MASK = 3;
static const uint32_t FIR_MASK_REG_IOO0_TX_INVALID_STATE_OR_PARITY_ERROR_MASK = 4;
static const uint32_t FIR_MASK_REG_IOO1_TX_INVALID_STATE_OR_PARITY_ERROR_MASK = 5;
static const uint32_t FIR_MASK_REG_OMI0_TX_INVALID_STATE_OR_PARITY_ERROR_MASK = 6;
static const uint32_t FIR_MASK_REG_OMI1_TX_INVALID_STATE_OR_PARITY_ERROR_MASK = 7;
static const uint32_t FIR_MASK_REG_ZCAL_INVALID_STATE_OR_PARITY_ERROR_MASK = 8;
static const uint32_t FIR_MASK_REG_PPE_INT_HWERROR_MASK = 9;
static const uint32_t FIR_MASK_REG_PPE_EXT_HWERROR_MASK = 10;
static const uint32_t FIR_MASK_REG_PPE_HALT_WATCHDOG_OR_INTERRUPT_MASK = 11;
static const uint32_t FIR_MASK_REG_PPE_HALT_DEBUG_MASK = 12;
static const uint32_t FIR_MASK_REG_PPE_HALTED_MASK = 13;
static const uint32_t FIR_MASK_REG_PPE_WATCHDOG_TIMEOUT_MASK = 14;
static const uint32_t FIR_MASK_REG_PPE_ARB_MISSED_SCRUB_TICK_MASK = 15;
static const uint32_t FIR_MASK_REG_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR_MASK = 16;
static const uint32_t FIR_MASK_REG_PPE_ARB_ARRAY_CORRECTABLE_ERROR_MASK = 17;
static const uint32_t FIR_MASK_REG_PPE_CODE_RECAL_ABORT_MASK = 18;
static const uint32_t FIR_MASK_REG_PPE_CODE_FATAL_ERROR_MASK = 19;
static const uint32_t FIR_MASK_REG_PPE_CODE_WARNING_MASK = 20;
static const uint32_t FIR_MASK_REG_PPE_CODE_DFT_ERROR_MASK = 21;
static const uint32_t FIR_MASK_REG_PPE_CODE_RECAL_NOT_RUN_MASK = 22;
static const uint32_t FIR_MASK_REG_PPE_CODE_THREAD_LOCKED_MASK = 23;
static const uint32_t FIR_MASK_REG_PPE_CODE_6_MASK = 24;
static const uint32_t FIR_MASK_REG_PPE_CODE_7_MASK = 25;
// pauc/reg00014.H

static const uint64_t OPCG_REG1 = 0x10030003ull;

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
// pauc/reg00014.H

static const uint64_t PB_DOB23_DIB23_INT_ERR_REG = 0x1001182aull;
// pauc/reg00014.H

static const uint64_t PB_MAILBOX_10_REG = 0x10011832ull;
// pauc/reg00014.H

static const uint64_t PB_MAILBOX_11_REG = 0x10011833ull;
// pauc/reg00014.H

static const uint64_t PB_PMU2_CNPM_COUNTER = 0x10011823ull;
// pauc/reg00014.H

static const uint64_t PB_PTL_FIR_MASK_REG_RWX = 0x10011803ull;
static const uint64_t PB_PTL_FIR_MASK_REG_WOX_AND = 0x10011804ull;
static const uint64_t PB_PTL_FIR_MASK_REG_WOX_OR = 0x10011805ull;

static const uint32_t PB_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK = 0;
static const uint32_t PB_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK = 1;
static const uint32_t PB_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK = 2;
static const uint32_t PB_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK = 3;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB01_UE_MASK = 8;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB01_CE_MASK = 9;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB01_SUE_MASK = 10;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB23_UE_MASK = 11;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB23_CE_MASK = 12;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB23_SUE_MASK = 13;
static const uint32_t PB_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK = 20;
static const uint32_t PB_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK = 21;
static const uint32_t PB_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK = 22;
static const uint32_t PB_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK = 23;
static const uint32_t PB_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK = 28;
static const uint32_t PB_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK = 29;
static const uint32_t PB_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK = 30;
static const uint32_t PB_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK = 31;
static const uint32_t PB_PTL_FIR_MASK_REG_MB00_SPATTN_MASK = 36;
static const uint32_t PB_PTL_FIR_MASK_REG_MB01_SPATTN_MASK = 37;
static const uint32_t PB_PTL_FIR_MASK_REG_MB10_SPATTN_MASK = 38;
static const uint32_t PB_PTL_FIR_MASK_REG_MB11_SPATTN_MASK = 39;
static const uint32_t PB_PTL_FIR_MASK_REG_MB20_SPATTN_MASK = 40;
static const uint32_t PB_PTL_FIR_MASK_REG_MB21_SPATTN_MASK = 41;
static const uint32_t PB_PTL_FIR_MASK_REG_MB30_SPATTN_MASK = 42;
static const uint32_t PB_PTL_FIR_MASK_REG_MB31_SPATTN_MASK = 43;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB01_ERR_MASK = 52;
static const uint32_t PB_PTL_FIR_MASK_REG_DOB23_ERR_MASK = 53;
static const uint32_t PB_PTL_FIR_MASK_REG_DIB01_ERR_MASK = 56;
static const uint32_t PB_PTL_FIR_MASK_REG_DIB23_ERR_MASK = 57;
// pauc/reg00014.H

static const uint64_t RCMD_RATE_CFG = 0x1001180cull;

static const uint32_t RCMD_RATE_CFG_X_RCMD_RATE = 0;
static const uint32_t RCMD_RATE_CFG_X_RCMD_RATE_LEN = 8;
static const uint32_t RCMD_RATE_CFG_Y_RCMD_RATE = 8;
static const uint32_t RCMD_RATE_CFG_Y_RCMD_RATE_LEN = 8;
static const uint32_t RCMD_RATE_CFG_X_RCMD_RATE_ADDER = 16;
static const uint32_t RCMD_RATE_CFG_X_RCMD_RATE_ADDER_LEN = 4;
static const uint32_t RCMD_RATE_CFG_Y_RCMD_RATE_ADDER = 20;
static const uint32_t RCMD_RATE_CFG_Y_RCMD_RATE_ADDER_LEN = 4;
// pauc/reg00014.H

static const uint64_t SLAVE_CONFIG_REG = 0x100f001eull;

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
// pauc/reg00014.H

static const uint64_t TRA1_TR0_CONFIG_1 = 0x10010484ull;

static const uint32_t TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// pauc/reg00014.H

static const uint64_t XSTOP2 = 0x1003000dull;

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
// pauc/reg00014.H

}
}
#include "pauc/reg00014.H"
#endif
