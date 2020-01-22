/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/mctprp.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include "mctprp.H"
#include "libmctp.h"
#include "libmctp-hostlpc.h"
#include <stdlib.h>
#include <string.h>
#include <initservice/taskargs.H>
#include <sys/time.h>
#include <trace/interface.H>
#include <intr/interrupt.H>
#include <lpc/lpcif.H>
#include <lpc/lpc_const.H>
#include <devicefw/userif.H>
#include <errl/errlmanager.H>
#include <hbotcompid.H>

#include <targeting/common/targetservice.H>


trace_desc_t* g_trac_mctp = nullptr;
TRAC_INIT(&g_trac_mctp, MCTP_COMP_NAME, 4*KILOBYTE, TRACE::BUFFER_SLOW);

static void * poll_kcs_status_task(void*)
{
    TRACFCOMP(g_trac_mctp, "Starting to poll status register");
    Singleton<MctpRP>::instance().poll_kcs_status();
    return nullptr;
}

void MctpRP::poll_kcs_status(void)
{
    task_detach();
    errlHndl_t l_errl = nullptr;
    msg_t* msg = nullptr;
    uint8_t l_status = 0;
    size_t l_size = sizeof(uint8_t);

    while(1)
    {
        // Perform an LPC read on the KCS status register to see if the BMC has sent us a message.
        // We know that the BMC has sent a message if the OBF bit in the status reg is set.
        l_errl = DeviceFW::deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                      &l_status,
                                      l_size,
                                      DEVICE_LPC_ADDRESS(LPC::TRANS_IO,
                                                         LPC::KCS_STATUS_REG));
        // If there was an error reading the status reg then something is wrong and we should exit
        if(l_errl)
        {
            // todo
            errlCommit(l_errl, MCTP_COMP_ID);
            // Do something.. ? commit ?
            break;
        }

        // If we found that the OBF bit is not set then just wait 100 ms and try poll again
        if(!(l_status & KCS_STATUS_OBF))
        {
            nanosleep(0,100 * NS_PER_MSEC);
            continue;
        }

        // otherwise read the ODR and send a message to the mctp_cmd_daemon
        // when the host reads this register it will clear the OBF bit in the status register
        l_errl = DeviceFW::deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                      &l_status,
                                      l_size,
                                      DEVICE_LPC_ADDRESS(LPC::TRANS_IO,
                                                         LPC::KCS_DATA_REG));

        if(l_errl)
        {
            // todo handle error ?
        }

        msg = msg_allocate();
        msg->type = l_status;
        msg_send(iv_msgQ, msg);
    }
}

static void * handle_kcs_cmd_task(void*)
{
    TRACFCOMP(g_trac_mctp, "Starting to handle kcs commands");
    Singleton<MctpRP>::instance().handle_kcs_cmd();
    return nullptr;
}

void MctpRP::handle_kcs_cmd(void)
{
    task_detach();

    uint8_t l_rc = 0;

    while(1)
    {
        msg_t* msg = msg_wait(iv_msgQ);

        switch(msg->type)
        {
          case MCTP::MSG_INIT:
              // TODO
              // Error because we should never see this
              break;
          case MCTP::MSG_TX_BEGIN:
              // TODO
              // Go read message from RX buffer
              break;
          case MCTP::MSG_RX_COMPLETE:
              // TODO
              // Send next message if any are waiting
              break;
          case MCTP::MSG_DUMMY:
              // This is used when the BMC wants to write the status register
              // and notify us that it was set
              l_rc = this->_mctp_process_version();
              // Add trace that channel is active and what the negotiated version should be
              break;
          default:
               // TODO
              // Error because its an unknown type
              break;
        }

        if(l_rc != 0)
        {
            break;
        }

    }
}


uint8_t MctpRP::_mctp_process_version(void)
{
    errlHndl_t l_errl = nullptr;
    uint8_t l_rc = 0;
    uint8_t l_status = 0;
    size_t l_size = sizeof(uint8_t);
    // Perform an LPC read on the KCS status register to verify the channel is active
    // and that the BMC has written the negotiated MCTP version
    l_errl = DeviceFW::deviceRead(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                  &l_status,
                                  l_size,
                                  DEVICE_LPC_ADDRESS(LPC::TRANS_IO,
                                                      LPC::KCS_STATUS_REG));

    // Verify that the channel is active
    if(!(l_status & KCS_STATUS_CHANNEL_ACTIVE))
    {
        TRACFCOMP(g_trac_mctp, "mctp_process_version: Error ! Channel is not active!" );
        // todo
        errlCommit(l_errl, MCTP_COMP_ID);
        l_rc = 1;
        // Commit error
    }

    // Read the negotiated version from the lpcmap hdr that the bmc should have
    // set prior to setting the KCS_STATUS_CHANNEL_ACTIVE bit
    {
        struct mctp_lpcmap_hdr *hdr;
        hdr = iv_hostlpc->lpc_hdr;
        // todo set system attribute
        TRACFCOMP(g_trac_mctp, "mctp_process_version: Negotiated version is : %d", hdr->negotiated_ver);
    }
    return l_rc;
}

void MctpRP::init(errlHndl_t& o_errl)
{
    // This will call the MctpRP construction which initializes MCTP
    // polling loops
    o_errl = Singleton<MctpRP>::instance()._init();;
}

errlHndl_t MctpRP::_init(void)
{
    TRACFCOMP(g_trac_mctp, "MctpRP::_init entry");
    errlHndl_t l_errl = nullptr;
    // Get the virtual address for the LPC bar and add the offsets
    // to the MCTP/PLDM space within  the FW Space of the LPC window.
    auto l_bar = LPC::get_lpc_virtual_bar() +
                        LPC::LPCHC_FW_SPACE +
                        LPC::LPCHC_MCTP_PLDM_BASE;

    // Initialize the host-lpc binding for hostboot
    iv_hostlpc = mctp_hostlpc_init_hostboot(l_bar);

    // Register the binding to the LPC bus we are using for this
    // MCTP configuration. NOTE this will trigger the "start" function
    // associated with the iv_hostlpc binding which does starts the
    // KCS init handshake with the BMC
    mctp_register_bus(iv_mctp, &iv_hostlpc->binding, HOST_EID);

    // Start cmd daemon first because we want it ready if poll daemon finds something right away
    task_create(handle_kcs_cmd_task, NULL);

    // Start the poll kcs status daemon which will read the KCS status reg every 100 ms and if
    // we see that the OBF bit in the KCS status register is set we will read the OBR KCS data reg
    // and send a message to the handle_kcs_cmd daemon
    task_create(poll_kcs_status_task, NULL);

    TRACFCOMP(g_trac_mctp, "MctpRP::_init exit");

    return l_errl;
}

// Emtpy constructor will create the message queue and initialize the mctp core
MctpRP::MctpRP(void):
    iv_hostlpc(nullptr),
    iv_mctp(mctp_init()),
    iv_msgQ(msg_q_create())
{
}

// Set the function that will be called when mctp.so is loaded
TASK_ENTRY_MACRO( MctpRP::init );


