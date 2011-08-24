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

#include <kernel/console.H>
#include <vfs/vfs.H>
#include <sys/task.h>
#include <sys/sync.h>
#include <sys/misc.h>
#include <sys/time.h>
#include <usr/cxxtest/TestSuite.H>

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <initservice/taskargs.H>       // task entry routine

#include "extinitsvc.H"
#include "extinitsvctasks.H"


namespace   INITSERVICE
{

extern  trace_desc_t *g_trac_initsvc;

/**
 * @brief   _start() - task entry point for this module
 *
 * @parms[in,out]   - pointer to TaskArgs struct
 *
 */
extern "C"
void _start( void *io_pArgs )
{
    TaskArgs::TaskArgs *pTaskArgs  =
            reinterpret_cast<TaskArgs::TaskArgs *>(io_pArgs);

    // initialize the extended modules in Hostboot.
    ExtInitSvc::getTheInstance().init( io_pArgs );

    if  ( pTaskArgs )
    {
        pTaskArgs->waitChildSync();
    }

    task_end();
}



/******************************************************************************/
// ExtInitSvc::getTheInstance return the only instance
/******************************************************************************/
ExtInitSvc& ExtInitSvc::getTheInstance()
{
    return Singleton<ExtInitSvc>::instance();
}

/******************************************************************************/
// ExtInitSvc::ExtInitSvc constructor
/******************************************************************************/
ExtInitSvc::ExtInitSvc()
{

}

/******************************************************************************/
// ExtInitSvc::~ExtInitSvc destructor
/******************************************************************************/
ExtInitSvc::~ExtInitSvc()
{

}


void ExtInitSvc::init( void *i_ptr )
{
    errlHndl_t      errl        =   NULL;   // steps will return an error handle if failure
    uint64_t        nextTask =   0;
    const TaskInfo  *ptask      =   NULL;
    TaskArgs::TaskArgs        args;

    TRACFCOMP( g_trac_initsvc,
            "Extended Initialization Service is starting." );

    //  ----------------------------------------------------------------
    //  loop through the task list and start up any tasks necessary
    //  ----------------------------------------------------------------
    for (   nextTask=0;
            nextTask<MAX_EXT_TASKS;
            nextTask++ )
    {
        //  make a local copy of the extended image task
        ptask    =   &(g_exttaskinfolist[nextTask]);
        if ( ptask->taskflags.task_type ==  END_TASK_LIST )
        {
            TRACDCOMP( g_trac_initsvc,
                    "End of ExtInitSvc task list." );
            break;
        }

        args.clear();                   // clear args for next task

        //  dispatch tasks...
        switch ( ptask->taskflags.task_type)
        {
        case    NONE:
            //  task is a place holder, skip
            TRACDBIN( g_trac_initsvc,
                    "task_type=NONE : ",
                    ptask->taskname,
                    strlen(ptask->taskname)    );
            break;
        case    INIT_TASK:
            TRACDBIN( g_trac_initsvc,
                    "task_type==INIT_TASK : ",
                    ptask->taskname,
                    strlen(ptask->taskname) );
            errl     = VFS::module_load( ptask->taskname );
            break;

        case    START_TASK:   //  call _init(), _start(), stay resident
            TRACDBIN( g_trac_initsvc,
                    "task_type=START_TASK : ",
                    ptask->taskname,
                    strlen(ptask->taskname)    );
            errl    =   InitService::getTheInstance().startTask(    ptask,
                                                                    &args );
            break;

        case    START_FN:
            TRACDCOMP( g_trac_initsvc,
                    "task_type==START_FN : %p",
                    ptask->taskfn );
            errl    =   InitService::getTheInstance().executeFn(    ptask,
                                                                    &args );
            // $$TODO
            break;
        case    BARRIER:
            TRACDCOMP( g_trac_initsvc,
                    "task_type==BARRIER" );
            // $$TODO
            break;

        case    UNINIT_TASK:
            TRACDBIN( g_trac_initsvc,
                    "task_type=UNINIT_TASK : ",
                    ptask->taskname,
                    strlen(ptask->taskname)    );
            errl    = VFS::module_unload( ptask->taskname );
            break;

        default:
            TRACDCOMP( g_trac_initsvc,
                    "Invalid task_type: %d",
                    ptask->taskflags.task_type );
            /*@     errorlog tag
             *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
             *  @moduleid       START_EXTINITSVC_ERRL_ID
             *  @reasoncode     INVALID_TASK_TYPE
             *  @userdata1      task_type value
             *  @userdata2      0
             *
             *  @devdesc        Extended Initialization Service found an invalid
             *                  Task Type in the task list.
             *                  The module id will identify the task.
             *                  task_type value will be the invalid type.
             */
            errl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                    START_EXTINITSVC_ERRL_ID,               //  moduleid
                    INVALID_TASK_TYPE,                      //  reason Code
                    0,                                      //  user1 = tidrc
                    0 );
            break;
        }   //  endswitch

        //  report an error
        InitService::getTheInstance().reportError( errl );

        if ( args.getReturnCode() != TASKARGS_UNDEFINED64 )
        {
            TRACFCOMP( g_trac_initsvc,
                    ERR_MRK "ExtInitSvc TaskArgs returned 0x%llx, errlog=%p",
                    args.getReturnCode(),
                    args.getErrorLog()
            );
        }

    }   // endfor


    TRACFCOMP( g_trac_initsvc,
            EXIT_MRK "ExtInitSvc finished.");

    //  =====================================================================
    //  -----   Unit Tests  -------------------------------------------------
    //  =====================================================================
    /**
     *  @note run all the unit tests after we finish the rest
     *      there are 2 images generated in the build:
     *      hbicore.bin         (HostBoot shippable image)
     *      hbicore_test.bin    (runs all unit tests)
     *      Only hbicore_test.bin has the libcxxtest.so module, so when
     *      we execute startTask() below on hbicore.bin, it will return -1,
     *      no module present.  This is OK.
     *
     */

    //  Pass it a set of args so we can wait on the barrier
    //  This is a bit wasteful since it is always allocated; we need a
    //  system call to check if a module exists.
    TaskArgs::TaskArgs  cxxtestargs;        //  create a new one for cxxtest
    cxxtestargs.clear();                    //  clear it

    TRACFCOMP( g_trac_initsvc,
                ENTER_MRK "    ");          // leave whitespace in trace
    TRACDBIN( g_trac_initsvc,
            ENTER_MRK "Run Unit Tests (if libcxxtests.so is present): ",
            CXXTEST_TASK.taskname,
            strlen(CXXTEST_TASK.taskname)    );

    errl = InitService::getTheInstance().startTask( &CXXTEST_TASK,
                                                    &cxxtestargs );

    // check the returncode and errorlog in the returned args
    if (    ( cxxtestargs.getReturnCode() != TASKARGS_UNDEFINED64 )
            || ( cxxtestargs.getErrorLog() != NULL )
    )
    {
        TRACFCOMP( g_trac_initsvc,
                ERR_MRK "CxxTests returned an error 0x%lx and an errorlog %p",
                cxxtestargs.getReturnCode(),
                cxxtestargs.getErrorLog()
        );
        //  report an error
        errlHndl_t  childerrl   =   cxxtestargs.getErrorLog();
        InitService::getTheInstance().reportError( childerrl );
    }

    TRACDCOMP( g_trac_initsvc,
            EXIT_MRK "Unit Tests finished.");
    TRACFCOMP( g_trac_initsvc,
                EXIT_MRK "    ");          // leave whitespace in trace

    // Shutdown all CPUs

    uint64_t l_shutdownStatus = SHUTDOWN_STATUS_GOOD;

    if (CxxTest::g_FailedTests)
    {
        l_shutdownStatus = SHUTDOWN_STATUS_UT_FAILED;
    }

    shutdown(l_shutdownStatus);

    // return to _start(), which may end the task or die.
    return;
}


}   // namespace
