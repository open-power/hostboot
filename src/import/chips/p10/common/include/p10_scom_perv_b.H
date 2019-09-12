/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_b.H $       */
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

#ifndef __p10_scom_perv_b_H_
#define __p10_scom_perv_b_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


static const uint64_t ATOMIC_LOCK_REG = 0x000f03ffull;

static const uint32_t ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t ATOMIC_LOCK_REG_ID = 1;
static const uint32_t ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// perv/reg00022.H

static const uint64_t ATTN_INTERRUPT_REG = 0x000f001aull;

static const uint32_t ATTN_INTERRUPT_REG_ATTN = 0;
// perv/reg00022.H

static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_HOLD_MODE = 0x00018321ull;
// perv/reg00022.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_COMP_DLY = 0x0001430bull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE_LEN = 16;
// perv/reg00022.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_DEC_DCC = 0x0001430full;
// perv/reg00022.H

static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SENSOR_DATA = 0x00012339ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ORE_IS_LATE = 3;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ACHE_IS_LATE = 7;
// perv/reg00022.H

static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_CHICKEN_SWITCHES = 0x00012335ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_CHICKEN_SWITCHES_STOP_ON_ERROR = 0;
// perv/reg00022.H

static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_DEC_DCC = 0x0001130full;
// perv/reg00022.H

static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_HOLD_MODE = 0x00011301ull;
// perv/reg00022.H

static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_LOW_PASS_DLY = 0x00011309ull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_LOW_PASS_DLY_LOW_PASS_DELAY_VALUE = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_LOW_PASS_DLY_LOW_PASS_DELAY_VALUE_LEN = 16;
// perv/reg00022.H

static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE = 0x00011327ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE = 0;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE = 4;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE_LEN = 4;
// perv/reg00022.H

static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_SINGLE_STEP_MODE = 0x00011324ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_SINGLE_STEP_MODE_STEP_COUNT = 0;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_SINGLE_STEP_MODE_STEP_COUNT_LEN = 32;
// perv/reg00022.H

static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT = 0x00011328ull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE = 0;
static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE_LEN = 6;
// perv/reg00022.H

static const uint64_t COMP_INTR_INTERRUPT_HOLD_REG = 0x000f0032ull;

static const uint32_t COMP_INTR_INTERRUPT_HOLD_REG_INTERRUPT_HOLD = 0;
static const uint32_t COMP_INTR_INTERRUPT_HOLD_REG_INTERRUPT_HOLD_LEN = 26;
// perv/reg00022.H

static const uint64_t COMP_P_0_CRSIS = 0x00030007ull;
// perv/reg00022.H

static const uint64_t EPS_DBG_TRACE_MODE_REG_2 = 0x000107cfull;

static const uint32_t EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE = 0;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_RUNN_COUNT_COMPARE_VALUE_LEN = 16;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_IMM_FREEZE_MODE = 16;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_STOP_ON_ERR = 17;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_BANK_ON_RUNN_MATCH = 18;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_FORCE_TEST_MODE = 19;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_ACCUM_HIST_MODE = 20;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_FRZ_COUNT_ON = 21;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK = 22;
static const uint32_t EPS_DBG_TRACE_MODE_REG_2_EXTEND_BANK_LEN = 2;
// perv/reg00022.H

static const uint64_t EPS_FIR_LOCAL_MASK_RW = 0x00040103ull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_AND = 0x00040104ull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_OR = 0x00040105ull;

static const uint32_t EPS_FIR_LOCAL_MASK_00 = 0;
static const uint32_t EPS_FIR_LOCAL_MASK_01 = 1;
static const uint32_t EPS_FIR_LOCAL_MASK_02 = 2;
static const uint32_t EPS_FIR_LOCAL_MASK_03 = 3;
static const uint32_t EPS_FIR_LOCAL_MASK_04 = 4;
static const uint32_t EPS_FIR_LOCAL_MASK_05 = 5;
static const uint32_t EPS_FIR_LOCAL_MASK_06 = 6;
static const uint32_t EPS_FIR_LOCAL_MASK_07 = 7;
static const uint32_t EPS_FIR_LOCAL_MASK_08 = 8;
static const uint32_t EPS_FIR_LOCAL_MASK_09 = 9;
static const uint32_t EPS_FIR_LOCAL_MASK_10 = 10;
static const uint32_t EPS_FIR_LOCAL_MASK_11 = 11;
static const uint32_t EPS_FIR_LOCAL_MASK_12 = 12;
static const uint32_t EPS_FIR_LOCAL_MASK_13 = 13;
static const uint32_t EPS_FIR_LOCAL_MASK_14 = 14;
static const uint32_t EPS_FIR_LOCAL_MASK_15 = 15;
static const uint32_t EPS_FIR_LOCAL_MASK_16 = 16;
static const uint32_t EPS_FIR_LOCAL_MASK_17 = 17;
static const uint32_t EPS_FIR_LOCAL_MASK_18 = 18;
static const uint32_t EPS_FIR_LOCAL_MASK_19 = 19;
static const uint32_t EPS_FIR_LOCAL_MASK_20 = 20;
static const uint32_t EPS_FIR_LOCAL_MASK_21 = 21;
static const uint32_t EPS_FIR_LOCAL_MASK_22 = 22;
static const uint32_t EPS_FIR_LOCAL_MASK_23 = 23;
static const uint32_t EPS_FIR_LOCAL_MASK_24 = 24;
static const uint32_t EPS_FIR_LOCAL_MASK_25 = 25;
static const uint32_t EPS_FIR_LOCAL_MASK_26 = 26;
static const uint32_t EPS_FIR_LOCAL_MASK_27 = 27;
static const uint32_t EPS_FIR_LOCAL_MASK_28 = 28;
static const uint32_t EPS_FIR_LOCAL_MASK_29 = 29;
static const uint32_t EPS_FIR_LOCAL_MASK_30 = 30;
static const uint32_t EPS_FIR_LOCAL_MASK_31 = 31;
static const uint32_t EPS_FIR_LOCAL_MASK_32 = 32;
static const uint32_t EPS_FIR_LOCAL_MASK_33 = 33;
static const uint32_t EPS_FIR_LOCAL_MASK_34 = 34;
static const uint32_t EPS_FIR_LOCAL_MASK_35 = 35;
static const uint32_t EPS_FIR_LOCAL_MASK_36 = 36;
static const uint32_t EPS_FIR_LOCAL_MASK_37 = 37;
static const uint32_t EPS_FIR_LOCAL_MASK_38 = 38;
static const uint32_t EPS_FIR_LOCAL_MASK_39 = 39;
static const uint32_t EPS_FIR_LOCAL_MASK_40 = 40;
static const uint32_t EPS_FIR_LOCAL_MASK_41 = 41;
static const uint32_t EPS_FIR_LOCAL_MASK_42 = 42;
static const uint32_t EPS_FIR_LOCAL_MASK_43 = 43;
static const uint32_t EPS_FIR_LOCAL_MASK_44 = 44;
static const uint32_t EPS_FIR_LOCAL_MASK_45 = 45;
static const uint32_t EPS_FIR_LOCAL_MASK_46 = 46;
static const uint32_t EPS_FIR_LOCAL_MASK_47 = 47;
static const uint32_t EPS_FIR_LOCAL_MASK_48 = 48;
static const uint32_t EPS_FIR_LOCAL_MASK_49 = 49;
static const uint32_t EPS_FIR_LOCAL_MASK_50 = 50;
static const uint32_t EPS_FIR_LOCAL_MASK_51 = 51;
static const uint32_t EPS_FIR_LOCAL_MASK_52 = 52;
static const uint32_t EPS_FIR_LOCAL_MASK_53 = 53;
static const uint32_t EPS_FIR_LOCAL_MASK_54 = 54;
static const uint32_t EPS_FIR_LOCAL_MASK_55 = 55;
static const uint32_t EPS_FIR_LOCAL_MASK_56 = 56;
static const uint32_t EPS_FIR_LOCAL_MASK_57 = 57;
static const uint32_t EPS_FIR_LOCAL_MASK_58 = 58;
static const uint32_t EPS_FIR_LOCAL_MASK_59 = 59;
static const uint32_t EPS_FIR_LOCAL_MASK_60 = 60;
static const uint32_t EPS_FIR_LOCAL_MASK_61 = 61;
static const uint32_t EPS_FIR_LOCAL_MASK_62 = 62;
static const uint32_t EPS_FIR_LOCAL_MASK_63 = 63;
// perv/reg00022.H

static const uint64_t EPS_THERM_WSUB2_CONTROL_REG = 0x00050032ull;

static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_RESET_TRIP_HISTORY = 0;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_RESET_SAMPLE_PULSE_CNT = 1;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_F_RESET_CPM_RD = 2;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_F_RESET_CPM_WR = 3;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_RESET_SAMPLE_DTS = 4;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_SAMPLE_DTS = 5;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE = 6;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS = 7;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS = 8;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS = 9;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE = 10;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_RESET_MEASURE_VOLT = 11;
static const uint32_t EPS_THERM_WSUB2_CONTROL_REG_FORCE_SHIFT_SENSOR = 12;
// perv/reg00022.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_DATA2 = 0x0005003bull;
// perv/reg00022.H

static const uint64_t FIRST_ERR_REG = 0x000f001eull;

static const uint32_t FIRST_ERR_REG_TIMEOUT_ACTIVE = 0;
static const uint32_t FIRST_ERR_REG_PARITY_ERR = 1;
static const uint32_t FIRST_ERR_REG_BEAT_NUM_ERR = 2;
static const uint32_t FIRST_ERR_REG_BEAT_REC_ERR = 3;
static const uint32_t FIRST_ERR_REG_RECEIVED_ERROR = 4;
static const uint32_t FIRST_ERR_REG_RX_PCB_DATA_P_ERR = 5;
static const uint32_t FIRST_ERR_REG_PIB_ADDR_P_ERR = 6;
static const uint32_t FIRST_ERR_REG_PIB_DATA_P_ERR = 7;
// perv/reg00022.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_1_FSI = 0x00002841ull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_1_FSI_BYTE = 0x00002904ull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_1_RW = 0x00050041ull;

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_1_MDA_M1A_DATA_AREA_1 = 0;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_1_MDA_M1A_DATA_AREA_1_LEN = 32;
// perv/reg00022.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI = 0x000028ccull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_12_FSI_BYTE = 0x00002b30ull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_12_RW = 0x000500ccull;

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_12_MDA_M2A_DATA_AREA_12 = 0;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_12_MDA_M2A_DATA_AREA_12_LEN = 32;
// perv/reg00022.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_7_FSI = 0x00002907ull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_7_FSI_BYTE = 0x00002c1cull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_7_RW = 0x00050107ull;

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_7_MDA_M2B_DATA_AREA_7 = 0;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_7_MDA_M2B_DATA_AREA_7_LEN = 32;
// perv/reg00022.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_B_FSI = 0x00002826ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_B_FSI_BYTE = 0x00002898ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_B_RO = 0x00050026ull;

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_B_M1HC1B_MAILBOX_1_HEADER_COMMAND_B = 0;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_B_M1HC1B_MAILBOX_1_HEADER_COMMAND_B_LEN = 32;
// perv/reg00022.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_A_FSI = 0x0000282aull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_A_FSI_BYTE = 0x000028a8ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_A_RW = 0x0005002aull;

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_A_M2HC1A_MAILBOX_2_HEADER_COMMAND_1_A = 0;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_A_M2HC1A_MAILBOX_2_HEADER_COMMAND_1_A_LEN = 32;
// perv/reg00022.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_FSI = 0x00002814ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_FSI_BYTE = 0x00002850ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_RW = 0x00050014ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0A_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0B_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0C_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX0D_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX10_CLKIN_SEL_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX11_CLKIN_SEL_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX12_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX13_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX14_CLKIN_SEL_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_REFCLK_CLKMUX23_CLKIN_SEL_DC_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_TOD_LPC_MUX_SEL_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_18_SPARE = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_19_SPARE = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX1_CLKIN_SEL_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2A_CLKIN_SEL_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX2B_CLKIN_SEL_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX3_CLKIN_SEL_DC = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_MUX4A_CLKIN_SEL_DC = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_CLKGLM_NEST_ASYNC_RESET_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_26_SPARE = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE = 31;
// perv/reg00022.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_COPY_FSI = 0x00002914ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_COPY_FSI_BYTE = 0x00002c50ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_COPY_RW = 0x00050114ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_COPY_ROOT_CTRL4_COPY_REG = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_COPY_ROOT_CTRL4_COPY_REG_LEN = 32;
// perv/reg00022.H

static const uint64_t L3TRA0_TR1_CONFIG_1 = 0x00018224ull;

static const uint32_t L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00022.H

static const uint64_t L3TRA1_TR0_TRACE_LO_DATA_REG = 0x00018241ull;

static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00022.H

static const uint64_t L3TRA2_TR0_CONFIG_0 = 0x00018283ull;

static const uint32_t L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00022.H

static const uint64_t L3TRA2_TR1_TRACE_HI_DATA_REG = 0x000182a0ull;

static const uint32_t L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA2_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00022.H

static const uint64_t L3TRA2_TR1_CONFIG_9 = 0x000182a9ull;

static const uint32_t L3TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t L3TRA2_TR1_CONFIG_9_SPARE_LT = 37;
// perv/reg00022.H

static const uint64_t LOCAL_FIR_RW = 0x00040100ull;
static const uint64_t LOCAL_FIR_WO_AND = 0x00040101ull;
static const uint64_t LOCAL_FIR_WO_OR = 0x00040102ull;

static const uint32_t LOCAL_FIR_CFIR = 0;
static const uint32_t LOCAL_FIR_CPLT_CTRL = 1;
static const uint32_t LOCAL_FIR_CC_PCB = 2;
static const uint32_t LOCAL_FIR_CC_OTHERS = 3;
static const uint32_t LOCAL_FIR_IN04 = 4;
static const uint32_t LOCAL_FIR_IN05 = 5;
static const uint32_t LOCAL_FIR_IN06 = 6;
static const uint32_t LOCAL_FIR_IN07 = 7;
static const uint32_t LOCAL_FIR_IN08 = 8;
static const uint32_t LOCAL_FIR_IN09 = 9;
static const uint32_t LOCAL_FIR_IN10 = 10;
static const uint32_t LOCAL_FIR_IN11 = 11;
static const uint32_t LOCAL_FIR_IN12 = 12;
static const uint32_t LOCAL_FIR_IN13 = 13;
static const uint32_t LOCAL_FIR_IN14 = 14;
static const uint32_t LOCAL_FIR_IN15 = 15;
static const uint32_t LOCAL_FIR_IN16 = 16;
static const uint32_t LOCAL_FIR_IN17 = 17;
static const uint32_t LOCAL_FIR_IN18 = 18;
static const uint32_t LOCAL_FIR_IN19 = 19;
static const uint32_t LOCAL_FIR_IN20 = 20;
static const uint32_t LOCAL_FIR_IN21 = 21;
static const uint32_t LOCAL_FIR_IN22 = 22;
static const uint32_t LOCAL_FIR_IN23 = 23;
static const uint32_t LOCAL_FIR_IN24 = 24;
static const uint32_t LOCAL_FIR_IN25 = 25;
static const uint32_t LOCAL_FIR_IN26 = 26;
static const uint32_t LOCAL_FIR_IN27 = 27;
static const uint32_t LOCAL_FIR_IN28 = 28;
static const uint32_t LOCAL_FIR_IN29 = 29;
static const uint32_t LOCAL_FIR_IN30 = 30;
static const uint32_t LOCAL_FIR_IN31 = 31;
static const uint32_t LOCAL_FIR_IN32 = 32;
static const uint32_t LOCAL_FIR_IN33 = 33;
static const uint32_t LOCAL_FIR_IN34 = 34;
static const uint32_t LOCAL_FIR_IN35 = 35;
static const uint32_t LOCAL_FIR_IN36 = 36;
static const uint32_t LOCAL_FIR_IN37 = 37;
static const uint32_t LOCAL_FIR_IN38 = 38;
static const uint32_t LOCAL_FIR_IN39 = 39;
static const uint32_t LOCAL_FIR_IN40 = 40;
static const uint32_t LOCAL_FIR_IN41 = 41;
static const uint32_t LOCAL_FIR_IN42 = 42;
static const uint32_t LOCAL_FIR_IN43 = 43;
static const uint32_t LOCAL_FIR_IN44 = 44;
static const uint32_t LOCAL_FIR_IN45 = 45;
static const uint32_t LOCAL_FIR_IN46 = 46;
static const uint32_t LOCAL_FIR_IN47 = 47;
static const uint32_t LOCAL_FIR_IN48 = 48;
static const uint32_t LOCAL_FIR_IN49 = 49;
static const uint32_t LOCAL_FIR_IN50 = 50;
static const uint32_t LOCAL_FIR_IN51 = 51;
static const uint32_t LOCAL_FIR_IN52 = 52;
static const uint32_t LOCAL_FIR_IN53 = 53;
static const uint32_t LOCAL_FIR_IN54 = 54;
static const uint32_t LOCAL_FIR_IN55 = 55;
static const uint32_t LOCAL_FIR_IN56 = 56;
static const uint32_t LOCAL_FIR_IN57 = 57;
static const uint32_t LOCAL_FIR_IN58 = 58;
static const uint32_t LOCAL_FIR_IN59 = 59;
static const uint32_t LOCAL_FIR_IN60 = 60;
static const uint32_t LOCAL_FIR_IN61 = 61;
static const uint32_t LOCAL_FIR_IN62 = 62;
static const uint32_t LOCAL_FIR_EXT_LOCAL_XSTOP = 63;
// perv/reg00022.H

static const uint64_t MCAST_GRP_1_SLAVES_REG = 0x000f0001ull;

static const uint32_t MCAST_GRP_1_SLAVES_REG_SLAVES_MCAST_GROUP_1 = 0;
static const uint32_t MCAST_GRP_1_SLAVES_REG_SLAVES_MCAST_GROUP_1_LEN = 6;
// perv/reg00022.H

static const uint64_t MCAST_GRP_2_SLAVES_REG = 0x000f0002ull;

static const uint32_t MCAST_GRP_2_SLAVES_REG_SLAVES_MCAST_GROUP_2 = 0;
static const uint32_t MCAST_GRP_2_SLAVES_REG_SLAVES_MCAST_GROUP_2_LEN = 6;
// perv/reg00022.H

static const uint64_t MCAST_GRP_4_SLAVES_REG = 0x000f0004ull;

static const uint32_t MCAST_GRP_4_SLAVES_REG_SLAVES_MCAST_GROUP_4 = 0;
static const uint32_t MCAST_GRP_4_SLAVES_REG_SLAVES_MCAST_GROUP_4_LEN = 6;
// perv/reg00022.H

static const uint64_t OTPC_M_EXPORT_REGL_CTRL = 0x0001000eull;

static const uint32_t OTPC_M_EXPORT_REGL_CTRL_TP_NX_ALLOW_CRYPTO_DC = 0;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_TP_EX_FUSE_VMX_CRYPTO_DIS_DC = 1;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_TP_EX_EFUSE_EXTENDED_MEMORY_DISABLE_DC = 2;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_TP_PB_FUSE_TOPOLOGY_2CHIP = 3;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_TP_PB_FUSE_TOPOLOGY_GROUP = 4;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_TP_PB_FUSE_TOPOLOGY_GROUP_LEN = 2;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_TP_NP_NVLINK_DISABLE = 6;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_OTP_PCBMS_HW_MODE_SEL_DC = 7;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_OTP_PCBMS_FUSED_CORE_MODE_SEL0_DC = 8;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_OTP_PCBMS_FUSED_CORE_MODE_SEL1_DC = 9;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_TP_MC_ALLOW_CRYPTO_DC = 10;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_OTP_SPIM_MEAS_SEEPROM_LOCK_DC = 11;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_TP_PAU_POWER_HEADER_DISABLE_DC = 12;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_TP_PAU_POWER_HEADER_DISABLE_DC_LEN = 6;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_TP_EX_FUSE_FLOP_THROTTLE_EN_DC = 18;
static const uint32_t OTPC_M_EXPORT_REGL_CTRL_TP_EX_FUSE_FLOP_THROTTLE_EN_DC_LEN = 2;
// perv/reg00022.H

static const uint64_t OTPC_M_EXPORT_REGL_STATUS = 0x00010009ull;

static const uint32_t OTPC_M_EXPORT_REGL_STATUS_TP_NX_ALLOW_CRYPTO_DC = 0;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_TP_EX_FUSE_VMX_CRYPTO_DIS_DC = 1;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_TP_EX_EFUSE_EXTENDED_MEMORY_DISABLE_DC = 2;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_TP_PB_FUSE_TOPOLOGY_2CHIP = 3;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_TP_PB_FUSE_TOPOLOGY_GROUP = 4;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_TP_PB_FUSE_TOPOLOGY_GROUP_LEN = 2;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_TP_NP_NVLINK_DISABLE = 6;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_OTP_PCBMS_HW_MODE_SEL_DC = 7;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_OTP_PCBMS_FUSED_CORE_MODE_SEL0_DC = 8;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_OTP_PCBMS_FUSED_CORE_MODE_SEL1_DC = 9;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_TP_EX_FUSE_SMT8_CTYPE_EN_DC = 10;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_TP_MC_ALLOW_CRYPTO_DC = 11;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_OTP_SPIM_MEAS_SEEPROM_LOCK_DC = 12;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_TP_PAU_POWER_HEADER_DISABLE_DC = 13;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_TP_PAU_POWER_HEADER_DISABLE_DC_LEN = 6;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_TP_EX_FUSE_FLOP_THROTTLE_EN_DC = 19;
static const uint32_t OTPC_M_EXPORT_REGL_STATUS_TP_EX_FUSE_FLOP_THROTTLE_EN_DC_LEN = 2;
// perv/reg00022.H

static const uint64_t OTPC_M_MEASURE_REG1 = 0x00010011ull;

static const uint32_t OTPC_M_MEASURE_REG1_SEEPROM_MEASUREMENT1_DATA = 0;
static const uint32_t OTPC_M_MEASURE_REG1_SEEPROM_MEASUREMENT1_DATA_LEN = 64;
// perv/reg00022.H

static const uint64_t RECOV = 0x00040001ull;

static const uint32_t RECOV_ANY_RECOV = 0;
static const uint32_t RECOV_RESERVED1R = 1;
static const uint32_t RECOV_ANY_LOCAL_XSTOP = 2;
static const uint32_t RECOV_RESERVED3R = 3;
static const uint32_t RECOV_PERV = 4;
static const uint32_t RECOV_IN05 = 5;
static const uint32_t RECOV_IN06 = 6;
static const uint32_t RECOV_IN07 = 7;
static const uint32_t RECOV_IN08 = 8;
static const uint32_t RECOV_IN09 = 9;
static const uint32_t RECOV_IN10 = 10;
static const uint32_t RECOV_IN11 = 11;
static const uint32_t RECOV_IN12 = 12;
static const uint32_t RECOV_IN13 = 13;
static const uint32_t RECOV_IN14 = 14;
static const uint32_t RECOV_IN15 = 15;
static const uint32_t RECOV_IN16 = 16;
static const uint32_t RECOV_IN17 = 17;
static const uint32_t RECOV_IN18 = 18;
static const uint32_t RECOV_IN19 = 19;
static const uint32_t RECOV_IN20 = 20;
static const uint32_t RECOV_IN21 = 21;
static const uint32_t RECOV_IN22 = 22;
static const uint32_t RECOV_IN23 = 23;
static const uint32_t RECOV_IN24 = 24;
static const uint32_t RECOV_IN25 = 25;
static const uint32_t RECOV_IN26 = 26;
static const uint32_t RECOV_IN27 = 27;
static const uint32_t RECOV_IN28 = 28;
static const uint32_t RECOV_IN29 = 29;
static const uint32_t RECOV_IN30 = 30;
static const uint32_t RECOV_IN31 = 31;
static const uint32_t RECOV_IN32 = 32;
static const uint32_t RECOV_IN33 = 33;
static const uint32_t RECOV_IN34 = 34;
static const uint32_t RECOV_IN35 = 35;
static const uint32_t RECOV_IN36 = 36;
static const uint32_t RECOV_IN37 = 37;
static const uint32_t RECOV_IN38 = 38;
static const uint32_t RECOV_IN39 = 39;
static const uint32_t RECOV_IN40 = 40;
static const uint32_t RECOV_IN41 = 41;
static const uint32_t RECOV_IN42 = 42;
static const uint32_t RECOV_IN43 = 43;
static const uint32_t RECOV_IN44 = 44;
static const uint32_t RECOV_IN45 = 45;
static const uint32_t RECOV_IN46 = 46;
static const uint32_t RECOV_IN47 = 47;
static const uint32_t RECOV_IN48 = 48;
static const uint32_t RECOV_IN49 = 49;
static const uint32_t RECOV_IN50 = 50;
static const uint32_t RECOV_IN51 = 51;
static const uint32_t RECOV_IN52 = 52;
static const uint32_t RECOV_IN53 = 53;
// perv/reg00022.H

static const uint64_t REC_ACK_REG = 0x000f0010ull;

static const uint32_t REC_ACK_REG_RECEIVE_ACKNOWLEDGE_REGISTER = 0;
static const uint32_t REC_ACK_REG_RECEIVE_ACKNOWLEDGE_REGISTER_LEN = 64;
// perv/reg00022.H

static const uint64_t REC_ERR_MST4_REG2 = 0x000f0052ull;

static const uint32_t REC_ERR_MST4_REG2_32_MST4_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST4_REG2_32_MST4_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST4_REG2_32_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_33_MST4_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST4_REG2_33_MST4_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST4_REG2_33_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_34_MST4_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST4_REG2_34_MST4_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST4_REG2_34_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_35_MST4_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST4_REG2_35_MST4_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST4_REG2_35_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_36_MST4_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST4_REG2_36_MST4_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST4_REG2_36_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_37_MST4_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST4_REG2_37_MST4_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST4_REG2_37_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_38_MST4_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST4_REG2_38_MST4_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST4_REG2_38_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_39_MST4_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST4_REG2_39_MST4_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST4_REG2_39_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_40_MST4_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST4_REG2_40_MST4_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST4_REG2_40_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_41_MST4_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST4_REG2_41_MST4_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST4_REG2_41_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_42_MST4_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST4_REG2_42_MST4_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST4_REG2_42_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_43_MST4_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST4_REG2_43_MST4_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST4_REG2_43_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_44_MST4_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST4_REG2_44_MST4_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST4_REG2_44_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_45_MST4_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST4_REG2_45_MST4_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST4_REG2_45_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_46_MST4_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST4_REG2_46_MST4_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST4_REG2_46_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG2_47_MST4_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST4_REG2_47_MST4_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST4_REG2_47_MST4_ERROR_CODE_LEN = 3;
// perv/reg00022.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG103 = 0x00018067ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG103_REGISTER103 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG103_REGISTER103_LEN = 64;
// perv/reg00022.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG12 = 0x0001800cull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG12_REGISTER12 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG12_REGISTER12_LEN = 64;
// perv/reg00022.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG2 = 0x00018002ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG2_REGISTER2 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG2_REGISTER2_LEN = 64;
// perv/reg00022.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG25 = 0x00018019ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG25_REGISTER25 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG25_REGISTER25_LEN = 64;
// perv/reg00022.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG44 = 0x0001802cull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG44_REGISTER44 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG44_REGISTER44_LEN = 64;
// perv/reg00022.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG73 = 0x00018049ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG73_REGISTER73 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG73_REGISTER73_LEN = 64;
// perv/reg00022.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG86 = 0x00018056ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG86_REGISTER86 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG86_REGISTER86_LEN = 64;
// perv/reg00022.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG99 = 0x00018063ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG99_REGISTER99 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG99_REGISTER99_LEN = 64;
// perv/reg00022.H

static const uint64_t TOD_TX_TTYPE_0_REG = 0x00040011ull;

static const uint32_t TOD_TX_TTYPE_0_REG_TX_TTYPE_0_TRIGGER = 0;
// perv/reg00023.H

static const uint64_t TOD_TX_TTYPE_1_REG = 0x00040012ull;

static const uint32_t TOD_TX_TTYPE_1_REG_TX_TTYPE_1_TRIGGER = 0;
// perv/reg00023.H

static const uint64_t TOD_TX_TTYPE_2_REG = 0x00040013ull;

static const uint32_t TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER = 0;
// perv/reg00023.H

static const uint64_t TOD_TX_TTYPE_3_REG = 0x00040014ull;

static const uint32_t TOD_TX_TTYPE_3_REG_TX_TTYPE_3_TRIGGER = 0;
// perv/reg00023.H

static const uint64_t TOD_TX_TTYPE_4_REG = 0x00040015ull;

static const uint32_t TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER = 0;
// perv/reg00023.H

static const uint64_t TOD_TX_TTYPE_5_REG = 0x00040016ull;

static const uint32_t TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER = 0;
// perv/reg00023.H

static const uint64_t TRA0_TR1_CONFIG_1 = 0x00010444ull;

static const uint32_t TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA0_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00023.H

static const uint64_t TRA2_TR0_CONFIG_0 = 0x00010503ull;

static const uint32_t TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00023.H

static const uint64_t TRA2_TR1_CONFIG = 0x00010542ull;

static const uint32_t TRA2_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA2_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA2_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA2_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA2_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TRA2_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA2_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA2_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA2_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA2_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA2_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA2_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TRA2_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TRA2_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// perv/reg00023.H

static const uint64_t TRA2_TR1_CONFIG_9 = 0x00010549ull;

static const uint32_t TRA2_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA2_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA2_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA2_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA2_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA2_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA2_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA2_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA2_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t TRA2_TR1_CONFIG_9_SPARE_LT = 37;
// perv/reg00023.H

static const uint64_t TRA3_TR0_CONFIG = 0x00010582ull;

static const uint32_t TRA3_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA3_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA3_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA3_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA3_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TRA3_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA3_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA3_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA3_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA3_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA3_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA3_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TRA3_TR0_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TRA3_TR0_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// perv/reg00023.H

static const uint64_t TRA5_TR0_CONFIG_1 = 0x00010684ull;

static const uint32_t TRA5_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA5_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00023.H

static const uint64_t TRA5_TR1_TRACE_LO_DATA_REG = 0x000106c1ull;

static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA5_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00023.H

static const uint64_t TRA6_TR0_TRACE_HI_DATA_REG = 0x00010700ull;

static const uint32_t TRA6_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA6_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00023.H

static const uint64_t TRA7_TR0_CONFIG_9 = 0x00010789ull;

static const uint32_t TRA7_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA7_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA7_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA7_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA7_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA7_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA7_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA7_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA7_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t TRA7_TR0_CONFIG_9_SPARE_LT = 37;
// perv/reg00023.H

static const uint64_t XSTOP4 = 0x00030014ull;

static const uint32_t XSTOP4_ENABLE = 0;
static const uint32_t XSTOP4_WAIT_SNOPA = 1;
static const uint32_t XSTOP4_TRIGGER_OPCG_GO = 2;
static const uint32_t XSTOP4_WAIT_ALWAYS = 3;
static const uint32_t XSTOP4_REGION_PERV = 4;
static const uint32_t XSTOP4_REGION_UNIT1 = 5;
static const uint32_t XSTOP4_REGION_UNIT2 = 6;
static const uint32_t XSTOP4_REGION_UNIT3 = 7;
static const uint32_t XSTOP4_REGION_UNIT4 = 8;
static const uint32_t XSTOP4_REGION_UNIT5 = 9;
static const uint32_t XSTOP4_REGION_UNIT6 = 10;
static const uint32_t XSTOP4_REGION_UNIT7 = 11;
static const uint32_t XSTOP4_REGION_UNIT8 = 12;
static const uint32_t XSTOP4_REGION_UNIT9 = 13;
static const uint32_t XSTOP4_REGION_UNIT10 = 14;
static const uint32_t XSTOP4_REGION_UNIT11 = 15;
static const uint32_t XSTOP4_REGION_UNIT12 = 16;
static const uint32_t XSTOP4_REGION_UNIT13 = 17;
static const uint32_t XSTOP4_REGION_UNIT14 = 18;
static const uint32_t XSTOP4_WAIT_CYCLES = 48;
static const uint32_t XSTOP4_WAIT_CYCLES_LEN = 12;
// perv/reg00023.H

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00022.H"
#include "perv/reg00023.H"
#endif
#endif
