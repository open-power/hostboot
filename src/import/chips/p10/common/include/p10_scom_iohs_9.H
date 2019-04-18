/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_9.H $       */
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

#ifndef __p10_scom_iohs_9_H_
#define __p10_scom_iohs_9_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_CTRL_ATOMIC_LOCK_REG = 0x180003ffull;

static const uint32_t AXON_CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t AXON_CTRL_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t AXON_CTRL_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t AXON_CTRL_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t AXON_CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// iohs/reg00041.H

static const uint64_t AXON_EPS_FIR_SUM_MASK_REG = 0x18040017ull;

static const uint32_t AXON_EPS_FIR_SUM_MASK_REG_XSTOP_TO_PCB = 0;
static const uint32_t AXON_EPS_FIR_SUM_MASK_REG_RECOV_TO_PCB = 1;
static const uint32_t AXON_EPS_FIR_SUM_MASK_REG_SPATTN_TO_PCB = 2;
static const uint32_t AXON_EPS_FIR_SUM_MASK_REG_LOCAL_XSTOP_TO_PCB = 3;
static const uint32_t AXON_EPS_FIR_SUM_MASK_REG_HOSTATTN_TO_PCB = 4;
// iohs/reg00041.H

static const uint64_t AXON_EPS_PSC_PSCOM_ERROR_MASK = 0x18010002ull;

static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR = 3;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_UL_P0_ERROR = 5;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_GENERAL_TIMEOUT = 15;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t AXON_EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
// iohs/reg00041.H

static const uint64_t AXON_HOSTATTN_MASK = 0x1804001aull;

static const uint32_t AXON_HOSTATTN_MASK_01 = 1;
static const uint32_t AXON_HOSTATTN_MASK_02 = 2;
static const uint32_t AXON_HOSTATTN_MASK_03 = 3;
static const uint32_t AXON_HOSTATTN_MASK_04 = 4;
static const uint32_t AXON_HOSTATTN_MASK_05 = 5;
static const uint32_t AXON_HOSTATTN_MASK_06 = 6;
static const uint32_t AXON_HOSTATTN_MASK_07 = 7;
static const uint32_t AXON_HOSTATTN_MASK_08 = 8;
static const uint32_t AXON_HOSTATTN_MASK_09 = 9;
static const uint32_t AXON_HOSTATTN_MASK_10 = 10;
static const uint32_t AXON_HOSTATTN_MASK_11 = 11;
static const uint32_t AXON_HOSTATTN_MASK_12 = 12;
static const uint32_t AXON_HOSTATTN_MASK_13 = 13;
static const uint32_t AXON_HOSTATTN_MASK_14 = 14;
static const uint32_t AXON_HOSTATTN_MASK_15 = 15;
static const uint32_t AXON_HOSTATTN_MASK_16 = 16;
static const uint32_t AXON_HOSTATTN_MASK_17 = 17;
static const uint32_t AXON_HOSTATTN_MASK_18 = 18;
static const uint32_t AXON_HOSTATTN_MASK_19 = 19;
static const uint32_t AXON_HOSTATTN_MASK_20 = 20;
static const uint32_t AXON_HOSTATTN_MASK_21 = 21;
static const uint32_t AXON_HOSTATTN_MASK_22 = 22;
static const uint32_t AXON_HOSTATTN_MASK_23 = 23;
static const uint32_t AXON_HOSTATTN_MASK_24 = 24;
static const uint32_t AXON_HOSTATTN_MASK_25 = 25;
static const uint32_t AXON_HOSTATTN_MASK_26 = 26;
static const uint32_t AXON_HOSTATTN_MASK_27 = 27;
static const uint32_t AXON_HOSTATTN_MASK_28 = 28;
static const uint32_t AXON_HOSTATTN_MASK_29 = 29;
static const uint32_t AXON_HOSTATTN_MASK_30 = 30;
static const uint32_t AXON_HOSTATTN_MASK_31 = 31;
static const uint32_t AXON_HOSTATTN_MASK_32 = 32;
static const uint32_t AXON_HOSTATTN_MASK_33 = 33;
static const uint32_t AXON_HOSTATTN_MASK_34 = 34;
static const uint32_t AXON_HOSTATTN_MASK_35 = 35;
static const uint32_t AXON_HOSTATTN_MASK_36 = 36;
static const uint32_t AXON_HOSTATTN_MASK_37 = 37;
static const uint32_t AXON_HOSTATTN_MASK_38 = 38;
static const uint32_t AXON_HOSTATTN_MASK_39 = 39;
static const uint32_t AXON_HOSTATTN_MASK_40 = 40;
static const uint32_t AXON_HOSTATTN_MASK_41 = 41;
static const uint32_t AXON_HOSTATTN_MASK_42 = 42;
static const uint32_t AXON_HOSTATTN_MASK_43 = 43;
static const uint32_t AXON_HOSTATTN_MASK_44 = 44;
static const uint32_t AXON_HOSTATTN_MASK_45 = 45;
static const uint32_t AXON_HOSTATTN_MASK_46 = 46;
static const uint32_t AXON_HOSTATTN_MASK_47 = 47;
static const uint32_t AXON_HOSTATTN_MASK_48 = 48;
static const uint32_t AXON_HOSTATTN_MASK_49 = 49;
static const uint32_t AXON_HOSTATTN_MASK_50 = 50;
static const uint32_t AXON_HOSTATTN_MASK_51 = 51;
static const uint32_t AXON_HOSTATTN_MASK_52 = 52;
static const uint32_t AXON_HOSTATTN_MASK_53 = 53;
// iohs/reg00041.H

static const uint64_t AXON_OPCG_CAPT2 = 0x18030011ull;

static const uint32_t AXON_OPCG_CAPT2_13_01EVEN = 4;
static const uint32_t AXON_OPCG_CAPT2_13_01EVEN_LEN = 5;
static const uint32_t AXON_OPCG_CAPT2_14_01ODD = 9;
static const uint32_t AXON_OPCG_CAPT2_14_01ODD_LEN = 5;
static const uint32_t AXON_OPCG_CAPT2_15_02EVEN = 14;
static const uint32_t AXON_OPCG_CAPT2_15_02EVEN_LEN = 5;
static const uint32_t AXON_OPCG_CAPT2_16_02ODD = 19;
static const uint32_t AXON_OPCG_CAPT2_16_02ODD_LEN = 5;
static const uint32_t AXON_OPCG_CAPT2_17_03EVEN = 24;
static const uint32_t AXON_OPCG_CAPT2_17_03EVEN_LEN = 5;
static const uint32_t AXON_OPCG_CAPT2_18_03ODD = 29;
static const uint32_t AXON_OPCG_CAPT2_18_03ODD_LEN = 5;
static const uint32_t AXON_OPCG_CAPT2_19_04EVEN = 34;
static const uint32_t AXON_OPCG_CAPT2_19_04EVEN_LEN = 5;
static const uint32_t AXON_OPCG_CAPT2_20_04ODD = 39;
static const uint32_t AXON_OPCG_CAPT2_20_04ODD_LEN = 5;
static const uint32_t AXON_OPCG_CAPT2_21_05EVEN = 44;
static const uint32_t AXON_OPCG_CAPT2_21_05EVEN_LEN = 5;
static const uint32_t AXON_OPCG_CAPT2_22_05ODD = 49;
static const uint32_t AXON_OPCG_CAPT2_22_05ODD_LEN = 5;
static const uint32_t AXON_OPCG_CAPT2_23_06EVEN = 54;
static const uint32_t AXON_OPCG_CAPT2_23_06EVEN_LEN = 5;
static const uint32_t AXON_OPCG_CAPT2_24_06ODD = 59;
static const uint32_t AXON_OPCG_CAPT2_24_06ODD_LEN = 5;
// iohs/reg00041.H

static const uint64_t AXON_PCB_OPCG_GO = 0x18030020ull;

static const uint32_t AXON_PCB_OPCG_GO_PCB_OPCGGO = 0;
// iohs/reg00041.H

static const uint64_t AXON_TRA0_TR0_CONFIG = 0x18010402ull;

static const uint32_t AXON_TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t AXON_TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t AXON_TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t AXON_TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t AXON_TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t AXON_TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t AXON_TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t AXON_TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t AXON_TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t AXON_TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t AXON_TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t AXON_TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t AXON_TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t AXON_TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// iohs/reg00041.H

static const uint64_t MULTICAST_GROUP_2 = 0x180f0002ull;

static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// iohs/reg00041.H

}
}
#include "iohs/reg00041.H"
#endif
