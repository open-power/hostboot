/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_2.H $         */
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

#ifndef __p10_scom_eq_2_H_
#define __p10_scom_eq_2_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [CPLT_STAT0]
static const uint64_t CPLT_STAT0 = 0x20000100ull;

static const uint32_t CPLT_STAT0_ABIST_DONE_DC = 0;
static const uint32_t CPLT_STAT0_EBIST_DONE_DC = 1;
static const uint32_t CPLT_STAT0_RESERVED_2I = 2;
static const uint32_t CPLT_STAT0_RESERVED_3I = 3;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT0_OUT = 4;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT1_OUT = 5;
static const uint32_t CPLT_STAT0_RESERVED_6I = 6;
static const uint32_t CPLT_STAT0_CC_CTRL_OPCG_DONE_DC = 8;
static const uint32_t CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC = 9;
static const uint32_t CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR = 10;
static const uint32_t CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR = 11;
static const uint32_t CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED = 12;
static const uint32_t CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT = 13;
static const uint32_t CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT_LEN = 10;
static const uint32_t CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID = 23;
static const uint32_t CPLT_STAT0_GLOBAL_FEH_DC = 24;
static const uint32_t CPLT_STAT0_FREE_USAGE_25I = 25;
static const uint32_t CPLT_STAT0_FREE_USAGE_26I = 26;
static const uint32_t CPLT_STAT0_FREE_USAGE_27I = 27;
static const uint32_t CPLT_STAT0_FREE_USAGE_28I = 28;
static const uint32_t CPLT_STAT0_FREE_USAGE_29I = 29;
static const uint32_t CPLT_STAT0_FREE_USAGE_30I = 30;
static const uint32_t CPLT_STAT0_FREE_USAGE_31I = 31;
//<< [CPLT_STAT0]
// eq/reg00002.H

//>> [EPS_THERM_WSUB2_MODE_REG]
static const uint64_t EPS_THERM_WSUB2_MODE_REG = 0x2005002full;

static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR = 0;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT = 1;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA = 2;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA = 5;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT = 6;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN = 4;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA = 10;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE = 12;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL = 13;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK = 14;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL = 16;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL_LEN = 4;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1 = 20;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2 = 24;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 = 28;
//<< [EPS_THERM_WSUB2_MODE_REG]
// eq/reg00002.H

//>> [QME_DUCR]
static const uint64_t QME_DUCR = 0x200e0170ull;

static const uint32_t QME_DUCR_FDCR_DELAY_C0 = 0;
static const uint32_t QME_DUCR_FDCR_DELAY_C0_LEN = 8;
static const uint32_t QME_DUCR_FDCR_DELAY_C1 = 8;
static const uint32_t QME_DUCR_FDCR_DELAY_C1_LEN = 8;
static const uint32_t QME_DUCR_FDCR_DELAY_C2 = 16;
static const uint32_t QME_DUCR_FDCR_DELAY_C2_LEN = 8;
static const uint32_t QME_DUCR_FDCR_DELAY_C3 = 24;
static const uint32_t QME_DUCR_FDCR_DELAY_C3_LEN = 8;
static const uint32_t QME_DUCR_FDCR_CAL_ADJUST_C0 = 32;
static const uint32_t QME_DUCR_FDCR_CAL_ADJUST_C0_LEN = 2;
static const uint32_t QME_DUCR_FDCR_CAL_ADJUST_C1 = 34;
static const uint32_t QME_DUCR_FDCR_CAL_ADJUST_C1_LEN = 2;
static const uint32_t QME_DUCR_FDCR_CAL_ADJUST_C2 = 36;
static const uint32_t QME_DUCR_FDCR_CAL_ADJUST_C2_LEN = 2;
static const uint32_t QME_DUCR_FDCR_CAL_ADJUST_C3 = 38;
static const uint32_t QME_DUCR_FDCR_CAL_ADJUST_C3_LEN = 2;
static const uint32_t QME_DUCR_CORE_UPDATE_ENABLE = 40;
static const uint32_t QME_DUCR_CORE_UPDATE_ENABLE_LEN = 4;
static const uint32_t QME_DUCR_RESERVED_44_63 = 44;
static const uint32_t QME_DUCR_RESERVED_44_63_LEN = 20;
//<< [QME_DUCR]
// eq/reg00002.H

//>> [QME_EISR]
static const uint64_t QME_EISR_RW = 0x200e0260ull;
static const uint64_t QME_EISR_WO_CLEAR = 0x200e0263ull;
static const uint64_t QME_EISR_WO_OR = 0x200e0262ull;

static const uint32_t QME_EISR_DEBUGGER = 0;
static const uint32_t QME_EISR_DEBUG_TRIGGER = 1;
static const uint32_t QME_EISR_SYSTEM_CHECKSTOP = 2;
static const uint32_t QME_EISR_LFIR_INDICATION = 3;
static const uint32_t QME_EISR_QOS_UPDATE = 4;
static const uint32_t QME_EISR_QOS_UPDATE_LEN = 4;
static const uint32_t QME_EISR_BCE_BUSY = 8;
static const uint32_t QME_EISR_RS4_BUSY = 9;
static const uint32_t QME_EISR_RESCLK_TARGET_ASSIST = 10;
static const uint32_t QME_EISR_RESCLK_DONE_ASSIST = 11;
static const uint32_t QME_EISR_PITCH_UPDATE = 12;
static const uint32_t QME_EISR_WOCR_UPDATE = 13;
static const uint32_t QME_EISR_TBR_CYCLES_ROLLED = 14;
static const uint32_t QME_EISR_TBR_TIMEBASE_ROLLED = 15;
static const uint32_t QME_EISR_DOORBELL_0 = 16;
static const uint32_t QME_EISR_DOORBELL_1 = 17;
static const uint32_t QME_EISR_DOORBELL_2 = 18;
static const uint32_t QME_EISR_PMCR_UPDATE = 19;
static const uint32_t QME_EISR_DOORBELL_A = 20;
static const uint32_t QME_EISR_DOORBELL_A_LEN = 4;
static const uint32_t QME_EISR_DOORBELL_3 = 20; // p10:20,
static const uint32_t QME_EISR_DOORBELL_4 = 21; // p10:20,
static const uint32_t QME_EISR_SPAREA = 22; // p10:20,
static const uint32_t QME_EISR_SPAREA_LEN = 2;
static const uint32_t QME_EISR_DOORBELL_B = 24;
static const uint32_t QME_EISR_DOORBELL_B_LEN = 4;
static const uint32_t QME_EISR_SPAREB = 24; // p10:20,
static const uint32_t QME_EISR_SPAREB_LEN = 4;
static const uint32_t QME_EISR_MMA_ACTIVE = 28;
static const uint32_t QME_EISR_MMA_ACTIVE_LEN = 4;
static const uint32_t QME_EISR_SPC_WKUP_RISE = 32;
static const uint32_t QME_EISR_SPC_WKUP_RISE_LEN = 4;
static const uint32_t QME_EISR_SPC_WKUP_FALL = 36;
static const uint32_t QME_EISR_SPC_WKUP_FALL_LEN = 4;
static const uint32_t QME_EISR_REG_WKUP_HIPRI = 40;
static const uint32_t QME_EISR_REG_WKUP_HIPRI_LEN = 4;
static const uint32_t QME_EISR_REG_WKUP_LOPRI = 44;
static const uint32_t QME_EISR_REG_WKUP_LOPRI_LEN = 4;
static const uint32_t QME_EISR_PM_STATE_ACTIVE_HIPRI = 48;
static const uint32_t QME_EISR_PM_STATE_ACTIVE_HIPRI_LEN = 4;
static const uint32_t QME_EISR_PM_STATE_ACTIVE_LOPRI = 52;
static const uint32_t QME_EISR_PM_STATE_ACTIVE_LOPRI_LEN = 4;
static const uint32_t QME_EISR_CPMS_INTERRUPT0 = 56;
static const uint32_t QME_EISR_CPMS_INTERRUPT0_LEN = 4;
static const uint32_t QME_EISR_CPMS_INTERRUPT1 = 60;
static const uint32_t QME_EISR_CPMS_INTERRUPT1_LEN = 4;
//<< [QME_EISR]
// eq/reg00002.H

//>> [QME_LFIRACT1]
static const uint64_t QME_LFIRACT1 = 0x200e000cull;

static const uint32_t QME_LFIRACT1_FIR_ACTION1 = 0;
static const uint32_t QME_LFIRACT1_FIR_ACTION1_LEN = 36;
//<< [QME_LFIRACT1]
// eq/reg00002.H

//>> [QME_SCOM_XIICAC]
static const uint64_t QME_SCOM_XIICAC = 0x200e0224ull;

static const uint32_t QME_SCOM_XIICAC_ICACHE_TAG_ADDR = 0;
static const uint32_t QME_SCOM_XIICAC_ICACHE_TAG_ADDR_LEN = 27;
static const uint32_t QME_SCOM_XIICAC_ICACHE_ERR = 32;
static const uint32_t QME_SCOM_XIICAC_QME_SCOM_XISIB_PIB_IFETCH_PENDING = 34;
static const uint32_t QME_SCOM_XIICAC_QME_SCOM_XIMEM_MEM_IFETCH_PENDING = 35;
static const uint32_t QME_SCOM_XIICAC_ICACHE_VALID = 36;
static const uint32_t QME_SCOM_XIICAC_ICACHE_VALID_LEN = 4;
//<< [QME_SCOM_XIICAC]
// eq/reg00002.H

//>> [QME_SCOM_XISGB]
static const uint64_t QME_SCOM_XISGB = 0x200e0220ull;

static const uint32_t QME_SCOM_XISGB_STORE_ADDRESS = 0;
static const uint32_t QME_SCOM_XISGB_STORE_ADDRESS_LEN = 32;
static const uint32_t QME_SCOM_XISGB_QME_SCOM_XIMEM_MEM_IMPRECISE_ERROR_PENDING = 35;
static const uint32_t QME_SCOM_XISGB_SGB_BYTE_VALID = 36;
static const uint32_t QME_SCOM_XISGB_SGB_BYTE_VALID_LEN = 4;
static const uint32_t QME_SCOM_XISGB_SGB_FLUSH_PENDING = 63;
//<< [QME_SCOM_XISGB]
// eq/reg00002.H

//>> [QME_SCRB]
static const uint64_t QME_SCRB_RW = 0x200e0128ull;
static const uint64_t QME_SCRB_WO_CLEAR = 0x200e012bull;
static const uint64_t QME_SCRB_WO_OR = 0x200e012aull;

static const uint32_t QME_SCRB_DATA = 0;
static const uint32_t QME_SCRB_DATA_LEN = 32;
//<< [QME_SCRB]
// eq/reg00002.H

//>> [QME_THOR]
static const uint64_t QME_THOR = 0x200e0098ull;

static const uint32_t QME_THOR_TSR_OVERRIDE_EN = 0;
static const uint32_t QME_THOR_PTSR_OVERRIDE_SEL = 1;
static const uint32_t QME_THOR_TSR_OVERRIDE_VAL = 4;
static const uint32_t QME_THOR_TSR_OVERRIDE_VAL_LEN = 8;
//<< [QME_THOR]
// eq/reg00002.H

//>> [SPATTN]
static const uint64_t SPATTN = 0x20040002ull;

static const uint32_t SPATTN_ANY_SPATTN = 0;
static const uint32_t SPATTN_RESERVED1S = 1;
static const uint32_t SPATTN_RESERVED2S = 2;
static const uint32_t SPATTN_RESERVED3S = 3;
static const uint32_t SPATTN_PERV = 4;
static const uint32_t SPATTN_IN05 = 5;
static const uint32_t SPATTN_IN06 = 6;
static const uint32_t SPATTN_IN07 = 7;
static const uint32_t SPATTN_IN08 = 8;
static const uint32_t SPATTN_IN09 = 9;
static const uint32_t SPATTN_IN10 = 10;
static const uint32_t SPATTN_IN11 = 11;
static const uint32_t SPATTN_IN12 = 12;
static const uint32_t SPATTN_IN13 = 13;
static const uint32_t SPATTN_IN14 = 14;
static const uint32_t SPATTN_IN15 = 15;
static const uint32_t SPATTN_IN16 = 16;
static const uint32_t SPATTN_IN17 = 17;
static const uint32_t SPATTN_IN18 = 18;
static const uint32_t SPATTN_IN19 = 19;
static const uint32_t SPATTN_IN20 = 20;
static const uint32_t SPATTN_IN21 = 21;
static const uint32_t SPATTN_IN22 = 22;
static const uint32_t SPATTN_IN23 = 23;
static const uint32_t SPATTN_IN24 = 24;
static const uint32_t SPATTN_IN25 = 25;
static const uint32_t SPATTN_IN26 = 26;
static const uint32_t SPATTN_IN27 = 27;
static const uint32_t SPATTN_IN28 = 28;
static const uint32_t SPATTN_IN29 = 29;
static const uint32_t SPATTN_IN30 = 30;
static const uint32_t SPATTN_IN31 = 31;
static const uint32_t SPATTN_IN32 = 32;
static const uint32_t SPATTN_IN33 = 33;
static const uint32_t SPATTN_IN34 = 34;
static const uint32_t SPATTN_IN35 = 35;
//<< [SPATTN]
// eq/reg00002.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00002.H"
#endif
#endif
