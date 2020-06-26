/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_9.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_pauc_9_H_
#define __p10_scom_pauc_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
{
#endif


//>> [CPLT_CTRL4]
static const uint64_t CPLT_CTRL4_RW = 0x10000004ull;
static const uint64_t CPLT_CTRL4_WO_CLEAR = 0x10000024ull;
static const uint64_t CPLT_CTRL4_WO_OR = 0x10000014ull;

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
//<< [CPLT_CTRL4]
// pauc/reg00009.H

//>> [EPS_THERM_WSUB_DTS_RESULT1]
static const uint64_t EPS_THERM_WSUB_DTS_RESULT1 = 0x10050001ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
//<< [EPS_THERM_WSUB_DTS_RESULT1]
// pauc/reg00009.H

//>> [XSTOP]
static const uint64_t XSTOP = 0x10040000ull;

static const uint32_t XSTOP_ANY_XSTOP = 0;
static const uint32_t XSTOP_SYSTEM_XSTOP = 1;
static const uint32_t XSTOP_ANY_SPATTN = 2;
static const uint32_t XSTOP_DBG_FIR_XSTOP_ON_TRIG = 3;
static const uint32_t XSTOP_PERV = 4;
static const uint32_t XSTOP_IN05 = 5;
static const uint32_t XSTOP_IN06 = 6;
static const uint32_t XSTOP_IN07 = 7;
static const uint32_t XSTOP_IN08 = 8;
static const uint32_t XSTOP_IN09 = 9;
static const uint32_t XSTOP_IN10 = 10;
static const uint32_t XSTOP_IN11 = 11;
static const uint32_t XSTOP_IN12 = 12;
static const uint32_t XSTOP_IN13 = 13;
static const uint32_t XSTOP_IN14 = 14;
static const uint32_t XSTOP_IN15 = 15;
static const uint32_t XSTOP_IN16 = 16;
static const uint32_t XSTOP_IN17 = 17;
static const uint32_t XSTOP_IN18 = 18;
static const uint32_t XSTOP_IN19 = 19;
static const uint32_t XSTOP_IN20 = 20;
static const uint32_t XSTOP_IN21 = 21;
static const uint32_t XSTOP_IN22 = 22;
static const uint32_t XSTOP_IN23 = 23;
static const uint32_t XSTOP_IN24 = 24;
static const uint32_t XSTOP_IN25 = 25;
static const uint32_t XSTOP_IN26 = 26;
static const uint32_t XSTOP_IN27 = 27;
static const uint32_t XSTOP_IN28 = 28;
static const uint32_t XSTOP_IN29 = 29;
static const uint32_t XSTOP_IN30 = 30;
static const uint32_t XSTOP_IN31 = 31;
static const uint32_t XSTOP_IN32 = 32;
static const uint32_t XSTOP_IN33 = 33;
static const uint32_t XSTOP_IN34 = 34;
static const uint32_t XSTOP_IN35 = 35;
static const uint32_t XSTOP_IN36 = 36;
static const uint32_t XSTOP_IN37 = 37;
static const uint32_t XSTOP_IN38 = 38;
static const uint32_t XSTOP_IN39 = 39;
static const uint32_t XSTOP_IN40 = 40;
static const uint32_t XSTOP_IN41 = 41;
static const uint32_t XSTOP_IN42 = 42;
static const uint32_t XSTOP_IN43 = 43;
static const uint32_t XSTOP_IN44 = 44;
static const uint32_t XSTOP_IN45 = 45;
static const uint32_t XSTOP_IN46 = 46;
static const uint32_t XSTOP_IN47 = 47;
static const uint32_t XSTOP_IN48 = 48;
static const uint32_t XSTOP_IN49 = 49;
static const uint32_t XSTOP_IN50 = 50;
static const uint32_t XSTOP_IN51 = 51;
static const uint32_t XSTOP_IN52 = 52;
static const uint32_t XSTOP_IN53 = 53;
//<< [XSTOP]
// pauc/reg00009.H

//>> [PB_PSAVE01_MODE_CFG]
static const uint64_t PB_PSAVE01_MODE_CFG = 0x10011814ull;

static const uint32_t PB_PSAVE01_MODE_CFG_MODE = 0;
static const uint32_t PB_PSAVE01_MODE_CFG_MODE_LEN = 2;
static const uint32_t PB_PSAVE01_MODE_CFG_WIDTH = 2;
static const uint32_t PB_PSAVE01_MODE_CFG_WIDTH_LEN = 3;
static const uint32_t PB_PSAVE01_MODE_CFG_SPARE = 5;
static const uint32_t PB_PSAVE01_MODE_CFG_SPARE_LEN = 3;
static const uint32_t PB_PSAVE01_MODE_CFG_MIN_RAND_UC = 8;
static const uint32_t PB_PSAVE01_MODE_CFG_MIN_RAND_UC_LEN = 8;
//<< [PB_PSAVE01_MODE_CFG]
// pauc/reg00009.H

//>> [PB_MISC_CFG]
static const uint64_t PB_MISC_CFG = 0x10011825ull;

static const uint32_t PB_MISC_CFG_SCOM_PTLX0_ENABLE = 0;
static const uint32_t PB_MISC_CFG_SCOM_PTLX1_ENABLE = 1;
static const uint32_t PB_MISC_CFG_SCOM_PTLY0_ENABLE = 2;
static const uint32_t PB_MISC_CFG_SCOM_PTLY1_ENABLE = 3;
static const uint32_t PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR = 4;
static const uint32_t PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR = 5;
static const uint32_t PB_MISC_CFG_SCOM_PTLX_RESET_KEEPER = 6;
static const uint32_t PB_MISC_CFG_SCOM_PTLY_RESET_KEEPER = 7;
static const uint32_t PB_MISC_CFG_TRANSPORT_0_ENABLE = 8;
static const uint32_t PB_MISC_CFG_TRANSPORT_1_ENABLE = 9;
static const uint32_t PB_MISC_CFG_TRANSPORT_2_ENABLE = 10;
static const uint32_t PB_MISC_CFG_TRANSPORT_3_ENABLE = 11;
static const uint32_t PB_MISC_CFG_TRANSPORT_0_IB_MUX_CTL0 = 12;
static const uint32_t PB_MISC_CFG_TRANSPORT_PAU0_EVN_IB_MUX_EN = 13;
static const uint32_t PB_MISC_CFG_TRANSPORT_1_IB_MUX_CTL0 = 14;
static const uint32_t PB_MISC_CFG_TRANSPORT_PAU0_ODD_IB_MUX_EN = 15;
static const uint32_t PB_MISC_CFG_TRANSPORT_2_IB_MUX_CTL0 = 16;
static const uint32_t PB_MISC_CFG_TRANSPORT_PAU1_EVN_IB_MUX_EN = 17;
static const uint32_t PB_MISC_CFG_TRANSPORT_3_IB_MUX_CTL0 = 18;
static const uint32_t PB_MISC_CFG_TRANSPORT_PAU1_ODD_IB_MUX_EN = 19;
static const uint32_t PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL0 = 20;
static const uint32_t PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL1 = 21;
static const uint32_t PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL2 = 22;
static const uint32_t PB_MISC_CFG_TRANSPORT_0_OB_MUX_CTL3 = 23;
static const uint32_t PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL0 = 24;
static const uint32_t PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL1 = 25;
static const uint32_t PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL2 = 26;
static const uint32_t PB_MISC_CFG_TRANSPORT_1_OB_MUX_CTL3 = 27;
static const uint32_t PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL0 = 28;
static const uint32_t PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL1 = 29;
static const uint32_t PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL2 = 30;
static const uint32_t PB_MISC_CFG_TRANSPORT_2_OB_MUX_CTL3 = 31;
static const uint32_t PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL0 = 32;
static const uint32_t PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL1 = 33;
static const uint32_t PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL2 = 34;
static const uint32_t PB_MISC_CFG_TRANSPORT_3_OB_MUX_CTL3 = 35;
static const uint32_t PB_MISC_CFG_SCOM_PTLX_EMULATION_MODE = 36;
static const uint32_t PB_MISC_CFG_SCOM_PTLY_EMULATION_MODE = 37;
static const uint32_t PB_MISC_CFG_TRANSPORT_PRI_BUS_CTL = 38;
static const uint32_t PB_MISC_CFG_ENABLE_DEGRADED_MODE = 39;
static const uint32_t PB_MISC_CFG_HW517132_DISABLE = 40;
static const uint32_t PB_MISC_CFG_MISC_SPARE = 41;
static const uint32_t PB_MISC_CFG_MISC_SPARE_LEN = 11;
//<< [PB_MISC_CFG]
// pauc/reg00009.H

//>> [PB_FP01_CFG]
static const uint64_t PB_FP01_CFG = 0x1001180aull;

static const uint32_t PB_FP01_CFG_0_CREDIT_PRIORITY_4_NOT_8 = 0;
static const uint32_t PB_FP01_CFG_0_DISABLE_GATHERING = 1;
static const uint32_t PB_FP01_CFG_0_DISABLE_CMD_COMPRESSION = 2;
static const uint32_t PB_FP01_CFG_0_DISABLE_PRSP_COMPRESSION = 3;
static const uint32_t PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT = 4;
static const uint32_t PB_FP01_CFG_0_LL_CREDIT_FW_LIMIT_LEN = 6;
static const uint32_t PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT = 10;
static const uint32_t PB_FP01_CFG_0_LL_CREDIT_HW_LIMIT_LEN = 6;
static const uint32_t PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT = 16;
static const uint32_t PB_FP01_CFG_0_LL_CREDIT_QW_LIMIT_LEN = 4;
static const uint32_t PB_FP01_CFG_0_FMR_ENABLE_1PER4_PRESP = 20;
static const uint32_t PB_FP01_CFG_01_CMD_EXP_TIME = 21;
static const uint32_t PB_FP01_CFG_01_CMD_EXP_TIME_LEN = 3;
static const uint32_t PB_FP01_CFG_0_RUN_AFTER_FRAME_ERROR = 24;
static const uint32_t PB_FP01_CFG_0_BRICKWALL_CREDITS_TO_NEST = 25;
static const uint32_t PB_FP01_CFG_0_PRS_SPARE = 26;
static const uint32_t PB_FP01_CFG_0_PRS_SPARE_LEN = 6;
static const uint32_t PB_FP01_CFG_1_CREDIT_PRIORITY_4_NOT_8 = 32;
static const uint32_t PB_FP01_CFG_1_DISABLE_GATHERING = 33;
static const uint32_t PB_FP01_CFG_1_DISABLE_CMD_COMPRESSION = 34;
static const uint32_t PB_FP01_CFG_1_DISABLE_PRSP_COMPRESSION = 35;
static const uint32_t PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT = 36;
static const uint32_t PB_FP01_CFG_1_LL_CREDIT_FW_LIMIT_LEN = 6;
static const uint32_t PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT = 42;
static const uint32_t PB_FP01_CFG_1_LL_CREDIT_HW_LIMIT_LEN = 6;
static const uint32_t PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT = 48;
static const uint32_t PB_FP01_CFG_1_LL_CREDIT_QW_LIMIT_LEN = 4;
static const uint32_t PB_FP01_CFG_1_FMR_ENABLE_1PER4_PRESP = 52;
static const uint32_t PB_FP01_CFG_1_FMR_SPARE = 53;
static const uint32_t PB_FP01_CFG_1_FMR_SPARE_LEN = 3;
static const uint32_t PB_FP01_CFG_1_RUN_AFTER_FRAME_ERROR = 56;
static const uint32_t PB_FP01_CFG_1_BRICKWALL_CREDITS_TO_NEST = 57;
static const uint32_t PB_FP01_CFG_1_PRS_SPARE = 58;
static const uint32_t PB_FP01_CFG_1_PRS_SPARE_LEN = 6;
//<< [PB_FP01_CFG]
// pauc/reg00009.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pauc/reg00009.H"
#endif
#endif
