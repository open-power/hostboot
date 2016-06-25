/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/core/p9_hcd_core_stopclocks.H $       */
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
/// @file  p9_hcd_core_stopclocks.H
/// @brief Core Clock Stop
///

// *HWP HWP Owner          : David Du       <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still     <stillgs@us.ibm.com>
// *HWP FW Owner           : Sangeetha T S  <sangeet2@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : HB:PREV
// *HWP Level              : 2

#ifndef __P9_HCD_CORE_STOPCLOCKS_H__
#define __P9_HCD_CORE_STOPCLOCKS_H__

#include <fapi2.H>

/// @typedef p9_hcd_core_stopclocks_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_hcd_core_stopclocks_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>&);

extern "C"
{

/// @brief Quad Clock Stop
/// @param [in] i_target TARGET_TYPE_EX target
/// @return FAPI2_RC_SUCCESS if success, else error code
    fapi2::ReturnCode
    p9_hcd_core_stopclocks(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target);

}

#endif  // __P9_HCD_CORE_STOPCLOCKS_H__
