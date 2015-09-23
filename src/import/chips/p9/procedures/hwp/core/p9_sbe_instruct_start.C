/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_sbe_instruct_start.C $         */
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
/// @file p9_sbe_instruct_start.C
/// @brief
///    Starts instructions on 1 core, thread 0.
///    Thread 0 will be started at CIA scan flush value of 0.
//
// *HWP HWP Owner: Michael Dye <dyem@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_sbe_instruct_start.H>

extern "C"
{

///
/// p9_sbe_instruct_start HWP entry point (Defined in .H file)
///
    fapi2::ReturnCode p9_sbe_instruct_start(const fapi2::Target<fapi2::TARGET_TYPE_CORE>
                                            & i_target)
    {
        //Mark Entry
        FAPI_INF("Entering ...");

        FAPI_INF("Starting thread 0 with bitset 1000 at address 0x0...");
        FAPI_TRY(p9_thread_control(i_target, 8, PTC_CMD_START, false),
                 "Failed when calling p9_thread_control thread 0 start");
        //Mark Exit
        FAPI_INF("Exiting ...");

    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern "C"
/* End: */
