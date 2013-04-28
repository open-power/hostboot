/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/tod_init/TodAssert.H $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef TODASSERT_H
#define TODASSERT_H

/**
 *  @file TodAssert.H
 *
 *  There are two different assert types provided:
 *      Standard assert behavior:
 *              assert(foo)
 *
 *      Standard assert behavior with a custom trace message:
 *              assert(foo, "This is a trace %d", 1234)
 */

#include <assert.h>

namespace TOD
{

/**
 *  @brief Forward common tod assert requests to platform specific handler
 *
 *  @par Detailed Description:
 *      Forwards assert request to platform specific assert macro which verifies
 *      condition, calls custom trace if provided, and ultimately calls platform
 *      assert
 *
 *  @param[in] expr,...
 *      Printf-like expression to act as the assert message
 */
#define TOD_ASSERT(expr,...) \
    assert(expr,__VA_ARGS__)

}

#endif
