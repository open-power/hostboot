/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_pdwn_lanes.H $          */
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
///----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 2
/// *HWP Consumed by      : FSP:HB
///----------------------------------------------------------------------------

#ifndef _P9_IO_XBUS_PDWN_LANES_H_
#define _P9_IO_XBUS_PDWN_LANES_H_

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include <fapi2.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_io_xbus_pdwn_lanes_FP_t) (
    const fapi2::Target < fapi2::TARGET_TYPE_XBUS >&,
    const uint8_t&,
    const std::vector< uint8_t >&,
    const std::vector< uint8_t >&);

extern "C"
{

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
        const std::vector< uint8_t >&                   i_tx_bad_lanes);

} // extern "C"

#endif // _P9_IO_XBUS_PDWN_LANES_H_
