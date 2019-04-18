/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_7.H $       */
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

#ifndef __p10_scom_omic_7_H_
#define __p10_scom_omic_7_H_


namespace scomt
{
namespace omic
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_CTL_REGS_RX_MODE11_PG = 0x800858600c00003full;

static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN = 48;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL = 49;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_CTL_REGS_RX_MODE21_PG = 0x8008a8600c00003full;

static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN = 48;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN_LEN = 4;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG = 0x800800600c00003full;

static const uint32_t RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 = 48;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 = 49;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 = 50;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 = 51;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 = 52;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT13_PG = 0x8009e8600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT = 49;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD = 50;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT23_PG = 0x800a38600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15 = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15_LEN = 16;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT33_PG = 0x800a88600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1 = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN = 8;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL3_PL = 0x8003d86d0c00003full;

static const uint32_t RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t RX0_RXCTL_DATASM_10_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_14_PLREGS_RX_CNTL2_PL = 0x8003c8690c00003full;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_16_PLREGS_RX_MODE1_PL = 0x8003d0700c00003full;

static const uint32_t RX0_RXCTL_DATASM_16_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t RX0_RXCTL_DATASM_16_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t RX0_RXCTL_DATASM_16_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t RX0_RXCTL_DATASM_16_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t RX0_RXCTL_DATASM_16_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL1_PL = 0x8003c0730c00003full;

static const uint32_t RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t RX0_RXCTL_DATASM_19_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_19_PLREGS_RX_STAT1_PL = 0x8003e0730c00003full;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_2_PLREGS_RX_CNTL3_PL = 0x8003d8620c00003full;

static const uint32_t RX0_RXCTL_DATASM_2_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t RX0_RXCTL_DATASM_2_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_20_PLREGS_RX_MODE1_PL = 0x8003d0740c00003full;

static const uint32_t RX0_RXCTL_DATASM_20_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t RX0_RXCTL_DATASM_20_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t RX0_RXCTL_DATASM_20_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t RX0_RXCTL_DATASM_20_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t RX0_RXCTL_DATASM_20_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_22_PLREGS_RX_CNTL2_PL = 0x8003c8760c00003full;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL = 0x8003d0640c00003full;

static const uint32_t RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_6_PLREGS_RX_CNTL2_PL = 0x8003c86e0c00003full;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x800120600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x800170600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c0600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x800288600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL = 0x800348610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800318610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e8610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x800238610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL14_PL = 0x800070610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL = 0x800320620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x800108620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x800158620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a8620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a0620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL15_PL = 0x800078620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_BIT_REGS_CNTLX5_PL = 0x800380630c00003full;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e0630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x800130630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x800180630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d0630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c0630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x800200630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x800250630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL13_PL = 0x800068630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL13_PL_COARSE = 48;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL13_PL_COARSE_LEN = 6;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL13_PL_GAIN = 54;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d8640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x800128640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x800178640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c8640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x800280640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d0640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL3_PL = 0x800018640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL = 0x800330650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_STAT5_PL = 0x8003b0650c00003full;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e0650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// omic/reg00140.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x800230650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL = 0x800030650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL = 0x8003686e0c00003full;

static const uint32_t RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_BIT_REGS_MODE4_PL = 0x8003386e0c00003full;

static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_BIT_REGS_STAT2_PL = 0x8003986e0c00003full;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_BIT_REGS_FIR_PL = 0x8003086e0c00003full;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b86e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f86e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002486e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c06e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_BIT_REGS_MODE8_PL = 0x8003586f0c00003full;

static const uint32_t RX0_1_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t RX0_1_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001106f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001606f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b06f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002206f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002706f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002986f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d0670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x800210670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x800260670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_CNTL6_PL = 0x800030670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_BIT_REGS_MODE3_PL = 0x800330660c00003full;

static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_BIT_REGS_STAT5_PL = 0x8003b0660c00003full;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a8660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f8660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x800148660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x800198660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b0660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_CNTL3_PL = 0x800018660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL6_PL = 0x8003886d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTLX1_PL = 0x8003606d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_STAT6_PL = 0x8003b86d0c00003full;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d86d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x8001286d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x8001786d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c86d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x8002806d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d06d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL = 0x8003106c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e06c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x8002306c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL16_PL = 0x8000806c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b06b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x8001006b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x8001506b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a06b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a86b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL17_PL = 0x8000886b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL = 0x8000206b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_FREQ = 51;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL4_PL_FREQ_LEN = 3;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000006b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// omic/reg00141.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL = 0x8003506a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_STAT1_PL = 0x8003906a0c00003full;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000986a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e86a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001386a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001886a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c86a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002086a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002586a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL = 0x8000086a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 58;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL = 0x800370690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTLX5_PL = 0x800380690c00003full;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL = 0x800340690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_STAT3_PL = 0x8003a0690c00003full;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x800120690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x800170690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c0690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x800288690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800318680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e8680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x800238680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL = 0x800090680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL = 0x800038680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_BIST_EN = 48;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_BIST_EN = 49;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN = 50;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ = 52;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN = 4;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ = 56;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN = 4;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_CTL_REGS_TX_CNTL1_PG = 0x800c44600c00003full;

static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL = 48;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL_LEN = 3;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG = 0x800ce4600c00003full;

static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 = 48;
static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN = 16;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT5_PG = 0x800d64600c00003full;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG = 0x800c94600c00003full;

static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS = 62;
static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET = 63;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL = 0x800494600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL = 0x8004e4600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL = 0x8004c4610c00003full;

static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL = 0x800514610c00003full;

static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL = 0x80044c620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL = 0x800424620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL = 0x8004a4630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL = 0x8004f4630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL = 0x800474630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL = 0x8004bc640c00003full;

static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL = 0x80050c640c00003full;

static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL = 0x800464640c00003full;

static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL = 0x80041c640c00003full;

static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL = 0x80048c650c00003full;

static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL = 0x8004dc650c00003full;

static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL = 0x8004546e0c00003full;

static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_0_TX_BIT_REGS_MODE3_PL = 0x80042c6e0c00003full;

static const uint32_t TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN = 52;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN = 53;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_CNTL14_PL = 0x80049c6f0c00003full;

static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_CNTL24_PL = 0x8004ec6f0c00003full;

static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_CNTL8_PL = 0x80046c6f0c00003full;

static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL = 0x80048c670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL = 0x8004dc670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL = 0x8004bc660c00003full;

static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// omic/reg00142.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_3_TX_BIT_REGS_CNTL28_PL = 0x80050c660c00003full;

static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_3_TX_BIT_REGS_FIR_MASK_PL = 0x80040c660c00003full;

static const uint32_t TX0_1_DD_3_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_3_TX_BIT_REGS_STAT1_PL = 0x800524660c00003full;

static const uint32_t TX0_1_DD_3_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL18_PL = 0x8004bc6d0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL28_PL = 0x80050c6d0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL12_PL = 0x80048c6c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL22_PL = 0x8004dc6c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL = 0x8004446c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL = 0x80049c6b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL = 0x8004ec6b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL7_PL = 0x8004646b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE1_PL = 0x80041c6b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL13_PL = 0x800494690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL23_PL = 0x8004e4690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL4_PL = 0x80044c690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL = 0x800424690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL19_PL = 0x8004c4680c00003full;

static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL29_PL = 0x800514680c00003full;

static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL9_PL = 0x800474680c00003full;

static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_FIR_MASK_PL = 0x80040c680c00003full;

static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// omic/reg00143.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_FIR_PL = 0x800404680c00003full;
// omic/reg00143.H

}
}
#include "omic/reg00140.H"
#include "omic/reg00141.H"
#include "omic/reg00142.H"
#include "omic/reg00143.H"
#endif
