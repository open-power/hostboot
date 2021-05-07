/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_2.H $       */
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

#ifndef __p10_scom_iohs_2_H_
#define __p10_scom_iohs_2_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_FIR_ACTION0_REG]
static const uint64_t DLP_FIR_ACTION0_REG = 0x18011006ull;

static const uint32_t DLP_FIR_ACTION0_REG_DLP_FIR_ACTION0 = 0;
static const uint32_t DLP_FIR_ACTION0_REG_DLP_FIR_ACTION0_LEN = 62;
//<< [DLP_FIR_ACTION0_REG]
// iohs/reg00008.H

//>> [DLP_FIR_ACTION1_REG]
static const uint64_t DLP_FIR_ACTION1_REG = 0x18011007ull;

static const uint32_t DLP_FIR_ACTION1_REG_DLP_FIR_ACTION1 = 0;
static const uint32_t DLP_FIR_ACTION1_REG_DLP_FIR_ACTION1_LEN = 62;
//<< [DLP_FIR_ACTION1_REG]
// iohs/reg00008.H

//>> [IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG]
static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG = 0x800a880010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN = 8;
//<< [IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG]
// iohs/reg00011.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00008.H"
#include "iohs/reg00009.H"
#include "iohs/reg00010.H"
#include "iohs/reg00011.H"
#endif
#endif
