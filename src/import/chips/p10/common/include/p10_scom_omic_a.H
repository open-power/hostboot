/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_a.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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

#ifndef __p10_scom_omic_a_H_
#define __p10_scom_omic_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> [DATASM_REGS_RX_CNT32_PG]
static const uint64_t DATASM_REGS_RX_CNT32_PG = 0x800a804010012c3full;

static const uint32_t DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1 = 48;
static const uint32_t DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1_LEN = 16;
//<< [DATASM_REGS_RX_CNT32_PG]
// omic/reg00010.H

//>> [DATASM_REGS_RX_CNT12_PG]
static const uint64_t DATASM_REGS_RX_CNT12_PG = 0x8009e04010012c3full;

static const uint32_t DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23 = 48;
static const uint32_t DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23_LEN = 8;
//<< [DATASM_REGS_RX_CNT12_PG]
// omic/reg00010.H

//>> [TX_CTL_SM_REGS_CTLSM_CNTL3_PG]
static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL3_PG = 0x800cd44010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN = 16;
//<< [TX_CTL_SM_REGS_CTLSM_CNTL3_PG]
// omic/reg00010.H

//>> [TX_CTL_SM_REGS_CTLSM_CNTL13_PG]
static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL13_PG = 0x800d244010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1_LEN = 16;
//<< [TX_CTL_SM_REGS_CTLSM_CNTL13_PG]
// omic/reg00010.H

//>> [CTL_REGS_TX_CNTL2_PG]
static const uint64_t CTL_REGS_TX_CNTL2_PG = 0x800c4c4010012c3full;

static const uint32_t CTL_REGS_TX_CNTL2_PG_A_FINE_SEL = 48;
static const uint32_t CTL_REGS_TX_CNTL2_PG_A_FINE_SEL_LEN = 3;
static const uint32_t CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL = 51;
static const uint32_t CTL_REGS_TX_CNTL2_PG_A_COARSE_SEL_LEN = 4;
static const uint32_t CTL_REGS_TX_CNTL2_PG_A_BER_SEL = 55;
static const uint32_t CTL_REGS_TX_CNTL2_PG_A_BER_SEL_LEN = 6;
static const uint32_t CTL_REGS_TX_CNTL2_PG_ENABLE = 61;
static const uint32_t CTL_REGS_TX_CNTL2_PG_CLOCK_ENABLE = 62;
//<< [CTL_REGS_TX_CNTL2_PG]
// omic/reg00010.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00010.H"
#endif
#endif
