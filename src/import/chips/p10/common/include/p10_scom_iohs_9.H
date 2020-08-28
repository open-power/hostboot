/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_9.H $       */
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

#ifndef __p10_scom_iohs_9_H_
#define __p10_scom_iohs_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_FIR_MASK_REG]
static const uint64_t DLP_FIR_MASK_REG_RW = 0x18011003ull;
static const uint64_t DLP_FIR_MASK_REG_WO_AND = 0x18011004ull;
static const uint64_t DLP_FIR_MASK_REG_WO_OR = 0x18011005ull;

static const uint32_t DLP_FIR_MASK_REG_0_TRAINED_MASK = 0;
static const uint32_t DLP_FIR_MASK_REG_1_TRAINED_MASK = 1;
static const uint32_t DLP_FIR_MASK_REG_0_OP_IRQ_MASK = 2;
static const uint32_t DLP_FIR_MASK_REG_1_OP_IRQ_MASK = 3;
static const uint32_t DLP_FIR_MASK_REG_0_REPLAY_THRESHOLD_MASK = 4;
static const uint32_t DLP_FIR_MASK_REG_1_REPLAY_THRESHOLD_MASK = 5;
static const uint32_t DLP_FIR_MASK_REG_0_CRC_ERROR_MASK = 6;
static const uint32_t DLP_FIR_MASK_REG_1_CRC_ERROR_MASK = 7;
static const uint32_t DLP_FIR_MASK_REG_0_NAK_RECEIVED_MASK = 8;
static const uint32_t DLP_FIR_MASK_REG_1_NAK_RECEIVED_MASK = 9;
static const uint32_t DLP_FIR_MASK_REG_0_REPLAY_BUFFER_FULL_MASK = 10;
static const uint32_t DLP_FIR_MASK_REG_1_REPLAY_BUFFER_FULL_MASK = 11;
static const uint32_t DLP_FIR_MASK_REG_0_SL_ECC_THRESHOLD_MASK = 12;
static const uint32_t DLP_FIR_MASK_REG_1_SL_ECC_THRESHOLD_MASK = 13;
static const uint32_t DLP_FIR_MASK_REG_0_SL_ECC_CORRECTABLE_MASK = 14;
static const uint32_t DLP_FIR_MASK_REG_1_SL_ECC_CORRECTABLE_MASK = 15;
static const uint32_t DLP_FIR_MASK_REG_0_SL_ECC_UE_MASK = 16;
static const uint32_t DLP_FIR_MASK_REG_1_SL_ECC_UE_MASK = 17;
static const uint32_t DLP_FIR_MASK_REG_0_RETRAIN_THRESHOLD_MASK = 18;
static const uint32_t DLP_FIR_MASK_REG_1_RETRAIN_THRESHOLD_MASK = 19;
static const uint32_t DLP_FIR_MASK_REG_0_LOSS_BLOCK_ALIGN_MASK = 20;
static const uint32_t DLP_FIR_MASK_REG_1_LOSS_BLOCK_ALIGN_MASK = 21;
static const uint32_t DLP_FIR_MASK_REG_0_INVALID_BLOCK_MASK = 22;
static const uint32_t DLP_FIR_MASK_REG_1_INVALID_BLOCK_MASK = 23;
static const uint32_t DLP_FIR_MASK_REG_0_DESKEW_ERROR_MASK = 24;
static const uint32_t DLP_FIR_MASK_REG_1_DESKEW_ERROR_MASK = 25;
static const uint32_t DLP_FIR_MASK_REG_0_DESKEW_OVERFLOW_MASK = 26;
static const uint32_t DLP_FIR_MASK_REG_1_DESKEW_OVERFLOW_MASK = 27;
static const uint32_t DLP_FIR_MASK_REG_0_SW_RETRAIN_MASK = 28;
static const uint32_t DLP_FIR_MASK_REG_1_SW_RETRAIN_MASK = 29;
static const uint32_t DLP_FIR_MASK_REG_0_ACK_QUEUE_OVERFLOW_MASK = 30;
static const uint32_t DLP_FIR_MASK_REG_1_ACK_QUEUE_OVERFLOW_MASK = 31;
static const uint32_t DLP_FIR_MASK_REG_0_ACK_QUEUE_UNDERFLOW_MASK = 32;
static const uint32_t DLP_FIR_MASK_REG_1_ACK_QUEUE_UNDERFLOW_MASK = 33;
static const uint32_t DLP_FIR_MASK_REG_0_NUM_REPLAY_MASK = 34;
static const uint32_t DLP_FIR_MASK_REG_1_NUM_REPLAY_MASK = 35;
static const uint32_t DLP_FIR_MASK_REG_0_TRAINING_SET_RECEIVED_MASK = 36;
static const uint32_t DLP_FIR_MASK_REG_1_TRAINING_SET_RECEIVED_MASK = 37;
static const uint32_t DLP_FIR_MASK_REG_0_PRBS_SELECT_ERROR_MASK = 38;
static const uint32_t DLP_FIR_MASK_REG_1_PRBS_SELECT_ERROR_MASK = 39;
static const uint32_t DLP_FIR_MASK_REG_0_TCOMPLETE_BAD_MASK = 40;
static const uint32_t DLP_FIR_MASK_REG_1_TCOMPLETE_BAD_MASK = 41;
static const uint32_t DLP_FIR_MASK_REG_0_NO_SPARE_MASK = 42;
static const uint32_t DLP_FIR_MASK_REG_1_NO_SPARE_MASK = 43;
static const uint32_t DLP_FIR_MASK_REG_0_SPARE_DONE_MASK = 44;
static const uint32_t DLP_FIR_MASK_REG_1_SPARE_DONE_MASK = 45;
static const uint32_t DLP_FIR_MASK_REG_0_TOO_MANY_CRC_ERRORS_MASK = 46;
static const uint32_t DLP_FIR_MASK_REG_1_TOO_MANY_CRC_ERRORS_MASK = 47;
static const uint32_t DLP_FIR_MASK_REG_0_NPU_DLX_ERROR_MASK = 48;
static const uint32_t DLP_FIR_MASK_REG_1_NPU_DLX_ERROR_MASK = 49;
static const uint32_t DLP_FIR_MASK_REG_0_OSC_SWITCH_MASK = 50;
static const uint32_t DLP_FIR_MASK_REG_1_OSC_SWITCH_MASK = 51;
static const uint32_t DLP_FIR_MASK_REG_0_CORRECTABLE_ARRAY_ERROR_MASK = 52;
static const uint32_t DLP_FIR_MASK_REG_1_CORRECTABLE_ARRAY_ERROR_MASK = 53;
static const uint32_t DLP_FIR_MASK_REG_0_UNCORRECTABLE_ARRAY_ERROR_MASK = 54;
static const uint32_t DLP_FIR_MASK_REG_1_UNCORRECTABLE_ARRAY_ERROR_MASK = 55;
static const uint32_t DLP_FIR_MASK_REG_0_TRAINING_FAILED_MASK = 56;
static const uint32_t DLP_FIR_MASK_REG_1_TRAINING_FAILED_MASK = 57;
static const uint32_t DLP_FIR_MASK_REG_0_UNRECOVERABLE_ERROR_MASK = 58;
static const uint32_t DLP_FIR_MASK_REG_1_UNRECOVERABLE_ERROR_MASK = 59;
static const uint32_t DLP_FIR_MASK_REG_0_INTERNAL_ERROR_MASK = 60;
static const uint32_t DLP_FIR_MASK_REG_1_INTERNAL_ERROR_MASK = 61;
//<< [DLP_FIR_MASK_REG]
// iohs/reg00038.H

//>> [DLP_LINK1_ERROR_STATUS]
static const uint64_t DLP_LINK1_ERROR_STATUS = 0x18011017ull;

static const uint32_t DLP_LINK1_ERROR_STATUS_LINK1_RESET_KEEPER = 0;
static const uint32_t DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE = 1;
static const uint32_t DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_CE_LEN = 7;
static const uint32_t DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE = 8;
static const uint32_t DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UE_LEN = 4;
static const uint32_t DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC = 12;
static const uint32_t DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_OSC_LEN = 2;
static const uint32_t DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN = 16;
static const uint32_t DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_TRAIN_LEN = 5;
static const uint32_t DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV = 24;
static const uint32_t DLP_LINK1_ERROR_STATUS_LINK1_ERROR_STATUS_UNRECOV_LEN = 14;
static const uint32_t DLP_LINK1_ERROR_STATUS_INTERNAL = 38;
static const uint32_t DLP_LINK1_ERROR_STATUS_INTERNAL_LEN = 26;
//<< [DLP_LINK1_ERROR_STATUS]
// iohs/reg00038.H

//>> [DLP_LINK1_TX_LANE_CONTROL]
static const uint64_t DLP_LINK1_TX_LANE_CONTROL = 0x18011011ull;

static const uint32_t DLP_LINK1_TX_LANE_CONTROL_00_CONTROL = 0;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_00_CONTROL_LEN = 4;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_01_CONTROL = 4;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_01_CONTROL_LEN = 4;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_02_CONTROL = 8;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_02_CONTROL_LEN = 4;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_03_CONTROL = 12;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_03_CONTROL_LEN = 4;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_04_CONTROL = 16;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_04_CONTROL_LEN = 4;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_05_CONTROL = 20;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_05_CONTROL_LEN = 4;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_06_CONTROL = 24;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_06_CONTROL_LEN = 4;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_07_CONTROL = 28;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_07_CONTROL_LEN = 4;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL = 32;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_SP_CONTROL_LEN = 4;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_FAILED = 48;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_FAILED_LEN = 9;
//<< [DLP_LINK1_TX_LANE_CONTROL]
// iohs/reg00038.H

//>> [DLP_SEC_CONFIG]
static const uint64_t DLP_SEC_CONFIG = 0x1801100dull;

static const uint32_t DLP_SEC_CONFIG_ENABLE_ERR_INJ = 0;
static const uint32_t DLP_SEC_CONFIG_ENABLE_TRACE = 1;
static const uint32_t DLP_SEC_CONFIG_RESET_INJ = 2;
static const uint32_t DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE = 12;
static const uint32_t DLP_SEC_CONFIG_LINK0_PSAVE_OVERRIDE_LEN = 2;
static const uint32_t DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE = 14;
static const uint32_t DLP_SEC_CONFIG_LINK1_PSAVE_OVERRIDE_LEN = 2;
static const uint32_t DLP_SEC_CONFIG_SBE_ERROR_RATE = 16;
static const uint32_t DLP_SEC_CONFIG_SBE_ERROR_RATE_LEN = 2;
static const uint32_t DLP_SEC_CONFIG_RAND_ERROR_RATE = 18;
static const uint32_t DLP_SEC_CONFIG_RAND_ERROR_RATE_LEN = 6;
static const uint32_t DLP_SEC_CONFIG_INV_SH_ERROR_RATE = 24;
static const uint32_t DLP_SEC_CONFIG_INV_SH_ERROR_RATE_LEN = 2;
static const uint32_t DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE = 26;
static const uint32_t DLP_SEC_CONFIG_SYNC_HEADER_ERROR_RATE_LEN = 6;
static const uint32_t DLP_SEC_CONFIG_EDPL_RATE = 48;
static const uint32_t DLP_SEC_CONFIG_EDPL_RATE_LEN = 16;
//<< [DLP_SEC_CONFIG]
// iohs/reg00038.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00038.H"
#include "iohs/reg00039.H"
#include "iohs/reg00040.H"
#include "iohs/reg00041.H"
#endif
#endif