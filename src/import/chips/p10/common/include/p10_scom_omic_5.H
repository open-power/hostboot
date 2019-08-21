/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_5.H $       */
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

#ifndef __p10_scom_omic_5_H_
#define __p10_scom_omic_5_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


static const uint64_t CTL_REGS_RX_MODE18_PG = 0x8008904010012c3full;

static const uint32_t CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH = 48;
static const uint32_t CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH_LEN = 5;
static const uint32_t CTL_REGS_RX_MODE18_PG_N1_SAMPLES = 53;
static const uint32_t CTL_REGS_RX_MODE18_PG_N1_SAMPLES_LEN = 2;
static const uint32_t CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH = 55;
static const uint32_t CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH_LEN = 4;
// omic/reg00005.H

static const uint64_t CTL_REGS_TX_SPARE_MODE_PG = 0x800c044010012c3full;

static const uint32_t CTL_REGS_TX_SPARE_MODE_PG_0 = 48;
static const uint32_t CTL_REGS_TX_SPARE_MODE_PG_1 = 49;
static const uint32_t CTL_REGS_TX_SPARE_MODE_PG_2 = 50;
static const uint32_t CTL_REGS_TX_SPARE_MODE_PG_3 = 51;
static const uint32_t CTL_REGS_TX_SPARE_MODE_PG_4 = 52;
static const uint32_t CTL_REGS_TX_SPARE_MODE_PG_5 = 53;
static const uint32_t CTL_REGS_TX_SPARE_MODE_PG_6 = 54;
static const uint32_t CTL_REGS_TX_SPARE_MODE_PG_7 = 55;
static const uint32_t CTL_REGS_TX_SPARE_MODE_PG_8_9 = 56;
static const uint32_t CTL_REGS_TX_SPARE_MODE_PG_8_9_LEN = 2;
// omic/reg00005.H

static const uint64_t DATASM_REGS_RX_CNTL9_PG = 0x8009c84010012c3full;

static const uint32_t DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15 = 48;
static const uint32_t DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15_LEN = 16;
// omic/reg00005.H

static const uint64_t DATASM_REGS_RX_STAT17_PG = 0x800b104010012c3full;

static const uint32_t DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL = 48;
static const uint32_t DATASM_REGS_RX_STAT17_PG_RX_LOFF_HYST_MAX_RO_SIGNAL_LEN = 8;
// omic/reg00005.H

static const uint64_t DATASM_REGS_RX_STAT27_PG = 0x800b604010012c3full;

static const uint32_t DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL = 48;
static const uint32_t DATASM_REGS_RX_STAT27_PG_RX_PSAVE_STS_PHY_16_23_RO_SIGNAL_LEN = 8;
// omic/reg00005.H

static const uint64_t DATASM_REGS_RX_STAT9_PG = 0x800ad04010012c3full;

static const uint32_t DATASM_REGS_RX_STAT9_PG_RX_SCAN_P_16_23_RO_SIGNAL = 48;
static const uint32_t DATASM_REGS_RX_STAT9_PG_RX_SCAN_P_16_23_RO_SIGNAL_LEN = 8;
// omic/reg00005.H

static const uint64_t TX_CTL_SM_REGS_FIR_PG = 0x800c844010012c3full;

static const uint32_t TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_SM_REGS_RO_SIGNAL = 48;
static const uint32_t TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_CTL_REGS_RO_SIGNAL = 49;
static const uint32_t TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_GCR_ARB_SM_RO_SIGNAL = 50;
static const uint32_t TX_CTL_SM_REGS_FIR_PG_G_FIR_ERR_TX_PSAVE_SM_RO_SIGNAL = 51;
static const uint32_t TX_CTL_SM_REGS_FIR_PG_L_FIR_ERR_RO_SIGNAL = 52;
// omic/reg00005.H

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00005.H"
#endif
#endif
