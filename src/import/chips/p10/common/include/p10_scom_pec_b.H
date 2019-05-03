/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_b.H $        */
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

#ifndef __p10_scom_pec_b_H_
#define __p10_scom_pec_b_H_


namespace scomt
{
namespace pec
{


static const uint64_t ATOMIC_LOCK_REG = 0x080f03ffull;

static const uint32_t ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t ATOMIC_LOCK_REG_ID = 1;
static const uint32_t ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// pec/reg00011.H

static const uint64_t ATTN_INTERRUPT_REG = 0x080f001aull;
// pec/reg00011.H

static const uint64_t EPS_DBG_TRACE_MODE_REG_2 = 0x080107cfull;

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
// pec/reg00011.H

static const uint64_t EPS_FIR_GXSTOP2_MASK_REG = 0x08040015ull;

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
// pec/reg00011.H

static const uint64_t EPS_FIR_LOCAL_MASK_RW = 0x0804000dull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_AND = 0x0804000eull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_OR = 0x0804000full;

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
// pec/reg00011.H

static const uint64_t LOCAL_FIR_RWX = 0x0804000aull;
static const uint64_t LOCAL_FIR_WOX_AND = 0x0804000bull;
static const uint64_t LOCAL_FIR_WOX_OR = 0x0804000cull;

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
// pec/reg00011.H

static const uint64_t PB_PBCQ_PEPBREGS_NSTQSTKOVR_REG = 0x0301180aull;

static const uint32_t PB_PBCQ_PEPBREGS_NSTQSTKOVR_REG_STK0 = 0;
static const uint32_t PB_PBCQ_PEPBREGS_NSTQSTKOVR_REG_STK0_LEN = 16;
static const uint32_t PB_PBCQ_PEPBREGS_NSTQSTKOVR_REG_STK1 = 16;
static const uint32_t PB_PBCQ_PEPBREGS_NSTQSTKOVR_REG_STK1_LEN = 8;
static const uint32_t PB_PBCQ_PEPBREGS_NSTQSTKOVR_REG_ENABLE = 24;
// pec/reg00011.H

static const uint64_t TRA0_TR1_CONFIG_1 = 0x08010444ull;

static const uint32_t TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// pec/reg00011.H

}
}
#include "pec/reg00011.H"
#endif
