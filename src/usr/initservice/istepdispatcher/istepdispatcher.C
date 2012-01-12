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

#include    <vfs/vfs.H>                     //  load_module
#include    <sys/task.h>                    //  tid_t, task_create, etc
#include    <sys/time.h>                    //  nanosleep
#include    <sys/misc.h>                    //  shutdown
#include    <trace/interface.H>             //  trace support
#include    <errl/errlentry.H>              //  errlHndl_t
#include    <devicefw/userif.H>             //  targeting

#include    <initservice/taskargs.H>        //  TaskArgs    structs

#include    <errl/errluserdetails.H>        //  ErrlUserDetails base class

#include    <targeting/attributes.H>        //  ISTEP_MODE attribute
#include    <targeting/entitypath.H>
#include    <targeting/target.H>
#include    <targeting/targetservice.H>

#include    "istepdispatcher.H"

#include    "splesscommon.H"

#include    <isteps/istepmasterlist.H>
#include    <targeting/util.H>


//  -----   namespace   ERRORLOG    -------------------------------------------
namespace   ERRORLOG
{
/**
 * @class IStepNameUserDetail
 *
 * report the failing IStepName to an errorlog
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

}   //  -----   end namespace   ERRORLOG    -----------------------------------


//  -----   namespace   INITSERVICE -------------------------------------------
namespace   INITSERVICE
{

using   namespace   ERRORLOG;           // IStepNameUserDetails
using   namespace   SPLESS;             // SingleStepMode

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
extern trace_desc_t *g_trac_initsvc;

/**

 * @note    SPLess PAUSE - These two constants are used in a nanosleep() call
 *          below to sleep between polls of the StatusReg.  Typically this will
 *          be about 10 ms - the actual value will be determined empirically.
 *
 */
const   uint64_t    SINGLESTEP_PAUSE_S     =   0;
const   uint64_t    SINGLESTEP_PAUSE_NS    =   10000000;

/**
 * @brief   set up _start() task entry procedure using the macro in taskargs.H
 */
TASK_ENTRY_MACRO( IStepDispatcher::getTheInstance().init );


const TaskInfo *IStepDispatcher::findTaskInfo(
                                const uint16_t i_IStep,
                                const uint16_t i_SubStep,
                                const char     *&io_rmodulename ) const
{
    const TaskInfo      *l_pistep       =   NULL;
    /**
     * @todo
     *  everything calling this should feed into the "real" istep/substep
     *  numbers ( starting at 1 ) - this routine will translate to index into
     *  the isteplists ( starting at 0 )
     *
     */
    //int16_t     l_istepIndex    =   i_IStep-1;
    //int16_t     l_substepIndex  =   i_SubStep-1;

    //assert( l_istepIndex >= 0 );
    //assert( l_substepIndex >= 0 );

    //  apply filters
    do
    {
        //  Sanity check / dummy IStep
        if ( g_isteps[i_IStep].pti == NULL)
        {
            TRACDCOMP( g_trac_initsvc,
                       "g_isteps[0x%x].pti == NULL (substep=0x%x)",
                       i_IStep,
                       i_SubStep );
            break;
        }

        TRACDCOMP( g_trac_initsvc,
                   "g_isteps[0x%x].numitems = 0x%x (substep=0x%x)",
                   i_IStep,
                   g_isteps[i_IStep].numitems,
                   i_SubStep );


        // check input range - IStep
        if  (   i_IStep >= MAX_ISTEPS   )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep 0x%x out of range. (substep=0x%x) ",
                       i_IStep,
                       i_SubStep );
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

        //  check to see if the pointer to the function is NULL.
        //  This is possible if some of the substeps aren't working yet
        //  and are just placeholders.
        if  (  g_isteps[i_IStep].pti[i_SubStep].taskfn == NULL )
        {
            TRACDCOMP( g_trac_initsvc,
                    "IStep 0x%x SubSStep 0x%x fn ptr is NULL.",
                    i_IStep,
                    i_SubStep );
            break;
        }


        l_pistep        =   &( g_isteps[i_IStep].pti[i_SubStep] );
        // find the name of the module that contains this function,
        io_rmodulename  =   VFS::module_find_name(
                                    reinterpret_cast<void*>(l_pistep->taskfn) );
        // looks good, send it back to the caller
        TRACDCOMP( g_trac_initsvc,
                   "Found TaskInfo 0x%p 0x%x 0x%x in module %s",
                   l_pistep,
                   i_IStep,
                   i_SubStep,
                   ((io_rmodulename!=NULL)?io_rmodulename:"NULL???") );


    }   while ( 0 );

    return  l_pistep;
}


void IStepDispatcher::init( void * io_ptr )
{
    // note, io_ptr will pass the TaskArgs struct through to runAllSteps, etc.

    if ( getIStepMode() )
    {
        TRACFCOMP( g_trac_initsvc,
                   "IStep single-step enable" );
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
        // printk( "IStep Mode flag = 0x%x\n", l_istepmodeflag );
    }


    return  l_istepmodeflag;
}


/**
 * @brief   Command 0: Run the requested IStep/SubStep
 *
 * param[in]    i_rcmd  -   ref to a filled in SPLessCmd struct
 * param[out]   o_sts   -   ref to a SPLessSts struct to be filled in
 *
 * @return  none
 */
void    IStepDispatcher::processSingleIStepCmd(
                                    SPLessCmd &i_rrawcmd,
                                    SPLessSts &o_rrawsts ) const
{
    errlHndl_t              l_errl          =   NULL;
    uint64_t                l_isteprc       =   NULL;
    TaskArgs::TaskArgs      l_taskargs;
    const TaskInfo          *l_pistep       =   NULL;
    //  init the command 0x00 struct to the incoming command reg values
    SPLessSingleIStepCmd    l_cmd( i_rrawcmd );
    //  create a cleared status 0x00 reg
    SPLessSingleIStepSts    l_sts;
    const char                    *l_modulename   =   NULL;



    //  look up istep+substep
    l_pistep  =   IStepDispatcher::getTheInstance().findTaskInfo(
                                                        l_cmd.istep,
                                                        l_cmd.substep,
                                                        l_modulename);

    do
    {
        if ( l_pistep == NULL )
        {
            // invalid istep, return error
            l_sts.hdr.runningbit    =   false;
            l_sts.hdr.readybit      =   true;
            l_sts.hdr.status        =   SPLESS_TASKRC_INVALID_ISTEP;
            l_sts.istep             =   l_cmd.istep;
            l_sts.substep           =   l_cmd.substep;
            l_sts.istepStatus       =   0;

            /**
             * @todo    post informational errl here.
             */
            TRACFCOMP( g_trac_initsvc,
                     "processSingleIStepCmd: ERROR: Cannot find IStep=%d, SubStep=%d",
                     l_cmd.istep,
                     l_cmd.substep );

            //  return to caller to write back to user console
            o_rrawsts.val64 =   l_sts.val64;
            break;
        }


        //  set running bit, fill in istep and substep
        l_sts.hdr.runningbit    =   true;
        l_sts.hdr.readybit      =   true;
        l_sts.hdr.status        =   0;
        l_sts.istep             =   l_cmd.istep;
        l_sts.substep           =   l_cmd.substep;
        l_sts.istepStatus       =   0;

        TRACFCOMP( g_trac_initsvc,
                 "processSingleIStepCmd: Running IStep=%d, SubStep=%d",
                 l_cmd.istep,
                 l_cmd.substep );


        //  write intermediate value back to user console
        o_rrawsts.val64 =   l_sts.val64;
        writeSts( o_rrawsts );


        /**
         * @todo    temporary - executeFn will eventually figure out and
         * load the correct module
         */
        if (    ( l_modulename != NULL )
             && ( !VFS::module_is_loaded( l_modulename ) )
             )
        {
            TRACDCOMP( g_trac_initsvc,
                    "loading module %s",
                    l_modulename );
            l_errl = VFS::module_load( l_modulename );
            if ( l_errl )
            {
                //  can't load module for istep, break out of inner loop
                //  with errl set
                TRACFCOMP( g_trac_initsvc,
                    "Could not load module %s",
                    l_modulename );

                l_sts.hdr.status    =   SPLESS_TASKRC_RETURNED_ERRLOG;
                // go ahead and commit the errorlog
                errlCommit( l_errl, INITSVC_COMP_ID );

                // failed to load module, return error
                 l_sts.hdr.runningbit    =   false;
                 l_sts.hdr.readybit      =   true;
                 l_sts.hdr.status        =   SPLESS_TASKRC_FAIL_LOADMODULE;
                 l_sts.istep             =   l_cmd.istep;
                 l_sts.substep           =   l_cmd.substep;
                 l_sts.istepStatus       =   0;

                 //  return to caller to write back to user console
                 o_rrawsts.val64 =   l_sts.val64;

                break;
            }
        }

        /**
         * @todo   placeholder - set progress code before starting
         * This will not be finalized until the progress code driver
         * is designed and implemented.
         */
        uint64_t l_progresscode  =  ( (l_cmd.istep<<16) | l_cmd.substep );
        InitService::getTheInstance().setProgressCode( l_progresscode );


        // clear the TaskArgs struct
        l_taskargs.clear();

        // clear the status struct for the next step
        l_sts.val64 =   0;

        //  launch the istep
        l_errl = InitService::getTheInstance().executeFn( l_pistep,
                &l_taskargs );
        //  filter errors returning from executeFn
        if ( l_errl )
        {
            //  handle an errorlog from the parent.  This means the
            //  launch failed, set the task Status to Bad.
            //  no need to process child info, thus the else.
            //  set the taskStatus to LAUNCH_FAIL; this will fall
            //  out the bottom and be written to SPLESS Status
            l_sts.hdr.status  =   SPLESS_TASKRC_LAUNCH_FAIL;
            errlCommit( l_errl, INITSVC_COMP_ID );
        }
        else
        {
            //  process information returned from the IStep.
            //  make local copies of the info; this has a secondary
            //  effect of clearing the errorlog pointer inside
            //  the TaskArgs  struct.
            l_isteprc   =   l_taskargs.getReturnCode();     // local copy
            l_errl      =   l_taskargs.getErrorLog();       // local copy

            //  check for child errorlog
            if ( l_errl )
            {
                //  tell the user that the IStep returned an errorlog
                l_sts.hdr.status    =   SPLESS_TASKRC_RETURNED_ERRLOG;
                // go ahead and commit the child errorlog
                errlCommit( l_errl, INITSVC_COMP_ID );
            }

            //  truncate IStep return status to 32 bits.
            l_isteprc   &= SPLESS_SINGLE_STEP_STS_MASK;
            l_sts.istepStatus =   static_cast<uint32_t>(l_isteprc);
        }   // end else parent errlog

        //  task status and  istepStatus should be set correctly now,
        //  send it to the user console.
        //  clear runningbit, report status
        //  set running bit, fill in istep and substep
        l_sts.hdr.runningbit    =   false;
        l_sts.hdr.readybit      =   true;
        // l_sts.hdr.seqnum        =   i_seqnum;
        // task status set above
        l_sts.istep             =   l_cmd.istep;
        l_sts.substep           =   l_cmd.substep;
        // istepStatus set above


        /**
         * @todo    post informational errl here.
         */

        //  write to status reg, return to caller to write to user console
        o_rrawsts.val64 =   l_sts.val64;

        break;

    } while(0);

}


/**
 * @brief  singleStepISteps
 *
 * Stop and wait for SP to send the next IStep to run.  Run that, then
 * wait for the next one.
 * This is not expected to return - errors etc are sent to the user to
 * handle.
 *
 * @param[in,out] io_ptr   -   pointer to any args passed in from
 *                             ExtInitSvc.  This may be a pointer to an
 *                             TaskArgs struct (or something else) which
 *                             can be filled out on return
 *
 * @return none
 */
void    IStepDispatcher::singleStepISteps( void *  io_ptr )
{
    SPLessCmd           l_cmd;
    SPLessSts           l_sts;
    uint8_t             l_seqnum        =   0;

    mutex_lock(&iv_poll_mutex);  // make sure this is only poller

    // initialize command reg
    l_cmd.val64 =   0;
    writeCmd( l_cmd );

    //  init status reg, enable ready bit
    l_sts.val64 =   0;
    l_sts.hdr.readybit  =   true;
    writeSts( l_sts );

    //
    //  @note Start the polling loop.
    //  Currently this has no exit, user should reset the machine and/or
    //  load the payload, which will wipe HostBoot from memory.
    //  Loop forever, unless something Very Bad happens.
    //
    while( 1 )
    {

        //  read command register from user console
        readCmd( l_cmd );

        // get the sequence number
        l_seqnum    =   l_cmd.hdr.seqnum;

        //  process any pending commands
        if ( l_cmd.hdr.gobit )
        {
            switch( l_cmd.hdr.cmdnum )
            {
                case SPLESS_SINGLE_ISTEP_CMD:
                    mutex_unlock(&iv_poll_mutex);
                    // command 0:  run istep/substep
                    processSingleIStepCmd( l_cmd, l_sts  );
                    mutex_lock(&iv_poll_mutex);
                    break;

                case SPLESS_RESUME_ISTEP_CMD: // not at break point here
                    l_sts.hdr.status    =   SPLESS_NOT_AT_BREAK_POINT;
                    break;

                default:
                    l_sts.hdr.status    =   SPLESS_INVALID_COMMAND;
            }   // endif switch

            l_sts.hdr.seqnum    =   l_seqnum;
            //  status should be set now, write to Status Reg.
            writeSts( l_sts );

            // clear command reg, including go bit (i.e. set to false)
            l_cmd.val64 =   0;
            writeCmd( l_cmd );
        }   //  endif   gobit


        // sleep, and wait for user to give us something else to do.
        /**
         * @todo Need a common method of doing delays in HostBoot
         * @VBU workaround
         */
        // Don't delay as long in VBU because it will take VERY long to
        // run the simulator
        if( TARGETING::is_vpo() )
        {
            // VBU delay per Patrick
            nanosleep(0,TEN_CTX_SWITCHES_NS);
        }
        else
        {
            nanosleep( SINGLESTEP_PAUSE_S, SINGLESTEP_PAUSE_NS );
        }
    }   //  endwhile


    //  @note
    //  Fell out of loop, clear sts reg and turn off readybit
    //  Currently this will never be reached.  Later there may be
    //  a reason to break out of the loop, if this happens we want to
    //  disable the ready bit so the user knows.
    l_sts.val64 =   0;
    l_sts.hdr.status    =   SPLESS_TASKRC_TERMINATED;
    l_sts.hdr.seqnum    =   l_seqnum;
    writeSts( l_sts );
    mutex_unlock(&iv_poll_mutex);

}


void    IStepDispatcher::runAllISteps( void * io_ptr )   const
{
    errlHndl_t          l_errl          =   NULL;
    uint16_t            l_IStep         =   0;
    uint16_t            l_SubStep       =   0;
    const TaskInfo      *l_pistep       =   NULL;
    uint64_t            l_progresscode  =   0;
    uint64_t            l_isteprc       =   0;
    const   char        *l_modulename   =   NULL;

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
            l_pistep    =   findTaskInfo( l_IStep,
                                          l_SubStep,
                                          l_modulename );
            if ( l_pistep == NULL )
            {

                break;  // break out of inner for loop
            }

            /**
             * @todo    temporary - executeFn will eventually figure out and
             * load the correct module
             */
            if (    ( l_modulename != NULL )
                 && ( !VFS::module_is_loaded( l_modulename ) )
                 )
            {
                TRACDCOMP( g_trac_initsvc,
                        "loading module %s",
                        l_modulename );
                l_errl = VFS::module_load( l_modulename );
                if ( l_errl )
                {
                    //  can't load module for istep, break out of inner loop
                    //  with errl set
                    TRACFCOMP( g_trac_initsvc,
                        "Could not load module %s",
                        l_modulename );

                    break;
                }
            }

            //  @todo   placeholder until progress codes are defined and
            //          progress code driver is implemented.
            l_progresscode  =  ( (l_IStep<<16) | l_SubStep );
            InitService::getTheInstance().setProgressCode( l_progresscode );

            //  print out what we are running
            TRACFCOMP( g_trac_initsvc,
                "Running IStep %s",
                l_pistep->taskname );


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
        //Tell initservice to perform shutdown sequence
        InitService::getTheInstance().doShutdown( SHUTDOWN_STATUS_ISTEP_FAILED );

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

void IStepDispatcher::handleBreakPoint(const fapi::Target & i_target, uint64_t i_info)
{
    SPLessCmd   l_cmd;
    SPLessSts   l_sts;
    uint8_t     l_seqnum        = 0;

    // need to be the only poller
    mutex_lock(&iv_poll_mutex);

    // init command reg
    l_cmd.val64 = 0;
    writeCmd ( l_cmd );

    // init status reg, enable ready bit
    l_sts.val64 = 0;
    l_sts.hdr.readybit = true;
    writeSts( l_sts );

    // TODO Tell the outside world that a break point has been hit?
    // TODO send i_target & i_info

    // Poll for cmd to resume
    while(1)
    {
        readCmd( l_cmd );
        l_seqnum = l_cmd.hdr.seqnum;

        if( l_cmd.hdr.gobit)
        {
            // only expect this command
            if (l_cmd.hdr.cmdnum == SPLESS_RESUME_ISTEP_CMD)
            {
                l_sts.hdr.seqnum = l_seqnum;
                writeSts( l_sts );
                l_cmd.val64 = 0;
                writeCmd( l_cmd );
                break; // return to continue istep
            }
            else // all other commands are not valid here.
            {
                l_sts.hdr.status = SPLESS_AT_BREAK_POINT;

                // write status
                l_sts.hdr.seqnum = l_seqnum;
                writeSts( l_sts );

                // clear cmd reg, including go bit
                l_cmd.val64 = 0;
                writeCmd( l_cmd );
            }
        }



        // TODO want to do the same kind fo delay as IStepDispatcher::singleStepISteps()
        /**
         * @todo Need a common method of doing delays in HostBoot
         * @VBU workaround
         */
        // Don't delay as long in VBU because it will take VERY long to
        // run the simulator
        if( TARGETING::is_vpo() )
        {
            // VBU delay per Patrick
            nanosleep(0,TEN_CTX_SWITCHES_NS);
        }
        else
        {
            nanosleep( SINGLESTEP_PAUSE_S, SINGLESTEP_PAUSE_NS );
        }
    }
    mutex_unlock(&iv_poll_mutex);
}

void iStepBreakPoint(const fapi::Target & i_target, uint64_t i_info)
{
    IStepDispatcher::getTheInstance().handleBreakPoint(i_target, i_info);
}

} // namespace
