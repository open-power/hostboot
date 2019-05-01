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
// perv/reg00013.H

static const uint64_t CTRL_ATOMIC_LOCK_REG = 0x000003ffull;

static const uint32_t CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// perv/reg00013.H

static const uint64_t DPLL_CNTL_NEST_REGS_STAT = 0x00000155ull;

static const uint32_t DPLL_CNTL_NEST_REGS_STAT_FREQOUT = 1;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_FREQOUT_LEN = 11;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT = 12;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_HIRES_FREQOUT_LEN = 5;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE = 60;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_FREQ_CHANGE = 61;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_BLOCK_ACTIVE = 62;
static const uint32_t DPLL_CNTL_NEST_REGS_STAT_LOCK = 63;
// perv/reg00013.H

static const uint64_t EPS_DBG_DEBUG_TRACE_CONTROL = 0x000107d0ull;
// perv/reg00013.H

static const uint64_t EPS_FIR_SUM_MASK_REG = 0x00040017ull;

static const uint32_t EPS_FIR_SUM_MASK_REG_XSTOP_TO_PCB = 0;
static const uint32_t EPS_FIR_SUM_MASK_REG_RECOV_TO_PCB = 1;
static const uint32_t EPS_FIR_SUM_MASK_REG_SPATTN_TO_PCB = 2;
static const uint32_t EPS_FIR_SUM_MASK_REG_LOCAL_XSTOP_TO_PCB = 3;
static const uint32_t EPS_FIR_SUM_MASK_REG_HOSTATTN_TO_PCB = 4;
// perv/reg00013.H

static const uint64_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ = 0x0005003cull;

static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
// perv/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

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
// perv/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR1_CONFIG_0 = 0x00018223ull;

static const uint32_t L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA2_TR0_CONFIG_1 = 0x00018284ull;

static const uint32_t L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

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
// perv/reg00013.H

//ERRCODE: // Some of the name targets not found in address targets.

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
// perv/reg00013.H

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
// perv/reg00013.H

static const uint64_t PRIMARY_ADDRESS_REG = 0x000f0000ull;
// perv/reg00013.H

static const uint64_t SCAN_UPDATEDR_LONG = 0x0003b000ull;
// perv/reg00013.H

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
// perv/reg00013.H

static const uint64_t TRA0_TR1_CONFIG_0 = 0x00010443ull;

static const uint32_t TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00013.H

static const uint64_t TRA1_TR1_TRACE_HI_DATA_REG = 0x000104c0ull;

static const uint32_t TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00013.H

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
// perv/reg00013.H

static const uint64_t TRA2_TR0_CONFIG_1 = 0x00010504ull;

static const uint32_t TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00013.H

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
// perv/reg00013.H

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
// perv/reg00013.H

static const uint64_t TRA5_TR0_CONFIG_0 = 0x00010683ull;

static const uint32_t TRA5_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA5_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00013.H

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
// perv/reg00013.H

}
}
#include "perv/reg00013.H"
#endif
