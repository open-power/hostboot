/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/test/hwpisteperrortest.H $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
#ifndef __HWPIstepErrorTest_H
#define __HWPIstepErrorTest_H

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <hwpisteperror.H>

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

    const uint16_t MY_REASON_CODE = 0xC0DE;
    const uint8_t  MY_MODULE_ID = 0xBB;
            // Create an error log
            errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    MY_MODULE_ID,
                                    MY_REASON_CODE,
                                    TWO_UINT32_TO_UINT64( 0xDE, 0xAD),
                                    TO_UINT64(0xBEEF) );
            do {

                IStepError l_stepError;

                l_stepError.addErrorDetails( ISTEP_INVALID_REASONCODE,
                                             ISTEP_INVALID_MODULE, l_errl );

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

                uint32_t eid = ( l_data0  & 0xFFFFFFF00000000) >> 32;
                uint32_t reason = (uint32_t)(l_data0 & 0x00000000FFFFFFFF);

                if( eid != l_errl->eid() )
                {
                    TS_FAIL("expected eid == l_errl->eid() "
                              "eid rebuilt from user data of "
                              "IStepError did not match original error eid");
                }
                else
                {
                    TS_TRACE("passed: eid == l_errl->eid()");
                }

                if( reason != l_errl->reasonCode() )
                {
                    TS_FAIL("expected reasonCode == l_errl->reasonCode() \
                              reasonCode rebuilt from user data of \
                              IStepError did not match original reasoncode");

                }
                else
                {
                    TS_TRACE("passed: reason == l_errl->reasonCode()");
                }


                // verify that we counted the error we added
                // count is in bytes 0-3 of userdata 2
                //
                uint64_t l_data1 = new_errl->getUserData2();

                l_data1 >>= 32;

                if( l_data1 != 1 )
                {
                    TS_FAIL("error count in IStepError not correct should be 1");
                }
                else
                {
                    TS_TRACE("passed: error count = 1");
                }


                errlCommit( l_errl, CXXTEST_COMP_ID );
                errlCommit( new_errl, CXXTEST_COMP_ID );

            }while(0);
    }
    void testIstepError2(void)
    {

    const uint16_t MY_REASON_CODE = 0xC0DE;
    const uint8_t  MY_MODULE_ID = 0xBB;
            // Create an error log
            errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    MY_MODULE_ID,
                                    MY_REASON_CODE,
                                    TWO_UINT32_TO_UINT64( 0xDE, 0xAD),
                                    TO_UINT64(0xBEEF) );
            do {

                IStepError l_stepError;

                l_stepError.addErrorDetails( ISTEP_INVALID_REASONCODE,
                                             ISTEP_INVALID_MODULE, l_errl );

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

                l_stepError.addErrorDetails( ISTEP_INVALID_REASONCODE,
                                             ISTEP_INVALID_MODULE, l_errl2);

                l_stepError.addErrorDetails( ISTEP_INVALID_REASONCODE,
                                             ISTEP_INVALID_MODULE, l_errl2);

                l_stepError.addErrorDetails( ISTEP_INVALID_REASONCODE,
                                             ISTEP_INVALID_MODULE, l_errl2);

                // count should be 4 and the data0 and data 1 values of the
                // istep error should be the same as before


                // this call to get resets the error handle
                errlHndl_t new_errl = l_stepError.getErrorHandle();

                uint64_t l_data0 = new_errl->getUserData1();

                uint32_t eid = ( l_data0  & 0xFFFFFFF00000000) >> 32;
                uint32_t reason = (uint32_t)(l_data0 & 0x00000000FFFFFFFF);

                if( eid != l_errl->eid() )
                {
                    TS_FAIL("expected eid == l_errl->eid() "
                              "eid rebuilt from user data of "
                              "IStepError did not match original error eid");
                }
                else
                {
                    TS_TRACE("passed: eid == l_errl->eid()");
                }

                if( reason != l_errl->reasonCode() )
                {
                    TS_FAIL("expected reasonCode == l_errl->reasonCode()"
                              "reasonCode rebuilt from user data of"
                              "IStepError did not match original reasoncode");

                }
                else
                {
                    TS_TRACE("passed: reason == l_errl->reasonCode()");
                }

                // verify that we counted the error we added
                // count is in bytes 0-3 of userdata 2
                //
                uint64_t l_data1 = new_errl->getUserData2();

                l_data1 >>= 32;

                if( l_data1 != 4 )
                {
                    TS_FAIL("error count in IStepError not correct"
                             "should be 4");
                    TS_TRACE("error count is %d", l_data1 );
                }
                else
                {
                    TS_TRACE("passed: error count is correct [%d]", l_data1 );
                }

                errlCommit( l_errl, CXXTEST_COMP_ID );
                errlCommit( new_errl, CXXTEST_COMP_ID );
                errlCommit( l_errl2, CXXTEST_COMP_ID );

            }while(0);
    }

};
#endif
