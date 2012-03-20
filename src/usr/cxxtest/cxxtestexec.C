//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/cxxtest/cxxtestexec.C $
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

#include <vfs/vfs.H>
#include <sys/task.h>
#include <string.h>
#include <kernel/console.H>
#include <sys/time.h>
#include <sys/sync.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#
#include <initservice/taskargs.H>
#include <cxxtest/TestSuite.H>

namespace CxxTest
{
    extern uint64_t    g_ModulesStarted;
    extern uint64_t    g_ModulesCompleted;

}   //  namespace

// prototype
void    cxxinit( errlHndl_t    &io_taskRetErrl );


trace_desc_t *g_trac_cxxtest = NULL;
TRAC_INIT(&g_trac_cxxtest, CXXTEST_COMP_NAME, 1024 );


/**
 * _start entry point for this task.
 */
TASK_ENTRY_MACRO( cxxinit );


/**
 *  @brief init() for CxxTest
 *  Iterate through all modules in the VFS named "libtest*" and create
 *  children tasks to execute them.
 *
 * * @parms[in,out]   - pointer to any args
 *
 */

void    cxxinit( errlHndl_t    &io_taskRetErrl )
{
    errlHndl_t  l_errl  =   NULL;
    std::vector<const char *> module_list;
    std::vector<tid_t> tasks;
    tid_t       tidrc           =   0;

    // output a blank line so that it's easier to find the beginning of
    //  CxxTest
    TRACDCOMP( g_trac_cxxtest, " ");
    TRACDCOMP( g_trac_cxxtest, " ");

    // count up the number of viable modules ahead of time
    TRACDCOMP( g_trac_cxxtest, "Counting CxxTestExec modules:" );

    VFS::find_test_modules(module_list);

    //  start executing the CxxTest modules

    TRACDCOMP( g_trac_cxxtest, ENTER_MRK "Execute CxxTestExec, totalmodules=%d.",
            module_list.size());
    printkd( "\n Begin CxxTest...\n");

    __sync_add_and_fetch(&CxxTest::g_ModulesStarted, 1);

    for(std::vector<const char *>::const_iterator i = module_list.begin();
        i != module_list.end(); ++i)
    {
        __sync_add_and_fetch(&CxxTest::g_ModulesStarted, 1);

        TRACDCOMP( g_trac_cxxtest,
                   "ModulesStarted=%d",
                   CxxTest::g_ModulesStarted );

        // load module and call _init()
        l_errl = VFS::module_load( *i );
        if ( l_errl )
        {
            // vfs could not load a module and returned an errorlog.
            //  commit the errorlog, mark the test failed, and
            //  move on.
            TS_FAIL( "ERROR: Task %s could not be loaded, committing errorlog",
                    *i );
            errlCommit( l_errl, CXXTEST_COMP_ID );
            continue;
        }

        tidrc = task_exec( *i, NULL );
        TRACDCOMP( g_trac_cxxtest, "Launched task: %s tidrc=%d",
                   *i, tidrc );
        tasks.push_back(tidrc);
    }

    TRACFCOMP( g_trac_cxxtest,  "Waiting for all tasks to finish....");

    //  wait for all the launched tasks to finish
    for (std::vector<tid_t>::iterator t = tasks.begin();
         t != tasks.end();
         ++t)
    {
        int status = 0;
        task_wait_tid(*t, &status, NULL);

        if (status != TASK_STATUS_EXITED_CLEAN)
        {
            TRACFCOMP( g_trac_cxxtest, "Task %d crashed.", *t );
            __sync_add_and_fetch(&CxxTest::g_FailedTests, 1);
        }
    }

    __sync_add_and_fetch(&CxxTest::g_ModulesCompleted, 1);
    TRACFCOMP( g_trac_cxxtest, " ModulesCompleted=%d",
            CxxTest::g_ModulesCompleted );

    TRACFCOMP( g_trac_cxxtest, EXIT_MRK "Finished CxxTestExec: ");
    TRACFCOMP( g_trac_cxxtest, "    total tests:   %d",
            CxxTest::g_TotalTests  );
    TRACFCOMP( g_trac_cxxtest, "    failed tests:  %d",
            CxxTest::g_FailedTests );
    TRACFCOMP( g_trac_cxxtest, "    warnings:      %d",
            CxxTest::g_Warnings    );
    TRACFCOMP( g_trac_cxxtest, "    trace calls:   %d",
            CxxTest::g_TraceCalls  );

    //  @todo dump out an informational errorlog??

    // should always return NULL
    task_end2( l_errl );
}
