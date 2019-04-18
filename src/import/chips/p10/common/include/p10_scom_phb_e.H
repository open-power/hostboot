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


static const uint64_t ETUX08_RSB_SCOM_SSR_PHB4_UVIAR = 0x08010902ull;

static const uint32_t ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VLD = 0;
static const uint32_t ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_4B = 1;
static const uint32_t ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_AUTO_INC = 2;
static const uint32_t ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE = 51;
static const uint32_t ETUX08_RSB_SCOM_SSR_PHB4_UVIAR_REQ_ADDR_VALUE_LEN = 11;
// phb/reg00242.H

}
}
#include "phb/reg00242.H"
#endif
