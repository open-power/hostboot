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


//>> [EC_PC_FIR_RAM_STATUS]
static const uint64_t EC_PC_FIR_RAM_STATUS = 0x20020450ull;

static const uint32_t EC_PC_FIR_RAM_STATUS_RAM_CONTROL_ACCESS_DURING_RECOV = 0;
static const uint32_t EC_PC_FIR_RAM_STATUS_RAM_COMPLETION = 1;
static const uint32_t EC_PC_FIR_RAM_STATUS_RAM_EXCEPTION = 2;
static const uint32_t EC_PC_FIR_RAM_STATUS_LSU_EMPTY = 3;
//<< [EC_PC_FIR_RAM_STATUS]
// c/reg00010.H

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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00010.H"
#endif
#endif
