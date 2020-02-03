/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/pldmrp.H $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

typedef uint8_t mctp_eid_t;

namespace PLDM
{
    enum msgq_msg_t
    {
        MSG_CONTROL_DISCOVERY = 0x00,
        MSG_SMBIOS            = 0x01,
        MSG_MONITOR_CONTROL   = 0x02,
        MSG_BIOS_CONTROL      = 0x03,
        MSG_OEM               = 0x3F
    };

    const uint8_t MCTP_OFFSET = 1;
}

typedef enum pldm_requester_error_codes {
  PLDM_REQUESTER_SUCCESS = 0,
  PLDM_REQUESTER_OPEN_FAIL = -1,
  PLDM_REQUESTER_NOT_PLDM_MSG = -2,
  PLDM_REQUESTER_NOT_RESP_MSG = -3,
  PLDM_REQUESTER_NOT_REQ_MSG = -4,
  PLDM_REQUESTER_RESP_MSG_TOO_SMALL = -5,
  PLDM_REQUESTER_INSTANCE_ID_MISMATCH = -6,
  PLDM_REQUESTER_SEND_FAIL = -7,
  PLDM_REQUESTER_RECV_FAIL = -8,
  PLDM_REQUESTER_INVALID_RECV_LEN = -9,
} pldm_requester_rc_t;

class PldmRP
{
  public:
     /**
     * Function that is called when libpldm.so is loaded by the initsvc. It will
     * create the message queues responsible for routing PLDM inbound and output
     * traffic
     *
     * @param[out] o_errl required by TASK_ENTRY_MACRO as a way to commit an error log
     *                    if the task entry function fails
     * @return void
     */
      static void init(errlHndl_t& o_errl);
     /**
     * Function that polls endlessly on a message Q that gets initialized
     * in the pldmRP ctor. When a message is found it is handled accordingly.
     *
     * @return void
     */
      void handle_inbound_messages(void);
      // Constructor
      PldmRP(void);
  private:
      // See public "init" function above
      errlHndl_t _init(void);
      msg_q_t     iv_inboundMsgQ;      // pldm inbound msgQ
      msg_q_t     iv_mctpOutboundMsgQ; // msgQ to send outbound traffic on

      // Disallow copying this class.
      PldmRP& operator=(const PldmRP&);
      PldmRP(const PldmRP&);
};

#endif /* PLDMRP_H */
