/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_nmmu_b.H $       */
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

#ifndef __p10_scom_nmmu_b_H_
#define __p10_scom_nmmu_b_H_


namespace scomt
{
namespace nmmu
{


static const uint64_t CFG_NMMU_XLAT_CTL_REG0 = 0x02010c4aull;

static const uint32_t CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR = 0;
static const uint32_t CFG_NMMU_XLAT_CTL_REG0_MM_CFG_XLAT_CTL_HRMOR_LEN = 64;
// nmmu/reg00011.H

static const uint64_t FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0 = 0x02010c24ull;

static const uint32_t FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63 = 0;
static const uint32_t FBC_CQ_WRAP_NX_DEBUG_SNAPSHOT_0_NX_DEBUG_SNAPSHOT_B0_63_LEN = 64;
// nmmu/reg00011.H

static const uint64_t FIR1_WOF_REG = 0x02010c48ull;
// nmmu/reg00011.H

}
}
#include "nmmu/reg00011.H"
#endif
