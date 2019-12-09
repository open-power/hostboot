/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_4.H $          */
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

#ifndef __p10_scom_c_4_H_
#define __p10_scom_c_4_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


static const uint64_t CPMS_CCCR = 0x200e0e70ull;

static const uint32_t CPMS_CCCR_COUNT_MODE = 0;
static const uint32_t CPMS_CCCR_COUNT_MODE_LEN = 2;
static const uint32_t CPMS_CCCR_COUNT_TYPE = 2;
static const uint32_t CPMS_CCCR_COUNT_TYPE_LEN = 2;
static const uint32_t CPMS_CCCR_COUNT_ENABLE_SEL = 4;
static const uint32_t CPMS_CCCR_COUNT_ENABLE_SEL_LEN = 2;
static const uint32_t CPMS_CCCR_INVERT_COUNT_ENABLE = 6;
static const uint32_t CPMS_CCCR_COUNT_ALWAYS_SAMPLED = 7;
static const uint32_t CPMS_CCCR_HI_THRESHOLD = 8;
static const uint32_t CPMS_CCCR_HI_THRESHOLD_LEN = 8;
static const uint32_t CPMS_CCCR_LO_THRESHOLD = 16;
static const uint32_t CPMS_CCCR_LO_THRESHOLD_LEN = 8;
static const uint32_t CPMS_CCCR_SPARE = 24;
static const uint32_t CPMS_CCCR_SPARE_LEN = 2;
// c/reg00004.H

static const uint64_t CPMS_DPCR = 0x200e0ea4ull;

static const uint32_t CPMS_DPCR_PROXY_SCALE_FACTOR = 0;
static const uint32_t CPMS_DPCR_PROXY_SCALE_FACTOR_LEN = 12;
static const uint32_t CPMS_DPCR_DDP_RECHARGE_DELAY = 12;
static const uint32_t CPMS_DPCR_DDP_RECHARGE_DELAY_LEN = 4;
static const uint32_t CPMS_DPCR_DDP_RECHARGE_VALUE = 16;
static const uint32_t CPMS_DPCR_DDP_RECHARGE_VALUE_LEN = 8;
// c/reg00004.H

static const uint64_t CPMS_PSSR = 0x200e0e9cull;

static const uint32_t CPMS_PSSR_ACCUM_ERROR = 0;
static const uint32_t CPMS_PSSR_ACCUM_ERROR_LEN = 20;
static const uint32_t CPMS_PSSR_AVG_FTX_PHASE0 = 20;
static const uint32_t CPMS_PSSR_AVG_FTX_PHASE0_LEN = 8;
static const uint32_t CPMS_PSSR_AVG_FTX_PHASE1 = 28;
static const uint32_t CPMS_PSSR_AVG_FTX_PHASE1_LEN = 8;
static const uint32_t CPMS_PSSR_AVG_FTX_TOTAL = 36;
static const uint32_t CPMS_PSSR_AVG_FTX_TOTAL_LEN = 8;
static const uint32_t CPMS_PSSR_PITCH_PERIOD_NUMBER = 44;
static const uint32_t CPMS_PSSR_PITCH_PERIOD_NUMBER_LEN = 4;
static const uint32_t CPMS_PSSR_PITCH_SUB_PERIOD = 48;
static const uint32_t CPMS_PSSR_PITCH_SUB_PERIOD_LEN = 2;
static const uint32_t CPMS_PSSR_PITCH_PERIOD_TIMER = 50;
static const uint32_t CPMS_PSSR_PITCH_PERIOD_TIMER_LEN = 13;
static const uint32_t CPMS_PSSR_PITCH_ACTIVE = 63;
// c/reg00004.H

static const uint64_t CPMS_RVCSR = 0x200e0e04ull;
static const uint64_t CPMS_RVCSR_WO_CLEAR = 0x200e0e07ull;
static const uint64_t CPMS_RVCSR_WO_OR = 0x200e0e06ull;

static const uint32_t CPMS_RVCSR_RVID_ENABLE = 0;
static const uint32_t CPMS_RVCSR_RVID_OVERRIDE = 1;
static const uint32_t CPMS_RVCSR_ACS_CALIBRATE = 2;
static const uint32_t CPMS_RVCSR_RVRM_TUNE = 6;
static const uint32_t CPMS_RVCSR_RVRM_TUNE_LEN = 6;
static const uint32_t CPMS_RVCSR_RVID_ACTIVE = 32;
static const uint32_t CPMS_RVCSR_BYPASS_ACTIVE = 33;
static const uint32_t CPMS_RVCSR_RVID_ENABLED = 34;
// c/reg00004.H

static const uint64_t EC_LS_LSU_HOLD_OUT_REG11 = 0x200206cbull;

static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_00 = 0;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_01 = 1;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_02 = 2;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_03 = 3;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_04 = 4;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_05 = 5;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_06 = 6;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_07 = 7;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_08 = 8;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_09 = 9;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_10 = 10;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_11 = 11;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_12 = 12;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_13 = 13;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_14 = 14;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG11_15 = 15;
// c/reg00004.H

static const uint64_t EC_LS_LSU_HOLD_OUT_REG7 = 0x200206c7ull;

static const uint32_t EC_LS_LSU_HOLD_OUT_REG7_LRQ0_OVERFLOW_ERR_HOLD_OUT = 0;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG7_LRQ1_OVERFLOW_ERR_HOLD_OUT = 1;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD0_RES_MULTILMQ_ERR_HOLD_OUT = 2;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG7_RSVT_LD1_RES_MULTILMQ_ERR_HOLD_OUT = 3;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT = 4;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_RECOV_HOLD_OUT = 5;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST0_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT = 6;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG7_DMAG_ST1_RES_EADIR_MULTIHIT_XSTOP_HOLD_OUT = 7;
// c/reg00004.H

static const uint64_t EC_PC_COMMON_SPR_VSU_HOLD_OUT = 0x200204b6ull;
// c/reg00004.H

static const uint64_t EC_PC_FIR_RECOV_THOLD = 0x2002044cull;

static const uint32_t EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT = 0;
static const uint32_t EC_PC_FIR_RECOV_THOLD_THRESHOLD_LIMIT_LEN = 8;
static const uint32_t EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET = 8;
static const uint32_t EC_PC_FIR_RECOV_THOLD_THRESHOLD_RESET_LEN = 2;
// c/reg00004.H

static const uint64_t EC_PC_IMA_EVENT_MASK = 0x20020400ull;

static const uint32_t EC_PC_IMA_EVENT_MASK_IC_TAP = 30;
static const uint32_t EC_PC_IMA_EVENT_MASK_IC_TAP_LEN = 3;
static const uint32_t EC_PC_IMA_EVENT_MASK_DIS_WRAP = 33;
static const uint32_t EC_PC_IMA_EVENT_MASK_FREEZE = 34;
static const uint32_t EC_PC_IMA_EVENT_MASK_EN_D_PRE = 36;
static const uint32_t EC_PC_IMA_EVENT_MASK_EN_I_PRE = 37;
static const uint32_t EC_PC_IMA_EVENT_MASK_ONE_EVENT = 38;
static const uint32_t EC_PC_IMA_EVENT_MASK_EVENT_VTID = 39;
static const uint32_t EC_PC_IMA_EVENT_MASK_EVENT_VTID_LEN = 2;
static const uint32_t EC_PC_IMA_EVENT_MASK_EVENT_SELECT = 41;
static const uint32_t EC_PC_IMA_EVENT_MASK_EVENT_SELECT_LEN = 5;
// c/reg00004.H

static const uint64_t EC_PC_SCR5 = 0x2002048bull;
// c/reg00004.H

static const uint64_t EC_PC_TOD_SYNC011 = 0x200204a3ull;

static const uint32_t EC_PC_TOD_SYNC011_TOD = 0;
static const uint32_t EC_PC_TOD_SYNC011_TOD_LEN = 52;
static const uint32_t EC_PC_TOD_SYNC011_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC011_CHIP_TOD_STATUS_LEN = 4;
// c/reg00004.H

static const uint64_t EC_PC_TOD_SYNC100 = 0x200204a3ull;

static const uint32_t EC_PC_TOD_SYNC100_TOD = 0;
static const uint32_t EC_PC_TOD_SYNC100_TOD_LEN = 51;
static const uint32_t EC_PC_TOD_SYNC100_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC100_CHIP_TOD_STATUS_LEN = 4;
// c/reg00004.H

static const uint64_t L2_L2MISC_L2CERRS_ERR_RPT1 = 0x20020013ull;

static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_CRESP_ERR = 0;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_IDLE_L3_DWDONE_ERR = 1;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_RCX_UNEXP_PB_RC_DTAG_PCHK_ERR = 2;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_REF_WITH_FLAG_IDLE_ERR = 3;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_KILL_REF_WITH_FLAG_IDLE_ERR = 4;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_DW_SET_SI_BY_MACH = 5;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_PD_DIR_MULT_HIT = 6;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_B0_SD_DIR_MULT_HIT = 7;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_B1_SD_DIR_MULT_HIT = 8;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_B2_SD_DIR_MULT_HIT = 9;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_B3_SD_DIR_MULT_HIT = 10;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_TEMP_MARK_ERR = 11;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_HANG_WAITING_FOR_FP_MATE = 12;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_BAD_FP_MATE = 13;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_LSU_TAG_REUSE_ERR = 14;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_MULT_REQ_ERR = 15;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_IFU_LATE_CANCEL_ERR = 16;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_XPF_MULT_REQ_ERR = 17;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_XLT_QUEUE_OVRFLW_ERR = 18;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_L3PF_REQ_ERR = 19;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_NCU_TID_DONE_ERR = 20;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_REQ_DEC_ERR = 21;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_ABCD = 22;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_11_LRU_MEM_INVALID_EFGH = 23;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_COMING_ERR = 24;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_OVERFLOW_ERR = 25;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_STQ_BOUNCE_ERR = 26;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_RC_PBBUS_SFSTAT_ERR = 27;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_TMA_LARXA_VS_FRCMISS_SV_ERR = 28;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_22_RC_TGT_NODAL_REQ_CRESP_DINC_ERR = 29;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_22_SN_TGT_NODAL_REQ_CRESP_DINC_ERR = 30;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT1_14_SNX_FSM_PARITY_ERR = 31;
// c/reg00004.H

static const uint64_t L2_L2MISC_L2CERRS_MODE_REG0 = 0x2002000aull;

static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_LRU_DIRECT_MAP = 0;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_RANDOM_EN = 1;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_EN = 2;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM = 3;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_SINGLE_MEM_LEN = 8;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_L3_DIS = 11;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ME_SX_EN = 12;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_CO_SOFT_PURGE_ALL_LINES_EN = 13;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_DCBZ_TRASHMODE_EN = 14;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_CAC_ERR_REPAIR_EN = 15;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_LINEDEL_ON_CAC_UE_EN = 16;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_HW_TRIG_LINEDEL_LDDISP_CE_EN = 17;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL = 18;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_L2_PB_ARB_RATE_SEL_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L3_ADDR_EN = 21;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_RC_FRC_DISP_EQ_NTM_INIG_SI_TO_RCR_EN = 22;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_CHIP_CONTAINED_MODE_EN = 23;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK = 24;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_Q_BIT_TID_MASK_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_HASH_L2_ADDR_EN = 28;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_SPARES1 = 29;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_SPARES1_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_STQ_PF_EN = 32;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_SPARES2 = 33;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_PERFMON_INFO_SRC_ED_SEL = 34;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_SPARES3 = 35;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_SPARES3_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_SKIP_GRP_SCOPE_EN = 38;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_CFG_TM_DTT_DIS = 39;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE = 40;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG0_MODE_REG0_SPARE_LEN = 2;
// c/reg00004.H

static const uint64_t L2_L2MISC_L2CERRS_TOPOTABLE2 = 0x20020016ull;

static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_16_VAL = 0;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_17_VAL = 1;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_18_VAL = 2;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_19_VAL = 3;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_20_VAL = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_21_VAL = 5;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_22_VAL = 6;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_23_VAL = 7;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_16 = 8;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_16_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_17 = 12;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_17_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_18 = 16;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_18_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_19 = 20;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_19_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_20 = 24;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_20_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_21 = 28;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_21_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_22 = 32;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_22_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_23 = 36;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE2_23_LEN = 4;
// c/reg00004.H

static const uint64_t L2TRA_TR1_CONFIG_3 = 0x20020086ull;

static const uint32_t L2TRA_TR1_CONFIG_3_C = 0;
static const uint32_t L2TRA_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t L2TRA_TR1_CONFIG_3_D = 24;
static const uint32_t L2TRA_TR1_CONFIG_3_D_LEN = 24;
// c/reg00004.H

static const uint64_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD = 0x20010627ull;

static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_VALID = 0;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_VALID = 1;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_VALID = 2;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_VALID = 3;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_VALID = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_VALID = 5;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_VALID = 6;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_VALID = 7;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16 = 8;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_16_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17 = 12;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_17_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18 = 16;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_18_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19 = 20;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_19_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20 = 24;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_20_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21 = 28;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_21_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22 = 32;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_22_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23 = 36;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD_23_LEN = 4;
// c/reg00004.H

static const uint64_t NC_NCMISC_NCSCOMS_ERR_RPT_REG = 0x2001064eull;

static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_OVERFLOW_ERR = 0;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_ILLEGAL_STORE_SIZE = 1;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LD_AMO_SEQ_ERR = 2;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_TTAG_PERR = 3;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR0_ATAG_PERR = 4;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_TTAG_PERR = 5;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR1_ATAG_PERR = 6;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_TTAG_PERR = 7;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR2_ATAG_PERR = 8;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_TTAG_PERR = 9;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CR3_ATAG_PERR = 10;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_ADDR_PERR = 11;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP0_TTAG_PERR = 12;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_ADDR_PERR = 13;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNP1_TTAG_PERR = 14;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PBARB_TRASHMODE_ERR = 15;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_TLBIE_BAD_OP_ERR = 16;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_MASTER_SEQ_ID_PAR_ERR = 17;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_SNOOP_TLBIE_SEQ_PARITY_ERR = 18;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR1 = 19;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_LVL_ERR2 = 20;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR1 = 21;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_ABORT_LVL_ERR2 = 22;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_PURGE_DONE_LVL_ERR1 = 23;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_IMA_FSM_TIMEOUT = 24;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_CORE_IS_DEAD_ERR = 25;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_1_UNEXP_SNPTLBCMP_NOT_MY_LPAR_ERR = 26;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLB_DATA_PAR_ERR = 27;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_LD_TGT_NODAL_DINC_ERR = 28;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_19_ST_TGT_NODAL_DINC_ERR = 29;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_TLBSM_FSM_PERR = 30;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_XSQCT_FSM_PERR = 31;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_LDCTL_FSM_PERR = 32;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_SNCTL_FSM_PERR = 33;
static const uint32_t NC_NCMISC_NCSCOMS_ERR_RPT_REG_0_UNEXP_IMA_DATA = 34;
// c/reg00004.H

static const uint64_t NC_NCMISC_NCSCOMS_FIR_ACTION0_REG = 0x20010646ull;

static const uint32_t NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0 = 0;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_ACTION0_REG_FIR_ACTION0_LEN = 29;
// c/reg00004.H

static const uint64_t NC_NCMISC_NCSCOMS_FIR_ACTION1_REG = 0x20010647ull;

static const uint32_t NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1 = 0;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_ACTION1_REG_FIR_ACTION1_LEN = 29;
// c/reg00004.H

static const uint64_t QME_SPWU_FSP = 0x200e0834ull;

static const uint32_t QME_SPWU_FSP_REQ = 0;
static const uint32_t QME_SPWU_FSP_DONE = 4;
// c/reg00004.H

static const uint64_t QME_SPWU_HYP = 0x200e083cull;

static const uint32_t QME_SPWU_HYP_REQ = 0;
static const uint32_t QME_SPWU_HYP_DONE = 4;
// c/reg00004.H

static const uint64_t QME_SPWU_OCC = 0x200e0838ull;

static const uint32_t QME_SPWU_OCC_REQ = 0;
static const uint32_t QME_SPWU_OCC_DONE = 4;
// c/reg00004.H

static const uint64_t QME_SSH_FSP = 0x200e0824ull;

static const uint32_t QME_SSH_FSP_STOP_GATED = 0;
static const uint32_t QME_SSH_FSP_SPECIAL_WKUP_DONE = 1;
static const uint32_t QME_SSH_FSP_STOP_TRANSITION = 2;
static const uint32_t QME_SSH_FSP_STOP_TRANSITION_LEN = 2;
static const uint32_t QME_SSH_FSP_REQ_STOP_LEVEL = 4;
static const uint32_t QME_SSH_FSP_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_FSP_ACT_STOP_LEVEL = 8;
static const uint32_t QME_SSH_FSP_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL = 12;
static const uint32_t QME_SSH_FSP_DEEPEST_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL = 16;
static const uint32_t QME_SSH_FSP_DEEPEST_ACT_STOP_LEVEL_LEN = 4;
// c/reg00004.H

static const uint64_t QME_SSH_HYP = 0x200e082cull;

static const uint32_t QME_SSH_HYP_STOP_GATED = 0;
static const uint32_t QME_SSH_HYP_SPECIAL_WKUP_DONE = 1;
static const uint32_t QME_SSH_HYP_STOP_TRANSITION = 2;
static const uint32_t QME_SSH_HYP_STOP_TRANSITION_LEN = 2;
static const uint32_t QME_SSH_HYP_REQ_STOP_LEVEL = 4;
static const uint32_t QME_SSH_HYP_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_HYP_ACT_STOP_LEVEL = 8;
static const uint32_t QME_SSH_HYP_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL = 12;
static const uint32_t QME_SSH_HYP_DEEPEST_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL = 16;
static const uint32_t QME_SSH_HYP_DEEPEST_ACT_STOP_LEVEL_LEN = 4;
// c/reg00004.H

static const uint64_t QME_SSH_OCC = 0x200e0828ull;

static const uint32_t QME_SSH_OCC_STOP_GATED = 0;
static const uint32_t QME_SSH_OCC_SPECIAL_WKUP_DONE = 1;
static const uint32_t QME_SSH_OCC_STOP_TRANSITION = 2;
static const uint32_t QME_SSH_OCC_STOP_TRANSITION_LEN = 2;
static const uint32_t QME_SSH_OCC_REQ_STOP_LEVEL = 4;
static const uint32_t QME_SSH_OCC_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OCC_ACT_STOP_LEVEL = 8;
static const uint32_t QME_SSH_OCC_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL = 12;
static const uint32_t QME_SSH_OCC_DEEPEST_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL = 16;
static const uint32_t QME_SSH_OCC_DEEPEST_ACT_STOP_LEVEL_LEN = 4;
// c/reg00004.H

static const uint64_t WRITE_PROTECT_ENABLE_REG = 0x20010005ull;

static const uint32_t WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING = 0;
static const uint32_t WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1;
// c/reg00004.H

#ifndef __PPE_HCODE__
}
}
#include "c/reg00004.H"
#endif
#endif
