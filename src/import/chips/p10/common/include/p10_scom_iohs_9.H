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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

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
// iohs/reg00040.H

static const uint64_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4 = 0x18040084ull;

static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_XSTOP_ERR = 0;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_RECOV_ERR = 1;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_SPATTN_ERR = 2;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_LXSTOP_ERR = 3;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_HOSTATTN_ERR = 4;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_SYS_XSTOP_ERR = 5;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_OOB1_ERR = 6;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_DBG_TRIG_ERR = 7;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// iohs/reg00040.H

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
// iohs/reg00040.H

static const uint64_t AXON_HOSTATTN_MASK_RW = 0x18040044ull;
static const uint64_t AXON_HOSTATTN_MASK_WO_CLEAR = 0x18040064ull;
static const uint64_t AXON_HOSTATTN_MASK_WO_OR = 0x18040054ull;

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
// iohs/reg00040.H

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
// iohs/reg00040.H

static const uint64_t AXON_PCB_OPCG_GO = 0x18030020ull;

static const uint32_t AXON_PCB_OPCG_GO_PCB_OPCGGO = 0;
// iohs/reg00040.H

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
static const uint32_t AXON_TRA0_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t AXON_TRA0_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// iohs/reg00040.H

static const uint64_t AXON_XSTOP5 = 0x18030015ull;

static const uint32_t AXON_XSTOP5_XSTOP5_MASK_B = 0;
static const uint32_t AXON_XSTOP5_ALIGNED_XSTOP5 = 1;
static const uint32_t AXON_XSTOP5_TRIGGER_OPCG_ON_XSTOP5 = 2;
static const uint32_t AXON_XSTOP5_XSTOP5_WAIT_ALLWAYS = 3;
static const uint32_t AXON_XSTOP5_XSTOP5_PERV = 4;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT1 = 5;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT2 = 6;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT3 = 7;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT4 = 8;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT5 = 9;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT6 = 10;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT7 = 11;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT8 = 12;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT9 = 13;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT10 = 14;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT11 = 15;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT12 = 16;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT13 = 17;
static const uint32_t AXON_XSTOP5_XSTOP5_UNIT14 = 18;
static const uint32_t AXON_XSTOP5_XSTOP5_WAIT_CYCLES = 48;
static const uint32_t AXON_XSTOP5_XSTOP5_WAIT_CYCLES_LEN = 12;
// iohs/reg00040.H

static const uint64_t DLP_FIR_MASK_REG_RW = 0x18011003ull;
static const uint64_t DLP_FIR_MASK_REG_WO_AND = 0x18011004ull;
static const uint64_t DLP_FIR_MASK_REG_WO_OR = 0x18011005ull;

static const uint32_t DLP_FIR_MASK_REG_LINK0_TRAINED_MASK = 0;
static const uint32_t DLP_FIR_MASK_REG_LINK1_TRAINED_MASK = 1;
static const uint32_t DLP_FIR_MASK_REG_LINK0_OP_IRQ_MASK = 2;
static const uint32_t DLP_FIR_MASK_REG_LINK1_OP_IRQ_MASK = 3;
static const uint32_t DLP_FIR_MASK_REG_LINK0_REPLAY_THRESHOLD_MASK = 4;
static const uint32_t DLP_FIR_MASK_REG_LINK1_REPLAY_THRESHOLD_MASK = 5;
static const uint32_t DLP_FIR_MASK_REG_LINK0_CRC_ERROR_MASK = 6;
static const uint32_t DLP_FIR_MASK_REG_LINK1_CRC_ERROR_MASK = 7;
static const uint32_t DLP_FIR_MASK_REG_LINK0_NAK_RECEIVED_MASK = 8;
static const uint32_t DLP_FIR_MASK_REG_LINK1_NAK_RECEIVED_MASK = 9;
static const uint32_t DLP_FIR_MASK_REG_LINK0_REPLAY_BUFFER_FULL_MASK = 10;
static const uint32_t DLP_FIR_MASK_REG_LINK1_REPLAY_BUFFER_FULL_MASK = 11;
static const uint32_t DLP_FIR_MASK_REG_LINK0_SL_ECC_THRESHOLD_MASK = 12;
static const uint32_t DLP_FIR_MASK_REG_LINK1_SL_ECC_THRESHOLD_MASK = 13;
static const uint32_t DLP_FIR_MASK_REG_LINK0_SL_ECC_CORRECTABLE_MASK = 14;
static const uint32_t DLP_FIR_MASK_REG_LINK1_SL_ECC_CORRECTABLE_MASK = 15;
static const uint32_t DLP_FIR_MASK_REG_LINK0_SL_ECC_UE_MASK = 16;
static const uint32_t DLP_FIR_MASK_REG_LINK1_SL_ECC_UE_MASK = 17;
static const uint32_t DLP_FIR_MASK_REG_LINK0_RETRAIN_THRESHOLD_MASK = 18;
static const uint32_t DLP_FIR_MASK_REG_LINK1_RETRAIN_THRESHOLD_MASK = 19;
static const uint32_t DLP_FIR_MASK_REG_LINK0_LOSS_BLOCK_ALIGN_MASK = 20;
static const uint32_t DLP_FIR_MASK_REG_LINK1_LOSS_BLOCK_ALIGN_MASK = 21;
static const uint32_t DLP_FIR_MASK_REG_LINK0_INVALID_BLOCK_MASK = 22;
static const uint32_t DLP_FIR_MASK_REG_LINK1_INVALID_BLOCK_MASK = 23;
static const uint32_t DLP_FIR_MASK_REG_LINK0_DESKEW_ERROR_MASK = 24;
static const uint32_t DLP_FIR_MASK_REG_LINK1_DESKEW_ERROR_MASK = 25;
static const uint32_t DLP_FIR_MASK_REG_LINK0_DESKEW_OVERFLOW_MASK = 26;
static const uint32_t DLP_FIR_MASK_REG_LINK1_DESKEW_OVERFLOW_MASK = 27;
static const uint32_t DLP_FIR_MASK_REG_LINK0_SW_RETRAIN_MASK = 28;
static const uint32_t DLP_FIR_MASK_REG_LINK1_SW_RETRAIN_MASK = 29;
static const uint32_t DLP_FIR_MASK_REG_LINK0_ACK_QUEUE_OVERFLOW_MASK = 30;
static const uint32_t DLP_FIR_MASK_REG_LINK1_ACK_QUEUE_OVERFLOW_MASK = 31;
static const uint32_t DLP_FIR_MASK_REG_LINK0_ACK_QUEUE_UNDERFLOW_MASK = 32;
static const uint32_t DLP_FIR_MASK_REG_LINK1_ACK_QUEUE_UNDERFLOW_MASK = 33;
static const uint32_t DLP_FIR_MASK_REG_LINK0_NUM_REPLAY_MASK = 34;
static const uint32_t DLP_FIR_MASK_REG_LINK1_NUM_REPLAY_MASK = 35;
static const uint32_t DLP_FIR_MASK_REG_LINK0_TRAINING_SET_RECEIVED_MASK = 36;
static const uint32_t DLP_FIR_MASK_REG_LINK1_TRAINING_SET_RECEIVED_MASK = 37;
static const uint32_t DLP_FIR_MASK_REG_LINK0_PRBS_SELECT_ERROR_MASK = 38;
static const uint32_t DLP_FIR_MASK_REG_LINK1_PRBS_SELECT_ERROR_MASK = 39;
static const uint32_t DLP_FIR_MASK_REG_LINK0_TCOMPLETE_BAD_MASK = 40;
static const uint32_t DLP_FIR_MASK_REG_LINK1_TCOMPLETE_BAD_MASK = 41;
static const uint32_t DLP_FIR_MASK_REG_LINK0_NO_SPARE_MASK = 42;
static const uint32_t DLP_FIR_MASK_REG_LINK1_NO_SPARE_MASK = 43;
static const uint32_t DLP_FIR_MASK_REG_LINK0_SPARE_DONE_MASK = 44;
static const uint32_t DLP_FIR_MASK_REG_LINK1_SPARE_DONE_MASK = 45;
static const uint32_t DLP_FIR_MASK_REG_LINK0_TOO_MANY_CRC_ERRORS_MASK = 46;
static const uint32_t DLP_FIR_MASK_REG_LINK1_TOO_MANY_CRC_ERRORS_MASK = 47;
static const uint32_t DLP_FIR_MASK_REG_LINK0_NPU_DLX_ERROR_MASK = 48;
static const uint32_t DLP_FIR_MASK_REG_LINK1_NPU_DLX_ERROR_MASK = 49;
static const uint32_t DLP_FIR_MASK_REG_OSC_SWITCH_MASK = 51;
static const uint32_t DLP_FIR_MASK_REG_LINK0_CORRECTABLE_ARRAY_ERROR_MASK = 52;
static const uint32_t DLP_FIR_MASK_REG_LINK1_CORRECTABLE_ARRAY_ERROR_MASK = 53;
static const uint32_t DLP_FIR_MASK_REG_LINK0_UNCORRECTABLE_ARRAY_ERROR_MASK = 54;
static const uint32_t DLP_FIR_MASK_REG_LINK1_UNCORRECTABLE_ARRAY_ERROR_MASK = 55;
static const uint32_t DLP_FIR_MASK_REG_LINK0_TRAINING_FAILED_MASK = 56;
static const uint32_t DLP_FIR_MASK_REG_LINK1_TRAINING_FAILED_MASK = 57;
static const uint32_t DLP_FIR_MASK_REG_LINK0_UNRECOVERABLE_ERROR_MASK = 58;
static const uint32_t DLP_FIR_MASK_REG_LINK1_UNRECOVERABLE_ERROR_MASK = 59;
static const uint32_t DLP_FIR_MASK_REG_LINK0_INTERNAL_ERROR_MASK = 60;
static const uint32_t DLP_FIR_MASK_REG_LINK1_INTERNAL_ERROR_MASK = 61;
// iohs/reg00040.H

static const uint64_t DLP_LINK1_ERROR_STATUS = 0x18011017ull;

static const uint32_t DLP_LINK1_ERROR_STATUS_RESET_KEEPER = 0;
static const uint32_t DLP_LINK1_ERROR_STATUS_ERROR_STATUS_CE = 1;
static const uint32_t DLP_LINK1_ERROR_STATUS_ERROR_STATUS_CE_LEN = 7;
static const uint32_t DLP_LINK1_ERROR_STATUS_ERROR_STATUS_UE = 8;
static const uint32_t DLP_LINK1_ERROR_STATUS_ERROR_STATUS_UE_LEN = 4;
static const uint32_t DLP_LINK1_ERROR_STATUS_ERROR_STATUS_OSC = 12;
static const uint32_t DLP_LINK1_ERROR_STATUS_ERROR_STATUS_OSC_LEN = 2;
static const uint32_t DLP_LINK1_ERROR_STATUS_ERROR_STATUS_TRAIN = 16;
static const uint32_t DLP_LINK1_ERROR_STATUS_ERROR_STATUS_TRAIN_LEN = 5;
static const uint32_t DLP_LINK1_ERROR_STATUS_ERROR_STATUS_UNRECOV = 24;
static const uint32_t DLP_LINK1_ERROR_STATUS_ERROR_STATUS_UNRECOV_LEN = 14;
static const uint32_t DLP_LINK1_ERROR_STATUS_ERROR_STATUS_INTERNAL = 40;
static const uint32_t DLP_LINK1_ERROR_STATUS_ERROR_STATUS_INTERNAL_LEN = 24;
// iohs/reg00040.H

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
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_08_CONTROL = 32;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL_08_CONTROL_LEN = 4;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL__FAILED = 48;
static const uint32_t DLP_LINK1_TX_LANE_CONTROL__FAILED_LEN = 9;
// iohs/reg00040.H

static const uint64_t DLP_REPLAY_THRESHOLD = 0x18011018ull;

static const uint32_t DLP_REPLAY_THRESHOLD_TB_SEL = 0;
static const uint32_t DLP_REPLAY_THRESHOLD_TB_SEL_LEN = 4;
static const uint32_t DLP_REPLAY_THRESHOLD_TAP_SEL = 4;
static const uint32_t DLP_REPLAY_THRESHOLD_TAP_SEL_LEN = 4;
static const uint32_t DLP_REPLAY_THRESHOLD_ENABLE = 8;
static const uint32_t DLP_REPLAY_THRESHOLD_ENABLE_LEN = 3;
static const uint32_t DLP_REPLAY_THRESHOLD_LINK0_CLEAR = 26;
static const uint32_t DLP_REPLAY_THRESHOLD_LINK1_CLEAR = 27;
static const uint32_t DLP_REPLAY_THRESHOLD_DIS_TB_CLEAR = 28;
static const uint32_t DLP_REPLAY_THRESHOLD_DIS_TAP_CLEAR = 29;
static const uint32_t DLP_REPLAY_THRESHOLD_DIS_TAP_STOP = 30;
static const uint32_t DLP_REPLAY_THRESHOLD_LINK0_COUNT = 32;
static const uint32_t DLP_REPLAY_THRESHOLD_LINK0_COUNT_LEN = 16;
static const uint32_t DLP_REPLAY_THRESHOLD_LINK1_COUNT = 48;
static const uint32_t DLP_REPLAY_THRESHOLD_LINK1_COUNT_LEN = 16;
// iohs/reg00040.H

static const uint64_t DLP_RETRAIN_THRESHOLD = 0x1801101aull;

static const uint32_t DLP_RETRAIN_THRESHOLD_TB_SEL = 0;
static const uint32_t DLP_RETRAIN_THRESHOLD_TB_SEL_LEN = 4;
static const uint32_t DLP_RETRAIN_THRESHOLD_TAP_SEL = 4;
static const uint32_t DLP_RETRAIN_THRESHOLD_TAP_SEL_LEN = 4;
static const uint32_t DLP_RETRAIN_THRESHOLD_ENABLE = 8;
static const uint32_t DLP_RETRAIN_THRESHOLD_ENABLE_LEN = 9;
static const uint32_t DLP_RETRAIN_THRESHOLD_LINK0_CLEAR = 26;
static const uint32_t DLP_RETRAIN_THRESHOLD_LINK1_CLEAR = 27;
static const uint32_t DLP_RETRAIN_THRESHOLD_DIS_TB_CLEAR = 28;
static const uint32_t DLP_RETRAIN_THRESHOLD_DIS_TAP_CLEAR = 29;
static const uint32_t DLP_RETRAIN_THRESHOLD_DIS_TAP_STOP = 30;
static const uint32_t DLP_RETRAIN_THRESHOLD_LINK0_COUNT = 32;
static const uint32_t DLP_RETRAIN_THRESHOLD_LINK0_COUNT_LEN = 16;
static const uint32_t DLP_RETRAIN_THRESHOLD_LINK1_COUNT = 48;
static const uint32_t DLP_RETRAIN_THRESHOLD_LINK1_COUNT_LEN = 16;
// iohs/reg00040.H

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
// iohs/reg00040.H

static const uint64_t DLP_SL_ECC_THRESHOLD = 0x18011019ull;

static const uint32_t DLP_SL_ECC_THRESHOLD_TB_SEL = 0;
static const uint32_t DLP_SL_ECC_THRESHOLD_TB_SEL_LEN = 4;
static const uint32_t DLP_SL_ECC_THRESHOLD_TAP_SEL = 4;
static const uint32_t DLP_SL_ECC_THRESHOLD_TAP_SEL_LEN = 4;
static const uint32_t DLP_SL_ECC_THRESHOLD_ENABLE = 8;
static const uint32_t DLP_SL_ECC_THRESHOLD_ENABLE_LEN = 2;
static const uint32_t DLP_SL_ECC_THRESHOLD_LINK0_CLEAR = 26;
static const uint32_t DLP_SL_ECC_THRESHOLD_LINK1_CLEAR = 27;
static const uint32_t DLP_SL_ECC_THRESHOLD_DIS_TB_CLEAR = 28;
static const uint32_t DLP_SL_ECC_THRESHOLD_DIS_TAP_CLEAR = 29;
static const uint32_t DLP_SL_ECC_THRESHOLD_DIS_TAP_STOP = 30;
static const uint32_t DLP_SL_ECC_THRESHOLD_LINK0_COUNT = 32;
static const uint32_t DLP_SL_ECC_THRESHOLD_LINK0_COUNT_LEN = 16;
static const uint32_t DLP_SL_ECC_THRESHOLD_LINK1_COUNT = 48;
static const uint32_t DLP_SL_ECC_THRESHOLD_LINK1_COUNT_LEN = 16;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE13_PG = 0x8008680010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE13_PG_1_FILTER_ENA = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE13_PG_1_FILTER_ENA_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE13_PG_1_FILTER_PAT = 52;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE13_PG_1_FILTER_PAT_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE13_PG_2_FILTER_ENA = 56;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE13_PG_2_FILTER_ENA_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE13_PG_2_FILTER_PAT = 60;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE13_PG_2_FILTER_PAT_LEN = 4;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE23_PG = 0x8008b80010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE23_PG_1_H_SEL = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE23_PG_1_H_SEL_LEN = 2;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE23_PG_2_H_SEL = 50;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE23_PG_2_H_SEL_LEN = 2;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT11_PG = 0x8009d80010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15_LEN = 16;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT21_PG = 0x800a280010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET = 48;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL2_PG = 0x8009900010012c3full;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT17_PG = 0x800b100010012c3full;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT27_PG = 0x800b600010012c3full;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT2_PG = 0x800a980010012c3full;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL = 0x8003d80d10012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL = 0x8003d00b10012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_15_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL2_PL = 0x8003c80910012c3full;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL2_PL = 0x8003c81510012c3full;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL = 0x8003d01710012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_23_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL = 0x8003c00310012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_3_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00040.H

static const uint64_t IOO_RX0_RXCTL_DATASM_3_PLREGS_RX_STAT1_PL = 0x8003e00310012c3full;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL2_PL = 0x8003680010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_MODE4_PL = 0x8003380010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_STAT2_PL = 0x8003980010012c3full;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8003180010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d00010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002100010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002600010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL14_PL = 0x8000700010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE8_PL = 0x8003580110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_FIR_PL = 0x8003080110012c3full;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a80110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f80110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001480110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001980110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b00110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b80210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f80210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002480210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c00210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL13_PL = 0x8000680210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN = 4;
// iohs/reg00040.H

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE3_PL = 0x8003300310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT5_PL = 0x8003b00310012c3full;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_SPARE_MODE_PL = 0x8003000310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001100310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001600310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b00310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002200310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002700310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002980310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL15_PL = 0x8000780310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL5_PL = 0x8000280310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN = 4;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA = 52;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN = 4;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN = 4;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE = 60;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN = 4;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE1_PL = 0x8003200410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 57;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 58;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT = 59;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x8002180410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x8002680410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL6_PL = 0x8000300410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL6_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL6_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN = 4;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a00510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f00510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x8001400510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x8001900510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b80510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL3_PL = 0x8000180510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL3_PL_ZERO = 51;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL3_PL_ZERO_LEN = 3;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_0_RX_BIT_REGS_CNTLX5_PL = 0x8003800610012c3full;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x8001200610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x8001700610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c00610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x8002880610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_MODE3_PL = 0x8003300710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_STAT5_PL = 0x8003b00710012c3full;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e80710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002380710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL14_PL = 0x8000700710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL2_PL = 0x8003680810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE4_PL = 0x8003380810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_STAT2_PL = 0x8003980810012c3full;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001080810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001580810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a80810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a00810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL15_PL = 0x8000780810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE8_PL = 0x8003581110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e01110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001301110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001801110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d01110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c01110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002001110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002501110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL13_PL = 0x8000681110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL13_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL13_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL13_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN = 4;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL5_PL = 0x8000281110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN = 4;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA = 52;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN = 4;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN = 4;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE = 60;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN = 4;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX1_PL = 0x8003601010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// iohs/reg00041.H

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_FIR_MASK_PL = 0x8003101010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// iohs/reg00042.H

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_FIR_PL = 0x8003081010012c3full;
// iohs/reg00042.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d81010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x8001281010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x8001781010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c81010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x8002801010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d01010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL6_PL = 0x8000301010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL6_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL6_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN = 4;
// iohs/reg00042.H

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE6_PL = 0x8003480f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00042.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e00f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x8002300f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL3_PL = 0x8000180f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL3_PL_ZERO = 51;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL3_PL_ZERO_LEN = 3;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE1_PL = 0x8003200e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 57;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 58;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT = 59;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a80e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f80e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001480e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001980e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b00e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL18_PL = 0x8000900e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL1_PL = 0x8000080e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d00d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002100d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002600d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL4_PL = 0x8000200d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL4_PL_ZERO = 51;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL4_PL_ZERO_LEN = 3;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001100c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001600c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b00c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002200c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002700c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002980c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_CNTLX9_PL = 0x8000480c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE6_PL = 0x8003480b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b80b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f80b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002480b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c00b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL2_PL = 0x8003680a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE4_PL = 0x8003380a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_STAT2_PL = 0x8003980a10012c3full;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a00a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f00a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x8001400a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x8001900a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b80a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL16_PL = 0x8000800a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE8_PL = 0x8003580910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_SPARE_MODE_PL = 0x8003000910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x8002180910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x8002680910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00042.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL10_PL = 0x8000500910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS = 49;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M = 50;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL10_PL_SIGDET_PD = 51;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP = 52;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS = 53;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP = 54;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP_LEN = 2;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS = 57;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP = 58;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP_LEN = 2;
// iohs/reg00043.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL8_PL = 0x8000400910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT_LEN = 2;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL = 50;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL_LEN = 2;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B = 52;
// iohs/reg00043.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000000910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// iohs/reg00043.H

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG = 0x800d140010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4_LEN = 6;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5 = 54;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5_LEN = 6;
// iohs/reg00043.H

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG = 0x800c940010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS = 62;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET = 63;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL11_PL = 0x8004840010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL1G_PL = 0x8004340010012c3full;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL21_PL = 0x8004d40010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL5_PL = 0x8004540010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_MODE3_PL = 0x80042c0010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE3_PL_FFE_BOOST_TST_EN = 52;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE3_PL_FFE_BOOST_EN = 53;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL8_PL = 0x80046c0110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_FIR_MASK_PL = 0x80040c0110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL17_PL = 0x8004b40310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL27_PL = 0x8005040310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_FIR_PL = 0x8004040310012c3full;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_STAT1_PL = 0x8005240310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL10_PL = 0x80047c0510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL20_PL = 0x8004cc0510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL2_PL = 0x80043c0510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00043.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL30_PL = 0x80051c0510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00043.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL10_PL = 0x80047c0610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00043.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL20_PL = 0x8004cc0610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00043.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL30_PL = 0x80051c0610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00043.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL6_PL = 0x80045c0710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00043.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL2_PL = 0x80043c0810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00043.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_MASK_PL = 0x80040c0810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00043.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL16_PL = 0x8004ac1110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// iohs/reg00043.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL26_PL = 0x8004fc1110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00043.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8004141010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00043.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_STAT1_PL = 0x8005241010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00043.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL11_PL = 0x8004840f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00043.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL1G_PL = 0x8004340f10012c3full;
// iohs/reg00043.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL21_PL = 0x8004d40f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL18_PL = 0x8004bc0e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL28_PL = 0x80050c0e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL12_PL = 0x80048c0d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL22_PL = 0x8004dc0d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL7_PL = 0x8004640d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8004140d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL = 0x80041c0d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN = 52;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN = 53;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL14_PL = 0x80049c0c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL24_PL = 0x8004ec0c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL3_PL = 0x8004440c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL13_PL = 0x8004940a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL23_PL = 0x8004e40a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL19_PL = 0x8004c40910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00043.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL29_PL = 0x8005140910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00043.H

static const uint64_t MULTICAST_GROUP_2 = 0x180f0002ull;

static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// iohs/reg00043.H

}
}
#ifndef __PPE_HCODE__
    #include "iohs/reg00040.H"
    #include "iohs/reg00041.H"
    #include "iohs/reg00042.H"
    #include "iohs/reg00043.H"
#endif
#endif
