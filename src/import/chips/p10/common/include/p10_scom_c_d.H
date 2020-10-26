/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_d.H $          */
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

#ifndef __p10_scom_c_d_H_
#define __p10_scom_c_d_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> [CPMS_MMA_PFETSTAT]
static const uint64_t CPMS_MMA_PFETSTAT = 0x200e0e34ull;

static const uint32_t CPMS_MMA_PFETSTAT_S_ENABLED_SENSE = 0;
static const uint32_t CPMS_MMA_PFETSTAT_S_DISABLED_SENSE = 1;
static const uint32_t CPMS_MMA_PFETSTAT_ENABLE_ACTUAL = 16;
static const uint32_t CPMS_MMA_PFETSTAT_ENABLE_ACTUAL_LEN = 8;
//<< [CPMS_MMA_PFETSTAT]
// c/reg00013.H

//>> [CPMS_PFETDLY]
static const uint64_t CPMS_PFETDLY = 0x200e0e1cull;

static const uint32_t CPMS_PFETDLY_POWDN_DLY = 0;
static const uint32_t CPMS_PFETDLY_POWDN_DLY_LEN = 4;
static const uint32_t CPMS_PFETDLY_L3_POWUP_DLY = 4;
static const uint32_t CPMS_PFETDLY_L3_POWUP_DLY_LEN = 4;
static const uint32_t CPMS_PFETDLY_CL2_POWUP_DLY = 8;
static const uint32_t CPMS_PFETDLY_CL2_POWUP_DLY_LEN = 4;
static const uint32_t CPMS_PFETDLY_MMA_POWUP_DLY = 12;
static const uint32_t CPMS_PFETDLY_MMA_POWUP_DLY_LEN = 4;
//<< [CPMS_PFETDLY]
// c/reg00013.H

//>> [EC_PC_COMMON_SPR_MODE]
static const uint64_t EC_PC_COMMON_SPR_MODE = 0x20020484ull;

static const uint32_t EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ = 10;
static const uint32_t EC_PC_COMMON_SPR_MODE_TFAC_ERR_INJ_LEN = 6;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT0_SEL = 20;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT1_SEL = 21;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT2_SEL = 22;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT3_SEL = 23;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT4_SEL = 24;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT5_SEL = 25;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT6_SEL = 26;
static const uint32_t EC_PC_COMMON_SPR_MODE_SPRC_LT7_SEL = 27;
//<< [EC_PC_COMMON_SPR_MODE]
// c/reg00013.H

//>> [EC_PC_PMC_THREAD_INFO]
static const uint64_t EC_PC_PMC_THREAD_INFO = 0x20020413ull;

static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_V = 0;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_V = 1;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_V = 2;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_V = 3;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID0_V = 4;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID1_V = 5;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID2_V = 6;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_PTID3_V = 7;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE = 8;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_SMT_MODE_LEN = 2;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP = 10;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID0_TO_PTID_MAP_LEN = 2;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP = 12;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID1_TO_PTID_MAP_LEN = 2;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP = 14;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID2_TO_PTID_MAP_LEN = 2;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP = 16;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_INFO_VTID3_TO_PTID_MAP_LEN = 2;
static const uint32_t EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE = 18;
static const uint32_t EC_PC_PMC_THREAD_INFO_RAM_THREAD_ACTIVE_LEN = 4;
static const uint32_t EC_PC_PMC_THREAD_INFO_PSCOM_PURGE = 22;
static const uint32_t EC_PC_PMC_THREAD_INFO_THREAD_ACTION_IN_PROGRESS = 23;
static const uint32_t EC_PC_PMC_THREAD_INFO_FTC_CORE_UCODE_REQUEST = 24;
static const uint32_t EC_PC_PMC_THREAD_INFO_FTC_RECOVERY_REQUEST = 25;
//<< [EC_PC_PMC_THREAD_INFO]
// c/reg00013.H

//>> [NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0]
static const uint64_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0 = 0x20010654ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_VAL = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_VAL = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_VAL = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_VAL = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_VAL = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_VAL = 5;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_VAL = 6;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_VAL = 7;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0 = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_0_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1 = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_1_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2 = 16;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_2_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3 = 20;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_3_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4 = 24;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_4_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5 = 28;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_5_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6 = 32;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_6_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7 = 36;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0_7_LEN = 4;
//<< [NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0]
// c/reg00013.H

//>> [QME_PSCRS0]
static const uint64_t QME_PSCRS0 = 0x200e0850ull;

static const uint32_t QME_PSCRS0_DPDES_EXIT_ENABLE = 0;
static const uint32_t QME_PSCRS0_SD = 1;
static const uint32_t QME_PSCRS0_ESL = 2;
static const uint32_t QME_PSCRS0_EC = 3;
static const uint32_t QME_PSCRS0_PSLL = 4;
static const uint32_t QME_PSCRS0_PSLL_LEN = 4;
static const uint32_t QME_PSCRS0_HYP_VIRT_EXIT_ENABLE = 8;
static const uint32_t QME_PSCRS0_UV_DB_EXIT_ENABLE = 9;
static const uint32_t QME_PSCRS0_HYP_DB_EXIT_ENABLE = 10;
static const uint32_t QME_PSCRS0_EXT_EXIT_ENABLE = 11;
static const uint32_t QME_PSCRS0_DEC_EXIT_ENABLE = 12;
static const uint32_t QME_PSCRS0_HMI_EXIT_ENABLE = 13;
static const uint32_t QME_PSCRS0_TR = 14;
static const uint32_t QME_PSCRS0_TR_LEN = 2;
static const uint32_t QME_PSCRS0_MTL = 16;
static const uint32_t QME_PSCRS0_MTL_LEN = 4;
static const uint32_t QME_PSCRS0_RL = 20;
static const uint32_t QME_PSCRS0_RL_LEN = 4;
static const uint32_t QME_PSCRS0_PLS = 24;
static const uint32_t QME_PSCRS0_PLS_LEN = 4;
//<< [QME_PSCRS0]
// c/reg00013.H

//>> [EC_PC_TOD_READ]
static const uint64_t EC_PC_TOD_READ = 0x200204a3ull;

static const uint32_t EC_PC_TOD_READ_TOD = 0;
static const uint32_t EC_PC_TOD_READ_TOD_LEN = 60;
//<< [EC_PC_TOD_READ]
// c/reg00013.H

//>> [CPMS_DCCR]
static const uint64_t CPMS_DCCR = 0x200e0e60ull;

static const uint32_t CPMS_DCCR_LARGE_OFFSET = 0;
static const uint32_t CPMS_DCCR_LARGE_OFFSET_LEN = 4;
static const uint32_t CPMS_DCCR_0_THRESH_SCALE = 4;
static const uint32_t CPMS_DCCR_0_THRESH_SCALE_LEN = 4;
static const uint32_t CPMS_DCCR_0_THRESH_VALUE = 8;
static const uint32_t CPMS_DCCR_0_THRESH_VALUE_LEN = 8;
static const uint32_t CPMS_DCCR_1_THRESH_SCALE = 16;
static const uint32_t CPMS_DCCR_1_THRESH_SCALE_LEN = 4;
static const uint32_t CPMS_DCCR_1_THRESH_VALUE = 20;
static const uint32_t CPMS_DCCR_1_THRESH_VALUE_LEN = 8;
static const uint32_t CPMS_DCCR_0_EVENT_SEL = 28;
static const uint32_t CPMS_DCCR_0_EVENT_SEL_LEN = 3;
static const uint32_t CPMS_DCCR_1_EVENT_SEL = 31;
static const uint32_t CPMS_DCCR_1_EVENT_SEL_LEN = 3;
//<< [CPMS_DCCR]
// c/reg00013.H

//>> [CPMS_PPSR]
static const uint64_t CPMS_PPSR = 0x200e0e98ull;

static const uint32_t CPMS_PPSR_ENERGY_PROXY_UPPER = 0;
static const uint32_t CPMS_PPSR_ENERGY_PROXY_UPPER_LEN = 32;
static const uint32_t CPMS_PPSR_ENERGY_PROXY_LOWER = 32;
static const uint32_t CPMS_PPSR_ENERGY_PROXY_LOWER_LEN = 8;
static const uint32_t CPMS_PPSR_PERIOD_PROXY_REMAIN = 40;
static const uint32_t CPMS_PPSR_PERIOD_PROXY_REMAIN_LEN = 20;
static const uint32_t CPMS_PPSR_FTX_SATURATED = 60;
static const uint32_t CPMS_PPSR_PITCH_SATURATED = 61;
static const uint32_t CPMS_PPSR_PITCH_ABORTED = 62;
static const uint32_t CPMS_PPSR_PITCH_ACTIVE = 63;
//<< [CPMS_PPSR]
// c/reg00013.H

//>> [EC_PC_FIR_CORE_ACTION1]
static const uint64_t EC_PC_FIR_CORE_ACTION1 = 0x20020447ull;

static const uint32_t EC_PC_FIR_CORE_ACTION1_IF_SRAM_REC_ERROR = 0;
static const uint32_t EC_PC_FIR_CORE_ACTION1_TC_FIR_XSTOP_ERROR = 1;
static const uint32_t EC_PC_FIR_CORE_ACTION1_IF_RFILE_REC_ERROR = 2;
static const uint32_t EC_PC_FIR_CORE_ACTION1_IF_RFILE_XSTOP_ERROR = 3;
static const uint32_t EC_PC_FIR_CORE_ACTION1_IF_LOG_REC_ERROR = 4;
static const uint32_t EC_PC_FIR_CORE_ACTION1_IF_LOG_XSTOP_ERROR = 5;
static const uint32_t EC_PC_FIR_CORE_ACTION1_UNUSED_6 = 6;
static const uint32_t EC_PC_FIR_CORE_ACTION1_VS_VSMM_ACC_ERROR = 7;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_RECOV_XSTOP_ERROR = 8;
static const uint32_t EC_PC_FIR_CORE_ACTION1_VS_STF_ERROR = 9;
static const uint32_t EC_PC_FIR_CORE_ACTION1_UNUSED_10 = 10;
static const uint32_t EC_PC_FIR_CORE_ACTION1_SD_LOG_REC_ERROR = 11;
static const uint32_t EC_PC_FIR_CORE_ACTION1_SD_LOG_XSTOP_ERROR = 12;
static const uint32_t EC_PC_FIR_CORE_ACTION1_SD_NOT_MT_CI_REC_ERROR = 13;
static const uint32_t EC_PC_FIR_CORE_ACTION1_SD_MCHK_AND_ME_EQ_0_ERROR = 14;
static const uint32_t EC_PC_FIR_CORE_ACTION1_SD_L2_UE_ERROR = 15;
static const uint32_t EC_PC_FIR_CORE_ACTION1_SD_L2_UE_OVER_THRES_ERROR = 16;
static const uint32_t EC_PC_FIR_CORE_ACTION1_SD_L2_CI_UE_ERROR = 17;
static const uint32_t EC_PC_FIR_CORE_ACTION1_MU_TLB_P_ERROR = 18;
static const uint32_t EC_PC_FIR_CORE_ACTION1_MU_SLB_P_ERROR = 19;
static const uint32_t EC_PC_FIR_CORE_ACTION1_UNUSED_20 = 20;
static const uint32_t EC_PC_FIR_CORE_ACTION1_MU_CXT_P_ERROR = 21;
static const uint32_t EC_PC_FIR_CORE_ACTION1_MU_LOG_XSTOP_ERROR = 22;
static const uint32_t EC_PC_FIR_CORE_ACTION1_MU_SYS_XSTOP_ERROR = 23;
static const uint32_t EC_PC_FIR_CORE_ACTION1_VS_LOG_REC_ERROR = 24;
static const uint32_t EC_PC_FIR_CORE_ACTION1_VS_LOG_XSTOP_ERROR = 25;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_RECOV_IN_MAINT_ERROR = 26;
static const uint32_t EC_PC_FIR_CORE_ACTION1_UNUSED_27 = 27;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_SYS_XSTOP_ERROR = 28;
static const uint32_t EC_PC_FIR_CORE_ACTION1_LS_SRAM_PARITY_ERROR = 29;
static const uint32_t EC_PC_FIR_CORE_ACTION1_LS_SETDELETE_ERROR = 30;
static const uint32_t EC_PC_FIR_CORE_ACTION1_LS_RFILE_REC_ERROR = 31;
static const uint32_t EC_PC_FIR_CORE_ACTION1_LS_RFILE_XSTOP_ERROR = 32;
static const uint32_t EC_PC_FIR_CORE_ACTION1_MU_TLB_MULTIHIT_ERROR = 33;
static const uint32_t EC_PC_FIR_CORE_ACTION1_MU_SLB_MULTIHIT_ERROR = 34;
static const uint32_t EC_PC_FIR_CORE_ACTION1_LS_DERAT_MULTIHIT_ERROR = 35;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_FWD_PROGRESS_ERROR = 36;
static const uint32_t EC_PC_FIR_CORE_ACTION1_LS_LOG_REC_ERROR = 37;
static const uint32_t EC_PC_FIR_CORE_ACTION1_LS_LOG_XSTOP_ERROR = 38;
static const uint32_t EC_PC_FIR_CORE_ACTION1_UNUSED_39 = 39;
static const uint32_t EC_PC_FIR_CORE_ACTION1_UNUSED_40 = 40;
static const uint32_t EC_PC_FIR_CORE_ACTION1_LS_SYS_XSTOP_ERROR = 41;
static const uint32_t EC_PC_FIR_CORE_ACTION1_UNUSED_42 = 42;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_THREAD_HANG_REC_ERROR = 43;
static const uint32_t EC_PC_FIR_CORE_ACTION1_UNUSED_44 = 44;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_LOG_XSTOP_ERROR = 45;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_TFX_XSTOP_ERROR = 46;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_TFAC_XSTOP_ERROR = 47;
static const uint32_t EC_PC_FIR_CORE_ACTION1_UNUSED_48 = 48;
static const uint32_t EC_PC_FIR_CORE_ACTION1_UNUSED_49 = 49;
static const uint32_t EC_PC_FIR_CORE_ACTION1_UNUSED_50 = 50;
static const uint32_t EC_PC_FIR_CORE_ACTION1_UNUSED_51 = 51;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_HANG_RECOVERY_FAILED = 52;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_CORE_HANG_DETECT_ERROR = 53;
static const uint32_t EC_PC_FIR_CORE_ACTION1_UNUSED_54 = 54;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_NEST_HANG_DETECT_ERROR = 55;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_REC_ERROR = 56;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR = 57;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR = 58;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_SCOM_ERROR = 59;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_XSTOP_ON_DBG_TRIGGER_ERROR = 60;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_REC_ERROR = 61;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_FW_INJ_XSTOP_ERROR = 62;
static const uint32_t EC_PC_FIR_CORE_ACTION1_PC_PHYP_XSTOP_ERROR = 63;
//<< [EC_PC_FIR_CORE_ACTION1]
// c/reg00013.H

//>> [EC_PC_SCR1]
static const uint64_t EC_PC_SCR1 = 0x20020487ull;
//<< [EC_PC_SCR1]
// c/reg00013.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00013.H"
#endif
#endif
