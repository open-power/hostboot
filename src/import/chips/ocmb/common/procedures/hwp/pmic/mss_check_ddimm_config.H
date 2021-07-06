/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic/mss_check_ddimm_config.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file mss_check_ddimm_config.H
/// @brief Procedure to assert valid PMIC/GI2C target config
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

// EKB-Mirror-To: hostboot

#ifndef __MSS_CHECK_DDIMM_CONFIG_H__
#define __MSS_CHECK_DDIMM_CONFIG_H__

#include <fapi2.H>

typedef fapi2::ReturnCode (*mss_check_ddimm_config_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&);

extern "C"
{
    ///
    /// @brief Assert valid PMIC/GI2C target config
    /// @param[in] i_target ocmb target
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode mss_check_ddimm_config(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target);

} // extern "C"

#endif
