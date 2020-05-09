/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_7.H $       */
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

#ifndef __p10_scom_omic_7_H_
#define __p10_scom_omic_7_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


//>> [CTL_REGS_RX_MODE8_PG]
static const uint64_t CTL_REGS_RX_MODE8_PG = 0x8008404010012c3full;

static const uint32_t CTL_REGS_RX_MODE8_PG_RX_BO_TIME = 48;
static const uint32_t CTL_REGS_RX_MODE8_PG_RX_BO_TIME_LEN = 5;
//<< [CTL_REGS_RX_MODE8_PG]
// omic/reg00007.H

//>> [DATASM_REGS_RX_STAT12_PG]
static const uint64_t DATASM_REGS_RX_STAT12_PG = 0x800ae84010012c3full;

static const uint32_t DATASM_REGS_RX_STAT12_PG_OP_QUEUE_EMPTY_RO_SIGNAL = 48;
static const uint32_t DATASM_REGS_RX_STAT12_PG_OP_QUEUE_FULL_RO_SIGNAL = 49;
static const uint32_t DATASM_REGS_RX_STAT12_PG_OP_QUEUE_EMPTY_SPACE_RO_SIGNAL = 52;
static const uint32_t DATASM_REGS_RX_STAT12_PG_OP_QUEUE_EMPTY_SPACE_RO_SIGNAL_LEN = 4;
static const uint32_t DATASM_REGS_RX_STAT12_PG_RESULT_QUEUE_EMPTY_RO_SIGNAL = 56;
static const uint32_t DATASM_REGS_RX_STAT12_PG_RESULT_QUEUE_FULL_RO_SIGNAL = 57;
static const uint32_t DATASM_REGS_RX_STAT12_PG_RESULT_QUEUE_FULL_SPACE_RO_SIGNAL = 60;
static const uint32_t DATASM_REGS_RX_STAT12_PG_RESULT_QUEUE_FULL_SPACE_RO_SIGNAL_LEN = 4;
//<< [DATASM_REGS_RX_STAT12_PG]
// omic/reg00007.H

//>> [DATASM_REGS_RX_STAT22_PG]
static const uint64_t DATASM_REGS_RX_STAT22_PG = 0x800b384010012c3full;

static const uint32_t DATASM_REGS_RX_STAT22_PG_RX_DL_PHY_RECAL_REQ_16_23_RO_SIGNAL = 48;
static const uint32_t DATASM_REGS_RX_STAT22_PG_RX_DL_PHY_RECAL_REQ_16_23_RO_SIGNAL_LEN = 8;
//<< [DATASM_REGS_RX_STAT22_PG]
// omic/reg00007.H

//>> [MC_OMI_FIR_ACTION0_REG]
//ERRCODE: // Some of the name targets not found in address targets: omic
// No targets could be determined from the address.

static const uint64_t MC_OMI_FIR_ACTION0_REG = 0x0c011406ull;

static const uint32_t MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 = 0;
static const uint32_t MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN = 62;
//<< [MC_OMI_FIR_ACTION0_REG]
// omic/reg00007.H

//>> [MC_OMI_FIR_ACTION1_REG]
//ERRCODE: // Some of the name targets not found in address targets: omic
// No targets could be determined from the address.

static const uint64_t MC_OMI_FIR_ACTION1_REG = 0x0c011407ull;

static const uint32_t MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 = 0;
static const uint32_t MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN = 62;
//<< [MC_OMI_FIR_ACTION1_REG]
// omic/reg00007.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00007.H"
#endif
#endif
