/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_e.H $          */
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

#ifndef __p10_scom_c_e_H_
#define __p10_scom_c_e_H_


namespace scomt
{
namespace c
{


static const uint64_t ATOMIC_LOCK_MASK_LATCH_REG = 0x20010007ull;

static const uint32_t ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK = 0;
static const uint32_t ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN = 32;
// c/reg00014.H

static const uint64_t CPMS_ASSR = 0x200e0e18ull;

static const uint32_t CPMS_ASSR_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE = 0;
static const uint32_t CPMS_ASSR_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE = 1;
static const uint32_t CPMS_ASSR_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE = 2;
static const uint32_t CPMS_ASSR_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE = 3;
static const uint32_t CPMS_ASSR_MMA_PFETSTAT_VDD_PFETS_ENABLED_SENSE = 4;
static const uint32_t CPMS_ASSR_MMA_PFETSTAT_VDD_PFETS_DISABLED_SENSE = 5;
static const uint32_t CPMS_ASSR_RVCSR_RVID_ACTIVE = 6;
static const uint32_t CPMS_ASSR_RVCSR_BYPASS_ACTIVE = 7;
static const uint32_t CPMS_ASSR_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET = 8;
static const uint32_t CPMS_ASSR_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE = 12;
static const uint32_t CPMS_ASSR_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE = 13;
static const uint32_t CPMS_ASSR_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE = 14;
static const uint32_t CPMS_ASSR_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE = 15;
static const uint32_t CPMS_ASSR_CGCSR_L3_CLKGLM_SEL = 16;
static const uint32_t CPMS_ASSR_CGCSR_CL2_CLKGLM_SEL = 17;
static const uint32_t CPMS_ASSR_CGCSR_L3_CLK_SYNC_DONE = 18;
static const uint32_t CPMS_ASSR_CGCSR_CL2_CLK_SYNC_DONE = 19;
// c/reg00014.H

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
static const uint32_t CPMS_DESR_SPARE_COUNT_SEL_LEN = 3;
static const uint32_t CPMS_DESR_SECONDARY_EVENT_SEL = 44;
static const uint32_t CPMS_DESR_SECONDARY_EVENT_SEL_LEN = 2;
// c/reg00014.H

static const uint64_t CPMS_DTTR = 0x200e0e88ull;

static const uint32_t CPMS_DTTR_RATE_LIMIT = 0;
static const uint32_t CPMS_DTTR_RATE_LIMIT_LEN = 8;
static const uint32_t CPMS_DTTR_INFLIGHT_LIMIT = 32;
static const uint32_t CPMS_DTTR_INFLIGHT_LIMIT_LEN = 8;
// c/reg00014.H

static const uint64_t EC_LS_LSU_HOLD_OUT_REG4 = 0x200206c4ull;
// c/reg00014.H

static const uint64_t EC_PC_PMC_CORE_THREAD_STATE = 0x20020412ull;
// c/reg00014.H

static const uint64_t EC_PC_PMU_SPRCOR_OCC_SCOMD = 0x20020411ull;
// c/reg00014.H

static const uint64_t EC_PC_SCR6 = 0x2002048cull;
// c/reg00014.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_4 = 0x20020a87ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_4_A = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_4_B = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_4_B_LEN = 24;
// c/reg00014.H

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
// c/reg00014.H

static const uint64_t L2TRA_TR0_CONFIG_9 = 0x20020049ull;

static const uint32_t L2TRA_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L2TRA_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L2TRA_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L2TRA_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L2TRA_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L2TRA_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L2TRA_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00014.H

static const uint64_t L2TRA_TR1_CONFIG_0 = 0x20020083ull;

static const uint32_t L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L2TRA_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00014.H

static const uint64_t L3_MISC_L3CERRS_FIR_ACTION0_REG = 0x20010606ull;

static const uint32_t L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0 = 0;
static const uint32_t L3_MISC_L3CERRS_FIR_ACTION0_REG_FIR_ACTION0_LEN = 33;
// c/reg00014.H

static const uint64_t L3_MISC_L3CERRS_FIR_ACTION1_REG = 0x20010607ull;

static const uint32_t L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1 = 0;
static const uint32_t L3_MISC_L3CERRS_FIR_ACTION1_REG_FIR_ACTION1_LEN = 33;
// c/reg00014.H

static const uint64_t L3_MISC_L3CERRS_FIR_MASK_REG_RW = 0x20010603ull;
static const uint64_t L3_MISC_L3CERRS_FIR_MASK_REG_WO_AND = 0x20010604ull;
static const uint64_t L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR = 0x20010605ull;
// c/reg00014.H

static const uint64_t L3_MISC_L3CERRS_PM_LCO_DIS_REG = 0x20010616ull;

static const uint32_t L3_MISC_L3CERRS_PM_LCO_DIS_REG_L3_PM_LCO_DIS_CFG = 0;
// c/reg00014.H

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
static const uint32_t QME_CISR_REG_WKUP_PRESENT = 62;
static const uint32_t QME_CISR_REG_WKUP_REQUESTED = 63;
// c/reg00014.H

}
}
#ifndef __PPE_HCODE__
    #include "c/reg00014.H"
#endif
#endif
