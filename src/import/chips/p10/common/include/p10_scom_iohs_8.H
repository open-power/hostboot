/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_8.H $       */
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

#ifndef __p10_scom_iohs_8_H_
#define __p10_scom_iohs_8_H_


namespace scomt
{
namespace iohs
{


static const uint64_t ASSIST_INTERRUPT_REG = 0x180f0011ull;
// iohs/reg00008.H

static const uint64_t AXON_CPLT_CONF1_RW = 0x18000009ull;
static const uint64_t AXON_CPLT_CONF1_WO_CLEAR = 0x18000029ull;
static const uint64_t AXON_CPLT_CONF1_WO_OR = 0x18000019ull;

static const uint32_t AXON_CPLT_CONF1_OD_IOVALID_DC = 0;
static const uint32_t AXON_CPLT_CONF1_EV_IOVALID_DC = 1;
// iohs/reg00008.H

static const uint64_t AXON_CPLT_CTRL1_RW = 0x18000001ull;
static const uint64_t AXON_CPLT_CTRL1_WO_CLEAR = 0x18000021ull;
static const uint64_t AXON_CPLT_CTRL1_WO_OR = 0x18000011ull;

static const uint32_t AXON_CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC = 0;
static const uint32_t AXON_CPLT_CTRL1_VITL_FENCE_DC = 3;
static const uint32_t AXON_CPLT_CTRL1_REGION0_FENCE_DC = 4;
static const uint32_t AXON_CPLT_CTRL1_REGION1_FENCE_DC = 5;
static const uint32_t AXON_CPLT_CTRL1_REGION2_FENCE_DC = 6;
static const uint32_t AXON_CPLT_CTRL1_REGION3_FENCE_DC = 7;
static const uint32_t AXON_CPLT_CTRL1_REGION4_FENCE_DC = 8;
static const uint32_t AXON_CPLT_CTRL1_REGION5_FENCE_DC = 9;
static const uint32_t AXON_CPLT_CTRL1_REGION6_FENCE_DC = 10;
static const uint32_t AXON_CPLT_CTRL1_REGION7_FENCE_DC = 11;
static const uint32_t AXON_CPLT_CTRL1_REGION8_FENCE_DC = 12;
static const uint32_t AXON_CPLT_CTRL1_REGION9_FENCE_DC = 13;
static const uint32_t AXON_CPLT_CTRL1_REGION10_FENCE_DC = 14;
static const uint32_t AXON_CPLT_CTRL1_REGION11_FENCE_DC = 15;
static const uint32_t AXON_CPLT_CTRL1_REGION12_FENCE_DC = 16;
static const uint32_t AXON_CPLT_CTRL1_REGION13_FENCE_DC = 17;
static const uint32_t AXON_CPLT_CTRL1_REGION14_FENCE_DC = 18;
// iohs/reg00008.H

static const uint64_t AXON_EPS_DBG_MODE_REG = 0x180107c0ull;

static const uint32_t AXON_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t AXON_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t AXON_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t AXON_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t AXON_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t AXON_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t AXON_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t AXON_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t AXON_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t AXON_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 11;
static const uint32_t AXON_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t AXON_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t AXON_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t AXON_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t AXON_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t AXON_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t AXON_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// iohs/reg00008.H

static const uint64_t AXON_EPS_THERM_WSUB_SKITTER_DATA2 = 0x1805001bull;
// iohs/reg00008.H

static const uint64_t AXON_EPS_THERM_WSUB_MODE_REG = 0x1805000full;

static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR = 0;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT = 1;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA = 2;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN = 3;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA = 5;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT = 6;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN = 4;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA = 10;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN = 2;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE = 12;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL = 13;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK = 14;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL = 16;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN = 4;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 = 20;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN = 3;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 = 24;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN = 3;
static const uint32_t AXON_EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 = 28;
// iohs/reg00008.H

static const uint64_t EDRAM_STATUS = 0x180f0029ull;

static const uint32_t EDRAM_STATUS_EDRAM_STAT = 0;
static const uint32_t EDRAM_STATUS_EDRAM_STAT_LEN = 4;
// iohs/reg00008.H

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
// iohs/reg00008.H

}
}
#include "iohs/reg00008.H"
#endif
