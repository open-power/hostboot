/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_1.H $       */
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

#ifndef __p10_scom_iohs_1_H_
#define __p10_scom_iohs_1_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_CPLT_CTRL5_RW = 0x18000005ull;
static const uint64_t AXON_CPLT_CTRL5_WO_CLEAR = 0x18000025ull;
static const uint64_t AXON_CPLT_CTRL5_WO_OR = 0x18000015ull;

static const uint32_t AXON_CPLT_CTRL5_0 = 0;
static const uint32_t AXON_CPLT_CTRL5_1 = 1;
static const uint32_t AXON_CPLT_CTRL5_2 = 2;
static const uint32_t AXON_CPLT_CTRL5_3 = 3;
static const uint32_t AXON_CPLT_CTRL5_4 = 4;
static const uint32_t AXON_CPLT_CTRL5_5 = 5;
static const uint32_t AXON_CPLT_CTRL5_6 = 6;
static const uint32_t AXON_CPLT_CTRL5_7 = 7;
static const uint32_t AXON_CPLT_CTRL5_8 = 8;
static const uint32_t AXON_CPLT_CTRL5_9 = 9;
static const uint32_t AXON_CPLT_CTRL5_10 = 10;
static const uint32_t AXON_CPLT_CTRL5_11 = 11;
static const uint32_t AXON_CPLT_CTRL5_12 = 12;
static const uint32_t AXON_CPLT_CTRL5_13 = 13;
static const uint32_t AXON_CPLT_CTRL5_14 = 14;
static const uint32_t AXON_CPLT_CTRL5_15 = 15;
static const uint32_t AXON_CPLT_CTRL5_16 = 16;
static const uint32_t AXON_CPLT_CTRL5_17 = 17;
static const uint32_t AXON_CPLT_CTRL5_18 = 18;
static const uint32_t AXON_CPLT_CTRL5_19 = 19;
// iohs/reg00001.H

static const uint64_t AXON_EPS_DBG_INST1_COND_REG_2 = 0x180107c2ull;

static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t AXON_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN = 24;
// iohs/reg00001.H

static const uint64_t AXON_EPS_DBG_INST2_COND_REG_2 = 0x180107c5ull;

static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t AXON_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN = 24;
// iohs/reg00001.H

static const uint64_t AXON_EPS_DBG_TRACE_REG_1 = 0x180107ceull;

static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t AXON_EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// iohs/reg00001.H

static const uint64_t AXON_EPS_FIR_GXSTOP0_MASK_REG = 0x18040013ull;

static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP = 0;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV = 1;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN = 2;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP = 3;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 = 4;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP = 5;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_OOB1 = 6;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t AXON_EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// iohs/reg00001.H

static const uint64_t AXON_EPS_THERM_WSUB_DTS_RESULT2 = 0x18050002ull;

static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// iohs/reg00001.H

static const uint64_t AXON_OPCG_REG0 = 0x18030002ull;

static const uint32_t AXON_OPCG_REG0_RUNN_MODE = 0;
static const uint32_t AXON_OPCG_REG0_OPCG_GO = 1;
static const uint32_t AXON_OPCG_REG0_RUN_SCAN0 = 2;
static const uint32_t AXON_OPCG_REG0_SCAN0_MODE = 3;
static const uint32_t AXON_OPCG_REG0_OPCG_IN_SLAVE_MODE = 4;
static const uint32_t AXON_OPCG_REG0_OPCG_IN_MASTER_MODE = 5;
static const uint32_t AXON_OPCG_REG0_KEEP_MS_MODE = 6;
static const uint32_t AXON_OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL = 7;
static const uint32_t AXON_OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL = 8;
static const uint32_t AXON_OPCG_REG0_RUN_OPCG_ON_UPDATE_DR = 11;
static const uint32_t AXON_OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR = 12;
static const uint32_t AXON_OPCG_REG0_STOP_RUNN_ON_XSTOP = 13;
static const uint32_t AXON_OPCG_REG0_OPCG_STARTS_BIST = 14;
static const uint32_t AXON_OPCG_REG0_LOOP_COUNT = 21;
static const uint32_t AXON_OPCG_REG0_LOOP_COUNT_LEN = 43;
// iohs/reg00001.H

static const uint64_t HEARTBEAT_REG = 0x180f0018ull;

static const uint32_t HEARTBEAT_REG_HEARTBEAT_DEAD = 0;
// iohs/reg00001.H

static const uint64_t RECOV_INTERRUPT_REG = 0x180f001bull;
// iohs/reg00001.H

}
}
#include "iohs/reg00001.H"
#endif
