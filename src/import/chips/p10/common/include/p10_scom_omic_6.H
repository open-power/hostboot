/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_6.H $       */
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

#ifndef __p10_scom_omic_6_H_
#define __p10_scom_omic_6_H_


namespace scomt
{
namespace omic
{


static const uint64_t CTL_REGS_RX_CNTL5_PG = 0x8009204010012c3full;

static const uint32_t CTL_REGS_RX_CNTL5_PG_RX_PERVASIVE_CAPT = 48;
static const uint32_t CTL_REGS_RX_CNTL5_PG_TC_BIST_SHARED_OVRD = 49;
static const uint32_t CTL_REGS_RX_CNTL5_PG_TC_BIST_OPCG_GO_OVRD = 50;
static const uint32_t CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_OVRD = 51;
static const uint32_t CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD = 52;
static const uint32_t CTL_REGS_RX_CNTL5_PG_RX_BIST_MAX_LANES_OVRD_LEN = 5;
static const uint32_t CTL_REGS_RX_CNTL5_PG_TC_BIST_CODE_GO = 57;
static const uint32_t CTL_REGS_RX_CNTL5_PG_SYSTEM_MANU_SEL = 58;
// omic/reg00006.H

static const uint64_t CTL_REGS_RX_MODE16_PG = 0x8008804010012c3full;

static const uint32_t CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0 = 48;
static const uint32_t CTL_REGS_RX_MODE16_PG_INC_DEC_AMT0_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE16_PG_THRESH1 = 51;
static const uint32_t CTL_REGS_RX_MODE16_PG_THRESH1_LEN = 5;
static const uint32_t CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1 = 56;
static const uint32_t CTL_REGS_RX_MODE16_PG_INC_DEC_AMT1_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE16_PG_THRESH2 = 59;
static const uint32_t CTL_REGS_RX_MODE16_PG_THRESH2_LEN = 5;
// omic/reg00006.H

static const uint64_t CTL_REGS_RX_MODE3_PG = 0x8008184010012c3full;

static const uint32_t CTL_REGS_RX_MODE3_PG_FILTER_DEPTH = 48;
static const uint32_t CTL_REGS_RX_MODE3_PG_FILTER_DEPTH_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE3_PG_THRESH4 = 52;
static const uint32_t CTL_REGS_RX_MODE3_PG_THRESH4_LEN = 5;
static const uint32_t CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG = 57;
static const uint32_t CTL_REGS_RX_MODE3_PG_VOTE_RATIO_CFG_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE3_PG_DATA_SRC = 60;
static const uint32_t CTL_REGS_RX_MODE3_PG_FORMAT = 61;
static const uint32_t CTL_REGS_RX_MODE3_PG_VOTE_WIN_BOTH = 62;
// omic/reg00006.H

static const uint64_t CTL_REGS_RX_FIR1_ERROR_INJECT_PG = 0x8009384010012c3full;

static const uint32_t CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ = 48;
static const uint32_t CTL_REGS_RX_FIR1_ERROR_INJECT_PG_RX_PG_FIR1_ERR_INJ_LEN = 11;
// omic/reg00006.H

static const uint64_t CTL_REGS_TX_CNTL4_PG = 0x800c5c4010012c3full;

static const uint32_t CTL_REGS_TX_CNTL4_PG_DAC_CNTL = 48;
static const uint32_t CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN = 8;
static const uint32_t CTL_REGS_TX_CNTL4_PG_PHASE_SEL = 57;
// omic/reg00006.H

static const uint64_t DATASM_REGS_RX_CNT14_PG = 0x8009f04010012c3full;

static const uint32_t DATASM_REGS_RX_CNT14_PG_0_SEL = 48;
static const uint32_t DATASM_REGS_RX_CNT14_PG_0_SEL_LEN = 5;
static const uint32_t DATASM_REGS_RX_CNT14_PG_1_SEL = 53;
static const uint32_t DATASM_REGS_RX_CNT14_PG_1_SEL_LEN = 5;
static const uint32_t DATASM_REGS_RX_CNT14_PG_2_SEL = 58;
static const uint32_t DATASM_REGS_RX_CNT14_PG_2_SEL_LEN = 5;
// omic/reg00006.H

static const uint64_t DATASM_REGS_RX_CNT24_PG = 0x800a404010012c3full;

static const uint32_t DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23 = 48;
static const uint32_t DATASM_REGS_RX_CNT24_PG_RX_A_LANE_FAIL_16_23_LEN = 8;
// omic/reg00006.H

static const uint64_t DATASM_REGS_RX_CNTL7_PG = 0x8009b84010012c3full;

static const uint32_t DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15 = 48;
static const uint32_t DATASM_REGS_RX_CNTL7_PG_RX_PSAVE_FENCE_STS_IO_DL_0_15_LEN = 16;
// omic/reg00006.H

static const uint64_t DATASM_REGS_RX_STAT19_PG = 0x800b204010012c3full;
// omic/reg00006.H

static const uint64_t DATASM_REGS_RX_STAT7_PG = 0x800ac04010012c3full;
// omic/reg00006.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL5_PG = 0x800ce44010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL5_PG_TX_PSAVE_FORCE_REQ_0_15_LEN = 16;
// omic/reg00006.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_STAT5_PG = 0x800d644010012c3full;
// omic/reg00006.H

}
}
#ifndef __PPE_HCODE__
    #include "omic/reg00006.H"
#endif
#endif
