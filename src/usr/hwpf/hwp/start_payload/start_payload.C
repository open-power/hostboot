/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/start_payload/start_payload.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 *  @file start_payload.C
 *
 *  Support file for IStep: start_payload
 *   Start Payload
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <kernel/console.H>              //  printk status
#include    <sys/misc.h>
#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <vfs/vfs.H>
#include    <initservice/initserviceif.H>
#include    <initservice/extinitserviceif.H>
#include    <initservice/istepdispatcherif.H>
#include    <usr/cxxtest/TestSuite.H>
#include    <hwpf/istepreasoncodes.H>
#include    <sys/time.h>
#include    <mbox/mbox_queues.H>
#include    <mbox/mboxif.H>

#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    "start_payload.H"

//  Uncomment these files as they become available:
// #include    "host_start_payload/host_start_payload.H"

namespace   START_PAYLOAD
{

using   namespace   TARGETING;
using   namespace   fapi;
using   namespace   ISTEP;

/**
 * @brief This function will call the Initservice interface to shutdown
 *      Hostboot.  This function will call shutdown, passing in system
 *      attribute variables for the Payload base and Payload offset.
 *
 * @return errlHndl_t - NULL if succesful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t callShutdown ( void );

/**
 * @brief This function will check the Istep mode and send the appropriate
 *      mailbox message to the Fsp to indicate what we're doing.
 *
 * @param[in] i_istepModeFlag - Whether or not Isteps is enabled.
 *
 * @param[in] i_spFuncs - The SpFuncs system attribute.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t notifyFsp ( bool i_istepModeFlag,
                       TARGETING::SpFunctions i_spFuncs );


//
//  Wrapper function to call 21.1 :
//      host_start_payload
//
void    call_host_start_payload( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_start_payload entry" );

    do
    {
        // Host Start Payload procedure, per documentation from Patrick.
        //  - Verify target image
        //      - TODO - Done via call to Secure Boot ROM.
        //      - Will be done in future sprints

        //  - Update HDAT with updated SLW images
        //      - TODO - Once we know where they go in the HDAT

        //  - Run CXX testcases
        l_errl = INITSERVICE::executeUnitTests();

        if( l_errl )
        {
            break;
        }

        //  - Call shutdown using payload base, and payload entry.
        //      - base/entry will be from system attributes
        //      - this will start the payload (Phyp)
        // NOTE: this call will not return if successful.
        l_errl = callShutdown();

        if( l_errl )
        {
            break;
        }
    } while( 0 );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_start_payload exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}


//
// Call shutdown
//
errlHndl_t callShutdown ( void )
{
    errlHndl_t err = NULL;
    uint64_t payloadBase = 0x0;
    uint64_t payloadEntry = 0x0;
    bool istepModeFlag = false;
    uint64_t status = SHUTDOWN_STATUS_GOOD;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               ENTER_MRK"callShutdown()" );

    do
    {
        // Get Target Service, and the system target.
        TargetService& tS = targetService();
        TARGETING::Target* sys = NULL;
        (void) tS.getTopLevelTarget( sys );

        if( NULL == sys )
        {
            // Error getting system target to get payload related values.  We
            // will create an error to be passed back.  This will cause the
            // istep to fail.
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK"System Target was NULL!" );

            /*@
             * @errortype
             * @reasoncode       ISTEP_TARGET_NULL
             * @severity         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid         ISTEP_START_PAYLOAD_CALL_SHUTDOWN
             * @userdata1        <UNUSED>
             * @userdata2        <UNUSED>
             * @devdesc          System target was NULL!
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                           ISTEP_START_PAYLOAD_CALL_SHUTDOWN,
                                           ISTEP_TARGET_NULL,
                                           0x0,
                                           0x0 );

            break;
        }

        // Get Payload base/entry from attributes
        payloadBase = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();
        payloadEntry = sys->getAttr<TARGETING::ATTR_PAYLOAD_ENTRY>();
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"Payload Base: 0x%08x, Entry: 0x%08x",
                   payloadBase, payloadEntry );
        payloadBase = (payloadBase * MEGABYTE);
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"   base: 0x%08x",
                   payloadBase );

        // Get Istep Mode flag
        istepModeFlag = sys->getAttr<ATTR_ISTEP_MODE>();
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"Istep mode flag: %s",
                   ((istepModeFlag) ? "Enabled" : "Disabled") );

        // Get the Service Processor Functions
        TARGETING::SpFunctions spFuncs =
                sys->getAttr<TARGETING::ATTR_SP_FUNCTIONS>();

        // Notify Fsp with appropriate mailbox message.
        err = notifyFsp( istepModeFlag,
                         spFuncs );

        if( err )
        {
            break;
        }

        // do the shutdown.
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_start_payload finished, shutdown = 0x%x.",
                   status );
        INITSERVICE::doShutdown( status,
                                 payloadBase,
                                 payloadEntry );

        // Hang out here until shutdown happens
        int status = 0x0;
        while( 1 )
        {
            task_wait( &status,
                       NULL );
        }
    } while( 0 );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"callShutdown()" );

    return err;
}

//
// Notify the Fsp via Mailbox Message
//
errlHndl_t notifyFsp ( bool i_istepModeFlag,
                       TARGETING::SpFunctions i_spFuncs )
{
    errlHndl_t err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               ENTER_MRK"notifyFsp()" );

    do
    {
        // Get the Istep msgQ
        msg_q_t msgQ;
        INITSERVICE::getIstepMsgQ( msgQ );

        // Get the Istep Msg to respond to.
        msg_t * myMsg = NULL;
        INITSERVICE::getIstepMsg( myMsg );

        if( NULL == myMsg )
        {
            if( i_istepModeFlag )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"Istep message was NULL in Istep Mode!" );

                /*@
                 * @errortype
                 * @reasoncode       ISTEP_MBOX_MSG_NULL
                 * @severity         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM
                 * @moduleid         ISTEP_START_PAYLOAD_NOTIFY_FSP
                 * @userdata1        <UNUSED>
                 * @userdata2        <UNUSED>
                 * @devdesc          Istep Mailbox Message returned was NULL!
                 */
                err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                               ISTEP_START_PAYLOAD_NOTIFY_FSP,
                                               ISTEP_MBOX_MSG_NULL,
                                               0x0,
                                               0x0 );

                break;
            }
            else
            {
                myMsg = msg_allocate();
            }
        }

        // TODO - All of the following mailbox interactions really should be
        // done within the Istep Dispatcher.  But, it needs to be reorganized
        // to do that.  Issue 42491 should be used for this discussion and
        // when it is determined what needs to be reorganized, this should be
        // addressed.
        myMsg->data[1] = 0x0;
        myMsg->extra_data = NULL;
        if( i_istepModeFlag )
        {
            // Istep Mode send istep complete
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       INFO_MRK"Isteps enabled, send istep complete msg" );

            // TODO - I cannot use this unless I completely mess around the
            // headers for the istepdispatcher.  I have Issue 42491 open now
            // to discuss doing that.  For now, I'm hard coding the msg type
            // to be equivalent to this value
//            myMsg->type = INITSERVICE::SINGLE_STEP_TYPE;
            myMsg->type = MBOX::FIRST_SECURE_MSG | 0x00;
            myMsg->data[0] = 0x0;   // Fsp expects 0x0 (SUCCESS) in istep mode

            // Respond to the Msg
            msg_respond( msgQ,
                         myMsg );
        }
        else
        {
            // Non-Istep mode send SYNC_POINT_REACHED
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       INFO_MRK"Isteps disabled, send SYNC_POINT_REACHED msg" );

            // TODO - This really needs to be in istep_mbox_msgs.H, but that
            // isn't in a place that I can use it right now, and it can't be
            // moved because its using Enums from a header (splesscommon.H)
            // that shouldn't be moved.
            // I've opened Issue 42491 to discuss changes.
            const uint64_t SYNC_POINT_REACHED = MBOX::FIRST_UNSECURE_MSG | 0x10;
            myMsg->type = SYNC_POINT_REACHED;

            // Hardcode steps in data[0] until issue 42491 is resolved.
            // Step 21, substep 1
            myMsg->data[0] = ((((uint64_t)21) << 32) | 1 );

            // Send the async msg.
            MBOX::send( MBOX::IPL_SERVICE_QUEUE,
                        myMsg );
        }

        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"Sent MBOX Msg (0x%08x), msg: 0x%016llx.%016llx",
                   myMsg->type,
                   myMsg->data[0],
                   myMsg->data[1] );
    } while( 0 );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"notifyFsp()" );

    return err;
}

};   // end namespace
