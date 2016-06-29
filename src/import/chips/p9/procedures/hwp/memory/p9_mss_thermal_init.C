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
/// @brief configure and start the OCC and thermal cache
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/mc/mc.H>
#include <lib/utils/find.H>
#include <p9_mss_thermal_init.H>

using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
extern "C"
{

///
/// @brief configure and start the OCC and thermal cache
/// @param[in] i_target the controller target
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_thermal_init( const fapi2::Target<TARGET_TYPE_MCS>& i_target )
    {
        FAPI_INF("Start thermal_init");

        for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
        {
            FAPI_TRY(mss::mc::thermal_throttle_scominit(p));
        }

        FAPI_TRY (mss::mc::disable_emergency_throttle(i_target));
        FAPI_INF("End thermal_init");
    fapi_try_exit:
        return fapi2::current_err;
    }
} //extern C
