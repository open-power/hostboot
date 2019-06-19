/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_e.H $       */
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

#ifndef __p10_scom_omic_e_H_
#define __p10_scom_omic_e_H_


namespace scomt
{
namespace omic
{


static const uint64_t CTL_REGS_TX_CNTL8_PG = 0x800c7c4010012c3full;

static const uint32_t CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31 = 48;
static const uint32_t CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31_LEN = 16;
// omic/reg00014.H

static const uint64_t DATASM_REGS_RX_CNT18_PG = 0x800a104010012c3full;

static const uint32_t DATASM_REGS_RX_CNT18_PG_4 = 48;
static const uint32_t DATASM_REGS_RX_CNT18_PG_4_LEN = 6;
static const uint32_t DATASM_REGS_RX_CNT18_PG_5 = 54;
static const uint32_t DATASM_REGS_RX_CNT18_PG_5_LEN = 6;
// omic/reg00014.H

static const uint64_t DATASM_REGS_RX_CNT28_PG = 0x800a604010012c3full;

static const uint32_t DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23 = 48;
static const uint32_t DATASM_REGS_RX_CNT28_PG_RX_A_LANE_DONE_16_23_LEN = 8;
// omic/reg00014.H

static const uint64_t DATASM_REGS_RX_STAT15_PG = 0x800b004010012c3full;
// omic/reg00014.H

static const uint64_t DATASM_REGS_RX_STAT25_PG = 0x800b504010012c3full;
// omic/reg00014.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL9_PG = 0x800d044010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL9_PG_0_LEN = 6;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1 = 54;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL9_PG_1_LEN = 6;
// omic/reg00014.H

static const uint64_t TX_CTL_SM_REGS_FIR_MASK_PG = 0x800c8c4010012c3full;

static const uint32_t TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK = 48;
static const uint32_t TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK_LEN = 5;
// omic/reg00014.H

}
}
#ifndef __PPE_HCODE__
    #include "omic/reg00014.H"
#endif
#endif
