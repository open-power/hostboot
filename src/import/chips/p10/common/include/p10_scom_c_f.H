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
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_VTB_P_HOLD_OUT = 30;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT = 31;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_DEC_P_HOLD_OUT_LEN = 4;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_HDEC_P_HOLD_OUT = 35;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT = 36;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_PURR_P_HOLD_OUT_LEN = 4;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT = 40;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SPURR_P_HOLD_OUT_LEN = 4;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_COMMON_SCOM_HOLD_OUT = 44;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT = 45;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFX_SPR_TFAC_XFER_HOLD_OUT_LEN = 3;
static const uint32_t EC_PC_COMMON_SPR_TFAC_HOLD_OUT_TFR_SPR_RFC_SCR_P_HOLD_OUT = 48;
//<< [EC_PC_COMMON_SPR_TFAC_HOLD_OUT]
// c/reg00015.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00015.H"
#endif
#endif
