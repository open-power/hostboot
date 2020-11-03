/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_f.H $          */
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

#ifndef __p10_scom_c_f_H_
#define __p10_scom_c_f_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> [CPMS_ACCR]
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
//<< [CPMS_ACCR]
// c/reg00015.H

//>> [CPMS_MMAR]
static const uint64_t CPMS_MMAR = 0x200e0e38ull;
static const uint64_t CPMS_MMAR_SCOM2 = 0x200e0e3aull;
static const uint64_t CPMS_MMAR_WO_CLEAR = 0x200e0e3bull;

static const uint32_t CPMS_MMAR_AVAILABLE = 0;
static const uint32_t CPMS_MMAR_FUNC_RESET = 1;
static const uint32_t CPMS_MMAR_LIMIT = 2;
static const uint32_t CPMS_MMAR_LIMIT_LEN = 2;
static const uint32_t CPMS_MMAR_LIMIT_UPDATE_SELECT = 4;
static const uint32_t CPMS_MMAR_DIRTY = 32;
//<< [CPMS_MMAR]
// c/reg00015.H

//>> [CPMS_SDSR]
static const uint64_t CPMS_SDSR = 0x200e0e68ull;

static const uint32_t CPMS_SDSR_DDS_DATA = 0;
static const uint32_t CPMS_SDSR_DDS_DATA_LEN = 5;
static const uint32_t CPMS_SDSR_CPMS_DDSR_DDS_DATA = 0; // p10:20,
static const uint32_t CPMS_SDSR_CPMS_DDSR_DDS_DATA_LEN = 5;
static const uint32_t CPMS_SDSR_DDS_MIN = 5;
static const uint32_t CPMS_SDSR_DDS_MIN_LEN = 5;
// ERROR Duplicate Dial         static const uint32_t CPMS_SDSR_DDS_MIN = 5; // p10:20,
// ERROR Duplicate Dial         static const uint32_t CPMS_SDSR_DDS_MIN_LEN = 5;
static const uint32_t CPMS_SDSR_DDS_MAX = 10;
static const uint32_t CPMS_SDSR_DDS_MAX_LEN = 5;
// ERROR Duplicate Dial         static const uint32_t CPMS_SDSR_DDS_MAX = 10; // p10:20,
// ERROR Duplicate Dial         static const uint32_t CPMS_SDSR_DDS_MAX_LEN = 5;
static const uint32_t CPMS_SDSR_SAMPLE_DISABLE_OCCURRED = 15;
// ERROR Duplicate Dial         static const uint32_t CPMS_SDSR_SAMPLE_DISABLE_OCCURRED = 15; // p10:20,
static const uint32_t CPMS_SDSR_STOP_STATE_OCCURRED = 16; // p10:20,
//<< [CPMS_SDSR]
// c/reg00015.H

//>> [EC_PC_COMMON_SPR_TFAC_HOLD_OUT]
static const uint64_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT = 0x200204b7ull;

static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT = 0;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_CONTROL_HOLD_OUT_LEN = 2;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT = 2;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_FIRMWARE_CONTROL_HOLD_OUT_LEN = 7;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT = 9;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_PURR_ACCUM_OFLOW_HOLD_OUT_LEN = 4;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFP_SPR_SPURR_SCALE_LIMIT_HOLD_OUT = 13;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT = 14;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_OFLOW_HOLD_OUT_LEN = 4;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT = 18;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_OFLOW_HOLD_OUT_LEN = 4;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_TBST_CORRUPT_HOLD_OUT = 22;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFC_SPR_PCNT_TB_P_HOLD_OUT = 23;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT = 24;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_DEC_P_HOLD_OUT_LEN = 4;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFD_SPR_PCNT_HDEC_P_HOLD_OUT = 28;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_TB_P_HOLD_OUT = 29;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_TB_P_HOLD_OUT = 29; // p10:20,
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT = 30;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_VTB_P_HOLD_OUT = 30; // p10:20,
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT = 31;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT_LEN = 4;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT = 31; // p10:20,
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_DEC_P_HOLD_OUT_LEN = 4;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT = 35;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_HDEC_P_HOLD_OUT = 35; // p10:20,
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT = 36;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT_LEN = 4;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT = 36; // p10:20,
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_PURR_P_HOLD_OUT_LEN = 4;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT = 40;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT_LEN = 4;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT = 40; // p10:20,
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SPURR_P_HOLD_OUT_LEN = 4;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT = 44;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT = 45;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT_LEN = 3;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT = 48;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_SCR_P_HOLD_OUT = 48; // p10:20,
//<< [EC_PC_COMMON_SPR_TFAC_HOLD_OUT]
// c/reg00015.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00015.H"
#endif
#endif
