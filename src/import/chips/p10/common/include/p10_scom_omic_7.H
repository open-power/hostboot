/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_7.H $       */
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

#ifndef __p10_scom_omic_7_H_
#define __p10_scom_omic_7_H_


namespace scomt
{
namespace omic
{


//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t CTL_REGS_RX_MODE8_PG = 0x800840600c00143full;

static const uint32_t CTL_REGS_RX_MODE8_PG_RX_BO_TIME = 48;
static const uint32_t CTL_REGS_RX_MODE8_PG_RX_BO_TIME_LEN = 5;
// omic/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_STAT12_PG = 0x800ae8600c00143full;
// omic/reg00007.H

//ERRCODE: // Some of the name targets not found in address targets: omic

static const uint64_t DATASM_REGS_RX_STAT22_PG = 0x800b38600c00143full;
// omic/reg00007.H

static const uint64_t MC_OMI_FIR_ACTION0_REG = 0x0c011746ull;

static const uint32_t MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0 = 0;
static const uint32_t MC_OMI_FIR_ACTION0_REG_MC_OMI_FIR_ACTION0_LEN = 62;
// omic/reg00007.H

static const uint64_t MC_OMI_FIR_ACTION1_REG = 0x0c011747ull;

static const uint32_t MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1 = 0;
static const uint32_t MC_OMI_FIR_ACTION1_REG_MC_OMI_FIR_ACTION1_LEN = 62;
// omic/reg00007.H

}
}
#include "omic/reg00007.H"
#endif
