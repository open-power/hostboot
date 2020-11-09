/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_3.H $          */
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

#ifndef __p10_scom_c_3_H_
#define __p10_scom_c_3_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> [CPMS_CCDR]
static const uint64_t CPMS_CCDR = 0x200e0e74ull;

static const uint32_t CPMS_CCDR_CHAR_COUNTA_SCALE = 0;
static const uint32_t CPMS_CCDR_CHAR_COUNTA_SCALE_LEN = 4;
static const uint32_t CPMS_CCDR_CHAR_COUNTA_VALUE = 4;
static const uint32_t CPMS_CCDR_CHAR_COUNTA_VALUE_LEN = 16;
static const uint32_t CPMS_CCDR_CHAR_COUNTB_SCALE = 20;
static const uint32_t CPMS_CCDR_CHAR_COUNTB_SCALE_LEN = 4;
static const uint32_t CPMS_CCDR_CHAR_COUNTB_VALUE = 24;
static const uint32_t CPMS_CCDR_CHAR_COUNTB_VALUE_LEN = 16;
static const uint32_t CPMS_CCDR_CHAR_COUNTC_SCALE = 40;
static const uint32_t CPMS_CCDR_CHAR_COUNTC_SCALE_LEN = 4;
static const uint32_t CPMS_CCDR_CHAR_COUNTC_VALUE = 44;
static const uint32_t CPMS_CCDR_CHAR_COUNTC_VALUE_LEN = 16;
static const uint32_t CPMS_CCDR_CHAR_COUNTA_MOD = 60;
static const uint32_t CPMS_CCDR_CHAR_COUNTB_MOD = 61;
static const uint32_t CPMS_CCDR_CHAR_COUNTC_MOD = 62;
static const uint32_t CPMS_CCDR_SAMPLE_DISABLE_INDICATOR = 63;
//<< [CPMS_CCDR]
// c/reg00003.H

//>> [CPMS_CL2_PFETCNTL]
static const uint64_t CPMS_CL2_PFETCNTL = 0x200e0e28ull;
static const uint64_t CPMS_CL2_PFETCNTL_WO_CLEAR = 0x200e0e2bull;
static const uint64_t CPMS_CL2_PFETCNTL_WO_OR = 0x200e0e2aull;

static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE = 0;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEQ_STATE_LEN = 2;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE = 2;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEQ_STATE_LEN = 2;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_VAL_OVERRIDE = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEL_OVERRIDE = 5;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_VAL_OVERRIDE = 6;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEL_OVERRIDE = 7;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_REGULATION_FINGER_SET = 8;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE = 12;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_ENABLE_VALUE_LEN = 8;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE = 20;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PFET_SEL_VALUE_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE = 24;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_ENABLE_VALUE_LEN = 8;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE = 32;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PFET_SEL_VALUE_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PG_STATE = 42;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PG_STATE_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PG_SEL = 46;
static const uint32_t CPMS_CL2_PFETCNTL_VDD_PG_SEL_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PG_STATE = 50;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PG_STATE_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PG_SEL = 54;
static const uint32_t CPMS_CL2_PFETCNTL_VCS_PG_SEL_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL = 58;
static const uint32_t CPMS_CL2_PFETCNTL_ACS_MINMAX_SEL_LEN = 4;
static const uint32_t CPMS_CL2_PFETCNTL_ACS_ENABLE = 62;
static const uint32_t CPMS_CL2_PFETCNTL_SRAM_ENABLE = 63;
//<< [CPMS_CL2_PFETCNTL]
// c/reg00003.H

//>> [CPMS_FDCR]
static const uint64_t CPMS_FDCR = 0x200e0e40ull;
static const uint64_t CPMS_FDCR_SCOM2 = 0x200e0e42ull;
static const uint64_t CPMS_FDCR_WO_CLEAR = 0x200e0e43ull;

static const uint32_t CPMS_FDCR_DISABLE = 0;
static const uint32_t CPMS_FDCR_FORCE_SAMPLE = 1;
static const uint32_t CPMS_FDCR_STICKY_CONTROL = 2;
static const uint32_t CPMS_FDCR_STICKY_CONTROL_LEN = 2;
static const uint32_t CPMS_FDCR_CONTROL_UPDATE_DISABLE = 4;
static const uint32_t CPMS_FDCR_SUPPRESS_FTC_UPDATE = 5;
static const uint32_t CPMS_FDCR_CAL_ADJUST = 6;
static const uint32_t CPMS_FDCR_CAL_ADJUST_LEN = 2;
static const uint32_t CPMS_FDCR_DELAY = 8;
static const uint32_t CPMS_FDCR_DELAY_LEN = 8;
static const uint32_t CPMS_FDCR_THRESHOLD_UPDATE_DISABLE = 16;
static const uint32_t CPMS_FDCR_TRIP_OFFSET = 17;
static const uint32_t CPMS_FDCR_TRIP_OFFSET_LEN = 3;
static const uint32_t CPMS_FDCR_DATA0_DETECT = 20;
static const uint32_t CPMS_FDCR_DATA0_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_DATA1_DETECT = 24;
static const uint32_t CPMS_FDCR_DATA1_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_DATA2_DETECT = 28;
static const uint32_t CPMS_FDCR_DATA2_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_LARGE_DROOP_DETECT = 32;
static const uint32_t CPMS_FDCR_LARGE_DROOP_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_SMALL_DROOP_DETECT = 36;
static const uint32_t CPMS_FDCR_SMALL_DROOP_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_SLOPEA_START_DETECT = 40;
static const uint32_t CPMS_FDCR_SLOPEA_START_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_SLOPEA_END_DETECT = 44;
static const uint32_t CPMS_FDCR_SLOPEA_END_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_SLOPEB_START_DETECT = 48;
static const uint32_t CPMS_FDCR_SLOPEB_START_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_SLOPEB_END_DETECT = 52;
static const uint32_t CPMS_FDCR_SLOPEB_END_DETECT_LEN = 4;
static const uint32_t CPMS_FDCR_SLOPEA_CYCLES = 56;
static const uint32_t CPMS_FDCR_SLOPEA_CYCLES_LEN = 4;
static const uint32_t CPMS_FDCR_SLOPEB_CYCLES = 60;
static const uint32_t CPMS_FDCR_SLOPEB_CYCLES_LEN = 4;
//<< [CPMS_FDCR]
// c/reg00003.H

//>> [CPMS_PRSR]
static const uint64_t CPMS_PRSR = 0x200e0eacull;

static const uint32_t CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN = 0;
static const uint32_t CPMS_PRSR_CPMS_PPSR_PERIOD_PROXY_REMAIN_LEN = 20;
//<< [CPMS_PRSR]
// c/reg00003.H

//>> [EC_PC_FIR_RAM_CTRL]
static const uint64_t EC_PC_FIR_RAM_CTRL = 0x2002044full;

static const uint32_t EC_PC_FIR_RAM_CTRL_RAM_VTID = 0;
static const uint32_t EC_PC_FIR_RAM_CTRL_RAM_VTID_LEN = 2;
static const uint32_t EC_PC_FIR_RAM_CTRL_PPC_PREDCD = 2;
static const uint32_t EC_PC_FIR_RAM_CTRL_PPC_PREDCD_LEN = 4;
static const uint32_t EC_PC_FIR_RAM_CTRL_SPARE = 6;
static const uint32_t EC_PC_FIR_RAM_CTRL_SPARE_LEN = 2;
static const uint32_t EC_PC_FIR_RAM_CTRL_PPC_INSTR = 8;
static const uint32_t EC_PC_FIR_RAM_CTRL_PPC_INSTR_LEN = 32;
//<< [EC_PC_FIR_RAM_CTRL]
// c/reg00003.H

//>> [EC_PC_FIR_RECOV_FWD_PROG_CTRL]
static const uint64_t EC_PC_FIR_RECOV_FWD_PROG_CTRL = 0x2002044bull;

static const uint32_t EC_PC_FIR_RECOV_FWD_PROG_CTRL_RESET_FWD_PROG = 0;
static const uint32_t EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD = 1;
static const uint32_t EC_PC_FIR_RECOV_FWD_PROG_CTRL_FWD_PROG_THOLD_LEN = 3;
//<< [EC_PC_FIR_RECOV_FWD_PROG_CTRL]
// c/reg00003.H

//>> [EC_PC_PMU_SPRCOR_HID]
static const uint64_t EC_PC_PMU_SPRCOR_HID = 0x20020415ull;

static const uint32_t EC_PC_PMU_SPRCOR_HID_ONE_PPC = 0;
static const uint32_t EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE = 1;
static const uint32_t EC_PC_PMU_SPRCOR_HID_FLUSH_IC = 2;
static const uint32_t EC_PC_PMU_SPRCOR_HID_EN_ATTN = 3;
static const uint32_t EC_PC_PMU_SPRCOR_HID_HILE = 4;
static const uint32_t EC_PC_PMU_SPRCOR_HID_DIS_RECOVERY = 5;
static const uint32_t EC_PC_PMU_SPRCOR_HID_MEGAMOUTH = 6;
static const uint32_t EC_PC_PMU_SPRCOR_HID_PREFETCH_RESET = 7;
static const uint32_t EC_PC_PMU_SPRCOR_HID_RADIX_MODE = 8;
static const uint32_t EC_PC_PMU_SPRCOR_HID_DCACHE_PARTITIONED = 9;
static const uint32_t EC_PC_PMU_SPRCOR_HID_ICACHE_PARTITIONED = 10;
static const uint32_t EC_PC_PMU_SPRCOR_HID_HID_SPARE_11 = 11;
static const uint32_t EC_PC_PMU_SPRCOR_HID_HID_SPARE_12 = 12;
static const uint32_t EC_PC_PMU_SPRCOR_HID_HID_SPARE_13 = 13;
static const uint32_t EC_PC_PMU_SPRCOR_HID_HID_SPARE_14 = 14;
static const uint32_t P10_20_EC_PC_PMU_SPRCOR_HID_P10_64K_OPT = 15; // p10:20,
static const uint32_t P10_20_EC_PC_PMU_SPRCOR_HID_HID_MU_CTXTTAG_EQ_TID = 16; // p10:20,
//<< [EC_PC_PMU_SPRCOR_HID]
// c/reg00003.H

//>> [L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG]
static const uint64_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG = 0x2002000eull;

static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TRIGGER = 0;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE = 1;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_TYPE_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_REG_BUSY = 9;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS = 10;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_PRGSM_BUSY = 11;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM = 16;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_MEM_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC = 19;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_CGC_LEN = 9;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_BANK = 28;
static const uint32_t L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG_ERR = 29;
//<< [L2_L2MISC_L2CERRS_PRD_PURGE_CMD_REG]
// c/reg00003.H

//>> [L3_MISC_L3CERRS_MODE_REG1]
static const uint64_t L3_MISC_L3CERRS_MODE_REG1 = 0x2001060aull;

static const uint32_t L3_MISC_L3CERRS_MODE_REG1_LCO_ENABLE_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG = 1;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_MY_LCO_TARGET_ID_CFG_LEN = 5;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG = 6;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_LCO_TARGETS_CFG_LEN = 32;
static const uint32_t L3_MISC_L3CERRS_MODE_REG1_CINJ_LCO_DIS_CFG = 38;
//<< [L3_MISC_L3CERRS_MODE_REG1]
// c/reg00003.H

//>> [QME_CDBA]
static const uint64_t QME_CDBA = 0x200e0800ull;

static const uint32_t QME_CDBA_MESSAGE_NUMBER = 0;
static const uint32_t QME_CDBA_MESSAGE_NUMBER_LEN = 8;
//<< [QME_CDBA]
// c/reg00003.H

//>> [QME_CSIR]
static const uint64_t QME_CSIR = 0x200e087cull;

static const uint32_t QME_CSIR_PMSR_INSTR_DATA = 36;
static const uint32_t QME_CSIR_PMSR_INSTR_DATA_LEN = 22;
//<< [QME_CSIR]
// c/reg00003.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00003.H"
#endif
#endif
