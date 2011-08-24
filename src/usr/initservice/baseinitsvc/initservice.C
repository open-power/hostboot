//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/baseinitsvc/initservice.C $
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
 * @file    initservice.C
 *
 *  Implements Initialization Service for Host boot.
 *  See initservice.H for details
 *
 */

#include <kernel/console.H>
#include <sys/vfs.h>
#include <vfs/vfs.H>
#include <sys/task.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <sys/sync.h>


#include "initservice.H"
#include "initsvctasks.H"



namespace   INITSERVICE
{

trace_desc_t *g_trac_initsvc = NULL;
TRAC_INIT(&g_trac_initsvc, "INITSERVICE", 4096);


/******************************************************************************/
// InitService::getTheInstance return the only instance
/******************************************************************************/
InitService& InitService::getTheInstance()
{
    return Singleton<InitService>::instance();
}

/******************************************************************************/
// InitService::Initservice constructor
/******************************************************************************/
InitService::InitService()
{

}

/******************************************************************************/
// InitService::~InitService destructor
/******************************************************************************/
InitService::~InitService()
{

}


errlHndl_t  InitService::startTask( const TaskInfo      *i_ptask,
                                    TaskArgs::TaskArgs  *io_pargs ) const
{
    tid_t       tidrc   =   0;
    errlHndl_t  lo_errl =   NULL;

    assert(i_ptask->taskflags.task_type == START_TASK);

    // Base modules have already been loaded and initialized,
    // extended modules have not.
    if(i_ptask->taskflags.module_type == EXT_IMAGE)
    {
        // load module and call _init()
        lo_errl = VFS::module_load( i_ptask->taskname );
    }

    if( !lo_errl)
    {
        tidrc   =   task_exec( i_ptask->taskname, io_pargs );   // launch the child

        if ( static_cast<int16_t>(tidrc) < 0 )
        {
            // task failed to launch, post an errorlog and dump some trace
            /*@     errorlog tag
             *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
             *  @moduleid       see task list
             *  @reasoncode     START_TASK_FAILED
             *  @userdata1      task id or task return code
             *  @userdata2      0
             *
             *  @devdesc        Initialization Service failed to start a task.
             *                  The module id will identify the task.
             *
             */
            lo_errl = new ERRORLOG::ErrlEntry(
                                              ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                                              i_ptask->taskflags.module_id,            //  moduleid
                                              INITSERVICE::START_TASK_FAILED,         //  reason Code
                                              tidrc,                                  //  user1 = tidrc
                                              0
                                             );
            TRACDBIN( g_trac_initsvc,
                      "ERROR starting task:",
                      i_ptask->taskname,
                      strlen(i_ptask->taskname) );
            TRACDCOMP( g_trac_initsvc,
                       "tidrc=%d, errlog p = %p" ,
                       (int16_t)tidrc, lo_errl );

        }  // endif tidrc
        else
        {
            // task launched OK.
            TRACDBIN( g_trac_initsvc,
                      "Task finished OK :",
                      i_ptask->taskname,
                      strlen(i_ptask->taskname) );
            TRACDCOMP( g_trac_initsvc,
                       "task number %d,  errlog p = %p",
                       tidrc, lo_errl );

            if ( io_pargs )
            {
                io_pargs->waitParentSync();                      // sync up childtask
            }
        }
    }
    // else module load failed. have error log

    return lo_errl;
}


errlHndl_t InitService::executeFn(  const TaskInfo  *i_ptask,
                                    TaskArgs *io_pargs ) const
{
    tid_t       tidrc   =   0;
    errlHndl_t  lo_errl    =   NULL;

    if ( i_ptask->taskfn == NULL )
    {
        TRACDBIN( g_trac_initsvc,
                "ERROR: NULL function pointer:",
                i_ptask->taskname,
                strlen(i_ptask->taskname) );
        /*@     errorlog tag
         *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
         *  @moduleid       see task list
         *  @reasoncode     NULL_FN_PTR
         *  @userdata1      0
         *  @userdata2      0
         *
         *  @devdesc        Initialization Service attempted to start a
         *                  function within a module but found a NULL pointer
         *                  instead of the function.
         *                  The module id will identify the task.
         */
        lo_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                i_ptask->taskflags.module_id,           //  moduleid
                INITSERVICE::NULL_FN_PTR,               //  reason Code
                0,
                0   );

        // fall through to end and return bad error log
    }
    else
    {
        //  valid function, launch it
        tidrc   =   task_create(    i_ptask->taskfn, io_pargs );
        if ( static_cast<int16_t>(tidrc) < 0 )
        {
            /*@     errorlog tag
             *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
             *  @moduleid       see task list
             *  @reasoncode     NULL_FN_PTR
             *  @userdata1      0
             *  @userdata2      0
             *
             *  @devdesc        Initialization Service attempted to start a
             *                  function within a module but the function
             *                  failed to launch
             *                  The module id will identify the task.
             */
            lo_errl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                    i_ptask->taskflags.module_id,           //  moduleid
                    INITSERVICE::START_FN_FAILED,           //  reason Code
                    tidrc,                                  //  user1 = tidrc
                    0   );

            TRACDBIN( g_trac_initsvc,
                    ENTER_MRK "ERROR starting function:",
                    i_ptask->taskname,
                    strlen(i_ptask->taskname) );
            TRACDCOMP( g_trac_initsvc,
                    EXIT_MRK "tidrc=%d, errlog p = %p" ,
                    (int16_t)tidrc, lo_errl );

        }  // endif tidrc
        else
        {
            TRACDBIN( g_trac_initsvc,
                    ENTER_MRK "function launched OK :",
                    i_ptask->taskname,
                    strlen(i_ptask->taskname) );
            TRACDCOMP( g_trac_initsvc,
                    EXIT_MRK "task number %d,  errlog p = %p",
                    tidrc, lo_errl );

            // task launched OK.
            if ( io_pargs )
            {
                io_pargs->waitParentSync();                 // sync up parent task
            }
        }

    }   // end else


    return lo_errl;
}


void    InitService::reportError(errlHndl_t &io_rerrl ) const
{

    if ( io_rerrl == NULL )
    {
        //  this is OK, do nothing
    }
    else
    {

        TRACDCOMP( g_trac_initsvc,
                "Committing the error log %p.",
                io_rerrl );

        errlCommit( io_rerrl );

    }

}


/**
 * @todo    this will make a system call to post the error code.
 */
void    InitService::setProgressCode( uint64_t  i_progresscode ) const
{

    // do nothing for now
}


/**
 * @note    For task_type = NONE case, I'm assuming that trace will not crash
 *          if we have a NULL taskname string, printing it is useful for debug.
 */
void    InitService::init( void *i_ptr )
{
    errlHndl_t          errl        =   NULL;   // steps will return an error handle if failure
    uint64_t            nextTask    =   0;
    const TaskInfo      *ptask      =   NULL;
    TaskArgs::TaskArgs  args;

    TRACFCOMP( g_trac_initsvc,
            ENTER_MRK "Initialization Service is starting." );

    //  ----------------------------------------------------------------
    //  loop through the task list and start up any tasks necessary
    //  ----------------------------------------------------------------

    for (   nextTask=0;
            nextTask<INITSERVICE::MAX_TASKS;
            nextTask++ )
    {
        //  make a local copy of the base image task
        ptask    =   &(g_taskinfolist[nextTask]);
        if ( ptask->taskflags.task_type ==  END_TASK_LIST )
        {
            TRACDCOMP( g_trac_initsvc,
                    "End of Initialization Service task list.\n" );
            break;
        }

        args.clear();               // clear args struct for next task

        //  dispatch tasks...
        switch ( ptask->taskflags.task_type)
        {
        case    NONE:
            //  task is a place holder, skip
            TRACDBIN( g_trac_initsvc,
                    "task_type==NONE",
                    ptask->taskname,
                    strlen( ptask->taskname)   );
            break;
        case    START_TASK:
            TRACDBIN( g_trac_initsvc,
                    "task_type==START_TASK",
                    ptask->taskname,
                    strlen( ptask->taskname)   );
            errl    =   startTask(  ptask,          // task struct
                    &args );        //  args
            break;
        case    START_FN:
            TRACDCOMP( g_trac_initsvc,
                    "task_type==START_FN : %p",
                    ptask->taskfn );
            errl    =   executeFn(  ptask,
                    &args );
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
                    "Invalid task_type %d: ",
                    ptask->taskflags.task_type );
            /*@     errorlog tag
             *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
             *  @moduleid       BASE_INITSVC_ERRL_ID
             *  @reasoncode     INVALID_TASK_TYPE
             *  @userdata1      task_type value
             *  @userdata2      0
             *
             *  @devdesc        Initialization Service found an invalid
             *                  Task Type in the task list.
             *                  The module id will identify the task.
             *                  task_type value will be the invalid type.
             */
            errl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                    BASE_INITSVC_ERRL_ID,                   //  moduleid
                    INVALID_TASK_TYPE,                      //  reason Code
                    ptask->taskflags.task_type,
                    0 );
            break;

        }   //  endswitch

        //  report an error
        reportError( errl );

        if ( args.getReturnCode() != TASKARGS_UNDEFINED64 )
        {
            TRACFCOMP( g_trac_initsvc,
                    ERR_MRK "InitService TaskArgs returned 0x%llx, errlog=%p",
                    args.getReturnCode(),
                    args.getErrorLog()
            );

            errlHndl_t   childerrl = args.getErrorLog();     // local copy
            reportError( childerrl );                       // report child error
        }



    }   // endfor

    //  die if we drop out with an error
    assert( errl == NULL);


    TRACFCOMP( g_trac_initsvc,
            EXIT_MRK "Initilization Service finished.");

    // return to _start(), which may end the task or die.
}


}   // namespace
