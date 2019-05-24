/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_3.H $       */
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

#ifndef __p10_scom_perv_3_H_
#define __p10_scom_perv_3_H_


namespace scomt
{
namespace perv
{


static const uint64_t CLOCK_STAT_NSL = 0x00030009ull;

static const uint32_t CLOCK_STAT_NSL_PERV_NSL = 4;
static const uint32_t CLOCK_STAT_NSL_UNIT1_NSL = 5;
static const uint32_t CLOCK_STAT_NSL_UNIT2_NSL = 6;
static const uint32_t CLOCK_STAT_NSL_UNIT3_NSL = 7;
static const uint32_t CLOCK_STAT_NSL_UNIT4_NSL = 8;
static const uint32_t CLOCK_STAT_NSL_UNIT5_NSL = 9;
static const uint32_t CLOCK_STAT_NSL_UNIT6_NSL = 10;
static const uint32_t CLOCK_STAT_NSL_UNIT7_NSL = 11;
static const uint32_t CLOCK_STAT_NSL_UNIT8_NSL = 12;
static const uint32_t CLOCK_STAT_NSL_UNIT9_NSL = 13;
static const uint32_t CLOCK_STAT_NSL_UNIT10_NSL = 14;
static const uint32_t CLOCK_STAT_NSL_UNIT11_NSL = 15;
static const uint32_t CLOCK_STAT_NSL_UNIT12_NSL = 16;
static const uint32_t CLOCK_STAT_NSL_UNIT13_NSL = 17;
static const uint32_t CLOCK_STAT_NSL_UNIT14_NSL = 18;
// perv/reg00004.H

static const uint64_t DEVICE_ID_REG = 0x000f000full;

static const uint32_t DEVICE_ID_REG_SOCKET_ID = 36;
static const uint32_t DEVICE_ID_REG_SOCKET_ID_LEN = 3;
static const uint32_t DEVICE_ID_REG_CHIPPOS_ID = 39;
// perv/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: perv

static const uint64_t DPLL_CNTL_PAU_REGS_CTRL_RW = 0x00060052ull;
static const uint64_t DPLL_CNTL_PAU_REGS_CTRL_WO_CLEAR = 0x00060053ull;
static const uint64_t DPLL_CNTL_PAU_REGS_CTRL_WO_OR = 0x00060054ull;

static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_DPLL_LOCK_SEL = 0;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_ENABLE_JUMP_PROTECT = 1;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_FF_BYPASS = 2;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_DCO_OVERRIDE = 3;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_DCO_INCR = 4;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_DCO_DECR = 5;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_SPARE = 6;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_SPARE_LEN = 2;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP = 8;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_UP_LEN = 8;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN = 16;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_FF_SLEWRATE_DN_LEN = 8;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_SPARE2 = 24;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_DYNAMIC_SLEW_MODE = 25;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_FAST_FMAX_DISABLE = 26;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_FAST_FMIN_DISABLE = 27;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L = 33;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_L_LEN = 3;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S = 37;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_N_S_LEN = 3;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S = 41;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_L_S_LEN = 3;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N = 45;
static const uint32_t DPLL_CNTL_PAU_REGS_CTRL_JUMP_VALUE_S_N_LEN = 3;
// perv/reg00004.H

static const uint64_t EPS_FIR_ANY_LOCAL_ERR_MASK = 0x00040080ull;

static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_XSTOP_TO_PCB = 0;
static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_RECOV_TO_PCB = 1;
static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_SPATTN_TO_PCB = 2;
static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_LOCAL_XSTOP_TO_PCB = 3;
static const uint32_t EPS_FIR_ANY_LOCAL_ERR_MASK_HOSTATTN_TO_PCB = 4;
// perv/reg00004.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT2 = 0x00050002ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT2_DTS_8_RESULT_LEN = 16;
// perv/reg00004.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA1 = 0x0005001aull;
// perv/reg00004.H

static const uint64_t EPS_THERM_WSUB_MODE_REG = 0x0005000full;

static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR = 0;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_FORCE_THRES_ACT = 1;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA = 2;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_TRIP_ENA_LEN = 3;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_SAMPLE_ENA = 5;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT = 6;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN = 4;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA = 10;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_MODE_ENA_LEN = 2;
static const uint32_t EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_MODE = 12;
static const uint32_t EPS_THERM_WSUB_MODE_REG_DTS_TRIGGER_SEL = 13;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_THRES_OVERFLOW_MASK = 14;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL = 16;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_READ_SEL_LEN = 4;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1 = 20;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L1_LEN = 3;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2 = 24;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L2_LEN = 3;
static const uint32_t EPS_THERM_WSUB_MODE_REG_THERM_DTS_ENABLE_L3 = 28;
// perv/reg00004.H

static const uint64_t EPS_THERM_WSUB2_DTS_RESULT0 = 0x00050020ull;

static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT0_2_RESULT_LEN = 16;
// perv/reg00004.H

static const uint64_t EPS_THERM_WSUB2_INJECT_REG = 0x00050031ull;

static const uint32_t EPS_THERM_WSUB2_INJECT_REG_TRIP = 0;
static const uint32_t EPS_THERM_WSUB2_INJECT_REG_TRIP_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_INJECT_REG_MODE = 2;
static const uint32_t EPS_THERM_WSUB2_INJECT_REG_MODE_LEN = 2;
// perv/reg00004.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A = 0x00050028ull;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_FSI = 0x0000282cull;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_FSI_BYTE = 0x000028b0ull;

static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_PERMISSION_TO_SEND_DOORBELL_2 = 0;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_ABORT_DOORBELL_2 = 1;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_LBUS_SLAVE_2B_PENDING = 2;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_PIB_SLAVE_2A_PENDING = 3;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_XDN_DOORBELL_2 = 5;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_XUP_DOORBELL_2 = 6;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_HEADER_COUNT_2A = 8;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_HEADER_COUNT_2A_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_DATA_COUNT_2A = 12;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_DATA_COUNT_2A_LEN = 8;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_HEADER_COUNT_2B = 20;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_HEADER_COUNT_2B_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_DATA_COUNT_2B = 24;
static const uint32_t FSXCOMP_FSXLOG_DOORBELL_STATUS_CONTROL_2A_DATA_COUNT_2B_LEN = 8;
// perv/reg00004.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_0_FSI = 0x00002880ull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_0_FSI_BYTE = 0x00002a00ull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_0_RW = 0x00050080ull;
// perv/reg00004.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_11_FSI = 0x0000288bull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_11_FSI_BYTE = 0x00002a2cull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_11_RW = 0x0005008bull;
// perv/reg00004.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_6_FSI = 0x000028c6ull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_6_FSI_BYTE = 0x00002b18ull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_6_RW = 0x000500c6ull;
// perv/reg00004.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_15_FSI = 0x0000290full;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_15_FSI_BYTE = 0x00002c3cull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_15_RW = 0x0005010full;
// perv/reg00004.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_FSI = 0x00002833ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_FSI_BYTE = 0x000028ccull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_RW_WOR = 0x00050033ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_WO_CLEAR = 0x00050034ull;

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 =
    29;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_XUP_MAILBOX_1 = 30;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_SLAVE_A_DOORBELL_INTERRUPT_MASK_PIB_SLAVE_A_PENDING_MAILBOX_1 = 31;
// perv/reg00004.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_FSI = 0x00002835ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_FSI_BYTE = 0x000028d4ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_RO = 0x00050035ull;

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_LBUS_SLAVE_B_DOORBELL_ERROR_MAILBOX_2 = 26;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_LBUS_SLAVE_B_DOORBELL_ERROR_MAILBOX_1 = 27;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_XDN_MAILBOX_2 = 28;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_XDN_MAILBOX_1 = 29;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_LBUS_SLAVE_B_PENDING_MAILBOX_2 = 30;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_B_DOORBELL_INTERRUPT_LBUS_SLAVE_B_PENDING_MAILBOX_1 = 31;
// perv/reg00004.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_FSI = 0x00002931ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_FSI_BYTE = 0x00002cc4ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_WO_CLEAR = 0x00050131ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE0_SEL_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE0_SEL_DC_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE1_SEL_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE1_SEL_DC_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE_MESH_SEL_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE_DRV_EN_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_PROBE_HIGHDRIVE_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_FSI_PROBE_SEL_DC = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_FSI_PROBE_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_AN_PROBE_DRVR_MCPRECOMP0_DC = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_AN_PROBE_DRVR_MCPRECOMP1_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_AN_PROBE_DRVR_MCPRECOMP2_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_IDDQ_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_SPARE_RI_CONTROL = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_SPARE_DI_CONTROL = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_RI_DC_B = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_DI1_DC_B = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_DI2_DC_B = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_22_SPARE_TEST = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_23_SPARE_TEST = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_TEST_BURNIN_MODE_DC = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TPFSI_ARRAY_SET_VBL_TO_VDD_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_26_SPARE = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_TP_GLBCK_MEM_TESTCLK_SEL_DC = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_28_SPARE_TEST_CONTROL = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_29_SPARE_TEST_CONTROL = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_30_SPARE_TEST_CONTROL = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_CLEAR_ROOT_CTRL1_31_SPARE_TEST_CONTROL = 31;
// perv/reg00004.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_COPY_FSI = 0x00002913ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_COPY_FSI_BYTE = 0x00002c4cull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_COPY_RW = 0x00050113ull;
// perv/reg00004.H

static const uint64_t L3TRA0_TR0_CONFIG_3 = 0x00018206ull;

static const uint32_t L3TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t L3TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t L3TRA0_TR0_CONFIG_3_D_LEN = 24;
// perv/reg00004.H

static const uint64_t L3TRA1_TR1_TRACE_LO_DATA_REG = 0x00018261ull;

static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA1_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00004.H

static const uint64_t L3TRA1_TR1_CONFIG_5 = 0x00018268ull;

static const uint32_t L3TRA1_TR1_CONFIG_5_C = 0;
static const uint32_t L3TRA1_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA1_TR1_CONFIG_5_D = 24;
static const uint32_t L3TRA1_TR1_CONFIG_5_D_LEN = 24;
// perv/reg00004.H

static const uint64_t L3TRA2_TR0_TRACE_HI_DATA_REG = 0x00018280ull;

static const uint32_t L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA2_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00004.H

static const uint64_t L3TRA2_TR0_CONFIG = 0x00018282ull;

static const uint32_t L3TRA2_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA2_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA2_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA2_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA2_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA2_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA2_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA2_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA2_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA2_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA2_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t L3TRA2_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t L3TRA2_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// perv/reg00004.H

static const uint64_t L3TRA2_TR1_CONFIG_2 = 0x000182a5ull;

static const uint32_t L3TRA2_TR1_CONFIG_2_A = 0;
static const uint32_t L3TRA2_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA2_TR1_CONFIG_2_B = 24;
static const uint32_t L3TRA2_TR1_CONFIG_2_B_LEN = 24;
// perv/reg00004.H

static const uint64_t L3TRA3_TR0_CONFIG_4 = 0x000182c7ull;

static const uint32_t L3TRA3_TR0_CONFIG_4_A = 0;
static const uint32_t L3TRA3_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA3_TR0_CONFIG_4_B = 24;
static const uint32_t L3TRA3_TR0_CONFIG_4_B_LEN = 24;
// perv/reg00004.H

static const uint64_t L3TRA3_TR1_CONFIG = 0x000182e2ull;

static const uint32_t L3TRA3_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA3_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA3_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA3_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA3_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA3_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA3_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA3_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA3_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA3_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA3_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t L3TRA3_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t L3TRA3_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// perv/reg00004.H

static const uint64_t LOCAL_XSTOP = 0x00040003ull;

static const uint32_t LOCAL_XSTOP_ANY_LOCAL_XSTOP = 0;
static const uint32_t LOCAL_XSTOP_RESERVED1L = 1;
static const uint32_t LOCAL_XSTOP_RESERVED2L = 2;
static const uint32_t LOCAL_XSTOP_RESERVED3L = 3;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_PERV = 4;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN05 = 5;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN06 = 6;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN07 = 7;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN08 = 8;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN09 = 9;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN10 = 10;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN11 = 11;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN12 = 12;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN13 = 13;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN14 = 14;
static const uint32_t LOCAL_XSTOP_LOCAL_XSTOP_IN15 = 15;
// perv/reg00004.H

static const uint64_t LXSTOP_INTERRUPT_REG = 0x000f002aull;
// perv/reg00004.H

static const uint64_t MULTICAST_GROUP_1 = 0x000f0001ull;

static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
// perv/reg00004.H

static const uint64_t NET_CTRL0_RW = 0x000f0040ull;
static const uint64_t NET_CTRL0_RW_WAND = 0x000f0041ull;
static const uint64_t NET_CTRL0_RW_WOR = 0x000f0042ull;

static const uint32_t NET_CTRL0_CHIPLET_ENABLE = 0;
static const uint32_t NET_CTRL0_PCB_EP_RESET = 1;
static const uint32_t NET_CTRL0_CLK_ASYNC_RESET = 2;
static const uint32_t NET_CTRL0_PLL_TEST_EN = 3;
static const uint32_t NET_CTRL0_PLL_RESET = 4;
static const uint32_t NET_CTRL0_PLL_BYPASS = 5;
static const uint32_t NET_CTRL0_VITAL_SCAN = 6;
static const uint32_t NET_CTRL0_VITAL_SCAN_IN = 7;
static const uint32_t NET_CTRL0_VITAL_PHASE = 8;
static const uint32_t NET_CTRL0_FLUSH_ALIGN_OVR = 9;
static const uint32_t NET_CTRL0_VITAL_AL = 10;
static const uint32_t NET_CTRL0_ACT_DIS = 11;
static const uint32_t NET_CTRL0_SYNC_PULSE = 13;
static const uint32_t NET_CTRL0_MPW3 = 14;
static const uint32_t NET_CTRL0_DELAY_LCLKR = 15;
static const uint32_t NET_CTRL0_VITAL_THOLD = 16;
static const uint32_t NET_CTRL0_FLUSH_SCAN_N = 17;
static const uint32_t NET_CTRL0_FENCE_EN = 18;
static const uint32_t NET_CTRL0_CPLT_RCTRL = 19;
static const uint32_t NET_CTRL0_CPLT_DCTRL = 20;
static const uint32_t NET_CTRL0_CPLT_RCTRL2 = 21;
static const uint32_t NET_CTRL0_ADJ_FUNC_CLKSEL = 22;
static const uint32_t NET_CTRL0_FUNC_LCB_EDIS = 24;
static const uint32_t NET_CTRL0_TP_FENCE_PCB = 25;
static const uint32_t NET_CTRL0_ARRAY_WRITE_ASSIST_EN = 27;
static const uint32_t NET_CTRL0_HTB_INTEST = 28;
static const uint32_t NET_CTRL0_HTB_EXTEST = 29;
static const uint32_t NET_CTRL0_PLLFORCE_OUT_EN = 31;
// perv/reg00004.H

static const uint64_t OTPC_M_MEASURE_REG11 = 0x0001001bull;

static const uint32_t OTPC_M_MEASURE_REG11_SEEPROM_MEASUREMENT11_DATA = 0;
static const uint32_t OTPC_M_MEASURE_REG11_SEEPROM_MEASUREMENT11_DATA_LEN = 64;
// perv/reg00004.H

static const uint64_t PHASE_COUNTER_RESET = 0x00030028ull;

static const uint32_t PHASE_COUNTER_RESET_PHASECOUNTER_RESET = 0;
// perv/reg00004.H

static const uint64_t PLL_LOCK_REG = 0x000f0019ull;
// perv/reg00004.H

static const uint64_t REC_ERR_MST3_REG2 = 0x000f004eull;

static const uint32_t REC_ERR_MST3_REG2_32_MST3_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST3_REG2_32_MST3_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST3_REG2_32_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_33_MST3_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST3_REG2_33_MST3_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST3_REG2_33_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_34_MST3_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST3_REG2_34_MST3_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST3_REG2_34_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_35_MST3_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST3_REG2_35_MST3_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST3_REG2_35_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_36_MST3_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST3_REG2_36_MST3_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST3_REG2_36_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_37_MST3_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST3_REG2_37_MST3_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST3_REG2_37_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_38_MST3_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST3_REG2_38_MST3_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST3_REG2_38_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_39_MST3_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST3_REG2_39_MST3_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST3_REG2_39_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_40_MST3_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST3_REG2_40_MST3_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST3_REG2_40_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_41_MST3_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST3_REG2_41_MST3_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST3_REG2_41_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_42_MST3_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST3_REG2_42_MST3_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST3_REG2_42_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_43_MST3_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST3_REG2_43_MST3_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST3_REG2_43_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_44_MST3_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST3_REG2_44_MST3_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST3_REG2_44_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_45_MST3_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST3_REG2_45_MST3_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST3_REG2_45_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_46_MST3_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST3_REG2_46_MST3_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST3_REG2_46_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG2_47_MST3_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST3_REG2_47_MST3_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST3_REG2_47_MST3_ERROR_CODE_LEN = 3;
// perv/reg00004.H

static const uint64_t REC_ERR_MST7_REG3 = 0x000f005full;

static const uint32_t REC_ERR_MST7_REG3_48_MST7_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST7_REG3_48_MST7_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST7_REG3_48_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_49_MST7_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST7_REG3_49_MST7_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST7_REG3_49_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_50_MST7_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST7_REG3_50_MST7_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST7_REG3_50_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_51_MST7_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST7_REG3_51_MST7_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST7_REG3_51_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_52_MST7_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST7_REG3_52_MST7_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST7_REG3_52_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_53_MST7_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST7_REG3_53_MST7_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST7_REG3_53_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_54_MST7_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST7_REG3_54_MST7_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST7_REG3_54_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_55_MST7_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST7_REG3_55_MST7_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST7_REG3_55_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_56_MST7_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST7_REG3_56_MST7_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST7_REG3_56_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_57_MST7_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST7_REG3_57_MST7_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST7_REG3_57_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_58_MST7_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST7_REG3_58_MST7_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST7_REG3_58_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_59_MST7_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST7_REG3_59_MST7_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST7_REG3_59_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_60_MST7_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST7_REG3_60_MST7_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST7_REG3_60_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_61_MST7_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST7_REG3_61_MST7_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST7_REG3_61_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_62_MST7_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST7_REG3_62_MST7_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST7_REG3_62_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG3_63_MST7_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST7_REG3_63_MST7_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST7_REG3_63_MST7_ERROR_CODE_LEN = 3;
// perv/reg00004.H

static const uint64_t REC_ERR_MST9_REG3 = 0x000f0067ull;

static const uint32_t REC_ERR_MST9_REG3_48_MST9_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST9_REG3_48_MST9_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST9_REG3_48_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_49_MST9_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST9_REG3_49_MST9_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST9_REG3_49_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_50_MST9_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST9_REG3_50_MST9_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST9_REG3_50_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_51_MST9_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST9_REG3_51_MST9_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST9_REG3_51_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_52_MST9_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST9_REG3_52_MST9_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST9_REG3_52_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_53_MST9_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST9_REG3_53_MST9_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST9_REG3_53_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_54_MST9_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST9_REG3_54_MST9_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST9_REG3_54_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_55_MST9_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST9_REG3_55_MST9_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST9_REG3_55_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_56_MST9_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST9_REG3_56_MST9_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST9_REG3_56_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_57_MST9_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST9_REG3_57_MST9_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST9_REG3_57_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_58_MST9_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST9_REG3_58_MST9_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST9_REG3_58_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_59_MST9_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST9_REG3_59_MST9_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST9_REG3_59_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_60_MST9_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST9_REG3_60_MST9_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST9_REG3_60_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_61_MST9_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST9_REG3_61_MST9_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST9_REG3_61_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_62_MST9_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST9_REG3_62_MST9_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST9_REG3_62_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG3_63_MST9_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST9_REG3_63_MST9_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST9_REG3_63_MST9_ERROR_CODE_LEN = 3;
// perv/reg00004.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG108 = 0x0000806cull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG108_REGISTER108 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG108_REGISTER108_LEN = 64;
// perv/reg00004.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG117 = 0x00008075ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG117_REGISTER117 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG117_REGISTER117_LEN = 64;
// perv/reg00004.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG120 = 0x00008078ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG120_REGISTER120 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG120_REGISTER120_LEN = 64;
// perv/reg00004.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG19 = 0x00008013ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG19_REGISTER19 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG19_REGISTER19_LEN = 64;
// perv/reg00004.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG31 = 0x0000801full;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG31_REGISTER31 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG31_REGISTER31_LEN = 64;
// perv/reg00004.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG50 = 0x00008032ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG50_REGISTER50 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG50_REGISTER50_LEN = 64;
// perv/reg00004.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG67 = 0x00008043ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG67_REGISTER67 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG67_REGISTER67_LEN = 64;
// perv/reg00004.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG78 = 0x0000804eull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG78_REGISTER78 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG78_REGISTER78_LEN = 64;
// perv/reg00004.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG9 = 0x00008009ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG9_REGISTER9 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG9_REGISTER9_LEN = 64;
// perv/reg00004.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG92 = 0x0000805cull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG92_REGISTER92 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG92_REGISTER92_LEN = 64;
// perv/reg00004.H

static const uint64_t SPATTN_MASK_RW = 0x00040042ull;
static const uint64_t SPATTN_MASK_WO_CLEAR = 0x00040062ull;
static const uint64_t SPATTN_MASK_WO_OR = 0x00040052ull;

static const uint32_t SPATTN_MASK_01 = 1;
static const uint32_t SPATTN_MASK_02 = 2;
static const uint32_t SPATTN_MASK_03 = 3;
static const uint32_t SPATTN_MASK_04 = 4;
static const uint32_t SPATTN_MASK_05 = 5;
static const uint32_t SPATTN_MASK_06 = 6;
static const uint32_t SPATTN_MASK_07 = 7;
static const uint32_t SPATTN_MASK_08 = 8;
static const uint32_t SPATTN_MASK_09 = 9;
static const uint32_t SPATTN_MASK_10 = 10;
static const uint32_t SPATTN_MASK_11 = 11;
static const uint32_t SPATTN_MASK_12 = 12;
static const uint32_t SPATTN_MASK_13 = 13;
static const uint32_t SPATTN_MASK_14 = 14;
static const uint32_t SPATTN_MASK_15 = 15;
static const uint32_t SPATTN_MASK_16 = 16;
static const uint32_t SPATTN_MASK_17 = 17;
static const uint32_t SPATTN_MASK_18 = 18;
static const uint32_t SPATTN_MASK_19 = 19;
static const uint32_t SPATTN_MASK_20 = 20;
static const uint32_t SPATTN_MASK_21 = 21;
static const uint32_t SPATTN_MASK_22 = 22;
static const uint32_t SPATTN_MASK_23 = 23;
static const uint32_t SPATTN_MASK_24 = 24;
static const uint32_t SPATTN_MASK_25 = 25;
static const uint32_t SPATTN_MASK_26 = 26;
static const uint32_t SPATTN_MASK_27 = 27;
static const uint32_t SPATTN_MASK_28 = 28;
static const uint32_t SPATTN_MASK_29 = 29;
static const uint32_t SPATTN_MASK_30 = 30;
static const uint32_t SPATTN_MASK_31 = 31;
static const uint32_t SPATTN_MASK_32 = 32;
static const uint32_t SPATTN_MASK_33 = 33;
static const uint32_t SPATTN_MASK_34 = 34;
static const uint32_t SPATTN_MASK_35 = 35;
// perv/reg00004.H

static const uint64_t TRA0_TR0_CONFIG_3 = 0x00010406ull;

static const uint32_t TRA0_TR0_CONFIG_3_C = 0;
static const uint32_t TRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_3_D = 24;
static const uint32_t TRA0_TR0_CONFIG_3_D_LEN = 24;
// perv/reg00004.H

static const uint64_t TRA1_TR1_CONFIG_5 = 0x000104c8ull;

static const uint32_t TRA1_TR1_CONFIG_5_C = 0;
static const uint32_t TRA1_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TRA1_TR1_CONFIG_5_D = 24;
static const uint32_t TRA1_TR1_CONFIG_5_D_LEN = 24;
// perv/reg00004.H

static const uint64_t TRA2_TR1_CONFIG_2 = 0x00010545ull;

static const uint32_t TRA2_TR1_CONFIG_2_A = 0;
static const uint32_t TRA2_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TRA2_TR1_CONFIG_2_B = 24;
static const uint32_t TRA2_TR1_CONFIG_2_B_LEN = 24;
// perv/reg00004.H

static const uint64_t TRA3_TR0_CONFIG_4 = 0x00010587ull;

static const uint32_t TRA3_TR0_CONFIG_4_A = 0;
static const uint32_t TRA3_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TRA3_TR0_CONFIG_4_B = 24;
static const uint32_t TRA3_TR0_CONFIG_4_B_LEN = 24;
// perv/reg00005.H

static const uint64_t TRA4_TR0_CONFIG = 0x00010602ull;

static const uint32_t TRA4_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA4_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA4_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA4_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA4_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TRA4_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA4_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA4_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA4_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA4_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA4_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA4_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA4_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA4_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TRA4_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TRA4_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// perv/reg00005.H

static const uint64_t TRA4_TR0_CONFIG_5 = 0x00010608ull;

static const uint32_t TRA4_TR0_CONFIG_5_C = 0;
static const uint32_t TRA4_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA4_TR0_CONFIG_5_D = 24;
static const uint32_t TRA4_TR0_CONFIG_5_D_LEN = 24;
// perv/reg00005.H

static const uint64_t TRA5_TR0_TRACE_LO_DATA_REG = 0x00010681ull;

static const uint32_t TRA5_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA5_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA5_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA5_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA5_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA5_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA5_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA5_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA5_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA5_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA5_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00005.H

static const uint64_t TRA5_TR1_CONFIG = 0x000106c2ull;

static const uint32_t TRA5_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA5_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA5_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA5_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA5_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TRA5_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA5_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA5_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA5_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA5_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA5_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA5_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA5_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA5_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TRA5_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TRA5_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// perv/reg00005.H

static const uint64_t TRA5_TR1_CONFIG_3 = 0x000106c6ull;

static const uint32_t TRA5_TR1_CONFIG_3_C = 0;
static const uint32_t TRA5_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TRA5_TR1_CONFIG_3_D = 24;
static const uint32_t TRA5_TR1_CONFIG_3_D_LEN = 24;
// perv/reg00005.H

static const uint64_t TRA6_TR1_TRACE_HI_DATA_REG = 0x00010740ull;

static const uint32_t TRA6_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA6_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00005.H

static const uint64_t TRA6_TR1_CONFIG_4 = 0x00010747ull;

static const uint32_t TRA6_TR1_CONFIG_4_A = 0;
static const uint32_t TRA6_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TRA6_TR1_CONFIG_4_B = 24;
static const uint32_t TRA6_TR1_CONFIG_4_B_LEN = 24;
// perv/reg00005.H

static const uint64_t TRA7_TR0_CONFIG_2 = 0x00010785ull;

static const uint32_t TRA7_TR0_CONFIG_2_A = 0;
static const uint32_t TRA7_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TRA7_TR0_CONFIG_2_B = 24;
static const uint32_t TRA7_TR0_CONFIG_2_B_LEN = 24;
// perv/reg00005.H

}
}
#include "perv/reg00004.H"
#include "perv/reg00005.H"
#endif
