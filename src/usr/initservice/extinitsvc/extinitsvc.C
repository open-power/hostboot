//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/extinitsvc/extinitsvc.C $
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
 * @file    extinitsvc.C
 *
 *  Implements Initialization Service for Host boot in the extended image.
 *  See extinitsvc.H for details
 *
 */

#include    <kernel/console.H>
#include    <vfs/vfs.H>
#include    <sys/task.h>
#include    <sys/sync.h>
#include    <sys/misc.h>
#include    <sys/time.h>
#include    <usr/cxxtest/TestSuite.H>

#include    <trace/interface.H>
#include    <errl/errlentry.H>
#include    <initservice/taskargs.H>       // task entry routine

#include    "extinitsvc.H"
#include    "extinitsvctasks.H"


namespace   INITSERVICE
{

extern  trace_desc_t *g_trac_initsvc;


/**
 * @brief   set up _start() task entry procedure using the macro in taskargs.H
 */
TASK_ENTRY_MACRO( ExtInitSvc::getTheInstance().init );


void ExtInitSvc::init( void *io_ptr )
{
    errlHndl_t          l_errl      =   NULL;
    uint64_t            l_task      =   0;
    const TaskInfo      *l_ptask    =   NULL;
    TaskArgs::TaskArgs  l_args;
    uint64_t            l_childrc   =   0;
    //  set up pointer to our taskargs
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_ptr );

    TRACFCOMP( g_trac_initsvc,
            "Extended Initialization Service is starting." );

    //  ----------------------------------------------------------------
    //  loop through the task list and start up any tasks necessary
    //  ----------------------------------------------------------------
    for (   l_task=0;
            l_task<INITSERVICE::MAX_EXT_TASKS;
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

        l_args.clear();

        //  dispatch the task
        l_errl  =   InitService::getTheInstance().dispatchTask( l_ptask,
                                                                &l_args  );

        //  process errorlogs returned from the task that was launched
        if ( l_errl )
        {
            TRACFCOMP( g_trac_initsvc,
                    "ERROR: dispatching task, errlog=0x%p",
                    l_errl );
            //  break out of loop with error.
            break;
        }

        //  make local copies of the values in TaskArgs that are returned from
        //  the child.
        //  this also clears the errorlog from the TaskArgs struct, so
        //  use it or lose it ( see taskargs.H for details ).
        l_childrc   =   l_args.getReturnCode();
        l_errl      =   l_args.getErrorLog();

        if  ( l_errl )
        {
            TRACFCOMP( g_trac_initsvc,
                    " Child task %s returned 0x%llx, errlog=0x%p",
                    l_ptask->taskname,
                    l_childrc,
                    l_errl );
            //  break out of loop with error
            break;
        }
        else
        {
            //  Check child results for a valid nonzero return code.
            //  If we have one, and no errorlog, then we create and
            //  post our own errorlog here.
            if ( l_childrc != 0 )
            {
                TRACFCOMP( g_trac_initsvc,
                        "EIS: Child task %s returned 0x%llx, no errlog",
                        l_ptask->taskname,
                        l_childrc );

                /*@     errorlog tag
                 *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                 *  @moduleid       EXTINITSVC_TASK_RETURNED_ERROR_ID
                 *  @reasoncode     EXTINITSVC_FAILED_NO_ERRLOG
                 *  @userdata1      returncode from task
                 *  @userdata2      0
                 *
                 *  @devdesc        The task returned with an error,
                 *                  but there was no errorlog returned.
                 *
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                        EXTINITSVC_TASK_RETURNED_ERROR_ID,
                        INITSERVICE::EXTINITSVC_FAILED_NO_ERRLOG,
                        l_childrc,
                        0 );

                // break out of loop with error
                break;
            }   // end if
        }   //  end else
    }   // endfor

    //  die if we drop out with an error
    if ( l_errl )
    {
        //  dropped out of loop with error.
        //  Commit the log first, then stop right here.
        TRACFCOMP( g_trac_initsvc,
                "ExtInitSvc: Committing errorlog..." );
        errlCommit( l_errl, INITSVC_COMP_ID );

        //  pass an error code to initsvc that we are shutting down.
        pTaskArgs->postReturnCode( TASKARGS_SHUTDOWN_RC );
        //Tell initservice to perform shutdown sequence
        InitService::getTheInstance().doShutdown(
                                      SHUTDOWN_STATUS_EXTINITSVC_FAILED);
    }

    TRACFCOMP( g_trac_initsvc,
            EXIT_MRK "ExtInitSvc finished.");

    //  Test if the child posted an errorcode.  If so, don't
    //  bother to run the unit tests.
    if ( pTaskArgs->getReturnCode() == 0 )
    {
        //  =====================================================================
        //  -----   Unit Tests  -------------------------------------------------
        //  =====================================================================
        /**
         *  @note run all of the unit tests after we finish the rest
         *      There are 2 images generated in the build:
         *      hbicore.bin         (HostBoot shippable image)
         *      hbicore_test.bin    (runs all unit tests)
         *      Only hbicore_test.bin has the libcxxtest.so module, so when
         *      we execute startTask() below on hbicore.bin, it will return -ENOENT,
         *      no module present.  This is OK.
         *
         *  @todo can we call call module_load() to see if libcxxtest.so exists?
         *          ask Doug or Patrick
         *
         */

        //  add a do-while loop so there is only one return at the bottom....
        do
        {
            //  Pass it a set of args so we can wait on the barrier
            errlHndl_t          l_cxxerrl       =   NULL;
            TaskArgs::TaskArgs  l_cxxtestargs;
            const TaskInfo      *l_pcxxtask     =   &CXXTEST_TASK;
            uint64_t            l_cxxchildrc    =   0;
            errlHndl_t          l_cxxchilderrl  =   NULL;

            l_cxxtestargs.clear();

            TRACDCOMP( g_trac_initsvc,
                    ENTER_MRK "Run Unit Tests (if libcxxtests.so is present): %s",
                    l_pcxxtask->taskname );

            // If the test task does not exist then don't run it.
            if(!VFS::module_exists(l_pcxxtask->taskname)) break;

            l_cxxerrl = InitService::getTheInstance().startTask( l_pcxxtask,
                    &l_cxxtestargs );

            //  process errorlogs returned from the task that was launched
            //  @TODO   if we are running the non-test version of HostBoot, this
            //          will always post an extra errorlog.  We need a way to know
            //          if we are running the _test version or not.
            if ( l_cxxerrl )
            {
                TRACFCOMP( g_trac_initsvc,
                        "Committing error from cxxtask launch" );
                errlCommit( l_cxxerrl, INITSVC_COMP_ID );
                break;      // ERROR, break out of do-while.
            }

            //  make local copies of the values in TaskArgs that are returned from
            //  the child.
            //  this also clears the errorlog from the TaskArgs struct, so
            //  use it or lose it ( see taskargs.H for details ).
            l_cxxchildrc    =   l_cxxtestargs.getReturnCode();
            l_cxxchilderrl  =   l_cxxtestargs.getErrorLog();

            if  ( l_cxxchilderrl )
            {
                TRACFCOMP( g_trac_initsvc,
                        " Child task returned 0x%llx, errlog=0x%p",
                        l_cxxchildrc,
                        l_cxxchilderrl );
                errlCommit( l_cxxchilderrl, INITSVC_COMP_ID );
            }
            else
            {
                //  Check child results for a valid nonzero return code.
                //  If we have one, and no errorlog, then we create and
                //  post our own errorlog here.
                if (  l_cxxchildrc != 0 )
                {
                    TRACFCOMP( g_trac_initsvc,
                            "Child task returned 0x%llx, no errlog",
                            l_cxxchildrc );

                    /*@     errorlog tag
                     *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                     *  @moduleid       CXXTEST_TASK_RETURNED_ERROR_ID
                     *  @reasoncode     CXXTEST_FAILED_NO_ERRLOG
                     *  @userdata1      returncode from istep
                     *  @userdata2      0
                     *
                     *  @devdesc        The unit test dispatcher returned with an
                     *                  error, but there was no errorlog returned.
                     */
                    l_cxxerrl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                            CXXTEST_TASK_RETURNED_ERROR_ID,
                            INITSERVICE::CXXTEST_FAILED_NO_ERRLOG,
                            l_cxxchildrc,
                            0 );
                    errlCommit( l_cxxerrl, INITSVC_COMP_ID );

                }   // end if
            }   //  end else

        }   while(0);   //  end do-while

    }


    //  =====================================================================
    //  -----   Shutdown all CPUs   -----------------------------------------
    //  =====================================================================
    TRACFCOMP( g_trac_initsvc,
            EXIT_MRK "CxxTests finished.");

    uint64_t l_shutdownStatus = SHUTDOWN_STATUS_GOOD;

    if (CxxTest::g_FailedTests)
    {
        l_shutdownStatus = SHUTDOWN_STATUS_UT_FAILED;
    }

    //Tell initservice to perform shutdown sequence
    InitService::getTheInstance().doShutdown(l_shutdownStatus);

    // return to _start(), which may end the task or die.
    return;
}


ExtInitSvc& ExtInitSvc::getTheInstance()
{
    return Singleton<ExtInitSvc>::instance();
}


ExtInitSvc::ExtInitSvc()
{ }


ExtInitSvc::~ExtInitSvc()
{ }


}   // namespace
