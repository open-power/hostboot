/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/cxxtest/cxxtest_data.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

/** @file   cxxtest_data.H
 *
 */


#ifndef __cxxtest__cxxtest_data_h__
#define __cxxtest__cxxtest_data_h__


namespace CxxTest
{

enum
{
    CXXTEST_FILENAME_SIZE         =    50,
    CXXTEST_FAIL_LIST_SIZE        =    10
};

struct CxxTestFailedEntry
{
    char failTestFile[CXXTEST_FILENAME_SIZE];
    uint64_t failTestData;
};

} // namespace CxxTest

#endif // __cxxtest__cxxtest_data_h__