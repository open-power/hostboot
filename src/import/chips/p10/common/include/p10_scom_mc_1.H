/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_1.H $         */
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

#ifndef __p10_scom_mc_1_H_
#define __p10_scom_mc_1_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mc
{
#endif


//>> [OPCG_CAPT3]
static const uint64_t OPCG_CAPT3 = 0x0c030012ull;

static const uint32_t OPCG_CAPT3_07EVEN = 4;
static const uint32_t OPCG_CAPT3_07EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_07ODD = 9;
static const uint32_t OPCG_CAPT3_07ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_08EVEN = 14;
static const uint32_t OPCG_CAPT3_08EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_08ODD = 19;
static const uint32_t OPCG_CAPT3_08ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_09EVEN = 24;
static const uint32_t OPCG_CAPT3_09EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_09ODD = 29;
static const uint32_t OPCG_CAPT3_09ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_10EVEN = 34;
static const uint32_t OPCG_CAPT3_10EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_10ODD = 39;
static const uint32_t OPCG_CAPT3_10ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_11EVEN = 44;
static const uint32_t OPCG_CAPT3_11EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_11ODD = 49;
static const uint32_t OPCG_CAPT3_11ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_12EVEN = 54;
static const uint32_t OPCG_CAPT3_12EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_12ODD = 59;
static const uint32_t OPCG_CAPT3_12ODD_LEN = 5;
//<< [OPCG_CAPT3]
// mc/reg00001.H

//>> [SCAN32]
static const uint64_t SCAN32 = 0x0c038000ull;

static const uint32_t SCAN32_SCAN32_REG = 0;
static const uint32_t SCAN32_SCAN32_REG_LEN = 32;
//<< [SCAN32]
// mc/reg00001.H

//>> [SCAN64]
static const uint64_t SCAN64 = 0x0c03e000ull;

static const uint32_t SCAN64_SCAN64_REG = 0;
static const uint32_t SCAN64_SCAN64_REG_LEN = 64;
//<< [SCAN64]
// mc/reg00001.H

//>> [SCOMFIR_MCTO]
static const uint64_t SCOMFIR_MCTO = 0x0c010c1bull;

static const uint32_t SCOMFIR_MCTO_SELECT_PB_HANG_PULSE = 0;
static const uint32_t SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE = 1;
static const uint32_t SCOMFIR_MCTO_RPT_HANG_SELECT = 2;
static const uint32_t SCOMFIR_MCTO_RPT_HANG_SELECT_LEN = 2;
static const uint32_t SCOMFIR_MCTO_RESERVED_4 = 4;
static const uint32_t SCOMFIR_MCTO_CL_TIMEOUT_VALUE = 5;
static const uint32_t SCOMFIR_MCTO_CL_TIMEOUT_VALUE_LEN = 3;
static const uint32_t SCOMFIR_MCTO_LOCAL_HANG_COMP = 8;
static const uint32_t SCOMFIR_MCTO_LOCAL_HANG_COMP_LEN = 16;
static const uint32_t SCOMFIR_MCTO_HANG_COMP = 24;
static const uint32_t SCOMFIR_MCTO_HANG_COMP_LEN = 8;
static const uint32_t SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG = 32;
static const uint32_t SCOMFIR_MCTO_ENABLE_CHANNEL_HANG = 33;
static const uint32_t SCOMFIR_MCTO_ENABLE_APO_HANG = 34;
static const uint32_t SCOMFIR_MCTO_RESERVED_53 = 35;
static const uint32_t SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG = 36;
static const uint32_t SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE = 37;
static const uint32_t SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE_LEN = 3;
//<< [SCOMFIR_MCTO]
// mc/reg00001.H

//>> [TRA0_TR0_TRACE_HI_DATA_REG]
static const uint64_t TRA0_TR0_TRACE_HI_DATA_REG = 0x0c010400ull;

static const uint32_t TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
//<< [TRA0_TR0_TRACE_HI_DATA_REG]
// mc/reg00001.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mc/reg00001.H"
#endif
#endif
