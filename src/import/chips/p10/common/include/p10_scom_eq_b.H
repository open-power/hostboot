/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_b.H $         */
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

#ifndef __p10_scom_eq_b_H_
#define __p10_scom_eq_b_H_


namespace scomt
{
namespace eq
{


static const uint64_t ATOMIC_LOCK_REG = 0x200f03ffull;

static const uint32_t ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t ATOMIC_LOCK_REG_ID = 1;
static const uint32_t ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// eq/reg00011.H

static const uint64_t ATTN_INTERRUPT_REG = 0x200f001aull;
// eq/reg00011.H

static const uint64_t EPS_DBG_TRACE_MODE_REG_2 = 0x200183efull;

static const uint32_t EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// eq/reg00011.H

static const uint64_t EPS_FIR_GXSTOP2_MASK_REG = 0x20040015ull;

static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_SUM_XSTOP = 0;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_SUM_RECOV = 1;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_SUM_SPATTN = 2;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_SUM_LOCAL_XSTOP = 3;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_SUM_TYPE4 = 4;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_SYSTEM_XSTOP = 5;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_OOB1 = 6;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// eq/reg00011.H

static const uint64_t EPS_FIR_LOCAL_MASK_RW = 0x2004000dull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_AND = 0x2004000eull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_OR = 0x2004000full;

static const uint32_t EPS_FIR_LOCAL_MASK_00 = 0;
static const uint32_t EPS_FIR_LOCAL_MASK_01 = 1;
static const uint32_t EPS_FIR_LOCAL_MASK_02 = 2;
static const uint32_t EPS_FIR_LOCAL_MASK_03 = 3;
static const uint32_t EPS_FIR_LOCAL_MASK_04 = 4;
static const uint32_t EPS_FIR_LOCAL_MASK_05 = 5;
static const uint32_t EPS_FIR_LOCAL_MASK_06 = 6;
static const uint32_t EPS_FIR_LOCAL_MASK_07 = 7;
static const uint32_t EPS_FIR_LOCAL_MASK_08 = 8;
static const uint32_t EPS_FIR_LOCAL_MASK_09 = 9;
static const uint32_t EPS_FIR_LOCAL_MASK_10 = 10;
static const uint32_t EPS_FIR_LOCAL_MASK_11 = 11;
static const uint32_t EPS_FIR_LOCAL_MASK_12 = 12;
static const uint32_t EPS_FIR_LOCAL_MASK_13 = 13;
static const uint32_t EPS_FIR_LOCAL_MASK_14 = 14;
static const uint32_t EPS_FIR_LOCAL_MASK_15 = 15;
static const uint32_t EPS_FIR_LOCAL_MASK_16 = 16;
static const uint32_t EPS_FIR_LOCAL_MASK_17 = 17;
static const uint32_t EPS_FIR_LOCAL_MASK_18 = 18;
static const uint32_t EPS_FIR_LOCAL_MASK_19 = 19;
static const uint32_t EPS_FIR_LOCAL_MASK_20 = 20;
static const uint32_t EPS_FIR_LOCAL_MASK_21 = 21;
static const uint32_t EPS_FIR_LOCAL_MASK_22 = 22;
static const uint32_t EPS_FIR_LOCAL_MASK_23 = 23;
static const uint32_t EPS_FIR_LOCAL_MASK_24 = 24;
static const uint32_t EPS_FIR_LOCAL_MASK_25 = 25;
static const uint32_t EPS_FIR_LOCAL_MASK_26 = 26;
static const uint32_t EPS_FIR_LOCAL_MASK_27 = 27;
static const uint32_t EPS_FIR_LOCAL_MASK_28 = 28;
static const uint32_t EPS_FIR_LOCAL_MASK_29 = 29;
static const uint32_t EPS_FIR_LOCAL_MASK_30 = 30;
static const uint32_t EPS_FIR_LOCAL_MASK_31 = 31;
static const uint32_t EPS_FIR_LOCAL_MASK_32 = 32;
static const uint32_t EPS_FIR_LOCAL_MASK_33 = 33;
static const uint32_t EPS_FIR_LOCAL_MASK_34 = 34;
static const uint32_t EPS_FIR_LOCAL_MASK_35 = 35;
static const uint32_t EPS_FIR_LOCAL_MASK_36 = 36;
static const uint32_t EPS_FIR_LOCAL_MASK_37 = 37;
static const uint32_t EPS_FIR_LOCAL_MASK_38 = 38;
static const uint32_t EPS_FIR_LOCAL_MASK_39 = 39;
static const uint32_t EPS_FIR_LOCAL_MASK_40 = 40;
static const uint32_t EPS_FIR_LOCAL_MASK_41 = 41;
static const uint32_t EPS_FIR_LOCAL_MASK_42 = 42;
static const uint32_t EPS_FIR_LOCAL_MASK_43 = 43;
static const uint32_t EPS_FIR_LOCAL_MASK_44 = 44;
static const uint32_t EPS_FIR_LOCAL_MASK_45 = 45;
static const uint32_t EPS_FIR_LOCAL_MASK_46 = 46;
static const uint32_t EPS_FIR_LOCAL_MASK_47 = 47;
static const uint32_t EPS_FIR_LOCAL_MASK_48 = 48;
// eq/reg00011.H

static const uint64_t EPS_THERM_WSUB2_CONTROL_REG = 0x20050032ull;
// eq/reg00011.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_DATA2 = 0x2005003bull;
// eq/reg00011.H

static const uint64_t L3TRA0_TR1_CONFIG_1 = 0x20018224ull;

static const uint32_t L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// eq/reg00011.H

static const uint64_t L3TRA1_TR0_TRACE_LO_DATA_REG = 0x20018241ull;

static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// eq/reg00011.H

static const uint64_t L3TRA2_TR0_CONFIG_0 = 0x20018283ull;

static const uint32_t L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// eq/reg00011.H

static const uint64_t L3TRA2_TR1_TRACE_HI_DATA_REG = 0x200182a0ull;

static const uint32_t L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// eq/reg00011.H

static const uint64_t L3TRA2_TR1_CONFIG_9 = 0x200182a9ull;

static const uint32_t L3TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// eq/reg00011.H

static const uint64_t LOCAL_FIR_RWX = 0x2004000aull;
static const uint64_t LOCAL_FIR_WOX_AND = 0x2004000bull;
static const uint64_t LOCAL_FIR_WOX_OR = 0x2004000cull;

static const uint32_t LOCAL_FIR_00 = 0;
static const uint32_t LOCAL_FIR_01 = 1;
static const uint32_t LOCAL_FIR_02 = 2;
static const uint32_t LOCAL_FIR_03 = 3;
static const uint32_t LOCAL_FIR_04 = 4;
static const uint32_t LOCAL_FIR_05 = 5;
static const uint32_t LOCAL_FIR_06 = 6;
static const uint32_t LOCAL_FIR_07 = 7;
static const uint32_t LOCAL_FIR_08 = 8;
static const uint32_t LOCAL_FIR_09 = 9;
static const uint32_t LOCAL_FIR_10 = 10;
static const uint32_t LOCAL_FIR_11 = 11;
static const uint32_t LOCAL_FIR_12 = 12;
static const uint32_t LOCAL_FIR_13 = 13;
static const uint32_t LOCAL_FIR_14 = 14;
static const uint32_t LOCAL_FIR_15 = 15;
static const uint32_t LOCAL_FIR_16 = 16;
static const uint32_t LOCAL_FIR_17 = 17;
static const uint32_t LOCAL_FIR_18 = 18;
static const uint32_t LOCAL_FIR_19 = 19;
static const uint32_t LOCAL_FIR_20 = 20;
static const uint32_t LOCAL_FIR_21 = 21;
static const uint32_t LOCAL_FIR_22 = 22;
static const uint32_t LOCAL_FIR_23 = 23;
static const uint32_t LOCAL_FIR_24 = 24;
static const uint32_t LOCAL_FIR_25 = 25;
static const uint32_t LOCAL_FIR_26 = 26;
static const uint32_t LOCAL_FIR_27 = 27;
static const uint32_t LOCAL_FIR_28 = 28;
static const uint32_t LOCAL_FIR_29 = 29;
static const uint32_t LOCAL_FIR_30 = 30;
static const uint32_t LOCAL_FIR_31 = 31;
static const uint32_t LOCAL_FIR_32 = 32;
static const uint32_t LOCAL_FIR_33 = 33;
static const uint32_t LOCAL_FIR_34 = 34;
static const uint32_t LOCAL_FIR_35 = 35;
static const uint32_t LOCAL_FIR_36 = 36;
static const uint32_t LOCAL_FIR_37 = 37;
static const uint32_t LOCAL_FIR_38 = 38;
static const uint32_t LOCAL_FIR_39 = 39;
static const uint32_t LOCAL_FIR_40 = 40;
static const uint32_t LOCAL_FIR_41 = 41;
static const uint32_t LOCAL_FIR_42 = 42;
static const uint32_t LOCAL_FIR_43 = 43;
static const uint32_t LOCAL_FIR_44 = 44;
static const uint32_t LOCAL_FIR_45 = 45;
static const uint32_t LOCAL_FIR_46 = 46;
static const uint32_t LOCAL_FIR_47 = 47;
static const uint32_t LOCAL_FIR_48 = 48;
// eq/reg00011.H

static const uint64_t QME_PCBQBI = 0x200e003cull;

static const uint32_t QME_PCBQBI_ENTRY_VALID = 0;
static const uint32_t QME_PCBQBI_MERGING_SCHEME = 2;
static const uint32_t QME_PCBQBI_MERGING_SCHEME_LEN = 3;
static const uint32_t QME_PCBQBI_R_NW = 8;
static const uint32_t QME_PCBQBI_PORT = 12;
static const uint32_t QME_PCBQBI_PORT_LEN = 4;
static const uint32_t QME_PCBQBI_ADDR = 16;
static const uint32_t QME_PCBQBI_ADDR_LEN = 16;
// eq/reg00011.H

static const uint64_t QME_RCPTR = 0x200e0188ull;

static const uint32_t QME_RCPTR_TARGET_PSTATE = 0;
static const uint32_t QME_RCPTR_TARGET_PSTATE_LEN = 8;
static const uint32_t QME_RCPTR_PSTATE_ACK_PENDING = 8;
static const uint32_t QME_RCPTR_TARGET_INDEX = 59;
static const uint32_t QME_RCPTR_TARGET_INDEX_LEN = 5;
// eq/reg00011.H

static const uint64_t QME_SCOM_XIMEM = 0x200e021cull;

static const uint32_t QME_SCOM_XIMEM_ADDR = 0;
static const uint32_t QME_SCOM_XIMEM_ADDR_LEN = 32;
static const uint32_t QME_SCOM_XIMEM_R_NW = 32;
static const uint32_t QME_SCOM_XIMEM_BUSY = 33;
static const uint32_t QME_SCOM_XIMEM_IMPRECISE_ERROR_PENDING = 34;
static const uint32_t QME_SCOM_XIMEM_BYTE_ENABLE = 35;
static const uint32_t QME_SCOM_XIMEM_BYTE_ENABLE_LEN = 8;
static const uint32_t QME_SCOM_XIMEM_LINE_MODE = 43;
static const uint32_t QME_SCOM_XIMEM_ERROR = 49;
static const uint32_t QME_SCOM_XIMEM_ERROR_LEN = 3;
static const uint32_t QME_SCOM_XIMEM_IFETCH_PENDING = 62;
static const uint32_t QME_SCOM_XIMEM_DATAOP_PENDING = 63;
// eq/reg00011.H

static const uint64_t QME_SCOM_XIVDR30 = 0x200e029cull;

static const uint32_t QME_SCOM_XIVDR30_0 = 0;
static const uint32_t QME_SCOM_XIVDR30_0_LEN = 32;
static const uint32_t QME_SCOM_XIVDR30_1 = 32;
static const uint32_t QME_SCOM_XIVDR30_1_LEN = 32;
// eq/reg00011.H

static const uint64_t QME_TTSR = 0x200e0138ull;
// eq/reg00011.H

}
}
#include "eq/reg00011.H"
#endif
