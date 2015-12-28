/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_eff_config.H $          */
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
/// @file p9_mss_eff_config.H
/// @brief Command and Control for the memory subsystem - populate attributes
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef __P9_MSS_EFF_CONFIG__
#define __P9_MSS_EFF_CONFIG__

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9_mss_eff_config_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MCS>&);

extern "C"
{

///
/// @brief Configure the attributes for each controller
/// @param[in] i_target, the controller (e.g., MCS)
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_eff_config( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target );

}

#endif
