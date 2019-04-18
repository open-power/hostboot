/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_e.H $       */
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

#ifndef __p10_scom_omic_e_H_
#define __p10_scom_omic_e_H_


namespace scomt
{
namespace omic
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_CTL_REGS_RX_MODE16_PG = 0x800880600c00003full;

static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 = 48;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN = 3;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1 = 51;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH1_LEN = 5;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 = 56;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN = 3;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2 = 59;
static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE16_PG_THRESH2_LEN = 5;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT14_PG = 0x8009f0600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_0_SEL_LEN = 5;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL = 53;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_1_SEL_LEN = 5;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL = 58;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT14_PG_2_SEL_LEN = 5;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT24_PG = 0x800a40600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23 = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23_LEN = 8;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG = 0x8009b8600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15 = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN = 16;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_SPARE_MODE_PG = 0x800980600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_SPARE_MODE_PG_0 = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_SPARE_MODE_PG_1 = 49;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_SPARE_MODE_PG_2 = 50;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_SPARE_MODE_PG_3 = 51;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_SPARE_MODE_PG_4 = 52;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_SPARE_MODE_PG_5 = 53;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_SPARE_MODE_PG_6 = 54;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_SPARE_MODE_PG_7 = 55;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_STAT7_PG = 0x800ac0600c00003full;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL = 0x8003c0600c00003full;

static const uint32_t RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_0_PLREGS_RX_STAT1_PL = 0x8003e0600c00003full;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL1_PL = 0x8003c06b0c00003full;

static const uint32_t RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_12_PLREGS_RX_STAT1_PL = 0x8003e06b0c00003full;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL3_PL = 0x8003d8660c00003full;

static const uint32_t RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTLX1_PL = 0x800360600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t RX0_0_DEFAULT_RD_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a8600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f8600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x800148600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x800198600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b0600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL15_PL = 0x800078600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL8_PL = 0x800040600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT = 48;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL8_PL_OCTANT_SELECT_LEN = 3;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT = 51;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL8_PL_SPEED_SELECT_LEN = 2;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL = 0x800320610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d0610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x800210610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x800260610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL13_PL = 0x800068610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE = 48;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE_LEN = 6;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN = 54;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL = 0x800348620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x800110620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x800160620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b0620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x800220620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x800270620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x800298620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x800000620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b8630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f8630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x800248630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c0630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL14_PL = 0x800070630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL = 0x800038630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_A_BIST_EN = 48;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_B_BIST_EN = 49;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN = 50;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ = 52;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN = 4;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ = 56;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN = 4;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_CNTLX5_PL = 0x800380640c00003full;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL = 0x800358640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a0640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f0640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x800140640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x800190640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b8640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL4_PL = 0x800020640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL4_PL_FREQ = 51;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL4_PL_FREQ_LEN = 3;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL = 0x800368650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL = 0x800338650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_STAT2_PL = 0x800398650c00003full;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_FIR_MASK_PL = 0x800310650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// omic/reg00168.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x800218650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x800268650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL = 0x800008650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN = 3;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 58;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_BIT_REGS_MODE3_PL = 0x8003306e0c00003full;

static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_BIT_REGS_STAT5_PL = 0x8003b06e0c00003full;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e06e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001306e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001806e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d06e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c06e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002006e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002506e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001086f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001586f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a86f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a06f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_BIT_REGS_MODE8_PL = 0x800358670c00003full;

static const uint32_t RX0_1_RD_2_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t RX0_1_RD_2_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e8670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x800238670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL = 0x800008670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN = 3;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 58;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL = 0x800368660c00003full;

static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_BIT_REGS_MODE4_PL = 0x800338660c00003full;

static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_BIT_REGS_STAT2_PL = 0x800398660c00003full;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_BIT_REGS_SPARE_MODE_PL = 0x800300660c00003full;

static const uint32_t RX0_1_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x800120660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x800170660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c0660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x800288660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_CNTL4_PL = 0x800020660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL4_PL_FREQ = 51;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL4_PL_FREQ_LEN = 3;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE7_PL = 0x8003506d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_STAT1_PL = 0x8003906d0c00003full;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a06d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f06d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x8001406d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x8001906d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b86d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL17_PL = 0x8000886d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x8002186c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x8002686c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x8001186b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x8001686b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b86b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d86b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x8002286b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x8002786b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x8002906b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL = 0x8000186b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL6_PL = 0x8003886a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTLX5_PL = 0x8003806a0c00003full;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_STAT6_PL = 0x8003b86a0c00003full;
// omic/reg00169.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f06a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x8002406a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c86a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL16_PL = 0x8000806a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL = 0x8000306a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL4_PL = 0x800378690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL4_PL_A = 49;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL4_PL_A_LEN = 7;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL4_PL_B = 57;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL4_PL_B_LEN = 7;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE2_PL = 0x800328690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR = 49;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN = 50;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN = 51;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN = 52;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE2_PL_LOCK_RATIO = 53;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN = 10;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_STAT4_PL = 0x8003a8690c00003full;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a8690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f8690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x800148690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x800198690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b0690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d0680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x800210680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x800260680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL = 0x800048680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_CTL_REGS_TX_CNTL6_PG = 0x800c6c600c00003full;

static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH = 48;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH_LEN = 9;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG = 0x800ccc600c00003full;

static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23 = 48;
static const uint32_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN = 8;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_STAT2_PG = 0x800d4c600c00003full;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL = 0x80049c600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL = 0x8004ec600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL = 0x800464610c00003full;

static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL = 0x80041c610c00003full;

static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL = 0x8004bc620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL = 0x80050c620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL = 0x800444620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL = 0x80048c630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL = 0x8004dc630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL = 0x8004a4650c00003full;

static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL = 0x8004f4650c00003full;

static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL = 0x8004c46e0c00003full;

static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_0_TX_BIT_REGS_CNTL29_PL = 0x8005146e0c00003full;

static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_0_TX_BIT_REGS_CNTL2_PL = 0x80043c6e0c00003full;

static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t TX0_1_DD_0_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_CNTL13_PL = 0x8004946f0c00003full;

static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_CNTL23_PL = 0x8004e46f0c00003full;

static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_FIR_PL = 0x8004046f0c00003full;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL = 0x8004a4670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL25_PL = 0x8004f4670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL = 0x80045c660c00003full;

static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL9_PL = 0x8004746d0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_0_TX_BIT_REGS_FIR_PL = 0x8004046d0c00003full;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL = 0x8004a46c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL = 0x8004f46c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL4_PL = 0x80044c6c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE2_PL = 0x8004246c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL = 0x8004946b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL = 0x8004e46b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL = 0x8004c46a0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL = 0x8005146a0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_3_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// omic/reg00170.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL = 0x80049c690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// omic/reg00171.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL = 0x8004ec690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// omic/reg00171.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL3_PL = 0x800444690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// omic/reg00171.H

}
}
#include "omic/reg00168.H"
#include "omic/reg00169.H"
#include "omic/reg00170.H"
#include "omic/reg00171.H"
#endif
