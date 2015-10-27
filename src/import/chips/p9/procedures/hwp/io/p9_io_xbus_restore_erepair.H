/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_restore_erepair.H $     */
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
///----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 1
/// *HWP Consumed by      : FSP:HB
///----------------------------------------------------------------------------

#ifndef _P9_IO_XBUS_RESTORE_EREPAIR_H_
#define _P9_IO_XBUS_RESTORE_EREPAIR_H_

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include <fapi2.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_io_xbus_restore_erepair_FP_t) (
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >&,
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >&,
    std::vector< uint8_t >&,
    std::vector< uint8_t >&);

extern "C"
{

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
        std::vector< uint8_t >& i_tx_bad_lanes);

} // extern "C"

#endif // _P9_IO_XBUS_RESTORE_EREPAIR_H_
