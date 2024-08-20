/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/procedures/hwp/pmic_ddr5/pmic_periodic_telemetry_ddr5.H $ */
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
/// @file pmic_periodic_telemetry_ddr5.H
/// @brief To be run periodically at runtime to collect telemetry data of 4U parts
///
// *HWP HWP Owner: Sneha Kadam <sneha.kadam1@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HBRT
// EKB-Mirror-To: hostboot

#ifndef __PMIC_PERIODIC_TELEMETRY_DDR5_H__
#define __PMIC_PERIODIC_TELEMETRY_DDR5_H__

#include <fapi2.H>
#include <lib/utils/pmic_common_utils_ddr5.H>
#include <lib/utils/pmic_periodic_telemetry_utils_ddr5.H>
#include <hwp_data_stream.H>

typedef fapi2::ReturnCode (*pmic_periodic_telemetry_ddr5_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    fapi2::hwp_data_ostream&);

extern "C"
{
    ///
    /// @brief Runtime periodic telemetry data collection for 4U parts
    ///
    /// @param[in] i_ocmb_target ocmb target
    /// @param[out] o_data hwp_data_ostream of struct information
    /// @param[in] i_reset_dqs_recal_count reset DQS recal count. This count should be
    ///            reset every 24 hours only. Others calling this HWP otherwise have to
    ///            make sure to pass DONT_RESET_COUNT in order to keep the count as is
    /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
    /// @note The functional flow of the periodic telemetry tool has been take from
    ///       "Redundant PoD5 - Functional Specification dated 20230421 version 0.10"
    ///       document provided by the Power team
    ///
    fapi2::ReturnCode pmic_periodic_telemetry_ddr5(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_target,
            fapi2::hwp_data_ostream& o_data, const uint8_t i_reset_dqs_recal_count = RESET_RECAL_COUNT);
}

#endif
