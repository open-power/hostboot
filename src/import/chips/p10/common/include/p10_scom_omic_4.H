/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_4.H $       */
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

#ifndef __p10_scom_omic_4_H_
#define __p10_scom_omic_4_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


static const uint64_t CTL_REGS_RX_MODE13_PG = 0x8008684010012c3full;

static const uint32_t CTL_REGS_RX_MODE13_PG_1_FILTER_ENA = 48;
static const uint32_t CTL_REGS_RX_MODE13_PG_1_FILTER_ENA_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE13_PG_1_FILTER_PAT = 52;
static const uint32_t CTL_REGS_RX_MODE13_PG_1_FILTER_PAT_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE13_PG_2_FILTER_ENA = 56;
static const uint32_t CTL_REGS_RX_MODE13_PG_2_FILTER_ENA_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE13_PG_2_FILTER_PAT = 60;
static const uint32_t CTL_REGS_RX_MODE13_PG_2_FILTER_PAT_LEN = 4;
// omic/reg00004.H

static const uint64_t CTL_REGS_RX_MODE23_PG = 0x8008b84010012c3full;

static const uint32_t CTL_REGS_RX_MODE23_PG_1_H_SEL = 48;
static const uint32_t CTL_REGS_RX_MODE23_PG_1_H_SEL_LEN = 2;
static const uint32_t CTL_REGS_RX_MODE23_PG_2_H_SEL = 50;
static const uint32_t CTL_REGS_RX_MODE23_PG_2_H_SEL_LEN = 2;
// omic/reg00004.H

static const uint64_t CTL_REGS_RX_MODE6_PG = 0x8008304010012c3full;

static const uint32_t CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2 = 48;
static const uint32_t CTL_REGS_RX_MODE6_PG_INC_DEC_AMT2_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE6_PG_THRESH3 = 51;
static const uint32_t CTL_REGS_RX_MODE6_PG_THRESH3_LEN = 5;
static const uint32_t CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3 = 56;
static const uint32_t CTL_REGS_RX_MODE6_PG_INC_DEC_AMT3_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE6_PG_THRESH4 = 59;
static const uint32_t CTL_REGS_RX_MODE6_PG_THRESH4_LEN = 5;
// omic/reg00004.H

static const uint64_t CTL_REGS_TX_CNTL1_PG = 0x800c444010012c3full;

static const uint32_t CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL = 48;
static const uint32_t CTL_REGS_TX_CNTL1_PG_TX_PATTERN_SEL_LEN = 3;
// omic/reg00004.H

static const uint64_t DATASM_REGS_RX_CNT11_PG = 0x8009d84010012c3full;

static const uint32_t DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15 = 48;
static const uint32_t DATASM_REGS_RX_CNT11_PG_RX_PSAVE_FORCE_STS_0_15_LEN = 16;
// omic/reg00004.H

static const uint64_t DATASM_REGS_RX_CNT21_PG = 0x800a284010012c3full;

static const uint32_t DATASM_REGS_RX_CNT21_PG_RX_IO_PB_NV_IOBIST_RESET = 48;
// omic/reg00004.H

static const uint64_t DATASM_REGS_RX_CNTL2_PG = 0x8009904010012c3full;
// omic/reg00004.H

static const uint64_t DATASM_REGS_RX_STAT2_PG = 0x800a984010012c3full;
// omic/reg00004.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL10_PG = 0x800d0c4010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2_LEN = 6;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3 = 54;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3_LEN = 6;
// omic/reg00004.H

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00004.H"
#endif
#endif
