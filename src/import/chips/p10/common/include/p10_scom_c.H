/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c.H $            */
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

#ifndef __c_H_
#define __c_H_


namespace scomt
{
namespace c
{


static const uint64_t ADDR_TRAP_REG = 0x20010003ull;

static const uint32_t ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR = 0;
static const uint32_t ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN = 16;
static const uint32_t ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR = 16;
static const uint32_t ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT = 17;
static const uint32_t ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR = 18;
static const uint32_t ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN = 13;
static const uint32_t ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY = 31;
static const uint32_t ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR = 32;
static const uint32_t ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION = 33;
static const uint32_t ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER = 34;
static const uint32_t ADDR_TRAP_REG_LAST_MASTERID = 35;
static const uint32_t ADDR_TRAP_REG_LAST_MASTERID_LEN = 4;
// c/reg00000.H

static const uint64_t ATOMIC_LOCK_MASK_LATCH_REG = 0x20010007ull;

static const uint32_t ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK = 0;
static const uint32_t ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN = 32;
// c/reg00000.H

static const uint64_t CPMS_CERR = 0x200e0e10ull;

static const uint32_t CPMS_CERR_L3_VDD_PFET_SEQ_ERR = 0;
static const uint32_t CPMS_CERR_L3_VCS_PFET_SEQ_ERR = 1;
static const uint32_t CPMS_CERR_CL2_VDD_PFET_SEQ_ERR = 2;
static const uint32_t CPMS_CERR_CL2_VCS_PFET_SEQ_ERR = 3;
static const uint32_t CPMS_CERR_MMA_VDD_PFET_SEQ_ERR = 4;
static const uint32_t CPMS_CERR_DDS_ERR = 5;
static const uint32_t CPMS_CERR_L3_CLOCK_SYNC_ERR = 6;
static const uint32_t CPMS_CERR_CL2_CLOCK_SYNC_ERR = 7;
static const uint32_t CPMS_CERR_SPARE = 8;
static const uint32_t CPMS_CERR_DPT_ACCESS_ERROR = 9;
static const uint32_t CPMS_CERR_FTC_INJECT_SMALL_ACTIVE = 10;
static const uint32_t CPMS_CERR_FTC_INJECT_LARGE_ACTIVE = 11;
static const uint32_t CPMS_CERR_FTC_LARGE_LARGE1 = 12;
static const uint32_t CPMS_CERR_FTC_LARGE_LARGE2 = 13;
static const uint32_t CPMS_CERR_FTC_SMALL_LARGE = 14;
static const uint32_t CPMS_CERR_FTC_LARGE_SMALL = 15;
// c/reg00000.H

static const uint64_t CPMS_CERRMSK = 0x200e0e14ull;

static const uint32_t CPMS_CERRMSK_PFET_SEQ_ERR_MASK = 0;
static const uint32_t CPMS_CERRMSK_DDS_ERR_MASK = 1;
static const uint32_t CPMS_CERRMSK_CLK_SYNC_ERR_MASK = 2;
static const uint32_t CPMS_CERRMSK_FTC_EVENT_MASK = 3;
static const uint32_t CPMS_CERRMSK_SPARE_MASK = 4;
static const uint32_t CPMS_CERRMSK_DPT_ACCESS_MASK = 5;
// c/reg00000.H

static const uint64_t CPMS_CGCSR_SCOM = 0x200e0e00ull;
static const uint64_t CPMS_CGCSR_SCOM1 = 0x200e0e02ull;
static const uint64_t CPMS_CGCSR_SCOM2 = 0x200e0e03ull;

static const uint32_t CPMS_CGCSR_L3_CLK_SYNC_ENABLE = 0;
static const uint32_t CPMS_CGCSR_CL2_CLK_SYNC_ENABLE = 1;
static const uint32_t CPMS_CGCSR_RESERVED_2_3 = 2;
static const uint32_t CPMS_CGCSR_RESERVED_2_3_LEN = 2;
static const uint32_t CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET = 4;
static const uint32_t CPMS_CGCSR_L3_CLKGLM_SEL = 7;
static const uint32_t CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET = 8;
static const uint32_t CPMS_CGCSR_CL2_CLKGLM_SEL = 11;
static const uint32_t CPMS_CGCSR_L3_CLK_SYNC_DONE = 32;
static const uint32_t CPMS_CGCSR_CL2_CLK_SYNC_DONE = 33;
// c/reg00000.H

static const uint64_t CPMS_CL2_PFETCNTL_SCOM = 0x200e0e28ull;
static const uint64_t CPMS_CL2_PFETCNTL_SCOM1 = 0x200e0e2aull;
static const uint64_t CPMS_CL2_PFETCNTL_SCOM2 = 0x200e0e2bull;

static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE = 0;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE_LEN = 2;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE = 2;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE_LEN = 2;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE = 5;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE = 6;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE = 7;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET = 8;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE = 12;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN = 8;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE = 20;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE = 24;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN = 8;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE = 32;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PG_STATE = 42;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PG_STATE_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PG_SEL = 46;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PG_SEL_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PG_STATE = 50;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PG_STATE_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PG_SEL = 54;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PG_SEL_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_SRAM_ENABLE = 63;
// c/reg00000.H

static const uint64_t CPMS_CL2_PFETSTAT = 0x200e0e2cull;

static const uint32_t CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE = 0;
static const uint32_t CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE = 1;
static const uint32_t CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE = 2;
static const uint32_t CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE = 3;
static const uint32_t CPMS_CL2_PFETSTAT_VDD_PFET_ENABLE_ACTUAL = 16;
static const uint32_t CPMS_CL2_PFETSTAT_VDD_PFET_ENABLE_ACTUAL_LEN = 8;
static const uint32_t CPMS_CL2_PFETSTAT_VCS_PFET_ENABLE_ACTUAL = 24;
static const uint32_t CPMS_CL2_PFETSTAT_VCS_PFET_ENABLE_ACTUAL_LEN = 8;
static const uint32_t CPMS_CL2_PFETSTAT_SRAM_ENABLE_ACTUAL = 63;
// c/reg00000.H

static const uint64_t CPMS_L3_PFETCNTL_SCOM = 0x200e0e20ull;
static const uint64_t CPMS_L3_PFETCNTL_SCOM1 = 0x200e0e22ull;
static const uint64_t CPMS_L3_PFETCNTL_SCOM2 = 0x200e0e23ull;

static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE = 0;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE_LEN = 2;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE = 2;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE_LEN = 2;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE = 4;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE = 5;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE = 6;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE = 7;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE = 12;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN = 8;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE = 20;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE_LEN = 4;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE = 24;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN = 8;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE = 32;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE_LEN = 4;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PG_STATE = 42;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PG_STATE_LEN = 4;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PG_SEL = 46;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PG_SEL_LEN = 4;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PG_STATE = 50;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PG_STATE_LEN = 4;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PG_SEL = 54;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PG_SEL_LEN = 4;
static const uint32_t CPMS_L3_PFETCNTL_SRAM_ENABLE = 63;
// c/reg00000.H

static const uint64_t CPMS_L3_PFETSTAT = 0x200e0e24ull;

static const uint32_t CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE = 0;
static const uint32_t CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE = 1;
static const uint32_t CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE = 2;
static const uint32_t CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE = 3;
static const uint32_t CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL = 16;
static const uint32_t CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL_LEN = 8;
static const uint32_t CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL = 24;
static const uint32_t CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL_LEN = 8;
static const uint32_t CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL = 63;
// c/reg00000.H

static const uint64_t CPMS_MMA_PFETCNTL_SCOM = 0x200e0e30ull;
static const uint64_t CPMS_MMA_PFETCNTL_SCOM1 = 0x200e0e32ull;
static const uint64_t CPMS_MMA_PFETCNTL_SCOM2 = 0x200e0e33ull;

static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE = 0;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE_LEN = 2;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE = 4;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE = 5;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE = 12;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN = 8;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE = 20;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE_LEN = 4;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PG_STATE = 42;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PG_STATE_LEN = 4;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PG_SEL = 46;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PG_SEL_LEN = 4;
static const uint32_t CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 = 63;
// c/reg00000.H

static const uint64_t CPMS_MMA_PFETSTAT = 0x200e0e34ull;

static const uint32_t CPMS_MMA_PFETSTAT_S_ENABLED_SENSE = 0;
static const uint32_t CPMS_MMA_PFETSTAT_S_DISABLED_SENSE = 1;
static const uint32_t CPMS_MMA_PFETSTAT__ENABLE_ACTUAL = 16;
static const uint32_t CPMS_MMA_PFETSTAT__ENABLE_ACTUAL_LEN = 8;
// c/reg00000.H

static const uint64_t CPMS_PFETDLY = 0x200e0e1cull;

static const uint32_t CPMS_PFETDLY_POWDN_DLY = 0;
static const uint32_t CPMS_PFETDLY_POWDN_DLY_LEN = 4;
static const uint32_t CPMS_PFETDLY_L3_POWUP_DLY = 4;
static const uint32_t CPMS_PFETDLY_L3_POWUP_DLY_LEN = 4;
static const uint32_t CPMS_PFETDLY_CL2_POWUP_DLY = 8;
static const uint32_t CPMS_PFETDLY_CL2_POWUP_DLY_LEN = 4;
static const uint32_t CPMS_PFETDLY_MMA_POWUP_DLY = 12;
static const uint32_t CPMS_PFETDLY_MMA_POWUP_DLY_LEN = 4;
// c/reg00000.H

static const uint64_t CPMS_RVCSR_SCOM = 0x200e0e04ull;
static const uint64_t CPMS_RVCSR_SCOM1 = 0x200e0e06ull;
static const uint64_t CPMS_RVCSR_SCOM2 = 0x200e0e07ull;

static const uint32_t CPMS_RVCSR_RVID_ENABLE = 0;
static const uint32_t CPMS_RVCSR_RVRM_TUNE = 6;
static const uint32_t CPMS_RVCSR_RVRM_TUNE_LEN = 6;
static const uint32_t CPMS_RVCSR_RVID_ACTIVE = 32;
static const uint32_t CPMS_RVCSR_BYPASS_ACTIVE = 33;
// c/reg00000.H

static const uint64_t EC_LS_UNIT_HOLD_OUT0 = 0x20010280ull;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_CTRL = 0x20010485ull;

static const uint32_t EC_PC_COMMON_CTRL_0_RUN_Q = 48;
static const uint32_t EC_PC_COMMON_CTRL_1_RUN_Q = 49;
static const uint32_t EC_PC_COMMON_CTRL_2_RUN_Q = 50;
static const uint32_t EC_PC_COMMON_CTRL_3_RUN_Q = 51;
static const uint32_t EC_PC_COMMON_CTRL_4_RUN_Q = 52;
static const uint32_t EC_PC_COMMON_CTRL_5_RUN_Q = 53;
static const uint32_t EC_PC_COMMON_CTRL_6_RUN_Q = 54;
static const uint32_t EC_PC_COMMON_CTRL_7_RUN_Q = 55;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_HMEER = 0x20010496ull;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_OCC_SCOMC = 0x20010482ull;

static const uint32_t EC_PC_COMMON_OCC_SCOMC_MODE_CX_OCC_SCOMC = 54;
static const uint32_t EC_PC_COMMON_OCC_SCOMC_MODE_CX_OCC_SCOMC_LEN = 7;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_OCC_SCOMD = 0x20010483ull;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_SCOMC = 0x20010480ull;

static const uint32_t EC_PC_COMMON_SCOMC_MODE_CX_SCOMC = 54;
static const uint32_t EC_PC_COMMON_SCOMC_MODE_CX_SCOMC_LEN = 7;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_SCOMD = 0x20010481ull;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_SPATTN_RWX = 0x20010499ull;
static const uint64_t EC_PC_COMMON_SPATTN_WOX_AND = 0x20010498ull;
static const uint64_t EC_PC_COMMON_SPATTN_WOX_OR = 0x20010497ull;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_SPATTN_MASK = 0x2001049aull;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_SPR_MODE = 0x20010484ull;

static const uint32_t EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ = 10;
static const uint32_t EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ_LEN = 6;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL = 20;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL = 21;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL = 22;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL = 23;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL = 24;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL = 25;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL = 26;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL = 27;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_CY_DISABLE = 28;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_TFAC_HOLD_OUT = 0x200104b7ull;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_V0_HMER_RWX_WAND = 0x20010492ull;
static const uint64_t EC_PC_COMMON_V0_HMER_WOX_OR = 0x2001048eull;

static const uint32_t EC_PC_COMMON_V0_HMER_MALFUNCTION_ALERT = 0;
static const uint32_t EC_PC_COMMON_V0_HMER_CME_REQUEST = 1;
static const uint32_t EC_PC_COMMON_V0_HMER_PROC_RCVY_DONE = 2;
static const uint32_t EC_PC_COMMON_V0_HMER_TFAC_ERR = 4;
static const uint32_t EC_PC_COMMON_V0_HMER_XSCOM_FAIL = 8;
static const uint32_t EC_PC_COMMON_V0_HMER_XSCOM_DONE = 9;
static const uint32_t EC_PC_COMMON_V0_HMER_PROC_RCVY_AGAIN = 11;
static const uint32_t EC_PC_COMMON_V0_HMER_SCOM_FIR_HMI = 16;
static const uint32_t EC_PC_COMMON_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND = 17;
static const uint32_t EC_PC_COMMON_V0_HMER_TRIG_FIR_HMI = 18;
static const uint32_t EC_PC_COMMON_V0_HMER_XSCOM_STATUS = 21;
static const uint32_t EC_PC_COMMON_V0_HMER_XSCOM_STATUS_LEN = 3;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_V1_HMER_RWX_WAND = 0x20010493ull;
static const uint64_t EC_PC_COMMON_V1_HMER_WOX_OR = 0x2001048full;

static const uint32_t EC_PC_COMMON_V1_HMER_MALFUNCTION_ALERT = 0;
static const uint32_t EC_PC_COMMON_V1_HMER_CME_REQUEST = 1;
static const uint32_t EC_PC_COMMON_V1_HMER_PROC_RCVY_DONE = 2;
static const uint32_t EC_PC_COMMON_V1_HMER_TFAC_ERR = 4;
static const uint32_t EC_PC_COMMON_V1_HMER_XSCOM_FAIL = 8;
static const uint32_t EC_PC_COMMON_V1_HMER_XSCOM_DONE = 9;
static const uint32_t EC_PC_COMMON_V1_HMER_PROC_RCVY_AGAIN = 11;
static const uint32_t EC_PC_COMMON_V1_HMER_SCOM_FIR_HMI = 16;
static const uint32_t EC_PC_COMMON_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND = 17;
static const uint32_t EC_PC_COMMON_V1_HMER_TRIG_FIR_HMI = 18;
static const uint32_t EC_PC_COMMON_V1_HMER_XSCOM_STATUS = 21;
static const uint32_t EC_PC_COMMON_V1_HMER_XSCOM_STATUS_LEN = 3;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_V2_HMER_RWX_WAND = 0x20010494ull;
static const uint64_t EC_PC_COMMON_V2_HMER_WOX_OR = 0x20010490ull;

static const uint32_t EC_PC_COMMON_V2_HMER_MALFUNCTION_ALERT = 0;
static const uint32_t EC_PC_COMMON_V2_HMER_CME_REQUEST = 1;
static const uint32_t EC_PC_COMMON_V2_HMER_PROC_RCVY_DONE = 2;
static const uint32_t EC_PC_COMMON_V2_HMER_TFAC_ERR = 4;
static const uint32_t EC_PC_COMMON_V2_HMER_XSCOM_FAIL = 8;
static const uint32_t EC_PC_COMMON_V2_HMER_XSCOM_DONE = 9;
static const uint32_t EC_PC_COMMON_V2_HMER_PROC_RCVY_AGAIN = 11;
static const uint32_t EC_PC_COMMON_V2_HMER_SCOM_FIR_HMI = 16;
static const uint32_t EC_PC_COMMON_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND = 17;
static const uint32_t EC_PC_COMMON_V2_HMER_TRIG_FIR_HMI = 18;
static const uint32_t EC_PC_COMMON_V2_HMER_XSCOM_STATUS = 21;
static const uint32_t EC_PC_COMMON_V2_HMER_XSCOM_STATUS_LEN = 3;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_V3_HMER_RWX_WAND = 0x20010495ull;
static const uint64_t EC_PC_COMMON_V3_HMER_WOX_OR = 0x20010491ull;

static const uint32_t EC_PC_COMMON_V3_HMER_MALFUNCTION_ALERT = 0;
static const uint32_t EC_PC_COMMON_V3_HMER_CME_REQUEST = 1;
static const uint32_t EC_PC_COMMON_V3_HMER_PROC_RCVY_DONE = 2;
static const uint32_t EC_PC_COMMON_V3_HMER_TFAC_ERR = 4;
static const uint32_t EC_PC_COMMON_V3_HMER_XSCOM_FAIL = 8;
static const uint32_t EC_PC_COMMON_V3_HMER_XSCOM_DONE = 9;
static const uint32_t EC_PC_COMMON_V3_HMER_PROC_RCVY_AGAIN = 11;
static const uint32_t EC_PC_COMMON_V3_HMER_SCOM_FIR_HMI = 16;
static const uint32_t EC_PC_COMMON_V3_HMER_THD_WAKE_BLOCKED_TM_SUSPEND = 17;
static const uint32_t EC_PC_COMMON_V3_HMER_TRIG_FIR_HMI = 18;
static const uint32_t EC_PC_COMMON_V3_HMER_XSCOM_STATUS = 21;
static const uint32_t EC_PC_COMMON_V3_HMER_XSCOM_STATUS_LEN = 3;
// c/reg00000.H

static const uint64_t EC_PC_FIR_CORE_ACTION0 = 0x20010446ull;
// c/reg00000.H

static const uint64_t EC_PC_FIR_CORE_ACTION1 = 0x20010447ull;
// c/reg00000.H

static const uint64_t EC_PC_FIR_CORE_RWX = 0x20010440ull;
static const uint64_t EC_PC_FIR_CORE_WOX_AND = 0x20010441ull;
static const uint64_t EC_PC_FIR_CORE_WOX_OR = 0x20010442ull;

static const uint32_t EC_PC_FIR_CORE_IF_SRAM_REC_ERROR = 0;
static const uint32_t EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR = 1;
static const uint32_t EC_PC_FIR_CORE_IF_RFILE_REC_ERROR = 2;
static const uint32_t EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR = 3;
static const uint32_t EC_PC_FIR_CORE_IF_LOG_REC_ERROR = 4;
static const uint32_t EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR = 5;
static const uint32_t EC_PC_FIR_CORE_UNUSED_6 = 6;
static const uint32_t EC_PC_FIR_CORE_VS_VSMM_ACC_ERR = 7;
static const uint32_t EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR = 8;
static const uint32_t EC_PC_FIR_CORE_VS_STF_ERROR = 9;
static const uint32_t EC_PC_FIR_CORE_UNUSED_10 = 10;
static const uint32_t EC_PC_FIR_CORE_SD_LOG_REC_ERROR = 11;
static const uint32_t EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR = 12;
static const uint32_t EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR = 13;
static const uint32_t EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR = 14;
static const uint32_t EC_PC_FIR_CORE_SD_L2_UE_ERROR = 15;
static const uint32_t EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR = 16;
static const uint32_t EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR = 17;
static const uint32_t EC_PC_FIR_CORE_MU_SRAM_PARITY_ERROR = 18;
static const uint32_t EC_PC_FIR_CORE_UNUSED_19 = 19;
static const uint32_t EC_PC_FIR_CORE_UNUSED_20 = 20;
static const uint32_t EC_PC_FIR_CORE_MU_LOG_REC_ERROR = 21;
static const uint32_t EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR = 22;
static const uint32_t EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR = 23;
static const uint32_t EC_PC_FIR_CORE_VS_LOG_REC_ERROR = 24;
static const uint32_t EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR = 25;
static const uint32_t EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR = 26;
static const uint32_t EC_PC_FIR_CORE_VS_DU_LOG_REC_ERROR = 27;
static const uint32_t EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR = 28;
static const uint32_t EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR = 29;
static const uint32_t EC_PC_FIR_CORE_LS_SETDELETE_ERROR = 30;
static const uint32_t EC_PC_FIR_CORE_LS_RFILE_REC_ERROR = 31;
static const uint32_t EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR = 32;
static const uint32_t EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR = 33;
static const uint32_t EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR = 34;
static const uint32_t EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR = 35;
static const uint32_t EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR = 36;
static const uint32_t EC_PC_FIR_CORE_LS_LOG_REC_ERROR = 37;
static const uint32_t EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR = 38;
static const uint32_t EC_PC_FIR_CORE_LS_NOT_MT_REC_ERROR = 39;
static const uint32_t EC_PC_FIR_CORE_UNUSED_40 = 40;
static const uint32_t EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR = 41;
static const uint32_t EC_PC_FIR_CORE_UNUSED_42 = 42;
static const uint32_t EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR = 43;
static const uint32_t EC_PC_FIR_CORE_UNUSED_44 = 44;
static const uint32_t EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR = 45;
static const uint32_t EC_PC_FIR_CORE_UNUSED_46 = 46;
static const uint32_t EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR = 47;
static const uint32_t EC_PC_FIR_CORE_UNUSED_48 = 48;
static const uint32_t EC_PC_FIR_CORE_UNUSED_49 = 49;
static const uint32_t EC_PC_FIR_CORE_UNUSED_50 = 50;
static const uint32_t EC_PC_FIR_CORE_UNUSED_51 = 51;
static const uint32_t EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED = 52;
static const uint32_t EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR = 53;
static const uint32_t EC_PC_FIR_CORE_UNUSED_54 = 54;
static const uint32_t EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR = 55;
static const uint32_t EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR = 56;
static const uint32_t EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR = 57;
static const uint32_t EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR = 58;
static const uint32_t EC_PC_FIR_CORE_PC_SCOM_ERROR = 59;
static const uint32_t EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR = 60;
static const uint32_t EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR = 61;
static const uint32_t EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR = 62;
static const uint32_t EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR = 63;
// c/reg00000.H

static const uint64_t EC_PC_FIR_CORE_FIRMASK_RW = 0x20010443ull;
static const uint64_t EC_PC_FIR_CORE_FIRMASK_WO_AND = 0x20010444ull;
static const uint64_t EC_PC_FIR_CORE_FIRMASK_WO_OR = 0x20010445ull;

static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR = 0;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR = 1;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR = 2;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR = 3;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR = 4;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR = 5;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_UNUSED_6 = 6;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR = 7;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR = 8;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR = 9;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_UNUSED_10 = 10;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR = 11;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR = 12;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR = 13;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR = 14;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR = 15;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR = 16;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR = 17;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_SRAM_PARITY_ERROR = 18;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_UNUSED_19 = 19;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_UNUSED_20 = 20;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_REC_ERROR = 21;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR = 22;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR = 23;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR = 24;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR = 25;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR = 26;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_VS_DU_LOG_REC_ERROR = 27;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR = 28;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR = 29;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR = 30;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR = 31;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR = 32;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR = 33;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR = 34;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR = 35;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR = 36;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR = 37;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR = 38;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_NOT_MT_REC_ERROR = 39;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_UNUSED_40 = 40;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR = 41;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_UNUSED_42 = 42;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR = 43;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_UNUSED_44 = 44;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR = 45;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_UNUSED_46 = 46;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR = 47;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_UNUSED_48 = 48;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_UNUSED_49 = 49;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_UNUSED_50 = 50;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_UNUSED_51 = 51;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED = 52;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR = 53;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_UNUSED_54 = 54;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR = 55;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR = 56;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR = 57;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR = 58;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR = 59;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR = 60;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR = 61;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR = 62;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR = 63;
// c/reg00000.H

static const uint64_t EC_PC_FIR_CORE_SYS = 0x2001044aull;
// c/reg00000.H

static const uint64_t EC_PC_FIR_CORE_WOF = 0x20010448ull;
// c/reg00000.H

static const uint64_t EC_PC_FIR_ERR_INJ = 0x2001044dull;

static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU = 0;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU = 1;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU = 2;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU = 3;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC = 4;
static const uint32_t EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL = 6;
static const uint32_t EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL = 7;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE = 8;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER = 9;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1 = 10;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP = 11;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK = 12;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK_LEN = 2;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK = 14;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK = 15;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND = 16;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL = 17;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL_LEN = 4;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK = 21;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK_LEN = 3;
// c/reg00000.H

static const uint64_t EC_PC_FIR_HOLD_OUT = 0x20010451ull;
// c/reg00000.H

static const uint64_t EC_PC_FIR_RAM_CTRL = 0x2001044full;
// c/reg00000.H

static const uint64_t EC_PC_FIR_RAM_MODEREG = 0x2001044eull;

static const uint32_t EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE = 0;
// c/reg00000.H

static const uint64_t EC_PC_FIR_RAM_STATUS = 0x20010450ull;
// c/reg00000.H

static const uint64_t EC_PC_FIR_RECOV_FWD_PROG_CTRL = 0x2001044bull;
// c/reg00000.H

static const uint64_t EC_PC_FIR_RECOV_THOLD = 0x2001044cull;

static const uint32_t EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET = 8;
static const uint32_t EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET_LEN = 2;
// c/reg00000.H

static const uint64_t EC_PC_IMA_EVENT_MASK = 0x20010400ull;

static const uint32_t EC_PC_IMA_EVENT_MASK_ECONL_0 = 0;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECRL_0 = 1;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECH_0 = 2;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECP_0 = 3;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECS_0 = 4;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECA_0 = 5;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECTA0_0 = 6;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECTA1_0 = 7;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECUS0_0 = 8;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECUS1_0 = 9;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECONL_1 = 10;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECRL_1 = 11;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECH_1 = 12;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECP_1 = 13;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECS_1 = 14;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECA_1 = 15;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECTA0_1 = 16;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECTA1_1 = 17;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECUS0_1 = 18;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECUS1_1 = 19;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECONL_2 = 20;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECRL_2 = 21;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECH_2 = 22;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECP_2 = 23;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECS_2 = 24;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECA_2 = 25;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECTA0_2 = 26;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECTA1_2 = 27;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECUS0_2 = 28;
static const uint32_t EC_PC_IMA_EVENT_MASK_ECUS1_2 = 29;
static const uint32_t EC_PC_IMA_EVENT_MASK_IC_TAP = 30;
static const uint32_t EC_PC_IMA_EVENT_MASK_IC_TAP_LEN = 3;
static const uint32_t EC_PC_IMA_EVENT_MASK_DIS_WRAP = 33;
static const uint32_t EC_PC_IMA_EVENT_MASK_FREEZE = 34;
static const uint32_t EC_PC_IMA_EVENT_MASK_ONL_OVR = 35;
static const uint32_t EC_PC_IMA_EVENT_MASK_DIS_D_PRE = 36;
static const uint32_t EC_PC_IMA_EVENT_MASK_DIS_I_PRE = 37;
// c/reg00000.H

static const uint64_t EC_PC_IMA_TRACE = 0x20010401ull;

static const uint32_t EC_PC_IMA_TRACE_SAMPSEL = 0;
static const uint32_t EC_PC_IMA_TRACE_SAMPSEL_LEN = 2;
static const uint32_t EC_PC_IMA_TRACE_CPMC_LOAD = 2;
static const uint32_t EC_PC_IMA_TRACE_CPMC_LOAD_LEN = 32;
static const uint32_t EC_PC_IMA_TRACE_CPMC1SEL = 34;
static const uint32_t EC_PC_IMA_TRACE_CPMC1SEL_LEN = 7;
static const uint32_t EC_PC_IMA_TRACE_CPMC2SEL = 41;
static const uint32_t EC_PC_IMA_TRACE_CPMC2SEL_LEN = 7;
static const uint32_t EC_PC_IMA_TRACE_BUFFERSIZE = 48;
static const uint32_t EC_PC_IMA_TRACE_BUFFERSIZE_LEN = 3;
// c/reg00000.H

static const uint64_t EC_PC_PMC_CORE_THREAD_STATE = 0x20010412ull;
// c/reg00000.H

static const uint64_t EC_PC_PMC_UPDATE = 0x20010414ull;

static const uint32_t EC_PC_PMC_UPDATE_PMC_UPDATE_MSR_S_ON_SRESET = 0;
// c/reg00000.H

static const uint64_t EC_PC_PMC_THREAD_INFO = 0x20010413ull;
// c/reg00000.H

static const uint64_t EC_PC_PMU_PMUC_SIER_MASK = 0x20010406ull;
// c/reg00000.H

static const uint64_t EC_PC_PMU_PMUC_SRC_MASK = 0x20010407ull;
// c/reg00000.H

static const uint64_t EC_PC_PMU_SPRCOR_CORE_FUSES = 0x2001040eull;
// c/reg00000.H

static const uint64_t EC_PC_PMU_SPRCOR_HID = 0x2001043bull;

static const uint32_t EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE = 1;
static const uint32_t EC_PC_PMU_SPRCOR_HID_FLUSH_IC = 2;
static const uint32_t EC_PC_PMU_SPRCOR_HID_EN_ATTN = 3;
static const uint32_t EC_PC_PMU_SPRCOR_HID_HILE = 4;
static const uint32_t EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY = 5;
static const uint32_t EC_PC_PMU_SPRCOR_HID_MEGAMOUTH = 6;
static const uint32_t EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET = 7;
static const uint32_t EC_PC_PMU_SPRCOR_HID_RADIX_MODE = 8;
static const uint32_t EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED = 9;
static const uint32_t EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED = 10;
static const uint32_t EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 = 11;
static const uint32_t EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 = 12;
// c/reg00000.H

static const uint64_t EC_PC_PMU_SPRCOR_HV_STATE = 0x2001040dull;
// c/reg00001.H

static const uint64_t EC_PC_PMU_SPRCOR_INV_ERATE = 0x2001040full;
// c/reg00001.H

static const uint64_t EC_PC_PMU_SPRCOR_SCOMC = 0x20010408ull;
// c/reg00001.H

static const uint64_t EC_PC_PMU_SPRCOR_SCOMC_EN = 0x2001040aull;
// c/reg00001.H

static const uint64_t EC_PC_PMU_SPRCOR_SHID0 = 0x2001040cull;
// c/reg00001.H

static const uint64_t EC_PC_PWM_EVENTS = 0x20010aa2ull;

static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32 = 32;
static const uint32_t EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD = 33;
static const uint32_t EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD_LEN = 7;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40 = 40;
static const uint32_t EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD = 41;
static const uint32_t EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD_LEN = 7;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48 = 48;
static const uint32_t EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD = 49;
static const uint32_t EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD_LEN = 3;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52 = 52;
static const uint32_t EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD = 53;
static const uint32_t EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD_LEN = 3;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56 = 56;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57 = 57;
static const uint32_t EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS = 58;
static const uint32_t EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS_LEN = 2;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60 = 60;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61 = 61;
static const uint32_t EC_PC_PWM_EVENTS_PMCM_THRESHOLD = 62;
static const uint32_t EC_PC_PWM_EVENTS_PMCM_THRESHOLD_LEN = 2;
// c/reg00001.H

static const uint64_t EC_PC_SCR0 = 0x20010486ull;
// c/reg00001.H

static const uint64_t EC_PC_SCR1 = 0x20010487ull;
// c/reg00001.H

static const uint64_t EC_PC_SCR2 = 0x20010488ull;
// c/reg00001.H

static const uint64_t EC_PC_SCR3 = 0x20010489ull;
// c/reg00001.H

static const uint64_t EC_PC_SCR4 = 0x2001048aull;
// c/reg00001.H

static const uint64_t EC_PC_SCR5 = 0x2001048bull;
// c/reg00001.H

static const uint64_t EC_PC_SCR6 = 0x2001048cull;
// c/reg00001.H

static const uint64_t EC_PC_SCR7 = 0x2001048dull;
// c/reg00001.H

static const uint64_t EC_PC_SPURR_FREQ_DETECT_CYC_CNT = 0x20010a9full;

static const uint32_t EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT = 0;
static const uint32_t EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT_LEN = 8;
// c/reg00001.H

static const uint64_t EC_PC_SPURR_FREQ_REF = 0x20010aa1ull;

static const uint32_t EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE = 0;
static const uint32_t EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE_LEN = 8;
// c/reg00001.H

static const uint64_t EC_PC_SPURR_FREQ_SCALE = 0x20010aa0ull;

static const uint32_t EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN = 0;
static const uint32_t EC_PC_SPURR_FREQ_SCALE_FACTOR = 1;
static const uint32_t EC_PC_SPURR_FREQ_SCALE_FACTOR_LEN = 7;
// c/reg00001.H

static const uint64_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS = 0x20010449ull;
// c/reg00001.H

static const uint64_t EC_PC_THRCTL_TCTLCOM_HANG_CONTROL = 0x20010452ull;

static const uint32_t EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT = 0;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_CORE_HANG_LIMIT_LEN = 8;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT = 8;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_NEST_HANG_LIMIT_LEN = 8;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_RETURN_GOOD_ON_COMP = 16;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT = 17;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_COMP_CNT_LIMIT_LEN = 8;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT = 25;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_HANG_REC_LIMIT_LEN = 3;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_USE_HANG_REC_LIMIT = 28;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK = 29;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HANG_CONTROL_ACTIVE_MASK_LEN = 5;
// c/reg00001.H

static const uint64_t EC_PC_THRCTL_TCTLCOM_RAS_MODEREG = 0x20010453ull;
// c/reg00001.H

static const uint64_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS = 0x20010454ull;
// c/reg00001.H

static const uint64_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT = 0x20010455ull;
// c/reg00001.H

static const uint64_t EC_PC_TOD_READ = 0x200104a3ull;
// c/reg00001.H

static const uint64_t EC_PC_TOD_SYNC000 = 0x200104a3ull;

static const uint32_t EC_PC_TOD_SYNC000_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC000_CHIP_TOD_STATUS_LEN = 4;
// c/reg00001.H

static const uint64_t EC_PC_TOD_SYNC001 = 0x200104a3ull;

static const uint32_t EC_PC_TOD_SYNC001_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC001_CHIP_TOD_STATUS_LEN = 4;
// c/reg00001.H

static const uint64_t EC_PC_TOD_SYNC010 = 0x200104a3ull;

static const uint32_t EC_PC_TOD_SYNC010_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC010_CHIP_TOD_STATUS_LEN = 4;
// c/reg00001.H

static const uint64_t EC_PC_TOD_SYNC011 = 0x200104a3ull;

static const uint32_t EC_PC_TOD_SYNC011_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC011_CHIP_TOD_STATUS_LEN = 4;
// c/reg00001.H

static const uint64_t EC_PC_TOD_SYNC100 = 0x200104a3ull;

static const uint32_t EC_PC_TOD_SYNC100_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC100_CHIP_TOD_STATUS_LEN = 4;
// c/reg00001.H

static const uint64_t EC_PC_TOD_SYNC101 = 0x200104a3ull;

static const uint32_t EC_PC_TOD_SYNC101_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC101_CHIP_TOD_STATUS_LEN = 4;
// c/reg00001.H

static const uint64_t EC_PC_TOD_SYNC110 = 0x200104a3ull;

static const uint32_t EC_PC_TOD_SYNC110_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC110_CHIP_TOD_STATUS_LEN = 4;
// c/reg00001.H

static const uint64_t EC_PC_TOD_SYNC111 = 0x200104a3ull;

static const uint32_t EC_PC_TOD_SYNC111_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC111_CHIP_TOD_STATUS_LEN = 4;
// c/reg00001.H

static const uint64_t EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG = 0x20010a40ull;

static const uint32_t EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00001.H

static const uint64_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG = 0x20010a41ull;

static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00001.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG = 0x20010a42ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00001.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG_0 = 0x20010a43ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00001.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG_1 = 0x20010a44ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00001.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG_2 = 0x20010a45ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_2_A = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_2_B = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_2_B_LEN = 24;
// c/reg00001.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG_3 = 0x20010a46ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_3_C = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_3_D = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_3_D_LEN = 24;
// c/reg00001.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG_4 = 0x20010a47ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_4_A = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_4_B = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_4_B_LEN = 24;
// c/reg00001.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG_5 = 0x20010a48ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_5_C = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_5_D = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_5_D_LEN = 24;
// c/reg00001.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG_9 = 0x20010a49ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00001.H

static const uint64_t EC_PC_TRACE2_TR0_TRACE_HI_DATA_REG = 0x20010a80ull;

static const uint32_t EC_PC_TRACE2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00001.H

static const uint64_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG = 0x20010a81ull;

static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00001.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG = 0x20010a82ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00001.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_0 = 0x20010a83ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00001.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_1 = 0x20010a84ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00001.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_2 = 0x20010a85ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_2_A = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_2_B = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_2_B_LEN = 24;
// c/reg00001.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_3 = 0x20010a86ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_3_C = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_3_D = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_3_D_LEN = 24;
// c/reg00001.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_4 = 0x20010a87ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_4_A = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_4_B = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_4_B_LEN = 24;
// c/reg00001.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_5 = 0x20010a88ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_5_C = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_5_D = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_5_D_LEN = 24;
// c/reg00001.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_9 = 0x20010a89ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00002.H

static const uint64_t EC_SD_SDP_SDCR_UNIT_HOLD_OUT0 = 0x20010240ull;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_ERR_INJ_REG = 0x2001080cull;

static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE = 0;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE = 4;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE = 8;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE_LEN = 2;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE = 10;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN = 13;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN = 14;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_ERR_RPT0 = 0x20010812ull;

static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR = 0;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR = 1;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR = 2;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR = 3;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR = 4;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR = 5;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR = 6;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR = 7;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR = 8;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR = 9;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR = 10;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR = 11;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR = 12;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR = 13;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR = 14;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR = 15;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR = 16;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR = 17;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR = 18;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR = 19;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR = 20;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR = 21;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR = 22;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR = 23;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR = 24;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR = 25;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR = 26;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR = 27;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR = 28;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR = 29;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR = 30;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT = 31;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR = 32;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL = 33;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT = 34;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE = 35;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ = 36;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR = 37;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR = 38;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR = 39;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR = 40;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR = 41;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_ERR_RPT1 = 0x20010813ull;

static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR = 0;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR = 1;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR = 2;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR = 3;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR = 4;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH = 5;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT = 6;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT = 7;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT = 8;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT = 9;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT = 10;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR = 11;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE = 12;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE = 13;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR = 14;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR = 15;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR = 16;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR = 17;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR = 18;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR = 19;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR = 20;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD = 21;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH = 22;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR = 23;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR = 24;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR = 25;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR = 26;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR = 27;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR = 28;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR = 29;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR = 30;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_FIR_ACTION0_REG = 0x20010806ull;

static const uint32_t L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0 = 0;
static const uint32_t L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0_LEN = 40;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_FIR_ACTION1_REG = 0x20010807ull;

static const uint32_t L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1 = 0;
static const uint32_t L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1_LEN = 40;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_FIR_MASK_REG_RW = 0x20010803ull;
static const uint64_t L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND = 0x20010804ull;
static const uint64_t L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR = 0x20010805ull;

static const uint32_t L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK = 0;
static const uint32_t L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK_LEN = 40;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_FIR_REG_RWX = 0x20010800ull;
static const uint64_t L2_L2MISC_L2CERRS_FIR_REG_WOX_AND = 0x20010801ull;
static const uint64_t L2_L2MISC_L2CERRS_FIR_REG_WOX_OR = 0x20010802ull;

static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE = 0;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE = 1;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE = 2;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED = 3;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO = 4;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO = 5;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED = 6;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED = 7;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE = 8;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED = 9;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED = 10;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED = 11;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT = 12;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT = 13;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR = 14;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED = 15;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR = 16;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR = 17;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR = 18;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK = 19;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK = 20;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK = 21;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR = 22;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP = 23;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR = 24;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR = 25;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR = 26;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR = 27;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT = 28;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING = 29;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH = 30;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT = 32;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE = 36;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG = 0x2001080dull;

static const uint32_t L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG = 0;
static const uint32_t L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE = 1;
static const uint32_t L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE = 2;
static const uint32_t L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE_LEN = 2;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_MODE_REG0 = 0x2001080aull;

static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_LRU_DIRECT_MAP = 0;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_RANDOM_EN = 1;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_SINGLE_MEM_EN = 2;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_SINGLE_MEM = 3;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_SINGLE_MEM_LEN = 8;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_L3_DIS = 11;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CO_SOFT_PURGE_ME_SX_EN = 12;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CO_SOFT_PURGE_ALL_LINES_EN = 13;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_DCBZ_TRASHMODE_EN = 14;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CAC_ERR_REPAIR_EN = 15;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_LINEDEL_ON_CAC_UE_EN = 16;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_HW_TRIG_LINEDEL_LDDISP_CE_EN = 17;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_L2_PB_ARB_RATE_SEL = 18;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_L2_PB_ARB_RATE_SEL_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_HASH_L3_ADDR_EN = 21;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN = 22;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CHIP_CONTAINED_MODE_EN = 23;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_Q_BIT_TID_MASK = 24;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_Q_BIT_TID_MASK_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_HASH_L2_ADDR_EN = 28;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_STQ_PF_EN = 32;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_PERFMON_INFO_SRC_ED_SEL = 34;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_SKIP_GRP_SCOPE_EN = 38;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_TM_DTT_DIS = 39;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_MODE_REG1 = 0x2001080bull;

static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS = 0;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS = 1;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE = 2;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE_LEN = 2;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV = 4;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV = 8;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN = 16;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE = 20;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN = 23;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN = 25;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM = 26;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM_LEN = 2;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG = 0x2001080full;

static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER = 0;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE = 1;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY = 9;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS = 10;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY = 11;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM = 16;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC = 19;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC_LEN = 9;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK = 28;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR = 29;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG = 0x2001080eull;

static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER = 0;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE = 1;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY = 9;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS = 10;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY = 11;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM = 16;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC = 19;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC_LEN = 9;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK = 28;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR = 29;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_RD_EPS_REG = 0x20010810ull;

static const uint32_t L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE = 0;
static const uint32_t L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE_LEN = 12;
static const uint32_t L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE = 12;
static const uint32_t L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE_LEN = 12;
static const uint32_t L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE = 24;
static const uint32_t L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE_LEN = 12;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_TOPOTABLE0 = 0x20010814ull;

static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_0_VAL = 0;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_1_VAL = 1;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_2_VAL = 2;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_3_VAL = 3;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_4_VAL = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_5_VAL = 5;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_6_VAL = 6;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_7_VAL = 7;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_0 = 8;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_0_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_1 = 12;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_1_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_2 = 16;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_2_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_3 = 20;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_3_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_4 = 24;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_4_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_5 = 28;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_5_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_6 = 32;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_6_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_7 = 36;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_7_LEN = 4;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_TOPOTABLE1 = 0x20010815ull;

static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL = 0;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL = 1;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL = 2;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL = 3;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL = 5;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL = 6;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL = 7;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_08 = 8;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_08_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_09 = 12;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_09_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_10 = 16;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_10_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_11 = 20;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_11_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_12 = 24;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_12_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_13 = 28;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_13_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_14 = 32;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_14_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_15 = 36;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_15_LEN = 4;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_TOPOTABLE2 = 0x20010816ull;

static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL = 0;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL = 1;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL = 2;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL = 3;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL = 5;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL = 6;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL = 7;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_16 = 8;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_16_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_17 = 12;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_17_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_18 = 16;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_18_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_19 = 20;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_19_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_20 = 24;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_20_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_21 = 28;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_21_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_22 = 32;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_22_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_23 = 36;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_23_LEN = 4;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_TOPOTABLE3 = 0x20010817ull;

static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL = 0;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL = 1;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL = 2;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL = 3;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL = 5;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL = 6;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL = 7;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_24 = 8;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_24_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_25 = 12;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_25_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_26 = 16;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_26_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_27 = 20;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_27_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_28 = 24;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_28_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_29 = 28;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_29_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_30 = 32;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_30_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_31 = 36;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_31_LEN = 4;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_WR_EPS_REG = 0x20010811ull;

static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE = 0;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE_LEN = 12;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE = 12;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE_LEN = 12;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE = 24;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL = 28;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN = 29;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE = 30;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE_LEN = 4;
// c/reg00002.H

static const uint64_t L2TRA_TR0_TRACE_HI_DATA_REG = 0x20010840ull;

static const uint32_t L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00002.H

static const uint64_t L2TRA_TR0_TRACE_LO_DATA_REG = 0x20010841ull;

static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00002.H

static const uint64_t L2TRA_TR0_CONFIG = 0x20010842ull;

static const uint32_t L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L2TRA_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t L2TRA_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L2TRA_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L2TRA_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t L2TRA_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t L2TRA_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00002.H

static const uint64_t L2TRA_TR0_CONFIG_0 = 0x20010843ull;

static const uint32_t L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00002.H

static const uint64_t L2TRA_TR0_CONFIG_1 = 0x20010844ull;

static const uint32_t L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00002.H

static const uint64_t L2TRA_TR0_CONFIG_2 = 0x20010845ull;

static const uint32_t L2TRA_TR0_CONFIG_2_A = 0;
static const uint32_t L2TRA_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t L2TRA_TR0_CONFIG_2_B = 24;
static const uint32_t L2TRA_TR0_CONFIG_2_B_LEN = 24;
// c/reg00002.H

static const uint64_t L2TRA_TR0_CONFIG_3 = 0x20010846ull;

static const uint32_t L2TRA_TR0_CONFIG_3_C = 0;
static const uint32_t L2TRA_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t L2TRA_TR0_CONFIG_3_D = 24;
static const uint32_t L2TRA_TR0_CONFIG_3_D_LEN = 24;
// c/reg00002.H

static const uint64_t L2TRA_TR0_CONFIG_4 = 0x20010847ull;

static const uint32_t L2TRA_TR0_CONFIG_4_A = 0;
static const uint32_t L2TRA_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t L2TRA_TR0_CONFIG_4_B = 24;
static const uint32_t L2TRA_TR0_CONFIG_4_B_LEN = 24;
// c/reg00002.H

static const uint64_t L2TRA_TR0_CONFIG_5 = 0x20010848ull;

static const uint32_t L2TRA_TR0_CONFIG_5_C = 0;
static const uint32_t L2TRA_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t L2TRA_TR0_CONFIG_5_D = 24;
static const uint32_t L2TRA_TR0_CONFIG_5_D_LEN = 24;
// c/reg00002.H

static const uint64_t L2TRA_TR0_CONFIG_9 = 0x20010849ull;

static const uint32_t L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00002.H

static const uint64_t L2TRA_TR1_TRACE_HI_DATA_REG = 0x20010880ull;

static const uint32_t L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00002.H

static const uint64_t L2TRA_TR1_TRACE_LO_DATA_REG = 0x20010881ull;

static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00002.H

static const uint64_t L2TRA_TR1_CONFIG = 0x20010882ull;

static const uint32_t L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L2TRA_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t L2TRA_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L2TRA_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L2TRA_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t L2TRA_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t L2TRA_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00002.H

static const uint64_t L2TRA_TR1_CONFIG_0 = 0x20010883ull;

static const uint32_t L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00002.H

static const uint64_t L2TRA_TR1_CONFIG_1 = 0x20010884ull;

static const uint32_t L2TRA_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L2TRA_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00002.H

static const uint64_t L2TRA_TR1_CONFIG_2 = 0x20010885ull;

static const uint32_t L2TRA_TR1_CONFIG_2_A = 0;
static const uint32_t L2TRA_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t L2TRA_TR1_CONFIG_2_B = 24;
static const uint32_t L2TRA_TR1_CONFIG_2_B_LEN = 24;
// c/reg00002.H

static const uint64_t L2TRA_TR1_CONFIG_3 = 0x20010886ull;

static const uint32_t L2TRA_TR1_CONFIG_3_C = 0;
static const uint32_t L2TRA_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t L2TRA_TR1_CONFIG_3_D = 24;
static const uint32_t L2TRA_TR1_CONFIG_3_D_LEN = 24;
// c/reg00002.H

static const uint64_t L2TRA_TR1_CONFIG_4 = 0x20010887ull;

static const uint32_t L2TRA_TR1_CONFIG_4_A = 0;
static const uint32_t L2TRA_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t L2TRA_TR1_CONFIG_4_B = 24;
static const uint32_t L2TRA_TR1_CONFIG_4_B_LEN = 24;
// c/reg00002.H

static const uint64_t L2TRA_TR1_CONFIG_5 = 0x20010888ull;

static const uint32_t L2TRA_TR1_CONFIG_5_C = 0;
static const uint32_t L2TRA_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t L2TRA_TR1_CONFIG_5_D = 24;
static const uint32_t L2TRA_TR1_CONFIG_5_D_LEN = 24;
// c/reg00002.H

static const uint64_t L2TRA_TR1_CONFIG_9 = 0x20010889ull;

static const uint32_t L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00002.H

static const uint64_t L3_MISC_L3CERRS_ERR_INJ_REG = 0x20010c0dull;

static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ = 0;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ = 1;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE = 2;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE_LEN = 2;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ = 4;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ = 5;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE = 6;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ = 7;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ = 8;
// c/reg00002.H

static const uint64_t L3_MISC_L3CERRS_FIR_ACTION0_REG = 0x20010c06ull;

static const uint32_t L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0 = 0;
static const uint32_t L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0_LEN = 33;
// c/reg00002.H

static const uint64_t L3_MISC_L3CERRS_FIR_ACTION1_REG = 0x20010c07ull;

static const uint32_t L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1 = 0;
static const uint32_t L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1_LEN = 33;
// c/reg00002.H

static const uint64_t L3_MISC_L3CERRS_FIR_MASK_REG_RW = 0x20010c03ull;
static const uint64_t L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND = 0x20010c04ull;
static const uint64_t L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR = 0x20010c05ull;
// c/reg00002.H

static const uint64_t L3_MISC_L3CERRS_FIR_REG_RWX = 0x20010c00ull;
static const uint64_t L3_MISC_L3CERRS_FIR_REG_WOX_AND = 0x20010c01ull;
static const uint64_t L3_MISC_L3CERRS_FIR_REG_WOX_OR = 0x20010c02ull;

static const uint32_t L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR = 0;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR = 1;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_FIR_SPARE2 = 2;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL = 3;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_RD_CE_DET_NOT_LINDEL_REQ = 4;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_RD_UE_DET = 5;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_RD_SUE_DET = 6;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_WR_DATA_CE_FROM_PB = 7;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_WR_DATA_UE_FROM_PB = 8;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_WR_DATA_SUE_FROM_PB = 9;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_WR_DATA_CE_FROM_L2 = 10;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_WR_DATA_UE_FROM_L2 = 11;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_WR_DATA_SUE_FROM_L2_OR_WIHPC = 12;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET = 13;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET = 14;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR = 15;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR = 16;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR = 17;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_ADDR_HANG_DETECTED = 18;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT = 19;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20 = 20;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21 = 21;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22 = 22;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED = 23;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR = 24;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR = 25;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE = 26;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_LRU_ERROR = 28;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR = 29;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD = 31;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD = 32;
// c/reg00002.H

static const uint64_t L3_MISC_L3CERRS_ERR_RPT0_REG = 0x20010c10ull;

static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR = 0;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR = 1;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR = 2;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR = 3;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR = 4;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR = 5;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR = 6;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR = 7;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR = 8;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR = 9;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR = 10;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR = 11;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR = 12;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR = 13;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR = 14;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2 = 15;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3 = 16;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR = 17;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR = 18;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR = 19;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR = 20;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR = 24;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR = 25;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR = 26;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR = 27;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR = 28;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR = 29;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR = 30;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR = 31;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR = 32;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR = 33;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR = 34;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR = 35;
// c/reg00002.H

static const uint64_t L3_MISC_L3CERRS_ERR_RPT1_REG = 0x20010c17ull;

static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR = 0;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR = 1;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR = 2;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR = 3;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR = 4;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR = 5;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR = 6;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0 = 7;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0 = 8;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_PBEXCA0_CMD_REQ_ERR0 = 9;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_PBEXCA0_CMD_REQ_ERR1 = 10;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_PBEXCA0_CMD_REQ_ERR2 = 11;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_PBEXCA1_CMD_REQ_ERR0 = 12;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_PBEXCA1_CMD_REQ_ERR1 = 13;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_PBEXCA1_CMD_REQ_ERR2 = 14;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0 = 15;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1 = 16;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3PBEXCA0_OVERFLOW_ERR = 17;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3PBEXCA1_OVERFLOW_ERR = 18;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3PBEXCA0_UNDERFLOW_ERR = 19;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3PBEXCA1_UNDERFLOW_ERR = 20;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR = 21;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR = 22;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR = 23;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE = 24;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR = 25;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR = 26;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR = 27;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR = 28;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR = 29;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR = 30;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR = 31;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR = 32;
// c/reg00002.H

static const uint64_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG = 0x20010c29ull;

static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL = 0;
static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL_LEN = 12;
static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL = 12;
static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL_LEN = 12;
static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL = 24;
static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL_LEN = 12;
static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG = 36;
// c/reg00002.H

static const uint64_t L3_MISC_L3CERRS_WR_EPSILON_CFG_REG = 0x20010c2aull;

static const uint32_t L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL = 0;
static const uint32_t L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER1_EPS_VAL_LEN = 12;
static const uint32_t L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL = 12;
static const uint32_t L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_WT4CR_WR_TIER2_EPS_VAL_LEN = 12;
static const uint32_t L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EPS_ON_LCO = 24;
static const uint32_t L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EN_WT4CR_WR_EXTENDED_MODE = 25;
static const uint32_t L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE = 26;
static const uint32_t L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_STEP_MODE_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE = 30;
static const uint32_t L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_L3_EPS_DIVIDER_MODE_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_WR_EPSILON_CFG_REG_EPS_CNT_USE_L3_DIVIDER_EN = 34;
// c/reg00002.H

static const uint64_t L3_MISC_L3CERRS_LCO_TARGET_ID_CTL_REG = 0x20010c0bull;

static const uint32_t L3_MISC_L3CERRS_LCO_TARGET_ID_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_LCO_TARGET_ID_CTL_REG_BACKING_CNT_CFG = 1;
static const uint32_t L3_MISC_L3CERRS_LCO_TARGET_ID_CTL_REG_BACKING_CNT_CFG_LEN = 3;
// c/reg00002.H

static const uint64_t L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG = 0x20010c15ull;

static const uint32_t L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS = 0;
static const uint32_t L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS_LEN = 5;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG = 0x20010c11ull;

static const uint32_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG_LEN = 16;
static const uint32_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG = 16;
static const uint32_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG_LEN = 2;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_MODE_REG0 = 0x20010c2bull;

static const uint32_t L3_MISC_L3CERRS_MODE_REG0__DISABLED_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__DMAP_CI_EN_CFG = 1;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__RDSN_LINEDEL_UE_EN = 2;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__NO_ALLOCATE_MODE_EN = 3;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__NO_ALLOCATE_MODE_ACTIVE = 4;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_PF_CFG_SKIP_GRP_SCOPE_EN = 5;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_CO_MEM_ME_BEHAVIOR_CFG = 6;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_CO_MEM_ME_BEHAVIOR_CFG_LEN = 2;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__LCO_RTY_LIMIT_DISABLE = 8;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__ADDR_HASH_EN_CFG = 11;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__MSTR_RTY_BACKOFF_EN_CFG = 12;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_CERRS_LCO_RETRY_THROTL_DIS = 13;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__HANG_POLL_PULSE_DIV = 14;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__HANG_POLL_PULSE_DIV_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__DATA_POLL_PULSE_DIV = 18;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__DATA_POLL_PULSE_DIV_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CFG_CHIP_ADDR_EXT_MASK_EN = 23;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CFG_CHIP_ADDR_EXT_MASK_EN_LEN = 7;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_LRU_DECR_EN_CFG = 30;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_LRU_DECR_PROB_SEL_CFG = 31;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_LRU_DECR_PROB_SEL_CFG_LEN = 2;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_LRU_DECR_SUB_SEL_CFG = 33;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_LRU_DECR_SUB_SEL_CFG_LEN = 3;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG = 36;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_MODE_REG1 = 0x20010c0aull;

static const uint32_t L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG = 1;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG_LEN = 5;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG = 6;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG_LEN = 32;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG = 38;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_PHYP_PURGE_REG = 0x20010c14ull;

static const uint32_t L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_REQ = 0;
static const uint32_t L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE = 1;
static const uint32_t L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_TTYPE_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_NEXT_CE = 5;
static const uint32_t L3_MISC_L3CERRS_PHYP_PURGE_REG_LINE_DEL_ON_ALL_CE = 6;
static const uint32_t L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_BUSY_ERR = 9;
static const uint32_t L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER = 12;
static const uint32_t L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_MEMBER_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR = 16;
static const uint32_t L3_MISC_L3CERRS_PHYP_PURGE_REG_PURGE_DIR_ADDR_LEN = 11;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_PM_LCO_DIS_REG = 0x20010c16ull;

static const uint32_t L3_MISC_L3CERRS_PM_LCO_DIS_REG_L3_PM_LCO_DIS_CFG = 0;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_PM_PURGE_REG = 0x20010c13ull;

static const uint32_t L3_MISC_L3CERRS_PM_PURGE_REG_REQ = 0;
static const uint32_t L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR = 1;
static const uint32_t L3_MISC_L3CERRS_PM_PURGE_REG_ABORT = 2;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_PRD_PURGE_REG = 0x20010c0eull;

static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ = 0;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE = 1;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE = 5;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE = 6;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR = 9;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER = 12;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR = 16;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR_LEN = 11;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD = 0x20010c25ull;

static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID = 0;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID = 1;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID = 2;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID = 3;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID = 5;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID = 6;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID = 7;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0 = 8;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1 = 12;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2 = 16;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3 = 20;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4 = 24;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5 = 28;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6 = 32;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7 = 36;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_LEN = 4;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD = 0x20010c26ull;

static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID = 0;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID = 1;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID = 2;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID = 3;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID = 5;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID = 6;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID = 7;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08 = 8;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09 = 12;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10 = 16;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11 = 20;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12 = 24;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13 = 28;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14 = 32;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15 = 36;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_LEN = 4;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD = 0x20010c27ull;

static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID = 0;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID = 1;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID = 2;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID = 3;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID = 5;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID = 6;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID = 7;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16 = 8;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17 = 12;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18 = 16;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19 = 20;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20 = 24;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21 = 28;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22 = 32;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23 = 36;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_LEN = 4;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD = 0x20010c28ull;

static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID = 0;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID = 1;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID = 2;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID = 3;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID = 5;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID = 6;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID = 7;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24 = 8;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25 = 12;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26 = 16;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27 = 20;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28 = 24;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29 = 28;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30 = 32;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31 = 36;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_LEN = 4;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG = 0x20010c0cull;

static const uint32_t L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG_LEN = 2;
// c/reg00003.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_CSEL = 0x20010047ull;
// c/reg00003.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_CTRL = 0x20010045ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP = 7;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP = 8;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP = 9;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP = 10;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112 = 11;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP = 13;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415 = 14;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415_LEN = 2;
// c/reg00003.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR = 0x2001004bull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_ENABLE_SPLIT_CORE = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR_SPARE2TO4 = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR_SPARE2TO4_LEN = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR_SCOPE = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR_SCOPE_LEN = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR = 8;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR_LEN = 43;
// c/reg00003.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS = 0x2001004aull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_ERROR = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_TRACE_ACTIVE = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_PDBAR_ERROR = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_RESERVED_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_FSM_LEN = 7;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT = 12;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS_IMA_COUNT_LEN = 4;
// c/reg00003.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_LAST = 0x20010043ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS = 12;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_LAST_HTM_LAST_ADDRESS_LEN = 45;
// c/reg00003.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_MEM = 0x20010041ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE_LEN = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE_LEN = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_BASE = 12;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_BASE_LEN = 28;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE = 40;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_LEN = 9;
// c/reg00003.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_MODE = 0x20010040ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0 = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE_LEN = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV = 10;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2 = 11;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP = 13;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP = 14;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP = 15;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL = 16;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY = 17;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP = 18;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES = 19;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES_LEN = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET = 24;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET_LEN = 8;
// c/reg00003.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_PTRC = 0x20010046ull;
// c/reg00003.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_STAT = 0x20010042ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_PURGE_IN_PROG = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_PURGE_DONE = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_CRESP_OV = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_REPAIR = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_BUF_WAIT = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_STATUS_TRIG_DROPPED_LT = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_ADDR_ERROR = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_STATUS_REC_DROPPED_LT = 7;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_INIT = 8;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_PREREQ = 9;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_READY = 10;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_TRACING = 11;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_PAUSED = 12;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_FLUSH = 13;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_COMPLETE = 14;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_ENABLE = 15;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_STAMP = 16;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_STATUS_SCOM_ERROR = 17;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_STATUS_UNUSED = 18;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_STATUS_UNUSED_LEN = 2;
// c/reg00003.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_TRIG = 0x20010044ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_START = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE_LEN = 10;
// c/reg00003.H

static const uint64_t NC_NCCHTM_NCCHTSC_MEM_OP_CTR = 0x20010048ull;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_ERR_RPT_REG = 0x20010c4eull;

static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR = 0;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE = 1;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR = 2;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR = 3;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR = 4;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR = 5;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR = 6;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR = 7;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR = 8;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR = 9;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR = 10;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR = 11;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR = 12;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR = 13;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR = 14;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR = 15;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR = 16;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR = 17;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR = 18;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1 = 19;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2 = 20;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1 = 21;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2 = 22;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1 = 23;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT = 24;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR = 25;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR = 26;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR = 27;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR = 28;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR = 29;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR = 30;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR = 31;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR = 32;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR = 33;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_FIR_ACTION0_REG = 0x20010c46ull;

static const uint32_t NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0 = 0;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0_LEN = 29;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_FIR_ACTION1_REG = 0x20010c47ull;

static const uint32_t NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1 = 0;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1_LEN = 29;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_FIR_MASK_REG_RW = 0x20010c43ull;
static const uint64_t NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_AND = 0x20010c44ull;
static const uint64_t NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_OR = 0x20010c45ull;

static const uint32_t NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK = 0;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK_LEN = 29;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_FIR_REG_RWX = 0x20010c40ull;
static const uint64_t NC_NCMISC_NCSCOMS_FIR_REG_WOX_AND = 0x20010c41ull;
static const uint64_t NC_NCMISC_NCSCOMS_FIR_REG_WOX_OR = 0x20010c42ull;

static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR = 0;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR = 1;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR = 2;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR = 3;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR = 4;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD = 5;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG = 6;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR = 7;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR = 8;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT = 9;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT = 10;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT = 11;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR = 12;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR = 14;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR = 19;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR = 20;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR = 21;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_INJ_REG = 0x20010c4dull;

static const uint32_t NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ = 0;
static const uint32_t NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ_LEN = 2;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG = 0x20010c51ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR_LEN = 40;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_MODE_REG = 0x20010c4aull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT_LEN = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK = 9;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK_LEN = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN = 13;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN = 14;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN = 15;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE = 16;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE_LEN = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE = 24;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE_LEN = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH = 32;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH_LEN = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC = 40;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC_LEN = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN = 48;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2 = 0x20010c4bull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV_LEN = 10;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV = 18;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV = 22;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV = 26;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV_LEN = 10;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3 = 0x20010c4cull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_EN = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_THRESHOLD = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_THRESHOLD_LEN = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_CMPLT_CNT = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_CMPLT_CNT_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_DELAY_CNT = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_DELAY_CNT_LEN = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_PACING_MST_DLY_EN = 16;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_PACING_PMU_THRESH = 17;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_PACING_PMU_THRESH_LEN = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_SMF_ENABLE = 20;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0 = 0x20010c52ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID = 13;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID = 14;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID = 26;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID = 27;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID = 39;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID = 40;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID_LEN = 12;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1 = 0x20010c53ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID = 13;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID = 14;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID = 26;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID = 27;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID = 39;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID = 40;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID_LEN = 12;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG = 0x20010c50ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR_LEN = 38;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_STATUS_REG = 0x20010c4full;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE = 3;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0 = 0x20010c54ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL = 5;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL = 6;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL = 7;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0 = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1 = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2 = 16;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3 = 20;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4 = 24;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5 = 28;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6 = 32;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7 = 36;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_LEN = 4;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1 = 0x20010c55ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL = 5;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL = 6;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL = 7;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08 = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09 = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10 = 16;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11 = 20;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12 = 24;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13 = 28;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14 = 32;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15 = 36;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_LEN = 4;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2 = 0x20010c56ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL = 5;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL = 6;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL = 7;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16 = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17 = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18 = 16;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19 = 20;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20 = 24;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21 = 28;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22 = 32;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23 = 36;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_LEN = 4;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3 = 0x20010c57ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL = 5;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL = 6;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL = 7;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24 = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25 = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26 = 16;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27 = 20;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28 = 24;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29 = 28;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30 = 32;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31 = 36;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_LEN = 4;
// c/reg00003.H

static const uint64_t PSCOM_ERROR_MASK = 0x20010002ull;

static const uint32_t PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR = 3;
static const uint32_t PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t PSCOM_ERROR_MASK_UL_P0_ERROR = 5;
static const uint32_t PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t PSCOM_ERROR_MASK_GENERAL_TIMEOUT = 15;
static const uint32_t PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
// c/reg00003.H

static const uint64_t PSCOM_MODE_REG = 0x20010000ull;

static const uint32_t PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR = 0;
static const uint32_t PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR = 1;
static const uint32_t PSCOM_MODE_REG_UNUSED_MODE_REG_BIT_2 = 2;
static const uint32_t PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR = 3;
static const uint32_t PSCOM_MODE_REG_WATCHDOG_ENABLE = 4;
static const uint32_t PSCOM_MODE_REG_SCOM_HANG_LIMIT = 5;
static const uint32_t PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN = 2;
static const uint32_t PSCOM_MODE_REG_FORCE_ALL_RINGS = 7;
static const uint32_t PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE = 8;
static const uint32_t PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT = 9;
static const uint32_t PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN = 3;
// c/reg00003.H

static const uint64_t PSCOM_STATUS_ERROR_REG = 0x20010001ull;

static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_P0_ERROR = 3;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_P0_ERROR = 5;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_GENERAL_TIMEOUT = 15;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_WDATA_PARITY_ERROR = 18;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_ADDRESS_PARITY_ERROR = 19;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_WDATA_PARITY_ERROR = 20;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_P0_ERROR = 21;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_UL_RDATA_PARITY_ERROR = 22;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_UL_P0_ERROR = 23;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_INTERFACE_MACHINE = 24;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_P2S_MACHINE = 25;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 26;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 27;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 28;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_WRITE_NVLD = 29;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_READ_NVLD = 30;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_ADDR_INVALID = 31;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_COMMAND_PARITY_ERROR = 32;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_GENERAL_TIMEOUT = 33;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 34;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 35;
// c/reg00003.H

static const uint64_t QME_CDBA = 0x200e0800ull;

static const uint32_t QME_CDBA_QME_CDBA_MESSAGE_NUMBER = 0;
static const uint32_t QME_CDBA_QME_CDBA_MESSAGE_NUMBER_LEN = 8;
// c/reg00003.H

static const uint64_t QME_CDBB = 0x200e0804ull;

static const uint32_t QME_CDBB_QME_CDBB_MESSAGE_NUMBER = 0;
static const uint32_t QME_CDBB_QME_CDBB_MESSAGE_NUMBER_LEN = 8;
// c/reg00003.H

static const uint64_t QME_CIIR = 0x200e0874ull;

static const uint32_t QME_CIIR_HMI_REQUEST = 0;
static const uint32_t QME_CIIR_MSGSND_INTR_INJECT = 28;
static const uint32_t QME_CIIR_MSGSND_INTR_INJECT_LEN = 4;
static const uint32_t QME_CIIR_MSGSNDU_INTR_INJECT = 60;
static const uint32_t QME_CIIR_MSGSNDU_INTR_INJECT_LEN = 4;
// c/reg00003.H

static const uint64_t QME_CISR = 0x200e0878ull;

static const uint32_t QME_CISR_HYP_INTR_PRESENT = 0;
static const uint32_t QME_CISR_HYP_INTR_PRESENT_LEN = 4;
static const uint32_t QME_CISR_OS_INTR_PRESENT = 4;
static const uint32_t QME_CISR_OS_INTR_PRESENT_LEN = 4;
static const uint32_t QME_CISR_MSGSND_INTR_PRESENT = 8;
static const uint32_t QME_CISR_MSGSND_INTR_PRESENT_LEN = 4;
static const uint32_t QME_CISR_EBB_INTR_PRESENT = 12;
static const uint32_t QME_CISR_EBB_INTR_PRESENT_LEN = 4;
static const uint32_t QME_CISR_HYP_INTR_REQUESTED = 16;
static const uint32_t QME_CISR_HYP_INTR_REQUESTED_LEN = 4;
static const uint32_t QME_CISR_OS_INTR_REQUESTED = 20;
static const uint32_t QME_CISR_OS_INTR_REQUESTED_LEN = 4;
static const uint32_t QME_CISR_MSGSND_INTR_REQUESTED = 24;
static const uint32_t QME_CISR_MSGSND_INTR_REQUESTED_LEN = 4;
static const uint32_t QME_CISR_MSGSND_INTR_SAMPLE = 28;
static const uint32_t QME_CISR_MSGSND_INTR_SAMPLE_LEN = 4;
static const uint32_t QME_CISR_MSGSND_ACK = 32;
static const uint32_t QME_CISR_MALF_ALERT_PRESENT = 33;
static const uint32_t QME_CISR_MALF_ALERT_REQUESTED = 34;
static const uint32_t QME_CISR_MSGSNDU_INTR_PRESENT = 36;
static const uint32_t QME_CISR_MSGSNDU_INTR_PRESENT_LEN = 4;
static const uint32_t QME_CISR_MSGSNDU_INTR_REQUESTED = 40;
static const uint32_t QME_CISR_MSGSNDU_INTR_REQUESTED_LEN = 4;
static const uint32_t QME_CISR_MSGSNDU_INTR_SAMPLE = 44;
static const uint32_t QME_CISR_MSGSNDU_INTR_SAMPLE_LEN = 4;
static const uint32_t QME_CISR_TFCS_DEC_PRESENT = 48;
static const uint32_t QME_CISR_TFCS_DEC_PRESENT_LEN = 4;
static const uint32_t QME_CISR_TFCS_DEC_REQUESTED = 52;
static const uint32_t QME_CISR_TFCS_DEC_REQUESTED_LEN = 4;
static const uint32_t QME_CISR_TFCS_HDEC_PRESENT = 56;
static const uint32_t QME_CISR_TFCS_HDEC_REQUESTED = 57;
static const uint32_t QME_CISR_DPDES_INTR_PRESENT = 58;
static const uint32_t QME_CISR_DPDES_INTR_REQUESTED = 59;
static const uint32_t QME_CISR_REG_WKUP_PRESENT = 62;
static const uint32_t QME_CISR_REG_WKUP_REQUESTED = 63;
// c/reg00003.H

static const uint64_t QME_CSIR = 0x200e087cull;

static const uint32_t QME_CSIR_QME_CSIR_DATA = 0;
static const uint32_t QME_CSIR_QME_CSIR_DATA_LEN = 64;
// c/reg00003.H

static const uint64_t QME_DCSR = 0x200e0870ull;

static const uint32_t QME_DCSR_PLS_T0 = 0;
static const uint32_t QME_DCSR_PLS_T0_LEN = 4;
static const uint32_t QME_DCSR_PLS_T1 = 4;
static const uint32_t QME_DCSR_PLS_T1_LEN = 4;
static const uint32_t QME_DCSR_PLS_T2 = 8;
static const uint32_t QME_DCSR_PLS_T2_LEN = 4;
static const uint32_t QME_DCSR_PLS_T3 = 12;
static const uint32_t QME_DCSR_PLS_T3_LEN = 4;
static const uint32_t QME_DCSR_SL_T0 = 16;
static const uint32_t QME_DCSR_SL_T0_LEN = 2;
static const uint32_t QME_DCSR_SL_T1 = 18;
static const uint32_t QME_DCSR_SL_T1_LEN = 2;
static const uint32_t QME_DCSR_SL_T2 = 20;
static const uint32_t QME_DCSR_SL_T2_LEN = 2;
static const uint32_t QME_DCSR_SL_T3 = 22;
static const uint32_t QME_DCSR_SL_T3_LEN = 2;
static const uint32_t QME_DCSR_SRESET_MSR_S = 24;
// c/reg00004.H

static const uint64_t QME_PMCRS = 0x200e0860ull;

static const uint32_t QME_PMCRS_QME_PMCRS_DATA = 0;
static const uint32_t QME_PMCRS_QME_PMCRS_DATA_LEN = 64;
// c/reg00004.H

static const uint64_t QME_PMSRS = 0x200e0864ull;

static const uint32_t QME_PMSRS_QME_PMSRS_DATA = 0;
static const uint32_t QME_PMSRS_QME_PMSRS_DATA_LEN = 64;
// c/reg00004.H

static const uint64_t QME_PSCRS0 = 0x200e0850ull;

static const uint32_t QME_PSCRS0_DPDES_EXIT_ENABLE = 0;
static const uint32_t QME_PSCRS0_SD = 1;
static const uint32_t QME_PSCRS0_ESL = 2;
static const uint32_t QME_PSCRS0_EC = 3;
static const uint32_t QME_PSCRS0_PSLL = 4;
static const uint32_t QME_PSCRS0_PSLL_LEN = 4;
static const uint32_t QME_PSCRS0_HYP_VIRT_EXIT_ENABLE = 8;
static const uint32_t QME_PSCRS0_UV_DB_EXIT_ENABLE = 9;
static const uint32_t QME_PSCRS0_HYP_DB_EXIT_ENABLE = 10;
static const uint32_t QME_PSCRS0_EXT_EXIT_ENABLE = 11;
static const uint32_t QME_PSCRS0_DEC_EXIT_ENABLE = 12;
static const uint32_t QME_PSCRS0_HMI_EXIT_ENABLE = 13;
static const uint32_t QME_PSCRS0_ = 14;
static const uint32_t QME_PSCRS0__LEN = 2;
static const uint32_t QME_PSCRS0_MTL = 16;
static const uint32_t QME_PSCRS0_MTL_LEN = 4;
static const uint32_t QME_PSCRS0_RL = 20;
static const uint32_t QME_PSCRS0_RL_LEN = 4;
static const uint32_t QME_PSCRS0_PLS = 24;
static const uint32_t QME_PSCRS0_PLS_LEN = 4;
// c/reg00004.H

static const uint64_t QME_PSCRS1 = 0x200e0854ull;

static const uint32_t QME_PSCRS1_DPDES_EXIT_ENABLE = 0;
static const uint32_t QME_PSCRS1_SD = 1;
static const uint32_t QME_PSCRS1_ESL = 2;
static const uint32_t QME_PSCRS1_EC = 3;
static const uint32_t QME_PSCRS1_PSLL = 4;
static const uint32_t QME_PSCRS1_PSLL_LEN = 4;
static const uint32_t QME_PSCRS1_HYP_VIRT_EXIT_ENABLE = 8;
static const uint32_t QME_PSCRS1_UV_DB_EXIT_ENABLE = 9;
static const uint32_t QME_PSCRS1_HYP_DB_EXIT_ENABLE = 10;
static const uint32_t QME_PSCRS1_EXT_EXIT_ENABLE = 11;
static const uint32_t QME_PSCRS1_DEC_EXIT_ENABLE = 12;
static const uint32_t QME_PSCRS1_HMI_EXIT_ENABLE = 13;
static const uint32_t QME_PSCRS1_ = 14;
static const uint32_t QME_PSCRS1__LEN = 2;
static const uint32_t QME_PSCRS1_MTL = 16;
static const uint32_t QME_PSCRS1_MTL_LEN = 4;
static const uint32_t QME_PSCRS1_RL = 20;
static const uint32_t QME_PSCRS1_RL_LEN = 4;
static const uint32_t QME_PSCRS1_PLS = 24;
static const uint32_t QME_PSCRS1_PLS_LEN = 4;
// c/reg00004.H

static const uint64_t QME_PSCRS2 = 0x200e0858ull;

static const uint32_t QME_PSCRS2_DPDES_EXIT_ENABLE = 0;
static const uint32_t QME_PSCRS2_SD = 1;
static const uint32_t QME_PSCRS2_ESL = 2;
static const uint32_t QME_PSCRS2_EC = 3;
static const uint32_t QME_PSCRS2_PSLL = 4;
static const uint32_t QME_PSCRS2_PSLL_LEN = 4;
static const uint32_t QME_PSCRS2_HYP_VIRT_EXIT_ENABLE = 8;
static const uint32_t QME_PSCRS2_UV_DB_EXIT_ENABLE = 9;
static const uint32_t QME_PSCRS2_HYP_DB_EXIT_ENABLE = 10;
static const uint32_t QME_PSCRS2_EXT_EXIT_ENABLE = 11;
static const uint32_t QME_PSCRS2_DEC_EXIT_ENABLE = 12;
static const uint32_t QME_PSCRS2_HMI_EXIT_ENABLE = 13;
static const uint32_t QME_PSCRS2_ = 14;
static const uint32_t QME_PSCRS2__LEN = 2;
static const uint32_t QME_PSCRS2_MTL = 16;
static const uint32_t QME_PSCRS2_MTL_LEN = 4;
static const uint32_t QME_PSCRS2_RL = 20;
static const uint32_t QME_PSCRS2_RL_LEN = 4;
static const uint32_t QME_PSCRS2_PLS = 24;
static const uint32_t QME_PSCRS2_PLS_LEN = 4;
// c/reg00004.H

static const uint64_t QME_PSCRS3 = 0x200e085cull;

static const uint32_t QME_PSCRS3_DPDES_EXIT_ENABLE = 0;
static const uint32_t QME_PSCRS3_SD = 1;
static const uint32_t QME_PSCRS3_ESL = 2;
static const uint32_t QME_PSCRS3_EC = 3;
static const uint32_t QME_PSCRS3_PSLL = 4;
static const uint32_t QME_PSCRS3_PSLL_LEN = 4;
static const uint32_t QME_PSCRS3_HYP_VIRT_EXIT_ENABLE = 8;
static const uint32_t QME_PSCRS3_UV_DB_EXIT_ENABLE = 9;
static const uint32_t QME_PSCRS3_HYP_DB_EXIT_ENABLE = 10;
static const uint32_t QME_PSCRS3_EXT_EXIT_ENABLE = 11;
static const uint32_t QME_PSCRS3_DEC_EXIT_ENABLE = 12;
static const uint32_t QME_PSCRS3_HMI_EXIT_ENABLE = 13;
static const uint32_t QME_PSCRS3_ = 14;
static const uint32_t QME_PSCRS3__LEN = 2;
static const uint32_t QME_PSCRS3_MTL = 16;
static const uint32_t QME_PSCRS3_MTL_LEN = 4;
static const uint32_t QME_PSCRS3_RL = 20;
static const uint32_t QME_PSCRS3_RL_LEN = 4;
static const uint32_t QME_PSCRS3_PLS = 24;
static const uint32_t QME_PSCRS3_PLS_LEN = 4;
// c/reg00004.H

static const uint64_t QME_RMOR = 0x200e0868ull;

static const uint32_t QME_RMOR_DATA = 0;
static const uint32_t QME_RMOR_DATA_LEN = 63;
static const uint32_t QME_RMOR_URMOR_SELECT = 63;
// c/reg00004.H

static const uint64_t QME_SCR_RW = 0x200e080cull;
static const uint64_t QME_SCR_WO_CLEAR = 0x200e080full;
static const uint64_t QME_SCR_WO_OR = 0x200e080eull;

static const uint32_t QME_SCR_QME_SCR_DATA = 0;
static const uint32_t QME_SCR_QME_SCR_DATA_LEN = 64;
// c/reg00004.H

static const uint64_t QME_SCSR_SCOM = 0x200e0840ull;
static const uint64_t QME_SCSR_SCOM1 = 0x200e0843ull;
static const uint64_t QME_SCSR_SCOM2 = 0x200e0842ull;

static const uint32_t QME_SCSR_ASSERT_PM_BLOCK_INTR = 0;
static const uint32_t QME_SCSR_ASSERT_PM_EXIT = 1;
static const uint32_t QME_SCSR_ASSERT_PM_ENTRY_LIMIT = 2;
static const uint32_t QME_SCSR_PC_SPARE_OUT = 3;
static const uint32_t QME_SCSR_HBUS_DISABLE = 4;
static const uint32_t QME_SCSR_L2_PURGE_REQ = 5;
static const uint32_t QME_SCSR_L2_PURGE_ABORT = 6;
static const uint32_t QME_SCSR_L2RCMD_INTF_QUIESCE = 7;
static const uint32_t QME_SCSR_NCU_TLBIE_QUIESCE = 8;
static const uint32_t QME_SCSR_NCU_PURGE_REQ = 9;
static const uint32_t QME_SCSR_NCU_PURGE_ABORT = 10;
static const uint32_t QME_SCSR_CHTM_PURGE_REQ = 11;
static const uint32_t QME_SCSR_PB_PURGE_REQ = 12;
static const uint32_t QME_SCSR_CORE_QUIESCE = 13;
static const uint32_t QME_SCSR_SPARE_MODE = 14;
static const uint32_t QME_SCSR_SRESET_REQ = 15;
static const uint32_t QME_SCSR_ASSERT_SPECIAL_WKUP_DONE = 16;
static const uint32_t QME_SCSR_SPARE_OUT = 17;
static const uint32_t QME_SCSR_SPARE18_19 = 18;
static const uint32_t QME_SCSR_SPARE18_19_LEN = 2;
static const uint32_t QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE = 20;
static const uint32_t QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE = 21;
static const uint32_t QME_SCSR_AUTO_PMSR_SHIFT_DIS = 22;
static const uint32_t QME_SCSR_REFRESH_PMSR = 23;
static const uint32_t QME_SCSR_BLOCK_INTR_OUTPUTS = 24;
static const uint32_t QME_SCSR_BLOCK_INTR_INPUTS = 25;
static const uint32_t QME_SCSR_ENABLE_PECE = 26;
static const uint32_t QME_SCSR_CTFS_DEC_WKUP_ENABLE = 27;
static const uint32_t QME_SCSR_PM_BLOCK_INTR = 32;
static const uint32_t QME_SCSR_PM_EXIT = 33;
static const uint32_t QME_SCSR_PM_ENTRY_LIMIT = 34;
static const uint32_t QME_SCSR_PC_SPARE_IN = 35;
static const uint32_t QME_SCSR_HBUS_INACTIVE = 36;
static const uint32_t QME_SCSR_L2_PURGE_DONE = 37;
static const uint32_t QME_SCSR_NCU_PURGE_DONE = 41;
static const uint32_t QME_SCSR_CHTM_PURGE_DONE = 43;
static const uint32_t QME_SCSR_PB_PURGE_DONE = 44;
static const uint32_t QME_SCSR_CORE_QUIESCED = 45;
static const uint32_t QME_SCSR_STOP_SHIFT_ACTIVE = 47;
static const uint32_t QME_SCSR_SPECIAL_WKUP_DONE = 48;
static const uint32_t QME_SCSR_SPARE_IN = 49;
static const uint32_t QME_SCSR_PC_THREAD_INSTR_RUNNING = 52;
static const uint32_t QME_SCSR_PC_THREAD_INSTR_RUNNING_LEN = 4;
static const uint32_t QME_SCSR_PMSR_SHIFT_ACTIVE = 56;
static const uint32_t QME_SCSR_OTHER_DPDES_INTR_PENDING = 57;
static const uint32_t QME_SCSR_PC_UNMASKED_ATTN = 58;
static const uint32_t QME_SCSR_PM_STATE_ACTIVE = 59;
static const uint32_t QME_SCSR_PM_STATE = 60;
static const uint32_t QME_SCSR_PM_STATE_LEN = 4;
// c/reg00004.H

static const uint64_t QME_SPWU_FSP = 0x200e0834ull;

static const uint32_t QME_SPWU_FSP_REQ = 0;
static const uint32_t QME_SPWU_FSP_DONE = 4;
// c/reg00004.H

static const uint64_t QME_SPWU_HYP = 0x200e083cull;

static const uint32_t QME_SPWU_HYP_REQ = 0;
static const uint32_t QME_SPWU_HYP_DONE = 4;
// c/reg00004.H

static const uint64_t QME_SPWU_OCC = 0x200e0838ull;

static const uint32_t QME_SPWU_OCC_REQ = 0;
static const uint32_t QME_SPWU_OCC_DONE = 4;
// c/reg00004.H

static const uint64_t QME_SPWU_OTR = 0x200e0830ull;

static const uint32_t QME_SPWU_OTR_REQ = 0;
static const uint32_t QME_SPWU_OTR_DONE = 4;
// c/reg00004.H

static const uint64_t QME_SSH_FSP = 0x200e0824ull;

static const uint32_t QME_SSH_FSP_STOP_GATED = 0;
static const uint32_t QME_SSH_FSP_SPECIAL_WKUP_DONE = 1;
static const uint32_t QME_SSH_FSP_STOP_TRANSITION = 2;
static const uint32_t QME_SSH_FSP_STOP_TRANSITION_LEN = 2;
static const uint32_t QME_SSH_FSP_REQ_STOP_LEVEL = 4;
static const uint32_t QME_SSH_FSP_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_FSP_ACT_STOP_LEVEL = 8;
static const uint32_t QME_SSH_FSP_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL = 12;
static const uint32_t QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL = 16;
static const uint32_t QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL_LEN = 4;
// c/reg00004.H

static const uint64_t QME_SSH_HYP = 0x200e082cull;

static const uint32_t QME_SSH_HYP_STOP_GATED = 0;
static const uint32_t QME_SSH_HYP_SPECIAL_WKUP_DONE = 1;
static const uint32_t QME_SSH_HYP_STOP_TRANSITION = 2;
static const uint32_t QME_SSH_HYP_STOP_TRANSITION_LEN = 2;
static const uint32_t QME_SSH_HYP_REQ_STOP_LEVEL = 4;
static const uint32_t QME_SSH_HYP_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_HYP_ACT_STOP_LEVEL = 8;
static const uint32_t QME_SSH_HYP_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL = 12;
static const uint32_t QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL = 16;
static const uint32_t QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL_LEN = 4;
// c/reg00004.H

static const uint64_t QME_SSH_OCC = 0x200e0828ull;

static const uint32_t QME_SSH_OCC_STOP_GATED = 0;
static const uint32_t QME_SSH_OCC_SPECIAL_WKUP_DONE = 1;
static const uint32_t QME_SSH_OCC_STOP_TRANSITION = 2;
static const uint32_t QME_SSH_OCC_STOP_TRANSITION_LEN = 2;
static const uint32_t QME_SSH_OCC_REQ_STOP_LEVEL = 4;
static const uint32_t QME_SSH_OCC_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OCC_ACT_STOP_LEVEL = 8;
static const uint32_t QME_SSH_OCC_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL = 12;
static const uint32_t QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL = 16;
static const uint32_t QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL_LEN = 4;
// c/reg00004.H

static const uint64_t QME_SSH_OTR = 0x200e0820ull;

static const uint32_t QME_SSH_OTR_STOP_GATED = 0;
static const uint32_t QME_SSH_OTR_SPECIAL_WKUP_DONE = 1;
static const uint32_t QME_SSH_OTR_STOP_TRANSITION = 2;
static const uint32_t QME_SSH_OTR_STOP_TRANSITION_LEN = 2;
static const uint32_t QME_SSH_OTR_REQ_STOP_LEVEL = 4;
static const uint32_t QME_SSH_OTR_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OTR_ACT_STOP_LEVEL = 8;
static const uint32_t QME_SSH_OTR_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL = 12;
static const uint32_t QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL = 16;
static const uint32_t QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OTR_SPECIAL_WKUP_OCCURRED = 20;
static const uint32_t QME_SSH_OTR_SPECIAL_WKUP_ENTERED = 21;
static const uint32_t QME_SSH_OTR_STOP_STATE_EXITED = 22;
static const uint32_t QME_SSH_OTR_STOP_STATE_ENTERED = 23;
static const uint32_t QME_SSH_OTR_DEEPEST_STOP_ENTRY = 24;
static const uint32_t QME_SSH_OTR_DEEPEST_STOP_ENTRY_LEN = 4;
// c/reg00004.H

static const uint64_t QME_SSH_SRC = 0x200e081cull;

static const uint32_t QME_SSH_SRC_STOP_GATED = 0;
static const uint32_t QME_SSH_SRC_SPECIAL_WKUP_DONE = 1;
static const uint32_t QME_SSH_SRC_STOP_TRANSITION = 2;
static const uint32_t QME_SSH_SRC_STOP_TRANSITION_LEN = 2;
static const uint32_t QME_SSH_SRC_REQ_STOP_LEVEL = 4;
static const uint32_t QME_SSH_SRC_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_SRC_ACT_STOP_LEVEL = 8;
static const uint32_t QME_SSH_SRC_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_SRC_REQ_WRITE_ENABLE = 12;
static const uint32_t QME_SSH_SRC_ACT_WRITE_ENABLE = 13;
static const uint32_t QME_SSH_SRC_SELF_SAVE_ACTIVE = 30;
static const uint32_t QME_SSH_SRC_SELF_RESTORE_ACTIVE = 31;
static const uint32_t QME_SSH_SRC_SAMPLED_STOP_ACTIVE = 39;
static const uint32_t QME_SSH_SRC_SAMPLED_STOP_STATE = 40;
static const uint32_t QME_SSH_SRC_SAMPLED_STOP_STATE_LEN = 4;
static const uint32_t QME_SSH_SRC_SPECIAL_WKUP_PRESENT = 48;
static const uint32_t QME_SSH_SRC_SPECIAL_WKUP_PRESENT_LEN = 4;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_SET = 56;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN = 2;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_CLR = 58;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN = 2;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_ACT = 60;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN = 2;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_DRP = 62;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN = 2;
// c/reg00004.H

static const uint64_t QME_TFCSR_SCOM = 0x200e0880ull;
static const uint64_t QME_TFCSR_SCOM1 = 0x200e0883ull;
static const uint64_t QME_TFCSR_SCOM2 = 0x200e0882ull;

static const uint32_t QME_TFCSR_XFER_START = 0;
static const uint32_t QME_TFCSR_TFAC_RESET = 1;
static const uint32_t QME_TFCSR_CORE_NUM = 30;
static const uint32_t QME_TFCSR_CORE_NUM_LEN = 2;
static const uint32_t QME_TFCSR_XFER_RECEIVE_DONE = 32;
static const uint32_t QME_TFCSR_XFER_SENT_DONE = 33;
static const uint32_t QME_TFCSR_INCOMING_ERR = 34;
static const uint32_t QME_TFCSR_RUNTIME_ERR = 35;
static const uint32_t QME_TFCSR_STATE_ERR = 36;
static const uint32_t QME_TFCSR_HDEC_MSB = 59;
static const uint32_t QME_TFCSR_DEC_MSB = 60;
static const uint32_t QME_TFCSR_DEC_MSB_LEN = 4;
// c/reg00004.H

static const uint64_t RING_FENCE_MASK_LATCH_REG = 0x20010008ull;

static const uint32_t RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK = 1;
static const uint32_t RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN = 31;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1 = 0x200103e1ull;

static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_2 = 0x200103e2ull;

static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_EPS_DBG_INST1_COND_REG_3 = 0x200103e3ull;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1 = 0x200103e4ull;

static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_2 = 0x200103e5ull;

static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_EPS_DBG_INST2_COND_REG_3 = 0x200103e6ull;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG = 0x200103e0ull;

static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 11;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE = 12;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_MODE_REG_2 = 0x200103efull;

static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0 = 0x200103edull;

static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1 = 0x200103eeull;

static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_EPS_DBG_DEBUG_TRACE_CONTROL = 0x200103f0ull;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_EPS_DBG_XTRA_TRACE_MODE = 0x200103f1ull;

static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN = 42;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG = 0x20010200ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG = 0x20010201ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG = 0x20010202ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_0 = 0x20010203ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_1 = 0x20010204ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_2 = 0x20010205ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_2_B_LEN = 24;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_3 = 0x20010206ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_3_D_LEN = 24;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_4 = 0x20010207ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_4_B_LEN = 24;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_5 = 0x20010208ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_5_D_LEN = 24;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9 = 0x20010209ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG = 0x20010220ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG = 0x20010221ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG = 0x20010222ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_0 = 0x20010223ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_1 = 0x20010224ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_2 = 0x20010225ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_2_B_LEN = 24;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_3 = 0x20010226ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_3_D_LEN = 24;
// c/reg00004.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_4 = 0x20010227ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_4_B_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_5 = 0x20010228ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_5_D_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9 = 0x20010229ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG = 0x20010240ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG = 0x20010241ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG = 0x20010242ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_0 = 0x20010243ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_1 = 0x20010244ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_2 = 0x20010245ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_2_B_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_3 = 0x20010246ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_3_D_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_4 = 0x20010247ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_4_B_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_5 = 0x20010248ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_5_D_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9 = 0x20010249ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG = 0x20010260ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG = 0x20010261ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG = 0x20010262ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_0 = 0x20010263ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_1 = 0x20010264ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_2 = 0x20010265ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_2_B_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_3 = 0x20010266ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_3_D_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_4 = 0x20010267ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_4_B_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_5 = 0x20010268ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_5_D_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9 = 0x20010269ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA1_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG = 0x20010280ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG = 0x20010281ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG = 0x20010282ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_0 = 0x20010283ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_1 = 0x20010284ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_2 = 0x20010285ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_2_B_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_3 = 0x20010286ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_3_D_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_4 = 0x20010287ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_4_B_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_5 = 0x20010288ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_5_D_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9 = 0x20010289ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG = 0x200102a0ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG = 0x200102a1ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG = 0x200102a2ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_0 = 0x200102a3ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_1 = 0x200102a4ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_2 = 0x200102a5ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_2_B_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_3 = 0x200102a6ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_3_D_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_4 = 0x200102a7ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_4_B_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_5 = 0x200102a8ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_5_D_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9 = 0x200102a9ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG = 0x200102c0ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG = 0x200102c1ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG = 0x200102c2ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_0 = 0x200102c3ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_1 = 0x200102c4ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_2 = 0x200102c5ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_2_B_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_3 = 0x200102c6ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_3_D_LEN = 24;
// c/reg00005.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_4 = 0x200102c7ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_4_B_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_5 = 0x200102c8ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_5_D_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9 = 0x200102c9ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00006.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG = 0x200102e0ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00006.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG = 0x200102e1ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00006.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG = 0x200102e2ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00006.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_0 = 0x200102e3ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00006.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_1 = 0x200102e4ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_2 = 0x200102e5ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_2_B_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_3 = 0x200102e6ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_3_D_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_4 = 0x200102e7ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_4_B_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_5 = 0x200102e8ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_5_D_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9 = 0x200102e9ull;

static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ00_TPCL3_L3TRA3_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1 = 0x200103e1ull;

static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_2 = 0x200103e2ull;

static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_EPS_DBG_INST1_COND_REG_3 = 0x200103e3ull;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1 = 0x200103e4ull;

static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_2 = 0x200103e5ull;

static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_EPS_DBG_INST2_COND_REG_3 = 0x200103e6ull;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG = 0x200103e0ull;

static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 11;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE = 12;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_MODE_REG_2 = 0x200103efull;

static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0 = 0x200103edull;

static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1 = 0x200103eeull;

static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_EPS_DBG_DEBUG_TRACE_CONTROL = 0x200103f0ull;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_EPS_DBG_XTRA_TRACE_MODE = 0x200103f1ull;

static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN = 42;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG = 0x20010200ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG = 0x20010201ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG = 0x20010202ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_0 = 0x20010203ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_1 = 0x20010204ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_2 = 0x20010205ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_2_B_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_3 = 0x20010206ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_3_D_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_4 = 0x20010207ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_4_B_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_5 = 0x20010208ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_5_D_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9 = 0x20010209ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG = 0x20010220ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG = 0x20010221ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG = 0x20010222ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_0 = 0x20010223ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_1 = 0x20010224ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_2 = 0x20010225ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_2_B_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_3 = 0x20010226ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_3_D_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_4 = 0x20010227ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_4_B_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_5 = 0x20010228ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_5_D_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9 = 0x20010229ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG = 0x20010240ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG = 0x20010241ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG = 0x20010242ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_0 = 0x20010243ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_1 = 0x20010244ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00006.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_2 = 0x20010245ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_2_B_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_3 = 0x20010246ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_3_D_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_4 = 0x20010247ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_4_B_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_5 = 0x20010248ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_5_D_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9 = 0x20010249ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG = 0x20010260ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG = 0x20010261ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG = 0x20010262ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_0 = 0x20010263ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_1 = 0x20010264ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_2 = 0x20010265ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_2_B_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_3 = 0x20010266ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_3_D_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_4 = 0x20010267ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_4_B_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_5 = 0x20010268ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_5_D_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9 = 0x20010269ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA1_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG = 0x20010280ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG = 0x20010281ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG = 0x20010282ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_0 = 0x20010283ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_1 = 0x20010284ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_2 = 0x20010285ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_2_B_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_3 = 0x20010286ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_3_D_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_4 = 0x20010287ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_4_B_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_5 = 0x20010288ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_5_D_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9 = 0x20010289ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG = 0x200102a0ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG = 0x200102a1ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG = 0x200102a2ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_0 = 0x200102a3ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_1 = 0x200102a4ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_2 = 0x200102a5ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_2_B_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_3 = 0x200102a6ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_3_D_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_4 = 0x200102a7ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_4_B_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_5 = 0x200102a8ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_5_D_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9 = 0x200102a9ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG = 0x200102c0ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG = 0x200102c1ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG = 0x200102c2ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_0 = 0x200102c3ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_1 = 0x200102c4ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_2 = 0x200102c5ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_2_B_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_3 = 0x200102c6ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_3_D_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_4 = 0x200102c7ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_4_B_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_5 = 0x200102c8ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_5_D_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9 = 0x200102c9ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG = 0x200102e0ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG = 0x200102e1ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG = 0x200102e2ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_0 = 0x200102e3ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_1 = 0x200102e4ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00007.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_2 = 0x200102e5ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_2_B_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_3 = 0x200102e6ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_3_D_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_4 = 0x200102e7ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_4_B_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_5 = 0x200102e8ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_5_D_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9 = 0x200102e9ull;

static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ01_TPCL3_L3TRA3_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1 = 0x200103e1ull;

static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_2 = 0x200103e2ull;

static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_EPS_DBG_INST1_COND_REG_3 = 0x200103e3ull;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1 = 0x200103e4ull;

static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_2 = 0x200103e5ull;

static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_EPS_DBG_INST2_COND_REG_3 = 0x200103e6ull;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG = 0x200103e0ull;

static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 11;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE = 12;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_MODE_REG_2 = 0x200103efull;

static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0 = 0x200103edull;

static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1 = 0x200103eeull;

static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_EPS_DBG_DEBUG_TRACE_CONTROL = 0x200103f0ull;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_EPS_DBG_XTRA_TRACE_MODE = 0x200103f1ull;

static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN = 42;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG = 0x20010200ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG = 0x20010201ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG = 0x20010202ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_0 = 0x20010203ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_1 = 0x20010204ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_2 = 0x20010205ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_2_B_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_3 = 0x20010206ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_3_D_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_4 = 0x20010207ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_4_B_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_5 = 0x20010208ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_5_D_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9 = 0x20010209ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG = 0x20010220ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG = 0x20010221ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG = 0x20010222ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_0 = 0x20010223ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_1 = 0x20010224ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_2 = 0x20010225ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_2_B_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_3 = 0x20010226ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_3_D_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_4 = 0x20010227ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_4_B_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_5 = 0x20010228ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_5_D_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9 = 0x20010229ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG = 0x20010240ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG = 0x20010241ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG = 0x20010242ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_0 = 0x20010243ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_1 = 0x20010244ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_2 = 0x20010245ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_2_B_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_3 = 0x20010246ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_3_D_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_4 = 0x20010247ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_4_B_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_5 = 0x20010248ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_5_D_LEN = 24;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9 = 0x20010249ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG = 0x20010260ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG = 0x20010261ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG = 0x20010262ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00008.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_0 = 0x20010263ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_1 = 0x20010264ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_2 = 0x20010265ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_2_B_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_3 = 0x20010266ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_3_D_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_4 = 0x20010267ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_4_B_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_5 = 0x20010268ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_5_D_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9 = 0x20010269ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA1_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG = 0x20010280ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG = 0x20010281ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG = 0x20010282ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_0 = 0x20010283ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_1 = 0x20010284ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_2 = 0x20010285ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_2_B_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_3 = 0x20010286ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_3_D_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_4 = 0x20010287ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_4_B_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_5 = 0x20010288ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_5_D_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9 = 0x20010289ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG = 0x200102a0ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG = 0x200102a1ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG = 0x200102a2ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_0 = 0x200102a3ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_1 = 0x200102a4ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_2 = 0x200102a5ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_2_B_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_3 = 0x200102a6ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_3_D_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_4 = 0x200102a7ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_4_B_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_5 = 0x200102a8ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_5_D_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9 = 0x200102a9ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG = 0x200102c0ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG = 0x200102c1ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG = 0x200102c2ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_0 = 0x200102c3ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_1 = 0x200102c4ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_2 = 0x200102c5ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_2_B_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_3 = 0x200102c6ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_3_D_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_4 = 0x200102c7ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_4_B_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_5 = 0x200102c8ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_5_D_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9 = 0x200102c9ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG = 0x200102e0ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG = 0x200102e1ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG = 0x200102e2ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_0 = 0x200102e3ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_1 = 0x200102e4ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_2 = 0x200102e5ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_2_B_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_3 = 0x200102e6ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_3_D_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_4 = 0x200102e7ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_4_B_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_5 = 0x200102e8ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_5_D_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9 = 0x200102e9ull;

static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ02_TPCL3_L3TRA3_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00009.H

static const uint64_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1 = 0x200103e1ull;

static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00009.H

static const uint64_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_2 = 0x200103e2ull;

static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00009.H

static const uint64_t TP_TCEQ03_TPCL3_EPS_DBG_INST1_COND_REG_3 = 0x200103e3ull;
// c/reg00009.H

static const uint64_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1 = 0x200103e4ull;

static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_2 = 0x200103e5ull;

static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_EPS_DBG_INST2_COND_REG_3 = 0x200103e6ull;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG = 0x200103e0ull;

static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 11;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE = 12;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_MODE_REG_2 = 0x200103efull;

static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0 = 0x200103edull;

static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1 = 0x200103eeull;

static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_EPS_DBG_DEBUG_TRACE_CONTROL = 0x200103f0ull;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_EPS_DBG_XTRA_TRACE_MODE = 0x200103f1ull;

static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN = 42;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG = 0x20010200ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG = 0x20010201ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG = 0x20010202ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_0 = 0x20010203ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_1 = 0x20010204ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_2 = 0x20010205ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_2_B_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_3 = 0x20010206ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_3_D_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_4 = 0x20010207ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_4_B_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_5 = 0x20010208ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_5_D_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9 = 0x20010209ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG = 0x20010220ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG = 0x20010221ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG = 0x20010222ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_0 = 0x20010223ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_1 = 0x20010224ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_2 = 0x20010225ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_2_B_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_3 = 0x20010226ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_3_D_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_4 = 0x20010227ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_4_B_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_5 = 0x20010228ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_5_D_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9 = 0x20010229ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG = 0x20010240ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG = 0x20010241ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG = 0x20010242ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_0 = 0x20010243ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_1 = 0x20010244ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_2 = 0x20010245ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_2_B_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_3 = 0x20010246ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_3_D_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_4 = 0x20010247ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_4_B_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_5 = 0x20010248ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_5_D_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9 = 0x20010249ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG = 0x20010260ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG = 0x20010261ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG = 0x20010262ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_0 = 0x20010263ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_1 = 0x20010264ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_2 = 0x20010265ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_2_B_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_3 = 0x20010266ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_3_D_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_4 = 0x20010267ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_4_B_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_5 = 0x20010268ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_5_D_LEN = 24;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9 = 0x20010269ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA1_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG = 0x20010280ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00010.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG = 0x20010281ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG = 0x20010282ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_0 = 0x20010283ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_1 = 0x20010284ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_2 = 0x20010285ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_2_B_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_3 = 0x20010286ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_3_D_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_4 = 0x20010287ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_4_B_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_5 = 0x20010288ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_5_D_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9 = 0x20010289ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG = 0x200102a0ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG = 0x200102a1ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG = 0x200102a2ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_0 = 0x200102a3ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_1 = 0x200102a4ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_2 = 0x200102a5ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_2_B_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_3 = 0x200102a6ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_3_D_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_4 = 0x200102a7ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_4_B_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_5 = 0x200102a8ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_5_D_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9 = 0x200102a9ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG = 0x200102c0ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG = 0x200102c1ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG = 0x200102c2ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_0 = 0x200102c3ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_1 = 0x200102c4ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_2 = 0x200102c5ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_2_B_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_3 = 0x200102c6ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_3_D_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_4 = 0x200102c7ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_4_B_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_5 = 0x200102c8ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_5_D_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9 = 0x200102c9ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG = 0x200102e0ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG = 0x200102e1ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG = 0x200102e2ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_0 = 0x200102e3ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_1 = 0x200102e4ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_2 = 0x200102e5ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_2_B_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_3 = 0x200102e6ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_3_D_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_4 = 0x200102e7ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_4_B_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_5 = 0x200102e8ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_5_D_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9 = 0x200102e9ull;

static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ03_TPCL3_L3TRA3_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00011.H

static const uint64_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1 = 0x200103e1ull;

static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00011.H

static const uint64_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_2 = 0x200103e2ull;

static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ04_TPCL3_EPS_DBG_INST1_COND_REG_3 = 0x200103e3ull;
// c/reg00011.H

static const uint64_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1 = 0x200103e4ull;

static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00011.H

static const uint64_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_2 = 0x200103e5ull;

static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00011.H

static const uint64_t TP_TCEQ04_TPCL3_EPS_DBG_INST2_COND_REG_3 = 0x200103e6ull;
// c/reg00011.H

static const uint64_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG = 0x200103e0ull;

static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 11;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE = 12;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// c/reg00011.H

static const uint64_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_MODE_REG_2 = 0x200103efull;

static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// c/reg00011.H

static const uint64_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0 = 0x200103edull;

static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// c/reg00011.H

static const uint64_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1 = 0x200103eeull;

static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// c/reg00011.H

static const uint64_t TP_TCEQ04_TPCL3_EPS_DBG_DEBUG_TRACE_CONTROL = 0x200103f0ull;
// c/reg00011.H

static const uint64_t TP_TCEQ04_TPCL3_EPS_DBG_XTRA_TRACE_MODE = 0x200103f1ull;

static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN = 42;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG = 0x20010200ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG = 0x20010201ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG = 0x20010202ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_0 = 0x20010203ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_1 = 0x20010204ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_2 = 0x20010205ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_2_B_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_3 = 0x20010206ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_3_D_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_4 = 0x20010207ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_4_B_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_5 = 0x20010208ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_5_D_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9 = 0x20010209ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG = 0x20010220ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG = 0x20010221ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG = 0x20010222ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_0 = 0x20010223ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_1 = 0x20010224ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_2 = 0x20010225ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_2_B_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_3 = 0x20010226ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_3_D_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_4 = 0x20010227ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_4_B_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_5 = 0x20010228ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_5_D_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9 = 0x20010229ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG = 0x20010240ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG = 0x20010241ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG = 0x20010242ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_0 = 0x20010243ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_1 = 0x20010244ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_2 = 0x20010245ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_2_B_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_3 = 0x20010246ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_3_D_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_4 = 0x20010247ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_4_B_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_5 = 0x20010248ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_5_D_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9 = 0x20010249ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG = 0x20010260ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG = 0x20010261ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG = 0x20010262ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_0 = 0x20010263ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_1 = 0x20010264ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_2 = 0x20010265ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_2_B_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_3 = 0x20010266ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_3_D_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_4 = 0x20010267ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_4_B_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_5 = 0x20010268ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_5_D_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9 = 0x20010269ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA1_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG = 0x20010280ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG = 0x20010281ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG = 0x20010282ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_0 = 0x20010283ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_1 = 0x20010284ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_2 = 0x20010285ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_2_B_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_3 = 0x20010286ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_3_D_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_4 = 0x20010287ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_4_B_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_5 = 0x20010288ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_5_D_LEN = 24;
// c/reg00012.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9 = 0x20010289ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG = 0x200102a0ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG = 0x200102a1ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG = 0x200102a2ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_0 = 0x200102a3ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_1 = 0x200102a4ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_2 = 0x200102a5ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_2_B_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_3 = 0x200102a6ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_3_D_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_4 = 0x200102a7ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_4_B_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_5 = 0x200102a8ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_5_D_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9 = 0x200102a9ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG = 0x200102c0ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG = 0x200102c1ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG = 0x200102c2ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_0 = 0x200102c3ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_1 = 0x200102c4ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_2 = 0x200102c5ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_2_B_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_3 = 0x200102c6ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_3_D_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_4 = 0x200102c7ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_4_B_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_5 = 0x200102c8ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_5_D_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9 = 0x200102c9ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG = 0x200102e0ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG = 0x200102e1ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG = 0x200102e2ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_0 = 0x200102e3ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_1 = 0x200102e4ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_2 = 0x200102e5ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_2_B_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_3 = 0x200102e6ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_3_D_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_4 = 0x200102e7ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_4_B_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_5 = 0x200102e8ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_5_D_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9 = 0x200102e9ull;

static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ04_TPCL3_L3TRA3_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1 = 0x200103e1ull;

static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_2 = 0x200103e2ull;

static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_EPS_DBG_INST1_COND_REG_3 = 0x200103e3ull;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1 = 0x200103e4ull;

static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_2 = 0x200103e5ull;

static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_EPS_DBG_INST2_COND_REG_3 = 0x200103e6ull;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG = 0x200103e0ull;

static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 11;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE = 12;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_MODE_REG_2 = 0x200103efull;

static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0 = 0x200103edull;

static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1 = 0x200103eeull;

static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_EPS_DBG_DEBUG_TRACE_CONTROL = 0x200103f0ull;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_EPS_DBG_XTRA_TRACE_MODE = 0x200103f1ull;

static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN = 42;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG = 0x20010200ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG = 0x20010201ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG = 0x20010202ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_0 = 0x20010203ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_1 = 0x20010204ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_2 = 0x20010205ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_2_B_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_3 = 0x20010206ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_3_D_LEN = 24;
// c/reg00013.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_4 = 0x20010207ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_4_B_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_5 = 0x20010208ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_5_D_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9 = 0x20010209ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG = 0x20010220ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG = 0x20010221ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG = 0x20010222ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_0 = 0x20010223ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_1 = 0x20010224ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_2 = 0x20010225ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_2_B_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_3 = 0x20010226ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_3_D_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_4 = 0x20010227ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_4_B_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_5 = 0x20010228ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_5_D_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9 = 0x20010229ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG = 0x20010240ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG = 0x20010241ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG = 0x20010242ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_0 = 0x20010243ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_1 = 0x20010244ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_2 = 0x20010245ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_2_B_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_3 = 0x20010246ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_3_D_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_4 = 0x20010247ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_4_B_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_5 = 0x20010248ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_5_D_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9 = 0x20010249ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG = 0x20010260ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG = 0x20010261ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG = 0x20010262ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_0 = 0x20010263ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_1 = 0x20010264ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_2 = 0x20010265ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_2_B_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_3 = 0x20010266ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_3_D_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_4 = 0x20010267ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_4_B_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_5 = 0x20010268ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_5_D_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9 = 0x20010269ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA1_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG = 0x20010280ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG = 0x20010281ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG = 0x20010282ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_0 = 0x20010283ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_1 = 0x20010284ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_2 = 0x20010285ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_2_B_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_3 = 0x20010286ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_3_D_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_4 = 0x20010287ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_4_B_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_5 = 0x20010288ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_5_D_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9 = 0x20010289ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG = 0x200102a0ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG = 0x200102a1ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG = 0x200102a2ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_0 = 0x200102a3ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_1 = 0x200102a4ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_2 = 0x200102a5ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_2_B_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_3 = 0x200102a6ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_3_D_LEN = 24;
// c/reg00014.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_4 = 0x200102a7ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_4_B_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_5 = 0x200102a8ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_5_D_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9 = 0x200102a9ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG = 0x200102c0ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG = 0x200102c1ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG = 0x200102c2ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_0 = 0x200102c3ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_1 = 0x200102c4ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_2 = 0x200102c5ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_2_B_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_3 = 0x200102c6ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_3_D_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_4 = 0x200102c7ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_4_B_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_5 = 0x200102c8ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_5_D_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9 = 0x200102c9ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG = 0x200102e0ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG = 0x200102e1ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG = 0x200102e2ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_0 = 0x200102e3ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_1 = 0x200102e4ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_2 = 0x200102e5ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_2_B_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_3 = 0x200102e6ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_3_D_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_4 = 0x200102e7ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_4_B_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_5 = 0x200102e8ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_5_D_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9 = 0x200102e9ull;

static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ05_TPCL3_L3TRA3_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1 = 0x200103e1ull;

static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_2 = 0x200103e2ull;

static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_EPS_DBG_INST1_COND_REG_3 = 0x200103e3ull;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1 = 0x200103e4ull;

static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_2 = 0x200103e5ull;

static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_EPS_DBG_INST2_COND_REG_3 = 0x200103e6ull;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG = 0x200103e0ull;

static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 11;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE = 12;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_MODE_REG_2 = 0x200103efull;

static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0 = 0x200103edull;

static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1 = 0x200103eeull;

static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_EPS_DBG_DEBUG_TRACE_CONTROL = 0x200103f0ull;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_EPS_DBG_XTRA_TRACE_MODE = 0x200103f1ull;

static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN = 42;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG = 0x20010200ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG = 0x20010201ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG = 0x20010202ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_0 = 0x20010203ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_1 = 0x20010204ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_2 = 0x20010205ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_2_B_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_3 = 0x20010206ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_3_D_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_4 = 0x20010207ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_4_B_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_5 = 0x20010208ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_5_D_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9 = 0x20010209ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG = 0x20010220ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG = 0x20010221ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG = 0x20010222ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_0 = 0x20010223ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_1 = 0x20010224ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00015.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_2 = 0x20010225ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_2_B_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_3 = 0x20010226ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_3_D_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_4 = 0x20010227ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_4_B_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_5 = 0x20010228ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_5_D_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9 = 0x20010229ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG = 0x20010240ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG = 0x20010241ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG = 0x20010242ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_0 = 0x20010243ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_1 = 0x20010244ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_2 = 0x20010245ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_2_B_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_3 = 0x20010246ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_3_D_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_4 = 0x20010247ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_4_B_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_5 = 0x20010248ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_5_D_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9 = 0x20010249ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG = 0x20010260ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG = 0x20010261ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG = 0x20010262ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_0 = 0x20010263ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_1 = 0x20010264ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_2 = 0x20010265ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_2_B_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_3 = 0x20010266ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_3_D_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_4 = 0x20010267ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_4_B_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_5 = 0x20010268ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_5_D_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9 = 0x20010269ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA1_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG = 0x20010280ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG = 0x20010281ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG = 0x20010282ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_0 = 0x20010283ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_1 = 0x20010284ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_2 = 0x20010285ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_2_B_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_3 = 0x20010286ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_3_D_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_4 = 0x20010287ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_4_B_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_5 = 0x20010288ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_5_D_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9 = 0x20010289ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG = 0x200102a0ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG = 0x200102a1ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG = 0x200102a2ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_0 = 0x200102a3ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_1 = 0x200102a4ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_2 = 0x200102a5ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_2_B_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_3 = 0x200102a6ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_3_D_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_4 = 0x200102a7ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_4_B_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_5 = 0x200102a8ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_5_D_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9 = 0x200102a9ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG = 0x200102c0ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG = 0x200102c1ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG = 0x200102c2ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_0 = 0x200102c3ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_1 = 0x200102c4ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00016.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_2 = 0x200102c5ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_2_B_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_3 = 0x200102c6ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_3_D_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_4 = 0x200102c7ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_4_B_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_5 = 0x200102c8ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_5_D_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9 = 0x200102c9ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG = 0x200102e0ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG = 0x200102e1ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG = 0x200102e2ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_0 = 0x200102e3ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_1 = 0x200102e4ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_2 = 0x200102e5ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_2_B_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_3 = 0x200102e6ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_3_D_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_4 = 0x200102e7ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_4_B_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_5 = 0x200102e8ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_5_D_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9 = 0x200102e9ull;

static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ06_TPCL3_L3TRA3_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1 = 0x200103e1ull;

static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_2 = 0x200103e2ull;

static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_EPS_DBG_INST1_COND_REG_3 = 0x200103e3ull;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1 = 0x200103e4ull;

static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_2 = 0x200103e5ull;

static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_EPS_DBG_INST2_COND_REG_3 = 0x200103e6ull;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG = 0x200103e0ull;

static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 11;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE = 12;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_SYNC_BRCST_MODE_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_MODE_REG_2 = 0x200103efull;

static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0 = 0x200103edull;

static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1 = 0x200103eeull;

static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_EPS_DBG_DEBUG_TRACE_CONTROL = 0x200103f0ull;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_EPS_DBG_XTRA_TRACE_MODE = 0x200103f1ull;

static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN = 42;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG = 0x20010200ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG = 0x20010201ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG = 0x20010202ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_0 = 0x20010203ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_1 = 0x20010204ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_2 = 0x20010205ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_2_B_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_3 = 0x20010206ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_3_D_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_4 = 0x20010207ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_4_B_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_5 = 0x20010208ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_5_D_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9 = 0x20010209ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG = 0x20010220ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG = 0x20010221ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG = 0x20010222ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_0 = 0x20010223ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_1 = 0x20010224ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_2 = 0x20010225ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_2_B_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_3 = 0x20010226ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_3_D_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_4 = 0x20010227ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_4_B_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_5 = 0x20010228ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_5_D_LEN = 24;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9 = 0x20010229ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG = 0x20010240ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG = 0x20010241ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG = 0x20010242ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00017.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_0 = 0x20010243ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_1 = 0x20010244ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_2 = 0x20010245ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_2_B_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_3 = 0x20010246ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_3_D_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_4 = 0x20010247ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_4_B_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_5 = 0x20010248ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_5_D_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9 = 0x20010249ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG = 0x20010260ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG = 0x20010261ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG = 0x20010262ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_0 = 0x20010263ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_1 = 0x20010264ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_2 = 0x20010265ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_2_B_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_3 = 0x20010266ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_3_D_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_4 = 0x20010267ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_4_B_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_5 = 0x20010268ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_5_D_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9 = 0x20010269ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA1_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG = 0x20010280ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG = 0x20010281ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG = 0x20010282ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_0 = 0x20010283ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_1 = 0x20010284ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_2 = 0x20010285ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_2_B_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_3 = 0x20010286ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_3_D_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_4 = 0x20010287ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_4_B_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_5 = 0x20010288ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_5_D_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9 = 0x20010289ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG = 0x200102a0ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG = 0x200102a1ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG = 0x200102a2ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_0 = 0x200102a3ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_1 = 0x200102a4ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_2 = 0x200102a5ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_2_B_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_3 = 0x200102a6ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_3_D_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_4 = 0x200102a7ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_4_B_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_5 = 0x200102a8ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_5_D_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9 = 0x200102a9ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG = 0x200102c0ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG = 0x200102c1ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG = 0x200102c2ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_0 = 0x200102c3ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_1 = 0x200102c4ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_2 = 0x200102c5ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_2_B_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_3 = 0x200102c6ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_3_D_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_4 = 0x200102c7ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_4_B_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_5 = 0x200102c8ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_5_D_LEN = 24;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9 = 0x200102c9ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG = 0x200102e0ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG = 0x200102e1ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG = 0x200102e2ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// c/reg00018.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_0 = 0x200102e3ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00019.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_1 = 0x200102e4ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00019.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_2 = 0x200102e5ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_2_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_2_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_2_B_LEN = 24;
// c/reg00019.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_3 = 0x200102e6ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_3_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_3_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_3_D_LEN = 24;
// c/reg00019.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_4 = 0x200102e7ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_4_A = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_4_B = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_4_B_LEN = 24;
// c/reg00019.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_5 = 0x200102e8ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_5_D_LEN = 24;
// c/reg00019.H

static const uint64_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9 = 0x200102e9ull;

static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TP_TCEQ07_TPCL3_L3TRA3_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00019.H

static const uint64_t WRITE_PROTECT_ENABLE_REG = 0x20010005ull;

static const uint32_t WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING = 0;
static const uint32_t WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1;
// c/reg00019.H

static const uint64_t WRITE_PROTECT_RINGS_REG = 0x20010006ull;

static const uint32_t WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS = 0;
static const uint32_t WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS_LEN = 32;
// c/reg00019.H

}
}
#include "c/reg00000.H"
#include "c/reg00001.H"
#include "c/reg00002.H"
#include "c/reg00003.H"
#include "c/reg00004.H"
#include "c/reg00005.H"
#include "c/reg00006.H"
#include "c/reg00007.H"
#include "c/reg00008.H"
#include "c/reg00009.H"
#include "c/reg00010.H"
#include "c/reg00011.H"
#include "c/reg00012.H"
#include "c/reg00013.H"
#include "c/reg00014.H"
#include "c/reg00015.H"
#include "c/reg00016.H"
#include "c/reg00017.H"
#include "c/reg00018.H"
#include "c/reg00019.H"
#endif
