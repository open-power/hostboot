/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_3.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __p10_scom_omic_3_H_
#define __p10_scom_omic_3_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> [MC_OMI_FIR_MASK_REG]
//ERRCODE: // Some of the name targets not found in address targets: omic
// No targets could be determined from the address.

static const uint64_t MC_OMI_FIR_MASK_REG_RW = 0x0c011403ull;
static const uint64_t MC_OMI_FIR_MASK_REG_WO_AND = 0x0c011404ull;
static const uint64_t MC_OMI_FIR_MASK_REG_WO_OR = 0x0c011405ull;

static const uint32_t MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK = 0;
static const uint32_t MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN = 20;
static const uint32_t MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK = 20;
static const uint32_t MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN = 20;
static const uint32_t MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK = 40;
static const uint32_t MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN = 20;
static const uint32_t MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK = 60;
//<< [MC_OMI_FIR_MASK_REG]
// omic/reg00003.H

//>> [CTL_REGS_TX_CNTL5_PG]
static const uint64_t CTL_REGS_TX_CNTL5_PG = 0x800c644010012c3full;

static const uint32_t CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET = 48;
static const uint32_t CTL_REGS_TX_CNTL5_PG_TX_TDR_PULSE_OFFSET_LEN = 15;
//<< [CTL_REGS_TX_CNTL5_PG]
// omic/reg00003.H

//>> [DATASM_REGS_RX_CNTL6_PG]
static const uint64_t DATASM_REGS_RX_CNTL6_PG = 0x8009b04010012c3full;

static const uint32_t DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23 = 48;
static const uint32_t DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN = 8;
//<< [DATASM_REGS_RX_CNTL6_PG]
// omic/reg00003.H

//>> [CTL_REGS_RX_MODE17_PG]
static const uint64_t CTL_REGS_RX_MODE17_PG = 0x8008884010012c3full;

static const uint32_t CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2 = 48;
static const uint32_t CTL_REGS_RX_MODE17_PG_INC_DEC_AMT2_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE17_PG_THRESH3 = 51;
static const uint32_t CTL_REGS_RX_MODE17_PG_THRESH3_LEN = 5;
static const uint32_t CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3 = 56;
static const uint32_t CTL_REGS_RX_MODE17_PG_INC_DEC_AMT3_LEN = 3;
static const uint32_t CTL_REGS_RX_MODE17_PG_THRESH4 = 59;
static const uint32_t CTL_REGS_RX_MODE17_PG_THRESH4_LEN = 5;
//<< [CTL_REGS_RX_MODE17_PG]
// omic/reg00003.H

//>> [TX_CTL_SM_REGS_CTLSM_CNTL4_PG]
static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL4_PG = 0x800cdc4010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL4_PG_TX_PSAVE_FENCE_STS_IO_DL_16_23_LEN = 8;
//<< [TX_CTL_SM_REGS_CTLSM_CNTL4_PG]
// omic/reg00003.H

//>> [TX_CTL_SM_REGS_CTLSM_CNTL14_PG]
static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL14_PG = 0x800d2c4010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL14_PG_TX_PSAVE_FORCE_REQ_16_23_1_LEN = 8;
//<< [TX_CTL_SM_REGS_CTLSM_CNTL14_PG]
// omic/reg00003.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00003.H"
#endif
#endif
