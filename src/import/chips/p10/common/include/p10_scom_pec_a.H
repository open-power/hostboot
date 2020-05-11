/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_a.H $        */
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

#ifndef __p10_scom_pec_a_H_
#define __p10_scom_pec_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


//>> [CLOCK_STAT_SL]
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
//<< [CLOCK_STAT_SL]
// pec/reg00010.H

//>> [CPLT_CTRL3]
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
//<< [CPLT_CTRL3]
// pec/reg00010.H

//>> [PB_PBAIB_REGS_PBAIBHWCFG_REG]
static const uint64_t PB_PBAIB_REGS_PBAIBHWCFG_REG = 0x08010800ull;

static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_RESERVED0 = 0;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_RESERVED0_LEN = 16;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_OSMB_DATASTART_MODE = 16;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_OSMB_DATASTART_MODE_LEN = 3;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_RESERVED1 = 19;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_TX_RESP_HWM = 20;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_TX_RESP_HWM_LEN = 4;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_TX_RESP_LWM = 24;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_TX_RESP_LWM_LEN = 4;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_OSMB_EARLYEMPTY_MODE = 28;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_OSMB_EARLYEMPTY_MODE_LEN = 2;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_PCIE_CLK_TRACE_EN = 30;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_PCIE_CLK_TRACE_STACK = 31;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_PCIE_CLK_TRACE_STACK_LEN = 2;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_RESERVED3 = 33;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_ISMB_ERROR_INJECT_STACK = 34;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_ISMB_ERROR_INJECT_STACK_LEN = 2;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_ISMB_ERROR_INJECT = 36;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_ISMB_ERROR_INJECT_LEN = 3;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_ISMB_CONSTANT_ERROR_INJECT = 39;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_OSMB_HOL_BLK_CNT = 40;
static const uint32_t PB_PBAIB_REGS_PBAIBHWCFG_REG_PE_OSMB_HOL_BLK_CNT_LEN = 3;
//<< [PB_PBAIB_REGS_PBAIBHWCFG_REG]
// pec/reg00010.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pec/reg00010.H"
#endif
#endif
