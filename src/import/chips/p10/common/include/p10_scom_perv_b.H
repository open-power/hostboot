/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_b.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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


//>> [ATOMIC_LOCK_REG]
static const uint64_t ATOMIC_LOCK_REG = 0x000f03ffull;

static const uint32_t ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t ATOMIC_LOCK_REG_ID = 1;
static const uint32_t ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
//<< [ATOMIC_LOCK_REG]
// perv/reg00022.H

//>> [ATTN_INTERRUPT_REG]
static const uint64_t ATTN_INTERRUPT_REG = 0x000f001aull;

static const uint32_t ATTN_INTERRUPT_REG_ATTN = 0;
//<< [ATTN_INTERRUPT_REG]
// perv/reg00022.H

//>> [EPS_FIR_LOCAL_MASK]
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
//<< [EPS_FIR_LOCAL_MASK]
// perv/reg00022.H

//>> [EPS_THERM_WSUB2_CONTROL_REG]
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
//<< [EPS_THERM_WSUB2_CONTROL_REG]
// perv/reg00022.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL4]
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
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_AN_NEST_DIV2_ASYNC_RESET_DC = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TPFSI_ALTREFCLK_SEL = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_28_SPARE = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_TP_PLL_FORCE_OUT_EN_DC = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_DPLL_FREEZE_DC = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_ROOT_CTRL4_31_SPARE = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL4]
// perv/reg00022.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL4_COPY]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_COPY_FSI = 0x00002914ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_COPY_FSI_BYTE = 0x00002c50ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_COPY_RW = 0x00050114ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_COPY_ROOT_CTRL4_COPY_REG = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL4_COPY_ROOT_CTRL4_COPY_REG_LEN = 32;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL4_COPY]
// perv/reg00022.H

//>> [LOCAL_FIR]
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
//<< [LOCAL_FIR]
// perv/reg00022.H

//>> [RECOV]
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
//<< [RECOV]
// perv/reg00022.H

//>> [REC_ACK_REG]
static const uint64_t REC_ACK_REG = 0x000f0010ull;

static const uint32_t REC_ACK_REG_RECEIVE_ACKNOWLEDGE_REGISTER = 0;
static const uint32_t REC_ACK_REG_RECEIVE_ACKNOWLEDGE_REGISTER_LEN = 64;
//<< [REC_ACK_REG]
// perv/reg00022.H

//>> [SINGLE_OTP_ROM_OTPROM_REG2]
static const uint64_t SINGLE_OTP_ROM_OTPROM_REG2 = 0x00018002ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG2_REGISTER2 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG2_REGISTER2_LEN = 64;
//<< [SINGLE_OTP_ROM_OTPROM_REG2]
// perv/reg00022.H

//>> [TOD_TX_TTYPE_2_REG]
static const uint64_t TOD_TX_TTYPE_2_REG = 0x00040013ull;

static const uint32_t TOD_TX_TTYPE_2_REG_TX_TTYPE_2_TRIGGER = 0;
//<< [TOD_TX_TTYPE_2_REG]
// perv/reg00023.H

//>> [TOD_TX_TTYPE_4_REG]
static const uint64_t TOD_TX_TTYPE_4_REG = 0x00040015ull;

static const uint32_t TOD_TX_TTYPE_4_REG_TX_TTYPE_4_TRIGGER = 0;
//<< [TOD_TX_TTYPE_4_REG]
// perv/reg00023.H

//>> [TOD_TX_TTYPE_5_REG]
static const uint64_t TOD_TX_TTYPE_5_REG = 0x00040016ull;

static const uint32_t TOD_TX_TTYPE_5_REG_TX_TTYPE_5_TRIGGER = 0;
//<< [TOD_TX_TTYPE_5_REG]
// perv/reg00023.H

//>> [XSTOP4]
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
//<< [XSTOP4]
// perv/reg00023.H

//>> [OTPC_M_EXPORT_REGL_STATUS]
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
//<< [OTPC_M_EXPORT_REGL_STATUS]
// perv/reg00022.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00022.H"
#include "perv/reg00023.H"
#endif
#endif
