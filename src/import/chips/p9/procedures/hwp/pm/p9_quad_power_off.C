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
/// @brief Power off the EQ -- including the functional cores associatated
///        with it.
///
//  *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
//  *HWP HWP Backup Owner: Greg Still <stillgs@us.ibm.com>
//  *HWP FW Owner:  Sangeetha T S <sangeet2@in.ibm.com>
//  *HWP Team: PM
//  *HWP Level: 1
//  *HWP Consumed by: FSP:HS
///
/// @verbatim
/// High-level procedure flow:
///     - for each good EC associated with the targeted EQ, power it off
///     - power off the EQ
/// @endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include <p9_quad_power_off.H>

// ----------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------

fapi2::ReturnCode
p9_quad_power_off(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_eq_target)
{
    FAPI_INF("> p9_quad_power_off...");


//fapi_try_exit:
    FAPI_INF("< p9_quad_power_off...");
    return fapi2::current_err;
}
