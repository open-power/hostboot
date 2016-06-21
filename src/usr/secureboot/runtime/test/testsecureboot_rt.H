/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/runtime/test/testsecureboot_rt.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

/**
 *  @file testsecureboot_rt.H
 *  @brief Test secureboot runtime functions
 */

#ifndef __TESTSECUREBOOT_RT_H
#define __TESTSECUREBOOT_RT_H

#include <cxxtest/TestSuite.H>
#include <runtime/interface.h>
#include <config.h>

#include "common/securetrace.H"

class SecurebootRtTestSuite: public CxxTest::TestSuite
{
    public:

    void testVerifyContainer()
    {
        SB_ENTER("SecurebootRtTestSuite::testVerifyContainer");

        do {

        auto pRtIntf = getRuntimeInterfaces();
        if (nullptr == pRtIntf)
        {
            TS_FAIL("testVerifyContainer: runtime interfaces pointer "
                "not set");
            break;
        }

#ifndef CONFIG_SECUREBOOT

        if (nullptr != pRtIntf->verify_container)
        {
            TS_FAIL("testVerifyContainer: verify_container function pointer "
                "set unexpectedly with secureboot compiled out");
            break;
        }

#else

        if (nullptr == pRtIntf->verify_container)
        {
            TS_FAIL("testVerifyContainer: verify_container function pointer "
                "not set with secureboot compiled in");
            break;
        }

        // If secureboot is compiled in, perform various API tests

        // TODO: RTC 156485 For now, function is a no op; add real tests here
        // when verify_container is fully implemented
        auto rc = pRtIntf->verify_container(
            nullptr,nullptr,0);
        if(rc != 0)
        {
            TS_FAIL("testVerifyContainer: expected verify_container to succeed "
                "when secureboot is compiled in -and- verify_container is not "
                "fully implemented, but it failed with rc = %d",
                rc);
            break;
        }

#endif

        } while(0);

        SB_EXIT("SecurebootRtTestSuite::testVerifyContainer");
    }

    private:

};

#endif
