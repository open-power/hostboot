/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_5.H $       */
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

#ifndef __p10_scom_iohs_5_H_
#define __p10_scom_iohs_5_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_EPS_PSC_ADDR_TRAP_REG = 0x18010003ull;

static const uint32_t AXON_EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR = 0;
static const uint32_t AXON_EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN = 16;
static const uint32_t AXON_EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR = 16;
static const uint32_t AXON_EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT = 17;
static const uint32_t AXON_EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR = 18;
static const uint32_t AXON_EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN = 13;
static const uint32_t AXON_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY = 31;
static const uint32_t AXON_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR = 32;
static const uint32_t AXON_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION = 33;
static const uint32_t AXON_EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER = 34;
static const uint32_t AXON_EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID = 35;
static const uint32_t AXON_EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID_LEN = 4;
// iohs/reg00037.H

static const uint64_t AXON_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG = 0x18010007ull;

static const uint32_t AXON_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK = 0;
static const uint32_t AXON_EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN = 32;
// iohs/reg00037.H

static const uint64_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG = 0x18010001ull;

static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_P0_ERROR = 3;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_P0_ERROR = 5;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_GENERAL_TIMEOUT = 15;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_WDATA_PARITY_ERROR = 18;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_ADDRESS_PARITY_ERROR = 19;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_WDATA_PARITY_ERROR = 20;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_P0_ERROR = 21;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_RDATA_PARITY_ERROR = 22;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_P0_ERROR = 23;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_INTERFACE_MACHINE = 24;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_P2S_MACHINE = 25;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 26;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 27;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 28;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_WRITE_NVLD = 29;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_READ_NVLD = 30;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_ADDR_INVALID = 31;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_COMMAND_PARITY_ERROR = 32;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_GENERAL_TIMEOUT = 33;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 34;
static const uint32_t AXON_EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 35;
// iohs/reg00037.H

static const uint64_t AXON_EPS_THERM_WSUB_CONTROL_REG = 0x18050012ull;
// iohs/reg00037.H

static const uint64_t AXON_LOCAL_XSTOP_MASK = 0x18040019ull;

static const uint32_t AXON_LOCAL_XSTOP_MASK_01 = 1;
static const uint32_t AXON_LOCAL_XSTOP_MASK_02 = 2;
static const uint32_t AXON_LOCAL_XSTOP_MASK_03 = 3;
static const uint32_t AXON_LOCAL_XSTOP_MASK_04 = 4;
static const uint32_t AXON_LOCAL_XSTOP_MASK_05 = 5;
static const uint32_t AXON_LOCAL_XSTOP_MASK_06 = 6;
static const uint32_t AXON_LOCAL_XSTOP_MASK_07 = 7;
static const uint32_t AXON_LOCAL_XSTOP_MASK_08 = 8;
static const uint32_t AXON_LOCAL_XSTOP_MASK_09 = 9;
static const uint32_t AXON_LOCAL_XSTOP_MASK_10 = 10;
static const uint32_t AXON_LOCAL_XSTOP_MASK_11 = 11;
static const uint32_t AXON_LOCAL_XSTOP_MASK_12 = 12;
static const uint32_t AXON_LOCAL_XSTOP_MASK_13 = 13;
static const uint32_t AXON_LOCAL_XSTOP_MASK_14 = 14;
static const uint32_t AXON_LOCAL_XSTOP_MASK_15 = 15;
// iohs/reg00037.H

static const uint64_t AXON_PCB_OPCG_STOP = 0x18030030ull;

static const uint32_t AXON_PCB_OPCG_STOP_PCB_OPCGSTOP = 0;
// iohs/reg00037.H

static const uint64_t AXON_SCAN32 = 0x18038000ull;
// iohs/reg00037.H

static const uint64_t AXON_SCAN64 = 0x1803e000ull;
// iohs/reg00037.H

static const uint64_t AXON_SCAN_CAPTUREDR_LONG = 0x1803d000ull;
// iohs/reg00037.H

static const uint64_t AXON_TRA0_TR0_CONFIG_5 = 0x18010408ull;

static const uint32_t AXON_TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t AXON_TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t AXON_TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t AXON_TRA0_TR0_CONFIG_5_D_LEN = 24;
// iohs/reg00037.H

static const uint64_t NET_CTRL1_RWX = 0x180f0044ull;
static const uint64_t NET_CTRL1_RWX_WAND = 0x180f0045ull;
static const uint64_t NET_CTRL1_RWX_WOR = 0x180f0046ull;

static const uint32_t NET_CTRL1_PLL_CLKIN_SEL = 0;
static const uint32_t NET_CTRL1_CLK_DCC_BYPASS_EN = 1;
static const uint32_t NET_CTRL1_CLK_PDLY_BYPASS_EN = 2;
static const uint32_t NET_CTRL1_CLK_DIV_BYPASS_EN = 3;
static const uint32_t NET_CTRL1_REFCLK_CLKMUX0_SEL = 4;
static const uint32_t NET_CTRL1_REFCLK_CLKMUX1_SEL = 5;
static const uint32_t NET_CTRL1_PLL_BNDY_BYPASS_EN = 6;
static const uint32_t NET_CTRL1_DPLL_TEST_SEL = 8;
static const uint32_t NET_CTRL1_DPLL_TEST_SEL_LEN = 8;
static const uint32_t NET_CTRL1_SB_STRENGTH = 16;
static const uint32_t NET_CTRL1_SB_STRENGTH_LEN = 4;
static const uint32_t NET_CTRL1_ASYNC_TYPE = 20;
static const uint32_t NET_CTRL1_ASYNC_OBS = 21;
static const uint32_t NET_CTRL1_CPM_CAL_SET = 22;
static const uint32_t NET_CTRL1_SENSEADJ_RESET0 = 23;
static const uint32_t NET_CTRL1_SENSEADJ_RESET1 = 24;
static const uint32_t NET_CTRL1_CLK_PULSE_EN = 25;
static const uint32_t NET_CTRL1_CLK_PULSE_MODE = 26;
static const uint32_t NET_CTRL1_CLK_PULSE_MODE_LEN = 2;
// iohs/reg00037.H

}
}
#include "iohs/reg00037.H"
#endif
