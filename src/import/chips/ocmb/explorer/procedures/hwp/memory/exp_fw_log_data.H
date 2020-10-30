/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_fw_log_data.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file exp_fw_log_data.H
/// @brief Procedure declaration to get Explorer log data
///
// ----------------------------------------
// *HWP HWP Owner: Matt Derksen <mderkse1@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB
// ----------------------------------------
#ifndef __EXP_FW_LOG_DATA__
#define __EXP_FW_LOG_DATA__

#include <fapi2.H>
#include <vector>
#include <lib/inband/exp_fw_log.H>

// Required for Cronus
typedef fapi2::ReturnCode (*exp_active_log_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    std::vector<uint8_t>& );

typedef fapi2::ReturnCode (*exp_saved_log_FP_t) (
    const mss::exp::ib::exp_image,
    const uint32_t,
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    std::vector<uint8_t>& );

typedef fapi2::ReturnCode (*exp_clear_active_log_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& );

typedef fapi2::ReturnCode (*exp_clear_saved_log_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& );

extern "C"
{

    ///
    /// @brief Grab active log entries from Explorer RAM
    /// @param[in] i_target the controller
    /// @param[out] o_data - where to put error log data
    ///
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode exp_active_log(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbTarget,
        std::vector<uint8_t>& o_data );

    ///
    /// @brief Grab saved log entries from Explorer SPI flash
    /// @param[in] i_image - 0 = image A, 1 = image B
    /// @param[in] i_offset - offset in image to start grabbing data (0-0x0FFFFF)
    /// @param[in] i_target the controller
    /// @param[in/out] io_data -
    ///               [in] size = amount of log data to gather (0-0x10000)
    ///               [out]where to put error log data
    ///
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode exp_saved_log(
        const mss::exp::ib::exp_image i_image,
        const uint32_t i_offset,
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbTarget,
        std::vector<uint8_t>& io_data );

    ///
    /// @brief Clear active log entries from Explorer RAM
    /// @param[in] i_target the controller
    ///
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode exp_clear_active_log(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbTarget );

    ///
    /// @brief Clear saved log entries from Explorer SPI flash
    /// @param[in] i_target the controller
    ///
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode exp_clear_saved_log(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbTarget );

}// extern C
#endif
