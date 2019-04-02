/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq.H $           */
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

#ifndef __eq_H_
#define __eq_H_


namespace scomt
{
namespace eq
{


static const uint64_t ASSIST_INTERRUPT_REG = 0x200f0011ull;
// eq/reg00000.H

static const uint64_t ATOMIC_LOCK_REG = 0x200f03ffull;

static const uint32_t ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t ATOMIC_LOCK_REG_ID = 1;
static const uint32_t ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// eq/reg00000.H

static const uint64_t ATTN_INTERRUPT_REG = 0x200f001aull;
// eq/reg00000.H

static const uint64_t BIST = 0x2003000bull;

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
// eq/reg00000.H

static const uint64_t CC_ATOMIC_LOCK_REG = 0x200303ffull;

static const uint32_t CC_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CC_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CC_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CC_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CC_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// eq/reg00000.H

static const uint64_t CC_PROTECT_MODE_REG = 0x200303feull;

static const uint32_t CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// eq/reg00000.H

static const uint64_t CLK_REGION = 0x20030006ull;

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
// eq/reg00000.H

static const uint64_t CLOCK_STAT_ARY = 0x2003000aull;

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
// eq/reg00000.H

static const uint64_t CLOCK_STAT_NSL = 0x20030009ull;

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
// eq/reg00000.H

static const uint64_t CLOCK_STAT_SL = 0x20030008ull;

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
// eq/reg00000.H

static const uint64_t CPLT_CONF0_RW = 0x20000008ull;
static const uint64_t CPLT_CONF0_WO_CLEAR = 0x20000028ull;
static const uint64_t CPLT_CONF0_WO_OR = 0x20000018ull;

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
// eq/reg00000.H

static const uint64_t CPLT_CONF1_RW = 0x20000009ull;
static const uint64_t CPLT_CONF1_WO_CLEAR = 0x20000029ull;
static const uint64_t CPLT_CONF1_WO_OR = 0x20000019ull;

static const uint32_t CPLT_CONF1_TC_AMUX_EQ_VSEL_DC_0H = 0;
static const uint32_t CPLT_CONF1_TC_AMUX_EQ_VSEL_DC_1H = 1;
static const uint32_t CPLT_CONF1_TC_AMUX_EQ_VSEL_DC_2H = 2;
static const uint32_t CPLT_CONF1_TC_AMUX_EQ_VSEL_OCB_MH_DC_3H = 3;
static const uint32_t CPLT_CONF1_TC_AMUX_EQ_VSEL_OCB_MH_DC_4H = 4;
static const uint32_t CPLT_CONF1_TC_AMUX_EQ_VSEL_OCB_MH_DC_5H = 5;
static const uint32_t CPLT_CONF1_TC_AMUX_EQ_VSEL_OCB_MH_DC_6H = 6;
static const uint32_t CPLT_CONF1_TC_AMUX_EQ_VSEL_PWR_DC_7H = 7;
static const uint32_t CPLT_CONF1_TC_AMUX_EQ_VSEL_PWR_DC_8H = 8;
static const uint32_t CPLT_CONF1_TC_AMUX_EQ_VSEL_PWR_DC_9H = 9;
static const uint32_t CPLT_CONF1_TC_AMUX_EQ_VSEL_QUAD_DC_10H = 10;
static const uint32_t CPLT_CONF1_TC_AMUX_EQ_VSEL_QUAD_DC_11H = 11;
static const uint32_t CPLT_CONF1_TC_AMUX_EQ_VSEL_VMEAS_DC = 12;
static const uint32_t CPLT_CONF1_UNUSED_13H = 13;
static const uint32_t CPLT_CONF1_UNUSED_14H = 14;
static const uint32_t CPLT_CONF1_UNUSED_15H = 15;
static const uint32_t CPLT_CONF1_UNUSED_16H = 16;
static const uint32_t CPLT_CONF1_UNUSED_17H = 17;
static const uint32_t CPLT_CONF1_UNUSED_18H = 18;
static const uint32_t CPLT_CONF1_UNUSED_19H = 19;
static const uint32_t CPLT_CONF1_UNUSED_20H = 20;
static const uint32_t CPLT_CONF1_UNUSED_21H = 21;
static const uint32_t CPLT_CONF1_UNUSED_22H = 22;
static const uint32_t CPLT_CONF1_UNUSED_23H = 23;
static const uint32_t CPLT_CONF1_UNUSED_24H = 24;
static const uint32_t CPLT_CONF1_UNUSED_25H = 25;
static const uint32_t CPLT_CONF1_UNUSED_26H = 26;
static const uint32_t CPLT_CONF1_UNUSED_27H = 27;
static const uint32_t CPLT_CONF1_UNUSED_28H = 28;
static const uint32_t CPLT_CONF1_UNUSED_29H = 29;
static const uint32_t CPLT_CONF1_UNUSED_30H = 30;
static const uint32_t CPLT_CONF1_UNUSED_31H = 31;
// eq/reg00000.H

static const uint64_t CPLT_CTRL0_RW = 0x20000000ull;
static const uint64_t CPLT_CTRL0_WO_CLEAR = 0x20000020ull;
static const uint64_t CPLT_CTRL0_WO_OR = 0x20000010ull;

static const uint32_t CPLT_CTRL0_CTRL_CC_ABSTCLK_MUXSEL_DC = 0;
static const uint32_t CPLT_CTRL0_UNUSED_1A = 1;
static const uint32_t CPLT_CTRL0_CTRL_CC_FLUSHMODE_INH = 2;
static const uint32_t CPLT_CTRL0_CTRL_CC_FORCE_ALIGN = 3;
static const uint32_t CPLT_CTRL0_TC_UNIT_ARY_WRT_THRU_DC = 4;
static const uint32_t CPLT_CTRL0_TC_UNIT_AVP_MODE = 5;
static const uint32_t CPLT_CTRL0_TC_CTRL0_BIT6_CHIPLET_ID_DC = 6;
static const uint32_t CPLT_CTRL0_UNUSED_7A = 7;
static const uint32_t CPLT_CTRL0_CTRL_CC_ABIST_RECOV_DISABLE_DC = 8;
static const uint32_t CPLT_CTRL0_UNUSED_9A = 9;
static const uint32_t CPLT_CTRL0_UNUSED_10A = 10;
static const uint32_t CPLT_CTRL0_RESERVED_11A = 11;
static const uint32_t CPLT_CTRL0_UNUSED_12A = 12;
static const uint32_t CPLT_CTRL0_TC_UNIT_DETERMINISTIC_TEST_ENA_DC = 13;
static const uint32_t CPLT_CTRL0_TC_UNIT_CONSTRAIN_SAFESCAN_DC = 14;
static const uint32_t CPLT_CTRL0_UNUSED_15A = 15;
static const uint32_t CPLT_CTRL0_UNUSED_16A = 16;
static const uint32_t CPLT_CTRL0_UNUSED_17A = 17;
static const uint32_t CPLT_CTRL0_RESERVED_18A = 18;
static const uint32_t CPLT_CTRL0_RESERVED_19A = 19;
static const uint32_t CPLT_CTRL0_TC_PSRO_SEL_DC = 20;
static const uint32_t CPLT_CTRL0_TC_PSRO_SEL_DC_LEN = 8;
static const uint32_t CPLT_CTRL0_UNUSED_28A = 28;
static const uint32_t CPLT_CTRL0_UNUSED_29A = 29;
static const uint32_t CPLT_CTRL0_UNUSED_30A = 30;
static const uint32_t CPLT_CTRL0_UNUSED_31A = 31;
static const uint32_t CPLT_CTRL0_UNUSED_32A = 32;
static const uint32_t CPLT_CTRL0_RESERVED_33A = 33;
static const uint32_t CPLT_CTRL0_RESERVED_34A = 34;
static const uint32_t CPLT_CTRL0_RESERVED_35A = 35;
static const uint32_t CPLT_CTRL0_TC_OELCC_EDGE_DELAYED_DC = 36;
static const uint32_t CPLT_CTRL0_TC_OELCC_ALIGN_FLUSH_DC = 37;
static const uint32_t CPLT_CTRL0_RESERVED_38A = 38;
static const uint32_t CPLT_CTRL0_RESERVED_39A = 39;
static const uint32_t CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC = 40;
static const uint32_t CPLT_CTRL0_CTRL_MISC_CLKDIV_SEL_DC_LEN = 2;
static const uint32_t CPLT_CTRL0_RESERVED_42A = 42;
static const uint32_t CPLT_CTRL0_RESERVED_43A = 43;
static const uint32_t CPLT_CTRL0_UNUSED_44A = 44;
static const uint32_t CPLT_CTRL0_UNUSED_45A = 45;
static const uint32_t CPLT_CTRL0_CTRL_CC_SSS_CALIBRATE_DC = 46;
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
// eq/reg00000.H

static const uint64_t CPLT_CTRL1_RW = 0x20000001ull;
static const uint64_t CPLT_CTRL1_WO_CLEAR = 0x20000021ull;
static const uint64_t CPLT_CTRL1_WO_OR = 0x20000011ull;

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
// eq/reg00000.H

static const uint64_t CPLT_CTRL2_RW = 0x20000002ull;
static const uint64_t CPLT_CTRL2_WO_CLEAR = 0x20000022ull;
static const uint64_t CPLT_CTRL2_WO_OR = 0x20000012ull;

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
// eq/reg00000.H

static const uint64_t CPLT_CTRL3_RW = 0x20000003ull;
static const uint64_t CPLT_CTRL3_WO_CLEAR = 0x20000023ull;
static const uint64_t CPLT_CTRL3_WO_OR = 0x20000013ull;

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
// eq/reg00000.H

static const uint64_t CPLT_CTRL4_RW = 0x20000004ull;
static const uint64_t CPLT_CTRL4_WO_CLEAR = 0x20000024ull;
static const uint64_t CPLT_CTRL4_WO_OR = 0x20000014ull;

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
// eq/reg00000.H

static const uint64_t CPLT_CTRL5_RW = 0x20000005ull;
static const uint64_t CPLT_CTRL5_WO_CLEAR = 0x20000025ull;
static const uint64_t CPLT_CTRL5_WO_OR = 0x20000015ull;

static const uint32_t CPLT_CTRL5_TC_REGION_POWER_GATE = 4;
static const uint32_t CPLT_CTRL5_TC_REGION_POWER_GATE_LEN = 15;
// eq/reg00000.H

static const uint64_t CPLT_MASK0 = 0x20000101ull;

static const uint32_t CPLT_MASK0_CPLTMASK0 = 0;
static const uint32_t CPLT_MASK0_CPLTMASK0_LEN = 24;
// eq/reg00000.H

static const uint64_t CPLT_STAT0 = 0x20000100ull;

static const uint32_t CPLT_STAT0_ABIST_DONE_DC = 0;
static const uint32_t CPLT_STAT0_EBIST_DONE_DC = 1;
static const uint32_t CPLT_STAT0_RESERVED_2I = 2;
static const uint32_t CPLT_STAT0_RESERVED_3I = 3;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT0_OUT = 4;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT1_OUT = 5;
static const uint32_t CPLT_STAT0_RESERVED_6I = 6;
static const uint32_t CPLT_STAT0_UNUSED = 7;
static const uint32_t CPLT_STAT0_CC_CTRL_OPCG_DONE_DC = 8;
static const uint32_t CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC = 9;
static const uint32_t CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR = 10;
static const uint32_t CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR = 11;
static const uint32_t CPLT_STAT0_FREE_USAGE_12I = 12;
static const uint32_t CPLT_STAT0_FREE_USAGE_13I = 13;
static const uint32_t CPLT_STAT0_FREE_USAGE_14I = 14;
static const uint32_t CPLT_STAT0_FREE_USAGE_15I = 15;
static const uint32_t CPLT_STAT0_FREE_USAGE_16I = 16;
static const uint32_t CPLT_STAT0_FREE_USAGE_17I = 17;
static const uint32_t CPLT_STAT0_FREE_USAGE_18I = 18;
static const uint32_t CPLT_STAT0_FREE_USAGE_19I = 19;
static const uint32_t CPLT_STAT0_FREE_USAGE_20I = 20;
static const uint32_t CPLT_STAT0_FREE_USAGE_21I = 21;
static const uint32_t CPLT_STAT0_FREE_USAGE_22I = 22;
static const uint32_t CPLT_STAT0_FREE_USAGE_23I = 23;
// eq/reg00000.H

static const uint64_t CTRL_ATOMIC_LOCK_REG = 0x200003ffull;

static const uint32_t CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// eq/reg00000.H

static const uint64_t CTRL_PROTECT_MODE_REG = 0x200003feull;

static const uint32_t CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// eq/reg00000.H

static const uint64_t DBG_CBS_CC = 0x20030013ull;

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
// eq/reg00000.H

static const uint64_t EDRAM_STATUS = 0x200f0029ull;

static const uint32_t EDRAM_STATUS_EDRAM_STAT = 0;
static const uint32_t EDRAM_STATUS_EDRAM_STAT_LEN = 4;
// eq/reg00000.H

static const uint64_t EPS_FIR_GXSTOP0_MASK_REG = 0x20040014ull;

static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_GXSTP0_XSTOP_MASK_IN = 0;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_GXSTP0_XSTOP_MASK_IN_LEN = 12;
// eq/reg00000.H

static const uint64_t EPS_FIR_GXSTOP1_MASK_REG = 0x20040015ull;

static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_GXSTP1_XSTOP_MASK_IN = 0;
static const uint32_t EPS_FIR_GXSTOP1_MASK_REG_GXSTP1_XSTOP_MASK_IN_LEN = 12;
// eq/reg00000.H

static const uint64_t EPS_FIR_GXSTOP2_MASK_REG = 0x20040016ull;

static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_GXSTP2_XSTOP_MASK_IN = 0;
static const uint32_t EPS_FIR_GXSTOP2_MASK_REG_GXSTP2_XSTOP_MASK_IN_LEN = 12;
// eq/reg00000.H

static const uint64_t EPS_FIR_GXSTOP_TRIG_REG = 0x20040013ull;

static const uint32_t EPS_FIR_GXSTOP_TRIG_REG_GXSTP_TRIG_IN = 0;
static const uint32_t EPS_FIR_GXSTOP_TRIG_REG_GXSTP_TRIG_IN_LEN = 12;
// eq/reg00000.H

static const uint64_t EPS_FIR_LOCAL_ACTION0 = 0x20040010ull;

static const uint32_t EPS_FIR_LOCAL_ACTION0_FIR_ACTION0_IN = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION0_FIR_ACTION0_IN_LEN = 49;
// eq/reg00000.H

static const uint64_t EPS_FIR_LOCAL_ACTION1 = 0x20040011ull;

static const uint32_t EPS_FIR_LOCAL_ACTION1_FIR_ACTION1_IN = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION1_FIR_ACTION1_IN_LEN = 49;
// eq/reg00000.H

static const uint64_t EPS_FIR_LOCAL_MASK_RW = 0x2004000dull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_AND = 0x2004000eull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_OR = 0x2004000full;

static const uint32_t EPS_FIR_LOCAL_MASK_LFIR_MASK_IN = 0;
static const uint32_t EPS_FIR_LOCAL_MASK_LFIR_MASK_IN_LEN = 49;
// eq/reg00000.H

static const uint64_t EPS_FIR_MODE_REG = 0x20040008ull;

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
// eq/reg00000.H

static const uint64_t EPS_FIR_SUM_MASK_REG = 0x20040017ull;

static const uint32_t EPS_FIR_SUM_MASK_REG_SMASK_IN = 0;
static const uint32_t EPS_FIR_SUM_MASK_REG_SMASK_IN_LEN = 5;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_CONTROL_REG = 0x20050012ull;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT0 = 0x20050000ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT1 = 0x20050001ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT2 = 0x20050002ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_DTS_TRC_RESULT = 0x20050003ull;

static const uint32_t EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE = 0;
static const uint32_t EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR = 44;
static const uint32_t EPS_THERM_WSUB_DTS_TRC_RESULT_DTS_1_RESULT = 48;
static const uint32_t EPS_THERM_WSUB_DTS_TRC_RESULT_DTS_1_RESULT_LEN = 16;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_ERR_STATUS_REG = 0x20050013ull;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_INJECT_REG = 0x20050011ull;

static const uint32_t EPS_THERM_WSUB_INJECT_REG_TRIP = 0;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_TRIP_LEN = 2;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_MODE = 2;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_MODE_LEN = 2;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG = 0x20050016ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC = 0;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC_LEN = 3;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT = 36;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN = 2;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA0 = 0x20050019ull;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA1 = 0x2005001aull;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA2 = 0x2005001bull;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_SKITTER_FORCE_REG = 0x20050014ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_SKITTER_MODE_REG = 0x20050010ull;

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
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_MODE_REG = 0x2005000full;

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
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ = 0x2005001cull;

static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB2_CONTROL_REG = 0x20050032ull;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB2_DTS_RESULT0 = 0x20050020ull;

static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_2_RESULT_LEN = 16;
// eq/reg00000.H

static const uint64_t EPS_THERM_WSUB2_DTS_RESULT1 = 0x20050021ull;

static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT_LEN = 16;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_DTS_RESULT2 = 0x20050022ull;

static const uint32_t EPS_THERM_WSUB2_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_DTS_TRC_RESULT = 0x20050023ull;

static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR = 44;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT = 48;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT_LEN = 16;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_ERR_STATUS_REG = 0x20050033ull;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_INJECT_REG = 0x20050031ull;

static const uint32_t EPS_THERM_WSUB2_INJECT_REG_TRIP = 0;
static const uint32_t EPS_THERM_WSUB2_INJECT_REG_TRIP_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_INJECT_REG_MODE = 2;
static const uint32_t EPS_THERM_WSUB2_INJECT_REG_MODE_LEN = 2;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG = 0x20050036ull;

static const uint32_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG_CLKSRC = 0;
static const uint32_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG_CLKSRC_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG_DELAY_SELECT = 36;
static const uint32_t EPS_THERM_WSUB2_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN = 2;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_DATA0 = 0x20050039ull;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_DATA1 = 0x2005003aull;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_DATA2 = 0x2005003bull;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_FORCE_REG = 0x20050034ull;

static const uint32_t EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_MODE_REG = 0x20050030ull;

static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE = 0;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_DISABLE_SKITTER_STICKINESS = 1;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_MODE_UNUSED1 = 2;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_MODE_UNUSED1_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL = 4;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL = 6;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS = 8;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE_WITH_TRIGGER = 44;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_DATA_V_LT = 45;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_MODE_REG = 0x2005002full;

static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR = 0;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT = 1;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA = 2;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA = 5;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT = 6;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN = 4;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA = 10;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE = 12;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL = 13;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK = 14;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_MODE_UNUSED = 15;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL = 16;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL_LEN = 4;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1 = 20;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2 = 24;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 = 28;
// eq/reg00001.H

static const uint64_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ = 0x2005003cull;

static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB2_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
// eq/reg00001.H

static const uint64_t ERROR_REG = 0x200f001full;

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
// eq/reg00001.H

static const uint64_t ERROR_STATUS = 0x2003000full;

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
// eq/reg00001.H

static const uint64_t FIR_MASK = 0x20040002ull;

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
static const uint32_t FIR_MASK_13_LEN = 13;
static const uint32_t FIR_MASK_26 = 26;
// eq/reg00001.H

static const uint64_t GSD_GROUPSEL_RWX = 0x200f0005ull;
static const uint64_t GSD_GROUPSEL_RWX_WAND = 0x200f0006ull;
static const uint64_t GSD_GROUPSEL_RWX_WOR = 0x200f0007ull;

static const uint32_t GSD_GROUPSEL_GSD_GROUPSELECT = 0;
static const uint32_t GSD_GROUPSEL_GSD_GROUPSELECT_LEN = 6;
// eq/reg00001.H

static const uint64_t HANG_PULSE_0_REG = 0x200f0020ull;

static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0 = 0;
static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN = 6;
static const uint32_t HANG_PULSE_0_REG_SUPPRESS_HANG_0 = 6;
// eq/reg00001.H

static const uint64_t HANG_PULSE_1_REG = 0x200f0021ull;

static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1 = 0;
static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN = 6;
static const uint32_t HANG_PULSE_1_REG_SUPPRESS_HANG_1 = 6;
// eq/reg00001.H

static const uint64_t HANG_PULSE_2_REG = 0x200f0022ull;

static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2 = 0;
static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN = 6;
static const uint32_t HANG_PULSE_2_REG_SUPPRESS_HANG_2 = 6;
// eq/reg00001.H

static const uint64_t HANG_PULSE_3_REG = 0x200f0023ull;

static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3 = 0;
static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN = 6;
static const uint32_t HANG_PULSE_3_REG_SUPPRESS_HANG_3 = 6;
// eq/reg00001.H

static const uint64_t HANG_PULSE_4_REG = 0x200f0024ull;

static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4 = 0;
static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN = 6;
static const uint32_t HANG_PULSE_4_REG_SUPPRESS_HANG_4 = 6;
// eq/reg00001.H

static const uint64_t HANG_PULSE_5_REG = 0x200f0025ull;

static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5 = 0;
static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN = 6;
static const uint32_t HANG_PULSE_5_REG_SUPPRESS_HANG_5 = 6;
// eq/reg00001.H

static const uint64_t HANG_PULSE_6_REG = 0x200f0026ull;

static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6 = 0;
static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN = 6;
static const uint32_t HANG_PULSE_6_REG_SUPPRESS_HANG_6 = 6;
// eq/reg00001.H

static const uint64_t HEARTBEAT_REG = 0x200f0018ull;

static const uint32_t HEARTBEAT_REG_HEARTBEAT_DEAD = 0;
// eq/reg00001.H

static const uint64_t HOSTATTN = 0x20040009ull;

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
// eq/reg00001.H

static const uint64_t HOSTATTN_MASK = 0x2004001aull;

static const uint32_t HOSTATTN_MASK_HOSTATTN_MASK_IN = 0;
static const uint32_t HOSTATTN_MASK_HOSTATTN_MASK_IN_LEN = 22;
// eq/reg00001.H

static const uint64_t LOCAL_FIR_RWX = 0x2004000aull;
static const uint64_t LOCAL_FIR_WOX_AND = 0x2004000bull;
static const uint64_t LOCAL_FIR_WOX_OR = 0x2004000cull;

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
// eq/reg00001.H

static const uint64_t LOCAL_XSTOP_ERR = 0x20040018ull;

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
// eq/reg00001.H

static const uint64_t LOCAL_XSTOP_MASK = 0x20040019ull;

static const uint32_t LOCAL_XSTOP_MASK_LOCAL_XSTOP_MASK_IN = 0;
static const uint32_t LOCAL_XSTOP_MASK_LOCAL_XSTOP_MASK_IN_LEN = 22;
// eq/reg00001.H

static const uint64_t MULTICAST_GROUP_1 = 0x200f0001ull;

static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
// eq/reg00001.H

static const uint64_t MULTICAST_GROUP_2 = 0x200f0002ull;

static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// eq/reg00001.H

static const uint64_t MULTICAST_GROUP_3 = 0x200f0003ull;

static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP = 3;
static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN = 3;
// eq/reg00001.H

static const uint64_t MULTICAST_GROUP_4 = 0x200f0004ull;

static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP = 3;
static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN = 3;
// eq/reg00001.H

static const uint64_t NET_CTRL0_RWX = 0x200f0040ull;
static const uint64_t NET_CTRL0_RWX_WAND = 0x200f0041ull;
static const uint64_t NET_CTRL0_RWX_WOR = 0x200f0042ull;

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
// eq/reg00001.H

static const uint64_t NET_CTRL1_RWX = 0x200f0044ull;
static const uint64_t NET_CTRL1_RWX_WAND = 0x200f0045ull;
static const uint64_t NET_CTRL1_RWX_WOR = 0x200f0046ull;

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
// eq/reg00001.H

static const uint64_t OPCG_ALIGN = 0x20030001ull;

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
// eq/reg00001.H

static const uint64_t OPCG_CAPT1 = 0x20030010ull;

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
// eq/reg00001.H

static const uint64_t OPCG_CAPT2 = 0x20030011ull;

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
// eq/reg00001.H

static const uint64_t OPCG_CAPT3 = 0x20030012ull;

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
// eq/reg00001.H

static const uint64_t OPCG_REG0 = 0x20030002ull;

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
// eq/reg00001.H

static const uint64_t OPCG_REG1 = 0x20030003ull;

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
// eq/reg00001.H

static const uint64_t OPCG_REG2 = 0x20030004ull;

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
// eq/reg00001.H

static const uint64_t PCB_OPCG_GO = 0x20030020ull;

static const uint32_t PCB_OPCG_GO_PCB_OPCGGO = 0;
// eq/reg00001.H

static const uint64_t PCB_OPCG_STOP = 0x20030030ull;

static const uint32_t PCB_OPCG_STOP_PCB_OPCGSTOP = 0;
// eq/reg00001.H

static const uint64_t PHASE_COUNTER_RESET = 0x20030028ull;

static const uint32_t PHASE_COUNTER_RESET_PHASECOUNTER_RESET = 0;
// eq/reg00001.H

static const uint64_t PLL_LOCK_REG = 0x200f0019ull;
// eq/reg00001.H

static const uint64_t PRE_COUNTER_REG = 0x200f0028ull;

static const uint32_t PRE_COUNTER_REG_PRE_COUNTER = 0;
static const uint32_t PRE_COUNTER_REG_PRE_COUNTER_LEN = 8;
// eq/reg00001.H

static const uint64_t PRIMARY_ADDRESS_REG = 0x200f0000ull;
// eq/reg00001.H

static const uint64_t PROTECT_MODE_REG = 0x200f03feull;

static const uint32_t PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// eq/reg00001.H

static const uint64_t QME_BCEBAR0 = 0x200e0060ull;

static const uint32_t QME_BCEBAR0_BASE = 8;
static const uint32_t QME_BCEBAR0_BASE_LEN = 36;
static const uint32_t QME_BCEBAR0_SIZE = 61;
static const uint32_t QME_BCEBAR0_SIZE_LEN = 3;
// eq/reg00002.H

static const uint64_t QME_BCEBAR1 = 0x200e0064ull;

static const uint32_t QME_BCEBAR1_BASE = 8;
static const uint32_t QME_BCEBAR1_BASE_LEN = 36;
static const uint32_t QME_BCEBAR1_SIZE = 61;
static const uint32_t QME_BCEBAR1_SIZE_LEN = 3;
// eq/reg00002.H

static const uint64_t QME_BCECSR = 0x200e0068ull;

static const uint32_t QME_BCECSR_BUSY = 0;
static const uint32_t QME_BCECSR_ERROR = 1;
static const uint32_t QME_BCECSR_RNW = 4;
static const uint32_t QME_BCECSR_BARSEL = 5;
static const uint32_t QME_BCECSR_PRIORITY = 6;
static const uint32_t QME_BCECSR_INJECT_ERR = 7;
static const uint32_t QME_BCECSR_TYPE = 13;
static const uint32_t QME_BCECSR_TYPE_LEN = 3;
static const uint32_t QME_BCECSR_NUM_BLOCKS = 17;
static const uint32_t QME_BCECSR_NUM_BLOCKS_LEN = 11;
static const uint32_t QME_BCECSR_SBASE = 28;
static const uint32_t QME_BCECSR_SBASE_LEN = 12;
static const uint32_t QME_BCECSR_MBASE = 42;
static const uint32_t QME_BCECSR_MBASE_LEN = 22;
// eq/reg00002.H

static const uint64_t QME_DB0 = 0x200e0100ull;

static const uint32_t QME_DB0_NUMBER = 0;
static const uint32_t QME_DB0_NUMBER_LEN = 8;
static const uint32_t QME_DB0_DATA = 8;
static const uint32_t QME_DB0_DATA_LEN = 56;
// eq/reg00002.H

static const uint64_t QME_DB1 = 0x200e0104ull;

static const uint32_t QME_DB1_NUMBER = 0;
static const uint32_t QME_DB1_NUMBER_LEN = 8;
static const uint32_t QME_DB1_DATA = 8;
static const uint32_t QME_DB1_DATA_LEN = 56;
// eq/reg00002.H

static const uint64_t QME_DB2 = 0x200e0108ull;

static const uint32_t QME_DB2_QME_DB2_MESSAGE_NUMBER = 0;
static const uint32_t QME_DB2_QME_DB2_MESSAGE_NUMBER_LEN = 8;
// eq/reg00002.H

static const uint64_t QME_DERP = 0x200e0250ull;

static const uint32_t QME_DERP_DEND = 0;
static const uint32_t QME_DERP_DEND_LEN = 32;
static const uint32_t QME_DERP_SOR = 32;
static const uint32_t QME_DERP_SOR_LEN = 32;
// eq/reg00002.H

static const uint64_t QME_DORP = 0x200e0254ull;

static const uint32_t QME_DORP_QUOTIENT = 0;
static const uint32_t QME_DORP_QUOTIENT_LEN = 32;
static const uint32_t QME_DORP_REMAINDER = 32;
static const uint32_t QME_DORP_REMAINDER_LEN = 32;
// eq/reg00002.H

static const uint64_t QME_EIMR_RW = 0x200e0264ull;
static const uint64_t QME_EIMR_WO_CLEAR = 0x200e0267ull;
static const uint64_t QME_EIMR_WO_OR = 0x200e0266ull;

static const uint32_t QME_EIMR_QME_EIMR_INTERRUPT_MASK = 0;
static const uint32_t QME_EIMR_QME_EIMR_INTERRUPT_MASK_LEN = 64;
// eq/reg00002.H

static const uint64_t QME_EINR = 0x200e0274ull;

static const uint32_t QME_EINR_QME_EINR_INTERRUPT_INPUT = 0;
static const uint32_t QME_EINR_QME_EINR_INTERRUPT_INPUT_LEN = 64;
// eq/reg00002.H

static const uint64_t QME_EIPR_RW = 0x200e0268ull;
static const uint64_t QME_EIPR_WO_CLEAR = 0x200e026bull;
static const uint64_t QME_EIPR_WO_OR = 0x200e026aull;

static const uint32_t QME_EIPR_QME_EIPR_INTERRUPT_POLARITY = 0;
static const uint32_t QME_EIPR_QME_EIPR_INTERRUPT_POLARITY_LEN = 64;
// eq/reg00002.H

static const uint64_t QME_EISR_RWX = 0x200e0260ull;
static const uint64_t QME_EISR_WOX_CLEAR = 0x200e0263ull;
static const uint64_t QME_EISR_WOX_OR = 0x200e0262ull;

static const uint32_t QME_EISR_DEBUGGER = 0;
static const uint32_t QME_EISR_DEBUG_TRIGGER = 1;
static const uint32_t QME_EISR_QUAD_CHECKSTOP = 2;
static const uint32_t QME_EISR_LFIR_INDICATION = 3;
static const uint32_t QME_EISR_SPARE4 = 4;
static const uint32_t QME_EISR_SPARE5 = 5;
static const uint32_t QME_EISR_SPARE6 = 6;
static const uint32_t QME_EISR_SPARE7 = 7;
static const uint32_t QME_EISR_BCE_BUSY = 8;
static const uint32_t QME_EISR_RS4_BUSY = 9;
static const uint32_t QME_EISR_RESCLK_TARGET_ASSIST = 10;
static const uint32_t QME_EISR_RESCLK_DONE_ASSIST = 11;
static const uint32_t QME_EISR_SPARE_12_13 = 12;
static const uint32_t QME_EISR_SPARE_12_13_LEN = 2;
static const uint32_t QME_EISR_TBR_CYCLES_ROLLED = 14;
static const uint32_t QME_EISR_TBR_TIMEBASE_ROLLED = 15;
static const uint32_t QME_EISR_DOORBELL_0 = 16;
static const uint32_t QME_EISR_DOORBELL_1 = 17;
static const uint32_t QME_EISR_DOORBELL_2 = 18;
static const uint32_t QME_EISR_PMCR_UPDATE = 19;
static const uint32_t QME_EISR_DOORBELL_A = 20;
static const uint32_t QME_EISR_DOORBELL_A_LEN = 4;
static const uint32_t QME_EISR_DOORBELL_B = 24;
static const uint32_t QME_EISR_DOORBELL_B_LEN = 4;
static const uint32_t QME_EISR_MMA_ACTIVE = 28;
static const uint32_t QME_EISR_MMA_ACTIVE_LEN = 4;
static const uint32_t QME_EISR_SPC_WKUP_RISE = 32;
static const uint32_t QME_EISR_SPC_WKUP_RISE_LEN = 4;
static const uint32_t QME_EISR_SPC_WKUP_FALL = 36;
static const uint32_t QME_EISR_SPC_WKUP_FALL_LEN = 4;
static const uint32_t QME_EISR_REG_WKUP_HIPRI = 40;
static const uint32_t QME_EISR_REG_WKUP_HIPRI_LEN = 4;
static const uint32_t QME_EISR_REG_WKUP_LOPRI = 44;
static const uint32_t QME_EISR_REG_WKUP_LOPRI_LEN = 4;
static const uint32_t QME_EISR_PM_STATE_ACTIVE_HIPRI = 48;
static const uint32_t QME_EISR_PM_STATE_ACTIVE_HIPRI_LEN = 4;
static const uint32_t QME_EISR_PM_STATE_ACTIVE_LOPRI = 52;
static const uint32_t QME_EISR_PM_STATE_ACTIVE_LOPRI_LEN = 4;
static const uint32_t QME_EISR_CPMS_INTERRUPT0 = 56;
static const uint32_t QME_EISR_CPMS_INTERRUPT0_LEN = 4;
static const uint32_t QME_EISR_CPMS_INTERRUPT1 = 60;
static const uint32_t QME_EISR_CPMS_INTERRUPT1_LEN = 4;
// eq/reg00002.H

static const uint64_t QME_EISTR = 0x200e0270ull;
// eq/reg00002.H

static const uint64_t QME_EITR_RW = 0x200e026cull;
static const uint64_t QME_EITR_WO_CLEAR = 0x200e026full;
static const uint64_t QME_EITR_WO_OR = 0x200e026eull;

static const uint32_t QME_EITR_QME_EITR_INTERRUPT_TYPE = 0;
static const uint32_t QME_EITR_QME_EITR_INTERRUPT_TYPE_LEN = 64;
// eq/reg00002.H

static const uint64_t QME_ERR = 0x200e0010ull;

static const uint32_t QME_ERR_PPE_INTERNAL_ERROR = 0;
static const uint32_t QME_ERR_PPE_EXTERNAL_ERROR = 1;
static const uint32_t QME_ERR_PPE_PROGRESS_ERROR = 2;
static const uint32_t QME_ERR_PPE_BREAKPOINT_ERROR = 3;
static const uint32_t QME_ERR_RESCLK_FREEZE = 4;
static const uint32_t QME_ERR_RESCLK_FREEZE_LEN = 4;
static const uint32_t QME_ERR_SPECIAL_WKUP_PROTOCOL_ERR = 8;
static const uint32_t QME_ERR_SPECIAL_WKUP_PROTOCOL_ERR_LEN = 4;
static const uint32_t QME_ERR_SPECIAL_WKUP_DONE_WINDOW = 12;
static const uint32_t QME_ERR_SPECIAL_WKUP_DONE_WINDOW_LEN = 4;
static const uint32_t QME_ERR_DISABLED_INTR = 16;
static const uint32_t QME_ERR_DISABLED_INTR_LEN = 4;
static const uint32_t QME_ERR_DECONFIGURED_INTR = 20;
static const uint32_t QME_ERR_DECONFIGURED_INTR_LEN = 4;
static const uint32_t QME_ERR_CTFS_ERR = 24;
static const uint32_t QME_ERR_CTFS_ERR_LEN = 4;
static const uint32_t QME_ERR_CPMS_ERR = 28;
static const uint32_t QME_ERR_CPMS_ERR_LEN = 4;
static const uint32_t QME_ERR_PCB_ENDPOINT_RESET = 32;
static const uint32_t QME_ERR_PCB_NETWORK_RESET = 33;
static const uint32_t QME_ERR_PIG_PENDING_SOURCE_LOST = 34;
static const uint32_t QME_ERR_PIG_PENDING_SOURCE_LOST_LEN = 6;
static const uint32_t QME_ERR_SPARE = 40;
static const uint32_t QME_ERR_SPARE_LEN = 4;
// eq/reg00002.H

static const uint64_t QME_FLAGS_RW = 0x200e0120ull;
static const uint64_t QME_FLAGS_WO_CLEAR = 0x200e0123ull;
static const uint64_t QME_FLAGS_WO_OR = 0x200e0122ull;

static const uint32_t QME_FLAGS_QME_FLAGS_DATA = 0;
static const uint32_t QME_FLAGS_QME_FLAGS_DATA_LEN = 64;
// eq/reg00002.H

static const uint64_t QME_LFIR_RWX = 0x200e0000ull;
static const uint64_t QME_LFIR_WOX_AND = 0x200e0001ull;
static const uint64_t QME_LFIR_WOX_OR = 0x200e0002ull;

static const uint32_t QME_LFIR_PPE_HALT_ERROR = 0;
static const uint32_t QME_LFIR_DEBUG_TRIGGER = 1;
static const uint32_t QME_LFIR_SPARE_TRIGGER = 2;
static const uint32_t QME_LFIR_PPE_WATCHDOG = 3;
static const uint32_t QME_LFIR_LOCAL_PCB_TIMEOUT = 4;
static const uint32_t QME_LFIR_FABRIC_ERROR = 5;
static const uint32_t QME_LFIR_SRAM_UE = 6;
static const uint32_t QME_LFIR_SRAM_CE = 7;
static const uint32_t QME_LFIR_RESCLK_ARRAY_PARITY_ERR = 8;
static const uint32_t QME_LFIR_PCB_INTERRUPT_PROTOCOL_ERR = 9;
static const uint32_t QME_LFIR_SRAM_SCRUB_ERR = 10;
static const uint32_t QME_LFIR_CTFS_ERR = 11;
static const uint32_t QME_LFIR_CPMS_ERR = 12;
static const uint32_t QME_LFIR_PGPE_HEARTBEAT_LOST = 13;
static const uint32_t QME_LFIR_BCE_TIMEOUT = 14;
static const uint32_t QME_LFIR_RESCLK_PROTOCOL_ERR = 15;
static const uint32_t QME_LFIR_PCB_RESET_WHEN_ACTIVE = 16;
static const uint32_t QME_LFIR_SPECIAL_WKUP_PROTOCOL_ERR = 17;
static const uint32_t QME_LFIR_SPECIAL_WKUP_DONE_WINDOW = 18;
static const uint32_t QME_LFIR_DISABLED_INTR = 19;
static const uint32_t QME_LFIR_DECONFIGURED_INTR = 20;
static const uint32_t QME_LFIR_RS4_TIMEOUT = 21;
static const uint32_t QME_LFIR_SPARE22 = 22;
static const uint32_t QME_LFIR_SPARE23 = 23;
static const uint32_t QME_LFIR_SPARE24 = 24;
static const uint32_t QME_LFIR_FIR_PARITY_ERR_DUP = 25;
static const uint32_t QME_LFIR_FIR_PARITY_ERR = 26;
// eq/reg00002.H

static const uint64_t QME_LFIRACT0 = 0x200e0008ull;

static const uint32_t QME_LFIRACT0_QME_LFIRACT0_FIR_ACTION1 = 0;
static const uint32_t QME_LFIRACT0_QME_LFIRACT0_FIR_ACTION1_LEN = 27;
// eq/reg00002.H

static const uint64_t QME_LFIRACT1 = 0x200e000cull;

static const uint32_t QME_LFIRACT1_QME_LFIRACT1_FIR_ACTION1 = 0;
static const uint32_t QME_LFIRACT1_QME_LFIRACT1_FIR_ACTION1_LEN = 27;
// eq/reg00002.H

static const uint64_t QME_LFIRMASK_RWX = 0x200e0004ull;
static const uint64_t QME_LFIRMASK_WOX_AND = 0x200e0005ull;
static const uint64_t QME_LFIRMASK_WOX_OR = 0x200e0006ull;

static const uint32_t QME_LFIRMASK_QME_LFIRMASK_FIR_MASK = 0;
static const uint32_t QME_LFIRMASK_QME_LFIRMASK_FIR_MASK_LEN = 27;
// eq/reg00002.H

static const uint64_t QME_PBCR_RW = 0x200e0044ull;
static const uint64_t QME_PBCR_WO_CLEAR = 0x200e0047ull;
static const uint64_t QME_PBCR_WO_OR = 0x200e0046ull;
// eq/reg00002.H

static const uint64_t QME_PCBQBI = 0x200e003cull;

static const uint32_t QME_PCBQBI_ENTRY_VALID = 0;
static const uint32_t QME_PCBQBI_MERGING_SCHEME = 2;
static const uint32_t QME_PCBQBI_MERGING_SCHEME_LEN = 3;
static const uint32_t QME_PCBQBI_R_NW = 8;
static const uint32_t QME_PCBQBI_PORT = 12;
static const uint32_t QME_PCBQBI_PORT_LEN = 4;
static const uint32_t QME_PCBQBI_ADDR = 16;
static const uint32_t QME_PCBQBI_ADDR_LEN = 16;
// eq/reg00002.H

static const uint64_t QME_PCBSID = 0x200e0034ull;
// eq/reg00002.H

static const uint64_t QME_PCBSII = 0x200e0038ull;
// eq/reg00002.H

static const uint64_t QME_PIG = 0x200e0030ull;

static const uint32_t QME_PIG_REQ_INTR_TYPE = 1;
static const uint32_t QME_PIG_REQ_INTR_TYPE_LEN = 4;
static const uint32_t QME_PIG_REQ_INTR_PAYLOAD = 5;
static const uint32_t QME_PIG_REQ_INTR_PAYLOAD_LEN = 19;
static const uint32_t QME_PIG_PENDING_SOURCE = 24;
static const uint32_t QME_PIG_PENDING_SOURCE_LEN = 6;
static const uint32_t QME_PIG_INTR_GRANTED = 32;
static const uint32_t QME_PIG_GRANTED_SOURCE = 33;
static const uint32_t QME_PIG_GRANTED_SOURCE_LEN = 3;
static const uint32_t QME_PIG_QUAD_ID = 37;
static const uint32_t QME_PIG_QUAD_ID_LEN = 3;
static const uint32_t QME_PIG_GRANTED_PACKET = 40;
static const uint32_t QME_PIG_GRANTED_PACKET_LEN = 24;
// eq/reg00002.H

static const uint64_t QME_PLSR = 0x200e0148ull;
// eq/reg00002.H

static const uint64_t QME_PPEBAR = 0x200e0050ull;

static const uint32_t QME_PPEBAR_BASE = 8;
static const uint32_t QME_PPEBAR_BASE_LEN = 36;
static const uint32_t QME_PPEBAR_SIZE = 61;
static const uint32_t QME_PPEBAR_SIZE_LEN = 3;
// eq/reg00002.H

static const uint64_t QME_PPEDBG_RW = 0x200e0244ull;
static const uint64_t QME_PPEDBG_WO_CLEAR = 0x200e0247ull;
static const uint64_t QME_PPEDBG_WO_OR = 0x200e0246ull;

static const uint32_t QME_PPEDBG_EN_DBG = 0;
static const uint32_t QME_PPEDBG_HALT_ON_XSTOP = 1;
static const uint32_t QME_PPEDBG_HALT_ON_TRIG = 2;
static const uint32_t QME_PPEDBG_EN_COVERAGE_MODE = 3;
static const uint32_t QME_PPEDBG_EN_INTR_ADDR = 4;
static const uint32_t QME_PPEDBG_EN_TRACE_EXTRA = 5;
static const uint32_t QME_PPEDBG_EN_TRACE_STALL = 6;
static const uint32_t QME_PPEDBG_EN_WAIT_CYCLES = 7;
static const uint32_t QME_PPEDBG_EN_FULL_SPEED = 8;
static const uint32_t QME_PPEDBG_DIS_FLOW_CHANGE = 9;
static const uint32_t QME_PPEDBG_TRACE_MODE_SEL = 10;
static const uint32_t QME_PPEDBG_TRACE_MODE_SEL_LEN = 2;
static const uint32_t QME_PPEDBG_FIR_TRIGGER = 16;
static const uint32_t QME_PPEDBG_MIB_GPIO = 17;
static const uint32_t QME_PPEDBG_MIB_GPIO_LEN = 3;
static const uint32_t QME_PPEDBG_TRACE_DATA_SEL = 20;
static const uint32_t QME_PPEDBG_TRACE_DATA_SEL_LEN = 4;
// eq/reg00002.H

static const uint64_t QME_PSREQ = 0x200e0130ull;

static const uint32_t QME_PSREQ_CORE_PARTIAL_GOOD = 48;
static const uint32_t QME_PSREQ_CORE_PARTIAL_GOOD_LEN = 4;
static const uint32_t QME_PSREQ_AUTO_PMCR_UPDATE = 52;
static const uint32_t QME_PSREQ_PMCR_RECENT_MODE = 53;
// eq/reg00002.H

static const uint64_t QME_PSSUM = 0x200e0134ull;

static const uint32_t QME_PSSUM_CORE_PARTIAL_GOOD = 48;
static const uint32_t QME_PSSUM_CORE_PARTIAL_GOOD_LEN = 4;
static const uint32_t QME_PSSUM_AUTO_PMCR_UPDATE = 52;
static const uint32_t QME_PSSUM_PMCR_RECENT_MODE = 53;
// eq/reg00002.H

static const uint64_t QME_PTSR = 0x200e013cull;
// eq/reg00002.H

static const uint64_t QME_QHB = 0x200e0080ull;

static const uint32_t QME_QHB_COUNT = 0;
static const uint32_t QME_QHB_COUNT_LEN = 16;
static const uint32_t QME_QHB_ENABLE = 16;
static const uint32_t QME_QHB_LOSS_THROTTLE_ENABLE = 17;
// eq/reg00002.H

static const uint64_t QME_QMCR_SCOM = 0x200e0088ull;
static const uint64_t QME_QMCR_SCOM1 = 0x200e008bull;
static const uint64_t QME_QMCR_SCOM2 = 0x200e008aull;

static const uint32_t QME_QMCR_PMCR_OVERRIDE_EN = 0;
static const uint32_t QME_QMCR_PSCR_OVERRIDE_EN = 1;
static const uint32_t QME_QMCR_CHAR_REGS_READ_ENABLE = 2;
static const uint32_t QME_QMCR_BCECSR_OVERRIDE_EN = 3;
static const uint32_t QME_QMCR_PSREQ_SCOM_READ_EN = 4;
static const uint32_t QME_QMCR_LOCK_PCB_ON_ERR = 5;
static const uint32_t QME_QMCR_STOP_OVERRIDE_MODE = 6;
static const uint32_t QME_QMCR_STOP_ACTIVE_MASK = 7;
static const uint32_t QME_QMCR_AUTO_PMCR_UPDATE = 8;
static const uint32_t QME_QMCR_PMCR_RECENT_MODE = 9;
static const uint32_t QME_QMCR_FUSED_CORE_PAIR_MODE = 10;
static const uint32_t QME_QMCR_CYCLE_REPRO_MODE = 11;
static const uint32_t QME_QMCR_QUEUED_WR_EN = 12;
static const uint32_t QME_QMCR_QUEUED_RD_EN = 13;
static const uint32_t QME_QMCR_LOPRI_STOP_WKUP_SEL = 16;
static const uint32_t QME_QMCR_LOPRI_STOP_WKUP_SEL_LEN = 4;
static const uint32_t QME_QMCR_LOPRI_STOP_ENTRY_SEL = 20;
static const uint32_t QME_QMCR_LOPRI_STOP_ENTRY_SEL_LEN = 4;
static const uint32_t QME_QMCR_WRITE_PROTECT_ENABLE = 24;
static const uint32_t QME_QMCR_SPARE_24_29 = 25;
static const uint32_t QME_QMCR_SPARE_24_29_LEN = 5;
static const uint32_t QME_QMCR_CPMS_PG_CLKOFF_DISABLE = 30;
static const uint32_t QME_QMCR_CTFS_PG_CLKOFF_DISABLE = 31;
static const uint32_t QME_QMCR_FUSED_CORE_MODE = 47;
static const uint32_t QME_QMCR_CORE_PARTIAL_GOOD = 60;
static const uint32_t QME_QMCR_CORE_PARTIAL_GOOD_LEN = 4;
// eq/reg00002.H

static const uint64_t QME_QSAR = 0x200e0074ull;
// eq/reg00002.H

static const uint64_t QME_QSCR_SCOM = 0x200e0070ull;
static const uint64_t QME_QSCR_SCOM1 = 0x200e0073ull;
static const uint64_t QME_QSCR_SCOM2 = 0x200e0072ull;
// eq/reg00002.H

static const uint64_t QME_QSDR = 0x200e0078ull;

static const uint32_t QME_QSDR_QME_QSDR_SRAM_DATA = 0;
static const uint32_t QME_QSDR_QME_QSDR_SRAM_DATA_LEN = 64;
// eq/reg00002.H

static const uint64_t QME_RCIMR = 0x200e018cull;

static const uint32_t QME_RCIMR_P0 = 0;
static const uint32_t QME_RCIMR_P0_LEN = 8;
static const uint32_t QME_RCIMR_X0 = 11;
static const uint32_t QME_RCIMR_X0_LEN = 5;
static const uint32_t QME_RCIMR_P1 = 16;
static const uint32_t QME_RCIMR_P1_LEN = 8;
static const uint32_t QME_RCIMR_X1 = 27;
static const uint32_t QME_RCIMR_X1_LEN = 5;
static const uint32_t QME_RCIMR_P2 = 32;
static const uint32_t QME_RCIMR_P2_LEN = 8;
static const uint32_t QME_RCIMR_X2 = 43;
static const uint32_t QME_RCIMR_X2_LEN = 5;
static const uint32_t QME_RCIMR_P3 = 48;
static const uint32_t QME_RCIMR_P3_LEN = 8;
static const uint32_t QME_RCIMR_X3 = 59;
static const uint32_t QME_RCIMR_X3_LEN = 5;
// eq/reg00002.H

static const uint64_t QME_RCMR_SCOM = 0x200e0180ull;
static const uint64_t QME_RCMR_SCOM1 = 0x200e0183ull;
static const uint64_t QME_RCMR_SCOM2 = 0x200e0182ull;

static const uint32_t QME_RCMR_MR_STEP_ENABLE = 0;
static const uint32_t QME_RCMR_MR_AUTO_ACK_ENABLE = 1;
static const uint32_t QME_RCMR_MR_AUTO_TARGET_DISABLE = 2;
static const uint32_t QME_RCMR_MR_AUTO_DONE_DISABLE = 3;
static const uint32_t QME_RCMR_MR_STEP_DELAY = 4;
static const uint32_t QME_RCMR_MR_STEP_DELAY_LEN = 4;
static const uint32_t QME_RCMR_SCR_CORE_CHANGE_ERROR = 8;
static const uint32_t QME_RCMR_SCR_CORE_CHANGE_ERROR_LEN = 4;
static const uint32_t QME_RCMR_MR_CORE0_CONTROL_INDEX = 35;
static const uint32_t QME_RCMR_MR_CORE0_CONTROL_INDEX_LEN = 5;
static const uint32_t QME_RCMR_MR_CORE1_CONTROL_INDEX = 43;
static const uint32_t QME_RCMR_MR_CORE1_CONTROL_INDEX_LEN = 5;
static const uint32_t QME_RCMR_MR_CORE2_CONTROL_INDEX = 51;
static const uint32_t QME_RCMR_MR_CORE2_CONTROL_INDEX_LEN = 5;
static const uint32_t QME_RCMR_MR_CORE3_CONTROL_INDEX = 59;
static const uint32_t QME_RCMR_MR_CORE3_CONTROL_INDEX_LEN = 5;
// eq/reg00002.H

static const uint64_t QME_RCOCR = 0x200e017cull;

static const uint32_t QME_RCOCR_0_RESCLK_CONTROL = 0;
static const uint32_t QME_RCOCR_0_RESCLK_CONTROL_LEN = 8;
static const uint32_t QME_RCOCR_1_RESCLK_CONTROL = 8;
static const uint32_t QME_RCOCR_1_RESCLK_CONTROL_LEN = 8;
static const uint32_t QME_RCOCR_2_RESCLK_CONTROL = 16;
static const uint32_t QME_RCOCR_2_RESCLK_CONTROL_LEN = 8;
static const uint32_t QME_RCOCR_3_RESCLK_CONTROL = 24;
static const uint32_t QME_RCOCR_3_RESCLK_CONTROL_LEN = 8;
static const uint32_t QME_RCOCR_0_RESCLK_ACTUAL = 32;
static const uint32_t QME_RCOCR_0_RESCLK_ACTUAL_LEN = 8;
static const uint32_t QME_RCOCR_1_RESCLK_ACTUAL = 40;
static const uint32_t QME_RCOCR_1_RESCLK_ACTUAL_LEN = 8;
static const uint32_t QME_RCOCR_2_RESCLK_ACTUAL = 48;
static const uint32_t QME_RCOCR_2_RESCLK_ACTUAL_LEN = 8;
static const uint32_t QME_RCOCR_3_RESCLK_ACTUAL = 56;
static const uint32_t QME_RCOCR_3_RESCLK_ACTUAL_LEN = 8;
// eq/reg00002.H

static const uint64_t QME_RCPTR = 0x200e0188ull;

static const uint32_t QME_RCPTR_TARGET_PSTATE = 0;
static const uint32_t QME_RCPTR_TARGET_PSTATE_LEN = 8;
static const uint32_t QME_RCPTR_PSTATE_ACK_PENDING = 8;
static const uint32_t QME_RCPTR_TARGET_INDEX = 59;
static const uint32_t QME_RCPTR_TARGET_INDEX_LEN = 5;
// eq/reg00002.H

static const uint64_t QME_RCSCR_SCOM = 0x200e0184ull;
static const uint64_t QME_RCSCR_SCOM1 = 0x200e0187ull;
static const uint64_t QME_RCSCR_SCOM2 = 0x200e0186ull;

static const uint32_t QME_RCSCR__OFF_REQ = 0;
static const uint32_t QME_RCSCR__OFF_REQ_LEN = 4;
static const uint32_t QME_RCSCR__CHANGE_DONE = 4;
static const uint32_t QME_RCSCR__CHANGE_DONE_LEN = 4;
static const uint32_t QME_RCSCR__CHANGE_ACTIVE = 8;
static const uint32_t QME_RCSCR__CHANGE_ACTIVE_LEN = 4;
static const uint32_t QME_RCSCR__PARTIAL_GOOD = 12;
static const uint32_t QME_RCSCR__PARTIAL_GOOD_LEN = 4;
static const uint32_t QME_RCSCR__CHANGE_ERROR = 16;
static const uint32_t QME_RCSCR__CHANGE_ERROR_LEN = 4;
static const uint32_t QME_RCSCR_0_TARGET_INDEX = 35;
static const uint32_t QME_RCSCR_0_TARGET_INDEX_LEN = 5;
static const uint32_t QME_RCSCR_1_TARGET_INDEX = 43;
static const uint32_t QME_RCSCR_1_TARGET_INDEX_LEN = 5;
static const uint32_t QME_RCSCR_2_TARGET_INDEX = 51;
static const uint32_t QME_RCSCR_2_TARGET_INDEX_LEN = 5;
static const uint32_t QME_RCSCR_3_TARGET_INDEX = 59;
static const uint32_t QME_RCSCR_3_TARGET_INDEX_LEN = 5;
// eq/reg00002.H

static const uint64_t QME_RCTAR0 = 0x200e0190ull;

static const uint32_t QME_RCTAR0_QME_RCTAR0_DATA = 0;
static const uint32_t QME_RCTAR0_QME_RCTAR0_DATA_LEN = 64;
// eq/reg00002.H

static const uint64_t QME_RCTAR1 = 0x200e0194ull;

static const uint32_t QME_RCTAR1_QME_RCTAR1_DATA = 0;
static const uint32_t QME_RCTAR1_QME_RCTAR1_DATA_LEN = 64;
// eq/reg00002.H

static const uint64_t QME_RCTAR2 = 0x200e0198ull;

static const uint32_t QME_RCTAR2_QME_RCTAR2_DATA = 0;
static const uint32_t QME_RCTAR2_QME_RCTAR2_DATA_LEN = 64;
// eq/reg00002.H

static const uint64_t QME_RCTAR3 = 0x200e019cull;

static const uint32_t QME_RCTAR3_QME_RCTAR3_DATA = 0;
static const uint32_t QME_RCTAR3_QME_RCTAR3_DATA_LEN = 64;
// eq/reg00002.H

static const uint64_t QME_RS4BAR = 0x200e0160ull;

static const uint32_t QME_RS4BAR_QME_RS4BAR_BASE = 0;
static const uint32_t QME_RS4BAR_QME_RS4BAR_BASE_LEN = 32;
// eq/reg00002.H

static const uint64_t QME_RS4CSR = 0x200e0168ull;

static const uint32_t QME_RS4CSR_BUSY = 0;
static const uint32_t QME_RS4CSR_ERROR = 1;
static const uint32_t QME_RS4CSR_SCAN_MODE_OVERRIDE = 5;
static const uint32_t QME_RS4CSR_SCAN_MODE_OVERRIDE_LEN = 2;
static const uint32_t QME_RS4CSR_INJECT_ERR = 7;
static const uint32_t QME_RS4CSR_ERR_CARE_MASK_INVALID = 9;
static const uint32_t QME_RS4CSR_ERR_CHECKWORD_MISMATCH = 10;
static const uint32_t QME_RS4CSR_ERR_SCAN_MODE_INVALID = 11;
static const uint32_t QME_RS4CSR_ERR_ROTATE_AMOUNT = 12;
static const uint32_t QME_RS4CSR_BAD_SCOM_RC = 13;
static const uint32_t QME_RS4CSR_BAD_SCOM_RC_LEN = 3;
// eq/reg00002.H

static const uint64_t QME_RS4DBGC = 0x200e0154ull;

static const uint32_t QME_RS4DBGC_SCAN_DATA_OUT = 0;
static const uint32_t QME_RS4DBGC_SCAN_DATA_OUT_LEN = 56;
static const uint32_t QME_RS4DBGC_LAST_CMD_TYPE = 63;
// eq/reg00002.H

static const uint64_t QME_RS4DBGD = 0x200e0158ull;

static const uint32_t QME_RS4DBGD_QME_RS4DBGD_SCAN_DATA_IN = 0;
static const uint32_t QME_RS4DBGD_QME_RS4DBGD_SCAN_DATA_IN_LEN = 64;
// eq/reg00002.H

static const uint64_t QME_RS4DBGS = 0x200e015cull;

static const uint32_t QME_RS4DBGS_ACTUAL_BITS = 16;
static const uint32_t QME_RS4DBGS_ACTUAL_BITS_LEN = 16;
static const uint32_t QME_RS4DBGS_MACHINE_STATE = 32;
static const uint32_t QME_RS4DBGS_MACHINE_STATE_LEN = 4;
static const uint32_t QME_RS4DBGS_STATE_COUNT = 36;
static const uint32_t QME_RS4DBGS_STATE_COUNT_LEN = 4;
static const uint32_t QME_RS4DBGS_CURRENT_NIBBLE = 40;
static const uint32_t QME_RS4DBGS_CURRENT_NIBBLE_LEN = 4;
static const uint32_t QME_RS4DBGS_CARE_MASK = 44;
static const uint32_t QME_RS4DBGS_CARE_MASK_LEN = 4;
static const uint32_t QME_RS4DBGS_TERMINATE_COUNT = 48;
static const uint32_t QME_RS4DBGS_TERMINATE_COUNT_LEN = 4;
static const uint32_t QME_RS4DBGS_SCAN_MODE = 52;
static const uint32_t QME_RS4DBGS_SCAN_COUNT = 58;
static const uint32_t QME_RS4DBGS_SCAN_COUNT_LEN = 6;
// eq/reg00002.H

static const uint64_t QME_RVCR = 0x200e0084ull;

static const uint32_t QME_RVCR_QME_RVCR_RVID_VALUE = 1;
static const uint32_t QME_RVCR_QME_RVCR_RVID_VALUE_LEN = 7;
// eq/reg00003.H

static const uint64_t QME_SCDR = 0x200e0144ull;
// eq/reg00003.H

static const uint64_t QME_SCOM_PBTXTR0 = 0x200e0040ull;

static const uint32_t QME_SCOM_PBTXTR0__VALID = 0;
static const uint32_t QME_SCOM_PBTXTR0__VALID_LEN = 8;
static const uint32_t QME_SCOM_PBTXTR0_0 = 8;
static const uint32_t QME_SCOM_PBTXTR0_0_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_1 = 12;
static const uint32_t QME_SCOM_PBTXTR0_1_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_2 = 16;
static const uint32_t QME_SCOM_PBTXTR0_2_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_3 = 20;
static const uint32_t QME_SCOM_PBTXTR0_3_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_4 = 24;
static const uint32_t QME_SCOM_PBTXTR0_4_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_5 = 28;
static const uint32_t QME_SCOM_PBTXTR0_5_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_6 = 32;
static const uint32_t QME_SCOM_PBTXTR0_6_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_7 = 36;
static const uint32_t QME_SCOM_PBTXTR0_7_LEN = 4;
// eq/reg00003.H

static const uint64_t QME_SCOM_PBTXTR1 = 0x200e0041ull;

static const uint32_t QME_SCOM_PBTXTR1__VALID = 0;
static const uint32_t QME_SCOM_PBTXTR1__VALID_LEN = 8;
static const uint32_t QME_SCOM_PBTXTR1_0 = 8;
static const uint32_t QME_SCOM_PBTXTR1_0_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_1 = 12;
static const uint32_t QME_SCOM_PBTXTR1_1_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_2 = 16;
static const uint32_t QME_SCOM_PBTXTR1_2_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_3 = 20;
static const uint32_t QME_SCOM_PBTXTR1_3_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_4 = 24;
static const uint32_t QME_SCOM_PBTXTR1_4_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_5 = 28;
static const uint32_t QME_SCOM_PBTXTR1_5_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_6 = 32;
static const uint32_t QME_SCOM_PBTXTR1_6_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR1_7 = 36;
static const uint32_t QME_SCOM_PBTXTR1_7_LEN = 4;
// eq/reg00003.H

static const uint64_t QME_SCOM_PBTXTR2 = 0x200e0042ull;

static const uint32_t QME_SCOM_PBTXTR2__VALID = 0;
static const uint32_t QME_SCOM_PBTXTR2__VALID_LEN = 8;
static const uint32_t QME_SCOM_PBTXTR2_0 = 8;
static const uint32_t QME_SCOM_PBTXTR2_0_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_1 = 12;
static const uint32_t QME_SCOM_PBTXTR2_1_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_2 = 16;
static const uint32_t QME_SCOM_PBTXTR2_2_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_3 = 20;
static const uint32_t QME_SCOM_PBTXTR2_3_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_4 = 24;
static const uint32_t QME_SCOM_PBTXTR2_4_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_5 = 28;
static const uint32_t QME_SCOM_PBTXTR2_5_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_6 = 32;
static const uint32_t QME_SCOM_PBTXTR2_6_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR2_7 = 36;
static const uint32_t QME_SCOM_PBTXTR2_7_LEN = 4;
// eq/reg00003.H

static const uint64_t QME_SCOM_PBTXTR3 = 0x200e0043ull;

static const uint32_t QME_SCOM_PBTXTR3__VALID = 0;
static const uint32_t QME_SCOM_PBTXTR3__VALID_LEN = 8;
static const uint32_t QME_SCOM_PBTXTR3_0 = 8;
static const uint32_t QME_SCOM_PBTXTR3_0_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_1 = 12;
static const uint32_t QME_SCOM_PBTXTR3_1_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_2 = 16;
static const uint32_t QME_SCOM_PBTXTR3_2_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_3 = 20;
static const uint32_t QME_SCOM_PBTXTR3_3_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_4 = 24;
static const uint32_t QME_SCOM_PBTXTR3_4_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_5 = 28;
static const uint32_t QME_SCOM_PBTXTR3_5_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_6 = 32;
static const uint32_t QME_SCOM_PBTXTR3_6_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR3_7 = 36;
static const uint32_t QME_SCOM_PBTXTR3_7_LEN = 4;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIDBGINF = 0x200e023cull;

static const uint32_t QME_SCOM_XIDBGINF_SRR0_TOP = 0;
static const uint32_t QME_SCOM_XIDBGINF_SRR0_TOP_LEN = 30;
static const uint32_t QME_SCOM_XIDBGINF_LR = 32;
static const uint32_t QME_SCOM_XIDBGINF_LR_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIDBGPRO = 0x200e0214ull;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIICAC = 0x200e0224ull;

static const uint32_t QME_SCOM_XIICAC_SIB_PIB_IFETCH_PENDING = 34;
static const uint32_t QME_SCOM_XIICAC_MEM_IFETCH_PENDING = 35;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIMEM = 0x200e021cull;

static const uint32_t QME_SCOM_XIMEM_ADDR = 0;
static const uint32_t QME_SCOM_XIMEM_ADDR_LEN = 32;
static const uint32_t QME_SCOM_XIMEM_R_NW = 32;
static const uint32_t QME_SCOM_XIMEM_BUSY = 33;
static const uint32_t QME_SCOM_XIMEM_IMPRECISE_ERROR_PENDING = 34;
static const uint32_t QME_SCOM_XIMEM_BYTE_ENABLE = 35;
static const uint32_t QME_SCOM_XIMEM_BYTE_ENABLE_LEN = 8;
static const uint32_t QME_SCOM_XIMEM_LINE_MODE = 43;
static const uint32_t QME_SCOM_XIMEM_ERROR = 49;
static const uint32_t QME_SCOM_XIMEM_ERROR_LEN = 3;
static const uint32_t QME_SCOM_XIMEM_IFETCH_PENDING = 62;
static const uint32_t QME_SCOM_XIMEM_DATAOP_PENDING = 63;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIRAMDBG = 0x200e020cull;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIRAMEDR = 0x200e0210ull;

static const uint32_t QME_SCOM_XIRAMEDR_IR = 0;
static const uint32_t QME_SCOM_XIRAMEDR_IR_LEN = 32;
static const uint32_t QME_SCOM_XIRAMEDR_EDR = 32;
static const uint32_t QME_SCOM_XIRAMEDR_EDR_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIRAMGA = 0x200e0208ull;

static const uint32_t QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR = 0;
static const uint32_t QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIRAMRA = 0x200e0204ull;
// eq/reg00003.H

static const uint64_t QME_SCOM_XISGB = 0x200e0220ull;

static const uint32_t QME_SCOM_XISGB_TORE_ADDRESS = 0;
static const uint32_t QME_SCOM_XISGB_TORE_ADDRESS_LEN = 32;
static const uint32_t QME_SCOM_XISGB_GB_BYTE_VALID = 36;
static const uint32_t QME_SCOM_XISGB_GB_BYTE_VALID_LEN = 4;
static const uint32_t QME_SCOM_XISGB_GB_FLUSH_PENDING = 63;
// eq/reg00003.H

static const uint64_t QME_SCOM_XISIB = 0x200e0218ull;

static const uint32_t QME_SCOM_XISIB_ADDR = 0;
static const uint32_t QME_SCOM_XISIB_ADDR_LEN = 32;
static const uint32_t QME_SCOM_XISIB_R_NW = 32;
static const uint32_t QME_SCOM_XISIB_BUSY = 33;
static const uint32_t QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING = 34;
static const uint32_t QME_SCOM_XISIB_RSP_INFO = 49;
static const uint32_t QME_SCOM_XISIB_RSP_INFO_LEN = 3;
static const uint32_t QME_SCOM_XISIB_RESET_PENDING = 61;
static const uint32_t QME_SCOM_XISIB_IFETCH_PENDING = 62;
static const uint32_t QME_SCOM_XISIB_DATAOP_PENDING = 63;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIVDR0 = 0x200e0280ull;

static const uint32_t QME_SCOM_XIVDR0_0 = 0;
static const uint32_t QME_SCOM_XIVDR0_0_LEN = 32;
static const uint32_t QME_SCOM_XIVDR0_1 = 32;
static const uint32_t QME_SCOM_XIVDR0_1_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIVDR2 = 0x200e0284ull;

static const uint32_t QME_SCOM_XIVDR2_2 = 0;
static const uint32_t QME_SCOM_XIVDR2_2_LEN = 32;
static const uint32_t QME_SCOM_XIVDR2_3 = 32;
static const uint32_t QME_SCOM_XIVDR2_3_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIVDR28 = 0x200e0298ull;

static const uint32_t QME_SCOM_XIVDR28_8 = 0;
static const uint32_t QME_SCOM_XIVDR28_8_LEN = 32;
static const uint32_t QME_SCOM_XIVDR28_9 = 32;
static const uint32_t QME_SCOM_XIVDR28_9_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIVDR30 = 0x200e029cull;

static const uint32_t QME_SCOM_XIVDR30_0 = 0;
static const uint32_t QME_SCOM_XIVDR30_0_LEN = 32;
static const uint32_t QME_SCOM_XIVDR30_1 = 32;
static const uint32_t QME_SCOM_XIVDR30_1_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIVDR4 = 0x200e0288ull;

static const uint32_t QME_SCOM_XIVDR4_4 = 0;
static const uint32_t QME_SCOM_XIVDR4_4_LEN = 32;
static const uint32_t QME_SCOM_XIVDR4_5 = 32;
static const uint32_t QME_SCOM_XIVDR4_5_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIVDR6 = 0x200e028cull;

static const uint32_t QME_SCOM_XIVDR6_6 = 0;
static const uint32_t QME_SCOM_XIVDR6_6_LEN = 32;
static const uint32_t QME_SCOM_XIVDR6_7 = 32;
static const uint32_t QME_SCOM_XIVDR6_7_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIVDR8 = 0x200e0290ull;

static const uint32_t QME_SCOM_XIVDR8_8 = 0;
static const uint32_t QME_SCOM_XIVDR8_8_LEN = 32;
static const uint32_t QME_SCOM_XIVDR8_9 = 32;
static const uint32_t QME_SCOM_XIVDR8_9_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIVDRX = 0x200e0294ull;

static const uint32_t QME_SCOM_XIVDRX_0 = 0;
static const uint32_t QME_SCOM_XIVDRX_0_LEN = 32;
static const uint32_t QME_SCOM_XIVDRX_3 = 32;
static const uint32_t QME_SCOM_XIVDRX_3_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCOM_XIXCR = 0x200e0200ull;

static const uint32_t QME_SCOM_XIXCR_QME_SCOM_XIXCR_CTR = 32;
static const uint32_t QME_SCOM_XIXCR_QME_SCOM_XIXCR_CTR_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCRA_RW = 0x200e0124ull;
static const uint64_t QME_SCRA_WO_CLEAR = 0x200e0127ull;
static const uint64_t QME_SCRA_WO_OR = 0x200e0126ull;

static const uint32_t QME_SCRA_QME_SCRA_DATA = 0;
static const uint32_t QME_SCRA_QME_SCRA_DATA_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SCRB_RW = 0x200e0128ull;
static const uint64_t QME_SCRB_WO_CLEAR = 0x200e012bull;
static const uint64_t QME_SCRB_WO_OR = 0x200e012aull;

static const uint32_t QME_SCRB_QME_SCRB_DATA = 0;
static const uint32_t QME_SCRB_QME_SCRB_DATA_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_SSDR = 0x200e0140ull;
// eq/reg00003.H

static const uint64_t QME_SWHR = 0x200e014cull;

static const uint32_t QME_SWHR_SH_SRC_SPC_WKUP_RECENT_SET = 52;
static const uint32_t QME_SWHR_SH_SRC_SPC_WKUP_RECENT_SET_LEN = 2;
static const uint32_t QME_SWHR_SH_SRC_SPC_WKUP_RECENT_CLR = 54;
static const uint32_t QME_SWHR_SH_SRC_SPC_WKUP_RECENT_CLR_LEN = 2;
static const uint32_t QME_SWHR_SH_SRC_SPC_WKUP_RECENT_ACT = 56;
static const uint32_t QME_SWHR_SH_SRC_SPC_WKUP_RECENT_ACT_LEN = 2;
static const uint32_t QME_SWHR_SH_SRC_SPC_WKUP_RECENT_DRP = 58;
static const uint32_t QME_SWHR_SH_SRC_SPC_WKUP_RECENT_DRP_LEN = 2;
static const uint32_t QME_SWHR_PWU_OTR_SPECIAL_WKUP_REQ = 60;
static const uint32_t QME_SWHR_PWU_FSP_SPECIAL_WKUP_REQ = 61;
static const uint32_t QME_SWHR_PWU_OCC_SPECIAL_WKUP_REQ = 62;
static const uint32_t QME_SWHR_PWU_HYP_SPECIAL_WKUP_REQ = 63;
// eq/reg00003.H

static const uint64_t QME_TBR = 0x200e0248ull;

static const uint32_t QME_TBR_TIMEBASE = 0;
static const uint32_t QME_TBR_TIMEBASE_LEN = 32;
static const uint32_t QME_TBR_CYCLES = 32;
static const uint32_t QME_TBR_CYCLES_LEN = 32;
// eq/reg00003.H

static const uint64_t QME_TSEL = 0x200e0240ull;

static const uint32_t QME_TSEL_WATCHDOG_SEL = 0;
static const uint32_t QME_TSEL_WATCHDOG_SEL_LEN = 4;
static const uint32_t QME_TSEL_FIT_SEL = 4;
static const uint32_t QME_TSEL_FIT_SEL_LEN = 4;
// eq/reg00003.H

static const uint64_t QME_TTSR = 0x200e0138ull;
// eq/reg00003.H

static const uint64_t RECOV_INTERRUPT_REG = 0x200f001bull;
// eq/reg00003.H

static const uint64_t RFIR = 0x20040001ull;

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
static const uint32_t RFIR_RFIR_IN13_LEN = 13;
// eq/reg00003.H

static const uint64_t SCAN32 = 0x20038000ull;
// eq/reg00003.H

static const uint64_t SCAN64 = 0x2003e000ull;
// eq/reg00003.H

static const uint64_t SCAN_CAPTUREDR = 0x2003c000ull;
// eq/reg00003.H

static const uint64_t SCAN_CAPTUREDR_LONG = 0x2003d000ull;
// eq/reg00003.H

static const uint64_t SCAN_LONG_ROTATE = 0x20039000ull;
// eq/reg00003.H

static const uint64_t SCAN_REGION_TYPE = 0x20030005ull;

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
// eq/reg00003.H

static const uint64_t SCAN_UPDATEDR = 0x2003a000ull;
// eq/reg00003.H

static const uint64_t SCAN_UPDATEDR_LONG = 0x2003b000ull;
// eq/reg00003.H

static const uint64_t SLAVE_CONFIG_REG = 0x200f001eull;

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
// eq/reg00003.H

static const uint64_t SPATTN_NCX = 0x20040005ull;
static const uint64_t SPATTN_ROX = 0x20040004ull;

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
// eq/reg00003.H

static const uint64_t SPA_MASK = 0x20040007ull;

static const uint32_t SPA_MASK_SPA_MASK_IN = 0;
static const uint32_t SPA_MASK_SPA_MASK_IN_LEN = 10;
// eq/reg00003.H

static const uint64_t SYNC_CONFIG = 0x20030000ull;

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
// eq/reg00003.H

static const uint64_t TIMEOUT_REG = 0x200f0010ull;
// eq/reg00003.H

static const uint64_t VITAL_SCAN_OUT = 0x200f0017ull;
// eq/reg00003.H

static const uint64_t XFIR = 0x20040000ull;

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
static const uint32_t XFIR_13_LEN = 13;
static const uint32_t XFIR_26 = 26;
// eq/reg00003.H

static const uint64_t XSTOP1 = 0x2003000cull;

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
// eq/reg00003.H

static const uint64_t XSTOP2 = 0x2003000dull;

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
// eq/reg00004.H

static const uint64_t XSTOP3 = 0x2003000eull;

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
// eq/reg00004.H

static const uint64_t XSTOP_INTERRUPT_REG = 0x200f001cull;
// eq/reg00004.H

}
}
#include "eq/reg00000.H"
#include "eq/reg00001.H"
#include "eq/reg00002.H"
#include "eq/reg00003.H"
#include "eq/reg00004.H"
#endif
