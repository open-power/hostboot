/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_6.H $       */
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

#ifndef __p10_scom_omic_6_H_
#define __p10_scom_omic_6_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> [CTL_REGS_TX_CNTL4_PG]
static const uint64_t CTL_REGS_TX_CNTL4_PG = 0x800c5c4010012c3full;

static const uint32_t CTL_REGS_TX_CNTL4_PG_DAC_CNTL = 48;
static const uint32_t CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN = 8;
static const uint32_t CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE = 56;
static const uint32_t CTL_REGS_TX_CNTL4_PG_PHASE_SEL = 57;
//<< [CTL_REGS_TX_CNTL4_PG]
// omic/reg00006.H

//>> [CTL_REGS_RX_MODE16_PG]
static const uint64_t CTL_REGS_RX_MODE16_PG = 0x8008804010012c3full;

static const uint32_t CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 = 48;
static const uint32_t CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE16_PG_THRESH1 = 51;
static const uint32_t CTL_REGS_RX_MODE16_PG_THRESH1_LEN = 5;
static const uint32_t CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 = 56;
static const uint32_t CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE16_PG_THRESH2 = 59;
static const uint32_t CTL_REGS_RX_MODE16_PG_THRESH2_LEN = 5;
//<< [CTL_REGS_RX_MODE16_PG]
// omic/reg00006.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00006.H"
#endif
#endif
