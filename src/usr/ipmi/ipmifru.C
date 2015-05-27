/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmi/ipmifru.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
 * @file ipmifru.C
 * @brief IPMI fru inventory definition
 */

#include "ipmifru.H"
#include "ipmiconfig.H"
#include <devicefw/driverif.H>
#include <devicefw/userif.H>

#include <sys/task.h>
#include <builtins.h>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>

#include <errl/errlmanager.H>
#include <errl/errlentry.H>

// Defined in ipmidd.C
extern trace_desc_t * g_trac_ipmi;
#define IPMI_TRAC(printf_string,args...) \
    TRACFCOMP(g_trac_ipmi,"fru: " printf_string,##args)

#ifdef CONFIG_BMC_IPMI

const uint8_t writeDataHeader = 3;

/**
 * setup _start and handle barrier
 */

/**
 * @brief  Constructor
 */
IpmiFRU::IpmiFRU(void):
    iv_msgQ(msg_q_create())
{
    task_create(&IpmiFRU::start, NULL);
}

/**
 * @brief  Destructor
 */
IpmiFRU::~IpmiFRU(void)
{
    msg_q_destroy(iv_msgQ);
}

void* IpmiFRU::start(void* unused)
{
    Singleton<IpmiFRU>::instance().execute();
    return NULL;
}

/**
 * @brief  Entry point of the fru ipmi thread
 */
void IpmiFRU::execute(void)
{
    // Mark as an independent daemon so if it crashes we terminate.
    task_detach();

    IPMI_TRAC(ENTER_MRK "execute: fru message loop");
    do {
        while (true)
        {
            msg_t* msg = msg_wait(iv_msgQ);

            const IPMIFRU::msg_type msg_type =
                static_cast<IPMIFRU::msg_type>(msg->type);

            // Invert the "default" by checking here. This allows the compiler
            // to warn us if the enum has an unhandled case but still catch
            // runtime errors where msg_type is set out of bounds.
            assert(msg_type <= IPMIFRU::MSG_LAST_TYPE,
                   "msg_type %d not handled", msg_type);

            switch(msg_type)
            {
            case IPMIFRU::MSG_WRITE_FRU_DATA:
                sendWriteFruData(msg);

                // done with the msg
                msg_free(msg);
                break;
            };
        } // while
    } while (false);

    return;
} // execute

///
/// @brief  Send write_fru_data msg to IpmiRP
///         called for msg->type MSG_WRITE_FRU_DATA
///
void IpmiFRU::sendWriteFruData(msg_t *i_msg)
{
    errlHndl_t err = NULL;
    const size_t l_maxBuffer = IPMI::max_buffer();

    // pull out the data - deviceId and offset are in data[0]
    const uint8_t &l_deviceId = (i_msg->data[0] >> 32);
    uint16_t l_offset = (i_msg->data[0] & 0xFFFFFFFF);
    uint16_t l_dataOffset = 0; // start at the l_data[0]

    size_t l_dataSize = i_msg->data[1]; // FRU data size
    uint8_t *l_data = static_cast<uint8_t*>(i_msg->extra_data);

    IPMI_TRAC(ENTER_MRK "sendWriteFruData for dev 0x%x, size %d",
                l_deviceId, l_dataSize);

    while ((l_dataSize > 0) && (err == NULL))
    {
        size_t this_size = std::min(l_maxBuffer, l_dataSize + writeDataHeader);
        uint8_t *this_data = new uint8_t[this_size];
        const uint16_t l_fruSize = this_size - writeDataHeader;

        // copy device ID, offset, fru data to new buffer
        this_data[0] = l_deviceId;
        this_data[1] = l_offset & 0xFF;
        this_data[2] = l_offset >> 8;
        memcpy(&this_data[writeDataHeader], l_data + l_dataOffset, l_fruSize);

        IPMI_TRAC(INFO_MRK "sending write_fru_data fru size %d offset %d",
                l_fruSize, l_offset);

        // update the offsets for the next time around
        l_offset += l_fruSize;
        l_dataOffset += l_fruSize;

        IPMI::completion_code cc = IPMI::CC_UNKBAD;
        err = IPMI::sendrecv(IPMI::write_fru_data(), cc, this_size, this_data);
        if (err)
        {
            IPMI_TRAC(ERR_MRK "Failed to send write_fru_data dev 0x%x",
                    l_deviceId);
            // err is set, so we'll break out of the while loop
        }
        else if (cc != IPMI::CC_OK)
        {
            IPMI_TRAC(ERR_MRK "Failed to send write_fru_data dev 0x%x CC 0x%x",
                    l_deviceId, cc);
            // stop sending; breaks out of the while loop
            l_dataSize = 0;
        }
        else
        {
            l_dataSize -= l_fruSize;
        }

        //  delete the buffer returned from sendrecv
        delete [] this_data;

    } // while there is data to send and no error

    if (err)
    {
        err->collectTrace(IPMI_COMP_NAME);
        errlCommit(err, IPMI_COMP_ID);
    }

    // delete the space the caller allocated; we need to do this because
    //  we're async relative to the caller
    delete [] l_data;

    return;
} // sendWriteFruData

namespace IPMIFRU
{
    ///
    /// @brief  Function to send fru data to the IpmiFRU msg queue
    ///
    void writeData(uint8_t i_deviceId, uint8_t *i_data,
                uint32_t i_dataSize, uint32_t i_offset)
    {
        IPMI_TRAC(ENTER_MRK "writeData(deviceId 0x%x size %d offset %d)",
                i_deviceId, i_dataSize, i_offset);

        // one message queue to the FRU thread
        static msg_q_t mq = Singleton<IpmiFRU>::instance().msgQueue();

        // send data in msg to fru thread
        msg_t *msg = msg_allocate();

        msg->type = MSG_WRITE_FRU_DATA;
        msg->data[0] = (static_cast<uint64_t>(i_deviceId) << 32) | i_offset;
        msg->data[1] = i_dataSize;

        uint8_t* l_data = new uint8_t[i_dataSize];
        memcpy(l_data, i_data, i_dataSize);
        msg->extra_data = l_data;

        //Send the msg (async) to the fru thread
        int rc = msg_send(mq, msg);

        //Return code is non-zero when the message queue is invalid
        //or the message type is invalid.
        if ( rc )
        {
            IPMI_TRAC(ERR_MRK "Failed (rc=%d) to send message for dev 0x%x.",
                    rc, i_deviceId);
            delete [] l_data; // delete, since msg wasn't sent
        }

        IPMI_TRAC(EXIT_MRK "writeData");
        return;
    } // writeData

}; // IPMIFRU namespace
#endif // CONFIG_BMC_IPMI
