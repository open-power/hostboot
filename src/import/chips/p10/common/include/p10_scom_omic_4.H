/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_4.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __p10_scom_omic_4_H_
#define __p10_scom_omic_4_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> [CTL_REGS_TX_CNTL1_PG]
static const uint64_t CTL_REGS_TX_CNTL1_PG = 0x800c444010012c3full;

static const uint32_t CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL = 48;
static const uint32_t CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL_LEN = 3;
//<< [CTL_REGS_TX_CNTL1_PG]
// omic/reg00004.H

//>> [DATASM_REGS_RX_CNT11_PG]
static const uint64_t DATASM_REGS_RX_CNT11_PG = 0x8009d84010012c3full;

static const uint32_t DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15 = 48;
static const uint32_t DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15_LEN = 16;
//<< [DATASM_REGS_RX_CNT11_PG]
// omic/reg00004.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00004.H"
#endif
#endif
