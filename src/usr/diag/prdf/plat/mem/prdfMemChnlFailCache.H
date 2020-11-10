/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemChnlFailCache.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
#include <map>
#include <targeting/common/targetservice.H>

#ifndef __prdfMemChnlFailCache_H
#define __prdfMemChnlFailCache_H

namespace PRDF
{

typedef std::map<TARGETING::TYPE, std::vector<uint64_t>> TargetScoms_t;

TargetScoms_t chnlFailScomList =
{
    {
        TARGETING::TYPE_OCMB_CHIP,
        { // SCOMs
            0x08040000, // OCMB_CHIPLET_CS_FIR
            0x08040001, // OCMB_CHIPLET_RE_FIR
            0x08040002, // OCMB_CHIPLET_FIR_MASK
            0x08040004, // OCMB_CHIPLET_SPA_FIR
            0x08040007, // OCMB_CHIPLET_SPA_FIR_MASK
            0x0804000a, // OCMB_LFIR
            0x0804000d, // OCMB_LFIR_MASK
            0x08040010, // OCMB_LFIR_ACT0
            0x08040011, // OCMB_LFIR_ACT1
            0x08010870, // MMIOFIR
            0x08010873, // MMIOFIR_MASK
            0x08010876, // MMIOFIR_ACT0
            0x08010877, // MMIOFIR_ACT1
            0x08011400, // SRQFIR
            0x08011403, // SRQFIR_MASK
            0x08011406, // SRQFIR_ACT0
            0x08011407, // SRQFIR_ACT1
            0x08011800, // MCBISTFIR
            0x08011803, // MCBISTFIR_MASK
            0x08011806, // MCBISTFIR_ACT0
            0x08011807, // MCBISTFIR_ACT1
            0x08011c00, // RDFFIR
            0x08011c03, // RDFFIR_MASK
            0x08011c06, // RDFFIR_ACT0
            0x08011c07, // RDFFIR_ACT1
            0x08012400, // TLXFIR
            0x08012403, // TLXFIR_MASK
            0x08012406, // TLXFIR_ACT0
            0x08012407, // TLXFIR_ACT1
            0x08012800, // OMIDLFIR
            0x08012803, // OMIDLFIR_MASK
            0x08012806, // OMIDLFIR_ACT0
            0x08012807, // OMIDLFIR_ACT1
            0x08011858, // OCMB_MBSSYMEC0
            0x08011859, // OCMB_MBSSYMEC1
            0x0801185A, // OCMB_MBSSYMEC2
            0x0801185B, // OCMB_MBSSYMEC3
            0x0801185C, // OCMB_MBSSYMEC4
            0x0801185D, // OCMB_MBSSYMEC5
            0x0801185E, // OCMB_MBSSYMEC6
            0x0801185F, // OCMB_MBSSYMEC7
            0x08011860, // OCMB_MBSSYMEC8
            0x0801187E, // MBSEVR0
            0x08011855, // MBSEC0
            0x08011856, // MBSEC1
            0x08011869, // MBSMSEC
            0x08011857, // MBSTR
            0x080118D6, // MCBAGRA
            0x080118D7, // MCBMCAT
            0x080118DB, // MCB_CNTL
            0x080118DC, // MCB_CNTLSTAT
            0x08011C10, // HW_MS0
            0x08011C11, // HW_MS1
            0x08011C12, // HW_MS2
            0x08011C13, // HW_MS3
            0x08011C14, // HW_MS4
            0x08011C15, // HW_MS5
            0x08011C16, // HW_MS6
            0x08011C17, // HW_MS7
            0x08011C18, // FW_MS0
            0x08011C19, // FW_MS1
            0x08011C1A, // FW_MS2
            0x08011C1B, // FW_MS3
            0x08011C1C, // FW_MS4
            0x08011C1D, // FW_MS5
            0x08011C1E, // FW_MS6
            0x08011C1F, // FW_MS7
            0x0801241C, // TLX_ERR0_REPORT
            0x0801241D, // TLX_ERR1_REPORT
            0x08012414, // TLX_ERR0_REPORT_MASK
            0x08012415, // TLX_ERR1_REPORT_MASK
            0x0801186A, // MBNCER
            0x0801186B, // MBRCER
            0x0801186C, // MBMPER
            0x0801186D, // MBUER
            0x0801186E, // MBAUER
            0x08011415, // FARB0
            0x08011C0C, // EXP_MSR
            0x0801186F, // MC_ADDR_TRANS
            0x08011870, // MC_ADDR_TRANS1
            0x08011871, // MC_ADDR_TRANS2
        }
    }
};

} // namespace PRDF

#endif // __prdfMemChnlFailCache_H
