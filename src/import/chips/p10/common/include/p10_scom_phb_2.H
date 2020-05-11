/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_phb_2.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __p10_scom_phb_2_H_
#define __p10_scom_phb_2_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace phb
{
#endif


//>> [REGS_CERR_RPT0_REG]
static const uint64_t REGS_CERR_RPT0_REG = 0x0301184aull;

static const uint32_t REGS_CERR_RPT0_REG_CERR_RPT0 = 0;
static const uint32_t REGS_CERR_RPT0_REG_CERR_RPT0_LEN = 64;
//<< [REGS_CERR_RPT0_REG]
// phb/reg00002.H

//>> [REGS_CERR_RPT1_REG]
static const uint64_t REGS_CERR_RPT1_REG = 0x0301184bull;

static const uint32_t REGS_CERR_RPT1_REG_CERR_RPT1 = 0;
static const uint32_t REGS_CERR_RPT1_REG_CERR_RPT1_LEN = 42;
//<< [REGS_CERR_RPT1_REG]
// phb/reg00002.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "phb/reg00002.H"
#endif
#endif
