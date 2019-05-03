/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_e.H $       */
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

#ifndef __p10_scom_perv_e_H_
#define __p10_scom_perv_e_H_


namespace scomt
{
namespace perv
{


static const uint64_t COMP_P_0_RSIS = 0x0003000aull;
// perv/reg00019.H

static const uint64_t DPLL_CNTL_NEST_REGS_ICHAR = 0x00000157ull;

static const uint32_t DPLL_CNTL_NEST_REGS_ICHAR_FREQIN_AVG = 1;
static const uint32_t DPLL_CNTL_NEST_REGS_ICHAR_FREQIN_AVG_LEN = 11;
static const uint32_t DPLL_CNTL_NEST_REGS_ICHAR_HIRES_FREQIN_AVG = 12;
static const uint32_t DPLL_CNTL_NEST_REGS_ICHAR_HIRES_FREQIN_AVG_LEN = 5;
static const uint32_t DPLL_CNTL_NEST_REGS_ICHAR_FREQIN_MAX = 21;
static const uint32_t DPLL_CNTL_NEST_REGS_ICHAR_FREQIN_MAX_LEN = 11;
static const uint32_t DPLL_CNTL_NEST_REGS_ICHAR_HIRES_FREQIN_MAX = 32;
static const uint32_t DPLL_CNTL_NEST_REGS_ICHAR_HIRES_FREQIN_MAX_LEN = 5;
static const uint32_t DPLL_CNTL_NEST_REGS_ICHAR_FREQIN_MIN = 41;
static const uint32_t DPLL_CNTL_NEST_REGS_ICHAR_FREQIN_MIN_LEN = 11;
static const uint32_t DPLL_CNTL_NEST_REGS_ICHAR_HIRES_FREQIN_MIN = 52;
static const uint32_t DPLL_CNTL_NEST_REGS_ICHAR_HIRES_FREQIN_MIN_LEN = 5;
// perv/reg00019.H

static const uint64_t DPLL_CNTL_NEST_REGS_OCHAR = 0x00000156ull;

static const uint32_t DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX = 1;
static const uint32_t DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MAX_LEN = 11;
static const uint32_t DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX = 12;
static const uint32_t DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MAX_LEN = 5;
static const uint32_t DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG = 21;
static const uint32_t DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_AVG_LEN = 11;
static const uint32_t DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG = 32;
static const uint32_t DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_AVG_LEN = 5;
static const uint32_t DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN = 41;
static const uint32_t DPLL_CNTL_NEST_REGS_OCHAR_FREQOUT_MIN_LEN = 11;
static const uint32_t DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN = 52;
static const uint32_t DPLL_CNTL_NEST_REGS_OCHAR_HIRES_FREQOUT_MIN_LEN = 5;
// perv/reg00019.H

static const uint64_t EPS_DBG_TRACE_REG_1 = 0x000107ceull;

static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO = 0;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO = 4;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO = 6;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO = 8;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO = 10;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_DO_LEN = 2;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_WAITN = 24;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_WAITN = 25;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_WAITN = 26;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_WAITN = 27;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_WAITN = 28;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_WAITN = 29;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION1_ACTION_BANK = 36;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CONDITION2_ACTION_BANK = 37;
static const uint32_t EPS_DBG_TRACE_REG_1_1_C2_TIMEOUT_ACTION_BANK = 38;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION1_ACTION_BANK = 39;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CONDITION2_ACTION_BANK = 40;
static const uint32_t EPS_DBG_TRACE_REG_1_2_C2_TIMEOUT_ACTION_BANK = 41;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT = 48;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t EPS_DBG_TRACE_REG_1_1_CHECKSTOP_MODE_SELECTOR = 51;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT = 52;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_LT_LEN = 3;
static const uint32_t EPS_DBG_TRACE_REG_1_2_CHECKSTOP_MODE_SELECTOR = 55;
// perv/reg00019.H

static const uint64_t EPS_FIR_LOCAL_ACTION1 = 0x00040011ull;

static const uint32_t EPS_FIR_LOCAL_ACTION1_00 = 0;
static const uint32_t EPS_FIR_LOCAL_ACTION1_01 = 1;
static const uint32_t EPS_FIR_LOCAL_ACTION1_02 = 2;
static const uint32_t EPS_FIR_LOCAL_ACTION1_03 = 3;
static const uint32_t EPS_FIR_LOCAL_ACTION1_04 = 4;
static const uint32_t EPS_FIR_LOCAL_ACTION1_05 = 5;
static const uint32_t EPS_FIR_LOCAL_ACTION1_06 = 6;
static const uint32_t EPS_FIR_LOCAL_ACTION1_07 = 7;
static const uint32_t EPS_FIR_LOCAL_ACTION1_08 = 8;
static const uint32_t EPS_FIR_LOCAL_ACTION1_09 = 9;
static const uint32_t EPS_FIR_LOCAL_ACTION1_10 = 10;
static const uint32_t EPS_FIR_LOCAL_ACTION1_11 = 11;
static const uint32_t EPS_FIR_LOCAL_ACTION1_12 = 12;
static const uint32_t EPS_FIR_LOCAL_ACTION1_13 = 13;
static const uint32_t EPS_FIR_LOCAL_ACTION1_14 = 14;
static const uint32_t EPS_FIR_LOCAL_ACTION1_15 = 15;
static const uint32_t EPS_FIR_LOCAL_ACTION1_16 = 16;
static const uint32_t EPS_FIR_LOCAL_ACTION1_17 = 17;
static const uint32_t EPS_FIR_LOCAL_ACTION1_18 = 18;
static const uint32_t EPS_FIR_LOCAL_ACTION1_19 = 19;
static const uint32_t EPS_FIR_LOCAL_ACTION1_20 = 20;
static const uint32_t EPS_FIR_LOCAL_ACTION1_21 = 21;
static const uint32_t EPS_FIR_LOCAL_ACTION1_22 = 22;
static const uint32_t EPS_FIR_LOCAL_ACTION1_23 = 23;
static const uint32_t EPS_FIR_LOCAL_ACTION1_24 = 24;
static const uint32_t EPS_FIR_LOCAL_ACTION1_25 = 25;
static const uint32_t EPS_FIR_LOCAL_ACTION1_26 = 26;
static const uint32_t EPS_FIR_LOCAL_ACTION1_27 = 27;
static const uint32_t EPS_FIR_LOCAL_ACTION1_28 = 28;
static const uint32_t EPS_FIR_LOCAL_ACTION1_29 = 29;
static const uint32_t EPS_FIR_LOCAL_ACTION1_30 = 30;
static const uint32_t EPS_FIR_LOCAL_ACTION1_31 = 31;
static const uint32_t EPS_FIR_LOCAL_ACTION1_32 = 32;
static const uint32_t EPS_FIR_LOCAL_ACTION1_33 = 33;
static const uint32_t EPS_FIR_LOCAL_ACTION1_34 = 34;
static const uint32_t EPS_FIR_LOCAL_ACTION1_35 = 35;
static const uint32_t EPS_FIR_LOCAL_ACTION1_36 = 36;
static const uint32_t EPS_FIR_LOCAL_ACTION1_37 = 37;
static const uint32_t EPS_FIR_LOCAL_ACTION1_38 = 38;
static const uint32_t EPS_FIR_LOCAL_ACTION1_39 = 39;
static const uint32_t EPS_FIR_LOCAL_ACTION1_40 = 40;
static const uint32_t EPS_FIR_LOCAL_ACTION1_41 = 41;
static const uint32_t EPS_FIR_LOCAL_ACTION1_42 = 42;
static const uint32_t EPS_FIR_LOCAL_ACTION1_43 = 43;
static const uint32_t EPS_FIR_LOCAL_ACTION1_44 = 44;
static const uint32_t EPS_FIR_LOCAL_ACTION1_45 = 45;
static const uint32_t EPS_FIR_LOCAL_ACTION1_46 = 46;
static const uint32_t EPS_FIR_LOCAL_ACTION1_47 = 47;
static const uint32_t EPS_FIR_LOCAL_ACTION1_48 = 48;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_GPWRP_RWX = 0x0000281full;

static const uint32_t FSXCOMP_FSXLOG_GPWRP_MAGIC_COOKIE = 0;
static const uint32_t FSXCOMP_FSXLOG_GPWRP_MAGIC_COOKIE_LEN = 16;
static const uint32_t FSXCOMP_FSXLOG_GPWRP_EN_OR_DIS_WRITE_PROTECTION = 16;
static const uint32_t FSXCOMP_FSXLOG_GPWRP_EN_OR_DIS_WRITE_PROTECTION_LEN = 16;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_10_RWX = 0x0000284aull;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_7_RWX = 0x00002847ull;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_14_RWX = 0x000028ceull;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_1_RWX = 0x00002901ull;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_WO_CLEAR = 0x0000293aull;

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_CHIPLET_EN_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_PCB_EP_RESET_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_CLK_ASYNC_RESET_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_3_RESERVED = 3;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_4_RESERVED = 4;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_5_RESERVED = 5;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_6_RESERVED = 6;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_SCIN_DC = 7;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_8_RESERVED = 8;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_FLUSH_ALIGN_OVERWRITE = 9;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_10_RESERVED = 10;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_EDIS_DC = 11;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_MPW1_DC_N = 12;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_MPW2_DC_N = 13;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_MPW3_DC_N = 14;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_DELAY_LCLKR_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_VITL_CLKOFF_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_17_RESERVED = 17;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_FENCE_EN_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_RI_DC_N = 19;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_DI1_DC_N = 20;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_DI2_DC_N = 21;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_22_RESERVED = 22;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_OTP_SCOM_FUSED_CORE_MODE = 23;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_24_RESERVED = 24;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_FENCE_PCB_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_26_RESERVED = 26;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_TP_ARRAY_WRITE_ASSIST_EN_DC = 27;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_28_RESERVED = 28;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_29_RESERVED = 29;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_30_RESERVED = 30;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_PERV_CTRL0_31_SPARE = 31;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_RW = 0x00002812ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_0_SPARE = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_3_SPARE = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_DISABLE_PARITY_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_TRACE_MODE_DATA_DC = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TP_PIB_VSB_SBE_TRACE_MODE = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TP_TPCPERV_VSB_TRACE_STOP = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TP_GPIO_PIB_TIMEOUT_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_SPARE_PIB_CONTROL = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TPCFSI_OPB_SW_RESET_DC = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_13_SPARE_OPB_CONTROL = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_14_SPARE_OPB_CONTROL = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_15_SPARE_OPB_CONTROL = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_16_SPARE = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TP_VREGDLY_SHUTOFF_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_18_SPARE = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_19_SPARE = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TPFSI_TC_HSSPORWREN_ALLOW = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_21_FREE_USAGE = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_22_FREE_USAGE = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_23_FREE_USAGE = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TP_IO_VSB_OP0A_V1P8_EN = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TP_IO_VSB_OP0B_V1P8_EN = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_26_FREE_USAGE = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_27_FREE_USAGE = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_28_FREE_USAGE = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_ROOT_CTRL2_29_FREE_USAGE = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TP_IO_VSB_OP3A_V1P8_EN = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_TP_IO_VSB_OP3B_V1P8_EN = 31;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_WO_CLEAR = 0x00002932ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_0_SPARE = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TPFSI_TP_DBG_PCB_DATA_PAR_DIS_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TPFSI_TP_DBG_PCB_TYPE_PAR_DIS_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_3_SPARE = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_PIB_DISABLE_PARITY_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_PIB_TRACE_MODE_DATA_DC = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_PIB_VSB_SBE_TRACE_MODE = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_TPCPERV_VSB_TRACE_STOP = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_GPIO_PIB_TIMEOUT = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_GPIO_PIB_TIMEOUT_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_SPARE_PIB_CONTROL = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TPCFSI_OPB_SW_RESET_DC = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_13_SPARE_OPB_CONTROL = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_14_SPARE_OPB_CONTROL = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_15_SPARE_OPB_CONTROL = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_16_SPARE = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_VREGDLY_SHUTOFF_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_18_SPARE = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_19_SPARE = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TPFSI_TC_HSSPORWREN_ALLOW = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_21_FREE_USAGE = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_22_FREE_USAGE = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_23_FREE_USAGE = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_IO_VSB_OP0A_V1P8_EN = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_IO_VSB_OP0B_V1P8_EN = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_26_FREE_USAGE = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_27_FREE_USAGE = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_28_FREE_USAGE = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_ROOT_CTRL2_29_FREE_USAGE = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_IO_VSB_OP3A_V1P8_EN = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL2_CLEAR_TP_IO_VSB_OP3B_V1P8_EN = 31;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_COPY_RW = 0x00002915ull;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_WO_OR = 0x00002928ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TPFSI_SPIMST0_PORT_MUX_SEL_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TPFSI_SPIMST1_PORT_MUX_SEL_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TPFSI_SPIMST2_PORT_MUX_SEL_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TPFSI_SPIMST3_PORT_MUX_SEL_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_ROOT_CTRL8_4_15 = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_ROOT_CTRL8_4_15_LEN = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TP_FSI_FENCE_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_VITL_FENCE_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_FSI0_FENCE_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_FSI0LL_FENCE_DC = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_FSI0INV_FENCE_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_FSI1_FENCE_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_FSI1LL_FENCE_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_TCFSI_FSIA_FENCE_DC = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_ROOT_CTRL8_24_31 = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL8_SET_ROOT_CTRL8_24_31_LEN = 8;
// perv/reg00019.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_RWX = 0x0000283dull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_SR_SCRATCH_REGISTER_6 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_SR_SCRATCH_REGISTER_6_LEN = 32;
// perv/reg00019.H

static const uint64_t L3TRA0_TR0_CONFIG = 0x00018202ull;

static const uint32_t L3TRA0_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA0_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA0_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA0_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA0_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA0_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA0_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA0_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// perv/reg00019.H

static const uint64_t L3TRA1_TR0_TRACE_HI_DATA_REG = 0x00018240ull;

static const uint32_t L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00019.H

static const uint64_t L3TRA1_TR0_CONFIG_1 = 0x00018244ull;

static const uint32_t L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00019.H

static const uint64_t L3TRA1_TR1_CONFIG = 0x00018262ull;

static const uint32_t L3TRA1_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L3TRA1_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L3TRA1_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L3TRA1_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t L3TRA1_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L3TRA1_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L3TRA1_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L3TRA1_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// perv/reg00019.H

static const uint64_t L3TRA2_TR1_TRACE_LO_DATA_REG = 0x000182a1ull;

static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA2_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00019.H

static const uint64_t L3TRA3_TR0_CONFIG_9 = 0x000182c9ull;

static const uint32_t L3TRA3_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA3_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA3_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA3_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA3_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA3_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA3_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00019.H

static const uint64_t L3TRA3_TR1_CONFIG_0 = 0x000182e3ull;

static const uint32_t L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00019.H

static const uint64_t OPCG_REG1 = 0x00030003ull;

static const uint32_t OPCG_REG1_SCAN_COUNT = 0;
static const uint32_t OPCG_REG1_SCAN_COUNT_LEN = 12;
static const uint32_t OPCG_REG1_MISR_A_VAL = 12;
static const uint32_t OPCG_REG1_MISR_A_VAL_LEN = 12;
static const uint32_t OPCG_REG1_MISR_B_VAL = 24;
static const uint32_t OPCG_REG1_MISR_B_VAL_LEN = 12;
static const uint32_t OPCG_REG1_MISR_INIT_WAIT = 36;
static const uint32_t OPCG_REG1_MISR_INIT_WAIT_LEN = 12;
static const uint32_t OPCG_REG1_SCAN_CLK_USE_EVEN = 49;
static const uint32_t OPCG_REG1_RTIM_THOLD_FORCE = 52;
static const uint32_t OPCG_REG1_DISABLE_ARY_CLK_DURING_FILL = 53;
static const uint32_t OPCG_REG1_SG_HIGH_DURING_FILL = 54;
static const uint32_t OPCG_REG1_LBIST_SKITTER_CTL = 55;
static const uint32_t OPCG_REG1_LBIST_SKITTER_CTL_LEN = 2;
static const uint32_t OPCG_REG1_MISR_MODE = 57;
static const uint32_t OPCG_REG1_INFINITE_MODE = 58;
static const uint32_t OPCG_REG1_NSL_FILL_COUNT = 59;
static const uint32_t OPCG_REG1_NSL_FILL_COUNT_LEN = 5;
// perv/reg00019.H

static const uint64_t OTPC_M_MEASURE_REG7 = 0x00010017ull;

static const uint32_t OTPC_M_MEASURE_REG7_SEEPROM_MEASUREMENT7_DATA = 0;
static const uint32_t OTPC_M_MEASURE_REG7_SEEPROM_MEASUREMENT7_DATA_LEN = 64;
// perv/reg00019.H

static const uint64_t OTPC_M_MODE_REGISTER = 0x00010008ull;

static const uint32_t OTPC_M_MODE_REGISTER_DCOMP_ENABLE = 0;
static const uint32_t OTPC_M_MODE_REGISTER_ECC_ENABLE = 1;
static const uint32_t OTPC_M_MODE_REGISTER_ECC_CHK_DISABLE = 3;
// perv/reg00019.H

static const uint64_t REC_ERR_MST1_REG3 = 0x000f0047ull;

static const uint32_t REC_ERR_MST1_REG3_48_MST1_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST1_REG3_48_MST1_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST1_REG3_48_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_49_MST1_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST1_REG3_49_MST1_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST1_REG3_49_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_50_MST1_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST1_REG3_50_MST1_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST1_REG3_50_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_51_MST1_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST1_REG3_51_MST1_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST1_REG3_51_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_52_MST1_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST1_REG3_52_MST1_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST1_REG3_52_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_53_MST1_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST1_REG3_53_MST1_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST1_REG3_53_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_54_MST1_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST1_REG3_54_MST1_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST1_REG3_54_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_55_MST1_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST1_REG3_55_MST1_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST1_REG3_55_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_56_MST1_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST1_REG3_56_MST1_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST1_REG3_56_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_57_MST1_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST1_REG3_57_MST1_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST1_REG3_57_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_58_MST1_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST1_REG3_58_MST1_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST1_REG3_58_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_59_MST1_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST1_REG3_59_MST1_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST1_REG3_59_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_60_MST1_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST1_REG3_60_MST1_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST1_REG3_60_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_61_MST1_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST1_REG3_61_MST1_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST1_REG3_61_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_62_MST1_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST1_REG3_62_MST1_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST1_REG3_62_MST1_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST1_REG3_63_MST1_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST1_REG3_63_MST1_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST1_REG3_63_MST1_ERROR_CODE_LEN = 3;
// perv/reg00019.H

static const uint64_t REC_ERR_MST5_REG2 = 0x000f0056ull;

static const uint32_t REC_ERR_MST5_REG2_32_MST5_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST5_REG2_32_MST5_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST5_REG2_32_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_33_MST5_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST5_REG2_33_MST5_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST5_REG2_33_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_34_MST5_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST5_REG2_34_MST5_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST5_REG2_34_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_35_MST5_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST5_REG2_35_MST5_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST5_REG2_35_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_36_MST5_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST5_REG2_36_MST5_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST5_REG2_36_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_37_MST5_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST5_REG2_37_MST5_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST5_REG2_37_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_38_MST5_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST5_REG2_38_MST5_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST5_REG2_38_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_39_MST5_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST5_REG2_39_MST5_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST5_REG2_39_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_40_MST5_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST5_REG2_40_MST5_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST5_REG2_40_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_41_MST5_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST5_REG2_41_MST5_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST5_REG2_41_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_42_MST5_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST5_REG2_42_MST5_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST5_REG2_42_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_43_MST5_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST5_REG2_43_MST5_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST5_REG2_43_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_44_MST5_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST5_REG2_44_MST5_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST5_REG2_44_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_45_MST5_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST5_REG2_45_MST5_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST5_REG2_45_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_46_MST5_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST5_REG2_46_MST5_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST5_REG2_46_MST5_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST5_REG2_47_MST5_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST5_REG2_47_MST5_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST5_REG2_47_MST5_ERROR_CODE_LEN = 3;
// perv/reg00019.H

static const uint64_t REC_ERR_REG1 = 0x000f0012ull;

static const uint32_t REC_ERR_REG1_16_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_REG1_16_ERROR_CODE = 1;
static const uint32_t REC_ERR_REG1_16_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_17_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_REG1_17_ERROR_CODE = 5;
static const uint32_t REC_ERR_REG1_17_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_18_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_REG1_18_ERROR_CODE = 9;
static const uint32_t REC_ERR_REG1_18_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_19_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_REG1_19_ERROR_CODE = 13;
static const uint32_t REC_ERR_REG1_19_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_20_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_REG1_20_ERROR_CODE = 17;
static const uint32_t REC_ERR_REG1_20_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_21_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_REG1_21_ERROR_CODE = 21;
static const uint32_t REC_ERR_REG1_21_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_22_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_REG1_22_ERROR_CODE = 25;
static const uint32_t REC_ERR_REG1_22_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_23_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_REG1_23_ERROR_CODE = 29;
static const uint32_t REC_ERR_REG1_23_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_24_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_REG1_24_ERROR_CODE = 33;
static const uint32_t REC_ERR_REG1_24_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_25_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_REG1_25_ERROR_CODE = 37;
static const uint32_t REC_ERR_REG1_25_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_26_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_REG1_26_ERROR_CODE = 41;
static const uint32_t REC_ERR_REG1_26_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_27_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_REG1_27_ERROR_CODE = 45;
static const uint32_t REC_ERR_REG1_27_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_28_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_REG1_28_ERROR_CODE = 49;
static const uint32_t REC_ERR_REG1_28_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_29_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_REG1_29_ERROR_CODE = 53;
static const uint32_t REC_ERR_REG1_29_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_30_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_REG1_30_ERROR_CODE = 57;
static const uint32_t REC_ERR_REG1_30_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_REG1_31_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_REG1_31_ERROR_CODE = 61;
static const uint32_t REC_ERR_REG1_31_ERROR_CODE_LEN = 3;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG105 = 0x00008069ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG105_REGISTER105 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG105_REGISTER105_LEN = 64;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG14 = 0x0000800eull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG14_REGISTER14 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG14_REGISTER14_LEN = 64;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG23 = 0x00008017ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG23_REGISTER23 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG23_REGISTER23_LEN = 64;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG4 = 0x00008004ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG4_REGISTER4 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG4_REGISTER4_LEN = 64;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG42 = 0x0000802aull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG42_REGISTER42 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG42_REGISTER42_LEN = 64;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG75 = 0x0000804bull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG75_REGISTER75 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG75_REGISTER75_LEN = 64;
// perv/reg00019.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG80 = 0x00008050ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG80_REGISTER80 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG80_REGISTER80_LEN = 64;
// perv/reg00019.H

static const uint64_t SLAVE_CONFIG_REG = 0x000f001eull;

static const uint32_t SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK = 0;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN = 1;
static const uint32_t SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP = 2;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK = 3;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_HEARTBEAT = 4;
static const uint32_t SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO = 5;
static const uint32_t SLAVE_CONFIG_REG_PM_DISABLE = 6;
static const uint32_t SLAVE_CONFIG_REG_PM_MUX_DISABLE = 7;
static const uint32_t SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS = 8;
static const uint32_t SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS = 9;
static const uint32_t SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS = 10;
static const uint32_t SLAVE_CONFIG_REG_MASK_PCBSL_ERRS = 11;
static const uint32_t SLAVE_CONFIG_REG_MASK_PLL_ERRS = 12;
static const uint32_t SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN = 8;
// perv/reg00019.H

static const uint64_t TOD_LOW_ORDER_STEP_REG = 0x00040023ull;

static const uint32_t TOD_LOW_ORDER_STEP_REG_LOW_ORDER_STEP_COUNTER_VALUE = 0;
static const uint32_t TOD_LOW_ORDER_STEP_REG_LOW_ORDER_STEP_COUNTER_VALUE_LEN = 6;
static const uint32_t TOD_LOW_ORDER_STEP_REG_REG_0X23_SPARE_06_07 = 6;
static const uint32_t TOD_LOW_ORDER_STEP_REG_REG_0X23_SPARE_06_07_LEN = 2;
// perv/reg00019.H

static const uint64_t TOD_SEC_PORT_1_CTRL_REG = 0x00040004ull;

static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT = 0;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_PORT_1_RX_SELECT_LEN = 3;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_03 = 3;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT = 4;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT = 6;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT = 8;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT = 10;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT = 12;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT = 14;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT = 16;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT = 18;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_SELECT_LEN = 2;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X0_PORT_1_TX_ENABLE = 20;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X1_PORT_1_TX_ENABLE = 21;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X2_PORT_1_TX_ENABLE = 22;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X3_PORT_1_TX_ENABLE = 23;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X4_PORT_1_TX_ENABLE = 24;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X5_PORT_1_TX_ENABLE = 25;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X6_PORT_1_TX_ENABLE = 26;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_SEC_X7_PORT_1_TX_ENABLE = 27;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31 = 28;
static const uint32_t TOD_SEC_PORT_1_CTRL_REG_REG_0X04_SPARE_28_31_LEN = 4;
// perv/reg00019.H

static const uint64_t TOD_S_PATH_CTRL_REG = 0x00040005ull;

static const uint32_t TOD_S_PATH_CTRL_REG_PRI_S_PATH_SELECT = 0;
static const uint32_t TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_01 = 1;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_M_CPS_ENABLE = 2;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_DISABLE = 3;
static const uint32_t TOD_S_PATH_CTRL_REG_SEC_S_PATH_SELECT = 4;
static const uint32_t TOD_S_PATH_CTRL_REG_REG_0X05_SPARE_05 = 5;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR = 6;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_STEP_CHECK_CPS_DEVIATION_FACTOR_LEN = 2;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION = 8;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CPS_DEVIATION_LEN = 4;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_CONSTANT_CPS_ENABLE = 12;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT = 13;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_0_STEP_CHECK_VALIDITY_COUNT_LEN = 3;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION = 16;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CPS_DEVIATION_LEN = 4;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_CONSTANT_CPS_ENABLE = 20;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT = 21;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_1_STEP_CHECK_VALIDITY_COUNT_LEN = 3;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_ERROR_DISABLE = 24;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_M_CPS_DISABLE = 25;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR = 26;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_FACTOR_LEN = 2;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION = 28;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_CHECK_CPS_DEVIATION_LEN = 4;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX = 32;
static const uint32_t TOD_S_PATH_CTRL_REG_S_PATH_REMOTE_SYNC_MISS_COUNT_MAX_LEN = 8;
// perv/reg00019.H

static const uint64_t TOD_TX_TTYPE_CTRL_REG = 0x00040027ull;

static const uint32_t TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS = 0;
static const uint32_t TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_LEN = 24;
static const uint32_t TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID = 24;
static const uint32_t TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ID_LEN = 8;
static const uint32_t TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_MODE = 32;
static const uint32_t TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_4_SEND_ENABLE = 33;
static const uint32_t TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_34 = 34;
static const uint32_t TOD_TX_TTYPE_CTRL_REG_MOVE_TOD_TO_TB_CORE_ADDRESS_ENABLE = 35;
static const uint32_t TOD_TX_TTYPE_CTRL_REG_REG_0X27_SPARE_36 = 36;
static const uint32_t TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE = 37;
static const uint32_t TOD_TX_TTYPE_CTRL_REG_TX_TTYPE_PIB_FSM_STATE_LEN = 3;
// perv/reg00019.H

static const uint64_t TRA1_TR0_CONFIG_1 = 0x00010484ull;

static const uint32_t TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00019.H

static const uint64_t TRA3_TR0_CONFIG_9 = 0x00010589ull;

static const uint32_t TRA3_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA3_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA3_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA3_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA3_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA3_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA3_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA3_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA3_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA3_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA3_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA3_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA3_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA3_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA3_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA3_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA3_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA3_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA3_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA3_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA3_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA3_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA3_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA3_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA3_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA3_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA3_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00019.H

static const uint64_t TRA3_TR1_CONFIG_0 = 0x000105c3ull;

static const uint32_t TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA3_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00019.H

static const uint64_t TRA4_TR1_CONFIG_1 = 0x00010644ull;

static const uint32_t TRA4_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA4_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00019.H

static const uint64_t TRA5_TR1_TRACE_HI_DATA_REG = 0x000106c0ull;

static const uint32_t TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA5_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00019.H

static const uint64_t TRA6_TR0_TRACE_LO_DATA_REG = 0x00010701ull;

static const uint32_t TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA6_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA6_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA6_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA6_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA6_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA6_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00019.H

static const uint64_t TRA6_TR0_CONFIG = 0x00010702ull;

static const uint32_t TRA6_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA6_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA6_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA6_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA6_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TRA6_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA6_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA6_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA6_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA6_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA6_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA6_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA6_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA6_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// perv/reg00019.H

static const uint64_t TRA6_TR0_CONFIG_0 = 0x00010703ull;

static const uint32_t TRA6_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA6_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00019.H

static const uint64_t TRA6_TR1_CONFIG_9 = 0x00010749ull;

static const uint32_t TRA6_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA6_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA6_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA6_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA6_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA6_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA6_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA6_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA6_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA6_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA6_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA6_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA6_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA6_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA6_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA6_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA6_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA6_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA6_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA6_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA6_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA6_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA6_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA6_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA6_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA6_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA6_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00019.H

static const uint64_t XSTOP2 = 0x0003000dull;

static const uint32_t XSTOP2_XSTOP2_MASK_B = 0;
static const uint32_t XSTOP2_ALIGNED_XSTOP2 = 1;
static const uint32_t XSTOP2_TRIGGER_OPCG_ON_XSTOP2 = 2;
static const uint32_t XSTOP2_XSTOP2_WAIT_ALLWAYS = 3;
static const uint32_t XSTOP2_XSTOP2_PERV = 4;
static const uint32_t XSTOP2_XSTOP2_UNIT1 = 5;
static const uint32_t XSTOP2_XSTOP2_UNIT2 = 6;
static const uint32_t XSTOP2_XSTOP2_UNIT3 = 7;
static const uint32_t XSTOP2_XSTOP2_UNIT4 = 8;
static const uint32_t XSTOP2_XSTOP2_UNIT5 = 9;
static const uint32_t XSTOP2_XSTOP2_UNIT6 = 10;
static const uint32_t XSTOP2_XSTOP2_UNIT7 = 11;
static const uint32_t XSTOP2_XSTOP2_UNIT8 = 12;
static const uint32_t XSTOP2_XSTOP2_UNIT9 = 13;
static const uint32_t XSTOP2_XSTOP2_UNIT10 = 14;
static const uint32_t XSTOP2_XSTOP2_UNIT11 = 15;
static const uint32_t XSTOP2_XSTOP2_UNIT12 = 16;
static const uint32_t XSTOP2_XSTOP2_UNIT13 = 17;
static const uint32_t XSTOP2_XSTOP2_UNIT14 = 18;
static const uint32_t XSTOP2_XSTOP2_WAIT_CYCLES = 48;
static const uint32_t XSTOP2_XSTOP2_WAIT_CYCLES_LEN = 12;
// perv/reg00020.H

}
}
#include "perv/reg00019.H"
#include "perv/reg00020.H"
#endif
