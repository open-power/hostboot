/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_volt.H $                */
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
/// @file p9_mss_volt.H
/// @brief Calculate and save off rail voltages
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre A. Marin <aamarin@us.ibm.com>
// *HWP FW  Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef MSS_VOLT_H_
#define MSS_VOLT_H_

#include <fapi2.H>
#include <vector>
#include <lib/spd/spd_decoder.H>
#include <lib/eff_config/attr_setters.H>

typedef fapi2::ReturnCode (*p9_mss_volt_FP_t) (const std::vector <fapi2::Target<fapi2::TARGET_TYPE_MCS>>&);

extern "C"
{

    ///
    /// @brief Calculate and save off rail voltages
    /// @param[in] i_target the controller (e.g., MCS)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_volt( const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCS>>& i_targets );

}

#endif
