/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_f.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __p10_scom_iohs_f_H_
#define __p10_scom_iohs_f_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_DLL_STATUS]
static const uint64_t DLP_DLL_STATUS = 0x18011028ull;

static const uint32_t DLP_DLL_STATUS_0_PHY_TRAINING_STATE = 0;
static const uint32_t DLP_DLL_STATUS_0_PHY_TRAINING_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_0_CURRENT_STATE = 4;
static const uint32_t DLP_DLL_STATUS_0_CURRENT_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_0_TIMEOUT_STATE = 8;
static const uint32_t DLP_DLL_STATUS_0_TIMEOUT_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_0_PRIOR_STATE = 12;
static const uint32_t DLP_DLL_STATUS_0_PRIOR_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_0_OPTICS_RST_B = 16;
static const uint32_t DLP_DLL_STATUS_0_OPTICS_IRQ = 17;
static const uint32_t DLP_DLL_STATUS_0_TRAINING = 18;
static const uint32_t DLP_DLL_STATUS_0_MAX_PKT_TIMER = 19;
static const uint32_t DLP_DLL_STATUS_0_MAX_PKT_TIMER_LEN = 5;
static const uint32_t DLP_DLL_STATUS_1_PHY_TRAINING_STATE = 24;
static const uint32_t DLP_DLL_STATUS_1_PHY_TRAINING_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_1_CURRENT_STATE = 28;
static const uint32_t DLP_DLL_STATUS_1_CURRENT_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_1_TIMEOUT_STATE = 32;
static const uint32_t DLP_DLL_STATUS_1_TIMEOUT_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_1_PRIOR_STATE = 36;
static const uint32_t DLP_DLL_STATUS_1_PRIOR_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_1_OPTICS_RST_B = 40;
static const uint32_t DLP_DLL_STATUS_1_OPTICS_IRQ = 41;
static const uint32_t DLP_DLL_STATUS_1_TRAINING = 42;
static const uint32_t DLP_DLL_STATUS_1_MAX_PKT_TIMER = 43;
static const uint32_t DLP_DLL_STATUS_1_MAX_PKT_TIMER_LEN = 5;
static const uint32_t DLP_DLL_STATUS_0_LINK_UP = 48;
static const uint32_t DLP_DLL_STATUS_1_LINK_UP = 49;
static const uint32_t DLP_DLL_STATUS_0_RESET_ACTIVE = 50;
static const uint32_t DLP_DLL_STATUS_1_RESET_ACTIVE = 51;
static const uint32_t DLP_DLL_STATUS_0_TDM_STATUS = 52;
static const uint32_t DLP_DLL_STATUS_0_TDM_STATUS_LEN = 2;
static const uint32_t DLP_DLL_STATUS_1_TDM_STATUS = 54;
static const uint32_t DLP_DLL_STATUS_1_TDM_STATUS_LEN = 2;
static const uint32_t DLP_DLL_STATUS_0_PSAVE_STATE = 56;
static const uint32_t DLP_DLL_STATUS_0_PSAVE_STATE_LEN = 4;
static const uint32_t DLP_DLL_STATUS_1_PSAVE_STATE = 60;
static const uint32_t DLP_DLL_STATUS_1_PSAVE_STATE_LEN = 4;
//<< [DLP_DLL_STATUS]
// iohs/reg00067.H

//>> [DLP_LINK0_ERROR_STATUS]
static const uint64_t DLP_LINK0_ERROR_STATUS = 0x18011016ull;

static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_RESET_KEEPER = 0;
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_RESET_KEEPER = 0; // p10:20,
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE = 1;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_CE_LEN = 7;
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ACK_FIFO_PARITY_ERROR = 1; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_CE = 2; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_CE = 3; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ODL_FRAME_CE = 4; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_CE = 5; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_DATA = 6; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_DATA = 7; // p10:20,
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE = 8;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UE_LEN = 4;
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_UE = 8; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_UE = 9; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ODL_FRAME_UE_CTL = 10; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_UE_CTL = 11; // p10:20,
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC = 12;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_OSC_LEN = 2;
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_OPT_OSC_SWITCH = 12; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_RX_OPT_OSC_SWITCH = 13; // p10:20,
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN = 16;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_TRAIN_LEN = 5;
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_INIT_SEQ_DOWN = 16; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_TSTART_GIVEUP = 17; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_LANE_MISMATCH = 18; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_LINK_MISMATCH = 19; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_RX_SLOWER = 20; // p10:20,
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV = 24;
static const uint32_t DLP_LINK0_ERROR_STATUS_LINK0_ERROR_STATUS_UNRECOV_LEN = 14;
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ACK_FIFO_OVERFLOW = 24; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_REPLAY_BUFFER_OVERFLOW = 25; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_OVERFLOW = 26; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_SEQ_LINK_ERROR = 27; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_CRC_COUNT_FAIL = 28; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_LINK_PAIR_ERROR = 29; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_REMOTE_CRC_COUNT_FAIL = 30; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_REMOTE_UNRECOV = 31; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_REMOTE_INTERNAL_ERROR = 32; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_REMOTE_UE = 33; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_REMOTE_SW_DISABLE = 34; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ODL_REPLAY_OVERFLOW = 35; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ODL_TL_RL_ERROR = 36; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_DLX_RL_ERROR = 37; // p10:20,
static const uint32_t DLP_LINK0_ERROR_STATUS_INTERNAL = 38;
static const uint32_t DLP_LINK0_ERROR_STATUS_INTERNAL_LEN = 26;
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ODL_DATA_PARITY_ERROR = 38; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ODL_CTL_PARTIY_ERROR = 39; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_TOGGLE_ERROR = 40; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_RECEIVE_LANE_BUFFER_OVERFLOW = 41; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_PACKET_STATE_ERROR = 42; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_T1_TRANSMIT_ERROR = 43; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_BYTES_OUTPUT_PARITY_ERROR = 44; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_IN_ERROR = 45; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_FRAME_BUFFER_TOGGLE_OUT_ERROR = 46; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_OUTPUT_REPLAY_PARITY_ERROR = 47; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_ERROR = 48; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_OVERFLOW_BYTES_PARITY_ERROR = 49; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_INVALID_STATE_ERROR = 50; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_RX_DATA_PARITY_ERROR = 51; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_RX_PARITY_ERROR = 52; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_TX_DATA_PARITY_ERROR = 53; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_SHIFT_AMOUNT_ERROR = 54; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ACK_FIFO_LINK_ERROR = 55; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_ERROR = 56; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_EARLY_OV_BYTES_PARITY_ERROR = 57; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_PROTOCOL_ERROR = 58; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_ACK_FIFO_UNDERFLOW = 59; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_RECEIVE_BUFFER_OVERFLOW = 60; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_FRAME_CTL_PARITY_ERROR = 61; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_RECAL_INVALID_STATE_ERROR = 62; // p10:20,
static const uint32_t P10_20_DLP_LINK0_ERROR_STATUS_RECEIVE_CONTROL_ERROR = 63; // p10:20,
//<< [DLP_LINK0_ERROR_STATUS]
// iohs/reg00067.H

//>> [TIMEOUT_REG]
static const uint64_t TIMEOUT_REG = 0x180f0010ull;

static const uint32_t TIMEOUT_REG_INT_TIMEOUT = 0;
static const uint32_t TIMEOUT_REG_INT_TIMEOUT_LEN = 2;
//<< [TIMEOUT_REG]
// iohs/reg00070.H

//>> [IOO_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG]
static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG = 0x800c640010012c3full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET_LEN = 15;
//<< [IOO_TX0_TXCTL_CTL_REGS_TX_CNTL5_PG]
// iohs/reg00070.H

//>> [IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG]
static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG = 0x800cc40010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15_LEN = 16;
//<< [IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG]
// iohs/reg00070.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00067.H"
#include "iohs/reg00068.H"
#include "iohs/reg00069.H"
#include "iohs/reg00070.H"
#endif
#endif
