/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_perv_tcmc.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2023                        */
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
#pragma once
#include <stdint.h>

#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif

static const uint64_t TCMC_ATTN = 0x40002ull;

static const uint32_t TCMC_ATTN_ANY_ATTN = 0;
static const uint32_t TCMC_ATTN_RESERVED1S = 1;
static const uint32_t TCMC_ATTN_RESERVED2S = 2;
static const uint32_t TCMC_ATTN_RESERVED3S = 3;
static const uint32_t TCMC_ATTN_ATTN_PERV = 4;
static const uint32_t TCMC_ATTN_ATTN_IN05 = 5;
static const uint32_t TCMC_ATTN_ATTN_IN06 = 6;
static const uint32_t TCMC_ATTN_ATTN_IN07 = 7;
static const uint32_t TCMC_ATTN_ATTN_IN08 = 8;
static const uint32_t TCMC_ATTN_ATTN_IN09 = 9;
static const uint32_t TCMC_ATTN_ATTN_IN10 = 10;
static const uint32_t TCMC_ATTN_ATTN_IN11 = 11;
static const uint32_t TCMC_ATTN_ATTN_IN12 = 12;
static const uint32_t TCMC_ATTN_ATTN_IN13 = 13;
static const uint32_t TCMC_ATTN_ATTN_IN14 = 14;
static const uint32_t TCMC_ATTN_ATTN_IN15 = 15;
static const uint32_t TCMC_ATTN_ATTN_IN16 = 16;
static const uint32_t TCMC_ATTN_ATTN_IN17 = 17;
static const uint32_t TCMC_ATTN_ATTN_IN18 = 18;
static const uint32_t TCMC_ATTN_ATTN_IN19 = 19;
static const uint32_t TCMC_ATTN_ATTN_IN20 = 20;
static const uint32_t TCMC_ATTN_ATTN_IN21 = 21;
static const uint32_t TCMC_ATTN_ATTN_IN22 = 22;
static const uint32_t TCMC_ATTN_ATTN_IN23 = 23;
static const uint32_t TCMC_ATTN_ATTN_IN24 = 24;
static const uint32_t TCMC_ATTN_ATTN_IN25 = 25;
static const uint32_t TCMC_ATTN_ATTN_IN26 = 26;
static const uint32_t TCMC_ATTN_ATTN_IN27 = 27;
static const uint32_t TCMC_ATTN_ATTN_IN28 = 28;
static const uint32_t TCMC_ATTN_ATTN_IN29 = 29;
static const uint32_t TCMC_ATTN_ATTN_IN30 = 30;
static const uint32_t TCMC_ATTN_ATTN_IN31 = 31;
static const uint32_t TCMC_ATTN_ATTN_IN32 = 32;
static const uint32_t TCMC_ATTN_ATTN_IN33 = 33;
static const uint32_t TCMC_ATTN_ATTN_IN34 = 34;
static const uint32_t TCMC_ATTN_ATTN_IN35 = 35;


static const uint64_t TCMC_ATTN_MASK_WO_CLEAR = 0x40062ull;
static const uint64_t TCMC_ATTN_MASK_WO_OR = 0x40052ull;
static const uint64_t TCMC_ATTN_MASK_RW = 0x40042ull;

static const uint32_t TCMC_ATTN_MASK_MASK_UNUSED = 0;
static const uint32_t TCMC_ATTN_MASK_MASK01 = 1;
static const uint32_t TCMC_ATTN_MASK_MASK02 = 2;
static const uint32_t TCMC_ATTN_MASK_MASK03 = 3;
static const uint32_t TCMC_ATTN_MASK_MASK04 = 4;
static const uint32_t TCMC_ATTN_MASK_MASK05 = 5;
static const uint32_t TCMC_ATTN_MASK_MASK06 = 6;
static const uint32_t TCMC_ATTN_MASK_MASK07 = 7;
static const uint32_t TCMC_ATTN_MASK_MASK08 = 8;
static const uint32_t TCMC_ATTN_MASK_MASK09 = 9;
static const uint32_t TCMC_ATTN_MASK_MASK10 = 10;
static const uint32_t TCMC_ATTN_MASK_MASK11 = 11;
static const uint32_t TCMC_ATTN_MASK_MASK12 = 12;
static const uint32_t TCMC_ATTN_MASK_MASK13 = 13;
static const uint32_t TCMC_ATTN_MASK_MASK14 = 14;
static const uint32_t TCMC_ATTN_MASK_MASK15 = 15;
static const uint32_t TCMC_ATTN_MASK_MASK16 = 16;
static const uint32_t TCMC_ATTN_MASK_MASK17 = 17;
static const uint32_t TCMC_ATTN_MASK_MASK18 = 18;
static const uint32_t TCMC_ATTN_MASK_MASK19 = 19;
static const uint32_t TCMC_ATTN_MASK_MASK20 = 20;
static const uint32_t TCMC_ATTN_MASK_MASK21 = 21;
static const uint32_t TCMC_ATTN_MASK_MASK22 = 22;
static const uint32_t TCMC_ATTN_MASK_MASK23 = 23;
static const uint32_t TCMC_ATTN_MASK_MASK24 = 24;
static const uint32_t TCMC_ATTN_MASK_MASK25 = 25;
static const uint32_t TCMC_ATTN_MASK_MASK26 = 26;
static const uint32_t TCMC_ATTN_MASK_MASK27 = 27;
static const uint32_t TCMC_ATTN_MASK_MASK28 = 28;
static const uint32_t TCMC_ATTN_MASK_MASK29 = 29;
static const uint32_t TCMC_ATTN_MASK_MASK30 = 30;
static const uint32_t TCMC_ATTN_MASK_MASK31 = 31;
static const uint32_t TCMC_ATTN_MASK_MASK32 = 32;
static const uint32_t TCMC_ATTN_MASK_MASK33 = 33;
static const uint32_t TCMC_ATTN_MASK_MASK34 = 34;
static const uint32_t TCMC_ATTN_MASK_MASK35 = 35;


static const uint64_t TCMC_ATTN_UNMASKED = 0x40012ull;

static const uint32_t TCMC_ATTN_UNMASKED_ATTN_UNMASKED_IN = 1;
static const uint32_t TCMC_ATTN_UNMASKED_ATTN_UNMASKED_IN_LEN = 35;


static const uint64_t TCMC_BIST = 0x3000Bull;

static const uint32_t TCMC_BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t TCMC_BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t TCMC_BIST_UNUSED_BC2 = 2;
static const uint32_t TCMC_BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t TCMC_BIST_BIST_REGION_PERV = 4;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT1 = 5;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT2 = 6;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT3 = 7;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT4 = 8;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT5 = 9;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT6 = 10;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT7 = 11;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT8 = 12;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT9 = 13;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT10 = 14;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT11 = 15;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT12 = 16;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT13 = 17;
static const uint32_t TCMC_BIST_BIST_REGION_UNIT14 = 18;
static const uint32_t TCMC_BIST_BIST_STROBE_WINDOW_EN = 48;


static const uint64_t TCMC_CC_ATOMIC_LOCK_REG = 0x303FFull;

static const uint32_t TCMC_CC_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t TCMC_CC_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t TCMC_CC_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t TCMC_CC_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t TCMC_CC_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;


static const uint64_t TCMC_CC_PROTECT_MODE_REG = 0x303FEull;

static const uint32_t TCMC_CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t TCMC_CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;


static const uint64_t TCMC_CC_STATUS = 0x30100ull;

static const uint32_t TCMC_CC_STATUS_CC_OPCG_DONE = 0;
static const uint32_t TCMC_CC_STATUS_PHASE_COUNT_ON_CLKCHANGE = 32;
static const uint32_t TCMC_CC_STATUS_PHASE_COUNT_ON_CLKCHANGE_LEN = 8;
static const uint32_t TCMC_CC_STATUS_DCM_PHASE_COUNT_COMPARE = 55;
static const uint32_t TCMC_CC_STATUS_DCM_PHASE_COUNT_COMPARE_LEN = 9;


static const uint64_t TCMC_CLK_REGION = 0x30006ull;

static const uint32_t TCMC_CLK_REGION_CLOCK_CMD = 0;
static const uint32_t TCMC_CLK_REGION_CLOCK_CMD_LEN = 2;
static const uint32_t TCMC_CLK_REGION_CLKCHG_TRIGGER_RCVR_MODE = 2;
static const uint32_t TCMC_CLK_REGION_CLKCHG_TRIGGER_CTRL_MODE = 3;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_PERV = 4;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT1 = 5;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT2 = 6;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT3 = 7;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT4 = 8;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT5 = 9;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT6 = 10;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT7 = 11;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT8 = 12;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT9 = 13;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT10 = 14;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT11 = 15;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT12 = 16;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT13 = 17;
static const uint32_t TCMC_CLK_REGION_CLOCK_REGION_UNIT14 = 18;
static const uint32_t TCMC_CLK_REGION_SEL_THOLD_SL = 48;
static const uint32_t TCMC_CLK_REGION_SEL_THOLD_NSL = 49;
static const uint32_t TCMC_CLK_REGION_SEL_THOLD_ARY = 50;
static const uint32_t TCMC_CLK_REGION_CLOCK_PULSE_USE_EVEN = 52;
static const uint32_t TCMC_CLK_REGION_SUPPRESS_FIRST_EVEN_CLK = 53;
static const uint32_t TCMC_CLK_REGION_SUPPRESS_LAST_ODD_CLK = 54;


static const uint64_t TCMC_CLOCK_STAT_ARY = 0x3000Aull;

static const uint32_t TCMC_CLOCK_STAT_ARY_PERV_ARY = 4;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT1_ARY = 5;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT2_ARY = 6;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT3_ARY = 7;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT4_ARY = 8;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT5_ARY = 9;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT6_ARY = 10;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT7_ARY = 11;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT8_ARY = 12;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT9_ARY = 13;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT10_ARY = 14;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT11_ARY = 15;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT12_ARY = 16;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT13_ARY = 17;
static const uint32_t TCMC_CLOCK_STAT_ARY_UNIT14_ARY = 18;


static const uint64_t TCMC_CLOCK_STAT_NSL = 0x30009ull;

static const uint32_t TCMC_CLOCK_STAT_NSL_PERV_NSL = 4;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT1_NSL = 5;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT2_NSL = 6;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT3_NSL = 7;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT4_NSL = 8;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT5_NSL = 9;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT6_NSL = 10;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT7_NSL = 11;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT8_NSL = 12;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT9_NSL = 13;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT10_NSL = 14;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT11_NSL = 15;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT12_NSL = 16;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT13_NSL = 17;
static const uint32_t TCMC_CLOCK_STAT_NSL_UNIT14_NSL = 18;


static const uint64_t TCMC_CLOCK_STAT_SL = 0x30008ull;

static const uint32_t TCMC_CLOCK_STAT_SL_PERV_SL = 4;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT1_SL = 5;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT2_SL = 6;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT3_SL = 7;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT4_SL = 8;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT5_SL = 9;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT6_SL = 10;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT7_SL = 11;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT8_SL = 12;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT9_SL = 13;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT10_SL = 14;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT11_SL = 15;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT12_SL = 16;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT13_SL = 17;
static const uint32_t TCMC_CLOCK_STAT_SL_UNIT14_SL = 18;


static const uint64_t TCMC_CPLT_CONF0_WO_CLEAR = 0x28ull;
static const uint64_t TCMC_CPLT_CONF0_WO_OR = 0x18ull;
static const uint64_t TCMC_CPLT_CONF0_RW = 0x8ull;

static const uint32_t TCMC_CPLT_CONF0_PROBE0_SEL = 0;
static const uint32_t TCMC_CPLT_CONF0_PROBE0_SEL_LEN = 6;
static const uint32_t TCMC_CPLT_CONF0_PROBE1_SEL = 8;
static const uint32_t TCMC_CPLT_CONF0_PROBE1_SEL_LEN = 6;
static const uint32_t TCMC_CPLT_CONF0_PROBE2_SEL = 16;
static const uint32_t TCMC_CPLT_CONF0_PROBE2_SEL_LEN = 6;
static const uint32_t TCMC_CPLT_CONF0_PROBE3_SEL = 24;
static const uint32_t TCMC_CPLT_CONF0_PROBE3_SEL_LEN = 6;
static const uint32_t TCMC_CPLT_CONF0_OFLOW_FEH_SEL = 32;
static const uint32_t TCMC_CPLT_CONF0_SCAN_PROTECT = 33;
static const uint32_t TCMC_CPLT_CONF0_SDIS_N = 34;
static const uint32_t TCMC_CPLT_CONF0_SCAN_DIAG = 35;
static const uint32_t TCMC_CPLT_CONF0_MASK_VITL_PCB_ERR = 40;
static const uint32_t TCMC_CPLT_CONF0_MASK_VITL_SCAN_OPCG_ERR = 41;
static const uint32_t TCMC_CPLT_CONF0_DBG_GLB_BRCST_EN = 44;
static const uint32_t TCMC_CPLT_CONF0_TOPOLOGY_MODE = 47;
static const uint32_t TCMC_CPLT_CONF0_TOPOLOGY_ID = 48;
static const uint32_t TCMC_CPLT_CONF0_TOPOLOGY_ID_LEN = 4;


static const uint64_t TCMC_CPLT_CONF1_WO_CLEAR = 0x29ull;
static const uint64_t TCMC_CPLT_CONF1_WO_OR = 0x19ull;
static const uint64_t TCMC_CPLT_CONF1_RW = 0x9ull;

static const uint32_t TCMC_CPLT_CONF1_DDR0_RESET = 2;
static const uint32_t TCMC_CPLT_CONF1_DDR1_RESET = 3;
static const uint32_t TCMC_CPLT_CONF1_DDR0_PWROKIN = 6;
static const uint32_t TCMC_CPLT_CONF1_DDR1_PWROKIN = 7;
static const uint32_t TCMC_CPLT_CONF1_DDR0_DFICLKRESET = 10;
static const uint32_t TCMC_CPLT_CONF1_DDR1_DFICLKRESET = 11;
static const uint32_t TCMC_CPLT_CONF1_DDR0_APBRESETN = 14;
static const uint32_t TCMC_CPLT_CONF1_DDR1_APBRESETN = 15;
static const uint32_t TCMC_CPLT_CONF1_DDR01_ATPGMODE_PUBMAC = 16;
static const uint32_t TCMC_CPLT_CONF1_DDR01_ATPGMODE_HARDMAC = 17;
static const uint32_t TCMC_CPLT_CONF1_DDR01_BYPASSMODEEN = 18;
static const uint32_t TCMC_CPLT_CONF1_DDR01_TESTMODEENDAT = 19;
static const uint32_t TCMC_CPLT_CONF1_DDR01_ATPGASSTCLKEN = 20;
static const uint32_t TCMC_CPLT_CONF1_DDR01_ATPGPLLCTRLBUSEN = 21;
static const uint32_t TCMC_CPLT_CONF1_DDR0_PLLBYPCLK_ENABLE = 22;
static const uint32_t TCMC_CPLT_CONF1_DDR1_PLLBYPCLK_ENABLE = 23;
static const uint32_t TCMC_CPLT_CONF1_DDR0_PUB_NTO1_RATIO = 24;
static const uint32_t TCMC_CPLT_CONF1_DDR1_PUB_NTO1_RATIO = 25;
static const uint32_t TCMC_CPLT_CONF1_DDR0_UC_NTO1_RATIO = 26;
static const uint32_t TCMC_CPLT_CONF1_DDR0_UC_NTO1_RATIO_LEN = 2;
static const uint32_t TCMC_CPLT_CONF1_DDR1_UC_NTO1_RATIO = 28;
static const uint32_t TCMC_CPLT_CONF1_DDR1_UC_NTO1_RATIO_LEN = 2;
static const uint32_t TCMC_CPLT_CONF1_DDR01_BYPSYNC = 31;


static const uint64_t TCMC_CPLT_CTRL0_WO_CLEAR = 0x20ull;
static const uint64_t TCMC_CPLT_CTRL0_WO_OR = 0x10ull;
static const uint64_t TCMC_CPLT_CTRL0_RW = 0x0ull;

static const uint32_t TCMC_CPLT_CTRL0_ABSTCLK_MUXSEL = 0;
static const uint32_t TCMC_CPLT_CTRL0_SYNCCLK_MUXSEL = 1;
static const uint32_t TCMC_CPLT_CTRL0_FLUSHMODE_INH = 2;
static const uint32_t TCMC_CPLT_CTRL0_FORCE_ALIGN = 3;
static const uint32_t TCMC_CPLT_CTRL0_ARY_WRT_THRU = 4;
static const uint32_t TCMC_CPLT_CTRL0_AVP_MODE = 5;
static const uint32_t TCMC_CPLT_CTRL0_VITL_PROTECTION = 6;
static const uint32_t TCMC_CPLT_CTRL0_ABIST_FLUSHMODE_INH = 7;
static const uint32_t TCMC_CPLT_CTRL0_ABIST_RECOV_DISABLE = 8;
static const uint32_t TCMC_CPLT_CTRL0_IOBIST_TX_WRAP_EN = 10;
static const uint32_t TCMC_CPLT_CTRL0_SKIT_ENABLE = 12;
static const uint32_t TCMC_CPLT_CTRL0_DETERMINISTIC_TEST_EN = 13;
static const uint32_t TCMC_CPLT_CTRL0_CONSTRAIN_SAFESCAN = 14;
static const uint32_t TCMC_CPLT_CTRL0_RRFA_TEST_EN = 15;
static const uint32_t TCMC_CPLT_CTRL0_NBTI_HDR_EN_OVR = 16;
static const uint32_t TCMC_CPLT_CTRL0_PSRO_SEL = 20;
static const uint32_t TCMC_CPLT_CTRL0_PSRO_SEL_LEN = 8;
static const uint32_t TCMC_CPLT_CTRL0_BSC_WRAPSEL = 28;
static const uint32_t TCMC_CPLT_CTRL0_BSC_INTMODE = 29;
static const uint32_t TCMC_CPLT_CTRL0_BSC_INV = 30;
static const uint32_t TCMC_CPLT_CTRL0_BSC_EXTMODE = 31;
static const uint32_t TCMC_CPLT_CTRL0_OELCC_EDGE_DELAYED = 36;
static const uint32_t TCMC_CPLT_CTRL0_OELCC_ALIGN_FLUSH = 37;
static const uint32_t TCMC_CPLT_CTRL0_ATPG_EN = 43;
static const uint32_t TCMC_CPLT_CTRL0_CCTEST = 44;
static const uint32_t TCMC_CPLT_CTRL0_OTP_PRGMODE = 45;
static const uint32_t TCMC_CPLT_CTRL0_PIN_LBIST = 47;


static const uint64_t TCMC_CPLT_CTRL0_EFF_RW = 0x90020ull;

static const uint32_t TCMC_CPLT_CTRL0_EFF_CPLT_CTRL0_EFF_REG = 0;
static const uint32_t TCMC_CPLT_CTRL0_EFF_CPLT_CTRL0_EFF_REG_LEN = 64;


static const uint64_t TCMC_CPLT_CTRL1_WO_CLEAR = 0x21ull;
static const uint64_t TCMC_CPLT_CTRL1_WO_OR = 0x11ull;
static const uint64_t TCMC_CPLT_CTRL1_RW = 0x1ull;

static const uint32_t TCMC_CPLT_CTRL1_MULTICYCLE_TEST_FENCE = 0;
static const uint32_t TCMC_CPLT_CTRL1_STG_ACT_EN = 1;
static const uint32_t TCMC_CPLT_CTRL1_REGION0_FENCE = 4;
static const uint32_t TCMC_CPLT_CTRL1_REGION1_FENCE = 5;
static const uint32_t TCMC_CPLT_CTRL1_REGION2_FENCE = 6;
static const uint32_t TCMC_CPLT_CTRL1_REGION3_FENCE = 7;
static const uint32_t TCMC_CPLT_CTRL1_REGION4_FENCE = 8;
static const uint32_t TCMC_CPLT_CTRL1_REGION5_FENCE = 9;
static const uint32_t TCMC_CPLT_CTRL1_REGION6_FENCE = 10;
static const uint32_t TCMC_CPLT_CTRL1_REGION7_FENCE = 11;
static const uint32_t TCMC_CPLT_CTRL1_REGION8_FENCE = 12;
static const uint32_t TCMC_CPLT_CTRL1_REGION9_FENCE = 13;
static const uint32_t TCMC_CPLT_CTRL1_REGION10_FENCE = 14;
static const uint32_t TCMC_CPLT_CTRL1_REGION11_FENCE = 15;
static const uint32_t TCMC_CPLT_CTRL1_REGION12_FENCE = 16;
static const uint32_t TCMC_CPLT_CTRL1_REGION13_FENCE = 17;
static const uint32_t TCMC_CPLT_CTRL1_REGION14_FENCE = 18;


static const uint64_t TCMC_CPLT_CTRL1_EFF_RW = 0x90021ull;

static const uint32_t TCMC_CPLT_CTRL1_EFF_CPLT_CTRL1_EFF_REG = 0;
static const uint32_t TCMC_CPLT_CTRL1_EFF_CPLT_CTRL1_EFF_REG_LEN = 32;


static const uint64_t TCMC_CPLT_CTRL2_WO_CLEAR = 0x22ull;
static const uint64_t TCMC_CPLT_CTRL2_WO_OR = 0x12ull;
static const uint64_t TCMC_CPLT_CTRL2_RW = 0x2ull;

static const uint32_t TCMC_CPLT_CTRL2_REGION0_PGOOD = 4;
static const uint32_t TCMC_CPLT_CTRL2_REGION1_PGOOD = 5;
static const uint32_t TCMC_CPLT_CTRL2_REGION2_PGOOD = 6;
static const uint32_t TCMC_CPLT_CTRL2_REGION3_PGOOD = 7;
static const uint32_t TCMC_CPLT_CTRL2_REGION4_PGOOD = 8;
static const uint32_t TCMC_CPLT_CTRL2_REGION5_PGOOD = 9;
static const uint32_t TCMC_CPLT_CTRL2_REGION6_PGOOD = 10;
static const uint32_t TCMC_CPLT_CTRL2_REGION7_PGOOD = 11;
static const uint32_t TCMC_CPLT_CTRL2_REGION8_PGOOD = 12;
static const uint32_t TCMC_CPLT_CTRL2_REGION9_PGOOD = 13;
static const uint32_t TCMC_CPLT_CTRL2_REGION10_PGOOD = 14;
static const uint32_t TCMC_CPLT_CTRL2_REGION11_PGOOD = 15;
static const uint32_t TCMC_CPLT_CTRL2_REGION12_PGOOD = 16;
static const uint32_t TCMC_CPLT_CTRL2_REGION13_PGOOD = 17;
static const uint32_t TCMC_CPLT_CTRL2_REGION14_PGOOD = 18;


static const uint64_t TCMC_CPLT_CTRL2_EFF_RW = 0x90022ull;

static const uint32_t TCMC_CPLT_CTRL2_EFF_CPLT_CTRL2_EFF_REG = 4;
static const uint32_t TCMC_CPLT_CTRL2_EFF_CPLT_CTRL2_EFF_REG_LEN = 15;


static const uint64_t TCMC_CPLT_CTRL3_WO_CLEAR = 0x23ull;
static const uint64_t TCMC_CPLT_CTRL3_WO_OR = 0x13ull;
static const uint64_t TCMC_CPLT_CTRL3_RW = 0x3ull;

static const uint32_t TCMC_CPLT_CTRL3_REGION0_PSCOM_EN = 4;
static const uint32_t TCMC_CPLT_CTRL3_REGION1_PSCOM_EN = 5;
static const uint32_t TCMC_CPLT_CTRL3_REGION2_PSCOM_EN = 6;
static const uint32_t TCMC_CPLT_CTRL3_REGION3_PSCOM_EN = 7;
static const uint32_t TCMC_CPLT_CTRL3_REGION4_PSCOM_EN = 8;
static const uint32_t TCMC_CPLT_CTRL3_REGION5_PSCOM_EN = 9;
static const uint32_t TCMC_CPLT_CTRL3_REGION6_PSCOM_EN = 10;
static const uint32_t TCMC_CPLT_CTRL3_REGION7_PSCOM_EN = 11;
static const uint32_t TCMC_CPLT_CTRL3_REGION8_PSCOM_EN = 12;
static const uint32_t TCMC_CPLT_CTRL3_REGION9_PSCOM_EN = 13;
static const uint32_t TCMC_CPLT_CTRL3_REGION10_PSCOM_EN = 14;
static const uint32_t TCMC_CPLT_CTRL3_REGION11_PSCOM_EN = 15;
static const uint32_t TCMC_CPLT_CTRL3_REGION12_PSCOM_EN = 16;
static const uint32_t TCMC_CPLT_CTRL3_REGION13_PSCOM_EN = 17;
static const uint32_t TCMC_CPLT_CTRL3_REGION14_PSCOM_EN = 18;


static const uint64_t TCMC_CPLT_CTRL3_EFF_RW = 0x90023ull;

static const uint32_t TCMC_CPLT_CTRL3_EFF_CPLT_CTRL3_EFF_REG = 4;
static const uint32_t TCMC_CPLT_CTRL3_EFF_CPLT_CTRL3_EFF_REG_LEN = 15;


static const uint64_t TCMC_CPLT_CTRL4_WO_CLEAR = 0x24ull;
static const uint64_t TCMC_CPLT_CTRL4_WO_OR = 0x14ull;
static const uint64_t TCMC_CPLT_CTRL4_RW = 0x4ull;

static const uint32_t TCMC_CPLT_CTRL4_REGION0_FLUSHMODE_INH = 4;
static const uint32_t TCMC_CPLT_CTRL4_REGION1_FLUSHMODE_INH = 5;
static const uint32_t TCMC_CPLT_CTRL4_REGION2_FLUSHMODE_INH = 6;
static const uint32_t TCMC_CPLT_CTRL4_REGION3_FLUSHMODE_INH = 7;
static const uint32_t TCMC_CPLT_CTRL4_REGION4_FLUSHMODE_INH = 8;
static const uint32_t TCMC_CPLT_CTRL4_REGION5_FLUSHMODE_INH = 9;
static const uint32_t TCMC_CPLT_CTRL4_REGION6_FLUSHMODE_INH = 10;
static const uint32_t TCMC_CPLT_CTRL4_REGION7_FLUSHMODE_INH = 11;
static const uint32_t TCMC_CPLT_CTRL4_REGION8_FLUSHMODE_INH = 12;
static const uint32_t TCMC_CPLT_CTRL4_REGION9_FLUSHMODE_INH = 13;
static const uint32_t TCMC_CPLT_CTRL4_REGION10_FLUSHMODE_INH = 14;
static const uint32_t TCMC_CPLT_CTRL4_REGION11_FLUSHMODE_INH = 15;
static const uint32_t TCMC_CPLT_CTRL4_REGION12_FLUSHMODE_INH = 16;
static const uint32_t TCMC_CPLT_CTRL4_REGION13_FLUSHMODE_INH = 17;
static const uint32_t TCMC_CPLT_CTRL4_REGION14_FLUSHMODE_INH = 18;


static const uint64_t TCMC_CPLT_CTRL4_EFF_RW = 0x90024ull;

static const uint32_t TCMC_CPLT_CTRL4_EFF_CPLT_CTRL4_EFF_REG = 4;
static const uint32_t TCMC_CPLT_CTRL4_EFF_CPLT_CTRL4_EFF_REG_LEN = 15;


static const uint64_t TCMC_CPLT_CTRL5_WO_CLEAR = 0x25ull;
static const uint64_t TCMC_CPLT_CTRL5_WO_OR = 0x15ull;
static const uint64_t TCMC_CPLT_CTRL5_RW = 0x5ull;



static const uint64_t TCMC_CPLT_CTRL5_EFF_RW = 0x90025ull;

static const uint32_t TCMC_CPLT_CTRL5_EFF_CPLT_CTRL5_EFF_REG = 4;
static const uint32_t TCMC_CPLT_CTRL5_EFF_CPLT_CTRL5_EFF_REG_LEN = 15;


static const uint64_t TCMC_CPLT_STAT0 = 0x100ull;

static const uint32_t TCMC_CPLT_STAT0_ABIST_DONE = 0;
static const uint32_t TCMC_CPLT_STAT0_ABIST_DIAG = 4;
static const uint32_t TCMC_CPLT_STAT0_OPCG_DONE = 8;
static const uint32_t TCMC_CPLT_STAT0_CHIPLET_IS_ALIGNED = 9;
static const uint32_t TCMC_CPLT_STAT0_ABIST_FEH = 24;


static const uint64_t TCMC_CTRL_ATOMIC_LOCK_REG = 0x3FFull;

static const uint32_t TCMC_CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t TCMC_CTRL_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t TCMC_CTRL_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t TCMC_CTRL_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t TCMC_CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;


static const uint64_t TCMC_CTRL_PROTECT_MODE_REG = 0x3FEull;

static const uint32_t TCMC_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t TCMC_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;


static const uint64_t TCMC_DBG_CBS_CC = 0x30013ull;

static const uint32_t TCMC_DBG_CBS_CC_DBG_RESET_EP = 0;
static const uint32_t TCMC_DBG_CBS_CC_DBG_OPCG_IP = 1;
static const uint32_t TCMC_DBG_CBS_CC_DBG_VITL_CLKOFF = 2;
static const uint32_t TCMC_DBG_CBS_CC_DBG_TEST_ENABLE = 3;
static const uint32_t TCMC_DBG_CBS_CC_DBG_CBS_REQ = 4;
static const uint32_t TCMC_DBG_CBS_CC_DBG_CBS_CMD = 5;
static const uint32_t TCMC_DBG_CBS_CC_DBG_CBS_CMD_LEN = 3;
static const uint32_t TCMC_DBG_CBS_CC_DBG_CBS_STATE = 8;
static const uint32_t TCMC_DBG_CBS_CC_DBG_CBS_STATE_LEN = 5;
static const uint32_t TCMC_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE = 13;
static const uint32_t TCMC_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR = 14;
static const uint32_t TCMC_DBG_CBS_CC_DBG_PCB_IDLE = 15;
static const uint32_t TCMC_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE = 16;
static const uint32_t TCMC_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN = 4;
static const uint32_t TCMC_DBG_CBS_CC_DBG_LAST_OPCG_MODE = 20;
static const uint32_t TCMC_DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN = 4;
static const uint32_t TCMC_DBG_CBS_CC_DBG_PCB_ERROR = 24;
static const uint32_t TCMC_DBG_CBS_CC_DBG_PARITY_ERROR = 25;
static const uint32_t TCMC_DBG_CBS_CC_DBG_CC_ERROR = 26;
static const uint32_t TCMC_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED = 27;
static const uint32_t TCMC_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET = 28;
static const uint32_t TCMC_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE = 29;
static const uint32_t TCMC_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE = 30;
static const uint32_t TCMC_DBG_CBS_CC_TP_TPFSI_CBS_ACK = 31;


static const uint64_t TCMC_DCM_CC_REALIGN_GO = 0x30024ull;

static const uint32_t TCMC_DCM_CC_REALIGN_GO_PCB_WRITE_DCM_CC_REALIGN_GO = 0;


static const uint64_t TCMC_EPS_ANY_LOCAL_ERR_MASK = 0x40080ull;

static const uint32_t TCMC_EPS_ANY_LOCAL_ERR_MASK_XSTOP_TO_PCB = 0;
static const uint32_t TCMC_EPS_ANY_LOCAL_ERR_MASK_RECOV_TO_PCB = 1;
static const uint32_t TCMC_EPS_ANY_LOCAL_ERR_MASK_ATTN_TO_PCB = 2;
static const uint32_t TCMC_EPS_ANY_LOCAL_ERR_MASK_LOCAL_XSTOP_TO_PCB = 3;


static const uint64_t TCMC_EPS_CFG_ATTN = 0x40106ull;

static const uint32_t TCMC_EPS_CFG_ATTN_ATTN00 = 0;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN01 = 1;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN02 = 2;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN03 = 3;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN04 = 4;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN05 = 5;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN06 = 6;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN07 = 7;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN08 = 8;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN09 = 9;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN10 = 10;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN11 = 11;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN12 = 12;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN13 = 13;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN14 = 14;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN15 = 15;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN16 = 16;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN17 = 17;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN18 = 18;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN19 = 19;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN20 = 20;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN21 = 21;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN22 = 22;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN23 = 23;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN24 = 24;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN25 = 25;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN26 = 26;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN27 = 27;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN28 = 28;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN29 = 29;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN30 = 30;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN31 = 31;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN32 = 32;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN33 = 33;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN34 = 34;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN35 = 35;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN36 = 36;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN37 = 37;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN38 = 38;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN39 = 39;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN40 = 40;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN41 = 41;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN42 = 42;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN43 = 43;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN44 = 44;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN45 = 45;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN46 = 46;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN47 = 47;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN48 = 48;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN49 = 49;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN50 = 50;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN51 = 51;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN52 = 52;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN53 = 53;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN54 = 54;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN55 = 55;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN56 = 56;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN57 = 57;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN58 = 58;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN59 = 59;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN60 = 60;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN61 = 61;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN62 = 62;
static const uint32_t TCMC_EPS_CFG_ATTN_ATTN63 = 63;


static const uint64_t TCMC_EPS_CFG_LXSTOP = 0x40107ull;

static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP00 = 0;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP01 = 1;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP02 = 2;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP03 = 3;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP04 = 4;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP05 = 5;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP06 = 6;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP07 = 7;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP08 = 8;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP09 = 9;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP10 = 10;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP11 = 11;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP12 = 12;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP13 = 13;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP14 = 14;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP15 = 15;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP16 = 16;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP17 = 17;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP18 = 18;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP19 = 19;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP20 = 20;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP21 = 21;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP22 = 22;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP23 = 23;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP24 = 24;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP25 = 25;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP26 = 26;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP27 = 27;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP28 = 28;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP29 = 29;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP30 = 30;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP31 = 31;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP32 = 32;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP33 = 33;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP34 = 34;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP35 = 35;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP36 = 36;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP37 = 37;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP38 = 38;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP39 = 39;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP40 = 40;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP41 = 41;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP42 = 42;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP43 = 43;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP44 = 44;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP45 = 45;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP46 = 46;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP47 = 47;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP48 = 48;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP49 = 49;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP50 = 50;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP51 = 51;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP52 = 52;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP53 = 53;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP54 = 54;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP55 = 55;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP56 = 56;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP57 = 57;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP58 = 58;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP59 = 59;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP60 = 60;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP61 = 61;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP62 = 62;
static const uint32_t TCMC_EPS_CFG_LXSTOP_LXSTOP63 = 63;


static const uint64_t TCMC_EPS_CFG_RECOV = 0x40105ull;

static const uint32_t TCMC_EPS_CFG_RECOV_RECOV00 = 0;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV01 = 1;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV02 = 2;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV03 = 3;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV04 = 4;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV05 = 5;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV06 = 6;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV07 = 7;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV08 = 8;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV09 = 9;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV10 = 10;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV11 = 11;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV12 = 12;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV13 = 13;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV14 = 14;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV15 = 15;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV16 = 16;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV17 = 17;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV18 = 18;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV19 = 19;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV20 = 20;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV21 = 21;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV22 = 22;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV23 = 23;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV24 = 24;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV25 = 25;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV26 = 26;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV27 = 27;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV28 = 28;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV29 = 29;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV30 = 30;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV31 = 31;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV32 = 32;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV33 = 33;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV34 = 34;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV35 = 35;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV36 = 36;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV37 = 37;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV38 = 38;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV39 = 39;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV40 = 40;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV41 = 41;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV42 = 42;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV43 = 43;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV44 = 44;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV45 = 45;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV46 = 46;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV47 = 47;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV48 = 48;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV49 = 49;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV50 = 50;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV51 = 51;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV52 = 52;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV53 = 53;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV54 = 54;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV55 = 55;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV56 = 56;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV57 = 57;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV58 = 58;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV59 = 59;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV60 = 60;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV61 = 61;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV62 = 62;
static const uint32_t TCMC_EPS_CFG_RECOV_RECOV63 = 63;


static const uint64_t TCMC_EPS_CFG_XSTOP = 0x40104ull;

static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP00 = 0;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP01 = 1;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP02 = 2;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP03 = 3;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP04 = 4;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP05 = 5;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP06 = 6;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP07 = 7;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP08 = 8;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP09 = 9;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP10 = 10;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP11 = 11;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP12 = 12;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP13 = 13;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP14 = 14;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP15 = 15;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP16 = 16;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP17 = 17;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP18 = 18;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP19 = 19;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP20 = 20;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP21 = 21;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP22 = 22;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP23 = 23;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP24 = 24;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP25 = 25;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP26 = 26;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP27 = 27;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP28 = 28;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP29 = 29;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP30 = 30;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP31 = 31;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP32 = 32;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP33 = 33;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP34 = 34;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP35 = 35;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP36 = 36;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP37 = 37;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP38 = 38;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP39 = 39;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP40 = 40;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP41 = 41;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP42 = 42;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP43 = 43;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP44 = 44;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP45 = 45;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP46 = 46;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP47 = 47;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP48 = 48;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP49 = 49;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP50 = 50;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP51 = 51;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP52 = 52;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP53 = 53;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP54 = 54;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP55 = 55;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP56 = 56;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP57 = 57;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP58 = 58;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP59 = 59;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP60 = 60;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP61 = 61;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP62 = 62;
static const uint32_t TCMC_EPS_CFG_XSTOP_XSTOP63 = 63;


static const uint64_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1 = 0x40081ull;

static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR = 0;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR = 1;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_ATTN_ERR = 2;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR = 3;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR = 4;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR = 5;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR = 6;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNUSED07 = 7;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNUSED08 = 8;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNUSED09 = 9;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNUSED10 = 10;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01 = 11;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02 = 12;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03 = 13;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04 = 14;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05 = 15;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06 = 16;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07 = 17;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08 = 18;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09 = 19;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10 = 20;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11 = 21;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12 = 22;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13 = 23;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14 = 24;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15 = 25;


static const uint64_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2 = 0x40082ull;

static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR = 0;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR = 1;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_ATTN_ERR = 2;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR = 3;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR = 4;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_STAGED_ERR = 5;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR = 6;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNUSED07 = 7;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNUSED08 = 8;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNUSED09 = 9;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNUSED10 = 10;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01 = 11;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02 = 12;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03 = 13;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04 = 14;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05 = 15;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06 = 16;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07 = 17;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08 = 18;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09 = 19;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP10 = 20;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP11 = 21;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP12 = 22;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP13 = 23;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP14 = 24;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP15 = 25;


static const uint64_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3 = 0x40083ull;

static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR = 0;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR = 1;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_ATTN_ERR = 2;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR = 3;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR = 4;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR = 5;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR = 6;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNUSED07 = 7;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNUSED08 = 8;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNUSED09 = 9;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNUSED10 = 10;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01 = 11;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02 = 12;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03 = 13;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04 = 14;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05 = 15;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06 = 16;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07 = 17;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08 = 18;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09 = 19;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP10 = 20;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP11 = 21;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP12 = 22;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP13 = 23;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP14 = 24;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP15 = 25;


static const uint64_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4 = 0x40084ull;

static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_XSTOP_ERR = 0;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_RECOV_ERR = 1;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_ATTN_ERR = 2;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_LXSTOP_ERR = 3;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_SYS_XSTOP_ERR = 4;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_SYS_XSTOP_STAGED_ERR = 5;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_DBG_TRIG_ERR = 6;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNUSED07 = 7;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNUSED08 = 8;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNUSED09 = 9;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNUSED10 = 10;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP01 = 11;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP02 = 12;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP03 = 13;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP04 = 14;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP05 = 15;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP06 = 16;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP07 = 17;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP08 = 18;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP09 = 19;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP10 = 20;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP11 = 21;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP12 = 22;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP13 = 23;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP14 = 24;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP15 = 25;


static const uint64_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5 = 0x40085ull;

static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR = 0;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR = 1;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_ATTN_ERR = 2;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR = 3;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR = 4;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR = 5;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR = 6;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNUSED07 = 7;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNUSED08 = 8;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNUSED09 = 9;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNUSED10 = 10;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 = 11;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 = 12;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 = 13;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 = 14;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 = 15;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 = 16;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 = 17;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 = 18;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 = 19;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 = 20;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 = 21;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 = 22;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 = 23;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 = 24;
static const uint32_t TCMC_EPS_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 = 25;


static const uint64_t TCMC_EPS_DBG_DEBUG_TRACE_CONTROL = 0x107D0ull;

static const uint32_t TCMC_EPS_DBG_DEBUG_TRACE_CONTROL_START = 0;
static const uint32_t TCMC_EPS_DBG_DEBUG_TRACE_CONTROL_STOP = 1;
static const uint32_t TCMC_EPS_DBG_DEBUG_TRACE_CONTROL_RESET = 2;


static const uint64_t TCMC_EPS_DBG_INST1_COND_REG_1 = 0x107C1ull;

static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;


static const uint64_t TCMC_EPS_DBG_INST1_COND_REG_2 = 0x107C2ull;

static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TCMC_EPS_DBG_INST1_COND_REG_2_TO_CMP_LT_LEN = 24;


static const uint64_t TCMC_EPS_DBG_INST1_COND_REG_3 = 0x107C3ull;



static const uint64_t TCMC_EPS_DBG_INST2_COND_REG_1 = 0x107C4ull;

static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_UNUSED_1 = 36;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_UNUSED_1_LEN = 3;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_UNUSED_2 = 43;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_UNUSED_2_LEN = 3;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;


static const uint64_t TCMC_EPS_DBG_INST2_COND_REG_2 = 0x107C5ull;

static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A = 0;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_A_LEN = 5;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B = 5;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_1_B_LEN = 5;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A = 10;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_A_LEN = 5;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B = 15;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_2_CROSS_COUPLE_SELECT_2_B_LEN = 5;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT = 20;
static const uint32_t TCMC_EPS_DBG_INST2_COND_REG_2_TO_CMP_LT_LEN = 24;


static const uint64_t TCMC_EPS_DBG_INST2_COND_REG_3 = 0x107C6ull;



static const uint64_t TCMC_EPS_DBG_MODE_REG = 0x107C0ull;

static const uint32_t TCMC_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t TCMC_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t TCMC_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t TCMC_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t TCMC_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t TCMC_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t TCMC_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t TCMC_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t TCMC_EPS_DBG_MODE_REG_STOP_ON_ATTN_SELECTION = 10;
static const uint32_t TCMC_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 11;
static const uint32_t TCMC_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE = 12;
static const uint32_t TCMC_EPS_DBG_MODE_REG_TRACE_RUN_ON = 16;
static const uint32_t TCMC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t TCMC_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t TCMC_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t TCMC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t TCMC_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t TCMC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t TCMC_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t TCMC_EPS_DBG_MODE_REG_UNUSED = 26;
static const uint32_t TCMC_EPS_DBG_MODE_REG_UNUSED_LEN = 6;


static const uint64_t TCMC_EPS_DBG_TRACE_MODE_REG_2 = 0x107CFull;

static const uint32_t TCMC_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t TCMC_EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t TCMC_EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t TCMC_EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t TCMC_EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t TCMC_EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t TCMC_EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t TCMC_EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t TCMC_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t TCMC_EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;


static const uint64_t TCMC_EPS_DBG_TRACE_REG_0 = 0x107CDull;

static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;


static const uint64_t TCMC_EPS_DBG_TRACE_REG_1 = 0x107CEull;

static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_CONDITION1_ACTION_DO = 0;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_CONDITION2_ACTION_DO = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_CONDITION1_ACTION_DO = 6;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_CONDITION2_ACTION_DO = 8;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_CONDITION1_ACTION_BANK = 36;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_CONDITION2_ACTION_BANK = 37;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_CONDITION1_ACTION_BANK = 39;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_CONDITION2_ACTION_BANK = 40;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_CHECKSTOP_MODE_LT = 48;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_CHECKSTOP_MODE_LT = 52;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t TCMC_EPS_DBG_TRACE_REG_1_INST2_CHECKSTOP_MODE_SELECTOR = 55;


static const uint64_t TCMC_EPS_DBG_XTRA_TRACE_MODE = 0x107D1ull;

static const uint32_t TCMC_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA = 0;
static const uint32_t TCMC_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN = 42;


static const uint64_t TCMC_EPS_DTS0123_RAW = 0x50010ull;

static const uint32_t TCMC_EPS_DTS0123_RAW_DTS0_DTR0_RAW_VALUE = 0;
static const uint32_t TCMC_EPS_DTS0123_RAW_DTS0_DTR0_RAW_VALUE_LEN = 12;
static const uint32_t TCMC_EPS_DTS0123_RAW_DTS0_DTR0_RAW_DTR_ID = 12;
static const uint32_t TCMC_EPS_DTS0123_RAW_DTS0_DTR0_RAW_DTR_ID_LEN = 2;
static const uint32_t TCMC_EPS_DTS0123_RAW_DTS0_DTR0_RAW_OVERFLOW_TIEDOWN = 14;
static const uint32_t TCMC_EPS_DTS0123_RAW_DTS0_DTR0_RAW_VALID = 15;
static const uint32_t TCMC_EPS_DTS0123_RAW_DTS1_DTR0_RAW_VALUE = 16;
static const uint32_t TCMC_EPS_DTS0123_RAW_DTS1_DTR0_RAW_VALUE_LEN = 12;
static const uint32_t TCMC_EPS_DTS0123_RAW_DTS1_DTR0_RAW_DTR_ID = 28;
static const uint32_t TCMC_EPS_DTS0123_RAW_DTS1_DTR0_RAW_DTR_ID_LEN = 2;
static const uint32_t TCMC_EPS_DTS0123_RAW_DTS1_DTR0_RAW_OVERFLOW_TIEDOWN = 30;
static const uint32_t TCMC_EPS_DTS0123_RAW_DTS1_DTR0_RAW_VALID = 31;


static const uint64_t TCMC_EPS_DTS0123_RESULT = 0x50000ull;

static const uint32_t TCMC_EPS_DTS0123_RESULT_DTS0_DTR0_RESULT = 0;
static const uint32_t TCMC_EPS_DTS0123_RESULT_DTS0_DTR0_RESULT_LEN = 4;
static const uint32_t TCMC_EPS_DTS0123_RESULT_DTS0_DTR0_DTR_ID = 12;
static const uint32_t TCMC_EPS_DTS0123_RESULT_DTS0_DTR0_DTR_ID_LEN = 2;
static const uint32_t TCMC_EPS_DTS0123_RESULT_DTS0_DTR0_OVERFLOW = 14;
static const uint32_t TCMC_EPS_DTS0123_RESULT_DTS0_DTR0_VALID = 15;
static const uint32_t TCMC_EPS_DTS0123_RESULT_DTS1_DTR0_RESULT = 16;
static const uint32_t TCMC_EPS_DTS0123_RESULT_DTS1_DTR0_RESULT_LEN = 4;
static const uint32_t TCMC_EPS_DTS0123_RESULT_DTS1_DTR0_DTR_ID = 28;
static const uint32_t TCMC_EPS_DTS0123_RESULT_DTS1_DTR0_DTR_ID_LEN = 2;
static const uint32_t TCMC_EPS_DTS0123_RESULT_DTS1_DTR0_OVERFLOW = 30;
static const uint32_t TCMC_EPS_DTS0123_RESULT_DTS1_DTR0_VALID = 31;


static const uint64_t TCMC_EPS_DTS01_COEFF = 0x50030ull;

static const uint32_t TCMC_EPS_DTS01_COEFF_DTS0_SCALAR_MULTI_FOR_SQUARED = 2;
static const uint32_t TCMC_EPS_DTS01_COEFF_DTS0_SCALAR_MULTI_FOR_SQUARED_LEN = 6;
static const uint32_t TCMC_EPS_DTS01_COEFF_DTS0_SCALAR_MULTIPLIER = 9;
static const uint32_t TCMC_EPS_DTS01_COEFF_DTS0_SCALAR_MULTIPLIER_LEN = 7;
static const uint32_t TCMC_EPS_DTS01_COEFF_DTS0_SIGNED_OFFSET = 23;
static const uint32_t TCMC_EPS_DTS01_COEFF_DTS0_SIGNED_OFFSET_LEN = 9;
static const uint32_t TCMC_EPS_DTS01_COEFF_DTS1_SCALAR_MULTI_FOR_SQUARED = 34;
static const uint32_t TCMC_EPS_DTS01_COEFF_DTS1_SCALAR_MULTI_FOR_SQUARED_LEN = 6;
static const uint32_t TCMC_EPS_DTS01_COEFF_DTS1_SCALAR_MULTIPLIER = 41;
static const uint32_t TCMC_EPS_DTS01_COEFF_DTS1_SCALAR_MULTIPLIER_LEN = 7;
static const uint32_t TCMC_EPS_DTS01_COEFF_DTS1_SIGNED_OFFSET = 55;
static const uint32_t TCMC_EPS_DTS01_COEFF_DTS1_SIGNED_OFFSET_LEN = 9;


static const uint64_t TCMC_EPS_DTS_CLEAR_RESULTS = 0x50021ull;

static const uint32_t TCMC_EPS_DTS_CLEAR_RESULTS_PCB_WRITE_CLEAR_RESULTS = 0;


static const uint64_t TCMC_EPS_DTS_ERROR_MASK_REG = 0x5002Eull;

static const uint32_t TCMC_EPS_DTS_ERROR_MASK_REG_DTS_ERROR_MASK = 0;
static const uint32_t TCMC_EPS_DTS_ERROR_MASK_REG_DTS_ERROR_MASK_LEN = 26;


static const uint64_t TCMC_EPS_DTS_ERROR_REG = 0x5002Full;

static const uint32_t TCMC_EPS_DTS_ERROR_REG_DTS0_SERIAL_PAR_ERR = 0;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_DTS1_SERIAL_PAR_ERR = 1;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_DTS2_SERIAL_PAR_ERR = 2;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_DTS3_SERIAL_PAR_ERR = 3;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_DTS4_SERIAL_PAR_ERR = 4;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_DTS5_SERIAL_PAR_ERR = 5;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_DTS6_SERIAL_PAR_ERR = 6;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_DTS7_SERIAL_PAR_ERR = 7;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_DTS8_SERIAL_PAR_ERR = 8;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_DTS9_SERIAL_PAR_ERR = 9;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_DTS10_SERIAL_PAR_ERR = 10;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_DTS11_SERIAL_PAR_ERR = 11;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_MDTS0_SERIAL_PAR_ERR = 12;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_MDTS1_SERIAL_PAR_ERR = 13;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_MDTS2_SERIAL_PAR_ERR = 14;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_MDTS3_SERIAL_PAR_ERR = 15;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_MDTS4_SERIAL_PAR_ERR = 16;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_MDTS5_SERIAL_PAR_ERR = 17;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_MDTS6_SERIAL_PAR_ERR = 18;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_MDTS7_SERIAL_PAR_ERR = 19;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_CALC_STATE_ERR = 20;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_RESULT_REG_PAR_ERR = 21;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_SKITTER_CONFIG_PARITY_ERR = 22;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_UNUSED23_ERR = 23;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_UNUSED24_ERR = 24;
static const uint32_t TCMC_EPS_DTS_ERROR_REG_UNUSED25_ERR = 25;


static const uint64_t TCMC_EPS_DTS_MEASURE_REQ = 0x50024ull;

static const uint32_t TCMC_EPS_DTS_MEASURE_REQ_DTS_MEASURE_REQUEST = 0;


static const uint64_t TCMC_EPS_DTS_MODE_REG = 0x50020ull;

static const uint32_t TCMC_EPS_DTS_MODE_REG_MINMAX_MODE_ENA = 0;
static const uint32_t TCMC_EPS_DTS_MODE_REG_MINMAX_MODE_ENA_LEN = 2;
static const uint32_t TCMC_EPS_DTS_MODE_REG_MEASURE_HANG_PULSE_ENA = 3;
static const uint32_t TCMC_EPS_DTS_MODE_REG_MEASURE_HANG_PULSE_CNT = 4;
static const uint32_t TCMC_EPS_DTS_MODE_REG_MEASURE_HANG_PULSE_CNT_LEN = 6;


static const uint64_t TCMC_EPS_DTS_SELECT = 0x50022ull;

static const uint32_t TCMC_EPS_DTS_SELECT_DTS0_SELECT = 0;
static const uint32_t TCMC_EPS_DTS_SELECT_DTS1_SELECT = 1;
static const uint32_t TCMC_EPS_DTS_SELECT_DTS2_SELECT = 2;
static const uint32_t TCMC_EPS_DTS_SELECT_DTS3_SELECT = 3;
static const uint32_t TCMC_EPS_DTS_SELECT_DTS4_SELECT = 4;
static const uint32_t TCMC_EPS_DTS_SELECT_DTS5_SELECT = 5;
static const uint32_t TCMC_EPS_DTS_SELECT_DTS6_SELECT = 6;
static const uint32_t TCMC_EPS_DTS_SELECT_DTS7_SELECT = 7;
static const uint32_t TCMC_EPS_DTS_SELECT_DTS8_SELECT = 8;
static const uint32_t TCMC_EPS_DTS_SELECT_DTS9_SELECT = 9;
static const uint32_t TCMC_EPS_DTS_SELECT_DTS10_SELECT = 10;
static const uint32_t TCMC_EPS_DTS_SELECT_DTS11_SELECT = 11;
static const uint32_t TCMC_EPS_DTS_SELECT_MDTS0_SELECT = 12;
static const uint32_t TCMC_EPS_DTS_SELECT_MDTS1_SELECT = 13;
static const uint32_t TCMC_EPS_DTS_SELECT_MDTS2_SELECT = 14;
static const uint32_t TCMC_EPS_DTS_SELECT_MDTS3_SELECT = 15;
static const uint32_t TCMC_EPS_DTS_SELECT_MDTS4_SELECT = 16;
static const uint32_t TCMC_EPS_DTS_SELECT_MDTS5_SELECT = 17;
static const uint32_t TCMC_EPS_DTS_SELECT_MDTS6_SELECT = 18;
static const uint32_t TCMC_EPS_DTS_SELECT_MDTS7_SELECT = 19;


static const uint64_t TCMC_EPS_DTS_SELECT_REPR = 0x50023ull;

static const uint32_t TCMC_EPS_DTS_SELECT_REPR_DTS0_SELECT_REPR = 0;
static const uint32_t TCMC_EPS_DTS_SELECT_REPR_DTS1_SELECT_REPR = 1;


static const uint64_t TCMC_EPS_LOCAL_FIR_WOF = 0x40108ull;

static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN00 = 0;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN01 = 1;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN02 = 2;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN03 = 3;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN04 = 4;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN05 = 5;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN06 = 6;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN07 = 7;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN08 = 8;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN09 = 9;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN10 = 10;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN11 = 11;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN12 = 12;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN13 = 13;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN14 = 14;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN15 = 15;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN16 = 16;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN17 = 17;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN18 = 18;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN19 = 19;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN20 = 20;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN21 = 21;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN22 = 22;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN23 = 23;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN24 = 24;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN25 = 25;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN26 = 26;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN27 = 27;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN28 = 28;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN29 = 29;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN30 = 30;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN31 = 31;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN32 = 32;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN33 = 33;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN34 = 34;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN35 = 35;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN36 = 36;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN37 = 37;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN38 = 38;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN39 = 39;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN40 = 40;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN41 = 41;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN42 = 42;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN43 = 43;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN44 = 44;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN45 = 45;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN46 = 46;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN47 = 47;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN48 = 48;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN49 = 49;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN50 = 50;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN51 = 51;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN52 = 52;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN53 = 53;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN54 = 54;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN55 = 55;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN56 = 56;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN57 = 57;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN58 = 58;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN59 = 59;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN60 = 60;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN61 = 61;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN62 = 62;
static const uint32_t TCMC_EPS_LOCAL_FIR_WOF_IN63 = 63;


static const uint64_t TCMC_EPS_MASK_WO_OR = 0x40103ull;
static const uint64_t TCMC_EPS_MASK_RW_WCLEAR = 0x40102ull;

static const uint32_t TCMC_EPS_MASK_MASK00 = 0;
static const uint32_t TCMC_EPS_MASK_MASK01 = 1;
static const uint32_t TCMC_EPS_MASK_MASK02 = 2;
static const uint32_t TCMC_EPS_MASK_MASK03 = 3;
static const uint32_t TCMC_EPS_MASK_MASK04 = 4;
static const uint32_t TCMC_EPS_MASK_MASK05 = 5;
static const uint32_t TCMC_EPS_MASK_MASK06 = 6;
static const uint32_t TCMC_EPS_MASK_MASK07 = 7;
static const uint32_t TCMC_EPS_MASK_MASK08 = 8;
static const uint32_t TCMC_EPS_MASK_MASK09 = 9;
static const uint32_t TCMC_EPS_MASK_MASK10 = 10;
static const uint32_t TCMC_EPS_MASK_MASK11 = 11;
static const uint32_t TCMC_EPS_MASK_MASK12 = 12;
static const uint32_t TCMC_EPS_MASK_MASK13 = 13;
static const uint32_t TCMC_EPS_MASK_MASK14 = 14;
static const uint32_t TCMC_EPS_MASK_MASK15 = 15;
static const uint32_t TCMC_EPS_MASK_MASK16 = 16;
static const uint32_t TCMC_EPS_MASK_MASK17 = 17;
static const uint32_t TCMC_EPS_MASK_MASK18 = 18;
static const uint32_t TCMC_EPS_MASK_MASK19 = 19;
static const uint32_t TCMC_EPS_MASK_MASK20 = 20;
static const uint32_t TCMC_EPS_MASK_MASK21 = 21;
static const uint32_t TCMC_EPS_MASK_MASK22 = 22;
static const uint32_t TCMC_EPS_MASK_MASK23 = 23;
static const uint32_t TCMC_EPS_MASK_MASK24 = 24;
static const uint32_t TCMC_EPS_MASK_MASK25 = 25;
static const uint32_t TCMC_EPS_MASK_MASK26 = 26;
static const uint32_t TCMC_EPS_MASK_MASK27 = 27;
static const uint32_t TCMC_EPS_MASK_MASK28 = 28;
static const uint32_t TCMC_EPS_MASK_MASK29 = 29;
static const uint32_t TCMC_EPS_MASK_MASK30 = 30;
static const uint32_t TCMC_EPS_MASK_MASK31 = 31;
static const uint32_t TCMC_EPS_MASK_MASK32 = 32;
static const uint32_t TCMC_EPS_MASK_MASK33 = 33;
static const uint32_t TCMC_EPS_MASK_MASK34 = 34;
static const uint32_t TCMC_EPS_MASK_MASK35 = 35;
static const uint32_t TCMC_EPS_MASK_MASK36 = 36;
static const uint32_t TCMC_EPS_MASK_MASK37 = 37;
static const uint32_t TCMC_EPS_MASK_MASK38 = 38;
static const uint32_t TCMC_EPS_MASK_MASK39 = 39;
static const uint32_t TCMC_EPS_MASK_MASK40 = 40;
static const uint32_t TCMC_EPS_MASK_MASK41 = 41;
static const uint32_t TCMC_EPS_MASK_MASK42 = 42;
static const uint32_t TCMC_EPS_MASK_MASK43 = 43;
static const uint32_t TCMC_EPS_MASK_MASK44 = 44;
static const uint32_t TCMC_EPS_MASK_MASK45 = 45;
static const uint32_t TCMC_EPS_MASK_MASK46 = 46;
static const uint32_t TCMC_EPS_MASK_MASK47 = 47;
static const uint32_t TCMC_EPS_MASK_MASK48 = 48;
static const uint32_t TCMC_EPS_MASK_MASK49 = 49;
static const uint32_t TCMC_EPS_MASK_MASK50 = 50;
static const uint32_t TCMC_EPS_MASK_MASK51 = 51;
static const uint32_t TCMC_EPS_MASK_MASK52 = 52;
static const uint32_t TCMC_EPS_MASK_MASK53 = 53;
static const uint32_t TCMC_EPS_MASK_MASK54 = 54;
static const uint32_t TCMC_EPS_MASK_MASK55 = 55;
static const uint32_t TCMC_EPS_MASK_MASK56 = 56;
static const uint32_t TCMC_EPS_MASK_MASK57 = 57;
static const uint32_t TCMC_EPS_MASK_MASK58 = 58;
static const uint32_t TCMC_EPS_MASK_MASK59 = 59;
static const uint32_t TCMC_EPS_MASK_MASK60 = 60;
static const uint32_t TCMC_EPS_MASK_MASK61 = 61;
static const uint32_t TCMC_EPS_MASK_MASK62 = 62;
static const uint32_t TCMC_EPS_MASK_MASK63 = 63;


static const uint64_t TCMC_EPS_MODE_REG = 0x40088ull;

static const uint32_t TCMC_EPS_MODE_REG_XSTOP_LOCK = 0;
static const uint32_t TCMC_EPS_MODE_REG_XSTOP_LOCK_RECOV = 1;
static const uint32_t TCMC_EPS_MODE_REG_XSTOP_LOCK_ATTN = 2;
static const uint32_t TCMC_EPS_MODE_REG_XSTOP_LOCK_LXSTOP = 3;
static const uint32_t TCMC_EPS_MODE_REG_MODE_REG04 = 4;
static const uint32_t TCMC_EPS_MODE_REG_MODE_REG05 = 5;
static const uint32_t TCMC_EPS_MODE_REG_DISABLE_IOPB_ERR = 6;
static const uint32_t TCMC_EPS_MODE_REG_MODE_REG07 = 7;
static const uint32_t TCMC_EPS_MODE_REG_MODE_REG08 = 8;
static const uint32_t TCMC_EPS_MODE_REG_MASK_DIRECT_ERROR = 9;
static const uint32_t TCMC_EPS_MODE_REG_MODE_REG10 = 10;
static const uint32_t TCMC_EPS_MODE_REG_MODE_REG11 = 11;
static const uint32_t TCMC_EPS_MODE_REG_MODE_REG12 = 12;
static const uint32_t TCMC_EPS_MODE_REG_MODE_REG13 = 13;
static const uint32_t TCMC_EPS_MODE_REG_RECOV_WOF_FREEZE = 14;
static const uint32_t TCMC_EPS_MODE_REG_RECOV_WOF_GATE = 15;


static const uint64_t TCMC_EPS_PSC_ADDR_TRAP_REG = 0x10003ull;

static const uint32_t TCMC_EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR = 0;
static const uint32_t TCMC_EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN = 16;
static const uint32_t TCMC_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR = 16;
static const uint32_t TCMC_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT = 17;
static const uint32_t TCMC_EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR = 18;
static const uint32_t TCMC_EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN = 13;
static const uint32_t TCMC_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY = 31;
static const uint32_t TCMC_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR = 32;
static const uint32_t TCMC_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION = 33;
static const uint32_t TCMC_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER = 34;
static const uint32_t TCMC_EPS_PSC_ADDR_TRAP_REG_LAST_CONTROLLERID = 35;
static const uint32_t TCMC_EPS_PSC_ADDR_TRAP_REG_LAST_CONTROLLERID_LEN = 4;


static const uint64_t TCMC_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG = 0x10007ull;

static const uint32_t TCMC_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK = 0;
static const uint32_t TCMC_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN = 32;


static const uint64_t TCMC_EPS_PSC_PSCOM_ERROR_MASK = 0x10002ull;

static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR = 3;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_UL_P0_ERROR = 5;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_LOCK_ERR = 11;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_WRITE_NVLD = 12;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_GENERAL_TIMEOUT_TRANSIT_STATES_OR_OTHER = 15;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
static const uint32_t TCMC_EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_DETECTED_READ_PARITY_ERROR = 18;


static const uint64_t TCMC_EPS_PSC_PSCOM_MODE_REG = 0x10000ull;

static const uint32_t TCMC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR = 0;
static const uint32_t TCMC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR = 1;
static const uint32_t TCMC_EPS_PSC_PSCOM_MODE_REG_UNUSED_MODE_REG_BIT_2 = 2;
static const uint32_t TCMC_EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR = 3;
static const uint32_t TCMC_EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE = 4;
static const uint32_t TCMC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT = 5;
static const uint32_t TCMC_EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN = 2;
static const uint32_t TCMC_EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS = 7;
static const uint32_t TCMC_EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE = 8;
static const uint32_t TCMC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT = 9;
static const uint32_t TCMC_EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN = 3;


static const uint64_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG = 0x10001ull;

static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_P0_ERROR = 3;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_P0_ERROR = 5;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_LOCK_ERR = 11;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_READ_WRITE_NVLD = 12;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_GENERAL_TIMEOUT_TRANSIT_STATES_OR_OTHER = 15;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_DETECTED_READ_PARITY_ERROR = 18;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_WDATA_PARITY_ERROR = 32;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_ADDRESS_PARITY_ERROR = 33;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_WDATA_PARITY_ERROR = 34;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_P0_ERROR = 35;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_RDATA_PARITY_ERROR = 36;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_P0_ERROR = 37;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_INTERFACE_MACHINE = 38;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_P2S_MACHINE = 39;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 40;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 41;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 42;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_LOCK_ERR = 43;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_READ_WRITE_NVLD = 44;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_ADDR_INVALID = 45;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_COMMAND_PARITY_ERROR = 46;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_GENERAL_TIMEOUT_TRANSIT_STATES_OR_OTHER = 47;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 48;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 49;
static const uint32_t TCMC_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_DETECTED_READ_PARITY_ERROR = 50;


static const uint64_t TCMC_EPS_PSC_RING_FENCE_MASK_LATCH_REG = 0x10008ull;

static const uint32_t TCMC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK = 1;
static const uint32_t TCMC_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN = 31;


static const uint64_t TCMC_EPS_PSC_WRITE_PROTECT_ENABLE_REG = 0x10005ull;

static const uint32_t TCMC_EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING = 0;
static const uint32_t TCMC_EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1;


static const uint64_t TCMC_EPS_PSC_WRITE_PROTECT_RINGS_REG = 0x10006ull;

static const uint32_t TCMC_EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS = 0;
static const uint32_t TCMC_EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS_LEN = 32;


static const uint64_t TCMC_ERROR_STATUS = 0x3000Full;

static const uint32_t TCMC_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR = 0;
static const uint32_t TCMC_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR = 1;
static const uint32_t TCMC_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR = 2;
static const uint32_t TCMC_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR = 3;
static const uint32_t TCMC_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR = 4;
static const uint32_t TCMC_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR = 5;
static const uint32_t TCMC_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR = 6;
static const uint32_t TCMC_ERROR_STATUS_UNUSED_ERROR07 = 7;
static const uint32_t TCMC_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR = 8;
static const uint32_t TCMC_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR = 9;
static const uint32_t TCMC_ERROR_STATUS_UNUSED_ERROR10 = 10;
static const uint32_t TCMC_ERROR_STATUS_SCAN_COLLISION_ERR = 11;
static const uint32_t TCMC_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR = 12;
static const uint32_t TCMC_ERROR_STATUS_OPCG_TRIGGER_ERR = 13;
static const uint32_t TCMC_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR = 14;
static const uint32_t TCMC_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR = 15;
static const uint32_t TCMC_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR = 16;
static const uint32_t TCMC_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR = 17;
static const uint32_t TCMC_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR = 18;
static const uint32_t TCMC_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR = 19;
static const uint32_t TCMC_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR = 20;
static const uint32_t TCMC_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR = 21;
static const uint32_t TCMC_ERROR_STATUS_CLKCMD_REQUEST_ERR = 22;
static const uint32_t TCMC_ERROR_STATUS_CBS_PROTOCOL_ERR = 23;
static const uint32_t TCMC_ERROR_STATUS_VITL_ALIGN_ERR = 24;
static const uint32_t TCMC_ERROR_STATUS_UNUSED_ERROR25 = 25;
static const uint32_t TCMC_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR = 26;
static const uint32_t TCMC_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR = 27;
static const uint32_t TCMC_ERROR_STATUS_DCM_SYNC_EN_ERR = 28;
static const uint32_t TCMC_ERROR_STATUS_DCM_PHASE_COUNT_COMPARE_CHECK_ERR = 29;
static const uint32_t TCMC_ERROR_STATUS_UNUSED_ERROR30 = 30;
static const uint32_t TCMC_ERROR_STATUS_UNUSED_ERROR31 = 31;


static const uint64_t TCMC_LFIR_WO_OR = 0x40101ull;
static const uint64_t TCMC_LFIR_RW_WCLEAR = 0x40100ull;

static const uint32_t TCMC_LFIR_CFIR = 0;
static const uint32_t TCMC_LFIR_CPLT_CTRL = 1;
static const uint32_t TCMC_LFIR_CC_PCB = 2;
static const uint32_t TCMC_LFIR_CC_OTHERS = 3;
static const uint32_t TCMC_LFIR_IN04 = 4;
static const uint32_t TCMC_LFIR_IN05 = 5;
static const uint32_t TCMC_LFIR_IN06 = 6;
static const uint32_t TCMC_LFIR_IN07 = 7;
static const uint32_t TCMC_LFIR_IN08 = 8;
static const uint32_t TCMC_LFIR_IN09 = 9;
static const uint32_t TCMC_LFIR_IN10 = 10;
static const uint32_t TCMC_LFIR_IN11 = 11;
static const uint32_t TCMC_LFIR_IN12 = 12;
static const uint32_t TCMC_LFIR_IN13 = 13;
static const uint32_t TCMC_LFIR_IN14 = 14;
static const uint32_t TCMC_LFIR_IN15 = 15;
static const uint32_t TCMC_LFIR_IN16 = 16;
static const uint32_t TCMC_LFIR_IN17 = 17;
static const uint32_t TCMC_LFIR_IN18 = 18;
static const uint32_t TCMC_LFIR_IN19 = 19;
static const uint32_t TCMC_LFIR_IN20 = 20;
static const uint32_t TCMC_LFIR_IN21 = 21;
static const uint32_t TCMC_LFIR_IN22 = 22;
static const uint32_t TCMC_LFIR_IN23 = 23;
static const uint32_t TCMC_LFIR_IN24 = 24;
static const uint32_t TCMC_LFIR_IN25 = 25;
static const uint32_t TCMC_LFIR_IN26 = 26;
static const uint32_t TCMC_LFIR_IN27 = 27;
static const uint32_t TCMC_LFIR_IN28 = 28;
static const uint32_t TCMC_LFIR_IN29 = 29;
static const uint32_t TCMC_LFIR_IN30 = 30;
static const uint32_t TCMC_LFIR_IN31 = 31;
static const uint32_t TCMC_LFIR_IN32 = 32;
static const uint32_t TCMC_LFIR_IN33 = 33;
static const uint32_t TCMC_LFIR_IN34 = 34;
static const uint32_t TCMC_LFIR_IN35 = 35;
static const uint32_t TCMC_LFIR_IN36 = 36;
static const uint32_t TCMC_LFIR_IN37 = 37;
static const uint32_t TCMC_LFIR_IN38 = 38;
static const uint32_t TCMC_LFIR_IN39 = 39;
static const uint32_t TCMC_LFIR_IN40 = 40;
static const uint32_t TCMC_LFIR_IN41 = 41;
static const uint32_t TCMC_LFIR_IN42 = 42;
static const uint32_t TCMC_LFIR_IN43 = 43;
static const uint32_t TCMC_LFIR_IN44 = 44;
static const uint32_t TCMC_LFIR_IN45 = 45;
static const uint32_t TCMC_LFIR_IN46 = 46;
static const uint32_t TCMC_LFIR_IN47 = 47;
static const uint32_t TCMC_LFIR_IN48 = 48;
static const uint32_t TCMC_LFIR_IN49 = 49;
static const uint32_t TCMC_LFIR_IN50 = 50;
static const uint32_t TCMC_LFIR_IN51 = 51;
static const uint32_t TCMC_LFIR_IN52 = 52;
static const uint32_t TCMC_LFIR_IN53 = 53;
static const uint32_t TCMC_LFIR_IN54 = 54;
static const uint32_t TCMC_LFIR_IN55 = 55;
static const uint32_t TCMC_LFIR_IN56 = 56;
static const uint32_t TCMC_LFIR_IN57 = 57;
static const uint32_t TCMC_LFIR_IN58 = 58;
static const uint32_t TCMC_LFIR_IN59 = 59;
static const uint32_t TCMC_LFIR_IN60 = 60;
static const uint32_t TCMC_LFIR_IN61 = 61;
static const uint32_t TCMC_LFIR_IN62 = 62;
static const uint32_t TCMC_LFIR_EXT_LOCAL_XSTOP = 63;


static const uint64_t TCMC_LOCAL_XSTOP = 0x40003ull;

static const uint32_t TCMC_LOCAL_XSTOP_ANY_LOCAL_XSTOP = 0;
static const uint32_t TCMC_LOCAL_XSTOP_RESERVED1L = 1;
static const uint32_t TCMC_LOCAL_XSTOP_RESERVED2L = 2;
static const uint32_t TCMC_LOCAL_XSTOP_RESERVED3L = 3;
static const uint32_t TCMC_LOCAL_XSTOP_LOCAL_XSTOP_PERV = 4;
static const uint32_t TCMC_LOCAL_XSTOP_LOCAL_XSTOP_IN05 = 5;
static const uint32_t TCMC_LOCAL_XSTOP_LOCAL_XSTOP_IN06 = 6;
static const uint32_t TCMC_LOCAL_XSTOP_LOCAL_XSTOP_IN07 = 7;
static const uint32_t TCMC_LOCAL_XSTOP_LOCAL_XSTOP_IN08 = 8;
static const uint32_t TCMC_LOCAL_XSTOP_LOCAL_XSTOP_IN09 = 9;
static const uint32_t TCMC_LOCAL_XSTOP_LOCAL_XSTOP_IN10 = 10;
static const uint32_t TCMC_LOCAL_XSTOP_LOCAL_XSTOP_IN11 = 11;
static const uint32_t TCMC_LOCAL_XSTOP_LOCAL_XSTOP_IN12 = 12;
static const uint32_t TCMC_LOCAL_XSTOP_LOCAL_XSTOP_IN13 = 13;
static const uint32_t TCMC_LOCAL_XSTOP_LOCAL_XSTOP_IN14 = 14;
static const uint32_t TCMC_LOCAL_XSTOP_LOCAL_XSTOP_IN15 = 15;


static const uint64_t TCMC_LOCAL_XSTOP_MASK_WO_CLEAR = 0x40063ull;
static const uint64_t TCMC_LOCAL_XSTOP_MASK_WO_OR = 0x40053ull;
static const uint64_t TCMC_LOCAL_XSTOP_MASK_RW = 0x40043ull;

static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK_UNUSED = 0;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK01 = 1;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK02 = 2;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK03 = 3;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK04 = 4;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK05 = 5;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK06 = 6;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK07 = 7;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK08 = 8;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK09 = 9;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK10 = 10;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK11 = 11;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK12 = 12;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK13 = 13;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK14 = 14;
static const uint32_t TCMC_LOCAL_XSTOP_MASK_MASK15 = 15;


static const uint64_t TCMC_LOCAL_XSTOP_UNMASKED = 0x40013ull;

static const uint32_t TCMC_LOCAL_XSTOP_UNMASKED_LOCAL_XSTOP_UNMASKED_IN = 1;
static const uint32_t TCMC_LOCAL_XSTOP_UNMASKED_LOCAL_XSTOP_UNMASKED_IN_LEN = 15;


static const uint64_t TCMC_OPCG_ALIGN = 0x30001ull;

static const uint32_t TCMC_OPCG_ALIGN_INOP_ALIGN = 0;
static const uint32_t TCMC_OPCG_ALIGN_INOP_ALIGN_LEN = 4;
static const uint32_t TCMC_OPCG_ALIGN_SNOP_ALIGN = 4;
static const uint32_t TCMC_OPCG_ALIGN_SNOP_ALIGN_LEN = 4;
static const uint32_t TCMC_OPCG_ALIGN_ENOP_ALIGN = 8;
static const uint32_t TCMC_OPCG_ALIGN_ENOP_ALIGN_LEN = 4;
static const uint32_t TCMC_OPCG_ALIGN_INOP_WAIT = 12;
static const uint32_t TCMC_OPCG_ALIGN_INOP_WAIT_LEN = 8;
static const uint32_t TCMC_OPCG_ALIGN_SNOP_WAIT = 20;
static const uint32_t TCMC_OPCG_ALIGN_SNOP_WAIT_LEN = 12;
static const uint32_t TCMC_OPCG_ALIGN_ENOP_WAIT = 32;
static const uint32_t TCMC_OPCG_ALIGN_ENOP_WAIT_LEN = 8;
static const uint32_t TCMC_OPCG_ALIGN_INOP_FORCE_SG = 40;
static const uint32_t TCMC_OPCG_ALIGN_SNOP_FORCE_SG = 41;
static const uint32_t TCMC_OPCG_ALIGN_ENOP_FORCE_SG = 42;
static const uint32_t TCMC_OPCG_ALIGN_NO_WAIT_ON_CLK_CMD = 43;
static const uint32_t TCMC_OPCG_ALIGN_UNUSED4445 = 44;
static const uint32_t TCMC_OPCG_ALIGN_UNUSED4445_LEN = 2;
static const uint32_t TCMC_OPCG_ALIGN_UNUSED46 = 46;
static const uint32_t TCMC_OPCG_ALIGN_SCAN_RATIO = 47;
static const uint32_t TCMC_OPCG_ALIGN_SCAN_RATIO_LEN = 5;
static const uint32_t TCMC_OPCG_ALIGN_OPCG_WAIT_CYCLES = 52;
static const uint32_t TCMC_OPCG_ALIGN_OPCG_WAIT_CYCLES_LEN = 12;


static const uint64_t TCMC_OPCG_CAPT1 = 0x30010ull;

static const uint32_t TCMC_OPCG_CAPT1_COUNT = 0;
static const uint32_t TCMC_OPCG_CAPT1_COUNT_LEN = 4;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_01 = 4;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_01_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_02 = 9;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_02_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_03 = 14;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_03_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_04 = 19;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_04_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_05 = 24;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_05_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_06 = 29;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_06_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_07 = 34;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_07_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_08 = 39;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_08_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_09 = 44;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_09_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_10 = 49;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_10_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_11 = 54;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_11_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_12 = 59;
static const uint32_t TCMC_OPCG_CAPT1_SEQ_12_LEN = 5;


static const uint64_t TCMC_OPCG_CAPT2 = 0x30011ull;

static const uint32_t TCMC_OPCG_CAPT2_UNUSED_CAPT2 = 0;
static const uint32_t TCMC_OPCG_CAPT2_UNUSED_CAPT2_LEN = 4;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_13_01EVEN = 4;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_13_01EVEN_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_14_01ODD = 9;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_14_01ODD_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_15_02EVEN = 14;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_15_02EVEN_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_16_02ODD = 19;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_16_02ODD_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_17_03EVEN = 24;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_17_03EVEN_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_18_03ODD = 29;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_18_03ODD_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_19_04EVEN = 34;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_19_04EVEN_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_20_04ODD = 39;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_20_04ODD_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_21_05EVEN = 44;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_21_05EVEN_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_22_05ODD = 49;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_22_05ODD_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_23_06EVEN = 54;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_23_06EVEN_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_24_06ODD = 59;
static const uint32_t TCMC_OPCG_CAPT2_SEQ_24_06ODD_LEN = 5;


static const uint64_t TCMC_OPCG_CAPT3 = 0x30012ull;

static const uint32_t TCMC_OPCG_CAPT3_UNUSED_CAPT3 = 0;
static const uint32_t TCMC_OPCG_CAPT3_UNUSED_CAPT3_LEN = 4;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_07EVEN = 4;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_07EVEN_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_07ODD = 9;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_07ODD_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_08EVEN = 14;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_08EVEN_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_08ODD = 19;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_08ODD_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_09EVEN = 24;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_09EVEN_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_09ODD = 29;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_09ODD_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_10EVEN = 34;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_10EVEN_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_10ODD = 39;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_10ODD_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_11EVEN = 44;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_11EVEN_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_11ODD = 49;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_11ODD_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_12EVEN = 54;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_12EVEN_LEN = 5;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_12ODD = 59;
static const uint32_t TCMC_OPCG_CAPT3_SEQ_12ODD_LEN = 5;


static const uint64_t TCMC_OPCG_REG0 = 0x30002ull;

static const uint32_t TCMC_OPCG_REG0_RUNN_MODE = 0;
static const uint32_t TCMC_OPCG_REG0_OPCG_GO = 1;
static const uint32_t TCMC_OPCG_REG0_RUN_SCAN0 = 2;
static const uint32_t TCMC_OPCG_REG0_SCAN0_MODE = 3;
static const uint32_t TCMC_OPCG_REG0_OPCG_TRIGGER_RCVR_MODE = 4;
static const uint32_t TCMC_OPCG_REG0_OPCG_TRIGGER_CTRL_MODE = 5;
static const uint32_t TCMC_OPCG_REG0_KEEP_TRIGGER_MODE_ACTIVE = 6;
static const uint32_t TCMC_OPCG_REG0_CTRL_MODE_TRIGGER_ALIGN = 7;
static const uint32_t TCMC_OPCG_REG0_CTRL_MODE_TRIGGER_ALIGN_LEN = 4;
static const uint32_t TCMC_OPCG_REG0_UNUSED_REG0_1112 = 11;
static const uint32_t TCMC_OPCG_REG0_UNUSED_REG0_1112_LEN = 2;
static const uint32_t TCMC_OPCG_REG0_STOP_RUNN_ON_XSTOP = 13;
static const uint32_t TCMC_OPCG_REG0_OPCG_STARTS_BIST = 14;
static const uint32_t TCMC_OPCG_REG0_RUNN_HLD_DLY_EN = 15;
static const uint32_t TCMC_OPCG_REG0_UNUSED_REG0_1620 = 16;
static const uint32_t TCMC_OPCG_REG0_UNUSED_REG0_1620_LEN = 5;
static const uint32_t TCMC_OPCG_REG0_LOOP_COUNT = 21;
static const uint32_t TCMC_OPCG_REG0_LOOP_COUNT_LEN = 43;


static const uint64_t TCMC_OPCG_REG1 = 0x30003ull;

static const uint32_t TCMC_OPCG_REG1_SCAN_COUNT = 0;
static const uint32_t TCMC_OPCG_REG1_SCAN_COUNT_LEN = 12;
static const uint32_t TCMC_OPCG_REG1_MISR_A_VAL = 12;
static const uint32_t TCMC_OPCG_REG1_MISR_A_VAL_LEN = 12;
static const uint32_t TCMC_OPCG_REG1_MISR_B_VAL = 24;
static const uint32_t TCMC_OPCG_REG1_MISR_B_VAL_LEN = 12;
static const uint32_t TCMC_OPCG_REG1_MISR_INIT_WAIT = 36;
static const uint32_t TCMC_OPCG_REG1_MISR_INIT_WAIT_LEN = 12;
static const uint32_t TCMC_OPCG_REG1_UNUSED48 = 48;
static const uint32_t TCMC_OPCG_REG1_SCAN_CLK_USE_EVEN = 49;
static const uint32_t TCMC_OPCG_REG1_DISABLE_FCE_DURING_FILL = 50;
static const uint32_t TCMC_OPCG_REG1_LBIST_SKITTER_CTL_EN = 51;
static const uint32_t TCMC_OPCG_REG1_RTIM_THOLD_FORCE = 52;
static const uint32_t TCMC_OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL = 53;
static const uint32_t TCMC_OPCG_REG1_SG_HIGH_DURING_FILL = 54;
static const uint32_t TCMC_OPCG_REG1_LBIST_SKITTER_CTL = 55;
static const uint32_t TCMC_OPCG_REG1_LBIST_SKITTER_CTL_LEN = 2;
static const uint32_t TCMC_OPCG_REG1_MISR_MODE = 57;
static const uint32_t TCMC_OPCG_REG1_INFINITE_MODE = 58;
static const uint32_t TCMC_OPCG_REG1_NSL_FILL_COUNT = 59;
static const uint32_t TCMC_OPCG_REG1_NSL_FILL_COUNT_LEN = 5;


static const uint64_t TCMC_OPCG_REG2 = 0x30004ull;

static const uint32_t TCMC_OPCG_REG2_OPCG_GO2 = 0;
static const uint32_t TCMC_OPCG_REG2_PRPG_WEIGHTING = 1;
static const uint32_t TCMC_OPCG_REG2_PRPG_WEIGHTING_LEN = 3;
static const uint32_t TCMC_OPCG_REG2_PRPG_SEED = 4;
static const uint32_t TCMC_OPCG_REG2_PRPG_SEED_LEN = 12;
static const uint32_t TCMC_OPCG_REG2_PRPG_A_VAL = 16;
static const uint32_t TCMC_OPCG_REG2_PRPG_A_VAL_LEN = 12;
static const uint32_t TCMC_OPCG_REG2_PRPG_B_VAL = 28;
static const uint32_t TCMC_OPCG_REG2_PRPG_B_VAL_LEN = 12;
static const uint32_t TCMC_OPCG_REG2_PRPG_MODE = 40;
static const uint32_t TCMC_OPCG_REG2_UNUSED41_47 = 41;
static const uint32_t TCMC_OPCG_REG2_UNUSED41_47_LEN = 7;
static const uint32_t TCMC_OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM = 48;
static const uint32_t TCMC_OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM_LEN = 4;
static const uint32_t TCMC_OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK = 52;
static const uint32_t TCMC_OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK_LEN = 4;
static const uint32_t TCMC_OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT = 56;
static const uint32_t TCMC_OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE = 57;
static const uint32_t TCMC_OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE = 58;
static const uint32_t TCMC_OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE = 59;
static const uint32_t TCMC_OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT = 60;
static const uint32_t TCMC_OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT_LEN = 4;


static const uint64_t TCMC_PCB_OPCG_GO = 0x30020ull;

static const uint32_t TCMC_PCB_OPCG_GO_PCB_OPCGGO = 0;


static const uint64_t TCMC_PCB_OPCG_STOP = 0x30030ull;

static const uint32_t TCMC_PCB_OPCG_STOP_PCB_OPCGSTOP = 0;


static const uint64_t TCMC_PHASE_COUNTER_RESET = 0x30028ull;

static const uint32_t TCMC_PHASE_COUNTER_RESET_PHASECOUNTER_RESET = 0;


static const uint64_t TCMC_RECOV = 0x40001ull;

static const uint32_t TCMC_RECOV_ANY_RECOV = 0;
static const uint32_t TCMC_RECOV_RESERVED1R = 1;
static const uint32_t TCMC_RECOV_RECOV_ANY_LOCAL_XSTOP = 2;
static const uint32_t TCMC_RECOV_RESERVED3R = 3;
static const uint32_t TCMC_RECOV_RECOV_PERV = 4;
static const uint32_t TCMC_RECOV_RECOV_IN05 = 5;
static const uint32_t TCMC_RECOV_RECOV_IN06 = 6;
static const uint32_t TCMC_RECOV_RECOV_IN07 = 7;
static const uint32_t TCMC_RECOV_RECOV_IN08 = 8;
static const uint32_t TCMC_RECOV_RECOV_IN09 = 9;
static const uint32_t TCMC_RECOV_RECOV_IN10 = 10;
static const uint32_t TCMC_RECOV_RECOV_IN11 = 11;
static const uint32_t TCMC_RECOV_RECOV_IN12 = 12;
static const uint32_t TCMC_RECOV_RECOV_IN13 = 13;
static const uint32_t TCMC_RECOV_RECOV_IN14 = 14;
static const uint32_t TCMC_RECOV_RECOV_IN15 = 15;
static const uint32_t TCMC_RECOV_RECOV_IN16 = 16;
static const uint32_t TCMC_RECOV_RECOV_IN17 = 17;
static const uint32_t TCMC_RECOV_RECOV_IN18 = 18;
static const uint32_t TCMC_RECOV_RECOV_IN19 = 19;
static const uint32_t TCMC_RECOV_RECOV_IN20 = 20;
static const uint32_t TCMC_RECOV_RECOV_IN21 = 21;
static const uint32_t TCMC_RECOV_RECOV_IN22 = 22;
static const uint32_t TCMC_RECOV_RECOV_IN23 = 23;
static const uint32_t TCMC_RECOV_RECOV_IN24 = 24;
static const uint32_t TCMC_RECOV_RECOV_IN25 = 25;
static const uint32_t TCMC_RECOV_RECOV_IN26 = 26;
static const uint32_t TCMC_RECOV_RECOV_IN27 = 27;
static const uint32_t TCMC_RECOV_RECOV_IN28 = 28;
static const uint32_t TCMC_RECOV_RECOV_IN29 = 29;
static const uint32_t TCMC_RECOV_RECOV_IN30 = 30;
static const uint32_t TCMC_RECOV_RECOV_IN31 = 31;
static const uint32_t TCMC_RECOV_RECOV_IN32 = 32;
static const uint32_t TCMC_RECOV_RECOV_IN33 = 33;
static const uint32_t TCMC_RECOV_RECOV_IN34 = 34;
static const uint32_t TCMC_RECOV_RECOV_IN35 = 35;
static const uint32_t TCMC_RECOV_RECOV_IN36 = 36;
static const uint32_t TCMC_RECOV_RECOV_IN37 = 37;
static const uint32_t TCMC_RECOV_RECOV_IN38 = 38;
static const uint32_t TCMC_RECOV_RECOV_IN39 = 39;
static const uint32_t TCMC_RECOV_RECOV_IN40 = 40;
static const uint32_t TCMC_RECOV_RECOV_IN41 = 41;
static const uint32_t TCMC_RECOV_RECOV_IN42 = 42;
static const uint32_t TCMC_RECOV_RECOV_IN43 = 43;
static const uint32_t TCMC_RECOV_RECOV_IN44 = 44;
static const uint32_t TCMC_RECOV_RECOV_IN45 = 45;
static const uint32_t TCMC_RECOV_RECOV_IN46 = 46;
static const uint32_t TCMC_RECOV_RECOV_IN47 = 47;
static const uint32_t TCMC_RECOV_RECOV_IN48 = 48;
static const uint32_t TCMC_RECOV_RECOV_IN49 = 49;
static const uint32_t TCMC_RECOV_RECOV_IN50 = 50;
static const uint32_t TCMC_RECOV_RECOV_IN51 = 51;
static const uint32_t TCMC_RECOV_RECOV_IN52 = 52;
static const uint32_t TCMC_RECOV_RECOV_IN53 = 53;


static const uint64_t TCMC_RECOV_MASK_WO_CLEAR = 0x40061ull;
static const uint64_t TCMC_RECOV_MASK_WO_OR = 0x40051ull;
static const uint64_t TCMC_RECOV_MASK_RW = 0x40041ull;

static const uint32_t TCMC_RECOV_MASK_MASK_UNUSED = 0;
static const uint32_t TCMC_RECOV_MASK_MASK01 = 1;
static const uint32_t TCMC_RECOV_MASK_MASK02 = 2;
static const uint32_t TCMC_RECOV_MASK_MASK03 = 3;
static const uint32_t TCMC_RECOV_MASK_MASK04 = 4;
static const uint32_t TCMC_RECOV_MASK_MASK05 = 5;
static const uint32_t TCMC_RECOV_MASK_MASK06 = 6;
static const uint32_t TCMC_RECOV_MASK_MASK07 = 7;
static const uint32_t TCMC_RECOV_MASK_MASK08 = 8;
static const uint32_t TCMC_RECOV_MASK_MASK09 = 9;
static const uint32_t TCMC_RECOV_MASK_MASK010 = 10;
static const uint32_t TCMC_RECOV_MASK_MASK011 = 11;
static const uint32_t TCMC_RECOV_MASK_MASK012 = 12;
static const uint32_t TCMC_RECOV_MASK_MASK013 = 13;
static const uint32_t TCMC_RECOV_MASK_MASK014 = 14;
static const uint32_t TCMC_RECOV_MASK_MASK015 = 15;
static const uint32_t TCMC_RECOV_MASK_MASK016 = 16;
static const uint32_t TCMC_RECOV_MASK_MASK017 = 17;
static const uint32_t TCMC_RECOV_MASK_MASK018 = 18;
static const uint32_t TCMC_RECOV_MASK_MASK019 = 19;
static const uint32_t TCMC_RECOV_MASK_MASK020 = 20;
static const uint32_t TCMC_RECOV_MASK_MASK021 = 21;
static const uint32_t TCMC_RECOV_MASK_MASK022 = 22;
static const uint32_t TCMC_RECOV_MASK_MASK023 = 23;
static const uint32_t TCMC_RECOV_MASK_MASK024 = 24;
static const uint32_t TCMC_RECOV_MASK_MASK025 = 25;
static const uint32_t TCMC_RECOV_MASK_MASK026 = 26;
static const uint32_t TCMC_RECOV_MASK_MASK027 = 27;
static const uint32_t TCMC_RECOV_MASK_MASK028 = 28;
static const uint32_t TCMC_RECOV_MASK_MASK029 = 29;
static const uint32_t TCMC_RECOV_MASK_MASK030 = 30;
static const uint32_t TCMC_RECOV_MASK_MASK031 = 31;
static const uint32_t TCMC_RECOV_MASK_MASK032 = 32;
static const uint32_t TCMC_RECOV_MASK_MASK033 = 33;
static const uint32_t TCMC_RECOV_MASK_MASK034 = 34;
static const uint32_t TCMC_RECOV_MASK_MASK035 = 35;
static const uint32_t TCMC_RECOV_MASK_MASK036 = 36;
static const uint32_t TCMC_RECOV_MASK_MASK037 = 37;
static const uint32_t TCMC_RECOV_MASK_MASK038 = 38;
static const uint32_t TCMC_RECOV_MASK_MASK039 = 39;
static const uint32_t TCMC_RECOV_MASK_MASK040 = 40;
static const uint32_t TCMC_RECOV_MASK_MASK041 = 41;
static const uint32_t TCMC_RECOV_MASK_MASK042 = 42;
static const uint32_t TCMC_RECOV_MASK_MASK043 = 43;
static const uint32_t TCMC_RECOV_MASK_MASK044 = 44;
static const uint32_t TCMC_RECOV_MASK_MASK045 = 45;
static const uint32_t TCMC_RECOV_MASK_MASK046 = 46;
static const uint32_t TCMC_RECOV_MASK_MASK047 = 47;
static const uint32_t TCMC_RECOV_MASK_MASK048 = 48;
static const uint32_t TCMC_RECOV_MASK_MASK049 = 49;
static const uint32_t TCMC_RECOV_MASK_MASK050 = 50;
static const uint32_t TCMC_RECOV_MASK_MASK051 = 51;
static const uint32_t TCMC_RECOV_MASK_MASK052 = 52;
static const uint32_t TCMC_RECOV_MASK_MASK053 = 53;


static const uint64_t TCMC_RECOV_UNMASKED = 0x40011ull;

static const uint32_t TCMC_RECOV_UNMASKED_RECOV_UNMASKED_IN = 1;
static const uint32_t TCMC_RECOV_UNMASKED_RECOV_UNMASKED_IN_LEN = 53;


static const uint64_t TCMC_REGION_CCFLUSH_STATUS = 0x30016ull;

static const uint32_t TCMC_REGION_CCFLUSH_STATUS_REGION_CCFLUSH = 4;
static const uint32_t TCMC_REGION_CCFLUSH_STATUS_REGION_CCFLUSH_LEN = 15;


static const uint64_t TCMC_SCAN = 0x38000ull;

static const uint32_t TCMC_SCAN_SCAN_BUFFER = 0;
static const uint32_t TCMC_SCAN_SCAN_BUFFER_LEN = 64;


static const uint64_t TCMC_SCAN64 = 0x3E000ull;

static const uint32_t TCMC_SCAN64_SCAN64_BUFFER = 0;
static const uint32_t TCMC_SCAN64_SCAN64_BUFFER_LEN = 64;


static const uint64_t TCMC_SCAN64CONTSCAN = 0x3F000ull;

static const uint32_t TCMC_SCAN64CONTSCAN_SCAN64CONTSCAN_REG = 0;
static const uint32_t TCMC_SCAN64CONTSCAN_SCAN64CONTSCAN_REG_LEN = 64;


static const uint64_t TCMC_SCAN_LONG_ROTATE = 0x39000ull;

static const uint32_t TCMC_SCAN_LONG_ROTATE_LRO_SCANCOUNT = 12;
static const uint32_t TCMC_SCAN_LONG_ROTATE_LRO_SCANCOUNT_LEN = 20;


static const uint64_t TCMC_SCAN_REGION_TYPE = 0x30005ull;

static const uint32_t TCMC_SCAN_REGION_TYPE_SYSTEM_FAST_INIT = 0;
static const uint32_t TCMC_SCAN_REGION_TYPE_PARALLEL_SCAN = 1;
static const uint32_t TCMC_SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR = 2;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_VITL = 3;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_PERV = 4;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT1 = 5;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT2 = 6;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT3 = 7;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT4 = 8;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT5 = 9;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT6 = 10;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT7 = 11;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT8 = 12;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT9 = 13;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT10 = 14;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT11 = 15;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT12 = 16;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT13 = 17;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_REGION_UNIT14 = 18;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_TYPE_FUNC = 48;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_TYPE_CFG = 49;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR = 50;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_TYPE_REGF = 51;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_TYPE_LBIST = 52;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_TYPE_ABIST = 53;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_TYPE_REPR = 54;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_TYPE_TIME = 55;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_TYPE_BNDY = 56;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_TYPE_FARR = 57;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_TYPE_CMSK = 58;
static const uint32_t TCMC_SCAN_REGION_TYPE_SCAN_TYPE_INEX = 59;


static const uint64_t TCMC_SYNC_CONFIG = 0x30000ull;

static const uint32_t TCMC_SYNC_CONFIG_SYNC_PULSE_DELAY = 0;
static const uint32_t TCMC_SYNC_CONFIG_SYNC_PULSE_DELAY_LEN = 4;
static const uint32_t TCMC_SYNC_CONFIG_SYNC_PULSE_INPUT_DIS = 4;
static const uint32_t TCMC_SYNC_CONFIG_SYNC_PULSE_INPUT_SEL = 5;
static const uint32_t TCMC_SYNC_CONFIG_SYNC_PULSE_OUT_DIS = 6;
static const uint32_t TCMC_SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED = 7;
static const uint32_t TCMC_SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD = 8;
static const uint32_t TCMC_SYNC_CONFIG_DISABLE_PCB_ITR = 9;
static const uint32_t TCMC_SYNC_CONFIG_CONT_SCAN_DISABLE = 10;
static const uint32_t TCMC_SYNC_CONFIG_UNUSED11 = 11;
static const uint32_t TCMC_SYNC_CONFIG_REGION_PGOOD_OVERRIDE = 12;
static const uint32_t TCMC_SYNC_CONFIG_CONT_SCAN_SHORT_WAIT = 13;
static const uint32_t TCMC_SYNC_CONFIG_VITL_ALIGN_CHECK_EN = 14;
static const uint32_t TCMC_SYNC_CONFIG_PHASE_COUNT_ON_CLKCHANGE_EN = 15;
static const uint32_t TCMC_SYNC_CONFIG_UNUSED1617 = 16;
static const uint32_t TCMC_SYNC_CONFIG_UNUSED1617_LEN = 2;
static const uint32_t TCMC_SYNC_CONFIG_UNUSED1823 = 18;
static const uint32_t TCMC_SYNC_CONFIG_UNUSED1823_LEN = 6;
static const uint32_t TCMC_SYNC_CONFIG_UNUSED2427 = 24;
static const uint32_t TCMC_SYNC_CONFIG_UNUSED2427_LEN = 4;
static const uint32_t TCMC_SYNC_CONFIG_DCM_SYNC_PULSE_IN_EN = 28;
static const uint32_t TCMC_SYNC_CONFIG_DCM_SYNC_PULSE_OUT_EN = 29;
static const uint32_t TCMC_SYNC_CONFIG_DCM_SYNC_TO_HALF_OUT_EN = 30;
static const uint32_t TCMC_SYNC_CONFIG_DCM_SYNC_WITH_CC_EN = 31;
static const uint32_t TCMC_SYNC_CONFIG_DCM_PHASE_COUNT_COMPARE_CHECK_EN = 32;
static const uint32_t TCMC_SYNC_CONFIG_DCM_MUX_OUT0_SEL = 33;
static const uint32_t TCMC_SYNC_CONFIG_DCM_MUX_OUT0_SEL_LEN = 3;
static const uint32_t TCMC_SYNC_CONFIG_UNUSED36 = 36;
static const uint32_t TCMC_SYNC_CONFIG_DCM_MUX_OUT1_SEL = 37;
static const uint32_t TCMC_SYNC_CONFIG_DCM_MUX_OUT1_SEL_LEN = 3;
static const uint32_t TCMC_SYNC_CONFIG_DCM_MUX_IN0_SEL = 40;
static const uint32_t TCMC_SYNC_CONFIG_DCM_MUX_IN0_SEL_LEN = 2;
static const uint32_t TCMC_SYNC_CONFIG_DCM_MUX_IN1_SEL = 42;
static const uint32_t TCMC_SYNC_CONFIG_DCM_MUX_IN1_SEL_LEN = 2;
static const uint32_t TCMC_SYNC_CONFIG_DCM_OUTGOING_RATIO = 44;
static const uint32_t TCMC_SYNC_CONFIG_DCM_OUTGOING_RATIO_LEN = 3;
static const uint32_t TCMC_SYNC_CONFIG_DCM_OUTGOING_SHIFT = 47;
static const uint32_t TCMC_SYNC_CONFIG_DCM_OUTGOING_SHIFT_LEN = 5;
static const uint32_t TCMC_SYNC_CONFIG_DCM_INGOING_RATIO = 52;
static const uint32_t TCMC_SYNC_CONFIG_DCM_INGOING_RATIO_LEN = 3;
static const uint32_t TCMC_SYNC_CONFIG_DCM_INGOING_SHIFT = 55;
static const uint32_t TCMC_SYNC_CONFIG_DCM_INGOING_SHIFT_LEN = 5;
static const uint32_t TCMC_SYNC_CONFIG_UNUSED6061 = 60;
static const uint32_t TCMC_SYNC_CONFIG_UNUSED6061_LEN = 2;
static const uint32_t TCMC_SYNC_CONFIG_REGION2_CLKSTOP_FENCE_OVR_EN = 62;
static const uint32_t TCMC_SYNC_CONFIG_REGION2_CLKSTOP_FENCE_OVR_VAL = 63;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG = 0x10402ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_BANK_MODE = 10;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_CTRL_CROSS_MODE = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_TRACE_CONTROL_UNUSED = 25;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_CTRL_CONFIG_TRACE_CONTROL_UNUSED_LEN = 3;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG = 0x10403ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_CMP_MSK_LT_B_0_TO_63_LEN = 64;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_1 = 0x10404ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_2 = 0x10405ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_2_PATTERNA = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_2_PATTERNA_LEN = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_2_PATTERNB = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_2_PATTERNB_LEN = 24;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_3 = 0x10406ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_3_PATTERNC = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_3_PATTERNC_LEN = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_3_PATTERND = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_3_PATTERND_LEN = 24;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_4 = 0x10407ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_4_MASKA = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_4_MASKA_LEN = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_4_MASKB = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_4_MASKB_LEN = 24;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_5 = 0x10408ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_5_MASKC = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_5_MASKC_LEN = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_5_MASKD = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_5_MASKD_LEN = 24;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9 = 0x10409ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_DATA_CONFIG_9_SPARE_LT = 37;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_HI_DATA_REG = 0x10400ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_LO_DATA_REG = 0x10401ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_0_SAMP_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG = 0x10412ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_BANK_MODE = 10;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_CTRL_CROSS_MODE = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_TRACE_CONTROL_UNUSED = 25;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_CTRL_CONFIG_TRACE_CONTROL_UNUSED_LEN = 3;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG = 0x10414ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_CMP_MSK_LT_B_64_TO_87_LEN = 24;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_0 = 0x10413ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_2 = 0x10415ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_2_PATTERNA = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_2_PATTERNA_LEN = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_2_PATTERNB = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_2_PATTERNB_LEN = 24;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_3 = 0x10416ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_3_PATTERNC = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_3_PATTERNC_LEN = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_3_PATTERND = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_3_PATTERND_LEN = 24;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_4 = 0x10417ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_4_MASKA = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_4_MASKA_LEN = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_4_MASKB = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_4_MASKB_LEN = 24;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_5 = 0x10418ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_5_MASKC = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_5_MASKC_LEN = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_5_MASKD = 24;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_5_MASKD_LEN = 24;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9 = 0x10419ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_DATA_CONFIG_9_SPARE_LT = 37;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_HI_DATA_REG = 0x10410ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;


static const uint64_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_LO_DATA_REG = 0x10411ull;

static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TCMC_TRA0_TRA_SCOMSAT_ARRAY_SELECT_1_SAMP_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;


static const uint64_t TCMC_WOF = 0x40021ull;

static const uint32_t TCMC_WOF_ANY_WOF = 0;
static const uint32_t TCMC_WOF_RESERVED1W = 1;
static const uint32_t TCMC_WOF_WOF_ANY_LOCAL_XSTOP = 2;
static const uint32_t TCMC_WOF_RESERVED3W = 3;
static const uint32_t TCMC_WOF_WOF_PERV = 4;
static const uint32_t TCMC_WOF_WOF_IN05 = 5;
static const uint32_t TCMC_WOF_WOF_IN06 = 6;
static const uint32_t TCMC_WOF_WOF_IN07 = 7;
static const uint32_t TCMC_WOF_WOF_IN08 = 8;
static const uint32_t TCMC_WOF_WOF_IN09 = 9;
static const uint32_t TCMC_WOF_WOF_IN010 = 10;
static const uint32_t TCMC_WOF_WOF_IN011 = 11;
static const uint32_t TCMC_WOF_WOF_IN012 = 12;
static const uint32_t TCMC_WOF_WOF_IN013 = 13;
static const uint32_t TCMC_WOF_WOF_IN014 = 14;
static const uint32_t TCMC_WOF_WOF_IN015 = 15;
static const uint32_t TCMC_WOF_WOF_IN016 = 16;
static const uint32_t TCMC_WOF_WOF_IN017 = 17;
static const uint32_t TCMC_WOF_WOF_IN018 = 18;
static const uint32_t TCMC_WOF_WOF_IN019 = 19;
static const uint32_t TCMC_WOF_WOF_IN020 = 20;
static const uint32_t TCMC_WOF_WOF_IN021 = 21;
static const uint32_t TCMC_WOF_WOF_IN022 = 22;
static const uint32_t TCMC_WOF_WOF_IN023 = 23;
static const uint32_t TCMC_WOF_WOF_IN024 = 24;
static const uint32_t TCMC_WOF_WOF_IN025 = 25;
static const uint32_t TCMC_WOF_WOF_IN026 = 26;
static const uint32_t TCMC_WOF_WOF_IN027 = 27;
static const uint32_t TCMC_WOF_WOF_IN028 = 28;
static const uint32_t TCMC_WOF_WOF_IN029 = 29;
static const uint32_t TCMC_WOF_WOF_IN030 = 30;
static const uint32_t TCMC_WOF_WOF_IN031 = 31;
static const uint32_t TCMC_WOF_WOF_IN032 = 32;
static const uint32_t TCMC_WOF_WOF_IN033 = 33;
static const uint32_t TCMC_WOF_WOF_IN034 = 34;
static const uint32_t TCMC_WOF_WOF_IN035 = 35;
static const uint32_t TCMC_WOF_WOF_IN036 = 36;
static const uint32_t TCMC_WOF_WOF_IN037 = 37;
static const uint32_t TCMC_WOF_WOF_IN038 = 38;
static const uint32_t TCMC_WOF_WOF_IN039 = 39;
static const uint32_t TCMC_WOF_WOF_IN040 = 40;
static const uint32_t TCMC_WOF_WOF_IN041 = 41;
static const uint32_t TCMC_WOF_WOF_IN042 = 42;
static const uint32_t TCMC_WOF_WOF_IN043 = 43;
static const uint32_t TCMC_WOF_WOF_IN044 = 44;
static const uint32_t TCMC_WOF_WOF_IN045 = 45;
static const uint32_t TCMC_WOF_WOF_IN046 = 46;
static const uint32_t TCMC_WOF_WOF_IN047 = 47;
static const uint32_t TCMC_WOF_WOF_IN048 = 48;
static const uint32_t TCMC_WOF_WOF_IN049 = 49;
static const uint32_t TCMC_WOF_WOF_IN050 = 50;
static const uint32_t TCMC_WOF_WOF_IN051 = 51;
static const uint32_t TCMC_WOF_WOF_IN052 = 52;
static const uint32_t TCMC_WOF_WOF_IN053 = 53;


static const uint64_t TCMC_XSTOP = 0x40000ull;

static const uint32_t TCMC_XSTOP_ANY_XSTOP = 0;
static const uint32_t TCMC_XSTOP_SYSTEM_XSTOP = 1;
static const uint32_t TCMC_XSTOP_XSTOP_ANY_ATTN = 2;
static const uint32_t TCMC_XSTOP_DBG_FIR_XSTOP_ON_TRIG = 3;
static const uint32_t TCMC_XSTOP_XSTOP_PERV = 4;
static const uint32_t TCMC_XSTOP_XSTOP_IN05 = 5;
static const uint32_t TCMC_XSTOP_XSTOP_IN06 = 6;
static const uint32_t TCMC_XSTOP_XSTOP_IN07 = 7;
static const uint32_t TCMC_XSTOP_XSTOP_IN08 = 8;
static const uint32_t TCMC_XSTOP_XSTOP_IN09 = 9;
static const uint32_t TCMC_XSTOP_XSTOP_IN10 = 10;
static const uint32_t TCMC_XSTOP_XSTOP_IN11 = 11;
static const uint32_t TCMC_XSTOP_XSTOP_IN12 = 12;
static const uint32_t TCMC_XSTOP_XSTOP_IN13 = 13;
static const uint32_t TCMC_XSTOP_XSTOP_IN14 = 14;
static const uint32_t TCMC_XSTOP_XSTOP_IN15 = 15;
static const uint32_t TCMC_XSTOP_XSTOP_IN16 = 16;
static const uint32_t TCMC_XSTOP_XSTOP_IN17 = 17;
static const uint32_t TCMC_XSTOP_XSTOP_IN18 = 18;
static const uint32_t TCMC_XSTOP_XSTOP_IN19 = 19;
static const uint32_t TCMC_XSTOP_XSTOP_IN20 = 20;
static const uint32_t TCMC_XSTOP_XSTOP_IN21 = 21;
static const uint32_t TCMC_XSTOP_XSTOP_IN22 = 22;
static const uint32_t TCMC_XSTOP_XSTOP_IN23 = 23;
static const uint32_t TCMC_XSTOP_XSTOP_IN24 = 24;
static const uint32_t TCMC_XSTOP_XSTOP_IN25 = 25;
static const uint32_t TCMC_XSTOP_XSTOP_IN26 = 26;
static const uint32_t TCMC_XSTOP_XSTOP_IN27 = 27;
static const uint32_t TCMC_XSTOP_XSTOP_IN28 = 28;
static const uint32_t TCMC_XSTOP_XSTOP_IN29 = 29;
static const uint32_t TCMC_XSTOP_XSTOP_IN30 = 30;
static const uint32_t TCMC_XSTOP_XSTOP_IN31 = 31;
static const uint32_t TCMC_XSTOP_XSTOP_IN32 = 32;
static const uint32_t TCMC_XSTOP_XSTOP_IN33 = 33;
static const uint32_t TCMC_XSTOP_XSTOP_IN34 = 34;
static const uint32_t TCMC_XSTOP_XSTOP_IN35 = 35;
static const uint32_t TCMC_XSTOP_XSTOP_IN36 = 36;
static const uint32_t TCMC_XSTOP_XSTOP_IN37 = 37;
static const uint32_t TCMC_XSTOP_XSTOP_IN38 = 38;
static const uint32_t TCMC_XSTOP_XSTOP_IN39 = 39;
static const uint32_t TCMC_XSTOP_XSTOP_IN40 = 40;
static const uint32_t TCMC_XSTOP_XSTOP_IN41 = 41;
static const uint32_t TCMC_XSTOP_XSTOP_IN42 = 42;
static const uint32_t TCMC_XSTOP_XSTOP_IN43 = 43;
static const uint32_t TCMC_XSTOP_XSTOP_IN44 = 44;
static const uint32_t TCMC_XSTOP_XSTOP_IN45 = 45;
static const uint32_t TCMC_XSTOP_XSTOP_IN46 = 46;
static const uint32_t TCMC_XSTOP_XSTOP_IN47 = 47;
static const uint32_t TCMC_XSTOP_XSTOP_IN48 = 48;
static const uint32_t TCMC_XSTOP_XSTOP_IN49 = 49;
static const uint32_t TCMC_XSTOP_XSTOP_IN50 = 50;
static const uint32_t TCMC_XSTOP_XSTOP_IN51 = 51;
static const uint32_t TCMC_XSTOP_XSTOP_IN52 = 52;
static const uint32_t TCMC_XSTOP_XSTOP_IN53 = 53;


static const uint64_t TCMC_XSTOP1 = 0x3000Cull;

static const uint32_t TCMC_XSTOP1_ENABLE = 0;
static const uint32_t TCMC_XSTOP1_WAIT_SNOPA = 1;
static const uint32_t TCMC_XSTOP1_TRIGGER_OPCG_GO = 2;
static const uint32_t TCMC_XSTOP1_WAIT_ALWAYS = 3;
static const uint32_t TCMC_XSTOP1_REGION_PERV = 4;
static const uint32_t TCMC_XSTOP1_REGION_UNIT1 = 5;
static const uint32_t TCMC_XSTOP1_REGION_UNIT2 = 6;
static const uint32_t TCMC_XSTOP1_REGION_UNIT3 = 7;
static const uint32_t TCMC_XSTOP1_REGION_UNIT4 = 8;
static const uint32_t TCMC_XSTOP1_REGION_UNIT5 = 9;
static const uint32_t TCMC_XSTOP1_REGION_UNIT6 = 10;
static const uint32_t TCMC_XSTOP1_REGION_UNIT7 = 11;
static const uint32_t TCMC_XSTOP1_REGION_UNIT8 = 12;
static const uint32_t TCMC_XSTOP1_REGION_UNIT9 = 13;
static const uint32_t TCMC_XSTOP1_REGION_UNIT10 = 14;
static const uint32_t TCMC_XSTOP1_REGION_UNIT11 = 15;
static const uint32_t TCMC_XSTOP1_REGION_UNIT12 = 16;
static const uint32_t TCMC_XSTOP1_REGION_UNIT13 = 17;
static const uint32_t TCMC_XSTOP1_REGION_UNIT14 = 18;
static const uint32_t TCMC_XSTOP1_WAIT_CYCLES = 48;
static const uint32_t TCMC_XSTOP1_WAIT_CYCLES_LEN = 12;


static const uint64_t TCMC_XSTOP2 = 0x3000Dull;

static const uint32_t TCMC_XSTOP2_ENABLE = 0;
static const uint32_t TCMC_XSTOP2_WAIT_SNOPA = 1;
static const uint32_t TCMC_XSTOP2_TRIGGER_OPCG_GO = 2;
static const uint32_t TCMC_XSTOP2_WAIT_ALWAYS = 3;
static const uint32_t TCMC_XSTOP2_REGION_PERV = 4;
static const uint32_t TCMC_XSTOP2_REGION_UNIT1 = 5;
static const uint32_t TCMC_XSTOP2_REGION_UNIT2 = 6;
static const uint32_t TCMC_XSTOP2_REGION_UNIT3 = 7;
static const uint32_t TCMC_XSTOP2_REGION_UNIT4 = 8;
static const uint32_t TCMC_XSTOP2_REGION_UNIT5 = 9;
static const uint32_t TCMC_XSTOP2_REGION_UNIT6 = 10;
static const uint32_t TCMC_XSTOP2_REGION_UNIT7 = 11;
static const uint32_t TCMC_XSTOP2_REGION_UNIT8 = 12;
static const uint32_t TCMC_XSTOP2_REGION_UNIT9 = 13;
static const uint32_t TCMC_XSTOP2_REGION_UNIT10 = 14;
static const uint32_t TCMC_XSTOP2_REGION_UNIT11 = 15;
static const uint32_t TCMC_XSTOP2_REGION_UNIT12 = 16;
static const uint32_t TCMC_XSTOP2_REGION_UNIT13 = 17;
static const uint32_t TCMC_XSTOP2_REGION_UNIT14 = 18;
static const uint32_t TCMC_XSTOP2_WAIT_CYCLES = 48;
static const uint32_t TCMC_XSTOP2_WAIT_CYCLES_LEN = 12;


static const uint64_t TCMC_XSTOP3 = 0x3000Eull;

static const uint32_t TCMC_XSTOP3_ENABLE = 0;
static const uint32_t TCMC_XSTOP3_WAIT_SNOPA = 1;
static const uint32_t TCMC_XSTOP3_TRIGGER_OPCG_GO = 2;
static const uint32_t TCMC_XSTOP3_WAIT_ALWAYS = 3;
static const uint32_t TCMC_XSTOP3_REGION_PERV = 4;
static const uint32_t TCMC_XSTOP3_REGION_UNIT1 = 5;
static const uint32_t TCMC_XSTOP3_REGION_UNIT2 = 6;
static const uint32_t TCMC_XSTOP3_REGION_UNIT3 = 7;
static const uint32_t TCMC_XSTOP3_REGION_UNIT4 = 8;
static const uint32_t TCMC_XSTOP3_REGION_UNIT5 = 9;
static const uint32_t TCMC_XSTOP3_REGION_UNIT6 = 10;
static const uint32_t TCMC_XSTOP3_REGION_UNIT7 = 11;
static const uint32_t TCMC_XSTOP3_REGION_UNIT8 = 12;
static const uint32_t TCMC_XSTOP3_REGION_UNIT9 = 13;
static const uint32_t TCMC_XSTOP3_REGION_UNIT10 = 14;
static const uint32_t TCMC_XSTOP3_REGION_UNIT11 = 15;
static const uint32_t TCMC_XSTOP3_REGION_UNIT12 = 16;
static const uint32_t TCMC_XSTOP3_REGION_UNIT13 = 17;
static const uint32_t TCMC_XSTOP3_REGION_UNIT14 = 18;
static const uint32_t TCMC_XSTOP3_WAIT_CYCLES = 48;
static const uint32_t TCMC_XSTOP3_WAIT_CYCLES_LEN = 12;


static const uint64_t TCMC_XSTOP4 = 0x30014ull;

static const uint32_t TCMC_XSTOP4_ENABLE = 0;
static const uint32_t TCMC_XSTOP4_WAIT_SNOPA = 1;
static const uint32_t TCMC_XSTOP4_TRIGGER_OPCG_GO = 2;
static const uint32_t TCMC_XSTOP4_WAIT_ALWAYS = 3;
static const uint32_t TCMC_XSTOP4_REGION_PERV = 4;
static const uint32_t TCMC_XSTOP4_REGION_UNIT1 = 5;
static const uint32_t TCMC_XSTOP4_REGION_UNIT2 = 6;
static const uint32_t TCMC_XSTOP4_REGION_UNIT3 = 7;
static const uint32_t TCMC_XSTOP4_REGION_UNIT4 = 8;
static const uint32_t TCMC_XSTOP4_REGION_UNIT5 = 9;
static const uint32_t TCMC_XSTOP4_REGION_UNIT6 = 10;
static const uint32_t TCMC_XSTOP4_REGION_UNIT7 = 11;
static const uint32_t TCMC_XSTOP4_REGION_UNIT8 = 12;
static const uint32_t TCMC_XSTOP4_REGION_UNIT9 = 13;
static const uint32_t TCMC_XSTOP4_REGION_UNIT10 = 14;
static const uint32_t TCMC_XSTOP4_REGION_UNIT11 = 15;
static const uint32_t TCMC_XSTOP4_REGION_UNIT12 = 16;
static const uint32_t TCMC_XSTOP4_REGION_UNIT13 = 17;
static const uint32_t TCMC_XSTOP4_REGION_UNIT14 = 18;
static const uint32_t TCMC_XSTOP4_WAIT_CYCLES = 48;
static const uint32_t TCMC_XSTOP4_WAIT_CYCLES_LEN = 12;


static const uint64_t TCMC_XSTOP5 = 0x30015ull;

static const uint32_t TCMC_XSTOP5_ENABLE = 0;
static const uint32_t TCMC_XSTOP5_WAIT_SNOPA = 1;
static const uint32_t TCMC_XSTOP5_TRIGGER_OPCG_GO = 2;
static const uint32_t TCMC_XSTOP5_WAIT_ALWAYS = 3;
static const uint32_t TCMC_XSTOP5_REGION_PERV = 4;
static const uint32_t TCMC_XSTOP5_REGION_UNIT1 = 5;
static const uint32_t TCMC_XSTOP5_REGION_UNIT2 = 6;
static const uint32_t TCMC_XSTOP5_REGION_UNIT3 = 7;
static const uint32_t TCMC_XSTOP5_REGION_UNIT4 = 8;
static const uint32_t TCMC_XSTOP5_REGION_UNIT5 = 9;
static const uint32_t TCMC_XSTOP5_REGION_UNIT6 = 10;
static const uint32_t TCMC_XSTOP5_REGION_UNIT7 = 11;
static const uint32_t TCMC_XSTOP5_REGION_UNIT8 = 12;
static const uint32_t TCMC_XSTOP5_REGION_UNIT9 = 13;
static const uint32_t TCMC_XSTOP5_REGION_UNIT10 = 14;
static const uint32_t TCMC_XSTOP5_REGION_UNIT11 = 15;
static const uint32_t TCMC_XSTOP5_REGION_UNIT12 = 16;
static const uint32_t TCMC_XSTOP5_REGION_UNIT13 = 17;
static const uint32_t TCMC_XSTOP5_REGION_UNIT14 = 18;
static const uint32_t TCMC_XSTOP5_WAIT_CYCLES = 48;
static const uint32_t TCMC_XSTOP5_WAIT_CYCLES_LEN = 12;


static const uint64_t TCMC_XSTOP_MASK_WO_CLEAR = 0x40060ull;
static const uint64_t TCMC_XSTOP_MASK_WO_OR = 0x40050ull;
static const uint64_t TCMC_XSTOP_MASK_RW = 0x40040ull;

static const uint32_t TCMC_XSTOP_MASK_MASK_UNUSED = 0;
static const uint32_t TCMC_XSTOP_MASK_MASK01 = 1;
static const uint32_t TCMC_XSTOP_MASK_MASK02 = 2;
static const uint32_t TCMC_XSTOP_MASK_MASK03 = 3;
static const uint32_t TCMC_XSTOP_MASK_MASK04 = 4;
static const uint32_t TCMC_XSTOP_MASK_MASK05 = 5;
static const uint32_t TCMC_XSTOP_MASK_MASK06 = 6;
static const uint32_t TCMC_XSTOP_MASK_MASK07 = 7;
static const uint32_t TCMC_XSTOP_MASK_MASK08 = 8;
static const uint32_t TCMC_XSTOP_MASK_MASK09 = 9;
static const uint32_t TCMC_XSTOP_MASK_MASK10 = 10;
static const uint32_t TCMC_XSTOP_MASK_MASK11 = 11;
static const uint32_t TCMC_XSTOP_MASK_MASK12 = 12;
static const uint32_t TCMC_XSTOP_MASK_MASK13 = 13;
static const uint32_t TCMC_XSTOP_MASK_MASK14 = 14;
static const uint32_t TCMC_XSTOP_MASK_MASK15 = 15;
static const uint32_t TCMC_XSTOP_MASK_MASK16 = 16;
static const uint32_t TCMC_XSTOP_MASK_MASK17 = 17;
static const uint32_t TCMC_XSTOP_MASK_MASK18 = 18;
static const uint32_t TCMC_XSTOP_MASK_MASK19 = 19;
static const uint32_t TCMC_XSTOP_MASK_MASK20 = 20;
static const uint32_t TCMC_XSTOP_MASK_MASK21 = 21;
static const uint32_t TCMC_XSTOP_MASK_MASK22 = 22;
static const uint32_t TCMC_XSTOP_MASK_MASK23 = 23;
static const uint32_t TCMC_XSTOP_MASK_MASK24 = 24;
static const uint32_t TCMC_XSTOP_MASK_MASK25 = 25;
static const uint32_t TCMC_XSTOP_MASK_MASK26 = 26;
static const uint32_t TCMC_XSTOP_MASK_MASK27 = 27;
static const uint32_t TCMC_XSTOP_MASK_MASK28 = 28;
static const uint32_t TCMC_XSTOP_MASK_MASK29 = 29;
static const uint32_t TCMC_XSTOP_MASK_MASK30 = 30;
static const uint32_t TCMC_XSTOP_MASK_MASK31 = 31;
static const uint32_t TCMC_XSTOP_MASK_MASK32 = 32;
static const uint32_t TCMC_XSTOP_MASK_MASK33 = 33;
static const uint32_t TCMC_XSTOP_MASK_MASK34 = 34;
static const uint32_t TCMC_XSTOP_MASK_MASK35 = 35;
static const uint32_t TCMC_XSTOP_MASK_MASK36 = 36;
static const uint32_t TCMC_XSTOP_MASK_MASK37 = 37;
static const uint32_t TCMC_XSTOP_MASK_MASK38 = 38;
static const uint32_t TCMC_XSTOP_MASK_MASK39 = 39;
static const uint32_t TCMC_XSTOP_MASK_MASK40 = 40;
static const uint32_t TCMC_XSTOP_MASK_MASK41 = 41;
static const uint32_t TCMC_XSTOP_MASK_MASK42 = 42;
static const uint32_t TCMC_XSTOP_MASK_MASK43 = 43;
static const uint32_t TCMC_XSTOP_MASK_MASK44 = 44;
static const uint32_t TCMC_XSTOP_MASK_MASK45 = 45;
static const uint32_t TCMC_XSTOP_MASK_MASK46 = 46;
static const uint32_t TCMC_XSTOP_MASK_MASK47 = 47;
static const uint32_t TCMC_XSTOP_MASK_MASK48 = 48;
static const uint32_t TCMC_XSTOP_MASK_MASK49 = 49;
static const uint32_t TCMC_XSTOP_MASK_MASK50 = 50;
static const uint32_t TCMC_XSTOP_MASK_MASK51 = 51;
static const uint32_t TCMC_XSTOP_MASK_MASK52 = 52;
static const uint32_t TCMC_XSTOP_MASK_MASK53 = 53;


static const uint64_t TCMC_XSTOP_UNMASKED = 0x40010ull;

static const uint32_t TCMC_XSTOP_UNMASKED_XSTOP_UNMASKED_IN = 1;
static const uint32_t TCMC_XSTOP_UNMASKED_XSTOP_UNMASKED_IN_LEN = 53;



#ifndef __PPE_HCODE__
}
}
#endif

#ifndef SCOMT_OMIT_FIELD_ACCESSORS
    #include "ody_scom_perv_tcmc_fields.H"
#endif
