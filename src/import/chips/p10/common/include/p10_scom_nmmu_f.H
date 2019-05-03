/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_nmmu_f.H $       */
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

#ifndef __p10_scom_nmmu_f_H_
#define __p10_scom_nmmu_f_H_


namespace scomt
{
namespace nmmu
{


static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_MASK_REG_RW = 0x02010c03ull;
static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_MASK_REG_WO_AND = 0x02010c04ull;
static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_MASK_REG_WO_OR = 0x02010c05ull;

static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_MASK_REG_NX_CQ_FIR_MASK = 0;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_FIR_MASK_REG_NX_CQ_FIR_MASK_LEN = 20;
// nmmu/reg00015.H

}
}
#include "nmmu/reg00015.H"
#endif
