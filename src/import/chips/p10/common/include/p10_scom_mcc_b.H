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


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_DECRYPT_CRYPTOKEY1B = 0x0c010f7bull;

static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B = 0;
static const uint32_t CRYPTO_DECRYPT_CRYPTOKEY1B_KEY1B_LEN = 64;
// mcc/reg00075.H

//ERRCODE: // Some of the name targets not found in address targets.

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
// mcc/reg00075.H

//ERRCODE: // Some of the name targets not found in address targets.

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
// mcc/reg00075.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t FIR_REG_ = 0x0c011000ull;

static const uint32_t FIR_REG_LINK0_TRAINED = 0;
static const uint32_t FIR_REG_LINK1_TRAINED = 1;
static const uint32_t FIR_REG_LINK0_OP_IRQ = 2;
static const uint32_t FIR_REG_LINK1_OP_IRQ = 3;
static const uint32_t FIR_REG_LINK0_REPLAY_THRESHOLD = 4;
static const uint32_t FIR_REG_LINK1_REPLAY_THRESHOLD = 5;
static const uint32_t FIR_REG_LINK0_CRC_ERROR = 6;
static const uint32_t FIR_REG_LINK1_CRC_ERROR = 7;
static const uint32_t FIR_REG_LINK0_NAK_RECEIVED = 8;
static const uint32_t FIR_REG_LINK1_NAK_RECEIVED = 9;
static const uint32_t FIR_REG_LINK0_REPLAY_BUFFER_FULL = 10;
static const uint32_t FIR_REG_LINK1_REPLAY_BUFFER_FULL = 11;
static const uint32_t FIR_REG_LINK0_SL_ECC_THRESHOLD = 12;
static const uint32_t FIR_REG_LINK1_SL_ECC_THRESHOLD = 13;
static const uint32_t FIR_REG_LINK0_SL_ECC_CORRECTABLE = 14;
static const uint32_t FIR_REG_LINK1_SL_ECC_CORRECTABLE = 15;
static const uint32_t FIR_REG_LINK0_SL_ECC_UE = 16;
static const uint32_t FIR_REG_LINK1_SL_ECC_UE = 17;
static const uint32_t FIR_REG_LINK0_RETRAIN_THRESHOLD = 18;
static const uint32_t FIR_REG_LINK1_RETRAIN_THRESHOLD = 19;
static const uint32_t FIR_REG_LINK0_LOSS_BLOCK_ALIGN = 20;
static const uint32_t FIR_REG_LINK1_LOSS_BLOCK_ALIGN = 21;
static const uint32_t FIR_REG_LINK0_INVALID_BLOCK = 22;
static const uint32_t FIR_REG_LINK1_INVALID_BLOCK = 23;
static const uint32_t FIR_REG_LINK0_DESKEW_ERROR = 24;
static const uint32_t FIR_REG_LINK1_DESKEW_ERROR = 25;
static const uint32_t FIR_REG_LINK0_DESKEW_OVERFLOW = 26;
static const uint32_t FIR_REG_LINK1_DESKEW_OVERFLOW = 27;
static const uint32_t FIR_REG_LINK0_SW_RETRAIN = 28;
static const uint32_t FIR_REG_LINK1_SW_RETRAIN = 29;
static const uint32_t FIR_REG_LINK0_ACK_QUEUE_OVERFLOW = 30;
static const uint32_t FIR_REG_LINK1_ACK_QUEUE_OVERFLOW = 31;
static const uint32_t FIR_REG_LINK0_ACK_QUEUE_UNDERFLOW = 32;
static const uint32_t FIR_REG_LINK1_ACK_QUEUE_UNDERFLOW = 33;
static const uint32_t FIR_REG_LINK0_NUM_REPLAY = 34;
static const uint32_t FIR_REG_LINK1_NUM_REPLAY = 35;
static const uint32_t FIR_REG_LINK0_TRAINING_SET_RECEIVED = 36;
static const uint32_t FIR_REG_LINK1_TRAINING_SET_RECEIVED = 37;
static const uint32_t FIR_REG_LINK0_PRBS_SELECT_ERROR = 38;
static const uint32_t FIR_REG_LINK1_PRBS_SELECT_ERROR = 39;
static const uint32_t FIR_REG_LINK0_TCOMPLETE_BAD = 40;
static const uint32_t FIR_REG_LINK1_TCOMPLETE_BAD = 41;
static const uint32_t FIR_REG_LINK0_NO_SPARE = 42;
static const uint32_t FIR_REG_LINK1_NO_SPARE = 43;
static const uint32_t FIR_REG_LINK0_SPARE_DONE = 44;
static const uint32_t FIR_REG_LINK1_SPARE_DONE = 45;
static const uint32_t FIR_REG_LINK0_TOO_MANY_CRC_ERRORS = 46;
static const uint32_t FIR_REG_LINK1_TOO_MANY_CRC_ERRORS = 47;
static const uint32_t FIR_REG_LINK0_NPU_DLX_ERROR = 48;
static const uint32_t FIR_REG_LINK1_NPU_DLX_ERROR = 49;
static const uint32_t FIR_REG_OSC_SWITCH = 51;
static const uint32_t FIR_REG_LINK0_CORRECTABLE_ARRAY_ERROR = 52;
static const uint32_t FIR_REG_LINK1_CORRECTABLE_ARRAY_ERROR = 53;
static const uint32_t FIR_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR = 54;
static const uint32_t FIR_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR = 55;
static const uint32_t FIR_REG_LINK0_TRAINING_FAILED = 56;
static const uint32_t FIR_REG_LINK1_TRAINING_FAILED = 57;
static const uint32_t FIR_REG_LINK0_UNRECOVERABLE_ERROR = 58;
static const uint32_t FIR_REG_LINK1_UNRECOVERABLE_ERROR = 59;
static const uint32_t FIR_REG_LINK0_INTERNAL_ERROR = 60;
static const uint32_t FIR_REG_LINK1_INTERNAL_ERROR = 61;
// mcc/reg00075.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LAT_MEASURE = 0x0c01100eull;

static const uint32_t LAT_MEASURE_LINK0_ROUND_TRIP_VALID = 0;
static const uint32_t LAT_MEASURE_LINK0_ROUND_TRIP = 2;
static const uint32_t LAT_MEASURE_LINK0_ROUND_TRIP_LEN = 10;
static const uint32_t LAT_MEASURE_LINK1_ROUND_TRIP_VALID = 12;
static const uint32_t LAT_MEASURE_LINK1_ROUND_TRIP = 14;
static const uint32_t LAT_MEASURE_LINK1_ROUND_TRIP_LEN = 10;
static const uint32_t LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID = 24;
static const uint32_t LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK = 25;
static const uint32_t LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE = 29;
static const uint32_t LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_LEN = 7;
static const uint32_t LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID = 36;
static const uint32_t LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK = 37;
static const uint32_t LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE = 41;
static const uint32_t LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_LEN = 7;
static const uint32_t LAT_MEASURE_LINK0_TOD_LATENCY = 49;
static const uint32_t LAT_MEASURE_LINK0_TOD_LATENCY_LEN = 7;
static const uint32_t LAT_MEASURE_LINK1_TOD_LATENCY = 57;
static const uint32_t LAT_MEASURE_LINK1_TOD_LATENCY_LEN = 7;
// mcc/reg00075.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PERF_COUNTERS_1 = 0x0c01101full;

static const uint32_t PERF_COUNTERS_1_4 = 0;
static const uint32_t PERF_COUNTERS_1_4_LEN = 16;
static const uint32_t PERF_COUNTERS_1_5 = 16;
static const uint32_t PERF_COUNTERS_1_5_LEN = 16;
static const uint32_t PERF_COUNTERS_1_6 = 32;
static const uint32_t PERF_COUNTERS_1_6_LEN = 16;
static const uint32_t PERF_COUNTERS_1_7 = 48;
static const uint32_t PERF_COUNTERS_1_7_LEN = 16;
// mcc/reg00075.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PHY_CONFIG = 0x0c01100cull;

static const uint32_t PHY_CONFIG_PHY_TRAIN_A_ADJ = 0;
static const uint32_t PHY_CONFIG_PHY_TRAIN_A_ADJ_LEN = 2;
static const uint32_t PHY_CONFIG_PHY_TRAIN_B_ADJ = 2;
static const uint32_t PHY_CONFIG_PHY_TRAIN_B_ADJ_LEN = 2;
static const uint32_t PHY_CONFIG_PHY_TRAIN_TIME = 4;
static const uint32_t PHY_CONFIG_PHY_TRAIN_TIME_LEN = 4;
static const uint32_t PHY_CONFIG_PHY_TRAIN_A_HYST = 8;
static const uint32_t PHY_CONFIG_PHY_TRAIN_A_HYST_LEN = 4;
static const uint32_t PHY_CONFIG_PHY_TRAIN_B_HYST = 12;
static const uint32_t PHY_CONFIG_PHY_TRAIN_B_HYST_LEN = 4;
static const uint32_t PHY_CONFIG_PRBS_PHASE_SELECT = 16;
static const uint32_t PHY_CONFIG_PRBS_PHASE_SELECT_LEN = 24;
static const uint32_t PHY_CONFIG_PRBS_CONFIG = 40;
static const uint32_t PHY_CONFIG_PRBS_CONFIG_LEN = 10;
static const uint32_t PHY_CONFIG_PRBS_INVERT = 50;
static const uint32_t PHY_CONFIG_LINK0_SELECT = 56;
static const uint32_t PHY_CONFIG_LINK1_SELECT = 57;
static const uint32_t PHY_CONFIG_PRECODER_ENABLE = 60;
static const uint32_t PHY_CONFIG_50G_MODE = 61;
static const uint32_t PHY_CONFIG_DL_SELECT = 62;
static const uint32_t PHY_CONFIG_DL_SELECT_LEN = 2;
// mcc/reg00075.H

//ERRCODE: // Some of the name targets not found in address targets.

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
// mcc/reg00075.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t USTL_USTLFIRWOF = 0x0c010e08ull;

static const uint32_t USTL_USTLFIRWOF_USTLFIRWOF_WOF = 0;
static const uint32_t USTL_USTLFIRWOF_USTLFIRWOF_WOF_LEN = 62;
// mcc/reg00075.H

}
}
#include "mcc/reg00075.H"
#endif
