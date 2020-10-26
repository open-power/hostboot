/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_b.H $        */
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

#ifndef __p10_scom_mcc_b_H_
#define __p10_scom_mcc_b_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [DSTL_DSTLFIR]
static const uint64_t DSTL_DSTLFIR_RW = 0x0c010d00ull;
static const uint64_t DSTL_DSTLFIR_WO_AND = 0x0c010d01ull;
static const uint64_t DSTL_DSTLFIR_WO_OR = 0x0c010d02ull;

static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP = 0;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION = 1;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION = 2;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT = 3;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP = 4;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION = 5;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION = 6;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT = 7;
static const uint32_t DSTL_DSTLFIR_MCS_DSTL_CMD_PARITY_ERROR = 8;
static const uint32_t DSTL_DSTLFIR_RESET_CREDITS_RD_WDF_BUFFER_NONZERO = 9;
static const uint32_t DSTL_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR = 10;
static const uint32_t DSTL_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR = 11;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR = 12;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR = 13;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_TIMEOUT_ERROR = 14;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_TIMEOUT_ERROR = 15;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR = 16;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR = 17;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_DL_LINK_DOWN = 18;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_DL_LINK_DOWN = 19;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION = 20;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION = 21;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_CHANNEL_TIMEOUT = 22;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_CHANNEL_TIMEOUT = 23;
static const uint32_t DSTL_DSTLFIR_DECRYPT_ERR_INFO = 24;
static const uint32_t DSTL_DSTLFIR_DECRYPT_ERR_INFO_LEN = 5;
static const uint32_t DSTL_DSTLFIR_ENCRYPT_ERR_INFO = 29;
static const uint32_t DSTL_DSTLFIR_ENCRYPT_ERR_INFO_LEN = 4;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED = 33;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED = 34;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_PARITY_ERROR = 35;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_PARITY_ERROR = 36;
static const uint32_t DSTL_DSTLFIR_SPARE37 = 37;
static const uint32_t DSTL_DSTLFIR_SPARE38 = 38;
//<< [DSTL_DSTLFIR]
// mcc/reg00011.H

//>> [CRYPTO_DECRYPT_CRYPTOKEY1B]
static const uint64_t CRYPTO_DECRYPT_CRYPTOKEY1B = 0x0c010f5bull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B_LEN = 64;
//<< [CRYPTO_DECRYPT_CRYPTOKEY1B]
// mcc/reg00011.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00011.H"
#endif
#endif
