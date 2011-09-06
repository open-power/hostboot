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
 */

#include <fapiReturnCode.H>
#include <fapiReturnCodeDataRef.H>

namespace fapi
{

//******************************************************************************
// Default Constructor
//******************************************************************************
ReturnCode::ReturnCode() :
    iv_rcValue(FAPI_RC_SUCCESS), iv_pPlatDataRef(NULL), iv_pHwpFfdcRef(NULL),
    iv_pErrTarget(NULL)
{

}

//******************************************************************************
// Constructor
//******************************************************************************
ReturnCode::ReturnCode(const uint32_t i_rcValue) :
    iv_rcValue(i_rcValue), iv_pPlatDataRef(NULL), iv_pHwpFfdcRef(NULL),
    iv_pErrTarget(NULL)
{

}

//******************************************************************************
// Copy Constructor
//******************************************************************************
ReturnCode::ReturnCode(const ReturnCode & i_right) :
    iv_rcValue(i_right.iv_rcValue), iv_pPlatDataRef(i_right.iv_pPlatDataRef),
    iv_pHwpFfdcRef(i_right.iv_pHwpFfdcRef), iv_pErrTarget(NULL)
{
    // Note shallow copy of data ref pointers. Both ReturnCodes now point to the
    // same data

    // Increment the data ref counts and create a new copy of the error target
    if (iv_pPlatDataRef)
    {
        (void) iv_pPlatDataRef->incRefCount();
    }

    if (iv_pHwpFfdcRef)
    {
        (void) iv_pHwpFfdcRef->incRefCount();
    }

    if (i_right.iv_pErrTarget)
    {
        iv_pErrTarget = new Target(*i_right.iv_pErrTarget);
    }
}

//******************************************************************************
// Destructor
//******************************************************************************
ReturnCode::~ReturnCode()
{
    // Remove interest in any data references and delete any Error Target
    (void) removePlatData();
    (void) removeHwpFfdc();
    delete iv_pErrTarget;
    iv_pErrTarget = NULL;
}

//******************************************************************************
// Assignment Operator
//******************************************************************************
ReturnCode & ReturnCode::operator=(const ReturnCode & i_right)
{
    // Test for self assignment
    if (this != &i_right)
    {
        // Remove interest in any data references and delete any Error Target
        (void) removePlatData();
        (void) removeHwpFfdc();
        delete iv_pErrTarget;
        iv_pErrTarget = NULL;

        // Copy instance variables. Note shallow copy of data ref pointers. Both
        // ReturnCodes now point to the same data
        iv_rcValue = i_right.iv_rcValue;
        iv_pPlatDataRef = i_right.iv_pPlatDataRef;
        iv_pHwpFfdcRef = i_right.iv_pHwpFfdcRef;

        // Increment the data ref counts and create a new copy of the error tgt
        if (iv_pPlatDataRef)
        {
            (void) iv_pPlatDataRef->incRefCount();
        }

        if (iv_pHwpFfdcRef)
        {
            (void) iv_pHwpFfdcRef->incRefCount();
        }

        if (i_right.iv_pErrTarget)
        {
            iv_pErrTarget = new Target(*i_right.iv_pErrTarget);
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

    if (ok())
    {
        // Remove interest in any data references and delete any Error Target
        (void) removePlatData();
        (void) removeHwpFfdc();
        delete iv_pErrTarget;
        iv_pErrTarget = NULL;
    }

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
// getPlatData function
//******************************************************************************
void * ReturnCode::getPlatData() const
{
    void * l_pData = NULL;

    if (iv_pPlatDataRef)
    {
        // Get the data
        l_pData = iv_pPlatDataRef->getData();
    }

    return l_pData;
}

//******************************************************************************
// releasePlatData function
//******************************************************************************
void * ReturnCode::releasePlatData()
{
    void * l_pData = NULL;

    if (iv_pPlatDataRef)
    {
        // Release the data
        l_pData = iv_pPlatDataRef->releaseData();

        // Remove interest in ReturnCodePlatDataRef
        (void) removePlatData();
    }

    return l_pData;
}

//******************************************************************************
// setPlatData function
//******************************************************************************
void ReturnCode::setPlatData(void * i_pData)
{
    // Remove interest in ReturnCodePlatDataRef
    (void) removePlatData();

    // Create a new ReturnCodePlatDataRef which points to the data
    iv_pPlatDataRef = new ReturnCodePlatDataRef(i_pData);
}

//******************************************************************************
// getHwpFfdc function
//******************************************************************************
const void * ReturnCode::getHwpFfdc(uint32_t & o_size) const
{
    const void * l_pFfdc = NULL;

    if (iv_pHwpFfdcRef)
    {
        // Get the HwpFfdc
        l_pFfdc = iv_pHwpFfdcRef->getData(o_size);
    }

    return l_pFfdc;
}

//******************************************************************************
// setHwpFfdc function
//******************************************************************************
void ReturnCode::setHwpFfdc(const void * i_pFfdc, const uint32_t i_size)
{
    // Remove interest in ReturnCodeHwpFfdcRef
    (void) removeHwpFfdc();

    // Create a new ReturnCodeHwpFfdcRef which contains the HwpFfdc
    iv_pHwpFfdcRef = new ReturnCodeHwpFfdcRef(i_pFfdc, i_size);
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
// setErrTarget function
//******************************************************************************
void ReturnCode::setErrTarget(const Target & i_target)
{
    if ((iv_rcValue != FAPI_RC_SUCCESS) && (iv_pErrTarget == NULL))
    {
        // Create a copy of the target
        iv_pErrTarget = new Target(i_target);
    }
}

//******************************************************************************
// getErrTarget function
//******************************************************************************
Target * ReturnCode::getErrTarget() const
{
    return iv_pErrTarget;
}

//******************************************************************************
// removePlatData function
//******************************************************************************
void ReturnCode::removePlatData()
{
    if (iv_pPlatDataRef)
    {
        // Decrement the ReturnCodePlatDataRef refcount
        if (iv_pPlatDataRef->decRefCountCheckZero())
        {
            // Refcount decremented to zero. No other ReturnCode points to the
            // ReturnCodePlatDataRef object, delete it
            delete iv_pPlatDataRef;
        }
        iv_pPlatDataRef = NULL;
    }
}

//******************************************************************************
// removeHwpFfdc function
//******************************************************************************
void ReturnCode::removeHwpFfdc()
{
    if (iv_pHwpFfdcRef)
    {
        // Decrement the ReturnCodeHwpFfdcRef refcount
        if (iv_pHwpFfdcRef->decRefCountCheckZero())
        {
            // Refcount decremented to zero. No other ReturnCode points to the
            // ReturnCodeHwpFfdcRef object, delete it
            delete iv_pHwpFfdcRef;
        }
        iv_pHwpFfdcRef = NULL;
    }
}

}
