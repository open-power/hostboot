/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/fapi/fapiTarget.C $                              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
// $Id: fapiTarget.C,v 1.10 2014/02/26 14:51:07 mjjones Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/fapi/fapiTarget.C,v $

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
 *                          mjjones     02/24/2014  Add isChip/Chiplet using types
 *                                                  Add isPhysParentChild
 */

#include <fapiTarget.H>
#include <fapiUtil.H>

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
    fapiFree(iv_pEcmdString);
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
        fapiFree(iv_pEcmdString);
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
// Set the handle.
//******************************************************************************
void Target::set(void * i_pHandle)
{
    iv_pHandle = i_pHandle;
    fapiFree(iv_pEcmdString);
    iv_pEcmdString = NULL;
}

//******************************************************************************
// Is a target type a chip?
//******************************************************************************
bool Target::isChip(const TargetType i_type)
{
    return ((i_type & (TARGET_TYPE_PROC_CHIP | TARGET_TYPE_MEMBUF_CHIP)) != 0);
}

//******************************************************************************
// Is a target type a chiplet?
//******************************************************************************
bool Target::isChiplet(const TargetType i_type)
{
    return ((i_type & (TARGET_TYPE_EX_CHIPLET |
                       TARGET_TYPE_MBA_CHIPLET |
                       TARGET_TYPE_MCS_CHIPLET |
                       TARGET_TYPE_XBUS_ENDPOINT |
                       TARGET_TYPE_ABUS_ENDPOINT |
                       TARGET_TYPE_L4 )) != 0);
}

//******************************************************************************
// Is a target type pair a physical parent/child?
//******************************************************************************
bool Target::isPhysParentChild(const TargetType i_parentType,
                               const TargetType i_childType)
{
    bool l_result = false;

    if (i_parentType == TARGET_TYPE_PROC_CHIP)
    {
        if ((i_childType == TARGET_TYPE_EX_CHIPLET) ||
            (i_childType == TARGET_TYPE_MCS_CHIPLET) ||
            (i_childType == TARGET_TYPE_XBUS_ENDPOINT) ||
            (i_childType == TARGET_TYPE_ABUS_ENDPOINT))
        {
            l_result = true;
        }
    }
    else if (i_parentType == TARGET_TYPE_MEMBUF_CHIP)
    {
        if ((i_childType == TARGET_TYPE_MBA_CHIPLET) ||
            (i_childType == TARGET_TYPE_L4))
        {
            l_result = true;
        }
    }

    return l_result;
}

}
