/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_f.H $       */
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

#ifndef __p10_scom_iohs_f_H_
#define __p10_scom_iohs_f_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_DBG_CBS_CC = 0x18030013ull;

static const uint32_t AXON_DBG_CBS_CC_DBG_RESET_EP = 0;
static const uint32_t AXON_DBG_CBS_CC_DBG_OPCG_IP = 1;
static const uint32_t AXON_DBG_CBS_CC_DBG_VITL_CLKOFF = 2;
static const uint32_t AXON_DBG_CBS_CC_DBG_TEST_ENABLE = 3;
static const uint32_t AXON_DBG_CBS_CC_DBG_CBS_REQ = 4;
static const uint32_t AXON_DBG_CBS_CC_DBG_CBS_CMD = 5;
static const uint32_t AXON_DBG_CBS_CC_DBG_CBS_CMD_LEN = 3;
static const uint32_t AXON_DBG_CBS_CC_DBG_CBS_STATE = 8;
static const uint32_t AXON_DBG_CBS_CC_DBG_CBS_STATE_LEN = 5;
static const uint32_t AXON_DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE = 13;
static const uint32_t AXON_DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR = 14;
static const uint32_t AXON_DBG_CBS_CC_DBG_PCB_IDLE = 15;
static const uint32_t AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE = 16;
static const uint32_t AXON_DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN = 4;
static const uint32_t AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE = 20;
static const uint32_t AXON_DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN = 4;
static const uint32_t AXON_DBG_CBS_CC_DBG_PCB_ERROR = 24;
static const uint32_t AXON_DBG_CBS_CC_DBG_PARITY_ERROR = 25;
static const uint32_t AXON_DBG_CBS_CC_DBG_CC_ERROR = 26;
static const uint32_t AXON_DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED = 27;
static const uint32_t AXON_DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET = 28;
static const uint32_t AXON_DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE = 29;
static const uint32_t AXON_DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE = 30;
static const uint32_t AXON_DBG_CBS_CC_TP_TPFSI_CBS_ACK = 31;
// iohs/reg00015.H

static const uint64_t AXON_EPS_DBG_XTRA_TRACE_MODE = 0x180107d1ull;

static const uint32_t AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA = 0;
static const uint32_t AXON_EPS_DBG_XTRA_TRACE_MODE_XTRA_TRACE_MODE_DATA_LEN = 42;
// iohs/reg00015.H

static const uint64_t AXON_EPS_FIR_GXSTOP1_MASK_REG = 0x18040014ull;

static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_SUM_XSTOP = 0;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_SUM_RECOV = 1;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_SUM_SPATTN = 2;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_SUM_LOCAL_XSTOP = 3;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_SUM_TYPE4 = 4;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_SYSTEM_XSTOP = 5;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_OOB1 = 6;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t AXON_EPS_FIR_GXSTOP1_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// iohs/reg00015.H

static const uint64_t AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG = 0x18010008ull;

static const uint32_t AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK = 1;
static const uint32_t AXON_EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN = 31;
// iohs/reg00015.H

static const uint64_t AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ = 0x1805001cull;

static const uint32_t AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t AXON_EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
// iohs/reg00015.H

static const uint64_t AXON_ERROR_STATUS = 0x1803000full;

static const uint32_t AXON_ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR = 0;
static const uint32_t AXON_ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR = 1;
static const uint32_t AXON_ERROR_STATUS_PCB_PARITY_ON_CMD_ERR = 2;
static const uint32_t AXON_ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR = 3;
static const uint32_t AXON_ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR = 4;
static const uint32_t AXON_ERROR_STATUS_PCB_PARITY_ON_DATA_ERR = 5;
static const uint32_t AXON_ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR = 6;
static const uint32_t AXON_ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR = 7;
static const uint32_t AXON_ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR = 8;
static const uint32_t AXON_ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR = 9;
static const uint32_t AXON_ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR = 10;
static const uint32_t AXON_ERROR_STATUS_SCAN_COLLISION_ERR = 11;
static const uint32_t AXON_ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR = 12;
static const uint32_t AXON_ERROR_STATUS_OPCG_TRIGGER_ERR = 13;
static const uint32_t AXON_ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR = 14;
static const uint32_t AXON_ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR = 15;
static const uint32_t AXON_ERROR_STATUS_PARITY_ON_OPCG_SM_ERR = 16;
static const uint32_t AXON_ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR = 17;
static const uint32_t AXON_ERROR_STATUS_PARITY_ON_OPCG_REG_ERR = 18;
static const uint32_t AXON_ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR = 19;
static const uint32_t AXON_ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR = 20;
static const uint32_t AXON_ERROR_STATUS_PARITY_ON_GPIO_REG_ERR = 21;
static const uint32_t AXON_ERROR_STATUS_CLKCMD_REQUEST_ERR = 22;
static const uint32_t AXON_ERROR_STATUS_CBS_PROTOCOL_ERR = 23;
static const uint32_t AXON_ERROR_STATUS_VITL_ALIGN_ERR = 24;
static const uint32_t AXON_ERROR_STATUS_UNIT_SYNC_LVL_ERR = 25;
static const uint32_t AXON_ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR = 26;
static const uint32_t AXON_ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR = 27;
// iohs/reg00015.H

static const uint64_t AXON_OPCG_CAPT3 = 0x18030012ull;

static const uint32_t AXON_OPCG_CAPT3_07EVEN = 4;
static const uint32_t AXON_OPCG_CAPT3_07EVEN_LEN = 5;
static const uint32_t AXON_OPCG_CAPT3_07ODD = 9;
static const uint32_t AXON_OPCG_CAPT3_07ODD_LEN = 5;
static const uint32_t AXON_OPCG_CAPT3_08EVEN = 14;
static const uint32_t AXON_OPCG_CAPT3_08EVEN_LEN = 5;
static const uint32_t AXON_OPCG_CAPT3_08ODD = 19;
static const uint32_t AXON_OPCG_CAPT3_08ODD_LEN = 5;
static const uint32_t AXON_OPCG_CAPT3_09EVEN = 24;
static const uint32_t AXON_OPCG_CAPT3_09EVEN_LEN = 5;
static const uint32_t AXON_OPCG_CAPT3_09ODD = 29;
static const uint32_t AXON_OPCG_CAPT3_09ODD_LEN = 5;
static const uint32_t AXON_OPCG_CAPT3_10EVEN = 34;
static const uint32_t AXON_OPCG_CAPT3_10EVEN_LEN = 5;
static const uint32_t AXON_OPCG_CAPT3_10ODD = 39;
static const uint32_t AXON_OPCG_CAPT3_10ODD_LEN = 5;
static const uint32_t AXON_OPCG_CAPT3_11EVEN = 44;
static const uint32_t AXON_OPCG_CAPT3_11EVEN_LEN = 5;
static const uint32_t AXON_OPCG_CAPT3_11ODD = 49;
static const uint32_t AXON_OPCG_CAPT3_11ODD_LEN = 5;
static const uint32_t AXON_OPCG_CAPT3_12EVEN = 54;
static const uint32_t AXON_OPCG_CAPT3_12EVEN_LEN = 5;
static const uint32_t AXON_OPCG_CAPT3_12ODD = 59;
static const uint32_t AXON_OPCG_CAPT3_12ODD_LEN = 5;
// iohs/reg00015.H

static const uint64_t AXON_RFIR = 0x18040001ull;

static const uint32_t AXON_RFIR_ANY_RECOV = 0;
static const uint32_t AXON_RFIR_RECOV_ANY_LOCAL_XSTOP = 1;
static const uint32_t AXON_RFIR_RESERVED2R = 2;
static const uint32_t AXON_RFIR_RESERVED3R = 3;
static const uint32_t AXON_RFIR_RECOV_PERV = 4;
static const uint32_t AXON_RFIR_RECOV_IN05 = 5;
static const uint32_t AXON_RFIR_RECOV_IN06 = 6;
static const uint32_t AXON_RFIR_RECOV_IN07 = 7;
static const uint32_t AXON_RFIR_RECOV_IN08 = 8;
static const uint32_t AXON_RFIR_RECOV_IN09 = 9;
static const uint32_t AXON_RFIR_RECOV_IN10 = 10;
static const uint32_t AXON_RFIR_RECOV_IN11 = 11;
static const uint32_t AXON_RFIR_RECOV_IN12 = 12;
static const uint32_t AXON_RFIR_RECOV_IN13 = 13;
static const uint32_t AXON_RFIR_RECOV_IN14 = 14;
static const uint32_t AXON_RFIR_RECOV_IN15 = 15;
static const uint32_t AXON_RFIR_RECOV_IN16 = 16;
static const uint32_t AXON_RFIR_RECOV_IN17 = 17;
static const uint32_t AXON_RFIR_RECOV_IN18 = 18;
static const uint32_t AXON_RFIR_RECOV_IN19 = 19;
static const uint32_t AXON_RFIR_RECOV_IN20 = 20;
static const uint32_t AXON_RFIR_RECOV_IN21 = 21;
static const uint32_t AXON_RFIR_RECOV_IN22 = 22;
static const uint32_t AXON_RFIR_RECOV_IN23 = 23;
static const uint32_t AXON_RFIR_RECOV_IN24 = 24;
static const uint32_t AXON_RFIR_RECOV_IN25 = 25;
static const uint32_t AXON_RFIR_RECOV_IN26 = 26;
static const uint32_t AXON_RFIR_RECOV_IN27 = 27;
static const uint32_t AXON_RFIR_RECOV_IN28 = 28;
static const uint32_t AXON_RFIR_RECOV_IN29 = 29;
static const uint32_t AXON_RFIR_RECOV_IN30 = 30;
static const uint32_t AXON_RFIR_RECOV_IN31 = 31;
static const uint32_t AXON_RFIR_RECOV_IN32 = 32;
static const uint32_t AXON_RFIR_RECOV_IN33 = 33;
static const uint32_t AXON_RFIR_RECOV_IN34 = 34;
static const uint32_t AXON_RFIR_RECOV_IN35 = 35;
static const uint32_t AXON_RFIR_RECOV_IN36 = 36;
static const uint32_t AXON_RFIR_RECOV_IN37 = 37;
static const uint32_t AXON_RFIR_RECOV_IN38 = 38;
static const uint32_t AXON_RFIR_RECOV_IN39 = 39;
static const uint32_t AXON_RFIR_RECOV_IN40 = 40;
static const uint32_t AXON_RFIR_RECOV_IN41 = 41;
static const uint32_t AXON_RFIR_RECOV_IN42 = 42;
static const uint32_t AXON_RFIR_RECOV_IN43 = 43;
static const uint32_t AXON_RFIR_RECOV_IN44 = 44;
static const uint32_t AXON_RFIR_RECOV_IN45 = 45;
static const uint32_t AXON_RFIR_RECOV_IN46 = 46;
static const uint32_t AXON_RFIR_RECOV_IN47 = 47;
static const uint32_t AXON_RFIR_RECOV_IN48 = 48;
static const uint32_t AXON_RFIR_RECOV_IN49 = 49;
static const uint32_t AXON_RFIR_RECOV_IN50 = 50;
static const uint32_t AXON_RFIR_RECOV_IN51 = 51;
static const uint32_t AXON_RFIR_RECOV_IN52 = 52;
static const uint32_t AXON_RFIR_RECOV_IN53 = 53;
// iohs/reg00015.H

static const uint64_t MULTICAST_GROUP_3 = 0x180f0003ull;

static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP = 3;
static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN = 3;
// iohs/reg00015.H

static const uint64_t PROTECT_MODE_REG = 0x180f03feull;

static const uint32_t PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// iohs/reg00015.H

static const uint64_t TIMEOUT_REG = 0x180f0010ull;
// iohs/reg00015.H

static const uint64_t VITAL_SCAN_OUT = 0x180f0017ull;
// iohs/reg00015.H

}
}
#include "iohs/reg00015.H"
#endif
