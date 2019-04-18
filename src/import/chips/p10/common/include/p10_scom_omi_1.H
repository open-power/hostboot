/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_1.H $        */
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

#ifndef __p10_scom_omi_1_H_
#define __p10_scom_omi_1_H_


namespace scomt
{
namespace omi
{


static const uint64_t PM_REGS_DLR_APOR = 0x0c011ebaull;

static const uint32_t PM_REGS_DLR_APOR_ACTIVITY_ACCUM = 0;
static const uint32_t PM_REGS_DLR_APOR_ACTIVITY_ACCUM_LEN = 32;
static const uint32_t PM_REGS_DLR_APOR_BASE_ACCUM = 32;
static const uint32_t PM_REGS_DLR_APOR_BASE_ACCUM_LEN = 32;
// omi/reg00097.H

}
}
#include "omi/reg00097.H"
#endif
