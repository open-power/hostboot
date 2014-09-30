/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmirp.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
#include <ipmi/ipmi_reasoncodes.H>
#include <devicefw/driverif.H>
#include <devicefw/userif.H>

#include <config.h>
#include <sys/task.h>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>
#include <sys/vfs.h>

#include <targeting/common/commontargeting.H>
#include <kernel/ipc.H>
#include <arch/ppc.H>
#include <errl/errlmanager.H>
#include <sys/time.h>
#include <sys/misc.h>
#include <errno.h>

// Defined in ipmidd.C
extern trace_desc_t * g_trac_ipmi;
#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"rp: "printf_string,##args)

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
    iv_respondq()
{
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

void IpmiRP::daemonProcess(errlHndl_t& o_errl)
{
    task_create(&IpmiRP::start, NULL);
}

/**
 * @brief Return the maximum data size to allocate
 */
inline size_t IpmiRP::maxBuffer(void)
{
    // shared_ptrs would be handy here, fwiw.
    IPMI::Message* msg = IPMI::Message::factory();
    size_t mbs = msg->max_buffer();
    delete msg;
    return mbs;
}

/**
 * @brief  Entry point of the resource provider
 */
void IpmiRP::execute(void)
{
    // Mark as an independent daemon so if it crashes we terminate.
    task_detach();

    IPMI_TRAC(ENTER_MRK "message loop");

    // TODO: RTC 116300 Mark the daemon as started in the interface.
    // TODO: RTC 116300 Query the BMC for timeouts, other config
    // TODO: RTC 116300 Hold off transmitters until the BMC is ready?

    // Register shutdown events with init service.
    //      Done at the "end" of shutdown processesing.
    //      This will flush out any IPMI messages which were sent as
    //      part of the shutdown processing. We chose MBOX priority
    //      as we don't want to accidentally get this message after
    //      interrupt processing has stopped in case we need intr to
    //      finish flushing the pipe.
    INITSERVICE::registerShutdownEvent(iv_msgQ, IPMI::MSG_STATE_SHUTDOWN,
                                       INITSERVICE::MBOX_PRIORITY);
    do {

        while (true)
        {
            msg_t* msg = msg_wait(iv_msgQ);

            const IPMI::msg_type msg_type =
                static_cast<IPMI::msg_type>(msg->type);

            // Invert the "default" by checking here. This allows the compiler
            // to warn us if the enum has an unhandled case but still catch
            // runtime errors where msg_type is set out of bounds.
            assert(msg_type <= IPMI::MSG_LAST_TYPE,
                   "msg_type %d not handled", msg_type);

            switch(msg_type)
            {
                // Messages we're told to send. If we get a transmission
                // error (EAGAIN counts) then the interface is likely
                // not idle, and so we don't want to bother with idle below
            case IPMI::MSG_STATE_SEND:
                // Push the message on the queue, and the idle() at the
                // bottom of this loop will start the transmit process.
                // Be sure to push_back to ensure ordering of transmission.
                iv_sendq.push_back(msg);
                break;

                // State changes from the IPMI hardware. These are async
                // messages so we get rid of them here.
            case IPMI::MSG_STATE_IDLE:
                msg_free(msg);
                // No-op - we do it at the bottom of the loop.
                break;

            case IPMI::MSG_STATE_RESP:
                msg_free(msg);
                response();
                break;
            case IPMI::MSG_STATE_EVNT:
                IPMI_TRAC(ERR_MRK "msg loop: unexpected ipmi sms");
                msg_free(msg);
                // TODO: RTC 116300 Handle SMS messages
                break;

                // Accept no more messages. Anything in the sendq is doomed.
                // This should be OK - either they were async messages in which
                // case they'd appear to never have been sent or they're sync
                // in which case the higher layers should have handled this case
                // in their shutdown processing.
            case IPMI::MSG_STATE_SHUTDOWN:
                IPMI_TRAC(INFO_MRK "ipmi shuting down");
                // TODO: RTC 116887 Hold off transmitters, drain queues.
                // Patrick suggests handling this like mailboxes.
                msg_respond(iv_msgQ, msg);
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
        }

    } while (false);

    return;
}

///
/// @brief  Go in to the idle state
///
void IpmiRP::idle(void)
{
    // If the interface is idle, we can write anything we need to write.
    for (IPMI::send_q_t::iterator i = iv_sendq.begin(); i != iv_sendq.end();)
    {
        // If we have a problem transmitting a message, then we just stop
        // here and wait for the next time the interface transitions to idle.
        // Note that there are two failure cases: the first is that there is
        // a problem transmitting. In this case we told the other end of the
        // message queue, and so the life of this message is over. The other
        // case is that the interface turned out to be busy in which case
        // this message can sit on the queue and it'll be next.

        IPMI::Message* msg = static_cast<IPMI::Message*>((*i)->extra_data);

        // If there was an i/o error, we do nothing - leave this message on
        // the queue. Don't touch msg after xmit returns. If the message was
        // sent, and it was async, msg has been destroyed.
        if (msg->xmit(iv_respondq))
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

        // Look for a message with this seq number waiting for a
        // repsonse. If there isn't a message looking for this response,
        // log that fact and drop this on the floor.
        // TO THINK ABOUT: Could there be a command which generated
        // more than one response packet from the BMC? If this happens,
        // these messages should be handled like SMS messages - sent to
        // the appropriate queue for a waiter to take care of. So if a
        // message can generate more than one packet of response, something
        // needs to register for the overflow. So far we have not seen
        // any such beast ...
        IPMI::respond_q_t::iterator itr = iv_respondq.find(rcv_buf->iv_key);
        if (itr == iv_respondq.end())
        {
            // Every async message goes through this path. The semantics
            // somewhat contrary to IPMI semantics in that we have the ability
            // to generate "async" messages when the IPMI spec says there's no
            // such thing. We decided to just drop the response on the floor.
            // This is good for "fire and forget" situations where we don't
            // really care if the BMC gets the message or processes it
            // correctly. However, the BMC doesn't know we don't care about the
            // response and sends it. This code path does the dropping of the
            // response.
            delete[] rcv_buf->iv_data;
            break;
        }

        msg_t* original_msg = itr->second;
        iv_respondq.erase(itr);

        // Hand the allocated buffer over to the original message's
        // ipmi_msg_t It will be responsible for de-allocating it
        // when it's dtor is called.
        IPMI::Message* ipmi_msg =
            static_cast<IPMI::Message*>(original_msg->extra_data);

        // Hand ownership of the data to the original requestor
        ipmi_msg->iv_data = rcv_buf->iv_data;
        ipmi_msg->iv_len  = rcv_buf->iv_len;

        // Send the response to the original caller of sendrecv()
        int rc = msg_respond(iv_msgQ, original_msg);
        if (rc)
        {
            // Not much we're going to do here, so lets commit an error and
            // the original request will timeout.

            /* @errorlog tag
             * @errortype       ERRL_SEV_UNRECOVERABLE
             * @moduleid        IPMI::MOD_IPMISRV_REPLY
             * @reasoncode      IPMI::RC_INVALID_QRESPONSE
             * @userdata1       rc from msg_respond()
             * @devdesc         msg_respond() failed
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          IPMI::MOD_IPMISRV_REPLY,
                                          IPMI::RC_INVALID_QRESPONSE,
                                          rc,
                                          0,
                                          true);
            err->collectTrace(IPMI_COMP_NAME);

            IPMI_TRAC(ERR_MRK "msg_respond() i/o error (response) %d", rc);
            errlCommit(err, IPMI_COMP_ID);

            // Remove the response data.
            delete[] ipmi_msg->iv_data;

            break;
        }

    } while(false);

    delete rcv_buf;
    return;
}



namespace IPMI
{
    ///
    /// @brief  Synchronus message send
    ///
    errlHndl_t sendrecv(const IPMI::network_function i_netfun,
                        const uint8_t i_cmd, uint8_t& o_completion_code,
                        size_t& io_len, uint8_t*& io_data)
    {
        errlHndl_t err;
        static msg_q_t mq = Singleton<IpmiRP>::instance().msgQueue();

        IPMI::Message* ipmi_msg = IPMI::Message::factory(i_netfun, i_cmd,
                                                         io_len, io_data,
                                                         IPMI::TYPE_SYNC);

        // I think if the buffer is too large this is a programming error.
        assert(io_len <= max_buffer());

        IPMI_TRAC("queuing sync %x:%x", i_netfun, i_cmd);
        int rc = msg_sendrecv(mq, ipmi_msg->iv_msg);

        // If the kernel didn't give a hassle about he message, check to see if
        // there was an error reported back from the other end of the queue. If
        // this message made it to the other end of the queue, then our memory
        // (io_data) is in the proper state.
        if (rc == 0) {
            err = ipmi_msg->iv_errl;
        }

        // Otherwise, lets make an errl out of our return code
        else
        {
            /* @errorlog tag
             * @errortype       ERRL_SEV_UNRECOVERABLE
             * @moduleid        IPMI::MOD_IPMISRV_SEND
             * @reasoncode      IPMI::RC_INVALID_SENDRECV
             * @userdata1       rc from msq_sendrecv()
             * @devdesc         msg_sendrecv() failed
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
        o_completion_code = ipmi_msg->iv_cc;
        delete ipmi_msg;

        return err;
    }

    ///
    /// @brief  Asynchronus message send
    ///
    errlHndl_t send(const IPMI::network_function i_netfun,
                    const uint8_t i_cmd,
                    const size_t i_len, uint8_t* i_data)
    {
        static msg_q_t mq = Singleton<IpmiRP>::instance().msgQueue();
        errlHndl_t err = NULL;

        // We don't delete this message, the message will self destruct
        // after it's been transmitted. Note it could be placed on the send
        // queue and we are none the wiser - so we can't delete it.
        IPMI::Message* ipmi_msg = IPMI::Message::factory(i_netfun, i_cmd,
                                                         i_len, i_data,
                                                         IPMI::TYPE_ASYNC);

        // I think if the buffer is too large this is a programming error.
        assert(i_len <= max_buffer());

        IPMI_TRAC("queuing async %x:%x", i_netfun, i_cmd);
        int rc = msg_send(mq, ipmi_msg->iv_msg);

        if (rc)
        {
            /* @errorlog tag
             * @errortype       ERRL_SEV_UNRECOVERABLE
             * @moduleid        IPMI::MOD_IPMISRV_SEND
             * @reasoncode      IPMI::RC_INVALID_SEND
             * @userdata1       rc from msq_send()
             * @devdesc         msg_send() failed
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
    inline size_t max_buffer(void)
    {
        static const size_t mbs = Singleton<IpmiRP>::instance().maxBuffer();
        return mbs;
    }

};
