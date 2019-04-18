/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_a.H $        */
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

#ifndef __p10_scom_phb_a_H_
#define __p10_scom_phb_a_H_


namespace scomt
{
namespace phb
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ETUX16_RSB_REGS_ACT0_REG = 0x0000090eull;
// phb/reg00238.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ETUX16_RSB_REGS_MASK_REG_RWX = 0x0000090bull;
static const uint64_t ETUX16_RSB_REGS_MASK_REG_WOX_AND = 0x0000090cull;
static const uint64_t ETUX16_RSB_REGS_MASK_REG_WOX_OR = 0x0000090dull;
// phb/reg00238.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP = 0x00000906ull;

static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE = 0;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE = 12;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN = 40;
// phb/reg00238.H

}
}
#include "phb/reg00238.H"
#endif
