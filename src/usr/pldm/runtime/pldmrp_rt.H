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
class PldmRP
{
  public:
      /** @brief cache_next_pldm_msg interface to attempt to cache the next pldm
       *         request or response
       *
       * @param[in] i_next_msg  Buffer containing the next PLDM message found
       *                        by MCTP that we want to attempt to store in the
       *                        PLDM resource provider for later
       * @param[in] i_len       Length of i_next_msg buffer
       *
       * @return int HBRT PLDM resource provider return codes (see pldmrp_rt.H)
       */
      PLDM::pldmrp_rt_rc cache_next_pldm_msg(const uint8_t * i_next_msg,
                                       size_t i_len);

      /**
       *  @brief Clears the input vector and swaps the contents of the cached
       *      request with it.  This has the effect of transferring the request
       *      to the given vector in O(1) complexity without having to
       *      allocate memory, and it clears out the cached request.
       *
       *  @param[io/out] io_request On input, a vector to receive the cached
       *                                request.
       *                            On output, a vector containing the request
       */
      void get_and_clear_next_request(std::vector<uint8_t>& io_request);

      // these vector members will act as a cache for a single PLDM response or
      // PLDM request. there should only be at most one of each cached at any
      // given time
      std::vector<uint8_t> iv_next_response;
      std::vector<uint8_t> iv_next_request;

      // Whether PLDM is in the response loop or not
      bool iv_waitingForResponse;

      // Constructor
      PldmRP(void) : iv_waitingForResponse(false) {};
  private:
      // Disallow copying this class.
      PldmRP& operator=(const PldmRP&) = delete;
};

#endif //PLDMRP_RT_H
