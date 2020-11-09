/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_1.H $        */
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

#ifndef __p10_scom_mcc_1_H_
#define __p10_scom_mcc_1_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [ATCL_CL_CLSCOM_MCPERF2]
static const uint64_t ATCL_CL_CLSCOM_MCPERF2 = 0x0c010c24ull;

static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0 = 0;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE0_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1 = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE1_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2 = 6;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE2_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3 = 9;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PF_DROP_VALUE3_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_DISABLE_DROPABLE = 12;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH = 13;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_THRESH_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PERF = 17;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_PERF_LEN = 2;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23 = 19;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RESERVED19_23_LEN = 5;
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCPERF2_HTM_ARMW_ADD_RSVD_P10D20 = 19; // p10:20,
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCPERF2_SPARE20_23 = 20; // p10:20,
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCPERF2_SPARE20_23_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL = 24;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_NSQ_LFSR_CNTL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL = 28;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_SQ_LFSR_CNTL_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_CMD_STALL = 32;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_RRQ_STALL = 33;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_WRQ_STALL = 34;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EN_CHARB_MERGE_STALL = 35;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RESERVED36 = 36;
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCPERF2_SPARE36 = 36; // p10:20,
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG = 37;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RCTRL_CONFIG_LEN = 3;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL = 40;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EPF_EPS_DEC_CNTL_LEN = 2;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL = 42;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_EPF_CL_LIMIT_MOD_CNTL_LEN = 2;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN = 44;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_NUM_CLEAN_LEN = 5;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RESERVED_49 = 49;
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCPERF2_SPARE_49 = 49; // p10:20,
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF = 50;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_NUM_RMW_BUF_LEN = 5;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH = 55;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RMW_BUF_THRESH_LEN = 4;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL = 59;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_BYP_RETRY_FULL_LEN = 2;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_DIS_NUM_CLEAN_MOD = 61;
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_RESERVED_62 = 62;
static const uint32_t P10_20_ATCL_CL_CLSCOM_MCPERF2_EN_DYN_RSVD_P10D20 = 62; // p10:20,
static const uint32_t ATCL_CL_CLSCOM_MCPERF2_LOAD_RSVD_VALUES = 63;
//<< [ATCL_CL_CLSCOM_MCPERF2]
// mcc/reg00001.H

//>> [CRYPTO_DECRYPT_CRYPTOKEY1A]
static const uint64_t CRYPTO_DECRYPT_CRYPTOKEY1A = 0x0c010f5aull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1A_KEY1A_LEN = 64;
//<< [CRYPTO_DECRYPT_CRYPTOKEY1A]
// mcc/reg00001.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00001.H"
#endif
#endif
