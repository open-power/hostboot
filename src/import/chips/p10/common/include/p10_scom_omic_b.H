/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_b.H $       */
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

#ifndef __p10_scom_omic_b_H_
#define __p10_scom_omic_b_H_


namespace scomt
{
namespace omic
{


static const uint64_t CTL_REGS_TX_CNTL9_PG = 0x800c244010012c3full;

static const uint32_t CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47 = 48;
static const uint32_t CTL_REGS_TX_CNTL9_PG_TX_PATTERN_32_47_LEN = 16;
// omic/reg00011.H

static const uint64_t DATASM_REGS_RX_CNT19_PG = 0x800a184010012c3full;

static const uint32_t DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6 = 48;
static const uint32_t DATASM_REGS_RX_CNT19_PG_RX_PSAVE_SUBSET6_LEN = 6;
// omic/reg00011.H

static const uint64_t DATASM_REGS_RX_CNT29_PG = 0x800a684010012c3full;

static const uint32_t DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_15 = 48;
static const uint32_t DATASM_REGS_RX_CNT29_PG_RX_B_LANE_DONE_0_15_LEN = 16;
// omic/reg00011.H

static const uint64_t DATASM_REGS_RX_STAT14_PG = 0x800af84010012c3full;
// omic/reg00011.H

static const uint64_t DATASM_REGS_RX_STAT24_PG = 0x800b484010012c3full;
// omic/reg00011.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL8_PG = 0x800cfc4010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23_LEN = 8;
// omic/reg00011.H

}
}
#ifndef __PPE_HCODE__
    #include "omic/reg00011.H"
#endif
#endif
