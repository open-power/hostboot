//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/plat/fapiPlatTarget.C $
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
 *  @file platTarget.C
 *
 *  @brief Implements the platform part of the Target class.
 *
 *  Note that platform code must provide the implementation.
 *
 *  FAPI has provided a default implementation for platforms that use the
 *  handle pointer to point to a Component that is not created/deleted when a
 *  Target object is created/deleted (i.e. two Target objects that reference
 *  the same component have the same pointer). It could be possible for a
 *  platform specific ID structure to be created and pointed to each time a new
 *  Target is created, in that case, the pointed to object's type needs to be
 *  be known in order to do a deep compare/copy and a delete.
 */

#include <fapiTarget.H>

namespace fapi
{

//******************************************************************************
// Compare the handle
//
// If the pointers point to the same component then the handles are the same
//******************************************************************************
bool Target::compareHandle(const Target & i_right) const
{
    return (iv_pHandle == i_right.iv_pHandle);
}

//******************************************************************************
// Copy the handle
//
// Note shallow copy of iv_pHandle. Both Targets point to the same component
//******************************************************************************
void Target::copyHandle(const Target & i_right)
{
    iv_pHandle = i_right.iv_pHandle;
}

//******************************************************************************
// Delete the handle
//******************************************************************************
void Target::deleteHandle()
{
    // Intentionally does nothing. The component must not be deleted
}

}
