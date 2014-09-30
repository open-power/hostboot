/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmibt.C $                                       */
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
 * @file ipmibt.C
 * @brief code for the IPMI BT message class
 */

#include <devicefw/driverif.H>
#include <devicefw/userif.H>
#include <ipmi/ipmi_reasoncodes.H>
#include <errl/errlmanager.H>

#include <util/lockfree/counter.H>

#include "ipmibt.H"
#include "ipmirp.H"
#include <errno.h>
#include <config.h>

// Defined in ipmidd.C
extern trace_desc_t * g_trac_ipmi;
#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"bt: "printf_string,##args)

namespace IPMI
{
    ///
    /// @brief msg ctor
    /// @param[in] i_netfun, the network function
    /// @param[in] i_cmd, the network command
    /// @param[in] i_data, the data for the command
    /// @param[in] i_len, the length of the data
    /// @param[in] i_data, the data (new'd space)
    ///
    BTMessage::BTMessage(const network_function i_netfun,
                         const uint8_t i_cmd, const uint8_t i_len,
                         uint8_t* i_data):
        Message(i_netfun, i_cmd, i_len, i_data)
    {
        // Sometimes we need to get back to this IPMI msg from the msg_t,
        // and sometimes we need to get the msg_t from the IPMI msg. So they
        // know about each other.
        iv_msg->extra_data = static_cast<void*>(this);
        iv_msg->type = MSG_STATE_SEND;
    }

    ///
    /// @brief  Transimit - send the data out the device interface
    ///
    errlHndl_t BTMessage::xmit(void)
    {
        // When a uint8_t is constructed, it's initialied to 0. So,
        // this initializes the sequence counter to 0.
        static Util::Lockfree::Counter<uint8_t> seq;

        // Assign a "unique" sequence number. Note that we don't
        // leverage the network function to create a sequence
        // number, we just keep an 8 bit counter. This *should*
        // be ok - it means we will get back the response to any
        // particular message before we send another 254 messages.
        // This seems safe.
        iv_seq = seq.next();

        // Initialize the error state of the message
        iv_state = 0;

        size_t unused_size;
        errlHndl_t err = deviceOp(DeviceFW::WRITE,
                              TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                              static_cast<void*>(this),
                              unused_size,
                              DeviceFW::IPMIBT);

        // If we're not going to remain on the i_sendq, we need to
        // delete the data.
        if ((err) || (iv_state != EAGAIN))
        {
            delete[] iv_data;
        }

        return err;
    }

    ///
    /// @brief  Receive - get bits off the block-transfer interface
    ///
    errlHndl_t BTMessage::recv(void)
    {
        // Check to make sure we are in the right state (coding error)
        assert(iv_data == NULL);

        // Go down to the device and read. Note the driver is BT specific
        // and we're BT specific so we can send down a BTMessage object.
        size_t unused_length;
        errlHndl_t err = deviceOp(DeviceFW::READ,
                               TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                               static_cast<void*>(this),
                               unused_length,
                               DeviceFW::IPMIBT);
        if (err)
        {
            delete[] iv_data;

            // If the reading the reponse fails, the caller may still call
            // delete[] on the pointer we return to them. This makes sure that
            // for this case, they're just deleting NULL.
            iv_data = NULL;
            iv_len = 0;
        }

        // For BT messages, the sequence number is the key - for other xports
        // it might be different. Note the sequence number is a reference to
        // our base's iv_key, so we're done.
        return err;
    }

    ///
    /// @brief BTSyncMessage ctor
    /// @param[in] i_netfun, the network function
    /// @param[in] i_cmd, the network command
    /// @param[in] i_data, the data for the command
    /// @param[in] i_len, the length of the data
    /// @param[in] i_data, the data (new'd space)
    ///
    BTSyncMessage::BTSyncMessage(const network_function i_netfun,
                                 const uint8_t i_cmd, const uint8_t i_len,
                                 uint8_t* i_data):
        BTMessage(i_netfun, i_cmd, i_len, i_data)
    {
    }

    ///
    /// @brief BTSyncMessage ctor
    /// @param[in] i_netfun, the network function
    /// @param[in] i_cmd, the network command
    /// @param[in] i_data, the data for the command
    /// @param[in] i_len, the length of the data
    /// @param[in] i_data, the data (new'd space)
    ///
    BTAsyncMessage::BTAsyncMessage(const network_function i_netfun,
                                   const uint8_t i_cmd, const uint8_t i_len,
                                   uint8_t* i_data):
        BTMessage(i_netfun, i_cmd, i_len, i_data)
    {
    }

    ///
    /// @brief sync msg transmit
    ///
    bool BTSyncMessage::xmit(respond_q_t& i_respondq)
    {
        errlHndl_t err = BTMessage::xmit();

        if (err)
        {
            // Something went wrong, so we need to respond back with the error
            iv_errl = err;

            msg_q_t mq = Singleton<IpmiRP>::instance().msgQueue();
            int rc = msg_respond(mq, iv_msg);
            if (rc)
            {
                // Yuk. We can't respond back to our caller with that error. So,
                // we'll commit it. I don't see much sense in creating another
                // error log, so we'll just trace the msg_respond() failure.
                IPMI_TRAC(ERR_MRK "msg_respond() i/o error (transmit) %d", rc);
                err->collectTrace(IPMI_COMP_NAME);
                errlCommit(err, IPMI_COMP_ID);
                iv_errl = NULL;
            }
        }

        // Otherwise, we either were transmitted ok or we were told EAGAIN.
        // We can tell this by iv_state - if it's not EAGAIN, we need to go hang
        // out on the response queue.
        else if (iv_state != EAGAIN)
        {
            i_respondq[iv_seq] = iv_msg;
        }
        else {
            IPMI_TRAC(INFO_MRK "busy, queue head %x:%x", iv_netfun, iv_cmd);
        }

        // If we had an i/o error we want the idle loop to stop
        // If we got EAGAIN we want the idle loop to stop as we just
        // put a message on the queue which couldn't be sent.
        return (iv_state != 0);
    }

    ///
    /// @brief async msg transmit
    ///
    bool BTAsyncMessage::xmit(respond_q_t&)
    {
        errlHndl_t err = BTMessage::xmit();
        bool io_error = (iv_state != 0);

        if (err)
        {
            // Not much we're going to do here, so just commit the error.
            err->collectTrace(IPMI_COMP_NAME);
            errlCommit(err, IPMI_COMP_ID);
        }

        // If we didn't have an error but we got back an EAGAIN
        // we've been queued up for a retry. Otherwise, we're free
        // to commit suicide.
        else if (iv_state != EAGAIN)
        {
            // Yes, this is OK - there is no further reference to this object.
            delete this;
        }
        else {
            IPMI_TRAC(INFO_MRK "busy, queue head %x:%x", iv_netfun, iv_cmd);
        }

        // If we had an i/o error we want the idle loop to stop.
        // If we got EAGAIN we want the idle loop to stop as we just
        // put a message on the queue which couldn't be sent. Note
        // we need to use this mechanism rather than letting the caller
        // check iv_state as we may have just deleted ourselves.
        return io_error;
    }
};
