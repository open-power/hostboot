/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/pldmif.H $                               */
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
#ifndef PLDMIF_H
#define PLDMIF_H

/**
 * @file pldmif.H
 *
 * @brief PLDM's Interface for external userspace modules to call
 *
 */

#include <cstddef>
#include <openbmc/pldm/libpldm/base.h>
#include <errl/errlentry.H>
#include <pldm/pldm_const.H>

namespace PLDM
{
#ifndef __HOSTBOOT_RUNTIME
    /**
    * @brief This function is intended to be used by the MCTP resource
    *        provider when they find a PLDM message and want the PLDM
    *        resource provider to handle it
    *
    * @param[in] i_msg  A ptr to PLDM message, no change of memory ownership.
    *                   Note that this func will assert is i_msg is nullptr.
    * @param[in] i_len  Length of buffer containing PLDM message,
                        i_len must be >= sizeof(pldm_msg_hdr).
    *
    * @return errHndl_t   nullptr unless error occurs
    */
    errlHndl_t routeInboundMsg(const uint8_t * i_msg, size_t i_len);
#else
    /**
    * @brief This function is intended to be used by the MCTP resource
    *        provider when it finds a PLDM message and wants the PLDM
    *        resource provider to handle it
    *
    * @param[in] i_next_msg  Buffer containing the next PLDM message found by
    *                        MCTP that we want to attempt to cache at PLDM layer
    * @param[in] i_len       Length of i_next_msg buffer
    *
    * @return pldmrp_rt_rc HBRT PLDM resource provider return code (see pldmrp_rt.H)
    */
    pldmrp_rt_rc cache_next_pldm_msg(const void * i_next_msg,
                                     size_t i_len);

    /**
    * @brief This function will return the PLDM response, if there is one,
    *        that HBRT's PLDM resource provider has cached.
    *
    * @return std::vector<uint8_t> Vector containing the next cached PLDM
    *                              response if there is one
    */
    const std::vector<uint8_t> & get_next_response(void);

    /**
    * @brief Clear the byte vector containing the cached pldm response in the PLDM
    *        resource provider
    *
    * @return void
    */
    void clear_next_response(void);

    /**
    * @brief This function will return the PLDM request, if there is one,
    *        that HBRT's PLDM resource provider has cached.
    *
    * @return std::vector<uint8_t> Vector containing the next cached PLDM
    *                              request if there is one
    */
    const std::vector<uint8_t> & get_next_request(void);

    /**
    * @brief Clear the byte vector containing the cached pldm request in the PLDM
    *        resource provider
    *
    * @return void
    */
    void clear_next_request(void);

    /**
    * @brief Process the next PLDM request cached by HBRT's PLDM resource
    *        provider.
    *
    * @return errHndl_t   nullptr unless error occurs
    */
    errlHndl_t handle_next_pldm_request(void);
#endif

    /**
    * @brief Copy the 3 byte header of a PLDM message into a
    *        uint64_t and return it
    *
    * @param[in] i_pldmMsg  PLDM message we want the header of as a uint64_t
    *
    * @return uint64_t      3 byte pldm message header as a uint64_t (left aligned)
    */
    uint64_t pldmHdrToUint64(const pldm_msg& i_pldmMsg);
}
#endif
