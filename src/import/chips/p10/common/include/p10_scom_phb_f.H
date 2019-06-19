/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_f.H $        */
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

#ifndef __p10_scom_phb_f_H_
#define __p10_scom_phb_f_H_


namespace scomt
{
namespace phb
{


static const uint64_t REGS_BARE_REG = 0x03011854ull;

static const uint32_t REGS_BARE_REG_MMIO_BAR0_EN = 0;
static const uint32_t REGS_BARE_REG_MMIO_BAR1_EN = 1;
static const uint32_t REGS_BARE_REG_PHB_BAR_EN = 2;
static const uint32_t REGS_BARE_REG_INT_BAR_EN = 3;
// phb/reg00015.H

static const uint64_t REGS_MMIOBAR0_REG = 0x0301184eull;

static const uint32_t REGS_MMIOBAR0_REG_PE_MMIO_BAR0 = 0;
static const uint32_t REGS_MMIOBAR0_REG_PE_MMIO_BAR0_LEN = 40;
// phb/reg00015.H

static const uint64_t REGS_MMIOBAR1_REG = 0x03011850ull;

static const uint32_t REGS_MMIOBAR1_REG_PE_MMIO_BAR1 = 0;
static const uint32_t REGS_MMIOBAR1_REG_PE_MMIO_BAR1_LEN = 40;
// phb/reg00015.H

static const uint64_t REGS_PBAIBTXDCR_REG = 0x0801084eull;

static const uint32_t REGS_PBAIBTXDCR_REG_A = 33;
static const uint32_t REGS_PBAIBTXDCR_REG_A_LEN = 2;
static const uint32_t REGS_PBAIBTXDCR_REG_R = 44;
static const uint32_t REGS_PBAIBTXDCR_REG_R_LEN = 4;
// phb/reg00015.H

}
}
#ifndef __PPE_HCODE__
    #include "phb/reg00015.H"
#endif
#endif
