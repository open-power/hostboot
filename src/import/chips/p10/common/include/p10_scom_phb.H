/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb.H $          */
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

#ifndef __phb_H_
#define __phb_H_


namespace scomt
{
namespace phb
{


//ERRCODE: // Some of the name targets not found in address targets.
// No targets could be determined from the address.

static const uint64_t ETUX08_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR = 0x08010d81ull;
// phb/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.
// No targets could be determined from the address.

static const uint64_t ETUX08_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PAST = 0x08010d83ull;
// phb/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.
// No targets could be determined from the address.

static const uint64_t ETUX16_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR = 0x08000d01ull;
// phb/reg00000.H

//ERRCODE: // Some of the name targets not found in address targets.
// No targets could be determined from the address.

static const uint64_t ETUX16_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PAST = 0x08000d03ull;
// phb/reg00000.H

}
}
#include "phb/reg00000.H"
#endif
