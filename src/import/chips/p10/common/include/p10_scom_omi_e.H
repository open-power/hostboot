/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_e.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __p10_scom_omi_e_H_
#define __p10_scom_omi_e_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> [TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL]
static const uint64_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL = 0x80041c4010012c3full;

static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 48;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 49;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN = 51;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN = 52;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 53;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 54;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 55;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
//<< [TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_MODE1_PL]
// omi/reg00029.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omi/reg00028.H"
#include "omi/reg00029.H"
#endif
#endif
