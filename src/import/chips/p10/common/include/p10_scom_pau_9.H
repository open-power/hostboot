/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_9.H $        */
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

#ifndef __p10_scom_pau_9_H_
#define __p10_scom_pau_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> [XSL_MAIN_GPU0_BAR]
static const uint64_t XSL_MAIN_GPU0_BAR = 0x10010a9aull;

static const uint32_t XSL_MAIN_GPU0_BAR_ENABLE = 0;
static const uint32_t XSL_MAIN_GPU0_BAR_ADDR_MASK = 1;
static const uint32_t XSL_MAIN_GPU0_BAR_ADDR_MASK_LEN = 35;
static const uint32_t XSL_MAIN_GPU0_BAR_SL_MODE = 36;
static const uint32_t XSL_MAIN_GPU0_BAR_4T_LIMIT = 37;
static const uint32_t XSL_MAIN_GPU0_BAR_4T_SELECT = 38;
static const uint32_t XSL_MAIN_GPU0_BAR_4T_SELECT_LEN = 2;
static const uint32_t XSL_MAIN_GPU0_BAR_MODE = 40;
static const uint32_t XSL_MAIN_GPU0_BAR_MODE_LEN = 4;
static const uint32_t XSL_MAIN_GPU0_BAR_GRANULE = 44;
static const uint32_t XSL_MAIN_GPU0_BAR_POISON = 45;
static const uint32_t XSL_MAIN_GPU0_BAR_M2MODE = 46;
static const uint32_t XSL_MAIN_GPU0_BAR_PA_IGNORE_MODE = 47;
static const uint32_t XSL_MAIN_GPU0_BAR_SECURE_A12 = 48;
static const uint32_t XSL_MAIN_GPU0_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t XSL_MAIN_GPU0_BAR_EXTENDED_MODE = 50;
static const uint32_t XSL_MAIN_GPU0_BAR_RESERVED = 51;
//<< [XSL_MAIN_GPU0_BAR]
// pau/reg00011.H

//>> [XSL_MAIN_GPU1_BAR]
static const uint64_t XSL_MAIN_GPU1_BAR = 0x10010a9bull;

static const uint32_t XSL_MAIN_GPU1_BAR_ENABLE = 0;
static const uint32_t XSL_MAIN_GPU1_BAR_ADDR_MASK = 1;
static const uint32_t XSL_MAIN_GPU1_BAR_ADDR_MASK_LEN = 35;
static const uint32_t XSL_MAIN_GPU1_BAR_SL_MODE = 36;
static const uint32_t XSL_MAIN_GPU1_BAR_4T_LIMIT = 37;
static const uint32_t XSL_MAIN_GPU1_BAR_4T_SELECT = 38;
static const uint32_t XSL_MAIN_GPU1_BAR_4T_SELECT_LEN = 2;
static const uint32_t XSL_MAIN_GPU1_BAR_MODE = 40;
static const uint32_t XSL_MAIN_GPU1_BAR_MODE_LEN = 4;
static const uint32_t XSL_MAIN_GPU1_BAR_GRANULE = 44;
static const uint32_t XSL_MAIN_GPU1_BAR_POISON = 45;
static const uint32_t XSL_MAIN_GPU1_BAR_M2MODE = 46;
static const uint32_t XSL_MAIN_GPU1_BAR_PA_IGNORE_MODE = 47;
static const uint32_t XSL_MAIN_GPU1_BAR_SECURE_A12 = 48;
static const uint32_t XSL_MAIN_GPU1_BAR_CHIP_EQ_GROUP = 49;
static const uint32_t XSL_MAIN_GPU1_BAR_EXTENDED_MODE = 50;
static const uint32_t XSL_MAIN_GPU1_BAR_RESERVED = 51;
//<< [XSL_MAIN_GPU1_BAR]
// pau/reg00011.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00011.H"
#endif
#endif
