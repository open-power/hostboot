/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_c.H $       */
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

#ifndef __p10_scom_iohs_c_H_
#define __p10_scom_iohs_c_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_CPLT_STAT0 = 0x18000100ull;

static const uint32_t AXON_CPLT_STAT0_ABIST_DONE_DC = 0;
static const uint32_t AXON_CPLT_STAT0_RESERVED_2I = 2;
static const uint32_t AXON_CPLT_STAT0_RESERVED_3I = 3;
static const uint32_t AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT = 4;
static const uint32_t AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT = 5;
static const uint32_t AXON_CPLT_STAT0_RESERVED_6I = 6;
static const uint32_t AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC = 8;
static const uint32_t AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC = 9;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_10I = 10;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_11I = 11;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_12I = 12;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_13I = 13;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_14I = 14;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_15I = 15;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_16I = 16;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_17I = 17;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_18I = 18;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_19I = 19;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_20I = 20;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_21I = 21;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_22I = 22;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_23I = 23;
// iohs/reg00012.H

static const uint64_t AXON_EPS_FIR_GXSTOP2_MASK_REG = 0x18040015ull;

static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_SUM_XSTOP = 0;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_SUM_RECOV = 1;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_SUM_SPATTN = 2;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_SUM_LOCAL_XSTOP = 3;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_SUM_TYPE4 = 4;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_SYSTEM_XSTOP = 5;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_OOB1 = 6;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t AXON_EPS_FIR_GXSTOP2_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// iohs/reg00012.H

static const uint64_t AXON_EPS_FIR_LOCAL_ACTION0 = 0x18040010ull;

static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_00 = 0;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_01 = 1;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_02 = 2;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_03 = 3;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_04 = 4;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_05 = 5;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_06 = 6;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_07 = 7;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_08 = 8;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_09 = 9;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_10 = 10;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_11 = 11;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_12 = 12;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_13 = 13;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_14 = 14;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_15 = 15;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_16 = 16;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_17 = 17;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_18 = 18;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_19 = 19;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_20 = 20;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_21 = 21;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_22 = 22;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_23 = 23;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_24 = 24;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_25 = 25;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_26 = 26;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_27 = 27;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_28 = 28;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_29 = 29;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_30 = 30;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_31 = 31;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_32 = 32;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_33 = 33;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_34 = 34;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_35 = 35;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_36 = 36;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_37 = 37;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_38 = 38;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_39 = 39;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_40 = 40;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_41 = 41;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_42 = 42;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_43 = 43;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_44 = 44;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_45 = 45;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_46 = 46;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_47 = 47;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_48 = 48;
// iohs/reg00012.H

static const uint64_t AXON_HOSTATTN = 0x18040009ull;

static const uint32_t AXON_HOSTATTN_ANY_HOST_ATTN = 0;
static const uint32_t AXON_HOSTATTN_RESERVED1H = 1;
static const uint32_t AXON_HOSTATTN_RESERVED2H = 2;
static const uint32_t AXON_HOSTATTN_RESERVED3H = 3;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_PERV = 4;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN05 = 5;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN06 = 6;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN07 = 7;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN08 = 8;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN09 = 9;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN10 = 10;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN11 = 11;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN12 = 12;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN13 = 13;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN14 = 14;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN15 = 15;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN16 = 16;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN17 = 17;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN18 = 18;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN19 = 19;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN20 = 20;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN21 = 21;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN22 = 22;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN23 = 23;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN24 = 24;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN25 = 25;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN26 = 26;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN27 = 27;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN28 = 28;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN29 = 29;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN30 = 30;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN31 = 31;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN32 = 32;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN33 = 33;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN34 = 34;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN35 = 35;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN36 = 36;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN37 = 37;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN38 = 38;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN39 = 39;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN40 = 40;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN41 = 41;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN42 = 42;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN43 = 43;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN44 = 44;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN45 = 45;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN46 = 46;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN47 = 47;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN48 = 48;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN49 = 49;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN50 = 50;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN51 = 51;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN52 = 52;
static const uint32_t AXON_HOSTATTN_HOST_ATTN_IN53 = 53;
// iohs/reg00012.H

static const uint64_t AXON_TRA0_TR0_CONFIG_1 = 0x18010404ull;

static const uint32_t AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// iohs/reg00012.H

static const uint64_t AXON_XSTOP3 = 0x1803000eull;

static const uint32_t AXON_XSTOP3_XSTOP3_MASK_B = 0;
static const uint32_t AXON_XSTOP3_ALIGNED_XSTOP3 = 1;
static const uint32_t AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3 = 2;
static const uint32_t AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS = 3;
static const uint32_t AXON_XSTOP3_XSTOP3_PERV = 4;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT1 = 5;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT2 = 6;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT3 = 7;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT4 = 8;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT5 = 9;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT6 = 10;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT7 = 11;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT8 = 12;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT9 = 13;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT10 = 14;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT11 = 15;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT12 = 16;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT13 = 17;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT14 = 18;
static const uint32_t AXON_XSTOP3_XSTOP3_WAIT_CYCLES = 48;
static const uint32_t AXON_XSTOP3_XSTOP3_WAIT_CYCLES_LEN = 12;
// iohs/reg00012.H

static const uint64_t MULTICAST_GROUP_4 = 0x180f0004ull;

static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP = 3;
static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN = 3;
// iohs/reg00012.H

static const uint64_t PRE_COUNTER_REG = 0x180f0028ull;

static const uint32_t PRE_COUNTER_REG_PRE_COUNTER = 0;
static const uint32_t PRE_COUNTER_REG_PRE_COUNTER_LEN = 8;
// iohs/reg00012.H

static const uint64_t XSTOP_INTERRUPT_REG = 0x180f001cull;
// iohs/reg00012.H

}
}
#include "iohs/reg00012.H"
#endif
