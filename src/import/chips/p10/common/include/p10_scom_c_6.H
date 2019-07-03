/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_6.H $          */
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

#ifndef __p10_scom_c_6_H_
#define __p10_scom_c_6_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


static const uint64_t CPMS_CERR = 0x200e0e10ull;

static const uint32_t CPMS_CERR_L3_PFET_SEQ_ERR = 0;
static const uint32_t CPMS_CERR_CL2_PFET_SEQ_ERR = 1;
static const uint32_t CPMS_CERR_MMA_PFET_SEQ_ERR = 2;
static const uint32_t CPMS_CERR_DDS_ERR = 3;
static const uint32_t CPMS_CERR_L3_CLOCK_SYNC_ERR = 4;
static const uint32_t CPMS_CERR_CL2_CLOCK_SYNC_ERR = 5;
static const uint32_t CPMS_CERR_DPT_ACCESS_ERROR = 6;
static const uint32_t CPMS_CERR_SPARE_ERR0 = 7;
static const uint32_t CPMS_CERR_SPARE_ERR1 = 8;
static const uint32_t CPMS_CERR_FTC_DEBUG_EVENT = 9;
static const uint32_t CPMS_CERR_FTC_DEBUG_EVENT_LEN = 3;
// c/reg00006.H

static const uint64_t CPMS_CUCR = 0x200e0e3cull;
static const uint64_t CPMS_CUCR_SCOM1 = 0x200e0e3full;
static const uint64_t CPMS_CUCR_SCOM2 = 0x200e0e3eull;

static const uint32_t CPMS_CUCR_ENABLE_CORE_SHADOW = 0;
static const uint32_t CPMS_CUCR_ENABLE_CORE_SAMPLE = 1;
static const uint32_t CPMS_CUCR_DPT_PER_THREAD_MODE = 2;
static const uint32_t CPMS_CUCR_SPARE = 3;
static const uint32_t CPMS_CUCR_SPARE_LEN = 2;
static const uint32_t CPMS_CUCR_REFRESH_FTC_SHADOW = 9;
static const uint32_t CPMS_CUCR_REFRESH_PP_SHADOW = 10;
static const uint32_t CPMS_CUCR_REFRESH_DPT_SETTINGS = 11;
static const uint32_t CPMS_CUCR_INDUCED_DROOP_COUNT = 12;
static const uint32_t CPMS_CUCR_INDUCED_DROOP_COUNT_LEN = 3;
static const uint32_t CPMS_CUCR_PCB_SKEW_ADJ = 17;
static const uint32_t CPMS_CUCR_PCB_SKEW_ADJ_LEN = 3;
static const uint32_t CPMS_CUCR_FTC_SHADOW_STATE = 33;
static const uint32_t CPMS_CUCR_FTC_SHADOW_STATE_LEN = 3;
static const uint32_t CPMS_CUCR_FTC_SHADOW_PENDING = 36;
static const uint32_t CPMS_CUCR_FTC_SHADOW_PENDING_LEN = 4;
static const uint32_t CPMS_CUCR_PP_SHADOW_STATE = 40;
static const uint32_t CPMS_CUCR_PP_SHADOW_STATE_LEN = 2;
static const uint32_t CPMS_CUCR_PP_SHADOW_PENDING = 42;
static const uint32_t CPMS_CUCR_PP_SHADOW_PENDING_LEN = 3;
static const uint32_t CPMS_CUCR_DPT_UPDATE_STATE = 45;
static const uint32_t CPMS_CUCR_DPT_UPDATE_STATE_LEN = 2;
static const uint32_t CPMS_CUCR_DPT_UPDATE_PENDING = 47;
static const uint32_t CPMS_CUCR_DPT_UPDATE_PENDING_LEN = 3;
static const uint32_t CPMS_CUCR_CORE_REFRESH_ACTIVE = 50;
static const uint32_t CPMS_CUCR_CORE_REFRESH_ACTIVE_LEN = 3;
static const uint32_t CPMS_CUCR_FDCR_UPDATE_INPROGRESS = 56;
static const uint32_t CPMS_CUCR_QME_EVENTS_PENDING = 57;
static const uint32_t CPMS_CUCR_QME_EVENTS_PENDING_LEN = 7;
// c/reg00006.H

static const uint64_t CPMS_MMA_PFETCNTL = 0x200e0e30ull;
static const uint64_t CPMS_MMA_PFETCNTL_WO_CLEAR = 0x200e0e33ull;
static const uint64_t CPMS_MMA_PFETCNTL_WO_OR = 0x200e0e32ull;

static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE = 0;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_SEQ_STATE_LEN = 2;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_VAL_OVERRIDE = 4;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_SEL_OVERRIDE = 5;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE = 12;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN = 8;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE = 20;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PFET_SEL_VALUE_LEN = 4;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PG_STATE = 42;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PG_STATE_LEN = 4;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PG_SEL = 46;
static const uint32_t CPMS_MMA_PFETCNTL_VDD_PG_SEL_LEN = 4;
static const uint32_t CPMS_MMA_PFETCNTL_MMA_FORCE_CL2 = 63;
// c/reg00006.H

static const uint64_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT3 = 0x20020603ull;
// c/reg00006.H

static const uint64_t EC_PC_COMMON_SPR_V0_HMER_RW_WAND = 0x20020492ull;
static const uint64_t EC_PC_COMMON_SPR_V0_HMER_WO_OR = 0x2002048eull;

static const uint32_t EC_PC_COMMON_SPR_V0_HMER_MALFUNCTION_ALERT = 0;
static const uint32_t EC_PC_COMMON_SPR_V0_HMER_QME_REQUEST = 1;
static const uint32_t EC_PC_COMMON_SPR_V0_HMER_PROC_RCVY_DONE = 2;
static const uint32_t EC_PC_COMMON_SPR_V0_HMER_TFAC_ERR = 4;
static const uint32_t EC_PC_COMMON_SPR_V0_HMER_XSCOM_FAIL = 8;
static const uint32_t EC_PC_COMMON_SPR_V0_HMER_XSCOM_DONE = 9;
static const uint32_t EC_PC_COMMON_SPR_V0_HMER_PROC_RCVY_AGAIN = 11;
static const uint32_t EC_PC_COMMON_SPR_V0_HMER_SCOM_FIR_HMI = 16;
static const uint32_t EC_PC_COMMON_SPR_V0_HMER_THD_WAKE_BLOCKED_TM_SUSPEND = 17;
static const uint32_t EC_PC_COMMON_SPR_V0_HMER_TRIG_FIR_HMI = 18;
static const uint32_t EC_PC_COMMON_SPR_V0_HMER_XSCOM_STATUS = 21;
static const uint32_t EC_PC_COMMON_SPR_V0_HMER_XSCOM_STATUS_LEN = 3;
// c/reg00006.H

static const uint64_t EC_PC_FIR_CORE_RW = 0x20020440ull;
static const uint64_t EC_PC_FIR_CORE_WO_AND = 0x20020441ull;
static const uint64_t EC_PC_FIR_CORE_WO_OR = 0x20020442ull;

static const uint32_t EC_PC_FIR_CORE_IF_SRAM_REC_ERROR = 0;
static const uint32_t EC_PC_FIR_CORE_TC_FIR_XSTOP_ERROR = 1;
static const uint32_t EC_PC_FIR_CORE_IF_RFILE_REC_ERROR = 2;
static const uint32_t EC_PC_FIR_CORE_IF_RFILE_XSTOP_ERROR = 3;
static const uint32_t EC_PC_FIR_CORE_IF_LOG_REC_ERROR = 4;
static const uint32_t EC_PC_FIR_CORE_IF_LOG_XSTOP_ERROR = 5;
static const uint32_t EC_PC_FIR_CORE_VS_VSMM_ACC_ERR = 7;
static const uint32_t EC_PC_FIR_CORE_PC_RECOV_XSTOP_ERROR = 8;
static const uint32_t EC_PC_FIR_CORE_VS_STF_ERROR = 9;
static const uint32_t EC_PC_FIR_CORE_SD_LOG_REC_ERROR = 11;
static const uint32_t EC_PC_FIR_CORE_SD_LOG_XSTOP_ERROR = 12;
static const uint32_t EC_PC_FIR_CORE_SD_NOT_MT_CI_REC_ERROR = 13;
static const uint32_t EC_PC_FIR_CORE_SD_MCHK_AND_ME_EQ_0_ERROR = 14;
static const uint32_t EC_PC_FIR_CORE_SD_L2_UE_ERROR = 15;
static const uint32_t EC_PC_FIR_CORE_SD_L2_UE_OVER_THRES_ERROR = 16;
static const uint32_t EC_PC_FIR_CORE_SD_L2_CI_UE_ERROR = 17;
static const uint32_t EC_PC_FIR_CORE_MU_SRAM_PARITY_ERROR = 18;
static const uint32_t EC_PC_FIR_CORE_MU_LOG_REC_ERROR = 21;
static const uint32_t EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR = 22;
static const uint32_t EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR = 23;
static const uint32_t EC_PC_FIR_CORE_VS_LOG_REC_ERROR = 24;
static const uint32_t EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR = 25;
static const uint32_t EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR = 26;
static const uint32_t EC_PC_FIR_CORE_VS_DU_LOG_REC_ERROR = 27;
static const uint32_t EC_PC_FIR_CORE_PC_SYS_XSTOP_ERROR = 28;
static const uint32_t EC_PC_FIR_CORE_LS_SRAM_PARITY_ERROR = 29;
static const uint32_t EC_PC_FIR_CORE_LS_SETDELETE_ERROR = 30;
static const uint32_t EC_PC_FIR_CORE_LS_RFILE_REC_ERROR = 31;
static const uint32_t EC_PC_FIR_CORE_LS_RFILE_XSTOP_ERROR = 32;
static const uint32_t EC_PC_FIR_CORE_MU_TLB_MULTIHIT_ERROR = 33;
static const uint32_t EC_PC_FIR_CORE_MU_SLB_MULTIHIT_ERROR = 34;
static const uint32_t EC_PC_FIR_CORE_LS_DERAT_MULTIHIT_ERROR = 35;
static const uint32_t EC_PC_FIR_CORE_PC_FWD_PROGRESS_ERROR = 36;
static const uint32_t EC_PC_FIR_CORE_LS_LOG_REC_ERROR = 37;
static const uint32_t EC_PC_FIR_CORE_LS_LOG_XSTOP_ERROR = 38;
static const uint32_t EC_PC_FIR_CORE_LS_NOT_MT_REC_ERROR = 39;
static const uint32_t EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR = 41;
static const uint32_t EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR = 43;
static const uint32_t EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR = 45;
static const uint32_t EC_PC_FIR_CORE_PC_TFAC_XSTOP_ERROR = 47;
static const uint32_t EC_PC_FIR_CORE_PC_HANG_RECOVERY_FAILED = 52;
static const uint32_t EC_PC_FIR_CORE_PC_CORE_HANG_DETECT_ERROR = 53;
static const uint32_t EC_PC_FIR_CORE_PC_NEST_HANG_DETECT_ERROR = 55;
static const uint32_t EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_REC_ERROR = 56;
static const uint32_t EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR = 57;
static const uint32_t EC_PC_FIR_CORE_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR = 58;
static const uint32_t EC_PC_FIR_CORE_PC_SCOM_ERROR = 59;
static const uint32_t EC_PC_FIR_CORE_PC_XSTOP_ON_DBG_TRIGGER_ERROR = 60;
static const uint32_t EC_PC_FIR_CORE_PC_FW_INJ_REC_ERROR = 61;
static const uint32_t EC_PC_FIR_CORE_PC_FW_INJ_XSTOP_ERROR = 62;
static const uint32_t EC_PC_FIR_CORE_PC_PHYP_XSTOP_ERROR = 63;
// c/reg00006.H

static const uint64_t EC_PC_FIR_CORE_FIRMASK_RW = 0x20020443ull;
static const uint64_t EC_PC_FIR_CORE_FIRMASK_WO_AND = 0x20020444ull;
static const uint64_t EC_PC_FIR_CORE_FIRMASK_WO_OR = 0x20020445ull;

static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_IF_SRAM_REC_ERROR = 0;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_TC_FIR_XSTOP_ERROR = 1;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_REC_ERROR = 2;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_IF_RFILE_XSTOP_ERROR = 3;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_REC_ERROR = 4;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_IF_LOG_XSTOP_ERROR = 5;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_VS_VSMM_ACC_ERROR = 7;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_XSTOP_ERROR = 8;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_VS_STF_ERROR = 9;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_REC_ERROR = 11;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_LOG_XSTOP_ERROR = 12;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_NOT_MT_CI_REC_ERROR = 13;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_MCHK_AND_ME_EQ_0_ERROR = 14;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_ERROR = 15;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_UE_OVER_THRES_ERROR = 16;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_SD_L2_CI_UE_ERROR = 17;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_SRAM_PARITY_ERROR = 18;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_REC_ERROR = 21;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR = 22;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR = 23;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR = 24;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR = 25;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR = 26;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_VS_DU_LOG_REC_ERROR = 27;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_SYS_XSTOP_ERROR = 28;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_SRAM_PARITY_ERROR = 29;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_SETDELETE_ERROR = 30;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_REC_ERROR = 31;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_RFILE_XSTOP_ERROR = 32;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_MULTIHIT_ERROR = 33;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_MULTIHIT_ERROR = 34;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_DERAT_MULTIHIT_ERROR = 35;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_FWD_PROGRESS_ERROR = 36;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_REC_ERROR = 37;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_LOG_XSTOP_ERROR = 38;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_NOT_MT_REC_ERROR = 39;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR = 41;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR = 43;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR = 45;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFAC_XSTOP_ERROR = 47;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_HANG_RECOVERY_FAILED = 52;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_CORE_HANG_DETECT_ERROR = 53;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_NEST_HANG_DETECT_ERROR = 55;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_REC_ERROR = 56;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR = 57;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR = 58;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_SCOM_ERROR = 59;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_XSTOP_ON_DBG_TRIGGER_ERROR = 60;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_REC_ERROR = 61;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_FW_INJ_XSTOP_ERROR = 62;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_PHYP_XSTOP_ERROR = 63;
// c/reg00006.H

static const uint64_t EC_PC_FIR_ERR_INJ = 0x2002044dull;

static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TO_LSU = 0;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TO_IFU = 1;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TO_ISU = 2;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TO_VSU = 3;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TO_PC = 4;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TO_MMU = 5;
static const uint32_t EC_PC_FIR_ERR_INJ_ERROR_PULSE_OR_LEVEL = 6;
static const uint32_t EC_PC_FIR_ERR_INJ_CLEAR_STICKY_LEVEL = 7;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_SCOM_WRITE = 8;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER = 9;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TRIGGER1 = 10;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TOD_TAP = 11;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK = 12;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_BLOCK_LEN = 2;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_DELAY_AFTER_BLOCK = 14;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK = 15;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_RECOVERY_BLK_EXTEND = 16;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL = 17;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_TAP_SEL_LEN = 4;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK = 21;
static const uint32_t EC_PC_FIR_ERR_INJ_ERR_INJ_HYP_BLOCK_LEN = 3;
// c/reg00006.H

static const uint64_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS = 0x20020449ull;
// c/reg00006.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG_4 = 0x20020a47ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_4_A = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_4_B = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_4_B_LEN = 24;
// c/reg00006.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG = 0x20020a82ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// c/reg00006.H

static const uint64_t L2_L2MISC_L2CERRS_FIR_MASK_REG_RW = 0x20020003ull;
static const uint64_t L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND = 0x20020004ull;
static const uint64_t L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR = 0x20020005ull;

static const uint32_t L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK = 0;
static const uint32_t L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK_LEN = 40;
// c/reg00006.H

static const uint64_t L2TRA_TR0_CONFIG_2 = 0x20020045ull;

static const uint32_t L2TRA_TR0_CONFIG_2_A = 0;
static const uint32_t L2TRA_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t L2TRA_TR0_CONFIG_2_B = 24;
static const uint32_t L2TRA_TR0_CONFIG_2_B_LEN = 24;
// c/reg00006.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2 = 0x2001064bull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_HANG_POLL_PULSE_DIV_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_CP_DATA_POLL_PULSE_DIV_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_SNOOP_DATA_POLL_PULSE_DIV_LEN = 10;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV = 18;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG1_HANG_POLL_PULSE_DIV_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV = 22;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_TLB_STG2_HANG_POLL_PULSE_DIV_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV = 26;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG2_MASTER_TLB_DATA_POLL_PULSE_DIV_LEN = 10;
// c/reg00006.H

static const uint64_t WRITE_PROTECT_RINGS_REG = 0x20010006ull;

static const uint32_t WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS = 0;
static const uint32_t WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS_LEN = 32;
// c/reg00006.H

#ifndef __PPE_HCODE__
}
}
#include "c/reg00006.H"
#endif
#endif
