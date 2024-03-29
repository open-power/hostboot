/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_7.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __p10_scom_perv_7_H_
#define __p10_scom_perv_7_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> [EPS_THERM_WSUB_CONTROL_REG]
static const uint64_t EPS_THERM_WSUB_CONTROL_REG = 0x00050012ull;

static const uint32_t EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY = 0;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT = 1;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD = 2;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR = 3;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS = 4;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS = 5;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE = 6;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS = 7;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS = 8;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS = 9;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE = 10;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT = 11;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR = 12;
//<< [EPS_THERM_WSUB_CONTROL_REG]
// perv/reg00014.H

//>> [FSXCOMP_FSXLOG_PERV_CTRL0_SET]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI = 0x0000292aull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI_BYTE = 0x00002ca8ull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_WO_OR = 0x0005012aull;

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_CHIPLET_EN_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_PCB_EP_RESET_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_AN_CLKGLM_TEST_TCK_ASYNC_RESET = 2;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED = 3;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_3_6_RESERVED_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_SCIN_DC = 7;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_8_RESERVED = 8;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_FLUSH_ALIGN_OVERWRITE = 9;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED = 10;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_10_12_RESERVED_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_SBE_CG_DIS = 13;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_CG_DIS = 14;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_TCPERV_VITL_FFDLYLCK_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_VITL_CLKOFF_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_17_RESERVED = 17;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_EN_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED = 19;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_19_21_RESERVED_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_OTP_SCOM_FUSED_CORE_MODE = 22;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_23_RESERVED = 23;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TCPERV_UNIT_FUNC_CLK_GATE_LCB_TEST_EDIS_DC = 24;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_FENCE_PCB_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED = 26;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_26_27_RESERVED_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_SPI_MVPD0_PROTECT = 28;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_29_RESERVED = 29;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_TP_EX_SINGLE_LPAR_EN_DC = 30;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_SET_PERV_CTRL0_31_SPARE = 31;
//<< [FSXCOMP_FSXLOG_PERV_CTRL0_SET]
// perv/reg00014.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI = 0x00002930ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_BYTE = 0x00002cc0ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_WO_CLEAR = 0x00050130ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_0_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_1_SPARE = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_TPI2C_BUS_FENCE_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPCFSI_OPB_SW0_FENCE_DC_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_6_7_SPARE_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_1_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PROTECTION_2_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_CFAM_PIB_SLV_RESET_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_11_SPARE = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_12_SPARE = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_13_SPARE = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_SPARE_FENCE_CONTROL = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_VDD2VIO_LVL_FENCE_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI2PCB_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_OOB_MUX = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PIB2PCB_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB2PCB_DC = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_REQ = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_FSI_CC_VSB_CBS_CMD_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_24_SPARE_CBS_CONTROL = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_25_SPARE_CBS_CONTROL = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_26_SPARE_CBS_CONTROL = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_27_SPARE_CBS_CONTROL = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_ROOT_CTRL0_28_SPARE_RESET = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_TPFSI_IO_OCMB_RESET_EN = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_PCB_RESET_DC = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR_GLOBAL_EP_RESET_DC = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL0_CLEAR]
// perv/reg00014.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL6]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_FSI = 0x00002816ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_FSI_BYTE = 0x00002858ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_RW = 0x00050016ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS0_RX_REFCLK_TERM_LEN = 2;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_0_3 = 0; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_0_3_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_SYS1_RX_REFCLK_TERM_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI0_RX_REFCLK_TERM_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_TP_AN_PCI1_RX_REFCLK_TERM_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31 = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_8_31_LEN = 24;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_CHKSW_DD1_HW547515_RCS_EVENTLOG = 8; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_9_15 = 9; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_ROOT_CTRL6_9_15_LEN = 7;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_DESKEW_SEL_A = 16; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_DESKEW_SEL_A_LEN = 4;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_DESKEW_SEL_B = 20; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_DESKEW_SEL_B_LEN = 4;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_RCS_CONTROL_7_0 = 24; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_RCS_CONTROL_7_0_LEN = 8;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL6]
// perv/reg00014.H

//>> [FSXCOMP_FSXLOG_SCRATCH_REGISTER_2]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI = 0x00002839ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI_BYTE = 0x000028e4ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_RW = 0x00050039ull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_SR_SCRATCH_REGISTER_2_LEN = 32;
//<< [FSXCOMP_FSXLOG_SCRATCH_REGISTER_2]
// perv/reg00014.H

//>> [HANG_PULSE_0_REG]
static const uint64_t HANG_PULSE_0_REG = 0x000f0020ull;

static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0 = 0;
static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN = 6;
static const uint32_t HANG_PULSE_0_REG_SUPPRESS_HANG_0 = 6;
//<< [HANG_PULSE_0_REG]
// perv/reg00014.H

//>> [HANG_PULSE_1_REG]
static const uint64_t HANG_PULSE_1_REG = 0x000f0021ull;

static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1 = 0;
static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN = 6;
static const uint32_t HANG_PULSE_1_REG_SUPPRESS_HANG_1 = 6;
//<< [HANG_PULSE_1_REG]
// perv/reg00014.H

//>> [HANG_PULSE_2_REG]
static const uint64_t HANG_PULSE_2_REG = 0x000f0022ull;

static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2 = 0;
static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN = 6;
static const uint32_t HANG_PULSE_2_REG_SUPPRESS_HANG_2 = 6;
//<< [HANG_PULSE_2_REG]
// perv/reg00014.H

//>> [HANG_PULSE_3_REG]
static const uint64_t HANG_PULSE_3_REG = 0x000f0023ull;

static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3 = 0;
static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN = 6;
static const uint32_t HANG_PULSE_3_REG_SUPPRESS_HANG_3 = 6;
//<< [HANG_PULSE_3_REG]
// perv/reg00014.H

//>> [HANG_PULSE_4_REG]
static const uint64_t HANG_PULSE_4_REG = 0x000f0024ull;

static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4 = 0;
static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN = 6;
static const uint32_t HANG_PULSE_4_REG_SUPPRESS_HANG_4 = 6;
//<< [HANG_PULSE_4_REG]
// perv/reg00014.H

//>> [HANG_PULSE_5_REG]
static const uint64_t HANG_PULSE_5_REG = 0x000f0025ull;

static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5 = 0;
static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN = 6;
static const uint32_t HANG_PULSE_5_REG_SUPPRESS_HANG_5 = 6;
//<< [HANG_PULSE_5_REG]
// perv/reg00014.H

//>> [OPCG_CAPT2]
static const uint64_t OPCG_CAPT2 = 0x00030011ull;

static const uint32_t OPCG_CAPT2_13_01EVEN = 4;
static const uint32_t OPCG_CAPT2_13_01EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_14_01ODD = 9;
static const uint32_t OPCG_CAPT2_14_01ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_15_02EVEN = 14;
static const uint32_t OPCG_CAPT2_15_02EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_16_02ODD = 19;
static const uint32_t OPCG_CAPT2_16_02ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_17_03EVEN = 24;
static const uint32_t OPCG_CAPT2_17_03EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_18_03ODD = 29;
static const uint32_t OPCG_CAPT2_18_03ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_19_04EVEN = 34;
static const uint32_t OPCG_CAPT2_19_04EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_20_04ODD = 39;
static const uint32_t OPCG_CAPT2_20_04ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_21_05EVEN = 44;
static const uint32_t OPCG_CAPT2_21_05EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_22_05ODD = 49;
static const uint32_t OPCG_CAPT2_22_05ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_23_06EVEN = 54;
static const uint32_t OPCG_CAPT2_23_06EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_24_06ODD = 59;
static const uint32_t OPCG_CAPT2_24_06ODD_LEN = 5;
//<< [OPCG_CAPT2]
// perv/reg00014.H

//>> [SINGLE_OTP_ROM_OTPROM_REG0]
static const uint64_t SINGLE_OTP_ROM_OTPROM_REG0 = 0x00018000ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG0_REGISTER0_LEN = 64;
//<< [SINGLE_OTP_ROM_OTPROM_REG0]
// perv/reg00014.H

//>> [SYNC_CONFIG]
static const uint64_t SYNC_CONFIG = 0x00030000ull;

static const uint32_t SYNC_CONFIG_SYNC_PULSE_DELAY = 0;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_DELAY_LEN = 4;
static const uint32_t SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS = 4;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_INPUT_SEL = 5;
static const uint32_t SYNC_CONFIG_USE_SYNC_FOR_SCAN = 6;
static const uint32_t SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED = 7;
static const uint32_t SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD = 8;
static const uint32_t SYNC_CONFIG_DISABLE_PCB_ITR = 9;
static const uint32_t SYNC_CONFIG_CONT_SCAN_DISABLE = 10;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_OUT_DIS = 11;
static const uint32_t SYNC_CONFIG_REGION_PGOOD_OVERRIDE = 12;
static const uint32_t SYNC_CONFIG_CONT_SCAN_SHORT_WAIT = 13;
static const uint32_t P10_20_SYNC_CONFIG_PCIE32_MODE = 14; // p10:20,
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN = 15;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE = 16;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN = 8;
//<< [SYNC_CONFIG]
// perv/reg00015.H

//>> [TOD_CHIP_CTRL_REG]
static const uint64_t TOD_CHIP_CTRL_REG = 0x00040010ull;

static const uint32_t TOD_CHIP_CTRL_REG_TIMEBASE_ENABLE = 0;
static const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT = 1;
static const uint32_t TOD_CHIP_CTRL_REG_I_PATH_CORE_SYNC_PERIOD_SELECT_LEN = 3;
static const uint32_t TOD_CHIP_CTRL_REG_I_PATH_SYNC_CHECK_DISABLE = 4;
static const uint32_t TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_FSM_STATE_DISABLE = 5;
static const uint32_t TOD_CHIP_CTRL_REG_RX_TTYPE_1_ON_STEP_ENABLE = 6;
static const uint32_t TOD_CHIP_CTRL_REG_MOVE_TOD_TO_TB_ON_2X_SYNC_ENABLE = 7;
static const uint32_t TOD_CHIP_CTRL_REG_USE_TB_SYNC_MECHANISM = 8;
static const uint32_t TOD_CHIP_CTRL_REG_USE_TB_STEP_SYNC = 9;
static const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE = 10;
static const uint32_t TOD_CHIP_CTRL_REG_LOW_ORDER_STEP_VALUE_LEN = 6;
static const uint32_t TOD_CHIP_CTRL_REG_DISTRIBUTION_BROADCAST_MODE_ENABLE = 16;
static const uint32_t TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18 = 17;
static const uint32_t TOD_CHIP_CTRL_REG_REG_0X10_SPARE_17_18_LEN = 2;
static const uint32_t TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23 = 19;
static const uint32_t TOD_CHIP_CTRL_REG_REG_0X10_SPARE_19_23_LEN = 5;
static const uint32_t TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25 = 24;
static const uint32_t TOD_CHIP_CTRL_REG_REG_0X10_SPARE_24_25_LEN = 2;
static const uint32_t TOD_CHIP_CTRL_REG_TX_TTYPE_PIB_MST_IF_RESET = 26;
static const uint32_t TOD_CHIP_CTRL_REG_REG_0X10_SPARE_27 = 27;
static const uint32_t TOD_CHIP_CTRL_REG_M_PATH_CLOCK_OFF_ENABLE = 28;
static const uint32_t TOD_CHIP_CTRL_REG_REG_0X10_SPARE_29 = 29;
static const uint32_t TOD_CHIP_CTRL_REG_XSTOP_GATE = 30;
static const uint32_t TOD_CHIP_CTRL_REG_STICKY_ERROR_INJECT_ENABLE = 31;
//<< [TOD_CHIP_CTRL_REG]
// perv/reg00015.H

//>> [TOD_ERROR_MASK_REG]
static const uint64_t TOD_ERROR_MASK_REG = 0x00040032ull;

static const uint32_t TOD_ERROR_MASK_REG_REG_0X00_DATA_PARITY_ERROR_MASK = 0;
static const uint32_t TOD_ERROR_MASK_REG_M_PATH_0_PARITY_ERROR_MASK = 1;
static const uint32_t TOD_ERROR_MASK_REG_M_PATH_1_PARITY_ERROR_MASK = 2;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X01_DATA_PARITY_ERROR_MASK = 3;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X02_DATA_PARITY_ERROR_MASK = 4;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X03_DATA_PARITY_ERROR_MASK = 5;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X04_DATA_PARITY_ERROR_MASK = 6;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X05_DATA_PARITY_ERROR_MASK = 7;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X06_DATA_PARITY_ERROR_MASK = 8;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X07_DATA_PARITY_ERROR_MASK = 9;
static const uint32_t TOD_ERROR_MASK_REG_S_PATH_0_PARITY_ERROR_MASK = 10;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X08_DATA_PARITY_ERROR_MASK = 11;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X09_DATA_PARITY_ERROR_MASK = 12;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X0A_DATA_PARITY_ERROR_MASK = 13;
static const uint32_t TOD_ERROR_MASK_REG_M_PATH_0_STEP_CHECK_ERROR_MASK = 14;
static const uint32_t TOD_ERROR_MASK_REG_M_PATH_1_STEP_CHECK_ERROR_MASK = 15;
static const uint32_t TOD_ERROR_MASK_REG_S_PATH_0_STEP_CHECK_ERROR_MASK = 16;
static const uint32_t TOD_ERROR_MASK_REG_I_PATH_STEP_CHECK_ERROR_MASK = 17;
static const uint32_t TOD_ERROR_MASK_REG_PSS_HAM_MASK = 18;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X0B_DATA_PARITY_ERROR_MASK = 19;
static const uint32_t TOD_ERROR_MASK_REG_S_PATH_1_PARITY_ERROR_MASK = 20;
static const uint32_t TOD_ERROR_MASK_REG_S_PATH_1_STEP_CHECK_ERROR_MASK = 21;
static const uint32_t TOD_ERROR_MASK_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_MASK = 22;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X0C_DATA_PARITY_ERROR_MASK = 23;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_MASK = 24;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_MASK = 25;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_MASK = 26;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X20_DATA_PARITY_ERROR_MASK = 27;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X23_DATA_PARITY_ERROR_MASK = 28;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X24_DATA_PARITY_ERROR_MASK = 29;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X29_DATA_PARITY_ERROR_MASK = 30;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_MASK = 31;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X10_DATA_PARITY_ERROR_MASK = 32;
static const uint32_t TOD_ERROR_MASK_REG_I_PATH_SYNC_CHECK_ERROR_MASK = 33;
static const uint32_t TOD_ERROR_MASK_REG_I_PATH_FSM_STATE_PARITY_ERROR_MASK = 34;
static const uint32_t TOD_ERROR_MASK_REG_I_PATH_TIME_REG_PARITY_ERROR_MASK = 35;
static const uint32_t TOD_ERROR_MASK_REG_I_PATH_TIME_REG_OVERFLOW_MASK = 36;
static const uint32_t TOD_ERROR_MASK_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_MASK = 37;
static const uint32_t TOD_ERROR_MASK_REG_RX_TTYPE_0_MASK = 38;
static const uint32_t TOD_ERROR_MASK_REG_RX_TTYPE_1_MASK = 39;
static const uint32_t TOD_ERROR_MASK_REG_RX_TTYPE_2_MASK = 40;
static const uint32_t TOD_ERROR_MASK_REG_RX_TTYPE_3_MASK = 41;
static const uint32_t TOD_ERROR_MASK_REG_RX_TTYPE_4_MASK = 42;
static const uint32_t TOD_ERROR_MASK_REG_RX_TTYPE_5_MASK = 43;
static const uint32_t TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_INVALID_ERROR_MASK = 44;
static const uint32_t TOD_ERROR_MASK_REG_PIB_SLAVE_WRITE_INVALID_ERROR_MASK = 45;
static const uint32_t TOD_ERROR_MASK_REG_PIB_SLAVE_READ_INVALID_ERROR_MASK = 46;
static const uint32_t TOD_ERROR_MASK_REG_PIB_SLAVE_ADDR_PARITY_ERROR_MASK = 47;
static const uint32_t TOD_ERROR_MASK_REG_PIB_SLAVE_DATA_PARITY_ERROR_MASK = 48;
static const uint32_t TOD_ERROR_MASK_REG_REG_0X27_DATA_PARITY_ERROR_MASK = 49;
static const uint32_t TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK = 50;
static const uint32_t TOD_ERROR_MASK_REG_PIB_MASTER_RSP_INFO_ERROR_MASK_LEN = 3;
static const uint32_t TOD_ERROR_MASK_REG_RX_TTYPE_INVALID_ERROR_MASK = 53;
static const uint32_t TOD_ERROR_MASK_REG_RX_TTYPE_4_DATA_PARITY_ERROR_MASK = 54;
static const uint32_t TOD_ERROR_MASK_REG_PIB_MASTER_REQUEST_ERROR_MASK = 55;
static const uint32_t TOD_ERROR_MASK_REG_PIB_RESET_DURING_ACCESS_ERROR_MASK = 56;
static const uint32_t TOD_ERROR_MASK_REG_EXTERNAL_XSTOP_ERROR_MASK = 57;
static const uint32_t TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_58 = 58;
static const uint32_t TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_59 = 59;
static const uint32_t TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_60 = 60;
static const uint32_t TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_61 = 61;
static const uint32_t TOD_ERROR_MASK_REG_OSCSWITCH_INTERRUPT_MASK = 62;
static const uint32_t TOD_ERROR_MASK_REG_SPARE_ERROR_MASK_63 = 63;
//<< [TOD_ERROR_MASK_REG]
// perv/reg00015.H

//>> [TOD_ERROR_ROUTING_REG]
static const uint64_t TOD_ERROR_ROUTING_REG = 0x00040033ull;

static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X00_DATA_PARITY_ERROR_ROUTING = 0;
static const uint32_t TOD_ERROR_ROUTING_REG_M_PATH_0_PARITY_ERROR_ROUTING = 1;
static const uint32_t TOD_ERROR_ROUTING_REG_M_PATH_1_PARITY_ERROR_ROUTING = 2;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X01_DATA_PARITY_ERROR_ROUTING = 3;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X02_DATA_PARITY_ERROR_ROUTING = 4;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X03_DATA_PARITY_ERROR_ROUTING = 5;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X04_DATA_PARITY_ERROR_ROUTING = 6;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X05_DATA_PARITY_ERROR_ROUTING = 7;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X06_DATA_PARITY_ERROR_ROUTING = 8;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X07_DATA_PARITY_ERROR_ROUTING = 9;
static const uint32_t TOD_ERROR_ROUTING_REG_S_PATH_0_PARITY_ERROR_ROUTING = 10;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X08_DATA_PARITY_ERROR_ROUTING = 11;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X09_DATA_PARITY_ERROR_ROUTING = 12;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X0A_DATA_PARITY_ERROR_ROUTING = 13;
static const uint32_t TOD_ERROR_ROUTING_REG_M_PATH_0_STEP_CHECK_ERROR_ROUTING = 14;
static const uint32_t TOD_ERROR_ROUTING_REG_M_PATH_1_STEP_CHECK_ERROR_ROUTING = 15;
static const uint32_t TOD_ERROR_ROUTING_REG_S_PATH_0_STEP_CHECK_ERROR_ROUTING = 16;
static const uint32_t TOD_ERROR_ROUTING_REG_I_PATH_STEP_CHECK_ERROR_ROUTING = 17;
static const uint32_t TOD_ERROR_ROUTING_REG_PSS_HAM_CORE_INTERRUPT_MASK = 18;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X0B_DATA_PARITY_ERROR_ROUTING = 19;
static const uint32_t TOD_ERROR_ROUTING_REG_S_PATH_1_PARITY_ERROR_ROUTING = 20;
static const uint32_t TOD_ERROR_ROUTING_REG_S_PATH_1_STEP_CHECK_ERROR_ROUTING = 21;
static const uint32_t TOD_ERROR_ROUTING_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR_ROUTING = 22;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X0C_DATA_PARITY_ERROR_ROUTING = 23;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR_ROUTING = 24;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR_ROUTING = 25;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR_ROUTING = 26;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X20_DATA_PARITY_ERROR_ROUTING = 27;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X23_DATA_PARITY_ERROR_ROUTING = 28;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X24_DATA_PARITY_ERROR_ROUTING = 29;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X29_DATA_PARITY_ERROR_ROUTING = 30;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR_ROUTING = 31;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X10_DATA_PARITY_ERROR_ROUTING = 32;
static const uint32_t TOD_ERROR_ROUTING_REG_I_PATH_SYNC_CHECK_ERROR_ROUTING = 33;
static const uint32_t TOD_ERROR_ROUTING_REG_I_PATH_FSM_STATE_PARITY_ERROR_ROUTING = 34;
static const uint32_t TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_PARITY_ERROR_ROUTING = 35;
static const uint32_t TOD_ERROR_ROUTING_REG_I_PATH_TIME_REG_OVERFLOW_CORE_INTERRUPT = 36;
static const uint32_t TOD_ERROR_ROUTING_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR_ROUTING = 37;
static const uint32_t TOD_ERROR_ROUTING_REG_RX_TTYPE_0_ERROR_ROUTING = 38;
static const uint32_t TOD_ERROR_ROUTING_REG_RX_TTYPE_1_ERROR_ROUTING = 39;
static const uint32_t TOD_ERROR_ROUTING_REG_RX_TTYPE_2_ERROR_ROUTING = 40;
static const uint32_t TOD_ERROR_ROUTING_REG_RX_TTYPE_3_ERROR_ROUTING = 41;
static const uint32_t TOD_ERROR_ROUTING_REG_RX_TTYPE_4_ERROR_ROUTING = 42;
static const uint32_t TOD_ERROR_ROUTING_REG_RX_TTYPE_5_ERROR_ROUTING = 43;
static const uint32_t TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_INVALID_ERROR_ROUTING = 44;
static const uint32_t TOD_ERROR_ROUTING_REG_PIB_SLAVE_WRITE_INVALID_ERROR_ROUTING = 45;
static const uint32_t TOD_ERROR_ROUTING_REG_PIB_SLAVE_READ_INVALID_ERROR_ROUTING = 46;
static const uint32_t TOD_ERROR_ROUTING_REG_PIB_SLAVE_ADDR_PARITY_ERROR_ROUTING = 47;
static const uint32_t TOD_ERROR_ROUTING_REG_PIB_SLAVE_DATA_PARITY_ERROR_ROUTING = 48;
static const uint32_t TOD_ERROR_ROUTING_REG_REG_0X27_DATA_PARITY_ERROR_ROUTING = 49;
static const uint32_t TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING = 50;
static const uint32_t TOD_ERROR_ROUTING_REG_PIB_MASTER_RSP_INFO_ERROR_ROUTING_LEN = 3;
static const uint32_t TOD_ERROR_ROUTING_REG_RX_TTYPE_INVALID_ERROR_ROUTING = 53;
static const uint32_t TOD_ERROR_ROUTING_REG_RX_TTYPE_4_DATA_PARITY_ERROR_ROUTING = 54;
static const uint32_t TOD_ERROR_ROUTING_REG_PIB_MASTER_REQUEST_ERROR_ROUTING = 55;
static const uint32_t TOD_ERROR_ROUTING_REG_PIB_RESET_DURING_ACCESS_ERROR_ROUTING = 56;
static const uint32_t TOD_ERROR_ROUTING_REG_EXTERNAL_XSTOP_ERROR_ROUTING = 57;
static const uint32_t TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_58 = 58;
static const uint32_t TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_59 = 59;
static const uint32_t TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_60 = 60;
static const uint32_t TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_61 = 61;
static const uint32_t TOD_ERROR_ROUTING_REG_OSCSWITCH_INTERRUPT_ROUTING = 62;
static const uint32_t TOD_ERROR_ROUTING_REG_SPARE_ERROR_ROUTING_63 = 63;
//<< [TOD_ERROR_ROUTING_REG]
// perv/reg00015.H

//>> [TOD_I_PATH_CTRL_REG]
static const uint64_t TOD_I_PATH_CTRL_REG = 0x00040006ull;

static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_DELAY_DISABLE = 0;
static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_DISABLE = 1;
static const uint32_t TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04 = 2;
static const uint32_t TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_02_04_LEN = 3;
static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_SELECT = 5;
static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR = 6;
static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN = 2;
static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION = 8;
static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CPS_DEVIATION_LEN = 4;
static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_CONSTANT_CPS_ENABLE = 12;
static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT = 13;
static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_STEP_CHECK_VALIDITY_COUNT_LEN = 3;
static const uint32_t TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21 = 16;
static const uint32_t TOD_I_PATH_CTRL_REG_REG_0X06_SPARE_16_21_LEN = 6;
static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE = 22;
static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_DELAY_ADJUST_VALUE_LEN = 10;
static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_CPS = 32;
static const uint32_t TOD_I_PATH_CTRL_REG_I_PATH_CPS_LEN = 8;
//<< [TOD_I_PATH_CTRL_REG]
// perv/reg00015.H

//>> [TOD_MOVE_TO_TB_REG]
static const uint64_t TOD_MOVE_TO_TB_REG = 0x00040017ull;

static const uint32_t TOD_MOVE_TO_TB_REG_MOVE_TOD_TO_TB_TRIGGER = 0;
//<< [TOD_MOVE_TO_TB_REG]
// perv/reg00015.H

//>> [TOD_M_PATH_1_STEP_STEER_REG]
static const uint64_t TOD_M_PATH_1_STEP_STEER_REG = 0x0004000full;

static const uint32_t TOD_M_PATH_1_STEP_STEER_REG_MODE = 0;
static const uint32_t TOD_M_PATH_1_STEP_STEER_REG_RATE = 1;
static const uint32_t TOD_M_PATH_1_STEP_STEER_REG_RATE_LEN = 31;
static const uint32_t TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_FLAG = 32;
static const uint32_t TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE = 33;
static const uint32_t TOD_M_PATH_1_STEP_STEER_REG_COUNTER_LOAD_VALUE_LEN = 31;
//<< [TOD_M_PATH_1_STEP_STEER_REG]
// perv/reg00015.H

//>> [FSXCOMP_FSXLOG_I2CDEVICEID_REGISTER]
static const uint64_t FSXCOMP_FSXLOG_I2CDEVICEID_REGISTER = 0x00050190ull;

static const uint32_t FSXCOMP_FSXLOG_I2CDEVICEID_REGISTER_I2C_DEVICEID_REGISTER = 0;
static const uint32_t FSXCOMP_FSXLOG_I2CDEVICEID_REGISTER_I2C_DEVICEID_REGISTER_LEN = 32;
static const uint32_t P10_20_FSXCOMP_FSXLOG_I2CDEVICEID_REGISTER_PORT_PROTECTION_A = 0; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_I2CDEVICEID_REGISTER_PORT_PROTECTION_A_LEN = 18;
static const uint32_t P10_20_FSXCOMP_FSXLOG_I2CDEVICEID_REGISTER_SLV_ID_A = 18; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_I2CDEVICEID_REGISTER_SLV_ID_A_LEN = 7;
static const uint32_t P10_20_FSXCOMP_FSXLOG_I2CDEVICEID_REGISTER_MASK_ID_A = 25; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_I2CDEVICEID_REGISTER_MASK_ID_A_LEN = 7;
//<< [FSXCOMP_FSXLOG_I2CDEVICEID_REGISTER]
// perv/reg00014.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00014.H"
#include "perv/reg00015.H"
#endif
#endif
