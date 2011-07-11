/**
 * @file    initservice.C
 *
 *  Implements Initialization Service for Host boot.
 *  See initservice.H for details
 *
 */

#include <kernel/console.H>
#include <sys/vfs.h>
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

/**
 * @todo    mechanism to set taskcommand in TaskArgs struct
 * @todo    check taskreturncode inside of TaskArgs
 * @todo    test errorlog inside of Taskargs
 */
errlHndl_t  InitService::startTask( const TaskInfo      *i_ptask,
                                    TaskArgs::TaskArgs  *io_pargs,
                                    errlHndl_t          &io_rerrl ) const
{
    tid_t   tidrc   =   0;

    assert(i_ptask->taskflags.task_type == START_TASK);

    tidrc   =   task_exec( i_ptask->taskname, io_pargs );   // launch the child
    if ( static_cast<int16_t>(tidrc) < 0 )
    {
        // task failed to launch, post an errorlog and dump some trace
        io_rerrl = new ERRORLOG::ErrlEntry(
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
                (int16_t)tidrc, io_rerrl );

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
                tidrc, io_rerrl );

        if ( io_pargs )
        {
            io_pargs->waitParentSync();                      // sync up childtask
        }
    
	}

    return io_rerrl;
}


errlHndl_t InitService::executeFn(  const TaskInfo  *i_ptask,
        TaskArgs *io_pargs
) const
{
    tid_t       tidrc   =   0;
    errlHndl_t  errl    =   NULL;

    if ( i_ptask->taskfn == NULL )
    {
        TRACDBIN( g_trac_initsvc,
                "ERROR: NULL function pointer:",
                i_ptask->taskname,
                strlen(i_ptask->taskname) );

        errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                i_ptask->taskflags.module_id,           //  moduleid
                INITSERVICE::NULL_FN_PTR,               //  reason Code
                0,
                0   );

        return  errl;
    }


    //  valid function, launch it
    tidrc   =   task_create(    i_ptask->taskfn, io_pargs );
    if ( static_cast<int16_t>(tidrc) < 0 )
    {
        errl = new ERRORLOG::ErrlEntry(
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
                (int16_t)tidrc, errl );

    }  // endif tidrc
    else
    {
        TRACDBIN( g_trac_initsvc,
                ENTER_MRK "function launched OK :",
                i_ptask->taskname,
                strlen(i_ptask->taskname) );
        TRACDCOMP( g_trac_initsvc,
                EXIT_MRK "task number %d,  errlog p = %p",
                tidrc, errl );

        // task launched OK.
        if ( io_pargs )
        {
            io_pargs->waitParentSync();                 // sync up parent task
        }
    }

    return errl;

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
                io_rerrl
        );

        errlCommit( io_rerrl );

    }

    return;
}


/**
 * @todo    this will make a system call to post the error code.
 */
void    InitService::setProgressCode( uint64_t  &i_progresscode ) const
{

    // do nothing for now
}


/**
 * @note    For task_type = NONE case, I'm assuming that trace will not crash
 *          if we have a NULL taskname string, printing it is useful for debug.
 */
void    InitService::init( void *i_ptr )
{
    errlHndl_t          errl            =   NULL;   // steps will return an error handle if failure
    uint64_t            nextTask     =   0;
    const TaskInfo      *ptask          =   NULL;
    TaskArgs::TaskArgs            args;

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
        ptask    =   &(iv_taskinfolist[nextTask]);
        if ( ptask->taskflags.task_type ==  END_TASK_LIST )
        {
            TRACDCOMP( g_trac_initsvc,
                    "End of Initialization Service task list.\n" );
            break;
        }

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
                                    &args,          //  args
                                    errl );         //  errlog
            break;
        case    START_FN:
            TRACDCOMP( g_trac_initsvc,
                    "task_type==START_FN : %p",
                    ptask->taskfn );
            // $$TODO
            break;
        case    BARRIER:
            TRACDCOMP( g_trac_initsvc,
                    "task_type==BARRIER" );
            // $$TODO
            break;

        default:
            TRACDCOMP( g_trac_initsvc,
                    "Invalid task_type %d: ",
                    ptask->taskflags.task_type );
            errl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                    BASE_INITSVC_ERRL_ID,                   //  moduleid
                    INVALID_TASK_TYPE,                      //  reason Code
                    0,                                      //  user1 = tidrc
                    0 );
            break;

        }   //  endswitch

        //  report an error
        reportError( errl );

    }   // endfor

    //  die if we drop out with an error
    assert( errl == NULL);


    TRACFCOMP( g_trac_initsvc,
            EXIT_MRK "Initilization Service finished.");

    // return to _start(), which may end the task or die.
    return;
}


}   // namespace    INITSERVICE
