/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_1.H $       */
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

#ifndef __p10_scom_perv_1_H_
#define __p10_scom_perv_1_H_


namespace scomt
{
namespace perv
{


static const uint64_t DBG_CBS_CC = 0x00030013ull;

static const uint32_t DBG_CBS_CC_DBG_RESET_EP = 0;
static const uint32_t DBG_CBS_CC_DBG_OPCG_IP = 1;
static const uint32_t DBG_CBS_CC_DBG_VITL_CLKOFF = 2;
static const uint32_t DBG_CBS_CC_DBG_TEST_ENABLE = 3;
static const uint32_t DBG_CBS_CC_DBG_CBS_REQ = 4;
static const uint32_t DBG_CBS_CC_DBG_CBS_CMD = 5;
static const uint32_t DBG_CBS_CC_DBG_CBS_CMD_LEN = 3;
static const uint32_t DBG_CBS_CC_DBG_CBS_STATE = 8;
static const uint32_t DBG_CBS_CC_DBG_CBS_STATE_LEN = 5;
static const uint32_t DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE = 13;
static const uint32_t DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR = 14;
static const uint32_t DBG_CBS_CC_DBG_PCB_IDLE = 15;
static const uint32_t DBG_CBS_CC_DBG_CURRENT_OPCG_MODE = 16;
static const uint32_t DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN = 4;
static const uint32_t DBG_CBS_CC_DBG_LAST_OPCG_MODE = 20;
static const uint32_t DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN = 4;
static const uint32_t DBG_CBS_CC_DBG_PCB_ERROR = 24;
static const uint32_t DBG_CBS_CC_DBG_PARITY_ERROR = 25;
static const uint32_t DBG_CBS_CC_DBG_CC_ERROR = 26;
static const uint32_t DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED = 27;
static const uint32_t DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET = 28;
static const uint32_t DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE = 29;
static const uint32_t DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE = 30;
static const uint32_t DBG_CBS_CC_TP_TPFSI_CBS_ACK = 31;
// perv/reg00001.H

static const uint64_t EPS_PSC_ADDR_TRAP_REG = 0x00010003ull;

static const uint32_t EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR = 0;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN = 16;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR = 16;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT = 17;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR = 18;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN = 13;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY = 31;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR = 32;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION = 33;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER = 34;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID = 35;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID_LEN = 4;
// perv/reg00001.H

static const uint64_t EPS_PSC_PSCOM_MODE_REG = 0x00010000ull;

static const uint32_t EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR = 0;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR = 1;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR = 3;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE = 4;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT = 5;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN = 2;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS = 7;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE = 8;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT = 9;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN = 3;
// perv/reg00001.H

static const uint64_t EPS_THERM_WSUB2_DTS_TRC_RESULT = 0x00050023ull;

static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR = 44;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT = 48;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT_LEN = 16;
// perv/reg00001.H

static const uint64_t EPS_THERM_WSUB2_ERR_STATUS_REG = 0x00050033ull;
// perv/reg00001.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_DATA1 = 0x0005003aull;
// perv/reg00001.H

static const uint64_t HEARTBEAT_REG = 0x000f0018ull;

static const uint32_t HEARTBEAT_REG_HEARTBEAT_DEAD = 0;
// perv/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR1_CONFIG_2 = 0x00018225ull;

static const uint32_t L3TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t L3TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t L3TRA0_TR1_CONFIG_2_B_LEN = 24;
// perv/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA1_TR0_CONFIG_4 = 0x00018247ull;

static const uint32_t L3TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t L3TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t L3TRA1_TR0_CONFIG_4_B_LEN = 24;
// perv/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA2_TR0_CONFIG_3 = 0x00018286ull;

static const uint32_t L3TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t L3TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t L3TRA2_TR0_CONFIG_3_D_LEN = 24;
// perv/reg00001.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA3_TR1_CONFIG_5 = 0x000182e8ull;

static const uint32_t L3TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t L3TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t L3TRA3_TR1_CONFIG_5_D_LEN = 24;
// perv/reg00001.H

static const uint64_t OPCG_CAPT3 = 0x00030012ull;

static const uint32_t OPCG_CAPT3_07EVEN = 4;
static const uint32_t OPCG_CAPT3_07EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_07ODD = 9;
static const uint32_t OPCG_CAPT3_07ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_08EVEN = 14;
static const uint32_t OPCG_CAPT3_08EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_08ODD = 19;
static const uint32_t OPCG_CAPT3_08ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_09EVEN = 24;
static const uint32_t OPCG_CAPT3_09EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_09ODD = 29;
static const uint32_t OPCG_CAPT3_09ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_10EVEN = 34;
static const uint32_t OPCG_CAPT3_10EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_10ODD = 39;
static const uint32_t OPCG_CAPT3_10ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_11EVEN = 44;
static const uint32_t OPCG_CAPT3_11EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_11ODD = 49;
static const uint32_t OPCG_CAPT3_11ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_12EVEN = 54;
static const uint32_t OPCG_CAPT3_12EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_12ODD = 59;
static const uint32_t OPCG_CAPT3_12ODD_LEN = 5;
// perv/reg00001.H

static const uint64_t RECOV_INTERRUPT_REG = 0x000f001bull;
// perv/reg00001.H

static const uint64_t SCAN32 = 0x00038000ull;
// perv/reg00001.H

static const uint64_t SCAN64 = 0x0003e000ull;
// perv/reg00001.H

static const uint64_t TRA0_TR0_TRACE_HI_DATA_REG = 0x00010400ull;

static const uint32_t TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00001.H

static const uint64_t TRA0_TR1_CONFIG_2 = 0x00010445ull;

static const uint32_t TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t TRA0_TR1_CONFIG_2_B_LEN = 24;
// perv/reg00001.H

static const uint64_t TRA1_TR0_CONFIG_4 = 0x00010487ull;

static const uint32_t TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t TRA1_TR0_CONFIG_4_B_LEN = 24;
// perv/reg00001.H

static const uint64_t TRA2_TR0_CONFIG_3 = 0x00010506ull;

static const uint32_t TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t TRA2_TR0_CONFIG_3_D_LEN = 24;
// perv/reg00001.H

static const uint64_t TRA3_TR1_TRACE_LO_DATA_REG = 0x000105c1ull;

static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00001.H

static const uint64_t TRA3_TR1_CONFIG_5 = 0x000105c8ull;

static const uint32_t TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t TRA3_TR1_CONFIG_5_D_LEN = 24;
// perv/reg00001.H

static const uint64_t TRA4_TR1_CONFIG_4 = 0x00010647ull;

static const uint32_t TRA4_TR1_CONFIG_4_A = 0;
static const uint32_t TRA4_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TRA4_TR1_CONFIG_4_B = 24;
static const uint32_t TRA4_TR1_CONFIG_4_B_LEN = 24;
// perv/reg00001.H

static const uint64_t TRA5_TR0_CONFIG_2 = 0x00010685ull;

static const uint32_t TRA5_TR0_CONFIG_2_A = 0;
static const uint32_t TRA5_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TRA5_TR0_CONFIG_2_B = 24;
static const uint32_t TRA5_TR0_CONFIG_2_B_LEN = 24;
// perv/reg00001.H

static const uint64_t TRA6_TR0_CONFIG_5 = 0x00010708ull;

static const uint32_t TRA6_TR0_CONFIG_5_C = 0;
static const uint32_t TRA6_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA6_TR0_CONFIG_5_D = 24;
static const uint32_t TRA6_TR0_CONFIG_5_D_LEN = 24;
// perv/reg00001.H

}
}
#include "perv/reg00001.H"
#endif
