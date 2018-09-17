/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmibt.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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
#include <ipmi/ipmiif.H>
#include <errno.h>
#include <config.h>

// Defined in ipmidd.C
extern trace_desc_t * g_trac_ipmi;
#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"bt: " printf_string,##args)

namespace IPMI
{
    ///
    /// @brief msg ctor
    /// @param[in] i_cmd, the network function & command
    /// @param[in] i_len, the length of the data
    /// @param[in] i_data, the data (new'd space)
    ///
    BTMessage::BTMessage(const command_t& i_cmd, const uint8_t i_len,
                         uint8_t* i_data):
        Message(i_cmd, i_len, i_data)
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
    errlHndl_t BTMessage::phy_xmit(void)
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

        // If we're not going to remain on the i_sendq, we need to delete
        // the data.
        if ((err) || (iv_state != EAGAIN))
        {
            delete[] iv_data;
            iv_data = NULL;
        }

        if (!err)
        {
            // If there wasn't an error, and we don't see EAGAIN, we need to
            // queue up for a response. Note we queue up both synchronus and
            // asynchronous messages, and let the subclasses handle what
            // happens when the response arrives (because it will.)
            if (iv_state != EAGAIN)
            {
                Singleton<IpmiRP>::instance().queueForResponse(*this);
            }

            // Otherwise we had no error, but were told EAGAIN, which means the
            // interface was busy.
            else
            {
                IPMI_TRAC(INFO_MRK "busy, queue head %x:%x", iv_netfun, iv_cmd);
            }
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

            // If the reading the response fails, the caller may still call
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
    /// @param[in] i_cmd, the network function & command
    /// @param[in] i_len, the length of the data
    /// @param[in] i_data, the data (new'd space)
    ///
    BTSyncMessage::BTSyncMessage(const command_t& i_cmd,
                                 const uint8_t i_len,
                                 uint8_t* i_data):
        BTMessage(i_cmd, i_len, i_data)
    {
    }

    ///
    /// @brief BTAsyncMessage ctor
    /// @param[in] i_cmd, the network function & command
    /// @param[in] i_len, the length of the data
    /// @param[in] i_data, the data (new'd space)
    ///
    BTAsyncMessage::BTAsyncMessage(const command_t& i_cmd,
                                   const uint8_t i_len,
                                   uint8_t* i_data):
        BTMessage(i_cmd, i_len, i_data)
    {
    }

    ///
    /// @brief BTAsyncReadEventMessage ctor
    /// @param[in] i_cmd, the network function & command
    /// @param[in] i_len, the length of the data
    /// @param[in] i_data, the data (new'd space)
    ///
    BTAsyncReadEventMessage::BTAsyncReadEventMessage(const command_t& i_cmd,
                                                     const uint8_t i_len,
                                                     uint8_t* i_data):
        BTAsyncMessage(i_cmd, i_len, i_data)
    {
    }

    ///
    /// @brief sync msg transmit
    ///
    bool BTSyncMessage::xmit(void)
    {
        errlHndl_t err = BTMessage::phy_xmit();

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

        // If we had an i/o error we want the idle loop to stop
        // If we got EAGAIN we want the idle loop to stop as we just
        // put a message on the queue which couldn't be sent.
        return (iv_state != 0);
    }

    ///
    /// @brief async msg transmit
    ///
    bool BTAsyncMessage::xmit(void)
    {
        errlHndl_t err = BTMessage::phy_xmit();

        if (err)
        {
            // Not much we're going to do here, so just commit the error.
            err->collectTrace(IPMI_COMP_NAME);
            errlCommit(err, IPMI_COMP_ID);
        }

        // If we had an i/o error we want the idle loop to stop.
        // If we got EAGAIN we want the idle loop to stop as we just
        // put a message on the queue which couldn't be sent.
        return (iv_state != 0);
    }

    ///
    /// @brief sync handle response
    ///
    void BTSyncMessage::response(msg_q_t i_msgQ)
    {
        // Send the response to the original caller of sendrecv()
        int rc = msg_respond(i_msgQ, iv_msg);
        if (rc)
        {
            // Not much we're going to do here, so lets commit an error and
            // the original request will timeout.
            IPMI_TRAC(ERR_MRK "msg_respond() i/o error (response) %d", rc);

            /*@
             * @errortype       ERRL_SEV_UNRECOVERABLE
             * @moduleid        IPMI::MOD_IPMISRV_REPLY
             * @reasoncode      IPMI::RC_INVALID_QRESPONSE
             * @userdata1       rc from msg_respond()
             * @devdesc         msg_respond() failed
             * @custdesc        Firmware error during system boot
             */
            errlHndl_t err = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                IPMI::MOD_IPMISRV_REPLY,
                IPMI::RC_INVALID_QRESPONSE,
                rc,
                0,
                true);

            err->collectTrace(IPMI_COMP_NAME);
            errlCommit(err, IPMI_COMP_ID);

            // Frotz the response data
            delete[] iv_data;
            iv_data = NULL;
        }
    }

    ///
    /// @brief async msg response
    ///
    void BTAsyncMessage::response(msg_q_t)
    {
        // If our completion code isn't CC_OK, lets log that fact. There's
        // not much we can do, but at least this might give a hint that
        // something is awry. Note the caller doesn't care, or this would
        // be synchronous.
        if (iv_cc != IPMI::CC_OK)
        {
            IPMI_TRAC(ERR_MRK "async message (%x:%x seq %d) completion code %x",
                      iv_netfun, iv_cmd, iv_seq, iv_cc);
        }

        // Yes, this is OK - there is no further reference to this object.
        delete this;
    }

    ///
    /// @brief handle the read of an event (OEM SEL)
    ///
    void BTAsyncReadEventMessage::response(msg_q_t)
    {
        do {
            // If our completion code isn't CC_OK, lets log that fact. There's
            // not much we can do, but at least this might give a hint that
            // something is awry.
            if (iv_cc != IPMI::CC_OK)
            {
                IPMI_TRAC(ERR_MRK "read event message (%x:%x seq %d) "
                          "completion code %x",
                          iv_netfun, iv_cmd, iv_seq, iv_cc);

                if (iv_cc == IPMI::CC_CMDSPC1)
                {
                    // We got a completion code with 0x80, which is no data
                    // Let's trace the event, but not log an error.
                    IPMI_TRAC(ERR_MRK "SEL returned with no data, not logging "
                              "an error");
                    break;
                }

                /*@
                 * @errortype       ERRL_SEV_INFORMATIONAL
                 * @moduleid        IPMI::MOD_IPMISRV_REPLY
                 * @reasoncode      IPMI::RC_READ_EVENT_FAILURE
                 * @userdata1       command of message
                 * @userdata2       completion code
                 * @devdesc         an async completion code was not CC_OK
                 * @custdesc        Unexpected IPMI completion code from the BMC
                 */
                errlHndl_t err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    IPMI::MOD_IPMISRV_REPLY,
                    IPMI::RC_READ_EVENT_FAILURE,
                    iv_cmd,
                    iv_cc,
                    true);

                err->collectTrace(IPMI_COMP_NAME);
                errlCommit(err, IPMI_COMP_ID);
                break;
            }
 
            // Before we self destruct, we need to turn the data collected in to
            // a record we can pass to the waiting event handler.
            Singleton<IpmiRP>::instance().postEvent(new IPMI::oemSEL(iv_data));

        } while(false);

        // Yes, this is OK - there is no further reference to this object.
        delete this;
    }

    ///
    /// @brief static factory
    ///
    /// Implement the factory member in terms of the BT interface. This is done
    /// in each of the back-end implementations, only one of which should be
    /// configured in at build time.
    ///
    /// @param[in] i_cmd, the network function & command
    /// @param[in] i_len, the length of the data
    /// @param[in] i_data, the data (allocated space)
    /// @param[in] i_type, synchronous or async
    ///
    /// @return a pointer to a new'd Message object
    ///
    Message* Message::factory(const command_t& i_cmd, const uint8_t i_len,
                              uint8_t* i_data, const message_type i_type)
    {
        Message* new_message = NULL;

        switch(i_type)
        {
        case TYPE_SYNC:
            new_message = new BTSyncMessage(i_cmd, i_len, i_data);
            break;
        case TYPE_ASYNC:
            new_message = new BTAsyncMessage(i_cmd, i_len, i_data);
            break;
        case TYPE_EVENT:
            new_message = new BTAsyncReadEventMessage(i_cmd, i_len, i_data);
            break;
        default:
            // We have ourselves a bug
            assert(false, "ipmi message factory: unk type %d\n", i_type);
            break;
        }

        return new_message;
    }
};
