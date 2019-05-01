/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_2.H $       */
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

#ifndef __p10_scom_iohs_2_H_
#define __p10_scom_iohs_2_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_CPLT_CTRL2_RW = 0x18000002ull;
static const uint64_t AXON_CPLT_CTRL2_WO_CLEAR = 0x18000022ull;
static const uint64_t AXON_CPLT_CTRL2_WO_OR = 0x18000012ull;

static const uint32_t AXON_CPLT_CTRL2_0_PGOOD = 4;
static const uint32_t AXON_CPLT_CTRL2_1_PGOOD = 5;
static const uint32_t AXON_CPLT_CTRL2_2_PGOOD = 6;
static const uint32_t AXON_CPLT_CTRL2_3_PGOOD = 7;
static const uint32_t AXON_CPLT_CTRL2_4_PGOOD = 8;
static const uint32_t AXON_CPLT_CTRL2_5_PGOOD = 9;
static const uint32_t AXON_CPLT_CTRL2_6_PGOOD = 10;
static const uint32_t AXON_CPLT_CTRL2_7_PGOOD = 11;
static const uint32_t AXON_CPLT_CTRL2_8_PGOOD = 12;
static const uint32_t AXON_CPLT_CTRL2_9_PGOOD = 13;
static const uint32_t AXON_CPLT_CTRL2_10_PGOOD = 14;
static const uint32_t AXON_CPLT_CTRL2_11_PGOOD = 15;
static const uint32_t AXON_CPLT_CTRL2_12_PGOOD = 16;
static const uint32_t AXON_CPLT_CTRL2_13_PGOOD = 17;
static const uint32_t AXON_CPLT_CTRL2_14_PGOOD = 18;
// iohs/reg00002.H

static const uint64_t AXON_CPLT_MASK0 = 0x18000101ull;

static const uint32_t AXON_CPLT_MASK0_ITR_MASK = 0;
static const uint32_t AXON_CPLT_MASK0_ITR_MASK_LEN = 24;
// iohs/reg00002.H

static const uint64_t AXON_CTRL_PROTECT_MODE_REG = 0x180003feull;

static const uint32_t AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// iohs/reg00002.H

static const uint64_t AXON_EPS_FIR_GXSTOP3_MASK_REG = 0x18040016ull;

static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_XSTOP = 0;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_RECOV = 1;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_SPATTN = 2;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_LOCAL_XSTOP = 3;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_SUM_TYPE4 = 4;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_SYSTEM_XSTOP = 5;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_OOB1 = 6;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t AXON_EPS_FIR_GXSTOP3_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// iohs/reg00002.H

static const uint64_t AXON_EPS_FIR_LOCAL_MASK_RW = 0x1804000dull;
static const uint64_t AXON_EPS_FIR_LOCAL_MASK_WO_AND = 0x1804000eull;
static const uint64_t AXON_EPS_FIR_LOCAL_MASK_WO_OR = 0x1804000full;

static const uint32_t AXON_EPS_FIR_LOCAL_MASK_00 = 0;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_01 = 1;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_02 = 2;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_03 = 3;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_04 = 4;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_05 = 5;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_06 = 6;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_07 = 7;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_08 = 8;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_09 = 9;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_10 = 10;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_11 = 11;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_12 = 12;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_13 = 13;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_14 = 14;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_15 = 15;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_16 = 16;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_17 = 17;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_18 = 18;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_19 = 19;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_20 = 20;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_21 = 21;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_22 = 22;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_23 = 23;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_24 = 24;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_25 = 25;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_26 = 26;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_27 = 27;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_28 = 28;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_29 = 29;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_30 = 30;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_31 = 31;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_32 = 32;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_33 = 33;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_34 = 34;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_35 = 35;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_36 = 36;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_37 = 37;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_38 = 38;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_39 = 39;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_40 = 40;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_41 = 41;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_42 = 42;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_43 = 43;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_44 = 44;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_45 = 45;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_46 = 46;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_47 = 47;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_48 = 48;
// iohs/reg00002.H

static const uint64_t AXON_EPS_THERM_WSUB_SKITTER_DATA1 = 0x1805001aull;
// iohs/reg00002.H

static const uint64_t AXON_LOCAL_FIR_RWX = 0x1804000aull;
static const uint64_t AXON_LOCAL_FIR_WOX_AND = 0x1804000bull;
static const uint64_t AXON_LOCAL_FIR_WOX_OR = 0x1804000cull;

static const uint32_t AXON_LOCAL_FIR_00 = 0;
static const uint32_t AXON_LOCAL_FIR_01 = 1;
static const uint32_t AXON_LOCAL_FIR_02 = 2;
static const uint32_t AXON_LOCAL_FIR_03 = 3;
static const uint32_t AXON_LOCAL_FIR_04 = 4;
static const uint32_t AXON_LOCAL_FIR_05 = 5;
static const uint32_t AXON_LOCAL_FIR_06 = 6;
static const uint32_t AXON_LOCAL_FIR_07 = 7;
static const uint32_t AXON_LOCAL_FIR_08 = 8;
static const uint32_t AXON_LOCAL_FIR_09 = 9;
static const uint32_t AXON_LOCAL_FIR_10 = 10;
static const uint32_t AXON_LOCAL_FIR_11 = 11;
static const uint32_t AXON_LOCAL_FIR_12 = 12;
static const uint32_t AXON_LOCAL_FIR_13 = 13;
static const uint32_t AXON_LOCAL_FIR_14 = 14;
static const uint32_t AXON_LOCAL_FIR_15 = 15;
static const uint32_t AXON_LOCAL_FIR_16 = 16;
static const uint32_t AXON_LOCAL_FIR_17 = 17;
static const uint32_t AXON_LOCAL_FIR_18 = 18;
static const uint32_t AXON_LOCAL_FIR_19 = 19;
static const uint32_t AXON_LOCAL_FIR_20 = 20;
static const uint32_t AXON_LOCAL_FIR_21 = 21;
static const uint32_t AXON_LOCAL_FIR_22 = 22;
static const uint32_t AXON_LOCAL_FIR_23 = 23;
static const uint32_t AXON_LOCAL_FIR_24 = 24;
static const uint32_t AXON_LOCAL_FIR_25 = 25;
static const uint32_t AXON_LOCAL_FIR_26 = 26;
static const uint32_t AXON_LOCAL_FIR_27 = 27;
static const uint32_t AXON_LOCAL_FIR_28 = 28;
static const uint32_t AXON_LOCAL_FIR_29 = 29;
static const uint32_t AXON_LOCAL_FIR_30 = 30;
static const uint32_t AXON_LOCAL_FIR_31 = 31;
static const uint32_t AXON_LOCAL_FIR_32 = 32;
static const uint32_t AXON_LOCAL_FIR_33 = 33;
static const uint32_t AXON_LOCAL_FIR_34 = 34;
static const uint32_t AXON_LOCAL_FIR_35 = 35;
static const uint32_t AXON_LOCAL_FIR_36 = 36;
static const uint32_t AXON_LOCAL_FIR_37 = 37;
static const uint32_t AXON_LOCAL_FIR_38 = 38;
static const uint32_t AXON_LOCAL_FIR_39 = 39;
static const uint32_t AXON_LOCAL_FIR_40 = 40;
static const uint32_t AXON_LOCAL_FIR_41 = 41;
static const uint32_t AXON_LOCAL_FIR_42 = 42;
static const uint32_t AXON_LOCAL_FIR_43 = 43;
static const uint32_t AXON_LOCAL_FIR_44 = 44;
static const uint32_t AXON_LOCAL_FIR_45 = 45;
static const uint32_t AXON_LOCAL_FIR_46 = 46;
static const uint32_t AXON_LOCAL_FIR_47 = 47;
static const uint32_t AXON_LOCAL_FIR_48 = 48;
// iohs/reg00002.H

}
}
#include "iohs/reg00002.H"
#endif
