/**
 * @file    extinitsvc.C
 *
 *  Implements Initialization Service for Host boot in the extended image.
 *  See extinitsvc.H for details
 *
 */

#include <kernel/console.H>
#include <sys/vfs.h>
#include <sys/task.h>
#include <sys/sync.h>

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


errlHndl_t  ExtInitSvc::startTask( const TaskInfo *i_ptask,
        TaskArgs::TaskArgs    *i_pargs,
        errlHndl_t &io_rerrl ) const
{
    /**
     *  @todo run constructor on task here.
     */

    InitService::startTask( i_ptask, i_pargs, io_rerrl );

    return io_rerrl;
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
        ptask    =   &(iv_exttaskinfolist[nextTask]);
        if ( ptask->taskflags.task_type ==  END_TASK_LIST )
        {
            TRACDCOMP( g_trac_initsvc,
                    "End of ExtInitSvc task list.\n" );
            break;
        }

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
        case    START_TASK:
            TRACDBIN( g_trac_initsvc,
                    "task_type=START_TASK : ",
                    ptask->taskname,
                    strlen(ptask->taskname)    );
            errl    =   startTask( ptask,
                    &args,
                    errl );
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
                    "Invalid task_type: %d",
                    ptask->taskflags.task_type );
            errl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                    START_EXTINITSVC_ERRL_ID,               //  moduleid
                    INVALID_TASK_TYPE,                      //  reason Code
                    0,                                      //  user1 = tidrc
                    0 );
            break;
        }   //  endswitch

        //  report an error
        reportError( errl );


    }   // endfor


    TRACFCOMP( g_trac_initsvc,
            EXIT_MRK "ExtInitSvc finished.");



    //  =====================================================================
    //  -----   Unit Tests  -------------------------------------------------
    //  =====================================================================
    /**
     *  @note run all the unit tests after we finish the rest
     */
    TRACDBIN( g_trac_initsvc,
            ENTER_MRK "Run Unit Tests: ",
            CXXTEST_TASK.taskname,
            strlen(CXXTEST_TASK.taskname)    );

    errl = startTask(   &CXXTEST_TASK,              //  task struct
                        NULL,                       //  no args
                        errl );                     //  pointer to errorlog
    //  report an error
    reportError( errl );

    TRACDCOMP( g_trac_initsvc,
            EXIT_MRK "Unit Tests finished.");


    // return to _start(), which may end the task or die.
    return;
}


}   // namespace    EXTINITSVC
