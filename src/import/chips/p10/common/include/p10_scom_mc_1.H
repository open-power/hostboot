/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_1.H $         */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_mc_1_H_
#define __p10_scom_mc_1_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mc
{
#endif


static const uint64_t DBG_CBS_CC = 0x0c030013ull;

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
// mc/reg00001.H

static const uint64_t EPS_PSC_ADDR_TRAP_REG = 0x0c010003ull;

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
// mc/reg00001.H

static const uint64_t EPS_PSC_PSCOM_MODE_REG = 0x0c010000ull;

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
// mc/reg00001.H

static const uint64_t HEARTBEAT_REG = 0x0c0f0018ull;

static const uint32_t HEARTBEAT_REG_HEARTBEAT_DEAD = 0;
// mc/reg00001.H

static const uint64_t MBA_SCOMFIR_MCBERRPTQ = 0x0c010fe7ull;

static const uint32_t MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_AACR_PARITY_HOLD_OUT = 0;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCDBG_PARITY_HOLD_OUT = 5;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATCFG0_PE_HOLD_OUT = 7;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATCFG1_PE_HOLD_OUT = 8;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATCFG2_PE_HOLD_OUT = 9;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATCFG3_PE_HOLD_OUT = 10;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATFNA_PE_HOLD_OUT = 11;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATFNB_PE_HOLD_OUT = 12;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATFNC_PE_HOLD_OUT = 13;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATFND_PE_HOLD_OUT = 14;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATFNSEL_PE_HOLD_OUT = 15;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATCTL_PE_HOLD_OUT = 16;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN0_PE_HOLD_OUT = 17;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN1_PE_HOLD_OUT = 18;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN2_PE_HOLD_OUT = 19;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_MBA_MCBERRPTQ_MCEBUSEN3_PE_HOLD_OUT = 20;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATMSKA0_PE_HOLD_OUT = 21;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATMSKA1_PE_HOLD_OUT = 22;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATMSKB0_PE_HOLD_OUT = 23;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATMSKB1_PE_HOLD_OUT = 24;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATPATA0_PE_HOLD_OUT = 25;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATPATA1_PE_HOLD_OUT = 26;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATPATB0_PE_HOLD_OUT = 27;
static const uint32_t MBA_SCOMFIR_MCBERRPTQ_WATPATB1_PE_HOLD_OUT = 28;
// mc/reg00001.H

static const uint64_t MBA_SCOMFIR_MCEBUSEN0 = 0x0c010fa4ull;

static const uint32_t MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS = 0;
static const uint32_t MBA_SCOMFIR_MCEBUSEN0_MCEBUSEN0_EVENT_BUS_SELECTS_LEN = 64;
// mc/reg00001.H

static const uint64_t MBA_SCOMFIR_WATMSKB0 = 0x0c010f82ull;

static const uint32_t MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0 = 0;
static const uint32_t MBA_SCOMFIR_WATMSKB0_WAT_MASK_B0_LEN = 44;
// mc/reg00001.H

static const uint64_t OPCG_CAPT3 = 0x0c030012ull;

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
// mc/reg00001.H

static const uint64_t RECOV_INTERRUPT_REG = 0x0c0f001bull;

static const uint32_t RECOV_INTERRUPT_REG_RECOV = 0;
// mc/reg00001.H

static const uint64_t SCAN32 = 0x0c038000ull;

static const uint32_t SCAN32_SCAN32_REG = 0;
static const uint32_t SCAN32_SCAN32_REG_LEN = 32;
// mc/reg00001.H

static const uint64_t SCAN64 = 0x0c03e000ull;

static const uint32_t SCAN64_SCAN64_REG = 0;
static const uint32_t SCAN64_SCAN64_REG_LEN = 64;
// mc/reg00001.H

static const uint64_t SCOMFIR_MCTO = 0x0c010c1bull;

static const uint32_t SCOMFIR_MCTO_SELECT_PB_HANG_PULSE = 0;
static const uint32_t SCOMFIR_MCTO_SELECT_LOCAL_HANG_PULSE = 1;
static const uint32_t SCOMFIR_MCTO_RPT_HANG_SELECT = 2;
static const uint32_t SCOMFIR_MCTO_RPT_HANG_SELECT_LEN = 2;
static const uint32_t SCOMFIR_MCTO_RESERVED_4 = 4;
static const uint32_t SCOMFIR_MCTO_CL_TIMEOUT_VALUE = 5;
static const uint32_t SCOMFIR_MCTO_CL_TIMEOUT_VALUE_LEN = 3;
static const uint32_t SCOMFIR_MCTO_LOCAL_HANG_COMP = 8;
static const uint32_t SCOMFIR_MCTO_LOCAL_HANG_COMP_LEN = 16;
static const uint32_t SCOMFIR_MCTO_HANG_COMP = 24;
static const uint32_t SCOMFIR_MCTO_HANG_COMP_LEN = 8;
static const uint32_t SCOMFIR_MCTO_ENABLE_NONMIRROR_HANG = 32;
static const uint32_t SCOMFIR_MCTO_ENABLE_CHANNEL_HANG = 33;
static const uint32_t SCOMFIR_MCTO_ENABLE_APO_HANG = 34;
static const uint32_t SCOMFIR_MCTO_RESERVED_53 = 35;
static const uint32_t SCOMFIR_MCTO_DISABLE_HARDWARE_TRACE_MANAGER_HANG = 36;
static const uint32_t SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE = 37;
static const uint32_t SCOMFIR_MCTO_CHANNEL_TIMEOUT_VALUE_LEN = 3;
// mc/reg00001.H

static const uint64_t TRA0_TR0_TRACE_HI_DATA_REG = 0x0c010400ull;

static const uint32_t TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// mc/reg00001.H

static const uint64_t TRA1_TR0_CONFIG_4 = 0x0c010487ull;

static const uint32_t TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t TRA1_TR0_CONFIG_4_B_LEN = 24;
// mc/reg00001.H

#ifndef __PPE_HCODE__
}
}
#include "mc/reg00001.H"
#endif
#endif
