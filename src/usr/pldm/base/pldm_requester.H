/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_requester.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
 * @file pldm_requester.H
 *
 * @brief Declares the pldmRequester singleton class which manages pldm requests
 *        from other userspace modules in hostboot.
 */

#ifndef PLDMREQUESTER_H
#define PLDMREQUESTER_H

#include <sys/msg.h>
class pldmRequester
{
  public:
     /**
     * Function that polls endlessly on a message Q that gets initialized
     * in pldm_msg_queues.C in the pldm_base module. When a message is found
     * it is handled accordingly.
     * Specifically this will handle PLDM requests from other user-space tasks
     * running on the host, send the requests to the MCTP transport, and
     * wait for a response.
     *
     * @return void
     */
      void handle_outbound_req_messages(void);

     /**
     * Resolves outbound MCTP message queue and launches a task to handle
     * outbound PLDM requests
     *
     * @return void
     */
      void init(void);

      // Constructor
      pldmRequester(void);

  private:

      //Private Member Variables
      msg_q_t iv_mctpOutboundMsgQ; // mctp outbound rsp/req msgQ

      // Disallow copying this class.
      pldmRequester& operator=(const pldmRequester&);
      pldmRequester(const pldmRequester&);
};

#endif /* PLDMREQUESTER_H */
