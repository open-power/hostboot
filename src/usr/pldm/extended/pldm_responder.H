/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/pldm_responder.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
 * @file pldm_responder.H
 *
 * @brief Declares the pldmResponder singleton class which handles and responds to
 *        pldm requests from the BMC
 */

#ifndef PLDMRESPONDER_H
#define PLDMRESPONDER_H

#include <sys/msg.h>
#include <errl/errlentry.H>
#include <pldm/pldmif.H>
#include <mctp/mctp_message_types.H>

struct pldm_msg;

namespace PLDM
{

class pldmResponder
{
  public:
     /**
     * Function that polls endlessly on a message Q that gets initialized
     * in pldm_msg_queues.C in the pldm_base module. When a message is found
     * it is handled accordingly.
     * Specifically this will handle PLDM requests originating from the BMC,
     * which is getting routed through Hostboot's MCTP stack and finally will
     * get passed to this polling loop.
     *
     * @return void
     */
      void handle_inbound_req_messages(void);

     /**
     * Resolves MCTP outbound message queue and launches task to handle
     * inbound PLDM requests
     *
     * @return void
     */
      void init(void);

      // Constructor
      pldmResponder(void);

  private:

      //Private Member Variables
      MCTP::mctp_outbound_msgq_t iv_mctpOutboundMsgQ; // mctp outbound rsp/req msgQ

      // Disallow copying this class.
      pldmResponder& operator=(const pldmResponder&);
      pldmResponder(const pldmResponder&);
};

/* @brief The type of incoming PLDM request handler functions.
 */
using pldm_msg_responder_t = errlHndl_t(*)(MCTP::mctp_outbound_msgq_t, const pldm_mctp_message&);

}

#endif /* PLDMRESPONDER_H */
