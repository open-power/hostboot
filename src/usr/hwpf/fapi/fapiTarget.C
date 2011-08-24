//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/fapi/fapiTarget.C $
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
 *  @file fapiTarget.C
 *
 *  @brief Implements the FAPI part of the Target class.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/13/2011  Created. Based on Hlava prototype
 *                          mjjones     07/05/2011. Removed const from handle
 */

#include <fapiTarget.H>

namespace fapi
{

//******************************************************************************
// Default Constructor
//******************************************************************************
Target::Target() :
    iv_type(TARGET_TYPE_NONE), iv_pHandle(NULL)
{

}

//******************************************************************************
// Constructor.
//******************************************************************************
Target::Target(const TargetType i_type,
               void * i_pHandle) :
    iv_type(i_type), iv_pHandle(i_pHandle)
{

}

//******************************************************************************
// Copy Constructor
//******************************************************************************
Target::Target(const Target & i_right) :
    iv_type(i_right.iv_type)
{
    (void) copyHandle(i_right);
}

//******************************************************************************
// Destructor
//******************************************************************************
Target::~Target()
{
    (void) deleteHandle();
}

//******************************************************************************
// Assignment Operator
//******************************************************************************
Target & Target::operator=(const Target & i_right)
{
    // Test for self assignment
    if (this != &i_right)
    {
        iv_type = i_right.iv_type;
        (void) copyHandle(i_right);
    }
    return *this;
}

//******************************************************************************
// Equality Comparison Operator
//******************************************************************************
bool Target::operator==(const Target & i_right) const
{
    bool l_equal = false;

    if (iv_type == i_right.iv_type)
    {
        l_equal = compareHandle(i_right);
    }

    return l_equal;
}

//******************************************************************************
// Inequality Comparison Operator
//******************************************************************************
bool Target::operator!=(const Target & i_right) const
{
    // Determine inequality by calling the equality comparison operator
    return (!(*this == i_right));
}

//******************************************************************************
// Get the handle.
//******************************************************************************
void * Target::get() const
{
    return iv_pHandle;
}

//******************************************************************************
// Set the handle.
//******************************************************************************
void Target::set(void * i_pHandle)
{
    iv_pHandle = i_pHandle;
}

//******************************************************************************
// Get the target type
//******************************************************************************
TargetType Target::getType() const
{
    return iv_type;
}

//******************************************************************************
// Set the target type
//******************************************************************************
void Target::setType(const TargetType i_type)
{
    iv_type = i_type;
}

}
