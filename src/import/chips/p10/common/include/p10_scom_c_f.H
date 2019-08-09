/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_f.H $          */
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

#ifndef __p10_scom_c_f_H_
#define __p10_scom_c_f_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


static const uint64_t CPMS_ACCR = 0x200e0e78ull;

static const uint32_t CPMS_ACCR_COUNT_MODE = 0;
static const uint32_t CPMS_ACCR_COUNT_MODE_LEN = 2;
static const uint32_t CPMS_ACCR_COUNT_TYPE = 2;
static const uint32_t CPMS_ACCR_COUNT_TYPE_LEN = 2;
static const uint32_t CPMS_ACCR_COUNT_ENABLE_SEL = 4;
static const uint32_t CPMS_ACCR_COUNT_ENABLE_SEL_LEN = 2;
static const uint32_t CPMS_ACCR_INVERT_COUNT_ENABLE = 6;
static const uint32_t CPMS_ACCR_COUNT_ALWAYS_SAMPLED = 7;
static const uint32_t CPMS_ACCR_HI_THRESHOLD = 8;
static const uint32_t CPMS_ACCR_HI_THRESHOLD_LEN = 8;
static const uint32_t CPMS_ACCR_LO_THRESHOLD = 16;
static const uint32_t CPMS_ACCR_LO_THRESHOLD_LEN = 8;
static const uint32_t CPMS_ACCR_SPARE = 24;
static const uint32_t CPMS_ACCR_SPARE_LEN = 2;
// c/reg00015.H

static const uint64_t CPMS_MMAR_RW = 0x200e0e38ull;
static const uint64_t CPMS_MMAR_WO_CLEAR = 0x200e0e3bull;
static const uint64_t CPMS_MMAR_WO_OR = 0x200e0e3aull;

static const uint32_t CPMS_MMAR_AVAILABLE = 0;
static const uint32_t CPMS_MMAR_FUNC_RESET = 1;
// c/reg00015.H

static const uint64_t EC_PC_COMMON_SPR_SCOMD = 0x20210481ull;
// c/reg00015.H

static const uint64_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT = 0x202104b7ull;
// c/reg00015.H

static const uint64_t EC_PC_PWM_EVENTS = 0x202104a2ull;

static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_32 = 32;
static const uint32_t EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD = 33;
static const uint32_t EC_PC_PWM_EVENTS_FREQ_SCALE_A_THRESHOLD_LEN = 7;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_40 = 40;
static const uint32_t EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD = 41;
static const uint32_t EC_PC_PWM_EVENTS_FREQ_SCALE_B_THRESHOLD_LEN = 7;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_48 = 48;
static const uint32_t EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD = 49;
static const uint32_t EC_PC_PWM_EVENTS_PSTATE_A_THRESHOLD_LEN = 3;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_52 = 52;
static const uint32_t EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD = 53;
static const uint32_t EC_PC_PWM_EVENTS_PSTATE_B_THRESHOLD_LEN = 3;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_56 = 56;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_57 = 57;
static const uint32_t EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS = 58;
static const uint32_t EC_PC_PWM_EVENTS_EVENT_MUX_SELECTS_LEN = 2;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_60 = 60;
static const uint32_t EC_PC_PWM_EVENTS_PWM_EVENTS_RESERVED_61 = 61;
static const uint32_t EC_PC_PWM_EVENTS_PMCM_THRESHOLD = 62;
static const uint32_t EC_PC_PWM_EVENTS_PMCM_THRESHOLD_LEN = 2;
// c/reg00015.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG_0 = 0x20210a43ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00015.H

static const uint64_t EC_PC_TRACE2_TR0_TRACE_HI_DATA_REG = 0x20210a80ull;

static const uint32_t EC_PC_TRACE2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t EC_PC_TRACE2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00015.H

static const uint64_t L2_L2MISC_L2CERRS_ERR_INJ_REG = 0x2021000cull;

static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE = 0;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_DW_TYPE_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE = 4;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_CW_TYPE_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE = 8;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_STQ_TYPE_LEN = 2;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE = 10;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_CPI_TYPE_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_LVDIR_EN = 13;
static const uint32_t L2_L2MISC_L2CERRS_ERR_INJ_REG_LRU_EN = 14;
// c/reg00015.H

static const uint64_t L2TRA_TR0_TRACE_LO_DATA_REG = 0x20210041ull;

static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L2TRA_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00015.H

static const uint64_t L2TRA_TR0_CONFIG = 0x20210042ull;

static const uint32_t L2TRA_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L2TRA_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L2TRA_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L2TRA_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t L2TRA_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L2TRA_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L2TRA_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L2TRA_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L2TRA_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L2TRA_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L2TRA_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// c/reg00015.H

static const uint64_t L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG = 0x2020060cull;

static const uint32_t L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_WIFSM_INJ_DIS_REG_L3_WIFSM_INJ_DIS_CFG_LEN = 2;
// c/reg00015.H

static const uint64_t NC_NCMISC_NCSCOMS_FIR_REG_RW = 0x20200640ull;
static const uint64_t NC_NCMISC_NCSCOMS_FIR_REG_WO_AND = 0x20200641ull;
static const uint64_t NC_NCMISC_NCSCOMS_FIR_REG_WO_OR = 0x20200642ull;

static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_CONTROL_ERR = 0;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_CONTROL_ERR = 1;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SLBIEG_SW_ERR = 2;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_ST_ADDR_ERR = 3;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_LD_ADDR_ERR = 4;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_ST_ACK_DEAD = 5;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_PB_EARLY_HANG = 6;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_MSG_ADDR_ERR = 7;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_STQ_DATA_PARITY_ERR = 8;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_STORE_TIMEOUT = 9;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_MASTER_TIMEOUT = 10;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_TLBIE_SNOOP_TIMEOUT = 11;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_IMA_CRESP_ADDR_ERR = 12;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_PMISC_CRESP_ADDR_ERR = 14;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_TGT_NODAL_DINC_ERR = 19;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_DARN_EN_ERR = 20;
static const uint32_t NC_NCMISC_NCSCOMS_FIR_REG_DARN_ADDR_ERR = 21;
// c/reg00015.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_MODE_REG = 0x2020064aull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_HTM_QUEUE_LIMIT_LEN = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TRASH_MODE_EN = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_FENCE_TLBIE = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK = 9;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_DROP_PRIORITY_MASK_LEN = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBI_GROUP_PUMP_EN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_SLBI_GROUP_PUMP_EN = 13;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_PACING_CNT_EN = 14;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_WT4TX_CORE_EN = 15;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE = 16;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_DEC_RATE_LEN = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE = 24;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_INC_RATE_LEN = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH = 32;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLBIE_CNT_THRESH_LEN = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC = 40;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_TLB_CHK_WAIT_DEC_LEN = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_MODE_REG_SKIP_GRP_SCOPE_EN = 48;
// c/reg00015.H

#ifndef __PPE_HCODE__
}
}
#include "c/reg00015.H"
#endif
#endif
