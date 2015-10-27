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
/// *HWP Level            : 1
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

// ----------------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------------

/**
 * @brief A HWP that runs Restore eRepair.  This procedure should update the
 * bad lane vector and power down the bad lanes.
 * @param[in] i_rx_target FAPI2 Rx Target
 * @param[in] i_tx_target FAPI2 Tx Target
 * @param[in] i_rx_bad_lanes Vector of Rx Bad Lanes
 * @param[in] i_tx_bad_lanes Vector of Tx Bad Lanes
 * @retval ReturnCode
 */
fapi2::ReturnCode
p9_io_xbus_restore_erepair(
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_rx_target,
    const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_tx_target,
    std::vector< uint8_t >& i_rx_bad_lanes,
    std::vector< uint8_t >& i_tx_bad_lanes)
{
    FAPI_IMP("Entering...");
    fapi2::ReturnCode rc = 0;
#if 0

fapi_try_exit:
#endif
    FAPI_IMP("Exiting...");
    return fapi2::FAPI2_RC_SUCCESS;
}

