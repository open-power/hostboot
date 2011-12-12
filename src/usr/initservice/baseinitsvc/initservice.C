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
#define __HIDDEN_SYSCALL_SHUTDOWN

#include    <kernel/console.H>
#include    <sys/vfs.h>
#include    <vfs/vfs.H>
#include    <sys/task.h>
#include    <sys/misc.h>
#include    <trace/interface.H>
#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>
#include    <sys/sync.h>
#include    <sys/mm.h>
#include    <vmmconst.h>

#include    "initservice.H"
#include    "initsvctasks.H"


//  -----   namespace   SPLESS  -----------------------------------------------
namespace   SPLESS
{
    //  allocate space for SPLess Command regs
    uint64_t    g_SPLess_Command_Reg    =   0;
    uint64_t    g_SPLess_Status_Reg     =   0;
    uint64_t    g_SPLess_IStepMode_Reg  =   0x123456789abcdef0;

}   //  -----   end namespace   SPLESS  ---------------------------------------

namespace   INITSERVICE
{

trace_desc_t *g_trac_initsvc = NULL;
TRAC_INIT(&g_trac_initsvc, "INITSVC", 4096 );


errlHndl_t InitService::startTask( const TaskInfo       *i_ptask,
                                   TaskArgs::TaskArgs   *io_pargs ) const
{
    tid_t       l_tidrc     =   0;
    errlHndl_t  l_errl      =   NULL;

    assert( i_ptask != NULL );
    assert( i_ptask->taskflags.task_type == START_TASK );

    // Base modules have already been loaded and initialized,
    // extended modules have not.
    if ( i_ptask->taskflags.module_type == EXT_IMAGE )
    {
        // load module and call _init()
        l_errl = VFS::module_load( i_ptask->taskname );
    }

    if ( ! l_errl )
    {
        // launch a task and wait for it.
        l_tidrc = task_exec( i_ptask->taskname, io_pargs );

        //  process the return - kernel returns a 16-bit signed # as a
        //  threadid/error
        if ( static_cast<int16_t> (l_tidrc) < 0 )
        {
            // task failed to launch, post an errorlog and dump some trace
            /*@     errorlog tag
             *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
             *  @moduleid       INITSVC_START_TASK_MOD_ID
             *  @reasoncode     START_TASK_FAILED
             *  @userdata1      task module id
             *  @userdata2      task id or task return code
             *
             *  @devdesc        Initialization Service failed to start a task.
             *
             */
            l_errl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                    INITSERVICE::INITSVC_START_TASK_MOD_ID,
                    INITSERVICE::START_TASK_FAILED,
                    i_ptask->taskflags.module_id,
                    l_tidrc );
        } // endif tidrc
        else
        {
            //  if InitService passed in a taskargs, wait for barrier.
            if ( io_pargs )
            {
                io_pargs->waitParentSync();
            }
        }   // endelse
    }   // endif ! l_errl


    //  return any errorlog to the caller
    return l_errl;
}

errlHndl_t InitService::executeFn( const TaskInfo   *i_ptask,
                                   TaskArgs         *io_pargs ) const
{
    tid_t       l_tidrc     =   0;
    errlHndl_t  l_errl      =   NULL;

    assert( i_ptask != NULL );
    assert( i_ptask->taskfn != NULL ) ;

    //  valid function, launch it
    l_tidrc = task_create( i_ptask->taskfn, io_pargs);
    if (static_cast<int16_t> (l_tidrc) < 0)
    {
        /*@     errorlog tag
         *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
         *  @moduleid       INITSVC_START_FN_MOD_ID
         *  @reasoncode     START_FN_FAILED
         *  @userdata1      task module id
         *  @userdata2      task id or task return code
         *
         *  @devdesc        Initialization Service attempted to start a
         *                  function within a module but the function
         *                  failed to launch
         */
        l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                INITSERVICE::INITSVC_START_FN_MOD_ID,
                INITSERVICE::START_FN_FAILED,
                i_ptask->taskflags.module_id,
                l_tidrc );

    } // endif tidrc
    else
    {
        // task launched OK.
        if ( io_pargs )
        {
            io_pargs->waitParentSync(); // sync up parent task
        }
    }

    return l_errl;
}


/**
 * @todo    this will make a system call to post the progress code.
 *
 */
void InitService::setProgressCode( uint64_t i_progresscode ) const
{

    // do nothing for now
}


errlHndl_t  InitService::dispatchTask( const TaskInfo   *i_ptask,
                                       TaskArgs         *io_pargs ) const
{
    errlHndl_t   l_errl  =   NULL;


    //  dispatch tasks...
    switch ( i_ptask->taskflags.task_type)
    {
    case NONE:
        //  task is a place holder, skip
        TRACDCOMP( g_trac_initsvc,
                   "task_type==NONE : %s",
                   i_ptask->taskname );
        break;
    case START_TASK:
        TRACDCOMP( g_trac_initsvc,
                  "task_type==START_TASK: %s",
                  i_ptask->taskname );
        l_errl = startTask( i_ptask,
                            io_pargs );
        break;
    case INIT_TASK:
        TRACDCOMP( g_trac_initsvc,
                   "task_type==INIT_TASK: %s",
                   i_ptask->taskname);

        l_errl = VFS::module_load( i_ptask->taskname );
        break;
    case START_FN:
        TRACDCOMP( g_trac_initsvc,
                   "task_type==START_FN : %s %p",
                   i_ptask->taskname,
                   i_ptask->taskfn );
        l_errl = executeFn( i_ptask,
                            io_pargs );
        break;
    case UNINIT_TASK:
        TRACDCOMP( g_trac_initsvc,
                  "task_type=UNINIT_TASK : %s ",
                  i_ptask->taskname );
        l_errl = VFS::module_unload( i_ptask->taskname );
        break;
    default:
        /**
         * @note    If there is a bad TaskInfo struct we just stop here.
         */
        TRACFCOMP( g_trac_initsvc,
                   "Invalid task_type %d: ABORT",
                   i_ptask->taskflags.task_type );
        assert( 0 );
        break;

    } //  endswitch

    return  l_errl;
}


void InitService::init( void *io_ptr )
{
    errlHndl_t          l_errl      =   NULL;
    uint64_t            l_task      =   0;
    const TaskInfo      *l_ptask    =   NULL;
    TaskArgs::TaskArgs  l_args;
    uint64_t            l_childrc   =   0;

    TRACFCOMP( g_trac_initsvc,
               ENTER_MRK "Initialization Service is starting." );

    //  loop through the task list and start up any tasks necessary
    for ( l_task=0;
          l_task < INITSERVICE::MAX_TASKS;
          l_task++ )
    {
        //  make a local copy of the base image task
        l_ptask = &(g_taskinfolist[ l_task]);
        if ( l_ptask->taskflags.task_type == END_TASK_LIST )
        {
            TRACDCOMP( g_trac_initsvc,
                    "End of Initialization Service task list." );
            break;
        }

        l_args.clear(); // clear args struct for next task

        //  dispatch the task and return good or errorlog
        l_errl  =   dispatchTask( l_ptask,
                                  &l_args );

        //  process errorlogs returned from the task that was launched
        if ( l_errl )
        {
            TRACFCOMP( g_trac_initsvc,
                       "ERROR: dispatching task, errorlog=0x%p",
                       l_errl );
            //  drop out with the error
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
                       " ERROR: Child task returned 0x%llx, errlog=0x%p",
                       l_childrc,
                       l_errl );
            //  drop out with the error
            break;
        }
        else
        {
            //  Check child results for a valid nonzero return code.
            //  If we have one, and no errorlog, then we create and
            //  post our own errorlog here.
            if (  l_childrc != 0 )
            {
                TRACFCOMP( g_trac_initsvc,
                           "IS: Child task %s returned 0x%llx, no errlog",
                           l_ptask->taskname,
                           l_childrc );

                /*@     errorlog tag
                 *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                 *  @moduleid       INITSVC_TASK_RETURNED_ERROR_ID
                 *  @reasoncode     INITSVC_FAILED_NO_ERRLOG
                 *  @userdata1      returncode from task
                 *  @userdata2      0
                 *
                 *  @devdesc        The task returned with an error,
                 *                  but there was no errorlog returned.
                 *                  See userdata1 for the return code.
                 *
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                        INITSVC_TASK_RETURNED_ERROR_ID,
                        INITSERVICE::INITSVC_FAILED_NO_ERRLOG,
                        l_childrc,
                        0 );
                // drop out with the error
                break;
            }   // end if
        }   //  end else
    } // endfor

    //  die if we drop out with an error
    if ( l_errl )
    {
        //  commit the log first, then shutdown.
        TRACFCOMP( g_trac_initsvc, "InitService: Committing errorlog." );
        errlCommit( l_errl, INITSVC_COMP_ID );

        //Tell initservice to perform shutdown sequence
        doShutdown( SHUTDOWN_STATUS_INITSVC_FAILED );

    }

    TRACFCOMP( g_trac_initsvc,
            EXIT_MRK "Initilization Service finished.");

    // return to _start()
}


InitService& InitService::getTheInstance( )
{
    return Singleton<InitService>::instance();
}


InitService::InitService( )
{ }


InitService::~InitService( )
{ }

void registerBlock(void* i_vaddr, uint64_t i_size, BlockPriority i_priority)
{
    Singleton<InitService>::instance().registerBlock(i_vaddr,i_size,i_priority);
}

void InitService::registerBlock(void* i_vaddr, uint64_t i_size,
                                BlockPriority i_priority)
{
    //Order priority from largest to smallest upon inserting
    std::vector<regBlock_t*>::iterator regBlock_iter = iv_regBlock.begin();
    for (; regBlock_iter!=iv_regBlock.end(); ++regBlock_iter)
    {
        if ((uint64_t)i_priority >= (*regBlock_iter)->priority)
        {
            iv_regBlock.insert(regBlock_iter,
                               new regBlock_t(i_vaddr,i_size,
                                              (uint64_t)i_priority));
            regBlock_iter=iv_regBlock.begin();
            break;
        }
    }
    if (regBlock_iter == iv_regBlock.end())
    {
        iv_regBlock.push_back(new regBlock_t(i_vaddr,i_size,
                                             (uint64_t)i_priority));
    }
}

void InitService::doShutdown(uint64_t i_status)
{
    int l_rc = 0;
    errlHndl_t l_err = NULL;
    std::vector<regBlock_t*>::iterator l_rb_iter = iv_regBlock.begin();
    //FLUSH each registered block in order
    while (l_rb_iter!=iv_regBlock.end())
    {
        l_rc = mm_remove_pages(FLUSH,(*l_rb_iter)->vaddr,(*l_rb_iter)->size);
        if (l_rc)
        {
            /*
             * @errorlog tag
             * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid        INITSVC_DO_SHUTDOWN_MOD_ID
             * @reasoncode      SHUTDOWN_FLUSH_FAILED
             * @userdata1       returncode from mm_remove_pages()
             * @userdata2       0
             *
             * @defdesc         Could not FLUSH virtual memory.
             *
             */
            l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                        INITSERVICE::INITSVC_DO_SHUTDOWN_MOD_ID,
                        INITSERVICE::SHUTDOWN_FLUSH_FAILED,l_rc,0);
            //Commit and attempt flushing other registered blocks
            errlCommit( l_err, INITSVC_COMP_ID );
            l_err = NULL;
        }
        l_rb_iter++;
    }
    shutdown(i_status);
}

} // namespace
