/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc.H $           */
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

#ifndef __mc_H_
#define __mc_H_


namespace scomt
{
namespace mc
{


static const uint64_t ASSIST_INTERRUPT_REG = 0x0c0f0011ull;
// mc/reg00000.H

static const uint64_t ATOMIC_LOCK_REG = 0x0c0f03ffull;

static const uint32_t ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t ATOMIC_LOCK_REG_ID = 1;
static const uint32_t ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// mc/reg00000.H

static const uint64_t ATTN_INTERRUPT_REG = 0x0c0f001aull;
// mc/reg00000.H

static const uint64_t BIST = 0x0c03000bull;

static const uint32_t BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t BIST_UNUSED_BC2 = 2;
static const uint32_t BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t BIST_BIST_PERV = 4;
static const uint32_t BIST_BIST_UNIT1 = 5;
static const uint32_t BIST_BIST_UNIT2 = 6;
static const uint32_t BIST_BIST_UNIT3 = 7;
static const uint32_t BIST_BIST_UNIT4 = 8;
static const uint32_t BIST_BIST_UNIT5 = 9;
static const uint32_t BIST_BIST_UNIT6 = 10;
static const uint32_t BIST_BIST_UNIT7 = 11;
static const uint32_t BIST_BIST_UNIT8 = 12;
static const uint32_t BIST_BIST_UNIT9 = 13;
static const uint32_t BIST_BIST_UNIT10 = 14;
static const uint32_t BIST_BIST_UNIT11 = 15;
static const uint32_t BIST_BIST_UNIT12 = 16;
static const uint32_t BIST_BIST_UNIT13 = 17;
static const uint32_t BIST_BIST_UNIT14 = 18;
static const uint32_t BIST_BIST_STROBE_WINDOW_EN = 48;
// mc/reg00000.H

static const uint64_t CC_ATOMIC_LOCK_REG = 0x0c0303ffull;

static const uint32_t CC_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CC_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CC_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CC_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CC_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// mc/reg00000.H

static const uint64_t CC_PROTECT_MODE_REG = 0x0c0303feull;

static const uint32_t CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// mc/reg00000.H

static const uint64_t CLK_REGION = 0x0c030006ull;

static const uint32_t CLK_REGION_CLOCK_CMD = 0;
static const uint32_t CLK_REGION_CLOCK_CMD_LEN = 2;
static const uint32_t CLK_REGION_SLAVE_MODE = 2;
static const uint32_t CLK_REGION_MASTER_MODE = 3;
static const uint32_t CLK_REGION_CLOCK_REGION_PERV = 4;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT1 = 5;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT2 = 6;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT3 = 7;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT4 = 8;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT5 = 9;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT6 = 10;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT7 = 11;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT8 = 12;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT9 = 13;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT10 = 14;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT11 = 15;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT12 = 16;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT13 = 17;
static const uint32_t CLK_REGION_CLOCK_REGION_UNIT14 = 18;
static const uint32_t CLK_REGION_SEL_THOLD_SL = 48;
static const uint32_t CLK_REGION_SEL_THOLD_NSL = 49;
static const uint32_t CLK_REGION_SEL_THOLD_ARY = 50;
static const uint32_t CLK_REGION_CLOCK_PULSE_USE_EVEN = 52;
static const uint32_t CLK_REGION_CLOCK_START_RUNN_SUPPR_FIRST_CLK = 53;
static const uint32_t CLK_REGION_CLOCK_STOP_RUNN_SUPPR_LAST_CLK = 54;
// mc/reg00000.H

static const uint64_t CLOCK_STAT_ARY = 0x0c03000aull;

static const uint32_t CLOCK_STAT_ARY_PERV_ARY = 4;
static const uint32_t CLOCK_STAT_ARY_UNIT1_ARY = 5;
static const uint32_t CLOCK_STAT_ARY_UNIT2_ARY = 6;
static const uint32_t CLOCK_STAT_ARY_UNIT3_ARY = 7;
static const uint32_t CLOCK_STAT_ARY_UNIT4_ARY = 8;
static const uint32_t CLOCK_STAT_ARY_UNIT5_ARY = 9;
static const uint32_t CLOCK_STAT_ARY_UNIT6_ARY = 10;
static const uint32_t CLOCK_STAT_ARY_UNIT7_ARY = 11;
static const uint32_t CLOCK_STAT_ARY_UNIT8_ARY = 12;
static const uint32_t CLOCK_STAT_ARY_UNIT9_ARY = 13;
static const uint32_t CLOCK_STAT_ARY_UNIT10_ARY = 14;
static const uint32_t CLOCK_STAT_ARY_UNIT11_ARY = 15;
static const uint32_t CLOCK_STAT_ARY_UNIT12_ARY = 16;
static const uint32_t CLOCK_STAT_ARY_UNIT13_ARY = 17;
static const uint32_t CLOCK_STAT_ARY_UNIT14_ARY = 18;
// mc/reg00000.H

static const uint64_t CLOCK_STAT_NSL = 0x0c030009ull;

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
// mc/reg00000.H

static const uint64_t CLOCK_STAT_SL = 0x0c030008ull;

static const uint32_t CLOCK_STAT_SL_PERV_SL = 4;
static const uint32_t CLOCK_STAT_SL_UNIT1_SL = 5;
static const uint32_t CLOCK_STAT_SL_UNIT2_SL = 6;
static const uint32_t CLOCK_STAT_SL_UNIT3_SL = 7;
static const uint32_t CLOCK_STAT_SL_UNIT4_SL = 8;
static const uint32_t CLOCK_STAT_SL_UNIT5_SL = 9;
static const uint32_t CLOCK_STAT_SL_UNIT6_SL = 10;
static const uint32_t CLOCK_STAT_SL_UNIT7_SL = 11;
static const uint32_t CLOCK_STAT_SL_UNIT8_SL = 12;
static const uint32_t CLOCK_STAT_SL_UNIT9_SL = 13;
static const uint32_t CLOCK_STAT_SL_UNIT10_SL = 14;
static const uint32_t CLOCK_STAT_SL_UNIT11_SL = 15;
static const uint32_t CLOCK_STAT_SL_UNIT12_SL = 16;
static const uint32_t CLOCK_STAT_SL_UNIT13_SL = 17;
static const uint32_t CLOCK_STAT_SL_UNIT14_SL = 18;
// mc/reg00000.H

static const uint64_t CPLT_CONF0_RW = 0x0c000008ull;
static const uint64_t CPLT_CONF0_WO_CLEAR = 0x0c000028ull;
static const uint64_t CPLT_CONF0_WO_OR = 0x0c000018ull;

static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC = 0;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE0_SEL_DC_LEN = 6;
static const uint32_t CPLT_CONF0_RESERVED_6G = 6;
static const uint32_t CPLT_CONF0_RESERVED_7G = 7;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC = 8;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE1_SEL_DC_LEN = 6;
static const uint32_t CPLT_CONF0_RESERVED_14G = 14;
static const uint32_t CPLT_CONF0_RESERVED_15G = 15;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC = 16;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE2_SEL_DC_LEN = 6;
static const uint32_t CPLT_CONF0_RESERVED_22G = 22;
static const uint32_t CPLT_CONF0_RESERVED_23G = 23;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC = 24;
static const uint32_t CPLT_CONF0_CTRL_MISC_PROBE3_SEL_DC_LEN = 6;
static const uint32_t CPLT_CONF0_RESERVED_30G = 30;
static const uint32_t CPLT_CONF0_RESERVED_31G = 31;
static const uint32_t CPLT_CONF0_CTRL_MISC_OFLOW_FEH_SEL_DC = 32;
static const uint32_t CPLT_CONF0_CTRL_CC_SCAN_PROTECT_DC = 33;
static const uint32_t CPLT_CONF0_CTRL_CC_SDIS_DC_N = 34;
static const uint32_t CPLT_CONF0_CTRL_CC_SCAN_DIAG_DC = 35;
static const uint32_t CPLT_CONF0_RESERVED_TEST_CONTROL_36G = 36;
static const uint32_t CPLT_CONF0_RESERVED_TEST_CONTROL_37G = 37;
static const uint32_t CPLT_CONF0_RESERVED_TEST_CONTROL_38G = 38;
static const uint32_t CPLT_CONF0_RESERVED_TEST_CONTROL_39G = 39;
static const uint32_t CPLT_CONF0_CTRL_EPS_MASK_VITL_PCB_ERR_DC = 40;
static const uint32_t CPLT_CONF0_CTRL_CC_MASK_VITL_SCAN_OPCG_ERR_DC = 41;
static const uint32_t CPLT_CONF0_RESERVED_42G = 42;
static const uint32_t CPLT_CONF0_RESERVED_43G = 43;
static const uint32_t CPLT_CONF0_TC_PCB_DBG_GLB_BRCST_EN = 44;
static const uint32_t CPLT_CONF0_RESERVED_45G = 45;
static const uint32_t CPLT_CONF0_FREE_USAGE_46G = 46;
static const uint32_t CPLT_CONF0_FREE_USAGE_47G = 47;
static const uint32_t CPLT_CONF0_FREE_USAGE_48G = 48;
static const uint32_t CPLT_CONF0_FREE_USAGE_49G = 49;
static const uint32_t CPLT_CONF0_FREE_USAGE_50G = 50;
static const uint32_t CPLT_CONF0_FREE_USAGE_51G = 51;
static const uint32_t CPLT_CONF0_FREE_USAGE_52G = 52;
static const uint32_t CPLT_CONF0_FREE_USAGE_53G = 53;
static const uint32_t CPLT_CONF0_FREE_USAGE_54G = 54;
static const uint32_t CPLT_CONF0_FREE_USAGE_55G = 55;
static const uint32_t CPLT_CONF0_FREE_USAGE_56G = 56;
static const uint32_t CPLT_CONF0_FREE_USAGE_57G = 57;
static const uint32_t CPLT_CONF0_FREE_USAGE_58G = 58;
static const uint32_t CPLT_CONF0_FREE_USAGE_59G = 59;
static const uint32_t CPLT_CONF0_FREE_USAGE_60G = 60;
static const uint32_t CPLT_CONF0_FREE_USAGE_61G = 61;
static const uint32_t CPLT_CONF0_FREE_USAGE_62G = 62;
static const uint32_t CPLT_CONF0_FREE_USAGE_63G = 63;
// mc/reg00000.H

static const uint64_t CPLT_CONF1_RW = 0x0c000009ull;
static const uint64_t CPLT_CONF1_WO_CLEAR = 0x0c000029ull;
static const uint64_t CPLT_CONF1_WO_OR = 0x0c000019ull;

static const uint32_t CPLT_CONF1_0H = 0;
static const uint32_t CPLT_CONF1_1H = 1;
static const uint32_t CPLT_CONF1_2H = 2;
static const uint32_t CPLT_CONF1_3H = 3;
static const uint32_t CPLT_CONF1_4H = 4;
static const uint32_t CPLT_CONF1_5H = 5;
static const uint32_t CPLT_CONF1_6H = 6;
static const uint32_t CPLT_CONF1_7H = 7;
static const uint32_t CPLT_CONF1_8H = 8;
static const uint32_t CPLT_CONF1_9H = 9;
static const uint32_t CPLT_CONF1_10H = 10;
static const uint32_t CPLT_CONF1_11H = 11;
static const uint32_t CPLT_CONF1_12H = 12;
static const uint32_t CPLT_CONF1_13H = 13;
static const uint32_t CPLT_CONF1_14H = 14;
static const uint32_t CPLT_CONF1_15H = 15;
static const uint32_t CPLT_CONF1_16H = 16;
static const uint32_t CPLT_CONF1_17H = 17;
static const uint32_t CPLT_CONF1_18H = 18;
static const uint32_t CPLT_CONF1_19H = 19;
static const uint32_t CPLT_CONF1_20H = 20;
static const uint32_t CPLT_CONF1_21H = 21;
static const uint32_t CPLT_CONF1_22H = 22;
static const uint32_t CPLT_CONF1_23H = 23;
static const uint32_t CPLT_CONF1_24H = 24;
static const uint32_t CPLT_CONF1_25H = 25;
static const uint32_t CPLT_CONF1_26H = 26;
static const uint32_t CPLT_CONF1_27H = 27;
static const uint32_t CPLT_CONF1_28H = 28;
static const uint32_t CPLT_CONF1_29H = 29;
static const uint32_t CPLT_CONF1_30H = 30;
static const uint32_t CPLT_CONF1_31H = 31;
// mc/reg00000.H

static const uint64_t CPLT_CTRL0_RW = 0x0c000000ull;
static const uint64_t CPLT_CTRL0_WO_CLEAR = 0x0c000020ull;
static const uint64_t CPLT_CTRL0_WO_OR = 0x0c000010ull;

static const uint32_t CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC = 0;
static const uint32_t CPLT_CTRL0_TC_UNIT_SYNCCLK_MUXSEL_DC = 1;
static const uint32_t CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH = 2;
static const uint32_t CPLT_CTRL0_CTRL_CC_FORCE_ALIGN = 3;
static const uint32_t CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC = 4;
static const uint32_t CPLT_CTRL0_UNUSED_5A = 5;
static const uint32_t CPLT_CTRL0_UNUSED_6A = 6;
static const uint32_t CPLT_CTRL0_UNUSED_7A = 7;
static const uint32_t CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC = 8;
static const uint32_t CPLT_CTRL0_UNUSED_9A = 9;
static const uint32_t CPLT_CTRL0_UNUSED_10A = 10;
static const uint32_t CPLT_CTRL0_RESERVED_11A = 11;
static const uint32_t CPLT_CTRL0_TC_SKIT_MODE_BIST_DC = 12;
static const uint32_t CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC = 13;
static const uint32_t CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC = 14;
static const uint32_t CPLT_CTRL0_TC_UNIT_RRFA_TEST_ENA_DC = 15;
static const uint32_t CPLT_CTRL0_UNUSED_16A = 16;
static const uint32_t CPLT_CTRL0_UNUSED_17A = 17;
static const uint32_t CPLT_CTRL0_RESERVED_18A = 18;
static const uint32_t CPLT_CTRL0_RESERVED_19A = 19;
static const uint32_t CPLT_CTRL0_TC_PSRO_SEL_DC = 20;
static const uint32_t CPLT_CTRL0_TC_PSRO_SEL_DC_LEN = 8;
static const uint32_t CPLT_CTRL0_TC_BSC_WRAPSEL_DC = 28;
static const uint32_t CPLT_CTRL0_TC_BSC_INTMODE_DC = 29;
static const uint32_t CPLT_CTRL0_TC_BSC_INV_DC = 30;
static const uint32_t CPLT_CTRL0_TC_BSC_EXTMODE_DC = 31;
static const uint32_t CPLT_CTRL0_UNUSED_32A = 32;
static const uint32_t CPLT_CTRL0_RESERVED_33A = 33;
static const uint32_t CPLT_CTRL0_RESERVED_34A = 34;
static const uint32_t CPLT_CTRL0_RESERVED_35A = 35;
static const uint32_t CPLT_CTRL0_RESERVED_36A = 36;
static const uint32_t CPLT_CTRL0_RESERVED_37A = 37;
static const uint32_t CPLT_CTRL0_RESERVED_38A = 38;
static const uint32_t CPLT_CTRL0_RESERVED_39A = 39;
static const uint32_t CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC = 40;
static const uint32_t CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN = 2;
static const uint32_t CPLT_CTRL0_RESERVED_42A = 42;
static const uint32_t CPLT_CTRL0_RESERVED_43A = 43;
static const uint32_t CPLT_CTRL0_UNUSED_44A = 44;
static const uint32_t CPLT_CTRL0_UNUSED_45A = 45;
static const uint32_t CPLT_CTRL0_UNUSED_46A = 46;
static const uint32_t CPLT_CTRL0_CTRL_CC_PIN_LBIST_DC = 47;
static const uint32_t CPLT_CTRL0_FREE_USAGE_48A = 48;
static const uint32_t CPLT_CTRL0_FREE_USAGE_49A = 49;
static const uint32_t CPLT_CTRL0_FREE_USAGE_50A = 50;
static const uint32_t CPLT_CTRL0_FREE_USAGE_51A = 51;
static const uint32_t CPLT_CTRL0_FREE_USAGE_52A = 52;
static const uint32_t CPLT_CTRL0_FREE_USAGE_53A = 53;
static const uint32_t CPLT_CTRL0_FREE_USAGE_54A = 54;
static const uint32_t CPLT_CTRL0_FREE_USAGE_55A = 55;
static const uint32_t CPLT_CTRL0_FREE_USAGE_56A = 56;
static const uint32_t CPLT_CTRL0_FREE_USAGE_57A = 57;
static const uint32_t CPLT_CTRL0_FREE_USAGE_58A = 58;
static const uint32_t CPLT_CTRL0_FREE_USAGE_59A = 59;
static const uint32_t CPLT_CTRL0_FREE_USAGE_60A = 60;
static const uint32_t CPLT_CTRL0_FREE_USAGE_61A = 61;
static const uint32_t CPLT_CTRL0_FREE_USAGE_62A = 62;
static const uint32_t CPLT_CTRL0_FREE_USAGE_63A = 63;
// mc/reg00000.H

static const uint64_t CPLT_CTRL1_RW = 0x0c000001ull;
static const uint64_t CPLT_CTRL1_WO_CLEAR = 0x0c000021ull;
static const uint64_t CPLT_CTRL1_WO_OR = 0x0c000011ull;

static const uint32_t CPLT_CTRL1_TC_UNIT_MULTICYCLE_TEST_FENCE_DC = 0;
static const uint32_t CPLT_CTRL1_UNUSED_1B = 1;
static const uint32_t CPLT_CTRL1_UNUSED_2B = 2;
static const uint32_t CPLT_CTRL1_TC_VITL_FENCE_DC = 3;
static const uint32_t CPLT_CTRL1_TC_REGION0_FENCE_DC = 4;
static const uint32_t CPLT_CTRL1_TC_REGION1_FENCE_DC = 5;
static const uint32_t CPLT_CTRL1_TC_REGION2_FENCE_DC = 6;
static const uint32_t CPLT_CTRL1_TC_REGION3_FENCE_DC = 7;
static const uint32_t CPLT_CTRL1_TC_REGION4_FENCE_DC = 8;
static const uint32_t CPLT_CTRL1_TC_REGION5_FENCE_DC = 9;
static const uint32_t CPLT_CTRL1_TC_REGION6_FENCE_DC = 10;
static const uint32_t CPLT_CTRL1_TC_REGION7_FENCE_DC = 11;
static const uint32_t CPLT_CTRL1_TC_REGION8_FENCE_DC = 12;
static const uint32_t CPLT_CTRL1_TC_REGION9_FENCE_DC = 13;
static const uint32_t CPLT_CTRL1_TC_REGION10_FENCE_DC = 14;
static const uint32_t CPLT_CTRL1_TC_REGION11_FENCE_DC = 15;
static const uint32_t CPLT_CTRL1_TC_REGION12_FENCE_DC = 16;
static const uint32_t CPLT_CTRL1_TC_REGION13_FENCE_DC = 17;
static const uint32_t CPLT_CTRL1_TC_REGION14_FENCE_DC = 18;
static const uint32_t CPLT_CTRL1_UNUSED_19B = 19;
static const uint32_t CPLT_CTRL1_UNUSED_20B = 20;
static const uint32_t CPLT_CTRL1_UNUSED_21B = 21;
static const uint32_t CPLT_CTRL1_UNUSED_22B = 22;
static const uint32_t CPLT_CTRL1_UNUSED_23B = 23;
static const uint32_t CPLT_CTRL1_UNUSED_24B = 24;
static const uint32_t CPLT_CTRL1_UNUSED_25B = 25;
static const uint32_t CPLT_CTRL1_UNUSED_26B = 26;
static const uint32_t CPLT_CTRL1_UNUSED_27B = 27;
static const uint32_t CPLT_CTRL1_UNUSED_28B = 28;
static const uint32_t CPLT_CTRL1_UNUSED_29B = 29;
static const uint32_t CPLT_CTRL1_UNUSED_30B = 30;
static const uint32_t CPLT_CTRL1_UNUSED_31B = 31;
// mc/reg00000.H

static const uint64_t CPLT_CTRL2_RW = 0x0c000002ull;
static const uint64_t CPLT_CTRL2_WO_CLEAR = 0x0c000022ull;
static const uint64_t CPLT_CTRL2_WO_OR = 0x0c000012ull;

static const uint32_t CPLT_CTRL2_0_PGOOD = 4;
static const uint32_t CPLT_CTRL2_1_PGOOD = 5;
static const uint32_t CPLT_CTRL2_2_PGOOD = 6;
static const uint32_t CPLT_CTRL2_3_PGOOD = 7;
static const uint32_t CPLT_CTRL2_4_PGOOD = 8;
static const uint32_t CPLT_CTRL2_5_PGOOD = 9;
static const uint32_t CPLT_CTRL2_6_PGOOD = 10;
static const uint32_t CPLT_CTRL2_7_PGOOD = 11;
static const uint32_t CPLT_CTRL2_8_PGOOD = 12;
static const uint32_t CPLT_CTRL2_9_PGOOD = 13;
static const uint32_t CPLT_CTRL2_10_PGOOD = 14;
static const uint32_t CPLT_CTRL2_11_PGOOD = 15;
static const uint32_t CPLT_CTRL2_12_PGOOD = 16;
static const uint32_t CPLT_CTRL2_13_PGOOD = 17;
static const uint32_t CPLT_CTRL2_14_PGOOD = 18;
// mc/reg00000.H

static const uint64_t CPLT_CTRL3_RW = 0x0c000003ull;
static const uint64_t CPLT_CTRL3_WO_CLEAR = 0x0c000023ull;
static const uint64_t CPLT_CTRL3_WO_OR = 0x0c000013ull;

static const uint32_t CPLT_CTRL3_0_PSCOM_EN = 4;
static const uint32_t CPLT_CTRL3_1_PSCOM_EN = 5;
static const uint32_t CPLT_CTRL3_2_PSCOM_EN = 6;
static const uint32_t CPLT_CTRL3_3_PSCOM_EN = 7;
static const uint32_t CPLT_CTRL3_4_PSCOM_EN = 8;
static const uint32_t CPLT_CTRL3_5_PSCOM_EN = 9;
static const uint32_t CPLT_CTRL3_6_PSCOM_EN = 10;
static const uint32_t CPLT_CTRL3_7_PSCOM_EN = 11;
static const uint32_t CPLT_CTRL3_8_PSCOM_EN = 12;
static const uint32_t CPLT_CTRL3_9_PSCOM_EN = 13;
static const uint32_t CPLT_CTRL3_10_PSCOM_EN = 14;
static const uint32_t CPLT_CTRL3_11_PSCOM_EN = 15;
static const uint32_t CPLT_CTRL3_12_PSCOM_EN = 16;
static const uint32_t CPLT_CTRL3_13_PSCOM_EN = 17;
static const uint32_t CPLT_CTRL3_14_PSCOM_EN = 18;
// mc/reg00000.H

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
// mc/reg00000.H

static const uint64_t CPLT_CTRL5_RW = 0x0c000005ull;
static const uint64_t CPLT_CTRL5_WO_CLEAR = 0x0c000025ull;
static const uint64_t CPLT_CTRL5_WO_OR = 0x0c000015ull;

static const uint32_t CPLT_CTRL5_TC_REGION_POWER_GATE = 4;
static const uint32_t CPLT_CTRL5_TC_REGION_POWER_GATE_LEN = 15;
// mc/reg00000.H

static const uint64_t CPLT_MASK0 = 0x0c000101ull;

static const uint32_t CPLT_MASK0_CPLTMASK0 = 0;
static const uint32_t CPLT_MASK0_CPLTMASK0_LEN = 24;
// mc/reg00000.H

static const uint64_t CPLT_STAT0 = 0x0c000100ull;

static const uint32_t CPLT_STAT0_ABIST_DONE_DC = 0;
static const uint32_t CPLT_STAT0_UNUSED_1I = 1;
static const uint32_t CPLT_STAT0_RESERVED_2I = 2;
static const uint32_t CPLT_STAT0_RESERVED_3I = 3;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT0_OUT = 4;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT1_OUT = 5;
static const uint32_t CPLT_STAT0_RESERVED_6I = 6;
static const uint32_t CPLT_STAT0_UNUSED_7I = 7;
static const uint32_t CPLT_STAT0_CC_CTRL_OPCG_DONE_DC = 8;
static const uint32_t CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC = 9;
static const uint32_t CPLT_STAT0_FREE_USAGE_10I = 10;
static const uint32_t CPLT_STAT0_FREE_USAGE_11I = 11;
static const uint32_t CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN = 12;
static const uint32_t CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN = 13;
static const uint32_t CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN = 14;
static const uint32_t CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN = 15;
static const uint32_t CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN = 16;
static const uint32_t CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN = 17;
static const uint32_t CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN = 18;
static const uint32_t CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN = 19;
static const uint32_t CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN = 20;
static const uint32_t CPLT_STAT0_FREE_USAGE_21I = 21;
static const uint32_t CPLT_STAT0_FREE_USAGE_22I = 22;
static const uint32_t CPLT_STAT0_FREE_USAGE_23I = 23;
// mc/reg00000.H

static const uint64_t CTRL_ATOMIC_LOCK_REG = 0x0c0003ffull;

static const uint32_t CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// mc/reg00000.H

static const uint64_t CTRL_PROTECT_MODE_REG = 0x0c0003feull;

static const uint32_t CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// mc/reg00000.H

static const uint64_t DBG_CBS_CC = 0x0c030013ull;

static const uint32_t DBG_CBS_CC_DBG_RESET_EP = 0;
static const uint32_t DBG_CBS_CC_DBG_OPCG_IP = 1;
static const uint32_t DBG_CBS_CC_DBG_VITL_CLKOFF = 2;
static const uint32_t DBG_CBS_CC_DBG_TEST_ENABLE = 3;
static const uint32_t DBG_CBS_CC_DBG_CBS_REQ = 4;
static const uint32_t DBG_CBS_CC_DBG_CBS_CMD = 5;
static const uint32_t DBG_CBS_CC_DBG_CBS_CMD_LEN = 3;
static const uint32_t DBG_CBS_CC_DBG_CBS_STATE = 8;
static const uint32_t DBG_CBS_CC_DBG_CBS_STATE_LEN = 5;
static const uint32_t DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE = 13;
static const uint32_t DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR = 14;
static const uint32_t DBG_CBS_CC_DBG_PCB_IDLE = 15;
static const uint32_t DBG_CBS_CC_DBG_CURRENT_OPCG_MODE = 16;
static const uint32_t DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN = 4;
static const uint32_t DBG_CBS_CC_DBG_LAST_OPCG_MODE = 20;
static const uint32_t DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN = 4;
static const uint32_t DBG_CBS_CC_DBG_PCB_ERROR = 24;
static const uint32_t DBG_CBS_CC_DBG_PARITY_ERROR = 25;
static const uint32_t DBG_CBS_CC_DBG_CC_ERROR = 26;
static const uint32_t DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED = 27;
static const uint32_t DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET = 28;
static const uint32_t DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE = 29;
static const uint32_t DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE = 30;
static const uint32_t DBG_CBS_CC_TP_TPFSI_CBS_ACK = 31;
// mc/reg00000.H

static const uint64_t EDRAM_STATUS = 0x0c0f0029ull;

static const uint32_t EDRAM_STATUS_EDRAM_STAT = 0;
static const uint32_t EDRAM_STATUS_EDRAM_STAT_LEN = 4;
// mc/reg00000.H

static const uint64_t EPS_DBG_INST1_COND_REG_1 = 0x0c0107c1ull;

static const uint32_t EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t EPS_DBG_INST1_COND_REG_1_UNUSED_1 = 36;
static const uint32_t EPS_DBG_INST1_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t EPS_DBG_INST1_COND_REG_1_UNUSED_2 = 43;
static const uint32_t EPS_DBG_INST1_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// mc/reg00000.H

static const uint64_t EPS_DBG_INST1_COND_REG_2 = 0x0c0107c2ull;

static const uint32_t EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t EPS_DBG_INST1_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t EPS_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN = 24;
// mc/reg00000.H

static const uint64_t EPS_DBG_INST1_COND_REG_3 = 0x0c0107c3ull;
// mc/reg00000.H

static const uint64_t EPS_DBG_INST2_COND_REG_1 = 0x0c0107c4ull;

static const uint32_t EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t EPS_DBG_INST2_COND_REG_1_UNUSED_1 = 36;
static const uint32_t EPS_DBG_INST2_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t EPS_DBG_INST2_COND_REG_1_UNUSED_2 = 43;
static const uint32_t EPS_DBG_INST2_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// mc/reg00000.H

static const uint64_t EPS_DBG_INST2_COND_REG_2 = 0x0c0107c5ull;

static const uint32_t EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t EPS_DBG_INST2_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t EPS_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN = 24;
// mc/reg00000.H

static const uint64_t EPS_DBG_INST2_COND_REG_3 = 0x0c0107c6ull;
// mc/reg00000.H

static const uint64_t EPS_DBG_MODE_REG = 0x0c0107c0ull;

static const uint32_t EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 11;
static const uint32_t EPS_DBG_MODE_REG_SYNC_BRCST_MODE = 12;
static const uint32_t EPS_DBG_MODE_REG_SYNC_BRCST_MODE_LEN = 2;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// mc/reg00000.H

static const uint64_t EPS_DBG_TRACE_MODE_REG_2 = 0x0c0107cfull;

static const uint32_t EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// mc/reg00000.H

static const uint64_t EPS_DBG_TRACE_REG_0 = 0x0c0107cdull;

static const uint32_t EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// mc/reg00000.H

static const uint64_t EPS_DBG_TRACE_REG_1 = 0x0c0107ceull;

static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// mc/reg00000.H

static const uint64_t EPS_DBG_DEBUG_TRACE_CONTROL = 0x0c0107d0ull;
// mc/reg00000.H

static const uint64_t EPS_DBG_XTRA_TRACE_MODE = 0x0c0107d1ull;

static const uint32_t EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA = 0;
static const uint32_t EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN = 42;
// mc/reg00000.H

static const uint64_t EPS_FIR_GXSTOP0_MASK_REG = 0x0c040014ull;

static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_GXSTP0_XSTOP_MASK_IN = 0;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_GXSTP0_XSTOP_MASK_IN_LEN = 12;
// mc/reg00000.H

static const uint64_t EPS_FIR_GXSTOP1_MASK_REG = 0x0c040015ull;

static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_GXSTP1_XSTOP_MASK_IN = 0;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_GXSTP1_XSTOP_MASK_IN_LEN = 12;
// mc/reg00000.H

static const uint64_t EPS_FIR_GXSTOP2_MASK_REG = 0x0c040016ull;

static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_GXSTP2_XSTOP_MASK_IN = 0;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_GXSTP2_XSTOP_MASK_IN_LEN = 12;
// mc/reg00000.H

static const uint64_t EPS_FIR_GXSTOP_TRIG_REG = 0x0c040013ull;

static const uint32_t EPS_FIR_GXSTOP_TRIG_REG_GXSTP_TRIG_IN = 0;
static const uint32_t EPS_FIR_GXSTOP_TRIG_REG_GXSTP_TRIG_IN_LEN = 12;
// mc/reg00000.H

static const uint64_t EPS_FIR_LOCAL_ACTION0 = 0x0c040010ull;

static const uint32_t EPS_FIR_LOCAL_ACTION0_FIR_ACTION0_IN = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION0_FIR_ACTION0_IN_LEN = 49;
// mc/reg00000.H

static const uint64_t EPS_FIR_LOCAL_ACTION1 = 0x0c040011ull;

static const uint32_t EPS_FIR_LOCAL_ACTION1_FIR_ACTION1_IN = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION1_FIR_ACTION1_IN_LEN = 49;
// mc/reg00000.H

static const uint64_t EPS_FIR_LOCAL_MASK_RW = 0x0c04000dull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_AND = 0x0c04000eull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_OR = 0x0c04000full;

static const uint32_t EPS_FIR_LOCAL_MASK_LFIR_MASK_IN = 0;
static const uint32_t EPS_FIR_LOCAL_MASK_LFIR_MASK_IN_LEN = 49;
// mc/reg00000.H

static const uint64_t EPS_FIR_MODE_REG = 0x0c040008ull;

static const uint32_t EPS_FIR_MODE_REG_MODE_IN0 = 0;
static const uint32_t EPS_FIR_MODE_REG_MODE_IN1 = 1;
static const uint32_t EPS_FIR_MODE_REG_MODE_IN2 = 2;
static const uint32_t EPS_FIR_MODE_REG_MODE_IN3 = 3;
static const uint32_t EPS_FIR_MODE_REG_MODE_IN4 = 4;
static const uint32_t EPS_FIR_MODE_REG_MODE_IN5 = 5;
static const uint32_t EPS_FIR_MODE_REG_MODE_IN6 = 6;
static const uint32_t EPS_FIR_MODE_REG_MODE_IN7 = 7;
static const uint32_t EPS_FIR_MODE_REG_MODE_IN8 = 8;
static const uint32_t EPS_FIR_MODE_REG_MODE_IN9 = 9;
static const uint32_t EPS_FIR_MODE_REG_MODE_IN10 = 10;
static const uint32_t EPS_FIR_MODE_REG_MODE_IN11 = 11;
static const uint32_t EPS_FIR_MODE_REG_MODE_IN = 12;
static const uint32_t EPS_FIR_MODE_REG_MODE_IN_LEN = 4;
// mc/reg00000.H

static const uint64_t EPS_FIR_SUM_MASK_REG = 0x0c040017ull;

static const uint32_t EPS_FIR_SUM_MASK_REG_SMASK_IN = 0;
static const uint32_t EPS_FIR_SUM_MASK_REG_SMASK_IN_LEN = 5;
// mc/reg00000.H

static const uint64_t EPS_PSC_ADDR_TRAP_REG = 0x0c010003ull;

static const uint32_t EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR = 0;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN = 16;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR = 16;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT = 17;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR = 18;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN = 13;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY = 31;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR = 32;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION = 33;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER = 34;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID = 35;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID_LEN = 4;
// mc/reg00000.H

static const uint64_t EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG = 0x0c010007ull;

static const uint32_t EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK = 0;
static const uint32_t EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN = 32;
// mc/reg00000.H

static const uint64_t EPS_PSC_PSCOM_ERROR_MASK = 0x0c010002ull;

static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR = 3;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_UL_P0_ERROR = 5;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_GENERAL_TIMEOUT = 15;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
// mc/reg00000.H

static const uint64_t EPS_PSC_PSCOM_MODE_REG = 0x0c010000ull;

static const uint32_t EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR = 0;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR = 1;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_UNUSED_MODE_REG_BIT_2 = 2;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR = 3;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE = 4;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT = 5;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN = 2;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS = 7;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE = 8;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT = 9;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN = 3;
// mc/reg00000.H

static const uint64_t EPS_PSC_PSCOM_STATUS_ERROR_REG = 0x0c010001ull;

static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_P0_ERROR = 3;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_P0_ERROR = 5;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_GENERAL_TIMEOUT = 15;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_WDATA_PARITY_ERROR = 18;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_ADDRESS_PARITY_ERROR = 19;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_WDATA_PARITY_ERROR = 20;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_P0_ERROR = 21;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_RDATA_PARITY_ERROR = 22;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_P0_ERROR = 23;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_INTERFACE_MACHINE = 24;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_P2S_MACHINE = 25;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 26;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 27;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 28;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_WRITE_NVLD = 29;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_READ_NVLD = 30;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_ADDR_INVALID = 31;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_COMMAND_PARITY_ERROR = 32;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_GENERAL_TIMEOUT = 33;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 34;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 35;
// mc/reg00000.H

static const uint64_t EPS_PSC_RING_FENCE_MASK_LATCH_REG = 0x0c010008ull;

static const uint32_t EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK = 1;
static const uint32_t EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN = 31;
// mc/reg00001.H

static const uint64_t EPS_PSC_WRITE_PROTECT_ENABLE_REG = 0x0c010005ull;

static const uint32_t EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING = 0;
static const uint32_t EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1;
// mc/reg00001.H

static const uint64_t EPS_PSC_WRITE_PROTECT_RINGS_REG = 0x0c010006ull;

static const uint32_t EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS = 0;
static const uint32_t EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS_LEN = 32;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_CONTROL_REG = 0x0c050012ull;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT0 = 0x0c050000ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT1 = 0x0c050001ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT2 = 0x0c050002ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_DTS_TRC_RESULT = 0x0c050003ull;

static const uint32_t EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE = 0;
static const uint32_t EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR = 44;
static const uint32_t EPS_THERM_WSUB_DTS_TRC_RESULT_DTS_1_RESULT = 48;
static const uint32_t EPS_THERM_WSUB_DTS_TRC_RESULT_DTS_1_RESULT_LEN = 16;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_ERR_STATUS_REG = 0x0c050013ull;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_INJECT_REG = 0x0c050011ull;

static const uint32_t EPS_THERM_WSUB_INJECT_REG_TRIP = 0;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_TRIP_LEN = 2;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_MODE = 2;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_MODE_LEN = 2;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG = 0x0c050016ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC = 0;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC_LEN = 3;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT = 36;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN = 2;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA0 = 0x0c050019ull;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA1 = 0x0c05001aull;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA2 = 0x0c05001bull;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_SKITTER_FORCE_REG = 0x0c050014ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_SKITTER_MODE_REG = 0x0c050010ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE = 0;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_DISABLE_SKITTER_STICKINESS = 1;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_MODE_UNUSED1 = 2;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_MODE_UNUSED1_LEN = 2;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL = 4;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL_LEN = 2;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL = 6;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL_LEN = 2;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS = 8;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS_LEN = 2;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE_WITH_TRIGGER = 44;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_DATA_V_LT = 45;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_MODE_REG = 0x0c05000full;

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
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_MODE_UNUSED = 15;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL = 16;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN = 4;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 = 20;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN = 3;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 = 24;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN = 3;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 = 28;
// mc/reg00001.H

static const uint64_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ = 0x0c05001cull;

static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
// mc/reg00001.H

static const uint64_t ERROR_REG = 0x0c0f001full;

static const uint32_t ERROR_REG_CE_ERROR = 0;
static const uint32_t ERROR_REG_CHIPLET_ERRORS = 1;
static const uint32_t ERROR_REG_CHIPLET_ERRORS_LEN = 3;
static const uint32_t ERROR_REG_PARITY_ERROR = 4;
static const uint32_t ERROR_REG_DATA_BUFFER_ERROR = 5;
static const uint32_t ERROR_REG_ADDR_BUFFER_ERROR = 6;
static const uint32_t ERROR_REG_PCB_FSM_ERROR = 7;
static const uint32_t ERROR_REG_CL_FSM_ERROR = 8;
static const uint32_t ERROR_REG_INT_RX_FSM_ERROR = 9;
static const uint32_t ERROR_REG_INT_TX_FSM_ERROR = 10;
static const uint32_t ERROR_REG_INT_TYPE_ERROR = 11;
static const uint32_t ERROR_REG_CL_DATA_ERROR = 12;
static const uint32_t ERROR_REG_INFO_ERROR = 13;
static const uint32_t ERROR_REG_UNUSED_0 = 14;
static const uint32_t ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR = 15;
static const uint32_t ERROR_REG_PCB_INTERFACE_ERROR = 16;
static const uint32_t ERROR_REG_CHIPLET_OFFLINE = 17;
static const uint32_t ERROR_REG_EDRAM_SEQUENCE_ERR = 18;
static const uint32_t ERROR_REG_CTRL_REG_PARITY_ERROR = 19;
static const uint32_t ERROR_REG_ADDRESS_REG_PARITY_ERROR = 20;
static const uint32_t ERROR_REG_TIMEOUT_REG_PARITY_ERROR = 21;
static const uint32_t ERROR_REG_CONFIG_REG_PARITY_ERROR = 22;
static const uint32_t ERROR_REG_DIV_REG_PARITY_ERROR = 23;
static const uint32_t ERROR_REG_PLL_UNLOCK_ERROR = 24;
static const uint32_t ERROR_REG_PLL_UNLOCK_ERROR_LEN = 8;
// mc/reg00001.H

static const uint64_t ERROR_STATUS = 0x0c03000full;

static const uint32_t ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR = 0;
static const uint32_t ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR = 1;
static const uint32_t ERROR_STATUS_PCB_PARITY_ON_CMD_ERR = 2;
static const uint32_t ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR = 3;
static const uint32_t ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR = 4;
static const uint32_t ERROR_STATUS_PCB_PARITY_ON_DATA_ERR = 5;
static const uint32_t ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR = 6;
static const uint32_t ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR = 7;
static const uint32_t ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR = 8;
static const uint32_t ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR = 9;
static const uint32_t ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR = 10;
static const uint32_t ERROR_STATUS_SCAN_COLLISION_ERR = 11;
static const uint32_t ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR = 12;
static const uint32_t ERROR_STATUS_OPCG_TRIGGER_ERR = 13;
static const uint32_t ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR = 14;
static const uint32_t ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR = 15;
static const uint32_t ERROR_STATUS_PARITY_ON_OPCG_SM_ERR = 16;
static const uint32_t ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR = 17;
static const uint32_t ERROR_STATUS_PARITY_ON_OPCG_REG_ERR = 18;
static const uint32_t ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR = 19;
static const uint32_t ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR = 20;
static const uint32_t ERROR_STATUS_PARITY_ON_GPIO_REG_ERR = 21;
static const uint32_t ERROR_STATUS_CLKCMD_REQUEST_ERR = 22;
static const uint32_t ERROR_STATUS_CBS_PROTOCOL_ERR = 23;
static const uint32_t ERROR_STATUS_VITL_ALIGN_ERR = 24;
static const uint32_t ERROR_STATUS_UNIT_SYNC_LVL_ERR = 25;
static const uint32_t ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR = 26;
static const uint32_t ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR = 27;
static const uint32_t ERROR_STATUS_UNUSED_ERROR28 = 28;
static const uint32_t ERROR_STATUS_UNUSED_ERROR29 = 29;
static const uint32_t ERROR_STATUS_UNUSED_ERROR30 = 30;
static const uint32_t ERROR_STATUS_UNUSED_ERROR31 = 31;
// mc/reg00001.H

static const uint64_t FIR_MASK = 0x0c040002ull;

static const uint32_t FIR_MASK_0 = 0;
static const uint32_t FIR_MASK_1 = 1;
static const uint32_t FIR_MASK_2 = 2;
static const uint32_t FIR_MASK_3 = 3;
static const uint32_t FIR_MASK_4 = 4;
static const uint32_t FIR_MASK_5 = 5;
static const uint32_t FIR_MASK_6 = 6;
static const uint32_t FIR_MASK_7 = 7;
static const uint32_t FIR_MASK_8 = 8;
static const uint32_t FIR_MASK_9 = 9;
static const uint32_t FIR_MASK_10 = 10;
static const uint32_t FIR_MASK_11 = 11;
static const uint32_t FIR_MASK_12 = 12;
static const uint32_t FIR_MASK_13 = 13;
static const uint32_t FIR_MASK_14 = 14;
static const uint32_t FIR_MASK_15 = 15;
static const uint32_t FIR_MASK_15_LEN = 11;
static const uint32_t FIR_MASK_26 = 26;
// mc/reg00001.H

static const uint64_t GSD_GROUPSEL_RWX = 0x0c0f0005ull;
static const uint64_t GSD_GROUPSEL_RWX_WAND = 0x0c0f0006ull;
static const uint64_t GSD_GROUPSEL_RWX_WOR = 0x0c0f0007ull;

static const uint32_t GSD_GROUPSEL_GSD_GROUPSELECT = 0;
static const uint32_t GSD_GROUPSEL_GSD_GROUPSELECT_LEN = 6;
// mc/reg00001.H

static const uint64_t HANG_PULSE_0_REG = 0x0c0f0020ull;

static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0 = 0;
static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN = 6;
static const uint32_t HANG_PULSE_0_REG_SUPPRESS_HANG_0 = 6;
// mc/reg00001.H

static const uint64_t HANG_PULSE_1_REG = 0x0c0f0021ull;

static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1 = 0;
static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN = 6;
static const uint32_t HANG_PULSE_1_REG_SUPPRESS_HANG_1 = 6;
// mc/reg00001.H

static const uint64_t HANG_PULSE_2_REG = 0x0c0f0022ull;

static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2 = 0;
static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN = 6;
static const uint32_t HANG_PULSE_2_REG_SUPPRESS_HANG_2 = 6;
// mc/reg00001.H

static const uint64_t HANG_PULSE_3_REG = 0x0c0f0023ull;

static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3 = 0;
static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN = 6;
static const uint32_t HANG_PULSE_3_REG_SUPPRESS_HANG_3 = 6;
// mc/reg00001.H

static const uint64_t HANG_PULSE_4_REG = 0x0c0f0024ull;

static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4 = 0;
static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN = 6;
static const uint32_t HANG_PULSE_4_REG_SUPPRESS_HANG_4 = 6;
// mc/reg00001.H

static const uint64_t HANG_PULSE_5_REG = 0x0c0f0025ull;

static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5 = 0;
static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN = 6;
static const uint32_t HANG_PULSE_5_REG_SUPPRESS_HANG_5 = 6;
// mc/reg00001.H

static const uint64_t HANG_PULSE_6_REG = 0x0c0f0026ull;

static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6 = 0;
static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN = 6;
static const uint32_t HANG_PULSE_6_REG_SUPPRESS_HANG_6 = 6;
// mc/reg00001.H

static const uint64_t HEARTBEAT_REG = 0x0c0f0018ull;

static const uint32_t HEARTBEAT_REG_HEARTBEAT_DEAD = 0;
// mc/reg00001.H

static const uint64_t HOSTATTN = 0x0c040009ull;

static const uint32_t HOSTATTN_0 = 0;
static const uint32_t HOSTATTN_1 = 1;
static const uint32_t HOSTATTN_2 = 2;
static const uint32_t HOSTATTN_3 = 3;
static const uint32_t HOSTATTN_4 = 4;
static const uint32_t HOSTATTN_5 = 5;
static const uint32_t HOSTATTN_6 = 6;
static const uint32_t HOSTATTN_7 = 7;
static const uint32_t HOSTATTN_8 = 8;
static const uint32_t HOSTATTN_9 = 9;
static const uint32_t HOSTATTN_10 = 10;
static const uint32_t HOSTATTN_11 = 11;
static const uint32_t HOSTATTN_12 = 12;
static const uint32_t HOSTATTN_13 = 13;
static const uint32_t HOSTATTN_14 = 14;
static const uint32_t HOSTATTN_15 = 15;
static const uint32_t HOSTATTN_16 = 16;
static const uint32_t HOSTATTN_17 = 17;
static const uint32_t HOSTATTN_18 = 18;
static const uint32_t HOSTATTN_19 = 19;
static const uint32_t HOSTATTN_20 = 20;
static const uint32_t HOSTATTN_21 = 21;
static const uint32_t HOSTATTN_22 = 22;
// mc/reg00001.H

static const uint64_t HOSTATTN_MASK = 0x0c04001aull;

static const uint32_t HOSTATTN_MASK_HOSTATTN_MASK_IN = 0;
static const uint32_t HOSTATTN_MASK_HOSTATTN_MASK_IN_LEN = 22;
// mc/reg00001.H

static const uint64_t LOCAL_FIR_RWX = 0x0c04000aull;
static const uint64_t LOCAL_FIR_WOX_AND = 0x0c04000bull;
static const uint64_t LOCAL_FIR_WOX_OR = 0x0c04000cull;

static const uint32_t LOCAL_FIR_0 = 0;
static const uint32_t LOCAL_FIR_1 = 1;
static const uint32_t LOCAL_FIR_2 = 2;
static const uint32_t LOCAL_FIR_3 = 3;
static const uint32_t LOCAL_FIR_4 = 4;
static const uint32_t LOCAL_FIR_5 = 5;
static const uint32_t LOCAL_FIR_6 = 6;
static const uint32_t LOCAL_FIR_7 = 7;
static const uint32_t LOCAL_FIR_8 = 8;
static const uint32_t LOCAL_FIR_9 = 9;
static const uint32_t LOCAL_FIR_10 = 10;
static const uint32_t LOCAL_FIR_11 = 11;
static const uint32_t LOCAL_FIR_12 = 12;
static const uint32_t LOCAL_FIR_13 = 13;
static const uint32_t LOCAL_FIR_14 = 14;
static const uint32_t LOCAL_FIR_15 = 15;
static const uint32_t LOCAL_FIR_16 = 16;
static const uint32_t LOCAL_FIR_17 = 17;
static const uint32_t LOCAL_FIR_18 = 18;
static const uint32_t LOCAL_FIR_19 = 19;
static const uint32_t LOCAL_FIR_20 = 20;
static const uint32_t LOCAL_FIR_21 = 21;
static const uint32_t LOCAL_FIR_22 = 22;
static const uint32_t LOCAL_FIR_23 = 23;
static const uint32_t LOCAL_FIR_24 = 24;
static const uint32_t LOCAL_FIR_25 = 25;
static const uint32_t LOCAL_FIR_26 = 26;
static const uint32_t LOCAL_FIR_27 = 27;
static const uint32_t LOCAL_FIR_28 = 28;
static const uint32_t LOCAL_FIR_29 = 29;
static const uint32_t LOCAL_FIR_30 = 30;
static const uint32_t LOCAL_FIR_31 = 31;
static const uint32_t LOCAL_FIR_32 = 32;
static const uint32_t LOCAL_FIR_33 = 33;
static const uint32_t LOCAL_FIR_34 = 34;
static const uint32_t LOCAL_FIR_35 = 35;
static const uint32_t LOCAL_FIR_36 = 36;
static const uint32_t LOCAL_FIR_37 = 37;
static const uint32_t LOCAL_FIR_38 = 38;
static const uint32_t LOCAL_FIR_39 = 39;
static const uint32_t LOCAL_FIR_40 = 40;
static const uint32_t LOCAL_FIR_41 = 41;
// mc/reg00001.H

static const uint64_t LOCAL_XSTOP_ERR = 0x0c040018ull;

static const uint32_t LOCAL_XSTOP_ERR_0 = 0;
static const uint32_t LOCAL_XSTOP_ERR_1 = 1;
static const uint32_t LOCAL_XSTOP_ERR_2 = 2;
static const uint32_t LOCAL_XSTOP_ERR_3 = 3;
static const uint32_t LOCAL_XSTOP_ERR_4 = 4;
static const uint32_t LOCAL_XSTOP_ERR_5 = 5;
static const uint32_t LOCAL_XSTOP_ERR_6 = 6;
static const uint32_t LOCAL_XSTOP_ERR_7 = 7;
static const uint32_t LOCAL_XSTOP_ERR_8 = 8;
static const uint32_t LOCAL_XSTOP_ERR_9 = 9;
static const uint32_t LOCAL_XSTOP_ERR_10 = 10;
static const uint32_t LOCAL_XSTOP_ERR_11 = 11;
static const uint32_t LOCAL_XSTOP_ERR_12 = 12;
static const uint32_t LOCAL_XSTOP_ERR_13 = 13;
static const uint32_t LOCAL_XSTOP_ERR_14 = 14;
static const uint32_t LOCAL_XSTOP_ERR_15 = 15;
static const uint32_t LOCAL_XSTOP_ERR_16 = 16;
static const uint32_t LOCAL_XSTOP_ERR_17 = 17;
static const uint32_t LOCAL_XSTOP_ERR_18 = 18;
static const uint32_t LOCAL_XSTOP_ERR_19 = 19;
static const uint32_t LOCAL_XSTOP_ERR_20 = 20;
static const uint32_t LOCAL_XSTOP_ERR_21 = 21;
static const uint32_t LOCAL_XSTOP_ERR_22 = 22;
// mc/reg00001.H

static const uint64_t LOCAL_XSTOP_MASK = 0x0c040019ull;

static const uint32_t LOCAL_XSTOP_MASK_LOCAL_XSTOP_MASK_IN = 0;
static const uint32_t LOCAL_XSTOP_MASK_LOCAL_XSTOP_MASK_IN_LEN = 22;
// mc/reg00001.H

static const uint64_t MULTICAST_GROUP_1 = 0x0c0f0001ull;

static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
// mc/reg00001.H

static const uint64_t MULTICAST_GROUP_2 = 0x0c0f0002ull;

static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// mc/reg00001.H

static const uint64_t MULTICAST_GROUP_3 = 0x0c0f0003ull;

static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP = 3;
static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN = 3;
// mc/reg00001.H

static const uint64_t MULTICAST_GROUP_4 = 0x0c0f0004ull;

static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP = 3;
static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN = 3;
// mc/reg00001.H

static const uint64_t NET_CTRL0_RWX = 0x0c0f0040ull;
static const uint64_t NET_CTRL0_RWX_WAND = 0x0c0f0041ull;
static const uint64_t NET_CTRL0_RWX_WOR = 0x0c0f0042ull;

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
// mc/reg00001.H

static const uint64_t NET_CTRL1_RWX = 0x0c0f0044ull;
static const uint64_t NET_CTRL1_RWX_WAND = 0x0c0f0045ull;
static const uint64_t NET_CTRL1_RWX_WOR = 0x0c0f0046ull;

static const uint32_t NET_CTRL1_PLL_CLKIN_SEL = 0;
static const uint32_t NET_CTRL1_CLK_DCC_BYPASS_EN = 1;
static const uint32_t NET_CTRL1_CLK_PDLY_BYPASS_EN = 2;
static const uint32_t NET_CTRL1_CLK_DIV_BYPASS_EN = 3;
static const uint32_t NET_CTRL1_REFCLK_CLKMUX0_SEL = 4;
static const uint32_t NET_CTRL1_REFCLK_CLKMUX1_SEL = 5;
static const uint32_t NET_CTRL1_PLL_BNDY_BYPASS_EN = 6;
static const uint32_t NET_CTRL1_DPLL_TEST_SEL = 8;
static const uint32_t NET_CTRL1_DPLL_TEST_SEL_LEN = 8;
static const uint32_t NET_CTRL1_SB_STRENGTH = 16;
static const uint32_t NET_CTRL1_SB_STRENGTH_LEN = 4;
static const uint32_t NET_CTRL1_ASYNC_TYPE = 20;
static const uint32_t NET_CTRL1_ASYNC_OBS = 21;
static const uint32_t NET_CTRL1_CPM_CAL_SET = 22;
static const uint32_t NET_CTRL1_SENSEADJ_RESET0 = 23;
static const uint32_t NET_CTRL1_SENSEADJ_RESET1 = 24;
static const uint32_t NET_CTRL1_CLK_PULSE_EN = 25;
static const uint32_t NET_CTRL1_CLK_PULSE_MODE = 26;
static const uint32_t NET_CTRL1_CLK_PULSE_MODE_LEN = 2;
// mc/reg00001.H

static const uint64_t OPCG_ALIGN = 0x0c030001ull;

static const uint32_t OPCG_ALIGN_INOP_ALIGN = 0;
static const uint32_t OPCG_ALIGN_INOP_ALIGN_LEN = 4;
static const uint32_t OPCG_ALIGN_SNOP_ALIGN = 4;
static const uint32_t OPCG_ALIGN_SNOP_ALIGN_LEN = 4;
static const uint32_t OPCG_ALIGN_ENOP_ALIGN = 8;
static const uint32_t OPCG_ALIGN_ENOP_ALIGN_LEN = 4;
static const uint32_t OPCG_ALIGN_INOP_WAIT = 12;
static const uint32_t OPCG_ALIGN_INOP_WAIT_LEN = 8;
static const uint32_t OPCG_ALIGN_SNOP_WAIT = 20;
static const uint32_t OPCG_ALIGN_SNOP_WAIT_LEN = 12;
static const uint32_t OPCG_ALIGN_ENOP_WAIT = 32;
static const uint32_t OPCG_ALIGN_ENOP_WAIT_LEN = 8;
static const uint32_t OPCG_ALIGN_INOP_FORCE_SG = 40;
static const uint32_t OPCG_ALIGN_SNOP_FORCE_SG = 41;
static const uint32_t OPCG_ALIGN_ENOP_FORCE_SG = 42;
static const uint32_t OPCG_ALIGN_NO_WAIT_ON_CLK_CMD = 43;
static const uint32_t OPCG_ALIGN_ALIGN_SOURCE_SELECT = 44;
static const uint32_t OPCG_ALIGN_ALIGN_SOURCE_SELECT_LEN = 2;
static const uint32_t OPCG_ALIGN_UNUSED46 = 46;
static const uint32_t OPCG_ALIGN_SCAN_RATIO = 47;
static const uint32_t OPCG_ALIGN_SCAN_RATIO_LEN = 5;
static const uint32_t OPCG_ALIGN_OPCG_WAIT_CYCLES = 52;
static const uint32_t OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN = 12;
// mc/reg00001.H

static const uint64_t OPCG_CAPT1 = 0x0c030010ull;

static const uint32_t OPCG_CAPT1_COUNT = 0;
static const uint32_t OPCG_CAPT1_COUNT_LEN = 4;
static const uint32_t OPCG_CAPT1_SEQ_01 = 4;
static const uint32_t OPCG_CAPT1_SEQ_01_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_02 = 9;
static const uint32_t OPCG_CAPT1_SEQ_02_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_03 = 14;
static const uint32_t OPCG_CAPT1_SEQ_03_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_04 = 19;
static const uint32_t OPCG_CAPT1_SEQ_04_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_05 = 24;
static const uint32_t OPCG_CAPT1_SEQ_05_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_06 = 29;
static const uint32_t OPCG_CAPT1_SEQ_06_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_07 = 34;
static const uint32_t OPCG_CAPT1_SEQ_07_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_08 = 39;
static const uint32_t OPCG_CAPT1_SEQ_08_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_09 = 44;
static const uint32_t OPCG_CAPT1_SEQ_09_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_10 = 49;
static const uint32_t OPCG_CAPT1_SEQ_10_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_11 = 54;
static const uint32_t OPCG_CAPT1_SEQ_11_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_12 = 59;
static const uint32_t OPCG_CAPT1_SEQ_12_LEN = 5;
// mc/reg00001.H

static const uint64_t OPCG_CAPT2 = 0x0c030011ull;

static const uint32_t OPCG_CAPT2_UNUSED_CAPT2 = 0;
static const uint32_t OPCG_CAPT2_UNUSED_CAPT2_LEN = 4;
static const uint32_t OPCG_CAPT2_SEQ_13_01EVEN = 4;
static const uint32_t OPCG_CAPT2_SEQ_13_01EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_SEQ_14_01ODD = 9;
static const uint32_t OPCG_CAPT2_SEQ_14_01ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_SEQ_15_02EVEN = 14;
static const uint32_t OPCG_CAPT2_SEQ_15_02EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_SEQ_16_02ODD = 19;
static const uint32_t OPCG_CAPT2_SEQ_16_02ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_SEQ_17_03EVEN = 24;
static const uint32_t OPCG_CAPT2_SEQ_17_03EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_SEQ_18_03ODD = 29;
static const uint32_t OPCG_CAPT2_SEQ_18_03ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_SEQ_19_04EVEN = 34;
static const uint32_t OPCG_CAPT2_SEQ_19_04EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_SEQ_20_04ODD = 39;
static const uint32_t OPCG_CAPT2_SEQ_20_04ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_SEQ_21_05EVEN = 44;
static const uint32_t OPCG_CAPT2_SEQ_21_05EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_SEQ_22_05ODD = 49;
static const uint32_t OPCG_CAPT2_SEQ_22_05ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_SEQ_23_06EVEN = 54;
static const uint32_t OPCG_CAPT2_SEQ_23_06EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_SEQ_24_06ODD = 59;
static const uint32_t OPCG_CAPT2_SEQ_24_06ODD_LEN = 5;
// mc/reg00001.H

static const uint64_t OPCG_CAPT3 = 0x0c030012ull;

static const uint32_t OPCG_CAPT3_UNUSED_CAPT3 = 0;
static const uint32_t OPCG_CAPT3_UNUSED_CAPT3_LEN = 4;
static const uint32_t OPCG_CAPT3_SEQ_07EVEN = 4;
static const uint32_t OPCG_CAPT3_SEQ_07EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_SEQ_07ODD = 9;
static const uint32_t OPCG_CAPT3_SEQ_07ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_SEQ_08EVEN = 14;
static const uint32_t OPCG_CAPT3_SEQ_08EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_SEQ_08ODD = 19;
static const uint32_t OPCG_CAPT3_SEQ_08ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_SEQ_09EVEN = 24;
static const uint32_t OPCG_CAPT3_SEQ_09EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_SEQ_09ODD = 29;
static const uint32_t OPCG_CAPT3_SEQ_09ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_SEQ_10EVEN = 34;
static const uint32_t OPCG_CAPT3_SEQ_10EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_SEQ_10ODD = 39;
static const uint32_t OPCG_CAPT3_SEQ_10ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_SEQ_11EVEN = 44;
static const uint32_t OPCG_CAPT3_SEQ_11EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_SEQ_11ODD = 49;
static const uint32_t OPCG_CAPT3_SEQ_11ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_SEQ_12EVEN = 54;
static const uint32_t OPCG_CAPT3_SEQ_12EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_SEQ_12ODD = 59;
static const uint32_t OPCG_CAPT3_SEQ_12ODD_LEN = 5;
// mc/reg00001.H

static const uint64_t OPCG_REG0 = 0x0c030002ull;

static const uint32_t OPCG_REG0_RUNN_MODE = 0;
static const uint32_t OPCG_REG0_OPCG_GO = 1;
static const uint32_t OPCG_REG0_RUN_SCAN0 = 2;
static const uint32_t OPCG_REG0_SCAN0_MODE = 3;
static const uint32_t OPCG_REG0_OPCG_IN_SLAVE_MODE = 4;
static const uint32_t OPCG_REG0_OPCG_IN_MASTER_MODE = 5;
static const uint32_t OPCG_REG0_KEEP_MS_MODE = 6;
static const uint32_t OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL = 7;
static const uint32_t OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL = 8;
static const uint32_t OPCG_REG0_UNUSED910 = 9;
static const uint32_t OPCG_REG0_RUN_OPCG_ON_UPDATE_DR = 11;
static const uint32_t OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR = 12;
static const uint32_t OPCG_REG0_STOP_RUNN_ON_XSTOP = 13;
static const uint32_t OPCG_REG0_OPCG_STARTS_BIST = 14;
static const uint32_t OPCG_REG0_UNUSED1520 = 15;
static const uint32_t OPCG_REG0_UNUSED1520_LEN = 6;
static const uint32_t OPCG_REG0_LOOP_COUNT = 21;
static const uint32_t OPCG_REG0_LOOP_COUNT_LEN = 43;
// mc/reg00001.H

static const uint64_t OPCG_REG1 = 0x0c030003ull;

static const uint32_t OPCG_REG1_SCAN_COUNT = 0;
static const uint32_t OPCG_REG1_SCAN_COUNT_LEN = 12;
static const uint32_t OPCG_REG1_MISR_A_VAL = 12;
static const uint32_t OPCG_REG1_MISR_A_VAL_LEN = 12;
static const uint32_t OPCG_REG1_MISR_B_VAL = 24;
static const uint32_t OPCG_REG1_MISR_B_VAL_LEN = 12;
static const uint32_t OPCG_REG1_MISR_INIT_WAIT = 36;
static const uint32_t OPCG_REG1_MISR_INIT_WAIT_LEN = 12;
static const uint32_t OPCG_REG1_UNUSED48 = 48;
static const uint32_t OPCG_REG1_SCAN_CLK_USE_EVEN = 49;
static const uint32_t OPCG_REG1_UNUSED5051 = 50;
static const uint32_t OPCG_REG1_UNUSED5051_LEN = 2;
static const uint32_t OPCG_REG1_RTIM_THOLD_FORCE = 52;
static const uint32_t OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL = 53;
static const uint32_t OPCG_REG1_SG_HIGH_DURING_FILL = 54;
static const uint32_t OPCG_REG1_LBIST_SKITTER_CTL = 55;
static const uint32_t OPCG_REG1_LBIST_SKITTER_CTL_LEN = 2;
static const uint32_t OPCG_REG1_MISR_MODE = 57;
static const uint32_t OPCG_REG1_INFINITE_MODE = 58;
static const uint32_t OPCG_REG1_NSL_FILL_COUNT = 59;
static const uint32_t OPCG_REG1_NSL_FILL_COUNT_LEN = 5;
// mc/reg00001.H

static const uint64_t OPCG_REG2 = 0x0c030004ull;

static const uint32_t OPCG_REG2_OPCG_GO2 = 0;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING = 1;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING_LEN = 3;
static const uint32_t OPCG_REG2_PRPG_VALUE = 4;
static const uint32_t OPCG_REG2_PRPG_VALUE_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_A_VAL = 16;
static const uint32_t OPCG_REG2_PRPG_A_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_B_VAL = 28;
static const uint32_t OPCG_REG2_PRPG_B_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_MODE = 40;
static const uint32_t OPCG_REG2_UNUSED41_47 = 41;
static const uint32_t OPCG_REG2_UNUSED41_47_LEN = 7;
static const uint32_t OPCG_REG2_SM_LBIST_CNTRL = 48;
static const uint32_t OPCG_REG2_SM_LBIST_CNTRL_LEN = 16;
// mc/reg00001.H

static const uint64_t PCB_OPCG_GO = 0x0c030020ull;

static const uint32_t PCB_OPCG_GO_PCB_OPCGGO = 0;
// mc/reg00001.H

static const uint64_t PCB_OPCG_STOP = 0x0c030030ull;

static const uint32_t PCB_OPCG_STOP_PCB_OPCGSTOP = 0;
// mc/reg00001.H

static const uint64_t PHASE_COUNTER_RESET = 0x0c030028ull;

static const uint32_t PHASE_COUNTER_RESET_PHASECOUNTER_RESET = 0;
// mc/reg00002.H

static const uint64_t PLL_LOCK_REG = 0x0c0f0019ull;
// mc/reg00002.H

static const uint64_t PRE_COUNTER_REG = 0x0c0f0028ull;

static const uint32_t PRE_COUNTER_REG_PRE_COUNTER = 0;
static const uint32_t PRE_COUNTER_REG_PRE_COUNTER_LEN = 8;
// mc/reg00002.H

static const uint64_t PRIMARY_ADDRESS_REG = 0x0c0f0000ull;
// mc/reg00002.H

static const uint64_t PROTECT_MODE_REG = 0x0c0f03feull;

static const uint32_t PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// mc/reg00002.H

static const uint64_t RECOV_INTERRUPT_REG = 0x0c0f001bull;
// mc/reg00002.H

static const uint64_t RFIR = 0x0c040001ull;

static const uint32_t RFIR_RFIR_IN0 = 0;
static const uint32_t RFIR_LFIR_RECOV_ERR = 1;
static const uint32_t RFIR_RFIR_IN4 = 2;
static const uint32_t RFIR_RFIR_IN5 = 3;
static const uint32_t RFIR_RFIR_IN6 = 4;
static const uint32_t RFIR_RFIR_IN7 = 5;
static const uint32_t RFIR_RFIR_IN8 = 6;
static const uint32_t RFIR_RFIR_IN9 = 7;
static const uint32_t RFIR_RFIR_IN10 = 8;
static const uint32_t RFIR_RFIR_IN11 = 9;
static const uint32_t RFIR_RFIR_IN12 = 10;
static const uint32_t RFIR_RFIR_IN13 = 11;
static const uint32_t RFIR_RFIR_IN14 = 12;
static const uint32_t RFIR_RFIR_IN15 = 13;
static const uint32_t RFIR_RFIR_IN16 = 14;
static const uint32_t RFIR_RFIR_IN17 = 15;
static const uint32_t RFIR_RFIR_IN18 = 16;
static const uint32_t RFIR_RFIR_IN19 = 17;
static const uint32_t RFIR_RFIR_IN20 = 18;
static const uint32_t RFIR_RFIR_IN21 = 19;
static const uint32_t RFIR_RFIR_IN22 = 20;
static const uint32_t RFIR_RFIR_IN22_LEN = 4;
// mc/reg00002.H

static const uint64_t SCAN32 = 0x0c038000ull;
// mc/reg00002.H

static const uint64_t SCAN64 = 0x0c03e000ull;
// mc/reg00002.H

static const uint64_t SCAN_CAPTUREDR = 0x0c03c000ull;
// mc/reg00002.H

static const uint64_t SCAN_CAPTUREDR_LONG = 0x0c03d000ull;
// mc/reg00002.H

static const uint64_t SCAN_LONG_ROTATE = 0x0c039000ull;
// mc/reg00002.H

static const uint64_t SCAN_REGION_TYPE = 0x0c030005ull;

static const uint32_t SCAN_REGION_TYPE_SYSTEM_FAST_INIT = 0;
static const uint32_t SCAN_REGION_TYPE_PARALLEL_SCAN = 1;
static const uint32_t SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR = 2;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_VITL = 3;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_PERV = 4;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT1 = 5;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT2 = 6;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT3 = 7;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT4 = 8;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT5 = 9;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT6 = 10;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT7 = 11;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT8 = 12;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT9 = 13;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT10 = 14;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT11 = 15;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT12 = 16;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT13 = 17;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT14 = 18;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_FUNC = 48;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_CFG = 49;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR = 50;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_REGF = 51;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_LBIST = 52;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_ABIST = 53;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_REPR = 54;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_TIME = 55;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_BNDY = 56;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_FARR = 57;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_CMSK = 58;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_INEX = 59;
// mc/reg00002.H

static const uint64_t SCAN_UPDATEDR = 0x0c03a000ull;
// mc/reg00002.H

static const uint64_t SCAN_UPDATEDR_LONG = 0x0c03b000ull;
// mc/reg00002.H

static const uint64_t SLAVE_CONFIG_REG = 0x0c0f001eull;

static const uint32_t SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK = 0;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN = 1;
static const uint32_t SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP = 2;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK = 3;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_HEARTBEAT = 4;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO = 5;
static const uint32_t SLAVE_CONFIG_REG_PM_DISABLE = 6;
static const uint32_t SLAVE_CONFIG_REG_PM_MUX_DISABLE = 7;
static const uint32_t SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS = 8;
static const uint32_t SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS = 9;
static const uint32_t SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS = 10;
static const uint32_t SLAVE_CONFIG_REG_MASK_PCBSL_ERRS = 11;
static const uint32_t SLAVE_CONFIG_REG_MASK_PLL_ERRS = 12;
static const uint32_t SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN = 8;
// mc/reg00002.H

static const uint64_t SPATTN_NCX = 0x0c040005ull;
static const uint64_t SPATTN_ROX = 0x0c040004ull;

static const uint32_t SPATTN_0 = 0;
static const uint32_t SPATTN_1 = 1;
static const uint32_t SPATTN_2 = 2;
static const uint32_t SPATTN_3 = 3;
static const uint32_t SPATTN_4 = 4;
static const uint32_t SPATTN_5 = 5;
static const uint32_t SPATTN_6 = 6;
static const uint32_t SPATTN_7 = 7;
static const uint32_t SPATTN_8 = 8;
static const uint32_t SPATTN_9 = 9;
// mc/reg00002.H

static const uint64_t SPA_MASK = 0x0c040007ull;

static const uint32_t SPA_MASK_SPA_MASK_IN = 0;
static const uint32_t SPA_MASK_SPA_MASK_IN_LEN = 10;
// mc/reg00002.H

static const uint64_t SYNC_CONFIG = 0x0c030000ull;

static const uint32_t SYNC_CONFIG_SYNC_PULSE_DELAY = 0;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_DELAY_LEN = 4;
static const uint32_t SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS = 4;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_INPUT_SEL = 5;
static const uint32_t SYNC_CONFIG_USE_SYNC_FOR_SCAN = 6;
static const uint32_t SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED = 7;
static const uint32_t SYNC_CONFIG_UNIT_REGION_CLKCMD_ENABLE = 8;
static const uint32_t SYNC_CONFIG_DISABLE_PCB_ITR = 9;
static const uint32_t SYNC_CONFIG_CONT_SCAN_DISABLE = 10;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_OUT_DIS = 11;
static const uint32_t SYNC_CONFIG_REGION_PGOOD_OVERRIDE = 12;
static const uint32_t SYNC_CONFIG_UNUSED1314 = 13;
static const uint32_t SYNC_CONFIG_UNUSED1314_LEN = 2;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN = 15;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE = 16;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN = 8;
// mc/reg00002.H

static const uint64_t TIMEOUT_REG = 0x0c0f0010ull;
// mc/reg00002.H

static const uint64_t TRA0_TR0_TRACE_HI_DATA_REG = 0x0c010400ull;

static const uint32_t TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// mc/reg00002.H

static const uint64_t TRA0_TR0_TRACE_LO_DATA_REG = 0x0c010401ull;

static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// mc/reg00002.H

static const uint64_t TRA0_TR0_CONFIG = 0x0c010402ull;

static const uint32_t TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TRA0_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// mc/reg00002.H

static const uint64_t TRA0_TR0_CONFIG_0 = 0x0c010403ull;

static const uint32_t TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// mc/reg00002.H

static const uint64_t TRA0_TR0_CONFIG_1 = 0x0c010404ull;

static const uint32_t TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// mc/reg00002.H

static const uint64_t TRA0_TR0_CONFIG_2 = 0x0c010405ull;

static const uint32_t TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t TRA0_TR0_CONFIG_2_B_LEN = 24;
// mc/reg00002.H

static const uint64_t TRA0_TR0_CONFIG_3 = 0x0c010406ull;

static const uint32_t TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TRA0_TR0_CONFIG_3_D_LEN = 24;
// mc/reg00002.H

static const uint64_t TRA0_TR0_CONFIG_4 = 0x0c010407ull;

static const uint32_t TRA0_TR0_CONFIG_4_A = 0;
static const uint32_t TRA0_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_4_B = 24;
static const uint32_t TRA0_TR0_CONFIG_4_B_LEN = 24;
// mc/reg00002.H

static const uint64_t TRA0_TR0_CONFIG_5 = 0x0c010408ull;

static const uint32_t TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TRA0_TR0_CONFIG_5_D_LEN = 24;
// mc/reg00002.H

static const uint64_t TRA0_TR0_CONFIG_9 = 0x0c010409ull;

static const uint32_t TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// mc/reg00002.H

static const uint64_t TRA1_TR0_TRACE_HI_DATA_REG = 0x0c010440ull;

static const uint32_t TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// mc/reg00002.H

static const uint64_t TRA1_TR0_TRACE_LO_DATA_REG = 0x0c010441ull;

static const uint32_t TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// mc/reg00002.H

static const uint64_t TRA1_TR0_CONFIG = 0x0c010442ull;

static const uint32_t TRA1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TRA1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED = 22;
static const uint32_t TRA1_TR0_CONFIG_TRACE_CONTROL_UNUSED_LEN = 6;
// mc/reg00002.H

static const uint64_t TRA1_TR0_CONFIG_0 = 0x0c010443ull;

static const uint32_t TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// mc/reg00002.H

static const uint64_t TRA1_TR0_CONFIG_1 = 0x0c010444ull;

static const uint32_t TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// mc/reg00002.H

static const uint64_t TRA1_TR0_CONFIG_2 = 0x0c010445ull;

static const uint32_t TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t TRA1_TR0_CONFIG_2_B_LEN = 24;
// mc/reg00002.H

static const uint64_t TRA1_TR0_CONFIG_3 = 0x0c010446ull;

static const uint32_t TRA1_TR0_CONFIG_3_C = 0;
static const uint32_t TRA1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_3_D = 24;
static const uint32_t TRA1_TR0_CONFIG_3_D_LEN = 24;
// mc/reg00002.H

static const uint64_t TRA1_TR0_CONFIG_4 = 0x0c010447ull;

static const uint32_t TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t TRA1_TR0_CONFIG_4_B_LEN = 24;
// mc/reg00002.H

static const uint64_t TRA1_TR0_CONFIG_5 = 0x0c010448ull;

static const uint32_t TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t TRA1_TR0_CONFIG_5_D_LEN = 24;
// mc/reg00002.H

static const uint64_t TRA1_TR0_CONFIG_9 = 0x0c010449ull;

static const uint32_t TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// mc/reg00002.H

static const uint64_t VITAL_SCAN_OUT = 0x0c0f0017ull;
// mc/reg00002.H

static const uint64_t XFIR = 0x0c040000ull;

static const uint32_t XFIR_0 = 0;
static const uint32_t XFIR_1 = 1;
static const uint32_t XFIR_2 = 2;
static const uint32_t XFIR_3 = 3;
static const uint32_t XFIR_4 = 4;
static const uint32_t XFIR_5 = 5;
static const uint32_t XFIR_6 = 6;
static const uint32_t XFIR_7 = 7;
static const uint32_t XFIR_8 = 8;
static const uint32_t XFIR_9 = 9;
static const uint32_t XFIR_10 = 10;
static const uint32_t XFIR_11 = 11;
static const uint32_t XFIR_12 = 12;
static const uint32_t XFIR_13 = 13;
static const uint32_t XFIR_14 = 14;
static const uint32_t XFIR_15 = 15;
static const uint32_t XFIR_16 = 16;
static const uint32_t XFIR_17 = 17;
static const uint32_t XFIR_18 = 18;
static const uint32_t XFIR_19 = 19;
static const uint32_t XFIR_20 = 20;
static const uint32_t XFIR_21 = 21;
static const uint32_t XFIR_22 = 22;
static const uint32_t XFIR_22_LEN = 4;
static const uint32_t XFIR_26 = 26;
// mc/reg00002.H

static const uint64_t XSTOP1 = 0x0c03000cull;

static const uint32_t XSTOP1_XSTOP1_MASK_B = 0;
static const uint32_t XSTOP1_ALIGNED_XSTOP1 = 1;
static const uint32_t XSTOP1_TRIGGER_OPCG_ON_XSTOP1 = 2;
static const uint32_t XSTOP1_XSTOP1_WAIT_ALLWAYS = 3;
static const uint32_t XSTOP1_XSTOP1_PERV = 4;
static const uint32_t XSTOP1_XSTOP1_UNIT1 = 5;
static const uint32_t XSTOP1_XSTOP1_UNIT2 = 6;
static const uint32_t XSTOP1_XSTOP1_UNIT3 = 7;
static const uint32_t XSTOP1_XSTOP1_UNIT4 = 8;
static const uint32_t XSTOP1_XSTOP1_UNIT5 = 9;
static const uint32_t XSTOP1_XSTOP1_UNIT6 = 10;
static const uint32_t XSTOP1_XSTOP1_UNIT7 = 11;
static const uint32_t XSTOP1_XSTOP1_UNIT8 = 12;
static const uint32_t XSTOP1_XSTOP1_UNIT9 = 13;
static const uint32_t XSTOP1_XSTOP1_UNIT10 = 14;
static const uint32_t XSTOP1_XSTOP1_UNIT11 = 15;
static const uint32_t XSTOP1_XSTOP1_UNIT12 = 16;
static const uint32_t XSTOP1_XSTOP1_UNIT13 = 17;
static const uint32_t XSTOP1_XSTOP1_UNIT14 = 18;
static const uint32_t XSTOP1_XSTOP1_WAIT_CYCLES = 48;
static const uint32_t XSTOP1_XSTOP1_WAIT_CYCLES_LEN = 12;
// mc/reg00002.H

static const uint64_t XSTOP2 = 0x0c03000dull;

static const uint32_t XSTOP2_XSTOP2_MASK_B = 0;
static const uint32_t XSTOP2_ALIGNED_XSTOP2 = 1;
static const uint32_t XSTOP2_TRIGGER_OPCG_ON_XSTOP2 = 2;
static const uint32_t XSTOP2_XSTOP2_WAIT_ALLWAYS = 3;
static const uint32_t XSTOP2_XSTOP2_PERV = 4;
static const uint32_t XSTOP2_XSTOP2_UNIT1 = 5;
static const uint32_t XSTOP2_XSTOP2_UNIT2 = 6;
static const uint32_t XSTOP2_XSTOP2_UNIT3 = 7;
static const uint32_t XSTOP2_XSTOP2_UNIT4 = 8;
static const uint32_t XSTOP2_XSTOP2_UNIT5 = 9;
static const uint32_t XSTOP2_XSTOP2_UNIT6 = 10;
static const uint32_t XSTOP2_XSTOP2_UNIT7 = 11;
static const uint32_t XSTOP2_XSTOP2_UNIT8 = 12;
static const uint32_t XSTOP2_XSTOP2_UNIT9 = 13;
static const uint32_t XSTOP2_XSTOP2_UNIT10 = 14;
static const uint32_t XSTOP2_XSTOP2_UNIT11 = 15;
static const uint32_t XSTOP2_XSTOP2_UNIT12 = 16;
static const uint32_t XSTOP2_XSTOP2_UNIT13 = 17;
static const uint32_t XSTOP2_XSTOP2_UNIT14 = 18;
static const uint32_t XSTOP2_XSTOP2_WAIT_CYCLES = 48;
static const uint32_t XSTOP2_XSTOP2_WAIT_CYCLES_LEN = 12;
// mc/reg00002.H

static const uint64_t XSTOP3 = 0x0c03000eull;

static const uint32_t XSTOP3_XSTOP3_MASK_B = 0;
static const uint32_t XSTOP3_ALIGNED_XSTOP3 = 1;
static const uint32_t XSTOP3_TRIGGER_OPCG_ON_XSTOP3 = 2;
static const uint32_t XSTOP3_XSTOP3_WAIT_ALLWAYS = 3;
static const uint32_t XSTOP3_XSTOP3_PERV = 4;
static const uint32_t XSTOP3_XSTOP3_UNIT1 = 5;
static const uint32_t XSTOP3_XSTOP3_UNIT2 = 6;
static const uint32_t XSTOP3_XSTOP3_UNIT3 = 7;
static const uint32_t XSTOP3_XSTOP3_UNIT4 = 8;
static const uint32_t XSTOP3_XSTOP3_UNIT5 = 9;
static const uint32_t XSTOP3_XSTOP3_UNIT6 = 10;
static const uint32_t XSTOP3_XSTOP3_UNIT7 = 11;
static const uint32_t XSTOP3_XSTOP3_UNIT8 = 12;
static const uint32_t XSTOP3_XSTOP3_UNIT9 = 13;
static const uint32_t XSTOP3_XSTOP3_UNIT10 = 14;
static const uint32_t XSTOP3_XSTOP3_UNIT11 = 15;
static const uint32_t XSTOP3_XSTOP3_UNIT12 = 16;
static const uint32_t XSTOP3_XSTOP3_UNIT13 = 17;
static const uint32_t XSTOP3_XSTOP3_UNIT14 = 18;
static const uint32_t XSTOP3_XSTOP3_WAIT_CYCLES = 48;
static const uint32_t XSTOP3_XSTOP3_WAIT_CYCLES_LEN = 12;
// mc/reg00002.H

static const uint64_t XSTOP_INTERRUPT_REG = 0x0c0f001cull;
// mc/reg00002.H

}
}
#include "mc/reg00000.H"
#include "mc/reg00001.H"
#include "mc/reg00002.H"
#endif
