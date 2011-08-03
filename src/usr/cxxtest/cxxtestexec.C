/****************************************************************************
 * $IBMCopyrightBlock:
 * 
 *  IBM Confidential
 * 
 *  Licensed Internal Code Source Materials
 * 
 *  IBM HostBoot Licensed Internal Code
 * 
 *  (C) Copyright IBM Corp. 2011
 * 
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 * $
****************************************************************************/

#include <sys/vfs.h>
#include <sys/task.h>
#include <string.h>
#include <kernel/console.H>
#include <sys/time.h>
#include <sys/sync.h>

#include <initservice/taskargs.H>
#include <cxxtest/TestSuite.H>

namespace CxxTest
{
    uint64_t    g_ModulesStarted    =   0;
    uint64_t    g_ModulesCompleted  =   0;

    /**
     * @var g_CxxTestBarrier    -   barrier for CxxTest modules.
     *  all test modules will wait on this barrier before returning to the caller
     *  in cxxtest/cxxtestexec.C .
     */
    barrier_t       g_CxxTestBarrier;

}   //  namespace

using namespace INITSERVICE;

trace_desc_t *g_trac_cxxtest = NULL;
TRAC_INIT(&g_trac_cxxtest, "CXXTEST", 1024 );


/**
 *  @brief _start() for CxxTest
 *  Iterate through all modules in the VFS named "libtest*" and create
 *  children tasks to execute them.
 *
 * * @parms[in,out]   - pointer to TaskArgs struct
 *
 */
extern "C"
void _start(void *io_pArgs)
{
    VfsSystemModule* vfsItr     =   &VFS_MODULES[0];
    tid_t       tidrc           =   0;
    uint64_t    totalmodules    =   0;
    TaskArgs::TaskArgs *pTaskArgs  =
            reinterpret_cast<TaskArgs::TaskArgs *>(io_pArgs);


    // count up the number of viable modules ahead of time
    TRACDCOMP( g_trac_cxxtest, "Counting CxxTextExec modules:" );

    while(vfsItr->module[0] != '\0')
    {
        if (0 == memcmp(vfsItr->module, "libtest", 7))
        {
            if (NULL != vfsItr->start)
            {
                TRACDBIN( g_trac_cxxtest,
                        "",
                        &(vfsItr->module[0]),
                        strlen( &(vfsItr->module[0]) )
                        );

                totalmodules++;
            }
        }
        vfsItr++;
    }

    //  start executing the CxxTest modules
    TRACDCOMP( g_trac_cxxtest, ENTER_MRK "Execute CxxTestExec, totalmodules=%d.",
            totalmodules);
    vfsItr     =   &VFS_MODULES[0];             //  re-init

    // set barrier for all the modules being started, plus this module
    barrier_init( &CxxTest::g_CxxTestBarrier, totalmodules+1 );

    __sync_add_and_fetch(&CxxTest::g_ModulesStarted, 1);

    while(vfsItr->module[0] != '\0')
    {
        if (0 == memcmp(vfsItr->module, "libtest", 7))
        {
            if (NULL != vfsItr->start)
            {
                __sync_add_and_fetch(&CxxTest::g_ModulesStarted, 1);

#if 0
                // arrgh, no %s in trace
                TRACDCOMP( g_trac_cxxtest,
                        "Running %s, ModulesStarted=%d",
                        __LINE__,
                        vfsItr->module,
                        CxxTest::g_ModulesStarted );
#else
                TRACDCOMP( g_trac_cxxtest,
                        "ModulesStarted=%d",
                        CxxTest::g_ModulesStarted );
#endif
                tidrc = task_exec( vfsItr->module, NULL );
                TRACDCOMP( g_trac_cxxtest, "Launched task: tidrc=%d",
                        tidrc );

            }
        }
        vfsItr++;
    }

    TRACDCOMP( g_trac_cxxtest,  "Waiting for all tasks to finish....");
    //  wait for all the launched tasks to finish
    barrier_wait( &CxxTest::g_CxxTestBarrier );

    __sync_add_and_fetch(&CxxTest::g_ModulesCompleted, 1);
    TRACDCOMP( g_trac_cxxtest, " ModulesCompleted=%d",
            CxxTest::g_ModulesCompleted );

    TRACDCOMP( g_trac_cxxtest, EXIT_MRK "Finished CxxTestExec: ");
    TRACDCOMP( g_trac_cxxtest, "    total tests:   %d",
            CxxTest::g_TotalTests  );
    TRACDCOMP( g_trac_cxxtest, "    failed tests:  %d",
            CxxTest::g_FailedTests );
    TRACDCOMP( g_trac_cxxtest, "    warnings:      %d",
            CxxTest::g_Warnings    );
    TRACDCOMP( g_trac_cxxtest, "    trace calls:   %d",
            CxxTest::g_TraceCalls  );


    // wait for TaskArgs barrier
    if  ( pTaskArgs )
    {
        pTaskArgs->waitChildSync();
    }

    task_end();
}
