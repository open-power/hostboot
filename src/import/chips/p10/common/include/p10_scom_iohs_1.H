/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_1.H $       */
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

#ifndef __p10_scom_iohs_1_H_
#define __p10_scom_iohs_1_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL]
static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL = 0x8000300010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN = 4;
//<< [IOO_RX0_0_RD_RX_DAC_REGS_CNTL6_PL]
// iohs/reg00004.H

//>> [IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG]
static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG = 0x800c6c0010012c3full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH_LEN = 9;
//<< [IOO_TX0_TXCTL_CTL_REGS_TX_CNTL6_PG]
// iohs/reg00007.H

//>> [IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG]
static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG = 0x800ccc0010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN = 8;
//<< [IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG]
// iohs/reg00007.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00004.H"
#include "iohs/reg00005.H"
#include "iohs/reg00006.H"
#include "iohs/reg00007.H"
#endif
#endif
