/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/mctprp.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include <mctp/mctp_message_types.H>
#include <hbotcompid.H>
#include <targeting/common/targetservice.H>

extern const char* VFS_ROOT_MSG_MCTP_OUT;
extern const char* VFS_ROOT_MSG_MCTP_IN;

struct ctx {
  struct mctp    *mctp;
  struct binding *binding;
  bool           verbose;
  int            local_eid;
};

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
        msg_send(iv_inboundMsgQ, msg);
    }
}

// TODO handle messages correctly
static void rx_message(uint8_t i_eid, void * i_data, void *i_msg, size_t i_len)
{
   TRACDBIN(g_trac_mctp, "mctp rx_message:", i_msg, i_len);
}

static void * handle_inbound_messages_task(void*)
{
    TRACFCOMP(g_trac_mctp, "Starting to handle inbound commands");
    Singleton<MctpRP>::instance().handle_inbound_messages();
    return nullptr;
}

void MctpRP::handle_inbound_messages(void)
{
    task_detach();

    uint8_t l_rc = 0;

    while(1)
    {
        msg_t* msg = msg_wait(iv_inboundMsgQ);

        switch(msg->type)
        {
          case MCTP::MSG_INIT:
              TRACFCOMP(g_trac_mctp,
                        "Found kcs msg type: MCTP::MSG_INIT which we do not support, ignoring it",
                        msg->type);
              break;
          case MCTP::MSG_TX_BEGIN:
              TRACDCOMP(g_trac_mctp, "BMC has sent us a message we need to read");
              mctp_hostlpc_rx_start(iv_hostlpc);
              break;
          case MCTP::MSG_RX_COMPLETE:
              // BMC has completed receiving the message we sent
              TRACDCOMP(g_trac_mctp, "BMC says they are complete reading what we sent");
              mctp_hostlpc_tx_complete(iv_hostlpc);
              break;
          case MCTP::MSG_DUMMY:
              // This is used when the BMC wants to write the status register
              // and notify us that it was set
              l_rc = this->_mctp_process_version();
              break;
          default:
              // Just leave a trace and move on with our life
              TRACFCOMP(g_trac_mctp,
                        "Found invalid kcs msg type: 0x%.02x, ignoring it",
                        msg->type);
              break;
        }

        if(l_rc != 0)
        {
            break;
        }

    }
}

static void * handle_outbound_messages_task(void*)
{
    TRACFCOMP(g_trac_mctp, "Starting to handle outbound commands");
    Singleton<MctpRP>::instance().handle_outbound_messages();
    return nullptr;
}

void MctpRP::handle_outbound_messages(void)
{
    task_detach();

    uint8_t l_rc = 0;



    // Do't start sending messages to the BMC until the channel is active
    while(!iv_channelActive)
    {
        nanosleep(0, NS_PER_MSEC * 500);
    }

    while(1)
    {
        msg_t* msg = msg_wait(iv_outboundMsgQ);

        switch(msg->type)
        {

          // Send a message
          case MCTP::MSG_SEND_PLDM:
              // The first byte of MCTP payload describes the contents
              // of the payload. Set first byte to be TYPE_PLDM (0x01)
              // so BMC knows to route the MCTP message to it's PLDM driver.
              *reinterpret_cast<uint8_t *>(msg->extra_data) = MCTP_MSG_TYPE_PLDM;
              TRACDBIN(g_trac_mctp, "pldm message : ", msg->extra_data , msg->data[0]);
              mctp_message_tx(iv_mctp, BMC_EID, msg->extra_data, msg->data[0]);
              break;
          default:
              // just mark a trace and move on with our lives
              TRACFCOMP(g_trac_mctp,
                        "Recieved am outbound MCTP message with a payload type 0x%.02x we do not know how to handle",
                        msg->type);
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
    else
    {
        iv_channelActive = true;
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

    msg_q_register(iv_inboundMsgQ, VFS_ROOT_MSG_MCTP_IN);
    msg_q_register(iv_outboundMsgQ, VFS_ROOT_MSG_MCTP_OUT);

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
    task_create(handle_inbound_messages_task, NULL);

    task_create(handle_outbound_messages_task, NULL);

    // Start the poll kcs status daemon which will read the KCS status reg every 100 ms and if
    // we see that the OBF bit in the KCS status register is set we will read the OBR KCS data reg
    // and send a message to the handle_obf_status daemon
    task_create(poll_kcs_status_task, NULL);

    // This ctx struct is a way to pass information we want into the mctp core logic
    // the core logic will call the registered rx_message function with the ctx struct as
    // a parm, this allows use to pass information about the context we are in to that func
    struct ctx *ctx, _ctx;
    ctx = &_ctx;
    ctx->local_eid = HOST_EID;
    ctx->mctp = iv_mctp;

    // Set the receive function to be rx_message which
    // will handle the message in the RX space accordingly
    mctp_set_rx_all(ctx->mctp, rx_message, ctx);

    TRACFCOMP(g_trac_mctp, "MctpRP::_init exit");

    return l_errl;
}

// Emtpy constructor will create the message queue and initialize the mctp core
MctpRP::MctpRP(void):
    iv_hostlpc(nullptr),
    iv_mctp(mctp_init()),
    iv_inboundMsgQ(msg_q_create()),
    iv_outboundMsgQ(msg_q_create()),
    iv_channelActive(false)
{
}

// Set the function that will be called when mctp.so is loaded
TASK_ENTRY_MACRO( MctpRP::init );


