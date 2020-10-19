/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_8.H $        */
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

#ifndef __p10_scom_omi_8_H_
#define __p10_scom_omi_8_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> [RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL]
static const uint64_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL = 0x8000184010012c3full;

static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO = 51;
static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL_ZERO_LEN = 3;
//<< [RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL3_PL]
// omi/reg00016.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omi/reg00016.H"
#include "omi/reg00017.H"
#endif
#endif
