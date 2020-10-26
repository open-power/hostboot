/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_5.H $        */
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

#ifndef __p10_scom_mcc_5_H_
#define __p10_scom_mcc_5_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [CRYPTO_DECRYPT_CRYPTONONCEA]
static const uint64_t CRYPTO_DECRYPT_CRYPTONONCEA = 0x0c010f5eull;

static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA_LEN = 64;
//<< [CRYPTO_DECRYPT_CRYPTONONCEA]
// mcc/reg00005.H

//>> [CRYPTO_ENCRYPT_CRYPTONONCEB]
static const uint64_t CRYPTO_ENCRYPT_CRYPTONONCEB = 0x0c010f57ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB_LEN = 24;
//<< [CRYPTO_ENCRYPT_CRYPTONONCEB]
// mcc/reg00005.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00005.H"
#endif
#endif
