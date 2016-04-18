/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_pdwn_lanes.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_io_xbus_pdwn_lanes.C
/// @brief P9 Xbus Power Down Lanes.
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
/// A HWP that powers down lanes.  This procedure should power down rx lanes,
///   tx lanes, or both rx & tx lanes.
///
/// Procedure Prereq:
///     - System clocks are running.
///
/// @endverbatim
///----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "p9_io_xbus_pdwn_lanes.H"
#include "p9_io_scom.H"
#include "p9_io_regs.H"

// ----------------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------------
fapi2::ReturnCode rx_pdwn_lanes(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t i_clock_group,
    const std::vector< uint8_t >& i_bad_lanes);
fapi2::ReturnCode tx_pdwn_lanes(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t i_clock_group,
    const std::vector< uint8_t >& i_bad_lanes);


/**
 * @brief A HWP that powers down the specified lanes on a given EDI+ Xbus
 *   target.  The rx & tx lanes in the vectors will be powered down on the
 *   given target.  Note: This procedure does not power down any lanes on the
 *   connected target of the link.
 * @param[in] i_target        FAPI2 Target
 * @param[in] i_group         Clock Group of Target
 * @param[in] i_rx_bad_lanes  Vector of Rx Bad Lanes
 * @param[in] i_tx_bad_lanes  Vector of Tx Bad Lanes
 * @retval ReturnCode
 */
fapi2::ReturnCode p9_io_xbus_pdwn_lanes(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                  i_group,
    const std::vector< uint8_t >&                   i_rx_bad_lanes,
    const std::vector< uint8_t >&                   i_tx_bad_lanes)
{
    FAPI_IMP("Entering...");

    FAPI_DBG("Rx Bad Lanes Size: %d", i_rx_bad_lanes.size());

    if( !i_rx_bad_lanes.empty() )
    {
        FAPI_TRY(rx_pdwn_lanes( i_target, i_group, i_rx_bad_lanes),
                 "Rx Power Down Lanes Failed");
    }

    FAPI_DBG("Tx Bad Lanes Size: %d", i_tx_bad_lanes.size());

    if( !i_tx_bad_lanes.empty() )
    {
        FAPI_TRY(tx_pdwn_lanes( i_target, i_group, i_tx_bad_lanes),
                 "Tx Power Down Lanes Failed");
    }

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}

/**
 * @brief A HWP that powers down the specified lanes on a given EDI+ Xbus
 *   target.  The rx lanes in the vector will be powered down on the
 *   given target.  Note: This procedure does not power down any lanes on the
 *   connected target of the link.
 * @param[in] i_target        FAPI2 Target
 * @param[in] i_clock_group   Clock Group of Target
 * @param[in] i_bad_lanes     Vector of Bad Lanes
 * @retval ReturnCode
 */
fapi2::ReturnCode rx_pdwn_lanes(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                  i_clock_group,
    const std::vector< uint8_t >&                   i_bad_lanes )
{
    FAPI_DBG( "rx_pdwn_lanes: Enter Size(%d)", i_bad_lanes.size() );
    char target_string[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString( i_target, target_string, fapi2::MAX_ECMD_STRING_LEN );

    if( !i_bad_lanes.empty() )
    {
        for( uint8_t index = 0; index < i_bad_lanes.size(); ++index )
        {
            FAPI_DBG("Powering Down Rx Lane[%d/%d]: Target(%s:g%d:l%d)",
                     index,
                     i_bad_lanes.size() - 1,
                     target_string,
                     i_clock_group,
                     i_bad_lanes[index] );

            FAPI_TRY( io::rmw( EDIP_RX_LANE_DIG_PDWN, i_target, i_clock_group, i_bad_lanes[index], 1 ),
                      "Failed rmw rx dig pdwn reg" );

            FAPI_TRY( io::rmw( EDIP_RX_LANE_ANA_PDWN, i_target, i_clock_group, i_bad_lanes[index], 1 ),
                      "Failed rmw rx ana pdwn reg" );

        }
    }

fapi_try_exit:
    FAPI_IMP( "rx_pdwn_lanes: Exiting." );
    return fapi2::current_err;
}

/**
 * @brief A HWP that powers down the specified lanes on a given EDI+ Xbus
 *   target.  The tx lanes in the vector will be powered down on the
 *   given target.  Note: This procedure does not power down any lanes on the
 *   connected target of the link.
 * @param[in] i_target        FAPI2 Target
 * @param[in] i_group         Clock Group of Target
 * @param[in] i_bad_lanes     Vector of Bad Lanes
 * @retval ReturnCode
 */
fapi2::ReturnCode tx_pdwn_lanes(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target,
    const uint8_t&                                  i_group,
    const std::vector< uint8_t >&                   i_bad_lanes )
{
    FAPI_IMP( "tx_pdwn_lanes: Enter Size(%d)", i_bad_lanes.size() );
    const uint8_t LANE_00 = 0;
    uint8_t l_msbswap = 0;
    uint8_t l_end_lane = 0;
    uint8_t l_lane = 0;
    uint64_t l_data = 0;
    char target_string[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString( i_target, target_string, fapi2::MAX_ECMD_STRING_LEN );

    if( !i_bad_lanes.empty() )
    {
        FAPI_TRY( io::read( EDIP_TX_MSBSWAP, i_target, i_group, LANE_00, l_data ),
                  "Failed read edip_tx_msbswap");
        l_msbswap = io::get(EDIP_TX_MSBSWAP, l_data );

        if( l_msbswap == 0x1 )
        {
            FAPI_TRY( io::read( EDIP_TX_END_LANE_ID, i_target, i_group, LANE_00, l_data ),
                      "Failed read edip_tx_end_lane_id");
            l_end_lane = io::get(EDIP_TX_END_LANE_ID, l_data );
            FAPI_DBG( "edip_tx_msbswap: tx_end_lane_id(%d).", l_end_lane );
        }

        for(uint8_t index = 0; index < i_bad_lanes.size(); ++index )
        {
            l_lane = i_bad_lanes[index];

            if( l_msbswap == 0x1 )
            {
                l_lane = l_end_lane - i_bad_lanes[index];
                FAPI_DBG( "edip_tx_msbswap: tx_end_lane_id(%d) lane(%d -> %d).",
                          l_end_lane, i_bad_lanes[index], l_lane );
            }

            FAPI_DBG("Powering Down Tx Lane[%d/%d]: Target(%s:g%d:l%d)",
                     index,
                     i_bad_lanes.size() - 1,
                     target_string,
                     i_group,
                     l_lane );

            FAPI_TRY( io::rmw( EDIP_TX_LANE_PDWN, i_target, i_group, l_lane, 1 ),
                      "Failed rmw tx pdwn");

        }
    }

fapi_try_exit:
    FAPI_IMP( "tx_pdwn_lanes: Exiting" );
    return fapi2::current_err;
}
