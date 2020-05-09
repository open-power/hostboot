/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_a.H $          */
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

#ifndef __p10_scom_c_a_H_
#define __p10_scom_c_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> [CPMS_DPMR]
static const uint64_t CPMS_DPMR = 0x200e0ea0ull;

static const uint32_t CPMS_DPMR_POWER_PROXY_ENABLE = 0;
static const uint32_t CPMS_DPMR_PROXY_CAL_MODE = 1;
static const uint32_t CPMS_DPMR_PIL_ENABLE = 2;
static const uint32_t CPMS_DPMR_DDP_ENABLE = 3;
static const uint32_t CPMS_DPMR_EMPATH_MODE_SEL = 4;
static const uint32_t CPMS_DPMR_DDP_DDS_ADJUST_EN = 5;
static const uint32_t CPMS_DPMR_SPARE = 6;
static const uint32_t CPMS_DPMR_SPARE_LEN = 2;
//<< [CPMS_DPMR]
// c/reg00010.H

//>> [EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1]
static const uint64_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1 = 0x20020601ull;

static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_16 = 0;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_17 = 1;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_18 = 2;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_19 = 3;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_20 = 4;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_21 = 5;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_22 = 6;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_23 = 7;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_24 = 8;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_25 = 9;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_26 = 10;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_27 = 11;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_28 = 12;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_29 = 13;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_30 = 14;
static const uint32_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1_31 = 15;
//<< [EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT1]
// c/reg00010.H

//>> [EC_PC_FIR_CORE_SYS]
static const uint64_t EC_PC_FIR_CORE_SYS = 0x2002044aull;

static const uint32_t EC_PC_FIR_CORE_SYS_CORE_SYS_ENABLE = 1;
//<< [EC_PC_FIR_CORE_SYS]
// c/reg00010.H

//>> [EC_PC_FIR_CORE_WOF]
static const uint64_t EC_PC_FIR_CORE_WOF = 0x20020448ull;

static const uint32_t EC_PC_FIR_CORE_WOF_IF_SRAM_REC_ERROR = 0;
static const uint32_t EC_PC_FIR_CORE_WOF_TC_FIR_XSTOP_ERROR = 1;
static const uint32_t EC_PC_FIR_CORE_WOF_IF_RFILE_REC_ERROR = 2;
static const uint32_t EC_PC_FIR_CORE_WOF_IF_RFILE_XSTOP_ERROR = 3;
static const uint32_t EC_PC_FIR_CORE_WOF_IF_LOG_REC_ERROR = 4;
static const uint32_t EC_PC_FIR_CORE_WOF_IF_LOG_XSTOP_ERROR = 5;
static const uint32_t EC_PC_FIR_CORE_WOF_UNUSED_6 = 6;
static const uint32_t EC_PC_FIR_CORE_WOF_VS_VSMM_ACC_ERROR = 7;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_RECOV_XSTOP_ERROR = 8;
static const uint32_t EC_PC_FIR_CORE_WOF_VS_STF_ERROR = 9;
static const uint32_t EC_PC_FIR_CORE_WOF_UNUSED_10 = 10;
static const uint32_t EC_PC_FIR_CORE_WOF_SD_LOG_REC_ERROR = 11;
static const uint32_t EC_PC_FIR_CORE_WOF_SD_LOG_XSTOP_ERROR = 12;
static const uint32_t EC_PC_FIR_CORE_WOF_SD_NOT_MT_CI_REC_ERROR = 13;
static const uint32_t EC_PC_FIR_CORE_WOF_SD_MCHK_AND_ME_EQ_0_ERROR = 14;
static const uint32_t EC_PC_FIR_CORE_WOF_SD_L2_UE_ERROR = 15;
static const uint32_t EC_PC_FIR_CORE_WOF_SD_L2_UE_OVER_THRES_ERROR = 16;
static const uint32_t EC_PC_FIR_CORE_WOF_SD_L2_CI_UE_ERROR = 17;
static const uint32_t EC_PC_FIR_CORE_WOF_MU_TLB_P_ERROR = 18;
static const uint32_t EC_PC_FIR_CORE_WOF_MU_SLB_P_ERROR = 19;
static const uint32_t EC_PC_FIR_CORE_WOF_UNUSED_20 = 20;
static const uint32_t EC_PC_FIR_CORE_WOF_MU_CXT_P_ERROR = 21;
static const uint32_t EC_PC_FIR_CORE_WOF_MU_LOG_XSTOP_ERROR = 22;
static const uint32_t EC_PC_FIR_CORE_WOF_MU_SYS_XSTOP_ERROR = 23;
static const uint32_t EC_PC_FIR_CORE_WOF_VS_LOG_REC_ERROR = 24;
static const uint32_t EC_PC_FIR_CORE_WOF_VS_LOG_XSTOP_ERROR = 25;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_RECOV_IN_MAINT_ERROR = 26;
static const uint32_t EC_PC_FIR_CORE_WOF_UNUSED_27 = 27;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_SYS_XSTOP_ERROR = 28;
static const uint32_t EC_PC_FIR_CORE_WOF_LS_SRAM_PARITY_ERROR = 29;
static const uint32_t EC_PC_FIR_CORE_WOF_LS_SETDELETE_ERROR = 30;
static const uint32_t EC_PC_FIR_CORE_WOF_LS_RFILE_REC_ERROR = 31;
static const uint32_t EC_PC_FIR_CORE_WOF_LS_RFILE_XSTOP_ERROR = 32;
static const uint32_t EC_PC_FIR_CORE_WOF_MU_TLB_MULTIHIT_ERROR = 33;
static const uint32_t EC_PC_FIR_CORE_WOF_MU_SLB_MULTIHIT_ERROR = 34;
static const uint32_t EC_PC_FIR_CORE_WOF_LS_DERAT_MULTIHIT_ERROR = 35;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_FWD_PROGRESS_ERROR = 36;
static const uint32_t EC_PC_FIR_CORE_WOF_LS_LOG_REC_ERROR = 37;
static const uint32_t EC_PC_FIR_CORE_WOF_LS_LOG_XSTOP_ERROR = 38;
static const uint32_t EC_PC_FIR_CORE_WOF_UNUSED_39 = 39;
static const uint32_t EC_PC_FIR_CORE_WOF_UNUSED_40 = 40;
static const uint32_t EC_PC_FIR_CORE_WOF_LS_SYS_XSTOP_ERROR = 41;
static const uint32_t EC_PC_FIR_CORE_WOF_UNUSED_42 = 42;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_THREAD_HANG_REC_ERROR = 43;
static const uint32_t EC_PC_FIR_CORE_WOF_UNUSED_44 = 44;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_LOG_XSTOP_ERROR = 45;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_TFX_XSTOP_ERROR = 46;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_TFAC_XSTOP_ERROR = 47;
static const uint32_t EC_PC_FIR_CORE_WOF_UNUSED_48 = 48;
static const uint32_t EC_PC_FIR_CORE_WOF_UNUSED_49 = 49;
static const uint32_t EC_PC_FIR_CORE_WOF_UNUSED_50 = 50;
static const uint32_t EC_PC_FIR_CORE_WOF_UNUSED_51 = 51;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_HANG_RECOVERY_FAILED = 52;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_CORE_HANG_DETECT_ERROR = 53;
static const uint32_t EC_PC_FIR_CORE_WOF_UNUSED_54 = 54;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_NEST_HANG_DETECT_ERROR = 55;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_REC_ERROR = 56;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_XSTOP_ERROR = 57;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_OTHER_CORE_CHIPLET_SYS_XSTOP_ERROR = 58;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_SCOM_ERROR = 59;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_XSTOP_ON_DBG_TRIGGER_ERROR = 60;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_FW_INJ_REC_ERROR = 61;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_FW_INJ_XSTOP_ERROR = 62;
static const uint32_t EC_PC_FIR_CORE_WOF_PC_PHYP_XSTOP_ERROR = 63;
//<< [EC_PC_FIR_CORE_WOF]
// c/reg00010.H

//>> [EC_PC_FIR_RAM_STATUS]
static const uint64_t EC_PC_FIR_RAM_STATUS = 0x20020450ull;

static const uint32_t EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV = 0;
static const uint32_t EC_PC_FIR_RAM_STATUS_RAM_COMPLETION = 1;
static const uint32_t EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION = 2;
static const uint32_t EC_PC_FIR_RAM_STATUS_LSU_EMPTY = 3;
//<< [EC_PC_FIR_RAM_STATUS]
// c/reg00010.H

//>> [EC_PC_PMC_UPDATE]
static const uint64_t EC_PC_PMC_UPDATE = 0x20020414ull;

static const uint32_t EC_PC_PMC_UPDATE_PMC_REG_MSR_S_ON_SRESET = 0;
static const uint32_t EC_PC_PMC_UPDATE_PMC_REG_DIS_XFER_TFAC = 1;
static const uint32_t EC_PC_PMC_UPDATE_PMC_REG_XFER_TFAC = 31;
static const uint32_t EC_PC_PMC_UPDATE_WRITE_VT0_PM_STATE = 32;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT0_PLS = 33;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT0_PLS_LEN = 4;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1 = 37;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT0_SRR1_LEN = 3;
static const uint32_t EC_PC_PMC_UPDATE_WRITE_VT1_PM_STATE = 40;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT1_PLS = 41;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT1_PLS_LEN = 4;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1 = 45;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT1_SRR1_LEN = 3;
static const uint32_t EC_PC_PMC_UPDATE_WRITE_VT2_PM_STATE = 48;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT2_PLS = 49;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT2_PLS_LEN = 4;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1 = 53;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT2_SRR1_LEN = 3;
static const uint32_t EC_PC_PMC_UPDATE_WRITE_VT3_PM_STATE = 56;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT3_PLS = 57;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT3_PLS_LEN = 4;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1 = 61;
static const uint32_t EC_PC_PMC_UPDATE_PSSCR_VT3_SRR1_LEN = 3;
//<< [EC_PC_PMC_UPDATE]
// c/reg00010.H

//>> [EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG]
static const uint64_t EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG = 0x20020a81ull;

static const uint32_t EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
//<< [EC_PC_TRACE2_TR_TR0_TRACE_LO_DATA_REG]
// c/reg00010.H

//>> [L2_L2MISC_L2CERRS_FIR_ACTION0_REG]
static const uint64_t L2_L2MISC_L2CERRS_FIR_ACTION0_REG = 0x20020006ull;

static const uint32_t L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0 = 0;
static const uint32_t L2_L2MISC_L2CERRS_FIR_ACTION0_REG_FIR_ACTION0_LEN = 40;
//<< [L2_L2MISC_L2CERRS_FIR_ACTION0_REG]
// c/reg00010.H

//>> [L2_L2MISC_L2CERRS_FIR_ACTION1_REG]
static const uint64_t L2_L2MISC_L2CERRS_FIR_ACTION1_REG = 0x20020007ull;

static const uint32_t L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1 = 0;
static const uint32_t L2_L2MISC_L2CERRS_FIR_ACTION1_REG_FIR_ACTION1_LEN = 40;
//<< [L2_L2MISC_L2CERRS_FIR_ACTION1_REG]
// c/reg00010.H

//>> [L2TRA_TR0_TRACE_HI_DATA_REG]
static const uint64_t L2TRA_TR0_TRACE_HI_DATA_REG = 0x20020040ull;

static const uint32_t L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L2TRA_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
//<< [L2TRA_TR0_TRACE_HI_DATA_REG]
// c/reg00010.H

//>> [L2TRA_TR0_CONFIG_0]
static const uint64_t L2TRA_TR0_CONFIG_0 = 0x20020043ull;

static const uint32_t L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L2TRA_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
//<< [L2TRA_TR0_CONFIG_0]
// c/reg00010.H

//>> [L2TRA_TR1_CONFIG_9]
static const uint64_t L2TRA_TR1_CONFIG_9 = 0x20020089ull;

static const uint32_t L2TRA_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L2TRA_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L2TRA_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L2TRA_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L2TRA_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L2TRA_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t L2TRA_TR1_CONFIG_9_SPARE_LT = 37;
//<< [L2TRA_TR1_CONFIG_9]
// c/reg00010.H

//>> [L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG]
static const uint64_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG = 0x20010611ull;

static const uint32_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_SEGR_COLUMN_CFG_LEN = 16;
static const uint32_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG = 16;
static const uint32_t L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG_ALLOC_MD_CFG_LEN = 2;
//<< [L3_MISC_L3CERRS_LRU_VIC_ALLOC_REG]
// c/reg00010.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00010.H"
#endif
#endif
