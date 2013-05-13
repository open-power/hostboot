/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/istepdispatcher.C $       */
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

// for VFS::module_load
#include <vfs/vfs.H>

#include    <sys/task.h>                    //  tid_t, task_create, etc

#include    <errl/errlentry.H>              //  errlHndl_t

#include    <devicefw/userif.H>             //  targeting

#include    <initservice/isteps_trace.H>    //  ISTEPS_TRACE buffer
#include    <initservice/initsvcudistep.H>  //  InitSvcUserDetailsIstep
#include    <initservice/taskargs.H>        //  TASK_ENTRY_MACRO

#include    <targeting/common/attributes.H> //  ISTEP_MODE attribute
#include    <targeting/common/targetservice.H>
#include    <targeting/attrsync.H>


#include    <establish_system_smp.H>

#include    <hwpf/plat/fapiPlatAttributeService.H>

#include    <mbox/mbox_queues.H>            // HB_ISTEP_MSGQ
#include    <mbox/mboxif.H>                 // register mailbox

#include    <isteps/istepmasterlist.H>
#include    <hwas/common/deconfigGard.H>

#include    "istepdispatcher.H"
#include    "istepWorker.H"
#include    "istep_mbox_msgs.H"

#include    "splesscommon.H"

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

const MBOX::queue_id_t HWSVRQ = MBOX::IPL_SERVICE_QUEUE;

/**
 * _start() task entry procedure using the macro in taskargs.H
 */
TASK_ENTRY_MACRO( IStepDispatcher::getTheInstance().init );

// ----------------------------------------------------------------------------
// IstepDispatcher()
// ----------------------------------------------------------------------------
IStepDispatcher::IStepDispatcher ()
    : iv_workerMsg( NULL )
{
    mutex_init( &iv_bkPtMutex );
    mutex_init( &iv_syncMutex );
    mutex_init( &iv_stepMutex );
    sync_cond_init( &iv_syncHit );

    iv_curIStep = 0x0;
    iv_curSubStep = 0x0;
    iv_sync = false;

    // Save flag indicating whether we're in MPIPL mode
    iv_mpipl_mode = checkMpiplMode();
    TRACFCOMP( g_trac_initsvc, "MPIPL mode = %u",
        iv_mpipl_mode );

    // init mailbox / message Q.
    iv_msgQ = msg_q_create();
}


// ----------------------------------------------------------------------------
// ~IstepDispatcher()
// ----------------------------------------------------------------------------
IStepDispatcher::~IStepDispatcher ()
{
}


// ----------------------------------------------------------------------------
// IstepDispatcher::getTheInstance()
// ----------------------------------------------------------------------------
IStepDispatcher& IStepDispatcher::getTheInstance ()
{
    return Singleton<IStepDispatcher>::instance();
}


// ----------------------------------------------------------------------------
// IStepDispatcher::init()
// ----------------------------------------------------------------------------
void IStepDispatcher::init ( errlHndl_t &io_rtaskRetErrl )
{
    errlHndl_t err = NULL;

    // initialize (and declare) ISTEPS_TRACE here, the rest of the isteps will
    // use it.
    ISTEPS_TRACE::g_trac_isteps_trace = NULL;
    TRAC_INIT(&ISTEPS_TRACE::g_trac_isteps_trace, "ISTEPS_TRACE", 2*KILOBYTE );

    printk( "IstepDispatcher entry.\n" );
    TRACFCOMP( g_trac_initsvc,
               "IStep Dispatcher entry." );

    do
    {
        if( !spLess() )
        {
            //  register message Q with FSP Mailbox - only if Fsp attached.
            err = MBOX::msgq_register( MBOX::HB_ISTEP_MSGQ,
                                       iv_msgQ );

            if( err )
            {
                break;
            }
        }

        // Spawn off the Worker thread
        tid_t l_workerTid = task_create( startIStepWorkerThread,
                                         iv_msgQ );
        assert( l_workerTid > 0 );

        // Check for SPLess operation in istep mode
        if( spLess() && getIStepMode())
        {
            // SPless user console is attached,
            //  launch SPTask.
            TRACFCOMP( g_trac_initsvc,
                       "IStep single-step enable (SPLESS)" );

            tid_t l_spTaskTid = task_create( spTask,
                                             iv_msgQ );
            assert( l_spTaskTid > 0 );
        }

        if( err )
        {
            TRACFCOMP( g_trac_initsvc,
                       "ERROR:  Failed to register mailbox, terminating" );

            break;
        }

        if( getIStepMode() )
        {
            printk( "IStep single-step\n" );
            TRACFCOMP( g_trac_initsvc,
                       "IStep single-step" );

            err = msgHndlr();
            if( err )
            {
                break;
            }
        }
        else
        {
            printk( "IStep run-all\n" );
            TRACFCOMP( g_trac_initsvc,
                       "IStep run all" );

            if(!spLess())
            {
                // Read the attribute indicating if the FSP has overrides
                // and get the overrides if it does
                uint8_t l_attrOverridesExist = 0;
                TARGETING::Target* l_pTopLevelTarget = NULL;
                TARGETING::targetService().getTopLevelTarget(l_pTopLevelTarget);

                if (l_pTopLevelTarget == NULL)
                {
                    TRACFCOMP(g_trac_initsvc,
                              "init: ERROR: Top level target not found");
                }
                else
                {
                    l_attrOverridesExist = l_pTopLevelTarget->
                      getAttr<TARGETING::ATTR_PLCK_IPL_ATTR_OVERRIDES_EXIST>();
                }

                if (l_attrOverridesExist)
                {
                    fapi::theAttrOverrideSync().getAttrOverridesFromFsp();
                }
            }

            // Execute all Isteps sequentially in 'normal' mode
            err = executeAllISteps();

            if( err )
            {
                // per interlock meeting, adding sync after ipl failure in
                // normal IPL mode
                TRACFCOMP( g_trac_initsvc, "sync attributes to FSP");

                errlHndl_t l_syncAttrErrl = TARGETING::syncAllAttributesToFsp();

                if(l_syncAttrErrl)
                {
                    TRACFCOMP(g_trac_initsvc, "Attribute sync failed, see"
                            "%x for details", l_syncAttrErrl->eid());
                    errlCommit(l_syncAttrErrl, INITSVC_COMP_ID);
                }

                break;
            }

            // Send the potentially modified set of Attribute overrides and any
            // Attributes to sync to the FSP
            fapi::theAttrOverrideSync().sendAttrOverridesAndSyncsToFsp();
        }
    } while( 0 );

    TRACFCOMP( g_trac_initsvc,
               "IStepDispatcher finished.");
    printk( "IStepDispatcher exit.\n" );
    io_rtaskRetErrl= err;
}


// ----------------------------------------------------------------------------
// IStepDispatcher::executeAllISteps()
// ----------------------------------------------------------------------------
errlHndl_t IStepDispatcher::executeAllISteps ( void )
{
    errlHndl_t err = NULL;
    msg_t * theMsg = NULL;

    TRACFCOMP( g_trac_initsvc,
               ENTER_MRK"IStepDispatcher::executeAllISteps()" );

    do
    {
        // Sequentially loop through all isteps, executing each by replying to
        // work needed msg from worker thread.
        uint32_t prevIstep = 0;
        uint32_t prevSubStep = 0;
        for( size_t istep = 0;
             istep < MaxISteps;
             istep++ )
        {
            for( size_t substep = 0;
                 substep < g_isteps[istep].numitems ;
                 substep++ )
            {

                //  Check to see if this is a valid istep, if not, don't
                //  send it to istepWorker.  IstepWorker treats invalid
                //  isteps as an error.
                if ( NULL   ==  findTaskInfo( istep, substep ))
                {
                    TRACFCOMP( g_trac_initsvc,
                               "executeAllSteps: "
                               "skipping empty istep %d, substep: %d",
                               istep, substep );
                    continue;
                }

                // Before we can do anything, we need to be sure that
                //  the worker thread is ready to start
                theMsg = msg_wait( iv_msgQ );

                // check for sync msgs
                if( theMsg->type == SYNC_POINT_REACHED )
                {
                    TRACFCOMP( g_trac_initsvc,
                               INFO_MRK"Got sync msg (0x%08x)",
                               theMsg->type );
                    handleSyncPointReachedMsg();

                    // We didn't really do anything for this substep
                    substep--;
                    continue;
                }

                // Look for an errlog in extra_data
                if( NULL != theMsg->extra_data )
                {
                    TRACFCOMP( g_trac_initsvc,
                               ERR_MRK"executeAllISteps: "
                               "Error returned from istep(%d), substep(%d)",
                               prevIstep,
                               prevSubStep );

                    err = ((errlHndl_t)theMsg->extra_data);

                    break;
                }

                TRACFCOMP( g_trac_initsvc,
                           INFO_MRK"executeAllSteps: "
                           "type: 0x%08x, istep: %d, substep: %d",
                           theMsg->type, istep, substep );



                // Set the Istep info
                prevIstep = istep;
                prevSubStep = substep;
                uint16_t istepInfo = ((istep << 8 ) | substep);
                setIstepInfo( istepInfo );

                // Put the step/substep into data[0] for the worker thread
                theMsg->data[0] = istepInfo;
                msg_respond( iv_msgQ,
                             theMsg );

                theMsg = NULL;
            } // for substep

            // check to see if there were any delayed deconfigure callouts
            // call HWAS to have this processed
            bool callouts = HWAS::processDelayedDeconfig();

            // for now, force a TI if there were callouts
            // TODO RTC: 45781
            if (callouts)
            {
                TRACFCOMP(g_trac_initsvc,
                    INFO_MRK"HWAS has delayed deconfigs!");

                // we are going to return an errl so that we TI
                //  but if there is an error already (and it's very likely,
                //  since that's how deconfigure callouts happen) we want
                //  go send that one along
                if (err)
                {
                    TRACFCOMP( g_trac_initsvc,
                       "istepDispatcher, committing errorlog, PLID = 0x%x",
                       err->plid() );
                    errlCommit( err, INITSVC_COMP_ID );
                    // err is now NULL
                }

                /*@
                 * @errortype
                 * @reasoncode       ISTEP_DELAYED_DECONFIG
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         ISTEP_INITSVC_MOD_ID
                 * @userdata1        Current Istep
                 * @userdata2        Current SubStep
                 * @devdesc          a delayed deconfigure callup was
                 *                   encountered;
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                ISTEP_INITSVC_MOD_ID,
                                                ISTEP_DELAYED_DECONFIG,
                                                ((iv_Msg->type & 0xFF00) >> 8),
                                                (iv_Msg->type & 0xFF) );
                break;
            }

            if( err )
            {
                break;
            }
        } // for istep < MaxISteps;

        if( err )
        {
            break;
        }
    } while ( 0 );

    TRACFCOMP( g_trac_initsvc,
               EXIT_MRK"IStepDispatcher::executeAllISteps()" );

    return err;
}


// ----------------------------------------------------------------------------
// IStepDispatcher::msgHndlr()
// ----------------------------------------------------------------------------
errlHndl_t IStepDispatcher::msgHndlr ( void )
{
    errlHndl_t err = NULL;
    msg_t * theMsg = NULL;

    // TODO - Issue 45012
    // There is enough common code between this path and executeAllISteps()
    // that the issue above will be used to combine the 2 paths into one
    // commone code path.

    TRACFCOMP( g_trac_initsvc,
               ENTER_MRK"IStepDispatcher::msgHndlr()" );

    // We will stay in this loop unless there is a failure or other reason to
    // exit out and terminate.  This loop is the main handler for the Istep
    // Dispatcher.  It receives all messages from the Fsp, Child worker
    // thread, and the SPLess task.
    while( 1 )
    {
        theMsg = msg_wait( iv_msgQ );

        TRACDCOMP( g_trac_initsvc,
                   "msgHndlr: rcvmsg t=0x%08x, d0=0x%016x, d1=0x%016x, x=%p",
                   theMsg->type,
                   theMsg->data[0],
                   theMsg->data[1],
                   theMsg->extra_data );

        switch( theMsg->type )
        {
            case SYNC_POINT_REACHED:
                TRACDCOMP( g_trac_initsvc,
                           "msgHndlr : SYNC_POINT_REACHED" );
                // Sync point reached from Fsp
                iv_Msg = theMsg;
                handleSyncPointReachedMsg();
                break;

            case MORE_WORK_NEEDED:
                TRACDCOMP( g_trac_initsvc,
                           "msgHndlr : MORE_WORK_NEEDED" );
                // Worker thread is ready for more work.
                iv_workerMsg = theMsg;
                // The very first MORE_WORK_NEEDED message will
                // have theMsg->data[0] set to 1. It is set to 0
                // for subsequent messages. handleMoreWorkNeededMsg
                // needs to know the very first MORE_WORK_NEEDED msg
                // to handle the case that a msg is queued in the
                // mbox msg queue before this first MORE_WORK_NEEDED
                // is received.
                handleMoreWorkNeededMsg( (theMsg->data[0] == 1) );
                break;

            case PROCESS_IOVALID_REQUEST:
                TRACFCOMP( g_trac_initsvc,
                           "msgHndlr : PROCESS_IOVALID_REQUEST" );

                // make sure the library is loaded
                err = VFS::module_load("libestablish_system_smp.so");

                // if the module loaded ok, do the processing
                if( err == NULL )
                {
                    iv_Msg = theMsg;
                    handleProcFabIovalidMsg();
                }
                break;


            default:
                // Default Message
                // This SHOULD be a message from the Fsp with the Step/substep
                // to be executed.
                // Gotta check to make sure Fsp hadn't sent us a 2nd Istep
                // request for some reason, if so, its an error.
                if( iv_Msg )
                {
                    TRACFCOMP( g_trac_initsvc,
                               ERR_MRK"msgHndlr: ERROR: "
                               "IStep Dispatcher has another Istep request"
                               "for step: %d, substep: %d",
                               ((theMsg->type & 0xFF00) >> 8),
                               (theMsg->type & 0xFF) );

                    /*@
                     * @errortype
                     * @reasoncode       ISTEP_MULTIPLE_ISTEP_REQ
                     * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                     * @moduleid         ISTEP_INITSVC_MOD_ID
                     * @userdata1        Current Istep
                     * @userdata2        Current SubStep
                     * @devdesc          A Second Istep request has been made
                     *                   and we are still working on a
                     *                   previous Istep.
                     */
                    err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        ISTEP_INITSVC_MOD_ID,
                        ISTEP_MULTIPLE_ISTEP_REQ,
                        ((theMsg->type & 0xFF00) >> 8),
                        (theMsg->type & 0xFF) );

                    break;
                }

                TRACDCOMP( g_trac_initsvc,
                           "msgHndlr : default" );
                iv_Msg = theMsg;
                handleIStepRequestMsg();
                break;
        };  // end switch

        if( err )
        {
            TRACFCOMP( g_trac_initsvc,
                       "istepDispatcher, recieved errorlog, PLID = 0x%x",
                       err->plid()  );
            // Breaking here will be a BAD thing...  It means that we are
            // exiting not just Istep Dispatcher, but all of Hostboot.
            // This should only happen if there is an error during an Istep.
            errlCommit( err,
                        INITSVC_COMP_ID );
        }
    }   // end while(1)

    TRACFCOMP( g_trac_initsvc,
               EXIT_MRK"IStepDispatcher::msgHndlr()" );

    return err;
}


// ----------------------------------------------------------------------------
// waitForSyncPoint()
// IStepDispatcher::waitForSyncPoint()
// ----------------------------------------------------------------------------
void waitForSyncPoint ( void )
{
    TRACDCOMP( g_trac_initsvc,
               ENTER_MRK"waitForSyncPoint()" );

    IStepDispatcher::getTheInstance().waitForSyncPoint();

    TRACDCOMP( g_trac_initsvc,
               EXIT_MRK"waitForSyncPoint()" );
}

void IStepDispatcher::waitForSyncPoint ( void )
{
    TRACDCOMP( g_trac_initsvc,
               ENTER_MRK"IStepDispatcher::waitForSyncPoint()" );

    if( getIStepMode() ||
        spLess() )
    {
        TRACFCOMP( g_trac_initsvc,
                   INFO_MRK"Istep mode or SPless, "
                   "no wait for sync point allowed" );
        return;
    }

    // Lock here to hold off all additional callers
    TRACFCOMP( g_trac_initsvc,
               INFO_MRK"Wait for sync point" );
    mutex_lock( &iv_syncMutex );
    while( !iv_sync )
    {
        sync_cond_wait( &iv_syncHit,
                        &iv_syncMutex );
    }
    iv_sync = false;
    mutex_unlock( &iv_syncMutex );
    TRACDCOMP( g_trac_initsvc,
               INFO_MRK"Sync point hit." );

    TRACDCOMP( g_trac_initsvc,
               EXIT_MRK"IStepDispatcher::waitForSyncPoint()" );
}

// ----------------------------------------------------------------------------
// sendSyncPoint()
// IStepDispatcher::sendSyncPoint()
// ----------------------------------------------------------------------------
errlHndl_t sendSyncPoint ( void )
{
    TRACFCOMP( g_trac_initsvc,
               ENTER_MRK"sendSyncPoint()" );

    return IStepDispatcher::getTheInstance().sendSyncPoint();
}

errlHndl_t IStepDispatcher::sendSyncPoint ( void )
{
    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_initsvc,
               ENTER_MRK"IStepDispatcher::sendSyncPoint()" );

    if( getIStepMode() )
    {
        TRACFCOMP( g_trac_initsvc,
                   INFO_MRK"Istep mode, no sending sync point allowed" );
        return err;
    }

    msg_t * myMsg = msg_allocate();
    myMsg->type = SYNC_POINT_REACHED;
    uint64_t tmpVal = iv_curIStep;
    tmpVal = tmpVal << 32;
    tmpVal |= iv_curSubStep;
    myMsg->data[0] = tmpVal;
    myMsg->data[1] = 0x0;
    myMsg->extra_data = NULL;
    err = sendMboxMsg( ISTEP_ASYNC,
                       myMsg );

    TRACDCOMP( g_trac_initsvc,
               EXIT_MRK"IStepDispatcher::sendSyncPoint()" );

    return err;
}

// ----------------------------------------------------------------------------
// sendIstepCompleteMsg()
// IStepDispatcher::sendIstepCompleteMsg()
// ----------------------------------------------------------------------------
errlHndl_t sendIstepCompleteMsg ( void )
{
    TRACFCOMP( g_trac_initsvc,
               ENTER_MRK"sendIstepCompleteMsg()" );

    return IStepDispatcher::getTheInstance().sendIstepCompleteMsg();
}

errlHndl_t IStepDispatcher::sendIstepCompleteMsg ( void )
{
    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_initsvc,
               ENTER_MRK"IStepDispatcher::sendIstepCompleteMsg()" );

    do
    {
        // We just need to respond back to the outstanding iv_Msg we should
        // already have
        if( iv_Msg )
        {
            iv_Msg->data[0] = 0x0;
            msg_respond( iv_msgQ,
                         iv_Msg );
            iv_Msg = NULL;
        }
        else
        {
            TRACFCOMP( g_trac_initsvc,
                       ERR_MRK"Request to send Istep complete, "
                       "but no outstanding message from Fsp found!!" );

            /*@
             * @errortype
             * @reasoncode       NO_MSG_PRESENT
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         ISTEP_INITSVC_MOD_ID
             * @userdata1        Current Istep
             * @userdata2        Current SubStep
             * @devdesc          Request to send Istep Complete msg to Fsp, but
             *                   no outstanding message from Fsp found.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           ISTEP_INITSVC_MOD_ID,
                                           NO_MSG_PRESENT,
                                           iv_curIStep,
                                           iv_curSubStep );

            break;
        }

    } while( 0 );

    TRACDCOMP( g_trac_initsvc,
               EXIT_MRK"IStepDispatcher::sendIstepCompleteMsg()" );

    return err;
}

// ----------------------------------------------------------------------------
// IStepDispatcher::sendMboxMsg()
// ----------------------------------------------------------------------------
errlHndl_t IStepDispatcher::sendMboxMsg ( IStepSync_t i_sendSync,
                                          msg_t * i_msg )
{
    errlHndl_t err = NULL;

    TRACDCOMP( g_trac_initsvc,
               ENTER_MRK"IStepDispatcher::sendMboxMsg()" );

    do
    {
        if( ISTEP_SYNC == i_sendSync )
        {
            err = MBOX::sendrecv( HWSVRQ,
                                  i_msg );
        }
        else if( ISTEP_ASYNC == i_sendSync )
        {
            err = MBOX::send( HWSVRQ,
                              i_msg );
        }
        else
        {
            // should never get here, but if we do, just return back...
            // Nothing to send.
        }

        if( err )
        {
            break;
        }
    } while( 0 );

    TRACDCOMP( g_trac_initsvc,
               EXIT_MRK"IStepDispatcher::sendMboxMsg()" );

    return err;
}


// ----------------------------------------------------------------------------
// IStepDispatcher::getIstepInfo()
// ----------------------------------------------------------------------------
void IStepDispatcher::getIstepInfo ( uint8_t & o_iStep,
                                     uint8_t & o_subStep )
{
    mutex_lock( &iv_stepMutex );
    o_iStep = iv_curIStep;
    o_subStep = iv_curSubStep;
    mutex_unlock( &iv_stepMutex );
}


// ----------------------------------------------------------------------------
// IStepDispatcher::setIstepInfo()
// ----------------------------------------------------------------------------
void IStepDispatcher::setIstepInfo ( uint16_t i_type )
{
    mutex_lock( &iv_stepMutex );
    iv_curIStep = ((i_type & 0xFF00) >> 8);
    iv_curSubStep = (i_type & 0xFF);
    mutex_unlock( &iv_stepMutex );
}


// ----------------------------------------------------------------------------
// IStepDispatcher::handleSyncPointReachedMsg()
// ----------------------------------------------------------------------------
void IStepDispatcher::handleSyncPointReachedMsg ( void )
{
    TRACDCOMP( g_trac_initsvc,
               ENTER_MRK"IStepDispatcher::handleSyncPointReachedMsg()" );

    do
    {
        // Indicate we hit a sync point, and get anyone waiting moving.
        mutex_lock( &iv_syncMutex );
        iv_sync = true;
        sync_cond_signal( &iv_syncHit );
        mutex_unlock( &iv_syncMutex );
    } while( 0 );

    TRACDCOMP( g_trac_initsvc,
               EXIT_MRK"IStepDispatcher::handleSyncPointReachedMsg()" );
}


// ----------------------------------------------------------------------------
// IStepDispatcher::handleMoreWorkNeededMsg()
// ----------------------------------------------------------------------------
void IStepDispatcher::handleMoreWorkNeededMsg ( bool i_first )
{
    uint32_t    l_plid  =   0;

    TRACDCOMP( g_trac_initsvc,
               ENTER_MRK"IStepDispatcher::handleMoreWorkNeededMsg()" );

    // Clear out current Istep/substep values.  Since worker thread told us
    // its done, nothing is running right now.
    iv_curIStep = 0x0;
    iv_curSubStep = 0x0;

    // Only something to do if we've gotten a request from Fsp or SPLESS
    if( iv_Msg )
    {
        if (i_first)
        {
            handleIStepRequestMsg();
        }
        // Send response back to caller?
        else if( !msg_is_async( iv_Msg ) )
        {
            //  if the istep failed, istepWorker will return the errorlog
            //  in iv_WorkerMsg->extra_data.  Commit the error here and then
            //  return the plid as status to the FSP/spless in iv_Msg.
            //  Note that there are 2 messages in transit here, iv_WorkerMsg
            //  and iv_Msg .
            if ( iv_workerMsg->extra_data   !=  NULL )
            {
                errlHndl_t tmpErr = static_cast<errlHndl_t>(iv_workerMsg->extra_data);
                l_plid              =   tmpErr->plid();
                errlCommit( tmpErr,
                            INITSVC_COMP_ID );

                // pass the plid back to FSP/spless as status.
            }
            // status is returned in the high 32 bits of data[0] .
            // I'm not sure what the lower 32 bits are.
            iv_Msg->data[0]     =   ( static_cast<uint64_t>(l_plid) << 32 );
            iv_Msg->data[1]     =   0x0;
            iv_Msg->extra_data  =   NULL;


            TRACDCOMP( g_trac_initsvc,
            "MoreWorkNeeded: sendmsg t=0x%08x, d0=0x%016x, d1=0x%016x, x=%p",
                       iv_Msg->type,
                       iv_Msg->data[0],
                       iv_Msg->data[1],
                       iv_Msg->extra_data );

            // Send the potentially modified set of Attribute overrides and any
            // Attributes to sync to the FSP
            fapi::theAttrOverrideSync().sendAttrOverridesAndSyncsToFsp();

            msg_respond( iv_msgQ,
                         iv_Msg );
            iv_Msg = NULL;
        }
    }
    else
    {
        // We should never be here... Worker message should only be doing
        // something if it got a request from outside.
    }

    TRACDCOMP( g_trac_initsvc,
               EXIT_MRK"IStepDispatcher::handleMoreWorkNeededMsg()" );
}


// ----------------------------------------------------------------------------
// iStepBreakPoint()
// ----------------------------------------------------------------------------
void iStepBreakPoint ( uint32_t i_info )
{
    TRACFCOMP( g_trac_initsvc,
               ENTER_MRK"handleBreakpointMsg()" );
    IStepDispatcher::getTheInstance().handleBreakpoint( i_info );
}


// ----------------------------------------------------------------------------
// IStepDispatcher::handleBreakpoint()
// ----------------------------------------------------------------------------
void IStepDispatcher::handleBreakpoint ( uint32_t i_info )
{
    // Throttle the breakpoints by locking here.
    mutex_lock( &iv_bkPtMutex );
    errlHndl_t err = NULL;
    TRACDCOMP( g_trac_initsvc,
               ENTER_MRK"IStepDispatcher::handleBreakpointMsg()" );

    // Send Breakpoint msg to Fsp.
    msg_t * myMsg = msg_allocate();
    myMsg->type = BREAKPOINT;
    uint64_t tmpVal = 0x0;
    tmpVal = tmpVal & i_info;
    myMsg->data[0] = (tmpVal << 32); // TODO - Is this really a Fsp requirement?
    myMsg->data[1] = 0x0;
    myMsg->extra_data = NULL;

    if( !spLess() )
    {
        // FSP Attached
        // Wait for Fsp to respond.
        err = sendMboxMsg( ISTEP_SYNC,
                           myMsg );
        // TODO - Do we care what they sent back?  Not sure... HwSvr
        // has no documentation on this...
        if( err )
        {
            errlCommit( err,
                        INITSVC_COMP_ID );
        }
    }
    else
    {
        // SPLESS
        msg_respond( iv_msgQ,
                     myMsg );

        // Now wait for spless code to respond that we're done with the
        // breakpoint
        msg_t * rspMsg;
        rspMsg = msg_wait( iv_msgQ );
        msg_free(rspMsg);
    }

    msg_free( myMsg );

    TRACDCOMP( g_trac_initsvc,
               EXIT_MRK"IStepDispatcher::handleBreakpointMsg()" );
    mutex_unlock( &iv_bkPtMutex );
}


// ----------------------------------------------------------------------------
// IStepDispatcher::handleIStepRequestMsg()
// ----------------------------------------------------------------------------
void IStepDispatcher::handleIStepRequestMsg ( void )
{
    TRACDCOMP( g_trac_initsvc,
               ENTER_MRK"IStepDispatcher::handleIStepRequestMsg()" );

    // Only something to do, if the worker thread is ready for work
    if( iv_workerMsg )
    {
        //  debug
        TRACDCOMP( g_trac_initsvc,
        "handleIstepRequestMsg: iv_Msg: t=0x%08x, d0=0x%016x, d1=0x%016x, x=%p",
                   iv_Msg->type,
                   iv_Msg->data[0],
                   iv_Msg->data[1],
                   iv_Msg->extra_data );

        // Set new istep/substep info
        uint16_t stepInfo = ((iv_Msg->data[0] & 0x000000FF00000000) >> 24);
        stepInfo = (stepInfo | (iv_Msg->data[0] & 0xFF) );
        setIstepInfo( stepInfo );

        TRACDCOMP( g_trac_initsvc,
                   INFO_MRK"handleIstepRequestMsg: Istep req: 0x%04x",
                   stepInfo );

        // Set step/substep in data[0];
        iv_workerMsg->data[0] = stepInfo;
        msg_respond( iv_msgQ,
                     iv_workerMsg );

        iv_workerMsg = NULL;
    }

    TRACDCOMP( g_trac_initsvc,
               EXIT_MRK"IStepDispatcher::handleIStepRequestMsg()" );
}


// ----------------------------------------------------------------------------
// IStepDispatcher::getIStepMode()
// ----------------------------------------------------------------------------
bool IStepDispatcher::getIStepMode( ) const
{
    using namespace TARGETING;
    Target* l_pTopLevel = NULL;
    bool l_istepmodeflag = false;
    TargetService& l_targetService = targetService();

    (void)l_targetService.getTopLevelTarget( l_pTopLevel );
    if( l_pTopLevel == NULL )
    {
        TRACFCOMP( g_trac_initsvc,
                   "Top level handle was NULL" );
        l_istepmodeflag = false;
    }
    else
    {
        l_istepmodeflag = l_pTopLevel->getAttr<ATTR_ISTEP_MODE> ();
    }

    return  l_istepmodeflag;
}


// ----------------------------------------------------------------------------
// IStepDispatcher::spLess()
// ----------------------------------------------------------------------------
bool IStepDispatcher::spLess ( void )
{
    bool spless = true;
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    TARGETING::SpFunctions spfuncs;
    if( sys &&
        sys->tryGetAttr<TARGETING::ATTR_SP_FUNCTIONS>(spfuncs) &&
        spfuncs.mailboxEnabled )
    {
        spless = false;
    }

    return spless;
}


// ----------------------------------------------------------------------------
// IStepDispatcher::checkMpiplMode()
// ----------------------------------------------------------------------------
bool IStepDispatcher::checkMpiplMode( ) const
{
    using namespace TARGETING;

    Target* l_pTopLevel = NULL;
    bool l_isMpiplMode = false;

    TargetService& l_targetService = targetService();
    (void)l_targetService.getTopLevelTarget( l_pTopLevel );

    uint8_t is_mpipl = 0;
    if(l_pTopLevel &&
       l_pTopLevel->tryGetAttr<ATTR_IS_MPIPL_HB>(is_mpipl) &&
       is_mpipl)
    {
        l_isMpiplMode = true;
    }

    return  l_isMpiplMode;
}

void IStepDispatcher::handleProcFabIovalidMsg(   )
{
    TRACDCOMP( g_trac_initsvc,
               ENTER_MRK"IStepDispatcher::handleProcFabIovalidMsg()" );

    // do hostboot processing for istep
    // sys_proc_fab_ipvalid
    ESTABLISH_SYSTEM_SMP::host_sys_fab_iovalid_processing( iv_Msg );

    // Send the message back as a response
    msg_respond(iv_msgQ, iv_Msg);

    // if there was an error don't winkle ?
    if( iv_Msg->data[0] == HWSVR_MSG_SUCCESS )
    {
        TRACFCOMP( g_trac_initsvc,
                   "$TODO RTC:71447 - winkle all cores");
    }

    TRACDCOMP( g_trac_initsvc,
               EXIT_MRK"IStepDispatcher::handleProcFabIovalidMsg()" );

    iv_Msg = NULL;
}


} // namespace


