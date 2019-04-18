/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_6.H $       */
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

#ifndef __p10_scom_perv_6_H_
#define __p10_scom_perv_6_H_


namespace scomt
{
namespace perv
{


static const uint64_t CPLT_CONF1_RW = 0x00000009ull;
static const uint64_t CPLT_CONF1_WO_CLEAR = 0x00000029ull;
static const uint64_t CPLT_CONF1_WO_OR = 0x00000019ull;

static const uint32_t CPLT_CONF1_OD_IOVALID_DC = 0;
static const uint32_t CPLT_CONF1__ANES_AMUX_VSEL_ES_EQ_DC_0H = 0;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_DC_0H = 0;
static const uint32_t CPLT_CONF1_EN_EQ_DC_0H = 0;
static const uint32_t CPLT_CONF1_0_IOVALID_DC = 0;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_0H = 0;
static const uint32_t CPLT_CONF1_EV_IOVALID_DC = 1;
static const uint32_t CPLT_CONF1__ANES_AMUX_VSEL_ES_EQ_DC_1H = 1;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_DC_1H = 1;
static const uint32_t CPLT_CONF1_EN_EQ_DC_1H = 1;
static const uint32_t CPLT_CONF1_1_IOVALID_DC = 1;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_1H = 1;
static const uint32_t CPLT_CONF1__ANES_AMUX_VSEL_ES_EQALL_DC_2H = 2;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_DC_2H = 2;
static const uint32_t CPLT_CONF1_NORTH_DC_2H = 2;
static const uint32_t CPLT_CONF1_2_IOVALID_DC = 2;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_2H = 2;
static const uint32_t CPLT_CONF1__ANES_AMUX_VSEL_ES_EQALL_DC_3H = 3;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_OCB_MH_DC_3H = 3;
static const uint32_t CPLT_CONF1_NORTH_DC_3H = 3;
static const uint32_t CPLT_CONF1_3_IOVALID_DC = 3;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_3H = 3;
static const uint32_t CPLT_CONF1__ANES_AMUX_VSEL_ES_EQALL_DC_4H = 4;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_OCB_MH_DC_4H = 4;
static const uint32_t CPLT_CONF1_NORTH_DC_4H = 4;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_4H = 4;
static const uint32_t CPLT_CONF1__ANES_AMUX_VSEL_ES_VDN_DC_5H = 5;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_OCB_MH_DC_5H = 5;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_5H = 5;
static const uint32_t CPLT_CONF1__ANES_AMUX_VSEL_ES_VDN_DC_6H = 6;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_OCB_MH_DC_6H = 6;
static const uint32_t CPLT_CONF1__ANES_AMUX_VSEL_ES_VDN_DC_7H = 7;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_PWR_DC_7H = 7;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_PWR_DC_8H = 8;
static const uint32_t CPLT_CONF1_IOVALID_DC_8H = 8;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_PWR_DC_9H = 9;
static const uint32_t CPLT_CONF1_IOVALID_DC_9H = 9;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_QUAD_DC_10H = 10;
static const uint32_t CPLT_CONF1_IOVALID_DC_10H = 10;
static const uint32_t CPLT_CONF1__LP_RESET = 11;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_QUAD_DC_11H = 11;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_VMEAS_DC = 12;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_12H = 12;
static const uint32_t CPLT_CONF1__ANES_VMEAS_CALIBRATE_DC = 13;
static const uint32_t CPLT_CONF1__ANEQ_VMEAS_CALIBRATE_DC = 13;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_13H = 13;
static const uint32_t CPLT_CONF1__ANES_VMEAS_MEASURE_DC = 14;
static const uint32_t CPLT_CONF1__ANEQ_VMEAS_MEASURE_DC = 14;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_14H = 14;
static const uint32_t CPLT_CONF1_CPLT_ANES_VMEAS_RESET_CLK_STOPPED_DC = 15;
static const uint32_t CPLT_CONF1_CPLT_ANEQ_VMEAS_RESET_CLK_STOPPED_DC = 15;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_15H = 15;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_16H = 16;
static const uint32_t CPLT_CONF1_APP1_RATIO_DC_17H = 17;
static const uint32_t CPLT_CONF1_APP1_RATIO_DC_18H = 18;
static const uint32_t CPLT_CONF1_APP1_RATIO_DC_19H = 19;
static const uint32_t CPLT_CONF1_APP1_RATIO_DC_20H = 20;
static const uint32_t CPLT_CONF1_APP1_RATIO_DC_21H = 21;
static const uint32_t CPLT_CONF1_APP2_RATIO_DC_22H = 22;
static const uint32_t CPLT_CONF1_APP2_RATIO_DC_23H = 23;
static const uint32_t CPLT_CONF1_APP2_RATIO_DC_24H = 24;
static const uint32_t CPLT_CONF1_APP2_RATIO_DC_25H = 25;
static const uint32_t CPLT_CONF1_APP2_RATIO_DC_26H = 26;
static const uint32_t CPLT_CONF1_SWAP_DC_28H = 28;
static const uint32_t CPLT_CONF1_SWAP_DC_29H = 29;
static const uint32_t CPLT_CONF1_SWAP_DC_30H = 30;
// perv/reg00218.H

static const uint64_t CPLT_CTRL1_RW = 0x00000001ull;
static const uint64_t CPLT_CTRL1_WO_CLEAR = 0x00000021ull;
static const uint64_t CPLT_CTRL1_WO_OR = 0x00000011ull;

static const uint32_t CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC = 0;
static const uint32_t CPLT_CTRL1_VITL_FENCE_DC = 3;
static const uint32_t CPLT_CTRL1_REGION0_FENCE_DC = 4;
static const uint32_t CPLT_CTRL1_REGION1_FENCE_DC = 5;
static const uint32_t CPLT_CTRL1_REGION2_FENCE_DC = 6;
static const uint32_t CPLT_CTRL1_REGION3_FENCE_DC = 7;
static const uint32_t CPLT_CTRL1_REGION4_FENCE_DC = 8;
static const uint32_t CPLT_CTRL1_REGION5_FENCE_DC = 9;
static const uint32_t CPLT_CTRL1_REGION6_FENCE_DC = 10;
static const uint32_t CPLT_CTRL1_REGION7_FENCE_DC = 11;
static const uint32_t CPLT_CTRL1_REGION8_FENCE_DC = 12;
static const uint32_t CPLT_CTRL1_REGION9_FENCE_DC = 13;
static const uint32_t CPLT_CTRL1_REGION10_FENCE_DC = 14;
static const uint32_t CPLT_CTRL1_REGION11_FENCE_DC = 15;
static const uint32_t CPLT_CTRL1_REGION12_FENCE_DC = 16;
static const uint32_t CPLT_CTRL1_REGION13_FENCE_DC = 17;
static const uint32_t CPLT_CTRL1_REGION14_FENCE_DC = 18;
// perv/reg00218.H

static const uint64_t DPLL_CNTL_NEST_REGS_CTRL_RW = 0x00000152ull;
static const uint64_t DPLL_CNTL_NEST_REGS_CTRL_WO_CLEAR = 0x00000053ull;
static const uint64_t DPLL_CNTL_NEST_REGS_CTRL_WO_OR = 0x00000054ull;

static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_DPLL_LOCK_SEL = 0;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_ENABLE_JUMP_PROTECT = 1;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_BYPASS = 2;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_DCO_OVERRIDE = 3;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_DCO_INCR = 4;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_DCO_DECR = 5;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_SPARE = 6;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_SPARE_LEN = 2;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP = 8;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_UP_LEN = 8;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN = 16;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_FF_SLEWRATE_DN_LEN = 8;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_SPARE2 = 24;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_DYNAMIC_SLEW_MODE = 25;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_FAST_FMAX_DISABLE = 26;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_FAST_FMIN_DISABLE = 27;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L = 33;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_L_LEN = 3;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S = 37;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_N_S_LEN = 3;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S = 41;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_L_S_LEN = 3;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N = 45;
static const uint32_t DPLL_CNTL_NEST_REGS_CTRL_JUMP_VALUE_S_N_LEN = 3;
// perv/reg00218.H

static const uint64_t EPS_DBG_INST1_COND_REG_3 = 0x000107c3ull;
// perv/reg00218.H

static const uint64_t EPS_DBG_INST2_COND_REG_3 = 0x000107c6ull;
// perv/reg00218.H

static const uint64_t EPS_FIR_GXSTOP0_MASK_REG = 0x00040013ull;

static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP = 0;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV = 1;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN = 2;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP = 3;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 = 4;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP = 5;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_OOB1 = 6;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// perv/reg00218.H

static const uint64_t EPS_PSC_PSCOM_STATUS_ERROR_REG = 0x00010001ull;

static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_P0_ERROR = 3;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_P0_ERROR = 5;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_GENERAL_TIMEOUT = 15;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_WDATA_PARITY_ERROR = 18;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_ADDRESS_PARITY_ERROR = 19;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_WDATA_PARITY_ERROR = 20;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_P0_ERROR = 21;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_RDATA_PARITY_ERROR = 22;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_P0_ERROR = 23;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_INTERFACE_MACHINE = 24;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_P2S_MACHINE = 25;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 26;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 27;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 28;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_WRITE_NVLD = 29;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_READ_NVLD = 30;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_ADDR_INVALID = 31;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_COMMAND_PARITY_ERROR = 32;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_GENERAL_TIMEOUT = 33;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 34;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 35;
// perv/reg00218.H

static const uint64_t EPS_PSC_RING_FENCE_MASK_LATCH_REG = 0x00010008ull;

static const uint32_t EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK = 1;
static const uint32_t EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN = 31;
// perv/reg00218.H

static const uint64_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ = 0x0005001cull;

static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
// perv/reg00218.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR0_CONFIG_5 = 0x00018208ull;

static const uint32_t L3TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t L3TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t L3TRA0_TR0_CONFIG_5_D_LEN = 24;
// perv/reg00218.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA1_TR1_TRACE_HI_DATA_REG = 0x00018260ull;

static const uint32_t L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00218.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA1_TR1_CONFIG_3 = 0x00018266ull;

static const uint32_t L3TRA1_TR1_CONFIG_3_C = 0;
static const uint32_t L3TRA1_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA1_TR1_CONFIG_3_D = 24;
static const uint32_t L3TRA1_TR1_CONFIG_3_D_LEN = 24;
// perv/reg00218.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA2_TR0_TRACE_LO_DATA_REG = 0x00018281ull;

static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA2_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00218.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA2_TR1_CONFIG_4 = 0x000182a7ull;

static const uint32_t L3TRA2_TR1_CONFIG_4_A = 0;
static const uint32_t L3TRA2_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA2_TR1_CONFIG_4_B = 24;
static const uint32_t L3TRA2_TR1_CONFIG_4_B_LEN = 24;
// perv/reg00218.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA3_TR0_CONFIG_2 = 0x000182c5ull;

static const uint32_t L3TRA3_TR0_CONFIG_2_A = 0;
static const uint32_t L3TRA3_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA3_TR0_CONFIG_2_B = 24;
static const uint32_t L3TRA3_TR0_CONFIG_2_B_LEN = 24;
// perv/reg00218.H

static const uint64_t LOCAL_XSTOP_MASK = 0x00040019ull;

static const uint32_t LOCAL_XSTOP_MASK_01 = 1;
static const uint32_t LOCAL_XSTOP_MASK_02 = 2;
static const uint32_t LOCAL_XSTOP_MASK_03 = 3;
static const uint32_t LOCAL_XSTOP_MASK_04 = 4;
static const uint32_t LOCAL_XSTOP_MASK_05 = 5;
static const uint32_t LOCAL_XSTOP_MASK_06 = 6;
static const uint32_t LOCAL_XSTOP_MASK_07 = 7;
static const uint32_t LOCAL_XSTOP_MASK_08 = 8;
static const uint32_t LOCAL_XSTOP_MASK_09 = 9;
static const uint32_t LOCAL_XSTOP_MASK_10 = 10;
static const uint32_t LOCAL_XSTOP_MASK_11 = 11;
static const uint32_t LOCAL_XSTOP_MASK_12 = 12;
static const uint32_t LOCAL_XSTOP_MASK_13 = 13;
static const uint32_t LOCAL_XSTOP_MASK_14 = 14;
static const uint32_t LOCAL_XSTOP_MASK_15 = 15;
// perv/reg00218.H

static const uint64_t TRA0_TR0_CONFIG_5 = 0x00010408ull;

static const uint32_t TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TRA0_TR0_CONFIG_5_D_LEN = 24;
// perv/reg00218.H

static const uint64_t TRA0_TR1_CONFIG = 0x00010442ull;

static const uint32_t TRA0_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA0_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA0_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA0_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA0_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TRA0_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA0_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA0_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA0_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// perv/reg00218.H

static const uint64_t TRA1_TR0_CONFIG = 0x00010482ull;

static const uint32_t TRA1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TRA1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// perv/reg00218.H

static const uint64_t TRA1_TR1_CONFIG_3 = 0x000104c6ull;

static const uint32_t TRA1_TR1_CONFIG_3_C = 0;
static const uint32_t TRA1_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TRA1_TR1_CONFIG_3_D = 24;
static const uint32_t TRA1_TR1_CONFIG_3_D_LEN = 24;
// perv/reg00218.H

static const uint64_t TRA2_TR1_CONFIG_4 = 0x00010547ull;

static const uint32_t TRA2_TR1_CONFIG_4_A = 0;
static const uint32_t TRA2_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TRA2_TR1_CONFIG_4_B = 24;
static const uint32_t TRA2_TR1_CONFIG_4_B_LEN = 24;
// perv/reg00218.H

static const uint64_t TRA3_TR0_CONFIG_2 = 0x00010585ull;

static const uint32_t TRA3_TR0_CONFIG_2_A = 0;
static const uint32_t TRA3_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TRA3_TR0_CONFIG_2_B = 24;
static const uint32_t TRA3_TR0_CONFIG_2_B_LEN = 24;
// perv/reg00218.H

static const uint64_t TRA4_TR0_CONFIG_3 = 0x00010606ull;

static const uint32_t TRA4_TR0_CONFIG_3_C = 0;
static const uint32_t TRA4_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA4_TR0_CONFIG_3_D = 24;
static const uint32_t TRA4_TR0_CONFIG_3_D_LEN = 24;
// perv/reg00218.H

static const uint64_t TRA5_TR0_TRACE_HI_DATA_REG = 0x00010680ull;

static const uint32_t TRA5_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA5_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00218.H

static const uint64_t TRA5_TR1_CONFIG_5 = 0x000106c8ull;

static const uint32_t TRA5_TR1_CONFIG_5_C = 0;
static const uint32_t TRA5_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TRA5_TR1_CONFIG_5_D = 24;
static const uint32_t TRA5_TR1_CONFIG_5_D_LEN = 24;
// perv/reg00218.H

static const uint64_t TRA6_TR1_TRACE_LO_DATA_REG = 0x00010741ull;

static const uint32_t TRA6_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA6_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA6_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA6_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA6_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA6_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA6_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA6_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA6_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA6_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA6_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00218.H

static const uint64_t TRA6_TR1_CONFIG_2 = 0x00010745ull;

static const uint32_t TRA6_TR1_CONFIG_2_A = 0;
static const uint32_t TRA6_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TRA6_TR1_CONFIG_2_B = 24;
static const uint32_t TRA6_TR1_CONFIG_2_B_LEN = 24;
// perv/reg00218.H

static const uint64_t TRA7_TR0_CONFIG_4 = 0x00010787ull;

static const uint32_t TRA7_TR0_CONFIG_4_A = 0;
static const uint32_t TRA7_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TRA7_TR0_CONFIG_4_B = 24;
static const uint32_t TRA7_TR0_CONFIG_4_B_LEN = 24;
// perv/reg00218.H

}
}
#include "perv/reg00218.H"
#endif
