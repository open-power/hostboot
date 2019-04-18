/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_3.H $       */
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

#ifndef __p10_scom_iohs_3_H_
#define __p10_scom_iohs_3_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_BIST = 0x1803000bull;

static const uint32_t AXON_BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t AXON_BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t AXON_BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t AXON_BIST_BIST_PERV = 4;
static const uint32_t AXON_BIST_BIST_UNIT1 = 5;
static const uint32_t AXON_BIST_BIST_UNIT2 = 6;
static const uint32_t AXON_BIST_BIST_UNIT3 = 7;
static const uint32_t AXON_BIST_BIST_UNIT4 = 8;
static const uint32_t AXON_BIST_BIST_UNIT5 = 9;
static const uint32_t AXON_BIST_BIST_UNIT6 = 10;
static const uint32_t AXON_BIST_BIST_UNIT7 = 11;
static const uint32_t AXON_BIST_BIST_UNIT8 = 12;
static const uint32_t AXON_BIST_BIST_UNIT9 = 13;
static const uint32_t AXON_BIST_BIST_UNIT10 = 14;
static const uint32_t AXON_BIST_BIST_UNIT11 = 15;
static const uint32_t AXON_BIST_BIST_UNIT12 = 16;
static const uint32_t AXON_BIST_BIST_UNIT13 = 17;
static const uint32_t AXON_BIST_BIST_UNIT14 = 18;
static const uint32_t AXON_BIST_BIST_STROBE_WINDOW_EN = 48;
// iohs/reg00035.H

static const uint64_t AXON_CLOCK_STAT_ARY = 0x1803000aull;

static const uint32_t AXON_CLOCK_STAT_ARY_PERV_ARY = 4;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT1_ARY = 5;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT2_ARY = 6;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT3_ARY = 7;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT4_ARY = 8;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT5_ARY = 9;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT6_ARY = 10;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT7_ARY = 11;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT8_ARY = 12;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT9_ARY = 13;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT10_ARY = 14;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT11_ARY = 15;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT12_ARY = 16;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT13_ARY = 17;
static const uint32_t AXON_CLOCK_STAT_ARY_UNIT14_ARY = 18;
// iohs/reg00035.H

static const uint64_t AXON_CLOCK_STAT_SL = 0x18030008ull;

static const uint32_t AXON_CLOCK_STAT_SL_PERV_SL = 4;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT1_SL = 5;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT2_SL = 6;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT3_SL = 7;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT4_SL = 8;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT5_SL = 9;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT6_SL = 10;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT7_SL = 11;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT8_SL = 12;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT9_SL = 13;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT10_SL = 14;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT11_SL = 15;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT12_SL = 16;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT13_SL = 17;
static const uint32_t AXON_CLOCK_STAT_SL_UNIT14_SL = 18;
// iohs/reg00035.H

static const uint64_t AXON_EPS_FIR_MODE_REG = 0x18040008ull;

static const uint32_t AXON_EPS_FIR_MODE_REG_00 = 0;
static const uint32_t AXON_EPS_FIR_MODE_REG_01 = 1;
static const uint32_t AXON_EPS_FIR_MODE_REG_02 = 2;
static const uint32_t AXON_EPS_FIR_MODE_REG_03 = 3;
static const uint32_t AXON_EPS_FIR_MODE_REG_04 = 4;
static const uint32_t AXON_EPS_FIR_MODE_REG_05 = 5;
static const uint32_t AXON_EPS_FIR_MODE_REG_06 = 6;
static const uint32_t AXON_EPS_FIR_MODE_REG_07 = 7;
static const uint32_t AXON_EPS_FIR_MODE_REG_08 = 8;
static const uint32_t AXON_EPS_FIR_MODE_REG_09 = 9;
static const uint32_t AXON_EPS_FIR_MODE_REG_10 = 10;
static const uint32_t AXON_EPS_FIR_MODE_REG_11 = 11;
static const uint32_t AXON_EPS_FIR_MODE_REG_12 = 12;
static const uint32_t AXON_EPS_FIR_MODE_REG_13 = 13;
static const uint32_t AXON_EPS_FIR_MODE_REG_14 = 14;
static const uint32_t AXON_EPS_FIR_MODE_REG_15 = 15;
// iohs/reg00035.H

static const uint64_t AXON_EPS_PSC_PSCOM_MODE_REG = 0x18010000ull;

static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR = 0;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR = 1;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR = 3;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE = 4;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT = 5;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN = 2;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS = 7;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE = 8;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT = 9;
static const uint32_t AXON_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN = 3;
// iohs/reg00035.H

static const uint64_t AXON_OPCG_CAPT1 = 0x18030010ull;

static const uint32_t AXON_OPCG_CAPT1_COUNT = 0;
static const uint32_t AXON_OPCG_CAPT1_COUNT_LEN = 4;
static const uint32_t AXON_OPCG_CAPT1_SEQ_01 = 4;
static const uint32_t AXON_OPCG_CAPT1_SEQ_01_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_02 = 9;
static const uint32_t AXON_OPCG_CAPT1_SEQ_02_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_03 = 14;
static const uint32_t AXON_OPCG_CAPT1_SEQ_03_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_04 = 19;
static const uint32_t AXON_OPCG_CAPT1_SEQ_04_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_05 = 24;
static const uint32_t AXON_OPCG_CAPT1_SEQ_05_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_06 = 29;
static const uint32_t AXON_OPCG_CAPT1_SEQ_06_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_07 = 34;
static const uint32_t AXON_OPCG_CAPT1_SEQ_07_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_08 = 39;
static const uint32_t AXON_OPCG_CAPT1_SEQ_08_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_09 = 44;
static const uint32_t AXON_OPCG_CAPT1_SEQ_09_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_10 = 49;
static const uint32_t AXON_OPCG_CAPT1_SEQ_10_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_11 = 54;
static const uint32_t AXON_OPCG_CAPT1_SEQ_11_LEN = 5;
static const uint32_t AXON_OPCG_CAPT1_SEQ_12 = 59;
static const uint32_t AXON_OPCG_CAPT1_SEQ_12_LEN = 5;
// iohs/reg00035.H

static const uint64_t AXON_TRA0_TR0_TRACE_HI_DATA_REG = 0x18010400ull;

static const uint32_t AXON_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t AXON_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// iohs/reg00035.H

static const uint64_t AXON_TRA0_TR0_CONFIG_4 = 0x18010407ull;

static const uint32_t AXON_TRA0_TR0_CONFIG_4_A = 0;
static const uint32_t AXON_TRA0_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t AXON_TRA0_TR0_CONFIG_4_B = 24;
static const uint32_t AXON_TRA0_TR0_CONFIG_4_B_LEN = 24;
// iohs/reg00035.H

static const uint64_t LXSTOP_INTERRUPT_REG = 0x180f002aull;
// iohs/reg00035.H

static const uint64_t MULTICAST_GROUP_1 = 0x180f0001ull;

static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
// iohs/reg00035.H

static const uint64_t NET_CTRL0_RWX = 0x180f0040ull;
static const uint64_t NET_CTRL0_RWX_WAND = 0x180f0041ull;
static const uint64_t NET_CTRL0_RWX_WOR = 0x180f0042ull;

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
// iohs/reg00035.H

static const uint64_t PLL_LOCK_REG = 0x180f0019ull;
// iohs/reg00035.H

}
}
#include "iohs/reg00035.H"
#endif
