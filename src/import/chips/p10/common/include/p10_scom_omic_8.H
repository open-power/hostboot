/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_8.H $       */
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

#ifndef __p10_scom_omic_8_H_
#define __p10_scom_omic_8_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


static const uint64_t CTL_REGS_RX_MODE15_PG = 0x8008784010012c3full;

static const uint32_t CTL_REGS_RX_MODE15_PG_0 = 48;
static const uint32_t CTL_REGS_RX_MODE15_PG_0_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE15_PG_1 = 52;
static const uint32_t CTL_REGS_RX_MODE15_PG_1_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE15_PG_2 = 56;
static const uint32_t CTL_REGS_RX_MODE15_PG_2_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE15_PG_3 = 60;
static const uint32_t CTL_REGS_RX_MODE15_PG_3_LEN = 4;
// omic/reg00008.H

static const uint64_t CTL_REGS_TX_CNTL7_PG = 0x800c744010012c3full;

static const uint32_t CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15 = 48;
static const uint32_t CTL_REGS_TX_CNTL7_PG_TX_PATTERN_0_15_LEN = 16;
// omic/reg00008.H

static const uint64_t CTL_REGS_TX_MODE1_PG = 0x800c0c4010012c3full;

static const uint32_t CTL_REGS_TX_MODE1_PG_CLKDIST_PDWN = 48;
static const uint32_t CTL_REGS_TX_MODE1_PG_RCTRL = 49;
static const uint32_t CTL_REGS_TX_MODE1_PG_16TO1 = 50;
static const uint32_t CTL_REGS_TX_MODE1_PG_BIST_DCC_EN = 54;
static const uint32_t CTL_REGS_TX_MODE1_PG_BIST_LS_EN = 55;
static const uint32_t CTL_REGS_TX_MODE1_PG_BIST_HS_EN = 56;
static const uint32_t CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC = 57;
static const uint32_t CTL_REGS_TX_MODE1_PG_IREF_CLOCK_DAC_LEN = 3;
static const uint32_t CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC = 60;
static const uint32_t CTL_REGS_TX_MODE1_PG_IREF_VSET_DAC_LEN = 2;
static const uint32_t CTL_REGS_TX_MODE1_PG_IREF_BYPASS = 62;
static const uint32_t CTL_REGS_TX_MODE1_PG_IREF_PDWN_B = 63;
// omic/reg00008.H

static const uint64_t DATASM_REGS_RX_CNT17_PG = 0x800a084010012c3full;

static const uint32_t DATASM_REGS_RX_CNT17_PG_2 = 48;
static const uint32_t DATASM_REGS_RX_CNT17_PG_2_LEN = 6;
static const uint32_t DATASM_REGS_RX_CNT17_PG_3 = 54;
static const uint32_t DATASM_REGS_RX_CNT17_PG_3_LEN = 6;
// omic/reg00008.H

static const uint64_t DATASM_REGS_RX_CNT27_PG = 0x800a584010012c3full;

static const uint32_t DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_15 = 48;
static const uint32_t DATASM_REGS_RX_CNT27_PG_RX_A_LANE_DONE_0_15_LEN = 16;
// omic/reg00008.H

static const uint64_t DATASM_REGS_RX_CNTL4_PG = 0x8009a04010012c3full;

static const uint32_t DATASM_REGS_RX_CNTL4_PG_RX_CLEAR_SERVO_QUEUES_WO_PULSE_SLOW_SIGNAL = 48;
// omic/reg00008.H

static const uint64_t DATASM_REGS_RX_STAT4_PG = 0x800aa84010012c3full;
// omic/reg00008.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL6_PG = 0x800cec4010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL6_PG_TX_PSAVE_FORCE_REQ_16_23_0_LEN = 8;
// omic/reg00008.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG = 0x800ca44010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_0 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_1 = 49;
static const uint32_t TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_2 = 50;
static const uint32_t TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_3 = 51;
static const uint32_t TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_4 = 52;
static const uint32_t TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_5 = 53;
static const uint32_t TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_6 = 54;
static const uint32_t TX_CTL_SM_REGS_CTLSM_SPARE_MODE_PG_7 = 55;
// omic/reg00008.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_STAT6_PG = 0x800d6c4010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_STAT6_PG_TX_BIST_DCC_FAIL = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_STAT6_PG_TX_BIST_LS_FAIL = 49;
static const uint32_t TX_CTL_SM_REGS_CTLSM_STAT6_PG_TX_BIST_HS_FAIL = 50;
static const uint32_t TX_CTL_SM_REGS_CTLSM_STAT6_PG_TX_IREF_PARITYCHK_CLOCK_RO_SIGNAL = 51;
// omic/reg00008.H

static const uint64_t TX_SYNC = 0x0c01174dull;

static const uint32_t TX_SYNC_ENA = 31;
static const uint32_t TX_SYNC_DL7_DELAY = 32;
static const uint32_t TX_SYNC_DL7_DELAY_LEN = 4;
static const uint32_t TX_SYNC_DL6_DELAY = 36;
static const uint32_t TX_SYNC_DL6_DELAY_LEN = 4;
static const uint32_t TX_SYNC_DL5_DELAY = 40;
static const uint32_t TX_SYNC_DL5_DELAY_LEN = 4;
static const uint32_t TX_SYNC_DL4_DELAY = 44;
static const uint32_t TX_SYNC_DL4_DELAY_LEN = 4;
static const uint32_t TX_SYNC_DL3_DELAY = 48;
static const uint32_t TX_SYNC_DL3_DELAY_LEN = 4;
static const uint32_t TX_SYNC_DL2_DELAY = 52;
static const uint32_t TX_SYNC_DL2_DELAY_LEN = 4;
static const uint32_t TX_SYNC_DL1_DELAY = 56;
static const uint32_t TX_SYNC_DL1_DELAY_LEN = 4;
static const uint32_t TX_SYNC_DL0_DELAY = 60;
static const uint32_t TX_SYNC_DL0_DELAY_LEN = 4;
// omic/reg00008.H

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00008.H"
#endif
#endif
