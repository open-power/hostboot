/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_obus_scominit.C $            */
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
/// @file p9_io_obus_scominit.C
/// @brief Invoke OBUS initfile
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Chris Steffen <cwsteffen@us.ibm.com>
// *HWP HWP Backup Owner: Gary Peterson <garyp@us.ibm.com>
// *HWP FW Owner        : Sumit Kumar <sumit_kumar@in.ibm.com>
// *HWP Team            : IO
// *HWP Level           : 2
// *HWP Consumed by     : FSP:HB
//----------------------------------------------------------------------------
//
// @verbatim
// High-level procedure flow:
//
//   Invoke OBUS scominit file.
//
// Procedure Prereq:
//   - System clocks are running.
// @endverbatim
//----------------------------------------------------------------------------


//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <p9_io_scom.H>
#include <p9_io_regs.H>
#include <p9_io_obus_scominit.H>


//------------------------------------------------------------------------------
//  Constant definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi2::ReturnCode p9_io_obus_scominit(
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_target,
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_connected_target)
{
    // mark HWP entry
    FAPI_INF("p9_io_obus_scominit: Entering...");
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;

    // get system target
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_system_target;

    // assert IO reset to power-up bus endpoint logic
    // read-modify-write, set single reset bit (HW auto-clears)
    // on writeback
    FAPI_TRY(io::rmw(OPT_IORESET_HARD_BUS0, i_target, 0, 0, 1));

    FAPI_INF("Invoke FAPI procedure core: input_target");
//TODO:
#if 0
    FAPI_EXEC_HWP(rc, p9_obus_scom, i_target, l_system_target);
#endif

    FAPI_INF("Invoke FAPI procedure core: connected_target");
//TODO:
#if 0
    FAPI_EXEC_HWP(rc, p9_obus_scom, i_connected_target, l_system_target);
#endif

    // mark HWP exit
    FAPI_INF("p9_io_obus_scominit: ...Exiting");

fapi_try_exit:
    return fapi2::current_err;
}

