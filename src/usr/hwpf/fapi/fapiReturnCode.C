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
 */

#include <fapiReturnCode.H>
#include <fapiReturnCodeDataRef.H>

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
ReturnCode::ReturnCode(const uint32_t i_rcValue) :
    iv_rcValue(i_rcValue), iv_pDataRef(NULL)
{

}

//******************************************************************************
// Copy Constructor
//******************************************************************************
ReturnCode::ReturnCode(const ReturnCode & i_right) :
    iv_rcValue(i_right.iv_rcValue), iv_pDataRef(i_right.iv_pDataRef)
{
    // Note shallow copy (in initializer list) of iv_pDataRef pointer. Both
    // ReturnCodes now points to the same ReturnCodeDataRef

    if (iv_pDataRef)
    {
        // Increase the ReturnCodeDataRef reference count
        (void) iv_pDataRef->incRefCount();
    }
}

//******************************************************************************
// Destructor
//******************************************************************************
ReturnCode::~ReturnCode()
{
    // Remove interest in any pointed to ReturnCodeDataRef
    (void) removeData();
}

//******************************************************************************
// Assignment Operator
//******************************************************************************
ReturnCode & ReturnCode::operator=(const ReturnCode & i_right)
{
    // Test for self assignment
    if (this != &i_right)
    {
        // Remove interest in any pointed to ReturnCodeDataRef
        (void) removeData();

        // Copy instance variables. Note shallow copy of iv_pDataRef pointer.
        // Both ReturnCodes now points to the same ReturnCodeDataRef
        iv_rcValue = i_right.iv_rcValue;
        iv_pDataRef = i_right.iv_pDataRef;

        if (iv_pDataRef)
        {
            // Increase the ReturnCodeDataRef reference count
            (void) iv_pDataRef->incRefCount();
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
// getData function
//******************************************************************************
void * ReturnCode::getData() const
{
    void * l_pData = NULL;

    if (iv_pDataRef)
    {
        // Get the data
        l_pData = iv_pDataRef->getData();
    }

    return l_pData;
}

//******************************************************************************
// releaseData function
//******************************************************************************
void * ReturnCode::releaseData()
{
    void * l_pData = NULL;

    if (iv_pDataRef)
    {
        // Release the data
        l_pData = iv_pDataRef->releaseData();

        // Remove interest in pointed to ReturnCodeDataRef
        (void) removeData();
    }

    return l_pData;
}

//******************************************************************************
// setData function
//******************************************************************************
void ReturnCode::setData(void * i_pData)
{
    // Remove interest in pointed to ReturnCodeDataRef
    (void) removeData();

    // Create new ReturnCodeDataRef which points to the data
    iv_pDataRef = new ReturnCodeDataRef(i_pData);
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
// removeData function
//******************************************************************************
void ReturnCode::removeData()
{
    if (iv_pDataRef)
    {
        // Decrement the ReturnCodeDataRef refcount
        if (iv_pDataRef->decRefCountCheckZero())
        {
            // Refcount decremented to zero. No other ReturnCode points to the
            // ReturnCodeDataRef object, delete it
            delete iv_pDataRef;
        }
        iv_pDataRef = NULL;
    }
}

}
