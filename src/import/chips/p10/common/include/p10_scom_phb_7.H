/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_7.H $        */
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

#ifndef __p10_scom_phb_7_H_
#define __p10_scom_phb_7_H_


namespace scomt
{
namespace phb
{


static const uint64_t REGS_MMIOBAR1_MASK_REG = 0x03011851ull;

static const uint32_t REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1 = 0;
static const uint32_t REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1_LEN = 40;
// phb/reg00007.H

static const uint64_t REGS_PBAIB_CERR_RPT_REG = 0x0801084bull;

static const uint32_t REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0 = 0;
static const uint32_t REGS_PBAIB_CERR_RPT_REG_PBAIB_CERR_RPT0_LEN = 21;
// phb/reg00007.H

static const uint64_t REGS_PE_CACHE_INJECT_CNTL_REG = 0x03011857ull;

static const uint32_t REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION = 0;
static const uint32_t REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_PARTIAL_CACHE_INJECTION_ON_HINT = 1;
static const uint32_t REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_PARTIAL_CACHE_INJECTION = 2;
static const uint32_t REGS_PE_CACHE_INJECT_CNTL_REG_STALL_PARTIAL_CACHE_INJECTION_ON_THRESHOLD = 3;
static const uint32_t REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION = 4;
static const uint32_t REGS_PE_CACHE_INJECT_CNTL_REG_ENABLE_FULL_CACHE_INJECTION_ON_HINT = 5;
static const uint32_t REGS_PE_CACHE_INJECT_CNTL_REG_SET_D_BIT_ON_FULL_CACHE_INJECTION = 6;
static const uint32_t REGS_PE_CACHE_INJECT_CNTL_REG_STALL_FULL_CACHE_INJECTION_ON_THRESHOLD = 7;
// phb/reg00007.H

static const uint64_t RSB_REGS_PHB5_PMON_COUNTERS = 0x08010919ull;
// phb/reg00007.H

}
}
#include "phb/reg00007.H"
#endif
