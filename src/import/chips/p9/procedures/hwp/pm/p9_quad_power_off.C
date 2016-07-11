/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_quad_power_off.C $              */
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
/// @file p9_quad_power_off.C
/// @brief Power off the EQ including the functional cores associatated with it.
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 2
// *HWP Consumed by     : OCC:CME:FSP
//----------------------------------------------------------------------------
//
// @verbatim
// High-level procedure flow:
//     - For each good EC associated with the targeted EQ, power it off.
//     - Power off the EQ.
// @endverbatim
//
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_quad_power_off.H>

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

// Procedure p9_quad_power_off entry point, comments in header
fapi2::ReturnCode p9_quad_power_off(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target)
{
    fapi2::ReturnCode rc   = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_unit_pos     = 0;

    FAPI_INF("p9_quad_power_off: Entering...");

    // Get chiplet position
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_unit_pos));
    FAPI_INF("Quad power off chiplet no.%d", l_unit_pos);

    // Call the procedure
//     p9_pm_pfet_control_eq(i_target,
//                           PM_PFET_TYPE_C::BOTH,
//                           PM_PFET_TYPE_C::OFF);


    FAPI_INF("p9_quad_power_off: ...Exiting");

fapi_try_exit:
    return fapi2::current_err;
}
