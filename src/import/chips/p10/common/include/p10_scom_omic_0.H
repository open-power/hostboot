/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_0.H $       */
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

#ifndef __p10_scom_omic_0_H_
#define __p10_scom_omic_0_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


static const uint64_t CTL_REGS_RX_MODE19_PG = 0x8008984010012c3full;

static const uint32_t CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH = 48;
static const uint32_t CTL_REGS_RX_MODE19_PG_HIST_BIAS_THRESH_LEN = 5;
static const uint32_t CTL_REGS_RX_MODE19_PG_N1_SAMPLES = 53;
static const uint32_t CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH = 54;
static const uint32_t CTL_REGS_RX_MODE19_PG_N1_BIAS_THRESH_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE19_PG_N2_SAMPLES = 58;
// omic/reg00000.H

static const uint64_t DATASM_REGS_RX_CNTL8_PG = 0x8009c04010012c3full;

static const uint32_t DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23 = 48;
static const uint32_t DATASM_REGS_RX_CNTL8_PG_RX_PSAVE_FENCE_STS_IO_DL_16_23_LEN = 8;
// omic/reg00000.H

static const uint64_t DATASM_REGS_RX_STAT16_PG = 0x800b084010012c3full;

static const uint32_t DATASM_REGS_RX_STAT16_PG_RX_CTLE_DIR_CHG_CNT_RO_SIGNAL = 48;
static const uint32_t DATASM_REGS_RX_STAT16_PG_RX_CTLE_DIR_CHG_CNT_RO_SIGNAL_LEN = 5;
// omic/reg00000.H

static const uint64_t DATASM_REGS_RX_STAT26_PG = 0x800b584010012c3full;
// omic/reg00000.H

static const uint64_t DATASM_REGS_RX_STAT8_PG = 0x800ac84010012c3full;
// omic/reg00000.H

static const uint64_t MC_OMI_FIR_WOF_REG = 0x0c011748ull;

static const uint32_t MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF = 0;
static const uint32_t MC_OMI_FIR_WOF_REG_MC_OMI_FIR_WOF_LEN = 62;
// omic/reg00000.H

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00000.H"
#endif
#endif
