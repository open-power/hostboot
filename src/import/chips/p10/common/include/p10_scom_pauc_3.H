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

#include "proc_scomt.H"

#ifndef __p10_scom_pauc_3_H_
#define __p10_scom_pauc_3_H_


namespace scomt
{
namespace pauc
{


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

static const uint64_t LOCAL_XSTOP = 0x10040018ull;

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
// pauc/reg00003.H

static const uint64_t LXSTOP_INTERRUPT_REG = 0x100f002aull;
// pauc/reg00003.H

static const uint64_t MULTICAST_GROUP_1 = 0x100f0001ull;

static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
// pauc/reg00003.H

static const uint64_t NET_CTRL0_RWX = 0x100f0040ull;
static const uint64_t NET_CTRL0_RWX_WAND = 0x100f0041ull;
static const uint64_t NET_CTRL0_RWX_WOR = 0x100f0042ull;

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
// pauc/reg00003.H

static const uint64_t PB_MAILBOX_DATA_REG = 0x1001182full;
// pauc/reg00003.H

static const uint64_t PB_PMU0_CNPM_COUNTER = 0x10011821ull;
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

static const uint64_t PLL_LOCK_REG = 0x100f0019ull;
// pauc/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t REGS_TX_IMPCAL2_PB = 0x800f0c001000003full;
// pauc/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t REGS_TX_IMPCAL_SWO6_PB = 0x800f5c001000003full;

static const uint32_t REGS_TX_IMPCAL_SWO6_PB_TX_ZCAL_SWO_IMP_CNTL_1R_1XP_0_15 = 48;
static const uint32_t REGS_TX_IMPCAL_SWO6_PB_TX_ZCAL_SWO_IMP_CNTL_1R_1XP_0_15_LEN = 16;
// pauc/reg00003.H

static const uint64_t RFIR = 0x10040001ull;

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
// pauc/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t SCOM_PPE_FLAGS_RWX = 0x10000023ull;
static const uint64_t SCOM_PPE_FLAGS_WOX_CLEAR = 0x10000025ull;
static const uint64_t SCOM_PPE_FLAGS_WOX_OR = 0x10000024ull;

static const uint32_t SCOM_PPE_FLAGS_SCOM_PPE_FLAGS_FIELD = 0;
static const uint32_t SCOM_PPE_FLAGS_SCOM_PPE_FLAGS_FIELD_LEN = 16;
// pauc/reg00003.H

static const uint64_t SPATTN_MASK = 0x10040007ull;

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

}
}
#include "pauc/reg00003.H"
#endif
