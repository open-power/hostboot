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


#include    <kernel/console.H>              // printk status
//  turn on clearAllBuffers()
#define     __HIDDEN_TRACEIF_CLEARBUFFER

#include    <vfs/vfs.H>                     //  load_module
#include    <sys/task.h>                    //  tid_t, task_create, etc
#include    <sys/time.h>                    //  nanosleep
#include    <sys/misc.h>                    //  shutdown

#include    <trace/interface.H>             //  trace support

#include    <errl/errlentry.H>              //  errlHndl_t
#include    <devicefw/userif.H>             //  targeting

#include    <initservice/isteps_trace.H>    //  ISTEPS_TRACE buffer
#include    <initservice/initsvcudistep.H>  //  InitSvcUserDetailsIstep
#include    <initservice/taskargs.H>        // TASK_ENTRY_MACRO


#include    <targeting/attributes.H>        //  ISTEP_MODE attribute
#include    <targeting/entitypath.H>
#include    <targeting/target.H>
#include    <targeting/targetservice.H>

#include    <mbox/mbox_queues.H>            // HB_ISTEP_MSGQ
#include    <mbox/mboxif.H>                 // register mailbox

#include    "istepdispatcher.H"

#include    "splesscommon.H"

#include    <isteps/istepmasterlist.H>
#include    <targeting/util.H>

//  -----   namespace   ISTEPS_TRACE    ---------------------------------------
namespace ISTEPS_TRACE
{

//  declare storage for isteps_trace!
trace_desc_t *g_trac_isteps_trace   =   NULL;

}   //  end namespace
//  -----   end namespace   ISTEPS_TRACE    -----------------------------------


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
 * _start() task entry procedure using the macro in taskargs.H
 */
TASK_ENTRY_MACRO( IStepDispatcher::getTheInstance().init );




void IStepDispatcher::init( errlHndl_t  &io_rtaskRetErrl )
{
    errlHndl_t  l_errl  =   NULL;

    // initialize (and declare) ISTEPS_TRACE here, the rest of the isteps will use it.
    ISTEPS_TRACE::g_trac_isteps_trace = NULL;

    printk( "IstepDispatcher entry.\n" );

    TRACFCOMP( g_trac_initsvc,
            "IStep Dispatcher entry." );

    TRAC_INIT(&ISTEPS_TRACE::g_trac_isteps_trace, "ISTEPS_TRACE", 2048 );


    if ( getIStepMode() == true )
    {
        printk( "IStep single-step\n" );
        TRACFCOMP( g_trac_initsvc,
                   "IStep single-step" );

        if  ( SPLESS::SPLessAttached( ) )
        {
            // SPless user console is attached,
            //  launch SPTask.

            TRACFCOMP( g_trac_initsvc,
                    "IStep single-step enable (SPLESS)" );

            tid_t   l_spTaskTid   = task_create( spTask, iv_msgQ );
            //  should never happen...
            assert( l_spTaskTid > 0 );

            // IStep single-step
            singleStepISteps( io_rtaskRetErrl );
        }
        else
        {
            TRACFCOMP( g_trac_initsvc,
                    "IStep single-step enable (FSP)" );

            //  register message Q with FSP Mailbox
            l_errl  =   MBOX::msgq_register(
                                    MBOX::HB_ISTEP_MSGQ,
                                    iv_msgQ ) ;
            if ( l_errl )
            {
                TRACFCOMP( g_trac_initsvc,
                        "ERROR:  Failed to register mailbox, terminating" );
                // fall through and report errorlog
                io_rtaskRetErrl  =   l_errl;
            }
            else
            {
                // IStep single-step
                singleStepISteps( io_rtaskRetErrl );
            }
        }
    }
    else
    {
        printk( "IStep run-all\n" );

        TRACFCOMP( g_trac_initsvc,
                   "IStep run all" );

        //  Run all the ISteps sequentially
        runAllISteps( io_rtaskRetErrl );
    }   // endelse


    TRACFCOMP( g_trac_initsvc,
               "IStepDispatcher finished.");

    printk( "IStepDispatcher exit.\n" );

    task_end2( io_rtaskRetErrl );
}

void    IStepDispatcher::runAllISteps( errlHndl_t   &io_rtaskRetErrl )
{
    errlHndl_t          l_errl          =   NULL;
    uint32_t            l_IStep         =   0;
    uint32_t            l_SubStep       =   0;
    const TaskInfo      *l_pistep       =   NULL;
    uint64_t            l_progresscode  =   0;


    for (   l_IStep=0;
            l_IStep<INITSERVICE::MaxISteps;
            l_IStep++ )
    {
        TRACDCOMP( g_trac_initsvc,
                        "runAllISteps: IStep %d: %d entries",
                        l_IStep,
                        g_isteps[l_IStep].numitems );

        for (   l_SubStep=0;
                l_SubStep < g_isteps[l_IStep].numitems;
                l_SubStep++)
        {
            /**
             *  @todo refactor - replace the following block with
             *      processSingleIStepCmd()
             */

            l_pistep    =   findTaskInfo(
                                    l_IStep,
                                    l_SubStep );
            if ( l_pistep == NULL )
            {
                // continue to end of list
                continue;
            }

            //  @todo   placeholder until progress codes are defined and
            //          progress code driver is implemented.
            l_progresscode  =  0;
            InitService::getTheInstance().setProgressCode( l_progresscode );

            //  print out what we are running
            TRACFCOMP( g_trac_initsvc,
                    "IStepDisp: Run IStep %d.%d %s",
                    l_IStep,
                    l_SubStep,
                    l_pistep->taskname );

            l_errl = InitService::getTheInstance().executeFn(
                                                        l_pistep,
                                                        NULL );

            // check for errors
            if ( l_errl )
            {
                TRACFCOMP( g_trac_initsvc,
                        "IStepDisp: istep %s returned errlog=%p",
                        l_pistep->taskname,
                        l_errl  );
                // if we have an errorlog, break out of the inner loop
                // and handle it.
                break;
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

    //
    if  ( l_errl )
    {
        TRACFCOMP( g_trac_initsvc,
            "IStepDisp ERROR:  errorlog %p",
            l_errl );

        // return to _start() with the errorlog set, parent should do shutdown
        io_rtaskRetErrl =   l_errl;
    }

    //  return to init with io_rtaskRetErrl set
}


void    IStepDispatcher::singleStepISteps( errlHndl_t   &io_rtaskRetErrl )
{
    SPLESS::SPLessSts   l_StsReg;
    uint32_t    l_Type      =   0;
    uint32_t    l_IStep     =   0;
    uint32_t    l_Substep   =   0;
    bool        l_quitflag  =   false;
    uint32_t    l_RetSts    =   0;
    errlHndl_t  l_errl      =   NULL;
    uint32_t    l_PLID      =   0;

    //  tell VPO and Simics that we're ready
    l_StsReg.hdr.readybit   =   1;
    SPLESS::writeSts( l_StsReg );

    mutex_lock(&iv_poll_mutex);  // make sure this is only poller

    while ( 1 )
    {
        TRACDCOMP( g_trac_initsvc,
                "IStepDisp wait for message." );

        //  wait for message from FSP or Dispatcher
        iv_pMsg  =   msg_wait( iv_msgQ );

        //  unblocked
        if ( msg_is_async( iv_pMsg ) )
        {
            //  should not receive async messages here, drop it, post errorlog
            //  and go back to waiting.
            TRACFCOMP( g_trac_initsvc,
                    "singleStepISteps: ERROR async msg type 0x%x, msg 0x%x.%x",
                    iv_pMsg->type,
                    static_cast<uint32_t>( iv_pMsg->data[0] >> 32 ),
                    static_cast<uint32_t>( iv_pMsg->data[0] & 0xffffffff ) );

            /*@     errorlog tag
             *  @errortype      ERRL_SEV_INFORMATIONAL
             *  @moduleid       BASE_INITSVC_MOD_ID
             *  @reasoncode     ISTEP_SINGLESTEP_ASYNC_RCVD
             *  @userdata1      type of packet
             *  @userdata2      first data word
             *
             *  @devdesc        IStepDisp was expecting a synchronous message
             *                  and received an asynchonous message.
             *
             */
            errlHndl_t  l_errlAsync = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                            INITSERVICE::BASE_INITSVC_MOD_ID,
                                            INITSERVICE::ISTEP_SINGLESTEP_ASYNC_RCVD,
                                            iv_pMsg->type,
                                            iv_pMsg->data[0] );

            errlCommit( l_errlAsync, INITSVC_COMP_ID );

            msg_free(iv_pMsg);
            iv_pMsg =    NULL;

            continue;
        }


        l_Type    = iv_pMsg->type;
        l_IStep   = static_cast<uint32_t>( iv_pMsg->data[0] >>32 ) ;
        l_Substep = static_cast<uint32_t>( iv_pMsg->data[0] & 0x0FFFFFFFF );

        TRACDCOMP( g_trac_initsvc,
                "IStepDisp recv msg type 0x%x, 0x%x.%x",
                l_Type,
                l_IStep,
                l_Substep  );

        //  Clear Status and PLID fields for response msg
        l_RetSts    =   0;
        l_PLID      =   0;

        switch( l_Type )
        {
            case SINGLE_STEP_TYPE:
                mutex_unlock(&iv_poll_mutex);
                // command 0:  run istep/substep
                TRACDCOMP( g_trac_initsvc,
                        "Run istep %d.%d ",
                        l_IStep,
                        l_Substep );
                l_errl  =   processSingleIStepCmd( l_IStep, l_Substep, l_RetSts );
                mutex_lock(&iv_poll_mutex);
                break;

            case BREAKPOINT_TYPE: // not at break point here
                TRACDCOMP( g_trac_initsvc,
                        "Not at break point."  );
                l_RetSts    =   SPLESS_NOT_AT_BREAK_POINT;
                break;

            case CLEAR_TRACE_TYPE:
                TRAC_CLEAR_BUFFERS();
                TRACFCOMP( g_trac_initsvc,
                        "Cleared all trace buffers." );
                l_RetSts    =   SPLESS_TRACE_BUFFERS_CLEARED;
                break;

            case SHUTDOWN_TYPE:
                TRACFCOMP( g_trac_initsvc,
                        "Shutting down HostBoot. "  );
                l_RetSts    =   SPLESS_SHUTTING_DOWN;
                l_quitflag            =   true;
                break;

            default:
                TRACFCOMP( g_trac_initsvc,
                        "ERROR: invalid command 0x%x ",
                        l_Type );
                l_RetSts    =   SPLESS_INVALID_COMMAND;
                break;
        }   // end switch

        if ( l_errl )
        {
            //  tell the user console that the IStep returned an errorlog
            l_RetSts    =   SPLESS_TASKRC_RETURNED_ERRLOG;
            //  get the platform log identifier (PLID) to send to FSP
            l_PLID      =   l_errl->plid();

            // go ahead and commit the child errorlog
            errlCommit( l_errl, INITSVC_COMP_ID );
        }

        iv_pMsg->type    =   l_Type;
        // Return l_RetSts as hi word of data[0]
        // Return l_PLID as lo word of data[0]
        iv_pMsg->data[0]    =
                ( static_cast<uint64_t>( l_RetSts ) << 32 ) |
                  static_cast<uint64_t>( l_PLID )  ;

        iv_pMsg->data[1]    =   0;
        iv_pMsg->extra_data =   NULL;

        TRACDCOMP( g_trac_initsvc,
                "IStepDisp send msg type 0x%x, 0x%x.%x",
                iv_pMsg->type,
                static_cast<uint32_t>( iv_pMsg->data[0] >> 32),
                static_cast<uint32_t>( iv_pMsg->data[0] & 0xFFFFFFFF ));

        //  send status back
        msg_respond( iv_msgQ, iv_pMsg );


        if  ( l_quitflag  ==  true )
        {
            //  shutdown command issued, break out of loop

            /*@     errorlog tag
             *  @errortype      ERRL_SEV_INFORMATIONAL
             *  @moduleid       BASE_INITSVC_MOD_ID
             *  @reasoncode     ISTEP_SINGLESTEP_SHUTDOWN
             *  @userdata1      0
             *  @userdata2      0
             *
             *  @devdesc        hb-istep terminated
             *
             */
            l_errl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    INITSERVICE::BASE_INITSVC_MOD_ID,
                    INITSERVICE::ISTEP_SINGLESTEP_SHUTDOWN,
                    0,
                    0 );
            break;
        }

    }   // end  while

    // fell out of loop, return with rtaskRetErrl set
    mutex_unlock(&iv_poll_mutex);
    io_rtaskRetErrl =   l_errl;
}


errlHndl_t  IStepDispatcher::processSingleIStepCmd(
                                    const   uint32_t    i_IStep,
                                    const   uint32_t    i_Substep,
                                    uint32_t            &o_rSts )
{
    errlHndl_t              l_errl          =   NULL;
    const TaskInfo          *l_pistep       =   NULL;

    o_rSts    =   0;

    //  look up istep+substep
    l_pistep  =   IStepDispatcher::getTheInstance().findTaskInfo(
                                                            i_IStep,
                                                            i_Substep );
    do
    {
        if ( l_pistep == NULL )
        {
            // invalid istep, return error
            TRACDCOMP( g_trac_initsvc,
                    "processSingleIStepCmd: Invalid IStep %d.%d\n",
                    i_IStep,
                    i_Substep  );

            o_rSts  =   SPLESS_INVALID_COMMAND;
            break;
        }

        /**
         * @todo   placeholder - set progress code before starting
         * This will not be finalized until the progress code driver
         * is designed and implemented.
         */
        uint64_t l_progresscode  =  0;
        InitService::getTheInstance().setProgressCode( l_progresscode );


        TRACFCOMP( g_trac_initsvc,
                "processSingleIStepCmd: Run IStep=%d.%d %s",
                i_IStep,
                i_Substep,
                l_pistep->taskname );

        //  launch the istep
        l_errl = InitService::getTheInstance().executeFn(
                l_pistep,
                NULL );

        if ( l_errl )
        {
            //  @todo    post informational errl here?

            break;
        }

    } while(0);


    return  l_errl;
}


const TaskInfo *IStepDispatcher::findTaskInfo(
                                const uint32_t i_IStep,
                                const uint32_t i_SubStep ) const
{
    //  default return is NULL
    const TaskInfo      *l_pistep       =   NULL;
    /**
     * @todo
     *  everything calling this should feed into the "real" istep/substep
     *  numbers ( starting at 1 ) - this routine should translate to index into
     *  the isteplists ( starting at 0 )
     *
     *      int32_t     l_istepIndex    =   i_IStep-1;
     *      int32_t     l_substepIndex  =   i_SubStep-1;
     *
     *      assert( l_istepIndex >= 0 );
     *      assert( l_substepIndex >= 0 );
     */

    //  apply filters
    do
    {
        //  Sanity check / dummy IStep
        if ( g_isteps[i_IStep].pti == NULL)
        {
            TRACDCOMP( g_trac_initsvc,
                       "g_isteps[%d].pti == NULL (substep=%d)",
                       i_IStep,
                       i_SubStep );
            break;
        }

        // check input range - IStep
        if  (   i_IStep >= INITSERVICE::MaxISteps   )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep %d out of range. (substep=%d) ",
                       i_IStep,
                       i_SubStep );
            break;      // break out with l_pistep set to NULL
        }

        //  check input range - ISubStep
        if  (   i_SubStep >= g_isteps[i_IStep].numitems )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep %d Substep %d out of range.",
                       i_IStep,
                       i_SubStep );
            break;      // break out with l_pistep set to NULL
        }

        //   check for end of list.
        if ( g_isteps[i_IStep].pti[i_SubStep].taskflags.task_type
                == END_TASK_LIST )
        {
            TRACDCOMP( g_trac_initsvc,
                       "IStep %d SubStep %d task_type==END_TASK_LIST.",
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
                    "IStep %d SubStep %d fn ptr is NULL.",
                    i_IStep,
                    i_SubStep );
            break;
        }


        //  we're good, set the istep & return it to caller
        l_pistep        =   &( g_isteps[i_IStep].pti[i_SubStep] );

    }   while ( 0 );

    return  l_pistep;
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


void IStepDispatcher::handleBreakPoint( uint32_t i_info )
{
    msg_t       *l_pBpMsg   =   msg_allocate();
    errlHndl_t  l_errl      =   NULL;

    // need to be the only poller
    mutex_lock(&iv_poll_mutex);


    l_pBpMsg->type       =    BREAKPOINT_TYPE;
    l_pBpMsg->data[0]    =
            ( static_cast<uint64_t>( i_info ) << 32 ) |
            static_cast<uint64_t>( 0 )  ;
    l_pBpMsg->data[1]    =   0;
    l_pBpMsg->extra_data =   NULL;

    // send new message to FSP
    TRACDCOMP( g_trac_initsvc,
            "handleBreakPoint: FSP: send sts type 0x%x, msg 0x%x.%x",
            l_pBpMsg->type,
            static_cast<uint32_t>( l_pBpMsg->data[0] >> 32 ),
            static_cast<uint32_t>( l_pBpMsg->data[0] & 0xffffffff ) );

    // send status to FSP
    l_errl  =   MBOX::sendrecv( MBOX::HB_ISTEP_MSGQ, l_pBpMsg );
    if ( l_errl )
    {
        TRACFCOMP( g_trac_initsvc,
                "handleBreakPoint: ERROR on MBOX sendrecv" );
        errlCommit( l_errl, INITSVC_COMP_ID );

        //  If sendrecv fails for some reason, error will be logged and
        //  breakpoint will resume anyway.
    }

    // unblocked

    TRACDCOMP( g_trac_initsvc,
            "handleBreakPoint exit: receive msg type 0x%x, msg 0x%x.%x",
            l_pBpMsg->type,
            static_cast<uint32_t>( l_pBpMsg->data[0] >> 32 ),
            static_cast<uint32_t>( l_pBpMsg->data[0] & 0xffffffff ) );

    msg_free( l_pBpMsg  );
    mutex_unlock(&iv_poll_mutex);
}


void IStepDispatcher::handleSPlessBreakPoint( uint32_t i_info )
{

    TRACDCOMP( g_trac_initsvc,
            "handleBreakPoint: hijacking message Q" );

    // need to be the only poller
    mutex_lock(&iv_poll_mutex);


    iv_pMsg->type       =    BREAKPOINT_TYPE;
    iv_pMsg->data[0]    =
            ( static_cast<uint64_t>( i_info ) << 32 ) |
            static_cast<uint64_t>( 0 )  ;
    iv_pMsg->data[1]    =   0;
    iv_pMsg->extra_data =   NULL;

    TRACDCOMP( g_trac_initsvc,
            "handleBreakPoint: send sts msg type 0x%x, msg 0x%x.%x",
            iv_pMsg->type,
            static_cast<uint32_t>( iv_pMsg->data[0] >> 32 ),
            static_cast<uint32_t>( iv_pMsg->data[0] & 0xffffffff ) );

    //  respond to SPtask
    msg_respond( iv_msgQ, iv_pMsg );

    // Poll for cmd to resume
    while( 1 )
    {

        //  wait for message from SPtask
        iv_pMsg  =   msg_wait( iv_msgQ );

        //  unblocked

        if ( msg_is_async( iv_pMsg ) )
        {
            //  should not receive async messages here, drop it, post errorlog
            //  and go back to waiting.
            TRACFCOMP( g_trac_initsvc,
                    "handleBreakPoint: ERROR async msg type 0x%x, msg 0x%x.%x",
                    iv_pMsg->type,
                    static_cast<uint32_t>( iv_pMsg->data[0] >> 32 ),
                    static_cast<uint32_t>( iv_pMsg->data[0] & 0xffffffff ) );

            /*@     errorlog tag
             *  @errortype      ERRL_SEV_INFORMATIONAL
             *  @moduleid       BASE_INITSVC_MOD_ID
             *  @reasoncode     ISTEP_SINGLESTEP_ASYNC_RCVD
             *  @userdata1      type of packet
             *  @userdata2      first data word
             *
             *  @devdesc        IStepDisp was expecting a synchronous message
             *                  and received an asynchonous message.
             *
             */
            errlHndl_t  l_errlAsync = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    INITSERVICE::BASE_INITSVC_MOD_ID,
                                    INITSERVICE::ISTEP_SINGLESTEP_ASYNC_RCVD,
                                    iv_pMsg->type,
                                    iv_pMsg->data[0] );

            errlCommit( l_errlAsync, INITSVC_COMP_ID );

            msg_free( iv_pMsg );
            iv_pMsg =    NULL;
            continue;
        }

        TRACDCOMP( g_trac_initsvc,
                "handleBreakPoint: receive msg type 0x%x, msg 0x%x.%x",
                iv_pMsg->type,
                static_cast<uint32_t>( iv_pMsg->data[0] >> 32 ),
                static_cast<uint32_t>( iv_pMsg->data[0] & 0xffffffff ) );

            // only expect this command
            if ( iv_pMsg->type  ==  BREAKPOINT_TYPE )
            {
                // correct response, return to istep
                break;
            }
            else
            {
                // all other commands are not valid here, return the same status
                iv_pMsg->type       =   BREAKPOINT_TYPE;
                iv_pMsg->data[0]    =
                        ( static_cast<uint64_t>( i_info ) << 32 ) |
                        static_cast<uint64_t>( 0 )  ;
                iv_pMsg->data[1]    =   0;
                iv_pMsg->extra_data =   NULL;

                TRACDCOMP( g_trac_initsvc,
                        "handleBreakPoint: send sts msg type 0x%x, msg 0x%x.%x",
                        iv_pMsg->type,
                        static_cast<uint32_t>( iv_pMsg->data[0] >> 32 ),
                        static_cast<uint32_t>( iv_pMsg->data[0] & 0xffffffff ) );

                //  reply back to SPLEss
                msg_respond( iv_msgQ, iv_pMsg );
            }   // end else
        }   // end while

    mutex_unlock(&iv_poll_mutex);
}

// route to SPless or FSP depending on what's attached
void iStepBreakPoint(uint32_t i_info)
{
    if ( SPLESS::SPLessAttached() )
    {
        IStepDispatcher::getTheInstance().handleSPlessBreakPoint( i_info );
    }
    else
    {
        IStepDispatcher::getTheInstance().handleBreakPoint( i_info );
    }
}


IStepDispatcher::IStepDispatcher()
: iv_sts()
{
    SPLESS::initIStepMode();
    mutex_init(&iv_poll_mutex);

    // init mailbox / message Q.
    iv_msgQ             =   msg_q_create();

}


IStepDispatcher::~IStepDispatcher()
{ }


} // namespace
