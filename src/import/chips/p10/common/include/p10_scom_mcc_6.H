/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_6.H $        */
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

#ifndef __p10_scom_mcc_6_H_
#define __p10_scom_mcc_6_H_


namespace scomt
{
namespace mcc
{


static const uint64_t CRYPTO_DECRYPT_CRYPTOCFG = 0x0c010f58ull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_CHK_DIS = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_CFG_WRITE_MODE_ECC_COR_DIS = 1;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_RESET_KEEPER = 2;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_ENABLE = 4;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_CRYPTO_SELECT = 5;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11 = 6;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_SPARE_6_11_LEN = 6;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ = 12;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW0_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ = 14;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW1_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ = 16;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW2_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ = 18;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW3_ERR_INJ_LEN = 2;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW0_SUE_INJ = 20;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW1_SUE_INJ = 21;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW2_SUE_INJ = 22;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_DW3_SUE_INJ = 23;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_ONE_SHOT_INJ = 24;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_PERSISTANT_INJ = 25;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31 = 26;
static const uint32_t CRYPTO_DECRYPT_CRYPTOCFG_SPARE_26_31_LEN = 6;
// mcc/reg00006.H

static const uint64_t DSTL_DSTLPSAVE2 = 0x0c010d14ull;

static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC = 0;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUC_LEN = 8;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC = 8;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUC_LEN = 8;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT = 16;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_A_LUT_LEN = 5;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT = 21;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_A_HUT_LEN = 5;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE = 26;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_A_SPARE_LEN = 2;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC = 28;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUC_LEN = 8;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC = 36;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUC_LEN = 8;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT = 44;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_B_LUT_LEN = 5;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT = 49;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_B_HUT_LEN = 5;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE = 54;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_B_SPARE_LEN = 2;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE = 56;
static const uint32_t DSTL_DSTLPSAVE2_MASTER_PSAVE_WSIZE_LEN = 3;
static const uint32_t DSTL_DSTLPSAVE2_RESERVED_59_63 = 59;
static const uint32_t DSTL_DSTLPSAVE2_RESERVED_59_63_LEN = 5;
// mcc/reg00006.H

}
}
#include "mcc/reg00006.H"
#endif
