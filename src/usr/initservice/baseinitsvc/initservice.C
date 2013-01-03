/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/baseinitsvc/initservice.C $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/**
 * @file    initservice.C
 *
 *  Implements Initialization Service for Host boot.
 *  See initservice.H for details
 *
 */
#define __HIDDEN_SYSCALL_SHUTDOWN

#include    <kernel/console.H>                  // printk status

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

#include    <errl/errludstring.H>

#include    <initservice/taskargs.H>        // TASK_ENTRY_MACRO

#include    "initservice.H"
#include    "initsvctasks.H"


//  -----   namespace   SPLESS  -----------------------------------------------
namespace   SPLESS
{
    //  allocate space for SPLess Command regs in the base image.
    uint64_t    g_SPLess_Command_Reg    =   0;
    uint64_t    g_SPLess_Status_Reg     =   0;

}
//  -----   end namespace   SPLESS  ---------------------------------------


namespace   INITSERVICE
{

trace_desc_t *g_trac_initsvc = NULL;
TRAC_INIT(&g_trac_initsvc, "INITSVC", 2*KILOBYTE );

/**
 *  @brief  start() task entry procedure
 *  This one is "special" since we do not return anything to the kernel/vfs
 */
extern "C"
void* _start(void *ptr)
{
    TRACFCOMP( g_trac_initsvc,
            "Executing Initialization Service module." );

    // initialize the base modules in Hostboot.
    InitService::getTheInstance().init( ptr );

    TRACFCOMP( g_trac_initsvc,
            "return from Initialization Service module." );

    return NULL;
}



errlHndl_t  InitService::checkNLoadModule( const TaskInfo *i_ptask ) const
{
    errlHndl_t      l_errl  =   NULL;
    const   char    *l_modulename   =   NULL;

    assert(i_ptask->taskflags.task_type   ==  START_FN );

    do  {

        //  i_ptask->taskflags.task_type   ==  STARTFN
        l_modulename  =   VFS::module_find_name(
                reinterpret_cast<void*>(i_ptask->taskfn) );
        if  ( l_modulename  ==   NULL )
        {
            /*@     errorlog tag
             *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
             *  @moduleid       BASE_INITSVC_MOD_ID
             *  @reasoncode     INITSVC_LOAD_MODULE_FAILED
             *  @userdata1      0
             *  @userdata2      0
             *
             *  @devdesc        Initialization Service failed to load a
             *                  module needed to load a function or task.
             *                  UserDetails will contain the name of the
             *                  function or task.
             */
            l_errl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                    INITSERVICE::BASE_INITSVC_MOD_ID,
                    INITSERVICE::INITSVC_LOAD_MODULE_FAILED,
                    0,
                    0 );

            //  error, break out of do block
            break;
        }

        TRACDCOMP( g_trac_initsvc,
                "checkNLoadModule: found %s in module %s",
                i_ptask->taskname,
                ((l_modulename!=NULL)?l_modulename:"NULL???") );

        if (  !VFS::module_is_loaded( l_modulename )
        )
        {
            TRACDCOMP( g_trac_initsvc,
                    "loading module %s",
                    l_modulename );
            l_errl = VFS::module_load( l_modulename );
            if ( l_errl )
            {
                //  load module returned with errl set
                TRACFCOMP( g_trac_initsvc,
                        "module_load( %s ) returned with an error.",
                        l_modulename );

                //  break out of do block
                break;
            }
        }

    }   while( 0 );     // end do() block


    return  l_errl;
}


errlHndl_t InitService::startTask(
        const TaskInfo       *i_ptask,
        void                 *io_pargs ) const
{
    tid_t       l_tidlnchrc     =   0;
    tid_t       l_tidretrc      =   0;
    errlHndl_t  l_errl          =   NULL;
    int         l_childsts      =   0;
    void        *l_childerrl    =   NULL;


    assert( i_ptask != NULL );
    // assert( i_ptask->taskflags.task_type == START_TASK );

    do  {
        // Base modules have already been loaded and initialized,
        // extended modules have not.
        if ( i_ptask->taskflags.module_type == EXT_IMAGE )
        {
            // load module if necessary
            l_errl = VFS::module_load( i_ptask->taskname );
        }
        if ( l_errl )
        {
            TRACFCOMP(g_trac_initsvc,
                    "ERROR: failed to load module for task '%s'",
                    i_ptask->taskname);

            // drop out of do block with errl set
            break;
        }

        // launch a task and wait for it.
        l_tidlnchrc = task_exec( i_ptask->taskname, io_pargs );
        TRACDCOMP( g_trac_initsvc,
                "launch task %s returned %d",
                i_ptask->taskname,
                l_tidlnchrc );

        //  process the return - kernel returns a 16-bit signed # as a
        //  threadid/error
        if ( static_cast<int16_t> (l_tidlnchrc) < 0 )
        {
            // task failed to launch, post an errorlog and dump some trace
            TRACFCOMP(g_trac_initsvc,
                    "ERROR 0x%x: starting task '%s'",
                    l_tidlnchrc,
                    i_ptask->taskname);

            /*@     errorlog tag
             *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
             *  @moduleid       BASE_INITSVC_MOD_ID
             *  @reasoncode     START_TASK_FAILED
             *  @userdata1      0
             *  @userdata2      task id or task return code
             *
             *  @devdesc        Initialization Service failed to start a task.
             *
             */
            l_errl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                    INITSERVICE::BASE_INITSVC_MOD_ID,
                    INITSERVICE::START_TASK_FAILED,
                    0,
                    l_tidlnchrc );

            //  break out of do block
            break;
        } // endif tidlnchrc

        TRACDCOMP(g_trac_initsvc,
                            "Wait for tid %d '%s'",
                            l_tidlnchrc,
                            i_ptask->taskname);

        //  wait here for the task to end.
        //  status of the task ( OK or Crashed ) is returned in l_childsts
        //  if the task returns an errorlog, it will be returned
        //  in l_childerrl
        l_tidretrc  =   task_wait_tid(
                                l_tidlnchrc,
                                &l_childsts,
                                &l_childerrl );
        if (    ( static_cast<int16_t>(l_tidretrc) < 0 )
             || ( l_childsts != TASK_STATUS_EXITED_CLEAN )
        )
        {
            // the launched task failed or crashed,
            //  post an errorlog and dump some trace
            /*@     errorlog tag
             *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
             *  @moduleid       BASE_INITSVC_MOD_ID
             *  @reasoncode     WAIT_TASK_FAILED
             *  @userdata1      task id or task return code
             *  @userdata2      returned status from task
             *
             *  @devdesc        Initialization Service launched a task and
             *                  the task returned an error.
             *
             */
            l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                    INITSERVICE::BASE_INITSVC_MOD_ID,
                                    INITSERVICE::WAIT_TASK_FAILED,
                                    l_tidretrc,
                                    l_childsts );

            //  break out of do block
            break;
        } // endif tidretrc

        //  check for returned errorlog
        if ( l_childerrl != NULL )
        {
            // cast to the correct type and return
            l_errl  =   reinterpret_cast<errlHndl_t>(l_childerrl);

            // break out of do block
            break;
        }

    }   while(0);   // end do block

    if ( l_errl )
    {
        // Add the task name as user detail data to any errorlog
        ERRORLOG::ErrlUserDetailsString(i_ptask->taskname).addToLog(l_errl);
    }

    //  return any errorlog to the caller
    return l_errl;
}   // startTask()


errlHndl_t InitService::executeFn(
                        const TaskInfo  *i_ptask,
                        void            *io_pargs ) const
{
    tid_t       l_tidlnchrc     =   0;
    tid_t       l_tidretrc      =   0;
    errlHndl_t  l_errl          =   NULL;
    int         l_childsts      =   0;
    void        *l_childerrl    =   NULL;

    assert( i_ptask != NULL );
    assert( i_ptask->taskfn != NULL ) ;


    do  {

        // If the module is not in the base image, then we must ensure that
        // the module has been loaded already.
        if (BASE_IMAGE != i_ptask->taskflags.module_type)
        {
            l_errl = checkNLoadModule( i_ptask );
        }
        if ( l_errl )
        {
            TRACFCOMP(g_trac_initsvc,
                    "ERROR: failed to load module for task '%s'",
                    i_ptask->taskname);

            //  break out with errorlog set
            break;
        }

        //  valid function, launch it
        l_tidlnchrc = task_create( i_ptask->taskfn, io_pargs);
        if (static_cast<int16_t> (l_tidlnchrc) < 0)
        {
            TRACFCOMP(g_trac_initsvc,
                    "ERROR %d: starting function in task'%s'",
                    l_tidlnchrc,
                    i_ptask->taskname);

            /*@     errorlog tag
             *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
             *  @moduleid       BASE_INITSVC_MOD_ID
             *  @reasoncode     START_FN_FAILED
             *  @userdata1      task return code
             *  @userdata2      0
             *
             *  @devdesc        Initialization Service attempted to start a
             *                  function within a module but the function
             *                  failed to launch
             */
            l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                    INITSERVICE::BASE_INITSVC_MOD_ID,
                                    INITSERVICE::START_FN_FAILED,
                                    l_tidlnchrc,
                                    0   );

            //  break out with errorlog set
            break;
        } // endif tidlnchrc

        //  wait here for the task to end.
        //  status of the task ( OK or Crashed ) is returned in l_childsts
        //  if the task returns an errorlog, it will be returned
        //  in l_childerrl
        l_tidretrc  =   task_wait_tid(
                                l_tidlnchrc,
                                &l_childsts,
                                &l_childerrl );
        if (    ( static_cast<int16_t>(l_tidretrc) < 0 )
             || ( l_childsts != TASK_STATUS_EXITED_CLEAN )
            )
        {
            // the launched task failed or crashed
            //  post an errorlog and dump some trace
            /*@     errorlog tag
             *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
             *  @moduleid       BASE_INITSVC_MOD_ID
             *  @reasoncode     WAIT_FN_FAILED
             *  @userdata1      task id or task return code
             *  @userdata2      returned status from task
             *
             *  @devdesc        Initialization Service launched a function and the task returned an error.
             *
             *
             */
            l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                    INITSERVICE::BASE_INITSVC_MOD_ID,
                                    INITSERVICE::WAIT_FN_FAILED,
                                    l_tidretrc,
                                    l_childsts );

            TRACFCOMP(g_trac_initsvc,
                    "ERROR : task_wait_tid(0x%x). '%s', l_tidretrc=0x%x, l_childsts=0x%x",
                    l_tidlnchrc,
                    i_ptask->taskname,
                    l_tidretrc,
                    l_childsts );

            //  break out of do block
            break;
        } // endif tidretrc

        //  check for returned errorlog
        if ( l_childerrl != NULL )
        {
            TRACFCOMP(g_trac_initsvc,
                    "ERROR : task_wait_tid(0x%x). '%s', l_childerrl=%p",
                    l_tidlnchrc,
                    i_ptask->taskname,
                    l_childerrl  );

            // cast to the correct type and return
            l_errl  =   reinterpret_cast<errlHndl_t>(l_childerrl);

            // break out of do block
            break;
        }

    }   while( 0 );     // end do block

    if ( l_errl )
    {
        // Add the task name as user detail data to any errorlog that was
        //  posted.
        ERRORLOG::ErrlUserDetailsString(i_ptask->taskname).addToLog(l_errl);
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
                                       void             *io_pargs ) const
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
    errlHndl_t      l_errl              =   NULL;
    uint64_t        l_task              =   0;
    const TaskInfo  *l_ptask            =   NULL;
    //  init shutdown status to good.
    uint64_t        l_shutdownStatus    =   SHUTDOWN_STATUS_GOOD;

    //  @todo detach from parent.
    // $$ task_detach();

    printk( "InitService entry.\n" );

    TRACFCOMP( g_trac_initsvc,
               "Initialization Service is starting, io_ptr=%p.", io_ptr );

    //  loop through the task list and start up any tasks necessary
    for ( l_task=0;
          l_task <  ( sizeof(g_taskinfolist)/sizeof(TaskInfo) ) ;
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

        //  dispatch the task and return good or errorlog
        l_errl  =   dispatchTask( l_ptask ,
                                  NULL );

        //  process errorlogs returned from the task that was launched
        if ( l_errl )
        {
            TRACFCOMP( g_trac_initsvc,
                       "ERROR: dispatching task, errorlog=0x%p",
                       l_errl );
            //  drop out with the error
            break;
        }

    } // endfor

    //  die if we drop out with an error
    if ( l_errl )
    {

        //  commit the log first, then shutdown.
        TRACFCOMP( g_trac_initsvc,
                "InitService: Committing errorlog %p",
                l_errl );

        // Set the shutdown status to be the plid to force a TI
        l_shutdownStatus = l_errl->plid();

        errlCommit( l_errl, INITSVC_COMP_ID );

    }

    //  =====================================================================
    //  -----   Shutdown all CPUs   -----------------------------------------
    //  =====================================================================

    TRACFCOMP( g_trac_initsvc,
            "InitService finished, shutdown = 0x%x.",
            l_shutdownStatus );

    //  Tell kernel to perform shutdown sequence
    InitService::getTheInstance().doShutdown( l_shutdownStatus );

    printk( "InitService exit.\n" );
    // return to _start() to exit the task.
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

void doShutdown ( uint64_t i_status,
                  uint64_t i_payload_base,
                  uint64_t i_payload_entry,
                  uint64_t i_payload_data)
{
    Singleton<InitService>::instance().doShutdown( i_status,
                                                   i_payload_base,
                                                   i_payload_entry,
                                                   i_payload_data);

    while(1)
    {
        task_yield();
    };
}

void InitService::doShutdown(uint64_t i_status,
                             uint64_t i_payload_base,
                             uint64_t i_payload_entry,
                             uint64_t i_payload_data)
{
    int l_rc = 0;
    errlHndl_t l_err = NULL;

    // Call registered services and notify of shutdown
    msg_t * l_msg = msg_allocate();
    l_msg->data[0] = i_status;
    l_msg->data[1] = 0;
    l_msg->extra_data = 0;

    for(EventRegistry_t::iterator i = iv_regMsgQ.begin();
        i != iv_regMsgQ.end();
        ++i)
    {
        l_msg->type = i->msgType;
        msg_sendrecv(i->msgQ,l_msg);
    }

     msg_free(l_msg);

    std::vector<regBlock_t*>::iterator l_rb_iter = iv_regBlock.begin();
    //FLUSH each registered block in order
    while (l_rb_iter!=iv_regBlock.end())
    {
        l_rc = mm_remove_pages(FLUSH,(*l_rb_iter)->vaddr,(*l_rb_iter)->size);
        if (l_rc)
        {
            TRACFCOMP(g_trac_initsvc, "ERROR: flushing virtual memory");
            /*
             * @errorlog tag
             * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid        BASE_INITSVC_MOD_ID
             * @reasoncode      SHUTDOWN_FLUSH_FAILED
             * @userdata1       returncode from mm_remove_pages()
             * @userdata2       0
             *
             * @defdesc         Could not FLUSH virtual memory.
             *
             */
            l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                        INITSERVICE::BASE_INITSVC_MOD_ID,
                        INITSERVICE::SHUTDOWN_FLUSH_FAILED,l_rc,0);
            //Commit and attempt flushing other registered blocks
            errlCommit( l_err, INITSVC_COMP_ID );
            l_err = NULL;
        }
        l_rb_iter++;
    }

    shutdown(i_status, i_payload_base, i_payload_entry, i_payload_data);
}

bool InitService::registerShutdownEvent(msg_q_t i_msgQ,
                                        uint32_t i_msgType,
                                        EventPriority_t i_priority)
{
    bool result = true;
    EventRegistry_t::iterator in_pos = iv_regMsgQ.end();

    for(EventRegistry_t::iterator r = iv_regMsgQ.begin();
        r != iv_regMsgQ.end();
        ++r)
    {
        if(r->msgQ == i_msgQ)
        {
            result = false;
            break;
        }

        if(r->msgPriority <= (uint32_t)i_priority)
        {
            in_pos = r;
        }
    }

    if(result)
    {
        in_pos = iv_regMsgQ.insert(in_pos,
                                   regMsgQ_t(i_msgQ, i_msgType, i_priority));
    }

    return result;
}

bool InitService::unregisterShutdownEvent(msg_q_t i_msgQ)
{
    bool result = false;
    for(EventRegistry_t::iterator r = iv_regMsgQ.begin();
        r != iv_regMsgQ.end();
        ++r)
    {
        if(r->msgQ == i_msgQ)
        {
            result = true;
            iv_regMsgQ.erase(r);
            break;
        }
    }
    return result;
}

/**
 * @see src/include/usr/initservice/initservicif.H
 */
bool registerShutdownEvent(msg_q_t i_msgQ,
                           uint32_t i_msgType,
                           EventPriority_t i_priority)
{
    return
    Singleton<InitService>::instance().registerShutdownEvent(i_msgQ,
                                                             i_msgType,
                                                             i_priority);
}

bool unregisterShutdownEvent(msg_q_t i_msgQ)
{
    return Singleton<InitService>::instance().unregisterShutdownEvent(i_msgQ);
}

} // namespace
