/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_9.H $         */
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

#ifndef __p10_scom_mc_9_H_
#define __p10_scom_mc_9_H_


namespace scomt
{
namespace mc
{


static const uint64_t CPLT_CTRL4_RW = 0x0c000004ull;
static const uint64_t CPLT_CTRL4_WO_CLEAR = 0x0c000024ull;
static const uint64_t CPLT_CTRL4_WO_OR = 0x0c000014ull;

static const uint32_t CPLT_CTRL4_0_FLUSHMODE_INH = 4;
static const uint32_t CPLT_CTRL4_1_FLUSHMODE_INH = 5;
static const uint32_t CPLT_CTRL4_2_FLUSHMODE_INH = 6;
static const uint32_t CPLT_CTRL4_3_FLUSHMODE_INH = 7;
static const uint32_t CPLT_CTRL4_4_FLUSHMODE_INH = 8;
static const uint32_t CPLT_CTRL4_5_FLUSHMODE_INH = 9;
static const uint32_t CPLT_CTRL4_6_FLUSHMODE_INH = 10;
static const uint32_t CPLT_CTRL4_7_FLUSHMODE_INH = 11;
static const uint32_t CPLT_CTRL4_8_FLUSHMODE_INH = 12;
static const uint32_t CPLT_CTRL4_9_FLUSHMODE_INH = 13;
static const uint32_t CPLT_CTRL4_10_FLUSHMODE_INH = 14;
static const uint32_t CPLT_CTRL4_11_FLUSHMODE_INH = 15;
static const uint32_t CPLT_CTRL4_12_FLUSHMODE_INH = 16;
static const uint32_t CPLT_CTRL4_13_FLUSHMODE_INH = 17;
static const uint32_t CPLT_CTRL4_14_FLUSHMODE_INH = 18;
// mc/reg00009.H

static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3 = 0x0c040083ull;

static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR = 0;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR = 1;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR = 2;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR = 3;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR = 4;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR = 5;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_OOB1_ERR = 6;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR = 7;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010 = 21;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011 = 22;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012 = 23;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013 = 24;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014 = 25;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015 = 26;
// mc/reg00009.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT1 = 0x0c050001ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
// mc/reg00009.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA2 = 0x0c05001bull;
// mc/reg00009.H

static const uint64_t EPS_THERM_WSUB_SKITTER_FORCE_REG = 0x0c050014ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// mc/reg00009.H

static const uint64_t MBA_SCOMFIR_AADR = 0x0c010f2aull;

static const uint32_t MBA_SCOMFIR_AADR_AADR_DATA = 0;
static const uint32_t MBA_SCOMFIR_AADR_AADR_DATA_LEN = 64;
// mc/reg00009.H

static const uint64_t MBA_SCOMFIR_WATCFG0DQ = 0x0c010f83ull;

static const uint32_t MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA = 0;
static const uint32_t MBA_SCOMFIR_WATCFG0DQ_WATCFG0DQ_CFG_WAT_PATA_LEN = 44;
// mc/reg00009.H

static const uint64_t MBA_SCOMFIR_WATCFG1CQ = 0x0c010f87ull;

static const uint32_t MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB = 0;
static const uint32_t MBA_SCOMFIR_WATCFG1CQ_WATCFG1CQ_CFG_WAT_MSKB_LEN = 44;
// mc/reg00009.H

static const uint64_t MULTICAST_GROUP_2 = 0x0c0f0002ull;

static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// mc/reg00009.H

static const uint64_t SCOMFIR_MCFIRMASK_RW = 0x0c010c03ull;
static const uint64_t SCOMFIR_MCFIRMASK_WO_AND = 0x0c010c04ull;
static const uint64_t SCOMFIR_MCFIRMASK_WO_OR = 0x0c010c05ull;

static const uint32_t SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK = 0;
static const uint32_t SCOMFIR_MCFIRMASK_MCFIRMASK_FIR_MASK_LEN = 24;
// mc/reg00009.H

static const uint64_t SCOMFIR_MCFIRWOF = 0x0c010c08ull;

static const uint32_t SCOMFIR_MCFIRWOF_MCFIRWOF_WOF = 0;
static const uint32_t SCOMFIR_MCFIRWOF_MCFIRWOF_WOF_LEN = 24;
// mc/reg00009.H

static const uint64_t TRA0_TR0_CONFIG_0 = 0x0c010403ull;

static const uint32_t TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// mc/reg00009.H

static const uint64_t XSTOP = 0x0c040000ull;

static const uint32_t XSTOP_ANY_XSTOP = 0;
static const uint32_t XSTOP_SYSTEM_XSTOP = 1;
static const uint32_t XSTOP_XSTOP_ANY_SPATTN = 2;
static const uint32_t XSTOP_DBG_FIR_XSTOP_ON_TRIG = 3;
static const uint32_t XSTOP_XSTOP_PERV = 4;
static const uint32_t XSTOP_XSTOP_IN05 = 5;
static const uint32_t XSTOP_XSTOP_IN06 = 6;
static const uint32_t XSTOP_XSTOP_IN07 = 7;
static const uint32_t XSTOP_XSTOP_IN08 = 8;
static const uint32_t XSTOP_XSTOP_IN09 = 9;
static const uint32_t XSTOP_XSTOP_IN10 = 10;
static const uint32_t XSTOP_XSTOP_IN11 = 11;
static const uint32_t XSTOP_XSTOP_IN12 = 12;
static const uint32_t XSTOP_XSTOP_IN13 = 13;
static const uint32_t XSTOP_XSTOP_IN14 = 14;
static const uint32_t XSTOP_XSTOP_IN15 = 15;
static const uint32_t XSTOP_XSTOP_IN16 = 16;
static const uint32_t XSTOP_XSTOP_IN17 = 17;
static const uint32_t XSTOP_XSTOP_IN18 = 18;
static const uint32_t XSTOP_XSTOP_IN19 = 19;
static const uint32_t XSTOP_XSTOP_IN20 = 20;
static const uint32_t XSTOP_XSTOP_IN21 = 21;
static const uint32_t XSTOP_XSTOP_IN22 = 22;
static const uint32_t XSTOP_XSTOP_IN23 = 23;
static const uint32_t XSTOP_XSTOP_IN24 = 24;
static const uint32_t XSTOP_XSTOP_IN25 = 25;
static const uint32_t XSTOP_XSTOP_IN26 = 26;
static const uint32_t XSTOP_XSTOP_IN27 = 27;
static const uint32_t XSTOP_XSTOP_IN28 = 28;
static const uint32_t XSTOP_XSTOP_IN29 = 29;
static const uint32_t XSTOP_XSTOP_IN30 = 30;
static const uint32_t XSTOP_XSTOP_IN31 = 31;
static const uint32_t XSTOP_XSTOP_IN32 = 32;
static const uint32_t XSTOP_XSTOP_IN33 = 33;
static const uint32_t XSTOP_XSTOP_IN34 = 34;
static const uint32_t XSTOP_XSTOP_IN35 = 35;
static const uint32_t XSTOP_XSTOP_IN36 = 36;
static const uint32_t XSTOP_XSTOP_IN37 = 37;
static const uint32_t XSTOP_XSTOP_IN38 = 38;
static const uint32_t XSTOP_XSTOP_IN39 = 39;
static const uint32_t XSTOP_XSTOP_IN40 = 40;
static const uint32_t XSTOP_XSTOP_IN41 = 41;
static const uint32_t XSTOP_XSTOP_IN42 = 42;
static const uint32_t XSTOP_XSTOP_IN43 = 43;
static const uint32_t XSTOP_XSTOP_IN44 = 44;
static const uint32_t XSTOP_XSTOP_IN45 = 45;
static const uint32_t XSTOP_XSTOP_IN46 = 46;
static const uint32_t XSTOP_XSTOP_IN47 = 47;
static const uint32_t XSTOP_XSTOP_IN48 = 48;
static const uint32_t XSTOP_XSTOP_IN49 = 49;
static const uint32_t XSTOP_XSTOP_IN50 = 50;
static const uint32_t XSTOP_XSTOP_IN51 = 51;
static const uint32_t XSTOP_XSTOP_IN52 = 52;
static const uint32_t XSTOP_XSTOP_IN53 = 53;
// mc/reg00009.H

}
}
#include "mc/reg00009.H"
#endif
