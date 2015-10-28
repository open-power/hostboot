/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_fab_iovalid.C $               */
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
/// @file p9_fab_iovalid.C
/// @brief Manage fabric link iovalid controls (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
/// @author Christy Graves <clgraves@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by: HB,FSP
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_fab_iovalid.H>


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


fapi2::ReturnCode
p9_fab_iovalid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
               const bool i_set_not_clear)
{
    FAPI_INF("Start");
    FAPI_INF("End");
    return fapi2::current_err;
}
