/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_5.H $        */
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

#ifndef __p10_scom_omi_5_H_
#define __p10_scom_omi_5_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> [TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL]
static const uint64_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL = 0x80042c4010012c3full;

static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN = 52;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN = 53;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL = 55;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL_LEN = 3;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL = 58;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL_LEN = 3;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL = 61;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL_LEN = 2;
//<< [TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE3_PL]
// omi/reg00011.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omi/reg00010.H"
#include "omi/reg00011.H"
#endif
#endif
