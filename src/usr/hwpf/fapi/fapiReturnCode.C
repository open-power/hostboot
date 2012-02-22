//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/fapi/fapiReturnCode.C $
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
 */

#include <fapiReturnCode.H>
#include <fapiReturnCodeDataRef.H>
#include <fapiPlatTrace.H>

namespace fapi
{

//******************************************************************************
// Default Constructor
//******************************************************************************
ReturnCode::ReturnCode() :
    iv_rcValue(FAPI_RC_SUCCESS), iv_pDataRef(NULL)
{

}

//******************************************************************************
// Constructor
//******************************************************************************
ReturnCode::ReturnCode(const ReturnCodes i_rcValue) :
    iv_rcValue(i_rcValue), iv_pDataRef(NULL)
{

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
    FAPI_ERR("Using deprecated ReturnCode function to assign integer");
    iv_rcValue = i_rcValue;

    // Forget about any associated data
    forgetData();

    return *this;
}

//******************************************************************************
// ok function
//******************************************************************************
bool ReturnCode::ok() const
{
    return (iv_rcValue == FAPI_RC_SUCCESS);
}

//******************************************************************************
// returnCode_t cast
//******************************************************************************
ReturnCode::operator uint32_t() const
{
    return iv_rcValue;
}

//******************************************************************************
// setFapiError function
//******************************************************************************
void ReturnCode::setFapiError(const ReturnCodes i_rcValue)
{
    iv_rcValue = i_rcValue;

    // Forget about any associated data (this is a new error)
    forgetData();
}

//******************************************************************************
// setEcmdError function
//******************************************************************************
void ReturnCode::setEcmdError(const uint32_t i_rcValue)
{
    iv_rcValue = i_rcValue;

    // Forget about any associated data (this is a new error)
    forgetData();
}

//******************************************************************************
// setPlatError function
//******************************************************************************
void ReturnCode::setPlatError(void * i_pData)
{
    iv_rcValue = FAPI_RC_PLAT_ERR_SEE_DATA;

    // Forget about any associated data (this is a new error)
    forgetData();

    ensureDataRefExists();
    iv_pDataRef->setPlatData(i_pData);
}

//******************************************************************************
// _setHwpError function
//******************************************************************************
void ReturnCode::_setHwpError(const HwpReturnCode i_rcValue)
{
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
        // Figure out the object of this entry
        const void * l_pObject = i_pObjects[i_pEntries[i].iv_object];

        if (i_pEntries[i].iv_type == EI_TYPE_FFDC)
        {
            // Get the size of the object to add as FFDC
            int8_t l_size = i_pEntries[i].iv_data1;

            if (l_size > 0)
            {
                // This is a regular FFDC data object that can be directly
                // memcopied
                addEIFfdc(l_pObject, l_size);
            }
            else
            {
                // This is a special FFDC data object
                if (l_size == ReturnCodeFfdc::EI_FFDC_SIZE_ECMDDB)
                {
                    // The FFDC is a ecmdDataBufferBase
                    FAPI_ERR("addErrorInfo: Adding ecmdDB FFDC");
                    const ecmdDataBufferBase * l_pDb =
                        static_cast<const ecmdDataBufferBase *>(l_pObject);
                    ReturnCodeFfdc::addEIFfdc(*this, *l_pDb);
                }
                else if (l_size == ReturnCodeFfdc::EI_FFDC_SIZE_TARGET)
                {
                    // The FFDC is a fapi::Target
                    FAPI_ERR("addErrorInfo: Adding fapi::Target FFDC");
                    const fapi::Target * l_pTarget =
                        static_cast<const fapi::Target *>(l_pObject);
                    ReturnCodeFfdc::addEIFfdc(*this, *l_pTarget);
                }
                else
                {
                    FAPI_ERR("addErrorInfo: Unrecognized FFDC data: %d",
                             l_size);
                }
            }
        }
        else if (i_pEntries[i].iv_type == EI_TYPE_CALLOUT)
        {
            // Get a pointer to the Target to callout and the priority
            const Target * l_pTarget = static_cast<const Target *>(l_pObject);
            CalloutPriority l_pri =
                static_cast<CalloutPriority>(i_pEntries[i].iv_data1);

            // Add the ErrorInfo
            FAPI_ERR("addErrorInfo: Adding callout, pri: %d", l_pri);
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
void ReturnCode::addEIFfdc(const void * i_pFfdc,
                           const uint32_t i_size)
{
    // Create a ErrorInfoFfdc object and add it to the Error Information
    FAPI_ERR("addEIFfdc: Adding FFDC, size: %d", i_size);
    ensureDataRefExists();
    ErrorInfoFfdc * l_pFfdc = new ErrorInfoFfdc(i_pFfdc, i_size);
    iv_pDataRef->getCreateErrorInfo().iv_ffdcs.push_back(l_pFfdc);
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
// ensureDataRefExists function
//******************************************************************************
void ReturnCode::ensureDataRefExists()
{
    if (!iv_pDataRef)
    {
        iv_pDataRef = new ReturnCodeDataRef();
    }
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
// addEICallout function
//******************************************************************************
void ReturnCode::addEICallout(const Target & i_target,
                              const CalloutPriority i_priority)
{
    // Create a ErrorInfoCallout object and add it to the Error Information
    ensureDataRefExists();
    ErrorInfoCallout * l_pCallout = new ErrorInfoCallout(i_target, i_priority);
    iv_pDataRef->getCreateErrorInfo().iv_callouts.push_back(l_pCallout);
}

//******************************************************************************
// addEIDeconfigure function
//******************************************************************************
void ReturnCode::addEIDeconfigure(const Target & i_target)
{
    // Create a ErrorInfoDeconfig object and add it to the Error Information
    ensureDataRefExists();
    ErrorInfoDeconfig * l_pDeconfig = new ErrorInfoDeconfig(i_target);
    iv_pDataRef->getCreateErrorInfo().iv_deconfigs.push_back(l_pDeconfig);
}

//******************************************************************************
// addEIGard function
//******************************************************************************
void ReturnCode::addEIGard(const Target & i_target)
{
    // Create a ErrorInfoGard object and add it to the Error Information
    ensureDataRefExists();
    ErrorInfoGard * l_pGard = new ErrorInfoGard(i_target);
    iv_pDataRef->getCreateErrorInfo().iv_gards.push_back(l_pGard);
}

}
