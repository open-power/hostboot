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

// System Headers
#include <sys/msg.h>
#include <sys/sync.h>
// Userspace Headers
#include <errl/errlentry.H>
#include <mctp/mctp_const.H>

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

      /**
      * Register the LPC bus with the hostlpc binding. This will trigger the
      * handshake between the host and the bmc over the KCS interface after
      * which MCTP traffic will start flowing.
      *
      * @return void
      */
      void register_mctp_bus(void);

      // Constructor
      MctpRP(void);
  private:

      // Private Member Functions
      void _init(void);       // See public "init" function above
      /**
      * When we receive the "DUMMY" KCS command in the ODR we know
      * that the bmc has written the negotiated status and activated the channel
      * This is the function that is called when we receive that DUMMY message
      *
      * @return errlHndl_t return 0 on success and an error log if there is a fail
      */
      errlHndl_t _mctp_channel_init(void);

      // Private Member Variables
      struct mctp_binding_hostlpc *iv_hostlpc; // ptr to hostlpc binding struct
      struct mctp *iv_mctp;                    // ptr to struct that has business logic
      msg_q_t     iv_inboundMsgQ;              // MCTP inbound messages
      msg_q_t     iv_outboundMsgQ;             // MCTP outbound messages
      volatile bool iv_channelActive;          // MCTP channel ready for traffic
      uint16_t    iv_mctpVersion;              // MCTP version negotiated during initialization
      mutex_t     iv_mctp_mutex;               // Mutex to protect tx_queue accesses

      // Disallow copying this class.
      MctpRP& operator=(const MctpRP&);
      MctpRP(const MctpRP&);
};

#endif //MCTP_H
