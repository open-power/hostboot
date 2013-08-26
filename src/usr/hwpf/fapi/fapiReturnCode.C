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
 *                          mjjones     05/20/2013  Support Bus Callouts
 *                          mjjones     06/24/2013  Support Children CDGs
 *                          mjjones     08/26/2013  Support HW Callouts
 */

#include <fapiReturnCode.H>
#include <fapiReturnCodeDataRef.H>
#include <fapiPlatTrace.H>
#include <fapiTarget.H>
#include <fapiUtil.H>

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
        ErrorInfoType l_type = static_cast<ErrorInfoType>(
            i_pEntries[i].iv_type);

        if (l_type == EI_TYPE_FFDC)
        {
            uint8_t l_objIndex = i_pEntries[i].ffdc.iv_ffdcObjIndex;
            uint16_t l_size = i_pEntries[i].ffdc.iv_ffdcSize;
            uint32_t l_ffdcId = i_pEntries[i].ffdc.iv_ffdcId;

            // Get the object to add as FFDC
            const void * l_pObject = i_pObjects[l_objIndex];

            if (l_size == ReturnCodeFfdc::EI_FFDC_SIZE_ECMDDB)
            {
                // The FFDC is a ecmdDataBufferBase
                const ecmdDataBufferBase * l_pDb =
                    static_cast<const ecmdDataBufferBase *>(l_pObject);
                    
                size_t byteLength = l_pDb->getWordLength() * sizeof(uint32_t);
                uint32_t * l_pData =
                        reinterpret_cast<uint32_t*>(fapiMalloc(byteLength));

                // getWordLength rounds up to the next 32bit boundary, ensure
                // that after extracting, any unset bits are zero
                l_pData[l_pDb->getWordLength() - 1] = 0;

                // Deliberately not checking return code from extract
                l_pDb->extract(l_pData, 0, l_pDb->getBitLength());
                addEIFfdc(l_ffdcId, l_pData, (l_pDb->getWordLength() * 4));
                
                fapiFree(l_pData);
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
                // This is a regular FFDC data object that can be directly
                // memcopied
                addEIFfdc(l_ffdcId, l_pObject, l_size);
            }
        }
        else if (l_type == EI_TYPE_HW_CALLOUT)
        {
            HwCallouts::HwCallout l_hw = static_cast<HwCallouts::HwCallout>(
                i_pEntries[i].hw_callout.iv_hw);
            CalloutPriorities::CalloutPriority l_pri =
                static_cast<CalloutPriorities::CalloutPriority>(
                    i_pEntries[i].hw_callout.iv_calloutPriority);

            // A refIndex of 0xff indicates that there is no reference target
            uint8_t l_refIndex = i_pEntries[i].hw_callout.iv_refObjIndex;

            if (l_refIndex != 0xff)
            {
                const Target * l_pRefTarget = static_cast<const Target *>(
                    i_pObjects[l_refIndex]);
                FAPI_ERR("addErrorInfo: Adding hw callout with ref, hw: %d, pri: %d",
                     l_hw, l_pri);
                addEIHwCallout(l_hw, l_pri, *l_pRefTarget);
            }
            else
            {
                Target l_emptyTarget;
                FAPI_ERR("addErrorInfo: Adding hw callout with no ref, hw: %d, pri: %d",
                     l_hw, l_pri);
                addEIHwCallout(l_hw, l_pri, l_emptyTarget);
            }
        }
        else if (l_type == EI_TYPE_PROCEDURE_CALLOUT)
        {
            ProcedureCallouts::ProcedureCallout l_proc =
                static_cast<ProcedureCallouts::ProcedureCallout>(
                    i_pEntries[i].proc_callout.iv_procedure);
            CalloutPriorities::CalloutPriority l_pri =
                static_cast<CalloutPriorities::CalloutPriority>(
                    i_pEntries[i].proc_callout.iv_calloutPriority);

            // Add the ErrorInfo
            FAPI_ERR("addErrorInfo: Adding proc callout, proc: %d, pri: %d",
                     l_proc, l_pri);
            addEIProcedureCallout(l_proc, l_pri);
        }
        else if (l_type == EI_TYPE_BUS_CALLOUT)
        {
            uint8_t l_ep1Index = i_pEntries[i].bus_callout.iv_endpoint1ObjIndex;
            uint8_t l_ep2Index = i_pEntries[i].bus_callout.iv_endpoint2ObjIndex;
            CalloutPriorities::CalloutPriority l_pri =
                static_cast<CalloutPriorities::CalloutPriority>(
                    i_pEntries[i].bus_callout.iv_calloutPriority);

            // Get the endpoint Targets for the bus to callout
            const Target * l_pTarget1 = static_cast<const Target *>(
                i_pObjects[l_ep1Index]);
            const Target * l_pTarget2 = static_cast<const Target *>(
                i_pObjects[l_ep2Index]);

            // Add the ErrorInfo
            FAPI_ERR("addErrorInfo: Adding bus callout, pri: %d", l_pri);
            addEIBusCallout(*l_pTarget1, *l_pTarget2, l_pri);
        }
        else if (l_type == EI_TYPE_CDG)
        {
            uint8_t l_targIndex = i_pEntries[i].target_cdg.iv_targetObjIndex;
            uint8_t l_callout = i_pEntries[i].target_cdg.iv_callout;
            uint8_t l_deconf = i_pEntries[i].target_cdg.iv_deconfigure;
            uint8_t l_gard = i_pEntries[i].target_cdg.iv_gard;
            CalloutPriorities::CalloutPriority l_pri =
                static_cast<CalloutPriorities::CalloutPriority>(
                    i_pEntries[i].target_cdg.iv_calloutPriority);

            // Get the Target to cdg
            const Target * l_pTarget = static_cast<const Target *>(
                i_pObjects[l_targIndex]);

            // Add the ErrorInfo
            FAPI_ERR("addErrorInfo: Adding target cdg (%d:%d:%d), pri: %d",
                     l_callout, l_deconf, l_gard, l_pri);
            addEICdg(*l_pTarget, l_callout, l_deconf, l_gard, l_pri);
        }
        else if (l_type == EI_TYPE_CHILDREN_CDG)
        {
            uint8_t l_parentChipIndex =
                i_pEntries[i].children_cdg.iv_parentChipObjIndex;
            TargetType l_childType = static_cast<TargetType>(
                i_pEntries[i].children_cdg.iv_childType);
            uint8_t l_callout = i_pEntries[i].children_cdg.iv_callout;
            uint8_t l_deconf = i_pEntries[i].children_cdg.iv_deconfigure;
            uint8_t l_gard = i_pEntries[i].children_cdg.iv_gard;
            CalloutPriorities::CalloutPriority l_pri =
                static_cast<CalloutPriorities::CalloutPriority>(
                    i_pEntries[i].children_cdg.iv_calloutPriority);

            // Get the Parent Target of the children to cdg
            const Target * l_pParentChip = static_cast<const Target *>(
                i_pObjects[l_parentChipIndex]);

            // Add the ErrorInfo
            FAPI_ERR("addErrorInfo: Adding children cdg (%d:%d:%d), type: 0x%08x, pri: %d",
                     l_callout, l_deconf, l_gard, l_childType, l_pri);
            addEIChildrenCdg(*l_pParentChip, l_childType, l_callout, l_deconf,
                             l_gard, l_pri);
        }
        else
        {
            FAPI_ERR("addErrorInfo: Unrecognized EI type: %d", l_type);
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

    // Note: This gets deallocated in ~ErrorInfo()
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
// addEIHwCallout function
//******************************************************************************
void ReturnCode::addEIHwCallout(
    const HwCallouts::HwCallout i_hw,
    const CalloutPriorities::CalloutPriority i_priority,
    const Target & i_refTarget)
{
    // Create an ErrorInfoHwCallout object and add it to the Error Information
    ErrorInfoHwCallout * l_pCallout = new ErrorInfoHwCallout(
        i_hw, i_priority, i_refTarget);
    getCreateReturnCodeDataRef().getCreateErrorInfo().
        iv_hwCallouts.push_back(l_pCallout);
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
// addEIBusCallout function
//******************************************************************************
void ReturnCode::addEIBusCallout(
    const Target & i_target1,
    const Target & i_target2,
    const CalloutPriorities::CalloutPriority i_priority)
{
    // Create an ErrorInfoBusCallout object and add it to the Error Information
    ErrorInfoBusCallout * l_pCallout = new ErrorInfoBusCallout(
        i_target1, i_target2, i_priority);
    getCreateReturnCodeDataRef().getCreateErrorInfo().
        iv_busCallouts.push_back(l_pCallout);
}

//******************************************************************************
// addEICdg function
//******************************************************************************
void ReturnCode::addEICdg(
    const Target & i_target,
    const bool i_callout,
    const bool i_deconfigure,
    const bool i_gard,
    const CalloutPriorities::CalloutPriority i_priority)
{
    // Create an ErrorInfoCDG object and add it to the Error Information
    ErrorInfoCDG * l_pCdg = new ErrorInfoCDG(i_target, i_callout, i_deconfigure,
        i_gard, i_priority);
    getCreateReturnCodeDataRef().getCreateErrorInfo().
        iv_CDGs.push_back(l_pCdg);
}

//******************************************************************************
// addEIChildrenCdg function
//******************************************************************************
void ReturnCode::addEIChildrenCdg(
    const Target & i_parentChip,
    const TargetType i_childType,
    const bool i_callout,
    const bool i_deconfigure,
    const bool i_gard,
    const CalloutPriorities::CalloutPriority i_priority)
{
    // Create an ErrorInfoChildrenCDG object and add it to the Error Information
    ErrorInfoChildrenCDG * l_pCdg = new ErrorInfoChildrenCDG(i_parentChip,
        i_childType, i_callout, i_deconfigure, i_gard, i_priority);
    getCreateReturnCodeDataRef().getCreateErrorInfo().
        iv_childrenCDGs.push_back(l_pCdg);
}

}
