//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/test/initservicetest.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

/**
 * @file    initservicetest.H
 *
 *  Unit tests for initservice module
 *
 */

#ifndef __TEST_INIT_SERVICETEST_H
#define __TEST_INIT_SERVICETEST_H



#include    <cxxtest/TestSuite.H>

#include    "../baseinitsvc/initservice.H"

/**
 * @brief   set up a dummy TaskInfo struct for test 1.
 * this taskname should not exist, so we are expecting an error log back.
 *
 */
const   INITSERVICE::TaskInfo    TASK_TEST1  =  {
        "libtestinitsvc_noexist.so" ,                   // taskname
        NULL,                                           // ptr to fn
        {
                INITSERVICE::START_TASK,                // startflag=true, try to start
                INITSERVICE::BASE_IMAGE,                // Base Module
                INITSERVICE::INIT_SVC_TEST1_ERRL_ID,    // module id for errorlog
        },
};


/**
 * @brief   set up a dummy TaskInfo struct for test 2.
 *  tasktest2 does indeed have a _start() function so this should return OK.
 *
 */
const   INITSERVICE::TaskInfo    TASK_TEST2  =  {
        "libinitsvctasktest2.so" ,                               // taskname
        NULL,                                           // ptr to fn
        {
                INITSERVICE::START_TASK,                // startflag=true, try to start
                INITSERVICE::BASE_IMAGE,                // Base Module
                INITSERVICE::INIT_SVC_TEST2_ERRL_ID,    // module id for errorlog
        },
};


/**
 * @brief   set up a dummy TaskInfo struct.
 *  libtrace does NOT have a _start() function so this should return an errorlog.
 *
 *  @todo   this needs to be replaced with a test module
 */
const   INITSERVICE::TaskInfo    TASK_TEST3  =  {
        "libtrace.so" ,                                 // taskname
        NULL,                                           // ptr to fn
        {
                INITSERVICE::START_TASK,                // startflag=true, try to start
                INITSERVICE::BASE_IMAGE,                // Base Module
                INITSERVICE::INIT_SVC_TEST3_ERRL_ID,    // module id for errorlog
        },
};

/**
 * @class InitServiceTest
 *
 *  runs unit testa against InitService class
 *
 */
class InitServiceTest: public CxxTest::TestSuite
{

public:
    /**
     *  @brief  testInitServiceStartTask1
     *      this should try to run a nonexistent task, return an
     *      errorlog, and not blow up
     *
     */
    void testInitServiceStartTask1(void)
    {

        errlHndl_t  l_errl    = NULL;
        /**
         * @todo    use a separate instance here, not the singleton
         */
        INITSERVICE::InitService &l_is
            = INITSERVICE::InitService::getTheInstance();

        TS_TRACE( "=====>Run a nonexistent task, expect an ERROR.");
        l_errl = l_is.startTask(  &TASK_TEST1,
                                NULL );
        if ( l_errl  )
        {
            TS_TRACE( "SUCCESS: startTask returned an errorlog.\n");
            //  clean up
            errlCommit( l_errl );
        }
        else
        {
            TS_FAIL( "ERROR: no error log was returned.\n");
        }

        return;
    }

    /**
     *  @brief  testInitServiceStartTask2
     *  this should try to run a task that does have a _start() function.
     *          it should return OK.
     */
    void testInitServiceStartTask2(void)
    {
        errlHndl_t  l_errl  =   NULL;
        /**
         * @todo    use a separate instance here, not the singleton
         */
        INITSERVICE::InitService &l_is
            = INITSERVICE::InitService::getTheInstance();

        TS_TRACE( "=====>Run a task with _start() function, expect SUCCESS.");
        l_errl = l_is.startTask( &TASK_TEST2,
                                 NULL );
        if ( l_errl )
        {
            TS_FAIL( "ERROR: StartTask returned an error log.\n");
            errlCommit( l_errl );
        }
        else
        {
            TS_TRACE( "SUCCESS: startTask returned OK.\n");
        }

        return;
    }


    /**
     *  @brief  testInitServiceStartTask3
     *  this should try to run a task that does NOT have a  _start() function.
     *          it should fail
     */
    void testInitServiceStartTask3(void)
    {
        errlHndl_t  l_errl    = NULL;
        /**
         * @todo    use a separate instance here, not the singleton
         */
        INITSERVICE::InitService   &l_is
            = INITSERVICE::InitService::getTheInstance();

        TS_TRACE( "====>Run a task with NO _start() function, expect an ERROR.");
        l_errl = l_is.startTask(  &TASK_TEST3,
                                NULL );
        if ( l_errl )
        {
            TS_TRACE( "SUCCESS: startTask returned an error log.\n");
            errlCommit( l_errl );
        }
        else
        {
            TS_FAIL( "ERROR: StartTask did not return an error log.\n");
        }

        return;
    }

};  // class InitServiceTest


#endif  // __TEST_INIT_SERVICETEST_H

