/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_4.H $       */
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

#ifndef __p10_scom_pauc_4_H_
#define __p10_scom_pauc_4_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
{
#endif


static const uint64_t CLOCK_STAT_ARY = 0x1003000aull;

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
// pauc/reg00004.H

static const uint64_t DL_PPE_WRAP_ARB_CSCR_RW = 0x10012c4aull;
static const uint64_t DL_PPE_WRAP_ARB_CSCR_WO_CLEAR = 0x10012c4bull;
static const uint64_t DL_PPE_WRAP_ARB_CSCR_WO_OR = 0x10012c4cull;

static const uint32_t DL_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE = 0;
static const uint32_t DL_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE = 1;
static const uint32_t DL_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS = 2;
static const uint32_t DL_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS = 3;
static const uint32_t DL_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE = 4;
static const uint32_t DL_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR = 5;
static const uint32_t DL_PPE_WRAP_ARB_CSCR_SPARE_6_7 = 6;
static const uint32_t DL_PPE_WRAP_ARB_CSCR_SPARE_6_7_LEN = 2;
static const uint32_t DL_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX = 47;
static const uint32_t DL_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX_LEN = 13;
// pauc/reg00004.H

static const uint64_t EPS_FIR_LOCAL_ACTION2 = 0x10040109ull;

static const uint32_t EPS_FIR_LOCAL_ACTION2_00 = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION2_01 = 1;
static const uint32_t EPS_FIR_LOCAL_ACTION2_02 = 2;
static const uint32_t EPS_FIR_LOCAL_ACTION2_03 = 3;
static const uint32_t EPS_FIR_LOCAL_ACTION2_04 = 4;
static const uint32_t EPS_FIR_LOCAL_ACTION2_05 = 5;
static const uint32_t EPS_FIR_LOCAL_ACTION2_06 = 6;
static const uint32_t EPS_FIR_LOCAL_ACTION2_07 = 7;
static const uint32_t EPS_FIR_LOCAL_ACTION2_08 = 8;
static const uint32_t EPS_FIR_LOCAL_ACTION2_09 = 9;
static const uint32_t EPS_FIR_LOCAL_ACTION2_10 = 10;
static const uint32_t EPS_FIR_LOCAL_ACTION2_11 = 11;
static const uint32_t EPS_FIR_LOCAL_ACTION2_12 = 12;
static const uint32_t EPS_FIR_LOCAL_ACTION2_13 = 13;
static const uint32_t EPS_FIR_LOCAL_ACTION2_14 = 14;
static const uint32_t EPS_FIR_LOCAL_ACTION2_15 = 15;
static const uint32_t EPS_FIR_LOCAL_ACTION2_16 = 16;
static const uint32_t EPS_FIR_LOCAL_ACTION2_17 = 17;
static const uint32_t EPS_FIR_LOCAL_ACTION2_18 = 18;
static const uint32_t EPS_FIR_LOCAL_ACTION2_19 = 19;
static const uint32_t EPS_FIR_LOCAL_ACTION2_20 = 20;
static const uint32_t EPS_FIR_LOCAL_ACTION2_21 = 21;
static const uint32_t EPS_FIR_LOCAL_ACTION2_22 = 22;
static const uint32_t EPS_FIR_LOCAL_ACTION2_23 = 23;
static const uint32_t EPS_FIR_LOCAL_ACTION2_24 = 24;
static const uint32_t EPS_FIR_LOCAL_ACTION2_25 = 25;
static const uint32_t EPS_FIR_LOCAL_ACTION2_26 = 26;
static const uint32_t EPS_FIR_LOCAL_ACTION2_27 = 27;
static const uint32_t EPS_FIR_LOCAL_ACTION2_28 = 28;
static const uint32_t EPS_FIR_LOCAL_ACTION2_29 = 29;
static const uint32_t EPS_FIR_LOCAL_ACTION2_30 = 30;
static const uint32_t EPS_FIR_LOCAL_ACTION2_31 = 31;
static const uint32_t EPS_FIR_LOCAL_ACTION2_32 = 32;
static const uint32_t EPS_FIR_LOCAL_ACTION2_33 = 33;
static const uint32_t EPS_FIR_LOCAL_ACTION2_34 = 34;
static const uint32_t EPS_FIR_LOCAL_ACTION2_35 = 35;
static const uint32_t EPS_FIR_LOCAL_ACTION2_36 = 36;
static const uint32_t EPS_FIR_LOCAL_ACTION2_37 = 37;
static const uint32_t EPS_FIR_LOCAL_ACTION2_38 = 38;
static const uint32_t EPS_FIR_LOCAL_ACTION2_39 = 39;
static const uint32_t EPS_FIR_LOCAL_ACTION2_40 = 40;
static const uint32_t EPS_FIR_LOCAL_ACTION2_41 = 41;
static const uint32_t EPS_FIR_LOCAL_ACTION2_42 = 42;
static const uint32_t EPS_FIR_LOCAL_ACTION2_43 = 43;
static const uint32_t EPS_FIR_LOCAL_ACTION2_44 = 44;
static const uint32_t EPS_FIR_LOCAL_ACTION2_45 = 45;
static const uint32_t EPS_FIR_LOCAL_ACTION2_46 = 46;
static const uint32_t EPS_FIR_LOCAL_ACTION2_47 = 47;
static const uint32_t EPS_FIR_LOCAL_ACTION2_48 = 48;
static const uint32_t EPS_FIR_LOCAL_ACTION2_49 = 49;
static const uint32_t EPS_FIR_LOCAL_ACTION2_50 = 50;
static const uint32_t EPS_FIR_LOCAL_ACTION2_51 = 51;
static const uint32_t EPS_FIR_LOCAL_ACTION2_52 = 52;
static const uint32_t EPS_FIR_LOCAL_ACTION2_53 = 53;
static const uint32_t EPS_FIR_LOCAL_ACTION2_54 = 54;
static const uint32_t EPS_FIR_LOCAL_ACTION2_55 = 55;
static const uint32_t EPS_FIR_LOCAL_ACTION2_56 = 56;
static const uint32_t EPS_FIR_LOCAL_ACTION2_57 = 57;
static const uint32_t EPS_FIR_LOCAL_ACTION2_58 = 58;
static const uint32_t EPS_FIR_LOCAL_ACTION2_59 = 59;
static const uint32_t EPS_FIR_LOCAL_ACTION2_60 = 60;
static const uint32_t EPS_FIR_LOCAL_ACTION2_61 = 61;
static const uint32_t EPS_FIR_LOCAL_ACTION2_62 = 62;
static const uint32_t EPS_FIR_LOCAL_ACTION2_63 = 63;
// pauc/reg00004.H

static const uint64_t EPS_THERM_WSUB_INJECT_REG = 0x10050011ull;

static const uint32_t EPS_THERM_WSUB_INJECT_REG_TRIP = 0;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_TRIP_LEN = 2;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_MODE = 2;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_MODE_LEN = 2;
// pauc/reg00004.H

static const uint64_t OPCG_REG2 = 0x10030004ull;

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
static const uint32_t OPCG_REG2_SM_LBIST_CNTRL = 48;
static const uint32_t OPCG_REG2_SM_LBIST_CNTRL_LEN = 16;
// pauc/reg00004.H

static const uint64_t PB_TL_LINK_RT_DELAY_CTL_REG = 0x10011819ull;

static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET = 0;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN = 2;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET = 2;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN = 2;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT = 4;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN = 2;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT = 6;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN = 2;
// pauc/reg00004.H

static const uint64_t PB_TL_LINK_SYN_23_REG = 0x10011813ull;

static const uint32_t PB_TL_LINK_SYN_23_REG_2_SCOM_SYN0 = 0;
static const uint32_t PB_TL_LINK_SYN_23_REG_2_SCOM_SYN0_LEN = 8;
static const uint32_t PB_TL_LINK_SYN_23_REG_2_SCOM_SYN1 = 8;
static const uint32_t PB_TL_LINK_SYN_23_REG_2_SCOM_SYN1_LEN = 8;
static const uint32_t PB_TL_LINK_SYN_23_REG_2_SCOM_SYN2 = 16;
static const uint32_t PB_TL_LINK_SYN_23_REG_2_SCOM_SYN2_LEN = 8;
static const uint32_t PB_TL_LINK_SYN_23_REG_2_SCOM_SYN3 = 24;
static const uint32_t PB_TL_LINK_SYN_23_REG_2_SCOM_SYN3_LEN = 8;
static const uint32_t PB_TL_LINK_SYN_23_REG_3_SCOM_SYN0 = 32;
static const uint32_t PB_TL_LINK_SYN_23_REG_3_SCOM_SYN0_LEN = 8;
static const uint32_t PB_TL_LINK_SYN_23_REG_3_SCOM_SYN1 = 40;
static const uint32_t PB_TL_LINK_SYN_23_REG_3_SCOM_SYN1_LEN = 8;
static const uint32_t PB_TL_LINK_SYN_23_REG_3_SCOM_SYN2 = 48;
static const uint32_t PB_TL_LINK_SYN_23_REG_3_SCOM_SYN2_LEN = 8;
// pauc/reg00004.H

static const uint64_t PCB_OPCG_GO = 0x10030020ull;

static const uint32_t PCB_OPCG_GO_PCB_OPCGGO = 0;
// pauc/reg00004.H

static const uint64_t PHY_PPE_WRAP_ARB_CSCR_RW = 0x10012c0aull;
static const uint64_t PHY_PPE_WRAP_ARB_CSCR_WO_CLEAR = 0x10012c0bull;
static const uint64_t PHY_PPE_WRAP_ARB_CSCR_WO_OR = 0x10012c0cull;

static const uint32_t PHY_PPE_WRAP_ARB_CSCR_SRAM_ACCESS_MODE = 0;
static const uint32_t PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_ENABLE = 1;
static const uint32_t PHY_PPE_WRAP_ARB_CSCR_ECC_CORRECT_DIS = 2;
static const uint32_t PHY_PPE_WRAP_ARB_CSCR_ECC_DETECT_DIS = 3;
static const uint32_t PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_TYPE = 4;
static const uint32_t PHY_PPE_WRAP_ARB_CSCR_ECC_INJECT_ERR = 5;
static const uint32_t PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7 = 6;
static const uint32_t PHY_PPE_WRAP_ARB_CSCR_SPARE_6_7_LEN = 2;
static const uint32_t PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX = 47;
static const uint32_t PHY_PPE_WRAP_ARB_CSCR_SRAM_SCRUB_INDEX_LEN = 13;
// pauc/reg00004.H

static const uint64_t PHY_PPE_WRAP_XIRAMGA = 0x10012c12ull;

static const uint32_t PHY_PPE_WRAP_XIRAMGA_GA_IR = 0;
static const uint32_t PHY_PPE_WRAP_XIRAMGA_GA_IR_LEN = 32;
static const uint32_t PHY_PPE_WRAP_XIRAMGA_RA_SPRG0 = 32;
static const uint32_t PHY_PPE_WRAP_XIRAMGA_RA_SPRG0_LEN = 32;
// pauc/reg00004.H

static const uint64_t REGION_CCFLUSH_STATUS = 0x10030016ull;

static const uint32_t REGION_CCFLUSH_STATUS_REGION_CCFLUSH = 4;
static const uint32_t REGION_CCFLUSH_STATUS_REGION_CCFLUSH_LEN = 15;
// pauc/reg00004.H

static const uint64_t TRA0_TR0_TRACE_LO_DATA_REG = 0x10010401ull;

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
// pauc/reg00004.H

static const uint64_t TRA0_TR1_CONFIG_4 = 0x10010447ull;

static const uint32_t TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t TRA0_TR1_CONFIG_4_B_LEN = 24;
// pauc/reg00004.H

static const uint64_t TRA1_TR0_CONFIG_2 = 0x10010485ull;

static const uint32_t TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t TRA1_TR0_CONFIG_2_B_LEN = 24;
// pauc/reg00004.H

static const uint64_t TXIRLM_REGS_TX_IMPCAL1_PB = 0x800f040010012c3full;

static const uint32_t TXIRLM_REGS_TX_IMPCAL1_PB_REQ_WO_PULSE_SLOW_SIGNAL = 48;
static const uint32_t TXIRLM_REGS_TX_IMPCAL1_PB_FORCE_SAMPLE_WO_PULSE_SLOW_SIGNAL = 49;
static const uint32_t TXIRLM_REGS_TX_IMPCAL1_PB_TEST_ENABLE_WO_PULSE_SLOW_SIGNAL = 50;
// pauc/reg00004.H

static const uint64_t TXIRLM_REGS_TX_IMPCAL_NVAL_PB = 0x800f1c0010012c3full;

static const uint32_t TXIRLM_REGS_TX_IMPCAL_NVAL_PB_TX_ZCAL_N = 48;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_NVAL_PB_TX_ZCAL_N_LEN = 9;
// pauc/reg00004.H

static const uint64_t TXIRLM_REGS_TX_IMPCAL_SWO3_PB = 0x800f440010012c3full;

static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO3_PB_TX_ZCAL_SWO_IMP_CNTL_1R_1XN_0_15 = 48;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO3_PB_TX_ZCAL_SWO_IMP_CNTL_1R_1XN_0_15_LEN = 16;
// pauc/reg00004.H

static const uint64_t TXIRLM_REGS_ZCAL_FIR_PB = 0x800f880010012c3full;

static const uint32_t TXIRLM_REGS_ZCAL_FIR_PB_ZCAL_FIR_ERRS_RO_SIGNAL = 48;
static const uint32_t TXIRLM_REGS_ZCAL_FIR_PB_ZCAL_FIR_ERRS_RO_SIGNAL_LEN = 2;
// pauc/reg00004.H

static const uint64_t XSTOP1 = 0x1003000cull;

static const uint32_t XSTOP1_MASK_B = 0;
static const uint32_t XSTOP1_ALIGNED_XSTOP1 = 1;
static const uint32_t XSTOP1_TRIGGER_OPCG_ON_XSTOP1 = 2;
static const uint32_t XSTOP1_WAIT_ALLWAYS = 3;
static const uint32_t XSTOP1_PERV = 4;
static const uint32_t XSTOP1_UNIT1 = 5;
static const uint32_t XSTOP1_UNIT2 = 6;
static const uint32_t XSTOP1_UNIT3 = 7;
static const uint32_t XSTOP1_UNIT4 = 8;
static const uint32_t XSTOP1_UNIT5 = 9;
static const uint32_t XSTOP1_UNIT6 = 10;
static const uint32_t XSTOP1_UNIT7 = 11;
static const uint32_t XSTOP1_UNIT8 = 12;
static const uint32_t XSTOP1_UNIT9 = 13;
static const uint32_t XSTOP1_UNIT10 = 14;
static const uint32_t XSTOP1_UNIT11 = 15;
static const uint32_t XSTOP1_UNIT12 = 16;
static const uint32_t XSTOP1_UNIT13 = 17;
static const uint32_t XSTOP1_UNIT14 = 18;
static const uint32_t XSTOP1_WAIT_CYCLES = 48;
static const uint32_t XSTOP1_WAIT_CYCLES_LEN = 12;
// pauc/reg00004.H

#ifndef __PPE_HCODE__
}
}
#include "pauc/reg00004.H"
#endif
#endif
