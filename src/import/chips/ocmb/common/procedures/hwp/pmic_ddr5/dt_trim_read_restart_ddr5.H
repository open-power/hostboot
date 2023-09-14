/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/dt_trim_read_restart_ddr5.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file dt_trim_read_restart_ddr5.H
/// @brief To be run when a DT is unreachable
///
// *HWP HWP Owner: David J. Chung <dj.chung@ibm.com>
// *HWP HWP Backup: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#ifndef __DT_TRIM_READ_RESTART_DDR5_H__
#define __DT_TRIM_READ_RESTART_DDR5_H__

#include <fapi2.H>
#include <lib/utils/pmic_common_utils_ddr5.H>

///
/// @brief Trim read reset data
///
enum trim_data : uint8_t
{
    TRIM_UNLOCK              = 0x0E,
    TRIM_LOCK                = 0x0F,
    TRIM_RD_INIT_0           = 0x3F,
    TRIM_RD_INIT_1           = 0x21,
    EXTENDABLE_RD_PULSE_EN_0 = 0x40,
    EXTENDABLE_RD_PULSE_EN_1 = 0x80,
    TRIM_PASSWORD_0          = 0xA5,
    TRIM_PASSWORD_1          = 0x5A,
};

typedef fapi2::ReturnCode (*dt_trim_read_restart_ddr5_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&);

extern "C"
{
    ///
    /// @brief Reset DT's via trim read
    /// @param[in] i_ocmb_target OCMB target
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    fapi2::ReturnCode dt_trim_read_restart_ddr5 (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target);
}

#endif
