/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_4.H $        */
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

#ifndef __p10_scom_mcc_4_H_
#define __p10_scom_mcc_4_H_


namespace scomt
{
namespace mcc
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ATCL_CL_CLSCOM_MCPERF4 = 0x0c010c32ull;

static const uint32_t ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_READ_RETRY = 0;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_EN_PSAVE_WRITE_RETRY = 1;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ = 2;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_READ_LEN = 7;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE = 9;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_CL_WRITE_LEN = 7;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF = 16;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_WRBUF_LEN = 7;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF = 23;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_PSAVE_NUM_RMWBUF_LEN = 7;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_RESERVED30_31 = 30;
static const uint32_t ATCL_CL_CLSCOM_MCPERF4_RESERVED30_31_LEN = 2;
// mcc/reg00068.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_ENCRYPT_CRYPTOKEY2A = 0x0c010f74ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY2A_KEY2A = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY2A_KEY2A_LEN = 64;
// mcc/reg00068.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t DSTL_DSTLCFG = 0x0c010d0bull;

static const uint32_t DSTL_DSTLCFG_TMPL0_ONLY = 0;
static const uint32_t DSTL_DSTLCFG_RESERVED_1 = 1;
static const uint32_t DSTL_DSTLCFG_TMPL7_ENABLE = 2;
static const uint32_t DSTL_DSTLCFG_TMPL1_DIS = 3;
static const uint32_t DSTL_DSTLCFG_FAST_RD_DISABLE = 4;
static const uint32_t DSTL_DSTLCFG_RESERVED_5 = 5;
static const uint32_t DSTL_DSTLCFG_TMPL4_DISABLE = 6;
static const uint32_t DSTL_DSTLCFG_SET_MDI_ON_2ND_DIS = 7;
static const uint32_t DSTL_DSTLCFG_READ_THRESHOLD = 8;
static const uint32_t DSTL_DSTLCFG_READ_THRESHOLD_LEN = 4;
static const uint32_t DSTL_DSTLCFG_RESERVED_12_15 = 12;
static const uint32_t DSTL_DSTLCFG_RESERVED_12_15_LEN = 4;
static const uint32_t DSTL_DSTLCFG_WR_TMP4_THRESHOLD = 16;
static const uint32_t DSTL_DSTLCFG_WR_TMP4_THRESHOLD_LEN = 4;
static const uint32_t DSTL_DSTLCFG_RESERVED_20_23 = 20;
static const uint32_t DSTL_DSTLCFG_RESERVED_20_23_LEN = 4;
static const uint32_t DSTL_DSTLCFG_WR_DBL_THRESHOLD = 24;
static const uint32_t DSTL_DSTLCFG_WR_DBL_THRESHOLD_LEN = 4;
static const uint32_t DSTL_DSTLCFG_CRITICAL_OW_DIS = 28;
static const uint32_t DSTL_DSTLCFG_ENABLE_SPEC_ATTN = 29;
static const uint32_t DSTL_DSTLCFG_ENABLE_HOST_ATTN = 30;
static const uint32_t DSTL_DSTLCFG_DEBUG_EN = 31;
static const uint32_t DSTL_DSTLCFG_DEBUG_LOCAL_SWAP = 32;
static const uint32_t DSTL_DSTLCFG_DEBUG_PASSTHRU = 33;
static const uint32_t DSTL_DSTLCFG_DEBUG_PASSTHRU_LEN = 11;
static const uint32_t DSTL_DSTLCFG_WRAP_MODE_EN = 44;
static const uint32_t DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH = 45;
static const uint32_t DSTL_DSTLCFG_CREDIT_RETURN_DELAY_THRESH_LEN = 4;
static const uint32_t DSTL_DSTLCFG_TIMEOUT_MODE = 49;
static const uint32_t DSTL_DSTLCFG_TIMEOUT_MODE_LEN = 3;
static const uint32_t DSTL_DSTLCFG_MMIO_ADDRBIT_POS = 52;
static const uint32_t DSTL_DSTLCFG_MMIO_ADDRBIT_POS_LEN = 5;
static const uint32_t DSTL_DSTLCFG_RESET_CREDITS = 57;
static const uint32_t DSTL_DSTLCFG_CHANA_DL_CREDIT_RESET = 58;
static const uint32_t DSTL_DSTLCFG_CHANB_DL_CREDIT_RESET = 59;
static const uint32_t DSTL_DSTLCFG_CREDITS_ON_DEBUG_BUS = 60;
static const uint32_t DSTL_DSTLCFG_RESERVED_61_63 = 61;
static const uint32_t DSTL_DSTLCFG_RESERVED_61_63_LEN = 3;
// mcc/reg00068.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PERF_COUNT_LSB_1 = 0x0c011021ull;
// mcc/reg00068.H

}
}
#include "mcc/reg00068.H"
#endif
