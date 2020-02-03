/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/mctprp.H $                                       */
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
#ifndef MCTPRP_H
#define MCTPRP_H

#include <sys/msg.h>
#include <errl/errlentry.H>
#include "libmctp-lpc.h"

namespace MCTP
{
    // Valid message types that are accepted
    // by the mctp inbound msg q
    enum inbound_msgq_msg_t
    {
        MSG_INIT        = 0x00,
        MSG_TX_BEGIN    = 0x01,
        MSG_RX_COMPLETE = 0x02,
        MSG_DUMMY       = 0xFF
    };

    // Valid message types that are accepted
    // by the mctp outbound msg q
    enum outbound_msgq_msg_t
    {
        MSG_SEND_PLDM        = 0x00
    };
}

class MctpRP
{
  public:

     /**
     * Function that polls endlessly on the KCS status register
     * and if it finds that the OBF bit is set in the KCS status register
     * then sends a message to the kcs_cmd handler.
     *
     * @return void
     */
      void poll_kcs_status(void);
     /**
     * Function that polls endlessly on a message Q that gets initialized
     * in the MctpRP ctor. When a message is found in the ODR it is read and
     *  handled by this queue.
     *
     *
     * @return void
     */
      void handle_inbound_messages(void);

     /**
     * Function that polls endlessly on a message Q that gets initialized
     * in the MctpRP ctor. Other userspace tasks can issue requests to this
     * queue if they wish to send messages across MCTP to the BMC.
     *
     * @return void
     */
      void handle_outbound_messages(void);

      /**
      * Function that is called when libmctp.so is loaded by the initsvc. It will
      * create the mctp core struct and the hostlpc binding and initialize the
      * bus registered to the MCTP binding so we are ready to start sending traffic
      *
      * @param[out] o_errl required by TASK_ENTRY_MACRO as a way to commit an error log
      *                    if the task entry function fails
      * @return void
      */
      static void init(errlHndl_t& o_errl);

      // Constructor
      MctpRP(void);
  private:
      // See public "init" function above
      errlHndl_t _init(void);
      /**
      * When we receive the "DUMMY" KCS command in the ODR we know
      * that the bmc has written the negotiated status and activated the channel
      * This is the function that is called when we receive that DUMMY message
      *
      * @return uint8_t return 0 on success and !0 if there is a fail
      */
      uint8_t _mctp_process_version(void);

      struct mctp_binding_hostlpc *iv_hostlpc; //!< ptr to hostlpc binding struct
      struct mctp *iv_mctp;    //!< ptr to struct that has business logic
      msg_q_t     iv_inboundMsgQ;     // mctp inbound messages
      msg_q_t     iv_outboundMsgQ;    // mctp outbound messages
      bool        iv_channelActive;   // MCTP channel ready for traffic

      // Disallow copying this class.
      MctpRP& operator=(const MctpRP&);
      MctpRP(const MctpRP&);
};

#endif //MCTP_H
