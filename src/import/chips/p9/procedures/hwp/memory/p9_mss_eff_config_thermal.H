/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/centaur/procedures/ipl/hwp/p9_mss_eff_config_thermal.H $ */
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
/// @file p9_mss_eff_config_thermal.H
/// @brief Perform thermal calculations as part of the effective configuration
///
// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef __P9_MSS_EFF_CONFIG_THERMAL__
#define __P9_MSS_EFF_CONFIG_THERMAL__

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9_mss_eff_config_thermal_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MCS>&);

extern "C"
{

///
/// @brief Perform thermal calculations as part of the effective configuration
/// @param[in] i_target, the controller (e.g., MCS)
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_eff_config_thermal( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target );

}

#endif

