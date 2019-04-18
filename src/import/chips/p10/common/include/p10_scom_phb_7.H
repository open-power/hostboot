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


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL = 0x00000904ull;

static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_ENABLE = 0;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_CMP_VALUE = 12;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_CMP_VALUE_LEN = 8;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_MSK_VALUE = 44;
static const uint32_t ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_MSK_VALUE_LEN = 8;
// phb/reg00235.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t ETUX16_RSB_REGS_WOF_REG = 0x00000910ull;
// phb/reg00235.H

}
}
#include "phb/reg00235.H"
#endif
