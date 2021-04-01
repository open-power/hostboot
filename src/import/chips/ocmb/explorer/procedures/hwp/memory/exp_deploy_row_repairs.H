/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_deploy_row_repairs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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

/// @file exp_deploy_row_repairs.H
/// @brief Row Repair Procedure
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#ifndef __EXP_DEPLOY_ROW_REPAIR__
#define __EXP_DELPOY_ROW_REPAIR__

#include <fapi2.H>

typedef fapi2::ReturnCode (*exp_deploy_row_repairs_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&);

extern "C"
{

    ///
    /// @brief Deploy SPPR row repair
    /// @param[in] i_target_ocmb ocmb target
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode exp_deploy_row_repairs(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_ocmb);

}
#endif
