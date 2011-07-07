/**
 *  @file fapiPlatHwpInvoker.C
 *
 *  @brief Implements the platform specific HW Procedure invoker functions.
 */

#include <fapiPlatHwpInvoker.H>
#include <fapiReturnCode.H>
#include <fapiPlatTrace.H>
#include <fapiTestHwp.H>

namespace fapi
{

//******************************************************************************
// rcToErrl function
//******************************************************************************
errlHndl_t rcToErrl(ReturnCode i_rc)
{
    errlHndl_t l_err = NULL;

    ReturnCode::returnCodeCreator l_creator = i_rc.getCreator();

    if (l_creator == ReturnCode::CREATOR_PLAT)
    {
        // Release the errlHndl_t
        l_err = reinterpret_cast<errlHndl_t> (i_rc.releaseData());
    }
    else
    {
        //@todo Figure out how to convert FAPI/HWP error to Host Boot error log
    }

    return l_err;
}


//******************************************************************************
// invokeHwpIsP7EM0ChipletClockOn function
//******************************************************************************
errlHndl_t invokeHwpIsP7EM0ChipletClockOn(TARGETING::Target* i_target,
                                          bool & o_clocksOn)
{

    FAPI_DBG(ENTER_MRK "HostBootHwpIsP7EM0ChipletClockOn");

    errlHndl_t l_err = NULL;

     // Create a generic Target object
    Target l_target(TARGET_TYPE_PROC_CHIP, reinterpret_cast<void *> (i_target));

    //@todo
    // Double check to see if any locking is needed here.
    // Lower XSCOM already has a mutex lock.

    // Call the HWP executor macro
    ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, hwpIsP7EM0ChipletClockOn, l_target, o_clocksOn);

    if (l_rc != FAPI_RC_SUCCESS)
    {
        FAPI_ERR("hwpIsP7EM0ChipletClockOn: Error (0x%x) from "
                 "execHwpIsP7EM0ChipletClockOn",
                 static_cast<uint32_t> (l_rc));
        l_err = rcToErrl(l_rc);
    }
    else
    {
        if (o_clocksOn)
        {
           FAPI_INF("hwpIsP7EM0ChipletClockOn: Clocks are on");
        }
        else
        {
           FAPI_INF("hwpIsP7EM0ChipletClockOn: Clocks are off");
        }
    }

    FAPI_DBG(EXIT_MRK "HostBootHwpIsP7EM0ChipletClockOn");

    return l_err;
}

//******************************************************************************
// invokeHwpInitial function
//******************************************************************************
errlHndl_t invokeHwpInitialTest(TARGETING::Target* i_target)
{

    FAPI_DBG(ENTER_MRK "invokeHwpInitialTest");

    errlHndl_t l_err = NULL;

     // Create a generic Target object
    Target l_target(TARGET_TYPE_PROC_CHIP, reinterpret_cast<void *> (i_target));

    //@todo
    // Double check to see if any locking is needed here.
    // Lower XSCOM already has a mutex lock.

    // Call the HWP executor macro
    ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, hwpInitialTest, l_target);

    if (l_rc != FAPI_RC_SUCCESS)
    {
        FAPI_ERR("invokeHwpInitialTest: Error (0x%x) from "
                 "exechwpInitialTest",
                 static_cast<uint32_t> (l_rc));
        l_err = rcToErrl(l_rc);
    }
    else
    {
        FAPI_INF("Success in call to exechwpInitialTest");
    }

    FAPI_DBG(EXIT_MRK "invokeHwpInitialTest");

    return l_err;
}

} // End namespace
