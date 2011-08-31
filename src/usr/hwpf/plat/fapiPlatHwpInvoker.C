//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/plat/fapiPlatHwpInvoker.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 *  @file fapiPlatHwpInvoker.C
 *
 *  @brief Implements the fapiRcToErrl function.
 */

#include <fapiTarget.H>
#include <fapiReturnCode.H>
#include <fapiPlatTrace.H>
#include <fapiErrorInfo.H>
#include <fapiPlatReasonCodes.H>
#include <fapiCollectFfdc.H>
#include <errl/errlentry.H>

namespace fapi
{

//******************************************************************************
// findErrInfoTarget. Finds a target identified by an error information record
// (for callout, garding or FFDC collection).
//******************************************************************************
Target findErrInfoTarget(const TargetType i_targetType,
                         const uint32_t i_targetPos,
                         const Target & i_errorTarget)
{
    Target l_target;

    // Note that the Error Target is the target of the failed HWP
    if (i_targetType == i_errorTarget.getType())
    {
         // The error info target type is the same as the Error Target.
         // Therefore the error info target IS the error target
         l_target = i_errorTarget;
    }
    else
    {
        // The error info target type is different from the Error Target. Figure
        // out the error info target from the target type and pos (relative to
        // the Error Target
        // TODO
        FAPI_ERR("findErrInfoTarget: Error Info Target determination TBD");
    }

    return l_target;
}

//******************************************************************************
// processErrInfoCallouts. Looks at the callout information in an error
// information record and adds callouts to the supplied error log
//******************************************************************************
void processErrInfoCallouts(ErrorInfoRecord & i_errInfoRecord,
                            const Target & i_errorTarget,
                            errlHndl_t o_pError)
{
    // Iterate through callouts, adding each callout to the error log
    for (ErrorInfoRecord::ErrorInfoCalloutItr_t l_itr =
             i_errInfoRecord.iv_callouts.begin();
         l_itr != i_errInfoRecord.iv_callouts.end(); ++l_itr)
    {
        // Find the Target to callout
        Target l_target = findErrInfoTarget((*l_itr).iv_targetType,
                                            (*l_itr).iv_targetPos,
                                            i_errorTarget);

        if (l_target.getType() == TARGET_TYPE_NONE)
        {
            FAPI_ERR("processErrInfoCallouts: Callout target not found");
        }
        else
        {
            // TODO Add callout to error log
            FAPI_ERR("processErrInfoCallouts: Adding callout TBD");
        }
    }
}

//******************************************************************************
// processErrInfoGards. Looks at the gard information in an error information
// record and gards targets
//******************************************************************************
void processErrInfoGards(ErrorInfoRecord & i_errInfoRecord,
                         const Target & i_errorTarget,
                         errlHndl_t o_pError)
{
    // Iterate through gard requests garding each target
    for (ErrorInfoRecord::ErrorInfoGardItr_t l_itr =
             i_errInfoRecord.iv_gards.begin();
         l_itr != i_errInfoRecord.iv_gards.end(); ++l_itr)
    {
        // Find the Target to gard
        Target l_target = findErrInfoTarget((*l_itr).iv_targetType,
                                            (*l_itr).iv_targetPos,
                                            i_errorTarget);

        if (l_target.getType() == TARGET_TYPE_NONE)
        {
            FAPI_ERR("processErrInfoGards: Gard target not found");
        }
        else
        {
            // TODO gard Target
            FAPI_ERR("processErrInfoGards: Garding TBD");
        }
    }
}

//******************************************************************************
// processErrInfoFfdcs. Looks at the FFDC information in an error information
// record, collects the FFDC and adds it to the supplied error log
//******************************************************************************
void processErrInfoFfdcs(ErrorInfoRecord & i_errInfoRecord,
                         const Target & i_errorTarget,
                         errlHndl_t o_pError)
{
    // Iterate through FFDC info, collecting and adding FFDC to the error log
    for(ErrorInfoRecord::ErrorInfoFfdcItr_t l_itr =
            i_errInfoRecord.iv_ffdcs.begin();
        l_itr != i_errInfoRecord.iv_ffdcs.end(); ++l_itr)
    {
        // Find the Target to collect FFDC from
        Target l_target = findErrInfoTarget((*l_itr).iv_targetType,
                                            (*l_itr).iv_targetPos,
                                            i_errorTarget);

        if (l_target.getType() == TARGET_TYPE_NONE)
        {
            FAPI_ERR("processErrInfoFfdcs: FFDC target not found");
        }
        else
        {
            // Collect FFDC. The token identifies the HWP to call to get FFDC
            FfdcHwpToken l_token = (*l_itr).iv_ffdcHwpToken;
            uint8_t * l_pFfdc = NULL;
            uint32_t l_size = 0;

            ReturnCode l_rc = fapiCollectFfdc(l_token, l_target, l_pFfdc,
                                              l_size);

            if (l_rc)
            {
                // Error collecting FFDC, just ignore
                FAPI_ERR("processErrInfoFfdcs: Error collecting FFDC. Token: %d",
                         l_token);
            }
            else
            {
                // Add FFDC to error log and delete
                // TODO Which comp id and section numbers should be used and how
                // will FFDC be parsed?
                FAPI_ERR("processErrInfoFfdcs: Adding %d bytes of FFDC to log. Token: %d",
                         l_size, l_token);
                o_pError->addFFDC(HWPF_COMP_ID, l_pFfdc, l_size);
                delete [] l_pFfdc;
                l_pFfdc = NULL;
            }

        }
    }
}

//******************************************************************************
// processErrInfo. Looks for an error information record associated with the
// specified HWP generated return code and processes it
//******************************************************************************
void processErrInfo(const ReturnCode & i_rc,
                    errlHndl_t o_pError)
{
    // Get the error info record from the Error Info Repository
    ErrorInfoRecord l_record;
    ErrorInfoRepository::Instance().find(i_rc, l_record);

    if (l_record.iv_rc != i_rc)
    {
        // Error Info Record not found. This should not happen
        FAPI_ERR("processErrInfo: No record found for 0x%x",
                 static_cast<uint32_t>(i_rc));
    }
    else
    {
        // Error Info Record found
        const char * l_pDescription = l_record.getDescription();

        if (l_pDescription)
        {
            FAPI_ERR("processErrInfo: Record found for 0x%x: %s",
                     static_cast<uint32_t>(i_rc), l_pDescription);
        }
        else
        {
            FAPI_ERR("processErrInfo: Record found for 0x%x: (no description)",
                     static_cast<uint32_t>(i_rc));
        }

        // Extract the Error Target (the Target of the failing HWP)
        Target * l_pErrTarget = i_rc.getErrTarget();

        if (l_pErrTarget == NULL)
        {
            FAPI_ERR("processErrInfo: Record contains no error target");
        }
        else
        {
            // Process the Error Info Record callout information
            processErrInfoCallouts(l_record, *l_pErrTarget, o_pError);

            // Process the Error Info Record gard information
            processErrInfoGards(l_record, *l_pErrTarget, o_pError);

            // Process the Error Info Record FFDC information
            processErrInfoFfdcs(l_record, *l_pErrTarget, o_pError);
        }
    }
}

//******************************************************************************
// fapiRcToErrl function. Converts a fapi::ReturnCode to an error log
//******************************************************************************
errlHndl_t fapiRcToErrl(ReturnCode & io_rc)
{
    errlHndl_t l_pError = NULL;

    if (io_rc)
    {
        // ReturnCode contains an error. Find out which component of the HWPF
        // created the error
        ReturnCode::returnCodeCreator l_creator = io_rc.getCreator();

        if (l_creator == ReturnCode::CREATOR_PLAT)
        {
            // PLAT error. Release the errlHndl_t
            FAPI_ERR("fapiRcToErrl: PLAT error: 0x%x",
                     static_cast<uint32_t>(io_rc));
            l_pError = reinterpret_cast<errlHndl_t> (io_rc.releasePlatData());
        }
        else if (l_creator == ReturnCode::CREATOR_HWP)
        {
            // HWP Error. Create an error log
            FAPI_ERR("fapiRcToErrl: HWP error: 0x%x",
                     static_cast<uint32_t>(io_rc));

            // TODO What should the severity be? Should it be in the error
            // record
            /*@
             * @errortype
             * @moduleid     MOD_RC_TO_ERRL
             * @reasoncode   RC_HWP_ERROR
             * @userdata1    Return Code Value
             * @devdesc      Error from HWP
             */
            l_pError = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               MOD_RC_TO_ERRL,
                                               RC_HWP_ERROR,
                                               static_cast<uint32_t>(io_rc));

            // Add any HWP FFDC stored in the ReturnCode to the error log
            uint32_t l_sz = 0;
            const void * l_pHwpFfdc = io_rc.getHwpFfdc(l_sz);

            if (l_sz)
            {
                // TODO Which comp id and section numbers should be used and how
                // will FFDC be parsed?
                FAPI_ERR("fapiRcToErrl: Adding %d bytes of HWP FFDC to errlog",
                         l_sz);
                l_pError->addFFDC(HWPF_COMP_ID, l_pHwpFfdc, l_sz);
            }

            // Process the error info record for this error
            processErrInfo(io_rc, l_pError);
        }
        else
        {
            // FAPI error. Create an error log
            FAPI_ERR("fapiRcToErrl: FAPI error: 0x%x",
                     static_cast<uint32_t>(io_rc));
            /*@
             * @errortype
             * @moduleid     MOD_RC_TO_ERRL
             * @reasoncode   RC_FAPI_ERROR
             * @userdata1    Return Code Value
             * @devdesc      FAPI Error
             */
            l_pError = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               MOD_RC_TO_ERRL,
                                               RC_FAPI_ERROR,
                                               static_cast<uint32_t>(io_rc));
        }

        // Set the ReturnCode to success, this will delete any HWP FFDC or PLAT
        // DATA associated with the ReturnCode
        io_rc = FAPI_RC_SUCCESS;
    }

    return l_pError;
}

} // End namespace
