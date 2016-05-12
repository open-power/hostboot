/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_scomoverride_chiplets.C $     */
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
/// @file p9_scomoverride_chiplets.C
///
/// @brief Apply sequenced scom overrides
///

//
// *HWP HW Owner : Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner : Thi N. Tran <thi@us.ibm.com>
// *HWP Team : Nest
// *HWP Level : 2
// *HWP Consumed by : HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p9_scomoverride_chiplets.H"

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p9_scomoverride_chiplets(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering ...");

    FAPI_DBG("Exiting ...");

    return fapi2::current_err;
}

