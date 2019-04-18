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


static const uint64_t ETUX08_RSB_REGS_WOF_REG = 0x08010910ull;
// phb/reg00231.H

static const uint64_t ETUX08_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PAST = 0x08010915ull;
// phb/reg00231.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL = 0x00000905ull;

static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE = 0;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE = 1;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE = 2;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE = 3;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE = 4;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE = 5;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE = 6;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE = 7;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE = 8;
// phb/reg00231.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK = 0x00000907ull;

static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE = 12;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN = 40;
// phb/reg00231.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ETUX16_RSB_SCOM_SSR_PHB4_UVIAR = 0x00000902ull;

static const uint32_t ETUX16_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD = 0;
static const uint32_t ETUX16_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B = 1;
static const uint32_t ETUX16_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC = 2;
static const uint32_t ETUX16_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE = 51;
static const uint32_t ETUX16_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE_LEN = 11;
// phb/reg00231.H

}
}
#include "phb/reg00231.H"
#endif
