/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_e.H $        */
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

#ifndef __p10_scom_mcc_e_H_
#define __p10_scom_mcc_e_H_


namespace scomt
{
namespace mcc
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t CRYPTO_ENCRYPT_CRYPTOKEY2B = 0x0c010f75ull;

static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B = 0;
static const uint32_t CRYPTO_ENCRYPT_CRYPTOKEY2B_KEY2B_LEN = 64;
// mcc/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t FIR_MASK_REG_SCOM = 0x0c011003ull;
static const uint64_t FIR_MASK_REG_SCOM1 = 0x0c011004ull;
static const uint64_t FIR_MASK_REG_SCOM2 = 0x0c011005ull;

static const uint32_t FIR_MASK_REG_LINK0_TRAINED_MASK = 0;
static const uint32_t FIR_MASK_REG_LINK1_TRAINED_MASK = 1;
static const uint32_t FIR_MASK_REG_LINK0_OP_IRQ_MASK = 2;
static const uint32_t FIR_MASK_REG_LINK1_OP_IRQ_MASK = 3;
static const uint32_t FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK = 4;
static const uint32_t FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK = 5;
static const uint32_t FIR_MASK_REG_LINK0_CRC_ERROR_MASK = 6;
static const uint32_t FIR_MASK_REG_LINK1_CRC_ERROR_MASK = 7;
static const uint32_t FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK = 8;
static const uint32_t FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK = 9;
static const uint32_t FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK = 10;
static const uint32_t FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK = 11;
static const uint32_t FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK = 12;
static const uint32_t FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK = 13;
static const uint32_t FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK = 14;
static const uint32_t FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK = 15;
static const uint32_t FIR_MASK_REG_LINK0_SL_ECC_UE_MASK = 16;
static const uint32_t FIR_MASK_REG_LINK1_SL_ECC_UE_MASK = 17;
static const uint32_t FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK = 18;
static const uint32_t FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK = 19;
static const uint32_t FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK = 20;
static const uint32_t FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK = 21;
static const uint32_t FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK = 22;
static const uint32_t FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK = 23;
static const uint32_t FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK = 24;
static const uint32_t FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK = 25;
static const uint32_t FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK = 26;
static const uint32_t FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK = 27;
static const uint32_t FIR_MASK_REG_LINK0_SW_RETRAIN_MASK = 28;
static const uint32_t FIR_MASK_REG_LINK1_SW_RETRAIN_MASK = 29;
static const uint32_t FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK = 30;
static const uint32_t FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK = 31;
static const uint32_t FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK = 32;
static const uint32_t FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK = 33;
static const uint32_t FIR_MASK_REG_LINK0_NUM_REPLAY_MASK = 34;
static const uint32_t FIR_MASK_REG_LINK1_NUM_REPLAY_MASK = 35;
static const uint32_t FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK = 36;
static const uint32_t FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK = 37;
static const uint32_t FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK = 38;
static const uint32_t FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK = 39;
static const uint32_t FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK = 40;
static const uint32_t FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK = 41;
static const uint32_t FIR_MASK_REG_LINK0_NO_SPARE_MASK = 42;
static const uint32_t FIR_MASK_REG_LINK1_NO_SPARE_MASK = 43;
static const uint32_t FIR_MASK_REG_LINK0_SPARE_DONE_MASK = 44;
static const uint32_t FIR_MASK_REG_LINK1_SPARE_DONE_MASK = 45;
static const uint32_t FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK = 46;
static const uint32_t FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK = 47;
static const uint32_t FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK = 48;
static const uint32_t FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK = 49;
static const uint32_t FIR_MASK_REG_OSC_SWITCH_MASK = 51;
static const uint32_t FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK = 52;
static const uint32_t FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK = 53;
static const uint32_t FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK = 54;
static const uint32_t FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK = 55;
static const uint32_t FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK = 56;
static const uint32_t FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK = 57;
static const uint32_t FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK = 58;
static const uint32_t FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK = 59;
static const uint32_t FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK = 60;
static const uint32_t FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK = 61;
// mcc/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REGS_PRX0_DLR_APOR = 0x0c01103aull;

static const uint32_t REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM = 0;
static const uint32_t REGS_PRX0_DLR_APOR_ACTIVITY_ACCUM_LEN = 32;
static const uint32_t REGS_PRX0_DLR_APOR_BASE_ACCUM = 32;
static const uint32_t REGS_PRX0_DLR_APOR_BASE_ACCUM_LEN = 32;
// mcc/reg00014.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t USTL_USTLINJ = 0x0c010e0cull;

static const uint32_t USTL_USTLINJ_FAIL_RESP_TYPE = 3;
static const uint32_t USTL_USTLINJ_FAIL_RESP_TYPE_LEN = 3;
static const uint32_t USTL_USTLINJ_FIR_INJECT = 8;
static const uint32_t USTL_USTLINJ_FIR_INJECT_LEN = 5;
static const uint32_t USTL_USTLINJ_US_DATA = 20;
static const uint32_t USTL_USTLINJ_US_DATA_LEN = 3;
static const uint32_t USTL_USTLINJ_CHAN_SEL = 24;
static const uint32_t USTL_USTLINJ_DATA_DW_SEL = 25;
static const uint32_t USTL_USTLINJ_US_DATA_ERR_EN = 26;
static const uint32_t USTL_USTLINJ_ONE_SHOT = 27;
static const uint32_t USTL_USTLINJ_DATA_OUT = 28;
// mcc/reg00014.H

}
}
#include "mcc/reg00014.H"
#endif
