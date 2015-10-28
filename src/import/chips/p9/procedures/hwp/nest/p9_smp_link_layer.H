/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_smp_link_layer.H $            */
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
/// @file p9_smp_link_layer.H
/// @brief Enable fabric link/transaction layers (FAPI2)
///
/// Enable fabric X/A data link (DL) and transaction (TL) layers
///
/// Procedure should enable use of link TL mailbox
///
/// @author Joe McGill <jmcgill@us.ibm.com>
/// @author Christy Graves <clgraves@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by: HB,FSP
//

#ifndef _P9_SMP_LINK_LAYER_H_
#define _P9_SMP_LINK_LAYER_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_smp_link_layer_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Enable fabric data link/transaction layers, for all logically enabled links on a single chip
///
/// @param[in] i_target Reference to processor chip target
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_smp_link_layer(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


} // extern "C"

#endif // _P9_SMP_LINK_LAYER_H_
