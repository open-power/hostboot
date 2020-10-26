/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_2.H $        */
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

#ifndef __p10_scom_mcc_2_H_
#define __p10_scom_mcc_2_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mcc
{
#endif


//>> [USTL_USTLFIR]
static const uint64_t USTL_USTLFIR_RW = 0x0c010e00ull;
static const uint64_t USTL_USTLFIR_WO_AND = 0x0c010e01ull;
static const uint64_t USTL_USTLFIR_WO_OR = 0x0c010e02ull;

static const uint32_t USTL_USTLFIR_CHANA_UNEXP_DATA_ERR = 0;
static const uint32_t USTL_USTLFIR_CHANB_UNEXP_DATA_ERR = 1;
static const uint32_t USTL_USTLFIR_CHANA_INVALID_TEMPLATE_ERROR = 2;
static const uint32_t USTL_USTLFIR_CHANB_INVALID_TEMPLATE_ERROR = 3;
static const uint32_t USTL_USTLFIR_RESERVED_4 = 4;
static const uint32_t USTL_USTLFIR_RESERVED_5 = 5;
static const uint32_t USTL_USTLFIR_WDF_BUFFER_CE = 6;
static const uint32_t USTL_USTLFIR_WDF_BUFFER_UE = 7;
static const uint32_t USTL_USTLFIR_WDF_BUFFER_SUE = 8;
static const uint32_t USTL_USTLFIR_WDF_BUFFER_OVERRUN = 9;
static const uint32_t USTL_USTLFIR_WDF_TAG_PARITY_ERROR = 10;
static const uint32_t USTL_USTLFIR_WDF_SCOM_SEQ_ERROR = 11;
static const uint32_t USTL_USTLFIR_WDF_PWCTL_SEQ_ERROR = 12;
static const uint32_t USTL_USTLFIR_WDF_MISC_REG_PARITY_ERROR = 13;
static const uint32_t USTL_USTLFIR_WDF_CL_POP_PARITY_ERROR = 14;
static const uint32_t USTL_USTLFIR_WDF_WR_DATA_SYNDROME_NE0 = 15;
static const uint32_t USTL_USTLFIR_WDF_CMT_PARITY_ERROR = 16;
static const uint32_t USTL_USTLFIR_READ_SPARE_1 = 17;
static const uint32_t USTL_USTLFIR_READ_SPARE_2 = 18;
static const uint32_t USTL_USTLFIR_READ_MBS_RDBUF_OVF_ERROR = 19;
static const uint32_t USTL_USTLFIR_WRT_BUFFER_CE = 20;
static const uint32_t USTL_USTLFIR_WRT_BUFFER_UE = 21;
static const uint32_t USTL_USTLFIR_WRT_BUFFER_SUE = 22;
static const uint32_t USTL_USTLFIR_WRT_SCOM_SEQ_ERROR = 23;
static const uint32_t USTL_USTLFIR_WRT_MISC_REG_PARITY_ERROR = 24;
static const uint32_t USTL_USTLFIR_WRT_DATA_SYNDROME_NE0 = 25;
static const uint32_t USTL_USTLFIR_WRT_BUFF_ERR = 26;
static const uint32_t USTL_USTLFIR_CHANA_FAIL_RESP_CHECKSTOP = 27;
static const uint32_t USTL_USTLFIR_CHANB_FAIL_RESP_CHECKSTOP = 28;
static const uint32_t USTL_USTLFIR_CHANA_FAIL_RESP_RECOVER = 29;
static const uint32_t USTL_USTLFIR_CHANB_FAIL_RESP_RECOVER = 30;
static const uint32_t USTL_USTLFIR_CHANA_LOL_DROP_CHECKSTOP = 31;
static const uint32_t USTL_USTLFIR_CHANB_LOL_DROP_CHECKSTOP = 32;
static const uint32_t USTL_USTLFIR_CHANA_LOL_DROP_RECOVER = 33;
static const uint32_t USTL_USTLFIR_CHANB_LOL_DROP_RECOVER = 34;
static const uint32_t USTL_USTLFIR_CHANA_FLIT_PARITY_ERROR = 35;
static const uint32_t USTL_USTLFIR_CHANB_FLIT_PARITY_ERROR = 36;
static const uint32_t USTL_USTLFIR_CHANA_FATAL_PARITY_ERROR = 37;
static const uint32_t USTL_USTLFIR_CHANB_FATAL_PARITY_ERROR = 38;
static const uint32_t USTL_USTLFIR_CHANA_BAD_RESP_LOG_VAL = 39;
static const uint32_t USTL_USTLFIR_CHANB_BAD_RESP_LOG_VAL = 40;
static const uint32_t USTL_USTLFIR_CHANA_EXCESS_BAD_DATA_BITS = 41;
static const uint32_t USTL_USTLFIR_CHANB_EXCESS_BAD_DATA_BITS = 42;
static const uint32_t USTL_USTLFIR_CHANA_COMP_TMPL0_DATA_NOT_MMIO = 43;
static const uint32_t USTL_USTLFIR_CHANB_COMP_TMPL0_DATA_NOT_MMIO = 44;
static const uint32_t USTL_USTLFIR_CHANA_MMIO_IN_LOL_MODE = 45;
static const uint32_t USTL_USTLFIR_CHANB_MMIO_IN_LOL_MODE = 46;
static const uint32_t USTL_USTLFIR_CHANA_BAD_DATA = 47;
static const uint32_t USTL_USTLFIR_CHANB_BAD_DATA = 48;
static const uint32_t USTL_USTLFIR_CHANA_EXCESS_DATA_ERROR = 49;
static const uint32_t USTL_USTLFIR_CHANB_EXCESS_DATA_ERROR = 50;
static const uint32_t USTL_USTLFIR_CHANA_BADCRC_DATA_NOT_VALID_ERROR = 51;
static const uint32_t USTL_USTLFIR_CHANB_BADCRC_DATA_NOT_VALID_ERROR = 52;
static const uint32_t USTL_USTLFIR_CHANA_FIFO_OVERFLOW_ERROR = 53;
static const uint32_t USTL_USTLFIR_CHANB_FIFO_OVERFLOW_ERROR = 54;
static const uint32_t USTL_USTLFIR_CHANA_INVALID_CMD_ERROR = 55;
static const uint32_t USTL_USTLFIR_CHANB_INVALID_CMD_ERROR = 56;
static const uint32_t USTL_USTLFIR_FATAL_REG_PARITY_ERROR = 57;
static const uint32_t USTL_USTLFIR_RECOV_REG_PARITY_ERROR = 58;
static const uint32_t USTL_USTLFIR_CHANA_INVALID_DL_DP_COMBO = 59;
static const uint32_t USTL_USTLFIR_CHANB_INVALID_DL_DP_COMBO = 60;
static const uint32_t USTL_USTLFIR_SPARE_61 = 61;
//<< [USTL_USTLFIR]
// mcc/reg00002.H

//>> [CRYPTO_DECRYPT_CRYPTOKEY2A]
static const uint64_t CRYPTO_DECRYPT_CRYPTOKEY2A = 0x0c010f5cull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY2A_KEY2A_LEN = 64;
//<< [CRYPTO_DECRYPT_CRYPTOKEY2A]
// mcc/reg00002.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mcc/reg00002.H"
#endif
#endif
