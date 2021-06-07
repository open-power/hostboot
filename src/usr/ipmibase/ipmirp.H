/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmibase/ipmirp.H $                                   */
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

#ifndef __IPMI_IPMIRP_H
#define __IPMI_IMPIRP_H

/**
 * @file ipmirp.H
 * @brief IPMI service provider declariation
 */

#include <stdint.h>
#include <builtins.h>
#include <ipmi/ipmiif.H>
#include <errl/errlentry.H>
#include <sys/msg.h>
#include <sys/sync.h>
#include <list>
#include <map>
#include <util/locked/list.H>
#include <intr/interrupt.H>
#include <limits.h>

#include "ipmimsg.H"

class IpmiRP
{
  public:

    /**
     * Initialize the IPMI service
     * @param[in] o_errl, NULL if OK
     */
    static void daemonProcess(errlHndl_t& o_errl);

    /**
     * IpmiDD data source
     */
    static void* attach(void *unused);

    /**
     * Thread start routine for the resource provider
     * @param[in] void*, unused
     */
    static void* start(void* unused);

    /**
     * Thread start routine for the timeout thread
     * @param[in] void*, unused
     */
    static void* timeout_thread(void* unused);

    /**
     * Thread start routine for a little task which
     * waits for the BMC to give us the interface capabilties
     * @param[in] void*, unused
     */
    static void* get_capabilities(void* unused);

    /**
     * Thread start routine for a little task which handles events
     * which aren't registered by any other task
     * @param[in] void*, unused
     */
    static void* last_chance_event_handler(void* unused);

    /**
     * Default constructor
     */
    IpmiRP(void);

    /**
     * Destructor
     */
    ~IpmiRP(void);

    /**
     * The mailbox service provider task
     */
    void msgHandler(void);

    /**
     * Return the max data buffer to allocate for the underlying transport.
     */
    inline size_t maxBuffer(void);

    /**
     * @brief Get the message queue associated with this RP
     * @param[in] void
     * @return, a msg_q_t which is the message queue
     */
    msg_q_t msgQueue(void)
        { return iv_msgQ; }

    /**
     * @brief Queue a message on to the response queue
     * @param[in] i_msg, the message to queue
     */
    void queueForResponse(IPMI::Message& i_msg);

    /**
     * @brief Tell the resource provider which queue to use for events
     * @param[in] i_cmd, the command we're looking for
     * @param[in] i_msgq, the queue we should be notified on
     */
    void registerForEvent(const IPMI::command_t& i_cmd, const msg_q_t& i_msgq);

    /**
     * @brief Give the resource provider a message to put in the eventq
     * @param[in] i_event, pointer to the new'd event (OEM SEL)
     */
    void postEvent(IPMI::oemSEL* i_event);

    /**
     * @brief Give the resource provider a message to put in the eventq
     * @param[in] i_event, pointer to the power event data to handle (OEM SEL)
     */
    void handlePowerMessage(IPMI::oemSEL* i_event);

  private:
    void attach(void);

    /**
     * Entry point for the resource provider
     */
    void execute(void);

    /**
     * Entry point for the timeout thread
     */
    void timeoutThread(void);

    /**
     * @brief Transmit a message over the IPMI interface
     * @param[in] i_msg, ptr to the message_q message
     * @note i_msg is not const because it contains a return code
     */
    int xmit(msg_t* i_msg);

    /**
     * @brief Transmit a synchronous message over the IPMI interface
     * @param[in] i_msg, ptr to the message_q message
     * @note this is a message used internally to send a message
     * over the IPMI interface and wait for a response from the BMC
     * @note i_msg is not const because it contains a return code
     */
    void xmit_sync(msg_t* i_msg);

    /**
     * @brief Transmit an asynchronous message over the IPMI interface
     * @param[in] i_msg, ptr to the message_q message
     * @note this is a message used internally to send a message
     * over the IPMI interface and not wait for a response from the BMC
     * @note i_msg is not const because it contains a return code
     */
    void xmit_async(msg_t* i_msg);

    /**
     * @brief Handle a message from the interface indicating the
     * interface has gone idle (and can be written to.)
     * @param[in] void
     */
    void idle(void);

    /**
     * @brief Handle an indication from the interface indicating the
     * BMC interface has a response message ready to read
     * @param[in] void
     */
    void response(void);

    /**
     * @brief Respond to an existing message.
     * @note This is used as the "base" response handler
     * @param[in] i_msg, the message to respond to
     */
    void response(IPMI::Message* i_msg);

    /**
     * @brief Respond to a message we're changing
     * @note This is used when we have a timeout and need to
     * respond to the caller.
     * @param[in] i_msg, the message to respond to
     * @param[in] i_cc, the complettion code
     */
    void response(IPMI::Message* i_msg, IPMI::completion_code i_cc);

    /**
     * @brief Query the BMC for interface capabilities
     * @param[in] void
     * @note this fills in iv_bmc_timeout, etc.
     */
    void getInterfaceCapabilities(void);

    /**
     * @brief Process incoming event messages if they're not processed by
     * any other task.
     * @param[in] void
     */
    void lastChanceEventHandler(void);

    msg_q_t           iv_msgQ;         //!< ipmi mesage queue
    IPMI::send_q_t    iv_sendq;        //!< msg to send queue
    IPMI::timeout_q_t iv_timeoutq;     //!< msgs waiting for a timeout
    IPMI::respond_q_t iv_respondq;     //!< msg respond pending list
    IPMI::event_q_t   iv_eventq;       //!< map events to msg_t
    msg_q_t           iv_last_chanceq; //!< last chance event queue

    // Protect the queues from the message loop and the timeout thread
    mutex_t     iv_mutex;
    sync_cond_t iv_cv;

    // The time, in seconds, the BMC told us is the max request/response
    // time interval.
    uint8_t     iv_bmc_timeout;

    // How many outstanding requests the BMC can handle
    uint8_t     iv_outstanding_req;

    // Size of the xmit buffer (max we can send)
    uint8_t     iv_xmit_buffer_size;

    // Size of the recv buffer (max BMC will send)
    uint8_t     iv_recv_buffer_size;

    // Recommended number of retries
    uint8_t     iv_retries;

    // Shutdown
    msg_t *     iv_shutdown_msg;     //!< shutdown msg to respond to

    //!< handle ipmi chassis power off request
    bool        iv_graceful_shutdown_pending;

    //!< handle ipmi chassis power off request modifier
    IPMI::power_request_type iv_chassis_power_mod;

    // Disallow copying this class.
    IpmiRP& operator=(const IpmiRP&);
    IpmiRP(const IpmiRP&);
};

#endif
