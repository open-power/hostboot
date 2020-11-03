/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_8.H $       */
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

#ifndef __p10_scom_iohs_8_H_
#define __p10_scom_iohs_8_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [AXON_CPLT_CONF1]
static const uint64_t AXON_CPLT_CONF1_RW = 0x18000009ull;
static const uint64_t AXON_CPLT_CONF1_WO_CLEAR = 0x18000029ull;
static const uint64_t AXON_CPLT_CONF1_WO_OR = 0x18000019ull;

static const uint32_t AXON_CPLT_CONF1_OD_IOVALID_DC = 0;
static const uint32_t AXON_CPLT_CONF1_EV_IOVALID_DC = 1;
//<< [AXON_CPLT_CONF1]
// iohs/reg00035.H

//>> [DLP_LINK0_RX_LANE_CONTROL]
static const uint64_t DLP_LINK0_RX_LANE_CONTROL = 0x18011012ull;

static const uint32_t DLP_LINK0_RX_LANE_CONTROL_DISABLED = 0;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_DISABLED_LEN = 9;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_BRINGUP = 12;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_BRINGUP_LEN = 9;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_SPARED = 24;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_SPARED_LEN = 9;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_LOCKED = 36;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_LOCKED_LEN = 9;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_FAILED = 48;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_FAILED_LEN = 9;
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS = 62; // p10:20,
static const uint32_t DLP_LINK0_RX_LANE_CONTROL_ERROR_STATUS_LEN = 2;
//<< [DLP_LINK0_RX_LANE_CONTROL]
// iohs/reg00035.H

//>> [DLP_OPTICAL_CONFIG]
static const uint64_t DLP_OPTICAL_CONFIG = 0x1801100full;

static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_DISABLE_BAD_LANE_COUNT = 0;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_NO_SPARE = 2;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_CRC_ERROR = 3;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION = 4;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_DURATION_LEN = 4;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX = 9;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_BAD_LANE_MAX_LEN = 7;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_DISABLE_LINK_FAIL_COUNT = 16;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION = 20;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_DURATION_LEN = 4;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX = 25;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_LINK_FAIL_MAX_LEN = 7;
static const uint32_t DLP_OPTICAL_CONFIG_CLEAR_LINK_FAIL_COUNTER = 32;
static const uint32_t DLP_OPTICAL_CONFIG_CLEAR_BAD_LANE_COUNTER = 33;
static const uint32_t DLP_OPTICAL_CONFIG_FULL_18_TX_LANE_SWAP = 39;
static const uint32_t DLP_OPTICAL_CONFIG_LINK0_RX_LANE_SWAP = 40;
static const uint32_t DLP_OPTICAL_CONFIG_LINK0_TX_LANE_SWAP = 41;
static const uint32_t DLP_OPTICAL_CONFIG_LINK1_RX_LANE_SWAP = 42;
static const uint32_t DLP_OPTICAL_CONFIG_LINK1_TX_LANE_SWAP = 43;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW = 44;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_LOW_LEN = 4;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START = 48;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_START_LEN = 4;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH = 52;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_ACK_QUEUE_HIGH_LEN = 4;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_OSC_SWITCH_ENABLE = 58;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_FAST_ASYNC_CROSS = 59;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT = 60;
static const uint32_t DLP_OPTICAL_CONFIG_CONFIG_RECAL_ABORT_TIMEOUT_LEN = 4;
//<< [DLP_OPTICAL_CONFIG]
// iohs/reg00035.H

//>> [ERROR_REG]
static const uint64_t ERROR_REG = 0x180f001full;

static const uint32_t ERROR_REG_CE_ERROR = 0;
static const uint32_t ERROR_REG_CHIPLET_ERRORS = 1;
static const uint32_t ERROR_REG_CHIPLET_ERRORS_LEN = 3;
static const uint32_t ERROR_REG_PARITY_ERROR = 4;
static const uint32_t ERROR_REG_DATA_BUFFER_ERROR = 5;
static const uint32_t ERROR_REG_ADDR_BUFFER_ERROR = 6;
static const uint32_t ERROR_REG_PCB_FSM_ERROR = 7;
static const uint32_t ERROR_REG_CL_FSM_ERROR = 8;
static const uint32_t ERROR_REG_INT_RX_FSM_ERROR = 9;
static const uint32_t ERROR_REG_INT_TX_FSM_ERROR = 10;
static const uint32_t ERROR_REG_INT_TYPE_ERROR = 11;
static const uint32_t ERROR_REG_CL_DATA_ERROR = 12;
static const uint32_t ERROR_REG_INFO_ERROR = 13;
static const uint32_t ERROR_REG_SEQ_ERROR = 14;
static const uint32_t ERROR_REG_CHIPLET_ATOMIC_LOCK_ERROR = 15;
static const uint32_t ERROR_REG_PCB_INTERFACE_ERROR = 16;
static const uint32_t ERROR_REG_CHIPLET_OFFLINE = 17;
static const uint32_t ERROR_REG_EDRAM_SEQUENCE_ERR = 18;
static const uint32_t ERROR_REG_CTRL_REG_PARITY_ERROR = 19;
static const uint32_t ERROR_REG_ADDRESS_REG_PARITY_ERROR = 20;
static const uint32_t ERROR_REG_TIMEOUT_REG_PARITY_ERROR = 21;
static const uint32_t ERROR_REG_CONFIG_REG_PARITY_ERROR = 22;
static const uint32_t ERROR_REG_DIV_REG_PARITY_ERROR = 23;
static const uint32_t ERROR_REG_PLL_UNLOCK_ERROR = 24;
static const uint32_t ERROR_REG_PLL_UNLOCK_ERROR_LEN = 8;
static const uint32_t ERROR_REG_QME_INTERFACE_PARITY_ERROR = 32;
static const uint32_t ERROR_REG_QME_DATA_PARITY_ERROR = 33;
static const uint32_t ERROR_REG_QME_ADDR_PARITY_ERROR = 34;
static const uint32_t ERROR_REG_QME_FSM_ERROR = 35;
static const uint32_t ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE = 36; // p10:20,
static const uint32_t ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE = 37; // p10:20,
//<< [ERROR_REG]
// iohs/reg00035.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00035.H"
#include "iohs/reg00036.H"
#include "iohs/reg00037.H"
#include "iohs/reg00038.H"
#endif
#endif
