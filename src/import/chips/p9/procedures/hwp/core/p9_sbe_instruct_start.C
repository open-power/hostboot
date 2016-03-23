/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/core/p9_sbe_instruct_start.C $        */
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
/// @file p9_sbe_instruct_start.C
/// @brief
///    Starts instructions on 1 core, thread 0.
///    Thread 0 will be started at CIA scan flush value of 0.
//
// *HWP HWP Owner: Nick Klazynski <jklazyns@us.ibm.com>
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
    fapi2::ReturnCode p9_sbe_instruct_start(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
    {
        fapi2::buffer<uint64_t> l_rasStatusReg(0);
        uint64_t l_state = 0;
        FAPI_DBG("Entering ...");

        FAPI_INF("Starting instruction on thread 0");
        FAPI_TRY(p9_thread_control(i_target, 0b1000, PTC_CMD_START, false,
                                   l_rasStatusReg, l_state),
                 "p9_sbe_instruct_start: p9_thread_control() returns an error");

    fapi_try_exit:
        FAPI_DBG("Exiting ...");
        return fapi2::current_err;
    }

} // extern "C"
/* End: */
