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

#include    <sys/task.h>                    //  tid_t, task_create, etc
#include    <sys/time.h>                    //  nanosleep
#include    <sys/misc.h>                    //  shutdown
#include    <trace/interface.H>             //  trace support
#include    <errl/errlentry.H>              //  errlHndl_t
#include    <devicefw/userif.H>             //  targeting
#include    <sys/mmio.h>                    //  mmio_scratch_read()
#include    <initservice/taskargs.H>        //  TaskArgs    structs

#include    <errl/errluserdetails.H>        //  ErrlUserDetails base class

#include    <targeting/attributes.H>        //  ISTEP_MODE attribute
#include    <targeting/entitypath.H>
#include    <targeting/target.H>
#include    <targeting/targetservice.H>

#include    "istepdispatcher.H"

#include    "splesscommon.H"

#include    <isteps/istepmasterlist.H>


namespace   ERRORLOG
{
/**
 * @class IStepNameUserDetail
 *
 * report the failing IStepName.
 *
 * @todo:   get rid of magic numbers in version and subsection.
 *          set up tags, plugins, include files, etc.
 *          For now we just want to report the failing istep string for debug.
 * @todo:   Expand this to report the istep / substep, error returned, etc.
 */

class   IStepNameUserDetail : public ErrlUserDetails
{

public:

    IStepNameUserDetail(
            const char *i_istepname,
            const uint16_t  i_istep     =   0,
            const uint16_t  i_substep   =   0,
            const uint64_t  i_isteprc   =   0   )
    {

    iv_CompId     = INITSVC_COMP_ID;
    iv_Version    = 1;
    iv_SubSection = 1;

    // Store the string in the internal buffer
    char * l_pString = (char *)allocUsrBuf( strlen(i_istepname)+1 );
    strcpy(l_pString, i_istepname );
    }

/**
 *  @brief Destructor
 *
 */
virtual ~IStepNameUserDetail() {}

private:

// Disabled
IStepNameUserDetail(const IStepNameUserDetail &);
IStepNameUserDetail & operator=(const IStepNameUserDetail &);
};

}   //  end namespace   ERRORLOG



namespace   INITSERVICE
{

using   namespace   ERRORLOG;           // IStepNameUserDetails

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


    //  apply filters
    do
    {

        //  Sanity check / dummy IStep
        if ( g_isteps[i_IStep].pti == NULL)
        {
            TRACDCOMP( g_trac_initsvc,
                       "g_isteps[%d].pti == NULL",
                       i_IStep );
            break;
        }

        TRACDCOMP( g_trac_initsvc,
                   "g_isteps[%d].numitems = 0x%x",
                   i_IStep,
                   g_isteps[i_IStep].numitems );


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
    // note, io_ptr will pass the TaskArgs struct through to runAllSteps, etc.

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
    using namespace TARGETING;
    Target* l_pTopLevel     =   NULL;
    bool    l_istepmodeflag =   false;
    TargetService& l_targetService = targetService();

    (void) l_targetService.getTopLevelTarget(l_pTopLevel);
    if (l_pTopLevel == NULL)
    {
        TRACFCOMP( g_trac_initsvc, "Top level handle was NULL" );
        l_istepmodeflag =   false;
    }
    else
    {
        l_istepmodeflag = l_pTopLevel->getAttr<ATTR_ISTEP_MODE> ();
    }


    return  l_istepmodeflag;
}


void IStepDispatcher::initIStepMode( )
{
    using namespace TARGETING;
    uint64_t    l_readData      =   0;
    Target      *l_pTopLevel    =   NULL;
    TargetService& l_targetService = targetService();

    (void) l_targetService.getTopLevelTarget(l_pTopLevel);
    if (l_pTopLevel == NULL)
    {
        TRACFCOMP( g_trac_initsvc, "Top level handle was NULL" );
        // drop through, default of attribute is is false
    }
    else
    {
        // got a pointer to Targeting, complete setting the flag
        l_readData  =   mmio_scratch_read( MMIO_SCRATCH_IPLSTEP_CONFIG );

        TRACDCOMP( g_trac_initsvc,
                "SCOM ScratchPad read, Offset 0x%x, Data 0x%llx",
                MMIO_SCRATCH_IPLSTEP_CONFIG,
                l_readData );

        // check for IStep Mode signature(s)
        if ( l_readData == ISTEP_MODE_ON_SIGNATURE )
        {
            l_pTopLevel->setAttr<ATTR_ISTEP_MODE> (true );
            TRACDCOMP( g_trac_initsvc,
                    "ISTEP_MODE attribute set to TRUE." );
        }

        if ( l_readData == ISTEP_MODE_OFF_SIGNATURE )
        {
            l_pTopLevel->setAttr<ATTR_ISTEP_MODE> ( false );
            TRACDCOMP( g_trac_initsvc,
                    "ISTEP_MODE attribute set to FALSE." );
        }
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
                           l_nextSubstep );

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
                    errlCommit( l_errl, INITSVC_COMP_ID );
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
                        errlCommit( l_errl, INITSVC_COMP_ID);
                    }

                    //  truncate IStep return status to 16 bits.
                    l_isteprc   &= 0x000000000000ffff;
                    l_istepStatus =   static_cast<uint16_t>(l_isteprc);

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
        errlCommit( l_errl, INITSVC_COMP_ID );
        assert(0);
    }

}


void    IStepDispatcher::runAllISteps( void * io_ptr )   const
{
    errlHndl_t          l_errl          =   NULL;
    uint16_t            l_IStep         =   0;
    uint16_t            l_SubStep       =   0;
    const TaskInfo      *l_pistep       =   NULL;
    uint64_t            l_progresscode  =   0;
    uint64_t            l_isteprc       =   0;

    // taskargs struct for children
    TaskArgs::TaskArgs  l_args;

    // set up pointer to our taskargs, passed in from caller
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_ptr );

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
                           "End of ISubStep 0x%x list.", l_SubStep );
                break;  // break out of inner for loop
            }

            //  @todo   placeholder until progress codes are defined and
            //          progress code driver is implemented.
            l_progresscode  =  ( (l_IStep<<16) | l_SubStep );
            InitService::getTheInstance().setProgressCode( l_progresscode );

            l_args.clear();

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


             if ( l_errl )
             {
                 TRACFCOMP( g_trac_initsvc,
                     "ISD: istep %s returned 0x%llx, errlog=%p",
                     l_pistep->taskname,
                     l_isteprc,
                     l_errl  );
                 // if we have an errorlog, break out of the inner loop
                 // and handle it.
                 break;
             }
             else
             {
                 //  Check child results for a valid nonzero return code.
                 //  If we have one, and no errorlog, then we create an
                 //  errorlog here.
                 if ( l_isteprc != 0 )
                 {
                     TRACFCOMP( g_trac_initsvc,
                                "ISD:  istep %s returned 0x%llx, no errlog",
                                l_pistep->taskname,
                                l_isteprc );

                     /*@     errorlog tag
                      *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                      *  @moduleid       ISTEP_RETURNED_ERROR_ID
                      *  @reasoncode     ISTEP_FAILED_NO_ERRLOG
                      *  @userdata1      istep / substep
                      *  @userdata2      returncode from istep
                      *
                      *  @devdesc        The Istep returned with an error,
                      *                  but there was no errorlog posted
                      *                  from the IStep. Look at user1 data
                      *                  for the istep / substep, and
                      *                  user2 data for the returned errorcode.
                      */
                     l_errl = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                             ISTEP_RETURNED_ERROR_ID,
                             INITSERVICE::ISTEP_FAILED_NO_ERRLOG,
                             ( l_IStep << 8 | l_SubStep ),
                             l_isteprc );
                     // attach the istep name to the error log
                     // @todo
                     IStepNameUserDetail   l_istepud( l_pistep->taskname );
                     l_istepud.addToLog( l_errl );
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
                   "ERROR:  istep=0x%x, substep=0x%x, isteprc=0x%x, committing errorlog and shutting down.",
                   l_IStep,
                   l_SubStep,
                   l_isteprc );
        errlCommit( l_errl, INITSVC_COMP_ID );

        // pass an error code on to extinitsvc that we are shutting down.
        pTaskArgs->postReturnCode( TASKARGS_SHUTDOWN_RC );
        // Tell the kernel to shutdown.
        shutdown( SHUTDOWN_STATUS_ISTEP_FAILED );

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
