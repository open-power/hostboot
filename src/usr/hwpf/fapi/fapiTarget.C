/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/fapi/fapiTarget.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
 *                          mjjones     07/05/2011  Removed const from handle
 *                          mjjones     09/12/2011  Added isChip and isChiplet
 *                          mjjones     02/07/2012  Remove MBS_CHIPLET
 *                                                  Add XBUS_ENDPOINT ABUS_ENDPOINT
 *                          mjjones     02/21/2012  Add high performance toEcmdString
 *                          mjjones     07/11/2012  Clear iv_pEcmdString on set
 */

#include <fapiTarget.H>

namespace fapi
{

//******************************************************************************
// Default Constructor
//******************************************************************************
Target::Target() :
    iv_type(TARGET_TYPE_NONE), iv_pHandle(NULL), iv_pEcmdString(NULL)
{

}

//******************************************************************************
// Constructor.
//******************************************************************************
Target::Target(const TargetType i_type,
               void * i_pHandle) :
    iv_type(i_type), iv_pHandle(i_pHandle), iv_pEcmdString(NULL)
{

}

//******************************************************************************
// Copy Constructor
//******************************************************************************
Target::Target(const Target & i_right) :
    iv_type(i_right.iv_type), iv_pEcmdString(NULL)
{
    (void) copyHandle(i_right);
}

//******************************************************************************
// Destructor
//******************************************************************************
Target::~Target()
{
    (void) deleteHandle();
    delete [] iv_pEcmdString;
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
        delete [] iv_pEcmdString;
        iv_pEcmdString = NULL;
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
    delete [] iv_pEcmdString;
    iv_pEcmdString = NULL;
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

//******************************************************************************
// Is the target a chip?
//******************************************************************************
bool Target::isChip() const
{
    return ((iv_type & (TARGET_TYPE_PROC_CHIP | TARGET_TYPE_MEMBUF_CHIP)) != 0);
}

//******************************************************************************
// Is the target a chiplet?
//******************************************************************************
bool Target::isChiplet() const
{
    return ((iv_type & (TARGET_TYPE_EX_CHIPLET |
                        TARGET_TYPE_MBA_CHIPLET |
                        TARGET_TYPE_MCS_CHIPLET |
                        TARGET_TYPE_XBUS_ENDPOINT |
                        TARGET_TYPE_ABUS_ENDPOINT)) != 0);
}

//******************************************************************************
// Get the ecmd-format string
//******************************************************************************
const char * Target::toEcmdString() const
{
    if (iv_pEcmdString == NULL)
    {
        iv_pEcmdString = new char[fapi::MAX_ECMD_STRING_LEN];
        char (&l_ecmdString)[fapi::MAX_ECMD_STRING_LEN] =
            *(reinterpret_cast<char(*)[fapi::MAX_ECMD_STRING_LEN]>
                (iv_pEcmdString));
        toString(l_ecmdString);
    }

    return iv_pEcmdString;
}

}
