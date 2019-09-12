/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_2.H $          */
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

#ifndef __p10_scom_c_2_H_
#define __p10_scom_c_2_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


static const uint64_t CPMS_DTIR = 0x200e0e80ull;

static const uint32_t CPMS_DTIR_VALID = 0;
static const uint32_t CPMS_DTIR_THREAD_SEL = 1;
static const uint32_t CPMS_DTIR_THREAD_SEL_LEN = 3;
static const uint32_t CPMS_DTIR_MODE_SEL = 6;
static const uint32_t CPMS_DTIR_MODE_SEL_LEN = 2;
static const uint32_t CPMS_DTIR_VALUE = 8;
static const uint32_t CPMS_DTIR_VALUE_LEN = 8;
static const uint32_t CPMS_DTIR_WINDOW_SEL = 17;
static const uint32_t CPMS_DTIR_WINDOW_SEL_LEN = 3;
// c/reg00002.H

static const uint64_t CPMS_FMMR = 0x200e0e4cull;

static const uint32_t CPMS_FMMR_ADJ_WARN_STAGGER_DISABLE = 0;
static const uint32_t CPMS_FMMR_ADJ_WARN_STAGGER_CYCLES = 1;
static const uint32_t CPMS_FMMR_ADJ_WARN_STAGGER_CYCLES_LEN = 3;
static const uint32_t CPMS_FMMR_ADJ_WARN_WEIGHT = 4;
static const uint32_t CPMS_FMMR_ADJ_WARN_RESPONSE = 5;
static const uint32_t CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT = 6;
static const uint32_t CPMS_FMMR_ADJ_WARN_OUTPUT_SELECT_LEN = 3;
static const uint32_t CPMS_FMMR_DDP_TRIP_SELECT = 9;
static const uint32_t CPMS_FMMR_DDP_TRIP_SELECT_LEN = 3;
static const uint32_t CPMS_FMMR_SLOPEA_TYPE_SELECT = 12;
static const uint32_t CPMS_FMMR_SLOPEA_TYPE_SELECT_LEN = 2;
static const uint32_t CPMS_FMMR_SLOPEB_TYPE_SELECT = 14;
static const uint32_t CPMS_FMMR_SLOPEB_TYPE_SELECT_LEN = 2;
static const uint32_t CPMS_FMMR_SMALL_ASSERT_STABILITY = 16;
static const uint32_t CPMS_FMMR_SMALL_ASSERT_STABILITY_LEN = 2;
static const uint32_t CPMS_FMMR_SMALL_DEASSERT_STABILITY = 18;
static const uint32_t CPMS_FMMR_SMALL_DEASSERT_STABILITY_LEN = 2;
static const uint32_t CPMS_FMMR_SMALL_INITIAL_CYCLES = 20;
static const uint32_t CPMS_FMMR_SMALL_INITIAL_CYCLES_LEN = 4;
static const uint32_t CPMS_FMMR_SMALL_INITIAL_ACTION = 24;
static const uint32_t CPMS_FMMR_SMALL_INITIAL_ACTION_LEN = 6;
static const uint32_t CPMS_FMMR_SMALL_PREFETCH_ACTION = 30;
static const uint32_t CPMS_FMMR_SMALL_PREFETCH_ACTION_LEN = 2;
static const uint32_t CPMS_FMMR_SMALL_DITHER_WINDOW_SEL = 32;
static const uint32_t CPMS_FMMR_SMALL_VECTOR_ACTION = 33;
static const uint32_t CPMS_FMMR_SMALL_VECTOR_ACTION_LEN = 3;
static const uint32_t CPMS_FMMR_SLOPE_TIMEOUT_SELECT = 36;
static const uint32_t CPMS_FMMR_SMALL_THROTTLE_ACTION = 37;
static const uint32_t CPMS_FMMR_SMALL_THROTTLE_ACTION_LEN = 3;
static const uint32_t CPMS_FMMR_SMALL_DITHER_REPEAT = 40;
static const uint32_t CPMS_FMMR_SMALL_DITHER_REPEAT_LEN = 4;
static const uint32_t CPMS_FMMR_SMALL_DITHER_INCREASE = 44;
static const uint32_t CPMS_FMMR_SMALL_DITHER_INCREASE_LEN = 4;
static const uint32_t CPMS_FMMR_SMALL_DITHER_INITIAL = 48;
static const uint32_t CPMS_FMMR_SMALL_DITHER_INITIAL_LEN = 5;
static const uint32_t CPMS_FMMR_DPLL_DATA2_SEL = 53;
static const uint32_t CPMS_FMMR_DPLL_DATA1_SEL = 54;
static const uint32_t CPMS_FMMR_DPLL_DATA1_SEL_LEN = 2;
static const uint32_t CPMS_FMMR_DPLL_DATA0_SEL = 56;
static const uint32_t CPMS_FMMR_DPLL_DATA0_SEL_LEN = 2;
static const uint32_t CPMS_FMMR_DDS_ERROR_ENCODE_DISABLE = 58;
static const uint32_t CPMS_FMMR_SMALL_RESPONSE_DISABLE = 59;
static const uint32_t CPMS_FMMR_SLOPE_REPORT_SEL = 60;
static const uint32_t CPMS_FMMR_OVERRIDE_VECTOR_LIMIT = 61;
static const uint32_t CPMS_FMMR_OVERRIDE_VECTOR_LIMIT_LEN = 3;
// c/reg00002.H

static const uint64_t CPMS_WOXR = 0x200e0e8cull;

static const uint32_t CPMS_WOXR_THROTTLE_INDEX = 2;
static const uint32_t CPMS_WOXR_THROTTLE_INDEX_LEN = 6;
// c/reg00002.H

static const uint64_t EC_LS_LSU_HOLD_OUT_REG10 = 0x200206caull;

static const uint32_t EC_LS_LSU_HOLD_OUT_REG10_EXES0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT = 0;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG10_EXES1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT = 1;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG10_SRQD_RTYPE_MISMATCH_ERR_HOLD_OUT = 2;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG10_SRQD_STEAL_OP_DURING_RECONFIG_ERR_HOLD_OUT = 3;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_DISCARD_STORAGE_OVERFLOW_ERR_HOLD_OUT = 4;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG10_SRQD_TM_HWSYNC_OVERFLOW_ERR_HOLD_OUT = 5;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_NTCACK_ERR_HOLD_OUT = 6;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG10_SRQD_UNEXPECTED_SYNCACK_ERR_HOLD_OUT = 7;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG10_SRQD_PASTE_EXCEPTION_DURING_RECONFIG_ERR_HOLD_OUT = 8;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG10_SRQD_SNOOPTLBIE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT = 9;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG10_SRQD_PTEUPDATE_RECEIVED_WITH_IN_PROGRESS_ERR_HOLD_OUT = 10;
// c/reg00002.H

static const uint64_t EC_LS_LSU_HOLD_OUT_REG6 = 0x200206c6ull;

static const uint32_t EC_LS_LSU_HOLD_OUT_REG6_MQ_RC4_RLD_INV_RD_ERROR_HOLD_OUT = 0;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG6_MQ_RC7_RLD_SAME_SCTR_TWICE_ERROR_HOLD_OUT = 1;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG6_MQ_RC6_SSP_RLD_SNP_BTW_BEATS_ERROR_HOLD_OUT = 2;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG6_MQ_KILLED_CDF_FOR_CI_LOAD_ERROR_HOLD_OUT = 3;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG6_MQ_MP4_3_IEQ1_FETCHES_SAME_TID_ERROR_HOLD_OUT = 4;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG6_GC0_OVERFLOW_ERR_HOLD_OUT = 5;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG6_GC0_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT = 6;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG6_GC0_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT = 7;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG6_GC0_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT = 8;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG6_GC1_OVERFLOW_ERR_HOLD_OUT = 9;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG6_GC1_ENTRY_NO_LONGER_UNALIGN_ERR_HOLD_OUT = 10;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG6_GC1_UA_RIGHT_W_NO_LEFT_ERR_HOLD_OUT = 11;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG6_GC1_OP_BOTH_UA_LEFT_AND_RIGHT_ERR_HOLD_OUT = 12;
// c/reg00002.H

static const uint64_t EC_PC_SCR4 = 0x2002048aull;
// c/reg00002.H

static const uint64_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT = 0x20020455ull;

static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HANG_DETECT_HOLD_OUT = 0;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_HUNG_HOLD_OUT = 1;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_CORE_STEP_HOLD_OUT = 2;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_DETECT_STATE_HOLD_OUT = 3;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_HANG_RECOV_HOLD_OUT = 4;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_NEST_HANG_DETECT_HOLD_OUT = 5;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_PPC_COMPLETE_HOLD_OUT = 6;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_RECOV_IN_MAINT_HOLD_OUT = 8;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT = 9;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_0_THREAD_CTL_STATE_HOLD_OUT = 10;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HANG_DETECT_HOLD_OUT = 11;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_HUNG_HOLD_OUT = 12;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_CORE_STEP_HOLD_OUT = 13;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_DETECT_STATE_HOLD_OUT = 14;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_HANG_RECOV_HOLD_OUT = 15;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_NEST_HANG_DETECT_HOLD_OUT = 16;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_PPC_COMPLETE_HOLD_OUT = 17;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_RECOV_IN_MAINT_HOLD_OUT = 19;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT = 20;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_1_THREAD_CTL_STATE_HOLD_OUT = 21;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HANG_DETECT_HOLD_OUT = 22;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_HUNG_HOLD_OUT = 23;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_CORE_STEP_HOLD_OUT = 24;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_DETECT_STATE_HOLD_OUT = 25;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_HANG_RECOV_HOLD_OUT = 26;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_NEST_HANG_DETECT_HOLD_OUT = 27;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_PPC_COMPLETE_HOLD_OUT = 28;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_RECOV_IN_MAINT_HOLD_OUT = 30;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT = 31;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_2_THREAD_CTL_STATE_HOLD_OUT = 32;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HANG_DETECT_HOLD_OUT = 33;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_HUNG_HOLD_OUT = 34;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_CORE_STEP_HOLD_OUT = 35;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_DETECT_STATE_HOLD_OUT = 36;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_HANG_RECOV_HOLD_OUT = 37;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_NEST_HANG_DETECT_HOLD_OUT = 38;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_PPC_COMPLETE_HOLD_OUT = 39;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_RECOV_IN_MAINT_HOLD_OUT = 41;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_STOP_COMPLETE_IN_SUSPEND_HOLD_OUT = 42;
static const uint32_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT_3_THREAD_CTL_STATE_HOLD_OUT = 43;
// c/reg00002.H

static const uint64_t EC_PC_TOD_SYNC010 = 0x200204a3ull;

static const uint32_t EC_PC_TOD_SYNC010_TOD = 0;
static const uint32_t EC_PC_TOD_SYNC010_TOD_LEN = 53;
static const uint32_t EC_PC_TOD_SYNC010_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC010_CHIP_TOD_STATUS_LEN = 4;
// c/reg00002.H

static const uint64_t EC_PC_TOD_SYNC101 = 0x200204a3ull;

static const uint32_t EC_PC_TOD_SYNC101_TOD = 0;
static const uint32_t EC_PC_TOD_SYNC101_TOD_LEN = 50;
static const uint32_t EC_PC_TOD_SYNC101_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC101_CHIP_TOD_STATUS_LEN = 4;
// c/reg00002.H

static const uint64_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG = 0x20020a41ull;

static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_ERR_RPT0 = 0x20020012ull;

static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR = 0;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR = 1;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR = 2;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR = 3;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR = 4;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR = 5;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR = 6;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR = 7;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR = 8;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR = 9;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR = 10;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR = 11;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR = 12;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR = 13;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR = 14;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR = 15;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR = 16;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR = 17;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR = 18;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR = 19;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR = 20;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR = 21;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR = 22;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR = 23;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR = 24;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR = 25;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR = 26;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR = 27;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR = 28;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR = 29;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR = 30;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT = 31;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR = 32;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL = 33;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT = 34;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE = 35;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ = 36;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR = 37;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR = 38;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR = 39;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR = 40;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR = 41;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_MODE_REG1 = 0x2002000bull;

static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS = 0;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS = 1;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE = 2;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE_LEN = 2;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV = 4;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV = 8;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1 = 12;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE1_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN = 16;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2 = 17;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE2_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE = 20;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN = 23;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_MODE_REG1_SPARE3 = 24;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN = 25;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM = 26;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM_LEN = 2;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_TOPOTABLE3 = 0x20020017ull;

static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL = 0;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL = 1;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL = 2;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL = 3;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL = 5;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL = 6;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL = 7;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_24 = 8;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_24_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_25 = 12;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_25_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_26 = 16;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_26_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_27 = 20;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_27_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_28 = 24;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_28_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_29 = 28;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_29_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_30 = 32;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_30_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_31 = 36;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_31_LEN = 4;
// c/reg00002.H

static const uint64_t L2TRA_TR1_TRACE_HI_DATA_REG = 0x20020080ull;

static const uint32_t L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00002.H

static const uint64_t L2TRA_TR1_CONFIG_2 = 0x20020085ull;

static const uint32_t L2TRA_TR1_CONFIG_2_A = 0;
static const uint32_t L2TRA_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t L2TRA_TR1_CONFIG_2_B = 24;
static const uint32_t L2TRA_TR1_CONFIG_2_B_LEN = 24;
// c/reg00002.H

static const uint64_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD = 0x20010625ull;

static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID = 0;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID = 1;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID = 2;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID = 3;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID = 5;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID = 6;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID = 7;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0 = 8;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1 = 12;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2 = 16;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3 = 20;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4 = 24;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5 = 28;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6 = 32;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7 = 36;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_LEN = 4;
// c/reg00002.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_MODE = 0x20010680ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0 = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE_LEN = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV = 10;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2 = 11;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP = 13;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP = 14;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP = 15;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL = 16;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY = 17;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP = 18;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES = 19;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES_LEN = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET = 24;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET_LEN = 8;
// c/reg00002.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG = 0x20010650ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR_LEN = 38;
// c/reg00002.H

#ifndef __PPE_HCODE__
}
}
#include "c/reg00002.H"
#endif
#endif
