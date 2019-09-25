/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_3.H $       */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_pauc_3_H_
#define __p10_scom_pauc_3_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
{
#endif


static const uint64_t CLOCK_STAT_NSL = 0x10030009ull;

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
// pauc/reg00003.H

static const uint64_t DL_PPE_WRAP_ARB_CSDR = 0x10012c4eull;

static const uint32_t DL_PPE_WRAP_ARB_CSDR_CSDR_SRAM_DATA = 0;
static const uint32_t DL_PPE_WRAP_ARB_CSDR_CSDR_SRAM_DATA_LEN = 64;
// pauc/reg00003.H

static const uint64_t DL_PPE_WRAP_XIDBGINF = 0x10012c5full;

static const uint32_t DL_PPE_WRAP_XIDBGINF_SRR0 = 0;
static const uint32_t DL_PPE_WRAP_XIDBGINF_SRR0_LEN = 30;
static const uint32_t DL_PPE_WRAP_XIDBGINF_LR = 32;
static const uint32_t DL_PPE_WRAP_XIDBGINF_LR_LEN = 32;
// pauc/reg00003.H

static const uint64_t EPS_FIR_ANY_LOCAL_ERR_MASK = 0x10040080ull;

static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_XSTOP_TO_PCB = 0;
static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_RECOV_TO_PCB = 1;
static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_SPATTN_TO_PCB = 2;
static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_LOCAL_XSTOP_TO_PCB = 3;
static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_HOSTATTN_TO_PCB = 4;
// pauc/reg00003.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT2 = 0x10050002ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// pauc/reg00003.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA1 = 0x1005001aull;
// pauc/reg00003.H

static const uint64_t EPS_THERM_WSUB_MODE_REG = 0x1005000full;

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
// pauc/reg00003.H

static const uint64_t LOCAL_XSTOP = 0x10040003ull;

static const uint32_t LOCAL_XSTOP_ANY_LOCAL_XSTOP = 0;
static const uint32_t LOCAL_XSTOP_RESERVED1L = 1;
static const uint32_t LOCAL_XSTOP_RESERVED2L = 2;
static const uint32_t LOCAL_XSTOP_RESERVED3L = 3;
static const uint32_t LOCAL_XSTOP_PERV = 4;
static const uint32_t LOCAL_XSTOP_IN05 = 5;
static const uint32_t LOCAL_XSTOP_IN06 = 6;
static const uint32_t LOCAL_XSTOP_IN07 = 7;
static const uint32_t LOCAL_XSTOP_IN08 = 8;
static const uint32_t LOCAL_XSTOP_IN09 = 9;
static const uint32_t LOCAL_XSTOP_IN10 = 10;
static const uint32_t LOCAL_XSTOP_IN11 = 11;
static const uint32_t LOCAL_XSTOP_IN12 = 12;
static const uint32_t LOCAL_XSTOP_IN13 = 13;
static const uint32_t LOCAL_XSTOP_IN14 = 14;
static const uint32_t LOCAL_XSTOP_IN15 = 15;
// pauc/reg00003.H

static const uint64_t LXSTOP_INTERRUPT_REG = 0x100f002aull;

static const uint32_t LXSTOP_INTERRUPT_REG_LXSTOP = 0;
// pauc/reg00003.H

static const uint64_t MULTICAST_GROUP_1 = 0x100f0001ull;

static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
// pauc/reg00003.H

static const uint64_t NET_CTRL0_RW = 0x100f0040ull;
static const uint64_t NET_CTRL0_RW_WAND = 0x100f0041ull;
static const uint64_t NET_CTRL0_RW_WOR = 0x100f0042ull;

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
static const uint32_t NET_CTRL0_TOADMODE_EN = 12;
static const uint32_t NET_CTRL0_SYNC_PULSE = 13;
static const uint32_t NET_CTRL0_MPW3 = 14;
static const uint32_t NET_CTRL0_DELAY_LCLKR = 15;
static const uint32_t NET_CTRL0_VITAL_THOLD = 16;
static const uint32_t NET_CTRL0_FLUSH_SCAN_N = 17;
static const uint32_t NET_CTRL0_FENCE_EN = 18;
static const uint32_t NET_CTRL0_CPLT_RCTRL = 19;
static const uint32_t NET_CTRL0_CPLT_DCTRL = 20;
static const uint32_t NET_CTRL0_CPLT_RCTRL2 = 21;
static const uint32_t NET_CTRL0_ADJ_FUNC_CLKSEL = 22;
static const uint32_t NET_CTRL0_PM_ACCESS = 23;
static const uint32_t NET_CTRL0_FUNC_LCB_EDIS = 24;
static const uint32_t NET_CTRL0_TP_FENCE_PCB = 25;
static const uint32_t NET_CTRL0_LVLTRANS_FENCE = 26;
static const uint32_t NET_CTRL0_ARRAY_WRITE_ASSIST_EN = 27;
static const uint32_t NET_CTRL0_HTB_INTEST = 28;
static const uint32_t NET_CTRL0_HTB_EXTEST = 29;
// ERROR Duplicate Dial         static const uint32_t NET_CTRL0_PM_ACCESS = 30;
static const uint32_t NET_CTRL0_PLLFORCE_OUT_EN = 31;
// pauc/reg00003.H

static const uint64_t PB_CFG_CNPM_REG = 0x1001181full;

static const uint32_t PB_CFG_CNPM_REG_EN = 0;
static const uint32_t PB_CFG_CNPM_REG_RESET_MODE = 1;
static const uint32_t PB_CFG_CNPM_REG_COUNTER_MODE = 2;
static const uint32_t PB_CFG_CNPM_REG_GLOBAL_PMISC_DIS = 3;
static const uint32_t PB_CFG_CNPM_REG_GLOBAL_PMISC_MODE = 4;
static const uint32_t PB_CFG_CNPM_REG_EXTERNAL_FREEZE = 5;
static const uint32_t PB_CFG_CNPM_REG_0_1_OP = 6;
static const uint32_t PB_CFG_CNPM_REG_0_1_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_2_3_OP = 8;
static const uint32_t PB_CFG_CNPM_REG_2_3_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_4_5_OP = 10;
static const uint32_t PB_CFG_CNPM_REG_4_5_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_6_7_OP = 12;
static const uint32_t PB_CFG_CNPM_REG_6_7_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_8_9_OP = 14;
static const uint32_t PB_CFG_CNPM_REG_8_9_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_10_11_OP = 16;
static const uint32_t PB_CFG_CNPM_REG_10_11_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_12_13_OP = 18;
static const uint32_t PB_CFG_CNPM_REG_12_13_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_14_15_OP = 20;
static const uint32_t PB_CFG_CNPM_REG_14_15_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_16_17_OP = 22;
static const uint32_t PB_CFG_CNPM_REG_16_17_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_18_19_OP = 24;
static const uint32_t PB_CFG_CNPM_REG_18_19_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_20_21_OP = 26;
static const uint32_t PB_CFG_CNPM_REG_20_21_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_22_23_OP = 28;
static const uint32_t PB_CFG_CNPM_REG_22_23_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_24_25_OP = 30;
static const uint32_t PB_CFG_CNPM_REG_24_25_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_26_27_OP = 32;
static const uint32_t PB_CFG_CNPM_REG_26_27_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_28_29_OP = 34;
static const uint32_t PB_CFG_CNPM_REG_28_29_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_30_31_OP = 36;
static const uint32_t PB_CFG_CNPM_REG_30_31_OP_LEN = 2;
static const uint32_t PB_CFG_CNPM_REG_CASCADE_PMU0 = 38;
static const uint32_t PB_CFG_CNPM_REG_CASCADE_PMU0_LEN = 3;
static const uint32_t PB_CFG_CNPM_REG_CASCADE_PMU1 = 41;
static const uint32_t PB_CFG_CNPM_REG_CASCADE_PMU1_LEN = 3;
static const uint32_t PB_CFG_CNPM_REG_CASCADE_PMU2 = 44;
static const uint32_t PB_CFG_CNPM_REG_CASCADE_PMU2_LEN = 3;
static const uint32_t PB_CFG_CNPM_REG_CASCADE_PMU3 = 47;
static const uint32_t PB_CFG_CNPM_REG_CASCADE_PMU3_LEN = 3;
static const uint32_t PB_CFG_CNPM_REG_SPARE = 50;
static const uint32_t PB_CFG_CNPM_REG_SPARE_LEN = 6;
// pauc/reg00003.H

static const uint64_t PB_FM0123_ERR = 0x10011827ull;

static const uint32_t PB_FM0123_ERR_0_CONTROL_ERROR = 0;
static const uint32_t PB_FM0123_ERR_0_ADDR_PERR = 1;
static const uint32_t PB_FM0123_ERR_0_CC0_CREDITERR = 2;
static const uint32_t PB_FM0123_ERR_0_CC1_CREDITERR = 3;
static const uint32_t PB_FM0123_ERR_0_CC2_CREDITERR = 4;
static const uint32_t PB_FM0123_ERR_0_CC3_CREDITERR = 5;
static const uint32_t PB_FM0123_ERR_0_DAT_HI_PERR = 6;
static const uint32_t PB_FM0123_ERR_0_DAT_LO_PERR = 7;
static const uint32_t PB_FM0123_ERR_0_FRAME_CREDITERR = 8;
static const uint32_t PB_FM0123_ERR_0_INTERNAL_ERR = 9;
static const uint32_t PB_FM0123_ERR_0_PRSP_PTYERR = 10;
static const uint32_t PB_FM0123_ERR_0_TTAG_PERR = 11;
static const uint32_t PB_FM0123_ERR_0_VC0_CREDITERR = 12;
static const uint32_t PB_FM0123_ERR_0_VC1_CREDITERR = 13;
static const uint32_t PB_FM0123_ERR_0_RTAG_PTYERR = 14;
static const uint32_t PB_FM0123_ERR_0_RTAG_MISC_PTY = 15;
static const uint32_t PB_FM0123_ERR_1_CONTROL_ERROR = 16;
static const uint32_t PB_FM0123_ERR_1_ADDR_PERR = 17;
static const uint32_t PB_FM0123_ERR_1_CC0_CREDITERR = 18;
static const uint32_t PB_FM0123_ERR_1_CC1_CREDITERR = 19;
static const uint32_t PB_FM0123_ERR_1_CC2_CREDITERR = 20;
static const uint32_t PB_FM0123_ERR_1_CC3_CREDITERR = 21;
static const uint32_t PB_FM0123_ERR_1_DAT_HI_PERR = 22;
static const uint32_t PB_FM0123_ERR_1_DAT_LO_PERR = 23;
static const uint32_t PB_FM0123_ERR_1_FRAME_CREDITERR = 24;
static const uint32_t PB_FM0123_ERR_1_INTERNAL_ERR = 25;
static const uint32_t PB_FM0123_ERR_1_PRSP_PTYERR = 26;
static const uint32_t PB_FM0123_ERR_1_TTAG_PERR = 27;
static const uint32_t PB_FM0123_ERR_1_VC0_CREDITERR = 28;
static const uint32_t PB_FM0123_ERR_1_VC1_CREDITERR = 29;
static const uint32_t PB_FM0123_ERR_1_RTAG_PTYERR = 30;
static const uint32_t PB_FM0123_ERR_1_RTAG_MISC_PTY = 31;
static const uint32_t PB_FM0123_ERR_2_CONTROL_ERROR = 32;
static const uint32_t PB_FM0123_ERR_2_ADDR_PERR = 33;
static const uint32_t PB_FM0123_ERR_2_CC0_CREDITERR = 34;
static const uint32_t PB_FM0123_ERR_2_CC1_CREDITERR = 35;
static const uint32_t PB_FM0123_ERR_2_CC2_CREDITERR = 36;
static const uint32_t PB_FM0123_ERR_2_CC3_CREDITERR = 37;
static const uint32_t PB_FM0123_ERR_2_DAT_HI_PERR = 38;
static const uint32_t PB_FM0123_ERR_2_DAT_LO_PERR = 39;
static const uint32_t PB_FM0123_ERR_2_FRAME_CREDITERR = 40;
static const uint32_t PB_FM0123_ERR_2_INTERNAL_ERR = 41;
static const uint32_t PB_FM0123_ERR_2_PRSP_PTYERR = 42;
static const uint32_t PB_FM0123_ERR_2_TTAG_PERR = 43;
static const uint32_t PB_FM0123_ERR_2_VC0_CREDITERR = 44;
static const uint32_t PB_FM0123_ERR_2_VC1_CREDITERR = 45;
static const uint32_t PB_FM0123_ERR_2_RTAG_PTYERR = 46;
static const uint32_t PB_FM0123_ERR_2_RTAG_MISC_PTY = 47;
static const uint32_t PB_FM0123_ERR_3_CONTROL_ERROR = 48;
static const uint32_t PB_FM0123_ERR_3_ADDR_PERR = 49;
static const uint32_t PB_FM0123_ERR_3_CC0_CREDITERR = 50;
static const uint32_t PB_FM0123_ERR_3_CC1_CREDITERR = 51;
static const uint32_t PB_FM0123_ERR_3_CC2_CREDITERR = 52;
static const uint32_t PB_FM0123_ERR_3_CC3_CREDITERR = 53;
static const uint32_t PB_FM0123_ERR_3_DAT_HI_PERR = 54;
static const uint32_t PB_FM0123_ERR_3_DAT_LO_PERR = 55;
static const uint32_t PB_FM0123_ERR_3_FRAME_CREDITERR = 56;
static const uint32_t PB_FM0123_ERR_3_INTERNAL_ERR = 57;
static const uint32_t PB_FM0123_ERR_3_PRSP_PTYERR = 58;
static const uint32_t PB_FM0123_ERR_3_TTAG_PERR = 59;
static const uint32_t PB_FM0123_ERR_3_VC0_CREDITERR = 60;
static const uint32_t PB_FM0123_ERR_3_VC1_CREDITERR = 61;
static const uint32_t PB_FM0123_ERR_3_RTAG_PTYERR = 62;
static const uint32_t PB_FM0123_ERR_3_RTAG_MISC_PTY = 63;
// pauc/reg00003.H

static const uint64_t PB_MAILBOX_DATA_REG = 0x1001182full;
// pauc/reg00003.H

static const uint64_t PB_PMU0_CNPM_COUNTER = 0x10011821ull;

static const uint32_t PB_PMU0_CNPM_COUNTER_0 = 0;
static const uint32_t PB_PMU0_CNPM_COUNTER_0_LEN = 16;
static const uint32_t PB_PMU0_CNPM_COUNTER_1 = 16;
static const uint32_t PB_PMU0_CNPM_COUNTER_1_LEN = 16;
static const uint32_t PB_PMU0_CNPM_COUNTER_2 = 32;
static const uint32_t PB_PMU0_CNPM_COUNTER_2_LEN = 16;
static const uint32_t PB_PMU0_CNPM_COUNTER_3 = 48;
static const uint32_t PB_PMU0_CNPM_COUNTER_3_LEN = 16;
// pauc/reg00003.H

static const uint64_t PB_TL_LINK_DATA_01_CFG_REG = 0x10011810ull;

static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_0 = 0;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT = 1;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC0_LIMIT_LEN = 7;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_1 = 8;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT = 9;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_LINK01_DOB_VC1_LIMIT_LEN = 7;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT = 16;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_LINK01_HI_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT = 24;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_LINK01_LO_BACKOFF_LIMIT_LEN = 8;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT = 32;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_VC_LIMIT_LEN = 5;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_LINK01_DIB_RTAG_DATA_ASY_LIMIT = 37;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2 = 38;
static const uint32_t PB_TL_LINK_DATA_01_CFG_REG_DIBDOB01_SP_2_LEN = 2;
// pauc/reg00003.H

static const uint64_t PHASE_COUNTER_RESET = 0x10030028ull;

static const uint32_t PHASE_COUNTER_RESET_PHASECOUNTER_RESET = 0;
// pauc/reg00003.H

static const uint64_t PHY_PPE_WRAP_ARB_CSDR = 0x10012c0eull;

static const uint32_t PHY_PPE_WRAP_ARB_CSDR_CSDR_SRAM_DATA = 0;
static const uint32_t PHY_PPE_WRAP_ARB_CSDR_CSDR_SRAM_DATA_LEN = 64;
// pauc/reg00003.H

static const uint64_t PHY_PPE_WRAP_MIB_XISGB = 0x10012c18ull;

static const uint32_t PHY_PPE_WRAP_MIB_XISGB_SGB_STORE_ADDRESS = 0;
static const uint32_t PHY_PPE_WRAP_MIB_XISGB_SGB_STORE_ADDRESS_LEN = 32;
static const uint32_t PHY_PPE_WRAP_MIB_XISGB_MEM_IMPRECISE_ERROR_PENDING = 35;
static const uint32_t PHY_PPE_WRAP_MIB_XISGB_SGB_BYTE_VALID = 36;
static const uint32_t PHY_PPE_WRAP_MIB_XISGB_SGB_BYTE_VALID_LEN = 4;
static const uint32_t PHY_PPE_WRAP_MIB_XISGB_SGB_FLUSH_PENDING = 63;
// pauc/reg00003.H

static const uint64_t PHY_PPE_WRAP_SCOM_WORK_REG1 = 0x10012c21ull;

static const uint32_t PHY_PPE_WRAP_SCOM_WORK_REG1_SCOM_PPE_WORK1 = 0;
static const uint32_t PHY_PPE_WRAP_SCOM_WORK_REG1_SCOM_PPE_WORK1_LEN = 32;
// pauc/reg00003.H

static const uint64_t PLL_LOCK_REG = 0x100f0019ull;

static const uint32_t PLL_LOCK_REG_LOCK = 0;
static const uint32_t PLL_LOCK_REG_LOCK_LEN = 8;
// pauc/reg00003.H

static const uint64_t SPATTN_MASK_RW = 0x10040042ull;
static const uint64_t SPATTN_MASK_WO_CLEAR = 0x10040062ull;
static const uint64_t SPATTN_MASK_WO_OR = 0x10040052ull;

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
// pauc/reg00003.H

static const uint64_t TRA0_TR0_CONFIG_3 = 0x10010406ull;

static const uint32_t TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TRA0_TR0_CONFIG_3_D_LEN = 24;
// pauc/reg00003.H

static const uint64_t TXIRLM_REGS_SPARE_MODE_PB = 0x800f7c0010012c3full;

static const uint32_t TXIRLM_REGS_SPARE_MODE_PB_0 = 48;
static const uint32_t TXIRLM_REGS_SPARE_MODE_PB_1 = 49;
static const uint32_t TXIRLM_REGS_SPARE_MODE_PB_2 = 50;
static const uint32_t TXIRLM_REGS_SPARE_MODE_PB_3 = 51;
static const uint32_t TXIRLM_REGS_SPARE_MODE_PB_4 = 52;
static const uint32_t TXIRLM_REGS_SPARE_MODE_PB_5 = 53;
static const uint32_t TXIRLM_REGS_SPARE_MODE_PB_6 = 54;
static const uint32_t TXIRLM_REGS_SPARE_MODE_PB_7 = 55;
// pauc/reg00003.H

static const uint64_t TXIRLM_REGS_TX_IMPCAL_SWO7_PB = 0x800f640010012c3full;

static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO7_PB_TX_ZCAL_SWO_IMP_CNTL_1R_1XP_16_31 = 48;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO7_PB_TX_ZCAL_SWO_IMP_CNTL_1R_1XP_16_31_LEN = 16;
// pauc/reg00003.H

#ifndef __PPE_HCODE__
}
}
#include "pauc/reg00003.H"
#endif
#endif
