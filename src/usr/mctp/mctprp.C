/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/mctprp.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
#include "mctp_trace.H"
#include <libmctp-astlpc.h>
#include <hostboot_mctp.H>
// System Headers
#include <assert.h>
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

errlHndl_t read_kcs_status(uint8_t & o_status)
{
    size_t size = sizeof(o_status);
    return DeviceFW::deviceRead(
                        TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                        &o_status,
                        size,
                        DEVICE_LPC_ADDRESS(LPC::TRANS_IO,
                                           LPC::KCS_STATUS_REG));
}

errlHndl_t read_kcs_data(uint8_t & o_data)
{
    size_t size = sizeof(o_data);
    return DeviceFW::deviceRead(
                        TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                        &o_data,
                        size,
                        DEVICE_LPC_ADDRESS(LPC::TRANS_IO,
                                            LPC::KCS_DATA_REG));
}

errlHndl_t drain_odr(void)
{
    uint8_t kcs_status = 0, kcs_data = 0;
    const uint8_t DRAIN_LIMIT = 255;
    uint8_t drain_counter = DRAIN_LIMIT;
    errlHndl_t errl = nullptr;
    errl = read_kcs_status(kcs_status);

    while((!errl) && --drain_counter && (kcs_status & KCS_STATUS_OBF))
    {
        errl = read_kcs_data(kcs_data);
        if(errl)
        {
            break;
        }
        // Give the other MCTP EID a 50 msec to react
        nanosleep(0, 50 * NS_PER_MSEC);
        errl = read_kcs_status(kcs_status);
    }

    if(!errl && !drain_counter)
    {
        TRACFCOMP(g_trac_mctp,
                  "More messages found in ODR than we ever expected to find.");
        /*@
        * @errortype
        * @severity   ERRL_SEV_PREDICTIVE
        * @moduleid   MOD_DRAIN_ODR
        * @reasoncode RC_DRAINED_MAX_ODR_MSGS
        * @userdata1  Number of KCS messages we drain from ODR before
        *             creating this error log.
        * @userdata2  Unused
        * @devdesc    BMC is likely DOSing the Host with PLDM messages
        *             intended for PHYP or HBRT.
        * @custdesc   A software error occured during system boot
        */
        errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                             MOD_DRAIN_ODR,
                             RC_DRAINED_MAX_ODR_MSGS,
                             DRAIN_LIMIT,
                             0,
                             ErrlEntry::NO_SW_CALLOUT);
        errl->collectTrace(MCTP_COMP_NAME);
        errl->collectTrace(PLDM_COMP_NAME);

        // Call out service processor / BMC firmware as high priority
        errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                  HWAS::SRCI_PRIORITY_HIGH);

        // Call out Hostboot firmware as medium priority
        errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                  HWAS::SRCI_PRIORITY_MED);
    }

    return errl;
}

void MctpRP::poll_kcs_status(void)
{
    task_detach();
    while(1)
    {
        mutex_lock(&iv_mutex);
        auto rc = mctp_astlpc_poll(iv_astlpc);
        mutex_unlock(&iv_mutex);
        if(rc)
        {
            printk("BMC stopped responding for LPC requests! RC from mctp_astlpc_poll = %d \n", rc);
            crit_assert(0);
        }
        nanosleep(0, 1 * NS_PER_MSEC);
    }
}

#ifdef CONFIG_MCTP
// Static function used to launch task calling poll_kcs_status on
// the MctpRP singleton
static void * poll_kcs_status_task(void*)
{
    TRACFCOMP(g_trac_mctp, "Starting to poll status register");
    Singleton<MctpRP>::instance().poll_kcs_status();
    return nullptr;
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
#endif

// Static function used to launch task calling handle_outbound_messages on
// the MctpRP singleton
static void * handle_outbound_messages_task(void*)
{
    TRACFCOMP(g_trac_mctp, "Starting to handle outbound commands");
    Singleton<MctpRP>::instance().handle_outbound_messages();
    return nullptr;
}

void MctpRP::handle_outbound_messages(void)
{
    task_detach();

/* If libmctp is not compiled then the channel will never activate.
   Move on so we can respond to iv_outboundMsgQ message to do pldm
   unit test cases. */
#ifdef CONFIG_MCTP
    size_t counter = 0;
    // Don't start sending messages to the BMC until the channel is active
    while(!iv_channelActive)
    {
        counter++;
        if(counter >= 1000)
        {
            // Either host or bmc is failing in its responsibilty to init the channel.
            // If this happens check bmc's journal to see if the mctp daemon crashed.
            printk("Failed to initialize MCTP channel with BMC in under 10 seconds,"
                   " triggering a critical assert as normal shutdown path is impossible without PLDM");
            crit_assert(0);
        }
        nanosleep(0, NS_PER_MSEC * 10);
    }
#endif

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
              TRACDBIN(g_trac_mctp, "pldm message : ",
                       msg->extra_data , msg->data[0]);
              int rc = 0;
#ifdef CONFIG_MCTP
              mutex_lock(&iv_mutex);
              rc = mctp_message_tx(iv_mctp, BMC_EID,
                                   msg->extra_data, msg->data[0]);
              mutex_unlock(&iv_mutex);

              if(rc)
              {
                  TRACFCOMP(g_trac_mctp,
                            "MSG_SEND_PLDM failed during mctp_message_tx rc = 0x%x."
                            " This likely means hostboot tried to send a message at"
                            " the wrong time.",
                            rc);
                  // first 8 bytes of MCTP payload
                  const uint64_t mctp_payload =
                          *reinterpret_cast<uint64_t*>(msg->extra_data);
                  /*@
                  * @errortype
                  * @severity   ERRL_SEV_UNRECOVERABLE
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

                  // Call out service processor / BMC firmware as medium priority
                  errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                            HWAS::SRCI_PRIORITY_MED);

                  // Call out Hostboot firmware as high priority
                  errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                            HWAS::SRCI_PRIORITY_HIGH);

                  // PLDM message msg originator must clean up original buffer
                  // in extra_data
                  msg->extra_data = errl;
                  errl = nullptr;
                  msg->data[1] = rc;
              }
#endif
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
    }
}

void MctpRP::init(errlHndl_t& o_errl)
{
    mctp_set_alloc_ops(malloc, free, realloc);
    return Singleton<MctpRP>::instance()._init();;
}


void MctpRP::register_mctp_bus(void)
{
#ifdef CONFIG_MCTP
    // Read and discard any potentially stale messages in the ODR
    auto errl = drain_odr();
    if(errl)
    {
        // Commit any errors from trying to drain the ODR queue then
        // attempt to continue.
        errlCommit(errl, MCTP_COMP_ID);
    }

    mutex_lock(&iv_mutex);
    // Register the binding to the LPC bus we are using for this
    // MCTP configuration. NOTE this will trigger the "start" function
    // associated with the iv_astlpc binding which starts the
    // KCS init handshake with the BMC
    mctp_register_bus(iv_mctp, mctp_binding_astlpc_core(iv_astlpc), HOST_EID);
    mutex_unlock(&iv_mutex);

    iv_channelActive = true;

    // Start the poll kcs status daemon which will read the KCS status reg
    // every 1 ms and if we see that the OBF bit in the KCS status register is
    // set we will read the ODR KCS data reg and act on it
    task_create(poll_kcs_status_task, nullptr);
#endif
    return;
}

// List external IO function we get from hostboot_mctp
extern int __mctp_hostlpc_hostboot_kcs_read(void *arg,
                                            enum mctp_binding_astlpc_kcs_reg reg,
                                            uint8_t *val);

extern int __mctp_hostlpc_hostboot_kcs_write(void *arg,
                                             enum mctp_binding_astlpc_kcs_reg reg,
                                             uint8_t val);

extern int __mctp_hostlpc_hostboot_lpc_read(void *arg, void * buf,
                                            long offset, size_t len);

extern int __mctp_hostlpc_hostboot_lpc_write(void *arg, const void * buf,
                                             long offset, size_t len);

static const struct mctp_binding_astlpc_ops astlpc_hostboot_ops = {
    .kcs_read = __mctp_hostlpc_hostboot_kcs_read,
    .kcs_write = __mctp_hostlpc_hostboot_kcs_write,
    .lpc_read = __mctp_hostlpc_hostboot_lpc_read,
    .lpc_write = __mctp_hostlpc_hostboot_lpc_write,
};

void MctpRP::_init(void)
{
    TRACFCOMP(g_trac_mctp, "MctpRP::_init entry");

#ifdef CONFIG_MCTP
    // Setup the trace hook to point at mctp_log_fn
    mctp_set_log_custom(mctp_log_fn);

    // Set the max message size to be large enough to account for
    // the maximum PLDM transfer size we expect
    mctp_set_max_message_size(iv_mctp, HOST_MAX_INCOMING_MESSAGE_ALLOCATION);

    // Set the receive function to be rx_message which
    // will handle the message in the RX space accordingly
    mctp_set_rx_all(iv_mctp, rx_message, nullptr);

    // Get the virtual address for the LPC bar and add the offsets
    // to the MCTP/PLDM space within  the FW Space of the LPC window.
    const auto mctp_bar = reinterpret_cast<void *>(
                        LPC::get_lpc_virtual_bar() +
                        LPC::LPCHC_FW_SPACE +
                        LPC::LPCHC_MCTP_PLDM_BASE);

    const uint32_t desired_mtu = 32768;
    // Initialize the host-lpc binding for hostboot
    iv_astlpc = mctp_astlpc_init(MCTP_BINDING_ASTLPC_MODE_HOST, desired_mtu,
                                 mctp_bar, &astlpc_hostboot_ops, nullptr);
#endif
    msg_q_register(iv_outboundMsgQ, VFS_ROOT_MSG_MCTP_OUT);
    task_create(handle_outbound_messages_task, nullptr);

    TRACFCOMP(g_trac_mctp, "MctpRP::_init exit");
    return;
}

// Emtpy constructor will create the message queue and initialize the mctp core
MctpRP::MctpRP(void):
    iv_astlpc(nullptr),
    iv_mctp(mctp_init()),
    iv_outboundMsgQ(msg_q_create()),
    iv_channelActive(false),
    iv_mutex(MUTEX_INITIALIZER)
{
}

// Set the function that will be called when mctp.so is loaded
TASK_ENTRY_MACRO( MctpRP::init );
