/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_2.H $        */
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

#ifndef __p10_scom_omi_2_H_
#define __p10_scom_omi_2_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> [TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_STAT1_PL]
static const uint64_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_STAT1_PL = 0x8005244010012c3full;

static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ERR_DET_RO_SIGNAL = 48;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_STAT1_PL_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL = 49;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL = 50;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_STAT1_PL_SEG_TEST_STATUS_RO_SIGNAL_LEN = 2;
static const uint32_t TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_STAT1_PL_TDR_CAPT_VAL_RO_SIGNAL = 63;
//<< [TXPACKS_0_DEFAULT_DD_TX_BIT_REGS_STAT1_PL]
// omi/reg00005.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omi/reg00004.H"
#include "omi/reg00005.H"
#endif
#endif
