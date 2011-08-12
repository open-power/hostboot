/**
 *  @file fapiPlatHwpInvoker.C
 *
 *  @brief Implements the platform specific HW Procedure invoker functions.
 */

#include <fapiPlatHwpInvoker.H>
#include <fapiHwpExecutor.H>
#include <fapiReturnCode.H>
#include <fapiPlatTrace.H>
#include <fapiErrorInfo.H>
#include <fapiPlatReasonCodes.H>
#include <fapiCollectFfdc.H>
#include <errl/errlentry.H>

namespace fapi
{

//******************************************************************************
// rcToErrl function. Converts an error fapi::ReturnCode into a errlHndl_t
//******************************************************************************
errlHndl_t rcToErrl(ReturnCode i_rc)
{
    errlHndl_t l_err = NULL;

    // Find out which component of the HWPF created the error
    ReturnCode::returnCodeCreator l_creator = i_rc.getCreator();

    if (l_creator == ReturnCode::CREATOR_PLAT)
    {
        // PLAT error. Release the errlHndl_t
        FAPI_ERR("rcToErrl: 0x%x is PLAT error", static_cast<uint32_t>(i_rc));
        l_err = reinterpret_cast<errlHndl_t> (i_rc.releasePlatData());
    }
    else if (l_creator == ReturnCode::CREATOR_HWP)
    {
        // HWP Error. Create an error log
        // TODO What should the severity be? Should it be in the error record
        /*@
         * @errortype
         * @moduleid     MOD_RC_TO_ERRL
         * @reasoncode   RC_HWP_ERROR
         * @userdata1    Return Code Value
         * @devdesc      Error from HWP
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        MOD_RC_TO_ERRL,
                                        RC_HWP_ERROR,
                                        static_cast<uint32_t>(i_rc));

        // Add any HWP FFDC stored in the ReturnCode to the error log
        uint32_t l_sz = 0;
        const void * l_pHwpFfdc = i_rc.getHwpFfdc(l_sz);

        if (l_sz)
        {
            // TODO Which comp id and section numbers should be used and how
            // will FFDC be parsed?
            FAPI_ERR("rcToErrl: Adding %d bytes of HWP FFDC to log", l_sz);
            l_err->addFFDC(HWPF_COMP_ID, l_pHwpFfdc, l_sz);
        }

        // Get the error info record from the Error Info Repository
        ErrorInfoRecord l_record;
        ErrorInfoRepository::Instance().find(i_rc, l_record);

        if (l_record.iv_rc == i_rc)
        {
            // Error Info Record found
            const char * l_pDescription = l_record.getDescription();

            if (l_pDescription)
            {
                FAPI_ERR("rcToErrl: HWP error record found for 0x%x: %s",
                         static_cast<uint32_t>(i_rc), l_pDescription);
            }
            else
            {
                FAPI_ERR("rcToErrl: HWP error record found for 0x%x: no "
                         "description", static_cast<uint32_t>(i_rc));
            }

            // Extract the Error Target (the Target of the failing HWP)
            Target * l_pErrTarget = i_rc.getErrTarget();

            if (l_pErrTarget == NULL)
            {
                FAPI_ERR("rcToErrl: HWP error record contains no error target");
            }
            else
            {
                // TODO Iterate through callouts, adding each callout to the
                // error log

                // Iterate through FFDC sections, collecting and adding FFDC to
                // the error log
                for(ErrorInfoRecord::ErrorInfoFfdcItr_t l_itr =
                        l_record.iv_ffdcs.begin();
                    l_itr != l_record.iv_ffdcs.end(); ++l_itr)
                {
                    // Get the FFDC HWP Token, this identifies the FFDC HWP to
                    // call to get FFDC
                    FfdcHwpToken l_token = (*l_itr).iv_ffdcHwpToken;

                    // Figure out which target to collect FFDC from
                    Target * l_pFfdcTarget = NULL;

                    if ((*l_itr).iv_targetType == l_pErrTarget->getType())
                    {
                        // The target type to collect FFDC from is the same as
                        // the Error Target. Collect FFDC from the error target
                        l_pFfdcTarget = l_pErrTarget;
                    }
                    else
                    {
                        // The target type to collect FFDC from is different
                        // from the Error Target. Figure out the target to
                        // collect FFDC from using the record's iv_targetPos 
                        // (relative to the Error Target)
                        // TODO
                        FAPI_ERR("rcToErrl: Collection of FFDC from non Error "
                                 "Target TBD");
                    }

                    if (l_pFfdcTarget)
                    {
                        // Collect FFDC
                        uint8_t * l_pFfdc = NULL;
                        uint32_t l_size = 0;

                        ReturnCode l_rc = fapiCollectFfdc(l_token,
                                                          *l_pFfdcTarget,
                                                          l_pFfdc, l_size);

                        if (l_rc)
                        {
                            // Error collecting FFDC, just ignore
                            FAPI_ERR("rcToErrl: Error collecting FFDC. "
                                     "Token: %d", l_token);
                        }
                        else
                        {
                            // Add FFDC to error log and delete
                            // TODO Which comp id and section numbers should be
                            // used and how will FFDC be parsed?
                            FAPI_ERR("rcToErrl: Adding %d bytes of FFDC to "
                                     "log. Token: %d", l_size, l_token);
                            l_err->addFFDC(HWPF_COMP_ID, l_pFfdc, l_size);
                            delete [] l_pFfdc;
                            l_pFfdc = NULL;
                        }
                    }
                }
            }
        }
        else
        {
            // Error Info Record not found. Should not happen
            FAPI_ERR("rcToErrl: HWP error record not found for 0x%x",
                     static_cast<uint32_t>(i_rc));
        }
    }
    else
    {
        // FAPI error.
        FAPI_ERR("rcToErrl: 0x%x is FAPI error", static_cast<uint32_t>(i_rc));
        /*@
         * @errortype
         * @moduleid     MOD_RC_TO_ERRL
         * @reasoncode   RC_FAPI_ERROR
         * @userdata1    Return Code Value
         * @devdesc      FAPI Error
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        MOD_RC_TO_ERRL,
                                        RC_FAPI_ERROR,
                                        static_cast<uint32_t>(i_rc));
    }

    return l_err;
}

//******************************************************************************
// invokeHwpInitialTest function
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

//******************************************************************************
// invokeHwpTestError function
//******************************************************************************
errlHndl_t invokeHwpTestError(TARGETING::Target* i_target)
{
    FAPI_DBG(ENTER_MRK "invokeHwpTestError");

    errlHndl_t l_err = NULL;

    // Create a generic Target object
    Target l_target(TARGET_TYPE_PROC_CHIP, reinterpret_cast<void *> (i_target));

    // Call the HWP executor macro
    ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, hwpTestError, l_target);

    if (l_rc != FAPI_RC_SUCCESS)
    {
        FAPI_INF("invokeHwpTestError: Expected error (0x%x) from HWP",
                 static_cast<uint32_t> (l_rc));
        l_err = rcToErrl(l_rc);
    }
    else
    {
        FAPI_ERR("Success from HWP");
    }

    FAPI_DBG(EXIT_MRK "invokeHwpTestError");

    return l_err;
}

} // End namespace
