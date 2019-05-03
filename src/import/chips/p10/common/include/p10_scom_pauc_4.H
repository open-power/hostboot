/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_4.H $       */
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

#ifndef __p10_scom_pauc_4_H_
#define __p10_scom_pauc_4_H_


namespace scomt
{
namespace pauc
{


static const uint64_t CLOCK_STAT_ARY = 0x1003000aull;

static const uint32_t CLOCK_STAT_ARY_PERV_ARY = 4;
static const uint32_t CLOCK_STAT_ARY_UNIT1_ARY = 5;
static const uint32_t CLOCK_STAT_ARY_UNIT2_ARY = 6;
static const uint32_t CLOCK_STAT_ARY_UNIT3_ARY = 7;
static const uint32_t CLOCK_STAT_ARY_UNIT4_ARY = 8;
static const uint32_t CLOCK_STAT_ARY_UNIT5_ARY = 9;
static const uint32_t CLOCK_STAT_ARY_UNIT6_ARY = 10;
static const uint32_t CLOCK_STAT_ARY_UNIT7_ARY = 11;
static const uint32_t CLOCK_STAT_ARY_UNIT8_ARY = 12;
static const uint32_t CLOCK_STAT_ARY_UNIT9_ARY = 13;
static const uint32_t CLOCK_STAT_ARY_UNIT10_ARY = 14;
static const uint32_t CLOCK_STAT_ARY_UNIT11_ARY = 15;
static const uint32_t CLOCK_STAT_ARY_UNIT12_ARY = 16;
static const uint32_t CLOCK_STAT_ARY_UNIT13_ARY = 17;
static const uint32_t CLOCK_STAT_ARY_UNIT14_ARY = 18;
// pauc/reg00004.H

static const uint64_t EPS_THERM_WSUB_INJECT_REG = 0x10050011ull;

static const uint32_t EPS_THERM_WSUB_INJECT_REG_TRIP = 0;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_TRIP_LEN = 2;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_MODE = 2;
static const uint32_t EPS_THERM_WSUB_INJECT_REG_MODE_LEN = 2;
// pauc/reg00004.H

static const uint64_t OPCG_REG2 = 0x10030004ull;

static const uint32_t OPCG_REG2_OPCG_GO2 = 0;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING = 1;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING_LEN = 3;
static const uint32_t OPCG_REG2_PRPG_VALUE = 4;
static const uint32_t OPCG_REG2_PRPG_VALUE_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_A_VAL = 16;
static const uint32_t OPCG_REG2_PRPG_A_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_B_VAL = 28;
static const uint32_t OPCG_REG2_PRPG_B_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_MODE = 40;
static const uint32_t OPCG_REG2_SM_LBIST_CNTRL = 48;
static const uint32_t OPCG_REG2_SM_LBIST_CNTRL_LEN = 16;
// pauc/reg00004.H

static const uint64_t PB_TL_LINK_RT_DELAY_CTL_REG = 0x10011819ull;

static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET = 0;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN = 2;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET = 2;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN = 2;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT = 4;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN = 2;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT = 6;
static const uint32_t PB_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN = 2;
// pauc/reg00004.H

static const uint64_t PB_TL_LINK_SYN_23_REG = 0x10011813ull;
// pauc/reg00004.H

static const uint64_t PCB_OPCG_GO = 0x10030020ull;

static const uint32_t PCB_OPCG_GO_PCB_OPCGGO = 0;
// pauc/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t PPE_XIDBGINF = 0x1000001full;

static const uint32_t PPE_XIDBGINF_SRR0 = 0;
static const uint32_t PPE_XIDBGINF_SRR0_LEN = 30;
static const uint32_t PPE_XIDBGINF_LR = 32;
static const uint32_t PPE_XIDBGINF_LR_LEN = 32;
// pauc/reg00004.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t REGS_TX_IMPCAL_SWO2_PB = 0x800f3c001000003full;

static const uint32_t REGS_TX_IMPCAL_SWO2_PB_IN_VAL = 48;
static const uint32_t REGS_TX_IMPCAL_SWO2_PB_IN_VAL_LEN = 7;
static const uint32_t REGS_TX_IMPCAL_SWO2_PB_AX_VAL = 55;
static const uint32_t REGS_TX_IMPCAL_SWO2_PB_AX_VAL_LEN = 7;
// pauc/reg00004.H

static const uint64_t TRA0_TR0_TRACE_LO_DATA_REG = 0x10010401ull;

static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// pauc/reg00004.H

static const uint64_t TRA0_TR1_CONFIG_4 = 0x10010447ull;

static const uint32_t TRA0_TR1_CONFIG_4_A = 0;
static const uint32_t TRA0_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TRA0_TR1_CONFIG_4_B = 24;
static const uint32_t TRA0_TR1_CONFIG_4_B_LEN = 24;
// pauc/reg00004.H

static const uint64_t TRA1_TR0_CONFIG_2 = 0x10010485ull;

static const uint32_t TRA1_TR0_CONFIG_2_A = 0;
static const uint32_t TRA1_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_2_B = 24;
static const uint32_t TRA1_TR0_CONFIG_2_B_LEN = 24;
// pauc/reg00004.H

static const uint64_t XSTOP1 = 0x1003000cull;

static const uint32_t XSTOP1_XSTOP1_MASK_B = 0;
static const uint32_t XSTOP1_ALIGNED_XSTOP1 = 1;
static const uint32_t XSTOP1_TRIGGER_OPCG_ON_XSTOP1 = 2;
static const uint32_t XSTOP1_XSTOP1_WAIT_ALLWAYS = 3;
static const uint32_t XSTOP1_XSTOP1_PERV = 4;
static const uint32_t XSTOP1_XSTOP1_UNIT1 = 5;
static const uint32_t XSTOP1_XSTOP1_UNIT2 = 6;
static const uint32_t XSTOP1_XSTOP1_UNIT3 = 7;
static const uint32_t XSTOP1_XSTOP1_UNIT4 = 8;
static const uint32_t XSTOP1_XSTOP1_UNIT5 = 9;
static const uint32_t XSTOP1_XSTOP1_UNIT6 = 10;
static const uint32_t XSTOP1_XSTOP1_UNIT7 = 11;
static const uint32_t XSTOP1_XSTOP1_UNIT8 = 12;
static const uint32_t XSTOP1_XSTOP1_UNIT9 = 13;
static const uint32_t XSTOP1_XSTOP1_UNIT10 = 14;
static const uint32_t XSTOP1_XSTOP1_UNIT11 = 15;
static const uint32_t XSTOP1_XSTOP1_UNIT12 = 16;
static const uint32_t XSTOP1_XSTOP1_UNIT13 = 17;
static const uint32_t XSTOP1_XSTOP1_UNIT14 = 18;
static const uint32_t XSTOP1_XSTOP1_WAIT_CYCLES = 48;
static const uint32_t XSTOP1_XSTOP1_WAIT_CYCLES_LEN = 12;
// pauc/reg00004.H

}
}
#include "pauc/reg00004.H"
#endif
