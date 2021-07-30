/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_d.H $       */
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

#ifndef __p10_scom_iohs_d_H_
#define __p10_scom_iohs_d_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_LINK1_QUALITY]
static const uint64_t DLP_LINK1_QUALITY = 0x18011027ull;

static const uint32_t DLP_LINK1_QUALITY_TX_BW = 1;
static const uint32_t DLP_LINK1_QUALITY_TX_BW_LEN = 11;
static const uint32_t DLP_LINK1_QUALITY_RX_BW = 13;
static const uint32_t DLP_LINK1_QUALITY_RX_BW_LEN = 11;
static const uint32_t DLP_LINK1_QUALITY_ERROR_RATE = 25;
static const uint32_t DLP_LINK1_QUALITY_ERROR_RATE_LEN = 23;
static const uint32_t DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3 = 48;
static const uint32_t DLP_LINK1_QUALITY_LINK_CAP_SLECC_SYN3_LEN = 8;
static const uint32_t DLP_LINK1_QUALITY_SPARE_COUNTER_2 = 57;
static const uint32_t DLP_LINK1_QUALITY_SPARE_COUNTER_2_LEN = 7;
//<< [DLP_LINK1_QUALITY]
// iohs/reg00058.H

//>> [IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL8_PG]
static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL8_PG = 0x8009c00010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23_LEN = 8;
//<< [IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL8_PG]
// iohs/reg00060.H

//>> [IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG]
static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG = 0x800cdc0010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23_LEN = 8;
//<< [IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL4_PG]
// iohs/reg00061.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00058.H"
#include "iohs/reg00059.H"
#include "iohs/reg00060.H"
#include "iohs/reg00061.H"
#endif
#endif
