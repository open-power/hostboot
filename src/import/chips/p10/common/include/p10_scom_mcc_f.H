/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_f.H $        */
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

#ifndef __p10_scom_mcc_f_H_
#define __p10_scom_mcc_f_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [CRYPTO_DECRYPT_CRYPTONONCEB]
static const uint64_t CRYPTO_DECRYPT_CRYPTONONCEB = 0x0c010f5full;

static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB_LEN = 24;
//<< [CRYPTO_DECRYPT_CRYPTONONCEB]
// mcc/reg00015.H

//>> [CRYPTO_ENCRYPT_CRYPTONONCEA]
static const uint64_t CRYPTO_ENCRYPT_CRYPTONONCEA = 0x0c010f56ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA_LEN = 64;
//<< [CRYPTO_ENCRYPT_CRYPTONONCEA]
// mcc/reg00015.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00015.H"
#endif
#endif
