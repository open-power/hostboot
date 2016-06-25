/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/cache/p9_hcd_cache_stopclocks.H $     */
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
/// @file  p9_hcd_cache_stopclocks.H
/// @brief Quad Clock Stop
///

// *HWP HWP Owner          : David Du       <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still     <stillgs@us.ibm.com>
// *HWP FW Owner           : Sangeetha T S  <sangeet2@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : HB:PREV
// *HWP Level              : 2

#ifndef __P9_HCD_CACHE_STOPCLOCKS_H__
#define __P9_HCD_CACHE_STOPCLOCKS_H__

#include <fapi2.H>
#include <p9_hcd_common.H>

/// @typedef p9_hcd_cache_stopclocks_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_hcd_cache_stopclocks_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>&,
    const p9hcd::P9_HCD_CLK_CTRL_CONSTANTS,
    const p9hcd::P9_HCD_EX_CTRL_CONSTANTS);

extern "C"
{

/// @brief Quad Clock Stop
/// @param [in] i_target TARGET_TYPE_EQ target
/// @param [in] i_skip_regions select clk regions to skip on stopclocks
/// @param [in] i_skip_ex select ex, odd and/or even, to skip on stopclocks
/// @return FAPI2_RC_SUCCESS if success, else error code
    fapi2::ReturnCode
    p9_hcd_cache_stopclocks(
        const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
        const p9hcd::P9_HCD_CLK_CTRL_CONSTANTS      i_select_regions,
        const p9hcd::P9_HCD_EX_CTRL_CONSTANTS       i_select_ex);

}

#endif  // __P9_HCD_CACHE_STOPCLOCKS_H__
