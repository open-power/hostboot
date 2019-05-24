/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_b.H $         */
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

#ifndef __p10_scom_mc_b_H_
#define __p10_scom_mc_b_H_


namespace scomt
{
namespace mc
{


static const uint64_t ATOMIC_LOCK_REG = 0x0c0f03ffull;

static const uint32_t ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t ATOMIC_LOCK_REG_ID = 1;
static const uint32_t ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// mc/reg00011.H

static const uint64_t ATTN_INTERRUPT_REG = 0x0c0f001aull;
// mc/reg00011.H

static const uint64_t EPS_DBG_TRACE_MODE_REG_2 = 0x0c0107cfull;

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
// mc/reg00011.H

static const uint64_t EPS_FIR_LOCAL_MASK_RW = 0x0c040103ull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_AND = 0x0c040104ull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_OR = 0x0c040105ull;

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
// mc/reg00011.H

static const uint64_t LOCAL_FIR_RW = 0x0c040100ull;
static const uint64_t LOCAL_FIR_WO_AND = 0x0c040101ull;
static const uint64_t LOCAL_FIR_WO_OR = 0x0c040102ull;

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
// mc/reg00011.H

static const uint64_t MBA_SCOMFIR_MCEBUSEN3 = 0x0c010fa7ull;

static const uint32_t MBA_SCOMFIR_MCEBUSEN3_N = 0;
static const uint32_t MBA_SCOMFIR_MCEBUSEN3_N_LEN = 16;
static const uint32_t MBA_SCOMFIR_MCEBUSEN3_NABLE = 16;
static const uint32_t MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT = 17;
static const uint32_t MBA_SCOMFIR_MCEBUSEN3_XTENDED_SELECT_LEN = 3;
// mc/reg00011.H

static const uint64_t MBA_SCOMFIR_MCWATDATA6 = 0x0c010fa0ull;

static const uint32_t MBA_SCOMFIR_MCWATDATA6_PATTERN_B = 0;
static const uint32_t MBA_SCOMFIR_MCWATDATA6_PATTERN_B_LEN = 22;
static const uint32_t MBA_SCOMFIR_MCWATDATA6_MASK_B = 22;
static const uint32_t MBA_SCOMFIR_MCWATDATA6_MASK_B_LEN = 22;
// mc/reg00011.H

static const uint64_t MBA_SCOMFIR_WATCFG1AQ = 0x0c010f85ull;

static const uint32_t MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL = 0;
static const uint32_t MBA_SCOMFIR_WATCFG1AQ_WATCFG1AQ_CFG_WAT_EVENT_SEL_LEN = 48;
// mc/reg00011.H

static const uint64_t RECOV = 0x0c040001ull;

static const uint32_t RECOV_ANY_RECOV = 0;
static const uint32_t RECOV_RESERVED1R = 1;
static const uint32_t RECOV_RECOV_ANY_LOCAL_XSTOP = 2;
static const uint32_t RECOV_RESERVED3R = 3;
static const uint32_t RECOV_RECOV_PERV = 4;
static const uint32_t RECOV_RECOV_IN05 = 5;
static const uint32_t RECOV_RECOV_IN06 = 6;
static const uint32_t RECOV_RECOV_IN07 = 7;
static const uint32_t RECOV_RECOV_IN08 = 8;
static const uint32_t RECOV_RECOV_IN09 = 9;
static const uint32_t RECOV_RECOV_IN10 = 10;
static const uint32_t RECOV_RECOV_IN11 = 11;
static const uint32_t RECOV_RECOV_IN12 = 12;
static const uint32_t RECOV_RECOV_IN13 = 13;
static const uint32_t RECOV_RECOV_IN14 = 14;
static const uint32_t RECOV_RECOV_IN15 = 15;
static const uint32_t RECOV_RECOV_IN16 = 16;
static const uint32_t RECOV_RECOV_IN17 = 17;
static const uint32_t RECOV_RECOV_IN18 = 18;
static const uint32_t RECOV_RECOV_IN19 = 19;
static const uint32_t RECOV_RECOV_IN20 = 20;
static const uint32_t RECOV_RECOV_IN21 = 21;
static const uint32_t RECOV_RECOV_IN22 = 22;
static const uint32_t RECOV_RECOV_IN23 = 23;
static const uint32_t RECOV_RECOV_IN24 = 24;
static const uint32_t RECOV_RECOV_IN25 = 25;
static const uint32_t RECOV_RECOV_IN26 = 26;
static const uint32_t RECOV_RECOV_IN27 = 27;
static const uint32_t RECOV_RECOV_IN28 = 28;
static const uint32_t RECOV_RECOV_IN29 = 29;
static const uint32_t RECOV_RECOV_IN30 = 30;
static const uint32_t RECOV_RECOV_IN31 = 31;
static const uint32_t RECOV_RECOV_IN32 = 32;
static const uint32_t RECOV_RECOV_IN33 = 33;
static const uint32_t RECOV_RECOV_IN34 = 34;
static const uint32_t RECOV_RECOV_IN35 = 35;
static const uint32_t RECOV_RECOV_IN36 = 36;
static const uint32_t RECOV_RECOV_IN37 = 37;
static const uint32_t RECOV_RECOV_IN38 = 38;
static const uint32_t RECOV_RECOV_IN39 = 39;
static const uint32_t RECOV_RECOV_IN40 = 40;
static const uint32_t RECOV_RECOV_IN41 = 41;
static const uint32_t RECOV_RECOV_IN42 = 42;
static const uint32_t RECOV_RECOV_IN43 = 43;
static const uint32_t RECOV_RECOV_IN44 = 44;
static const uint32_t RECOV_RECOV_IN45 = 45;
static const uint32_t RECOV_RECOV_IN46 = 46;
static const uint32_t RECOV_RECOV_IN47 = 47;
static const uint32_t RECOV_RECOV_IN48 = 48;
static const uint32_t RECOV_RECOV_IN49 = 49;
static const uint32_t RECOV_RECOV_IN50 = 50;
static const uint32_t RECOV_RECOV_IN51 = 51;
static const uint32_t RECOV_RECOV_IN52 = 52;
static const uint32_t RECOV_RECOV_IN53 = 53;
// mc/reg00011.H

static const uint64_t SCOMFIR_MCFGP0 = 0x0c010c0aull;

static const uint32_t SCOMFIR_MCFGP0_0_VALID = 0;
static const uint32_t SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS = 1;
static const uint32_t SCOMFIR_MCFGP0_0_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t SCOMFIR_MCFGP0_0_GROUP_SIZE = 25;
static const uint32_t SCOMFIR_MCFGP0_0_GROUP_SIZE_LEN = 15;
static const uint32_t SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP = 40;
static const uint32_t SCOMFIR_MCFGP0_0_MC_CHANNELS_PER_GROUP_LEN = 3;
static const uint32_t SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION = 43;
static const uint32_t SCOMFIR_MCFGP0_0_GROUP_MEMBER_IDENTIFICATION_LEN = 3;
static const uint32_t SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE = 46;
static const uint32_t SCOMFIR_MCFGP0_R0_CONFIGURATION_GROUP_SIZE_LEN = 8;
static const uint32_t SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE = 54;
static const uint32_t SCOMFIR_MCFGP0_R0_MMIO_GROUP_SIZE_LEN = 8;
// mc/reg00011.H

static const uint64_t XSTOP4 = 0x0c030014ull;

static const uint32_t XSTOP4_XSTOP4_MASK_B = 0;
static const uint32_t XSTOP4_ALIGNED_XSTOP4 = 1;
static const uint32_t XSTOP4_TRIGGER_OPCG_ON_XSTOP4 = 2;
static const uint32_t XSTOP4_XSTOP4_WAIT_ALLWAYS = 3;
static const uint32_t XSTOP4_XSTOP4_PERV = 4;
static const uint32_t XSTOP4_XSTOP4_UNIT1 = 5;
static const uint32_t XSTOP4_XSTOP4_UNIT2 = 6;
static const uint32_t XSTOP4_XSTOP4_UNIT3 = 7;
static const uint32_t XSTOP4_XSTOP4_UNIT4 = 8;
static const uint32_t XSTOP4_XSTOP4_UNIT5 = 9;
static const uint32_t XSTOP4_XSTOP4_UNIT6 = 10;
static const uint32_t XSTOP4_XSTOP4_UNIT7 = 11;
static const uint32_t XSTOP4_XSTOP4_UNIT8 = 12;
static const uint32_t XSTOP4_XSTOP4_UNIT9 = 13;
static const uint32_t XSTOP4_XSTOP4_UNIT10 = 14;
static const uint32_t XSTOP4_XSTOP4_UNIT11 = 15;
static const uint32_t XSTOP4_XSTOP4_UNIT12 = 16;
static const uint32_t XSTOP4_XSTOP4_UNIT13 = 17;
static const uint32_t XSTOP4_XSTOP4_UNIT14 = 18;
static const uint32_t XSTOP4_XSTOP4_WAIT_CYCLES = 48;
static const uint32_t XSTOP4_XSTOP4_WAIT_CYCLES_LEN = 12;
// mc/reg00011.H

}
}
#include "mc/reg00011.H"
#endif
