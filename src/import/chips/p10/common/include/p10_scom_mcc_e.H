/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_e.H $        */
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

#ifndef __p10_scom_mcc_e_H_
#define __p10_scom_mcc_e_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [USTL_USTLFIRACT1]
static const uint64_t USTL_USTLFIRACT1 = 0x0c010e07ull;

static const uint32_t USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1 = 0;
static const uint32_t USTL_USTLFIRACT1_USTLFIRACT1_ACTION_1_LEN = 62;
//<< [USTL_USTLFIRACT1]
// mcc/reg00014.H

//>> [CRYPTO_ENCRYPT_CRYPTOKEY2B]
static const uint64_t CRYPTO_ENCRYPT_CRYPTOKEY2B = 0x0c010f55ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B_LEN = 64;
//<< [CRYPTO_ENCRYPT_CRYPTOKEY2B]
// mcc/reg00014.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00014.H"
#endif
#endif
