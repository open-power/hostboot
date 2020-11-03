/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_8.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __p10_scom_perv_8_H_
#define __p10_scom_perv_8_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> [DPLL_CNTL_MISC_REGS_PFET]
//ERRCODE: // Some of the name targets not found in address targets: perv

static const uint64_t DPLL_CNTL_MISC_REGS_PFET = 0x00060080ull;

static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC = 0;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC = 0; // p10:20,
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC = 1;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC = 1; // p10:20,
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC = 2;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC = 2; // p10:20,
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC = 3;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC = 3; // p10:20,
// ERROR Duplicate Dial         static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_DISABLED_SENSE_OUT_DC = 4;
// ERROR Duplicate Dial         static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_DISABLED_SENSE_OUT_DC = 4; // p10:20,
// ERROR Duplicate Dial         static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO2_VDD_PFETS_ENABLED_SENSE_OUT_DC = 5;
// ERROR Duplicate Dial         static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO1_VDD_PFETS_ENABLED_SENSE_OUT_DC = 5; // p10:20,
// ERROR Duplicate Dial         static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_DISABLED_SENSE_OUT_DC = 6;
// ERROR Duplicate Dial         static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_DISABLED_SENSE_OUT_DC = 6; // p10:20,
// ERROR Duplicate Dial         static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO3_VDD_PFETS_ENABLED_SENSE_OUT_DC = 7;
// ERROR Duplicate Dial         static const uint32_t DPLL_CNTL_MISC_REGS_PFET_EMO0_VDD_PFETS_ENABLED_SENSE_OUT_DC = 7; // p10:20,
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_DISABLED_SENSE_OUT_DC = 8;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PAU0_VDD_PFETS_ENABLED_SENSE_OUT_DC = 9;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_DISABLED_SENSE_OUT_DC = 10;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PAU3_VDD_PFETS_ENABLED_SENSE_OUT_DC = 11;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_DISABLED_SENSE_OUT_DC = 12;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PAU4_VDD_PFETS_ENABLED_SENSE_OUT_DC = 13;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_DISABLED_SENSE_OUT_DC = 14;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PAU5_VDD_PFETS_ENABLED_SENSE_OUT_DC = 15;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_DISABLED_SENSE_OUT_DC = 16;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PAU6_VDD_PFETS_ENABLED_SENSE_OUT_DC = 17;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_DISABLED_SENSE_OUT_DC = 18;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PAU7_VDD_PFETS_ENABLED_SENSE_OUT_DC = 19;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC = 20;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC = 20; // p10:20,
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC = 21;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC = 21; // p10:20,
// ERROR Duplicate Dial         static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_DISABLED_SENSE_OUT_DC = 22;
// ERROR Duplicate Dial         static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_DISABLED_SENSE_OUT_DC = 22; // p10:20,
// ERROR Duplicate Dial         static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PCIE1_VDD_PFETS_ENABLED_SENSE_OUT_DC = 23;
// ERROR Duplicate Dial         static const uint32_t DPLL_CNTL_MISC_REGS_PFET_PCIE0_VDD_PFETS_ENABLED_SENSE_OUT_DC = 23; // p10:20,
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_DISABLED_SENSE_OUT_DC = 24;
static const uint32_t DPLL_CNTL_MISC_REGS_PFET_NMMU_VDD_PFETS_ENABLED_SENSE_OUT_DC = 25;
//<< [DPLL_CNTL_MISC_REGS_PFET]
// perv/reg00016.H

//>> [EPS_FIR_LOCAL_ACTION0]
static const uint64_t EPS_FIR_LOCAL_ACTION0 = 0x00040106ull;

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
//<< [EPS_FIR_LOCAL_ACTION0]
// perv/reg00016.H

//>> [ERROR_REG]
static const uint64_t ERROR_REG = 0x000f001full;

static const uint32_t ERROR_REG_TIMEOUT_ACTIVE = 0;
static const uint32_t ERROR_REG_CE_ERROR = 0;
static const uint32_t ERROR_REG_PARITY_ERR = 1;
static const uint32_t ERROR_REG_CHIPLET_ERRORS = 1;
static const uint32_t ERROR_REG_CHIPLET_ERRORS_LEN = 3;
static const uint32_t ERROR_REG_BEAT_NUM_ERR = 2;
static const uint32_t ERROR_REG_BEAT_REC_ERR = 3;
static const uint32_t ERROR_REG_RECEIVED_ERROR = 4;
static const uint32_t ERROR_REG_PARITY_ERROR = 4;
static const uint32_t ERROR_REG_RX_PCB_DATA_P_ERR = 5;
static const uint32_t ERROR_REG_DATA_BUFFER_ERROR = 5;
static const uint32_t ERROR_REG_PIB_ADDR_P_ERR = 6;
static const uint32_t ERROR_REG_ADDR_BUFFER_ERROR = 6;
static const uint32_t ERROR_REG_PIB_DATA_P_ERR = 7;
static const uint32_t ERROR_REG_PCB_FSM_ERROR = 7;
static const uint32_t ERROR_REG_DEC_MCAST_GRP_ERR = 8;
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
static const uint32_t ERROR_REG_QME_RISING_EDGE_DETECTED_ON_QUIESCE = 36; // p10:20,
static const uint32_t ERROR_REG_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE = 37; // p10:20,
//<< [ERROR_REG]
// perv/reg00016.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL1_COPY]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI = 0x00002911ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_FSI_BYTE = 0x00002c44ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_RW = 0x00050111ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL1_COPY_ROOT_CTRL1_COPY_REG_LEN = 32;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL1_COPY]
// perv/reg00016.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL3]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_FSI = 0x00002813ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_FSI_BYTE = 0x0000284cull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_RW = 0x00050013ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_RESET_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_BYPASS_EN_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_TEST_EN_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW1_ALTREFCLK_SEL_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_RESET_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_BYPASS_EN_DC = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_TEST_EN_DC = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLCLKSW2_ALTREFCLK_SEL_DC = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_RESET_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_BYPASS_EN_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLTODFLT_TEST_EN_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLTODFLT = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_RESET_DC = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_BYPASS_EN_DC = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLNESTFLT_TEST_EN_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLNESTFLT = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_RESET_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_BYPASS_EN_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOFLT_TEST_EN_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOFLT = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_RESET_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_BYPASS_EN_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PLLIOSSFLT_TEST_EN_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_SPARE_PLLIOSSFLT = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_RESET_DC = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_BYPASS_EN_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_TEST_EN_DC = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_PAU_DPLL_FUNC_CLKSEL_DC = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_RESET_DC = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_BYPASS_EN_DC = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_TEST_EN_DC = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_TP_NEST_DPLL_FUNC_CLKSEL_DC = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL3]
// perv/reg00016.H

//>> [FSXCOMP_FSXLOG_SCRATCH_REGISTER_7]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI = 0x0000283eull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI_BYTE = 0x000028f8ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_RW = 0x0005003eull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_SR_SCRATCH_REGISTER_7_LEN = 32;
//<< [FSXCOMP_FSXLOG_SCRATCH_REGISTER_7]
// perv/reg00016.H

//>> [OPCG_REG0]
static const uint64_t OPCG_REG0 = 0x00030002ull;

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
static const uint32_t OPCG_REG0_RUNN_HLD_DLY_EN = 15;
static const uint32_t OPCG_REG0_LOOP_COUNT = 21;
static const uint32_t OPCG_REG0_LOOP_COUNT_LEN = 43;
//<< [OPCG_REG0]
// perv/reg00016.H

//>> [OTPC_M_SECURITY_SWITCH_REGISTER]
static const uint64_t OTPC_M_SECURITY_SWITCH_REGISTER = 0x00010005ull;
static const uint64_t OTPC_M_SECURITY_SWITCH_REGISTER_SCOM1 = 0x00010006ull;

static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS = 0;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_PRIMARY = 1;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_LATE_LAUNCH_SECONDARY = 2;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_LOCAL_QUIESCE_ACHIEVED = 3;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SEEPROM_UPDATE_LOCK = 4;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_LOCALITY_4_ACCESS = 5;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_DEBUG = 6;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPARE0 = 7;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_ABUS_SECURITY_LOCK = 8;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK = 9;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE0 = 10;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_PROT_EX_SPARE1 = 11;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPIMST_TPM_DECONFIG_PROTECT = 12;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK = 13;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE0 = 14;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_PROT_TP_SPARE1 = 15;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_WRITE_PROTECT = 16;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK0_READ_PROTECT = 17;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_WRITE_PROTECT = 18;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK1_READ_PROTECT = 19;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_WRITE_PROTECT = 20;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK2_READ_PROTECT = 21;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_WRITE_PROTECT = 22;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK3_READ_PROTECT = 23;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_WRITE_PROTECT = 24;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK4_READ_PROTECT = 25;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE0_PROTECT = 26;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_SPIM_SECURE_KEY_LOCK_SPARE1_PROTECT = 27;
static const uint32_t OTPC_M_SECURITY_SWITCH_REGISTER_MC_MEMORY_ENCRYPTION_LOCK = 28;
//<< [OTPC_M_SECURITY_SWITCH_REGISTER]
// perv/reg00016.H

//>> [OTPC_M_STATUS_REGISTER]
static const uint64_t OTPC_M_STATUS_REGISTER = 0x00010002ull;

static const uint32_t OTPC_M_STATUS_REGISTER_ADDR_NVLD = 0;
static const uint32_t OTPC_M_STATUS_REGISTER_WRITE_NVLD = 1;
static const uint32_t OTPC_M_STATUS_REGISTER_READ_NVLD = 2;
static const uint32_t OTPC_M_STATUS_REGISTER_INVLD_CMD_ERR = 3;
static const uint32_t OTPC_M_STATUS_REGISTER_CORR_ERR = 4;
static const uint32_t OTPC_M_STATUS_REGISTER_UNCORR_ERROR = 5;
static const uint32_t OTPC_M_STATUS_REGISTER_DATA_REG_0_31 = 6;
static const uint32_t OTPC_M_STATUS_REGISTER_DATA_REG_0_31_LEN = 32;
static const uint32_t OTPC_M_STATUS_REGISTER_CTRL_BUSY = 44;
static const uint32_t OTPC_M_STATUS_REGISTER_DCOMP_ERR = 45;
static const uint32_t OTPC_M_STATUS_REGISTER_INVLD_PRGM_ERR = 46;
static const uint32_t OTPC_M_STATUS_REGISTER_COMMAND_COMPLETE = 52;
static const uint32_t OTPC_M_STATUS_REGISTER_RDWR_OP_BUSY = 54;
static const uint32_t OTPC_M_STATUS_REGISTER_DCOMP_ENGINE_BUSY = 55;
static const uint32_t OTPC_M_STATUS_REGISTER_RD_DATA_COUNT = 56;
static const uint32_t OTPC_M_STATUS_REGISTER_RD_DATA_COUNT_LEN = 8;
//<< [OTPC_M_STATUS_REGISTER]
// perv/reg00016.H

//>> [REC_ERR_REG0]
static const uint64_t REC_ERR_REG0 = 0x000f0011ull;

static const uint32_t REC_ERR_REG0_MASTER_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_REG0_MASTER_ERROR_CODE = 1;
static const uint32_t REC_ERR_REG0_MASTER_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE1_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_REG0_SLAVE1_ERROR_CODE = 5;
static const uint32_t REC_ERR_REG0_SLAVE1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE2_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_REG0_SLAVE2_ERROR_CODE = 9;
static const uint32_t REC_ERR_REG0_SLAVE2_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE3_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_REG0_SLAVE3_ERROR_CODE = 13;
static const uint32_t REC_ERR_REG0_SLAVE3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE4_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_REG0_SLAVE4_ERROR_CODE = 17;
static const uint32_t REC_ERR_REG0_SLAVE4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE5_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_REG0_SLAVE5_ERROR_CODE = 21;
static const uint32_t REC_ERR_REG0_SLAVE5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE6_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_REG0_SLAVE6_ERROR_CODE = 25;
static const uint32_t REC_ERR_REG0_SLAVE6_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE7_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_REG0_SLAVE7_ERROR_CODE = 29;
static const uint32_t REC_ERR_REG0_SLAVE7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE8_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_REG0_SLAVE8_ERROR_CODE = 33;
static const uint32_t REC_ERR_REG0_SLAVE8_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE9_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_REG0_SLAVE9_ERROR_CODE = 37;
static const uint32_t REC_ERR_REG0_SLAVE9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE10_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_REG0_SLAVE10_ERROR_CODE = 41;
static const uint32_t REC_ERR_REG0_SLAVE10_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE11_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_REG0_SLAVE11_ERROR_CODE = 45;
static const uint32_t REC_ERR_REG0_SLAVE11_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE12_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_REG0_SLAVE12_ERROR_CODE = 49;
static const uint32_t REC_ERR_REG0_SLAVE12_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE13_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_REG0_SLAVE13_ERROR_CODE = 53;
static const uint32_t REC_ERR_REG0_SLAVE13_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE14_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_REG0_SLAVE14_ERROR_CODE = 57;
static const uint32_t REC_ERR_REG0_SLAVE14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG0_SLAVE15_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_REG0_SLAVE15_ERROR_CODE = 61;
static const uint32_t REC_ERR_REG0_SLAVE15_ERROR_CODE_LEN = 3;
//<< [REC_ERR_REG0]
// perv/reg00016.H

//>> [SCAN_REGION_TYPE]
static const uint64_t SCAN_REGION_TYPE = 0x00030005ull;

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
//<< [SCAN_REGION_TYPE]
// perv/reg00017.H

//>> [TRA0_TR0_CONFIG]
static const uint64_t TRA0_TR0_CONFIG = 0x00010402ull;

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
//<< [TRA0_TR0_CONFIG]
// perv/reg00017.H

//>> [WOF]
static const uint64_t WOF = 0x00040021ull;

static const uint32_t WOF_ANY_WOF = 0;
static const uint32_t WOF_RESERVED1W = 1;
static const uint32_t WOF_ANY_LOCAL_XSTOP = 2;
static const uint32_t WOF_RESERVED3W = 3;
static const uint32_t WOF_PERV = 4;
static const uint32_t WOF_IN05 = 5;
static const uint32_t WOF_IN06 = 6;
static const uint32_t WOF_IN07 = 7;
static const uint32_t WOF_IN08 = 8;
static const uint32_t WOF_IN09 = 9;
static const uint32_t WOF_IN010 = 10;
static const uint32_t WOF_IN011 = 11;
static const uint32_t WOF_IN012 = 12;
static const uint32_t WOF_IN013 = 13;
static const uint32_t WOF_IN014 = 14;
static const uint32_t WOF_IN015 = 15;
static const uint32_t WOF_IN016 = 16;
static const uint32_t WOF_IN017 = 17;
static const uint32_t WOF_IN018 = 18;
static const uint32_t WOF_IN019 = 19;
static const uint32_t WOF_IN020 = 20;
static const uint32_t WOF_IN021 = 21;
static const uint32_t WOF_IN022 = 22;
static const uint32_t WOF_IN023 = 23;
static const uint32_t WOF_IN024 = 24;
static const uint32_t WOF_IN025 = 25;
static const uint32_t WOF_IN026 = 26;
static const uint32_t WOF_IN027 = 27;
static const uint32_t WOF_IN028 = 28;
static const uint32_t WOF_IN029 = 29;
static const uint32_t WOF_IN030 = 30;
static const uint32_t WOF_IN031 = 31;
static const uint32_t WOF_IN032 = 32;
static const uint32_t WOF_IN033 = 33;
static const uint32_t WOF_IN034 = 34;
static const uint32_t WOF_IN035 = 35;
static const uint32_t WOF_IN036 = 36;
static const uint32_t WOF_IN037 = 37;
static const uint32_t WOF_IN038 = 38;
static const uint32_t WOF_IN039 = 39;
static const uint32_t WOF_IN040 = 40;
static const uint32_t WOF_IN041 = 41;
static const uint32_t WOF_IN042 = 42;
static const uint32_t WOF_IN043 = 43;
static const uint32_t WOF_IN044 = 44;
static const uint32_t WOF_IN045 = 45;
static const uint32_t WOF_IN046 = 46;
static const uint32_t WOF_IN047 = 47;
static const uint32_t WOF_IN048 = 48;
static const uint32_t WOF_IN049 = 49;
static const uint32_t WOF_IN050 = 50;
static const uint32_t WOF_IN051 = 51;
static const uint32_t WOF_IN052 = 52;
static const uint32_t WOF_IN053 = 53;
//<< [WOF]
// perv/reg00017.H

//>> [XSTOP3]
static const uint64_t XSTOP3 = 0x0003000eull;

static const uint32_t XSTOP3_ENABLE = 0;
static const uint32_t XSTOP3_WAIT_SNOPA = 1;
static const uint32_t XSTOP3_TRIGGER_OPCG_GO = 2;
static const uint32_t XSTOP3_WAIT_ALWAYS = 3;
static const uint32_t XSTOP3_REGION_PERV = 4;
static const uint32_t XSTOP3_REGION_UNIT1 = 5;
static const uint32_t XSTOP3_REGION_UNIT2 = 6;
static const uint32_t XSTOP3_REGION_UNIT3 = 7;
static const uint32_t XSTOP3_REGION_UNIT4 = 8;
static const uint32_t XSTOP3_REGION_UNIT5 = 9;
static const uint32_t XSTOP3_REGION_UNIT6 = 10;
static const uint32_t XSTOP3_REGION_UNIT7 = 11;
static const uint32_t XSTOP3_REGION_UNIT8 = 12;
static const uint32_t XSTOP3_REGION_UNIT9 = 13;
static const uint32_t XSTOP3_REGION_UNIT10 = 14;
static const uint32_t XSTOP3_REGION_UNIT11 = 15;
static const uint32_t XSTOP3_REGION_UNIT12 = 16;
static const uint32_t XSTOP3_REGION_UNIT13 = 17;
static const uint32_t XSTOP3_REGION_UNIT14 = 18;
static const uint32_t XSTOP3_WAIT_CYCLES = 48;
static const uint32_t XSTOP3_WAIT_CYCLES_LEN = 12;
//<< [XSTOP3]
// perv/reg00017.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00016.H"
#include "perv/reg00017.H"
#endif
#endif
