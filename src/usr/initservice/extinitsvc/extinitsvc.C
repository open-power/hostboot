/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/extinitsvc/extinitsvc.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
 * @file    extinitsvc.C
 *
 *  Implements Initialization Service for Host boot in the extended image.
 *  See extinitsvc.H for details
 *
 */

#include    <kernel/console.H>              //  printk status

#include    <vfs/vfs.H>
#include    <sys/task.h>
#include    <sys/sync.h>
#include    <sys/misc.h>
#include    <sys/time.h>
#include    <usr/cxxtest/TestSuite.H>
#include    <arch/magic.H>

#include    <trace/interface.H>
#include    <errl/errlentry.H>
#include    <initservice/taskargs.H>       // task entry macro

#include    "extinitsvc.H"
#include    "extinitsvctasks.H"


namespace   INITSERVICE
{

extern  trace_desc_t *g_trac_initsvc;

/**
 *      _start() task entry procedure using the macro in taskargs.H
 */
TASK_ENTRY_MACRO( ExtInitSvc::getTheInstance().init );


void ExtInitSvc::init( errlHndl_t   &io_rtaskRetErrl )
{
    errlHndl_t          l_errl      =   NULL;
    uint64_t            l_task      =   0;
    const TaskInfo      *l_ptask    =   NULL;

    printk( "ExtInitSvc entry.\n" );

    TRACFCOMP( g_trac_initsvc,
            "Extended Initialization Service is starting." );

    //  ----------------------------------------------------------------
    //  loop through the task list and start up any tasks necessary
    //  ----------------------------------------------------------------
    for (   l_task=0;
            l_task < ( sizeof(g_exttaskinfolist)/sizeof(TaskInfo) ) ;
            l_task++ )
    {
        //  make a local copy of the extended image task
        l_ptask    =   &(g_exttaskinfolist[l_task]);
        if ( l_ptask->taskflags.task_type ==  END_TASK_LIST )
        {
            TRACDCOMP( g_trac_initsvc,
                    "End of ExtInitSvc task list." );
            break;
        }

        //  dispatch the task
        l_errl  =   InitService::getTheInstance().dispatchTask( l_ptask,
                                                                NULL  );

        //  process errorlogs returned from the task that was launched
        if ( l_errl )
        {
            TRACFCOMP( g_trac_initsvc,
                    "ERROR: task %s returned errlog=%p",
                    l_ptask->taskname,
                    l_errl );
            //  break out of loop with error.
            break;
        }
    }   // endfor

    //  die if we drop out with an error
    if ( l_errl )
    {
        //  pass the errorlog to initservice to be committed.
        //  initservice should do the shutdown.
        TRACFCOMP( g_trac_initsvc,
                "ExtInitSvc: ERROR: return to initsvc with errlog %p",
                l_errl );

        io_rtaskRetErrl=l_errl;
        return;
    }

    //  finish things up, return to initservice with goodness.
    TRACFCOMP( g_trac_initsvc,
            "ExtInitSvc finished OK, return to initsvc with NULL.");

    printk( "ExtInitSvc exit.\n" );

    io_rtaskRetErrl=NULL;
}


ExtInitSvc& ExtInitSvc::getTheInstance()
{
    return Singleton<ExtInitSvc>::instance();
}


ExtInitSvc::ExtInitSvc()
{ }


ExtInitSvc::~ExtInitSvc()
{ }


//
// Execute CXX Unit Tests
// NOTE: This should be done right before doShutDown is called.
//
errlHndl_t executeUnitTests ( void )
{
    return Singleton<ExtInitSvc>::instance().executeUnitTests();
}

errlHndl_t ExtInitSvc::executeUnitTests ( void )
{
    errlHndl_t err = nullptr;

    TRACDCOMP( g_trac_initsvc,
               ENTER_MRK"executeUnitTests()" );
    MAGIC_INST_PRINT_ISTEP(99,1);

    do
    {
        //  ---------------------------------------------------------------------
        //  -----   Unit Tests  -------------------------------------------------
        //  ---------------------------------------------------------------------
        /**
         *  @note run all of the unit tests after we finish the rest
         *      There are 2 images generated in the build:
         *      hbicore.bin         (HostBoot shippable image)
         *      hbicore_test.bin    (runs all unit tests)
         *      Only hbicore_test.bin has the libcxxtest.so module, so that's
         *      how we test whether to run this.
         */
        // If the test task does not exist then don't run it.
        if ( VFS::module_exists( cxxTestTask.taskname ) )
        {
            printk( "CxxTest entry.\n" );

            //  Pass it a set of args so we can wait on the barrier
            errlHndl_t l_cxxerrl = nullptr;
            const INITSERVICE::TaskInfo *l_pcxxtask = &cxxTestTask;

            TRACFCOMP( g_trac_initsvc,
                       "Run CxxTest Unit Tests: %s",
                       l_pcxxtask->taskname );

            INITSERVICE::InitService &is
                = INITSERVICE::InitService::getTheInstance();
            l_cxxerrl = is.startTask( l_pcxxtask,
                                      nullptr );

            // process any errorlogs from cxxtestexec (not sure there are any...)
            if ( l_cxxerrl )
            {
                //  end the task and pass the errorlog to initservice to be
                //  committed.  initservice should do the shutdown.
                TRACFCOMP( g_trac_initsvc,
                           "CxxTest: ERROR: return to host_start_payload istep "
                           "with errlog 0x%X",
                           l_cxxerrl->plid() );

                err = l_cxxerrl;
                break;
            }   // endif l_cxxerrl


            //  make up and post an errorlog if any tests failed.
            if ( CxxTest::g_FailedTests )
            {
                // some unit tests failed, post an errorlog
                /*@     errorlog tag
                 *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                 *  @moduleid       CXXTEST_MOD_ID
                 *  @reasoncode     CXXTEST_FAILED_TEST
                 *  @userdata1      number of failed tests
                 *  @userdata2      <UNUSED>
                 *  @devdesc        One or more CxxTest Unit Tests failed.
                 */
                l_cxxerrl = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                        INITSERVICE::CXXTEST_MOD_ID,
                                        INITSERVICE::CXXTEST_FAILED_TEST,
                                        CxxTest::g_FailedTests,
                                        0 );

                TRACFCOMP( g_trac_initsvc,
                           "CxxTest ERROR:  %d failed tests, build errlog 0x%X.",
                           CxxTest::g_FailedTests,
                           l_cxxerrl->plid() );

                //  end the task and pass the errorlog to initservice to be
                //  committed.  initservice should do the shutdown.
                TRACFCOMP( g_trac_initsvc,
                           "CxxTest: return to host_start_payload with errlog!" );

                err = l_cxxerrl;
                break;
            }   // endif g_FailedTest

            printk( "CxxTest exit.\n" );
        }   // endif cxxtest module exists.
    } while( 0 );

    TRACDCOMP( g_trac_initsvc,
               EXIT_MRK"executeUnitTests()" );

    return err;
}

}   // namespace
