/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_1.H $       */
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

#ifndef __p10_scom_omic_1_H_
#define __p10_scom_omic_1_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


static const uint64_t CTL_REGS_RX_CNTL1_PG = 0x8009004010012c3full;

static const uint32_t CTL_REGS_RX_CNTL1_PG_EN = 48;
static const uint32_t CTL_REGS_RX_CNTL1_PG_TIMER_SEL = 49;
static const uint32_t CTL_REGS_RX_CNTL1_PG_TIMER_SEL_LEN = 4;
// omic/reg00001.H

static const uint64_t CTL_REGS_RX_MODE12_PG = 0x8008604010012c3full;

static const uint32_t CTL_REGS_RX_MODE12_PG_CLOCK_DAC = 48;
static const uint32_t CTL_REGS_RX_MODE12_PG_CLOCK_DAC_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE12_PG_DATA_DAC = 51;
static const uint32_t CTL_REGS_RX_MODE12_PG_DATA_DAC_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE12_PG_VSET_DAC = 54;
static const uint32_t CTL_REGS_RX_MODE12_PG_VSET_DAC_LEN = 2;
static const uint32_t CTL_REGS_RX_MODE12_PG_BYPASS = 56;
static const uint32_t CTL_REGS_RX_MODE12_PG_PDWN_B = 57;
// omic/reg00001.H

static const uint64_t CTL_REGS_RX_MODE22_PG = 0x8008b04010012c3full;

static const uint32_t CTL_REGS_RX_MODE22_PG_FILTER_DEPTH = 48;
static const uint32_t CTL_REGS_RX_MODE22_PG_FILTER_DEPTH_LEN = 5;
static const uint32_t CTL_REGS_RX_MODE22_PG_TIMEOUT = 53;
static const uint32_t CTL_REGS_RX_MODE22_PG_TIMEOUT_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG = 57;
static const uint32_t CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE22_PG_SERVO_THRESH4 = 60;
static const uint32_t CTL_REGS_RX_MODE22_PG_SERVO_THRESH4_LEN = 2;
static const uint32_t CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH = 62;
// omic/reg00001.H

static const uint64_t CTL_REGS_RX_MODE7_PG = 0x8008384010012c3full;

static const uint32_t CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT = 48;
static const uint32_t CTL_REGS_RX_MODE7_PG_AMP_TIMEOUT_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT = 52;
static const uint32_t CTL_REGS_RX_MODE7_PG_LOFF_TIMEOUT_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT = 56;
static const uint32_t CTL_REGS_RX_MODE7_PG_CTLE_TIMEOUT_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT = 60;
static const uint32_t CTL_REGS_RX_MODE7_PG_LTE_TIMEOUT_LEN = 4;
// omic/reg00001.H

static const uint64_t CTL_REGS_RX_FIR1_PG = 0x8009284010012c3full;

static const uint32_t CTL_REGS_RX_FIR1_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL = 48;
static const uint32_t CTL_REGS_RX_FIR1_PG_G_FIR_ERR_DATASM_REGS_RO_SIGNAL = 49;
static const uint32_t CTL_REGS_RX_FIR1_PG_G_FIR_ERR_DATASM_REGRW_RO_SIGNAL = 50;
static const uint32_t CTL_REGS_RX_FIR1_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL = 51;
static const uint32_t CTL_REGS_RX_FIR1_PG_G_FIR_ERR_RX_PSAVE_SM_RO_SIGNAL = 52;
static const uint32_t CTL_REGS_RX_FIR1_PG_G_FIR_ERR_RX_SERVO_MAIN_SM_RO_SIGNAL = 53;
static const uint32_t CTL_REGS_RX_FIR1_PG_G_FIR_ERR_RX_SERVO_AMP_SM_RO_SIGNAL = 54;
static const uint32_t CTL_REGS_RX_FIR1_PG_G_FIR_ERR_RX_SERVO_LOFF_SM_RO_SIGNAL = 55;
static const uint32_t CTL_REGS_RX_FIR1_PG_G_FIR_ERR_RX_SERVO_CTLE_SM_RO_SIGNAL = 56;
static const uint32_t CTL_REGS_RX_FIR1_PG_G_FIR_ERR_RX_SERVO_LTE_SM_RO_SIGNAL = 57;
static const uint32_t CTL_REGS_RX_FIR1_PG_G_FIR_ERR_RX_SERVO_QUAD_SM_RO_SIGNAL = 58;
static const uint32_t CTL_REGS_RX_FIR1_PG_L_FIR_ERR_RO_SIGNAL = 59;
// omic/reg00001.H

static const uint64_t DATASM_REGS_RX_CNT10_PG = 0x8009d04010012c3full;

static const uint32_t DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0 = 48;
static const uint32_t DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0_LEN = 8;
// omic/reg00001.H

static const uint64_t DATASM_REGS_RX_CNT20_PG = 0x800a204010012c3full;

static const uint32_t DATASM_REGS_RX_CNT20_PG_TIME = 48;
static const uint32_t DATASM_REGS_RX_CNT20_PG_TIME_LEN = 6;
static const uint32_t DATASM_REGS_RX_CNT20_PG_FIFO_TIME = 54;
static const uint32_t DATASM_REGS_RX_CNT20_PG_FIFO_TIME_LEN = 6;
static const uint32_t DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE = 61;
static const uint32_t DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE = 62;
static const uint32_t DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS = 63;
// omic/reg00001.H

static const uint64_t DATASM_REGS_RX_CNT30_PG = 0x800a704010012c3full;

static const uint32_t DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23 = 48;
static const uint32_t DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23_LEN = 8;
// omic/reg00001.H

static const uint64_t DATASM_REGS_RX_CNTL3_PG = 0x8009984010012c3full;

static const uint32_t DATASM_REGS_RX_CNTL3_PG_RX_SERVO_OP_QUEUE1_WO_PULSE_SLOW_SIGNAL = 48;
static const uint32_t DATASM_REGS_RX_CNTL3_PG_RX_SERVO_OP_QUEUE1_WO_PULSE_SLOW_SIGNAL_LEN = 16;
// omic/reg00001.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL11_PG = 0x800d144010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL11_PG_4_LEN = 6;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5 = 54;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL11_PG_5_LEN = 6;
// omic/reg00001.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL1_PG = 0x800cc44010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL1_PG_TX_PSAVE_FENCE_REQ_DL_IO_0_15_LEN = 16;
// omic/reg00001.H

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00001.H"
#endif
#endif
