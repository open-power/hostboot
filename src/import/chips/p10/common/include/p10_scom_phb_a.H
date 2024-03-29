/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_a.H $        */
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

#ifndef __p10_scom_phb_a_H_
#define __p10_scom_phb_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


//>> [REGS_CQSTAT_REG]
static const uint64_t REGS_CQSTAT_REG = 0x0301184cull;

static const uint32_t REGS_CQSTAT_REG_INBOUND_ACTIVE = 0;
static const uint32_t REGS_CQSTAT_REG_OUTBOUND_ACTIVE = 1;
//<< [REGS_CQSTAT_REG]
// phb/reg00010.H

//>> [REGS_NFIRMASK_REG]
static const uint64_t REGS_NFIRMASK_REG_RW = 0x03011843ull;
static const uint64_t REGS_NFIRMASK_REG_WO_AND = 0x03011844ull;
static const uint64_t REGS_NFIRMASK_REG_WO_OR = 0x03011845ull;

static const uint32_t REGS_NFIRMASK_REG_NFIRMASK = 0;
static const uint32_t REGS_NFIRMASK_REG_NFIRMASK_LEN = 28;
//<< [REGS_NFIRMASK_REG]
// phb/reg00010.H

//>> [REGS_PHBBAR_REG]
static const uint64_t REGS_PHBBAR_REG = 0x03011852ull;

static const uint32_t REGS_PHBBAR_REG_PE_PHB_BAR = 0;
static const uint32_t REGS_PHBBAR_REG_PE_PHB_BAR_LEN = 42;
//<< [REGS_PHBBAR_REG]
// phb/reg00010.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "phb/reg00010.H"
#endif
#endif
