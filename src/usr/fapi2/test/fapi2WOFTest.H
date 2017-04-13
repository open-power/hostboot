/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2WOFTest.H $                           */
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
#ifndef __WOFTEST_H__
#define __WOFTEST_H__

/**
 *  @file fapi2WOFTest.H
 *
 *  @brief Test case for WOF access code
 */

#include <stdio.h>
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include <devicefw/userif.H>
#include <utilFilter.H>

using   namespace   TARGETING;

class WOFTest: public CxxTest::TestSuite
{
public:

    /**
      * @brief Test WOF table access attribute
      *
      */
    void testWOFTableAccess (void)
    {
        //fapi2::ReturnCode l_rc;
        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sysParent;

        FAPI_INF("testWOFTableAccess: ENTER");

        // TODO RTC 172778 Enable WOF test and check for correct table data
        /*
        //Set up a char array to hold the data from an attr read
        fapi2::ATTR_WOF_TABLE_DATA_Type l_wofAttrData;

        //Perform an ATTR_GET on sys target
        FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_DATA,
                      l_sysParent,
                      l_wofAttrData);
        */
        FAPI_INF("testWOFTableAccess: EXIT !!");

  } // testWOFTableAccess

};

#endif
