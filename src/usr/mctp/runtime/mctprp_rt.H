/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/runtime/mctprp_rt.H $                            */
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
#ifndef MCTPRP_RT_H
#define MCTPRP_RT_H

/**
 *  @file  mctprp_rt.H
 *  @brief Header for hbrt's MCTP resource provider.
 */

// System Headers
#include <sys/msg.h>
// Userspace Headers
#include <errl/errlentry.H>
#include <mctp/mctp_const.H>

class MctpRP
{
  public:
      friend class Singleton<MctpRP>;
      /**
      * @brief Send a MCTP payload using the mctp binding
      * @param[in] i_mctp_payload vector of bytes that contains mctp
      *                           payload that needs to be sent.
      *                           See DSP0236 v1.0.0 Figure 4
      *
      * @return int               Return Code which will either be from
      *                           interface.h or from libmctp_rc.h
      *                           (there should be no overlap)
      */
      int send_message(const MCTP::byte_vector_t& i_mctp_payload);

      /**
      * @brief Perform MCTP_RECEIVE fw_request to get the next MCTP packet
      *        if the hypervisor has one for HBRT
      *
      * @return int               Return Code which will either be from
      *                           interface.h or from libmctp_rc.h
      *                           (there should be no overlap)
      */
      int get_next_packet(void);

      //Destructor
      ~MctpRP(void);
  private:
      // Private Member Variables
      struct mctp *iv_mctp;                    // ptr to struct that has business logic
      struct mctp_binding_hbrtvirt *iv_hbrtvirt; // ptr to hostlpc binding struct

      // Constructor
      MctpRP(void);

      // Disallow copying this class.
      MctpRP& operator=(const MctpRP&) = delete;
};

#endif //MCTPRP_RT_H
