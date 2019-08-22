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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_iohs_3_H_
#define __p10_scom_iohs_3_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


static const uint64_t AXON_BIST = 0x1803000bull;

static const uint32_t AXON_BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t AXON_BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t AXON_BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t AXON_BIST_BIST_REGION_PERV = 4;
static const uint32_t AXON_BIST_BIST_REGION_UNIT1 = 5;
static const uint32_t AXON_BIST_BIST_REGION_UNIT2 = 6;
static const uint32_t AXON_BIST_BIST_REGION_UNIT3 = 7;
static const uint32_t AXON_BIST_BIST_REGION_UNIT4 = 8;
static const uint32_t AXON_BIST_BIST_REGION_UNIT5 = 9;
static const uint32_t AXON_BIST_BIST_REGION_UNIT6 = 10;
static const uint32_t AXON_BIST_BIST_REGION_UNIT7 = 11;
static const uint32_t AXON_BIST_BIST_REGION_UNIT8 = 12;
static const uint32_t AXON_BIST_BIST_REGION_UNIT9 = 13;
static const uint32_t AXON_BIST_BIST_REGION_UNIT10 = 14;
static const uint32_t AXON_BIST_BIST_REGION_UNIT11 = 15;
static const uint32_t AXON_BIST_BIST_REGION_UNIT12 = 16;
static const uint32_t AXON_BIST_BIST_REGION_UNIT13 = 17;
static const uint32_t AXON_BIST_BIST_REGION_UNIT14 = 18;
static const uint32_t AXON_BIST_BIST_STROBE_WINDOW_EN = 48;
// iohs/reg00012.H

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
// iohs/reg00012.H

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
// iohs/reg00012.H

static const uint64_t AXON_EPS_FIR_MODE_REG = 0x18040088ull;

static const uint32_t AXON_EPS_FIR_MODE_REG_XSTOP_LOCK = 0;
static const uint32_t AXON_EPS_FIR_MODE_REG_XSTOP_LOCK_RECOV = 1;
static const uint32_t AXON_EPS_FIR_MODE_REG_XSTOP_LOCK_SPATTN = 2;
static const uint32_t AXON_EPS_FIR_MODE_REG_XSTOP_LOCK_LXSTOP = 3;
static const uint32_t AXON_EPS_FIR_MODE_REG_XSTOP_LOCK_HOSTATTN = 4;
static const uint32_t AXON_EPS_FIR_MODE_REG_MODE_REG05 = 5;
static const uint32_t AXON_EPS_FIR_MODE_REG_DISABLE_IOPB_ERR = 6;
static const uint32_t AXON_EPS_FIR_MODE_REG_MODE_REG07 = 7;
static const uint32_t AXON_EPS_FIR_MODE_REG_MODE_REG08 = 8;
static const uint32_t AXON_EPS_FIR_MODE_REG_MASK_DIRECT_ERROR = 9;
static const uint32_t AXON_EPS_FIR_MODE_REG_MODE_REG10 = 10;
static const uint32_t AXON_EPS_FIR_MODE_REG_MODE_REG11 = 11;
static const uint32_t AXON_EPS_FIR_MODE_REG_MODE_REG12 = 12;
static const uint32_t AXON_EPS_FIR_MODE_REG_MODE_REG13 = 13;
static const uint32_t AXON_EPS_FIR_MODE_REG_MODE_REG14 = 14;
static const uint32_t AXON_EPS_FIR_MODE_REG_MODE_REG15 = 15;
// iohs/reg00012.H

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
// iohs/reg00012.H

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
// iohs/reg00012.H

static const uint64_t AXON_RECOV = 0x18040001ull;

static const uint32_t AXON_RECOV_ANY_RECOV = 0;
static const uint32_t AXON_RECOV_RESERVED1R = 1;
static const uint32_t AXON_RECOV_RECOV_ANY_LOCAL_XSTOP = 2;
static const uint32_t AXON_RECOV_RESERVED3R = 3;
static const uint32_t AXON_RECOV_RECOV_PERV = 4;
static const uint32_t AXON_RECOV_RECOV_IN05 = 5;
static const uint32_t AXON_RECOV_RECOV_IN06 = 6;
static const uint32_t AXON_RECOV_RECOV_IN07 = 7;
static const uint32_t AXON_RECOV_RECOV_IN08 = 8;
static const uint32_t AXON_RECOV_RECOV_IN09 = 9;
static const uint32_t AXON_RECOV_RECOV_IN10 = 10;
static const uint32_t AXON_RECOV_RECOV_IN11 = 11;
static const uint32_t AXON_RECOV_RECOV_IN12 = 12;
static const uint32_t AXON_RECOV_RECOV_IN13 = 13;
static const uint32_t AXON_RECOV_RECOV_IN14 = 14;
static const uint32_t AXON_RECOV_RECOV_IN15 = 15;
static const uint32_t AXON_RECOV_RECOV_IN16 = 16;
static const uint32_t AXON_RECOV_RECOV_IN17 = 17;
static const uint32_t AXON_RECOV_RECOV_IN18 = 18;
static const uint32_t AXON_RECOV_RECOV_IN19 = 19;
static const uint32_t AXON_RECOV_RECOV_IN20 = 20;
static const uint32_t AXON_RECOV_RECOV_IN21 = 21;
static const uint32_t AXON_RECOV_RECOV_IN22 = 22;
static const uint32_t AXON_RECOV_RECOV_IN23 = 23;
static const uint32_t AXON_RECOV_RECOV_IN24 = 24;
static const uint32_t AXON_RECOV_RECOV_IN25 = 25;
static const uint32_t AXON_RECOV_RECOV_IN26 = 26;
static const uint32_t AXON_RECOV_RECOV_IN27 = 27;
static const uint32_t AXON_RECOV_RECOV_IN28 = 28;
static const uint32_t AXON_RECOV_RECOV_IN29 = 29;
static const uint32_t AXON_RECOV_RECOV_IN30 = 30;
static const uint32_t AXON_RECOV_RECOV_IN31 = 31;
static const uint32_t AXON_RECOV_RECOV_IN32 = 32;
static const uint32_t AXON_RECOV_RECOV_IN33 = 33;
static const uint32_t AXON_RECOV_RECOV_IN34 = 34;
static const uint32_t AXON_RECOV_RECOV_IN35 = 35;
static const uint32_t AXON_RECOV_RECOV_IN36 = 36;
static const uint32_t AXON_RECOV_RECOV_IN37 = 37;
static const uint32_t AXON_RECOV_RECOV_IN38 = 38;
static const uint32_t AXON_RECOV_RECOV_IN39 = 39;
static const uint32_t AXON_RECOV_RECOV_IN40 = 40;
static const uint32_t AXON_RECOV_RECOV_IN41 = 41;
static const uint32_t AXON_RECOV_RECOV_IN42 = 42;
static const uint32_t AXON_RECOV_RECOV_IN43 = 43;
static const uint32_t AXON_RECOV_RECOV_IN44 = 44;
static const uint32_t AXON_RECOV_RECOV_IN45 = 45;
static const uint32_t AXON_RECOV_RECOV_IN46 = 46;
static const uint32_t AXON_RECOV_RECOV_IN47 = 47;
static const uint32_t AXON_RECOV_RECOV_IN48 = 48;
static const uint32_t AXON_RECOV_RECOV_IN49 = 49;
static const uint32_t AXON_RECOV_RECOV_IN50 = 50;
static const uint32_t AXON_RECOV_RECOV_IN51 = 51;
static const uint32_t AXON_RECOV_RECOV_IN52 = 52;
static const uint32_t AXON_RECOV_RECOV_IN53 = 53;
// iohs/reg00012.H

static const uint64_t AXON_RECOV_MASK_RW = 0x18040041ull;
static const uint64_t AXON_RECOV_MASK_WO_CLEAR = 0x18040061ull;
static const uint64_t AXON_RECOV_MASK_WO_OR = 0x18040051ull;

static const uint32_t AXON_RECOV_MASK_1 = 1;
static const uint32_t AXON_RECOV_MASK_2 = 2;
static const uint32_t AXON_RECOV_MASK_3 = 3;
static const uint32_t AXON_RECOV_MASK_4 = 4;
static const uint32_t AXON_RECOV_MASK_5 = 5;
static const uint32_t AXON_RECOV_MASK_6 = 6;
static const uint32_t AXON_RECOV_MASK_7 = 7;
static const uint32_t AXON_RECOV_MASK_8 = 8;
static const uint32_t AXON_RECOV_MASK_9 = 9;
static const uint32_t AXON_RECOV_MASK_10 = 10;
static const uint32_t AXON_RECOV_MASK_11 = 11;
static const uint32_t AXON_RECOV_MASK_12 = 12;
static const uint32_t AXON_RECOV_MASK_13 = 13;
static const uint32_t AXON_RECOV_MASK_14 = 14;
static const uint32_t AXON_RECOV_MASK_15 = 15;
static const uint32_t AXON_RECOV_MASK_16 = 16;
static const uint32_t AXON_RECOV_MASK_17 = 17;
static const uint32_t AXON_RECOV_MASK_18 = 18;
static const uint32_t AXON_RECOV_MASK_19 = 19;
static const uint32_t AXON_RECOV_MASK_20 = 20;
static const uint32_t AXON_RECOV_MASK_21 = 21;
static const uint32_t AXON_RECOV_MASK_22 = 22;
static const uint32_t AXON_RECOV_MASK_23 = 23;
static const uint32_t AXON_RECOV_MASK_24 = 24;
static const uint32_t AXON_RECOV_MASK_25 = 25;
static const uint32_t AXON_RECOV_MASK_26 = 26;
static const uint32_t AXON_RECOV_MASK_27 = 27;
static const uint32_t AXON_RECOV_MASK_28 = 28;
static const uint32_t AXON_RECOV_MASK_29 = 29;
static const uint32_t AXON_RECOV_MASK_30 = 30;
static const uint32_t AXON_RECOV_MASK_31 = 31;
static const uint32_t AXON_RECOV_MASK_32 = 32;
static const uint32_t AXON_RECOV_MASK_33 = 33;
static const uint32_t AXON_RECOV_MASK_34 = 34;
static const uint32_t AXON_RECOV_MASK_35 = 35;
static const uint32_t AXON_RECOV_MASK_36 = 36;
static const uint32_t AXON_RECOV_MASK_37 = 37;
static const uint32_t AXON_RECOV_MASK_38 = 38;
static const uint32_t AXON_RECOV_MASK_39 = 39;
static const uint32_t AXON_RECOV_MASK_40 = 40;
static const uint32_t AXON_RECOV_MASK_41 = 41;
static const uint32_t AXON_RECOV_MASK_42 = 42;
static const uint32_t AXON_RECOV_MASK_43 = 43;
static const uint32_t AXON_RECOV_MASK_44 = 44;
static const uint32_t AXON_RECOV_MASK_45 = 45;
static const uint32_t AXON_RECOV_MASK_46 = 46;
static const uint32_t AXON_RECOV_MASK_47 = 47;
static const uint32_t AXON_RECOV_MASK_48 = 48;
static const uint32_t AXON_RECOV_MASK_49 = 49;
static const uint32_t AXON_RECOV_MASK_50 = 50;
static const uint32_t AXON_RECOV_MASK_51 = 51;
static const uint32_t AXON_RECOV_MASK_52 = 52;
static const uint32_t AXON_RECOV_MASK_53 = 53;
// iohs/reg00012.H

static const uint64_t AXON_TRA0_TR0_TRACE_HI_DATA_REG = 0x18010400ull;

static const uint32_t AXON_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t AXON_TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// iohs/reg00012.H

static const uint64_t AXON_TRA0_TR0_CONFIG_4 = 0x18010407ull;

static const uint32_t AXON_TRA0_TR0_CONFIG_4_A = 0;
static const uint32_t AXON_TRA0_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t AXON_TRA0_TR0_CONFIG_4_B = 24;
static const uint32_t AXON_TRA0_TR0_CONFIG_4_B_LEN = 24;
// iohs/reg00012.H

static const uint64_t DLP_MISC_ERROR_STATUS = 0x18011029ull;

static const uint32_t DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER = 0;
static const uint32_t DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS = 1;
static const uint32_t DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS_LEN = 7;
static const uint32_t DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS = 8;
static const uint32_t DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS_LEN = 8;
static const uint32_t DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS = 16;
static const uint32_t DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS_LEN = 8;
static const uint32_t DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS = 24;
static const uint32_t DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS_LEN = 18;
static const uint32_t DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS = 44;
static const uint32_t DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS_LEN = 18;
// iohs/reg00012.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG = 0x8008480010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2 = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC2_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2 = 52;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC2_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3 = 56;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_INC3_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3 = 60;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE9_PG_DEC3_LEN = 4;
// iohs/reg00012.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG = 0x800a100010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_4_LEN = 6;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5 = 54;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT18_PG_5_LEN = 6;
// iohs/reg00012.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT28_PG = 0x800a600010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL1_PL = 0x8003c00e10012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00012.H

static const uint64_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_STAT1_PL = 0x8003e00e10012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL = 52;
static const uint32_t IOO_RX0_RXCTL_DATASM_12_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL = 53;
// iohs/reg00012.H

static const uint64_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_CNTL3_PL = 0x8003d80210012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_2_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00012.H

static const uint64_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL = 0x8003d00410012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_4_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00012.H

static const uint64_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_CNTL2_PL = 0x8003c80610012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_6_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL = 52;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001080010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001580010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a80010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a00010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL = 0x8000180010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_ZERO = 51;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_ZERO_LEN = 3;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL = 0x8003200110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 57;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 58;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT = 59;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e00110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001300110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001800110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d00110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c00110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002000110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002500110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL6_PL = 0x8000300110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN = 4;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL = 0x8003600210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 58;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 59;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A = 60;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A = 61;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN = 62;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE6_PL = 0x8003480210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x8001200210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x8001700210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c00210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x8002880210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e80310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002380310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE8_PL = 0x8003580410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b00410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x8001000410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x8001500410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a00410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a80410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 8;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL13_PL = 0x8000680410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN = 4;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL = 0x8003680510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE4_PL = 0x8003380510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00012.H

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_STAT2_PL = 0x8003980510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL_LEN = 15;
// iohs/reg00013.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000980510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e80510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001380510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001880510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c80510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002080510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002580510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL15_PL = 0x8000780510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS = 50;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS = 51;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE6_PL = 0x8003480610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_1_RD_0_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b80610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f80610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002480610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c00610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL3_PL = 0x8000180610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL3_PL_ZERO = 51;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL3_PL_ZERO_LEN = 3;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001100710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001600710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b00710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002200710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002700710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002980710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL6_PL = 0x8000300710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL6_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL6_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL6_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN = 4;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d00810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002100810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002600810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL = 0x8003201110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 57;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 58;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT = 59;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a81110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f81110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001481110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001981110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b01110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE3_PL = 0x8003301010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_STAT5_PL = 0x8003b01010012c3full;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f01010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x8002401010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c81010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL15_PL = 0x8000781010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL15_PL_MINI_PR_GRAY_ENCODE_DIS = 50;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL15_PL_TINY_PR_GRAY_ENCODE_DIS = 51;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8003180f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL = 0x8003000f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x8001180f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x8001680f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b80f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d80f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x8002280f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x8002780f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x8002900f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL13_PL = 0x8000680f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL13_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL13_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN = 4;
// iohs/reg00013.H

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL = 0x8003800e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL = 49;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL = 50;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL = 51;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL = 52;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL = 53;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 54;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 57;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL = 58;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL = 59;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL = 60;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL = 61;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL = 62;
// iohs/reg00013.H

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE8_PL = 0x8003580e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00013.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e00e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 8;
// iohs/reg00013.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001300e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001800e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d00e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c00e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002000e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002500e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL11_PL = 0x8000580e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL11_PL_TERM_PD = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST = 49;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST_LEN = 5;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL11_PL_OFF_CM = 54;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL11_PL_OFF_CM_LEN = 4;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL11_PL_OFF_DM = 58;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL11_PL_OFF_DM_LEN = 6;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL8_PL = 0x8000400e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT_LEN = 2;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL = 50;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL_LEN = 2;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B = 52;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL = 0x8003680d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE4_PL = 0x8003380d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_STAT2_PL = 0x8003980d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL_LEN = 15;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_PL = 0x8003080d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001080d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001580d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a80d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a00d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL17_PL = 0x8000880d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_MODE3_PL = 0x8003300c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_STAT5_PL = 0x8003b00c10012c3full;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e80c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002380c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL16_PL = 0x8000800c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL2_PL = 0x8000100c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL2_PL_NS_DATA = 48;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL2_PL_NS_DATA_LEN = 4;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL2_PL_EW_DATA = 52;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL2_PL_EW_DATA_LEN = 4;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL2_PL_NS_EDGE = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL2_PL_NS_EDGE_LEN = 4;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL2_PL_EW_EDGE = 60;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTL2_PL_EW_EDGE_LEN = 4;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x8001200b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x8001700b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c00b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x8002880b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL10_PL = 0x8000500b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS = 49;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M = 50;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL10_PL_SIGDET_PD = 51;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP = 52;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP = 53;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS = 54;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP_LEN = 2;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP = 58;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP_LEN = 2;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL = 0x8000380b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL_EN_DC = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL_PR_POS = 49;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL_PR_POS_LEN = 5;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS = 54;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL = 0x8003600a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 58;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 59;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_RLM_CLK_SEL_A = 60;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_SEL_A = 61;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTLX1_PL_DL_CLK_EN = 62;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000980a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e80a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001380a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001880a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c80a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002080a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002580a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL4_PL = 0x8000200a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL4_PL_ZERO = 51;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL4_PL_ZERO_LEN = 3;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTLX9_PL = 0x8000480a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL = 0x8003200910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 57;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 58;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT = 59;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8003180910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b00910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x8001000910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x8001500910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a00910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a80910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 8;
// iohs/reg00014.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL1_PL = 0x8000080910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 54;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00014.H

static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL10_PG = 0x800c2c0010012c3full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63 = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63_LEN = 16;
// iohs/reg00014.H

static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG = 0x800c540010012c3full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL_LEN = 3;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL = 51;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL_LEN = 4;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL = 55;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL_LEN = 6;
// iohs/reg00014.H

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG = 0x800cf40010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15_LEN = 16;
// iohs/reg00014.H

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_FIR_PG = 0x800c840010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL = 49;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL = 50;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL = 51;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL = 52;
// iohs/reg00015.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL18_PL = 0x8004bc0010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00015.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL22_PL = 0x8004dc0110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00015.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_STAT1_PL = 0x8005240110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_STAT1_PL_TX_BIST_PRBS_ERR_DET_RO_SIGNAL = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_STAT1_PL_TX_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL = 49;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00015.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL14_PL = 0x80049c0210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00015.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL24_PL = 0x8004ec0210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN = 9;
// iohs/reg00015.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL5_PL = 0x8004540210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// iohs/reg00015.H

static const uint64_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL = 0x80042c0210012c3full;

static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN = 52;
static const uint32_t IOO_TX0_0_DD_2_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 53;
// iohs/reg00015.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL8_PL = 0x80046c0310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00015.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8004140310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00015.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL23_PL = 0x8004e40410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00015.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL6_PL = 0x80045c0410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00015.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL19_PL = 0x8004c40510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00015.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL29_PL = 0x8005140510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL = 0x8004c40610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL29_PL = 0x8005140610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL2_PL = 0x80043c0610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_FIR_PL = 0x8004040610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL_LEN = 2;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_STAT2_PL = 0x80052c0610012c3full;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL23_PL = 0x8004e40710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL = 0x8004a40810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL25_PL = 0x8004f40810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL = 0x80045c1110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL22_PL = 0x8004dc1010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL8_PL = 0x80046c1010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL18_PL = 0x8004bc0f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL5_PL = 0x8004540f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// iohs/reg00015.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL = 0x80042c0f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN = 52;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 53;
// iohs/reg00015.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL11_PL = 0x8004840e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_24_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_24_HS_EN_LEN = 9;
// iohs/reg00015.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL1G_PL = 0x8004340e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 6;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 59;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61;
// iohs/reg00015.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL21_PL = 0x8004d40e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00015.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL = 0x8004440e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00015.H

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL = 0x8004b40b10012c3full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00015.H

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL7_PL = 0x8004640b10012c3full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// iohs/reg00015.H

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL = 0x80041c0b10012c3full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN = 52;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN = 53;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// iohs/reg00015.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL9_PL = 0x8004740a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_24_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_24_HS_EN_LEN = 9;
// iohs/reg00015.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL10_PL = 0x80047c0910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00015.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL20_PL = 0x8004cc0910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00015.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL30_PL = 0x80051c0910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00015.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL4_PL = 0x80044c0910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// iohs/reg00015.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL = 0x8004240910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// iohs/reg00015.H

static const uint64_t LXSTOP_INTERRUPT_REG = 0x180f002aull;
// iohs/reg00015.H

static const uint64_t MULTICAST_GROUP_1 = 0x180f0001ull;

static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
// iohs/reg00015.H

static const uint64_t NET_CTRL0_RW = 0x180f0040ull;
static const uint64_t NET_CTRL0_RW_WAND = 0x180f0041ull;
static const uint64_t NET_CTRL0_RW_WOR = 0x180f0042ull;

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
// iohs/reg00015.H

static const uint64_t PLL_LOCK_REG = 0x180f0019ull;
// iohs/reg00015.H

static const uint64_t REGS_PRX0_DLR_APSR = 0x18011039ull;

static const uint32_t REGS_PRX0_DLR_APSR_LINK_POPULATED = 0;
static const uint32_t REGS_PRX0_DLR_APSR_LINK_TYPE = 1;
static const uint32_t REGS_PRX0_DLR_APSR_LINK_TYPE_LEN = 3;
static const uint32_t REGS_PRX0_DLR_APSR_LINK_INFO = 4;
static const uint32_t REGS_PRX0_DLR_APSR_LINK_INFO_LEN = 6;
static const uint32_t REGS_PRX0_DLR_APSR_DL_ENABLE = 10;
static const uint32_t REGS_PRX0_DLR_APSR_FREEZE_PROXY = 11;
static const uint32_t REGS_PRX0_DLR_APSR_ACTIVITY_SAMPLE = 12;
static const uint32_t REGS_PRX0_DLR_APSR_ACTIVITY_SAMPLE_LEN = 8;
static const uint32_t REGS_PRX0_DLR_APSR_BASE_SAMPLE = 20;
static const uint32_t REGS_PRX0_DLR_APSR_BASE_SAMPLE_LEN = 8;
// iohs/reg00015.H

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00012.H"
#include "iohs/reg00013.H"
#include "iohs/reg00014.H"
#include "iohs/reg00015.H"
#endif
#endif
