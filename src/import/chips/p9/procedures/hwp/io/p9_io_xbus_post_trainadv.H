/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_io_xbus_post_trainadv.H $           */
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
/// @file p9_io_xbus_post_trainadv.H
/// @brief Post-Training PHY Status Function.
///
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 1
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------

#ifndef _P9_IO_XBUS_POST_TRAINADV_H_
#define _P9_IO_XBUS_POST_TRAINADV_H_

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include <fapi2.H>

//-----------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_io_xbus_post_trainadv_FP_t)
(const fapi2::Target < fapi2::TARGET_TYPE_XBUS >&);

// ----------------------------------------------------------------------------
// Constant Definitions
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Function Protoypes
// ----------------------------------------------------------------------------
extern "C" {

    /**
     * @brief A simple HWP that runs after io_run_trainig.
     *  This function is called on every Xbus.
     * @param[in] iTarget Reference to Target
     * @retval ReturnCode
     */
    fapi2::ReturnCode
    p9_io_xbus_post_trainadv(const fapi2::Target< fapi2::TARGET_TYPE_XBUS >& i_target);

} // extern "C"

#endif // _P9_IO_XBUS_POST_TRAINADV_H_
