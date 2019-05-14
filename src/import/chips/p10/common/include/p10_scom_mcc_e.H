/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_e.H $        */
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

#include "proc_scomt.H"

#ifndef __p10_scom_mcc_e_H_
#define __p10_scom_mcc_e_H_


namespace scomt
{
namespace mcc
{


static const uint64_t CRYPTO_ENCRYPT_CRYPTOKEY2B = 0x0c010f55ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B_LEN = 64;
// mcc/reg00014.H

static const uint64_t USTL_USTLINJ = 0x0c010e0cull;

static const uint32_t USTL_USTLINJ_FAIL_RESP_TYPE = 3;
static const uint32_t USTL_USTLINJ_FAIL_RESP_TYPE_LEN = 3;
static const uint32_t USTL_USTLINJ_FIR_INJECT = 8;
static const uint32_t USTL_USTLINJ_FIR_INJECT_LEN = 5;
static const uint32_t USTL_USTLINJ_US_DATA = 20;
static const uint32_t USTL_USTLINJ_US_DATA_LEN = 3;
static const uint32_t USTL_USTLINJ_CHAN_SEL = 24;
static const uint32_t USTL_USTLINJ_US_DATA_ERR_EN = 26;
static const uint32_t USTL_USTLINJ_ONE_SHOT = 27;
static const uint32_t USTL_USTLINJ_DATA_OUT = 28;
static const uint32_t USTL_USTLINJ_DATA_DW_SEL = 29;
static const uint32_t USTL_USTLINJ_DATA_DW_SEL_LEN = 2;
// mcc/reg00014.H

}
}
#include "mcc/reg00014.H"
#endif
