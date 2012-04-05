//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/istepdispatcher/sptask.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
 *  @file sptask.C
 *
 *  SP / SPless task  detached from IStep Dispatcher.
 *      Handles
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
#include    <sys/msg.h>                     //  message Q's
#include    <mbox/mbox_queues.H>            //  MSG_HB_MSG_BASE


#include    <trace/interface.H>             //  trace support
#include    <errl/errlentry.H>              //  errlHndl_t

#include    <initservice/initsvcudistep.H>  //  InitSvcUserDetailsIstep
#include    <initservice/taskargs.H>        // TASK_ENTRY_MACRO

#include    <targeting/util.H>              //

#include    "istepdispatcher.H"
#include    "splesscommon.H"
#include    "istep_mbox_msgs.H"


namespace   INITSERVICE
{

using   namespace   ERRORLOG;               // IStepNameUserDetails
using   namespace   SPLESS;                 // SingleStepMode
using   namespace   TARGETING;              //

/******************************************************************************/
// Globals/Constants
/******************************************************************************/
extern trace_desc_t *g_trac_initsvc;

/**
 * @const   SPLess PAUSE - These two constants are used in a nanosleep() call
 *          below to sleep between polls of the StatusReg.  Typically this will
 *          be about 10 ms - the actual value will be determined empirically.
 */
const   uint64_t    SINGLESTEP_PAUSE_S     =   0;
const   uint64_t    SINGLESTEP_PAUSE_NS    =   10000000;

/**
 * @brief Translate beween commands on SPless user console and FSP commands
 *
 * @param[in]   -   command from SPLess user console
 *
 * @return  FSP command
 *
 */
uint32_t    SPLessToFSP( const uint8_t i_cmd )
{
    uint32_t    l_FSPCmd    =   0;

    switch( i_cmd )
    {

    case    SPLESS_SINGLE_ISTEP_CMD:
        l_FSPCmd    =   SINGLE_STEP_TYPE;
        break;
    case    SPLESS_RESUME_ISTEP_CMD:
        l_FSPCmd    =   BREAKPOINT_TYPE;
        break;
    case    SPLESS_CLEAR_TRACE_CMD:
        l_FSPCmd    =   CLEAR_TRACE_TYPE;
        break;
    case    SPLESS_SHUTDOWN_CMD:
        l_FSPCmd    =   SHUTDOWN_TYPE;
        break;
    default:
        TRACFCOMP( g_trac_initsvc,
                "spTask ERROR:  unknown cmd %d",
                i_cmd  );
        // should never happen...
        assert( 0 );
    }

    return  l_FSPCmd;
}



/**
 * @brief  userConsoleComm
 *
 * Communicate with User Console on VPO or Simics.
 * Forwards commands to HostBoot (IStep Dispatcher) via a message Q.
 * Forwards status from HostBoot to VPO or Simics user console.
 *
 * Stop and wait for the user console to send the next IStep to run.
 * Run that, then  wait for the next one.
 *
 * @param[in,out]  -   pointer to a message Q, passed in by the parent
 *
 * @return none
 */
void    userConsoleComm( void *  io_msgQ )
{
    SPLessCmd               l_cmd;
    SPLessSts               l_sts;
    uint8_t                 l_seqnum        =   0;
    bool                    l_quitflag      =   false;
    int                     l_sr_rc         =   0;
    msg_q_t                 l_SendMsgQ      =   static_cast<msg_q_t>( io_msgQ );
    msg_t                   *l_pMsg         =   msg_allocate();
    msg_q_t                 l_RecvMsgQ      =   msg_q_create();
    msg_t                   *l_pCurrentMsg  =  NULL;

    TRACFCOMP( g_trac_initsvc,
            "userConsoleComm entry, args=%p",
            io_msgQ  );

    // initialize command reg
    l_cmd.val64 =   0;
    writeCmd( l_cmd );

    //  init status reg, enable ready bit
    l_sts.val64 =   0;
    l_sts.hdr.readybit  =   true;
    writeSts( l_sts );

    //  set Current to our message on entry
    l_pCurrentMsg   =   l_pMsg;
    //
    //  Start the polling loop.
    //
    while( 1 )
    {
        //  read command register from user console
        readCmd( l_cmd );

        //  process any pending commands
        if ( l_cmd.hdr.gobit )
        {
            // get the sequence number from caller
            l_seqnum    =   l_cmd.hdr.seqnum;

            //  clear status
            l_sts.val64 =   0;

            //  set running bit, fill in istep and substep
            l_sts.hdr.runningbit    =   true;
            l_sts.hdr.readybit      =   true;

            // @todo modify hb-istep to check both running bit and seqnum
            // l_sts.hdr.seqnum        =   l_seqnum;
            l_sts.istep             =   l_cmd.istep;
            l_sts.substep           =   l_cmd.substep;


            // write the intermediate value back to the console.
            TRACDCOMP( g_trac_initsvc,
                    "userConsoleComm Write status 0x%x.%x",
                    static_cast<uint32_t>( l_sts.val64 >> 32 ),
                    static_cast<uint32_t>( l_sts.val64 & 0x0ffffffff ) );

            writeSts( l_sts );

            // pass the command on to IstepDisp, block until reply
            l_pCurrentMsg->type        =  SPLessToFSP( l_cmd.hdr.cmdnum );
            l_pCurrentMsg->data[0]     =
                    ( static_cast<uint64_t>( l_cmd.istep ) << 32 ) |
                    static_cast<uint64_t>( l_cmd.substep )  ;
            l_pCurrentMsg->data[1]     =   0;
            l_pCurrentMsg->extra_data  =   NULL;

            TRACDCOMP( g_trac_initsvc,
                     "userConsoleComm send %p cmd type 0x%x, 0x%x.%x",
                     l_pCurrentMsg,
                     l_pCurrentMsg->type,
                     static_cast<uint32_t>( l_pCurrentMsg->data[0] >> 32 ),
                     static_cast<uint32_t>( l_pCurrentMsg->data[0] & 0x0ffffffff ) );

            //
            //  msg_sendrecv_noblk  effectively splits the "channel" into
            //  a send Q and a receive Q
            //
            l_sr_rc =   msg_sendrecv_noblk( l_SendMsgQ, l_pCurrentMsg, l_RecvMsgQ );
            //  should never happen.
            assert( l_sr_rc == 0 );

            //  This should unblock on any message sent on the Q,
            l_pCurrentMsg  =   msg_wait( l_RecvMsgQ );

            // process returned status from IStepDisp
            l_sts.hdr.status    =   0;

            TRACDCOMP( g_trac_initsvc,
                        "spTask: %p recv msg type 0x%x, 0x%x.%x",
                        l_pCurrentMsg,
                        l_pCurrentMsg->type,
                        static_cast<uint32_t>( l_pCurrentMsg->data[0] >> 32 ),
                        static_cast<uint32_t>( l_pCurrentMsg->data[0] & 0x0ffffffff ) );

            if ( l_pCurrentMsg->type   == BREAKPOINT_TYPE )
            {
                l_sts.hdr.status    =   SPLESS_AT_BREAK_POINT;
            }
            //  istep status is the hi word in the returned data 0
            l_sts.istepStatus   =
                    static_cast<uint32_t>( l_pCurrentMsg->data[0] >> 32 );

            // finish filling in status
            l_sts.hdr.runningbit    =   false;
            l_sts.hdr.seqnum        =   l_seqnum;
            l_sts.istep             =   l_cmd.istep;
            l_sts.substep           =   l_cmd.substep;
            //  status should be set now, write to Status Reg.

            writeSts( l_sts );

            //  if shutdown issued, end this task
            if ( l_cmd.hdr.cmdnum   ==  SPLESS_SHUTDOWN_CMD )
            {
                l_quitflag    =   true;
            }

            // clear command reg, including go bit (i.e. set to false)
            l_cmd.val64 =   0;
            writeCmd( l_cmd );
        }   //  endif   gobit


        if  ( l_quitflag  ==  true )
        {
            //  shutdown command issued, break out of loop
            break;
        }

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

    //  free the message struct
    msg_free( l_pMsg  );

    //  @note
    //  Fell out of loop, clear sts reg and turn off readybit
    //  disable the ready bit so the user knows.
    l_sts.val64 =   0;
    l_sts.hdr.status    =   SPLESS_TASKRC_TERMINATED;
    l_sts.hdr.seqnum    =   l_seqnum;
    writeSts( l_sts );

    TRACFCOMP( g_trac_initsvc,
            "userConsoleComm exit" );

    // return to main to end task
}

void spTask( void    *io_pArgs )
{

    TRACFCOMP( g_trac_initsvc,
            "spTask entry, args=%p",
            io_pArgs  );

    //  IStepDisp should not expect us to come back.
    task_detach();

    //  Start talking to VPO / Simics User console.
    userConsoleComm( io_pArgs );

    TRACFCOMP( g_trac_initsvc,
            "spTask exit." );

    // shutdown requested, end the task.
    task_end();
}


} // namespace
