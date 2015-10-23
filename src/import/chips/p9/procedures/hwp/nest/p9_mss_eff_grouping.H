/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_mss_eff_grouping.H $          */
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
/// ----------------------------------------------------------------------------
/// @file  p9_mss_eff_grouping.H
///
/// @brief Perform Memory Controller grouping on each processor chip
///
/// The purpose of this procedure is to effectively group the memory on each
/// processor chip based on available memory behind its memory grouping ports.
/// Some placement policy/scheme and other info that are stored in the
/// attributes are used as part of the grouping process.
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 1
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------

#ifndef _P9_MSS_EFF_GROUPING_H_
#define _P9_MSS_EFF_GROUPING_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

/// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_mss_eff_grouping_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
///
/// @brief p9_mss_eff_grouping procedure
///
/// This HWP is to group the MCs of the input target processor chip based
/// on the amount of memory behind its ports and some policy attribute settings.
///
/// @param[in]    i_target   Reference to TARGET_TYPE_PROC_CHIP target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
extern "C"
{

    fapi2::ReturnCode p9_mss_eff_grouping(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif  // _P9_MSS_EFF_GROUPING_H_
