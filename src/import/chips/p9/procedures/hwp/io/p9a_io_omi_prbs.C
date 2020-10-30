/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9a_io_omi_prbs.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file p9a_io_omi_prbs.C
/// @brief Drive PRBS Data.
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 3
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
/// Drive PRBS
///
/// Procedure Prereq:
///     - System clocks are running.
///     - Scominit Procedure is completed.
///
/// @endverbatim
///----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <p9a_io_omi_prbs.H>
#include <p9_io_scom.H>
#include <p9_io_regs.H>

//-----------------------------------------------------------------------------
// Function Declarations
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Function Definitions
//-----------------------------------------------------------------------------

/**
 * @brief Rx Dc Calibration
 * @param[in] i_tgt         FAPI2 Target
 * @param[in] i_lane_vector Lane Vector
 * @param[in] i_data        Data to be set to rx_run_dccal
 * @retval ReturnCode
 */
fapi2::ReturnCode p9a_io_omi_prbs(const OMIC_TGT i_tgt, const bool i_on)
{
    FAPI_IMP("p9a_io_omi_prbs: I/O OMI Entering");
    const uint8_t GRP0 = 0;
    const uint8_t LN0  = 0;

    const uint32_t PATTERN_ZEROS  = 0;
    const uint32_t PATTERN_PRBS23 = 5;

    uint32_t l_data = PATTERN_ZEROS;

    if (i_on)
    {
        l_data = PATTERN_PRBS23;
    }

    FAPI_TRY(io::rmw(OPT_TX_ERR_INJ_CLOCK_ENABLE   , i_tgt, GRP0, LN0, 1));
    FAPI_TRY(io::rmw(OPT_TX_DRV_DATA_PATTERN_GCRMSG, i_tgt, GRP0, LN0, l_data));
    FAPI_TRY(io::rmw(OPT_TX_ERR_INJ_CLOCK_ENABLE   , i_tgt, GRP0, LN0, 0));

fapi_try_exit:
    FAPI_IMP("p9a_io_omi_prbs: I/O OMI Exiting");
    return fapi2::current_err;
}
