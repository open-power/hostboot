/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_thermal_init.C $        */
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
/// @file p9_mss_thermal_init.C
/// @brief Initialize thermal sensors
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mss_thermal_init.H>

using fapi2::TARGET_TYPE_MCBIST;

extern "C"
{
///
/// @brief Initialize thermal sensors
/// @param[in] i_target, the McBIST of the ports of the dram you're training
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_thermal_init( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
    {
        FAPI_INF("Start thermal_init");
        FAPI_INF("End thermal_init");
        return fapi2::FAPI2_RC_SUCCESS;
    }
}
