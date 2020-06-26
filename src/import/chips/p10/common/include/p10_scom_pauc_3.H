/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_3.H $       */
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

#ifndef __p10_scom_pauc_3_H_
#define __p10_scom_pauc_3_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
{
#endif


//>> [CLOCK_STAT_NSL]
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
//<< [CLOCK_STAT_NSL]
// pauc/reg00003.H

//>> [EPS_THERM_WSUB_DTS_RESULT2]
static const uint64_t EPS_THERM_WSUB_DTS_RESULT2 = 0x10050002ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
//<< [EPS_THERM_WSUB_DTS_RESULT2]
// pauc/reg00003.H

//>> [EPS_THERM_WSUB_MODE_REG]
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
//<< [EPS_THERM_WSUB_MODE_REG]
// pauc/reg00003.H

//>> [NET_CTRL0]
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
//<< [NET_CTRL0]
// pauc/reg00003.H

//>> [PHY_PPE_WRAP_ARB_CSDR]
static const uint64_t PHY_PPE_WRAP_ARB_CSDR = 0x10012c0eull;

static const uint32_t PHY_PPE_WRAP_ARB_CSDR_CSDR_SRAM_DATA = 0;
static const uint32_t PHY_PPE_WRAP_ARB_CSDR_CSDR_SRAM_DATA_LEN = 64;
//<< [PHY_PPE_WRAP_ARB_CSDR]
// pauc/reg00003.H

//>> [PLL_LOCK_REG]
static const uint64_t PLL_LOCK_REG = 0x100f0019ull;

static const uint32_t PLL_LOCK_REG_LOCK = 0;
static const uint32_t PLL_LOCK_REG_LOCK_LEN = 8;
//<< [PLL_LOCK_REG]
// pauc/reg00003.H

//>> [MULTICAST_GROUP_1]
static const uint64_t MULTICAST_GROUP_1 = 0x100f0001ull;

static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
//<< [MULTICAST_GROUP_1]
// pauc/reg00003.H

//>> [SPATTN_MASK]
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
//<< [SPATTN_MASK]
// pauc/reg00003.H

//>> [LOCAL_XSTOP]
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
//<< [LOCAL_XSTOP]
// pauc/reg00003.H

//>> [PB_FM0123_ERR]
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
//<< [PB_FM0123_ERR]
// pauc/reg00003.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pauc/reg00003.H"
#endif
#endif
