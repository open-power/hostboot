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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_phb_3_H_
#define __p10_scom_phb_3_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


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

static const uint32_t RSB_REGS_WOF_REG_AIB_COMMAND_INVALID = 0;
static const uint32_t RSB_REGS_WOF_REG_AIB_ADDRESSING_ERROR = 1;
static const uint32_t RSB_REGS_WOF_REG_AIB_ACCESS_ERROR = 2;
static const uint32_t RSB_REGS_WOF_REG_PAPR_OUTBOUND_INJECTION_ERROR_TRIGGERED = 3;
static const uint32_t RSB_REGS_WOF_REG_AIB_FATAL_CLASS_ERROR = 4;
static const uint32_t RSB_REGS_WOF_REG_AIB_INF_CLASS_ERROR = 5;
static const uint32_t RSB_REGS_WOF_REG_PE_STOP_STATE_ERROR = 6;
static const uint32_t RSB_REGS_WOF_REG_AIB_DAT_ERR_SIGNALED = 7;
static const uint32_t RSB_REGS_WOF_REG_OUT_COMMON_ARRAY_FATAL_ERROR = 8;
static const uint32_t RSB_REGS_WOF_REG_OUT_COMMON_LATCH_FATAL_ERROR = 9;
static const uint32_t RSB_REGS_WOF_REG_OUT_COMMON_LOGIC_FATAL_ERROR = 10;
static const uint32_t RSB_REGS_WOF_REG_BLIF_OUT_INTERFACE_PARITY_ERROR = 11;
static const uint32_t RSB_REGS_WOF_REG_PCIE_CFG_WRITE_CA_OR_UR_RESPONSE = 12;
static const uint32_t RSB_REGS_WOF_REG_MMIO_REQUEST_TIMEOUT = 13;
static const uint32_t RSB_REGS_WOF_REG_OUT_RRB_SOURCED_ERROR = 14;
static const uint32_t RSB_REGS_WOF_REG_CFG_LOGIC_SIGNALED_ERROR = 15;
static const uint32_t RSB_REGS_WOF_REG_RSB_REG_REQUEST_ADDRESS_ERROR = 16;
static const uint32_t RSB_REGS_WOF_REG_RSB_FDA_FATAL_ERROR = 17;
static const uint32_t RSB_REGS_WOF_REG_RSB_FDA_INF_ERROR = 18;
static const uint32_t RSB_REGS_WOF_REG_RSB_FDB_FATAL_ERROR = 19;
static const uint32_t RSB_REGS_WOF_REG_RSB_FDB_INF_ERROR = 20;
static const uint32_t RSB_REGS_WOF_REG_RSB_ERR_FATAL_ERROR = 21;
static const uint32_t RSB_REGS_WOF_REG_RSB_ERR_INF_ERROR = 22;
static const uint32_t RSB_REGS_WOF_REG_RSB_DBG_FATAL_ERROR = 23;
static const uint32_t RSB_REGS_WOF_REG_RSB_DBG_INF_ERROR = 24;
static const uint32_t RSB_REGS_WOF_REG_RSB_PCIE_REQUEST_ACCESS_ERROR = 25;
static const uint32_t RSB_REGS_WOF_REG_RSB_BUS_LOGIC_ERROR = 26;
static const uint32_t RSB_REGS_WOF_REG_RSB_UVI_FATAL_ERROR = 27;
static const uint32_t RSB_REGS_WOF_REG_RSB_UVI_INF_ERROR = 28;
static const uint32_t RSB_REGS_WOF_REG_SCOM_FATAL_ERROR = 29;
static const uint32_t RSB_REGS_WOF_REG_SCOM_INF_ERROR = 30;
static const uint32_t RSB_REGS_WOF_REG_PCIE_MACRO_ERROR_ACTIVE_STATUS = 31;
static const uint32_t RSB_REGS_WOF_REG_ARB_IODA_FATAL_ERROR = 32;
static const uint32_t RSB_REGS_WOF_REG_ARB_MSI_PE_MATCH_ERROR = 33;
static const uint32_t RSB_REGS_WOF_REG_ARB_MSI_ADDRESS_ERROR = 34;
static const uint32_t RSB_REGS_WOF_REG_ARB_TVT_ERROR = 35;
static const uint32_t RSB_REGS_WOF_REG_ARB_RCVD_FATAL_ERROR_MSG = 36;
static const uint32_t RSB_REGS_WOF_REG_ARB_RCVD_NONFATAL_ERROR_MSG = 37;
static const uint32_t RSB_REGS_WOF_REG_ARB_RCVD_CORRECTIBLE_ERROR_MSG = 38;
static const uint32_t RSB_REGS_WOF_REG_PAPR_INBOUND_INJECTION_ERROR_TRIGGERED = 39;
static const uint32_t RSB_REGS_WOF_REG_ARB_COMMON_FATAL_ERROR = 40;
static const uint32_t RSB_REGS_WOF_REG_ARB_TABLE_BAR_DISABLED_ERROR = 41;
static const uint32_t RSB_REGS_WOF_REG_ARB_BLIF_COMPLETION_ERROR = 42;
static const uint32_t RSB_REGS_WOF_REG_ARB_PCT_TIMEOUT_ERROR = 43;
static const uint32_t RSB_REGS_WOF_REG_ARB_ECC_CORRECTABLE_ERROR = 44;
static const uint32_t RSB_REGS_WOF_REG_ARB_ECC_UNCORRECTABLE_ERROR = 45;
static const uint32_t RSB_REGS_WOF_REG_ARB_TLP_POISON_SIGNALED = 46;
static const uint32_t RSB_REGS_WOF_REG_ARB_RTT_PENUM_INVALID_ERROR = 47;
static const uint32_t RSB_REGS_WOF_REG_MRG_COMMON_FATAL_ERROR = 48;
static const uint32_t RSB_REGS_WOF_REG_MRG_TABLE_BAR_DISABLED_ERROR = 49;
static const uint32_t RSB_REGS_WOF_REG_MRG_ECC_CORRECTABLE_ERROR = 50;
static const uint32_t RSB_REGS_WOF_REG_MRG_ECC_UNCORRECTABLE_ERROR = 51;
static const uint32_t RSB_REGS_WOF_REG_MRG_AIB2_TX_TIMEOUT_ERROR = 52;
static const uint32_t RSB_REGS_WOF_REG_MRG_MRT_ERROR = 53;
static const uint32_t RSB_REGS_WOF_REG_MRG_RESERVED01 = 54;
static const uint32_t RSB_REGS_WOF_REG_MRG_RESERVED02 = 55;
static const uint32_t RSB_REGS_WOF_REG_TCE_IODA_PAGE_ACCESS_ERROR = 56;
static const uint32_t RSB_REGS_WOF_REG_TCE_REQUEST_TIMEOUT_ERROR = 57;
static const uint32_t RSB_REGS_WOF_REG_TCE_UNEXPECTED_RESPONSE_ERROR = 58;
static const uint32_t RSB_REGS_WOF_REG_TCE_COMMON_FATAL_ERRORS = 59;
static const uint32_t RSB_REGS_WOF_REG_TCE_ECC_CORRECTABLE_ERROR = 60;
static const uint32_t RSB_REGS_WOF_REG_TCE_ECC_UNCORRECTABLE_ERROR = 61;
static const uint32_t RSB_REGS_WOF_REG_TCE_RESERVED01 = 62;
static const uint32_t RSB_REGS_WOF_REG_LEM_FIR_INTERNAL_PARITY_ERROR = 63;
// phb/reg00003.H

static const uint64_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR = 0x08010913ull;

static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_PHB5_DLR_PASR_DL_LINK_POPULATED = 0;
static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_SPARE_4 = 4;
static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_PHB5_DLR_PASR_DL_PCI_GEN = 5;
static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_PHB5_DLR_PASR_DL_PCI_GEN_LEN = 3;
static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_PHB5_DLR_PASR_DL_PCI_SIZE = 8;
static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_PHB5_DLR_PASR_DL_PCI_SIZE_LEN = 2;
static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_DL_ENABLE = 10;
static const uint32_t RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR_PHB5_DLR_PASR_FREEZE_INFO = 11;
// phb/reg00003.H

#ifndef __PPE_HCODE__
}
}
#include "phb/reg00003.H"
#endif
#endif
