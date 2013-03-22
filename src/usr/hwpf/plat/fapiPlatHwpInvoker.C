/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatHwpInvoker.C $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file fapiPlatHwpInvoker.C
 *
 *  @brief Implements the fapiRcToErrl function.
 */

#include <fapiTarget.H>
#include <fapiReturnCode.H>
#include <fapiPlatTrace.H>
#include <fapiErrorInfo.H>
#include <hwpf/hwpf_reasoncodes.H>
#include <errl/errlentry.H>

namespace fapi
{

/**
 * @brief Translates a FAPI callout priority to an HWAS callout priority
 *
 * @param[i] i_fapiPri FAPI callout priority
 *
 * @return HWAS callout priority
 */
HWAS::callOutPriority xlateCalloutPriority(
    const fapi::CalloutPriorities::CalloutPriority i_fapiPri)
{
    // Use the CalloutPriority enum value as an index
    HWAS::callOutPriority l_priority = HWAS::SRCI_PRIORITY_HIGH;
    size_t l_index = i_fapiPri;

    const HWAS::callOutPriority HWAS_PRI[] = {HWAS::SRCI_PRIORITY_LOW,
                                              HWAS::SRCI_PRIORITY_MED,
                                              HWAS::SRCI_PRIORITY_HIGH};

    if (l_index < (sizeof(HWAS_PRI)/sizeof(HWAS::callOutPriority)))
    {
        l_priority = HWAS_PRI[i_fapiPri];
    }
    else
    {
        FAPI_ERR(
            "fapi::xlateCalloutPriority: Unknown priority 0x%x, assuming HIGH",
            i_fapiPri);
    }
  
    return l_priority;
}

/**
 * @brief Translates a FAPI procedure callout to an HWAS procedure callout
 *
 * @param[i] i_fapiProc FAPI procedure callout
 *
 * @return HWAS procedure callout
 */
HWAS::epubProcedureID xlateProcedureCallout(
    const fapi::ProcedureCallouts::ProcedureCallout i_fapiProc)
{
    // Use the ProcedureCallout enum value as an index
    HWAS::epubProcedureID l_proc = HWAS::EPUB_PRC_HB_CODE;
    size_t l_index = i_fapiProc;

    const HWAS::epubProcedureID HWAS_PROC[] = {
        HWAS::EPUB_PRC_HB_CODE,
        HWAS::EPUB_PRC_LVL_SUPP,
        HWAS::EPUB_PRC_MEMORY_PLUGGING_ERROR};

    if (l_index < (sizeof(HWAS_PROC)/sizeof(HWAS::epubProcedureID)))
    {
        l_proc = HWAS_PROC[i_fapiProc];
    }
    else
    {
        FAPI_ERR(
            "fapi::xlateProcedureCallout: Unknown proc 0x%x, assuming CODE",
            i_fapiProc);
    }
 
    return l_proc;
}

/**
 * @brief Processes any FFDC in the ReturnCode Error Information and adds them
 *        to the error log
 *
 * @param[i] i_errInfo  Reference to ReturnCode Error Information
 * @param[io] io_pError Errorlog  Handle
 */
void processEIFfdcs(const ErrorInfo & i_errInfo,
                    errlHndl_t io_pError)
{
    // Iterate through the FFDC sections, adding each to the error log
    uint32_t l_size = 0;

    for (ErrorInfo::ErrorInfoFfdcCItr_t l_itr = i_errInfo.iv_ffdcs.begin();
         l_itr != i_errInfo.iv_ffdcs.end(); ++l_itr)
    {
        const void * l_pFfdc = (*l_itr)->getData(l_size);
        uint32_t l_ffdcId = (*l_itr)->getFfdcId();

        // Add the FFDC ID as the first word, then the FFDC data
        ERRORLOG::ErrlUD * l_pUD = io_pError->addFFDC(
            HWPF_COMP_ID, &l_ffdcId, sizeof(l_ffdcId), 1, HWPF_UDT_HWP_FFDC);

        if (l_pUD)
        { 
            io_pError->appendToFFDC(l_pUD, l_pFfdc, l_size);
        }
    }
}

/**
 * @brief Processes any Procedure callouts requests in the ReturnCode Error
 *        Information and adds them to the error log
 *
 * @param[i] i_errInfo  Reference to ReturnCode Error Information
 * @param[io] io_pError Errorlog  Handle
 */
void processEIProcCallouts(const ErrorInfo & i_errInfo,
                           errlHndl_t io_pError)
{
    // Iterate through the procedure callout requests, adding each to the error
    // log
    for (ErrorInfo::ErrorInfoProcedureCalloutCItr_t l_itr =
             i_errInfo.iv_procedureCallouts.begin();
         l_itr != i_errInfo.iv_procedureCallouts.end(); ++l_itr)
    {
        HWAS::epubProcedureID l_procedure =
            xlateProcedureCallout((*l_itr)->iv_procedure);

        HWAS::callOutPriority l_priority =
            xlateCalloutPriority((*l_itr)->iv_calloutPriority);

        io_pError->addProcedureCallout(l_procedure, l_priority);
    }
}

/**
 * @brief Processes any Callout/Deconfigure/GARD requests in the ReturnCode Error
 *        Information and adds them to the error log
 *
 * @param[i] i_errInfo  Reference to ReturnCode Error Information
 * @param[io] io_pError Errorlog  Handle
 */
void processEICDGs(const ErrorInfo & i_errInfo,
                   errlHndl_t io_pError)
{
    // TODO: RTC issue 47147
    // Need to figure out how connections are called out. Assuming this is done
    // by calling out Target pairs, then the HWAS::SRCI_PRIORITY will need to
    // be a 'grouping' priority (MEDA/B/C)

    // Iterate through the CGD requests, adding each to the error log
    for (ErrorInfo::ErrorInfoCDGCItr_t l_itr = i_errInfo.iv_CDGs.begin();
         l_itr != i_errInfo.iv_CDGs.end(); ++l_itr)
    {
        TARGETING::Target * l_pTarget =
            reinterpret_cast<TARGETING::Target*>((*l_itr)->iv_target.get());

        HWAS::callOutPriority l_priority =
            xlateCalloutPriority((*l_itr)->iv_calloutPriority);

        HWAS::DeconfigEnum l_deconfig = HWAS::NO_DECONFIG;
        if ((*l_itr)->iv_deconfigure)
        {
            l_deconfig = HWAS::DELAYED_DECONFIG;
        }

        HWAS::GARD_ErrorType l_gard = HWAS::GARD_NULL;
        if ((*l_itr)->iv_gard)
        {
            l_gard = HWAS::GARD_Unrecoverable;
        }

        io_pError->addHwCallout(l_pTarget, l_priority, l_deconfig, l_gard);
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
            uint32_t l_rcValue = static_cast<uint32_t>(io_rc);
            FAPI_ERR("fapiRcToErrl: HWP error: 0x%x", l_rcValue);

            // TODO What should the severity be? Should it be in the error info?

            /*@
             * @errortype
             * @moduleid     MOD_HWP_RC_TO_ERRL
             * @reasoncode   RC_HWP_GENERATED_ERROR
             * @userdata1    RC value from HWP
             * @userdata2    <unused>
             * @devdesc      HW Procedure generated error. See User Data.
             */
            l_pError = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               MOD_HWP_RC_TO_ERRL,
                                               RC_HWP_GENERATED_ERROR,
                                               TO_UINT64(l_rcValue));

            // Add the rcValue as FFDC. This will explain what the error was
            l_pError->addFFDC(HWPF_COMP_ID, &l_rcValue, sizeof(l_rcValue), 1,
                              HWPF_UDT_HWP_RCVALUE);

            // Get the Error Information Pointer
            const ErrorInfo * l_pErrorInfo = io_rc.getErrorInfo();

            if (l_pErrorInfo)
            {
                // There is error information associated with the ReturnCode
                processEIFfdcs(*l_pErrorInfo, l_pError);
                processEIProcCallouts(*l_pErrorInfo, l_pError);
                processEICDGs(*l_pErrorInfo, l_pError);
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

            // The errlog reason code is the HWPF compID and the rcValue LSB
            uint32_t l_rcValue = static_cast<uint32_t>(io_rc);
            uint16_t l_reasonCode = l_rcValue;
            l_reasonCode &= 0xff;
            l_reasonCode |= HWPF_COMP_ID;

            // HostBoot errlog tags for FAPI errors are in hwpfReasonCodes.H
            l_pError = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               MOD_FAPI_RC_TO_ERRL,
                                               l_reasonCode);

            // FAPI may have added Error Information.
            // Get the Error Information Pointer
            const ErrorInfo * l_pErrorInfo = io_rc.getErrorInfo();

            if (l_pErrorInfo)
            {
                processEIFfdcs(*l_pErrorInfo, l_pError);
                processEIProcCallouts(*l_pErrorInfo, l_pError);
                processEICDGs(*l_pErrorInfo, l_pError);
            }
        }

        // Set the ReturnCode to success, this will delete any ErrorInfo or PLAT
        // DATA associated with the ReturnCode
        io_rc = FAPI_RC_SUCCESS;
    }

    return l_pError;
}

} // End namespace
