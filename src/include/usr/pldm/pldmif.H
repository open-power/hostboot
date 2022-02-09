/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/pldmif.H $                               */
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

    // Callback type given to registerShutdownCallback
    using shutdown_callback_t = void(*)(void*);

    /* @brief Register a callback that will be invoked at the beginning of firmware shutdown.
     * @param[in] i_handler  Callback function
     * @param[in] i_context  Callback context, forwarded to the callback
     */
    void registerShutdownCallback(shutdown_callback_t i_handler, void* i_context);


    enum traffic_direction : uint8_t
    {
        INBOUND, /* Coming from the BMC */
        OUTBOUND /* Going to the BMC */
    };

    /**
     * @brief Log a given PLDM message in the appropriate PLDM flight recorder log
     *        based upon the information in the header of the PLDM message and
     *        the direction parameter.
     *
     * @param[in] i_hdr A ptr to a PLDM message, no change of memory ownership.
     * @param[in] i_dir The direction of the PLDM message:
     *                   - INBOUND if message is coming from the BMC.
     *                   - OUTBOUND if message is going to the BMC
     */
    void logPldmMsg(const pldm_msg_hdr* const i_hdr, traffic_direction i_dir);
#else

    /**
     *  @brief Tells PLDM whether it's waiting for a response or not
     *
     *  @param[in] i_waitingForResponse Whether PLDM is waiting for a response
     *      or not
     */
    void set_waiting_for_response(bool i_waitingForResponse);

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
