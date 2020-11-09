/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_e.H $          */
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

#ifndef __p10_scom_c_e_H_
#define __p10_scom_c_e_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> [CPMS_ASSR]
static const uint64_t CPMS_ASSR = 0x200e0e18ull;

static const uint32_t CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE = 0;
static const uint32_t CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE = 1;
static const uint32_t CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE = 2;
static const uint32_t CPMS_ASSR_CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE = 3;
static const uint32_t CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE = 4;
static const uint32_t CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE = 5;
static const uint32_t CPMS_ASSR_CPMS_RVCSR_RVID_ACTIVE = 6;
static const uint32_t CPMS_ASSR_CPMS_RVCSR_BYPASS_ACTIVE = 7;
static const uint32_t P10_20_CPMS_ASSR_CPMS_RVCSR_BYPASS_RAW = 7; // p10:20,
static const uint32_t CPMS_ASSR_CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET = 8;
static const uint32_t CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE = 12;
static const uint32_t CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE = 13;
static const uint32_t CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE = 14;
static const uint32_t CPMS_ASSR_CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE = 15;
static const uint32_t CPMS_ASSR_L3_CLKGLM_SEL = 16;
static const uint32_t CPMS_ASSR_L2_CLKGLM_SEL = 17;
static const uint32_t CPMS_ASSR_CPMS_CGCSR_L3_CLK_SYNC_DONE = 18;
static const uint32_t CPMS_ASSR_CPMS_CGCSR_CL2_CLK_SYNC_DONE = 19;
static const uint32_t P10_20_CPMS_ASSR_CPMS_L3_PFETSTAT_VDD_PFETS_FINGER0_SENSE = 20; // p10:20,
static const uint32_t P10_20_CPMS_ASSR_CPMS_L3_PFETSTAT_VCS_PFETS_FINGER0_SENSE = 21; // p10:20,
static const uint32_t P10_20_CPMS_ASSR_CPMS_CL2_PFETSTAT_L2_VDD_PFETS_FINGER0_SENSE = 22; // p10:20,
static const uint32_t P10_20_CPMS_ASSR_CPMS_CL2_PFETSTAT_L2_VCS_PFETS_FINGER0_SENSE = 23; // p10:20,
static const uint32_t P10_20_CPMS_ASSR_CPMS_MMA_PFETSTAT_VDD_PFETS_FINGER0_SENSE = 24; // p10:20,
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_AVG = 27;
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_AVG_LEN = 5;
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_SENSE0 = 32;
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_SENSE0_LEN = 5;
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_SENSE1 = 37;
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_SENSE1_LEN = 5;
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_SENSE2 = 42;
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_SENSE2_LEN = 5;
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_SENSE3 = 47;
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_SENSE3_LEN = 5;
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX = 52;
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MAX_LEN = 5;
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN = 57;
static const uint32_t CPMS_ASSR_CL2_VDD_CURRENT_SENSE_MIN_LEN = 5;
//<< [CPMS_ASSR]
// c/reg00014.H

//>> [CPMS_DESR]
static const uint64_t CPMS_DESR = 0x200e0e5cull;

static const uint32_t CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL = 0;
static const uint32_t CPMS_DESR_COUNTA_FTC_ACTIVITY_SEL_LEN = 3;
static const uint32_t CPMS_DESR_COUNTA_FTC_EVENT_SEL = 3;
static const uint32_t CPMS_DESR_COUNTA_FTC_EVENT_SEL_LEN = 3;
static const uint32_t CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL = 6;
static const uint32_t CPMS_DESR_COUNTB_FTC_ACTIVITY_SEL_LEN = 3;
static const uint32_t CPMS_DESR_COUNTB_FTC_EVENT_SEL = 9;
static const uint32_t CPMS_DESR_COUNTB_FTC_EVENT_SEL_LEN = 3;
static const uint32_t CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL = 12;
static const uint32_t CPMS_DESR_COUNTC_FTC_ACTIVITY_SEL_LEN = 3;
static const uint32_t CPMS_DESR_COUNTC_FTC_EVENT_SEL = 15;
static const uint32_t CPMS_DESR_COUNTC_FTC_EVENT_SEL_LEN = 3;
static const uint32_t CPMS_DESR_COUNTA_FTC_STATE_SELECT = 18;
static const uint32_t CPMS_DESR_COUNTA_FTC_STATE_SELECT_LEN = 3;
static const uint32_t CPMS_DESR_COUNTB_FTC_STATE_SELECT = 21;
static const uint32_t CPMS_DESR_COUNTB_FTC_STATE_SELECT_LEN = 3;
static const uint32_t CPMS_DESR_COUNTC_FTC_STATE_SELECT = 24;
static const uint32_t CPMS_DESR_COUNTC_FTC_STATE_SELECT_LEN = 3;
static const uint32_t CPMS_DESR_FTC_INVERT_SEL = 27;
static const uint32_t CPMS_DESR_FTC_INVERT_SEL_LEN = 3;
static const uint32_t CPMS_DESR_FTC_SPARE = 30;
static const uint32_t CPMS_DESR_FTC_SPARE_LEN = 2;
static const uint32_t CPMS_DESR_FTC_EVENT_INVERT = 32;
static const uint32_t CPMS_DESR_FTC_EVENT_INVERT_LEN = 3;
static const uint32_t CPMS_DESR_STATEW_ENABLE = 35;
static const uint32_t CPMS_DESR_STATEW_ENABLE_LEN = 3;
static const uint32_t CPMS_DESR_STATEZ_ENABLE = 38;
static const uint32_t CPMS_DESR_STATEZ_ENABLE_LEN = 3;
static const uint32_t CPMS_DESR_SPARE_COUNT_SEL = 41;
static const uint32_t CPMS_DESR_SECONDARY_QUAL_SEL = 42;
static const uint32_t CPMS_DESR_SECONDARY_QUAL_SEL_LEN = 2;
static const uint32_t CPMS_DESR_SECONDARY_EVENT_SEL = 44;
static const uint32_t CPMS_DESR_SECONDARY_EVENT_SEL_LEN = 2;
//<< [CPMS_DESR]
// c/reg00014.H

//>> [CPMS_DTTR]
static const uint64_t CPMS_DTTR = 0x200e0e88ull;

static const uint32_t CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT = 0;
static const uint32_t CPMS_DTTR_CPMS_DTCR_CORE_DPT_RATE_LIMIT_LEN = 8;
static const uint32_t CPMS_DTTR_T1_DPT_RATE_LIMIT = 8;
static const uint32_t CPMS_DTTR_T1_DPT_RATE_LIMIT_LEN = 8;
static const uint32_t CPMS_DTTR_T2_DPT_RATE_LIMIT = 16;
static const uint32_t CPMS_DTTR_T2_DPT_RATE_LIMIT_LEN = 8;
static const uint32_t CPMS_DTTR_T3_DPT_RATE_LIMIT = 24;
static const uint32_t CPMS_DTTR_T3_DPT_RATE_LIMIT_LEN = 8;
static const uint32_t CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT = 32;
static const uint32_t CPMS_DTTR_CPMS_DTCR_CORE_DPT_INFLIGHT_LIMIT_LEN = 8;
static const uint32_t CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT = 40;
static const uint32_t CPMS_DTTR_T1_DPT_INFLIGHT_LIMIT_LEN = 8;
static const uint32_t CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT = 48;
static const uint32_t CPMS_DTTR_T2_DPT_INFLIGHT_LIMIT_LEN = 8;
static const uint32_t CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT = 56;
static const uint32_t CPMS_DTTR_T3_DPT_INFLIGHT_LIMIT_LEN = 8;
//<< [CPMS_DTTR]
// c/reg00014.H

//>> [L2_L2MISC_L2CERRS_TOPOTABLE1]
static const uint64_t L2_L2MISC_L2CERRS_TOPOTABLE1 = 0x20020015ull;

static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_08_VAL = 0;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_09_VAL = 1;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_10_VAL = 2;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_11_VAL = 3;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_12_VAL = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_13_VAL = 5;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_14_VAL = 6;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_15_VAL = 7;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_08 = 8;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_08_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_09 = 12;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_09_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_10 = 16;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_10_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_11 = 20;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_11_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_12 = 24;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_12_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_13 = 28;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_13_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_14 = 32;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_14_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_15 = 36;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE1_15_LEN = 4;
//<< [L2_L2MISC_L2CERRS_TOPOTABLE1]
// c/reg00014.H

//>> [L3_MISC_L3CERRS_FIR_MASK_REG]
static const uint64_t L3_MISC_L3CERRS_FIR_MASK_REG_RW = 0x20010603ull;
static const uint64_t L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND = 0x20010604ull;
static const uint64_t L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR = 0x20010605ull;

static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR_MASK = 0;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_CHIP_CONTAINED_ERR_MASK = 1;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_TOPO_TABLE_ERR_MASK = 2;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_DRAM_POS_WORDLINE_FAIL_MASK = 3;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_CE_DET_NOT_LINDEL_REQ_MASK = 4;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_UE_DET_MASK = 5;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_RD_DF_SUE_DET_MASK = 6;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_PB_MASK = 7;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_PB_MASK = 8;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_PB_MASK = 9;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_CE_FROM_L2_OR_WIHPC_MASK = 10;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_UE_FROM_L2_OR_WIHPC_MASK = 11;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_WR_DF_SUE_FROM_L2_OR_WIHPC_MASK = 12;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_CE_DET_MASK = 13;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_UE_DET_MASK = 14;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_DIR_RD_PHANTOM_ERROR_MASK = 15;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ADDR_ERR_MASK = 16;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ADDR_ERR_MASK = 17;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_PB_HANG_POLL_MASK = 18;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_LRU_INVAL_CNT_MASK = 19;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE20_MASK = 20;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE21_MASK = 21;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_FIR_SPARE22_MASK = 22;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_MACH_HANG_DETECTED_MASK = 23;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_HW_CONTROL_ERR_MASK = 24;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_SNP_CACHE_INHIBIT_ERR_MASK = 25;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_LINE_DEL_CE_DONE_MASK = 26;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_NOT_PROX_MASK = 27;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_LRU_VIC_SEL_ERROR_MASK = 28;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_ALL_MEMBERS_DELETED_ERROR_MASK = 29;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_LCO_IN_CHIPLET_ID_MISMATCH_MASK = 30;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_WR_ACK_DEAD_MASK = 31;
static const uint32_t L3_MISC_L3CERRS_FIR_MASK_REG_PB_MAST_RD_ACK_DEAD_MASK = 32;
//<< [L3_MISC_L3CERRS_FIR_MASK_REG]
// c/reg00014.H

//>> [L3_MISC_L3CERRS_PM_LCO_DIS_REG]
static const uint64_t L3_MISC_L3CERRS_PM_LCO_DIS_REG = 0x20010616ull;

static const uint32_t L3_MISC_L3CERRS_PM_LCO_DIS_REG_LCO_DIS_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_PM_LCO_DIS_REG_RCMD_DIS_CFG = 1;
//<< [L3_MISC_L3CERRS_PM_LCO_DIS_REG]
// c/reg00014.H

//>> [QME_CISR]
static const uint64_t QME_CISR = 0x200e0878ull;

static const uint32_t QME_CISR_HYP_INTR_PRESENT = 0;
static const uint32_t QME_CISR_HYP_INTR_PRESENT_LEN = 4;
static const uint32_t QME_CISR_OS_INTR_PRESENT = 4;
static const uint32_t QME_CISR_OS_INTR_PRESENT_LEN = 4;
static const uint32_t QME_CISR_MSGSND_INTR_PRESENT = 8;
static const uint32_t QME_CISR_MSGSND_INTR_PRESENT_LEN = 4;
static const uint32_t QME_CISR_EBB_INTR_PRESENT = 12;
static const uint32_t QME_CISR_EBB_INTR_PRESENT_LEN = 4;
static const uint32_t QME_CISR_HYP_INTR_REQUESTED = 16;
static const uint32_t QME_CISR_HYP_INTR_REQUESTED_LEN = 4;
static const uint32_t QME_CISR_OS_INTR_REQUESTED = 20;
static const uint32_t QME_CISR_OS_INTR_REQUESTED_LEN = 4;
static const uint32_t QME_CISR_MSGSND_INTR_REQUESTED = 24;
static const uint32_t QME_CISR_MSGSND_INTR_REQUESTED_LEN = 4;
static const uint32_t QME_CISR_MSGSND_INTR_SAMPLE = 28;
static const uint32_t QME_CISR_MSGSND_INTR_SAMPLE_LEN = 4;
static const uint32_t QME_CISR_MSGSND_ACK = 32;
static const uint32_t QME_CISR_MALF_ALERT_PRESENT = 33;
static const uint32_t QME_CISR_MALF_ALERT_REQUESTED = 34;
static const uint32_t QME_CISR_MSGSNDU_INTR_PRESENT = 36;
static const uint32_t QME_CISR_MSGSNDU_INTR_PRESENT_LEN = 4;
static const uint32_t QME_CISR_MSGSNDU_INTR_REQUESTED = 40;
static const uint32_t QME_CISR_MSGSNDU_INTR_REQUESTED_LEN = 4;
static const uint32_t QME_CISR_MSGSNDU_INTR_SAMPLE = 44;
static const uint32_t QME_CISR_MSGSNDU_INTR_SAMPLE_LEN = 4;
static const uint32_t QME_CISR_TFCS_DEC_PRESENT = 48;
static const uint32_t QME_CISR_TFCS_DEC_PRESENT_LEN = 4;
static const uint32_t QME_CISR_TFCS_DEC_REQUESTED = 52;
static const uint32_t QME_CISR_TFCS_DEC_REQUESTED_LEN = 4;
static const uint32_t QME_CISR_TFCS_HDEC_PRESENT = 56;
static const uint32_t QME_CISR_TFCS_HDEC_REQUESTED = 57;
static const uint32_t QME_CISR_DPDES_INTR_PRESENT = 58;
static const uint32_t QME_CISR_DPDES_INTR_REQUESTED = 59;
static const uint32_t QME_CISR_PC_INTR_PENDING = 60;
static const uint32_t QME_CISR_PC_INTR_REQUESTED = 61;
static const uint32_t QME_CISR_REG_WKUP_PRESENT = 62;
static const uint32_t QME_CISR_REG_WKUP_REQUESTED = 63;
//<< [QME_CISR]
// c/reg00014.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00014.H"
#endif
#endif
