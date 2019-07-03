/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_8.H $        */
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

#ifndef __p10_scom_pec_8_H_
#define __p10_scom_pec_8_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


static const uint64_t ASSIST_INTERRUPT_REG = 0x080f0011ull;
// pec/reg00008.H

static const uint64_t EDRAM_STATUS = 0x080f0029ull;

static const uint32_t EDRAM_STATUS_EDRAM_STAT = 0;
static const uint32_t EDRAM_STATUS_EDRAM_STAT_LEN = 4;
// pec/reg00008.H

static const uint64_t EPS_DBG_TRACE_REG_0 = 0x080107cdull;

static const uint32_t EPS_DBG_TRACE_REG_0_INST1_COND3_ENABLE = 0;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_COND3_ENABLE = 1;
static const uint32_t EPS_DBG_TRACE_REG_0_INST3_COND3_ENABLE = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST4_COND3_ENABLE = 3;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_SLOW_LFSR_MODE = 4;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_SLOW_LFSR_MODE = 5;
static const uint32_t EPS_DBG_TRACE_REG_0_INST3_SLOW_LFSR_MODE = 6;
static const uint32_t EPS_DBG_TRACE_REG_0_INST4_SLOW_LFSR_MODE = 7;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL = 8;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL = 10;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL = 12;
static const uint32_t EPS_DBG_TRACE_REG_0_INST1_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL = 14;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION1_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL = 16;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_CONDITION2_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL = 18;
static const uint32_t EPS_DBG_TRACE_REG_0_INST2_C2_TIMEOUT_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_STOP = 32;
static const uint32_t EPS_DBG_TRACE_REG_0_EXT_TRIG_ON_FREEZE = 33;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL = 34;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS0_TRIG_SEL_LEN = 5;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL = 39;
static const uint32_t EPS_DBG_TRACE_REG_0_CORE_RAS1_TRIG_SEL_LEN = 5;
static const uint32_t EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL = 44;
static const uint32_t EPS_DBG_TRACE_REG_0_PC_TP_TRIG_SEL_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_0_DBG_ARM_SEL = 46;
static const uint32_t EPS_DBG_TRACE_REG_0_DBG_ARM_SEL_LEN = 4;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL = 50;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG0_LEVEL_SEL_LEN = 4;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL = 54;
static const uint32_t EPS_DBG_TRACE_REG_0_TRIG1_LEVEL_SEL_LEN = 4;
// pec/reg00008.H

static const uint64_t EPS_FIR_LOCAL_ACTION0 = 0x08040106ull;

static const uint32_t EPS_FIR_LOCAL_ACTION0_00 = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION0_01 = 1;
static const uint32_t EPS_FIR_LOCAL_ACTION0_02 = 2;
static const uint32_t EPS_FIR_LOCAL_ACTION0_03 = 3;
static const uint32_t EPS_FIR_LOCAL_ACTION0_04 = 4;
static const uint32_t EPS_FIR_LOCAL_ACTION0_05 = 5;
static const uint32_t EPS_FIR_LOCAL_ACTION0_06 = 6;
static const uint32_t EPS_FIR_LOCAL_ACTION0_07 = 7;
static const uint32_t EPS_FIR_LOCAL_ACTION0_08 = 8;
static const uint32_t EPS_FIR_LOCAL_ACTION0_09 = 9;
static const uint32_t EPS_FIR_LOCAL_ACTION0_10 = 10;
static const uint32_t EPS_FIR_LOCAL_ACTION0_11 = 11;
static const uint32_t EPS_FIR_LOCAL_ACTION0_12 = 12;
static const uint32_t EPS_FIR_LOCAL_ACTION0_13 = 13;
static const uint32_t EPS_FIR_LOCAL_ACTION0_14 = 14;
static const uint32_t EPS_FIR_LOCAL_ACTION0_15 = 15;
static const uint32_t EPS_FIR_LOCAL_ACTION0_16 = 16;
static const uint32_t EPS_FIR_LOCAL_ACTION0_17 = 17;
static const uint32_t EPS_FIR_LOCAL_ACTION0_18 = 18;
static const uint32_t EPS_FIR_LOCAL_ACTION0_19 = 19;
static const uint32_t EPS_FIR_LOCAL_ACTION0_20 = 20;
static const uint32_t EPS_FIR_LOCAL_ACTION0_21 = 21;
static const uint32_t EPS_FIR_LOCAL_ACTION0_22 = 22;
static const uint32_t EPS_FIR_LOCAL_ACTION0_23 = 23;
static const uint32_t EPS_FIR_LOCAL_ACTION0_24 = 24;
static const uint32_t EPS_FIR_LOCAL_ACTION0_25 = 25;
static const uint32_t EPS_FIR_LOCAL_ACTION0_26 = 26;
static const uint32_t EPS_FIR_LOCAL_ACTION0_27 = 27;
static const uint32_t EPS_FIR_LOCAL_ACTION0_28 = 28;
static const uint32_t EPS_FIR_LOCAL_ACTION0_29 = 29;
static const uint32_t EPS_FIR_LOCAL_ACTION0_30 = 30;
static const uint32_t EPS_FIR_LOCAL_ACTION0_31 = 31;
static const uint32_t EPS_FIR_LOCAL_ACTION0_32 = 32;
static const uint32_t EPS_FIR_LOCAL_ACTION0_33 = 33;
static const uint32_t EPS_FIR_LOCAL_ACTION0_34 = 34;
static const uint32_t EPS_FIR_LOCAL_ACTION0_35 = 35;
static const uint32_t EPS_FIR_LOCAL_ACTION0_36 = 36;
static const uint32_t EPS_FIR_LOCAL_ACTION0_37 = 37;
static const uint32_t EPS_FIR_LOCAL_ACTION0_38 = 38;
static const uint32_t EPS_FIR_LOCAL_ACTION0_39 = 39;
static const uint32_t EPS_FIR_LOCAL_ACTION0_40 = 40;
static const uint32_t EPS_FIR_LOCAL_ACTION0_41 = 41;
static const uint32_t EPS_FIR_LOCAL_ACTION0_42 = 42;
static const uint32_t EPS_FIR_LOCAL_ACTION0_43 = 43;
static const uint32_t EPS_FIR_LOCAL_ACTION0_44 = 44;
static const uint32_t EPS_FIR_LOCAL_ACTION0_45 = 45;
static const uint32_t EPS_FIR_LOCAL_ACTION0_46 = 46;
static const uint32_t EPS_FIR_LOCAL_ACTION0_47 = 47;
static const uint32_t EPS_FIR_LOCAL_ACTION0_48 = 48;
static const uint32_t EPS_FIR_LOCAL_ACTION0_49 = 49;
static const uint32_t EPS_FIR_LOCAL_ACTION0_50 = 50;
static const uint32_t EPS_FIR_LOCAL_ACTION0_51 = 51;
static const uint32_t EPS_FIR_LOCAL_ACTION0_52 = 52;
static const uint32_t EPS_FIR_LOCAL_ACTION0_53 = 53;
static const uint32_t EPS_FIR_LOCAL_ACTION0_54 = 54;
static const uint32_t EPS_FIR_LOCAL_ACTION0_55 = 55;
static const uint32_t EPS_FIR_LOCAL_ACTION0_56 = 56;
static const uint32_t EPS_FIR_LOCAL_ACTION0_57 = 57;
static const uint32_t EPS_FIR_LOCAL_ACTION0_58 = 58;
static const uint32_t EPS_FIR_LOCAL_ACTION0_59 = 59;
static const uint32_t EPS_FIR_LOCAL_ACTION0_60 = 60;
static const uint32_t EPS_FIR_LOCAL_ACTION0_61 = 61;
static const uint32_t EPS_FIR_LOCAL_ACTION0_62 = 62;
static const uint32_t EPS_FIR_LOCAL_ACTION0_63 = 63;
// pec/reg00008.H

static const uint64_t EPS_PSC_PSCOM_ERROR_MASK = 0x08010002ull;

static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_DL_RETURN_P0_ERROR = 3;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_UL_P0_ERROR = 5;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_GENERAL_TIMEOUT = 15;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t EPS_PSC_PSCOM_ERROR_MASK_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
// pec/reg00008.H

static const uint64_t EPS_PSC_WRITE_PROTECT_RINGS_REG = 0x08010006ull;

static const uint32_t EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS = 0;
static const uint32_t EPS_PSC_WRITE_PROTECT_RINGS_REG_WRITE_PROTECT_RINGS_LEN = 32;
// pec/reg00008.H

static const uint64_t ERROR_REG = 0x080f001full;

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
// pec/reg00008.H

static const uint64_t OPCG_REG0 = 0x08030002ull;

static const uint32_t OPCG_REG0_RUNN_MODE = 0;
static const uint32_t OPCG_REG0_OPCG_GO = 1;
static const uint32_t OPCG_REG0_RUN_SCAN0 = 2;
static const uint32_t OPCG_REG0_SCAN0_MODE = 3;
static const uint32_t OPCG_REG0_OPCG_IN_SLAVE_MODE = 4;
static const uint32_t OPCG_REG0_OPCG_IN_MASTER_MODE = 5;
static const uint32_t OPCG_REG0_KEEP_MS_MODE = 6;
static const uint32_t OPCG_REG0_TRIGGER_OPCG_ON_UNIT0_SYNC_LVL = 7;
static const uint32_t OPCG_REG0_TRIGGER_OPCG_ON_UNIT1_SYNC_LVL = 8;
static const uint32_t OPCG_REG0_RUN_OPCG_ON_UPDATE_DR = 11;
static const uint32_t OPCG_REG0_RUN_OPCG_ON_CAPTURE_DR = 12;
static const uint32_t OPCG_REG0_STOP_RUNN_ON_XSTOP = 13;
static const uint32_t OPCG_REG0_OPCG_STARTS_BIST = 14;
static const uint32_t OPCG_REG0_LOOP_COUNT = 21;
static const uint32_t OPCG_REG0_LOOP_COUNT_LEN = 43;
// pec/reg00008.H

static const uint64_t PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3 = 0x0301180full;

static const uint32_t PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3 = 0;
static const uint32_t PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG3_PE_TOPOLOGY_ID_REG3_LEN = 40;
// pec/reg00008.H

static const uint64_t SCAN_CAPTUREDR_LONG = 0x0803d000ull;
// pec/reg00008.H

static const uint64_t SCAN_REGION_TYPE = 0x08030005ull;

static const uint32_t SCAN_REGION_TYPE_SYSTEM_FAST_INIT = 0;
static const uint32_t SCAN_REGION_TYPE_PARALLEL_SCAN = 1;
static const uint32_t SCAN_REGION_TYPE_PARALLEL_SCAN_AND_NOTOR = 2;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_VITL = 3;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_PERV = 4;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT1 = 5;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT2 = 6;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT3 = 7;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT4 = 8;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT5 = 9;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT6 = 10;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT7 = 11;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT8 = 12;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT9 = 13;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT10 = 14;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT11 = 15;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT12 = 16;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT13 = 17;
static const uint32_t SCAN_REGION_TYPE_SCAN_REGION_UNIT14 = 18;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_FUNC = 48;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_CFG = 49;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_CCFG_GPTR = 50;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_REGF = 51;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_LBIST = 52;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_ABIST = 53;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_REPR = 54;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_TIME = 55;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_BNDY = 56;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_FARR = 57;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_CMSK = 58;
static const uint32_t SCAN_REGION_TYPE_SCAN_TYPE_INEX = 59;
// pec/reg00008.H

static const uint64_t TRA0_TR0_CONFIG = 0x08010402ull;

static const uint32_t TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TRA0_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TRA0_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// pec/reg00008.H

static const uint64_t XSTOP3 = 0x0803000eull;

static const uint32_t XSTOP3_XSTOP3_MASK_B = 0;
static const uint32_t XSTOP3_ALIGNED_XSTOP3 = 1;
static const uint32_t XSTOP3_TRIGGER_OPCG_ON_XSTOP3 = 2;
static const uint32_t XSTOP3_XSTOP3_WAIT_ALLWAYS = 3;
static const uint32_t XSTOP3_XSTOP3_PERV = 4;
static const uint32_t XSTOP3_XSTOP3_UNIT1 = 5;
static const uint32_t XSTOP3_XSTOP3_UNIT2 = 6;
static const uint32_t XSTOP3_XSTOP3_UNIT3 = 7;
static const uint32_t XSTOP3_XSTOP3_UNIT4 = 8;
static const uint32_t XSTOP3_XSTOP3_UNIT5 = 9;
static const uint32_t XSTOP3_XSTOP3_UNIT6 = 10;
static const uint32_t XSTOP3_XSTOP3_UNIT7 = 11;
static const uint32_t XSTOP3_XSTOP3_UNIT8 = 12;
static const uint32_t XSTOP3_XSTOP3_UNIT9 = 13;
static const uint32_t XSTOP3_XSTOP3_UNIT10 = 14;
static const uint32_t XSTOP3_XSTOP3_UNIT11 = 15;
static const uint32_t XSTOP3_XSTOP3_UNIT12 = 16;
static const uint32_t XSTOP3_XSTOP3_UNIT13 = 17;
static const uint32_t XSTOP3_XSTOP3_UNIT14 = 18;
static const uint32_t XSTOP3_XSTOP3_WAIT_CYCLES = 48;
static const uint32_t XSTOP3_XSTOP3_WAIT_CYCLES_LEN = 12;
// pec/reg00008.H

#ifndef __PPE_HCODE__
}
}
#include "pec/reg00008.H"
#endif
#endif
