/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_8.H $        */
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

#ifndef __p10_scom_phb_8_H_
#define __p10_scom_phb_8_H_


namespace scomt
{
namespace phb
{


static const uint64_t REGS_PFIRMASK_REG_RW = 0x08010843ull;
static const uint64_t REGS_PFIRMASK_REG_WO_AND = 0x08010844ull;
static const uint64_t REGS_PFIRMASK_REG_WO_OR = 0x08010845ull;

static const uint32_t REGS_PFIRMASK_REG_PFIRMASK = 0;
static const uint32_t REGS_PFIRMASK_REG_PFIRMASK_LEN = 6;
// phb/reg00008.H

static const uint64_t REGS_PFIRWOF_REG = 0x08010848ull;
// phb/reg00008.H

static const uint64_t RSB_REGS_ACTION1_REG = 0x0801090full;
// phb/reg00008.H

static const uint64_t RSB_REGS_UVI_PHB5_SCOM_UV_SEC_INCL_CMP = 0x08010906ull;

static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_SEC_INCL_CMP_ENABLE = 0;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_SEC_INCL_CMP_VALUE = 12;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_SEC_INCL_CMP_VALUE_LEN = 40;
// phb/reg00008.H

}
}
#ifndef __PPE_HCODE__
    #include "phb/reg00008.H"
#endif
#endif
