/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_8.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __p10_scom_c_8_H_
#define __p10_scom_c_8_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


static const uint64_t CPMS_ACDR = 0x200e0e7cull;

static const uint32_t CPMS_ACDR_CHAR_COUNTA_SCALE = 0;
static const uint32_t CPMS_ACDR_CHAR_COUNTA_SCALE_LEN = 4;
static const uint32_t CPMS_ACDR_CHAR_COUNTA_VALUE = 4;
static const uint32_t CPMS_ACDR_CHAR_COUNTA_VALUE_LEN = 16;
static const uint32_t CPMS_ACDR_CHAR_COUNTB_SCALE = 20;
static const uint32_t CPMS_ACDR_CHAR_COUNTB_SCALE_LEN = 4;
static const uint32_t CPMS_ACDR_CHAR_COUNTB_VALUE = 24;
static const uint32_t CPMS_ACDR_CHAR_COUNTB_VALUE_LEN = 16;
static const uint32_t CPMS_ACDR_CHAR_COUNTC_SCALE = 40;
static const uint32_t CPMS_ACDR_CHAR_COUNTC_SCALE_LEN = 4;
static const uint32_t CPMS_ACDR_CHAR_COUNTC_VALUE = 44;
static const uint32_t CPMS_ACDR_CHAR_COUNTC_VALUE_LEN = 16;
static const uint32_t CPMS_ACDR_CHAR_COUNTA_MOD = 60;
static const uint32_t CPMS_ACDR_CHAR_COUNTB_MOD = 61;
static const uint32_t CPMS_ACDR_CHAR_COUNTC_MOD = 62;
static const uint32_t CPMS_ACDR_SAMPLE_DISABLE_INDICATOR = 63;
// c/reg00008.H

static const uint64_t CPMS_CL2_PFETSTAT = 0x200e0e2cull;

static const uint32_t CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE = 0;
static const uint32_t CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE = 1;
static const uint32_t CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE = 2;
static const uint32_t CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE = 3;
static const uint32_t CPMS_CL2_PFETSTAT_VDD_PFET_ENABLE_ACTUAL = 16;
static const uint32_t CPMS_CL2_PFETSTAT_VDD_PFET_ENABLE_ACTUAL_LEN = 8;
static const uint32_t CPMS_CL2_PFETSTAT_VCS_PFET_ENABLE_ACTUAL = 24;
static const uint32_t CPMS_CL2_PFETSTAT_VCS_PFET_ENABLE_ACTUAL_LEN = 8;
static const uint32_t CPMS_CL2_PFETSTAT_SRAM_ENABLE_ACTUAL = 63;
// c/reg00008.H

static const uint64_t CPMS_DTCR = 0x200e0e84ull;

static const uint32_t CPMS_DTCR_DPT_MODE = 0;
static const uint32_t CPMS_DTCR_DPT_MODE_LEN = 2;
static const uint32_t CPMS_DTCR_DPT_MODE_UPDATE = 2;
static const uint32_t CPMS_DTCR_DPT_RATE_UPDATE = 3;
static const uint32_t CPMS_DTCR_DPT_INFLIGHT_UPDATE = 4;
static const uint32_t CPMS_DTCR_DPT_WINDOW_SEL = 5;
static const uint32_t CPMS_DTCR_DPT_WINDOW_SEL_LEN = 3;
static const uint32_t CPMS_DTCR_CORE_DPT_RATE_LIMIT = 8;
static const uint32_t CPMS_DTCR_CORE_DPT_RATE_LIMIT_LEN = 8;
static const uint32_t CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT = 16;
static const uint32_t CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT_LEN = 8;
static const uint32_t CPMS_DTCR_DISABLE_DPT_ON_UPDATE = 24;
static const uint32_t CPMS_DTCR_CORE_SMT_MODE = 34;
static const uint32_t CPMS_DTCR_CORE_SMT_MODE_LEN = 2;
// c/reg00008.H

static const uint64_t CPMS_ESCR = 0x200e0e6cull;

static const uint32_t CPMS_ESCR_DURATION_MODE = 0;
static const uint32_t CPMS_ESCR_DURATION_MODE_LEN = 2;
static const uint32_t CPMS_ESCR_DURATION_EVENT_INVERT = 2;
static const uint32_t CPMS_ESCR_DURATION_EVENT_INVERT_LEN = 2;
static const uint32_t CPMS_ESCR_DURATION_RANGE = 4;
static const uint32_t CPMS_ESCR_DURATION_RANGE_LEN = 3;
static const uint32_t CPMS_ESCR_DURATION_START_SEL = 7;
static const uint32_t CPMS_ESCR_DURATION_START_SEL_LEN = 5;
static const uint32_t CPMS_ESCR_DURATION_TIMEOUT_SEL = 12;
static const uint32_t CPMS_ESCR_DURATION_TIMEOUT_SEL_LEN = 3;
static const uint32_t CPMS_ESCR_DURATION_STOP_SEL = 15;
static const uint32_t CPMS_ESCR_DURATION_STOP_SEL_LEN = 5;
static const uint32_t CPMS_ESCR_STATEW_SELECT = 20;
static const uint32_t CPMS_ESCR_STATEW_SELECT_LEN = 3;
static const uint32_t CPMS_ESCR_STATEW_INVERT = 23;
static const uint32_t CPMS_ESCR_STATEZ_SELECT = 24;
static const uint32_t CPMS_ESCR_STATEZ_SELECT_LEN = 3;
static const uint32_t CPMS_ESCR_STATEZ_PULSE = 27;
static const uint32_t CPMS_ESCR_EVENTX_PULSE = 28;
static const uint32_t CPMS_ESCR_EVENTY_PULSE = 29;
static const uint32_t CPMS_ESCR_STATEX_PULSE = 30;
static const uint32_t CPMS_ESCR_STATEY_PULSE = 31;
static const uint32_t CPMS_ESCR_STATEX_COMPARE = 32;
static const uint32_t CPMS_ESCR_STATEX_COMPARE_LEN = 4;
static const uint32_t CPMS_ESCR_STATEX_DONTCARE = 36;
static const uint32_t CPMS_ESCR_STATEX_DONTCARE_LEN = 4;
static const uint32_t CPMS_ESCR_STATEY_COMPARE = 40;
static const uint32_t CPMS_ESCR_STATEY_COMPARE_LEN = 4;
static const uint32_t CPMS_ESCR_STATEY_DONTCARE = 44;
static const uint32_t CPMS_ESCR_STATEY_DONTCARE_LEN = 4;
static const uint32_t CPMS_ESCR_EVENTX_COMPARE = 48;
static const uint32_t CPMS_ESCR_EVENTX_COMPARE_LEN = 4;
static const uint32_t CPMS_ESCR_EVENTX_DONTCARE = 52;
static const uint32_t CPMS_ESCR_EVENTX_DONTCARE_LEN = 4;
static const uint32_t CPMS_ESCR_EVENTY_COMPARE = 56;
static const uint32_t CPMS_ESCR_EVENTY_COMPARE_LEN = 4;
static const uint32_t CPMS_ESCR_EVENTY_DONTCARE = 60;
static const uint32_t CPMS_ESCR_EVENTY_DONTCARE_LEN = 4;
// c/reg00008.H

static const uint64_t EC_LS_LSU_HOLD_OUT_REG13 = 0x200206cdull;

static const uint32_t EC_LS_LSU_HOLD_OUT_REG13_D_XFVC_UPDATE_PASS_FAIL_NOT_ONE_HOT_ERR_HOLD_OUT = 0;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG13_D_SRQZ01_AGN_INVAL_WALK_V_BOTH_ACTIVE_SAME_CYCLE_ERR_HOLD_OUT = 1;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG13_D_ATOMIC_PTEUPDATE_RECEIVED_ERR_HOLD_OUT = 2;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG13_D_RECONFIG_L2_NOT_EMPTY_ERR_HOLD_OUT = 3;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG13_D_RECONFIG_NOT_QUIESCED_ERR_HOLD_OUT = 4;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG13_D_DRAINING_INVALID_TTYPE_ERR_HOLD_OUT = 5;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG13_P_RC7_DRAIN_V_NO_REQ_ACTIVE_ERR_HOLD_OUT = 6;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG13_P_PTEUPDATE_RECEIVED_WITH_NO_FIELDS_ERR_HOLD_OUT = 7;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG13_P_LS_L2_ST_G_SHOULD_NOT_BE_SET_ERR_HOLD_OUT = 8;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG13_P_LS_L2_ST_ORD_G_SHOULD_NOT_BE_SET_ERR_HOLD_OUT = 9;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG13_P_MU_LS_ST_RC_RA60_EQUALS_0_ERR_HOLD_OUT = 10;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG13_P_NCU_STORE_32B_ERR_HOLD_OUT = 11;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG13_P_STORE_0B_ERR_HOLD_OUT = 12;
// c/reg00008.H

static const uint64_t EC_LS_LSU_HOLD_OUT_REG5 = 0x200206c5ull;

static const uint32_t EC_LS_LSU_HOLD_OUT_REG5_RES_LD0_DCAC_TAG_ERR_HOLD_OUT = 0;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG5_RES_LD1_DCAC_TAG_ERR_HOLD_OUT = 1;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG5_RES_LD0_EADIR_ERR_HOLD_OUT = 2;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG5_RES_LD1_EADIR_ERR_HOLD_OUT = 3;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG5_LD0_ACC_LLQ_RF_PERR_RECOV_HOLD_OUT = 4;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG5_LD1_ACC_LLQ_RF_PERR_RECOV_HOLD_OUT = 5;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG5_ERTO_MP2_ERATMHE_HOLD_OUT = 6;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG5_ERTO_MP2_ERRPT_ERAT_PARITY_ERR_HOLD_OUT = 7;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG5_ERTO_MP3_ERRPT_FMISS_ERR_HOLD_OUT_0 = 8;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG5_ERTO_MP3_ERRPT_FMISS_ERR_HOLD_OUT_1 = 9;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG5_ERTO_MP3_ERRPT_FMISS_ERR_HOLD_OUT_2 = 10;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG5_ERTO_MP3_ERRPT_FMISS_ERR_HOLD_OUT_3 = 11;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG5_LMQ_MP5_BAD_RESPONSE_HOLD_OUT = 12;
// c/reg00008.H

static const uint64_t EC_PC_COMMON_SPR_V3_HMER_RW_WAND = 0x20020495ull;
static const uint64_t EC_PC_COMMON_SPR_V3_HMER_WO_OR = 0x20020491ull;

static const uint32_t EC_PC_COMMON_SPR_V3_HMER_V3_HMER_MALFUNCTION_ALERT = 0;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_SPARE_1 = 1;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_V3_HMER_PROC_RCVY_DONE = 2;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_V3_HMER_SUSPEND_MODE = 3;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_V3_HMER_TFAC_ERR = 4;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_V3_HMER_TFX_ERR = 5;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_SPARE_6 = 6;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_SPARE_7 = 7;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_V3_HMER_XSCOM_FAIL = 8;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_V3_HMER_XSCOM_DONE = 9;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_SPARE_10 = 10;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_V3_HMER_PROC_RCVY_AGAIN = 11;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_SPARE_12 = 12;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_SPARE_13 = 13;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_SPARE_14 = 14;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_SPARE_15 = 15;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_V3_HMER_SCOM_FIR_HMI = 16;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_V3_HMER_THD_WAKE_BLOCKED_TM_SUSPEND = 17;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_V3_HMER_TRIG_FIR_HMI = 18;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_SPARE_19 = 19;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_SPARE_20 = 20;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_V3_HMER_XSCOM_STATUS = 21;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_V3_HMER_XSCOM_STATUS_LEN = 3;
// c/reg00008.H

static const uint64_t EC_PC_PMU_SPRCOR_HV_STATE = 0x2002040dull;

static const uint32_t EC_PC_PMU_SPRCOR_HV_STATE_0_MSR_HV = 56;
static const uint32_t EC_PC_PMU_SPRCOR_HV_STATE_1_MSR_HV = 57;
static const uint32_t EC_PC_PMU_SPRCOR_HV_STATE_2_MSR_HV = 58;
static const uint32_t EC_PC_PMU_SPRCOR_HV_STATE_3_MSR_HV = 59;
static const uint32_t EC_PC_PMU_SPRCOR_HV_STATE_0_MSR_PR = 60;
static const uint32_t EC_PC_PMU_SPRCOR_HV_STATE_1_MSR_PR = 61;
static const uint32_t EC_PC_PMU_SPRCOR_HV_STATE_2_MSR_PR = 62;
static const uint32_t EC_PC_PMU_SPRCOR_HV_STATE_3_MSR_PR = 63;
// c/reg00008.H

static const uint64_t EC_PC_PMU_SPRCOR_SCOMC_EN = 0x2002040aull;

static const uint32_t EC_PC_PMU_SPRCOR_SCOMC_EN_ENABLE_INDIRECT_PMU_SCOM = 0;
// c/reg00008.H

static const uint64_t EC_PC_PMU_SPRCOR_SCOMD = 0x20020409ull;
// c/reg00008.H

static const uint64_t EC_PC_PMU_SPRCOR_SHID0 = 0x2002040cull;

static const uint32_t EC_PC_PMU_SPRCOR_SHID0_TRIG2_TRACE_EN = 0;
static const uint32_t EC_PC_PMU_SPRCOR_SHID0_DIS_TRACE_SPR = 1;
// c/reg00008.H

static const uint64_t EC_PC_SCR7 = 0x2002048dull;
// c/reg00008.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_5 = 0x20020a88ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_5_C = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_5_D = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_5_D_LEN = 24;
// c/reg00008.H

static const uint64_t L2_L2MISC_L2CERRS_TOPOTABLE0 = 0x20020014ull;

static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_0_VAL = 0;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_1_VAL = 1;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_2_VAL = 2;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_3_VAL = 3;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_4_VAL = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_5_VAL = 5;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_6_VAL = 6;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_7_VAL = 7;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_0 = 8;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_0_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_1 = 12;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_1_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_2 = 16;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_2_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_3 = 20;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_3_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_4 = 24;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_4_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_5 = 28;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_5_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_6 = 32;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_6_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_7 = 36;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_7_LEN = 4;
// c/reg00008.H

static const uint64_t L2TRA_TR1_CONFIG_1 = 0x20020084ull;

static const uint32_t L2TRA_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L2TRA_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00008.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_STAT = 0x20010682ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_PURGE_IN_PROG = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_PURGE_DONE = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_CRESP_OV = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_REPAIR = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_BUF_WAIT = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_STATUS_TRIG_DROPPED_LT = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_ADDR_ERROR = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_STATUS_REC_DROPPED_LT = 7;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_INIT = 8;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_PREREQ = 9;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_READY = 10;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_TRACING = 11;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_PAUSED = 12;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_FLUSH = 13;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_COMPLETE = 14;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_ENABLE = 15;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_STAMP = 16;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_STATUS_SCOM_ERROR = 17;
// c/reg00008.H

static const uint64_t PSCOM_STATUS_ERROR_REG = 0x20010001ull;

static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_P0_ERROR = 3;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_P0_ERROR = 5;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_LOCK_ERR = 11;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_READ_WRITE_NVLD = 12;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_GENERAL_TIMEOUT = 15;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_WDATA_PARITY_ERROR = 18;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_ADDRESS_PARITY_ERROR = 19;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_WDATA_PARITY_ERROR = 20;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_P0_ERROR = 21;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_UL_RDATA_PARITY_ERROR = 22;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_UL_P0_ERROR = 23;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_INTERFACE_MACHINE = 24;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_P2S_MACHINE = 25;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 26;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 27;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 28;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_LOCK_ERR = 29;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_READ_WRITE_NVLD = 30;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_ADDR_INVALID = 31;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_COMMAND_PARITY_ERROR = 32;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_GENERAL_TIMEOUT = 33;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 34;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 35;
// c/reg00008.H

static const uint64_t QME_QOSR = 0x200e08a0ull;

static const uint32_t QME_QOSR_0_QOS_INDEX = 2;
static const uint32_t QME_QOSR_0_QOS_INDEX_LEN = 6;
static const uint32_t QME_QOSR_1_QOS_INDEX = 10;
static const uint32_t QME_QOSR_1_QOS_INDEX_LEN = 6;
static const uint32_t QME_QOSR_2_QOS_INDEX = 18;
static const uint32_t QME_QOSR_2_QOS_INDEX_LEN = 6;
static const uint32_t QME_QOSR_3_QOS_INDEX = 26;
static const uint32_t QME_QOSR_3_QOS_INDEX_LEN = 6;
static const uint32_t QME_QOSR_0_DTC_INDEX = 34;
static const uint32_t QME_QOSR_0_DTC_INDEX_LEN = 6;
static const uint32_t QME_QOSR_1_DTC_INDEX = 42;
static const uint32_t QME_QOSR_1_DTC_INDEX_LEN = 6;
static const uint32_t QME_QOSR_2_DTC_INDEX = 50;
static const uint32_t QME_QOSR_2_DTC_INDEX_LEN = 6;
static const uint32_t QME_QOSR_3_DTC_INDEX = 58;
static const uint32_t QME_QOSR_3_DTC_INDEX_LEN = 6;
// c/reg00008.H

#ifndef __PPE_HCODE__
}
}
#include "c/reg00008.H"
#endif
#endif
