/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/test/unittestadapter.H $                    */
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

#ifndef _TARGETING_UNITTESTADAPTER_H
#define _TARGETING_UNITTESTADAPTER_H

/**
 *  @file targeting/test/unittestadapter.H
 *
 *  @brief Header file which pulls in platform specific CXX testcase headers
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <cxxtest/TestSuite.H>

// Just forward common API call to platform specific call
#define TARG_TS_TRACE TS_TRACE

// Just forward common API call to platform specific call
#define TARG_TS_FAIL TS_FAIL

#endif // _TARGETING_UNITTESTADAPTER_H
