/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_a.H $       */
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

#ifndef __p10_scom_iohs_a_H_
#define __p10_scom_iohs_a_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_CC_ATOMIC_LOCK_REG = 0x180303ffull;

static const uint32_t AXON_CC_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t AXON_CC_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t AXON_CC_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t AXON_CC_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t AXON_CC_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// iohs/reg00010.H

static const uint64_t AXON_EPS_DBG_TRACE_MODE_REG_2 = 0x180107cfull;

static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t AXON_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// iohs/reg00010.H

static const uint64_t AXON_EPS_FIR_LOCAL_ACTION1 = 0x18040011ull;

static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_00 = 0;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_01 = 1;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_02 = 2;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_03 = 3;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_04 = 4;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_05 = 5;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_06 = 6;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_07 = 7;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_08 = 8;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_09 = 9;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_10 = 10;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_11 = 11;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_12 = 12;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_13 = 13;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_14 = 14;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_15 = 15;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_16 = 16;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_17 = 17;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_18 = 18;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_19 = 19;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_20 = 20;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_21 = 21;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_22 = 22;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_23 = 23;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_24 = 24;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_25 = 25;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_26 = 26;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_27 = 27;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_28 = 28;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_29 = 29;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_30 = 30;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_31 = 31;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_32 = 32;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_33 = 33;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_34 = 34;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_35 = 35;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_36 = 36;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_37 = 37;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_38 = 38;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_39 = 39;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_40 = 40;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_41 = 41;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_42 = 42;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_43 = 43;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_44 = 44;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_45 = 45;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_46 = 46;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_47 = 47;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION1_48 = 48;
// iohs/reg00010.H

static const uint64_t AXON_SCAN_UPDATEDR_LONG = 0x1803b000ull;
// iohs/reg00010.H

static const uint64_t AXON_SYNC_CONFIG = 0x18030000ull;

static const uint32_t AXON_SYNC_CONFIG_SYNC_PULSE_DELAY = 0;
static const uint32_t AXON_SYNC_CONFIG_SYNC_PULSE_DELAY_LEN = 4;
static const uint32_t AXON_SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS = 4;
static const uint32_t AXON_SYNC_CONFIG_SYNC_PULSE_INPUT_SEL = 5;
static const uint32_t AXON_SYNC_CONFIG_USE_SYNC_FOR_SCAN = 6;
static const uint32_t AXON_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED = 7;
static const uint32_t AXON_SYNC_CONFIG_UNIT_REGION_CLKCMD_ENABLE = 8;
static const uint32_t AXON_SYNC_CONFIG_DISABLE_PCB_ITR = 9;
static const uint32_t AXON_SYNC_CONFIG_CONT_SCAN_DISABLE = 10;
static const uint32_t AXON_SYNC_CONFIG_SYNC_PULSE_OUT_DIS = 11;
static const uint32_t AXON_SYNC_CONFIG_REGION_PGOOD_OVERRIDE = 12;
static const uint32_t AXON_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN = 15;
static const uint32_t AXON_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE = 16;
static const uint32_t AXON_SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN = 8;
// iohs/reg00010.H

static const uint64_t AXON_TRA0_TR0_CONFIG_0 = 0x18010403ull;

static const uint32_t AXON_TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t AXON_TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// iohs/reg00010.H

static const uint64_t AXON_XSTOP2 = 0x1803000dull;

static const uint32_t AXON_XSTOP2_XSTOP2_MASK_B = 0;
static const uint32_t AXON_XSTOP2_ALIGNED_XSTOP2 = 1;
static const uint32_t AXON_XSTOP2_TRIGGER_OPCG_ON_XSTOP2 = 2;
static const uint32_t AXON_XSTOP2_XSTOP2_WAIT_ALLWAYS = 3;
static const uint32_t AXON_XSTOP2_XSTOP2_PERV = 4;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT1 = 5;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT2 = 6;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT3 = 7;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT4 = 8;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT5 = 9;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT6 = 10;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT7 = 11;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT8 = 12;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT9 = 13;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT10 = 14;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT11 = 15;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT12 = 16;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT13 = 17;
static const uint32_t AXON_XSTOP2_XSTOP2_UNIT14 = 18;
static const uint32_t AXON_XSTOP2_XSTOP2_WAIT_CYCLES = 48;
static const uint32_t AXON_XSTOP2_XSTOP2_WAIT_CYCLES_LEN = 12;
// iohs/reg00010.H

}
}
#include "iohs/reg00010.H"
#endif
