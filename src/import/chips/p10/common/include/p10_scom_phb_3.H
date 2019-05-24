/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_3.H $        */
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

#ifndef __p10_scom_phb_3_H_
#define __p10_scom_phb_3_H_


namespace scomt
{
namespace phb
{


static const uint64_t REGS_NFIRACTION0_REG = 0x03011846ull;

static const uint32_t REGS_NFIRACTION0_REG_NFIRACTION0 = 0;
static const uint32_t REGS_NFIRACTION0_REG_NFIRACTION0_LEN = 28;
// phb/reg00003.H

static const uint64_t REGS_NFIRACTION1_REG = 0x03011847ull;

static const uint32_t REGS_NFIRACTION1_REG_NFIRACTION1 = 0;
static const uint32_t REGS_NFIRACTION1_REG_NFIRACTION1_LEN = 28;
// phb/reg00003.H

static const uint64_t REGS_RESERVED1_REG = 0x0801084cull;
// phb/reg00003.H

static const uint64_t RSB_REGS_WOF_REG = 0x08010910ull;
// phb/reg00003.H

static const uint64_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR = 0x08010913ull;

static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_LINK_POPULATED = 0;
static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN = 5;
static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_GEN_LEN = 3;
static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE = 8;
static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_PCI_SIZE_LEN = 2;
static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_FREEZE_INFO = 11;
// phb/reg00003.H

}
}
#include "phb/reg00003.H"
#endif
