/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_7.H $       */
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

#ifndef __p10_scom_pauc_7_H_
#define __p10_scom_pauc_7_H_


namespace scomt
{
namespace pauc
{


static const uint64_t EPS_THERM_WSUB_CONTROL_REG = 0x10050012ull;
// pauc/reg00007.H

static const uint64_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG = 0x10050016ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC = 0;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC_LEN = 3;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT = 36;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN = 2;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_0_REG = 0x100f0020ull;

static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0 = 0;
static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN = 6;
static const uint32_t HANG_PULSE_0_REG_SUPPRESS_HANG_0 = 6;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_1_REG = 0x100f0021ull;

static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1 = 0;
static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN = 6;
static const uint32_t HANG_PULSE_1_REG_SUPPRESS_HANG_1 = 6;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_2_REG = 0x100f0022ull;

static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2 = 0;
static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN = 6;
static const uint32_t HANG_PULSE_2_REG_SUPPRESS_HANG_2 = 6;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_3_REG = 0x100f0023ull;

static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3 = 0;
static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN = 6;
static const uint32_t HANG_PULSE_3_REG_SUPPRESS_HANG_3 = 6;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_4_REG = 0x100f0024ull;

static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4 = 0;
static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN = 6;
static const uint32_t HANG_PULSE_4_REG_SUPPRESS_HANG_4 = 6;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_5_REG = 0x100f0025ull;

static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5 = 0;
static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN = 6;
static const uint32_t HANG_PULSE_5_REG_SUPPRESS_HANG_5 = 6;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_6_REG = 0x100f0026ull;

static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6 = 0;
static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN = 6;
static const uint32_t HANG_PULSE_6_REG_SUPPRESS_HANG_6 = 6;
// pauc/reg00007.H

static const uint64_t HOSTATTN_INTERRUPT_REG = 0x100f002bull;
// pauc/reg00007.H

static const uint64_t OPCG_CAPT2 = 0x10030011ull;

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
// pauc/reg00007.H

static const uint64_t PB_PMU1_TLPM_COUNTER = 0x1001181cull;
// pauc/reg00007.H

static const uint64_t PPE_ARB_CSCR_RW = 0x10012c0aull;
static const uint64_t PPE_ARB_CSCR_WO_CLEAR = 0x10012c0bull;
static const uint64_t PPE_ARB_CSCR_WO_OR = 0x10012c0cull;

static const uint32_t PPE_ARB_CSCR_SRAM_ACCESS_MODE = 0;
static const uint32_t PPE_ARB_CSCR_SRAM_SCRUB_ENABLE = 1;
static const uint32_t PPE_ARB_CSCR_ECC_CORRECT_DIS = 2;
static const uint32_t PPE_ARB_CSCR_ECC_DETECT_DIS = 3;
static const uint32_t PPE_ARB_CSCR_ECC_INJECT_TYPE = 4;
static const uint32_t PPE_ARB_CSCR_ECC_INJECT_ERR = 5;
static const uint32_t PPE_ARB_CSCR_SPARE_6_7 = 6;
static const uint32_t PPE_ARB_CSCR_SPARE_6_7_LEN = 2;
static const uint32_t PPE_ARB_CSCR_SRAM_SCRUB_INDEX = 47;
static const uint32_t PPE_ARB_CSCR_SRAM_SCRUB_INDEX_LEN = 13;
// pauc/reg00007.H

static const uint64_t RECOV_UNMASKED = 0x10040011ull;

static const uint32_t RECOV_UNMASKED_RECOV_UNMASKED_IN = 1;
static const uint32_t RECOV_UNMASKED_RECOV_UNMASKED_IN_LEN = 53;
// pauc/reg00007.H

static const uint64_t SCAN_UPDATEDR = 0x1003a000ull;
// pauc/reg00007.H

static const uint64_t SCOM_PPE_WORK_REG1 = 0x10012c21ull;

static const uint32_t SCOM_PPE_WORK_REG1_SCOM_PPE_WORK1 = 0;
static const uint32_t SCOM_PPE_WORK_REG1_SCOM_PPE_WORK1_LEN = 32;
// pauc/reg00007.H

static const uint64_t SPATTN_UNMASKED = 0x10040012ull;

static const uint32_t SPATTN_UNMASKED_SPATTN_UNMASKED_IN = 1;
static const uint32_t SPATTN_UNMASKED_SPATTN_UNMASKED_IN_LEN = 35;
// pauc/reg00007.H

static const uint64_t SYNC_CONFIG = 0x10030000ull;

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
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN = 15;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE = 16;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN = 8;
// pauc/reg00007.H

static const uint64_t TRA0_TR1_CONFIG_3 = 0x10010446ull;

static const uint32_t TRA0_TR1_CONFIG_3_C = 0;
static const uint32_t TRA0_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TRA0_TR1_CONFIG_3_D = 24;
static const uint32_t TRA0_TR1_CONFIG_3_D_LEN = 24;
// pauc/reg00007.H

static const uint64_t TRA1_TR0_CONFIG_5 = 0x10010488ull;

static const uint32_t TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t TRA1_TR0_CONFIG_5_D_LEN = 24;
// pauc/reg00007.H

}
}
#include "pauc/reg00007.H"
#endif
