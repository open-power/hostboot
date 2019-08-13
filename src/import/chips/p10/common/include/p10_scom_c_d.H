/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_d.H $          */
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

#ifndef __p10_scom_c_d_H_
#define __p10_scom_c_d_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


static const uint64_t CPMS_DCCR = 0x200e0e60ull;

static const uint32_t CPMS_DCCR__LARGE_OFFSET = 0;
static const uint32_t CPMS_DCCR__LARGE_OFFSET_LEN = 4;
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
// c/reg00013.H

static const uint64_t CPMS_MMA_PFETSTAT = 0x200e0e34ull;

static const uint32_t CPMS_MMA_PFETSTAT_S_ENABLED_SENSE = 0;
static const uint32_t CPMS_MMA_PFETSTAT_S_DISABLED_SENSE = 1;
static const uint32_t CPMS_MMA_PFETSTAT__ENABLE_ACTUAL = 16;
static const uint32_t CPMS_MMA_PFETSTAT__ENABLE_ACTUAL_LEN = 8;
// c/reg00013.H

static const uint64_t CPMS_PFETDLY = 0x200e0e1cull;

static const uint32_t CPMS_PFETDLY_POWDN_DLY = 0;
static const uint32_t CPMS_PFETDLY_POWDN_DLY_LEN = 4;
static const uint32_t CPMS_PFETDLY_L3_POWUP_DLY = 4;
static const uint32_t CPMS_PFETDLY_L3_POWUP_DLY_LEN = 4;
static const uint32_t CPMS_PFETDLY_CL2_POWUP_DLY = 8;
static const uint32_t CPMS_PFETDLY_CL2_POWUP_DLY_LEN = 4;
static const uint32_t CPMS_PFETDLY_MMA_POWUP_DLY = 12;
static const uint32_t CPMS_PFETDLY_MMA_POWUP_DLY_LEN = 4;
// c/reg00013.H

static const uint64_t EC_LS_LSU_HOLD_OUT_REG3 = 0x200206c3ull;
// c/reg00013.H

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
// c/reg00013.H

static const uint64_t EC_PC_COMMON_SPR_V2_HMER_RW_WAND = 0x20020494ull;
static const uint64_t EC_PC_COMMON_SPR_V2_HMER_WO_OR = 0x20020490ull;

static const uint32_t EC_PC_COMMON_SPR_V2_HMER_MALFUNCTION_ALERT = 0;
static const uint32_t EC_PC_COMMON_SPR_V2_HMER_QME_REQUEST = 1;
static const uint32_t EC_PC_COMMON_SPR_V2_HMER_PROC_RCVY_DONE = 2;
static const uint32_t EC_PC_COMMON_SPR_V2_HMER_TFAC_ERR = 4;
static const uint32_t EC_PC_COMMON_SPR_V2_HMER_XSCOM_FAIL = 8;
static const uint32_t EC_PC_COMMON_SPR_V2_HMER_XSCOM_DONE = 9;
static const uint32_t EC_PC_COMMON_SPR_V2_HMER_PROC_RCVY_AGAIN = 11;
static const uint32_t EC_PC_COMMON_SPR_V2_HMER_SCOM_FIR_HMI = 16;
static const uint32_t EC_PC_COMMON_SPR_V2_HMER_THD_WAKE_BLOCKED_TM_SUSPEND = 17;
static const uint32_t EC_PC_COMMON_SPR_V2_HMER_TRIG_FIR_HMI = 18;
static const uint32_t EC_PC_COMMON_SPR_V2_HMER_XSCOM_STATUS = 21;
static const uint32_t EC_PC_COMMON_SPR_V2_HMER_XSCOM_STATUS_LEN = 3;
// c/reg00013.H

static const uint64_t EC_PC_FIR_CORE_ACTION1 = 0x20020447ull;
// c/reg00013.H

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
// c/reg00013.H

static const uint64_t EC_PC_PMU_SPRCOR_OCC_SCOMC = 0x20020410ull;
// c/reg00013.H

static const uint64_t EC_PC_SCR1 = 0x20020487ull;
// c/reg00013.H

static const uint64_t EC_PC_TOD_READ = 0x200204a3ull;
// c/reg00013.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_3 = 0x20020a86ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_3_C = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_3_D = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_3_D_LEN = 24;
// c/reg00013.H

static const uint64_t EC_SD_SDP_SDCR_UNIT_HOLD_OUT2 = 0x20020642ull;
// c/reg00013.H

static const uint64_t L2_L2MISC_L2CERRS_FIR_REG_RW = 0x20020000ull;
static const uint64_t L2_L2MISC_L2CERRS_FIR_REG_WO_AND = 0x20020001ull;
static const uint64_t L2_L2MISC_L2CERRS_FIR_REG_WO_OR = 0x20020002ull;

static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE = 0;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_UE = 1;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_SUE = 2;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_HW_DIR_INTIATED_LINE_DELETE_OCCURRED = 3;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_MODIFIED_LINE_BY_CO = 4;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_UE_SUE_DETECTED_ON_NON_MODIFIED_LINE_BY_CO = 5;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_DIR_CE_DETECTED = 6;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_DIR_UE_DETECTED = 7;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_DIR_STUCK_BIT_CE = 8;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_DIR_SBCE_REPAIR_FAILED = 9;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_MULTIPLE_DIR_ERRORS_DETECTED = 10;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_LRU_READ_ERROR_DETECTED = 11;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_POWERBUS_DATA_TIMEOUT = 12;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_NCU_POWERBUS_DATA_TIMEOUT = 13;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_HW_CONTROL_ERROR = 14;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_LRU_ALL_MEMBERS_IN_CGC_ARE_LINE_DELETED = 15;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_INHIBITED_HIT_CACHEABLE_ERROR = 16;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR = 17;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_STORE_RECEIVED_PB_CRESP_ADR_ERR = 18;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_CE_ERR_FROM_F2CHK = 19;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_UE_ERR_FROM_F2CHK = 20;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_POWBUS_DATA_SUE_ERR_FROM_F2CHK = 21;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_TGT_NODAL_REQ_DINC_ERR = 22;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RC_LOAD_RECEIVED_PB_CRESP_ADR_ERR_FOR_HYP = 23;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_RCDAT_RD_PARITY_ERR = 24;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CO_PSH_RECEIVED_PB_CRESP_ADR_ERR = 25;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_LVDIR_PERR = 26;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_LPCRD_TOPOTABLE_SW_CFG_ERR = 27;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_DARN_DATA_TIMEOUT = 28;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_EARLY_HANG_WARNING = 29;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CHIP_CONTAINED_UNEXP_CO_PUSH = 30;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_PEC_PH3_TIMEOUT = 32;
static const uint32_t L2_L2MISC_L2CERRS_FIR_REG_CACHE_RD_CE_AND_UE = 36;
// c/reg00013.H

static const uint64_t L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG = 0x20010615ull;

static const uint32_t L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS = 0;
static const uint32_t L3_MISC_L3CERRS_LINE_DELETED_MEMBERS_REG_L3_LINE_DELETED_MEMBERS_LEN = 5;
// c/reg00013.H

static const uint64_t NC_NCMISC_NCSCOMS_INJ_REG = 0x2001064dull;

static const uint32_t NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ = 0;
static const uint32_t NC_NCMISC_NCSCOMS_INJ_REG_STQ_ERR_INJ_LEN = 2;
// c/reg00013.H

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
// c/reg00013.H

static const uint64_t PSCOM_MODE_REG = 0x20010000ull;

static const uint32_t PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR = 0;
static const uint32_t PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR = 1;
static const uint32_t PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR = 3;
static const uint32_t PSCOM_MODE_REG_WATCHDOG_ENABLE = 4;
static const uint32_t PSCOM_MODE_REG_SCOM_HANG_LIMIT = 5;
static const uint32_t PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN = 2;
static const uint32_t PSCOM_MODE_REG_FORCE_ALL_RINGS = 7;
static const uint32_t PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE = 8;
static const uint32_t PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT = 9;
static const uint32_t PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN = 3;
// c/reg00013.H

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
static const uint32_t QME_PSCRS0_ = 14;
static const uint32_t QME_PSCRS0__LEN = 2;
static const uint32_t QME_PSCRS0_MTL = 16;
static const uint32_t QME_PSCRS0_MTL_LEN = 4;
static const uint32_t QME_PSCRS0_RL = 20;
static const uint32_t QME_PSCRS0_RL_LEN = 4;
static const uint32_t QME_PSCRS0_PLS = 24;
static const uint32_t QME_PSCRS0_PLS_LEN = 4;
// c/reg00013.H

#ifndef __PPE_HCODE__
}
}
#include "c/reg00013.H"
#endif
#endif
