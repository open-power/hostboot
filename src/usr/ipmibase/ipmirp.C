/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmibase/ipmirp.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
 * @file ipmirp.C
 * @brief IPMI resource provider definition
 */

#include "ipmirp.H"
#include "ipmiconfig.H"
#include "ipmidd.H"
#include <ipmi/ipmi_reasoncodes.H>
#include <ipmi/ipmiif.H>
#include <ipmi/ipmisel.H>
#include <devicefw/driverif.H>
#include <devicefw/userif.H>

#include <sys/task.h>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <sys/vfs.h>

#include <kernel/ipc.H>
#include <arch/ppc.H>
#include <errl/errlmanager.H>
#include <sys/time.h>
#include <sys/misc.h>
#include <errno.h>

#include <console/consoleif.H>

// Defined in ipmidd.C
extern trace_desc_t * g_trac_ipmi;
#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"rp: " printf_string,##args)


// Set this to true if you want to see all of the pnor messages
const bool g_PNOR_DEBUG = false;

/**
 * setup _start and handle barrier
 */
TASK_ENTRY_MACRO( IpmiRP::daemonProcess );

/**
 * @brief  Constructor
 */
IpmiRP::IpmiRP(void):
    iv_msgQ(msg_q_create()),
    iv_sendq(),
    iv_timeoutq(),
    iv_respondq(),
    iv_eventq(),
    iv_last_chanceq(msg_q_create()),
    iv_bmc_timeout(IPMI::g_bmc_timeout),
    iv_outstanding_req(IPMI::g_outstanding_req),
    iv_xmit_buffer_size(IPMI::g_xmit_buffer_size),
    iv_recv_buffer_size(IPMI::g_recv_buffer_size),
    iv_retries(IPMI::g_retries),
    iv_shutdown_msg(NULL),
    iv_graceful_shutdown_pending(false),
    iv_chassis_power_mod(IPMI::CHASSIS_POWER_OFF)
{
    mutex_init(&iv_mutex);
    sync_cond_init(&iv_cv);
}

/**
 * @brief  Destructor
 */
IpmiRP::~IpmiRP(void)
{
    msg_q_destroy(iv_msgQ);
}

void* IpmiRP::start(void* unused)
{
    Singleton<IpmiRP>::instance().execute();
    return NULL;
}

void* IpmiRP::timeout_thread(void* unused)
{
    Singleton<IpmiRP>::instance().timeoutThread();
    return NULL;
}

void* IpmiRP::get_capabilities(void* unused)
{
    Singleton<IpmiRP>::instance().getInterfaceCapabilities();
    return NULL;
}

void* IpmiRP::last_chance_event_handler(void* unused)
{
    Singleton<IpmiRP>::instance().lastChanceEventHandler();
    return NULL;
}

void IpmiRP::daemonProcess(errlHndl_t& o_errl)
{
    task_create(&IpmiRP::attach, NULL);
    task_create(&IpmiRP::start, NULL);
}

/**
 * @brief Return the transport header size
 */
size_t getXportHeaderSize(void)
{
    // Get the header size from the physical transport.
    IPMI::Message* msg = IPMI::Message::factory();
    size_t xport_size = msg->header_size();
    delete msg;
    return xport_size;
}

/**
 * @brief Return the maximum data size to allocate
 */
inline size_t IpmiRP::maxBuffer(void)
{
    // If the interface isn't up (say we're sending the
    // get-capabilities command, or some such) we use the
    // defaults setup in the ctor.

    static size_t  xport_header_size = getXportHeaderSize();

    mutex_lock(&iv_mutex);

    // Given the max buffer information from the get-capabilities
    // command, subtract off the physical layers header size.

    // iv_xmit_buffer_size can change - it'll be one thing for
    // the default when the RP is created, and possibly another
    // when the get-capabilities command returns.
    // an additional 1 is subtracted based on issues seen with AMI
    size_t mbs = iv_xmit_buffer_size - xport_header_size - 1;

    mutex_unlock(&iv_mutex);

    return mbs;
}

/**
 * @brief Start routine of the time-out handler
 */
void IpmiRP::timeoutThread(void)
{
    // Mark as an independent daemon so if it crashes we terminate.
    task_detach();

    IPMI_TRAC(ENTER_MRK "time out thread");

    // If there's something on the queue we want to grab it's timeout time
    // and wait. Note the response queue is "sorted" as we send messages in
    // order. So, the first message on the queue is the one who's timeout
    // is going to come first.
    while (true)
    {
        mutex_lock(&iv_mutex);
        while ((iv_timeoutq.size() == 0))
        {
            sync_cond_wait(&iv_cv, &iv_mutex);
        }

        msg_t*& msq_msg = iv_timeoutq.front();
        IPMI::Message* msg = static_cast<IPMI::Message*>(msq_msg->extra_data);

        // The difference between the timeout of the first message in the
        // queue and the current time is the time we wait for a timeout
        timespec_t tmp_time;
        clock_gettime(CLOCK_MONOTONIC, &tmp_time);

        uint64_t now = (NS_PER_SEC * tmp_time.tv_sec) + tmp_time.tv_nsec;
        uint64_t timeout = (NS_PER_SEC * msg->iv_timeout.tv_sec) +
            msg->iv_timeout.tv_nsec;

        if (now >= timeout)
        {
            IPMI_TRAC("timeout: %x:%x, seq=x%X",
                      msg->iv_netfun, msg->iv_cmd, msg->iv_seq );

            // This little bugger timed out. Get him off the timeoutq
            iv_timeoutq.pop_front();

            // Get him off the responseq, and reply back to the waiter that
            // there was a timeout
            response(msg, IPMI::CC_TIMEOUT);

            // Tell the resource provider to check for any pending messages
            msg_t* msg_idleMsg = msg_allocate();
            msg_idleMsg->type = IPMI::MSG_STATE_IDLE;
            msg_send(iv_msgQ, msg_idleMsg);

            mutex_unlock(&iv_mutex);
        }
        else
        {
            mutex_unlock(&iv_mutex);
            nanosleep( 0, timeout - now );
        }
    }
    IPMI_TRAC(EXIT_MRK "time out thread");

    return;
}

/**
 * @brief Get the BMC interface capabilities
 */
void IpmiRP::getInterfaceCapabilities(void)
{
    // Mark as an independent daemon so if it crashes we terminate.
    task_detach();

    // Queue up a get-capabilities message. Anything that queues up behind us
    // (I guess it could queue up in front of us too ...) will use the defaults.

    IPMI::completion_code cc = IPMI::CC_UNKBAD;
    size_t len = 0;
    uint8_t* data = NULL;
    errlHndl_t err = IPMI::sendrecv(IPMI::get_capabilities(), cc, len, data);

    do {
        // If we have a problem, we can't "turn on" the IPMI stack.
        if (err)
        {
            IPMI_TRAC("get_capabilities returned an error, using defaults");
            err->collectTrace(IPMI_COMP_NAME);
            errlCommit(err, IPMI_COMP_ID);
            break;
        }

        // If we get back a funky completion code, we'll use the defaults.
        if (cc != IPMI::CC_OK)
        {
            IPMI_TRAC("get_capabilities not ok %d, using defaults", cc);
            break;
        }

        // If we didn't get back what we expected, use the defaults
        if (len != 5)
        {
            IPMI_TRAC("get_capabilities length %d; using defaults", len);
            break;
        }

        // Protect the members as we're on another thread.
        mutex_lock(&iv_mutex);
        // @TODO RTC:123041 - In theory the number of outstanding requests is
        //       set via the response data below, but currently the response
        //       value isn't correct so the default will be used.
        //iv_outstanding_req = data[0];
        iv_xmit_buffer_size = data[1];
        iv_recv_buffer_size = data[2];
        // @TODO RTC:123041 - In theory the BMC timeout is set via the response
        //       data below, but currently the response value isn't correct so
        //       the default will be used.
        //iv_bmc_timeout = data[3];
        iv_retries = data[4];

        IPMI_TRAC("get_capabilities: requests %d, in buf %d, "
                  "out buf %d, timeout %d, retries %d",
                  iv_outstanding_req, iv_xmit_buffer_size,
                  iv_recv_buffer_size, iv_bmc_timeout, iv_retries);

        mutex_unlock(&iv_mutex);
    } while(false);

    delete[] data;

    return;
}

/**
 * @brief Tell the resource provider which queue to use for events
 * @param[in] i_cmd, the command we're looking for
 * @param[in] i_msgq, the queue we should be notified on
 */
void IpmiRP::registerForEvent(const IPMI::command_t& i_cmd,
                              const msg_q_t& i_msgq)
{
    mutex_lock(&iv_mutex);

    // We only need the command internally, but we create the entire
    // command_t as it's really the true representation of the event type.
    iv_eventq[i_cmd.second] = i_msgq;
    mutex_unlock(&iv_mutex);
    IPMI_TRAC("event registration for %x:%x", i_cmd.first, i_cmd.second);
}

void IPMI::register_for_event(const IPMI::command_t& i_cmd,
                              const msg_q_t& i_msgq)
{
    Singleton<IpmiRP>::instance().registerForEvent(i_cmd, i_msgq);
}

/**
 * @brief Give the resource provider a message to put in the eventq
 * @param[in] i_event, pointer to the new'd event (OEM SEL)
 */
void IpmiRP::postEvent(IPMI::oemSEL* i_event)
{
    // Called in the context of the RP message loop, mutex locked

    do {
        // Check to see if event is valid. AMI recomends we check the netfun,
        // the SEL id, and the record id. If they don't match, we're allowed
        // to consider this an unhandled message.
        if ( (i_event->iv_netfun      != IPMI::OEM_VALID_NETFUN) ||
             (i_event->iv_record      != IPMI::OEM_VALID_SEL_ID) ||
             (i_event->iv_record_type != IPMI::OEM_VALID_RECORD_TYPE) )
        {
            IPMI_TRAC("rejecting event netfun: 0x%x record: 0x%x record type: 0x%x cmd: 0x%x",
                      i_event->iv_netfun,
                      i_event->iv_record,
                      i_event->iv_record_type,
                      i_event->iv_cmd[0]);

            // ... and clean up the memory for the caller
            delete i_event;
            break;
        }

        // Check to see if this event has a queue registered
        IPMI::event_q_t::iterator it = iv_eventq.find(i_event->iv_cmd[0]);
        msg_q_t outq = (it == iv_eventq.end()) ? iv_last_chanceq : it->second;

        // Create a message to send asynchronously to the event handler queue
        // Assign the event to the message, the caller will delete the message
        // and the event.
        msg_t* msg = msg_allocate();
        msg->type = IPMI::TYPE_EVENT;
        msg->extra_data = i_event;

        IPMI_TRAC("queuing event %x:%x for handler",
                  i_event->iv_netfun, i_event->iv_cmd[0])
            int rc = msg_send(outq, msg);

        if (rc)
        {
            /*@
             * @errortype       ERRL_SEV_UNRECOVERABLE
             * @moduleid        IPMI::MOD_IPMISRV_POSTEVENT
             * @reasoncode      IPMI::RC_INVALID_SEND
             * @userdata1       rc from msq_send()
             * @devdesc         msg_send() failed
             * @custdesc        Firmware error during IPMI event handling
             */
            errlHndl_t err =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        IPMI::MOD_IPMISRV_POSTEVENT,
                                        IPMI::RC_INVALID_SEND,
                                        rc,
                                        0,
                                        true);
            err->collectTrace(IPMI_COMP_NAME);
            errlCommit(err, IPMI_COMP_ID);

            // ... and clean up the memory for the caller
            delete i_event;
            msg_free(msg);
        }

    } while(0);

    return;
}

/**
 * @brief Send a message indicating we're rejecting the pnor handshake request.
 */
static void rejectPnorRequest(void)
{
    // Per AMI email, send a 0 to reject the pnor request.
    static const uint8_t reject_request = 0x0;

    uint8_t* data = new uint8_t(reject_request);
    IPMI_TRAC("rejecting pnor access request %x", *data);

    uint8_t len = 0;
    errlHndl_t err = send(IPMI::pnor_response(), len, data);
    if (err)
    {
        err->collectTrace(IPMI_COMP_NAME);
        errlCommit(err, IPMI_COMP_ID);
    }
}

/**
 * @brief Handle various IPMI Power Messages
 */
void IpmiRP::handlePowerMessage( IPMI::oemSEL* i_event )
{

    do {
        // if the event type is "soft off" then update the modifier to send
        // a power off to the BMC
        if( i_event->iv_cmd[1] == IPMI::CHASSIS_POWER_OFF )
        {
            iv_chassis_power_mod = IPMI::CHASSIS_POWER_OFF;

            // handle the graceful shutdown message
            IPMI_TRAC("Graceful shutdown request received");

#ifdef CONFIG_CONSOLE
            CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "IPMI: shutdown requested");
            CONSOLE::flush();
#endif

        }
        else
        {
            //Ignore this message - It is an undefined/unsupported command
            IPMI_TRAC("Ignoring command with unknown Power Control Action: %x",
                         i_event->iv_cmd[1]);
            break;
        }

        // tell the istep dispacher to stop executing isteps
        INITSERVICE::stopIpl();

        // register for the post memory flush callback
        INITSERVICE::registerShutdownEvent(IPMI_COMP_ID, iv_msgQ,
                        IPMI::MSG_STATE_GRACEFUL_SHUTDOWN,
                        INITSERVICE::POST_MEM_FLUSH_NOTIFY_LAST);

        iv_graceful_shutdown_pending = true;
        lwsync();

        // initiate the shutdown processing in the background
        INITSERVICE::doShutdown(SHUTDOWN_STATUS_GOOD,true);


    } while (0);

}
/**
 * @brief Wait for events and read them
 */
void IpmiRP::lastChanceEventHandler(void)
{
    // Mark as an independent daemon so if it crashes we terminate.
    task_detach();

    // To create a event handler, all you need to do is create a message
    // queue (or use one you have) and register for events.

    // register with the resource provider, use the existing queue
    registerForEvent(IPMI::power_off(), iv_last_chanceq);


    // We'll handle the pnor request in this context as we just send
    // an async message which says "no."
    registerForEvent(IPMI::pnor_request(), iv_last_chanceq);

    do {

        msg_t* msg = msg_wait(iv_last_chanceq);

        IPMI::oemSEL* event = reinterpret_cast<IPMI::oemSEL*>(msg->extra_data);

        if (event->iv_cmd[0] == IPMI::pnor_request().second)
        {
            // We'll handle the pnor request in this context as we just send
            // an async message which says "no."
            rejectPnorRequest();
        }
        else if ( event->iv_cmd[0] == IPMI::power_off().second )
        {
            handlePowerMessage(event);
        }
        else {
            // TODO: RTC: 120128
            // The last-chance handler should do more than this - it needs to
            // respond back to the BMC and tell it whatever it needs to know. If
            // this response isn't simple for a specific message, then a real
            // handler should probably be written.

            IPMI_TRAC("last chance handler for event: %x:%x (%x %x %x)",
                      event->iv_netfun, event->iv_cmd[0],
                      event->iv_record, event->iv_record_type,
                      event->iv_timestamp);
        }
        // There's no way anyone can post an event synchronously, so we're done.
        delete event;
        msg_free(msg);

    } while(true);

    return;
}

void* IpmiRP::attach(void *unused)
{
    Singleton<IpmiRP>::instance().attach();

    return NULL;
}

void IpmiRP::attach(void)
{
    task_detach();

    msg_q_t mq = Singleton<IpmiDD>::instance().eventQueue();

    /* FIXME: Never shut down */
    while (1)
    {
        /* Forward it into the internal message queue */
        msg_send(iv_msgQ, msg_wait(mq));
        lwsync();
    }
}

/**
 * @brief  Entry point of the resource provider
 */
void IpmiRP::execute(void)
{
    bool l_shutdown_pending = false;

    // Mark as an independent daemon so if it crashes we terminate.
    task_detach();

    // Register shutdown events with init service.
    //      Done at the "end" of shutdown processing.
    //      This will flush out any IPMI messages which were sent as
    //      part of the shutdown processing. We chose MBOX priority
    //      as we don't want to accidentally get this message after
    //      interrupt processing has stopped in case we need intr to
    //      finish flushing the pipe.
    INITSERVICE::registerShutdownEvent(IPMI_COMP_ID, iv_msgQ,
                                       IPMI::MSG_STATE_SHUTDOWN,
                                       INITSERVICE::MBOX_PRIORITY);

    // Start the thread that waits for timeouts
    task_create( &IpmiRP::timeout_thread, NULL );

    // Queue and wait for a message for the interface capabilities
    task_create( &IpmiRP::get_capabilities, NULL);

    // Wait for an event message read it and handle it if no one else does
    task_create( &IpmiRP::last_chance_event_handler, NULL);

    while (true)
    {

        msg_t* msg = msg_wait(iv_msgQ);

        const IPMI::msg_type msg_type =
            static_cast<IPMI::msg_type>(msg->type);

        // Invert the "default" by checking here. This allows the compiler
        // to warn us if the enum has an un-handled case but still catch
        // runtime errors where msg_type is set out of bounds.
        assert(msg_type <= IPMI::MSG_LAST_TYPE,
               "msg_type %d not handled", msg_type);

        switch(msg_type)
        {
            // Messages we're told to send.
            // Push the message on the queue, and the idle() at the
            // bottom of this loop will start the transmit process.
            // Be sure to push_back to ensure ordering of transmission.
        case IPMI::MSG_STATE_SEND:
        {
            IPMI::Message* l_ipmi_msg =
                static_cast<IPMI::Message*>(msg->extra_data);
            bool l_is_pnor = IPMI::is_pnor_req(l_ipmi_msg->iv_netfun,
                                               l_ipmi_msg->iv_cmd);
            // don't trace the constant pnor hiomap stuff
            if( !l_is_pnor || g_PNOR_DEBUG )
            {
                IPMI_TRAC(WARN_MRK "Got message (0x%x:0x%x): l_is_pnor: %d",
                          l_ipmi_msg->iv_netfun, l_ipmi_msg->iv_cmd, l_is_pnor);
            }
            /* PNOR requests always allowed, else we hang shutdown */
            if (!l_shutdown_pending || l_is_pnor)
            {
                iv_sendq.push_back(msg);
            }
            // shutting down, do not accept new messages
            else
            {
                IPMI_TRAC(WARN_MRK "IPMI shutdown pending. Message dropped");
                response(l_ipmi_msg, IPMI::CC_BADSTATE);
                msg_free(msg);
            }
            break;

            // State changes from the IPMI hardware. These are async
            // messages so we get rid of them here.
        }
        case IPMI::MSG_STATE_IDLE:
            msg_free(msg);
            // No-op - we do it at the bottom of the loop.
            break;

            // Handle a response (B2H_ATN)
        case IPMI::MSG_STATE_RESP:
            msg_free(msg);
            response();
            break;

            // Handle an event (SMS_ATN). The protocol states that when we see
            // the sms attention bit, we issue a read_event message, which will
            // come back with the OEM SEL of the event in its payload.
        case IPMI::MSG_STATE_EVNT:
            {
                msg_free(msg);
                uint8_t* data = NULL;
                uint8_t len = 0;
                errlHndl_t err = send(IPMI::read_event(), len, data,
                                      IPMI::TYPE_EVENT);
                if (err)
                {
                    err->collectTrace(IPMI_COMP_NAME);
                    errlCommit(err, IPMI_COMP_ID);
                }
            }
            break;

            // Accept no more messages. Anything in the sendq is sent and
            // we wait for the reply from the BMC.
        case IPMI::MSG_STATE_SHUTDOWN:
            {
                l_shutdown_pending = true;    // Stop incoming new messages
                iv_shutdown_msg = msg;        // Reply to this message
                break;
            }
        case IPMI::MSG_STATE_GRACEFUL_SHUTDOWN:
            {
                IPMI_TRAC(INFO_MRK "MSG_STATE_GRACEFUL_SHUTDOWN: send power"
                                    " off command to BMC");
                // clear the graceful shutdown flag so we will exit after
                // sending the power off cmd
                iv_graceful_shutdown_pending = false;
                size_t len = 1;
                uint8_t* data = new uint8_t[len];

                // send the correct chassis power modifier.
                data[0] = iv_chassis_power_mod;

                IPMI::Message* ipmi_msg = IPMI::Message::factory(
                        IPMI::chassis_power_off(), len, data, IPMI::TYPE_ASYNC);

                // queue up the power off message
                iv_sendq.push_back(ipmi_msg->iv_msg);

                iv_shutdown_msg = msg;   // Reply to this message

#ifdef CONFIG_CONSOLE
            CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "IPMI: shutdown complete\n");
            CONSOLE::flush();
#endif

            }
            break;

        // begin a graceful reboot initiated by us
        case IPMI::MSG_STATE_INITIATE_POWER_CYCLE:
        case IPMI::MSG_STATE_INITIATE_SOFT_POWER_OFF:
            {
                msg_free(msg);

#ifdef CONFIG_CONSOLE
                if (msg_type == IPMI::MSG_STATE_INITIATE_POWER_CYCLE)
                {
                    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "IPMI: Initiate power cycle");
                }
                else // == IPMI::MSG_STATE_INITIATE_SOFT_POWER_OFF
                {
                    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "IPMI: Initiate soft power off");
                }
                CONSOLE::flush();
#endif
                // setup the power cmd modifier to tell the bmc to
                // do a power reset or soft power off
                if (msg_type == IPMI::MSG_STATE_INITIATE_POWER_CYCLE)
                {
                    iv_chassis_power_mod =  IPMI::CHASSIS_POWER_RESET;
                }
                else // == IPMI::MSG_STATE_INITIATE_SOFT_POWER_OFF
                {
                    iv_chassis_power_mod =
                       IPMI::CHASSIS_POWER_SOFT_OFF_VIA_OVER_TEMP;
                }

                // register for the post memory flush callback
                INITSERVICE::registerShutdownEvent(IPMI_COMP_ID, iv_msgQ,
                        IPMI::MSG_STATE_GRACEFUL_SHUTDOWN,
                        INITSERVICE::POST_MEM_FLUSH_NOTIFY_LAST);

                iv_graceful_shutdown_pending = true;
                lwsync();

                // initiate the shutdown processing in the background
                INITSERVICE::doShutdown(SHUTDOWN_STATUS_GOOD,true);

            }
            break;

        };

        // There's a good chance the interface will be idle right after
        // the operation we just performed. Since we need to poll for the
        // idle state, calling idle after processing a message may decrease
        // the latency of waiting for idle. The worst case is that we find
        // the interface busy and go back to waiting. Note: there's no need
        // to keep calling idle if there are old elements on the sendq;
        // we'll need to wait for the interface to indicate we're idle.
        if ((IPMI::MSG_STATE_SEND != msg_type) || (iv_sendq.size() == 1))
        {
            idle();
        }

        // Once quiesced, reply to shutdown msg and exit.
        // Shutdown simply puts us in a state we deny all further requests bar
        // those from PnorIpmiDD. Access to the PNOR must be provided right up
        // until we call the shutdown syscall, so there's no point at which we
        // can deallocate the resources consumed by IpmiRP, IpmiDD or
        // PnorIpmiDD.
        if (l_shutdown_pending && iv_respondq.empty() && iv_sendq.empty())
        {
            IPMI_TRAC(INFO_MRK "reply to the MSG_STATE_SHUTDOWN message");
            msg_respond(iv_msgQ, iv_shutdown_msg);
        }
    }

    IPMI_TRAC(EXIT_MRK "message loop");
    return;
}

///
/// @brief  Go in to the idle state
///
void IpmiRP::idle(void)
{
    // If the interface is idle, we can write anything we need to write.
    for (IPMI::send_q_t::iterator i = iv_sendq.begin();
         i != iv_sendq.end();)
    {
        // Check to see if we have many outstanding requests. If so, don't send
        // any more messages. Note the eagain mechanism still works even though
        // we're not sending messages as eventually we'll get enough responses
        // to shorten the response queue and since the message loop calls us
        // to transmit even for the reception of a message, the driver will
        // eventually reset egagains. If responses timeout, we end up here as
        // the response queue processing sends an idle message when anything is
        // removed.
        if (iv_outstanding_req <= iv_respondq.size())
        {
            break;
        }

        // If we have a problem transmitting a message, then we just stop
        // here and wait for the next time the interface transitions to idle
        // Note that there are two failure cases: the first is that there is
        // a problem transmitting. In this case we told the other end of the
        // message queue, and so the life of this message is over. The other
        // case is that the interface turned out to be busy in which case
        // this message can sit on the queue and it'll be next.

        IPMI::Message* msg = static_cast<IPMI::Message*>((*i)->extra_data);

        // If there was an i/o error, we do nothing - leave this message on
        // the queue. Don't touch msg after xmit returns. If the message was
        // sent, and it was async, msg has been destroyed.
        if (msg->xmit())
        {
            break;
        }
        i  = iv_sendq.erase(i);
    }

    return;
}

///
/// @brief Handle a response to a message we sent
///
void IpmiRP::response(void)
{
    IPMI::Message* rcv_buf = IPMI::Message::factory();

    do
    {
        // Go down to the device and read. Fills in iv_key.
        errlHndl_t err = rcv_buf->recv();

        if (err)
        {
            // Not much we're going to do here, so lets commit the error and
            // the original request will timeout.
            err->collectTrace(IPMI_COMP_NAME);
            errlCommit(err, IPMI_COMP_ID);
            break;
        }

        mutex_lock(&iv_mutex);
        response(rcv_buf);
        mutex_unlock(&iv_mutex);

    } while (false);

    delete rcv_buf;
    return;
}

///
/// @brief Handle a response to a message we want to change
///
void IpmiRP::response(IPMI::Message* i_msg, IPMI::completion_code i_cc)
{
    // The third bit in the netfun indicates this is a reply.
    static const uint8_t reply_bit = 0x04;

    i_msg->iv_cc = i_cc;
    i_msg->iv_netfun |= reply_bit; // update the netfun
    i_msg->iv_len = 0;             // sending no data
    i_msg->iv_data = NULL;
    response(i_msg);
    return;
}

///
/// @brief Handle a response to a message we have
///
void IpmiRP::response(IPMI::Message* i_msg)
{
    do {

        // Look for a message with this seq number waiting for a
        // response. If there isn't a message looking for this response,
        // log and leave. Async messages should also be on this queue,
        // even though the caller has long gone on to other things.
        IPMI::respond_q_t::iterator itr = iv_respondq.find(i_msg->iv_key);
        if (itr == iv_respondq.end())
        {
            IPMI_TRAC(ERR_MRK "message not found on the response queue: "
                      "%d %x:%x", i_msg->iv_key, i_msg->iv_netfun,
                      i_msg->iv_cmd);

            delete[] i_msg->iv_data;
            break;
        }

        msg_t* original_msg = itr->second;

        // Get us off the response queue, and the timeout queue.
        iv_respondq.erase(itr);
        iv_timeoutq.remove(original_msg);

        // Hand the allocated buffer over to the original message's
        // ipmi_msg_t It will be responsible for de-allocating it
        // when it's dtor is called.
        IPMI::Message* ipmi_msg =
            static_cast<IPMI::Message*>(original_msg->extra_data);

        // Hand ownership of the data to the original requester
        ipmi_msg->iv_data   = i_msg->iv_data;
        ipmi_msg->iv_len    = i_msg->iv_len;
        ipmi_msg->iv_cc     = i_msg->iv_cc;
        ipmi_msg->iv_netfun = i_msg->iv_netfun;

        // The subclasses know how to handle the response from here.
        // For example, sync messages will respond and async will delete
        ipmi_msg->response(iv_msgQ);

    } while(false);

    return;
}

///
/// @brief Queue a message on to the response queue
///
void IpmiRP::queueForResponse(IPMI::Message& i_msg)
{
    // Figure out when this fellow's timeout should occur. If we
    // have a problem from clock_gettime we have a bug, not an error.
    clock_gettime(CLOCK_MONOTONIC, &(i_msg.iv_timeout));

    // Lock before accessing the timeout (and the queues, etc.)
    mutex_lock(&iv_mutex);

    // BMC request-to-response times are always seconds, 1 - 30.
    // And I don't think we care about roll over here. Enforce the
    // timeout as a timeout per-message. Meaning if there are 2
    // messages on the timeout queue, make the timeout of this message
    // iv_bmc_timeout + iv_bmc_timeout*2
    i_msg.iv_timeout.tv_sec +=
                  (iv_bmc_timeout + (iv_bmc_timeout*iv_timeoutq.size()) );

    // Put this message on the response queue so we can find it later
    // for a response and on the timeout queue so if it times out
    // we can find it there. Note all message will all have the same
    // timeout - mostly. Every message sent before the BMC tells us
    // the timeout (at least one message) will have the shortest possible
    // timeout. The BMC might lengthen the timeout, but can not shorten
    // it.
    iv_respondq[i_msg.iv_seq] = i_msg.iv_msg;
    iv_timeoutq.push_back(i_msg.iv_msg);

    // If we put a message in an empty timeout queue (we know this as
    // there's only one message in the queue now) signal the timeout thread
    if (iv_timeoutq.size() == 1)
    {
        sync_cond_signal(&iv_cv);
    }

    mutex_unlock(&iv_mutex);
    return;
}

namespace IPMI
{
    ///
    /// @brief  Synchronus message send
    ///
    errlHndl_t sendrecv(const IPMI::command_t& i_cmd,
                        IPMI::completion_code& o_completion_code,
                        size_t& io_len, uint8_t*& io_data)
    {
        errlHndl_t err;
        static msg_q_t mq = Singleton<IpmiRP>::instance().msgQueue();

        IPMI::Message* ipmi_msg = IPMI::Message::factory(i_cmd, io_len, io_data,
                                                         IPMI::TYPE_SYNC);

        // I think if the buffer is too large this is a programming error.
        assert(io_len <= max_buffer());

        // don't trace the constant pnor hiomap stuff
        if( !IPMI::is_pnor_req(ipmi_msg->iv_netfun,ipmi_msg->iv_cmd)
            || g_PNOR_DEBUG )
        {
            IPMI_TRAC("queuing sync %x:%x", ipmi_msg->iv_netfun, ipmi_msg->iv_cmd);
        }
        int rc = msg_sendrecv(mq, ipmi_msg->iv_msg);

        // If the kernel didn't give a hassle about the message, check to see if
        // there was an error reported back from the other end of the queue. If
        // this message made it to the other end of the queue, then our memory
        // (io_data) is in the proper state.
        if (rc == 0) {
            err = ipmi_msg->iv_errl;
        }

        // Otherwise, lets make an errl out of our return code
        else
        {
            /*@
             * @errortype       ERRL_SEV_UNRECOVERABLE
             * @moduleid        IPMI::MOD_IPMISRV_SEND
             * @reasoncode      IPMI::RC_INVALID_SENDRECV
             * @userdata1       rc from msq_sendrecv()
             * @devdesc         msg_sendrecv() failed
             * @custdesc        Firmware error during system boot
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          IPMI::MOD_IPMISRV_SEND,
                                          IPMI::RC_INVALID_SENDRECV,
                                          rc,
                                          0,
                                          true);
            err->collectTrace(IPMI_COMP_NAME);

            // ... and clean up the memory for the caller
            delete[] io_data;
        }

        // The length and the data are the response, if there was one. All of
        // there are pretty much invalid if there was an error.
        io_len = ipmi_msg->iv_len;
        io_data = ipmi_msg->iv_data;
        o_completion_code = static_cast<IPMI::completion_code>(ipmi_msg->iv_cc);
        delete ipmi_msg;

        return err;
    }

    ///
    /// @brief  Asynchronous message send
    ///
    errlHndl_t send(const IPMI::command_t& i_cmd,
                    const size_t i_len, uint8_t* i_data,
                    IPMI::message_type i_type)
    {
        static msg_q_t mq = Singleton<IpmiRP>::instance().msgQueue();
        errlHndl_t err = NULL;

        // We don't delete this message, the message will self destruct
        // after it's been transmitted. Note it could be placed on the send
        // queue and we are none the wiser - so we can't delete it.
        IPMI::Message* ipmi_msg = IPMI::Message::factory(i_cmd, i_len,
                                                         i_data, i_type);

        // I think if the buffer is too large this is a programming error.
        assert(i_len <= max_buffer());

        IPMI_TRAC("queuing async %x:%x", ipmi_msg->iv_netfun, ipmi_msg->iv_cmd);
        int rc = msg_send(mq, ipmi_msg->iv_msg);

        if (rc)
        {
            /*@
             * @errortype       ERRL_SEV_UNRECOVERABLE
             * @moduleid        IPMI::MOD_IPMISRV_SEND
             * @reasoncode      IPMI::RC_INVALID_SEND
             * @userdata1       rc from msq_send()
             * @devdesc         msg_send() failed
             * @custdesc        Firmware error during system boot
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          IPMI::MOD_IPMISRV_SEND,
                                          IPMI::RC_INVALID_SEND,
                                          rc,
                                          0,
                                          true);
            err->collectTrace(IPMI_COMP_NAME);

            // ... and clean up the memory for the caller
            delete[] i_data;
        }

        return err;
    }

    ///
    /// @brief  Maximum buffer for data (max xport - header)
    ///
    size_t max_buffer(void)
    {
        return Singleton<IpmiRP>::instance().maxBuffer();
    }

    ///
    /// @brief Synchronously send an event
    ///
    errlHndl_t send_event(const uint8_t i_sensor_type,
                          const uint8_t i_sensor_number,
                          const bool i_assertion,
                          const uint8_t i_type,
                          completion_code& o_completion_code,
                          const size_t i_len,
                          uint8_t* i_data)
    {
        static const size_t event_header = 5;

        // Sanity check
        assert((i_len > 0) && (i_len < 4),
               "event request i_len incorrect %d", i_len);
        assert(i_type < 0x80, "event request i_type out of range %x", i_type);

        size_t len = event_header + i_len;
        uint8_t* data = new uint8_t[len];
        IPMI::completion_code cc = IPMI::CC_OK;

        data[0] = 0x01;     // More or less fixed, see table 5.4
        data[1] = 0x04;     // Fixed in the IPMI spec table 29.5
        data[2] = i_sensor_type;
        data[3] = i_sensor_number;
        data[4] = (i_assertion ? 0x80 : 0x00) + i_type;
        for (size_t i = 0; i < i_len; i++)
        {
            data[event_header + i] = i_data[i];
        }

        // We're done with i_data, but the caller deletes it. Note there's
        // no response data to an event - so there's nothing to copy over,
        // no reference to i_data, nothing.

        errlHndl_t err = sendrecv(IPMI::platform_event(), cc, len, data);

        o_completion_code = cc;
        delete[] data;
        return err;
    }

    /**
     * Retrieve some information about the BMC and the connection
     * we have to it.
     */
    BmcInfo_t getBmcInfo(void)
    {
        BmcInfo_t l_info;

        l_info.bulkTransferLpcBaseAddr = REG_HOSTBMC;
        static size_t size = sizeof(uint8_t);
        l_info.bulkTransferSize = size;
        l_info.chipVersion = cpu_dd_level();
        l_info.smsAttnInterrupt = CTRL_SMS_ATN;
        l_info.bmcToHostInterrupt = CTRL_B2H_ATN;

        //TODO RTC:162537 Add in non-generic bmc vendors AMI, Aten and OpenBmc
        char l_vendor[32] = "openpower,generic";
        strncpy(l_info.bmcVendor,l_vendor,sizeof(l_info.bmcVendor));


        return l_info;
    }

}; // End namespace IPMI
