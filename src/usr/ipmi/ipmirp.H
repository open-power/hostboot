/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmirp.H $                                    */
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

#ifndef __IPMI_IPMIRP_H
#define __IPMI_IMPIRP_H

/**
 * @file ipmirp.H
 * @brief IPMI service provider declariation
 */

#include <stdint.h>
#include <builtins.h>
#include <ipmi/ipmiif.H>
#include "ipmibt.H"
#include <errl/errlentry.H>
#include <sys/msg.h>
#include <sys/sync.h>
#include <list>
#include <map>
#include <util/locked/list.H>
#include <intr/interrupt.H>
#include <limits.h>

namespace TARGETING
{
    class Target;
};

class IpmiRP
{
  public:

    /**
     * Initialize the IPMI service
     * @param[in] o_errl, NULL if OK
     */
    static void daemonProcess(errlHndl_t& o_errl);

    /**
     * Thread start routine for the resource provider
     * @param[in] void*, unused
     */
    static void* start(void* unused);

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

  private:

    /**
     * Entry point for the resource provider
     */
    void execute(void);

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
     * @brief Handle an indication from the interface indicating the
     * BMC interface has an event/sms message ready to read
     * @param[in] void
     */
    void event(void);

    msg_q_t           iv_msgQ;        //!< ipmi mesage queue
    IPMI::send_q_t    iv_sendq;       //!< msg to send queue
    IPMI::respond_q_t iv_respondq;    //!< msg respond pending list

    // Disallow copying this class.
    IpmiRP& operator=(const IpmiRP&);
    IpmiRP(const IpmiRP&);
};

#endif
