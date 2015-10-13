/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_xbus_scominit.C $            */
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
/// @file p9_io_xbus_scominit.C
/// @brief Invoke XBUS initfile
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Chris Steffen <cwsteffen@us.ibm.com>
// *HWP HWP Backup Owner:
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

enum
{
    ENUM_ATTR_PROC_X_ENABLE = 1
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
    const fapi2::Target<fapi2::TARGET_TYPE_XBUS>& i_connected_target)
{
    std::vector < fapi2::Target < fapi2::TARGET_TYPE_XBUS |
    fapi2::TARGET_TYPE_PERV >> l_targets;
    fapi2::Target<fapi2::TARGET_TYPE_PERV>               l_this_pu_target;
    fapi2::Target<fapi2::TARGET_TYPE_PERV>               l_connected_pu_target;

    fapi2::buffer<uint32_t> l_xbus_enable_attr;
    fapi2::buffer<uint64_t> l_data64;

    // mark HWP entry
    FAPI_INF("p9_io_xbus_scominit: Entering ...");

    // get parent chip targets
    l_this_pu_target = i_target.getParent<fapi2::TARGET_TYPE_PERV>();
    l_connected_pu_target =
        i_connected_target.getParent<fapi2::TARGET_TYPE_PERV>();

    // populate targets vector
    l_targets.push_back(i_target);             // chiplet target
    l_targets.push_back(l_this_pu_target);     // chip target
    l_targets.push_back(i_connected_target);   // connected chiplet target
    l_targets.push_back(l_connected_pu_target);// connected chip target

    // query XBUS partial good attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG,
                           l_this_pu_target,
                           l_xbus_enable_attr));

    FAPI_ASSERT(l_xbus_enable_attr.getBit<8>() != ENUM_ATTR_PROC_X_ENABLE,
                fapi2::P9_XBUS_SCOMINIT_PARTIAL_GOOD_ERR()
                .set_TARGET(l_this_pu_target),
                "ERROR: Partial good attribute error");

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

    //TODO:Initfile work in progress. yet to be available
    FAPI_INF("Invoke FAPI procedure core");
#if 0
    fapi2::Target<fapi2::TARGET_TYPE_XBUS> fapi_target(&l_targets);
    FAPI_EXEC_HWP(rc_fapi, p9_xbus_scom, fapi_target);
#endif

    // mark HWP exit
    FAPI_INF("p9_io_xbus_scominit: ...Exiting");

fapi_try_exit:
    return fapi2::current_err;
}

