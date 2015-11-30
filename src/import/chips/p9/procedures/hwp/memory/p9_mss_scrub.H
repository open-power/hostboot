/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/centaur/procedures/ipl/hwp/p9_mss_scrub.H $       */
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
/// @file p9_mss_scrub.H
/// @brief Begin background scrub
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Luke Mulkey <lwmulkey@us.ibm.com>
// *HWP FW Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef __P9_MSS_SCRUB__
#define __P9_MSS_SCRUB__

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9_mss_scrub_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>&);

extern "C"
{

    ///
    /// @brief Begin background scrub
    /// @param[in] i_target, MCBIST
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_scrub( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

}

#endif
