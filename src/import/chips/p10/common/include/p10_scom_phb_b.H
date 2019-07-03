/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_b.H $        */
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

#ifndef __p10_scom_phb_b_H_
#define __p10_scom_phb_b_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


static const uint64_t REGS_PE_SPARSE_PAGE_CNTL_REG = 0x03011856ull;

static const uint32_t REGS_PE_SPARSE_PAGE_CNTL_REG_FV = 3;
static const uint32_t REGS_PE_SPARSE_PAGE_CNTL_REG_T3 = 4;
static const uint32_t REGS_PE_SPARSE_PAGE_CNTL_REG_T4 = 5;
// phb/reg00011.H

static const uint64_t RSB_REGS_ACT0_REG = 0x0801090eull;
// phb/reg00011.H

static const uint64_t RSB_REGS_MASK_REG_RW = 0x0801090bull;
static const uint64_t RSB_REGS_MASK_REG_WO_AND = 0x0801090cull;
static const uint64_t RSB_REGS_MASK_REG_WO_OR = 0x0801090dull;
// phb/reg00011.H

#ifndef __PPE_HCODE__
}
}
#include "phb/reg00011.H"
#endif
#endif
