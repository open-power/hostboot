/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/hwasPlatAssert.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __HWAS_PLAT_ASSERT_H
#define __HWAS_PLAT_ASSERT_H

/**
 *  @file hwas/hwasPlatAssert.H
 *  @brief Forward common hwas assert requests to the platform specific
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
 *  @brief Forward common hwas assert requests to platform specific handler
 *
 *  @par Detailed Description:
 *      Forwards assert request to platform specific assert macro which verifies
 *      condition, calls custom trace if provided, and ultimately calls platform
 *      assert
 *
 *  @param[in] expr,...
 *      Printf-like expression to act as the assert message
 */
#define HWAS_ASSERT(expr,...) \
    assert(expr,__VA_ARGS__)

#endif // __HWAS_PLAT_ASSERT_H
