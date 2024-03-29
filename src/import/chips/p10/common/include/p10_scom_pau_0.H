/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_0.H $        */
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

#ifndef __p10_scom_pau_0_H_
#define __p10_scom_pau_0_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> [MISC_REGS_OPTICAL_IO_CONFIG]
static const uint64_t MISC_REGS_OPTICAL_IO_CONFIG = 0x10010b33ull;

static const uint32_t MISC_REGS_OPTICAL_IO_CONFIG_NTL0_NOT_OTH = 0;
static const uint32_t MISC_REGS_OPTICAL_IO_CONFIG_NTL1_NOT_OTH = 1;
static const uint32_t MISC_REGS_OPTICAL_IO_CONFIG_OTL0_NOT_OTH = 2;
static const uint32_t MISC_REGS_OPTICAL_IO_CONFIG_OTL1_NOT_OTH = 3;
//<< [MISC_REGS_OPTICAL_IO_CONFIG]
// pau/reg00000.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00000.H"
#endif
#endif
