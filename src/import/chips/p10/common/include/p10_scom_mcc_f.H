/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_f.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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


static const uint64_t ATCL_CL_CLSCOM_MCEBUSCL = 0x0c010c29ull;

static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS0 = 0;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS1 = 1;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS2 = 2;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_CLS3 = 3;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTA = 4;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_SEL_EBUS_EVENTB = 5;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15 = 6;
static const uint32_t ATCL_CL_CLSCOM_MCEBUSCL_RESERVED6_15_LEN = 10;
// mcc/reg00015.H

static const uint64_t CRYPTO_DECRYPT_CRYPTONONCEB = 0x0c010f5full;

static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEB_NONCEB_LEN = 24;
// mcc/reg00015.H

static const uint64_t CRYPTO_ENCRYPT_CRYPTONONCEA = 0x0c010f56ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEA_NONCEA_LEN = 64;
// mcc/reg00015.H

static const uint64_t USTL_USTLLOLDROP = 0x0c010e11ull;

static const uint32_t USTL_USTLLOLDROP_A_DROP_REASON = 0;
static const uint32_t USTL_USTLLOLDROP_A_DROP_REASON_LEN = 22;
static const uint32_t USTL_USTLLOLDROP_B_DROP_REASON = 32;
static const uint32_t USTL_USTLLOLDROP_B_DROP_REASON_LEN = 22;
// mcc/reg00015.H

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00015.H"
#endif
#endif
