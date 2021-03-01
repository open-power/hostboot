/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_9.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __p10_scom_perv_9_H_
#define __p10_scom_perv_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> [CPLT_CTRL4]
static const uint64_t CPLT_CTRL4_RW = 0x00000004ull;
static const uint64_t CPLT_CTRL4_WO_CLEAR = 0x00000024ull;
static const uint64_t CPLT_CTRL4_WO_OR = 0x00000014ull;

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
// perv/reg00018.H

//>> [EPS_THERM_WSUB_DTS_RESULT1]
static const uint64_t EPS_THERM_WSUB_DTS_RESULT1 = 0x00050001ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
//<< [EPS_THERM_WSUB_DTS_RESULT1]
// perv/reg00018.H

//>> [FSXCOMP_FSXLOG_CBS_ENVSTAT]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI = 0x00002804ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE = 0x00002810ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_RO = 0x00050004ull;

static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_TEST_ENABLE = 0;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CARD_TEST_BSC = 1;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_VDN_PGOOD = 2;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_FSI_IN_ENA = 3;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_CHIP_MASTER = 4;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_SMD = 5;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_C4_JTAG_TMS = 6;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER = 7;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_REMAINDER_LEN = 17;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC = 24;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MAJOR_EC_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC = 28;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CBS_ENVSTAT_MINOR_EC_LEN = 4;
//<< [FSXCOMP_FSXLOG_CBS_ENVSTAT]
// perv/reg00018.H

//>> [FSXCOMP_FSXLOG_PERV_CTRL1_COPY]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI = 0x0000291bull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE = 0x00002c6cull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW = 0x0005011bull;

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG = 0;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_COPY_PERV_CTRL1_COPY_REG_LEN = 32;
//<< [FSXCOMP_FSXLOG_PERV_CTRL1_COPY]
// perv/reg00018.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI = 0x00002937ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE = 0x00002cdcull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR = 0x00050137ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL = 24;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP_DRVR_2X_CUR_EN_DC = 24; // p10:20,
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL = 25;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_E0A_DRVR_2X_CUR_EN_DC = 25; // p10:20,
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL = 26;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_E0B_DRVR_2X_CUR_EN_DC = 26; // p10:20,
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL = 27;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_E0C_DRVR_2X_CUR_EN_DC = 27; // p10:20,
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL = 28;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_E1A_DRVR_2X_CUR_EN_DC = 28; // p10:20,
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL = 29;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_E1B_DRVR_2X_CUR_EN_DC = 29; // p10:20,
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL = 30;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_E1C_DRVR_2X_CUR_EN_DC = 30; // p10:20,
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR]
// perv/reg00018.H

//>> [FSXCOMP_FSXLOG_SCRATCH_REGISTER_8]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI = 0x0000283full;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE = 0x000028fcull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW = 0x0005003full;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8_LEN = 32;
//<< [FSXCOMP_FSXLOG_SCRATCH_REGISTER_8]
// perv/reg00018.H

//>> [TOD_TRACE_DATA_1_REG]
static const uint64_t TOD_TRACE_DATA_1_REG = 0x0004001dull;

static const uint32_t TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1 = 0;
static const uint32_t TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1_LEN = 64;
//<< [TOD_TRACE_DATA_1_REG]
// perv/reg00019.H

//>> [TOD_TRACE_DATA_2_REG]
static const uint64_t TOD_TRACE_DATA_2_REG = 0x0004001eull;

static const uint32_t TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2 = 0;
static const uint32_t TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2_LEN = 64;
//<< [TOD_TRACE_DATA_2_REG]
// perv/reg00019.H

//>> [TOD_TRACE_DATA_3_REG]
static const uint64_t TOD_TRACE_DATA_3_REG = 0x0004001full;

static const uint32_t TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3 = 0;
static const uint32_t TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3_LEN = 64;
//<< [TOD_TRACE_DATA_3_REG]
// perv/reg00019.H

//>> [XSTOP]
static const uint64_t XSTOP = 0x00040000ull;

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
// perv/reg00019.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00018.H"
#include "perv/reg00019.H"
#endif
#endif
