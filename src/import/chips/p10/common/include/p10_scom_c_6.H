/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_6.H $          */
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

#ifndef __p10_scom_c_6_H_
#define __p10_scom_c_6_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> [CPMS_CERR]
static const uint64_t CPMS_CERR = 0x200e0e10ull;

static const uint32_t CPMS_CERR_L3_PFET_SEQ_ERR = 0;
static const uint32_t CPMS_CERR_CL2_PFET_SEQ_ERR = 1;
static const uint32_t CPMS_CERR_MMA_PFET_SEQ_ERR = 2;
static const uint32_t CPMS_CERR_DDS_ERR = 3;
static const uint32_t CPMS_CERR_L3_CLOCK_SYNC_ERR = 4;
static const uint32_t CPMS_CERR_CL2_CLOCK_SYNC_ERR = 5;
static const uint32_t CPMS_CERR_DPT_ACCESS_ERROR = 6;
static const uint32_t CPMS_CERR_PROXY_UNDERFLOW = 7;
static const uint32_t CPMS_CERR_PITCH_SATURATED = 8;
static const uint32_t CPMS_CERR_FTC_DEBUG_EVENT = 9;
static const uint32_t CPMS_CERR_FTC_DEBUG_EVENT_LEN = 3;
static const uint32_t P10_20_CPMS_CERR_CCFG_PARITY_ERR = 12; // p10:20,
static const uint32_t P10_20_CPMS_CERR_RVRM_DROPOUT = 13; // p10:20,
static const uint32_t P10_20_CPMS_CERR_PITCH_UPDATE_ERR = 14; // p10:20,
static const uint32_t P10_20_CPMS_CERR_SPARE_ERR = 15; // p10:20,
//<< [CPMS_CERR]
// c/reg00006.H

//>> [CPMS_CUCR]
static const uint64_t CPMS_CUCR = 0x200e0e3cull;
static const uint64_t CPMS_CUCR_SCOM2 = 0x200e0e3eull;
static const uint64_t CPMS_CUCR_WO_CLEAR = 0x200e0e3full;

static const uint32_t CPMS_CUCR_ENABLE_CORE_SHADOW = 0;
static const uint32_t CPMS_CUCR_ENABLE_CORE_SAMPLE = 1;
static const uint32_t CPMS_CUCR_DPT_PER_THREAD_MODE = 2;
static const uint32_t CPMS_CUCR_SPARE = 3;
static const uint32_t CPMS_CUCR_SPARE_LEN = 2;
static const uint32_t CPMS_CUCR_CORE_MODE_SAMPLE_DISABLE = 5;
static const uint32_t CPMS_CUCR_STOP01_SAMPLE_ENABLE = 6;
static const uint32_t CPMS_CUCR_REFRESH_FTC_SHADOW = 9;
static const uint32_t CPMS_CUCR_REFRESH_PP_SHADOW = 10;
static const uint32_t CPMS_CUCR_REFRESH_DPT_SETTINGS = 11;
static const uint32_t CPMS_CUCR_INDUCED_DROOP_COUNT = 12;
static const uint32_t CPMS_CUCR_INDUCED_DROOP_COUNT_LEN = 3;
static const uint32_t CPMS_CUCR_PCB_SKEW_ADJ = 17;
static const uint32_t CPMS_CUCR_PCB_SKEW_ADJ_LEN = 3;
static const uint32_t CPMS_CUCR_FDCR_UPDATE_INPROGRESS = 31;
static const uint32_t CPMS_CUCR_CORE_SAMPLE_ENABLED_LT = 32;
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
static const uint32_t CPMS_CUCR_QME_DATA_TYPE1_PENDING = 53;
static const uint32_t CPMS_CUCR_QME_DATA_TYPE2_PENDING = 54;
static const uint32_t CPMS_CUCR_QME_DATA_TYPE3_PENDING = 55;
static const uint32_t CPMS_CUCR_QME_TYPE0_EVENTB0_PENDING = 56;
static const uint32_t CPMS_CUCR_QME_TYPE0_EVENTB1_PENDING = 57;
static const uint32_t CPMS_CUCR_QME_TYPE0_EVENTB2_PENDING = 58;
static const uint32_t CPMS_CUCR_QME_TYPE0_EVENTB3_PENDING = 59;
static const uint32_t CPMS_CUCR_QME_TYPE0_EVENTC0_PENDING = 60;
static const uint32_t CPMS_CUCR_QME_TYPE0_EVENTC1_PENDING = 61;
static const uint32_t CPMS_CUCR_QME_TYPE0_EVENTC2_PENDING = 62;
static const uint32_t CPMS_CUCR_QME_TYPE0_EVENTC3_PENDING = 63;
//<< [CPMS_CUCR]
// c/reg00006.H

//>> [CPMS_DMSR]
static const uint64_t CPMS_DMSR = 0x200e0e64ull;

static const uint32_t CPMS_DMSR_0_COUNT = 0;
static const uint32_t CPMS_DMSR_0_COUNT_LEN = 24;
static const uint32_t CPMS_DMSR_1_COUNT = 32;
static const uint32_t CPMS_DMSR_1_COUNT_LEN = 24;
//<< [CPMS_DMSR]
// c/reg00006.H

//>> [CPMS_DPPR]
static const uint64_t CPMS_DPPR = 0x200e0ea8ull;
static const uint64_t CPMS_DPPR_WO_CLEAR = 0x200e0eabull;
static const uint64_t CPMS_DPPR_WO_OR = 0x200e0eaaull;

static const uint32_t CPMS_DPPR_PITCH_ABORT_INTERRUPT_ENABLE = 0;
static const uint32_t CPMS_DPPR_PTSR_EVENT_SELECT = 1;
static const uint32_t CPMS_DPPR_ENERGY_PROXY_RESET_MODE = 2;
static const uint32_t CPMS_DPPR_PIL_THROTTLE_ENABLE = 3;
static const uint32_t CPMS_DPPR_OCP_THROTTLE_ENABLE = 4;
static const uint32_t CPMS_DPPR_OCP_INTERRUPT_ENABLE = 5;
static const uint32_t CPMS_DPPR_OCP_ENABLE = 6;
static const uint32_t CPMS_DPPR_SPARE = 7;
static const uint32_t CPMS_DPPR_SPARE_LEN = 5;
static const uint32_t CPMS_DPPR_PP0_THRESH_SCALE = 16;
static const uint32_t CPMS_DPPR_PP0_THRESH_SCALE_LEN = 4;
static const uint32_t CPMS_DPPR_PP0_THRESH_VALUE = 20;
static const uint32_t CPMS_DPPR_PP0_THRESH_VALUE_LEN = 4;
static const uint32_t CPMS_DPPR_PP1_THRESH_SCALE = 24;
static const uint32_t CPMS_DPPR_PP1_THRESH_SCALE_LEN = 4;
static const uint32_t CPMS_DPPR_PP1_THRESH_VALUE = 28;
static const uint32_t CPMS_DPPR_PP1_THRESH_VALUE_LEN = 4;
static const uint32_t CPMS_DPPR_OCP_WAIT_FOR_GRANT = 32;
static const uint32_t CPMS_DPPR_OCP_LOCAL_MSB_MAX = 33;
static const uint32_t CPMS_DPPR_OCP_LOCAL_MSB_MAX_LEN = 2;
static const uint32_t CPMS_DPPR_OCP_LOCAL_OVERAGE = 35;
static const uint32_t CPMS_DPPR_OCP_LOCAL_OVERAGE_LEN = 5;
static const uint32_t CPMS_DPPR_OCP_LOCAL_TANK_VALUE = 40;
static const uint32_t CPMS_DPPR_OCP_LOCAL_TANK_VALUE_LEN = 10;
static const uint32_t CPMS_DPPR_OCP_PITCH_OVERRIDE = 50;
static const uint32_t CPMS_DPPR_OCP_OVERRIDE_HISTORY = 51;
//<< [CPMS_DPPR]
// c/reg00006.H

//>> [CPMS_MMA_PFETCNTL]
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
//<< [CPMS_MMA_PFETCNTL]
// c/reg00006.H

//>> [EC_PC_FIR_CORE]
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
static const uint32_t EC_PC_FIR_CORE_MU_TLB_P_ERROR = 18;
static const uint32_t EC_PC_FIR_CORE_MU_SLB_P_ERROR = 19;
static const uint32_t EC_PC_FIR_CORE_MU_CXT_P_ERROR = 21;
static const uint32_t EC_PC_FIR_CORE_MU_LOG_XSTOP_ERROR = 22;
static const uint32_t EC_PC_FIR_CORE_MU_SYS_XSTOP_ERROR = 23;
static const uint32_t EC_PC_FIR_CORE_VS_LOG_REC_ERROR = 24;
static const uint32_t EC_PC_FIR_CORE_VS_LOG_XSTOP_ERROR = 25;
static const uint32_t EC_PC_FIR_CORE_PC_RECOV_IN_MAINT_ERROR = 26;
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
static const uint32_t EC_PC_FIR_CORE_LS_SYS_XSTOP_ERROR = 41;
static const uint32_t EC_PC_FIR_CORE_PC_THREAD_HANG_REC_ERROR = 43;
static const uint32_t EC_PC_FIR_CORE_PC_LOG_XSTOP_ERROR = 45;
static const uint32_t EC_PC_FIR_CORE_PC_TFX_XSTOP_ERROR = 46;
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
//<< [EC_PC_FIR_CORE]
// c/reg00006.H

//>> [EC_PC_FIR_CORE_FIRMASK]
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
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_TLB_P_ERROR = 18;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_SLB_P_ERROR = 19;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_CXT_P_ERROR = 21;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_LOG_XSTOP_ERROR = 22;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_MU_SYS_XSTOP_ERROR = 23;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_REC_ERROR = 24;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_VS_LOG_XSTOP_ERROR = 25;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_RECOV_IN_MAINT_ERROR = 26;
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
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_LS_SYS_XSTOP_ERROR = 41;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_THREAD_HANG_REC_ERROR = 43;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_LOG_XSTOP_ERROR = 45;
static const uint32_t EC_PC_FIR_CORE_FIRMASK_MASK_PC_TFX_XSTOP_ERROR = 46;
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
//<< [EC_PC_FIR_CORE_FIRMASK]
// c/reg00006.H

//>> [EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS]
static const uint64_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS = 0x20020449ull;

static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CLEAR_MAINT = 3;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_SRESET_REQUEST = 4;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STEP = 5;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_START = 6;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_0_CORE_STOP = 7;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CLEAR_MAINT = 11;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_SRESET_REQUEST = 12;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STEP = 13;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_START = 14;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_1_CORE_STOP = 15;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CLEAR_MAINT = 19;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_SRESET_REQUEST = 20;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STEP = 21;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_START = 22;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_2_CORE_STOP = 23;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CLEAR_MAINT = 27;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_SRESET_REQUEST = 28;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STEP = 29;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_START = 30;
static const uint32_t EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS_3_CORE_STOP = 31;
//<< [EC_PC_THRCTL_TCTLCOM_DIRECT_CONTROLS]
// c/reg00006.H

//>> [L2_L2MISC_L2CERRS_FIR_MASK_REG]
static const uint64_t L2_L2MISC_L2CERRS_FIR_MASK_REG_RW = 0x20020003ull;
static const uint64_t L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_AND = 0x20020004ull;
static const uint64_t L2_L2MISC_L2CERRS_FIR_MASK_REG_WO_OR = 0x20020005ull;

static const uint32_t L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK = 0;
static const uint32_t L2_L2MISC_L2CERRS_FIR_MASK_REG_L2_FIR_MASK_LEN = 40;
//<< [L2_L2MISC_L2CERRS_FIR_MASK_REG]
// c/reg00006.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00006.H"
#endif
#endif
