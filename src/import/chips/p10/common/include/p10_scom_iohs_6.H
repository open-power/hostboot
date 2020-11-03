/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_6.H $       */
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

#ifndef __p10_scom_iohs_6_H_
#define __p10_scom_iohs_6_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_FIR_REG]
static const uint64_t DLP_FIR_REG_RW = 0x18011000ull;
static const uint64_t DLP_FIR_REG_WO_AND = 0x18011001ull;
static const uint64_t DLP_FIR_REG_WO_OR = 0x18011002ull;

static const uint32_t DLP_FIR_REG_0_TRAINED = 0;
static const uint32_t DLP_FIR_REG_1_TRAINED = 1;
static const uint32_t DLP_FIR_REG_0_OP_IRQ = 2;
static const uint32_t DLP_FIR_REG_1_OP_IRQ = 3;
static const uint32_t DLP_FIR_REG_0_REPLAY_THRESHOLD = 4;
static const uint32_t DLP_FIR_REG_1_REPLAY_THRESHOLD = 5;
static const uint32_t DLP_FIR_REG_0_CRC_ERROR = 6;
static const uint32_t DLP_FIR_REG_1_CRC_ERROR = 7;
static const uint32_t DLP_FIR_REG_0_NAK_RECEIVED = 8;
static const uint32_t DLP_FIR_REG_1_NAK_RECEIVED = 9;
static const uint32_t DLP_FIR_REG_0_REPLAY_BUFFER_FULL = 10;
static const uint32_t DLP_FIR_REG_1_REPLAY_BUFFER_FULL = 11;
static const uint32_t DLP_FIR_REG_0_SL_ECC_THRESHOLD = 12;
static const uint32_t DLP_FIR_REG_1_SL_ECC_THRESHOLD = 13;
static const uint32_t DLP_FIR_REG_0_SL_ECC_CORRECTABLE = 14;
static const uint32_t DLP_FIR_REG_1_SL_ECC_CORRECTABLE = 15;
static const uint32_t DLP_FIR_REG_0_SL_ECC_UE = 16;
static const uint32_t DLP_FIR_REG_1_SL_ECC_UE = 17;
static const uint32_t DLP_FIR_REG_0_RETRAIN_THRESHOLD = 18;
static const uint32_t DLP_FIR_REG_1_RETRAIN_THRESHOLD = 19;
static const uint32_t DLP_FIR_REG_0_LOSS_BLOCK_ALIGN = 20;
static const uint32_t DLP_FIR_REG_1_LOSS_BLOCK_ALIGN = 21;
static const uint32_t DLP_FIR_REG_0_INVALID_BLOCK = 22;
static const uint32_t DLP_FIR_REG_1_INVALID_BLOCK = 23;
static const uint32_t DLP_FIR_REG_0_DESKEW_ERROR = 24;
static const uint32_t DLP_FIR_REG_1_DESKEW_ERROR = 25;
static const uint32_t DLP_FIR_REG_0_DESKEW_OVERFLOW = 26;
static const uint32_t DLP_FIR_REG_1_DESKEW_OVERFLOW = 27;
static const uint32_t DLP_FIR_REG_0_SW_RETRAIN = 28;
static const uint32_t DLP_FIR_REG_1_SW_RETRAIN = 29;
static const uint32_t DLP_FIR_REG_0_ACK_QUEUE_OVERFLOW = 30;
static const uint32_t DLP_FIR_REG_1_ACK_QUEUE_OVERFLOW = 31;
static const uint32_t DLP_FIR_REG_0_ACK_QUEUE_UNDERFLOW = 32;
static const uint32_t DLP_FIR_REG_1_ACK_QUEUE_UNDERFLOW = 33;
static const uint32_t DLP_FIR_REG_0_NUM_REPLAY = 34;
static const uint32_t DLP_FIR_REG_1_NUM_REPLAY = 35;
static const uint32_t DLP_FIR_REG_0_TRAINING_SET_RECEIVED = 36;
static const uint32_t DLP_FIR_REG_1_TRAINING_SET_RECEIVED = 37;
static const uint32_t DLP_FIR_REG_0_PRBS_SELECT_ERROR = 38;
static const uint32_t DLP_FIR_REG_1_PRBS_SELECT_ERROR = 39;
static const uint32_t DLP_FIR_REG_0_TCOMPLETE_BAD = 40;
static const uint32_t DLP_FIR_REG_1_TCOMPLETE_BAD = 41;
static const uint32_t DLP_FIR_REG_0_NO_SPARE = 42;
static const uint32_t DLP_FIR_REG_1_NO_SPARE = 43;
static const uint32_t DLP_FIR_REG_0_SPARE_DONE = 44;
static const uint32_t DLP_FIR_REG_1_SPARE_DONE = 45;
static const uint32_t DLP_FIR_REG_0_TOO_MANY_CRC_ERRORS = 46;
static const uint32_t DLP_FIR_REG_1_TOO_MANY_CRC_ERRORS = 47;
static const uint32_t DLP_FIR_REG_0_NPU_DLX_ERROR = 48;
static const uint32_t DLP_FIR_REG_1_NPU_DLX_ERROR = 49;
static const uint32_t DLP_FIR_REG_0_OSC_SWITCH = 50;
static const uint32_t DLP_FIR_REG_1_OSC_SWITCH = 51;
static const uint32_t DLP_FIR_REG_0_CORRECTABLE_ARRAY_ERROR = 52;
static const uint32_t DLP_FIR_REG_1_CORRECTABLE_ARRAY_ERROR = 53;
static const uint32_t DLP_FIR_REG_0_UNCORRECTABLE_ARRAY_ERROR = 54;
static const uint32_t DLP_FIR_REG_1_UNCORRECTABLE_ARRAY_ERROR = 55;
static const uint32_t DLP_FIR_REG_0_TRAINING_FAILED = 56;
static const uint32_t DLP_FIR_REG_1_TRAINING_FAILED = 57;
static const uint32_t DLP_FIR_REG_0_UNRECOVERABLE_ERROR = 58;
static const uint32_t DLP_FIR_REG_1_UNRECOVERABLE_ERROR = 59;
static const uint32_t DLP_FIR_REG_0_INTERNAL_ERROR = 60;
static const uint32_t DLP_FIR_REG_1_INTERNAL_ERROR = 61;
//<< [DLP_FIR_REG]
// iohs/reg00025.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00025.H"
#include "iohs/reg00026.H"
#include "iohs/reg00027.H"
#include "iohs/reg00028.H"
#include "iohs/reg00029.H"
#endif
#endif
