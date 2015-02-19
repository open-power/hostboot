/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/sptask.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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
#include    <sys/msg.h>                     //  message Q's
#include    <mbox/mbox_queues.H>            //  MSG_HB_MSG_BASE


#include    <trace/interface.H>             //  trace support
#include    <errl/errlentry.H>              //  errlHndl_t

#include    <initservice/initsvcudistep.H>  //  InitSvcUserDetailsIstep
#include    <initservice/taskargs.H>        // TASK_ENTRY_MACRO

#include    <targeting/common/util.H>       //
#include    <console/consoleif.H>
#include    <config.h>

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
    SPLessCmd               l_trigger;
    l_trigger.cmd.key = 0x15;           //Random starting value
    int                     l_sr_rc         =   0;
    msg_q_t                 l_SendMsgQ      =   static_cast<msg_q_t>( io_msgQ );
    msg_t                   *l_pMsg         =   msg_allocate();
    msg_q_t                 l_RecvMsgQ      =   msg_q_create();
    msg_t                   *l_pCurrentMsg  =  NULL;

    TRACFCOMP( g_trac_initsvc,
            "userConsoleComm entry, args=%p",
            io_msgQ  );

    // initialize command status reg
    //  init status reg, enable ready bit
    l_cmd.cmd.readybit  =   true;
    l_cmd.cmd.key = l_trigger.cmd.key;
    writeCmdSts( l_cmd );

    TRACFCOMP( g_trac_initsvc,
            "userConsoleComm : readybit set." );

#ifdef CONFIG_CONSOLE_OUTPUT_PROGRESS
#ifdef CONFIG_BMC_AST2400
    const char* l_input = "SIO";
#else
    const char* l_input = "CFAM";
#endif
    CONSOLE::displayf(NULL, "ISTEP mode -- awaiting user input from %s", l_input);
    CONSOLE::flush();
#endif


    //  set Current to our message on entry
    l_pCurrentMsg   =   l_pMsg;
    //
    //  Start the polling loop.
    //
    while( 1 )
    {
        //  read command register
        readCmdSts( l_cmd );

        //  process any pending commands
        if ( l_cmd.cmd.gobit &&
             (l_cmd.cmd.key == l_trigger.cmd.key))
        {
            // clear go bit, status, and set running bit
            l_cmd.sts               =   0;
            l_cmd.cmd.key           =   0;
            l_cmd.cmd.runningbit    =   true;
            l_cmd.cmd.readybit      =   false;
            l_cmd.cmd.gobit         =   false;

            // write the intermediate value back to the console.
            TRACFCOMP( g_trac_initsvc,
                    "userConsoleComm Write status (running) istep %d.%d",
                    l_cmd.istep, l_cmd.substep );

            writeCmdSts( l_cmd );

            // pass the command on to IstepDisp, block until reply

            l_pCurrentMsg->type     = ISTEP_MSG_TYPE;
            l_pCurrentMsg->data[0]  =
                ( ( static_cast<uint64_t>(l_cmd.istep & 0xFF) << 32) |
                  ( static_cast<uint64_t>(l_cmd.substep & 0xFF ) ) );
            l_pCurrentMsg->data[1]     =   0;
            l_pCurrentMsg->extra_data  =   NULL;

#ifdef CONFIG_CONSOLE_OUTPUT_PROGRESS
            CONSOLE::displayf(NULL, "ISTEP %2d.%2d", l_cmd.istep, l_cmd.substep);
            CONSOLE::flush();
#endif
            TRACFCOMP( g_trac_initsvc,
            "userConsoleComm: sendmsg type=0x%08x, d0=0x%016llx,"
                       " d1=0x%016llx, x=%p",
                       l_pCurrentMsg->type,
                       l_pCurrentMsg->data[0],
                       l_pCurrentMsg->data[1],
                       l_pCurrentMsg->extra_data );
            //
            //  msg_sendrecv_noblk  effectively splits the "channel" into
            //  a send Q and a receive Q
            //
            l_sr_rc =   msg_sendrecv_noblk( l_SendMsgQ, l_pCurrentMsg, l_RecvMsgQ );
            //  should never happen.
            assert( l_sr_rc == 0 );

            //  This should unblock on any message sent on the Q,
            l_pCurrentMsg  =   msg_wait( l_RecvMsgQ );

            // Update command/status reg when the command is done
            l_cmd.cmd.key           =   ++l_trigger.cmd.key;
            l_cmd.cmd.runningbit    =   false;
            l_cmd.cmd.readybit      =   true;
            l_cmd.cmd.gobit         =   false;

            TRACFCOMP( g_trac_initsvc,
                       "userConsoleComm: rcvmsg type=0x%08x, d0=0x%016llx"
                       ", d1=0x%016llx, x=%p",
                       l_pCurrentMsg->type,
                       l_pCurrentMsg->data[0],
                       l_pCurrentMsg->data[1],
                       l_pCurrentMsg->extra_data );

            if ( l_pCurrentMsg->type   == BREAKPOINT )
            {
                l_cmd.sts    =   SPLESS_AT_BREAK_POINT;
            }

            //  istep status is the hi word in the returned data 0
            //  this should be either 0 or a plid from a returned errorlog
            //  Don't have enough space to store entire, PLID... just check
            //  If non zero
            else if(static_cast<uint32_t>( l_pCurrentMsg->data[0] >> 32 ) !=0x0)
            {
                l_cmd.sts = SPLESS_ISTEP_FAIL;
            }

            writeCmdSts( l_cmd );
        }   //  endif   gobit

        // sleep, and wait for user to give us something else to do.
        if( TARGETING::is_vpo() )
        {
            // In VPO/VBU, yield the task, any real delay takes too long
            task_yield();
        }
        else
        {
            nanosleep( SINGLESTEP_PAUSE_S, SINGLESTEP_PAUSE_NS );
        }
    }   //  endwhile

    TRACFCOMP( g_trac_initsvc,
               "sptask: Uh-oh, we just exited...  what went wrong?" );

    //  @note
    //  Fell out of loop, clear sts reg and turn off readybit
    //  disable the ready bit so the user knows.
    l_cmd.cmd.readybit = false;
    l_cmd.sts    =   SPLESS_TASKRC_TERMINATED;
    writeCmdSts( l_cmd );

    TRACFCOMP( g_trac_initsvc,
            "userConsoleComm exit" );

    //  free the message struct
    msg_free( l_pMsg  );

    // return to main to end task
}

void* spTask( void    *io_pArgs )
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

    // End the task.
    return NULL;
}


} // namespace
