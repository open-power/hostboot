/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_7.H $         */
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

#ifndef __p10_scom_eq_7_H_
#define __p10_scom_eq_7_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ONE_SHOT_MODE = 0x20018323ull;
// eq/reg00007.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_PHASE_MEASUREMENT = 0x20014318ull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL = 1;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL_LEN = 7;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL = 8;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL = 9;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL_LEN = 7;
// eq/reg00007.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_ENABLE_OVERRIDE = 0x20014312ull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_ENABLE_OVERRIDE_ENA = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_ENABLE_OVERRIDE_VAL = 1;
// eq/reg00007.H

static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE = 0x20014327ull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE = 0;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE = 4;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE_LEN = 4;
// eq/reg00007.H

static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_SWAP_CORE_INC_DEC = 0x2001432eull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_SWAP_CORE_INC_DEC_CORE_INC_DEC_INVERT = 0;
// eq/reg00007.H

static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS = 0x2001232dull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT = 0;
// eq/reg00007.H

static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CACHE_SYNC_ENABLE = 0x20012331ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CACHE_SYNC_ENABLE_ENABLE_OVERRIDE = 0;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_OVERRIDE_CACHE_SYNC_ENABLE_VALUE_OVERRIDE = 1;
// eq/reg00007.H

static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_DEC = 0x20011310ull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_DEC_DCC_VALUE = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_DEC_DCC_VALUE_LEN = 8;
// eq/reg00007.H

static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_ONE_SHOT_MODE = 0x20011323ull;
// eq/reg00007.H

static const uint64_t EPS_FIR_LOCAL_WOF = 0x20040108ull;

static const uint32_t EPS_FIR_LOCAL_WOF_00 = 0;
static const uint32_t EPS_FIR_LOCAL_WOF_01 = 1;
static const uint32_t EPS_FIR_LOCAL_WOF_02 = 2;
static const uint32_t EPS_FIR_LOCAL_WOF_03 = 3;
static const uint32_t EPS_FIR_LOCAL_WOF_04 = 4;
static const uint32_t EPS_FIR_LOCAL_WOF_05 = 5;
static const uint32_t EPS_FIR_LOCAL_WOF_06 = 6;
static const uint32_t EPS_FIR_LOCAL_WOF_07 = 7;
static const uint32_t EPS_FIR_LOCAL_WOF_08 = 8;
static const uint32_t EPS_FIR_LOCAL_WOF_09 = 9;
static const uint32_t EPS_FIR_LOCAL_WOF_10 = 10;
static const uint32_t EPS_FIR_LOCAL_WOF_11 = 11;
static const uint32_t EPS_FIR_LOCAL_WOF_12 = 12;
static const uint32_t EPS_FIR_LOCAL_WOF_13 = 13;
static const uint32_t EPS_FIR_LOCAL_WOF_14 = 14;
static const uint32_t EPS_FIR_LOCAL_WOF_15 = 15;
static const uint32_t EPS_FIR_LOCAL_WOF_16 = 16;
static const uint32_t EPS_FIR_LOCAL_WOF_17 = 17;
static const uint32_t EPS_FIR_LOCAL_WOF_18 = 18;
static const uint32_t EPS_FIR_LOCAL_WOF_19 = 19;
static const uint32_t EPS_FIR_LOCAL_WOF_20 = 20;
static const uint32_t EPS_FIR_LOCAL_WOF_21 = 21;
static const uint32_t EPS_FIR_LOCAL_WOF_22 = 22;
static const uint32_t EPS_FIR_LOCAL_WOF_23 = 23;
static const uint32_t EPS_FIR_LOCAL_WOF_24 = 24;
static const uint32_t EPS_FIR_LOCAL_WOF_25 = 25;
static const uint32_t EPS_FIR_LOCAL_WOF_26 = 26;
static const uint32_t EPS_FIR_LOCAL_WOF_27 = 27;
static const uint32_t EPS_FIR_LOCAL_WOF_28 = 28;
static const uint32_t EPS_FIR_LOCAL_WOF_29 = 29;
static const uint32_t EPS_FIR_LOCAL_WOF_30 = 30;
static const uint32_t EPS_FIR_LOCAL_WOF_31 = 31;
static const uint32_t EPS_FIR_LOCAL_WOF_32 = 32;
static const uint32_t EPS_FIR_LOCAL_WOF_33 = 33;
static const uint32_t EPS_FIR_LOCAL_WOF_34 = 34;
static const uint32_t EPS_FIR_LOCAL_WOF_35 = 35;
static const uint32_t EPS_FIR_LOCAL_WOF_36 = 36;
static const uint32_t EPS_FIR_LOCAL_WOF_37 = 37;
static const uint32_t EPS_FIR_LOCAL_WOF_38 = 38;
static const uint32_t EPS_FIR_LOCAL_WOF_39 = 39;
static const uint32_t EPS_FIR_LOCAL_WOF_40 = 40;
static const uint32_t EPS_FIR_LOCAL_WOF_41 = 41;
static const uint32_t EPS_FIR_LOCAL_WOF_42 = 42;
static const uint32_t EPS_FIR_LOCAL_WOF_43 = 43;
static const uint32_t EPS_FIR_LOCAL_WOF_44 = 44;
static const uint32_t EPS_FIR_LOCAL_WOF_45 = 45;
static const uint32_t EPS_FIR_LOCAL_WOF_46 = 46;
static const uint32_t EPS_FIR_LOCAL_WOF_47 = 47;
static const uint32_t EPS_FIR_LOCAL_WOF_48 = 48;
static const uint32_t EPS_FIR_LOCAL_WOF_49 = 49;
static const uint32_t EPS_FIR_LOCAL_WOF_50 = 50;
static const uint32_t EPS_FIR_LOCAL_WOF_51 = 51;
static const uint32_t EPS_FIR_LOCAL_WOF_52 = 52;
static const uint32_t EPS_FIR_LOCAL_WOF_53 = 53;
static const uint32_t EPS_FIR_LOCAL_WOF_54 = 54;
static const uint32_t EPS_FIR_LOCAL_WOF_55 = 55;
static const uint32_t EPS_FIR_LOCAL_WOF_56 = 56;
static const uint32_t EPS_FIR_LOCAL_WOF_57 = 57;
static const uint32_t EPS_FIR_LOCAL_WOF_58 = 58;
static const uint32_t EPS_FIR_LOCAL_WOF_59 = 59;
static const uint32_t EPS_FIR_LOCAL_WOF_60 = 60;
static const uint32_t EPS_FIR_LOCAL_WOF_61 = 61;
static const uint32_t EPS_FIR_LOCAL_WOF_62 = 62;
static const uint32_t EPS_FIR_LOCAL_WOF_63 = 63;
// eq/reg00007.H

static const uint64_t EPS_THERM_WSUB_CONTROL_REG = 0x20050012ull;

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
// eq/reg00007.H

static const uint64_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG = 0x20050016ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC = 0;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC_LEN = 3;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT = 36;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN = 2;
// eq/reg00007.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_DATA0 = 0x20050039ull;
// eq/reg00007.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_MODE_REG = 0x20050030ull;

static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE = 0;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_DISABLE_SKITTER_STICKINESS = 1;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL = 4;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL = 6;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS = 8;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE_WITH_TRIGGER = 44;
static const uint32_t EPS_THERM_WSUB2_SKITTER_MODE_REG_SKITTER_DATA_V_LT = 45;
// eq/reg00007.H

static const uint64_t HANG_PULSE_0_REG = 0x200f0020ull;

static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0 = 0;
static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN = 6;
static const uint32_t HANG_PULSE_0_REG_SUPPRESS_HANG_0 = 6;
// eq/reg00007.H

static const uint64_t HANG_PULSE_1_REG = 0x200f0021ull;

static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1 = 0;
static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN = 6;
static const uint32_t HANG_PULSE_1_REG_SUPPRESS_HANG_1 = 6;
// eq/reg00007.H

static const uint64_t HANG_PULSE_2_REG = 0x200f0022ull;

static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2 = 0;
static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN = 6;
static const uint32_t HANG_PULSE_2_REG_SUPPRESS_HANG_2 = 6;
// eq/reg00007.H

static const uint64_t HANG_PULSE_3_REG = 0x200f0023ull;

static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3 = 0;
static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN = 6;
static const uint32_t HANG_PULSE_3_REG_SUPPRESS_HANG_3 = 6;
// eq/reg00007.H

static const uint64_t HANG_PULSE_4_REG = 0x200f0024ull;

static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4 = 0;
static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN = 6;
static const uint32_t HANG_PULSE_4_REG_SUPPRESS_HANG_4 = 6;
// eq/reg00007.H

static const uint64_t HANG_PULSE_5_REG = 0x200f0025ull;

static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5 = 0;
static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN = 6;
static const uint32_t HANG_PULSE_5_REG_SUPPRESS_HANG_5 = 6;
// eq/reg00007.H

static const uint64_t HANG_PULSE_6_REG = 0x200f0026ull;

static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6 = 0;
static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN = 6;
static const uint32_t HANG_PULSE_6_REG_SUPPRESS_HANG_6 = 6;
// eq/reg00007.H

static const uint64_t HOSTATTN_INTERRUPT_REG = 0x200f002bull;

static const uint32_t HOSTATTN_INTERRUPT_REG_TYPE4 = 0;
// eq/reg00007.H

static const uint64_t L3TRA0_TR1_TRACE_LO_DATA_REG = 0x20018221ull;

static const uint32_t L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// eq/reg00007.H

static const uint64_t L3TRA0_TR1_CONFIG_3 = 0x20018226ull;

static const uint32_t L3TRA0_TR1_CONFIG_3_C = 0;
static const uint32_t L3TRA0_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA0_TR1_CONFIG_3_D = 24;
static const uint32_t L3TRA0_TR1_CONFIG_3_D_LEN = 24;
// eq/reg00007.H

static const uint64_t L3TRA1_TR0_CONFIG_5 = 0x20018248ull;

static const uint32_t L3TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t L3TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t L3TRA1_TR0_CONFIG_5_D_LEN = 24;
// eq/reg00007.H

static const uint64_t L3TRA2_TR0_CONFIG_2 = 0x20018285ull;

static const uint32_t L3TRA2_TR0_CONFIG_2_A = 0;
static const uint32_t L3TRA2_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA2_TR0_CONFIG_2_B = 24;
static const uint32_t L3TRA2_TR0_CONFIG_2_B_LEN = 24;
// eq/reg00007.H

static const uint64_t L3TRA3_TR0_TRACE_HI_DATA_REG = 0x200182c0ull;

static const uint32_t L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// eq/reg00007.H

static const uint64_t L3TRA3_TR1_CONFIG_4 = 0x200182e7ull;

static const uint32_t L3TRA3_TR1_CONFIG_4_A = 0;
static const uint32_t L3TRA3_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA3_TR1_CONFIG_4_B = 24;
static const uint32_t L3TRA3_TR1_CONFIG_4_B_LEN = 24;
// eq/reg00007.H

static const uint64_t OPCG_CAPT2 = 0x20030011ull;

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
// eq/reg00007.H

static const uint64_t QMETRA0_TR0_CONFIG_3 = 0x20018406ull;

static const uint32_t QMETRA0_TR0_CONFIG_3_C = 0;
static const uint32_t QMETRA0_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t QMETRA0_TR0_CONFIG_3_D = 24;
static const uint32_t QMETRA0_TR0_CONFIG_3_D_LEN = 24;
// eq/reg00007.H

static const uint64_t QME_ERR = 0x200e0010ull;

static const uint32_t QME_ERR_PPE_INTERNAL_ERROR = 0;
static const uint32_t QME_ERR_PPE_EXTERNAL_ERROR = 1;
static const uint32_t QME_ERR_PPE_PROGRESS_ERROR = 2;
static const uint32_t QME_ERR_PPE_BREAKPOINT_ERROR = 3;
static const uint32_t QME_ERR_RESCLK_FREEZE = 4;
static const uint32_t QME_ERR_RESCLK_FREEZE_LEN = 4;
static const uint32_t QME_ERR_SPECIAL_WKUP_PROTOCOL_ERR = 8;
static const uint32_t QME_ERR_SPECIAL_WKUP_PROTOCOL_ERR_LEN = 4;
static const uint32_t QME_ERR_SPECIAL_WKUP_DONE_WINDOW = 12;
static const uint32_t QME_ERR_SPECIAL_WKUP_DONE_WINDOW_LEN = 4;
static const uint32_t QME_ERR_DISABLED_INTR = 16;
static const uint32_t QME_ERR_DISABLED_INTR_LEN = 4;
static const uint32_t QME_ERR_DECONFIGURED_INTR = 20;
static const uint32_t QME_ERR_DECONFIGURED_INTR_LEN = 4;
static const uint32_t QME_ERR_CTFS_ERR = 24;
static const uint32_t QME_ERR_CTFS_ERR_LEN = 4;
static const uint32_t QME_ERR_CPMS_ERR = 28;
static const uint32_t QME_ERR_CPMS_ERR_LEN = 4;
static const uint32_t QME_ERR_PCB_ENDPOINT_RESET = 32;
static const uint32_t QME_ERR_PCB_NETWORK_RESET = 33;
static const uint32_t QME_ERR_PIG_PENDING_SOURCE_LOST = 34;
static const uint32_t QME_ERR_PIG_PENDING_SOURCE_LOST_LEN = 6;
static const uint32_t QME_ERR_SPARE = 40;
static const uint32_t QME_ERR_SPARE_LEN = 4;
static const uint32_t QME_ERR_LOCAL_ACCESS_PROTECT_ERR = 44;
static const uint32_t QME_ERR_LOCAL_ACCESS_REGION_ERR = 45;
static const uint32_t QME_ERR_LOCAL_ACCESS_PARTIAL_ERR = 46;
// eq/reg00007.H

static const uint64_t QME_QHTTRIG = 0x200e01b0ull;

static const uint32_t QME_QHTTRIG_START = 0;
static const uint32_t QME_QHTTRIG_STOP = 1;
static const uint32_t QME_QHTTRIG_PAUSE = 2;
// eq/reg00007.H

static const uint64_t QME_QMCR = 0x200e0088ull;
static const uint64_t QME_QMCR_SCOM2 = 0x200e008aull;
static const uint64_t QME_QMCR_WO_CLEAR = 0x200e008bull;

static const uint32_t QME_QMCR_PMCR_OVERRIDE_EN = 0;
static const uint32_t QME_QMCR_PSCR_OVERRIDE_EN = 1;
static const uint32_t QME_QMCR_CHAR_REGS_READ_ENABLE = 2;
static const uint32_t QME_QMCR_BCECSR_OVERRIDE_EN = 3;
static const uint32_t QME_QMCR_PSREQ_SCOM_READ_EN = 4;
static const uint32_t QME_QMCR_LOCK_QUEUE_ON_PCB_ERR = 5;
static const uint32_t QME_QMCR_STOP_OVERRIDE_MODE = 6;
static const uint32_t QME_QMCR_STOP_ACTIVE_MASK = 7;
static const uint32_t QME_QMCR_AUTO_PMCR_UPDATE = 8;
static const uint32_t QME_QMCR_PMCR_RECENT_MODE = 9;
static const uint32_t QME_QMCR_FUSED_CORE_PAIR_MODE = 10;
static const uint32_t QME_QMCR_CYCLE_REPRO_MODE = 11;
static const uint32_t QME_QMCR_QUEUED_WR_EN = 12;
static const uint32_t QME_QMCR_QUEUED_RD_EN = 13;
static const uint32_t QME_QMCR_RESET_IMPRECISE_QERR = 14;
static const uint32_t QME_QMCR_RESET_PB_RAMP = 15;
static const uint32_t QME_QMCR_LOPRI_STOP_WKUP_SEL = 16;
static const uint32_t QME_QMCR_LOPRI_STOP_WKUP_SEL_LEN = 4;
static const uint32_t QME_QMCR_LOPRI_STOP_ENTRY_SEL = 20;
static const uint32_t QME_QMCR_LOPRI_STOP_ENTRY_SEL_LEN = 4;
static const uint32_t QME_QMCR_WRITE_PROTECT_ENABLE = 24;
static const uint32_t QME_QMCR_TTSR_READ_ENABLE = 25;
static const uint32_t QME_QMCR_PTSR_READ_ENABLE = 26;
static const uint32_t QME_QMCR_RESET_QME_PCB_MASTER_INTERFACE = 27;
static const uint32_t QME_QMCR_OCP_REQUEST_ENABLE = 28;
static const uint32_t QME_QMCR_STOP_SHIFTREG_OVERRIDE_EN = 29;
static const uint32_t QME_QMCR_CPMS_PG_CLKOFF_DISABLE = 30;
static const uint32_t QME_QMCR_CTFS_PG_CLKOFF_DISABLE = 31;
static const uint32_t QME_QMCR_DTC_SEQUENCER_ENABLE = 32;
static const uint32_t QME_QMCR_WOF_AUTO_SEQ_ENABLE = 33;
static const uint32_t QME_QMCR_QOS_AUTO_SEQ_ENABLE = 34;
static const uint32_t QME_QMCR_QOSR_SPR_UPDATE_ENABLE = 35;
static const uint32_t QME_QMCR_SPARE2 = 36;
static const uint32_t QME_QMCR_SPARE2_LEN = 4;
static const uint32_t QME_QMCR_FUSED_CORE_MODE = 47;
static const uint32_t QME_QMCR_CORE_PARTIAL_GOOD = 60;
static const uint32_t QME_QMCR_CORE_PARTIAL_GOOD_LEN = 4;
// eq/reg00007.H

static const uint64_t QME_SCOM_XIDBGINF = 0x200e023cull;

static const uint32_t QME_SCOM_XIDBGINF_SRR0_TOP = 0;
static const uint32_t QME_SCOM_XIDBGINF_SRR0_TOP_LEN = 30;
static const uint32_t QME_SCOM_XIDBGINF_LR = 32;
static const uint32_t QME_SCOM_XIDBGINF_LR_LEN = 32;
// eq/reg00007.H

static const uint64_t QME_SWPR1 = 0x200e0094ull;

static const uint32_t QME_SWPR1_BAR = 0;
static const uint32_t QME_SWPR1_BAR_LEN = 27;
static const uint32_t QME_SWPR1_SIZE = 44;
static const uint32_t QME_SWPR1_SIZE_LEN = 15;
// eq/reg00007.H

static const uint64_t RECOV_UNMASKED = 0x20040011ull;

static const uint32_t RECOV_UNMASKED_IN = 1;
static const uint32_t RECOV_UNMASKED_IN_LEN = 53;
// eq/reg00007.H

static const uint64_t SCAN_UPDATEDR = 0x2003a000ull;

static const uint32_t SCAN_UPDATEDR_SCAN_UPDATEDR_REG = 0;
static const uint32_t SCAN_UPDATEDR_SCAN_UPDATEDR_REG_LEN = 32;
// eq/reg00007.H

static const uint64_t SPATTN_UNMASKED = 0x20040012ull;

static const uint32_t SPATTN_UNMASKED_IN = 1;
static const uint32_t SPATTN_UNMASKED_IN_LEN = 35;
// eq/reg00007.H

static const uint64_t SYNC_CONFIG = 0x20030000ull;

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
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN = 15;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE = 16;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN = 8;
// eq/reg00007.H

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00007.H"
#endif
#endif
