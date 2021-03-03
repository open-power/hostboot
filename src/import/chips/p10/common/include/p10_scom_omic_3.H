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

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00003.H"
#endif
#endif
