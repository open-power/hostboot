/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_npu_scominit.C $              */
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
/// @file p9_npu_scominit.C
/// @brief Apply SCOM overrides for the NPU unit via an init file
///
// *HWP HWP Owner: Michael Dye <dyem@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by: HB

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_npu_scominit.H>

extern "C"
{

///
/// p9_npu_scominit HWP entry point (Defined in .H file)
///
    fapi2::ReturnCode p9_npu_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                                      & i_target)
    {
        //Mark Entry
        FAPI_DBG("Entering ...");
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        // uint8_t l_capi_mode;
        // uint8_t l_opt_mode [4];
        //basically what we need to know is which of the 6 possible NPU bricks are connected to GPUs in the system.
        //From that information we know which of the 3 NPU Powerbus ramps to activate.

        //Level of NPU involvement is determined from the below 4 pieces of information
        FAPI_DBG("Collecting system information to determine npu state");
        //Powerbus Epsilon setting
        //FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CAPI_MODE, FAPI_SYSTEM, l_capi_mode));
        //Gives information on link type for powerbus snooping setup
        //FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_OPT_MODE, FAPI_SYSTEM, l_opt_mode));
        //Attribute for GPUs in System
        //"Link Enable" reflected in targeting mode

        //NPU snoop configuration using above information
        //scom FIR initialization in initfile

        //Mark Exit
        FAPI_DBG("Exiting ...");

        //fapi_try_exit:
        return fapi2::current_err;
    }

} // extern "C"
/* End: */
