//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/istepdispatcher/istepdispatcher.C $
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
 *  @file istepdispatcher.C
 *
 *  IStep Dispatcher code.  Launched from Extended Initialization Service
 *
 *  PNOR Driver and Trace should be available by the time this is launched.
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <stdio.h>
#include    <string.h>

#include    <sys/task.h>                    // tid_t, task_create, etc
#include    <sys/time.h>                    // nanosleep
#include    <trace/interface.H>             //  trace support
#include    <errl/errlentry.H>              //  errlHndl_t
#include    <devicefw/userif.H>             //  targeting
#include    <sys/mmio.h>                    //  mmio_scratch_read()

#include    "istepdispatcher.H"

#include    "splesscommon.H"

#include    <isteps/isteplist.H>


namespace   INITSERVICE
{

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
extern trace_desc_t *g_trac_initsvc;

/**
 * @enum
 *  SPLess Task return codes
 *
 * task return codes for SPless single step
 * @note    future errors will be passed from task_create() and task_exec()
 *          and should be documented in errno.h
 *
 */
enum    {
    SPLESS_TASKRC_INVALID_ISTEP     =   -3,     // invalid istep or substep
    SPLESS_TASKRC_LAUNCH_FAIL       =   -4,     // failed to launch the task
    SPLESS_TASKRC_RETURNED_ERRLOG   =   -5,     // istep returned an errorlog
    SPLESS_TASKRC_TERMINATED        =   -6,     // terminated the polling loop
};

/**
 * @note    SPLess PAUSE - These two constants are used in a nanosleep() call
 *          below to sleep between polls of the StatusReg.  Typically this will
 *          be about 100 ms - the actual value will be determined empirically.
 *
 * @debug  simics "feature" - set polling time to 1 sec for demo
 *
 */

const   uint64_t    SINGLESTEP_PAUSE_S     =   1;
const   uint64_t    SINGLESTEP_PAUSE_NS    =   100000000;


/**
 * @brief   set up _start() task entry procedure using the macro in taskargs.H
 */
TASK_ENTRY_MACRO( IStepDispatcher::getTheInstance().init );


const TaskInfo *IStepDispatcher::findTaskInfo( const uint16_t i_IStep,
                                               const uint16_t i_SubStep ) const
{
    const TaskInfo      *l_pistep       =   NULL;

    TRACDCOMP( g_trac_initsvc,
               "g_isteps[%d].numitems = 0x%x",
               i_IStep,
               g_isteps[i_IStep].numitems );

    //  apply filters
    do
    {

        // check input range - IStep
        if  (   i_IStep >= MAX_ISTEPS   )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep 0x%x out of range.",
                       i_IStep );
            break;      // break out with l_pistep set to NULL
        }

        //  check input range - ISubStep
        if  (   i_SubStep >= g_isteps[i_IStep].numitems )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep 0x%x Substep 0x%x out of range.",
                       i_IStep,
                       i_SubStep );
            break;      // break out with l_pistep set to NULL
        }

        //   check for end of list.
        if ( g_isteps[i_IStep].pti[i_SubStep].taskflags.task_type
                == END_TASK_LIST )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep 0x%x SubSStep 0x%x task_type==END_TASK_LIST.",
                       i_IStep,
                       i_SubStep );
            break;
        }

        // looks good, send it back to the caller
        TRACDCOMP( g_trac_initsvc,
                   "Found TaskInfo 0x%x 0x%x",
                   i_IStep,
                   i_SubStep );
        l_pistep    =   &( g_isteps[i_IStep].pti[i_SubStep] );

    }   while ( 0 );

    return  l_pistep;
}


void IStepDispatcher::init( void * io_ptr )
{

    TRACFCOMP( g_trac_initsvc,
               ENTER_MRK "starting IStepDispatcher, io_ptr=%p ",
               io_ptr );

    if ( getIStepMode() )
    {
        TRACFCOMP( g_trac_initsvc,
                   "IStep single-step" );
        // IStep single-step
        singleStepISteps( io_ptr );
    }
    else
    {
        TRACFCOMP( g_trac_initsvc,
                   "IStep run all" );
        //  Run all the ISteps sequentially
        runAllISteps( io_ptr );
    }   // endelse


    TRACFCOMP( g_trac_initsvc,
               EXIT_MRK "IStepDispatcher finished.");
}


bool IStepDispatcher::getIStepMode( )   const
{

    return  iv_istepmodeflag;
}


/**
 * @todo    revisit this when PNOR Driver is implemented
 *
 */
void IStepDispatcher::initIStepMode( )
{
    uint64_t l_readData = 0;

    l_readData  =   mmio_scratch_read( MMIO_SCRATCH_IPLSTEP_CONFIG );

    TRACDCOMP( g_trac_initsvc,
               "SCOM ScratchPad read, Offset 0x%x, Data 0x%llx",
               MMIO_SCRATCH_IPLSTEP_CONFIG,
               l_readData );

    // check for IStep Mode signature
    if ( l_readData == ISTEP_MODE_SIGNATURE )
    {
        iv_istepmodeflag    =   true;
     }
    else
    {
        iv_istepmodeflag    =   false;
    }

}


void    IStepDispatcher::singleStepISteps( void *  io_ptr )   const
{
    errlHndl_t          l_errl          =   NULL;
    TaskArgs::TaskArgs  l_args;
    const TaskInfo      *l_pistep       =   NULL;
    bool                l_gobit         =   false;
    uint16_t            l_nextIStep     =   0;
    uint16_t            l_nextSubstep   =   0;
    uint16_t            l_taskStatus    =   0;
    uint16_t            l_istepStatus   =   0;
    uint32_t            l_progresscode  =   0;
    uint64_t            l_isteprc       =   0;

    TRACFCOMP( g_trac_initsvc, "Start IStep single-step.\n" );

    // initialize command reg
    SPLESSCMD::write( false,            //  go bit is false
                      0,                //  istep = 0
                      0 );              //  substep = 0

    SPLESSSTS::write( false,            //  running bit
                      true,             //  ready bit
                      0,                //  istep running
                      0,                //  substep running
                      0,                //  task status
                      0 );              //  istep status

    //
    //  @note Start the polling loop.
    //  Currently this has no exit, user should reset the machine and/or
    //  load the payload, which will wipe HostBoot from memory.
    //  Loop forever, unless something Very Bad happens.
    //
    while( 1 )
    {
        //  read command reg, updates l_gobit, l_nextIStep, l_nextSubstep
        SPLESSCMD::read( l_gobit,
                         l_nextIStep,
                         l_nextSubstep );

        //  process any commands
        if ( l_gobit )
        {
            TRACDCOMP( g_trac_initsvc,
                       "gobit turned on, istep=0x%x, substep=0x%x",
                       l_nextIStep,
                       l_nextSubstep );

            //  look up istep+substep
            l_pistep  =   findTaskInfo( l_nextIStep,
                                        l_nextSubstep );
            if ( l_pistep == NULL )
            {
                //  no istep TaskInfo returned, update status & drop to end.
                TRACFCOMP( g_trac_initsvc,
                           "Invalid IStep 0x%x / substep 0x%x, try again.",
                           l_nextIStep,
                           l_nextSubstep );
                SPLESSSTS::write( false,
                                  true,
                                  l_nextIStep,
                                  l_nextSubstep,
                                  SPLESS_TASKRC_INVALID_ISTEP,
                                  0 );
            }
            else
            {
                //  set running bit, fill in istep and substep
                SPLESSSTS::write( true,          //  set running bit
                                  true,          //  ready bit
                                  l_nextIStep,   //  running istep
                                  l_nextSubstep, //  running substep
                                  0,             //  task status (=0)
                                  0 );           //  istep status(=0)

                /**
                 * @todo   placeholder - set progress code before starting
                 * This will not be finalized until the progress code driver
                 * is designed and implemented.
                 */
                l_progresscode  =  ( (l_nextIStep<<16) | l_nextSubstep );
                InitService::getTheInstance().setProgressCode( l_progresscode );

                //  launch the istep
                TRACDCOMP( g_trac_initsvc,
                           "execute Istep=0x%x / Substep=0x%x",
                           l_nextIStep,
                           l_nextSubStep );

                //  clear status, etc for the next istep
                l_taskStatus    =   0;
                l_istepStatus   =   0;
                l_args.clear();

                //  launch the istep
                l_errl = InitService::getTheInstance().executeFn( l_pistep,
                                                                  &l_args );
                //  filter errors returning from executeFn
                if ( l_errl )
                {
                    //  handle an errorlog from the parent.  This means the
                    //  launch failed, set the task Status to Bad.
                    //  no need to process child info, thus the else.
                    //  set the taskStatus to LAUNCH_FAIL; this will fall
                    //  out the bottom and be written to SPLESS Status
                    l_taskStatus    =   SPLESS_TASKRC_LAUNCH_FAIL;
                    TRACFCOMP( g_trac_initsvc,
                               "ERROR 0x%x:  function launch FAIL",
                               l_taskStatus );
                    errlCommit( l_errl );
                }
                else
                {
                    //  process information returned from the IStep.
                    //  make local copies of the info; this has a secondary
                    //  effect of clearing the errorlog pointer inside
                    //  the TaskArgs  struct.
                    l_isteprc   =   l_args.getReturnCode();     // local copy
                    l_errl      =   l_args.getErrorLog();       // local copy

                    TRACDCOMP( g_trac_initsvc,
                               "IStep TaskArgs return 0x%llx, errlog=%p",
                               l_isteprc,
                               l_errl );

                    //  check for child errorlog
                    if ( l_errl )
                    {
                        //  tell the user that the IStep returned an errorlog
                        l_taskStatus    =   SPLESS_TASKRC_RETURNED_ERRLOG;
                        // go ahead and commit the child errorlog
                        errlCommit( l_errl);
                    }

                    //  massage the return code from the IStep -
                    //  If the istep did not set an errorcode,
                    //  then we report 0
                    if ( l_isteprc == TASKARGS_UNDEFINED64 )
                    {
                        l_istepStatus   =   0;
                    }
                    else
                    {
                        //  truncate IStep return status to 16 bits.
                        l_isteprc   &= 0x000000000000ffff;
                        l_istepStatus =   static_cast<uint16_t>(l_isteprc);
                    }

                }   // end else parent errlog

                //  l_taskStatus and l_istepStatus should be set correctly now,
                //  send it to the user.
                //  clear runningbit, report status
                TRACDCOMP( g_trac_initsvc,
                           "Write IStep Status: istep=0x%x, substep=0x%x, taskstatus=0x%x, istepstatus=0x%x",
                           l_nextIStep,
                           l_nextSubstep,
                           l_taskStatus,
                           l_istepStatus );
                SPLESSSTS::write( false,                 // clear running bit
                                  true,                  // ready bit
                                  l_nextIStep,           //  running istep
                                  l_nextSubstep,         //  running substep
                                  l_taskStatus,          //  task status
                                  l_istepStatus          //  istepStatus
                                );

                SPLESSCMD::setgobit( false );            //  clear gobit
            }   // end else  l_pistep
        }   //  endif   gobit

        // sleep, and wait for user to give us something else to do.
        nanosleep( SINGLESTEP_PAUSE_S, SINGLESTEP_PAUSE_NS );
    }   //  endwhile


    //  @note
    //  Fell out of loop, clear sts reg and turn off readybit
    //  Currently this will never be reached.  Later there may be
    //  a reason to break out of the loop, if this happens we want to
    //  disable the ready bit so the user knows.
    SPLESSSTS::write( false,
                      false,
                      0,
                      0,
                      SPLESS_TASKRC_TERMINATED,
                      0
                    );

    //  all errorlogs should have been committed in the loop, we should
    //  not have any errorlogs still set.
    if ( l_errl )
    {
        // if we do then commit it and stop here.
        errlCommit( l_errl );
        assert(0);
    }

}


void    IStepDispatcher::runAllISteps( void * io_ptr )   const
{
    errlHndl_t          l_errl          =   NULL;
    uint16_t            l_IStep         =   0;
    uint16_t            l_SubStep       =   0;
    const TaskInfo      *l_pistep       =   NULL;
    TaskArgs::TaskArgs  l_args;
    uint64_t            l_progresscode  =   0;
    uint64_t            l_isteprc       =   0;

    for (   l_IStep=0;
            l_IStep<INITSERVICE::MAX_ISTEPS;
            l_IStep++ )
    {
        for (   l_SubStep=0;
                l_SubStep < INITSERVICE::MAX_SUBSTEPS;
                l_SubStep++)
        {
            TRACDCOMP( g_trac_initsvc,
                       "Find IStep=%d, SubStep=%d",
                       l_IStep,
                       l_SubStep );

            l_pistep    =   findTaskInfo( l_IStep,
                                          l_SubStep );
            if ( l_pistep == NULL )
            {

                TRACDCOMP( g_trac_initsvc,
                           "End of ISubStep list." );
                break;  // break out of inner for loop
            }

            //  @todo   placeholder until progress codes are defined and
            //          progress code driver is implemented.
            l_progresscode  =  ( (l_IStep<<16) | l_SubStep );
            InitService::getTheInstance().setProgressCode( l_progresscode );

            l_args.clear();

            TRACFCOMP( g_trac_initsvc,
                       "Run IStep 0x%x / Substep 0x%x",
                       l_IStep,
                       l_SubStep );

            l_errl = InitService::getTheInstance().executeFn( l_pistep,
                                                              &l_args );
            if ( l_errl )
            {
                //  Handle an errorlog from the parent, if it exists
                //  an error here is probably fatal, it means we can't
                //  launch the task or it doesn't exist.  In either
                //  case we should exit the loop.
                //  Can't commit the errorlog here because we are using it
                //  as a flag to exit the loop.
                break;
            }

            //  make local copies of the status returned from the istep.
            //  note that this also removes the errorlog from the TaskArgs
            //  struct - it is read-once.  See taskargs.H for details
            l_isteprc   =   l_args.getReturnCode();
            l_errl      =   l_args.getErrorLog();

             TRACDCOMP( g_trac_initsvc,
                       "IStep TaskArgs returned 0x%llx, errlog=%p",
                       l_isteprc,
                       l_errl  );
             if ( l_errl )
             {
                 // if we have an errorlog, break out of the inner loop
                 // and handle it.
                 break;
             }
             else
             {
                 //  Check child results for a valid nonzero return code.
                 //  If we have one, and no errorlog, then we create an
                 //  errorlog here.
                 if (    ( l_isteprc != TASKARGS_UNDEFINED64 )
                      && ( l_isteprc != 0 )
                     )
                 {
                     TRACFCOMP( g_trac_initsvc,
                                "istep returned 0x%llx, no errlog",
                                l_isteprc );

                     /*@     errorlog tag
                      *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                      *  @moduleid       see task list
                      *  @reasoncode     ISTEP_FAILED_NO_ERRLOG
                      *  @userdata1      returncode from istep
                      *  @userdata2      0
                      *
                      *  @devdesc        The Istep returned with an error,
                      *                  but there was no errorlog posted
                      *                  from the IStep.
                      */
                     l_errl = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                             l_pistep->taskflags.module_id,
                             INITSERVICE::ISTEP_FAILED_NO_ERRLOG,
                             l_isteprc,
                             0 );
                     // drop out of inner loop with errlog set.
                     break;
                 }   // end if ( )
             }
        }   // endfor l_SubStep

        if ( l_errl )
        {
            // something left an error log in the inner loop, breakout
            break;
        }
    }   // endfor l_IStep


    /**
     * @todo detect Can-Continue condition here and reset/rerun ISteps.
     *      For now this is pushed to a later sprint.
     */


    //  Post any errorlogs.  If one exists, stop here.   Otherwise, return
    //  to caller.
    if  ( l_errl )
    {
        TRACFCOMP( g_trac_initsvc,
                   "ERROR:  istep=0x%x, substep=0x%x, committing errorlog %p",
                   l_IStep,
                   l_SubStep,
                   l_errl );
        errlCommit( l_errl );
        assert( 0 );
    }

}




bool IStepDispatcher::getCanContinueProcedure(  const  TaskInfo &i_failingIStep,
                                                errlHndl_t      &i_failingError,
                                                TaskInfo        &io_nextIstep
                                                ) const
{

    return  false;
}


IStepDispatcher& IStepDispatcher::getTheInstance()
{
    return Singleton<IStepDispatcher>::instance();
}


IStepDispatcher::IStepDispatcher()
{
    initIStepMode();            // set up internal flag

}


IStepDispatcher::~IStepDispatcher()
{ }

} // namespace
