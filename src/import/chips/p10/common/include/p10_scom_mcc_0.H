/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_0.H $        */
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

#ifndef __p10_scom_mcc_0_H_
#define __p10_scom_mcc_0_H_


namespace scomt
{
namespace mcc
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t FIR_WOF_REG = 0x0c011008ull;

static const uint32_t FIR_WOF_REG_DLP_FIR_WOF = 0;
static const uint32_t FIR_WOF_REG_DLP_FIR_WOF_LEN = 62;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK0_INFO = 0x0c011014ull;

static const uint32_t LINK0_INFO_MAX_TIMEOUT = 0;
static const uint32_t LINK0_INFO_MAX_TIMEOUT_LEN = 16;
static const uint32_t LINK0_INFO_FRAME_CAP_VALID = 16;
static const uint32_t LINK0_INFO_FRAME_CAP_INST = 17;
static const uint32_t LINK0_INFO_FRAME_CAP_ADDR = 18;
static const uint32_t LINK0_INFO_FRAME_CAP_ADDR_LEN = 6;
static const uint32_t LINK0_INFO_FRAME_CAP_SYN = 24;
static const uint32_t LINK0_INFO_FRAME_CAP_SYN_LEN = 8;
static const uint32_t LINK0_INFO_REPLAY_CAP_VALID = 32;
static const uint32_t LINK0_INFO_REPLAY_CAP_INST = 33;
static const uint32_t LINK0_INFO_REPLAY_CAP_INST_LEN = 2;
static const uint32_t LINK0_INFO_REPLAY_CAP_ADDR = 35;
static const uint32_t LINK0_INFO_REPLAY_CAP_ADDR_LEN = 9;
static const uint32_t LINK0_INFO_REPLAY_CAP_SYN = 44;
static const uint32_t LINK0_INFO_REPLAY_CAP_SYN_LEN = 8;
static const uint32_t LINK0_INFO_ACK_FIFO_CAP_VALID = 52;
static const uint32_t LINK0_INFO_ACK_FIFO_CAP_ADDR = 55;
static const uint32_t LINK0_INFO_ACK_FIFO_CAP_ADDR_LEN = 9;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK0_RX_LANE_CONTROL = 0x0c011012ull;

static const uint32_t LINK0_RX_LANE_CONTROL_DISABLED = 0;
static const uint32_t LINK0_RX_LANE_CONTROL_DISABLED_LEN = 9;
static const uint32_t LINK0_RX_LANE_CONTROL_BRINGUP = 12;
static const uint32_t LINK0_RX_LANE_CONTROL_BRINGUP_LEN = 9;
static const uint32_t LINK0_RX_LANE_CONTROL_SPARED = 24;
static const uint32_t LINK0_RX_LANE_CONTROL_SPARED_LEN = 9;
static const uint32_t LINK0_RX_LANE_CONTROL_LOCKED = 36;
static const uint32_t LINK0_RX_LANE_CONTROL_LOCKED_LEN = 9;
static const uint32_t LINK0_RX_LANE_CONTROL_FAILED = 48;
static const uint32_t LINK0_RX_LANE_CONTROL_FAILED_LEN = 9;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK1_ERROR_STATUS = 0x0c011017ull;

static const uint32_t LINK1_ERROR_STATUS_RESET_KEEPER = 0;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_CE = 1;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_CE_LEN = 7;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_UE = 8;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_UE_LEN = 4;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_OSC = 12;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_OSC_LEN = 2;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_TRAIN = 16;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_TRAIN_LEN = 5;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_UNRECOV = 24;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_UNRECOV_LEN = 14;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_INTERNAL = 40;
static const uint32_t LINK1_ERROR_STATUS_ERROR_STATUS_INTERNAL_LEN = 24;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t MC_OMI_FIR_WOF_REG = 0x0c011b48ull;

static const uint32_t MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF = 0;
static const uint32_t MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF_LEN = 62;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t MISC_ERROR_STATUS = 0x0c011029ull;

static const uint32_t MISC_ERROR_STATUS_MISC_RESET_KEEPER = 0;
static const uint32_t MISC_ERROR_STATUS_DLX0_ERROR_STATUS = 8;
static const uint32_t MISC_ERROR_STATUS_DLX0_ERROR_STATUS_LEN = 8;
static const uint32_t MISC_ERROR_STATUS_DLX1_ERROR_STATUS = 16;
static const uint32_t MISC_ERROR_STATUS_DLX1_ERROR_STATUS_LEN = 8;
static const uint32_t MISC_ERROR_STATUS_OLL_ERROR_STATUS = 24;
static const uint32_t MISC_ERROR_STATUS_OLL_ERROR_STATUS_LEN = 18;
static const uint32_t MISC_ERROR_STATUS_ODL_ERROR_STATUS = 44;
static const uint32_t MISC_ERROR_STATUS_ODL_ERROR_STATUS_LEN = 18;
// mcc/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REGS_PRX1_DLR_APOR = 0x0c01103eull;

static const uint32_t REGS_PRX1_DLR_APOR_ACTIVITY_ACCUM = 0;
static const uint32_t REGS_PRX1_DLR_APOR_ACTIVITY_ACCUM_LEN = 32;
static const uint32_t REGS_PRX1_DLR_APOR_BASE_ACCUM = 32;
static const uint32_t REGS_PRX1_DLR_APOR_BASE_ACCUM_LEN = 32;
// mcc/reg00000.H

}
}
#include "mcc/reg00000.H"
#endif
