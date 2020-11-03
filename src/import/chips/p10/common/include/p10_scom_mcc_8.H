/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_8.H $        */
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

#ifndef __p10_scom_mcc_8_H_
#define __p10_scom_mcc_8_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [ATCL_CL_CLSCOM_MCEPSQ]
static const uint64_t ATCL_CL_CLSCOM_MCEPSQ = 0x0c010c26ull;

static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON = 0;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_JITTER_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_LOCAL_NODE_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON = 16;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_NEAR_NODAL_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON = 24;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_GROUP_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON = 32;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_REMOTE_NODAL_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON = 40;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_VECTOR_GROUP_EPSILON_LEN = 8;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON = 48;
static const uint32_t ATCL_CL_CLSCOM_MCEPSQ_EPF_EPSILON_LEN = 8;
//<< [ATCL_CL_CLSCOM_MCEPSQ]
// mcc/reg00008.H

//>> [CRYPTO_DECRYPT_CRYPTOKEY2B]
static const uint64_t CRYPTO_DECRYPT_CRYPTOKEY2B = 0x0c010f5dull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY2B_KEY2B_LEN = 64;
//<< [CRYPTO_DECRYPT_CRYPTOKEY2B]
// mcc/reg00008.H

//>> [CRYPTO_ENCRYPT_CRYPTOCFG]
static const uint64_t CRYPTO_ENCRYPT_CRYPTOCFG = 0x0c010f50ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS = 1;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_RESET_KEEPER = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_ENABLE = 4;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTO_SELECT = 5;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11 = 6;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_SPARE_6_11_LEN = 6;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ = 12;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW0_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ = 14;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW1_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ = 16;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW2_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ = 18;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW3_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW0_SUE_INJ = 20;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW1_SUE_INJ = 21;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW2_SUE_INJ = 22;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_DW3_SUE_INJ = 23;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_ONE_SHOT_INJ = 24;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_PERSISTANT_INJ = 25;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE = 26;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOCFG_CRYPTOCFG_26_31_SPARE_LEN = 6;
//<< [CRYPTO_ENCRYPT_CRYPTOCFG]
// mcc/reg00008.H

//>> [USTL_USTLFIRACT0]
static const uint64_t USTL_USTLFIRACT0 = 0x0c010e06ull;

static const uint32_t USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0 = 0;
static const uint32_t USTL_USTLFIRACT0_USTLFIRACT0_ACTION_0_LEN = 62;
//<< [USTL_USTLFIRACT0]
// mcc/reg00008.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00008.H"
#endif
#endif
