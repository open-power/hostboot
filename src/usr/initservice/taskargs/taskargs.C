//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/taskargs/taskargs.C $
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
 * @file    taskargs.C
 *
 * common file to hold arguments passed onto tasks.
 * will also hold macros, etc to manage arguments
 *
 * @note Notes on barrier:
 *  barrier_init() will initialize the barrier to the number of threads to
 *  wait on.
 *  "barrier_wait() function shall synchronize participating threads at
 *  the barrier referenced by barrier.
 *  The calling thread shall block until the required number of threads
 *  have called pthread_barrier_wait specifying the barrier."
 *
 *  So in this case, the barrier is initialized to 2 (through barrier_init()
 *  in the constructor).
 *  When InitSvc launches the child, it calls barrier wait() (through
 *  waitChildSync() ) which adds 1 task  to the "waitlist", blocks, and
 *  returns to InitSvc.  InitSvc then calls waitParentSync() which adds
 *  its' task to the "waitlist".   When the second task is added, both task
 *  are unblocked.
 *
 *  The barrier is destroyed when TaskArgs goes out of scope by calling
 *  barrier_destroy() in the destructor.
 *
 */

#include <initservice/taskargs.H>


namespace   INITSERVICE
{

extern  trace_desc_t *g_trac_initsvc;


void    TaskArgs::waitParentSync( )
{

    barrier_wait( &iv_sync_barrier);

}


void    TaskArgs::waitChildSync( )
{

    barrier_wait( &iv_sync_barrier);

}


void    TaskArgs::postReturnCode( const uint64_t i_returncode )
{
    iv_taskreturncode  =   i_returncode;

    return;
}


uint64_t TaskArgs::getReturnCode( ) const
{

    return iv_taskreturncode;
}


void    TaskArgs::setCommand( const uint64_t  i_command )
{

    iv_taskcommand =   i_command;

    return;
}


uint64_t    TaskArgs::getCommand( ) const
{

    return  iv_taskcommand;
}


void        TaskArgs::postErrorLog( errlHndl_t i_errl )
{

    iv_errl =   i_errl;
}


errlHndl_t  TaskArgs::getErrorLog( )
{
    errlHndl_t  l_errl  = iv_errl;

    // null out iv_errl after returning it to someone.
    iv_errl =   NULL;

    return  l_errl;
}


void    TaskArgs::clear()
{
    iv_taskreturncode   =   TASKARGS_UNDEFINED64;   //  init iv_returncode to undefined
    iv_taskcommand      =   TASKARGS_UNDEFINED64;   //  init iv_command to undefined

    //  this should not happen, should have been handled by the caller(s)
    //  commit the errorlog here just to get rid of it
    if ( iv_errl )
    {
        TRACFCOMP( g_trac_initsvc,
                ERR_MRK "ERROR: errorlog %p was left in TaskArgs",
                iv_errl );

        errlCommit(iv_errl,INITSVC_COMP_ID);
    }

}


TaskArgs::TaskArgs()
:   iv_errl( NULL ),                                //  init errorlog handle to NULL
    iv_taskreturncode(TASKARGS_UNDEFINED64),        //  init iv_returncode to undefined
    iv_taskcommand(TASKARGS_UNDEFINED64)            //  init iv_command to undefined
{
    // set barrier to wait for 2 tasks before releasing,
    //  see notes above.
    barrier_init( &iv_sync_barrier, 2 );
}


TaskArgs::~TaskArgs()
{
    clear();
    barrier_destroy( &iv_sync_barrier );
    // add an assert here to check if there is still an errorlog pending?
}

};  // namespace
