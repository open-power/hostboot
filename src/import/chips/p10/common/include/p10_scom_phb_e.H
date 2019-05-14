/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_e.H $        */
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

#ifndef __p10_scom_phb_e_H_
#define __p10_scom_phb_e_H_


namespace scomt
{
namespace phb
{


static const uint64_t REGS_INTBAR_REG = 0x03011853ull;

static const uint32_t REGS_INTBAR_REG_PE_INT_BAR = 0;
static const uint32_t REGS_INTBAR_REG_PE_INT_BAR_LEN = 28;
// phb/reg00014.H

static const uint64_t REGS_PHBRESET_REG = 0x0801084aull;

static const uint32_t REGS_PHBRESET_REG_PE_ETU_RESET = 0;
// phb/reg00014.H

static const uint64_t RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL = 0x08010904ull;

static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_ENABLE = 0;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE = 12;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_CMP_VALUE_LEN = 8;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE = 44;
static const uint32_t RSB_REGS_UVI_PHB5_SCOM_UV_SEC_EXCL_MSK_VALUE_LEN = 8;
// phb/reg00014.H

static const uint64_t RSB_SCOM_SSR_PHB5_UVIAR = 0x08010902ull;

static const uint32_t RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VLD = 0;
static const uint32_t RSB_SCOM_SSR_PHB5_UVIAR_REQ_4B = 1;
static const uint32_t RSB_SCOM_SSR_PHB5_UVIAR_AUTO_INC = 2;
static const uint32_t RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE = 51;
static const uint32_t RSB_SCOM_SSR_PHB5_UVIAR_REQ_ADDR_VALUE_LEN = 11;
// phb/reg00014.H

}
}
#include "phb/reg00014.H"
#endif
