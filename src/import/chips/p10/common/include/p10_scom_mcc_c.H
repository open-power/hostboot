/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_c.H $        */
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

#ifndef __p10_scom_mcc_c_H_
#define __p10_scom_mcc_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [DSTL_DSTLFIRACT0]
static const uint64_t DSTL_DSTLFIRACT0 = 0x0c010d06ull;

static const uint32_t DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 = 0;
static const uint32_t DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN = 39;
// ERROR Duplicate Dial         static const uint32_t DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0 = 0; // p10:20,
// ERROR Duplicate Dial         static const uint32_t DSTL_DSTLFIRACT0_DSTLFIRACT0_ACTION_0_LEN = 41;
//<< [DSTL_DSTLFIRACT0]
// mcc/reg00012.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00012.H"
#endif
#endif
