/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_3.H $        */
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

#ifndef __p10_scom_pec_3_H_
#define __p10_scom_pec_3_H_


namespace scomt
{
namespace pec
{


static const uint64_t CLOCK_STAT_NSL = 0x08030009ull;

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
// pec/reg00003.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT2 = 0x08050002ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// pec/reg00003.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA1 = 0x0805001aull;
// pec/reg00003.H

static const uint64_t EPS_THERM_WSUB_MODE_REG = 0x0805000full;

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
// pec/reg00003.H

static const uint64_t LOCAL_XSTOP = 0x08040018ull;

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
// pec/reg00003.H

static const uint64_t LXSTOP_INTERRUPT_REG = 0x080f002aull;
// pec/reg00003.H

static const uint64_t MULTICAST_GROUP_1 = 0x080f0001ull;

static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
// pec/reg00003.H

static const uint64_t NET_CTRL0_RWX = 0x080f0040ull;
static const uint64_t NET_CTRL0_RWX_WAND = 0x080f0041ull;
static const uint64_t NET_CTRL0_RWX_WOR = 0x080f0042ull;

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
// pec/reg00003.H

static const uint64_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG = 0x03011810ull;

static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_ENABLE = 0;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_TYPE = 1;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_DISABLE_SCOPE = 2;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE = 6;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_VALUE_LEN = 2;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT = 8;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_OUTSTANDING_COUNT_LEN = 2;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE = 10;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_MAX_CRESP_ATAG_VALUE_LEN = 2;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE = 12;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_CRESP_ATAG_DELTA_VALUE_LEN = 2;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT = 14;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SAMPLE_RANGE_COUNT_LEN = 10;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA = 24;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_RATE_CHANGE_DELTA_LEN = 4;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA = 28;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_RATE_CHANGE_DELTA_LEN = 4;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE = 32;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_DECREMENT_RATE_LEN = 8;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE = 40;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_GROUP_MINIMUM_DECREMENT_RATE_LEN = 8;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE = 48;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_DECREMENT_RATE_LEN = 8;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE = 56;
static const uint32_t PB_PBCQ_PEPBREGS_PE_INJECT_THRESHOLD_REG_SYSTEM_MINIMUM_DECREMENT_RATE_LEN = 8;
// pec/reg00003.H

static const uint64_t PHASE_COUNTER_RESET = 0x08030028ull;

static const uint32_t PHASE_COUNTER_RESET_PHASECOUNTER_RESET = 0;
// pec/reg00003.H

static const uint64_t PLL_LOCK_REG = 0x080f0019ull;
// pec/reg00003.H

static const uint64_t RFIR = 0x08040001ull;

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
// pec/reg00003.H

static const uint64_t SPATTN_MASK = 0x08040007ull;

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
// pec/reg00003.H

static const uint64_t TRA0_TR0_CONFIG_3 = 0x08010406ull;

static const uint32_t TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TRA0_TR0_CONFIG_3_D_LEN = 24;
// pec/reg00003.H

}
}
#include "pec/reg00003.H"
#endif
