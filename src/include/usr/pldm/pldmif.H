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
#include <vector>
#include <openbmc/pldm/libpldm/base.h>
#include <errl/errlentry.H>
#include <pldm/pldm_const.H>
#include <mctp/mctp_message_types.H>
#include <util/typed_msg.H>

namespace PLDM
{
    enum traffic_direction : uint8_t
    {
        INBOUND, /* Coming from the BMC */
        OUTBOUND /* Going to the BMC */
    };

    /* @brief Contains information necessary to respond to an incoming PLDM
     *        request. This structure does NOT own the memory pointed to by
     *        pldm_msg_no_own.
     */
    struct pldm_mctp_message_view
    {
        bool mctp_tag_owner = false;
        uint8_t mctp_msg_tag = 0;
        const pldm_msg* pldm_msg_no_own = nullptr;
        size_t pldm_msg_size;
    };

    /* @brief Contains information necessary to respond to an incoming PLDM
     *        request.
     */
    struct pldm_mctp_message
    {
        pldm_mctp_message(const pldm_mctp_message_view i_view)
            : mctp_tag_owner(i_view.mctp_tag_owner),
              mctp_msg_tag(i_view.mctp_msg_tag),
              pldm_data(reinterpret_cast<const uint8_t*>(i_view.pldm_msg_no_own),
                        reinterpret_cast<const uint8_t*>(i_view.pldm_msg_no_own) + i_view.pldm_msg_size)
        { }

        pldm_mctp_message(const bool i_mctp_tag_owner,
                          const uint8_t i_mctp_msg_tag,
                          std::vector<uint8_t> i_pldm_data)
            : mctp_tag_owner(i_mctp_tag_owner),
              mctp_msg_tag(i_mctp_msg_tag),
              pldm_data(move(i_pldm_data))
        { }

        pldm_mctp_message(const pldm_mctp_message&) = delete;
        pldm_mctp_message(pldm_mctp_message&&) = default;

        void operator=(const pldm_mctp_message&) = delete;
        pldm_mctp_message& operator=(pldm_mctp_message&&) = default;

        bool mctp_tag_owner = false;
        uint8_t mctp_msg_tag = 0;
        std::vector<uint8_t> pldm_data;

        /* @brief Interpret the data member as a PLDM message. */
        const pldm_msg* pldm() const
        {
            return reinterpret_cast<const pldm_msg*>(pldm_data.data());
        }

        /* @brief Get the size of the PLDM payload, not including the PLDM
         *        header. */
        size_t payload_size() const
        {
            return pldm_data.size() - sizeof(pldm_msg_hdr);
        }

        /* @brief Whether this structure contains a message or not. */
        bool empty() const
        {
            return pldm_data.empty();
        }
    };

    /* The response to a PLDM-send message. */
    struct pldm_mctp_response
    {
        errlHndl_t error;
        pldm_mctp_message response;
    };

    using pldm_inbound_rsp_msgq_t = Util::unipipe<pldm_mctp_message>;
    using pldm_inbound_req_msgq_t = Util::unipipe<pldm_mctp_message>;
    using pldm_outbound_req_msgq_t = Util::bipipe<MCTP::outgoing_mctp_msg, pldm_mctp_response>;

#ifndef __HOSTBOOT_RUNTIME
    extern pldm_inbound_rsp_msgq_t g_inboundPldmRspMsgQ;  // pldm inbound response msgQ
    extern pldm_inbound_req_msgq_t g_inboundPldmReqMsgQ;  // pldm inbound request msgQ
    extern pldm_outbound_req_msgq_t g_outboundPldmReqMsgQ;  // pldm outbound request msgQ

    /**
    * @brief This function is intended to be used by the MCTP resource
    *        provider when they find a PLDM message and want the PLDM
    *        resource provider to handle it
    *
    * @param[in] i_req  The inbound PLDM message.
    *
    * @return errHndl_t   nullptr unless error occurs
    */
    errlHndl_t routeInboundMsg(pldm_mctp_message_view i_req);

    // Callback type given to registerShutdownCallback
    using shutdown_callback_t = void(*)(void*);

    /* @brief Register a callback that will be invoked at the beginning of firmware shutdown.
     * @param[in] i_handler  Callback function
     * @param[in] i_context  Callback context, forwarded to the callback
     */
    void registerShutdownCallback(shutdown_callback_t i_handler, void* i_context);

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
    // These are dummy queues that aren't actually used by runtime code.
    const pldm_inbound_rsp_msgq_t g_inboundPldmRspMsgQ(nullptr);  // pldm inbound response msgQ
    const pldm_inbound_req_msgq_t g_inboundPldmReqMsgQ(nullptr);  // pldm inbound request msgQ
    const pldm_outbound_req_msgq_t g_outboundPldmReqMsgQ(nullptr);  // pldm outbound request msgQ

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
    *
    * @return pldmrp_rt_rc HBRT PLDM resource provider return code (see pldmrp_rt.H)
    */
    pldmrp_rt_rc cache_next_pldm_msg(PLDM::pldm_mctp_message i_next_msg);

    /**
    * @brief This function will return the PLDM response, if there is one,
    *        that HBRT's PLDM resource provider has cached.
    *
    * @return std::vector<uint8_t> Vector containing the next cached PLDM
    *                              response if there is one
    */
    const pldm_mctp_message& get_next_response();

    /**
    * @brief Clear the byte vector containing the cached pldm response in the PLDM
    *        resource provider
    *
    * @return void
    */
    void clear_next_response();

    /**
    * @brief This function will return the PLDM request, if there is one,
    *        that HBRT's PLDM resource provider has cached.
    *
    * @return std::vector<uint8_t> Vector containing the next cached PLDM
    *                              request if there is one
    */
    const pldm_mctp_message& get_next_request();

    /**
    * @brief Clear the byte vector containing the cached pldm request in the PLDM
    *        resource provider
    *
    * @return void
    */
    void clear_next_request();

    /**
     *  @brief Get the next incoming PLDM request and clear the cached copy.
     *
     *  @return  The next incoming PLDM request.
     */
    pldm_mctp_message get_and_clear_next_request();

    /**
     *  @brief Get the next incoming PLDM response and clear the cached copy.
     *
     *  @return  The next incoming PLDM response.
     */
    pldm_mctp_message get_and_clear_next_response();

    /**
    * @brief Process the next PLDM request cached by HBRT's PLDM resource
    *        provider.
    *
    * @return errHndl_t   nullptr unless error occurs
    */
    errlHndl_t handle_next_pldm_request();
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

    /**
     * @brief Add all 4 flight recorder sections to error log
     * @note  This will only work at IPL time, do-nothing at runtime
     * @param[in] io_errl Error log for fr sections
     */
    void addPldmFrData(const errlHndl_t i_errl);
}
#endif
