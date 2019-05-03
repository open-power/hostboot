/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_1.H $        */
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

#ifndef __p10_scom_phb_1_H_
#define __p10_scom_phb_1_H_


namespace scomt
{
namespace phb
{


static const uint64_t REGS_PBAIBTXCCR_REG = 0x0801084dull;

static const uint32_t REGS_PBAIBTXCCR_REG_0_CCA = 0;
static const uint32_t REGS_PBAIBTXCCR_REG_0_CCA_LEN = 3;
static const uint32_t REGS_PBAIBTXCCR_REG_0_CCR = 10;
static const uint32_t REGS_PBAIBTXCCR_REG_0_CCR_LEN = 6;
static const uint32_t REGS_PBAIBTXCCR_REG_1_CCA = 16;
static const uint32_t REGS_PBAIBTXCCR_REG_1_CCA_LEN = 3;
static const uint32_t REGS_PBAIBTXCCR_REG_1_CCR = 26;
static const uint32_t REGS_PBAIBTXCCR_REG_1_CCR_LEN = 6;
static const uint32_t REGS_PBAIBTXCCR_REG_2_CCA = 32;
static const uint32_t REGS_PBAIBTXCCR_REG_2_CCA_LEN = 3;
static const uint32_t REGS_PBAIBTXCCR_REG_2_CCR = 41;
static const uint32_t REGS_PBAIBTXCCR_REG_2_CCR_LEN = 7;
static const uint32_t REGS_PBAIBTXCCR_REG_3_CCA = 48;
static const uint32_t REGS_PBAIBTXCCR_REG_3_CCA_LEN = 3;
static const uint32_t REGS_PBAIBTXCCR_REG_3_CCR = 58;
static const uint32_t REGS_PBAIBTXCCR_REG_3_CCR_LEN = 6;
// phb/reg00001.H

static const uint64_t RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK = 0x08010907ull;

static const uint32_t RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE = 12;
static const uint32_t RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN = 40;
// phb/reg00001.H

static const uint64_t RSB_SCOM_SSR_PHB4_UVIAR = 0x08010902ull;

static const uint32_t RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD = 0;
static const uint32_t RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B = 1;
static const uint32_t RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC = 2;
static const uint32_t RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE = 51;
static const uint32_t RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE_LEN = 11;
// phb/reg00001.H

}
}
#include "phb/reg00001.H"
#endif
