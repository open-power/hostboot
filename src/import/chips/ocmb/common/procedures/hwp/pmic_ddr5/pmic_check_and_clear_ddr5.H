/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/pmic_check_and_clear_ddr5.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file pmic_check_and_clear_ddr5.H
/// @brief To be run to clear the status bits after issuing a reset
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#ifndef __PMIC_CHECK_AND_CLEAR_DDR5_H__
#define __PMIC_CHECK_AND_CLEAR_DDR5_H__

#include <fapi2.H>

static constexpr uint8_t CLEAR_STATUS_0 = 0x08;
static constexpr uint8_t CLEAR_STATUS_1 = 0x02;
static constexpr uint8_t CLEAR_STATUS_2 = 0x00;
static constexpr uint8_t CLEAR_STATUS_3 = 0x20;

typedef fapi2::ReturnCode (*pmic_check_and_clear_ddr5_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&);

extern "C"
{
    ///
    /// @brief To be run to clear the status bits after issuing a reset
    ///
    /// @param[in] i_ocmb_target ocmb target
    /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
    /// @note For 4U: The below HWP is based on section 10.8 of
    ///       "Redundant PoD5 - Functional Specification dated 20240219 version 0.16"
    ///       document provided by the Power team
    ///       For 2U: The below HWP is based on section 10.8 of
    ///       "Non-Redundant PoD5 - Functional Specification dated 20240220 version 0.04"
    ///       document provided by the Power team
    ///
    fapi2::ReturnCode pmic_check_and_clear_ddr5(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target);
}

#endif
