/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_restore_erepair.C $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_io_xbus_restore_erepair.C
/// @brief Restore eRepair.
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
/// A HWP that runs Restore eRepair.  This procedure should update the
/// bad lane vector and power down the bad lanes.
///
/// Procedure Prereq:
///     - System clocks are running.
///
/// @endverbatim
///----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "p9_io_xbus_restore_erepair.H"
#include "p9_io_gcr.H"
#include "p9_io_regs.H"
#include "p9_io_xbus_pdwn_lanes.H"

// ----------------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------------
fapi2::ReturnCode set_rx_bad_lane_vectors(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_rx_target,
    const uint8_t& i_rx_clock_group,
    const std::vector< uint8_t >& i_rx_bad_lanes);


/**
 * @brief A HWP that runs Restore eRepair.  This procedure should update the
 * bad lane vector and power down the bad lanes. If either rx_bad_lanes or
 * tx_bad_lanes are empty, the corresponding [rx/tx] target will not be
 * worked on.
 * @param[in] i_rx_target        FAPI2 Rx Target
 * @param[in] i_rx_clock_group   Rx Clock Group of Rx Target
 * @param[in] i_rx_bad_lanes     Vector of Rx Bad Lanes
 * @param[in] i_tx_target        FAPI2  Tx Target
 * @param[in] i_tx_clock_group   Tx Clock Group of Tx Target
 * @param[in] i_tx_bad_lanes     Vector of Tx Bad Lanes
 * @retval ReturnCode
 */
fapi2::ReturnCode
p9_io_xbus_restore_erepair(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_rx_target,
    const uint8_t& i_rx_clock_group,
    const std::vector< uint8_t >& i_rx_bad_lanes,
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_tx_target,
    const uint8_t& i_tx_clock_group,
    const std::vector< uint8_t >& i_tx_bad_lanes)
{
    FAPI_IMP("Entering...");
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;

    FAPI_DBG("Rx Bad Lanes Size: %d", i_rx_bad_lanes.size());
    FAPI_DBG("Tx Bad Lanes Size: %d", i_tx_bad_lanes.size());

    if( !i_rx_bad_lanes.empty() )
    {
        FAPI_TRY(set_rx_bad_lane_vectors(i_rx_target, i_rx_clock_group, i_rx_bad_lanes),
                 "Setting Rx Bad Lane Vectors Failed");
    }

    FAPI_EXEC_HWP(rc,
                  p9_io_xbus_pdwn_lanes,
                  i_rx_target,
                  i_rx_clock_group,
                  i_rx_bad_lanes,
                  i_tx_target,
                  i_tx_clock_group,
                  i_tx_bad_lanes);


fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}

/**
 * @brief Sets the rx bad lane vector
 * @param[in] i_rx_target        FAPI2 Rx Target
 * @param[in] i_rx_clock_group   Rx Clock Group of Target
 * @param[in] i_rx_bad_lanes     Vector of Bad Lanes
 */
fapi2::ReturnCode set_rx_bad_lane_vectors(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_rx_target,
    const uint8_t& i_rx_clock_group,
    const std::vector< uint8_t >& i_rx_bad_lanes)
{
    FAPI_IMP("Entering...");
    fapi2::ReturnCode rc                = fapi2::FAPI2_RC_SUCCESS;
    const uint8_t IO_GCR_REG_WIDTH      = 16;
    uint8_t bad_lane                    = 0;
    char target_string[fapi2::MAX_ECMD_STRING_LEN];

    Register < EDIP_RX_CTL_STAT2_E_PG > rx_bad_lane_0_15_reg;
    Register < EDIP_RX_CTL_STAT4_E_PG > rx_bad_lane_16_31_reg;

    fapi2::toString(i_rx_target, target_string, fapi2::MAX_ECMD_STRING_LEN);

    for(uint8_t index = 0; index < i_rx_bad_lanes.size(); ++index)
    {
        bad_lane = i_rx_bad_lanes[index];
        FAPI_DBG("Setting Bad Lane[%d/%d]:%d Target(%s:g%d)",
                 index,
                 i_rx_bad_lanes.size() - 1,
                 bad_lane,
                 target_string,
                 i_rx_clock_group);

        // For each group, the bad lane vector is split up into 2 registers due
        //   to GCR registers only being 16 bits wide.
        if( i_rx_bad_lanes[index] < IO_GCR_REG_WIDTH )
        {
            FAPI_TRY( rx_bad_lane_0_15_reg.read(i_rx_target, i_rx_clock_group),
                      "Reading rx_bad_lane_0_15_reg failed" );
            rx_bad_lane_0_15_reg.set( ( 0x8000 >> bad_lane ) | rx_bad_lane_0_15_reg.get() );
            FAPI_TRY( rx_bad_lane_0_15_reg.write(i_rx_target, i_rx_clock_group),
                      "Writing rx_bad_lane_0_15_reg failed" );
        }
        else
        {
            bad_lane -= IO_GCR_REG_WIDTH;
            FAPI_TRY( rx_bad_lane_16_31_reg.read(i_rx_target, i_rx_clock_group),
                      "Reading rx_bad_lane_16_31_reg failed" );
            rx_bad_lane_16_31_reg.set( ( 0x8000 >> bad_lane ) | rx_bad_lane_16_31_reg.get() );
            FAPI_TRY( rx_bad_lane_16_31_reg.write(i_rx_target, i_rx_clock_group),
                      "Writing rx_bad_lane_16_31_reg failed" );
        }

    }

fapi_try_exit:
    FAPI_IMP("Exiting...");
    return fapi2::current_err;
}

