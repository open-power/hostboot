/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/responses/pldm_monitor_control_responders.H $ */
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

/* @file  pldm_monitor_control_responders.H
 *
 * @brief Contains definitions for PLDM message handlers for requests in the
 *        Platform Monitor & Control category (see DSP0248 v1.0.1 for details).
 */

#ifndef PLDM_MONITOR_CONTROL_RESPONDERS_H__
#define PLDM_MONITOR_CONTROL_RESPONDERS_H__

#include <sys/msg.h>
#include <errl/errlentry.H>
#include <mctp/mctp_message_types.H>
#include <pldm/pldmif.H>

struct pldm_msg;
struct pldm_get_state_sensor_readings_req;
struct pldm_set_state_effecter_states_req;

namespace PLDM
{

/* @brief handleGetPdrRequest
 *
 *        Handler for getPDR requests. (See DSP0248 v1.0.0 section 26.2 for
 *        details.)
 *
 * @param[in] i_msgQ         Handle to the MCTP outbound response message queue
 * @param[in] i_msg          getPDR request message object
 * @return    errlHndl_t     Error if any, otherwise nullptr.
 */
errlHndl_t handleGetPdrRequest(MCTP::mctp_outbound_msgq_t i_msgQ, const pldm_mctp_message& i_msg);

/* @brief handlePdrRepoChangeEventRequest
 *
 *        Handler for PDR Repository Change Event requests. (See DSP0248 v1.2.0
 *        section 16.14 for details.)
 *
 * @param[in] i_msgQ         Handle to MCTP outbound request message queue
 * @param[in] i_msg          The PLDM message received
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handlePdrRepoChangeEventRequest(MCTP::mctp_outbound_msgq_t i_msgQ,
                                           const pldm_mctp_message& i_msg);

/* @brief handleSetStateEffecterStatesRequest
 *
 *        Handler for Set State Effecter States requests. (See DSP0248 v1.2.0
 *        section 22.5 for details.)
 *
 * @param[in] i_msgQ         Handle to MCTP outbound request message queue
 * @param[in] i_msg          The PLDM message received
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleSetStateEffecterStatesRequest(MCTP::mctp_outbound_msgq_t i_msgQ,
                                               const pldm_mctp_message& i_msg);

/* @brief Handler for Get State Sensor Readings requests. (See DSP0248 v1.2.0
 *        section 20.2 for details.)
 *
 * @param[in] i_msgQ         Handle to MCTP outbound request message queue
 * @param[in] i_msg          The PLDM message received
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleGetStateSensorReadingsRequest(MCTP::mctp_outbound_msgq_t i_msgQ,
                                               const pldm_mctp_message& i_msg);

/* @brief Common arguments to all state sensor/effecter handler callbacks.
 */
struct state_query_handler_callback_args
{
    // Target that the effecter/sensor is related to.
    TARGETING::Target* i_target = nullptr;
    // The PLDM message queue.
    MCTP::mctp_outbound_msgq_t i_msgQ = nullptr;
    // The PLDM message.
    const pldm_mctp_message* i_msg = nullptr;
    // The payload length of the raw PLDM message.
    size_t i_payload_len = 0;
    // Arbitrary data for the callback.
    uint64_t i_userdata = 0;
};

/* @brief Arguments to state effecter handler callbacks.
 */
struct state_effecter_callback_args : state_query_handler_callback_args
{
    // The PLDM "set state effecter states" request structure.
    const pldm_set_state_effecter_states_req* i_req = nullptr;
};

/* @brief Arguments to state sensor handler callbacks.
 */
struct state_sensor_callback_args : state_query_handler_callback_args
{
    // The PLDM "get state sensor readings" request structure.
    const pldm_get_state_sensor_readings_req* i_req = nullptr;
};

/* @brief Handler for Set State Effecter requests for OCC state effecters.
 *
 * @param[in] i_args         State query handler arguments.
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleOccSetStateEffecterRequest(const state_effecter_callback_args& i_args);

/* @brief Handler for Set State Effecter requests for graceful shutdown.
 *
 * @param[in] i_args         State query handler arguments.
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleGracefulShutdownRequest(const state_effecter_callback_args& i_args);

/* @brief Handler for Get State Sensor Readings requests for FRU functional state sensors.
 *
 * @param[in] i_args         State query handler arguments.
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleFunctionalStateSensorGetRequest(const state_sensor_callback_args& i_args);

/* @brief Handler for Get State Sensor Readings requests for OCC state sensor.
 *
 * @param[in] i_args         State query handler arguments.
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleOccStateSensorGetRequest(const state_sensor_callback_args& i_args);

/* @brief Handler for Get State Sensor Readings requests for graceful shutdown.
 *
 * @param[in] i_args         State query handler arguments.
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleGracefulShutdownSensorGetRequest(const state_sensor_callback_args& i_args);

/* @brief Handler for Get State Sensor Readings requests for attribute-backed sensors.
 *
 * @param[in] i_args         State query handler arguments.
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleAttributeBackedSensorGetRequest(const state_sensor_callback_args& i_args);

/* @brief Handler for Set State Effecter States requests for SBE HRESET functionality.
 *
 * @param[in] i_args         State query handler arguments.
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleSbeHresetRequest(const state_effecter_callback_args& i_args);

/* @brief handleSetEventReceiverRequest
 *
 *        Handler for Set Event Receiver request. (See DSP0248 v1.2.0a
 *        section 16.4 for details.)
 *
 * @param[in] i_msgQ         Handle to MCTP outbound request message queue
 * @param[in] i_msg          The PLDM message received
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleSetEventReceiverRequest(MCTP::mctp_outbound_msgq_t i_msgQ,
                                         const pldm_mctp_message& i_msg);

/* @brief Handler for Set State Effecter requests for DCE invocation.
 *
 * @param[in] i_args         State query handler arguments.
 * @return errlHndl_t        Error if any, otherwise nullptr.
 */
errlHndl_t handleInvokeDceRequest(const state_effecter_callback_args& i_args);

}

#endif
