//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/targeting/adapters/assertadapter.H $
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

#ifndef __TARGETING_ASSERTADAPTER_H
#define __TARGETING_ASSERTADAPTER_H

/**
 *  @file targeting/adapters/assertadapter.H
 *  @brief Forward common targeting assert requests to the platform specific
 *      handlers
 *
 *  There are two different assert types provided:
 *      Standard assert behavior:
 *              assert(foo)
 *
 *      Standard assert behavior with a custom trace message:
 *              assert(foo, "This is a trace %d", 1234)
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <assert.h>

/**
 *  @brief Forward common targeting assert requests to platform specific handler
 *
 *  @par Detailed Description:
 *      Forwards assert request to platform specific assert macro which verifies
 *      condition, calls custom trace if provided, and ultimately calls platform
 *      assert
 *
 *  @param[in] expr,...
 *      Printf-like expression to act as the assert message
 */
#define TARG_ASSERT(expr,...) \
    assert(expr,__VA_ARGS__)

#endif // __TARGETING_ASSERTADAPTER_H
