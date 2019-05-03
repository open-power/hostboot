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

#include "proc_scomt.H"

#ifndef __p10_scom_omic_5_H_
#define __p10_scom_omic_5_H_


namespace scomt
{
namespace omic
{


//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t CTL_REGS_RX_MODE18_PG = 0x800890600c00143full;

static const uint32_t CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH = 48;
static const uint32_t CTL_REGS_RX_MODE18_PG_HIST_BIAS_THRESH_LEN = 5;
static const uint32_t CTL_REGS_RX_MODE18_PG_N1_SAMPLES = 53;
static const uint32_t CTL_REGS_RX_MODE18_PG_N1_SAMPLES_LEN = 2;
static const uint32_t CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH = 55;
static const uint32_t CTL_REGS_RX_MODE18_PG_N1_BIAS_THRESH_LEN = 4;
// omic/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t CTL_REGS_TX_SPARE_MODE_PG = 0x800c04600c00143full;

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

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_CNTL9_PG = 0x8009c8600c00143full;

static const uint32_t DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15 = 48;
static const uint32_t DATASM_REGS_RX_CNTL9_PG_RX_PSAVE_FORCE_REQ_0_15_LEN = 16;
// omic/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_STAT17_PG = 0x800b10600c00143full;
// omic/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_STAT27_PG = 0x800b60600c00143full;
// omic/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_STAT9_PG = 0x800ad0600c00143full;
// omic/reg00005.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t TX_CTL_SM_REGS_FIR_PG = 0x800c84600c00143full;
// omic/reg00005.H

}
}
#include "omic/reg00005.H"
#endif
