/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/fapi/fapiReturnCode.C $                          */
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
 *  @file fapiReturnCode.C
 *
 *  @brief Implements the ReturnCode class.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/13/2011  Created.
 *                          mjjones     07/05/2011. Removed const from data
 *                          mjjones     07/25/2011  Added support for FFDC and
 *                                                  Error Target
 *                          camvanng    09/06/2011  Clear Plat Data, Hwp FFDC data,
 *                                                  and Error Target if
 *                                                  FAPI_RC_SUCCESS is assigned to
 *                                                  ReturnCode
 *                          mjjones     09/22/2011  Added ErrorInfo Support
 *                          mjjones     01/12/2012  Enforce correct usage
 *                          mjjones     02/22/2012  Allow user to add Target FFDC
 *                          mjjones     03/16/2012  Add type to FFDC data
 *                          mjjones     03/16/2012  Allow different PLAT errors
 *                          mjjones     05/02/2012  Only trace setEcmdError on err
 *                          mjjones     07/11/2012  Remove a trace
 *                          brianh      07/31/2012  performance/size optimizations
 *                          mjjones     08/14/2012  Use new ErrorInfo structure
 *                          mjjones     09/19/2012  Add FFDC ID to error info
 *                          mjjones     03/22/2013  Support Procedure Callouts
 */

#include <fapiReturnCode.H>
#include <fapiReturnCodeDataRef.H>
#include <fapiPlatTrace.H>
#include <fapiTarget.H>

namespace fapi
{

//******************************************************************************
// Constructor
//******************************************************************************
ReturnCode::ReturnCode(const ReturnCodes i_rcValue) :
    iv_rcValue(i_rcValue), iv_pDataRef(NULL)
{
    if (i_rcValue != FAPI_RC_SUCCESS)
    {
        FAPI_ERR("ctor: Creating error 0x%x", i_rcValue);
    }
}

//******************************************************************************
// Copy Constructor
//******************************************************************************
ReturnCode::ReturnCode(const ReturnCode & i_right) :
    iv_rcValue(i_right.iv_rcValue), iv_pDataRef(i_right.iv_pDataRef)
{
    // Note shallow copy of data ref pointer. Both ReturnCodes now point to any
    // associated data. If there is data, increment the data ref count
    if (iv_pDataRef)
    {
        iv_pDataRef->incRefCount();
    }
}

//******************************************************************************
// Destructor
//******************************************************************************
ReturnCode::~ReturnCode()
{
    // Forget about any associated data
    forgetData();
}

//******************************************************************************
// Assignment Operator
//******************************************************************************
ReturnCode & ReturnCode::operator=(const ReturnCode & i_right)
{
    // Test for self assignment
    if (this != &i_right)
    {
        // Forget about any associated data
        forgetData();

        // Note shallow copy of data ref pointer. Both ReturnCodes now point to
        // any associated data. If there is data, increment the data ref count
        iv_rcValue = i_right.iv_rcValue;
        iv_pDataRef = i_right.iv_pDataRef;

        if (iv_pDataRef)
        {
            iv_pDataRef->incRefCount();
        }
    }

    return *this;
}

//******************************************************************************
// Assignment Operator
//******************************************************************************
ReturnCode & ReturnCode::operator=(const uint32_t i_rcValue)
{
    iv_rcValue = i_rcValue;

    // Forget about any associated data
    forgetData();

    return *this;
}

//******************************************************************************
// setFapiError function
//******************************************************************************
void ReturnCode::setFapiError(const ReturnCodes i_rcValue)
{
    FAPI_ERR("setFapiError: Creating FAPI error 0x%x", i_rcValue);
    iv_rcValue = i_rcValue;

    // Forget about any associated data (this is a new error)
    forgetData();
}

//******************************************************************************
// setEcmdError function
//******************************************************************************
void ReturnCode::setEcmdError(const uint32_t i_rcValue)
{
    // Some HWPs perform an ecmdDataBaseBufferBase operation, then call this
    // function then check if the ReturnCode indicates an error. Therefore only
    // trace an error if there actually is an error
    if (i_rcValue != 0)
    {
        FAPI_ERR("setEcmdError: Creating ECMD error 0x%x", i_rcValue);
    }
    iv_rcValue = i_rcValue;

    // Forget about any associated data (this is a new error)
    forgetData();
}

//******************************************************************************
// setPlatError function
//******************************************************************************
void ReturnCode::setPlatError(void * i_pData,
                              const ReturnCodes i_rcValue)
{
    FAPI_ERR("setPlatError: Creating PLAT error 0x%x", i_rcValue);
    iv_rcValue = i_rcValue;

    // Forget about any associated data (this is a new error)
    forgetData();

    if (i_pData)
    {
        getCreateReturnCodeDataRef().setPlatData(i_pData);
    }
}

//******************************************************************************
// _setHwpError function
//******************************************************************************
void ReturnCode::_setHwpError(const HwpReturnCode i_rcValue)
{
    FAPI_ERR("_setHwpError: Creating HWP error 0x%x", i_rcValue);
    iv_rcValue = i_rcValue;

    // Forget about any associated data (this is a new error)
    forgetData();
}

//******************************************************************************
// getPlatData function
//******************************************************************************
void * ReturnCode::getPlatData() const
{
    void * l_pData = NULL;

    if (iv_pDataRef)
    {
        l_pData = iv_pDataRef->getPlatData();
    }

    return l_pData;
}

//******************************************************************************
// releasePlatData function
//******************************************************************************
void * ReturnCode::releasePlatData()
{
    void * l_pData = NULL;

    if (iv_pDataRef)
    {
        l_pData = iv_pDataRef->releasePlatData();
    }

    return l_pData;
}

//******************************************************************************
// addErrorInfo function
//******************************************************************************
void ReturnCode::addErrorInfo(const void * const * i_pObjects,
                              const ErrorInfoEntry * i_pEntries,
                              const uint8_t i_count)
{
    for (uint32_t i = 0; i < i_count; i++)
    {
        // Figure out the object that this ErrorInfo refers to
        const void * l_pObject = i_pObjects[i_pEntries[i].iv_object];

        if (i_pEntries[i].iv_type == EI_TYPE_FFDC)
        {
            // Get the size of the object to add as FFDC
            int8_t l_size = i_pEntries[i].iv_data1;
            uint32_t l_ffdcId = i_pEntries[i].iv_data2;

            if (l_size > 0)
            {
                // This is a regular FFDC data object that can be directly
                // memcopied
                addEIFfdc(l_ffdcId, l_pObject, l_size);
            }
            else if (l_size == ReturnCodeFfdc::EI_FFDC_SIZE_ECMDDB)
            {
                // The FFDC is a ecmdDataBufferBase
                const ecmdDataBufferBase * l_pDb =
                    static_cast<const ecmdDataBufferBase *>(l_pObject);
                    
                uint32_t * l_pData = new uint32_t[l_pDb->getWordLength()];

                // getWordLength rounds up to the next 32bit boundary, ensure
                // that after extracting, any unset bits are zero
                l_pData[l_pDb->getWordLength() - 1] = 0;

                // Deliberately not checking return code from extract
                l_pDb->extract(l_pData, 0, l_pDb->getBitLength());
                addEIFfdc(l_ffdcId, l_pData, (l_pDb->getWordLength() * 4));
                
                delete [] l_pData;
            }
            else if (l_size == ReturnCodeFfdc::EI_FFDC_SIZE_TARGET)
            {
                // The FFDC is a fapi::Target
                const fapi::Target * l_pTarget =
                    static_cast<const fapi::Target *>(l_pObject);
                
                const char * l_ecmdString = l_pTarget->toEcmdString();
                addEIFfdc(l_ffdcId, l_ecmdString, (strlen(l_ecmdString) + 1));
            }
            else
            {
                 FAPI_ERR("addErrorInfo: Unrecognized FFDC data: %d", l_size);
            }
        }
        else if (i_pEntries[i].iv_type == EI_TYPE_PROCEDURE_CALLOUT)
        {
            ProcedureCallouts::ProcedureCallout l_proc =
                static_cast<ProcedureCallouts::ProcedureCallout>
                    (i_pEntries[i].iv_data2);
            CalloutPriorities::CalloutPriority l_pri =
                static_cast<CalloutPriorities::CalloutPriority>
                    (i_pEntries[i].iv_data1);

            // Add the ErrorInfo
            FAPI_ERR("addErrorInfo: Adding proc callout, proc: %d, pri: %d",
                     l_proc, l_pri);
            addEIProcedureCallout(l_proc, l_pri);
        }
        else if (i_pEntries[i].iv_type == EI_TYPE_CALLOUT)
        {
            // Get a pointer to the Target to callout and the priority
            const Target * l_pTarget = static_cast<const Target *>(l_pObject);
            CalloutPriorities::CalloutPriority l_pri =
                static_cast<CalloutPriorities::CalloutPriority>
                    (i_pEntries[i].iv_data1);

            // Add the ErrorInfo
            FAPI_ERR("addErrorInfo: Adding target callout, pri: %d", l_pri);
            addEICallout(*l_pTarget, l_pri);
        }
        else if (i_pEntries[i].iv_type == EI_TYPE_DECONF)
        {
            // Get a pointer to the Target to deconfigure
            const Target * l_pTarget = static_cast<const Target *>(l_pObject);

            // Add the ErrorInfo
            FAPI_ERR("addErrorInfo: Adding deconfigure");
            addEIDeconfigure(*l_pTarget);
        }
        else if (i_pEntries[i].iv_type == EI_TYPE_GARD)
        {
            // Get a pointer to the Target to create a GARD record for
            const Target * l_pTarget = static_cast<const Target *>(l_pObject);

            // Add the ErrorInfo
            FAPI_ERR("addErrorInfo: Adding GARD");
            addEIGard(*l_pTarget);
        }
        else
        {
            FAPI_ERR("addErrorInfo: Unrecognized EI type: %d",
                     i_pEntries[i].iv_type);
        }
    }
}

//******************************************************************************
// addEIFfdc function
//******************************************************************************
void ReturnCode::addEIFfdc(const uint32_t i_ffdcId,
                           const void * i_pFfdc,
                           const uint32_t i_size)
{
    // Create a ErrorInfoFfdc object and add it to the Error Information
    ErrorInfoFfdc * l_pFfdc = new ErrorInfoFfdc(i_ffdcId, i_pFfdc, i_size);
    getCreateReturnCodeDataRef().getCreateErrorInfo().
        iv_ffdcs.push_back(l_pFfdc);
}


//******************************************************************************
// getErrorInfo function
//******************************************************************************
const ErrorInfo * ReturnCode::getErrorInfo() const
{
    ErrorInfo * l_pErrorInfo = NULL;

    if (iv_pDataRef != NULL)
    {
        l_pErrorInfo = iv_pDataRef->getErrorInfo();
    }

    return l_pErrorInfo;
}

//******************************************************************************
// getCreator function
//******************************************************************************
ReturnCode::returnCodeCreator ReturnCode::getCreator() const
{
    returnCodeCreator l_creator = CREATOR_HWP;

    if ((iv_rcValue & FAPI_RC_FAPI_MASK) || (iv_rcValue & FAPI_RC_ECMD_MASK))
    {
        l_creator = CREATOR_FAPI;
    }
    else if (iv_rcValue & FAPI_RC_PLAT_MASK)
    {
        l_creator = CREATOR_PLAT;
    }

    return l_creator;
}

//******************************************************************************
// getCreateReturnCodeDataRef function
//******************************************************************************
ReturnCodeDataRef & ReturnCode::getCreateReturnCodeDataRef()
{
    if (iv_pDataRef == NULL)
    {
        iv_pDataRef = new ReturnCodeDataRef();
    }

    return *iv_pDataRef;
}

//******************************************************************************
// forgetData function
//******************************************************************************
void ReturnCode::forgetData()
{
    if (iv_pDataRef)
    {
        // Decrement the refcount
        if (iv_pDataRef->decRefCountCheckZero())
        {
            // Refcount decremented to zero. No other ReturnCode points to the
            // ReturnCodeDataRef object, delete it
            delete iv_pDataRef;
        }
        iv_pDataRef = NULL;
    }
}

//******************************************************************************
// addEIProcedureCallout function
//******************************************************************************
void ReturnCode::addEIProcedureCallout(
    const ProcedureCallouts::ProcedureCallout i_procedure,
    const CalloutPriorities::CalloutPriority i_priority)
{
    // Create an ErrorInfoProcedureCallout object and add it to the Error
    // Information
    ErrorInfoProcedureCallout * l_pCallout = new ErrorInfoProcedureCallout(
        i_procedure, i_priority);
    getCreateReturnCodeDataRef().getCreateErrorInfo().
        iv_procedureCallouts.push_back(l_pCallout);
}

//******************************************************************************
// addEICallout function
//******************************************************************************
void ReturnCode::addEICallout(
    const Target & i_target,
    const CalloutPriorities::CalloutPriority i_priority)
{
    // Get/Create a ErrorInfoCDG object for the target and update the callout
    ErrorInfoCDG & l_errorInfoCdg = getCreateReturnCodeDataRef().
        getCreateErrorInfo().getCreateErrorInfoCDG(i_target);
    l_errorInfoCdg.iv_callout = true;

    // If the same target is called out multiple times, use the highest priority
    if (i_priority > l_errorInfoCdg.iv_calloutPriority)
    {
        l_errorInfoCdg.iv_calloutPriority = i_priority;
    }
}

//******************************************************************************
// addEIDeconfigure function
//******************************************************************************
void ReturnCode::addEIDeconfigure(const Target & i_target)
{
    // Get/Create a ErrorInfoCDG object for the target and update the deconfig
    ErrorInfoCDG & l_errorInfoCdg = getCreateReturnCodeDataRef().
        getCreateErrorInfo().getCreateErrorInfoCDG(i_target);
    l_errorInfoCdg.iv_deconfigure = true;
}

//******************************************************************************
// addEIGard function
//******************************************************************************
void ReturnCode::addEIGard(const Target & i_target)
{
    // Get/Create a ErrorInfoCDG object for the target and update the GARD
    ErrorInfoCDG & l_errorInfoCdg = getCreateReturnCodeDataRef().
        getCreateErrorInfo().getCreateErrorInfoCDG(i_target);
    l_errorInfoCdg.iv_gard = true;
}

}
