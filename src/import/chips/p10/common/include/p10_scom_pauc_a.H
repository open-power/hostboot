/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_a.H $       */
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

#ifndef __p10_scom_pauc_a_H_
#define __p10_scom_pauc_a_H_


namespace scomt
{
namespace pauc
{


static const uint64_t CC_PROTECT_MODE_REG = 0x100303feull;

static const uint32_t CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// pauc/reg00010.H

static const uint64_t CLOCK_STAT_SL = 0x10030008ull;

static const uint32_t CLOCK_STAT_SL_PERV_SL = 4;
static const uint32_t CLOCK_STAT_SL_UNIT1_SL = 5;
static const uint32_t CLOCK_STAT_SL_UNIT2_SL = 6;
static const uint32_t CLOCK_STAT_SL_UNIT3_SL = 7;
static const uint32_t CLOCK_STAT_SL_UNIT4_SL = 8;
static const uint32_t CLOCK_STAT_SL_UNIT5_SL = 9;
static const uint32_t CLOCK_STAT_SL_UNIT6_SL = 10;
static const uint32_t CLOCK_STAT_SL_UNIT7_SL = 11;
static const uint32_t CLOCK_STAT_SL_UNIT8_SL = 12;
static const uint32_t CLOCK_STAT_SL_UNIT9_SL = 13;
static const uint32_t CLOCK_STAT_SL_UNIT10_SL = 14;
static const uint32_t CLOCK_STAT_SL_UNIT11_SL = 15;
static const uint32_t CLOCK_STAT_SL_UNIT12_SL = 16;
static const uint32_t CLOCK_STAT_SL_UNIT13_SL = 17;
static const uint32_t CLOCK_STAT_SL_UNIT14_SL = 18;
// pauc/reg00010.H

static const uint64_t CPLT_CTRL3_RW = 0x10000003ull;
static const uint64_t CPLT_CTRL3_WO_CLEAR = 0x10000023ull;
static const uint64_t CPLT_CTRL3_WO_OR = 0x10000013ull;

static const uint32_t CPLT_CTRL3_0_PSCOM_EN = 4;
static const uint32_t CPLT_CTRL3_1_PSCOM_EN = 5;
static const uint32_t CPLT_CTRL3_2_PSCOM_EN = 6;
static const uint32_t CPLT_CTRL3_3_PSCOM_EN = 7;
static const uint32_t CPLT_CTRL3_4_PSCOM_EN = 8;
static const uint32_t CPLT_CTRL3_5_PSCOM_EN = 9;
static const uint32_t CPLT_CTRL3_6_PSCOM_EN = 10;
static const uint32_t CPLT_CTRL3_7_PSCOM_EN = 11;
static const uint32_t CPLT_CTRL3_8_PSCOM_EN = 12;
static const uint32_t CPLT_CTRL3_9_PSCOM_EN = 13;
static const uint32_t CPLT_CTRL3_10_PSCOM_EN = 14;
static const uint32_t CPLT_CTRL3_11_PSCOM_EN = 15;
static const uint32_t CPLT_CTRL3_12_PSCOM_EN = 16;
static const uint32_t CPLT_CTRL3_13_PSCOM_EN = 17;
static const uint32_t CPLT_CTRL3_14_PSCOM_EN = 18;
// pauc/reg00010.H

static const uint64_t EPS_DBG_INST1_COND_REG_1 = 0x100107c1ull;

static const uint32_t EPS_DBG_INST1_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t EPS_DBG_INST1_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t EPS_DBG_INST1_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t EPS_DBG_INST1_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t EPS_DBG_INST1_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t EPS_DBG_INST1_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t EPS_DBG_INST1_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t EPS_DBG_INST1_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t EPS_DBG_INST1_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t EPS_DBG_INST1_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t EPS_DBG_INST1_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t EPS_DBG_INST1_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// pauc/reg00010.H

static const uint64_t EPS_DBG_INST2_COND_REG_1 = 0x100107c4ull;

static const uint32_t EPS_DBG_INST2_COND_REG_1_COND1_SEL_A = 0;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND1_SEL_A_LEN = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND1_SEL_B = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND1_SEL_B_LEN = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND2_SEL_A = 16;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND2_SEL_A_LEN = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND2_SEL_B = 24;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND2_SEL_B_LEN = 8;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C1_INAROW_MODE = 32;
static const uint32_t EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE1 = 33;
static const uint32_t EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE1 = 34;
static const uint32_t EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE1 = 35;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C2_INAROW_MODE = 39;
static const uint32_t EPS_DBG_INST2_COND_REG_1_AND_TRIGGER_MODE2 = 40;
static const uint32_t EPS_DBG_INST2_COND_REG_1_NOT_TRIGGER_MODE2 = 41;
static const uint32_t EPS_DBG_INST2_COND_REG_1_EDGE_TRIGGER_MODE2 = 42;
static const uint32_t EPS_DBG_INST2_COND_REG_1_COND3_ENABLE_RESET = 46;
static const uint32_t EPS_DBG_INST2_COND_REG_1_EXACT_TO_MODE = 47;
static const uint32_t EPS_DBG_INST2_COND_REG_1_RESET_C2TIMER_ON_C1 = 48;
static const uint32_t EPS_DBG_INST2_COND_REG_1_RESET_C3_ON_C0 = 49;
static const uint32_t EPS_DBG_INST2_COND_REG_1_SLOW_TO_MODE = 50;
static const uint32_t EPS_DBG_INST2_COND_REG_1_EXACT_RESET_C3_ON_TO = 51;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT = 52;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C1_COUNT_LT_LEN = 4;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT = 56;
static const uint32_t EPS_DBG_INST2_COND_REG_1_C2_COUNT_LT_LEN = 4;
static const uint32_t EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT = 60;
static const uint32_t EPS_DBG_INST2_COND_REG_1_RESET_C3_SELECT_LEN = 3;
// pauc/reg00010.H

static const uint64_t EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG = 0x10010007ull;

static const uint32_t EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK = 0;
static const uint32_t EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN = 32;
// pauc/reg00010.H

static const uint64_t PB_PMU3_TLPM_COUNTER = 0x1001181eull;
// pauc/reg00010.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t REGS_SPARE_MODE_PB = 0x800f7c001000003full;

static const uint32_t REGS_SPARE_MODE_PB_0 = 48;
static const uint32_t REGS_SPARE_MODE_PB_1 = 49;
static const uint32_t REGS_SPARE_MODE_PB_2 = 50;
static const uint32_t REGS_SPARE_MODE_PB_3 = 51;
static const uint32_t REGS_SPARE_MODE_PB_4 = 52;
static const uint32_t REGS_SPARE_MODE_PB_5 = 53;
static const uint32_t REGS_SPARE_MODE_PB_6 = 54;
static const uint32_t REGS_SPARE_MODE_PB_7 = 55;
// pauc/reg00010.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t REGS_TX_IMPCAL_SWO1_PB = 0x800f34001000003full;

static const uint32_t REGS_TX_IMPCAL_SWO1_PB_SWO_EN = 48;
static const uint32_t REGS_TX_IMPCAL_SWO1_PB_SWO_CAL_SEGS = 49;
static const uint32_t REGS_TX_IMPCAL_SWO1_PB_SWO_CMP_INV = 50;
static const uint32_t REGS_TX_IMPCAL_SWO1_PB_SWO_CMP_OFFSET = 51;
static const uint32_t REGS_TX_IMPCAL_SWO1_PB_SWO_CMP_RESET = 52;
static const uint32_t REGS_TX_IMPCAL_SWO1_PB_SWO_POWERDOWN = 53;
static const uint32_t REGS_TX_IMPCAL_SWO1_PB_SWO_TCOIL = 54;
static const uint32_t REGS_TX_IMPCAL_SWO1_PB_RANGE_CHECK = 56;
static const uint32_t REGS_TX_IMPCAL_SWO1_PB_CYA_DATA_INV = 57;
static const uint32_t REGS_TX_IMPCAL_SWO1_PB_TEST_OVR_2R = 58;
static const uint32_t REGS_TX_IMPCAL_SWO1_PB_TEST_OVR_1R = 59;
static const uint32_t REGS_TX_IMPCAL_SWO1_PB_TEST_OVR_4X_SEG = 60;
static const uint32_t REGS_TX_IMPCAL_SWO1_PB_TEST_CLK_DIV = 61;
static const uint32_t REGS_TX_IMPCAL_SWO1_PB_TEST_CLK_DIV_LEN = 2;
// pauc/reg00010.H

}
}
#include "pauc/reg00010.H"
#endif
