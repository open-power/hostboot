/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_3.H $       */
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

#ifndef __p10_scom_omic_3_H_
#define __p10_scom_omic_3_H_


namespace scomt
{
namespace omic
{


//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t CTL_REGS_RX_MODE17_PG = 0x800888600c00143full;

static const uint32_t CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 = 48;
static const uint32_t CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE17_PG_THRESH3 = 51;
static const uint32_t CTL_REGS_RX_MODE17_PG_THRESH3_LEN = 5;
static const uint32_t CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 = 56;
static const uint32_t CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE17_PG_THRESH4 = 59;
static const uint32_t CTL_REGS_RX_MODE17_PG_THRESH4_LEN = 5;
// omic/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t CTL_REGS_RX_MODE2_PG = 0x800810600c00143full;

static const uint32_t CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE = 48;
static const uint32_t CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT = 49;
static const uint32_t CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK = 53;
static const uint32_t CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK_LEN = 7;
static const uint32_t CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE = 60;
// omic/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t CTL_REGS_TX_CNTL5_PG = 0x800c64600c00143full;

static const uint32_t CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET = 48;
static const uint32_t CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET_LEN = 15;
// omic/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_CNT15_PG = 0x8009f8600c00143full;

static const uint32_t DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL = 48;
static const uint32_t DATASM_REGS_RX_CNT15_PG_RX_PSAVE_FW_VAL3_SEL_LEN = 5;
// omic/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_CNT25_PG = 0x800a48600c00143full;

static const uint32_t DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15 = 48;
static const uint32_t DATASM_REGS_RX_CNT25_PG_RX_B_LANE_FAIL_0_15_LEN = 16;
// omic/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_CNTL6_PG = 0x8009b0600c00143full;

static const uint32_t DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23 = 48;
static const uint32_t DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN = 8;
// omic/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_STAT18_PG = 0x800b18600c00143full;
// omic/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_STAT28_PG = 0x800b68600c00143full;
// omic/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_STAT6_PG = 0x800ab8600c00143full;
// omic/reg00003.H

static const uint64_t MC_OMI_FIR_MASK_REG_SCOM = 0x0c011743ull;
static const uint64_t MC_OMI_FIR_MASK_REG_SCOM1 = 0x0c011744ull;
static const uint64_t MC_OMI_FIR_MASK_REG_SCOM2 = 0x0c011745ull;

static const uint32_t MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK = 0;
static const uint32_t MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN = 20;
static const uint32_t MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK = 20;
static const uint32_t MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN = 20;
static const uint32_t MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK = 40;
static const uint32_t MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN = 20;
static const uint32_t MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK = 60;
// omic/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL14_PG = 0x800d2c600c00143full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1_LEN = 8;
// omic/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL4_PG = 0x800cdc600c00143full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23_LEN = 8;
// omic/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t TX_CTL_SM_REGS_CTLSM_STAT4_PG = 0x800d5c600c00143full;
// omic/reg00003.H

}
}
#include "omic/reg00003.H"
#endif
