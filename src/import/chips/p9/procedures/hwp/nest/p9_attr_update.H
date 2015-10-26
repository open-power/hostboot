/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_attr_update.H $               */
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
/// @file p9_attr_update.H
///
/// @brief Stub HWP for FW to override attributes programmatically
///

//
// *HWP HW Owner : Michael Dye <dyem@us.ibm.com>
// *HWP FW Owner : Thi N. Tran <thi@us.ibm.com>
// *HWP Team : Nest
// *HWP Level : 1
// *HWP Consumed by : HB
//


#ifndef _P9_ATTR_UPDATE_H_
#define _P9_ATTR_UPDATE_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

typedef fapi2::ReturnCode (*p9_attr_update_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

/// @brief  Placeholder for attribute overrides
///
/// @param[in] i_target Reference to processor chip target
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p9_attr_update(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif // _P9_ATTR_UPDATE_H_
