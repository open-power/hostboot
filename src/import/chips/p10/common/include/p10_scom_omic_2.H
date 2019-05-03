/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_2.H $       */
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

#ifndef __p10_scom_omic_2_H_
#define __p10_scom_omic_2_H_


namespace scomt
{
namespace omic
{


//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t CTL_REGS_RX_MODE9_PG = 0x800848600c00143full;

static const uint32_t CTL_REGS_RX_MODE9_PG_INC2 = 48;
static const uint32_t CTL_REGS_RX_MODE9_PG_INC2_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE9_PG_DEC2 = 52;
static const uint32_t CTL_REGS_RX_MODE9_PG_DEC2_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE9_PG_INC3 = 56;
static const uint32_t CTL_REGS_RX_MODE9_PG_INC3_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE9_PG_DEC3 = 60;
static const uint32_t CTL_REGS_RX_MODE9_PG_DEC3_LEN = 4;
// omic/reg00002.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_STAT13_PG = 0x800af0600c00143full;
// omic/reg00002.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_STAT23_PG = 0x800b40600c00143full;
// omic/reg00002.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t TX_CTL_SM_REGS_FIR_RESET_PG = 0x800c94600c00143full;

static const uint32_t TX_CTL_SM_REGS_FIR_RESET_PG_CLR_PAR_ERRS = 62;
static const uint32_t TX_CTL_SM_REGS_FIR_RESET_PG_FIR_RESET = 63;
// omic/reg00002.H

}
}
#include "omic/reg00002.H"
#endif
