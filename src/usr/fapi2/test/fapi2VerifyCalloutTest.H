/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2VerifyCalloutTest.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef __fapi2VerifyCalloutTest_H
#define __fapi2VerifyCalloutTest_H

#include <cxxtest/TestSuite.H>
#include <fapi2.H>

#include "fapi2VerifyCalloutTest.C"

class test_verifyCallout: public CxxTest::TestSuite
{
public:


    /*
     * @brief Test hw callout with gard and deconfig
     */
    void testCalloutDeconfigGard(void)
    {
        uint32_t l_res = rcTestCalloutDeconfigGard();

        if (l_res != 0)
        {
            TS_FAIL("rcTestCalloutDeconfigGard. Fail l_res=%d", l_res);
        }
    }

    /*
     * @brief Test procedure callout
     */
    void testCalloutProcedure(void)
    {
        uint32_t l_res = rcTestCalloutProcedure();

        if(l_res != 0)
        {
            TS_FAIL("rcTestCalloutProcedure. Fail l_res=%d", l_res);
        }
    }

    /*
     * @brief Test hw callout
     */
    void testCalloutHw(void)
    {
        uint32_t l_res = rcTestCalloutHw();

        if(l_res != 0)
        {
            TS_FAIL("rcTestCalloutHw. Fail l_res=%d", l_res);
        }
    }

    /*
     * @brief Test hw callout with deconfig
     */
    void testCalloutDeconfig(void)
    {
        uint32_t l_res = rcTestCalloutDeconfig();

        if(l_res != 0)
        {
            TS_FAIL("rcTestCalloutDeconfig. Fail l_res=%d", l_res);
        }
    }
};
#endif
