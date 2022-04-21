/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/runtime/pldmrp_rt.H $                            */
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
#ifndef PLDMRP_RT_H
#define PLDMRP_RT_H

/** @file  pldmrp_rt.H
 *  @brief Header for hbrt's PLDM resource provider.
 */

#include <vector>
#include <pldm/pldm_const.H>
#include <pldm/pldmif.H>

class PldmRP
{
  public:
      /** @brief cache_next_pldm_msg interface to attempt to cache the next pldm
       *         request or response
       *
       * @param[in] i_next_msg  Buffer containing the next PLDM message found
       *                        by MCTP that we want to attempt to store in the
       *                        PLDM resource provider for later
       *
       * @return int HBRT PLDM resource provider return codes (see pldmrp_rt.H)
       */
      PLDM::pldmrp_rt_rc cache_next_pldm_msg(PLDM::pldm_mctp_message i_next_msg);

      /**
       * @brief Retreive the next incoming PLDM request and clear the cached copy.
       *
       * @return  The next incoming PLDM request.
       */
      PLDM::pldm_mctp_message get_and_clear_next_request();

      /**
       * @brief Retreive the next incoming PLDM response and clear the cached copy.
       *
       * @return  The next PLDM request.
       */
      PLDM::pldm_mctp_message get_and_clear_next_response();

      // these members will act as a cache for a single PLDM response or PLDM
      // request. there should only be at most one of each cached at any given
      // time
      PLDM::pldm_mctp_message iv_next_response;
      PLDM::pldm_mctp_message iv_next_request;

      // Whether PLDM is in the response loop or not
      bool iv_waitingForResponse;

      // Constructor
      PldmRP()
          : iv_next_response(false, 0, { }),
            iv_next_request(false, 0, { }),
            iv_waitingForResponse(false)
      { }

  private:
      // Disallow copying this class.
      PldmRP& operator=(const PldmRP&) = delete;
};

#endif //PLDMRP_RT_H
