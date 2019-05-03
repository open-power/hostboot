/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_2.H $        */
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

#ifndef __p10_scom_phb_2_H_
#define __p10_scom_phb_2_H_


namespace scomt
{
namespace phb
{


static const uint64_t REGS_CERR_RPT0_REG = 0x0301184aull;

static const uint32_t REGS_CERR_RPT0_REG_CERR_RPT0 = 0;
static const uint32_t REGS_CERR_RPT0_REG_CERR_RPT0_LEN = 64;
// phb/reg00002.H

static const uint64_t REGS_CERR_RPT1_REG = 0x0301184bull;

static const uint32_t REGS_CERR_RPT1_REG_CERR_RPT1 = 0;
static const uint32_t REGS_CERR_RPT1_REG_CERR_RPT1_LEN = 41;
// phb/reg00002.H

static const uint64_t RSB_SCOM_SSR_PHB4_HVIAR = 0x08010900ull;

static const uint32_t RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VLD = 0;
static const uint32_t RSB_SCOM_SSR_PHB4_HVIAR_REQ_4B = 1;
static const uint32_t RSB_SCOM_SSR_PHB4_HVIAR_AUTO_INC = 2;
static const uint32_t RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE = 51;
static const uint32_t RSB_SCOM_SSR_PHB4_HVIAR_REQ_ADDR_VALUE_LEN = 11;
// phb/reg00002.H

}
}
#include "phb/reg00002.H"
#endif
