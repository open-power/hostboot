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
#include <errl/errlentry.H>

namespace fapi
{

//******************************************************************************
// processEIFfdcs.
// Processes any FFDC in the ReturnCode Error Information
//******************************************************************************
void processEIFfdcs(const ErrorInfo & i_errInfo,
                    errlHndl_t io_pError)
{
    // Iterate through the FFDCs, adding each to the error log
    // TODO Should all of the FFDC sections be added as a single blob? There is
    // overhead to adding lots of different sections.
    uint32_t l_size;
    const void * l_pFfdc;

    for (ErrorInfo::ErrorInfoFfdcCItr_t l_itr = i_errInfo.iv_ffdcs.begin();
         l_itr != i_errInfo.iv_ffdcs.end(); ++l_itr)
    {
        l_pFfdc = (*l_itr)->getData(l_size);

        FAPI_ERR("processEIFfdcs: Adding %d bytes of FFDC to errlog",
                 l_size);

        // TODO Which comp id and section numbers should be used and how will
        // FFDC be parsed?
        io_pError->addFFDC(HWPF_COMP_ID, l_pFfdc, l_size);
    }
}

//******************************************************************************
// processEICallouts
// Processes any Callout requests in the ReturnCode Error Information
//******************************************************************************
void processEICallouts(const ErrorInfo & i_errInfo,
                          errlHndl_t io_pError)
{
    // Iterate through the callout requestss, adding each  to the error log
    for (ErrorInfo::ErrorInfoCalloutCItr_t l_itr =
             i_errInfo.iv_callouts.begin();
         l_itr != i_errInfo.iv_callouts.end(); ++l_itr)
    {
        // TODO Add callout to error log
        FAPI_ERR("processEICallouts: Adding target callout to errlog (TODO). Type: 0x%x. Pri: 0x%x",
                 (*l_itr)->iv_target.getType(), (*l_itr)->iv_priority);
    }
}

//******************************************************************************
// processEIDeconfigs
// Processes any Deconfig requests in the ReturnCode Error Information
//******************************************************************************
void processEIDeconfigs(const ErrorInfo & i_errInfo,
                           errlHndl_t io_pError)
{
    // Iterate through the deconfigure requests, deconfiguring each target
    for (ErrorInfo::ErrorInfoDeconfigCItr_t l_itr =
             i_errInfo.iv_deconfigs.begin();
         l_itr != i_errInfo.iv_deconfigs.end(); ++l_itr)
    {
        // TODO Deconfigure target
        FAPI_ERR("processEIDeconfigs: Deconfiguring target (TODO). Type: 0x%x",
                 (*l_itr)->iv_target.getType());
    }
}


//******************************************************************************
// processEiGards
// Processes any Gard requests in the ReturnCode Error Information
//******************************************************************************
void processEiGards(const ErrorInfo & i_errInfo,
                       errlHndl_t io_pError)
{
    // Iterate through gard requests, creating a GARD record for each target
    for (ErrorInfo::ErrorInfoGardCItr_t l_itr = i_errInfo.iv_gards.begin();
         l_itr != i_errInfo.iv_gards.end(); ++l_itr)
    {
        // TODO Create GARD record for target
        FAPI_ERR("processEIGards: Garding target (TODO). Type: 0x%x",
                 (*l_itr)->iv_target.getType());
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

            // Get the Error Information Pointer
            const ErrorInfo * l_pErrorInfo = NULL;

            l_pErrorInfo = io_rc.getErrorInfo();

            if (l_pErrorInfo)
            {
                // There is error information associated with the ReturnCode
                processEIFfdcs(*l_pErrorInfo, l_pError);
                processEICallouts(*l_pErrorInfo, l_pError);
                processEIDeconfigs(*l_pErrorInfo, l_pError);
                processEiGards(*l_pErrorInfo, l_pError);
            }
            else
            {
                FAPI_ERR("fapiRcToErrl: No Error Information");
            }
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

        // Set the ReturnCode to success, this will delete any ErrorInfo or PLAT
        // DATA associated with the ReturnCode
        io_rc = FAPI_RC_SUCCESS;
    }

    return l_pError;
}

} // End namespace
