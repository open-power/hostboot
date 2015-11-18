/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_xbus_read_erepair.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_io_xbus_read_erepair.C
/// @brief Read eRepair.
///----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 2
/// *HWP Consumed by      : FSP:HB
///----------------------------------------------------------------------------
///
/// @verbatim
/// High-level procedure flow:
///
/// A HWP that runs Read eRepair. This procedure reads the current bad
/// lanes and passes by reference the lane numbers in a vector.
///
/// Procedure Prereq:
///     - System clocks are running.
///
/// @endverbatim
///----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "p9_io_xbus_read_erepair.H"
#include "p9_io_gcr.H"
#include "p9_io_regs.H"

// ----------------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------------


/**
 * @brief A HWP that runs Read eRepair. This procedure reads the current bad
 * lanes and passes by reference the lane numbers in a vector.
 * @param[in] i_target        Reference to Target
 * @param[in] i_clock_group   Clock Group of Target
 * @param[out] o_bad_lanes    Vector of bad lanes
 * @retval ReturnCode
 */
fapi2::ReturnCode
p9_io_xbus_read_erepair(const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
                        const uint8_t& i_clock_group,
                        std::vector< uint8_t >& o_bad_lanes)
{
    FAPI_IMP("Entering...");

    fapi2::ReturnCode rc           = fapi2::FAPI2_RC_SUCCESS;
    const uint16_t BAD_LANES_3PLUS = 3;
    const uint16_t BAD_LANES_2     = 2;
    const uint16_t BAD_LANES_1     = 1;
    const uint16_t BAD_LANES_0     = 0;
    Register < EDIP_RX_GLBSM_STAT9_E_PG > rx_bad_lanes_reg;

    o_bad_lanes.clear();

    FAPI_TRY(rx_bad_lanes_reg.read(i_target, i_clock_group), "Reading Bad Lane Code Failed.");
    FAPI_DBG( "Bad Lane Code: %d", rx_bad_lanes_reg.get<EDIP_RX_BAD_LANE_CODE>() );

    switch( rx_bad_lanes_reg.get<EDIP_RX_BAD_LANE_CODE>() )
    {
        case BAD_LANES_3PLUS:
            FAPI_DBG( "Bad Lane: Three or more bad lanes found." );

        case BAD_LANES_2:
            FAPI_DBG( "Bad Lane 2: %d", rx_bad_lanes_reg.get<EDIP_RX_BAD_LANE2>() );
            o_bad_lanes.push_back( (uint8_t)rx_bad_lanes_reg.get<EDIP_RX_BAD_LANE2>() );

        case BAD_LANES_1:
            FAPI_DBG( "Bad Lane 1: %d", rx_bad_lanes_reg.get<EDIP_RX_BAD_LANE1>() );
            o_bad_lanes.push_back( (uint8_t)rx_bad_lanes_reg.get<EDIP_RX_BAD_LANE1>() );
            break;

        case BAD_LANES_0:
            FAPI_DBG( "No Bad Lanes" );

        default:
            break;
    }

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}

