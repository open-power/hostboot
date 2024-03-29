/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_9.H $        */
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

#ifndef __p10_scom_omi_9_H_
#define __p10_scom_omi_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> [EDPL_MAX_COUNT]
static const uint64_t EDPL_MAX_COUNT = 0x0c011415ull;

static const uint32_t EDPL_MAX_COUNT_7_MAX_COUNT = 0;
static const uint32_t EDPL_MAX_COUNT_7_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_6_MAX_COUNT = 8;
static const uint32_t EDPL_MAX_COUNT_6_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_5_MAX_COUNT = 16;
static const uint32_t EDPL_MAX_COUNT_5_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_4_MAX_COUNT = 24;
static const uint32_t EDPL_MAX_COUNT_4_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_3_MAX_COUNT = 32;
static const uint32_t EDPL_MAX_COUNT_3_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_2_MAX_COUNT = 40;
static const uint32_t EDPL_MAX_COUNT_2_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_1_MAX_COUNT = 48;
static const uint32_t EDPL_MAX_COUNT_1_MAX_COUNT_LEN = 8;
static const uint32_t EDPL_MAX_COUNT_0_MAX_COUNT = 56;
static const uint32_t EDPL_MAX_COUNT_0_MAX_COUNT_LEN = 8;
//<< [EDPL_MAX_COUNT]
// omi/reg00018.H

//>> [RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL]
static const uint64_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL = 0x8000684010012c3full;

static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN = 48;
static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1 = 52;
static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN = 4;
static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2 = 56;
static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN = 4;
//<< [RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL13_PL]
// omi/reg00019.H

//>> [TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL]
static const uint64_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL = 0x8004444010012c3full;

static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE = 54;
//<< [TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_CNTL3_PL]
// omi/reg00019.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omi/reg00018.H"
#include "omi/reg00019.H"
#endif
#endif
