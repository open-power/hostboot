/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_tdm_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file p10_fbc_tdm_utils.H
/// @brief Utility functions for TDM entry/exit (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

#ifndef _P10_FBC_TDM_UTILS_H_
#define _P10_FBC_TDM_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// DL Control state machine command encodings:
const uint8_t DL_CONTROL_COMMAND_ENTER_TDM = 0xA;
const uint8_t DL_CONTROL_COMMAND_EXIT_TDM = 0xB;
const uint8_t DL_CONTROL_COMMAND_PARTIAL_RESET = 0xE;

// PHY lane/group constants
const uint8_t  PHY_IOO_EVEN_START_LANE  = 0;
const uint8_t  PHY_IOO_EVEN_END_LANE    = 12;
const uint32_t PHY_IOO_EVEN_LANE_VECTOR = 0x00000FFF;

const uint8_t  PHY_IOO_ODD_START_LANE   = 12;
const uint8_t  PHY_IOO_ODD_END_LANE     = 24;
const uint32_t PHY_IOO_ODD_LANE_VECTOR  = 0x00FFF000;

const uint8_t  PHY_IOO_GROUP_NUMBER     = 0;

// PPE External Control Register Commands
enum p10_fbc_tdm_utils_ppe_cmd_t
{
    CLEAR      = 0,
    HALT       = 1,
    RESUME     = 2,
    STEP       = 3,
    TOGGLE     = 4,
    SOFT_RESET = 5,
    HARD_RESET = 6,
    FORCE_HALT = 7
};

// DL Control State Machine Commands
enum p10_fbc_tdm_utils_dl_cmd_t
{
    NOOP              = 0x0,
    RUN_LAT_MEASURE   = 0x1,
    OPTICS_NO_RESET   = 0x2,
    OPTICS_RESET      = 0x3,
    RST_CAP_REPLAY    = 0x4,
    RST_CAP_FRAME     = 0x5,
    RST_CAP_ACK_FIFO  = 0x6,
    RESET_PERF_COUNT  = 0x7,
    RETRAIN           = 0x8,
    RESET_MAX_TIMEOUT = 0x9,
    ENTER_TDM         = 0xA,
    EXIT_TDM          = 0xB,
    START_RECAL       = 0xC,
    RESET_RECAL       = 0xD,
    PART_RESET        = 0xE,
    RESET             = 0xF
};

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Mask PHY/DL/TL FIR bits associated with selected half-link
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to target (true=even,false=odd)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_fbc_tdm_utils_fir_mask(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const bool i_even_not_odd);

///
/// @brief Reset PHY/DL/TL FIR bits associated with selected half-link
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to target (true=even,false=odd)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_fbc_tdm_utils_fir_reset_all(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const bool i_even_not_odd);

///
/// @brief Reset DL FIR bits associated with selected half-link, preserving
///        link trained indicators.
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to target (true=even,false=odd)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_fbc_tdm_utils_fir_reset_err(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const bool i_even_not_odd);

///
/// @brief Unmask PHY/DL/TL FIR bits associated with selected half-link
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to target (true=even,false=odd)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_fbc_tdm_utils_fir_unmask(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const bool i_even_not_odd);

///
/// @brief Report link up/down status on selected half-link
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to target (true=even,false=odd)
/// @param[out] o_link_down     Boolean indicating link state (true=down,false=up)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_fbc_tdm_utils_tdm_query(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const bool i_even_not_odd,
        bool& o_link_down);

///
/// @brief Check that provided target and its connected endpoint are configured
///        for fabric/SMP protocol, and return vector containing both endpoints
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] o_targets        Vector containing input target and its connected
///                             endpoint target
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_fbc_tdm_utils_validate_targets(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOHS>>& o_targets);

///
/// @brief Utility function to send command to DL state machine (half-link)
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to target (true=even,false=odd)
/// @param[in] i_command        Encoded operation for DL state machine
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_fbc_tdm_utils_dl_send_command(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const bool i_even_not_odd,
        const p10_fbc_tdm_utils_dl_cmd_t i_command);

///
/// @brief Stop IO PPE to permit link re-retraining
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to target (true=even,false=odd)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_fbc_tdm_utils_ppe_halt(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const bool i_even_not_odd);

///
/// @brief Restart IO PPE to permit future recovery actions
///
/// @param[in] i_target         Reference to IOHS endpoint target
/// @param[in] i_even_not_odd   Identify half-link to target (true=even,false=odd)
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_fbc_tdm_utils_ppe_restart(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const bool i_even_not_odd);

} // extern "C"

#endif // _P10_FBC_TDM_UTILS_H_
