/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/test/hwpisteperrortest.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
#ifndef __HWPIstepErrorTest_H
#define __HWPIstepErrorTest_H

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <isteps/hwpisteperror.H>
#include <istepdispatcher.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;

class HwpIStepErrorTest: public CxxTest::TestSuite
{
public:
    /**
     * @brief Test IStepError class
     */
    void testIstepError1(void)
    {
        uint8_t l_iStep = 0;
        uint8_t l_subStep =0;
        const uint16_t MY_REASON_CODE = 0xC0DE;
        const uint8_t  MY_MODULE_ID = 0xBB;

        TS_TRACE("testIStepError1: entry");

        // Get the expected iStep and subStep. Likely the last valid values
        // since the test case is running after the iSteps.
        INITSERVICE::IStepDispatcher::
                getTheInstance().getIstepInfo(l_iStep,l_subStep);

        // Create an error log
        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                MY_MODULE_ID,
                                MY_REASON_CODE,
                                TWO_UINT32_TO_UINT64( 0xDE, 0xAD),
                                TO_UINT64(0xBEEF) );
        do {

            IStepError l_stepError;

            l_stepError.addErrorDetails( l_errl );

            TS_TRACE("testIStepError1: original elog eid is %d",
                          l_errl->eid() );

            TS_TRACE("testIStepError1: original elog reasoncode is %d",
                          l_errl->reasonCode() );

            // grab the values from the original errorlog for use later
            uint64_t test_data0 = l_errl->eid();
            test_data0 <<= 32;

            test_data0 |= l_errl->reasonCode();

            // this call to get resets the error handle
            errlHndl_t new_errl = l_stepError.getErrorHandle();

            uint64_t l_data0 = new_errl->getUserData1();

            uint32_t eid = ( l_data0  & 0xFFFFFFFF00000000) >> 32;
            uint32_t reason = (uint32_t)(l_data0 & 0x00000000FFFFFFFF);

            // Verify the reference to the added error log.
            // Added log id is in bytes 0-3 of userdata 1.
            // Reason code is in bytes 4-6 of userdata 1.
            if( eid != l_errl->eid() )
            {
                TS_FAIL("testIstepError1: expected"
                            "eid[0x%.8x] == l_errl->eid()[0x%.8x] "
                            "eid rebuilt from user data of "
                            "IStepError did not match original error eid",
                            eid, l_errl->eid());
            }
            else
            {
                TS_TRACE("testIstepError1: passed: eid == l_errl->eid()");
            }

            if( reason != l_errl->reasonCode() )
            {
                TS_FAIL("testIstepError1: "
                        "expected reasonCode == l_errl->reasonCode() \
                          reasonCode rebuilt from user data of \
                          IStepError did not match original reasoncode");

            }
            else
            {
                TS_TRACE("testIstepError1: passed: "
                         "reason == l_errl->reasonCode()");
            }

            // Verify that we counted the error we added.
            // Count is in bytes 0-3 of userdata 2.
            // iStep and subStep in bytes 4-6 of userdata 2.
            uint64_t l_data1 = new_errl->getUserData2();

            uint32_t l_count  = ( l_data1&0xFFFFFFFF00000000 ) >> 32;
            uint32_t l_errlStepSubStep =
                            (uint32_t)(l_data1&0x00000000FFFFFFFF);
            uint32_t l_expectedStepSubStep =
                            (uint32_t)(l_subStep | (l_iStep<<8));

            if( l_count != 1 )
            {
                TS_FAIL("error count in IStepError not correct,"
                        " should be 1, is %d",l_count);
            }
            else
            {
                TS_TRACE("passed: error count = 1");
            }

            if( l_errlStepSubStep != l_expectedStepSubStep )
            {
                TS_FAIL("Step/SubStep in IStepError not correct,"
                        " should be 0x%08x, is 0x%08x ",
                        l_expectedStepSubStep,
                        l_errlStepSubStep);
            }
            else
            {
                TS_TRACE("passed: step/subStep correct");
            }

            errlCommit( l_errl, CXXTEST_COMP_ID );
            errlCommit( new_errl, CXXTEST_COMP_ID );

        }while(0);
    }

    void testIstepError2(void)
    {
        uint8_t l_iStep = 0;
        uint8_t l_subStep =0;
        const uint16_t MY_REASON_CODE = 0xC0DE;
        const uint8_t  MY_MODULE_ID = 0xBB;

        TS_TRACE("testIStepError2: entry");

        // Get the expected iStep and subStep. Likely the last valid values
        // since the test case is running after the iSteps.
        INITSERVICE::IStepDispatcher::
                getTheInstance().getIstepInfo(l_iStep,l_subStep);

        // Create an error log
        errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                MY_MODULE_ID,
                                MY_REASON_CODE,
                                TWO_UINT32_TO_UINT64( 0xDE, 0xAD),
                                TO_UINT64(0xBEEF) );
        do {

            IStepError l_stepError;

            l_stepError.addErrorDetails( l_errl );

            TS_TRACE("testIStepError2: original elog eid is %d",
                      l_errl->eid() );

            TS_TRACE("testIStepError2: original elog reasoncode is %d",
                      l_errl->reasonCode() );

            // grab the values from the original errorlog for use later
            uint64_t test_data0 = l_errl->eid();
            test_data0 <<= 32;

            test_data0 |= l_errl->reasonCode();

            // add a new elog in three more times..
            // Create an error log -- junk data
            errlHndl_t l_errl2 = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                0x05,
                                0xcafe,
                                TWO_UINT32_TO_UINT64( 0xDE, 0xAD),
                                TO_UINT64(0xBEEF) );

            l_stepError.addErrorDetails( l_errl2 );
            l_stepError.addErrorDetails( l_errl2 );
            l_stepError.addErrorDetails( l_errl2 );

            // count should be 4 and the data0 and data 1 values of the
            // istep error should be the same as before

            // this call to get resets the error handle
            errlHndl_t new_errl = l_stepError.getErrorHandle();

            uint64_t l_data0 = new_errl->getUserData1();

            uint32_t eid = ( l_data0  & 0xFFFFFFFF00000000) >> 32;
            uint32_t reason = (uint32_t)(l_data0 & 0x00000000FFFFFFFF);

            if( eid != l_errl->eid() )
            {
                TS_FAIL("testIStepError2: expected "
                        "eid[0x%.8x] == l_errl->eid()[0x%.8x] "
                        "eid rebuilt from user data of "
                        "IStepError did not match original error eid",
                        eid, l_errl->eid());
            }
            else
            {
                TS_TRACE("testIStepError2: passed: eid == l_errl->eid()");
            }

            if( reason != l_errl->reasonCode() )
            {
                TS_FAIL("testIStepError2: "
                        "expected reasonCode == l_errl->reasonCode()"
                        "reasonCode rebuilt from user data of"
                        "IStepError did not match original reasoncode");

            }
            else
            {
                TS_TRACE("testIStepError2: passed: "
                         "reason == l_errl->reasonCode()");
            }

            // Verify that 4 logs have been added.
            // Count is in bytes 0-3 of userdata 2.
            // iStep and subStep in bytes 4-6 of userdata 2.
            uint64_t l_data1 = new_errl->getUserData2();

            uint32_t l_count  = ( l_data1&0xFFFFFFFF00000000 ) >> 32;
            uint32_t l_errlStepSubStep =
                            (uint32_t)(l_data1&0x00000000FFFFFFFF);
            uint32_t l_expectedStepSubStep =
                            (uint32_t)(l_subStep | (l_iStep<<8));

            if( l_count != 4 )
            {
                TS_FAIL("error count in IStepError not correct,"
                        " should be 4, is %d",l_count);
            }
            else
            {
                TS_TRACE("passed: error count = 4");
            }

            if( l_errlStepSubStep != l_expectedStepSubStep )
            {
                TS_FAIL("Step/SubStep in IStepError not correct,"
                        " should be 0x%08x, is 0x%08x ",
                        l_expectedStepSubStep,
                        l_errlStepSubStep);
            }
            else
            {
                TS_TRACE("passed: step/subStep correct");
            }

            errlCommit( l_errl, CXXTEST_COMP_ID );
            errlCommit( new_errl, CXXTEST_COMP_ID );
            errlCommit( l_errl2, CXXTEST_COMP_ID );

        }while(0);
    }

};
#endif
