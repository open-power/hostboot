/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_3.H $         */
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

#ifndef __p10_scom_mc_3_H_
#define __p10_scom_mc_3_H_


namespace scomt
{
namespace mc
{


static const uint64_t CLOCK_STAT_NSL = 0x0c0303c9ull;

static const uint32_t CLOCK_STAT_NSL_PERV_NSL = 4;
static const uint32_t CLOCK_STAT_NSL_UNIT1_NSL = 5;
static const uint32_t CLOCK_STAT_NSL_UNIT2_NSL = 6;
static const uint32_t CLOCK_STAT_NSL_UNIT3_NSL = 7;
static const uint32_t CLOCK_STAT_NSL_UNIT4_NSL = 8;
static const uint32_t CLOCK_STAT_NSL_UNIT5_NSL = 9;
static const uint32_t CLOCK_STAT_NSL_UNIT6_NSL = 10;
static const uint32_t CLOCK_STAT_NSL_UNIT7_NSL = 11;
static const uint32_t CLOCK_STAT_NSL_UNIT8_NSL = 12;
static const uint32_t CLOCK_STAT_NSL_UNIT9_NSL = 13;
static const uint32_t CLOCK_STAT_NSL_UNIT10_NSL = 14;
static const uint32_t CLOCK_STAT_NSL_UNIT11_NSL = 15;
static const uint32_t CLOCK_STAT_NSL_UNIT12_NSL = 16;
static const uint32_t CLOCK_STAT_NSL_UNIT13_NSL = 17;
static const uint32_t CLOCK_STAT_NSL_UNIT14_NSL = 18;
// mc/reg00003.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT2 = 0x0c0503c2ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// mc/reg00003.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA1 = 0x0c0503daull;
// mc/reg00003.H

static const uint64_t EPS_THERM_WSUB_MODE_REG = 0x0c0503cfull;

static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR = 0;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT = 1;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA = 2;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN = 3;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA = 5;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT = 6;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN = 4;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA = 10;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN = 2;
static const uint32_t EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE = 12;
static const uint32_t EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL = 13;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK = 14;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL = 16;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN = 4;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 = 20;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN = 3;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 = 24;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN = 3;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 = 28;
// mc/reg00003.H

static const uint64_t LOCAL_XSTOP = 0x0c0403d8ull;

static const uint32_t LOCAL_XSTOP_ANY_LOCAL_XSTOP = 0;
static const uint32_t LOCAL_XSTOP_RESERVED1L = 1;
static const uint32_t LOCAL_XSTOP_RESERVED2L = 2;
static const uint32_t LOCAL_XSTOP_RESERVED3L = 3;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_PERV = 4;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN05 = 5;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN06 = 6;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN07 = 7;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN08 = 8;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN09 = 9;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN10 = 10;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN11 = 11;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN12 = 12;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN13 = 13;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN14 = 14;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN15 = 15;
// mc/reg00003.H

static const uint64_t LXSTOP_INTERRUPT_REG = 0x0c0f03eaull;
// mc/reg00003.H

static const uint64_t MBA_SCOMFIR_DBG0_SCOM1Q = 0x0c010fd5ull;

static const uint32_t MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87 = 0;
static const uint32_t MBA_SCOMFIR_DBG0_SCOM1Q_DEBUG_BUS_64_87_LEN = 24;
static const uint32_t MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED = 24;
static const uint32_t MBA_SCOMFIR_DBG0_SCOM1Q_RESERVED_LEN = 40;
// mc/reg00003.H

static const uint64_t MBA_SCOMFIR_DBGCFG0Q = 0x0c010fe8ull;

static const uint32_t MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_ENABLE = 0;
static const uint32_t MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01 = 1;
static const uint32_t MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT01_LEN = 11;
static const uint32_t MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23 = 12;
static const uint32_t MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_ASYNC_PORT23_LEN = 11;
static const uint32_t MBA_SCOMFIR_DBGCFG0Q_CFG_DBG_PICK_OMI = 23;
static const uint32_t MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44 = 24;
static const uint32_t MBA_SCOMFIR_DBGCFG0Q_RESERVED_24_44_LEN = 21;
static const uint32_t MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_TRIGGER = 45;
static const uint32_t MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_RESET = 46;
static const uint32_t MBA_SCOMFIR_DBGCFG0Q_SCOM_SET_WAT_EXT_ARM = 47;
// mc/reg00003.H

static const uint64_t MULTICAST_GROUP_1 = 0x0c0f03c1ull;

static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
// mc/reg00003.H

static const uint64_t NET_CTRL0_RWX = 0x0c0f03c0ull;
static const uint64_t NET_CTRL0_RWX_WAND = 0x0c0f03c1ull;
static const uint64_t NET_CTRL0_RWX_WOR = 0x0c0f03c2ull;

static const uint32_t NET_CTRL0_CHIPLET_ENABLE = 0;
static const uint32_t NET_CTRL0_PCB_EP_RESET = 1;
static const uint32_t NET_CTRL0_CLK_ASYNC_RESET = 2;
static const uint32_t NET_CTRL0_PLL_TEST_EN = 3;
static const uint32_t NET_CTRL0_PLL_RESET = 4;
static const uint32_t NET_CTRL0_PLL_BYPASS = 5;
static const uint32_t NET_CTRL0_VITAL_SCAN = 6;
static const uint32_t NET_CTRL0_VITAL_SCAN_IN = 7;
static const uint32_t NET_CTRL0_VITAL_PHASE = 8;
static const uint32_t NET_CTRL0_FLUSH_ALIGN_OVR = 9;
static const uint32_t NET_CTRL0_VITAL_AL = 10;
static const uint32_t NET_CTRL0_ACT_DIS = 11;
static const uint32_t NET_CTRL0_MPW1 = 12;
static const uint32_t NET_CTRL0_MPW2 = 13;
static const uint32_t NET_CTRL0_MPW3 = 14;
static const uint32_t NET_CTRL0_DELAY_LCLKR = 15;
static const uint32_t NET_CTRL0_VITAL_THOLD = 16;
static const uint32_t NET_CTRL0_FLUSH_SCAN_N = 17;
static const uint32_t NET_CTRL0_FENCE_EN = 18;
static const uint32_t NET_CTRL0_CPLT_RCTRL = 19;
static const uint32_t NET_CTRL0_CPLT_DCTRL = 20;
static const uint32_t NET_CTRL0_ADJ_FUNC_CLKSEL = 22;
static const uint32_t NET_CTRL0_TP_SRAM_ENABLE = 23;
static const uint32_t NET_CTRL0_TP_FENCE_PCB = 25;
static const uint32_t NET_CTRL0_LVLTRANS_FENCE = 26;
static const uint32_t NET_CTRL0_ARRAY_WRITE_ASSIST_EN = 27;
static const uint32_t NET_CTRL0_HTB_INTEST = 28;
static const uint32_t NET_CTRL0_HTB_EXTEST = 29;
static const uint32_t NET_CTRL0_PLLFORCE_OUT_EN = 31;
// mc/reg00003.H

static const uint64_t PHASE_COUNTER_RESET = 0x0c0303e8ull;

static const uint32_t PHASE_COUNTER_RESET_PHASECOUNTER_RESET = 0;
// mc/reg00003.H

static const uint64_t PLL_LOCK_REG = 0x0c0f03d9ull;
// mc/reg00003.H

static const uint64_t RFIR = 0x0c0403c1ull;

static const uint32_t RFIR_ANY_RECOV = 0;
static const uint32_t RFIR_RECOV_ANY_LOCAL_XSTOP = 1;
static const uint32_t RFIR_RESERVED2R = 2;
static const uint32_t RFIR_RESERVED3R = 3;
static const uint32_t RFIR_RECOV_PERV = 4;
static const uint32_t RFIR_RECOV_IN05 = 5;
static const uint32_t RFIR_RECOV_IN06 = 6;
static const uint32_t RFIR_RECOV_IN07 = 7;
static const uint32_t RFIR_RECOV_IN08 = 8;
static const uint32_t RFIR_RECOV_IN09 = 9;
static const uint32_t RFIR_RECOV_IN10 = 10;
static const uint32_t RFIR_RECOV_IN11 = 11;
static const uint32_t RFIR_RECOV_IN12 = 12;
static const uint32_t RFIR_RECOV_IN13 = 13;
static const uint32_t RFIR_RECOV_IN14 = 14;
static const uint32_t RFIR_RECOV_IN15 = 15;
static const uint32_t RFIR_RECOV_IN16 = 16;
static const uint32_t RFIR_RECOV_IN17 = 17;
static const uint32_t RFIR_RECOV_IN18 = 18;
static const uint32_t RFIR_RECOV_IN19 = 19;
static const uint32_t RFIR_RECOV_IN20 = 20;
static const uint32_t RFIR_RECOV_IN21 = 21;
static const uint32_t RFIR_RECOV_IN22 = 22;
static const uint32_t RFIR_RECOV_IN23 = 23;
static const uint32_t RFIR_RECOV_IN24 = 24;
static const uint32_t RFIR_RECOV_IN25 = 25;
static const uint32_t RFIR_RECOV_IN26 = 26;
static const uint32_t RFIR_RECOV_IN27 = 27;
static const uint32_t RFIR_RECOV_IN28 = 28;
static const uint32_t RFIR_RECOV_IN29 = 29;
static const uint32_t RFIR_RECOV_IN30 = 30;
static const uint32_t RFIR_RECOV_IN31 = 31;
static const uint32_t RFIR_RECOV_IN32 = 32;
static const uint32_t RFIR_RECOV_IN33 = 33;
static const uint32_t RFIR_RECOV_IN34 = 34;
static const uint32_t RFIR_RECOV_IN35 = 35;
static const uint32_t RFIR_RECOV_IN36 = 36;
static const uint32_t RFIR_RECOV_IN37 = 37;
static const uint32_t RFIR_RECOV_IN38 = 38;
static const uint32_t RFIR_RECOV_IN39 = 39;
static const uint32_t RFIR_RECOV_IN40 = 40;
static const uint32_t RFIR_RECOV_IN41 = 41;
static const uint32_t RFIR_RECOV_IN42 = 42;
static const uint32_t RFIR_RECOV_IN43 = 43;
static const uint32_t RFIR_RECOV_IN44 = 44;
static const uint32_t RFIR_RECOV_IN45 = 45;
static const uint32_t RFIR_RECOV_IN46 = 46;
static const uint32_t RFIR_RECOV_IN47 = 47;
static const uint32_t RFIR_RECOV_IN48 = 48;
static const uint32_t RFIR_RECOV_IN49 = 49;
static const uint32_t RFIR_RECOV_IN50 = 50;
static const uint32_t RFIR_RECOV_IN51 = 51;
static const uint32_t RFIR_RECOV_IN52 = 52;
static const uint32_t RFIR_RECOV_IN53 = 53;
// mc/reg00003.H

static const uint64_t SCOMFIR_MCERPT0 = 0x0c010fdeull;

static const uint32_t SCOMFIR_MCERPT0_AACR_PARITY_ERROR = 0;
static const uint32_t SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY0_PARITY_ERROR = 1;
static const uint32_t SCOMFIR_MCERPT0_CONTENT_ADDRESSABLE_MEMORY1_PARITY_ERROR = 2;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL0_CLSTATE_MACHINE_TIMEOUT_ERROR = 3;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL1_CLSTATE_MACHINE_TIMEOUT_ERROR = 4;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL0_CLAO_MACHINE_TIMEOUT_ERROR = 5;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL1_CLAO_MACHINE_TIMEOUT_ERROR = 6;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL0_MCAMOC_PARITY_ERROR = 9;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL0_MCBUSY_PARITY_ERROR = 10;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL0_MCEBUSCL_PARITY_ERROR = 11;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL0_MCEPS_PARITY_ERROR = 12;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL0_MCERRINJ_PARITY_ERROR = 13;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL0_MCPERF0_PARITY_ERROR = 14;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL0_MCPERF2_PARITY_ERROR = 15;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL0_MCWAT_PARITY_ERROR = 16;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL1_MCAMOC_PARITY_ERROR = 17;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL1_MCBUSY_PARITY_ERROR = 18;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL1_MCEBUSCL_PARITY_ERROR = 19;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL1_MCEPS_PARITY_ERROR = 20;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL1_MCERRINJ_PARITY_ERROR = 21;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL1_MCPERF0_PARITY_ERROR = 22;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL1_MCPERF2_PARITY_ERROR = 23;
static const uint32_t SCOMFIR_MCERPT0_CHANNEL1_MCWAT_PARITY_ERROR = 24;
static const uint32_t SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS0_ERROR = 29;
static const uint32_t SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL0_BUS1_ERROR = 30;
static const uint32_t SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS0_ERROR = 31;
static const uint32_t SCOMFIR_MCERPT0_DATAPATH_ROUTING_TAG_PARITY_CHANNEL1_BUS1_ERROR = 32;
static const uint32_t SCOMFIR_MCERPT0_FASTPATH_ADDRESS_PARITY_ERROR = 33;
static const uint32_t SCOMFIR_MCERPT0_MCFGP0_PARITY_ERROR = 38;
static const uint32_t SCOMFIR_MCERPT0_MCFGP1_PARITY_ERROR = 39;
static const uint32_t SCOMFIR_MCERPT0_MCFGPR0_PARITY_ERROR = 40;
static const uint32_t SCOMFIR_MCERPT0_MCFGPR1_PARITY_ERROR = 41;
static const uint32_t SCOMFIR_MCERPT0_MCLFSR_PARITY_ERROR = 42;
static const uint32_t SCOMFIR_MCERPT0_MCMODE0_PARITY_ERROR = 43;
static const uint32_t SCOMFIR_MCERPT0_MCMODE1_PARITY_ERROR = 44;
static const uint32_t SCOMFIR_MCERPT0_MCMODE2_PARITY_ERROR = 45;
static const uint32_t SCOMFIR_MCERPT0_MCPERF1_PARITY_ERROR = 46;
static const uint32_t SCOMFIR_MCERPT0_MCSYNC_PARITY_ERROR = 47;
static const uint32_t SCOMFIR_MCERPT0_MCWATACT_PARITY_ERROR = 48;
static const uint32_t SCOMFIR_MCERPT0_MCTO_PARITY_ERROR = 49;
static const uint32_t SCOMFIR_MCERPT0_RCMD0_ADDRESS_PARITY_ERROR_ON_CAR1 = 51;
static const uint32_t SCOMFIR_MCERPT0_RCMD0_TRANSFERTAG_PARITY_ERROR = 52;
static const uint32_t SCOMFIR_MCERPT0_RCMD1_ADDRESS_PARITY_ERROR_ON_CAR1 = 53;
static const uint32_t SCOMFIR_MCERPT0_RCMD1_TRANSFERTAG_PARITY_ERROR = 54;
static const uint32_t SCOMFIR_MCERPT0_RCMD2_ADDRESS_PARITY_ERROR_ON_CAR1 = 55;
static const uint32_t SCOMFIR_MCERPT0_RCMD2_TRANSFERTAG_PARITY_ERROR = 56;
static const uint32_t SCOMFIR_MCERPT0_RCMD3_ADDRESS_PARITY_ERROR_ON_CAR1 = 57;
static const uint32_t SCOMFIR_MCERPT0_RCMD3_TRANSFERTAG_PARITY_ERROR = 58;
static const uint32_t SCOMFIR_MCERPT0_MCFGPM0_PARITY_ERROR = 59;
static const uint32_t SCOMFIR_MCERPT0_MCFGPM1_PARITY_ERROR = 60;
static const uint32_t SCOMFIR_MCERPT0_MCWATCNTL2_PARITY_ERROR = 61;
// mc/reg00003.H

static const uint64_t SCOMFIR_MCWATCNTL2 = 0x0c010fd9ull;

static const uint32_t SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL0 = 0;
static const uint32_t SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL0_LEN = 7;
static const uint32_t SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL1 = 7;
static const uint32_t SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL1_LEN = 7;
static const uint32_t SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL2 = 14;
static const uint32_t SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL2_LEN = 7;
static const uint32_t SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL3 = 21;
static const uint32_t SCOMFIR_MCWATCNTL2_CFG_PBI_DBG_SEL3_LEN = 7;
static const uint32_t SCOMFIR_MCWATCNTL2_RESERVED_28_49 = 28;
static const uint32_t SCOMFIR_MCWATCNTL2_RESERVED_28_49_LEN = 22;
static const uint32_t SCOMFIR_MCWATCNTL2_CL_EARLY_HANG_MODE = 50;
// mc/reg00003.H

static const uint64_t SPATTN_MASK = 0x0c0403c7ull;

static const uint32_t SPATTN_MASK_01 = 1;
static const uint32_t SPATTN_MASK_02 = 2;
static const uint32_t SPATTN_MASK_03 = 3;
static const uint32_t SPATTN_MASK_04 = 4;
static const uint32_t SPATTN_MASK_05 = 5;
static const uint32_t SPATTN_MASK_06 = 6;
static const uint32_t SPATTN_MASK_07 = 7;
static const uint32_t SPATTN_MASK_08 = 8;
static const uint32_t SPATTN_MASK_09 = 9;
static const uint32_t SPATTN_MASK_10 = 10;
static const uint32_t SPATTN_MASK_11 = 11;
static const uint32_t SPATTN_MASK_12 = 12;
static const uint32_t SPATTN_MASK_13 = 13;
static const uint32_t SPATTN_MASK_14 = 14;
static const uint32_t SPATTN_MASK_15 = 15;
static const uint32_t SPATTN_MASK_16 = 16;
static const uint32_t SPATTN_MASK_17 = 17;
static const uint32_t SPATTN_MASK_18 = 18;
static const uint32_t SPATTN_MASK_19 = 19;
static const uint32_t SPATTN_MASK_20 = 20;
static const uint32_t SPATTN_MASK_21 = 21;
static const uint32_t SPATTN_MASK_22 = 22;
static const uint32_t SPATTN_MASK_23 = 23;
static const uint32_t SPATTN_MASK_24 = 24;
static const uint32_t SPATTN_MASK_25 = 25;
static const uint32_t SPATTN_MASK_26 = 26;
static const uint32_t SPATTN_MASK_27 = 27;
static const uint32_t SPATTN_MASK_28 = 28;
static const uint32_t SPATTN_MASK_29 = 29;
static const uint32_t SPATTN_MASK_30 = 30;
static const uint32_t SPATTN_MASK_31 = 31;
static const uint32_t SPATTN_MASK_32 = 32;
static const uint32_t SPATTN_MASK_33 = 33;
static const uint32_t SPATTN_MASK_34 = 34;
static const uint32_t SPATTN_MASK_35 = 35;
// mc/reg00003.H

static const uint64_t TRA0_TR0_CONFIG_3 = 0x0c0107c6ull;

static const uint32_t TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TRA0_TR0_CONFIG_3_D_LEN = 24;
// mc/reg00003.H

}
}
#include "mc/reg00003.H"
#endif
