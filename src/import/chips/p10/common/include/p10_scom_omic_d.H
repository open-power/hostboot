/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_d.H $       */
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

#ifndef __p10_scom_omic_d_H_
#define __p10_scom_omic_d_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


static const uint64_t CMN_CONFIG = 0x0c01174eull;

static const uint32_t CMN_CONFIG_MESO_BUFFER_ENABLE = 0;
static const uint32_t CMN_CONFIG_MESO_BUFFER_START = 1;
static const uint32_t CMN_CONFIG_MESO_BUFFER_START_LEN = 3;
static const uint32_t CMN_CONFIG_CFG_CMN_SPARE = 4;
static const uint32_t CMN_CONFIG_CFG_CMN_SPARE_LEN = 2;
static const uint32_t CMN_CONFIG_CFG_CMN_RX_EDGE_ENA = 6;
static const uint32_t CMN_CONFIG_CFG_CMN_RX_EDGE_MARGIN = 7;
static const uint32_t CMN_CONFIG_CFG_CMN_RX_EDGE_MARGIN_LEN = 5;
static const uint32_t CMN_CONFIG_CFG_CMN_PSAV_STS_ENABLE = 12;
static const uint32_t CMN_CONFIG_CFG_CMN_RECAL_TIMER = 13;
static const uint32_t CMN_CONFIG_CFG_CMN_RECAL_TIMER_LEN = 3;
static const uint32_t CMN_CONFIG_CFG_CMN_1US_TMR = 16;
static const uint32_t CMN_CONFIG_CFG_CMN_1US_TMR_LEN = 12;
static const uint32_t CMN_CONFIG_CFG_CMN_DBG_EN = 28;
static const uint32_t CMN_CONFIG_CFG_CMN_DBG_SEL = 29;
static const uint32_t CMN_CONFIG_CFG_CMN_DBG_SEL_LEN = 3;
static const uint32_t CMN_CONFIG_CFG_CMN_RD_RST = 32;
static const uint32_t CMN_CONFIG_CFG_CMN_PRE_SCALAR = 33;
static const uint32_t CMN_CONFIG_CFG_CMN_PRE_SCALAR_LEN = 3;
static const uint32_t CMN_CONFIG_CFG_CMN_FREEZE = 36;
static const uint32_t CMN_CONFIG_CFG_CMN_PORT_SEL = 37;
static const uint32_t CMN_CONFIG_CFG_CMN_PORT_SEL_LEN = 3;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR3_PS = 40;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR3_PS_LEN = 2;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR3_ES = 42;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR3_ES_LEN = 2;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR2_PS = 44;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR2_PS_LEN = 2;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR2_ES = 46;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR2_ES_LEN = 2;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR1_PS = 48;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR1_PS_LEN = 2;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR1_ES = 50;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR1_ES_LEN = 2;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR0_PS = 52;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR0_PS_LEN = 2;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR0_ES = 54;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR0_ES_LEN = 2;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR3_PE = 56;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR2_PE = 57;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR1_PE = 58;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR0_PE = 59;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR3_EN = 60;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR2_EN = 61;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR1_EN = 62;
static const uint32_t CMN_CONFIG_CFG_CMN_CNTR0_EN = 63;
// omic/reg00013.H

static const uint64_t CTL_REGS_RX_MODE14_PG = 0x8008704010012c3full;

static const uint32_t CTL_REGS_RX_MODE14_PG_RX_LOFF_LIVEDGE_MODE = 48;
// omic/reg00013.H

static const uint64_t CTL_REGS_RX_MODE1_PG = 0x8008084010012c3full;

static const uint32_t CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN = 48;
static const uint32_t CTL_REGS_RX_MODE1_PG_16TO1 = 51;
// omic/reg00013.H

static const uint64_t CTL_REGS_TX_CNTL6_PG = 0x800c6c4010012c3full;

static const uint32_t CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH = 48;
static const uint32_t CTL_REGS_TX_CNTL6_PG_TX_TDR_PULSE_WIDTH_LEN = 9;
// omic/reg00013.H

static const uint64_t DATASM_REGS_RX_CNT16_PG = 0x800a004010012c3full;

static const uint32_t DATASM_REGS_RX_CNT16_PG_0 = 48;
static const uint32_t DATASM_REGS_RX_CNT16_PG_0_LEN = 6;
static const uint32_t DATASM_REGS_RX_CNT16_PG_1 = 54;
static const uint32_t DATASM_REGS_RX_CNT16_PG_1_LEN = 6;
// omic/reg00013.H

static const uint64_t DATASM_REGS_RX_CNT26_PG = 0x800a504010012c3full;

static const uint32_t DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23 = 56;
static const uint32_t DATASM_REGS_RX_CNT26_PG_RX_B_LANE_FAIL_16_23_LEN = 8;
// omic/reg00013.H

static const uint64_t DATASM_REGS_RX_CNTL5_PG = 0x8009a84010012c3full;

static const uint32_t DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15 = 48;
static const uint32_t DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15_LEN = 16;
// omic/reg00013.H

static const uint64_t DATASM_REGS_RX_STAT5_PG = 0x800ab04010012c3full;
// omic/reg00013.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL7_PG = 0x800cf44010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15_LEN = 16;
// omic/reg00013.H

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00013.H"
#endif
#endif
