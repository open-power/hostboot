/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_7.H $         */
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

#ifndef __p10_scom_mc_7_H_
#define __p10_scom_mc_7_H_


namespace scomt
{
namespace mc
{


static const uint64_t EPS_THERM_WSUB_CONTROL_REG = 0x0c050012ull;
// mc/reg00007.H

static const uint64_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG = 0x0c050016ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC = 0;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC_LEN = 3;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT = 36;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN = 2;
// mc/reg00007.H

static const uint64_t FIR_MASK = 0x0c040002ull;

static const uint32_t FIR_MASK_01 = 1;
static const uint32_t FIR_MASK_02 = 2;
static const uint32_t FIR_MASK_03 = 3;
static const uint32_t FIR_MASK_04 = 4;
static const uint32_t FIR_MASK_05 = 5;
static const uint32_t FIR_MASK_06 = 6;
static const uint32_t FIR_MASK_07 = 7;
static const uint32_t FIR_MASK_08 = 8;
static const uint32_t FIR_MASK_09 = 9;
static const uint32_t FIR_MASK_10 = 10;
static const uint32_t FIR_MASK_11 = 11;
static const uint32_t FIR_MASK_12 = 12;
static const uint32_t FIR_MASK_13 = 13;
static const uint32_t FIR_MASK_14 = 14;
static const uint32_t FIR_MASK_15 = 15;
static const uint32_t FIR_MASK_16 = 16;
static const uint32_t FIR_MASK_17 = 17;
static const uint32_t FIR_MASK_18 = 18;
static const uint32_t FIR_MASK_19 = 19;
static const uint32_t FIR_MASK_20 = 20;
static const uint32_t FIR_MASK_21 = 21;
static const uint32_t FIR_MASK_22 = 22;
static const uint32_t FIR_MASK_23 = 23;
static const uint32_t FIR_MASK_24 = 24;
static const uint32_t FIR_MASK_25 = 25;
static const uint32_t FIR_MASK_26 = 26;
static const uint32_t FIR_MASK_27 = 27;
static const uint32_t FIR_MASK_28 = 28;
static const uint32_t FIR_MASK_29 = 29;
static const uint32_t FIR_MASK_30 = 30;
static const uint32_t FIR_MASK_31 = 31;
static const uint32_t FIR_MASK_32 = 32;
static const uint32_t FIR_MASK_33 = 33;
static const uint32_t FIR_MASK_34 = 34;
static const uint32_t FIR_MASK_35 = 35;
static const uint32_t FIR_MASK_36 = 36;
static const uint32_t FIR_MASK_37 = 37;
static const uint32_t FIR_MASK_38 = 38;
static const uint32_t FIR_MASK_39 = 39;
static const uint32_t FIR_MASK_40 = 40;
static const uint32_t FIR_MASK_41 = 41;
static const uint32_t FIR_MASK_42 = 42;
static const uint32_t FIR_MASK_43 = 43;
static const uint32_t FIR_MASK_44 = 44;
static const uint32_t FIR_MASK_45 = 45;
static const uint32_t FIR_MASK_46 = 46;
static const uint32_t FIR_MASK_47 = 47;
static const uint32_t FIR_MASK_48 = 48;
static const uint32_t FIR_MASK_49 = 49;
static const uint32_t FIR_MASK_50 = 50;
static const uint32_t FIR_MASK_51 = 51;
static const uint32_t FIR_MASK_52 = 52;
static const uint32_t FIR_MASK_53 = 53;
// mc/reg00007.H

static const uint64_t HANG_PULSE_0_REG = 0x0c0f0020ull;

static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0 = 0;
static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN = 6;
static const uint32_t HANG_PULSE_0_REG_SUPPRESS_HANG_0 = 6;
// mc/reg00007.H

static const uint64_t HANG_PULSE_1_REG = 0x0c0f0021ull;

static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1 = 0;
static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN = 6;
static const uint32_t HANG_PULSE_1_REG_SUPPRESS_HANG_1 = 6;
// mc/reg00007.H

static const uint64_t HANG_PULSE_2_REG = 0x0c0f0022ull;

static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2 = 0;
static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN = 6;
static const uint32_t HANG_PULSE_2_REG_SUPPRESS_HANG_2 = 6;
// mc/reg00007.H

static const uint64_t HANG_PULSE_3_REG = 0x0c0f0023ull;

static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3 = 0;
static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN = 6;
static const uint32_t HANG_PULSE_3_REG_SUPPRESS_HANG_3 = 6;
// mc/reg00007.H

static const uint64_t HANG_PULSE_4_REG = 0x0c0f0024ull;

static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4 = 0;
static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN = 6;
static const uint32_t HANG_PULSE_4_REG_SUPPRESS_HANG_4 = 6;
// mc/reg00007.H

static const uint64_t HANG_PULSE_5_REG = 0x0c0f0025ull;

static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5 = 0;
static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN = 6;
static const uint32_t HANG_PULSE_5_REG_SUPPRESS_HANG_5 = 6;
// mc/reg00007.H

static const uint64_t HANG_PULSE_6_REG = 0x0c0f0026ull;

static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6 = 0;
static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN = 6;
static const uint32_t HANG_PULSE_6_REG_SUPPRESS_HANG_6 = 6;
// mc/reg00007.H

static const uint64_t HOSTATTN_INTERRUPT_REG = 0x0c0f002bull;
// mc/reg00007.H

static const uint64_t MBA_SCOMFIR_MCEBUSEN1 = 0x0c010fa5ull;

static const uint32_t MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS = 0;
static const uint32_t MBA_SCOMFIR_MCEBUSEN1_MCEBUSEN1_EVENT_BUS_SELECTS_LEN = 64;
// mc/reg00007.H

static const uint64_t MBA_SCOMFIR_MCWATDATA4 = 0x0c010f9eull;

static const uint32_t MBA_SCOMFIR_MCWATDATA4_PATTERN_B = 0;
static const uint32_t MBA_SCOMFIR_MCWATDATA4_PATTERN_B_LEN = 22;
static const uint32_t MBA_SCOMFIR_MCWATDATA4_MASK_B = 22;
static const uint32_t MBA_SCOMFIR_MCWATDATA4_MASK_B_LEN = 22;
// mc/reg00007.H

static const uint64_t OPCG_CAPT2 = 0x0c030011ull;

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
// mc/reg00007.H

static const uint64_t SCAN_UPDATEDR = 0x0c03a000ull;
// mc/reg00007.H

static const uint64_t SCOMFIR_MCFGP0A = 0x0c010c0eull;

static const uint32_t SCOMFIR_MCFGP0A_HOLE_VALID = 0;
static const uint32_t SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t SCOMFIR_MCFGP0A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t SCOMFIR_MCFGP0A_RESERVED_16_21 = 16;
static const uint32_t SCOMFIR_MCFGP0A_RESERVED_16_21_LEN = 6;
static const uint32_t SCOMFIR_MCFGP0A_SMF_VALID = 22;
static const uint32_t SCOMFIR_MCFGP0A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS = 24;
static const uint32_t SCOMFIR_MCFGP0A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS = 43;
static const uint32_t SCOMFIR_MCFGP0A_SMF_UPPER_ADDRESS_LEN = 19;
// mc/reg00007.H

static const uint64_t SCOMFIR_MCFGPM1E = 0x0c010c1dull;

static const uint32_t SCOMFIR_MCFGPM1E_VALID = 0;
static const uint32_t SCOMFIR_MCFGPM1E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t SCOMFIR_MCFGPM1E_LOWER_ADDRESS = 2;
static const uint32_t SCOMFIR_MCFGPM1E_LOWER_ADDRESS_LEN = 19;
static const uint32_t SCOMFIR_MCFGPM1E_UPPER_ADDRESS = 21;
static const uint32_t SCOMFIR_MCFGPM1E_UPPER_ADDRESS_LEN = 19;
// mc/reg00007.H

static const uint64_t SYNC_CONFIG = 0x0c030000ull;

static const uint32_t SYNC_CONFIG_SYNC_PULSE_DELAY = 0;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_DELAY_LEN = 4;
static const uint32_t SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS = 4;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_INPUT_SEL = 5;
static const uint32_t SYNC_CONFIG_USE_SYNC_FOR_SCAN = 6;
static const uint32_t SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED = 7;
static const uint32_t SYNC_CONFIG_UNIT_REGION_CLKCMD_ENABLE = 8;
static const uint32_t SYNC_CONFIG_DISABLE_PCB_ITR = 9;
static const uint32_t SYNC_CONFIG_CONT_SCAN_DISABLE = 10;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_OUT_DIS = 11;
static const uint32_t SYNC_CONFIG_REGION_PGOOD_OVERRIDE = 12;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN = 15;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE = 16;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN = 8;
// mc/reg00007.H

static const uint64_t TRA1_TR0_CONFIG_5 = 0x0c010448ull;

static const uint32_t TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t TRA1_TR0_CONFIG_5_D_LEN = 24;
// mc/reg00007.H

static const uint64_t XFIR = 0x0c040000ull;

static const uint32_t XFIR_ANY_XSTOP = 0;
static const uint32_t XFIR_SYSTEM_XSTOP = 1;
static const uint32_t XFIR_XSTOP_ANY_SPATTN = 2;
static const uint32_t XFIR_DBG_FIR_XSTOP_ON_TRIG = 3;
static const uint32_t XFIR_XSTOP_PERV = 4;
static const uint32_t XFIR_XSTOP_IN05 = 5;
static const uint32_t XFIR_XSTOP_IN06 = 6;
static const uint32_t XFIR_XSTOP_IN07 = 7;
static const uint32_t XFIR_XSTOP_IN08 = 8;
static const uint32_t XFIR_XSTOP_IN09 = 9;
static const uint32_t XFIR_XSTOP_IN10 = 10;
static const uint32_t XFIR_XSTOP_IN11 = 11;
static const uint32_t XFIR_XSTOP_IN12 = 12;
static const uint32_t XFIR_XSTOP_IN13 = 13;
static const uint32_t XFIR_XSTOP_IN14 = 14;
static const uint32_t XFIR_XSTOP_IN15 = 15;
static const uint32_t XFIR_XSTOP_IN16 = 16;
static const uint32_t XFIR_XSTOP_IN17 = 17;
static const uint32_t XFIR_XSTOP_IN18 = 18;
static const uint32_t XFIR_XSTOP_IN19 = 19;
static const uint32_t XFIR_XSTOP_IN20 = 20;
static const uint32_t XFIR_XSTOP_IN21 = 21;
static const uint32_t XFIR_XSTOP_IN22 = 22;
static const uint32_t XFIR_XSTOP_IN23 = 23;
static const uint32_t XFIR_XSTOP_IN24 = 24;
static const uint32_t XFIR_XSTOP_IN25 = 25;
static const uint32_t XFIR_XSTOP_IN26 = 26;
static const uint32_t XFIR_XSTOP_IN27 = 27;
static const uint32_t XFIR_XSTOP_IN28 = 28;
static const uint32_t XFIR_XSTOP_IN29 = 29;
static const uint32_t XFIR_XSTOP_IN30 = 30;
static const uint32_t XFIR_XSTOP_IN31 = 31;
static const uint32_t XFIR_XSTOP_IN32 = 32;
static const uint32_t XFIR_XSTOP_IN33 = 33;
static const uint32_t XFIR_XSTOP_IN34 = 34;
static const uint32_t XFIR_XSTOP_IN35 = 35;
static const uint32_t XFIR_XSTOP_IN36 = 36;
static const uint32_t XFIR_XSTOP_IN37 = 37;
static const uint32_t XFIR_XSTOP_IN38 = 38;
static const uint32_t XFIR_XSTOP_IN39 = 39;
static const uint32_t XFIR_XSTOP_IN40 = 40;
static const uint32_t XFIR_XSTOP_IN41 = 41;
static const uint32_t XFIR_XSTOP_IN42 = 42;
static const uint32_t XFIR_XSTOP_IN43 = 43;
static const uint32_t XFIR_XSTOP_IN44 = 44;
static const uint32_t XFIR_XSTOP_IN45 = 45;
static const uint32_t XFIR_XSTOP_IN46 = 46;
static const uint32_t XFIR_XSTOP_IN47 = 47;
static const uint32_t XFIR_XSTOP_IN48 = 48;
static const uint32_t XFIR_XSTOP_IN49 = 49;
static const uint32_t XFIR_XSTOP_IN50 = 50;
static const uint32_t XFIR_XSTOP_IN51 = 51;
static const uint32_t XFIR_XSTOP_IN52 = 52;
static const uint32_t XFIR_XSTOP_IN53 = 53;
// mc/reg00007.H

}
}
#include "mc/reg00007.H"
#endif
