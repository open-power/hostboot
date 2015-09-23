/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_exit_cache_contained.C $       */
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
/// @file p9_exit_cache_contained.C
/// @brief  Placeholder for overrides needed to step the core from cache-contained execution to expand to memory
///
// *HWP HWP Owner: Michael Dye <dyem@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by: HB


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_exit_cache_contained.H>

extern "C"
{
///
/// p9_exit_cache_contained HWP entry point (Defined in .H file)
///
    fapi2::ReturnCode p9_exit_cache_contained(const
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            & i_target)
    {
        fapi2::ReturnCode rc;

        //Mark Entry
        FAPI_INF("Entering ...");

        //Mark Exit
        FAPI_INF("Exiting ...");

        return rc;
    }
} // extern "C"
/* End: */
