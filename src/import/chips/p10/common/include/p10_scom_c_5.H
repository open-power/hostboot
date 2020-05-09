/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_5.H $          */
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

#ifndef __p10_scom_c_5_H_
#define __p10_scom_c_5_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> [ADDR_TRAP_REG]
static const uint64_t ADDR_TRAP_REG = 0x20010003ull;

static const uint32_t ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR = 0;
static const uint32_t ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN = 16;
static const uint32_t ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR = 16;
static const uint32_t ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT = 17;
static const uint32_t ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR = 18;
static const uint32_t ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN = 13;
static const uint32_t ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY = 31;
static const uint32_t ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR = 32;
static const uint32_t ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION = 33;
static const uint32_t ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER = 34;
static const uint32_t ADDR_TRAP_REG_LAST_MASTERID = 35;
static const uint32_t ADDR_TRAP_REG_LAST_MASTERID_LEN = 4;
//<< [ADDR_TRAP_REG]
// c/reg00005.H

//>> [CPMS_FLMR]
static const uint64_t CPMS_FLMR_RW = 0x200e0e48ull;
static const uint64_t CPMS_FLMR_WO_CLEAR = 0x200e0e4bull;
static const uint64_t CPMS_FLMR_WO_OR = 0x200e0e4aull;

static const uint32_t CPMS_FLMR_LARGE_INITIAL_CYCLES = 0;
static const uint32_t CPMS_FLMR_LARGE_INITIAL_CYCLES_LEN = 6;
static const uint32_t CPMS_FLMR_LARGE_INITIAL_ACTION = 6;
static const uint32_t CPMS_FLMR_LARGE_INITIAL_ACTION_LEN = 5;
static const uint32_t CPMS_FLMR_LARGE_PREFETCH_ACTION = 11;
static const uint32_t CPMS_FLMR_LARGE_PREFETCH_ACTION_LEN = 2;
static const uint32_t CPMS_FLMR_LARGE_RESPONSE_DISABLE = 13;
static const uint32_t CPMS_FLMR_LARGE_FLUSH_TYPE = 14;
static const uint32_t CPMS_FLMR_LARGE_DITHER_WINDOW_SEL = 15;
static const uint32_t CPMS_FLMR_LARGE_DITHER_INITIAL = 16;
static const uint32_t CPMS_FLMR_LARGE_DITHER_INITIAL_LEN = 4;
static const uint32_t CPMS_FLMR_LARGE_DITHER_REPEAT = 20;
static const uint32_t CPMS_FLMR_LARGE_DITHER_REPEAT_LEN = 4;
static const uint32_t CPMS_FLMR_LARGE_DITHER_INCREASE = 24;
static const uint32_t CPMS_FLMR_LARGE_DITHER_INCREASE_LEN = 4;
static const uint32_t CPMS_FLMR_PHASE1_RECOVERY_ACTION = 28;
static const uint32_t CPMS_FLMR_PHASE1_RECOVERY_ACTION_LEN = 3;
static const uint32_t CPMS_FLMR_PHASE1_RECOVERY_PREFETCH = 31;
static const uint32_t CPMS_FLMR_PHASE1_RECOVERY_PREFETCH_LEN = 2;
static const uint32_t CPMS_FLMR_PHASE1_RECOVERY_VECTOR = 33;
static const uint32_t CPMS_FLMR_PHASE1_RECOVERY_VECTOR_LEN = 3;
static const uint32_t CPMS_FLMR_PHASE2_RECOVERY_ACTION = 36;
static const uint32_t CPMS_FLMR_PHASE2_RECOVERY_ACTION_LEN = 3;
static const uint32_t CPMS_FLMR_PHASE2_RECOVERY_PREFETCH = 39;
static const uint32_t CPMS_FLMR_PHASE2_RECOVERY_PREFETCH_LEN = 2;
static const uint32_t CPMS_FLMR_PHASE2_RECOVERY_VECTOR = 41;
static const uint32_t CPMS_FLMR_PHASE2_RECOVERY_VECTOR_LEN = 3;
static const uint32_t CPMS_FLMR_PHASE2_RECOVERY_CYCLES = 44;
static const uint32_t CPMS_FLMR_PHASE2_RECOVERY_CYCLES_LEN = 8;
static const uint32_t CPMS_FLMR_MMA_DROOP_PROTECT_ENABLE = 52;
static const uint32_t CPMS_FLMR_MMA_DROOP_PREDICT_SELECT = 53;
static const uint32_t CPMS_FLMR_MMA_DROOP_PREDICT_SELECT_LEN = 3;
static const uint32_t CPMS_FLMR_CORE_UCODE_IDLE_DISABLE = 56;
static const uint32_t CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS = 57;
static const uint32_t CPMS_FLMR_CORE_UCODE_GRANT_SUPPRESS_LEN = 2;
static const uint32_t CPMS_FLMR_CORE_UCODE_GRANT_INJECT = 59;
static const uint32_t CPMS_FLMR_FTC_RESET = 60;
static const uint32_t CPMS_FLMR_IGNORE_IFU_THROTTLE_ACTIVE = 61;
static const uint32_t CPMS_FLMR_PHASE1_DITHER_NTC = 62;
static const uint32_t CPMS_FLMR_CORE_UCODE_EXIT_DISABLE = 63;
//<< [CPMS_FLMR]
// c/reg00005.H

//>> [CPMS_WPCR]
static const uint64_t CPMS_WPCR = 0x200e0e94ull;

static const uint32_t CPMS_WPCR_SPARE = 0;
static const uint32_t CPMS_WPCR_SPARE_LEN = 2;
static const uint32_t CPMS_WPCR_BASE_THROTTLE_INDEX = 2;
static const uint32_t CPMS_WPCR_BASE_THROTTLE_INDEX_LEN = 6;
static const uint32_t CPMS_WPCR_INTERVAL_PROXY_TARGET = 12;
static const uint32_t CPMS_WPCR_INTERVAL_PROXY_TARGET_LEN = 20;
static const uint32_t CPMS_WPCR_SPARE2 = 32;
static const uint32_t CPMS_WPCR_PROXY_THRESH_SELECT = 33;
static const uint32_t CPMS_WPCR_PROXY_THRESH_SELECT_LEN = 3;
static const uint32_t CPMS_WPCR_PROXY_CARRYOUT_SEL = 36;
static const uint32_t CPMS_WPCR_PROXY_CARRYOUT_SEL_LEN = 4;
static const uint32_t CPMS_WPCR_PITCH_FTX_SAT_MAX = 58;
static const uint32_t CPMS_WPCR_PITCH_FTX_SAT_MIN = 59;
static const uint32_t CPMS_WPCR_PITCH_ACCERR_SAT_MAX = 60;
static const uint32_t CPMS_WPCR_PITCH_ACCERR_SAT_MIN = 61;
static const uint32_t CPMS_WPCR_PITCH_APP_SATURATED = 62;
static const uint32_t CPMS_WPCR_STOP_STATE_OCCURRED = 63;
//<< [CPMS_WPCR]
// c/reg00005.H

//>> [EC_LS_LSU_HOLD_OUT_REG8]
static const uint64_t EC_LS_LSU_HOLD_OUT_REG8 = 0x200206c8ull;

static const uint32_t EC_LS_LSU_HOLD_OUT_REG8_0_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT = 0;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG8_0_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT = 1;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT = 2;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT = 3;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT = 4;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG8_0_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT = 5;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG8_1_FIN_LD_STFWD_AND_BLOCK_DVAL_ERR_HOLD_OUT = 6;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG8_1_FLS_LD_FINAL_PASS_AND_NO_FINISH_ERR_HOLD_OUT = 7;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_REJECT_AND_FINISH_ON_SAME_OP_ERR_HOLD_OUT = 8;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_SLEEP_ERR_HOLD_OUT = 9;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_DVAL_AND_WAKEUP_ERR_HOLD_OUT = 10;
static const uint32_t EC_LS_LSU_HOLD_OUT_REG8_1_FLSP1_HYPV_TRAP_DETECT_AND_NTC_ERR_HOLD_OUT = 11;
//<< [EC_LS_LSU_HOLD_OUT_REG8]
// c/reg00005.H

//>> [EC_PC_PMU_SPRCOR_CORE_FUSES]
static const uint64_t EC_PC_PMU_SPRCOR_CORE_FUSES = 0x2002040eull;

static const uint32_t EC_PC_PMU_SPRCOR_CORE_FUSES_EXT_MEMORY_DIS = 0;
static const uint32_t EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL = 1;
static const uint32_t EC_PC_PMU_SPRCOR_CORE_FUSES_FLOP_CONTROL_LEN = 2;
static const uint32_t EC_PC_PMU_SPRCOR_CORE_FUSES_VMX_CRYPTO_DIS = 3;
//<< [EC_PC_PMU_SPRCOR_CORE_FUSES]
// c/reg00005.H

//>> [EC_PC_SPURR_FREQ_REF]
static const uint64_t EC_PC_SPURR_FREQ_REF = 0x200204a1ull;

static const uint32_t EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE = 0;
static const uint32_t EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE_LEN = 8;
//<< [EC_PC_SPURR_FREQ_REF]
// c/reg00005.H

//>> [EC_PC_TOD_SYNC001]
static const uint64_t EC_PC_TOD_SYNC001 = 0x200204a3ull;

static const uint32_t EC_PC_TOD_SYNC001_TOD = 0;
static const uint32_t EC_PC_TOD_SYNC001_TOD_LEN = 54;
static const uint32_t EC_PC_TOD_SYNC001_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC001_CHIP_TOD_STATUS_LEN = 4;
//<< [EC_PC_TOD_SYNC001]
// c/reg00005.H

//>> [EC_PC_TOD_SYNC110]
static const uint64_t EC_PC_TOD_SYNC110 = 0x200204a3ull;

static const uint32_t EC_PC_TOD_SYNC110_TOD = 0;
static const uint32_t EC_PC_TOD_SYNC110_TOD_LEN = 49;
static const uint32_t EC_PC_TOD_SYNC110_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC110_CHIP_TOD_STATUS_LEN = 4;
//<< [EC_PC_TOD_SYNC110]
// c/reg00005.H

//>> [EC_PC_TRACE1_TR_TR0_CONFIG_3]
static const uint64_t EC_PC_TRACE1_TR_TR0_CONFIG_3 = 0x20020a46ull;

static const uint32_t EC_PC_TRACE1_TR_TR0_CONFIG_3_C = 0;
static const uint32_t EC_PC_TRACE1_TR_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t EC_PC_TRACE1_TR_TR0_CONFIG_3_D = 24;
static const uint32_t EC_PC_TRACE1_TR_TR0_CONFIG_3_D_LEN = 24;
//<< [EC_PC_TRACE1_TR_TR0_CONFIG_3]
// c/reg00005.H

//>> [L2TRA_TR0_CONFIG_5]
static const uint64_t L2TRA_TR0_CONFIG_5 = 0x20020048ull;

static const uint32_t L2TRA_TR0_CONFIG_5_C = 0;
static const uint32_t L2TRA_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t L2TRA_TR0_CONFIG_5_D = 24;
static const uint32_t L2TRA_TR0_CONFIG_5_D_LEN = 24;
//<< [L2TRA_TR0_CONFIG_5]
// c/reg00005.H

//>> [L3_MISC_L3CERRS_ERR_INJ_REG]
static const uint64_t L3_MISC_L3CERRS_ERR_INJ_REG = 0x2001060dull;

static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ = 0;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ = 1;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE = 2;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE_LEN = 2;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ = 4;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ = 5;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE = 6;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ = 7;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ = 8;
//<< [L3_MISC_L3CERRS_ERR_INJ_REG]
// c/reg00005.H

//>> [L3_MISC_L3CERRS_MODE_REG0]
static const uint64_t L3_MISC_L3CERRS_MODE_REG0 = 0x2001062bull;

static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_DISABLED_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_DMAP_CI_EN_CFG = 1;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_RDSN_LINEDEL_UE_EN = 2;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_EN = 3;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_NO_ALLOCATE_MODE_ACTIVE = 4;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_PF_CFG_SKIP_GRP_SCOPE_EN = 5;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG = 6;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_CO_MEM_ME_BEHAVIOR_CFG_LEN = 2;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_LCO_RTY_LIMIT_DISABLE = 8;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_09 = 9;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_10 = 10;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_ADDR_HASH_EN_CFG = 11;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_MSTR_RTY_BACKOFF_EN_CFG = 12;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3CERRS_LCO_RETRY_THROTL_DIS = 13;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV = 14;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_HANG_POLL_PULSE_DIV_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV = 18;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_DATA_POLL_PULSE_DIV_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_SPARE_MODE_REG0_22 = 22;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN = 23;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_CFG_CHIP_ADDR_EXT_MASK_EN_LEN = 7;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_EN_CFG = 30;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG = 31;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_PROB_SEL_CFG_LEN = 2;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG = 33;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_CERRS_LRU_DECR_SUB_SEL_CFG_LEN = 3;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_L3_DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG = 36;
//<< [L3_MISC_L3CERRS_MODE_REG0]
// c/reg00005.H

//>> [NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]
static const uint64_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR = 0x2001068bull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4 = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE1TO4_LEN = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE_LEN = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11 = 8;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SPARE8TO11_LEN = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR = 12;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_LEN = 41;
//<< [NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR]
// c/reg00005.H

//>> [NC_NCCHTM_NCCHTSC_HTM_TRIG]
static const uint64_t NC_NCCHTM_NCCHTSC_HTM_TRIG = 0x20010684ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_START = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE_LEN = 10;
//<< [NC_NCCHTM_NCCHTSC_HTM_TRIG]
// c/reg00005.H

//>> [NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0]
static const uint64_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0 = 0x20010652ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID = 13;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID = 14;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID = 26;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID = 27;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID = 39;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID = 40;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID_LEN = 12;
//<< [NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0]
// c/reg00005.H

//>> [QME_CIIR]
static const uint64_t QME_CIIR = 0x200e0874ull;

static const uint32_t QME_CIIR_MSGSND_INTR_INJECT = 28;
static const uint32_t QME_CIIR_MSGSND_INTR_INJECT_LEN = 4;
static const uint32_t QME_CIIR_MSGSNDU_INTR_INJECT = 60;
static const uint32_t QME_CIIR_MSGSNDU_INTR_INJECT_LEN = 4;
//<< [QME_CIIR]
// c/reg00005.H

//>> [QME_RMOR]
static const uint64_t QME_RMOR = 0x200e0868ull;

static const uint32_t QME_RMOR_DATA = 0;
static const uint32_t QME_RMOR_DATA_LEN = 63;
static const uint32_t QME_RMOR_URMOR_SELECT = 63;
//<< [QME_RMOR]
// c/reg00005.H

//>> [QME_SCR]
static const uint64_t QME_SCR_RW = 0x200e080cull;
static const uint64_t QME_SCR_WO_CLEAR = 0x200e080full;
static const uint64_t QME_SCR_WO_OR = 0x200e080eull;

static const uint32_t QME_SCR_DATA = 0;
static const uint32_t QME_SCR_DATA_LEN = 64;
//<< [QME_SCR]
// c/reg00005.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00005.H"
#endif
#endif
