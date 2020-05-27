/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_9.H $        */
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

#ifndef __p10_scom_mcc_9_H_
#define __p10_scom_mcc_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [DSTL_DSTLFIRMASK]
static const uint64_t DSTL_DSTLFIRMASK_RW = 0x0c010d03ull;
static const uint64_t DSTL_DSTLFIRMASK_WO_AND = 0x0c010d04ull;
static const uint64_t DSTL_DSTLFIRMASK_WO_OR = 0x0c010d05ull;

static const uint32_t DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK = 0;
static const uint32_t DSTL_DSTLFIRMASK_DSTLFIRMASK_FIR_MASK_LEN = 39;
//<< [DSTL_DSTLFIRMASK]
// mcc/reg00009.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00009.H"
#endif
#endif
