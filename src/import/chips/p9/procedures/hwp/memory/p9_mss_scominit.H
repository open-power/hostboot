/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_scominit.H $            */
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
/// @file p9_mss_scominit.C
/// @brief SCOM inits for PHY, MC
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Craig Hamilton <cchamilt@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef __P9_MSS_SCOMINIT__
#define __P9_MSS_SCOMINIT__

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9_mss_scominit_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>&);

extern "C"
{

///
/// @brief SCOM inits for PHY, MC
/// @param[in] i_target the MCBIST
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_scominit( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target );

}

#endif

