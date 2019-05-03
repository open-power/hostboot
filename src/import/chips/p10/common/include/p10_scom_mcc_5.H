/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_5.H $        */
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

#ifndef __p10_scom_mcc_5_H_
#define __p10_scom_mcc_5_H_


namespace scomt
{
namespace mcc
{


static const uint64_t CRYPTO_DECRYPT_CRYPTONONCEA = 0x0c010f5eull;

static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTONONCEA_NONCEA_LEN = 64;
// mcc/reg00005.H

static const uint64_t CRYPTO_ENCRYPT_CRYPTONONCEB = 0x0c010f57ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTONONCEB_NONCEB_LEN = 17;
// mcc/reg00005.H

static const uint64_t USTL_USTLOCAPIERROR = 0x0c010e14ull;

static const uint32_t USTL_USTLOCAPIERROR_USTLOCAPIERROR_SUB_CHANNEL_ID = 0;
static const uint32_t USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE = 1;
static const uint32_t USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_TYPE_LEN = 8;
static const uint32_t USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION = 9;
static const uint32_t USTL_USTLOCAPIERROR_OCAPIERROR_ERROR_INFORMATION_LEN = 31;
// mcc/reg00005.H

static const uint64_t WRITE_WRTDBGMCA = 0x0c010f4aull;

static const uint32_t WRITE_WRTDBGMCA_MCA_DBG_SEL_IN = 0;
static const uint32_t WRITE_WRTDBGMCA_MCA_DBG_SEL_WRT = 1;
static const uint32_t WRITE_WRTDBGMCA_WBRD_DEBUG_0_SELECT = 2;
static const uint32_t WRITE_WRTDBGMCA_WBRD_DEBUG_1_SELECT = 3;
static const uint32_t WRITE_WRTDBGMCA_WBWR_DEBUG_0_SELECT = 4;
static const uint32_t WRITE_WRTDBGMCA_WBWR_DEBUG_1_SELECT = 5;
static const uint32_t WRITE_WRTDBGMCA_SLICE0_DEBUG_0_SELECT = 6;
static const uint32_t WRITE_WRTDBGMCA_SLICE0_DEBUG_1_SELECT = 7;
static const uint32_t WRITE_WRTDBGMCA_SLICE1_DEBUG_0_SELECT = 8;
static const uint32_t WRITE_WRTDBGMCA_SLICE1_DEBUG_1_SELECT = 9;
static const uint32_t WRITE_WRTDBGMCA_SLICE2_DEBUG_0_SELECT = 10;
static const uint32_t WRITE_WRTDBGMCA_SLICE2_DEBUG_1_SELECT = 11;
static const uint32_t WRITE_WRTDBGMCA_SLICE3_DEBUG_0_SELECT = 12;
static const uint32_t WRITE_WRTDBGMCA_SLICE3_DEBUG_1_SELECT = 13;
static const uint32_t WRITE_WRTDBGMCA_WRCNTL_DEBUG_SELECT = 14;
static const uint32_t WRITE_WRTDBGMCA_DBG_SPARE_MCA = 15;
static const uint32_t WRITE_WRTDBGMCA_WAT_EVENT_ENABLE_MCA = 16;
static const uint32_t WRITE_WRTDBGMCA_WAT_SPARE1_MCA = 17;
static const uint32_t WRITE_WRTDBGMCA_WAT_SPARE1_MCA_LEN = 3;
static const uint32_t WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA = 20;
static const uint32_t WRITE_WRTDBGMCA_WAT0_EVENT_SELECT_MCA_LEN = 4;
static const uint32_t WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA = 24;
static const uint32_t WRITE_WRTDBGMCA_WAT1_EVENT_SELECT_MCA_LEN = 4;
// mcc/reg00005.H

}
}
#include "mcc/reg00005.H"
#endif
