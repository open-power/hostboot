/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_freq.C $                */
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
/// @file p9_mss_freq.C
/// @brief Calculate and save off DIMM frequencies
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Luke Mulkey <lwmulkey@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include "p9_mss_freq.H"

using fapi2::TARGET_TYPE_MCS;
using fapi2::FAPI2_RC_SUCCESS;

///
/// @brief Calculate and save off DIMM frequencies
/// @param[in] i_target the controller (e.g., MCS)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9_mss_freq( const fapi2::Target<TARGET_TYPE_MCS>& i_target )
{
    FAPI_INF("Start mss freq");
    FAPI_INF("End mss freq");
    return FAPI2_RC_SUCCESS;
}
