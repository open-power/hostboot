/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/pldmrp.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef PLDMRP_H
#define PLDMRP_H

#include <sys/msg.h>
#include <errl/errlentry.H>
#include <pldm/pldm_const.H>

class PldmRP
{
  public:
     /**
     * Function that is called when libpldm.so is loaded by the initsvc. It will
     * create the message queues responsible for routing PLDM inbound and output
     * traffic
     *
     * @param[out] o_errl required by TASK_ENTRY_MACRO as a way to commit an error log
     *                    if the task entry function fails (unused)
     * @return void
     */
      static void init(errlHndl_t& o_errl);
     /**
     * Function that polls endlessly on a message Q that gets initialized
     * in the pldmRP ctor. When a message is found it is handled accordingly.
     * Specifically this will handle PLDM requests from other user-space tasks
     * running on the host, send the requests to the MCTP transport, and
     * wait for a response.
     *
     * @return void
     */
      void handle_outbound_req_messages(void);
     /**
     * Function that polls endlessly on a message Q that gets initialized
     * in the pldmRP ctor. When a message is found it is handled accordingly.
     * Specifically this will handle PLDM requests originating from the BMC,
     * which is getting routed through Hostboot's MCTP stack and finally will
     * get passed to this polling loop.
     *
     * @return void
     */
      void handle_inbound_req_messages(void);

      /**
      * Return a ptr to the message queue PLDM RP is waiting on for
      * for inbound PLDM requests from the BMC
      */
      msg_q_t getInboundReqMsgQ(void)
      {
          return this->iv_inboundReqMsgQ;
      }

      /**
      * Return a ptr to the message queue PLDM RP is waiting on for
      * for inbound PLDM response from the BMC
      */
      msg_q_t getInboundRspMsgQ(void)
      {
          return this->iv_inboundRspMsgQ;
      }

      // Constructor
      PldmRP(void);

  private:
      //Private Member Functions
      void _init(void);             // See public "init" function above
      //Private Member Variables
      msg_q_t     iv_inboundReqMsgQ;      // pldm inbound request msgQ
      msg_q_t     iv_outboundReqMsgQ;     // pldm outbound request msgQ
      msg_q_t     iv_inboundRspMsgQ;      // pldm inbound response msgQ
      msg_q_t     iv_mctpOutboundMsgQ;    // mctp outbound rsp/req msgQ

      // Disallow copying this class.
      PldmRP& operator=(const PldmRP&);
      PldmRP(const PldmRP&);
};

#endif /* PLDMRP_H */
