/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_8.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __p10_scom_pau_8_H_
#define __p10_scom_pau_8_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


//>> [CS_SM1_SNP_MISC_GENID_BAR]
static const uint64_t CS_SM1_SNP_MISC_GENID_BAR = 0x1001089dull;

static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE = 0;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1 = 2;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR = 3;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN = 30;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2 = 33;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON = 35;
//<< [CS_SM1_SNP_MISC_GENID_BAR]
// pau/reg00009.H

//>> [MISC_FENCE_STATE]
static const uint64_t MISC_FENCE_STATE = 0x10010b46ull;

static const uint32_t MISC_FENCE_STATE_0 = 0;
static const uint32_t MISC_FENCE_STATE_1 = 1;
static const uint32_t MISC_FENCE_STATE_2 = 2;
static const uint32_t MISC_FENCE_STATE_3 = 3;
static const uint32_t MISC_FENCE_STATE_4 = 4;
//<< [MISC_FENCE_STATE]
// pau/reg00009.H

//>> [CS_CTL_MISC_CONFIG2]
static const uint64_t CS_CTL_MISC_CONFIG2 = 0x10010982ull;

static const uint32_t CS_CTL_MISC_CONFIG2_BRK0_OCAPI_MODE = 0;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK1_OCAPI_MODE = 1;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK2_OCAPI_MODE = 2;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK3_OCAPI_MODE = 3;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK4_OCAPI_MODE = 4;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK0_NVLINK_MODE = 5;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK1_NVLINK_MODE = 6;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK2_NVLINK_MODE = 7;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK3_NVLINK_MODE = 8;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK4_NVLINK_MODE = 9;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4 = 10;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_4 = 10;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4 = 11;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_4 = 11;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4 = 12;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_4 = 12;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4 = 13;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_4 = 13;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4 = 14;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_4 = 14;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_C2 = 15;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_C2 = 16;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_C2 = 17;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_C2 = 18;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_C2 = 19;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO = 20;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK0_OCAPI_AMO = 20;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO = 21;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK1_OCAPI_AMO = 21;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO = 22;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK2_OCAPI_AMO = 22;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO = 23;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK3_OCAPI_AMO = 23;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO = 24;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_BRK4_OCAPI_AMO = 24;
static const uint32_t CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0 = 25;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK0 = 25;
static const uint32_t CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1 = 26;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK1 = 26;
static const uint32_t CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2 = 27;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK2 = 27;
static const uint32_t CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3 = 28;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK3 = 28;
static const uint32_t CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4 = 29;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_WRITE_MEM_OS_BIT_BRK4 = 29;
static const uint32_t CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE = 30;
static const uint32_t CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE_LEN = 2;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE = 30;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_GENID_SYNC_SCOPE_LEN = 2;
static const uint32_t CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0 = 32;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_GENID_SYNC_FORCE_RCMD0 = 32;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK0_IMP_TAGS_MODE_ENABLE = 33;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK1_IMP_TAGS_MODE_ENABLE = 34;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK2_IMP_TAGS_MODE_ENABLE = 35;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK3_IMP_TAGS_MODE_ENABLE = 36;
static const uint32_t CS_CTL_MISC_CONFIG2_BRK4_IMP_TAGS_MODE_ENABLE = 37;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED = 38;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_CP_2CRED = 38;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED = 39;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_GP_2CRED = 39;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED = 40;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_SP_2CRED = 40;
static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK = 41;
// ERROR Duplicate Dial         static const uint32_t CS_CTL_MISC_CONFIG2_ENABLE_PB_BACK2BACK = 41;
static const uint32_t CS_CTL_MISC_CONFIG2_2_RESERVED1 = 42;
static const uint32_t CS_CTL_MISC_CONFIG2_2_RESERVED1_LEN = 6;
static const uint32_t P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW531747_CAS_T_IMP_TAGS = 42; // p10:20,
static const uint32_t P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539321_SM_REQIN_CREDIT_DROP = 43; // p10:20,
static const uint32_t P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW539464_BACK_TO_SYNC_DONE = 44; // p10:20,
static const uint32_t P10_20_CS_CTL_MISC_CONFIG2_ENABLE_HW549830_MI_RETRY_NON_CP = 45; // p10:20,
static const uint32_t P10_20_CS_CTL_MISC_CONFIG2_DISABLE_HW551717_ZERO_CO_FIELD = 46; // p10:20,
static const uint32_t P10_20_CS_CTL_MISC_CONFIG2_2_RESERVED1 = 47; // p10:20,
static const uint32_t CS_CTL_MISC_CONFIG2_GENID_RATE_INC = 48;
static const uint32_t CS_CTL_MISC_CONFIG2_GENID_RATE_INC_LEN = 8;
static const uint32_t CS_CTL_MISC_CONFIG2_GENID_RATE_DEC = 56;
static const uint32_t CS_CTL_MISC_CONFIG2_GENID_RATE_DEC_LEN = 8;
//<< [CS_CTL_MISC_CONFIG2]
// pau/reg00009.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00009.H"
#include "pau/reg00010.H"
#endif
#endif
