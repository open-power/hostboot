//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/targeting/adapters/erroradapter.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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

#ifndef __TARGETING_ERRORADAPTER_H
#define __TARGETING_ERRORADAPTER_H

/**
 *  @file targeting/adapters/erroradapter.H
 *
 *  @brief Adapts platform neutral error log requests to the platform
 */

//******************************************************************************
// Includes
//******************************************************************************

// Include the platform specific errlentry.H file and pick up the platform 
// specific errlHndlt_t typedef. This is enough for common code to use pass 
// errlHndl_t pointers around and check for NULL
#include <errl/errlentry.H>

namespace COMMON
{

namespace ERRORLOG
{
    /**
     *  @brief Import the ::ERRORLOG namespace into the ::COMMON:ERRORLOG
     *      namespace.  This allows all the common targeting code to use the 
     *      same namespacing yet directly invoke platform specific error log 
     *      support.  Since nothing else is declared in the namespace, there is 
     *      no danger of a namespace collision.
     */
    using namespace ::ERRORLOG;

} // End namespace COMMON

} // End namespace ERRORLOG

#endif // __TARGETING_ERRORADAPTER_H
