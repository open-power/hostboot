/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_e.H $         */
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

#ifndef __p10_scom_mc_e_H_
#define __p10_scom_mc_e_H_


namespace scomt
{
namespace mc
{


static const uint64_t EPS_DBG_TRACE_REG_1 = 0x0c0107ceull;

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
// mc/reg00014.H

static const uint64_t EPS_FIR_LOCAL_ACTION1 = 0x0c0403d1ull;

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
// mc/reg00014.H

static const uint64_t MBA_SCOMFIR_AACR = 0x0c010fe9ull;

static const uint32_t MBA_SCOMFIR_AACR_BUFFER = 0;
static const uint32_t MBA_SCOMFIR_AACR_ADDRESS = 1;
static const uint32_t MBA_SCOMFIR_AACR_ADDRESS_LEN = 10;
static const uint32_t MBA_SCOMFIR_AACR_AUTOINC = 11;
static const uint32_t MBA_SCOMFIR_AACR_ECCGEN = 12;
static const uint32_t MBA_SCOMFIR_AACR_CHANNEL = 13;
static const uint32_t MBA_SCOMFIR_AACR_CHANNEL_LEN = 2;
// mc/reg00014.H

static const uint64_t MBA_SCOMFIR_MCWATDATA0 = 0x0c010fdaull;

static const uint32_t MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE = 0;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_COUNT_VALUE_LEN = 6;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE = 6;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_TIMER_VALUE_LEN = 8;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT = 16;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_EXTERNAL_ARM_SELECT_LEN = 4;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT = 20;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_EXTERNAL_RESET_SELECT_LEN = 4;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_EXTERNAL_TRIGGER_SELECT = 24;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_EXTERNAL_TRIGGER_SELECT_LEN = 4;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT = 28;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT0_SELECT_LEN = 4;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT = 32;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT1_SELECT_LEN = 4;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT = 36;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT2_SELECT_LEN = 4;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT = 40;
static const uint32_t MBA_SCOMFIR_MCWATDATA0_LOCAL_EVENT3_SELECT_LEN = 4;
// mc/reg00014.H

static const uint64_t MBA_SCOMFIR_SPARE = 0x0c010fcfull;

static const uint32_t MBA_SCOMFIR_SPARE_SPARE = 0;
static const uint32_t MBA_SCOMFIR_SPARE_SPARE_LEN = 8;
// mc/reg00014.H

static const uint64_t MBA_SCOMFIR_WATCFG0CQ = 0x0c010fc2ull;

static const uint32_t MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB = 0;
static const uint32_t MBA_SCOMFIR_WATCFG0CQ_WATCFG0CQ_CFG_WAT_MSKB_LEN = 44;
// mc/reg00014.H

static const uint64_t MBA_SCOMFIR_WATCFG1DQ = 0x0c010fc8ull;

static const uint32_t MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA = 0;
static const uint32_t MBA_SCOMFIR_WATCFG1DQ_WATCFG1DQ_CFG_WAT_PATA_LEN = 44;
// mc/reg00014.H

static const uint64_t OPCG_REG1 = 0x0c0303c3ull;

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
// mc/reg00014.H

static const uint64_t SCOMFIR_AAER = 0x0c010feeull;

static const uint32_t SCOMFIR_AAER_AAER_TAG_ECC = 0;
static const uint32_t SCOMFIR_AAER_AAER_TAG_ECC_LEN = 9;
// mc/reg00014.H

static const uint64_t SCOMFIR_MCFGP0E = 0x0c010fd6ull;

static const uint32_t SCOMFIR_MCFGP0E_VALID = 0;
static const uint32_t SCOMFIR_MCFGP0E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t SCOMFIR_MCFGP0E_LOWER_ADDRESS = 2;
static const uint32_t SCOMFIR_MCFGP0E_LOWER_ADDRESS_LEN = 19;
static const uint32_t SCOMFIR_MCFGP0E_UPPER_ADDRESS = 21;
static const uint32_t SCOMFIR_MCFGP0E_UPPER_ADDRESS_LEN = 19;
// mc/reg00014.H

static const uint64_t SCOMFIR_MCFGPM1A = 0x0c010ff1ull;

static const uint32_t SCOMFIR_MCFGPM1A_HOLE_VALID = 0;
static const uint32_t SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t SCOMFIR_MCFGPM1A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t SCOMFIR_MCFGPM1A_RESERVED_16_21 = 16;
static const uint32_t SCOMFIR_MCFGPM1A_RESERVED_16_21_LEN = 6;
static const uint32_t SCOMFIR_MCFGPM1A_SMF_VALID = 22;
static const uint32_t SCOMFIR_MCFGPM1A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS = 24;
static const uint32_t SCOMFIR_MCFGPM1A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS = 43;
static const uint32_t SCOMFIR_MCFGPM1A_SMF_UPPER_ADDRESS_LEN = 19;
// mc/reg00014.H

static const uint64_t SCOMFIR_MCFGPR1 = 0x0c010fcdull;

static const uint32_t SCOMFIR_MCFGPR1_CONFIGURATION_VALID = 0;
static const uint32_t SCOMFIR_MCFGPR1_MMIO_VALID = 1;
static const uint32_t SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS = 2;
static const uint32_t SCOMFIR_MCFGPR1_CONFIGURATION_GROUP_BASE_ADDRESS_LEN = 31;
static const uint32_t SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS = 33;
static const uint32_t SCOMFIR_MCFGPR1_MMIO_GROUP_BASE_ADDRESS_LEN = 31;
// mc/reg00014.H

static const uint64_t SLAVE_CONFIG_REG = 0x0c0f03deull;

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
// mc/reg00014.H

static const uint64_t TRA1_TR0_CONFIG_1 = 0x0c0107c4ull;

static const uint32_t TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA1_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// mc/reg00014.H

static const uint64_t XSTOP2 = 0x0c0303cdull;

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
// mc/reg00014.H

}
}
#include "mc/reg00014.H"
#endif
