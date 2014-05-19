/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/test/errlReportTest.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef __ERRLREPORTTEST_H
#define __ERRLREPORTTEST_H

/**
 *  @file errlReportTest.H
 *
 *  @brief Test case for Error Logging Reporting
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errlreasoncodes.H>
#include <trace/trace.H>
#include <hbotcompid.H>
#include <errl/errludtarget.H>
#include <targeting/common/target.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicates.H>
#include <hwas/common/hwasCallout.H>
#include <kernel/syscalls.H>
#include <sys/time.h>


class ErrlReportTest: public CxxTest::TestSuite
{
public:

    /**
     * @brief Send a small size error log to FSP
     *  - Create an error log with only 192 bytes
     *  - Verify that hostbot created error log and sent it to FSP
     *  - Found an issue with FSI mailbox DMA code to realign data len
     *  - The problem should be fixed in Feature 855338 (fips810)
     */

    void testErrlReport1(void)
    {
        errlHndl_t l_err = NULL;
        uint64_t l_userData1 = 0xDEADBEEF;
        uint64_t l_userData2 = 0xDEADBEEF;

        TS_TRACE( "test testErrlReport1");
        do
        {
            // Create an error log
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE,
                                    l_userData1,
                                    l_userData2);
            if (l_err == NULL)
            {
                TS_FAIL("testErrlReport1: createErrlLog() failed.");
                break;
            }

            // Commit error log.
            errlCommit(l_err, CXXTEST_COMP_ID);

        } while(0);
    }


    /**
     * @brief Send multiple error logs back to back to FSP
     *  - Create several error logs and send them to FSP in a loop.
     *  - Verify that error logs are created and sent to FSP
     *  - Verify that FSP received all the error logs and log them properly.
     */
    void testErrlReport2( void )
    {
        errlHndl_t l_err = NULL;
        uint32_t l_loopi = 0 ;

        TS_TRACE( "test testErrlReport2");

        do
        {
            for (l_loopi = 0; l_loopi < 5; l_loopi++)
            {

                 // Create an error log
                 l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE,
                                    l_loopi,
                                    l_loopi);
                 if (l_err == NULL)
                 {
                     TS_FAIL("testErrlReport2: createErrlLog() failed.");
                     break;
                 }

                 // Commit error log
                 errlCommit(l_err, CXXTEST_COMP_ID);
           }
        } while(0);
    }



    /**
     * @brief Send an unrecoverable error log to FSP
     *  - Verify that an error log with severity unrecoverable created successfully
     *  - Verify that the error log is sent to FSP
     *  - Verify that FSP log the error as unrecoverable one.
     *
     */

    void testErrlReport3(void)
    {
        errlHndl_t l_err = NULL;
        uint64_t l_userData1 = 0xEEEEEEEE;
        uint64_t l_userData2 = 0xEEEEEEEE;

        TS_TRACE( "test testErrlReport3");
        do
        {
            // Create an error log
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE,
                                    l_userData1,
                                    l_userData2);
            if (l_err == NULL)
            {
                TS_FAIL("testErrlReport3: createErrlLog() failed");
                break;
            }

            // Commit error log.
            errlCommit(l_err, CXXTEST_COMP_ID);
        } while(0);
    }


    /**
     * @brief Send a critical system terminate error log from Hostboot to FSP
     *  - Verify that hostbot errorlog is sent to FSP.
     *  - Verify that FSP logged the error as critical system terminate one.
     *
     */

    void testErrlReport4(void)
    {
        errlHndl_t l_err = NULL;
        uint64_t l_userData1 = 0xAAAAAAAA;
        uint64_t l_userData2 = 0xBBBBBBBB;

        TS_TRACE( "test testErrlReport4");
        do
        {
            // Create an error log
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE,
                                    l_userData1,
                                    l_userData2);
            if (l_err == NULL)
            {
                TS_FAIL("testErrlReport4: createErrlLog() failed.");
                break;
            }

            // Commit error log.
            errlCommit(l_err, CXXTEST_COMP_ID);
        } while(0);
    }

    /**
     * @brief Send a big size error log to FSP
     *  - Verfiy that an error log with ffdc and traces is created successfully
     *  - Verify that the error log is sent to FSP
     *  - Verify that FSP logged the error with correct data successfully
     */
    void testErrlReport5(void)
    {
        bool l_rc;
        ERRORLOG::ErrlUD * pffdc;
        uint64_t l_userData1 = 0xFFFFFFFF;
        uint64_t l_userData2 = 0xFFFFFFFF;

        TS_TRACE( "test testErrlReport5");
        do
        {
            // Create an error log
            errlHndl_t l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ERRORLOG::ERRL_TEST_MOD_ID,
                                    ERRORLOG::ERRL_TEST_REASON_CODE,
                                    l_userData1,
                                    l_userData2);


            // Make sure log is created
            if (l_err == NULL)
            {
                TS_FAIL("testErrlReport5: createErrlLog() failed");
                break;
            }

            // add FFDC
            const char * l_str = "Error log report testing.";
            pffdc = l_err->addFFDC( DEVFW_COMP_ID, l_str, strlen( l_str ), 0, 0);
            if ( NULL == pffdc )
            {
                TS_FAIL("testErrlReport5: addFFDC() failed");
                break;
            }

            // Collect traces
            l_rc = l_err->collectTrace(  "XSCOM" , 0x7D0 );
            if( !l_rc )
            {
                TS_FAIL( "testErrlReport5: collectTrace(XSCOM) returns false." );
                break;
            }

            l_rc = l_err->collectTrace(  "TARG" , 4003 );
            if( !l_rc )
            {
                TS_FAIL( "testErrlReport5: collectTrace(TARG,4003) returns false" );
                break;
            }

            // Add null data.
            pffdc = l_err->addFFDC( ERRL_COMP_ID, NULL, 0,  9, 10 );
            if ( NULL != pffdc )
            {
                TS_FAIL(" addFFDC() returned non null");
                break;
            }

            // Commit error log.
            errlCommit(l_err, CXXTEST_COMP_ID);

        } while(0);
    }

};

#endif
