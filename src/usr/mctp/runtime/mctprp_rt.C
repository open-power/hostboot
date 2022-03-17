/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/runtime/mctprp_rt.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
 *  @file  mctprp_rt.C
 *  @brief Source code for hbrt's MCTP resource provider. Its primary job is to
 *         provide interaces for MCTP users to send messages across the bus and
 *         to attempt to look for new messages. The resource provider will initalize
 *         the mctp binding to the virtual bus provided by the hypervisor. Also it
 *         will provide an interface to the hbrtvirt mctp binding to route completed
 *         mctp messages to the appropriate message handler (see MctpRP::rx_message)
 */

// Headers from local directory
#include "mctprp_rt.H"
#include "../mctp_trace.H"
#include "libmctp-hbrtvirt.h"
// System Headers
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
// Userspace Headers
#include <trace/interface.H>
#include <runtime/interface.h>
#include <errl/errlmanager.H>
#include <mctp/mctp_errl.H>
#include <mctp/mctp_reasoncodes.H>
#include <pldm/pldmif.H>

using namespace ERRORLOG;
using namespace MCTP;

trace_desc_t* g_trac_mctp = nullptr;
TRAC_INIT(&g_trac_mctp, MCTP_COMP_NAME, 4*KILOBYTE, TRACE::BUFFER_SLOW);

namespace MCTP
{
    int get_next_packet(void)
    {
        return Singleton<MctpRP>::instance().get_next_packet();
    }

    int send_message(const byte_vector_t& i_mctp_payload)
    {
        return Singleton<MctpRP>::instance().send_message(i_mctp_payload);
    }
}

int MctpRP::get_next_packet(void)
{
    TRACDCOMP(g_trac_mctp,
             "requesting next mctp packet");
    return mctp_hbrtvirt_rx_start(iv_hbrtvirt);
}

int MctpRP::send_message(const byte_vector_t& i_mctp_payload)
{
    TRACDBIN(g_trac_mctp,
             "sending mctp payload: ",
             i_mctp_payload.data(),
             i_mctp_payload.size());

    int rc = mctp_message_tx(iv_mctp,
                             BMC_EID,
                             // TODO https://github.com/openbmc/libmctp/issues/4
                             // remove const_cast
                             const_cast<uint8_t*>(i_mctp_payload.data()),
                             i_mctp_payload.size());

    return rc;
}

static void rx_message(uint8_t i_eid, void * i_data,
                       void * i_msg, size_t i_len)
{
   TRACDBIN(g_trac_mctp, "mctp rx_message:", i_msg, i_len);

   auto msg_bytes = static_cast<const uint8_t *const>(i_msg);

   // First byte of the msg should be the MCTP payload type.
   // For now we only support PLDM over MCTP
   switch(*msg_bytes)
   {
      case MCTP_MSG_TYPE_PLDM :
      {
          // Skip first byte of the MCTP payload which has the payload type.
          // The PLDM layer is unaware of this byte.
          PLDM::pldmrp_rt_rc rc =
              PLDM::cache_next_pldm_msg(msg_bytes + sizeof(MCTP::message_type),
                                        i_len - sizeof(MCTP::message_type));
          if(rc)
          {
              uint64_t request_hdr_data = 0;
              if(rc != PLDM::RC_INVALID_MESSAGE_LEN)
              {
                   request_hdr_data =
                      PLDM::pldmHdrToUint64(
                        *reinterpret_cast<const pldm_msg*>(msg_bytes + sizeof(MCTP::message_type)));
              }
              TRACFBIN(g_trac_mctp, "Failed to cache mctp payload:", i_msg, i_len);
              /*@
              * @errortype  ERRL_SEV_PREDICTIVE
              * @moduleid   MOD_RX_CALLBACK
              * @reasoncode RC_ERROR_CACHING_MSG
              * @userdata1[0:31]  HBRT PLDM RP Return Code
              * @userdata1[32:63] Source MCTP Endpoint ID
              * @userdata2        Header of PLDM message
              * @devdesc    Unable to process PLDM message from the BMC
              * @custdesc   A software error occurred during host/bmc
              *             communication
              */
              errlHndl_t errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                              MOD_RX_CALLBACK,
                                              RC_ERROR_CACHING_MSG,
                                              TWO_UINT32_TO_UINT64(
                                                TO_UINT32(rc),
                                                TO_UINT32(i_eid)),
                                              request_hdr_data,
                                              ErrlEntry::NO_SW_CALLOUT);
              addBmcAndHypErrorCallouts(errl);
              errlCommit(errl, MCTP_COMP_ID);
          }
          break;
      }
      default :
      {
          TRACFCOMP(g_trac_mctp,
                    "Warning! Received a MCTP message with a payload type %u from eid %u we do not know how to handle, it will be ignored",
                    *msg_bytes,
                    i_eid);
          TRACFBIN(g_trac_mctp, "failing mctp rx_message:", i_msg, i_len);
         /*@
          * @errortype  ERRL_SEV_PREDICTIVE
          * @moduleid   MOD_RX_CALLBACK
          * @reasoncode RC_INVALID_MSG_TYPE
          * @userdata1  MCTP Message Type (first byte of MCTP payload)
          * @userdata2  Source MCTP Endpoint ID
          * @devdesc    MCTP message of unknown type received
          * @custdesc   A software error occurred during host/bmc
          *             communication
          */
          errlHndl_t errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                          MOD_RX_CALLBACK,
                                          RC_INVALID_MSG_TYPE,
                                          *msg_bytes,
                                          i_eid,
                                          ErrlEntry::NO_SW_CALLOUT);
          addBmcAndHypErrorCallouts(errl);
          errlCommit(errl, MCTP_COMP_ID);
          break;
      }
   }
}

/**
* @brief Initialize mctp binding for hbrt and provide clear
*        interfaces for sending and receiving mctp messages.
*
* @return void
*/
void init_mctp_resource_provider(void)
{
    mctp_set_alloc_ops(malloc, free, realloc);
    Singleton<MctpRP>::instance();
}

MctpRP::MctpRP(void):
    iv_mctp(mctp_init()),
    iv_hbrtvirt(mctp_hbrtvirt_init_hbrt())
{
    TRACFCOMP(g_trac_mctp, "MctpRP constructor entry");

    mctp_set_max_message_size(iv_mctp, HOST_MAX_INCOMING_MESSAGE_ALLOCATION);

    // Set the receive function to be rx_message which
    // will handle the message in the RX space accordingly
    mctp_set_rx_all(iv_mctp, rx_message, NULL);

    mctp_register_bus(iv_mctp, &iv_hbrtvirt->binding, HBRT_EID);

    mctp_binding_set_tx_enabled(&iv_hbrtvirt->binding, true);

    mctp_set_log_custom(mctp_log_fn);

    TRACFCOMP(g_trac_mctp, "MctpRP constructor exit");
}

MctpRP::~MctpRP(void)
{
    TRACFCOMP(g_trac_mctp, "MctpRP destructor entry");
    mctp_hbrtvirt_destroy(iv_hbrtvirt);
    mctp_destroy(iv_mctp);
    TRACFCOMP(g_trac_mctp, "MctpRP destructor exit");

}

// Force the init function to execute when the module loads.
//   We want to do this here rather than waiting for a
//   post-init call in rt_main because we need this support
//   in order to initialize some of the other modules that
//   get loaded later.
struct initMctp
{
    initMctp()
    {
        init_mctp_resource_provider();
    }
};

initMctp g_initMctp;
