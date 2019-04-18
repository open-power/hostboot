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


static const uint64_t ETUX08_RSB_REGS_ACT0_REG = 0x0801090eull;
// phb/reg00229.H

static const uint64_t ETUX08_RSB_REGS_MASK_REG_RWX = 0x0801090bull;
static const uint64_t ETUX08_RSB_REGS_MASK_REG_WOX_AND = 0x0801090cull;
static const uint64_t ETUX08_RSB_REGS_MASK_REG_WOX_OR = 0x0801090dull;
// phb/reg00229.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ETUX16_RSB_REGS_PHB5_PMON_CONFIG = 0x00000917ull;
// phb/reg00229.H

}
}
#include "phb/reg00229.H"
#endif
