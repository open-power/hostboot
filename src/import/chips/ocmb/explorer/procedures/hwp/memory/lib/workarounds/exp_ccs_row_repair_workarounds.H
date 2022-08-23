/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_ccs_row_repair_workarounds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
///
/// @file exp_ccs_row_repair_workarounds.H
/// @brief Workarounds for exp_ccs_row_repair_* procedures
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory
// EKB-Mirror-To: hostboot

#ifndef _EXP_ROW_REPAIR_WORKAROUNDS_H_
#define _EXP_ROW_REPAIR_WORKAROUNDS_H_

#include <fapi2.H>

namespace mss
{
namespace exp
{
namespace workarounds
{
///
/// @brief Disable periodic zq cal - Implemented as a work around for erratum on Explorer during concurrent CCS exp_row_repair.C
/// @param[in] i_target the target
/// @param[out] o_data the reg data
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode disable_zq_cal(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                 fapi2::buffer<uint64_t>& o_data);
}
}
}
#endif
