/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_dccal.H $               */
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
/// @file p9_io_xbus_dccal.H
/// @brief Run Dccal on the link.
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 2
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------

#ifndef _P9_IO_XBUS_DCCAL_H
#define _P9_IO_XBUS_DCCAL_H

//-----------------------------------------------------------------------------
//  fapi2 Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>


typedef fapi2::ReturnCode (*p9_io_xbus_dccal_FP_t)
( const fapi2::Target < fapi2::TARGET_TYPE_XBUS>&,
  const uint8_t& );

extern "C"
{

    /**
     * @brief A I/O EDI+ Procedure that runs Rx Dccal and Tx Z Impedance calibration
     * on every instance of the EDI+ XBUS.
     * @param[in] i_target FAPI2 Target
     * @retval ReturnCode
     */
    fapi2::ReturnCode
    p9_io_xbus_dccal(
        const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_target,
        const uint8_t&                                   i_group );

} // extern "C"

#endif // _P9_IO_XBUS_DCCAL_H
