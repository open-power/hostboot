/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_4.H $        */
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

#ifndef __p10_scom_phb_4_H_
#define __p10_scom_phb_4_H_


namespace scomt
{
namespace phb
{


static const uint64_t REGS_NFIR_REG_RW = 0x03011840ull;
static const uint64_t REGS_NFIR_REG_WO_AND = 0x03011841ull;
static const uint64_t REGS_NFIR_REG_WO_OR = 0x03011842ull;

static const uint32_t REGS_NFIR_REG_NFIRNFIR = 0;
static const uint32_t REGS_NFIR_REG_NFIRNFIR_LEN = 28;
// phb/reg00004.H

static const uint64_t RSB_REGS_PHB5_PMON_EVENT_SEL = 0x08010918ull;
// phb/reg00004.H

}
}
#ifndef __PPE_HCODE__
    #include "phb/reg00004.H"
#endif
#endif
