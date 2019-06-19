/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_a.H $        */
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

#ifndef __p10_scom_pec_a_H_
#define __p10_scom_pec_a_H_


namespace scomt
{
namespace pec
{


static const uint64_t CC_PROTECT_MODE_REG = 0x080303feull;

static const uint32_t CC_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t CC_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// pec/reg00010.H

static const uint64_t CLOCK_STAT_SL = 0x08030008ull;

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
// pec/reg00010.H

static const uint64_t CPLT_CTRL3_RW = 0x08000003ull;
static const uint64_t CPLT_CTRL3_WO_CLEAR = 0x08000023ull;
static const uint64_t CPLT_CTRL3_WO_OR = 0x08000013ull;

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
// pec/reg00010.H

static const uint64_t EPS_DBG_INST1_COND_REG_1 = 0x080107c1ull;

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
// pec/reg00010.H

static const uint64_t EPS_DBG_INST2_COND_REG_1 = 0x080107c4ull;

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
// pec/reg00010.H

static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4 = 0x08040084ull;

static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_XSTOP_ERR = 0;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_RECOV_ERR = 1;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_SPATTN_ERR = 2;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_LXSTOP_ERR = 3;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_HOSTATTN_ERR = 4;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_SYS_XSTOP_ERR = 5;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_OOB1_ERR = 6;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_DBG_TRIG_ERR = 7;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK4_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// pec/reg00010.H

static const uint64_t EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG = 0x08010007ull;

static const uint32_t EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK = 0;
static const uint32_t EPS_PSC_ATOMIC_LOCK_MASK_LATCH_REG_ATOMIC_LOCK_MASK_LEN = 32;
// pec/reg00010.H

static const uint64_t PB_PBAIB_REGS_PBAIBHWCFG_REG = 0x08010800ull;

static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_OSMB_DATASTART_MODE = 16;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_OSMB_DATASTART_MODE_LEN = 3;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_TX_RESP_HWM = 20;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_TX_RESP_HWM_LEN = 4;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_TX_RESP_LWM = 24;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_TX_RESP_LWM_LEN = 4;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_OSMB_EARLYEMPTY_MODE = 28;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_OSMB_EARLYEMPTY_MODE_LEN = 2;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PCIE_CLK_TRACE_EN = 30;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_SELECT_ETU_TRACE = 31;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PCI_CLK_TRACE_SEL = 32;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PCI_CLK_TRACE_SEL_LEN = 4;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_ISMB_ERROR_INJECT = 36;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_ISMB_ERROR_INJECT_LEN = 3;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_OSMB_HOL_BLK_CNT = 40;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_OSMB_HOL_BLK_CNT_LEN = 3;
// pec/reg00010.H

static const uint64_t PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG = 0x03011807ull;

static const uint32_t PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_EN = 0;
static const uint32_t PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_INBOUND_OVERRIDE_EN = 1;
static const uint32_t PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_OUTBOUND_OVERRIDE_EN = 2;
static const uint32_t PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_CHECKOUT_BASE_RTAG = 3;
static const uint32_t PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_CHECKOUT_BASE_RTAG_LEN = 17;
static const uint32_t PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_RESPONSE_BASE_RTAG = 23;
static const uint32_t PB_PBCQ_PEPBREGS_NMMU_RTAG_OVERRIDE_REG_RESPONSE_BASE_RTAG_LEN = 17;
// pec/reg00010.H

static const uint64_t PB_PBCQ_PEPBREGS_NRDSTKOVR_REG = 0x03011808ull;

static const uint32_t PB_PBCQ_PEPBREGS_NRDSTKOVR_REG_STK0 = 0;
static const uint32_t PB_PBCQ_PEPBREGS_NRDSTKOVR_REG_STK0_LEN = 32;
static const uint32_t PB_PBCQ_PEPBREGS_NRDSTKOVR_REG_STK1 = 32;
static const uint32_t PB_PBCQ_PEPBREGS_NRDSTKOVR_REG_STK1_LEN = 16;
static const uint32_t PB_PBCQ_PEPBREGS_NRDSTKOVR_REG_ENABLE = 48;
// pec/reg00010.H

}
}
#ifndef __PPE_HCODE__
    #include "pec/reg00010.H"
#endif
#endif
