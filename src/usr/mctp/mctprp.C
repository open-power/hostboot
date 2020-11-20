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

/**
 * @file  mctprp.C
 * @brief Resource provider for MCTP stack during IPL time
 */

// Headers from local directory
#include "mctprp.H"
#include "libmctp-hostlpc.h"
// System Headers
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <kernel/console.H>
// Userspace Headers
#include <devicefw/userif.H>
#include <errl/errlmanager.H>
#include <mctp/mctp_reasoncodes.H>
#include <pldm/pldmif.H>
#include <hbotcompid.H>
#include <initservice/taskargs.H>
#include <intr/interrupt.H>
#include <lpc/lpcif.H>
#include <lpc/lpc_const.H>
#include <targeting/common/targetservice.H>
#include <trace/interface.H>
#include <initservice/initserviceif.H>
#ifdef CONFIG_CONSOLE
#include <console/consoleif.H>
#endif

using namespace ERRORLOG;
using namespace MCTP;

extern const char* VFS_ROOT_MSG_MCTP_OUT;
extern const char* VFS_ROOT_MSG_MCTP_IN;

trace_desc_t* g_trac_mctp = nullptr;
TRAC_INIT(&g_trac_mctp, MCTP_COMP_NAME, 4*KILOBYTE, TRACE::BUFFER_SLOW);

namespace MCTP
{
    void register_mctp_bus(void)
    {
        return Singleton<MctpRP>::instance().register_mctp_bus();
    }
}

// This isn't utilized right now but it gives us flexibility
// with our binding in the future to pass parameters into the
// rx logic
struct ctx {
  struct mctp    *mctp;
  struct binding *binding;
  bool           verbose;
  int            local_eid;
};

// Static function used to launch task calling poll_kcs_status on
// the MctpRP singleton
static void * poll_kcs_status_task(void*)
{
    TRACFCOMP(g_trac_mctp, "Starting to poll status register");
    Singleton<MctpRP>::instance().poll_kcs_status();
    return nullptr;
}

// Call hostlpc binding function mctp_hostlpc_tx_complete but wrap it in a mutex lock
static void lock_and_mctp_hostlpc_tx_complete(struct mctp_binding_hostlpc *hostlpc,
                                              mutex_t &mutex)
{
    mutex_lock(&mutex);
    mctp_hostlpc_tx_complete(hostlpc);
    mutex_unlock(&mutex);
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
        // Perform an LPC read on the KCS status register to see if the BMC has
        // sent the Host a message. We know that the BMC has sent a message if
        // the OBF bit in the status reg is set.
        l_errl =
            DeviceFW::deviceRead(
                            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            &l_status,
                            l_size,
                            DEVICE_LPC_ADDRESS(LPC::TRANS_IO,
                                               LPC::KCS_STATUS_REG));
        // If there was an error reading the status reg then something is wrong
        // and we should exit
        if(l_errl)
        {
            // TODO RTC: 249716
            // Do something.. ? fail ? retry ?
            errlCommit(l_errl, MCTP_COMP_ID);
            break;
        }

        // If we found that the OBF bit is not set then wait 1 ms and try
        // poll again
        if(!(l_status & KCS_STATUS_OBF))
        {
            nanosleep(0,1 * NS_PER_MSEC);
            continue;
        }

        // otherwise read the ODR and send a message to the mctp_cmd_daemon
        // when the host reads this register it will clear the OBF bit in the
        // status register
        l_errl =
            DeviceFW::deviceRead(
                            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            &l_status,
                            l_size,
                            DEVICE_LPC_ADDRESS(LPC::TRANS_IO,
                                               LPC::KCS_DATA_REG));

        if(l_errl)
        {
            // TODO RTC: 249716
            // Do something.. ? fail ? retry ?
            errlCommit(l_errl, MCTP_COMP_ID);
            break;
        }

        switch(l_status)
        {
          case MSG_INIT:
              TRACFCOMP(g_trac_mctp,
                        "Found kcs msg type: MCTP::MSG_INIT which we do not support, ignoring it",
                        msg->type);
              break;
          case MSG_TX_BEGIN:
              TRACDCOMP(g_trac_mctp, "BMC has sent us a message we need to read");
              mctp_hostlpc_rx_start(iv_hostlpc);
              break;
          case MSG_RX_COMPLETE:
              // BMC has completed receiving the message we sent
              TRACDCOMP(g_trac_mctp, "BMC says they are complete reading what we sent");
              lock_and_mctp_hostlpc_tx_complete(iv_hostlpc, iv_mctp_mutex);
              break;
          case MSG_DUMMY:

              // The BMC will send us this message after writing the status
              // register during the initization sequence to notify us they
              // have filled out info in the config section of the lpc space
              // and has activated the KCS interface
              l_errl = this->_mctp_channel_init();

              if(l_errl)
              {
                  uint32_t l_fatalEid = l_errl->eid();
                  errlCommit(l_errl, MCTP_COMP_ID);
#ifdef CONFIG_CONSOLE
                  CONSOLE::displayf(CONSOLE::DEFAULT, NULL,
                                    "MCTP initialization failed! The commited error log 0x%X will be in hostboot dump but will not make it to BMC",
                                    l_fatalEid);
#endif

                  // 2nd param "true" indicates we want to the call the
                  // function to trigger a shutdown in a separate thread.
                  // This allows us to register for and handle shutdown events
                  // in this thread.
                  INITSERVICE::doShutdown(l_fatalEid, true);
              }
              break;
          default:
              // Just leave a trace and move on with our life
              TRACFCOMP(g_trac_mctp,
                        "Found invalid kcs msg type: 0x%.02x, ignoring it",
                        msg->type);
              break;
        }
    }
}

static void rx_message(uint8_t i_eid, void * i_data, void *i_msg, size_t i_len)
{
   TRACDBIN(g_trac_mctp, "mctp rx_message:", i_msg, i_len);

   uint8_t * l_pByteBuffer = reinterpret_cast<uint8_t *>(i_msg);

   // First byte of the msg should be the MCTP payload type.
   // For now we only support PLDM over MCTP
   switch(*l_pByteBuffer)
   {
      case MCTP_MSG_TYPE_PLDM :
      {
          errlHndl_t errl = nullptr;
          // Offset into sizeof(MCTP::MCTP_MSG_TYPE_PLDM) MCTP packet payload
          // as where PLDM message begins. (see DSP0236 v1.3.0 figure 4)
          // Also update the len param to account for this offset
          errl = PLDM::routeInboundMsg(
                            ( reinterpret_cast<uint8_t *>(i_msg) +
                              sizeof(MCTP::MCTP_MSG_TYPE_PLDM)),
                            (i_len - sizeof(MCTP::MCTP_MSG_TYPE_PLDM)));

          if(errl)
          {
              TRACFBIN(g_trac_mctp,
                       "mctp rx_message: error occurred attempting to process the PLDM message"
                       , i_msg, i_len);
              errl->collectTrace(MCTP_COMP_NAME);
              errlCommit(errl, MCTP_COMP_ID);
          }

          // i_msg buffer is managed by the mctp core logic so we do not need
          // to worry about it
          break;
      }
      default :
      {
          assert(0,
                "Received a MCTP message with a payload type we do not know how to handle");
          break;
      }
   }
}


// Static function used to launch task calling handle_outbound_messages on
// the MctpRP singleton
static void * handle_outbound_messages_task(void*)
{
    TRACFCOMP(g_trac_mctp, "Starting to handle outbound commands");
    Singleton<MctpRP>::instance().handle_outbound_messages();
    return nullptr;
}

// Call libmctp core function mctp_message_tx but wrap it in a mutex lock
static int lock_and_mctp_message_tx(struct mctp *mctp, mctp_eid_t eid,
                                    void *msg, size_t msg_len, mutex_t &mutex)
{
    mutex_lock(&mutex);
    int rc = mctp_message_tx(mctp, eid, msg, msg_len);
    mutex_unlock(&mutex);
    return rc;
}

void MctpRP::handle_outbound_messages(void)
{
    task_detach();

    uint8_t l_rc = 0;

    // Don't start sending messages to the BMC until the channel is active
    // TODO RTC: 249701 determine timeout
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
          case MSG_SEND_PLDM:
          {
              // The first byte of MCTP payload describes the contents
              // of the payload. Set first byte to be TYPE_PLDM (0x01)
              // so BMC knows to route the MCTP message to it's PLDM driver.
              *reinterpret_cast<uint8_t *>(msg->extra_data) =
                                                          MCTP_MSG_TYPE_PLDM;
              TRACDBIN(g_trac_mctp,
                       "pldm message : ",
                       msg->extra_data ,
                       msg->data[0]);
              int rc = lock_and_mctp_message_tx(iv_mctp,
                                                BMC_EID,
                                                msg->extra_data,
                                                msg->data[0],
                                                iv_mctp_mutex);

              if(rc != RC_MCTP_SUCCESS)
              {
                  TRACFCOMP(g_trac_mctp,
                            "MSG_SEND_PLDM failed during mctp_message_tx  rc = 0x%x",
                            rc);
                  // first 8 bytes of MCTP payload
                  const uint64_t mctp_payload =
                          *reinterpret_cast<uint64_t*>(msg->extra_data);
                  /*
                  * @errortype  ERRL_SEV_UNRECOVERABLE
                  * @moduleid   MOD_HANDLE_OUTBOUND
                  * @reasoncode RC_SEND_PLDM_FAIL
                  * @userdata1  Return code returned by MCTP core logic
                  * @userdata2  First 8 bytes of MCTP payload
                  * @devdesc    Software problem while sending pldm message
                  * @custdesc   A software error occured during system boot
                  */
                  errlHndl_t errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                        MOD_HANDLE_OUTBOUND,
                                        RC_SEND_PLDM_FAIL,
                                        rc,
                                        mctp_payload,
                                        ErrlEntry::NO_SW_CALLOUT);
                  errl->collectTrace(MCTP_COMP_NAME);
                  errl->collectTrace(PLDM_COMP_NAME);

                  // Call out service processor / BMC firmware as high priority
                  errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                            HWAS::SRCI_PRIORITY_HIGH);

                  // Call out Hostboot firmware as medium priority
                  errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                            HWAS::SRCI_PRIORITY_MED);

                  // PLDM message msg originator must clean up original buffer
                  // in extra_data
                  msg->extra_data = errl;
                  errl = nullptr;
                  msg->data[1] = rc;
              }

              rc = msg_respond(iv_outboundMsgQ, msg);
              assert(rc == 0,
                     "Failed attempting to respond to MSG_SEND_PLDM message got rc %d",
                     rc);
              break;
          }
          default:
              // just mark a trace and move on with our lives
              TRACFCOMP(g_trac_mctp,
                        "Received am outbound MCTP message with a payload type 0x%.02x we do not know how to handle",
                        msg->type);
              break;
        }

        if(l_rc != 0)
        {
            break;
        }
    }
}


errlHndl_t MctpRP::_mctp_channel_init(void)
{
    errlHndl_t l_errl = nullptr;
do
{
    uint8_t l_status = 0;
    size_t l_size = sizeof(uint8_t);
    // Perform an LPC read on the KCS status register to verify the channel is
    // active and that the BMC has written the negotiated MCTP version
    l_errl = DeviceFW::deviceRead(
                              TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                              &l_status,
                              l_size,
                              DEVICE_LPC_ADDRESS(LPC::TRANS_IO,
                                                 LPC::KCS_STATUS_REG));

    if(l_errl)
    {
        break;
    }

    // Verify that the channel is active
    if(iv_channelActive && !(l_status & KCS_STATUS_CHANNEL_ACTIVE))
    {
        TRACFCOMP(g_trac_mctp,
                  "_mctp_channel_init: Error ! KCS status reports channel as inactive when HB thinks its active!" );
        /*@errorlog
        * @errortype       ERRL_SEV_UNRECOVERABLE
        * @moduleid        MOD_MCTP_CHANNEL_INIT
        * @reasoncode      RC_CHANNEL_INACTIVE
        * @userdata1       kcs status register value
        * @userdata2       mctp version
        *                  (should not have been set but might be useful)
        *
        * @devdesc         Initialization of MCTP protocol between Host and
        *                  BMC failed
        * @custdesc        A problem occurred during the IPL of the system
        *
        */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE, // severity
                               MOD_MCTP_CHANNEL_INIT,   // moduleid
                               RC_CHANNEL_INACTIVE,    // reason code
                               l_status, // KCS status register value
                               iv_hostlpc->lpc_hdr->negotiated_ver, // version
                               ErrlEntry::ADD_SW_CALLOUT);
    }
    else if(!iv_channelActive && (l_status & KCS_STATUS_CHANNEL_ACTIVE))
    {
        iv_channelActive = true;
        // Read the negotiated version from the lpcmap hdr that the bmc should
        // have set prior to setting the KCS_STATUS_CHANNEL_ACTIVE bit
        iv_mctpVersion = iv_hostlpc->lpc_hdr->negotiated_ver;
        TRACFCOMP(g_trac_mctp,
                  "_mctp_channel_init: Negotiated version is : %d",
                  iv_mctpVersion);

        if(iv_hostlpc->lpc_hdr->negotiated_ver >= 2)
        {
            TRACFCOMP(g_trac_mctp,
                  "_mctp_channel_init: Setting packet size to be %ld",
                      iv_hostlpc->lpc_hdr->rx_size );
            iv_hostlpc->binding.pkt_size = iv_hostlpc->lpc_hdr->rx_size;
        }
        printk("MCTP Version : %d    packet size : %d \n",
               iv_hostlpc->lpc_hdr->negotiated_ver,
               iv_hostlpc->binding.pkt_size);

    }

    //else if none of the conditions above are met, the DUMMY_COMMAND is a no op

}while(0);

  return l_errl;
}

void MctpRP::init(errlHndl_t& o_errl)
{
    // This will call the MctpRP construction which initializes MCTP
    // polling loops
    return Singleton<MctpRP>::instance()._init();;
}


void MctpRP::register_mctp_bus(void)
{

    // Register the binding to the LPC bus we are using for this
    // MCTP configuration. NOTE this will trigger the "start" function
    // associated with the iv_hostlpc binding which starts the
    // KCS init handshake with the BMC
    mctp_register_bus(iv_mctp, &iv_hostlpc->binding, HOST_EID);

    // Start the poll kcs status daemon which will read the KCS status reg
    // every 1 ms and if we see that the OBF bit in the KCS status register is
    // set we will read the OBR KCS data reg and send a message to the
    // handle_obf_status daemon
    task_create(poll_kcs_status_task, NULL);
    return;
}

void MctpRP::_init(void)
{
    TRACFCOMP(g_trac_mctp, "MctpRP::_init entry");

    msg_q_register(iv_inboundMsgQ, VFS_ROOT_MSG_MCTP_IN);
    msg_q_register(iv_outboundMsgQ, VFS_ROOT_MSG_MCTP_OUT);

    // Get the virtual address for the LPC bar and add the offsets
    // to the MCTP/PLDM space within  the FW Space of the LPC window.
    auto l_bar = LPC::get_lpc_virtual_bar() +
                        LPC::LPCHC_FW_SPACE +
                        LPC::LPCHC_MCTP_PLDM_BASE;

    // Initialize the host-lpc binding for hostboot
    iv_hostlpc = mctp_hostlpc_init_hostboot(l_bar);

    // Start cmd daemon first because we want it ready if poll daemon finds
    // something right away
    task_create(handle_outbound_messages_task, NULL);

    // Set the receive function to be rx_message which
    // will handle the message in the RX space accordingly
    mctp_set_rx_all(iv_mctp, rx_message, NULL);

    TRACFCOMP(g_trac_mctp, "MctpRP::_init exit");
    return;
}

// Emtpy constructor will create the message queue and initialize the mctp core
MctpRP::MctpRP(void):
    iv_hostlpc(nullptr),
    iv_mctp(mctp_init()),
    iv_inboundMsgQ(msg_q_create()),
    iv_outboundMsgQ(msg_q_create()),
    iv_channelActive(false),
    iv_mctp_mutex(MUTEX_INITIALIZER)
{
}

// Set the function that will be called when mctp.so is loaded
TASK_ENTRY_MACRO( MctpRP::init );
