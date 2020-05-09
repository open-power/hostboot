/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_a.H $       */
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

#ifndef __p10_scom_omic_a_H_
#define __p10_scom_omic_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> [CTL_REGS_RX_CNTL3_PG]
static const uint64_t CTL_REGS_RX_CNTL3_PG = 0x8009104010012c3full;

static const uint32_t CTL_REGS_RX_CNTL3_PG_CLR_PAR_ERRS = 62;
static const uint32_t CTL_REGS_RX_CNTL3_PG_FIR_RESET = 63;
//<< [CTL_REGS_RX_CNTL3_PG]
// omic/reg00010.H

//>> [CTL_REGS_RX_MODE10_PG]
static const uint64_t CTL_REGS_RX_MODE10_PG = 0x8008504010012c3full;

static const uint32_t CTL_REGS_RX_MODE10_PG_FILTER_DEPTH = 48;
static const uint32_t CTL_REGS_RX_MODE10_PG_FILTER_DEPTH_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE10_PG_THRESH4 = 52;
static const uint32_t CTL_REGS_RX_MODE10_PG_THRESH4_LEN = 5;
static const uint32_t CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG = 57;
static const uint32_t CTL_REGS_RX_MODE10_PG_VOTE_RATIO_CFG_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE10_PG_DATA_SRC = 60;
static const uint32_t CTL_REGS_RX_MODE10_PG_VOTE_WIN_BOTH = 61;
//<< [CTL_REGS_RX_MODE10_PG]
// omic/reg00010.H

//>> [CTL_REGS_RX_MODE20_PG]
static const uint64_t CTL_REGS_RX_MODE20_PG = 0x8008a04010012c3full;

static const uint32_t CTL_REGS_RX_MODE20_PG_AMP_HYST_START = 48;
static const uint32_t CTL_REGS_RX_MODE20_PG_AMP_HYST_START_LEN = 5;
static const uint32_t CTL_REGS_RX_MODE20_PG_LOFF_HYST_START = 53;
static const uint32_t CTL_REGS_RX_MODE20_PG_LOFF_HYST_START_LEN = 5;
//<< [CTL_REGS_RX_MODE20_PG]
// omic/reg00010.H

//>> [CTL_REGS_RX_MODE5_PG]
static const uint64_t CTL_REGS_RX_MODE5_PG = 0x8008284010012c3full;

static const uint32_t CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0 = 48;
static const uint32_t CTL_REGS_RX_MODE5_PG_INC_DEC_AMT0_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE5_PG_THRESH1 = 51;
static const uint32_t CTL_REGS_RX_MODE5_PG_THRESH1_LEN = 5;
static const uint32_t CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1 = 56;
static const uint32_t CTL_REGS_RX_MODE5_PG_INC_DEC_AMT1_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE5_PG_THRESH2 = 59;
static const uint32_t CTL_REGS_RX_MODE5_PG_THRESH2_LEN = 5;
//<< [CTL_REGS_RX_MODE5_PG]
// omic/reg00010.H

//>> [CTL_REGS_RX_FIR1_MASK_PG]
static const uint64_t CTL_REGS_RX_FIR1_MASK_PG = 0x8009304010012c3full;

static const uint32_t CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK = 48;
static const uint32_t CTL_REGS_RX_FIR1_MASK_PG_RX_PG_FIR1_ERRS_MASK_LEN = 12;
//<< [CTL_REGS_RX_FIR1_MASK_PG]
// omic/reg00010.H

//>> [CTL_REGS_TX_CNTL10_PG]
static const uint64_t CTL_REGS_TX_CNTL10_PG = 0x800c2c4010012c3full;

static const uint32_t CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63 = 48;
static const uint32_t CTL_REGS_TX_CNTL10_PG_TX_PATTERN_48_63_LEN = 16;
//<< [CTL_REGS_TX_CNTL10_PG]
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

//>> [DATASM_REGS_RX_CNT12_PG]
static const uint64_t DATASM_REGS_RX_CNT12_PG = 0x8009e04010012c3full;

static const uint32_t DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23 = 48;
static const uint32_t DATASM_REGS_RX_CNT12_PG_RX_PSAVE_FORCE_STS_16_23_LEN = 8;
//<< [DATASM_REGS_RX_CNT12_PG]
// omic/reg00010.H

//>> [DATASM_REGS_RX_CNT22_PG]
static const uint64_t DATASM_REGS_RX_CNT22_PG = 0x800a304010012c3full;

static const uint32_t DATASM_REGS_RX_CNT22_PG_CTLE_GAIN_CHECK_EN = 48;
static const uint32_t DATASM_REGS_RX_CNT22_PG_LATCHOFF_CHECK_EN = 49;
static const uint32_t DATASM_REGS_RX_CNT22_PG_EOFF_CHECK_EN = 50;
static const uint32_t DATASM_REGS_RX_CNT22_PG_EOFF_POFF_CHECK_EN = 51;
static const uint32_t DATASM_REGS_RX_CNT22_PG_CTLE_PEAK1_CHECK_EN = 52;
static const uint32_t DATASM_REGS_RX_CNT22_PG_CTLE_PEAK2_CHECK_EN = 53;
static const uint32_t DATASM_REGS_RX_CNT22_PG_LTE_GAIN_CHECK_EN = 54;
static const uint32_t DATASM_REGS_RX_CNT22_PG_LTE_ZERO_CHECK_EN = 55;
static const uint32_t DATASM_REGS_RX_CNT22_PG_BANK_SYNC_CHECK_EN = 56;
static const uint32_t DATASM_REGS_RX_CNT22_PG_QUAD_PHASE_CHECK_EN = 57;
static const uint32_t DATASM_REGS_RX_CNT22_PG_DFE_H1_CHECK_EN = 58;
static const uint32_t DATASM_REGS_RX_CNT22_PG_DFE_CHECK_EN = 59;
static const uint32_t DATASM_REGS_RX_CNT22_PG_DDC_CHECK_EN = 60;
static const uint32_t DATASM_REGS_RX_CNT22_PG_PR_BER_CHECK_EN = 61;
static const uint32_t DATASM_REGS_RX_CNT22_PG_LINK_LAYER_CHECK_EN = 62;
//<< [DATASM_REGS_RX_CNT22_PG]
// omic/reg00010.H

//>> [DATASM_REGS_RX_CNT32_PG]
static const uint64_t DATASM_REGS_RX_CNT32_PG = 0x800a804010012c3full;

static const uint32_t DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1 = 48;
static const uint32_t DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1_LEN = 16;
//<< [DATASM_REGS_RX_CNT32_PG]
// omic/reg00010.H

//>> [DATASM_REGS_RX_CNTL1_PG]
static const uint64_t DATASM_REGS_RX_CNTL1_PG = 0x8009884010012c3full;

static const uint32_t DATASM_REGS_RX_CNTL1_PG_DATA_PIPE_CAPTURE_WO_PULSE_SLOW_SIGNAL = 52;
static const uint32_t DATASM_REGS_RX_CNTL1_PG_RESET_SERVO_STATUS_WO_PULSE_SLOW_SIGNAL = 53;
static const uint32_t DATASM_REGS_RX_CNTL1_PG_BER_RESET_WO_PULSE_SLOW_SIGNAL = 54;
//<< [DATASM_REGS_RX_CNTL1_PG]
// omic/reg00010.H

//>> [DATASM_REGS_RX_STAT1_PG]
static const uint64_t DATASM_REGS_RX_STAT1_PG = 0x800a904010012c3full;

static const uint32_t DATASM_REGS_RX_STAT1_PG_RX_BER_TIMER_RUNNING_RO_SIGNAL = 48;
static const uint32_t DATASM_REGS_RX_STAT1_PG_RX_PB_IO_NV_IOBIST_PRBS_ERROR_RO_SIGNAL = 49;
static const uint32_t DATASM_REGS_RX_STAT1_PG_RX_SYNCCLK_MUXSEL_DC_RO_SIGNAL = 50;
static const uint32_t DATASM_REGS_RX_STAT1_PG_TC_OPCG_IOBIST_GO_RO_SIGNAL = 51;
static const uint32_t DATASM_REGS_RX_STAT1_PG_TC_SHARED_PIN_DC_RO_SIGNAL = 52;
//<< [DATASM_REGS_RX_STAT1_PG]
// omic/reg00010.H

//>> [TX_CTL_SM_REGS_CTLSM_CNTL13_PG]
static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL13_PG = 0x800d244010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1_LEN = 16;
//<< [TX_CTL_SM_REGS_CTLSM_CNTL13_PG]
// omic/reg00010.H

//>> [TX_CTL_SM_REGS_CTLSM_CNTL3_PG]
static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL3_PG = 0x800cd44010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL3_PG_TX_PSAVE_FENCE_STS_IO_DL_0_15_LEN = 16;
//<< [TX_CTL_SM_REGS_CTLSM_CNTL3_PG]
// omic/reg00010.H

//>> [TX_CTL_SM_REGS_CTLSM_STAT3_PG]
static const uint64_t TX_CTL_SM_REGS_CTLSM_STAT3_PG = 0x800d544010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_STAT3_PG_TX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL_LEN = 8;
//<< [TX_CTL_SM_REGS_CTLSM_STAT3_PG]
// omic/reg00010.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00010.H"
#endif
#endif
