/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_linktrain.H $           */
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
/// @file p9_io_xbus_linktrain.H
/// @brief I/O Link Training on the Xbus Links.
///
///-----------------------------------------------------------------------------
/// *HWP HWP Owner        : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP HWP Backup Owner : Gary Peterson <garyp@us.ibm.com>
/// *HWP FW Owner         : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team             : IO
/// *HWP Level            : 2
/// *HWP Consumed by      : FSP:HB
///-----------------------------------------------------------------------------
#ifndef _P9_IO_XBUS_TRAIN_H
#define _P9_IO_XBUS_TRAIN_H

//-----------------------------------------------------------------------------
//  System Header Include
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  fapi2 Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>

typedef fapi2::ReturnCode (*p9_io_xbus_linktrain_FP_t)
(const fapi2::Target < fapi2::TARGET_TYPE_XBUS >&,
 const fapi2::Target < fapi2::TARGET_TYPE_XBUS >&);

extern "C"
{

    /**
     * @brief A HWP that runs on every instance of the XBUS(EDI+)
     * @param[in] i_master Reference to the Master Target
     * @param[in] i_slave  Reference to the Slave Target
     * @retval ReturnCode
     */
    fapi2::ReturnCode
    p9_io_xbus_linktrain( const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_master,
                          const fapi2::Target < fapi2::TARGET_TYPE_XBUS >& i_slave );

} // extern "C"


#endif // _P9_IO_XBUS_TRAIN_H
