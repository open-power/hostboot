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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_perv_6_H_
#define __p10_scom_perv_6_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


static const uint64_t COMP_INTR_HOST_MASK_REG = 0x000f0033ull;

static const uint32_t COMP_INTR_HOST_MASK_REG_IPOLL_MASK_0 = 0;
static const uint32_t COMP_INTR_HOST_MASK_REG_IPOLL_MASK_1 = 1;
static const uint32_t COMP_INTR_HOST_MASK_REG_IPOLL_MASK_2 = 2;
static const uint32_t COMP_INTR_HOST_MASK_REG_IPOLL_MASK_3 = 3;
static const uint32_t COMP_INTR_HOST_MASK_REG_IPOLL_MASK_4 = 4;
static const uint32_t COMP_INTR_HOST_MASK_REG_IPOLL_MASK_5 = 5;
static const uint32_t COMP_INTR_HOST_MASK_REG_ERROR_MASK_0 = 6;
static const uint32_t COMP_INTR_HOST_MASK_REG_ERROR_MASK_1 = 7;
static const uint32_t COMP_INTR_HOST_MASK_REG_ERROR_MASK_2 = 8;
static const uint32_t COMP_INTR_HOST_MASK_REG_ERROR_MASK_3 = 9;
static const uint32_t COMP_INTR_HOST_MASK_REG_ERROR_MASK_4 = 10;
static const uint32_t COMP_INTR_HOST_MASK_REG_ERROR_MASK_5 = 11;
// perv/reg00009.H

static const uint64_t COMP_INTR_INTERRUPT_CONF_REG_RW = 0x000f002full;
static const uint64_t COMP_INTR_INTERRUPT_CONF_REG_RW_WAND = 0x000f0031ull;
static const uint64_t COMP_INTR_INTERRUPT_CONF_REG_RW_WOR = 0x000f0030ull;

static const uint32_t COMP_INTR_INTERRUPT_CONF_REG_SEL0 = 1;
static const uint32_t COMP_INTR_INTERRUPT_CONF_REG_SEL0_LEN = 3;
static const uint32_t COMP_INTR_INTERRUPT_CONF_REG_SEL1 = 5;
static const uint32_t COMP_INTR_INTERRUPT_CONF_REG_SEL1_LEN = 3;
static const uint32_t COMP_INTR_INTERRUPT_CONF_REG_GP = 8;
static const uint32_t COMP_INTR_INTERRUPT_CONF_REG_CC = 9;
// perv/reg00009.H

static const uint64_t CPLT_CONF1_RW = 0x00000009ull;
static const uint64_t CPLT_CONF1_WO_CLEAR = 0x00000029ull;
static const uint64_t CPLT_CONF1_WO_OR = 0x00000019ull;

static const uint32_t CPLT_CONF1_OD_IOVALID_DC = 0;
static const uint32_t CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_0H = 0;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_DC_0H = 0;
static const uint32_t CPLT_CONF1_EN_EQ_DC_0H = 0;
static const uint32_t CPLT_CONF1_0_IOVALID_DC = 0;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_0H = 0;
static const uint32_t CPLT_CONF1_EV_IOVALID_DC = 1;
static const uint32_t CPLT_CONF1_ANES_AMUX_VSEL_ES_EQ_DC_1H = 1;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_DC_1H = 1;
static const uint32_t CPLT_CONF1_EN_EQ_DC_1H = 1;
static const uint32_t CPLT_CONF1_1_IOVALID_DC = 1;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_1H = 1;
static const uint32_t CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_2H = 2;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_DC_2H = 2;
static const uint32_t CPLT_CONF1_NORTH_DC_2H = 2;
static const uint32_t CPLT_CONF1_2_IOVALID_DC = 2;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_2H = 2;
static const uint32_t CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_3H = 3;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_OCB_MH_DC_3H = 3;
static const uint32_t CPLT_CONF1_NORTH_DC_3H = 3;
static const uint32_t CPLT_CONF1_3_IOVALID_DC = 3;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_3H = 3;
static const uint32_t CPLT_CONF1_ANES_AMUX_VSEL_ES_EQALL_DC_4H = 4;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_OCB_MH_DC_4H = 4;
static const uint32_t CPLT_CONF1_NORTH_DC_4H = 4;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_4H = 4;
static const uint32_t CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_5H = 5;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_OCB_MH_DC_5H = 5;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_5H = 5;
static const uint32_t CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_6H = 6;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_OCB_MH_DC_6H = 6;
static const uint32_t CPLT_CONF1_ANES_AMUX_VSEL_ES_VDN_DC_7H = 7;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_PWR_DC_7H = 7;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_PWR_DC_8H = 8;
static const uint32_t CPLT_CONF1_IOVALID_DC_8H = 8;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_PWR_DC_9H = 9;
static const uint32_t CPLT_CONF1_IOVALID_DC_9H = 9;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_QUAD_DC_10H = 10;
static const uint32_t CPLT_CONF1_IOVALID_DC_10H = 10;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_QUAD_DC_11H = 11;
static const uint32_t CPLT_CONF1_LP_RESET = 12;
static const uint32_t CPLT_CONF1__AMUX_EQ_VSEL_VMEAS_DC = 12;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_12H = 12;
static const uint32_t CPLT_CONF1__ANEQ_VMEAS_CALIBRATE_DC = 13;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_13H = 13;
static const uint32_t CPLT_CONF1__ANEQ_VMEAS_MEASURE_DC = 14;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_14H = 14;
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
// perv/reg00009.H

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
// perv/reg00009.H

static const uint64_t EPS_DBG_INST1_COND_REG_3 = 0x000107c3ull;
// perv/reg00009.H

static const uint64_t EPS_DBG_INST2_COND_REG_3 = 0x000107c6ull;
// perv/reg00009.H

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
// perv/reg00009.H

static const uint64_t EPS_PSC_RING_FENCE_MASK_LATCH_REG = 0x00010008ull;

static const uint32_t EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK = 1;
static const uint32_t EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN = 31;
// perv/reg00009.H

static const uint64_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ = 0x0005001cull;

static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
// perv/reg00009.H

static const uint64_t FIRST_REPLY_REG = 0x000f0018ull;

static const uint32_t FIRST_REPLY_REG_FIRST_REPLY_REGISTER = 0;
static const uint32_t FIRST_REPLY_REG_FIRST_REPLY_REGISTER_LEN = 6;
// perv/reg00009.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_6_FSI = 0x00002886ull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_6_FSI_BYTE = 0x00002a18ull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_6_RW = 0x00050086ull;
// perv/reg00009.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_0_FSI = 0x000028c0ull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_0_FSI_BYTE = 0x00002b00ull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_0_RW = 0x000500c0ull;
// perv/reg00009.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_13_FSI = 0x0000290dull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_13_FSI_BYTE = 0x00002c34ull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_13_RW = 0x0005010dull;
// perv/reg00009.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_0_A_FSI = 0x00002821ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_0_A_FSI_BYTE = 0x00002884ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_0_A_RW = 0x00050021ull;

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A = 0;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_0_A_M1HC0A_MAILBOX_1_HEADER_COMMAND_0_A_LEN = 32;
// perv/reg00009.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_0_B_FSI = 0x0000282dull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_0_B_FSI_BYTE = 0x000028b4ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_0_B_RO = 0x0005002dull;

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B = 0;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_0_B_M2HC0B_MAILBOX_2_HEADER_COMMAND_0_B_LEN = 32;
// perv/reg00009.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_RCS_EL1_FSI = 0x00002941ull;
static const uint32_t FSXCOMP_FSXLOG_RCS_EL1_FSI_BYTE = 0x00002d04ull;
static const uint32_t FSXCOMP_FSXLOG_RCS_EL1_RO = 0x00050141ull;

static const uint32_t FSXCOMP_FSXLOG_RCS_EL1_RCS_EVENTLOG_1 = 0;
static const uint32_t FSXCOMP_FSXLOG_RCS_EL1_RCS_EVENTLOG_1_LEN = 32;
// perv/reg00009.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI = 0x00002912ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_FSI_BYTE = 0x00002c48ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_COPY_RW = 0x00050112ull;
// perv/reg00009.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_12_FSI = 0x00002983ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_12_FSI_BYTE = 0x00002e0cull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_12_RW = 0x00050183ull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_12_SR_SCRATCH_REGISTER_12 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_12_SR_SCRATCH_REGISTER_12_LEN = 32;
// perv/reg00009.H

static const uint64_t L3TRA0_TR0_CONFIG_5 = 0x00018208ull;

static const uint32_t L3TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t L3TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t L3TRA0_TR0_CONFIG_5_D_LEN = 24;
// perv/reg00009.H

static const uint64_t L3TRA1_TR1_TRACE_HI_DATA_REG = 0x00018260ull;

static const uint32_t L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA1_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00009.H

static const uint64_t L3TRA1_TR1_CONFIG_3 = 0x00018266ull;

static const uint32_t L3TRA1_TR1_CONFIG_3_C = 0;
static const uint32_t L3TRA1_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA1_TR1_CONFIG_3_D = 24;
static const uint32_t L3TRA1_TR1_CONFIG_3_D_LEN = 24;
// perv/reg00009.H

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
// perv/reg00009.H

static const uint64_t L3TRA2_TR1_CONFIG_4 = 0x000182a7ull;

static const uint32_t L3TRA2_TR1_CONFIG_4_A = 0;
static const uint32_t L3TRA2_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA2_TR1_CONFIG_4_B = 24;
static const uint32_t L3TRA2_TR1_CONFIG_4_B_LEN = 24;
// perv/reg00009.H

static const uint64_t L3TRA3_TR0_CONFIG_2 = 0x000182c5ull;

static const uint32_t L3TRA3_TR0_CONFIG_2_A = 0;
static const uint32_t L3TRA3_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA3_TR0_CONFIG_2_B = 24;
static const uint32_t L3TRA3_TR0_CONFIG_2_B_LEN = 24;
// perv/reg00009.H

static const uint64_t LOCAL_XSTOP_MASK_RW = 0x00040043ull;
static const uint64_t LOCAL_XSTOP_MASK_WO_CLEAR = 0x00040063ull;
static const uint64_t LOCAL_XSTOP_MASK_WO_OR = 0x00040053ull;

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
// perv/reg00009.H

static const uint64_t LOCAL_XSTOP_UNMASKED = 0x00040013ull;

static const uint32_t LOCAL_XSTOP_UNMASKED_LOCAL_XSTOP_UNMASKED_IN = 1;
static const uint32_t LOCAL_XSTOP_UNMASKED_LOCAL_XSTOP_UNMASKED_IN_LEN = 15;
// perv/reg00009.H

static const uint64_t REC_ERR_MST14_REG2 = 0x000f007aull;

static const uint32_t REC_ERR_MST14_REG2_32_MST14_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST14_REG2_32_MST14_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST14_REG2_32_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_33_MST14_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST14_REG2_33_MST14_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST14_REG2_33_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_34_MST14_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST14_REG2_34_MST14_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST14_REG2_34_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_35_MST14_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST14_REG2_35_MST14_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST14_REG2_35_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_36_MST14_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST14_REG2_36_MST14_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST14_REG2_36_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_37_MST14_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST14_REG2_37_MST14_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST14_REG2_37_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_38_MST14_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST14_REG2_38_MST14_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST14_REG2_38_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_39_MST14_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST14_REG2_39_MST14_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST14_REG2_39_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_40_MST14_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST14_REG2_40_MST14_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST14_REG2_40_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_41_MST14_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST14_REG2_41_MST14_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST14_REG2_41_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_42_MST14_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST14_REG2_42_MST14_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST14_REG2_42_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_43_MST14_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST14_REG2_43_MST14_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST14_REG2_43_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_44_MST14_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST14_REG2_44_MST14_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST14_REG2_44_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_45_MST14_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST14_REG2_45_MST14_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST14_REG2_45_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_46_MST14_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST14_REG2_46_MST14_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST14_REG2_46_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG2_47_MST14_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST14_REG2_47_MST14_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST14_REG2_47_MST14_ERROR_CODE_LEN = 3;
// perv/reg00009.H

static const uint64_t REC_ERR_MST2_REG2 = 0x000f004aull;

static const uint32_t REC_ERR_MST2_REG2_32_MST2_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST2_REG2_32_MST2_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST2_REG2_32_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_33_MST2_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST2_REG2_33_MST2_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST2_REG2_33_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_34_MST2_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST2_REG2_34_MST2_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST2_REG2_34_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_35_MST2_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST2_REG2_35_MST2_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST2_REG2_35_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_36_MST2_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST2_REG2_36_MST2_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST2_REG2_36_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_37_MST2_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST2_REG2_37_MST2_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST2_REG2_37_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_38_MST2_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST2_REG2_38_MST2_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST2_REG2_38_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_39_MST2_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST2_REG2_39_MST2_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST2_REG2_39_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_40_MST2_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST2_REG2_40_MST2_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST2_REG2_40_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_41_MST2_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST2_REG2_41_MST2_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST2_REG2_41_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_42_MST2_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST2_REG2_42_MST2_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST2_REG2_42_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_43_MST2_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST2_REG2_43_MST2_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST2_REG2_43_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_44_MST2_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST2_REG2_44_MST2_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST2_REG2_44_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_45_MST2_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST2_REG2_45_MST2_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST2_REG2_45_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_46_MST2_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST2_REG2_46_MST2_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST2_REG2_46_MST2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST2_REG2_47_MST2_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST2_REG2_47_MST2_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST2_REG2_47_MST2_ERROR_CODE_LEN = 3;
// perv/reg00009.H

static const uint64_t REC_ERR_MST6_REG3 = 0x000f005bull;

static const uint32_t REC_ERR_MST6_REG3_48_MST6_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST6_REG3_48_MST6_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST6_REG3_48_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_49_MST6_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST6_REG3_49_MST6_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST6_REG3_49_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_50_MST6_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST6_REG3_50_MST6_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST6_REG3_50_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_51_MST6_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST6_REG3_51_MST6_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST6_REG3_51_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_52_MST6_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST6_REG3_52_MST6_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST6_REG3_52_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_53_MST6_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST6_REG3_53_MST6_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST6_REG3_53_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_54_MST6_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST6_REG3_54_MST6_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST6_REG3_54_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_55_MST6_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST6_REG3_55_MST6_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST6_REG3_55_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_56_MST6_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST6_REG3_56_MST6_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST6_REG3_56_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_57_MST6_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST6_REG3_57_MST6_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST6_REG3_57_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_58_MST6_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST6_REG3_58_MST6_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST6_REG3_58_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_59_MST6_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST6_REG3_59_MST6_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST6_REG3_59_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_60_MST6_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST6_REG3_60_MST6_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST6_REG3_60_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_61_MST6_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST6_REG3_61_MST6_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST6_REG3_61_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_62_MST6_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST6_REG3_62_MST6_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST6_REG3_62_MST6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST6_REG3_63_MST6_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST6_REG3_63_MST6_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST6_REG3_63_MST6_ERROR_CODE_LEN = 3;
// perv/reg00009.H

static const uint64_t REC_ERR_MST8_REG3 = 0x000f0063ull;

static const uint32_t REC_ERR_MST8_REG3_48_MST8_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST8_REG3_48_MST8_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST8_REG3_48_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_49_MST8_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST8_REG3_49_MST8_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST8_REG3_49_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_50_MST8_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST8_REG3_50_MST8_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST8_REG3_50_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_51_MST8_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST8_REG3_51_MST8_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST8_REG3_51_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_52_MST8_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST8_REG3_52_MST8_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST8_REG3_52_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_53_MST8_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST8_REG3_53_MST8_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST8_REG3_53_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_54_MST8_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST8_REG3_54_MST8_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST8_REG3_54_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_55_MST8_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST8_REG3_55_MST8_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST8_REG3_55_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_56_MST8_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST8_REG3_56_MST8_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST8_REG3_56_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_57_MST8_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST8_REG3_57_MST8_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST8_REG3_57_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_58_MST8_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST8_REG3_58_MST8_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST8_REG3_58_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_59_MST8_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST8_REG3_59_MST8_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST8_REG3_59_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_60_MST8_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST8_REG3_60_MST8_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST8_REG3_60_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_61_MST8_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST8_REG3_61_MST8_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST8_REG3_61_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_62_MST8_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST8_REG3_62_MST8_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST8_REG3_62_MST8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST8_REG3_63_MST8_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST8_REG3_63_MST8_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST8_REG3_63_MST8_ERROR_CODE_LEN = 3;
// perv/reg00009.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG111 = 0x0000806full;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG111_REGISTER111 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG111_REGISTER111_LEN = 64;
// perv/reg00009.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG126 = 0x0000807eull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG126_REGISTER126 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG126_REGISTER126_LEN = 64;
// perv/reg00009.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG28 = 0x0000801cull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG28_REGISTER28 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG28_REGISTER28_LEN = 64;
// perv/reg00009.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG37 = 0x00008025ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG37_REGISTER37 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG37_REGISTER37_LEN = 64;
// perv/reg00009.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG49 = 0x00008031ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG49_REGISTER49 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG49_REGISTER49_LEN = 64;
// perv/reg00009.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG56 = 0x00008038ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG56_REGISTER56 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG56_REGISTER56_LEN = 64;
// perv/reg00009.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG61 = 0x0000803dull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG61_REGISTER61 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG61_REGISTER61_LEN = 64;
// perv/reg00009.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG94 = 0x0000805eull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG94_REGISTER94 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG94_REGISTER94_LEN = 64;
// perv/reg00009.H

static const uint64_t TOD_M_PATH_0_STEP_STEER_REG = 0x0004000eull;

static const uint32_t TOD_M_PATH_0_STEP_STEER_REG_MODE = 0;
static const uint32_t TOD_M_PATH_0_STEP_STEER_REG_RATE = 1;
static const uint32_t TOD_M_PATH_0_STEP_STEER_REG_RATE_LEN = 31;
static const uint32_t TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_FLAG = 32;
static const uint32_t TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE = 33;
static const uint32_t TOD_M_PATH_0_STEP_STEER_REG_COUNTER_LOAD_VALUE_LEN = 31;
// perv/reg00009.H

static const uint64_t TOD_M_PATH_STATUS_REG = 0x00040009ull;

static const uint32_t TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD = 0;
static const uint32_t TOD_M_PATH_STATUS_REG_0_STEP_ALIGN_THRESHOLD_LEN = 8;
static const uint32_t TOD_M_PATH_STATUS_REG_0_CPS = 8;
static const uint32_t TOD_M_PATH_STATUS_REG_0_CPS_LEN = 8;
static const uint32_t TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD = 16;
static const uint32_t TOD_M_PATH_STATUS_REG_1_STEP_ALIGN_THRESHOLD_LEN = 8;
static const uint32_t TOD_M_PATH_STATUS_REG_1_CPS = 24;
static const uint32_t TOD_M_PATH_STATUS_REG_1_CPS_LEN = 8;
// perv/reg00009.H

static const uint64_t TOD_PROBE_SELECT_REG = 0x0004000cull;

static const uint32_t TOD_PROBE_SELECT_REG_0_DATA_SELECT = 0;
static const uint32_t TOD_PROBE_SELECT_REG_0_DATA_SELECT_LEN = 8;
static const uint32_t TOD_PROBE_SELECT_REG_1_DATA_SELECT = 8;
static const uint32_t TOD_PROBE_SELECT_REG_1_DATA_SELECT_LEN = 8;
static const uint32_t TOD_PROBE_SELECT_REG_2_DATA_SELECT = 16;
static const uint32_t TOD_PROBE_SELECT_REG_2_DATA_SELECT_LEN = 8;
static const uint32_t TOD_PROBE_SELECT_REG_3_DATA_SELECT = 24;
static const uint32_t TOD_PROBE_SELECT_REG_3_DATA_SELECT_LEN = 8;
// perv/reg00009.H

static const uint64_t TOD_PSS_MSS_CTRL_REG = 0x00040007ull;

static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_SELECT = 0;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_S_TOD_SELECT = 1;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_S_DRAWER_SELECT = 2;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_1_STEP_CHECK_ENABLE = 3;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_0_STEP_CHECK_ENABLE = 4;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_M_PATH_1_STEP_CHECK_ENABLE = 5;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_S_PATH_0_STEP_CHECK_ENABLE = 6;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PRI_I_PATH_STEP_CHECK_ENABLE = 7;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_SELECT = 8;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_S_TOD_SELECT = 9;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_S_DRAWER_SELECT = 10;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_1_STEP_CHECK_ENABLE = 11;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_0_STEP_CHECK_ENABLE = 12;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_M_PATH_1_STEP_CHECK_ENABLE = 13;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_S_PATH_0_STEP_CHECK_ENABLE = 14;
static const uint32_t TOD_PSS_MSS_CTRL_REG_SEC_I_PATH_STEP_CHECK_ENABLE = 15;
static const uint32_t TOD_PSS_MSS_CTRL_REG_PSS_SWITCH_SYNC_ERROR_DISABLE = 16;
static const uint32_t TOD_PSS_MSS_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_X_DISABLE = 17;
static const uint32_t TOD_PSS_MSS_CTRL_REG_STEP_CHECK_ENABLE_CHICKEN_SWITCH = 18;
static const uint32_t TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_19 = 19;
static const uint32_t TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_20 = 20;
static const uint32_t TOD_PSS_MSS_CTRL_REG_MISC_RESYNC_OSC_FROM_TOD = 21;
static const uint32_t TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31 = 22;
static const uint32_t TOD_PSS_MSS_CTRL_REG_REG_0X07_SPARE_22_31_LEN = 10;
// perv/reg00009.H

static const uint64_t TOD_RX_TTYPE_CTRL_REG = 0x00040029ull;

static const uint32_t TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA = 0;
static const uint32_t TOD_RX_TTYPE_CTRL_REG_RX_TTYPE_DATA_LEN = 64;
// perv/reg00009.H

static const uint64_t TRA0_TR0_CONFIG_5 = 0x00010408ull;

static const uint32_t TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TRA0_TR0_CONFIG_5_D_LEN = 24;
// perv/reg00009.H

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
static const uint32_t TRA0_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TRA0_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// perv/reg00009.H

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
static const uint32_t TRA1_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TRA1_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// perv/reg00009.H

static const uint64_t TRA1_TR1_CONFIG_3 = 0x000104c6ull;

static const uint32_t TRA1_TR1_CONFIG_3_C = 0;
static const uint32_t TRA1_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TRA1_TR1_CONFIG_3_D = 24;
static const uint32_t TRA1_TR1_CONFIG_3_D_LEN = 24;
// perv/reg00009.H

static const uint64_t TRA2_TR1_CONFIG_4 = 0x00010547ull;

static const uint32_t TRA2_TR1_CONFIG_4_A = 0;
static const uint32_t TRA2_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TRA2_TR1_CONFIG_4_B = 24;
static const uint32_t TRA2_TR1_CONFIG_4_B_LEN = 24;
// perv/reg00009.H

static const uint64_t TRA3_TR0_CONFIG_2 = 0x00010585ull;

static const uint32_t TRA3_TR0_CONFIG_2_A = 0;
static const uint32_t TRA3_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TRA3_TR0_CONFIG_2_B = 24;
static const uint32_t TRA3_TR0_CONFIG_2_B_LEN = 24;
// perv/reg00009.H

static const uint64_t TRA4_TR0_CONFIG_3 = 0x00010606ull;

static const uint32_t TRA4_TR0_CONFIG_3_C = 0;
static const uint32_t TRA4_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA4_TR0_CONFIG_3_D = 24;
static const uint32_t TRA4_TR0_CONFIG_3_D_LEN = 24;
// perv/reg00009.H

static const uint64_t TRA5_TR0_TRACE_HI_DATA_REG = 0x00010680ull;

static const uint32_t TRA5_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA5_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00010.H

static const uint64_t TRA5_TR1_CONFIG_5 = 0x000106c8ull;

static const uint32_t TRA5_TR1_CONFIG_5_C = 0;
static const uint32_t TRA5_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TRA5_TR1_CONFIG_5_D = 24;
static const uint32_t TRA5_TR1_CONFIG_5_D_LEN = 24;
// perv/reg00010.H

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
// perv/reg00010.H

static const uint64_t TRA6_TR1_CONFIG_2 = 0x00010745ull;

static const uint32_t TRA6_TR1_CONFIG_2_A = 0;
static const uint32_t TRA6_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TRA6_TR1_CONFIG_2_B = 24;
static const uint32_t TRA6_TR1_CONFIG_2_B_LEN = 24;
// perv/reg00010.H

static const uint64_t TRA7_TR0_CONFIG_4 = 0x00010787ull;

static const uint32_t TRA7_TR0_CONFIG_4_A = 0;
static const uint32_t TRA7_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TRA7_TR0_CONFIG_4_B = 24;
static const uint32_t TRA7_TR0_CONFIG_4_B_LEN = 24;
// perv/reg00010.H

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00009.H"
#include "perv/reg00010.H"
#endif
#endif
