/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_scominit.C $            */
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
/// @file p9_io_xbus_scominit.C
/// @brief Invoke XBUS initfile
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
//   Invoke XBUS scominit file.
//
// Procedure Prereq:
//   - System clocks are running.
// @endverbatim
//----------------------------------------------------------------------------


//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <p9_io_gcr.H>
#include <p9_io_regs.H>
#include <p9_io_xbus_scominit.H>
#include <p9_xbus_g0_scom.H>
#include <p9_xbus_g1_scom.H>

enum
{
    ENUM_ATTR_XBUS_GROUP_0,
    ENUM_ATTR_XBUS_GROUP_1
};

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi2::ReturnCode p9_io_xbus_scominit(
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_target,
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_connected_target,
    const uint8_t i_group)
{
    // mark HWP entry
    FAPI_INF("p9_io_xbus_scominit: Entering ...");
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;

    // get system target
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_system_target;


    // assert IO reset to power-up bus endpoint logic
    // read-modify-write, set single reset bit (HW auto-clears)
    // on writeback
    {
        Register<EDIP_SCOM_MODE_PB> scom_mode_pb;
        FAPI_TRY(scom_mode_pb.read(i_target),
                 "Scom Read failed: scom_mode_pb.");
        scom_mode_pb.set<EDIP_IORESET_HARD_BUS0>(1);
        FAPI_TRY(scom_mode_pb.write(i_target),
                 "Scom Write failed: scom_mode_pb.");
    }

    switch(i_group)
    {
        case ENUM_ATTR_XBUS_GROUP_0:
            FAPI_INF("Group 0:Invoke FAPI procedure core: input_target");
            FAPI_EXEC_HWP(rc, p9_xbus_g0_scom, i_target, l_system_target);

            FAPI_INF("Group 0:Invoke FAPI procedure core: connected_target");
            FAPI_EXEC_HWP(rc, p9_xbus_g0_scom, i_connected_target, l_system_target);
            break;

        case ENUM_ATTR_XBUS_GROUP_1:
            FAPI_INF("Group 1:Invoke FAPI procedure core: input_target");
            FAPI_EXEC_HWP(rc, p9_xbus_g1_scom, i_target, l_system_target);

            FAPI_INF("Group 1:Invoke FAPI procedure core: connected_target");
            FAPI_EXEC_HWP(rc, p9_xbus_g1_scom, i_connected_target, l_system_target);
            break;
    }

    // mark HWP exit
    FAPI_INF("p9_io_xbus_scominit: ...Exiting");

fapi_try_exit:
    return fapi2::current_err;
}

