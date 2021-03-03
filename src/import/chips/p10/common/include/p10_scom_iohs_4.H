/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_4.H $       */
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

#ifndef __p10_scom_iohs_4_H_
#define __p10_scom_iohs_4_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]
static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG = 0x800c0c0010012c3full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_RCTRL = 49;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_16TO1 = 50;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_DCC_EN = 54;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_LS_EN = 55;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_BIST_HS_EN = 56;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC = 57;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC_LEN = 3;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC = 60;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC_LEN = 2;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_BYPASS = 62;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG_IREF_PDWN_B = 63;
//<< [IOO_TX0_TXCTL_CTL_REGS_TX_MODE1_PG]
// iohs/reg00019.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00016.H"
#include "iohs/reg00017.H"
#include "iohs/reg00018.H"
#include "iohs/reg00019.H"
#endif
#endif
