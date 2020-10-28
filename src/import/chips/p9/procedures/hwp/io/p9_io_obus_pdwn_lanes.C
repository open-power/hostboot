/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_obus_pdwn_lanes.C $ */
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
/// @file p9_io_obus_pdwn_lanes.C
/// @brief Train the Link.
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
/// Run Dccal
///
/// Procedure Prereq:
///     - System clocks are running.
///
/// @endverbatim
///----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include <p9_io_obus_pdwn_lanes.H>
#include <p9_io_scom.H>
#include <p9_io_regs.H>

//-----------------------------------------------------------------------------
// Function Declarations
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Function Definitions
//-----------------------------------------------------------------------------

/**
 * @brief A I/O Obus Procedure to kickstart H1 AP
 * @param[in] i_tgt         FAPI2 Target
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_obus_kickstart_bad_h1ap(const OBUS_TGT i_tgt)
{
    FAPI_IMP("p9_io_obus_kickstart_bad_h1ap: I/O Obus Entering");
    const uint8_t GRP0 = 0;
    const uint8_t LN0  = 0;

    uint64_t l_data  = 0;
    uint64_t l_data2 = 0;

    FAPI_TRY(io::read(OPT_RX_EYE_OPT_STATE, i_tgt, GRP0, LN0, l_data),
             "Error reading OPT_RX_EYE_OPT_STATE");

    FAPI_TRY(io::read(OPT_RX_EYE_OPT_STATE, i_tgt, GRP0, LN0, l_data2),
             "Error reading OPT_RX_EYE_OPT_STATE");

    if (io::get(OPT_RX_EYE_OPT_STATE, l_data) == 0xFC && io::get(OPT_RX_EYE_OPT_STATE, l_data2) == 0xFC)
    {
        // Setup the interrupt state machine
        FAPI_TRY(io::rmw(OPT_RX_INT_ENABLE_ENC, i_tgt, GRP0, LN0, 0x05));
        FAPI_TRY(io::rmw(OPT_RX_INT_CURRENT_STATE, i_tgt, GRP0, LN0, 0xFC));
        FAPI_TRY(io::rmw(OPT_RX_INT_NEXT_STATE, i_tgt, GRP0, LN0, 0xFC));
        FAPI_TRY(io::rmw(OPT_RX_INT_GOTO_STATE, i_tgt, GRP0, LN0, 0xFD));

        // Enable the state machine
        FAPI_TRY(io::rmw(OPT_RX_INT_MODE, i_tgt, GRP0, LN0, 0x02));

        // Enable the state machine
        FAPI_TRY(io::rmw(OPT_RX_INT_MODE, i_tgt, GRP0, LN0, 0x00));

        // Setup the interrupt state machine
        FAPI_TRY(io::rmw(OPT_RX_INT_ENABLE_ENC, i_tgt, GRP0, LN0, 0x00));
        FAPI_TRY(io::rmw(OPT_RX_INT_CURRENT_STATE, i_tgt, GRP0, LN0, 0x00));
        FAPI_TRY(io::rmw(OPT_RX_INT_NEXT_STATE, i_tgt, GRP0, LN0, 0x00));
        FAPI_TRY(io::rmw(OPT_RX_INT_GOTO_STATE, i_tgt, GRP0, LN0, 0x00));

    }

fapi_try_exit:
    FAPI_IMP("p9_io_obus_kickstart_bad_h1ap: I/O Obus Exiting");
    return fapi2::current_err;
}


/**
 * @brief A I/O Obus Procedure to power down lanes
 * on every instance of the OBUS.
 * @param[in] i_tgt         FAPI2 Target
 * @param[in] i_lane_vector Lanve Vector
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_obus_pdwn_lanes(const OBUS_TGT i_tgt, const uint32_t i_lane_vector)
{
    FAPI_IMP("p9_io_obus_pdwn_lanes: I/O Obus Entering");
    const uint8_t GRP0  = 0;
    const uint8_t LN0   = 0;
    const uint8_t LANES = 24;
    const uint8_t  TIMEOUT = 200;
    const uint64_t DLY_1MS = 1000000;
    const uint64_t DLY_1MIL_CYCLES = 1000000;

    char l_tgtStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_tgt, l_tgtStr, fapi2::MAX_ECMD_STRING_LEN);
    FAPI_DBG("I/O Obus Pdwn Lanes %s, Lane Vector(0x%X)", l_tgtStr, i_lane_vector);

    fapi2::ATTR_CHIP_EC_FEATURE_HW446279_USE_PPE_Type l_hw446279_use_ppe;
    auto l_chip = i_tgt.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW446279_USE_PPE,
                           l_chip,
                           l_hw446279_use_ppe));

    if(l_hw446279_use_ppe)
    {
        FAPI_DBG("Skipping I/O Obus Pdwn Lanes %s, Lane Vector(0x%X)", l_tgtStr, i_lane_vector);
    }
    else
    {

        // set rx_rc_enable_auto_recal = 0
        FAPI_TRY(io::rmw(OPT_RX_RC_ENABLE_AUTO_RECAL, i_tgt, GRP0, LN0, 0x0),
                 "Error setting OPT_RX_ENABLE_AUTO_RECAL");

        // Power down Per-Lane Registers
        for(uint8_t lane = 0; lane < LANES; ++lane)
        {
            if(((0x1 << lane) & i_lane_vector) != 0)
            {
                uint64_t l_data = 0;

                // poll for rx_lane_busy = 0
                for (uint8_t l_count = 0; l_count < TIMEOUT; ++l_count)
                {
                    FAPI_TRY(io::read(OPT_RX_LANE_BUSY, i_tgt, GRP0, lane, l_data),
                             "Error reading OPT_RX_LANE_BUSY");

                    if (io::get(OPT_RX_LANE_BUSY, l_data) == 0)
                    {
                        break;
                    }
                    else
                    {
                        FAPI_TRY(p9_io_obus_kickstart_bad_h1ap(i_tgt));
                    }

                    FAPI_TRY(fapi2::delay(DLY_1MS, DLY_1MIL_CYCLES));
                }

                FAPI_ASSERT((io::get(OPT_RX_LANE_BUSY, l_data) == 0),
                            fapi2::IO_OBUS_PDWN_BAD_LANE_TIMEOUT()
                            .set_TARGET(i_tgt)
                            .set_GROUP(GRP0)
                            .set_LANE(lane),
                            "Timeout waiting for RX lane busy status");

                FAPI_TRY(io::rmw(OPT_RX_LANE_ANA_PDWN, i_tgt, GRP0, lane, 0x01));
                FAPI_TRY(io::rmw(OPT_RX_LANE_DIG_PDWN, i_tgt, GRP0, lane, 0x01));
                FAPI_TRY(io::rmw(OPT_TX_LANE_PDWN    , i_tgt, GRP0, lane, 0x01));

                // set rx_lane_disabled = 1
                FAPI_TRY(io::rmw(OPT_RX_LANE_DISABLED, i_tgt, GRP0, lane, 0x1),
                         "Error setting OPT_RX_LANE_DISABLED");
            }

        }

        // set rx_rc_enable_auto_recal = 1
        FAPI_TRY(io::rmw(OPT_RX_RC_ENABLE_AUTO_RECAL, i_tgt, GRP0, LN0, 0x1),
                 "Error setting OPT_RX_ENABLE_AUTO_RECAL");
    }

fapi_try_exit:
    FAPI_IMP("p9_io_obus_pdwn_lanes: I/O Obus Exiting");
    return fapi2::current_err;
}
