/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2Test.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#ifndef __FAPI2TEST_H__
#define __FAPI2TEST_H__

/**
 *  @file fapi2Test.H
 *
 *  @brief Test case for FAPI2 code
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <targeting/common/targetservice.H>
#include <fapi2.H>
#include <p9_sample_procedure.H>
#include <hwp_executor.H>
#include <plat_hwp_invoker.H>
#include <pnor/pnorif.H>
#include <targeting/common/utilFilter.H>
#include <fapi2TestUtils.H>
#include <hwpf_fapi2_reasoncodes.H>

#include "fapi2HwpTest.C"
#include "fapi2GetChildrenTest.C"

using namespace fapi2;

class fapi2Test: public CxxTest::TestSuite
{
public:

/**
* @brief Test some basic HWPs that hit all targets
*        that runs through the FAPI2 macros
*
*/
void test_fapi2Test(void)
{
    FAPI_INF(">>test_fapi2HwpTest starting...");
    fapi2HwpTest();
    FAPI_INF("<<test_fapi2HwpTest exiting...");

    FAPI_INF(">>test_fapi2GetChildrenTest starting...");
    fapi2GetChildrenTest();
    FAPI_INF("<<test_fapi2ChildTest exiting...");
}

};

#endif