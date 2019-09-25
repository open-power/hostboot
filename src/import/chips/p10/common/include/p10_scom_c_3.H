/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_3.H $          */
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

#ifndef __p10_scom_c_3_H_
#define __p10_scom_c_3_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


static const uint64_t CPMS_CCDR = 0x200e0e74ull;

static const uint32_t CPMS_CCDR_CHAR_COUNTA_SCALE = 0;
static const uint32_t CPMS_CCDR_CHAR_COUNTA_SCALE_LEN = 4;
static const uint32_t CPMS_CCDR_CHAR_COUNTA_VALUE = 4;
static const uint32_t CPMS_CCDR_CHAR_COUNTA_VALUE_LEN = 16;
static const uint32_t CPMS_CCDR_CHAR_COUNTB_SCALE = 20;
static const uint32_t CPMS_CCDR_CHAR_COUNTB_SCALE_LEN = 4;
static const uint32_t CPMS_CCDR_CHAR_COUNTB_VALUE = 24;
static const uint32_t CPMS_CCDR_CHAR_COUNTB_VALUE_LEN = 16;
static const uint32_t CPMS_CCDR_CHAR_COUNTC_SCALE = 40;
static const uint32_t CPMS_CCDR_CHAR_COUNTC_SCALE_LEN = 4;
static const uint32_t CPMS_CCDR_CHAR_COUNTC_VALUE = 44;
static const uint32_t CPMS_CCDR_CHAR_COUNTC_VALUE_LEN = 16;
static const uint32_t CPMS_CCDR_CHAR_COUNTA_MOD = 60;
static const uint32_t CPMS_CCDR_CHAR_COUNTB_MOD = 61;
static const uint32_t CPMS_CCDR_CHAR_COUNTC_MOD = 62;
static const uint32_t CPMS_CCDR_SAMPLE_DISABLE_INDICATOR = 63;
// c/reg00003.H

static const uint64_t CPMS_CL2_PFETCNTL = 0x200e0e28ull;
static const uint64_t CPMS_CL2_PFETCNTL_WO_CLEAR = 0x200e0e2bull;
static const uint64_t CPMS_CL2_PFETCNTL_WO_OR = 0x200e0e2aull;

static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE = 0;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE_LEN = 2;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE = 2;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE_LEN = 2;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE = 5;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE = 6;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE = 7;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET = 8;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE = 12;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN = 8;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE = 20;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE = 24;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN = 8;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE = 32;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PG_STATE = 42;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PG_STATE_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PG_SEL = 46;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PG_SEL_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PG_STATE = 50;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PG_STATE_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PG_SEL = 54;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PG_SEL_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL = 58;
static const uint32_t CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_ACS_ENABLE = 62;
static const uint32_t CPMS_CL2_PFETCNTL_SRAM_ENABLE = 63;
// c/reg00003.H

static const uint64_t CPMS_FDCR = 0x200e0e40ull;
static const uint64_t CPMS_FDCR_SCOM1 = 0x200e0e43ull;
static const uint64_t CPMS_FDCR_SCOM2 = 0x200e0e42ull;

static const uint32_t CPMS_FDCR_DISABLE = 0;
static const uint32_t CPMS_FDCR_FORCE_SAMPLE = 1;
static const uint32_t CPMS_FDCR_STICKY_CONTROL = 2;
static const uint32_t CPMS_FDCR_STICKY_CONTROL_LEN = 2;
static const uint32_t CPMS_FDCR_CONTROL_UPDATE_DISABLE = 4;
static const uint32_t CPMS_FDCR_SUPPRESS_FTC_UPDATE = 5;
static const uint32_t CPMS_FDCR_CAL_ADJUST = 6;
static const uint32_t CPMS_FDCR_CAL_ADJUST_LEN = 2;
static const uint32_t CPMS_FDCR_DELAY = 8;
static const uint32_t CPMS_FDCR_DELAY_LEN = 8;
static const uint32_t CPMS_FDCR_THRESHOLD_UPDATE_DISABLE = 16;
static const uint32_t CPMS_FDCR_TRIP_OFFSET = 17;
static const uint32_t CPMS_FDCR_TRIP_OFFSET_LEN = 3;
static const uint32_t CPMS_FDCR_DATA0_DETECT = 20;
static const uint32_t CPMS_FDCR_DATA0_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_DATA1_DETECT = 24;
static const uint32_t CPMS_FDCR_DATA1_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_DATA2_DETECT = 28;
static const uint32_t CPMS_FDCR_DATA2_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_LARGE_DROOP_DETECT = 32;
static const uint32_t CPMS_FDCR_LARGE_DROOP_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_SMALL_DROOP_DETECT = 36;
static const uint32_t CPMS_FDCR_SMALL_DROOP_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_SLOPEA_START_DETECT = 40;
static const uint32_t CPMS_FDCR_SLOPEA_START_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_SLOPEA_END_DETECT = 44;
static const uint32_t CPMS_FDCR_SLOPEA_END_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_SLOPEB_START_DETECT = 48;
static const uint32_t CPMS_FDCR_SLOPEB_START_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_SLOPEB_END_DETECT = 52;
static const uint32_t CPMS_FDCR_SLOPEB_END_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_SLOPEA_CYCLES = 56;
static const uint32_t CPMS_FDCR_SLOPEA_CYCLES_LEN = 4;
static const uint32_t CPMS_FDCR_SLOPEB_CYCLES = 60;
static const uint32_t CPMS_FDCR_SLOPEB_CYCLES_LEN = 4;
// c/reg00003.H

static const uint64_t EC_LS_LSU_HOLD_OUT_REG9 = 0x200206c9ull;

static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_DALC_MP3_L1WK_MP_ACCESS_CONCURRENTLY_ERROR_HOLD_OUT = 0;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_RACP_MP4_RC5_RADIR_MULTIHIT_RECOV_HOLD_OUT = 1;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_RACP_MP4_RC5_RADIR_MULTIHIT_XSTOP_HOLD_OUT = 2;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_LMQ_RC4_SSP_DRAIN_AND_SNOOP_CONCURRENTLY_ERROR_HOLD_OUT = 3;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_LMQ_MP4_INVALID_ENTRY_LHR_ERROR_HOLD_OUT = 4;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_LLQ_ERROR_ENTRY_RELAUNCH_PENDING_INVALID_HOLD_OUT = 5;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_LLQ_ERROR_ENTRY_INVALID_WAIT_STATE_CHANGE_HOLD_OUT = 6;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_LLQ_ERROR_FINISH_WAIT_STATE_NON_ZERO_HOLD_OUT = 7;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_SCOM_PARITY_ERROR_HOLD_OUT = 8;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_RC5_STORE_DRAIN_PARITY_ERROR_HOLD_OUT = 9;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_DCACHE_DYNAM_SET_DELETED_HOLD_OUT = 10;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_SETP_DYNAM_SET_DELETED_HOLD_OUT = 11;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_EADIR_DYNAM_SET_DELETED_HOLD_OUT = 12;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG9_RADA_DYNAM_SET_DELETED_HOLD_OUT = 13;
// c/reg00003.H

static const uint64_t EC_PC_COMMON_SPR_V1_HMER_RW_WAND = 0x20020493ull;
static const uint64_t EC_PC_COMMON_SPR_V1_HMER_WO_OR = 0x2002048full;

static const uint32_t EC_PC_COMMON_SPR_V1_HMER_V1_HMER_MALFUNCTION_ALERT = 0;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_V1_HMER_QME_REQUEST = 1;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_V1_HMER_PROC_RCVY_DONE = 2;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_SPARE_3 = 3;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_V1_HMER_TFAC_ERR = 4;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_TFMR_PARITY_ERR = 5;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_SPARE_6 = 6;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_SPARE_7 = 7;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_V1_HMER_XSCOM_FAIL = 8;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_V1_HMER_XSCOM_DONE = 9;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_SPARE_10 = 10;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_V1_HMER_PROC_RCVY_AGAIN = 11;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_SPARE_12 = 12;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_SPARE_13 = 13;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_SPARE_14 = 14;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_SPARE_15 = 15;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_V1_HMER_SCOM_FIR_HMI = 16;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_V1_HMER_THD_WAKE_BLOCKED_TM_SUSPEND = 17;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_V1_HMER_TRIG_FIR_HMI = 18;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_SPARE_19 = 19;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_SPARE_20 = 20;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_V1_HMER_XSCOM_STATUS = 21;
static const uint32_t EC_PC_COMMON_SPR_V1_HMER_V1_HMER_XSCOM_STATUS_LEN = 3;
// c/reg00003.H

static const uint64_t EC_PC_FIR_RAM_CTRL = 0x2002044full;

static const uint32_t EC_PC_FIR_RAM_CTRL_RAM_VTID = 0;
static const uint32_t EC_PC_FIR_RAM_CTRL_RAM_VTID_LEN = 2;
static const uint32_t EC_PC_FIR_RAM_CTRL_PPC_PREDCD = 2;
static const uint32_t EC_PC_FIR_RAM_CTRL_PPC_PREDCD_LEN = 4;
static const uint32_t EC_PC_FIR_RAM_CTRL_SPARE = 6;
static const uint32_t EC_PC_FIR_RAM_CTRL_SPARE_LEN = 2;
static const uint32_t EC_PC_FIR_RAM_CTRL_PPC_INSTR = 8;
static const uint32_t EC_PC_FIR_RAM_CTRL_PPC_INSTR_LEN = 32;
// c/reg00003.H

static const uint64_t EC_PC_FIR_RECOV_FWD_PROG_CTRL = 0x2002044bull;

static const uint32_t EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG = 0;
static const uint32_t EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD = 1;
static const uint32_t EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD_LEN = 3;
// c/reg00003.H

static const uint64_t EC_PC_PMU_SPRCOR_HID = 0x20020415ull;

static const uint32_t EC_PC_PMU_SPRCOR_HID_ONE_PPC = 0;
static const uint32_t EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE = 1;
static const uint32_t EC_PC_PMU_SPRCOR_HID_FLUSH_IC = 2;
static const uint32_t EC_PC_PMU_SPRCOR_HID_EN_ATTN = 3;
static const uint32_t EC_PC_PMU_SPRCOR_HID_HILE = 4;
static const uint32_t EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY = 5;
static const uint32_t EC_PC_PMU_SPRCOR_HID_MEGAMOUTH = 6;
static const uint32_t EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET = 7;
static const uint32_t EC_PC_PMU_SPRCOR_HID_RADIX_MODE = 8;
static const uint32_t EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED = 9;
static const uint32_t EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED = 10;
static const uint32_t EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 = 11;
static const uint32_t EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 = 12;
static const uint32_t EC_PC_PMU_SPRCOR_HID_HID_SPARE_13 = 13;
static const uint32_t EC_PC_PMU_SPRCOR_HID_HID_SPARE_14 = 14;
// c/reg00003.H

static const uint64_t EC_PC_TOD_SYNC000 = 0x200204a3ull;

static const uint32_t EC_PC_TOD_SYNC000_TOD = 0;
static const uint32_t EC_PC_TOD_SYNC000_TOD_LEN = 55;
static const uint32_t EC_PC_TOD_SYNC000_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC000_CHIP_TOD_STATUS_LEN = 4;
// c/reg00003.H

static const uint64_t EC_PC_TOD_SYNC111 = 0x200204a3ull;

static const uint32_t EC_PC_TOD_SYNC111_TOD = 0;
static const uint32_t EC_PC_TOD_SYNC111_TOD_LEN = 48;
static const uint32_t EC_PC_TOD_SYNC111_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC111_CHIP_TOD_STATUS_LEN = 4;
// c/reg00003.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG_2 = 0x20020a45ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_2_A = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_2_B = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_2_B_LEN = 24;
// c/reg00003.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_9 = 0x20020a89ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_9_SPARE_LT = 37;
// c/reg00003.H

static const uint64_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG = 0x2002000eull;

static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER = 0;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE = 1;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY = 9;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS = 10;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY = 11;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM = 16;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC = 19;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC_LEN = 9;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK = 28;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR = 29;
// c/reg00003.H

static const uint64_t L2_L2MISC_L2CERRS_RD_EPS_REG = 0x20020010ull;

static const uint32_t L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE = 0;
static const uint32_t L2_L2MISC_L2CERRS_RD_EPS_REG_0_RD_EPS_VALUE_LEN = 12;
static const uint32_t L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE = 12;
static const uint32_t L2_L2MISC_L2CERRS_RD_EPS_REG_1_RD_EPS_VALUE_LEN = 12;
static const uint32_t L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE = 24;
static const uint32_t L2_L2MISC_L2CERRS_RD_EPS_REG_2_RD_EPS_VALUE_LEN = 12;
// c/reg00003.H

static const uint64_t L2TRA_TR0_CONFIG_4 = 0x20020047ull;

static const uint32_t L2TRA_TR0_CONFIG_4_A = 0;
static const uint32_t L2TRA_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t L2TRA_TR0_CONFIG_4_B = 24;
static const uint32_t L2TRA_TR0_CONFIG_4_B_LEN = 24;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_ERR_RPT0_REG = 0x20010610ull;

static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_BAD_HPC_ERR = 0;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_BAD_HPC_ERR = 1;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3CORTR_NO_LCO_TGTS_ERR = 2;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_TTAG_P_ERR = 3;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_TTAG_P_ERR = 4;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_RCMD_ADDR_P_ERR = 5;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_RCMD_ADDR_P_ERR = 6;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_TTAG_P_ERR = 7;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_TTAG_P_ERR = 8;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN0_CRESP_ATAG_P_ERR = 9;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN1_CRESP_ATAG_P_ERR = 10;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_DATA_RTAG_P_ERR = 11;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_CRESP_ERR = 12;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN_UNSOLICITED_CRESP_ERR = 13;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_CO_UNSOLICITED_CRESP_ERR = 14;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR2 = 15;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_MC_FP_MATE_CMD_ERR3 = 16;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_FSM_P_ERR = 17;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_WI_UNSOLICITED_DATA_ERR = 18;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_PF_UNSOLICITED_DATA_ERR = 19;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR = 20;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_TM_CAM_ERR_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_COFSM_ADDR_ERR = 24;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SNFSM_ADDR_ERR = 25;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL0_CACHE_INHIBIT_ERR = 26;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL1_CACHE_INHIBIT_ERR = 27;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_CACHE_INHIBIT_ERR = 28;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_CACHE_INHIBIT_ERR = 29;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL2_BAD_HPC_ERR = 30;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_L3SDRTL3_BAD_HPC_ERR = 31;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_SN_MACHINE_HANG_ERR = 32;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_RD_MACHINE_HANG_ERR = 33;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_CI_MACHINE_HANG_ERR = 34;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT0_REG_CO_MACHINE_HANG_ERR = 35;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_ERR_RPT1_REG = 0x20010617ull;

static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_HANG_ERR = 0;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_HANG_ERR = 1;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_RD_OVERRUN_CK_ERR = 2;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3L2CTL_PF_OVERRUN_CK_ERR = 3;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3CICTL_CI_OVERRUN_CK_ERR = 4;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA0_DW_DIR_HIT_ERR = 5;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3XMEMA1_DW_DIR_HIT_ERR = 6;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_WR_INVAL_MEMBER_CCAR0 = 7;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_CAC_RD_INVAL_MEMBER_CCAR0 = 8;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_NC_CMD_REQ_ERR = 9;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L2_CMD_REQ_ERR = 10;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_L3_CMD_REQ_ERR = 11;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_12_SPARE = 12;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_13_SPARE = 13;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_14_SPARE = 14;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR0 = 15;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_MC_FP_MATE_CMD_ERR1 = 16;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_OVERFLOW_ERR = 17;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_PB_TOKEN_UNDERFLOW_ERR = 18;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_19_SPARE = 19;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_20_SPARE = 20;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_PF_MACHINE_W4DT_HANG_ERR = 21;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_WI_MACHINE_W4DT_HANG_ERR = 22;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_CO_CRESP_ACK_DEAD_ERR = 23;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_ERR_RPT1_24_SPARE = 24;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_TTAG_P_ERR = 25;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_TTAG_P_ERR = 26;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_RCMD_ADDR_P_ERR = 27;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_RCMD_ADDR_P_ERR = 28;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_TTAG_P_ERR = 29;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_TTAG_P_ERR = 30;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN2_CRESP_ATAG_P_ERR = 31;
static const uint32_t L3_MISC_L3CERRS_ERR_RPT1_REG_SN3_CRESP_ATAG_P_ERR = 32;
// c/reg00003.H

static const uint64_t L3_MISC_L3CERRS_MODE_REG1 = 0x2001060aull;

static const uint32_t L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG = 1;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG_LEN = 5;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG = 6;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG_LEN = 32;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG = 38;
// c/reg00003.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_CTRL = 0x20010685ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_TRIG_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_TRIG = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_MTSPR_MARK = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_MARK_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG0_STOP = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_DBG1_STOP = 7;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_RUN_STOP = 8;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP0_STOP = 9;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_CHIP1_STOP = 10;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112 = 11;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1112_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_XSTOP_STOP = 13;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415 = 14;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_CTRL_SPARE1415_LEN = 2;
// c/reg00003.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_PTRC = 0x20010686ull;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_FIR_MASK_REG_RW = 0x20010643ull;
static const uint64_t NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_AND = 0x20010644ull;
static const uint64_t NC_NCMISC_NCSCOMS_FIR_MASK_REG_WO_OR = 0x20010645ull;

static const uint32_t NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK = 0;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_MASK_REG_FIR_MASK_LEN = 29;
// c/reg00003.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1 = 0x20010653ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_VALID = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_4_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_VALID = 13;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID = 14;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_3_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_VALID = 26;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID = 27;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_2_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_VALID = 39;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID = 40;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG1_1_LPAR_ID_LEN = 12;
// c/reg00003.H

static const uint64_t PSCOM_ERROR_MASK = 0x20010002ull;

static const uint32_t PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR = 3;
static const uint32_t PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t PSCOM_ERROR_MASK_UL_P0_ERROR = 5;
static const uint32_t PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t PSCOM_ERROR_MASK_PSCOM_LOCK_ERR = 11;
static const uint32_t PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_WRITE_NVLD = 12;
static const uint32_t PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t PSCOM_ERROR_MASK_GENERAL_TIMEOUT = 15;
static const uint32_t PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
// c/reg00003.H

static const uint64_t QME_CDBA = 0x200e0800ull;

static const uint32_t QME_CDBA_MESSAGE_NUMBER = 0;
static const uint32_t QME_CDBA_MESSAGE_NUMBER_LEN = 8;
// c/reg00003.H

static const uint64_t QME_CSIR = 0x200e087cull;

static const uint32_t QME_CSIR_PMSR_INSTR_DATA = 36;
static const uint32_t QME_CSIR_PMSR_INSTR_DATA_LEN = 22;
// c/reg00003.H

#ifndef __PPE_HCODE__
}
}
#include "c/reg00003.H"
#endif
#endif
