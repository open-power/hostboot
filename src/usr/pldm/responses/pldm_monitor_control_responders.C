/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/responses/pldm_monitor_control_responders.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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

/* @file  pldm_monitor_control_responders.C
 *
 * @brief Contains definitions for the PLDM Platform Monitor & Control message
 *        handlers.
 */

#include <pldm/responses/pldm_monitor_control_responders.H>

// PLDM
#include <pldm/pldm_errl.H>
#include <pldm/pldm_const.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_response.H>
#include "../common/pldmtrace.H"
#include <pldm/extended/pldm_watchdog.H>
#include <pldm/base/pldm_shutdown.H>

// Targeting
#include <targeting/common/utilFilter.H>
#include <targeting/common/targetservice.H>

// libpldm headers from pldm subtree
#include <openbmc/pldm/libpldm/platform.h>
#include <openbmc/pldm/libpldm/base.h>
#include <openbmc/pldm/libpldm/state_set.h>


// PdrManager
#include <pldm/extended/pdr_manager.H>

// Initservice
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>

// Misc
#include <errl/errlmanager.H>
#include <runtime/interface.h>
#include <htmgt/htmgt.H>
#include <arch/ppc.H>
#include <sys/misc.h>

#ifdef __HOSTBOOT_RUNTIME
#include <sbeio/sbe_retry_handler.H>
#endif

// Standard library
#include <memory>

using namespace ERRORLOG;
using namespace TARGETING;

namespace PLDM
{

errlHndl_t handleGetPdrRequest(const msg_q_t i_msgQ,
                               const pldm_msg* const i_msg,
                               const size_t i_payload_len)
{
    PLDM_ENTER("handleGetPdrRequest");

    pldm_get_pdr_req pdr_req { };
    errlHndl_t errl = nullptr;
    std::vector<uint8_t> pdr_data;
    pdr_handle_t next_record_handle = 0;
    uint8_t pldm_response_code = PLDM_SUCCESS;

    do
    {
        {
            const int rc =
                decode_get_pdr_req(i_msg,
                                   i_payload_len,
                                   &pdr_req.record_handle,
                                   &pdr_req.data_transfer_handle,
                                   &pdr_req.transfer_op_flag,
                                   &pdr_req.request_count,
                                   &pdr_req.record_change_number);

            if (rc != PLDM_SUCCESS)
            {
                PLDM_ERR("Failed to decode getPDR request, rc = %d",
                         rc);

                /*@
                 * @errortype  ERRL_SEV_UNRECOVERABLE
                 * @moduleid   MOD_HANDLE_GET_PDR
                 * @reasoncode RC_MSG_DECODE_FAIL
                 * @userdata1  RC returned from decode function
                 * @devdesc    Software problem, failed to decode PLDM getPDR request
                 * @custdesc   A software error occurred during system boot
                 */
                errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                     MOD_HANDLE_GET_PDR,
                                     RC_MSG_DECODE_FAIL,
                                     rc,
                                     0,
                                     ErrlEntry::NO_SW_CALLOUT);

                addBmcErrorCallouts(errl);
                errlCommit(errl, PLDM_COMP_ID);

                pldm_response_code = PLDM_ERROR_INVALID_DATA;
                break;
            }
        }

        if (pdr_req.data_transfer_handle != 0)
        {
            // We don't support multipart transfers
            PLDM_ERR("Got invalid data transfer handle 0x%x in getPDR request",
                     pdr_req.data_transfer_handle);
            pldm_response_code = PLDM_PLATFORM_INVALID_DATA_TRANSFER_HANDLE;
            break;
        }

        if (pdr_req.transfer_op_flag != PLDM_GET_FIRSTPART)
        {
            PLDM_ERR("Got invalid transfer op flag 0x%x in getPDR request",
                     pdr_req.transfer_op_flag);
            pldm_response_code = PLDM_PLATFORM_INVALID_TRANSFER_OPERATION_FLAG;
            break;
        }

        if (pdr_req.record_change_number != 0)
        {
            PLDM_ERR("Got invalid record change number 0x%x in getPDR request",
                     pdr_req.record_change_number);
            pldm_response_code = PLDM_PLATFORM_INVALID_RECORD_CHANGE_NUMBER;
            break;
        }

        pdr_handle_t record_handle = pdr_req.record_handle;

        const bool record_found
            = PLDM::thePdrManager().findPdr(record_handle,
                                            &pdr_data,
                                            next_record_handle);

        PLDM_INF("BMC requesting PDR handle 0x%08x, returning 0x%08x",
                 pdr_req.record_handle,
                 record_handle);

        if (!record_found)
        {
            PLDM_ERR("Got invalid record handle 0x%x in getPDR request",
                     pdr_req.record_handle);
            pldm_response_code = PLDM_PLATFORM_INVALID_RECORD_HANDLE;
            break;
        }
    } while (false);

    const size_t max_request_count = pdr_req.request_count;

    // If we found the PDR with the given record handle, we send back at
    // most the number of bytes that the client asked for.
    const uint32_t response_pdr_size
        = (pldm_response_code == PLDM_SUCCESS
           ? std::min(pdr_data.size(), max_request_count)
           : 0);

    errl =
        send_pldm_response<PLDM_GET_PDR_MIN_RESP_BYTES>
        (i_msgQ,
         encode_get_pdr_resp,
         response_pdr_size,
         i_msg->hdr.instance_id,
         pldm_response_code,
         next_record_handle,
         0, // No remaining data
         PLDM_START_AND_END,
         payload_length_placeholder_t(),
         pdr_data.data(),
         0); // CRC, not used for START_AND_END

    if (errl)
    {
        PLDM_ERR("Failed to encode and/or send getPDR response "
                 "(response size = %d, response code = 0x%x, "
                 "next record handle = 0x%08x)",
                 response_pdr_size, pldm_response_code,
                 next_record_handle);

        errl->collectTrace(PLDM_COMP_NAME);
    }

    PLDM_EXIT("handleGetPdrRequest");

    return errl;
}

errlHndl_t handlePdrRepoChangeEventRequest(const msg_q_t i_msgQ,
                                           const pldm_msg* const i_msg,
                                           const size_t i_payload_len)
{
    PLDM_ENTER("handlePdrRepoChangeEventRequest");

    errlHndl_t errl = nullptr;
    uint8_t response_code = PLDM_SUCCESS;

    // This do/while block is for decoding and verifying the request
    do
    {
        // All these variables except event_class are ignored, because we don't
        // support any other event than the PDR Repo Changed event, and even in
        // that case we don't need to read the event data (because we drop and
        // refresh the entire repo).

        uint8_t format_version = 0,
                tid = 0,
                event_class = 0;

        size_t event_data_offset = 0;

        errl = decode_pldm_request
            (decode_platform_event_message_req,
             i_msg,
             i_payload_len,
             &format_version,
             &tid,
             &event_class,
             &event_data_offset);

        if (errl)
        {
            PLDM_ERR("Failed to decode PLDM PDR Repository Changed Event request");
            errlCommit(errl, PLDM_COMP_ID);
            response_code = PLDM_ERROR;
            break;
        }

        if (event_class != PLDM_PDR_REPOSITORY_CHG_EVENT)
        {
            PLDM_ERR("Invalid event class %d in platform event handler",
                     event_class);

            /*@
             * @errortype  ERRL_SEV_INFORMATIONAL
             * @moduleid   MOD_HANDLE_REPO_CHANGED_EVENT
             * @reasoncode RC_INVALID_MSG_TYPE
             * @userdata1  Expected event class
             * @userdata2  Actual event class
             * @devdesc    Software problem, invalid event class received from BMC
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                 MOD_HANDLE_REPO_CHANGED_EVENT,
                                 RC_INVALID_MSG_TYPE,
                                 PLDM_PDR_REPOSITORY_CHG_EVENT,
                                 event_class,
                                 ErrlEntry::NO_SW_CALLOUT);

            addBmcErrorCallouts(errl);
            errlCommit(errl, PLDM_COMP_ID);
            response_code = PLDM_ERROR;
            break;
        }
    } while (false);

    // This do/while is for sending a response
    do
    {
        errl =
            send_pldm_response<PLDM_PLATFORM_EVENT_MESSAGE_RESP_BYTES>
            (i_msgQ,
             encode_platform_event_message_resp,
             0, // No payload after the header
             i_msg->hdr.instance_id,
             response_code,
             PLDM_EVENT_NO_LOGGING);

        if (errl)
        {
            PLDM_ERR("Failed to send PLDM PDR Repository Changed event response");
            errl->collectTrace(PLDM_COMP_NAME);
            break;
        }
#ifndef __HOSTBOOT_RUNTIME
        if (response_code == PLDM_SUCCESS)
        {
            errl = thePdrManager().notifyBmcPdrRepoChanged();

            if (errl)
            {
                PLDM_ERR("Failed to notify PDR manager that BMC PDR repository changed");
                errl->collectTrace(PLDM_COMP_NAME);
                break;
            }
        }
#endif
    } while (false);

    PLDM_EXIT("handlePdrRepoChangeEventRequest");

    return errl;
}

/* @brief Send a response to a GetStateSensorStates request.
 *
 * @param[in] i_msgQ                      The outgoing PLDM message queue.
 * @param[in] i_msg                       The PLDM request to respond to.
 * @param[in] i_sensor_operational_state  The operational state of the sensor.
 * @param[in] i_sensor_state              The state value of the sensor.
 * @return errlHndl_t                     Error if any, otherwise nullptr.
 */
static errlHndl_t sendStateSensorGetRequestResponse(const msg_q_t i_msgQ,
                                                    const pldm_msg* const i_msg,
                                                    const pldm_sensor_present_state i_sensor_operational_state,
                                                    const sensor_state_t i_sensor_state)
{
    get_sensor_state_field sensor_state =
    {
        .sensor_op_state = i_sensor_operational_state,
        .present_state = i_sensor_state,
        .previous_state = i_sensor_state,
        .event_state = i_sensor_state
    };

    return
        send_pldm_response<PLDM_GET_STATE_SENSOR_READINGS_MIN_RESP_BYTES>
        (i_msgQ,
         encode_get_state_sensor_readings_resp,
         sizeof(sensor_state),
         i_msg->hdr.instance_id,
         PLDM_SUCCESS,
         1, // sensor count of 1
         &sensor_state);
}

errlHndl_t handleFunctionalStateSensorGetRequest(const state_sensor_callback_args& i_args)
{
    PLDM_INF(ENTER_MRK"handleFunctionalStateSensorGetRequest (target: 0x%08x, sensor ID %d)",
             get_huid(i_args.i_target),
             i_args.i_req->sensor_id);

    /* Encode and send a PLDM response to the request. */

    const sensor_state_t current_state = (i_args.i_target->getAttr<ATTR_HWAS_STATE>().functional
                                          ? PLDM_STATE_SET_HEALTH_STATE_NORMAL
                                          : PLDM_STATE_SET_HEALTH_STATE_CRITICAL);

    const errlHndl_t errl = sendStateSensorGetRequestResponse(i_args.i_msgQ, i_args.i_msg, PLDM_SENSOR_NORMAL, current_state);

    PLDM_INF(EXIT_MRK"handleFunctionalStateSensorGetRequest (errl = %p)", errl);

    return errl;
}

errlHndl_t handleGracefulShutdownSensorGetRequest(const state_sensor_callback_args& i_args)
{
    PLDM_INF(ENTER_MRK"handleGracefulShutdownSensorGetRequest");

#ifdef __HOSTBOOT_RUNTIME
    const sensor_state_t current_state = PLDM_SW_TERM_NORMAL;
#else
    const sensor_state_t current_state = (INITSERVICE::isShutdownRequested()
                                          ? PLDM_SW_TERM_GRACEFUL_SHUTDOWN_REQUESTED
                                          : PLDM_SW_TERM_NORMAL);
#endif

    const errlHndl_t errl = sendStateSensorGetRequestResponse(i_args.i_msgQ, i_args.i_msg, PLDM_SENSOR_NORMAL, current_state);

    PLDM_INF(EXIT_MRK"handleGracefulShutdownSensorGetRequest");

    return errl;
}

errlHndl_t handleOccStateSensorGetRequest(const state_sensor_callback_args& i_args)
{
    Target* const i_occ_proc = getImmediateParentByAffinity(i_args.i_target);

    PLDM_INF(ENTER_MRK"handleOccStateSensorGetRequest 0x%08x %d",
             get_huid(i_occ_proc),
             i_args.i_req->sensor_id);

    /* Encode and send a PLDM response to the request. */

#ifdef __HOSTBOOT_RUNTIME
    const sensor_state_t current_state = ( HTMGT::occsAreRunning()
                                          ? PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_IN_SERVICE
                                          : PLDM_STATE_SET_OPERATIONAL_RUNNING_STATUS_STOPPED);

    const errlHndl_t errl = sendStateSensorGetRequestResponse(i_args.i_msgQ, i_args.i_msg, PLDM_SENSOR_NORMAL, current_state);
#else
    // The OCC state cannot be read until runtime.
    const errlHndl_t errl = sendStateSensorGetRequestResponse(i_args.i_msgQ, i_args.i_msg, PLDM_SENSOR_UNKNOWN, 0);
#endif

    PLDM_INF(EXIT_MRK"handleOccStateSensorGetRequest");

    return errl;
}

errlHndl_t handleGracefulShutdownRequest(const state_effecter_callback_args& i_args)
{
    PLDM_INF(ENTER_MRK"handleGracefulShutdownRequest");

    errlHndl_t errl = nullptr;

#ifdef __HOSTBOOT_RUNTIME
    PLDM_ERR("handleGracefulShutdownRequest: Received graceful shutdown request at runtime");
    send_cc_only_response(i_args.i_msgQ, i_args.i_msg, PLDM_ERROR_NOT_READY);

    /*@
     * @errortype  ERRL_SEV_UNRECOVERABLE
     * @moduleid   MOD_HANDLE_GRACEFUL_SHUTDOWN_REQUEST
     * @reasoncode RC_NOT_READY
     * @devdesc    Software problem, graceful shutdown requested by BMC at runtime
     * @custdesc   A software error occurred during runtime
     */
    errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                         MOD_HANDLE_GRACEFUL_SHUTDOWN_REQUEST,
                         RC_NOT_READY,
                         0,
                         0,
                         ErrlEntry::NO_SW_CALLOUT);

    addBmcErrorCallouts(errl);
#else
    PLDM_INF("handleGracefulShutdownRequest: Received graceful shutdown request");
    send_cc_only_response(i_args.i_msgQ, i_args.i_msg, PLDM_SUCCESS);

    PLDM::requestSoftPowerOff(PLDM::POWEROFF_BMC_INITIATED);
#endif

    PLDM_INF(EXIT_MRK"handleGracefulShutdownRequest");

    return errl;
}

errlHndl_t handleOccSetStateEffecterRequest(const state_effecter_callback_args& i_args)
{
    errlHndl_t errl = nullptr;
    uint8_t response_code = PLDM_SUCCESS;

    Target* const i_occ_proc = getImmediateParentByAffinity(i_args.i_target);

    do
    {

    /* Validate some of the parameters in the requests that we can check immediately. */

    const auto i_req = i_args.i_req;

    if (i_req->comp_effecter_count != 1
        || !i_req->field[0].set_request
        || (i_req->field[0].effecter_state != PLDM_STATE_SET_BOOT_RESTART_CAUSE_WARM_RESET
            && i_req->field[0].effecter_state != PLDM_STATE_SET_BOOT_RESTART_CAUSE_HARD_RESET))
    {
        PLDM_ERR("handleOccSetStateEffecterRequest: Received invalid state effecter set request "
                 "(effecter 0x%x, PROC = 0x%08x, effecter count = %d, "
                 "set_request = %d, effecter_state = %d)",
                 i_req->effecter_id,
                 get_huid(i_occ_proc),
                 i_req->comp_effecter_count,
                 i_req->field[0].set_request,
                 i_req->field[0].effecter_state);

        /*@
         * @errortype  ERRL_SEV_PREDICTIVE
         * @moduleid   MOD_HANDLE_SET_OCC_STATE
         * @reasoncode RC_INVALID_EFFECTER_STATE
         * @userdata1  HUID of the PROC with the OCC that was being reset
         * @userdata2[0:15]  Set request field of first effecter
         * @userdata2[16:31] Effecter state of first effecter
         * @userdata2[32:63] Effecter count
         * @devdesc    Software problem, invalid effecter state from BMC
         * @custdesc   A software error occurred during system boot
         */
        errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                             MOD_HANDLE_SET_OCC_STATE,
                             RC_INVALID_EFFECTER_STATE,
                             get_huid(i_occ_proc),
                             TWO_UINT16_ONE_UINT32_TO_UINT64(i_req->field[0].set_request,
                                                             i_req->field[0].effecter_state,
                                                             i_req->comp_effecter_count),
                             ErrlEntry::NO_SW_CALLOUT);

        addBmcErrorCallouts(errl);
        errlCommit(errl, PLDM_COMP_ID);
        response_code = PLDM_PLATFORM_INVALID_STATE_VALUE;
        break;
    }

    /* Act on the request if the request was valid */

    if (i_occ_proc->getAttr<ATTR_HOMER_PHYS_ADDR>() == 0)
    {
        PLDM_ERR("handleOccSetStateEffecterRequest: Failed to restart the OCC "
                 "on PROC HUID = 0x%08x at IPL time "
                 "(request too early - HOMER_PHYS_ADDR is 0)",
                 get_huid(i_occ_proc));

        /*@
         * @errortype  ERRL_SEV_PREDICTIVE
         * @moduleid   MOD_HANDLE_SET_STATE_EFFECTER_STATES_REQUEST
         * @reasoncode RC_OCC_RESET_TOO_SOON
         * @userdata1  HUID of the PROC with the OCC that was being reset
         * @devdesc    Software problem, BMC requested OCC reset too soon
         * @custdesc   A software error occurred during system boot
         */
        errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                             MOD_HANDLE_SET_STATE_EFFECTER_STATES_REQUEST,
                             RC_OCC_RESET_TOO_SOON,
                             get_huid(i_occ_proc),
                             0,
                             ErrlEntry::NO_SW_CALLOUT);

        addBmcErrorCallouts(errl);
        errlCommit(errl, PLDM_COMP_ID);
        response_code = PLDM_ERROR_NOT_READY;
        break;
    }

    } while (false);

    /* Respond to the request notifying the BMC that we are going to attempt the OCC reset */

    if (!errl)
    {
        errl =
            send_pldm_response<PLDM_SET_STATE_EFFECTER_STATES_RESP_BYTES>
            (i_args.i_msgQ,
             encode_set_state_effecter_states_resp,
             0, // No payload after the header
             i_args.i_msg->hdr.instance_id,
             response_code);

        if (errl)
        {
            PLDM_ERR("handleOccSetStateEffecterRequest: Failed to send PLDM Set State Effecter States (OCC) event response");
            errl->collectTrace(PLDM_COMP_NAME);
        }
    }

    if (response_code == PLDM_SUCCESS)
    {
        PLDM_INF("handleOccSetStateEffecterRequest: Restarting OCC on PROC HUID = 0x%08x...",
                 get_huid(i_occ_proc));

        HTMGT::processOccReset(i_occ_proc);

        PLDM_INF("handleOccSetStateEffecterRequest: Restarted OCC on PROC HUID = 0x%08x",
                 get_huid(i_occ_proc));
    }

    return errl;
}

errlHndl_t handleSetStateEffecterStatesRequest(const msg_q_t i_msgQ,
                                               const pldm_msg* const i_msg,
                                               const size_t i_payload_len)
{
    PLDM_ENTER("handleSetStateEffecterStatesRequest");

    errlHndl_t errl = nullptr;

    /* Decode and verify the request */

    pldm_set_state_effecter_states_req req = { };

    do
    {
        errl = decode_pldm_request(decode_set_state_effecter_states_req,
                                   i_msg,
                                   i_payload_len,
                                   &req.effecter_id,
                                   &req.comp_effecter_count,
                                   req.field);

        if (errl)
        {
            PLDM_ERR("Failed to decode PLDM Set State Effecter States request");
            send_cc_only_response(i_msgQ, i_msg, PLDM_ERROR);
            break;
        }

        /* Have the PDR manager invoke the appropriate callback handler. */

        errl = thePdrManager().setStateEffecterStates(i_msgQ, i_msg, i_payload_len, &req);
    } while (false);

    PLDM_EXIT("handleSetStateEffecterStatesRequest");

    return errl;
}

errlHndl_t handleGetStateSensorReadingsRequest(const msg_q_t i_msgQ,
                                               const pldm_msg* const i_msg,
                                               const size_t i_payload_len)
{
    PLDM_ENTER("handleGetStateSensorReadingsRequest");

    errlHndl_t errl = nullptr;

    do
    {
        /* Decode and verify the request */

        pldm_get_state_sensor_readings_req req = { };

        errl = decode_pldm_request(decode_get_state_sensor_readings_req,
                                   i_msg,
                                   i_payload_len,
                                   &req.sensor_id,
                                   &req.sensor_rearm,
                                   &req.reserved);

        if (errl)
        {
            PLDM_ERR("Failed to decode PLDM Get State Sensor Readings request");
            send_cc_only_response(i_msgQ, i_msg, PLDM_ERROR);
            break;
        }

        /* Have the PDR manager invoke the appropriate callback handler. */

        errl = thePdrManager().getStateSensorReadings(i_msgQ, i_msg, i_payload_len, &req);
    } while (false);

    PLDM_EXIT("handleGetStateSensorReadingsRequest");

    return errl;
}

errlHndl_t handleSetEventReceiverRequest(const msg_q_t i_msgQ,
                                         const pldm_msg* const i_msg,
                                         const size_t i_payload_len)
{
    PLDM_ENTER("handleSetEventReceiverRequest");
    errlHndl_t l_errl = nullptr;
    uint8_t l_response_code = PLDM_SUCCESS;

    uint8_t l_event_message_global_enable = 0;
    uint8_t l_transport_protocol_type = 0;
    uint8_t l_event_receiver_address_info = 0;
    uint16_t l_heartbeat_timer = 0;

    // Decode and verify the request
    do {

    l_errl = decode_pldm_request(
                decode_set_event_receiver_req,
                i_msg,
                i_payload_len,
                &l_event_message_global_enable,
                &l_transport_protocol_type,
                &l_event_receiver_address_info,
                &l_heartbeat_timer);
    if(l_errl)
    {
        PLDM_ERR("handleSetEventReceiverRequest: failed to decode the request");
        errlCommit(l_errl, PLDM_COMP_ID);
        l_response_code = PLDM_ERROR;
        break;
    }

    PLDM_INF("handleSetEventReceiverRequest: BMC requested watchdog timeout of %d seconds",
             l_heartbeat_timer);

    if(l_event_message_global_enable !=
       PLDM_EVENT_MESSAGE_GLOBAL_ENABLE_ASYNC_KEEP_ALIVE)
    {
        PLDM_ERR("handleSetEventReceiverRequest: invalid value for message global enable received: %d",
                 l_event_message_global_enable);
        /*@
         * @errortype
         * @moduleid MOD_HANDLE_SET_EVENT_RECEIVER
         * @reasoncode RC_BAD_GLOBAL_ENABLE
         * @userdata1 Expected value of message global enable
         * @userdata2 Actual value of message global enable
         * @devdesc BMC sent an unexpected message global enable value
         *          in the SetEventReceiverRequest command
         * @custdesc A software error occurred during system boot
         */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               MOD_HANDLE_SET_EVENT_RECEIVER,
                               RC_BAD_GLOBAL_ENABLE,
                               PLDM_EVENT_MESSAGE_GLOBAL_ENABLE_ASYNC_KEEP_ALIVE,
                               l_event_message_global_enable,
                               ErrlEntry::NO_SW_CALLOUT);
        addBmcErrorCallouts(l_errl);
        errlCommit(l_errl, PLDM_COMP_ID);
        l_response_code = PLDM_PLATFORM_ENABLE_METHOD_NOT_SUPPORTED;
        break;
    }

    if(l_heartbeat_timer < HB_MIN_WATCHDOG_TIMEOUT_SEC)
    {
        // BMC requested watchdog timeout that's too small
        /*@
         * @errortype
         * @moduleid MOD_HANDLE_SET_EVENT_RECEIVER
         * @reasoncode RC_BAD_WATCHDOG_VALUE
         * @userdata1 Minimum value of the watchdog supported by HB
         * @userdata2 Watchdog timeout value sent by BMC
         * @devdesc BMC requested a watchdog timeout value that's too
         *          small
         * @custdesc A software error occurred during system boot
         */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               MOD_HANDLE_SET_EVENT_RECEIVER,
                               RC_BAD_WATCHDOG_VALUE,
                               HB_MIN_WATCHDOG_TIMEOUT_SEC,
                               l_heartbeat_timer,
                               ErrlEntry::NO_SW_CALLOUT);
        addBmcErrorCallouts(l_errl);
        errlCommit(l_errl, PLDM_COMP_ID);
        l_response_code = PLDM_PLATFORM_HEARTBEAT_FREQUENCY_TOO_HIGH;
        break;
    }
    else
    {
        // Set the internal watchdog period to what BMC indicated
        g_pldmWatchdogPeriodSec = l_heartbeat_timer;
    }

    if(UTIL::assertGetToplevelTarget()->getAttr<ATTR_ISTEP_MODE>())
    {
        // We don't want BMC to set watchdog timer in istep mode.
        // PLDM_PLATFORM_ENABLE_METHOD_NOT_SUPPORTED is our indicator
        // to BMC that we don't want the watchdog timer to be set.
        l_response_code = PLDM_PLATFORM_ENABLE_METHOD_NOT_SUPPORTED;
        break;
    }

    }while(0);


    // Send the response to BMC
    do {
    l_errl = send_pldm_response<PLDM_SET_EVENT_RECEIVER_RESP_BYTES>(
                i_msgQ,
                encode_set_event_receiver_resp,
                0, // no payload size
                i_msg->hdr.instance_id,
                l_response_code);
    if(l_errl)
    {
        PLDM_ERR("handleSetEventReceiverRequest: Could not send the response to BMC");
        l_errl->collectTrace(PLDM_COMP_NAME);
        break;
    }

    // No error happened above, so arm the watchdog and set the default timeout
    /// value.
    if(l_response_code == PLDM_SUCCESS)
    {
        // No need to arm the watchdog if we're in istep mode.
        if(!UTIL::assertGetToplevelTarget()->getAttr<ATTR_ISTEP_MODE>())
        {
            g_pldmWatchdogArmed = true;
            l_errl = resetWatchdogTimer();
            if(l_errl)
            {
                PLDM_ERR("handleSetEventReceiverRequest: Could not send the first watchdog to BMC");
                break;
            }
        }
    }

    }while(0);

    PLDM_EXIT("handleSetEventReceiverRequest");
    return l_errl;
}

errlHndl_t handleAttributeBackedSensorGetRequest(const state_sensor_callback_args& i_args)
{
    PLDM_ENTER("handleAttributeBackedSensorGetRequest");

    uint16_t attr_data = 0;

    assert(i_args.i_target->unsafeTryGetAttr(static_cast<ATTRIBUTE_ID>(i_args.i_userdata), sizeof(attr_data), &attr_data),
           "Cannot read attribute 0x%08x on target 0x%08x",
           i_args.i_userdata, get_huid(i_args.i_target));

    const errlHndl_t errl = sendStateSensorGetRequestResponse(i_args.i_msgQ, i_args.i_msg, PLDM_SENSOR_NORMAL, attr_data);

    PLDM_EXIT("handleAttributeBackedSensorGetRequest");

    return errl;
}

// @TODO RTC 247294: Delete these constants and use the ones from libpldm
enum ibm_oem_pldm_state_set_sbe_dump_state_values {
    SBE_DUMP_COMPLETED = 0x1,
    SBE_RETRY_REQUIRED = 0x2,
};

#ifdef __HOSTBOOT_RUNTIME

errlHndl_t handleSbeHresetRequest(const state_effecter_callback_args& i_args)
{
    errlHndl_t errl = nullptr;
    const auto proc = i_args.i_target;

    PLDM_ENTER("handleSbeHresetRequest(0x%08x)", get_huid(proc));

    do
    {

    if (i_args.i_req->field[0].effecter_state != SBE_RETRY_REQUIRED)
    {
        /*@
         * @errortype  ERRL_SEV_INFORMATIONAL
         * @moduleid   MOD_HANDLE_SBE_HRESET_REQUEST_RT
         * @reasoncode RC_NOT_READY
         * @userdata1  HUID of processor
         * @userdata2  ID of PLDM effecter
         * @devdesc    Software problem, SBE dump complete notification sent by BMC at runtime
         * @custdesc   A software error occurred during runtime
         */
        errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                             MOD_HANDLE_SBE_HRESET_REQUEST_RT,
                             RC_NOT_READY,
                             get_huid(proc),
                             i_args.i_req->effecter_id,
                             ErrlEntry::NO_SW_CALLOUT);
        addBmcErrorCallouts(errl);

        send_cc_only_response(i_args.i_msgQ, i_args.i_msg, PLDM_ERROR_NOT_READY);
        break;
    }

    send_cc_only_response(i_args.i_msgQ, i_args.i_msg, PLDM_SUCCESS);

    using namespace SBEIO;

    PLDM_INF("handleSbeHresetRequest: Attempting SBE HRESET on processor 0x%08x", get_huid(proc));

    SbeRetryHandler l_sbeObj(proc,
                             SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                             SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                             EMPTY_PLID,
                             NOT_INITIAL_POWERON);

    l_sbeObj.main_sbe_handler();

    } while (false);

    PLDM_EXIT("handleSbeHresetRequest(0x%08x)", get_huid(proc));

    return errl;
}

#else

errlHndl_t handleSbeHresetRequest(const state_effecter_callback_args& i_args)
{
    errlHndl_t errl = nullptr;

    if (i_args.i_req->field[0].effecter_state != SBE_DUMP_COMPLETED)
    {
        PLDM_ERR("handleSbeHresetRequest: BMC sent HRESET request for processor 0x%08x at IPL time",
                 get_huid(i_args.i_target));

        /*@
         * @errortype  ERRL_SEV_INFORMATIONAL
         * @moduleid   MOD_HANDLE_SBE_HRESET_REQUEST
         * @reasoncode RC_NOT_READY
         * @userdata1  HUID of processor
         * @userdata2  ID of PLDM effecter
         * @devdesc    Software problem, SBE HRESET request sent by BMC at IPL time
         * @custdesc   A software error occurred during runtime
         */
        errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                             MOD_HANDLE_SBE_HRESET_REQUEST,
                             RC_NOT_READY,
                             get_huid(i_args.i_target),
                             i_args.i_req->effecter_id,
                             ErrlEntry::NO_SW_CALLOUT);
        addBmcErrorCallouts(errl);

        send_cc_only_response(i_args.i_msgQ, i_args.i_msg, PLDM_ERROR_NOT_READY);
    }
    else
    {
        send_cc_only_response(i_args.i_msgQ, i_args.i_msg, PLDM_SUCCESS);
    }

    return errl;
}

#endif

}
