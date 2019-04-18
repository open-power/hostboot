/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_5.H $       */
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

#ifndef __p10_scom_omic_5_H_
#define __p10_scom_omic_5_H_


namespace scomt
{
namespace omic
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_CTL_REGS_RX_MODE14_PG = 0x800870600c00003full;

static const uint32_t RX0_RXCTL_CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE = 48;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT16_PG = 0x800a00600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0 = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_0_LEN = 6;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1 = 54;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT16_PG_1_LEN = 6;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNT26_PG = 0x800a50600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23 = 56;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23_LEN = 8;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG = 0x8009a8600c00003full;

static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15 = 48;
static const uint32_t RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15_LEN = 16;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_STAT19_PG = 0x800b20600c00003full;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_REGS_RX_STAT5_PG = 0x800ab0600c00003full;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL3_PL = 0x8003d8600c00003full;

static const uint32_t RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t RX0_RXCTL_DATASM_0_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL3_PL = 0x8003d86b0c00003full;

static const uint32_t RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_14_PLREGS_RX_MODE1_PL = 0x8003d0690c00003full;

static const uint32_t RX0_RXCTL_DATASM_14_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t RX0_RXCTL_DATASM_14_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t RX0_RXCTL_DATASM_14_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t RX0_RXCTL_DATASM_14_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t RX0_RXCTL_DATASM_14_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_16_PLREGS_RX_CNTL2_PL = 0x8003c8700c00003full;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_20_PLREGS_RX_CNTL2_PL = 0x8003c8740c00003full;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_22_PLREGS_RX_MODE1_PL = 0x8003d0760c00003full;

static const uint32_t RX0_RXCTL_DATASM_22_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t RX0_RXCTL_DATASM_22_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t RX0_RXCTL_DATASM_22_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t RX0_RXCTL_DATASM_22_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t RX0_RXCTL_DATASM_22_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_4_PLREGS_RX_CNTL2_PL = 0x8003c8640c00003full;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL = 0x8003d06e0c00003full;

static const uint32_t RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t RX0_RXCTL_DATASM_6_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL1_PL = 0x8003c0660c00003full;

static const uint32_t RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t RX0_RXCTL_DATASM_9_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_RXCTL_DATASM_9_PLREGS_RX_STAT1_PL = 0x8003e0660c00003full;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x800108600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x800158600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a8600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a0600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL17_PL = 0x800088600c00003full;

static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t RX0_0_DEFAULT_RD_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE3_PL = 0x800330610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_BIT_REGS_STAT5_PL = 0x8003b0610c00003full;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e0610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x800130610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x800180610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d0610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c0610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x800200610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x800250610c00003full;

static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL2_PL = 0x800368620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTLX1_PL = 0x800360620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE4_PL = 0x800338620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_BIT_REGS_STAT2_PL = 0x800398620c00003full;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x800120620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x800170620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c0620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x800288620c00003full;

static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_2_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_BIT_REGS_MODE8_PL = 0x800358630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e8630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x800238630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL16_PL = 0x800080630c00003full;

static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t RX0_0_DEFAULT_RD_3_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b0640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x800100640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x800150640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a0640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a8640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL6_PL = 0x800030640c00003full;

static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t RX0_0_DEFAULT_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE6_PL = 0x800348650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x800098650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// omic/reg00132.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e8650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x800138650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x800188650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c8650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x800208650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x800258650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL = 0x800018650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL = 0x800048650c00003full;

static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t RX0_0_DEFAULT_RD_5_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_BIT_REGS_MODE1_PL = 0x8003206e0c00003full;

static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 56;
static const uint32_t RX0_1_RD_0_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 57;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d06e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002106e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002606e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000006e0c00003full;

static const uint32_t RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t RX0_1_RD_0_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL = 0x8003006f0c00003full;

static const uint32_t RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t RX0_1_RD_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a86f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f86f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001486f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001986f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b06f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_RX_DAC_REGS_CNTLX9_PL = 0x8000486f0c00003full;

static const uint32_t RX0_1_RD_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t RX0_1_RD_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t RX0_1_RD_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t RX0_1_RD_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b8670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f8670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x800248670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c0670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_2_RX_DAC_REGS_CNTL3_PL = 0x800018670c00003full;

static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL3_PL_FREQ = 51;
static const uint32_t RX0_1_RD_2_RX_DAC_REGS_CNTL3_PL_FREQ_LEN = 3;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_BIT_REGS_MODE6_PL = 0x800348660c00003full;

static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t RX0_1_RD_3_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x800110660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x800160660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b0660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x800220660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x800270660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x800298660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_CNTL18_PL = 0x800090660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_1_RD_3_RX_DAC_REGS_CNTL6_PL = 0x800030660c00003full;

static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE = 48;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL6_PL_COARSE_LEN = 6;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN = 54;
static const uint32_t RX0_1_RD_3_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL3_PL = 0x8003706d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE5_PL = 0x8003406d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_BIT_REGS_STAT3_PL = 0x8003a06d0c00003full;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b06d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x8001006d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x8001506d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a06d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a86d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL15_PL = 0x8000786d0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t RX0_2_DEFAULT_RD_0_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_BIT_REGS_CNTLX5_PL = 0x8003806c0c00003full;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000986c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e86c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001386c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001886c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c86c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002086c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// omic/reg00133.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002586c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL13_PL = 0x8000686c0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE = 48;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL13_PL_COARSE_LEN = 6;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN = 54;
static const uint32_t RX0_2_DEFAULT_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_BIT_REGS_FIR_PL = 0x8003086b0c00003full;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d86b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x8001286b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x8001786b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c86b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x8002806b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d06b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL1_PL = 0x8000086b0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA = 55;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL1_PL_PRBS_TEST_DATA_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 58;
static const uint32_t RX0_2_DEFAULT_RD_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL4_PL = 0x8003786a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL4_PL_A = 49;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL4_PL_A_LEN = 7;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL4_PL_B = 57;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_CNTL4_PL_B_LEN = 7;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE2_PL = 0x8003286a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR = 49;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN = 50;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN = 51;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN = 52;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO = 53;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN = 10;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_BIT_REGS_STAT4_PL = 0x8003a86a0c00003full;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e06a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x8002306a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL14_PL = 0x8000706a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL4_PL = 0x8000206a0c00003full;

static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL4_PL_FREQ = 51;
static const uint32_t RX0_2_DEFAULT_RD_3_RX_DAC_REGS_CNTL4_PL_FREQ_LEN = 3;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL6_PL = 0x800388690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_BIT_REGS_STAT6_PL = 0x8003b8690c00003full;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x800108690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x800158690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a8690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a0690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL7_PL = 0x800038690c00003full;

static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL7_PL_A_BIST_EN = 48;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL7_PL_B_BIST_EN = 49;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN = 50;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL7_PL_BISTCLK_EN_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ = 52;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL7_PL_A_PRBS15_ADJ_LEN = 4;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ = 56;
static const uint32_t RX0_2_DEFAULT_RD_4_RX_DAC_REGS_CNTL7_PL_B_PRBS15_ADJ_LEN = 4;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_CNTLX1_PL = 0x800360680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e0680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x800130680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x800180680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d0680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c0680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x800200680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x800250680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x800000680c00003full;

static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t RX0_2_DEFAULT_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_TXCTL_CTL_REGS_TX_CNTL4_PG = 0x800c5c600c00003full;

static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL = 48;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN = 8;
static const uint32_t TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL = 57;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL16_PL = 0x8004ac600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL26_PL = 0x8004fc600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL = 0x80046c600c00003full;

static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL5_PL = 0x800454610c00003full;

static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL = 0x80042c610c00003full;

static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN = 52;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN = 53;
static const uint32_t TX0_0_DEFAULT_DD_1_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_STAT1_PL = 0x800524620c00003full;

static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t TX0_0_DEFAULT_DD_2_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL10_PL = 0x80047c630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL20_PL = 0x8004cc630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL30_PL = 0x80051c630c00003full;

static const uint32_t TX0_0_DEFAULT_DD_3_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL2_PL = 0x80043c640c00003full;

static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800414640c00003full;

static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t TX0_0_DEFAULT_DD_4_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL17_PL = 0x8004b4650c00003full;

static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL27_PL = 0x800504650c00003full;

static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_0_DEFAULT_DD_5_TX_BIT_REGS_FIR_PL = 0x800404650c00003full;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_CNTL11_PL = 0x8004846f0c00003full;

static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_CNTL1G_PL = 0x8004346f0c00003full;
// omic/reg00134.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_CNTL21_PL = 0x8004d46f0c00003full;

static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t TX0_1_DD_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_TX_BIT_REGS_FIR_MASK_PL = 0x80040c6f0c00003full;

static const uint32_t TX0_1_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t TX0_1_DD_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL = 0x8004b4670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL27_PL = 0x800504670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_2_TX_BIT_REGS_CNTL9_PL = 0x800474670c00003full;

static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t TX0_1_DD_2_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_3_TX_BIT_REGS_CNTL4_PL = 0x80044c660c00003full;

static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_1_DD_3_TX_BIT_REGS_MODE2_PL = 0x800424660c00003full;

static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t TX0_1_DD_3_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL17_PL = 0x8004b46c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL27_PL = 0x8005046c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL6_PL = 0x80045c6c0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_1_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL11_PL = 0x8004846b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL1G_PL = 0x8004346b0c00003full;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL21_PL = 0x8004d46b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL2_PL = 0x80043c6b0c00003full;

static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t TX0_2_DEFAULT_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL16_PL = 0x8004ac690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL26_PL = 0x8004fc690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_STAT1_PL = 0x800524690c00003full;

static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t TX0_2_DEFAULT_DD_4_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// omic/reg00135.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x800414680c00003full;

static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t TX0_2_DEFAULT_DD_5_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// omic/reg00135.H

}
}
#include "omic/reg00132.H"
#include "omic/reg00133.H"
#include "omic/reg00134.H"
#include "omic/reg00135.H"
#endif
