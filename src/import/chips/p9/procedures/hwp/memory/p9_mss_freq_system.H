/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_freq_system.H $         */
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
/// @file p9_mss_freq_system.H
/// @brief Sets synchronous mode
///
// *HWP HWP Owner: Andre A. Marin <aamarin@us.ibm.com>
// *HWP FW  Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef FREQ_SYSTEM_H_
#define FREQ_SYSTEM_H_

#include <fapi2.H>
#include <vector>

typedef fapi2::ReturnCode (*p9_mss_freq_system_FP_t) (const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCBIST> >&);

extern "C"
{

    ///
    /// @brief Set synchronous mode
    /// @param[in] i_target the controller (e.g., MCS)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_freq_system( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCBIST> >& i_targets);

}

#endif
