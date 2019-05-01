/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_7.H $       */
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

#ifndef __p10_scom_iohs_7_H_
#define __p10_scom_iohs_7_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_CC_PROTECT_MODE_REG = 0x180303feull;

static const uint32_t AXON_CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t AXON_CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// iohs/reg00007.H

static const uint64_t AXON_CPLT_CTRL4_RW = 0x18000004ull;
static const uint64_t AXON_CPLT_CTRL4_WO_CLEAR = 0x18000024ull;
static const uint64_t AXON_CPLT_CTRL4_WO_OR = 0x18000014ull;

static const uint32_t AXON_CPLT_CTRL4_0_FLUSHMODE_INH = 4;
static const uint32_t AXON_CPLT_CTRL4_1_FLUSHMODE_INH = 5;
static const uint32_t AXON_CPLT_CTRL4_2_FLUSHMODE_INH = 6;
static const uint32_t AXON_CPLT_CTRL4_3_FLUSHMODE_INH = 7;
static const uint32_t AXON_CPLT_CTRL4_4_FLUSHMODE_INH = 8;
static const uint32_t AXON_CPLT_CTRL4_5_FLUSHMODE_INH = 9;
static const uint32_t AXON_CPLT_CTRL4_6_FLUSHMODE_INH = 10;
static const uint32_t AXON_CPLT_CTRL4_7_FLUSHMODE_INH = 11;
static const uint32_t AXON_CPLT_CTRL4_8_FLUSHMODE_INH = 12;
static const uint32_t AXON_CPLT_CTRL4_9_FLUSHMODE_INH = 13;
static const uint32_t AXON_CPLT_CTRL4_10_FLUSHMODE_INH = 14;
static const uint32_t AXON_CPLT_CTRL4_11_FLUSHMODE_INH = 15;
static const uint32_t AXON_CPLT_CTRL4_12_FLUSHMODE_INH = 16;
static const uint32_t AXON_CPLT_CTRL4_13_FLUSHMODE_INH = 17;
static const uint32_t AXON_CPLT_CTRL4_14_FLUSHMODE_INH = 18;
// iohs/reg00007.H

static const uint64_t AXON_EPS_DBG_INST1_COND_REG_3 = 0x180107c3ull;
// iohs/reg00007.H

static const uint64_t AXON_EPS_DBG_INST2_COND_REG_3 = 0x180107c6ull;
// iohs/reg00007.H

static const uint64_t AXON_EPS_DBG_TRACE_REG_0 = 0x180107cdull;

static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t AXON_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// iohs/reg00007.H

static const uint64_t AXON_EPS_THERM_WSUB_SKITTER_CLKSRC_REG = 0x18050016ull;

static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC = 0;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC_LEN = 3;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT = 36;
static const uint32_t AXON_EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN = 2;
// iohs/reg00007.H

static const uint64_t AXON_OPCG_REG1 = 0x18030003ull;

static const uint32_t AXON_OPCG_REG1_SCAN_COUNT = 0;
static const uint32_t AXON_OPCG_REG1_SCAN_COUNT_LEN = 12;
static const uint32_t AXON_OPCG_REG1_MISR_A_VAL = 12;
static const uint32_t AXON_OPCG_REG1_MISR_A_VAL_LEN = 12;
static const uint32_t AXON_OPCG_REG1_MISR_B_VAL = 24;
static const uint32_t AXON_OPCG_REG1_MISR_B_VAL_LEN = 12;
static const uint32_t AXON_OPCG_REG1_MISR_INIT_WAIT = 36;
static const uint32_t AXON_OPCG_REG1_MISR_INIT_WAIT_LEN = 12;
static const uint32_t AXON_OPCG_REG1_SCAN_CLK_USE_EVEN = 49;
static const uint32_t AXON_OPCG_REG1_RTIM_THOLD_FORCE = 52;
static const uint32_t AXON_OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL = 53;
static const uint32_t AXON_OPCG_REG1_SG_HIGH_DURING_FILL = 54;
static const uint32_t AXON_OPCG_REG1_LBIST_SKITTER_CTL = 55;
static const uint32_t AXON_OPCG_REG1_LBIST_SKITTER_CTL_LEN = 2;
static const uint32_t AXON_OPCG_REG1_MISR_MODE = 57;
static const uint32_t AXON_OPCG_REG1_INFINITE_MODE = 58;
static const uint32_t AXON_OPCG_REG1_NSL_FILL_COUNT = 59;
static const uint32_t AXON_OPCG_REG1_NSL_FILL_COUNT_LEN = 5;
// iohs/reg00007.H

static const uint64_t AXON_SCAN_CAPTUREDR = 0x1803c000ull;
// iohs/reg00007.H

static const uint64_t HANG_PULSE_0_REG = 0x180f0020ull;

static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0 = 0;
static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN = 6;
static const uint32_t HANG_PULSE_0_REG_SUPPRESS_HANG_0 = 6;
// iohs/reg00007.H

static const uint64_t HANG_PULSE_1_REG = 0x180f0021ull;

static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1 = 0;
static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN = 6;
static const uint32_t HANG_PULSE_1_REG_SUPPRESS_HANG_1 = 6;
// iohs/reg00007.H

static const uint64_t HANG_PULSE_2_REG = 0x180f0022ull;

static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2 = 0;
static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN = 6;
static const uint32_t HANG_PULSE_2_REG_SUPPRESS_HANG_2 = 6;
// iohs/reg00007.H

static const uint64_t HANG_PULSE_3_REG = 0x180f0023ull;

static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3 = 0;
static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN = 6;
static const uint32_t HANG_PULSE_3_REG_SUPPRESS_HANG_3 = 6;
// iohs/reg00007.H

static const uint64_t HANG_PULSE_4_REG = 0x180f0024ull;

static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4 = 0;
static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN = 6;
static const uint32_t HANG_PULSE_4_REG_SUPPRESS_HANG_4 = 6;
// iohs/reg00007.H

static const uint64_t HANG_PULSE_5_REG = 0x180f0025ull;

static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5 = 0;
static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN = 6;
static const uint32_t HANG_PULSE_5_REG_SUPPRESS_HANG_5 = 6;
// iohs/reg00007.H

static const uint64_t HANG_PULSE_6_REG = 0x180f0026ull;

static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6 = 0;
static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN = 6;
static const uint32_t HANG_PULSE_6_REG_SUPPRESS_HANG_6 = 6;
// iohs/reg00007.H

static const uint64_t HOSTATTN_INTERRUPT_REG = 0x180f002bull;
// iohs/reg00007.H

}
}
#include "iohs/reg00007.H"
#endif
