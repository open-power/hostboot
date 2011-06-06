/**
 * @file    initservicetest.H
 *
 *  Private functions for VFS2 phase.
 */

#ifndef __TEST_INIT_SERVICETEST_H
#define __TEST_INIT_SERVICETEST_H

/**
 *  @file initservicetest.H
 *
 *  @brief Unit tests for initservice module
 */

#include    <cxxtest/TestSuite.H>

#include    "../initservice.H"

/**
 * @brief   set up a dummy TaskInfo struct for test 1.
 * this taskname should not exist, so we are expecting an error log back.
 *
 */
const   INITSERVICE::TaskInfo    TASK_TEST1  =  {
        "libtestinitsvc_noexist.so" ,                   // taskname
        {
                true,                               // startflag=true, try to start
                INITSERVICE::BASE_MODULE,           // Base Module
                INITSERVICE::INIT_SVC_TEST1_ID,     // module id for errorlog
        },
};


/**
 * @brief   set up a dummy TaskInfo struct for test 2.
 *  example.C does indeed have a _start() function so this should return OK.
 *
 *  @todo   this needs to be replaced with a test module
 */
const   INITSERVICE::TaskInfo    TASK_TEST2  =  {
        "libexample.so" ,                           // taskname
        {
                true,                               // startflag=true, try to start
                INITSERVICE::BASE_MODULE,           // Base Module
                INITSERVICE::INIT_SVC_TEST2_ID,     // module id for errorlog
        },
};


/**
 * @brief   set up a dummy TaskInfo struct.
 *  libtrace does NOT have a _start() function so this should return an errorlog.
 *
 *  @todo   this needs to be replaced with a test module
 */
const   INITSERVICE::TaskInfo    TASK_TEST3  =  {
        "libtrace.so" ,                           // taskname
        {
                true,                               // startflag=true, try to start
                INITSERVICE::BASE_MODULE,           // Base Module
                INITSERVICE::INIT_SVC_TEST3_ID,     // module id for errorlog
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
        errlHndl_t  errl    = NULL;
        /**
         * @todo    use a separate instance here, not the singleton
         */
        INITSERVICE::InitService   &l_is = INITSERVICE::InitService::getTheInstance();
        tid_t   tidrc   =   0;


        TS_TRACE( "=====>Attempt to run a nonexistent task.\n  ");
        tidrc   =   l_is.startTask( TASK_TEST1, errl );
        printk( "testInitServiceStartTask1: startTask returned %d: errl=%p\n", tidrc, errl );
        if ( (int16_t)tidrc < 0  )
        {
            TS_TRACE( "SUCCESS: startTask returned an errorlog.\n");
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
        errlHndl_t  errl    = NULL;
        /**
         * @todo    use a separate instance here, not the singleton
         */
        INITSERVICE::InitService   &l_is = INITSERVICE::InitService::getTheInstance();
        tid_t   tidrc   =   0;


        TS_TRACE( "=====>Attempt to run a task with a _start() function.\n  ");
        tidrc   =   l_is.startTask( TASK_TEST2, errl );
        printk( "testInitServiceStartTask2: startTask returned %d: errl=%p\n", tidrc, errl );
        if ( (int16_t)tidrc >= 0  )
        {
            TS_TRACE( "SUCCESS: startTask returned OK.\n");
        }
        else
        {
            TS_FAIL( "ERROR: StartTask returned an error log.\n");
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
        errlHndl_t  errl    = NULL;
        /**
         * @todo    use a separate instance here, not the singleton
         */
        INITSERVICE::InitService   &l_is = INITSERVICE::InitService::getTheInstance();
        tid_t   tidrc   =   0;


        TS_TRACE( "====>Attempt to run a task with NO _start() function.\n  ");
        tidrc   =   l_is.startTask( TASK_TEST3, errl );
        printk( "testInitServiceStartTask3: startTask returned %d: errl=%p\n", tidrc, errl );
        if ( (int16_t)tidrc < 0  )
        {
            TS_TRACE( "SUCCESS: startTask returned an error log.\n");
        }
        else
        {
            TS_FAIL( "ERROR: StartTask did not return an error log.\n");
        }

        return;
    }

    /**
     *  @brief  testInitServicereportError1
     *      This will call reportError with a NULL errlHndl_t .  It should handle it
     *      OK (reportError() will print an error message to trace)
     */
    void testInitServicereportError1(void)
    {
        errlHndl_t  errl    = NULL;
        /**
         * @todo    use a separate instance here, not the singleton
         */
        INITSERVICE::InitService   &l_is = INITSERVICE::InitService::getTheInstance();

        TS_TRACE( "====> call reportError with NULL handle, should handle it OK\n  ");
        l_is.reportError( errl );

        // reportError() might crash, if it returns, just make sure it didn't modify
        //  the input pointer
        if ( errl != NULL)
        {
            TS_FAIL( "ERROR:  expected the NULL errlHndl_t to stay NULL\n");
        }
        else
        {
            TS_TRACE( "SUCCESS: reportError returned OK.");
        }

        return;
    }

    /**
     *  @brief  testInitServicereportError1
     *      This will call reportError with a good errorlog.
     *      on return, it should be NULLED out
     *      @todo can we check with the errorlogging facility to see if it got
     *      posted??
     */
    void testInitServicereportError2(void)
    {
        errlHndl_t  errl    = NULL;
        /**
         * @todo    use a separate instance here, not the singleton
         */
        INITSERVICE::InitService   &l_is = INITSERVICE::InitService::getTheInstance();

        errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                INITSERVICE::INIT_SVC_TEST5_ID,
                INITSERVICE::START_TASK_FAILED,
                0,
                0
        );

        TS_TRACE( "====> call reportError with good error handle, should commit and then delete\n  ");
        l_is.reportError( errl );
        if ( errl !=NULL )
        {
            TS_FAIL( "ERROR: reportError did not delete the errlHndl_t handle!\n" );
        }
        else
        {
            TS_TRACE( "SUCCESS: reportError returned OK.");
        }

        return;
    }

};  // class InitServiceTest


#endif  // __TEST_INIT_SERVICETEST_H

