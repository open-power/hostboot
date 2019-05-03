/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_b.H $        */
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

#ifndef __p10_scom_mcc_b_H_
#define __p10_scom_mcc_b_H_


namespace scomt
{
namespace mcc
{


static const uint64_t CRYPTO_DECRYPT_CRYPTOKEY1B = 0x0c010f5bull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B_LEN = 64;
// mcc/reg00011.H

static const uint64_t DSTL_DSTLCREDIT = 0x0c010d0aull;

static const uint32_t DSTL_DSTLCREDIT_XVC0_CREDIT_INIT = 2;
static const uint32_t DSTL_DSTLCREDIT_XVC0_CREDIT_INIT_LEN = 6;
static const uint32_t DSTL_DSTLCREDIT_XVC3_CREDIT_INIT = 12;
static const uint32_t DSTL_DSTLCREDIT_XVC3_CREDIT_INIT_LEN = 4;
static const uint32_t DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT = 17;
static const uint32_t DSTL_DSTLCREDIT_XDCP0_CREDIT_INIT_LEN = 7;
static const uint32_t DSTL_DSTLCREDIT_VC0_CREDIT_INIT = 28;
static const uint32_t DSTL_DSTLCREDIT_VC0_CREDIT_INIT_LEN = 4;
static const uint32_t DSTL_DSTLCREDIT_VC1_CREDIT_INIT = 36;
static const uint32_t DSTL_DSTLCREDIT_VC1_CREDIT_INIT_LEN = 4;
static const uint32_t DSTL_DSTLCREDIT_DCP1_CREDIT_INIT = 42;
static const uint32_t DSTL_DSTLCREDIT_DCP1_CREDIT_INIT_LEN = 6;
static const uint32_t DSTL_DSTLCREDIT_XDCP0_CHANA_POOL = 50;
static const uint32_t DSTL_DSTLCREDIT_XDCP0_CHANA_POOL_LEN = 6;
static const uint32_t DSTL_DSTLCREDIT_XDCP0_CHANB_POOL = 58;
static const uint32_t DSTL_DSTLCREDIT_XDCP0_CHANB_POOL_LEN = 6;
// mcc/reg00011.H

static const uint64_t DSTL_DSTLFIR_RWX = 0x0c010d00ull;
static const uint64_t DSTL_DSTLFIR_WOX_AND = 0x0c010d01ull;
static const uint64_t DSTL_DSTLFIR_WOX_OR = 0x0c010d02ull;

static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_TLX_CHECKSTOP = 0;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_TLX_RECOVERABLE_ATTENTION = 1;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_TLX_SPECIAL_ATTENTION = 2;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT = 3;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_TLX_CHECKSTOP = 4;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_TLX_RECOVERABLE_ATTENTION = 5;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_TLX_SPECIAL_ATTENTION = 6;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT = 7;
static const uint32_t DSTL_DSTLFIR_ASYNC_CROSSING_PARITY_ERROR = 8;
static const uint32_t DSTL_DSTLFIR_CMD_WRDATA_PARITY_ERROR = 9;
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
static const uint32_t DSTL_DSTLFIR_SPARE24 = 24;
static const uint32_t DSTL_DSTLFIR_SPARE25 = 25;
static const uint32_t DSTL_DSTLFIR_DECRYPT_ERR_INFO = 26;
static const uint32_t DSTL_DSTLFIR_DECRYPT_ERR_INFO_LEN = 3;
static const uint32_t DSTL_DSTLFIR_ENCRYPT_ERR_INFO = 29;
static const uint32_t DSTL_DSTLFIR_ENCRYPT_ERR_INFO_LEN = 4;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_A_TLX_APPLICATION_INTERRUPT_RETRIED = 33;
static const uint32_t DSTL_DSTLFIR_SUBCHANNEL_B_TLX_APPLICATION_INTERRUPT_RETRIED = 34;
// mcc/reg00011.H

static const uint64_t USTL_USTLERRRPT = 0x0c010e0eull;

static const uint32_t USTL_USTLERRRPT_HANA_RDCMD_PARITY_ERROR_HOLD_OUT = 0;
static const uint32_t USTL_USTLERRRPT_HANA_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 1;
static const uint32_t USTL_USTLERRRPT_HANA_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 2;
static const uint32_t USTL_USTLERRRPT_HANA_BADCRC_PARITY_ERROR_HOLD_OUT = 3;
static const uint32_t USTL_USTLERRRPT_HANB_RDCMD_PARITY_ERROR_HOLD_OUT = 4;
static const uint32_t USTL_USTLERRRPT_HANB_CMTQ_CM2P_PARITY_ERROR_HOLD_OUT = 5;
static const uint32_t USTL_USTLERRRPT_HANB_FAIL_CM2F_PARITY_ERROR_HOLD_OUT = 6;
static const uint32_t USTL_USTLERRRPT_HANB_BADCRC_PARITY_ERROR_HOLD_OUT = 7;
static const uint32_t USTL_USTLERRRPT_HANA_FLIT_PARITY_ERROR_HOLD_OUT = 8;
static const uint32_t USTL_USTLERRRPT_HANB_FLIT_PARITY_ERROR_HOLD_OUT = 9;
static const uint32_t USTL_USTLERRRPT_HANA_BAD_DATA_HOLD_OUT = 10;
static const uint32_t USTL_USTLERRRPT_HANB_BAD_DATA_HOLD_OUT = 11;
static const uint32_t USTL_USTLERRRPT_HANA_SUE_HOLD_OUT = 12;
static const uint32_t USTL_USTLERRRPT_HANB_SUE_HOLD_OUT = 13;
static const uint32_t USTL_USTLERRRPT_HANA_BUFFER_OVERFLOW_HOLD_OUT = 14;
static const uint32_t USTL_USTLERRRPT_HANA_DATA_BUFFER_OVERFLOW_HOLD_OUT = 15;
static const uint32_t USTL_USTLERRRPT_HANA_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 16;
static const uint32_t USTL_USTLERRRPT_HANA_META_QUEUE_OVERFLOW_HOLD_OUT = 17;
static const uint32_t USTL_USTLERRRPT_HANA_READ_RESPONSE_OVERFLOW_HOLD_OUT = 18;
static const uint32_t USTL_USTLERRRPT_HANA_COMP_META_NOT_VALID_HOLD_OUT = 19;
static const uint32_t USTL_USTLERRRPT_HANB_BUFFER_OVERFLOW_HOLD_OUT = 20;
static const uint32_t USTL_USTLERRRPT_HANB_DATA_BUFFER_OVERFLOW_HOLD_OUT = 21;
static const uint32_t USTL_USTLERRRPT_HANB_META_QUEUE_OVERFLOW_HOLD_OUT = 22;
static const uint32_t USTL_USTLERRRPT_HANB_COMMIT_QUEUE_OVERFLOW_HOLD_OUT = 23;
static const uint32_t USTL_USTLERRRPT_HANB_READ_RESPONSE_OVERFLOW_HOLD_OUT = 24;
static const uint32_t USTL_USTLERRRPT_HANB_COMP_META_NOT_VALID_HOLD_OUT = 25;
static const uint32_t USTL_USTLERRRPT_NFG_MCHWFM_PE_HOLD_OUT = 26;
static const uint32_t USTL_USTLERRRPT_NFG_REG_PE_HOLD_OUT = 27;
static const uint32_t USTL_USTLERRRPT_NFG_DBG_PE_HOLD_OUT = 28;
static const uint32_t USTL_USTLERRRPT_NFG_INJ_FIR_PE_HOLD_OUT = 29;
static const uint32_t USTL_USTLERRRPT_HANA_TMPL9_TO_MANY_DATA_HOLD_OUT = 30;
static const uint32_t USTL_USTLERRRPT_HANB_TMPL9_TO_MANY_DATA = 31;
static const uint32_t USTL_USTLERRRPT_HANA_EXCESS_DATA_ERROR_HOLD_OUT = 32;
static const uint32_t USTL_USTLERRRPT_HANB_EXCESS_DATA_ERROR_HOLD_OUT = 33;
static const uint32_t USTL_USTLERRRPT_HANA_BOGUS_QUEUE_OVERFLOW_HOLD_OUT = 34;
static const uint32_t USTL_USTLERRRPT_HANA_META_PARITY_ERROR_HOLD_OUT = 36;
static const uint32_t USTL_USTLERRRPT_HANB_META_PARITY_ERROR_HOLD_OUT = 37;
// mcc/reg00011.H

static const uint64_t USTL_USTLFIRWOF = 0x0c010e08ull;

static const uint32_t USTL_USTLFIRWOF_USTLFIRWOF_WOF = 0;
static const uint32_t USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN = 62;
// mcc/reg00011.H

}
}
#include "mcc/reg00011.H"
#endif
