/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_0.H $          */
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

#ifndef __p10_scom_c_0_H_
#define __p10_scom_c_0_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


static const uint64_t CPMS_L3_PFETCNTL = 0x200e0e20ull;
static const uint64_t CPMS_L3_PFETCNTL_WO_CLEAR = 0x200e0e23ull;
static const uint64_t CPMS_L3_PFETCNTL_WO_OR = 0x200e0e22ull;

static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE = 0;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_SEQ_STATE_LEN = 2;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE = 2;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_SEQ_STATE_LEN = 2;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_VAL_OVERRIDE = 4;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_SEL_OVERRIDE = 5;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_VAL_OVERRIDE = 6;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_SEL_OVERRIDE = 7;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE = 12;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN = 8;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE = 20;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PFET_SEL_VALUE_LEN = 4;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE = 24;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN = 8;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE = 32;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PFET_SEL_VALUE_LEN = 4;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PG_STATE = 42;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PG_STATE_LEN = 4;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PG_SEL = 46;
static const uint32_t CPMS_L3_PFETCNTL_VDD_PG_SEL_LEN = 4;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PG_STATE = 50;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PG_STATE_LEN = 4;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PG_SEL = 54;
static const uint32_t CPMS_L3_PFETCNTL_VCS_PG_SEL_LEN = 4;
static const uint32_t CPMS_L3_PFETCNTL_SRAM_ENABLE = 63;
// c/reg00000.H

static const uint64_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2 = 0x20020602ull;

static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_32 = 0;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_33 = 1;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_34 = 2;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_35 = 3;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_36 = 4;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_37 = 5;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_38 = 6;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_39 = 7;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_40 = 8;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_41 = 9;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_42 = 10;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_43 = 11;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_44 = 12;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_45 = 13;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT2_46 = 14;
// c/reg00000.H

static const uint64_t EC_PC_COMMON_SPR_HMEER = 0x20020496ull;

static const uint32_t EC_PC_COMMON_SPR_HMEER_ENABLE = 0;
static const uint32_t EC_PC_COMMON_SPR_HMEER_ENABLE_LEN = 24;
// c/reg00000.H

static const uint64_t EC_PC_PMU_SPRCOR_INV_ERATE = 0x2002040full;
// c/reg00000.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG_5 = 0x20020a48ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_5_C = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_5_D = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_5_D_LEN = 24;
// c/reg00000.H

static const uint64_t L2TRA_TR0_CONFIG_3 = 0x20020046ull;

static const uint32_t L2TRA_TR0_CONFIG_3_C = 0;
static const uint32_t L2TRA_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t L2TRA_TR0_CONFIG_3_D = 24;
static const uint32_t L2TRA_TR0_CONFIG_3_D_LEN = 24;
// c/reg00000.H

static const uint64_t L3_MISC_L3CERRS_PM_PURGE_REG = 0x20010613ull;

static const uint32_t L3_MISC_L3CERRS_PM_PURGE_REG_REQ = 0;
static const uint32_t L3_MISC_L3CERRS_PM_PURGE_REG_BUSY_ERR = 1;
static const uint32_t L3_MISC_L3CERRS_PM_PURGE_REG_ABORT = 2;
// c/reg00000.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_CSEL = 0x20010687ull;
// c/reg00000.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3 = 0x2001064cull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_EN = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_THRESHOLD = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_THRESHOLD_LEN = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_CMPLT_CNT = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_CMPLT_CNT_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_DELAY_CNT = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_STALL_DELAY_CNT_LEN = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_PACING_MST_DLY_EN = 16;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_PACING_PMU_THRESH = 17;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_PACING_PMU_THRESH_LEN = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_SMF_ENABLE = 20;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_TLBIE_OVERLAP_OP2_EN = 21;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_SPARE = 22;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG3_SPARE_LEN = 10;
// c/reg00000.H

static const uint64_t QME_SPWU_OTR = 0x200e0830ull;

static const uint32_t QME_SPWU_OTR_REQ = 0;
static const uint32_t QME_SPWU_OTR_DONE = 4;
// c/reg00000.H

static const uint64_t QME_SSH_OTR = 0x200e0820ull;

static const uint32_t QME_SSH_OTR_STOP_GATED = 0;
static const uint32_t QME_SSH_OTR_SPECIAL_WKUP_DONE = 1;
static const uint32_t QME_SSH_OTR_STOP_TRANSITION = 2;
static const uint32_t QME_SSH_OTR_STOP_TRANSITION_LEN = 2;
static const uint32_t QME_SSH_OTR_REQ_STOP_LEVEL = 4;
static const uint32_t QME_SSH_OTR_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OTR_ACT_STOP_LEVEL = 8;
static const uint32_t QME_SSH_OTR_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL = 12;
static const uint32_t QME_SSH_OTR_DEEPEST_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL = 16;
static const uint32_t QME_SSH_OTR_DEEPEST_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_OTR_SPECIAL_WKUP_OCCURRED = 20;
static const uint32_t QME_SSH_OTR_SPECIAL_WKUP_ENTERED = 21;
static const uint32_t QME_SSH_OTR_STOP_STATE_EXITED = 22;
static const uint32_t QME_SSH_OTR_STOP_STATE_ENTERED = 23;
static const uint32_t QME_SSH_OTR_DEEPEST_STOP_ENTRY = 24;
static const uint32_t QME_SSH_OTR_DEEPEST_STOP_ENTRY_LEN = 4;
// c/reg00000.H

static const uint64_t QME_SSH_SRC = 0x200e081cull;

static const uint32_t QME_SSH_SRC_STOP_GATED = 0;
static const uint32_t QME_SSH_SRC_SPECIAL_WKUP_DONE = 1;
static const uint32_t QME_SSH_SRC_STOP_TRANSITION = 2;
static const uint32_t QME_SSH_SRC_STOP_TRANSITION_LEN = 2;
static const uint32_t QME_SSH_SRC_REQ_STOP_LEVEL = 4;
static const uint32_t QME_SSH_SRC_REQ_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_SRC_ACT_STOP_LEVEL = 8;
static const uint32_t QME_SSH_SRC_ACT_STOP_LEVEL_LEN = 4;
static const uint32_t QME_SSH_SRC_REQ_WRITE_ENABLE = 12;
static const uint32_t QME_SSH_SRC_ACT_WRITE_ENABLE = 13;
static const uint32_t QME_SSH_SRC_SELF_SAVE_ACTIVE = 30;
static const uint32_t QME_SSH_SRC_SELF_RESTORE_ACTIVE = 31;
static const uint32_t QME_SSH_SRC_SAMPLED_STOP_ACTIVE = 39;
static const uint32_t QME_SSH_SRC_SAMPLED_STOP_STATE = 40;
static const uint32_t QME_SSH_SRC_SAMPLED_STOP_STATE_LEN = 4;
static const uint32_t QME_SSH_SRC_SPECIAL_WKUP_PRESENT = 48;
static const uint32_t QME_SSH_SRC_SPECIAL_WKUP_PRESENT_LEN = 4;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_SET = 56;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_SET_LEN = 2;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_CLR = 58;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_CLR_LEN = 2;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_ACT = 60;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_ACT_LEN = 2;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_DRP = 62;
static const uint32_t QME_SSH_SRC_SPC_WKUP_RECENT_DRP_LEN = 2;
// c/reg00000.H

#ifndef __PPE_HCODE__
}
}
#include "c/reg00000.H"
#endif
#endif
