/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_d.H $        */
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

#ifndef __p10_scom_phb_d_H_
#define __p10_scom_phb_d_H_


namespace scomt
{
namespace phb
{


static const uint64_t REGS_PE_DFREEZE_REG = 0x03011855ull;

static const uint32_t REGS_PE_DFREEZE_REG_PE_DFREEZE = 0;
static const uint32_t REGS_PE_DFREEZE_REG_PE_DFREEZE_LEN = 28;
// phb/reg00013.H

static const uint64_t REGS_PFIR_REG_RWX = 0x08010840ull;
static const uint64_t REGS_PFIR_REG_WOX_AND = 0x08010841ull;
static const uint64_t REGS_PFIR_REG_WOX_OR = 0x08010842ull;

static const uint32_t REGS_PFIR_REG_PFIRPFIR = 0;
static const uint32_t REGS_PFIR_REG_PFIRPFIR_LEN = 6;
// phb/reg00013.H

}
}
#include "phb/reg00013.H"
#endif
